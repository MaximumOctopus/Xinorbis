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

#include "Convert.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "TabUiUsers.h"

extern ScanEngine* GScanEngine;
extern LanguageHandler* GLanguageHandler;


void TabUiUsers::Chart(TChart* chart, int DataSource)
{
	chart->SeriesList->Items[0]->Clear();

	if (GScanEngine->Data[DataSource].FileCount == 0) return;

	chart->Legend->TextStyle = ltsPlain;

	if (chart->Tag == 1)
	{
		chart->Title->Text->Strings[0] = GLanguageHandler->Text[kQuantityFilesUser].c_str();
	}
	else
	{
		chart->Title->Text->Strings[0] = GLanguageHandler->Text[kSizeFilesUser].c_str();
	}

	int ColourMod = 0;

	for (UserData *user : GScanEngine->Data[DataSource].Users)
	{
		if (chart->Tag == 1)
		{
			chart->SeriesList->Items[0]->Add(user->Count, user->Name.c_str(), TColor(kSpectrumColours[ColourMod % kSpectrumMod]));

			ColourMod++;
		}
		else
		{
			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				chart->SeriesList->Items[0]->Add((double)user->Size / (double)GScanEngine->Data[DataSource].TotalSize, user->Name.c_str(), TColor(kSpectrumColours[ColourMod % kSpectrumMod]));			}
			else
			{
				chart->SeriesList->Items[0]->Add(100, user->Name.c_str(), TColor(kSpectrumColours[ColourMod % kSpectrumMod]));
			}

			ColourMod++;
		}
	}
}


void TabUiUsers::Table(TStringGrid* grid, int DataSource, int display_mode)
{
//  if XSettings.Forms.ProgressForm <> Nil then
//	XSettings.Forms.ProgressForm.SetProcessText(GLanguageHandler->Text[kBuilding] + ' ' + GLanguageHandler->Text[kUserDetails]);

	//grid->ClearRows(1, grid.RowCount - 1);
	grid->RowCount = 2;

	if (GScanEngine->Data[DataSource].Users.size() == 0)
	{
		grid->Cells[kUsersTableName][1] = GLanguageHandler->Text[kNoneFound].c_str();
		return;
	}


	int count = 0;
	unsigned __int64 size = 0;
	int Row = 1;

	grid->BeginUpdate();

	grid->RowCount = GScanEngine->Data[DataSource].Users.size() + 1;

	for (UserData *user : GScanEngine->Data[DataSource].Users)
	{
		switch (display_mode)
		{
		case kDisplayModeShowAll:
			count = user->Count;
			size  = user->Size;

			grid->Cells[1][Row] = user->Name.c_str();
			grid->Cells[2][Row] = user->Count;
			grid->Cells[3][Row] = user->PercentCountString.c_str();

			grid->Cells[5][Row] = Convert::ConvertToUsefulUnit(user->Size).c_str();
			grid->Cells[6][Row] = user->PercentSizeString.c_str();

			grid->Cells[7][Row] = TColor(kSpectrumColours[(Row - 1) % kSpectrumMod]);
			grid->Cells[8][Row] = user->Size;

			grid->Cells[9][Row] = (int)(user->PercentCount * 50);
			grid->Cells[10][Row] = (int)(user->PercentSize * 50);
			break;

		default:
			count = user->CategoryDataQty[display_mode];
			size  = user->CategoryDataSize[display_mode];
			// to do
		}

		Row++;
	}

//	DoTableSort(oTable, oTable.SortSettings.Column, UsersSortColumns[oTable.SortSettings.Column]);

	grid->EndUpdate();
}
