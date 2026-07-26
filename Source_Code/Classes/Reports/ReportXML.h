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

#include "ReportXMLOptions.h"


namespace ReportXML
{
	void Summary(XMLReportOptions, std::vector<std::wstring>*, int);
	void FullList(XMLReportOptions, std::vector<std::wstring>*, int);

	void ReportSummary(std::vector<std::wstring>*, int);
	void ReportFileAttributes(std::vector<std::wstring>*, int);
	void ReportFileCategory(std::vector<std::wstring>*, int);
	void ReportFolderList(std::vector<std::wstring>*, int);
	void ReportFileDates(std::vector<std::wstring>*, int);
	void ReportMagnitude(std::vector<std::wstring>*, int);
	void ReportExtensionLists(std::vector<std::wstring>*, int);
	void ReportNullFiles(std::vector<std::wstring>*, int);
	void ReportTopLarge(std::vector<std::wstring>*, int);
	void ReportTopSmallest(std::vector<std::wstring>*, int);
	void ReportTopNewest(std::vector<std::wstring>*, int);
	void ReportTopOldest(std::vector<std::wstring>*, int);
	void ReportUsers(std::vector<std::wstring>*, int);
	void ReportTemporaryFiles(std::vector<std::wstring>*, int);
};