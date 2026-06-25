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

#include "XFrameProperties.h"
#include "XFrameSelect.h"
#include "XFrameSummary.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SystemGlobal* GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TForm1::FormCreate(TObject *Sender)
{
	GSystemGlobal = new SystemGlobal();

	CreateFrames();

	SetLanguageText();
}


void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//
}


#pragma region Application_Init
void TForm1::CreateFrames()
{
	FrameSelect = new TFrameSelect(this);
	FrameSelect->Parent = pMainCanvas;
	FrameSelect->Align = alClient;
	FrameSelect->OnNewScan = std::bind(OnNewScan, std::placeholders::_1);

	FrameSummary = new TFrameSummary(this);
	FrameSummary->Parent = pMainCanvas;
	FrameSummary->Align = alClient;
	FrameSummary->Visible = false;

	FrameProperties = new TFrameProperties(this);
	FrameProperties->Parent = pMainCanvas;
	FrameProperties->Align = alClient;
	FrameProperties->Visible = false;
}


void TForm1::SetLanguageText()
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
#pragma end_region


#pragma region Frame_Select
void __fastcall TForm1::OnNewScan(const std::wstring folder)
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
void TForm1::PostScan()
{
	FrameSummary->Update();

    FrameProperties->Update();
}
#pragma end_region


#pragma region Top_Toolbar
void __fastcall TForm1::tbSaveReportsClick(TObject *Sender)
{
//
}


void __fastcall TForm1::tbOpenClick(TObject *Sender)
{
//
}


void __fastcall TForm1::tbSettingsClick(TObject *Sender)
{
//
}


void __fastcall TForm1::tbWizardClick(TObject *Sender)
{
//
}


void __fastcall TForm1::tbRefreshClick(TObject *Sender)
{
//
}


void __fastcall TForm1::tbAboutClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Gui_Views
void TForm1::ToggleSoftwareStatus(bool newstatus)
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


void __fastcall TForm1::lTaskID1Click(TObject *Sender)
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


void TForm1::SetSidePanelDisplay(int WelcomeId, int TaskId, int TaskSubId, bool AddToHistory)
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


void TForm1::SetWelcomeDisplay(int WelcomeId)
{/*
  for t := 1 to SideMenuWelcomeCount do begin
	if t <> welcomeID then begin
	  WelcomeOptions[t].Font.Style := [];
	end;
  end;

  if (welcomeID <> -1) and (welcomeID <= SideMenuWelcomeCount) then
	WelcomeOptions[welcomeID].Font.Style := [fsBold]; */
}


void TForm1::DoWelcome(int WelcomeId)
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


void TForm1::DoTask(int TaskId, int TaskSubId)
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
		break;
	case 4:
		HandleResizing(pMainSearchPanelIndex);

		FrameSearch.Source := FSource;
		FrameSearch.SetTab(0);
		FrameSearch.BringToFront;
		break;
	case 5:
		HandleResizing(pMainMapPanelIndex);

		UpdateFrameMap;

		FrameMap.BringToFront;
		break;
	case 6:
		HandleResizing(pMainSearchPanelIndex);

		FrameSearch.Source := FSource;
		FrameSearch.SetTab(2);
		FrameSearch.BringToFront;
		break;
	case 7:
		HandleResizing(pMainSearchPanelIndex);

		FrameSearch.Source := FSource;
		FrameSearch.SetTab(3);
		FrameSearch.BringToFront;
		break;
	case 8:
		HandleResizing(pMainExploderPanelIndex);

		UpdateFrameExploder;

		FrameExploder.BringToFront;
		break;       */
	}

//	if XSettings.System.Tutorial then
//      OnTutorialBarChange(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
//,												  '\tutorial\t' + IntToStr(aTaskID) + '.dat');
}


void TForm1::HandleResizing(int NewPanelInFront)
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
			break; /*
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
								   end;*/
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
		break;                   /*
	case pMainNavigationPanelIndex  : begin
								 FrameNavigation[FSource].Visible := True;
								 FrameNavigation[FSource].Align   := alClient;

								 FrameNavigation[FSource].Panel25Resize(nil);
								 FrameNavigation[FSource].Panel26Resize(nil);
							   end;
	case pMainSearchPanelIndex      : begin
								 FrameSearch.Visible := True;
								 FrameSearch.Align   := alClient;
								 FrameSearch.FrameResize(Nil);
							   end;
	case pMainFileHistoryPanelIndex : begin
								 FrameFolderHistory.Visible := True;
								 FrameFolderHistory.Align   := alClient;

								 FrameFolderHistory.tpFHStatsResize(Nil);
							   end;
	case pMainWebReportsPanelIndex  : begin
								 FrameWebReports.Visible := True;
								 FrameWebReports.Align   := alClient;
							   end;
	case pMainMapPanelIndex         : begin
								 FrameMap.Visible := True;
								 FrameMap.Align   := alClient;
								end;
	case pMainExploderPanelIndex    : begin
								 FrameExploder.Visible := True;
								 FrameExploder.Align   := alClient;   */
	}
}
#pragma end_region

