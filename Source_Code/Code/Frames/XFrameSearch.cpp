//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConstantsGui.h"
#include "ConstantsReports.h"

#include "XFrameSearch.h"

#include "XFormGetCopyMove.h"
#include "XFormXinorbisDialog.h"

#include "ConstantsData.h"
#include "FileExtensionHandler.h"
#include "GridUtility.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "Log.h"
#include "QuickMenuHandler.h"
#include "ReportHandler.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SplashHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"

extern FileExtensionHandler *GFileExtensionHandler;
extern Log *GLog;
extern LanguageHandler *GLanguageHandler;
extern QuickMenuHandler *GQuickMenuHandler;
extern ReportHandler *GReportHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;
extern SplashHandler *GSplashHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameSearch *FrameSearch;
//---------------------------------------------------------------------------
__fastcall TFrameSearch::TFrameSearch(TComponent* Owner)
	: TFrame(Owner)
{
	Init();
}


void __fastcall TFrameSearch::FrameResize(TObject *Sender)
{
	int total = 0;

	for (int t = 1; t < 13; t++)
	{
		if (sgSearchResults->ColWidths[t] != -1)
		{
			total += sgSearchResults->ColWidths[t];
		}
	}

	sgSearchResults->ColWidths[0] = sgSearchResults->Width - (total + __WidthOfScrollbar);
}


void TFrameSearch::Init()
{
	SearchDataChanged = false;

	GScanEngine->Data[DataTarget].Path.String = GLanguageHandler->Text[kSearch];

	lSearchDetails->Caption = GLanguageHandler->Text[kSearchResults].c_str();

	lGaugeQuantity->Caption = GLanguageHandler->Text[kBySize].c_str();

	lGaugeSize->Caption   = GLanguageHandler->Text[kByQuantity].c_str();

	tsSearch->Caption = GLanguageHandler->Text[kSearch].c_str();
	tsProperties->Caption = GLanguageHandler->Text[kDetail].c_str();

	sgSearchResults->DefaultRowHeight  = GSettingsHandler->Appearance.RowHeight;

	sgSearchResults->Cells[kschVFileName][0]   = GLanguageHandler->Text[kFileName].c_str();
	sgSearchResults->Cells[kschVSize][0]       = GLanguageHandler->Text[kSize].c_str();
	sgSearchResults->Cells[kschVCDate][0]      = GLanguageHandler->Text[kDate].c_str();

	sgSearchResults->Cells[kschVADate][0]      = GLanguageHandler->Text[kAccessed].c_str();
	sgSearchResults->Cells[kschVMDate][0]      = GLanguageHandler->Text[kModified].c_str();
	sgSearchResults->Cells[kschVOwner][0]      = GLanguageHandler->Text[kFileOwner].c_str();
	sgSearchResults->Cells[kschVAttributes][0] = GLanguageHandler->Text[kAttr].c_str();

	sgSearchResults->ColWidths[kschVADate] = -1;
	sgSearchResults->ColWidths[kschVMDate] = -1;
	sgSearchResults->ColWidths[kschVAttributes] = -1;
	sgSearchResults->ColWidths[kschVOwner] = -1;
	sgSearchResults->ColWidths[kschIFileName] = -1;
	sgSearchResults->ColWidths[kschISize] = -1;
	sgSearchResults->ColWidths[kschICDate] = -1;
	sgSearchResults->ColWidths[kschIADate] = -1;
	sgSearchResults->ColWidths[kschIMDate] = -1;
	sgSearchResults->ColWidths[kschIColour] = -1;

	cbSearchShowPath->Caption   = GLanguageHandler->Text[kShowFullPath].c_str();
	cbSearchColourCode->Caption = GLanguageHandler->Text[kColourCode].c_str();

	// ===========================================================================================

	miExploreDirectory->Caption = GLanguageHandler->Text[kExploreFolder].c_str();

	miSearchOpen->Caption       = GLanguageHandler->Text[kViewOpenFile].c_str();
	miSearchOpenCustom->Caption = GLanguageHandler->Text[kOpenWithCustomViewer].c_str();
	miExploreDirectory->Caption = GLanguageHandler->Text[kExploreFolder].c_str();
	miSFileProperties->Caption  = GLanguageHandler->Text[kFileProperties].c_str();
	miGenerateMD5->Caption      = GLanguageHandler->Text[kGenerateMD5].c_str();
	miHexEdit->Caption          = GLanguageHandler->Text[kHexEdit].c_str();

	miCopyMenu->Caption         = GLanguageHandler->Text[kCopy].c_str();
	miCopySelected->Caption     = (GLanguageHandler->Text[kSelected] + kEllipsis).c_str();;
	miCopyAll->Caption          = (GLanguageHandler->Text[kAll] + kEllipsis).c_str();;
	miMoveMenu->Caption         = GLanguageHandler->Text[kMove].c_str();
	miMoveSelected->Caption     = (GLanguageHandler->Text[kSelected] + kEllipsis).c_str();
	miMoveAll->Caption          = (GLanguageHandler->Text[kAll] + kEllipsis).c_str();
	miDeleteMenu->Caption       = GLanguageHandler->Text[kDelete].c_str();
	miDeleteSelected->Caption   = (GLanguageHandler->Text[kSelected] + kEllipsis).c_str();
	miDeleteAll->Caption        = (GLanguageHandler->Text[kAll] + kEllipsis).c_str();

	miZIP->Caption              = (GLanguageHandler->Text[kAddZipFile] + kEllipsis).c_str();
	miSearchExportToCB->Caption = GLanguageHandler->Text[kCopyResultsToClipboard].c_str();

	miSSave->Caption            = (GLanguageHandler->Text[kSaveAs] + kEllipsis).c_str();

	//

	for (int t = 0; t < puQuickSearch->Items->Count; t++)
	{
		if (puQuickSearch->Items[t].Tag != -1)
		{
			puQuickSearch->Items[t].OnClick = miQuickSearchClick;
		}
	}

	// ===========================================================================================

	ice = new XIceCream(this, pICSearch);

	// ===========================================================================================

	//CreateReportsFrame(dataSearch);

	// ===========================================================================================

//	LoadSettings;

	SearchEngine = new ProcessSearch();
}


void TFrameSearch::DeInit()
{
	SaveSettings();

	if (SearchEngine != nullptr)
	{
        delete SearchEngine;
	}

	if (ice != nullptr)
	{
		delete ice;
	}
}


void TFrameSearch::ExecuteSearch(const std::wstring search)
{
	if (!search.empty())
	{
		if (eSearch->Items->IndexOf(search.c_str()) == -1)
		{
			eSearch->Items->Add(search.c_str());
		}

		eSearch->Text = search.c_str();
	}

	pcSearch->ActivePageIndex = 0;

	sbGoSearchClick(sbGoSearch);
}


int TFrameSearch::CurrentTab()
{
	return pcSearch->ActivePageIndex;
}


void TFrameSearch::SetTab(int tab)
{
	pcSearch->ActivePageIndex = tab;
}


std::wstring TFrameSearch::GetSelectedFileName(int tag)
{
	return sgSearchResults->Cells[kschIFileName][sgSearchResults->Selection.Top].c_str();
}


#pragma region Application_Hooks
void __fastcall TFrameSearch::OnRequestNewSearch(int index, const std::wstring search)
{
	ExecuteSearch(search);
}


void __fastcall TFrameSearch::OnNewResults(unsigned __int64 size, int file_count, int folder_count)
{
//	TotalSearchSize         = aSize;
//	TotalSearchFilesCount   = aFilesCount;
//	TotalSearchFoldersCount = aFolderCount;
}
#pragma end_region


#pragma region Popup_QuickSearch
void __fastcall TFrameSearch::miQuickSearchClick(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	QuickMenuAction qma = GQuickMenuHandler->FromMenu(mi->Tag);

	switch (qma.Action)
	{
	case QMAction::kSearchString:
		eSearch->Text = qma.Search.c_str();
		eSearchChange(NULL);

		sbGoSearchClick(sbGoSearch);
		break;
	case QMAction::kOther:
		if (qma.SubAction == 1)
		{
			if (OnOpenSearchWizard)
			{
				OnOpenSearchWizard(0);
			}
		}
		break;
	}
}
#pragma end_region


#pragma region Popup_Search
void __fastcall TFrameSearch::puSearchPopup(TObject *Sender)
{
	bool status = true;

	if (!GSplashHandler->ProcessWindowsVisible())
	{
		TPopupMenu *pu = (TPopupMenu*)Sender;
        TStringGrid *sg = (TStringGrid*)pu->PopupComponent;

		std::wstring file_name = GetSelectedFileName(sg->Tag);

		if (file_name.empty())
		{
			status = false;
		}

		miSearchOpen->Enabled       = status;
		miSearchOpenCustom->Enabled = status;
		miExploreDirectory->Enabled = status;
		miSFileProperties->Enabled  = status;
		miGenerateMD5->Enabled      = status;
		miHexEdit->Enabled          = status;
		miCopyMenu->Enabled         = status;
		miMoveMenu->Enabled         = status;
		miDeleteMenu->Enabled       = status;
		miZIP->Enabled              = status;
		miSearchExportToCB->Enabled = status;
		miSSave->Enabled            = status;

		switch (sg->Tag)
		{
		case 2:
		case 3:
			miCopyAll->Enabled   = false;
			miMoveAll->Enabled   = false;
			miDeleteAll->Enabled = false;

			miZIP->Enabled       = false;
			break;
		}
	}
}


void __fastcall TFrameSearch::miSearchOpenClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		WindowsUtility::ExecuteFile(L"\"" + file_name + L"\"", L"");
	}
}


void __fastcall TFrameSearch::miSearchOpenCustomClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		if (FileExists(file_name.c_str()))
		{
			WindowsUtility::ExecuteFile(L"\"" + GSettingsHandler->General.CustomViewer + L"\"", L"\"" + file_name + L"\"");
		}
		else
		{
			GLog->AddError(L"Search unable to open custom file \"" + file_name + L"\".");
		}
	}
}


void __fastcall TFrameSearch::miExploreDirectoryClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		std::wstring fe = ExtractFilePath(file_name.c_str()).c_str();

		WindowsUtility::ExecuteFile(L"\"" + fe + L"\"", L"");
	}
}


void __fastcall TFrameSearch::miSFilePropertiesClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, file_name);
	}
}


void __fastcall TFrameSearch::miGenerateMD5Click(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		// TO DO	ShowMD5Checksum(file_name, TMD5.Generate(file_name));
	}
}


void __fastcall TFrameSearch::miHexEditClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		WindowsUtility::ExecuteFile(L"\"" + GSystemGlobal->ExePath + L"\\Be.HexEditor.exe\"", file_name);
	}
}


void __fastcall TFrameSearch::miZIPClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
												  L".zip",
                                                  L"",
												  Utility::GetDefaultFileName(L".zip", GLanguageHandler->Text[kSearch] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

		int ZipCount = 0; // TO DO XinorbisZip.ZipAllFiles(lFileName, grid->Tag, sgSearchResults, kschIFileName);

		if (ZipCount == -1)
		{
			ShowXDialog(GLanguageHandler->Text[kErrorCompressingFiles],
						  GLanguageHandler->Text[kErrorCompressingFiles],
						  XDialogTypeWarning);
		}
		else if (ZipCount == 0)
		{
			ShowXDialog(GLanguageHandler->Text[kWarning],
					  GLanguageHandler->Text[kNoFilesToCompress] + L" \"" + file_name + L"\".",
					  XDialogTypeWarning);
		}
	}
}


void __fastcall TFrameSearch::miSearchExportToCBClick(TObject *Sender)
{
	SearchCSVReport();
}


void __fastcall TFrameSearch::miSSaveClick(TObject *Sender)
{
	sbSaveSearchClick(NULL);
}


void __fastcall TFrameSearch::miCopySelectedClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kCopyTo] + kEllipsis);
	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!folder.empty() && !file_name.empty())
	{
		std::wstring effn = Utility::SplitFileName(file_name);

		CopyFile(file_name.c_str(),
				 (folder + effn).c_str(),
				 false);
	}
}


void __fastcall TFrameSearch::miCopyAllClick(TObject *Sender)
{
	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kCopyTo] + kEllipsis);

	if (!folder.empty())
	{
		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			CopyFile((GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name).c_str(),
					 (folder + file->Name).c_str(),
					 false);
		}
	}
}



void __fastcall TFrameSearch::miMoveSelectedClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring folder    = GetCopyMoveFolder(GLanguageHandler->Text[kMoveTo] + kEllipsis);
	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!folder.empty() && !file_name.empty())
	{
		MoveFileEx(file_name.c_str(),
				   (folder + file_name).c_str(),
				   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
	}
}


void __fastcall TFrameSearch::miMoveAllClick(TObject *Sender)
{
	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kMoveTo] + kEllipsis);

	if (!folder.empty())
	{
		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			MoveFileEx((GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name).c_str(),
					   (folder + file->Name).c_str(),
					   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
		}
	}
}


void __fastcall TFrameSearch::miDeleteSelectedClick(TObject *Sender)
{
	if (MessageDlg(GLanguageHandler->Text[kDialog3].c_str(), mtWarning, mbYesNo, 0) == mrYes)
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

		std::wstring file_name = GetSelectedFileName(grid->Tag);

		if (!file_name.empty())
		{
			WindowsUtility::SendToRecycleBin(file_name);
		}
	}
}


void __fastcall TFrameSearch::miDeleteAllClick(TObject *Sender)
{
	if (MessageDlg(GLanguageHandler->Text[kDialog4].c_str(), mtWarning, mbYesNo, 0) == mrYes)
	{
		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			WindowsUtility::SendToRecycleBin(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name);
		}
	}
}
#pragma end_region


#pragma region Bottom_Panel
void __fastcall TFrameSearch::sbSettingsClick(TObject *Sender)
{
//
}


void __fastcall TFrameSearch::sbPagePreviousClick(TObject *Sender)
{
	if (PageNumber > FirstPage)
	{
		PageNumber--;

		RenderResults(PageNumber * GSettingsHandler->General.MaxSearchResults,
					  (PageNumber * GSettingsHandler->General.MaxSearchResults) + GSettingsHandler->General.MaxSearchResults - 1);

		UpdateGUI();
	}
}


void __fastcall TFrameSearch::sbPageNextClick(TObject *Sender)
{
	if (PageNumber < LastPage)
	{
		PageNumber++;

		RenderResults(PageNumber * GSettingsHandler->General.MaxSearchResults,
					  (PageNumber * GSettingsHandler->General.MaxSearchResults) + GSettingsHandler->General.MaxSearchResults - 1);
		UpdateGUI();
	}
}
#pragma end_region


#pragma region Settings
void TFrameSearch::LoadSettings()
{
	if (GSettingsHandler->OpenSettings(true))
	{
		cbSearchShowPath->Checked = GSettingsHandler->ReadBool(L"Prefs", L"Search_ShowPath", true);

		for (int t = 0; t < kMaximumRecentScans; t++)
		{
			std::wstring s = GSettingsHandler->ReadString(L"Prefs", L"SearchTerm" + std::to_wstring(t + 1), L"");

			if (!s.empty())
			{
				eSearch->Items->Add(s.c_str());
			}
		}

		GSettingsHandler->CloseSettings();
	}
	else
	{
		GLog->AddError(L"Error loading settings in FrameSearch");
	}

	BuildSearchCharts();
}


void TFrameSearch::SaveSettings()
{
	if (GSettingsHandler->OpenSettings(false))
	{
		GSettingsHandler->WriteBool(L"Prefs", L"Search_ShowPath", cbSearchShowPath->Checked);

		if (eSearch->Items->Count != 0)
		{
			for (int t = 0; t < eSearch->Items->Count; t++)
			{
				GSettingsHandler->WriteString(L"Prefs", L"SearchTerm" + std::to_wstring(t + 1), eSearch->Items->Strings[t].c_str());
			}
		}

		GSettingsHandler->CloseSettings();
	}
	else
	{
		GLog->AddError(L"Error saving FrameSearch settings");
	}
}
#pragma end_region


void TFrameSearch::RenderResults(int index_from, int index_to)
{
	if (index_from < 0)
	{
		index_from = 0;
	}

	if (index_to > GScanEngine->Data[kDataSearch].Files.size() - 1)
	{
		index_to = GScanEngine->Data[kDataSearch].Files.size() - 1;
	}

	GridUtility::Clear(sgSearchResults, false);

	if (GScanEngine->Data[kDataSearch].Files.size() != 0)
	{
		sgSearchResults->BeginUpdate();
		sgSearchResults->RowCount = 2;

		int row = 1;
		int index = index_from;

		while (index < index_to)
		{
			FileObject *tfo = GScanEngine->Data[kDataSearch].Files[index];

			// == File Name / Path =============================================
			if (cbSearchShowPath->Checked)
			{
				sgSearchResults->Cells[kschVFileName][row] = (GScanEngine->Data[kDataSearch].Folders[tfo->FilePathIndex] + tfo->Name).c_str();
			}
			else
			{
				sgSearchResults->Cells[kschVFileName][row] = tfo->Name.c_str();
			}

			sgSearchResults->Cells[kschIFileName][row] = (GScanEngine->Data[kDataSearch].Folders[tfo->FilePathIndex] + tfo->Name).c_str();

			// == File Size ====================================================
			if (faDirectory & tfo->Attributes)
			{
				sgSearchResults->Cells[kschVSize][row]   = GLanguageHandler->Text[kFolderUC].c_str();
				sgSearchResults->Cells[kschISize][row]   = L"-1";

				sgSearchResults->Cells[kschIColour][row] = kFileCategoryDirectory;
			}
			else
			{
				sgSearchResults->Cells[kschVSize][row]   = Convert::ConvertToUsefulUnit(tfo->Size).c_str();
				sgSearchResults->Cells[kschISize][row]   = tfo->Size;

				int colour = GFileExtensionHandler->GetExtensionCategoryIDFromName(tfo->Name);
				sgSearchResults->Cells[kschIColour][row] = colour;
			}

			// == Attributes ===================================================
			std::wstring ts = L"----  ";

			if (faArchive & tfo->Attributes)  ts[1] = L'A';
			if (faReadOnly & tfo->Attributes) ts[2] = L'R';
			if (faSysFile & tfo->Attributes)  ts[3] = L'S';
			if (faHidden & tfo->Attributes)   ts[4] = L'H';

			sgSearchResults->Cells[kschVAttributes][row] = ts.c_str();

			// == User =========================================================
			sgSearchResults->Cells[kschVOwner][row] = GScanEngine->Data[kDataSearch].Users[tfo->Owner]->Name.c_str();

			// == Dates ========================================================
			sgSearchResults->Cells[kschVCDate][row] = Convert::IntDateToString(tfo->DateCreated).c_str();
			sgSearchResults->Cells[kschICDate][row] = tfo->DateCreated;

			sgSearchResults->Cells[kschVADate][row] = Convert::IntDateToString(tfo->DateAccessed).c_str();
			sgSearchResults->Cells[kschIADate][row] = tfo->DateAccessed;

			sgSearchResults->Cells[kschVMDate][row] = Convert::IntDateToString(tfo->DateModified).c_str();
			sgSearchResults->Cells[kschIMDate][row] = tfo->DateModified;

			// =================================================================

			sgSearchResults->RowCount++;

			index++;
			row++;
		}

		if (sgSearchResults->RowCount != 2)
		{
			sgSearchResults->RowCount--;
		}
	}

	sgSearchResults->EndUpdate();
}


void TFrameSearch::ClearGUI(bool no_results)
{
	if (no_results)
	{
		lSearchDetails->Caption = GLanguageHandler->Text[kNoMatchesFound].c_str();
	}
	else
	{
		lSearchDetails->Caption = L"";
	}

	sbPagePrevious->Enabled = false;
	sbPageNext->Enabled = false;

	PageNumber = 0;
	lPageNumber->Caption = L"";
}


void TFrameSearch::UpdateGUI()
{
	if (sgSearchResults->Cells[kschVFileName][1] == L"")
	{
		ClearGUI(true);
	}
	else
	{
		std::wstring ts = L"";

		if (TotalSearchFilesCount != 0)
		{
			if (GScanEngine->Data[DataSource].Files.size() == 0)
			{
				ts = GLanguageHandler->Text[kFound] + L" " + std::to_wstring(TotalSearchFilesCount) + L" " + GLanguageHandler->Text[kFiles] + L" (100%)";
			}
			else
			{
				std::wstring sp = FloatToStrF(((TotalSearchFilesCount) / GScanEngine->Data[DataSource].FileCount) * 100, ffFixed, 7, 2, GSettingsHandler->XinorbisFormat).c_str();

				ts = GLanguageHandler->Text[kFound] + L" " + std::to_wstring(TotalSearchFilesCount) + L" " + GLanguageHandler->Text[kFiles] + L" (" + sp + L"%)";
			}
		}

		if (TotalSearchFoldersCount != 0)
		{
			std::wstring cp = FloatToStrF((TotalSearchFoldersCount) / GScanEngine->Data[DataSource].FolderCount * 100, ffFixed, 7, 2, GSettingsHandler->XinorbisFormat).c_str();

			if (ts.empty())
			{
				ts += GLanguageHandler->Text[kFound] + L" " + std::to_wstring(TotalSearchFoldersCount) + L" " + GLanguageHandler->Text[kFolders] + L" " + cp + L"%)";
			}
			else
			{
				ts += L" " + GLanguageHandler->Text[kAnd] + L" " + std::to_wstring(TotalSearchFoldersCount) + L" " + GLanguageHandler->Text[kFolders] + L" " + cp + L"%)";
			}
		}

		if (GScanEngine->Data[DataSource].TotalSize != 0)
		{
			std::wstring sp = FloatToStrF((TotalSearchSize / GScanEngine->Data[DataSource].TotalSize) * 100, ffFixed, 7, 2, GSettingsHandler->XinorbisFormat).c_str();

			ts += L", " + Convert::ConvertToUsefulUnit(TotalSearchSize) + L" (" + sp + L"%)";
		}
		else
		{
			ts += L", " + Convert::ConvertToUsefulUnit(TotalSearchSize) + L" (100%)";
		}

		lSearchDetails->Caption = ts.c_str();

		UpdateSearchGUI();
	}
}


void TFrameSearch::UpdateSearchGUI()
{
	lPageNumber->Caption = (std::to_wstring(PageNumber + 1) + L" (" + std::to_wstring(LastPage) + L")").c_str();

	lShowing->Caption = (GLanguageHandler->Text[kShowing] + L" " +
						 std::to_wstring((PageNumber * GSettingsHandler->General.MaxSearchResults) + 1) +
						 kEllipsis + std::to_wstring((PageNumber * GSettingsHandler->General.MaxSearchResults) + sgSearchResults->RowCount - 1) + L" " +
						 GLanguageHandler->Text[kOf] + L" " + std::to_wstring(TotalSearchFilesCount + TotalSearchFoldersCount) + L".").c_str();

	if (PageNumber > FirstPage)
	{
		sbPagePrevious->Enabled = true;
	}
	else
	{
		sbPagePrevious->Enabled = false;
	}

	if (PageNumber < LastPage)
	{
		sbPageNext->Enabled = true;
	}
	else
	{
		sbPageNext->Enabled = false;
	}

	//ResizeColumns();
}


std::wstring TFrameSearch::GetSearchText()
{
	return eSearch->Text.c_str();
}


#pragma region Tab_Search
void __fastcall TFrameSearch::sbGoSearchClick(TObject *Sender)
{
//f not(GSettingsHandler->ProcessWindowsVisible) then {
	if (eSearch->Text != L"")
	{
		//FSearchDataChanged = True;

		sbGoSearch->Enabled = false;

		PageNumber = 0;

//	  if Assigned(FMenuChange) then
//		FMenuChange("", 0, 1);

	  lSearchDetails->Caption = (GLanguageHandler->Text[kSearching] + kEllipsis).c_str();
	  lSearchDetails->Refresh();

//	  if eSearch.Items.IndexOf(eSearch->Text) = -1 then {
//		if eSearch->Text != "" then
//		  eSearch.Items.Insert(0, eSearch->Text);
//	  }

		Command c(PrimaryCommand::Search, eSearch->Text.c_str());

		SearchEngine->Execute(c);

		PostSearch();

//	  FSearchThread = TSearchThread.Create(True);
//	  FSearchThread.SetData(FSource, eSearch->Text);
//	  FSearchThread.OnGetResults    = OnNewResults;
//	  FSearchThread.OnTerminate     = SearchThreadOnTerminate;
//	  FSearchThread.Priority        = tpHigher;
//	  FSearchThread.Start
	}
}


void TFrameSearch::PostSearch()
{
	for (UserData *user : GScanEngine->Data[DataSource].Users)
	{
		UserData *ud = new UserData(user->Name);

		GScanEngine->Data[kDataSearch].Users.push_back(ud);
	}

	for (std::wstring folder : GScanEngine->Data[DataSource].Folders)
	{
		GScanEngine->Data[kDataSearch].Folders.push_back(folder);
	}

	GScanEngine->Data[kDataSearch].Path.String = GScanEngine->Data[DataSource].Path.String;

	// =========================================================================

	if (OnMenuChange)
	{
		OnMenuChange(GLanguageHandler->Text[kSearch], 0, 0);
	}

//	if (SetStatusBarText)
//	{
//		FSetStatusBarText(GLanguageHandler->Text[kSearchFinished]);
//	}

	FirstPage = 0;
	LastPage  = (int)std::ceil((double)GScanEngine->Data[kDataSearch].Files.size() / (double)GSettingsHandler->General.MaxSearchResults) - 1;

	RenderResults(0, GSettingsHandler->General.MaxSearchResults - 1);

	UpdateGUI();

//	if (pSearchChart.Visible then
//    BuildSearchChart;

	UpdateIceCream();

	sbGoSearch->Enabled = true;
}


void __fastcall TFrameSearch::eSearchChange(TObject *Sender)
{
//  leave uncommented ClearGUI(False);
}


void __fastcall TFrameSearch::eSearchKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN && sbGoSearch->Enabled)
	{
		sbGoSearchClick(sbGoSearch);
	}
}

void __fastcall TFrameSearch::sbSearchHelpClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"t41.htm");
}


void __fastcall TFrameSearch::sbSearchSyntaxClick(TObject *Sender)
{
	HelpHandler::OpenSearchManual();
}


void __fastcall TFrameSearch::sbSCAccessedClick(TObject *Sender)
{
	TSpeedButton *button = (TSpeedButton*)Sender;

	int column_index = TableColumnLookup[button->Tag * 2];

	GridUtility::ToggleColumn(sgSearchResults,
							  button,
							  TableColumnLookup[(button->Tag * 2) + 1],
							  DefaultColumnWidths[column_index],
							  column_index);

	FrameResize(NULL);
}


void __fastcall TFrameSearch::cbSearchColourCodeClick(TObject *Sender)
{
	if (sgSearchResults->Cells[kGridColVFilename][1] != L"")
	{
		if (cbSearchColourCode->Checked)
		{
			sgSearchResults->Font->Color = clBlack;
		}
		else
		{
			sgSearchResults->Font->Color = clWhite;
		}

		sgSearchResults->Refresh();
    }
}


void __fastcall TFrameSearch::cbSearchShowPathClick(TObject *Sender)
{
	sbGoSearchClick(sbGoSearch);
}


void __fastcall TFrameSearch::sbSaveSearchClick(TObject *Sender)
{
	std::wstring path = eSearch->Text.c_str();

	std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(L".csv",
														 GLanguageHandler->Text[kSearchResults]));

	if (!file_name.empty())
	{
		switch (GReportHandler->GetReportType(file_name))
		{
		case kReportTypeCSV:
		{
			CSVReportOptions tcsvo = GSettingsHandler->Reports.CSV[kReportLayoutQuick];
			tcsvo.Category = -1;
			tcsvo.Data  = kDataFileList;
			tcsvo.FileName = file_name;

			GReportHandler->SaveCSV(tcsvo, kDataSearch, false, false);
			break;
		}
		case kReportTypeHTML:
			GReportHandler->SaveHTMLFileList(kDataSearch, file_name,
											 GLanguageHandler->Text[kSearchResults] + L" \"" + path + L"\"");
			break;
		case kReportTypeText:
			GReportHandler->SaveTextSearch(file_name, path, kDataSearch);
			break;
        }
	}
}


void TFrameSearch::SearchCSVReport()
{
 // lCSVOutput : TStringList;
//  tempCSVOptions : TCSVReportOptions;
  //	lCSVOutput = TStringList.Create;

//	tempCSVOptions = GSettingsHandler->Report.CSVOptions[LayoutQuick];
  //	tempCSVOptions.CSVData  = CDataFileList;
//	tempCSVOptions.FileName = "";
  //	tempCSVOptions.Category = -1;

//	GReportCSV.GenerateCSVReport(dataSearch, lCSVOutput, tempCSVOptions, LayoutQuick);

	//Clipboard.AsText = lCSVOutput->Text;

}


void __fastcall TFrameSearch::pcSearchChange(TObject *Sender)
{
	if (pcSearch->ActivePageIndex == 1)
	{
		if (SearchDataChanged)
		{
			BuildPropertiesTab(kDataSearch);

			SearchDataChanged = false;
		}
	}
}
#pragma end_region


#pragma region Search_Displays
void TFrameSearch::BuildSearchCharts()
 {
	if (GScanEngine->Data[DataSource].Files.size() != 0 && GScanEngine->Data[DataSource].TotalSize != 0)
	{
		gaugeQuantity->Progress = ((TotalSearchFilesCount + TotalSearchFoldersCount) / (GScanEngine->Data[DataSource].FileCount + GScanEngine->Data[DataSource].FolderCount)) * 100;
		gaugeSize->Progress = (TotalSearchSize / GScanEngine->Data[DataSource].TotalSize) * 100;

		UpdateIceCream();

	}
}


void TFrameSearch::UpdateIceCream()
{
	ice->Begin();

	for (int t = 1; t < kFileCategoriesCount; t++)
	{
		ice->Add(0, GScanEngine->Data[DataTarget].ExtensionSpread[t].PercentCount,
					GLanguageHandler->TypeDescriptions[t],
					std::to_wstring(GScanEngine->Data[DataTarget].ExtensionSpread[t].Count) + L" files",
					GSettingsHandler->FileCategoryColors[t]);

		ice->Add(1, GScanEngine->Data[DataTarget].ExtensionSpread[t].PercentSize,
					GLanguageHandler->TypeDescriptions[t],
					Convert::ConvertToUsefulUnit(GScanEngine->Data[DataTarget].ExtensionSpread[t].Size),
					GSettingsHandler->FileCategoryColors[t]);
	}

	ice->End();
}
#pragma end_region


#pragma region Tab_Properties
void TFrameSearch::BuildPropertiesTab(int index)
{                    /*    to do
	Screen.Cursor  = crHourGlass;

	GScanEngine->Data[index].FromFile      = False;
	GScanEngine->Data[index].Filename      = "";
	GScanEngine->Data[index].ScanTable     = "";
	GScanEngine->Data[index].ScanType      = ScanTypeSearch;
	GScanEngine->Data[index].ScanSource    = GScanEngine[FSource].ScanSource;
	GScanEngine->Data[index].ScanDateFHStr = GScanEngine[FSource].ScanDateFHStr;

	GScanEngine->Data[index].InitNow;

	//  ToggleSoftwareStatus(index, False);
	GSettingsHandler->ShowProgressWindow;

  // ===========================================================================

//    PurgeAllDataRefresh(aDATAINDEX, FrameReports[index].sgNullFiles,
//                                    FrameReports[index].sgNullFolders,
//                                    FrameSearch.sgSearchResults);

  // ======================================================================================================

	for t = 0 to JustInTimeCount do
	{
		if GSettingsHandler->Optimisations.JustInTimeDisplay)
		{
			GSettingsHandler->System.JustInTimeProcessed[aDataIndex, t] = False
		}
		else
		{
			GSettingsHandler->System.JustInTimeProcessed[aDataIndex, t] = True;
		}
	}

	FReportsFrame.PreScan;

	GSettingsHandler->Forms.ProgressForm.SetProcessBar(1);
	GXinorbisScan.DataIndex = aDataIndex;
	GXinorbisScan.Clear;
	GXinorbisScan.Analyse;

	GScanEngine[aDataIndex].TotalSize   = GXinorbisScan.FileTotalSpace;
	GScanEngine[aDataIndex].TotalSizeOD = GXinorbisScan.FileOnDisk;
	GScanEngine[aDataIndex].FileCount   = GXinorbisScan.FileCount;
	GScanEngine[aDataIndex].FolderCount = GXinorbisScan.FolderCount;

	GSettingsHandler->Forms.ProgressForm.SetProcessIcon(2);
	//    BuildRootListFromXinFiles(1);

	GSettingsHandler->Forms.ProgressForm.SetProcessText(GLanguageHandler->Text[kAnalysingData] + rsEllipsis);

	GXinorbisScan.AnalyseData(True);

	FReportsFrame.PostScan;

	GSettingsHandler->Forms.ProgressForm.SetProcessBar(5);

	GSettingsHandler->Forms.ProgressForm.SetProcessIcon(3);

	// =====================================================================

	FReportsFrame.BuildDisplay;

	// =====================================================================

	FReportsFrame.RefreshGraph(NULL);

	//  ToggleSoftwareStatus(aDataIndex, True);

	GSettingsHandler->HideProgressWindow;

	Screen->Cursor = crDefault; */
}
#pragma end_region


/*              to do
procedure TFrameSearch.sgSearchResultsCanSort(Sender: TObject; ACol: Integer;
  var DoSort: Boolean);
{
  DoSort = False;

  if TAdvStringGrid(Sender).SortSettings.Direction = sdDescending then
	TAdvStringGrid(Sender).SortSettings.Direction = sdAscending
  else
	TAdvStringGrid(Sender).SortSettings.Direction = sdDescending;

  case ACol of
    schVSize       : GScanEngine[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileSizes));
    schVCDate      : GScanEngine[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
	schVADate      : GScanEngine[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
    schVMDate      : GScanEngine[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
    schVFilename   : GScanEngine[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNames));
    schVOwner      : GScanEngine[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareOwnerSD));
    schVAttributes : GScanEngine[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileAttributes));
  }

  RenderResults(FPageNumber * GSettingsHandler->General.MaxSearchResults,
			   (FPageNumber * GSettingsHandler->General.MaxSearchResults) + GSettingsHandler->General.MaxSearchResults - 1);
  UpdateGUI;
}

procedure TFrameSearch.sgSearchResultsGetCellColor(Sender: TObject; ARow,
  ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
{
  if cbSearchColourCode.Checked then {
    if ARow > 0 then
      ABrush.Color = GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender)->Cells[kschIColour, ARow])];
  end
  else {
	if gdSelected in AState then
      ABrush.Color = CGridColourSelected
    else {
      if Odd(ARow) then
        ABrush.Color = CGridColourOn
      else
        ABrush.Color = CGridColourOff;
    }
  }
}


const
  SearchSortColumns     : array[0..6] of integer = (schVFilename, kschISize, 2, 3, 4, 5, 6);


procedure TFrameSearch.CreateReportsFrame(aDataIndex : integer);
{
  FReportsFrame = TFrameReports.Create(Self);
  FReportsFrame.Name                        = "FrameReports" + std::to_wstring(aDataIndex);
  FReportsFrame.Parent                      = tsProperties;
  FReportsFrame.Source                      = aDataIndex;
  FReportsFrame.Init;
  FReportsFrame.Visible                     = True;
  FReportsFrame.GetLeftOffset               = OnGetLeftOffset;
  FReportsFrame.GetTopOffset                = OnGetTopOffset;

//  FReportsFrame.OnNewScan                   = RequestNewScan;
  FReportsFrame.OnNewSearch                 = OnRequestNewSearch;
 {FReportsFrame.OnNewSummary                = RequestNewSummary;
  FReportsFrame.OnProcessWindowStatusChange = OnProcessWindowStatusChange;
  FReportsFrame.OnSetStatusBarText          = OnStatusBarChange;
  FReportsFrame.OnSettingsTab               = OnOpenSettingsTab;
  FReportsFrame.OnSetTutorialBarText        = OnTutorialBarChange; }

  GReportText.SetGrids(aDataIndex, FReportsFrame.sgNullFiles,
                                   FReportsFrame.sgNullFolders,
                                   FReportsFrame.sgTop50Big,
                                   FReportsFrame.sgTop50Small,
                                   FReportsFrame.sgTop101BigDate,
                                   FReportsFrame.sgTop101SmallDate);

  GReportXML.SetGrids(aDataIndex,  FReportsFrame.tvFileDates,
                                   FReportsFrame.sgNullFiles,  FReportsFrame.sgNullFolders,    FReportsFrame.sgTop50Big,
                                   FReportsFrame.sgTop50Small, FReportsFrame.sgTop101BigDate,  FReportsFrame.sgTop101SmallDate,
                                   FReportsFrame.cbFileDates,  FReportsFrame.cbFileDatesUsers, FReportsFrame.cbTop101Dates);


  GReportHTML.SetGrids(aDataIndex, FReportsFrame.tvFileDates,
								   FReportsFrame.sgNullFiles,  FReportsFrame.sgNullFolders,    FReportsFrame.sgTop50Big,
                                   FReportsFrame.sgTop50Small, FReportsFrame.sgTop101BigDate,  FReportsFrame.sgTop101SmallDate,
                                   FReportsFrame.cbFileDates,  FReportsFrame.cbTop101Dates);


  GReportSummary.SetGrids(aDataIndex, FReportsFrame.sgNullFiles,
                                      FReportsFrame.sgNullFolders,
                                      FReportsFrame.sgDirList,
                                      FReportsFrame.sgTop50Big,
                                      FReportsFrame.sgUsers);

  //UpdateGUICustomNames(aDataIndex);
}


*/


