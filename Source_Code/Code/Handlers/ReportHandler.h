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

#include <vector>

#include "ReportCSVOptions.h"
#include "ReportDateOptions.h"
#include "ReportHTMLOptions.h"
#include "ReportJSONOptions.h"
#include "ReportTextOptions.h"
#include "ReportTreeOptions.h"
#include "ReportXinorbisOptions.h"
#include "ReportXMLOptions.h"


class LastReport
{
public:

	std::wstring FileName = L"";
	std::wstring ScanPath = L"";

	int DataIndex = 0;

	int ReportType = 0;
	int ReportSubType = 0;
};


class ReportHandler
{
public:

	LastReport Last;

	bool SaveCSV(CSVReportOptions&, int, bool, bool);
	bool SaveDate(DateReportOptions&, int, bool, bool);
	bool SaveHTML(HTMLReportOptions&, int, bool, bool);
	bool SaveHTMLFileList(int, const std::wstring, const std::wstring);
	bool SaveJSON(JSONReportOptions&, int, bool, bool);
	bool SaveText(TextReportOptions&, int, bool, bool);
	bool SaveTextSearch(const std::wstring, const std::wstring path, int);
	bool SaveTree(TreeReportOptions&, int, bool, bool);
	bool SaveXinorbis(XinorbisReportOptions&, int, bool, bool);
	bool SaveXML(XMLReportOptions&, int, bool, bool);

	bool SaveReport(const std::wstring, std::vector<std::wstring> *data);

	bool AutoSave(const std::wstring, int,
				  CSVReportOptions&, DateReportOptions&, HTMLReportOptions&, JSONReportOptions&,
				  TextReportOptions&, TreeReportOptions&, XinorbisReportOptions&, XMLReportOptions&);

	bool CopyReportToClipboard(std::vector<std::wstring> *data);
	bool CopyReportToClipboard(const std::wstring);

	int GetReportType(const std::wstring);

	void ClearLastReport();
	void SetLastReport(int, const std::wstring, const std::wstring, int, int);
};

