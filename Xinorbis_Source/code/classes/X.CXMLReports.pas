{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CXMLReports;

interface


uses
  SysUtils, System.Classes, Vcl.StdCtrls, Windows,

  TMSLogging,

  AdvGrid, htmltv,

  X.CReportOptions, X.ReportUtility,

  X.Dialogs.Dialog,

  X.Constants, X.Conversions, X.FileExtension, X.FileExtensionsObject, X.Formatting, X.Global, X.GlobalObjects,
  X.LanguageHandler, X.GuiLogic, X.CSizeOfFolder, X.CFileObject,
  X.Settings, X.SystemGlobal, X.Utility, X.Windows;


type
  TXMLReport = class
  private
    FJustInTime         : TJustInTime;
    FSetStatusBarText   : TSetStatusBarText;

    FHTMLTreeViews      : array[0..2] of THTMLTreeView;
    FAdvStringGrids     : array[0..2, 1..6] of TAdvStringGrid;
    FComboBoxes         : array[0..2, 1..3] of TComboBox;

    procedure XMLReportSummary(aDATAINDEX : integer; var aXMLOutput : TStringList; Options  : TXMLReportOptions);
    procedure XMLReportFileAttributes(aDATAINDEX : integer; var aXMLOutput : TStringList);
    procedure XMLReportFileCategory(aDATAINDEX : integer; var aXMLOutput : TStringList);
    procedure XMLReportFolderList(aDATAINDEX : integer; var aXMLOutput : TStringList);
    procedure XMLReportMagnitude(aDATAINDEX : integer; var aXMLOutput : TStringList);
    procedure XMLReportExtensionLists(aDATAINDEX : integer; var aXMLOutput : TStringList);
    procedure XMLReportNullFiles(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGNullFiles, aSGNullFolders : TAdvStringGrid);
    procedure XMLReportFileDates(aDATAINDEX : integer; var aXMLOutput : TStringList; aCBFileDates : TComboBox; aTVFileDates : THTMLTreeview);
    procedure XMLReportUsers(aDATAINDEX : integer; var aXMLOutput : TStringList);
    procedure XMLReportTopLarge(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGTop50Big : TAdvStringGrid);
    procedure XMLReportTopSmallest(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGTop50Small : TAdvStringGrid);
    procedure XMLReportTopNewest(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGTop101BigDate : TAdvStringGrid);
    procedure XMLReportTopOldest(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGTop101SmallDate : TAdvStringGrid);
    procedure XMLReportNameLength(aDATAINDEX : integer; var aXMLOutput : TStringList);
  public
    procedure GenerateXMLOutput(aDataIndex : integer; Options  : TXMLReportOptions; var lXMLOutput : TStringList);
    procedure GenerateXMLOutputFileList(const aFileName : string; var aXMLOutput : TStringList; aDataIndex, aReportLayout : integer);

    procedure GenerateXMLCompareOutput(const filename, aPath, aLeftCaption, aRightCaption : string;
                                                    asgFHCompareLeft, asgFHCompareRight : TAdvStringGrid);

    procedure SetGrids(aDataIndex : integer; var atvFileDates : THTMLTreeView;
      var asgNullFiles, asgNullFolders, asgTop50Big, asgTop50Small, asgTop101BigDate, asgTop101SmallDate : TAdvStringGrid;
      var acbFileDates, acbFileDatesUsers, acbTop101Dates : TComboBox);

    property  OnJustInTime       : TJustInTime       read FJustInTime         write FJustInTime;
    property  OnSetStatusBarText : TSetStatusBarText read FSetStatusBarText   write FSetStatusBarText;
  end;


var
  GReportXML : TXMLReport;


implementation


const
  CNullFiles       = 1;
  CNullFolders     = 2;
  CTop50Big        = 3;
  CTop50Small      = 4;
  CTop101BigDate   = 5;
  CTop101SmallDate = 6;

  CFileDates       = 1;
  CFileDatesUsers  = 2;
  CTop101Dates     = 3;


procedure TXMLReport.GenerateXMLOutput(aDataIndex : integer; Options : TXMLReportOptions; var lXMLOutput : TStringList);
 var
  t : integer;
  s : string;

  procedure AddXMLReportItem(sidx : integer);
   begin
    case sidx of
       1              : begin
                        end;
       CXMLSummary    : XMLReportSummary(aDataIndex, lXMLOutput, Options);
       CXMLAttributes : XMLReportFileAttributes(aDataIndex, lXMLOutput);
       CXMLCategory   : XMLReportFileCategory(aDataIndex, lXMLOutput);
       CXMLFolders    : XMLReportFolderList(aDataIndex, lXMLOutput);
       CXMLMagnitude  : XMLReportMagnitude(aDataIndex, lXMLOutput);
       CXMLExtensions : XMLReportExtensionLists(aDataIndex, lXMLOutput);
       CXMLNullFiles  : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexNull);

                          XMLReportNullFiles(aDataIndex, lXMLOutput, FAdvStringGrids[aDataIndex, CNullFiles], FAdvStringGrids[aDataIndex, CNullFolders]);
                        end;
       CXMLDatesC,
       CXMLDatesA,
       CXMLDatesM     : begin
                          case sidx of
                            CXMLDatesC : if Assigned(FJustInTime) then
                                           FJustInTime(TabIndexDatesCreated);
                            CXMLDatesA : if Assigned(FJustInTime) then
                                           FJustInTime(TabIndexDatesAccessed);
                            CXMLDatesM : if Assigned(FJustInTime) then
                                           FJustInTime(TabIndexDatesModified);
                          end;

                          XMLReportFileDates(aDataIndex, lXMLOutput, FComboBoxes[aDataIndex, CFileDates], FHTMLTreeViews[CFileDates]);
                        end;
      CXMLUsers       : XMLReportUsers(aDataIndex, lXMLOutput);
      CXMLLargest     : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexTop50);

                          XMLReportTopLarge(aDataIndex, lXMLOutput, FAdvStringGrids[aDataIndex, CTop50Big]);
                        end;
      CXMLSmallest    : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexTop50);

                          XMLReportTopSmallest(aDataIndex, lXMLOutput, FAdvStringGrids[aDataIndex, CTop50Small]);
                        end;
      CXMLNewest      : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexTop50);

                          XMLReportTopNewest(aDataIndex, lXMLOutput, FAdvStringGrids[aDataIndex, CTop101BigDate]);
                        end;
      CXMLOldest      : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexTop50);

                          XMLReportTopOldest(aDataIndex, lXMLOutput, FAdvStringGrids[aDataIndex, CTop101SmallDate]);
                        end;
      CXMLNameLength  : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexNameLength);

                          XMLReportNameLength(aDataIndex, lXMLOutput);
                        end;
    end;
  end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'GenerateXMLOutput :: invalid dataindex :: ' +inttostr(aDataIndex));

  //----------------------------------------------------------------------------
  //--Lets write the file-------------------------------------------------------
  //----------------------------------------------------------------------------

  lXMLOutput := TStringList.Create;

  lXMLOutput.Add('<?xml version="1.0"?>');
  lXMLOutput.Add('<!-- generated with Xinorbis ' + x8Title + ' - ' + x8Date + ' -->');
  lXMLOutput.Add('<!-- generated at ' + TUtility.GetDate(GETTIMEFORMAT_FILE) + ' ' + TUtility.GetTime(GETTIMEFORMAT_FILE) + ' -->');
  lXMLOutput.Add('<!-- http://www.xinorbis.com - Paul A Freshney -->');
  lXMLOutput.Add('<xinorbisreport>');

  // ===========================================================================

  s := '';

  for t := 1 to length(Options.Layout) do begin
    if Options.Layout[t] = ':' then begin
      AddXMLReportItem(StrToIntDef(s, 1));

      s := '';
    end
    else
      s := s + Options.Layout[t];
  end;

  // ===========================================================================

  lXMLOutput.Add('</xinorbisreport>');

  if Options.Filename <> '' then begin
    try
      lXMLOutput.SaveToFile(Options.Filename);

      GReportUtility.SetLastReport(aDataIndex, Options.Filename, GScanDetails[aDataIndex].ScanPath, ReportXML, LayoutUnknown);

      if Assigned(FSetStatusBarText) then
        FSetStatusBarText(XText[rsXMLReportSavedAs] + ': '  + Options.FileName);
    except
      ShowXDialog(XText[rsErrorSaving] + ': XML ' + XText[rsReport],
                  XText[rsErrorSaving] + ' "' + Options.FileName + '".',
                  XDialogTypeWarning);
    end;
  end;
end;               //                  FrameFolderHistory.SelectedPath, eFHCompareSearch.Text, bFHCompareLeft.Caption, bFHCompareRight.Caption


procedure TXMLReport.SetGrids(aDataIndex : integer; var atvFileDates : THTMLTreeView;
                   var asgNullFiles, asgNullFolders, asgTop50Big, asgTop50Small, asgTop101BigDate, asgTop101SmallDate : TAdvStringGrid;
                   var acbFileDates, acbFileDatesUsers, acbTop101Dates : TComboBox);
begin
  FHTMLTreeViews[aDataIndex]                    := atvFileDates;

  FAdvStringGrids[aDataIndex, CNullFiles]       := asgNullFiles;
  FAdvStringGrids[aDataIndex, CNullFolders]     := asgNullFolders;
  FAdvStringGrids[aDataIndex, CTop50Big]        := asgTop50Big;
  FAdvStringGrids[aDataIndex, CTop50Small]      := asgTop50Small;
  FAdvStringGrids[aDataIndex, CTop101BigDate]   := asgTop101BigDate;
  FAdvStringGrids[aDataIndex, CTop101SmallDate] := asgTop101SmallDate;

  FComboBoxes[aDataIndex, CFileDates]           := acbFileDates;
  FComboBoxes[aDataIndex, CFileDatesUsers]      := acbFileDatesUsers;
  FComboBoxes[aDataIndex, CTop101Dates]         := acbTop101Dates;
end;


procedure TXMLReport.GenerateXMLCompareOutput(const filename, aPath, aLeftCaption, aRightCaption : string;
                                                    asgFHCompareLeft, asgFHCompareRight : TAdvStringGrid);
var
  wp : TextFile;
  t : integer;
begin
  AssignFile(wp, filename);

  {$I-}
  Rewrite(wp);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsErrorSaving] + ': XML Comparison report',
                XText[rsErrorSaving] + ' "' + FileName + '".',
                XDialogTypeWarning);
  end
  else begin
    Writeln(wp, '<?xml version="1.0"?>');
    Writeln(wp, '<!-- generated with Xinorbis ' + x8Title + ' - ' + x8Date + ' -->');
    Writeln(wp, '<!-- http://www.xinorbis.com - (c) Paul A Freshney ' + TUtility.GetCurrentYear + ' -->');
    Writeln(wp, '<xinorbiscomparisonreport>');

    // ===========================================================================

    Writeln(wp, '<information>');
    Writeln(wp, TXFormatting.InsertElement('folder', TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(aPath)), 1));
    Writeln(wp, TXFormatting.InsertElement('date', TUtility.GetDate(GETTIMEFORMAT_DISPLAY), 1));
    Writeln(wp, TXFormatting.InsertElement('time', TUtility.GetTime(GETTIMEFORMAT_DISPLAY), 1));
    Writeln(wp, TXFormatting.InsertElement('scanleftdate', aLeftCaption, 1));
    Writeln(wp, TXFormatting.InsertElement('scanrightdate', aRightCaption, 1));
    Writeln(wp, TXFormatting.InsertElement('leftfilecount', IntToStr(CompareData[XLeftSide].Data[XFileCount]), 1));
    Writeln(wp, TXFormatting.InsertElement('rightfilecount', IntToStr(CompareData[XRightSide].Data[XFileCount]), 1));
    Writeln(wp, TXFormatting.InsertElement('leftfilesize', IntToStr(CompareData[XLeftSide].Data[XFileSize]), 1));
    Writeln(wp, TXFormatting.InsertElement('rightfilesize', IntToStr(CompareData[XRightSide].Data[XFileSize]), 1));
    Writeln(wp, TXFormatting.InsertElement('leftfoldercount', IntToStr(CompareData[XLeftSide].Data[XFolderCount]), 1));
    Writeln(wp, TXFormatting.InsertElement('rightfoldercount', IntToStr(CompareData[XRightSide].Data[XFolderCount]), 1));
    Writeln(wp, '</information>');

    Writeln(wp, '<data>');
    Writeln(wp, '  <filedata date="' + aLeftCaption + '">');
    for t := 1 to asgFHCompareLeft.RowCount - 1 do begin
      Writeln(wp, '    <file>');
      Writeln(wp, TXFormatting.InsertElement('filenamestr',         TXFormatting.Privacy(asgFHCompareLeft.Cells[FHschFilename, t]), 3));
      Writeln(wp, TXFormatting.InsertElement('filesizestr',         asgFHCompareLeft.Cells[FHschSize, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filesizeondiskstr',   asgFHCompareLeft.Cells[FHschSizeOnDisk, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filesizeint',         asgFHCompareLeft.Cells[FHschSortSize, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filesizeondiskint',   asgFHCompareLeft.Cells[FHschSortSizeOnDisk, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedatecreatedstr',  asgFHCompareLeft.Cells[FHschCreated, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedateaccessedstr', asgFHCompareLeft.Cells[FHschAccessed, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedatemodifiedstr', asgFHCompareLeft.Cells[FHschModified, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedatecreatedint',  asgFHCompareLeft.Cells[FHschSortCreated, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedateaccessedint', asgFHCompareLeft.Cells[FHschSortAccessed, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedatemodifiedint', asgFHCompareLeft.Cells[FHschSortModified, t], 3));
      Writeln(wp, TXFormatting.InsertElement('fileowner',           TXFormatting.Privacy(asgFHCompareLeft.Cells[FHschOwner, t]), 3));
      Writeln(wp, TXFormatting.InsertElement('fileattributes',      asgFHCompareLeft.Cells[FHschStatus, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filecategory',        asgFHCompareLeft.Cells[FHschCategory, t], 3));
      Writeln(wp, '    </file>');
    end;
    Writeln(wp, '  </filedata>');
    Writeln(wp, '  <filedata date="' + aRightCaption + '">');
    for t := 1 to asgFHCompareRight.RowCount - 1 do begin
      Writeln(wp, '    <file>');
      Writeln(wp, TXFormatting.InsertElement('filenamestr',         TXFormatting.Privacy(asgFHCompareRight.Cells[FHschFilename, t]), 3));
      Writeln(wp, TXFormatting.InsertElement('filesizestr',         asgFHCompareRight.Cells[FHschSize, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filesizeondiskstr',   asgFHCompareRight.Cells[FHschSizeOnDisk, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filesizeint',         asgFHCompareRight.Cells[FHschSortSize, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filesizeondiskint',   asgFHCompareRight.Cells[FHschSortSizeOnDisk, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedatecreatedstr',  asgFHCompareRight.Cells[FHschCreated, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedateaccessedstr', asgFHCompareRight.Cells[FHschAccessed, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedatemodifiedstr', asgFHCompareRight.Cells[FHschModified, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedatecreatedint',  asgFHCompareRight.Cells[FHschSortCreated, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedateaccessedint', asgFHCompareRight.Cells[FHschSortAccessed, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filedatemodifiedint', asgFHCompareRight.Cells[FHschSortModified, t], 3));
      Writeln(wp, TXFormatting.InsertElement('fileowner',           TXFormatting.Privacy(asgFHCompareRight.Cells[FHschOwner, t]), 3));
      Writeln(wp, TXFormatting.InsertElement('fileattributes',      asgFHCompareRight.Cells[FHschStatus, t], 3));
      Writeln(wp, TXFormatting.InsertElement('filecategory',        asgFHCompareRight.Cells[FHschCategory, t], 3));
      Writeln(wp, '    </file>');
    end;
    Writeln(wp, '  </filedata>');
    Writeln(wp, '</data>');

    // ===========================================================================

    Writeln(wp, '</xinorbiscomparisonreport>');

    CloseFile(wp);

    GReportUtility.SetLastReport(dataFolderHistory, Filename, GScanDetails[dataFolderHistory].ScanPath, ReportXML, LayoutUnknown);

    if Assigned(FSetStatusBarText) then
      FSetStatusBarText(XText[rsXMLReportSavedAs] + ': '  + FileName);
  end;
  {$I+}
end;


procedure TXMLReport.GenerateXMLOutputFileList(const aFileName : string; var aXMLOutput : TStringList; aDataIndex, aReportLayout : integer);
var
  t : integer;
  tfo : TFileObject;

  function BoolToString(fish : boolean): String;
   begin
    if fish then
      Result := '1'
    else
      Result := '0';
  end;


 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'GenerateXMLOutputFileList :: invalid dataindex :: ' + inttostr(aDataIndex));

  aXMLOutput.Add('<?xml version="1.0"?>');
  aXMLOutput.Add('<!--  -->');
  aXMLOutput.Add('<!-- generated with Xinorbis ' + x8Title + ' - ' + x8Date + ' -->');
  aXMLOutput.Add('<!-- http://xinorbis.com - Paul A Freshney -->');
  aXMLOutput.Add('<!--  -->');
  aXMLOutput.Add('<xinorbisfilelist>');

  for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
    tfo := GScanDetails[aDataIndex].Files.Items[t];

    aXMLOutput.Add('<item>');
    aXMLOutput.Add(TXFormatting.InsertElement('name', TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(tfo.FileName)), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('path', TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(GScanDetails[aDataIndex].Folders[tfo.FilePathIndex])), 2));

    if (faDirectory and tfo.Attributes) = faDirectory then begin
      aXMLOutput.Add(TXFormatting.InsertElement('sizewords', '-1', 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizebytes', '-1', 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizeondiskwords', '-1', 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizeondiskbytes', '-1', 2));
    end
    else begin
      aXMLOutput.Add(TXFormatting.InsertElement('sizewords', TConvert.ConvertToUsefulUnit(tfo.FileSize), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizebytes', IntToStr(tfo.FileSize), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizeondiskwords', TConvert.ConvertToUsefulUnit(tfo.FileSizeOnDisk), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizeondiskbytes', IntToStr(tfo.FileSizeOnDisk), 2));
    end;

    aXMLOutput.Add(TXFormatting.InsertElement('owner',                TXFormatting.Privacy(GScanDetails[aDataIndex].Users[tfo.Owner].Name), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('timecreated',          IntToStr(tfo.FileTimeC), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('timemodified',         IntToStr(tfo.FileTimeM), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('timeaccessed',         IntToStr(tfo.FileTimeA), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('datecreated',          TConvert.IntDateToString(tfo.FileDateC), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('datemodified',         TConvert.IntDateToString(tfo.FileDateM), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('dateaccessed',         TConvert.IntDateToString(tfo.FileDateA), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('datecreatedyyyymmdd',  IntToStr(tfo.FileDateC), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('datemodifiedyyyymmdd', IntToStr(tfo.FileDateM), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('dateaccessedyyyymmdd', IntToStr(tfo.FileDateA), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('category',             IntToStr(tfo.FileCategory), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('folder',               TConvert.AttributeToIntAsString(tfo.Attributes, faDirectory), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('readonly',             TConvert.AttributeToIntAsString(tfo.Attributes, faReadOnly), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('hidden',               TConvert.AttributeToIntAsString(tfo.Attributes, faHidden), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('system',               TConvert.AttributeToIntAsString(tfo.Attributes, faSysFile), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('archive',              TConvert.AttributeToIntAsString(tfo.Attributes, faArchive), 2));
    aXMLOutput.Add(TXFormatting.InsertElement('temp',                 BoolToString(tfo.Temp), 2));
    aXMLOutput.Add('</item>');
  end;

  aXMLOutput.Add('</xinorbisfilelist>');

  if aFileName <> '' then begin
    try
      aXMLOutput.SaveToFile(aFileName);

      GReportUtility.SetLastReport(aDataIndex, aFilename, GScanDetails[aDataIndex].ScanPath, ReportXML, aReportLayout);

      if (GReportUtility.ReportSubType = LayoutQuick) and (XSettings.Report.XMLOptions[LayoutQuick].XMLAutoOpen) then begin
        if XSettings.Report.XMLOutput <> '' then
          TXWindows.ExecuteFile(0, '"' + XSettings.Report.XMLOutput + '"', '"' + XSettings.Report.XMLOptions[LayoutQuick].FileName + '"', '')
        else
          TXWindows.ExecuteFile(0, 'notepad.exe', '"' + XSettings.Report.XMLOptions[LayoutQuick].FileName + '"', '');
      end;

      if Assigned(FSetStatusBarText) then
        FSetStatusBarText('Finished saving XML report.');
    except
      on e : exception do begin
        TMSLogger.Error('Error saving XML file list "' + aFileName + '". ' + e.ClassName + ' / ' + e.Message);
      end;
    end;
  end;
end;


procedure TXMLReport.XMLReportSummary(aDATAINDEX : integer; var aXMLOutput : TStringList; Options : TXMLReportOptions);
var
  lDriveDetails : TXDriveDetails;

begin
  if GScanDetails[aDATAINDEX].ScanPath <> '' then
    lDriveDetails := TXWindows.GetDriveDetails(GScanDetails[aDATAINDEX].ScanPath[1]);

  aXMLOutput.Add('<information>');
  aXMLOutput.Add(TXFormatting.InsertElement('folder',            TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(GScanDetails[aDATAINDEX].ScanPath)), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('date',              TUtility.GetDate(GETTIMEFORMAT_DISPLAY), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('dateYYYYMMDD',      TConvert.DateToYYYYMMDD(Now), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('time',              TUtility.GetTime(GETTIMEFORMAT_DISPLAY), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('timeHHMM',          TConvert.TimeToString(Now, False), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('numberfiles',       IntToStr(GScanDetails[aDATAINDEX].FileCount), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('numberfolders',     IntToStr(GScanDetails[aDataIndex].FolderCount), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('sizeoffiles',       TConvert.ConvertToUsefulUnit(GScanDetails[aDATAINDEX].TotalSize), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('drivetype',         TXWindows.GetDiskTypeString(GScanDetails[aDATAINDEX].ScanPath + ':'), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('sectorspercluster', IntToStr(lDriveDetails.SectorsPerCluster), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('bytespersector',    IntToStr(lDriveDetails.BytesPerSector), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('freeclusters',      IntToStr(lDriveDetails.FreeClusters), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('totalclusters',     IntToStr(lDriveDetails.Clusters), 1));
  aXMLOutput.Add(TXFormatting.InsertElement('volumename',        lDriveDetails.VolumeName, 1));
  aXMLOutput.Add(TXFormatting.InsertElement('serialnumber',      lDriveDetails.SerialNumberHex, 1));
  aXMLOutput.Add(TXFormatting.InsertElement('filesystem',        lDriveDetails.FileSystem, 1));

  if (GSystemGlobal.drivespacefree >= 0) and (GSystemGlobal.drivespacemax > 0) then begin
    aXMLOutput.Add(TXFormatting.InsertElement('diskspacefree',     TConvert.ConvertToUsefulUnit(GSystemGlobal.drivespacefree), 1));
    aXMLOutput.Add(TXFormatting.InsertElement('diskspacemax',      TConvert.ConvertToUsefulUnit(GSystemGlobal.drivespacemax), 1));
  end
  else begin
    aXMLOutput.Add(TXFormatting.InsertElement('diskspacefree',     'n/a', 1));
    aXMLOutput.Add(TXFormatting.InsertElement('diskspacemax',      'n/a', 1));
  end;

  if (GScanDetails[aDataIndex].ScanSource = ScanSourceFolderHistory) then begin
    aXMLOutput.Add(TXFormatting.InsertElement('folderhistorydate', GScanDetails[aDataIndex].ScanDateFHStr, 1));
  end;

  if (aDataIndex = dataSearch) then begin
    aXMLOutput.Add(TXFormatting.InsertElement('searchquery', Options.Special, 1));
  end;

  aXMLOutput.Add('</information>');
end;


procedure TXMLReport.XMLReportFileAttributes(aDATAINDEX : integer; var aXMLOutput : TStringList);
 var
  t : integer;

 begin
  //-----------------------------------------------------------------
   //file attributes -------------------------------------------------
  //-----------------------------------------------------------------
  aXMLOutput.Add('<categorylist>');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    for t := 1 to __AttributesToDisplayCount do begin
      aXMLOutput.Add('  <attribute name="' + LanguageTypes[t] + '">');
      aXMLOutput.Add(TXFormatting.InsertElement('numberfiles',          IntToStr(GScanDetails[aDataIndex].FileAttributes[t, 0]), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('numberfilesaspercent', TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 0] / GScanDetails[aDATAINDEX].FileCount), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizeoffiles',          TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].FileAttributes[t, 1]), 2));
      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 1] / GScanDetails[aDATAINDEX].TotalSize), 2))
      else
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', '100%', 2));

      aXMLOutput.Add('  </attribute>');
    end;
  end;

  aXMLOutput.Add('</categorylist>');
end;


procedure TXMLReport.XMLReportFileCategory(aDATAINDEX : integer; var aXMLOutput : TStringList);
 var
  t : integer;

 begin
  //-----------------------------------------------------------------
  //file category table----------------------------------------------
  //-----------------------------------------------------------------
  aXMLOutput.Add('<categorylist>');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    for t := 0 to __FileCategoriesCount do begin
      aXMLOutput.Add('  <category name="' + TypeDescriptions[t] + '">');
      aXMLOutput.Add(TXFormatting.InsertElement('numberfiles',          IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('numberfilesaspercent', IntToStr(Round((GScanDetails[aDataIndex].ExtensionSpread[t, 1] / GScanDetails[aDATAINDEX].FileCount) * 100)), 2));

      aXMLOutput.Add(TXFormatting.InsertElement('sizeoffiles', TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, 2]), 2));
      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', IntToStr(Round((GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDATAINDEX].TotalSize) * 100)), 2))
      else
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', '100', 2));

      aXMLOutput.Add('  </category>');
    end;
  end;

  aXMLOutput.Add('</categorylist>');
end;


procedure TXMLReport.XMLReportFolderList(aDATAINDEX : integer; var aXMLOutput : TStringList);
 var
  t : integer;

 begin
  //----------------------------------------------------------------------------
  // --directory list---by file count-------------------------------------------
  //----------------------------------------------------------------------------
  aXMLOutput.Add('<folderlist>');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    for t := 0 to GScanDetails[aDATAINDEX].RootFolders.Count - 1 do begin
      aXMLOutput.Add('  <folder name="' + TXFormatting.Privacy(GScanDetails[aDATAINDEX].RootFolders[t].Name) + '" hidden="' + BoolToStr((GScanDetails[aDATAINDEX].RootFolders[t].Attributes and Sysutils.faHidden) = Sysutils.faHidden) + '">');

      aXMLOutput.Add(TXFormatting.InsertElement('numberoffiles',          IntToStr(GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount]), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('numberoffilesaspercent', IntToStr(Round((GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount] / GScanDetails[aDATAINDEX].FileCount) * 100)), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizeoffiles',            TConvert.ConvertToUsefulUnit(GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootSize]), 2));
      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', IntToStr(Round((GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootSize] / GScanDetails[aDATAINDEX].TotalSize) * 100)), 2))
      else
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', '100', 2));

      aXMLOutput.Add('  </folder>');
    end;
  end;

  aXMLOutput.Add('</folderlist>');
end;


procedure TXMLReport.XMLReportMagnitude(aDATAINDEX : integer; var aXMLOutput : TStringList);
 var
  t : integer;
  lCategory : integer;
  lTitle : string;

 begin
  //-----------------------------------------------------------------
  //-- magnitudes ---------------------------------------------------
  //-----------------------------------------------------------------
  aXMLOutput.Add('<magnitudelist>');

  for lCategory := 0 to __FileCategoriesCount do begin

    if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

      if lCategory = 0 then
        lTitle := XText[rsMagnitude] + ': ' + XText[rsAll]
      else
        lTitle := XText[rsMagnitude] + ': ' + TypeDescriptions[lCategory];

      if (lCategory = 0) or (GScanDetails[aDataIndex].Magnitude.HasData(lCategory)) then begin

        aXMLOutput.Add('  <magnitudecategory name=''' + lTitle + '''>');

        for t := 0 to __MagnitudesCount do begin
          aXMLOutput.Add('    <magnitude name=''' + magnilabels3[t] + '''>');
          aXMLOutput.Add(TXFormatting.InsertElement('numberoffiles',          IntToStr(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t,0]), 3));
          aXMLOutput.Add(TXFormatting.InsertElement('numberoffilesaspercent', IntToStr(Round((GScanDetails[aDataIndex].Magnitude.Data[lCategory, t,0] /GScanDetails[aDATAINDEX].FileCount)*100)), 3));
          aXMLOutput.Add(TXFormatting.InsertElement('sizeoffiles',            TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t,1]), 3));

          if GScanDetails[aDATAINDEX].TotalSize <> 0 then
            aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', IntToStr(Round((GScanDetails[aDataIndex].Magnitude.Data[lCategory, t,1] /GScanDetails[aDATAINDEX].TotalSize) * 100)), 3))
          else
            aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', '100', 3));
          aXMLOutput.Add('    </magnitude>');
        end;

        aXMLOutput.Add('  </magnitudecategory>');
      end;
    end;
  end;

  aXMLOutput.Add('</magnitudelist>');
end;


procedure TXMLReport.XMLReportExtensionLists(aDATAINDEX : integer; var aXMLOutput : TStringList);
 var
  t, z : integer;
  tfx : TFileExtension;

 begin
  //-----------------------------------------------------------------
  //----- extension lists -------------------------------------------
  //-----------------------------------------------------------------
  for t := 1 to __FileCategoriesCount do begin
    if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

      aXMLOutput.Add('<extensiondata>');

      aXMLOutput.Add('  <extensioncategory name=''' + TypeDescriptions[t] + '''>');
      aXMLOutput.Add(TXFormatting.InsertElement('numberoffiles',          IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('numberoffilesaspercent', IntToStr(Round((GScanDetails[aDataIndex].ExtensionSpread[t, 1] /GScanDetails[aDATAINDEX].FileCount) * 100)), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizoffiles',             TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, 2]), 2));

      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', IntToStr(Round((GScanDetails[aDataIndex].ExtensionSpread[t, 2] /GScanDetails[aDATAINDEX].TotalSize) * 100)), 2))
      else
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', '100', 2));

      aXMLOutput.Add('  </extensioncategory>');

      if t <= 9 then begin
        for z := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
          tfx := FileExtensionsObject.CategoryExtensions[z];

          if tfx.Category = t then begin
            //only include within report if number of files in extension > 0
            if tfx.Quantity[aDATAINDEX] > 0 then begin
              aXMLOutput.Add('  <extension name=''' + tfx.Name + '''>');
              aXMLOutput.Add(TXFormatting.InsertElement('numberoffiles',          IntToStr(tfx.Quantity[aDATAINDEX]), 2));
              aXMLOutput.Add(TXFormatting.InsertElement('numberoffilesaspercent', IntToStr(Round((tfx.Quantity[aDATAINDEX] /GScanDetails[aDATAINDEX].FileCount) * 100)), 2));
              aXMLOutput.Add(TXFormatting.InsertElement('sizeoffiles',            TConvert.ConvertToUsefulUnit(tfx.Size[aDATAINDEX]), 2));

              if GScanDetails[aDATAINDEX].TotalSize <> 0 then
                aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', IntToStr(Round((tfx.Size[aDATAINDEX] /GScanDetails[aDATAINDEX].TotalSize) * 100)), 2))
              else
                aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', '100', 2));
              aXMLOutput.Add('  </extension>');
            end;
          end;
        end;
      end
      else begin
        for z := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin

          if FileExtensionsObject.CategoryExtensions[z].Category = Category_Other then begin
            if FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX] > 0 then begin
              aXMLOutput.Add('  <extension name=''' + FileExtensionsObject.CategoryExtensions[z].Name + ''' >');
              aXMLOutput.Add(TXFormatting.InsertElement('numberoffiles',          IntToStr(FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX]), 2));
              aXMLOutput.Add(TXFormatting.InsertElement('numberoffilesaspercent', IntToStr(Round((FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX] / GScanDetails[aDATAINDEX].FileCount) * 100)), 2));
              aXMLOutput.Add(TXFormatting.InsertElement('sizeoffiles',            TConvert.ConvertToUsefulUnit(FileExtensionsObject.CategoryExtensions[z].Size[aDATAINDEX]), 2));

              if GScanDetails[aDATAINDEX].TotalSize<> 0 then
                aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', IntToStr(Round((FileExtensionsObject.CategoryExtensions[z].Size[aDATAINDEX] / GScanDetails[aDATAINDEX].TotalSize) * 100)), 2))
              else
                aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', '100', 2));

              aXMLOutput.Add('  </extension>');
            end;
          end;
        end;
      end;

      aXMLOutput.Add('</extensiondata>');
    end;
  end;
end;


procedure TXMLReport.XMLReportNullFiles(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGNullFiles, aSGNullFolders : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGNullFiles <> Nil) and (aSGNullFolders <> Nil) then begin
    //-----------------------------------------------------------------
    //--null files ----------------------------------------------------
    //-----------------------------------------------------------------

    if aSGNullFiles.Cells[0, 1] <> XText[rsNoneFound] then begin
      aXMLOutput.Add('<nullfiles>');

      for t := 1 to aSGNullFiles.RowCount - 1 do begin
        aXMLOutput.Add('  <nullfile name=''' + TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(aSGNullFiles.Cells[0, t])) + ''' />');
      end;

      aXMLOutput.Add('</nullfiles>');
    end
    else
      aXMLOutput.Add('<nullfiles />');

    if aSGNullFolders.Cells[0, 1] <> XText[rsNoneFound] then begin
      aXMLOutput.Add('<nullfolders>');

      for t := 1 to aSGNullFolders.RowCount - 1 do begin
        aXMLOutput.Add('  <nullfolder name=''' + TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(aSGNullFolders.Cells[0, t])) + ''' />');
      end;

      aXMLOutput.Add('</nullfolders>');
    end
    else
      aXMLOutput.Add('<nullfolders />');
  end;
end;


procedure TXMLReport.XMLReportFileDates(aDATAINDEX : integer; var aXMLOutput : TStringList; aCBFileDates : TComboBox; aTVFileDates : THTMLTreeview);
 var
  t, i, z, filecount : integer;
  year : string;
  filesize : int64;

 begin
  if (aCBFileDates <> Nil) and (aTVFileDates <> Nil) then begin

    aXMLOutput.Add('<filedates type="' + aCBFileDates.Text + '">');

    if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

      for t := 0 to aTVFileDates.Items.Count - 1 do begin
        if aTVFileDates.Items[t].Parent = Nil then begin
          year := Copy(aTVFileDates.Items[t].Text, 4, 4);

          i := Pos(': ', aTVFileDates.Items[t].Text);
          z := Pos(' (', aTVFileDates.Items[t].Text);

          filecount := StrToIntDef(Copy(aTVFileDates.Items[t].Text, i + 2, z - (i + 2)), -1);

          if filecount <> -1 then begin
            i := Pos(')', aTVFileDates.Items[t].Text);

            filesize  := TConvert.ConvertUsefulUnitToInteger(Copy(aTVFileDates.Items[t].Text, z + 2, i - (z + 2)));

            aXMLOutput.Add('  <filedate year="' + year + '">');
            aXMLOutput.Add('    <filecount percentage="' + TConvert.RealToPercent(filecount / GScanDetails[aDATAINDEX].FileCount) + '">' + IntToStr(filecount) +  '</filecount>');

            if GScanDetails[aDATAINDEX].TotalSize <> 0 then
              aXMLOutput.Add('    <filesize percentage="' + TConvert.RealToPercent(filesize / GScanDetails[aDATAINDEX].TotalSize) + '">' + Copy(aTVFileDates.Items[t].Text, z + 2, i - (z + 2)) + '</filecount>')
            else
             aXMLOutput.Add('    <filesize percentage="100%">' + Copy(aTVFileDates.Items[t].Text, z + 2, i - (z + 2)) + '</filecount>');

            aXMLOutput.Add('  </filedate>');
          end;
        end;
      end;
    end;

    aXMLOutput.Add('</filedates>');
  end;
end;


procedure TXMLReport.XMLReportUsers(aDATAINDEX : integer; var aXMLOutput : TStringList);
 var
  t : integer;

 begin
  //-----------------------------------------------------------------
  //-- Users --------------------------------------------------------
  //-----------------------------------------------------------------
  aXMLOutput.Add('<users>');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin
    for t := 0 to GScanDetails[aDATAINDEX].Users.Count - 1 do begin
      aXMLOutput.Add('<user name="' + TXFormatting.Privacy(GScanDetails[aDATAINDEX].Users[t].Name) + '">');
      aXMLOutput.Add(TXFormatting.InsertElement('numberfiles',          IntToStr(GScanDetails[aDATAINDEX].Users[t].Data[XUserCount]), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('numberfilesaspercent', TConvert.RealToPercent(GScanDetails[aDATAINDEX].Users[t].Data[XUserCount] / GScanDetails[aDATAINDEX].FileCount), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('sizeoffiles',          TConvert.ConvertToUsefulUnit(GScanDetails[aDATAINDEX].Users[t].Data[XUserSize]), 2));

      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', TConvert.RealToPercent(GScanDetails[aDATAINDEX].Users[t].Data[XUserSize] / GScanDetails[aDATAINDEX].TotalSize), 2))
      else
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', '100%', 2));

      aXMLOutput.Add('</user>');
    end;
  end;

  aXMLOutput.Add('</users>');
end;


procedure TXMLReport.XMLReportTopLarge(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGTop50Big : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGTop50Big <> Nil) then begin
    //-----------------------------------------------------------------
    //--Top 50 --------------------------------------------------------
    //-----------------------------------------------------------------

    aXMLOutput.Add('<top101largest>');

    for t := 1 to aSGTop50Big.RowCount - 1 do begin
      aXMLOutput.Add('  <top101large size=''' + aSGTop50Big.Cells[1, t] + '''>' + TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(aSGTop50Big.Cells[0, t])) + '</top50large>');
    end;

    aXMLOutput.Add('</top101largest>');
  end;
end;


procedure TXMLReport.XMLReportTopSmallest(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGTop50Small : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGTop50Small <> Nil) then begin
    //-----------------------------------------------------------------
    //--Top 50 --------------------------------------------------------
    //-----------------------------------------------------------------

    aXMLOutput.Add('<top101smallest>');

    for t := 1 to aSGTop50Small.RowCount - 1 do begin
      aXMLOutput.Add('  <top101small size=''' + aSGTop50Small.Cells[1, t] + '''>' + TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(aSGTop50Small.Cells[0, t])) + '</top50small>');
    end;

    aXMLOutput.Add('</top101smallest>');
  end;
end;


procedure TXMLReport.XMLReportTopNewest(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGTop101BigDate : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGTop101BigDate <> Nil) then begin
    //-----------------------------------------------------------------
    //-- Top 101 newest file ------------------------------------------
    //-----------------------------------------------------------------

    aXMLOutput.Add('<top101newest>');

    for t := 1 to aSGTop101BigDate.RowCount - 1 do begin
      aXMLOutput.Add('  <top101new date=''' + aSGTop101BigDate.Cells[1, t] + ''' size=''' + aSGTop101BigDate.Cells[2, t] + ''' owner=''' + TXFormatting.Privacy(aSGTop101BigDate.Cells[3, t]) + '''</top101new>');
    end;

    aXMLOutput.Add('</top101newest>');
  end;
end;


procedure TXMLReport.XMLReportTopOldest(aDATAINDEX : integer; var aXMLOutput : TStringList; aSGTop101SmallDate : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGTop101SmallDate <> Nil) then begin
    //-----------------------------------------------------------------
    //-- Top 101 oldest files -----------------------------------------
    //-----------------------------------------------------------------
    aXMLOutput.Add('<top101oldest>');

    for t := 1 to aSGTop101SmallDate.RowCount - 1 do begin
      aXMLOutput.Add('  <top101old date=''' + aSGTop101SmallDate.Cells[1, t] + ''' size=''' + aSGTop101SmallDate.Cells[2, t] + ''' owner=''' + TXFormatting.Privacy(aSGTop101SmallDate.Cells[3, t]) + '''</top101old>');
    end;

    aXMLOutput.Add('</top101oldest>');
  end;
end;


procedure TXMLReport.XMLReportNameLength(aDATAINDEX : integer; var aXMLOutput : TStringList);
 var
  t : integer;
  lNameLength : string;

 begin
  //-----------------------------------------------------------------
  //file category table----------------------------------------------
  //-----------------------------------------------------------------
  aXMLOutput.Add('<pathlengths>');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    for t := 0 to 279 do begin
      if t = 279 then
        lNameLength := '&gt;=280'
      else
        lNameLength := IntToStr(t + 1);

      aXMLOutput.Add('  <pathlength name="' + lNameLength + '">');
      aXMLOutput.Add(TXFormatting.InsertElement('numberfiles',          IntToStr(GScanDetails[aDataIndex].NameLengthCount[t]), 2));
      aXMLOutput.Add(TXFormatting.InsertElement('numberfilesaspercent', IntToStr(Round((GScanDetails[aDataIndex].NameLengthCount[t] / GScanDetails[aDATAINDEX].FileCount) * 100)), 2));

      aXMLOutput.Add(TXFormatting.InsertElement('sizeoffiles', TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].NameLengthSize[t]), 2));

      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', IntToStr(Round((GScanDetails[aDataIndex].NameLengthSize[t] / GScanDetails[aDATAINDEX].TotalSize) * 100)), 2))
      else
        aXMLOutput.Add(TXFormatting.InsertElement('sizeoffilesaspercent', '100', 2));

      aXMLOutput.Add('  </pathlength>');
    end;
  end;

  aXMLOutput.Add('</pathlengths>');
end;


end.
