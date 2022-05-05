{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CHTMLReports;


interface


uses
  Generics.Defaults, System.Classes, System.SysUtils, Vcl.StdCtrls, System.IniFiles, Math, dialogs,

  VCLTee.TeeProcs, VCLTee.TeEngine, VCLTee.Chart, VCLTee.Series,
  VCLTee.TeCanvas,

  AdvGrid, htmltv,

  X.CReportOptions, X.CUserData, X.ChartUtility, X.ReportUtility, X.CFileObject,

  X.Dialogs.Dialog,

  X.Constants, X.Conversions, X.FileExtension, X.FileExtensionsObject, X.Formatting, X.Global, X.GlobalObjects,
  X.LanguageHandler, X.CSizeOfFolder,
  X.Settings, X.SystemGlobal, X.Utility, X.GuiLogic;


type
  THTMLReport = class
  private
    FJustInTime              : TJustInTime;
    FBuildInformationDisplay : TBuildInformationDisplay;
    FSetStatusBarText        : TSetStatusBarText;

    FHTMLTreeViews      : array[0..2] of THTMLTreeView;
    FAdvStringGrids     : array[0..2, 1..6] of TAdvStringGrid;
    FComboBoxes         : array[0..2, 1..2] of TComboBox;

    FvtcHTML: TChart;
    FvtcHTML2: TChart;

    function  WebFileLink(s : string): string;
    procedure InsertSpacingTable(var aTextFile : TextFile);

    procedure HTMLReportHeader(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; const aFHISelectCaption, aMenuString : string);
    procedure HTMLReportFileCategory(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);
    procedure HTMLReportFileAttributesTable(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions);
    procedure HTMLReportUsers(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions);
    procedure HTMLReportFileExtensionLists(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions);
    procedure HTMLReportMagnitude(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);
    procedure HTMLReportQuickInfo(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);
    procedure HTMLReportDirectoryList(aDATAINDEX, aFileDatesCount : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);

    procedure HTMLReportTop50Largest(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aTop50Big : TAdvStringGrid);
    procedure HTMLReportTop50Smallest(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aTop50Small : TAdvStringGrid);
    procedure HTMLReportTop101Newest(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aTop101BigDate : TAdvStringGrid; aTop101Dates : TComboBox);
    procedure HTMLReportTop101Oldest(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aTop101SmallDate : TAdvStringGrid; aTop101Dates : TComboBox);
    procedure HTMLReportFileDates(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string; aFileDates : TComboBox; aTVFileDates : THTMLTreeview);
    procedure HTMLReportNullFiles(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aSGNullFiles, aSGNullFolders : TAdvStringGrid);

    procedure HTMLReportNameLength(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);
  public
    procedure GenerateHTMLReport(aDataIndex : integer; Options : THTMLReportOptions; aCaption : string);
    procedure GenerateHTMLFileReport(aDataIndex : integer; aReportOutput : TStringList; aTitle, aFileName : string);
    procedure GenerateHTMLCompareReport(Options : THTMLCompareOptions;
      aSelectedPath, aCompareText, aLeftCaption, aRightCaption : string;
      aQuickCompareA, aQuickCompareB : THashedStringList;
      asgFHCompareLeft, asgFHCompareRight : TAdvStringGrid);

    procedure SetGrids(aDataIndex : integer;
                       atvFileDates : THTMLTreeView;
                       asgNullFiles, asgNullFolders, asgTop50Big, asgTop50Small, asgTop101BigDate, asgTop101SmallDate : TAdvStringGrid;
                       acbFileDates, acbTop101Dates : TComboBox);

    function  BuildHTMLReportOptionsFromFile(const fn : string): THTMLReportOptions;

    property  Chart1                   : TChart            read FvtcHTML            write FvtcHTML;
    property  Chart2                   : TChart            read FvtcHTML2           write FvtcHTML2;

    property  OnJustInTime              : TJustInTime              read FJustInTime              write FJustInTime;
    property  OnBuildInformationDisplay : TBuildInformationDisplay read FBuildInformationDisplay write FBuildInformationDisplay;
    property  OnSetStatusBarText        : TSetStatusBarText        read FSetStatusBarText        write FSetStatusBarText;
  end;


var
  GReportHTML : THTMLReport;


implementation


const
  HTMLHeader            = 1;
  HTMLSimpleSummary     = 2;
  HTMLFileAttributes    = 3;
  HTMLCategories        = 4;
  HTMLFolders           = 5;
  HTMLMagnitude         = 6;
  HTMLFileExtensions    = 7;
  HTMLNullfiles         = 8;
  HTMLFileDatesC        = 9;
  HTMLFileDatesA        = 10;
  HTMLFileDatesM        = 11;
  HTMLUsers             = 12;
  HTMLTop101Largest     = 13;
  HTMLTop101Smallest    = 14;
  HTMLTop101Newest      = 15;
  HTMLTop101Oldest      = 16;

  CNullFiles            = 1;
  CNullFolders          = 2;
  CTop50Big             = 3;
  CTop50Small           = 4;
  CTop101BigDate        = 5;
  CTop101SmallDate      = 6;

  CFileDates            = 1;
  CTop101Dates          = 2;


procedure THTMLReport.SetGrids(aDataIndex: Integer;
                               atvFileDates: THTMLTreeview;
                               asgNullFiles, asgNullFolders, asgTop50Big, asgTop50Small, asgTop101BigDate, asgTop101SmallDate: TAdvStringGrid;
                               acbFileDates, acbTop101Dates: TComboBox);
begin
  FHTMLTreeViews[aDataIndex]                    := atvFileDates;

  FAdvStringGrids[aDataIndex, CNullFiles]       := asgNullFiles;
  FAdvStringGrids[aDataIndex, CNullFolders]     := asgNullFolders;
  FAdvStringGrids[aDataIndex, CTop50Big]        := asgTop50Big;
  FAdvStringGrids[aDataIndex, CTop50Small]      := asgTop50Small;
  FAdvStringGrids[aDataIndex, CTop101BigDate]   := asgTop101BigDate;
  FAdvStringGrids[aDataIndex, CTop101SmallDate] := asgTop101SmallDate;

  FComboBoxes[aDataIndex, CFileDates]           := acbFileDates;
  FComboBoxes[aDataIndex, CTop101Dates]         := acbTop101Dates;
end;


procedure THTMLReport.GenerateHTMLReport(aDataIndex : integer; Options : THTMLReportOptions; aCaption : string);
var
  wp : TextFile;
  t, colour : integer;
  MenuString, mrrandom, s, lNameLength : String;
  IncludeImages : boolean;

 procedure CreateMainGraph(datarange: integer);
  var
   t : integer;

  begin
   FvtcHTML.SeriesList.Items[0].Clear;
   FvtcHTML.Width                 := ReportSizes[Options.LayoutSize, rsChartCM];
   FvtcHTML.Height                := 220;
   FvtcHTML.Color                 := Options.HTMLColours.Colour[10];
   FvtcHTML.Legend.TextStyle      := ltsPlain;
   FvtcHTML.Title.Text.Strings[0] := TXFormatting.Privacy(GScanDetails[aDataIndex].ScanPath);

   for t := 1 to __FileCategoriesCount do begin
     if GScanDetails[aDataIndex].ExtensionSpread[t, datarange] <> 0 then begin
       FvtcHTML.SeriesList.Items[0].Add(GScanDetails[aDataIndex].ExtensionSpread[t, datarange], TypeDescriptions[t], GSystemGlobal.FileCategoryColors[t]);
     end;
   end;

   TChartUtility.SaveChartToPNG(FvtcHTML, ExtractFilePath(Options.FileName) + 'data\cm' + IntToStr(datarange) + mrrandom + '.png');
 end;

 procedure CreateDriveDetailsGraph;
  var
   free, used : integer;

  begin
   FvtcHTML.SeriesList.Items[0].Clear;
   FvtcHTML.Width                 := ReportSizes[Options.LayoutSize, rsChartDD];
   FvtcHTML.Height                := 200;
   FvtcHTML.Color                 := Options.HTMLColours.Colour[10];
   FvtcHTML.Legend.Visible        := False;
   FvtcHTML.Legend.TextStyle      := ltsPlain;
   FvtcHTML.Title.Text.Strings[0] := XText[rsDriveDetailsFor] + ' "' + TXFormatting.Privacy(GScanDetails[aDataIndex].ScanPath) + '"';

   if GSystemGlobal.drivespacemax > 0 then begin
     free := Round((GSystemGlobal.drivespacefree / GSystemGlobal.drivespacemax) * 100);
     used := 100 - free;
   end
   else begin
     free := 0;
     used := 100;
   end;

   FvtcHTML.SeriesList.Items[0].Add(free, XText[rsDriveFree], $43ff6B);
   FvtcHTML.SeriesList.Items[0].Add(used, XText[rsDriveUsed], $435EFF);

   TChartUtility.SaveChartToPNG(FvtcHTML, ExtractFilePath(Options.FileName) + 'data\dd' + mrrandom + '.png');

   FvtcHTML.Legend.Visible := True;
 end;


 procedure CreateNameLengthGraph(datarange: integer);
 var
   t : integer;

 begin
   FvtcHTML.SeriesList.Items[0].Clear;
   FvtcHTML.Width                 := ReportSizes[Options.LayoutSize, rsChartCM];
   FvtcHTML.Height                := 220;
   FvtcHTML.Color                 := Options.HTMLColours.Colour[10];
   FvtcHTML.Legend.TextStyle      := ltsPlain;
   if (datarange = 1) then
     FvtcHTML.Title.Text.Strings[0] := XText[rsLength] + ' (' + XText[rsQuantity] + ')'
   else
     FvtcHTML.Title.Text.Strings[0] := XText[rsLength] + ' (' + XText[rsSize] + ')';

   for t := 0 to 279 do begin
     if t = 279 then
       lNameLength := '>=280'
     else
       lNameLength := IntToStr(t + 1);

     case datarange of
       1 : if GScanDetails[aDataIndex].NameLengthCount[t] <> 0 then begin
             FvtcHTML.SeriesList.Items[0].Add(GScanDetails[aDataIndex].NameLengthCount[t], lNameLength, spectrumcolours[t mod spectrummod]);
           end;
       2 : if GScanDetails[aDataIndex].NameLengthSize[t] <> 0 then begin
             FvtcHTML.SeriesList.Items[0].Add(GScanDetails[aDataIndex].NameLengthSize[t], lNameLength, spectrumcolours[t mod spectrummod]);
           end;
     end;
   end;

   TChartUtility.SaveChartToPNG(FvtcHTML, ExtractFilePath(Options.FileName) + 'data\nl' + IntToStr(datarange) + mrrandom + '.png');
 end;


 procedure CreateDirListGraph(datarange : integer);
  var
   t : integer;

  begin
   FvtcHTML2.Width  := ReportSizes[Options.LayoutSize, rsChartCD];
   FvtcHTML2.Height := 400;
   FvtcHTML2.Color  := Options.HTMLColours.Colour[10];

   if datarange = 1 then
     FvtcHTML2.LeftAxis.Title.Caption := XText[rsBytes]
   else
     FvtcHTML2.LeftAxis.Title.Caption := XText[rsQuantity];

   //----------------------------------------------------------------------------
   //-- build graph -------------------------------------------------------------
   //----------------------------------------------------------------------------
   FvtcHTML2.SeriesList.Items[0].Clear;
   FvtcHTML2.Legend.TextStyle      := ltsPlain;
   FvtcHTML2.Title.Text.Strings[0] := TXFormatting.Privacy(GScanDetails[aDataIndex].ScanPath);

   for t := 0 to GScanDetails[aDataIndex].RootFolders.Count - 1 do begin
     if GScanDetails[aDataIndex].RootFolders[t].Data[datarange] <> 0 then begin
       if Options.HTMLColours.MonoBarGraph then
         colour := Options.HTMLColours.Colour[5]
       else
         colour := spectrumcolours[t mod spectrummod];

       FvtcHTML2.SeriesList.Items[0].Add(GScanDetails[aDataIndex].RootFolders[t].Data[datarange], TXFormatting.Privacy(GScanDetails[aDataIndex].RootFolders[t].Name), colour);
     end;
   end;

   TChartUtility.SaveChartToPNG(FvtcHTML2, ExtractFilePath(Options.FileName) + 'data\cd' + IntToStr(datarange) + mrrandom + '.png');
 end;


 procedure CreateMagnitudeGraph(datarange : integer);
  var
   t, lCategory : integer;

  begin
   FvtcHTML2.Width  := ReportSizes[Options.LayoutSize, rsChartXM];
   FvtcHTML2.Height := 220;
   FvtcHTML2.Color  := Options.HTMLColours.Colour[10];

   for lCategory := 0 to __FileCategoriesCount do begin

     if (lCategory = 0) or (GScanDetails[aDataIndex].Magnitude.HasData(lCategory)) then begin
       //-- build graph -------------------------------------------------------------
       FvtcHTML2.SeriesList.Items[0].Clear;
       FvtcHTML2.Legend.TextStyle      := ltsPlain;
       FvtcHTML2.Title.Text.Strings[0] := GScanDetails[aDataIndex].ScanPath;

       if datarange = 1 then
        FvtcHTML2.LeftAxis.Title.Caption := '%'
      else
        FvtcHTML2.LeftAxis.Title.Caption := XText[rsQuantity];

       for t := 0 to __MagnitudesCount do begin
         if GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, datarange] <> 0 then begin
           FvtcHTML2.SeriesList.Items[0].Add(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, datarange], magnilabels2[t], magnicolors[t]);
         end;
       end;

       TChartUtility.SaveChartToPNG(FvtcHTML2, ExtractFilePath(Options.FileName) + 'data\xm' + IntToStr(datarange) + IntToStr(lCategory) + '_' + mrrandom + '.png');
     end;
   end;
 end;


 procedure CreateFileDatesGraph;
  var
   t,x,i : integer;
   dd : string;

  begin
   // ==========================================================================

   if FHTMLTreeViews[aDataIndex] <> Nil then begin
     FvtcHTML2.SeriesList.Items[0].Clear;
     FvtcHTML2.Width  := ReportSizes[Options.LayoutSize, rsChartFD];
     FvtcHTML2.Height := 220;
     FvtcHTML2.Color  := Options.HTMLColours.Colour[10];

     FvtcHTML2.Legend.TextStyle       := ltsPlain;
     FvtcHTML2.Title.Text.Strings[0]  := '';
     FvtcHTML2.LeftAxis.Title.Caption := XText[rsQty];

     i := 0;
     for t := 0 to FHTMLTreeViews[aDataIndex].Items.Count - 1 do begin
       if FHTMLTreeViews[aDataIndex].Items[t].Parent = Nil then begin
         x  := Pos(':', FHTMLTreeViews[aDataIndex].Items[t].Text) + 2;
         dd := '';

         while FHTMLTreeViews[aDataIndex].Items[t].Text[x] <> ' ' do begin
           dd := dd + FHTMLTreeViews[aDataIndex].Items[t].Text[x];
           inc(x);
         end;

         FvtcHTML2.SeriesList.Items[0].Add(StrToInt(dd), Copy(FHTMLTreeViews[aDataIndex].Items[t].Text, 4, 4), spectrumcolours[i mod spectrummod]);

         inc(i);
       end;
     end;

     TChartUtility.SaveChartToPNG(FvtcHTML2, ExtractFilePath(Options.FileName) + 'data\fd' + mrrandom + '.png');
   end;
 end;


 procedure BuildMenuList;
  var
   t : integer;
   s : string;

  begin
   s := '';
   MenuString := '|| ';

   for t := 1 to length(Options.Layout) do begin
     if Options.Layout[t] = ':' then begin
       case StrToIntDef(s, 999) of
         HTMLFileAttributes : MenuString := MenuString + '<a href="#op2">'   + XText[rsFileAttributes] + '</a> || ';
         HTMLCategories     : MenuString := MenuString + '<a href="#op3">'   + XText[rsCombineDrivesFolders] + '</a> || ';
         HTMLFolders        : MenuString := MenuString + '<a href="#op4">'   + XText[rsFolders] + '</a> || ';
         HTMLMagnitude      : MenuString := MenuString + '<a href="#op5">'   + XText[rsMagnitude] + '</a> || ';
         HTMLFileExtensions : MenuString := MenuString + '<a href="#op6">'   + XText[rsFileExtensions] + '</a> || ';
         HTMLNullfiles      : MenuString := MenuString + '<a href="#op7">'   + XText[rsNullFiles] + '</a> / <a href="#op7a">' + XText[rsEmptyFolders] + '</a> || ';
         HTMLFileDatesC     : MenuString := MenuString + '<a href="#op8">'   + XText[rsFileDates] + '</a> || ';
         HTMLUsers          : MenuString := MenuString + '<a href="#op10">'  + XText[rsUsers] + '</a> || ';
         HTMLTop101Largest  : MenuString := MenuString + '<a href="#op9">'   + XText[rsTop101] + ' (' + XText[rsLargest]  + ')</a> || ';
         HTMLTop101Smallest : MenuString := MenuString + '<a href="#op14">'  + XText[rsTop101] + ' (' + XText[rsSmallest] + ')</a> || ';
         HTMLTop101Newest   : MenuString := MenuString + '<a href="#op15">'  + XText[rsTop101] + ' (' + XText[rsNewest]   + ')</a> || ';
         HTMLTop101Oldest   : MenuString := MenuString + '<a href="#op16">'  + XText[rsTop101] + ' (' + XText[rsOldest]   + ')</a> || ';

         999                : MenuString := MenuString + XText[rsError] + ' || ';
       end;

       s:= '';
     end
     else
       s:= s + Options.Layout[t];
   end;
 end;


 procedure AddHTMLReportItem(sidx : integer);
  begin
    case sidx of
       CHTMLHeader     : HTMLReportHeader(aDataIndex, wp, Options, aCaption, MenuString);
       CHTMLQuick      : HTMLReportQuickInfo(aDataIndex, wp, Options, IncludeImages, mrrandom);
       CHTMLFAT        : HTMLReportFileAttributesTable(aDataIndex, wp, Options);
       CHTMLCategory   : HTMLReportFileCategory(aDataIndex, wp, Options, IncludeImages, mrrandom);
       CHTMLFolders    : HTMLReportDirectoryList(aDataIndex, FHTMLTreeViews[aDataIndex].Items.Count, wp, Options, IncludeImages, mrrandom);
       CHTMLMagnitude  : HTMLReportMagnitude(aDataIndex, wp, Options, IncludeImages, mrrandom);
       CHTMLExtensions : HTMLReportFileExtensionLists(aDataIndex, wp, Options);
       CHTMLNullFiles  : begin
                           if Assigned(FJustInTime) then
                             FJustInTime(TabIndexNull);

                           HTMLReportNullFiles(aDataIndex, wp, Options, FAdvStringGrids[aDataIndex, CNullFiles], FAdvStringGrids[aDataIndex, CNullFolders]);
                         end;
       CHTMLDatesC,
       CHTMLDatesA,
       CHTMLDatesM     : begin
                           if (aDataIndex = dataLatestScan) or (aDataIndex = dataSearch) then begin
                             case sidx of
                               CHTMLDatesC : FComboBoxes[aDataIndex, CFileDates].ItemIndex := 0;
                               CHTMLDatesA : FComboBoxes[aDataIndex, CFileDates].ItemIndex := 1;
                               CHTMLDatesM : FComboBoxes[aDataIndex, CFileDates].ItemIndex := 2;
                             end;

                             if Assigned(FBuildInformationDisplay) then
                               FBuildInformationDisplay(0);
                           end;

                           // we have to generate the File Dates graph ONLY after the display has been
                           // created
                           CreateFileDatesGraph;

                           HTMLReportFileDates(aDataIndex, wp, Options, IncludeImages, mrrandom, FComboBoxes[aDataIndex, CFileDates], FHTMLTreeViews[aDataIndex]);
                         end;
      CHTMLUsers       : HTMLReportUsers(aDataIndex, wp, Options);
      CHTMLLargest     : begin
                           if Assigned(FJustInTime) then
                             FJustInTime(TabIndexTop50);

                           HTMLReportTop50Largest(aDataIndex, wp, Options, FAdvStringGrids[aDataIndex, CTop50Big]);
                         end;
      CHTMLSmallest    : begin
                           if Assigned(FJustInTime) then
                             FJustInTime(TabIndexTop50);

                           HTMLReportTop50Smallest(aDataIndex, wp, Options, FAdvStringGrids[aDataIndex, CTop50Small]);
                         end;
      CHTMLNewest      : begin
                           if Assigned(FJustInTime) then
                             FJustInTime(TabIndexTop50);

                           HTMLReportTop101Newest(aDataIndex, wp, Options, FAdvStringGrids[aDataIndex, CTop101BigDate], FComboBoxes[aDataIndex, CTop101Dates]);
                         end;
      CHTMLOldest      : begin
                           if Assigned(FJustInTime) then
                             FJustInTime(TabIndexTop50);

                           HTMLReportTop101Oldest(aDataIndex, wp, Options, FAdvStringGrids[aDataIndex, CTop101SmallDate], FComboBoxes[aDataIndex, CTop101Dates]);
                         end;
      CHTMLNameLength  : begin
                           if Assigned(FJustInTime) then
                             FJustInTime(TabIndexNameLength);

                           CreateNameLengthGraph(1);
                           CreateNameLengthGraph(2);

                           HTMLReportNameLength(aDataIndex, wp, Options, IncludeImages, mrrandom);
                         end;
    end;
 end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'GenerateHTMLReport :: invalid dataindex :: ' +inttostr(aDataIndex));

  if Not(DirectoryExists(ExtractFilePath(Options.FileName) + 'data')) then
    CreateDir(ExtractFilePath(Options.FileName) + 'data');

  if Options.HTMLUnits = 0 then
    Options.HTMLAlign := 'center'
  else
    Options.HTMLAlign := 'right';

  //----------------------------------------------------------------------------
  //before we create the page, we need to create the graphs.....----------------
  //----------------------------------------------------------------------------
  mrrandom := IntToHex(RandomRange(0, 99999999), 8);

  BuildMenuList;

  IncludeImages := TUtility.FindReportItem(Options.Layout, 0);

  if IncludeImages then begin
    FvtcHTML.Color  := Options.HTMLColours.Colour[9];
    FvtcHTML2.Color := Options.HTMLColours.Colour[9];

    CreateMainGraph(1);
    CreateMainGraph(2);
    CreateMagnitudeGraph(0);
    CreateMagnitudeGraph(1);
    CreateDirListGraph(0);
    CreateDirListGraph(1);

    if (aDataIndex = dataLatestScan) then
      CreateDriveDetailsGraph;
  end;

  //----------------------------------------------------------------------------
  //--Lets write the file-------------------------------------------------------
  //----------------------------------------------------------------------------

  AssignFile(wp, Options.FileName);

  {$I-}
  Rewrite(wp);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsErrorSaving] + ': ' + XText[rsHTMLReport], XText[rsErrorSaving] + ' "' + Options.FileName + '".', XDialogTypeWarning);
  end
  else begin
    Writeln(wp, '<html><head><title>xinorbis analysis "' + GScanDetails[aDataIndex].ScanPath + '"</title>');
    Writeln(wp, '<meta name="generator" content="xinorbis, (c) Paul Alan Freshney 2002-' + TUtility.GetCurrentYear + ', xinorbis@maximumoctopus.com">');
    Writeln(wp, '<meta name="debug" content="' + IntToStr(Options.LayoutSize) + '">');
    Writeln(wp, '<meta name="debug" content="randomnumberID ' + mrrandom + '">');
    Writeln(wp, '<style type="text/css">');
    Writeln(wp, '<!--');
    Writeln(wp, 'A:link {color:#' + TConvert.WebColor(Options.HTMLColours.Colour[1]) + '; text-decoration: none;}');
    Writeln(wp, 'A:visited {color:#' + TConvert.WebColor(Options.HTMLColours.Colour[1]) + '; text-decoration: none;}');
    Writeln(wp, 'A:hover {color:#' + TConvert.WebColor(Options.HTMLColours.Colour[2]) + '; text-decoration: underline;}');
    Writeln(wp, 'A:active {color:#' + TConvert.WebColor(Options.HTMLColours.Colour[1]) + '; text-decoration: none;}');
    Writeln(wp, '.C4G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[4]) + ';}');
    Writeln(wp, '.C4CB {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-aligh:center; font-weight: bold; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[4]) + ';}');
    Writeln(wp, '.C4C {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[4]) + ';}');
    Writeln(wp, '.C4L {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:left; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[4]) + ';}');
    Writeln(wp, '.C4R {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:right; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[4]) + ';}');
    Writeln(wp, '.C7G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[7]) + ';}');
    Writeln(wp, '.C7CB {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; font-weight: bold; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[7]) + ';}');
    Writeln(wp, '.C7C {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[7]) + ';}');
    Writeln(wp, '.XCB {text-align:center; font-weight: bold;}');
    Writeln(wp, '-->');
    Writeln(wp, '</style></head>');
    Writeln(wp, '<body leftmargin="5" bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[3]) + '" text="#' + TConvert.WebColor(Options.HTMLColours.Colour[8]) + '" topmargin="5">');

    s := '';

    for t := 1 to length(Options.Layout) do begin
      if Options.Layout[t] = ':' then begin
        if s <> '' then begin
          AddHTMLReportItem(StrToIntDef(s, -1));
        end;

        s := '';
      end
      else
        s := s + Options.Layout[t];
    end;

    // footer table. always gets added
    Writeln(wp, '<table align="center" width="' + IntToStr(ReportSizes[Options.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
    Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[6]) + '">');
    Writeln(wp,   '<td align="center" class="C7G">');
    Writeln(wp,     '<a href="mailto:xinorbis@maximumoctopus.com">xinorbis@maximumoctopus.com</a> / <a href="http://www.xinorbis.com" target="_blank">www.xinorbis.com</a></td>');
    Writeln(wp, '</tr>');
    Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[6]) + '" class="C7G">');
    Writeln(wp,   '<td align="center">Xinorbis (c) Paul Alan Freshney 2002-' + TUtility.GetCurrentYear + '</td>');
    Writeln(wp, '</tr>');
    Writeln(wp, '</table></body></html>');

    CloseFile(wp);

    GReportUtility.SetLastReport(aDataIndex, Options.Filename, GScanDetails[aDataIndex].ScanPath, ReportHTML, LayoutUnknown);

    if Assigned(FSetStatusBarText) then
      FSetStatusBarText(XText[rsHTMLReportSavedAs] + ': ' + Options.FileName);
  end;
  {$I+}
end;


procedure THTMLReport.GenerateHTMLCompareReport(Options : THTMLCompareOptions;
                           aSelectedPath, aCompareText, aLeftCaption, aRightCaption : string;
                           aQuickCompareA, aQuickCompareB : THashedStringList;
                           asgFHCompareLeft, asgFHCompareRight : TAdvStringGrid);
var
  wp : TextFile;
  t : integer;
  mrrandom, alignmode, s : String;
  menulist : TStringList;

 procedure InsertSpacingTable;
 begin
   Writeln(wp, '<table align="center" width="' + IntToStr(ReportSizes[Options.LayoutSize, rsTableWidth]) + '" border="0"><tr><td>&nbsp;</td></tr></table>');
 end;

 procedure BuildMenuList;
 var
   t : integer;
   s : string;

 begin
   menulist := TStringList.Create;

   s := '';

   for t := 1 to length(Options.Layout) do begin
    if Options.Layout[t] = ':' then begin
      case StrToInt(s) of
         3 : begin
               menulist.Add('&nbsp;&nbsp;- <a href="#op2">' + XText[rsDifferenceLeft] + '</a>');
               menulist.Add('&nbsp;&nbsp;- <a href="#op3">' + XText[rsDifferenceRight] + '</a>');
             end;
         4 : menulist.Add('&nbsp;&nbsp;- <a href="#op4">' + XText[rsSizeChanges] + '</a>');
      end;

      s := '';
    end
    else
      s := s + Options.Layout[t];
   end;

   if menulist.Count <> 4 then begin
     for t := menulist.Count + 1 to 4 do
       menulist.Add('');
   end;
 end;


 procedure AddHTMLReportItem(sidx : integer);
   var
    t,i : integer;

   begin
    case sidx of
       1 : begin
             //----------------------------------------------------------------------------
             //--header table---------------------------------------------------------------
             //----------------------------------------------------------------------------
             Writeln(wp, '<table align="center" width="' + IntToStr(ReportSizes[Options.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1" bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[10]) + '">');
             Writeln(wp, '<tr class="C4G">');
             Writeln(wp,   '<td><div align="center"><b>xinorbis 8</b> comparison report for <b><a href="' + TXFormatting.Privacy(WebFileLink(aSelectedPath)) + '">' + TXFormatting.Privacy(aSelectedPath) + '</a></b></div></td>');
             Writeln(wp, '</tr>');
             Writeln(wp, '<tr class="C4G"><td><div align="center">Comparison at <b>' + aLeftCaption + '</b> and <b>' + aRightCaption + '</b>.</div></td></tr>');
             Writeln(wp, '<tr class="C4G"><td><div align="center">Search function <b>' + aCompareText + '</b>.</div></td></tr>');
             Writeln(wp, '<tr class="C4G"><td><div align="center">Produced at <b>' + TUtility.GetTime(GETTIMEFORMAT_DISPLAY) + '</b> on <b>' + TUtility.GetDate(GETTIMEFORMAT_DISPLAY) + '</b></div></td></tr>');
             Writeln(wp, '</table>');

             InsertSpacingTable;
           end;
       2 : begin
             //-----------------------------------------------------------------
             //--quick info table-----------------------------------------------
             //-----------------------------------------------------------------
             Writeln(wp, '<table align="center" width="' + IntToStr(ReportSizes[Options.LayoutSize, rsTableWidth]) + '" height="100" border="0" cellspacing="1" cellpadding="1" bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[10]) + '">');
             Writeln(wp, '<tr><td width="100%" bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[6]) + '" class="C7G"><strong>' + XText[rsSummary] + '</strong></td></tr>');
             Writeln(wp, '<tr>');
             Writeln(wp,   '<td>');
             Writeln(wp,   '<table width="100%" border="0" cellpadding="0" cellspacing="0">');
             Writeln(wp, '<tr>');
             Writeln(wp,   '<td width="191" class="C4G">' + menulist.Strings[0] + '</td>');
             Writeln(wp,   '<td width="275" class="C4G">&nbsp;</td>');
             Writeln(wp,   '<td width="147" class="C4G"><div align="right"><b>' + aLeftCaption + '</b></div></td>');
             Writeln(wp,   '<td width="147" class="C4G"><div align="right"><b>' + aRightCaption + '</b></div></td>');
             Writeln(wp,   '<td width="10">&nbsp;</td>');
             Writeln(wp, '</tr>');
             Writeln(wp, '<tr>');
             Writeln(wp,   '<td width="191" class="C4G">' + menulist.Strings[1] + '</td>');
             Writeln(wp,   '<td width="275" class="C4G"><div align="right">' + XText[rsNumberOfFiles] + '</div></td>');
             Writeln(wp,   '<td width="147" class="C4G"><div align="right">' + IntToStr(CompareData[XLeftSide].Data[XFileCount]) + '</div></td>');
             Writeln(wp,   '<td width="147" class="C4G"><div align="right">' + IntToStr(CompareData[XRightSide].Data[XFileCount]) + '</div></td>');
             Writeln(wp,   '<td width="10">&nbsp;</td>');
             Writeln(wp, '</tr>');
             Writeln(wp, '<tr>');
             Writeln(wp, '<td width="191" class="C4G">' + menulist.Strings[2] + '</td>');
             Writeln(wp,   '<td width="275" class="C4G"><div align="right">' + XText[rsSizeOfFiles] + '</div></td>');
             Writeln(wp,   '<td width="147" class="C4G"><div align="right">' + TConvert.ConvertToUsefulUnit(CompareData[XLeftSide].Data[XFileSize]) + '</div></td>');
             Writeln(wp,   '<td width="147" class="C4G"><div align="right">' + TConvert.ConvertToUsefulUnit(CompareData[XRightSide].Data[XFileSize]) + '</div></td>');
             Writeln(wp,   '<td width="10">&nbsp;</td>');
             Writeln(wp, '</tr>');
             Writeln(wp, '<tr>');
             Writeln(wp,   '<td width="191" class="C4G">' +menulist.Strings[3] + '</td>');
             Writeln(wp,   '<td width="275" class="C4G"><div align="right">' + XText[rsNumberOfFolders] + '</div></td>');
             Writeln(wp,   '<td width="147" class="C4G"><div align="right">' + IntToStr(CompareData[XLeftSide].Data[XFolderCount]) + '</div></td>');
             Writeln(wp,   '<td width="147" class="C4G"><div align="right">' + IntToStr(CompareData[XRightSide].Data[XFolderCount]) + '</div></td>');
             Writeln(wp,   '<td width="10">&nbsp;</td>');
             Writeln(wp, '</tr>');
             Writeln(wp, '<tr>');
             Writeln(wp,   '<td width="191" class="C4G">&nbsp;</td>');
             Writeln(wp,   '<td width="275" class="C4G">&nbsp;</td>');
             Writeln(wp,   '<td width="147" class="C4G">&nbsp;</td>');
             Writeln(wp,   '<td width="147" class="C4G">&nbsp;</td>');
             Writeln(wp,   '<td width="10">&nbsp;</td>');
             Writeln(wp, '</tr>');
             Writeln(wp, '</table>');
             Writeln(wp, '</td>');
             Writeln(wp, '</tr>');
             Writeln(wp, '</table>');

             InsertSpacingTable;
           end;
       3 : begin
             //-----------------------------------------------------------------
             //new files on left -----------------------------------------------
             //-----------------------------------------------------------------
             Writeln(wp, '<table align="center" width="' + IntToStr(ReportSizes[Options.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
             Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[6]) + '">');
             Writeln(wp,   '<td colspan="2" width="96" height="13" class="C7G"><a name="op2" /><b>' + XText[rsFilesLeftNotRight] + '</b></td>');
             Writeln(wp, '</tr>');

             for t := 0 to aQuickCompareA.Count - 1 do begin
               if aQuickCompareB.IndexOf(aQuickCompareA.Strings[t]) = -1 then begin
                 Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[10]) + '">');
                 Writeln(wp,   '<td width="706" height="13" class="C4G">' + TXFormatting.Privacy(aQuickCompareA.Strings[t]) + '</td>');
                 Writeln(wp,   '<td width="64" height="13" class="C4G"><div align="center">' + TXFormatting.Privacy(asgFHCompareLeft.Cells[1, 1 + t]) + '</div></td>');
                 Writeln(wp, '</tr>');
               end;
             end;

             Writeln(wp, '</table>');

             InsertSpacingTable;

             //-----------------------------------------------------------------
             //new files on right ----------------------------------------------
             //-----------------------------------------------------------------
             Writeln(wp, '<table align="center" width="' + IntToStr(ReportSizes[Options.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
             Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[6]) + '">');
             Writeln(wp,   '<td colspan="2" width="636" height="13" class="C7G"><a name="op3" /><b>' + XText[rsFilesRightNotLeft] + '</b></td>');
             Writeln(wp, '</tr>');

             for t := 0 to aQuickCompareB.Count - 1 do begin
               if aQuickCompareA.IndexOf(aQuickCompareB.Strings[t]) = -1 then begin
                 Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[10]) + '">');
                 Writeln(wp,   '<td width="706" height="13" class="C4G">' + TXFormatting.Privacy(aQuickCompareB.Strings[t]) + '</td>');
                 Writeln(wp,   '<td width="64" height="13" class="C4G"><div align="center">' + asgFHCompareRight.Cells[1, 1 + t] + '</div></td>');
                 Writeln(wp, '</tr>');
               end;
             end;

             Writeln(wp, '</table>');

             InsertSpacingTable;
           end;
       4 : begin
             //-----------------------------------------------------------------
             //file size change ------------------------------------------------
             //-----------------------------------------------------------------
             Writeln(wp, '<table align="center" width="' + IntToStr(ReportSizes[Options.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
             Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[6]) + '">');
             Writeln(wp,   '<td width="570" height="13" class="C7G"><a name="op4" /><b>' + XText[rsFilesSizeChanged] + '</b></td>');
             Writeln(wp,   '<td width="100" height="13" class="C7G"><div align="center"><b>' + aLeftCaption + '</b></div></td>');
             Writeln(wp,   '<td width="100" height="13" class="C7G"><div align="center"><b>' + aRightCaption + '</b></div></td>');
             Writeln(wp, '</tr>');

             for t := 0 to aQuickCompareA.Count - 1 do begin
               i := aQuickCompareB.IndexOf(aQuickCompareA.Strings[t]);

               if i<>-1 then begin
                 Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[10]) + '">');
                 Writeln(wp,   '<td width="570" height="13" class="C4G">' + TXFormatting.Privacy(aQuickCompareA.Strings[t]) + '</td>');
                 Writeln(wp,   '<td width="100" height="13" class="C4G"><div align="center">' + asgFHCompareRight.Cells[1, 1 + t] + '</div></td>');
                 Writeln(wp,   '<td width="100" height="13" class="C4G"><div align="center">' + asgFHCompareLeft.Cells[1, 1 + i] + '</div></td>');
                 Writeln(wp, '</tr>');
               end;
             end;

             Writeln(wp, '</table>');

             InsertSpacingTable;
           end;
    end;
 end;

 begin
  if Not(DirectoryExists(ExtractFilePath(Options.FileName) + 'data')) then
    CreateDir(ExtractFilePath(Options.FileName) + 'data');

  if Options.HTMLUnits = 0 then
    alignmode := 'center'
  else
    alignmode := 'right';

  aQuickCompareA.Clear;
  aQuickCompareB.Clear;

  for t := 1 to asgFHCompareLeft.RowCount - 1 do
    aQuickCompareA.Add(asgFHCompareLeft.Cells[0, t]);

  for t := 1 to asgFHCompareRight.RowCount - 1 do
    aQuickCompareB.Add(asgFHCompareRight.Cells[0, t]);

  //----------------------------------------------------------------------------
  //before we create the page, we need to create the graphs.....----------------
  //----------------------------------------------------------------------------

  mrrandom := IntToHex(RandomRange(0, 99999999), 8);

  BuildMenuList;

  //----------------------------------------------------------------------------
  //--Lets write the file-------------------------------------------------------
  //----------------------------------------------------------------------------

  AssignFile(wp, Options.FileName);

  {$I-}
  Rewrite(wp);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsErrorSaving] + ': HTML compare report',
                XText[rsErrorSaving] + ' "' + Options.FileName + '".',
                XDialogTypeWarning);
  end
  else begin
    Writeln(wp, '<html><head>');
    Writeln(wp, '<title>xinorbis compare: {' + TXFormatting.Privacy(aSelectedPath) + '}</title>');
    Writeln(wp, '<meta name="generator" content="xinorbis, (c) Paul Alan Freshney 2002-' + TUtility.GetCurrentYear + ', xinorbis@maximumoctopus.com">');
    Writeln(wp, '<style type="text/css">');
    Writeln(wp, '<!--');
    Writeln(wp, 'A:link {color:#' + TConvert.WebColor(Options.HTMLColours.Colour[1]) + '; text-decoration: none;}');
    Writeln(wp, 'A:visited {color:#' + TConvert.WebColor(Options.HTMLColours.Colour[1]) + '; text-decoration: none;}');
    Writeln(wp, 'A:hover {color:#' + TConvert.WebColor(Options.HTMLColours.Colour[2]) + '; text-decoration: underline;}');
    Writeln(wp, 'A:active {color:#' + TConvert.WebColor(Options.HTMLColours.Colour[1]) + '; text-decoration: none;}');
    Writeln(wp, '.C4G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[4]) + ';}');
    Writeln(wp, '.C7G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#' + TConvert.WebColor(Options.HTMLColours.Colour[7]) + ';}');
    Writeln(wp, '-->');
    Writeln(wp, '</style></head>');
    Writeln(wp, '<body leftmargin="5" bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[3]) + '" text="#' + TConvert.WebColor(Options.HTMLColours.Colour[8]) + '" topmargin="5">');

    s := '';

    for t := 1 to length(Options.Layout) do begin
      if Options.Layout[t] = ':' then begin
        AddHTMLReportItem(StrToIntDef(s, -1));

        s := '';
      end
      else
        s := s + Options.Layout[t];
    end;

    // footer table. always gets added
    Writeln(wp, '<table align="center" width="' + IntToStr(ReportSizes[Options.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
    Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[6]) + '">');
    Writeln(wp,   '<td align="center" class="C7G">');
    Writeln(wp,   '<a href="mailto:xinorbis@maximumoctopus.com">xinorbis@maximumoctopus.com</a> / <a href="http://www.xinorbis.com" target="_blank">www.xinorbis.com</a></td>');
    Writeln(wp, '</tr>');
    Writeln(wp, '<tr bgcolor="#' + TConvert.WebColor(Options.HTMLColours.Colour[6]) + '" class="C7G">');
    Writeln(wp,   '<td align="center">(c) Paul Alan Freshney 2002-' + TUtility.GetCurrentYear + '</td>');
    Writeln(wp, '</tr>');
    Writeln(wp, '</table></body></html>');

    CloseFile(wp);

    GReportUtility.SetLastReport(dataFolderHistory, Options.Filename, GScanDetails[dataFolderHistory].ScanPath, ReportHTML, LayoutUnknown);

    if Assigned(FSetStatusBarText) then
      FSetStatusBarText(XText[rsHTMLReportSavedAs] + ': '  + Options.FileName);
  end;
  {$I+}

  menulist.Free;
end;


// =============================================================================


procedure THTMLReport.InsertSpacingTable(var aTextFile : TextFile);
  begin
   Writeln(aTextFile, '<table align="center" width="770" border="0"><tr><td>&nbsp;</td></tr></table>');
end;


function THTMLReport.WebFileLink(s : string): string;
 var
  t : integer;

 begin
  for t := 1 to length(s) do begin
    if s[t] = ':' then s[t] := '|';
    if s[t] = '\' then s[t] := '/';
  end;

  Result := 'file:///' + s;
end;


procedure THTMLReport.HTMLReportHeader(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; const aFHISelectCaption, aMenuString : string);
var
  tstr : string;
  t : integer;

begin
  //----------------------------------------------------------------------------
  //--header table---------------------------------------------------------------
  //----------------------------------------------------------------------------
  Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">');
  Writeln(aTextFile, '<tr class="C4G">');
  if XSettings.LastScanMultiple then begin
    Writeln(aTextFile,   '<td><a name="top"><div align="center"><b>xinorbis ' + x8Title + '</b> ' + XText[rsReportFor] + ' ...</div></td></tr>');

    tstr := '';
    for t := 0 to GScanDetails[aDataIndex].MultipleList.Count - 1 do
      tstr := tstr + ' <a href="' + WebFileLink(TXFormatting.Privacy(GScanDetails[aDataIndex].MultipleList.Strings[t])) + '">' + TXFormatting.Privacy(GScanDetails[aDataIndex].MultipleList.Strings[t]) + '</a> *';

    Writeln(aTextFile,   '<tr class="C4C"><td> *' + tstr + '</td></tr>');
  end
  else
    Writeln(aTextFile,   '<td class="C4C"><b>xinorbis 8</b> ' + XText[rsReportFor] +
                         ' <b><a href="' + WebFileLink(TXFormatting.Privacy(GScanDetails[aDATAINDEX].ScanPath)) + '">' + TXFormatting.Privacy(GScanDetails[aDATAINDEX].ScanPath) + '</a></b></td>');

  Writeln(aTextFile, '</tr>');
  Writeln(aTextFile, '<tr class="C4C">');
  Writeln(aTextFile,   '<td>' + XText[rsAnalysedAt] + ' <b>' + TUtility.GetTime(GETTIMEFORMAT_DISPLAY) + '</b>, <b>' + TUtility.GetDate(GETTIMEFORMAT_DISPLAY) + '</b>.</td>');
  Writeln(aTextFile, '</tr>');

  if ((GScanDetails[aDataIndex].ScanSource = ScanSourceFolderHistory)) then begin
    Writeln(aTextFile, '<tr class="C4C">');
    Writeln(aTextFile,   '<td>' + XText[rsFolderHistory] + ' <b>' + GScanDetails[aDataIndex].ScanDateFHStr + '</b>.</td>');
    Writeln(aTextFile, '</tr>');
  end;

  if (aDataIndex = dataSearch) then begin
    Writeln(aTextFile, '<tr class="C4C">');
    Writeln(aTextFile,   '<td>' + XText[rsSearch] + ': <b>' + aOptions.Special + '</b>.</td>');
    Writeln(aTextFile, '</tr>');
  end;

  Writeln(aTextFile, '</tr>');
  Writeln(aTextFile, '</table>');

  InsertSpacingTable(aTextFile);

  //----------------------------------------------------------------------------
  // -- excluded folder list ---------------------------------------------------
  //----------------------------------------------------------------------------
  if GSystemGlobal.ExcludedFolders.Count <> 0 then begin
    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
    Writeln(aTextFile, '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td width="387" height="20"><b>' + XText[rsExcludedFolder] + '</b></td></tr>');

    for t := 0 to GSystemGlobal.ExcludedFolders.Count - 1 do begin
      Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">' +
                           '<td class="C4L"><a href="' + WebFileLink(TXFormatting.Privacy(GSystemGlobal.ExcludedFolders.Strings[t])) + '" target="_blank">' +TXFormatting.Privacy(GSystemGlobal.ExcludedFolders.Strings[t]) + '<a></td>' +
                         '</tr>');
    end;

    Writeln(aTextFile, '</table>');

    InsertSpacingTable(aTextFile);
  end;

  //----------------------------------------------------------------------------
  // -- excluded file list -----------------------------------------------------
  //----------------------------------------------------------------------------
  if GSystemGlobal.ExcludedFiles.Count <> 0 then begin
    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
    Writeln(aTextFile, '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td width="387" height="20"><b>' + XText[rsExcludedFiles] + '</b></td></tr>');

    for t := 0 to GSystemGlobal.ExcludedFiles.Count - 1 do begin
      Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">' +
                           '<td class="C4L"><a href="' + WebFileLink(TXFormatting.Privacy(GSystemGlobal.ExcludedFiles.Strings[t])) + '" target="_blank">' + TXFormatting.Privacy(GSystemGlobal.ExcludedFiles.Strings[t]) + '<a></td>' +
                         '</tr>');
    end;

    Writeln(aTextFile, '</table>');

    InsertSpacingTable(aTextFile);
  end;

  //----------------------------------------------------------------------------
  //-- navigation table---------------------------------------------------------
  //----------------------------------------------------------------------------
  Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">' +
                     '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td class="C7G"><strong>Menu</strong></td></tr>' +
                     '<tr class="C4C"><td>' + aMenuString + '</td></tr></table>');

  InsertSpacingTable(aTextFile);
end;


procedure THTMLReport.HTMLReportFileCategory(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);
 var
  large1, large2, t, rowidx : integer;

 begin
  //-----------------------------------------------------------------
  //file category table----------------------------------------------
  //-----------------------------------------------------------------
  Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                     '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                       '<td width="100" height="13" class="C7G"><a name="op3" /><b>' + XText[rsCategory] + '</b></td>' +
                       '<td width="64" height="13" class="C7CB">' + XText[rsQuantity] + '</td>' +
                       '<td width="64" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                       '<td width="160" height="13">&nbsp;</td>' +
                       '<td width="85" height="13" class="C7CB">' + XText[rsSizeOfFiles] + '</td>' +
                       '<td width="67" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                       '<td width="160" height="20">&nbsp;</td>' +
                     '</tr>');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin
    if GScanDetails[aDATAINDEX].TotalSize <> 0 then begin
      //find largest category %
      large1 := 0;
      large2 := 0;
      for t := 0 to __FileCategoriesCount do begin
        if Round((GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDATAINDEX].TotalSize) * 100) > large2 then large2 := Round((GScanDetails[aDataIndex].ExtensionSpread[t, 2] /GScanDetails[aDATAINDEX].TotalSize) * 100);
        if Round((GScanDetails[aDataIndex].ExtensionSpread[t, 1] / GScanDetails[aDATAINDEX].FileCount) * 100) > large1 then large1 := Round((GScanDetails[aDataIndex].ExtensionSpread[t, 1] /GScanDetails[aDATAINDEX].FileCount) * 100);
      end;
      if large1 <= 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];
      if large2 <= 0 then large2 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

      rowidx := 1;

      //build the file category table
      for t := 1 to __FileCategoriesCount do begin
        if GScanDetails[aDataIndex].ExtensionSpread[t, 1] <> 0 then begin
          // ==================================================================
          if odd(rowidx) then
            Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
          else
            Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

          inc(rowidx);
          // ==================================================================

          Writeln(aTextFile,   '<td width="100" class="C4L">' + TypeDescriptions[t] + '</td>');
          Writeln(aTextFile,   '<td width="64" class="C4C">' + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]) + '</td>');
          Writeln(aTextFile,   '<td width="64" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 1] /GScanDetails[aDATAINDEX].FileCount) + '</td>');
          Writeln(aTextFile,   '<td width="160">' +
                                 '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].ExtensionSpread[t, 1] /GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(GSystemGlobal.FileCategoryColors[t]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                   '<tr><td></td></tr>' +
                                 '</table>' +
                               '</td>');
          Writeln(aTextFile,   '<td width="85" class="C4G"><div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, GScanDetails[aDataIndex].ExtensionSpread[t, 2]) + '</div></td>');
          Writeln(aTextFile,   '<td width="67" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDATAINDEX].TotalSize) + '</td>');
          Writeln(aTextFile,   '<td width="160">' +
                                 '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].ExtensionSpread[t, 2] /GScanDetails[aDATAINDEX].TotalSize) * 100)*(ReportSizes[aOptions.LayoutSize, rsBarGraph] / large2))) + '" border="0" bgcolor="#' + TConvert.WebColor(GSystemGlobal.FileCategoryColors[t]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                   '<tr><td></td></tr>' +
                                 '</table>' +
                               '</td>');
          Writeln(aTextFile, '</tr>');
        end;
      end;

      // ==================================================================
      if odd(rowidx) then
        Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
      else
        Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

      inc(rowidx);
      // ==================================================================
      Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">' +
                           '<td width="100">&nbsp;</td>' +
                           '<td width="64">&nbsp;</td>' +
                           '<td width="64">&nbsp;</td>' +
                           '<td width="160">&nbsp;</td>' +
                           '<td width="85">&nbsp;</td>' +
                           '<td width="67">&nbsp;</td>' +
                           '<td width="160">&nbsp;</td>' +
                         '</tr>');

      // ==================================================================
      if odd(rowidx) then
        Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
      else
        Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

      // ==================================================================
	    Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">');
      Writeln(aTextFile,   '<td width="100" class="C4L">' + XText[rsTemporary] + '</td>');
      Writeln(aTextFile,   '<td width="64" class="C4C">' + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[0, 1]) + '</td>');
      Writeln(aTextFile,   '<td width="64" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[0, 1] / GScanDetails[aDATAINDEX].FileCount) + '</td>');
      Writeln(aTextFile,   '<td width="160">' +
                             '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].ExtensionSpread[0, 1] /GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#000000" height="8" cellpadding="0" cellspacing="0">' +
                               '<tr><td></td></tr>' +
                             '</table>' +
                           '</td>');
      Writeln(aTextFile,   '<td width="85" class="C4G"><div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, GScanDetails[aDataIndex].ExtensionSpread[0, 2]) + '</div></td>');
      Writeln(aTextFile,   '<td width="67" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[0, 2] /GScanDetails[aDATAINDEX].TotalSize) + '</td>');
      Writeln(aTextFile,   '<td width="160">' +
                             '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].ExtensionSpread[0, 2] /GScanDetails[aDATAINDEX].TotalSize) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large2))) + '" border="0" bgcolor="#000000" height="8" cellpadding="0" cellspacing="0">' +
                               '<tr><td></td></tr>' +
                             '</table>' +
                           '</td>');
      Writeln(aTextFile, '</tr>');

      Writeln(aTextFile, '</table>');

      InsertSpacingTable(aTextFile);

      //build the graph table
      if (aIncludeImages) then begin
        Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellspacing="1" cellpadding="1">' +
                           '<tr class="C7CB">' +
                             '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' + XText[rsLargestFiles] + '</td>' +
                             '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' + XText[rsSize] + '</td>' +
                           '</tr>' +
                           '<tr>' +
                             '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><img src="data/cm1' + aMrRandom + '.png' + '"></td>' +
                             '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><img src="data/cm2' + aMrRandom + '.png' + '"></td>' +
                           '</tr>' +
                           '</table>');

        InsertSpacingTable(aTextFile);
      end;
    end;
  end
end;


procedure THTMLReport.HTMLReportFileAttributesTable(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions);
 var
  large1, large2, t : integer;

 begin
  //-----------------------------------------------------------------
  //file attributes table--------------------------------------------
  //-----------------------------------------------------------------

  Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
  Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                       '<td width="100" height="13" class="C7G"><a name="op2" /><b>' + XText[rsFileAttributes] + '</b></td>' +
                       '<td width="64" height="13" class="C7CB">' + XText[rsQuantity] + '</td>' +
                       '<td width="64" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                       '<td width="160" height="13">&nbsp;</td>' +
                       '<td width="85" height="13" class="C7CB">' + XText[rsSizeOfFiles] + '</td>' +
                       '<td width="67" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                       '<td width="160" height="20">&nbsp;</td>' +
                     '</tr>');

  if GScanDetails[aDATAINDEX].FileCount > 0 then begin
    if GScanDetails[aDATAINDEX].TotalSize > 0 then begin
      //find largest category %

      large1 := 0;
      large2 := 0;
      for t := 1 to __AttributesToDisplayCount do begin
        if Round((GScanDetails[aDataIndex].FileAttributes[t, 0] / GScanDetails[aDATAINDEX].FileCount) * 100) > large1 then large1 := Round((GScanDetails[aDataIndex].FileAttributes[t, 0] /GScanDetails[aDATAINDEX].FileCount) * 100);
        if Round((GScanDetails[aDataIndex].FileAttributes[t, 1] / GScanDetails[aDATAINDEX].TotalSize) * 100) > large2 then large2 := Round((GScanDetails[aDataIndex].FileAttributes[t, 1] /GScanDetails[aDATAINDEX].TotalSize) * 100);
      end;
      if large1 <= 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];
      if large2 <= 0 then large2 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

      //build the file category table
      for t := 1 to __AttributesToDisplayCount do begin
        if odd(t) then
          Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
        else
          Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

        Writeln(aTextFile, '<td width="100" class="C4L">' +LanguageTypes[t] + '</td>');
        Writeln(aTextFile, '<td width="64" class="C4C">' + IntToStr(GScanDetails[aDataIndex].FileAttributes[t, 0]) + '</td>');
        Writeln(aTextFile, '<td width="64" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 0] /GScanDetails[aDATAINDEX].FileCount) + '</td>');
        Writeln(aTextFile, '<td width="160">' +
                             '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].FileAttributes[t, 0] /GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">' +
                               '<tr><td></td></tr>' +
                             '</table>' +
                           '</td>');
        Writeln(aTextFile, '<td width="85" class="C4G">' +
                             '<div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, GScanDetails[aDataIndex].FileAttributes[t, 1]) + '</div>' +
                           '</td>');
        Writeln(aTextFile, '<td width="67" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 1] /GScanDetails[aDATAINDEX].TotalSize) + '</td>' +
                             '<td width="160">' +
                               '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].FileAttributes[t, 1] /GScanDetails[aDATAINDEX].TotalSize) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large2))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                 '<tr><td></td></tr>' +
                               '</table>' +
                             '</td>');
        Writeln(aTextFile, '</tr>');
      end;
    end
    else begin
    end;
  end
  else begin
  end;

  Writeln(aTextFile, '</table>');

  InsertSpacingTable(aTextFile);
end;


procedure THTMLReport.HTMLReportUsers(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions);
 var
  large1, large2, t, i, rowidx : integer;

begin
  //-----------------------------------------------------------------
  //-- Username -----------------------------------------------------
  //-----------------------------------------------------------------
  Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
  Writeln(aTextFile, '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td colspan="7" height="13"><a name="op10" /><b>' + XText[rsUsageByUser] + '</b></td><tr>');
  Writeln(aTextFile, '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                       '<td width="100" height="13"><b>' + XText[rsOwner] + '</b></td>' +
                       '<td width="64" height="13" class="XCB">' + XText[rsQuantity] + '</td>' +
                       '<td width="64" height="13" class="XCB">' + XText[rsAsPercent] + '</td>' +
                       '<td width="160" height="13">&nbsp;</td>' +
                       '<td width="85" height="13" class="XCB">' + XText[rsSizeOfFiles] + '</td>' +
                       '<td width="67" height="13" class="XCB">' + XText[rsAsPercent] + '</td>' +
                       '<td width="160" height="20">&nbsp;</td>' +
                     '</tr>');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin
    if GScanDetails[aDATAINDEX].TotalSize <> 0 then begin
      large1 := 0;
      large2 := 0;
      for i := 0 to GScanDetails[aDATAINDEX].Users.Count - 1 do begin
        if Round((GScanDetails[aDATAINDEX].Users[i].Data[XUserCount] / GScanDetails[aDATAINDEX].FileCount) * 100) > large1 then large1 := Round((GScanDetails[aDATAINDEX].Users[i].Data[XUserCount] /GScanDetails[aDATAINDEX].FileCount) * 100);
        if Round((GScanDetails[aDATAINDEX].Users[i].Data[XUserSize] / GScanDetails[aDATAINDEX].TotalSize) * 100) > large2 then  large2 := Round((GScanDetails[aDATAINDEX].Users[i].Data[XUserSize] /GScanDetails[aDATAINDEX].TotalSize) * 100);
      end;
      if large1 <= 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];
      if large2 <= 0 then large2 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

      rowidx := 1;

      // ============================================================

      GScanDetails[aDATAINDEX].Users.Sort(TComparer<TUserData>.Construct(SortUsersBySizeDesc));

      // ============================================================

      for t := 0 to GScanDetails[aDATAINDEX].Users.Count - 1 do begin
        // ==================================================================
        if odd(rowidx) then
          Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
        else
          Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

        inc(rowidx);
        // ==================================================================

        Writeln(aTextFile,   '<td width="100" height="13">' +TXFormatting.Privacy(GScanDetails[aDATAINDEX].Users[t].Name) + '</td>');
        Writeln(aTextFile,   '<td width="64" height="13"><div align="center">' + IntToStr(GScanDetails[aDATAINDEX].Users[t].Data[XUserCount]) + '</div></td>');
        Writeln(aTextFile,   '<td width="64" height="13"><div align="center">' + TConvert.RealToPercent(GScanDetails[aDATAINDEX].Users[t].Data[XUserCount] /GScanDetails[aDATAINDEX].FileCount) + '</div></td>');
        Writeln(aTextFile,   '<td width="160">' +
                               '<table width="' + IntToStr(Round(((GScanDetails[aDATAINDEX].Users[t].Data[XUserCount] / GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                '<tr><td></td></tr>' +
                               '</table>' +
                             '</td>');
        Writeln(aTextFile,   '<td width="85" height="13"><div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, GScanDetails[aDATAINDEX].Users[t].Data[XUserSize]) + '</div></td>');
        Writeln(aTextFile,   '<td width="67" height="13">' +
                               '<div align="center">' + TConvert.RealToPercent(GScanDetails[aDATAINDEX].Users[t].Data[XUserSize] /GScanDetails[aDATAINDEX].TotalSize) + '</div>' +
                             '</td>');
        Writeln(aTextFile,   '<td width="160">' +
                               '<table width="' + IntToStr(Round(((GScanDetails[aDATAINDEX].Users[t].Data[XUserSize] /GScanDetails[aDATAINDEX].TotalSize) * 100)*(ReportSizes[aOptions.LayoutSize, rsBarGraph] / large2))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                 '<tr><td></td></tr>' +
                               '</table>' +
                             '</td>');
        Writeln(aTextFile, '</tr>');
      end;

      InsertSpacingTable(aTextFile);
    end;
  end;
end;


procedure THTMLReport.HTMLReportFileExtensionLists(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions);
 var
  linecount, large1, large2, t, i, z, rowidx, percentage : integer;
  tfx : TFileExtension;

 begin
  //-----------------------------------------------------------------
  //-- File Extesnion Lists------------------------------------------
  //-----------------------------------------------------------------
  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin
    if GScanDetails[aDATAINDEX].TotalSize <> 0 then begin
      large1 := 0;
      large2 := 0;
      for i := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
        if Round((FileExtensionsObject.CategoryExtensions[i].Quantity[aDATAINDEX] / GScanDetails[aDATAINDEX].FileCount) * 100) > large1 then large1 := Round((FileExtensionsObject.CategoryExtensions[i].Quantity[aDATAINDEX] / GScanDetails[aDATAINDEX].FileCount) * 100);
        if Round((FileExtensionsObject.CategoryExtensions[i].Size[aDATAINDEX] / GScanDetails[aDATAINDEX].TotalSize) * 100) > large2     then large2 := Round((FileExtensionsObject.CategoryExtensions[i].Size[aDATAINDEX] / GScanDetails[aDATAINDEX].TotalSize) * 100);
      end;
      if large1 <= 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];
      if large2 <= 0 then large2 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

      for t := 1 to __FileCategoriesCount do begin

        if (aOptions.CategoryList[t] = '1') and (GScanDetails[aDataIndex].ExtensionSpread[t, 1] <> 0) then begin

          Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
          Writeln(aTextFile, '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                               '<td colspan="7" height="13"><a name="op6" /><b>' +TypeDescriptions[t] + ' [ ' + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]) + ' files (' + TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 1] /GScanDetails[aDATAINDEX].FileCount) + ') / ' + TConvert.GetSizeString(aOptions.HTMLUnits, GScanDetails[aDataIndex].ExtensionSpread[t, 2]) + ' (' +TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDATAINDEX].TotalSize) + ') ]' + '</b></td>' +
                             '<tr>');
          Writeln(aTextFile, '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                               '<td width="100" height="13"><b>' + XText[rsExtension] + '</b></td>' +
                               '<td width="64" height="13" class="XCB">' + XText[rsQuantity] + '</td>' +
                               '<td width="64" height="13" class="XCB">' + XText[rsAsPercent] + '</td>' +
                               '<td width="160" height="13">&nbsp;</td>' +
                               '<td width="85" height="13" class="XCB">' + XText[rsSizeOfFiles] + '</td>' +
                               '<td width="67" height="13" class="XCB">' + XText[rsAsPercent] + '</td>' +
                               '<td width="160" height="20">&nbsp;</td>' +
                             '</tr>');

          linecount := 0;
          if t <> __FileCategoriesOther then begin
            rowidx := 1;

            for z := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
              tfx := FileExtensionsObject.CategoryExtensions[z];

              if tfx.Category=t then begin
                //only include within report if number of files in extension > 0
                if tfx.Quantity[aDATAINDEX] > 0 then begin

                  // ==================================================================
                  if odd(rowidx) then
                    Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
                  else
                    Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

                  inc(rowidx);
                  // ==================================================================

                  Writeln(aTextFile, '<td width="100" height="13">.' + tfx.Name + '</td>');
                  Writeln(aTextFile, '<td width="64" height="13"><div align="center">' + IntToStr(tfx.Quantity[aDATAINDEX]) + '</div></td>');
                  Writeln(aTextFile, '<td width="64" height="13"><div align="center">' + TConvert.RealToPercent(tfx.Quantity[aDATAINDEX] /GScanDetails[aDATAINDEX].FileCount) + '</div></td>');
                  Writeln(aTextFile, '<td width="160">' +
                                        '<table width="' + IntToStr(Round(((tfx.Quantity[aDATAINDEX] /GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                          '<tr><td></td></tr>' +
                                        '</table>' +
                                     '</td>');
                  Writeln(aTextFile, '<td width="85" height="13"><div align="' + aOptions.HTMlAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, tfx.Size[aDATAINDEX]) + '</div></td>');
                  Writeln(aTextFile, '<td width="67" height="13"><div align="center">' + TConvert.RealToPercent(tfx.Size[aDATAINDEX] /GScanDetails[aDATAINDEX].TotalSize) + '</div></td>');
                  Writeln(aTextFile, '<td width="160">' +
                                       '<table width="' + IntToStr(Round(((tfx.Size[aDATAINDEX] /GScanDetails[aDATAINDEX].TotalSize) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large2))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                         '<tr><td></td></tr>' +
                                       '</table>' +
                                     '</td>');
                  Writeln(aTextFile, '</tr>');

                  inc(linecount);
                end;
              end;
            end;
          end
          else begin
            large1 := 0;
            large2 := 0;

            for z := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
              if FileExtensionsObject.CategoryExtensions[z].Category = Category_Other then begin
                if Round(((FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX] /GScanDetails[aDATAINDEX].FileCount)) * 100) > large1 then large1 := Round(((FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX] / GScanDetails[aDATAINDEX].FileCount)) * 100);
                if Round((FileExtensionsObject.CategoryExtensions[z].Size[aDATAINDEX] /GScanDetails[aDATAINDEX].TotalSize) * 100) > large2       then large2 := Round((FileExtensionsObject.CategoryExtensions[z].Size[aDATAINDEX] / GScanDetails[aDATAINDEX].TotalSize) * 100);
              end;
            end;

            if large1 <= 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];
            if large2 <= 0 then large2 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

            rowidx := 1;

            for z := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
              if FileExtensionsObject.CategoryExtensions[z].Category = Category_Other then begin

                //only include within report if number of files in extension > 0
                if FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX] <> 0 then begin

                  // ==================================================================
                  if odd(rowidx) then
                    Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
                  else
                    Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

                  inc(rowidx);
                  // ==================================================================

                  if FileExtensionsObject.CategoryExtensions[z].Name = '' then
                    Writeln(aTextFile, '<td width="100" height="13"><i>none</i></td>')
                  else
                    Writeln(aTextFile, '<td width="100" height="13">' + FileExtensionsObject.CategoryExtensions[z].Name + '</td>');
                  Writeln(aTextFile, '<td width="64" height="13"><div align="center">' + IntToStr(FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX]) + '</div></td>');
                  Writeln(aTextFile, '<td width="64" height="13"><div align="center">' + TConvert.RealToPercent(FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX] / GScanDetails[aDATAINDEX].FileCount) + '</div></td>');
                  Writeln(aTextFile, '<td width="160">');
                  if large1 <> 0 then
                    Writeln(aTextFile, '<table width="' + IntToStr(Round(((FileExtensionsObject.CategoryExtensions[z].Quantity[aDATAINDEX] / GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">')
                  else
                    Writeln(aTextFile, '<table width="1" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">');
                  Writeln(aTextFile, '<tr><td></td></tr>' +
                                       '</table>' +
                                     '</td>');
                  Writeln(aTextFile, '<td width="85" height="13">' +
                                       '<div align="' + aOptions.HTMLAlign + '">' +  TConvert.GetSizeString(aOptions.HTMLUnits, FileExtensionsObject.CategoryExtensions[z].Size[aDATAINDEX]) + '</div>' +
                                     '</td>');

                  percentage := Round(((FileExtensionsObject.CategoryExtensions[z].Size[aDATAINDEX]) / GScanDetails[aDATAINDEX].TotalSize)*100);

                  Writeln(aTextFile,   '<td width="67" height="13"><div align="center">' + TConvert.RealToPercent(FileExtensionsObject.CategoryExtensions[z].Size[aDATAINDEX] / GScanDetails[aDATAINDEX].TotalSize) + '</div></td>');
                  Writeln(aTextFile,   '<td width="160">');
                  if large2 <> 0 then
                    Writeln(aTextFile,     '<table width="' + IntToStr(Round(percentage * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large2))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">')
                  else
                    Writeln(aTextFile,     '<table width="1" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">');
                  Writeln(aTextFile,   '<tr><td></td></tr>');
                  Writeln(aTextFile,   '</table>');
                  Writeln(aTextFile,   '</td>');
                  Writeln(aTextFile, '</tr>');

                  inc(linecount);
                end;
              end;
            end;
          end;

          if linecount = 0 then begin
            Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><td colspan="7" height="13" class="C4G">' + XText[rsNoneFound] + '.</td></tr>');
          end;

          Writeln(aTextFile, '</table>');

          InsertSpacingTable(aTextFile);
        end;
      end;
    end;
  end;
end;


procedure THTMLReport.HTMLReportMagnitude(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);
var
  lCategory, large1, large2, t : integer;
  lTitle : string;

begin
  //-----------------------------------------------------------------
  //-- magnitude tables ---------------------------------------------
  //-----------------------------------------------------------------

  for lCategory := 0 to __FileCategoriesCount do begin

    if lCategory = 0 then
      lTitle := XText[rsMagnitude] + ': ' + XText[rsAll]
    else
      lTitle := XText[rsMagnitude] + ': ' + TypeDescriptions[lCategory];

    if (lCategory = 0) or (GScanDetails[aDataIndex].Magnitude.HasData(lCategory)) then
      Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                         '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                           '<td width="100" height="13" class="C7G"><a name="op5" /><b>' + lTitle + '</b></td>' +
                           '<td width="64" height="13" class="C7CB">' + XText[rsQuantity] + '</td>' +
                           '<td width="64" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                           '<td width="160" height="13">&nbsp;</td>' +
                           '<td width="85" height="13" class="C7CB">' + XText[rsSizeOfFiles] + '</td>' +
                           '<td width="67" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                           '<td width="160" height="20">&nbsp;</td>' +
                         '</tr>');

    if (GScanDetails[aDATAINDEX].FileCount <> 0) and (GScanDetails[aDataIndex].Magnitude.HasData(lCategory)) then begin
      //find largest category %
      if GScanDetails[aDATAINDEX].TotalSize <> 0 then begin
        large1 := 0;
        large2 := 0;
        for t := 0 to __MagnitudesCount do begin
          if Round((GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 0] / GScanDetails[aDATAINDEX].FileCount) * 100) > large1 then
            large1 := Round((GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 0] / GScanDetails[aDATAINDEX].FileCount) * 100);

          if Round((GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 1] / GScanDetails[aDATAINDEX].TotalSize) * 100) > large2 then
            large2 := Round((GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 1] / GScanDetails[aDATAINDEX].TotalSize) * 100);
        end;
        if large1 <= 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];
        if large2 <= 0 then large2 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

        //build the file category table
        for t := 0 to __MagnitudesCount do begin
          if odd(t + 1) then
            Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
          else
            Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

          Writeln(aTextFile,   '<td width="100" class="C4L">' + magnilabels2[t] + '</td>');
          Writeln(aTextFile,   '<td width="64" class="C4C">' + IntToStr(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 0]) + '</td>');
          Writeln(aTextFile,   '<td width="64" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 0] /GScanDetails[aDATAINDEX].FileCount) + '</td>');
          Writeln(aTextFile,   '<td width="160">' +
                               '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].Magnitude.Data[lCategory, t,0] / GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(magnicolors[t]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                 '<tr><td></td></tr>'  +
                                 '</table>'  +
                               '</td>');
          Writeln(aTextFile,   '<td width="85" class="C4G"><div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 1]) + '</div></td>');
          Writeln(aTextFile,   '<td width="67" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].Magnitude.Data[lCategory, t,1] /GScanDetails[aDATAINDEX].TotalSize) + '</td>');
          Writeln(aTextFile,   '<td width="160">' +
                                 '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].Magnitude.Data[lCategory, t, 1] / GScanDetails[aDATAINDEX].TotalSize) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large2))) + '" border="0" bgcolor="#' + TConvert.WebColor(magnicolors[t]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                   '<tr><td></td></tr>' +
                                 '</table>' +
                               '</td>');
          Writeln(aTextFile, '</tr>');
        end;
        Writeln(aTextFile, '</table>');

        //--build the magnitude graph table-------------------------------------------
        if (aIncludeImages) then begin
          Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellspacing="1" cellpadding="1">' +
                             '<tr class="C7CB">' +
                                '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' + XText[rsQuantity] + '</td>' +
                                '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' + XText[rsSizeOfFiles] + '</td>' +
                             '</tr>' +
                             '<tr>' +
                               '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><img src="data/xm0' + IntToStr(lCategory) + '_' + aMrRandom + '.png' + '"></td>' +
                               '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><img src="data/xm1' + IntToStr(lCategory) + '_' + aMrRandom + '.png' + '"></td>' +
                             '</tr>' +
                             '</table>');
        end;

        InsertSpacingTable(aTextFile);
      end;
    end;
  end;
end;


procedure THTMLReport.HTMLReportQuickInfo(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);
 begin
  //-----------------------------------------------------------------
  //--quick info table-----------------------------------------------
  //-----------------------------------------------------------------
  Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" height="180" border="0" cellspacing="1" cellpadding="1" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">');
  Writeln(aTextFile, '<tr><td width="100%" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '" class="C7G"><strong>' + XText[rsSummary] + '</strong></td></tr>');
  Writeln(aTextFile, '<tr>');
  Writeln(aTextFile,   '<td>');
  Writeln(aTextFile,   '<table width="100%" border="0" cellpadding="1" cellspacing="1">');
  Writeln(aTextFile,   '<tr>');
  Writeln(aTextFile,     '<td width="310" rowspan="11">');
  if (aIncludeImages) and (aDataIndex = dataLatestScan) then
    Writeln(aTextFile,       '<img src="data/dd' + aMrRandom + '.png' + '">');
  Writeln(aTextFile,     '</td>');
  Writeln(aTextFile,     '<td width="170" class="C4R">' + XText[rsNumberOfFiles] + ' </td>');
  Writeln(aTextFile,     '<td width="92" class="C4L"> - ' + IntToStr(GScanDetails[aDATAINDEX].FileCount) + '</td>');
  Writeln(aTextFile,   '</tr>');

  Writeln(aTextFile,   '<tr>' +
                         '<td width="170" class="C4R">' + XText[rsNumberOfFolders] + ' </td>' +
                         '<td width="92" class="C4L"> - ' + IntToStr(GScanDetails[aDataIndex].FolderCount) + '</td>' +
                       '</tr>');
  Writeln(aTextFile,   '<tr>' +
                         '<td width="170" class="C4R">' + XText[rsTotalSizeofFilesAnalysed] + ' </td>' +
                         '<td width="92" class="C4L"> - ' + TConvert.ConvertToUsefulUnit(GScanDetails[aDATAINDEX].TotalSize) + '</td>' +
                       '</tr>');
  Writeln(aTextFile,   '<tr>' +
                         '<td width="170" class="C4G">&nbsp;</td>' +
                         '<td width="92" class="C4G">&nbsp;</td>' +
                       '</tr>');
  Writeln(aTextFile,   '<tr>');
  Writeln(aTextFile,     '<td width="170" class="C4R">' + XText[rsDiskSpaceUsed] + ' </td>');
  if GScanDetails[aDATAINDEX].TotalSizeOD > 0 then
    Writeln(aTextFile,   '<td width="92" class="C4L"> - ' + TConvert.ConvertToUsefulUnit(GScanDetails[aDATAINDEX].TotalSizeOD) + '</td>')
  else
    Writeln(aTextFile,   '<td width="92" class="C4L"> - ' + XText[rsUnknown] + '</td>');
  Writeln(aTextFile,   '</tr>');

  Writeln(aTextFile,   '<tr>');
  Writeln(aTextFile,     '<td width="170" class="C4R">' + XText[rsDiskSpaceWasted] + ' </td>');
  if GScanDetails[aDATAINDEX].TotalSizeOD >=GScanDetails[aDATAINDEX].TotalSize then
    Writeln(aTextFile,   '<td width="92" class="C4L"> - ' + TConvert.ConvertToUsefulUnit(GScanDetails[aDATAINDEX].TotalSizeOD -GScanDetails[aDATAINDEX].TotalSize) + '</td>')
  else
    Writeln(aTextFile,   '<td width="92" class="C4L"> - ' + XText[rsUnknown] + '</td>');
  Writeln(aTextFile,   '</tr>');

  Writeln(aTextFile,   '<tr>' +
                         '<td width="170" class="C4G">&nbsp;</td>' +
                         '<td width="92" class="C4G">&nbsp;</td>' +
                       '</tr>');

  if GSystemGlobal.drivespacefree > 0 then begin
    Writeln(aTextFile,   '<tr>' +
                           '<td width="170" class="C4R">' + XText[rsDiskSpaceFree] + ' </td>' +
                           '<td width="92" class="C4L"> - ' + TConvert.ConvertToUsefulUnit(GSystemGlobal.drivespacefree) + '</td>' +
                         '</tr>');
  end
  else begin
    Writeln(aTextFile,   '<tr>' +
                           '<td width="170" class="C4R">' + XText[rsDiskSpaceFree] + ' </td>' +
                           '<td width="92" class="C4L"> - ?</td>' +
                         '</tr>');
  end;

  Writeln(aTextFile,   '<tr>' +
                         '<td width="170" class="C4G">&nbsp;</td>' +
                         '<td width="92" class="C4G">&nbsp;</td>' +
                       '</tr>');
  Writeln(aTextFile,   '<tr>' +
                         '<td width="170" class="C4G">&nbsp;</td>' +
                         '<td width="92" class="C4G">&nbsp;</td>' +
                       '</tr>');
  Writeln(aTextFile,   '</table>');
  Writeln(aTextFile,   '</td>');
  Writeln(aTextFile, '</tr>');
  Writeln(aTextFile, '</table>');

  InsertSpacingTable(aTextFile);
end;


procedure THTMLReport.HTMLReportDirectoryList(aDATAINDEX, aFileDatesCount : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);
 var
  large1, t, rowidx, colour : integer;

 begin
  //-----------------------------------------------------------------
  // --directory list---by file count--------------------------------
  //-----------------------------------------------------------------
  Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                     '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                       '<td width="387" height="20"><a name="op4" /><b>' + XText[rsFoldersRootQuantity] + '</b></td>' +
                     '</tr>');
  Writeln(aTextFile, '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                       '<td width="387" height="20"><b>' + XText[rsFolder] + '</b></td>' +
                       '<td width="83" height="20" class="XCB">' + XText[rsQtyOfFiles] + '</td>' +
                       '<td width="65" height="20" class="XCB">' + XText[rsAsPercent] + '</td>' +
                       '<td width="155" height="20">&nbsp;</td>' +
                     '</tr>');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin
    //find largest category %
    large1 := 0;
    for t := 0 to GScanDetails[aDATAINDEX].RootFolders.Count - 1 do begin
      if Round((GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount] /GScanDetails[aDATAINDEX].FileCount) * 100) > large1 then
        large1 := Round((GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount] /GScanDetails[aDATAINDEX].FileCount) * 100);
    end;
    if large1 <= 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

    rowidx := 1;

    for t := 0 to GScanDetails[aDATAINDEX].RootFolders.Count - 1 do begin
      if GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount] <> 0 then begin
        if aOptions.HTMLColours.MonoBarGraph then
          colour := aOptions.HTMLColours.Colour[5]
        else
          colour := spectrumcolours[t mod spectrummod];

        // ==================================================================
        if odd(rowidx) then
          Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
        else
          Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

        inc(rowidx);
        // ==================================================================

        Writeln(aTextFile, '<td width="387" class="C4L">');
        if t = 0 then
          Writeln(aTextFile, '<a href="' + WebFileLink(TXFormatting.Privacy(GScanDetails[aDATAINDEX].ScanPath)) + '" target="_blank">' + TXFormatting.MakeItalic(TXFormatting.Privacy(GScanDetails[aDATAINDEX].RootFolders[t].Name), (GScanDetails[aDATAINDEX].RootFolders[t].Attributes and faHidden) = faHidden) + '</a>')
        else
          Writeln(aTextFile, '<a href="' + WebFileLink(TXFormatting.Privacy(GScanDetails[aDATAINDEX].ScanPath + GScanDetails[aDATAINDEX].RootFolders[t].Name)) + '" target="_blank">' + TXFormatting.MakeItalic(TXFormatting.Privacy(GScanDetails[aDATAINDEX].RootFolders[t].Name), (GScanDetails[aDATAINDEX].RootFolders[t].Attributes and faHidden) = faHidden) + '</a>');

        Writeln(aTextFile,   '</td>');
        Writeln(aTextFile,   '<td width="83" class="C4C">' + IntToStr(GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount]) + '</td>');
        Writeln(aTextFile,   '<td width="65" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount] /GScanDetails[aDATAINDEX].FileCount) + '</td>');
        Writeln(aTextFile,   '<td width="160">' +
                               '<table width="' + IntToStr(Round(((GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount] /GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(colour) + '" height="8" cellpadding="0" cellspacing="0">' +
                                 '<tr><td></td></tr>' +
                               '</table>' +
                             '</td>');
        Writeln(aTextFile, '</tr>');
      end;
    end;
    Writeln(aTextFile, '</table>');

    //add the graph
    if (aIncludeImages) and (aFileDatesCount <> 0) then begin
      Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellspacing="1" cellpadding="1">' +
                         '<tr class="C7CB">' +
                           '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' + XText[rsLargestFiles] + '</td>' +
                         '</tr>' +
                         '<tr><td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><img src="data/cd0' + aMrRandom + '.png' + '"></td></tr>' +
                         '</table>');
    end;

    InsertSpacingTable(aTextFile);

    //-------------------------------------------------------------------
    //--directory list---by file size------------------------------------
    //-------------------------------------------------------------------
    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                         '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '" class="C7G">' +
                           '<td width="387" height="20"><b>' + XText[rsFoldersRootSize] + '</b></td>' +
                         '</tr>');
    Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '" class="C7G">' +
                         '<td width="387" height="20"><b>' + XText[rsFolder] + '</b></td>' +
                         '<td width="83" height="20" class="XCB">' + XText[rsSizeOfFiles] + '</td>' +
                         '<td width="65" height="20" class="XCB">' + XText[rsAsPercent] + '</td>' +
                         '<td width="155" height="20">&nbsp;</td>' +
                       '</tr>');

    if GScanDetails[aDATAINDEX].TotalSize <> 0 then begin
      //find largest category %
      large1 := 0;
      for t := 0 to GScanDetails[aDATAINDEX].RootFolders.Count - 1 do begin
        if Round((GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootSize] /GScanDetails[aDATAINDEX].TotalSize) * 100) > large1 then
          large1 := Round((GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootSize] /GScanDetails[aDATAINDEX].TotalSize) * 100);
      end;
      if large1 <= 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

      rowidx := 1;

      for t := 0 to GScanDetails[aDATAINDEX].RootFolders.Count - 1 do begin
        if GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootCount] <> 0 then begin
          if aOptions.HTMLColours.MonoBarGraph then
            colour := aOptions.HTMLColours.Colour[5]
          else
            colour := spectrumcolours[t mod spectrummod];

          // ==================================================================
          if odd(rowidx) then
            Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
          else
            Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

          inc(rowidx);
          // ==================================================================

          Writeln(aTextFile, '<td width="387" class="C4L">');
          if t = 0 then
            Writeln(aTextFile, '<a href="' + WebFileLink(TXFormatting.Privacy(GScanDetails[aDATAINDEX].ScanPath)) + '" target="_blank">' + TXFormatting.MakeItalic(TXFormatting.Privacy(GScanDetails[aDATAINDEX].RootFolders[t].Name), (GScanDetails[aDATAINDEX].RootFolders[t].Attributes and faHidden) = faHidden) + '</a>')
          else
            Writeln(aTextFile, '<a href="' + WebFileLink(TXFormatting.Privacy(GScanDetails[aDATAINDEX].ScanPath + GScanDetails[aDATAINDEX].RootFolders[t].Name)) + '" target="_blank">' + TXFormatting.MakeItalic(TXFormatting.Privacy(GScanDetails[aDATAINDEX].RootFolders[t].Name), (GScanDetails[aDATAINDEX].RootFolders[t].Attributes and faHidden) = faHidden) + '</a>');
          Writeln(aTextFile,   '</td>');
          Writeln(aTextFile,   '<td width="83" class="C4G">' +
                                 '<div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootSize]) + '</div>' +
                               '</td>');
          Writeln(aTextFile,   '<td width="65" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootSize] /GScanDetails[aDATAINDEX].TotalSize) + '</td>');
          Writeln(aTextFile,   '<td width="160">' +
                                 '<table width="' + IntToStr(Round(((GScanDetails[aDATAINDEX].RootFolders[t].Data[XRootSize] /GScanDetails[aDATAINDEX].TotalSize) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(colour) + '" height="8" cellpadding="0" cellspacing="0">' +
                                   '<tr><td></td></tr>' +
                                 '</table>' +
                               '</td>');
          Writeln(aTextFile, '</tr>');
        end;
      end;

      //add the graph
      if (aIncludeImages) then begin
        Writeln(aTextFile, '</table>');
        Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellspacing="1" cellpadding="1">' +
                             '<tr class="C7CB"><td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' + XText[rsSize] + '</td></tr>' +
                             '<tr><td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><img src="data/cd1' + aMrRandom + '.png' + '"></td></tr>' +
                           '</table>');
      end;
    end;
  end;

  InsertSpacingTable(aTextFile);
end;


procedure THTMLReport.HTMLReportTop50Largest(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aTop50Big : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aTop50Big <> Nil) then begin
    //-----------------------------------------------------------------
    //--top 50 largest files ------------------------------------------
    //-----------------------------------------------------------------
    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                       '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td colspan="4" height="13"><a name="op9" /><b>' + XText[rsTop101] + ' (' + XText[rsLargest]  + ')</b></td></tr>' +
                       '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                         '<td height="13" width="440"><b>' + XText[rsFiles] + '</b></td>' +
                         '<td height="13" width="160" class"XCB"><b>' + XText[rsAsPercent] + '</b></td>' +
                         '<td height="13" width="85" class"XCB"><b>' + XText[rsSize] + '</b></td>' +
                         '<td height="13" width="85" class"XCB"><b>' + XText[rsOwner] + '</b></td>' +
                       '</tr>');

    for t := 1 to aTop50Big.RowCount - 1 do begin
      // ==================================================================
      if odd(t) then
        Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
      else
        Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');
      // ==================================================================

      Writeln(aTextFile,   '<td height="13" width="440">' + TXFormatting.Privacy(aTop50Big.Cells[0,t]) + '</td>');
      Writeln(aTextFile,   '<td height="13" width="160">');

      if GScanDetails[aDATAINDEX].TotalSize <> 0 then
        Writeln(aTextFile,     '<table width="' + IntToStr(Round(((StrToInt64(aTop50Big.Cells[3,t]) / GScanDetails[aDATAINDEX].TotalSize)*ReportSizes[aOptions.LayoutSize, rsBarGraph]))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">')
      else
        Writeln(aTextFile,     '<table width="140" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">');

      Writeln(aTextFile,     '<tr><td></td></tr>');
      Writeln(aTextFile,     '</table>');
      Writeln(aTextFile,   '</td>');
      Writeln(aTextFile,   '<td height="13" width="85"><div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, StrToInt64(aTop50Big.Cells[3,t])) + '</div></td>');
      Writeln(aTextFile,   '<td height="13" width="85"><div align="' + aOptions.HTMLAlign + '">' + aTop50Big.Cells[2,t] + '</div></td>');
      Writeln(aTextFile, '</tr>');
    end;

    Writeln(aTextFile, '</table>');

    InsertSpacingTable(aTextFile);
  end;
end;


procedure THTMLReport.HTMLReportTop50Smallest(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aTop50Small : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aTop50Small <> Nil) then begin
    //----------------------------------------------------------------------------
    //--top 50 smallest files ----------------------------------------------------
    //----------------------------------------------------------------------------
    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                       '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td colspan="2" height="13"><a name="op14" /><b>' + XText[rsTop101] + ' (' + XText[rsSmallest] + ')</b></td></tr>' +
                       '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                         '<td height="13" width="685"><b>' + XText[rsFiles] + '</b></td>' +
                         '<td height="13" width="85"><b>' + XText[rsSize] + '</b></td>' +
                       '</tr>');

    for t := 1 to aTop50Small.RowCount - 1 do begin
      // ==================================================================
      if odd(t) then
        Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
      else
        Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');
      // ==================================================================

      Writeln(aTextFile,   '<td height="13" width="685">' + TXFormatting.Privacy(aTop50Small.Cells[0,t]) + '</td>');
      Writeln(aTextFile,   '<td height="13" width="85"><div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, StrToInt64(aTop50Small.Cells[2,t])) + '</div></td>');
      Writeln(aTextFile, '</tr>');
    end;

    Writeln(aTextFile, '</table>');

    InsertSpacingTable(aTextFile);
  end;
end;


procedure THTMLReport.HTMLReportTop101Newest(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aTop101BigDate : TAdvStringGrid; aTop101Dates : TComboBox);
 var
  t : integer;

 begin
  if (aTop101BigDate <> Nil) and (aTop101Dates <> Nil) then begin
    //----------------------------------------------------------------------------
    //--top 101 newest files -----------------------------------------------------
    //----------------------------------------------------------------------------

    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                       '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td colspan="4" height="13"><a name="op15" /><b>' + XText[rsTop101] + ' (' + XText[rsNewest]   + ')</b></td></tr>' +
                       '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                         '<td height="13" width="510"><b>' + XText[rsFiles] + '</b></td>' +
                         '<td height="13" width="90" class"XCB"><b>' + aTop101Dates.Items[aTop101Dates.ItemIndex] + '</b></td>' +
                         '<td height="13" width="85" class"XCB"><b>' + XText[rsSize] + '</b></td>' +
                         '<td height="13" width="85" class"XCB"><b>' + XText[rsOwner] + '</b></td>' +
                       '</tr>');

    for t := 1 to aTop101BigDate.RowCount - 1 do begin
      // ==================================================================
      if odd(t) then
        Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
      else
        Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');
      // ==================================================================

      Writeln(aTextFile,   '<td height="13" width="510">' + TXFormatting.Privacy(aTop101BigDate.Cells[0,t]) + '</td>');
      Writeln(aTextFile,   '<td height="13" width="90"><div align="center">' + aTop101BigDate.Cells[1,t] + '</div></td>');
      Writeln(aTextFile,   '<td height="13" width="85"><div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, StrToInt64(aTop101BigDate.Cells[5,t])) + '</div></td>');
      Writeln(aTextFile,   '<td height="13" width="85"><div align="' + aOptions.HTMLAlign + '">' + aTop101BigDate.Cells[3,t] + '</div></td>');
      Writeln(aTextFile, '</tr>');
    end;

    Writeln(aTextFile, '</table>');

    InsertSpacingTable(aTextFile);
  end;
end;


procedure THTMLReport.HTMLReportTop101Oldest(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aTop101SmallDate : TAdvStringGrid; aTop101Dates : TComboBox);
 var
  t : integer;

 begin
  if (aTop101SmallDate <> Nil) and (aTop101Dates <> Nil) then begin
    //----------------------------------------------------------------------------
    //--top 101 oldest files -----------------------------------------------------
    //----------------------------------------------------------------------------
    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                       '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td colspan="4" height="13"><a name="op16" /><b>' + XText[rsTop101] + ' (' + XText[rsOldest]   + ')</b></td></tr>' +
                       '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                         '<td height="13" width="510"><b>' + XText[rsFiles] + '</b></td>' +
                         '<td height="13" width="90" class"XCB"><b>' + aTop101Dates.Items[aTop101Dates.ItemIndex] + '</b></td>' +
                         '<td height="13" width="85" class"XCB"><b>' + XText[rsSize] + '</b></td>' +
                         '<td height="13" width="85" class"XCB"><b>' + XText[rsOwner] + '</b></td>' +
                       '</tr>');

    for t := 1 to aTop101SmallDate.RowCount - 1 do begin
      // ==================================================================
      if odd(t) then
        Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
      else
        Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');
      // ==================================================================

      Writeln(aTextFile,   '<td height="13" width="510">' + TXFormatting.Privacy(aTop101SmallDate.Cells[0,t]) + '</td>');
      Writeln(aTextFile,   '<td height="13" width="90"><div align="center">' + aTop101SmallDate.Cells[1,t] + '</div></td>');
      Writeln(aTextFile,   '<td height="13" width="85"><div align="' + aOptions.HTMLAlign + '">' +TConvert.GetSizeString(aOptions.HTMLUnits, StrToInt64(aTop101SmallDate.Cells[5,t])) + '</div></td>');
      Writeln(aTextFile,   '<td height="13" width="85"><div align="' + aOptions.HTMLAlign + '">' +aTop101SmallDate.Cells[3,t] + '</div></td>');
      Writeln(aTextFile, '</tr>');
    end;

    Writeln(aTextFile, '</table>');
    InsertSpacingTable(aTextFile);
  end;
end;


procedure THTMLReport.HTMLReportFileDates(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string; aFileDates : TComboBox; aTVFileDates : THTMLTreeview);
 var
  large1, large2, t, i, z, filecount, rowidx : integer;
  filesize : int64;
  year : string;

 begin
  if (aFileDates <> Nil) and (aTVFileDates <> Nil) then begin
    //-----------------------------------------------------------------
    //--file dates graph ----------------------------------------------
    //-----------------------------------------------------------------

    if (aIncludeImages) then begin
      Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellspacing="1" cellpadding="1">' +
                         '<tr class="C7CB"><td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><a name="op8" />' + XText[rsFileDates] + ' (' + aFileDates.Text + ')</td></tr>' +
                         '<tr><td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><img src="data/fd' + aMrRandom + '.png' + '"></td></tr>' +
                         '</table>');

      InsertSpacingTable(aTextFile);
    end;

    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                       '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td colspan="7" width="387" height="20"><a name="op8" /><b>' + XText[rsFileDates] + ' (' + aFileDates.Text + ')</b></td></tr>' +
                       '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                         '<td width="100" height="13" class="C7G"><a name="op3" /><b>' + XText[rsYear] + '</b></td>' +
                         '<td width="64" height="13" class="C7CB">' + XText[rsQuantity] + '</td>' +
                         '<td width="64" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                         '<td width="160" height="13">&nbsp;</td>' +
                         '<td width="85" height="13" class="C7CB">' + XText[rsSizeOfFiles] + '</td>' +
                         '<td width="67" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                         '<td width="160" height="20">&nbsp;</td>' +
                       '</tr>');

    if GScanDetails[aDATAINDEX].FileCount <> 0 then begin
      //find largest category %
      large1 := 0;
      large2 := 0;

      for t := 0 to aTVFileDates.Items.Count - 1 do begin
        if aTVFileDates.Items[t].Parent = Nil then begin
          i := Pos(': ', aTVFileDates.Items[t].Text);
          z := Pos(' (', aTVFileDates.Items[t].Text);

          filecount := StrToIntDef(Copy(aTVFileDates.Items[t].Text, i + 2, z - (i + 2)), -1);

          if filecount <> -1 then begin
            i := Pos(')', aTVFileDates.Items[t].Text);

            filesize  := TConvert.ConvertUsefulUnitToInteger(Copy(aTVFileDates.Items[t].Text, z + 2, i - (z + 2)));

            if Round((filecount /GScanDetails[aDATAINDEX].FileCount) * 100) > large1 then large1 := Round((filecount /GScanDetails[aDATAINDEX].FileCount) * 100);

            if GScanDetails[aDATAINDEX].TotalSize <> 0 then
              if Round((filesize /GScanDetails[aDATAINDEX].TotalSize) * 100) > large2 then large2 := Round((filesize /GScanDetails[aDATAINDEX].TotalSize) * 100);
          end;
        end;
      end;

      if large1 = 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];
      if large2 = 0 then large2 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

      rowidx := 1;

      for t := 0 to aTVFileDates.Items.Count - 1 do begin
        if aTVFileDates.Items[t].Parent = Nil then begin
          year := Copy(aTVFileDates.Items[t].Text, 4, 4);

          i := Pos(': ', aTVFileDates.Items[t].Text);
          z := Pos(' (', aTVFileDates.Items[t].Text);

          filecount := StrToIntDef(Copy(aTVFileDates.Items[t].Text, i + 2, z - (i + 2)), -1);

          if filecount <> -1 then begin

            i := Pos(')', aTVFileDates.Items[t].Text);

            filesize  := TConvert.ConvertUsefulUnitToInteger(Copy(aTVFileDates.Items[t].Text, z + 2, i - (z + 2)));

            if filecount <> 0 then begin
              // ==================================================================
              if odd(rowidx) then
                Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
              else
                Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

              inc(rowidx);
              // ==================================================================

              Writeln(aTextFile,   '<td width="100" class="C4L">' + year + '</td>');
              Writeln(aTextFile,   '<td width="64" class="C4C">' + IntToStr(filecount) + '</td>');
              Writeln(aTextFile,   '<td width="64" class="C4C">' + TConvert.RealToPercent(filecount /GScanDetails[aDATAINDEX].FileCount) + '</td>');
              Writeln(aTextFile,   '<td width="160">' +
                                   '<table width="' + IntToStr(Round(((filecount /GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                     '<tr><td></td></tr>' +
                                   '</table>' +
                                   '</td>');
              Writeln(aTextFile,   '<td width="85" class="C4G"><div align="' + aOptions.HTMLAlign + '">' +TConvert.GetSizeString(aOptions.HTMLUnits, filesize) + '</div></td>');
              if GScanDetails[aDATAINDEX].TotalSize <> 0 then
                Writeln(aTextFile,   '<td width="67" class="C4C">' +TConvert.RealToPercent(filesize /GScanDetails[aDATAINDEX].TotalSize) + '</td>')
              else
                Writeln(aTextFile,   '<td width="67" class="C4C">100%</td>');
              Writeln(aTextFile,     '<td width="160">');
              if GScanDetails[aDATAINDEX].TotalSize <> 0 then
                Writeln(aTextFile,     '<table width="' + IntToStr(Round(((filesize /GScanDetails[aDATAINDEX].TotalSize) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large2))) + '" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">')
              else
                Writeln(aTextFile,     '<table width="140" border="0" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">');
              Writeln(aTextFile,     '<tr><td></td></tr>');
              Writeln(aTextFile,     '</table>');
              Writeln(aTextFile,   '</td>');
              Writeln(aTextFile, '</tr>');
            end;
          end;
        end;
      end;

      InsertSpacingTable(aTextFile);
    end;
  end;
end;


procedure THTMLReport.HTMLReportNullFiles(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aSGNullFiles, aSGNullFolders : TAdvStringGrid);
 var
  t : integer;

 begin
  if (aSGNullFiles <> Nil) and (aSGNullFolders <> Nil) then begin
    //-------------------------------------------------------------
    //--null files ----------------------------------------------------
    //-----------------------------------------------------------------
    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
    Writeln(aTextFile, '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '"><td height="13"><a name="op7" /><b>' + XText[rsNullFiles] + '</b></td></tr>');

    if (aSGNullFiles.Cells[0, 1] = XText[rsNoneFound]) or (aSGNullFiles.Cells[0, 1] = '') then begin
      Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '" class="C4G"><td colspan="7" height="13">' + XText[rsNoneFound] + '</td></tr>');
    end
    else begin
      for t := 1 to aSGNullFiles.RowCount - 1 do begin
        // ==================================================================
        if odd(t + 1) then
          Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
        else
          Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

        // ==================================================================

        Writeln(aTextFile,  '<td height="13">' + TXFormatting.Privacy(aSGNullFiles.Cells[0, t]) + '</td>');
        Writeln(aTextFile, '</tr>');
      end;
    end;

    Writeln(aTextFile, '</table>');

    InsertSpacingTable(aTextFile);

    Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">');
    Writeln(aTextFile, '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">');
    Writeln(aTextFile, '<td height="13"><a name="op7a" /><b>' + XText[rsEmptyFolders] + '</b></td>');
    Writeln(aTextFile, '</tr>');

    if aSGNullFolders.Cells[1, 1] = XText[rsNoneFound] then begin
      Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '" class="C4G"><td colspan="7" height="13">' + XText[rsNoneFound] + '</td></tr>');
    end
    else begin
      for t := 1 to aSGNullFolders.RowCount - 1 do begin
        // ==================================================================
        if odd(t + 1) then
          Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
        else
          Writeln(aTextFile, '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

        // ==================================================================

        Writeln(aTextFile,   '<td height="13"><a href="' + WebFileLink(TXFormatting.Privacy(aSGNullFolders.Cells[0,t])) + '">' + TXFormatting.Privacy(aSGNullFolders.Cells[0,t]) + '</a></td>');

        Writeln(aTextFile, '</tr>');
      end;
    end;
    Writeln(aTextFile, '</table>');

    InsertSpacingTable(aTextFile);
  end;
end;


procedure THTMLReport.HTMLReportNameLength(aDATAINDEX : integer; var aTextFile : TextFile; aOptions : THTMLReportOptions; aIncludeImages : boolean; aMrRandom : string);
var
  large1, large2, t, rowidx : integer;
  lNameLength : string;

begin
  //-----------------------------------------------------------------
  //file category table----------------------------------------------
  //-----------------------------------------------------------------
  Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellpadding="1" cellspacing="1">' +
                     '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' +
                       '<td width="100" height="13" class="C7G"><a name="op3" /><b>' + XText[rsFileNameLength] + '</b></td>' +
                       '<td width="64" height="13" class="C7CB">' + XText[rsQuantity] + '</td>' +
                       '<td width="64" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                       '<td width="160" height="13">&nbsp;</td>' +
                       '<td width="85" height="13" class="C7CB">' + XText[rsSizeOfFiles] + '</td>' +
                       '<td width="67" height="13" class="C7CB">' + XText[rsAsPercent] + '</td>' +
                       '<td width="160" height="20">&nbsp;</td>' +
                     '</tr>');

  if GScanDetails[aDATAINDEX].FileCount <> 0 then begin
    if GScanDetails[aDATAINDEX].TotalSize <> 0 then begin
      //find largest category %
      large1 := 0;
      large2 := 0;

      for t := 0 to __FileCategoriesCount do begin
        if Round((GScanDetails[aDataIndex].NameLengthSize[t]  / GScanDetails[aDATAINDEX].TotalSize) * 100) > large2 then large2 := Round((GScanDetails[aDataIndex].NameLengthSize[t] /GScanDetails[aDATAINDEX].TotalSize) * 100);
        if Round((GScanDetails[aDataIndex].NameLengthCount[t] / GScanDetails[aDATAINDEX].FileCount) * 100) > large1 then large1 := Round((GScanDetails[aDataIndex].NameLengthCount[t] /GScanDetails[aDATAINDEX].FileCount) * 100);
      end;
      if large1 <= 0 then large1 := ReportSizes[aOptions.LayoutSize, rsBarGraph];
      if large2 <= 0 then large2 := ReportSizes[aOptions.LayoutSize, rsBarGraph];

      rowidx := 1;

      //build the file length table
      for t := 0 to 279 do begin
        if t = 279 then
          lNameLength := '&gt;=280'
        else
          lNameLength := IntToStr(t + 1);


        if GScanDetails[aDataIndex].NameLengthCount[t] <> 0 then begin
          // ==================================================================
          if odd(rowidx) then
            Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '">')
          else
            Writeln(aTextFile, '<tr bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[11]) + '">');

          inc(rowidx);
          // ==================================================================

          Writeln(aTextFile,   '<td width="100" class="C4L">' + IntToStr(t + 1) + '</td>');
          Writeln(aTextFile,   '<td width="64" class="C4C">' + lNameLength + '</td>');
          Writeln(aTextFile,   '<td width="64" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].NameLengthCount[t] /GScanDetails[aDATAINDEX].FileCount) + '</td>');
          Writeln(aTextFile,   '<td width="160">' +
                                 '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].NameLengthCount[t] /GScanDetails[aDATAINDEX].FileCount) * 100) * (ReportSizes[aOptions.LayoutSize, rsBarGraph] / large1))) + '" border="0" bgcolor="#' + TConvert.WebColor(spectrumcolours[t mod spectrummod]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                   '<tr><td></td></tr>' +
                                 '</table>' +
                               '</td>');
          Writeln(aTextFile,   '<td width="85" class="C4G"><div align="' + aOptions.HTMLAlign + '">' + TConvert.GetSizeString(aOptions.HTMLUnits, GScanDetails[aDataIndex].NameLengthSize[t]) + '</div></td>');
          Writeln(aTextFile,   '<td width="67" class="C4C">' + TConvert.RealToPercent(GScanDetails[aDataIndex].NameLengthSize[t] / GScanDetails[aDATAINDEX].TotalSize) + '</td>');
          Writeln(aTextFile,   '<td width="160">' +
                                 '<table width="' + IntToStr(Round(((GScanDetails[aDataIndex].NameLengthSize[t] /GScanDetails[aDATAINDEX].TotalSize) * 100)*(ReportSizes[aOptions.LayoutSize, rsBarGraph] / large2))) + '" border="0" bgcolor="#' + TConvert.WebColor(spectrumcolours[t mod spectrummod]) + '" height="8" cellpadding="0" cellspacing="0">' +
                                   '<tr><td></td></tr>' +
                                 '</table>' +
                               '</td>');
          Writeln(aTextFile, '</tr>');
        end;
      end;

      Writeln(aTextFile, '</table>');

      InsertSpacingTable(aTextFile);

      //build the graph table
      if (aIncludeImages) then begin
        Writeln(aTextFile, '<table align="center" width="' + IntToStr(ReportSizes[aOptions.LayoutSize, rsTableWidth]) + '" border="0" cellspacing="1" cellpadding="1">' +
                           '<tr class="C7CB">' +
                             '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' + XText[rsFileNameLength] + '</td>' +
                             '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[6]) + '">' + XText[rsFileNameLength] + '</td>' +
                           '</tr>' +
                           '<tr>' +
                             '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><img src="data/nl1' + aMrRandom + '.png' + '"></td>' +
                             '<td bgcolor="#' + TConvert.WebColor(aOptions.HTMLColours.Colour[10]) + '"><img src="data/nl2' + aMrRandom + '.png' + '"></td>' +
                           '</tr>' +
                           '</table>');

        InsertSpacingTable(aTextFile);
      end;
    end;
  end
end;


procedure THTMLReport.GenerateHTMLFileReport(aDataIndex : integer; aReportOutput : TStringList; aTitle, aFileName : string);
var
  t : integer;
  tfo : TFileObject;

begin
  aReportOutput.Add('<!DOCTYPE html><html><head><style>p { display: inline;} .name { color : #886600; } .user { color : #668800; } .size { color : #006688; }</style></head><body>');
  aReportOutput.Add('<p>Xinorbis :: <b>' + aTitle + '</b></p><br/><br/>');

  if GScanDetails[aDataIndex].Files.Count <> 0 then begin

    for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
      tfo := GScanDetails[aDataIndex].Files[t];

      aReportOutput.Add('<p class="name">' + GScanDetails[aDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName + '</p>');
      aReportOutput.Add('<p class="user">' + GScanDetails[aDataIndex].Users[tfo.Owner].Name + '</p>');
      aReportOutput.Add('<p class="size">' + TConvert.ConvertToUsefulUnit(tfo.FileSize) + ' (' + IntToStr(tfo.FileSize) + ' ' + XText[rsBytes] + ')</p>');
      aReportOutput.Add('<br/>');
    end;
  end
  else begin
    aReportOutput.Add('<p class="name">No files found.</p>');
    aReportOutput.Add('<br/>');
  end;

  aReportOutput.Add('</body></html>');

  if aFileName <> '' then begin
    try
      aReportOutput.SaveToFile(aFileName);

      GReportUtility.SetLastReport(aDataIndex, aFileName, GScanDetails[aDataIndex].ScanPath, ReportText, LayoutUnknown);

      if Assigned(FSetStatusBarText) then
        FSetStatusBarText(XText[rsTextReportSavedAs] + ': '  + aFileName);
    except
      ShowXDialog(XText[rsErrorSavingReport], XText[rsErrorSaving] + ' "' + aFileName + '".', XDialogTypeWarning);
    end;
  end;
end;


function THTMLReport.BuildHTMLReportOptionsFromFile(const fn : string): THTMLReportOptions;
 var
  tf : TextFile;
  s : string;
  tHTMLro : THTMLReportOptions;

 begin
  Assert(fn <> '', 'BuildHTMLReportOptionsFromFile :: invalid filename');

  AssignFile(tf, fn);
  {$I-}
  Reset(tf);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsErrorOpening] + ': ' + XText[rsReport],
                XText[rsErrorOpening] + ' "' + fn + '".',
                XDialogTypeWarning);
  end
  else begin
    tHTMLro.HTMLUnits    := XSettings.Report.HTMLOptions[1].HTMLUnits;

    Readln(tf, s);
    tHTMLro.Layout       := s;

    Readln(tf, s);
    tHTMLro.CategoryList := s;

    Readln(tf, s);
    tHTMLro.LayoutSize   := StrToInt(s);

    CloseFile(tf);
  end;
  {$I+}

  Result := tHTMLro;
end;


end.
