//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameFolderHistory.h"

#include "ChartUtility.h"
#include "GridUtility.h"
#include "LanguageHandler.h"
#include "SaveDialogs.h"
#include "SettingsHandler.h"
#include "Utility.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;

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
	//sgFHCompareLeft->DefaultRowHeight  = GSettingsHandler->Appearance.RowHeight;
//	sgFHCompareRight->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
//	sgFHTable->DefaultRowHeight        = GSettingsHandler->Appearance.RowHeight;

  /*	sbFHCLHideCreated->Hint    = GLanguageHandler->Text[kHint1];
	sbFHCRHideAccessed->Hint   = GLanguageHandler->Text[kHint1];
	sbFHCLHideAccessed->Hint   = GLanguageHandler->Text[kHint2];
	sbFHCRHideAccessed->Hint   = GLanguageHandler->Text[kHint2];
	sbFHCLHideModified->Hint   = GLanguageHandler->Text[kHint3];
	sbFHCRHideModified->Hint   = GLanguageHandler->Text[kHint3];
	sbFHCLHideOwner->Hint      = GLanguageHandler->Text[kHint4];
	sbFHCRHideOwner->Hint      = GLanguageHandler->Text[kHint4];
	sbFHCLHideAttributes->Hint = GLanguageHandler->Text[kHint5];
	sbFHCRHideAttributes->Hint = GLanguageHandler->Text[kHint5];
	sbFHCLHideSOD->Hint        = GLanguageHandler->Text[kHint6];
	sbFHCRHideSOD->Hint        = GLanguageHandler->Text[kHint6];
	sbFHCShowLeft->Hint        = GLanguageHandler->Text[kHint8];
	sbFHCShowRight->Hint       = GLanguageHandler->Text[kHint8];


  t, lWidth : integer;
  lFA : array[0..2] of string;

{
  lFA[0] = GLanguageHandler->Text[kCreated];
  lFA[1] = GLanguageHandler->Text[kAccessed];
  lFA[2] = GLanguageHandler->Text[kModified];

  FCharts[1] = vtcFolderHistory;

  // ===========================================================================

  miFHCSSaveAll->Caption  = GLanguageHandler->Text[kSaveAll];
  miFHCSSaveDo->Caption   = GLanguageHandler->Text[kSaveDoExist];
  miFHCSSaveDont->Caption = GLanguageHandler->Text[kSaveDontExist];

  // ===========================================================================

  miGenericExport->Caption        = GLanguageHandler->Text[kExportContent] + rsEllipsis;
  miGenericClipboard->Caption     = GLanguageHandler->Text[kCopyTableToClipboard];
  miGenericClipboardHTML->Caption = GLanguageHandler->Text[kSaveAs] + " HTML";;

  // ===========================================================================

  miChartOptions->Caption         = GLanguageHandler->Text[kChartOptions];
  miCOSave->Caption               = GLanguageHandler->Text[kSaveChart];
  miCOCopy->Caption               = GLanguageHandler->Text[kCopyChartToClipboard];
  miCOAdvanced->Caption           = GLanguageHandler->Text[kAdvancedOptions];

  // ===========================================================================

  cbFHCompareUnits.Clear;

  cbFHCompareFolderInclude->Caption = GLanguageHandler->Text[kIncludeFullPath];

  tsFHMainStatus->Caption = "Stats" + "        ";
  tsFHMainSearch->Caption = GLanguageHandler->Text[kSearch] + "        ";

  tsFHChart->Caption = GLanguageHandler->Text[kChart] + "        ";
  tsFHTable->Caption = GLanguageHandler->Text[kTable] + "        ";
  lFHCTotalSize->Caption = GLanguageHandler->Text[kTotalSize] + ":";


  rbFHSize->Caption               = GLanguageHandler->Text[kBySize];
  rbFHMagSize->Caption            = GLanguageHandler->Text[kBySize];

  rbFHCount->Caption                = GLanguageHandler->Text[kByQuantity];
  rbFHMagCount->Caption             = GLanguageHandler->Text[kByQuantity];

  lFHCompareSize->Caption = GLanguageHandler->Text[kSize];
  lFHCompareSize->Caption   = GLanguageHandler->Text[kSize];

  cbFHComparePath->Caption  = GLanguageHandler->Text[kShowFullPath];

  lFHFolderCount->Caption  = GLanguageHandler->Text[kFolders] + ":";
  lFHCMagnitude->Caption     = GLanguageHandler->Text[kMagnitude];

  sbFHOpenFolder->Caption= GLanguageHandler->Text[kOpen];

  cbFHCompareColour->Caption       = GLanguageHandler->Text[kColourCode];
  llFHPleaseWait->Caption = GLanguageHandler->Text[kLoadingFileHistoryData] + rsEllipsis;

  rbFJTRToday->Caption= GLanguageHandler->Text[kRelativeToToday];
  rbFJTRPrevious->Caption = GLanguageHandler->Text[kRelativeToPrevious];
  tsFHCompare->Caption = GLanguageHandler->Text[kFileHistoryCompare] + "        ";

  lFHAvailableComputer->Caption  = GLanguageHandler->Text[kFolderHistoryComputer];
  lFHAvailablePath->Caption      = GLanguageHandler->Text[kFolderHistoryFolder];

  lWidth = Max(lFHAvailableComputer->Width, lFHAvailablePath->Width);

  cbFHAvailableComputer.Left    = lFHAvailableComputer.Left + lWidth + 8;
  cbFHAvailableFilter.Left      = lFHAvailablePath.Left + lWidth + 8;
  cbFHAvailablePath.Left        = cbFHAvailableFilter.Left + 58;
  sbFHFolderInfo.Left           = cbFHAvailablePath.Left + cbFHAvailablePath->Width + 8;

  bFHISelect->Caption            = GLanguageHandler->Text[kSelectScanDateTime];
  bFHCompareLeft->Caption        = GLanguageHandler->Text[kSelectScanDateTime];
  bFHCompareRight->Caption       = GLanguageHandler->Text[kSelectScanDateTime];
  bFHCompareFolderLeft->Caption  = GLanguageHandler->Text[kSelectScanDateTime];
  bFHCompareFolderRight->Caption = GLanguageHandler->Text[kSelectScanDateTime];
  bFHCompareTreeLeft->Caption    = GLanguageHandler->Text[kSelectScanDateTime];
  bFHCompareTreeRight->Caption   = GLanguageHandler->Text[kSelectScanDateTime];

  tsFHCompareFolder->Caption  = GLanguageHandler->Text[kCompareFolder] + "        ";
  tsFHCompareFolder2->Caption = GLanguageHandler->Text[kCompareFolderTree] + "        ";

  lFHCFiles->Caption      = GLanguageHandler->Text[kFiles] + ":";
  lFHCCategory->Caption   = GLanguageHandler->Text[kCategory] + ":";
  lFHCFilesCount->Caption = GLanguageHandler->Text[kFiles] + ":";

  cbFHCompareUnits->Items->Add(GLanguageHandler->Text[kMostConvenient]);
  cbFHCompareUnits->Items->Add(GLanguageHandler->Text[kBytes]);
  cbFHCompareUnits->Items->Add(GLanguageHandler->Text[kKilobytes]);
  cbFHCompareUnits->Items->Add(GLanguageHandler->Text[kMegabytes]);

  FQuickCompareA = THashedStringList.Create;
  FQuickCompareB = THashedStringList.Create;

  tsFHTimeLine->Caption = GLanguageHandler->Text[kTimeLine] + "        ";

  tsFHMainSearch.TabVisible = False;

  GXGuiUtil.SetButtonOffImage(sbFHCLHideCreated,    CImageCreated);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideAccessed,   CImageAccessed);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideModified,   CImageModified);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideOwner,      CImageOwner);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideAttributes, CImageAttributes);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideSOD,        CImageSizeOnDisk);

  GXGuiUtil.SetButtonOffImage(sbFHCRHideCreated,    CImageCreated);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideAccessed,   CImageAccessed);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideModified,   CImageModified);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideOwner,      CImageOwner);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideAttributes, CImageAttributes);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideSOD,        CImageSizeOnDisk);

  GXGuiUtil.SetButtonOffImage(sbFHCShowLeft, 8);
  GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);

  InitDisplayDoOnce;

  if GSettingsHandler->FHCompare[1, 1] then sbFHCLHideCreatedClick(sbFHCLHideCreated);
  if GSettingsHandler->FHCompare[1, 2] then sbFHCLHideCreatedClick(sbFHCLHideAccessed);
  if GSettingsHandler->FHCompare[1, 3] then sbFHCLHideCreatedClick(sbFHCLHideModified);
  if GSettingsHandler->FHCompare[1, 4] then sbFHCLHideCreatedClick(sbFHCLHideOwner);
  if GSettingsHandler->FHCompare[1, 5] then sbFHCLHideCreatedClick(sbFHCLHideAttributes);
  if GSettingsHandler->FHCompare[1, 6] then sbFHCLHideCreatedClick(sbFHCLHideSOD);

  if GSettingsHandler->FHCompare[2, 1] then sbFHCRHideCreatedClick(sbFHCRHideCreated);
  if GSettingsHandler->FHCompare[2, 2] then sbFHCRHideCreatedClick(sbFHCRHideAccessed);
  if GSettingsHandler->FHCompare[2, 3] then sbFHCRHideCreatedClick(sbFHCRHideModified);
  if GSettingsHandler->FHCompare[2, 4] then sbFHCRHideCreatedClick(sbFHCRHideOwner);
  if GSettingsHandler->FHCompare[2, 5] then sbFHCRHideCreatedClick(sbFHCRHideAttributes);
  if GSettingsHandler->FHCompare[2, 6] then sbFHCRHideCreatedClick(sbFHCRHideSOD);

  FHCatButtons[0]=sbFHCF1;   FHCatButtons[1]=sbFHCF2;   FHCatButtons[2]=sbFHCF3;   FHCatButtons[3]=sbFHCF4;   FHCatButtons[4]=sbFHCF5;
  FHCatButtons[5]=sbFHCF6;   FHCatButtons[6]=sbFHCF7;   FHCatButtons[7]=sbFHCF8;   FHCatButtons[8]=sbFHCF9;   FHCatButtons[9]=sbFHCF10;
  FHCatButtons[10]=sbFHCF11; FHCatButtons[11]=sbFHCF12; FHCatButtons[12]=sbFHCF13; FHCatButtons[13]=sbFHCF14; FHCatButtons[14]=sbFHCF15;
  FHCatButtons[15]=sbFHCF16; FHCatButtons[16]=sbFHCF17; FHCatButtons[17]=sbFHCF18; FHCatButtons[18]=sbFHCF19; FHCatButtons[19]=sbFHCF20;

  for t = 0 to __FileCategoriesCount do {
    GXGuiUtil.SetFolderHistoryButtonImage(FHCatButtons[t], FHCCImageBase[t]);

    FHCatButtons[t]->Hint = FHCatButtons[t]->Hint + " (" + TypeDescriptionsSmall[t] + ")";
  };

  cbFHCompareUnits->ItemIndex = 0;

  SetTheme;

  InitUpdate;	*/
}


/*
procedure TFrameFolderHistory.InitUpdate;
var
  i : integer;

{
  SetTableRowHeights;

  for i = 1 to __ChartCount do {
	ChartUtility::SetAdvancedOptions(FCharts[i], GSettingsHandler->Charts.Options);
  };
};


procedure TFrameFolderHistory.InitDisplayDoOnce ;
{
  TGridUtility.ConfigureInfoTable(sgFHCDLeft);
  TGridUtility.ConfigureInfoTable(sgFHCDRight);

  LoadSettings;
}*/
#pragma }_region


#pragma region Application_Control
void TFrameFolderHistory::ResetDisplay(bool aDisableBuildInformationTabs, bool aMode)
{
/*  TGridUtility.ConfigureInfoTable(sgFHCDLeft);
  TGridUtility.ConfigureInfoTable(sgFHCDRight);

  // ===========================================================================

  bFHISelect->Enabled  = aDisableBuildInformationTabs;
  sbFHGetDate->Enabled = aDisableBuildInformationTabs;

  // ===========================================================================

    sgFHTable.ClearRows(1, sgFHTable->RowCount - 1);
    sgFHTable->RowCount = 2;

    sgFHTable->Cells[ 0, 0] = GLanguageHandler->Text[kDate];
    sgFHTable->Cells[ 1, 0] = GLanguageHandler->Text[kFiles];
    sgFHTable->Cells[ 2, 0] = GLanguageHandler->Text[kDelta];
    sgFHTable->Cells[ 4, 0] = GLanguageHandler->Text[kFolders];
    sgFHTable->Cells[ 5, 0] = GLanguageHandler->Text[kDelta];
    sgFHTable->Cells[ 7, 0] = GLanguageHandler->Text[kTotalSize];
    sgFHTable->Cells[ 8, 0] = GLanguageHandler->Text[kDelta];
    sgFHTable->Cells[10, 0] = GLanguageHandler->Text[kUsedSpace];
    sgFHTable->Cells[11, 0] = GLanguageHandler->Text[kDelta];

  // ===========================================================================

    sgFHCompareLeft.ClearRows(1, sgFHCompareLeft->RowCount - 1);
    sgFHCompareLeft->RowCount = 2;

    if aMode = False then {
      sgFHCompareLeft->Cells[ 0, 0]  = GLanguageHandler->Text[kFilename];
      sgFHCompareLeft->Cells[ 1, 0]  = GLanguageHandler->Text[kSize];
      sgFHCompareLeft->Cells[ 2, 0]  = GLanguageHandler->Text[kSizeOD];
      sgFHCompareLeft->Cells[ 3, 0]  = GLanguageHandler->Text[kCreated];
      sgFHCompareLeft->Cells[ 4, 0]  = GLanguageHandler->Text[kAccessed];
      sgFHCompareLeft->Cells[ 5, 0]  = GLanguageHandler->Text[kModified];
      sgFHCompareLeft->Cells[ 6, 0]  = GLanguageHandler->Text[kOwner];
      sgFHCompareLeft->Cells[ 7, 0]  = GLanguageHandler->Text[kStatus];
    };

    eFHCompareSearchChange(Nil);
    lFHCompareRight->Caption = rsEllipsis;
    lFHCompareLeft->Caption  = rsEllipsis;

  // ===========================================================================

    sgFHCompareRight.ClearRows(1, sgFHCompareRight->RowCount - 1);
    sgFHCompareRight->RowCount = 2;

    if aMode=False then {
	  sgFHCompareRight->Cells[ 0, 0]  = GLanguageHandler->Text[kFilename];
      sgFHCompareRight->Cells[ 1, 0]  = GLanguageHandler->Text[kSize];
      sgFHCompareRight->Cells[ 2, 0]  = GLanguageHandler->Text[kSizeOD];
      sgFHCompareRight->Cells[ 3, 0]  = GLanguageHandler->Text[kCreated];
      sgFHCompareRight->Cells[ 4, 0]  = GLanguageHandler->Text[kAccessed];
      sgFHCompareRight->Cells[ 5, 0]  = GLanguageHandler->Text[kModified];
      sgFHCompareRight->Cells[ 6, 0]  = GLanguageHandler->Text[kOwner];
      sgFHCompareRight->Cells[ 7, 0]  = GLanguageHandler->Text[kStatus];
    };

  // ===========================================================================

    vtcFolderHistory.SeriesList.Clear;

  // ============================================================================

  if Assigned(FOnResetDisplay) then
	FOnResetDisplay(dataFolderHistory);*/
}
#pragma }_region


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
#pragma }_region


#pragma region Application_Hooks
#pragma }_region


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
	return L"";//Result = cbFHAvailablePath->Text;
}


void TFrameFolderHistory::SetSelectedPath(const std::wstring path)
{
/*var
  t, xfound : integer;

	if aPath != L""
	{
		xfound = -1;

		cbFHAvailableComputerChange(Nil);

		for t = 0 to cbFHAvailablePath->Items->Count - 1
		{
			if UpperCase(cbFHAvailablePath->Items[t]) = UpperCase(aPath)
			{
				xfound = t;
			}
		}

		if xfound != -1
		{
			cbFHAvailablePath->ItemIndex = xfound;

			sbFHOpenFolderClick(Nil);
		}
	} */
}


std::wstring TFrameFolderHistory::GetSelectedComputer()
{
	return L"";//  Result = cbFHAvailableComputer->Text;
}


std::wstring TFrameFolderHistory::GetFolderHistoryItem(int index)
{
/*	if (index < clbFolderHistory.Count)
	{
		Result = clbFolderHistory->Items[Index];
	}      */

	return L"";
}


std::wstring TFrameFolderHistory::GetFolderHistoryItemSelected()
{
	return L"";// Result = clbFolderHistory->Items[bFHISelect->Tag];
}


void TFrameFolderHistory::DoFHSearch(const std::wstring search_term)
{
}


void TFrameFolderHistory::DoCompareSearch(const std::wstring search_term)
{
/*	if aSearchTerm != L"")
	{
		eFHCompareSearch->Text = aSearchTerm;

		sbFHCompareSearchClick(Nil);
	}*/
}


void TFrameFolderHistory::DoCompareDriveSearch(const std::wstring search_term)
{
/*	if aSearchTerm != L"")
	{
		eFHCompareDriveFolder->Text = aSearchTerm;

		sbFHCompareFolderSearchClick(Nil);
	}*/
}


bool TFrameFolderHistory::GetAvailablePathContains(const std::wstring path)
{
/*	if cbFHAvailablePath->Items->IndexOf(aPath) = -1)
	{
		Result = True
	}
	else
	{
		Result = False;
	}*/
}


void TFrameFolderHistory::SetSelectedPathWithoutExecute(const std::wstring path)
{
/*	if aPath != L"")
	{
		xfound = -1;

		cbFHAvailableComputerChange(Nil);

		for t = 0 to cbFHAvailablePath->Items->Count - 1)
		{
			if cbFHAvailablePath->Items[t] = UpperCase(aPath)
			{
				xfound = t;
			}
		}

		if xfound != -1)
		{
			cbFHAvailablePath->ItemIndex = xfound;
		}
	}*/
}
#pragma }_region


#pragma region Tab_Stats
void __fastcall TFrameFolderHistory::SpeedButton1Click(TObject *Sender)
{
/*  if not(GSettingsHandler->ProcessWindowsVisible)
	{
		lDBExists = True;

		if not(GSettingsHandler->Database.UseODBC)
		{
			if not(FileExists(GSystemGlobal.AppDataPath + "FolderHistory\Database\Xinorbis.db"))
			{
				lDBExists = False;
			}
		}

		if lDBExists
		{
			if cbFHAvailablePath->Text != L""
			{
				GScanDetails[dataFolderHistory].ScanPath = cbFHAvailablePath->Text;

				tpFHStats.Visible  = True;         // to do make sure new layout
				tsFHMainSearch.TabVisible = True;

				ResetDisplay(True, False);

				BuildFolderHistory(cbFHAvailableComputer->Text, cbFHAvailablePath->Text);

				BuildTimeLine;
			}
		}
		else
		{
			ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kNoFHFSelected], XDialogTypeWarning);
		}
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kError] + " " + GLanguageHandler->Text[kFolderHistory],
				   TLanguageHandler.FillParameter(rsCannotFindFileParam, GSystemGlobal.AppDataPath + "FolderHistory\Database\Xinorbis.db"),
				   XDialogTypeWarning);
	}*/
}


void __fastcall TFrameFolderHistory::cbFHAvailableComputerChange(TObject *Sender)
{
/*  fha : TFolderHistoryInfo;
  t : integer;
  s : string;

 {
	cbFHAvailableFilter->Items->Clear;
	cbFHAvailableFilter->Items->Add("*");
	cbFHAvailableFilter.Sorted = True;
	cbFHAvailablePath->Items->Clear;

	for t = 0 to FolderHistoryAvailable.Count - 1 do
	{
		fha = FolderHistoryAvailable[t];

		if fha.ComputerName = cbFHAvailableComputer->Items[cbFHAvailableComputer->ItemIndex]
		{
			if (AnsiStartsStr("\\", fha.ScanPath))
			{
				s = "\\"
			}
			else
			{
				s = Copy(fha.ScanPath, 1, 3);
			}

			if (cbFHAvailableFilter->Items->IndexOf(s) = -1)
			{
				cbFHAvailableFilter->Items->Add(s);
			}

			cbFHAvailablePath->Items->Add(fha.ScanPath);
		}
	}

	if (cbFHAvailablePath->Tag < cbFHAvailablePath->Items->Count) and (cbFHAvailablePath->Tag != -1)
	{
		cbFHAvailablePath->ItemIndex = cbFHAvailablePath->Tag
	}
	else
	{
		cbFHAvailableFilter->ItemIndex = 0;
		cbFHAvailablePath->ItemIndex   = 0;
	}

	cbFHAvailablePath.Refresh;*/
}


void __fastcall TFrameFolderHistory::cbFHAvailableFilterChange(TObject *Sender)
{
/*  fha : TFolderHistoryInfo;
  t : integer;
  lAll : boolean;

	cbFHAvailablePath->Items->Clear;

	if cbFHAvailableFilter->Text = "*")
	{
		lAll = true
	}
	else
	{
		lAll = false;
	}

	for t = 0 to FolderHistoryAvailable.Count - 1 do
	{
		fha = FolderHistoryAvailable[t];

		if fha.ComputerName = cbFHAvailableComputer->Items[cbFHAvailableComputer->ItemIndex]
		{
			if lAll)
			{
				cbFHAvailablePath->Items->Add(fha.ScanPath)
			}
			else
			{
				if AnsiStartsStr(cbFHAvailableFilter->Text, fha.ScanPath)
				{
					cbFHAvailablePath->Items->Add(fha.ScanPath)
				}
			}
		}
	}

	if (cbFHAvailablePath->Tag < cbFHAvailablePath->Items->Count) and (cbFHAvailablePath->Tag != -1)
	{
		cbFHAvailablePath->ItemIndex = cbFHAvailablePath->Tag
	}
	else
	{
		cbFHAvailablePath->ItemIndex   = 0;
	}

	cbFHAvailablePath.Refresh;*/
}


void __fastcall TFrameFolderHistory::cbFHAvailablePathChange(TObject *Sender)
{
/*  ResetDisplay(False, False);

	cbFHAvailablePath->Tag   = cbFHAvailablePath->ItemIndex;

	bFHISelect->Caption      = GLanguageHandler->Text[kSelectDateTime];
	bFHISelect->Enabled      = False;
	bFHISelect->Tag          = -1;

	// ===========================================================================

	bFHCompareLeft->Caption  = GLanguageHandler->Text[kSelectDateTime];
	bFHCompareRight->Caption = GLanguageHandler->Text[kSelectDateTime];
	bFHCompareLeft->Tag      = -1;
	bFHCompareRight->Tag     = -1;

	bFHCompareLeft->Caption  = GLanguageHandler->Text[kSelectDateTime];
	bFHCompareRight->Caption = GLanguageHandler->Text[kSelectDateTime];
	bFHCompareLeft->Tag      = -1;
	bFHCompareRight->Tag     = -1;

	bFHCompareFolderLeft->Caption  = GLanguageHandler->Text[kSelectDateTime];
	bFHCompareFolderRight->Caption = GLanguageHandler->Text[kSelectDateTime];
	bFHCompareFolderLeft->Tag      = -1;
	bFHCompareFolderRight->Tag     = -1;

	bFHCompareTreeLeft->Caption  = GLanguageHandler->Text[kSelectDateTime];
	bFHCompareTreeRight->Caption = GLanguageHandler->Text[kSelectDateTime];
	bFHCompareTreeLeft->Tag      = -1;
	bFHCompareTreeRight->Tag     = -1;

	tvFHTLeft->Items->Clear;
	tvFHTRight->Items->Clear;

	// =========================================================================

	if Assigned(FOnUpdateLeftStatusPanel)
	{
		FOnUpdateLeftStatusPanel(0);
	}*/
}


void __fastcall TFrameFolderHistory::sbStatsInfoClick(TObject *Sender)
{
	//DoDBSelectedFolder(cbFHAvailableComputer->Text, UpperCase(cbFHAvailablePath->Text));
}


void __fastcall TFrameFolderHistory::SpeedButton2Click(TObject *Sender)
{
/*  s = DoShowCal}ar(clbFolderHistory->Items);

	if s != L"" then
	{
		dx = Convert::IntDateToString(StrToInt(Copy(s, 1, 8))) + " " +
								   s[9] + s[10] + ":" + s[11] + s[12] + ":" + s[13] + s[14];

		i = FindFolderHistoryItem(dx);

		if i != -1
		{
			bFHISelect->Tag     = i;
			bFHISelect->Caption = dx;

			if bFHISelect->Tag != -1)
			{
				sbFHBuildInformationTabsClick(nil);
			}
		}
	}*/
}


void __fastcall TFrameFolderHistory::bFHISelectClick(TObject *Sender)
{
/*  if not(GSettingsHandler->ProcessWindowsVisible)
	{
		puFHSelectDate->Tag = 1;

		puFHSelectDate->Popup(FGetLeftOffset + bFHISelect.Left + 20,
						 FGetTopOffset + 227);
	};*/
}


void __fastcall TFrameFolderHistory::pcStatsChange(TObject *Sender)
{
/*  if Assigned(FSetTutorialBarText)
	{
		FSetTutorialBarText(GSystemGlobal.ExePath + "data\languages\" + TLanguageHandler.GetLanguageSymbol(GSettingsHandler->CurrentLanguage) +
												"\tutorial\fht" + IntToStr(tpFHStats.ActivePageIndex) + ".dat");  // to do make sure new layout
	}

	if tpFHStats.ActivePageIndex = 5)
	{
		atlFolderHistory.VerticalMargin = Round(atlFolderHistory.Height / 2) - 10;
	}*/
}


void TFrameFolderHistory::BuildFolderHistorySelectDataMenu()
{ /*
  mi : TMenuItem;
  LastYearNode, LastMonthNode, LastDayNode : TMenuItem;
  lyy, lmm, ldd, t : integer;
  cyy, cmm, cdd : integer;
  xdate : string;

 {
  bFHISelect->Tag = -1;
  LastYearNode   = Nil;
  LastMonthNode  = Nil;
  LastDayNode    = Nil;
  lyy            = -1;
  lmm            = -1;
  ldd            = -1;

  puFHSelectDate->Items->Clear;

  for t = 0 to clbFolderHistory.Count - 1 do {
    xdate = Convert::DateTimeFToYYYYMMDD(clbFolderHistory->Items[t]);

    if xdate != L"" then {
	  cyy = StrToInt(Copy(xdate, 1, 4));
      cmm = StrToInt(Copy(xdate, 5, 2));
      cdd = StrToInt(Copy(xdate, 7, 2));

      if cyy != lyy then {
        mi = TMenuItem.Create(puFHSelectDate);
        mi->Caption = IntToStr(cyy);

        puFHSelectDate->Items->Add(mi);
        LastYearNode = mi;

        lyy = cyy;
      };

      if cmm != lmm then {
        mi = TMenuItem.Create(puFHSelectDate);
        mi->Caption = months[cmm];

        LastYearNode.Add(mi);
        LastMonthNode = mi;

        lmm = cmm;
      };

      if cdd != ldd then {
        mi = TMenuItem.Create(puFHSelectDate);
		mi->Caption = IntToStr(cdd);

		LastMonthNode.Add(mi);
		LastDayNode = mi;

		ldd = cdd;
	  };

	  mi = TMenuItem.Create(puFHSelectDate);
	  mi.OnClick = miSelectDateTimeClick;
	  mi->Caption = Copy(clbFolderHistory->Items[t], 12, 8);
	  mi->Tag     = t;

	  LastDayNode.Add(mi);
	};
  }; */
}


void TFrameFolderHistory::BuildFolderHistoryAvailable()
{
/* var
  sr : TSearchRec;
  tf : TextFile;
  fha : TFolderHistoryInfo;
  sp, thispc  : string;
  t, tpxidx : integer;

 function GetPathFromFHFile(const FileName : string): string;
  var
   s : string;

  {
   AssignFile(tf, FileName);
   {$I-}
   Reset(tf);

   if IOResult != 0 then {
	 ShowXDialog(GLanguageHandler->Text[kError] + ": " + GLanguageHandler->Text[kFolderHistory],
				 GLanguageHandler->Text[kErrorOpening] + " L"" + filename + L"".",
				 XDialogTypeWarning);
   }
   else {
	 Readln(tf, s);

	 CloseFile(tf);
   };
   {$I+}

   Result = s;
 };

 function GetComputerNameFromPath(const FileName : string): string;
  var
   s : string;
   i,z : integer;

  {
   s = L"";
   z = Pos("FOLDERHISTORY\", UpperCase(FileName));

   i = z + 14;
   while FileName[i] != "\" do {
	 s = s + FileName[i];

	 inc(i);
   };

   Result = s;
 };

 {
  if (GSettingsHandler->HistorySettings->Enabled) and (GSettingsHandler->System.UserEnabledFH) then {
	cbFHAvailablePath->Items->Clear;
	cbFHAvailableComputer->Items->Clear;
	FolderHistoryAvailable.Clear;

	thispc = TXWindows.GetComputerNetName;
	tpxidx = 0;

	// firstly we need a list of computer names and paths that have been scanned...
	if FindFirst(GSystemGlobal.AppDataPath + "folderhistory\" + thispc + "\*.xfh", $3F, sr) = 0 then {
	  repeat
		sp = GetPathFromFHFile(GSystemGlobal.AppDataPath + "folderhistory\" + thispc + "\" + sr.Name);

		fha = TFolderHistoryInfo.Create;
		fha.ScanPath     = sp;
		fha.MD5          = sr.Name;
		fha.ComputerName = GetComputerNameFromPath(GSystemGlobal.AppDataPath + "folderhistory\" + thispc + "\" + sr.Name);;

		FolderHistoryAvailable.Add(fha);

	  until FindNext(sr) != 0;

	  FindClose(sr);
	};

	// now we populate the GUI with the new details
	for t = 0 to FolderHistoryAvailable.Count - 1 do {
	  fha = FolderHistoryAvailable[t];

	  if cbFHAvailableComputer->Items->IndexOf(fha.ComputerName) = -1 then
		cbFHAvailableComputer->Items->Add(fha.ComputerName);

	  if fha.ComputerName = thispc then
		tpxidx = cbFHAvailableComputer->Items->Count - 1;

	};

	FolderHistoryAvailable.Sort(TComparer<TFolderHistoryInfo>.Construct(CompareFHPaths));

	cbFHAvailableComputer->ItemIndex = tpxidx;

	cbFHAvailableComputerChange(Nil);

	if cbFHAvailableComputer->Items->Count = 0 then {
	  cbFHAvailableComputer->Items->Add(thispc);
	  cbFHAvailableComputer->ItemIndex = 0;
	};

	cbFHAvailableComputer->Tag = -1;
	cbFHAvailablePath->Tag     = -1;
  };*/
}


void TFrameFolderHistory::BuildFolderHistory(const std::wstring computer_name, const std::wstring scan_path)
{
/*  bFHISelect->Caption            = GLanguageHandler->Text[kSelectDateTime];
  bFHCompareLeft->Caption        = GLanguageHandler->Text[kSelectDateTime];
  bFHCompareRight->Caption       = GLanguageHandler->Text[kSelectDateTime];
  bFHCompareFolderLeft->Caption  = GLanguageHandler->Text[kSelectDateTime];
  bFHCompareFolderRight->Caption = GLanguageHandler->Text[kSelectDateTime];

  bFHISelect->Tag                = -1;
  bFHISelect->Enabled            = True;
  bFHCompareLeft->Tag            = -1;
  bFHCompareRight->Tag           = -1;
  bFHCompareFolderLeft->Tag      = -1;
  bFHCompareFolderRight->Tag     = -1;

  FolderHistory.Clear;

  clbFolderHistory.Clear;

  sgFHCompareLeft.ClearRows(1, sgFHCompareLeft->RowCount - 1);
  sgFHCompareRight.ClearRows(1, sgFHCompareRight->RowCount - 1);
  sgFHCompareLeft->RowCount  = 2;
  sgFHCompareRight->RowCount = 2;

  if LoadFolderHistory(ComputerName, ScanPath, clbFolderHistory->Items) then {

    if FolderHistory.Count > 0 then {

      BuildFolderHistoryTable;

      // ===========================================================================

      TDisplayUtility.BuildFolderHistoryGraph(FrameSelect.ePath->Text, vtcFolderHistory, clbFolderHistory, rbFHCount.Checked, rbFHSize.Checked, rbFHMagCount.Checked, rbFHMagSize.Checked);

      if clbFolderHistory.Count != 0 then {
        clbFolderHistory.Checked[0]     = True;
        clbFolderHistory->ItemIndex      = 0;
		rbFHCountClick(Nil);
      };

      if clbFolderHistory.Count != 0 then
		FileHistoryControlStatus(True)
      else
        FileHistoryControlStatus(False);
    }
    else {
      ShowXDialog(GLanguageHandler->Text[kError] + " :: " + GLanguageHandler->Text[kFolderHistory], "Error building File History!", XDialogTypeWarning);
    };
  }
  else {
    if FileExists(GSystemGlobal.AppDataPath + "FolderHistory\" + ComputerName + "\" + TMD5.Generate(UpperCase(ScanPath)) + ".xfh") then {
      if MessageDlg(GLanguageHandler->Text[kDialog7] + #13#13 + GLanguageHandler->Text[kDialog8], mtInformation, [mbYes, mbNo], 0) = mrYes then {
		RepairFile(TMD5.Generate(UpperCase(ScanPath)) + ".xfh", GSystemGlobal.AppDataPath + "FolderHistory\" + ComputerName + "\" + TMD5.Generate(ScanPath) + ".xfh");
	  };
	};
  };

  BuildFolderHistorySelectDataMenu; */
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
/*  bFHISelect->Enabled  = newstatus;
	sbFHGetDate->Enabled = newstatus;

	rbFHCount->Enabled                = newstatus;
	rbFHSize->Enabled                 = newstatus;

	rbFJTRToday->Enabled              = newstatus;
	rbFJTRPrevious->Enabled           = newstatus;

	for t = 0 to __FileCategoriesCount do
	FHCatButtons[t]->Enabled = newstatus;

	rbFHMagCount->Enabled               = newstatus;
	rbFHMagSize->Enabled                = newstatus;

	sbFHCompareFavourites->Enabled      = newstatus;
	sbfhCompareDriveFavourites->Enabled = newstatus;
	sbFHCompareSearch->Enabled          = newstatus;
	sbFHCSearchSyntax->Enabled          = newstatus;
	eFHCompareSearch->Enabled           = newstatus;
	cbFHCompareUnits->Enabled           = newstatus;
	cbFHComparePath->Enabled            = newstatus;
	cbFHCompareColour->Enabled          = newstatus;
	sbFHCompareLeftSave->Enabled        = newstatus;
	sbFHCompareRightSave->Enabled       = newstatus;

	sbFHCompareFolderSearch->Enabled    = newstatus;
	eFHCompareDriveFolder->Enabled      = newstatus;
	sbFHCompareFolderLeftSave->Enabled  = newstatus;
	sbFHCompareFolderRightSave->Enabled = newstatus; */
}
#pragma }_region


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
/*	if clbFolderHistory->ItemIndex != -1)
	{
		int fhidx = (FolderHistory.Count - clbFolderHistory->ItemIndex) - 1;

		lFHFileCount->Caption = IntToStr(FolderHistory[fhidx].FileCount);
		lFHFileSize->Caption  = Convert::ConvertToUsefulUnit(FolderHistory[fhidx].FileSize);
		lFHFolders->Caption   = IntToStr(FolderHistory[fhidx].FolderCount);
	}

	TDisplayUtility.BuildFolderHistoryGraph(GScanDetails[dataFolderHistory].ScanPath,
											vtcFolderHistory,
											clbFolderHistory,
											rbFHCount.Checked, rbFHSize.Checked, rbFHMagCount.Checked, rbFHMagSize.Checked);*/
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
/*  FHCCStatus[TSpeedbutton(Sender)->Tag] = not FHCCStatus[TSpeedbutton(Sender)->Tag];

	if FHCCStatus[TSpeedbutton(Sender)->Tag])
	{
		idx = FHCCImageBase[TSpeedbutton(Sender)->Tag]
	}
	else
	{
		idx = FHCCImageBase[TSpeedbutton(Sender)->Tag] + 1;
	}

	GXGuiUtil.SetFolderHistoryButtonImage(TSpeedbutton(Sender), idx);

	rbFHCountClick(Nil);*/
}
#pragma }_region


#pragma region Tab_Stats_Table
void TFrameFolderHistory::InitTable()
{
/*	sgFHTable->ColWidths[0]  = sgFHTable->Width - 603;
	sgFHTable->ColWidths[1]  = 70;
	sgFHTable->ColWidths[2]  = 70;
	sgFHTable->ColWidths[3]  = 6;
	sgFHTable->ColWidths[4]  = 70;
	sgFHTable->ColWidths[5]  = 70;
	sgFHTable->ColWidths[6]  = 6;
	sgFHTable->ColWidths[7]  = 70;
	sgFHTable->ColWidths[8]  = 70;
	sgFHTable->ColWidths[9]  = 6;
	sgFHTable->ColWidths[10] = 70;
	sgFHTable->ColWidths[11] = 70;*/
}


void __fastcall TFrameFolderHistory::rbStatsTableTodayClick(TObject *Sender)
{
	BuildFolderHistoryTable();
}


void __fastcall TFrameFolderHistory::StringGrid1DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*  if (ACol > 0) and (ARow > 0)
	{
		if sgFHTable->Cells[ACol, ARow] != L""
		{
			if gdSelected in State
			{
				sgFHTable->Canvas->Brush->Color = sgFHTable.SelectionColor;
			}
			else
			{
				if odd(ARow)
				{
					sgFHTable->Canvas->Brush->Color = sgFHTable.Bands.PrimaryColor
				}
				else
				{
					sgFHTable->Canvas->Brush->Color = $00FFFFFF;
				}
			}

			//sgFHTAble->Canvas.FillRect(Rect);
			//sgFHTable->Canvas->TextRect(Rect, Rect.Left + sgFHTable->ColWidths[ACol] - sgFHTable->Canvas->TextWidth(sgFHTable->Cells[ACol, ARow]) - 5, Rect.Top + 1, sgFHTable->Cells[ACol, ARow]);
		}
	}*/
}


void TFrameFolderHistory::BuildFolderHistoryTable()
{
/*TGridUtility.ClearStringGird(sgFHTable, False);

  // now build table ===========================================================

  sgFHTable.{Update;

  sgFHTable->RowCount = 1 + clbFolderHistory->Items->Count;

  i = clbFolderHistory->Items->Count;

  if rbFJTRPrevious.Checked then {
    for t = 0 to clbFolderHistory->Items->Count - 1 do {
      sgFHTable->Cells[ 0, i] = FolderHistory[t].ScanDateStr;

      sgFHTable->Cells[ 1, i] = IntToStr(FolderHistory[t].FileCount);
      sgFHTable->Cells[ 4, i] = IntToStr(FolderHistory[t].FolderCount);
      sgFHTable->Cells[ 7, i] = Convert::ConvertToUsefulUnit(FolderHistory[t].FileSize);
      sgFHTable->Cells[10, i] = Convert::ConvertToUsefulUnit(FolderHistory[t].FileSizeOnDisk);

      if t = 0 then {
        sgFHTable->Cells[ 2, i] = L"";
        sgFHTable->Cells[ 5, i] = L"";
        sgFHTable->Cells[ 8, i] = L"";
        sgFHTable->Cells[11, i] = L"";
      }
      else {
        sgFHTable->Cells[ 2, i] = Convert::GetDelta(FolderHistory[t].FileCount -
                                                    FolderHistory[t - 1].FileCount);

        sgFHTable->Cells[ 5, i] = Convert::GetDelta(FolderHistory[t].FolderCount -
                                                    FolderHistory[t - 1].FolderCount);

        sgFHTable->Cells[ 8, i] = Convert::GetDeltaSize(FolderHistory[t].FileSize-
                                                        FolderHistory[t - 1].FileSize);

        sgFHTable->Cells[11, i] = Convert::GetDeltaSize(FolderHistory[t].FileSizeOnDisk-
                                                        FolderHistory[t - 1].FileSizeOnDisk);
      };

      dec(i);
    };
  }
  else {
    for t = 0 to clbFolderHistory->Items->Count - 1 do {
      sgFHTable->Cells[ 0, i] = FolderHistory[t].ScanDateStr;

      sgFHTable->Cells[ 1, i] = IntToStr(FolderHistory[t].FileCount);
      sgFHTable->Cells[ 4, i] = IntToStr(FolderHistory[t].FolderCount);
      sgFHTable->Cells[ 7, i] = Convert::ConvertToUsefulUnit(FolderHistory[t].FileSize);
      sgFHTable->Cells[10, i] = Convert::ConvertToUsefulUnit(FolderHistory[t].FileSizeOnDisk);

      if t = clbFolderHistory->Items->Count - 1 then {
        sgFHTable->Cells[ 2, i] = L"";
        sgFHTable->Cells[ 5, i] = L"";
        sgFHTable->Cells[ 8, i] = L"";
        sgFHTable->Cells[11, i] = L"";
      }
      else {
        sgFHTable->Cells[ 2, i] = Convert::GetDelta(FolderHistory[t].FileCount -
                                           FolderHistory[clbFolderHistory->Items->Count - 1].FileCount);

        sgFHTable->Cells[ 5, i] = Convert::GetDelta(FolderHistory[t].FolderCount -
                                           FolderHistory[clbFolderHistory->Items->Count - 1].FolderCount);

        sgFHTable->Cells[ 8, i] = Convert::GetDeltaSize(FolderHistory[t].FileSize -
                                           FolderHistory[clbFolderHistory->Items->Count - 1].FileSize);

        sgFHTable->Cells[11, i] = Convert::GetDelta(FolderHistory[t].FileSizeOnDisk -
                                           FolderHistory[clbFolderHistory->Items->Count - 1].FileSizeOnDisk);
      };

      dec(i);
    };
  };

  sgFHTable.}Update; */
}
#pragma }_region


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
#pragma }_region


#pragma region Tab_Generic
void __fastcall TFrameFolderHistory::ShowCalendar(TObject *Sender)
{
/* var
  s,dx : string;
  i : integer;

	s = DoShowCal}ar(clbFolderHistory->Items);

	if s != L""
	{
		dx = Convert::IntDateToString(StrToInt(Copy(s, 1, 8))) + " " +
									   s[9] + s[10] + ":" + s[11] + s[12] + ":" + s[13] + s[14];

		i = FindFolderHistoryItem(dx);

		if i != -1
		{
			switch TSpeedButton(Sender)->Tag of
			CCompareLeft        : {
									bFHCompareLeft->Tag     = i;
									bFHCompareLeft->Caption = dx;
								  };
			CCompareRight       : {
									bFHCompareRight->Tag     = i;
									bFHCompareRight->Caption = dx;
								  };
			CCompareFolderLeft  : {
									bFHCompareFolderLeft->Tag     = i;
									bFHCompareFolderLeft->Caption = dx;
								  };
			CCompareFolderRight : {
									bFHCompareFolderRight->Tag     = i;
									bFHCompareFolderRight->Caption = dx;
								  };
			CCompareTreeLeft    : {
									bFHCompareTreeLeft->Tag     = i;
									bFHCompareTreeLeft->Caption = dx;
								  };
			CCompareTreeRight   : {
									bFHCompareTreeRight->Tag     = i;
									bFHCompareTreeRight->Caption = dx;
								  };
			}
		}
	} */
}


void __fastcall TFrameFolderHistory::sbShowManualClick(TObject *Sender)
{
	//THelp.OpenSearchManual;
}


void __fastcall TFrameFolderHistory::sbSearchSyntaxClick(TObject *Sender)
{
//
}


int TFrameFolderHistory::FindFolderHistoryItem(const std::wstring item)
{
/*  Result = -1;

	for t = 0 to clbFolderHistory->Items->Count - 1)
	{
		if clbFolderHistory->Items[t] = xItem)
		{
			Result = t;

			Break;
		}
	}*/
}


void TFrameFolderHistory::BuildInformationTabs()
{
/*  if (bFHISelect->Tag != -1) then {

	std::wstring dt = Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHISelect->Tag]);

	// ===========================================================================

	if TableExists(TMD5.Generate(UpperCase(cbFHAvailablePath->Text)) + DT + cbFHAvailableComputer->Text) then {

//      if Assigned(FOnProcessWindowStatus) then
//        FOnProcessWindowStatus(CWindowAnalysisProgress, 1);

	  TPreScan.PurgeAllData(dataFolderHistory, Nil, Nil, Nil); //sgNullFiles, sgSearchResults);

	  Screen.Cursor          = crSQLWait;
	  llFHPleaseWait.Visible = True;

	  if Assigned(FScanFromFolderHistory) then
		FScanFromFolderHistory(cbFHAvailablePath->Text,
							   TMD5.Generate(UpperCase(cbFHAvailablePath->Text)) + DT + cbFHAvailableComputer->Text,
							   Convert::YYYYMMDDHHMMSSToString(DT));

	  if assigned(FOnUpdateHistoryFinished) then
		FOnUpdateHistoryFinished;

	  llFHPleaseWait.Visible = False;
	}
	else {
	  ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kNoFileData] + ": " + bFHISelect->Caption, XDialogTypeWarning);
	};
	}*/
}
#pragma }_region


#pragma region Tab_Search_Compare
void TFrameFolderHistory::InitCompare()
{
   /*	sgFHCompareLeft.HideColumns(8, 13);

	sgFHCompareLeft->ColWidths[0] = sgFHCompareLeft->Width - 530;
	sgFHCompareLeft->ColWidths[1] = 70;
	sgFHCompareLeft->ColWidths[2] = 70;
	sgFHCompareLeft->ColWidths[3] = 70;
	sgFHCompareLeft->ColWidths[4] = 70;
	sgFHCompareLeft->ColWidths[5] = 70;
	sgFHCompareLeft->ColWidths[6] = 100;
	sgFHCompareLeft->ColWidths[7] = 55;

	// ===========================================================================

	sgFHCompareRight.HideColumns(8, 13);

	sgFHCompareRight->ColWidths[0] = sgFHCompareRight->Width - 530;
	sgFHCompareRight->ColWidths[1] = 70;
	sgFHCompareRight->ColWidths[2] = 70;
	sgFHCompareRight->ColWidths[3] = 70;
	sgFHCompareRight->ColWidths[4] = 70;
	sgFHCompareRight->ColWidths[5] = 70;
	sgFHCompareRight->ColWidths[6] = 100;
	sgFHCompareRight->ColWidths[7] = 55;*/
}


void __fastcall TFrameFolderHistory::sbQuickSearchClick(TObject *Sender)
{
//  puFHQuickSearch->Tag = TSpeedbutton(Sender)->Tag;

//  puFHQuickSearch->Popup(FGetLeftOffset + 38, FGetTopOffset + 205);
}


void __fastcall TFrameFolderHistory::sbGoSearchClick(TObject *Sender)
{
/*  if not(GSettingsHandler->ProcessWindowsVisible)
	{
		if not(GSettingsHandler->ProcessWindowsVisible)
		{
			if (bFHCompareLeft->Tag != -1) and (bFHCompareRight->Tag != -1)
			{
				if eFHCompareSearch->Text != L"")
				{
					FHCompareBuildLeft(Nil);
					FHCompareBuildRight(Nil);

					if eFHCompareSearch->Items->IndexOf(eFHCompareSearch->Text) = -1)
					{
						if eFHCompareSearch->Text != L"")
						{
							eFHCompareSearch->Items->Insert(0, eFHCompareSearch->Text);
						}
					}
				}
			}
			else
			{
				ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kPleaseSelectADate], XDialogTypeWarning);
			}
		}
	}*/
}


void __fastcall TFrameFolderHistory::eSearchChange(TObject *Sender)
{
/*  lCLPagePrevious->Tag     = 0;
	lCRPagePrevious->Tag     = 0;

	lCLPagePrevious->Enabled = False;
	lCLPageNext->Enabled     = False;
	lCLPageNumber->Caption   = "1";
	lCLShowing->Caption      = "n/a";

	lCRPagePrevious->Enabled = False;
	lCRPageNext->Enabled     = False;
	lCRPageNumber->Caption   = "1";
	lCRShowing->Caption      = "n/a";*/
}


void __fastcall TFrameFolderHistory::eSearchKeyPress(TObject *Sender, System::WideChar &Key)
{
/*  if key = #13 then
  {
	sbFHCompareSearchClick(sbFHCompareSearch);
  }*/
}


void __fastcall TFrameFolderHistory::BitBtn1Click(TObject *Sender)
{
/*  puFHSelectDate->Tag = 2;

	puFHSelectDate->Popup(FGetLeftOffset + bFHCompareLeft.Left + 20,
					   FGetTopOffset + Panel46.Height + Panel32.Height + pFHCompare.Height + 80);*/
}


void __fastcall TFrameFolderHistory::BitBtn2Click(TObject *Sender)
{
/*  puFHSelectDate->Tag = 3;

  puFHSelectDate->Popup(FGetLeftOffset + bFHCompareRight.Left + Panel15.Left ,
					   FGetTopOffset + Panel46.Height + Panel32.Height + pFHCompare.Height + 80);*/
}


void __fastcall TFrameFolderHistory::cbCompareColourCodeClick(TObject *Sender)
{
/*  if sgFHCompareLeft->Cells[0,1] != L"")
	{
		sgFHCompareLeft.Refresh;
	}

	if sgFHCompareRight->Cells[0,1] != L"")
	{
		sgFHCompareRight.Refresh;
	}*/
}


void __fastcall TFrameFolderHistory::SpeedButton9Click(TObject *Sender)
{
//	TGridUtility.SaveFHStringGridData(sgFHCompareLeft, eFHCompareSearch->Text, fhscModeSaveAll);
}


void __fastcall TFrameFolderHistory::SpeedButton20Click(TObject *Sender)
{
//  TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch->Text, fhscModeSaveAll);
}


void __fastcall TFrameFolderHistory::SpeedButton8Click(TObject *Sender)
{
/*  TGridUtility.ToggleColumn(sgFHCompareLeft,
							TSpeedbutton(Sender),
							TableColumnLookup[(TSpeedbutton(Sender)->Tag * 2) + 1],
							TableColumnLookup[TSpeedbutton(Sender)->Tag * 2]);

  Splitter2Moved(Nil);*/
}


void __fastcall TFrameFolderHistory::SpeedButton17Click(TObject *Sender)
{
/*  TGridUtility.ToggleColumn(sgFHCompareRight, TSpeedbutton(Sender), TableColumnLookup[(TSpeedbutton(Sender)->Tag * 2) + 1], TableColumnLookup[TSpeedbutton(Sender)->Tag * 2]);

  Splitter2Moved(Nil);*/
}


void __fastcall TFrameFolderHistory::SpeedButton15Click(TObject *Sender)
{
/*  if sbFHCShowLeft->Tag = 0 then {
	GXGuiUtil.SetButtonOffImage(sbFHCShowLeft, CImageShow);
	Screen.Cursor = crHourGlass;

	sbFHCShowLeft->Tag = 1;
	cbFHCompareColour.Checked = False;
	i = 0;

	FQuickCompareB.Clear;

	for t = 1 to sgFHCompareRight->RowCount - 1 do {
	  FQuickCompareB.Add(sgFHCompareRight->Cells[0, t]);
	};

	FQuickCompareB.Sort;

	// ===========================================================================

	for t = 1 to sgFHCompareLeft->RowCount - 1 do {
	  if FQuickCompareB.IndexOf(sgFHCompareLeft->Cells[0, t]) != -1 then
		sgFHCompareLeft->Cells[FHschCategory, t] = "1"
	  else {
		sgFHCompareLeft->Cells[FHschCategory, t] = "2";

		inc(i);
	  };
	};

	lFHCompareLeft->Caption = GLanguageHandler->Text[kFound] + " <b>" + IntToStr(i) + "</b> " + GLanguageHandler->Text[kFiles] + ".";
	Screen.Cursor = crDefault;
  }
  else {
	sbFHCShowLeft->Tag = 0;
	GImageHandler->SetButtonOnImage(sbFHCShowLeft, kImageShow);
  };

  sgFHCompareLeft.Refresh;*/
}


void __fastcall TFrameFolderHistory::SpeedButton26Click(TObject *Sender)
{
/*  if sbFHCShowRight->Tag = 0 then {
	GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);

	Screen.Cursor = crHourGlass;

	sbFHCShowRight->Tag        = 1;
	cbFHCompareColour.Checked = False;
	i = 0;

	FQuickCompareA.Clear;

	for t = 1 to sgFHCompareLeft->RowCount - 1 do {
	  FQuickCompareA.Add(sgFHCompareLeft->Cells[0, t]);
	};

	FQuickCompareA.Sort;

	// ===========================================================================

	for t = 1 to sgFHCompareRight->RowCount - 1 do {
	  if FQuickCompareA.IndexOf(sgFHCompareRight->Cells[0, t]) != -1 then
		sgFHCompareRight->Cells[FHschCategory, t] = "1"
	  else {
		sgFHCompareRight->Cells[FHschCategory, t] = "2";

		inc(i);
	  };
	};

	lFHCompareRight->Caption = GLanguageHandler->Text[kFound] + " <b>" + IntToStr(i) + "</b> " + GLanguageHandler->Text[kFiles] + ".";;

	Screen.Cursor = crDefault;
  }
  else {
	GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);
	sbFHCShowRight->Tag = 0;
  };

  sgFHCompareRight.Refresh;*/
}


/*procedure TFrameFolderHistory.FHCompareBuildLeft(Sender : TObject);
 var
  SQL : string;

 {
  if Pos("SELECT ", eFHCompareSearch->Text) != 0 then {
    if GSettingsHandler->HistorySettings.SQLinSearch then {
	  SQL = StringReplace(eFHCompareSearch->Text, "*", " FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ", [rfReplaceAll]);

      SQL = StringReplace(SQL, "$x$", L""" + Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareLeft->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text) + L""", [rfReplaceAll]);
    }
    else {
      SQL = L"";

      ShowXDialog(GLanguageHandler->Text[kWarning],
                  GLanguageHandler->Text[kDialog10],
                  XDialogTypeWarning);
    };
  }
  else {
    SQL = TSearchUtility.XinorbisSearchToSQL(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareLeft->Tag]),
                                              cbFHAvailablePath->Text,
                                              cbFHAvailableComputer->Text,
                                              eFHCompareSearch->Text,
                                              lCLPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults,
                                              GSettingsHandler->General.MaxSearchResults,
                                              False)
  };

  if TableExists(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareLeft->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text)) then {
    if SQL != L"" then {
      sbFHCShowLeft->Tag = 0;
      GXGuiUtil.SetButtonOffImage(sbFHCShowLeft, 8);
      Screen.Cursor = crSQLWait;

      LastSQL[2] = SQL;

      GCompareLeftThread = TCompareLeftThread.Create(True);
	  GCompareLeftThread.SetData(SQL, cbFHCompareUnits->ItemIndex, cbFHComparePath.Checked, sgFHCompareLeft);
      GCompareLeftThread.OnTerminate = CompareLeftThreadOnTerminate;
	  GCompareLeftThread.Priority    = tpTimeCritical;        //tpTimeCritical
	  GCompareLeftThread.Start;
	};
  }
  else {
	ShowXDialog(GLanguageHandler->Text[kWarning],
				GLanguageHandler->Text[kNoFileData] + ": " +bFHCompareLeft->Caption,
				XDialogTypeWarning);
  };
};


procedure TFrameFolderHistory.FHCompareBuildRight(Sender : TObject);
 var
  SQL : string;

 {
  if Pos("SELECT ", eFHCompareSearch->Text) != 0 then {
	if GSettingsHandler->HistorySettings.SQLinSearch then {
	  SQL = StringReplace(eFHCompareSearch->Text, "*", " FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ", [rfReplaceAll]);

	  SQL = StringReplace(SQL, "$x$", L""" + Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareRight->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text) + L""", [rfReplaceAll]);
    }
    else {
	  SQL = L"";

      ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kDialog10], XDialogTypeWarning);
    };
  }
  else {
	SQL = TSearchUtility.XinorbisSearchToSQL(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareRight->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text, eFHCompareSearch->Text, lCRPagePrevious->Tag*GSettingsHandler->General.MaxSearchResults, GSettingsHandler->General.MaxSearchResults, False)
  };

  if TableExists(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareRight->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text)) then {
	if SQL != L"" then {
	  sbFHCShowRight->Tag = 0;
	  GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);
	  Screen.Cursor = crSQLWait;

	  LastSQL[3] = SQL;

	  GCompareRightThread = TCompareRightThread.Create(True);
	  GCompareRightThread.SetData(SQL, cbFHCompareUnits->ItemIndex, cbFHComparePath.Checked, sgFHCompareRight);
	  GCompareRightThread.OnTerminate = CompareRightThreadOnTerminate;
      GCompareRightThread.Priority    = tpTimeCritical;
      GCompareRightThread.Start;
	};
  }
  else {
	ShowXDialog(GLanguageHandler->Text[kWarning],
				GLanguageHandler->Text[kNoFileData] + ": " + bFHCompareRight->Caption,
				XDialogTypeWarning);
  };
};      */


/*void procedure TFrameFolderHistory.CompareLeftThreadOnTerminate(Sender : TObject);
 {
  if sgFHCompareLeft->Cells[0, 1] != L"" then {
    if CompareData[XLeftSide].Data[XFileCount] = 0 then
      lFHCompareLeft->Caption = GLanguageHandler->Text[kFound] + " <b>" + IntToStr(CompareData[XLeftSide].Data[XFolderCount]) + "</b> " + GLanguageHandler->Text[kFolders] + "."
    else if CompareData[XRightSide].Data[XFolderCount] = 0 then
      lFHCompareLeft->Caption = GLanguageHandler->Text[kFound] + " <b>" + IntToStr(CompareData[XLeftSide].Data[XFileCount]) + "</b> " + GLanguageHandler->Text[kFiles] + " (<b>" + Convert::ConvertToUsefulUnit(CompareData[XLeftSide].Data[XFileSize]) + "</b>)."
    else
      lFHCompareLeft->Caption = GLanguageHandler->Text[kFound] + " <b>" + IntToStr(CompareData[XLeftSide].Data[XFileCount]) + "</b> " + GLanguageHandler->Text[kFiles] + " (<b>" + Convert::ConvertToUsefulUnit(CompareData[XLeftSide].Data[XFileSize]) + "</b>) + <b>" + IntToStr(CompareData[XLeftSide].Data[XFolderCount]) + "</b> " + GLanguageHandler->Text[kFolders] + ".";
  }
  else
    lFHCompareLeft->Caption = GLanguageHandler->Text[kNoFilesFound];

  // == navigation logic ===================================================

  lCLPageNumber->Caption = IntToStr(lCLPagePrevious->Tag + 1);
  lCLShowing->Caption    = IntToStr(lCLPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults + 1) + rsEllipsis +
                                    IntToStr((lCLPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults) + GSettingsHandler->General.MaxSearchResults);

  if lCLPagePrevious->Tag = 0 then
	lCLPagePrevious->Enabled = False
  else
    lCLPagePrevious->Enabled = True;

  if CompareData[XLeftSide].Data[XFileCount] + CompareData[XLeftSide].Data[XFolderCount] < GSettingsHandler->General.MaxSearchResults then {
    if lCLPagePrevious->Tag = 0 then
      lCLPagePrevious->Enabled = False
    else
      lCLPagePrevious->Enabled = True;

    lCLPageNext->Enabled = False;
  }
  else {
    lCLPagePrevious->Enabled = True;
    lCLPageNext->Enabled     = False;
  };

  // =======================================================================

  sgFHCompareLeft.}Update;

  TGridUtility.SortTable(sgFHCompareLeft, sgFHCompareLeft.SortSettings.Column);

  Screen.Cursor = crDefault;
};


procedure TFrameFolderHistory.CompareRightThreadOnTerminate(Sender : TObject);
 {
  if sgFHCompareRight->Cells[0,1] != L"" then {
    if CompareData[XRightSide].Data[XFileCount] = 0 then
      lFHCompareRight->Caption = GLanguageHandler->Text[kFound] +
                                     " <b>" + IntToStr(CompareData[XRightSide].Data[XFolderCount]) + "</b> " +
                                     GLanguageHandler->Text[kFolders] + "."
    else if CompareData[XRightSide].Data[XFolderCount] = 0 then
      lFHCompareRight->Caption = GLanguageHandler->Text[kFound] +
                                     " <b>" + IntToStr(CompareData[XRightSide].Data[XFileCount]) + "</b> " +
                                     GLanguageHandler->Text[kFiles] +
                                     " (<b>" + Convert::ConvertToUsefulUnit(CompareData[XRightSide].Data[XFileSize]) + "</b>)."
	else
      lFHCompareRight->Caption = GLanguageHandler->Text[kFound] +
                                     " <b>" + IntToStr(CompareData[XRightSide].Data[XFileCount]) + "</b> " +
                                     GLanguageHandler->Text[kFiles] +
                                     " (<b>" + Convert::ConvertToUsefulUnit(CompareData[XRightSide].Data[XFileSize]) + "</b>) + <b>" +
                                     IntToStr(CompareData[XRightSide].Data[XFolderCount]) + "</b> " + GLanguageHandler->Text[kFolders] + ".";
  }
  else
    lFHCompareRight->Caption = GLanguageHandler->Text[kNoFilesFound];

  // == navigation logic ===================================================

  lCRPageNumber->Caption = IntToStr(lCRPagePrevious->Tag + 1);
  lCRShowing->Caption    = IntToStr(lCRPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults + 1) + rsEllipsis + IntToStr((lCRPagePrevious->Tag * GSettingsHandler->General.MaxSearchResults) + GSettingsHandler->General.MaxSearchResults);

  if lCRPagePrevious->Tag = 0 then
    lCRPagePrevious->Enabled = False
  else
    lCRPagePrevious->Enabled = True;

  if CompareData[XRightSide].Data[XFileCount] + CompareData[XRightSide].Data[XFolderCount] < GSettingsHandler->General.MaxSearchResults then {
    if lCRPagePrevious->Tag = 0 then
      lCRPagePrevious->Enabled = False
    else
      lCRPagePrevious->Enabled = True;

    lCRPageNext->Enabled = False;
  }
  else {
    lCRPagePrevious->Enabled = True;
    lCRPageNext->Enabled     = False;
  };

  // =======================================================================

  sgFHCompareRight.}Update;

  TGridUtility.SortTable(sgFHCompareRight, sgFHCompareLeft.SortSettings.Column);

  Screen.Cursor = crDefault;
} */


void __fastcall TFrameFolderHistory::Splitter1Moved(TObject *Sender)
{
/*  i = 530;

	if sgFHCompareLeft.IsHiddenColumn(2) then dec(i, 70);
	if sgFHCompareLeft.IsHiddenColumn(3) then dec(i, 70);
	if sgFHCompareLeft.IsHiddenColumn(4) then dec(i, 70);
	if sgFHCompareLeft.IsHiddenColumn(5) then dec(i, 70);
	if sgFHCompareLeft.IsHiddenColumn(6) then dec(i, 100);
	if sgFHCompareLeft.IsHiddenColumn(7) then dec(i, 55);

	sgFHCompareLeft->ColWidths[0]  = sgFHCompareLeft->Width - i;

	i = 530;

	if sgFHCompareRight.IsHiddenColumn(2) then dec(i, 70);
	if sgFHCompareRight.IsHiddenColumn(3) then dec(i, 70);
	if sgFHCompareRight.IsHiddenColumn(4) then dec(i, 70);
	if sgFHCompareRight.IsHiddenColumn(5) then dec(i, 70);
	if sgFHCompareRight.IsHiddenColumn(6) then dec(i, 100);
	if sgFHCompareRight.IsHiddenColumn(7) then dec(i, 55);

	sgFHCompareRight->ColWidths[0] = sgFHCompareRight->Width - i; */
}


void __fastcall TFrameFolderHistory::StringGrid2DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*procedure TFrameFolderHistory.sgFHCompareLeftDrawCell(Sender: TObject; ACol,
  ARow: Integer; Rect: TRect; State: TGridDrawState);
 var
  l,w : integer;

 {
  if (cbFHCompareColour.Checked) then {
	if ARow != 0 then {

	  TAdvStringGrid(Sender)->Canvas->Brush->Color = GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender)->Cells[FHschCategory, ARow])];
	  TAdvStringGrid(Sender)->Canvas->TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender)->Cells[ACol, ARow]);
	};
  }
  else if (sbFHCShowLeft->Tag = 1) then {
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


void __fastcall TFrameFolderHistory::StringGrid3DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*
	if (cbFHCompareColour.Checked) then {
		if ARow != 0 then {
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
#pragma }_region


#pragma region Tab_Search_CompareFolder
void __fastcall TFrameFolderHistory::ComboBox3KeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift)
{
	if (Key == VK_RETURN)
	{
		//sbFHCompareFolderSearchClick(Nil);
	}
}


void __fastcall TFrameFolderHistory::sbCompareFolderSearchClick(TObject *Sender)
{
/*  if not(GSettingsHandler->ProcessWindowsVisible)
	{
		if (bFHCompareFolderLeft->Tag != -1) and (bFHCompareFolderRight->Tag != -1)
		{
			if eFHCompareDriveFolder->Text != L""
			{
				FHCompareFolderBuildLeft(Nil);
				FHCompareFolderBuildRight(Nil);
			}
		}
		else
		{
			ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kPleaseSelectADate], XDialogTypeWarning);
		}
	}*/
}


void __fastcall TFrameFolderHistory::BitBtn5Click(TObject *Sender)
{
/*  puFHSelectDate->Tag = 5;

	puFHSelectDate->Popup(FGetLeftOffset + bFHCompareLeft.Left + 20,
							FGetTopOffset + Panel46.Height + Panel4.Height + Panel45.Height + 80);*/
}


void __fastcall TFrameFolderHistory::BitBtn6Click(TObject *Sender)
{
/*  puFHSelectDate->Tag = 6;

  puFHSelectDate->Popup(FGetLeftOffset + bFHCompareLeft.Left + Panel49.Left + 20,
					   FGetTopOffset + Panel46.Height + Panel4.Height + Panel45.Height + 80);*/
}


/*procedure TFrameFolderHistory.FHCompareFolderBuildLeft(Sender : TObject);
var
  SQL : string;

{
  if Pos("SELECT ", eFHCompareDriveFolder->Text) != 0 then {
    if GSettingsHandler->HistorySettings.SQLinSearch then {
      SQL = StringReplace(eFHCompareDriveFolder->Text, "*", " FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ", [rfReplaceAll]);

      SQL = StringReplace(SQL, "$x$", L""" + Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareFolderLeft->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text) + L""", [rfReplaceAll]);
    }
    else {
      SQL = L"";
      ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kDialog10], XDialogTypeWarning);
    };
  }
  else {
    SQL = TSearchUtility.XinorbisSearchAllToSQL(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareFolderLeft->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text, False)
  };

  if TableExists(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareFolderLeft->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text)) then {
    if SQL != L"" then {
      LastSQL[2] = SQL;

      GCompareFolderLeftThread = TCompareFolderLeftThread.Create(True);
      GCompareFolderLeftThread.SetData(SQL, eFHCompareDriveFolder->Text, lFHCDLeft, sgFHCDLeft);
      GCompareFolderLeftThread.OnTerminate = CompareFolderLeftThreadOnTerminate;
      GCompareFolderLeftThread.Priority    = tpTimeCritical;        //tpTimeCritical
      GCompareFolderLeftThread.Start;
    };
  }
  else {
    ShowXDialog(GLanguageHandler->Text[kWarning],
                GLanguageHandler->Text[kNoFileData] + ": " + bFHCompareLeft->Caption,
                XDialogTypeWarning);
  };
};


procedure TFrameFolderHistory.FHCompareFolderBuildRight(Sender : TObject);
 var
  SQL : string;

 {
  if Pos("SELECT ", eFHCompareDriveFolder->Text) != 0 then {
    if GSettingsHandler->HistorySettings.SQLinSearch then {
	  SQL = StringReplace(eFHCompareDriveFolder->Text, "*", " FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ", [rfReplaceAll]);

      SQL = StringReplace(SQL, "$x$", L""" + Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareFolderRight->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text) + L""", [rfReplaceAll]);
    }
    else {
      SQL = L"";

      ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kDialog10], XDialogTypeWarning);
    };
  }
  else {
    SQL = TSearchUtility.XinorbisSearchAllToSQL(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareFolderRight->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text, False)
  };

  if TableExists(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareFolderRight->Tag]), cbFHAvailablePath->Text, cbFHAvailableComputer->Text)) then {
    if SQL != L"" then {
      LastSQL[2] = SQL;

      GCompareFolderRightThread = TCompareFolderRightThread.Create(True);
	  GCompareFolderRightThread.SetData(SQL, eFHCompareDriveFolder->Text, lFHCDRight, sgFHCDRight);
      GCompareFolderRightThread.OnTerminate = CompareFolderRightThreadOnTerminate;
      GCompareFolderRightThread.Priority    = tpTimeCritical;        //tpTimeCritical
      GCompareFolderRightThread.Start;
    };
  }
  else {
    ShowXDialog(GLanguageHandler->Text[kWarning],
                GLanguageHandler->Text[kNoFileData] + ": " + bFHCompareLeft->Caption,
                XDialogTypeWarning);
  };
};               */


void __fastcall TFrameFolderHistory::SpeedButton32Click(TObject *Sender)
{
/*  sgrid : TAdvStringGrid;
  lFileName : string;

	lFileName = SaveDialogs::ExecuteReports(TUtility.GetDefaultFileName(".csv", GLanguageHandler->Text[kFileHistoryCompare] + "_" + GLanguageHandler->Text[kLeft]));

	if lFileName != L""
	{
		switch TSpeedbutton(Sender)->Tag)
		{
		CLeft  : sgrid = sgFHCDLeft;
		CRight : sgrid = sgFHCDRight;

		default:
			sgrid = sgFHCDLeft;
		}

		TGridUtility.SaveGrid(sgrid, lFileName);
	}*/
}


void __fastcall TFrameFolderHistory::Splitter2Moved(TObject *Sender)
{
/*	sgFHCDLeft->ColWidths[0]  = 10;
	sgFHCDLeft->ColWidths[2]  = 50;
	sgFHCDLeft->ColWidths[3]  = 52;
	sgFHCDLeft->ColWidths[4]  = 4;
	sgFHCDLeft->ColWidths[5]  = 60;
	sgFHCDLeft->ColWidths[6]  = 52;

	sgFHCDLeft->ColWidths[1]  = sgFHCDLeft->Width - (230 + 23);

	sgFHCDRight->ColWidths[0] = 10;
	sgFHCDRight->ColWidths[2] = 50;
	sgFHCDRight->ColWidths[3] = 52;
	sgFHCDRight->ColWidths[4] = 4;
	sgFHCDRight->ColWidths[5] = 60;
	sgFHCDRight->ColWidths[6] = 52;

	sgFHCDRight->ColWidths[1] = sgFHCDRight->Width - (230 + 23); */
}


void __fastcall TFrameFolderHistory::StringGrid5DrawCell(TObject *Sender, System::LongInt ACol,
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

#pragma }_region


#pragma region Tab_Search_CompareFolderTree
void __fastcall TFrameFolderHistory::sbCompareTreeClick(TObject *Sender)
{
/*	if not(GSettingsHandler->ProcessWindowsVisible)
	{
		if bFHCompareTreeLeft->Tag != -1
		{
			InitialiseTreeWithFolders(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareTreeLeft->Tag]),
								cbFHAvailablePath->Text, cbFHAvailableComputer->Text), tvFHTLeft);
		}

		if bFHCompareTreeRight->Tag != -1)
		{
			InitialiseTreeWithFolders(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareTreeRight->Tag]),
								cbFHAvailablePath->Text, cbFHAvailableComputer->Text), tvFHTRight);
		}

		sbFHCompareFolder2LeftSaveClick->Enabled  = True;
		sbFHCompareFolder2RightSaveClick->Enabled = True;
	}  */
}


void __fastcall TFrameFolderHistory::bCompareTreeLeftClick(TObject *Sender)
{
//  puFHSelectDate->Tag = 7;

//  puFHSelectDate->Popup(FGetLeftOffset + bFHCompareTreeLeft.Left + 20,
//					   FGetTopOffset + Panel46.Height + Panel48.Height + Panel55.Height + 80);
}


void __fastcall TFrameFolderHistory::bCompareTreeRightClick(TObject *Sender)
{
//  puFHSelectDate->Tag = 8;

//  puFHSelectDate->Popup(FGetLeftOffset + bFHCompareTreeRight.Left + Panel56.Left + 20,
//					   FGetTopOffset + Panel46.Height + Panel48.Height + Panel55.Height + 80);
}


void __fastcall TFrameFolderHistory::SpeedButton28Click(TObject *Sender)
{
/*  stree : THTMLTreeView;
  lFileName : string;

{
	lFileName = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + " (*.txt)|*.txt",
										".txt",
										TUtility.GetDefaultFileName(".txt", GLanguageHandler->Text[kFileHistoryCompare] + "_" + GLanguageHandler->Text[kLeft]));

	if lFileName != L""
	{
		switch TSpeedbutton(Sender)->Tag)
		{
		CLeft  : stree = tvFHTLeft;
		CRight : stree = tvFHTRight;
		default:
		  stree = tvFHTLeft;
		}
	};

	try
	{
	  stree.SaveToFile(lFileName);
	}
	except
	{
	  on e : exception do {
		TMSLogger.Error("Error saving tree L"" + e.ClassName + " / " + e.Message);
	  }
	}*/
}

void __fastcall TFrameFolderHistory::TreeView1Expanding(TObject *Sender, TTreeNode *Node,
		  bool &AllowExpansion)
{
/*  if PNodeData(Node.Data)^.FolderID != -2 then {
	PopulateTreeFolder(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareTreeLeft->Tag]),
					   cbFHAvailablePath->Text,
					   cbFHAvailableComputer->Text),
					   tvFHTLeft, node, L"", PNodeData(Node.Data)^.FolderID);

	PNodeData(Node.Data)^.FolderID = -2;
	}*/
}


void __fastcall TFrameFolderHistory::TreeView2Expanding(TObject *Sender, TTreeNode *Node,
		  bool &AllowExpansion)
{
/*  if PNodeData(Node.Data)^.FolderID != -2 then {
	PopulateTreeFolder(Convert::CreateTableName(Convert::DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory->Items[bFHCompareTreeRight->Tag]),
					   cbFHAvailablePath->Text,
					   cbFHAvailableComputer->Text),
					   tvFHTLeft, node, L"", PNodeData(Node.Data)^.FolderID);

	PNodeData(Node.Data)^.FolderID = -2;
  };*/
}
#pragma }_region


#pragma region Popup_Charts
void __fastcall TFrameFolderHistory::miCOSaveClick(TObject *Sender)
{
/*	std::wstring file_name = SaveDialogs::ExecuteImages(TUtility.GetDefaultFileName(".png", GLanguageHandler->Text[kChart]));

	if lFileName != L"")
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TChart* chart = (TChart*)pum->PopupComponent;

		mychart = TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu)->PopupComponent);

		ChartUtility::SaveChartToPNG(mychart, lFileName);
	}*/
}


void __fastcall TFrameFolderHistory::miCOCopyClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TChart* chart = (TChart*)pum->PopupComponent;

	ChartUtility::CopyChartToClipboard(chart);
}


void __fastcall TFrameFolderHistory::miCOAdvancedClick(TObject *Sender)
{ /*
  mychart : TChart;
  tceo    : TChartOptions;

  mychart = TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu)->PopupComponent);

  tceo = GSettingsHandler->Charts.Options;

  tceo.ChartType = ChartUtility::GetChartType(mychart);

  // ===========================================================================

  tceo = DoAdvancedChartOptions(tceo);

  // ===========================================================================

  if tceo.Result = 1 then {
	ChartUtility::SetAdvancedOptions(mychart, tceo);

	if Assigned(FChartsHaveChanged) then
	  FChartsHaveChanged;
  };                          */
}
#pragma }_region


#pragma region Popup_CompareSave
void __fastcall TFrameFolderHistory::puFHCompareSavePopup(TObject *Sender)
{
/*  status : boolean;

  function DoExist(sg : TAdvStringGrid): integer;
   var
	t : integer;

   {
	Result = 0;

	for t = 1 to sg->RowCount - 1 do {
	  if sg->Cells[FHschCategory, t] = "1" then inc(Result);
	}
  };

  function DontExist(sg : TAdvStringGrid): integer;
   var
	t : integer;

   {
	Result = 0;

	for t = 1 to sg->RowCount - 1 do {
	  if sg->Cells[FHschCategory, t] = "2" then inc(Result);
	}
  };

 {
  miFHCSSaveDo->Caption   = GLanguageHandler->Text[kSaveDoExist];
  miFHCSSaveDont->Caption = GLanguageHandler->Text[kSaveDontExist];

  switch TSpeedbutton(Tpopupmenu(Sender)->PopupComponent)->Tag of
	1 : {
		  if sbFHCShowLeft->Tag = 0 then
			status = False
		  else {
			status = True;

			miFHCSSaveDo->Caption   = GLanguageHandler->Text[kSaveDoExist] + " (" + IntToStr(DoExist(sgFHCompareLeft)) + ")";
			miFHCSSaveDont->Caption = GLanguageHandler->Text[kSaveDontExist] + " (" + IntToStr(DontExist(sgFHCompareLeft)) + ")";
		  };

          miFHCSSaveDo->Enabled   = status;
		  miFHCSSaveDont->Enabled = status;
		};
	2 : {
          if sbFHCShowRight->Tag = 0 then
			status = False
          else {
			status = True;

			miFHCSSaveDo->Caption   = GLanguageHandler->Text[kSaveDoExist] + " (" + IntToStr(DoExist(sgFHCompareRight)) + ")";
			miFHCSSaveDont->Caption = GLanguageHandler->Text[kSaveDontExist] + " (" + IntToStr(DontExist(sgFHCompareRight)) + ")";
          };

		  miFHCSSaveDo->Enabled     = status;
          miFHCSSaveDont->Enabled   = status;
		};
  };        */
}


void __fastcall TFrameFolderHistory::miFHCSSaveAllClick(TObject *Sender)
{    /*
	switch TSpeedbutton(Tpopupmenu(Sender)->PopupComponent)->Tag of
	1 : TGridUtility.SaveFHStringGridData(sgFHCompareLeft,  eFHCompareSearch->Text, TMenuItem(Sender)->Tag);
	2 : TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch->Text, TMenuItem(Sender)->Tag);
	}  */
}


void __fastcall TFrameFolderHistory::miFHCSSaveDoClick(TObject *Sender)
{       /*
	switch TSpeedbutton(Tpopupmenu(Sender)->PopupComponent)->Tag of
	1 : TGridUtility.SaveFHStringGridData(sgFHCompareLeft,  eFHCompareSearch->Text, TMenuItem(Sender)->Tag);
	2 : TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch->Text, TMenuItem(Sender)->Tag);
	} */
}


void __fastcall TFrameFolderHistory::miFHCSSaveDontClick(TObject *Sender)
{          /*
	switch TSpeedbutton(Tpopupmenu(Sender)->PopupComponent)->Tag)
	{
	1:
		TGridUtility.SaveFHStringGridData(sgFHCompareLeft,  eFHCompareSearch->Text, TMenuItem(Sender)->Tag);
	2:
		TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch->Text, TMenuItem(Sender)->Tag);
	} */
}
#pragma }_region


#pragma region Popup_GenericTable
void __fastcall TFrameFolderHistory::puGenericTablePopup(TObject *Sender)
{
/*  lTable : TAdvStringGrid;
  lStatus : boolean;

	if not(GSettingsHandler->ProcessWindowsVisible)
	{
		lTable = TAdvStringGrid(Tpopupmenu(Sender)->PopupComponent);

		if (lTable->Cells[0, 1] = L"") and (lTable->Cells[1, 1] = L"")
		{
			lStatus = False;
		}
		else
		{
			lStatus = True;
		}

		miGenericExport->Enabled        = lStatus;
		miGenericClipboard->Enabled     = lStatus;
		miGenericClipboardHTML->Enabled = lStatus;
	}*/
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
		GridUtility::SaveGrid(grid, file_name);
	}
}


void __fastcall TFrameFolderHistory::miGenericClipboardClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	/*  grid.CopyToClipBoard; */
}


void __fastcall TFrameFolderHistory::miGenericClipboardHTMLClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	/* grid.CopyToClipBoardAsHTML; */
}
#pragma }_region


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

				sbFHCompareSearchClick(sbFHCompareSearch);
			  };
		  4 : {
				eFHCompareDriveFolder->Text = ss;
			  };
		};
	  };
	};
  };
}     */
#pragma }_region


#pragma region Popup_SelectDate
void __fastcall TFrameFolderHistory::miSelectDateTimeClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();

/*	switch (pum->Tag)
	{
	case 1:
	{
		int lOldID = bFHISelect->Tag;

		  bFHISelect->Tag     = TMenuItem(Sender)->Tag;
		  bFHISelect->Caption = clbFolderHistory->Items[bFHISelect->Tag];

		  if bFHISelect->Tag != lOldID then
			sbFHBuildInformationTabsClick(nil);
		break;
	}
	2:
		bFHCompareLeft->Tag     = TMenuItem(Sender)->Tag;
		bFHCompareLeft->Caption = clbFolderHistory->Items[bFHCompareLeft->Tag];
		break;
	3:
		bFHCompareRight->Tag     = TMenuItem(Sender)->Tag;
		bFHCompareRight->Caption = clbFolderHistory->Items[bFHCompareRight->Tag];
		break;
//    4 :{
		break;
	5:
		bFHCompareFolderLeft->Tag     = TMenuItem(Sender)->Tag;
		bFHCompareFolderLeft->Caption = clbFolderHistory->Items[bFHCompareFolderLeft->Tag];
		break;
	6:
		bFHCompareFolderRight->Tag     = TMenuItem(Sender)->Tag;
		bFHCompareFolderRight->Caption = clbFolderHistory->Items[bFHCompareFolderRight->Tag];
		break;
	7:
		bFHCompareTreeLeft->Tag     = TMenuItem(Sender)->Tag;
		bFHCompareTreeLeft->Caption = clbFolderHistory->Items[bFHCompareTreeLeft->Tag];
		break;
	8:
		bFHCompareTreeRight->Tag     = TMenuItem(Sender)->Tag;
		bFHCompareTreeRight->Caption = clbFolderHistory->Items[bFHCompareTreeRight->Tag];
		break;
	}*/
}
#pragma }_region


#pragma region TimeLine
/*void TFrameFolderHistory::BuildTimeLine;
var
  t : integer;
  lRangeFrom, lRangeTo : TDateTime;

{
  if FolderHistory.Count != 0 then {
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
  };
};             */
#pragma }_region


#pragma region Reports
//par1, caption; par2, text FileName; par3, zsr report, par4; html report, par5; do charts, par6; xml reports
/*function TFrameFolderHistory.SaveReports(var TextOptions : TTextReportOptions; var CSVOptions  : TCSVReportOptions;
										 var HTMLOptions : THTMLReportOptions; var XinOptions  : TXinorbisReportOptions;
										 var XMLOptions  : TXMLReportOptions;  var TreeOptions : TTreeReportOptions): boolean;

var
  lReportOutput : TStringList;

{
  if Assigned(FSetStatusBarText) then
    FSetStatusBarText(GLanguageHandler->Text[kSavingReports] + " " + GLanguageHandler->Text[kPleaseWait]);

  Result = True;

  // =========================================================================
  // -- save out text version ------------------------------------------------
  // =========================================================================
  if TextOptions.FileName != L"" then {
    lReportOutput = TStringList.Create;

     GReportText.GenerateTextReport(dataFolderHistory, lReportOutput, TextOptions);

    FreeAndNil(lReportOutput);
  };

  // =========================================================================
  // -- save out xinorbis report ---------------------------------------------
  // =========================================================================
  if XinOptions.FileName != L"" then {
	GReportXinorbis.GenerateXinorbisReport(dataFolderHistory, XinOptions);
  };

  // =========================================================================
  // -- save out HTML version ------------------------------------------------
  // =========================================================================
  if HTMLOptions.FileName != L"" then {
    GReportHTML.GenerateHTMLReport(dataFolderHistory, HTMLOptions, L"");
  };

  // =========================================================================
  // -- save out XML version -------------------------------------------------
  // =========================================================================
  if XMLOptions.FileName != L"" then {
    lReportOutput = TStringList.Create;

    if XMLOptions.XMLData = CDataSummary then
      GReportXML.GenerateXMLOutput(dataFolderHistory, XMLOptions, lReportOutput)
    else
      GReportXML.GenerateXMLOutputFileList(XMLOptions.FileName, lReportOutput, dataFolderHistory, LayoutUnknown);

    FreeAndNil(lReportOutput);
  };

  // =========================================================================
  // -- save out CSV version -------------------------------------------------
  // =========================================================================
  if CSVOptions.FileName != L"" then {
    lReportOutput = TStringList.Create;

    GReportCSV.GenerateCSVReport(dataFolderHistory, lReportOutput, CSVOptions, LayoutUnknown);

    FreeAndNil(lReportOutput);
  };

  // =========================================================================
  // -- save out Tree version ------------------------------------------------
  // =========================================================================
  if TreeOptions.FileName != L"" then {
    if not(FIsFHUpdateThreadRunning) then {
      lReportOutput = TStringList.Create;

      GReportTree.GenerateTreeReport(dataFolderHistory, lReportOutput, TreeOptions);

      FreeAndNil(lReportOutput);
	};
  };

  // =========================================================================
  // -------------------------------------------------------------------------
  // =========================================================================

  if Assigned(FSetStatusBarText) then
    FSetStatusBarText("");
}2719*/
#pragma }_region
