// ============================================================================
//
// (c) Paul Alan Freshney 2012-2019
// www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com
//
// ============================================================================

unit X.Exploder;


interface


uses
  ExtCtrls, classes, controls, types, sysutils, graphics, math, contnrs, dialogs,
  System.Generics.Collections,

  X.CExploderDataObject,

  X.Conversions;


type
  TMouseClickEvent  = procedure(aFolderID, aCount : integer; aSize : int64) of object;
  TMouseRightClick  = procedure(const aFolderID : integer) of object;
  TMouseDoubleClick = procedure(const aFolderID : integer) of object;
  TMouseOverEvent   = procedure(const aFolderID : integer) of object;
  TOnGoBackEvent    = procedure of object;

  TXExploder = class
  private
    FCurrentFolder         : string;
    FCentreX               : integer;
    FCentreY               : integer;
    FSliceAngle            : double;
    FMaxRadius             : double;
    FSelectedSlice         : integer;
    FSelectedOldSlice      : integer;
    FHubRadius             : integer;
    FSliceForText          : double;
    FBackgroundColour      : integer;

    FLargestSize           : int64;
    FLargestQuantity       : integer;

    FOnMouseClick      : TMouseClickEvent;
    FOnMouseRightClick : TMouseRightClick;
    FOnMouseDblClick   : TMouseDoubleClick;
    FOnMouseOver       : TMouseOverEvent;
    FOnGoBack          : TOnGoBackEvent;

    PaintBox          : TPaintBox;

    FExploderData     : TObjectList<TXExploderDataObject>;

    FBusy       : boolean;
    FHasData    : boolean;
    FMode       : integer;
    FDataSource : integer;

    FFolderTotalCount : integer;
    FFolderTotalSize  : int64;

    procedure ClearDisplay;
    procedure DrawHub;
    procedure DrawText(const aText : string; aX5, aY5 : integer);
    procedure DrawPie(const aText : string; aStartAngle, aSliceAngle, aSliceRadius : double; aColour : integer);

    procedure PaintBoxUpdateQuantity(Sender: TObject);
    procedure PaintBoxUpdateSize(Sender: TObject);
    procedure PaintBoxMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure PaintBoxMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);

    function  GetExploderItemFrom(x, y : integer): integer;

    function  GetExploderItem(aIndex : integer): TXExploderDataObject;
    procedure SetMode(aMode : integer);

    procedure CalculatePies;
 public
    constructor Create(AOwner: TComponent; Zig : TWinControl);
    destructor  Destroy; Override;

    procedure New;
    procedure Clear;

    procedure Resize;

    procedure BeginData(const aCurrentFolder : string);
    procedure AddData(const aFolderName : string; aFolderID, aFileCount : integer; aFileSize : int64; aColour : integer);
    procedure EndData;

    property  DataSource            : integer              read FDataSource       write FDataSource;
    property  Item[Index : integer] : TXExploderDataObject read GetExploderItem;
    property  Mode                  : integer              read FMode             write SetMode;

    property  FolderTotalCount      : integer              read FFolderTotalCount;
    property  FolderTotalSize       : int64                read FFolderTotalSize;

    property  Colour                : integer              read FBackgroundColour  write FBackgroundColour;

    property  OnMouseClick          : TMouseClickEvent     read FOnMouseClick      write FOnMouseClick;
    property  OnMouseRightClick     : TMouseRightClick     read FOnMouseRightClick write FOnMouseRightClick;
    property  OnMouseDblClick       : TMouseDoubleClick    read FOnMouseDblClick   write FOnMouseDblClick;
    property  OnMouseOver           : TMouseOverEvent      read FOnMouseOver       write FOnMouseOver;
    property  OnGoBack              : TOnGoBackEvent       read FOnGoBack          write FOnGoBack;
  protected
  end;


const
  mapModeSize     = 0;
  mapModeQuantity = 1;


implementation


// ================================================================================================
// ================================================================================================
// ================================================================================================


constructor TXExploder.Create(AOwner: TComponent; Zig : TWinControl);
begin
  FExploderData        := TObjectList<TXExploderDataObject>.Create;

  PaintBox             := TPaintBox.Create(AOwner);
  PaintBox.Parent      := Zig;
  PaintBox.Align       := alClient;
  PaintBox.OnPaint     := PaintBoxUpdateSize;
  PaintBox.OnMouseDown := PaintBoxMouseDown;
  PaintBox.OnMouseMove := PaintBoxMouseMove;

  FHasData             := False;
  FBusy                := False;
  FDataSource          := -1;

  FSelectedSlice       := -1;
  FSelectedOldSlice    := -1;

  FSliceForText        := 28; // degrees

  FLargestSize         := -1;
  FLargestQuantity     := -1;

  FMaxRadius           := Min(PaintBox.Height, PaintBox.Width) - 20;
  FHubRadius           := 25;
end;


destructor TXExploder.Destroy;
begin
  PaintBox.Free;

  FExploderData.Free;

  inherited Destroy;
end;


procedure TXExploder.Resize;
begin
  FMaxRadius    := Round(Min(PaintBox.Height, PaintBox.Width) / 2) - 50;

  FCentreX      := Round(PaintBox.Width / 2);
  FCentreY      := Round(PaintBox.Height / 2);

  FSliceForText := 28; // degrees

  PaintBox.Invalidate;
end;


procedure TXExploder.ClearDisplay;
begin
  PaintBox.Canvas.Brush.Color := FBackgroundColour;
  PaintBox.Canvas.FillRect(Rect(0, 0, PaintBox.Width - 1, PaintBox.Height - 1));
end;


procedure TXExploder.DrawHub;
begin
  PaintBox.Canvas.Brush.Color := FBackgroundColour;
  PaintBox.Canvas.Pen.Color   := clBlack;
  PaintBox.Canvas.Ellipse(FCentreX - FHubRadius, FCentreY - FHubRadius, FCentreX + FHubRadius, FCentreY + FHubRadius);
end;


procedure TXExploder.DrawText(const aText : string; aX5, aY5 : integer);
begin
  PaintBox.Canvas.Brush.Color := FBackgroundColour;
  PaintBox.Canvas.Brush.Style := bsClear;
  PaintBox.Canvas.Pen.Color := clBlack;
  PaintBox.Canvas.TextOut(aX5, aY5, aText);
end;


procedure TXExploder.DrawPie(const aText : string; aStartAngle, aSliceAngle, aSliceRadius : double; aColour : integer);
var
  X1, X2, X3, X4, X5 : integer;
  Y1, Y2, Y3, Y4, Y5 : integer;
  lRadius, lOrientation : integer;

begin
  lRadius := 50 + Round(FMaxRadius * aSliceRadius);

  X1 := FCentreX - lRadius;
  Y1 := FCentreY - lRadius;
  X2 := FCentreX + lRadius;
  Y2 := FCentreY + lRadius;

  { negative signs on "Y" values to correct for "flip" from normal math defintion for "Y" dimension }
  X3 := FCentreX + Round(lRadius * Cos(DegToRad(aStartAngle)));
  Y3 := FCentreY - Round(lRadius * Sin(DegToRad(aStartAngle)));
  X4 := FCentreX + Round(lRadius * Cos(DegToRad(aSliceAngle)));
  Y4 := FCentreY - Round(lRadius * Sin(DegToRad(aSliceAngle)));

  PaintBox.Canvas.Brush.Color := aColour;
  PaintBox.Canvas.Brush.Style := bsSolid;

  PaintBox.Canvas.Pie(X1, Y1, X2, Y2, X3, Y3, X4, Y4);

  //== draw text ===============================================================
  // +10 is a naughty hack to centre the text within the slice. the co-ords
  // refer to the top left corner of the text (not the centre :(

  // only draw the text if the slices are above a minimum width (so the text fits nicely)
  if (FSliceForText <= FSliceAngle) then begin

    lOrientation := Round(aStartAngle + ((aSliceAngle - aStartAngle) / 2));

    PaintBox.Canvas.Font.Size := 12;

    if (lOrientation > 90) and (lOrientation < 270) then begin
      inc(lOrientation, 180);

      PaintBox.Canvas.Font.Orientation := lOrientation * 10;

      X5 := FCentreX + Round((FHubRadius + 20 + (PaintBox.Canvas.TextWidth(aText))) * Cos(DegToRad(aStartAngle - 5 + (((aSliceAngle - aStartAngle) / 2)))));
      Y5 := FCentreY - Round((FHubRadius + 20 + (PaintBox.Canvas.TextWidth(aText))) * Sin(DegToRad(aStartAngle - 5 + (((aSliceAngle - aStartAngle) / 2)))));
    end
    else begin
      PaintBox.Canvas.Font.Orientation := lOrientation * 10;

      X5 := FCentreX + Round((FHubRadius + 20) * Cos(DegToRad(aStartAngle + 10 + (((aSliceAngle - aStartAngle) / 2)))));
      Y5 := FCentreY - Round((FHubRadius + 20) * Sin(DegToRad(aStartAngle + 10 + (((aSliceAngle - aStartAngle) / 2)))));
    end;

    DrawText(aText, X5, Y5);
  end;
end;


procedure TXExploder.PaintBoxUpdateSize(Sender: TObject);
var
  t : integer;
  TXMDO : TXExploderDataObject;

begin
  ClearDisplay;

  if FExploderData.Count <> 0 then begin

    for t:= 0 to FExploderData.Count - 1 do begin
      TXMDO := FExploderData[t];

      if FSelectedSlice <> t then begin
        DrawPie(TXMDO.FolderName + ' (' + TConvert.ConvertToUsefulUnit(TXMDO.FileSize) + ')',
                t * FSliceAngle, (t * FSliceAngle) + FSliceAngle,
                TXMDO.PieSize,
                TXMDO.Colour);
      end;
    end;

    if (FSelectedSlice <> -1) then begin
      if (FExploderData.Count > 1) then
        DrawPie(FExploderData[FSelectedSlice].FolderName + ' (' + TConvert.ConvertToUsefulUnit(FExploderData[FSelectedSlice].FileSize) + ')',
                (FSelectedSlice * FSliceAngle), (FSelectedSlice * FSliceAngle) + FSliceAngle,
                FExploderData[FSelectedSlice].PieSize,
                $00CCCCCC)
      else
        DrawPie(FExploderData[FSelectedSlice].FolderName + ' (' + TConvert.ConvertToUsefulUnit(FExploderData[FSelectedSlice].FileSize) + ')',
                (FSelectedSlice * FSliceAngle), (FSelectedSlice * FSliceAngle) + FSliceAngle,
                FExploderData[FSelectedSlice].PieSize,
                FExploderData[FSelectedSlice].Colour)
    end;
  end;

  DrawHub;
end;


procedure TXExploder.PaintBoxUpdateQuantity(Sender: TObject);
var
  t : integer;
  TXMDO : TXExploderDataObject;

begin
  ClearDisplay;

  if FExploderData.Count <> 0 then begin

    for t:= 0 to FExploderData.Count - 1 do begin
      TXMDO := FExploderData[t];

     if FSelectedSlice <> t then
        DrawPie(TXMDO.FolderName + ' (' + IntToStr(TXMDO.FileCount) + ')',
                t * FSliceAngle, (t * FSliceAngle) + FSliceAngle,
                TXMDO.PieQuantity,
                TXMDO.Colour);
    end;

    if (FSelectedSlice <> -1) then begin
      if (FExploderData.Count > 1) then
        DrawPie(FExploderData[FSelectedSlice].FolderName + ' (' + IntToStr(FExploderData[FSelectedSlice].FileCount) + ')',
                (FSelectedSlice * FSliceAngle), (FSelectedSlice * FSliceAngle) + FSliceAngle,
                FExploderData[FSelectedSlice].PieQuantity,
                $00CCCCCC)
      else
        DrawPie(FExploderData[FSelectedSlice].FolderName + ' (' + IntToStr(FExploderData[FSelectedSlice].FileCount) + ')',
                (FSelectedSlice * FSliceAngle), (FSelectedSlice * FSliceAngle) + FSliceAngle,
                FExploderData[FSelectedSlice].PieQuantity,
                FExploderData[FSelectedSlice].Colour);
    end;
  end;

  DrawHub;
end;


procedure TXExploder.PaintBoxMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  lItem : integer;

begin
  if Assigned(FOnMouseOver) and (FHasData) then begin
    if (ssLeft in Shift) then begin
      lItem := GetExploderItemFrom(X, Y);

      FSelectedSlice := lItem;

      if lItem <> -1 then begin
        PaintBox.Invalidate;

        if FExploderData[lItem].FolderName <> '\' then begin // represents root of the folder, can't enter it!
          if Assigned(FOnMouseClick) then
            FOnMouseClick(FExploderData[lItem].FolderID,
                          FExploderData[lItem].FileCount,
                          FExploderData[lItem].FileSize);
        end;
      end
      else
        if Assigned(FOnGoBack) then begin
          FOnGoBack;

          PaintBox.Invalidate;
        end;
    end
    else if (ssRight in Shift) then begin
      if Assigned(FOnMouseRightClick) and (FHasData) then begin
        lItem := GetExploderItemFrom(X, Y);

        FSelectedSlice := lItem;

        if FSelectedSlice <> FSelectedOldSlice then begin
          PaintBox.Invalidate;

          FSelectedOldSlice := FSelectedSlice;
        end;

        FOnMouseRightClick(lItem);
      end;
    end
    else if (ssMiddle in Shift) then begin
      if Assigned(FOnMouseDblClick) and (FHasData) then begin
        lItem := GetExploderItemFrom(X, Y);

        FSelectedSlice := lItem;

        if FSelectedSlice <> FSelectedOldSlice then begin
          PaintBox.Invalidate;

          FSelectedOldSlice := FSelectedSlice;
        end;

        FOnMouseDblClick(lItem);
      end;
    end;
  end;
end;


procedure TXExploder.PaintBoxMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
var
  lItem : integer;

begin
  if Assigned(FOnMouseOver) and (FHasData) then begin
    lItem := GetExploderItemFrom(X, Y);

    FSelectedSlice := lItem;

    if FSelectedSlice <> FSelectedOldSlice then begin
      PaintBox.Invalidate;

      FSelectedOldSlice := FSelectedSlice;
    end;

    FOnMouseOver(lItem);
  end;
end;


// ================================================================================================
// ================================================================================================
// ================================================================================================


function  TXExploder.GetExploderItemFrom(x, y : integer): integer;
var
  lDeg : integer;
  lRad : double;
  lRadius : double;

begin
  Result := -1;

  // first check that we're outside the hub
  lRadius := Sqrt(((FCentreY - y) * (FCentreY - y)) + ((x - FCentreX) * (x - FCentreX)));

  if lRadius < FHubRadius then begin

  end
  else begin
    lRad := ArcTan2(FCentreY - y, x - FCentreX);

    lDeg := Round(lRad * (180 / PI));

    if FExploderData.Count > 0 then begin
      if lDeg < 0 then
        lDeg := lDeg + 360;

      Result := Ceil(lDeg / ((1 / FExploderData.Count) * 360)) - 1;

//    showmessage(inttostr(ldeg) + ' ' + inttostr(result) + ' ' + inttostr(FCentreY - y) + ' ' + inttostr(x-fcentrex));
    end;
  end;
end;


function TXExploder.GetExploderItem(aIndex : integer): TXExploderDataObject;
begin
  if (aIndex >= 0) and (aIndex < FExploderData.Count) then begin
    Result := FExploderData[aIndex];
  end
  else
    Result := Nil;
end;


procedure TXExploder.SetMode(aMode : integer);
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


procedure TXExploder.New;
begin
  {}
end;


procedure TXExploder.Clear;
begin
  FExploderData.Clear;

  FBusy             := True;
  FHasData          := False;

  FFolderTotalCount := 0;
  FFolderTotalSize  := 0;

  FLargestSize      := -1;
  FLargestQuantity  := -1;

  FBusy             := False;
end;


procedure TXExploder.BeginData(const aCurrentFolder : string);
begin
  Clear;

  FCurrentFolder := aCurrentFolder;
end;


procedure TXExploder.AddData(const aFolderName : string; aFolderID, aFileCount : integer; aFileSize : int64; aColour : integer);
var
  TXMDO : TXExploderDataObject;

begin
  TXMDO := TXExploderDataObject.Create;

  TXMDO.FolderName := aFolderName;
  TXMDO.FolderID   := aFolderID;
  TXMDO.FileCount  := aFileCount;
  TXMDO.FileSize   := aFileSize;
  TXMDO.Colour     := aColour;

  FExploderData.Add(TXMDO);

  inc(FFolderTotalCount, aFileCount);
  inc(FFolderTotalSize, aFileSize);

  if (FLargestSize < aFileSize) then
    FLargestSize := aFileSize;

  if (FLargestQuantity < aFileCount) then
    FLargestQuantity := aFileCount;
end;


procedure TXExploder.EndData;
begin
  FHasData          := True;
  FSelectedSlice    := -1;
  FSelectedOldSlice := -1;
  
  CalculatePies;

  PaintBox.Invalidate;

  FBusy    := False;
end;


procedure TXExploder.CalculatePies;
var
  TXMDO : TXExploderDataObject;
  t : integer;

begin
  if FExploderData.Count <> 0 then begin
    FSliceAngle := (1 / FExploderData.Count) * 360;

    for t:= 0 to FExploderData.Count - 1 do begin

      TXMDO := FExploderData[t];

      if FFolderTotalSize <> 0 then
        FExploderData[t].PieSize     := (TXMDO.FileSize  / FLargestSize)
      else
        FExploderData[t].PieSize     := 1;

      if FFolderTotalCount <> 0 then
        FExploderData[t].PieQuantity := (TXMDO.FileCount / FLargestQuantity)
      else
        FExploderData[t].PieQuantity := 1;
    end;
  end
  else begin
    TXMDO := TXExploderDataObject.Create;

    TXMDO.FolderName  := '';
    TXMDO.FolderID    := -1;
    TXMDO.FileCount   := 0;
    TXMDO.FileSize    := 0;
    TXMDO.Colour      := $00cccccc;
    TXMDO.PieSize     := 100;
    TXMDO.PieQuantity := 100;

    FExploderData.Add(TXMDO);
  end;
end;


// ================================================================================================
// ================================================================================================
// ================================================================================================


end.
