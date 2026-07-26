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

#include "ReportCSVOptions.h"


namespace ReportCSV
{
	void Summary(CSVReportOptions, std::vector<std::wstring>&, int);

	void FullList(CSVReportOptions, std::vector<std::wstring>&, int);
};