{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CCSVPreview;

interface


uses
  System.SysUtils, Classes,

  X.CReportColours, X.CReportOptions, X.Formatting,

  X.Conversions, X.Constants, X.LanguageHandler, X.Utility, X.Global, X.SystemGlobal;


type
  TCSVPreview = class
  public
    class procedure Get(aReport : TCSVReportOptions; var aOutput : TStringList);
  end;


implementation


class procedure TCSVPreview.Get(aReport : TCSVReportOptions; var aOutput : TStringList);
var
  s, separator : string;
  t : integer;

begin
  case aReport.CSVSeparator of
    CSVSeparatorComma : separator := ',';
    CSVSeparatorTab   : separator := #9;
    CSVSeparatorPling : separator := '|';
  else
    separator := ',';
  end;

  case aReport.CSVData of
    CDataSummary : begin
          if aReport.CSVTitles then
            aOutput.Add('"' + XText[rsCategory]                + '"' + separator +
                               '"' + XText[rsQuantity]         + '"' + separator +
                               '"' + XText[rsQuantity]         + ' ' + XText[rsAsPercent] + '"' + separator +
                               '"' + XText[rsSize]             + '"' + separator +
                               '"' + XText[rsSizeOfFilesBytes] + '"' + separator +
                               '"' + XText[rsSize] + ' ' + XText[rsAsPercent] + '"');

          for t := 1 to __FileCategoriesCount do begin
            s := '"' + TypeDescriptions[t] + '"' + separator;

            s := s + '1234' + separator;

            s := s + '"100%"' + separator;

            case aReport.CSVUnits of
              CSVUnitsConvenient : s := s + '"120.51 KB"'                     + separator;
              CSVUnitsBytes      : s := s + '"123412 ' + XText[rsBytes] + '"' + separator;
              CSVUnitsKilobytes  : s := s + '"120.51 KB"'                     + separator;
              CSVUnitsMegabytes  : s := s + '"0.12 MB"'                       + separator;
            end;

            s := s + '"123412"' + separator;

            s := s + '"100"';

            aOutput.Add(s);
          end;
        end;
    CDataFileList : begin
          if aReport.CSVTitles then
            aOutput.Add('"' + XText[rsFileName]                                  + '"' + separator +
                        '"' + XText[rsFilePath]                                  + '"' + separator +
                        '"' + XText[rsSize]                                      + '"' + separator +
                        '"' + XText[rsSizeOfFilesBytes]                          + '"' + separator +
                        '"' + XText[rsSizeOnDisk]                                + '"' + separator +
                        '"' + XText[rsCreatedDate]                               + '"' + separator +
                        '"' + XText[rsAccessedDate]                              + '"' + separator +
                        '"' + XText[rsModifiedDate]                              + '"' + separator +
                        '"' + XText[rsCreatedDate] + ' (' + XText[rsTime] + ')'  + '"' + separator +
                        '"' + XText[rsAccessedDate] + ' (' + XText[rsTime] + ')' + '"' + separator +
                        '"' + XText[rsModifiedDate] + ' (' + XText[rsTime] + ')' + '"' + separator +
                        '"' + XText[rsCategory]                                  + '"' + separator +
                        '"' + XText[rsCategory] + ' ID'                          + '"' + separator +
                        '"' + XText[rsOwner]                                     + '"' + separator +
                        '"' + LanguageTypes[FileType_ReadOnly]                   + '"' + separator +
                        '"' + LanguageTypes[FileType_Hidden]                     + '"' + separator +
                        '"' + LanguageTypes[FileType_System]                     + '"' + separator +
                        '"' + LanguageTypes[FileType_Archive]                    + '"' + separator +
                        '"' + XText[rsTemporary] + '"');

          for t := 1 to 15 do begin
             if odd(t) then begin
                s := '"' + TXFormatting.Privacy('CSV Folder' + IntToStr(t)) + '"' + separator;
                s := s + '"' + TXFormatting.Privacy('c:\preview\temp\CSV Filename' + IntToStr(t)) + '\"'+  separator;

                s := s + UpperCase(XText[rsFolder]) + separator;
                s := s + '-1' + separator;
                s := s + '-1' + separator;

                s := s + TConvert.IntDateToString(19750417) + separator;
                s := s + TConvert.IntDateToString(18710830) + separator;
                s := s + TConvert.IntDateToString(19231215) + separator;

                s := s + IntToStr(19750417) + separator;
                s := s + IntToStr(18710830) + separator;
                s := s + IntToStr(19231215) + separator;

                s := s + UpperCase(XText[rsFolder]) + separator;

                s := s + '"99"' + separator;

                s := s + TXFormatting.Privacy('"Rutherford"') + separator;

                s := s + '1' + separator;
                s := s + '0' + separator;
                s := s + '0' + separator;
                s := s + '1' + separator;
                s := s + '0';
             end
             else begin
                s := '"' + TXFormatting.Privacy('CSV File Name' + IntToStr(t)) + '"' + separator;
                s := s + '"' + TXFormatting.Privacy('c:\preview\temp\CSV File name' + IntToStr(t)) + '"'+  separator;

                case aReport.CSVUnits of
                  CSVUnitsConvenient : s := s + '"196.98 KB"'                     + separator;
                  CSVUnitsBytes      : s := s + '"201705 ' + XText[rsBytes] + '"' + separator;
                  CSVUnitsKilobytes  : s := s + '"196.98 KB"'                     + separator;
                  CSVUnitsMegabytes  : s := s + '"0.19 MB"'                       + separator;
                end;
                s := s + '"'+IntToStr(201705) + '"' + separator;
                s := s + '"'+IntToStr(201705) + '"' + separator;

                s := s + TConvert.IntDateToString(19750417) + separator;
                s := s + TConvert.IntDateToString(18710830) + separator;
                s := s + TConvert.IntDateToString(19231215) + separator;

                s := s + IntToStr(19750417) + separator;
                s := s + IntToStr(18710830) + separator;
                s := s + IntToStr(19231215) + separator;

                s := s + '"' + TypeDescriptions[t] + '"' + separator;

                s := s + IntToStr(t) + separator;

                s := s + TXFormatting.Privacy('"Freeman"') + separator;

                s := s + '1' + separator;
                s := s + '1' + separator;
                s := s + '0' + separator;
                s := s + '0' + separator;
                s := s + '1';
             end;

             aOutput.Add(s);
           end;
        end;
  end;
end;


end.
