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

// uses the Google Graph API
// https://developers.google.com/chart/

// https://plotly.com/javascript/


#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "ConstantsSystem.h"
#include "ConstantsReports.h"
#include "Convert.h"
#include "FileExtension.h"
#include "FileExtensionHandler.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportDeep.h"
#include "ReportHTML.h"
#include "ReportHTMLOptions.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "Utility.h"
#include "WindowsUtility.h"

extern FileExtensionHandler* GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SettingsHandler* GSettingsHandler;


namespace ReportHTML
{
	bool sortBySize(const UserData& lhs, const UserData& rhs) { return lhs.Size < rhs.Size; }


	void GenerateReport(HTMLReportOptions options)
	{
		if (options.DeepScan)
		{
			std::wcout << GLanguageHandler->Text[kSavingReports] + L" (HTML Deep): " + Formatting::TrimFileNameForOutput(options.FileName) << "\n";
		}
		else
		{
			std::wcout << GLanguageHandler->Text[kSavingReports] + L" (HTML): " + Formatting::TrimFileNameForOutput(options.FileName) << "\n";
		}

		std::wcout << "\n";

		// ============================================================================
		// == before we create the page, we need to create the graphs..... ============
		// ============================================================================

		std::wstring menu = BuildMenuList(options);

		// ============================================================================
		// == Lets write the file =====================================================
		// ============================================================================

		std::ofstream file(options.FileName);

		if (file)
		{
			file << Formatting::to_utf8(L"<html><head><title>FolderScanUltra analysis \"" + GScanEngine->Path.String + L"\"</title>\n");
			file << Formatting::to_utf8(L"<meta name=\"generator\" content=\"FolderScanUltra, (c) Paul Alan Freshney 2002-" + Utility::CurrentYear() + L", paul@freshney.org\">\n");
			file << Formatting::to_utf8(L"<meta name=\"debug\" content=\"" + std::to_wstring(options.LayoutSize) + L"\">\n");
			file << Formatting::to_utf8(L"<style type=\"text/css\">\n");
			file << Formatting::to_utf8(L"<!--\n");
			file << Formatting::to_utf8(L"A:link {color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[0]) + L"; text-decoration: none;}\n");
			file << Formatting::to_utf8(L"A:visited {color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[0]) + L"; text-decoration: none;}\n");
			file << Formatting::to_utf8(L"A:hover {color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[1]) + L"; text-decoration: underline;}\n");
			file << Formatting::to_utf8(L"A:active {color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[0]) + L"; text-decoration: none;}\n");
			file << Formatting::to_utf8(L".C4G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[3]) + L";}\n");
			file << Formatting::to_utf8(L".C4CB {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; font-weight: bold; color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[3]) + L";}\n");
			file << Formatting::to_utf8(L".C4C {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[3]) + L";}\n");
			file << Formatting::to_utf8(L".C4L {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:left; color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[3]) + L";}\n");
			file << Formatting::to_utf8(L".C4R {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:right; color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[3]) + L";}\n");
			file << Formatting::to_utf8(L".C7G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[6]) + L";}\n");
			file << Formatting::to_utf8(L".C7CB {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; font-weight: bold; color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[6]) + L";}\n");
			file << Formatting::to_utf8(L".C7C {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; color:#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[6]) + L";}\n");
			file << Formatting::to_utf8(L".XCB {text-align:center; font-weight: bold;}\n");
			file << Formatting::to_utf8(L"-->\n");
			file << Formatting::to_utf8(L"</style></head>\n");
			file << Formatting::to_utf8(L"<body leftmargin=\"5\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[2]) + L"\" text=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[7]) + L"\" topmargin=\"5\">\n");

			// ===========================================================================

			if (options.Layout[0])
			{
				BuildGraphScript(file, options);
			}

			// ===========================================================================

			for (int t = 0; t < __HTMLLayoutOptionsCount; t++)
			{
				if (options.Layout[t])
				{
					switch (t)
					{
					case 0:
						ReportHeader(file, options, menu);
						ReportQuickInfo(file, options);

						if (GScanEngine->Path.ExcludeFolders)
						{
							ReportExclude(file, options);
						}

						break;
					case 1:
						ReportFileAttributesTable(file, options);
						break;
					case 2:
						ReportFileCategory(file, options);
						break;
					case 3:
						ReportDirectoryList(1, file, options);
						break;
					case 4:
						ReportMagnitude(file, options);
						break;
					case 5:
						ReportFileExtensionLists(file, options);
						break;
					case 6:
						ReportNullFiles(file, options);
						break;
					case 7:
						ReportFileDates(file, options);
						break;
					case 8:
						ReportTop101Largest(file, options);
						ReportTop101Smallest(file, options);

						ReportTop101Newest(file, options);
						ReportTop101Oldest(file, options);
						break;
					case 9:
						ReportUsers(file, options);
						break;
					case 10:
						ReportTemporary(file);
						break;
					}
				}
			}

			if (options.DeepScan)
			{
				CreateDeepReport(file, options);
			}

			// ===========================================================================
			// footer table. always gets added

			file << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
			file << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">\n");
			file << Formatting::to_utf8(L"<td align=\"center\" class=\"C7G\">\n");
			file << Formatting::to_utf8(L"<a href=\"mailto:paul@freshney.org\">paul@freshney.org</a> / <a href=\"https://github.com/MaximumOctopus/FolderScanUltra\" target=\"_blank\">https://github.com/MaximumOctopus/FolderScanUltra</a></td>\n");
			file << Formatting::to_utf8(L"</tr>\n");
			file << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\" class=\"C7G\"><td align=\"center\">(c) Paul Alan Freshney 2002-" + Utility::CurrentYear() + L"</td></tr>");
			file << Formatting::to_utf8(L"</table></body></html>\n");

			file.close();
		}
		else
		{
			std::wcout << L"\n";
			std::wcout << GLanguageHandler->Text[kErrorSaving] + L" \"" + options.FileName + L"\".\n";
			std::wcout << L"\n";
		}
	}


	void CreateDeepReport(std::ofstream& ofile, HTMLReportOptions options)
	{
		ReportDeep deep;

		int anchor = 50;

		for (int r = 0; r < GScanEngine->Data.RootFolders.size(); r++)
		{
			std::wstring folder = GScanEngine->Path.String;

			if (GScanEngine->Data.RootFolders[r].Name != L"root")
			{
				folder += GScanEngine->Data.RootFolders[r].Name + L"\\";
			}

			int folderIndex = GScanEngine->GetFolderIndex(folder);

			if (folderIndex != -1)
			{
				if (!deep.ProcessFolder(folderIndex))
				{
					// if there are no sub-folders then use the root folder's data
					deep.Add(L"\"", GScanEngine->Data.RootFolders[r].Size, GScanEngine->Data.RootFolders[r].Count);
				}

				if (deep.FolderData.size() != 0)
				{
					SevenColumnTableDoubleTitleHeader(ofile, L"op" + std::to_wstring(anchor), folder, GLanguageHandler->Text[kFolder]);

					int largeSize = 0;
					int largeCount = 0;

					largeCount = std::round(((double)deep.largestCount / (double)GScanEngine->Data.FileCount) * 100);
					largeSize = std::round(((double)deep.largestSize / (double)GScanEngine->Data.TotalSize) * 100);

					if (largeCount <= 0) largeCount = __ReportSizes[__rsBarGraph];
					if (largeSize <= 0) largeSize = __ReportSizes[__rsBarGraph];

					for (int s = 0; s < deep.FolderData.size(); s++)
					{
						SevenColumnTableRow(ofile, s, deep.FolderData[s].Folder,
							std::to_wstring(deep.FolderData[s].FileCount),
							Convert::DoubleToPercent((double)deep.FolderData[s].FileCount / (double)GScanEngine->Data.FileCount),
							Convert::GetSizeString(options.Units, deep.FolderData[s].Size),
							Convert::DoubleToPercent((double)deep.FolderData[s].Size / (double)GScanEngine->Data.TotalSize),
							GSettingsHandler->Reports.HTMLColours[4],
							(((double)deep.FolderData[s].FileCount / (double)GScanEngine->Data.FileCount) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)largeCount),
							(((double)deep.FolderData[s].Size / (double)GScanEngine->Data.TotalSize) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)largeSize)
						);
					}

					ofile << Formatting::to_utf8(L"</table>\n");

					anchor++;

					InsertSpacingTable(ofile);
				}
			}
			else
			{
				std::wcout << " Error cannot find folder \"" << folder << "\"\n";
			}
		}
	}


	void ReportHeader(std::ofstream& ofile, HTMLReportOptions options, std::wstring menu_string)
	{
		// ============================================================================
		// == header table ============================================================
		// ============================================================================

		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C4G\">\n");

		ofile << Formatting::to_utf8(L"<td class=\"C4C\"><b>FolderScanUltra " + __XVersion + L"</b> " + GLanguageHandler->Text[kReportFor] +
			L" <b><a href=\"" + Utility::WebFileLink(GScanEngine->Path.String) + L"\">" + GScanEngine->Path.String + L"</a></b></td>\n");

		ofile << Formatting::to_utf8(L"</tr>\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C4C\">\n");
		ofile << Formatting::to_utf8(L"<td>" + GLanguageHandler->Text[kAnalysedAt] + L" <b>" + Utility::GetTime(DateTimeFormat::Display) + L"</b>, <b>" + Utility::GetDate(DateTimeFormat::Display) + L"</b>.</td>\n");
		ofile << Formatting::to_utf8(L"</tr>\n");

		if (GScanEngine->Data.Source == ScanSource::CSVImport)
		{
			ofile << Formatting::to_utf8(L"<tr class=\"C4C\">\n");
			ofile << Formatting::to_utf8(L"<td>CSV Source: <b>" + GScanEngine->Path.CSVSource + L"</b>.</td>\n");
			ofile << Formatting::to_utf8(L"</tr>\n");
		}

		if (GScanEngine->FilterCategory != -1)
		{
			ofile << Formatting::to_utf8(L"<tr class=\"C4C\">\n");
			ofile << Formatting::to_utf8(L"<td>Filtered by category <b>" + __FileExtensionFileName[GScanEngine->FilterCategory] + L"</b>.</td>\n");
			ofile << Formatting::to_utf8(L"</tr>\n");
		}
	
		ofile << Formatting::to_utf8(L"</table>\n");

		InsertSpacingTable(ofile);

		// ============================================================================
		// == navigation table ========================================================
		// ============================================================================

		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">" +
			L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\"><td class=\"C7G\"><strong>Menu</strong></td></tr>" +
			L"<tr class=\"C4C\"><td>" + menu_string + L"</td></tr></table>\n");

		InsertSpacingTable(ofile);
	}


	void ReportFileCategory(std::ofstream& ofile, HTMLReportOptions options)
	{
		// ============================================================================
		// == file category table =====================================================
		// ============================================================================

		SevenColumnTableHeader(ofile, L"op2", GLanguageHandler->Text[kCategory]);

		if (GScanEngine->Data.FileCount != 0)
		{
			int rowidx = 1;
			int large1 = 0;
			int large2 = 0;

			if (GScanEngine->Data.TotalSize != 0)
			{
				//find largest category %

				for (int t = 0; t < __FileCategoriesCount; t++)
				{
					if (std::round(((double)GScanEngine->Data.ExtensionSpread[t].Size / (double)GScanEngine->Data.TotalSize) * 100) > large2) { large2 = std::round(((double)GScanEngine->Data.ExtensionSpread[t].Size / (double)GScanEngine->Data.TotalSize) * 100); }
					if (std::round(((double)GScanEngine->Data.ExtensionSpread[t].Count / (double)GScanEngine->Data.FileCount) * 100) > large1) { large1 = std::round(((double)GScanEngine->Data.ExtensionSpread[t].Count / (double)GScanEngine->Data.FileCount) * 100); }
				}

				if (large1 <= 0) large1 = __ReportSizes[__rsBarGraph];
				if (large2 <= 0) large2 = __ReportSizes[__rsBarGraph];

				//build the file category table
				for (int t = 1; t < __FileCategoriesCount; t++)
				{
					if (GScanEngine->Data.ExtensionSpread[t].Count != 0)
					{
						SevenColumnTableRow(ofile, rowidx, GLanguageHandler->TypeDescriptions[t],
							std::to_wstring(GScanEngine->Data.ExtensionSpread[t].Count),
							Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[t].Count / (double)GScanEngine->Data.FileCount),
							Convert::GetSizeString(options.Units, GScanEngine->Data.ExtensionSpread[t].Size),
							Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[t].Size / (double)GScanEngine->Data.TotalSize),
							GSettingsHandler->FileCategoryColors[t],
							(((double)GScanEngine->Data.ExtensionSpread[t].Count / (double)GScanEngine->Data.FileCount) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large1),
							(((double)GScanEngine->Data.ExtensionSpread[t].Size / (double)GScanEngine->Data.TotalSize) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large2)
						);

						rowidx++;
					}
				}
			}

			SevenColumnTableRowBlank(ofile, rowidx, L"");

			rowidx++;

			// ==================================================================

			SevenColumnTableRow(ofile, rowidx, GLanguageHandler->Text[kTemporary],
				std::to_wstring(GScanEngine->Data.ExtensionSpread[0].Count),
				Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[0].Count / (double)GScanEngine->Data.FileCount),
				Convert::GetSizeString(options.Units, GScanEngine->Data.ExtensionSpread[0].Size),
				Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[0].Size / (double)GScanEngine->Data.TotalSize),
				0x000000,
				(((double)GScanEngine->Data.ExtensionSpread[0].Count / (double)GScanEngine->Data.FileCount) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large1),
				(((double)GScanEngine->Data.ExtensionSpread[0].Size / (double)GScanEngine->Data.TotalSize) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large2)
			);

			ofile << Formatting::to_utf8(L"</table>\n");

			InsertSpacingTable(ofile);

			//build the graph table
			if (options.Layout[0])
			{
				DoubleGraph(ofile, L"chartCategory1", L"chartCategory2");

				InsertSpacingTable(ofile);
			}
		}
	}


	void ReportFileAttributesTable(std::ofstream& ofile, HTMLReportOptions options)
	{
		// ============================================================================
		// == file attributes table ===================================================
		// ============================================================================

		SevenColumnTableHeader(ofile, L"op2", GLanguageHandler->Text[kFileAttributes]);

		if (GScanEngine->Data.FileCount > 0)
		{
			if (GScanEngine->Data.TotalSize > 0)
			{
				//find largest category %

				int large1 = 0;
				int large2 = 0;

				for (int t = 0; t < __AttributesToDisplayCount; t++)
				{
					if (std::round(((double)GScanEngine->Data.FileAttributes[t].Count / (double)GScanEngine->Data.FileCount) * 100) > large1) { large1 = std::round(((double)GScanEngine->Data.FileAttributes[t].Count / (double)GScanEngine->Data.FileCount) * 100); };
					if (std::round(((double)GScanEngine->Data.FileAttributes[t].Size / (double)GScanEngine->Data.TotalSize) * 100) > large2) { large2 = std::round(((double)GScanEngine->Data.FileAttributes[t].Size / (double)GScanEngine->Data.TotalSize) * 100); };
				}

				if (large1 <= 0) large1 = __ReportSizes[__rsBarGraph];
				if (large2 <= 0) large2 = __ReportSizes[__rsBarGraph];

				//build the file category table
				for (int t = 0; t < __AttributesToDisplayCount; t++)
				{
					SevenColumnTableRow(ofile, t, GLanguageHandler->LanguageTypes[t],
						std::to_wstring(GScanEngine->Data.FileAttributes[t].Count),
						Convert::DoubleToPercent((double)GScanEngine->Data.FileAttributes[t].Count / (double)GScanEngine->Data.FileCount),
						Convert::GetSizeString(options.Units, GScanEngine->Data.FileAttributes[t].Size),
						Convert::DoubleToPercent((double)GScanEngine->Data.FileAttributes[t].Size / (double)GScanEngine->Data.TotalSize),
						GSettingsHandler->Reports.HTMLColours[4],
						(((double)GScanEngine->Data.FileAttributes[t].Count / (double)GScanEngine->Data.FileCount) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large1),
						(((double)GScanEngine->Data.FileAttributes[t].Size / (double)GScanEngine->Data.TotalSize) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large2)
					);
				}
			}
		}

		ofile << Formatting::to_utf8(L"</table>\n");

		InsertSpacingTable(ofile);
	}


	void ReportUsers(std::ofstream& ofile, HTMLReportOptions options)
	{
		// ============================================================================
		// == Username ================================================================
		// ============================================================================

		SevenColumnTableDoubleTitleHeader(ofile, L"op10", GLanguageHandler->Text[kUsageByUser], GLanguageHandler->Text[kOwner]);

		if (GScanEngine->Data.FileCount != 0)
		{
			if (GScanEngine->Data.TotalSize != 0)
			{
				int large1 = 0;
				int large2 = 0;
				int rowidx = 1;

				for (int i = 0; i < GScanEngine->Data.Users.size(); i++)
				{
					if (std::round(((double)GScanEngine->Data.Users[i].Count / (double)GScanEngine->Data.FileCount) * 100) > large1) { large1 = std::round(((double)GScanEngine->Data.Users[i].Count / (double)GScanEngine->Data.FileCount) * 100); }
					if (std::round(((double)GScanEngine->Data.Users[i].Size / (double)GScanEngine->Data.TotalSize) * 100) > large2) { large2 = std::round(((double)GScanEngine->Data.Users[i].Size / (double)GScanEngine->Data.TotalSize) * 100); }
				}

				if (large1 <= 0) large1 = __ReportSizes[__rsBarGraph];
				if (large2 <= 0) large2 = __ReportSizes[__rsBarGraph];

				// ============================================================

				std::sort(GScanEngine->Data.Users.begin(), GScanEngine->Data.Users.end(), sortBySize);

				// ============================================================

				for (int t = 0; t < GScanEngine->Data.Users.size(); t++)
				{
					SevenColumnTableRow(ofile, rowidx, GScanEngine->Data.Users[t].Name,
						std::to_wstring(GScanEngine->Data.Users[t].Count),
						Convert::DoubleToPercent((double)GScanEngine->Data.Users[t].Count / (double)GScanEngine->Data.FileCount),
						Convert::GetSizeString(options.Units, GScanEngine->Data.Users[t].Size),
						Convert::DoubleToPercent((double)GScanEngine->Data.Users[t].Size / (double)GScanEngine->Data.TotalSize),
						GSettingsHandler->Reports.HTMLColours[4],
						(((double)GScanEngine->Data.Users[t].Count / (double)GScanEngine->Data.FileCount) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large1),
						((double)(GScanEngine->Data.Users[t].Size / (double)GScanEngine->Data.TotalSize) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large2)
					);

					rowidx++;
				}

				InsertSpacingTable(ofile);
			}
		}
	}


	void ReportTemporary(std::ofstream& ofile)
	{
		int rowidx = 0;

		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\"><td height=\"13\"><a name=\"op7\" /><b>" + GLanguageHandler->Text[kTempFiles] + L"</b></td></tr>\n");

		if (GScanEngine->Data.TemporaryFiles.size() == 0)
		{
			ofile << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\" class=\"C4G\"><td colspan=\"7\" height=\"13\">" + GLanguageHandler->Text[kNoneFound] + L"</td></tr>\n");
		}
		else
		{
			for (int t = 0; t < GScanEngine->Data.TemporaryFiles.size(); t++)
			{
				if (t % 2 == 0)
				{
					ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
				}
				else
				{
					ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[10]) + L"\">\n");
				}

				ofile << Formatting::to_utf8(L"<td height=\"13\">" + GScanEngine->Data.TemporaryFiles[t] + L"</td>\n");

				ofile << Formatting::to_utf8(L"</tr>\n");

				rowidx++;
			}
		}

		ofile << Formatting::to_utf8(L"</table>\n");

		InsertSpacingTable(ofile);
	}


	void ReportFileExtensionLists(std::ofstream &ofile, HTMLReportOptions options)
	{
		// ============================================================================
		// == File Extesnion Lists ====================================================
		// ============================================================================

		if (GScanEngine->Data.FileCount != 0)
		{
			if (GScanEngine->Data.TotalSize != 0)
			{
				int large1 = 0;
				int large2 = 0;
				int linecount = 0;
				int rowidx;
				int percentage = 0;
		
				for (int i = 0; i < GFileExtensionHandler->Extensions.size(); i++)
				{
					if (std::round(((double)GFileExtensionHandler->Extensions[i]->Count / (double)GScanEngine->Data.FileCount) * 100) > large1) { large1 = std::round(((double)GFileExtensionHandler->Extensions[i]->Count / (double)GScanEngine->Data.FileCount) * 100); }
					if (std::round(((double)GFileExtensionHandler->Extensions[i]->Size / (double)GScanEngine->Data.TotalSize) * 100) > large2) { large2 = std::round(((double)GFileExtensionHandler->Extensions[i]->Size / (double)GScanEngine->Data.TotalSize) * 100); }
				}

				if (large1 <= 0) large1 = __ReportSizes[__rsBarGraph];
				if (large2 <= 0) large2 = __ReportSizes[__rsBarGraph];

				for (int t = 1; t < __FileCategoriesCount; t++)
				{
					if ((options.CategoryList[t]) && (GScanEngine->Data.ExtensionSpread[t].Count != 0))
					{
						SevenColumnTableDoubleTitleHeader(ofile, L"op6",
							GLanguageHandler->TypeDescriptions[t] + L" [ " + std::to_wstring(GScanEngine->Data.ExtensionSpread[t].Count) + L" files (" + Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[t].Count / (double)GScanEngine->Data.FileCount) + L") / " + Convert::GetSizeString(options.Units, GScanEngine->Data.ExtensionSpread[t].Size) + L" (" + Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[t].Size / (double)GScanEngine->Data.TotalSize) + L") ]",
							GLanguageHandler->Text[kExtension]
						);

						linecount = 0;
						
						if (t != __FileCategoriesOther)
						{
							rowidx = 1;

							for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
							{
								FileExtension *tfx = GFileExtensionHandler->Extensions[z];

								if (tfx->Category == t)
								{
									//only include within report if number of files in extension > 0
									if (tfx->Count > 0)
									{
										SevenColumnTableRow(ofile, rowidx, tfx->Name,
											std::to_wstring(tfx->Count),
											Convert::DoubleToPercent((double)tfx->Count / (double)GScanEngine->Data.FileCount),
											Convert::GetSizeString(options.Units, tfx->Size),
											Convert::DoubleToPercent((double)tfx->Size / (double)GScanEngine->Data.TotalSize),
											GSettingsHandler->Reports.HTMLColours[4],
											(((double)tfx->Count / (double)GScanEngine->Data.FileCount) * 100)* ((double)__ReportSizes[__rsBarGraph] / (double)large1),
											(((double)tfx->Size / (double)GScanEngine->Data.TotalSize) * 100)* ((double)__ReportSizes[__rsBarGraph] / (double)large2)
											);
	
										linecount++;

										rowidx++;
									}
								}
							}
						}
						else 
						{
							large1 = 0;
							large2 = 0;

							for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
							{
								if (GFileExtensionHandler->Extensions[z]->Category == __Category_Other)
								{
									if (std::round((((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data.FileCount)) * 100) > large1) { large1 = std::round((((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data.FileCount)) * 100); }
									if (std::round(((double)GFileExtensionHandler->Extensions[z]->Size / (double)GScanEngine->Data.TotalSize) * 100) > large2) { large2 = std::round(((double)GFileExtensionHandler->Extensions[z]->Size / (double)GScanEngine->Data.TotalSize) * 100); }
								}
							}

							if (large1 <= 0) large1 = __ReportSizes[__rsBarGraph];
							if (large2 <= 0) large2 = __ReportSizes[__rsBarGraph];

							rowidx = 1;

							for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
							{
								if (GFileExtensionHandler->Extensions[z]->Category == __Category_Other)
								{
									//only include within report if number of files in extension > 0
									if (GFileExtensionHandler->Extensions[z]->Count != 0)
									{
										// ==================================================================
										if (rowidx % 2 != 0)
										{
											ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
										}
										else
										{
											ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[10]) + L"\">\n");
										}

										rowidx++;
										// ==================================================================


										if (GFileExtensionHandler->Extensions[z]->Name.empty())
										{
											ofile << Formatting::to_utf8(L"<td width=\"100\" height=\"13\"><i>none</i></td>\n");
										}
										else
										{
											ofile << Formatting::to_utf8(L"<td width=\"100\" height=\"13\">" + GFileExtensionHandler->Extensions[z]->Name + L"</td>\n");
										}

										ofile << Formatting::to_utf8(L"<td width=\"64\" height=\"13\"><div align=\"center\">" + std::to_wstring(GFileExtensionHandler->Extensions[z]->Count) + L"</div></td>\n");
										ofile << Formatting::to_utf8(L"<td width=\"64\" height=\"13\"><div align=\"center\">" + Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data.FileCount) + L"</div></td>\n");
										ofile << Formatting::to_utf8(L"<td width=\"160\">\n");
										
										if (large1 != 0)
										{
											ofile << Formatting::to_utf8(L"<table width=\"" + std::to_wstring(std::round((((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data.FileCount) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large1))) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[4]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
										}
										else
										{
											ofile << Formatting::to_utf8(L"<table width=\"1\" border=\"0\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[4]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
										}
										
										ofile << Formatting::to_utf8(L"<tr><td></td></tr></table></td>\n");
										ofile << Formatting::to_utf8(L"<td width=\"85\" height=\"13\"><div align=\"" + options.Align + L"\">" + Convert::GetSizeString(options.Units, GFileExtensionHandler->Extensions[z]->Size) + L"</div></td>\n");

										percentage = std::round((((double)GFileExtensionHandler->Extensions[z]->Size) / (double)GScanEngine->Data.TotalSize) * 100);

										ofile << Formatting::to_utf8(L"<td width=\"67\" height=\"13\"><div align=\"center\">" + Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z]->Size / (double)GScanEngine->Data.TotalSize) + L"</div></td>\n");
										ofile << Formatting::to_utf8(L"<td width=\"160\">\n");

										if (large2 != 0)
										{
											ofile << Formatting::to_utf8(L"<table width=\"" + std::to_wstring(std::round((double)percentage * ((double)__ReportSizes[__rsBarGraph] / (double)large2))) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[4]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
										}
										else
										{
											ofile << Formatting::to_utf8(L"<table width=\"1\" border=\"0\" bgcolor = \"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[4]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
										}
										
										ofile << Formatting::to_utf8(L"<tr><td></td></tr>\n");
										ofile << Formatting::to_utf8(L"</table>\n");
										ofile << Formatting::to_utf8(L"</td>\n");
										ofile << Formatting::to_utf8(L"</tr>\n");

										linecount++;
									}
								}
							}
						}

						if (linecount == 0)
						{
							ofile << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\"><td colspan=\"7\" height=\"13\" class=\"C4G\">" + GLanguageHandler->Text[kNoneFound] + L".</td></tr>\n");
						}

						ofile << Formatting::to_utf8(L"</table>\n");

						InsertSpacingTable(ofile);
					}
				}
			}
		}
	}


	void ReportMagnitude(std::ofstream &ofile, HTMLReportOptions options)
	{
		// ============================================================================
		// == magnitude table =========================================================
		// ============================================================================

		SevenColumnTableHeader(ofile, L"op5", GLanguageHandler->Text[kMagnitude]);

		if (GScanEngine->Data.FileCount != 0)
		{
			//find largest category %
			if (GScanEngine->Data.TotalSize != 0)
			{
				int large1 = 0;
				int large2 = 0;

				for (int t = 0; t < __MagnitudesCount; t++)
				{
					if (std::round(((double)GScanEngine->Data.Magnitude[t].Count / (double)GScanEngine->Data.FileCount) * 100) > large1) { large1 = std::round(((double)GScanEngine->Data.Magnitude[t].Count / (double)GScanEngine->Data.FileCount) * 100); }
					if (std::round(((double)GScanEngine->Data.Magnitude[t].Size / (double)GScanEngine->Data.TotalSize) * 100) > large2) { large2 = std::round(((double)GScanEngine->Data.Magnitude[t].Size / (double)GScanEngine->Data.TotalSize) * 100); }
				}

				if (large1 <= 0) large1 = __ReportSizes[__rsBarGraph];
				if (large2 <= 0) large2 = __ReportSizes[__rsBarGraph];

				//build the file category table
				for (int t = 0; t < __MagnitudesCount; t++)
				{
					SevenColumnTableRow(ofile, t, __MagnitudeLabels[t],
						std::to_wstring(GScanEngine->Data.Magnitude[t].Count),
						Convert::DoubleToPercent((double)GScanEngine->Data.Magnitude[t].Count / (double)GScanEngine->Data.FileCount),
						Convert::GetSizeString(options.Units, GScanEngine->Data.Magnitude[t].Size),
						Convert::DoubleToPercent((double)GScanEngine->Data.Magnitude[t].Size / (double)GScanEngine->Data.TotalSize),
						__MagnitudeColours[t],
						(((double)GScanEngine->Data.Magnitude[t].Count / (double)GScanEngine->Data.FileCount) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large1),
						(((double)GScanEngine->Data.Magnitude[t].Size / (double)GScanEngine->Data.TotalSize) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large2)
					);
				}

				ofile << Formatting::to_utf8(L"</table>\n");

				InsertSpacingTable(ofile);

				if (options.Layout[0])
				{
					DoubleGraph(ofile, L"chartMagnitude1", L"chartMagnitude2");

					InsertSpacingTable(ofile);
				}
			}
		}
	}


	void ReportQuickInfo(std::ofstream &ofile, HTMLReportOptions options)
	{
		// ============================================================================
		// == quick info table ========================================================
		// ============================================================================

		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" height=\"180\" border=\"0\" cellspacing=\"1\" cellpadding=\"1\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
		ofile << Formatting::to_utf8(L"<tr><td width=\"100%\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\" class=\"C7G\"><strong>" + GLanguageHandler->Text[kSummary] + L"</strong></td></tr>\n");
		ofile << Formatting::to_utf8(L"<tr>\n");
		ofile << Formatting::to_utf8(L"<td>\n");
		ofile << Formatting::to_utf8(L"<table width=\"100%\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		ofile << Formatting::to_utf8(L"<tr>\n");
		ofile << Formatting::to_utf8(L"<td width=\"350\" rowspan=\"11\"><div align=\"center\" id=\"chartQuickInfo1\"></div></td>\n");
		ofile << Formatting::to_utf8(L"<td width=\"350\" rowspan=\"11\"><div align=\"center\" id=\"chartQuickInfo2\"></div></td>\n");
		ofile << Formatting::to_utf8(L"<td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kNumberOfFiles] + L" </td>\n");
		ofile << Formatting::to_utf8(L"<td width=\"92\" class=\"C4L\"> <b>" + std::to_wstring(GScanEngine->Data.FileCount) + L"</b></td>\n");
		ofile << Formatting::to_utf8(L"</tr>\n");

		ofile << Formatting::to_utf8(L"<tr><td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kNumberOfFolders] +
				L" </td><td width=\"92\" class=\"C4L\"> <b>" + std::to_wstring(GScanEngine->Data.FolderCount) +	L"</b></td></tr>\n");
		ofile << Formatting::to_utf8(L"<tr><td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kTotalSizeofFilesAnalysed] + L" </td><td width=\"92\" class=\"C4L\"> <b>" + Convert::ConvertToUsefulUnit(GScanEngine->Data.TotalSize) + L"</b></td></tr>\n");
		ofile << Formatting::to_utf8(L"<tr><td width=\"170\" class=\"C4G\">&nbsp;</td><td width=\"92\" class=\"C4G\">&nbsp;</td></tr>\n");
		ofile << Formatting::to_utf8(L"<tr>\n");
		ofile << Formatting::to_utf8(L"<td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kDiskSpaceUsed] + L" </td>\n");

		if (GScanEngine->DiskStats.DriveSpaceUsed > 0)
		{
			ofile << Formatting::to_utf8(L"<td width=\"92\" class=\"C4L\"> <b>" + Convert::ConvertToUsefulUnit(GScanEngine->DiskStats.DriveSpaceUsed) + L"</b></td>\n");
		}
		else
		{
			ofile << Formatting::to_utf8(L"<td width=\"92\" class=\"C4L\"> <b>" + GLanguageHandler->Text[kUnknown] + L"</b></td>\n");
		}

		ofile << Formatting::to_utf8(L"</tr>\n");

		ofile << Formatting::to_utf8(L"<tr>\n");
		ofile << Formatting::to_utf8(L"<td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kDiskSpaceWasted] + L" </td>\n");

		if (GScanEngine->Data.TotalSizeOD >= GScanEngine->Data.TotalSize)
		{
			ofile << Formatting::to_utf8(L"<td width=\"92\" class=\"C4L\"> <b>" + Convert::ConvertToUsefulUnit(GScanEngine->Data.TotalSizeOD - GScanEngine->Data.TotalSize) + L"</b></td>\n");
		}
		else
		{
			ofile << Formatting::to_utf8(L"<td width=\"92\" class=\"C4L\"> <b>" + GLanguageHandler->Text[kUnknown] + L"</b></td>\n");
		}

		ofile << Formatting::to_utf8(L"</tr>\n");
		ofile << Formatting::to_utf8(L"<tr><td width=\"170\" class=\"C4G\">&nbsp;</td><td width=\"92\" class=\"C4G\">&nbsp;</td></tr>\n");

		if (GScanEngine->DiskStats.DriveSpaceFree > 0)
		{
			ofile << Formatting::to_utf8(L"<tr><td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kDiskSpaceFree] + L" </td>" +
				L"<td width=\"92\" class=\"C4L\"> <b>" + Convert::ConvertToUsefulUnit(GScanEngine->DiskStats.DriveSpaceFree) + L"</b></td>" +
				L"</tr>\n");
		}
		else
		{
			ofile << Formatting::to_utf8(L"<tr><td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kDiskSpaceFree] + L" </td><td width=\"92\" class=\"C4L\"> <b>?</b> </td></tr>\n");
		}
		
		ofile << Formatting::to_utf8(L"<tr><td width=\"170\" class=\"C4G\">&nbsp;</td><td width=\"92\" class=\"C4G\">&nbsp;</td></tr>\n");
		ofile << Formatting::to_utf8(L"<tr><td width=\"170\" class=\"C4G\">&nbsp;</td><td width=\"92\" class=\"C4G\">&nbsp;</td></tr>\n");
		ofile << Formatting::to_utf8(L"</table>\n");
		ofile << Formatting::to_utf8(L"</td>\n");
		ofile << Formatting::to_utf8(L"</tr>\n");
		ofile << Formatting::to_utf8(L"</table>\n");
	
		InsertSpacingTable(ofile);
	}


	void ReportExclude(std::ofstream& ofile, HTMLReportOptions options)
	{
		// ============================================================================
		// == excluded folders ========================================================
		// ============================================================================

		std::wstring FolderList = L"";

		for (int t = 0; t < GScanEngine->ExcludeCount(); t++)
		{
			FolderList += GScanEngine->GetExcludeItem(t);

			if (t != GScanEngine->ExcludeCount() - 1)
			{
				FolderList += L", ";
			}
		}

		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellspacing=\"1\" cellpadding=\"1\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
		ofile << Formatting::to_utf8(L"<tr><td width=\"100%\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\" class=\"C7G\"><strong>Excluded Folders</strong></td></tr>\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C4L\"><td>Folder Pattern List: <strong>" + FolderList + L"</strong></td></tr>\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C4L\"><td>&nbsp;</td></tr>\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C4L\"><td>Excluded <strong>" + std::to_wstring(GScanEngine->Path.ExcludedFolderCount) + L"</strong> folders (top level)</td></tr>\n");
		ofile << Formatting::to_utf8(L"</table>\n");

		InsertSpacingTable(ofile);
	}


	void ReportDirectoryList(int fileDatesCount, std::ofstream &ofile, HTMLReportOptions options)
	{
		// ============================================================================
		// == directory list---by file count ==========================================
		// ============================================================================

		FourColumnTableDoubleTitleHeader(ofile, L"op4", GLanguageHandler->Text[kFoldersRootQuantity], GLanguageHandler->Text[kFolder], GLanguageHandler->Text[kQtyOfFiles], GLanguageHandler->Text[kAsPercent]);

		if (GScanEngine->Data.FileCount != 0)
		{
			//find largest category %
			int large1 = 0;
			int rowidx = 1;
			int colour = 0;

			for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
			{
				if (std::round(((double)GScanEngine->Data.RootFolders[t].Count / (double)GScanEngine->Data.FileCount) * 100) > large1)
				{
					large1 = std::round(((double)GScanEngine->Data.RootFolders[t].Count / (double)GScanEngine->Data.FileCount) * 100);
				}
			}
			
			if (large1 <= 0) { large1 = __ReportSizes[__rsBarGraphSmall]; }

// to do			std::ranges::sort(GScanEngine->Data.RootFolders, {}, &RootFolder::Count);
			
			for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
			{
				if (GScanEngine->Data.RootFolders[t].Count != 0)
				 {
					if (GSettingsHandler->Reports.HTMLMonoBargraph)
					{
						colour = GSettingsHandler->Reports.HTMLColours[4];
					}
					else
					{
						colour = __SpectrumColours[t % __SpectrumMod];
					}

					// ==================================================================

					std::wstring link = L"";

					if (t == 0)
					{
						link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Path.String) + L"\" target=\"_blank\">" + Formatting::MakeItalic(GScanEngine->Data.RootFolders[t].Name, GScanEngine->Data.RootFolders[t].Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
					}
					else
					{
						link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Path.String + GScanEngine->Data.RootFolders[t].Name) + L"\" target=\"_blank\">" + Formatting::MakeItalic(GScanEngine->Data.RootFolders[t].Name, GScanEngine->Data.RootFolders[t].Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
					}

					FourColumnTableRow(ofile, rowidx, link,
						std::to_wstring(GScanEngine->Data.RootFolders[t].Count),
						Convert::DoubleToPercent((double)GScanEngine->Data.RootFolders[t].Count / (double)GScanEngine->Data.FileCount),
						colour,
						(((double)GScanEngine->Data.RootFolders[t].Count / (double)GScanEngine->Data.FileCount) * 100) * ((double)__ReportSizes[__rsBarGraphSmall] / (double)large1)
					);

					rowidx++;
				}
			}
				
			ofile << Formatting::to_utf8(L"</table>\n");

			if ((options.Layout[0]) && (fileDatesCount != 0))
			{
				SingleGraph(ofile, kQuantity, L"chartDirectory1");
			}

			InsertSpacingTable(ofile);

			// ============================================================================
			// == directory list---by file size ===========================================
			// ============================================================================
			
			FourColumnTableDoubleTitleHeader(ofile, L"op4", GLanguageHandler->Text[kFoldersRootSize], GLanguageHandler->Text[kFolder], GLanguageHandler->Text[kSizeOfFiles], GLanguageHandler->Text[kAsPercent]);

			if (GScanEngine->Data.TotalSize != 0)
			{
				//find largest category %
				large1  = 0;

				for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
				{
					if (std::round(((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize) * 100) > large1)
					{
						large1 = std::round(((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize) * 100);
					}
				}

				if (large1 <= 0) { large1 = __ReportSizes[__rsBarGraphSmall]; }

				rowidx = 1;

// to do				std::ranges::sort(GScanEngine->Data.RootFolders, {}, &RootFolder::Size);

				for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
				{
					if (GScanEngine->Data.RootFolders[t].Count != 0)
					{
						if (GSettingsHandler->Reports.HTMLMonoBargraph)
						{
							colour = GSettingsHandler->Reports.HTMLColours[4];
						}
						else
						{
							colour = __SpectrumColours[t % __SpectrumMod];
						}

						std::wstring link = L"";
						
						if (t == 0)
						{
							link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Path.String) + L"\" target=\"_blank\">" + Formatting::MakeItalic(GScanEngine->Data.RootFolders[t].Name, GScanEngine->Data.RootFolders[t].Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
						}
						else
						{
							link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Path.String + GScanEngine->Data.RootFolders[t].Name) + L"\" target=\"_blank\">" + Formatting::MakeItalic(GScanEngine->Data.RootFolders[t].Name, GScanEngine->Data.RootFolders[t].Attributes  & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
						}

						FourColumnTableRow(ofile, rowidx, link,
							Convert::GetSizeString(options.Units, GScanEngine->Data.RootFolders[t].Size),
							Convert::DoubleToPercent((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize),
							colour,
							(((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize) * 100)* ((double)__ReportSizes[__rsBarGraphSmall] / (double)large1)
						);

						rowidx++;
					}
				}

				if (options.Layout[0])
				{
					ofile << Formatting::to_utf8(L"</table>\n");

					SingleGraph(ofile, kSize, L"chartDirectory2");
				}

				// ============================================================================
				// == directory list---alphabetical by file size ==============================
				// ============================================================================

				FourColumnTableDoubleTitleHeader(ofile, L"op4", GLanguageHandler->Text[kFoldersRootSize], GLanguageHandler->Text[kFolder] + L" (alphabetical)", GLanguageHandler->Text[kSizeOfFiles], GLanguageHandler->Text[kAsPercent]);

				if (GScanEngine->Data.TotalSize != 0)
				{
					//find largest category %
					large1 = 0;

					for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
					{
						if (std::round(((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize) * 100) > large1)
						{
							large1 = std::round(((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize) * 100);
						}
					}

					if (large1 <= 0) { large1 = __ReportSizes[__rsBarGraphSmall]; }

					rowidx = 1;

// to do					std::ranges::sort(GScanEngine->Data.RootFolders, {}, &RootFolder::Name);

					for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
					{
						if (GScanEngine->Data.RootFolders[t].Count != 0)
						{
							if (GSettingsHandler->Reports.HTMLMonoBargraph)
							{
								colour = GSettingsHandler->Reports.HTMLColours[4];
							}
							else
							{
								colour = __SpectrumColours[t % __SpectrumMod];
							}

							std::wstring link = L"";

							if (t == 0)
							{
								link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Path.String) + L"\" target=\"_blank\">" + Formatting::MakeItalic(GScanEngine->Data.RootFolders[t].Name, GScanEngine->Data.RootFolders[t].Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
							}
							else
							{
								link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Path.String + GScanEngine->Data.RootFolders[t].Name) + L"\" target=\"_blank\">" + Formatting::MakeItalic(GScanEngine->Data.RootFolders[t].Name, GScanEngine->Data.RootFolders[t].Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
							}

							FourColumnTableRow(ofile, rowidx, link,
								Convert::GetSizeString(options.Units, GScanEngine->Data.RootFolders[t].Size),
								Convert::DoubleToPercent((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize),
								colour,
								(((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize) * 100) * ((double)__ReportSizes[__rsBarGraphSmall] / (double)large1)
							);

							rowidx++;
						}
					}
				}
			}
		}

		InsertSpacingTable(ofile);
	}


	void DeepReportFrom(std::ofstream& ofile, std::wstring folder, SizeOfFolder sof, unsigned __int64 largestSize, int largestCount)
	{
		SevenColumnTableDoubleTitleHeader(ofile, L"op9", GLanguageHandler->Text[kFileAttributes] + L" (Created)", GLanguageHandler->Text[kYear]);
	}


	void ReportTop101Largest(std::ofstream &ofile, HTMLReportOptions options)
	{
		// ============================================================================
		// == top 50 largest files ====================================================
		// ============================================================================

		FourColumnTableDoubleTitleHeader(ofile, L"op9", GLanguageHandler->Text[kTop101] + L"(" + GLanguageHandler->Text[kLargest] + L")", GLanguageHandler->Text[kFileTypes],
			GLanguageHandler->Text[kSize],
			GLanguageHandler->Text[kOwner]
		);

		for (int t = 0; t < GScanEngine->Data.Top100Large.size(); t++)
		{
			float tableWidth = 0;

			if (GScanEngine->Data.TotalSize != 0)
			{
				tableWidth = ((double)GScanEngine->Data.Top100Large[t].Size / (double)GScanEngine->Data.TotalSize) * (double)__ReportSizes[__rsBarGraphSmall];
			}

			FourColumnTableRow(ofile, t, 
				GScanEngine->Data.Folders[GScanEngine->Data.Top100Large[t].FilePathIndex] + GScanEngine->Data.Top100Large[t].Name,
				Convert::GetSizeString(options.Units, GScanEngine->Data.Top100Large[t].Size),
				GScanEngine->Data.Users[GScanEngine->Data.Top100Large[t].Owner].Name,
				GSettingsHandler->Reports.HTMLColours[4],
				tableWidth
				);
		}

		ofile << Formatting::to_utf8(L"</table>\n");

		InsertSpacingTable(ofile);
	}


	void ReportTop101Smallest(std::ofstream &ofile, HTMLReportOptions options)
	{
		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">" +
			L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\"><td colspan=\"2\" height=\"13\"><a name=\"op14\"/><b>" + GLanguageHandler->Text[kTop101] + L"(" + GLanguageHandler->Text[kSmallest] + L")</b></td></tr>" +
			L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">" +
			L"<td height=\"13\" width=\"685\"><b>" + GLanguageHandler->Text[kFiles] + L"</b></td>" +
			L"<td height=\"13\" width=\"85\"><b>" + GLanguageHandler->Text[kSize] + L"</b></td>" +
			L"</tr>\n");

		for (int t = 0; t < GScanEngine->Data.Top100Small.size(); t++)
		{
			if (t % 2 != 0)
			{
				ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
			}
			else
			{
				ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[10]) + L"\">\n");
			}
			
			ofile << Formatting::to_utf8(L"<td height=\"13\" width=\"685\">" + GScanEngine->Data.Folders[GScanEngine->Data.Top100Small[t].FilePathIndex] + GScanEngine->Data.Top100Small[t].Name + L"</td>\n");
			ofile << Formatting::to_utf8(L"<td height=\"13\" width=\"85\"><div align=\"" + options.Align + L"\">" + Convert::GetSizeString(options.Units, GScanEngine->Data.Top100Small[t].Size) + L"</div></td>\n");
			ofile << Formatting::to_utf8(L"</tr>\n");
		}

		ofile << Formatting::to_utf8(L"</table>\n");

		InsertSpacingTable(ofile);
	}


	void ReportTop101Newest(std::ofstream &ofile, HTMLReportOptions options)
	{
		FourColumnTableDoubleTitleHeaderNoGraph(ofile, L"op13", GLanguageHandler->Text[kHTMLReport16], GLanguageHandler->Text[kFiles],
			GLanguageHandler->Text[kCreated],
			GLanguageHandler->Text[kSize],
			GLanguageHandler->Text[kOwner]
		);

		for (int t = 0; t < GScanEngine->Data.Top100Newest.size(); t++)
		{
			FourColumnTableDoubleTitleNoGraphRow(ofile, t, GScanEngine->Data.Top100Newest[t].Name,
				Convert::IntDateToString(GScanEngine->Data.Top100Newest[t].DateCreated),
				Convert::GetSizeString(options.Units, GScanEngine->Data.Top100Newest[t].Size),
				GScanEngine->Data.Users[GScanEngine->Data.Top100Newest[t].Owner].Name
			);		
		}

		ofile << Formatting::to_utf8(L"</table>\n");

		InsertSpacingTable(ofile);
	}


	void ReportTop101Oldest(std::ofstream &ofile, HTMLReportOptions options)
	{
		FourColumnTableDoubleTitleHeaderNoGraph(ofile, L"op14", GLanguageHandler->Text[kHTMLReport17], GLanguageHandler->Text[kFiles],
			GLanguageHandler->Text[kCreated],
			GLanguageHandler->Text[kSize],
			GLanguageHandler->Text[kOwner]
		);

		for (int t = 0; t < GScanEngine->Data.Top100Oldest.size(); t++)
		{
			FourColumnTableDoubleTitleNoGraphRow(ofile, t, GScanEngine->Data.Top100Newest[t].Name,
				Convert::IntDateToString(GScanEngine->Data.Top100Oldest[t].DateCreated),
				Convert::GetSizeString(options.Units, GScanEngine->Data.Top100Oldest[t].Size),
				GScanEngine->Data.Users[GScanEngine->Data.Top100Oldest[t].Owner].Name
			);
		}

		ofile << Formatting::to_utf8(L"</table>\n");

		InsertSpacingTable(ofile);
	}	
	

	void ReportFileDates(std::ofstream &ofile, HTMLReportOptions options)
	{
		if (options.Layout[0])
		{
			SingleGraph(ofile, kFileDates, L"chartFileDates1");

			SingleGraph(ofile, kFileDates, L"chartFileDates2");

			InsertSpacingTable(ofile);
		}

		SevenColumnTableDoubleTitleHeader(ofile, L"op9", GLanguageHandler->Text[kFileAttributes] + L" (Created)", GLanguageHandler->Text[kYear]);

		if (GScanEngine->Data.Files.size() != 0)
		{
			//find largest category %
			int large1 = 0;
			int large2 = 0;

			for (int t = 0; t < GScanEngine->Data.FileDates.size(); t++)
			{
				if (std::round(((double)GScanEngine->Data.FileDates[t].Count / (double)GScanEngine->Data.FileCount) * 100) > large1)
				{
					large1 = std::round(((double)GScanEngine->Data.FileDates[t].Count / (double)GScanEngine->Data.FileCount) * 100);
				}

				if (GScanEngine->Data.TotalSize != 0)
				{
					if (std::round(((double)GScanEngine->Data.FileDates[t].Size / (double)GScanEngine->Data.TotalSize) * 100) > large2)
					{
						large2 = std::round(((double)GScanEngine->Data.FileDates[t].Size / (double)GScanEngine->Data.TotalSize) * 100);
					}
				}
			}
	
			if (large1 == 0) large1 = __ReportSizes[__rsBarGraph];
			if (large2 == 0) large2 = __ReportSizes[__rsBarGraph];

			int rowidx = 1;

			for (int t = 0; t < GScanEngine->Data.FileDates.size(); t++)
			{

				if ((GScanEngine->Data.FileCount != 0) && (GScanEngine->Data.FileDates[t].Count != 0))
				{
					std::wstring aspc = L"100%";
					float aspcgraph = (double)__ReportSizes[__rsBarGraph];

					if (GScanEngine->Data.TotalSize != 0)
					{
						aspc = Convert::DoubleToPercent((double)GScanEngine->Data.FileDates[t].Size / (double)GScanEngine->Data.TotalSize);
					}

					if (GScanEngine->Data.TotalSize != 0)
					{
						aspcgraph = (((double)GScanEngine->Data.FileDates[t].Size / (double)GScanEngine->Data.TotalSize) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large2);
					}

					SevenColumnTableRow(ofile, rowidx, std::to_wstring(GScanEngine->Data.FileDates[t].Year),
						std::to_wstring(GScanEngine->Data.FileDates[t].Count),
						Convert::DoubleToPercent((double)GScanEngine->Data.FileDates[t].Count / (double)GScanEngine->Data.FileCount),
						Convert::GetSizeString(options.Units, GScanEngine->Data.FileDates[t].Size),
						aspc,
						GSettingsHandler->Reports.HTMLColours[4],
						(((double)GScanEngine->Data.FileDates[t].Count / (double)GScanEngine->Data.FileCount) * 100) * ((double)__ReportSizes[__rsBarGraph] / (double)large1),
						aspcgraph
						);

					rowidx++;
				}
			}

			InsertSpacingTable(ofile);
		}
		else
		{
			SevenColumnTableRowBlank(ofile, 0, L"<b>No data</b");

			InsertSpacingTable(ofile);
		}
	}

	void ReportNullFiles(std::ofstream &ofile, HTMLReportOptions options)
	{
		int rowidx = 0;

		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\"><td height=\"13\"><a name=\"op7\" /><b>" + GLanguageHandler->Text[kNullFiles] + L"</b></td></tr>\n");

		if (GScanEngine->Data.NullFiles.size() == 0)
		{
			ofile << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\" class=\"C4G\"><td colspan=\"7\" height=\"13\">" + GLanguageHandler->Text[kNoneFound] + L"</td></tr>\n");
		}
		else
		{
			for (int t = 0; t < GScanEngine->Data.NullFiles.size(); t++)
			{
				if (t % 2 == 0)
				{
					ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
				}
				else
				{
					ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[10]) + L"\">\n");
				}

				ofile << Formatting::to_utf8(L"<td height=\"13\">" + GScanEngine->Data.NullFiles[t] + L"</td>\n");

				ofile << Formatting::to_utf8(L"</tr>\n");

				rowidx++;
			}
		}
		
		ofile << Formatting::to_utf8(L"</table>\n");

		InsertSpacingTable(ofile);
	}


	std::wstring BuildMenuList(HTMLReportOptions options)
	{
		std::wstring menu = L"||";

		if (options.Layout[1]) menu += L"<a href=\"#op2\">" + GLanguageHandler->Text[kFileAttributes] + L"</a> || ";
		if (options.Layout[2]) menu += L"<a href=\"#op3\">" + GLanguageHandler->Text[kCombineDrivesFolders] + L"</a> || ";
		if (options.Layout[3]) menu += L"<a href=\"#op4\">" + GLanguageHandler->Text[kFolders] + L"</a> || ";
		if (options.Layout[4]) menu += L"<a href=\"#op5\">" + GLanguageHandler->Text[kMagnitude] + L"</a> || ";
		if (options.Layout[5]) menu += L"<a href=\"#op6\">" + GLanguageHandler->Text[kFileExtensions] + L"</a> || ";
		if (options.Layout[6]) menu += L"<a href=\"#op7\">" + GLanguageHandler->Text[kNullFiles] + L"</a> / <a href=\"#op7a\">" + GLanguageHandler->Text[kEmptyFolders] + L"</a> || ";
		if (options.Layout[7]) menu += L"<a href=\"#op8\">" + GLanguageHandler->Text[kFileDates] + L"</a> || ";
		if (options.Layout[8]) menu += L"<a href=\"#op9\">" + GLanguageHandler->Text[kTop101] + L" (" + GLanguageHandler->Text[kLargest] + L")</a> || ";
		if (options.Layout[9]) menu += L"<a href=\"#op10\">" + GLanguageHandler->Text[kUsers] + L"</a> || ";
		if (options.Layout[10]) menu += L"<a href=\"#op10\">" + GLanguageHandler->Text[kTemp] + L"</a> || ";

		if (options.DeepScan)  menu += L"<a href=\"#op50\">" + GLanguageHandler->Text[kDeepScan] + L"</a> || ";

		return menu;
	}


	void InsertSpacingTable(std::ofstream &ofile)
	{
		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"770\" border=\"0\"><tr><td>&nbsp;</td></tr></table>\n");
	} 


	void DoubleGraph(std::ofstream& ofile, std::wstring id1, std::wstring id2)
	{
		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellspacing=\"1\" cellpadding=\"1\">" +
			L"<tr class=\"C7CB\">" +
			L"<td bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">" + GLanguageHandler->Text[kQuantity] + L"</td>" +
			L"<td bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">" + GLanguageHandler->Text[kSize] + L"</td>" +
			L"</tr>" +
			L"<tr>" +
			L"<td bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\"><div align=\"center\" id=\"" + id1 + L"\"></td>" +
			L"<td bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\"><div align=\"center\" id=\"" + id2 + L"\"></td>" +
			L"</tr>" +
			L"</table>\n");
	}


	void SingleGraph(std::ofstream& ofile, int title_language_id, std::wstring id)
	{
		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellspacing=\"1\" cellpadding=\"1\">" +
			L"<tr class=\"C7CB\">" +
			L"<td bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">" + GLanguageHandler->Text[title_language_id] + L"</td>" +
			L"</tr>" +
			L"<tr><td bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\"><div align=\"center\" id=\"" + id + L"\"></td></tr>" +
			L"</table>\n");
	}


	void BuildGraphScript(std::ofstream &ofile, HTMLReportOptions options)
	{
		ofile << Formatting::to_utf8(L"<script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n");
		ofile << Formatting::to_utf8(L"<script type=\"text/javascript\">\n");
		ofile << Formatting::to_utf8(L"google.charts.load('current', {'packages':['corechart']});\n");
		ofile << Formatting::to_utf8(L"google.charts.setOnLoadCallback(drawChart);\n");

		ofile << Formatting::to_utf8(L"function drawChart() {\n");

		BuildGraphData(ofile, options);

		BuildGraphCode(ofile, options);

		ofile << Formatting::to_utf8(L"}\n");

		ofile << Formatting::to_utf8(L"</script>\n");
	}


	void BuildGraphData(std::ofstream &ofile, HTMLReportOptions options)
	{
		for (int t = 0; t < __HTMLLayoutOptionsCount; t++)
		{
			if (options.Layout[t])
			{
				switch (t)
				{
				case 0:
					BuildGraphDataQuickInfo(ofile);

					break;
				case 2:
					BuildGraphDataCategory(ofile);

					break;
				case 3:
					BuildGraphDataDirectory(ofile);

					break;
				case 4:
					BuildGraphDataMagnitude(ofile);

					break;
				case 7:
					BuildGraphDataFileDates(ofile);

					break;
				}
			}
		}
	}


	void BuildGraphCode(std::ofstream &ofile, HTMLReportOptions options)
	{
		for (int t = 0; t < __HTMLLayoutOptionsCount; t++)
		{
			if (options.Layout[t])
			{
				switch (t)
				{
				case 0:
					ofile << Formatting::to_utf8(L"var optionsQI1 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartDD]) + L", 'height' : 200 };\n");
					ofile << Formatting::to_utf8(L"var optionsQI2 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartDD]) + L", 'height' : 200 };\n");

					ofile << Formatting::to_utf8(L"var chartQI1 = new google.visualization.PieChart(document.getElementById('chartQuickInfo1'));\n");
					ofile << Formatting::to_utf8(L"var chartQI2 = new google.visualization.PieChart(document.getElementById('chartQuickInfo2'));\n");
					ofile << Formatting::to_utf8(L"chartQI1.draw(dataQI1, optionsQI1);\n");
					ofile << Formatting::to_utf8(L"chartQI2.draw(dataQI2, optionsQI2);\n");

					break;
				case 2:
					ofile << Formatting::to_utf8(L"var optionsC1 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartCM]) + L", 'height' : 220 };\n");
					ofile << Formatting::to_utf8(L"var optionsC2 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartCM]) + L", 'height' : 220 };\n");

					ofile << Formatting::to_utf8(L"var chartC1 = new google.visualization.ColumnChart(document.getElementById('chartCategory1'));\n");
					ofile << Formatting::to_utf8(L"var chartC2 = new google.visualization.ColumnChart(document.getElementById('chartCategory2'));\n");

					ofile << Formatting::to_utf8(L"chartC1.draw(dataC1, optionsC1);\n");
					ofile << Formatting::to_utf8(L"chartC2.draw(dataC2, optionsC2);\n");

					break;
				case 3:
					ofile << Formatting::to_utf8(L"var optionsD1 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartCD]) + L", 'height' : 400 };\n");
					ofile << Formatting::to_utf8(L"var optionsD2 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartCD]) + L", 'height' : 400 };\n");

					ofile << Formatting::to_utf8(L"var chartD1 = new google.visualization.ColumnChart(document.getElementById('chartDirectory1'));\n");
					ofile << Formatting::to_utf8(L"var chartD2 = new google.visualization.ColumnChart(document.getElementById('chartDirectory2'));\n");

					ofile << Formatting::to_utf8(L"chartD1.draw(dataD1, optionsD1);\n");
					ofile << Formatting::to_utf8(L"chartD2.draw(dataD2, optionsD2);\n");

					break;
				case 4:

					ofile << Formatting::to_utf8(L"var optionsM1 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartXM]) + L", 'height' : 220 };\n");
					ofile << Formatting::to_utf8(L"var optionsM2 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartXM]) + L", 'height' : 220 };\n");

					ofile << Formatting::to_utf8(L"var chartM1 = new google.visualization.ColumnChart(document.getElementById('chartMagnitude1'));\n");
					ofile << Formatting::to_utf8(L"var chartM2 = new google.visualization.ColumnChart(document.getElementById('chartMagnitude2'));\n");

					ofile << Formatting::to_utf8(L"chartM1.draw(dataM1, optionsM1);\n");
					ofile << Formatting::to_utf8(L"chartM2.draw(dataM2, optionsM2);\n");


					break;
				case 7:

					ofile << Formatting::to_utf8(L"var optionsFD1 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartFD]) + L", 'height' : 400 };\n");
					ofile << Formatting::to_utf8(L"var optionsFD2 = { 'legend' : 'none', 'width' : " + std::to_wstring(__ReportSizes[__rsChartFD]) + L", 'height' : 400 };\n");

					ofile << Formatting::to_utf8(L"var chartFD1 = new google.visualization.ColumnChart(document.getElementById('chartFileDates1'));\n");
					ofile << Formatting::to_utf8(L"var chartFD2 = new google.visualization.ColumnChart(document.getElementById('chartFileDates2'));\n");
					
					ofile << Formatting::to_utf8(L"chartFD1.draw(dataFD1, optionsFD1);\n");
					ofile << Formatting::to_utf8(L"chartFD2.draw(dataFD2, optionsFD2);\n");

					break;
				}
			}
		}
	}


	void BuildGraphDataQuickInfo(std::ofstream &ofile)
	{
		ofile << Formatting::to_utf8(L"var dataQI1 = google.visualization.arrayToDataTable([\n");
		ofile << Formatting::to_utf8(L"['Disk space', '%'], ['Disk Free', " + std::to_wstring(GScanEngine->DiskStats.DriveSpaceFree) + L"], ['Disk Used', " + std::to_wstring(GScanEngine->DiskStats.DriveSpaceUsed) + L"] ]);\n");

		ofile << Formatting::to_utf8(L"var dataQI2 = google.visualization.arrayToDataTable([\n");
		ofile << Formatting::to_utf8(L"['Disk space', '%'], ['Disk', " + std::to_wstring(GScanEngine->DiskStats.DriveSpaceTotal - GScanEngine->Data.TotalSize) + L"], ['Scan', " + std::to_wstring(GScanEngine->Data.TotalSize) + L"] ]);\n");
	}


	void BuildGraphDataCategory(std::ofstream &ofile)
	{
		ofile << Formatting::to_utf8(L"var dataC1 = new google.visualization.arrayToDataTable([ ['Category', 'Quantity', { role: 'style' }],\n");

		for (int t = 1; t < __FileCategoriesCount; t++)
		{
			ofile << Formatting::to_utf8(L"['" + GLanguageHandler->TypeDescriptions[t] + L"', " + std::to_wstring(GScanEngine->Data.ExtensionSpread[t].Count) + L", '#" + Convert::WebColour(GSettingsHandler->FileCategoryColors[t]) + L"'],\n");
		}

		ofile << Formatting::to_utf8(L"]);\n");

		ofile << Formatting::to_utf8(L"var dataC2 = new google.visualization.arrayToDataTable([ ['Category', 'Size', { role: 'style' }],\n");

		for (int t = 1; t < __FileCategoriesCount; t++)
		{
			ofile << Formatting::to_utf8(L"['" + GLanguageHandler->TypeDescriptions[t] + L"', " + std::to_wstring(GScanEngine->Data.ExtensionSpread[t].Size) + L", '#" + Convert::WebColour(GSettingsHandler->FileCategoryColors[t]) + L"'],\n");
		}

		ofile << Formatting::to_utf8(L"]);\n");
	}


	void BuildGraphDataDirectory(std::ofstream &ofile)
	{
		int colour;

		ofile << Formatting::to_utf8(L"var dataD1 = new google.visualization.arrayToDataTable([ ['Folder', 'Quantity', { role: 'style' }],\n");

		for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
		{
			colour = __SpectrumColours[t % __SpectrumMod];

			ofile << Formatting::to_utf8(L"[\"" + GScanEngine->Data.RootFolders[t].Name + L"\", " + std::to_wstring(GScanEngine->Data.RootFolders[t].Count) + L", '#" + Convert::WebColour(colour) + L"'],\n");
		}

		ofile << Formatting::to_utf8(L"]);\n");

		ofile << Formatting::to_utf8(L"var dataD2 = new google.visualization.arrayToDataTable([ ['Folder', 'Size', { role: 'style' }],\n");

		for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
		{
			colour = __SpectrumColours[t % __SpectrumMod];

			ofile << Formatting::to_utf8(L"[\"" + GScanEngine->Data.RootFolders[t].Name + L"\", " + std::to_wstring(GScanEngine->Data.RootFolders[t].Size) + L", '#" + Convert::WebColour(colour) + L"'],\n");
		}

		ofile << Formatting::to_utf8(L"]);\n");
	}


	void BuildGraphDataMagnitude(std::ofstream &ofile)
	{
		ofile << Formatting::to_utf8(L"var dataM1 = new google.visualization.arrayToDataTable([ ['Range', 'Quantity', { role: 'style' }],\n");

		for (int t = 0; t < __MagnitudesCount; t++)
		{
			ofile << Formatting::to_utf8(L"['" + __MagnitudeLabelsShort[t] + L"', " + std::to_wstring(GScanEngine->Data.Magnitude[t].Count) + L", '#" + Convert::WebColour(__MagnitudeColours[t]) + L"'],\n");
		}

		ofile << Formatting::to_utf8(L"]);\n");

		ofile << Formatting::to_utf8(L"var dataM2 = new google.visualization.arrayToDataTable([ ['Range', 'Size', { role: 'style' }],\n");

		for (int t = 0; t < __MagnitudesCount; t++)
		{
			ofile << Formatting::to_utf8(L"['" + __MagnitudeLabelsShort[t] + L"', " + std::to_wstring(GScanEngine->Data.Magnitude[t].Size) + L", '#" + Convert::WebColour(__MagnitudeColours[t]) + L"'],\n");
		}

		ofile << Formatting::to_utf8(L"]);\n");
	}


	void BuildGraphDataFileDates(std::ofstream &ofile)
	{
		int colour;

		ofile << Formatting::to_utf8(L"var dataFD1 = new google.visualization.arrayToDataTable([ ['Year', 'Quantity', { role: 'style' }],\n");

		for (int t = 0; t < GScanEngine->Data.FileDates.size(); t++)
		{
			if (GScanEngine->Data.FileDates[t].Count != 0)
			{
				colour = __SpectrumColours[t % __SpectrumMod];

				ofile << Formatting::to_utf8(L"['" + std::to_wstring(GScanEngine->Data.FileDates[t].Year) + L"', " + std::to_wstring(GScanEngine->Data.FileDates[t].Count) + L", '#" + Convert::WebColour(colour) + L"'],\n");
			}
		}

		ofile << Formatting::to_utf8(L"]);\n");

		ofile << Formatting::to_utf8(L"var dataFD2 = new google.visualization.arrayToDataTable([ ['Year', 'Size', { role: 'style' }],\n");

		for (int t = 0; t < GScanEngine->Data.FileDates.size(); t++)
		{
			if (GScanEngine->Data.FileDates[t].Count != 0)
			{
				colour = __SpectrumColours[t % __SpectrumMod];

				ofile << Formatting::to_utf8(L"['" + std::to_wstring(GScanEngine->Data.FileDates[t].Year) + L"', " + std::to_wstring(GScanEngine->Data.FileDates[t].Size) + L", '#" + Convert::WebColour(colour) + L"'],\n");
			}
		}

		ofile << Formatting::to_utf8(L"]);\n");
	}


	void FourColumnTableDoubleTitleHeader(std::ofstream& ofile, std::wstring anchor, std::wstring title_top, std::wstring title_bottom, std::wstring col1, std::wstring col2)
	{
		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">" +
			L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\"><td colspan=\"4\" height=\"13\"><a name=\"" + anchor + L"\" /><b>" + title_top + L"</b></td></tr>" +
			L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">" +
			L"<td height=\"13\" width=\"910\"><b>" + title_bottom + L"</b></td>" +
			L"<td height=\"13\" width=\"160\" class=\"XCB\">&nbsp;</td>" +
			L"<td height=\"13\" width=\"90\" class=\"XCB\">" + col1 + L"</td>" +
			L"<td height=\"13\" width=\"90\" class=\"XCB\">" + col2 + L"</td>" +
			L"</tr>\n");
	}


	void FourColumnTableRow(std::ofstream& ofile, int row, std::wstring col1, std::wstring col3, std::wstring col4, int graph_colour, float graph)
	{
		if (row % 2 != 0)
		{
			ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
		}
		else
		{
			ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[10]) + L"\">\n");
		}

		ofile << Formatting::to_utf8(L"<td height=\"13\">" + col1 + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\">\n");
		ofile << Formatting::to_utf8(L"<table width=\"" + std::to_wstring(graph) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(graph_colour) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
		ofile << Formatting::to_utf8(L"<tr><td></td></tr>\n");
		ofile << Formatting::to_utf8(L"</table>\n");
		ofile << Formatting::to_utf8(L"</td>\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\" align=\"right\">" + col3 + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\" align=\"right\">" + col4 + L"</td>\n");
		ofile << Formatting::to_utf8(L"</tr>\n");
	}


	void FourColumnTableDoubleTitleHeaderNoGraph(std::ofstream& ofile, std::wstring anchor, std::wstring title_top, std::wstring title_bottom, std::wstring col1, std::wstring col2, std::wstring col3)
	{
		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">\n");
		ofile << Formatting::to_utf8(L"<td colspan=\"4\" height=\"13\"><a name=\"" + anchor + L"\" /><b>" + title_top + L"</b></td>\n");
		ofile << Formatting::to_utf8(L"</tr>\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\" width=\"980\"><b>" + title_bottom + L"</b></td>\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\" width=\"90\" align=\"center\"><b>" + col1 + L"</b></td>\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\" width=\"90\" align=\"center\"><b>" + col2 + L"</b></td>\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\" width=\"90\" align=\"center\"><b>" + col3 + L"</b></td>\n");
	}


	void FourColumnTableDoubleTitleNoGraphRow(std::ofstream& ofile, int row, std::wstring col1, std::wstring col2, std::wstring col3, std::wstring col4)
	{
		if (row % 2 != 0)
		{
			ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
		}
		else
		{
			ofile << Formatting::to_utf8(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[10]) + L"\">\n");
		}

		ofile << Formatting::to_utf8(L"<td height=\"13\">" + col1 + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\" align=\"right\">" + col2 + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\" align=\"right\">" + col3 + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td height=\"13\" align=\"left\">" + col4 + L"</td>\n");
		ofile << Formatting::to_utf8(L"</tr>\n");
	}


	void SevenColumnTableHeader(std::ofstream& ofile, std::wstring anchor, std::wstring title)
	{
		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		ofile << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">" +
			L"<td width=\"150\" height=\"13\" class=\"C7G\"> <a name=\"" + anchor + L"\" /><b>" + title + L"</b></td>" +
			L"<td width=\"90\" height=\"13\" class=\"C7CB\">" + GLanguageHandler->Text[kQuantity] + L"</td>" +
			L"<td width=\"80\" height=\"13\" class=\"C7CB\">" + GLanguageHandler->Text[kAsPercent] + L"</td>" +
			L"<td width=\"380\" height=\"13\"> &nbsp; </td>" +
			L"<td width=\"90\" height=\"13\" class=\"C7CB\">" + GLanguageHandler->Text[kSizeOfFiles] + L"</td>" +
			L"<td width=\"80\" height=\"13\" class=\"C7CB\">" + GLanguageHandler->Text[kAsPercent] + L"</td>" +
			L"<td width=\"380\" height=\"20\">&nbsp;</td>" +
			L"</tr>\n");
	}


	void SevenColumnTableRow(std::ofstream& ofile, int row, std::wstring caption, std::wstring col1, std::wstring col2, std::wstring col3, std::wstring col4, int graph_colour, float graph_left, float graph_right)
	{
		if (row % 2 != 0)
		{
			ofile << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
		}
		else
		{
			ofile << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[10]) + L"\">\n");
		}

		ofile << Formatting::to_utf8(L"<td class=\"C4L\">" + caption + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td class=\"C4G\" align=\"right\">" + col1 + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td class=\"C4G\" align=\"right\">" + col2 + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td><table width=\"" + std::to_wstring((int)graph_left) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(graph_colour) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">" +
			L"<tr><td></td></tr></table></td>\n");
		ofile << Formatting::to_utf8(L"<td class=\"C4G\" align=\"right\">" + col3 + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td class=\"C4G\" align=\"right\">" + col4 + L"</td>" +
			L"<td>" +
			L"<table width=\"" + std::to_wstring((int)graph_right) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(graph_colour) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">" +
			L"<tr><td></td></tr>" +
			L"</table>" +
			L"</td>\n");
		ofile << Formatting::to_utf8(L"</tr>\n");
	}


	void SevenColumnTableRowBlank(std::ofstream& ofile, int row, std::wstring caption)
	{
		if (row % 2 != 0)
		{
			ofile << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[9]) + L"\">\n");
		}
		else
		{
			ofile << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[10]) + L"\">\n");
		}

		ofile << Formatting::to_utf8(L"<td class=\"C4L\">" + caption + L"</td>\n");
		ofile << Formatting::to_utf8(L"<td class=\"C4C\" align=\"right\">&nbsp;</td>\n");
		ofile << Formatting::to_utf8(L"<td class=\"C4C\" align=\"right\">&nbsp;</td>\n");
		ofile << Formatting::to_utf8(L"<td>&nbsp;</td>\n");
		ofile << Formatting::to_utf8(L"<td class=\"C4G\" align=\"right\">&nbsp;</td>\n");
		ofile << Formatting::to_utf8(L"<td class=\"C4C\" align=\"right\">&nbsp;</td>\n");
		ofile << Formatting::to_utf8(L"<td>&nbsp;</td></tr>\n");
	}


	void SevenColumnTableEnd(std::ofstream& ofile)
	{
		ofile << Formatting::to_utf8(L"</table>\n");
	}


	void SevenColumnTableDoubleTitleHeader(std::ofstream& ofile, std::wstring anchor, std::wstring title_top, std::wstring title_bottom)
	{
		ofile << Formatting::to_utf8(L"<table align=\"center\" width=\"" + std::to_wstring(__ReportSizes[__rsTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		ofile << Formatting::to_utf8(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">\n");
		ofile << Formatting::to_utf8(L"<td colspan=\"7\" width=\"387\" height=\"20\"><a name=\"" + anchor + L"\"</a><b>" + title_top + L"</b></td>\n");
		ofile << Formatting::to_utf8(L"</tr>\n");
		ofile << Formatting::to_utf8(L"<tr bgcolor=\"#" + Convert::WebColour(GSettingsHandler->Reports.HTMLColours[5]) + L"\">\n");
		ofile << Formatting::to_utf8(L"<td width=\"150\" height=\"13\" class=\"C7G\"><a name=\"op3\" /><b>" + GLanguageHandler->Text[kYear] + L"</b></td>\n");
		ofile << Formatting::to_utf8(L"<td width=\"90\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kQuantity] + L"</b></div></td>\n");
		ofile << Formatting::to_utf8(L"<td width=\"80\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>\n");
		ofile << Formatting::to_utf8(L"<td width=\"380\" height=\"13\">&nbsp;</td>\n");
		ofile << Formatting::to_utf8(L"<td width=\"90\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kSizeOfFiles] + L"</b></div></td>\n");
		ofile << Formatting::to_utf8(L"<td width=\"80\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>\n");
		ofile << Formatting::to_utf8(L"<td width=\"380\" height=\"20\">&nbsp;</td>\n");
		ofile << Formatting::to_utf8(L"</tr>\n");
	}
};