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

#include "ReportDateOptions.h"


namespace ReportDates
{
	void Day(DateReportOptions, std::vector<std::wstring>*, int);
	void Month(DateReportOptions, std::vector<std::wstring>*, int);
	void Year(DateReportOptions, std::vector<std::wstring>*, int);

	void ReportDates(DateReportOptions, std::vector<std::wstring>*, int);
}