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
#include "ConstantsReports.h"


struct TreeReportOptions
{
	std::wstring FileName = L"";

	bool IncludeSize = true;
	bool IncludeAttributes = true;
};