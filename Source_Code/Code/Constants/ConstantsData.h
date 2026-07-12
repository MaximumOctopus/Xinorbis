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


enum class DateTimeFormat { Display = 0, File = 1, YYYYMMDD = 2, Slash = 3, HHMM = 4};
enum class DateFormat { kSlashDDMMYYYY = 0, kSlashMMDDYYYY, kSlashYYYYMMDD, kHyphenDDMMYYYY, kHyphenMMDDYYYY };

static const int kAttributesToDisplayCount = 13;    // number of file attributes
static const int kAttributesTotalCount     = 21;
static const int kMagnitudesCount          = 13;

static const int kHTMLColoursCount = 11;
static const int kReportTypeCount  =  6;
static const int kQuickFolderCount = 20;
static const int kChartCount       = 19;
static const int kFTPOptionsCount  =  6;

static const int kAutoSaveItemCount = 6;

// extra file attribute constants

static const int faSparseFile         = 512;
static const int faReparsePoint       = 1024;
//static const int faCompressed         = 2048;
static const int faOffline            = 4096;
static const int faNotContentI        = 8192;
//static const int faEncrypted          = 16384;
static const int faRecallOnOpen       = 262144;
static const int faRecallOnDataAccess = 4194304;

// ===========================================================================
// == Categories =============================================================
// ===========================================================================

static const int __FileCategoryDirectory =  0;

static const int __Category_Temp         =  0;
static const int __Category_Program      =  1;
static const int __Category_System       =  2;
static const int __Category_Graphics     =  3;
static const int __Category_Movie        =  4;
static const int __Category_Sound        =  5;
static const int __Category_Office       =  6;
static const int __Category_Code         =  7;
static const int __Category_Compressed   =  8;
static const int __Category_Other        =  9;
static const int __Category_Custom_1     = 10;
static const int __Category_Custom_2     = 11;
static const int __Category_Custom_3     = 12;
static const int __Category_Custom_4     = 13;
static const int __Category_Custom_5     = 14;
static const int __Category_Custom_6     = 15;
static const int __Category_Custom_7     = 16;
static const int __Category_Custom_8     = 17;
static const int __Category_Custom_9     = 18;
static const int __Category_Custom_10    = 19;
static const int __Category_Custom_All   = 99;

// ===========================================================================
// == File Types =============================================================
// ===========================================================================

static const int __FileType_Hidden = 0;
static const int __FileType_System = 1;
static const int __FileType_Archive = 2;
static const int __FileType_Null = 3;
static const int __FileType_ReadOnly = 4;
static const int __FileType_Compressed = 5;
static const int __FileType_Encrypted = 6;
static const int __FileType_RecallOnOpen = 7;
static const int __FileType_RecallOnDataAccess = 8;
static const int __FileType_Offline = 9;
static const int __FileType_CreatedToday = 10;
static const int __FileType_AccessedToday = 11;
static const int __FileType_ModifiedToday = 12;

static const int __FileType_Temp = 13;
static const int __FileType_Folder = 14;
static const int __FileType_File = 15;
static const int __FileType_NoExtension = 16;
static const int __FileType_SparseFile = 17;
static const int __FileType_Reparsepoint = 18;
static const int __FileType_NotContentI = 19;

static const int __FileType_Virtual = 20;