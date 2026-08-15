// =====================================================================
//
//   Xinorbis 10.0
//
// (c) Paul Alan Freshney 2002-2026
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/Xinorbis
//
// =====================================================================

#pragma once

static const int kAttributesToDisplayCount = 13;    // attributes that are output to reports/screen etc.
static const int kAttributesCount = 21;
static const int kMagnitudesCount = 13;

static const int kHTMLColoursCount = 11;
static const int kHTMLItemsCount = 17;

static const int kTextItemsCount = 17;
static const int kXMLItemsCount = 17;

static const int kMaxCSVFields = 20;

static const int kReportLayoutUnknown = 0;
static const int kReportLayoutAutoSave = 1;
static const int kReportLayoutQuick    = 2;
static const int kReportLayoutSaveAs   = 3;
static const int kReportLayoutCustom1  = 4;
static const int kReportLayoutCustom2  = 5;

static const int kReportTypeCSV       = 0;
static const int kReportTypeDate      = 1;
static const int kReportTypeHTML      = 2;
static const int kReportTypeJSON      = 3;
static const int kReportTypeText      = 4;
static const int kReportTypeTree      = 5;
static const int kReportTypeXinorbis  = 6;
static const int kReportTypeXinorbis2 = 7;
static const int kReportTypeXML       = 8;
static const int kReportTypeUnknown   = 99;

static const int kTableWidth = 0;
static const int kBarGraph = 1;
static const int kChartDD = 2;
static const int kChartCM = 3;
static const int kChartCD = 4;
static const int kChartXM = 5;
static const int kChartFD = 6;
static const int kBarGraphSmall = 7;

static const int kFileCategoriesCount = 20;
static const int kFileCategoriesOther = 9;
static const int kFileCategoriesCustom1 = 10;

static const int kTextReportOptionsCount = 11;
static const int kTreeReportOptionsCount = 6;

static const int kSelectionQuantity = 1;
static const int kSelectionSize     = 2;

static const int kLabelOptionDefault        = 0;
static const int kLabelOptionMostConvenient = 1;
static const int kLabelOptionKilobyte       = 2;
static const int kLabelOptionMegabyte       = 3;
static const int kLabelOptionGigabyte       = 4;

static const int kIntervalDay               = 0;
static const int kIntervalWeek              = 1;
static const int kIntervalMonth             = 2;
static const int kIntervalYear              = 3;
static const int kIntervalHour              = 4;

static const int kGraphWidth = 150;

static const int kSpectrumMod = 29;

static const int kReportSizes[8] = { 1250, 370, 350, 618, 1238, 618, 1238, 152 };  // 1280x mode

static const int kDefaultDisplayColours[kFileCategoriesCount] = { 0xFFFF00, 0x9d9fff, 0x70b7fe, 0x72f1fc, 0x73fcb7, 0xc5fd71, 0xeefc72, 0xfccf72, 0xfc8d72, 0xfe79be,
																  0xfe70f3, 0x99bdd5, 0x8c8c8c, 0xd1d1d1, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff };

static const int kMagnitudeColour[kMagnitudesCount] = { 0x8383FF, 0x83BAFF, 0x83ECFF, 0x83FFCC, 0x92ff83, 0xD5FF83,
														0xFFFE83, 0xFFCF83, 0xFF9283, 0xFF83Af, 0xFF83F5, 0xFF83F5, 0xFF83F5 };

static const int kSpectrumColours[kSpectrumMod] = { 0x0000FF, 0x0022FF, 0x0054FF, 0x0084FF, 0x00B4FF, 0x00E4FF, 0x00FFA8, 0x00FF36, 0x3EFF00, 0xB0FF00,
													0xFFFA00, 0xFFDC00, 0xFFBE00, 0xFFA000, 0xFF8200, 0xFF6400, 0xFF4600, 0xFF2800, 0xFF0A00, 0xFF0020,
													0xFF0050, 0xFF0080, 0xFF00B0, 0xFF00E0, 0xFF02F0, 0xFF05F0, 0xFF08F0, 0xFF0BF0, 0xFF0EF0 };

const static std::wstring DefaultExtensionFileName[kFileCategoriesCount] = {L"Temp", L"Programs", L"System", L"Graphics", L"Movie",
																			 L"Audio", L"Office", L"Programming", L"Compressed", L"Other",
																			 L"Custom1", L"Custom2", L"Custom3", L"Custom4", L"Custom5",
																			 L"Custom6", L"Custom7", L"Custom8", L"Custom9", L"Custom10" };

const static std::wstring kMagnitudeLabels[] = { L"less than 1K", L"1K - 1MB", L"1MB - 10MB", L"10MB - 50MB", L"50MB - 100MB",
												  L"100MB - 150MB", L"150MB - 200MB", L"200MB - 250MB", L"250MB - 500MB", L"500MB - 1GB",
												  L"1GB - 2GB", L"2GB - 5GB", L"5GB+" };

static const std::wstring kMagnitudeLabelsShort[]  = { L"<=1K", L"1K < x <=1MB", L"1MB < x <=10MB", L"10MB < x <=50MB", L"50MB < x <=100MB", L"100MB < x <=150MB",
														L"150MB < x <=200MB", L"200MB < x <=250MB", L"250MB < x <=500MB", L"500MB < x <=1GB", L"1GB < x <=2GB",
														L"2GB < x <=5GB", L">5GB" };

static const int kMagnitudeColours[13] = { 0x8383FF, 0x83BAFF, 0x83ECFF, 0x83FFCC, 0x92ff83, 0xD5FF83, 0xFFFE83, 0xFFCF83, 0xFF9283, 0xFF83AF, 0xFF83F5, 0xFF83F5, 0xFF83F5 };
static const int kGraphColours[13] = { 0x8383FF, 0x83BAFF, 0x83ECFF, 0x83FFCC, 0x92ff83, 0xD5FF83, 0xFFFE83, 0xFFCF83, 0xFF9283, 0xFF83AF, 0xFF83F5, 0xD6D5DB, 0xFFFFFF };



//static const int __DefaultDisplayColours[__FileCategoriesCount] = { 0x9d9fff, 0x70b7fe, 0x72f1fc, 0x73fcb7, 0xc5fd71, 0xeefc72, 0xfccf72, 0xfc8d72, 0xfe79be,
//																	0xfe70f3, 0x99bdd5, 0x8c8c8c, 0xd1d1d1, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff };
//                                                                  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff);

//  graphcolors : array[0..12] of integer = ($8383FF, $83BAFF, $83ECFF, $83FFCC, $92ff83, $D5FF83,
//                                           $FFFE83, $FFCF83, $FF9283, $FF83Af, $FF83F5, $D6D5DB, $FFFFFF);


static const int kGridColVFilename   = 0;
static const int kGridColVSize       = 1;
static const int kGridColVCDate      = 2;
static const int kGridColVADate      = 3;
static const int kGridColVMDate      = 4;
static const int kGridColVOwner      = 5;
static const int kGridColVAttributes = 6;
static const int kGridColIFilename   = 7;
static const int kGridColISize       = 8;
static const int kGridColICDate      = 9;
static const int kGridColIADate      = 10;
static const int kGridColIMDate      = 11;
static const int kGridColIColour     = 12;

static const int kFieldIgnore             = 0;
static const int kFieldFullFilePath       = 1;
static const int kFieldFileSizeBytes      = 2;
static const int kFieldFileSizeOnDisk     = 3;
static const int kFieldCreatedDDMMYYYY    = 4;
static const int kFieldCreatedMMDDYYYY    = 5;
static const int kFieldModifiedDDMMYYYY   = 6;
static const int kFieldModifiedMMDDYYYY   = 7;
static const int kFieldAccessedDDMMYYYY   = 8;
static const int kFieldAccessedMMDDYYYY   = 9;
static const int kFieldFilePath           = 10;
static const int kFieldFileName           = 11;
static const int kFieldOwner              = 12;
static const int kFieldCategory           = 13;
static const int kFieldReadOnly           = 14;
static const int kFieldHidden             = 15;
static const int kFieldSystem             = 16;
static const int kFieldArchive            = 17;
static const int kFieldTemp               = 18;
static const int kFieldAttributes         = 19;
static const int kFieldCreatedTimeHHMMSS  = 20;
static const int kFieldModifiedTimeHHMMSS = 21;
static const int kFieldAccessedTimeHHMMSS = 22;


static const int kDataSummary       = 0;
static const int kDataFileList      = 1;

static const int kCSVSeparatorComma  = 0;
static const int kCSVSeparatorTab    = 1;
static const int kCSVSeparatorPling  = 2;

static const int kCSVUnitsConvenient = 0;
static const int kCSVUnitsBytes      = 1;
static const int kCSVUnitsKilobytes  = 2;
static const int kCSVUnitsMegabytes  = 3;

static const int kHTMLHeader        = 1;
static const int kHTMLQuick         = 2;
static const int kHTMLFAT           = 3;
static const int kHTMLCategory      = 4;
static const int kHTMLFolders       = 5;
static const int kHTMLMagnitude     = 6;
static const int kHTMLExtensions    = 7;
static const int kHTMLNullFiles     = 8;
static const int kHTMLDatesC        = 9;
static const int kHTMLDatesA        = 10;
static const int kHTMLDatesM        = 11;
static const int kHTMLUsers         = 12;
static const int kHTMLLargest       = 13;
static const int kHTMLSmallest      = 14;
static const int kHTMLNewest        = 15;
static const int kHTMLOldest        = 16;
static const int kHTMLNameLength    = 17;

static const int kXMLSummary        = 2;
static const int kXMLAttributes     = 3;
static const int kXMLCategory       = 4;
static const int kXMLFolders        = 5;
static const int kXMLMagnitude      = 6;
static const int kXMLExtensions     = 7;
static const int kXMLNullFiles      = 8;
static const int kXMLDatesC         = 9;
static const int kXMLDatesA         = 10;
static const int kXMLDatesM         = 11;
static const int kXMLUsers          = 12;
static const int kXMLLargest        = 13;
static const int kXMLSmallest       = 14;
static const int kXMLNewest         = 15;
static const int kXMLOldest         = 16;
static const int kXMLNameLength     = 17;

static const int kTextHeader        = 1;
static const int kTextSummary       = 2;
static const int kTextAttributes    = 3;
static const int kTextCategory      = 4;
static const int kTextFolders       = 5;
static const int kTextMagnitude     = 6;
static const int kTextExtensions    = 7;
static const int kTextNullFiles     = 8;
static const int kTextDatesC        = 9;
static const int kTextDatesA        = 10;
static const int kTextDatesM        = 11;
static const int kTextUsers         = 12;
static const int kTextLargest       = 13;
static const int kTextSmallest      = 14;
static const int kTextNewest        = 15;
static const int kTextOldest        = 16;
static const int kTextNameLength    = 17;

// these values are preserved from previous versions of Xinorbis
static const int kScanSourceLive             = 0;
static const int kScanSourceFileXinNormal    = 1;
static const int kScanSourceFileCSV          = 2;
static const int kScanSourceFileXinDetailed  = 3;
static const int kScanSourceLiveShare        = 4;
static const int kScanSourceFolderHistory    = 5;
static const int kScanSourceSearchResults    = 6;
static const int kScanSourceFileXin2Detailed = 7;
