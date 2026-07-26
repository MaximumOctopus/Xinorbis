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


class XMapDataObject
{
public:

	std::wstring FolderName = L"";

	int FileCount = 0;
	unsigned __int64 FileSize = 0;

	int Colour = 0;
	int ColourBW = 0;

	int BlockStart = 0;
	int BlockEnd = 0;
};
