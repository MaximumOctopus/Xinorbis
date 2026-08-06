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

#include <iomanip>
#include <string>

#include "XFormXinorbisDialog.h"

#include "Convert.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportSummary.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "Utility.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;


	// this is the output you get with only a folder name is specified when running the application
void ReportSummary::Generate(const std::wstring file_name, int DataSource,
	TStringGrid *gridNullFiles, TStringGrid *gridNullFolders, TStringGrid *gridFolderList, TStringGrid *gridTop101Big, TStringGrid *gridUsers)
{
//  Assert((aDataIndex >= 0) and (aDataIndex <= 1), "SaveSummary :: invalid dataindex :: " + inttostr(aDataIndex));
	std::ofstream file(file_name);

	if (file)
	{
		std::wstring s = L"";

		for (int t = 0; t < GSettingsHandler->Reports.Summary.Layout.size(); t++)
		{
			if (GSettingsHandler->Reports.Summary.Layout[t] == L':')
			{
				int section_index = stoi(s);

				switch (section_index)
				{
				case 1:
				case 2:
				case 3:
				case 5:
				case 8:
				case 9:
					AddSummaryItem(file, nullptr, nullptr, DataSource, section_index);
					break;
				case 4:
					AddSummaryItem(file, gridNullFiles, gridNullFolders, DataSource, section_index);
					break;
				case 6:
					AddSummaryItem(file, gridFolderList, gridTop101Big, DataSource, section_index);
					break;
				case 7:
					AddSummaryItem(file, gridUsers, nullptr, DataSource, section_index);
					break;
                }

				s = L"";
			}
			else
			{
				s += GSettingsHandler->Reports.Summary.Layout[t];
            }
		}

		file << Formatting::to_utf8(L" =============================================================");

		file.close();

	//  if Assigned(FSetStatusBarText) then
	//	FSetStatusBarText(GLanguageHandler->Text[kSummary] + ": "  + FileName);
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kErrorSaving] + L": " + GLanguageHandler->Text[kSummary],
					GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
					XDialogTypeWarning);
	}
}


void ReportSummary::AddSummaryItem(std::ofstream &file, TStringGrid *grid1, TStringGrid *grid2, int DataSource, int section_index)
{
	switch (section_index)
	{
	case 1:
	{
		file << Formatting::to_utf8(L" =============================================================\n");
		file << Formatting::to_utf8(L"\n");

//		if (GSettingsHandler->LastScanMultiple)
//		{
//			file << Formatting::to_utf8(SummaryReport[0] + L"\"" + GScanEngine->Data[DataSource].MultipleList.Strings[0] + L"\"\n");

//			for (int t = 1 to GScanEngine[aDataIndex].MultipleList.Count - 1)
//			{
//				file << Formatting::to_utf8(Formatting::AddLeading(L"", Length(SummaryReport[0]) - 1, L" ") + L"\"" + GScanEngine->Data[DataSource].MultipleList.Strings[t] + L"\"\n");
//			}
//		}
//		else
//		{
			file << Formatting::to_utf8(GLanguageHandler->SummaryReport[0] + L"\"" + GScanEngine->Data[DataSource].Path.String + L"\"\n");
		//}

		if (GScanEngine->Data[DataSource].Source == ScanSource::FileXinorbisNormal ||
			GScanEngine->Data[DataSource].Source == ScanSource::FileXinorbisDetailed ||
			GScanEngine->Data[DataSource].Source == ScanSource::FileCSV)
		{
			std::wstring file_name = Utility::SplitFileName(GScanEngine->Data[DataSource].Path.FileName);

			file << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->SummaryReportZeroLength - 1, L' ') + GLanguageHandler->Text[kFrom] + L": " + file_name + L"\n");
		}

		file << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->SummaryReportZeroLength - 1, L' ') + Utility::GetDate(DateTimeFormat::Display) + L", " + Utility::GetTime(DateTimeFormat::Display) + L"\n");

		if (DataSource == kDataFolderHistory)
		{
			file << Formatting::to_utf8(L"\n");
			file << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->SummaryReportZeroLength - 1, L' ') + GLanguageHandler->Text[kFolderHistory] + L": " + GScanEngine->Data[DataSource].Path.FileHistoryStr + L"\n");
		}

		file << Formatting::to_utf8(L"\n");

		if (GScanEngine->ExcludedFolders.size() != 0)
		{
			file << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->SummaryReportZeroLength - 1, L' ') + GLanguageHandler->Text[kExcludedFolders] + L";\n");

			for (int t = 0; t < GScanEngine->ExcludedFolders.size(); t++)
			{
				file << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->SummaryReportZeroLength - 1, L' ') + L"\"" + GScanEngine->ExcludedFolders[t] + L"\"\n");
			}

			file << Formatting::to_utf8(L"\n");
		}

		if (GScanEngine->ExcludedFiles.size() != 0)
		{
			file << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->SummaryReportZeroLength - 1, L' ') + GLanguageHandler->Text[kExcludedFiles] + L";\n");

			for (int t = 0; t < GScanEngine->ExcludedFiles.size(); t++)
			{
				file << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->SummaryReportZeroLength - 1, L' ') + L"\"" + GScanEngine->ExcludedFiles[t] + L"\"\n");
			}

			file << Formatting::to_utf8(L"\n");
		}

		file << Formatting::to_utf8(L" =============================================================\n");
		break;
	}
	case 2:
		file << Formatting::to_utf8(GLanguageHandler->SummaryReport[1] + std::to_wstring(GScanEngine->Data[DataSource].FileCount) + L"\n");
		file << Formatting::to_utf8(GLanguageHandler->SummaryReport[2] + std::to_wstring(GScanEngine->Data[DataSource].FolderCount) + L"\n");
		break;
	case 3:
		file << Formatting::to_utf8(GLanguageHandler->SummaryReport[3] + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSize) + L"\n");

		if (GScanEngine->Data[DataSource].DiskStats.DriveSectorSize != 0)
		{
			file << Formatting::to_utf8(GLanguageHandler->SummaryReport[4] + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSizeOD) + L"\n");
			file << Formatting::to_utf8(GLanguageHandler->SummaryReport[5] + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSizeOD - GScanEngine->Data[DataSource].TotalSize) + L"\n");
		}
		break;
	case 4:
		file << Formatting::to_utf8(GLanguageHandler->SummaryReport[6] + std::to_wstring(grid1->RowCount - 1) + L"\n");
		file << Formatting::to_utf8(GLanguageHandler->SummaryReport[7] + std::to_wstring(grid2->RowCount - 1) + L"\n");
		break;
	case 5:  // averages
		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			file << Formatting::to_utf8(GLanguageHandler->SummaryReport[8] + Convert::ConvertToUsefulUnit(std::round(GScanEngine->Data[DataSource].TotalSize / GScanEngine->Data[DataSource].FileCount)) + L"\n");
		}
		else
		{
			file << Formatting::to_utf8(GLanguageHandler->SummaryReport[8] + L"0\n");
		}

		if (GScanEngine->Data[DataSource].FolderCount != 0)
		{
			std::wstring fcpf =  FloatToStrF(GScanEngine->Data[DataSource].FileCount / GScanEngine->Data[DataSource].FolderCount, ffFixed, 7, 2, GSettingsHandler->XinorbisFormat).c_str();

			file << Formatting::to_utf8(GLanguageHandler->SummaryReport[9] + fcpf + L"\n");
		}
		break;
	case 6:
	{
		int z = 1;

		for (int t = 1; t < grid1->RowCount; t++)
		{
			std::wstring s1 = grid1->Cells[8][t].c_str();
			std::wstring s2 = grid1->Cells[8][z].c_str();

			if (stoi(s1) > stoi(s2))
			{
				z = t;
			}
		}

		if (grid1->Cells[1][z] != L"\\")
		{
			std::wstring s1 = grid1->Cells[1][z].c_str();
			std::wstring s2 = grid1->Cells[8][z].c_str();
			std::wstring s3 = grid1->Cells[3][z].c_str();

			file << Formatting::to_utf8(GLanguageHandler->SummaryReport[10] + L"\\" + s1 + L"\\ (L" + Convert::ConvertToUsefulUnit(stoi(s2)) + L", " + s3 + L" of files)\n");
		}
		else
		{
			std::wstring s1 = grid1->Cells[8][z].c_str();
			std::wstring s2 = grid1->Cells[3][z].c_str();

			file << Formatting::to_utf8(GLanguageHandler->SummaryReport[11] + L"(L" + Convert::ConvertToUsefulUnit(stoi(s1)) + L", " + s2 + L" of files)\n");
		}

		std::wstring sa = grid2->Cells[0][1].c_str();
		std::wstring sb = grid2->Cells[1][1].c_str();

		file << Formatting::to_utf8(GLanguageHandler->SummaryReport[12] + sa + L" (L" + sb + L")\n");
		break;
	}
	case 7:
	{
		if (GScanEngine->Data[DataSource].Users.size() != 0)
		{
			int z = 1;

			for (int t = 1; t < grid1->RowCount; t++)
			{
				std::wstring s1 = grid1->Cells[7][t].c_str();
				std::wstring s2 = grid1->Cells[7][z].c_str();

				if (stoi(s1) > stoi(s2))
				{
					z = t;
				}
			}

			std::wstring s1 = grid1->Cells[1][z].c_str();
			std::wstring s2 = grid1->Cells[7][z].c_str();
			std::wstring s3 = grid1->Cells[3][z].c_str();

			file << Formatting::to_utf8(GLanguageHandler->SummaryReport[13] + s1 + L" (L" + Convert::ConvertToUsefulUnit(stoi(s2)) + L", " + s3 + L")\n");
		}
		break;
	}
	case 8:
		file << Formatting::to_utf8(GLanguageHandler->SummaryReport[14] + L"\n");

		for (int t = 1; t < kFileCategoriesCount; t++)
		{
			if (GScanEngine->Data[DataSource].ExtensionSpread[t].Count != 0)
			{
				file << Formatting::to_utf8(Formatting::AddTrailing(L" " + GLanguageHandler->TypeDescriptions[t], 25, L' ') + L": " + Formatting::AddLeading(L" " + std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count), 7, L' ') + L" :: " + Formatting::AddLeading(L" " + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size), 11, L' ') + L"\n");
			}
			else
			{
				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					file << Formatting::to_utf8(Formatting::AddTrailing(L" " + GLanguageHandler->TypeDescriptions[t], 25, L' ') + L": " + Formatting::AddLeading(L" " + std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count), 7, L' ') + L" :: " + Formatting::AddLeading(L" " + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size), 11, L' ') + L"  (L" + Convert::DoubleToPercent(GScanEngine->Data[DataSource].ExtensionSpread[t].Size / GScanEngine->Data[DataSource].TotalSize) + L")\n");
				}
				else
				{
					file << Formatting::to_utf8(Formatting::AddTrailing(L" " + GLanguageHandler->TypeDescriptions[t], 25, L' ') + L": " + Formatting::AddLeading(L" " + std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count), 7, L' ') + L" :: " + Formatting::AddLeading(L" " + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size), 11, L' ') + L"  (100%)\n");
				}
			}
		}
		break;
	case 9:
		if (GScanEngine->Data[DataSource].Source != ScanSource::FileCSV)
		{
			if (GScanEngine->Data[DataSource].Path.String.find(L'\\') == std::wstring::npos)
			{
				file << Formatting::to_utf8(GLanguageHandler->DriveReport[0] + WindowsUtility::GetDiskTypeString(GScanEngine->Data[DataSource].Path.String + L":") + L"\n");

				if (GScanEngine->Data[DataSource].DiskStats.DriveSpaceTotal >= 0)
				{
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[1] + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].DiskStats.DriveSpaceTotal) + L"\n");
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[2] + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].DiskStats.DriveSpaceFree) + L"\n");
				}
				else
				{
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[1] + L"n/a\n");
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[2] + L"n/a\n");
				}

				std::wstring drive = GScanEngine->Data[DataSource].Path.String.substr(0, 2);

				DriveDetails dd = WindowsUtility::GetDriveDetails(drive);

				if (dd.Clusters != 0)
				{
					file << Formatting::to_utf8(L"\n");
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[3] + std::to_wstring(dd.SectorsPerCluster) + L"\n");
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[4] + std::to_wstring(dd.BytesPerSector) + L"\n");
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[5] + std::to_wstring(dd.FreeClusters) + L"\n");
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[6] + std::to_wstring(dd.Clusters) + L"\n");
					file << Formatting::to_utf8(L"\n");
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[7] + dd.VolumeName + L"\n");
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[8] + dd.SerialNumber + L" ($" + dd.SerialNumberHex + L")\n");
					file << Formatting::to_utf8(GLanguageHandler->DriveReport[9] + dd.FileSystem);
				}
			}
			else
			{
				file << Formatting::to_utf8(GLanguageHandler->DriveReport[10] + L"\n");
			}
		}
		break;
	}

	file << Formatting::to_utf8(L"\n");
}
