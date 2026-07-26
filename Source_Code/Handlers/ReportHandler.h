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

	int ReportType = 0;
	int ReportSubType = 0;
};


class ReportHandler
{
public:

	LastReport Last;

	bool SaveCSV(CSVReportOptions, int, bool, bool);
//	void SaveDate(DateReportOptions, int, bool, bool);
	bool SaveHTML(HTMLReportOptions, int, bool, bool);
	bool SaveJSON(JSONReportOptions, int, bool, bool);
	bool SaveText(TextReportOptions, int, bool, bool);
	bool SaveTree(TreeReportOptions, int, bool, bool);
	bool SaveXinorbis(XinorbisReportOptions, int, bool, bool);
	bool SaveXML(XMLReportOptions, int, bool, bool);

	bool SaveReport(const std::wstring, std::vector<std::wstring> *data);

	bool CopyReportToClipboard(std::vector<std::wstring> *data);
};

