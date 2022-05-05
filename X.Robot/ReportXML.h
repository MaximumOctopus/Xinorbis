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


#include "ReportXMLReportOptions.h"
#include <string>


namespace ReportXML
{
	void Summary(XMLReportOptions options);
	void FullList(XMLReportOptions options);

	void ReportSummary(std::wofstream &ofile);
	void ReportFileAttributes(std::wofstream &ofile);
	void ReportFileAttributes(std::wofstream &ofile);
	void ReportFileCategory(std::wofstream &ofile);
	void ReportFolderList(std::wofstream &ofile);
	void ReportFileDates(std::wofstream &ofile);
	void ReportMagnitude(std::wofstream &ofile);
	void ReportExtensionLists(std::wofstream &ofile);
	void ReportNullFiles(std::wofstream &ofile);
	void ReportTopLarge(std::wofstream &ofile);
	void ReportTopSmallest(std::wofstream &ofile);
	void ReportTopNewest(std::wofstream &ofile);
	void ReportTopOldest(std::wofstream &ofile);
	void ReportUsers(std::wofstream &ofile);
};