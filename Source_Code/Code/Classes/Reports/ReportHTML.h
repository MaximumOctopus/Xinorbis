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
#include "ReportHTMLOptions.h"
#include "SizeOfFolder.h"


namespace ReportHTML
{
	void GenerateReport(HTMLReportOptions&);

	void CreateDeepReport(std::ofstream&, HTMLReportOptions&);

   	void DeepReportFrom(std::ofstream&, std::wstring, SizeOfFolder, unsigned __int64, int, HTMLReportOptions &);

	void ReportHeader(std::ofstream &ofile, HTMLReportOptions&, std::wstring);
	void ReportExclude(std::ofstream&, HTMLReportOptions&);
	void ReportFileCategory(std::ofstream &, HTMLReportOptions&);
	void ReportFileAttributesTable(std::ofstream &, HTMLReportOptions&);
	void ReportUsers(std::ofstream &, HTMLReportOptions&);
	void ReportFileExtensionLists(std::ofstream &, HTMLReportOptions&);
	void ReportMagnitude(std::ofstream &, HTMLReportOptions&);
	void ReportQuickInfo(std::ofstream &, HTMLReportOptions&);
	void ReportDirectoryList(int, std::ofstream &, HTMLReportOptions&);
	void ReportTop101Largest(std::ofstream &, HTMLReportOptions&);
	void ReportTop101Smallest(std::ofstream &, HTMLReportOptions&);
	void ReportTop101Newest(std::ofstream &, HTMLReportOptions&);
	void ReportTop101Oldest(std::ofstream &, HTMLReportOptions&);
	void ReportFileDates(std::ofstream &, HTMLReportOptions&);
	void ReportNullFiles(std::ofstream &, HTMLReportOptions&);
	void ReportTemporary(std::ofstream&, HTMLReportOptions &);

	std::wstring BuildMenuList(HTMLReportOptions &);
	void InsertSpacingTable(std::ofstream &);

	void BuildGraphScript(std::ofstream &, HTMLReportOptions&);

	void DoubleGraph(std::ofstream&, std::wstring, std::wstring, HTMLReportOptions &);
	void SingleGraph(std::ofstream&, int, std::wstring, HTMLReportOptions &);

	void BuildGraphData(std::ofstream &, HTMLReportOptions&);
	void BuildGraphCode(std::ofstream &, HTMLReportOptions&);

	void BuildGraphDataQuickInfo(std::ofstream &);
	void BuildGraphDataCategory(std::ofstream &);
	void BuildGraphDataDirectory(std::ofstream &);
	void BuildGraphDataMagnitude(std::ofstream &);
	void BuildGraphDataFileDates(std::ofstream &);

	void FourColumnTableDoubleTitleHeader(std::ofstream&, std::wstring anchor, std::wstring, std::wstring, std::wstring, std::wstring, HTMLReportOptions &);
	void FourColumnTableRow(std::ofstream&, int, std::wstring, std::wstring, std::wstring, int, float, HTMLReportOptions &);

	void FourColumnTableDoubleTitleHeaderNoGraph(std::ofstream&, std::wstring anchor, std::wstring, std::wstring, std::wstring, std::wstring, std::wstring, HTMLReportOptions &);
	void FourColumnTableDoubleTitleNoGraphRow(std::ofstream&, int, std::wstring, std::wstring, std::wstring, std::wstring, HTMLReportOptions &);

	void SevenColumnTableHeader(std::ofstream&, std::wstring anchor, std::wstring, HTMLReportOptions &);
	void SevenColumnTableRow(std::ofstream&, int row, std::wstring, std::wstring, std::wstring, std::wstring, std::wstring, int, float, float, HTMLReportOptions &);
	void SevenColumnTableRowBlank(std::ofstream&, int, std::wstring, HTMLReportOptions &);
	void SevenColumnTableEnd(std::ofstream&);

	void SevenColumnTableDoubleTitleHeader(std::ofstream&, std::wstring anchor, std::wstring, std::wstring, HTMLReportOptions &);
};