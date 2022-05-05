{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CHTMLPreview;

interface


uses
  System.SysUtils, Classes,

  X.CReportColours, X.CReportOptions,

  X.Conversions, X.Constants, X.LanguageHandler, X.Utility, X.Global, X.SystemGlobal;


type
  THTMLPreview = class
  public
    class function Get(aReport : THTMLReportOptions; aColours : THTMLColours): string;
  end;


implementation


class function THTMLPreview.Get(aReport : THTMLReportOptions; aColours : THTMLColours): string;
var
  t, colour: integer;
  s, alignmode : String;
  menulist : TStringList;

 procedure InsertSpacingTable;
  begin
   Result := Result + '<table align="center" width="770" border="0">';
   Result := Result + '  <tr><td>&nbsp;</td></tr>';
   Result := Result + '</table>';
 end;

 procedure BuildMenuList;
 begin
   menulist.Add('&nbsp;&nbsp;- <a href="#op2">'  + XText[rsReportOptions] + '</a>');
   menulist.Add('&nbsp;&nbsp;- <a href="#op3">'  + XText[rsExtension]  + '</a>');
   menulist.Add('&nbsp;&nbsp;- <a href="#op4">'  + XText[rsCategory] + '</a>');
   menulist.Add('&nbsp;&nbsp;- <a href="#op5">'  + XText[rsPath] + '</a>');
   menulist.Add('&nbsp;&nbsp;- <a href="#op6">'  + XText[rsAssociatedFileExtensions] + '</a>');
   menulist.Add('&nbsp;&nbsp;- <a href="#op7">'  + XText[rsHelp] + '</a> / <a href="#op7a">' + XText[rsAutosaveReports] + '</a>');
   menulist.Add('&nbsp;&nbsp;- <a href="#op8">'  + XText[rsChartOptions] + '</a>');
   menulist.Add('&nbsp;&nbsp;- <a href="#op9">'  + XText[rsRestoreDefaults] + '</a>');
   menulist.Add('&nbsp;&nbsp;- <a href="#op10">' + XText[rsAutosaveOptions] + '</a>');
 end;

 procedure AddHTMLReportItem(sidx : integer);
 var
   t : integer;

 begin
   case sidx of
       CHTMLHeader : begin
             //----------------------------------------------------------------------------
             //--header table---------------------------------------------------------------
             //----------------------------------------------------------------------------
             Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1" bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '">';
             Result := Result + '<tr class="C4G">';
             Result := Result + '<td><div align="center"><b>xinorbis<sup>8</sup></b> report for <b><a href="#">c:\xinorbis\preview</a></b></div></td>';
             Result := Result + '</tr>';
             Result := Result + '<tr class="C4G"><td><div align="center">Analysed at <b>' + TUtility.GetTime(GETTIMEFORMAT_DISPLAY) + '</b> on <b>' + TUtility.GetDate(GETTIMEFORMAT_DISPLAY) + '</b></div></td>';
             Result := Result + '</tr>';
             Result := Result + '</table>';

             InsertSpacingTable;
           end;
       CHTMLQuick : begin
             //-----------------------------------------------------------------
             //--quick info table-----------------------------------------------
             //-----------------------------------------------------------------
             Result := Result + '<table align="center" width="770" height="180" border="0" cellpadding="1" cellspacing="1" bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '">';
             Result := Result + '<tr><td width="100%" bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '" class="C7G"><strong>' + XText[rsSummary] + '</strong></td></tr>';
             Result := Result + '<tr>';
             Result := Result +   '<td>';
             Result := Result +   '<table width="100%" border="0" cellpadding="0" cellspacing="0">';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="100" class="C4G">' + menulist.Strings[0] + '</div></td>';
             Result := Result +     '<td width="310" rowspan="11"></td>';
             Result := Result +     '<td width="170" class="C4G"><div align="right">' + XText[rsFileAttributes] + ' - </div></td>';
             Result := Result +     '<td width="92" class="C4G"><div align="left"> - 3141592</div></td>';
             Result := Result +   '</tr>';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="170" class="C4G">' + menulist.Strings[1] + '</div></td>';
             Result := Result +     '<td width="170" class="C4G"><div align="right">' + XText[rsFiles] + ' - </div></td>';
             Result := Result +     '<td width="92" class="C4G"><div align="left"> - 2718</div></td>';
             Result := Result +   '</tr>';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="170" class="C4G">' + menulist.Strings[2] + '</div></td>';
             Result := Result +     '<td width="170" class="C4G"><div align="right">' + XText[rsCategoryColours] + ' - </div></td>';
             Result := Result +     '<td width="92" class="C4G"><div align="left"> - 245MB</div></td>';
             Result := Result +   '</tr>';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="170" class="C4G">' + menulist.Strings[3] + '</div></td>';
             Result := Result +     '<td width="170" class="C4G">&nbsp;</td>';
             Result := Result +     '<td width="92" class="C4G">&nbsp;</td>';
             Result := Result +   '</tr>';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="170" class="C4G">' + menulist.Strings[4] + '</div></td>';
             Result := Result +     '<td width="170" class="C4G"><div align="right">Disk space used - </div></td>';
             Result := Result +     '<td width="92" class="C4G"><div align="left"> - 1.41GB</div></td>';
             Result := Result +   '</tr>';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="170" class="C4G">' + menulist.Strings[5] + '</div></td>';
             Result := Result +     '<td width="170" class="C4G"><div align="right">Disk space wasted - </div></td>';
             Result := Result +     '<td width="92" class="C4G"><div align="left"> - 148MB</div></td>';
             Result := Result +   '</tr>';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="170" class="C4G">' + menulist.Strings[6] + '</div></td>';
             Result := Result +     '<td width="170" class="C4G">&nbsp;</td>';
             Result := Result +     '<td width="92" class="C4G">&nbsp;</td>';
             Result := Result +   '</tr>';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="170" class="C4G">' + menulist.Strings[7] + '</div></td>';
             Result := Result +     '<td width="170" class="C4G"><div align="right">' + XText[rsFolder] + ' - </div></td>';
             Result := Result +     '<td width="92" class="C4G"><div align="left"> - 1.2GB</div></td>';
             Result := Result +   '</tr>';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="170" class="C4G">' + menulist.Strings[8] + '</div></td>';
             Result := Result +     '<td width="170" class="C4G">&nbsp;</td>';
             Result := Result +     '<td width="92" class="C4G">&nbsp;</td>';
             Result := Result +   '</tr>';
             Result := Result +   '<tr>';
             Result := Result +     '<td width="170" class="C4G">&nbsp;</td>';
             Result := Result +     '<td width="170" class="C4G">&nbsp;</td>';
             Result := Result +     '<td width="92" class="C4G">&nbsp;</td>';
             Result := Result +   '</tr>';
             Result := Result +   '</table>';
             Result := Result +   '</td>';
             Result := Result + '</tr>';
             Result := Result + '</table>';

             InsertSpacingTable;
           end;
       CHTMLFAT : begin
             //-----------------------------------------------------------------
             //file attributes table--------------------------------------------
             //-----------------------------------------------------------------
             Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1">';
             Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result +   '<td width="100" height="13" class="C7G"><a name="op2" /><b>' + XText[rsReportOptions] + '</b></td>';
             Result := Result +   '<td width="64" height="13" class="C7G"><div align="center"><b>' + XText[rsQty] + '</b></div></td>';
             Result := Result +   '<td width="64" height="13" class="C7G"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result +   '<td width="160" height="13">&nbsp;</td>';
             Result := Result +   '<td width="85" height="13" class="C7G"><div align="center"><b>' + XText[rsFileSize] + '</b></div></td>';
             Result := Result +   '<td width="67" height="13" class="C7G"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result +   '<td width="160" height="20">&nbsp;</td>';
             Result := Result + '</tr>';

             //build the file category table
             for t := 1 to __AttributesToDisplayCount do begin
               if odd(t) then
                 Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '">'
               else
                 Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[11]) + '">';

               Result := Result +   '<td width="100" class="C4G">';
               Result := Result +     '<div align="left">' + LanguageTypes[t] + '</div>';
               Result := Result +   '</td>';
               Result := Result +   '<td width="64" class="C4G"><div align="center">' + IntToStr(Random(2000)) + '</div></td>';
               Result := Result +   '<td width="64" class="C4G"><div align="center">' + IntToStr(2 + Random(130)) + '</div></td>';
               Result := Result +   '<td width="160">';
               Result := Result +   '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(aColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">';
               Result := Result +     '<tr><td></td></tr>';
               Result := Result +   '</table>';
               Result := Result +   '</td>';
               Result := Result +   '<td width="85" class="C4G"><div align="' + alignmode + '">1GB</div></td>';
               Result := Result +   '<td width="67" class="C4G"><div align="center">10%</div></td>';
               Result := Result +   '<td width="160">';
               Result := Result +   '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(aColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">';
               Result := Result +     '<tr><td></td></tr>';
               Result := Result +   '</table>';
               Result := Result +   '</td>';
               Result := Result + '</tr>';
             end;
             Result := Result + '</table>';

             InsertSpacingTable;
           end;
       CHTMLCategory : begin
             //-----------------------------------------------------------------
             //file category table----------------------------------------------
             //-----------------------------------------------------------------
             Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1">';
             Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result +   '<td width="100" height="13" class="C7G"><a name="op3" /><b>' + XText[rsExtension] + '</b></td>';
             Result := Result +   '<td width="64" height="13" class="C7G"><div align="center"><b>' + XText[rsQty] + '</b></div></td>';
             Result := Result +   '<td width="64" height="13" class="C7G"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result +   '<td width="160" height="13">&nbsp;</td>';
             Result := Result +   '<td width="85" height="13" class="C7G"><div align="center"><b>' + XText[rsFileSize] + '</b></div></td>';
             Result := Result +   '<td width="67" height="13" class="C7G"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result +   '<td width="160" height="20">&nbsp;</td>';
             Result := Result + '</tr>';

             //build the file category table
             for t := 1 to __FileCategoriesCount do begin
                 if odd(t) then
                   Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '">'
                 else
                   Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[11]) + '">';

                 Result := Result +   '<td width="100" class="C4G"><div align="left">' + TypeDescriptions[t] + '</div></td>';
                 Result := Result +   '<td width="64" class="C4G"><div align="center">' + IntToStr(2 + Random(1300)) + '</div></td>';
                 Result := Result +   '<td width="64" class="C4G"><div align="center">' + IntToStr(2 + Random(80)) + '%</div></td>';
                 Result := Result +   '<td width="160">';
                 Result := Result +     '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(GSystemGlobal.FileCategoryColors[t]) + '" height="8" cellpadding="0" cellspacing="0">';
                 Result := Result +     '<tr><td></td></tr>';
                 Result := Result +     '</table>';
                 Result := Result +   '</td>';
                 Result := Result +   '<td width="85" class="C4G"><div align="' + alignmode + '">1GB</div></td>';
                 Result := Result +   '<td width="67" class="C4G"><div align="center">' + IntToStr(2 + Random(80)) + '%</div></td>';
                 Result := Result +   '<td width="160">';
                 Result := Result +     '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(GSystemGlobal.FileCategoryColors[t]) + '" height="8" cellpadding="0" cellspacing="0">';
                 Result := Result +     '<tr><td></td></tr>';
                 Result := Result +     '</table>';
                 Result := Result +   '</td>';
                 Result := Result + '</tr>';
             end;

             Result := Result + '</table>';

             InsertSpacingTable;
           end;
       CHTMLFolders : begin
             //-----------------------------------------------------------------
             // --directory list---by file count--------------------------------
             //-----------------------------------------------------------------
             Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1">';
             Result := Result + '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result +   '<td width="387" height="20"><a name="op4" /><b>' + XText[rsFileName] + '</b></td>';
             Result := Result + '</tr>';
             Result := Result + '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result +   '<td width="387" height="20"><b>' + XText[rsFolder] + '</b></td>';
             Result := Result +   '<td width="83" height="20"><div align="center"><b>' + XText[rsQtyOfFiles] + '</b></div></td>';
             Result := Result +   '<td width="65" height="20"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result +   '<td width="155" height="20">&nbsp;</td>';
             Result := Result + '</tr>';

             for t := 0 to 3 do begin
                 if aColours.MonoBargraph then
                   colour := aColours.Colour[5]
                 else
                   colour := spectrumcolours[t mod spectrummod];

                 if odd(t) then
                   Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '">'
                 else
                   Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[11]) + '">';

                 Result := Result +   '<td width="387" class="C4G"><div align="left">Preview Folder #' + IntToStr(t) + '</div></td>';
                 Result := Result +   '<td width="83" class="C4G"><div align="center">' + IntToStr(4 + Random(100)) + '</div></td>';
                 Result := Result +   '<td width="65" class="C4G"><div align="center">' + IntToStr(4 + Random(20)) + '%</div></td>';
                 Result := Result +   '<td width="160">';
                 Result := Result +     '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(colour) + '" height="8" cellpadding="0" cellspacing="0">';
                 Result := Result +     '<tr><td></td></tr>';
                 Result := Result +     '</table>';
                 Result := Result +   '</td>';
                 Result := Result + '</tr>';
             end;
             Result := Result + '</table>';

             InsertSpacingTable;
           end;
       6 : begin
             //-----------------------------------------------------------------
             //-- magnitude table ----------------------------------------------
             //-----------------------------------------------------------------
             Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1">';
             Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result +   '<td width="100" height="13" class="C7G"><a name="op5" /><b>' + XText[rsPath] + '</b></td>';
             Result := Result +   '<td width="64" height="13" class="C7G"><div align="center"><b>' + XText[rsQty] + '</b></div></td>';
             Result := Result +   '<td width="64" height="13" class="C7G"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result +   '<td width="160" height="13">&nbsp;</td>';
             Result := Result +   '<td width="85" height="13" class="C7G"><div align="center"><b>' + XText[rsFileSize] + '</b></div></td>';
             Result := Result +   '<td width="67" height="13" class="C7G"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result +   '<td width="160" height="20">&nbsp;</td>';
             Result := Result + '</tr>';

             //build the file category table
             for t := 0 to __MagnitudesCount do begin
               if odd(t + 1) then
                 Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '">'
               else
                 Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[11]) + '">';

               Result := Result +   '<td width="100" class="C4G"><div align="left">' + magnilabels2[t] + '</div></td>';
               Result := Result +   '<td width="64" class="C4G"><div align="center">' + IntToStr(Random(20)) + '</div></td>';
               Result := Result +   '<td width="64" class="C4G"><div align="center">' + IntToStr(Random(20)) + '%</div></td>';
               Result := Result +   '<td width="160">';
               Result := Result +     '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' +  TConvert.WebColor(magnicolors[t]) + '" height="8" cellpadding="0" cellspacing="0">';
               Result := Result +     '<tr><td></td></tr>';
               Result := Result +     '</table>';
               Result := Result +   '</td>';
               Result := Result +   '<td width="85" class="C4G"><div align="' + alignmode + '">' + TConvert.GetSizeString(aReport.HTMLUnits, 1024 * Random(1024) * Random(1024)) + '</div></td>';
               Result := Result +   '<td width="67" class="C4G"><div align="center">' + IntToStr(Random(20)) + '</div></td>';
               Result := Result +   '<td width="160">';
               Result := Result +     '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(magnicolors[t]) + '" height="8" cellpadding="0" cellspacing="0">';
               Result := Result +     '<tr><td></td></tr>';
               Result := Result +     '</table>';
               Result := Result +   '</td>';
               Result := Result + '</tr>';
             end;
             Result := Result + '</table>';

             InsertSpacingTable;
           end;
       CHTMLNullFiles : begin
             //-----------------------------------------------------------------
             //-- null files ---------------------------------------------------
             //-----------------------------------------------------------------
             Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1">';
             Result := Result + '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result + '<td height="13"><a name="op7" /><b>' + XText[rsNullFiles] + '</b></td>';
             Result := Result + '</tr>';
             Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '" class="C4G">';
             Result := Result + '<td colspan="7" height="13">' +  XText[rsGeneral] + '</td>';
             Result := Result + '</tr>';
             Result := Result + '</table>';

             InsertSpacingTable;

             Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1">';
             Result := Result + '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result + '<td height="13"><a name="op7a" /><b>' + XText[rsEmptyFolders] + '</b></td>';
             Result := Result + '</tr>';

             Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '" class="C4G">';
             Result := Result + '<td colspan="7" height="13">' + XText[rsGeneral] + '</td>';
             Result := Result + '</tr>';
             Result := Result + '</table>';

             InsertSpacingTable;
           end;
      CHTMLUsers : begin
             //-----------------------------------------------------------------
             //-- Username -----------------------------------------------------
             //-----------------------------------------------------------------
             Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1">';
             Result := Result + '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result + '<td colspan="7" height="13"><a name="op10" /><b>' + XText[rsUsageByUser] + '</b></td>';
             Result := Result + '<tr>';
             Result := Result + '<tr class="C7G" bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result + '<td width="100" height="13"><b>' + XText[rsSmallestFiles] + '</b></td>';
             Result := Result + '<td width="64" height="13"><div align="center"><b>' + XText[rsQty] + '</b></div></td>';
             Result := Result + '<td width="64" height="13"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result + '<td width="160" height="13">&nbsp;</td>';
             Result := Result + '<td width="85" height="13"><div align="center"><b>' + XText[rsFileSize] + '</b></div></td>';
             Result := Result + '<td width="67" height="13"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result + '<td width="160" height="20">&nbsp;</td>';
             Result := Result + '</tr>';
             Result := Result + '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '">';
             Result := Result + '<td width="100" height="13">Mr. R Andom</td>';
             Result := Result + '<td width="64" height="13"><div align="center">123</div></td>';
             Result := Result + '<td width="64" height="13"><div align="center">24</div></td>';
             Result := Result + '<td width="160">';
             Result := Result + '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(aColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">';
             Result := Result + '<tr><td></td></tr>';
             Result := Result + '</table>';
             Result := Result + '</td>';
             Result := Result + '<td width="85" height="13"><div align="' + alignmode + '">53</div></td>';
             Result := Result + '<td width="67" height="13"><div align="center">25</div></td>';
             Result := Result + '<td width="160">';
             Result := Result + '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(aColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">';
             Result := Result + '<tr><td></td></tr>';
             Result := Result + '</table>';
             Result := Result + '</td>';
             Result := Result + '</tr>';
             Result := Result + '<tr class="C4G" bgcolor="#' + TConvert.WebColor(aColours.Colour[11]) + '">';
             Result := Result + '<td width="100" height="13">Mrs. S Quirrel</td>';
             Result := Result + '<td width="64" height="13"><div align="center">123</div></td>';
             Result := Result + '<td width="64" height="13"><div align="center">24</div></td>';
             Result := Result + '<td width="160">';
             Result := Result + '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(aColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">';
             Result := Result + '<tr><td></td></tr>';
             Result := Result + '</table>';
             Result := Result + '</td>';
             Result := Result + '<td width="85" height="13"><div align="' + alignmode + '">53</div></td>';
             Result := Result + '<td width="67" height="13"><div align="center">25</div></td>';
             Result := Result + '<td width="160">';
             Result := Result + '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(aColours.Colour[5]) + '" height="8" cellpadding="0" cellspacing="0">';
             Result := Result + '<tr><td></td></tr>';
             Result := Result + '</table>';
             Result := Result + '</td>';
             Result := Result + '</tr>';

             InsertSpacingTable;
           end;
      CHTMLNameLength : begin
             //-----------------------------------------------------------------
             //file name length ------------------------------------------------
             //-----------------------------------------------------------------
             Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1">';
             Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
             Result := Result +   '<td width="100" height="13" class="C7G"><a name="op3" /><b>' + XText[rsLength] + '</b></td>';
             Result := Result +   '<td width="64" height="13" class="C7G"><div align="center"><b>' + XText[rsQty] + '</b></div></td>';
             Result := Result +   '<td width="64" height="13" class="C7G"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result +   '<td width="160" height="13">&nbsp;</td>';
             Result := Result +   '<td width="85" height="13" class="C7G"><div align="center"><b>' + XText[rsFileSize] + '</b></div></td>';
             Result := Result +   '<td width="67" height="13" class="C7G"><div align="center"><b>' + XText[rsAsPercent] + '</b></div></td>';
             Result := Result +   '<td width="160" height="20">&nbsp;</td>';
             Result := Result + '</tr>';

             //build the file category table
             for t := 1 to 5 do begin
                 if odd(t) then
                   Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[10]) + '">'
                 else
                   Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[11]) + '">';

                 Result := Result +   '<td width="100" class="C4G"><div align="left">' + IntToStr(t * 5) + '</div></td>';
                 Result := Result +   '<td width="64" class="C4G"><div align="center">' + IntToStr(2 + Random(1300)) + '</div></td>';
                 Result := Result +   '<td width="64" class="C4G"><div align="center">' + IntToStr(2 + Random(80)) + '%</div></td>';
                 Result := Result +   '<td width="160">';
                 Result := Result +     '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(GSystemGlobal.FileCategoryColors[t]) + '" height="8" cellpadding="0" cellspacing="0">';
                 Result := Result +     '<tr><td></td></tr>';
                 Result := Result +     '</table>';
                 Result := Result +   '</td>';
                 Result := Result +   '<td width="85" class="C4G"><div align="' + alignmode + '">1GB</div></td>';
                 Result := Result +   '<td width="67" class="C4G"><div align="center">' + IntToStr(2 + Random(80)) + '%</div></td>';
                 Result := Result +   '<td width="160">';
                 Result := Result +     '<table width="' + IntToStr(2 + Random(130)) + '" border="0" bgcolor="#' + TConvert.WebColor(GSystemGlobal.FileCategoryColors[t]) + '" height="8" cellpadding="0" cellspacing="0">';
                 Result := Result +     '<tr><td></td></tr>';
                 Result := Result +     '</table>';
                 Result := Result +   '</td>';
                 Result := Result + '</tr>';
             end;

             Result := Result + '</table>';

             InsertSpacingTable;
           end;
    end;
 end;

begin
  Result := '';

  menulist := TStringList.Create;

  if aReport.HTMLUnits = 0 then
    alignmode := 'center'
  else
    alignmode := 'right';

  BuildMenuList;

  //----------------------------------------------------------------------------
  //--Lets write the file-------------------------------------------------------
  //----------------------------------------------------------------------------

  Result := Result + '<html><head><title>xinorbis analysis: <strong>p:\review\folder\</strong></title>';
  Result := Result + '<style type="text/css"><!--';
  Result := Result + 'A:link {color:#' + TConvert.WebColor(aColours.Colour[1]) + '; text-decoration: none;}';
  Result := Result + 'A:visited {color:#' + TConvert.WebColor(aColours.Colour[1]) + '; text-decoration: none;}';
  Result := Result + 'A:hover {color:#' + TConvert.WebColor(aColours.Colour[2]) + '; text-decoration: underline;}';
  Result := Result + 'A:active {color:#' + TConvert.WebColor(aColours.Colour[1]) + '; text-decoration: none;}';
  Result := Result + '.C4G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#' + TConvert.WebColor(aColours.Colour[4]) + ';}';
  Result := Result + '.C7G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#' + TConvert.WebColor(aColours.Colour[7]) + ';}';
  Result := Result + '-->';
  Result := Result + '</style></head><body leftmargin="5" bgcolor="#' + TConvert.WebColor(aColours.Colour[3]) + '" text="#' + TConvert.WebColor(aColours.Colour[8]) + '" topmargin="5">';

  s := '';

  for t := 1 to length(aReport.Layout) do begin
    if aReport.Layout[t] = ':' then begin
      if s <> '' then begin
        AddHTMLReportItem(StrToIntDef(s, -1));
      end;

      s := '';
    end
    else
      s := s + aReport.Layout[t];
  end;

  // footer table. always gets added
  Result := Result + '<table align="center" width="770" border="0" cellpadding="1" cellspacing="1">';
  Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '">';
  Result := Result +   '<td align="center" class="C7G">';
  Result := Result +   '<a href="mailto:xinorbis@maximumoctopus.com">xinorbis@maximumoctopus.com</a> / <a href="http://www.xinorbis.com" target="_blank">www.xinorbis.com</a></td>';
  Result := Result + '</tr>';
  Result := Result + '<tr bgcolor="#' + TConvert.WebColor(aColours.Colour[6]) + '" class="C7G"><td align="center">(c) Paul Alan Freshney 2002-' + TUtility.GetCurrentYear + '</td></tr>';
  Result := Result + '</table></body></html>';

  menulist.Free;
end;


end.
