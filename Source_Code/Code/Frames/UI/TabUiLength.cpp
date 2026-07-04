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
#include "SettingsHandler.h"
#include "TabUiLength.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SettingsHandler* GSettingsHandler;


void TabUiLength::Chart(TChart* chart, int label_options)
{
// to do	if (GScanEngine->Data.LeCount == 0) return;

	// == don't show size details if the chart is in quantity mode =============
//	if (chart->Tag == fQuantity) // to do
//	{
//		label_options = 0;
//	}
	// =========================================================================

	chart->SeriesList->Items[0]->Clear();
	chart->Legend->TextStyle = ltsPlain;

	if (GScanEngine->Path.LastScanMultiple)
	{
		chart->Title->Text->Strings[0] = GLanguageHandler->Text[kMultipleFolders].c_str();
	}
	else
	{
		chart->Title->Text->Strings[0] = GScanEngine->Path.String.c_str();
	}

	for (int t = 0; t < 280; t++)
	{
		if (chart->Tag == 1)
		{
			if (GScanEngine->Data.Lengths[t].Count != 0)
			{
				std::wstring label = L"";

				switch (label_options)
				{
				case kLabelOptionDefault:
					label = GScanEngine->Data.Lengths[t].Name;
					break;
				case kLabelOptionMostConvenient:
					label = Convert::ConvertToUsefulUnit(GScanEngine->Data.Lengths[t].Size);
					break;
				case kLabelOptionKilobyte:
					label = Convert::ConvertToStaticUnit(GScanEngine->Data.Lengths[t].Size, UnitConversion::kUnitKB);
					break;
				case kLabelOptionMegabyte:
					label = Convert::ConvertToStaticUnit(GScanEngine->Data.Lengths[t].Size, UnitConversion::kUnitMB);
					break;
				case kLabelOptionGigabyte:
					label = Convert::ConvertToStaticUnit(GScanEngine->Data.Lengths[t].Size, UnitConversion::kUnitGB);
					break;
				}

				chart->SeriesList->Items[0]->Add(GScanEngine->Data.Lengths[t].Count, label.c_str(), TColor(__SpectrumColours[t % __SpectrumMod]));
			}
		}
		else
		{
            if (GScanEngine->Data.Lengths[t].Size != 0)
			{
				std::wstring label = L"";

				switch (label_options)
				{
				case kLabelOptionDefault:
					label = GScanEngine->Data.Lengths[t].Name;
					break;
				case kLabelOptionMostConvenient:
					label = Convert::ConvertToUsefulUnit(GScanEngine->Data.Lengths[t].Size);
					break;
				case kLabelOptionKilobyte:
					label = Convert::ConvertToStaticUnit(GScanEngine->Data.Lengths[t].Size, UnitConversion::kUnitKB);
					break;
				case kLabelOptionMegabyte:
					label = Convert::ConvertToStaticUnit(GScanEngine->Data.Lengths[t].Size, UnitConversion::kUnitMB);
					break;
				case kLabelOptionGigabyte:
					label = Convert::ConvertToStaticUnit(GScanEngine->Data.Lengths[t].Size, UnitConversion::kUnitGB);
					break;
				}

				chart->SeriesList->Items[0]->Add(GScanEngine->Data.Lengths[t].Size, label.c_str(), TColor(__SpectrumColours[t % __SpectrumMod]));
			}
		}
	}
}



void TabUiLength::Table(TStringGrid* grid, int index, bool add_all)
{
//  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabTableTable :: invalid dataindex :: ' + inttostr(aDataIndex));

  //if XSettings.System.Debug then TMSLogger.Info('InformationTabTableTable : ' + IntToStr(aDataIndex) + '/' + IntToStr(oTableDisplay) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

//  if XSettings.Forms.ProgressForm <> Nil then
//    XSettings.Forms.ProgressForm.SetProcessText(XText[kBuilding] + ' ' + XText[kTableDisplay]);

	grid->BeginUpdate();

	grid->RowCount = 2;

	int Row = 1;
	bool AddRow = true;

	for (int t = 0; t < 280; t++)
	{
		if (add_all)
		{
			AddRow = true;
		}
		else
		{
			if (GSettingsHandler->TabDisplay[index].Option[1].Value == 1)
			{
				if (GScanEngine->Data.Lengths[t].Count != 0)
				{
					AddRow = true;
				}
			}
			else
			{
				AddRow = false;
			}
		}

		if (AddRow)
		{
			ConsolidatedData cd = GScanEngine->Data.Lengths[t];

			grid->Cells[1][Row]  = cd.Name.c_str();

			grid->Cells[2][Row]  = cd.Count;
			grid->Cells[3][Row]  = cd.PercentCountString.c_str();

			grid->Cells[5][Row]  = Convert::ConvertToUsefulUnit(cd.Size).c_str();
			grid->Cells[6][Row]  = cd.PercentSizeString.c_str();

			grid->RowCount++;
		}

		Row++;
	}

	if (grid->RowCount > 2)
	{
		grid->RowCount--;
	}

	grid->EndUpdate();

	//DoTableSort(oTable, oTable.SortSettings.Column, MainReportSortColumns[oTable.SortSettings.Column]);
}