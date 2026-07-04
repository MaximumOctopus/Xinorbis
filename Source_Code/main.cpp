//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConstantsGui.h"
#include "ConstantsLanguage.h"
#include "ExecutionParameters.h"
#include "LanguageHandler.h"
#include "main.h"
#include "ScanEngine.h"
#include "SystemGlobal.h"

#include "XFormAbout.h"
#include "XFormFileAges.h"
#include "XFormFileSpread.h"

#include "XFrameExploder.h"
#include "XFrameMap.h"
#include "XFrameProperties.h"
#include "XFrameSearch.h"
#include "XFrameSelect.h"
#include "XFrameStructure.h"
#include "XFrameSummary.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SystemGlobal* GSystemGlobal;

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

	CreateFrames();

	SetLanguageText();
    SetMenuLanguageText();
}


void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
//
}


#pragma region Application_Init
void TFormMain::CreateFrames()
{
	FrameSelect = new TFrameSelect(this);
	FrameSelect->Parent = pMainCanvas;
	FrameSelect->Align = alClient;
	FrameSelect->OnNewScan = std::bind(OnNewScan, std::placeholders::_1);

	FrameSummary = new TFrameSummary(this);
	FrameSummary->Parent = pMainCanvas;
	FrameSummary->Align = alClient;
	FrameSummary->Visible = false;

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

	FrameSearch = new TFrameSearch(this);
	FrameSearch->Parent = pMainCanvas;
	FrameSearch->Align = alClient;
	FrameSearch->Visible = false;

	FrameStructure = new TFrameStructure(this);
	FrameStructure->Parent = pMainCanvas;
	FrameStructure->Align = alClient;
	FrameStructure->Visible = false;
}


void TFormMain::SetLanguageText()
{
	// View Panel
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
	miEReportOptions->Caption        = (GLanguageHandler->Text[kFileTypes] + kEllipsis).c_str();
	miEFileTypes->Caption            = (GLanguageHandler->Text[kFileTypes] + kEllipsis).c_str();
	miECustomiseQuickFolder->Caption = (GLanguageHandler->Text[kCustomiseQuickFolderMenu] + kEllipsis).c_str();

	// == Search Menu ==========================================================================
	miSSearch->Caption       = GLanguageHandler->Text[kSearch].c_str();
	miSWizard->Caption       = (GLanguageHandler->Text[kWizard] + kEllipsis).c_str();
	miSSearchSyntax->Caption = (GLanguageHandler->Text[kSearchSyntax] + kEllipsis).c_str();

	// == View Menu ============================================================================
	miVOpenLastReport->Caption            = GLanguageHandler->Text[kOpenLastReport].c_str();
	miVCopyLastReportToClipboard->Caption = GLanguageHandler->Text[kCopyLastReportToClipboard].c_str();
	miVFolderProperties->Caption          = (GLanguageHandler->Text[kReportOptions] + kEllipsis).c_str();

	miTabTable->Caption                   = GLanguageHandler->Text[kCategories].c_str(); // to do hide/show these on popup menu if data available!"
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

//	miRReportOptions->Caption  = GLanguageHandler->Text[kReportBrowser] + kEllipsis;
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
	miHHelpCats->Caption        = L"Help Cats!";// to do
	miHHelp->Caption            = GLanguageHandler->Text[kHelp].c_str();
	miHContextHelp->Caption     = GLanguageHandler->Text[kContextHelp].c_str();
	miHUserManual->Caption      = GLanguageHandler->Text[kUserManual].c_str();
	miHReference->Caption       = (GLanguageHandler->Text[kReference] + kEllipsis).c_str();
	miHFAQs->Caption            = (L"FAQs" + kEllipsis).c_str();
	miHXinorbisHome->Caption    = GLanguageHandler->Text[kXinorbisHome].c_str();
	miHReportBug->Caption       = GLanguageHandler->Text[kReportBugFeature].c_str();
	miHCheckForUpdates->Caption = GLanguageHandler->Text[kCheckForUpdates].c_str();
	miHAbout->Caption           = GLanguageHandler->Text[kAbout].c_str();
}
#pragma end_region


#pragma region Frame_Select
void __fastcall TFormMain::OnNewScan(const std::wstring folder)
{
	ExecutionParameters ex;

	if (GScanEngine->Execute(true, folder, ex))
	{
		ToggleSoftwareStatus(true);

        PostScan();
	}
}
#pragma end_region


#pragma region Post_Scan
void TFormMain::PostScan()
{
	FrameSummary->Update();

    FrameProperties->Update();
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


void __fastcall TFormMain::tbSettingsClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::tbWizardClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::tbRefreshClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::tbAboutClick(TObject *Sender)
{
	FormAbout->ShowModal();
}
#pragma end_region


#pragma region Bottom_Toolbar
void __fastcall TFormMain::sbHomeClick(TObject *Sender)
{
		  //
}


void __fastcall TFormMain::sbNavigatePreviousClick(TObject *Sender)
{
	  //
}


void __fastcall TFormMain::sbNavigateNextClick(TObject *Sender)
{
		 //
}


void __fastcall TFormMain::SpeedButton4Click(TObject *Sender)
{
	//
}


void __fastcall TFormMain::SpeedButton5Click(TObject *Sender)
{
   //
}


void __fastcall TFormMain::sbReportSummaryClick(TObject *Sender)
{
	 //
}


void __fastcall TFormMain::sbReportCSVClick(TObject *Sender)
{
	 //
}


void __fastcall TFormMain::sbReportHTMLClick(TObject *Sender)
{
 //
}


void __fastcall TFormMain::sbReportTextClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::sbReportTreeClick(TObject *Sender)
{
 //
}


void __fastcall TFormMain::sbReportXMLClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::sbReportSettingsClick(TObject *Sender)
{
//
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
	case 0:
		SetSidePanelDisplay(kNullEntry, 1, kNullEntry, 1);
		break;
	case 1:
		SetSidePanelDisplay(kNullEntry, 2, kNullEntry, 1);
		break;
	case 2:
		SetSidePanelDisplay(kNullEntry, 3, kNullEntry, 1);
		break;
	case 3:
		SetSidePanelDisplay(kNullEntry, 4, kNullEntry, 1);
		break;
	case 4:
		SetSidePanelDisplay(kNullEntry, 5, kNullEntry, 1);
		break;
	case 5:
		SetSidePanelDisplay(kNullEntry, 6, kNullEntry, 1);
		break;
	case 6:
		SetSidePanelDisplay(kNullEntry, 7, kNullEntry, 1);
		break;
	case 7:
		SetSidePanelDisplay(kNullEntry, 8, kNullEntry, 1);
		break;
	}
}


void TFormMain::SetSidePanelDisplay(int WelcomeId, int TaskId, int TaskSubId, bool AddToHistory)
{
	//SetWelcomeDisplay(welcomeID);

	//DoWelcome(welcomeID);

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
{/*
  for t := 1 to SideMenuWelcomeCount do begin
	if t <> welcomeID then begin
	  WelcomeOptions[t].Font.Style := [];
	end;
  end;

  if (welcomeID <> -1) and (welcomeID <= SideMenuWelcomeCount) then
	WelcomeOptions[welcomeID].Font.Style := [fsBold]; */
}


void TFormMain::DoWelcome(int WelcomeId)
{   /*
	if aWelcomeID <> -1 then begin
		case aWelcomeID of
		  1 : begin
				HandleResizing(pScanSelectionPanelIndex);

				FrameSelect.pScanSelection.BringToFront;
			  end;
		  2 : begin
				HandleResizing(pMainFileHistoryPanelIndex);
				FrameFolderHistory.BringToFront;

				FrameFolderHistory.AvailableComputerChange;
			  end;
		  5 : begin
				HandleResizing(pMainWebReportsPanelIndex);
				FrameWebReports.BringToFront;
			  end;
		end;

		if XSettings.System.Tutorial then
		  OnTutorialBarChange(GSystemGlobal.ExePath + 'data\languages\' +
													TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
													'\tutorial\w' + IntToStr(aWelcomeID) + '.dat');
	} */
}


void TFormMain::DoTask(int TaskId, int TaskSubId)
{
	if (TaskId == kNullEntry) return;

	if (TaskId < 99)
	{
		// to do SetTasksDisplay(TaskId);
	}

	switch (TaskId)
	{
	case 1:
		HandleResizing(kMainSummaryPanelIndex);
		FrameSummary->BringToFront();
		break;
	case 2:
		HandleResizing(kMainPropertiesPanelIndex);
		FrameProperties->BringToFront();

		//if aTaskSubID <> NullEntry then
		 // FrameReports.pMainReports.ActivePageIndex := aTaskSubID;

		break;
/*	case 3:
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
	case 4:
		HandleResizing(kMainSearchPanelIndex);

//		FrameSearch.Source := FSource;
		FrameSearch->SetTab(0);
		FrameSearch->BringToFront();
		break;
	case 5:
		HandleResizing(kMainMapPanelIndex);

//		UpdateFrameMap;

		FrameMap->BringToFront();
		break;
	case 6:
		HandleResizing(kMainSearchPanelIndex);

//		FrameSearch.Source := FSource;
		FrameSearch->SetTab(2);
		FrameSearch->BringToFront();
		break;
	case 7:
		HandleResizing(kMainSearchPanelIndex);

//		FrameSearch.Source := FSource;
		FrameSearch->SetTab(3);
		FrameSearch->BringToFront();
		break;
	case 8:
		HandleResizing(kMainExploderPanelIndex);

//		UpdateFrameExploder;

		FrameExploder->BringToFront();
		break;
	}

//	if XSettings.System.Tutorial then
//      OnTutorialBarChange(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
//,												  '\tutorial\t' + IntToStr(aTaskID) + '.dat');
}


void TFormMain::HandleResizing(int NewPanelInFront)
{
	if (PanelInFront != NewPanelInFront/* || PanelSource != Source*/)
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
void __fastcall TFormMain::miFScanClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miFSaveReportsClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miFExitClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Menu_Edit
void __fastcall TFormMain::miESettingsClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miEReportOptionsClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miEFileTypesClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miECustomiseQuickFolderClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Menu_Search
void __fastcall TFormMain::miSSearchClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miSWizardClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miSSearchSyntaxClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Menu_View
void __fastcall TFormMain::miVOpenLastReportClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miVCopyLastReportToClipboardClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miVCategoryColoursClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miVLogsClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miTabTableClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Menu_Reports
void __fastcall TFormMain::miRCustomiseCSVReportClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miRCustomiseHTMLReportClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miRCustomiseTextReportClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miRCustomiseTreeReportClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miRCustomiseXMLReportClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miRReportOptionsClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miRReportBrowserClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miHTMLReportClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Menu_Tools
void __fastcall TFormMain::miTFolderHistoryInfoClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miTBackupXinorbisClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miTAddToContextMenuClick(TObject *Sender)
{
//
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
//
}


void __fastcall TFormMain::miDDuplicatesFileSizeClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miDFolderDetailClick(TObject *Sender)
{
//
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
//
}


void __fastcall TFormMain::miHHelpClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miHContextHelpClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miHUserManualClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miHReferenceClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miHFAQsClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miHXinorbisHomeClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miHReportBugClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::miHCheckForUpdatesClick(TObject *Sender)
{
//
}
#pragma end_region
