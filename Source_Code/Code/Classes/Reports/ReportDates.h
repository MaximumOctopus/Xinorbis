// =====================================================================
//
// FolderScanUltra 5
//
// (c) Paul Alan Freshney 2019-2026
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FolderScanUltra
// 
// =====================================================================

#pragma once

#include "ReportDateOptions.h"


class ReportDates
{
	void Day(DateReportOptions);
	void Month(DateReportOptions);
	void Year(DateReportOptions);

public:

	ReportDates(DateReportOptions);
};