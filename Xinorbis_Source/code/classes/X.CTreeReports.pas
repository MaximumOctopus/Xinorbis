{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CTreeReports;

interface


uses
  Generics.Defaults, System.Classes, System.SysUtils,

  TMSLogging,

  X.CReportOptions,

  X.Dialogs.Dialog,

  X.GlobalObjects, X.Global,

  X.Constants, X.Conversions, X.Formatting, X.CFileObject, X.GuiLogic, X.Utility,
  X.LanguageHandler;


type
  TTreeReport = class
  private
    FSetStatusBarText   : TSetStatusBarText;
  public
    function  GenerateTreeReport(aDataIndex : integer; var lTreeOutput : TStringList; Options : TTreeReportOptions): boolean;

    function  BuildTreeReportOptionsFromFile(const fn : string): TTreeReportOptions;

    property  OnSetStatusBarText : TSetStatusBarText read FSetStatusBarText   write FSetStatusBarText;
  end;


var
  GReportTree : TTreeReport;


implementation


function TTreeReport.GenerateTreeReport(aDataIndex : integer; var lTreeOutput : TStringList; Options : TTreeReportOptions): boolean;
 var
  tfoldercount, tfilecount, indent, t : integer;
  tfilesize : Int64;
  oldpath : string;
  lOptional : string;

  function GetIndent(const s : string): integer;
   var
    t : integer;

   begin
    Result := 0;

    for t:= 1 to length(s) do
      if s[t] = '\' then inc(Result);
  end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'GenerateTreeReport :: invalid dataindex :: ' + inttostr(aDataIndex));

  Result := True;

  case aDataIndex of
    dataLatestScan    : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathTreeLS));
    dataFolderHistory : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathTreeFH));
  end;

  oldpath := '';
  indent  := 1;

  tfoldercount := 0;
  tfilecount   := 0;
  tfilesize    := 0;

  for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
    if ((faDirectory and GScanDetails[aDataIndex].Files[t].Attributes) = faDirectory) then begin
      inc(tfoldercount);
    end
    else begin
      if Options.CategoryList[GScanDetails[aDataIndex].Files[t].FileCategory] = '1' then begin
        inc(tfilecount);
        inc(tfilesize, GScanDetails[aDataIndex].Files[t].FileSize);
      end;
    end;
  end;

  lTreeOutput.Add('');
  lTreeOutput.Add(SummaryReport[1] + IntToStr(tfilecount));
  lTreeOutput.Add(SummaryReport[2] + IntToStr(tfoldercount));
  lTreeOutput.Add(SummaryReport[3] + TConvert.ConvertToUsefulUnit(tfilesize));

  if (aDataIndex = dataFolderHistory) then begin
    lTreeOutput.Add('');
    lTreeOutput.Add(TXFormatting.AddLeading('', Length(SummaryReport[1]) - 1, ' ') + XText[rsFolderHistory] + ': ' + GScanDetails[aDataIndex].ScanDateFHStr);
  end;

  lTreeOutput.Add('');

  lTreeOutput.Add(TXFormatting.Privacy(GScanDetails[aDataIndex].ScanPath));

    for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
      if ((faDirectory and GScanDetails[aDataIndex].Files[t].Attributes) = faDirectory) then begin
        if GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files[t].FilePathIndex] + GScanDetails[aDataIndex].Files[t].Filename <> oldpath then begin
          lTreeOutput.Add('');

          oldpath := GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files[t].FilePathIndex] + GScanDetails[aDataIndex].Files[t].Filename;

          indent  := GetIndent(GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files[t].FilePathIndex] + GScanDetails[aDataIndex].Files[t].Filename);

          if Options.IncludeAttributes then
            lOptional := ' [' + TXFormatting.GetAttributesAsString(GScanDetails[aDataIndex].Files[t].Attributes) + ']'
          else
            lOptional := '';


          lTreeOutput.Add(TXFormatting.StringOfChars((indent) * 4, ' ') + '\ ' +
                          TUtility.LastFolder(TXFormatting.Privacy(GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files[t].FilePathIndex] + GScanDetails[aDataIndex].Files[t].Filename)) +
                          lOptional);
        end;
      end
      else begin
        if Options.CategoryList[GScanDetails[aDataIndex].Files[t].FileCategory] = '1' then begin
          if oldpath <> GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files[t].FilePathIndex] then begin
            lTreeOutput.Add('');

            oldpath := GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files[t].FilePathIndex];

            indent  := GetIndent(GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files[t].FilePathIndex] + GScanDetails[aDataIndex].Files[t].Filename)
          end;

          lOptional := '';

          if Options.IncludeSize then
            lOptional := TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].Files[t].FileSize), 8, ' ') + ' ';

          if Options.IncludeAttributes then begin
            lOptional := lOptional + TXFormatting.GetAttributesAsString(GScanDetails[aDataIndex].Files[t].Attributes) + ' ';
          end;

          lTreeOutput.Add(TXFormatting.StringOfChars(indent * 4, ' ') + lOptional + TXFormatting.Privacy(GScanDetails[aDataIndex].Files[t].Filename));
        end;
      end;

    end;

  if (Options.Filename <> '') then begin
    try
      lTreeOutput.SaveToFile(Options.Filename);

      TMSLogger.Info(XText[rsTreeReportSavedAs] + ': ' + Options.FileName);

      if Assigned(FSetStatusBarText) then
        FSetStatusBarText(XText[rsTreeReportSavedAs] + ': '  + Options.FileName);
    except
      ShowXDialog(XText[rsErrorSavingReport], XText[rsErrorSaving] + ' "' + Options.FileName + '".', XDialogTypeWarning);

      Result := False;
    end;
  end;
end;


function TTreeReport.BuildTreeReportOptionsFromFile(const fn : string): TTreeReportOptions;
 var
  tf : TextFile;
  s : string;
  tTreero : TTreeReportOptions;

 begin
  Assert(fn <> '', 'BuildTreeReportOptionsFromFile :: invalid filename');

  AssignFile(tf, fn);
  {$I-}
  Reset(tf);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsErrorOpening] + ': ' + XText[rsReport],
                XText[rsErrorOpening] + ' "' + fn + '".',
                XDialogTypeWarning);
  end
  else begin
    Readln(tf, s);
    tTreero.IncludeSize       := TConvert.StringBoolToInteger(s);

    Readln(tf, s);
    tTreero.IncludeAttributes := TConvert.StringBoolToInteger(s);

    Readln(tf, s);
    tTreero.CategoryList      := s;

    CloseFile(tf);
  end;
  {$I+}

  Result := tTreero;
end;


end.
