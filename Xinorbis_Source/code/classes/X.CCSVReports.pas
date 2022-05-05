{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CCSVReports;

interface


uses
  SysUtils, Classes,

  TMSLogging,

  X.Dialogs.Dialog,

  X.CReportOptions, X.ReportUtility, X.CFileObject, X.Conversions,

  X.GuiLogic, X.GlobalObjects, X.Global,

  X.Constants, X.Settings, X.Windows,

  X.Formatting, X.Utility,
  X.LanguageHandler;


type
  TCSVReport = class
  private
    FJustInTime         : TJustInTime;
    FMenuChange         : TMenuChange;
    FSetStatusBarText   : TSetStatusBarText;
  public
    function GenerateCSVReport(aDataIndex : integer; var lCSVOutput : TStringList; Options : TCSVReportOptions; reportlayout : integer): boolean;
    procedure CSVThreadOnTerminate(Sender : TObject);

    property  OnJustInTime       : TJustInTime       read FJustInTime         write FJustInTime;
    property  OnMenuChange       : TMenuChange       read FMenuChange         write FMenuChange;
    property  OnSetStatusBarText : TSetStatusBarText read FSetStatusBarText   write FSetStatusBarText;
  end;


var
  GReportCSV : TCSVReport;


implementation


function TCSVReport.GenerateCSVReport(aDataIndex : integer; var lCSVOutput : TStringList; Options : TCSVReportOptions; reportlayout : integer): boolean;
var
  t  : integer;
  s : string;
  separator : string;
  tfo : TFileObject;
  addtofile : boolean;

begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'GenerateCSVReport :: invalid dataindex :: ' + inttostr(aDataIndex));

  Result := True;

  if aDataIndex <> dataSearch then begin
    if Assigned(FJustInTime) then
      FJustInTime(TabIndexTop50);
  end;

  if Assigned(FMenuChange) then
    FMenuChange('', 1, 1);

  // ===========================================================================

  case Options.CSVSeparator of
    CSVSeparatorComma : separator := ',';
    CSVSeparatorTab   : separator := #9;
    CSVSeparatorPling : separator := '|';
  else
    separator := ',';
  end;

  case Options.CSVData of
    CDataSummary : begin
          try
            if Options.CSVTitles then
              lCSVOutput.Add('"' + XText[rsCategory]                            + '"' + separator +
                             '"' + XText[rsQuantity]                            + '"' + separator +
                             '"' + XText[rsQuantity] + ' ' + XText[rsAsPercent] + '"' + separator +
                             '"' + XText[rsSize]                                + '"' + separator +
                             '"' + XText[rsSizeOfFilesBytes]                    + '"' + separator +
                             '"' + XText[rsSize] + ' ' + XText[rsAsPercent]     + '"');

            for t := 1 to __FileCategoriesCount do begin
              s := '"' + TypeDescriptions[t] + '"' + separator;

              s := s + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]) + separator;

              s := s + '"' + IntToStr(Round((GScanDetails[aDataIndex].ExtensionSpread[t, 1] / GScanDetails[aDataIndex].FileCount) * 100)) + '"' + separator;

              s := s + '"' + TConvert.GetSizeString(Options.CSVUnits, GScanDetails[aDataIndex].ExtensionSpread[t, 2]) + '"' + separator;

              s := s + '"' + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 2]) + '"' + separator;

              if GScanDetails[aDataIndex].TotalSize <> 0 then
                s := s + '"' + IntToStr(Round((GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDataIndex].TotalSize) * 100)) + '"'
              else
                s := s + '"100"';

              lCSVOutput.Add(s);
            end;
          except
            on E : Exception do begin
              ShowXDialog(XText[rsErrorSavingReport], s + ' :: Exception:  ' + E.ClassName + ' :: ' + E.Message, XDialogTypeWarning);
            end;
          end;
        end;
    CDataFileList : begin
          try
            if Options.CSVTitles then
              lCSVOutput.Add('"' + XText[rsFileName] + '"' + separator +
                             '"' + XText[rsFilePath] + '"' + separator +
                             '"' + XText[rsSize] + '"' + separator +
                             '"' + XText[rsSizeOfFilesBytes] + '"' + separator +
                             '"' + XText[rsSizeOnDisk] + '"' + separator +
                             '"' + XText[rsCreatedDate] + '"' + separator +
                             '"' + XText[rsAccessedDate] + '"' + separator +
                             '"' + XText[rsModifiedDate] + '"' + separator +
                             '"' + XText[rsCreatedDate] + ' (' + XText[rsTime] + ')' + '"' + separator +
                             '"' + XText[rsAccessedDate] + ' (' + XText[rsTime] + ')' + '"' + separator +
                             '"' + XText[rsModifiedDate] + ' (' + XText[rsTime] + ')' + '"' + separator +
                             '"' + XText[rsCategory] + '"' + separator +
                             '"' + XText[rsCategory] + ' ID' + '"' + separator +
                             '"' + XText[rsOwner] + '"' + separator +
                             '"' + LanguageTypes[FileType_ReadOnly] + '"' + separator +
                             '"' + LanguageTypes[FileType_Hidden] + '"' + separator +
                             '"' + LanguageTypes[FileType_System] + '"' + separator +
                             '"' + LanguageTypes[FileType_Archive] + '"' + separator +
                             '"' + XText[rsTemporary] + '"' + separator +
                             '"' + XText[rsFileAttributes] + '"');

            for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
              tfo := GScanDetails[aDataIndex].Files.Items[t];

              addtofile := False;

              if Options.Category = -1 then
                addtofile :=True
              else begin
                if tfo.FileCategory = Options.Category then
                  addtofile := True;
              end;

              if addtofile then begin
                if (faDirectory and tfo.Attributes) = faDirectory then begin
                  s := '"' + TXFormatting.Privacy(tfo.FileName) + '"' + separator;
                  s := s + '"' + TXFormatting.Privacy(GScanDetails[aDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName) + '"' +  separator;

                  s := s + UpperCase(XText[rsFolder]) + separator;
                  s := s + '-1' + separator;
                  s := s + '-1' + separator;

                  s := s + TConvert.IntDateToString(tfo.FileDateC) + separator;
                  s := s + TConvert.IntDateToString(tfo.FileDateA) + separator;
                  s := s + TConvert.IntDateToString(tfo.FileDateM) + separator;

                  s := s + IntToStr(tfo.FileTimeC) + separator;
                  s := s + IntToStr(tfo.FileTimeA) + separator;
                  s := s + IntToStr(tfo.FileTimeM) + separator;

                  s := s + UpperCase(XText[rsFolder]) + separator;

                  s := s + '"99"' + separator;

                  s := s + '"' + TXFormatting.Privacy(GScanDetails[aDataIndex].Users[tfo.Owner].Name) + '"' + separator;

                  s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly) + separator;
                  s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faHidden) + separator;
                  s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faSysFile) + separator;
                  s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faArchive) + separator;
                  s := s + IntToStr(TConvert.BoolToInteger(tfo.Temp)) + separator;
                  s := s + IntToStr(tfo.Attributes);
                end
                else begin
                  s := '"' + TXFormatting.Privacy(tfo.FileName) + '"' + separator;
                  s := s + '"'+ TXFormatting.Privacy(GScanDetails[aDataIndex].Folders[tfo.FilePathIndex] + tfo.Filename) + '"' + separator;

                  s := s + '"' + TConvert.GetSizeString(Options.CSVUnits, tfo.FileSize) + '"' + separator;
                  s := s + '"' + IntToStr(tfo.FileSize) + '"' + separator;
                  s := s + '"' + IntToStr(tfo.FileSizeOnDisk) + '"' + separator;

                  s := s + TConvert.IntDateToString(tfo.FileDateC) + separator;
                  s := s + TConvert.IntDateToString(tfo.FileDateA) + separator;
                  s := s + TConvert.IntDateToString(tfo.FileDateM) + separator;

                  s := s + IntToStr(tfo.FileTimeC) + separator;
                  s := s + IntToStr(tfo.FileTimeA) + separator;
                  s := s + IntToStr(tfo.FileTimeM) + separator;

                  s := s + '"' + TypeDescriptions[tfo.FileCategory] + '"' + separator;

                  s := s + IntToStr(tfo.FileCategory) + separator;

                  s := s + '"' + TXFormatting.Privacy(GScanDetails[aDataIndex].Users[tfo.Owner].Name) + '"' + separator;

                  s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly) + separator;
                  s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faHidden)   + separator;
                  s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faSysFile)  + separator;
                  s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faArchive)  + separator;
                  s := s + IntToStr(TConvert.BoolToInteger(tfo.Temp)) + separator;
                  s := s + IntToStr(tfo.Attributes);
                end;

               lCSVOutput.Add(s);
              end;
            end
          except
            on E : Exception do begin
              ShowXDialog(XText[rsErrorSavingReport], s + ' :: Exception:  ' + E.ClassName + ' :: ' + E.Message, XDialogTypeWarning);
            end;
          end;
        end;
  end;

  if (Options.Filename <> '') then begin
    try
      lCSVOutput.SaveToFile(Options.Filename);

      TMSLogger.Info(XText[rsCSVReportSavedAs] + ': ' + Options.FileName);

      if Assigned(FSetStatusBarText) then
        FSetStatusBarText(XText[rsCSVReportSavedAs] + ': '  + Options.FileName);

      GReportUtility.SetLastReport(aDataIndex, Options.Filename, GScanDetails[aDataIndex].ScanPath, ReportCSV, reportlayout);
    except
      ShowXDialog(XText[rsErrorSavingReport], XText[rsErrorSaving] + ' "' + Options.FileName + '".', XDialogTypeWarning);

      Result := False;
    end;
  end;

  CSVThreadOnTerminate(nil);
end;


procedure TCSVReport.CSVThreadOnTerminate(Sender : TObject);
 begin
  if Assigned(FMenuChange) then
      FMenuChange('', 1, 0);

  if (GReportUtility.ReportSubType = LayoutQuick) and (XSettings.Report.CSVOptions[LayoutQuick].CSVAutoOpen) then begin
    if XSettings.Report.CSVOutput <> '' then
      TXWindows.ExecuteFile(0, '"' + XSettings.Report.CSVOutput + '"', '"' + XSettings.Report.CSVOptions[LayoutQuick].FileName + '"', '')
    else
      TXWindows.ExecuteFile(0, 'notepad.exe', '"' + XSettings.Report.CSVOptions[LayoutQuick].FileName + '"', '');
  end;

  if Assigned(FSetStatusBarText) then
    FSetStatusBarText('Finished saving CSV report.');
end;


end.
