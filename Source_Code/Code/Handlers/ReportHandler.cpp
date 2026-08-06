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

#include <algorithm>

#include "ConstantsReports.h"
#include "ReportHandler.h"

#include "ReportCSV.h"
#include "ReportHTML.h"
#include "ReportText.h"
#include "ReportTree.h"
#include "ReportXML.h"


ReportHandler *GReportHandler;


bool ReportHandler::SaveReport(const std::wstring file_name, std::vector<std::wstring> *data)
{
	return false;
}


bool ReportHandler::CopyReportToClipboard(std::vector<std::wstring> *)
{
	return false;
}


// =============================================================================


bool ReportHandler::SaveCSV(CSVReportOptions &report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
	std::vector<std::wstring> *data = new std::vector<std::wstring>;

	if (report.FullList)
	{
		ReportCSV::FullList(report, data, DataSource);
	}
	else
	{
		ReportCSV::Summary(report, data, DataSource);
	}

	if (!report.FileName.empty())
	{
		SaveReport(report.FileName, data);
	}

	if (copy_to_clipboard)
	{
		CopyReportToClipboard(data);
	}

	delete data;
}


bool ReportHandler::SaveDate(DateReportOptions &report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
    return false;
}


bool ReportHandler::SaveHTML(HTMLReportOptions &report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
	std::vector<std::wstring> *data = new std::vector<std::wstring>;

	ReportHTML::Generate(report, data, DataSource);

	if (!report.FileName.empty())
	{
		SaveReport(report.FileName, data);
	}

	if (copy_to_clipboard)
	{
		CopyReportToClipboard(data);
	}

	delete data;
}


bool ReportHandler::SaveHTMLFileList(int DataSource, const std::wstring file_name, const std::wstring title)
{
	std::vector<std::wstring> *data = new std::vector<std::wstring>;

	ReportHTML::FileReport(data, DataSource, file_name, title);

	SaveReport(file_name, data);

	delete data;
}


bool ReportHandler::SaveJSON(JSONReportOptions &report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
	return true;
}


bool ReportHandler::SaveText(TextReportOptions &report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
	std::vector<std::wstring> *data = new std::vector<std::wstring>;

	ReportText::Generate(report, data, DataSource);

	if (!report.FileName.empty())
	{
		SaveReport(report.FileName, data);
	}

	if (copy_to_clipboard)
	{
		CopyReportToClipboard(data);
	}

	delete data;
}


bool ReportHandler::SaveTextSearch(const std::wstring file_name, const std::wstring path, int DataSource)
{
	std::vector<std::wstring> *data = new std::vector<std::wstring>;

	ReportText::SearchResults(data, DataSource, path);

	SaveReport(file_name, data);

	delete data;
}


bool ReportHandler::SaveTree(TreeReportOptions &report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
	std::vector<std::wstring> *data = new std::vector<std::wstring>;

	ReportTree::Generate(report, data, DataSource);

	if (!report.FileName.empty())
	{
		SaveReport(report.FileName, data);
	}

	if (copy_to_clipboard)
	{
		CopyReportToClipboard(data);
	}

	delete data;
}


bool ReportHandler::SaveXinorbis(XinorbisReportOptions &report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
	//GReportXinorbis.GenerateXinorbisReport(FSource, XinOptions);
	return false;
}


bool ReportHandler::SaveXML(XMLReportOptions &report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
	std::vector<std::wstring> *data = new std::vector<std::wstring>;

	if (report.Data == kDataSummary)
	{
		ReportXML::Summary(report, data, DataSource);
	}
	else
	{
		ReportXML::FullList(report, data, DataSource); // MOVE TO xinorbisreports
	}

	if (!report.FileName.empty())
	{
		SaveReport(report.FileName, data);
	}

	if (copy_to_clipboard)
	{
		CopyReportToClipboard(data);
	}

	delete data;
}


bool ReportHandler::AutoSave(const std::wstring path, int DataSource,
							 CSVReportOptions &csvro, DateReportOptions &datero, HTMLReportOptions &htmlro, JSONReportOptions &jsonro,
							 TextReportOptions &textro, TreeReportOptions &tree, XinorbisReportOptions &xinro, XMLReportOptions &xmlro)
{
	if (!csvro.FileName.empty())
	{
		SaveCSV(csvro, DataSource, false, false);
	}

	if (!datero.FileName.empty())
	{
		SaveDate(datero, DataSource, false, false);
	}


	if (!htmlro.FileName.empty())
	{
		SaveHTML(htmlro, DataSource, false, false);
	}


	if (!jsonro.FileName.empty())
	{
	   	SaveJSON(jsonro, DataSource, false, false);
	}


	if (!textro.FileName.empty())
	{
		SaveText(textro, DataSource, false, false);
	}


	if (!tree.FileName.empty())
	{
		SaveTree(tree, DataSource, false, false);
	}


	if (!xinro.FileName.empty())
	{
		SaveXinorbis(xinro, DataSource, false, false);
	}


	if (!xmlro.FileName.empty())
	{
		SaveXML(xmlro, DataSource, false, false);
	}


	return true;
}


// =============================================================================


int ReportHandler::GetReportType(const std::wstring file_name)
{
	std::wstring fnuc = file_name;

	std::transform(fnuc.begin(), fnuc.end(), fnuc.begin(), ::toupper);

	if (fnuc.find(L".CSV") != std::wstring::npos)
	{
		return kReportTypeCSV;
	}
	else if (fnuc.find(L".HTM") != std::wstring::npos ||
			 fnuc.find(L".HTML") != std::wstring::npos)
	{
		return kReportTypeHTML;
	}
	else if (fnuc.find(L".TXT") != std::wstring::npos)
	{
		return kReportTypeText;
	}
	else if (fnuc.find(L".ZSR") != std::wstring::npos)
	{
		return kReportTypeXinorbis;
	}
	else if (fnuc.find(L".ZSR2") != std::wstring::npos)
	{
		return kReportTypeXinorbis2;
	}
	else if (fnuc.find(L".XML") != std::wstring::npos)
	{
		return kReportTypeXML;
	}

	return kReportTypeUnknown;
}


void ReportHandler::ClearLastReport()
{
	Last.DataIndex = 0;
	Last.FileName = L"";
	Last.ScanPath = L"";

	Last.ReportType = -1;
	Last.ReportSubType = -1;
}


void ReportHandler::SetLastReport(int data_source,
	const std::wstring file_name, const std::wstring scan_path, int report_type, int sub_type)
{
	Last.DataIndex = data_source;
	Last.FileName = file_name;
	Last.ScanPath = scan_path;

	Last.ReportType = report_type;
	Last.ReportSubType = sub_type;
}
