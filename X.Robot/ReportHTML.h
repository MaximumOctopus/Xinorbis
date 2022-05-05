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


#include "ReportHTMLReportOptions.h"
#include <string>


const int __MagniColours[13] = { 0x8383FF, 0x83BAFF, 0x83ECFF, 0x83FFCC, 0x92ff83, 0xD5FF83, 0xFFFE83, 0xFFCF83, 0xFF9283, 0xFF83AF, 0xFF83F5, 0xFF83F5, 0xFF83F5 };
const int __GraphColours[13] = { 0x8383FF, 0x83BAFF, 0x83ECFF, 0x83FFCC, 0x92ff83, 0xD5FF83, 0xFFFE83, 0xFFCF83, 0xFF9283, 0xFF83AF, 0xFF83F5, 0xD6D5DB, 0xFFFFFF };


namespace ReportHTML
{
	void GenerateReport(HTMLReportOptions options);

	void ReportHeader(std::wofstream &ofile, HTMLReportOptions options, std::wstring menuString);
	void ReportFileCategory(std::wofstream &ofile, HTMLReportOptions options);
	void ReportFileAttributesTable(std::wofstream &ofile, HTMLReportOptions options);
	void ReportUsers(std::wofstream &ofile, HTMLReportOptions options);
	void ReportFileExtensionLists(std::wofstream &ofile, HTMLReportOptions options);
	void ReportMagnitude(std::wofstream &ofile, HTMLReportOptions options);
	void ReportQuickInfo(std::wofstream &ofile, HTMLReportOptions options);
	void ReportDirectoryList(int fileDatesCount, std::wofstream &ofile, HTMLReportOptions options);
	void ReportTop101Largest(std::wofstream &ofile, HTMLReportOptions options);
	void ReportTop101Smallest(std::wofstream &ofile, HTMLReportOptions options);
	void ReportTop101Newest(std::wofstream &ofile, HTMLReportOptions options);
	void ReportTop101Oldest(std::wofstream &ofile, HTMLReportOptions options);
	void ReportFileDates(std::wofstream &ofile, HTMLReportOptions options);
	void ReportNullFiles(std::wofstream &ofile, HTMLReportOptions options);

	std::wstring BuildMenuList(HTMLReportOptions options);
	void InsertSpacingTable(std::wofstream &ofile);

	void BuildGraphScript(std::wofstream &ofile, HTMLReportOptions options);
	
	void BuildGraphData(std::wofstream &ofile, HTMLReportOptions options);
	void BuildGraphCode(std::wofstream &ofile, HTMLReportOptions options);

	void BuildGraphDataQuickInfo(std::wofstream &ofile);
	void BuildGraphDataCategory(std::wofstream &ofile);
	void BuildGraphDataDirectory(std::wofstream &ofile);
	void BuildGraphDataMagnitude(std::wofstream &ofile);
	void BuildGraphDataFileDates(std::wofstream &ofile);
};