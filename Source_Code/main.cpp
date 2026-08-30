/*
  ZeemSpace - Hard Disk analyser

	  ** xinorbis - Renamed February 28th 2002 **

      (c) Paul Alan Freshney 2002-2003
      (c) Aardvark Digital 2002-2003

  Delphi 7 convert, September 10th 2003

  Original Started: January 6th 2002

  Version2

		   Started: September 10th 2003

  Version3+

		   Started: February 27th 2005

  Version 6.1

		   Started: March 6th 2014

  Version 6.2 (Unicode vesion)

		   Started: September 25th 2014

  Version 7.0

		   Started: December 16th 2015

  Migration to Delphi 2007, December 7th 2012

  Version 8.0

  Migration to Delphi 10.1 Berlin

		   Started: October 8th 2016

  Version 8.3.0

		   Started: January 6th 2020

  Version 10.0.0 (C++ Builder rewrite)

		   Started: July 4th 2026
*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>

#include "ConstantsGui.h"
#include "ConstantsLanguage.h"
#include "ConstantsSettings.h"
#include "ConstantsSystem.h"
#include "ExecutionParameters.h"
#include "FileExtensionHandler.h"
#include "Formatting.h"
#include "GuiUtility.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "Log.h"
#include "main.h"
#include "ReportHandler.h"
#include "ReportSummary.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "ScanHistoryHandler.h"
#include "SettingsHandler.h"
#include "SplashHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"
#include "XZip.h"

#include "XFormAbout.h"
#include "XFormCategoryColours.h"
#include "XFormCheckVersion.h"
#include "XFormDebug.h"
#include "XFormFileAssociations.h"
#include "XFormFileAges.h"
#include "XFormFileSpread.h"
#include "XFormLog.h"
#include "XFormMoreDetail.h"
#include "XFormQuickMenuBuilder.h"
#include "XFormReference.h"
#include "XFormSearchWizard.h"
#include "XFormSettings.h"
#include "XFormXinorbisDialog.h"

#include "XFormEditCSVReport.h"
#include "XFormEditHTMLReport.h"
#include "XFormEditTextReport.h"
#include "XFormEditTreeReport.h"
#include "XFormEditXmlReport.h"

#include "XFormReportOptions.h"

#include "XFrameExploder.h"
#include "XFrameMap.h"
#include "XFrameProperties.h"
#include "XFrameSearch.h"
#include "XFrameSelect.h"
#include "XFrameStructure.h"
#include "XFrameSummary.h"

extern FileExtensionHandler *GFileExtensionHandler;
extern LanguageHandler *GLanguageHandler;
extern Log *GLog;
extern ReportHandler *GReportHandler;
extern ScanEngine *GScanEngine;
extern ScanHistoryHandler *GScanHistoryHandler;
extern SettingsHandler *GSettingsHandler;
extern SplashHandler *GSplashHandler;
extern SystemGlobal *GSystemGlobal;
extern XZip *GXZip;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TFormMain::FormCreate(TObject *Sender)
{
	GSystemGlobal = new SystemGlobal();

	ConfigureObjects();

	CreateFrames();

	SetLanguageText();
	SetMenuLanguageText();
}


void __fastcall TFormMain::FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
		  int &MaxWidth, int &MaxHeight)
{
	MinWidth = 800;
}


void __fastcall TFormMain::FormResize(TObject *Sender)
{
//
}


void __fastcall TFormMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	CanClose = true;
}


void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	FrameSelect->SaveSettings();

	FrameProperties->SaveSettings();

	// == folder history =======================================================

	//FrameFolderHistory.SaveSettings;

//	if Assigned(FrameReports[dataFolderHistory])
//	{
//		FrameReports[dataFolderHistory].SaveSettings;
//  }

	//	FolderHistoryAvailable.Clear;

	// =========================================================================

	GSettingsHandler->Save(Top, Left, Width, Height, GLanguageHandler->GetLanguageSymbol());

	if (GSettingsHandler->Database.UseODBC)
	{
//		CloseODBC; to do
	}

	Action = caFree;
}


void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
    GSystemGlobal->FreeObjects();
}


#pragma region Application_Init
void TFormMain::CreateFrames()
{
	FrameSelect = new TFrameSelect(this);
	FrameSelect->Parent = pMainCanvas;
	FrameSelect->Align = alClient;
	FrameSelect->OnNewScan = std::bind(OnNewScan, std::placeholders::_1);
//  FrameSelect.OnChangeFHPath   := RequestNewFHPath;
	FrameSelect->OnScanWithMultiple = std::bind(RequestNewCombineScan, std::placeholders::_1);

	FrameSummary = new TFrameSummary(this);
	FrameSummary->Parent = pMainCanvas;
	FrameSummary->Align = alClient;
	FrameSummary->Visible = false;
//	FrameSummary[aDataIndex].OnReportsChange    := OnReportsChange;
//	FrameSummary[aDataIndex].OnSetStatusBarText := OnStatusBarChange;

	FrameExploder = new TFrameExploder(this);
	FrameExploder->Parent = pMainCanvas;
	FrameExploder->Align = alClient;
	FrameExploder->Visible = false;

	FrameMap = new TFrameMap(this);
	FrameMap->Parent = pMainCanvas;
	FrameMap->Align = alClient;
	FrameMap->Visible = false;

	FrameProperties = new TFrameProperties(this);
	FrameProperties->Parent = pMainCanvas;
	FrameProperties->Align = alClient;
	FrameProperties->Visible = false;
//  FrameProperties->IsFHUpdateThreadRunning = IsFolderHistoryRunning;
	FrameProperties->OnScanWithNewPath = std::bind(RequestNewScan, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	FrameProperties->OnNewSearch = std::bind(RequestNewSearch, std::placeholders::_1, std::placeholders::_2);
//  FrameProperties->OnNewSummary = RequestNewSummary;
//  FrameProperties->OnProcessWindowStatusChange = OnProcessWindowStatusChange;
//  FrameProperties->OnSetStatusBarText = OnStatusBarChange;
//  FrameProperties->OnSettingsTab = OnOpenSettingsTab;
//  FrameProperties->OnSetTutorialBarText = OnTutorialBarChange;

	FrameSearch = new TFrameSearch(this);
	FrameSearch->Parent = pMainCanvas;
	FrameSearch->Align = alClient;
	FrameSearch->Visible = false;
	FrameSearch->OnMenuChange = std::bind(OnMenuChange, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	FrameSearch->OnOpenSearchWizard = std::bind(OnOpenSearchWizard, std::placeholders::_1);

	FrameStructure = new TFrameStructure(this);
	FrameStructure->Parent = pMainCanvas;
	FrameStructure->Align = alClient;
	FrameStructure->Visible = false;

//	  FrameWebReports  := TFrameWebReports.Create(Self);
//  FrameWebReports.Parent  := Panel2;
//  FrameWebReports.Visible := False;

}


void TFormMain::CreateFolderHistoryFrame()
{ /*                                      FolderHistory
	FrameFolderHistory := TFrameFolderHistory.Create(Self);
	FrameFolderHistory.Parent  := Panel2;
	FrameFolderHistory.Visible := False;
	FrameFolderHistory.Init;
	FrameFolderHistory.GetLeftOffset                 := OnGetLeftOffset;
	FrameFolderHistory.GetTopOffset                  := OnGetTopOffset;
	FrameFolderHistory.IsFHUpdateThreadRunning       := IsFolderHistoryRunning;
	FrameFolderHistory.OnExtSetSidePanelDisplay      := OnExtSetSidePanelDisplay;
	FrameFolderHistory.OnOpenSearchWizard            := OnOpenSearchWizard;
	FrameFolderHistory.OnProcessWindowProgressChange := OnProcessWindowProgressChange;
	FrameFolderHistory.OnProcessWindowStatusChange   := OnProcessWindowStatusChange;
	FrameFolderHistory.OnSetStatusBarText            := OnStatusBarChange;
	FrameFolderHistory.OnSetTutorialBarText          := OnTutorialBarChange;
	FrameFolderHistory.OnResetDisplay                := OnResetDisplay;
	FrameFolderHistory.OnScanFromFolderHistory       := ScanFromFolderHistory;
	FrameFolderHistory.OnUpdateHistoryFinished       := OnUpdateHistoryFinished;
	FrameFolderHistory.OnChartsHaveChanged           := OnChartsHaveChanged; */
}


void TFormMain::FreeFrames()
{
}


void TFormMain::SetLanguageText()
{
	Caption = (L"xinorbis :: " + __XVersion + L" / " + __XDate).c_str();
	sbMain->SimpleText = (GLanguageHandler->Text[kWelcomeTo] + L" Xinorbis " + __XVersion + L" / " + __XDate + L". (c) Paul Alan Freshney 2002-" + Utility::CurrentYear()).c_str();

	// =========================================================================================

	// bottom toolbar
	sbNavigatePrevious->Hint = GLanguageHandler->Text[kHintM1];
	sbNavigateNext->Hint     = GLanguageHandler->Text[kHintM2];
	sbHome->Hint             = GLanguageHandler->Text[kHintM3];

	sbTogglePrivacy->Hint       = (GLanguageHandler->Text[kHintM4] + L" [" + GLanguageHandler->Text[kDisabled] + L"]").c_str();
	sbToggleFolderHistory->Hint = (GLanguageHandler->Text[kHintM5] + L" [" + GLanguageHandler->Text[kEnabled] + L"]").c_str();
	sbToggleVirtualFiles->Hint  = (GLanguageHandler->Text[kIgnoreVirtualFolders] + L" [" + GLanguageHandler->Text[kEnabled] + L"]").c_str();

	sbReportSummary->Hint  = GLanguageHandler->Text[kSummary].c_str();
	sbReportCSV->Hint      = GLanguageHandler->Text[kCSVReport].c_str();
	sbReportDate->Hint     = GLanguageHandler->Text[kDateReport].c_str();
	sbReportHTML->Hint     = GLanguageHandler->Text[kHTMLReport].c_str();
	sbReportJSON->Hint     = GLanguageHandler->Text[kJSONReport].c_str();
	sbReportText->Hint     = GLanguageHandler->Text[kTextReport].c_str();
	sbReportTree->Hint     = GLanguageHandler->Text[kTreeReport].c_str();
	sbReportXML->Hint      = GLanguageHandler->Text[kXMLReport].c_str();
	sbReportSettings->Hint = (GLanguageHandler->Text[kReport] + L" " + GLanguageHandler->Text[kSettings]).c_str();

	// data selection panel
	lDataTitle->Caption = GLanguageHandler->Text[kData].c_str();

	lWelcomeScan->Caption = GLanguageHandler->Text[kScanDriveFolder].c_str();
	lWelcomeFolderHistory->Caption = GLanguageHandler->Text[kFolderHistory].c_str();

	lDataSource->Caption = GLanguageHandler->Text[kDataSource].c_str();

	sbSourceLive->Caption = GLanguageHandler->Text[kScan].c_str();
	sbSourceFolderHistory->Caption = GLanguageHandler->Text[kFolderHistory].c_str();

	// View Panel
	lReportsTitle->Caption = GLanguageHandler->Text[kReports].c_str();

	lTaskID1->Caption = GLanguageHandler->Text[kSummary].c_str();
	lTaskID2->Caption = GLanguageHandler->Text[kFolderProperties].c_str();
	lTaskID3->Caption = GLanguageHandler->Text[kFolderStructure].c_str();
	lTaskID4->Caption = GLanguageHandler->Text[kSearch].c_str();
	lTaskID5->Caption = GLanguageHandler->Text[kFolderMap].c_str();

	lTaskID6->Caption = GLanguageHandler->Text[kDuplicatesFileName].c_str();
	lTaskID7->Caption = GLanguageHandler->Text[kDuplicatesFileSize].c_str();

	lTaskID8->Caption = GLanguageHandler->Text[kFolderExploder].c_str();

	lAdvID1->Caption = (GLanguageHandler->Text[kFileSizeSpread] + kEllipsis).c_str();
	lAdvID2->Caption = (GLanguageHandler->Text[kFolderDetail] + kEllipsis).c_str();
	lAdvID3->Caption = (GLanguageHandler->Text[kFileAge] + kEllipsis).c_str();
}


void TFormMain::SetMenuLanguageText()
{
	// == File Menu ============================================================================
	miFScan->Caption        = (GLanguageHandler->Text[kScan] + kEllipsis).c_str();
	miFSaveReports->Caption = (GLanguageHandler->Text[kSaveReports] + kEllipsis).c_str();
	miFExit->Caption        = (L"&" + GLanguageHandler->Text[kExit]).c_str();

	// == Edit =================================================================================
	miESettings->Caption             = (GLanguageHandler->Text[kSettings] + kEllipsis).c_str();
	miEReportOptions->Caption        = (GLanguageHandler->Text[kReportOptions] + kEllipsis).c_str();
	miEFileTypes->Caption            = (GLanguageHandler->Text[kFileTypes] + kEllipsis).c_str();
	miECustomiseQuickFolder->Caption = (GLanguageHandler->Text[kCustomiseQuickFolderMenu] + kEllipsis).c_str();

	// == Search Menu ==========================================================================
	miSSearch->Caption       = GLanguageHandler->Text[kSearch].c_str();
	miSWizard->Caption       = (GLanguageHandler->Text[kWizard] + kEllipsis).c_str();
	miSSearchSyntax->Caption = (GLanguageHandler->Text[kSearchSyntax] + kEllipsis).c_str();

	// == View Menu ============================================================================
	miVOpenLastReport->Caption            = GLanguageHandler->Text[kOpenLastReport].c_str();
	miVFolderProperties->Caption          = (GLanguageHandler->Text[kReportOptions] + kEllipsis).c_str();

	miTabTable->Caption                   = GLanguageHandler->Text[kCategories].c_str();
	miTabTree->Caption                    = GLanguageHandler->Text[kType].c_str();
	miTabOther->Caption                   = GLanguageHandler->Text[kExtensions].c_str();
	miTabFolders->Caption                 = GLanguageHandler->Text[kFolders].c_str();
	miTabMagnitude->Caption               = GLanguageHandler->Text[kMagnitude].c_str();
	miTabFileDates->Caption               = GLanguageHandler->Text[kDates].c_str();
	miTabHistory->Caption                 = GLanguageHandler->Text[kHistory].c_str();
	miTabTop101->Caption                  = GLanguageHandler->Text[kTop101].c_str();
	miTabNullFiles->Caption               = GLanguageHandler->Text[kNull].c_str();
	miTabUsers->Caption                   = GLanguageHandler->Text[kUsers].c_str();
	miTabTemp->Caption                    = GLanguageHandler->Text[kTemp].c_str();
	miTabNameLength->Caption              = GLanguageHandler->Text[kFileNameLength].c_str();

	miVCategoryColours->Caption           = (GLanguageHandler->Text[kCategoryColours] + kEllipsis).c_str();
	miVLogs->Caption                      = (GLanguageHandler->Text[kLogs] + kEllipsis).c_str();

	// == Reports ================================================================
	miRNew->Caption            = GLanguageHandler->Text[kNew].c_str();
	miCSVReport->Caption       = GLanguageHandler->Text[kCSVReport].c_str();
	miHTMLReport->Caption      = GLanguageHandler->Text[kHTMLReport].c_str();
	miTextReport->Caption      = GLanguageHandler->Text[kTextReport].c_str();
	miTreeReport->Caption      = GLanguageHandler->Text[kTreeReport].c_str();
	miXMLReport->Caption       = GLanguageHandler->Text[kXMLReport].c_str();

	miRCustomiseCSVReport->Caption  = (GLanguageHandler->Text[kCustomise] + L" CSV " + GLanguageHandler->Text[kReport]).c_str();
	miRCustomiseHTMLReport->Caption = (GLanguageHandler->Text[kCustomise] + L" HTML " + GLanguageHandler->Text[kReport]).c_str();
	miRCustomiseTextReport->Caption = (GLanguageHandler->Text[kCustomise] + L" " + GLanguageHandler->Text[kText] + L" " + GLanguageHandler->Text[kReport]).c_str();
	miRCustomiseTreeReport->Caption = (GLanguageHandler->Text[kCustomise] + L" " + GLanguageHandler->Text[kTree] + L" " + GLanguageHandler->Text[kReport]).c_str();
	miRCustomiseXMLReport->Caption  = (GLanguageHandler->Text[kCustomise] + L" XML " + GLanguageHandler->Text[kReport]).c_str();

	miRReportOptions->Caption  = (GLanguageHandler->Text[kReportOptions] + kEllipsis).c_str();
	miRCopyLastReportToClipboard->Caption = GLanguageHandler->Text[kCopyLastReportToClipboard].c_str();

	miRReportBrowser->Caption  = (GLanguageHandler->Text[kReportBrowser] + kEllipsis).c_str();

	// == Tools ================================================================================
	miTFolderHistoryInfo->Caption = (GLanguageHandler->Text[kFolderHistoryInfo] + kEllipsis).c_str();
	miTBackupXinorbis->Caption    = GLanguageHandler->Text[kBackupYourXinorbisData].c_str();
  	miTLanguage->Caption          = GLanguageHandler->Text[kLanguage].c_str();
	miTAddToContextMenu->Caption  = (GLanguageHandler->Text[kAddXinorbisToExplorerContextMenu] + kEllipsis).c_str();

	// == Detail ===============================================================================
	miDFileSizeSpread->Caption     = (GLanguageHandler->Text[kFileSizeSpread] + kEllipsis).c_str();
	miDDuplicatesFileName->Caption = GLanguageHandler->Text[kDuplicatesFileName].c_str();
	miDDuplicatesFileSize->Caption = GLanguageHandler->Text[kDuplicatesFileSize].c_str();
	miDFolderDetail->Caption       = (GLanguageHandler->Text[kFolderDetail] + kEllipsis).c_str();
	miDFileAge->Caption            = (GLanguageHandler->Text[kFileAge] + kEllipsis).c_str();

	// == Help =================================================================================
	miHTutorial->Caption        = GLanguageHandler->Text[kTutorial].c_str();
	//  miDonate->Caption           = GLanguageHandler->Text[kPurchaseXinorbis].c_str();
	miHHelpCats->Caption        = GLanguageHandler->Text[kHelpCats].c_str();
	miHHelp->Caption            = GLanguageHandler->Text[kHelp].c_str();
	miHContextHelp->Caption     = GLanguageHandler->Text[kContextHelp].c_str();
	miHUserManual->Caption      = GLanguageHandler->Text[kUserManual].c_str();
	miHReference->Caption       = (GLanguageHandler->Text[kReference] + kEllipsis).c_str();
	miHFAQs->Caption            = (L"FAQs" + kEllipsis).c_str();
	miHXinorbisHome->Caption    = GLanguageHandler->Text[kXinorbisHome].c_str();
	miHReportBug->Caption       = GLanguageHandler->Text[kReportBugFeature].c_str();
	miHCheckForUpdates->Caption = GLanguageHandler->Text[kCheckForUpdates].c_str();
	miHAbout->Caption           = GLanguageHandler->Text[kAbout].c_str();

	#ifdef _DEBUG
	miDebug->Visible = true;
    #endif

	//LoadMenu(FrameSearch.puQuickSearch,          GSystemGlobal.ExePath + 'data\languages\' + languagesymbol + '\QuickSearch.menu');
// TO DO	LoadMenu(FrameFolderHistory.puFHQuickSearch, GSystemGlobal.ExePath + 'data\languages\' + languagesymbol + '\FHQuickSearch.menu');
}


void TFormMain::ConfigureObjects()
{
	WelcomeOptions[0] = lWelcomeScan; WelcomeOptions[1] = lWelcomeFolderHistory;

	TaskOptions[0] = lTaskID1; TaskOptions[1] = lTaskID2; TaskOptions[2] = lTaskID3;
	TaskOptions[3] = lTaskID4; TaskOptions[4] = lTaskID5; TaskOptions[5] = lTaskID6;
	TaskOptions[6] = lTaskID7; TaskOptions[7] = lTaskID8;

	AdvancedOptions[0] = lAdvID1; AdvancedOptions[1] = lAdvID2; AdvancedOptions[2] = lAdvID3;

	LanguageMenus[0]  = miLang1;  LanguageMenus[1]  = miLang2;  LanguageMenus[2]  = miLang3;
	LanguageMenus[3]  = miLang4;  LanguageMenus[4]  = miLang5;  LanguageMenus[5]  = miLang6;
	LanguageMenus[6]  = miLang7;  LanguageMenus[7]  = miLang8;  LanguageMenus[8]  = miLang9;
	LanguageMenus[9]  = miLang10; LanguageMenus[10] = miLang11; LanguageMenus[11] = miLang12;
	LanguageMenus[12] = miLang13;
}


void TFormMain::UpdateGUICustomNames(int data_source)
{
  //if Assigned(FrameReports[aDataIndex]) then
//	FrameReports[aDataIndex].UpdateGUICustomNames;

//  if Assigned(FrameNavigation[aDataIndex]) then
//	FrameNavigation[aDataIndex].UpdateGUICustomNames;
}
#pragma end_region


#pragma region Application_Control
void TFormMain::ToggleSoftwareStatus(int index, bool status)
{
	FrameSelect->bScanNow->Enabled        = status;
	FrameSelect->cbScanPath->Enabled      = status;
	FrameSelect->bSelect->Enabled         = status;
	FrameSelect->bExcludeFolders->Enabled = status;
	FrameSelect->bExcludeFiles->Enabled   = status;
	FrameSelect->bFavourites->Enabled     = status;
	FrameSelect->bCombine->Enabled        = status;
	FrameSelect->bExplore->Enabled        = status;

	GuiUtility::SetButtonImageEnabled(sbReportSummary,  kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportCSV,      kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportDate,     kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportHTML,     kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportJSON,     kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportText,     kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportTree,     kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportXinorbis, kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportXML,      kReportIconOffStart, status);

	for (int t = 0; t < kSideMenuTasksCount; t++)
	{
		TaskOptions[t]->Enabled = status;
	}

	tbWizard->Enabled = status;

	for (int t = 0; t < kSideMenuAdvancedCount; t++)
	{
		AdvancedOptions[t]->Enabled = status;
	}

	FrameProperties->ToggleStatus(status);
}


void TFormMain::UpdateLeftPanelStatus()
{
	bool status = true;

	if (GScanEngine->Data[DataSource].Files.size() == 0)
	{
		status = false;
	}

	// =========================================================================
	// == Tasks Panel ==========================================================
	// =========================================================================

	for (int t = 0; t < 4; t++)
	{
		TaskOptions[t]->Enabled = status;
	}

	// =========================================================================
	// == Advanced Panel =======================================================
	// =========================================================================

	AdvancedOptions[0]->Enabled = status;
	AdvancedOptions[1]->Enabled = status;
	AdvancedOptions[2]->Enabled = status;

	// =========================================================================
	// == Quick Reports ========================================================
	// =========================================================================

	if (FrameSearch->Visible)
	{
		GuiUtility::SetButtonImageEnabled(sbReportSummary, kReportIconOffStart, false);
		GuiUtility::SetButtonImageEnabled(sbReportTree,    kReportIconOffStart, false);
	}
	else
	{
		GuiUtility::SetButtonImageEnabled(sbReportSummary, kReportIconOffStart, status);
		GuiUtility::SetButtonImageEnabled(sbReportTree,    kReportIconOffStart, status);
	}

	GuiUtility::SetButtonImageEnabled(sbReportCSV,      kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportDate,     kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportHTML,     kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportJSON,     kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportText,     kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportXML,      kReportIconOffStart, status);
	GuiUtility::SetButtonImageEnabled(sbReportXinorbis, kReportIconOffStart, status);
}
#pragma end_region


#pragma region Application_Menu
void TFormMain::UpdateMainMenu()
{
	miVOpenLastReport->Enabled            = (!GReportHandler->Last.FileName.empty());
	miRCopyLastReportToClipboard->Enabled = (!GReportHandler->Last.FileName.empty());

	bool status = (GScanEngine->Data[DataSource].Files.size() != 0);

	miCSVReport->Enabled           = status;
	miDateReport->Enabled          = status;
	miHTMLReport->Enabled          = status;
	miTextReport->Enabled          = status;
	miXinorbisReport->Enabled      = status;
	miTreeReport->Enabled          = status;
	miXMLReport->Enabled           = status;

	miFSaveReports->Enabled        = status;
	miSSearch->Enabled             = status;
	miSWizard->Enabled             = status;

	miDFileSizeSpread->Enabled     = status;
	miDDuplicatesFileName->Enabled = status;
	miDDuplicatesFileSize->Enabled = status;
	miDFolderDetail->Enabled       = status;
	miDFileAge->Enabled            =  status;

	miTabTable->Enabled            = status;
	miTabTree->Enabled             = status;
	miTabOther->Enabled            = status;
	miTabFolders->Enabled          = status;
	miTabMagnitude->Enabled        = status;
	miTabFileDates->Enabled        = status;
	miTabHistory->Enabled          = status;
	miTabTop101->Enabled           = status;
	miTabNullFiles->Enabled        = status;
	miTabUsers->Enabled            = status;
	miTabTemp->Enabled             = status;
	miTabNameLength->Enabled       = status;
}
#pragma end_region


#pragma region Application_Hooks
void TFormMain::OnOpenSettingsTab(int tab)
{
	if (OpenSettings(tab) == 1)
	{
		DoPreferenceChanges();

		FrameSelect->UpdateQuickFolders();

		FrameSearch->BuildSearchCharts();

		//FrameFolderHistory.InitUpdate;
		//FrameReports[dataLatestScan].InitUpdate;

		//if Assigned(FrameReports[dataFolderHistory])                      TO DO TO DO
		//{
		//	FrameReports[ dataFolderHistory].InitUpdate;
		//}

		//FrameSelect->BuildScanHistoryTable(0);

		// =====================================================================

		GSettingsHandler->ProgressPercentage = ProgressUpdates[GSettingsHandler->Optimisations.ProgressUpdate][0];
		GSettingsHandler->ProgressFileCount  = ProgressUpdates[GSettingsHandler->Optimisations.ProgressUpdate][1];

		// =====================================================================

		if (GSettingsHandler->History.Enabled)
		{
			//tbToggleFH.Enabled    := True;
			//tbToggleFH.ImageIndex := 6;

			//lWelcomeFolderHistory.Enabled  := True;

			//XSettings.System.UserEnabledFH := True;
		}
		else
		{
			//tbToggleFH.Enabled    := False;
			//tbToggleFH.ImageIndex := 5;

			//lWelcomeFolderHistory.Enabled  := False;

			//XSettings.System.UserEnabledFH := False;
		}
	}
}


void TFormMain::OnNewReport()
{
	UpdateMainMenu();
}


void TFormMain::OnJustInTime(int value)
{
	if (!FrameProperties->JIT.GetTab(value))
	{
		FrameProperties->UpdateDisplay(value);
    }
}


void TFormMain::OnStatusBarChange(const std::wstring text)
{
	sbMain->Panels->Items[0]->Text = text.c_str();
}


void TFormMain::OnReportsChange(int tab)
{
	lTaskID1Click(lTaskID2);

	//FrameReports[DataSource].ActivePage := aNewTab;
}


void TFormMain::OnTutorialBarChange(const std::wstring text)
{
	if (GSettingsHandler->System.Tutorial)
	{
		if (text.find(L'\\') != std::wstring::npos)
		{
			if (FileExists(text.c_str()))
			{
				//lTutorial.HTMLText.LoadFromFile(aText)
			}
			else
			{
				//lTutorial.HTMLText[0] := XText[rsMissingFile] + ': ' + aText;
			}
		}
		else
		{
//			if FileExists(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
//						'\tutorial\' + aText + '.dat')
//			{
//				lTutorial.HTMLText.LoadFromFile(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
//												'\tutorial\' + aText + '.dat')
//			}
//			else                     TO DO TO DO
//			{
//				lTutorial.HTMLText[0] := XText[rsMissingFile] + ': \tutorial\' + aText;
//			}
		}
	}
}


void TFormMain::OnResetDisplay(int status)
{
	if (FrameMap->DataSource == kDataFolderHistory)
	{
		FrameMap->Clear();
	}
}


void TFormMain::OnMenuChange(const std::wstring text, int menu_item, int state)
{
	switch (menu_item)
	{
	case 0:
		if (state == 0)
		{
			lTaskID4->Font->Color = clWindowText;
		}
		else
		{
			lTaskID4->Font->Color = clGreen;
		}

		if (!text.empty())
		{
			lTaskID4->Caption = text.c_str();
		}
		break;
	case 1:
		break;
	case 2:
		break;
	}
}


void TFormMain::OnProcessWindowStatusChange(int window, int status)
{
	switch (status)
	{
	case kWindowAnalysisProgress:
		switch (window)
		{
		case kWindowAnalysisProgress:
			GSplashHandler->HideProcessWindow();
			break;
		case kWindowZipProgress:
			GSplashHandler->HideZipWindow();
			break;
		}
		break;
	case kWindowZipProgress:
		switch (window)
		{
		case kWindowAnalysisProgress:
			GSplashHandler->ShowProcessWindow();
			break;
		case kWindowZipProgress:
			GSplashHandler->ShowZipWindow();
			break;
		}
        break;
	}
}


void TFormMain::OnFormClose(int form)
{
	switch (form)
	{
	case kFormFileSpread:
		lAdvID1->Font->Style.Clear();
		break;
	case kFormExplore:
		lAdvID2->Font->Style.Clear();
		break;
	case kFormFileAges:
		lAdvID3->Font->Style.Clear();
		break;
	}
}


void TFormMain::OnExtSetSidePanelDisplay(int welcome_id, int task_id, int task_sub_id, int can_add_to_history)
{
	SetSidePanelDisplay(welcome_id, task_id, task_sub_id, can_add_to_history);
}


void TFormMain::OnProcessWindowProgressChange(int progress)
{
	GSplashHandler->SetProgressBar(progress);
}


void TFormMain::OnUpdateHistoryFinished()
{
//	if not Assigned(FrameNavigation[dataFolderHistory])
//	{
//		CreateNavigationFrame(dataFolderHistory); TO DO
//	}

	//BuildSummary(dataFolderHistory, 0);

	// =========================================================================

 //	UpdateLeftPanelStatus();
}


void TFormMain::OnChartsHaveChanged()
{
	//FrameReports[dataLatestScan].InitUpdate;
	//FrameNavigation[dataLatestScan].InitUpdate;

	//if Assigned(FrameReports[dataFolderHistory])
   //	{
   //		FrameReports[dataFolderHistory].InitUpdate;
   //	}

 //	if Assigned(FrameNavigation[dataFolderHistory])
  //	{
  //		FrameNavigation[dataFolderHistory].InitUpdate;
   //	}

   //	FrameFolderHistory.InitUpdate;
}


void TFormMain::OnOpenSearchWizard(int status)
{
	miSWizardClick(NULL);
}


void TFormMain::DoPreferenceChanges()
{
	GFileExtensionHandler->Sort();
}


void TFormMain::RequestNewScan(const std::wstring path, int data_source, bool from_file)
{
	if (from_file)
	{
		if (Utility::GetFileExtension(path) == L".zsr2")
		{
//			XinorbisScan(aDataIndex, '', aNewPath, ScanTypeNormal, ScanSourceFileXin2Detailed)
		}
		else if (Utility::GetFileExtension(path) == L".zsr")
		{
//			XinorbisScan(aDataIndex, '', aNewPath, ScanTypeNormal, ScanSourceFileXinDetailed)
		}
		else
		{
//			BuildMainFromCSV(aDataIndex, aNewPath);
		}
	}
	else
	{
//		XinorbisScan(aDataIndex, aNewPath, '', ScanTypeNormal, ScanSourceLive);
	}
}


void TFormMain::RequestNewCombineScan(int status)
{
 // TO Do	CombineScan();
}


void TFormMain::RequestNewSummary(int data_source, bool auto_open)
{
	// TO DO BuildSummary(data_source, 0);
}


void TFormMain::RequestNewFHPath(const std::wstring path)
{
	//if (!path.empty())
	//{
	 //	lWelcomeFolderHistoryMouseDown(lWelcomeFolderHistory, mbLeft, [ssLeft], 0, 0);

	//	FrameFolderHistory.SelectedPath := aPath;
   //	}
}


void TFormMain::RequestNewSearch(const std::wstring search, int data_source)
{
	//SetSidePanelDisplay(kNullEntry, 4, kNullEntry, 1);
	// make sure to set menu and show search frame ^ ?

	//FrameSearch.DoSearch(aNewSearch);
}


void TFormMain::BuildMainFromCSV(const std::wstring file_name, int data_source)         // check this needs dataindex, dont think it does
 { /*                   to do
	CSVDataFormat csvdf = OpenCSVDataFormat(file_name);

	if ret.Fields[0] <> -1)
	{
		if (GScanEngine->ImportFromCSVCustom(file_name, data_source, csvdf, true, true, true))
		{
		// update all of the displays, most of these have helper functions that handle eg updating comboboxes...

		GSystemGlobal.drivespacemax  := 0;
		GSystemGlobal.drivespacefree := 0;

		GSplashHandler->SetProgressBar(5);

		GXinorbisScan.AnalyseDataFromCSVImport(aDataIndex);

		//-- ensure that the top101 tab is configured for our list of users --------

		FrameReports[aDataIndex].cbTopUsers.Clear;
		FrameReports[aDataIndex].cbTop101DatesUser.Clear;
		FrameReports[aDataIndex].cbTopUsers.Items.Add(XText[rsAllUsers]);
		FrameReports[aDataIndex].cbTop101DatesUser.Items.Add(XText[rsAllUsers]);

		for t := 0 to GScanDetails[aDataIndex].Users.Count - 1 do begin
		FrameReports[aDataIndex].cbTopUsers.Items.Add(GScanDetails[aDataIndex].Users[t].Name);
		FrameReports[aDataIndex].cbTop101DatesUser.Items.Add(GScanDetails[aDataIndex].Users[t].Name);
		end;

		FrameReports[aDataIndex].cbTopUsers.ItemIndex := 0;
		FrameReports[aDataIndex].cbTop101DatesUser.ItemIndex  := 0;

		// =========================================================================

		GSplashHandler->SetProgressBar(6);
		XSettings.Forms.ProgressForm.SetProcessIcon(3);

		TDisplayUtility.InformationTabTableTable(    aDataIndex, 1, FrameReports[aDataIndex].sgMainReport);
		TDisplayUtility.InformationTabFolderTable(   aDataIndex, FrameReports[aDataIndex].sgDirList);
		TDisplayUtility.InformationTabTypesList(     aDataIndex, FrameReports[aDataIndex].sgFileTypes);
		TDisplayUtility.InformationTabMagnitudeTable(aDataIndex, FrameReports[aDataIndex].cbMagnitudeScope.ItemIndex, FrameReports[aDataIndex].sgMagnitude);
		TDisplayUtility.InformationTabUsersTable(    aDataIndex, FrameReports[aDataIndex].cbUsersDisplayMode.ItemIndex, FrameReports[aDataIndex].sgUsers);

		FrameReports[aDataIndex].RefreshGraphDirList(nil);

		TDisplayUtility.InformationTabTypesTable(aDataIndex, 2, FrameReports[aDataIndex].tvFileTypes);

		case TDisplayUtility.InformationTabTypesTablePost(FrameReports[aDataIndex].tvFileTypes) of
		1 : FrameReports[aDataIndex].tvFileTypesClick(FrameReports[aDataIndex].tvFileTypes);
		2 : FrameReports[aDataIndex].cbTreeSizeClick(Nil);
		end;

		TDisplayUtility.InformationTabMagnitudeGraph(aDataIndex, FrameReports[aDataIndex].cbMagnitudeScope.ItemIndex, FrameReports[aDataIndex].vtcMagnitude, FrameReports[aDataIndex].cbGraphSizeMagnitude.Checked);

		FrameReports[aDataIndex].BuildUserDetailsGraph(Nil);

		FrameReports[aDataIndex].pTop101Left.Caption     := TDisplayUtility.BuildTop101FileSize(aDataIndex, FrameReports[aDataIndex].sgTop50Big, FrameReports[aDataIndex].sgTop50Small, FrameReports[aDataIndex].cbTopUsers, FrameReports[aDataIndex].capacityTop101);
		FrameReports[aDataIndex].pTop101DateLeft.Caption := TDisplayUtility.BuildTop101Date(aDataIndex, FrameReports[aDataIndex].sgTop101BigDate, FrameReports[aDataIndex].sgTop101SmallDate, FrameReports[aDataIndex].cbTop101DatesUser, FrameReports[aDataIndex].cbTop101Dates);

		if not(XSettings.Optimisations.JustInTimeDisplay) then begin
			TDisplayUtility.InformationTabFileDatesTree(aDataIndex, FrameReports[aDataIndex].cbFileDates.ItemIndex, FrameReports[aDataIndex].cbFileDatesUsers, XSettings.Optimisations.BuildDateTree, FrameReports[aDataIndex].tvFileDates, FrameReports[aDataIndex].vtcFileDates, FrameReports[aDataIndex].rbDatesQuantity.Checked, FrameReports[aDataIndex].capacityBarDates);

			FrameReports[aDataIndex].lHistoryResults.HTMLText[0] := TDisplayUtility.InformationTabHistoryGraph(aDataIndex, FrameReports[aDataIndex].vtcHistory, FrameReports[aDataIndex].cbHUsers, HGraphData,
																											 FrameReports[aDataIndex].dtpHFrom.Date, FrameReports[aDataIndex].dtpHTo.Date, FrameReports[aDataIndex].cbHInterval.ItemIndex,
																											 FrameReports[aDataIndex].cbHDateSelect.ItemIndex, FrameReports[aDataIndex].rbHQuantity.Checked,
																											 FrameReports[aDataIndex].cbHCumulative.Checked, FrameReports[aDataIndex].cbHInterval.Items[FrameReports[aDataIndex].cbHInterval.ItemIndex], FrameReports[aDataIndex].capacityBarHistory);

			FrameReports[aDataIndex].lTempStatus.Caption := TDisplayUtility.BuildTempChart(aDataIndex, FrameReports[aDataIndex].sgTemp, FrameReports[aDataIndex].vtcTemp, FrameReports[aDataIndex].rbTempSize.Checked);



			case aDataIndex of
			dataLatestScan    : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathLS));
			dataFolderHistory : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathFH));
			end;

			FrameNavigation[aDataIndex].BuildNavigationTab;

			FrameNavigation[aDataIndex].SelectAndDblClick(1, 1);
		end;

		BuildSummary(aDataIndex, 0);

		FrameReports[aDataIndex].RefreshGraph(nil);

		ToggleSoftwareStatus(aDataIndex, True);

		HideProcessWindow;
		Caption := cx;
	}*/
}


void TFormMain::CombineScan()   // use FSouce when reactivating code
{ /*       to do
//  t : integer;

begin
{  ScanMultiple := DoCombine;

  if ScanMultiple.Count <> 0 then begin
    XSettings.LastScanMultiple := True;

   GScanDetails[dataLatestScan].TimeStarted := Now;

	Screen.Cursor := crHourGlass;
    //ToggleSoftwareStatus(False);

    // =========================================================================
    GScanDetails[dataLatestScan].Users.Clear;
    GScanDetails[dataLatestScan].Files.Clear;
    GScanDetails[dataLatestScan].Folders.Clear;
    //ClearStringGird(sgNullFolders, False);
    // =========================================================================

   GScanDetails[dataLatestScan].ScanMode:=ScanSourceLive;

   GScanDetails[dataLatestScan].ScanDateStr := GetDate(GETTIMEFORMAT_SLASH) + ' ' + TUtility.GetTime(GETTIMEFORMAT_SLASH);
   GScanDetails[dataLatestScan].ScanDateInt := GetDate(GETTIMEFORMAT_YYYYMMDD) + TUtility.GetTime(GETTIMEFORMAT_FILE);

    if Assigned(FOnProcessWindowStatus) then
      FOnProcessWindowStatus(CWindowAnalysisProgress, 1);

    for t := 0 to ScanMultiple.Count - 1 do begin
      XSettings.ProgressForm.SetProcessText(XText[rsCreatingFileList]);

      ffMain.Criteria.Files.Location := ScanMultiple.strings[t];

      ffMain.Execute;
    end;

//    PrepareToAnalyse(ScanMultiple.strings[0], True, True, True);

    if Assigned(FOnProcessWindowStatus) then
        FOnProcessWindowStatus(CWindowAnalysisProgress, 1);
    // =========================================================================

    pMainReportsxxxChange(Nil);
    ToggleSoftwareStatus(True);

  //  case XSettings.PostScanMode of
//      0 : {};
//      1 : lTaskID1Click(Nil);
//      2 : begin
//            lTaskID2Click(Nil);

//            pMainReports.ActivePageIndex := XSettings.PostScanIPPage;
//          end;
//      3 : lTaskID4Click(Nil);
//    end;

    // =========================================================================
//  end;       } */
}
#pragma end_region


#pragma region Application_Source
void __fastcall TFormMain::sbSourceLiveClick(TObject *Sender)
{
	//FSource := dataLatestScan;

//  ActivateSource(FSource);
}


void __fastcall TFormMain::sbSourceFolderHistoryClick(TObject *Sender)
{
//  FSource := dataFolderHistory;

//  ActivateSource(FSource);
}


void TFormMain::NewSourceAvailable(int source)
{
	switch (source)
	{
	case kDataScan:
		sbSourceLive->Enabled = true;

		sbSourceLiveClick(NULL);
		break;
	case kDataFolderHistory:
		sbSourceFolderHistory->Enabled = true;

		sbSourceFolderHistoryClick(NULL);
		break;
	}
}


void TFormMain::ActivateSource(int source)
{
	switch (source)
	{
	case kDataScan:
		DeactivateSource(kDataFolderHistory);

		sbSourceLive->Enabled = true;
		break;
	case kDataFolderHistory:
		DeactivateSource(kDataScan);

		sbSourceFolderHistory->Enabled = true;
		break;
	}

	UpdateMainMenu();

	DoNavigationHistoryAction(NavigationHistory[sbHome->Tag]);
}


void TFormMain::DeactivateSource(int source)
{
	switch (source)
	{
	case kDataScan:
		sbSourceLive->Enabled = false;
		break;
	case kDataFolderHistory:
		sbSourceFolderHistory->Enabled = false;
		break;
	}
}
#pragma end_region


#pragma region Frame_Select
void __fastcall TFormMain::OnNewScan(const std::wstring folder)
{
    GScanHistoryHandler->Add(folder, L"", L"");

	ExecutionParameters ex;

	if (GScanEngine->Execute(true, folder, ex))
	{
		ToggleSoftwareStatus(true);

        PostScan();
	}
}
#pragma end_region


#pragma region Frame_Exploder
void TFormMain::UpdateFrameExploder()
{
	FrameExploder->Update();
}
#pragma end_region


#pragma region Frame_Map
void TFormMain::UpdateFrameMap()
{
	FrameMap->Update();
}
#pragma end_region


#pragma region Post_Scan
void TFormMain::PostScan()
{
	FrameSummary->Update();
	FrameSummary->SetProcessTime(GScanEngine->ProcessTime);

	FrameExploder->NeedsRefresh = true;
	FrameMap->NeedsRefresh = true;

	FrameProperties->Update();

	ToggleSoftwareStatus(DataSource, true);

	Screen->Cursor = crDefault;

	// == only add if directory ================================================

	if (GScanEngine->Data[DataSource].Source != ScanSource::FolderHistory &&
		GScanEngine->Data[DataSource].Source != ScanSource::FileXinorbisDetailed &&
		GScanEngine->Data[DataSource].Source != ScanSource::FileXinorbis2Detailed)
	{
		if (GScanEngine->Data[DataSource].Path.String.size() >= 3)
		{
			GScanHistoryHandler->Add(GScanEngine->Data[DataSource].Path.String,
									 Convert::VectorToString(GScanEngine->ExcludedFiles),
									 Convert::VectorToString(GScanEngine->ExcludedFolders));

			FrameSelect->BuildScanHistory(0);
		}
	}

	switch (GSettingsHandler->General.PostScanMode)
	{
	case kPostScanNothing:
		// do nothing
		break;
	case kPostScanSummary:
		lTaskID1Click(lTaskID1);
		break;
	case kPostScanInformation:
		lTaskID1Click(lTaskID2);

		FrameProperties->SetTab(GSettingsHandler->General.PostScanIPPage);
		break;
	case kPostScanStructure:
		lTaskID1Click(lTaskID3);
		break;
	}

	if (GScanEngine->Data[DataSource].FileAttributes[kFileType_RecallOnOpen].Count != 0 ||
		GScanEngine->Data[DataSource].FileAttributes[kFileType_RecallOnDataAccess].Count != 0 ||
		GScanEngine->Data[DataSource].FileAttributes[kFileType_Offline].Count != 0)
	{
		iScanWarning->Visible = true;
		iScanWarning->Hint    = GLanguageHandler->Text[kReportContainsVirtualFiles].c_str();
	}
	else
	{
		iScanWarning->Visible = false;
	}

	// =========================================================================

	UpdateMainMenu();

	switch (GScanEngine->Data[DataSource].Source)
	{
	case ScanSource::LiveScan:
	case ScanSource::LiveShare:
		GLog->Add(L"Scan of \"" + GScanEngine->Last.Folder + L"\" finished");
		break;
	case ScanSource::FileXinorbisNormal:
	case ScanSource::FileCSV:
	case ScanSource::FileXinorbisDetailed:
	case ScanSource::FileXinorbis2Detailed:
		GLog->Add(L"Import of \"" + GScanEngine->Last.Folder + L"\" finished");
		break;
	case ScanSource::FolderHistory:
		GLog->Add(L"Loaded from Folder History table \"" + GScanEngine->Data[DataSource].ScanTable + L"\".");
		break;
	case ScanSource::SearchResults:
		break;
	}
}
#pragma end_region


#pragma region Top_Toolbar
void __fastcall TFormMain::tbSaveReportsClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::tbOpenClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::tbRefreshClick(TObject *Sender)
{
//  ShowProcessWindow;

	if (DataSource == kDataScan)
	{
		GScanEngine->Refresh();
	}
	else
	{
//  if FSource <> dataFolderHistory then                         // make refresh work with folder history
//	if GScanDetails[FSource].Files.Count <> 0 then begin
//	  XinorbisScan(FSource, GScanDetails[FSource].ScanPath, '', ScanTypeRefresh, GScanDetails[FSource].ScanSource);
//	end;
//end;
	}

//  HideProcessWindow;
}


void __fastcall TFormMain::tbAboutClick(TObject *Sender)
{
	FormAbout->ShowModal();
}
#pragma end_region


#pragma region Bottom_Toolbar
void TFormMain::AddToPageNavigationHistory(const std::wstring page_data)
{
	if (NavigationHistory[NavigationHistory.size() - 1] != page_data) // stop duplicates
	{
		NavigationHistory.push_back(page_data);

		sbNavigatePrevious->Enabled = true;

		sbHome->Tag = NavigationHistory.size() - 1;
	}
}


void __fastcall TFormMain::sbHomeClick(TObject *Sender)
{
	lWelcomeScanClick(NULL);
}


void __fastcall TFormMain::sbNavigatePreviousClick(TObject *Sender)
{
	if (sbHome->Tag > 0)
	{
		sbHome->Tag--;

		if (sbHome->Tag == 0)
		{
			sbNavigatePrevious->Enabled = false;
		}

		sbNavigateNext->Enabled = true;

		DoNavigationHistoryAction(NavigationHistory[sbHome->Tag]);
	}
}


void __fastcall TFormMain::sbNavigateNextClick(TObject *Sender)
{
	if (sbHome->Tag < NavigationHistory.size() - 1)
	{
		sbHome->Tag++;

		if (sbHome->Tag >= NavigationHistory.size() - 1)
		{
			sbNavigateNext->Enabled = false;
		}

		sbNavigatePrevious->Enabled = true;

		DoNavigationHistoryAction(NavigationHistory[sbHome->Tag]);
	}
}


void __fastcall TFormMain::sbToggleFolderHistoryClick(TObject *Sender)
{
	if (sbToggleFolderHistory->Tag == 0)
	{
		sbToggleFolderHistory->Tag = 1;
		sbToggleFolderHistory->Hint = (GLanguageHandler->Text[kHintM5] + L" [" + GLanguageHandler->Text[kEnabled] + L"]").c_str();
	}
	else
	{
		sbToggleFolderHistory->Tag = 0;
		sbToggleFolderHistory->Hint = (GLanguageHandler->Text[kHintM5] + L" [" + GLanguageHandler->Text[kDisabled] + L"]").c_str();
	}

	GSettingsHandler->Database.FolderHistoryEnabled = !GSettingsHandler->Database.FolderHistoryEnabled;
	sbToggleFolderHistory->ImageIndex = sbToggleFolderHistory->Tag + 5;
}


void __fastcall TFormMain::sbTogglePrivacyClick(TObject *Sender)
{
	if (sbTogglePrivacy->Tag == 0)
	{
		sbTogglePrivacy->Tag = 1;
		sbTogglePrivacy->Hint = (GLanguageHandler->Text[kHintM4] + L" [" + GLanguageHandler->Text[kEnabled] + L"]").c_str();
	}
	else
	{
		sbTogglePrivacy->Tag = 0;
		sbTogglePrivacy->Hint = (GLanguageHandler->Text[kHintM4] + L" [" + GLanguageHandler->Text[kDisabled] + L"]").c_str();
	}

	GSettingsHandler->Database.Privacy = !GSettingsHandler->Database.Privacy;
	sbTogglePrivacy->ImageIndex = sbTogglePrivacy->Tag + 3;
}


void __fastcall TFormMain::sbToggleVirtualFilesClick(TObject *Sender)
{
	if (sbToggleVirtualFiles->Tag == 0)
	{
		sbToggleVirtualFiles->Tag = 1;
		sbToggleVirtualFiles->Hint = (GLanguageHandler->Text[kIgnoreVirtualFolders] + L" [" + GLanguageHandler->Text[kEnabled] + L"]").c_str();
	}
	else
	{
		sbToggleVirtualFiles->Tag = 0;
		sbToggleVirtualFiles->Hint = (GLanguageHandler->Text[kIgnoreVirtualFolders] + L" [" + GLanguageHandler->Text[kDisabled] + L"]").c_str();
	}

	GScanEngine->AllowVirtualFiles = !GScanEngine->AllowVirtualFiles;
	sbToggleVirtualFiles->ImageIndex = sbToggleVirtualFiles->Tag + 9;
}


void __fastcall TFormMain::sbReportSummaryMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (sbReportSummary->Enabled)
	{
		std::wstring path = GSystemGlobal->AppDataPath + L"reports\\" + WindowsUtility::GetComputerNetName() + L"\\summary\\quick\\";
		std::wstring file_name = L"";

		bool auto_open = false;

		if (Shift.Contains(ssMiddle))
		{
			auto_open = true;
		}

		if (FrameProperties->Visible || FrameSummary->Visible)
		{
			file_name = Formatting::MakeFileNameCompatible(GScanEngine->Data[FrameProperties->DataSource].Path.String) + L"_" +
									Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) +
									L".txt";

			 ReportSummary::Generate(path + file_name, FrameProperties->DataSource,
									 FrameProperties->sgNullFiles, FrameProperties->sgNullFolders,
									 FrameProperties->sgFolders, FrameProperties->sgTop101Big, FrameProperties->sgUsers);
		}
/*		else if (FrameFolderHistory->Visible)
		{
			file_name = GSystemGlobal->AppDataPath + L"reports\\" + WindowsUtility::GetComputerNetName + L"\\summary\\quick\\" +
						Formatting::MakeFileNameCompatible(GScanEngine->Data[data_source].ScanPath) + L"_" +
						Utility::GetDate(GETTIMEFORMAT_YYYYMMDD) + L"_" +
						Utility::GetTime(GETTIMEFORMAT_FILE) +
						L".txt";

			data_source = FrameFolderHistory->DataSource;
		} */
	}
}


void __fastcall TFormMain::sbReportCSVMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (sbReportCSV->Enabled)
	{
		std::wstring path = GSystemGlobal->AppDataPath + L"reports\\" + WindowsUtility::GetComputerNetName() + L"\\csv\\quick\\";
		int data_source = 0;

		bool auto_open = false;

		if (Shift.Contains(ssMiddle))
		{
			auto_open = true;
		}

		CSVReportOptions csvro = GSettingsHandler->Reports.CSV[kReportLayoutQuick];

		csvro.Data = kDataFileList;

		if (FrameProperties->Visible || FrameSummary->Visible)
		{
			csvro.FileName = path +
							 Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
							 Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) +
							 L".csv";

			data_source = FrameProperties->DataSource;
		}
		else if (FrameSearch->Visible)
		{
			csvro.FileName = path +
							 Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
							 Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) +
							 L"_" + GLanguageHandler->Text[kSearch] + L".csv";

			data_source = FrameSearch->DataSource;
		}

		GReportHandler->SaveCSV(csvro, data_source, false, auto_open);
    }
}


void __fastcall TFormMain::sbReportDateMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
//
}


void __fastcall TFormMain::sbReportHTMLMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (sbReportHTML->Enabled)
	{
		std::wstring path = GSystemGlobal->AppDataPath + L"reports\\" + WindowsUtility::GetComputerNetName() + L"\\html\\quick\\";
		std::wstring file_name = L"";

		bool auto_open = false;

		if (Shift.Contains(ssMiddle))
		{
			auto_open = true;
		}

		if (FrameProperties->Visible || FrameSummary->Visible)
		{
			HTMLReportOptions htmlro = GSettingsHandler->Reports.HTML[kReportLayoutQuick];

			file_name = Formatting::MakeFileNameCompatible(GLanguageHandler->Text[kSearchResults] + L"_" + GScanEngine->Data[FrameSearch->DataSource].Path.String) + L"_" +
						L"_" +
						Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) +
						L"_" + GLanguageHandler->Text[kSearch] + L".htm";

			htmlro.FileName = path + file_name;

			GReportHandler->SaveHTML(htmlro, FrameProperties->DataSource, false, auto_open);
		}
		else if (FrameSearch->Visible)
		{
			if (FrameSearch->CurrentTab() == 0)
			{
				file_name = Formatting::MakeFileNameCompatible(GLanguageHandler->Text[kSearchResults] + L"_" + GScanEngine->Data[FrameSearch->DataSource].Path.String) + L"_" +
							L"_" +
							Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) +
							L"_" + GLanguageHandler->Text[kSearch] + L".htm";

				GReportHandler->SaveHTMLFileList(FrameSearch->DataSource,
												 path + file_name,
												 GLanguageHandler->Text[kSearchResults] + L" \"" + FrameSearch->GetSearchText() + L"\"");
			}
			else
			{
				HTMLReportOptions htmlro = GSettingsHandler->Reports.HTML[kReportLayoutQuick];

				file_name = Formatting::MakeFileNameCompatible(GLanguageHandler->Text[kSearchResults] + L"_" + GScanEngine->Data[FrameSearch->DataSource].Path.String) + L"_" +
							Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) +
							L"_" + GLanguageHandler->Text[kSearch] + L".htm";

				htmlro.FileName = path + file_name;

				GReportHandler->SaveHTML(htmlro, FrameSearch->DataSource, false, auto_open);
			}
		}
	}
}


void __fastcall TFormMain::sbReportJSONMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (sbReportJSON->Enabled)
	{
    }
}


void __fastcall TFormMain::sbReportTextMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (sbReportText->Enabled)
	{
		std::wstring path = GSystemGlobal->AppDataPath + L"reports\\" + WindowsUtility::GetComputerNetName() + L"\\text\\quick\\";
		std::wstring file_name = L"";
		int data_source = 0;

		bool auto_open = false;

		if (Shift.Contains(ssMiddle))
		{
			auto_open = true;
		}

		TextReportOptions tro = GSettingsHandler->Reports.Text[kReportLayoutQuick];

		if (FrameProperties->Visible || FrameSummary->Visible)
		{
			tro.FileName = path +
						   Formatting::MakeFileNameCompatible(GScanEngine->Data[data_source].Path.String) + L"_" +
						   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".txt";
		}
		else if (FrameSearch->Visible)
		{
			data_source = FrameSearch->DataSource;

			tro.FileName = path +
			               Formatting::MakeFileNameCompatible(GScanEngine->Data[data_source].Path.String) + L"_" +
						   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) +
						   L"_" + GLanguageHandler->Text[kSearch] + L".txt";

			tro.Special = FrameSearch->GetSearchText();
		}

		if (!tro.FileName.empty())
		{
			GReportHandler->SaveText(tro, data_source, false, auto_open);
		}
	}
}


void __fastcall TFormMain::sbReportTreeMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (sbReportTree->Enabled)
	{
		bool auto_open = false;

		if (Shift.Contains(ssMiddle))
		{
			auto_open = true;
		}

		TreeReportOptions tro = GSettingsHandler->Reports.Tree[kReportLayoutQuick];

		tro.FileName = GSystemGlobal->AppDataPath + L"reports\\" + WindowsUtility::GetComputerNetName() + L"\\tree\\quick\\" +
					   Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
					   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".txt";

		GReportHandler->SaveTree(tro, DataSource, false, auto_open);
	}
}


void __fastcall TFormMain::sbReportXinorbisMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (sbReportXinorbis->Enabled)
	{
		bool auto_open = false;

		if (Shift.Contains(ssMiddle))
		{
			auto_open = true;
		}

		XinorbisReportOptions xro = GSettingsHandler->Reports.Xinorbis[kReportLayoutQuick];

		xro.FileName = GSystemGlobal->AppDataPath + L"reports\\" + WindowsUtility::GetComputerNetName() + L"\\xinorbis\\quick\\" +
					   Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
					   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".zsr2";

		GReportHandler->SaveXinorbis(xro, DataSource, false, auto_open);
    }
}


void __fastcall TFormMain::sbReportXMLMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (sbReportXML->Enabled)
	{
		std::wstring path = GSystemGlobal->AppDataPath + L"reports\\" + WindowsUtility::GetComputerNetName() + L"\\xml\\quick\\";
		std::wstring file_name = L"";
		int data_source = 0;

		bool auto_open = false;

		if (Shift.Contains(ssMiddle))
		{
			auto_open = true;
		}

		XMLReportOptions xmlro = GSettingsHandler->Reports.XML[kReportLayoutQuick];

		if (FrameProperties->Visible || FrameSummary->Visible)
		{
			xmlro.FileName = path +
							 Formatting::MakeFileNameCompatible(GScanEngine->Data[data_source].Path.String) + L"_" +
							 Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".xml";
		}
		else if (FrameSearch->Visible)
		{
			data_source = FrameSearch->DataSource;

			xmlro.FileName = path +
							 Formatting::MakeFileNameCompatible(GScanEngine->Data[data_source].Path.String) + L"_" +
							 Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) +
							 L"_" + GLanguageHandler->Text[kSearch] + L".xml";

			xmlro.Special = FrameSearch->GetSearchText();

			if (FrameSearch->CurrentTab() == 0)
			{
				xmlro.Data = kDataFileList;
			}
		}

		GReportHandler->SaveXML(xmlro, data_source, false, auto_open);
	}
}


void __fastcall TFormMain::sbReportSettingsClick(TObject *Sender)
{
//
}


void TFormMain::DoNavigationHistoryAction(const std::wstring action)
{
	int TaskId    = -1;
	int WelcomeId = -1;

	switch (action[0])
	{
	case L'W':
		WelcomeId = stoi(action.substr(1, 1));
		break;
	case L'T':
		TaskId = stoi(action.substr(1, 1));
		break;
	case L'H':
		WelcomeId = 1;                     // open Welcome option 1 (scan folder)
		break;
	}

	SetSidePanelDisplay(WelcomeId, TaskId, kNullEntry, 0);
}
#pragma end_region


#pragma region Gui_Navigation
void __fastcall TFormMain::lWelcomeScanClick(TObject *Sender)
{
	FrameSelect->BringToFront();

	SetSidePanelDisplay(1, kNullEntry, kNullEntry, 1);
}


void __fastcall TFormMain::lWelcomeFolderHistoryMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (Shift.Contains(ssLeft))
	{
		SetSidePanelDisplay(2, kNullEntry, kNullEntry, 1);
	}
	else if (Shift.Contains(ssMiddle))
	{
		miRReportBrowserClick(NULL);
	}
}
#pragma end_region


#pragma region Gui_Views
void TFormMain::ToggleSoftwareStatus(bool newstatus)
{
	lTaskID1->Enabled = newstatus;
	lTaskID2->Enabled = newstatus;
	lTaskID3->Enabled = newstatus;
	lTaskID4->Enabled = newstatus;
	lTaskID5->Enabled = newstatus;
	lTaskID6->Enabled = newstatus;
	lTaskID7->Enabled = newstatus;
	lTaskID8->Enabled = newstatus;

	lAdvID1->Enabled = newstatus;
	lAdvID2->Enabled = newstatus;
	lAdvID3->Enabled = newstatus;
}


void __fastcall TFormMain::lTaskID1Click(TObject *Sender)
{
	TLabel *label = (TLabel*)Sender;

	switch (label->Tag)
	{
	case kTaskSummary:
		SetSidePanelDisplay(kNullEntry, kTaskSummary, kNullEntry, 1);
		break;
	case kTaskProperties:
		SetSidePanelDisplay(kNullEntry, kTaskProperties, kNullEntry, 1);
		break;
	case kTaskStructure:
		SetSidePanelDisplay(kNullEntry, kTaskStructure, kNullEntry, 1);
		break;
	case kTaskSearch:
		SetSidePanelDisplay(kNullEntry, kTaskSearch, kNullEntry, 1);
		break;
	case kTaskMap:
		SetSidePanelDisplay(kNullEntry, kTaskMap, kNullEntry, 1);
		break;
	case kTaskDuplicatesName:
		SetSidePanelDisplay(kNullEntry, kTaskDuplicatesName, kNullEntry, 1);
		break;
	case kTaskDuplicatesSize:
		SetSidePanelDisplay(kNullEntry, kTaskDuplicatesSize, kNullEntry, 1);
		break;
	case kTaskExploder:
		SetSidePanelDisplay(kNullEntry, kTaskExploder, kNullEntry, 1);
		break;
	}
}


void TFormMain::SetSidePanelDisplay(int WelcomeId, int TaskId, int TaskSubId, bool AddToHistory)
{
	//SetWelcomeDisplay(welcomeID);

	DoWelcome(WelcomeId);

	DoTask(TaskId, TaskSubId);

//	if canAddToHistory = 1 then begin
//		if welcomeID <> -1 then
//		  AddToPageNavigationHistory('W' + IntToStr(welcomeID));

//		if taskID <> -1 then
//		  AddToPageNavigationHistory('T' + IntToStr(taskID));
//	end;

	if (TaskId == -1 && WelcomeId == -1)
	{
		//HandleResizing(pMainPanelIndex); TO DO

//		FrameSelect.BringToFront;
	}

	//UpdateLeftPanelStatus;
}


void TFormMain::SetWelcomeDisplay(int WelcomeId)
{
	for (int t = 0; t < kSideMenuWelcomeCount; t++)
	{
		if (t != WelcomeId)
		{
			WelcomeOptions[t]->Font->Style.Clear();
		}
	}

	if (WelcomeId != -1 && WelcomeId < kSideMenuWelcomeCount)
	{
		WelcomeOptions[WelcomeId]->Font->Style = TFontStyles() << fsBold;
	}
}


void TFormMain::DoWelcome(int WelcomeId)
{
	if (WelcomeId != -1)
	{
		switch (WelcomeId)
		{
		case 1:
			HandleResizing(kScanSelectionPanelIndex);
			FrameSelect->pcSelect->ActivePageIndex = 0;
			FrameSelect->BringToFront();

			break;
		case 2:
//			HandleResizing(kMainFileHistoryPanelIndex);
//			FrameFolderHistory->BringToFront();

//			FrameFolderHistory->AvailableComputerChange();
			break;
		case 5:
//			HandleResizing(kMainWebReportsPanelIndex);
//			FrameWebReports->BringToFront();
			break;
		}

		if (GSettingsHandler->System.Tutorial)
		{
//			OnTutorialBarChange(GSystemGlobal.ExePath +
//								L"data\\languages\\" +
//								GLanguageHandler->GetLanguageSymbol() +
//								L"\\tutorial\\w" + std::to_wstring(WelcomeId) + L".dat");
		}
	}
}


void TFormMain::DoTask(int TaskId, int TaskSubId)
{
	if (TaskId == kNullEntry) return;

	if (TaskId < 99)
	{
		SetTasksDisplay(TaskId);
	}

	switch (TaskId)
	{
	case kTaskSummary:
		HandleResizing(kMainSummaryPanelIndex);
		FrameSummary->BringToFront();
		break;
	case kTaskProperties:
		HandleResizing(kMainPropertiesPanelIndex);
		FrameProperties->BringToFront();

		//if aTaskSubID <> NullEntry then
		 // FrameReports.pMainReports.ActivePageIndex := aTaskSubID;

		break;
/*	case kTaskStructure:     folder history stuff
		if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
			   ShowXDialog(XText[kWarning], XText[kleaseWaitFolderHistory], XDialogTypeXinorbis);
			 end
			 else begin
			   HandleResizing(pMainNavigationPanelIndex);
			   FrameNavigation[FSource].BringToFront;

			   if XSettings.System.JustInTimeProcessed[FSource, TabNavigation] = False then begin
				 case FSource of
				   dataLatestScan    : GScanDetails[FSource].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathLS));
				   dataFolderHistory : GScanDetails[FSource].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathFH));
				 end;

				 FrameNavigation[FSource].BuildNavigationTab;

				 FrameNavigation[FSource].SelectAndDblClick(1, 1);

				 XSettings.System.JustInTimeProcessed[FSource, TabNavigation] := True;
			   end;
			 end;
		   end;
		break;          */
	case kTaskSearch:
		HandleResizing(kMainSearchPanelIndex);

		FrameSearch->DataSource = DataSource;
		FrameSearch->SetTab(0);
		FrameSearch->BringToFront();
		break;
	case kTaskMap:
		HandleResizing(kMainMapPanelIndex);

//		UpdateFrameMap();

		FrameMap->BringToFront();
		break;
	case kTaskDuplicatesName:
		HandleResizing(kMainSearchPanelIndex);

		FrameSearch->DataSource = DataSource;
		FrameSearch->SetTab(2);
		FrameSearch->BringToFront();
		break;
	case kTaskDuplicatesSize:
		HandleResizing(kMainSearchPanelIndex);

		FrameSearch->DataSource = DataSource;
		FrameSearch->SetTab(3);
		FrameSearch->BringToFront();
		break;
	case kTaskExploder:
		HandleResizing(kMainExploderPanelIndex);

//		UpdateFrameExploder();

		FrameExploder->BringToFront();
		break;
	}

//	if XSettings.System.Tutorial then
//      OnTutorialBarChange(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
//,												  '\tutorial\t' + IntToStr(aTaskID) + '.dat');
}


void TFormMain::SetTasksDisplay(int task_id)
{
	for (int t = 0; t < kSideMenuTasksCount; t++)
	{
		if (t != task_id)
		{
			TaskOptions[t]->Font->Style.Clear();
		}
	}

	if (task_id != -1)
	{
	   TaskOptions[task_id]->Font->Style = TFontStyles() << fsBold;
	}
}


void TFormMain::HandleResizing(int NewPanelInFront)
{
	if (PanelInFront != NewPanelInFront)
	{
		switch (PanelInFront)
		{
		case kMainPanelIndex:
			//pMain->Visible = false;
			//pMain->Align = alNone;
			break;
		case kScanSelectionPanelIndex:
			FrameSelect->Visible = false;
			FrameSelect->Align = alNone;
			break;
		case kMainSummaryPanelIndex:
			FrameSummary->Visible = false;
			FrameSummary->Align = alNone;
			break;
		case kMainPropertiesPanelIndex:
			FrameProperties->Visible = false;
			FrameProperties->Align = alNone;

			//FrameReports.pMainReportsResize(Nil);
			break;
		case kMainNavigationPanelIndex:
			FrameStructure->Visible = false;
			FrameStructure->Align = alNone;

//			FrameStructure->Panel25Resize(nil);
//			FrameStructure->Panel26Resize(nil);
			break;
		case kMainSearchPanelIndex:
			FrameSearch->Visible = false;
			FrameSearch->Align = alNone;
			break;
		case kMainFileHistoryPanelIndex:
//			FrameFolderHistory->Visible = false;
//			FrameFolderHistory->Align = alNone;
			break;
		case kMainWebReportsPanelIndex:
//			FrameWebReports.Visible := False;
//			FrameWebReports.Align   := alNone;
			break;
		case kMainMapPanelIndex:
			FrameMap->Visible = false;
			FrameMap->Align = alNone;
			break;
		case kMainExploderPanelIndex:
			FrameExploder->Visible = false;
			FrameExploder->Align = alNone;
			break;
		}
	}

	PanelInFront = NewPanelInFront;
	//FormDisplay.Source       := FSource;

	switch (NewPanelInFront)
	{
	case kMainPanelIndex:
		//pMain.Visible := True;
		//pMain.Align   := alClient;
		break;
	case kScanSelectionPanelIndex:
		FrameSelect->Visible = true;
		FrameSelect->Align = alClient;

///		FrameSelect->pScanSelectionResize(Nil);
		break;
	case kMainSummaryPanelIndex:
		FrameSummary->Align = alClient;
		FrameSummary->Visible = true;
		break;
	case kMainPropertiesPanelIndex:
		FrameProperties->Visible = true;
		FrameProperties->Align = alClient;

		//FrameProperties[FSource].pMainReportsResize(Nil);
		break;
	case kMainNavigationPanelIndex:
		FrameStructure->Visible = true;
		FrameStructure->Align = alClient;

		//FrameStructure[FSource].Panel25Resize(nil);
//		FrameStructure[FSource].Panel26Resize(nil);
		break;
	case kMainSearchPanelIndex:
		FrameSearch->Visible = true;
		FrameSearch->Align = alClient;
//		FrameSearch->FrameResize(Nil);
		break;
	case kMainFileHistoryPanelIndex:
		  //	FrameFolderHistory->Visible = true;
		  //	FrameFolderHistory->Align = alClient;

//			FrameFolderHistory.tpFHStatsResize(Nil);
		break;
	case kMainWebReportsPanelIndex:
		  //	FrameWebReports->Visible = true;
		  //	FrameWebReports->Align = alClient;
		break;
	case kMainMapPanelIndex:
		FrameMap->Visible = true;
		FrameMap->Align = alClient;
		break;
	case kMainExploderPanelIndex:
		FrameExploder->Visible = true;
		FrameExploder->Align = alClient;
		break;
	}
}
#pragma end_region


#pragma region Menu_File
void __fastcall TFormMain::miFSaveReportsClick(TObject *Sender)
{
	TextReportOptions tro;
	CSVReportOptions csvro;
	HTMLReportOptions htmlro;
	XinorbisReportOptions xinro;
	XMLReportOptions xmlro;
	TreeReportOptions tero;

//  tbSave.ImageIndex := CToolbarSaveOn;

//	if (OpenReportSave(tro, csvro, htmlro, xinro, xmlro, tero))
//	{
		// TO DO , need to create then save .... GReportHandler->SaveReport(tro, csvro, htmlro, xinro, xmlro, tero);
	//}

	//dataFolderHistory : if DoReportSave(FSource, TextOptions, CSVOptions, HTMLOptions, XinOptions, XMLOptions, TreeOptions) then
//						  FrameFolderHistory.SaveReports(TextOptions, CSVOptions, HTMLOptions, XinOptions, XMLOptions, TreeOptions)
//}

  //tbSave.ImageIndex := CToolbarSaveOff;
}


void __fastcall TFormMain::miFExitClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Menu_Edit
void __fastcall TFormMain::miESettingsClick(TObject *Sender)
{
	OpenSettings(-1);
}


void __fastcall TFormMain::ToolButton7Click(TObject *Sender)
{
	//SetSidePanelDisplay(5, NullEntry, NullEntry, 1);
}


void __fastcall TFormMain::ToolButton8Click(TObject *Sender)
{
	//if XSettings.ftpOptions[ftpActualLink] <> '' then
//	TXWindows.ExecuteFile(0, XSettings.ftpOptions[ftpActualLink], '', '')
//  else
//	ShowXDialog(XText[rsWebReports], XText[rsWebReportsSettingsMissing], XDialogTypeXinorbis);
}


void __fastcall TFormMain::miEReportOptionsClick(TObject *Sender)
{
	OpenReportSettings(-1);
}


void __fastcall TFormMain::miEFileTypesClick(TObject *Sender)
{
	if (OpenFileAssociations())
	{
    }
}


void __fastcall TFormMain::miECustomiseQuickFolderClick(TObject *Sender)
{
	OpenQuickMenuBuilder();
}
#pragma end_region


#pragma region Menu_Search
void __fastcall TFormMain::miSSearchClick(TObject *Sender)
{
//     lTaskID1Click(lTaskID4);
}


void __fastcall TFormMain::miSWizardClick(TObject *Sender)
{
	std::wstring s = OpenSearchWizard();

	if (!s.empty())
	{
		switch (DataSource)
		{
		case kDataScan:
			if (GScanEngine->Data[DataSource].Files.size() != 0)
			{
				lTaskID1Click(lTaskID4);

				FrameSearch->ExecuteSearch(s);
			}
			break;
		case kDataFolderHistory:
		   /*	if (FrameFolderHistory.tpFHMain.ActivePageIndex = TabFHMainSearch)
			   (FrameFolderHistory.tsFHSearch.ActivePageIndex = TabFHCompare)
			{
				FrameFolderHistory.eFHCompareSearch.Text := s;

				FrameFolderHistory.sbFHCompareSearchClick(FrameFolderHistory.sbFHCompareSearch);
			}
			else
			{
				lTaskID1Click(lTaskID4);

				FrameSearch->ExecuteSearch(s);
			} */
			break;
		}
	}
}



void __fastcall TFormMain::miSSearchSyntaxClick(TObject *Sender)
{
	HelpHandler::OpenSearchManual();
}
#pragma end_region


#pragma region Menu_View
void __fastcall TFormMain::miVOpenLastReportClick(TObject *Sender)
{
	if (!GReportHandler->Last.FileName.empty())
	{
		if (FileExists(GReportHandler->Last.FileName.c_str()))
		{
			switch (GReportHandler->GetReportType(GReportHandler->Last.FileName))
			{
			case kReportTypeCSV:
				if (!GSettingsHandler->Reports.CSVCommand.empty())
				{
					WindowsUtility::ExecuteFile(L"\"" + GSettingsHandler->Reports.CSVCommand + L"\"", L"\"" + GReportHandler->Last.FileName + L"\"");
				}
				else
				{
					WindowsUtility::ExecuteFile(L"notepad.exe", L"\"" + GReportHandler->Last.FileName + L"\"");
				}
				break;
			case kReportTypeDate:
				break;
			case kReportTypeHTML:
				if (!GSettingsHandler->Reports.HTMLCommand.empty())
				{
					WindowsUtility::ExecuteFile(L"\"" + GSettingsHandler->Reports.HTMLCommand + L"\"", L"\"" + GReportHandler->Last.FileName + L"\"");
				}
				else
				{
					WindowsUtility::ExecuteFile(L"\"" + GReportHandler->Last.FileName + L"\"", L"");
				}
				break;
			case kReportTypeJSON:
				break;
			case kReportTypeText:
				if (!GSettingsHandler->Reports.TextCommand.empty())
				{
					WindowsUtility::ExecuteFile(L"\"" + GSettingsHandler->Reports.TextCommand + L"\"", L"\"" + GReportHandler->Last.FileName + L"\"");
				}
				else
				{
					WindowsUtility::ExecuteFile(L"\"" + GReportHandler->Last.FileName + L"\"", L"");
				}
				break;
			case kReportTypeXinorbis:
				WindowsUtility::ExecuteFile(L"notepad.exe", L"\"" + GReportHandler->Last.FileName + L"\"");
				break;
			case kReportTypeXML:
				if (!GSettingsHandler->Reports.XMLCommand.empty())
				{
					WindowsUtility::ExecuteFile(L"\"" + GSettingsHandler->Reports.XMLCommand + L"\"", L"\"" + GReportHandler->Last.FileName + L"\"");
				}
				else
				{
					WindowsUtility::ExecuteFile(L"notepad.exe", L"\"" + GReportHandler->Last.FileName + L"\"");
				}
				break;
			}
		}
		else
		{
			ShowXDialog(GLanguageHandler->Text[kReportNotFound],
						GReportHandler->Last.FileName,
						XDialogTypeWarning);
		}
	}
}


void __fastcall TFormMain::miRCopyLastReportToClipboardClick(TObject *Sender)
{
	if (!GReportHandler->Last.FileName.empty())
	{
		if (FileExists(GReportHandler->Last.FileName.c_str()))
		{
			GReportHandler->CopyReportToClipboard(GReportHandler->Last.FileName);
		}
	}
}


void __fastcall TFormMain::miVCategoryColoursClick(TObject *Sender)
{
	OpenCategoryColours();
}


void __fastcall TFormMain::miVLogsClick(TObject *Sender)
{
	FormLog->Visible = !FormLog->Visible;

	miVLogs->Checked = FormLog->Visible;
}


void __fastcall TFormMain::miTabTableClick(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	SetSidePanelDisplay(kNullEntry, 2, mi->Tag, kNullEntry);
}
#pragma end_region


#pragma region Menu_Reports
void __fastcall TFormMain::miRCustomiseCSVReportClick(TObject *Sender)
{
	CSVReportOptions csvro = OpenCSVReportOptions(0, false);
}


void __fastcall TFormMain::miRCustomiseHTMLReportClick(TObject *Sender)
{
	HTMLReportOptions htmlro = OpenHTMLReportOptions(0, false);
}


void __fastcall TFormMain::miRCustomiseTextReportClick(TObject *Sender)
{
	TextReportOptions textro = OpenTextReportOptions(0, false);
}


void __fastcall TFormMain::miRCustomiseTreeReportClick(TObject *Sender)
{
	TreeReportOptions treero = OpenTreeReportOptions(0, false);
}


void __fastcall TFormMain::miRCustomiseXMLReportClick(TObject *Sender)
{
	XMLReportOptions xmlro = OpenXMLReportOptions(0, false);
}


void __fastcall TFormMain::miRReportOptionsClick(TObject *Sender)
{
	OpenReportSettings(-1);
}


void __fastcall TFormMain::miRReportBrowserClick(TObject *Sender)
{
	WindowsUtility::ExecuteFile(L"\"" + GSystemGlobal->AppDataPath + L"reports" + L"\"", L"");
}


void __fastcall TFormMain::miCSVReportClick(TObject *Sender)
{
	sbReportCSVMouseDown(sbReportCSV, mbLeft, TShiftState() << ssLeft, 0, 0);
}


void __fastcall TFormMain::miDateReportClick(TObject *Sender)
{
	sbReportDateMouseDown(sbReportDate, mbLeft, TShiftState() << ssLeft, 0, 0);
}


void __fastcall TFormMain::miHTMLReportClick(TObject *Sender)
{
	sbReportHTMLMouseDown(sbReportHTML, mbLeft, TShiftState() << ssLeft, 0, 0);
}


void __fastcall TFormMain::miJSONReportClick(TObject *Sender)
{
	sbReportJSONMouseDown(sbReportJSON, mbLeft, TShiftState() << ssLeft, 0, 0);
}


void __fastcall TFormMain::miTextReportClick(TObject *Sender)
{
	sbReportTextMouseDown(sbReportText, mbLeft, TShiftState() << ssLeft, 0, 0);
}


void __fastcall TFormMain::miTreeReportClick(TObject *Sender)
{
	sbReportTreeMouseDown(sbReportTree, mbLeft, TShiftState() << ssLeft, 0, 0);
}


void __fastcall TFormMain::miXMLReportClick(TObject *Sender)
{
	sbReportXMLMouseDown(sbReportXML, mbLeft, TShiftState() << ssLeft, 0, 0);
}


void __fastcall TFormMain::miXinorbisReportClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Menu_Tools
void __fastcall TFormMain::miTFolderHistoryInfoClick(TObject *Sender)
{
	//ShowDatabaseInfo();
}


void __fastcall TFormMain::miTBackupXinorbisClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
												  L".zip",
												  GSystemGlobal->ExePath,
												  L"XinorbisBackup_" + Convert::DateToYYYYMMDDS(Now()) + L".zip");

	if (!file_name.empty())
	{
		GXZip->Folder(file_name, GSystemGlobal->AppDataPath);
	}
}


void __fastcall TFormMain::miLang1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	GLanguageHandler->CurrentLanguage = GLanguageHandler->OrdinalToLanguageSymbol(mi->Tag);

 //  DONT UNCOMMENT LoadLanguageDetails(TMenuItem(Sender).Tag, False);
}


void __fastcall TFormMain::miTAddToContextMenuClick(TObject *Sender)
{
	WindowsUtility::AddToContextMenu(Application->ExeName.c_str());
}
#pragma end_region


#pragma region Menu_Detail
void __fastcall TFormMain::miDFileSizeSpreadClick(TObject *Sender)
{
	if (FormFileSpread == nullptr)
	{
		FormFileSpread = new TFormFileSpread(this);
	}

	FormFileSpread->Show();
}


void __fastcall TFormMain::miDDuplicatesFileNameClick(TObject *Sender)
{
	lTaskID1Click(lTaskID6);
}


void __fastcall TFormMain::miDDuplicatesFileSizeClick(TObject *Sender)
{
	lTaskID1Click(lTaskID7);
}


void __fastcall TFormMain::miDFolderDetailClick(TObject *Sender)
{
	OpenMoreDetails(0, GScanEngine->Data[DataSource].Path.String);
}


void __fastcall TFormMain::miDFileAgeClick(TObject *Sender)
{
	if (FormFileAges == nullptr)
	{
		FormFileAges = new TFormFileAges(this);
	}

	FormFileAges->Show();
}
#pragma end_region


#pragma region Menu_Help
void __fastcall TFormMain::miHTutorialClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miHHelpCatsClick(TObject *Sender)
{
	WindowsUtility::ExecuteFile(L"http://xinorbis.co.uk/catware.htm", L"");
}


void __fastcall TFormMain::miHHelpClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"index.htm");
}


void __fastcall TFormMain::miHContextHelpClick(TObject *Sender)
{
	 /* folder history
	switch (FrameReports->pcProperties->ActivePageIndex)
	{
	case kTabFHMainStats:
		FHSubIndex := FrameFolderHistory.tpFHStats.ActivePageIndex;
		break;
	case TabFHMainSearch:
		lFHSubIndex := FrameFolderHistory.tsFHSearch.ActivePageIndex;
		break;
	}                 */

	if (NavigationHistory.size() != 0)
	{
		HelpHandler::OpenContextHelpPage(NavigationHistory[sbHome->Tag],
										 FrameProperties->CurrentTab(),
										 -1,
										 0);
    }
}


void __fastcall TFormMain::miHUserManualClick(TObject *Sender)
{
	WindowsUtility::ExecuteFile(L"\"" + GSystemGlobal->ExePath + L"Xinorbis10_User_Manual.pdf\"", L"");
}


void __fastcall TFormMain::miHReferenceClick(TObject *Sender)
{
	ShowReference();
}


void __fastcall TFormMain::miHFAQsClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"faqs.htm");
}


void __fastcall TFormMain::miHXinorbisHomeClick(TObject *Sender)
{
	WindowsUtility::ExecuteFile(L"http://www.xinorbis.co.uk/index.htm", L"");
}


void __fastcall TFormMain::miHReportBugClick(TObject *Sender)
{
	WindowsUtility::ExecuteFile(L"mailto:xinorbis@maximumoctopus.com?Subject=Xinorbis Feedback", L"");
}


void __fastcall TFormMain::miHCheckForUpdatesClick(TObject *Sender)
{
	OpenCheckForNewVersion(__XVersion, __XDate, false);
}
#pragma end_region


#pragma region Menu_Debug
void __fastcall TFormMain::miDOpenDebugClick(TObject *Sender)
{
	FormDebug->ShowModal();
}


void __fastcall TFormMain::Select1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	switch (mi->Tag)
	{
	case 0:
		//select
		break;
	case 1:
		lTaskID1Click(lTaskID2);
		break;
	case 2:
		//search
		break;
	case 3:
		//summary
		break;
	case 4:
		//structure
		break;
	}
}
#pragma end_region


#pragma region Folder_History
/*void TFormMain::TryBuildFolderHistoryAvailable;
begin
  if (XSettings.HistorySettings.Enabled) and (XSettings.System.UserEnabledFH) then begin
	FrameFolderHistory.BuildFolderHistoryAvailable;
  end
  else begin
	lWelcomeFolderHistory.Enabled := False;
	lWelcomeFolderHistory.Hint    := 'Disabled, enable through Settings->General';
  end;
end;

procedure TfrmMain.UpdateFolderHistoryOnTerminate(Sender: TObject);
 begin
  if GUpdateFolderHistoryUpdateThread.Error <> '' then begin
	ShowXDialog(XText[rsErrorSaving] + ': ' + XText[rsFolderHistory] + ' Database',
				GUpdateFolderHistoryUpdateThread.Error,
				XDialogTypeWarning);

	TMSLogger.Info(GUpdateFolderHistoryUpdateThread.Error);
  end;

  GUpdateFolderHistoryUpdateThread := Nil;

  FrameFolderHistory.BuildFolderHistory(TXWindows.GetComputerNetName, FrameSelect.ePath.Text);

  if FrameFolderHistory.clbFolderHistory.Count <> 0 then begin
	FrameFolderHistory.clbFolderHistory.Checked[0] := True;
	FrameFolderHistory.clbFolderHistory.ItemIndex  := 0;
	FrameFolderHistory.rbFHCountClick(Nil);
  end;

  lWelcomeFolderHistory.Font.Color := clWindowText;
  lWelcomeFolderHistory.Caption    := XText[rsFolderHistory];

  TMSLogger.Info('Folder History Update Finished.');
end;

procedure TfrmMain.ProcessUpdateFolderHistoryFile;
 begin
  TFolderHistoryUtility.UpdateFolderHistoryFile(dataLatestScan, FrameSelect.ePath.Text);

  if XSettings.HistorySettings.FullLogging then begin
	lWelcomeFolderHistory.Font.Color := clGreen;

	TMSLogger.Info('Folder History Update Started');

	GUpdateFolderHistoryUpdateThread := TUpdateFolderHistoryUpdateThread.Create(True);
	GUpdateFolderHistoryUpdateThread.OnTerminate := UpdateFolderHistoryOnTerminate;
	GUpdateFolderHistoryUpdateThread.SetData(GScanDetails[dataLatestScan].ScanMD5 +
											 GScanDetails[dataLatestScan].ScanDateInt +
											 TXWindows.GetComputerNetName,
											 XSettings.Database.ODBConnectionString,
											 XSettings.Database.UseODBC,
											 lWelcomeFolderHistory);
	GUpdateFolderHistoryUpdateThread.Start;
  end;
end;

void TFormMain::ScanFromFolderHistory(const aScanPath, aTableName : string; aFileHistoryDate : string);
}
  XinorbisScan(dataFolderHistory, aScanPath, aTableName, ScanTypeNormal, ScanSourceFolderHistory);

  GScanDetails[dataFolderHistory].ScanDateFHStr := aFileHistoryDate;
}               */
#pragma end_region


void TFormMain::AutoSaveReports(int data_source)
{
	GSettingsHandler->Reports.CSV[kReportLayoutAutoSave].FileName      = L"";
	GSettingsHandler->Reports.Date[kReportLayoutAutoSave].FileName     = L"";
	GSettingsHandler->Reports.HTML[kReportLayoutAutoSave].FileName     = L"";
	GSettingsHandler->Reports.JSON[kReportLayoutAutoSave].FileName     = L"";
	GSettingsHandler->Reports.Text[kReportLayoutAutoSave].FileName     = L"";
	GSettingsHandler->Reports.Tree[kReportLayoutAutoSave].FileName     = L"";
	GSettingsHandler->Reports.Xinorbis[kReportLayoutAutoSave].FileName = L"";
	GSettingsHandler->Reports.XML[kReportLayoutAutoSave].FileName      = L"";

	if (GSettingsHandler->Reports.AutoSaveItem[0])
	{
		GSettingsHandler->Reports.CSV[kReportLayoutAutoSave].FileName = GSystemGlobal->ExePath + L"reports\\" +
																  WindowsUtility::GetComputerNetName() + L"\\CSV\\autosaves\\" +
																  Formatting::MakeFileNameCompatible(FrameSelect->cbScanPath->Text.c_str()) + L"_" +
																  Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".csv";
	}

	if (GSettingsHandler->Reports.AutoSaveItem[1])
	{
		GSettingsHandler->Reports.Date[kReportLayoutAutoSave].FileName = GSystemGlobal->ExePath + L"reports\\" +
																   WindowsUtility::GetComputerNetName() + L"\\CSV\\autosaves\\" +
																   Formatting::MakeFileNameCompatible(FrameSelect->cbScanPath->Text.c_str()) + L"_" +
																   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".csv";
	}

	if (GSettingsHandler->Reports.AutoSaveItem[2])
	{
		GSettingsHandler->Reports.HTML[kReportLayoutAutoSave].FileName = GSystemGlobal->ExePath + L"reports\\" +
																   WindowsUtility::GetComputerNetName() + L"\\HTML\\autosaves\\" +
																   Formatting::MakeFileNameCompatible(FrameSelect->cbScanPath->Text.c_str()) + L"_" +
																   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".htm";
	}

	if (GSettingsHandler->Reports.AutoSaveItem[3])
	{
		GSettingsHandler->Reports.JSON[kReportLayoutAutoSave].FileName = GSystemGlobal->ExePath + L"reports\\" +
																   WindowsUtility::GetComputerNetName() + L"\\CSV\\autosaves\\" +
																   Formatting::MakeFileNameCompatible(FrameSelect->cbScanPath->Text.c_str()) + L"_" +
																   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".csv";
	}

	if (GSettingsHandler->Reports.AutoSaveItem[4])
	{
		GSettingsHandler->Reports.Text[kReportLayoutAutoSave].FileName = GSystemGlobal->ExePath + L"\\reports\\" +
																   WindowsUtility::GetComputerNetName() + L"\\text\\autosaves\\" +
																   Formatting::MakeFileNameCompatible(FrameSelect->cbScanPath->Text.c_str()) + L"_" +
																   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".txt";
	}

	if (GSettingsHandler->Reports.AutoSaveItem[5])
	{
		GSettingsHandler->Reports.Tree[kReportLayoutAutoSave].FileName = GSystemGlobal->ExePath + L"reports\\" +
																   WindowsUtility::GetComputerNetName() + L"\\tree\\autosaves\\" +
																   Formatting::MakeFileNameCompatible(FrameSelect->cbScanPath->Text.c_str()) + L"_" +
																   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".txt";
	}

	if (GSettingsHandler->Reports.AutoSaveItem[6])
	{
		GSettingsHandler->Reports.Xinorbis[kReportLayoutAutoSave].FileName = GSystemGlobal->ExePath + L"reports\\" +
																	  WindowsUtility::GetComputerNetName() + L"\\xinorbis\\autosaves\\" +
																	  Formatting::MakeFileNameCompatible(FrameSelect->cbScanPath->Text.c_str()) + L"_" +
																	  Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".zsr2";
	}



	if (GSettingsHandler->Reports.AutoSaveItem[7])
	{
		GSettingsHandler->Reports.XML[kReportLayoutAutoSave].FileName = GSystemGlobal->ExePath + L"reports\\" +
																  WindowsUtility::GetComputerNetName() + L"\\XML\\autosaves\\" +
																  Formatting::MakeFileNameCompatible(FrameSelect->cbScanPath->Text.c_str()) + L"_" +
																  Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".xml";
	}

	GReportHandler->AutoSave(FrameSelect->cbScanPath->Text.c_str(), data_source,
							 GSettingsHandler->Reports.CSV[kReportLayoutAutoSave], GSettingsHandler->Reports.Date[kReportLayoutAutoSave],
							 GSettingsHandler->Reports.HTML[kReportLayoutAutoSave], GSettingsHandler->Reports.JSON[kReportLayoutAutoSave],
							 GSettingsHandler->Reports.Text[kReportLayoutAutoSave], GSettingsHandler->Reports.Tree[kReportLayoutAutoSave],
							 GSettingsHandler->Reports.Xinorbis[kReportLayoutAutoSave], GSettingsHandler->Reports.XML[kReportLayoutAutoSave]);
}

/*

procedure TfrmMain.FormCreate(Sender: TObject);
var
  t : integer;
  param, s : string;

begin
  TGLobal.InitialiseGlobalText;
  Init;
  TGLobal.InitialiseSortCode;

  GXGuiUtil := TGuiUtil.Create(GSystemGlobal.ExePath + 'data\system\images\');

  Randomize;
  CreateReportObjects; // needs to be before frames!

  CreateFrames;
  ConfigureObjects;

  // ===========================================================================

  for t := 0 to __FileCategoriesCount do
	FHCCStatus[t] := True;

  // ===========================================================================

  if XSettings.HistorySettings.Enabled then begin
    tbToggleFH.Enabled    := True;
    tbToggleFH.ImageIndex := 6;

    XSettings.System.UserEnabledFH := True;
  end
  else begin
    tbToggleFH.Enabled    := False;
    tbToggleFH.ImageIndex := 5;

    XSettings.System.UserEnabledFH := False;
  end;

  XSettings.System.UserEnabledVirtual := False;

  // ===========================================================================

  FrameSelect.BuildScanHistoryTable(0);


  if not FileExtensionsObject.LoadFileExtensionLists(XSettings.CustomSettings.SettingsSaveLocation) then
	GLog->Add(L"Failed to load file extension data!");

  if ParamStr(ParamCount) = '/languagedebug' then
	LoadLanguageDetails(XSettings.CurrentLanguage, True)
  else
    LoadLanguageDetails(XSettings.CurrentLanguage, False);

  if ParamStr(ParamCount) = '/debug' then begin
    XSettings.System.Debug := True;

	GLog->Add(L"Debug activated");
  end;

  // ---------------------------------------------------------------------------

  DoPreferenceChanges;
  TXWindows.GetNetworkDrives;

  TXWindows.SetupFormatSettings;

  FormDisplay.PanelInFront := pMainPanelIndex;
  FormDisplay.Source       := -1;

  FrameSelect.BringToFront;

  TryBuildFolderHistoryAvailable;

  // ===========================================================================

  HandleResizing(pScanSelectionPanelIndex);
  FrameSelect.BringToFront;

  // ===========================================================================


  if (ParamStr(1) <> '') then begin
	if UpperCase(ExtractFileExt(ParamStr(1))) = '.ZSR2' then
	  XinorbisScan(dataLatestScan, '', ParamStr(1), ScanTypeNormal, ScanSourceFileXin2Detailed)
    else if UpperCase(ExtractFileExt(ParamStr(1))) = '.ZSR' then
	  XinorbisScan(dataLatestScan, '', ParamStr(1), ScanTypeNormal, ScanSourceFileXinDetailed)
    else begin
      if SysUtils.DirectoryExists(ParamStr(1)) then begin

        param := ParamStr(1);
		if param[length(param)] <> '\' then param := param + '\';

        FrameSelect.ePath.Text := param;
        FrameSelect.sbGoPathClick(Nil);
      end;
    end;
  end;

  if FrameSelect.ePath.Text = '' then
    FrameSelect.ePath.Text := 'C:\';

  if FrameSelect.ePath.Text[2] = ':' then begin
	s := FrameSelect.ePath.Text;

    FrameSelect.dcbexMain.Drive     := s[1];
    FrameSelect.dlbexMain.Directory := s;
  end;


  OnTutorialBarChange('intro');
end;

procedure TfrmMain.Init;
begin
  frmSpread.OnHide        := OnFormClose;
  frmFileAges.OnHide      := OnFormClose;
  frmExplore.OnHide       := OnFormClose;
}

procedure TfrmMain.CreateReportsFrame(aDataIndex : integer);
  GReportText.SetGrids(aDataIndex, FrameReports[aDataIndex].sgNullFiles,
								   FrameReports[aDataIndex].sgNullFolders,
								   FrameReports[aDataIndex].sgTop50Big,
								   FrameReports[aDataIndex].sgTop50Small,
								   FrameReports[aDataIndex].sgTop101BigDate,
								   FrameReports[aDataIndex].sgTop101SmallDate);

  GReportXML.SetGrids(aDataIndex,  FrameReports[aDataIndex].tvFileDates,
								   FrameReports[aDataIndex].sgNullFiles,  FrameReports[aDataIndex].sgNullFolders,    FrameReports[aDataIndex].sgTop50Big,
								   FrameReports[aDataIndex].sgTop50Small, FrameReports[aDataIndex].sgTop101BigDate,  FrameReports[aDataIndex].sgTop101SmallDate,
								   FrameReports[aDataIndex].cbFileDates,  FrameReports[aDataIndex].cbFileDatesUsers, FrameReports[aDataIndex].cbTop101Dates);


  GReportHTML.SetGrids(aDataIndex, FrameReports[aDataIndex].tvFileDates,
								   FrameReports[aDataIndex].sgNullFiles,  FrameReports[aDataIndex].sgNullFolders,    FrameReports[aDataIndex].sgTop50Big,
								   FrameReports[aDataIndex].sgTop50Small, FrameReports[aDataIndex].sgTop101BigDate,  FrameReports[aDataIndex].sgTop101SmallDate,
								   FrameReports[aDataIndex].cbFileDates,  FrameReports[aDataIndex].cbTop101Dates);


  GReportSummary.SetGrids(aDataIndex, FrameReports[aDataIndex].sgNullFiles,
									  FrameReports[aDataIndex].sgNullFolders,
									  FrameReports[aDataIndex].sgDirList,
									  FrameReports[aDataIndex].sgTop50Big,
									  FrameReports[aDataIndex].sgUsers);

  UpdateGUICustomNames(aDataIndex);
end;


procedure TfrmMain.CreateSearchFrame;
  GReportText.SetGrids(dataSearch, FrameSearch.ReportFrame.sgNullFiles,
								   FrameSearch.ReportFrame.sgNullFolders,
								   FrameSearch.ReportFrame.sgTop50Big,
								   FrameSearch.ReportFrame.sgTop50Small,
								   FrameSearch.ReportFrame.sgTop101BigDate,
								   FrameSearch.ReportFrame.sgTop101SmallDate);

  GReportXML.SetGrids(dataSearch,  FrameSearch.ReportFrame.tvFileDates,
								   FrameSearch.ReportFrame.sgNullFiles,  FrameSearch.ReportFrame.sgNullFolders,    FrameSearch.ReportFrame.sgTop50Big,
								   FrameSearch.ReportFrame.sgTop50Small, FrameSearch.ReportFrame.sgTop101BigDate,  FrameSearch.ReportFrame.sgTop101SmallDate,
								   FrameSearch.ReportFrame.cbFileDates,  FrameSearch.ReportFrame.cbFileDatesUsers, FrameSearch.ReportFrame.cbTop101Dates);


  GReportHTML.SetGrids(dataSearch, FrameSearch.ReportFrame.tvFileDates,
								   FrameSearch.ReportFrame.sgNullFiles,  FrameSearch.ReportFrame.sgNullFolders,    FrameSearch.ReportFrame.sgTop50Big,
								   FrameSearch.ReportFrame.sgTop50Small, FrameSearch.ReportFrame.sgTop101BigDate,  FrameSearch.ReportFrame.sgTop101SmallDate,
								   FrameSearch.ReportFrame.cbFileDates,  FrameSearch.ReportFrame.cbTop101Dates);


  GReportSummary.SetGrids(dataSearch, FrameSearch.ReportFrame.sgNullFiles,
									  FrameSearch.ReportFrame.sgNullFolders,
									  FrameSearch.ReportFrame.sgDirList,
									  FrameSearch.ReportFrame.sgTop50Big,
									  FrameSearch.ReportFrame.sgUsers);
end;

5569 :: 4438 */

