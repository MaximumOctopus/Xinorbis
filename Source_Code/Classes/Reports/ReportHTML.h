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

#include "ReportHTMLOptions.h"
#include "SizeOfFolder.h"


namespace ReportHTML
{
	void Generate(HTMLReportOptions&, std::vector<std::wstring>*, int);

	void CreateDeepReport(std::vector<std::wstring>*, HTMLReportOptions&, int);

	void DeepReportFrom(std::vector<std::wstring>*, std::wstring, SizeOfFolder, unsigned __int64, int, HTMLReportOptions &);

	void ReportHeader(std::vector<std::wstring>*, HTMLReportOptions&, int, std::wstring);
	void ReportExclude(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportFileCategory(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportFileAttributesTable(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportUsers(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportFileExtensionLists(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportMagnitude(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportQuickInfo(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportDirectoryList(int, std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportTop101Largest(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportTop101Smallest(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportTop101Newest(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportTop101Oldest(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportFileDates(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportNullFiles(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void ReportTemporary(std::vector<std::wstring>*, HTMLReportOptions&, int);

	std::wstring BuildMenuList(HTMLReportOptions &);
	void InsertSpacingTable(std::vector<std::wstring>*);

	void BuildGraphScript(std::vector<std::wstring>*, HTMLReportOptions&, int);

	void DoubleGraph(std::vector<std::wstring>*, std::wstring, std::wstring, HTMLReportOptions &);
	void SingleGraph(std::vector<std::wstring>*, int, std::wstring, HTMLReportOptions &);

	void BuildGraphData(std::vector<std::wstring>*, HTMLReportOptions&, int);
	void BuildGraphCode(std::vector<std::wstring>*, HTMLReportOptions&);

	void BuildGraphDataQuickInfo(std::vector<std::wstring>*, int);
	void BuildGraphDataCategory(std::vector<std::wstring>*, int);
	void BuildGraphDataDirectory(std::vector<std::wstring>*, int);
	void BuildGraphDataMagnitude(std::vector<std::wstring>*, int);
	void BuildGraphDataFileDates(std::vector<std::wstring>*, int);

	void FourColumnTableDoubleTitleHeader(std::vector<std::wstring>*, std::wstring anchor, std::wstring, std::wstring, std::wstring, std::wstring, HTMLReportOptions &);
	void FourColumnTableRow(std::vector<std::wstring>*, int, std::wstring, std::wstring, std::wstring, int, float, HTMLReportOptions &);

	void FourColumnTableDoubleTitleHeaderNoGraph(std::vector<std::wstring>*, std::wstring anchor, std::wstring, std::wstring, std::wstring, std::wstring, std::wstring, HTMLReportOptions &);
	void FourColumnTableDoubleTitleNoGraphRow(std::vector<std::wstring>*, int, std::wstring, std::wstring, std::wstring, std::wstring, HTMLReportOptions &);

	void SevenColumnTableHeader(std::vector<std::wstring>*, std::wstring anchor, std::wstring, HTMLReportOptions &);
	void SevenColumnTableRow(std::vector<std::wstring>*, int row, std::wstring, std::wstring, std::wstring, std::wstring, std::wstring, int, float, float, HTMLReportOptions &);
	void SevenColumnTableRowBlank(std::vector<std::wstring>*, int, std::wstring, HTMLReportOptions &);
	void SevenColumnTableEnd(std::vector<std::wstring>*);

	void SevenColumnTableDoubleTitleHeader(std::vector<std::wstring>*, std::wstring anchor, std::wstring, std::wstring, HTMLReportOptions &);
};