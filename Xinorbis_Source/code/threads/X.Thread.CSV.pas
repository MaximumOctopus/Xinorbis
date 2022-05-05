{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Thread.CSV;

interface

uses
  SysUtils, classes,

  X.Settings, X.CReportOptions, X.Global, X.Formatting, X.Utility,
  X.LanguageHandler;


type
  TCSVThread = class(TThread)
  public
    procedure SetData(dx : integer; CSVOptions : TCSVReportOptions);
  private
  protected
    Options   : TCSVReportOptions;
    dataindex : integer;

    procedure Execute; override;
  end;


implementation


uses
  X.Conversions, X.GlobalObjects, X.CFileObject, X.Constants, X.CUserData;


procedure TCSVThread.SetData(dx : integer; CSVOptions : TCSVReportOptions);
 begin
  dataindex := dx;
  Options   := CSVOptions
end;


procedure TCSVThread.Execute;
 var
  wp : TextFile;
  t  : integer;
  s : string;
  separator : string;
  tfo : TFileObject;
  addtofile : boolean;

 begin
  FreeOnTerminate := True;

  case Options.CSVSeparator of
    CSVSeparatorComma : separator := ',';
    CSVSeparatorTab   : separator := #9;
    CSVSeparatorPling : separator := '|';
  else
    separator := ',';
  end;

  AssignFile(wp, Options.Filename);
  Rewrite(wp);

  case Options.CSVData of
    CDataSummary : begin
          if Options.CSVTitles then
            Writeln(wp, '"' + XText[rsCategory]                            + '"' + separator +
                        '"' + XText[rsQuantity]                            + '"' + separator +
                        '"' + XText[rsQuantity] + ' ' + XText[rsAsPercent] + '"' + separator +
                        '"' + XText[rsSize]                                + '"' + separator +
                        '"' + XText[rsSizeOfFilesBytes]                    + '"' + separator +
                        '"' + XText[rsSize] + ' ' + XText[rsAsPercent]     + '"');

          for t := 1 to __FileCategoriesCount do begin
            s := '"' + TypeDescriptions[t] + '"' + separator;

            s := s + IntToStr(GScanDetails[DataIndex].ExtensionSpread[t, 1]) + separator;

            s := s + '"' + IntToStr(Round((GScanDetails[DataIndex].ExtensionSpread[t, 1] / GScanDetails[DATAINDEX].FileCount) * 100)) + '"' + separator;

            s := s + '"' + TConvert.GetSizeString(Options.CSVUnits, GScanDetails[DataIndex].ExtensionSpread[t, 2]) + '"' + separator;

            s := s + '"' + IntToStr(GScanDetails[DataIndex].ExtensionSpread[t, 2]) + '"' + separator;

            if GScanDetails[DATAINDEX].TotalSize <> 0 then
              s := s + '"' + IntToStr(Round((GScanDetails[DataIndex].ExtensionSpread[t, 2] / GScanDetails[DATAINDEX].TotalSize) * 100)) + '"'
            else
              s := s + '"100"';

            Writeln(wp, s);
          end;
        end;
    CDataFileList : begin
          if Options.CSVTitles then
            Writeln(wp, '"' + XText[rsFileName] + '"' + separator +
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
                        '"' + XText[rsTemporary] + '"');

          for t := 0 to GScanDetails[DataIndex].Files.Count-1 do begin
            tfo := GScanDetails[DataIndex].Files.Items[t];

            addtofile := False;

            if Options.Category = -1 then
              addtofile := True
            else begin
              if tfo.FileCategory = Options.Category then
                addtofile := True;
            end;

            if addtofile then begin
              if (faDirectory and tfo.Attributes) = faDirectory then begin
                s := '"' + TXFormatting.Privacy(tfo.FileName) + '"' + separator;
                s := s + '"' + TXFormatting.Privacy(GScanDetails[DataIndex].Folders[tfo.FilePathIndex] + tfo.FileName) + '"' +  separator;

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

                s := s + '"' + TXFormatting.Privacy(GScanDetails[DataIndex].Users[tfo.Owner].Name) + '"' + separator;

                s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly) + separator;
                s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faHidden) + separator;
                s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faSysFile) + separator;
                s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faArchive) + separator;
                s := s + IntToStr(TConvert.BoolToInteger(tfo.Temp));
              end
              else begin
                s := '"' + TXFormatting.Privacy(tfo.FileName) + '"' + separator;
                s := s + '"'+TXFormatting.Privacy(GScanDetails[DataIndex].Folders[tfo.FilePathIndex] + tfo.Filename) + '"' + separator;

                s := s + '"'+TConvert.GetSizeString(Options.CSVUnits, tfo.FileSize) + '"' + separator;
                s := s + '"'+IntToStr(tfo.FileSize) + '"' + separator;
                s := s + '"'+IntToStr(tfo.FileSizeOnDisk) + '"' + separator;

                s := s + TConvert.IntDateToString(tfo.FileDateC) + separator;
                s := s + TConvert.IntDateToString(tfo.FileDateA) + separator;
                s := s + TConvert.IntDateToString(tfo.FileDateM) + separator;

                s := s + IntToStr(tfo.FileTimeC) + separator;
                s := s + IntToStr(tfo.FileTimeA) + separator;
                s := s + IntToStr(tfo.FileTimeM) + separator;

                s := s + '"' + TypeDescriptions[tfo.FileCategory] + '"' + separator;

                s := s + IntToStr(tfo.FileCategory) + separator;

                s := s + '"' + TXFormatting.Privacy(GScanDetails[DataIndex].Users[tfo.Owner].Name) + '"' + separator;

                s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly) + separator;
                s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faHidden)   + separator;
                s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faSysFile)  + separator;
                s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faArchive)  + separator;
                s := s + IntToStr(TConvert.BoolToInteger(tfo.Temp));
              end;

              Writeln(wp, s);
            end;
          end;
        end;
  end;

  CloseFile(wp); // move
end;


end.
