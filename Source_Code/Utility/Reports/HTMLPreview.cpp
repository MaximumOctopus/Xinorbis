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

#include "ConstantsReports.h"
#include "Convert.h"
#include "DateUtility.h"
#include "HTMLPreview.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"
#include "Utility.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;


void HTMLPreview::Get(std::vector<std::wstring> &output, HTMLReportOptions &options, HTMLColours &colour)
{
	std::vector<std::wstring> Menu;

	std::wstring align = L"";

	if (options.Units == 0)
	{
		align = L"center";
	}
	else
	{
		align = L"right";
	}

	BuildMenuList(Menu);

	//----------------------------------------------------------------------------
	//--Lets write the file-------------------------------------------------------
	//----------------------------------------------------------------------------

	output.push_back(L"<html><head><title>xinorbis analysis: <strong>p:\\review\\folder\\</strong></title>");
	output.push_back(L"<style type=\"text/css\"><!--");
	output.push_back(L"A:link {color:#" + Convert::WebColour(colour.Colour[1]) + L"; text-decoration: none;}");
	output.push_back(L"A:visited {color:#" + Convert::WebColour(colour.Colour[1]) + L"; text-decoration: none;}");
	output.push_back(L"A:hover {color:#" + Convert::WebColour(colour.Colour[2]) + L"; text-decoration: underline;}");
	output.push_back(L"A:active {color:#" + Convert::WebColour(colour.Colour[1]) + L"; text-decoration: none;}");
	output.push_back(L".C4G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#" + Convert::WebColour(colour.Colour[4]) + L";}");
	output.push_back(L".C7G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#" + Convert::WebColour(colour.Colour[7]) + L";}");
	output.push_back(L"-->");
	output.push_back(L"</style></head><body leftmargin=\"5\" bgcolor=\"#" + Convert::WebColour(colour.Colour[3]) + L"\" text=\"#" + Convert::WebColour(colour.Colour[8]) + L"\" topmargin=\"5\">");

	std::wstring s = L"";

	for (int t = 0; t < options.Layout.size(); t++)
	{
		if (options.Layout[t] == L':')
		{
			if (!s.empty())
			{
				AddHTMLReportItem(output, Menu, colour, options.Units, align, stoi(s));
			}

			s = L"";
		}
		else
		{
			s += options.Layout[t];
		}
	}

	// footer table. always gets added
	output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">");
	output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
	output.push_back(   L"<td align=\"center\" class=\"C7G\">");
	output.push_back(   L"<a href=\"mailto:xinorbis@maximumoctopus.com\">xinorbis@maximumoctopus.com</a> / <a href=\"http://www.xinorbis.com\" target=\"_blank\">www.xinorbis.com</a></td>");
	output.push_back(L"</tr>");
	output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\" class=\"C7G\"><td align=\"center\">(c) Paul Alan Freshney 2002-" + DateUtility::CurrentYear() + L"</td></tr>");
	output.push_back(L"</table></body></html>");
}


void HTMLPreview::BuildMenuList(std::vector<std::wstring> &menu)
{
	menu.push_back(L"&nbsp;&nbsp;- <a href=\"#op2\">"  + GLanguageHandler->Text[kReportOptions] + L"</a>");
	menu.push_back(L"&nbsp;&nbsp;- <a href=\"#op3\">"  + GLanguageHandler->Text[kExtension]  + L"</a>");
	menu.push_back(L"&nbsp;&nbsp;- <a href=\"#op4\">"  + GLanguageHandler->Text[kCategory] + L"</a>");
	menu.push_back(L"&nbsp;&nbsp;- <a href=\"#op5\">"  + GLanguageHandler->Text[kPath] + L"</a>");
	menu.push_back(L"&nbsp;&nbsp;- <a href=\"#op6\">"  + GLanguageHandler->Text[kAssociatedFileExtensions] + L"</a>");
	menu.push_back(L"&nbsp;&nbsp;- <a href=\"#op7\">"  + GLanguageHandler->Text[kHelp] + L"</a> / <a href=\"#op7a\">" + GLanguageHandler->Text[kAutoSaveReports] + L"</a>");
	menu.push_back(L"&nbsp;&nbsp;- <a href=\"#op8\">"  + GLanguageHandler->Text[kChartOptions] + L"</a>");
	menu.push_back(L"&nbsp;&nbsp;- <a href=\"#op9\">"  + GLanguageHandler->Text[kRestoreDefaults] + L"</a>");
	menu.push_back(L"&nbsp;&nbsp;- <a href=\"#op10\">" + GLanguageHandler->Text[kAutosaveOptions] + L"</a>");
}


void HTMLPreview::AddHTMLReportItem(std::vector<std::wstring> &output, std::vector<std::wstring> &menu, HTMLColours &colour, int HTMLUnits, const std::wstring align, int section_index)
{
	auto InsertSpacingTable = [&output]()
	{
		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\">");
		output.push_back(L"  <tr><td>&nbsp;</td></tr>");
		output.push_back(L"</table>");
	};

	int table_colour = 0;

	switch (section_index)
	{
	case kHTMLHeader:
		//----------------------------------------------------------------------------
		//--header table---------------------------------------------------------------
		//----------------------------------------------------------------------------
		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\" bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\">");
		output.push_back(L"<tr class=\"C4G\">");
		output.push_back(L"<td><div align=\"center\"><b>xinorbis<sup>8</sup></b> report for <b><a href=\"#\">c:\\xinorbis\\preview</a></b></div></td>");
		output.push_back(L"</tr>");
		output.push_back(L"<tr class=\"C4G\"><td><div align=\"center\">Analysed at <b>" + Utility::GetTime(DateTimeFormat::Display) + L"</b> on <b>" + Utility::GetDate(DateTimeFormat::Display) + L"</b></div></td>");
		output.push_back(L"</tr>");
		output.push_back(L"</table>");

		InsertSpacingTable();
		break;
	case kHTMLQuick:
		//-----------------------------------------------------------------
		//--quick info table-----------------------------------------------
		//-----------------------------------------------------------------
		output.push_back(L"<table align=\"center\" width=\"770\" height=\"180\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\" bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\">");
		output.push_back(L"<tr><td width=\"100%\" bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\" class=\"C7G\"><strong>" + GLanguageHandler->Text[kSummary] + L"</strong></td></tr>");
		output.push_back(L"<tr>");
		output.push_back(   L"<td>");
		output.push_back(   L"<table width=\"100%\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"100\" class=\"C4G\">" + menu[0] + L"</div></td>");
		output.push_back(     L"<td width=\"310\" rowspan=\"11\"></td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\"><div align=\"right\">" + GLanguageHandler->Text[kFileAttributes] + L" - </div></td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\"><div align=\"left\"> - 3141592</div></td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">" + menu[1] + L"</div></td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\"><div align=\"right\">" + GLanguageHandler->Text[kFiles] + L" - </div></td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\"><div align=\"left\"> - 2718</div></td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">" + menu[2] + L"</div></td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\"><div align=\"right\">" + GLanguageHandler->Text[kCategoryColours] + L" - </div></td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\"><div align=\"left\"> - 245MB</div></td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">" + menu[3] + L"</div></td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">&nbsp;</td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\">&nbsp;</td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">" + menu[4] + L"</div></td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\"><div align=\"right\">Disk space used - </div></td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\"><div align=\"left\"> - 1.41GB</div></td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">" + menu[5] + L"</div></td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\"><div align=\"right\">Disk space wasted - </div></td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\"><div align=\"left\"> - 148MB</div></td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">" + menu[6] + L"</div></td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">&nbsp;</td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\">&nbsp;</td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">" + menu[7] + L"</div></td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\"><div align=\"right\">" + GLanguageHandler->Text[kFolder] + L" - </div></td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\"><div align=\"left\"> - 1.2GB</div></td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">" + menu[8] + L"</div></td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">&nbsp;</td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\">&nbsp;</td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"<tr>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">&nbsp;</td>");
		output.push_back(     L"<td width=\"170\" class=\"C4G\">&nbsp;</td>");
		output.push_back(     L"<td width=\"92\" class=\"C4G\">&nbsp;</td>");
		output.push_back(   L"</tr>");
		output.push_back(   L"</table>");
		output.push_back(   L"</td>");
		output.push_back(L"</tr>");
		output.push_back(L"</table>");

		InsertSpacingTable();
		break;
	case kHTMLFAT:
		//-----------------------------------------------------------------
		//file attributes table--------------------------------------------
		//-----------------------------------------------------------------
		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">");
		output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(   L"<td width=\"100\" height=\"13\" class=\"C7G\"><a name=\"op2\" /><b>" + GLanguageHandler->Text[kReportOptions] + L"</b></td>");
		output.push_back(   L"<td width=\"64\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kQty] + L"</b></div></td>");
		output.push_back(   L"<td width=\"64\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(   L"<td width=\"160\" height=\"13\">&nbsp;</td>");
		output.push_back(   L"<td width=\"85\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kFileSize] + L"</b></div></td>");
		output.push_back(   L"<td width=\"67\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(   L"<td width=\"160\" height=\"20\">&nbsp;</td>");
		output.push_back(L"</tr>");

		//build the file category table
		for (int t = 0; t <__AttributesToDisplayCount; t++)
		{
			if (t % 2)
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\">");
			}
			else
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[11]) + L"\">");
			}

			output.push_back(   L"<td width=\"100\" class=\"C4G\">");
			output.push_back(     L"<div align=\"left\">" + GLanguageHandler->LanguageTypes[t] + L"</div>");
			output.push_back(   L"</td>");
			output.push_back(   L"<td width=\"64\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(Random(2000)) + L"</div></td>");
			output.push_back(   L"<td width=\"64\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(2 + Random(130)) + L"</div></td>");
			output.push_back(   L"<td width=\"160\">");
			output.push_back(   L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(colour.Colour[5]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
			output.push_back(     L"<tr><td></td></tr>");
			output.push_back(   L"</table>");
			output.push_back(   L"</td>");
			output.push_back(   L"<td width=\"85\" class=\"C4G\"><div align=\"" + align + L"\">1GB</div></td>");
			output.push_back(   L"<td width=\"67\" class=\"C4G\"><div align=\"center\">10%</div></td>");
			output.push_back(   L"<td width=\"160\">");
			output.push_back(   L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(colour.Colour[5]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
			output.push_back(     L"<tr><td></td></tr>");
			output.push_back(   L"</table>");
			output.push_back(   L"</td>");
			output.push_back(L"</tr>");
		}
		output.push_back(L"</table>");

		InsertSpacingTable();
		break;
	case kHTMLCategory:
		//-----------------------------------------------------------------
		//file category table----------------------------------------------
		//-----------------------------------------------------------------
		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">");
		output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(   L"<td width=\"100\" height=\"13\" class=\"C7G\"><a name=\"op3\" /><b>" + GLanguageHandler->Text[kExtension] + L"</b></td>");
		output.push_back(   L"<td width=\"64\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kQty] + L"</b></div></td>");
		output.push_back(   L"<td width=\"64\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(   L"<td width=\"160\" height=\"13\">&nbsp;</td>");
		output.push_back(   L"<td width=\"85\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kFileSize] + L"</b></div></td>");
		output.push_back(   L"<td width=\"67\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(   L"<td width=\"160\" height=\"20\">&nbsp;</td>");
		output.push_back(L"</tr>");

		//build the file category table
		for (int t = 0; t < __FileCategoriesCount; t++)
		{
			if (t % 2)
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\">)");
			}
			else
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[11]) + L"\">");
            }

			output.push_back(   L"<td width=\"100\" class=\"C4\"><div align=\"left\">" + GLanguageHandler->TypeDescriptions[t] + L"</div></td>");
			output.push_back(   L"<td width=\"64\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(2 + Random(1300)) + L"</div></td>");
			output.push_back(   L"<td width=\"64\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(2 + Random(80)) + L"%</div></td>");
			output.push_back(   L"<td width=\"160\">");
			output.push_back(     L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->FileCategoryColors[t]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
			output.push_back(     L"<tr><td></td></tr>");
			output.push_back(     L"</table>");
			output.push_back(   L"</td>");
			output.push_back(   L"<td width=\"85\" class=\"C4G\"><div align=\"" + align + L"\">1GB</div></td>");
			output.push_back(   L"<td width=\"67\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(2 + Random(80)) + L"%</div></td>");
			output.push_back(   L"<td width=\"160\">");
			output.push_back(   L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->FileCategoryColors[t]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
			output.push_back(     L"<tr><td></td></tr>");
			output.push_back(     L"</table>");
			output.push_back(   L"</td>");
			output.push_back(L"</tr>");
		}

		output.push_back(L"</table>");

		InsertSpacingTable();
		break;
	case kHTMLFolders:
		//-----------------------------------------------------------------
		// --directory list---by file count--------------------------------
		//-----------------------------------------------------------------
		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">");
		output.push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(   L"<td width=\"387\" height=\"20\"><a name=\"op4\" /><b>" + GLanguageHandler->Text[kFileName] + L"</b></td>");
		output.push_back(L"</tr>");
		output.push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(  L"<td width=\"387\" height=\"20\"><b>" + GLanguageHandler->Text[kFolder] + L"</b></td>");
		output.push_back(   L"<td width=\"83\" height=\"20\"><div align=\"center\"><b>" + GLanguageHandler->Text[kQtyOfFiles] + L"</b></div></td>");
		output.push_back(   L"<td width=\"65\" height=\"20\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(   L"<td width=\"155\" height=\"20\">&nbsp;</td>");
		output.push_back(L"</tr>");

		for (int t = 0; t < 4; t++)
		{
			if (colour.MonoBargraph)
			{
				table_colour = colour.Colour[5];
			}
			else
			{
				table_colour = __SpectrumColours[t % __SpectrumMod];
			}

			if (t & 2)
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\">");
			}
			else
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[11]) + L"\">");
			}

			output.push_back(   L"<td width=\"387\" class=\"C4G\"><div align=\"left\">Preview Folder #" + std::to_wstring(t) + L"</div></td>");
			output.push_back(   L"<td width=\"83\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(4 + Random(100)) + L"</div></td>");
			output.push_back(   L"<td width=\"65\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(4 + Random(20)) + L"%</div></td>");
			output.push_back(   L"<td width=\"160\">");
			output.push_back(     L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(table_colour) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
			output.push_back(     L"<tr><td></td></tr>");
			output.push_back(     L"</table>");
			output.push_back(   L"</td>");
			output.push_back(L"</tr>");
		}

		output.push_back(L"</table>");

		InsertSpacingTable();
		break;
	case 6:
		//-----------------------------------------------------------------
		//-- magnitude table ----------------------------------------------
		//-----------------------------------------------------------------
		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">");
		output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(   L"<td width=\"100\" height=\"13\" class=\"C7G\"><a name=\"op5\" /><b>" + GLanguageHandler->Text[kPath] + L"</b></td>");
		output.push_back(   L"<td width=\"64\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kQty] + L"</b></div></td>");
		output.push_back(   L"<td width=\"64\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(   L"<td width=\"160\" height=\"13\">&nbsp;</td>");
		output.push_back(   L"<td width=\"85\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kFileSize] + L"</b></div></td>");
		output.push_back(   L"<td width=\"67\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(   L"<td width=\"160\" height=\"20\">&nbsp;</td>");
		output.push_back(L"</tr>");

		//build the file category table
		for (int t = 0; t < __MagnitudesCount; t++)
		{
			if (t % 2)
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\">");
			}
			else
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[11]) + L"\">");
			}

			output.push_back(   L"<td width=\"100\" class=\"C4G\"><div align=\"left\">" + __MagnitudeLabelsShort[t] + L"</div></td>");
			output.push_back(   L"<td width=\"64\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(Random(20)) + L"</div></td>");
			output.push_back(   L"<td width=\"64\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(Random(20)) + L"%</div></td>");
			output.push_back(   L"<td width=\"160\">");
			output.push_back(     L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(__MagnitudeColour[t]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
			output.push_back(     L"<tr><td></td></tr>");
			output.push_back(     L"</table>");
			output.push_back(   L"</td>");
			output.push_back(   L"<td width=\"85\" class=\"C4G\"><div align=\"" + align + L"\">" + Convert::GetSizeString(HTMLUnits, 1024 * Random(1024) * Random(1024)) + L"</div></td>");
			output.push_back(   L"<td width=\"67\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(Random(20)) + L"</div></td>");
			output.push_back(   L"<td width=\"160\">");
			output.push_back(     L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(__MagnitudeColour[t]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
			output.push_back(     L"<tr><td></td></tr>");
			output.push_back(     L"</table>");
			output.push_back(   L"</td>");
			output.push_back(L"</tr>");
		}

		output.push_back(L"</table>");

		InsertSpacingTable();
		break;
	case kHTMLNullFiles:
		//-----------------------------------------------------------------
		//-- null files ---------------------------------------------------
		//-----------------------------------------------------------------
		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">");
		output.push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(L"<td height=\"13\"><a name=\"op7\" /><b>" + GLanguageHandler->Text[kNullFiles] + L"</b></td>");
		output.push_back(L"</tr>");
		output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\" class=\"C4G\">");
		output.push_back(L"<td colspan=\"7\" height=\"13\">" +  GLanguageHandler->Text[kGeneral] + L"</td>");
		output.push_back(L"</tr>");
		output.push_back(L"</table>");

		InsertSpacingTable();

		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">");
		output.push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(L"<td height=\"13\"><a name=\"op7a\" /><b>" + GLanguageHandler->Text[kEmptyFolders] + L"</b></td>");
		output.push_back(L"</tr>");

		output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\" class=\"C4G\">");
		output.push_back(L"<td colspan=\"7\" height=\"13\">" + GLanguageHandler->Text[kGeneral] + L"</td>");
		output.push_back(L"</tr>");
		output.push_back(L"</table>");

		InsertSpacingTable();
		break;
	case kHTMLUsers:
		//-----------------------------------------------------------------
		//-- Username -----------------------------------------------------
		//-----------------------------------------------------------------
		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">");
		output.push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(L"<td colspan=\"7\" height=\"13\"><a name=\"op10\" /><b>" + GLanguageHandler->Text[kUsageByUser] + L"</b></td>");
		output.push_back(L"<tr>");
		output.push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(L"<td width=\"100\" height=\"13\"><b>" + GLanguageHandler->Text[kSmallestFiles] + L"</b></td>");
		output.push_back(L"<td width=\"64\" height=\"13\"><div align=\"center\"><b>" + GLanguageHandler->Text[kQty] + L"</b></div></td>");
		output.push_back(L"<td width=\"64\" height=\"13\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(L"<td width=\"160\" height=\"13\">&nbsp;</td>");
		output.push_back(L"<td width=\"85\" height=\"13\"><div align=\"center\"><b>" + GLanguageHandler->Text[kFileSize] + L"</b></div></td>");
		output.push_back(L"<td width=\"67\" height=\"13\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(L"<td width=\"160\" height=\"20\">&nbsp;</td>");
		output.push_back(L"</tr>");
		output.push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\">");
		output.push_back(L"<td width=\"100\" height=\"13\">Mr. R Andom</td>");
		output.push_back(L"<td width=\"64\" height=\"13\"><div align=\"center\">123</div></td>");
		output.push_back(L"<td width=\"64\" height=\"13\"><div align=\"center\">24</div></td>");
		output.push_back(L"<td width=\"160\">");
		output.push_back(L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(colour.Colour[5]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
		output.push_back(L"<tr><td></td></tr>");
		output.push_back(L"</table>");
		output.push_back(L"</td>");
		output.push_back(L"<td width=\"85\" height=\"13\"><div align=\"" + align + L"\">53</div></td>");
		output.push_back(L"<td width=\"67\" height=\"13\"><div align=\"center\">25</div></td>");
		output.push_back(L"<td width=\"160\">");
		output.push_back(L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(colour.Colour[5]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
		output.push_back(L"<tr><td></td></tr>");
		output.push_back(L"</table>");
		output.push_back(L"</td>");
		output.push_back(L"</tr>");
		output.push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(colour.Colour[11]) + L"\">");
		output.push_back(L"<td width=\"100\" height=\"13\">Mrs. S Quirrel</td>");
		output.push_back(L"<td width=\"64\" height=\"13\"><div align=\"center\">123</div></td>");
		output.push_back(L"<td width=\"64\" height=\"13\"><div align=\"center\">24</div></td>");
		output.push_back(L"<td width=\"160\">");
		output.push_back(L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(colour.Colour[5]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
		output.push_back(L"<tr><td></td></tr>");
		output.push_back(L"</table>");
		output.push_back(L"</td>");
		output.push_back(L"<td width=\"85\" height=\"13\"><div align=\"" + align + L"\">53</div></td>");
		output.push_back(L"<td width=\"67\" height=\"13\"><div align=\"center\">25</div></td>");
		output.push_back(L"<td width=\"160\">");
		output.push_back(L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(colour.Colour[5]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
		output.push_back(L"<tr><td></td></tr>");
		output.push_back(L"</table>");
		output.push_back(L"</td>");
		output.push_back(L"</tr>");

		InsertSpacingTable();
		break;
	case kHTMLNameLength:
		//-----------------------------------------------------------------
		//file name length ------------------------------------------------
		//-----------------------------------------------------------------
		output.push_back(L"<table align=\"center\" width=\"770\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">");
		output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[6]) + L"\">");
		output.push_back(L"<td width=\"100\" height=\"13\" class=\"C7G\"><a name=\"op3\" /><b>" + GLanguageHandler->Text[kLength] + L"</b></td>");
		output.push_back(L"<td width=\"64\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kQty] + L"</b></div></td>");
		output.push_back(L"<td width=\"64\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(L"<td width=\"160\" height=\"13\">&nbsp;</td>");
		output.push_back(L"<td width=\"85\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kFileSize] + L"</b></div></td>");
		output.push_back(L"<td width=\"67\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>");
		output.push_back(L"<td width=\"160\" height=\"20\">&nbsp;</td>");
		output.push_back(L"</tr>");

		//build the file category table
		for (int t = 0; t < 5; t++)
		{
			if (t % 2)
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[10]) + L"\">");
			}
			else
			{
				output.push_back(L"<tr bgcolor=\"#" + Convert::WebColour(colour.Colour[11]) + L"\">");
			}

			output.push_back(L"<td width=\"100\" class=\"C4G\"><div align=\"left\">" + std::to_wstring(t * 5) + L"</div></td>");
			output.push_back(L"<td width=\"64\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(2 + Random(1300)) + L"</div></td>");
			output.push_back(L"<td width=\"64\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(2 + Random(80)) + L"%</div></td>");
			output.push_back(L"<td width=\"160\">");
			output.push_back(L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->FileCategoryColors[t]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
			output.push_back(L"<tr><td></td></tr>");
			output.push_back(L"</table>");
			output.push_back(L"</td>");
			output.push_back(L"<td width=\"85\" class=\"C4G\"><div align=\"" + align + L"\">1GB</div></td>");
			output.push_back(L"<td width=\"67\" class=\"C4G\"><div align=\"center\">" + std::to_wstring(2 + Random(80)) + L"%</div></td>");
			output.push_back(L"<td width=\"160\">");
			output.push_back(L"<table width=\"" + std::to_wstring(2 + Random(130)) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->FileCategoryColors[t]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">");
			output.push_back(L"<tr><td></td></tr>");
			output.push_back(L"</table>");
			output.push_back(L"</td>");

			output.push_back(L"</tr>");
		}

		output.push_back(L"</table>");

		InsertSpacingTable();
		break;
	}
}
