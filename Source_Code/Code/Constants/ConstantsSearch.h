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

#include <string>

#include "ConstantsData.h"


namespace SearchConstants
{
	static const int kCategoryTermCount = 29;
	static const int kTypeTermCount = 21;

	static const std::wstring kCategoryTerms[kCategoryTermCount] = {
		L"PROG",
		L"SYS", L"SYSTEM",
		L"GFX", L"GRAPHIC",
		L"MOVIE", L"FILM",
		L"SND", L"SOUND", L"AUDIO",
		L"OFF", L"OFFICE",
		L"COD", L"CODE",
		L"COM", L"ZIP",
		L"OTH", L"OTHER",
        L"C1", L"C2", L"C3", L"C4", L"C5", L"C6",
        L"C7", L"C8", L"C9", L"C10", L"CX"
    };

	static const int kCategoryValues[kCategoryTermCount] = {
		kCategory_Program,
		kCategory_System, kCategory_System,
		kCategory_Graphics, kCategory_Graphics,
		kCategory_Movie, kCategory_Movie,
		kCategory_Sound, kCategory_Sound, kCategory_Sound,
		kCategory_Office, kCategory_Office,
		kCategory_Code, kCategory_Code,
		kCategory_Compressed, kCategory_Compressed,
		kCategory_Other, kCategory_Other,
		kCategory_Custom_1, kCategory_Custom_2, kCategory_Custom_3,
		kCategory_Custom_4, kCategory_Custom_5, kCategory_Custom_6,
		kCategory_Custom_7, kCategory_Custom_8, kCategory_Custom_9,
		kCategory_Custom_10, kCategory_Custom_All
    };

	static const std::wstring kTypeTerms[kTypeTermCount] = {
        L"FILE", L"FOLDER", L"NOEXT", L"HIDDEN",
        L"SYSTEM", L"ARCHIVE", L"SPARSEFILE", L"REPARSEPOINT",
        L"COMPRESSED", L"OFFLINE", L"NOTCONTENTI", L"ENCRYPTED",
        L"NULL", L"READONLY", L"CREATED", L"ACCESSED",
        L"MODIFIED", L"TEMP", L"RECALLONOPEN", L"RECALLONDATAACCESS", L"VIRTUAL"
    };

	static const int kTypeValues[kTypeTermCount] = {
		kFileType_File, kFileType_Folder, kFileType_NoExtension, kFileType_Hidden,
		kFileType_System, kFileType_Archive, kFileType_SparseFile, kFileType_Reparsepoint,
		kFileType_Compressed, kFileType_Offline, kFileType_NotContentI, kFileType_Encrypted,
		kFileType_Null, kFileType_ReadOnly, kFileType_CreatedToday, kFileType_AccessedToday,
		kFileType_ModifiedToday, kFileType_Temp, kFileType_RecallOnOpen, kFileType_RecallOnDataAccess, kFileType_Virtual
	};

	static const int kModeField = 0;
	static const int kModeTest = 1;
	static const int kModeValue = 2;

	static const int kTestLessThan    = 0;
	static const int kTestEqualTo     = 1;
	static const int kTestGreaterThan = 2;
	static const int kTestNotEqualTo  = 3;
	static const int kTestContains    = 4;
    static const int kTestNotContains = 5;
}
