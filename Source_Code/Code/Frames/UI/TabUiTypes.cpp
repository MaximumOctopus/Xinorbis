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
#include "FileExtensionHandler.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "TabUiTypes.h"

extern FileExtensionHandler* GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SettingsHandler* GSettingsHandler;


void TabUiTypes::Tree(TTreeView* view, int index)
{
	view->Items->Clear();
	view->Items->BeginUpdate();

	for (int t = 0; t < __FileCategoriesCount; t++)
	{
		bool AddRow = true;

		switch (GSettingsHandler->TabDisplay[index].Option[t].Value)
		{
		case 1:
			AddRow = true;
			break;
		case 2:
			if (GScanEngine->Data.ExtensionSpread[t].Count != 0)
			{
				AddRow = true;
			}
			else
			{
				AddRow = false;
			}
			break;
		case 3:
			if (GSettingsHandler->TabDisplay[view->Tag].Option[t + 1].Value == 1)
			{
				AddRow = true;
			}
			else
			{
				AddRow = false;
            }
			break;

		default:
			AddRow = false;
			break;
		}

		AddRow = true;

		if (AddRow)
		{
			std::wstring numstr = GScanEngine->Data.ExtensionSpread[t].PercentCountString;
			std::wstring ftsstr = GScanEngine->Data.ExtensionSpread[t].PercentSizeString;

			std::wstring cx = GScanEngine->Data.ExtensionSpread[t].Name + L" [ " +
							  std::to_wstring(GScanEngine->Data.ExtensionSpread[t].Count) + L" " + GLanguageHandler->Text[kFiles] +
							  L" (" + numstr + L") / " + Convert::ConvertToUsefulUnit(GScanEngine->Data.ExtensionSpread[t].Size) + L" (" + ftsstr + L") ]";

			TTreeNode *tvNode = view->Items->Add(NULL, cx.c_str());

			for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
			{
				if (GFileExtensionHandler->Extensions[z]->Category == t)
				{
					if (GFileExtensionHandler->Extensions[z]->Count != 0)
					{
						std::wstring label = L"." + GFileExtensionHandler->Extensions[z]->Name + L": " +
											 std::to_wstring(GFileExtensionHandler->Extensions[z]->Count) +
											 L" (" + Convert::ConvertToUsefulUnit(GFileExtensionHandler->Extensions[z]->Size) + L")";

						view->Items->AddChild(tvNode, label.c_str());
					}
				}
			}
		}
	}

	view->Items->EndUpdate();
}


void TabUiTypes::TreePost(TTreeView* view)
{                /*
	if (view->Items->Count != 0)
	{
		int i = -1;
		int t = 0;

		while (i == -1 && t < view->Items->Count)
		{
			if (view->Items[t]->Parent != nullptr)
			{
				if (Pos('0%', view.Items[t].Text) = 0)
				{
					i = t;
				}
			}

			t++;
		}

		if (i != -1)
		{
			view->Select(view->Items[i], []);

			return 1;
		}
	}
	else
	{
		return  2;
	}

	return 0;         */
}


void TabUiTypes::List(TStringGrid* grid)
{
//	if XSettings.Forms.ProgressForm <> Nil then begin
//	XSettings.Forms.ProgressForm.SetProcessText(XText[kBuilding] + ' ' + XText[kFileTypes]);
//	XSettings.System.JustInTimeProcessed[aDataIndex, TabIndexTypes] := True;
//	end;

	grid->BeginUpdate();

	for (int t = 0; t < __AttributesCount; t++)
	{
		/*for t := 1 to __AttributesToDisplayCount do begin
		grid.Cells[0, t] := LanguageTypes[t];

		grid.Cells[1, t] := IntToStr(GScanDetails[aDataIndex].FileAttributes[t, 0]);

		if GScanDetails[aDataIndex].FileCount <> 0 then begin
		  grid.Cells[2, t] := TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 0] / GScanDetails[aDataIndex].FileCount);
		  grid.Cells[6, t] := IntToStr(Round((GScanDetails[aDataIndex].FileAttributes[t, 0] / GScanDetails[aDataIndex].FileCount) * 50));
		end
		else begin
		  grid.Cells[2, t] := '100%';
		  oTable.Cells[6, t] := '100';
		end;

		oTable.Cells[4, t] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].FileAttributes[t, 1]);

		if GScanDetails[aDataIndex].TotalSize <> 0 then begin
		  oTable.Cells[5, t] := TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 1] / GScanDetails[aDataIndex].TotalSize);
		  oTable.Cells[7, t] := IntToStr(Round((GScanDetails[aDataIndex].FileAttributes[t, 1] / GScanDetails[aDataIndex].TotalSize) * 50));
		end
		else begin
		  oTable.Cells[5, t] := '100%';
		  oTable.Cells[7, t] := '100';
		end; */
	}

	grid->EndUpdate();

	grid->Refresh();
}


void TabUiTypes::Chart(TChart* chart, int label_options)
{
	if (GScanEngine->Data.FileCount == 0) return;

	chart->SeriesList->Items[0]->Clear();
	chart->Legend->TextStyle = ltsPlain;
	chart->Title->Text->Strings[0] = GLanguageHandler->TypeDescriptions[GSettingsHandler->TabInternal.TreeViewChartIndex].c_str();

	int ci = 0;

	for (int t = 0; t < GFileExtensionHandler->Extensions.size(); t++)
	{
		FileExtension *tfx = GFileExtensionHandler->Extensions[t];

		if (tfx->Category == GSettingsHandler->TabInternal.TreeViewChartIndex)
		{
			switch (chart->Tag)
			{
			case kSelectionQuantity:
				if (tfx->Count != 0)
				{
					std::wstring label = L"";

					switch (label_options)
					{
					case kLabelOptionDefault:
						label = tfx->Name;
						break;
					case kLabelOptionMostConvenient:
						label = tfx->Name + L" " + std::to_wstring(tfx->Count) + L" (" + Convert::ConvertToUsefulUnit(tfx->Size) + L")";
						break;
					case kLabelOptionKilobyte:
						label = tfx->Name + L" " + std::to_wstring(tfx->Count) + L" (" + Convert::ConvertToStaticUnit(tfx->Size, UnitConversion::kUnitKB) + L")";
						break;
					case kLabelOptionMegabyte:
						label = tfx->Name + L" " + tfx->Name + L" " + std::to_wstring(tfx->Count) + L" (" + Convert::ConvertToStaticUnit(tfx->Size, UnitConversion::kUnitMB) + L")";
						break;
					case kLabelOptionGigabyte:
						label = std::to_wstring(tfx->Count) + L" (" + Convert::ConvertToStaticUnit(tfx->Size, UnitConversion::kUnitGB) + L")";
						break;
					}

					chart->SeriesList->Items[0]->Add(tfx->Count, label.c_str(), TColor(__SpectrumColours[ci % __SpectrumMod]));
				}
				break;
			case kSelectionSize:
				if (tfx->Size != 0)
				{
					std::wstring label = L"";

					switch (label_options)
					{
					case kLabelOptionDefault:
						label = tfx->Name;
						break;
					case kLabelOptionMostConvenient:
						label = tfx->Name + L" (" + Convert::ConvertToUsefulUnit(tfx->Size) + L")";
						break;
					case kLabelOptionKilobyte:
						label = tfx->Name + L" (" + Convert::ConvertToStaticUnit(tfx->Size, UnitConversion::kUnitKB) + L")";
						break;
					case kLabelOptionMegabyte:
						label = tfx->Name + L" (" + Convert::ConvertToStaticUnit(tfx->Size, UnitConversion::kUnitMB) + L")";
						break;
					case kLabelOptionGigabyte:
						label = tfx->Name + L" (" + Convert::ConvertToStaticUnit(tfx->Size, UnitConversion::kUnitGB) + L")";
						break;
					}

					chart->SeriesList->Items[0]->Add(tfx->Size, label.c_str(), TColor(__SpectrumColours[ci % __SpectrumMod]));
				}
				break;
			}

			ci++;
		}
	}
}
