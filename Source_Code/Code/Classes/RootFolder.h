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


class RootFolder
{
public:
	std::wstring Name = L"";

	DWORD Attributes = 0;
	int Count = 0;
	unsigned __int64 Size = 0;


	// this represents the files in the root of the scan folder
	bool FilesInRoot = false;
};
