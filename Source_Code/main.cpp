//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>

#include "ConstantsGui.h"
#include "ConstantsLanguage.h"
#include "ConstantsSettings.h"
#include "ExecutionParameters.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "main.h"
#include "ReportHandler.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SplashHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"

#include "XFormAbout.h"
#include "XFormCategoryColours.h"
#include "XFormFileAssociations.h"
#include "XFormFileAges.h"
#include "XFormFileSpread.h"
#include "XFormLog.h"
#include "XFormMoreDetail.h"
#include "XFormQuickMenuBuilder.h"
#include "XFormSettings.h"

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

extern LanguageHandler *GLanguageHandler;
extern ReportHandler *GReportHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;
extern SplashHandler *GSplashHandler;
extern SystemGlobal *GSystemGlobal;

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

    ConfigureObjects();

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
	miEReportOptions->Caption        = (GLanguageHandler->Text[kReportOptions] + kEllipsis).c_str();
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
#pragma end_region


#pragma region Application_Control
void TFormMain::ToggleSoftwareStatus(int index, bool status) // to do for fsource?
{
	FrameSelect->bScanNow->Enabled        = status;
	FrameSelect->eScanPath->Enabled       = status;
	FrameSelect->bSelect->Enabled         = status;
	FrameSelect->bExcludeFolders->Enabled = status;
	FrameSelect->bExcludeFiles->Enabled   = status;
	FrameSelect->bFavourites->Enabled     = status;
	FrameSelect->bCombine->Enabled        = status;
	FrameSelect->bExplore->Enabled        = status;

  /*	GXGuiUtil.SetButtonImageEnabled(tbReportCSV,      CReportOffStart, status);
	GXGuiUtil.SetButtonImageEnabled(tbReportHTML,     CReportOffStart, status);
	GXGuiUtil.SetButtonImageEnabled(tbReportSummary,  CReportOffStart, status);
	GXGuiUtil.SetButtonImageEnabled(tbReportText,     CReportOffStart, status);
	GXGuiUtil.SetButtonImageEnabled(tbReportTree,     CReportOffStart, status);
	GXGuiUtil.SetButtonImageEnabled(tbReportXML,      CReportOffStart, status);
	GXGuiUtil.SetButtonImageEnabled(tbReportXinorbis, CReportOffStart, status); */

	for (int t = 0; t < kSideMenuTasksCount; t++)
	{
		TaskOptions[t]->Enabled = status;
	}

	tbWizard->Enabled = status;

	for (int t = 0; t < kSideMenuAdvancedCount; t++)
	{
		AdvancedOptions[t]->Enabled = status;
	}

/*	if (FrameReports[aDataIndex])
	{
		FrameReports[aDataIndex]->pMainReports->Enabled         = status;

		FrameReports[aDataIndex]->rbGraphSize->Enabled          = status;
		FrameReports[aDataIndex]->rbGraphQuantity->Enabled      = status;

		FrameReports[aDataIndex]->cbTreeSize->Enabled           = status;
		FrameReports[aDataIndex]->cbTreeQuantity->Enabled       = status;

		FrameReports[aDataIndex]->cbGraphSizeMagnitude->Enabled = status;
		FrameReports[aDataIndex]->cbGraphQtyMagnitude->Enabled  = status;

		FrameReports[aDataIndex]->rbUsersSize->Enabled          = status;
		FrameReports[aDataIndex]->rbUsersQuantity->Enabled      = status;
	} */
}
#pragma end_region


#pragma region Application_Menu
void TFormMain::UpdateMainMenu()
{
/*	miOpenLastReport.Enabled            := (GReportUtility.LastReportFilename <> '');
	miCopyLastReportToClipboard.Enabled := (GReportUtility.LastReportFilename <> '');

	bool status = (GScanEngine->Data[DataSource].Files.size() != 0);

	miHTMLReport->Enabled       = status;
	miXMLReport->Enabled        = status;
	miCSVReport->Enabled        = status;
	miTextReport->Enabled       = status;
	miXinorbisReport->Enabled   = status;
	miTreeReport->Enabled       = status;

	miSaveReports->Enabled      = status;
	miSearchMain->Enabled       = status;
	miSearchWizard->Enabled     = status;

	miDFileSize->Enabled        = status;
	miDDuplicatesName->Enabled  = status;
	miDDuplicatesSize->Enabled  = status;
	miMoreFolderDetail->Enabled = status;
	miFileAges->Enabled         = status;

	miTabTable->Enabled         = status;
	miTabTree->Enabled          = status;
	miTabOther->Enabled         = status;
	miTabFolders->Enabled       = status;
	miTabMagnitude->Enabled     = status;
	miTabFileDates->Enabled     = status;
	miTabHistory->Enabled       = status;
	miTabTop50->Enabled         = status;
	miTabNullFiles->Enabled     = status;
	miTabUsers->Enabled         = status;
	miTabTemp->Enabled          = status;
	miTabNameLength->Enabled    = status; */
}
#pragma end_region


#pragma region Application_Hooks
void TFormMain::OnOpenSettingsTab(int tab)
{
	if (OpenSettings(tab) == 1)
	{
		DoPreferenceChanges();

		FrameSelect->UpdateQuickFolders();

		FrameSearch->RebuildCharts();

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
   // to do	FrameReports[FSource].JustInTimeDisplay(value);
}


void TFormMain::OnBuildInformationDisplay(int value)
{
	switch (value)
	{
	case 0:
		//TDisplayUtility.InformationTabFileDatesTree(FSource,
		//											FrameReports[FSource].cbFileDates.ItemIndex, FrameReports[FSource].cbFileDatesUsers,
		//											True, // or the display won't build!!
		 //	   to do 										FrameReports[FSource].tvFileDates, FrameReports[FSource].vtcFileDates, True, Nil);
		break;
	}
}


void TFormMain::OnStatusBarChange(const std::wstring text)
{
   // to do	sbMain->Panels[0]->Text = text.c_str();
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
	if (FrameMap->DataSource == kDataFolderHistory)      // to do!  i think this should be source aware!
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
// to do		lAdvID->Font->Style = [];
		break;
	case kFormExplore:
//		lAdvID2->Font->Style = [];
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
	// to do FileExtensionsObject.CategoryExtensions.Sort(TComparer<TFileExtension>.Construct(CompareExtensions));
}
#pragma end_region


#pragma region Menu_Utility
void TFormMain::LoadMenu(TPopupMenu *pum, const std::wstring file_name)
{
	TMenuItem *LastNode = nullptr;

	std::wifstream file(file_name);

	if (file)
	{
		std::wstring s(L"");

		while (std::getline(file, s))
		{
			if (!s.empty())
			{
				switch (s[1])
				{
				case L'-':
				{
					TMenuItem *mi = new TMenuItem(pum);
					mi->Caption = L"-";

					if (LastNode == nullptr)
					{
						pum->Items->Add(mi);
					}
					else
					{
						LastNode->Add(mi);
					}

					break;
				}
				case L'{':
				{
					TMenuItem *mi = new TMenuItem(pum);
					mi->Caption = s.substr(1).c_str();
					mi->Enabled = false;

					if (LastNode == nullptr)
					{
						pum->Items->Add(mi);
					}
					else
					{
						LastNode->Add(mi);
					}
					break;
				}
				case L'[':
				{
					TMenuItem *mi = new TMenuItem(pum);
					mi->Caption = s.substr(1).c_str();
					mi->Enabled = true;

					if (LastNode == nullptr)
					{
						pum->Items->Add(mi);
					}
					else
					{
						LastNode->Add(mi);
					}

					LastNode = mi;
					break;
				}
				case L'.':
				{
					TMenuItem *mi = new TMenuItem(pum);

					auto ix = s.find(L'=');

					if (ix != std::wstring::npos)
					{
						mi->Caption = s.substr(0, ix - 1).c_str();

						MenuStrings.push_back(s.substr(ix + 1).c_str());

						if (pum == FrameSearch->puQuickSearch)
						{
							//mi->OnClick = FrameSearch->miQuickSearchClick;   to do
						}
						else
						{
							//mi->OnClick = FrameFolderHistory->miQuickSearchClick; to doto do
						}

						mi->Tag = MenuStrings.size() - 1;
					}
					else
					{
						mi->Caption = s.substr(0, ix - 1).c_str();
					}

					mi->Enabled = true;

					if (LastNode == nullptr)
					{
						pum->Items->Add(mi);
					}
					else
					{
						LastNode->Add(mi);
					}
					break;
				}
				case L'*':
				{
					LastNode = LastNode->Parent;

					break;
				}
				}
			}
		}

		file.close();
	}
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


#pragma region Frame_Exploder
void TFormMain::UpdateFrameExploder()
{
//  lDataSource := FSource;

//	if lDataSource <> FrameExploder.DataSource then
	FrameExploder->Clear();

	if (!FrameExploder->HasData)
	{
		FrameExploder->BeginData(GScanEngine->Data[DataSource].Path.String, -1, 0); // -1 for initial data set

		for (int t = 0; t < FrameProperties->sgFolders->RowCount; t++)
		{
			//FrameExploder->AddData(FrameReports[lDataSource].sgDirList.Cells[1, t],
//								   GScanDetails[lDataSource].GetFolderIndex(FrameReports[lDataSource].sgDirList.Cells[1, t]),
//								   std::to_wstring(FrameReports[lDataSource].sgDirList.Cells[2, t]),
//								   std::to_wstring(FrameReports[lDataSource].sgDirList.Cells[8, t]),
//								   __SpectrumColours[(t - 1) % __SpectrumMod]);
		}

		FrameExploder->EndData();
	}
}
#pragma end_region


#pragma region Frame_Map
void TFormMain::UpdateFrameMap()
{
//  int lDataSource := FSource;

	//  if lDataSource <> FrameMap.DataSource then
	FrameMap->Clear();

  // ====================================================================

	if (!FrameMap->HasData)
	{
		FrameMap->BeginData();

		for (int t = 0; t < FrameProperties->sgFolders->RowCount; t++)
		{
			//FrameMap.AddData(FrameReports[lDataSource].sgDirList.Cells[1, t],
		  //					 std::to_wstring(FrameReports[lDataSource].sgDirList.Cells[2, t]),
			 //				 std::to_wstring(FrameReports[lDataSource].sgDirList.Cells[8, t]),
			 //				 __SpectrumColours[(t - 1) % __SpectrumMod]);
		}

		FrameMap->EndData();
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


void __fastcall TFormMain::SpeedButton4Click(TObject *Sender)
{
	//
}


void __fastcall TFormMain::SpeedButton5Click(TObject *Sender)
{
   //
}


void __fastcall TFormMain::sbReportSummaryClick(TObject *Sender)
{        /*
procedure TfrmMain.lReportSummaryMouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  lFileName : string;

begin
  if tbReportSummary.Enabled then begin
	if FrameFolderHistory.Visible then begin

	  lFileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\summary\quick\' +
				   TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
				   TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' +
				   TUtility.GetTime(GETTIMEFORMAT_FILE) +
				   '.txt';

	  GReportSummary.SaveSummary(FSource, lFileName);

	  GReportUtility.SetLastReport(FSource, lFileName, GScanDetails[FSource].ScanPath, ReportSummary, LayoutUnknown);
	end
	else begin
	  lFileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\summary\quick\' +
				   TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
				   TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' +
				   TUtility.GetTime(GETTIMEFORMAT_FILE) +
				   '.txt';

	  GReportSummary.SaveSummary(FSource, lFileName);

	  GReportUtility.SetLastReport(FSource, lFileName, GScanDetails[FSource].ScanPath, ReportSummary, LayoutUnknown);
	end;
  end;

  if (Button = mbMiddle) then begin
	miOpenLastReportClick(Nil);
  end; */
}


void __fastcall TFormMain::sbReportCSVClick(TObject *Sender)
{    /*
procedure TfrmMain.lReportCSVMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 var
  DT : string;
  lFileName : string;
  tempCSVOptions : TCSVReportOptions;
  lCSVOutput : TStringList;
  lSource : integer;

 begin
  if tbReportCSV.Enabled then begin
    if FrameFolderHistory.Visible then begin

      TLabel(Sender).Font.Style := [fsBold];

      lFileName := TXSaveDialog.Execute(XText[rsCSVFiles] + ' (*.csv)|*.csv',
                                        '.csv',
										TUtility.GetDefaultFileName('.csv', 'csv_' + XText[rsReport]),
                                        GSystemGlobal.AppDataPath);

      if lFileName <> '' then begin
        DT := TConvert.DateTimeFToYYYYMMDDHHMMSS(FrameFolderHistory.FolderHistoryItemSelected);

        ExportTableToCSV(lFileName, TMD5.Generate(UpperCase(FrameFolderHistory.SelectedPath)) + DT + FrameFolderHistory.SelectedComputer);

		GReportUtility.SetLastReport(FSource, lFileName, GScanDetails[FSource].ScanPath, ReportCSV, LayoutUnknown);

        sbMain.Panels[0].Text := XText[rsCSVReportSavedAs] + ': <b>' + lFileName + '</b>';
      end;

      TLabel(Sender).Font.Style := [];
    end
    else begin
	  tempCSVOptions := XSettings.Report.CSVOptions[kReportLayoutQuick];

      if FrameSearch.Visible then begin
        if (GScanDetails[dataSearch].FileCount <> 0) then begin
          lSource   := dataSearch;

          if FrameSearch.ActivePage = 1 then begin
            lFileName := '_' + XText[rsSearch] + '.csv';
          end
          else begin
            tempCSVOptions.CSVData := CDataFileList;

			lFileName := '_' + XText[rsSearch] + '.csv';
          end
        end
        else begin
          ShowXDialog(XText[rsWarning],
                      XText[rsNoDataToExport],
                      XDialogTypeWarning);

          Exit;
        end;
      end
      else begin
        lSource   := FSource;

        lFileName := '.csv';
	  end;

      tempCSVOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\csv\quick\' +
                                 TXFormatting.MakeFileNameCompatible(GScanDetails[lSource].ScanPath) + '_' +
                                 TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) +
                                 lFileName;

      tempCSVOptions.Category := -1;

      lCSVOutput := TStringList.Create;

	  GReportCSV.GenerateCSVReport(lSource, lCSVOutput, tempCSVOptions, kReportLayoutQuick);

      FreeAndNil(lCSVOutput);
    end;
  end;

  if (Button = mbMiddle) then begin
    miOpenLastReportClick(Nil);
  end;
end;       */
}


void __fastcall TFormMain::sbReportDateClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::sbReportHTMLClick(TObject *Sender)
{            /*
procedure TfrmMain.lReportHTMLMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 var
  lFileName : string;
  tempHTMLOptions : THTMLReportOptions;
  lReportOutput : TStringList;

 begin
  tempHTMLOptions := XSettings.Report.HTMLOptions[LayoutQuick];

  if FrameFolderHistory.Visible then begin
    Assert(Sender <> Nil, 'lFHReportHTMLMouseDown :: sender is nil');

    TLabel(Sender).Font.Style := [fsBold];

	if FrameFolderHistory.ActivePage = TabFHCompare then begin
      lFileName := TXFormatting.MakeFileNameCompatible(FrameFolderHistory.SelectedPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.htm';

      XSettings.Report.HTMLCompareOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML_Compare\quick\' + lFileName;

      GReportHTML.GenerateHTMLCompareReport(XSettings.Report.HTMLCompareOptions,
                                            FrameFolderHistory.SelectedPath, FrameFolderHistory.eFHCompareSearch.Text, FrameFolderHistory.bFHCompareLeft.Caption, FrameFolderHistory.bFHCompareRight.Caption,
                                            FrameFolderHistory.QuickCompareA, FrameFolderHistory.QuickCompareB,
                                            FrameFolderHistory.sgFHCompareLeft, FrameFolderHistory.sgFHCompareRight);

      if XSettings.Report.HTMLCompareOutput <> '' then
        TXWindows.ExecuteFile(0, '"' + XSettings.Report.HTMLCompareOutput + '"', '"' + GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML_Compare\quick\' + lFileName + '"', '')
      else
        TXWindows.ExecuteFile(0, '"' + GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML_Compare\quick\' + lFileName + '"', '', '');

      sbMain.Panels[0].Text := XText[rsHTMLCReportSavedAs] + ': <b>' + GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML_Compare\quick\' + lFileName + '</b>';
    end
    else begin
      lFileName := TXFormatting.MakeFileNameCompatible(FrameFolderHistory.SelectedPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.htm';

      tempHTMLOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML\quick\FH_' + lFileName;

      GReportHTML.GenerateHTMLReport(FSource, tempHTMLOptions, FrameFolderHistory.bFHISelect.Caption);
    end;

    TLabel(Sender).Font.Style := [];
  end
  else begin
    if FrameSearch.Visible then begin
      if (GScanDetails[dataSearch].FileCount <> 0) then begin
        if FrameSearch.ActivePage = 1 then begin
          tempHTMLOptions.FileName := TXFormatting.MakeFileNameCompatible(XText[rsSearchResults] + '_' + GScanDetails[dataSearch].ScanPath) + '_' +
                                      TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '_' + XText[rsSearch] + '.htm';

          BuildOpenHTMLReport(dataSearch, tempHTMLOptions);
        end
        else begin
          lFileName := TXFormatting.MakeFileNameCompatible(XText[rsSearchResults] + '_' + GScanDetails[dataSearch].ScanPath) + '_' +
                     TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '_' + XText[rsSearch] + '.htm';

          lReportOutput := TStringList.Create;

          GReportHTML.GenerateHTMLFileReport(dataSearch, lReportOutput, XText[rsSearchResults] + ' "' + FrameSearch.SearchText + '"', lFileName);

          FreeAndNil(lReportOutput);
        end;
      end
      else begin
        ShowXDialog(XText[rsWarning],
                    XText[rsNoDataToExport],
                    XDialogTypeWarning);

        Exit;
      end;
    end
    else begin
      BuildOpenHTMLReport(FSource, tempHTMLOptions);
    end;
  end;

  if (Button = mbMiddle) then begin
	miOpenLastReportClick(Nil);
  end;
end;    */
}


void __fastcall TFormMain::sbReportJSONClick(TObject *Sender)
{
//
}


void __fastcall TFormMain::sbReportTextClick(TObject *Sender)
{                           /*
procedure TfrmMain.lReportTextMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  tempTextOptions : TTextReportOptions;
  lCSVOptions  : TCSVReportOptions;
  lHTMLOptions : THTMLReportOptions;
  lXinOptions  : TXinorbisReportOptions;
  lXMLOptions  : TXMLReportOptions;
  lTreeOptions : TTreeReportOptions;
  lSource : integer;
  lFileName : string;

begin
  tempTextOptions := XSettings.Report.TextOptions[kReportLayoutQuick];

  if Button = mbMiddle then
    tempTextOptions.TextAutoOpen := True;

  if FrameFolderHistory.Visible then begin
    tempTextOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\text\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
                                TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

    FrameFolderHistory.SaveReports(tempTextOptions, lCSVOptions, lHTMLOptions, lXinOptions, lXMLOptions, lTreeOptions);
  end
  else begin
    if FrameSearch.Visible then begin
      lFileName := '_' + XText[rsSearch] + '.txt';

      tempTextOptions.Special := FrameSearch.SearchText;

      if FrameSearch.ActivePage = 1 then begin
        lSource   := dataSearch;
      end
      else begin
        lSource   := FSource;
      end;
    end
    else begin
      lSource   := FSource;

      lFileName := '.txt';
    end;

    tempTextOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\text\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[lSource].ScanPath) + '_' +
                                TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) +
                                lFileName;

    FrameReports[lSource].SaveReports(tempTextOptions, lCSVOptions, lHTMLOptions, lXinOptions, lXMLOptions, lTreeOptions);
  end;

  if tempTextOptions.TextAutoOpen then
    miOpenLastReportClick(Nil);
end;*/
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

		tro.FileName = GSystemGlobal->AppDataPath + L"reports\\" +
					   WindowsUtility::GetComputerNetName() + L"\\tree\\quick\\" +
					   Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
					   Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".txt";

		GReportHandler->SaveTree(tro, DataSource, false, auto_open);
	}
}

	 /*
procedure TfrmMain.lReportXinorbisMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 var
  lTextOptions : TTextReportOptions;
  lCSVOptions  : TCSVReportOptions;
  lHTMLOptions : THTMLReportOptions;
  lXMLOptions  : TXMLReportOptions;
  lTreeOptions : TTreeReportOptions;
  tempXinorbisOptions : TXinorbisReportOptions;

 begin
  tempXinorbisOptions := XSettings.Report.XinorbisOptions[LayoutQuick];
  tempXinorbisOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\xinorbis\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
								  TUtility.GetDate(DateTimeFormat::YYYYMMDD) + '_' + TUtility.GetTime(DateTimeFormat::File) + '.zsr2';

  if Button = mbMiddle then
	tempXinorbisOptions.XinorbisAutoOpen := True;

  if FrameReports[FSource].SaveReports(lTextOptions, lCSVOptions, lHTMLOptions, tempXinorbisOptions, lXMLOptions, lTreeOptions) then
	GReportUtility.SetLastReport(FSource, lTreeOptions.Filename, GScanDetails[FSource].ScanPath, ReportTree, LayoutUnknown);

  if tempXinorbisOptions.XinorbisAutoOpen then
	miOpenLastReportClick(Nil);
end;  */


void __fastcall TFormMain::sbReportXMLMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{                                   /*
procedure TfrmMain.lReportXMLMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  DT : string;
  lFileName : string;
  tempXMLOptions : TXMLReportOptions;
  lReportOutput : TStringList;
  lSource : integer;

begin
  if tbReportXML.Enabled then begin
	if FrameFolderHistory.Visible then begin

	  TLabel(Sender).Font.Style := [fsBold];

	  if (FrameFolderHistory.tpFHMain.ActivePageIndex = TabFHMainSearch) and
		 (FrameFolderHistory.tsFHSearch.ActivePageIndex = TabFHCompare) then begin
		sbFHCXMLReportClick(nil);
	  end
	  else begin
		lFileName := TXSaveDialog.Execute(XText[rsXMLFiles] + ' (*.xml)|*.xml',
										  '.xml',
										  TUtility.GetDefaultFileName('.xml', 'xml_' + XText[rsReport]),
										  GSystemGlobal.AppDataPath);

		if lFileName <> '' then begin
		  DT := TConvert.DateTimeFToYYYYMMDDHHMMSS(FrameFolderHistory.FolderHistoryItemSelected);

		  ExportTableToXML(lFileName, TMD5.Generate(UpperCase(FrameFolderHistory.SelectedPath)) + DT + FrameFolderHistory.SelectedComputer);

		  GReportUtility.SetLastReport(FSource, lFileName, GScanDetails[FSource].ScanPath, ReportXML, LayoutUnknown);

		  sbMain.Panels[0].Text := XText[rsXMLReportSavedAs] + ': <b>' + lFileName + '</b>';
		end;
	  end;

	  TLabel(Sender).Font.Style := [];
	end
	else begin
	  tempXMLOptions := XSettings.Report.XMLOptions[LayoutQuick];

	  if FrameSearch.Visible then begin
		if (GScanDetails[dataSearch].FileCount <> 0) then begin

		  lSource   := dataSearch;

		  lFileName := '_' + XText[rsSearch] + '.xml';

		  tempXMLOptions.Special := FrameSearch.SearchText;

		  if FrameSearch.ActivePage = 1 then begin
		  end
		  else begin
			tempXMLOptions.XMLData := CDataFileList;
		  end;
		end
		else begin
		  ShowXDialog(XText[rsWarning],
					  XText[rsNoDataToExport],
					  XDialogTypeWarning);

		  Exit;
		end;
	  end
	  else begin
		lSource   := FSource;

		lFileName := '.xml';
	  end;

	  tempXMLOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\xml\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[lSource].ScanPath) + '_' +
								 TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) +
								 lFileName;

	  lReportOutput := TStringList.Create;

	  if tempXMLOptions.XMLData = CDataSummary then
		GReportXML.GenerateXMLOutput(lSource, tempXMLOptions, lReportOutput)
	  else
		GReportXML.GenerateXMLOutputFileList(tempXMLOptions.FileName, lReportOutput, lSource, kReportLayoutQuick);

	  FreeAndNil(lReportOutput);
	end;
  end;

  if (Button = mbMiddle) and not(tempXMLOptions.XMLAutoOpen) then begin
	miOpenLastReportClick(Nil);
  end;
end; */
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
	HandleResizing(kScanSelectionPanelIndex);

	//FrameSelect->pScanSelection->BringToFront();

	SetSidePanelDisplay(1, kNullEntry, kNullEntry, 1);
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
{      /*
ocedure TfrmMain.miSearchWizardClick(Sender: TObject);
var
  s : string;

begin
  s := DoSearchWizard;

  if s <> '' then begin

	case FSource of
	  dataLatestScan    : begin
							if (GScanDetails[FSource].Files.Count <> 0) then begin
							  lTaskID1Click(lTaskID4);

							  FrameSearch.DoSearch(s);
							end;
						  end;
	 dataFolderHistory  : begin
							if (FrameFolderHistory.tpFHMain.ActivePageIndex = TabFHMainSearch) and
							   (FrameFolderHistory.tsFHSearch.ActivePageIndex = TabFHCompare) then begin
							  FrameFolderHistory.eFHCompareSearch.Text := s;

							  FrameFolderHistory.sbFHCompareSearchClick(FrameFolderHistory.sbFHCompareSearch);
							end
							else begin
							  lTaskID1Click(lTaskID4);

							  FrameSearch.DoSearch(s);
							end;
						  end;
	end;
  end; */
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


void __fastcall TFormMain::miLang1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;


	// TO DO XSettings.CurrentLanguage := TMenuItem(Sender).Tag;
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
	WindowsUtility::ExecuteFile(L"http://www.xinorbis.co.uk/index.htm", L"");
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




/*
{
      ZeemSpace - Hard Disk analyser

      ** xinorbis - Renamed February 28th 2002 **

      (c) Paul Alan Freshney 2002-2003
      (c) Aardvark Digital 2002-2003

  Delphi 7 convert, September 10th 2003

  Original Started: January 6th 2002
     Last Modified: September 9th 2003

  Version2

             Started: September 10th 2003
     Last Modiucfied: July 8th 2004

  Version3+

           Started: February 27th 2005
     Last Modified: February 14th 2014

  Version 6.1

           Started: March 6th 2014
     Last Modified: March 6th 2014

  Version 6.2 (Unicode vesion)

           Started: September 25th 2014
     Last Modified: September 25th 2014

  Version 7.0

           Started: December 16th 2015
     Last Modified: December 16th 2015

  Migration to Delphi 2007, December 7th 2012

  Version 8.0

  Migration to Delphi 10.1 Berlin

		   Started: October 8th 2016
	 Last Modified: June 9th 2019

  Version 8.3.0

		   Started: January 6th 2020

  4596 (45520)
}


const
  SideMenuWelcomeCount  = 2;
  SideMenuTasksCount    = 8;
  SideMenuAdvancedCount = 3;


type
  TFormDisplay = record
				   PanelInFront : integer;
				   Source       : integer;
				 end;

  private
    FSource : integer;

    WelcomeOptions  : array[1..SideMenuWelcomeCount] of TLabel;
	TaskOptions     : array[1..SideMenuTasksCount] of TLabel;
	AdvancedOptions : array[1..SideMenuAdvancedCount] of TLabel;

    LanguageMenus   : array[0..13] of TMenuItem;

    FormDisplay     : TFormDisplay;

    NavigationHistory : TStringList;

    FrameSummary    : array[0..1] of TFrameSummary;
    FrameNavigation : array[0..1] of TFrameNavigation;
    FrameReports    : array[0..1] of TFrameReports;

	GUpdateFolderHistoryUpdateThread : TUpdateFolderHistoryUpdateThread;

    procedure Init;

    procedure CreateFrames;
    procedure CreateSummaryFrame(aDataIndex : integer);
    procedure CreateNavigationFrame(aDataIndex : integer);
    procedure CreateReportsFrame(aDataIndex : integer);
    procedure CreateSearchFrame;

    procedure DestroyFrames;

    procedure DestroyReports;

    procedure BuildSummary(aDataIndex, aFileCatMode : integer);

    procedure RequestNewScan(aDataIndex : integer; aFromFile : boolean; const aNewPath : string);
    procedure RequestNewCombineScan(const aStatus : integer);
    procedure RequestNewSummary(aDataIndex : integer; const aAutoOpen : integer);
    procedure RequestNewFHPath(const aPath : string);
    procedure RequestNewSearch(aDataIndex : integer; const aNewSearch : string);

    procedure ScanOnFoundNull(aDataIndex : integer; const aFileName : string);
    procedure ScanOnFoundTemp(aDataIndex : integer; const aFileName, aSizeWords, aSize : string);
    procedure ScanOnProgress(const aCount : integer);

    procedure TryBuildFolderHistoryAvailable;

    procedure OnJustInTime(aValue : integer);
    procedure OnNewReport;
    procedure OnBuildInformationDisplay(aValue : integer);
    procedure OnMenuChange(const aNewText : string; aMenuItem, aState : integer);
    procedure OnOpenSettingsTab(const aNewTab : integer);
    procedure OnOpenSearchWizard(const aStatus : integer);
    procedure OnReportsChange(const aNewTab : integer);
    procedure OnStatusBarChange(const aText : string);
    procedure OnTutorialBarChange(const aText : string);
    procedure OnResetDisplay(aStatus : integer);
    procedure OnChartsHaveChanged;

    procedure DoWelcome(aWelcomeID : integer);
    procedure DoTask(aTaskID, aTaskSubID : integer);

    procedure OnFormClose(const aForm : integer);
    procedure OnExtSetSidePanelDisplay(welcomeID, taskID, tasksubID, canAddToHistory : integer);
    procedure OnProcessWindowProgressChange(const aProgress : integer);
    procedure ScanFromFolderHistory(const aScanPath, aTableName : string; aFileHistoryDate : string);
    procedure OnUpdateHistoryFinished;

	procedure OnProcessWindowStatusChange(const aWindow, aStatus : integer);

    function  OnGetLeftOffset: integer;
    function  OnGetTopOffset: integer;
    function  IsFolderHistoryRunning: boolean;

    procedure NewSourceAvailable(aSource : integer);
    procedure ActivateSource(aSource : integer);
    procedure DeactivateSource(aSource : integer);

    procedure DoUpdateBalloon;
    procedure UpdateMainMenu;

    procedure UpdateFrameMap;
    procedure UpdateFrameExploder;
  public
  end;

const
  CReportHTML = 0;
  CReportCSV  = 1;
  CReportText = 3;
  CReportTree = 5;

  CAOSpread   = 0;
  CAOExplore  = 3;
  CAOFileAges = 4;

  CReportOffStart = 7;

  CToolbarSaveOff   = 0;
  CToolbarSaveOn    = 9;
  CToolbarPrefsOff  = 1;
  CToolbarPrefsOn   = 10;
  CToolbarWizardOff = 5;
  CToolbarWizardOn  = 8;


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

  Caption               := 'xinorbis :: ' + x8Title + ' / ' + x8Date;
  sbMain.Panels[0].Text := XText[rsWelcomeTo] + ' Xinorbis <b>' + x8Version + '</b> / <b>' + x8Date + '</b>. (c) Paul Alan Freshney 2002-' + TUtility.GetCurrentYear;

  XinorbisZip           := TZipFiles.Create;

  CreateObjects;

  XSettings.LoadBasic;

  CreateReportObjects; // needs to be before frames!

  CreateFrames;
  ConfigureObjects;

  // ===========================================================================

  for t := 0 to __FileCategoriesCount do
    FHCCStatus[t] := True;

  // ===========================================================================

  FrameSelect.SetupQuickFolders;

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
    TMSLogger.Info('Failed to load file extension data!');

  if ParamStr(ParamCount) = '/languagedebug' then
    LoadLanguageDetails(XSettings.CurrentLanguage, True)
  else
    LoadLanguageDetails(XSettings.CurrentLanguage, False);

  if ParamStr(ParamCount) = '/debug' then begin
    XSettings.System.Debug := True;

    TMSLogger.Info('Debug activated');
  end;

  // ---------------------------------------------------------------------------

  LoadFileExtensionData;
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

  GXGuiUtil.SetButtonOffImage(FrameSearch.sbSCAccessed,   CImageAccessed);
  GXGuiUtil.SetButtonOffImage(FrameSearch.sbSCModified,   CImageModified);
  GXGuiUtil.SetButtonOffImage(FrameSearch.sbSCOwner,      CImageOwner);
  GXGuiUtil.SetButtonOffImage(FrameSearch.sbSCAttributes, CImageAttributes);

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

  // ===========================================================================

  DoUpdateBalloon;

  OnTutorialBarChange('intro');
end;


procedure TfrmMain.Xinorbis1Click(Sender: TObject);
begin
  {$IFDEF debug}
  ShowXDialog('Debug', 'Dialog test', XDialogTypeXinorbis);
  {$ENDIF}
end;


procedure TfrmMain.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  trayIcon.Visible := False;

  // ===========================================================================

  FrameSelect.SaveSettings;

  FrameFolderHistory.SaveSettings;

  FrameReports[dataLatestScan].SaveSettings;

  if Assigned(FrameReports[dataFolderHistory]) then
    FrameReports[dataFolderHistory].SaveSettings;

  // ===========================================================================

  FolderHistoryAvailable.Clear;

  XSettings.SaveBasic;

  if XSettings.Database.UseODBC then
    CloseODBC;

  Action := caFree;
end;


procedure TfrmMain.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
    CanClose := False;

    ShowXDialog(XText[rsWarning], XText[rsPleaseWaitFolderHistory], XDialogTypeXinorbis);
  end
  else if GWebReportsThread <> Nil then begin
    CanClose := False;

    ShowXDialog(XText[rsXinorbisIsBusy],
                XText[rsPleaseWaitWebReports],
                XDialogTypeXinorbis);
  end
  else
    CanClose := True;
end;


procedure TfrmMain.FormDestroy(Sender: TObject);
begin
  DestroyFrames;
  DestroyReports;

  FreeAndNil(GXinorbisScan);
  FreeAndNil(GXGuiUtil);
  FreeAndNil(GSystemGlobal);

  FreeAndNil(GScanDetails);
  FreeAndNil(FileExtensionsObject);

  XSettings.Free;

  TUtility.StringListClear(NetworkDrivesList);
  NetworkDrivesList.Free;

  FolderHistory.Free;
  FolderHistoryAvailable.Free;

  ScanHistory.Free;

  TUtility.StringListClear(MenuStrings);
  MenuStrings.Free;

  TUtility.StringListClear(NavigationHistory);
  NavigationHistory.Free;

  TUtility.StringListClear(HGraphData);
  HGraphData.Free;
  TUtility.StringListClear(FHGraphData);
  FHGraphData.Free;

  FreeAndNil(XinorbisZip);

  TLanguageHandler.Free;
end;


procedure TfrmMain.Information1Click(Sender: TObject);
begin
  {$IFDEF debug}
  ShowXDialog('Debug', 'Dialog test', XDialogTypeInformation);
  {$ENDIF}
end;


procedure TfrmMain.Init;
begin
  frmSpread               := TfrmSpread.Create(Self);
  frmFileAges             := TfrmFileAges.Create(Self);
  frmExplore              := TfrmExplore.Create(Self);

  frmSpread.OnHide        := OnFormClose;
  frmFileAges.OnHide      := OnFormClose;
  frmExplore.OnHide       := OnFormClose;

  tbSourceFolderHistory.Caption := XText[rsFolderHistory];

  {$IFNDEF debug}
  miDebug.Visible  := False;
  {$ENDIF}

  lDataSource.Caption           := XText[rsDataSource];
  tbSourceLive.Caption          := XText[rsScan];

  // == File Menu ============================================================================

  miScan.Caption                      := XText[rsScan] + rsEllipsis;
  miSaveReports.Caption               := XText[rsSaveReports] + rsEllipsis;
  Exit1.Caption                       := '&' + XText[rsExit];

  // == Search Menu ==========================================================================

  miSearchMain.Caption                := XText[rsSearch];
  miSearchWizard.Caption              := XText[rsWizard] + rsEllipsis;

  // == View Menu ============================================================================

  miOpenLastReport.Caption            := XText[rsOpenLastReport];
  miCopyLastReportToClipboard.Caption := XText[rsCopyLastReportToClipboard];
  miReportOptions.Caption             := XText[rsReportOptions] + rsEllipsis;
  miReportBrowser.Caption             := XText[rsReportBrowser] + rsEllipsis;
  InformationSection1.Caption         := XText[rsFolderProperties];

  miTabTable.Caption                  := XText[rsCategories]; // to do hide/show these on popup menu if data available!"
  miTabTree.Caption                   := XText[rsType];
  miTabOther.Caption                  := XText[rsExtensions];
  miTabFolders.Caption                := XText[rsFolders];
  miTabMagnitude.Caption              := XText[rsMagnitude];
  miTabFileDates.Caption              := XText[rsDates];
  miTabHistory.Caption                := XText[rsHistory];
  miTabTop50.Caption                  := XText[rsTop101];
  miTabNullFiles.Caption              := XText[rsNull];
  miTabUsers.Caption                  := XText[rsUsers];
  miTabTemp.Caption                   := XText[rsTemp];
  miTabNameLength.Caption             := XText[rsFileNameLength];

  miShowSearchSyntax.Caption          := XText[rsSearchSyntax] + rsEllipsis;
  miShowCategoryColours.Caption       := XText[rsCategoryColours] + rsEllipsis;
  miViewLogFolder.Caption             := XText[rsLogs] + rsEllipsis;

  // == Reports ================================================================

  miNewReportSM.Caption               := XText[rsNew];
  miHTMLReport.Caption                := XText[rsHTMLReport];
  miXMLReport.Caption                 := XText[rsXMLReport];
  miCSVReport.Caption                 := XText[rsCSVReport];
  miTextReport.Caption                := XText[rsTextReport];
  miTreeReport.Caption                := XText[rsTreeReport];

  miMainReports.Caption               := XText[rsReport];
  miEditCSVReports.Caption            := XText[rsCustomise] + ' CSV ' + XText[rsReport];
  miEditHTMLReports.Caption           := XText[rsCustomise] + ' HTML ' + XText[rsReport];
  miEditTextReports.Caption           := XText[rsCustomise] + ' ' + XText[rsText] + ' ' + XText[rsReport];
  miEditTreeReports.Caption           := XText[rsCustomise] + ' ' + XText[rsTree] + ' ' + XText[rsReport];
  miEditXMLReports.Caption            := XText[rsCustomise] + ' XML ' + XText[rsReport];

  // == Detail ===============================================================================

  miDFileSize.Caption        := XText[rsFileSizeSpread] + rsEllipsis;
  miDDuplicatesName.Caption  := XText[rsDuplicatesFileName];
  miDDuplicatesSize.Caption  := XText[rsDuplicatesFileSize];
  miMoreFolderDetail.Caption := XText[rsFolderDetail] + rsEllipsis;
  miFileAges.Caption         := XText[rsFileAge] + rsEllipsis;

  // == Edit =================================================================================

  miPreferences.Caption                        := XText[rsSettings] + rsEllipsis;
  miFileAssociations.Caption                   := XText[rsFileTypes] + rsEllipsis;
  miCustomiseQuickFolderMenu.Caption           := XText[rsCustomiseQuickFolderMenu] + rsEllipsis;
  miFHInfo.Caption                             := XText[rsFolderHistoryInfo] + rsEllipsis;
  miBackupData.Caption                         := XText[rsBackupYourXinorbisData];
  miLanguage.Caption                           := XText[rsLanguage];
  miAddXinorbistoExplorerToContextMenu.Caption := XText[rsAddXinorbisToExplorerContextMenu];

  // == Help =================================================================================

  miTutorial.Caption         := XText[rsTutorial];
//  miDonate.Caption           := XText[rsPurchaseXinorbis];
  Help2.Caption              := XText[rsHelp];
  miContextHelp.Caption      := XText[rsContextHelp];
  miUserManual.Caption       := XText[rsUserManual];
  miReference.Caption        := XText[rsReference] + rsEllipsis;
  miXinorbisHome.Caption     := XText[rsXinorbisHome];
  miHelpSendFeedback.Caption := XText[rsReportBugFeature];
  Checkforupdate1.Caption    := XText[rsCheckForUpdates];
  About1.Caption             := XText[rsAbout];

  // =========================================================================================

  lWelcomeScan.Caption          := XText[rsScanDriveFolder];
  lWelcomeFolderHistory.Caption := XText[rsFolderHistory];

  lTaskID1.Caption              := XText[rsSummary];
  lTaskID2.Caption              := XText[rsFolderProperties];
  lTaskID3.Caption              := XText[rsFolderStructure];
  lTaskID4.Caption              := XText[rsSearch];
  lTaskID5.Caption              := XText[rsFolderMap];

  lTaskID6.Caption              := XText[rsDuplicatesFileName];
  lTaskID7.Caption              := XText[rsDuplicatesFileSize];

  lTaskID8.Caption              := XText[rsFolderExploder];

  lAdvID1.Caption               := XText[rsFileSizeSpread] + rsEllipsis;
  lAdvID2.Caption               := XText[rsFolderDetail] + rsEllipsis;
  lAdvID3.Caption               := XText[rsFileAge] + rsEllipsis;

  File1.Caption              := XText[rsFile];
  miEdit.Caption             := XText[rsEdit];
  Edit1.Caption              := XText[rsTools];
  miSearch.Caption           := XText[rsSearch];
  View1.Caption              := XText[rsView];
  Help1.Caption              := XText[rsHelp];
  miOpenCustomReport.Caption := XText[rsOpen] + rsEllipsis;
  miCustomReport.Caption     := XText[rsCustom] + rsEllipsis;
  miDetail.Caption           := XText[rsDetail];

  advSource.Text             := '<P align="center"><b>' + XText[rsWelcome] + '</b></P>';
  advViews.Text              := '<P align="center"><b>' + XText[rsView] + '</b></P>';

  // =========================================================================================

  tbNavigatePrevious.Hint := XText[rsHintM1];
  tbNavigateNext.Hint     := XText[rsHintM2];
  tbHome.Hint             := XText[rsHintM3];

  tbPrivacy.Hint          := XText[rsHintM4] + ' [' + XText[rsDisabled] + ']';
  tbToggleFH.Hint         := XText[rsHintM5] + ' [' + XText[rsEnabled] + ']';
  tbToggleVirtual.Hint    := XText[rsIgnoreVirtualFolders] + ' [' + XText[rsEnabled] + ']';

  // =========================================================================================

  tbReportSummary.Hint     := XText[rsSummary];
  tbReportCSV.Hint         := XText[rsCSVReport];
  tbReportHTML.Hint        := XText[rsHTMLReport];
  tbReportText.Hint        := XText[rsTextReport];
  tbReportTree.Hint        := XText[rsTreeReport];
  tbReportXML.Hint         := XText[rsXMLReport];
  tbReportPreferences.Hint := XText[rsReport] + ' ' + XText[rsSettings];
end;





procedure TfrmMain.CreateFrames;
begin
  CreateSummaryFrame(dataLatestScan);
  CreateNavigationFrame(dataLatestScan);
  CreateReportsFrame(dataLatestScan);

  FrameSelect  := TFrameSelect.Create(Self);
  FrameSelect.Parent           := Panel2;
  FrameSelect.Align            := alClient;
  FrameSelect.GetLeftOffset    := OnGetLeftOffset;
  FrameSelect.GetTopOffset     := OnGetTopOffset;
  FrameSelect.OnChangeFHPath   := RequestNewFHPath;
  FrameSelect.OnNewScan        := RequestNewScan;
  FrameSelect.OnNewCombineScan := RequestNewCombineScan;
  FrameSelect.Init;

  CreateSearchFrame;

  FrameWebReports  := TFrameWebReports.Create(Self);
  FrameWebReports.Parent  := Panel2;
  FrameWebReports.Visible := False;

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
  FrameFolderHistory.OnChartsHaveChanged           := OnChartsHaveChanged;
end;


procedure TfrmMain.CreateSummaryFrame(aDataIndex : integer);
begin
  FrameSummary[aDataIndex] := TFrameSummary.Create(Self);
  FrameSummary[aDataIndex].Name               := 'FrameSummary' + IntToStr(aDataIndex);
  FrameSummary[aDataIndex].Parent             := Panel2;
  FrameSummary[aDataIndex].Source             := aDataIndex;
  FrameSummary[aDataIndex].Visible            := False;
  FrameSummary[aDataIndex].Init;
  FrameSummary[aDataIndex].OnReportsChange    := OnReportsChange;
  FrameSummary[aDataIndex].OnSetStatusBarText := OnStatusBarChange;
end;


procedure TfrmMain.CreateNavigationFrame(aDataIndex : integer);
begin
  FrameNavigation[aDataIndex]  := TFrameNavigation.Create(Self);
  FrameNavigation[aDataIndex].Name          := 'FrameNavigation' + IntToStr(aDataIndex);
  FrameNavigation[aDataIndex].Parent        := Panel2;
  FrameNavigation[aDataIndex].Source        := aDataIndex;
  FrameNavigation[aDataIndex].GetLeftOffset := OnGetLeftOffset;
  FrameNavigation[aDataIndex].GetTopOffset  := OnGetTopOffset;
  FrameNavigation[aDataIndex].OnProcessWindowStatusChange   := OnProcessWindowStatusChange;
  FrameNavigation[aDataIndex].Init;
  FrameNavigation[aDataIndex].Visible       := False;
end;


procedure TfrmMain.CreateReportsFrame(aDataIndex : integer);
begin
  FrameReports[aDataIndex] := TFrameReports.Create(Self);
  FrameReports[aDataIndex].Name                        := 'FrameReports' + IntToStr(aDataIndex);
  FrameReports[aDataIndex].Parent                      := Panel2;
  FrameReports[aDataIndex].Source                      := aDataIndex;
  FrameReports[aDataIndex].Init;
  FrameReports[aDataIndex].Visible                     := False;
  FrameReports[aDataIndex].GetLeftOffset               := OnGetLeftOffset;
  FrameReports[aDataIndex].GetTopOffset                := OnGetTopOffset;
  FrameReports[aDataIndex].IsFHUpdateThreadRunning     := IsFolderHistoryRunning;
  FrameReports[aDataIndex].OnNewScan                   := RequestNewScan;
  FrameReports[aDataIndex].OnNewSearch                 := RequestNewSearch;
  FrameReports[aDataIndex].OnNewSummary                := RequestNewSummary;
  FrameReports[aDataIndex].OnProcessWindowStatusChange := OnProcessWindowStatusChange;
  FrameReports[aDataIndex].OnSetStatusBarText          := OnStatusBarChange;
  FrameReports[aDataIndex].OnSettingsTab               := OnOpenSettingsTab;
  FrameReports[aDataIndex].OnSetTutorialBarText        := OnTutorialBarChange;

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
begin
  FrameSearch  := TFrameSearch.Create(Self);
  FrameSearch.Parent             := Panel2;
  FrameSearch.Visible            := False;
  FrameSearch.Init;
  FrameSearch.GetLeftOffset      := OnGetLeftOffset;
  FrameSearch.GetTopOffset       := OnGetTopOffset;
  FrameSearch.OnMenuChange       := OnMenuChange;
  FrameSearch.OnOpenSearchWizard := OnOpenSearchWizard;


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


procedure TfrmMain.DestroyFrames;
begin
  FrameSummary[dataLatestScan].Free;

  if Assigned(FrameSummary[dataFolderHistory]) then
    FrameSummary[dataFolderHistory].Free;

  // ===========================================================================

  FrameNavigation[dataLatestScan].DeInit;
  FrameNavigation[dataLatestScan].Free;

  // ===========================================================================

  FrameSelect.Free;

  // ===========================================================================

  FrameSearch.DeInit;
  FrameSearch.Free;

  // ===========================================================================

  FrameWebReports.Free;

  FrameMap.DeInit;
  FrameMap.Free;

  FrameExploder.DeInit;
  FrameExploder.Free;

  FrameFolderHistory.DeInit;
  FreeAndNil(FrameFolderHistory);

  FreeAndNil(FrameReports);
end;


// =============================================================================


procedure TfrmMain.TryBuildFolderHistoryAvailable;
begin
  if (XSettings.HistorySettings.Enabled) and (XSettings.System.UserEnabledFH) then begin
    FrameFolderHistory.BuildFolderHistoryAvailable;
  end
  else begin
    lWelcomeFolderHistory.Enabled := False;
    lWelcomeFolderHistory.Hint    := 'Disabled, enable through Settings->General';
  end;
end;


procedure TfrmMain.CreateObjects;
var
  lScanDetails : TScanDetails;

begin
  // == file scanner ===========================================================
  GXinorbisScan := TXinorbisScan.Create(0);
  GXinorbisScan.OnFoundNull := ScanOnFoundNull;
  GXinorbisScan.OnFoundTemp := ScanOnFoundTemp;
  GXinorbisScan.OnScanCount := ScanOnProgress;

  // ===========================================================================

  GScanDetails := TObjectList<TScanDetails>.Create;

  lScanDetails := TScanDetails.Create;
  GScanDetails.Add(lScanDetails);

  lScanDetails := TScanDetails.Create;
  GScanDetails.Add(lScanDetails);

  lScanDetails := TScanDetails.Create;
  GScanDetails.Add(lScanDetails);

  FileExtensionsObject := TFileExtensionsObject.Create;

  // ===========================================================================

  NetworkDrivesList            := TStringList.Create;

  FolderHistory                := TObjectList<TFolderHistoryObject>.Create;
  FolderHistoryAvailable       := TObjectList<TFolderHistoryInfo>.Create;

  ScanHistory                  := TObjectList<TScanHistoryObject>.Create;

  MenuStrings                  := TStringList.Create;

  NavigationHistory            := TStringList.Create;
  NavigationHistory.Add('H0');

  HGraphData                   := TStringList.Create;
  FHGraphData                  := TStringList.Create;
end;


procedure TfrmMain.CreateReportObjects;
begin
  GReportUtility := TReportUtility.Create;
  GReportUtility.ReportListFileName := GSystemGlobal.AppDataPath + 'Reports\reportlist.dat';
  GReportUtility.OnNewReport        := OnNewReport;

  GReportCSV      := TCSVReport.Create;
  GReportCSV.OnJustInTime       := OnJustInTime;
  GReportCSV.OnMenuChange       := OnMenuChange;
  GReportCSV.OnSetStatusBarText := OnStatusBarChange;

  GReportHTML     := THTMLReport.Create;
  GReportHTML.Chart1                    := vtcHTML;
  GReportHTML.Chart2                    := vtcHTML2;
  GReportHTML.OnJustInTime              := OnJustInTime;
  GReportHTML.OnBuildInformationDisplay := OnBuildInformationDisplay;
  GReportHTML.OnSetStatusBarText        := OnStatusBarChange;

  GReportText     := TTextReport.Create;
  GReportText.OnJustInTime       := OnJustInTime;
  GReportText.OnSetStatusBarText := OnStatusBarChange;

  GReportTree     := TTreeReport.Create;
  GReportTree.OnSetStatusBarText := OnStatusBarChange;

  GReportXinorbis := TXinorbisReport.Create;
  GReportXinorbis.OnJustInTime       := OnJustInTime;
  GReportXinorbis.OnSetStatusBarText := OnStatusBarChange;

  GReportXML      := TXMLReport.Create;
  GReportXML.OnJustInTime       := OnJustInTime;
  GReportXML.OnSetStatusBarText := OnStatusBarChange;

  GReportSummary := TSummaryReports.Create;
  GReportSummary.OnSetStatusBarText := OnStatusBarChange;
end;


procedure TfrmMain.DestroyReports;
begin
  FreeAndNil(GReportXML);
  FreeAndNil(GReportXinorbis);
  FreeAndNil(GReportTree);
  FreeAndNil(GReportText);
  FreeAndNil(GReportSummary);
  FreeAndNil(GReportHTML);
  FreeAndNil(GReportCSV);

  FreeAndNil(GReportUtility);
end;


procedure TfrmMain.HandleResizing(NewPanelInFront : integer);
begin
  if (FormDisplay.PanelInFront <> NewPanelInFront) or
     (FormDisplay.Source       <> FSource) then begin
	case FormDisplay.PanelInFront of
      pMainPanelIndex            : begin
                                     //pMain.Visible := False;
                                     //pMain.Align   := alNone;
                                   end;
      pScanSelectionPanelIndex   : begin
                                     FrameSelect.Visible := False;
                                     FrameSelect.Align   := alNone;
                                   end;
      pMainSummaryPanelIndex     : begin
                                     FrameSummary[FormDisplay.Source].Visible := False;
                                     FrameSummary[FormDisplay.Source].Align   := alNone;
                                   end;
      pMainReportsPanelIndex     : begin
                                     FrameReports[FormDisplay.Source].Visible := False;
                                     FrameReports[FormDisplay.Source].Align   := alNone;

                                     //FrameReports.pMainReportsResize(Nil);
                                   end;
      pMainNavigationPanelIndex  : begin
                                     FrameNavigation[FormDisplay.Source].Visible := False;
                                     FrameNavigation[FormDisplay.Source].Align   := alNone;

                                     FrameNavigation[FormDisplay.Source].Panel25Resize(nil);
                                     FrameNavigation[FormDisplay.Source].Panel26Resize(nil);

                                   end;
      pMainSearchPanelIndex      : begin
                                     FrameSearch.Visible := False;
                                     FrameSearch.Align   := alNone;
                                   end;
      pMainFileHistoryPanelIndex : begin
                                     FrameFolderHistory.Visible := False;
                                     FrameFolderHistory.Align   := alNone;
                                   end;
      pMainWebReportsPanelIndex  : begin
                                     FrameWebReports.Visible := False;
                                     FrameWebReports.Align   := alNone;
                                   end;
      pMainMapPanelIndex         : begin
                                     FrameMap.Visible := False;
                                     FrameMap.Align   := alNone;
								   end;
      pMainExploderPanelIndex    : begin
                                     FrameExploder.Visible := False;
                                     FrameExploder.Align   := alNone;
                                   end;
      end;
    end;

    FormDisplay.PanelInFront := NewPanelInFront;
    FormDisplay.Source       := FSource;

    case NewPanelInFront of
      pMainPanelIndex            : begin
                                     //pMain.Visible := True;
                                     //pMain.Align   := alClient;
                                   end;
      pScanSelectionPanelIndex   : begin
                                     FrameSelect.Visible := True;
                                     FrameSelect.Align   := alClient;

                                     FrameSelect.pScanSelectionResize(Nil);
                                   end;
      pMainSummaryPanelIndex     : begin
                                     FrameSummary[FSource].Align   := alClient;
                                     FrameSummary[FSource].Visible := True;
                                   end;
      pMainReportsPanelIndex     : begin
                                     FrameReports[FSource].Visible := True;
                                     FrameReports[FSource].Align   := alClient;

                                     FrameReports[FSource].pMainReportsResize(Nil);
                                   end;
      pMainNavigationPanelIndex  : begin
                                     FrameNavigation[FSource].Visible := True;
                                     FrameNavigation[FSource].Align   := alClient;

                                     FrameNavigation[FSource].Panel25Resize(nil);
                                     FrameNavigation[FSource].Panel26Resize(nil);
                                   end;
      pMainSearchPanelIndex      : begin
                                     FrameSearch.Visible := True;
                                     FrameSearch.Align   := alClient;
									 FrameSearch.FrameResize(Nil);
                                   end;
      pMainFileHistoryPanelIndex : begin
                                     FrameFolderHistory.Visible := True;
                                     FrameFolderHistory.Align   := alClient;

                                     FrameFolderHistory.tpFHStatsResize(Nil);
                                   end;
      pMainWebReportsPanelIndex  : begin
                                     FrameWebReports.Visible := True;
                                     FrameWebReports.Align   := alClient;
                                   end;
      pMainMapPanelIndex         : begin
                                     FrameMap.Visible := True;
                                     FrameMap.Align   := alClient;
                                    end;
      pMainExploderPanelIndex    : begin
                                     FrameExploder.Visible := True;
                                     FrameExploder.Align   := alClient;
                                   end;
  end;
end;


procedure TfrmMain.Help2Click(Sender: TObject);
begin
  THelp.OpenHelpPage('index.htm');
end;


procedure TfrmMain.ClearAllData;
 begin
  Screen.Cursor := crDefault;
end;


procedure TfrmMain.ConfigureFindFile(aScanPath : string; aTag : integer);
var
  t : integer;

begin
  GXinorbisScan.ClearFilters;

  if GSystemGlobal.ExcludedFolders.Count <> 0 then begin
    for t := 0 to GSystemGlobal.ExcludedFolders.Count - 1 do
      GXinorbisScan.AddExcludedFolder(GSystemGlobal.ExcludedFolders[t]);
  end;

  if GSystemGlobal.ExcludedFiles.Count <> 0 then begin
    for t:= 0 to GSystemGlobal.ExcludedFiles.Count - 1 do
      GXinorbisScan.AddExcludedFile(GSystemGlobal.ExcludedFiles[t]);
  end;

  GXinorbisScan.SetExcludeModes(GSystemGlobal.ExcludeVirtual);

  GXinorbisScan.Tag := aTag;

  GXinorbisScan.SetScanFolder(aScanPath);
end;


function TfrmMain.DoScanModeNormal(aDataIndex : integer; aScanPath : string): string;
var
  ts : string;
  nwid : integer;
  tempchar : char;

begin
  XSettings.Forms.ProgressForm.SetProcessText(XText[rsScanningFolder] + rsEllipsis);
  XSettings.Forms.ProgressForm.SetProcessIcon(1);
  XSettings.LastScanMultiple := False;
  GXinorbisScan.SizeOfCurrentScanFolder    := 1;

  ts        := aScanPath;
  ts[1]     := UpCase(ts[1]);
  aScanPath := ts;

  GScanDetails[aDataIndex].ScanPath := aScanPath;
  FrameSelect.ePath.Text            := aScanPath;

  if aDataIndex = dataLatestScan then begin
    tempchar := GScanDetails[aDataIndex].ScanPath[1];

    GSystemGlobal.drivespacemax  := DiskSize(Ord(tempchar) - 64);
    GSystemGlobal.drivespacefree := DiskFree(Ord(tempchar) - 64);
  end
  else begin
    //tempchar := 'C';

    GSystemGlobal.drivespacemax  := -1;
    GSystemGlobal.drivespacefree := -1;
  end;

  nwid := TXWindows.IsThisNetworkDrive(aScanPath);

  if nwid <> -1 then begin
    FrameSelect.ePath.Text := TXWindows.ConvertPathToNetwork(aScanPath, nwid);

    aScanPath := FrameSelect.ePath.Text;
    GScanDetails[aDataIndex].ScanPath := aScanPath;
  end;

  GScanDetails[aDataIndex].ScanMD5 := TMD5.Generate(UpperCase(aScanPath));

  // =====================================================================

  ConfigureFindFile(aScanPath, 1);

  GXinorbisScan.Scan;

  // =====================================================================

  Result := aScanPath;
end;


procedure TfrmMain.XinorbisScan(aDataIndex : integer; ScanPath : string; const fromfile : string; ScanType, ScanSource : integer);
begin
  if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
    ShowXDialog(XText[rsWarning], XText[rsPleaseWaitFolderHistory], XDialogTypeXinorbis);

    Exit;
  end;

  // =======================================================================================================

  GScanDetails[aDataIndex].ScanType   := ScanType;
  GScanDetails[aDataIndex].ScanSource := ScanSource;
  GScanDetails[aDataIndex].ScanPath   := ScanPath;
  GScanDetails[aDataIndex].InProgress := True;

  // =======================================================================================================

  XinorbisScanPre(aDataIndex, fromfile);

  // =======================================================================================================

  XinorbisScanExecute(aDataIndex);

  // =======================================================================================================

  XinorbisScanAnalysis(aDataIndex);

  // =======================================================================================================

  XinorbisScanBuild(aDataIndex);

  // =======================================================================================================

  XinorbisScanReportsAndFH(aDataIndex);

  // =======================================================================================================

  XinorbisScanPost(aDataIndex);

  // =======================================================================================================

  GScanDetails[aDataIndex].InProgress := False;
end;


procedure TfrmMain.XinorbisScanPre(aDataIndex : integer; const aFromFile : string);
var
  t : integer;

begin
  if Not(Assigned(FrameReports[aDataIndex])) then
    CreateReportsFrame(aDataIndex);

  if not Assigned(FrameSummary[aDataIndex]) then
    CreateSummaryFrame(aDataIndex);

  // ===========================================================================

  GScanDetails[aDataIndex].FromFile  := False;
  GScanDetails[aDataIndex].Filename  := aFromFile;
  GScanDetails[aDataIndex].ScanTable := aFromFile;

  if GScanDetails[aDataIndex].ScanPath <> '' then begin
    if GScanDetails[aDataIndex].ScanSource <> ScanSourceFolderHistory  then begin
      if GScanDetails[aDataIndex].ScanPath = '\' then
		GScanDetails[aDataIndex].ScanSource := ScanSourceLiveShare
      else
		GScanDetails[aDataIndex].ScanSource := ScanSourceLive;
    end;
  end;

  GScanDetails[aDataIndex].InitNow;

  Screen.Cursor  := crHourGlass;

  ToggleSoftwareStatus(aDataIndex, False);
  ShowProcessWindow;

  // ===========================================================================

  if GScanDetails[aDataIndex].ScanType = ScanTypeRefresh then begin
    TPreScan.PurgeAllDataRefresh(aDATAINDEX, FrameReports[aDataIndex].sgNullFiles,
                                             FrameReports[aDataIndex].sgNullFolders,
                                             FrameSearch.sgSearchResults);
  end
  else
    TPreScan.PurgeAllData(aDATAINDEX, FrameReports[aDataIndex].sgNullFiles,
                                      FrameReports[aDataIndex].sgNullFolders,
                                      FrameSearch.sgSearchResults);

  // ======================================================================================================

  for t := 0 to JustInTimeCount do begin
    if XSettings.Optimisations.JustInTimeDisplay then
      XSettings.System.JustInTimeProcessed[aDataIndex, t] := False
    else
      XSettings.System.JustInTimeProcessed[aDataIndex, t] := True;
  end;

  FrameMap.ClearMap;
  // to do clear frameexploder

  FrameReports[aDataIndex].PreScan;
end;

// aScanMode = ScanModeNormal : aScanpath is folder to scan
procedure TfrmMain.XinorbisScanExecute(aDataIndex : integer);
begin
  if (GXinorbisScan.StopScan) then Exit;

  GSplashHandler->SetProgressBar(1);

  // =======================================================================
  // -- Choose the data source ---------------------------------------------
  // =======================================================================
  case GScanDetails[aDataIndex].ScanType of
    ScanTypeNormal  : begin
                        if GScanDetails[aDataIndex].ScanPath <> '' then begin
                          case GScanDetails[aDataIndex].ScanSource of
                            ScanSourceFolderHistory : begin
                                                        PopulateXinFilesFromTable(GScanDetails[aDataIndex].ScanTable);              // db table name to use for data

                                                        GXinorbisScan.PrepareForFolderHistory;
                                                      end;
                          else
                            GScanDetails[aDataIndex].ScanPath := DoScanModeNormal(aDataIndex, GScanDetails[aDataIndex].ScanPath); // direct scan of ascanpath
                          end;
                        end
                        else begin                                 // From report
                          GScanDetails[aDataIndex].FromFile := True;

                          case GScanDetails[aDataIndex].ScanSource of
                            ScanSourceFileXinDetailed  : BuildXinFilesFromReport(GScanDetails[aDataIndex].Filename);
                            ScanSourceFileXin2Detailed : BuildXin2FilesFromReport(GScanDetails[aDataIndex].Filename);
                          else
                            showmessage('ERROR UNKNOWN SCAN SOURCE!!');
                          end;
                        end;

                        GXinorbisScan.DataIndex := aDataIndex;
                        GXinorbisScan.Analyse;

                        GScanDetails[aDataIndex].TotalSize   := GXinorbisScan.FileTotalSpace;
                        GScanDetails[aDataIndex].TotalSizeOD := GXinorbisScan.FileOnDisk;
                        GScanDetails[aDataIndex].FileCount   := GXinorbisScan.FileCount;
                        GScanDetails[aDataIndex].FolderCount := GXinorbisScan.FolderCount;

                        NewSourceAvailable(aDataIndex);
                      end;
    ScanTypeRefresh : begin
                        GXinorbisScan.DataIndex := aDataIndex;
                        GXinorbisScan.Clear;
                        GXinorbisScan.Analyse;

                        GScanDetails[aDataIndex].TotalSize   := GXinorbisScan.FileTotalSpace;
                        GScanDetails[aDataIndex].TotalSizeOD := GXinorbisScan.FileOnDisk;
                        GScanDetails[aDataIndex].FileCount   := GXinorbisScan.FileCount;
                        GScanDetails[aDataIndex].FolderCount := GXinorbisScan.FolderCount;
                      end;
  end;
end;


procedure TfrmMain.XinorbisScanAnalysis(aDataIndex : integer);
begin
  if (GXinorbisScan.StopScan) then Exit;

  XSettings.Forms.ProgressForm.SetProcessIcon(2);
//    BuildRootListFromXinFiles(1);

  XSettings.Forms.ProgressForm.SetProcessText(XText[rsAnalysingData] + rsEllipsis);

  GXinorbisScan.AnalyseData(True);

  FrameReports[aDataIndex].PostScan;
end;


procedure TfrmMain.XinorbisScanBuild(aDataIndex : integer);
begin
  if (GXinorbisScan.StopScan) then Exit;

GSplashHandler->SetProgressBar(5);

  XSettings.Forms.ProgressForm.SetProcessIcon(3);

  // =====================================================================

  BuildDisplay(aDataIndex);

  // =====================================================================

  if (GScanDetails[aDataIndex].ScanSource <> ScanSourceFolderHistory) and
     (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXinDetailed) and
     (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXin2Detailed) then begin

    if GScanDetails[aDataIndex].ScanType = ScanTypeNormal then begin
      if (XSettings.HistorySettings.Enabled) and (XSettings.System.UserEnabledFH) then begin
        XSettings.Forms.ProgressForm.SetProcessIcon(4);
        XSettings.Forms.ProgressForm.SetProcessText(XText[rsUpdatingFolderHistory] + rsEllipsis);

        if not(GScanDetails[aDataIndex].FromFile) then begin
          ProcessUpdateFolderHistoryFile;
        end;
      end;
    end;
  end;

  // =====================================================================

  BuildSummary(aDataIndex, 0);

  FrameReports[aDataIndex].RefreshGraph(nil);
end;


procedure TfrmMain.XinorbisScanReportsAndFH(aDataIndex : integer);
begin
  if not(GXinorbisScan.StopScan) then begin
    XSettings.Forms.ProgressForm.SetProcessIcon(5);

    if (GScanDetails[aDataIndex].ScanSource <> ScanSourceFolderHistory) and
       (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXinDetailed) and
       (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXin2Detailed) then begin

      if XSettings.Report.autosavemode then begin
        XSettings.Forms.ProgressForm.SetProcessText(XText[rsSavingReports] + rsEllipsis);

		AutoSaveReports(aDataIndex);
	  end;

	  // ---------------------------------------------------------------------
	  // -- set the history toolbar to show the newly scanned path -----------
	  // ---------------------------------------------------------------------

	  if FrameFolderHistory.GetAvailablePathContains(FrameSelect.ePath.Text) then
		TryBuildFolderHistoryAvailable;

	  FrameFolderHistory.SetSelectedPathWithoutExecute(FrameSelect.ePath.Text);
	end;
  end
  else begin
	ClearAllData;
  end;
end;


procedure TfrmMain.AutoSaveReports(aDataIndex : integer);
 begin
  XSettings.Report.TextOptions[LayoutAutoSave].FileName       := '';
  XSettings.Report.CSVOptions[LayoutAutoSave].FileName        := '';
  XSettings.Report.HTMLOptions[LayoutAutoSave].FileName       := '';
  XSettings.Report.XinorbisOptions[LayoutAutoSave].FileName   := '';
  XSettings.Report.XMLOptions[LayoutAutoSave].FileName        := '';
  XSettings.Report.TreeOptions[LayoutAutoSave].FileName       := '';

  if XSettings.Report.AutoSaveItem[1] then
    XSettings.Report.TextOptions[LayoutAutoSave].FileName     := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\text\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

  if XSettings.Report.AutoSaveItem[2] then
    XSettings.Report.XinorbisOptions[LayoutAutoSave].FileName := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\xinorbis\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.zsr2';

  if XSettings.Report.AutoSaveItem[3] then
    XSettings.Report.HTMLOptions[LayoutAutoSave].FileName     := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\HTML\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
														  TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.htm';

  if XSettings.Report.AutoSaveItem[4] then
    XSettings.Report.XMLOptions[LayoutAutoSave].FileName      := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\XML\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
														  TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.xml';

  if XSettings.Report.AutoSaveItem[5] then
    XSettings.Report.CSVOptions[LayoutAutoSave].FileName      := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\CSV\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_'  + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.csv';

  if XSettings.Report.AutoSaveItem[6] then
    XSettings.Report.TreeOptions[LayoutAutoSave].FileName     := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\tree\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_'  + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

  FrameReports[aDataIndex].SaveReports(XSettings.Report.TextOptions[LayoutAutoSave],
                                       XSettings.Report.CSVOptions[LayoutAutoSave],
                                       XSettings.Report.HTMLOptions[LayoutAutoSave],
                                       XSettings.Report.XinorbisOptions[LayoutAutoSave],
                                       XSettings.Report.XMLOptions[LayoutAutoSave],
                                       XSettings.Report.TreeOptions[LayoutAutoSave]);
end;


procedure TfrmMain.XinorbisScanPost(aDataIndex : integer);
begin
  ToggleSoftwareStatus(aDataIndex, True);

  HideProcessWindow;

  Screen.Cursor := crDefault;

  // == only add if directory ================================================

  if not(GXinorbisScan.StopScan) then begin
    if (GScanDetails[aDataIndex].ScanSource <> ScanSourceFolderHistory) and
       (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXinDetailed) and
       (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXin2Detailed) then begin
      if length(GScanDetails[aDataIndex].ScanPath) >= 3 then begin
        AddToScanHistory(GScanDetails[aDataIndex].ScanPath, TConvert.DateToYYYYMMDDI(Now), TConvert.TimeToString(Now, True),
                         TUtility.ExcludedFilesToString, TUtility.ExcludedFoldersToString);

        FrameSelect.BuildScanHistoryTable(0);
      end;
    end;

    case XSettings.General.PostScanMode of
      CPostScanNothing     : {}; // do nothing
      CPostScanSummary     : lTaskID1Click(lTaskID1);
      CPostScanInformation : begin
                               lTaskID1Click(lTaskID2);

                               FrameReports[aDataIndex].ActivePage := XSettings.General.PostScanIPPage;
                             end;
      CPostScanStructure   : lTaskID1Click(lTaskID3);
    end;

    if (GScanDetails[aDataIndex].FileAttributes[FileType_RecallOnOpen, 0] <> 0) or
       (GScanDetails[aDataIndex].FileAttributes[FileType_RecallOnDataAccess, 0] <> 0) or
       (GScanDetails[aDataIndex].FileAttributes[FileType_Offline, 0] <> 0) then begin
      tbPostScanWarning.Visible := True;
      tbPostScanWarning.Hint    := XText[rsReportContainsVirtualFiles];
    end
    else
      tbPostScanWarning.Visible := False;
  end
  else begin
    tbPostScanWarning.Visible := True;
    tbPostScanWarning.Hint    := XText[rsScanStoppedBeforeComplete];
  end;

  // ===========================================================================

  if not(GXinorbisScan.StopScan) then begin
    FrameReports[aDataIndex].pMainReportsChange(Nil);

    FrameSummary[aDataIndex].lSProcessTime.Caption := XText[rsProcessedIn] + ' ' + TUtility.TimeElapsed(Now - GScanDetails[aDataIndex].TimeStarted);

    GXinorbisScan.StopScan := False;
  end
  else
    IfScanCancelled(aDataIndex);

  UpdateMainMenu;

  case GScanDetails[aDataIndex].ScanSource of
	ScanSourceLive,
	ScanSourceLiveShare        : TMSLogger.Info('Scan of "' + FrameSelect.ePath.Text + '" finished');
    ScanSourceFileXinNormal,
    ScanSourceFileCSV,
    ScanSourceFileXinDetailed,
    ScanSourceFileXin2Detailed : TMSLogger.Info('Import of "' + GScanDetails[aDataIndex].Filename + '" finished');
    ScanSourceFolderHistory    : TMSLogger.Info('Loaded from Folder History table "' + GScanDetails[aDataIndex].ScanTable + '".');
    ScanSourceSearchResults    : {};
  end;
end;


procedure TfrmMain.CombineScan;   // use FSouce when reactivating code
//var
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
//  end;       }
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


procedure TfrmMain.BuildDisplay(aDataIndex : integer);
begin
  case aDataIndex of
    dataLatestScan    : begin
                          FrameReports[aDataIndex].BuildDisplay;

                          GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathLS));
                        end;
    dataFolderHistory : begin
                          FrameReports[aDataIndex].BuildDisplay;

                          GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathFH));
                        end;
  end;
end;


procedure TfrmMain.ApplicationEvents1ShowHint(var HintStr: string;
  var CanShow: Boolean; var HintInfo: THintInfo);
begin
  if HintInfo.HintControl = tbPrivacy  then
    OnTutorialBarChange('hintPrivacy')
  else if HintInfo.HintControl = tbToggleFH then
    OnTutorialBarChange('hintToggleFH')
  else if (HintInfo.HintControl = tbReportSummary) or (HintInfo.HintControl = tbReportCSV) or
          (HintInfo.HintControl = tbReportHTML) or (HintInfo.HintControl = tbReportText) or
          (HintInfo.HintControl = tbReportTree) or (HintInfo.HintControl = tbReportXML) then
    OnTutorialBarChange('hintReports');
end;


procedure TfrmMain.tbPreferencesClick(Sender: TObject);
 begin
  tbPreferences.ImageIndex := CToolbarPrefsOn;

  OnOpenSettingsTab(0);

  tbPreferences.ImageIndex := CToolbarPrefsOff;
end;


procedure TfrmMain.tbPrefsClick(Sender: TObject);
 begin
  tbPreferencesClick(nil);
end;


procedure TfrmMain.tbExitClick(Sender: TObject);
 begin
  Close;
end;


procedure TfrmMain.FormResize(Sender: TObject);
 begin
  sbMain.Panels[0].Width := Width;

  if WindowState = wsNormal then begin
    if (XSettings.Forms.ProgressForm <> nil) then
      XSettings.MaximiseProgressWindow;
  end
  else begin
    if (XSettings.Forms.ProgressForm <> nil) then
      XSettings.MinimiseProgressWindow;
  end;
end;


//only to be used for the 'main screen'
function TfrmMain.BuildXinFilesFromReport(const aReportPath : string): boolean;
 begin
  TPreScan.PurgeAllData(dataLatestScan,
                        FrameReports[dataLatestScan].sgNullFiles,
                        FrameReports[dataLatestScan].sgNullFolders,
                        FrameSearch.sgSearchResults);

  Result := TPopulate.FromXinFilesFromReport(dataLatestScan, aReportPath);
end;


//only to be used for the 'main screen'
function TfrmMain.BuildXin2FilesFromReport(const aReportPath : string): boolean;
begin
  TPreScan.PurgeAllData(dataLatestScan,
                        FrameReports[dataLatestScan].sgNullFiles,
                        FrameReports[dataLatestScan].sgNullFolders,
                        FrameSearch.sgSearchResults);

  Result := TPopulate.FromXin2FilesFromReport(dataLatestScan, aReportPath);
end;


procedure TfrmMain.BuildMainFromCSV(aDataIndex : integer; const fn : string);         // check this needs dataindex, dont think it does
 var
  ret : TCSVDataFormat;
  cx : string;
  t : integer;

  function IsValidNumber(const s : string): boolean;
   var
    t : integer;

  begin
   Result := True;

   for t := 1 to length(s) do
     if (ord(s[t]) < 48) or (ord(s[t]) > 57) then
       Result := False;
  end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 1), 'BuildMainFromCSV :: invalid dataindex :: ' + inttostr(aDataIndex));

  ret := GetCSVDataFormat(fn);

  if ret.Fields[0] <> -1 then begin
    GScanDetails[aDataIndex].TimeStarted := Now;

    cx      := Caption;
    Caption := XText[rsPleaseWait];

    ShowProcessWindow;

    //--------------------------------------------------------------------------

    GSplashHandler->SetProgressBar(3);

    TPreScan.PurgeAllData(aDataIndex,
                          FrameReports[aDataIndex].sgNullFiles,
                          FrameReports[aDataIndex].sgNullFolders,
                          FrameSearch.sgSearchResults);

    TPopulate.FromXinFilesFromCSV(aDataIndex, ret, fn);

    //--------------------------------------------------------------------------

	GSplashHandler->SetProgressBar(4);
    XSettings.Forms.ProgressForm.SetProcessIcon(2);

    //--------------------------------------------------------------------------

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
  end;
end;


procedure TfrmMain.trayIconBalloonClick(Sender: TObject);
begin
  Checkforupdate1Click(Nil);
end;


procedure TfrmMain.trayIconClick(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, 'http://www.xinorbis.com/index.htm', '', '');
end;


procedure TfrmMain.tbSearchWizardClick(Sender: TObject);
var
  s : string;

begin
  if not(XSettings.ProcessWindowsVisible) then begin

    tbSearchWizard.ImageIndex := CToolbarWizardOn;

    s := DoUserWizard;

	if FrameFolderHistory.Visible then begin
      case FrameFolderHistory.ActivePage of
        3 : FrameFolderHistory.DoFHSearch(s);
        4 : FrameFolderHistory.DoCompareSearch(s);
        5 : FrameFolderHistory.DoCompareDriveSearch(s);
      else
        lTaskID1Click(lTaskID4);

        FrameSearch.DoSearch(s);
      end;
    end
    else begin
      lTaskID1Click(lTaskID4);

      FrameSearch.DoSearch(s);
    end;

    tbSearchWizard.ImageIndex := CToolbarWizardOff;
  end;
end;


procedure TfrmMain.tbSourceFolderHistoryClick(Sender: TObject);
begin
  FSource := dataFolderHistory;

  ActivateSource(FSource);
end;


procedure TfrmMain.tbSourceLiveClick(Sender: TObject);
begin
  FSource := dataLatestScan;

  ActivateSource(FSource);
end;


procedure TfrmMain.miHTMLReportClick(Sender: TObject);
 begin
  lReportHTMLMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.lReportPreferencesClick(Sender: TObject);
 begin
  DoReportSettings(8);
end;


procedure TfrmMain.miCustomReportClick(Sender: TObject);
var
  tHTMLrl : THTMLReportOptions;
  tTEXTrl : TTextReportOptions;
  tTREErl : TTreeReportOptions;
  tCSVrl  : TCSVReportOptions;

begin
  case TLabel(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag of
    CReportHTML  : begin
					tHTMLrl := DoHTMLReport(kReportLayoutQuick, True);

                    if tHTMLrl.Layout <> '$' then begin
                      BuildOpenHTMLReport(FSource, tHTMLrl);
                    end;
                  end;
    CReportCSV  : begin
					tCSVrl := DoCSVReport(kReportLayoutQuick, True);

                    if tCSVrl.Layout <> '$' then begin
                      BuildOpenCSVReport(tCSVrl);
                    end;
                  end;
    CReportText : begin
					tTEXTrl := DoTextReport(LayoutQuick, FSource, True);

                    if tTEXTrl.Layout <> '$' then begin
                      BuildOpenTextReport(tTEXTrl);
                    end;
                  end;
    CReportTree : begin
					tTREErl := DoTreeReport(kReportLayoutQuick, FSource, True);

                    if tTREErl.Layout <> '$' then begin
                      BuildOpenTreeReport(tTREErl);
                    end;
                  end;
  end;
end;


procedure TfrmMain.miOpenCustomReportClick(Sender: TObject);
var
  lFileName : string;

begin
  case TLabel(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag of
    CReportHTML : begin
                    lFileName := TXOpenDialog.Execute(XText[rsCustomReportFiles] + ' (*.xcrhtml)|*.xcrhtml',
                                                      '.xcrhtml',
                                                      GSystemGlobal.AppDataPath + 'Saves\Custom Reports',
                                                      '');

                    if lFileName <> '' then
                      BuildOpenHTMLReport(FSource, GReportHTML.BuildHTMLReportOptionsFromFile(lFileName));
                  end;
    CReportText : begin
                    lFileName := TXOpenDialog.Execute(XText[rsCustomReportFiles] + ' (*.xcrtxt)|*.xcrtxt',
                                                      '.xcrtxt',
                                                      GSystemGlobal.AppDataPath + 'Saves\Custom Reports',
                                                      '');

                    if lFileName <> '' then
                      BuildOpenTextReport(GReportText.BuildTextReportOptionsFromFile(lFileName));
                  end;
    CReportTree : begin
                    lFileName := TXOpenDialog.Execute(XText[rsCustomReportFiles] + ' (*.xcrtree)|*.xcrtree',
                                                      '.xcrtree',
                                                      GSystemGlobal.AppDataPath + 'Saves\Custom Reports',
                                                      '');

                    if lFileName <> '' then
                      BuildOpenTreeReport(GReportTree.BuildTreeReportOptionsFromFile(lFileName));
                  end;
  end;
end;





procedure TfrmMain.miEditHTMLReportsClick(Sender: TObject);
begin
  case TMenuItem(Sender).Tag of
    0 : DoCSVReport(0, False);
    1 : DoHTMLReport(0, False);
    2 : DoTextReport(0, FSource, False);
    3 : DoTreeReport(0, FSource, False);
    4 : DoXMLReport(0, FSource);
  end;
end;


procedure TfrmMain.Exit1Click(Sender: TObject);
 begin
  Close;
end;


procedure TfrmMain.miXinorbisReportClick(Sender: TObject);
 begin
  lReportXinorbisMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.miXMLReportClick(Sender: TObject);
 begin
  lReportXMLMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.miUserManualClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, '"' + GSystemGlobal.ExePath + 'Xinorbis8 User Manual.pdf"', '', '');
end;


procedure TfrmMain.miViewLogFolderClick(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, '"' + GSystemGlobal.ExePath + 'Logs\"', '', '');
end;


procedure TfrmMain.miContextHelpClick(Sender: TObject);
var
  lFHSubIndex : integer;

begin
  case FrameReports[FSource].pMainReports.ActivePageIndex of
    TabFHMainStats  : lFHSubIndex := FrameFolderHistory.tpFHStats.ActivePageIndex;
    TabFHMainSearch : lFHSubIndex := FrameFolderHistory.tsFHSearch.ActivePageIndex;
  else
    lFHSubIndex := 0;
  end;

  THelp.OpenContextHelpPage(NavigationHistory[tbHome.Tag],
                            FrameReports[FSource].pMainReports.ActivePageIndex,
                            FrameFolderHistory.tpFHMain.ActivePageIndex,
                            lFHSubIndex);
end;


procedure TfrmMain.miFAQsClick(Sender: TObject);
begin
  THelp.OpenHelpPage('faqs.htm');
end;


procedure TfrmMain.miReferenceClick(Sender: TObject);
 begin
  ShowReference;
end;


procedure TfrmMain.AdvancedOptionsClick(Sender: TObject);
var
  lOption : integer;

begin
  lOption := -1;

  if Sender is TMenuItem then
    lOption := TMenuItem(Sender).Tag
  else if Sender is TLabel then
    lOption := TLabel(Sender).Tag;

  case lOption of
    0 : SetAdvancedOptions(lOption);
    1 : lTaskID1Click(lTaskID6);
    2 : lTaskID1Click(lTaskID7);
    3 : SetAdvancedOptions(lOption);
    4 : SetAdvancedOptions(lOption);
  end;
end;


procedure TfrmMain.SetAdvancedOptions(aOptions : integer);
begin
  case aOptions of
    CAOSpread   : begin
                    lAdvID1.Font.Style := [fsBold];

                    DoSpread(FSource);

                    lAdvID1.Font.Style := [];
                  end;
    CAOExplore  : begin
                    lAdvID2.Font.Style := [fsBold];

                    DoExplore(FSource, GScanDetails[FSource].ScanPath);

                    lAdvID2.Font.Style := [];
                  end;
    CAOFileAges : begin
                    lAdvID3.Font.Style := [fsBold];

                    DoFileAges(FSource);

                    lAdvID3.Font.Style := [];
                  end;
  end;
end;


procedure TfrmMain.miReportBrowserClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, '"' + GSystemGlobal.AppDataPath + 'reports' + '"', '', '');
end;


procedure TfrmMain.tbWebReportsClick(Sender: TObject);
 begin
  if XSettings.ftpOptions[ftpActualLink] <> '' then
    TXWindows.ExecuteFile(0, XSettings.ftpOptions[ftpActualLink], '', '')
  else
    ShowXDialog(XText[rsWebReports], XText[rsWebReportsSettingsMissing], XDialogTypeXinorbis);
end;


procedure TfrmMain.miShowCategoryColoursClick(Sender: TObject);
 begin
  ShowCategoryColours;
end;


procedure TfrmMain.miShowSearchSyntaxClick(Sender: TObject);
begin
  THelp.OpenSearchManual;
end;


procedure TfrmMain.sbRefreshClick(Sender: TObject);
 begin
  ShowProcessWindow;

  GXinorbisScan.Analyse; // check this works

  HideProcessWindow;
end;


procedure TfrmMain.FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
 begin
  MinWidth := 800;
end;


// =======================================================================================================
// =======================================================================================================


procedure TfrmMain.About1Click(Sender: TObject);
 begin
  ShowAbout;
end;


procedure TfrmMain.Checkforupdate1Click(Sender: TObject);
 begin
  if CheckForNewVersion(x8Version, x8Date, 'x8', False) = mrAll then
    Halt(0);
end;


procedure TfrmMain.miTextReportClick(Sender: TObject);
 begin
  lReportTextMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.miTreeReportClick(Sender: TObject);
 begin
  lReportTreeMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.LoadFileExtensionData;
begin
  if not(FileExtensionsObject.LoadFileExtensionDescriptions(GSystemGlobal.ExePath + 'data\system\xinfe.txt')) then begin
    ShowXDialog(XText[rsWarning],
                XText[rsErrorOpening] + ' "' + GSystemGlobal.ExePath + 'data\system\xinfe.txt' + '".',
                XDialogTypeWarning);

    sbMain.Panels[0].Text := '<b>' + XText[rsError] + '</b>: ' + GSystemGlobal.ExePath + 'data\system\xinfe.txt';
  end;
end;


procedure TfrmMain.LoadLanguageDetails(languageindex : integer; debugmode : boolean);
var
  t : integer;
  languagesymbol : string;

begin
  TGLobal.InitialiseGlobalText;

  // if the selected language folder doesn't exist the set it to English
  if Not(SysUtils.DirectoryExists(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(languageindex))) then begin
    languageindex := LanguageUK;

    ShowXDialog(XText[rsErrorOpeningXinorbisSystemFile], 'Language not found.', XDialogTypeWarning);
  end;

  languagesymbol := TLanguageHandler.GetLanguageSymbol(languageindex);

//  LanguageMenus[XSettings.CurrentLanguage].ImageIndex := 24 + XSettings.CurrentLanguage;
  LanguageMenus[XSettings.CurrentLanguage].ImageIndex := 13 + XSettings.CurrentLanguage;

  for t := 0 to 11 do
    LanguageTabs[t] := FrameReports[dataLatestScan].pMainReports.AdvSmoothTabPages[t].Caption;

  // ===========================================================================

  MenuStrings.Clear;

  LoadMenu(FrameSearch.puQuickSearch,          GSystemGlobal.ExePath + 'data\languages\' + languagesymbol + '\QuickSearch.menu');
  LoadMenu(FrameFolderHistory.puFHQuickSearch, GSystemGlobal.ExePath + 'data\languages\' + languagesymbol + '\FHQuickSearch.menu');

  // ===========================================================================

  if (XSettings.CustomSettings.SettingsSaveLocation = SaveLocationRegistry) then begin
    TGlobal.LoadTypeDescriptions;
  end;
end;


procedure TfrmMain.UpdateGUICustomNames(aDataIndex : integer);
begin
  if Assigned(FrameReports[aDataIndex]) then
    FrameReports[aDataIndex].UpdateGUICustomNames;

  if Assigned(FrameNavigation[aDataIndex]) then
    FrameNavigation[aDataIndex].UpdateGUICustomNames;
end;

procedure TfrmMain.ShowZipProcessWindow;
 begin
  XSettings.ShowZipWindow;
end;


procedure TfrmMain.HideZipProcessWindow;
 begin
  XSettings.HideZipWindow;
end;


procedure TfrmMain.ShowProcessWindow;
 begin
  XSettings.ShowProgressWindow;
end;


rocedure TfrmMain.HideProcessWindow;
 begin
  XSettings.HideProgressWindow;
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


procedure TfrmMain.miCSVReportClick(Sender: TObject);
begin
  lReportCSVMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.miTutorialClick(Sender: TObject);
begin
  pTutorial.Visible := not(pTutorial.Visible);
end;


procedure TfrmMain.W7ToolButton3Click(Sender: TObject);
begin
  if FSource <> dataFolderHistory then                         // to do, make refresh work with folder history
    if GScanDetails[FSource].Files.Count <> 0 then begin
      XinorbisScan(FSource, GScanDetails[FSource].ScanPath, '', ScanTypeRefresh, GScanDetails[FSource].ScanSource);
    end;
end;


procedure TfrmMain.Warning1Click(Sender: TObject);
begin
  {$IFDEF debug}
  ShowXDialog('Debug', 'Dialog test', XDialogTypeWarning);
  {$ENDIF}
end;


procedure TfrmMain.miFHInfoClick(Sender: TObject);
 begin
  ShowDatabaseInfo;
end;


procedure TfrmMain.miBackupDataClick(Sender: TObject);
var
 lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsCompressedFiles] + ' (*.zip)|*.zip',
                                    '.zip',
                                    'XinorbisBackup_' + TConvert.DateToYYYYMMDD(Now) + '.zip',
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    ShowZipProcessWindow;

    XinorbisZip.ZipFolder(lFileName, GSystemGlobal.AppDataPath);

    HideZipProcessWindow;
  end;
end;


procedure TfrmMain.sbFHCXMLReportClick(Sender: TObject);
var
  lFilename : string;

 begin
  lFilename := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\XML_Compare\quick\' + TXFormatting.MakeFileNameCompatible(FrameFolderHistory.SelectedPath) + '_' +
               TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.xml';

  GReportXML.GenerateXMLCompareOutput(lFilename, FrameFolderHistory.SelectedPath,
                                      FrameFolderHistory.bFHCompareLeft.Caption, FrameFolderHistory.bFHCompareRight.Caption,
                                      FrameFolderHistory.sgFHCompareLeft, FrameFolderHistory.sgFHCompareRight);

  if XSettings.Report.XMLOutput <> '' then
    TXWindows.ExecuteFile(0, '"' + XSettings.Report.XMLOutput + '"', '"' + lFilename + '"', '')
  else
    TXWindows.ExecuteFile(0, 'notepad.exe', '"' + lFilename + '"', '');

  sbMain.Panels[0].Text := XText[rsXMLCReportSavedAs] + ': ' + lFilename;
end;

procedure TfrmMain.miOpenLastReportClick(Sender: TObject);
 begin
  if GReportUtility.LastReportFilename <> '' then begin
    if FileExists(GReportUtility.LastReportFilename) then begin

      case GReportUtility.GetReportType(GReportUtility.LastReportFilename) of
        CReportTypeCSV      : begin
                                if XSettings.Report.CSVOutput <> '' then
                                  TXWindows.ExecuteFile(0, '"' + XSettings.Report.CSVOutput + '"', '"' + GReportUtility.LastReportFilename + '"', '')
                                else
                                  TXWindows.ExecuteFile(0, 'notepad.exe', '"' + GReportUtility.LastReportFilename + '"', '');
                              end;
        CReportTypeHTML     : begin
                                if XSettings.Report.HTMLOutput <> '' then
                                  TXWindows.ExecuteFile(0, '"' + XSettings.Report.HTMLOutput + '"', '"' + GReportUtility.LastReportFilename + '"', '')
                                else
                                  TXWindows.ExecuteFile(0, '"' + GReportUtility.LastReportFilename + '"', '', '');
                              end;
        CReportTypeText     : begin
                                if XSettings.Report.TextOutput <> '' then
                                  TXWindows.ExecuteFile(0, '"' + XSettings.Report.TextOutput + '"', '"' + GReportUtility.LastReportFilename + '"', '')
                                else
                                  TXWindows.ExecuteFile(0, '"' + GReportUtility.LastReportFilename + '"', '', '');
                              end;
        CReportTypeXinorbis : begin
                                TXWindows.ExecuteFile(0, 'notepad.exe', '"' + GReportUtility.LastReportFilename + '"', '');
                              end;
        CReportTypeXML      : begin
                                if XSettings.Report.XMLOutput <> '' then
                                  TXWindows.ExecuteFile(0, '"' + XSettings.Report.XMLOutput + '"', '"' + GReportUtility.LastReportFilename + '"', '')
                                else
                                  TXWindows.ExecuteFile(0, 'notepad.exe', '"' + GReportUtility.LastReportFilename + '"', '');
                              end;
      else
        ShowXDialog(XText[rsReportNotFound],
                    GReportUtility.LastReportFilename,
                    XDialogTypeWarning);
      end;
    end;
  end;
end;


procedure TfrmMain.miCopyLastReportToClipboardClick(Sender: TObject);
var
  lDocument : TStringList;

begin
  if GReportUtility.LastReportFilename <> '' then begin
    lDocument := TStringList.Create;

    lDocument.LoadFromFile(GReportUtility.LastReportFilename);

    Clipboard.AsText := lDocument.Text;

    lDocument.Free;
  end;
end;


procedure TfrmMain.BuildOpenHTMLReport(aDataIndex : integer; HTMLr : THTMLReportOptions);
 begin
  HTMLr.Filename := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\html\quick\' +
                    TXFormatting.MakeFileNameCompatible(GScanDetails[aDataIndex].ScanPath) + '_' +
                    TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.htm';

  GReportHTML.GenerateHTMLReport(aDataIndex, HTMLr, '');

  if HTMLr.HTMLAutoOpen then
    miOpenLastReportClick(Nil);
end;


procedure TfrmMain.BuildOpenCSVReport(CSVr : TCSVReportOptions);
var
  lCSVOutput : TStringList;

begin
  CSVr.Filename := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\csv\quick\' +
                   TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
                   TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.csv';

  lCSVOutput := TStringList.Create;

  GReportCSV.GenerateCSVReport(FSource, lCSVOutput, CSVr, LayoutQuick);

  FreeAndNil(lCSVOutput);

  if CSVr.CSVAutoOpen then
    miOpenLastReportClick(Nil);
end;


procedure TfrmMain.BuildOpenTextReport(Textr : TTextReportOptions);
var
  lCSVOptions  : TCSVReportOptions;
  lHTMLOptions : THTMLReportOptions;
  lXinOptions  : TXinorbisReportOptions;
  lXMLOptions  : TXMLReportOptions;
  lTreeOptions : TTreeReportOptions;

begin
  Textr.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\text\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

  FrameReports[FSource].SaveReports(Textr, lCSVOptions, lHTMLOptions, lXinOptions, lXMLOptions, lTreeOptions);

  miOpenLastReportClick(Nil);
end;


procedure TfrmMain.BuildOpenTreeReport(Treer : TTreeReportOptions);
var
  lReportOutput : TStringList;

begin
  if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
    ShowXDialog(XText[rsWarning], XText[rsPleaseWaitFolderHistory], XDialogTypeXinorbis);
  end
  else begin
    Treer.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\tree\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

    lReportOutput := TStringList.Create;

    if GReportTree.GenerateTreeReport(FSource, lReportOutput, Treer) then
	  GReportUtility.SetLastReport(FSource, Treer.Filename, GScanDetails[FSource].ScanPath, ReportTree, LayoutUnknown);

	FreeAndNil(lReportOutput);

    miOpenLastReportClick(Nil);
  end;
end;


procedure TfrmMain.iSideMenuWelcomeClick(Sender: TObject);
 begin
  Assert(sender <> nil, 'iSideMenuWelcomeClick :: Nil TImage');

  if TPanel(TImage(Sender).Parent).Height = TImage(Sender).Tag then begin
    TPanel(TImage(Sender).Parent).Height := 22;
  end
  else begin
    TPanel(TImage(Sender).Parent).Height := TImage(Sender).Tag;
  end;
end;


procedure TfrmMain.SetSidePanelDisplay(welcomeID, taskID, tasksubID, canAddToHistory : integer);
 begin
  SetWelcomeDisplay(welcomeID);

  DoWelcome(welcomeID);

  DoTask(taskID, tasksubID);

  if canAddToHistory = 1 then begin
    if welcomeID <> -1 then
      AddToPageNavigationHistory('W' + IntToStr(welcomeID));

    if taskID <> -1 then
      AddToPageNavigationHistory('T' + IntToStr(taskID));
  end;

  if (taskID = -1) and (welcomeID = -1) then begin
    HandleResizing(pMainPanelIndex);

    FrameSelect.BringToFront;
  end;

  UpdateLeftPanelStatus;
end;


procedure TfrmMain.DoWelcome(aWelcomeID : integer);
begin
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
  end;
end;


procedure TfrmMain.DoTask(aTaskID, aTaskSubID : integer);
begin
  if aTaskID < 99 then
    SetTasksDisplay(aTaskID);

  if aTaskID <> NullEntry then begin

    case aTaskID of
       1 : begin
             HandleResizing(pMainSummaryPanelIndex);
             FrameSummary[FSource].BringToFront;
           end;
       2 : begin
             HandleResizing(pMainReportsPanelIndex);
             FrameReports[FSource].BringToFront;

             if aTaskSubID <> NullEntry then
               FrameReports[FSource].pMainReports.ActivePageIndex := aTaskSubID;
           end;
       3 : begin
             if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
               ShowXDialog(XText[rsWarning], XText[rsPleaseWaitFolderHistory], XDialogTypeXinorbis);
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
       4 : begin
             HandleResizing(pMainSearchPanelIndex);

             FrameSearch.Source := FSource;
             FrameSearch.SetTab(0);
             FrameSearch.BringToFront;
           end;
       5 : begin
             HandleResizing(pMainMapPanelIndex);

             UpdateFrameMap;

             FrameMap.BringToFront;
           end;
       6 : begin
             HandleResizing(pMainSearchPanelIndex);

             FrameSearch.Source := FSource;
             FrameSearch.SetTab(2);
             FrameSearch.BringToFront;
           end;
       7 : begin
             HandleResizing(pMainSearchPanelIndex);

             FrameSearch.Source := FSource;
             FrameSearch.SetTab(3);
             FrameSearch.BringToFront;
           end;
       8 : begin
             HandleResizing(pMainExploderPanelIndex);

             UpdateFrameExploder;

             FrameExploder.BringToFront;
           end;
    end;

    if XSettings.System.Tutorial then
      OnTutorialBarChange(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
                                                  '\tutorial\t' + IntToStr(aTaskID) + '.dat');
  end;
end;


procedure TfrmMain.SetWelcomeDisplay(welcomeID : integer);
 var
  t : integer;

 begin
  for t := 1 to SideMenuWelcomeCount do begin
    if t <> welcomeID then begin
      WelcomeOptions[t].Font.Style := [];
    end;
  end;

  if (welcomeID <> -1) and (welcomeID <= SideMenuWelcomeCount) then
    WelcomeOptions[welcomeID].Font.Style := [fsBold];
end;


procedure TfrmMain.SetTasksDisplay(taskID : integer);
 var
  t : integer;

 begin
  for t := 1 to SideMenuTasksCount do begin
    if t <> taskID then begin
      TaskOptions[t].Font.Style := [];
    end;
  end;

  if taskID <> -1 then
    TaskOptions[taskID].Font.Style := [fsBold];
end;


procedure TfrmMain.UpdateLeftPanelStatus;
 var
  status : boolean;
  t : integer;

 begin
  if GScanDetails[FSource].Files.Count = 0 then
    status := False
  else
    status := True;

  // =========================================================================
  // == Tasks Panel ==========================================================
  // =========================================================================

  for t:= 1 to 5 do
    TaskOptions[t].Enabled   := status;

  // =========================================================================
  // == Advanced Panel =======================================================
  // =========================================================================

  AdvancedOptions[1].Enabled := status;
  AdvancedOptions[2].Enabled := status;
  AdvancedOptions[3].Enabled := status;

  // =========================================================================
  // == Quick Reports ========================================================
  // =========================================================================

  if FrameSearch.Visible then begin
    GXGuiUtil.SetButtonImageEnabled(tbReportSummary, CReportOffStart, False);
    GXGuiUtil.SetButtonImageEnabled(tbReportTree,    CReportOffStart, False);
  end
  else begin
    GXGuiUtil.SetButtonImageEnabled(tbReportSummary, CReportOffStart, status);
    GXGuiUtil.SetButtonImageEnabled(tbReportTree,    CReportOffStart, status);
  end;

  GXGuiUtil.SetButtonImageEnabled(tbReportCSV,       CReportOffStart, status);
  GXGuiUtil.SetButtonImageEnabled(tbReportHTML,      CReportOffStart, status);
  GXGuiUtil.SetButtonImageEnabled(tbReportText,      CReportOffStart, status);
  GXGuiUtil.SetButtonImageEnabled(tbReportXML,       CReportOffStart, status);
  GXGuiUtil.SetButtonImageEnabled(tbReportXinorbis,  CReportOffStart, status);
end;


procedure TfrmMain.Searchmanual1Click(Sender: TObject);
begin
  THelp.OpenSearchManual;
end;


procedure TfrmMain.SetAdvancedDisplay(advancedID : integer);
 var
  t : integer;

 begin
  for t := 1 to SideMenuAdvancedCount do begin
    if t <> advancedID then begin
      AdvancedOptions[t].Font.Style := [];
    end;
  end;

  if advancedID <> -1 then
    AdvancedOptions[advancedID].Font.Style := [fsBold];
end;


procedure TfrmMain.lTaskID1Click(Sender: TObject);
var
  cl : string;

begin
  Assert(Sender <> Nil, 'lTaskID1Click :: nil caller!');

  case TLabel(Sender).Tag of
    0 : SetSidePanelDisplay(NullEntry, 1, NullEntry, 1);
    1 : SetSidePanelDisplay(NullEntry, 2, NullEntry, 1);
    2 : SetSidePanelDisplay(NullEntry, 3, NullEntry, 1);
    3 : begin
          cl := Copy(NavigationHistory[NavigationHistory.Count - 1], 1, 2);

          SetSidePanelDisplay(NullEntry, 4, NullEntry, 1);
        end;
    4 : begin
          SetSidePanelDisplay(NullEntry, 5, NullEntry, 1);
        end;
    5 : begin
          SetSidePanelDisplay(NullEntry, 6, NullEntry, 1);
        end;
    6 : begin
          SetSidePanelDisplay(NullEntry, 7, NullEntry, 1);
        end;
    7 : begin
          SetSidePanelDisplay(NullEntry, 8, NullEntry, 1);
        end;
  end;
end;


procedure TfrmMain.lTutorialDblClick(Sender: TObject);
 begin
  miTutorialClick(Nil);
end;


procedure TfrmMain.sbNewScanClick(Sender: TObject);
 begin
  HandleResizing(pScanSelectionPanelIndex);
  FrameSelect.pScanSelection.BringToFront;

  SetSidePanelDisplay(1, NullEntry, NullEntry, 1);
end;


procedure TfrmMain.tbPrivacyClick(Sender: TObject);
 begin
  if tbPrivacy.Tag = 0 then begin
    tbPrivacy.Tag                    := 1;
    XSettings.Database.PrivacyActive := True;
    tbPrivacy.ImageIndex             := 4;

    tbPrivacy.Hint                   := XText[rsHintM4] + ' [' + XText[rsEnabled] + ']';
  end
  else begin
    tbPrivacy.Tag                    := 0;
    XSettings.Database.PrivacyActive := False;
    tbPrivacy.ImageIndex             := 3;

    tbPrivacy.Hint                   := XText[rsHintM4] + ' [' + XText[rsDisabled] + ']';
  end;
end;


procedure TfrmMain.tbToggleFHClick(Sender: TObject);
 begin
  if XSettings.System.UserEnabledFH then begin
    tbToggleFH.ImageIndex := 5;

    tbToggleFH.Hint       := XText[rsHintM5] + ' [' + XText[rsDisabled] + ']';

    XSettings.System.UserEnabledFH := False;
  end
  else begin
    tbToggleFH.ImageIndex := 6;

    tbToggleFH.Hint       := XText[rsHintM5] + ' [' + XText[rsEnabled] + ']';

    XSettings.System.UserEnabledFH := True;
  end;
end;


procedure TfrmMain.tbToggleVirtualClick(Sender: TObject);
begin
  if XSettings.System.UserEnabledVirtual then begin
    tbToggleVirtual.ImageIndex := 16;

    tbToggleVirtual.Hint       := XText[rsIgnoreVirtualFolders] + ' [' + XText[rsEnabled] + ']';

    XSettings.System.UserEnabledVirtual := False;

    GXinorbisScan.AllowVirtual          := False;
  end
  else begin
    tbToggleVirtual.ImageIndex := 15;

    tbToggleVirtual.Hint       := XText[rsIgnoreVirtualFolders] + ' [' + XText[rsDisabled] + ']';

    XSettings.System.UserEnabledVirtual := True;

    GXinorbisScan.AllowVirtual          := True;
  end;
end;

procedure TfrmMain.lWelcomeFolderHistoryMouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if ssLeft in shift then
    SetSidePanelDisplay(2, NullEntry, NullEntry, 1)
  else if ssMiddle in shift then
     miReportBrowserClick(nil);
end;


procedure TfrmMain.lWelcomeWebReportsClick(Sender: TObject);
 begin
  SetSidePanelDisplay(5, NullEntry, NullEntry, 1);
end;



procedure TfrmMain.lHelpSendFeedbackClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'mailto:xinorbis@maximumoctopus.com?Subject=Xinorbis Feedback', '', '');
end;


procedure TfrmMain.BuildSummary(aDataIndex, aFileCatMode : integer);
var
  zSize, zCount, t : integer;
  lDirList          : TAdvStringGrid;

begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 1), 'BuildSummary :: invalid dataindex :: ' +inttostr(aDataindex));

  lDirList := FrameReports[aDataIndex].sgDirList;

//  if XSettings.Debug then frmLog.AddToLog('BuildSummary : ' + IntToStr(DataIndex) + '/' + IntToStr(GScanDetails[DataIndex].Files.Count) + '/' + IntToStr(GScanDetails[DATAINDEX].FileCount) + '/' + IntToStr(GScanDetails[DATAINDEX].TotalSize));

  //
  if GScanDetails[aDataIndex].FileCount <> 0 then
  begin
    sbMain.Panels[0].Text := '<b>' + IntToStr(GScanDetails[aDataIndex].FileCount) + '</b> ' + XText[rsFiles] + '  ::  ' +
                             '<b>' + IntToStr(GScanDetails[aDataIndex].FolderCount) + '</b> ' + XText[rsFolders] + '  ::  ' +
                             XText[rsSize] + ': <b>' + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].TotalSize) + '</b>';
  end
  else
  begin
    sbMain.Panels[0].Text := '<b>' + IntToStr(GScanDetails[aDataIndex].FileCount) + '</b> ' + XText[rsFiles] + '  ::  ' +
                             '<b>' + IntToStr(GScanDetails[aDataIndex].FolderCount) + '</b> ' + XText[rsFolders] + '  ::  ' +
                             XText[rsSize] + ': <b>' + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].TotalSize) + '</b>';
  end;

  FrameSummary[aDataIndex].BuildPreamble;

  // == files and folder =======================================================

  FrameSummary[aDataIndex].BuildFileFolders(GScanDetails[aDataIndex].FileAttributes[FileType_Null, 0],
                                            GScanDetails[aDataIndex].FileAttributes[FileType_NullFolder, 0]);

  //-- largest folder ----------------------------------------------------------

  zSize  := 1;
  zCount := 1;

  for t := 1 to FrameReports[aDataIndex].sgDirList.RowCount - 1 do begin
    if StrToInt(lDirList.Cells[2, t]) > StrToInt(lDirList.Cells[2, zCount])    then zCount := t;

    if StrToInt64(lDirList.Cells[8, t]) > StrToInt64(lDirList.Cells[8, zSize]) then zSize  := t;
  end;

  FrameSummary[aDataIndex].BuildLargestFile(FrameReports[aDataIndex].sgDirList.Cells[1, zSize], lDirList.Cells[5, zSize], TXFormatting.ReplaceEntities(lDirList.Cells[6, zSize]),
                                            FrameReports[aDataIndex].sgDirList.Cells[1, zCount], lDirList.Cells[2, zCount], TXFormatting.ReplaceEntities(lDirList.Cells[3, zCount]));

  FrameSummary[aDataIndex].SetChart(FrameSummary[aDataIndex].gSLDCount, StrToInt64(lDirList.Cells[2, zCount]), GScanDetails[aDataIndex].FileCount);
  FrameSummary[aDataIndex].SetChart(FrameSummary[aDataIndex].gSLDSize,  StrToInt64(lDirList.Cells[8, zSize]),  GScanDetails[aDataIndex].TotalSize);

  //-- largest file ------------------------------------------------------------
  FrameSummary[aDataIndex].lLFx.HTMLText[0] := FrameReports[aDataIndex].sgTop50Big.Cells[0, 1] + ' (<b>' + FrameReports[aDataIndex].sgTop50Big.Cells[1, 1] + '</b>)';

  if (GScanDetails[aDataIndex].TotalSize <> 0) and (FrameReports[aDataIndex].sgTop50Big.Cells[3, 1] <> '') then
    FrameSummary[aDataIndex].gSLF.SetDisplay((StrToInt64(FrameReports[aDataIndex].sgTop50Big.Cells[3, 1]) / GScanDetails[aDataIndex].TotalSize) * 100)
  else
    FrameSummary[aDataIndex].gSLF.SetDisplay(100);

  // == User stuff =============================================================

  if GScanDetails[aDataIndex].Users.Count <> 0 then begin
    zSize  := 1;
    zCount := 1;

    for t := 1 to FrameReports[aDataIndex].sgUsers.RowCount - 1 do begin
      if StrToInt(FrameReports[aDataIndex].sgUsers.Cells[2, t]) > StrToInt(FrameReports[aDataIndex].sgUsers.Cells[2, zCount]) then    zCount := t; // quantity of files

      if StrToInt64(FrameReports[aDataIndex].sgUsers.Cells[7, t]) > StrToInt64(FrameReports[aDataIndex].sgUsers.Cells[7, zSize]) then zSize  := t; // size of files
    end;

    FrameSummary[aDataIndex].lLUxSize.HTMLText[0]  := FrameReports[aDataIndex].sgUsers.Cells[1, zSize] + ' (<b>' + FrameReports[aDataIndex].sgUsers.Cells[5, zCount] + '</b>, <b>' + FrameReports[aDataIndex].sgUsers.Cells[6, zSize] + '</b>)';
    FrameSummary[aDataIndex].lLUxCount.HTMLText[0] := FrameReports[aDataIndex].sgUsers.Cells[1, zCount] + ' (<b>' + FrameReports[aDataIndex].sgUsers.Cells[2, zCount] + '</b>, <b>' + FrameReports[aDataIndex].sgUsers.Cells[3, zCount] + '</b>)';

    FrameSummary[aDataIndex].SetChart(FrameSummary[aDataIndex].gSLUCount, StrToInt64(FrameReports[aDataIndex].sgUsers.Cells[2, zCount]), GScanDetails[aDataIndex].FileCount);
    FrameSummary[aDataIndex].SetChart(FrameSummary[aDataIndex].gSLUSize,  StrToInt64(FrameReports[aDataIndex].sgUsers.Cells[7, zSize]),  GScanDetails[aDataIndex].TotalSize);
  end
  else begin
    FrameSummary[aDataIndex].lLUxSize.HTMLText[0]  := '-';
    FrameSummary[aDataIndex].lLUxCount.HTMLText[0] := '-';

    FrameSummary[aDataIndex].gSLUSize.SetDisplay(0);
    FrameSummary[aDataIndex].gSLUCount.SetDisplay(0);
  end;

  // == build file category stuffz =============================================

  FrameSummary[aDataIndex].BuildCapacityBars(aDataIndex);

  // == drive details ==========================================================

  FrameSummary[aDataIndex].BuildDriveSection(aDataIndex);
end;


procedure TfrmMain.IfScanCancelled(aDataIndex : integer);
 begin
  TMSLogger.Info('Scan cancelled');

  GScanDetails[aDataIndex].ClearAll;

  FrameReports[aDataIndex].ClearEverything;

  tbHomeClick(Nil);
end;


procedure TfrmMain.sgReportListCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
 begin
  if (Acol = 1) then begin
    DoSort := False;

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction := sdAscending
      else
        SortSettings.Direction := sdDescending;

      Sortsettings.Column := 5;
      QSort;

      SortSettings.Column := Acol;
    end;
  end
  else if (Acol = 2) then begin
    DoSort := False;

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction := sdAscending
      else
        SortSettings.Direction := sdDescending;

      Sortsettings.Column := 6;
      QSort;

      SortSettings.Column := Acol;
    end;
  end
end;


procedure TfrmMain.AnaylseDataThreadOnTerminate(Sender : TObject);
 begin
//  AnalyseDataThread := Nil;
end;


procedure TfrmMain.RequestNewScan(aDataIndex : integer; aFromFile : boolean; const aNewPath : string);
begin
  if aFromFile then begin
    if Pos('.zsr2', aNewPath) <> 0 then
      XinorbisScan(aDataIndex, '', aNewPath, ScanTypeNormal, ScanSourceFileXin2Detailed)
    else if Pos('.zsr', aNewPath) <> 0 then
      XinorbisScan(aDataIndex, '', aNewPath, ScanTypeNormal, ScanSourceFileXinDetailed)
    else
      BuildMainFromCSV(aDataIndex, aNewPath);
  end
  else
    XinorbisScan(aDataIndex, aNewPath, '', ScanTypeNormal, ScanSourceLive);
end;


procedure TfrmMain.ScanFromFolderHistory(const aScanPath, aTableName : string; aFileHistoryDate : string);
begin
  XinorbisScan(dataFolderHistory, aScanPath, aTableName, ScanTypeNormal, ScanSourceFolderHistory);

  GScanDetails[dataFolderHistory].ScanDateFHStr := aFileHistoryDate;
end;

procedure TfrmMain.RequestNewCombineScan(const aStatus : integer);
begin
  CombineScan;
end;


procedure TfrmMain.RequestNewSummary(aDataIndex : integer; const aAutoOpen : integer);
begin
  BuildSummary(aDataIndex, 0);
end;


procedure TfrmMain.RequestNewFHPath(const aPath : string);
begin
  if aPath <> '' then begin
    lWelcomeFolderHistoryMouseDown(lWelcomeFolderHistory, mbLeft, [ssLeft], 0, 0);

    FrameFolderHistory.SelectedPath := aPath;
  end;
end;


procedure TfrmMain.RequestNewSearch(aDataIndex : integer; const aNewSearch : string);
begin
  SetSidePanelDisplay(NullEntry, 4, NullEntry, 1);
  // make sure to set menu and show search frame ^ ?

  FrameSearch.DoSearch(aNewSearch);
end;


function  TfrmMain.OnGetLeftOffset: integer;
begin
  Result := Left + pNavigation.Width + 5;
end;


function  TfrmMain.OnGetTopOffset: integer;
begin
  Result := Top + pNavigation.Top;
end;


function  TfrmMain.IsFolderHistoryRunning: boolean;
begin
  Result := GUpdateFolderHistoryUpdateThread <> Nil;
end;


procedure TfrmMain.ScanOnProgress(const aCount : integer);
begin
  XSettings.Forms.ProgressForm.SetStatus3(IntToStr(aCount));
end;


procedure TfrmMain.ClearLanguage1Click(Sender: TObject);
begin
  {$IFDEF debug}
  XSettings.CurrentLanguage := LanguageUNDEFINED;
  {$ENDIF}
end;





procedure TfrmMain.NewSourceAvailable(aSource : integer);
begin
  case aSource of
    dataLatestScan    : begin
                          tbSourceLive.Enabled := True;

                          tbSourceLiveClick(Nil);
                        end;

    dataFolderHistory : begin
                          tbSourceFolderHistory.Enabled := True;

                          tbSourceFolderHistoryClick(Nil);
                        end;
  end;
end;


procedure TfrmMain.ActivateSource(aSource : integer);
begin
  case aSource of
    dataLatestScan    : begin
                          DeactivateSource(dataFolderHistory);

                          tbSourceLive.Color   := clMoneyGreen;
                          tbSourceLive.ColorTo := clNone;
                        end;

    dataFolderHistory : begin
                          DeactivateSource(dataLatestScan);

                          tbSourceFolderHistory.Color   := clMoneyGreen;
                          tbSourceFolderHistory.ColorTo := clNone;
                        end;
  end;

  UpdateMainMenu;

  DoNavigationHistoryAction(NavigationHistory[tbHome.Tag]);
end;


procedure TfrmMain.DeactivateSource(aSource : integer);
begin
  case aSource of
    dataLatestScan    : begin
                          tbSourceLive.Color   := clBtnFace;
                          tbSourceLive.ColorTo := clNone;
                        end;

    dataFolderHistory : begin
                          tbSourceFolderHistory.Color   := clBtnFace;
                          tbSourceFolderHistory.ColorTo := clNone;
                        end;
  end;
end;


procedure TfrmMain.DoUpdateBalloon;
begin
  if GSystemGlobal.NewVersionAvailable then begin
    trayIcon.BalloonHint := XText[rsANewVersionIsAvailable];

    trayIcon.ShowBalloonHint;
  end
end;


5569 */
