{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.ReportUtility;

interface

uses
  System.SysUtils,

  TMSLogging,

  X.Conversions, X.GuiLogic;


type
  TReportUtility = class
  private
    FLastReportFilename : string;
    FReportType         : integer;
    FReportSubType      : integer;
    FNewReport          : TNewReport;

    FReportListFileName : string;
  public
    constructor Create;

    procedure ClearLastReport;
    procedure SetLastReport(aDataIndex : integer; const fn, aScanPath : string; aReportType, aReportSubType : integer);

    function  GetReportType(aFileName: string): integer;

    property  LastReportFilename : string            read FLastReportFilename write FLastReportFilename;
    property  ReportType         : integer           read FReportType         write FReportType;
    property  ReportSubType      : integer           read FReportSubType      write FReportSubType;

    property  ReportListFileName : string            read FReportListFileName write FReportListFileName;

    property  OnNewReport        : TNewReport        read FNewReport          write FNewReport;
  end;


const
  CReportTypeCSV       = 0;
  CReportTypeHTML      = 1;
  CReportTypeText      = 2;
  CReportTypeTree      = 3;
  CReportTypeXinorbis  = 4;
  CReportTypeXML       = 5;
  CReportTypeXinorbis2 = 6;
  CReportTypeUnknown   = 99;


var
  GReportUtility : TReportUtility;


implementation


constructor TReportUtility.Create;
begin
  ClearLastReport;

  FReportListFileName := '';
end;


procedure TReportUtility.SetLastReport(aDataIndex : integer; const fn, aScanPath : string; aReportType, aReportSubType : integer);
var
  tf : TextFile;

begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'SetLastReport :: invalid dataindex :: ' + inttostr(aDataIndex));

  if fn <> '' then begin
    FLastReportFilename := fn;
    FReportType         := aReportType;
    FReportSubType      := aReportSubType;

    //==========================================================================
    //== add to report list ====================================================
    //==========================================================================

    try
      AssignFile(tf, FReportListFileName);
      if FileExists(FReportListFileName) then
        {$I-}
        Append(tf)
        {$I+}
      else
        {$I-}
        Rewrite(tf);
        {$I+}

      if (IOResult <> 0) then begin
        // GScanDetails[aDataIndex].ScanPath
        Writeln(tf, IntToStr(FReportType) + ';' + aScanPath + ';' + TConvert.DateToYYYYMMDD(Now) + TConvert.TimeToString(Now, False) + ';' + fn + ';');
      end
      else
        TMSLogger.Error('Error updating "' + FReportListFileName + '". IOResult: ' + IntToStr(IOResult));
    finally
      CloseFile(tf);
    end;

    if Assigned(FNewReport) then
      FNewReport;
  end;
end;


procedure TReportUtility.ClearLastReport;
begin
  FLastReportFilename := '';
  FReportType         := -1;
  FReportSubType      := -1;
end;


function TReportUtility.GetReportType(aFileName: string): integer;
begin
  if UpperCase(ExtractFileExt(aFileName)) = '.CSV' then
    Result := CReportTypeCSV
  else if (UpperCase(ExtractFileExt(aFileName)) = '.HTM') or
          (UpperCase(ExtractFileExt(aFileName)) = '.HTML') then
    Result := CReportTypeHTML
  else if UpperCase(ExtractFileExt(aFileName)) = '.TXT' then
    Result := CReportTypeText
  else if UpperCase(ExtractFileExt(aFileName)) = '.ZSR' then
    Result := CReportTypeXinorbis
  else if UpperCase(ExtractFileExt(aFileName)) = '.ZSR2' then
    Result := CReportTypeXinorbis2
  else if UpperCase(ExtractFileExt(aFileName)) = '.XML' then
    Result := CReportTypeXML
  else
    Result := CReportTypeUnknown;
end;


end.
