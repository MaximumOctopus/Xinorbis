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

enum class ScanSource { None = 0, LiveScan, FileXinorbisNormal, FileXinorbisDetailed, FileXinorbis2Detailed,
						FileCSV, LiveShare, FolderHistory, SearchResults };

enum class DateTimeFormat { Display = 0, File = 1, YYYYMMDD = 2, Slash = 3, HHMM = 4};
enum class DateFormat { kSlashDDMMYYYY = 0, kSlashMMDDYYYY, kSlashYYYYMMDD, kHyphenDDMMYYYY, kHyphenMMDDYYYY, kYYYYMMDD };

static const int kDataScan = 0;
static const int kDataSearch = 1;
static const int kDataFolderHistory = 2;

static const int kReportTypeCount  =  6;
static const int kQuickFolderCount = 20;

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

static const int kFileCategoryDirectory =  0;

static const int kCategory_Temp         =  0;
static const int kCategory_Program      =  1;
static const int kCategory_System       =  2;
static const int kCategory_Graphics     =  3;
static const int kCategory_Movie        =  4;
static const int kCategory_Sound        =  5;
static const int kCategory_Office       =  6;
static const int kCategory_Code         =  7;
static const int kCategory_Compressed   =  8;
static const int kCategory_Other        =  9;
static const int kCategory_Custom_1     = 10;
static const int kCategory_Custom_2     = 11;
static const int kCategory_Custom_3     = 12;
static const int kCategory_Custom_4     = 13;
static const int kCategory_Custom_5     = 14;
static const int kCategory_Custom_6     = 15;
static const int kCategory_Custom_7     = 16;
static const int kCategory_Custom_8     = 17;
static const int kCategory_Custom_9     = 18;
static const int kCategory_Custom_10    = 19;
static const int kCategory_Custom_All   = 99;

// ===========================================================================
// == File Types =============================================================
// ===========================================================================

static const int kFileType_Hidden = 0;
static const int kFileType_System = 1;
static const int kFileType_Archive = 2;
static const int kFileType_Null = 3;
static const int kFileType_ReadOnly = 4;
static const int kFileType_Compressed = 5;
static const int kFileType_Encrypted = 6;
static const int kFileType_RecallOnOpen = 7;
static const int kFileType_RecallOnDataAccess = 8;
static const int kFileType_Offline = 9;
static const int kFileType_CreatedToday = 10;
static const int kFileType_AccessedToday = 11;
static const int kFileType_ModifiedToday = 12;

static const int kFileType_Temp = 13;
static const int kFileType_Folder = 14;
static const int kFileType_File = 15;
static const int kFileType_NoExtension = 16;
static const int kFileType_SparseFile = 17;
static const int kFileType_Reparsepoint = 18;
static const int kFileType_NotContentI = 19;

static const int kFileType_Virtual = 20;