//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <algorithm>

#include "XFrameFolderHistory.h"

#include "XFormCalendar.h"
#include "XFormChartOptions.h"
#include "XFormDatabaseInfo.h"
#include "XFormXinorbisDialog.h"

#include "ChartUtility.h"
#include "ConstantsGui.h"
#include "ConstantsImages.h"
#include "Convert.h"
#include "FolderHistoryHandler.h"
#include "GridUtility.h"
#include "HelpHandler.h"
#include "ImageHandler.h"
#include "LanguageHandler.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SqlUtility.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "XDatabase.h"

extern FolderHistoryHandler *GFolderHistoryHandler;
extern ImageHandler *GImageHandler;
extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;
extern XDatabase *GXDatabase;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameFolderHistory *FrameFolderHistory;
//---------------------------------------------------------------------------
__fastcall TFrameFolderHistory::TFrameFolderHistory(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------


#pragma region Init
void TFrameFolderHistory::Init()
{
	std::wstring LFA[3];

	CLS = new CompareLeftSide();
	CRS = new CompareRightSide();
	CFLS = new CompareFolderLeftSide();
	CFRS = new CompareFolderRightSide();

	SetTableRowHeights();

	SetHints();

	ChartUtility::SetAdvancedOptions(vtcFolderHistory, GSettingsHandler->Chart);

	LFA[0] = GLanguageHandler->Text[kCreated];
	LFA[1] = GLanguageHandler->Text[kAccessed];
	LFA[2] = GLanguageHandler->Text[kModified];

	// =========================================================================

	miFHCSSaveAll->Caption  = GLanguageHandler->Text[kSaveAll].c_str();
	miFHCSSaveDo->Caption   = GLanguageHandler->Text[kSaveDoExist].c_str();
	miFHCSSaveDont->Caption = GLanguageHandler->Text[kSaveDontExist].c_str();

	// =========================================================================

	miGenericExport->Caption        = (GLanguageHandler->Text[kExportContent] + L"...").c_str();
	miGenericClipboard->Caption     = GLanguageHandler->Text[kCopyTableToClipboard].c_str();
	miGenericClipboardHTML->Caption = (GLanguageHandler->Text[kSaveAs] + L" HTML").c_str();

	// =========================================================================

	miChartOptions->Caption         = GLanguageHandler->Text[kChartOptions].c_str();
	miCOSave->Caption               = GLanguageHandler->Text[kSaveChart].c_str();
	miCOCopy->Caption               = GLanguageHandler->Text[kCopyChartToClipboard].c_str();
	miCOAdvanced->Caption           = GLanguageHandler->Text[kAdvancedOptions].c_str();

	// =========================================================================

	cbCompareUnits->Clear();
	cbCompareUnits->Items->Add(GLanguageHandler->Text[kMostConvenient].c_str());
	cbCompareUnits->Items->Add(GLanguageHandler->Text[kBytes].c_str());
	cbCompareUnits->Items->Add(GLanguageHandler->Text[kKilobytes].c_str());
	cbCompareUnits->Items->Add(GLanguageHandler->Text[kMegabytes].c_str());
	cbCompareUnits->ItemIndex = 0;

	cbCompareFolderInclude->Caption = GLanguageHandler->Text[kIncludeFullPath].c_str();

	tsStats->Caption = L"Stats";
	tsSearch->Caption = GLanguageHandler->Text[kSearch].c_str();

	tsChart->Caption = GLanguageHandler->Text[kChart].c_str();
	tsTable->Caption = GLanguageHandler->Text[kTable].c_str();

	lFolderCount->Caption  = GLanguageHandler->Text[kFolders].c_str();
	lFileCount->Caption  = GLanguageHandler->Text[kFiles].c_str();
	lTotalSize->Caption = GLanguageHandler->Text[kTotalSize].c_str();

	rbChartSize->Caption      = GLanguageHandler->Text[kBySize].c_str();
	rbMagnitudeSize->Caption  = GLanguageHandler->Text[kBySize].c_str();
	rbChartCount->Caption     = GLanguageHandler->Text[kByQuantity].c_str();
	rbMagnitudeCount->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	lSearchDetails->Caption = GLanguageHandler->Text[kSize].c_str();

	cbCompareShowFullPath->Caption  = GLanguageHandler->Text[kShowFullPath].c_str();

	lMagnitude->Caption     = GLanguageHandler->Text[kMagnitude].c_str();

	sbOpenFolder->Caption = GLanguageHandler->Text[kOpen].c_str();

	cbCompareColourCode->Caption  = GLanguageHandler->Text[kColourCode].c_str();
	llFHPleaseWait->Caption = (GLanguageHandler->Text[kLoadingFileHistoryData] + L"...").c_str();

	rbStatsTableToday->Caption= GLanguageHandler->Text[kRelativeToToday].c_str();
	rbStatsTablePrevious->Caption = GLanguageHandler->Text[kRelativeToPrevious].c_str();
	tsSearch->Caption = GLanguageHandler->Text[kFileHistoryCompare].c_str();

	lFHAvailableComputer->Caption  = GLanguageHandler->Text[kFolderHistoryComputer].c_str();
	lFHAvailablePath->Caption      = GLanguageHandler->Text[kFolderHistoryFolder].c_str();

	int lWidth = std::max(lFHAvailableComputer->Width, lFHAvailablePath->Width);

	cbFHAvailableComputer->Left    = lFHAvailableComputer->Left + lWidth + 8;
	cbFHAvailableFilter->Left      = lFHAvailablePath->Left + lWidth + 8;
	cbFHAvailablePath->Left        = cbFHAvailableFilter->Left + 58;
	sbStatsInfo->Left           = cbFHAvailablePath->Left + cbFHAvailablePath->Width + 8;

	bSelectDate->Caption             = GLanguageHandler->Text[kSelectScanDateTime].c_str();
	bCompareLeftDate->Caption        = GLanguageHandler->Text[kSelectScanDateTime].c_str();
	bCompareRightDate->Caption       = GLanguageHandler->Text[kSelectScanDateTime].c_str();
	bCompareFolderLeftDate->Caption  = GLanguageHandler->Text[kSelectScanDateTime].c_str();
	bCompareFolderRightDate->Caption = GLanguageHandler->Text[kSelectScanDateTime].c_str();
	bCompareTreeLeftDate->Caption    = GLanguageHandler->Text[kSelectScanDateTime].c_str();
	bCompareTreeRightDate->Caption   = GLanguageHandler->Text[kSelectScanDateTime].c_str();

	tsCompareFolder->Caption  = GLanguageHandler->Text[kCompareFolder].c_str();
	tsCompareTree->Caption = GLanguageHandler->Text[kCompareFolderTree].c_str();

	tsTimeLine->Caption = GLanguageHandler->Text[kTimeLine].c_str();

	tsSearch->TabVisible = false;

	GImageHandler->SetButtonOffImage(sbFHCLHideCreated,    kImageCreated);
	GImageHandler->SetButtonOffImage(sbFHCLHideAccessed,   kImageAccessed);
	GImageHandler->SetButtonOffImage(sbFHCLHideModified,   kImageModified);
	GImageHandler->SetButtonOffImage(sbFHCLHideOwner,      kImageOwner);
	GImageHandler->SetButtonOffImage(sbFHCLHideAttributes, kImageAttributes);
	GImageHandler->SetButtonOffImage(sbFHCLHideSOD,        kImageSizeOnDisk);

	GImageHandler->SetButtonOffImage(sbFHCRHideCreated,    kImageCreated);
	GImageHandler->SetButtonOffImage(sbFHCRHideAccessed,   kImageAccessed);
	GImageHandler->SetButtonOffImage(sbFHCRHideModified,   kImageModified);
	GImageHandler->SetButtonOffImage(sbFHCRHideOwner,      kImageOwner);
	GImageHandler->SetButtonOffImage(sbFHCRHideAttributes, kImageAttributes);
	GImageHandler->SetButtonOffImage(sbFHCRHideSOD,        kImageSizeOnDisk);

	GImageHandler->SetButtonOffImage(sbCompareLeftShow, 8);
	GImageHandler->SetButtonOffImage(sbCompareRightShow, 8);

	InitDisplayDoOnce();

	if (GSettingsHandler->FolderHistory.Compare[0][0]) sbFHCLHideCreatedClick(sbFHCLHideCreated);
	if (GSettingsHandler->FolderHistory.Compare[0][1]) sbFHCLHideCreatedClick(sbFHCLHideAccessed);
	if (GSettingsHandler->FolderHistory.Compare[0][2]) sbFHCLHideCreatedClick(sbFHCLHideModified);
	if (GSettingsHandler->FolderHistory.Compare[0][3]) sbFHCLHideCreatedClick(sbFHCLHideOwner);
	if (GSettingsHandler->FolderHistory.Compare[0][4]) sbFHCLHideCreatedClick(sbFHCLHideAttributes);
	if (GSettingsHandler->FolderHistory.Compare[0][5]) sbFHCLHideCreatedClick(sbFHCLHideSOD);

	if (GSettingsHandler->FolderHistory.Compare[1][0]) sbFHCRHideCreatedClick(sbFHCRHideCreated);
	if (GSettingsHandler->FolderHistory.Compare[1][1]) sbFHCRHideCreatedClick(sbFHCRHideAccessed);
	if (GSettingsHandler->FolderHistory.Compare[1][2]) sbFHCRHideCreatedClick(sbFHCRHideModified);
	if (GSettingsHandler->FolderHistory.Compare[1][3]) sbFHCRHideCreatedClick(sbFHCRHideOwner);
	if (GSettingsHandler->FolderHistory.Compare[1][4]) sbFHCRHideCreatedClick(sbFHCRHideAttributes);
	if (GSettingsHandler->FolderHistory.Compare[1][5]) sbFHCRHideCreatedClick(sbFHCRHideSOD);

	FHCatButtons[0]  = sbFHCF1;  FHCatButtons[1]  = sbFHCF2;  FHCatButtons[2]  = sbFHCF3;  FHCatButtons[3]  = sbFHCF4;
	FHCatButtons[4]  = sbFHCF5;  FHCatButtons[5]  = sbFHCF6;  FHCatButtons[6]  = sbFHCF7;  FHCatButtons[7]  = sbFHCF8;
	FHCatButtons[8]  = sbFHCF9;  FHCatButtons[9]  = sbFHCF10; FHCatButtons[10] = sbFHCF11; FHCatButtons[11] = sbFHCF12;
	FHCatButtons[12] = sbFHCF13; FHCatButtons[13] = sbFHCF14; FHCatButtons[14] = sbFHCF15; FHCatButtons[15] = sbFHCF16;
	FHCatButtons[16] = sbFHCF17; FHCatButtons[17] = sbFHCF18; FHCatButtons[18] = sbFHCF19; FHCatButtons[19] = sbFHCF20;

	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		GImageHandler->SetFolderHistoryButtonImage(FHCatButtons[t], kImageBase[t]);

		std::wstring hint = FHCatButtons[t]->Hint.c_str();

		hint += L" (" + GLanguageHandler->TypeDescriptionsSmall[t] + L")";

		FHCatButtons[t]->Hint = hint.c_str();
	}
}


void TFrameFolderHistory::InitDisplayDoOnce()
{
	InitCompare();
	InitCompareFolder();

//	LoadSettings();
}


void TFrameFolderHistory::SetTableRowHeights()
{
	sgCompareLeft->DefaultRowHeight        = GSettingsHandler->Appearance.RowHeight;
	sgCompareRight->DefaultRowHeight       = GSettingsHandler->Appearance.RowHeight;
	sgCompareFolderLeft->DefaultRowHeight  = GSettingsHandler->Appearance.RowHeight;
	sgCompareFolderRight->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgStatsTable->DefaultRowHeight         = GSettingsHandler->Appearance.RowHeight;
}


void TFrameFolderHistory::SetHints()
{
	sbFHCLHideCreated->Hint    = GLanguageHandler->Text[kHint1].c_str();
	sbFHCRHideCreated->Hint    = GLanguageHandler->Text[kHint1].c_str();
	sbFHCLHideAccessed->Hint   = GLanguageHandler->Text[kHint2].c_str();
	sbFHCRHideAccessed->Hint   = GLanguageHandler->Text[kHint2].c_str();
	sbFHCLHideModified->Hint   = GLanguageHandler->Text[kHint3].c_str();
	sbFHCRHideModified->Hint   = GLanguageHandler->Text[kHint3].c_str();
	sbFHCLHideOwner->Hint      = GLanguageHandler->Text[kHint4].c_str();
	sbFHCRHideOwner->Hint      = GLanguageHandler->Text[kHint4].c_str();
	sbFHCLHideAttributes->Hint = GLanguageHandler->Text[kHint5].c_str();
	sbFHCRHideAttributes->Hint = GLanguageHandler->Text[kHint5].c_str();
	sbFHCLHideSOD->Hint        = GLanguageHandler->Text[kHint6].c_str();
	sbFHCRHideSOD->Hint        = GLanguageHandler->Text[kHint6].c_str();
	sbCompareLeftShow->Hint    = GLanguageHandler->Text[kHint8].c_str();
	sbCompareRightShow->Hint   = GLanguageHandler->Text[kHint8].c_str();
}
#pragma end_region


#pragma region Application_Control
void TFrameFolderHistory::ResetDisplay(bool aDisableBuildInformationTabs, bool aMode)
{
//	TGridUtility.ConfigureInfoTable(sgFHCDLeft);
//  	TGridUtility.ConfigureInfoTable(sgFHCDRight);

	// =========================================================================

	bSelectDate->Enabled  = aDisableBuildInformationTabs;
	sbGetDate->Enabled = aDisableBuildInformationTabs;

	// =========================================================================

	sgCompareLeft->RowCount = 2;
	lCompareLeftResults->Caption = L"...";

	sgCompareRight->RowCount = 2;
	lCompareRightResults->Caption = L"...";

	// =========================================================================

	vtcFolderHistory->SeriesList->Clear();

	// =========================================================================

//	if Assigned(FOnResetDisplay) then
//	FOnResetDisplay(dataFolderHistory);*/
}
#pragma end_region


#pragma region Application_Settings
void TFrameFolderHistory::LoadSettings()
{
/*var
  t, lChart : integer;
  s : string;
  lReg : TRegistry;

{
  GSettingsHandler->OpenSettings(True);

  if (GSettingsHandler->customsettings.SettingsSaveLocation = SaveLocationConfigIni) then {
    for t = 1 to MaximumFolderHistory do {
      s = GSettingsHandler->ReadStringFromSettings("Prefs", "FHSearchTerm" + IntToStr(t), L"");
   //   if s != L"" then
    //    eFHSearch->Items->Add(s);

      s = GSettingsHandler->ReadStringFromSettings("Prefs", "FHSearchCompareTerm" + IntToStr(t), L"");
      if s != L"" then
        eFHCompareSearch->Items->Add(s);
	};
  }
  else {
    lReg = TRegistry.Create(KEY_READ);

    try
      lReg.RootKey = HKEY_CURRENT_USER;
      lReg.OpenKey("\software\" + XinorbisRegistryKey + "\FHSearchTerm", True);

      t = 0;
      While lReg.ValueExists("Term" + IntToStr(t)) do {
	 //   eFHSearch->Items->Add(lReg.ReadString("Term" + IntToStr(t)));
        inc(t);
      };
    finally
      lReg.Free;
    };

	lReg = TRegistry.Create(KEY_READ);

    try
      lReg.RootKey = HKEY_CURRENT_USER;
      lReg.OpenKey("\software\" + XinorbisRegistryKey + "\FHCompareSearchTerm", True);

      t = 0;
      While lReg.ValueExists("Term" + IntToStr(t)) do {
        eFHCompareSearch->Items->Add(lReg.ReadString("Term" + IntToStr(t)));
        inc(t);
	  };
	finally
	  lReg.Free;
	};
  };

  // ===========================================================================

  for t = 1 to __ChartCount do {
	lChart = GSettingsHandler->ReadIntegerFromSettings("Charts", "FileHistory_" + IntToStr(t), 0, -1);

	ChartUtility::SetChartType(FCharts[t], lChart);
  };

  GSettingsHandler->CloseSettings; */
}


void TFrameFolderHistory::SaveSettings()
{
/*  t : integer;
  lReg : TRegistry;

{
  GSettingsHandler->OpenSettings(False);

  GSettingsHandler->WriteBoolToSettings("FHCompare", "X1Y1", sgFHCompareLeft.IsHiddenColumn(sbFHCLHideCreated->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X1Y2", sgFHCompareLeft.IsHiddenColumn(sbFHCLHideAccessed->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X1Y3", sgFHCompareLeft.IsHiddenColumn(sbFHCLHideModified->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X1Y4", sgFHCompareLeft.IsHiddenColumn(sbFHCLHideOwner->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X1Y5", sgFHCompareLeft.IsHiddenColumn(sbFHCLHideAttributes->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X1Y6", sgFHCompareLeft.IsHiddenColumn(sbFHCLHideSOD->Tag));

  GSettingsHandler->WriteBoolToSettings("FHCompare", "X2Y1", sgFHCompareRight.IsHiddenColumn(sbFHCRHideCreated->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X2Y2", sgFHCompareRight.IsHiddenColumn(sbFHCRHideAccessed->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X2Y3", sgFHCompareRight.IsHiddenColumn(sbFHCRHideModified->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X2Y4", sgFHCompareRight.IsHiddenColumn(sbFHCRHideOwner->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X2Y5", sgFHCompareRight.IsHiddenColumn(sbFHCRHideAttributes->Tag));
  GSettingsHandler->WriteBoolToSettings("FHCompare", "X2Y6", sgFHCompareRight.IsHiddenColumn(sbFHCRHideSOD->Tag));

  if (GSettingsHandler->customsettings.SettingsSaveLocation = SaveLocationConfigIni) then {
  {  if eFHSearch->Items->Count != 0 then {
	  for t = 0 to eFHSearch->Items->Count - 1 do {
		GSettingsHandler->WriteStringToSettings("Prefs", "FHSearchTerm" + IntToStr(t + 1), eFHSearch->Items[t]);
	  };
	};    }

	if eFHCompareSearch->Items->Count != 0 then {
	  for t = 0 to eFHCompareSearch->Items->Count - 1 do {
		GSettingsHandler->WriteStringToSettings("Prefs", "FHSearchCompareTerm" + IntToStr(t + 1), eFHCompareSearch->Items[t]);
	  };
	};
  }
  else {
   { if eFHSearch->Items->Count != 0 then {
	  lReg = TRegistry.Create(KEY_WRITE);

	  try
		lReg.RootKey = HKEY_CURRENT_USER;
		lReg.OpenKey("\software\" + XinorbisRegistryKey + "\FHSearchTerm", True);

		for t = 0 to eFHSearch->Items->Count - 1 do
		  if t < 20 then lReg.WriteString("Term" + IntToStr(t), eFHSearch->Items[t]);
	  finally
	   lReg.Free;
	  };
	};    }

	if eFHCompareSearch->Items->Count != 0 then {
	  lReg = TRegistry.Create(KEY_WRITE);

	  try
		lReg.RootKey = HKEY_CURRENT_USER;
		lReg.OpenKey("\software\" + XinorbisRegistryKey + "\FHCompareSearchTerm", True);

		for t = 0 to eFHCompareSearch->Items->Count - 1 do
		  if t < 20 then lReg.WriteString("Term" + IntToStr(t), eFHCompareSearch->Items[t]);
	  finally
		lReg.Free;
	  };
	};
  };

  // ===========================================================================

  for t = 1 to __ChartCount do {
	GSettingsHandler->WriteIntegerToSettings("Charts", "FileHistory_" + IntToStr(t), ChartUtility::GetChartType(FCharts[t]));
  };

  GSettingsHandler->CloseSettings; */
}
#pragma end_region


#pragma region Application_Hooks
#pragma end_region


#pragma region Public_Stuff
int TFrameFolderHistory::GetActivePage()
{
	return pcStats->ActivePageIndex;
}


void TFrameFolderHistory::SetActivePage(int page)
{
	pcStats->ActivePageIndex = page;
}


std::wstring TFrameFolderHistory::GetSelectedPath()
{
	return cbFHAvailablePath->Text.c_str();
}


std::wstring TFrameFolderHistory::GetSelectedComputer()
{
	return cbFHAvailableComputer->Text.c_str();
}


std::wstring TFrameFolderHistory::GetFolderHistoryItem(int index)
{
	if (index < clbFolderHistory->Items->Count)
	{
		return clbFolderHistory->Items->Strings[index].c_str();
	}

	return L"";
}


std::wstring TFrameFolderHistory::GetFolderHistoryItemSelected()
{
	return clbFolderHistory->Items->Strings[bSelectDate->Tag].c_str();
}


void TFrameFolderHistory::DoFHSearch(const std::wstring search_term)
{
}


void TFrameFolderHistory::DoCompareSearch(const std::wstring search_term)
{
	if (!search_term.empty())
	{
		eCompareSearch->Text = search_term.c_str();

		sbGoSearchClick(NULL);
	}
}


void TFrameFolderHistory::DoCompareDriveSearch(const std::wstring search_term)
{
	if (!search_term.empty())
	{
		eCompareFolderSearch->Text = search_term.c_str();

		sbCompareFolderSearchClick(NULL);
	}
}


bool TFrameFolderHistory::GetAvailablePathContains(const std::wstring path)
{
	if (cbFHAvailablePath->Items->IndexOf(path.c_str()) == -1)
	{
		return true;
	}

    return false;
}
#pragma end_region


#pragma region Tab_Stats
void __fastcall TFrameFolderHistory::pcStatsResize(TObject *Sender)
{
	sgStatsTable->ColWidths[0]  = sgStatsTable->Width - 603;
	sgStatsTable->ColWidths[1]  = 70;
	sgStatsTable->ColWidths[2]  = 70;
	sgStatsTable->ColWidths[3]  = 6;
	sgStatsTable->ColWidths[4]  = 70;
	sgStatsTable->ColWidths[5]  = 70;
	sgStatsTable->ColWidths[6]  = 6;
	sgStatsTable->ColWidths[7]  = 70;
	sgStatsTable->ColWidths[8]  = 70;
	sgStatsTable->ColWidths[9]  = 6;
	sgStatsTable->ColWidths[10] = 70;
	sgStatsTable->ColWidths[11] = 70;
}


void __fastcall TFrameFolderHistory::sbOpenFolderClick(TObject *Sender)
{
	bool dbExists = true;

	if (!GSettingsHandler->Database.UseODBC)
	{
		std::wstring db_file_name = GSystemGlobal->AppDataPath + L"Database\\Xinorbis.db";

		if (FileExists(db_file_name.c_str()))
		{
			dbExists = false;
		}
	}

	if (dbExists)
	{
		if (cbFHAvailablePath->Text != L"")
		{
			GScanEngine->Data[kDataFolderHistory].Path.String = cbFHAvailablePath->Text.c_str();

			pcStats->Visible = true;         // to do make sure new layout
			tsSearch->TabVisible = true;

			ResetDisplay(true, false);

			BuildFolderHistory(cbFHAvailableComputer->Text.c_str(),
			                   cbFHAvailablePath->Text.c_str());

			BuildTimeLine();
		}
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kNoFHFSelected], XDialogTypeWarning);
	}
}


void __fastcall TFrameFolderHistory::cbFHAvailableComputerChange(TObject *Sender)
{
	cbFHAvailableFilter->Items->Clear();
	cbFHAvailableFilter->Items->Add(L"*");
	cbFHAvailableFilter->Sorted = true;
	cbFHAvailablePath->Items->Clear();

	for (FolderHistoryInfo *fhi : GFolderHistoryHandler->FolderHistoryAvailable)
	{
		if (fhi->ComputerName == cbFHAvailableComputer->Items->Strings[cbFHAvailableComputer->ItemIndex].c_str())
		{
			std::wstring s = L"";

			if (fhi->ScanPath[0] == L'\\') // looks for \\ at beginning of path
			{
				s = L"\\";
			}
			else
			{
				s = fhi->ScanPath.substr(0, 3);
			}

			if (cbFHAvailableFilter->Items->IndexOf(s.c_str()) == -1)
			{
				cbFHAvailableFilter->Items->Add(s.c_str());
			}

			cbFHAvailablePath->Items->Add(fhi->ScanPath.c_str());
		}
	}

	if (cbFHAvailablePath->Tag < cbFHAvailablePath->Items->Count && cbFHAvailablePath->Tag != -1)
	{
		cbFHAvailablePath->ItemIndex = cbFHAvailablePath->Tag;
	}
	else
	{
		cbFHAvailableFilter->ItemIndex = 0;
		cbFHAvailablePath->ItemIndex   = 0;
	}

	cbFHAvailablePath->Refresh();
}


void __fastcall TFrameFolderHistory::cbFHAvailableFilterChange(TObject *Sender)
{
	bool include_all = false;

	cbFHAvailablePath->Items->Clear();

	if (cbFHAvailableFilter->Text == L"*")
	{
		include_all = true;
	}

	for (FolderHistoryInfo *fhi : GFolderHistoryHandler->FolderHistoryAvailable)
	{
		if (fhi->ComputerName == cbFHAvailableComputer->Items->Strings[cbFHAvailableComputer->ItemIndex].c_str())
		{
			if (include_all)
			{
				cbFHAvailablePath->Items->Add(fhi->ScanPath.c_str());
			}
			else
			{
				if (fhi->ScanPath.rfind(cbFHAvailableFilter->Text.c_str(), 0) == 0)
				{
					cbFHAvailablePath->Items->Add(fhi->ScanPath.c_str());
				}
			}
		}
	}

	if (cbFHAvailablePath->Tag < cbFHAvailablePath->Items->Count && cbFHAvailablePath->Tag != -1)
	{
		cbFHAvailablePath->ItemIndex = cbFHAvailablePath->Tag;
	}
	else
	{
		cbFHAvailablePath->ItemIndex   = 0;
	}

	cbFHAvailablePath->Refresh();
}


void __fastcall TFrameFolderHistory::cbFHAvailablePathChange(TObject *Sender)
{
	ResetDisplay(false, false);

	cbFHAvailablePath->Tag = cbFHAvailablePath->ItemIndex;

	bSelectDate->Caption = GLanguageHandler->Text[kSelectDateTime].c_str();
	bSelectDate->Enabled = false;
	bSelectDate->Tag     = -1;

	// ===========================================================================

	bCompareLeftDate->Caption  = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareRightDate->Caption = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareLeftDate->Tag      = -1;
	bCompareRightDate->Tag     = -1;

	bCompareFolderLeftDate->Caption  = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareFolderRightDate->Caption = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareFolderLeftDate->Tag      = -1;
	bCompareFolderRightDate->Tag     = -1;

	bCompareTreeLeftDate->Caption  = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareTreeRightDate->Caption = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareTreeLeftDate->Tag      = -1;
	bCompareTreeRightDate->Tag     = -1;

	tvCompareLeft->Items->Clear();
	tvCompareRight->Items->Clear();

	// =========================================================================

	if (OnUpdateLeftStatusPanel)
	{
		OnUpdateLeftStatusPanel(0);
	}
}


void __fastcall TFrameFolderHistory::sbStatsInfoClick(TObject *Sender)
{
	std::wstring path = cbFHAvailablePath->Text.c_str();

	std::transform(path.begin(), path.end(), path.begin(), ::toupper);

	OpenDatabaseInformation(cbFHAvailableComputer->Text.c_str(), path);
}


void __fastcall TFrameFolderHistory::sbGetDateClick(TObject *Sender)
{
	std::vector<std::wstring> data;

	for (int t = 0; t < clbFolderHistory->Items->Count; t++) data.push_back(clbFolderHistory->Items->Strings[t].c_str());

	std::wstring s = OpenCalendar(data);

	if (!s.empty())
	{
		int date = stoi(s.substr(0, 8));

		std::wstring dx = Convert::IntDateToString(date) + L" " +
						  s.substr(8, 2) + L":" + s.substr(10, 2) + L":" + s.substr(12, 2);

		int i = FindFolderHistoryItem(dx);

		if (i != -1)
		{
			bSelectDate->Tag     = i;
			bSelectDate->Caption = dx.c_str();

			if (bSelectDate->Tag != -1)
			{
				BuildInformationTabs();
			}
		}
	}
}


void __fastcall TFrameFolderHistory::bSelectDateClick(TObject *Sender)
{
	puFHSelectDate->Tag = 1;

	TPoint mouse_pos = Mouse->CursorPos;

	puFHSelectDate->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameFolderHistory::pcStatsChange(TObject *Sender)
{
	if (OnSetTutorialBarText)
	{
		OnSetTutorialBarText(GSystemGlobal->ExePath + L"data\\languages\\" +
							 GLanguageHandler->GetLanguageSymbol() +
							 L"\\tutorial\\fht" + std::to_wstring(pcStats->ActivePageIndex) + L".dat");  // to do make sure new layout
	}

/*	if tpFHStats.ActivePageIndex = 5)
	{
		atlFolderHistory.VerticalMargin = Round(atlFolderHistory.Height / 2) - 10;
	}*/
}


void TFrameFolderHistory::BuildFolderHistorySelectDataMenu()
{
	bSelectDate->Tag = -1;
	TMenuItem *LastYearNode   = nullptr;
	TMenuItem *LastMonthNode  = nullptr;
	TMenuItem *LastDayNode    = nullptr;

	int lyy = -1;
	int lmm = -1;
	int ldd = -1;

	puFHSelectDate->Items->Clear();

	for (int t = 0; t < clbFolderHistory->Count; t++)
	{
		std::wstring list_item = clbFolderHistory->Items->Strings[t].c_str();

		std::wstring date = Convert::DateTimeFToYYYYMMDD(list_item);

		if (!date.empty())
		{
			int cyy = stoi(date.substr(0, 4));
			int cmm = stoi(date.substr(4, 2));
			int cdd = stoi(date.substr(6, 2));

			if (cyy != lyy)
			{
				TMenuItem *mi = new TMenuItem(puFHSelectDate);
				mi->Caption = cyy;

				puFHSelectDate->Items->Add(mi);
				LastYearNode = mi;

				lyy = cyy;
			}

			if (cmm != lmm)
			{
				TMenuItem *mi = new TMenuItem(puFHSelectDate);
				mi->Caption = GLanguageHandler->Months[cmm].c_str();

				LastYearNode->Add(mi);
				LastMonthNode = mi;

				lmm = cmm;
			}

			if (cdd != ldd)
			{
				TMenuItem *mi = new TMenuItem(puFHSelectDate);
				mi->Caption = IntToStr(cdd);

				LastMonthNode->Add(mi);
				LastDayNode = mi;

				ldd = cdd;
			}

			TMenuItem *mi = new TMenuItem(puFHSelectDate);
			mi->OnClick = miSelectDateTimeClick;
			mi->Caption = list_item.substr(11, 8).c_str();
			mi->Tag     = t;

			LastDayNode->Add(mi);
		}
	}
}


void TFrameFolderHistory::BuildFolderHistoryAvailable()
{
/* var
  sr : TSearchRec;
  tf : TextFile;
  fha : TFolderHistoryInfo;
  sp, thispc  : string;
  t, tpxidx : integer;

	auto GetPathFromFHFile = [](const std::wstring file_name) -> std::wstring
	{
		if (file)
		{
			Readln(tf, s);

			CloseFile(tf);

			return s;
		}

		ShowXDialog(GLanguageHandler->Text[kError] + ": " + GLanguageHandler->Text[kFolderHistory],
					GLanguageHandler->Text[kErrorOpening] + " L"" + filename + L"".",
					XDialogTypeWarning);

		return L"";
	};

	auto GetComputerNameFromPath = [](const std::wstring file_name) -> std::wstring
	{
		std::wstring s = L"";
		z = Pos("FOLDERHISTORY\", UpperCase(FileName));

		i = z + 14;

		while FileName[i] != "\" do
		{
			s = s + FileName[i];

			inc(i);
		}

		return s;
	};


	if (GSettingsHandler->HistorySettings->Enabled) and (GSettingsHandler->System.UserEnabledFH)
	{
		cbFHAvailablePath->Items->Clear;
		cbFHAvailableComputer->Items->Clear;
		FolderHistoryAvailable.Clear;

		thispc = TXWindows.GetComputerNetName;
		tpxidx = 0;

		if (GFolderHistoryHandler->PopulateAvailable(GSystemGlobal.AppDataPath + "folderhistory\" + thispc + "\"))
		{
			// now we populate the GUI with the new details
			for (FolderHistoryInfo *fhi : GFolderHistoryHandler->FolderHistoryAvailable)
			{
				if cbFHAvailableComputer->Items->IndexOf(fhi.ComputerName) = -1)
				{
					cbFHAvailableComputer->Items->Add(fhi.ComputerName);
				}

				if fhi.ComputerName = thispc)
				{
					tpxidx = cbFHAvailableComputer->Items->Count - 1;
				}
			}

			FolderHistoryAvailable.Sort(TComparer<TFolderHistoryInfo>.Construct(CompareFHPaths));

			cbFHAvailableComputer->ItemIndex = tpxidx;

			cbFHAvailableComputerChange(Nil);

			if cbFHAvailableComputer->Items->Count = 0
			{
				cbFHAvailableComputer->Items->Add(thispc);
				cbFHAvailableComputer->ItemIndex = 0;
			}

			cbFHAvailableComputer->Tag = -1;
			cbFHAvailablePath->Tag     = -1;
		}
	}*/
}


void TFrameFolderHistory::BuildFolderHistory(const std::wstring computer_name, const std::wstring scan_path)
{
	bSelectDate->Caption = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareLeftDate->Caption  = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareRightDate->Caption = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareFolderLeftDate->Caption  = GLanguageHandler->Text[kSelectDateTime].c_str();
	bCompareFolderRightDate->Caption = GLanguageHandler->Text[kSelectDateTime].c_str();

	bSelectDate->Tag             = -1;
	bSelectDate->Enabled         = true;
	bCompareRightDate->Tag       = -1;
	bCompareRightDate->Tag       = -1;
	bCompareFolderLeftDate->Tag  = -1;
	bCompareFolderRightDate->Tag = -1;

	GFolderHistoryHandler->FolderHistory.clear();

	clbFolderHistory->Items->Clear();

//	sgCompareLeft.ClearRows(1, sgFHCompareLeft->RowCount - 1);
//	sgCompareRight.ClearRows(1, sgFHCompareRight->RowCount - 1);
	sgCompareLeft->RowCount  = 2;
	sgCompareRight->RowCount = 2;

	std::vector<std::wstring> data;

	if (GFolderHistoryHandler->Load(computer_name, scan_path, data))
	{
		BuildFolderHistoryTable();  // "data" goes in here?!

		// =================================================================

		ChartUtility::BuildFolderHistoryGraph(scan_path, vtcFolderHistory, data,
											  rbChartCount->Checked, rbChartSize->Checked,
											  rbMagnitudeCount->Checked, rbMagnitudeSize->Checked);

		if (clbFolderHistory->Count != 0)
		{
			clbFolderHistory->Checked[0] = true;
			clbFolderHistory->ItemIndex = 0;

			rbChartCountClick(NULL);
		}

		if (clbFolderHistory->Count != 0)
		{
			FileHistoryControlStatus(true);
		}
		else
		{
			FileHistoryControlStatus(false);
		}
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kError] + L" :: " + GLanguageHandler->Text[kFolderHistory],
					L"Error building File History!",
				XDialogTypeWarning);

		//std::wstring file_name = GSystemGlobal->AppDataPath + L"FolderHistory\\" + computer_name + L"\\" + Utility::GetMD5(UpperCase(scan_path)) + L"xfh";

	   //	if (FileExists(file_name.c_str()))
	   //	{
//			if (MessageDlg(GLanguageHandler->Text[kDialog7] + #13#13 + GLanguageHandler->Text[kDialog8], mtInformation, [mbYes, mbNo], 0) = mrYes then {
// to do				RepairFile(TMD5.Generate(UpperCase(ScanPath)) + ".xfh", GSystemGlobal.AppDataPath + "FolderHistory\" + ComputerName + "\" + TMD5.Generate(scan_path) + ".xfh");
//			}
	  //	}
	}

	BuildFolderHistorySelectDataMenu();
}


void TFrameFolderHistory::RepairFile(const std::wstring scan_path, const std::wstring file_name)
{
/*	if RenameFile(FileName, ExtractFilePath(FileName) + scanpath)
	{
		ShowXDialog(GLanguageHandler->Text[kWarning],
					GLanguageHandler->Text[kDialog5],
					XDialogTypeInformation)
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kWarning],
					GLanguageHandler->Text[kDialog6],
					XDialogTypeInformation);
	} */
}


void TFrameFolderHistory::FileHistoryControlStatus(bool newstatus)
{
	bSelectDate->Enabled = newstatus;
	sbGetDate->Enabled = newstatus;

	rbChartCount->Enabled = newstatus;
	rbChartSize->Enabled = newstatus;
	rbMagnitudeCount->Enabled = newstatus;
	rbMagnitudeSize->Enabled = newstatus;

	rbStatsTableToday->Enabled = newstatus;
	rbStatsTablePrevious->Enabled = newstatus;

	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		FHCatButtons[t]->Enabled = newstatus;
	}

	sbCompareFavourites->Enabled       = newstatus;
	sbCompareFolderFavourites->Enabled = newstatus;
	sbGoSearch->Enabled                = newstatus;
	sbSearchSyntax->Enabled            = newstatus;
	eCompareSearch->Enabled            = newstatus;
	cbCompareUnits->Enabled            = newstatus;
	cbCompareShowFullPath->Enabled     = newstatus;
	cbCompareColourCode->Enabled       = newstatus;
	sbCompareFolderLeftSave->Enabled   = newstatus;
	sbCompareFolderRightSave->Enabled  = newstatus;

	sbCompareFolderSearch->Enabled    = newstatus;
	eCompareFolderSearch->Enabled      = newstatus;
	sbCompareFolderLeftSave->Enabled  = newstatus;
	sbCompareFolderRightSave->Enabled = newstatus;
}
#pragma end_region


#pragma region Tab_Stats_Chart
void __fastcall TFrameFolderHistory::cbChartFilesClick(TObject *Sender)
{
	if (cbChartFiles->Checked)
	{
		pStatsChartFiles->Height = 102;
	}
	else
	{
		pStatsChartFiles->Height = 21;
	}
}


void __fastcall TFrameFolderHistory::rbChartCountClick(TObject *Sender)
{
	if (clbFolderHistory->ItemIndex != -1)
	{
		int fhidx = (GFolderHistoryHandler->FolderHistory.size() - clbFolderHistory->ItemIndex) - 1;

		lFileCountValue->Caption   = GFolderHistoryHandler->FolderHistory[fhidx]->FileCount;
		lTotalSizeValue->Caption   = Convert::ConvertToUsefulUnit(GFolderHistoryHandler->FolderHistory[fhidx]->FileSize).c_str();
		lFolderCountValue->Caption = IntToStr(GFolderHistoryHandler->FolderHistory[fhidx]->FolderCount);
	}

	std::vector<std::wstring> selection_list; // copy from clbfolderhistory selected.

	ChartUtility::BuildFolderHistoryGraph(GScanEngine->Data[kDataFolderHistory].Path.String,
										  vtcFolderHistory,
										  selection_list,
										  rbChartCount->Checked, rbChartSize->Checked, rbMagnitudeCount->Checked, rbMagnitudeSize->Checked);
}


void __fastcall TFrameFolderHistory::cbChartCategoryClick(TObject *Sender)
{
	if (cbChartCategory->Checked)
	{
		pStatsChartCategory->Height = 164;
	}
	else
	{
		pStatsChartCategory->Height = 21;
	}
}


void __fastcall TFrameFolderHistory::sbFHCF1Click(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	GSettingsHandler->FolderHistory.CCStatus[sb->Tag] = !GSettingsHandler->FolderHistory.CCStatus[sb->Tag];

    int idx = -1;

	if (GSettingsHandler->FolderHistory.CCStatus[sb->Tag])
	{
		idx = kImageBase[sb->Tag];
	}
	else
	{
		idx = kImageBase[sb->Tag] + 1;
	}

	GImageHandler->SetFolderHistoryButtonImage(sb, idx);

//	rbFHCountClick(Nil);*/
}
#pragma end_region


#pragma region Tab_Stats_Table
void TFrameFolderHistory::InitTableStats()
{
	//sgStatsTable.ClearRows(1, sgStatsTable->RowCount - 1);
	sgStatsTable->RowCount = 2;

	sgStatsTable->Cells[ 0][0] = GLanguageHandler->Text[kDate].c_str();
	sgStatsTable->Cells[ 1][0] = GLanguageHandler->Text[kFiles].c_str();
	sgStatsTable->Cells[ 2][0] = GLanguageHandler->Text[kDelta].c_str();
	sgStatsTable->Cells[ 4][0] = GLanguageHandler->Text[kFolders].c_str();
	sgStatsTable->Cells[ 5][0] = GLanguageHandler->Text[kDelta].c_str();
	sgStatsTable->Cells[ 7][0] = GLanguageHandler->Text[kTotalSize].c_str();
	sgStatsTable->Cells[ 8][0] = GLanguageHandler->Text[kDelta].c_str();
	sgStatsTable->Cells[10][0] = GLanguageHandler->Text[kUsedSpace].c_str();
	sgStatsTable->Cells[11][0] = GLanguageHandler->Text[kDelta].c_str();
}


void __fastcall TFrameFolderHistory::rbStatsTableTodayClick(TObject *Sender)
{
	BuildFolderHistoryTable();
}


void __fastcall TFrameFolderHistory::sgStatsTableDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*  if (ACol > 0 && ARow > 0)
	{
		if sgStatsTable->Cells[ACol][ARow] != L""
		{
			if gdSelected in State
			{
				sgStatsTable->Canvas->Brush->Color = sgStatsTable.SelectionColor;
			}
			else
			{
				if odd(ARow)
				{
					sgStatsTable->Canvas->Brush->Color = sgStatsTable.Bands.PrimaryColor
				}
				else
				{
					sgStatsTable->Canvas->Brush->Color = $00FFFFFF;
				}
			}

			//sgStatsTable->Canvas.FillRect(Rect);
			//sgStatsTable->Canvas->TextRect(Rect, Rect.Left + sgStatsTable->ColWidths[ACol] - sgStatsTable->Canvas->TextWidth(sgStatsTable->Cells[ACol, ARow]) - 5, Rect.Top + 1, sgStatsTable->Cells[ACol, ARow]);
		}
	}*/
}


void TFrameFolderHistory::BuildFolderHistoryTable()
{
	//TGridUtility.ClearStringGird(sgStatsTable, False);

	// now build table ===========================================================

	sgStatsTable->BeginUpdate();

	sgStatsTable->RowCount = 1 + clbFolderHistory->Items->Count;

	int i = clbFolderHistory->Items->Count;

	if (rbStatsTablePrevious->Checked)
	{
		for (int t = 0; t < clbFolderHistory->Items->Count; t++)
		{
			FolderHistoryObject *fho = GFolderHistoryHandler->FolderHistory[t];
			FolderHistoryObject *fhop = GFolderHistoryHandler->FolderHistory[t - 1];

			sgStatsTable->Cells[ 0][i] = fho->ScanDateStr.c_str();

			sgStatsTable->Cells[ 1][i] = fho->FileCount;
			sgStatsTable->Cells[ 4][i] = fho->FolderCount;
			sgStatsTable->Cells[ 7][i] = Convert::ConvertToUsefulUnit(fho->FileSize).c_str();
			sgStatsTable->Cells[10][i] = Convert::ConvertToUsefulUnit(fho->FileSizeOnDisk).c_str();

			if (t == 0)
			{
				sgStatsTable->Cells[ 2][i] = L"";
				sgStatsTable->Cells[ 5][i] = L"";
				sgStatsTable->Cells[ 8][i] = L"";
				sgStatsTable->Cells[11][i] = L"";
			}
			else
			{
				sgStatsTable->Cells[ 2][i] = Convert::GetDelta(fho->FileCount - fhop->FileCount).c_str();

				sgStatsTable->Cells[ 5][i] = Convert::GetDelta(fho->FolderCount - fhop->FolderCount).c_str();

				sgStatsTable->Cells[ 8][i] = Convert::GetDeltaSize(fho->FileSize - fhop->FileSize).c_str();

				sgStatsTable->Cells[11][i] = Convert::GetDeltaSize(fho->FileSizeOnDisk - fhop->FileSizeOnDisk).c_str();
			}

			i++;
		}
	}
	else
	{
		for (int t = 0; t < clbFolderHistory->Items->Count; t++)
		{
			FolderHistoryObject *fho = GFolderHistoryHandler->FolderHistory[t];
			FolderHistoryObject *fhol = GFolderHistoryHandler->FolderHistory[clbFolderHistory->Items->Count - 1];

			sgStatsTable->Cells[ 0][i] = fho->ScanDateStr.c_str();

			sgStatsTable->Cells[ 1][i] = fho->FileCount;
			sgStatsTable->Cells[ 4][i] = fho->FolderCount;
			sgStatsTable->Cells[ 7][i] = Convert::ConvertToUsefulUnit(fho->FileSize).c_str();
			sgStatsTable->Cells[10][i] = Convert::ConvertToUsefulUnit(fho->FileSizeOnDisk).c_str();

			if (t == clbFolderHistory->Items->Count - 1)
			{
				sgStatsTable->Cells[ 2][i] = L"";
				sgStatsTable->Cells[ 5][i] = L"";
				sgStatsTable->Cells[ 8][i] = L"";
				sgStatsTable->Cells[11][i] = L"";
			}
			else
			{
				sgStatsTable->Cells[ 2][i] = Convert::GetDelta(fho->FileCount - fhol->FileCount).c_str();

				sgStatsTable->Cells[ 5][i] = Convert::GetDelta(fho->FolderCount - fhol->FolderCount).c_str();

				sgStatsTable->Cells[ 8][i] = Convert::GetDeltaSize(fho->FileSize - fhol->FileSize).c_str();

				sgStatsTable->Cells[11][i] = Convert::GetDelta(fho->FileSizeOnDisk - fhol->FileSizeOnDisk).c_str();
			}

			i++;
		}
	}

	sgStatsTable->EndUpdate();
}
#pragma end_region


#pragma region Tab_Stats_TimeLine
/*procedure TFrameFolderHistory.atlFolderHistoryDblClick(Sender: TObject);
{
	sbTLResetClick(Nil);
}


procedure TFrameFolderHistory.atlFolderHistoryIndicatorClick(
  Sender: TObject; indicator: TAdvSmoothTimeLineBarIndicator);
var
  lFHId : integer;

{
  lFHId = indicator->Tag;

  lFHTLIndicatorDetails->Caption = Convert::DateToString(FolderHistory[lFHID].ScanDate) +
									   " @" + Convert::TimeToString(FolderHistory[lFHID].ScanDate, True) +
									   " <b>" + IntToStr(FolderHistory[lFHId].FileCount) + "</b> " + GLanguageHandler->Text[kFiles] +
									   " (<b>" + Convert::ConvertToUsefulUnit(FolderHistory[lFHId].FileSize) + "</b>)";
};


procedure TFrameFolderHistory.atlFolderHistoryMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
{
  lFHTLUnderCursor->Caption = Convert::DateToString(atlFolderHistory.XToDateTime(X));
}


procedure TFrameFolderHistory.sbTLResetClick(Sender: TObject);
{
  atlFolderHistory.Range.RangeFrom = oldTLFrom;
  atlFolderHistory.Range.RangeTo   = oldTLTo;

  atlFolderHistory.Resize;
};


procedure TFrameFolderHistory.sbTLSaveClick(Sender: TObject);
var
  lFileName : string;

{
  lFileName = SaveDialogs::ExecuteImages(TUtility.GetDefaultFileName(".png", GLanguageHandler->Text[kTimeLine]));

  if lFileName != L"" then {
    try
      atlFolderHistory.SaveToImage(lFileName,
                                   atlFolderHistory->Width, atlFolderHistory.Height,
                                   itPNG);
    except
      on e : exception do {
        ShowXDialog(GLanguageHandler->Text[kWarning],
                    GLanguageHandler->Text[kErrorSaving] + " L"" + lFileName + L"". " + e.ClassName + " / " + e.Message,
                    XDialogTypeWarning);
	  };
    };
  };*/


void TFrameFolderHistory::BuildTimeLine()
{/*
var
  t : integer;
  lRangeFrom, lRangeTo : TDateTime;

{
  if GFolderHistoryHandler->FolderHistory.size() != 0 then {
	lRangeFrom = Now;
	lRangeTo   = EncodeDate(1975, 01, 01);

	atlFolderHistory.{Update;

	atlFolderHistory.RangeAppearance.DivisionFormat = Convert::GetDateFormat + " hh:nn";

	atlFolderHistory.TimeLineIndicators.Clear;

	for t = 0 to FolderHistory.Count - 1 do {
      with atlFolderHistory.TimeLineIndicators.Add do {
        Shape           = isDiamond;

        Position        = FolderHistory[t].ScanDate;

        AnnotationColor = spectrumcolours[t mod spectrummod];

        Color           = clWhite;
        ColorTo         = AnnotationColor;

        Annotation      = IntToStr(FolderHistory[t].FileCount) + " " + GLanguageHandler->Text[kFiles] + " (" + Convert::ConvertToUsefulUnit(FolderHistory[t].FileSize) + ")";

        Fixed           = True;

        Tag             = t;

        if odd(t) then
          AnnotationPosition = apOnTop
        else
          AnnotationPosition = apAtBottom;

        if FolderHistory[t].ScanDate < lRangeFrom then
          lRangeFrom = FolderHistory[t].ScanDate;

        if FolderHistory[t].ScanDate > lRangeTo then
          lRangeTo = FolderHistory[t].ScanDate;
      };
    };

	atlFolderHistory.}Update;

    atlFolderHistory.Range.MinimumRange = IncDay(lRangeFrom, -7);
    atlFolderHistory.Range.MaximumRange = IncDay(lRangeTo, 7);

	atlFolderHistory.Range.RangeFrom    = lRangeFrom;
	atlFolderHistory.Range.RangeTo      = lRangeTo;

	oldTLFrom = lRangeFrom;
	oldTLTo   = lRangeTo;

	sbTLResetClick(nil);
  }; */
}
#pragma end_region


#pragma region Tab_Generic
void __fastcall TFrameFolderHistory::ShowCalendar(TObject *Sender)
{
	std::vector<std::wstring> data;

	for (int t = 0; t < clbFolderHistory->Items->Count; t++) data.push_back(clbFolderHistory->Items->Strings[t].c_str());

	std::wstring s = OpenCalendar(data);

	if (!s.empty())
	{
		int date = stoi(s.substr(0, 8));

		std::wstring dx = Convert::IntDateToString(date) + L" " +
						  s.substr(8, 2) + L":" + s.substr(10, 2) + L":" + s.substr(12, 2);

		int i = FindFolderHistoryItem(dx);

		if (i != -1)
		{
			TSpeedButton *sb = (TSpeedButton*)Sender;

			switch (sb->Tag)
			{
			case kCompareLeft:
				bCompareLeftDate->Tag     = i;
				bCompareLeftDate->Caption = dx.c_str();
				break;
			case kCompareRight:
				bCompareRightDate->Tag     = i;
				bCompareRightDate->Caption = dx.c_str();
				break;
			case kCompareFolderLeft:
				bCompareFolderLeftDate->Tag     = i;
				bCompareFolderLeftDate->Caption = dx.c_str();
				break;
			case kCompareFolderRight:
				bCompareFolderRightDate->Tag     = i;
				bCompareFolderRightDate->Caption = dx.c_str();
				break;
			case kCompareTreeLeft:
				bCompareTreeLeftDate->Tag     = i;
				bCompareTreeLeftDate->Caption = dx.c_str();
				break;
			case kCompareTreeRight:
				bCompareTreeRightDate->Tag     = i;
				bCompareTreeRightDate->Caption = dx.c_str();
				break;
			}
		}
	}
}


void __fastcall TFrameFolderHistory::sbShowManualClick(TObject *Sender)
{
	HelpHandler::OpenSearchManual();
}


void __fastcall TFrameFolderHistory::sbSearchSyntaxClick(TObject *Sender)
{
//
}


int TFrameFolderHistory::FindFolderHistoryItem(const std::wstring item)
{
	for (int t = 0; t < clbFolderHistory->Items->Count; t++)
	{
		if (clbFolderHistory->Items->Strings[t] == item.c_str())
		{
			return t;
		}
	}

	return -1;
}


void TFrameFolderHistory::BuildInformationTabs()
{
	if (bSelectDate->Tag != -1)
	{
		std::wstring dt = Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bSelectDate->Tag].c_str());

		// ===========================================================================

		std::wstring path = cbFHAvailablePath->Text.c_str();

		std::transform(path.begin(), path.end(), path.begin(), ::toupper);

		path += dt + cbFHAvailableComputer->Text.c_str();

		if (GXDatabase->TableExists(Utility::GetMD5(path)))
		{
	//      if Assigned(FOnProcessWindowStatus)
//			{
	//        FOnProcessWindowStatus(CWindowAnalysisProgress, 1);
//			}

		 //	to do TPreScan.PurgeAllData(dataFolderHistory, Nil, Nil, Nil); //sgNullFiles, sgSearchResults);

			Screen->Cursor          = crSQLWait;
			llFHPleaseWait->Visible = true;

			if (OnScanFromFolderHistory)
			{
				OnScanFromFolderHistory(cbFHAvailablePath->Text.c_str(),
										Utility::GetMD5(path),
										Convert::YYMMDDHHMMSSToFHString(dt));
			}

			if (OnUpdateHistoryFinished)
			{
				OnUpdateHistoryFinished(0);
			}

			llFHPleaseWait->Visible = False;
		}
		else
		{
			std::wstring date_caption = bSelectDate->Caption.c_str();

			ShowXDialog(GLanguageHandler->Text[kWarning],
						GLanguageHandler->Text[kNoFileData] + L": " +
						date_caption,
						XDialogTypeWarning);
		}
	}
}
#pragma end_region


#pragma region Tab_Search_Compare
void TFrameFolderHistory::InitCompare()
{
	sgCompareLeft->RowCount = 2;
	sgCompareRight->RowCount = 2;

	sgCompareLeft->Cells[0][0]  = GLanguageHandler->Text[kFileName].c_str();
	sgCompareLeft->Cells[1][0]  = GLanguageHandler->Text[kSize].c_str();
	sgCompareLeft->Cells[2][0]  = GLanguageHandler->Text[kSizeOD].c_str();
	sgCompareLeft->Cells[3][0]  = GLanguageHandler->Text[kCreated].c_str();
	sgCompareLeft->Cells[4][0]  = GLanguageHandler->Text[kAccessed].c_str();
	sgCompareLeft->Cells[5][0]  = GLanguageHandler->Text[kModified].c_str();
	sgCompareLeft->Cells[6][0]  = GLanguageHandler->Text[kOwner].c_str();
	sgCompareLeft->Cells[7][0]  = GLanguageHandler->Text[kStatus].c_str();

	sgCompareRight->Cells[0][0]  = GLanguageHandler->Text[kFileName].c_str();
	sgCompareRight->Cells[1][0]  = GLanguageHandler->Text[kSize].c_str();
	sgCompareRight->Cells[2][0]  = GLanguageHandler->Text[kSizeOD].c_str();
	sgCompareRight->Cells[3][0]  = GLanguageHandler->Text[kCreated].c_str();
	sgCompareRight->Cells[4][0]  = GLanguageHandler->Text[kAccessed].c_str();
	sgCompareRight->Cells[5][0]  = GLanguageHandler->Text[kModified].c_str();
	sgCompareRight->Cells[6][0]  = GLanguageHandler->Text[kOwner].c_str();
	sgCompareRight->Cells[7][0]  = GLanguageHandler->Text[kStatus].c_str();

	int total = 0;

	for (int t = 1; t < 14; t++)
	{
		sgCompareLeft->ColWidths[t] = CompareWidths[t];
		sgCompareRight->ColWidths[t] = CompareWidths[t];

		total += CompareWidths[t];
	}

	sgCompareLeft->ColWidths[0] = sgCompareLeft->Width - (total + __WidthOfScrollbar);
	sgCompareRight->ColWidths[0] = sgCompareRight->Width - (total + __WidthOfScrollbar);
}


void __fastcall TFrameFolderHistory::sbCompareFavouritesClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	puFHQuickSearch->Tag = sb->Tag;

	TPoint mouse_pos = Mouse->CursorPos;

	puFHQuickSearch->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameFolderHistory::sbGoSearchClick(TObject *Sender)
{
	if (bCompareLeftDate->Tag != -1 && bCompareRightDate->Tag != -1)
	{
		if (eCompareSearch->Text != L"")
		{
			CompareBuildLeft();
			CompareBuildRight();

			if (eCompareSearch->Items->IndexOf(eCompareSearch->Text) == -1)
			{
				if (eCompareSearch->Text != L"")
				{
					eCompareSearch->Items->Insert(0, eCompareSearch->Text);
				}
			}
		}
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kWarning],
					GLanguageHandler->Text[kPleaseSelectADate],
					XDialogTypeWarning);
	}
}


void __fastcall TFrameFolderHistory::eCompareSearchChange(TObject *Sender)
{
	lCLPagePrevious->Tag = 0;
	lCRPagePrevious->Tag = 0;

	lCLPagePrevious->Enabled = false;
	lCLPageNext->Enabled     = false;
	lCLPageNumber->Caption   = L"1";
	lCLShowing->Caption      = L"n/a";

	lCRPagePrevious->Enabled = false;
	lCRPageNext->Enabled     = false;
	lCRPageNumber->Caption   = L"1";
	lCRShowing->Caption      = L"n/a";
}


void __fastcall TFrameFolderHistory::eCompareSearchKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN)
	{
		sbGoSearchClick(sbGoSearch);
	}
}


void __fastcall TFrameFolderHistory::bCompareLeftDateClick(TObject *Sender)
{
	puFHSelectDate->Tag = 2;

	TPoint mouse_pos = Mouse->CursorPos;

	puFHSelectDate->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameFolderHistory::bCompareRightDateClick(TObject *Sender)
{
	puFHSelectDate->Tag = 3;

	TPoint mouse_pos = Mouse->CursorPos;

	puFHSelectDate->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameFolderHistory::cbCompareColourCodeClick(TObject *Sender)
{
	if (sgCompareLeft->Cells[0][1] != L"")
	{
		sgCompareLeft->Refresh();
	}

	if (sgCompareRight->Cells[0][1] != L"")
	{
		sgCompareRight->Refresh();
	}
}


void __fastcall TFrameFolderHistory::sbCompareLeftSaveClick(TObject *Sender)
{
	GridUtility::SaveFolderHistoryData(sgCompareLeft, eCompareSearch->Text.c_str(), kFHModeSaveAll);
}


void __fastcall TFrameFolderHistory::sbCompareRightSaveClick(TObject *Sender)
{
	GridUtility::SaveFolderHistoryData(sgCompareRight, eCompareSearch->Text.c_str(), kFHModeSaveAll);
}


void __fastcall TFrameFolderHistory::sbFHCLHideCreatedClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	int column = sb->Tag * 2 + 1;

	GridUtility::ToggleColumn(sgCompareLeft, sb,
							  column,
							  CompareWidths[column],
							  TableColumnLookup[sb->Tag * 2]);

	Splitter1Moved(NULL);
}


void __fastcall TFrameFolderHistory::sbFHCRHideCreatedClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	int column = sb->Tag * 2 + 1;

	GridUtility::ToggleColumn(sgCompareRight, sb,
							  column,
							  CompareWidths[column],
							  TableColumnLookup[sb->Tag * 2]);

	Splitter1Moved(NULL);
}


void __fastcall TFrameFolderHistory::sbCompareLeftShowClick(TObject *Sender)
{
	if (sbCompareLeftShow->Tag == 0)
	{
		GImageHandler->SetButtonOffImage(sbCompareLeftShow, kImageShow);
		Screen->Cursor = crHourGlass;

		sbCompareLeftShow->Tag = 1;
		cbCompareColourCode->Checked = false;
		int i = 0;

		QuickCompareB.clear();

		for (int t = 1; t < sgCompareRight->RowCount; t++)
		{
			QuickCompareB.push_back(sgCompareRight->Cells[0][t].c_str());
		}

	// to do std::sort(		FQuickCompareB.Sort;

		// =====================================================================

		for (int t = 1; t < sgCompareLeft->RowCount; t++)
		{
			if (std::find(QuickCompareB.begin(), QuickCompareB.end(), sgCompareLeft->Cells[0][t].c_str()) != QuickCompareB.end())
			{
				sgCompareLeft->Cells[kFHColumnCategory][t] = L"1";
			}
			else
			{
				sgCompareLeft->Cells[kFHColumnCategory][t] = L"2";

				i++;
			}
		}

		lCompareLeftResults->Caption = (GLanguageHandler->Text[kFound] + L" " + std::to_wstring(i) + L" " + GLanguageHandler->Text[kFiles] + L".").c_str();
		Screen->Cursor = crDefault;
	}
	else
	{
		sbCompareLeftShow->Tag = 0;
		GImageHandler->SetButtonOffImage(sbCompareLeftShow, kImageShow);
	}

	sgCompareLeft->Refresh();
}


void __fastcall TFrameFolderHistory::sbCompareRightShowClick(TObject *Sender)
{
	if (sbCompareRightShow->Tag == 0)
	{
		GImageHandler->SetButtonOffImage(sbCompareRightShow, 8);

		Screen->Cursor = crHourGlass;

		sbCompareRightShow->Tag        = 1;
		cbCompareColourCode->Checked = false;
		int i = 0;

		QuickCompareA.clear();

		for (int t = 1; t < sgCompareLeft->RowCount; t++)
		{
			QuickCompareA.push_back(sgCompareLeft->Cells[0][t].c_str());
		}

//		std::sort(to do QuickCompareA.Sort;

		// =====================================================================

		for (int t = 1; t < sgCompareRight->RowCount; t++)
		{
			if (std::find(QuickCompareA.begin(), QuickCompareA.end(), sgCompareRight->Cells[0][t].c_str()) != QuickCompareA.end())
			{
				sgCompareRight->Cells[kFHColumnCategory][t] = L"1";
			}
			else
			{
				sgCompareRight->Cells[kFHColumnCategory][t] = L"2";

				i++;
			}
		}

		lCompareRightResults->Caption = (GLanguageHandler->Text[kFound] + L" " + std::to_wstring(i) + L" " + GLanguageHandler->Text[kFiles] + L".").c_str();

		Screen->Cursor = crDefault;
	}
	else
	{
		GImageHandler->SetButtonOffImage(sbCompareRightShow, 8);
		sbCompareRightShow->Tag = 0;
	}

	sgCompareRight->Refresh();
}


void TFrameFolderHistory::CompareBuildLeft()
{
	std::wstring search_text = eCompareSearch->Text.c_str();
	std::wstring sql = L"";

	if (search_text.find(L"SELECT ") != std::wstring::npos)
	{
		if (GSettingsHandler->History.SQLinSearch)
		{
			sql = Utility::ReplaceString(search_text,
										 L"*",
										 L" FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ");

			sql = Utility::ReplaceString(sql,
										 L"$x$",
										 L"\"" + Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareLeftDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str()) + L"\"");
		}
		else
		{
			sql = L"";

			ShowXDialog(GLanguageHandler->Text[kWarning],
						GLanguageHandler->Text[kDialog10],
						XDialogTypeWarning);
		}
	}
	else
	{
		sql = SqlUtility::XinorbisSearchToSQL(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareLeftDate->Tag].c_str()),
											  cbFHAvailablePath->Text.c_str(),
											  cbFHAvailableComputer->Text.c_str(),
											  eCompareSearch->Text.c_str(),
											  lCLPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults,
											  GSettingsHandler->General.MaxSearchResults,
											  false);
	}

	if (GXDatabase->TableExists(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareLeftDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str())))
	{
		if (sql != L"")
		{
			sbCompareLeftShow->Tag = 0;
			GImageHandler->SetButtonOffImage(sbCompareLeftShow, 8);
			Screen->Cursor = crSQLWait;

			LastSql[0] = sql;

			CLS->SetData(sql, cbCompareUnits->ItemIndex, cbCompareShowFullPath->Checked, sgCompareLeft);

			CLS->Execute();

			PostCompareLeft();
		}
	}
	else
	{
		std::wstring compare_date = bCompareLeftDate->Caption.c_str();

		ShowXDialog(GLanguageHandler->Text[kWarning],
					GLanguageHandler->Text[kNoFileData] + L": " + compare_date,
					XDialogTypeWarning);
	}
}


void TFrameFolderHistory::CompareBuildRight()
{
	std::wstring search_text = eCompareSearch->Text.c_str();
	std::wstring sql = L"";

	if (search_text.find(L"SELECT ") != std::wstring::npos)
	{
		if (GSettingsHandler->History.SQLinSearch)
		{
			sql = Utility::ReplaceString(search_text,
										 L"*",
										 L" FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ");

			sql = Utility::ReplaceString(sql,
										 L"$x$",
										 L"\"" + Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareRightDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str()) + L"\"");
		}
		else
		{
			sql = L"";

			ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kDialog10], XDialogTypeWarning);
		}
	}
	else
	{
		sql = SqlUtility::XinorbisSearchToSQL(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareRightDate->Tag].c_str()),
											  cbFHAvailablePath->Text.c_str(),
											  cbFHAvailableComputer->Text.c_str(),
											  eCompareSearch->Text.c_str(),
											  lCRPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults,
											  GSettingsHandler->General.MaxSearchResults,
											  false);
	}

	if (GXDatabase->TableExists(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareRightDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str())))
	{
		if (!sql.empty())
		{
			sbCompareRightShow->Tag = 0;
			GImageHandler->SetButtonOffImage(sbCompareRightShow, 8);
			Screen->Cursor = crSQLWait;

			LastSql[1] = sql;

			CRS->SetData(sql, cbCompareUnits->ItemIndex, cbCompareShowFullPath->Checked, sgCompareRight);

			CRS->Execute();

			PostCompareRight();
		}
	}
	else
	{
		std::wstring compare_date = bCompareRightDate->Caption.c_str();

		ShowXDialog(GLanguageHandler->Text[kWarning],
					GLanguageHandler->Text[kNoFileData] + L": " + compare_date,
					XDialogTypeWarning);
	}
}


void TFrameFolderHistory::PostCompareLeft()
{
	if (sgCompareLeft->Cells[0][1] != L"")
	{
		if (CLS->Data.Files == 0)
		{
			lCompareLeftResults->Caption = (GLanguageHandler->Text[kFound] + L" " + std::to_wstring(CLS->Data.Folders) + L" " + GLanguageHandler->Text[kFolders] + L".").c_str();
		}
		else if (CLS->Data.Folders == 0)
		{
			lCompareLeftResults->Caption = (GLanguageHandler->Text[kFound] + L" " + std::to_wstring(CLS->Data.Files) + L" " + GLanguageHandler->Text[kFiles] + L" (" + Convert::ConvertToUsefulUnit(CLS->Data.Size) + L".").c_str();
		}
		else
		{
			lCompareLeftResults->Caption = (GLanguageHandler->Text[kFound] + L" " + std::to_wstring(CLS->Data.Files) + L" " + GLanguageHandler->Text[kFiles] + L" (" + Convert::ConvertToUsefulUnit(CLS->Data.Size) + L") + " + std::to_wstring(CLS->Data.Folders) + L" " + GLanguageHandler->Text[kFolders] + L".").c_str();
		}
	}
	else
	{
		lCompareLeftResults->Caption = GLanguageHandler->Text[kNoFilesFound].c_str();
	}

	// == navigation logic ===================================================

	lCLPageNumber->Caption = lCLPagePrevious->Tag + 1;
	lCLShowing->Caption    = (std::to_wstring(lCLPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults + 1) + L"..." +
							  std::to_wstring((lCLPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults) + GSettingsHandler->General.MaxSearchResults)).c_str();

	if (lCLPagePrevious->Tag == 0)
	{
		lCLPagePrevious->Enabled = false;
	}
	else
	{
		lCLPagePrevious->Enabled = true;
	}

	if (CLS->Data.Files + CLS->Data.Folders < GSettingsHandler->General.MaxSearchResults)
	{
		if (lCLPagePrevious->Tag == 0)
		{
			lCLPagePrevious->Enabled = false;
		}
		else
		{
			lCLPagePrevious->Enabled = true;
		}

		lCLPageNext->Enabled = false;
	}
	else
	{
		lCLPagePrevious->Enabled = true;
		lCLPageNext->Enabled     = false;
	}

	// =======================================================================

	sgCompareLeft->EndUpdate();

	// TGridUtility.SortTable(sgFHCompareLeft, sgFHCompareLeft.SortSettings.Column);

	Screen->Cursor = crDefault;
}


void TFrameFolderHistory::PostCompareRight()
{
	if (sgCompareRight->Cells[0][1] != L"")
	{
		if (CRS->Data.Files == 0)
		{
			lCompareRightResults->Caption = (GLanguageHandler->Text[kFound] +
											 L" " + std::to_wstring(CRS->Data.Folders) + L" " +
											 GLanguageHandler->Text[kFolders] + L".").c_str();
		}
		else if (CRS->Data.Folders == 0)
		{
			lCompareRightResults->Caption = (GLanguageHandler->Text[kFound] +
										L" " + std::to_wstring(CRS->Data.Files) + L" " +
										GLanguageHandler->Text[kFiles] +
										L" " + Convert::ConvertToUsefulUnit(CRS->Data.Size) + L").").c_str();
		}
		else
		{
			lCompareRightResults->Caption = (GLanguageHandler->Text[kFound] +
											 L" " + std::to_wstring(CRS->Data.Files) + L" " +
											 GLanguageHandler->Text[kFiles] +
											 L" (" + Convert::ConvertToUsefulUnit(CRS->Data.Size) + L") + " +
											 std::to_wstring(CRS->Data.Folders) + L" " + GLanguageHandler->Text[kFolders] + L".").c_str();
		}
	}
	else
	{
		lCompareRightResults->Caption = GLanguageHandler->Text[kNoFilesFound].c_str();
	}

	// == navigation logic =====================================================

	lCRPageNumber->Caption = lCRPagePrevious->Tag + 1;
	lCRShowing->Caption    = (std::to_wstring(lCRPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults + 1) + L"..." +
	                          std::to_wstring((lCRPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults) + GSettingsHandler->General.MaxSearchResults)).c_str();

	if (lCRPagePrevious->Tag == 0)
	{
		lCRPagePrevious->Enabled = false;
	}
	else
	{
		lCRPagePrevious->Enabled = true;
	}

	if (CRS->Data.Files + CRS->Data.Folders < GSettingsHandler->General.MaxSearchResults)
	{
		if (lCRPagePrevious->Tag == 0)
		{
			 lCRPagePrevious->Enabled = false;
		}
		else
		{
			lCRPagePrevious->Enabled = true;
		}

		lCRPageNext->Enabled = false;
	}
	else
	{
		lCRPagePrevious->Enabled = true;
		lCRPageNext->Enabled     = false;
	}

	// =======================================================================

	sgCompareRight->EndUpdate();

///	TGridUtility.SortTable(sgFHCompareRight, sgFHCompareLeft.SortSettings.Column);

	Screen->Cursor = crDefault;
}


void __fastcall TFrameFolderHistory::Splitter1Moved(TObject *Sender)
{
	int total = 0;

	for (int t = 1; t < 14; t++)
	{
		sgCompareLeft->ColWidths[t] = CompareWidths[t];
		sgCompareRight->ColWidths[t] = CompareWidths[t];

		total += CompareWidths[t];
	}

	sgCompareLeft->ColWidths[0] = sgCompareLeft->Width - (total + __WidthOfScrollbar);
	sgCompareRight->ColWidths[0] = sgCompareRight->Width - (total + __WidthOfScrollbar);
}


void __fastcall TFrameFolderHistory::sgCompareLeftDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*  l,w : integer;

 {
  if (cbFHCompareColour.Checked) then {
	if ARow != 0 then {

	  TAdvStringGrid(Sender)->Canvas->Brush->Color = GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender)->Cells[FHschCategory, ARow])];
	  TAdvStringGrid(Sender)->Canvas->TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender)->Cells[ACol, ARow]);
	};
  }
  else if (sbCompareLeftShow->Tag = 1) then {
	if ARow != 0 then {
	  TAdvStringGrid(Sender)->Canvas->Brush->Color = CompareColoursX[StrToInt(TAdvStringGrid(Sender)->Cells[FHschCategory, ARow])];
	  TAdvStringGrid(Sender)->Canvas->TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender)->Cells[ACol, ARow]);
	};
  };

  if ACol > 0 then {
	switch ACol of
	  1,2 : {
			  w = TAdvStringGrid(Sender)->Canvas->TextWidth(TAdvStringGrid(Sender)->Cells[ACol, ARow]);
			  l = TAdvStringGrid(Sender)->ColWidths[ACol] - w;

			  TAdvStringGrid(Sender)->Canvas->TextRect(Rect, Rect.Left + l - 2, Rect.Top + 2, TAdvStringGrid(Sender)->Cells[ACol, ARow]);
			};
	};
  };
};*/
}


void __fastcall TFrameFolderHistory::sgCompareRightDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*  if (cbCompareColourCode->Checked)
	{
		if ARow != 0
		{
			TAdvStringGrid(Sender)->Canvas->Brush->Color = GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender)->Cells[FHschCategory, ARow])];
			  TAdvStringGrid(Sender)->Canvas->TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender)->Cells[ACol, ARow]);
		}
	}
	else if (sbFHCShowRight->Tag = 1)
	{
		if ARow != 0)
		{
			TAdvStringGrid(Sender)->Canvas->Brush->Color = CompareColoursX[StrToInt(TAdvStringGrid(Sender)->Cells[FHschCategory, ARow])];
			TAdvStringGrid(Sender)->Canvas->TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender)->Cells[ACol, ARow]);
		}
	}*/
}
#pragma end_region


#pragma region Tab_Search_CompareFolder
void TFrameFolderHistory::InitCompareFolder()
{
}


void __fastcall TFrameFolderHistory::eCompareFolderSearchKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift)
{
	if (Key == VK_RETURN)
	{
		sbCompareFolderSearchClick(NULL);
	}
}


void __fastcall TFrameFolderHistory::sbCompareFolderSearchClick(TObject *Sender)
{
	if (bCompareFolderLeftDate->Tag != -1 && bCompareFolderRightDate->Tag != -1)
	{
		if (eCompareFolderSearch->Text != L"")
		{
			CompareFolderBuildLeft();
			CompareFolderBuildRight();
		}
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kPleaseSelectADate], XDialogTypeWarning);
	}
}


void __fastcall TFrameFolderHistory::bCompareFolderLeftDateClick(TObject *Sender)
{
	puFHSelectDate->Tag = 5;

	TPoint mouse_pos = Mouse->CursorPos;

	puFHSelectDate->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameFolderHistory::bCompareFolderRightDateClick(TObject *Sender)
{
	puFHSelectDate->Tag = 6;

	TPoint mouse_pos = Mouse->CursorPos;

	puFHSelectDate->Popup(mouse_pos.X, mouse_pos.Y);
}


void TFrameFolderHistory::CompareFolderBuildLeft()
{
	std::wstring search_text = eCompareFolderSearch->Text.c_str();
	std::wstring sql = L"";

	if (search_text.find(L"SELECT ") != std::wstring::npos)
	{
		if (GSettingsHandler->History.SQLinSearch)
		{
			sql = Utility::ReplaceString(search_text,
										 L"*",
										 L" FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ");

			sql = Utility::ReplaceString(sql,
										 L"$x$",
										 L"\"" + Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareFolderLeftDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str()) + L"\"");
		}
		else
		{
			sql = L"";
			ShowXDialog(GLanguageHandler->Text[kWarning],
			GLanguageHandler->Text[kDialog10],
			XDialogTypeWarning);
		}
	}
	else
	{
		sql = SqlUtility::XinorbisSearchAllToSQL(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareFolderLeftDate->Tag].c_str()),
												 cbFHAvailablePath->Text.c_str(),
												 cbFHAvailableComputer->Text.c_str(),
												 false);
	}

	if (GXDatabase->TableExists(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareFolderLeftDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str())))
	{
		if (sql != L"")
		{
			LastSql[0] = sql;

			CFLS->SetData(sql,
						  search_text,
						  lCompareFolderLeftResults,
						  sgCompareFolderLeft);

			CFLS->Execute();

			CompareFolderBuildLeft();
		}
	}
	else
	{
		std::wstring compare_date = bCompareFolderLeftDate->Caption.c_str();

		ShowXDialog(GLanguageHandler->Text[kWarning],
					GLanguageHandler->Text[kNoFileData] + L": " + compare_date,
					XDialogTypeWarning);
	}
}


void TFrameFolderHistory::CompareFolderBuildRight()
{
	std::wstring search_text = eCompareFolderSearch->Text.c_str();
	std::wstring sql = L"";

	if (search_text.find(L"SELECT ") != std::wstring::npos)
	{
		if (GSettingsHandler->History.SQLinSearch)
		{
			sql = Utility::ReplaceString(search_text,
										 L"*",
										 L" FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ");

			sql = Utility::ReplaceString(sql,
										 L"$x$",
										 L"\"" + Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareFolderRightDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str()) + L"\"");
		}
		else
		{
			sql = L"";

			ShowXDialog(GLanguageHandler->Text[kWarning],
						GLanguageHandler->Text[kDialog10],
						XDialogTypeWarning);
		}
	}
	else
	{
		sql = SqlUtility::XinorbisSearchAllToSQL(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareFolderRightDate->Tag].c_str()),
												 cbFHAvailablePath->Text.c_str(),
												 cbFHAvailableComputer->Text.c_str(),
												 false);
	}

	if (GXDatabase->TableExists(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareFolderRightDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str())))
	{
		if (sql != L"")
		{
			LastSql[0] = sql;

			CFRS->SetData(sql, search_text, lCompareFolderRightResults, sgCompareFolderRight);

			CFRS->Execute();

			CompareFolderBuildRight();
		}
	}
	else
	{
		std::wstring compare_date = bCompareFolderRightDate->Caption.c_str();

		ShowXDialog(GLanguageHandler->Text[kWarning],
					GLanguageHandler->Text[kNoFileData] + L": " + compare_date,
					XDialogTypeWarning);
    }
}


void __fastcall TFrameFolderHistory::sbCompareFolderLeftSaveClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kFileHistoryCompare] + L"_" + GLanguageHandler->Text[kLeft]));

	if (!file_name.empty())
	{
		TSpeedButton *sb = (TSpeedButton*)Sender;

		switch (sb->Tag)
		{
		case kOptionLeft:
			GridUtility::Save(sgCompareFolderLeft, file_name);
			break;
		case kOptionRight:
			GridUtility::Save(sgCompareFolderRight, file_name);
			break;
		}
	}
}


void __fastcall TFrameFolderHistory::Splitter2Moved(TObject *Sender)
{
	int total = 0;

	for (int t = 1; t < 14; t++)
	{
		sgCompareFolderLeft->ColWidths[t] = CompareWidths[t];
		sgCompareFolderRight->ColWidths[t] = CompareWidths[t];

		if (CompareWidths[t] != -1)
		{
			total += CompareWidths[t];
        }
	}

	sgCompareFolderLeft->ColWidths[0] = sgCompareFolderLeft->Width - (total + __WidthOfScrollbar);
	sgCompareFolderRight->ColWidths[0] = sgCompareFolderRight->Width - (total + __WidthOfScrollbar);
}


void __fastcall TFrameFolderHistory::sgCompareFolderLeftDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*  if ARow != 0 then {
    switch ACol of
      CFieldEmpty           : {
								Rect.Left   = Rect.Left;
								Rect.Top    = Rect.Top;
								Rect.Right  = Rect.Right;
                                Rect.Bottom = Rect.Bottom;

								if TAdvStringGrid(Sender)->Cells[7, Arow] != L"" then {
                                  TAdvStringGrid(Sender)->Canvas->Brush->Color = GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender)->Cells[7, Arow])];
                                  TAdvStringGrid(Sender)->Canvas.Rectangle(Rect);
								};
                              };
	  CFieldCategoryCountPC : {
                                TAdvStringGrid(Sender)->Canvas->Brush->Color = GSettingsHandler->Navigation.BarColours[5];
                                TAdvStringGrid(Sender)->Canvas.Rectangle(Rect);

                                if TAdvStringGrid(Sender)->Cells[9, ARow] != "0" then {
								  zRect.Top    = Rect.Top + 1;
								  zRect.Bottom = Rect.Bottom - 1;
								  zRect.Left   = Rect.Left + 1;
								  zRect.Right  = Rect.Left + StrToInt(TAdvStringGrid(Sender)->Cells[9, ARow]);

								  TAdvStringGrid(Sender)->Canvas->Brush->Color = GSettingsHandler->Navigation.BarColours[6];
								  TAdvStringGrid(Sender)->Canvas.FillRect(zRect);
								};

								TAdvStringGrid(Sender)->Canvas->Brush->Style = bsClear;
								TAdvStringGrid(Sender)->Canvas.Font.Color  = clBlack;
								TAdvStringGrid(Sender)->Canvas->TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender)->Cells[3, ARow]);
							  };
	  CFieldCategorySizePC  : {
                                TAdvStringGrid(Sender)->Canvas->Brush->Color = GSettingsHandler->Navigation.BarColours[5];
								TAdvStringGrid(Sender)->Canvas.Rectangle(Rect);

								if TAdvStringGrid(Sender)->Cells[10, ARow] != "0" then {
								  zRect.Top    = Rect.Top + 1;
								  zRect.Bottom = Rect.Bottom - 1;
								  zRect.Left   = Rect.Left + 1;
								  zRect.Right  = Rect.Left + StrToInt(TAdvStringGrid(Sender)->Cells[10, ARow]);

								  TAdvStringGrid(Sender)->Canvas->Brush->Color = GSettingsHandler->Navigation.BarColours[6];
								  TAdvStringGrid(Sender)->Canvas.FillRect(zRect);
								};

								TAdvStringGrid(Sender)->Canvas->Brush->Style = bsClear;
								TAdvStringGrid(Sender)->Canvas.Font.Color  = clBlack;
								TAdvStringGrid(Sender)->Canvas->TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender)->Cells[6, ARow]);
							  };
	};
  };*/
}

#pragma end_region


#pragma region Tab_Search_CompareFolderTree
void __fastcall TFrameFolderHistory::sbCompareTreeClick(TObject *Sender)
{
	if (bCompareTreeLeftDate->Tag != -1)
	{
		GXDatabase->InitialiseTreeWithFolders(tvCompareLeft,
			Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareTreeLeftDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str()));
	}

	if (bCompareTreeRightDate->Tag != -1)
	{
		GXDatabase->InitialiseTreeWithFolders(tvCompareRight,
			Convert::CreateTableName(Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items->Strings[bCompareTreeRightDate->Tag].c_str()), cbFHAvailablePath->Text.c_str(), cbFHAvailableComputer->Text.c_str()));
	}

	sbCompareFolderLeftSave->Enabled  = true;
	sbCompareFolderRightSave->Enabled = true;
}


void __fastcall TFrameFolderHistory::bCompareTreeLeftDateClick(TObject *Sender)
{
	puFHSelectDate->Tag = 7;

	TPoint mouse_pos = Mouse->CursorPos;

	puFHSelectDate->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameFolderHistory::bCompareTreeRightDateClick(TObject *Sender)
{
	puFHSelectDate->Tag = 8;

	TPoint mouse_pos = Mouse->CursorPos;

	puFHSelectDate->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameFolderHistory::SpeedButton28Click(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt",
												  L".txt",
                                                  L"",
												  Utility::GetDefaultFileName(L".txt", GLanguageHandler->Text[kFileHistoryCompare] + L"_" + GLanguageHandler->Text[kLeft]));

	if (!file_name.empty())
	{
		TSpeedButton* sb = (TSpeedButton*)Sender;

		switch (sb->Tag)
		{
		case kOptionLeft:
			tvCompareLeft->SaveToFile(file_name.c_str());
			break;
		case kOptionRight:
			tvCompareRight->SaveToFile(file_name.c_str());
			break;
		}
	}
}

void __fastcall TFrameFolderHistory::tvCompareLeftExpanding(TObject *Sender, TTreeNode *Node,
		  bool &AllowExpansion)
{
/*  if PNodeData(Node.Data)^.FolderID != -2
	{
		GXDatabase->PopulateTreeFolder(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareTreeLeft->Tag]),
									   cbFHAvailablePath->Text,
									   cbFHAvailableComputer->Text),
									   tvFHTLeft, node, L"", PNodeData(Node.Data)^.FolderID);

		PNodeData(Node.Data)^.FolderID = -2;
	}*/
}


void __fastcall TFrameFolderHistory::tvCompareRightExpanding(TObject *Sender, TTreeNode *Node,
		  bool &AllowExpansion)
{
/*  if PNodeData(Node.Data)^.FolderID != -2
	{
		GXDatabase->PopulateTreeFolder(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareTreeRight->Tag]),
									   cbFHAvailablePath->Text,
									   cbFHAvailableComputer->Text),
									   tvFHTLeft, node, L"", PNodeData(Node.Data)^.FolderID);

		PNodeData(Node.Data)^.FolderID = -2;
  	};*/
}
#pragma end_region


#pragma region Popup_Charts
void __fastcall TFrameFolderHistory::miCOSaveClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::ExecuteImages(Utility::GetDefaultFileName(L".png", GLanguageHandler->Text[kChart]));

	if (!file_name.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TChart* chart = (TChart*)pum->PopupComponent;

		ChartUtility::SaveChartToPNG(chart, file_name);
	}
}


void __fastcall TFrameFolderHistory::miCOCopyClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TChart* chart = (TChart*)pum->PopupComponent;

	ChartUtility::CopyChartToClipboard(chart);
}


void __fastcall TFrameFolderHistory::miCOAdvancedClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TChart* chart = (TChart*)pum->PopupComponent;

	ChartOptions co = GSettingsHandler->Chart;

	co.Type = ChartUtility::GetChartType(chart);

	// =========================================================================

	co = ShowChartOptions(co);

	// =========================================================================

	if (co.Result == 1)
	{
		ChartUtility::SetAdvancedOptions(chart, co);

		if (OnChartsHaveChanged)
		{
			OnChartsHaveChanged(0);
		}
    }
}
#pragma end_region


#pragma region Popup_CompareSave
void __fastcall TFrameFolderHistory::puFHCompareSavePopup(TObject *Sender)
{
	auto DoExist = [](TStringGrid *sg) -> int
	{
		int count = 0;

		for (int t = 1; t < sg->RowCount; t++)
		{
			if (sg->Cells[kFHColumnCategory][t] == L"1")
			{
				count++;
			}
		}

		return count;
	};

	auto DontExist = [](TStringGrid *sg) -> int
	{
		int count = 0;

		for (int t = 1; t < sg->RowCount; t++)
		{
			if (sg->Cells[kFHColumnCategory][t] == L"2")
			{
				count++;
			}
		}

		return count;
	};

	bool status = false;

	miFHCSSaveDo->Caption   = GLanguageHandler->Text[kSaveDoExist].c_str();
	miFHCSSaveDont->Caption = GLanguageHandler->Text[kSaveDontExist].c_str();

	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TSpeedButton* sb = (TSpeedButton*)pum->PopupComponent;

	switch (sb->Tag)
	{
	case 1:
		if (sbCompareLeftShow->Tag == 0)
		{
			status = false;
		}
		else
		{
			status = true;

			miFHCSSaveDo->Caption   = (GLanguageHandler->Text[kSaveDoExist] + L" (" + std::to_wstring(DoExist(sgCompareLeft)) + L")").c_str();
			miFHCSSaveDont->Caption = (GLanguageHandler->Text[kSaveDontExist] + L" (" + std::to_wstring(DontExist(sgCompareLeft)) + L")").c_str();
		}

		miFHCSSaveDo->Enabled   = status;
		miFHCSSaveDont->Enabled = status;

		break;
	case 2:
		if (sbCompareRightShow->Tag == 0)
		{
			status = false;
		}
		else
		{
			status = true;

			miFHCSSaveDo->Caption   = (GLanguageHandler->Text[kSaveDoExist] + L" (" + std::to_wstring(DoExist(sgCompareRight)) + L")").c_str();
			miFHCSSaveDont->Caption = (GLanguageHandler->Text[kSaveDontExist] + L" (" + std::to_wstring(DontExist(sgCompareRight)) + L")").c_str();
		}

		miFHCSSaveDo->Enabled     = status;
		miFHCSSaveDont->Enabled   = status;
		break;
	}
}


void __fastcall TFrameFolderHistory::miFHCSSaveAllClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TSpeedButton* sb = (TSpeedButton*)pum->PopupComponent;

	switch (sb->Tag)
	{
	case 1:
		GridUtility::SaveFolderHistoryData(sgCompareLeft,  eCompareSearch->Text.c_str(), mi->Tag);
		break;
	case 2:
		GridUtility::SaveFolderHistoryData(sgCompareRight, eCompareSearch->Text.c_str(), mi->Tag);
		break;
	}
}


void __fastcall TFrameFolderHistory::miFHCSSaveDoClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TSpeedButton* sb = (TSpeedButton*)pum->PopupComponent;

	switch (sb->Tag)
	{
	case 1:
		GridUtility::SaveFolderHistoryData(sgCompareLeft,  eCompareSearch->Text.c_str(), mi->Tag);
		break;
	case 2:
		GridUtility::SaveFolderHistoryData(sgCompareRight, eCompareSearch->Text.c_str(), mi->Tag);
		break;
	}
}


void __fastcall TFrameFolderHistory::miFHCSSaveDontClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TSpeedButton* sb = (TSpeedButton*)pum->PopupComponent;

	switch (sb->Tag)
	{
	case 1:
		GridUtility::SaveFolderHistoryData(sgCompareLeft,  eCompareSearch->Text.c_str(), mi->Tag);
		break;
	case 2:
		GridUtility::SaveFolderHistoryData(sgCompareRight, eCompareSearch->Text.c_str(), mi->Tag);
		break;
	}
}
#pragma end_region


#pragma region Popup_GenericTable
void __fastcall TFrameFolderHistory::puGenericTablePopup(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	bool status = true;

	if (grid->Cells[0][1] == L"" && grid->Cells[1][1] == L"")
	{
		status = false;
	}

	miGenericExport->Enabled        = status;
	miGenericClipboard->Enabled     = status;
	miGenericClipboardHTML->Enabled = status;
}


void __fastcall TFrameFolderHistory::miGenericExportClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(L".csv",
														 GLanguageHandler->Text[kSearch] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		GridUtility::Save(grid, file_name);
	}
}


void __fastcall TFrameFolderHistory::miGenericClipboardClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	GridUtility::CopyToClipboard(grid, 0);
}


void __fastcall TFrameFolderHistory::miGenericClipboardHTMLClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	GridUtility::CopyToClipboardAsHTML(grid, 0);
}
#pragma end_region


#pragma region Popup_QuickSearch
/*procedure TFrameFolderHistory.miQuickSearchClick(Sender: TObject);
 var
  ss : string;
  ix : integer;

 {
  ss = L"";
  ix = -1;

  if Pos("{", MenuStrings[TMenuItem(Sender)->Tag]) != 0 then
	ss = ParseMenuSearchCommand(MenuStrings[TMenuItem(Sender)->Tag])
  else if MenuStrings[TMenuItem(Sender)->Tag][1] = "$" then
	ix = ParseMenuSearchCommandII(MenuStrings[TMenuItem(Sender)->Tag])
  else
	ss = MenuStrings[TMenuItem(Sender)->Tag];

  if ix != -1 then {
	switch ix of
	  1 : if Assigned(FOpenSearchWizard) then
			FOpenSearchWizard(0);
		  };
  }
  else {
	if ss = "SetLastSQL" then {
	  //
	}
	else {
	  if ss != L"" then {
		switch Tpopupmenu(TMenuItem(Sender).GetParentMenu)->Tag of
		  3 : {
				eFHCompareSearch->Text = ss;
				eFHCompareSearchChange(Nil);

				sbGoSearch(sbGoSearch);
			  };
		  4 : {
				eFHCompareDriveFolder->Text = ss;
			  };
		};
	  };
	};
  };
}     */
#pragma end_region


#pragma region Popup_SelectDate
void __fastcall TFrameFolderHistory::miSelectDateTimeClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();

	switch (pum->Tag)
	{
	case 1:
	{
		int old_id = bSelectDate->Tag;

		bSelectDate->Tag     = mi->Tag;
		bSelectDate->Caption = clbFolderHistory->Items->Strings[bSelectDate->Tag];

		if (bSelectDate->Tag != old_id)
		{
			BuildInformationTabs();
		}
		break;
	}
	case 2:
		bCompareLeftDate->Tag     = mi->Tag;
		bCompareLeftDate->Caption = clbFolderHistory->Items->Strings[bCompareLeftDate->Tag];
		break;
	case 3:
		bCompareRightDate->Tag     = mi->Tag;
		bCompareRightDate->Caption = clbFolderHistory->Items->Strings[bCompareRightDate->Tag];
		break;
	case 4:
		break;
	case 5:
		bCompareFolderLeftDate->Tag     = mi->Tag;
		bCompareFolderLeftDate->Caption = clbFolderHistory->Items->Strings[bCompareFolderLeftDate->Tag];
		break;
	case 6:
		bCompareFolderRightDate->Tag     = mi->Tag;
		bCompareFolderRightDate->Caption = clbFolderHistory->Items->Strings[bCompareFolderRightDate->Tag];
		break;
	case 7:
		bCompareTreeLeftDate->Tag     = mi->Tag;
		bCompareTreeLeftDate->Caption = clbFolderHistory->Items->Strings[bCompareTreeLeftDate->Tag];
		break;
	case 8:
		bCompareTreeRightDate->Tag     = mi->Tag;
		bCompareTreeRightDate->Caption = clbFolderHistory->Items->Strings[bCompareTreeRightDate->Tag];
		break;
	}
}
#pragma end_region
