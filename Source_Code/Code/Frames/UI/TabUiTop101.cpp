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
#include "GridUtility.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "TabUiTop101.h"

extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;


std::wstring TabUiTop101::Date(TStringGrid* gridbig, TStringGrid* gridsmall, int DataSource, int user_id, int date_type)
{
	constexpr static int kDatePropertyCreated = 0;
	constexpr static int kDatePropertyAccessed = 1;
	constexpr static int kDatePropertyModified = 2;

	if (GScanEngine->Data[DataSource].FileCount == 0) return L"n/a";

	switch (date_type)
	{
	case kDatePropertyCreated:
		GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateCreated);
		break;
	case kDatePropertyAccessed:
		GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateAccessed);
		break;
	case kDatePropertyModified:
		GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateModified);
		break;
	}

	GridUtility::Clear(gridbig, false);
	GridUtility::Clear(gridsmall, false);

	gridbig->BeginUpdate();
	gridsmall->BeginUpdate();

	// == build top list of largest files ========================================
	int added_count = 0;
	int index = GScanEngine->Data[DataSource].Files.size() - 1;
	unsigned __int64 TopSize = 0;

	while (index >= 0 && added_count <= 100)
	{
		 if (!(faDirectory & GScanEngine->Data[DataSource].Files[index]->Attributes))
		 {
            bool CanAdd = false;

			if (user_id == -1)
			{
				CanAdd = true;
			}
			else
			{
				CanAdd = (GScanEngine->Data[DataSource].Files[index]->Owner == user_id);
			}

			if (CanAdd)
			{
				FileObject *fo = GScanEngine->Data[DataSource].Files[index];

				gridbig->Cells[0][gridbig->RowCount - 1] = (GScanEngine->Data[DataSource].Folders[fo->FilePathIndex] + fo->Name).c_str();

				switch (date_type)
				{
				case kDatePropertyCreated:
					gridbig->Cells[1][gridbig->RowCount - 1] = Convert::IntDateToString(fo->DateCreated).c_str();
					break;
				case kDatePropertyAccessed:
					gridbig->Cells[1][gridbig->RowCount - 1] = Convert::IntDateToString(fo->DateAccessed).c_str();
					break;
				case kDatePropertyModified:
					gridbig->Cells[1][gridbig->RowCount - 1] = Convert::IntDateToString(fo->DateModified).c_str();
					break;
				}

				gridbig->Cells[2][gridbig->RowCount - 1] = Convert::ConvertToUsefulUnit(fo->Size).c_str();
				gridbig->Cells[3][gridbig->RowCount - 1] = GScanEngine->Data[DataSource].Users[fo->Owner]->Name.c_str();
				gridbig->Cells[4][gridbig->RowCount - 1] = GSettingsHandler->FileCategoryColors[fo->Category];

				gridbig->RowCount++;

				added_count++;
				TopSize += fo->Size;
			}
		}

		index--;
	}

	gridbig->RowCount--;


	// == build top list of smallest files =======================================
	added_count = 0;
	index = 0;

	while (index < GScanEngine->Data[DataSource].Files.size() && added_count <= 101)
	{
		if (!(faDirectory & GScanEngine->Data[DataSource].Files[index]->Attributes))
		{
			FileObject *fo = GScanEngine->Data[DataSource].Files[index];

			gridsmall->Cells[0][gridsmall->RowCount - 1] = (GScanEngine->Data[DataSource].Folders[fo->FilePathIndex] + fo->Name).c_str();

			switch (date_type)
			{
			case kDatePropertyCreated:
				gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::IntDateToString(fo->DateCreated).c_str();
				break;
			case kDatePropertyAccessed:
				gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::IntDateToString(fo->DateAccessed).c_str();
				break;
			case kDatePropertyModified:
				gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::IntDateToString(fo->DateModified).c_str();
				break;
			}

			gridsmall->Cells[2][gridsmall->RowCount - 1] = Convert::ConvertToUsefulUnit(fo->Size).c_str();
			gridsmall->Cells[3][gridsmall->RowCount - 1] = GScanEngine->Data[DataSource].Users[fo->Owner]->Name.c_str();
			gridsmall->Cells[4][gridsmall->RowCount - 1] = GSettingsHandler->FileCategoryColors[fo->Category];

			gridsmall->RowCount++;

			added_count++;
		}

		index++;
	}

	gridsmall->RowCount--;

	gridbig->EndUpdate();
	gridsmall->EndUpdate();

	if (GScanEngine->Data[DataSource].TotalSize != 0 && GScanEngine->Data[DataSource].FileCount != 0)
	{
		return std::to_wstring(gridbig->RowCount - 1) + L" " +
			   GLanguageHandler->Text[kFiles] + L" (" +
			   Convert::DoubleToPercent((double)(gridbig->RowCount - 1) / (double)GScanEngine->Data[DataSource].FileCount) + L"), " +
			   Convert::ConvertToUsefulUnit(TopSize) + L" (" + Convert::DoubleToPercent((double)TopSize / (double)GScanEngine->Data[DataSource].TotalSize) + L")";
	}

	return std::to_wstring(gridbig->RowCount - 1) + L" " +
		   GLanguageHandler->Text[kFiles] + L" (100%), " + Convert::ConvertToUsefulUnit(TopSize) + L" (100%)";
}


// assumes data is sorted from low to high
std::wstring TabUiTop101::Size(TStringGrid* gridbig, TStringGrid* gridsmall, XIceCream *ice, int DataSource, int user_id)
{
	if (GScanEngine->Data[DataSource].FileCount == 0) return L"n/a";

//	if XSettings.Forms.ProgressForm <> Nil then
//	  XSettings.Forms.ProgressForm.SetProcessText(XText[kBuilding] + ' ' + XText[kTop101]);

	GScanEngine->Data[DataSource].SortByProperty(SortMode::kSize);

	GridUtility::Clear(gridbig, false);
	GridUtility::Clear(gridsmall, false);

	gridbig->BeginUpdate();
	gridsmall->BeginUpdate();

	// == build top list of largest files ========================================
	int added_count = 0;
	int index = GScanEngine->Data[DataSource].Files.size() - 1;
	unsigned __int64 TopSize = 0;

	while (index >= 0 && added_count <= 101)
	{
		bool CanAdd = false;

		if (!(faDirectory & GScanEngine->Data[DataSource].Files[index]->Attributes))
		{
			if (user_id == -1)
			{
				CanAdd = true;
			}
			else
			{
				CanAdd = (GScanEngine->Data[DataSource].Files[index]->Owner == user_id);
			}

			if (CanAdd)
			{
				FileObject *fo = GScanEngine->Data[DataSource].Files[index];

				gridbig->Cells[0][gridbig->RowCount - 1] = (GScanEngine->Data[DataSource].Folders[fo->FilePathIndex] + fo->Name).c_str();
				gridbig->Cells[1][gridbig->RowCount - 1] = Convert::ConvertToUsefulUnit(fo->Size).c_str();
				gridbig->Cells[2][gridbig->RowCount - 1] = GScanEngine->Data[DataSource].Users[fo->Owner]->Name.c_str();
				gridbig->Cells[3][gridbig->RowCount - 1] = GSettingsHandler->FileCategoryColors[fo->Category];

				gridbig->RowCount++;

				added_count++;
				TopSize += fo->Size;
			}
		}

		index--;
	}

	gridbig->RowCount--;

	ice->Clear();

	if (GScanEngine->Data[DataSource].TotalSize != 0 && GScanEngine->Data[DataSource].FileCount != 0)
	{
		ice->Begin();

		ice->Add(0, ((TopSize / GScanEngine->Data[DataSource].TotalSize) * 100),
						 L"Top 101",
						 Convert::ConvertToUsefulUnit(TopSize),
						 0x002288FF);

		ice->Add(0, 100 - ((TopSize / GScanEngine->Data[DataSource].TotalSize) * 100),
						 L"Others",
						 Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSize - TopSize),
						 0x00AAAAAA);

		ice->End();
	}

	// == build top list of smallest files =======================================
	added_count = 0;
	index = 0;

	while (index < GScanEngine->Data[DataSource].Files.size() && added_count <= 100)
	{
		if (!(faDirectory & GScanEngine->Data[DataSource].Files[index]->Attributes))
		{
			FileObject *fo = GScanEngine->Data[DataSource].Files[index];

			gridsmall->Cells[0][gridsmall->RowCount - 1] = (GScanEngine->Data[DataSource].Folders[fo->FilePathIndex] + fo->Name).c_str();
			gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::ConvertToUsefulUnit(fo->Size).c_str();
			gridsmall->Cells[2][gridsmall->RowCount - 1] = GSettingsHandler->FileCategoryColors[fo->Category];

			gridsmall->RowCount++;

			added_count++;
		}

		index++;
	}

	gridsmall->RowCount--;

	gridsmall->EndUpdate();
	gridbig->EndUpdate();

	if (GScanEngine->Data[DataSource].TotalSize != 0 && GScanEngine->Data[DataSource].FileCount != 0)
	{
		return std::to_wstring(gridbig->RowCount - 1) + L" " +
			   GLanguageHandler->Text[kFiles] + L" (" +
			   Convert::DoubleToPercent((double)(gridbig->RowCount - 1) / (double)GScanEngine->Data[DataSource].FileCount) + L"), " +
			   Convert::ConvertToUsefulUnit(TopSize) + L" (" + Convert::DoubleToPercent((double)TopSize / (double)GScanEngine->Data[DataSource].TotalSize) + L")";
	}

	return std::to_wstring(gridbig->RowCount - 1) + L" " +
		   GLanguageHandler->Text[kFiles] + L" (100%), " + Convert::ConvertToUsefulUnit(TopSize) + L" (100%)";
}
