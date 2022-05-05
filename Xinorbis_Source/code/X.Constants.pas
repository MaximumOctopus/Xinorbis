unit X.Constants;


interface


const
   x8Version = '8.3.1';
   x8Date    = 'February 24th 2020';

  {$ifdef CPUX64}
     x8Title   = x8Version + ' (x64)';
  {$else}
     x8Title   = x8Version + ' (x32)';
  {$endif}

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  CCharacter_1 = 48;
  CCharacter_2 = 49;
  CCharacter_3 = 50;

  // ===========================================================================
  // == Scanning ===============================================================
  // ===========================================================================

  ScanTypeNormal             = 0;
  ScanTypeRefresh            = 1;
  ScanTypeSearch             = 2;

  ScanSourceLive             = 0;
  ScanSourceFileXinNormal    = 1;
  ScanSourceFileCSV          = 2;
  ScanSourceFileXinDetailed  = 3;
  ScanSourceLiveShare        = 4;
  ScanSourceFolderHistory    = 5;
  ScanSourceSearchResults    = 6;
  ScanSourceFileXin2Detailed = 7;

  Xin2SectionInfo            = 0;
  Xin2SectionFolders         = 1;
  Xin2SectionFile            = 2;
  Xin2SectionUnknown         = 99;

  XinorbisLayoutNormal   = 0;
  XinorbisLayoutDetailed = 1;

  dataLatestScan    = 0;
  dataFolderHistory = 1;
  dataSearch        = 2;

  XFileUsed    = 1; // actual size
  XSpaceUsed   = 2; // total of space used (including wasted sector(s))
  XCount       = 3;

  XFileCount   = 1;
  XFolderCount = 2;
  XFileSize    = 3;
  XRootCount   = 0;
  XRootSize    = 1;
  XUserCount   = 1;
  XUserSize    = 2;

  XLeftSide    = 1;
  XRightSide   = 2;

  CPostScanNothing      = 0;
  CPostScanSummary      = 1;
  CPostScanInformation  = 2;
  CPostScanStructure    = 3;

  // ===========================================================================
  // == Panels etc. =============================================================
  // ===========================================================================

  JustInTimeCount            = 18;

  pMainPanelIndex            = 0;
  pScanSelectionPanelIndex   = 1;
  pMainSummaryPanelIndex     = 2;
  pMainReportsPanelIndex     = 3;
  pMainNavigationPanelIndex  = 4;
  pMainSearchPanelIndex      = 5;
  pMainFileHistoryPanelIndex = 6;
  pMainReportListPanelIndex  = 7;
  pMainWebReportsPanelIndex  = 8;
  pMainMapPanelIndex         = 9;
  pMainExploderPanelIndex    = 10;
  pLogPanelIndex             = 99;

  // ===========================================================================
  // == Registry ===============================================================
  // ===========================================================================

  XinorbisRegistryKey = 'maximumoctopus\Xinorbis8';

  // ===========================================================================
  // == Grids ==================================================================
  // ===========================================================================

  _WidthOfScrollbar = 22;

  TableGraphBackground = $F5FFFF;

//  CGridColourOn       = $00F9F5F2;
//  CGridColourOff      = $00FFFFFF;
  CGridColourOn       = $00666666;
  CGridColourOff      = $00444444;
  CGridColourSelected = $00888888;
  CGridTextColour     = $00000000;

  sgnIsFolder      = 0;
  sgnFileName      = 1;
  sgnStringSize    = 2;
  sgnGraphSize     = 3;
  sgnStringPCent   = 4;
  sgnCreatedDate   = 5;
  sgnAccessedDate  = 6;
  sgnModifiedDate  = 7;
  sgnUserName      = 8;
  sgnAttributes    = 9;
  sgnSizeOnDisk    = 10;
  sgnIntegerPCent  = 11;
  sgnFolderFile    = 12;
  sgnOrderIndex    = 13;
  sgnIntegerSize   = 14;
  sgnCategoryIndex = 15;
  sgnIntegetSoD    = 16;

  schVFilename     = 0;
  schVSize         = 1;
  schVCDate        = 2;
  schVADate        = 3;
  schVMDate        = 4;
  schVOwner        = 5;
  schVAttributes   = 6;
  schIFilename     = 7;
  schISize         = 8;
  schICDate        = 9;
  schIADate        = 10;
  schIMDate        = 11;
  schIColour       = 12;

  FHschFilename       = 0;
  FHschSize           = 1;
  FHschSizeOnDisk     = 2;
  FHschCreated        = 3;
  FHschAccessed       = 4;
  FHschModified       = 5;
  FHschOwner          = 6;
  FHschStatus         = 7;
  FHschCategory       = 8;
  FHschSortSize       = 9;
  FHschSortSizeOnDisk = 10;
  FHschSortCreated    = 11;
  FHschSortAccessed   = 12;
  FHschSortModified   = 13;

  fhscModeSaveAll     = 0;
  fhscModeSaveDo      = 1;
  fhscModeSaveDont    = 2;

  fFilePath      = 0;
  fFileName      = 1;
  fFileSize      = 2;
  fFileSizeDisk  = 3;
  fFileDateC     = 4;
  fFileDateA     = 5;
  fFileDateM     = 6;
  fCategory      = 7;
  fDirectory     = 8;
  fReadonly      = 9;
  fHidden        = 10;
  fSystem        = 11;
  fArchive       = 12;
  fTemp          = 13;
  fOwner         = 14;

  CMagnitude1          = 0;
  CMagnitude2          = 1;
  CMagnitude3          = 2;
  CMagnitude4          = 3;
  CMagnitude5          = 4;
  CMagnitude6          = 5;
  CMagnitude7          = 6;
  CMagnitude8          = 7;
  CMagnitude9          = 8;
  CMagnitude10         = 9;
  CMagnitude11         = 10;
  CMagnitude12         = 11;
  CMagnitude13         = 12;

  //                                        glyph,column
  TableColumnLookup: array[0..55] of word = (2,3, 3,4, 4,5, 5,6,              //  0-3  = search page
                                             1,3, 2,4, 3,5, 4,6, 5,7, 6, 2,   //  4-9  = FH Compare Left
                                             1,3, 2,4, 3,5, 4,6, 5,7, 6, 2,   // 10-15 = FH Compare Right
                                             1,5, 2,6, 3,7, 4,8, 5,9, 6,10,   // 16-21 = navigation left
                                             1,5, 2,6, 3,7, 4,8, 5,9, 6,10);  // 22-27 = navigation side

  // ===========================================================================
  // ==  Grid widths                                                          ==
  // ===========================================================================

  columnSpacer =   6;
  columnIcon   =  18;
  columnSize   =  70;
  columnSizeOD =  70;
  columnDate   =  70;
  columnOwner  = 100;
  columnState  =  55;

  // ===========================================================================
  // == Reports ================================================================
  // ===========================================================================

  ReportSizes : array[0..3, 0..6] of integer = (( 960, 230, 392, 470,  950, 470,  950),   // 1024x mode
                                                ( 770, 150, 310, 380,  766, 380,  766),   // 800x  mode
                                                ( 960, 230, 392, 470,  950, 470,  950),   // 1024x mode
                                                (1250, 240, 496, 608, 1225, 608, 1225));  // 1280x mode

  LayoutUnknown  = 0;
  LayoutAutoSave = 1;
  LayoutQuick    = 2;
  LayoutSaveAs   = 3;
  LayoutCustom1  = 4;
  LayoutCustom2  = 5;

  HTMLColoursCount  = 11;
  ReportTypesCount  = 5;
  QuickFolderCount  = 20;
  ChartCount        = 19;
  ftpOptionsCount   = 6;

  SaveLocationRegistry  = False;
  SaveLocationConfigIni = True;
  AutoSaveItemCount     = 6;

  MaximumFolderHistory = 25;

  ProgressUpdates : array[0..5, 1..2] of integer = (( 30,   500),
                                                    ( 20,  2000),
                                                    ( 10,  5000),
                                                    (  6, 10000),
                                                    (  4, 20000),
                                                    (  1, 40000));

  __AttributesToDisplayCount = 13;    // number of file attributes
  __AttributesTotalCount     = 20;
  __MagnitudesCount          = 12;

  ReportASCII      = 1;
  ReportCSV        = 2;
  ReportHTML       = 3;
  ReportText       = 4;
  ReportTree       = 5;
  ReportXinorbis   = 6;
  ReportXML        = 7;
  ReportSummary    = 8;

  rsTableWidth = 0;
  rsBarGraph   = 1;
  rsChartDD    = 2;
  rsChartCM    = 3;
  rsChartCD    = 4;
  rsChartXM    = 5;
  rsChartFD    = 6;

  // ===========================================================================
  // == Categories =============================================================
  // ===========================================================================

  __FileCategoriesCount = 19;
  __FileCategoriesOther = 9;

  Category_Temp         = 0;
  Category_MagnitudeAll = 0;

  Category_Program      = 1;
  Category_System       = 2;
  Category_Graphics     = 3;
  Category_Movie        = 4;
  Category_Sound        = 5;
  Category_Office       = 6;
  Category_Code         = 7;
  Category_Compressed   = 8;
  Category_Other        = 9;
  Category_Custom_1     = 10;
  Category_Custom_2     = 11;
  Category_Custom_3     = 12;
  Category_Custom_4     = 13;
  Category_Custom_5     = 14;
  Category_Custom_6     = 15;
  Category_Custom_7     = 16;
  Category_Custom_8     = 17;
  Category_Custom_9     = 18;
  Category_Custom_10    = 19;
  Category_Custom_All   = 99;

  // ===========================================================================
  // == Language ===============================================================
  // ===========================================================================

  LanguageUK        =  0;
  LanguageNL        =  1;
  LanguageFR        =  2;
  LanguageDE        =  3;
  LanguageIT        =  4;
  LanguagePT        =  5;
  LanguageES        =  6;
  LanguageSW        =  7;
  LanguageCZ        =  8;
  LanguageHU        =  9;
  LanguageUS        = 10;
  LanguageRU        = 11;
  LanguageCAT       = 12;
  LanguageUNDEFINED = 99;

  // ===========================================================================
  // == File Types =============================================================
  // ===========================================================================

  faSparseFile         = 512;
  faReparsePoint       = 1024;
  faCompressed         = 2048;
  faOffline            = 4096;
  faNotContentI        = 8192;
  faEncrypted          = 16384;
  faRecallOnOpen       = 262144;
  faRecallOnDataAccess = 4194304;

  FileType_NullFolder         = 0;
  FileType_Hidden             = 1;
  FileType_System             = 2;
  FileType_Archive            = 3;
  FileType_Null               = 4;
  FileType_ReadOnly           = 5;
  FileType_Compressed         = 6;
  FileType_Encrypted          = 7;
  FileType_RecallOnOpen       = 8;
  FileType_RecallOnDataAccess = 9;
  FileType_Offline            = 10;
  FileType_CreatedToday       = 11;
  FileType_AccessedToday      = 12;
  FileType_ModifiedToday      = 13;

  FileType_Temp               = 14;
  FileType_Folder             = 15;
  FileType_File               = 16;
  FileType_NoExtension        = 17;
  FileType_SparseFile         = 18;
  FileType_Reparsepoint       = 19;
  FileType_NotContentI        = 20;

  FileType_Virtual            = 21;

  // ===========================================================================
  // == Tabs ===================================================================
  // ===========================================================================

  TabIndexMain          = 0;
  TabIndexTypes         = 1;
  TabIndexExtensions    = 2;
  TabIndexFolder        = 3;
  TabIndexMagnitude     = 4;
  TabIndexDates         = 5;
  TabIndexHistory       = 6;
  TabIndexTop50         = 7;
  TabIndexNull          = 8;
  TabIndexUsers         = 9;
  TabIndexTemp          = 10;
  TabNavigation         = 12;
  TabIndexDatesCreated  = 13;
  TabIndexDatesAccessed = 14;
  TabIndexDatesModified = 15;
  TabIndexNameLength    = 16;

  TabFHMainStats        = 0;
  TabFHMainSearch       = 1;

  TabFHChart            = 0;
  TabFHTable            = 1;
  TabFHTimeLine         = 2;

  TabFHCompare          = 0;
  TabFHCompareDiff      = 1;
  TabFHCompareTree      = 2;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  CHandleMultipleExtOption1 = 0;
  CHandleMultipleExtOption2 = 1;
  CHandleMultipleExtOption3 = 2;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  ftpHost          = 1;
  ftpUsername      = 2;
  ftpPassword      = 3;
  ftpRemoteFolder  = 4;
  ftpActualLink    = 5;
  ftpInitialFolder = 6;

  unitKB = 0;
  unitMB = 1;
  unitGB = 2;
  unitTB = 3;

  spectrummod = 29;// (0 - 28);

  magnicolors     : array[0..__MagnitudesCount] of integer = ($8383FF, $83BAFF, $83ECFF, $83FFCC, $92ff83, $D5FF83,
                                                          $FFFE83, $FFCF83, $FF9283, $FF83Af, $FF83F5, $FF83F5, $FF83F5);

//  graphcolors : array[0..12] of integer = ($8383FF, $83BAFF, $83ECFF, $83FFCC, $92ff83, $D5FF83,
//                                           $FFFE83, $FFCF83, $FF9283, $FF83Af, $FF83F5, $D6D5DB, $FFFFFF);

  spectrumcolours : array[0..spectrummod - 1] of integer = ($0000FF, $0022FF, $0054FF, $0084FF, $00B4FF, $00E4FF, $00FFA8, $00FF36, $3EFF00, $B0FF00,
                                                            $FFFA00, $FFDC00, $FFBE00, $FFA000, $FF8200, $FF6400, $FF4600, $FF2800, $FF0A00, $FF0020,
                                                            $FF0050, $FF0080, $FF00B0, $FF00E0, $FF02F0, $FF05F0, $FF08F0, $FF0BF0, $FF0EF0);

  DefaultDisplayColours : array[1..__FileCategoriesCount] of integer = ($9d9fff, $70b7fe, $72f1fc, $73fcb7, $c5fd71, $eefc72, $fccf72, $fc8d72, $fe79be,
                                                                        $fe70f3, $99bdd5, $8c8c8c, $d1d1d1, $ffffff, $ffffff, $ffffff, $ffffff, $ffffff, $ffffff);
//                                                                      $ffffff, $ffffff, $ffffff, $ffffff, $ffffff, $ffffff, $ffffff, $ffffff, $ffffff, $ffffff);

  defaultextfn : array[0..__FileCategoriesCount] of string = ('Temp', 'Programs', 'System', 'Graphics', 'Movie', 'Audio', 'Office', 'Programming', 'Compressed', 'Other',
                                                              'Custom1', 'Custom2', 'Custom3', 'Custom4', 'Custom5', 'Custom6', 'Custom7', 'Custom8', 'Custom9', 'Custom10');
 //                                                            'Custom11', 'Custom12', 'Custom13', 'Custom14', 'Custom15', 'Custom16', 'Custom17', 'Custom18', 'Custom19', 'Custom20');

  XPieChart = 0;
  XBarChart = 1;

  ChartGradientSelection : array[0..9] of integer = ($c0c0ff, $c0ffff, $c1ddff, $c0ffc0, $ffffc0, $ffc0ff, $ffc0c0, $ffffff, $c0c0c0, $000000);

  GETTIMEFORMAT_DISPLAY   = 0;
  GETTIMEFORMAT_FILE      = 1;
  GETTIMEFORMAT_YYYYMMDD  = 2;
  GETTIMEFORMAT_SLASH     = 3;

  FileCategoryDirectory = 0;

  ProgressLevelMax      = 0;
  ProgressLevel1        = 1;
  ProgressLevel2        = 2;
  ProgressLevel3        = 3;
  ProgressLevel4        = 4;
  ProgressLevelMin      = 5;

  // == form constants for loading/saving dimensions etc. ========================

  _DBSelectedFolder           = 0;

  _FormFileSpread             = 1;
  _FormReference              = 2;
  _FormReport                 = 3;
  _FormInfoDatabase           = 4;
  _FormExplore                = 5;
  _FormFileAges               = 6;
  _FormCombine                = 7;
  _FormDeplicates             = 8;
  _FormDuplicates             = 9;
  _FormReportsList            = 10;
  _FormSearchSyntax           = 11;

  _FormEditHTMLReport         = 20;
  _FormEditTextReport         = 21;
  _FormEditTreeReport         = 22;
  _FormEditXMLReport          = 23;
  _FormEditCSVReport          = 24;

  // =============================================================================

  NullEntry = -1;

implementation


end.
