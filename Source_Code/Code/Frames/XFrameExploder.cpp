//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameExploder.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameExploder *FrameExploder;
//---------------------------------------------------------------------------
__fastcall TFrameExploder::TFrameExploder(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------


/*
{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: January 28th 2002
  Last Modified: January 11th 2020
}


unit  X.Frame.Exploder;


interface


uses Vcl.Controls, Vcl.StdCtrls, AdvOfficeButtons, Vcl.ExtCtrls, HTMLabel,
  System.Classes,  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants,
  Vcl.Graphics, Vcl.Forms, dialogs, System.Generics.Collections, Vcl.Buttons,

  X.Form.Explore,

  X.CSizeOfFolder, X.CExploderDataObject,

  X.Constants, X.GlobalObjects, X.Conversions, X.Exploder, X.LanguageHandler,
  X.Windows;

type
  TFolderDetail = class
    Name  : string;
    Size  : int64;
    Count : integer;
  end;

  TFrameExploder = class(TFrame)
    pExploder: TPanel;
    pExploderTop: TPanel;
    lExploderFolder: TLabel;
    cbExploderSize: TAdvOfficeRadioButton;
    cbExploderQuantity: TAdvOfficeRadioButton;
    lExploderDetails: THTMLabel;
    lExploderDetails2: THTMLabel;
    shapeExploder: TShape;
    bEBack: TBitBtn;
    procedure cbExploderSizeClick(Sender: TObject);
    procedure pExploderResize(Sender: TObject);
    procedure bEBakClick(Sender: TObject);
  private
    FExploderCache  : TObjectList<TXExploderDataObject>;
    FDirectoryList  : TObjectList<TFolderDetail>;
    FDirectoryIndex : integer;
    FAddToCache     : boolean;

    FSource   : integer;

    FHasData  : boolean;
    FOldIndex : integer;

    XExploder : TXExploder;

    function  GetDataSource: integer;
    procedure SetDataSource(aDataSource : integer);

    procedure OnMouseMove(const aFolderID : integer);
    procedure OnMouseClick(aFolderID, aCount : integer; aSize : int64);
    procedure OnMouseDblClick(const aFolderID : integer);
    procedure OnMouseRightClick(const aFolderID : integer);
    procedure OnGoBack;

    procedure WMDestroy(var Msg: TWMDestroy); message WM_DESTROY;

    procedure AddToCache(const aFolderName : string; aFolderID, aFileCount : integer; aFileSize : int64; aColour : integer);

    procedure BuildFromCache;
    procedure BuildFromFolderID(aFolderID : integer; aCount : integer;aSize : int64);
  public
    procedure Init;
    procedure DeInit;

    procedure ClearExploder;

    procedure BeginData(const aCurrentFolder : string; aCount : integer; aSize : int64);
    procedure AddData(const aFolderName : string; aFolderID, aFileCount : integer; aFileSize : int64; aColour : integer);
    procedure EndData;

    property Source     : integer read FSource       write FSource;
    property DataSource : integer read GetDataSource write SetDataSource;
    property HasData    : boolean read FHasData;
  end;


var
  FrameExploder : TFrameExploder;


implementation

{$R *.dfm}


procedure TFrameExploder.WMDestroy(var Msg: TWMDestroy);
begin
  if (csDestroying in ComponentState)  then
    DeInit;

  inherited;
end;


void FrameExploder::Init()
{
  FrameExploder.DoubleBuffered := True;

  FExploderCache  := TObjectList<TXExploderDataObject>.Create;
  FDirectoryList  := TObjectList<TFolderDetail>.Create;
  FDirectoryIndex := -1;

  XExploder := TXExploder.Create(Self, pExploder);
  XExploder.Colour            := $00333333;
  XExploder.OnMouseClick      := OnMouseClick;
  XExploder.OnMouseRightClick := OnMouseRightClick;
  XExploder.OnMouseDblClick   := OnMouseDblClick;
  XExploder.OnMouseOver       := OnMouseMove;
  XExploder.OnGoBack          := OnGoBack;

  FHasData  := False;
  FOldIndex := -1;

  cbExploderSize.Caption     := XText[kBySize];
  cbExploderQuantity.Caption := XText[kByQuantity];
}


procedure TFrameExploder.DeInit;
begin
  FreeAndNil(XExploder);

  FreeAndNil(FDirectoryList);
  FreeAndNil(FExploderCache);
end;


procedure TFrameExploder.OnMouseMove(const aFolderID : integer);
var
  TXMDO : TXExploderDataObject;

begin
  if aFolderID <> -1 then begin
    if aFolderID <> FOldIndex then begin
      TXMDO := XExploder.Item[aFolderID];

      if TXMDO.FolderName = '\' then
        lExploderFolder.Caption      := TXMDO.FolderName
      else
		lExploderFolder.Caption      := FDirectoryList[FDirectoryList.Count - 1].Name + TXMDO.FolderName + '\';

	  lExploderDetails.HTMLText[0]  := '<b>' + IntToStr(TXMDO.FileCount) + '</b> ' + XText[kFiles]   + ' (<b>' + FloatToStrF((TXMDO.FileCount / XExploder .FolderTotalCount) * 100, ffFixed, 7, 2) + '%</b>)';
      lExploderDetails2.HTMLText[0] := '<b>' + TConvert.ConvertToUsefulUnit(TXMDO.FileSize) + '</b> ' + ' (<b>' + FloatToStrF((TXMDO.FileSize / XExploder.FolderTotalSize) * 100, ffFixed, 7, 2) + '%</b>)';

      shapeExploder.Brush.Color := TXMDO.Colour;

      FOldIndex := aFolderID;
    end;
  end
  else begin
    if FDirectoryList.Count = 1 then
      lExploderFolder.Caption       := ''
    else
      lExploderFolder.Caption       := '<- <b>' + FDirectoryList[FDirectoryList.Count - 1].Name + '</b>';

    lExploderDetails.HTMLText[0]  := '';
    lExploderDetails2.HTMLText[0] := '';

    shapeExploder.Brush.Color     := $00ffffff;

    FOldIndex := -1;
  end;
end;


procedure TFrameExploder.pExploderResize(Sender: TObject);
begin
  XExploder.Resize;
end;


procedure TFrameExploder.OnMouseClick(aFolderID, aCount : integer; aSize : int64);
begin
  if aFolderID <> -1 then begin
    BuildFromFolderID(aFolderID, aCount, aSize);
  end;
end;


procedure TFrameExploder.OnGoBack;
var
  lFolderID : integer;

begin
  if FDirectoryIndex > 0 then begin
    FDirectoryList.Delete(FDirectoryList.Count - 1);

    FDirectoryIndex := FDirectoryList.Count - 1;

    lFolderID := GScanDetails[FSource].GetFullFolderIndex(FDirectoryList[FDirectoryIndex].Name);

    if FDirectoryIndex = 0 then begin // use cached data
      BuildFromCache;
    end
    else begin
      BuildFromFolderID(lFolderID,
                        FDirectoryList[FDirectoryIndex].Count,
                        FDirectoryList[FDirectoryIndex].Size);
    end;
  end;
end;


procedure TFrameExploder.OnMouseDblClick(const aFolderID : integer);
var
  TXMDO : TXExploderDataObject;

begin
  if aFolderID <> -1 then begin
    TXMDO := XExploder.Item[aFolderID];

    if TXMDO.FolderName = '\' then
      DoExplore(FSource, TXMDO.FolderName)
    else
      DoExplore(FSource, FDirectoryList[FDirectoryList.Count - 1].Name + TXMDO.FolderName + '\');
  end;
end;


procedure TFrameExploder.OnMouseRightClick(const aFolderID : integer);
var
  TXMDO : TXExploderDataObject;

begin
  if aFolderID <> -1 then begin
    TXMDO := XExploder.Item[aFolderID];

    if TXMDO.FolderName = '\' then
      TXWindows.ExecuteFile(0, '"' + TXMDO.FolderName + '"', '', '')
    else
      TXWindows.ExecuteFile(0, '"' + FDirectoryList[FDirectoryList.Count - 1].Name + TXMDO.FolderName + '\' + '"', '', '');
  end;
end;


procedure TFrameExploder.ClearExploder;
begin
  FHasData         := False;

  FOldIndex        := -1;
end;


procedure TFrameExploder.BeginData(const aCurrentFolder : string; aCount : integer; aSize : int64);
var
  lCanAdd : boolean;
  TFD     : TFolderDetail;

begin
  XExploder.BeginData(aCurrentFolder);

  FAddToCache := False;
  FOldIndex   := -1;
  lCanAdd     := False;

  if FDirectoryList.Count = 0 then begin
    lCanAdd     := True;

    FAddToCache := True;
  end
  else begin
    if FDirectoryList[FDirectoryList.Count - 1].Name <> aCurrentFolder then
      lCanAdd := True;
  end;

  if lCanAdd then begin
    TFD := TFolderDetail.Create;

    TFD.Name  := aCurrentFolder;
    TFD.Size  := aSize;
    TFD.Count := aCount;

    FDirectoryList.Add(TFD);

    FDirectoryIndex := FDirectoryList.Count - 1;
  end;
end;


procedure TFrameExploder.cbExploderSizeClick(Sender: TObject);
begin
  if cbExploderSize.Checked then
    XExploder.Mode := mapModeSize
  else
    XExploder.Mode := mapModeQuantity;
end;


procedure TFrameExploder.AddData(const aFolderName : string; aFolderID, aFileCount : integer; aFileSize : int64; aColour : integer);
begin
  XExploder.AddData(aFolderName, aFolderID, aFileCount, aFileSize, aColour);

  if FAddToCache then begin
    AddToCache(aFolderName, aFolderID, aFileCount, aFileSize, aColour);
  end;
end;


procedure TFrameExploder.EndData;
begin
  XExploder.EndData;

  FHasData := True;

  bEBack.Enabled := FDirectoryList.Count > 1;
end;


function  TFrameExploder.GetDataSource: integer;
begin
  Result := XExploder.DataSource;
end;


procedure TFrameExploder.SetDataSource(aDataSource : integer);
begin
  if aDataSource <> XExploder.DataSource then
    ClearExploder;

  XExploder.DataSource := aDataSource;
end;


procedure TFrameExploder.AddToCache(const aFolderName : string; aFolderID, aFileCount : integer; aFileSize : int64; aColour : integer);
var
  TXMDO : TXExploderDataObject;

begin
  TXMDO := TXExploderDataObject.Create;

  TXMDO.FolderName := aFolderName;
  TXMDO.FolderID   := aFolderID;
  TXMDO.FileCount  := aFileCount;
  TXMDO.FileSize   := aFileSize;
  TXMDO.Colour     := aColour;

  FExploderCache.Add(TXMDO);
end;


procedure TFrameExploder.bEBakClick(Sender: TObject);
begin
  OnGoBack;
end;


procedure TFrameExploder.BuildFromCache;
var
  t : integer;

begin
  BeginData(FDirectoryList[0].Name, FDirectoryList[0].Size, FDirectoryList[0].Count);

  for t := 0 to FExploderCache.Count - 1 do begin

    AddData(FExploderCache[t].FolderName,
            FExploderCache[t].FolderID,
            FExploderCache[t].FileCount,
            FExploderCache[t].FileSize,
            FExploderCache[t].Colour);
  end;

  EndData;
end;


procedure TFrameExploder.BuildFromFolderID(aFolderID, aCount : integer; aSize : int64);
var
  i, lColourMod : integer;
  tsof : TSizeOfFolder;
  lSize  : int64;
  lCount : integer;

begin
  i          := 0;
  lColourMod := 0;

  lSize      := 0;
  lCount     := 0;

  if GScanDetails[FSource].Files.Count > 0 then begin

    BeginData(GScanDetails[FSource].Folders[aFolderID],
              aCount, aSize);

    while i < GScanDetails[FSource].Files.Count do begin
      if GScanDetails[FSource].Files.Items[i].FilePathIndex = aFolderID then begin

        if ((faDirectory and GScanDetails[FSource].Files.Items[i].Attributes) = faDirectory) then begin

          // cache the results in the FileSize, FileSizeOnDisk, and FileCategory parameters of the file object as these aren't used for folders
          // ===================================================================================================================
          if GScanDetails[FSource].Files.Items[i].FileSize = 0 then begin

            tsof := GXinorbisScan.SizeOfFolder(GScanDetails[FSource].Folders[GScanDetails[FSource].Files.Items[i].FilePathIndex] + GScanDetails[FSource].Files.Items[i].FileName);

            GScanDetails[FSource].Files.Items[i].FileSize       := tsof.Data[XFileUsed];
            GScanDetails[FSource].Files.Items[i].FileSizeOnDisk := tsof.Data[XSpaceUsed];

            GScanDetails[FSource].Files.Items[i].FileCategory    := tsof.Data[XCount];
          end
          else begin
            tsof.Data[XFileUsed]  := GScanDetails[FSource].Files.Items[i].FileSize;
            tsof.Data[XSpaceUsed] := GScanDetails[FSource].Files.Items[i].FileSizeOnDisk;

            tsof.Data[XCount]     := GScanDetails[FSource].Files.Items[i].FileCategory;
          end;

          AddData(GScanDetails[FSource].Files.Items[i].FileName, GScanDetails[FSource].GetFullFolderIndex(GScanDetails[FSource].Folders[GScanDetails[FSource].Files.Items[i].FilePathIndex] + GScanDetails[FSource].Files.Items[i].FileName + '\'),
                 tsof.Data[XCount],
                 tsof.Data[XFileUsed],
                 spectrumcolours[lColourMod mod spectrummod]);

          inc(lSize,  tsof.Data[XFileUsed]);
          inc(lCount, tsof.Data[XCount]);

          inc(lColourMod);
        end;
      end;

      inc(i);
    end;

    if (aSize <> -1) and (aCount <> -1) then begin
      if (lSize <> aSize) or (lCount <> aCount) then begin
        AddData('/', -1,
                aCount - lCount,
                aSize - lSize,
                spectrumcolours[lColourMod mod spectrummod]);
      end;
    end;

    EndData;

    // =========================================================================
  end;
end;
*/
