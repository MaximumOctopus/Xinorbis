//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameMap *FrameMap;
//---------------------------------------------------------------------------
__fastcall TFrameMap::TFrameMap(TComponent* Owner)
	: TFrame(Owner)
{
}



/*

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.ExtCtrls, Vcl.StdCtrls,

  AdvOfficeButtons,

  X.Form.Explore,

  X.Constants, X.GlobalObjects, X.Conversions, X.Map, X.LanguageHandler, HTMLabel;


type
  TFrameMap = class(TFrame)
    pMap: TPanel;
    Panel1: TPanel;
    lMapFolder: TLabel;
    cbMapSize: TAdvOfficeRadioButton;
    cbMapQuantity: TAdvOfficeRadioButton;
    lMapDetails: THTMLabel;
    lMapDetails2: THTMLabel;
    lMapSize: TLabel;
    cbMapSizeSelect: TComboBox;
    shapeMap: TShape;
    cbHighlightMode: TAdvOfficeCheckBox;
    procedure cbMapSizeClick(Sender: TObject);
    procedure cbMapSizeSelectChange(Sender: TObject);
    procedure cbHighlightModeClick(Sender: TObject);
  private
    FSource   : integer;

    FHasData  : boolean;
    FOldIndex : integer;

    XMap : TXMap;

    function  GetDataSource: integer;
    procedure SetDataSource(aDataSource : integer);

    procedure OnMouseMove(const aFolderID : integer);
    procedure OnMouseClick(const aFolderID : integer);

    procedure WMDestroy(var Msg: TWMDestroy); message WM_DESTROY;
  public
    procedure Init;
    procedure DeInit;

    procedure ClearMap;

    procedure BeginData;
    procedure AddData(const aFolderName : string; aFileCount : integer; aFileSize : int64; aColour : integer);
    procedure EndData;

    property Source     : integer read FSource       write FSource;
    property DataSource : integer read GetDataSource write SetDataSource;
    property HasData    : boolean read FHasData;
  end;


var
  FrameMap : TFrameMap;


implementation


{$R *.dfm}


const
  CBlockSizeA = 0;
  CBlockSizeB = 1;


procedure TFrameMap.WMDestroy(var Msg: TWMDestroy);
begin
  if (csDestroying in ComponentState)  then
    DeInit;

  inherited;
end;


procedure TFrameMap.Init;
begin
  FrameMap.DoubleBuffered := True;

  XMap := TXMap.Create(Self, pMap);
  XMap.OnMouseClick := OnMouseClick;
  XMap.OnMouseOver  := OnMouseMove;

  FHasData  := False;
  FOldIndex := -1;

  cbMapSize.Caption     := XText[kBySize];
  cbMapQuantity.Caption := XText[kByQuantity];
  lMapSize.Caption      := XText[kSize];
end;


procedure TFrameMap.DeInit;
begin
  FreeAndNil(XMap);
end;


procedure TFrameMap.OnMouseMove(const aFolderID : integer);
var
  TXMDO : TXMapDataObject;

begin
  if aFolderID <> -1 then begin
    if aFolderID <> FOldIndex then begin
      TXMDO := XMap.Item[aFolderID];

      if TXMDO.FolderName = '\' then
        lMapFolder.Caption      := TXMDO.FolderName
      else
        lMapFolder.Caption      := '\' + TXMDO.FolderName + '\';

	  lMapDetails.HTMLText[0]  := '<b>' + IntToStr(TXMDO.FileCount) + '</b> ' + XText[kFiles]   + ' (<b>' + FloatToStrF((TXMDO.FileCount / XMap.FolderTotalCount) * 100, ffFixed, 7, 2) + '%</b>)';
      lMapDetails2.HTMLText[0] := '<b>' + TConvert.ConvertToUsefulUnit(TXMDO.FileSize) + '</b> ' + ' (<b>' + FloatToStrF((TXMDO.FileSize / XMap.FolderTotalSize) * 100, ffFixed, 7, 2) + '%</b>)';

      shapeMap.Brush.Color := TXMDO.Colour;

      FOldIndex := aFolderID;
    end;
  end
  else begin
    lMapFolder.Caption       := '';
    lMapDetails.HTMLText[0]  := '';
    lMapDetails2.HTMLText[0] := '';

    FOldIndex                := -1;

    shapeMap.Brush.Color     := $00ffffff;
  end;
end;


procedure TFrameMap.OnMouseClick(const aFolderID : integer);
var
  TXMDO : TXMapDataObject;

begin
  if aFolderID <> -1 then begin
    TXMDO := XMap.Item[aFolderID];

    if TXMDO.FolderName = '\' then
      DoExplore(FSource, GScanDetails[FSource].ScanPath)
    else
      DoExplore(FSource, GScanDetails[FSource].ScanPath + TXMDO.FolderName + '\');
  end;
end;


procedure TFrameMap.ClearMap;
begin
  XMap.Clear;

  FHasData  := False;
  FOldIndex := -1;
end;


procedure TFrameMap.BeginData;
begin
  XMap.BeginData;
end;


procedure TFrameMap.cbHighlightModeClick(Sender: TObject);
begin
  XMap.HighlightMode := cbHighlightMode.Checked;
end;


procedure TFrameMap.cbMapSizeClick(Sender: TObject);
begin
  if cbMapSize.Checked then
    XMap.Mode := mapModeSize
  else
    XMap.Mode := mapModeQuantity;
end;


procedure TFrameMap.cbMapSizeSelectChange(Sender: TObject);
begin
  case cbMapSizeSelect.ItemIndex of
    CBlockSizeA : begin
                    XMap.BlocksSize := 4;
                    XMap.BlocksGap  := 1;
                  end;
    CBlockSizeB : begin
                    XMap.BlocksSize := 5;
                    XMap.BlocksGap  := 1;
                  end;
  end;
end;

procedure TFrameMap.AddData(const aFolderName : string; aFileCount : integer; aFileSize : int64; aColour : integer);
begin
  XMap.AddData(aFolderName, aFileCount, aFileSize, aColour);
end;


procedure TFrameMap.EndData;
begin
  XMap.EndData;

  FHasData := True;
end;


function  TFrameMap.GetDataSource: integer;
begin
  Result := XMap.DataSource;
end;


procedure TFrameMap.SetDataSource(aDataSource : integer);
begin
  if aDataSource <> XMap.DataSource then
    ClearMap;

  XMap.DataSource := aDataSource;
end;


end.
*/
