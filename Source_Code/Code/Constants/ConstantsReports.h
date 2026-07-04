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

static const int __AttributesToDisplayCount = 13;    // attributes that are output to reports/screen etc.
static const int __AttributesCount = 21;
static const int __MagnitudesCount = 13;

static const int __HTMLColoursCount = 11;

static const int __rsTableWidth = 0;
static const int __rsBarGraph = 1;
static const int __rsChartDD = 2;
static const int __rsChartCM = 3;
static const int __rsChartCD = 4;
static const int __rsChartXM = 5;
static const int __rsChartFD = 6;
static const int __rsBarGraphSmall = 7;

static const int __FileCategoriesCount = 20;
static const int __FileCategoriesOther = 9;
static const int __FileCategoriesCustom1 = 10;

static const int __TextReportOptionsCount = 11;
static const int __TreeReportOptionsCount = 6;

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

static const int __GraphWidth = 150;

static const int __SpectrumMod = 29;

static const int __ReportSizes[8] = { 1250, 370, 350, 618, 1238, 618, 1238, 152 };  // 1280x mode

static const int __DefaultDisplayColours[__FileCategoriesCount] = { 0xFFFF00, 0x9d9fff, 0x70b7fe, 0x72f1fc, 0x73fcb7, 0xc5fd71, 0xeefc72, 0xfccf72, 0xfc8d72, 0xfe79be,
																	0xfe70f3, 0x99bdd5, 0x8c8c8c, 0xd1d1d1, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff };

static const int __MagnitudeColour[__MagnitudesCount] = { 0x8383FF, 0x83BAFF, 0x83ECFF, 0x83FFCC, 0x92ff83, 0xD5FF83,
														  0xFFFE83, 0xFFCF83, 0xFF9283, 0xFF83Af, 0xFF83F5, 0xFF83F5, 0xFF83F5 };

static const int __SpectrumColours[__SpectrumMod] = { 0x0000FF, 0x0022FF, 0x0054FF, 0x0084FF, 0x00B4FF, 0x00E4FF, 0x00FFA8, 0x00FF36, 0x3EFF00, 0xB0FF00,
													  0xFFFA00, 0xFFDC00, 0xFFBE00, 0xFFA000, 0xFF8200, 0xFF6400, 0xFF4600, 0xFF2800, 0xFF0A00, 0xFF0020,
													  0xFF0050, 0xFF0080, 0xFF00B0, 0xFF00E0, 0xFF02F0, 0xFF05F0, 0xFF08F0, 0xFF0BF0, 0xFF0EF0 };

const static std::wstring DefaultExtensionFileName[__FileCategoriesCount] = {L"Temp", L"Programs", L"System", L"Graphics", L"Movie",
																			 L"Audio", L"Office", L"Programming", L"Compressed", L"Other",
																			 L"Custom1", L"Custom2", L"Custom3", L"Custom4", L"Custom5",
																			 L"Custom6", L"Custom7", L"Custom8", L"Custom9", L"Custom10" };

const static std::wstring __MagnitudeLabels[] = { L"less than 1K", L"1K - 1MB", L"1MB - 10MB", L"10MB - 50MB", L"50MB - 100MB",
												  L"100MB - 150MB", L"150MB - 200MB", L"200MB - 250MB", L"250MB - 500MB", L"500MB - 1GB",
												  L"1GB - 2GB", L"2GB - 5GB", L"5GB+" };

static const std::wstring __MagnitudeLabelsShort[]  = { L"<=1K", L"1K < x <=1MB", L"1MB < x <=10MB", L"10MB < x <=50MB", L"50MB < x <=100MB", L"100MB < x <=150MB",
														L"150MB < x <=200MB", L"200MB < x <=250MB", L"250MB < x <=500MB", L"500MB < x <=1GB", L"1GB < x <=2GB",
														L"2GB < x <=5GB", L">5GB" };

static const int __MagnitudeColours[13] = { 0x8383FF, 0x83BAFF, 0x83ECFF, 0x83FFCC, 0x92ff83, 0xD5FF83, 0xFFFE83, 0xFFCF83, 0xFF9283, 0xFF83AF, 0xFF83F5, 0xFF83F5, 0xFF83F5 };
static const int __GraphColours[13] = { 0x8383FF, 0x83BAFF, 0x83ECFF, 0x83FFCC, 0x92ff83, 0xD5FF83, 0xFFFE83, 0xFFCF83, 0xFF9283, 0xFF83AF, 0xFF83F5, 0xD6D5DB, 0xFFFFFF };



//static const int __DefaultDisplayColours[__FileCategoriesCount] = { 0x9d9fff, 0x70b7fe, 0x72f1fc, 0x73fcb7, 0xc5fd71, 0xeefc72, 0xfccf72, 0xfc8d72, 0xfe79be,
//																	0xfe70f3, 0x99bdd5, 0x8c8c8c, 0xd1d1d1, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff };
//                                                                  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff);

//  graphcolors : array[0..12] of integer = ($8383FF, $83BAFF, $83ECFF, $83FFCC, $92ff83, $D5FF83,
//                                           $FFFE83, $FFCF83, $FF9283, $FF83Af, $FF83F5, $D6D5DB, $FFFFFF);


static const int __GridColVFilename   = 0;
static const int __GridColVSize       = 1;
static const int __GridColVCDate      = 2;
static const int __GridColVADate      = 3;
static const int __GridColVMDate      = 4;
static const int __GridColVOwner      = 5;
static const int __GridColVAttributes = 6;
static const int __GridColIFilename   = 7;
static const int __GridColISize       = 8;
static const int __GridColICDate      = 9;
static const int __GridColIADate      = 10;
static const int __GridColIMDate      = 11;
static const int __GridColIColour     = 12;

static const int kFieldIgnore             = 0;
static const int kFieldFullFilePath       = 1;
static const int kFieldFileSizeBytes      = 2;
static const int kFieldFileSizeOnDIsk     = 3;
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

