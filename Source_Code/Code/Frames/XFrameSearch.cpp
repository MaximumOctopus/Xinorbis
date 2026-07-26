//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConstantsReports.h"

#include "XFrameSearch.h"

#include "XFormGetCopyMove.h"
#include "XFormXinorbisDialog.h"

#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SplashHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;
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
//	int i = 0;
//
//	for t := 1 to 12 do begin
//	if not(sgSearchResults.IsHiddenColumn(t)) then
//	  inc(i, sgSearchResults.ColWidths[t]);
// end;

//	sgSearchResults->ColWidths[0] = sgSearchResults->Width - (i + __WidthOfScrollbar);
}


void TFrameSearch::Init()
{
 /*	FSearchDataChanged = False;

	GScanEngine[dataSearch].ScanPath = GLanguageHandler->Text[kSearch];

	tsSearch.Caption   = GLanguageHandler->Text[kSearch];

	tsProperties.Caption     = GLanguageHandler->Text[kDetail];
	tsDuplicatesName.Caption = GLanguageHandler->Text[kDuplicatesName];
	tsDuplicatesSize.Caption = GLanguageHandler->Text[kDuplicatesSize];

	sgDuplicatesName.HideColumn(2);
	sgDuplicatesName->Cells[0, 0]   = GLanguageHandler->Text[kFilePath];
	sgDuplicatesName->Cells[1, 0]   = GLanguageHandler->Text[kSize];

	sgDuplicatesSize.HideColumn(2);
	sgDuplicatesSize->Cells[0, 0]   = GLanguageHandler->Text[kFilePath];
	sgDuplicatesSize->Cells[1, 0]   = GLanguageHandler->Text[kSize];

	lSearchDetails.Caption = GLanguageHandler->Text[kSearchResults];

	miExploreDirectory.Caption     = GLanguageHandler->Text[kExploreFolder];

	lPSearchSize.Caption = GLanguageHandler->Text[kBySize];

	lPSearchQuantity.Caption   = GLanguageHandler->Text[kByQuantity];

	cbSearchShowPath.Caption   = GLanguageHandler->Text[kShowFullPath];
	cbSearchColourCode.Caption = GLanguageHandler->Text[kColourCode];

	sgSearchResults.DefaultRowHeight  = GSettingsHandler->General.RowHeight;

	sgSearchResults->Cells[schVFilename, 0]   = GLanguageHandler->Text[kFileName];
	sgSearchResults->Cells[schVSize, 0]       = GLanguageHandler->Text[kSize];
	sgSearchResults->Cells[schVCDate, 0]      = GLanguageHandler->Text[kDate];

	sgSearchResults->Cells[schVADate, 0]      = GLanguageHandler->Text[kAccessed];
	sgSearchResults->Cells[schVMDate, 0]      = GLanguageHandler->Text[kModified];
	sgSearchResults->Cells[schVOwner, 0]      = GLanguageHandler->Text[kFileOwner];
	sgSearchResults->Cells[schVAttributes, 0] = GLanguageHandler->Text[kAttr];

	sgSearchResults.HideColumn(kschVADate);
	sgSearchResults.HideColumn(kschVMDate);
	sgSearchResults.HideColumn(kschVAttributes);
	sgSearchResults.HideColumn(kschVOwner);
	sgSearchResults.HideColumn(kschIFilename);
	sgSearchResults.HideColumn(kschISize);
	sgSearchResults.HideColumn(kschICDate);
	sgSearchResults.HideColumn(kschIADate);
	sgSearchResults.HideColumn(kschIMDate);
	sgSearchResults.HideColumn(kschIColour);

	// ===========================================================================================

	miSearchOpen.Caption       = GLanguageHandler->Text[kViewOpenFile];
	miSearchOpenCustom.Caption = GLanguageHandler->Text[kOpenWithCustomViewer];
	miExploreDirectory.Caption = GLanguageHandler->Text[kExploreFolder];
	miSFileProperties.Caption  = GLanguageHandler->Text[kFileProperties];
	miGenerateMD5.Caption      = GLanguageHandler->Text[kGenerateMD5];
	miHexEdit.Caption          = GLanguageHandler->Text[kHexEdit];

	miCopyMenu.Caption         = GLanguageHandler->Text[kCopy];
	miCopySelected.Caption     = GLanguageHandler->Text[kSelected] + rsEllipsis;
	miCopyAll.Caption          = GLanguageHandler->Text[kAll] + rsEllipsis;
	miMoveMenu.Caption         = GLanguageHandler->Text[kMove];
	miMoveSelected.Caption     = GLanguageHandler->Text[kSelected] + rsEllipsis;
	miMoveAll.Caption          = GLanguageHandler->Text[kAll] + rsEllipsis;
	miDeleteMenu.Caption       = GLanguageHandler->Text[kDelete];
	miDeleteSelected.Caption   = GLanguageHandler->Text[kSelected] + rsEllipsis;
	miDeleteAll.Caption        = GLanguageHandler->Text[kAll] + rsEllipsis;

	miZIP.Caption              = GLanguageHandler->Text[kAddZipFile] + rsEllipsis;
	miSearchExportToCB.Caption = GLanguageHandler->Text[kCopyResultsToClipboard];

	miSSave.Caption            = GLanguageHandler->Text[kSaveAs] + rsEllipsis;

	// ===========================================================================================

	CreateReportsFrame(dataSearch);

	// ===========================================================================================

	SetTheme;

	LoadSettings;      */
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
	std::wstring ss = L"";
	int ix = -1;

  /*	if Pos("{", MenuStrings[TMenuItem(Sender).Tag]) != 0)
	{
		ss = ParseMenuSearchCommand(MenuStrings[TMenuItem(Sender).Tag])
	}
	else if MenuStrings[TMenuItem(Sender).Tag][1] = "$" then
	{
		ix = ParseMenuSearchCommandII(MenuStrings[TMenuItem(Sender).Tag])
	}
	else
	{
		ss = MenuStrings[TMenuItem(Sender).Tag];
	}

	if ix != -1 then
	{
		if (ix == 1)
		{
			if Assigned(FOpenSearchWizard)
			{
				FOpenSearchWizard(0);
			}
		}
	}
	else
	{
		if ss != "" then
		{
			eSearch->Text = ss;
			eSearchChange(NULL);

			sbGoSearchClick(sbGoSearch);
		}
	}                               */
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
		// TO DO LOG	TMSLogger.Error("miSearchOpenCustomClickError loading file "" + file_name + "".");
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
		// TO DO	WindowsUtility::ShowFilePropertiesDialog(Application->Handle, file_name);
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
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	switch (grid->Tag)
	{
	case 1:
		SearchCSVReport();
		break;
	case 2:
		// TO DO sbCopyCSVDNClick(NULL);
		break;
	case 3:
		// TO DO sbCopyCSVDSClick(NULL);
		break;
	}
}


void __fastcall TFrameSearch::miSSaveClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	switch (grid->Tag)
	{
	case 1:
		sbSaveSearchClick(NULL);
		break;
	case 2:
		// TO DO sbSaveDNClick(NULL);
		break;
	case 3:
		// TO DO sbSaveDSClick(NULL);
		break;
	}
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
		//CopyFile(PChar(file_name),
		//		 PChar(folder + ExtractFileName(file_name)),
		//		 false);
	}
}


void __fastcall TFrameSearch::miCopyAllClick(TObject *Sender)
{
	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kCopyTo] + kEllipsis);

	if (!folder.empty())
	{
		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			//CopyFile(PChar(GScanEngine[dataSearch].Folders[file->FilePathIndex] + file->Name),
			 //		 PChar(folder + file->Name),
			  //		 false);
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
	   //	MoveFileEx(PChar(file_name),
	   //			   PChar(s + file_name),
	   //			   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
	}
}


void __fastcall TFrameSearch::miMoveAllClick(TObject *Sender)
{
	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kMoveTo] + kEllipsis);

	if (!folder.empty())
	{
		for (FileObject *file : GScanEngine->Data[DataSource].Files)   // to do, all, search data, NOT .Files
		{
		  //	MoveFileEx(PChar(GScanEngine[dataSearch].Folders[file->FilePathIndex] + file->Name),
		  //			   PChar(folder + file->Name),
		  //				MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
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
			// TO DO WindowsUtility::SendToRecycleBin(GScanEngine[dataSearch].Folders[file->FilePathIndex] + file->Name);
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
/*	if GSettingsHandler->OpenSettings(True) then
	{
		pSearchChart.Width       = GSettingsHandler->ReadIntegerFromSettings("Prefs", "Sizes_pSearchResults", 200, 200);

		cbSearchShowPath.Checked = GSettingsHandler->ReadBoolFromSettings("Prefs", "Search_ShowPath", True);

		if (GSettingsHandler->customsettings.SettingsSaveLocation = SaveLocationConfigIni) then
		{
			for t = 1 to MaximumFolderHistory do
			{
				s = GSettingsHandler->ReadStringFromSettings("Prefs", "SearchTerm" + IntToStr(t), "");

				if s != "" then
				{
					eSearch.Items.Add(s);
				}
			}
		}
		else
		{
			lReg = TRegistry.Create(KEY_READ);

			try
			{
				lReg.RootKey = HKEY_CURRENT_USER;
				lReg.OpenKey("\software\" + XinorbisRegistryKey + "\SearchTerm", True);

				t = 0;
				While lReg.ValueExists("Term" + IntToStr(t)) do
				{
					eSearch.Items.Add(lReg.ReadString("Term" + IntToStr(t)));
					t++;
				}
			}
			catch(...)
			{
				lReg.Free;
			}

		}

		GSettingsHandler->CloseSettings;
	}
	else
	{
		TMSLogger.Error("Error loading settings in FrameSearch");
	}

  	RebuildCharts(); */
}


void TFrameSearch::SaveSettings()
{
  /*lReg : TRegistry;
	if GSettingsHandler->OpenSettings(False) then
	{
		GSettingsHandler->WriteIntegerToSettings("Prefs", "Sizes_pSearchResults", pSearchChart.Width);

		GSettingsHandler->WriteBoolToSettings("Prefs", "Search_ShowPath",         cbSearchShowPath.Checked);

		if (GSettingsHandler->customsettings.SettingsSaveLocation = SaveLocationConfigIni) then {
			if eSearch.Items.Count != 0 then
			{
				for t = 0 to eSearch.Items.Count - 1 do
				{
					GSettingsHandler->WriteStringToSettings("Prefs", "SearchTerm" + IntToStr(t + 1), eSearch.Items[t]);
				}
			}
		}
		else
		{
			if eSearch.Items.Count != 0 then
			{
				lReg = TRegistry.Create(KEY_WRITE);

				try
				{
					lReg.RootKey = HKEY_CURRENT_USER;
					lReg.OpenKey("\software\" + XinorbisRegistryKey + "\SearchTerm", True);

					for t = 0 to eSearch.Items.Count - 1 do
					{
						if t < MaximumFolderHistory then lReg.WriteString("Term" + IntToStr(t), eSearch.Items[t]);
					}
				}
				catch(...)
				{
					lReg.Free;
				}
			}
		}

		GSettingsHandler->CloseSettings;
	}
	else
	{
	//TMSLogger.Error("Error saving FrameSearch settings");
	}               */
}
#pragma end_region


void TFrameSearch::RenderResults(int index_from, int index_to)
{   /*
  l{, lEnd, lTemp, lInc : integer;
  t, sColourCode : integer;
  ts : string;
  lFinished : boolean;
  tfo : TFileObject;

{
  l{    = a{;
  lEnd      = a}
  lInc      = 1;

  if l{ < 0 then
    l{ = 0;

  if lEnd > GScanEngine[dataSearch].Files.Count - 1 then
    lEnd = GScanEngine[dataSearch].Files.Count - 1;

  if sgSearchResults.SortSettings.Direction = sdAscending then {
    lTemp  = l}
    lEnd   = l{;
    l{ = lTemp;

    lInc   = -1;
  }

  TGridUtility.ClearStringGird(sgSearchResults, False);

  sgSearchResults.{Update;

  sgSearchResults.RowCount = 2;

  if GScanEngine[dataSearch].Files.Count != 0 then {

    t = l{;

    repeat

      tfo = GScanEngine[dataSearch].Files[t];

      // == File Name / Path =====================================================

      if cbSearchShowPath.Checked then
	   sgSearchResults->Cells[kschVFileName, sgSearchResults.RowCount - 1] = GScanEngine[dataSearch].Folders[tfo.FilePathIndex] + tfo.FileName
	  else
		sgSearchResults->Cells[kschVFileName, sgSearchResults.RowCount - 1] = tfo.FileName;

	  sgSearchResults->Cells[kschIFileName, sgSearchResults.RowCount - 1] = GScanEngine[dataSearch].Folders[tfo.FilePathIndex] + tfo.FileName;

	  // == File Size ============================================================

	  if ((faDirectory and tfo.Attributes) = faDirectory) then {
		sgSearchResults->Cells[kschVSize,   sgSearchResults.RowCount - 1]   = UpperCase(GLanguageHandler->Text[kFolder]);
		sgSearchResults->Cells[kschISize,   sgSearchResults.RowCount - 1]   = "-1";

		sgSearchResults->Cells[kschIColour, sgSearchResults.RowCount - 1] = IntToStr(FileCategoryDirectory);
	  end
	  else {
		sgSearchResults->Cells[kschVSize,   sgSearchResults.RowCount - 1]   = TConvert.ConvertToUsefulUnit(tfo.FileSize);
		sgSearchResults->Cells[kschISize,   sgSearchResults.RowCount - 1]   = IntToStr(tfo.FileSize);

		sColourCode  = FileExtensionsObject.GetExtensionCategoryIDFromName(tfo.FileName);
        sgSearchResults->Cells[kschIColour, sgSearchResults.RowCount - 1] = IntToStr(sColourCode);
      }

      // == Attributes ===========================================================

      ts = "----  ";
      if ((faArchive and tfo.Attributes)  = faArchive) then  ts[1] = "A";
      if ((faReadOnly and tfo.Attributes) = faReadOnly) then ts[2] = "R";
      if ((faSysFile and tfo.Attributes)  = faSysFile) then  ts[3] = "S";
      if ((faHidden and tfo.Attributes)   = faHidden) then   ts[4] = "H";

      sgSearchResults->Cells[schVAttributes, sgSearchResults.RowCount - 1] = ts;

      // == User =================================================================

      sgSearchResults->Cells[schVOwner, sgSearchResults.RowCount - 1]      = GScanEngine[dataSearch].Users[tfo.Owner].Name;

      // == Dates ================================================================

	  sgSearchResults->Cells[kschVCDate, sgSearchResults.RowCount - 1]      = TConvert.IntDateToString(tfo.FileDateC);
	  sgSearchResults->Cells[kschICDate, sgSearchResults.RowCount - 1]      = IntToStr(tfo.FileDateC);

	  sgSearchResults->Cells[kschVADate, sgSearchResults.RowCount - 1]      = TConvert.IntDateToString(tfo.FileDateA);
	  sgSearchResults->Cells[kschIADate, sgSearchResults.RowCount - 1]      = IntToStr(tfo.FileDateA);

	  sgSearchResults->Cells[kschVMDate, sgSearchResults.RowCount - 1]      = TConvert.IntDateToString(tfo.FileDateM);
	  sgSearchResults->Cells[kschIMDate, sgSearchResults.RowCount - 1]      = IntToStr(tfo.FileDateM);

      // =========================================================================

	  sgSearchResults.RowCount = sgSearchResults.RowCount + 1;

      inc(t, lInc);

      if (lInc = 1) then
        lFinished = t > lEnd
      else
        lFinished = t < l}

    until lFinished;

    if sgSearchResults.RowCount != 2 then
      sgSearchResults.RowCount = sgSearchResults.RowCount - 1;
  }

  sgSearchResults.EndUpdate;*/
}


void TFrameSearch::ClearGUI(bool no_results)
{
 /*	if (no_results)
	{
		lSearchDetails.HTMLText[0] = GLanguageHandler->Text[kNoMatchesFound]
	}
	else
	{
		lSearchDetails.HTMLText[0] = "";
	}

	lsPagePrevious->Enabled     = False;
	lsPageNext->Enabled         = False;

	FPageNumber                = 0;
	lPageNumber.Caption        = "";

	lShowing.Caption           = ""; */
}


void TFrameSearch::UpdateGUI()
{  /*
	if (sgSearchResults->Cells[schVFilename][1] == L"")
	{
		ClearGUI(true);
	}
	else
	{
		std::wstring ts = L"";

		if TotalSearchFilesCount != 0)
		{
			if GScanEngine[FSource].FileCount = 0)
			{
				ts = GLanguageHandler->Text[kFound] + " <b>" + IntToStr(TotalSearchFilesCount) + "</b> " + GLanguageHandler->Text[kFiles] + " (100%)"
			}
			else
			{
				ts = GLanguageHandler->Text[kFound] + " <b>" + IntToStr(TotalSearchFilesCount) + "</b> " + GLanguageHandler->Text[kFiles] + " (<b>" + FloatToStrF(((TotalSearchFilesCount) / GScanEngine[FSource].FileCount) * 100, ffFixed, 7, 2, XinorbisFormatSettings) + "%</b>)";
			}
		}

		if TotalSearchFoldersCount != 0 then
		{
			if (ts.empty())
			{
				ts = GLanguageHandler->Text[kFound] + " <b>" + IntToStr(TotalSearchFoldersCount) + "</b> " + GLanguageHandler->Text[kFolders] + " (<b>" + FloatToStrF(((TotalSearchFoldersCount) / GScanEngine[FSource].FolderCount) * 100, ffFixed, 7, 2, XinorbisFormatSettings) + "%</b>)"
			}
			else
			{
				ts += L" " + GLanguageHandler->Text[kAnd] + " <b>" + IntToStr(TotalSearchFoldersCount) + "</b> " + GLanguageHandler->Text[kFolders] + " (<b>" + FloatToStrF(((TotalSearchFoldersCount) / GScanEngine[FSource].FolderCount) * 100, ffFixed, 7, 2, XinorbisFormatSettings) + "%</b>)";
			}
		}

		if GScanEngine[FSource].TotalSize != 0)
		{
			lSearchDetails.HTMLText[0] = ts + ", <b>" + TConvert.ConvertToUsefulUnit(TotalSearchSize) + "</b> (" + FloatToStrF((TotalSearchSize / GScanEngine[FSource].TotalSize) * 100, ffFixed, 7, 2, XinorbisFormatSettings) + "%)"
		}
		else
		{
			lSearchDetails.HTMLText[0] = ts + ", <b>" + TConvert.ConvertToUsefulUnit(TotalSearchSize) + "</b> (100%)";
		}

		UpdateSearchGUI;
	} */
}


void TFrameSearch::UpdateSearchGUI()
{                                       /*
	lPageNumber->Caption = IntToStr(FPageNumber + 1) + " (" + IntToStr(FLastPage + 1) + ")";

	lShowing.Caption = GLanguageHandler->Text[kShowing] + " " +
					  IntToStr((FPageNumber * GSettingsHandler->General.MaxSearchResults) + 1) +
					  rsEllipsis + IntToStr((FPageNumber * GSettingsHandler->General.MaxSearchResults) + sgSearchResults.RowCount - 1) + " " +
					  GLanguageHandler->Text[kOf] + " " + IntToStr(TotalSearchFilesCount + TotalSearchFoldersCount) + ".";

	if (PageNumber > FFirstPage)
	{
		lsPagePrevious->Enabled = True
	}
	else
	{
		lsPagePrevious->Enabled = False;
	}

	if (FPageNumber < FLastPage)
	{
		lsPageNext->Enabled = True
	}
	else
	{
		lsPageNext->Enabled = False;
	}

	ResizeColumns; */
}


void TFrameSearch::RebuildCharts()
{
// to do
}



/*

const
  SearchSortColumns     : array[0..6] of integer = (schVFilename, kschISize, 2, 3, 4, 5, 6);


procedure TFrameSearch.SetTheme;
{
  TThemeHelper.SetSmoothTabPager(pSearchOptions);

  TThemeHelper.SetSmoothTabPage(tsSearch);
  TThemeHelper.SetSmoothTabPage(tsProperties);
  TThemeHelper.SetSmoothTabPage(tsDuplicatesName);
  TThemeHelper.SetSmoothTabPage(tsDuplicatesSize);
}


procedure TFrameSearch.DeInit;
{
  SaveSettings;
}


function TFrameSearch.GetActivePage: integer;
{
  Result = pSearchOptions.ActivePageIndex;
}


procedure TFrameSearch.CreateReportsFrame(aDataIndex : integer);
{
  FReportsFrame = TFrameReports.Create(Self);
  FReportsFrame.Name                        = "FrameReports" + IntToStr(aDataIndex);
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


procedure TFrameSearch.SetTab(aTab : integer);
{
  pSearchOptions.ActivePageIndex = aTab;
}


function TFrameSearch.GetSearchText: string;
{
  Result = eSearch->Text;
}



procedure TFrameSearch.SearchThreadOnTerminate(Sender: TObject);
var
  t : integer;
  lUserData : TUserData;

{
  for t= 0 to GScanEngine[FSource].Users.Count - 1 do {
    lUserData = TUserData.Create;

    lUserData.Name = GScanEngine[FSource].Users[t].Name;

    GScanEngine[dataSearch].Users.Add(lUserData);
  }

  for t= 0 to GScanEngine[FSource].Folders.Count - 1 do
    GScanEngine[dataSearch].Folders.Add(GScanEngine[FSource].Folders[t]);

  GScanEngine[dataSearch].ScanPath = GScanEngine[FSource].ScanPath;

  // ===========================================================================

  if Assigned(FMenuChange) then
    FMenuChange(GLanguageHandler->Text[kSearch], 0, 0);

  UpdateSearchCapacity;

  if Assigned(FSetStatusBarText) then
    FSetStatusBarText(GLanguageHandler->Text[kSearchFinished]);

  FFirstPage = 0;
  FLastPage  = Ceil(GScanEngine[dataSearch].Files.Count / GSettingsHandler->General.MaxSearchResults) - 1;

  RenderResults(0, GSettingsHandler->General.MaxSearchResults - 1);
  UpdateGUI;

  if pSearchChart.Visible then
    BuildSearchChart;

  UpdateSearchCapacity;

  sbGoSearch->Enabled = True;
}


procedure TFrameSearch.sbSearchThingClick(Sender: TObject);
{
  if sbSearchThing.Tag = 1 then
    sbSearchThing.Tag = 2
  else
    sbSearchThing.Tag = 1;

  UpdateSearchCapacity;
}

procedure TFrameSearch.UpdateSearchCapacity;
 var
  t : integer;
  lCapacityItem : TCapacityItem;

 {
  capacitySearch.Items.Clear;

  for t = 1 to __FileCategoriesCount do {
    if sbSearchThing.Tag = 1 then {
      if GScanEngine[dataSearch].Files.Count != 0 then {
        if ExtSpreadSearch[t, 1] != 0 then {
          lCapacityItem             = capacitySearch.Items.Add;
          lCapacityItem.Value       = (ExtSpreadSearch[t, 1] / TotalSearchFilesCount) * 100;
          lCapacityItem.Color       = GSystemGlobal.FileCategoryColors[t];
          lCapacityItem.ColorTo     = GSystemGlobal.FileCategoryColors[t];
          lCapacityItem.DisplayName = TypeDescriptions[t];
          lCapacityItem.Description = TypeDescriptions[t];
          lCapacityItem.Hint        = TypeDescriptions[t] + " (" + IntToStr(ExtSpreadSearch[t, 1]) + " files)";
        }
      }
    end
    else {
      if TotalSearchSize != 0 then {
        if ExtSpreadSearch[t, 2] != 0 then {
          lCapacityItem             = capacitySearch.Items.Add;
          lCapacityItem.Value       = (ExtSpreadSearch[t, 2] / TotalSearchSize) * 100;
          lCapacityItem.Color       = GSystemGlobal.FileCategoryColors[t];
          lCapacityItem.ColorTo     = GSystemGlobal.FileCategoryColors[t];
          lCapacityItem.DisplayName = TypeDescriptions[t];
          lCapacityItem.Description = TypeDescriptions[t];
          lCapacityItem.Hint        = TypeDescriptions[t] + " (" + TConvert.ConvertToUsefulUnit(ExtSpreadSearch[t, 2]) + ")";
        }
      }
     }
  }
}


 */

#pragma region Tab_Search
void __fastcall TFrameSearch::sbGoSearchClick(TObject *Sender)
{
//f not(GSettingsHandler->ProcessWindowsVisible) then {
	if (eSearch->Text != L"")
	{
		//FSearchDataChanged = True;

		sbGoSearch->Enabled = false;

		PageNumber = 0;

//		GScanEngine->Search.Clear();

//	  if Assigned(FMenuChange) then
//		FMenuChange("", 0, 1);

//	  lSearchDetails.HTMLText[0] = GLanguageHandler->Text[kSearching] + rsEllipsis;
//	  lSearchDetails.Refresh;

//	  if eSearch.Items.IndexOf(eSearch->Text) = -1 then {
//		if eSearch->Text != "" then
//		  eSearch.Items.Insert(0, eSearch->Text);
//	  }

//	  FSearchThread = TSearchThread.Create(True);
//	  FSearchThread.SetData(FSource, eSearch->Text);
//	  FSearchThread.OnGetResults    = OnNewResults;
//	  FSearchThread.OnTerminate     = SearchThreadOnTerminate;
//	  FSearchThread.Priority        = tpHigher;
//	  FSearchThread.Start
	}
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
	// to do THelp.OpenHelpPage("t41.htm");
}


void __fastcall TFrameSearch::sbSearchSyntaxClick(TObject *Sender)
{
// to do	THelp.OpenSearchManual;
}


void __fastcall TFrameSearch::sbSCAccessedClick(TObject *Sender)
{
//	TGridUtility.ToggleColumn(sgSearchResults,
//							  TSpeedbutton(Sender),
//	   to do						  TableColumnLookup[(TSpeedbutton(Sender).Tag * 2) + 1],
//							  TableColumnLookup[TSpeedbutton(Sender).Tag * 2]);
//
//	ResizeColumns();
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
{                                     /*
procedure TFrameSearch.sbSaveSearchClick(Sender: TObject);
var
  tf : TextFile;
  t, a, b, c, w : integer;
  lFileName : string;
  tempCSVOptions : TCSVReportOptions;
  lReportOutput : TStringList;

{
	std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(".csv", GLanguageHandler->Text[kSearchResults]));

	if (!file_name.empty())
	{
		switch (GReportUtility.GetReportType(lFileName))
		{
		CReportTypeCSV:
		{
			tempCSVOptions = GSettingsHandler->Report.CSVOptions[LayoutQuick];
			tempCSVOptions.Category = -1;
			tempCSVOptions.CSVData  = CDataFileList;
			tempCSVOptions.FileName = lFileName;

			lReportOutput = TStringList.Create;

			GReportCSV.GenerateCSVReport(dataSearch, lReportOutput, tempCSVOptions, LayoutUnknown);

			FreeAndNULL(lReportOutput);
		}
		CReportTypeHTML:
		{
			lReportOutput = TStringList.Create;

			GReportHTML.GenerateHTMLFileReport(dataSearch, lReportOutput, GLanguageHandler->Text[kSearchResults] + " "" + eSearch->Text + """, lFileName);

			FreeAndNULL(lReportOutput);
		}
		CReportTypeText:
		{
			AssignFile(tf, lFileName);

			{$I-}
			Rewrite(tf);

			if IOResult != 0 then {
			ShowXDialog(GLanguageHandler->Text[kWarning],
						GLanguageHandler->Text[kErrorSaving] + " "" + lFileName + "".",
						XDialogTypeWarning);

			if Assigned(FSetStatusBarText) then
			  FSetStatusBarText(GLanguageHandler->Text[kError] + " " + lFileName);
			end
			else {
			a = Length(GLanguageHandler->Text[kPath]);
			b = Length(GLanguageHandler->Text[kSearch]);
			c = Length(GLanguageHandler->Text[kFound]);

			w = Max(Max(a, b), c);   // find the largest of the three texts

			Writeln(tf, "// Xinorbis 8.3 - " + GLanguageHandler->Text[kSearchResults]);
			Writeln(tf, "//");

			if FSource = dataLatestScan then
			  Writeln(tf, "// " + GLanguageHandler->Text[kPath] + TXFormatting.StringOfChars(w - a, " ") + " : " + GScanEngine[FSource].ScanPath)
			else
			  Writeln(tf, "// " + GLanguageHandler->Text[kPath] + TXFormatting.StringOfChars(w - a, " ") + " : " + GScanEngine[FSource].ScanPath + " (DB " + GLanguageHandler->Text[kTable] + " " + GScanEngine[FSource].ScanTable + ")");

			Writeln(tf, "// " + GLanguageHandler->Text[kSearch] + TXFormatting.StringOfChars(w - b, " ") + " : " + eSearch->Text);
			Writeln(tf, "// " + GLanguageHandler->Text[kFound]  + TXFormatting.StringOfChars(w - c, " ") + " : " + IntToStr(GScanEngine[dataSearch].Files.Count));
			Writeln(tf, "");

			writeln(tf, GLanguageHandler->Text[kFilePath] + " " +
						" [" +  GLanguageHandler->Text[kSize] + "] " +
						GLanguageHandler->Text[kFileOwner] +  " :: " +
						GLanguageHandler->Text[kAttr]);

			Writeln(tf, "");

			for t = 0 to GScanEngine[dataSearch].Files.Count - 1 do {
			  Writeln(tf, GScanEngine[dataSearch].Folders[GScanEngine[dataSearch].Files[t].FilePathIndex] + GScanEngine[dataSearch].Files[t].Filename +
						  "  [" + TConvert.ConvertToUsefulUnit(GScanEngine[dataSearch].Files[t].FileSize) + "] " +
						  GScanEngine[dataSearch].Users[GScanEngine[dataSearch].Files[t].Owner].Name + " :: " +
						  TConvert.AttributesToString(GScanEngine[dataSearch].Files[t].Attributes));
			}

			CloseFile(tf);
		}
	}                 */
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


void TFrameSearch::BuildSearchCharts()
 {
/*	if (GScanEngine[FSource].FileCount != 0) and (GScanEngine[FSource].TotalSize != 0)
	{
		guageSearchQuantity.SetDisplay(((TotalSearchFilesCount + TotalSearchFoldersCount) / (GScanEngine[FSource].FileCount + GScanEngine[FSource].FolderCount)) * 100);
		guageSearchSize.SetDisplay(    ((TotalSearchSize) / GScanEngine[FSource].TotalSize) * 100);
    } */
}
#pragma end_region


#pragma region Tab_Properties
void TFrameSearch::BuildPropertiesTab(int index)
{                    /*
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


/*
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


procedure TFrameSearch.sgSearchResultsEndColumnSize(Sender: TObject; ACol: Integer);
{
  ResizeColumns;
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
}*/
