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


struct CSVReportOptions
{
	std::wstring FileName = L"";

	int Data = 0;

	int Separator = 0;
	int Units = 0;
	bool Titles = true;
	int Category = -1; //0-14 or -1 for ALL

    bool FullList = false;

	std::wstring Layout = L"";

	bool AutoOpen = false;
};