{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Form.DBSelectedFolder;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls, Buttons, Grids, BaseGrid, AdvGrid, AdvObj,
  VCLTee.TeeProcs, VCLTee.TeEngine, VCLTee.Chart, VCLTee.Series, AdvSplitter, AdvUtil,
  VclTee.TeeGDIPlus,

  X.CFolderHistoryObject, X.Help,

  X.GridUtility, X.LanguageHandler, X.SystemGlobal, X.Windows;

type
  TfrmDBSelectedFolder = class(TForm)
    sgDatabase: TAdvStringGrid;
    Panel1: TPanel;
    Panel2: TPanel;
    bHelp: TBitBtn;
    bCopy: TBitBtn;
    bClose: TBitBtn;
    Image1: TImage;
    lFolder: TLabel;
    lCount: TLabel;
    lComputerName: TLabel;
    bFiles: TBitBtn;
    bSize: TBitBtn;
    vtcSelected: TChart;
    Series1: TBarSeries;
    Splitter1: TAdvSplitter;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure bHelpClick(Sender: TObject);
    procedure bCopyClick(Sender: TObject);
    procedure BuildGraph(Sender: TObject);
    procedure vtcSelectedMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure sgDatabaseResize(Sender: TObject);
    procedure sgDatabaseDrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure sgDatabaseGetCellColor(Sender: TObject; ARow, ACol: Integer;
      AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
    procedure Image1Click(Sender: TObject);
  private
    ComputerName, ScanPath : string;
    graphsizeformat : integer;
  public
    { Public declarations }
  end;

var
  frmDBSelectedFolder: TfrmDBSelectedFolder;

procedure DoDBSelectedFolder(const a, b : string);


implementation

{$R *.dfm}

uses
  X.Utility, X.MD5, X.Global, X.Settings, X.Constants, X.Conversions,

  X.Dialogs.Dialog;


const
  CGraphFormatKilobyte = 0;
  CGraphFormatMegabyte = 1;
  CGraphFormatGigabyte = 2;

  CDataFiles           = 0;
  CDataSize            = 1;


procedure DoDBSelectedFolder(const a, b : string);
 begin
  with TfrmDBSelectedFolder.Create(Application) do
    try
      ComputerName :=a;
      ScanPath     :=b;

      lComputerName.Caption :=a;
      lFolder.Caption       :=b;

      ShowModal;
    finally
      free;
    end;
end;


procedure TfrmDBSelectedFolder.FormCreate(Sender: TObject);
 var
  fd : TFormDetails;

 begin
  bClose.Caption := XText[rsCancel];

  bFiles.Caption := XText[rsFiles];
  bSize.Caption  := XText[rsSize];

  sgDatabase.ColWidths[1] := 80;
  sgDatabase.ColWidths[2] := 80;
  sgDatabase.ColWidths[3] := 80;
  sgDatabase.HideColumn(4);

  fd := XSettings.LoadFormDetails(_DBSelectedFolder);

  if fd.formID <> -1 then begin
    Width            := fd.w;
    Height           := fd.h;
    sgDatabase.Width := fd.p1;

    sgDatabaseResize(Nil);
  end;
end;


procedure TfrmDBSelectedFolder.FormClose(Sender: TObject;  var Action: TCloseAction);
 var
  fd : TFormDetails;

 begin
  fd.formID :=_DBSelectedFolder;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;
  fd.p1     := sgDatabase.Width;

  XSettings.SaveFormDetails(fd);

  Action := caFree;
end;


procedure TfrmDBSelectedFolder.FormShow(Sender: TObject);
 var
  tf : TextFile;
  s,xprop,xvalue : string;
  largestitem : int64;

 begin
  largestitem := 0;

  sgDatabase.Cells[0, 0] := XText[rsDateTime];
  sgDatabase.Cells[1, 0] := XText[rsFiles];
  sgDatabase.Cells[2, 0] := XText[rsSizeOfFiles];
  sgDatabase.Cells[3, 0] := XText[rsFolders];

  Caption := XText[rsSelectedFolder];

  bHelp.Caption   := XText[rsHelp];

  if FileExists(GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh') then begin
    AssignFile(tf, GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh');
    {$I-}
    Reset(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorOpening] + ': ' + XText[rsFolderHistory],
                  XText[rsErrorOpeningXinorbisSystemFile] + ': ' + #13#13 +
                  GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh',
                  XDialogTypeWarning);
    end
    else begin
      // read the first line, it contains the scan path --------------------------
      Readln(tf, s);
      // -------------------------------------------------------------------------

      while not(eof(tf)) do begin
        Readln(tf, s);

        if s[1] = '{' then begin
        end
        else if s[1] = '}' then begin
          sgDatabase.RowCount := sgDatabase.RowCount + 1;
        end
        else begin
          xprop  := Copy(s, 1, 3);
          xvalue := Copy(s, 5, length(s) - 4);

          case IdentifyProperty(xprop) of
            CPropertyScanDateString : sgDatabase.Cells[0, sgDatabase.RowCount - 1] := xvalue;
           // : sgDatabase.Cells[1, sgDatabase.RowCount - 1] := xvalue;
            CPropertyFileCount      : sgDatabase.Cells[1, sgDatabase.RowCount - 1] := xvalue;
            CPropertyTotalSize      : begin
                                        sgDatabase.Cells[2, sgDatabase.RowCount - 1] := TConvert.ConvertToUsefulUnit(StrToInt64(xvalue));
                                        sgDatabase.Cells[4, sgDatabase.RowCount - 1] := xvalue;

                                        largestitem := StrToInt64(xvalue);                            // ?
                                      end;
            CPropertyFolderCount    : sgDatabase.Cells[3, sgDatabase.RowCount - 1] := xvalue;
          end;
        end;
      end;

      CloseFile(tf);
    end;
    {$I+}

    sgDatabase.RowCount := sgDatabase.RowCount - 1;

    lCount.Caption := XText[rsFound] + ': ' + IntToStr(sgDatabase.RowCount - 1);

    if largestitem < (1024 * 1024) then
      graphsizeformat := CGraphFormatKilobyte
    else if largestitem < (1024 * 1024 * 1024) then
      graphsizeformat := CGraphFormatMegabyte
    else
      graphsizeformat := CGraphFormatGigabyte;

    BuildGraph(bFiles);      
  end
  else begin

  end;
end;


procedure TfrmDBSelectedFolder.Image1Click(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, '"' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\' + '"', '', '');
end;


procedure TfrmDBSelectedFolder.sgDatabaseDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
 var
  l,w : integer;

 begin
  if ARow <> 0 then begin
    case ACol of
      1,2,3 : begin
                w := TAdvStringGrid(Sender).Canvas.TextWidth(TAdvStringGrid(Sender).Cells[ACol, ARow]);
                l := TAdvStringGrid(Sender).ColWidths[ACol] - w;

                TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + l - 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
              end;
    end;
  end;
end;


procedure TfrmDBSelectedFolder.sgDatabaseGetCellColor(Sender: TObject; ARow,
  ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
begin
  if gdSelected in AState then
    ABrush.Color := CGridColourSelected
  else begin
    if Odd(ARow) then
      ABrush.Color := CGridColourOn
    else
      ABrush.Color := CGridColourOff;
  end;
end;


procedure TfrmDBSelectedFolder.sgDatabaseResize(Sender: TObject);
 begin
  sgDatabase.ColWidths[0] := sgDatabase.Width - (240 + 23);
end;


procedure TfrmDBSelectedFolder.vtcSelectedMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
var
  AValueIndex : integer;

begin
  Assert(Sender <> Nil, 'vtcSelectedMouseMove :: Nil chart');

  AValueIndex := TChart(Sender).SeriesList[0].GetCursorValueIndex;

  if AValueIndex > -1 then begin
    Screen.cursor := crHandPoint;

    sgDatabase.SelectRows(AValueIndex + 1, 1);
  end
  else begin
    Screen.cursor := crDefault;
  end;
end;


procedure TfrmDBSelectedFolder.bHelpClick(Sender: TObject);
 begin
  THelp.OpenHelpPage('dbselectedfolder.htm');
end;


procedure TfrmDBSelectedFolder.bCopyClick(Sender: TObject);
 begin
  TGridUtility.CopyGridToClipboard(0, sgDatabase);
end;


procedure TfrmDBSelectedFolder.BuildGraph(Sender: TObject);
 var
  t,dataselect : integer;
  doutput : double;

 begin
  dataselect :=TBitBtn(Sender).Tag;

  vtcSelected.SeriesList[0].Clear;

  for t := 1 to sgDatabase.RowCount - 1 do begin
    case dataselect of
      CDataFiles : vtcSelected.SeriesList[0].Add(StrToFloat(sgDatabase.Cells[1, t]), IntToStr(t), DefaultDisplayColours[1 + (t mod 12)]);
      CDataSize  : begin
                     case graphsizeformat of
                       CGraphFormatKilobyte : doutput := StrToInt64(sgDatabase.Cells[4, t]) / Int64(1024);               // size in KB
                       CGraphFormatMegabyte : doutput := StrToInt64(sgDatabase.Cells[4, t]) / Int64(1024 * 1024);        // size in MB
                       CGraphFormatGigabyte : doutput := StrToInt64(sgDatabase.Cells[4, t]) / Int64(1024 * 1024 * 1024); // size in GB
                     else
                       doutput := StrToInt64(sgDatabase.Cells[4, t]) / Int64(1024);                   // size in KB
                     end;

                              vtcSelected.SeriesList[0].Add(doutput, IntToStr(t), DefaultDisplayColours[1 + (t mod 12)]);
          end;
    end;
  end;
end;


end.
