{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: January 16th 2019
  Last Modified: January 11th 2020
}


unit X.Form.DatabaseInfo;

interface

uses
  Windows, Messages, System.SysUtils, System.Variants, Classes, Graphics, Controls, Forms,
  System.UITypes, Dialogs, ExtCtrls, ComCtrls, StdCtrls, Buttons, Grids, BaseGrid, AdvGrid,
  AdvObj, HTMLabel, AdvUtil,

  X.Dialogs.Save,

  X.Help, X.GridUtility, X.CTableDetails, X.LanguageHandler, X.SystemGlobal,
  X.Windows;

type
  TfrmDatabaseInfo = class(TForm)
    sgDatabase: TAdvStringGrid;
    Panel1: TPanel;
    Image1: TImage;
    lSize: TLabel;
    lTables: TLabel;
    Panel2: TPanel;
    sbShowNames: TBitBtn;
    sbDeleteTable: TBitBtn;
    Bevel2: TBevel;
    bSave: TBitBtn;
    Bevel3: TBevel;
    bExportCSV: TBitBtn;
    bExportXML: TBitBtn;
    bCancel: TBitBtn;
    lDatabaseSize: THTMLabel;
    lTableCount: THTMLabel;
    sbSearch: TSpeedButton;
    BitBtn1: TBitBtn;
    Bevel1: TBevel;
    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure sbShowNamesClick(Sender: TObject);
    procedure bSaveClick(Sender: TObject);
    procedure sbDeleteTableClick(Sender: TObject);
    procedure bExportCSVClick(Sender: TObject);
    procedure bExportXMLClick(Sender: TObject);
    procedure sgDatabaseClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure DeleteFromDatabaseXFH(const filename, date : string);
    procedure sgDatabaseResize(Sender: TObject);
    procedure sgDatabaseGetCellColor(Sender: TObject; ARow, ACol: Integer;
      AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
    procedure sbSearchClick(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
    procedure Image1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmDatabaseInfo: TfrmDatabaseInfo;

procedure ShowDatabaseInfo;


implementation

{$R *.dfm}

uses
  X.MD5, X.Database, X.Utility, X.Global, X.Settings, X.Constants, X.Conversions,

  X.Dialogs.Dialog;


const
  CColumnDateTime  = 120;
  CColumnTableName = 350;
  CColumnPCName    = 99;


procedure ShowDatabaseInfo;
 begin
  with TfrmDatabaseInfo.Create(Application) do
    try
      ShowModal;
    finally
      free;
    end;
end;


procedure TfrmDatabaseInfo.FormCreate(Sender: TObject);
 var
  fd : TFormDetails;

 begin
  sgDatabase.Cells[0, 0] := XText[rsComputer];
  sgDatabase.Cells[1, 0] := XText[rsFolder];
  sgDatabase.Cells[2, 0] := XText[rsDateTime];
  sgDatabase.Cells[3, 0] := XText[rsTableName];

  sgDatabase.HideColumns(3, 5);

  bCancel.Caption := XText[rsCancel];
  bSave.Caption   := XText[rsSave];

  lSize.Caption   := XText[rsSize];
  lTables.Caption := XText[rsTables];

  // ===========================================================================

  fd := XSettings.LoadFormDetails(_FormInfoDatabase);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  // ===========================================================================

  sgDatabaseResize(Nil);  
end;


procedure TfrmDatabaseInfo.FormShow(Sender: TObject);
 var
  tsl : TStringList;
  t : integer;
  ttd, oldttd : TTableDetails;
  tf: file of Byte;
  lDBSize : int64;

 begin
  Caption               := XText[rsFileHistoryDBInfo];
  sbShowNames.Caption   := XText[rsShowNames];
  sbDeleteTable.Caption := XText[rsDelete];

  sgDatabase.ClearRows(1, sgDatabase.RowCount - 1);
  sgDatabase.RowCount   := 2;

  if XSettings.Database.UseODBC then begin
    lDatabaseSize.HTMLText[0] := '<i>' + XText[rsUnknown] + '</i>';
  end
  else begin
    lDBSize := 0;

    if FileExists(GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db') then begin
      AssignFile(tf, GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');
      {$I-}
      Reset(tf);

      if IOResult <> 0 then begin

      end
      else begin
        lDBSize := FileSize(tf);
        CloseFile(tf);
      end;
      {$I+}
    end;

    if lDBSize <> 0 then begin
      // ===========================================================================

      tsl := GetAllAvailableTables;
      tsl.Sort;

      lTableCount.HTMLText[0] := '<b>' + IntToStr(tsl.Count) + '</b>';

      for t := 0 to tsl.Count - 1 do begin
        ttd := TConvert.SplitTableName(tsl.Strings[t]);

        if (ttd.Date = oldttd.Date) and (ttd.Time = oldttd.Time) and (ttd.Computer = oldttd.Computer + 'F') then begin
          sgDatabase.Cells[5, t]     := '1.1';
          sgDatabase.Cells[5, t + 1] := '1.1';

          sgDatabase.Cells[0, t + 1] := oldttd.Computer;
        end
        else begin
          sgDatabase.Cells[5, t + 1] := '1.0';
          sgDatabase.Cells[0, t + 1] := ttd.Computer;
        end;

        sgDatabase.Cells[1, t + 1] := ttd.Path;
        sgDatabase.Cells[2, t + 1] := ttd.DateYYYYMMDD + '  ' + ttd.TimeHHMMSS;
        sgDatabase.Cells[3, t + 1] := tsl.Strings[t];

        sgDatabase.Cells[4, t + 1] := ttd.Date + ttd.Time;

        sgDatabase.RowCount := sgDatabase.RowCount + 1;

        oldttd := ttd;
      end;

      sgDatabase.RowCount := sgDatabase.RowCount - 1;
    end
    else begin
      sgDatabase.Cells[0, 1] := XText[rsDatabaseIsEmpty];

      sbShowNames.Enabled   := False;
      sbDeleteTable.Enabled := False;
      bSave.Enabled         := False;
      bExportCSV.Enabled    := False;
      bExportXML.Enabled    := False;
    end;

    lDatabaseSize.HTMLText[0] := '<b>' + TConvert.ConvertToUsefulUnit(lDBSize) + '</b> (<b>' + IntToStr(lDBSize) + '</b> ' + XText[rsBytes] + ')';
  end;
end;


procedure TfrmDatabaseInfo.Image1Click(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, '"' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\' + '"', '', '');
end;


procedure TfrmDatabaseInfo.FormClose(Sender: TObject; var Action: TCloseAction);
 var
  fd : TFormDetails;

 begin
  fd.formID := _FormInfoDatabase;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  Action := caFree;
end;


procedure TfrmDatabaseInfo.sbSearchClick(Sender: TObject);
begin
  THelp.OpenHelpPage('dbinfo.htm');
end;


procedure TfrmDatabaseInfo.sbShowNamesClick(Sender: TObject);
 begin
  if sgDatabase.IsHiddenColumn(3) then begin
    sgDatabase.UnHideColumn(3);

    sbShowNames.Caption := XText[rsHideNames];
  end
  else begin
    sgDatabase.HideColumn(3);

    sbShowNames.Caption := XText[rsShowNames];
  end;

  sgDatabaseResize(Nil);
end;


procedure TfrmDatabaseInfo.DeleteFromDatabaseXFH(const filename, date : string);
 var
  tf : textfile;
  bob : TStringList;
  t : integer;
  canwrite : boolean;

 begin
  if FileExists(filename) then begin
    bob := TStringList.Create;
    bob.LoadFromFile(filename);

    AssignFile(tf, filename);
    {$I-}
    Rewrite(tf);
    {$I+}

    if IOResult <> 0 then begin
      ShowXDialog('Error writing to database',
                  TLanguageHandler.FillParameter(rsCannotFindFileParam, filename),
                  XDialogTypeWarning);
    end
    else begin
      Writeln(tf, bob.strings[0]);

      canwrite := false;

      for t := 1 to bob.Count - 1 do begin
        if bob.strings[t] <> '' then begin
          if bob.strings[t][1] = '{' then begin
            if Copy(bob.strings[t + 2], 5, 14) = date then begin
              canwrite := False
            end
            else begin
              canwrite := True;

              Writeln(tf, '{');
            end;
          end
          else begin
            if canwrite then
              Writeln(tf, bob.strings[t]);
          end;
        end;
      end;

      CloseFile(tf);
    end;

    bob.Free;
  end
  else
    ShowXDialog('Error locating database',
                TLanguageHandler.FillParameter(rsCannotFindFileParam, filename),
                XDialogTypeWarning);
end;


procedure TfrmDatabaseInfo.sbDeleteTableClick(Sender: TObject);
 begin
  if sgDatabase.Selection.Top > 0 then begin
    if MessageDlg(XText[rsDeleteFHAreYouSure], mtWarning, [mbYes, mbNo], 0) = mrYes then begin
      bExportCSV.Enabled := False;
      bExportXML.Enabled := False;

      DeleteTable(sgDatabase.Cells[3, sgDatabase.Selection.Top]);
      DeleteFromDatabaseXFH(GSystemGlobal.AppDataPath + 'FolderHistory\' +
                            sgDatabase.Cells[0, sgDatabase.Selection.Top] + '\' +
                            TMD5.Generate(UpperCase(sgDatabase.Cells[1, sgDatabase.Selection.Top])) + '.xfh',
                            sgDatabase.Cells[4, sgDatabase.Selection.Top]);

      sgDatabase.RemoveRows(sgDatabase.Selection.Top, 1);
    end;
  end;
end;


procedure TfrmDatabaseInfo.bSaveClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsXFileList] + ' (*.txt)|*.txt',
                                    '.txt',
                                    TUtility.GetDefaultFileName('.txt', 'database_info'),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    TGridUtility.SaveGrid(sgDatabase, lFileName);
  end;
end;


procedure TfrmDatabaseInfo.bExportCSVClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsCSVFiles] + ' (*.csv)|*.csv',
                                    '.csv',
                                    TUtility.GetDefaultFileName('.csv', 'database_info'),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    if not(ExportTableToCSV(lFileName, sgDatabase.Cells[3, sgDatabase.Selection.Top])) then
      ShowXDialog(XText[rsErrorSavingReport] + ' (CSV)',
                  XText[rsErrorSaving] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
  end;
end;


procedure TfrmDatabaseInfo.bExportXMLClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsXMLFiles] + ' (*.xml)|*.xml',
                                    '.xml',
                                    TUtility.GetDefaultFileName('.xml', 'database_info'),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    if not(ExportTableToXML(lFileName, sgDatabase.Cells[3, sgDatabase.Selection.Top])) then
      ShowXDialog(XText[rsErrorSavingReport] + ' (XML)',
                  XText[rsErrorSaving] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
  end;
end;


procedure TfrmDatabaseInfo.BitBtn1Click(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, 'http://xinorbis.com/xdatabase/X.Database32.zip', '', '');
end;


procedure TfrmDatabaseInfo.sgDatabaseClick(Sender: TObject);
 begin
  bExportCSV.Enabled := True;
  bExportXML.Enabled := True;
end;


procedure TfrmDatabaseInfo.sgDatabaseGetCellColor(Sender: TObject; ARow,
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


procedure TfrmDatabaseInfo.sgDatabaseResize(Sender: TObject);
 begin
  sgDatabase.ColWidths[0] := CColumnPCName;

  if sgDatabase.IsHiddenColumn(3) then begin
    sgDatabase.ColWidths[1] := sgDatabase.Width - (CColumnPCName + CColumnDateTime + _WidthOfScrollbar);
    sgDatabase.ColWidths[2] := CColumnDateTime;
  end
  else begin
    sgDatabase.ColWidths[1] := sgDatabase.Width - (CColumnPCName + CColumnDateTime + CColumnTableName + _WidthOfScrollbar);
    sgDatabase.ColWidths[2] := CColumnDateTime;
    sgDatabase.ColWidths[3] := CColumnTableName;
  end;
end;


end.
