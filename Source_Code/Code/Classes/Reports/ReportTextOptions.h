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


struct TextReportOptions
{
	std::wstring FileName = L"";

	bool Layout[__TextReportOptionsCount] = { false };
	bool CategoryList[__FileCategoriesCount] = { false };

	bool DeepScan = false;
};