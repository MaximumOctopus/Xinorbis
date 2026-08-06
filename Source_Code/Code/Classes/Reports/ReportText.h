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
#include <vector>

#include "ReportTextOptions.h"


const int TRDescriptionWidth = 39;
const int TRQuantityWidth    =  9;
const int TRAsPercentWidth   =  7;
const int TRSizeWidth        = 11;


namespace ReportText
{
    // simplified report ideal for search results
	void SearchResults(std::vector<std::wstring> *data, int, const std::wstring);

	void Generate(TextReportOptions, std::vector<std::wstring>*, int);

	void CreateDeepReport(std::vector<std::wstring>*, int);

	void ReportHeader(std::vector<std::wstring>*);
	void ReportSummary(std::vector<std::wstring>*, int);
	void ReportAttributes(std::vector<std::wstring>*, int);
	void ReportCategories(std::vector<std::wstring>*, int);
	void ReportDirectoryList(std::vector<std::wstring>*, int);
	void ReportFileDates(std::vector<std::wstring>*, int);
	void ReportMagnitude(std::vector<std::wstring>*, int);
	void ReportExtensions(std::vector<std::wstring>*, TextReportOptions, int);
	void ReportNullFiles(std::vector<std::wstring>*, int);
	void ReportTemporaryFiles(std::vector<std::wstring>*, int);
	void ReportUsers(std::vector<std::wstring>*, int);

	void ReportLargestFiles(std::vector<std::wstring>*, int);
	void ReportSmallestFiles(std::vector<std::wstring>*, int);

	void ReportNewestFiles(std::vector<std::wstring>*, int);
	void ReportOldestFiles(std::vector<std::wstring>*, int);

	void TitleBlock5Row(std::vector<std::wstring>*, int, int);
	void TitleBlock3Row(std::vector<std::wstring>*, int);
};