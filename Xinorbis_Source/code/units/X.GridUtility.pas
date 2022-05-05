{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.GridUtility;

interface

uses
  SysUtils, Vcl.Buttons, AdvGrid, Math, dialogs,

  TMSLogging,

  X.Dialogs.Save, X.Dialogs.Dialog,

  X.ReportUtility,

  X.Formatting, X.GlobalObjects, X.Constants, X.Global, X.Utility, X.LanguageHandler;


type
  TGridUtility = class
  public
    class procedure CopyGridToClipboard(StartCol : integer; Grid : TAdvStringGrid);

    class procedure ClearStringGird(sGrid : TAdvStringGrid; clearobjects : boolean);
    class procedure ConfigureInfoTable(grid : TAdvStringGrid);
    class procedure ConfigureInfoTypes(grid : TAdvStringGrid);
    class procedure ConfigureInfoFolders(grid : TAdvStringGrid);
    class procedure ConfigureInfoUsers(grid : TAdvStringGrid);
    class procedure ConfigureInfoMagnitude(grid : TAdvStringGrid);
    class procedure ConfigureInfoLength(grid : TAdvStringGrid);
    class procedure ConfigureInfoExtensions(grid : TAdvStringGrid);
    class procedure Configure101DateTable(grid : TAdvStringGrid; aFirstColumn : string);

    class procedure DoTableSort(MrGrid : TAdvStringGrid; DisplayColumn, SortingColumn : integer);
    class procedure SortTable(table : TAdvStringGrid; acol : integer);

    class procedure ToggleColumn(grid : TAdvStringGrid; buttonID : TSpeedButton; columnID, glyphID : integer);

    class procedure SaveFHStringGridData(grid : TAdvStringGrid; aSearchString : string; mode : integer);

    class function  SaveGrid(aGrid : TAdvStringGrid; const aFileName : string): boolean;
  end;


implementation


class procedure TGridUtility.CopyGridToClipboard(StartCol : integer; Grid : TAdvStringGrid);
 begin
  Assert(grid <> Nil, 'CopyGridToClipboard :: grid is nil');

  grid.CopyToClipBoard;
end;


class procedure TGridUtility.ClearStringGird(sGrid : TAdvStringGrid; clearobjects : boolean);
 var
  t : integer;

 begin
  Assert(sGrid <> Nil, 'ClearStringGird :: Grid is nil');

  if clearobjects then begin
    for t := 1 to sGrid.RowCount - 1 do begin
      sGrid.Objects[t, 0].Free;
    end;
  end;

  sGrid.ClearRows(1, sGrid.RowCount - 1);
  sGrid.RowCount := 2;
end;


class procedure TGridUtility.ConfigureInfoTable(grid : TAdvStringGrid);
var
  t : integer;

begin
  Assert(Grid <> Nil, 'ConfigureInfoTable :: Grid is nil');

  grid.BeginUpdate;

  grid.RowCount :=__FileCategoriesCount + 1;

  grid.Cells[1,0] := XText[rsCategory];
  grid.Cells[2,0] := XText[rsFiles];
  grid.Cells[3,0] := XText[rsAsPercent];
  grid.Cells[5,0] := XText[rsSize];
  grid.Cells[6,0] := XText[rsAsPercent];

  for t := 1 to __FileCategoriesCount do begin
    grid.Cells[1,t]  := TypeDescriptions[t];
    grid.Cells[2,t]  := '  -';
    grid.Cells[3,t]  := '  -';
    grid.Cells[5,t]  := '  -';
    grid.Cells[6,t]  := '  -';
    grid.Cells[7,t]  := IntToStr(t);
    grid.Cells[8,t]  := '  -';
    grid.Cells[9,t]  := '0';
    grid.Cells[10,t] := '0';
  end;

  grid.HideColumns(7, 10);

  grid.EndUpdate;
end;


class   procedure TGridUtility.ConfigureInfoTypes(grid : TAdvStringGrid);
var
  t : integer;

begin
  Assert(Grid <> Nil, 'ConfigureIntoTypes :: Grid is nil');
  grid.BeginUpdate;

  grid.RowCount := __AttributesToDisplayCount + 1;

  grid.Cells[0, 0] := XText[rsFileAttributes];
  grid.Cells[1, 0] := XText[rsFiles];
  grid.Cells[2, 0] := XText[rsAsPercent];
  grid.Cells[4, 0] := XText[rsSize];
  grid.Cells[5, 0] := XText[rsAsPercent];

  for t := 1 to __AttributesToDisplayCount do begin
    grid.Cells[0, t] := LanguageTypes[t];
    grid.Cells[1, t] := '  -';
    grid.Cells[2, t] := '  -';
    grid.Cells[4, t] := '  -';
    grid.Cells[5, t] := '  -';
    grid.Cells[6, t] := '0';
    grid.Cells[7, t] := '0';
  end;

  grid.HideColumns(6, 7);

  grid.EndUpdate;
end;


class   procedure TGridUtility.ConfigureInfoFolders(grid : TAdvStringGrid);
begin
  Assert(Grid <> Nil, 'ConfigureInfoFolders :: Grid is nil');

  grid.BeginUpdate;

  grid.RowCount := 2;

  grid.Cells[ 1, 0] := XText[rsFolder];
  grid.Cells[ 2, 0] := XText[rsHashFiles];
  grid.Cells[ 3, 0] := XText[rsAsPercent];
  grid.Cells[ 5, 0] := XText[rsSize];
  grid.Cells[ 6, 0] := XText[rsAsPercent];

  grid.Cells[ 1, 1] := '  -';
  grid.Cells[ 2, 1] := '  -';
  grid.Cells[ 3, 1] := '  -';
  grid.Cells[ 5, 1] := '  -';
  grid.Cells[ 6, 1] := '  -';
  grid.Cells[ 9, 1] := '0';
  grid.Cells[10, 1] := '0';

  grid.HideColumns(7, 10);

  grid.EndUpdate;
end;


class   procedure TGridUtility.ConfigureInfoUsers(grid : TAdvStringGrid);
begin
  Assert(Grid <> Nil, 'ConfigureInfoUsers :: Grid is nil');

  grid.BeginUpdate;

  grid.RowCount := 2;

  grid.Cells[1, 0] := XText[rsOwner];
  grid.Cells[2, 0] := XText[rsFiles];
  grid.Cells[3, 0] := XText[rsAsPercent];
  grid.Cells[5, 0] := XText[rsSize];
  grid.Cells[6, 0] := XText[rsAsPercent];

  grid.Cells[1, 1] := '  -';
  grid.Cells[8, 1] := '0';
  grid.Cells[9, 1] := '0';

  grid.HideColumns(7, 9);

  grid.EndUpdate;
end;


class procedure TGridUtility.ConfigureInfoMagnitude(grid : TAdvStringGrid);
var
  t : integer;

begin
  Assert(Grid <> Nil, 'ConfigureInfoMagnitude :: Grid is nil');

  grid.BeginUpdate;

  grid.RowCount := __MagnitudesCount + 1;

  grid.Cells[1, 0] := XText[rsFileSize];
  grid.Cells[2, 0] := XText[rsHashFiles];
  grid.Cells[3, 0] := XText[rsAsPercent];
  grid.Cells[5, 0] := XText[rsSize];
  grid.Cells[6, 0] := XText[rsAsPercent];

  for t := 0 to __MagnitudesCount - 1 do begin
    grid.Cells[ 1, t + 1] := magnilabels[t];
    grid.Cells[ 2, t + 1] := '  -';
    grid.Cells[ 3, t + 1] := '  -';
    grid.Cells[ 5, t + 1] := '  -';
    grid.Cells[ 6, t + 1] := '  -';

    grid.Cells[ 7, t + 1] := IntToStr(t);
    grid.Cells[ 8, t + 1] := '0';
    grid.Cells[ 9, t + 1] := '0';
    grid.Cells[10, t + 1] := '0';
  end;

  grid.HideColumns(7, 10);

  grid.EndUpdate;
end;


class procedure TGridUtility.ConfigureInfoLength(grid : TAdvStringGrid);
var
  t : integer;

begin
  Assert(Grid <> Nil, 'ConfigureInfoTable :: Grid is nil');

  grid.BeginUpdate;

  grid.RowCount :=__FileCategoriesCount + 1;

  grid.Cells[1,0] := XText[rsFileNameLength];
  grid.Cells[2,0] := XText[rsFiles];
  grid.Cells[3,0] := XText[rsAsPercent];
  grid.Cells[5,0] := XText[rsSize];
  grid.Cells[6,0] := XText[rsAsPercent];

  for t := 1 to __FileCategoriesCount do begin
    grid.Cells[1,t]  := TypeDescriptions[t];
    grid.Cells[2,t]  := '  -';
    grid.Cells[3,t]  := '  -';
    grid.Cells[5,t]  := '  -';
    grid.Cells[6,t]  := '  -';
    grid.Cells[7,t]  := IntToStr(t);
    grid.Cells[8,t]  := '  -';
    grid.Cells[9,t]  := '0';
    grid.Cells[10,t] := '0';
  end;

  grid.HideColumns(7, 10);

  grid.EndUpdate;
end;


class procedure TGridUtility.ConfigureInfoExtensions(grid : TAdvStringGrid);
begin
  Assert(Grid <> Nil, 'ConfigureInfoExtensions :: Grid is nil');

  grid.BeginUpdate;

  grid.RowCount := 2;

  grid.Cells[0,0] := XText[rsExtension];
  grid.Cells[1,0] := XText[rsFiles];
  grid.Cells[2,0] := XText[rsAsPercent];
  grid.Cells[4,0] := XText[rsSize];
  grid.Cells[5,0] := XText[rsAsPercent];
  grid.Cells[7,0] := XText[rsSuggestedFileType];

  grid.HideColumns(8, 12);

  grid.EndUpdate;
end;


class procedure TGridUtility.Configure101DateTable(grid : TAdvStringGrid; aFirstColumn : string);
begin
  grid.BeginUpdate;

  grid.Cells[0, 0]   := aFirstColumn;
  grid.Cells[1, 0]   := XText[rsDate];
  grid.Cells[2, 0]   := XText[rsSize];
  grid.Cells[3, 0]   := XText[rsFileOwner];
  grid.HideColumns(4, 5);

  grid.EndUpdate;
end;


class procedure TGridUtility.DoTableSort(MrGrid : TAdvStringGrid; DisplayColumn, SortingColumn : integer);
 begin
  MrGrid.SortSettings.Column := SortingColumn;

  MrGrid.QSort;

  MrGrid.SortSettings.Column := DisplayColumn;
end;


class procedure TGridUtility.SortTable(table : TAdvStringGrid; acol : integer);
 begin
  if (Acol >= 1) and (Acol <= 5) then begin
    with TAdvStringGrid(table) do begin
      Sortsettings.Column := Acol + 8;

      table.QSort;

      SortSettings.Column := Acol;
    end;
  end
  else
    table.QSort;
end;


class procedure TGridUtility.SaveFHStringGridData(grid : TAdvStringGrid; aSearchString : string; mode : integer);
var
  tf : TextFile;
  t, a, b, c, w : integer;
  dooutput : boolean;
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsCSVFiles] + ' (*.csv)|*.csv|' + XText[rsXFileList] + ' (*.txt)|*.txt',
                                    '.txt',
                                    TUtility.GetDefaultFileName('.txt', XText[rsTable] + '_' + XText[rsExport]));

  if lFileName <> '' then begin
    case GReportUtility.GetReportType(lFileName) of
      CReportTypeCSV      : begin
                              AssignFile(tf, lFileName);

                              {$I-}
                              Rewrite(tf);

                              if IOResult <> 0 then begin
                                ShowXDialog(XText[rsErrorSaving] + ': ' + XText[rsTable],
                                            XText[rsErrorSaving] + ' "' + lFileName + '".',
                                            XDialogTypeWarning);
                              end
                              else begin
                                Writeln(tf, '"' + XText[rsFileName]         + '","' +
                                            '"' + XText[rsSize]             + '","' +
                                            '"' + XText[rsSizeOfFilesBytes] + '","' +
                                            '"' + XText[rsSizeOnDisk]       + '","' +
                                            '"' + XText[rsSizeOnDisk]       + '","' +
                                            '"' + XText[rsCreatedDate]      + '","' +
                                            '"' + XText[rsAccessedDate]     + '","' +
                                            '"' + XText[rsModifiedDate]     + '","' +
                                            '"' + XText[rsOwner]            + '","' +
                                            '"' + XText[rsFileAttributes]   + '","');

                                for t := 1 to grid.RowCount - 1 do begin
                                  dooutput := True;

                                  if mode <> fhscModeSaveAll then begin
                                    case mode of
                                      fhscModeSaveDo   : if grid.Cells[FHschCategory, t] <> '1' then dooutput := False;
                                      fhscModeSaveDont : if grid.Cells[FHschCategory, t] <> '2' then dooutput := False;
                                    end;
                                  end;

                                  if dooutput then
                                    Writeln(tf, '"' + grid.Cells[FHschFileName, t]       + '","' +
                                                '"' + grid.Cells[FHschSize, t]           + '","' +
                                                '"' + grid.Cells[FHschSortSize, t]       + '","' +
                                                '"' + grid.Cells[FHschSizeOnDisk, t]     + '","' +
                                                '"' + grid.Cells[FHschSortSizeOnDisk, t] + '","' +
                                                '"' + grid.Cells[FHschCreated, t]        + '","' +
                                                '"' + grid.Cells[FHschAccessed, t]       + '","' +
                                                '"' + grid.Cells[FHschModified, t]       + '","' +
                                                '"' + grid.Cells[FHschOwner, t]          + '","' +
                                                '"' + grid.Cells[FHschStatus, t]         + '"');
                                end;

                                CloseFile(tf);
                              end;
                              {$I+}
                            end;
      CReportTypeText     : begin
                              AssignFile(tf, lFileName);

                              {$I-}
                              Rewrite(tf);

                              if IOResult <> 0 then begin
                                ShowXDialog(XText[rsErrorSaving] + ': ' + XText[rsTable],
                                            XText[rsErrorSaving] + ' "' + lFileName + '".',
                                            XDialogTypeWarning);
                              end
                              else begin
                                a := Length(XText[rsPath]);
                                b := Length(XText[rsSearch]);
                                c := Length(XText[rsFound]);

                                w := Max(Max(a, b), c);   // find the largest of the three texts

                                Writeln(tf, '// Xinorbis 8 - ' + XText[rsSearchResults]);
                                Writeln(tf, '//');
                                Writeln(tf, '// ' + XText[rsPath]   + TXFormatting.StringOfChars(w - a, ' ') + ' : ' + XText[rsFolderHistory]);
                                Writeln(tf, '// ' + XText[rsSearch] + TXFormatting.StringOfChars(w - b, ' ') + ' : ' + aSearchString);
                                Writeln(tf, '// ' + XText[rsFound]  + TXFormatting.StringOfChars(w - c, ' ') + ' : ' + IntToStr(grid.RowCount - 1) + ' matches found.');
                                Writeln(tf, '');

                                for t := 1 to grid.RowCount - 1 do begin
                                  dooutput := True;

                                  if mode <> fhscModeSaveAll then begin
                                    case mode of
                                      fhscModeSaveDo   : if grid.Cells[FHschCategory, t] <> '1' then dooutput := False;
                                      fhscModeSaveDont : if grid.Cells[FHschCategory, t] <> '2' then dooutput := False;
                                    end;
                                  end;

                                  if dooutput then
                                    Writeln(tf, grid.Cells[FHschFileName, t] + '  [' + grid.Cells[FHschSize, t] + ']');
                                end;

                                CloseFile(tf);
                              end;
                              {$I+}
                            end;
    end;
  end;
end;


class procedure TGridUtility.ToggleColumn(grid : TAdvStringGrid; buttonID : TSpeedButton; columnID, glyphID : integer);
 begin
  if grid.IsHiddenColumn(columnID) then begin
    grid.UnHideColumn(columnID);

    GXGuiUtil.SetButtonOnImage(buttonID, glyphID);
  end
  else begin
    grid.HideColumn(columnID);

    GXGuiUtil.SetButtonOffImage(buttonID, glyphID);
  end;
end;


class function TGridUtility.SaveGrid(aGrid : TAdvStringGrid; const aFileName : string): boolean;
begin
  Result := True;

  try
    case GReportUtility.GetReportType(aFileName) of
      CReportTypeCSV  : aGrid.SaveToCSV(aFileName);
      CReportTypeHTML : aGrid.SaveToHTML(aFileName, False, false);
      CReportTypeText : aGrid.SaveToASCII(aFileName);
    end;
  except
    on e : exception do begin
      Result := False;

      TMSLogger.Error('Error saving grid "' + aFileName + '".');
    end;
  end;
end;


end.
