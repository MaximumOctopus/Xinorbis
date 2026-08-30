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
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "TabUiFolders.h"

extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;


void TabUiFolders::Chart(TChart* chart, int DataSource, double filter_value, int ChartLabelOption)
{
	if (GScanEngine->Data[DataSource].FileCount > 0)
	{
		if (chart->Tag == 1)
		{
			chart->LeftAxis->Title->Caption   = Convert::LowerCase(GLanguageHandler->Text[kFolder]).c_str();
			chart->BottomAxis->Title->Caption = Convert::LowerCase(GLanguageHandler->Text[kBytes]).c_str();
		}
		else
		{
			chart->LeftAxis->Title->Caption   = Convert::LowerCase(GLanguageHandler->Text[kFolder]).c_str();
			chart->BottomAxis->Title->Caption = Convert::LowerCase(GLanguageHandler->Text[kQuantity]).c_str();
		}

		//-- build graph -------------------------------------------------------------
		chart->SeriesList->Items[0]->Clear();

		if (chart->Series[0]->ClassNameIs(L"THorizBarSeries"))
		{
			chart->SeriesList->Items[0]->Marks->Style = smsXValue;
		}
		else
		{
			chart->SeriesList->Items[0]->Marks->Style = smsLabelValue;
		}

		chart->Legend->TextStyle = ltsPlain;

		chart->Title->Text->Strings[0] = GScanEngine->Data[DataSource].Path.String.c_str();

		int colindex = 0;
		double filtertest = 0;

		for (int t = 0; t < GScanEngine->Data[DataSource].RootFolders.size(); t++)
		{
			if (chart->Tag == 1)
			{
				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					filtertest = (GScanEngine->Data[DataSource].RootFolders[t]->Size / GScanEngine->Data[DataSource].TotalSize) * 100;
				}
				else
				{
					filtertest = 100;
				}

				if (GScanEngine->Data[DataSource].RootFolders[t]->Size != 0 && filtertest > filter_value)
				{
					chart->SeriesList->Items[0]->Add(GScanEngine->Data[DataSource].RootFolders[t]->Size,
													 GScanEngine->Data[DataSource].RootFolders[t]->Name.c_str(),
													 TColor(kSpectrumColours[colindex % kSpectrumMod]));

					colindex++;
				}
			}
			else
			{
				filtertest = (GScanEngine->Data[DataSource].RootFolders[t]->Count / GScanEngine->Data[DataSource].FileCount) * 100;

				if (GScanEngine->Data[DataSource].RootFolders[t]->Count != 0 && filtertest > filter_value)
				{
					chart->SeriesList->Items[0]->Add(GScanEngine->Data[DataSource].RootFolders[t]->Count,
													 GScanEngine->Data[DataSource].RootFolders[t]->Name.c_str(),
													 TColor(kSpectrumColours[colindex % kSpectrumMod]));

					colindex++;
				}
			}
		}
	}
}


void TabUiFolders::Table(TStringGrid *grid, int DataSource)
{
	grid->RowCount = 2;

	if (GScanEngine->Data[DataSource].RootFolders.size() == 0)
	{
		grid->Cells[1][1] = GLanguageHandler->Text[kNoneFound].c_str();
		return;
	}

	int Row = 1;

	grid->BeginUpdate();

	grid->RowCount = GScanEngine->Data[DataSource].RootFolders.size() + 1;

	for (RootFolder *folder : GScanEngine->Data[DataSource].RootFolders)
	{
		grid->Cells[1][Row] = folder->Name.c_str();
		grid->Cells[2][Row] = folder->Count;
		grid->Cells[3][Row] = folder->PercentCountString.c_str();

		grid->Cells[5][Row] = Convert::ConvertToUsefulUnit(folder->Size).c_str();
		grid->Cells[6][Row] = folder->PercentSizeString.c_str();

		grid->Cells[7][Row] = TColor(kSpectrumColours[(Row - 1) % kSpectrumMod]);
		grid->Cells[8][Row] = folder->Size;

		grid->Cells[9][Row] = (int)(folder->PercentCount * 50);
		grid->Cells[10][Row] = (int)(folder->PercentSize * 50);

		Row++;
	}

//	DoTableSort(oTable, oTable.SortSettings.Column, UsersSortColumns[oTable.SortSettings.Column]);

	grid->EndUpdate();
}
