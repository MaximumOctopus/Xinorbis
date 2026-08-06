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
#include "TabUiTop101.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


std::wstring TabUiTop101::Date(TStringGrid* gridbig, TStringGrid* gridsmall, int DataSource, int user_id, int date_type)
{
	if (GScanEngine->Data[DataSource].FileCount == 0) return L"n/a";

	switch (date_type)
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
				case kCreatedDate:
					gridbig->Cells[1][gridbig->RowCount - 1] = Convert::IntDateToString(fo->DateCreated).c_str();
					break;
				case kAccessedDate:
					gridbig->Cells[1][gridbig->RowCount - 1] = Convert::IntDateToString(fo->DateAccessed).c_str();
					break;
				case kModifiedDate:
					gridbig->Cells[1][gridbig->RowCount - 1] = Convert::IntDateToString(fo->DateModified).c_str();
					break;
				}

				gridbig->Cells[2][gridbig->RowCount - 1] = Convert::ConvertToUsefulUnit(fo->Size).c_str();
				gridbig->Cells[3][gridbig->RowCount - 1] = GScanEngine->Data[DataSource].Users[fo->Owner]->Name.c_str();
//				gridbig->Cells[CTopBigFileName, ][gridbig->RowCount - 1] = IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanDetails[aDataIndex].Files.Items[t].FileName));
//				gridbig->Cells[CTopBigFileSizeAB][gridbig->RowCount - 1] = IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize);

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
			case kCreatedDate:
				gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::IntDateToString(fo->DateCreated).c_str();
				break;
			case kAccessedDate:
				gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::IntDateToString(fo->DateAccessed).c_str();
				break;
			case kModifiedDate:
				gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::IntDateToString(fo->DateModified).c_str();
				break;
			}

			gridsmall->Cells[2][gridsmall->RowCount - 1] = Convert::ConvertToUsefulUnit(fo->Size).c_str();
			gridsmall->Cells[3][gridsmall->RowCount - 1] = GScanEngine->Data[DataSource].Users[fo->Owner]->Name.c_str();
//			gridsmall->Cells[CTopBigFileName, ][gridsmall->RowCount - 1] = IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanDetails[aDataIndex].Files.Items[t].FileName));
//			gridsmall->Cells[CTopBigFileSizeAB][gridsmall->RowCount - 1] = IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize);

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
std::wstring TabUiTop101::Size(TStringGrid* gridbig, TStringGrid* gridsmall, int DataSource, int user_id)
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
//				gridbig->Cells[3][gridbig.RowCount - 1] := IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize);
//				gridbig->Cells[4][gridbig.RowCount - 1] := IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanDetails[aDataIndex].Files.Items[t].FileName));

				gridbig->RowCount++;

				added_count++;
				TopSize += fo->Size;
			}
		}

		index--;
	}

	gridbig->RowCount--;

	/*icecream->Clear();

	if (GScanEngine->Data[DataSource].TotalSize != 0 && GScanEngine->Data[DataSource].Count != 0)
	{
		icecream->Begin();

		icecream->Add((TopSize /GScanDetails[aDataIndex].TotalSize * 100),
					  L"Top 101",
					  L"Top 101  (" + Convert::ConvertToUsefulUnit(TopSize) + L")",
					  0x00FF8822);

		icecream->Add(100 - ((TopSize /GScanDetails[aDataIndex].TotalSize * 100)),
					  L"Others",
					  L"Others  (" + Convert::ConvertToUsefulUnit(TopSize - GScanEngine->Data[DataSource].TotalSize) + L")",
					  0x00AAAAAA);

	  icecream->End();
	}*/

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
//			oTableSmall.Cells[2, oTableSmall.RowCount - 1] := IntToStr(GScanEngine[aDataIndex].Files.Items[t].FileSize);
//			oTableSmall.Cells[3, oTableSmall.RowCount - 1] := IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanEngine[aDataIndex].Files.Items[t].FileName));

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
