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


#include "ReportTextOptions.h"
#include <string>


const int TRDescriptionWidth = 39;
const int TRQuantityWidth    =  9;
const int TRAsPercentWidth   =  7;
const int TRSizeWidth        = 11;


namespace ReportText
{
	void FullList(TextReportOptions);

	void CreateDeepReport(std::ofstream&);

	void ReportHeader(std::ofstream &);
	void ReportSummary(std::ofstream &);
	void ReportAttributes(std::ofstream &);
	void ReportCategories(std::ofstream &);
	void ReportDirectoryList(std::ofstream &);
	void ReportFileDates(std::ofstream &);
	void ReportMagnitude(std::ofstream &);
	void ReportExtensions(std::ofstream &, TextReportOptions);
	void ReportNullFiles(std::ofstream &);
	void ReportTemporaryFiles(std::ofstream&);
	void ReportUsers(std::ofstream &);

	void ReportLargestFiles(std::ofstream &);
	void ReportSmallestFiles(std::ofstream &);

	void ReportNewestFiles(std::ofstream &);
	void ReportOldestFiles(std::ofstream &);

	void TitleBlock5Row(std::ofstream&, int, int);
	void TitleBlock3Row(std::ofstream&, int);
};