//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <algorithm>

#include "XFormSettings.h"

#include "ConstantsData.h"
#include "ConstantsSettings.h"
#include "FileExtension.h"
#include "FileExtensionHandler.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

extern FileExtensionHandler* GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern SettingsHandler* GSettingsHandler;
extern SystemGlobal* GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSettings *FormSettings;
//---------------------------------------------------------------------------
__fastcall TFormSettings::TFormSettings(TComponent* Owner)
	: TForm(Owner)
{
}


int OpenSettings(int OpenTab)
{
	TFormSettings *FormSettings = new TFormSettings(Application);

	FormSettings->OpenTabAtStart = OpenTab;

	//olduserpath = GSystemGlobal.AppDataPath;

	// =======================================================================

	if (FormSettings->ShowModal() == mrOk)
	{
		FormSettings->UpdateSettingsOnSave();
	}

	delete FormSettings;

    return 0; // TO DO
}


void __fastcall TFormSettings::FormCreate(TObject *Sender)
{
	Init();

	BuildNavigationTable();
	SetLanguage();
}


void __fastcall TFormSettings::FormShow(TObject *Sender)
{
	switch (OpenTabAtStart)
	{
	case kPageGeneral:
		sbGeneralClick(sbGeneral);
		break;
	case kPageOptimisations:
		sbGeneralClick(sbOptimisations);
		break;
	case kPageTemp : sbGeneralClick(sbTempFiles);
		break;
	}

	OpenTabAtStart = -1;
}


void __fastcall TFormSettings::sbGeneralClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	switch (sb->Tag)
	{
	case kPagePostScan:
		pPostScan->BringToFront();
		break;
	case kPageOptimisations:
		pOptimisations->BringToFront();
		break;
	case kPagePaths:
		pPaths->BringToFront();
		break;
	case kPageGeneral:
		pGeneral->BringToFront();
		break;
	case kPageNavigate:
		pNavigate->BringToFront();
		break;
	case kPageUNUSED:
		{};
		break;
	case kPageFavourites:
		pFavourites->BringToFront();
		break;
	case kPageTemp:
		pTemp->BringToFront();
		break;
	}
}


void TFormSettings::UpdateSettingsOnSave()
{
//		GSettingsHandler->Optimisations.BuildDateTree       = not SliderStateToBoolean(tsODateTree->State);
//		GSettingsHandler->Optimisations.GetUserDetails      = not SliderStateToBoolean(tsOIgnoreOwner->State);
//		GSettingsHandler->Optimisations.GetTempFiles        = not SliderStateToBoolean(tsOIgnoreTemporary->State);

//		GSettingsHandler->Optimisations.JustInTimeDisplay   = not SliderStateToBoolean(tsOJIT->State);
//		GSettingsHandler->Optimisations.AddToDate           = SliderStateToBoolean(tsOFileNamesDateTree->State);
//		GSettingsHandler->Optimisations.AddToDateLimit      = SliderStateToBoolean(tsOFileNameDateTreeLimit->State);
		GSettingsHandler->Optimisations.AddToDateLimitCount = eShowFilesInTypeBoxLimit->Text.ToIntDef(5000);
		GSettingsHandler->Optimisations.ProgressUpdate      = cbProgressUpdate->ItemIndex;

		switch (cbDateFormat->ItemIndex)
		{
		case 0:
			GSettingsHandler->General.FormatDate = DateFormat::kSlashDDMMYYYY;
			break;
		case 1:
			GSettingsHandler->General.FormatDate = DateFormat::kSlashMMDDYYYY;
			break;
		case 2:
			GSettingsHandler->General.FormatDate = DateFormat::kSlashYYYYMMDD;
			break;
		case 3:
			GSettingsHandler->General.FormatDate = DateFormat::kHyphenDDMMYYYY;
			break;
		case 4:
			GSettingsHandler->General.FormatDate = DateFormat::kHyphenMMDDYYYY;
			break;
		}

		GSettingsHandler->General.MaxSearchResults    = eMaxSearchResults->Text.ToIntDef(10000);
		GSettingsHandler->General.CustomViewer        = eGCustomViewer->Text;

   		GSettingsHandler->Appearance.RowHeight        = eRowHeight->Text.ToIntDef(17);

//		GSettingsHandler->HistorySettings.Enabled     = SliderStateToBoolean(tsFolderHistory->State);
//		GSettingsHandler->HistorySettings.FullLogging = SliderStateToBoolean(tsLogEnable.State);
//		GSettingsHandler->HistorySettings.SQLinSearch = SliderStateToBoolean(tsAllowSQLInSearch.State);

//		GSettingsHandler->General.SaveLog             = SliderStateToBoolean(tsLogging->State);

//		GSettingsHandler->General.Autocheckupdate = SliderStateToBoolean(tsAutoCheckUpdates->State);

		// =====================================================================

		if (rbPSDoNothing->Checked)
		{
			GSettingsHandler->General.PostScanMode = kPostScanNothing;
		}
		else if (rbPSSummary->Checked)
		{
			GSettingsHandler->General.PostScanMode = kPostScanSummary;
		}
		else if (rbPSInformationPage->Checked)
		{
			GSettingsHandler->General.PostScanMode = kPostScanInformation;
		}
		else if (rbPSFolderStructure->Checked)
		{
			GSettingsHandler->General.PostScanMode = kPostScanStructure;
		}

		GSettingsHandler->General.PostScanIPPage = cbIPPostScan->ItemIndex;

		// ---------------------------------------------------------------------

		for (int t = GFileExtensionHandler->Extensions.size(); t >= 0; t++)
		{
			if (GFileExtensionHandler->Extensions[t]->Category == 0)
			{
//				GFileExtensionHandler->Extensions.r; delete t
			}
		}

		for (int t = 0; t < lbTemp->Items->Count; t++)
		{
			FileExtension *tfx = new FileExtension(lbTemp->Items->Strings[t].c_str(), 0);

			GFileExtensionHandler->Extensions.push_back(tfx);
		}

		// ---------------------------------------------------------------------

		for (int t = 0; t < kQuickFolderCount; t++)
		{
			GSettingsHandler->QuickFolders[t] = L"";
		}

		for (int t = 0; t < lbQuickFolders->Count; t++)
		{
			GSettingsHandler->QuickFolders[t] = lbQuickFolders->Items->Strings[t];
		}

		for (int t = 0; t < 6; t++)
		{
			GSettingsHandler->Appearance.BarColours[t] = bargraphs[t]->Brush->Color;
		}

		//FileExtensionsObject.SaveFileExtensionLists(XSettings.CustomSettings.SettingsSaveLocation);

		//SaveUsersPath();
}


#pragma region Setup
void TFormSettings::Init()
{
	//miFSH1->Caption       = TXWindows.GetSpecialFolder(5);
//	miFSH2->Caption       = TXWindows.GetSpecialFolder(6);
//	miFSH3->Caption       = TXWindows.GetSpecialFolder(7); TO DO
//	miFSH4->Caption       = TXWindows.GetSpecialFolder(8);
//	miFSH5->Caption       = TXWindows.GetSpecialFolder(9);

	cbDateFormat->Items->Add((GLanguageHandler->Dates[kDateDD] + L"/" + GLanguageHandler->Dates[kDateMM] + L"/" + GLanguageHandler->Dates[kDateYYYY]).c_str());
	cbDateFormat->Items->Add((GLanguageHandler->Dates[kDateMM] + L"/" + GLanguageHandler->Dates[kDateDD] + L"/" + GLanguageHandler->Dates[kDateYYYY]).c_str());
	cbDateFormat->Items->Add((GLanguageHandler->Dates[kDateYYYY] + L"/" + GLanguageHandler->Dates[kDateMM] + L"/" + GLanguageHandler->Dates[kDateDD]).c_str());
	cbDateFormat->Items->Add((GLanguageHandler->Dates[kDateDD] + L"-" + GLanguageHandler->Dates[kDateMM] + L"-" + GLanguageHandler->Dates[kDateYYYY]).c_str());
	cbDateFormat->Items->Add((GLanguageHandler->Dates[kDateMM] + L"-" + GLanguageHandler->Dates[kDateDD] + L"-" + GLanguageHandler->Dates[kDateYYYY]).c_str());

	bargraphs[0] = sNL1;
	bargraphs[1] = sNL2;
	bargraphs[2] = sNL3;
	bargraphs[3] = sNL4;
	bargraphs[4] = sNL5;
	bargraphs[5] = sNL6;

	for (int t = 0; t < 6; t++)
	{
		bargraphs[t]->Brush->Color = TColor(GSettingsHandler->Appearance.BarColours[t]);
	}

	// let's setup the gui

	tsODateTree->State            = BooleanToSliderState(!GSettingsHandler->Optimisations.BuildDateTree);
	tsOIgnoreOwner->State           = BooleanToSliderState(!GSettingsHandler->Optimisations.GetUserDetails);
	tsOIgnoreTemporary->State             = BooleanToSliderState(!GSettingsHandler->Optimisations.GetTempFiles);
	tsOJIT->State                     = BooleanToSliderState(!GSettingsHandler->Optimisations.JustInTimeDisplay);
	tsOFileNamesDateTree->State        = BooleanToSliderState(GSettingsHandler->Optimisations.AddToDate);
   //	cbShowFilesInTypeBoxStateChanged(cbShowFilesInTypeBox, cbShowFilesInTypeBox.State, 0);
	tsOFileNameDateTreeLimit->State   = BooleanToSliderState(GSettingsHandler->Optimisations.AddToDateLimit);
	eShowFilesInTypeBoxLimit->Text     = GSettingsHandler->Optimisations.AddToDateLimitCount;
	cbProgressUpdate->ItemIndex        = GSettingsHandler->Optimisations.ProgressUpdate;

	eXinorbisFolder->Text              = GSystemGlobal->AppDataPath.c_str();
	eGCustomViewer->Text               = GSettingsHandler->General.CustomViewer.c_str();

   //	cbFHEnable.State                  = BooleanToSliderState(GSettingsHandler.HistorySettings.Enabled);
	//cbFHLogEnable.State               = BooleanToSliderState(GSettingsHandler.HistorySettings.FullLogging);
	//cbAllowSQLInSearch.State          = BooleanToSliderState(GSettingsHandler.HistorySettings.SQLinSearch);
   //	cbFHEnableStateChanged(cbFHEnable, cbFHEnable->State, 0);

   //	cbSaveLog.State                   = BooleanToSliderState(GSettingsHandler->General.SaveLog);

	switch (GSettingsHandler->General.FormatDate)
	{
	case DateFormat::kSlashDDMMYYYY:
		cbDateFormat->ItemIndex = 0;
		break;
	case DateFormat::kSlashMMDDYYYY:
		cbDateFormat->ItemIndex = 1;
		break;
	case DateFormat::kSlashYYYYMMDD:
		cbDateFormat->ItemIndex = 2;
		break;
	case DateFormat::kHyphenDDMMYYYY:
		cbDateFormat->ItemIndex = 3;
		break;
	case DateFormat::kHyphenMMDDYYYY:
		cbDateFormat->ItemIndex = 4;
		break;
	}

	eRowHeight->Text                   = GSettingsHandler->Appearance.RowHeight;
	eMaxSearchResults->Text            = GSettingsHandler->General.MaxSearchResults;

	tsAutoCheckUpdates->State          = BooleanToSliderState(GSettingsHandler->General.AutoCheckUpdate);

	  // =======================================================================

	switch (GSettingsHandler->General.PostScanMode)
	{
	case kPostScanNothing:
		rbPSDoNothing->Checked = true;
		break;
	case kPostScanSummary:
		rbPSSummary->Checked = true;
		break;
	case kPostScanInformation:
		rbPSInformationPage->Checked = true;
		break;
	case kPostScanStructure:
		rbPSFolderStructure->Checked = true;
		break;
	}

	cbIPPostScan->ItemIndex = GSettingsHandler->General.PostScanIPPage;

	// update temporary file type list
	for (int t = 0; t < GFileExtensionHandler->Extensions.size(); t++)
	{
		FileExtension *tfx = GFileExtensionHandler->Extensions[t];

		if (tfx->Category == 0)
		{
			if (lbTemp->Items->IndexOf(tfx->Name.c_str()) == -1)
			{
				lbTemp->Items->Add(tfx->Name.c_str());
			}
		}
	}

	for (int t = 0; t < kQuickFolderCount; t++)
	{
		if (GSettingsHandler->QuickFolders[t] != L"")
		{
			lbQuickFolders->Items->Add(GSettingsHandler->QuickFolders[t].c_str());
		}
	}
}


void TFormSettings::BuildNavigationTable()
{
//	sgNavigationSide->HiHideColumn(8);

	for (int t = 1; t < 11; t++)
	{
		sgNavigationSide->Cells[0][t] = Things[t - 1].c_str();

//		sgNavigationSide->Cells[8][t] = IntToStr(round((t * 10) / 2));
	}

	sgNavigationSide->ColWidths[1] = 10;
	sgNavigationSide->ColWidths[3] = 10;
	sgNavigationSide->ColWidths[5] = 10;
	sgNavigationSide->ColWidths[7] = 10;

	sgNavigationSide->ColWidths[2] = 50;
	sgNavigationSide->ColWidths[4] = 50;
	sgNavigationSide->ColWidths[6] = 50;

	sgNavigationSide->ColWidths[0] = sgNavigationSide->Width - (150 + 40) - 5;
}


void TFormSettings::SetLanguage()
{
	Caption = GLanguageHandler->Text[kSettings].c_str();

	// ===========================================================================

	sbGeneral->Caption          = GLanguageHandler->Text[kGeneral].c_str();
	sbPostScan->Caption         = GLanguageHandler->Text[kPostScan].c_str();
	sbOptimisations->Caption    = GLanguageHandler->Text[kOptimisations].c_str();
	sbPaths->Caption            = GLanguageHandler->Text[kPaths].c_str();

	sbAppearance->Caption       = GLanguageHandler->Text[kAppearance].c_str();
	sbFavourites->Caption       = GLanguageHandler->Text[kFavourite].c_str();
	sbTempFiles->Caption        = GLanguageHandler->Text[kTempFiles].c_str();

	lGeneral->Caption           = GLanguageHandler->Text[kGeneral].c_str();
	lPostScan->Caption          = GLanguageHandler->Text[kPostScan].c_str();
	lOptimisations->Caption     = GLanguageHandler->Text[kOptimisations].c_str();
	lPaths->Caption             = GLanguageHandler->Text[kPaths].c_str();
	lTemp->Caption              = GLanguageHandler->Text[kTempFiles].c_str();
	lFavourites->Caption        = GLanguageHandler->Text[kFavourite].c_str();
	lNavigate->Caption          = GLanguageHandler->Text[kAppearance].c_str();

	rbPSSummary->Caption        = GLanguageHandler->Text[kSummary].c_str();
	rbPSInformationPage->Caption = GLanguageHandler->Text[kInformationPages].c_str();
	rbPSFolderStructure->Caption = GLanguageHandler->Text[kFolderStructure].c_str();

	// ===========================================================================

	bHelp->Caption              = GLanguageHandler->Text[kHelp].c_str();
	bSave->Caption              = GLanguageHandler->Text[kSave].c_str();
	bCancel->Caption            = GLanguageHandler->Text[kCancel].c_str();

	lQuickFolders->Caption      = GLanguageHandler->Text[kFavourites].c_str();

	// ===========================================================================

	tDataFolder->Caption   = GLanguageHandler->Text[kXinorbisDataFolder].c_str();
	//  tPostScan->Caption     =LanguageStrings[61];

	// to do rbNPostScan->Caption   = GLanguageHandler->Text[kDoNothing].c_str(); to do

	for (int t = 0; t < 12; t++)
	{
		cbIPPostScan->Items->Add(GLanguageHandler->LanguageTabs[t].c_str());
	}

	lAutoCheckUpdates->Caption = GLanguageHandler->Text[kAutomaticallyCheckForUpdates].c_str();
	lFHEnable->Caption         = GLanguageHandler->Text[kEnableFolderHistory].c_str();
	lFHLogEnable->Caption      = GLanguageHandler->Text[kEnableFullFileLogging].c_str();
	lAllowSQLInSearch->Caption = GLanguageHandler->Text[kAllowSQLStatementsWhenSearching].c_str();

	lSaveLog->Caption          = GLanguageHandler->Text[kSaveLog].c_str();

	lTableRowHeight->Caption          = GLanguageHandler->Text[kTableRowHeight].c_str();
	lRowHeight->Caption               = (L"(" + GLanguageHandler->Text[kDefault] + L": 17)").c_str();
	lDateFormat->Caption              = GLanguageHandler->Text[kDateFormat].c_str();
	lMaxSearchResults->Caption        = GLanguageHandler->Text[kSearchResultLimit].c_str();
	lDefaultMaxSearchResults->Caption = (L"(" + GLanguageHandler->Text[kDefault] + L": 20000)").c_str();

	lOBuildDateTree->Caption          = GLanguageHandler->Text[kDontBuildDateTree].c_str();
	lOGetUserDetails->Caption         = GLanguageHandler->Text[kDontGetFileOwnerDetails].c_str();
	lOGetTempFiles->Caption           = GLanguageHandler->Text[kDontProcessTempFiles].c_str();
	lOJustInTime->Caption             = GLanguageHandler->Text[kJIT].c_str();
	lShowFilesInTypeBox->Caption      = GLanguageHandler->Text[kAddFileNamesToDateTab].c_str();
	lShowFilesInTypeBoxLimit->Caption = (GLanguageHandler->Text[kWhenFewer] + L":").c_str();
	eShowFilesInTypeBoxLimit->Left    = lShowFilesInTypeBoxLimit->Left + lShowFilesInTypeBoxLimit->Width + 6;
	lProgressUpdate->Caption          = GLanguageHandler->Text[kScanningProgress].c_str();

	cbProgressUpdate->Items->Add(GLanguageHandler->Text[kUpdateProgress1].c_str());
	cbProgressUpdate->Items->Add(GLanguageHandler->Text[kUpdateProgress2].c_str());
	cbProgressUpdate->Items->Add(GLanguageHandler->Text[kUpdateProgress3].c_str());
	cbProgressUpdate->Items->Add(GLanguageHandler->Text[kUpdateProgress4].c_str());
	cbProgressUpdate->Items->Add(GLanguageHandler->Text[kUpdateProgress5].c_str());
	cbProgressUpdate->Items->Add(GLanguageHandler->Text[kUpdateProgress6].c_str());

	tCustomViewer->Caption     = GLanguageHandler->Text[kCustomViewer].c_str();

	bGResetGraphGradients->Caption = GLanguageHandler->Text[kResetChartGradientColours].c_str();
	bClearScanHistory->Caption     = GLanguageHandler->Text[kClearScanHistory].c_str();
	bClearAllSettings->Caption     = GLanguageHandler->Text[kRestoreToDefaults].c_str();

	// ===========================================================================

	lTypesOfTempFile->Caption = GLanguageHandler->Text[kTypesOfTempFiles].c_str();

	// == navigation =============================================================

	lNLeftSideProgress->Caption  = GLanguageHandler->Text[kLeftSideProgressBar].c_str();
	lNRightSideProgress->Caption = GLanguageHandler->Text[kRightSideProgressBar].c_str();
	lNAllOtherTables->Caption    = GLanguageHandler->Text[kAllOtherTables].c_str();
}


#pragma region PopupMenus
void __fastcall TFormSettings::miFSH1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	lbQuickFolders->Items->Add(mi->Caption);
}
#pragma end_region


#pragma region Page_General
void __fastcall TFormSettings::bGResetGraphGradientsClick(TObject *Sender)
{
//  if MessageDlg(GLanguageHandler->Text[kResetChartGradientColours] + #13#13 + GLanguageHandler->Text[kAreYouSureContinue], mtWarning, [mbYes, mbNo], 0) = mrYes then begin
//	XSettings.ResetChartGradients; TO DO
//  end;
}


void __fastcall TFormSettings::bClearScanHistoryClick(TObject *Sender)
{
/*  if MessageDlg(GLanguageHandler->Text[kClearScanHistoryPrompt], mtWarning, [mbYes, mbNo], 0) = mrYes then begin
	ScanHistory.Clear;

	Reg = TRegistry.Create(KEY_WRITE);

	try
	  Reg.RootKey = HKEY_CURRENT_USER;
	  Reg.DeleteKey('\software\' + XinorbisRegistryKey + L"\SinglePaths');
	finally
	 Reg.Free;
	end;
  end; TO DO DO DO */
}


void __fastcall TFormSettings::bClearAllSettingsClick(TObject *Sender)
{
//	if MessageDlg(GLanguageHandler->Text[kRestoreToDefaults] + L"?' + #13#13 + GLanguageHandler->Text[kAreYouSureContinue], mtWarning, [mbYesNo], 0) == mrYes)
//	{
//		XSettings.SetAllToDefault; TO DO
//	}
}
#pragma end_region


#pragma region Page_PostScan
#pragma end_region


#pragma region Page_Optimisations
#pragma end_region


#pragma region Page_Paths
void __fastcall TFormSettings::sbXinorbisFolderClick(TObject *Sender)
{
	std::wstring folder = L""; // TO DO WindowsUtility::BrowseForFolder(Handle);

	if (!folder.empty())
	{
		eXinorbisFolder->Text = folder.c_str();
	}
}


void __fastcall TFormSettings::sbGCustomViewerClick(TObject *Sender)
{
	std::wstring file_name = LoadDialogs::ExecuteExe(L"");

	if (!file_name.empty())
	{
		eGCustomViewer->Text = file_name.c_str();
	}
}
#pragma end_region


#pragma region Page_Appearance
void __fastcall TFormSettings::sNL2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	TShape* shape = (TShape*)Sender;

	cdMain->Color = bargraphs[shape->Tag]->Brush->Color;

	if (cdMain->Execute())
	{
		bargraphs[shape->Tag]->Brush->Color = cdMain->Color;

		sgNavigationSide->Refresh();
	}
}


void __fastcall TFormSettings::sgNavigationSideDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	if (ARow > 0)
	{
		switch (ACol)
		{
		case 2:
		{
			sgNavigationSide->Canvas->Brush->Color = sNL1->Brush->Color;
			sgNavigationSide->Canvas->Rectangle(Rect);

			//if (sgNavigationSide->Cells[8, ARow] <> '0' then begin
			TRect rect;
			rect.Top    = Rect.Top + 1;
			rect.Bottom = Rect.Bottom - 1;
			rect.Left   = Rect.Left + 1;
			rect.Right  = Rect.Left + ARow * 5;

			sgNavigationSide->Canvas->Brush->Color = sNL2->Brush->Color;
			sgNavigationSide->Canvas->FillRect(rect);
			//end;

			break;
		}
/*		  4 : begin
				TAdvStringGrid(Sender).Canvas.Brush.Color := sNL3.Brush.Color;
				TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

				if TAdvStringGrid(Sender).Cells[8, ARow] <> '0' then begin
				  zRect.Top    := Rect.Top + 1;
				  zRect.Bottom := Rect.Bottom - 1;
				  zRect.Left   := Rect.Left + 1;
				  zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[8, ARow]);

				  TAdvStringGrid(Sender).Canvas.Brush.Color := sNL4.Brush.Color;
				  TAdvStringGrid(Sender).Canvas.FillRect(zRect);
				end;
			  end;
		  6 : begin
				TAdvStringGrid(Sender).Canvas.Brush.Color := sNL5.Brush.Color;
				TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

				if TAdvStringGrid(Sender).Cells[8, ARow] <> '0' then begin
				  zRect.Top    := Rect.Top + 1;
				  zRect.Bottom := Rect.Bottom - 1;
				  zRect.Left   := Rect.Left + 1;
				  zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[8, ARow]);

				  TAdvStringGrid(Sender).Canvas.Brush.Color := sNL6.Brush.Color;
				  TAdvStringGrid(Sender).Canvas.FillRect(zRect);
				end;
			  end;           */
		}
	}
}
#pragma end_region


#pragma region Page_Favourites
void __fastcall TFormSettings::SpeedButton14Click(TObject *Sender)
{
	if (lbQuickFolders->ItemIndex > 0)
	{
		int i = lbQuickFolders->ItemIndex;

		lbQuickFolders->Items->Move(i, i - 1);

		lbQuickFolders->ItemIndex = i - 1;
	}
}


void __fastcall TFormSettings::SpeedButton13Click(TObject *Sender)
{
	if (lbQuickFolders->ItemIndex < lbQuickFolders->Count - 1)
	{
		int i = lbQuickFolders->ItemIndex;

		lbQuickFolders->Items->Move(i, i + 1);

		lbQuickFolders->ItemIndex = i + 1;
	}
}


void __fastcall TFormSettings::SpeedButton11Click(TObject *Sender)
{
	if (lbQuickFolders->Count < kQuickFolderCount)
	{
		std::wstring folder = L"";// TO DO TXWindows.BrowseForFolder(Handle);

		if (!folder.empty())
		{
			std::wstring folderuc = folder;

			std::transform(folderuc.begin(), folderuc.end(), folderuc.begin(), ::toupper);

			bool found = false;

			std::wstring favourite = L"";

			for (int t = 0; t < 20; t++)
			{
				std::wstring favourite = GSettingsHandler->QuickFolders[t];
				std::transform(favourite.begin(), favourite.end(), favourite.begin(), ::toupper);

				if (favourite == folderuc)
				{
					found = true;
				}
			}

			if (!found)
			{
				if (!folderuc.empty())
				{
					 lbQuickFolders->Items->Add(folder.c_str());
				}
			}
			else
			{
// TO DO				ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kQuickFoldersAlreadyExists], XDialogTypeWarning);
			}
		}
	}
}


void __fastcall TFormSettings::SpeedButton12Click(TObject *Sender)
{
	lbQuickFolders->DeleteSelected();
}


void __fastcall TFormSettings::sbQFExploreClick(TObject *Sender)
{
	if (lbQuickFolders->ItemIndex != -1)
	{
		std::wstring folder = lbQuickFolders->Items->Strings[lbQuickFolders->ItemIndex].c_str();

		WindowsUtility::ExecuteFile(L"\"" + folder + L"\"", L"");
	}
}
#pragma end_region


#pragma region Page_Temp
void __fastcall TFormSettings::sbTempClick(TObject *Sender)
{
	if (lbTemp->Items->IndexOf(eAddTemp->Text) == -1)
	{
		lbTemp->Items->Add(eAddTemp->Text);
	}

	eAddTemp->Text = L"";
}
//---------------------------------------------------------------------------

void __fastcall TFormSettings::eDeleteTempClick(TObject *Sender)
{
	lbTemp->DeleteSelected();
}


void __fastcall TFormSettings::eAddTempChange(TObject *Sender)
{
	if (eAddTemp->Text == L"")
	{
		sbTemp->Enabled = false;
	}
	else
	{
		sbTemp->Enabled = true;
	}
}


void __fastcall TFormSettings::eAddTempKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == VK_RETURN)
	{
		sbTempClick(NULL);
	}
}


void __fastcall TFormSettings::lbTempClick(TObject *Sender)
{
	if (lbTemp->SelCount == 0)
	{
		eDeleteTemp->Enabled = false;
	}
	else
	{
		eDeleteTemp->Enabled = true;
	}
}
#pragma end_region


#pragma region Bottom_Buttons
void __fastcall TFormSettings::bHelpClick(TObject *Sender)
{
		 // to do THelp.OpenHelpPage('prefs.htm');
}

#pragma end_region


bool TFormSettings::SliderStateToBoolean(TToggleSwitchState state)
{
	if (state == TToggleSwitchState::tssOff)
	{
		return false;
	}

	return true;
}


TToggleSwitchState TFormSettings::BooleanToSliderState(bool state)
{
	if (state)
	{
		return TToggleSwitchState::tssOn;
	}

	return TToggleSwitchState::tssOff;
}


/*



procedure TfrmFileTypes.SaveUsersPath;
 var
  config : TIniFile;

 begin
  if olduserpath != eXinorbisFolder.Text then begin
    config = TINIFile.Create(GSystemGlobal.ExePath + L"custom.ini');

	try
	  config.WriteString('Main', 'DataPath', eXinorbisFolder.Text);
	finally
	  config.Free;
	end;

	ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kXinorbisDataFolderChanges], XDialogTypeWarning);
  end;
end;

procedure TfrmFileTypes.cbShowFilesInTypeBoxStateChanged(Sender: TObject;
  State: TAdvSmoothSliderState; Value: Double);
begin
  cbShowFilesInTypeBoxLimit.Enabled = SliderStateToBoolean(cbShowFilesInTypeBox.State);
  eShowFilesInTypeBoxLimit.Enabled  = SliderStateToBoolean(cbShowFilesInTypeBox.State);
end;

procedure TfrmFileTypes.cbFHEnableStateChanged(Sender: TObject;
  State: TAdvSmoothSliderState; Value: Double);
begin
  cbFHLogEnable.Enabled      = SliderStateToBoolean(State);
  cbAllowSQLInSearch.Enabled = SliderStateToBoolean(State);
end;


*/
