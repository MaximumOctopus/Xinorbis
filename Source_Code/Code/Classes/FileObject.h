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
#include <Windows.h>


class FileObject
{

public:

    int FilePathIndex = 0;
    
    std::wstring Name = L"";
	unsigned __int64 Size = 0;

    int SizeOnDisk = 0;
    int DateCreated = 0;	// yyyymmdd
    int DateAccessed = 0;	// yyyymmdd
    int DateModified = 0;	// yyyymmdd
    int TimeCreated = 0;	// hhmmss
    int TimeAccessed = 0;	// hhmmss
    int TimeModified = 0;	// hhmmss
	int Category = 0;
    DWORD Attributes = 0;
    bool Temp = false;
    int Owner = 0;

	FileObject();

    std::wstring ToCSV(const std::wstring folder, const std::wstring user, int units);
    std::wstring ToJSON(const std::wstring folder, const std::wstring user);
    std::wstring ToXml(const std::wstring folder, const std::wstring user);
};