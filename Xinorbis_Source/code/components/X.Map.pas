// ============================================================================
//
// (c) Paul Alan Freshney 2012-2020
// www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com
//
// ============================================================================

unit X.Map;


interface


uses
  ExtCtrls, classes, controls, types, sysutils, graphics, math, contnrs, dialogs,
  System.Generics.Collections;


type
  TMouseClickEvent = procedure(const aFolderID : integer) of object;
  TMouseOverEvent  = procedure(const aFolderID : integer) of object;

  TXMapDataObject = class
    FolderName : string;

    FileCount  : integer;
    FileSize   : int64;

    Colour     : integer;
    ColourBW   : integer;

    BlockStart : integer;
    BlockEnd   : integer;
  end;

  TXMap = class
  private
    FOnMouseClick    : TMouseClickEvent;
    FOnMouseOver     : TMouseOverEvent;

    PaintBox         : TPaintBox;

    FMapData       : TObjectList<TXMapDataObject>;

    FBusy          : boolean;
    FHasData       : boolean;
    FMode          : integer;
    FDataSource    : integer;
    FSelected      : integer;
    FHighlightMode : boolean;

    FFolderTotalCount : integer;
    FFolderTotalSize  : int64;

    FBlocksSize, FBlocksGap, FBlocksPixel : integer;
    FBlocksX, FBlocksY : integer;

    procedure PaintBoxUpdateQuantity(Sender: TObject);
    procedure PaintBoxUpdateSize(Sender: TObject);
    procedure PaintBoxMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure PaintBoxMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);

    function  GetMapItemFrom(x, y : integer): integer;

    function  GetMapItem(aIndex : integer): TXMapDataObject;

    procedure SetBlocksSize(aBlocksSize : integer);
    procedure SetBlocksGap(aBlocksGap : integer);
    procedure SetHighlightMode(aHighlightMode : boolean);
    procedure SetMode(aMode : integer);

    function  ColourToBW(aColour : integer): integer;
 public
    constructor Create(AOwner: TComponent; Zig : TWinControl);
    destructor  Destroy; Override;

    procedure Clear;

    procedure BeginData;
    procedure AddData(const aFolderName : string; aFileCount : integer; aFileSize : int64; aColour : integer);
    procedure EndData;

    property  HighlightMode         : boolean          read FHighlightMode    write SetHighlightMode;

    property  BlocksSize            : integer          read FBlocksSize       write SetBlocksSize;
    property  BlocksGap             : integer          read FBlocksGap        write SetBlocksGap;

    property  DataSource            : integer          read FDataSource       write FDataSource;
    property  Item[Index : integer] : TXMapDataObject  read GetMapItem;
    property  Mode                  : integer          read FMode             write SetMode;

    property  FolderTotalCount      : integer          read FFolderTotalCount;
    property  FolderTotalSize       : int64            read FFolderTotalSize;

    property  OnMouseClick          : TMouseClickEvent read FOnMouseClick     write FOnMouseClick;
    property  OnMouseOver           : TMouseOverEvent  read FOnMouseOver      write FOnMouseOver;
  protected
  end;


const
  mapModeSize     = 0;
  mapModeQuantity = 1;


implementation


// ================================================================================================
// ================================================================================================
// ================================================================================================


constructor TXMap.Create(AOwner: TComponent; Zig : TWinControl);
begin
  FMapData := TObjectList<TXMapDataObject>.Create;

  PaintBox             := TPaintBox.Create(AOwner);
  PaintBox.Parent      := Zig;
  PaintBox.Align       := alClient;
  PaintBox.OnPaint     := PaintBoxUpdateSize;
  PaintBox.OnMouseDown := PaintBoxMouseDown;
  PaintBox.OnMouseMove := PaintBoxMouseMove;

  FBlocksSize          := 4;
  FBlocksGap           := 1;
  FBlocksPixel         := FBlocksSize + FBlocksGap;

  FBlocksX             := Round(PaintBox.Width / (FBlocksPixel));
  FBlocksY             := Round(PaintBox.Height / (FBlocksPixel));

  FHasData             := False;
  FBusy                := False;
  FDataSource          := -1;

  FSelected            := -1;
  FHighlightMode       := True;
end;


destructor TXMap.Destroy;
begin
  PaintBox.Free;

  FMapData.Free;

  inherited Destroy;
end;


procedure TXMap.PaintBoxUpdateSize(Sender: TObject);
var
  x, y : integer;
  lFolderItem, lBlocks, lBlockCount : integer;

begin
  FBlocksX := Floor(PaintBox.Width / (FBlocksPixel));
  FBlocksY := Floor(PaintBox.Height / (FBlocksPixel));

  if FHasData then begin
    lFolderItem := 0;

    if (not(FHighlightMode)) or (FSelected = lFolderItem) then
      PaintBox.Canvas.Brush.Color := FMapData[lFolderItem].Colour
    else
      PaintBox.Canvas.Brush.Color := FMapData[lFolderItem].ColourBW;

    lBlocks     := Floor((FMapData[lFolderItem].FileSize / FFolderTotalSize) * (FBlocksX * FBlocksY));
    lBlockCount := 0;

    FMapData[lFolderItem].BlockStart := 0;
    FMapData[lFolderItem].BlockEnd   := lBlocks - 1;

    if (FBlocksY > 0) and (FBlocksX > 0) then begin
      for y := 0 to FBlocksY - 1 do begin
        for x:= 0 to FBlocksX - 1 do begin

          PaintBox.Canvas.FillRect(Rect(x * FBlocksPixel,
                                        y * FBlocksPixel,
                                       (x * FBlocksPixel) + FBlocksSize,
                                       (y * FBlocksPixel) + FBlocksSize));

          inc(lBlockCount);

          if lBlockCount >= lBlocks then begin
            inc(lFolderItem);

            if lFolderItem < FMapData.Count then begin
              lBlocks     := Round((FMapData[lFolderItem].FileSize / FFolderTotalSize) * (FBlocksX * FBlocksY));
              lBlockCount := 0;

              FMapData[lFolderItem].BlockStart := FMapData[lFolderItem - 1].BlockEnd + 1;
              FMapData[lFolderItem].BlockEnd   := FMapData[lFolderItem].BlockStart + lBlocks - 1;

              if (not(FHighlightMode)) or (FSelected = lFolderItem) then
                PaintBox.Canvas.Brush.Color := FMapData[lFolderItem].Colour
              else
                PaintBox.Canvas.Brush.Color := FMapData[lFolderItem].ColourBW;
            end
            else
              PaintBox.Canvas.Brush.Color := $00ffffff;
          end;
        end;
      end;
    end;
  end
  else begin
    PaintBox.Canvas.Brush.Color := $00aaaaaa;

    if (FBlocksY > 0) and (FBlocksX > 0) then begin
      for y := 0 to FBlocksY - 1 do begin
        for x:= 0 to FBlocksX - 1 do begin

          PaintBox.Canvas.FillRect(Rect(x * FBlocksPixel,
                                        y * FBlocksPixel,
                                       (x * FBlocksPixel) + FBlocksSize,
                                       (y * FBlocksPixel) + FBlocksSize));

        end;
      end;
    end;
  end;
end;


procedure TXMap.PaintBoxUpdateQuantity(Sender: TObject);
var
  x, y : integer;
  lFolderItem, lBlocks, lBlockCount : integer;

begin
  FBlocksX := Floor(PaintBox.Width / (FBlocksPixel));
  FBlocksY := Floor(PaintBox.Height / (FBlocksPixel));

  if FHasData then begin
    lFolderItem := 0;

    if (not(FHighlightMode)) or (FSelected = lFolderItem) then
      PaintBox.Canvas.Brush.Color := FMapData[lFolderItem].Colour
    else
      PaintBox.Canvas.Brush.Color := FMapData[lFolderItem].ColourBW;

    lBlocks     := Floor((FMapData[lFolderItem].FileCount / FFolderTotalCount) * (FBlocksX * FBlocksY));
    lBlockCount := 0;

    FMapData[lFolderItem].BlockStart := 0;
    FMapData[lFolderItem].BlockEnd   := lBlocks - 1;

    if (FBlocksY > 0) and (FBlocksX > 0) then begin
      for y := 0 to FBlocksY - 1 do begin
        for x:= 0 to FBlocksX - 1 do begin

          PaintBox.Canvas.FillRect(Rect(x * FBlocksPixel,
                                        y * FBlocksPixel,
                                       (x * FBlocksPixel) + FBlocksSize,
                                       (y * FBlocksPixel) + FBlocksSize));

          inc(lBlockCount);

          if lBlockCount >= lBlocks then begin
            inc(lFolderItem);

            if lFolderItem < FMapData.Count then begin
              lBlocks     := Round((FMapData[lFolderItem].FileCount / FFolderTotalCount) * (FBlocksX * FBlocksY));
              lBlockCount := 0;

              FMapData[lFolderItem].BlockStart := FMapData[lFolderItem - 1].BlockEnd + 1;
              FMapData[lFolderItem].BlockEnd   := FMapData[lFolderItem].BlockStart + lBlocks - 1;

              if (not(FHighlightMode)) or (FSelected = lFolderItem) then
                PaintBox.Canvas.Brush.Color := FMapData[lFolderItem].Colour
              else
                PaintBox.Canvas.Brush.Color := FMapData[lFolderItem].ColourBW;
            end
            else
              PaintBox.Canvas.Brush.Color := $00ffffff;
          end;
        end;
      end;
    end;
  end
  else begin
    PaintBox.Canvas.Brush.Color := $00aaaaaa;

    if (FBlocksY > 0) and (FBlocksX > 0) then begin
      for y := 0 to FBlocksY - 1 do begin
        for x:= 0 to FBlocksX - 1 do begin

          PaintBox.Canvas.FillRect(Rect(x * FBlocksPixel,
                                        y * FBlocksPixel,
                                       (x * FBlocksPixel) + FBlocksSize,
                                       (y * FBlocksPixel) + FBlocksSize));

        end;
      end;
    end;
  end;
end;


procedure TXMap.PaintBoxMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  lItem : integer;

begin
  if Assigned(FOnMouseOver) and (FHasData) then begin
    lItem := GetMapItemFrom(X, Y);

    FOnMouseClick(lItem);

    if (FHighlightMode) and (FSelected <> lItem) then begin
      FSelected := lItem;

      PaintBox.Invalidate;
    end;
  end;
end;


procedure TXMap.PaintBoxMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
var
  lItem : integer;

begin
  if Assigned(FOnMouseOver) and (FHasData) then begin
    lItem := GetMapItemFrom(X, Y);

    FOnMouseOver(lItem);

    if (FHighlightMode) and (FSelected <> lItem) then begin
      FSelected := lItem;

      PaintBox.Invalidate;
    end;
  end;
end;


// ================================================================================================
// ================================================================================================
// ================================================================================================


function  TXMap.GetMapItemFrom(x, y : integer): integer;
var
  lBlock : integer;
  lX, lY : integer;
  t : integer;

begin
  lX := Floor(X / FBlocksPixel);
  lY := Floor(Y / FBlocksPixel);

  lBlock := Floor(lX + ((lY) * (PaintBox.Width / FBlocksPixel)));

  Result := -1;

  if FMapData.Count > 0 then begin
    for t:= 0 to FMapData.Count - 1 do begin
      if (FMapData[t].BlockStart <= lBlock) and (FMapData[t].BlockEnd >= lBlock) then begin
        Result := t;

        Break;
      end;
    end;
  end;
end;


function TXMap.GetMapItem(aIndex : integer): TXMapDataObject;
begin
  if (aIndex >= 0) and (aIndex < FMapData.Count) then begin
    Result := FMapData[aIndex];
  end
  else
    Result := Nil;
end;


procedure TXMap.SetBlocksSize(aBlocksSize : integer);
begin
  if aBlocksSize > 0 then begin
    FBlocksSize  := aBlocksSize;

    FBlocksPixel := FBlocksSize + FBlocksGap;
  end;

  PaintBox.Invalidate;
end;


procedure TXMap.SetBlocksGap(aBlocksGap : integer);
begin
  if aBlocksGap > 0 then begin
    FBlocksGap  := aBlocksGap;

    FBlocksPixel := FBlocksSize + FBlocksGap;
  end;

  PaintBox.Invalidate;
end;


procedure TXMap.SetHighlightMode(aHighlightMode : boolean);
begin
  FHighlightMode := aHighlightMode;

  PaintBox.Invalidate;
end;


procedure TXMap.SetMode(aMode : integer);
begin
  FMode := aMode;

  case aMode of
    mapModeSize     : PaintBox.OnPaint := PaintBoxUpdateSize;
    mapModeQuantity : PaintBox.OnPaint := PaintBoxUpdateQuantity;
  end;

  PaintBox.Invalidate;
end;


// ================================================================================================
// ================================================================================================
// ================================================================================================


procedure TXMap.Clear;
begin
  FBusy    := True;
  FHasData := False;

  FFolderTotalCount := 0;
  FFolderTotalSize  := 0;

  FMapData.Clear;

  FBusy    := False;
end;


procedure TXMap.BeginData;
begin
  Clear;
end;


procedure TXMap.AddData(const aFolderName : string; aFileCount : integer; aFileSize : int64; aColour : integer);
var
  TXMDO : TXMapDataObject;

begin
  TXMDO := TXMapDataObject.Create;

  TXMDO.FolderName := aFolderName;
  TXMDO.FileCount  := aFileCount;
  TXMDO.FileSize   := aFileSize;
  TXMDO.Colour     := aColour;
  TXMDO.ColourBW   := ColourToBW(aColour);

  FMapData.Add(TXMDO);

  inc(FFolderTotalCount, aFileCount);
  inc(FFolderTotalSize, aFileSize);
end;


procedure TXMap.EndData;
begin
  FBusy    := False;
  FHasData := True;
end;


// ================================================================================================
// ================================================================================================
// ================================================================================================


function TXMap.ColourToBW(aColour : integer): integer;
var
  X, r, g, b : integer;

begin
  R := (aColour and $000000FF);
  G := (aColour and $0000FF00) shr 8;
  B := (aColour and $00FF0000) shr 16;

  X := Round((R * 0.30) + (G * 0.59) + (B * 0.11));

  Result := (X shl 16) + (X shl 8) + (X);
end;


end.
