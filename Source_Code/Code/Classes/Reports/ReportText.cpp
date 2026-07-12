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
#include <fstream>
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


namespace ReportText
{
	void FullList(TextReportOptions options)
	{
		std::ofstream ofile(options.FileName);

		if (ofile)
		{
			//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (Text):\n";
			//GLog->Add( L"    " << options.FileName << "\n\n";

			for (int t = 0; t < __TextReportOptionsCount; t++)
			{
				if (options.Layout[t])
				{
					switch (t)
					{
						case 0:
							ReportHeader(ofile);
							ReportSummary(ofile);
							break;
						case 1:
							ReportAttributes(ofile);
							break;
						case 2:
							ReportCategories(ofile);
							break;
						case 3:
							ReportDirectoryList(ofile);
							break;
						case 4:
							ReportMagnitude(ofile);
							break;
						case 5:
							ReportExtensions(ofile, options);
							break;
						case 6:
							ReportNullFiles(ofile);
							break;
						case 7:
							ReportTemporaryFiles(ofile);
							break;
						case 8:
							ReportLargestFiles(ofile);
							ReportSmallestFiles(ofile);
							ReportNewestFiles(ofile);
							ReportOldestFiles(ofile);
							break;
						case 9:
							ReportUsers(ofile);
							break;
						case 10:
							ReportFileDates(ofile);
							break;
					}
				}
			}

			if (options.DeepScan)
			{
				CreateDeepReport(ofile);
			}

			ofile << "\n";
			ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
			ofile << Formatting::to_utf8(L"======================= FolderScanUltra Text Report = (c) Paul A Freshney " + Utility::CurrentYear() + L" ==\n");
		}
		else
		{
			//GLog->Add( GLanguageHandler->Text[kErrorSaving] + L" (Text):\n";
			//GLog->Add( L"    " << options.FileName << "\n\n";
		}
	}


	void CreateDeepReport(std::ofstream& ofile)
	{
		ReportDeep deep;

		int anchor = 50;

		for (int r = 0; r < GScanEngine->Data.RootFolders.size(); r++)
		{
			std::wstring folder = GScanEngine->Path.String;

			if (!GScanEngine->Data.RootFolders[r].FilesInRoot)
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
					TitleBlock5Row(ofile, 5, 6);
					ofile << Formatting::to_utf8(folder + L"\n\n");

					if (GScanEngine->Data.FileCount != 0)
					{
						for (int s = 0; s < deep.FolderData.size(); s++)
						{
							std::wstring str = Formatting::AddTrailing(L' ' + deep.FolderData[s].Folder, TRDescriptionWidth, L' ') +
								Formatting::AddLeading(std::to_wstring(deep.FolderData[s].FileCount), TRQuantityWidth, L' ') + L"  " +
								Formatting::AddLeading(Convert::DoubleToPercent((double)deep.FolderData[s].FileCount / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
								Formatting::AddLeading(Convert::ConvertToUsefulUnit(deep.FolderData[s].Size), TRSizeWidth, L' ');

							if (GScanEngine->Data.TotalSize != 0)
							{
								str += Formatting::AddLeading(Convert::DoubleToPercent((double)deep.FolderData[s].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
							}
							else
							{
								str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
							}

							//      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails.RootFolders[t].Attributes);

							ofile << Formatting::to_utf8(str + L"\n");
						}					
					}
					else
					{
						ofile << "No data\n";
					}

					ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n\n");

					anchor++;
				}
			}
			else
			{
				//GLog->Add( " Error: cannot find folder \"" << folder << "\"\n";
			}
		}
	}


	void ReportHeader(std::ofstream &ofile)
	{
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
		ofile << Formatting::to_utf8(L"--------------------------------------------------------------------------------\n");
		ofile << Formatting::to_utf8(L"-- FolderScanUltra -------------------------------------------------------------\n");
		ofile << Formatting::to_utf8(L"--------------------------------------------------------------------------------\n");
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
		ofile << Formatting::to_utf8(L"\n");
	}


	void ReportSummary(std::ofstream &ofile)
	{
		ofile << Formatting::to_utf8(GLanguageHandler->SummaryReport[0] + L" \"" + GScanEngine->Path.String + L"\"\n");

		if (GScanEngine->FilterCategory != -1)
		{
			ofile << Formatting::to_utf8(L"                  (filtered by category \"" + __FileExtensionFileName[GScanEngine->FilterCategory] + L"\")\n");
		}

		if (GScanEngine->Data.Source == ScanSource::CSVImport)
		{
			ofile << Formatting::to_utf8(L"                  (from CSV import \"" + GScanEngine->Path.CSVSource + L"\")\n");
		}

		ofile << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->SummaryReport[0].size() + 1, L' ') + Utility::GetDate(DateTimeFormat::Display) + L", " + Utility::GetTime(DateTimeFormat::Display) + L"\n\n");
		ofile << Formatting::to_utf8(GLanguageHandler->SummaryReport[1] + L" " + std::to_wstring(GScanEngine->Data.FileCount) + L"\n");
		ofile << Formatting::to_utf8(GLanguageHandler->SummaryReport[2] + L" " + std::to_wstring(GScanEngine->Data.FolderCount) + L"\n");
		ofile << Formatting::to_utf8(GLanguageHandler->SummaryReport[3] + L" " + Convert::ConvertToUsefulUnit(GScanEngine->Data.TotalSize) + L"\n\n");
		ofile << Formatting::to_utf8(GLanguageHandler->DriveReport[0]   + L" " + WindowsUtility::GetDiskTypeString(GScanEngine->GetDrive()) + L"\n");
		
		DriveDetails dd = WindowsUtility::GetDriveDetails(GScanEngine->GetDrive());

		if (dd.Valid)
		{
			ofile << "\n";

			ofile << Formatting::to_utf8(GLanguageHandler->DriveReport[1] + L" " + dd.FileSystem + L"\n");
			ofile << Formatting::to_utf8(GLanguageHandler->DriveReport[5] + L" " + std::to_wstring(dd.SectorsPerCluster) + L"\n");
			ofile << Formatting::to_utf8(GLanguageHandler->DriveReport[6] + L" " + std::to_wstring(dd.BytesPerSector) + L"\n");
			ofile << Formatting::to_utf8(GLanguageHandler->DriveReport[7] + L" " + std::to_wstring(dd.FreeClusters) + L"\n");
			ofile << Formatting::to_utf8(GLanguageHandler->DriveReport[8] + L" " + std::to_wstring(dd.Clusters) + L"\n");
			ofile << Formatting::to_utf8(GLanguageHandler->DriveReport[9] + L" " + dd.VolumeName + L"\n");
			ofile << Formatting::to_utf8(GLanguageHandler->DriveReport[10] + L" " + dd.SerialNumber + L" (" + dd.SerialNumberHex + L")\n");
		}

		ofile << "\n";

		if (GScanEngine->Data.FileCount != 0)
		{
			ofile << Formatting::to_utf8(GLanguageHandler->SummaryReport[8] + L" " + Convert::ConvertToUsefulUnit(GScanEngine->Data.AverageFileSize) + L"\n");
		}

		if (GScanEngine->Data.FolderCount != 0)
		{
			ofile << Formatting::to_utf8(GLanguageHandler->SummaryReport[9] + L" " + std::to_wstring(GScanEngine->Data.AverageFilesPerFolder) + L"\n");
		}

		ofile << "\n";

		if (GScanEngine->Path.ExcludeFolders)
		{
			for (int t = 0; t < GScanEngine->ExcludeCount(); t++)
			{
				ofile << Formatting::to_utf8(GLanguageHandler->SummaryReport[15] + L" " + GScanEngine->GetExcludeItem(t) + L"\n");
			}

			ofile << "\n";
			ofile << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->SummaryReport[15].size(), L' ') + L" Excluded " + std::to_wstring(GScanEngine->Path.ExcludedFolderCount) + L" folders.\n");
			ofile << "\n";
		}
	}


	void ReportAttributes(std::ofstream &ofile)
	{
		TitleBlock5Row(ofile, 3, 4);

		if (GScanEngine->Data.FileCount != 0)
		{
			for (int t = 0; t < __AttributesToDisplayCount; t++)
			{
				std::wstring str =	Formatting::AddTrailing(L" " + GLanguageHandler->LanguageTypes[t], TRDescriptionWidth, L' ') +
									Formatting::AddLeading(std::to_wstring(GScanEngine->Data.FileAttributes[t].Count), TRQuantityWidth, L' ') + L"  " +
									Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.FileAttributes[t].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, ' ') + L"  " +
									Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.FileAttributes[t].Size), TRSizeWidth, ' ') + L"  ";

				if (GScanEngine->Data.TotalSize != 0)
				{	
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.FileAttributes[t].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, ' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				ofile << Formatting::to_utf8(str + L"\n");
			}
		}

		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n\n");
	}


	void ReportCategories(std::ofstream &ofile)
	{
		TitleBlock5Row(ofile, 1, 2);

		if (GScanEngine->Data.FileCount != 0)
		{
			for (int t = 0; t < __FileCategoriesCount; t++)
			{
				std::wstring str = Formatting::AddTrailing(L" " + GLanguageHandler->TypeDescriptions[t], TRDescriptionWidth, L' ') +
					Formatting::AddLeading(std::to_wstring(GScanEngine->Data.ExtensionSpread[t].Count), TRQuantityWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[t].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.ExtensionSpread[t].Size), TRSizeWidth, L' ');

				if (GScanEngine->Data.TotalSize != 0)
				{
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[t].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				ofile << Formatting::to_utf8(str + L"\n");
			}

			ofile << "\n";
			
			std::wstring str = Formatting::AddTrailing(L' ' + GLanguageHandler->Text[kTemporary], TRDescriptionWidth, L' ') +
							   Formatting::AddLeading(std::to_wstring(GScanEngine->Data.ExtensionSpread[0].Count), TRQuantityWidth, L' ') + L"  " +
							   Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[0].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
							   Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.ExtensionSpread[0].Size), TRSizeWidth, L' ') + L"  ";

			if (GScanEngine->Data.TotalSize != 0)
			{
				str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[0].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
			}
			else
			{
				str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
			}

			ofile << Formatting::to_utf8(str + L"\n");

			ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n\n");
		}
	}


	void ReportDirectoryList(std::ofstream &ofile)
	{
		TitleBlock5Row(ofile, 5, 6);

		if (GScanEngine->Data.FileCount != 0)
		{
// to do			std::ranges::sort(GScanEngine->Data.RootFolders, {}, &RootFolder::Size);

			if (GScanEngine->Data.RootFolders.size() != 0)
			{
				for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
				{
					std::wstring str = Formatting::AddTrailing(L' ' + GScanEngine->Data.RootFolders[t].Name, TRDescriptionWidth, L' ') +
									   Formatting::AddLeading(std::to_wstring(GScanEngine->Data.RootFolders[t].Count), TRQuantityWidth, L' ') + L"  " +
									   Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.RootFolders[t].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
									   Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.RootFolders[t].Size), TRSizeWidth, L' ');

					if (GScanEngine->Data.TotalSize != 0)
					{
						str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
					}
					else
					{
						str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
					}

					//      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails.RootFolders[t].Attributes);

					ofile << Formatting::to_utf8(str + L"\n");
				}
			}
		}

		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n\n");

		TitleBlock5Row(ofile, 5, 6);

		if (GScanEngine->Data.FileCount != 0)
		{
// to do			std::ranges::sort(GScanEngine->Data.RootFolders, {}, &RootFolder::Count);

			if (GScanEngine->Data.RootFolders.size() != 0)
			{
				for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
				{
					std::wstring str = Formatting::AddTrailing(L' ' + GScanEngine->Data.RootFolders[t].Name, TRDescriptionWidth, L' ') +
						Formatting::AddLeading(std::to_wstring(GScanEngine->Data.RootFolders[t].Count), TRQuantityWidth, L' ') + L"  " +
						Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.RootFolders[t].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
						Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.RootFolders[t].Size), TRSizeWidth, L' ');

					if (GScanEngine->Data.TotalSize != 0)
					{
						str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
					}
					else
					{
						str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
					}

					//      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails.RootFolders[t].Attributes);

					ofile << Formatting::to_utf8(str + L"\n");
				}
			}
		}

		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n\n");

		// ========================================================================================================
		// only show alphabetical table if there are enough entries to make it worth while
		// ========================================================================================================

		if (GScanEngine->Data.RootFolders.size() > 20)
		{
			TitleBlock5Row(ofile, 5, 6);

			if (GScanEngine->Data.FileCount != 0)
			{
// to do				std::ranges::sort(GScanEngine->Data.RootFolders, {}, &RootFolder::Name);

				if (GScanEngine->Data.RootFolders.size() != 0)
				{
					for (int t = 0; t < GScanEngine->Data.RootFolders.size(); t++)
					{
						std::wstring str = Formatting::AddTrailing(L' ' + GScanEngine->Data.RootFolders[t].Name, TRDescriptionWidth, L' ') +
							Formatting::AddLeading(std::to_wstring(GScanEngine->Data.RootFolders[t].Count), TRQuantityWidth, L' ') + L"  " +
							Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.RootFolders[t].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
							Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.RootFolders[t].Size), TRSizeWidth, L' ');

						if (GScanEngine->Data.TotalSize != 0)
						{
							str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.RootFolders[t].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
						}
						else
						{
							str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
						}

						//      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails.RootFolders[t].Attributes);

						ofile << Formatting::to_utf8(str + L"\n");
					}
				}
			}

			ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n\n");
		}
	}


	void ReportFileDates(std::ofstream &ofile)
	{
		TitleBlock5Row(ofile, 20, 21);

		if (GScanEngine->Data.FileCount != 0)
		{
			if (GScanEngine->Data.FileDates.size() != 0)
			{
				for (int t = 0; t < GScanEngine->Data.FileDates.size(); t++)
				{
					if (GScanEngine->Data.FileDates[t].Count != 0)
					{
						std::wstring str = Formatting::AddTrailing(L' ' + std::to_wstring(GScanEngine->Data.FileDates[t].Year), TRDescriptionWidth, L' ') +
							Formatting::AddLeading(std::to_wstring(GScanEngine->Data.FileDates[t].Count), TRQuantityWidth, L' ') + L"  " +
							Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.FileDates[t].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
							Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.FileDates[t].Size), TRSizeWidth, L' ') + L"  ";

						if (GScanEngine->Data.TotalSize != 0)
						{
							str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.FileDates[t].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
						}
						else
						{
							str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
						}

						ofile << Formatting::to_utf8(str + L"\n");
					}
				}
			}
		}

		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n\n");
	}

	
	void ReportMagnitude(std::ofstream &ofile)
	{
		TitleBlock5Row(ofile, 7, 2);

		if (GScanEngine->Data.FileCount != 0)
		{
			for (int t = 0; t < __MagnitudesCount; t++)
			{
				std::wstring str = Formatting::AddTrailing(L' ' + __MagnitudeLabelsShort[t], TRDescriptionWidth, L' ') +
					Formatting::AddLeading(std::to_wstring(GScanEngine->Data.Magnitude[t].Count), TRQuantityWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.Magnitude[t].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.Magnitude[t].Size), TRSizeWidth, L' ') + L"  ";

				if (GScanEngine->Data.TotalSize != 0)
				{
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.Magnitude[t].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				ofile << Formatting::to_utf8(str + L"\n");
			}
		}

		ofile << Formatting::to_utf8(GLanguageHandler->Text[kFavourite] + L"\n\n");
	}


	void ReportExtensions(std::ofstream &ofile, TextReportOptions options)
	{
		TitleBlock3Row(ofile, 8);

		if (GScanEngine->Data.FileCount != 0)
		{
			for (int t = 1; t < __FileCategoriesCount; t++)
			{
				if (options.CategoryList[t])
				{
					ofile << Formatting::to_utf8(GLanguageHandler->TextReport[2] + L"\n");

					std::wstring str  = Formatting::AddTrailing(L' ' + GLanguageHandler->TypeDescriptions[t], TRDescriptionWidth, L' ') +
										Formatting::AddLeading(std::to_wstring(GScanEngine->Data.ExtensionSpread[t].Count), TRQuantityWidth, L' ') + L"  " +
										Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[t].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
										Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.ExtensionSpread[t].Size), TRSizeWidth, L' ') + L"  ";

					if (GScanEngine->Data.TotalSize != 0)
					{
						str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.ExtensionSpread[t].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
					}
					else
					{
						str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
					}

					ofile << Formatting::to_utf8(str + L"\n");
					ofile << Formatting::to_utf8(L"---------------------------------------------------------------------------------\n");
					                               
					if (t != __FileCategoriesOther)
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
														Formatting::AddLeading(Convert::DoubleToPercent((double)tfx->Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, ' ') + L"  " +
														Formatting::AddLeading(Convert::ConvertToUsefulUnit(tfx->Size), TRSizeWidth, L' ') + L"  ";

									if (GScanEngine->Data.TotalSize != 0)
									{
										str += Formatting::AddLeading(Convert::DoubleToPercent((double)tfx->Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
									}
									else
									{
										str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
									}

									ofile << Formatting::to_utf8(str + L"\n");
								}
							}
						}
					}
					else
					{
						for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
						{
							if (GFileExtensionHandler->Extensions[z]->Category == __Category_Other)
							{
								std::wstring str  = Formatting::AddTrailing(L' ' + GFileExtensionHandler->Extensions[z]->Name, TRDescriptionWidth, L' ') +
													Formatting::AddLeading(std::to_wstring(GFileExtensionHandler->Extensions[z]->Count), TRQuantityWidth, L' ') + L"  " +
													Formatting::AddLeading(Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z]->Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
													Formatting::AddLeading(Convert::ConvertToUsefulUnit(GFileExtensionHandler->Extensions[z]->Size), TRSizeWidth, L' ') + L"  ";

								if (GScanEngine->Data.TotalSize != 0)
								{
									str += Formatting::AddLeading(Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z]->Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
								}
								else
								{
									str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
								}

								ofile << Formatting::to_utf8(str + L"\n");
							}
						}
					}

					ofile << "\n";
				}
			}
		}
	}


	void ReportNullFiles(std::ofstream &ofile)
	{
		TitleBlock3Row(ofile, 9);

		if (GScanEngine->Data.NullFiles.size() != 0)
		{
			for (int t = 0; t < GScanEngine->Data.NullFiles.size(); t++)
			{
				ofile << Formatting::to_utf8(GScanEngine->Data.NullFiles[t] + L"\n");
			}
		}
		else
		{
			ofile << Formatting::to_utf8(GLanguageHandler->Text[kNoneFound] + L"\n");
		}

		ofile << "\n";

		TitleBlock3Row(ofile, 10);

		if (GScanEngine->Data.NullFolders.size() != 0)
		{
			for (int t = 0; t < GScanEngine->Data.NullFolders.size(); t++)
			{
				ofile << Formatting::to_utf8(GScanEngine->Data.NullFolders[t] + L"\n");
			}
		}
		else
		{
			ofile << Formatting::to_utf8(GLanguageHandler->Text[kNoneFound] + L"\n");
		}

		ofile << "\n";
	}


	void ReportTemporaryFiles(std::ofstream& ofile)
	{
		TitleBlock3Row(ofile, 19);

		if (GScanEngine->Data.FileCount != 0)
		{
			if (GScanEngine->Data.TemporaryFiles.size() != 0)
			{
				for (int t = 0; t < GScanEngine->Data.TemporaryFiles.size(); t++)
				{
					ofile << Formatting::to_utf8(GScanEngine->Data.TemporaryFiles[t] + L"\n");
				}
			}
			else
			{
				ofile << Formatting::to_utf8(GLanguageHandler->Text[kNoneFound] + L"\n");
			}
		}

		ofile << "\n";
	}


	void ReportUsers(std::ofstream &ofile)
	{
		TitleBlock5Row(ofile, 11, 12);

		if (GScanEngine->Data.FileCount != 0)
		{
			for (int t = 0; t < GScanEngine->Data.Users.size(); t++)
			{
				std::wstring str  = Formatting::AddTrailing(L' ' + GScanEngine->Data.Users[t].Name, TRDescriptionWidth, L' ') +
									Formatting::AddLeading(std::to_wstring(GScanEngine->Data.Users[t].Count), TRQuantityWidth, L' ') + L"  " +
									Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.Users[t].Count / (double)GScanEngine->Data.FileCount), TRAsPercentWidth, L' ') + L"  " +
									Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.Users[t].Size), TRSizeWidth, L' ') + L"  ";

				if (GScanEngine->Data.TotalSize != 0)
				{
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanEngine->Data.Users[t].Size / (double)GScanEngine->Data.TotalSize), TRAsPercentWidth, L' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				ofile << Formatting::to_utf8(str + L"\n");
			}
		}

		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
		ofile << Formatting::to_utf8(L"\n");
	}

	
	void ReportLargestFiles(std::ofstream &ofile)
	{
		TitleBlock3Row(ofile, 13);

		for (int t = 0; t < GScanEngine->Data.Top100Large.size(); t++)
		{
			ofile << Formatting::to_utf8(Formatting::AddLeading(Convert::IntDateToString(GScanEngine->Data.Top100Large[t].DateCreated), 9, L' ') + L" " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.Top100Large[t].Size), 14, L' ') + L" " +
					GScanEngine->Data.Folders[GScanEngine->Data.Top100Large[t].FilePathIndex] + GScanEngine->Data.Top100Large[t].Name + L"\n");
		}

		ofile << "\n";
	}


	void ReportSmallestFiles(std::ofstream &ofile)
	{
		TitleBlock3Row(ofile, 14);

		for (int t = 0; t < GScanEngine->Data.Top100Large.size(); t++)
		{
			ofile << Formatting::to_utf8(Formatting::AddLeading(Convert::IntDateToString(GScanEngine->Data.Top100Small[t].DateCreated), 9, ' ') + L" " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.Top100Small[t].Size), 14, ' ') + L" " +
					GScanEngine->Data.Folders[GScanEngine->Data.Top100Small[t].FilePathIndex] + GScanEngine->Data.Top100Small[t].Name + L"\n");
		}

		ofile << "\n";
	}


	void ReportNewestFiles(std::ofstream &ofile)
	{
		TitleBlock3Row(ofile, 15);

		for (int t = 0; t < GScanEngine->Data.Top100Newest.size(); t++)
		{
			ofile << Formatting::to_utf8(Formatting::AddLeading(Convert::IntDateToString(GScanEngine->Data.Top100Newest[t].DateCreated), 9, ' ') + L" " +
				Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.Top100Newest[t].Size), 14, ' ') + L" " +
				GScanEngine->Data.Folders[GScanEngine->Data.Top100Newest[t].FilePathIndex] + GScanEngine->Data.Top100Newest[t].Name + L"\n");
		}

		ofile << "\n";
	}


	void ReportOldestFiles(std::ofstream &ofile)
	{
		TitleBlock3Row(ofile, 16);

		for (int t = 0; t < GScanEngine->Data.Top100Oldest.size(); t++)
		{
			ofile << Formatting::to_utf8(Formatting::AddLeading(Convert::IntDateToString(GScanEngine->Data.Top100Oldest[t].DateCreated), 9, ' ') + L" " +
				Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.Top100Oldest[t].Size), 14, ' ') + L" " +
				GScanEngine->Data.Folders[GScanEngine->Data.Top100Oldest[t].FilePathIndex] + GScanEngine->Data.Top100Oldest[t].Name + L"\n");
		}

		ofile << "\n";
	}


	void TitleBlock5Row(std::ofstream& ofile, int language_id_1, int language_id_2)
	{
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[language_id_1] + L"\n");
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[language_id_2] + L"\n");
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
	}


	void TitleBlock3Row(std::ofstream& ofile, int language_id)
	{
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[language_id] + L"\n");
		ofile << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
	}
}