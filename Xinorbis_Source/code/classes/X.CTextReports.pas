{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CTextReports;

interface


uses
  SysUtils, System.Classes, dialogs,
  AdvGrid,

  X.CReportOptions, X.ReportUtility,

  X.Dialogs.Dialog,

  X.Constants, X.Conversions, X.FileExtension, X.FileExtensionsObject, X.Formatting, X.Global, X.GlobalObjects,
  X.LanguageHandler, X.GuiLogic,
  X.Settings, {X.SystemGlobal,} X.Utility, X.Windows;


type
  TTextReport = class
  private
    FJustInTime         : TJustInTime;
    FSetStatusBarText   : TSetStatusBarText;

    FAdvStringGrids     : array[0..2, 0..5] of TAdvStringGrid;

    procedure TextReportHeader(aDATAINDEX : integer; var aTextOutput : TStringList);
    procedure TextReportSummary(aDATAINDEX : integer; var aTextOutput : TStringList; Options : TTextReportOptions);
    procedure TextReportAttributes(aDATAINDEX : integer; var aTextOutput : TStringList);
    procedure TextReportCategories(aDATAINDEX : integer; var aTextOutput : TStringList);
    procedure TextReportDirectoryList(aDATAINDEX : integer; var aTextOutput : TStringList);
    procedure TextReportMagnitude(aDATAINDEX : integer; var aTextOutput : TStringList);
    procedure TextReportExtensions(aDATAINDEX : integer; var aTextOutput : TStringList; aOptions : TTextReportOptions);
    procedure TextReportNullFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGNullFiles, aSGNullFolders : TAdvStringGrid);
    procedure TextReportUsers(aDATAINDEX : integer; var aTextOutput : TStringList);
    procedure TextReportLargestFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGTop50Big : TAdvStringGrid);
    procedure TextReportSmallestFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGTop50Small : TAdvStringGrid);
    procedure TextReportMewestFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGTop101BigDate : TAdvStringGrid);
    procedure TextReportOldestFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGTop101SmallDate : TAdvStringGrid);
    procedure TextReportNameLength(aDATAINDEX : integer; var aTextOutput : TStringList);
  public
    procedure GenerateTextReport(aDataIndex : integer; var aTextOutput : TStringList; Options : TTextReportOptions);

    procedure SetGrids(aDataIndex : integer; var aNullFiles : TAdvStringGrid;
                                             var aNullFolders : TAdvStringGrid;
                                             var aTop50Big : TAdvStringGrid;
                                             var aTop50Small : TAdvStringGrid;
                                             var aTop101BigDate : TAdvStringGrid;
                                             var aTop101SmallDate : TAdvStringGrid);

    function  BuildTextReportOptionsFromFile(const fn : string): TTextReportOptions;

    property  OnJustInTime       : TJustInTime       read FJustInTime         write FJustInTime;
    property  OnSetStatusBarText : TSetStatusBarText read FSetStatusBarText   write FSetStatusBarText;
  end;

var
  GReportText : TTextReport;


implementation


const
  TRDescriptionWidth = 25;
  TRQuantityWidth    =  9;
  TRAsPercentWidth   =  7;
  TRSizeWidth        = 11;

  CNullFiles         =  0;
  CNullFolders       =  1;
  CTop50Big          =  2;
  CTop50Small        =  3;
  CTop101BigDate     =  4;
  CTop101SmallDate   =  5;


procedure TTextReport.GenerateTextReport(aDataIndex : integer; var aTextOutput : TStringList; Options : TTextReportOptions);
var
  t : integer;
  s : string;

  procedure AddTextReportItem(sidx : integer);
  begin
    case sidx of
      CTextHeader     : TextReportHeader(aDataIndex, aTextOutput);
      CTextSummary    : TextReportSummary(aDataIndex, aTextOutput, Options);
      CTextAttributes : TextReportAttributes(aDataIndex, aTextOutput);
      CTextCategory   : TextReportCategories(aDataIndex, aTextOutput);
      CTextFolders    : TextReportDirectoryList(aDataIndex, aTextOutput);
      CTextMagnitude  : TextReportmagnitude(aDataIndex, aTextOutput);
      CTextExtensions : TextReportExtensions(aDataIndex, aTextOutput, Options);
      CTextNullFiles  : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexNull);

                          TextReportNullFiles(aDataIndex, aTextOutput, FAdvStringGrids[aDataIndex, CNullFiles], FAdvStringGrids[aDataIndex, CNullFolders]);
                        end;
      CTextDatesC     : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexDatesCreated);
                        end;
      CTextDatesA     : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexDatesAccessed);
                        end;
      CTextDatesM     : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexDatesModified);
                        end;
      CTextUsers      : TextReportUsers(aDataIndex, aTextOutput);
      CTextLargest    : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexTop50);

                          TextReportLargestFiles(aDataIndex, aTextOutput, FAdvStringGrids[aDataIndex, CTop50Big]);
                        end;
      CTextSmallest   : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexTop50);

                          TextReportSmallestFiles(aDataIndex, aTextOutput, FAdvStringGrids[aDataIndex, CTop50Small]);
                        end;
      CTextNewest     : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexTop50);

                          TextReportMewestFiles(aDataIndex, aTextOutput, FAdvStringGrids[aDataIndex, CTop101BigDate]);
                        end;
      CTextOldest     : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexTop50);

                          TextReportOldestFiles(aDataIndex, aTextOutput, FAdvStringGrids[aDataIndex, CTop101SmallDate]);
                        end;
      CTextNameLength : begin
                          if Assigned(FJustInTime) then
                            FJustInTime(TabIndexNameLength);

                          TextReportNameLength(aDataIndex, aTextOutput);
                        end;
    end;
  end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'GenerateTextReport :: invalid dataindex :: ' + inttostr(aDataIndex));

  s := '';

  for t := 1 to length(Options.Layout) do begin
    if Options.Layout[t] = ':' then begin
      AddTextReportItem(StrToIntDef(s, -1));

      s := '';
    end
    else
      s := s + Options.Layout[t];
  end;

  aTextOutput.Add('');
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add('=========== Xinorbis 8 = (c) Paul A Freshney ' + TUtility.GetCurrentYear + ' / Text Report ==');

  if Options.Filename <> '' then begin
    try
      aTextOutput.SaveToFile(Options.FileName);

      GReportUtility.SetLastReport(aDataIndex, Options.Filename, GScanDetails[aDataIndex].ScanPath, ReportText, LayoutUnknown);

      if Assigned(FSetStatusBarText) then
        FSetStatusBarText(XText[rsTextReportSavedAs] + ': '  + Options.FileName);
    except
      ShowXDialog(XText[rsErrorSavingReport], XText[rsErrorSaving] + ' "' + Options.FileName + '".', XDialogTypeWarning);
    end;
  end;
end;


procedure TTextReport.SetGrids(aDataIndex : integer; var aNullFiles : TAdvStringGrid;
                                                     var aNullFolders : TAdvStringGrid;
                                                     var aTop50Big : TAdvStringGrid;
                                                     var aTop50Small : TAdvStringGrid;
                                                     var aTop101BigDate : TAdvStringGrid;
                                                     var aTop101SmallDate : TAdvStringGrid);
begin
  FAdvStringGrids[aDataIndex, CNullFiles]       := aNullFiles;
  FAdvStringGrids[aDataIndex, CNullFolders]     := aNullFolders;
  FAdvStringGrids[aDataIndex, CTop50Big]        := aTop50Big;
  FAdvStringGrids[aDataIndex, CTop50Small]      := aTop50Small;
  FAdvStringGrids[aDataIndex, CTop101BigDate]   := aTop101BigDate;
  FAdvStringGrids[aDataIndex, CTop101SmallDate] := aTop101SmallDate;
end;


procedure TTextReport.TextReportHeader(aDATAINDEX : integer; var aTextOutput : TStringList);
 begin
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add('------------------------------------------------------------------');
  aTextOutput.Add('-- Xinorbis 8 ----------------------------------------------------');
  aTextOutput.Add('------------------------------------------------------------------');
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add('');
end;


procedure TTextReport.TextReportSummary(aDATAINDEX : integer; var aTextOutput : TStringList; Options : TTextReportOptions);
 var
  t : integer;

 begin
   //-- simple summary -----------------------------------------------
   if XSettings.LastScanMultiple then begin
     aTextOutput.Add(SummaryReport[0] + TXFormatting.Privacy(GScanDetails[aDataIndex].MultipleList.Strings[0]) + '"');
    for t := 1 to GScanDetails[aDataIndex].MultipleList.Count - 1 do begin
        aTextOutput.Add(TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') +
                           '"' + TXFormatting.Privacy(GScanDetails[aDataIndex].MultipleList.Strings[t]) + '"');
     end;
   end
   else
     aTextOutput.Add(SummaryReport[0] + '"' + TXFormatting.Privacy(GScanDetails[aDATAINDEX].ScanPath) + '"');

   aTextOutput.Add(TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + TUtility.GetDate(GETTIMEFORMAT_DISPLAY) + ', ' + TUtility.GetTime(GETTIMEFORMAT_DISPLAY));

   if (GScanDetails[aDataIndex].ScanSource = ScanSourceFolderHistory) then begin
     aTextOutput.Add('');
     aTextOutput.Add(TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + XText[rsFolderHistory] + ': ' + GScanDetails[aDataIndex].ScanDateFHStr);
   end;

   if (aDataIndex = dataSearch) then begin
     aTextOutput.Add('');
     aTextOutput.Add(TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + XText[rsSearch] + ': "' + Options.Special + '"');
   end;

   aTextOutput.Add('');

   aTextOutput.Add(SummaryReport[1] + IntToStr(GScanDetails[aDATAINDEX].FileCount));
   aTextOutput.Add(SummaryReport[2] + IntToStr(GScanDetails[aDataIndex].FolderCount));

   if GScanDetails[aDATAINDEX].TotalSize < (1024 * 1024) then
     aTextOutput.Add(SummaryReport[3] + FloatToStrF((GScanDetails[aDATAINDEX].TotalSize / 1024), ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitKB])
   else if GScanDetails[aDATAINDEX].TotalSize < (1024 * 1024 * 1024) then
     aTextOutput.Add(SummaryReport[3] + FloatToStrF((GScanDetails[aDATAINDEX].TotalSize / (1024*1024)), ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitMB])
   else
     aTextOutput.Add(SummaryReport[3] + FloatToStrF((GScanDetails[aDATAINDEX].TotalSize / (1024*1024*1024)), ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitGB]);

  aTextOutput.Add('');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then
    aTextOutput.Add(SummaryReport[8] + TConvert.ConvertToUsefulUnit(Round(GScanDetails[aDATAINDEX].TotalSize /GScanDetails[aDATAINDEX].FileCount)));

  if GScanDetails[aDataIndex].FolderCount <> 0 then
    aTextOutput.Add(SummaryReport[9] + FloatToStrF(GScanDetails[aDATAINDEX].FileCount /GScanDetails[aDataIndex].FolderCount, ffFixed, 7, 2, XinorbisFormatSettings));

  aTextOutput.Add('');
end;


procedure TTextReport.TextReportAttributes(aDATAINDEX : integer; var aTextOutput : TStringList);
 var
  t : integer;
  str : string;

 begin
  //-- attributes --------------------------------------------------------------
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[3]);
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[4]);
  aTextOutput.Add(TextReport[0]);

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    for t := 1 to __AttributesToDisplayCount do begin
      str := TXFormatting.AddTrailing(' '  + LanguageTypes[t], TRDescriptionWidth, ' ');
      str := str + TXFormatting.AddLeading(IntToStr(GScanDetails[aDataIndex].FileAttributes[t, 0]), TRQuantityWidth, ' ');
      str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 0] / GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
      str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].FileAttributes[t, 1]), TRSizeWidth, ' ');

      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 1] /GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
      else
        str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

      aTextOutput.Add( str);
    end;
  end;

  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add('');
end;


procedure TTextReport.TextReportCategories(aDATAINDEX : integer; var aTextOutput : TStringList);
 var
  t : integer;
  str : string;

 begin
  //-- categories --------------------------------------------------------
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[1]);
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[2]);
  aTextOutput.Add(TextReport[0]);

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    for t := 1 to __FileCategoriesCount do begin
      str := TXFormatting.AddTrailing(' ' + TypeDescriptions[t], TRDescriptionWidth, ' ');
      str := str + TXFormatting.AddLeading(IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]), TRQuantityWidth, ' ');
      str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 1] /GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
      str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, 2]), TRSizeWidth, ' ');

      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 2] /GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
      else
        str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

      aTextOutput.Add(str);
    end;

    aTextOutput.Add('');

    str := TXFormatting.AddTrailing(' ' + XText[rsTemporary], TRDescriptionWidth, ' ');
    str := str + TXFormatting.AddLeading(IntToStr(GScanDetails[aDataIndex].ExtensionSpread[0, 1]), TRQuantityWidth, ' ');
    str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[0, 1] / GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
    str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[0, 2]), TRSizeWidth, ' ');

    if GScanDetails[aDATAINDEX].TotalSize <> 0 then
      str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[0, 2] / GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
    else
      str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

    aTextOutput.Add(str);
  end;

  aTextOutput.Add(TextReport[+0]);
  aTextOutput.Add('');
end;


procedure TTextReport.TextReportDirectoryList(aDATAINDEX : integer; var aTextOutput : TStringList);
 var
  t : integer;
  str : string;

 begin
  //-- directory list -----------------------------------------------
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[5]);
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[6]);
  aTextOutput.Add(TextReport[0]);

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    for t := 0 to GScanDetails[aDATAINDEX].RootFolders.Count - 1 do begin
      str := TXFormatting.AddTrailing(' ' +TXFormatting.Privacy(GScanDetails[aDATAINDEX].RootFolders[t].Name), TRDescriptionWidth, ' ');
      str := str + TXFormatting.AddLeading(IntToStr(GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount]), TRQuantityWidth, ' ');
      str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount] /GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
      str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootSize]), TRSizeWidth, ' ');

      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootSize] /GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
      else
        str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails[aDATAINDEX].RootFolders[t].Attributes);

      aTextOutput.Add(str);
    end;
  end;

  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add('');
end;


procedure TTextReport.TextReportmagnitude(aDATAINDEX : integer; var aTextOutput : TStringList);
 var
  t, lCategory : integer;
  str, lTitle : string;

 begin
  //-- file magnitudes ----------------------------------------------

  for lCategory := 0 to 19 do begin

    if lCategory = 0 then
      lTitle := '-- ' + XText[rsMagnitude] + ': ' + XText[rsAll] + ' '
    else
      lTitle := '-- ' + XText[rsMagnitude] + ': ' + TypeDescriptions[lCategory] + ' ';

    if (lCategory = 0) or (GScanDetails[aDataIndex].Magnitude.HasData(lCategory)) then begin
      aTextOutput.Add(TextReport[0]);
      aTextOutput.Add(TXFormatting.AddTrailing(lTitle, length(TextReport[0]), '-'));
      aTextOutput.Add(TextReport[0]);
      aTextOutput.Add(TextReport[2]);
      aTextOutput.Add(TextReport[0]);
    end;

    if (GScanDetails[aDataIndex].Magnitude.HasData(lCategory)) then begin
      if GScanDetails[aDATAINDEX].FileCount <> 0 then begin
        for t := 0 to __MagnitudesCount do begin
          str := TXFormatting.AddTrailing(' ' + magnilabels[t], TRDescriptionWidth, ' ');
          str := str + TXFormatting.AddLeading(IntToStr(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 0]), TRQuantityWidth, ' ');
          str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 0] / GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
          str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 1]), TRSizeWidth, ' ');

          if GScanDetails[aDATAINDEX].TotalSize <> 0 then
            str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 1] / GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
          else
            str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

          aTextOutput.Add(str);
        end;
      end;

      aTextOutput.Add(TextReport[0]);
      aTextOutput.Add('');
    end;
  end;
end;


procedure TTextReport.TextReportExtensions(aDATAINDEX : integer; var aTextOutput : TStringList; aOptions : TTextReportOptions);
 var
  t, z : integer;
  str : string;
  tfx : TFileExtension;

 begin
  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    aTextOutput.Add(TextReport[0]);
    aTextOutput.Add(TextReport[8]);
    aTextOutput.Add(TextReport[0]);

    for t := 1 to __FileCategoriesCount do begin
      if aOptions.CategoryList[t] = '1' then begin

        aTextOutput.Add(TextReport[2]);

        str := TXFormatting.AddTrailing(' '  + TypeDescriptions[t], TRDescriptionWidth, ' ');
        str := str + TXFormatting.AddLeading(IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]), TRQuantityWidth, ' ');
        str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 1] / GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
        str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, 2]), TRSizeWidth, ' ');

        if GScanDetails[aDATAINDEX].TotalSize <> 0 then
          str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
        else
          str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

        aTextOutput.Add(str);
        aTextOutput.Add('------------------------------------------------------------------');

        if t <> __FileCategoriesOther then begin
          for z := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
            tfx := FileExtensionsObject.CategoryExtensions[z];

            if tfx.Category = t then begin
              //only include within report if number of files in extension > 0
              if tfx.Quantity[aDATAINDEX] > 0 then begin
                str := TXFormatting.AddTrailing(' ' + tfx.Name, TRDescriptionWidth, ' ');
                str := str + TXFormatting.AddLeading(IntToStr(tfx.Quantity[aDATAINDEX]), TRQuantityWidth, ' ');
                str := str + TXFormatting.AddLeading(TConvert.RealToPercent(tfx.Quantity[aDATAINDEX] / GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
                str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(tfx.Size[aDATAINDEX]), TRSizeWidth, ' ');

                if GScanDetails[aDATAINDEX].TotalSize <> 0 then
                  str := str + TXFormatting.AddLeading(TConvert.RealToPercent(tfx.Size[aDATAINDEX] / GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
                else
                  str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

                aTextOutput.Add(str);
              end;
            end;
          end;
        end
        else begin
          for z := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin

            if FileExtensionsObject.CategoryExtensions[z].Category = Category_Other then begin
              if FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX] <> 0 then begin
                str := TXFormatting.AddTrailing(' ' + FileExtensionsObject.CategoryExtensions[z].Name, TRDescriptionWidth, ' ');
                str := str + TXFormatting.AddLeading(IntToStr(FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX]), TRQuantityWidth, ' ');
                str := str + TXFormatting.AddLeading(TConvert.RealToPercent(FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX] / GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
                str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(FileExtensionsObject.CategoryExtensions[z].Size[aDATAINDEX]), TRSizeWidth, ' ');

                if GScanDetails[aDATAINDEX].TotalSize <> 0 then
                  str := str + TXFormatting.AddLeading(TConvert.RealToPercent(FileExtensionsObject.CategoryExtensions[z].Size[aDATAINDEX] / GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
                else
                  str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

                aTextOutput.Add(str);
              end;
            end;
          end;
        end;

        aTextOutput.Add('');
      end;
    end;
  end;
end;


procedure TTextReport.TextReportNullFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGNullFiles, aSGNullFolders : TAdvStringGrid);
 var
  t : integer;

 begin
  if ((aSGNullFiles <> Nil) and (aSGNullFolders <> Nil)) then begin

    //-- null files ---------------------------------------------------
    aTextOutput.Add(TextReport[0]);
    aTextOutput.Add(TextReport[9]);
    aTextOutput.Add(TextReport[0]);

    if aSGNullFiles.Cells[0, 1] <> XText[rsNoneFound] then begin
      for t := 1 to aSGNullFiles.RowCount - 1 do
        aTextOutput.Add(TXFormatting.Privacy(aSGNullFiles.Cells[0, 1]));
    end
    else
      aTextOutput.Add(XText[rsNoneFound]);

    aTextOutput.Add('');
    aTextOutput.Add(TextReport[0]);
    aTextOutput.Add(TextReport[10]);
    aTextOutput.Add(TextReport[0]);

    if aSGNullFolders.Cells[0, 1] <> XText[rsNoneFound] then begin
      for t := 1 to aSGNullFolders.RowCount - 1 do
        aTextOutput.Add(TXFormatting.Privacy(aSGNullFolders.Cells[0, 1]));
    end
    else
      aTextOutput.Add(XText[rsNoneFound]);
  end;

  aTextOutput.Add('');
end;


procedure TTextReport.TextReportUsers(aDATAINDEX : integer; var aTextOutput : TStringList);
 var
  t : integer;
  str : string;

 begin
  // users ----------------------------------------------------------
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[11]);
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[12]);
  aTextOutput.Add(TextReport[0]);

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    for t := 0 to GScanDetails[aDATAINDEX].Users.Count - 1 do begin
      str := TXFormatting.AddTrailing(' ' + TXFormatting.Privacy(GScanDetails[aDATAINDEX].Users[t].Name), TRDescriptionWidth, ' ');
      str := str + TXFormatting.AddLeading(IntToStr(GScanDetails[aDATAINDEX].Users[t].Data[XUserCount]), TRQuantityWidth, ' ');
      str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDATAINDEX].Users[t].Data[XUserCount] /GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
      str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanDetails[aDATAINDEX].Users[t].Data[XUserSize]), TRSizeWidth, ' ');

      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDATAINDEX].Users[t].Data[XUserSize] /GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
      else
        str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

      aTextOutput.Add(str);
    end;
  end;

  aTextOutput.Add(TextReport[+0]);
  aTextOutput.Add('');
end;


procedure TTextReport.TextReportLargestFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGTop50Big : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGTop50Big <> Nil) then begin
    // top 50 largest files -------------------------------------------
    aTextOutput.Add(TextReport[0]);
    aTextOutput.Add(TextReport[13]);
    aTextOutput.Add(TextReport[0]);

    for t := 1 to aSGTop50Big.RowCount - 1 do begin
      aTextOutput.Add(TXFormatting.AddLeading(aSGTop50Big.Cells[1,t], 9, ' ') + ' ' + TXFormatting.AddTrailing(aSGTop50Big.Cells[2,t], 14, ' ') + ' ' + TXFormatting.Privacy(aSGTop50Big.Cells[0,t]));
    end;

    aTextOutput.Add('');
  end;
end;


procedure TTextReport.TextReportSmallestFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGTop50Small : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGTop50Small <> Nil) then begin
    // top 50 smallest files ------------------------------------------
    aTextOutput.Add(TextReport[0]);
    aTextOutput.Add(TextReport[14]);
    aTextOutput.Add(TextReport[0]);

    for t := 1 to aSGTop50Small.RowCount - 1 do begin
      aTextOutput.Add(TXFormatting.AddLeading(aSGTop50Small.Cells[1,t], 9, ' ') + ' ' + TXFormatting.Privacy(aSGTop50Small.Cells[0,t]));
    end;

    aTextOutput.Add('');
  end;
end;


procedure TTextReport.TextReportMewestFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGTop101BigDate : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGTop101BigDate <> Nil) then begin
    //----------------------------------------------------------------------------
    //--top 101 newest files -----------------------------------------------------
    //----------------------------------------------------------------------------

    aTextOutput.Add(TextReport[0]);
    aTextOutput.Add(TextReport[15]);
    aTextOutput.Add(TextReport[0]);

    for t := 1 to aSGTop101BigDate.RowCount - 1 do begin
      aTextOutput.Add(aSGTop101BigDate.Cells[1, t] + ' ' +
              TXFormatting.AddLeading(aSGTop101BigDate.Cells[2, t], 9, ' ') +
              TXFormatting.AddLeading(aSGTop101BigDate.Cells[3, t], 15, ' ') + ' ' +
              TXFormatting.Privacy(aSGTop101BigDate.Cells[0, t]));
    end;
  end;

  aTextOutput.Add('');
end;


procedure TTextReport.TextReportOldestFiles(aDATAINDEX : integer; var aTextOutput : TStringList; aSGTop101SmallDate : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGTop101SmallDate <> Nil) then begin
    //----------------------------------------------------------------------------
    //--top 101 oldest files -----------------------------------------------------
    //----------------------------------------------------------------------------

    aTextOutput.Add(TextReport[0]);
    aTextOutput.Add(TextReport[14]);
    aTextOutput.Add(TextReport[0]);

    for t := 1 to aSGTop101SmallDate.RowCount - 1 do begin
      aTextOutput.Add(aSGTop101SmallDate.Cells[1, t] + ' ' +
                      TXFormatting.AddLeading(aSGTop101SmallDate.Cells[2, t], 9, ' ') +
                      TXFormatting.AddLeading(aSGTop101SmallDate.Cells[3, t], 15, ' ') + ' ' +
                      TXFormatting.Privacy(aSGTop101SmallDate.Cells[0, t]));
    end;
  end;

  aTextOutput.Add('');
end;


procedure TTextReport.TextReportNameLength(aDATAINDEX : integer; var aTextOutput : TStringList);
var
  t : integer;
  str, lNameLength : string;

begin
  //-- categories --------------------------------------------------------
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[17]);
  aTextOutput.Add(TextReport[0]);
  aTextOutput.Add(TextReport[18]);
  aTextOutput.Add(TextReport[0]);

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin

    for t := 0 to 279 do begin
      if t = 279 then
        lNameLength := '>=280'
      else
        lNameLength := IntToStr(t + 1);

      if GScanDetails[aDataIndex].NameLengthCount[t] <> 0 then begin
        str := TXFormatting.AddTrailing(' ' + lNameLength, TRDescriptionWidth, ' ');
        str := str + TXFormatting.AddLeading(IntToStr(GScanDetails[aDataIndex].NameLengthCount[t]), TRQuantityWidth, ' ');
        str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].NameLengthCount[t] / GScanDetails[aDATAINDEX].FileCount), TRAsPercentWidth, ' ');
        str := str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].NameLengthSize[t]), TRSizeWidth, ' ');

        if GScanDetails[aDATAINDEX].TotalSize <> 0 then
          str := str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanDetails[aDataIndex].NameLengthSize[t] / GScanDetails[aDATAINDEX].TotalSize), TRAsPercentWidth, ' ')
        else
          str := str + TXFormatting.AddLeading('100%', TRAsPercentWidth, ' ');

        aTextOutput.Add(str);
      end;
    end;

    aTextOutput.Add(str);
  end;

  aTextOutput.Add(TextReport[+0]);
  aTextOutput.Add('');
end;


function TTextReport.BuildTextReportOptionsFromFile(const fn : string): TTextReportOptions;
 var
  tf : TextFile;
  s : string;
  tTextro : TTextReportOptions;

 begin
  Assert(fn <> '', 'BuildTextReportOptionsFromFile :: invalid filename');

  AssignFile(tf, fn);
  {$I-}
  Reset(tf);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsErrorOpening] + ': ' + XText[rsReport],
                XText[rsErrorOpening] + ' "' + fn + '".',
                XDialogTypeWarning);
  end
  else begin
    Reset(tf);

    Readln(tf, s);
    tTextro.Layout       := s;

    Readln(tf, s);
    tTextro.CategoryList := s;

    CloseFile(tf);
  end;
  {$I+}

  Result := tTextro;
end;


end.
