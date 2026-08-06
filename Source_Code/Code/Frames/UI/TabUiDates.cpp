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

#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "TabUiDates.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SettingsHandler* GSettingsHandler;


void TabUiDates::Chart(TTreeView* tree, TChart* chart)
{
	int colour = 0;

	chart->SeriesList->Items[0]->Clear();

	// build graph from tree nodes ===============================================
	for (int t = 0; t < tree->Items->Count; t++)
	{
		if (tree->Items->Item[t]->Parent == NULL)
		{
			int index = Pos(L":", tree->Items->Item[t]->Text) + 2;

			std::wstring dd = L"";

			while (tree->Items->Item[t]->Text[index] != L' ')
			{
				dd += tree->Items->Item[t]->Text[index];

				index++;
			}

			chart->SeriesList->Items[0]->Add(stoi(dd), tree->Items->Item[t]->Text.SubString(0, 4), TColor(kSpectrumColours[t % kSpectrumMod])); // ignore <b> from text

			colour++;
		}
	}
}


void TabUiDates::Tree(TTreeView* tree, XIceCream* icecream, int DataSource, int userid, int data_range, bool build_tree, bool quantity)
{
	if (!build_tree || GScanEngine->Data[DataSource].Files.size() == 0) return;

	std::wstring yy = L"";
	std::wstring mm = L"";
	std::wstring dd = L"";

	std::wstring oldyear  = L"9999";
	std::wstring oldmonth = L"9999";
	std::wstring oldday   = L"9999";

	int YearCount  = 0;
	int MonthCount = 0;
	int DayCount   = 0;

	unsigned __int64 YearSize = 0;
	unsigned __int64 MonthSize = 0;
	unsigned __int64 DaySize = 0;

	TTreeNode* yearnode = nullptr;
	TTreeNode* monthnode = nullptr;
	TTreeNode* daynode = nullptr;

	unsigned __int64 ExtSpreadSize[kFileCategoriesCount];
	int ExtSpreadCount[kFileCategoriesCount];

	// =========================================================================

	unsigned __int64 DatesTotalSize = 0;
	int DatesTotalCount = 0;

	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		ExtSpreadSize[t] = 0;
		ExtSpreadCount[t] = 0;
	}

	// =========================================================================

	tree->Items->Clear();
	tree->Items->BeginUpdate();

//      if XSettings.Forms.ProgressForm <> Nil then
//        XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsDateTree]);

	bool AddFileName = false;

	if (GSettingsHandler->Optimisations.AddToDate)
	{
		if (GSettingsHandler->Optimisations.AddToDateLimit)
		{
			if (GScanEngine->Data[DataSource].FileCount <= GSettingsHandler->Optimisations.AddToDateLimitCount)
			{
				AddFileName = true;
			}
		}
		else
		{
			AddFileName = true;
		}
	}

	switch (data_range)
	{
	case kCreatedDate:
		GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateCreated);
		break;
	case kAccessedDate:
		GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateAccessed);
		break;
	case kModifiedDate:
		GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateModified);
		break;
	}

	for (FileObject *file : GScanEngine->Data[DataSource].Files)
	{
		if (!(faDirectory & file->Attributes))
		{
			std::wstring strdate = L"";

			switch (data_range)
			{
			case kCreatedDate:
				strdate = file->DateCreated;
				yy      = strdate.substr(0, 4);
				mm      = strdate.substr(4, 2);
				dd      = strdate.substr(6, 2);
				break;
			case kAccessedDate:
				strdate = file->DateAccessed;
				yy      = strdate.substr(0, 4);
				mm      = strdate.substr(4, 2);
				dd      = strdate.substr(6, 2);
				break;
			case kModifiedDate:
				strdate = file->DateModified;
				yy      = strdate.substr(0, 4);
				mm      = strdate.substr(4, 2);
				dd      = strdate.substr(6, 2);
				break;
			}

			// ===================================================================

			switch (stoi(dd))
			{
			case 1:
			case 21:
			case 31:
				dd += L"st";
				break;
			case 2:
			case 22:
				dd += L"nd";
				break;
			case 3:
			case 23:
				dd += L"rd";
				break;

			default:
				dd += L"th";
			}

			// ===================================================================

			if (yy != oldyear)
			{
				if (oldyear != L"9999")
				{
					yearnode->Text = (oldyear + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(YearCount) + L" (" + Convert::ConvertToUsefulUnit(YearSize) + L")]").c_str();
				}

				if (oldmonth != L"9999")
				{
					monthnode->Text = (GLanguageHandler->ShortMonths[stoi(oldmonth)] + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(MonthCount) + L" (" + Convert::ConvertToUsefulUnit(MonthSize) + L")]").c_str();
				}

				if (oldday != L"9999")
				{
					daynode->Text = (oldday + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(DayCount) + L" (" + Convert::ConvertToUsefulUnit(DaySize) + L")]").c_str();
				}

				oldyear   = yy;
				oldday    = dd;
				oldmonth  = mm;

				yearnode  = tree->Items->Add(NULL, yy.c_str());
				monthnode = tree->Items->AddChild(yearnode, GLanguageHandler->ShortMonths[stoi(mm)].c_str());
				daynode   = tree->Items->AddChild(monthnode, dd.c_str());

				YearCount  = 0;  YearSize  = 0;
				MonthCount = 0;  MonthSize = 0;
				DayCount   = 0;  DaySize   = 0;
			}

			if (mm != oldmonth)
			{
				if (oldmonth != L"9999")
				{
					monthnode->Text = (GLanguageHandler->ShortMonths[stoi(oldmonth)] + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(MonthCount) + L" (" + Convert::ConvertToUsefulUnit(MonthSize) + L")]").c_str();
				}

				if (oldday != L"9999")
				{
					daynode->Text = (oldday + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(DayCount) + L" (" + Convert::ConvertToUsefulUnit(DaySize) + L")]").c_str();
				}

				oldday     = dd;
				oldmonth   = mm;

				monthnode  = tree->Items->AddChild(yearnode, GLanguageHandler->ShortMonths[stoi(mm)].c_str());
				daynode    = tree->Items->AddChild(monthnode, dd.c_str());

				MonthCount = 0;
				MonthSize  = 0;
				DayCount   = 0;
				DaySize    = 0;
			}

			if (dd != oldday)
			{
				if (oldday != L"9999")
				{
					daynode->Text = (oldday + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(DayCount) + L" (" + Convert::ConvertToUsefulUnit(DaySize) + L")]").c_str();
				}

				oldday = dd;

				if (monthnode != nullptr)
				{
					daynode = tree->Items->AddChild(monthnode, dd.c_str());
				}

				DayCount = 0;
				DaySize  = 0;
			}

			// ===================================================================

			if (userid != -1)
			{
				if (file->Owner != userid)
				{
					AddFileName = false;
				}
			}

			// ===================================================================

			if (AddFileName)
			{
				tree->Items->AddChild(daynode, (GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name).c_str());
			}

			YearCount++;
			MonthCount++;
			DayCount++;

			YearSize += file->Size;
			MonthSize += file->Size;
			DaySize += file->Size;

			DatesTotalCount++;
			DatesTotalSize += file->Size;

			ExtSpreadCount[file->Category]++;
			ExtSpreadSize[file->Category] += file->Size;
		}
	}

	yearnode->Text  = (yy + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(YearCount) + L" (" + Convert::ConvertToUsefulUnit(YearSize) + L")]").c_str();
	monthnode->Text = (GLanguageHandler->ShortMonths[stoi(oldmonth) ] + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(MonthCount) + L" (" + Convert::ConvertToUsefulUnit(MonthSize) + L")]").c_str();
	daynode->Text   = (oldday + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(DayCount) + L" (" + Convert::ConvertToUsefulUnit(DaySize) + L")]").c_str();

	// ===========================================================================

	tree->Items->EndUpdate();

	if (icecream != nullptr)
	{
		icecream->Begin();

		for (int t = 1; t < kFileCategoriesCount; t++)
		{
			if (DatesTotalCount != 0)
			{
				if (ExtSpreadCount[t] != 0)
				{
					icecream->Add(0,
								  (ExtSpreadCount[t] / DatesTotalCount) * 100,
								  GLanguageHandler->TypeDescriptions[t],
								  GLanguageHandler->TypeDescriptions[t] + L" (" + std::to_wstring(ExtSpreadCount[t]) + L" files)",
								  GSettingsHandler->FileCategoryColors[t]);
				}
			}

			if (DatesTotalSize != 0)
			{
				if (ExtSpreadSize[t] != 0)
				{
					icecream->Add(1,
								  (ExtSpreadSize[t] / DatesTotalSize) * 100,
								  GLanguageHandler->TypeDescriptions[t],
								  GLanguageHandler->TypeDescriptions[t] + L" (" + Convert::ConvertToUsefulUnit(ExtSpreadSize[t]) + L")",
								  GSettingsHandler->FileCategoryColors[t]);
				}
			}
		}

		icecream->End();
	}

//	switch (DataSource)
//	{
//	case kDataScan:
//		GScanEngine->Data[DataSource].SortByPropert(SortMode::kFullPath);
//        break;

//	case kDataFolderHistory:
//	//GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathFH));
//      break;
//  }
}

