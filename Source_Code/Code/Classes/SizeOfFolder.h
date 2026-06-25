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


struct SizeOfFolder
{
	std::wstring Folder = L"";

	unsigned __int64 Size = 0;
	unsigned __int64 SizeOnDisk = 0;

	int FileCount = 0;
};
