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

			chart->SeriesList->Items[0]->Add(stoi(dd), tree->Items->Item[t]->Text.SubString(0, 4), TColor(__SpectrumColours[t % __SpectrumMod])); // ignore <b> from text

			colour++;
		}
	}
}


void TabUiDates::Table(TTreeView* tree, int userid, int data_range, bool build_tree, bool quantity)
{
	if (!build_tree || GScanEngine->Data.Files.size() == 0) return;

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

	// ===========================================================================

	unsigned __int64 DatesTotalSize = 0;
	int DatesTotalCount = 0;

//	for t := 1 to __FileCategoriesCount do begin // clear data
//		ExtSpreadDates[t, 1] := 0;
//		ExtSpreadDates[t, 2] := 0;
//	  end;

  // ===========================================================================

	tree->Items->Clear();
	tree->Items->BeginUpdate();

//      if XSettings.Forms.ProgressForm <> Nil then
//        XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsDateTree]);

	bool AddFileName = false;

	if (GSettingsHandler->Optimisations.AddToDate)
	{
		if (GSettingsHandler->Optimisations.AddToDateLimit)
		{
			if (GScanEngine->Data.FileCount <= GSettingsHandler->Optimisations.AddToDateLimitCount)
			{
				AddFileName = true;
			}
		}
		else
		{
			AddFileName = true;
		}
	}

//	switch (data_range)
//	{
//	case kCreatedDate:
//		GScanEngine->taIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
//	case kAccessedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
//	case kModifiedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
//	}

	for (FileObject file : GScanEngine->Data.Files)
	{
		if (!(faDirectory & file.Attributes))
		{
			std::wstring strdate = L"";

			switch (data_range)
			{
			case kCreatedDate:
				strdate = file.DateCreated;
				yy      = strdate.substr(0, 4);
				mm      = strdate.substr(4, 2);
				dd      = strdate.substr(6, 2);
				break;
			case kAccessedDate:
				strdate = file.DateAccessed;
				yy      = strdate.substr(0, 4);
				mm      = strdate.substr(4, 2);
				dd      = strdate.substr(6, 2);
				break;
			case kModifiedDate:
				strdate = file.DateModified;
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
				if (file.Owner != userid)
				{
					AddFileName = false;
				}
			}

			// ===================================================================

			if (AddFileName)
			{
				tree->Items->AddChild(daynode, (GScanEngine->Data.Folders[file.FilePathIndex] + file.Name).c_str());
			}

			YearCount++;
			MonthCount++;
			DayCount++;

			YearSize += file.Size;
			MonthSize += file.Size;
			DaySize += file.Size;

			DatesTotalCount++;
			DatesTotalSize += file.Size;

			//inc(ExtSpreadDates[GScanDetails[aDataIndex].Files.Items[x].FileCategory, 1]);
			//inc(ExtSpreadDates[GScanDetails[aDataIndex].Files.Items[x].FileCategory, 2], GScanDetails[aDataIndex].Files.Items[x].FileSize);
		}
	}

	yearnode->Text  = (yy + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(YearCount) + L" (" + Convert::ConvertToUsefulUnit(YearSize) + L")]").c_str();
	monthnode->Text = (GLanguageHandler->ShortMonths[stoi(oldmonth) ] + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(MonthCount) + L" (" + Convert::ConvertToUsefulUnit(MonthSize) + L")]").c_str();
	daynode->Text   = (oldday + L" [" + GLanguageHandler->Text[kFiles] + L": " + std::to_wstring(DayCount) + L" (" + Convert::ConvertToUsefulUnit(DaySize) + L")]").c_str();

	// ===========================================================================

	tree->Items->EndUpdate();

//	switch (aDataIndex)
//	{                TO DO TO DO TO DO
//	  dataLatestScan    : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathLS));
//	  dataFolderHistory : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathFH));
//	}
}

