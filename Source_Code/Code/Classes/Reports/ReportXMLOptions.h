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


static const int XMLReportOptionsCount = 11;


struct XMLReportOptions
{
	std::wstring FileName = L"";
	std::wstring Layout = L"";

	bool OutputOptions[10];

	int Data = 0;

    bool AutoOpen = false;
};