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

#include "Convert.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportSummary.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "Utility.h"

extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;


	// this is the output you get with only a folder name is specified when running the application
void ReportSummary::Generate(const std::wstring file_name)
{
//  Assert((aDataIndex >= 0) and (aDataIndex <= 1), "SaveSummary :: invalid dataindex :: " + inttostr(aDataIndex));
	std::ofstream file(file_name);

	if (file)
	{
		std::wstring s = L"";

		for (int t = 0; t < GSettingsHandler->Reports.SummaryLayout.size(); t++)
		{
			if (GSettingsHandler->Reports.SummaryLayout[t] == L':')
			{
				AddSummaryItem(file, stoi(s));

				s = L"";
			}
			else
			{
				s += GSettingsHandler->Reports.SummaryLayout[t];
            }
		}

		file << Formatting::to_utf8(L" =============================================================");

		file.close();

	//  if Assigned(FSetStatusBarText) then
	//	FSetStatusBarText(GLanguageHandler->Text[rsSummary] + ": "  + FileName);
	}
	else
	{
	   // to d o	ShowXDialog(GLanguageHandler->Text[kErrorSaving] + L": " + GLanguageHandler->Text[kSummary], GLanguageHandler->Text[kErrorSaving] + L" \"" + filename + L"\".", XDialogTypeWarning);
	}
}


void ReportSummary::AddSummaryItem(std::ofstream &file, int DataSource)
{             /* to do
	switch (index)
	{
	case 1:
	{
		file << Formatting::to_utf8(L" =============================================================\n");
		file << Formatting::to_utf8(L"\n");

		if GSettingsHandler->LastScanMultiple)
		{
			file << Formatting::to_utf8(SummaryReport[0] + L"\"" + GScanEngine->Data[DataSource].MultipleList.Strings[0] + L"\"\n");

			for t := 1 to GScanEngine[aDataIndex].MultipleList.Count - 1)
			{
				file << Formatting::to_utf8(Formatting::AddLeading(L"", Length(SummaryReport[0]) - 1, L" ") + L"\"" + GScanEngine->Data[DataSource].MultipleList.Strings[t] + L"\"\n");
			}
		}
		else
		{
			file << Formatting::to_utf8(SummaryReport[0] + L"\"" + GScanEngine->Data[DataSource].ScanPath + L"\"\n");
		}

		if (GScanEngine->Data[DataSource].ScanSource = ScanSourceFileXinNormal) or
		   (GScanEngine->Data[DataSource].ScanSource = ScanSourceFileXinDetailed) or
		   (GScanEngine->Data[DataSource].ScanSource = ScanSourceFileCSV)
		{
			file << Formatting::to_utf8(Formatting::AddLeading(L"", Length(SummaryReport[0]) - 1, L" ") + GLanguageHandler->Text[rsFrom] + L": " + ExtractFilename(GScanEngine[aDataIndex].Filename) + L"\n");
		}

		file << Formatting::to_utf8(Formatting::AddLeading(L"", Length(SummaryReport[0]) - 1, L" ") + TUtility.GetDate(GETTIMEFORMAT_DISPLAY) + L", " + TUtility.GetTime(GETTIMEFORMAT_DISPLAY) + L"\n");

		if (aDataIndex = dataFolderHistory)
		{
			file << Formatting::to_utf8(L"\n");
			file << Formatting::to_utf8(Formatting::AddLeading(L"", Length(SummaryReport[0]) - 1, L" ") + GLanguageHandler->Text[rsFolderHistory] + L": " + GScanEngine[aDataIndex].ScanDateFHStr + L"\n");
		}

		file << Formatting::to_utf8(L"\n");

		if GSystemGlobal.ExcludedFolders.Count != 0)
		{
			file << Formatting::to_utf8(Formatting::AddLeading(L"", Length(SummaryReport[0]) - 1, L" ") + GLanguageHandler->Text[rsExcludedFolders] + ";\n");

			for t := 0 to GSystemGlobal.ExcludedFolders.Count - 1)
			{
				file << Formatting::to_utf8(Formatting::AddLeading(L"", Length(SummaryReport[0]) - 1, L" ") + L"\"" + GSystemGlobal.ExcludedFolders.Strings[t] + L"\"\n");
			}

			file << Formatting::to_utf8(L"\n");
		}

		if GSystemGlobal.ExcludedFiles.Count != 0)
		{
			file << Formatting::to_utf8(Formatting::AddLeading(L"", Length(SummaryReport[0]) - 1, L" ") + GLanguageHandler->Text[rsExcludedFiles] + L";\n");

			for t := 0 to GSystemGlobal.ExcludedFiles.Count - 1)
			{
				file << Formatting::to_utf8(Formatting::AddLeading(L"", Length(SummaryReport[0]) - 1, " ") + L"\"" + GSystemGlobal.ExcludedFiles.Strings[t] + L"\"\n");
			}

			file << Formatting::to_utf8(L"\n");
		}

		file << Formatting::to_utf8(L" =============================================================\n");
		break;
	}
	case 2:
		file << Formatting::to_utf8(SummaryReport[1] + IntToStr(GScanEngine->Data[DataSource].FileCount) + L"\n");
		file << Formatting::to_utf8(SummaryReport[2] + IntToStr(GScanEngine->Data[DataSource].FolderCount) + L"\n");
		break;
	case 3:
		file << Formatting::to_utf8(SummaryReport[3] + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSize) + L"\n");

		if drivesectorsize != 0)
		{
			file << Formatting::to_utf8(SummaryReport[4] + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSizeOD) + L"\n");
			file << Formatting::to_utf8(SummaryReport[5] + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSizeOD - GScanEngine[aDataIndex].TotalSize) + L"\n");
		}
		break;
	case 4:
		file << Formatting::to_utf8(SummaryReport[6] + IntToStr(FGrids[aDataIndex, CNullFiles].RowCount - 1) + L"\n");
		file << Formatting::to_utf8(SummaryReport[7] + IntToStr(FGrids[aDataIndex, CNullFolders].RowCount - 1) + L"\n");
		break;
	case 5:  // averages
		if GScanEngine[aDataIndex].FileCount != 0)
		{
			file << Formatting::to_utf8(SummaryReport[8] + Convert::ConvertToUsefulUnit(Round(GScanEngine->Data[DataSource].TotalSize / GScanEngine[aDataIndex].FileCount)) + L"\n")
		}
		else
		{
			file << Formatting::to_utf8(SummaryReport[8] + L"0\n");
		}

		if GScanEngine[aDataIndex].FolderCount != 0)
		{
			file << Formatting::to_utf8(SummaryReport[9] + FloatToStrF(GScanEngine[aDataIndex].FileCount / GScanEngine->Data[DataSource].FolderCount, ffFixed, 7, 2, XinorbisFormatSettings) + L"\n");
		}
		break;
	case 6:
	{
		int z = 1;

		for t := 1 to FGrids[aDataIndex, CDirList].RowCount - 1)
		{
			if StrToInt64(FGrids[aDataIndex, CDirList].Cells[8, t]) > StrToInt64(FGrids[aDataIndex, CDirList].Cells[8, z]) then
			{
				z := t;
			}
		}

		if FGrids[aDataIndex, CDirList].Cells[1, z] != L"\\")
		{
			file << Formatting::to_utf8(SummaryReport[10] + L"\\" + FGrids[aDataIndex, CDirList].Cells[1, z] + L"\\ (L" + Convert::ConvertToUsefulUnit(StrToInt64(FGrids[aDataIndex, CDirList].Cells[8, z])) + L", " + FGrids[aDataIndex, CDirList].Cells[3, z] + L" of files)\n")
		}
		else
		{
			file << Formatting::to_utf8(SummaryReport[11] + L"(L" + Convert::ConvertToUsefulUnit(StrToInt64(FGrids[aDataIndex, CDirList].Cells[8, z])) + L", " + FGrids[aDataIndex, CDirList].Cells[3, z] + " of files)\n");
		}

		file << Formatting::to_utf8(SummaryReport[12] + FGrids[aDataIndex, CTop50Big].Cells[0, 1] + L" (L" + FGrids[aDataIndex, CTop50Big].Cells[1, 1] + L")\n");
		break;
	case 7:
	{
		if GScanEngine[aDataIndex].Users.Count != 0)
		{
			int z = 1;

			for t := 1 to FGrids[aDataIndex, CUsers].RowCount - 1)
			{
				if StrToInt64(FGrids[aDataIndex, CUsers].Cells[7, t]) > StrToInt64(FGrids[aDataIndex, CUsers].Cells[7, z])
				{
					z := t;
				}
			}

			file << Formatting::to_utf8(SummaryReport[13] + FGrids[aDataIndex, CUsers].Cells[1, z] + L" (L" + Convert::ConvertToUsefulUnit(StrToInt64(FGrids[aDataIndex, CUsers].Cells[7, z])) + L", " + FGrids[aDataIndex, CUsers].Cells[3, z] + L")\n");
		}
		break;
	}
	case 8 : begin
		file << Formatting::to_utf8(SummaryReport[14] + L"\n");

		for t := 1 to __FileCategoriesCount)
		{
			if GScanEngine[aDataIndex].ExtensionSpread[t, 1] = 0)
			{
				file << Formatting::to_utf8(Formatting::AddTrailing(L" " + GLanguageHandler->TypeDescriptions[t], 25, " ") + ": " + Formatting::AddLeading(L" " +IntToStr(GScanEngine[aDataIndex].ExtensionSpread[t, 1]), 7, L" ") + L" :: " + Formatting::AddLeading(L" " + Convert::ConvertToUsefulUnit(GScanEngine[aDataIndex].ExtensionSpread[t, 2]), 11, L" \n"))
			}
			else
			{
				if GScanEngine[aDataIndex].TotalSize != 0)
				{
					file << Formatting::to_utf8(Formatting::AddTrailing(L" " + GLanguageHandler->TypeDescriptions[t], 25, " ") + ": " + Formatting::AddLeading(L" " +IntToStr(GScanEngine[aDataIndex].ExtensionSpread[t, 1]), 7, L" ") + L" :: " + Formatting::AddLeading(L" " + Convert::ConvertToUsefulUnit(GScanEngine[aDataIndex].ExtensionSpread[t, 2]), 11, L" ") + "  (L" + Convert::RealToPercent(GScanEngine[aDataIndex].ExtensionSpread[t, 2] / GScanEngine[aDataIndex].TotalSize) + L")\n")
				}
				else
				{
					file << Formatting::to_utf8(Formatting::AddTrailing(L" " + GLanguageHandler->TypeDescriptions[t], 25, " ") + ": " + Formatting::AddLeading(L" " +IntToStr(GScanEngine[aDataIndex].ExtensionSpread[t, 1]), 7, L" ") + L" :: " + Formatting::AddLeading(L" " + Convert::ConvertToUsefulUnit(GScanEngine[aDataIndex].ExtensionSpread[t, 2]), 11, L" ") + L"  (100%)\n");
				}
			}
		}
		break;
	case 9:
		if GScanEngine[aDataIndex].ScanSource != ScanSourceFileCSV)
		{
			if Pos(L"\\",GScanEngine[aDataIndex].ScanPath) = 0)
			{
				file << Formatting::to_utf8(DriveReport[0] + TXWindows.GetDiskTypeString(GScanEngine[aDataIndex].ScanPath + ":") + L"\n");

				if GSystemGlobal.drivespacemax >= 0)
				{
					file << Formatting::to_utf8(DriveReport[1] + Convert::ConvertToUsefulUnit(GSystemGlobal.drivespacemax) + L"\n");
					file << Formatting::to_utf8(DriveReport[2] + Convert::ConvertToUsefulUnit(GSystemGlobal.drivespacefree) + L"\n");
				}
				else
				{
					file << Formatting::to_utf8(DriveReport[1] + "n/a\n");
					file << Formatting::to_utf8(DriveReport[2] + "n/a\n");
				}

				lDriveDetails := TXWindows.GetDriveDetails(GScanEngine[aDataIndex].ScanPath[1]);

				if lDriveDetails.Clusters != 0)
				{
					file << Formatting::to_utf8(L"\n");
					file << Formatting::to_utf8(DriveReport[3] + IntToStr(lDriveDetails.SectorsPerCluster) + L"\n");
					file << Formatting::to_utf8(DriveReport[4] + IntToStr(lDriveDetails.BytesPerSector) + L"\n");
					file << Formatting::to_utf8(DriveReport[5] + IntToStr(lDriveDetails.FreeClusters) + L"\n");
					file << Formatting::to_utf8(DriveReport[6] + IntToStr(lDriveDetails.Clusters) + L"\n");
					file << Formatting::to_utf8(L"\n");
					file << Formatting::to_utf8(DriveReport[7] + lDriveDetails.VolumeName + L"\n");
					file << Formatting::to_utf8(DriveReport[8] + lDriveDetails.SerialNumber + L" ($" + lDriveDetails.SerialNumberHex + ")\n");
					file << Formatting::to_utf8(DriveReport[9] + lDriveDetails.FileSystem);
				}
			}
			else
			{
				file << Formatting::to_utf8(DriveReport[10]);
			}
		}
		break;
	}

	file << Formatting::to_utf8(L""); */
}
