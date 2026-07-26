//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <algorithm>

#include "XFormMoreDetail.h"

#include "ConstantsGui.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm16 *Form16;
//---------------------------------------------------------------------------
__fastcall TForm16::TForm16(TComponent* Owner)
	: TForm(Owner)
{
}


void OpenMoreDetails(int index, const std::wstring path)
{
	Form16->DirectoryList.push_back(path);

	Form16->ExplorePath = path;
	Form16->DataSource = index;

  	Form16->Show();
}


void __fastcall TForm16::FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
		  int &MaxWidth, int &MaxHeight)
{
	MinWidth  = 500;
	MinHeight = 210;
}


void __fastcall TForm16::FormShow(TObject *Sender)
{
	Screen->Cursor = crHourGlass;

	BuildFrom(DirectoryList[0]);

	FormResize(NULL);

	Screen->Cursor = crDefault;
}


void __fastcall TForm16::FormResize(TObject *Sender)
{
	sgExplore->ColWidths[0] = 18;
	sgExplore->ColWidths[1] = sgExplore->Width - 351;
	sgExplore->ColWidths[2] = 42;
	sgExplore->ColWidths[3] = 102;
	sgExplore->ColWidths[4] = 4;
	sgExplore->ColWidths[5] = 62;
	sgExplore->ColWidths[6] = 102;
}


void __fastcall TForm16::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormExplore, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	DirectoryList.clear();

//	if (FULSP)
//	{
//		FULSP(kFormExplore);
//    }

	Action = caHide;
}


void TForm16::Init()
{
	std::wstring things[3];
	things[0] = GLanguageHandler->Text[kOn];
	things[1] = GLanguageHandler->Text[kBefore];
	things[2] = GLanguageHandler->Text[kAfter];

	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormExplore);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}

	sgExplore->Canvas->Brush->Color = TColor(0x00FF4400);

	sgExplore->Cells[kColFolderName][0]     = GLanguageHandler->Text[kFolder].c_str();
	sgExplore->Cells[kColFileCount][0]      = (L"# " + GLanguageHandler->Text[kFiles]).c_str();
	sgExplore->Cells[kColFilesAsPercent][0] = GLanguageHandler->Text[kAsPercent].c_str();
	sgExplore->Cells[kColSize][0]           = GLanguageHandler->Text[kSize].c_str();
	sgExplore->Cells[kColSizeAsPercent][0]  = GLanguageHandler->Text[kAsPercent].c_str();

//	sgExplore.HideColumn(7);
//	sgExplore.HideColumn(8);
//	sgExplore.HideColumn(9);

	// ===========================================================================

	miExploreFolder->Caption  = GLanguageHandler->Text[kExploreFolder].c_str();

	// ===========================================================================

	cbSLTUnit->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbSLTUnit->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbSLTUnit->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbSLTUnit->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());
	cbSLTUnit->ItemIndex = 0;

	cbSGTUnit->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbSGTUnit->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbSGTUnit->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbSGTUnit->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());
	cbSGTUnit->ItemIndex = 0;

	// ===========================================================================

	bHelp->Caption         = GLanguageHandler->Text[kHelp].c_str();
	bClose->Caption        = GLanguageHandler->Text[kClose].c_str();

	cbContainingText->Caption  = GLanguageHandler->Text[kContainingText].c_str();
	cbFileSize->Caption        = GLanguageHandler->Text[kFileSize].c_str();
	cbCategory->Caption        = GLanguageHandler->Text[kCategory].c_str();
	cbFileAttributes->Caption  = GLanguageHandler->Text[kFileAttributes].c_str();
	cbCreatedDate->Caption     = GLanguageHandler->Text[kCreatedDate].c_str();
	cbAccessedDate->Caption    = GLanguageHandler->Text[kAccessedDate].c_str();
	cbModifiedDate->Caption    = GLanguageHandler->Text[kModifiedDate].c_str();
	cbFileOwner->Caption       = GLanguageHandler->Text[kFileOwner].c_str();
	cbNameLength->Caption      = GLanguageHandler->Text[kFileNameLength].c_str();

	lContaining->Caption   = GLanguageHandler->Text[kContains].c_str();

	sbProg->Caption        = GLanguageHandler->TypeDescriptions[1].c_str();
	sbSys->Caption         = GLanguageHandler->TypeDescriptions[2].c_str();
	sbGfx->Caption         = GLanguageHandler->TypeDescriptions[3].c_str();
	sbMovie->Caption       = GLanguageHandler->TypeDescriptions[4].c_str();
	sbSnd->Caption         = GLanguageHandler->TypeDescriptions[5].c_str();
	sbOffice->Caption      = GLanguageHandler->TypeDescriptions[6].c_str();
	sbCode->Caption        = GLanguageHandler->TypeDescriptions[7].c_str();
	sbCompressed->Caption  = GLanguageHandler->TypeDescriptions[8].c_str();
	sbOther->Caption       = GLanguageHandler->TypeDescriptions[9].c_str();
	sbCustom1->Caption     = GLanguageHandler->TypeDescriptions[10].c_str();
	sbCustom2->Caption     = GLanguageHandler->TypeDescriptions[11].c_str();
	sbCustom3->Caption     = GLanguageHandler->TypeDescriptions[12].c_str();
	sbCustom4->Caption     = GLanguageHandler->TypeDescriptions[13].c_str();
	sbCustom5->Caption     = GLanguageHandler->TypeDescriptions[14].c_str();
	sbCustom6->Caption     = GLanguageHandler->TypeDescriptions[15].c_str();
	sbCustom7->Caption     = GLanguageHandler->TypeDescriptions[16].c_str();
	sbCustom8->Caption     = GLanguageHandler->TypeDescriptions[17].c_str();
	sbCustom9->Caption     = GLanguageHandler->TypeDescriptions[18].c_str();
	sbCustom10->Caption    = GLanguageHandler->TypeDescriptions[19].c_str();

	cbAHidden->Caption     = GLanguageHandler->LanguageTypes[1].c_str();
	cbASystem->Caption     = GLanguageHandler->LanguageTypes[2].c_str();
	cbAArchive->Caption    = GLanguageHandler->LanguageTypes[3].c_str();
	cbAReadOnly->Caption   = GLanguageHandler->LanguageTypes[5].c_str();
	cbATemp->Caption       = GLanguageHandler->Text[kTemporary].c_str();

	bFilter->Caption       = GLanguageHandler->Text[kFilter].c_str();

	// ===========================================================================

	DateControls[0] = dtpCreated1;
	DateControls[1] = dtpCreated2;
	DateControls[2] = dtpAccessed1;
	DateControls[3] = dtpAccessed2;
	DateControls[4] = dtpModified1;
	DateControls[5] = dtpModified2;

	for (int t = 0; t < 6; t++)
	{
		DateControls[t]->DateTime = Now();
	}

	cbUSelect->Items->Add(GLanguageHandler->Text[kEqualTo].c_str());
	cbUSelect->Items->Add(GLanguageHandler->Text[kNotEqualTo].c_str());
	cbUSelect->Items->Add(GLanguageHandler->Text[kContains].c_str());
	cbUSelect->Items->Add(GLanguageHandler->Text[kDoesntContain].c_str());

	cbUSelect->ItemIndex = 0;

	for (int t = 0; t < 3; t++)
	{
		cbCreated1->Items->Add(things[t].c_str());
		cbCreated2->Items->Add(things[t].c_str());
		cbAccessed1->Items->Add(things[t].c_str());
		cbAccessed2->Items->Add(things[t].c_str());
		cbModified1->Items->Add(things[t].c_str());
		cbModified2->Items->Add(things[t].c_str());
	}

	cbCreated1->ItemIndex  = 0;
	cbCreated2->ItemIndex  = 0;
	cbAccessed1->ItemIndex = 0;
	cbAccessed2->ItemIndex = 0;
	cbModified1->ItemIndex = 0;
	cbModified2->ItemIndex = 0;

	CategoryControls[0]  = sbProg;    CategoryControls[1]  = sbSys;     CategoryControls[2]  = sbGfx;      CategoryControls[3]  = sbMovie;
	CategoryControls[4]  = sbSnd;     CategoryControls[5]  = sbOffice;  CategoryControls[6]  = sbCode;     CategoryControls[7]  = sbCompressed;
	CategoryControls[8]  = sbOther;   CategoryControls[9]  = sbCustom1; CategoryControls[10] = sbCustom2;  CategoryControls[11] = sbCustom3;
	CategoryControls[12] = sbCustom4; CategoryControls[13] = sbCustom5; CategoryControls[14] = sbCustom6;  CategoryControls[15] = sbCustom7;
	CategoryControls[16] = sbCustom8; CategoryControls[17] = sbCustom9; CategoryControls[18] = sbCustom10;
}


#pragma region LeftSide_Parameters
void __fastcall TForm16::cbContainingTextClick(TObject *Sender)
{
	TCheckBox *cb = (TCheckBox*)Sender;

	TPanel *panel = (TPanel*)cb->Parent;

	if (cb->Checked)
	{
		panel->Height = 24;

		cb->Font->Style.Clear();
		cb->Checked = false;
	}
	else
	{
		panel->Height = PanelHeights[cb->Tag];

		cb->Font->Style.Clear();
		cb->Checked = true;
	}

	CheckForValidSearch();

	bFilterClick(NULL);
}
#pragma end_region



/*


procedure TfrmExplore.sgExploreGetAlignment(Sender: TObject; ARow,
  ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
{
  if (ACol = colFileCount) or (ACol = colSize) then
    HAlign = taRightJustify
  else
    HAlign = taLeftJustify;
}


procedure TfrmExplore.sgExploreGetCellColor(Sender: TObject; ARow,
  ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
{
  if gdSelected in AState then
	ABrush.Color = CGridColourSelected
  else {
    if Odd(ARow) then
      ABrush.Color = CGridColourOn
    else
	  ABrush.Color = CGridColourOff;
  }
}



procedure TfrmExplore.sgExploreCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
 {
  if (Acol = colFilesAsPercent) then {
    DoSort = False;

    with TAdvStringGrid(Sender) do {
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction = sdAscending
      else
        SortSettings.Direction = sdDescending;

      Sortsettings.Column = colFileCount;
      QSort;
      SortSettings.Column = Acol;
    }
  end
  else if (Acol = colSize) or (ACol = colSizeAsPercent) then {
    DoSort = False;

    with TAdvStringGrid(Sender) do {
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction = sdAscending
      else
        SortSettings.Direction = sdDescending;

      Sortsettings.Column = colSizeCache;
      QSort;
      SortSettings.Column = Acol;
    }
  }
}



*/
void __fastcall TForm16::sbBackClick(TObject *Sender)
{
	DirectoryList.pop_back();

	BuildFrom(DirectoryList[DirectoryList.size() - 1]);

	if (DirectoryList.size() == 1)
	{
		sbBack->Enabled = false;
	}
}


void __fastcall TForm16::sgExploreDblClick(TObject *Sender)
{
	if (sgExplore->Cells[kColFolderName][sgExplore->Selection.Top] != L"\\")
	{
		std::wstring folder = sgExplore->Cells[kColFolderName][sgExplore->Selection.Top].c_str();

		DirectoryList.push_back(DirectoryList[DirectoryList.size() - 1] + folder + L"\\");

		BuildFrom(DirectoryList[DirectoryList.size() - 1]);

		sbBack->Enabled = true;
	}
	else
	{
		if (sbBack->Enabled)
		{
			sbBackClick(NULL);
		}
	}
}


void __fastcall TForm16::sgExploreDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	if (ARow == 0) return;

	switch (ACol)
	{
	case kColIcon:
		//ilExplore.Draw(TAdvStringGrid(Sender).Canvas, Rect.Left + 1, Rect.Top, 0, True);
		break;
	case kColFilesAsPercent:
		/*TAdvStringGrid(Sender).Canvas.Brush.Color = XSettings.Navigation.BarColours[5];
		TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

		if TAdvStringGrid(Sender)->Cells[colFileCountPCache, ARow] != "0" then {
		  zRect.Top    = Rect.Top + 1;
		  zRect.Bottom = Rect.Bottom - 1;
		  zRect.Left   = Rect.Left + 1;
		  zRect.Right  = Rect.Left + StrToInt(TAdvStringGrid(Sender)->Cells[colFileCountPCache, ARow]);

		  TAdvStringGrid(Sender).Canvas.Brush.Color = XSettings.Navigation.BarColours[6];
		  TAdvStringGrid(Sender).Canvas.FillRect(zRect);
		}

		TAdvStringGrid(Sender).Canvas.Brush.Style = bsClear;
		TAdvStringGrid(Sender).Canvas.Font.Color  = clBlack;
		TAdvStringGrid(Sender).Canvas.TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender)->Cells[colFilesAsPercent, ARow]); */
		break;
	case kColSizeAsPercent:
		/*TAdvStringGrid(Sender).Canvas.Brush.Color = XSettings.Navigation.BarColours[5];
		TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

		if (TAdvStringGrid(Sender)->Cells[colSizePCache, ARow] != "0")
		{
			zRect.Top    = Rect.Top + 1;
			zRect.Bottom = Rect.Bottom - 1;
			zRect.Left   = Rect.Left + 1;
			zRect.Right  = Rect.Left + StrToInt(TAdvStringGrid(Sender)->Cells[colSizePCache, ARow]);

			TAdvStringGrid(Sender).Canvas.Brush.Color = XSettings.Navigation.BarColours[6];
			TAdvStringGrid(Sender).Canvas.FillRect(zRect);
		}

		TAdvStringGrid(Sender).Canvas.Brush.Style = bsClear;
		TAdvStringGrid(Sender).Canvas.Font.Color  = clBlack;
		TAdvStringGrid(Sender).Canvas.TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender)->Cells[colSizeAsPercent, ARow]);*/
		break;
	}
}


void __fastcall TForm16::bFilterClick(TObject *Sender)
{
	BuildFrom(DirectoryList[DirectoryList.size() - 1]);
}


void __fastcall TForm16::cbUSelectChange(TObject *Sender)
{
	if (cbUSelect->ItemIndex == 0)
	{
		eUContent->Enabled = false;
	}
	else
	{
		eUContent->Enabled = true;
	}
}


void __fastcall TForm16::eSLTEnter(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	OldText = edit->Text.c_str();
}


void __fastcall TForm16::eSLTExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int value = StrToIntDef(edit->Text, -1);

	if (value == -1)
	{
		edit->Text = OldText.c_str();
	}
}


void __fastcall TForm16::bHelpClick(TObject *Sender)
{
	//Help.OpenHelpPage("a41.htm");
}


void __fastcall TForm16::miExploreFolderClick(TObject *Sender)
{
	std::wstring s = DirectoryList[DirectoryList.size() - 1] + sgExplore->Cells[kColFolderName][sgExplore->Selection.Top].c_str() + L"\\";

	if (!s.empty())
	{
		WindowsUtility::ExecuteFile(s, L"");
	}
}


void TForm16::CheckForValidSearch()
{
	if (cbContainingText->Checked || cbCreatedDate->Checked || cbAccessedDate->Checked || cbModifiedDate->Checked ||
		cbFileSize->Checked || cbCategory->Checked || cbFileOwner->Checked || cbFileAttributes->Checked || cbNameLength->Checked)
	{
		bFilter->Enabled = true;
	}
	else
	{
		bFilter->Enabled = false;
	}
}


void TForm16::BuildFrom(const std::wstring path)
{
	auto GetInnerDirectory = [path](const std::wstring s) -> std::wstring
	{
		std::wstring found_path = L"";
		bool keepadding = true;

		for (int t = path.size() + 1; t < s.size(); t++)
		{
			if (s[t] == L'\\')
			{
				keepadding = false;
			}

			if (keepadding)
			{
				//found_path += s[t];
			}
		}

		if (keepadding)
		{
			return L"\\";
		}

		return found_path;
	};

	//Assert((FDataIndex >= 0) and (FDataIndex <= 1), "TfrmExplore->BuildFrom :: invalid dataindex :: " + std::to_wstring(FDataIndex));

	Caption = (GLanguageHandler->Text[kExploring] + L": " + path).c_str();

	sgExplore->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;

	std::vector<std::wstring> DirCache;
	std::vector<std::wstring> SizeCache;
	std::vector<std::wstring> NumberCache;

	DirCache.push_back(L"\\");
	SizeCache.push_back(L"0");
	NumberCache.push_back(L"0");

	unsigned __int64 TotalSize = 0;
	int TotalFCount = 0;
	int TotalDCount = 0;

	sgExplore->BeginUpdate();

	for (FileObject *file : GScanEngine->Data[DataSource].Files)
	{
		if (path.compare(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name) == 0)
		{
			if (faDirectory & file->Attributes)
			{
				std::wstring tempdir = GetInnerDirectory(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name);

				auto dci = std::find(DirCache.begin(), DirCache.end(), tempdir);

				if (dci == DirCache.end())
				{
					DirCache.push_back(tempdir);
					SizeCache.push_back(std::to_wstring(file->Size));
					NumberCache.push_back(L"0");   // ignore folders
				}
				else
				{
					int index = std::distance(std::begin(DirCache), dci);

					SizeCache[index] = std::to_wstring(stoi(SizeCache[index]) + file->Size);
					//NumberCache.Strings[index]=std::to_wstring(StrToInt(NumberCache.Strings[dci]) + 1); // ignore folders
				}

				TotalSize += file->Size;
				TotalDCount++;
			}
			else
			{
				bool OKToAdd      = true;
				bool CategoryAdd  = true;
				bool AttributeAdd = true;

				//== check for size ====================================================

				if (cbContainingText->Checked)
				{
					if (eContaining->Text != L"")
					{
						std::wstring contentuc = eUContent->Text.c_str();
						std::wstring file_name = GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name;

						std::transform(contentuc.begin(), contentuc.end(), contentuc.begin(), ::toupper);
						std::transform(file_name.begin(), file_name.end(), file_name.begin(), ::toupper);

						if (file_name.find(contentuc) == std::wstring::npos) OKToAdd = false;
					}
				}

				//== check for size ====================================================

				if (cbFileSize->Checked)
				{
					unsigned __int64 temp_size = 0;

					if (eSLT->Text != L"")
					{
						temp_size = eSLT->Text.ToIntDef(0);

						switch (cbSLTUnit->ItemIndex)
						{
						case kUnitsBytes    : if (!(file->Size <= temp_size))                        OKToAdd = false; break;
						case kUnitsKilobytes: if (!(file->Size <= (temp_size * 1024)))               OKToAdd = false; break;
						case kUnitsMegabytes: if (!(file->Size <= (temp_size * 1024 * 1024)))        OKToAdd = false; break;
						case kUnitsGigabytes: if (!(file->Size <= (temp_size * 1024 * 1024 * 1024))) OKToAdd = false; break;
						}
                    }
				}

				if (eSGT->Text != L"")
				{
					unsigned __int64 temp_size = 0;

					if (eSGT->Text != L"")
					{
						temp_size = eSGT->Text.ToIntDef(0);

						switch (cbSGTUnit->ItemIndex)
						{
						case kUnitsBytes    : if (!(file->Size >= temp_size))                        OKToAdd = false; break;
						case kUnitsKilobytes: if (!(file->Size >= (temp_size * 1024)))               OKToAdd = false; break;
						case kUnitsMegabytes: if (!(file->Size >= (temp_size * 1024 * 1024)))        OKToAdd = false; break;
						case kUnitsGigabytes: if (!(file->Size >= (temp_size * 1024 * 1024 * 1024))) OKToAdd = false; break;
						}
					}
				}

				//== check for category ================================================

				if (cbCategory->Checked)
				{
					CategoryAdd = false;

					for (int i = 0; i < 19; i++)
					{
						if (CategoryControls[i]->Checked && file->Category == i)
						{
							CategoryAdd = true;
						}
					}
				}

				//== check for category ================================================

				if (cbFileAttributes->Checked)
				{
					AttributeAdd = false;

					if (cbAHidden->Checked)   if (faHidden & file->Attributes)   AttributeAdd = true;
					if (cbASystem->Checked)   if (faSysFile & file->Attributes)  AttributeAdd = true;
					if (cbAArchive->Checked)  if (faArchive & file->Attributes)  AttributeAdd = true;
					if (cbAReadOnly->Checked) if (faReadOnly & file->Attributes) AttributeAdd = true;

					if (cbATemp->Checked)     if (file->Temp) AttributeAdd = true;
				}

				//== check for created date ============================================

				if (cbCreatedDate->Checked)
				{
					if (cbCreated1->ItemIndex != 0)
					{
						switch (cbCreated1->ItemIndex)
						{
						case 1: if (Convert::DateToYYYYMMDDI(dtpCreated1->Date) != file->DateCreated) OKToAdd = false; break;
						case 2: if (Convert::DateToYYYYMMDDI(dtpCreated1->Date) >= file->DateCreated) OKToAdd = false; break;
						case 3: if (Convert::DateToYYYYMMDDI(dtpCreated1->Date) <= file->DateCreated) OKToAdd = false; break;
						}
					}

					if (cbCreated2->ItemIndex != 0)
					{
						switch (cbCreated2->ItemIndex)
						{
						case 1: if (Convert::DateToYYYYMMDDI(dtpCreated2->Date) != file->DateCreated) OKToAdd = false; break;
						case 2: if (Convert::DateToYYYYMMDDI(dtpCreated2->Date) >= file->DateCreated) OKToAdd = false; break;
						case 3: if (Convert::DateToYYYYMMDDI(dtpCreated2->Date) <= file->DateCreated) OKToAdd = false; break;
                        }
					}
				}

				//== check for created date ============================================

				if (cbAccessedDate->Checked)
				{
					if (cbAccessed1->ItemIndex != 0)
					{
						switch (cbAccessed1->ItemIndex)
						{
						case 1: if (Convert::DateToYYYYMMDDI(dtpAccessed1->Date) != file->DateAccessed) OKToAdd = false; break;
						case 2: if (Convert::DateToYYYYMMDDI(dtpAccessed1->Date) >= file->DateAccessed) OKToAdd = false; break;
						case 3: if (Convert::DateToYYYYMMDDI(dtpAccessed1->Date) <= file->DateAccessed) OKToAdd = false; break;
						}
					}
				}

				if (cbAccessed2->ItemIndex != 0)
				{
					switch (cbAccessed2->ItemIndex)
					{
					case 1: if (Convert::DateToYYYYMMDDI(dtpAccessed2->Date) != file->DateAccessed) OKToAdd = false; break;
					case 2: if (Convert::DateToYYYYMMDDI(dtpAccessed2->Date) >= file->DateAccessed) OKToAdd = false; break;
					case 3: if (Convert::DateToYYYYMMDDI(dtpAccessed2->Date) <= file->DateAccessed) OKToAdd = false; break;
					}
				}

				//== check for created date ============================================

				if (cbModifiedDate->Checked)
				{
					if (cbModified1->ItemIndex != 0)
					{
						switch (cbModified1->ItemIndex)
						{
						case 1: if (Convert::DateToYYYYMMDDI(dtpModified1->Date) != file->DateModified) OKToAdd = false; break;
						case 2: if (Convert::DateToYYYYMMDDI(dtpModified1->Date) >= file->DateModified) OKToAdd = false; break;
						case 3: if (Convert::DateToYYYYMMDDI(dtpModified1->Date) <= file->DateModified) OKToAdd = false; break;
						}
					}
				}

				if (cbModified2->ItemIndex != 0)
				{
					switch (cbModified2->ItemIndex)
					{
					case 1: if (Convert::DateToYYYYMMDDI(dtpModified2->Date) != file->DateModified) OKToAdd = false; break;
					case 2: if (Convert::DateToYYYYMMDDI(dtpModified2->Date) >= file->DateModified) OKToAdd = false; break;
					case 3: if (Convert::DateToYYYYMMDDI(dtpModified2->Date) <= file->DateModified) OKToAdd = false; break;
					}
				}

				//== check for created date ============================================

				if (cbFileOwner->Checked)
				{
					if (cbUSelect->ItemIndex != 0)
					{
						std::wstring contentuc = eUContent->Text.c_str();

						std::transform(contentuc.begin(), contentuc.end(), contentuc.begin(), ::toupper);

						switch (cbUSelect->ItemIndex)
						{
						case 1: if (GScanEngine->Data[DataSource].Users[file->Owner]->NameUC != contentuc) OKToAdd = false; break;
						case 2: if (GScanEngine->Data[DataSource].Users[file->Owner]->NameUC == contentuc) OKToAdd = false; break;
						case 3: if (GScanEngine->Data[DataSource].Users[file->Owner]->NameUC.find(contentuc) == std::wstring::npos) OKToAdd = false; break;
						case 4: if (GScanEngine->Data[DataSource].Users[file->Owner]->NameUC.find(contentuc) != std::wstring::npos) OKToAdd = false; break;
						}
					}
				}

				//== check for name lengths ============================================

				if (cbNameLength->Checked)
				{
					if (eNLLT->Text != L"")
					{
						int nl = StrToIntDef(eNLLT->Text, 300);

						if ((GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name).size() > nl)
						{
							OKToAdd = false;
						}
					}

					if (eNLGT->Text != L"")
					{
						int nl = StrToIntDef(eNLGT->Text, 1);

						if ((GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name).size() < nl)
						{
							OKToAdd = false;
						}
					}
				}

				//======================================================================
				//======================================================================

				if (OKToAdd && CategoryAdd && AttributeAdd)
				{
					std::wstring tempdir = GetInnerDirectory(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name);

					auto dci = std::find(DirCache.begin(), DirCache.end(), tempdir);

					if (dci == DirCache.end())
					{
						DirCache.push_back(tempdir);
						SizeCache.push_back(std::to_wstring(file->Size));
						NumberCache.push_back(L"1");
					}
					else
					{
						int index = std::distance(std::begin(DirCache), dci);

						SizeCache[index]   = std::to_wstring(stoi(SizeCache[index]) + file->Size);
						NumberCache[index] = std::to_wstring(stoi(NumberCache[index]) + 1);
					}

					TotalSize += file->Size;
					TotalFCount++;
				}
			}
		}
	}

	// build display
	sgExplore->RowCount = DirCache.size() + 1;

	for (int t = 0; t < DirCache.size(); t++)
	{
		sgExplore->Cells[kColFolderName][t + 1] = DirCache[t].c_str();
		sgExplore->Cells[kColFileCount][t + 1] = NumberCache[t].c_str();

		if (TotalFCount != 0)
		{
			double d = stoi(NumberCache[t]) / (double)TotalFCount;

			sgExplore->Cells[kColFilesAsPercent][t + 1] = (std::to_wstring(std::round(d * 100)) + L"%").c_str();
		}
		else
		{
			sgExplore->Cells[kColFilesAsPercent][t + 1] = L"n/a";
		}

		sgExplore->Cells[kColSize][t + 1] = Convert::ConvertToUsefulUnit(stoi(SizeCache[t])).c_str();
		sgExplore->Cells[kColSizeCache][t + 1] = SizeCache[t].c_str();

		if (TotalSize != 0)
		{
			double d = stoi(SizeCache[t]) / (double)TotalSize;

			sgExplore->Cells[kColSizeAsPercent][t + 1] = (std::to_wstring(std::round(d * 100)) + L"%").c_str();
		}
		else
		{
			sgExplore->Cells[kColSizeAsPercent][t + 1] = L"n/a";
		}

		if (TotalFCount != 0)
		{
			double d = stoi(NumberCache[t]) / (double)TotalFCount;

			sgExplore->Cells[kColFileCountPCache][t + 1] = std::to_wstring(std::round(d * 100)).c_str();
		}
		else
		{
			sgExplore->Cells[kColFileCountPCache][t + 1] = L"0";
		}

		if (TotalSize != 0)
		{
			double d = stoi(SizeCache[t]) / (double)TotalSize;

			sgExplore->Cells[kColSizePCache][t + 1] = std::to_wstring(std::round(d * 100)).c_str();
		}
		else
		{
			sgExplore->Cells[kColSizePCache][t + 1] = L"0";
		}
	}

//	lData.HTMLText[0] = "<b>" + std::to_wstring(TotalFCount) + "</b> " + GLanguageHandler->Text[kFiles] + "; <b>" + std::to_wstring(TotalDCount) + "</b> " + GLanguageHandler->Text[kFolders] + "; <b>" + Convert::ConvertToUsefulUnit(TotalSize) + "</b>";

	sgExplore->EndUpdate();
}


void __fastcall TForm16::cbCreated1Change(TObject *Sender)
{
	TComboBox *cb = (TComboBox*)Sender;

	if (cb->ItemIndex != 0)
	{
		DateControls[cb->Tag]->Enabled = true;
	}
	else
	{
		DateControls[cb->Tag]->Enabled = false;
	}
}//950
