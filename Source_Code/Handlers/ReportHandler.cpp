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

#include "ReportHandler.h"

#include "ConstantsReports.h"
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


bool ReportHandler::SaveCSV(CSVReportOptions report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
	/*std::vector<std::wstring> *data = new std::vector<std::wstring>;

	ReportCSV::Generate(FSource, data, report, LayoutUnknown);

	if (!report.FileName.empty())
	{
		SaveReport(report.FileName, data);
	}

	if (copy_to_clipboard)
	{
		CopyReportToClipboard(data);
	}

	delete data;      */
}


// bool ReportHandler::SaveDate(DateReportOptions report, bool auto_open)
//{
//}


bool ReportHandler::SaveHTML(HTMLReportOptions report, int DataSource, bool copy_to_clipboard, bool auto_open)
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


bool ReportHandler::SaveJSON(JSONReportOptions report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
    return true;
}


bool ReportHandler::SaveText(TextReportOptions report, int DataSource, bool copy_to_clipboard, bool auto_open)
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


bool ReportHandler::SaveTree(TreeReportOptions report, int DataSource, bool copy_to_clipboard, bool auto_open)
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


bool ReportHandler::SaveXinorbis(XinorbisReportOptions report, int DataSource, bool copy_to_clipboard, bool auto_open)
{
	//GReportXinorbis.GenerateXinorbisReport(FSource, XinOptions);
}


bool ReportHandler::SaveXML(XMLReportOptions report, int DataSource, bool copy_to_clipboard, bool auto_open)
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
