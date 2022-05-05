{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CReportOptions;

interface

uses
  X.CReportColours;


const
  CLayout800x600  = 1;
  CLayout1024x768 = 2;
  CLayout1280x960 = 3;


type
  THTMLReportOptions     = record
                             Filename      : string;
                             HTMLUnits     : integer;
                             HTMLAlign     : string;
                             Layout        : string;
                             LayoutSize    : integer;  // 1 = 800x600, 2 = 1024x768, 3 = 1280x960
                             CategoryList  : string;
                             HTMLAutoOpen  : boolean;

                             HTMLColours   : THTMLColours;

                             Special       : string;
                           end;

  TTextReportOptions     = record
                             Filename     : string;
                             Layout       : string;
                             CategoryList : string;
                             TextAutoOpen : boolean;

                             Special      : string;
                           end;

  TXMLReportOptions      = record
                             Filename        : string;
                             XMLData         : integer; // 0 or 1
                             XMLAutoOpen     : boolean;
                             XMLOutputOption : array[1..10] of boolean;
                             Layout          : string;

                             Special         : string;
                           end;

  TXinorbisReportOptions = record
                             Filename : string;
                             Layout   : integer;
                             XinorbisAutoOpen : boolean;
                          end;

  TTreeReportOptions     = record
                             Filename          : string;
                             Layout            : string;
                             IncludeSize       : boolean;
                             IncludeAttributes : boolean;
                             CategoryList      : string;
                             TreeAutoOpen      : boolean;
                           end;

  THTMLCompareOptions    = record
                             Filename      : string;
                             HTMLUnits     : integer;
                             Layout        : string;
                             LayoutSize    : integer;  // 1 = 800x600, 2 = 1024x768, 3 = 1280x960

                             HTMLColours   : THTMLColours;
                           end;

  TCSVReportOptions     = record
                             Filename     : string;
                             CSVSeparator : integer;
                             CSVData      : integer; // 0 or 1
                             CSVUnits     : integer;
                             CSVTitles    : boolean;
                             CSVAutoOpen  : boolean;
                             Category     : integer; //0-14 or -1 for ALL
                             Layout       : string;

                             Special      : string;
                           end;

const
  CDataSummary       = 0;
  CDataFileList      = 1;

  CSVSeparatorComma  = 0;
  CSVSeparatorTab    = 1;
  CSVSeparatorPling  = 2;

  CSVUnitsConvenient = 0;
  CSVUnitsBytes      = 1;
  CSVUnitsKilobytes  = 2;
  CSVUnitsMegabytes  = 3;

  CHTMLHeader        = 1;
  CHTMLQuick         = 2;
  CHTMLFAT           = 3;
  CHTMLCategory      = 4;
  CHTMLFolders       = 5;
  CHTMLMagnitude     = 6;
  CHTMLExtensions    = 7;
  CHTMLNullFiles     = 8;
  CHTMLDatesC        = 9;
  CHTMLDatesA        = 10;
  CHTMLDatesM        = 11;
  CHTMLUsers         = 12;
  CHTMLLargest       = 13;
  CHTMLSmallest      = 14;
  CHTMLNewest        = 15;
  CHTMLOldest        = 16;
  CHTMLNameLength    = 17;

  CXMLSummary        = 2;
  CXMLAttributes     = 3;
  CXMLCategory       = 4;
  CXMLFolders        = 5;
  CXMLMagnitude      = 6;
  CXMLExtensions     = 7;
  CXMLNullFiles      = 8;
  CXMLDatesC         = 9;
  CXMLDatesA         = 10;
  CXMLDatesM         = 11;
  CXMLUsers          = 12;
  CXMLLargest        = 13;
  CXMLSmallest       = 14;
  CXMLNewest         = 15;
  CXMLOldest         = 16;
  CXMLNameLength     = 17;

  CTextHeader        = 1;
  CTextSummary       = 2;
  CTextAttributes    = 3;
  CTextCategory      = 4;
  CTextFolders       = 5;
  CTextMagnitude     = 6;
  CTextExtensions    = 7;
  CTextNullFiles     = 8;
  CTextDatesC        = 9;
  CTextDatesA        = 10;
  CTextDatesM        = 11;
  CTextUsers         = 12;
  CTextLargest       = 13;
  CTextSmallest      = 14;
  CTextNewest        = 15;
  CTextOldest        = 16;
  CTextNameLength    = 17;


implementation


end.
