//
// X.Robot 4.0 :: C++ rewrite
//
// (c) Paul Alan Freshney 2019-2020
//     Maximum Octopus Limited
//
// xinorbis.com
// maximumoctopus.com
// 
// twitter.com/maximumoctopus
//
//
// January 30th 2019
//


#pragma once


#include "ReportTextReportOptions.h"
#include <string>


const int TRDescriptionWidth = 25;
const int TRQuantityWidth    = 9;
const int TRAsPercentWidth   = 7;
const int TRSizeWidth        = 11;


const std::string magnilabels3[] = { "less than 1K", "1K - 1MB", "1MB - 10MB", "10MB - 50MB", "50MB - 100MB",
									 "100MB - 150MB", "150MB - 200MB", "200MB - 250MB", "250MB - 500MB", "500MB - 1GB",
									 "1GB - 2GB", "2GB - 5GB", "5GB+" };


namespace ReportText
{
	void FullList(TextReportOptions options);

	void ReportHeader(std::wofstream &file);
	void ReportSummary(std::wofstream &ofile);
	void ReportAttributes(std::wofstream &ofile);
	void ReportCategories(std::wofstream &ofile);
	void ReportDirectoryList(std::wofstream &ofile);
	void ReportFileDates(std::wofstream &ofile);
	void ReportMagnitude(std::wofstream &ofile);
	void ReportExtensions(std::wofstream &ofile, TextReportOptions options);
	void ReportNullFiles(std::wofstream &ofile);
	void ReportUsers(std::wofstream &ofile);

	void ReportLargestFiles(std::wofstream &ofile);
	void ReportSmallestFiles(std::wofstream &ofile);

	void ReportNewestFiles(std::wofstream &ofile);
	void ReportOldestFiles(std::wofstream &ofile);
};
