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

#include "ConstantsData.h"
#include "Convert.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "TabUiTemp.h"

extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;


void TabUiTemp::Chart(TChart* chart, int DataSource, bool quantity)
{
	chart->SeriesList->Items[0]->Clear();
	chart->Legend->TextStyle = ltsPlain;

	if (GScanEngine->Data[DataSource].TotalSize != 0)
	{
		if (quantity)
		{
			chart->Title->Text->Strings[0] = GLanguageHandler->Text[kTempFilePTNF].c_str();

			if (GScanEngine->Data[DataSource].FileCount != 0)
			{
				chart->SeriesList->Items[0]->Add(100 - ((GScanEngine->Data[DataSource].ExtensionSpread[kCategory_Temp].Count) / GScanEngine->Data[DataSource].FileCount) * 100,
												 GLanguageHandler->Text[kAllOtherFiles].c_str(),
												 TColor(0x444444));

				chart->SeriesList->Items[0]->Add(((GScanEngine->Data[DataSource].ExtensionSpread[kCategory_Temp].Size) / GScanEngine->Data[DataSource].FileCount) * 100,
												 GLanguageHandler->Text[kTempFiles].c_str(),
												 TColor(0x00CCFF));
			}
		}
		else
		{
			chart->Title->Text->Strings[0] = GLanguageHandler->Text[kTempFilePTSF].c_str();

			chart->SeriesList->Items[0]->Add(100 - ((GScanEngine->Data[DataSource].ExtensionSpread[kCategory_Temp].Count) / GScanEngine->Data[DataSource].TotalSize) * 100,
											 GLanguageHandler->Text[kAllOtherFiles].c_str(),
											 TColor(0x444444));
			chart->SeriesList->Items[0]->Add(((GScanEngine->Data[DataSource].ExtensionSpread[kCategory_Temp].Size) / GScanEngine->Data[DataSource].TotalSize) * 100,
											 GLanguageHandler->Text[kTempFiles].c_str(),
											 TColor(0x00CCFF));
		}
	}
}


std::wstring TabUiTemp::Table(TStringGrid* grid, int DataSource)
{
	//grid->ClearRows(1, grid.RowCount - 1);
	grid->RowCount = 2;

	if (GScanEngine->Data[DataSource].ExtensionSpread[kCategory_Temp].Count != 0)
	{
		grid->Cells[0][1] = GLanguageHandler->Text[kNoneFound].c_str();

		return GLanguageHandler->Text[kNoTempFilesFound];
	}

	int count = 0;
	unsigned __int64 size = 0;
	int Row = 1;

	grid->BeginUpdate();

	grid->RowCount = GScanEngine->Data[DataSource].TemporaryFiles.size() + 1;

	for (TempFileObject *file : GScanEngine->Data[DataSource].TemporaryFiles)
	{
		grid->Cells[0][Row] = file->Name.c_str();
		grid->Cells[1][Row] = Convert::ConvertToUsefulUnit(file->Size).c_str();

		Row++;
	}

//	DoTableSort(oTable, oTable.SortSettings.Column, UsersSortColumns[oTable.SortSettings.Column]);

	grid->EndUpdate();

	return std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[kCategory_Temp].Count) + L" " +
		   GLanguageHandler->Text[kFiles] +
		   L" (" + Convert::ConvertToUsefulUnit(GScanEngine[DataSource].ExtensionSpread[kCategory_Temp].Size) + L")";
}