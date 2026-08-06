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
#include <string>

#include "Convert.h"
#include "DriveDetails.h"
#include "FileExtensionHandler.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportDeep.h"
#include "ReportText.h"
#include "ReportTextOptions.h"
#include "ScanEngine.h"
#include "Utility.h"
#include "WindowsUtility.h"


extern FileExtensionHandler *GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


void ReportText::Generate(TextReportOptions report, std::vector<std::wstring> *data, int DataSource)
{
	//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (Text):\n";
	//GLog->Add( L"    " << options.FileName << "\n\n";

	for (int t = 0; t < kTextReportOptionsCount; t++)
	{
		if (report.Layout[t])
		{
			switch (t)
			{
				case 0:
					ReportHeader(data);
					ReportSummary(data, DataSource);
					break;
				case 1:
					ReportAttributes(data, DataSource);
					break;
				case 2:
					ReportCategories(data, DataSource);
					break;
				case 3:
					ReportDirectoryList(data, DataSource);
					break;
				case 4:
					ReportMagnitude(data, DataSource);
					break;
				case 5:
					ReportExtensions(data, report, DataSource);
					break;
				case 6:
					ReportNullFiles(data, DataSource);
					break;
				case 7:
					ReportTemporaryFiles(data, DataSource);
					break;
				case 8:
					ReportLargestFiles(data, DataSource);
					ReportSmallestFiles(data, DataSource);
					ReportNewestFiles(data, DataSource);
					ReportOldestFiles(data, DataSource);
					break;
				case 9:
					ReportUsers(data, DataSource);
					break;
				case 10:
					ReportFileDates(data, DataSource);
					break;
			}
		}
	}

	if (report.DeepScan)
	{
		CreateDeepReport(data, DataSource);
	}

	data->push_back(L"\n");
	data->push_back(GLanguageHandler->TextReport[0] + L"\n");
	data->push_back(L"======================= FolderScanUltra Text Report = (c) Paul A Freshney " + Utility::CurrentYear() + L" ==\n");
}


void ReportText::CreateDeepReport(std::vector<std::wstring> *data, int DataSource)
{
	ReportDeep deep;

	int anchor = 50;

	for (int r = 0; r < GScanEngine->Data[DataSource].RootFolders.size(); r++)
	{
		std::wstring folder = GScanEngine->Data[DataSource].Path.String;

		if (!GScanEngine->Data[DataSource].RootFolders[r]->FilesInRoot)
		{
			folder += GScanEngine->Data[DataSource].RootFolders[r]->Name + L"\\";
		}

		int folderIndex = GScanEngine->Data[DataSource].GetFolderIndex(folder);

		if (folderIndex != -1)
		{
			if (!deep.ProcessFolder(folderIndex, DataSource))
			{
				// if there are no sub-folders then use the root folder's data
				deep.Add(L"\"", GScanEngine->Data[DataSource].RootFolders[r]->Size, GScanEngine->Data[DataSource].RootFolders[r]->Count);
			}

			if (deep.FolderData.size() != 0)
			{
				TitleBlock5Row(data, 5, 6);
				data->push_back(folder + L"\n\n");

				if (GScanEngine->Data[DataSource].FileCount != 0)
				{
					for (int s = 0; s < deep.FolderData.size(); s++)
					{
						std::wstring str = Formatting::AddTrailing(L' ' + deep.FolderData[s].Folder, TRDescriptionWidth, L' ') +
							Formatting::AddLeading(std::to_wstring(deep.FolderData[s].FileCount), TRQuantityWidth, L' ') + L"  " +
							Formatting::AddLeading(Convert::DoubleToPercent((double)deep.FolderData[s].FileCount / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
							Formatting::AddLeading(Convert::ConvertToUsefulUnit(deep.FolderData[s].Size), TRSizeWidth, L' ');

						if (GScanEngine->Data[DataSource].TotalSize != 0)
						{
							str += Formatting::AddLeading(Convert::DoubleToPercent((double)deep.FolderData[s].Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
						}
						else
						{
							str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
						}

						//      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails.RootFolders[t].Attributes);

						data->push_back(str + L"\n");
					}
				}
				else
				{
					data->push_back(L"\n");
				}

				data->push_back(GLanguageHandler->TextReport[0] + L"\n\n");

				anchor++;
			}
		}
		else
		{
			//GLog->Add( " Error: cannot find folder \"" << folder << "\"\n";
		}
	}
}


void ReportText::ReportHeader(std::vector<std::wstring> *data)
{
	data->push_back(GLanguageHandler->TextReport[0] + L"\n");
	data->push_back(L"--------------------------------------------------------------------------------\n");
	data->push_back(L"-- FolderScanUltra -------------------------------------------------------------\n");
	data->push_back(L"--------------------------------------------------------------------------------\n");
	data->push_back(GLanguageHandler->TextReport[0] + L"\n");
	data->push_back(L"\n");
}


void ReportText::ReportSummary(std::vector<std::wstring> *data, int DataSource)
{
	data->push_back(GLanguageHandler->SummaryReport[0] + L" \"" + GScanEngine->Data[DataSource].Path.String + L"\"\n");

	if (GScanEngine->FilterCategory != -1)
	{
		data->push_back(L"                  (filtered by category \"" + kFileExtensionFileName[GScanEngine->FilterCategory] + L"\")\n");
	}

	if (GScanEngine->Data[DataSource].Source == ScanSource::FileCSV)
	{
		data->push_back(L"                  (from CSV import \"" + GScanEngine->Data[DataSource].Path.FileName + L"\")\n");
	}

	data->push_back(Formatting::AddLeading(L"", GLanguageHandler->SummaryReport[0].size() + 1, L' ') + Utility::GetDate(DateTimeFormat::Display) + L", " + Utility::GetTime(DateTimeFormat::Display) + L"\n\n");
	data->push_back(GLanguageHandler->SummaryReport[1] + L" " + std::to_wstring(GScanEngine->Data[DataSource].FileCount) + L"\n");
	data->push_back(GLanguageHandler->SummaryReport[2] + L" " + std::to_wstring(GScanEngine->Data[DataSource].FolderCount) + L"\n");
	data->push_back(GLanguageHandler->SummaryReport[3] + L" " + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSize) + L"\n\n");
	data->push_back(GLanguageHandler->DriveReport[0]   + L" " + WindowsUtility::GetDiskTypeString(GScanEngine->Data[DataSource].GetDrive()) + L"\n");

	DriveDetails dd = WindowsUtility::GetDriveDetails(GScanEngine->Data[DataSource].GetDrive());

	if (dd.Valid)
	{
		data->push_back(L"\n");

		data->push_back(GLanguageHandler->DriveReport[1] + L" " + dd.FileSystem + L"\n");
		data->push_back(GLanguageHandler->DriveReport[5] + L" " + std::to_wstring(dd.SectorsPerCluster) + L"\n");
		data->push_back(GLanguageHandler->DriveReport[6] + L" " + std::to_wstring(dd.BytesPerSector) + L"\n");
		data->push_back(GLanguageHandler->DriveReport[7] + L" " + std::to_wstring(dd.FreeClusters) + L"\n");
		data->push_back(GLanguageHandler->DriveReport[8] + L" " + std::to_wstring(dd.Clusters) + L"\n");
		data->push_back(GLanguageHandler->DriveReport[9] + L" " + dd.VolumeName + L"\n");
		data->push_back(GLanguageHandler->DriveReport[10] + L" " + dd.SerialNumber + L" (" + dd.SerialNumberHex + L")\n");
	}

	data->push_back(L"\n");

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		data->push_back(GLanguageHandler->SummaryReport[8] + L" " + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].AverageFileSize) + L"\n");
	}

	if (GScanEngine->Data[DataSource].FolderCount != 0)
	{
		data->push_back(GLanguageHandler->SummaryReport[9] + L" " + std::to_wstring(GScanEngine->Data[DataSource].AverageFilesPerFolder) + L"\n");
	}

	data->push_back(L"\n");

	if (GScanEngine->Data[DataSource].Path.ExcludeFolders)
	{
		for (int t = 0; t < GScanEngine->ExcludeCount(); t++)
		{
			data->push_back(GLanguageHandler->SummaryReport[15] + L" " + GScanEngine->GetExcludeItem(t) + L"\n");
		}

		data->push_back(L"\n");
		data->push_back(Formatting::AddLeading(L"", GLanguageHandler->SummaryReport[15].size(), L' ') + L" Excluded " + std::to_wstring(GScanEngine->Data[DataSource].Path.ExcludedFolderCount) + L" folders.\n");
		data->push_back(L"\n");
	}
}


void ReportText::ReportAttributes(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock5Row(data, 3, 4);

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		for (int t = 0; t < kAttributesToDisplayCount; t++)
		{
			std::wstring str =	Formatting::AddTrailing(L" " + GLanguageHandler->LanguageTypes[t], TRDescriptionWidth, L' ') +
								Formatting::AddLeading(std::to_wstring(GScanEngine->Data[DataSource].FileAttributes[t].Count), TRQuantityWidth, L' ') + L"  " +
								Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].FileAttributes[t].Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, ' ') + L"  " +
								Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].FileAttributes[t].Size), TRSizeWidth, ' ') + L"  ";

			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].FileAttributes[t].Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, ' ');
			}
			else
			{
				str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
			}

			data->push_back(L"\n");
		}
	}

	data->push_back(GLanguageHandler->TextReport[0] + L"\n\n");
}


void ReportText::ReportCategories(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock5Row(data, 1, 2);

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		for (int t = 0; t < kFileCategoriesCount; t++)
		{
			std::wstring str = Formatting::AddTrailing(L" " + GLanguageHandler->TypeDescriptions[t], TRDescriptionWidth, L' ') +
				Formatting::AddLeading(std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count), TRQuantityWidth, L' ') + L"  " +
				Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
				Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size), TRSizeWidth, L' ');

			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
			}
			else
			{
				str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
			}

			data->push_back(str + L"\n");
		}

		data->push_back(L"\n");

		std::wstring str = Formatting::AddTrailing(L' ' + GLanguageHandler->Text[kTemporary], TRDescriptionWidth, L' ') +
						   Formatting::AddLeading(std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[0].Count), TRQuantityWidth, L' ') + L"  " +
						   Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[0].Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
						   Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[0].Size), TRSizeWidth, L' ') + L"  ";

		if (GScanEngine->Data[DataSource].TotalSize != 0)
		{
			str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[0].Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
		}
		else
		{
			str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
		}

		data->push_back(str + L"\n");

		data->push_back(GLanguageHandler->TextReport[0] + L"\n\n");
	}
}


void ReportText::ReportDirectoryList(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock5Row(data, 5, 6);

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		GScanEngine->Data[DataSource].SortByProperty(SortMode::kRootFoldersSize);

		if (GScanEngine->Data[DataSource].RootFolders.size() != 0)
		{
			for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
			{
				std::wstring str = Formatting::AddTrailing(L' ' + rootfolder->Name, TRDescriptionWidth, L' ') +
								   Formatting::AddLeading(std::to_wstring(rootfolder->Count), TRQuantityWidth, L' ') + L"  " +
								   Formatting::AddLeading(Convert::DoubleToPercent((double)rootfolder->Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
								   Formatting::AddLeading(Convert::ConvertToUsefulUnit(rootfolder->Size), TRSizeWidth, L' ');

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				//      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails.RootFolders[t].Attributes);

				data->push_back(str + L"\n");
			}
		}
	}

	data->push_back(GLanguageHandler->TextReport[0] + L"\n\n");

	TitleBlock5Row(data, 5, 6);

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		GScanEngine->Data[DataSource].SortByProperty(SortMode::kRootFoldersCount);

		if (GScanEngine->Data[DataSource].RootFolders.size() != 0)
		{
			for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
			{
				std::wstring str = Formatting::AddTrailing(L' ' + rootfolder->Name, TRDescriptionWidth, L' ') +
					Formatting::AddLeading(std::to_wstring(rootfolder->Count), TRQuantityWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::DoubleToPercent((double)rootfolder->Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(rootfolder->Size), TRSizeWidth, L' ');

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				//      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails.RootFolders[t].Attributes);

				data->push_back(str + L"\n");
			}
		}
	}

	data->push_back(GLanguageHandler->TextReport[0] + L"\n\n");

	// ========================================================================================================
	// only show alphabetical table if there are enough entries to make it worth while
	// ========================================================================================================

	if (GScanEngine->Data[DataSource].RootFolders.size() > 20)
	{
		TitleBlock5Row(data, 5, 6);

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
        	GScanEngine->Data[DataSource].SortByProperty(SortMode::kRootFoldersName);

			if (GScanEngine->Data[DataSource].RootFolders.size() != 0)
			{
				for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
				{
					std::wstring str = Formatting::AddTrailing(L' ' + rootfolder->Name, TRDescriptionWidth, L' ') +
						Formatting::AddLeading(std::to_wstring(rootfolder->Count), TRQuantityWidth, L' ') + L"  " +
						Formatting::AddLeading(Convert::DoubleToPercent((double)rootfolder->Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
						Formatting::AddLeading(Convert::ConvertToUsefulUnit(rootfolder->Size), TRSizeWidth, L' ');

					if (GScanEngine->Data[DataSource].TotalSize != 0)
					{
						str += Formatting::AddLeading(Convert::DoubleToPercent((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
					}
					else
					{
						str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
					}

					//      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails.RootFolders[t].Attributes);

					data->push_back(str + L"\n");
				}
			}
		}

		data->push_back(GLanguageHandler->TextReport[0] + L"\n\n");
	}
}


void ReportText::ReportFileDates(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock5Row(data, 20, 21);

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		if (GScanEngine->Data[DataSource].FileDates.size() != 0)
		{
			for (FileDateObject *fdo : GScanEngine->Data[DataSource].FileDates)
			{
				if (fdo->Count != 0)
				{
					std::wstring str = Formatting::AddTrailing(L' ' + std::to_wstring(fdo->Year), TRDescriptionWidth, L' ') +
						Formatting::AddLeading(std::to_wstring(fdo->Count), TRQuantityWidth, L' ') + L"  " +
						Formatting::AddLeading(Convert::DoubleToPercent((double)fdo->Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
						Formatting::AddLeading(Convert::ConvertToUsefulUnit(fdo->Size), TRSizeWidth, L' ') + L"  ";

					if (GScanEngine->Data[DataSource].TotalSize != 0)
					{
						str += Formatting::AddLeading(Convert::DoubleToPercent((double)fdo->Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
					}
					else
					{
						str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
					}

					data->push_back(str + L"\n");
				}
			}
		}
	}

	data->push_back(GLanguageHandler->TextReport[0] + L"\n\n");
}


void ReportText::ReportMagnitude(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock5Row(data, 7, 2);

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		for (int t = 0; t < kMagnitudesCount; t++)
		{
			std::wstring str = Formatting::AddTrailing(L' ' + kMagnitudeLabelsShort[t], TRDescriptionWidth, L' ') +
				Formatting::AddLeading(std::to_wstring(GScanEngine->Data[DataSource].Magnitude[t].Count), TRQuantityWidth, L' ') + L"  " +
				Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].Magnitude[t].Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
				Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].Magnitude[t].Size), TRSizeWidth, L' ') + L"  ";

			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].Magnitude[t].Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
			}
			else
			{
				str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
			}

			data->push_back(str + L"\n");
		}
	}

	data->push_back(GLanguageHandler->Text[kFavourite] + L"\n\n");
}


void ReportText::ReportExtensions(std::vector<std::wstring> *data, TextReportOptions report, int DataSource)
{
	TitleBlock3Row(data, 8);

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		for (int t = 1; t < kFileCategoriesCount; t++)
		{
			if (report.CategoryList[t])
			{
				data->push_back(GLanguageHandler->TextReport[2] + L"\n");

				std::wstring str  = Formatting::AddTrailing(L' ' + GLanguageHandler->TypeDescriptions[t], TRDescriptionWidth, L' ') +
									Formatting::AddLeading(std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count), TRQuantityWidth, L' ') + L"  " +
									Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
									Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size), TRSizeWidth, L' ') + L"  ";

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				data->push_back(str + L"\n");
				data->push_back(L"---------------------------------------------------------------------------------\n");

				if (t != kFileCategoriesOther)
				{
					for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
					{
						FileExtension *tfx = GFileExtensionHandler->Extensions[z];

						if (tfx->Category == t)
						{
							//only include within report if number of files in extension > 0
							if (tfx->Count > 0)
							{
								std::wstring str  = Formatting::AddTrailing(L' ' + tfx->Name, TRDescriptionWidth, L' ') +
													Formatting::AddLeading(std::to_wstring(tfx->Count), TRQuantityWidth, ' ') + L"  " +
													Formatting::AddLeading(Convert::DoubleToPercent((double)tfx->Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, ' ') + L"  " +
													Formatting::AddLeading(Convert::ConvertToUsefulUnit(tfx->Size), TRSizeWidth, L' ') + L"  ";

								if (GScanEngine->Data[DataSource].TotalSize != 0)
								{
									str += Formatting::AddLeading(Convert::DoubleToPercent((double)tfx->Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
								}
								else
								{
									str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
								}

								data->push_back(str + L"\n");
							}
						}
					}
				}
				else
				{
					for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
					{
						if (GFileExtensionHandler->Extensions[z]->Category == kCategory_Other)
						{
							std::wstring str  = Formatting::AddTrailing(L' ' + GFileExtensionHandler->Extensions[z]->Name, TRDescriptionWidth, L' ') +
												Formatting::AddLeading(std::to_wstring(GFileExtensionHandler->Extensions[z]->Count), TRQuantityWidth, L' ') + L"  " +
												Formatting::AddLeading(Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
												Formatting::AddLeading(Convert::ConvertToUsefulUnit(GFileExtensionHandler->Extensions[z]->Size), TRSizeWidth, L' ') + L"  ";

							if (GScanEngine->Data[DataSource].TotalSize != 0)
							{
								str += Formatting::AddLeading(Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z]->Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
							}
							else
							{
								str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
							}

							data->push_back(str + L"\n");
						}
					}
				}

				data->push_back(L"\n");
			}
		}
	}
}


void ReportText::ReportNullFiles(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock3Row(data, 9);

	if (GScanEngine->Data[DataSource].NullFiles.size() != 0)
	{
		for (int t = 0; t < GScanEngine->Data[DataSource].NullFiles.size(); t++)
		{
			data->push_back(GScanEngine->Data[DataSource].NullFiles[t] + L"\n");
		}
	}
	else
	{
		data->push_back(GLanguageHandler->Text[kNoneFound] + L"\n");
	}

	data->push_back(L"\n");

	TitleBlock3Row(data, 10);

	if (GScanEngine->Data[DataSource].NullFolders.size() != 0)
	{
		for (int t = 0; t < GScanEngine->Data[DataSource].NullFolders.size(); t++)
		{
			data->push_back(GScanEngine->Data[DataSource].NullFolders[t] + L"\n");
		}
	}
	else
	{
		data->push_back(GLanguageHandler->Text[kNoneFound] + L"\n");
	}

	data->push_back(L"\n");
}


void ReportText::ReportTemporaryFiles(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock3Row(data, 19);

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		if (GScanEngine->Data[DataSource].TemporaryFiles.size() != 0)
		{
			for (int t = 0; t < GScanEngine->Data[DataSource].TemporaryFiles.size(); t++)
			{
				data->push_back(GScanEngine->Data[DataSource].TemporaryFiles[t] + L"\n");
			}
		}
		else
		{
			data->push_back(GLanguageHandler->Text[kNoneFound] + L"\n");
		}
	}

	data->push_back(L"\n");
}


void ReportText::ReportUsers(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock5Row(data, 11, 12);

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		for (UserData *user : GScanEngine->Data[DataSource].Users)
		{
			std::wstring str  = Formatting::AddTrailing(L' ' + user->Name, TRDescriptionWidth, L' ') +
								Formatting::AddLeading(std::to_wstring(user->Count), TRQuantityWidth, L' ') + L"  " +
								Formatting::AddLeading(Convert::DoubleToPercent((double)user->Count / (double)GScanEngine->Data[DataSource].FileCount), TRAsPercentWidth, L' ') + L"  " +
								Formatting::AddLeading(Convert::ConvertToUsefulUnit(user->Size), TRSizeWidth, L' ') + L"  ";

			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				str += Formatting::AddLeading(Convert::DoubleToPercent((double)user->Size / (double)GScanEngine->Data[DataSource].TotalSize), TRAsPercentWidth, L' ');
			}
			else
			{
				str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
			}

			data->push_back(str + L"\n");
		}
	}

	data->push_back(GLanguageHandler->TextReport[0] + L"\n");
	data->push_back(L"\n");
}


void ReportText::ReportLargestFiles(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock3Row(data, 13);

	for (FileObject *file : GScanEngine->Data[DataSource].Top100Large)
	{
		data->push_back(Formatting::AddLeading(Convert::IntDateToString(file->DateCreated), 9, L' ') + L" " +
				Formatting::AddLeading(Convert::ConvertToUsefulUnit(file->Size), 14, L' ') + L" " +
				GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
	}

	data->push_back(L"\n");
}


void ReportText::ReportSmallestFiles(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock3Row(data, 14);

	for (FileObject *file : GScanEngine->Data[DataSource].Top100Large)
	{
		data->push_back(Formatting::AddLeading(Convert::IntDateToString(file->DateCreated), 9, ' ') + L" " +
				Formatting::AddLeading(Convert::ConvertToUsefulUnit(file->Size), 14, ' ') + L" " +
				GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
	}

	data->push_back(L"\n");
}


void ReportText::ReportNewestFiles(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock3Row(data, 15);

	for (FileObject *file : GScanEngine->Data[DataSource].Top100Newest)
	{
		data->push_back(Formatting::AddLeading(Convert::IntDateToString(file->DateCreated), 9, ' ') + L" " +
			Formatting::AddLeading(Convert::ConvertToUsefulUnit(file->Size), 14, ' ') + L" " +
			GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
	}

	data->push_back(L"\n");
}


void ReportText::ReportOldestFiles(std::vector<std::wstring> *data, int DataSource)
{
	TitleBlock3Row(data, 16);

	for (FileObject *file : GScanEngine->Data[DataSource].Top100Oldest)
	{
		data->push_back(Formatting::AddLeading(Convert::IntDateToString(file->DateCreated), 9, ' ') + L" " +
			Formatting::AddLeading(Convert::ConvertToUsefulUnit(file->Size), 14, ' ') + L" " +
			GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
	}

	data->push_back(L"\n");
}


void ReportText::TitleBlock5Row(std::vector<std::wstring> *data, int language_id_1, int language_id_2)
{
	data->push_back(GLanguageHandler->TextReport[0] + L"\n");
	data->push_back(GLanguageHandler->TextReport[language_id_1] + L"\n");
	data->push_back(GLanguageHandler->TextReport[0] + L"\n");
	data->push_back(GLanguageHandler->TextReport[language_id_2] + L"\n");
	data->push_back(GLanguageHandler->TextReport[0] + L"\n");
}


void ReportText::TitleBlock3Row(std::vector<std::wstring> *data, int language_id)
{
	data->push_back(GLanguageHandler->TextReport[0] + L"\n");
	data->push_back(GLanguageHandler->TextReport[language_id] + L"\n");
	data->push_back(GLanguageHandler->TextReport[0] + L"\n");
}


void ReportText::SearchResults(std::vector<std::wstring> *data, int DataSource, const std::wstring path)
{
	int a = GLanguageHandler->Text[kPath].size();
	int b = GLanguageHandler->Text[kSearch].size();
	int c = GLanguageHandler->Text[kFound].size();

	int w = std::max(std::max(a, b), c);   // find the largest of the three texts

	data->push_back(L"// Xinorbis 10.0 - " + GLanguageHandler->Text[kSearchResults]);
	data->push_back(L"//");

	if (DataSource == kDataScan || DataSource == kDataSearch)
	{
		data->push_back(L"// " + GLanguageHandler->Text[kPath] + Formatting::StringOfChars(w - a, L' ') + L" : " + GScanEngine->Data[DataSource].Path.String);
	}
	else
	{
		data->push_back(L"// " + GLanguageHandler->Text[kPath] + Formatting::StringOfChars(w - a, L' ') + L" : " + GScanEngine->Data[DataSource].Path.String + L" (DB " + GLanguageHandler->Text[kTable] + L" " + GScanEngine->Data[DataSource].ScanTable + L")");
	}

	data->push_back(L"// " + GLanguageHandler->Text[kSearch] + Formatting::StringOfChars(w - b, L' ') + L" : " + path);
	data->push_back(L"// " + GLanguageHandler->Text[kFound]  + Formatting::StringOfChars(w - c, L' ') + L" : " + std::to_wstring(GScanEngine->Data[DataSource].Files.size()));
	data->push_back(L"");

	data->push_back(GLanguageHandler->Text[kFilePath] + L" " +
				    L" [" +  GLanguageHandler->Text[kSize] + L"] " +
					GLanguageHandler->Text[kFileOwner] +  L" :: " +
					GLanguageHandler->Text[kAttr]);

	data->push_back(L"");

	for (FileObject *file : GScanEngine->Data[DataSource].Files)
	{
		data->push_back(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name +
						L"  [" + Convert::ConvertToUsefulUnit(file->Size) + L"] " +
						GScanEngine->Data[DataSource].Users[file->Owner]->Name + L" :: " +
						Formatting::GetAttributeAsString(file->Attributes));
	}
}
