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


void TabUiUsers::Chart(TChart* chart)
{
	chart->SeriesList->Items[0]->Clear();

	if (GScanEngine->Data.FileCount == 0) return;

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

	for (UserData user : GScanEngine->Data.Users)
	{
		if (chart->Tag == 1)
		{
			chart->SeriesList->Items[0]->Add(user.Count, user.Name.c_str(), TColor(__SpectrumColours[ColourMod % __SpectrumMod]));

			ColourMod++;
		}
		else
		{
			if (GScanEngine->Data.TotalSize != 0)
			{
				chart->SeriesList->Items[0]->Add((double)user.Size / (double)GScanEngine->Data.TotalSize, user.Name.c_str(), TColor(__SpectrumColours[ColourMod % __SpectrumMod]));			}
			else
			{
				chart->SeriesList->Items[0]->Add(100, user.Name.c_str(), TColor(__SpectrumColours[ColourMod % __SpectrumMod]));
			}

			ColourMod++;
		}
	}
}


void TabUiUsers::Table(TStringGrid* grid, int display_mode)
{
//  if XSettings.Forms.ProgressForm <> Nil then
//	XSettings.Forms.ProgressForm.SetProcessText(GLanguageHandler->Text[kBuilding] + ' ' + GLanguageHandler->Text[kUserDetails]);

	//grid->ClearRows(1, grid.RowCount - 1);
	grid->RowCount = 2;

	if (GScanEngine->Data.Users.size() == 0)
	{
		grid->Cells[kUsersTableName][1] = GLanguageHandler->Text[kNoneFound].c_str();
		return;
	}


	int count = 0;
	unsigned __int64 size = 0;
	int row = 1;

	grid->BeginUpdate();

	grid->RowCount = GScanEngine->Data.Users.size() + 1;

	for (UserData user : GScanEngine->Data.Users)
	{
		switch (display_mode)
		{
		case kDisplayModeShowAll:
			count = user.Count;
			size  = user.Size;
			break;

		default:
			count = user.CategoryDataQty[display_mode];
			size  = user.CategoryDataSize[display_mode];
		}

		grid->Cells[kUsersTableName][row] = user.Name.c_str();
		grid->Cells[kUsersTableCount][row] = count;

		if (GScanEngine->Data.FileCount != 0)
		{
			grid->Cells[kUsersTableCountAs][row] = Convert::DoubleToPercent(count / GScanEngine->Data.FileCount).c_str();
			grid->Cells[kUsersTableGraphCount][row] = std::round((count / GScanEngine->Data.FileCount) * 50);
		}
		else
		{
			grid->Cells[kUsersTableCountAs][row] = L"100%";
			grid->Cells[kUsersTableGraphCount][row] = L"50";
		}

		grid->Cells[kUsersTableSize][row] = Convert::ConvertToUsefulUnit(size).c_str();

		if (GScanEngine->Data.TotalSize != 0)
		{
			grid->Cells[kUsersTableSizeAs][row] = Convert::DoubleToPercent(size / GScanEngine->Data.TotalSize).c_str();
			grid->Cells[kUsersTableGraphSize][row] = std::round((size / GScanEngine->Data.TotalSize) * 50);
		}
		else
		{
			grid->Cells[kUsersTableSizeAs][row] = L"100%";
			grid->Cells[kUsersTableGraphSize][row] = L"50";
		}

		grid->Cells[kUsersTableSortSize][row] = size;
	}

//	DoTableSort(oTable, oTable.SortSettings.Column, UsersSortColumns[oTable.SortSettings.Column]);

	grid->EndUpdate();
}
