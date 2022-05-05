unit X.CReportOptions;

interface


type
  THTMLReportOptions     = record
                             Filename      : string;
                             HTMLUnits     : integer;
                             HTMLAlign     : string;
                             Layout        : string;
                             LayoutSize    : integer;  // 1 = 800x600, 2 = 1024x768, 3 = 1280x960
                             CategoryList  : string;
                             HTMLAutoOpen  : boolean;
                           end;

  TTextReportOptions    = record
                            Filename     : string;
                            Layout       : string;
                            CategoryList : string;
                            TextAutoOpen : boolean;
                          end;

  TXMLReportOptions      = record
                             Filename        : string;
                             XMLData         : integer;
                             XMLAutoOpen     : boolean;
                             XMLOutputOption : array[1..10] of boolean;
                             Layout          : string;
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
                           end;

  TCSVReportOptions     = record
                             Filename     : string;
                             CSVSeparator : integer;
                             CSVData      : integer;
                             CSVUnits     : integer;
                             CSVTitles    : boolean;
                             CSVAutoOpen  : boolean;
                             Category     : integer; //0-14 or -1 for ALL
                             Layout       : string;
                           end;


implementation


end.
