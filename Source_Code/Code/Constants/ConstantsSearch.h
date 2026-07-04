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
	static const int CategoryTermCount = 29;
	static const int TypeTermCount = 21;

	static const std::wstring CategoryTerms[CategoryTermCount] = {
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

    static const int CategoryValues[CategoryTermCount] = {
        __Category_Program,
        __Category_System, __Category_System,
        __Category_Graphics, __Category_Graphics,
        __Category_Movie, __Category_Movie,
        __Category_Sound, __Category_Sound, __Category_Sound,
        __Category_Office, __Category_Office,
        __Category_Code, __Category_Code,
        __Category_Compressed, __Category_Compressed,
        __Category_Other, __Category_Other,
        __Category_Custom_1, __Category_Custom_2, __Category_Custom_3,
        __Category_Custom_4, __Category_Custom_5, __Category_Custom_6,
        __Category_Custom_7, __Category_Custom_8, __Category_Custom_9,
        __Category_Custom_10, __Category_Custom_All
    };

    static const std::wstring TypeTerms[TypeTermCount] = {
        L"FILE", L"FOLDER", L"NOEXT", L"HIDDEN",
        L"SYSTEM", L"ARCHIVE", L"SPARSEFILE", L"REPARSEPOINT",
        L"COMPRESSED", L"OFFLINE", L"NOTCONTENTI", L"ENCRYPTED",
        L"NULL", L"READONLY", L"CREATED", L"ACCESSED",
        L"MODIFIED", L"TEMP", L"RECALLONOPEN", L"RECALLONDATAACCESS", L"VIRTUAL"
    };

    static const int TypeValues[TypeTermCount] = {
        __FileType_File, __FileType_Folder, __FileType_NoExtension, __FileType_Hidden,
        __FileType_System, __FileType_Archive, __FileType_SparseFile, __FileType_Reparsepoint,
        __FileType_Compressed, __FileType_Offline, __FileType_NotContentI, __FileType_Encrypted,
        __FileType_Null, __FileType_ReadOnly, __FileType_CreatedToday, __FileType_AccessedToday,
		__FileType_ModifiedToday, __FileType_Temp, __FileType_RecallOnOpen, __FileType_RecallOnDataAccess, __FileType_Virtual
	};

	static const int ModeField = 0;
	static const int ModeTest = 1;
	static const int ModeValue = 2;
}
