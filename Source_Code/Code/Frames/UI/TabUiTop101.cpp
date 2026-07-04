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
#include "TabUiTop101.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


std::wstring TabUiTop101::Date(TStringGrid* gridbig, TStringGrid* gridsmall, const std::wstring user_name, int date_type)
{
	if (GScanEngine->Data.FileCount == 0) return L"n/a";

//	if XSettings.Forms.ProgressForm <> Nil then
//      XSettings.Forms.ProgressForm.SetProcessText(XText[kBuilding] + ' ' + XText[kTop101]);

	switch (date_type)
	{
	case 0:
		GScanEngine->SortByProperty(0);
		break;
	case 1:
		GScanEngine->SortByProperty(1);
		break;
	case 2:
		GScanEngine->SortByProperty(2);
		break;
	}

//	TGridUtility.ClearStringGird(gridbig, False);
//	TGridUtility.ClearStringGird(oTopSmall, False);

	gridbig->BeginUpdate();
	gridsmall->BeginUpdate();

	// == build top list of largest files ========================================
	int added_count = 0;
	int index = GScanEngine->Data.Files.size() - 1;
	unsigned __int64 TopSize = 0;

	while (index >= 0 && added_count <= 100)
	{
		 if (!(faDirectory & GScanEngine->Data.Files[index].Attributes))
		 {
            bool CanAdd = false;

			if (user_name == L"")
			{
				CanAdd = true;
			}
			else
			{
				CanAdd = (GScanEngine->Data.Users[GScanEngine->Data.Files[index].Owner].Name == user_name);
			}

			if (CanAdd)
			{
				FileObject fo = GScanEngine->Data.Files[index];

				gridbig->Cells[0][gridbig->RowCount - 1] = (GScanEngine->Data.Folders[fo.FilePathIndex] + fo.Name).c_str();

				switch (date_type)
				{
				case kCreatedDate:
					gridbig->Cells[1][gridbig->RowCount - 1] = Convert::IntDateToString(fo.DateCreated).c_str();
					break;
				case kAccessedDate:
					gridbig->Cells[1][gridbig->RowCount - 1] = Convert::IntDateToString(fo.DateAccessed).c_str();
					break;
				case kModifiedDate:
					gridbig->Cells[1][gridbig->RowCount - 1] = Convert::IntDateToString(fo.DateModified).c_str();
					break;
				}

				gridbig->Cells[2][gridbig->RowCount - 1] = Convert::ConvertToUsefulUnit(fo.Size).c_str();
				gridbig->Cells[3][gridbig->RowCount - 1] = GScanEngine->Data.Users[fo.Owner].Name.c_str();
//				gridbig->Cells[CTopBigFileName, ][gridbig->RowCount - 1] = IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanDetails[aDataIndex].Files.Items[t].FileName));
//				gridbig->Cells[CTopBigFileSizeAB][gridbig->RowCount - 1] = IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize);

				gridbig->RowCount++;

				added_count++;
				TopSize += fo.Size;
			}
		}

		index--;
	}

	gridbig->RowCount--;


	// == build top list of smallest files =======================================
	added_count = 0;
	index = 0;

	while (index < GScanEngine->Data.Files.size() && added_count <= 100)
	{
		if (!(faDirectory & GScanEngine->Data.Files[index].Attributes))
		{
			FileObject fo = GScanEngine->Data.Files[index];

			gridsmall->Cells[0][gridsmall->RowCount - 1] = (GScanEngine->Data.Folders[fo.FilePathIndex] + fo.Name).c_str();

			switch (date_type)
			{
			case kCreatedDate:
				gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::IntDateToString(fo.DateCreated).c_str();
				break;
			case kAccessedDate:
				gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::IntDateToString(fo.DateAccessed).c_str();
				break;
			case kModifiedDate:
				gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::IntDateToString(fo.DateModified).c_str();
				break;
			}

			gridsmall->Cells[2][gridsmall->RowCount - 1] = Convert::ConvertToUsefulUnit(fo.Size).c_str();
			gridsmall->Cells[3][gridsmall->RowCount - 1] = GScanEngine->Data.Users[fo.Owner].Name.c_str();
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

	if (GScanEngine->Data.TotalSize != 0 && GScanEngine->Data.FileCount != 0)
	{
		return std::to_wstring(gridbig->RowCount - 1) + L" " +
			   GLanguageHandler->Text[kFiles] + L" (" +
			   Convert::DoubleToPercent((double)(gridbig->RowCount - 1) / (double)GScanEngine->Data.FileCount) + L"), " +
			   Convert::ConvertToUsefulUnit(TopSize) + L" (" + Convert::DoubleToPercent((double)TopSize / (double)GScanEngine->Data.TotalSize) + L")";
	}

	return std::to_wstring(gridbig->RowCount - 1) + L" " +
		   GLanguageHandler->Text[kFiles] + L" (100%), " + Convert::ConvertToUsefulUnit(TopSize) + L" (100%)";
}


// assumes data is sorted from low to high
std::wstring TabUiTop101::FileSize(TStringGrid* gridbig, TStringGrid* gridsmall, const std::wstring user_name)
{
	if (GScanEngine->Data.FileCount == 0) return L"n/a";

//	if XSettings.Forms.ProgressForm <> Nil then
//	  XSettings.Forms.ProgressForm.SetProcessText(XText[kBuilding] + ' ' + XText[kTop101]);

	// to do GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileSizes));

//	TGridUtility.ClearStringGird(gridbig, False);
//	TGridUtility.ClearStringGird(oTableSmall, False);

	gridbig->BeginUpdate();
	gridsmall->BeginUpdate();

	// == build top list of largest files ========================================
	int added_count = 0;
	int index = GScanEngine->Data.Files.size() - 1;
	unsigned __int64 TopSize = 0;

	while (index >= 0 && added_count <= 100)
	{
		bool CanAdd = false;

		if (!(faDirectory & GScanEngine->Data.Files[index].Attributes))
		{
			if (user_name == L"")
			{
				CanAdd = true;
			}
			else
			{
				CanAdd = (GScanEngine->Data.Users[GScanEngine->Data.Files[index].Owner].Name == user_name);
			}

			if (CanAdd)
			{
				FileObject fo = GScanEngine->Data.Files[index];

				gridbig->Cells[0][gridbig->RowCount - 1] = (GScanEngine->Data.Folders[fo.FilePathIndex] + fo.Name).c_str();
				gridbig->Cells[1][gridbig->RowCount - 1] = Convert::ConvertToUsefulUnit(fo.Size).c_str();
				gridbig->Cells[2][gridbig->RowCount - 1] = GScanEngine->Data.Users[fo.Owner].Name.c_str();
//				gridbig->Cells[3][gridbig.RowCount - 1] := IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize);
//				gridbig->Cells[4][gridbig.RowCount - 1] := IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanDetails[aDataIndex].Files.Items[t].FileName));

				gridbig->RowCount++;

				added_count++;
			 	TopSize += fo.Size;
			}
		}

		index--;
	}

	gridbig->RowCount--;

	/*oCapacityBar.Items.Clear;

	if (GScanEngine->Data.TotalSize != 0 && GScanEngine->Data.Count != 0)
	{
	  Result := IntToStr(oTableBig.RowCount - 1) + ' ' +
						 XText[kFiles] + ' (' +
						 TConvert.RealToPercent((oTableBig.RowCount - 1) /GScanDetails[aDataIndex].FileCount) + '), ' +
						 TConvert.ConvertToUsefulUnit(TopSize) + ' (' + TConvert.RealToPercent(TopSize / GScanDetails[aDataIndex].TotalSize) + ')';

	  lCapacityItem             := oCapacityBar.Items.Add;
	  lCapacityItem.Value       := (TopSize /GScanDetails[aDataIndex].TotalSize * 100);
	  lCapacityItem.Color       := $00FF8822;
	  lCapacityItem.ColorTo     := $00FF8822;
	  lCapacityItem.DisplayName := 'Top 101';
	  lCapacityItem.Description := 'Top 101';
	  lCapacityItem.Hint        := 'Top 101  (' + TConvert.ConvertToUsefulUnit(TopSize) + ')';

	  lCapacityItem             := oCapacityBar.Items.Add;
	  lCapacityItem.Value       := 100 - ((TopSize /GScanDetails[aDataIndex].TotalSize * 100));
	  lCapacityItem.Color       := $00AAAAAA;
	  lCapacityItem.ColorTo     := $00AAAAAA;
	  lCapacityItem.DisplayName := 'Others';
	  lCapacityItem.Description := 'Others';
	  lCapacityItem.Hint        := 'Others  (' + TConvert.ConvertToUsefulUnit(TopSize -GScanEngine[aDataIndex].TotalSize) + ')';
	end
	else
	  Result := IntToStr(oTableBig.RowCount - 1) + ' ' + XText[kFiles] + ' (100%), ' + TConvert.ConvertToUsefulUnit(TopSize) + ' (100%)'; */

	// == build top list of smallest files =======================================
	added_count = 0;
	index = 0;

	while (index < GScanEngine->Data.Files.size() && added_count <= 100)
	{
		if (!(faDirectory & GScanEngine->Data.Files[index].Attributes))
		{
			FileObject fo = GScanEngine->Data.Files[index];

			gridsmall->Cells[0][gridsmall->RowCount - 1] = (GScanEngine->Data.Folders[fo.FilePathIndex] + fo.Name).c_str();
			gridsmall->Cells[1][gridsmall->RowCount - 1] = Convert::ConvertToUsefulUnit(fo.Size).c_str();
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

	if (GScanEngine->Data.TotalSize != 0 && GScanEngine->Data.FileCount != 0)
	{
		return std::to_wstring(gridbig->RowCount - 1) + L" " +
			   GLanguageHandler->Text[kFiles] + L" (" +
			   Convert::DoubleToPercent((double)(gridbig->RowCount - 1) / (double)GScanEngine->Data.FileCount) + L"), " +
			   Convert::ConvertToUsefulUnit(TopSize) + L" (" + Convert::DoubleToPercent((double)TopSize / (double)GScanEngine->Data.TotalSize) + L")";
	}

	return std::to_wstring(gridbig->RowCount - 1) + L" " +
		   GLanguageHandler->Text[kFiles] + L" (100%), " + Convert::ConvertToUsefulUnit(TopSize) + L" (100%)";
}
