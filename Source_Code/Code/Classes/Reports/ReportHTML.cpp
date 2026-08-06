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
	bool sortBySize(const UserData* lhs, const UserData* rhs) { return lhs->Size < rhs->Size; }


	void Generate(HTMLReportOptions &options, std::vector<std::wstring> *data, int DataSource)
	{
		if (options.DeepScan)
		{
			//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (HTML Deep): " + Formatting::TrimFileNameForOutput(options.FileName) << "\n";
		}
		else
		{
			//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (HTML): " + Formatting::TrimFileNameForOutput(options.FileName) << "\n";
		}

		// ============================================================================
		// == before we create the page, we need to create the graphs..... ============
		// ============================================================================

		std::wstring menu = BuildMenuList(options);

		// ============================================================================
		// == Lets write the file =====================================================
		// ============================================================================

		data->push_back(L"<html><head><title>FolderScanUltra analysis \"" + GScanEngine->Data[DataSource].Path.String + L"\"</title>\n");
		data->push_back(L"<meta name=\"generator\" content=\"FolderScanUltra, (c) Paul Alan Freshney 2002-" + Utility::CurrentYear() + L", paul@freshney.org\">\n");
		data->push_back(L"<meta name=\"debug\" content=\"" + std::to_wstring(options.LayoutSize) + L"\">\n");
		data->push_back(L"<style type=\"text/css\">\n");
		data->push_back(L"<!--\n");
		data->push_back(L"A:link {color:#" + Convert::WebColour(options.HTMLColours[0]) + L"; text-decoration: none;}\n");
		data->push_back(L"A:visited {color:#" + Convert::WebColour(options.HTMLColours[0]) + L"; text-decoration: none;}\n");
		data->push_back(L"A:hover {color:#" + Convert::WebColour(options.HTMLColours[1]) + L"; text-decoration: underline;}\n");
		data->push_back(L"A:active {color:#" + Convert::WebColour(options.HTMLColours[0]) + L"; text-decoration: none;}\n");
		data->push_back(L".C4G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#" + Convert::WebColour(options.HTMLColours[3]) + L";}\n");
		data->push_back(L".C4CB {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; font-weight: bold; color:#" + Convert::WebColour(options.HTMLColours[3]) + L";}\n");
		data->push_back(L".C4C {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; color:#" + Convert::WebColour(options.HTMLColours[3]) + L";}\n");
		data->push_back(L".C4L {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:left; color:#" + Convert::WebColour(options.HTMLColours[3]) + L";}\n");
		data->push_back(L".C4R {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:right; color:#" + Convert::WebColour(options.HTMLColours[3]) + L";}\n");
		data->push_back(L".C7G {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; color:#" + Convert::WebColour(options.HTMLColours[6]) + L";}\n");
		data->push_back(L".C7CB {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; font-weight: bold; color:#" + Convert::WebColour(options.HTMLColours[6]) + L";}\n");
		data->push_back(L".C7C {font-family: Geneva, Arial, Helvetica, san-serif; font-size:10pt; text-align:center; color:#" + Convert::WebColour(options.HTMLColours[6]) + L";}\n");
		data->push_back(L".XCB {text-align:center; font-weight: bold;}\n");
		data->push_back(L"-->\n");
		data->push_back(L"</style></head>\n");
		data->push_back(L"<body leftmargin=\"5\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[2]) + L"\" text=\"#" + Convert::WebColour(options.HTMLColours[7]) + L"\" topmargin=\"5\">\n");
		// ===========================================================================

		if (options.Layout[0])
		{
			BuildGraphScript(data, options, DataSource);
		}

		// ===========================================================================

		for (int t = 0; t < kHTMLLayoutOptionsCount; t++)
		{
			if (options.Layout[t])
			{
				switch (t)
				{
				case 0:
					ReportHeader(data, options, DataSource, menu);
					ReportQuickInfo(data, options, DataSource);

					if (GScanEngine->Data[DataSource].Path.ExcludeFolders)
					{
						ReportExclude(data, options, DataSource);
					}

					break;
				case 1:
					ReportFileAttributesTable(data, options, DataSource);
					break;
				case 2:
					ReportFileCategory(data, options, DataSource);
					break;
				case 3:
					ReportDirectoryList(1, data, options, DataSource);
					break;
				case 4:
					ReportMagnitude(data, options, DataSource);
					break;
				case 5:
					ReportFileExtensionLists(data, options, DataSource);
					break;
				case 6:
					ReportNullFiles(data, options, DataSource);
					break;
				case 7:
					ReportFileDates(data, options, DataSource);
					break;
				case 8:
					ReportTop101Largest(data, options, DataSource);
					ReportTop101Smallest(data, options, DataSource);

					ReportTop101Newest(data, options, DataSource);
					ReportTop101Oldest(data, options, DataSource);
					break;
				case 9:
					ReportUsers(data, options, DataSource);
					break;
				case 10:
					ReportTemporary(data, options, DataSource);
					break;
				}
			}
		}

		if (options.DeepScan)
		{
			CreateDeepReport(data, options, DataSource);
		}

		// ===========================================================================
		// footer table. always gets added

		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">\n");
		data->push_back(L"<td align=\"center\" class=\"C7G\">\n");
		data->push_back(L"<a href=\"mailto:paul@freshney.org\">paul@freshney.org</a> / <a href=\"https://github.com/MaximumOctopus/FolderScanUltra\" target=\"_blank\">https://github.com/MaximumOctopus/FolderScanUltra</a></td>\n");
		data->push_back(L"</tr>\n");
		data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\" class=\"C7G\"><td align=\"center\">(c) Paul Alan Freshney 2002-" + Utility::CurrentYear() + L"</td></tr>");
		data->push_back(L"</table></body></html>\n");
	}


	void CreateDeepReport(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		ReportDeep deep;

		int anchor = 50;

		for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
		{
			std::wstring folder = GScanEngine->Data[DataSource].Path.String;

			if (rootfolder->Name != L"root")
			{
				folder += rootfolder->Name + L"\\";
			}

			int folderIndex = GScanEngine->Data[DataSource].GetFolderIndex(folder);

			if (folderIndex != -1)
			{
				if (!deep.ProcessFolder(folderIndex, DataSource))
				{
					// if there are no sub-folders then use the root folder's data
					deep.Add(L"\"", rootfolder->Size, rootfolder->Count);
				}

				if (deep.FolderData.size() != 0)
				{
					SevenColumnTableDoubleTitleHeader(data, L"op" + std::to_wstring(anchor), folder, GLanguageHandler->Text[kFolder], options);

					int largeSize = 0;
					int largeCount = 0;

					largeCount = std::round(((double)deep.largestCount / (double)GScanEngine->Data[DataSource].FileCount) * 100);
					largeSize = std::round(((double)deep.largestSize / (double)GScanEngine->Data[DataSource].TotalSize) * 100);

					if (largeCount <= 0) largeCount = kReportSizes[kBarGraph];
					if (largeSize <= 0) largeSize = kReportSizes[kBarGraph];

					for (int s = 0; s < deep.FolderData.size(); s++)
					{
						SevenColumnTableRow(data, s, deep.FolderData[s].Folder,
							std::to_wstring(deep.FolderData[s].FileCount),
							Convert::DoubleToPercent((double)deep.FolderData[s].FileCount / (double)GScanEngine->Data[DataSource].FileCount),
							Convert::GetSizeString(options.Units, deep.FolderData[s].Size),
							Convert::DoubleToPercent((double)deep.FolderData[s].Size / (double)GScanEngine->Data[DataSource].TotalSize),
							options.HTMLColours[4],
							(((double)deep.FolderData[s].FileCount / (double)GScanEngine->Data[DataSource].FileCount) * 100) * ((double)kReportSizes[kBarGraph] / (double)largeCount),
							(((double)deep.FolderData[s].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) * ((double)kReportSizes[kBarGraph] / (double)largeSize),
							options
						);
					}

					data->push_back(L"</table>\n");

					anchor++;

					InsertSpacingTable(data);
				}
			}
			else
			{
				//GLog->Add( " Error cannot find folder \"" << folder << "\"\n";
			}
		}
	}


	void ReportHeader(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource, std::wstring menu_string)
	{
		// ============================================================================
		// == header table ============================================================
		// ============================================================================

		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
		data->push_back(L"<tr class=\"C4G\">\n");

		data->push_back(L"<td class=\"C4C\"><b>FolderScanUltra " + __XVersion + L"</b> " + GLanguageHandler->Text[kReportFor] +
			L" <b><a href=\"" + Utility::WebFileLink(GScanEngine->Data[DataSource].Path.String) + L"\">" + GScanEngine->Data[DataSource].Path.String + L"</a></b></td>\n");

		data->push_back(L"</tr>\n");
		data->push_back(L"<tr class=\"C4C\">\n");
		data->push_back(L"<td>" + GLanguageHandler->Text[kAnalysedAt] + L" <b>" + Utility::GetTime(DateTimeFormat::Display) + L"</b>, <b>" + Utility::GetDate(DateTimeFormat::Display) + L"</b>.</td>\n");
		data->push_back(L"</tr>\n");

		if (GScanEngine->Data[DataSource].Source == ScanSource::FileCSV)
		{
			data->push_back(L"<tr class=\"C4C\">\n");
			data->push_back(L"<td>CSV Source: <b>" + GScanEngine->Data[DataSource].Path.FileName + L"</b>.</td>\n");
			data->push_back(L"</tr>\n");
		}

		if (GScanEngine->FilterCategory != -1)
		{
			data->push_back(L"<tr class=\"C4C\">\n");
			data->push_back(L"<td>Filtered by category <b>" + kFileExtensionFileName[GScanEngine->FilterCategory] + L"</b>.</td>\n");
			data->push_back(L"</tr>\n");
		}

		data->push_back(L"</table>\n");

		InsertSpacingTable(data);

		// ============================================================================
		// == navigation table ========================================================
		// ============================================================================

		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">" +
			L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\"><td class=\"C7G\"><strong>Menu</strong></td></tr>" +
			L"<tr class=\"C4C\"><td>" + menu_string + L"</td></tr></table>\n");

		InsertSpacingTable(data);
	}


	void ReportFileCategory(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		// ============================================================================
		// == file category table =====================================================
		// ============================================================================

		SevenColumnTableHeader(data, L"op2", GLanguageHandler->Text[kCategory], options);

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			int rowidx = 1;
			int large1 = 0;
			int large2 = 0;

			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				//find largest category %

				for (int t = 0; t < kFileCategoriesCount; t++)
				{
					if (std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) > large2) { large2 = std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100); }
					if (std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) > large1) { large1 = std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100); }
				}

				if (large1 <= 0) large1 = kReportSizes[kBarGraph];
				if (large2 <= 0) large2 = kReportSizes[kBarGraph];

				//build the file category table
				for (int t = 1; t < kFileCategoriesCount; t++)
				{
					if (GScanEngine->Data[DataSource].ExtensionSpread[t].Count != 0)
					{
						SevenColumnTableRow(data, rowidx, GLanguageHandler->TypeDescriptions[t],
							std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count),
							Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount),
							Convert::GetSizeString(options.Units, GScanEngine->Data[DataSource].ExtensionSpread[t].Size),
							Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize),
							GSettingsHandler->FileCategoryColors[t],
							(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) * ((double)kReportSizes[kBarGraph] / (double)large1),
							(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) * ((double)kReportSizes[kBarGraph] / (double)large2),
							options
						);

						rowidx++;
					}
				}
			}

			SevenColumnTableRowBlank(data, rowidx, L"", options);

			rowidx++;

			// ==================================================================

			SevenColumnTableRow(data, rowidx, GLanguageHandler->Text[kTemporary],
				std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[0].Count),
				Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[0].Count / (double)GScanEngine->Data[DataSource].FileCount),
				Convert::GetSizeString(options.Units, GScanEngine->Data[DataSource].ExtensionSpread[0].Size),
				Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[0].Size / (double)GScanEngine->Data[DataSource].TotalSize),
				0x000000,
				(((double)GScanEngine->Data[DataSource].ExtensionSpread[0].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) * ((double)kReportSizes[kBarGraph] / (double)large1),
				(((double)GScanEngine->Data[DataSource].ExtensionSpread[0].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) * ((double)kReportSizes[kBarGraph] / (double)large2),
				options
			);

			data->push_back(L"</table>\n");

			InsertSpacingTable(data);

			//build the graph table
			if (options.Layout[0])
			{
				DoubleGraph(data, L"chartCategory1", L"chartCategory2", options);

				InsertSpacingTable(data);
			}
		}
	}


	void ReportFileAttributesTable(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		// ============================================================================
		// == file attributes table ===================================================
		// ============================================================================

		SevenColumnTableHeader(data, L"op2", GLanguageHandler->Text[kFileAttributes], options);

		if (GScanEngine->Data[DataSource].FileCount > 0)
		{
			if (GScanEngine->Data[DataSource].TotalSize > 0)
			{
				//find largest category %

				int large1 = 0;
				int large2 = 0;

				for (int t = 0; t < kAttributesToDisplayCount; t++)
				{
					if (std::round(((double)GScanEngine->Data[DataSource].FileAttributes[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) > large1) { large1 = std::round(((double)GScanEngine->Data[DataSource].FileAttributes[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100); };
					if (std::round(((double)GScanEngine->Data[DataSource].FileAttributes[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) > large2) { large2 = std::round(((double)GScanEngine->Data[DataSource].FileAttributes[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100); };
				}

				if (large1 <= 0) large1 = kReportSizes[kBarGraph];
				if (large2 <= 0) large2 = kReportSizes[kBarGraph];

				//build the file category table
				for (int t = 0; t < kAttributesToDisplayCount; t++)
				{
					SevenColumnTableRow(data, t, GLanguageHandler->LanguageTypes[t],
						std::to_wstring(GScanEngine->Data[DataSource].FileAttributes[t].Count),
						Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].FileAttributes[t].Count / (double)GScanEngine->Data[DataSource].FileCount),
						Convert::GetSizeString(options.Units, GScanEngine->Data[DataSource].FileAttributes[t].Size),
						Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].FileAttributes[t].Size / (double)GScanEngine->Data[DataSource].TotalSize),
						options.HTMLColours[4],
						(((double)GScanEngine->Data[DataSource].FileAttributes[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) * ((double)kReportSizes[kBarGraph] / (double)large1),
						(((double)GScanEngine->Data[DataSource].FileAttributes[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) * ((double)kReportSizes[kBarGraph] / (double)large2),
						options
					);
				}
			}
		}

		data->push_back(L"</table>\n");

		InsertSpacingTable(data);
	}


	void ReportUsers(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		// ============================================================================
		// == Username ================================================================
		// ============================================================================

		SevenColumnTableDoubleTitleHeader(data, L"op10", GLanguageHandler->Text[kUsageByUser], GLanguageHandler->Text[kOwner], options);

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				int large1 = 0;
				int large2 = 0;
				int rowidx = 1;

				for (UserData *user : GScanEngine->Data[DataSource].Users)
				{
					if (std::round(((double)user->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) > large1) { large1 = std::round(((double)user->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100); }
					if (std::round(((double)user->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) > large2) { large2 = std::round(((double)user->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100); }
				}

				if (large1 <= 0) large1 = kReportSizes[kBarGraph];
				if (large2 <= 0) large2 = kReportSizes[kBarGraph];

				// ============================================================

				std::sort(GScanEngine->Data[DataSource].Users.begin(), GScanEngine->Data[DataSource].Users.end(), sortBySize);

				// ============================================================

				for (UserData *user : GScanEngine->Data[DataSource].Users)
				{
					SevenColumnTableRow(data, rowidx, user->Name,
						std::to_wstring(user->Count),
						Convert::DoubleToPercent((double)user->Count / (double)GScanEngine->Data[DataSource].FileCount),
						Convert::GetSizeString(options.Units, user->Size),
						Convert::DoubleToPercent((double)user->Size / (double)GScanEngine->Data[DataSource].TotalSize),
						options.HTMLColours[4],
						(((double)user->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) * ((double)kReportSizes[kBarGraph] / (double)large1),
						((double)(user->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) * ((double)kReportSizes[kBarGraph] / (double)large2),
						options
					);

					rowidx++;
				}

				InsertSpacingTable(data);
			}
		}
	}


	void ReportTemporary(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		int rowidx = 0;

		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		data->push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\"><td height=\"13\"><a name=\"op7\" /><b>" + GLanguageHandler->Text[kTempFiles] + L"</b></td></tr>\n");

		if (GScanEngine->Data[DataSource].TemporaryFiles.size() == 0)
		{
			data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\" class=\"C4G\"><td colspan=\"7\" height=\"13\">" + GLanguageHandler->Text[kNoneFound] + L"</td></tr>\n");
		}
		else
		{
			for (int t = 0; t < GScanEngine->Data[DataSource].TemporaryFiles.size(); t++)
			{
				if (t % 2 == 0)
				{
					data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
				}
				else
				{
					data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[10]) + L"\">\n");
				}

				data->push_back(L"<td height=\"13\">" + GScanEngine->Data[DataSource].TemporaryFiles[t] + L"</td>\n");

				data->push_back(L"</tr>\n");

				rowidx++;
			}
		}

		data->push_back(L"</table>\n");

		InsertSpacingTable(data);
	}


	void ReportFileExtensionLists(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		// ============================================================================
		// == File Extesnion Lists ====================================================
		// ============================================================================

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				int large1 = 0;
				int large2 = 0;
				int linecount = 0;
				int rowidx;
				int percentage = 0;

				for (int i = 0; i < GFileExtensionHandler->Extensions.size(); i++)
				{
					if (std::round(((double)GFileExtensionHandler->Extensions[i]->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) > large1) { large1 = std::round(((double)GFileExtensionHandler->Extensions[i]->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100); }
					if (std::round(((double)GFileExtensionHandler->Extensions[i]->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) > large2) { large2 = std::round(((double)GFileExtensionHandler->Extensions[i]->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100); }
				}

				if (large1 <= 0) large1 = kReportSizes[kBarGraph];
				if (large2 <= 0) large2 = kReportSizes[kBarGraph];

				for (int t = 1; t < kFileCategoriesCount; t++)
				{
					if ((options.CategoryList[t]) && (GScanEngine->Data[DataSource].ExtensionSpread[t].Count != 0))
					{
						SevenColumnTableDoubleTitleHeader(data, L"op6",
							GLanguageHandler->TypeDescriptions[t] + L" [ " + std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count) + L" files (" + Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount) + L") / " + Convert::GetSizeString(options.Units, GScanEngine->Data[DataSource].ExtensionSpread[t].Size) + L" (" + Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) + L") ]",
							GLanguageHandler->Text[kExtension],
							options
						);

						linecount = 0;

						if (t != kFileCategoriesOther)
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
										SevenColumnTableRow(data, rowidx, tfx->Name,
											std::to_wstring(tfx->Count),
											Convert::DoubleToPercent((double)tfx->Count / (double)GScanEngine->Data[DataSource].FileCount),
											Convert::GetSizeString(options.Units, tfx->Size),
											Convert::DoubleToPercent((double)tfx->Size / (double)GScanEngine->Data[DataSource].TotalSize),
											options.HTMLColours[4],
											(((double)tfx->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100)* ((double)kReportSizes[kBarGraph] / (double)large1),
											(((double)tfx->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100)* ((double)kReportSizes[kBarGraph] / (double)large2),
											options
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
								if (GFileExtensionHandler->Extensions[z]->Category == kCategory_Other)
								{
									if (std::round((((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data[DataSource].FileCount)) * 100) > large1) { large1 = std::round((((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data[DataSource].FileCount)) * 100); }
									if (std::round(((double)GFileExtensionHandler->Extensions[z]->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) > large2) { large2 = std::round(((double)GFileExtensionHandler->Extensions[z]->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100); }
								}
							}

							if (large1 <= 0) large1 = kReportSizes[kBarGraph];
							if (large2 <= 0) large2 = kReportSizes[kBarGraph];

							rowidx = 1;

							for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
							{
								if (GFileExtensionHandler->Extensions[z]->Category == kCategory_Other)
								{
									//only include within report if number of files in extension > 0
									if (GFileExtensionHandler->Extensions[z]->Count != 0)
									{
										// ==================================================================
										if (rowidx % 2 != 0)
										{
											data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
										}
										else
										{
											data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[10]) + L"\">\n");
										}

										rowidx++;
										// ==================================================================


										if (GFileExtensionHandler->Extensions[z]->Name.empty())
										{
											data->push_back(L"<td width=\"100\" height=\"13\"><i>none</i></td>\n");
										}
										else
										{
											data->push_back(L"<td width=\"100\" height=\"13\">" + GFileExtensionHandler->Extensions[z]->Name + L"</td>\n");
										}

										data->push_back(L"<td width=\"64\" height=\"13\"><div align=\"center\">" + std::to_wstring(GFileExtensionHandler->Extensions[z]->Count) + L"</div></td>\n");
										data->push_back(L"<td width=\"64\" height=\"13\"><div align=\"center\">" + Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data[DataSource].FileCount) + L"</div></td>\n");
										data->push_back(L"<td width=\"160\">\n");

										if (large1 != 0)
										{
											data->push_back(L"<table width=\"" + std::to_wstring(std::round((((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) * ((double)kReportSizes[kBarGraph] / (double)large1))) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[4]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
										}
										else
										{
											data->push_back(L"<table width=\"1\" border=\"0\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[4]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
										}

										data->push_back(L"<tr><td></td></tr></table></td>\n");
										data->push_back(L"<td width=\"85\" height=\"13\"><div align=\"" + options.Align + L"\">" + Convert::GetSizeString(options.Units, GFileExtensionHandler->Extensions[z]->Size) + L"</div></td>\n");

										percentage = std::round((((double)GFileExtensionHandler->Extensions[z]->Size) / (double)GScanEngine->Data[DataSource].TotalSize) * 100);

										data->push_back(L"<td width=\"67\" height=\"13\"><div align=\"center\">" + Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z]->Size / (double)GScanEngine->Data[DataSource].TotalSize) + L"</div></td>\n");
										data->push_back(L"<td width=\"160\">\n");

										if (large2 != 0)
										{
											data->push_back(L"<table width=\"" + std::to_wstring(std::round((double)percentage * ((double)kReportSizes[kBarGraph] / (double)large2))) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[4]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
										}
										else
										{
											data->push_back(L"<table width=\"1\" border=\"0\" bgcolor = \"#" + Convert::WebColour(options.HTMLColours[4]) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
										}

										data->push_back(L"<tr><td></td></tr>\n");
										data->push_back(L"</table>\n");
										data->push_back(L"</td>\n");
										data->push_back(L"</tr>\n");

										linecount++;
									}
								}
							}
						}

						if (linecount == 0)
						{
							data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\"><td colspan=\"7\" height=\"13\" class=\"C4G\">" + GLanguageHandler->Text[kNoneFound] + L".</td></tr>\n");
						}

						data->push_back(L"</table>\n");

						InsertSpacingTable(data);
					}
				}
			}
		}
	}


	void ReportMagnitude(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		// ============================================================================
		// == magnitude table =========================================================
		// ============================================================================

		SevenColumnTableHeader(data, L"op5", GLanguageHandler->Text[kMagnitude], options);

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			//find largest category %
			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				int large1 = 0;
				int large2 = 0;

				for (int t = 0; t < kMagnitudesCount; t++)
				{
					if (std::round(((double)GScanEngine->Data[DataSource].Magnitude[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) > large1) { large1 = std::round(((double)GScanEngine->Data[DataSource].Magnitude[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100); }
					if (std::round(((double)GScanEngine->Data[DataSource].Magnitude[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) > large2) { large2 = std::round(((double)GScanEngine->Data[DataSource].Magnitude[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100); }
				}

				if (large1 <= 0) large1 = kReportSizes[kBarGraph];
				if (large2 <= 0) large2 = kReportSizes[kBarGraph];

				//build the file category table
				for (int t = 0; t < kMagnitudesCount; t++)
				{
					SevenColumnTableRow(data, t, kMagnitudeLabels[t],
						std::to_wstring(GScanEngine->Data[DataSource].Magnitude[t].Count),
						Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].Magnitude[t].Count / (double)GScanEngine->Data[DataSource].FileCount),
						Convert::GetSizeString(options.Units, GScanEngine->Data[DataSource].Magnitude[t].Size),
						Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].Magnitude[t].Size / (double)GScanEngine->Data[DataSource].TotalSize),
						kMagnitudeColours[t],
						(((double)GScanEngine->Data[DataSource].Magnitude[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) * ((double)kReportSizes[kBarGraph] / (double)large1),
						(((double)GScanEngine->Data[DataSource].Magnitude[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) * ((double)kReportSizes[kBarGraph] / (double)large2),
						options
					);
				}

				data->push_back(L"</table>\n");

				InsertSpacingTable(data);

				if (options.Layout[0])
				{
					DoubleGraph(data, L"chartMagnitude1", L"chartMagnitude2", options);

					InsertSpacingTable(data);
				}
			}
		}
	}


	void ReportQuickInfo(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		// ============================================================================
		// == quick info table ========================================================
		// ============================================================================

		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" height=\"180\" border=\"0\" cellspacing=\"1\" cellpadding=\"1\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
		data->push_back(L"<tr><td width=\"100%\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\" class=\"C7G\"><strong>" + GLanguageHandler->Text[kSummary] + L"</strong></td></tr>\n");
		data->push_back(L"<tr>\n");
		data->push_back(L"<td>\n");
		data->push_back(L"<table width=\"100%\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		data->push_back(L"<tr>\n");
		data->push_back(L"<td width=\"350\" rowspan=\"11\"><div align=\"center\" id=\"chartQuickInfo1\"></div></td>\n");
		data->push_back(L"<td width=\"350\" rowspan=\"11\"><div align=\"center\" id=\"chartQuickInfo2\"></div></td>\n");
		data->push_back(L"<td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kNumberOfFiles] + L" </td>\n");
		data->push_back(L"<td width=\"92\" class=\"C4L\"> <b>" + std::to_wstring(GScanEngine->Data[DataSource].FileCount) + L"</b></td>\n");
		data->push_back(L"</tr>\n");

		data->push_back(L"<tr><td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kNumberOfFolders] +
				L" </td><td width=\"92\" class=\"C4L\"> <b>" + std::to_wstring(GScanEngine->Data[DataSource].FolderCount) +	L"</b></td></tr>\n");
		data->push_back(L"<tr><td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kTotalSizeofFilesAnalysed] + L" </td><td width=\"92\" class=\"C4L\"> <b>" + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSize) + L"</b></td></tr>\n");
		data->push_back(L"<tr><td width=\"170\" class=\"C4G\">&nbsp;</td><td width=\"92\" class=\"C4G\">&nbsp;</td></tr>\n");
		data->push_back(L"<tr>\n");
		data->push_back(L"<td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kDiskSpaceUsed] + L" </td>\n");

		if (GScanEngine->Data[DataSource].DiskStats.DriveSpaceUsed > 0)
		{
			data->push_back(L"<td width=\"92\" class=\"C4L\"> <b>" + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].DiskStats.DriveSpaceUsed) + L"</b></td>\n");
		}
		else
		{
			data->push_back(L"<td width=\"92\" class=\"C4L\"> <b>" + GLanguageHandler->Text[kUnknown] + L"</b></td>\n");
		}

		data->push_back(L"</tr>\n");

		data->push_back(L"<tr>\n");
		data->push_back(L"<td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kDiskSpaceWasted] + L" </td>\n");

		if (GScanEngine->Data[DataSource].TotalSizeOD >= GScanEngine->Data[DataSource].TotalSize)
		{
			data->push_back(L"<td width=\"92\" class=\"C4L\"> <b>" + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSizeOD - GScanEngine->Data[DataSource].TotalSize) + L"</b></td>\n");
		}
		else
		{
			data->push_back(L"<td width=\"92\" class=\"C4L\"> <b>" + GLanguageHandler->Text[kUnknown] + L"</b></td>\n");
		}

		data->push_back(L"</tr>\n");
		data->push_back(L"<tr><td width=\"170\" class=\"C4G\">&nbsp;</td><td width=\"92\" class=\"C4G\">&nbsp;</td></tr>\n");

		if (GScanEngine->Data[DataSource].DiskStats.DriveSpaceFree > 0)
		{
			data->push_back(L"<tr><td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kDiskSpaceFree] + L" </td>" +
				L"<td width=\"92\" class=\"C4L\"> <b>" + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].DiskStats.DriveSpaceFree) + L"</b></td>" +
				L"</tr>\n");
		}
		else
		{
			data->push_back(L"<tr><td width=\"170\" class=\"C4R\">" + GLanguageHandler->Text[kDiskSpaceFree] + L" </td><td width=\"92\" class=\"C4L\"> <b>?</b> </td></tr>\n");
		}

		data->push_back(L"<tr><td width=\"170\" class=\"C4G\">&nbsp;</td><td width=\"92\" class=\"C4G\">&nbsp;</td></tr>\n");
		data->push_back(L"<tr><td width=\"170\" class=\"C4G\">&nbsp;</td><td width=\"92\" class=\"C4G\">&nbsp;</td></tr>\n");
		data->push_back(L"</table>\n");
		data->push_back(L"</td>\n");
		data->push_back(L"</tr>\n");
		data->push_back(L"</table>\n");

		InsertSpacingTable(data);
	}


	void ReportExclude(std::vector<std::wstring> *data, HTMLReportOptions& options, int DataSource)
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

		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellspacing=\"1\" cellpadding=\"1\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
		data->push_back(L"<tr><td width=\"100%\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\" class=\"C7G\"><strong>Excluded Folders</strong></td></tr>\n");
		data->push_back(L"<tr class=\"C4L\"><td>Folder Pattern List: <strong>" + FolderList + L"</strong></td></tr>\n");
		data->push_back(L"<tr class=\"C4L\"><td>&nbsp;</td></tr>\n");
		data->push_back(L"<tr class=\"C4L\"><td>Excluded <strong>" + std::to_wstring(GScanEngine->Data[DataSource].Path.ExcludedFolderCount) + L"</strong> folders (top level)</td></tr>\n");
		data->push_back(L"</table>\n");

		InsertSpacingTable(data);
	}


	void ReportDirectoryList(int fileDatesCount, std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		// ============================================================================
		// == directory list---by file count ==========================================
		// ============================================================================

		FourColumnTableDoubleTitleHeader(data, L"op4", GLanguageHandler->Text[kFoldersRootQuantity], GLanguageHandler->Text[kFolder], GLanguageHandler->Text[kQtyOfFiles], GLanguageHandler->Text[kAsPercent], options);

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			//find largest category %
			int large1 = 0;
			int rowidx = 1;
			int colour = 0;

			for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
			{
				if (std::round(((double)rootfolder->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) > large1)
				{
					large1 = std::round(((double)rootfolder->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100);
				}
			}

			if (large1 <= 0) { large1 = kReportSizes[kBarGraphSmall]; }

			GScanEngine->Data[DataSource].SortByProperty(SortMode::kRootFoldersCount);

			int mod = 0;

			for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
			{
				if (rootfolder->Count != 0)
				 {
					if (options.HTMLMonoBargraph)
					{
						colour = options.HTMLColours[4];
					}
					else
					{
						colour = kSpectrumColours[mod % kSpectrumMod];
					}

					// ==================================================================

					std::wstring link = L"";

					if (mod == 0)
					{
						link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Data[DataSource].Path.String) + L"\" target=\"_blank\">" + Formatting::MakeItalic(rootfolder->Name, rootfolder->Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
					}
					else
					{
						link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Data[DataSource].Path.String + rootfolder->Name) + L"\" target=\"_blank\">" + Formatting::MakeItalic(rootfolder->Name, rootfolder->Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
					}

					FourColumnTableRow(data, rowidx, link,
						std::to_wstring(rootfolder->Count),
						Convert::DoubleToPercent((double)rootfolder->Count / (double)GScanEngine->Data[DataSource].FileCount),
						colour,
						(((double)rootfolder->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) * ((double)kReportSizes[kBarGraphSmall] / (double)large1),
						options
					);

					rowidx++;
				}

                mod++;
			}

			data->push_back(L"</table>\n");

			if ((options.Layout[0]) && (fileDatesCount != 0))
			{
				SingleGraph(data, kQuantity, L"chartDirectory1", options);
			}

			InsertSpacingTable(data);

			// ============================================================================
			// == directory list---by file size ===========================================
			// ============================================================================

			FourColumnTableDoubleTitleHeader(data, L"op4", GLanguageHandler->Text[kFoldersRootSize], GLanguageHandler->Text[kFolder], GLanguageHandler->Text[kSizeOfFiles], GLanguageHandler->Text[kAsPercent], options);

			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				//find largest category %
				large1  = 0;

				for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
				{
					if (std::round(((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) > large1)
					{
						large1 = std::round(((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100);
					}
				}

				if (large1 <= 0) { large1 = kReportSizes[kBarGraphSmall]; }

				rowidx = 1;

				GScanEngine->Data[DataSource].SortByProperty(SortMode::kRootFoldersSize);

				mod = 0;

				for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
				{
					if (rootfolder->Count != 0)
					{
						if (options.HTMLMonoBargraph)
						{
							colour = options.HTMLColours[4];
						}
						else
						{
							colour = kSpectrumColours[mod % kSpectrumMod];
						}

						std::wstring link = L"";

						if (mod == 0)
						{
							link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Data[DataSource].Path.String) + L"\" target=\"_blank\">" + Formatting::MakeItalic(rootfolder->Name, rootfolder->Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
						}
						else
						{
							link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Data[DataSource].Path.String + rootfolder->Name) + L"\" target=\"_blank\">" + Formatting::MakeItalic(rootfolder->Name, rootfolder->Attributes  & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
						}

						FourColumnTableRow(data, rowidx, link,
							Convert::GetSizeString(options.Units, rootfolder->Size),
							Convert::DoubleToPercent((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize),
							colour,
							(((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100)* ((double)kReportSizes[kBarGraphSmall] / (double)large1),
							options
						);

						rowidx++;
					}
				}

				if (options.Layout[0])
				{
					data->push_back(L"</table>\n");

					SingleGraph(data, kSize, L"chartDirectory2", options);
				}

				// ============================================================================
				// == directory list---alphabetical by file size ==============================
				// ============================================================================

				FourColumnTableDoubleTitleHeader(data, L"op4", GLanguageHandler->Text[kFoldersRootSize], GLanguageHandler->Text[kFolder] + L" (alphabetical)", GLanguageHandler->Text[kSizeOfFiles], GLanguageHandler->Text[kAsPercent], options);

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					//find largest category %
					large1 = 0;

					for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
					{
						if (std::round(((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) > large1)
						{
							large1 = std::round(((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100);
						}
					}

					if (large1 <= 0) { large1 = kReportSizes[kBarGraphSmall]; }

					rowidx = 1;

			        GScanEngine->Data[DataSource].SortByProperty(SortMode::kRootFoldersName);

					mod = 0;

					for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
					{
						if (rootfolder->Count != 0)
						{
							if (options.HTMLMonoBargraph)
							{
								colour = options.HTMLColours[4];
							}
							else
							{
								colour = kSpectrumColours[mod % kSpectrumMod];
							}

							std::wstring link = L"";

							if (mod == 0)
							{
								link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Data[DataSource].Path.String) + L"\" target=\"_blank\">" + Formatting::MakeItalic(rootfolder->Name, rootfolder->Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
							}
							else
							{
								link = L"<a href=\"" + Utility::WebFileLink(GScanEngine->Data[DataSource].Path.String + rootfolder->Name) + L"\" target=\"_blank\">" + Formatting::MakeItalic(rootfolder->Name, rootfolder->Attributes & FILE_ATTRIBUTE_HIDDEN) + L"</a>";
							}

							FourColumnTableRow(data, rowidx, link,
								Convert::GetSizeString(options.Units, rootfolder->Size),
								Convert::DoubleToPercent((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize),
								colour,
								(((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) * ((double)kReportSizes[kBarGraphSmall] / (double)large1),
								options
							);

							rowidx++;
						}

                        mod++;
					}
				}
			}
		}

		InsertSpacingTable(data);
	}


	void DeepReportFrom(std::vector<std::wstring> *data, std::wstring folder, SizeOfFolder sof, unsigned __int64 largestSize, int largestCount, HTMLReportOptions &options)
	{
		SevenColumnTableDoubleTitleHeader(data, L"op9", GLanguageHandler->Text[kFileAttributes] + L" (Created)", GLanguageHandler->Text[kYear], options);
	}


	void ReportTop101Largest(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		// ============================================================================
		// == top 50 largest files ====================================================
		// ============================================================================

		FourColumnTableDoubleTitleHeader(data, L"op9", GLanguageHandler->Text[kTop101] + L"(" + GLanguageHandler->Text[kLargest] + L")", GLanguageHandler->Text[kFileTypes],
			GLanguageHandler->Text[kSize],
			GLanguageHandler->Text[kOwner],
			options
		);

		int mod = 0;

		for (FileObject *file : GScanEngine->Data[DataSource].Top100Large)
		{
			float tableWidth = 0;

			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				tableWidth = ((double)file->Size / (double)GScanEngine->Data[DataSource].TotalSize) * (double)kReportSizes[kBarGraphSmall];
			}

			FourColumnTableRow(data, mod,
				GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name,
				Convert::GetSizeString(options.Units, file->Size),
				GScanEngine->Data[DataSource].Users[file->Owner]->Name,
				options.HTMLColours[4],
				tableWidth,
                options
				);

            mod++;
		}

		data->push_back(L"</table>\n");

		InsertSpacingTable(data);
	}


	void ReportTop101Smallest(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">" +
			L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\"><td colspan=\"2\" height=\"13\"><a name=\"op14\"/><b>" + GLanguageHandler->Text[kTop101] + L"(" + GLanguageHandler->Text[kSmallest] + L")</b></td></tr>" +
			L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">" +
			L"<td height=\"13\" width=\"685\"><b>" + GLanguageHandler->Text[kFiles] + L"</b></td>" +
			L"<td height=\"13\" width=\"85\"><b>" + GLanguageHandler->Text[kSize] + L"</b></td>" +
			L"</tr>\n");

		int mod = 0;

		for (FileObject *file : GScanEngine->Data[DataSource].Top100Small)
		{
			if (mod % 2 != 0)
			{
				data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
			}
			else
			{
				data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[10]) + L"\">\n");
			}

			data->push_back(L"<td height=\"13\" width=\"685\">" + GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"</td>\n");
			data->push_back(L"<td height=\"13\" width=\"85\"><div align=\"" + options.Align + L"\">" + Convert::GetSizeString(options.Units, file->Size) + L"</div></td>\n");
			data->push_back(L"</tr>\n");

            mod++;
		}

		data->push_back(L"</table>\n");

		InsertSpacingTable(data);
	}


	void ReportTop101Newest(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		FourColumnTableDoubleTitleHeaderNoGraph(data, L"op13", GLanguageHandler->Text[kHTMLReport16], GLanguageHandler->Text[kFiles],
			GLanguageHandler->Text[kCreated],
			GLanguageHandler->Text[kSize],
			GLanguageHandler->Text[kOwner],
			options
		);

		int mod = 0;

		for (FileObject *file : GScanEngine->Data[DataSource].Top100Newest)
		{
			FourColumnTableDoubleTitleNoGraphRow(data, mod, file->Name,
				Convert::IntDateToString(file->DateCreated),
				Convert::GetSizeString(options.Units, file->Size),
				GScanEngine->Data[DataSource].Users[file->Owner]->Name,
				options
			);

            mod++;
		}

		data->push_back(L"</table>\n");

		InsertSpacingTable(data);
	}


	void ReportTop101Oldest(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		FourColumnTableDoubleTitleHeaderNoGraph(data, L"op14", GLanguageHandler->Text[kHTMLReport17], GLanguageHandler->Text[kFiles],
			GLanguageHandler->Text[kCreated],
			GLanguageHandler->Text[kSize],
			GLanguageHandler->Text[kOwner],
            options
		);

		int mod = 0;

		for (FileObject *file : GScanEngine->Data[DataSource].Top100Oldest)
		{
			FourColumnTableDoubleTitleNoGraphRow(data, mod, file->Name,
				Convert::IntDateToString(file->DateCreated),
				Convert::GetSizeString(options.Units, file->Size),
				GScanEngine->Data[DataSource].Users[file->Owner]->Name,
				options
			);

			mod++;
		}

		data->push_back(L"</table>\n");

		InsertSpacingTable(data);
	}


	void ReportFileDates(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		if (options.Layout[0])
		{
			SingleGraph(data, kFileDates, L"chartFileDates1", options);

			SingleGraph(data, kFileDates, L"chartFileDates2", options);

			InsertSpacingTable(data);
		}

		SevenColumnTableDoubleTitleHeader(data, L"op9", GLanguageHandler->Text[kFileAttributes] + L" (Created)", GLanguageHandler->Text[kYear], options);

		if (GScanEngine->Data[DataSource].Files.size() != 0)
		{
			//find largest category %
			int large1 = 0;
			int large2 = 0;

			for (FileDateObject *fdo : GScanEngine->Data[DataSource].FileDates)
			{
				if (std::round(((double)fdo->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) > large1)
				{
					large1 = std::round(((double)fdo->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100);
				}

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					if (std::round(((double)fdo->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) > large2)
					{
						large2 = std::round(((double)fdo->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100);
					}
				}
			}

			if (large1 == 0) large1 = kReportSizes[kBarGraph];
			if (large2 == 0) large2 = kReportSizes[kBarGraph];

			int rowidx = 1;

			for (FileDateObject *fdo : GScanEngine->Data[DataSource].FileDates)
			{
				if ((GScanEngine->Data[DataSource].FileCount != 0) && (fdo->Count != 0))
				{
					std::wstring aspc = L"100%";
					float aspcgraph = (double)kReportSizes[kBarGraph];

					if (GScanEngine->Data[DataSource].TotalSize != 0)
					{
						aspc = Convert::DoubleToPercent((double)fdo->Size / (double)GScanEngine->Data[DataSource].TotalSize);
					}

					if (GScanEngine->Data[DataSource].TotalSize != 0)
					{
						aspcgraph = (((double)fdo->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100) * ((double)kReportSizes[kBarGraph] / (double)large2);
					}

					SevenColumnTableRow(data, rowidx, std::to_wstring(fdo->Year),
						std::to_wstring(fdo->Count),
						Convert::DoubleToPercent((double)fdo->Count / (double)GScanEngine->Data[DataSource].FileCount),
						Convert::GetSizeString(options.Units, fdo->Size),
						aspc,
						options.HTMLColours[4],
						(((double)fdo->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100) * ((double)kReportSizes[kBarGraph] / (double)large1),
						aspcgraph,
						options
						);

					rowidx++;
				}
			}

			InsertSpacingTable(data);
		}
		else
		{
			SevenColumnTableRowBlank(data, 0, L"<b>No data</b", options);

			InsertSpacingTable(data);
		}
	}

	void ReportNullFiles(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		int rowidx = 0;

		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		data->push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\"><td height=\"13\"><a name=\"op7\" /><b>" + GLanguageHandler->Text[kNullFiles] + L"</b></td></tr>\n");

		if (GScanEngine->Data[DataSource].NullFiles.size() == 0)
		{
			data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\" class=\"C4G\"><td colspan=\"7\" height=\"13\">" + GLanguageHandler->Text[kNoneFound] + L"</td></tr>\n");
		}
		else
		{
			for (int t = 0; t < GScanEngine->Data[DataSource].NullFiles.size(); t++)
			{
				if (t % 2 == 0)
				{
					data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
				}
				else
				{
					data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[10]) + L"\">\n");
				}

				data->push_back(L"<td height=\"13\">" + GScanEngine->Data[DataSource].NullFiles[t] + L"</td>\n");

				data->push_back(L"</tr>\n");

				rowidx++;
			}
		}

		data->push_back(L"</table>\n");

		InsertSpacingTable(data);
	}


	std::wstring BuildMenuList(HTMLReportOptions &options)
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


	void InsertSpacingTable(std::vector<std::wstring> *data)
	{
		data->push_back(L"<table align=\"center\" width=\"770\" border=\"0\"><tr><td>&nbsp;</td></tr></table>\n");
	}


	void DoubleGraph(std::vector<std::wstring> *data, std::wstring id1, std::wstring id2, HTMLReportOptions &options)
	{
		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellspacing=\"1\" cellpadding=\"1\">" +
			L"<tr class=\"C7CB\">" +
			L"<td bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">" + GLanguageHandler->Text[kQuantity] + L"</td>" +
			L"<td bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">" + GLanguageHandler->Text[kSize] + L"</td>" +
			L"</tr>" +
			L"<tr>" +
			L"<td bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\"><div align=\"center\" id=\"" + id1 + L"\"></td>" +
			L"<td bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\"><div align=\"center\" id=\"" + id2 + L"\"></td>" +
			L"</tr>" +
			L"</table>\n");
	}


	void SingleGraph(std::vector<std::wstring> *data, int title_language_id, std::wstring id, HTMLReportOptions &options)
	{
		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellspacing=\"1\" cellpadding=\"1\">" +
			L"<tr class=\"C7CB\">" +
			L"<td bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">" + GLanguageHandler->Text[title_language_id] + L"</td>" +
			L"</tr>" +
			L"<tr><td bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\"><div align=\"center\" id=\"" + id + L"\"></td></tr>" +
			L"</table>\n");
	}


	void BuildGraphScript(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		data->push_back(L"<script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n");
		data->push_back(L"<script type=\"text/javascript\">\n");
		data->push_back(L"google.charts.load('current', {'packages':['corechart']});\n");
		data->push_back(L"google.charts.setOnLoadCallback(drawChart);\n");

		data->push_back(L"function drawChart() {\n");

		BuildGraphData(data, options, DataSource);

		BuildGraphCode(data, options);

		data->push_back(L"}\n");

		data->push_back(L"</script>\n");
	}


	void BuildGraphData(std::vector<std::wstring> *data, HTMLReportOptions &options, int DataSource)
	{
		for (int t = 0; t < kHTMLLayoutOptionsCount; t++)
		{
			if (options.Layout[t])
			{
				switch (t)
				{
				case 0:
					BuildGraphDataQuickInfo(data, DataSource);

					break;
				case 2:
					BuildGraphDataCategory(data, DataSource);

					break;
				case 3:
					BuildGraphDataDirectory(data, DataSource);

					break;
				case 4:
					BuildGraphDataMagnitude(data, DataSource);

					break;
				case 7:
					BuildGraphDataFileDates(data, DataSource);

					break;
				}
			}
		}
	}


	void BuildGraphCode(std::vector<std::wstring> *data, HTMLReportOptions &options)
	{
		for (int t = 0; t < kHTMLLayoutOptionsCount; t++)
		{
			if (options.Layout[t])
			{
				switch (t)
				{
				case 0:
					data->push_back(L"var optionsQI1 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartDD]) + L", 'height' : 200 };\n");
					data->push_back(L"var optionsQI2 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartDD]) + L", 'height' : 200 };\n");

					data->push_back(L"var chartQI1 = new google.visualization.PieChart(document.getElementById('chartQuickInfo1'));\n");
					data->push_back(L"var chartQI2 = new google.visualization.PieChart(document.getElementById('chartQuickInfo2'));\n");
					data->push_back(L"chartQI1.draw(dataQI1, optionsQI1);\n");
					data->push_back(L"chartQI2.draw(dataQI2, optionsQI2);\n");

					break;
				case 2:
					data->push_back(L"var optionsC1 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartCM]) + L", 'height' : 220 };\n");
					data->push_back(L"var optionsC2 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartCM]) + L", 'height' : 220 };\n");

					data->push_back(L"var chartC1 = new google.visualization.ColumnChart(document.getElementById('chartCategory1'));\n");
					data->push_back(L"var chartC2 = new google.visualization.ColumnChart(document.getElementById('chartCategory2'));\n");

					data->push_back(L"chartC1.draw(dataC1, optionsC1);\n");
					data->push_back(L"chartC2.draw(dataC2, optionsC2);\n");

					break;
				case 3:
					data->push_back(L"var optionsD1 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartCD]) + L", 'height' : 400 };\n");
					data->push_back(L"var optionsD2 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartCD]) + L", 'height' : 400 };\n");

					data->push_back(L"var chartD1 = new google.visualization.ColumnChart(document.getElementById('chartDirectory1'));\n");
					data->push_back(L"var chartD2 = new google.visualization.ColumnChart(document.getElementById('chartDirectory2'));\n");

					data->push_back(L"chartD1.draw(dataD1, optionsD1);\n");
					data->push_back(L"chartD2.draw(dataD2, optionsD2);\n");

					break;
				case 4:

					data->push_back(L"var optionsM1 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartXM]) + L", 'height' : 220 };\n");
					data->push_back(L"var optionsM2 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartXM]) + L", 'height' : 220 };\n");

					data->push_back(L"var chartM1 = new google.visualization.ColumnChart(document.getElementById('chartMagnitude1'));\n");
					data->push_back(L"var chartM2 = new google.visualization.ColumnChart(document.getElementById('chartMagnitude2'));\n");

					data->push_back(L"chartM1.draw(dataM1, optionsM1);\n");
					data->push_back(L"chartM2.draw(dataM2, optionsM2);\n");


					break;
				case 7:

					data->push_back(L"var optionsFD1 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartFD]) + L", 'height' : 400 };\n");
					data->push_back(L"var optionsFD2 = { 'legend' : 'none', 'width' : " + std::to_wstring(kReportSizes[kChartFD]) + L", 'height' : 400 };\n");

					data->push_back(L"var chartFD1 = new google.visualization.ColumnChart(document.getElementById('chartFileDates1'));\n");
					data->push_back(L"var chartFD2 = new google.visualization.ColumnChart(document.getElementById('chartFileDates2'));\n");

					data->push_back(L"chartFD1.draw(dataFD1, optionsFD1);\n");
					data->push_back(L"chartFD2.draw(dataFD2, optionsFD2);\n");

					break;
				}
			}
		}
	}


	void BuildGraphDataQuickInfo(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"var dataQI1 = google.visualization.arrayToDataTable([\n");
		data->push_back(L"['Disk space', '%'], ['Disk Free', " + std::to_wstring(GScanEngine->Data[DataSource].DiskStats.DriveSpaceFree) + L"], ['Disk Used', " + std::to_wstring(GScanEngine->Data[DataSource].DiskStats.DriveSpaceUsed) + L"] ]);\n");

		data->push_back(L"var dataQI2 = google.visualization.arrayToDataTable([\n");
		data->push_back(L"['Disk space', '%'], ['Disk', " + std::to_wstring(GScanEngine->Data[DataSource].DiskStats.DriveSpaceTotal - GScanEngine->Data[DataSource].TotalSize) + L"], ['Scan', " + std::to_wstring(GScanEngine->Data[DataSource].TotalSize) + L"] ]);\n");
	}


	void BuildGraphDataCategory(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"var dataC1 = new google.visualization.arrayToDataTable([ ['Category', 'Quantity', { role: 'style' }],\n");

		for (int t = 1; t < kFileCategoriesCount; t++)
		{
			data->push_back(L"['" + GLanguageHandler->TypeDescriptions[t] + L"', " + std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count) + L", '#" + Convert::WebColour(GSettingsHandler->FileCategoryColors[t]) + L"'],\n");
		}

		data->push_back(L"]);\n");

		data->push_back(L"var dataC2 = new google.visualization.arrayToDataTable([ ['Category', 'Size', { role: 'style' }],\n");

		for (int t = 1; t < kFileCategoriesCount; t++)
		{
			data->push_back(L"['" + GLanguageHandler->TypeDescriptions[t] + L"', " + std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Size) + L", '#" + Convert::WebColour(GSettingsHandler->FileCategoryColors[t]) + L"'],\n");
		}

		data->push_back(L"]);\n");
	}


	void BuildGraphDataDirectory(std::vector<std::wstring> *data, int DataSource)
	{
		int colour;

		data->push_back(L"var dataD1 = new google.visualization.arrayToDataTable([ ['Folder', 'Quantity', { role: 'style' }],\n");

		for (int t = 0; t < GScanEngine->Data[DataSource].RootFolders.size(); t++)
		{
			colour = kSpectrumColours[t % kSpectrumMod];

			data->push_back(L"[\"" + GScanEngine->Data[DataSource].RootFolders[t]->Name + L"\", " + std::to_wstring(GScanEngine->Data[DataSource].RootFolders[t]->Count) + L", '#" + Convert::WebColour(colour) + L"'],\n");
		}

		data->push_back(L"]);\n");

		data->push_back(L"var dataD2 = new google.visualization.arrayToDataTable([ ['Folder', 'Size', { role: 'style' }],\n");

		for (int t = 0; t < GScanEngine->Data[DataSource].RootFolders.size(); t++)
		{
			colour = kSpectrumColours[t % kSpectrumMod];

			data->push_back(L"[\"" + GScanEngine->Data[DataSource].RootFolders[t]->Name + L"\", " + std::to_wstring(GScanEngine->Data[DataSource].RootFolders[t]->Size) + L", '#" + Convert::WebColour(colour) + L"'],\n");
		}

		data->push_back(L"]);\n");
	}


	void BuildGraphDataMagnitude(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"var dataM1 = new google.visualization.arrayToDataTable([ ['Range', 'Quantity', { role: 'style' }],\n");

		for (int t = 0; t < kMagnitudesCount; t++)
		{
			data->push_back(L"['" + kMagnitudeLabelsShort[t] + L"', " + std::to_wstring(GScanEngine->Data[DataSource].Magnitude[t].Count) + L", '#" + Convert::WebColour(kMagnitudeColours[t]) + L"'],\n");
		}

		data->push_back(L"]);\n");

		data->push_back(L"var dataM2 = new google.visualization.arrayToDataTable([ ['Range', 'Size', { role: 'style' }],\n");

		for (int t = 0; t < kMagnitudesCount; t++)
		{
			data->push_back(L"['" + kMagnitudeLabelsShort[t] + L"', " + std::to_wstring(GScanEngine->Data[DataSource].Magnitude[t].Size) + L", '#" + Convert::WebColour(kMagnitudeColours[t]) + L"'],\n");
		}

		data->push_back(L"]);\n");
	}


	void BuildGraphDataFileDates(std::vector<std::wstring> *data, int DataSource)
	{
		int colour;

		data->push_back(L"var dataFD1 = new google.visualization.arrayToDataTable([ ['Year', 'Quantity', { role: 'style' }],\n");

		for (int t = 0; t < GScanEngine->Data[DataSource].FileDates.size(); t++)
		{
			if (GScanEngine->Data[DataSource].FileDates[t]->Count != 0)
			{
				colour = kSpectrumColours[t % kSpectrumMod];

				data->push_back(L"['" + std::to_wstring(GScanEngine->Data[DataSource].FileDates[t]->Year) + L"', " + std::to_wstring(GScanEngine->Data[DataSource].FileDates[t]->Count) + L", '#" + Convert::WebColour(colour) + L"'],\n");
			}
		}

		data->push_back(L"]);\n");

		data->push_back(L"var dataFD2 = new google.visualization.arrayToDataTable([ ['Year', 'Size', { role: 'style' }],\n");

		for (int t = 0; t < GScanEngine->Data[DataSource].FileDates.size(); t++)
		{
			if (GScanEngine->Data[DataSource].FileDates[t]->Count != 0)
			{
				colour = kSpectrumColours[t % kSpectrumMod];

				data->push_back(L"['" + std::to_wstring(GScanEngine->Data[DataSource].FileDates[t]->Year) + L"', " + std::to_wstring(GScanEngine->Data[DataSource].FileDates[t]->Size) + L", '#" + Convert::WebColour(colour) + L"'],\n");
			}
		}

		data->push_back(L"]);\n");
	}


	void FourColumnTableDoubleTitleHeader(std::vector<std::wstring> *data, std::wstring anchor, std::wstring title_top, std::wstring title_bottom, std::wstring col1, std::wstring col2, HTMLReportOptions &options)
	{
		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">" +
			L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\"><td colspan=\"4\" height=\"13\"><a name=\"" + anchor + L"\" /><b>" + title_top + L"</b></td></tr>" +
			L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">" +
			L"<td height=\"13\" width=\"910\"><b>" + title_bottom + L"</b></td>" +
			L"<td height=\"13\" width=\"160\" class=\"XCB\">&nbsp;</td>" +
			L"<td height=\"13\" width=\"90\" class=\"XCB\">" + col1 + L"</td>" +
			L"<td height=\"13\" width=\"90\" class=\"XCB\">" + col2 + L"</td>" +
			L"</tr>\n");
	}


	void FourColumnTableRow(std::vector<std::wstring> *data, int row, std::wstring col1, std::wstring col3, std::wstring col4, int graph_colour, float graph, HTMLReportOptions &options)
	{
		if (row % 2 != 0)
		{
			data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
		}
		else
		{
			data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[10]) + L"\">\n");
		}

		data->push_back(L"<td height=\"13\">" + col1 + L"</td>\n");
		data->push_back(L"<td height=\"13\">\n");
		data->push_back(L"<table width=\"" + std::to_wstring(graph) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(graph_colour) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">\n");
		data->push_back(L"<tr><td></td></tr>\n");
		data->push_back(L"</table>\n");
		data->push_back(L"</td>\n");
		data->push_back(L"<td height=\"13\" align=\"right\">" + col3 + L"</td>\n");
		data->push_back(L"<td height=\"13\" align=\"right\">" + col4 + L"</td>\n");
		data->push_back(L"</tr>\n");
	}


	void FourColumnTableDoubleTitleHeaderNoGraph(std::vector<std::wstring> *data, std::wstring anchor, std::wstring title_top, std::wstring title_bottom, std::wstring col1, std::wstring col2, std::wstring col3, HTMLReportOptions &options)
	{
		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		data->push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">\n");
		data->push_back(L"<td colspan=\"4\" height=\"13\"><a name=\"" + anchor + L"\" /><b>" + title_top + L"</b></td>\n");
		data->push_back(L"</tr>\n");
		data->push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">\n");
		data->push_back(L"<td height=\"13\" width=\"980\"><b>" + title_bottom + L"</b></td>\n");
		data->push_back(L"<td height=\"13\" width=\"90\" align=\"center\"><b>" + col1 + L"</b></td>\n");
		data->push_back(L"<td height=\"13\" width=\"90\" align=\"center\"><b>" + col2 + L"</b></td>\n");
		data->push_back(L"<td height=\"13\" width=\"90\" align=\"center\"><b>" + col3 + L"</b></td>\n");
	}


	void FourColumnTableDoubleTitleNoGraphRow(std::vector<std::wstring> *data, int row, std::wstring col1, std::wstring col2, std::wstring col3, std::wstring col4, HTMLReportOptions &options)
	{
		if (row % 2 != 0)
		{
			data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
		}
		else
		{
			data->push_back(L"<tr class=\"C4G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[10]) + L"\">\n");
		}

		data->push_back(L"<td height=\"13\">" + col1 + L"</td>\n");
		data->push_back(L"<td height=\"13\" align=\"right\">" + col2 + L"</td>\n");
		data->push_back(L"<td height=\"13\" align=\"right\">" + col3 + L"</td>\n");
		data->push_back(L"<td height=\"13\" align=\"left\">" + col4 + L"</td>\n");
		data->push_back(L"</tr>\n");
	}


	void SevenColumnTableHeader(std::vector<std::wstring> *data, std::wstring anchor, std::wstring title, HTMLReportOptions &options)
	{
		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">" +
			L"<td width=\"150\" height=\"13\" class=\"C7G\"> <a name=\"" + anchor + L"\" /><b>" + title + L"</b></td>" +
			L"<td width=\"90\" height=\"13\" class=\"C7CB\">" + GLanguageHandler->Text[kQuantity] + L"</td>" +
			L"<td width=\"80\" height=\"13\" class=\"C7CB\">" + GLanguageHandler->Text[kAsPercent] + L"</td>" +
			L"<td width=\"380\" height=\"13\"> &nbsp; </td>" +
			L"<td width=\"90\" height=\"13\" class=\"C7CB\">" + GLanguageHandler->Text[kSizeOfFiles] + L"</td>" +
			L"<td width=\"80\" height=\"13\" class=\"C7CB\">" + GLanguageHandler->Text[kAsPercent] + L"</td>" +
			L"<td width=\"380\" height=\"20\">&nbsp;</td>" +
			L"</tr>\n");
	}


	void SevenColumnTableRow(std::vector<std::wstring> *data, int row, std::wstring caption, std::wstring col1, std::wstring col2, std::wstring col3, std::wstring col4, int graph_colour, float graph_left, float graph_right, HTMLReportOptions &options)
	{
		if (row % 2 != 0)
		{
			data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
		}
		else
		{
			data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[10]) + L"\">\n");
		}

		data->push_back(L"<td class=\"C4L\">" + caption + L"</td>\n");
		data->push_back(L"<td class=\"C4G\" align=\"right\">" + col1 + L"</td>\n");
		data->push_back(L"<td class=\"C4G\" align=\"right\">" + col2 + L"</td>\n");
		data->push_back(L"<td><table width=\"" + std::to_wstring((int)graph_left) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(graph_colour) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">" +
			L"<tr><td></td></tr></table></td>\n");
		data->push_back(L"<td class=\"C4G\" align=\"right\">" + col3 + L"</td>\n");
		data->push_back(L"<td class=\"C4G\" align=\"right\">" + col4 + L"</td>" +
			L"<td>" +
			L"<table width=\"" + std::to_wstring((int)graph_right) + L"\" border=\"0\" bgcolor=\"#" + Convert::WebColour(graph_colour) + L"\" height=\"8\" cellpadding=\"0\" cellspacing=\"0\">" +
			L"<tr><td></td></tr>" +
			L"</table>" +
			L"</td>\n");
		data->push_back(L"</tr>\n");
	}


	void SevenColumnTableRowBlank(std::vector<std::wstring> *data, int row, std::wstring caption, HTMLReportOptions &options)
	{
		if (row % 2 != 0)
		{
			data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[9]) + L"\">\n");
		}
		else
		{
			data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[10]) + L"\">\n");
		}

		data->push_back(L"<td class=\"C4L\">" + caption + L"</td>\n");
		data->push_back(L"<td class=\"C4C\" align=\"right\">&nbsp;</td>\n");
		data->push_back(L"<td class=\"C4C\" align=\"right\">&nbsp;</td>\n");
		data->push_back(L"<td>&nbsp;</td>\n");
		data->push_back(L"<td class=\"C4G\" align=\"right\">&nbsp;</td>\n");
		data->push_back(L"<td class=\"C4C\" align=\"right\">&nbsp;</td>\n");
		data->push_back(L"<td>&nbsp;</td></tr>\n");
	}


	void SevenColumnTableEnd(std::vector<std::wstring> *data)
	{
		data->push_back(L"</table>\n");
	}


	void SevenColumnTableDoubleTitleHeader(std::vector<std::wstring> *data, std::wstring anchor, std::wstring title_top, std::wstring title_bottom, HTMLReportOptions &options)
	{
		data->push_back(L"<table align=\"center\" width=\"" + std::to_wstring(kReportSizes[kTableWidth]) + L"\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\">\n");
		data->push_back(L"<tr class=\"C7G\" bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">\n");
		data->push_back(L"<td colspan=\"7\" width=\"387\" height=\"20\"><a name=\"" + anchor + L"\"</a><b>" + title_top + L"</b></td>\n");
		data->push_back(L"</tr>\n");
		data->push_back(L"<tr bgcolor=\"#" + Convert::WebColour(options.HTMLColours[5]) + L"\">\n");
		data->push_back(L"<td width=\"150\" height=\"13\" class=\"C7G\"><a name=\"op3\" /><b>" + GLanguageHandler->Text[kYear] + L"</b></td>\n");
		data->push_back(L"<td width=\"90\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kQuantity] + L"</b></div></td>\n");
		data->push_back(L"<td width=\"80\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>\n");
		data->push_back(L"<td width=\"380\" height=\"13\">&nbsp;</td>\n");
		data->push_back(L"<td width=\"90\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kSizeOfFiles] + L"</b></div></td>\n");
		data->push_back(L"<td width=\"80\" height=\"13\" class=\"C7G\"><div align=\"center\"><b>" + GLanguageHandler->Text[kAsPercent] + L"</b></div></td>\n");
		data->push_back(L"<td width=\"380\" height=\"20\">&nbsp;</td>\n");
		data->push_back(L"</tr>\n");
	}


	void FileReport(std::vector<std::wstring> *data, int DataSource, const std::wstring file_name, const std::wstring title)
	{
		data->push_back(L"<!DOCTYPE html><html><head><style>p { display: inline;} .name { color : #886600; } .user { color : #668800; } .size { color : #006688; }</style></head><body>");
		data->push_back(L"<p>Xinorbis :: <b>" + title + L"</b></p><br/><br/>");

		if (GScanEngine->Data[DataSource].Files.size() != 0)
		{
			for (FileObject *file : GScanEngine->Data[DataSource].Files)
			{
				data->push_back(L"<p class=\"name\">" + GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"</p>");
				data->push_back(L"<p class=\"user\">" + GScanEngine->Data[DataSource].Users[file->Owner]->Name + L"</p>");
				data->push_back(L"<p class=\"size\">" + Convert::ConvertToUsefulUnit(file->Size) + L" (" + std::to_wstring(file->Size) + L" " + GLanguageHandler->Text[kBytes] + L")</p>");
				data->push_back(L"<br/>");
			}
		}
		else
		{
			data->push_back(L"<p class=\"name\">No files found.</p>");
			data->push_back(L"<br/>");
		}

		data->push_back(L"</body></html>");
	}
};
