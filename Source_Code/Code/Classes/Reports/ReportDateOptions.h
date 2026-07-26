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


struct DateReportOptions
{
	std::wstring FileName = L"";

	bool Created = true;
	bool OutputSorted = false;

	bool Day = false;
	bool Month = false;
	bool Year = false;
};