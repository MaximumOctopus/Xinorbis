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


static const int __WidthOfScrollbar = 26; // (pixels)

static const int kNullEntry = -1;

static const int kMainPanelIndex            = 0;
static const int kScanSelectionPanelIndex   = 1;
static const int kMainSummaryPanelIndex     = 2;
static const int kMainPropertiesPanelIndex  = 3;
static const int kMainStructurePanelIndex   = 4;
static const int kMainSearchPanelIndex      = 5;
static const int kMainDuplicatesPanelIndex  = 6;
static const int kMainFileHistoryPanelIndex = 7;
static const int kMainReportListPanelIndex  = 8;
static const int kMainWebReportsPanelIndex  = 9;
static const int kMainMapPanelIndex         = 10;
static const int kMainExploderPanelIndex    = 11;
static const int kLogPanelIndex             = 99;

static const int kDBSelectedFolder   = 0;

static const int kTaskSummary = 0;
static const int kTaskProperties = 1;
static const int kTaskStructure = 2;
static const int kTaskSearch = 3;
static const int kTaskMap = 4;
static const int kTaskDuplicatesName = 5;
static const int kTaskDuplicatesSize = 6;
static const int kTaskExploder = 7;

static const int kFormFileSpread     = 1;
static const int kFormReference      = 2;
static const int kFormReport         = 3;
static const int kFormInfoDatabase   = 4;
static const int kFormExplore        = 5;
static const int kFormFileAges       = 6;
static const int kFormCombine        = 7;
static const int kFormDeplicates     = 8;
static const int kFormDuplicates     = 9;
static const int kFormReportsList    = 10;
static const int kFormSearchSyntax   = 11;

static const int kFormEditHTMLReport = 20;
static const int kFormEditTextReport = 21;
static const int kFormEditTreeReport = 22;
static const int kFormEditXMLReport  = 23;
static const int kFormEditCSVReport  = 24;

static const int kTabIndexCategories    = 0;
static const int kTabIndexTypes         = 1;
static const int kTabIndexExtensions    = 2;
static const int kTabIndexFolders       = 3;
static const int kTabIndexMagnitude     = 4;
static const int kTabIndexDates         = 5;
static const int kTabIndexHistory       = 6;
static const int kTabIndexTop101        = 7;
static const int kTabIndexNull          = 8;
static const int kTabIndexUsers         = 9;
static const int kTabIndexTemp          = 10;
static const int kTabNavigation         = 12;
static const int kTabIndexDatesCreated  = 13;
static const int kTabIndexDatesAccessed = 14;
static const int kTabIndexDatesModified = 15;
static const int kTabIndexNameLength    = 16;

static const int kTabFHMainStats        = 0;
static const int kTabFHMainSearch       = 1;

static const int kTabFHChart            = 0;
static const int kTabFHTable            = 1;
static const int kTabFHTimeLine         = 2;

static const int kTabFHCompare          = 0;
static const int kTabFHCompareDiff      = 1;
static const int kTabFHCompareTree      = 2;

static const int kTabDisplayOptionTree    = 2;
static const int kTabDisplayOptionLengths = 3;

static const int kWindowAnalysisProgress = 0;
static const int kWindowZipProgress      = 1;

static const int kReportIconOffStart = 9;

// folder structure
static const int kLeftOptions  = 0;
static const int kRightOptions = 1;

static const int ksgnIsFolder      = 0;
static const int ksgnFileName      = 1;
static const int ksgnStringSize    = 2;
static const int ksgnGraphSize     = 3;
static const int ksgnStringPCent   = 4;
static const int ksgnCreatedDate   = 5;
static const int ksgnAccessedDate  = 6;
static const int ksgnModifiedDate  = 7;
static const int ksgnUserName      = 8;
static const int ksgnAttributes    = 9;
static const int ksgnSizeOnDisk    = 10;
static const int ksgnIntegerPCent  = 11;
static const int ksgnFolderFile    = 12;
static const int ksgnOrderIndex    = 13;
static const int ksgnIntegerSize   = 14;
static const int ksgnCategoryIndex = 15;
static const int ksgnIntegetSoD    = 16;

//

static const int kChartTypeUnknown    = 0;
static const int kChartTypePie        = 1;
static const int kChartTypeBar        = 2;
static const int kChartTypeHorizontal = 3;

  //                                   glyph,column
static const int TableColumnLookup[56] = { 2,3, 3,4, 4,5, 5,6,              	//  0-3  = search page
										   1,3, 2,4, 3,5, 4,6, 5,7, 6, 2,   	//  4-9  = FH Compare Left
										   1,3, 2,4, 3,5, 4,6, 5,7, 6, 2,   	// 10-15 = FH Compare Right
										   1,5, 2,6, 3,7, 4,8, 5,9, 6, 10,   	// 16-21 = navigation left
										   1,5, 2,6, 3,7, 4,8, 5,9, 6, 10  };	// 22-27 = navigation side

static const int kGridColourOn = 0x00666666;
static const int kGridColourOff = 0x00444444;
static const int kGridColourSelected = 0x00664422;
static const int kGridHeader = 0x00444444;
