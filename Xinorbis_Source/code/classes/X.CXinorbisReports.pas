{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 17th 2020
}


unit X.CXinorbisReports;


interface


uses
  System.SysUtils,

  X.Dialogs.Dialog,

  X.CReportOptions, X.ReportUtility,

  X.GlobalObjects, X.GuiLogic,

  X.Constants, X.Conversions, X.Formatting, X.LanguageHandler, X.Utility;


type
  TXinorbisReport = class
  private
    FJustInTime         : TJustInTime;
    FSetStatusBarText   : TSetStatusBarText;
  public
    procedure GenerateXinorbisReport(aDataIndex : integer; Options : TXinorbisReportOptions);

    property  OnJustInTime       : TJustInTime       read FJustInTime         write FJustInTime;
    property  OnSetStatusBarText : TSetStatusBarText read FSetStatusBarText   write FSetStatusBarText;
  end;


const
  CRowFileName      = 0;
  CRowFilePathIndex = 1;
  CRowSize          = 2;
  CRowSizeOnDisk    = 3;
  CRowDateCreated   = 4;
  CRowDateAccessed  = 5;
  CRowDateModified  = 6;
  CRowTimeCreated   = 7;
  CRowTimeAccessed  = 8;
  CRowTimeModified  = 9;
  CRowCategory      = 10;
  CRowReadOnly      = 11;
  CRowHidden        = 12;
  CRowSysFile       = 13;
  CRowArchive       = 14;
  CRowTemp          = 15;
  CRowOwner         = 16;
  CRowAttributes    = 17;


var
  GReportXinorbis : TXinorbisReport;


implementation


procedure TXinorbisReport.GenerateXinorbisReport(aDataIndex : integer; Options : TXinorbisReportOptions);
var
  tf : TextFile;
  t : integer;

begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 1), 'GenerateXinorbisReport :: invalid dataindex :: ' + inttostr(aDataIndex));

  // maybe statusbar message here

  //now save all data for later retrieval and analysis!
  AssignFile(tf, Options.FileName);

  {$I-}
  Rewrite(tf);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsErrorSavingReport],
                XText[rsErrorSaving] + ' "' + Options.FileName + '".',
                XDialogTypeWarning);
  end
  else begin
    writeln(tf, '{info');
    Writeln(tf, 'XReport2');
    writeln(tf, TXFormatting.Privacy(GScanDetails[aDataIndex].ScanPath));
    writeln(tf, IntToStr(GScanDetails[aDataIndex].FolderCount));
    writeln(tf, IntToStr(GScanDetails[aDataIndex].FileCount));
    writeln(tf, TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].TotalSize));
    Writeln(tf, TUtility.GetDate(GETTIMEFORMAT_DISPLAY) + ', ' + TUtility.GetTime(GETTIMEFORMAT_DISPLAY));
    Writeln(tf, IntToStr(GScanDetails[aDataIndex].ScanType));
    writeln(tf, '}');

    if (GScanDetails[aDataIndex].Folders.Count > 0) then begin
      writeln(tf, '{folderlist');

      for t := 0 to GScanDetails[aDataIndex].Folders.Count - 1 do begin
        writeln(tf, GScanDetails[aDataIndex].Folders[t]);
      end;

      writeln(tf, '}');
    end;

    if (GScanDetails[aDataIndex].Files.Count > 0) then begin
      for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin

        writeln(tf, '{file');

        Writeln(tf, TXFormatting.Privacy(GScanDetails[aDataIndex].Files.Items[t].FileName));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FilePathIndex));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSizeOnDisk));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileDateC));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileDateA));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileDateM));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileTimeC));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileTimeA));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileTimeM));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileCategory));
        Writeln(tf, TConvert.AttributeToIntAsString(GScanDetails[aDataIndex].Files.Items[t].Attributes, faReadOnly));
        Writeln(tf, TConvert.AttributeToIntAsString(GScanDetails[aDataIndex].Files.Items[t].Attributes, faHidden));
        Writeln(tf, TConvert.AttributeToIntAsString(GScanDetails[aDataIndex].Files.Items[t].Attributes, faSysFile));
        Writeln(tf, TConvert.AttributeToIntAsString(GScanDetails[aDataIndex].Files.Items[t].Attributes, faArchive));
        Writeln(tf, TConvert.BoolToInteger(GScanDetails[aDataIndex].Files.Items[t].Temp));
        Writeln(tf, TXFormatting.Privacy(GScanDetails[aDataIndex].Users[GScanDetails[aDataIndex].Files.Items[t].Owner].Name));
        Writeln(tf, IntToStr(GScanDetails[aDataIndex].Files.Items[t].Attributes));

        writeln(tf, '}');
      end;
    end;

    CloseFile(tf);

    GReportUtility.SetLastReport(aDataIndex, Options.Filename, GScanDetails[aDataIndex].ScanPath, ReportXinorbis, LayoutUnknown);

    if Assigned(FSetStatusBarText) then
      FSetStatusBarText(XText[rsXinorbisReportFileName] + ': '  + Options.FileName);
  end;
  {$I+}
end;


end.
