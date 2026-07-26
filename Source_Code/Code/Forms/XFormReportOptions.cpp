//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormReportOptions.h"
#include "XFormXinorbisDialog.h"

#include "ConstantsSettings.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}


int OpenReportSettings(int open_at_tab)
{
	TForm8 *Form8 = new TForm8(Application);

	if (open_at_tab != -1)
	{
		Form8->OpenTab = open_at_tab;
	}

	if (Form8->ShowModal() == mrOk)
	{
		Form8->UpdateSettings();
	}

	delete Form8;

	return 0; // to do, what is this?!
}


void __fastcall TForm8::FormCreate(TObject *Sender)
{
	Init();
}


void __fastcall TForm8::FormShow(TObject *Sender)
{
	switch (OpenTab)
	{
	case 8:
		pOutputOptions->BringToFront();
		break;
	case 9:
		sbASCIIClick(sbWebReports);
		break;

	default:
		pOutputOptions->BringToFront();
		break;
	}

	OpenTab = -1;
}


void TForm8::Init()
{
	Caption = GLanguageHandler->Text[kSettings].c_str();

	// ===========================================================================

	sbWebReports->Caption       = GLanguageHandler->Text[kWebReports].c_str();

	sbAutoSave->Caption         = GLanguageHandler->Text[kAutoSave].c_str();

	sbReportTree->Caption       = GLanguageHandler->Text[kTree].c_str();

	lOutputOptions->Caption     = GLanguageHandler->Text[kReportOptions].c_str();
	lReportsAutosave->Caption   = (GLanguageHandler->Text[kReportOptions] + L": Autosave").c_str();
	lReportsCSV->Caption        = (GLanguageHandler->Text[kReportOptions] + L": CSV").c_str();
	lReportsHTML->Caption       = (GLanguageHandler->Text[kReportOptions] + L": HTML").c_str();
	lReportsTree->Caption       = (GLanguageHandler->Text[kReportOptions] + L": " + GLanguageHandler->Text[kTree]).c_str();
	lReportsText->Caption       = (GLanguageHandler->Text[kReportOptions] + L": Text").c_str();
	lReportsXML->Caption        = (GLanguageHandler->Text[kReportOptions] + L": XML").c_str();
	lReportsXinorbis->Caption   = (GLanguageHandler->Text[kReportOptions] + L": Xinorbis").c_str();

	// ===========================================================================

	//  bHelp->Caption              = GLanguageHandler->Text[kHelp].c_str();
	bSave->Caption              = GLanguageHandler->Text[kSave].c_str();
	bCancel->Caption            = GLanguageHandler->Text[kCancel].c_str();

	// ===========================================================================

	lASDrive->Caption     = GLanguageHandler->Text[kAutoSaveReports].c_str();

	lADR_5->Caption       = GLanguageHandler->Text[kTree].c_str();

	lASOrganise->Caption  = GLanguageHandler->Text[kOrganiseReports].c_str();

	// ===========================================================================

	Label6->Caption             = GLanguageHandler->Text[kOpenInApplication].c_str();
	lTextDefaultOutput->Caption = GLanguageHandler->Text[kOpenInApplication].c_str();
	Label8->Caption             = GLanguageHandler->Text[kOpenInApplicationsDefault].c_str();
	Label29->Caption            = GLanguageHandler->Text[kOpenInApplicationsDefault].c_str();

	// document options ==========================================================

	lDocOptions->Caption = GLanguageHandler->Text[kDocOptions].c_str();

	// == report main menu =======================================================

	lReportMenuTree->Caption = GLanguageHandler->Text[kTree].c_str();

	// == text tab ===============================================================

	// ===========================================================================

	gbXReportType->Caption     = GLanguageHandler->Text[kChooseReportType].c_str();
	rbXReportNormal->Caption   = GLanguageHandler->Text[kNormal].c_str();
	rbXReportDetailed->Caption = GLanguageHandler->Text[kDetailed].c_str();

	cbXinorbisLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbXinorbisLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbXinorbisLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbXinorbisLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbXinorbisLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbXinorbisLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbXinorbisLayouts->ItemIndex = 0;

	// == FTP ====================================================================

	Label47->Caption = GLanguageHandler->Text[kWebReports].c_str();
	Label48->Caption = GLanguageHandler->Text[kFTPHost].c_str();
	Label49->Caption = GLanguageHandler->Text[kFTPUsername].c_str();
	Label50->Caption = GLanguageHandler->Text[kFTPPassword].c_str();
	Label53->Caption = GLanguageHandler->Text[kInitialFolder].c_str();
	Label51->Caption = GLanguageHandler->Text[kReportsFolder].c_str();
	Label52->Caption = GLanguageHandler->Text[kReportsURL].c_str();

	eFTPHost->Text          = GSettingsHandler->FTP.Options[kFTPOptionHost].c_str();
	eFTPUsername->Text      = GSettingsHandler->FTP.Options[kFTPOptionUserName].c_str();
	eFTPPassword->Text      = GSettingsHandler->FTP.Options[kFTPOptionPassword].c_str();
	eFTPRemoteFolder->Text  = GSettingsHandler->FTP.Options[kFTPOptionRemoteFolder].c_str();
	eFTPLink->Text          = GSettingsHandler->FTP.Options[kFTPOptionActualLink].c_str();
	eFTPInitialFolder->Text = GSettingsHandler->FTP.Options[kFTPOptionInitialFolder].c_str();

	// =======================================================================

	cbASDrive->State = BooleanToSliderState(GSettingsHandler->Reports.AutoSaveMode);
	cbASDriveClick(NULL);

	cbADR_1->State   = BooleanToSliderState(GSettingsHandler->Reports.AutoSaveItem[0]);
	cbADR_2->State   = BooleanToSliderState(GSettingsHandler->Reports.AutoSaveItem[1]);
	cbADR_3->State   = BooleanToSliderState(GSettingsHandler->Reports.AutoSaveItem[2]);
	cbADR_4->State   = BooleanToSliderState(GSettingsHandler->Reports.AutoSaveItem[3]);
	cbADR_9->State   = BooleanToSliderState(GSettingsHandler->Reports.AutoSaveItem[4]);
	cbADR_5->State   = BooleanToSliderState(GSettingsHandler->Reports.AutoSaveItem[5]);

	// =======================================================================

	cbXinorbisLayoutsChange(NULL);

	eOOHTMLOutput->Text = GSettingsHandler->Reports.HTMLOutput.c_str();
	eOOXMLOutput->Text  = GSettingsHandler->Reports.XMLOutput.c_str();
	eOOCSVOutput->Text  = GSettingsHandler->Reports.CSVOutput.c_str();
	eOOTextOutput->Text = GSettingsHandler->Reports.TextOutput.c_str();
}


void TForm8::UpdateSettings()
{
	GSettingsHandler->FTP.Options[kFTPOptionHost]          = eFTPHost->Text;
	GSettingsHandler->FTP.Options[kFTPOptionUserName]      = eFTPUsername->Text;
	GSettingsHandler->FTP.Options[kFTPOptionPassword]      = eFTPPassword->Text;
	GSettingsHandler->FTP.Options[kFTPOptionRemoteFolder]  = eFTPRemoteFolder->Text;
	GSettingsHandler->FTP.Options[kFTPOptionActualLink]    = eFTPLink->Text;
	GSettingsHandler->FTP.Options[kFTPOptionInitialFolder] = eFTPInitialFolder->Text;

	// ---------------------------------------------------------------------

	GSettingsHandler->Reports.HTMLOutput = eOOHTMLOutput->Text.c_str();
	GSettingsHandler->Reports.XMLOutput  = eOOXMLOutput->Text.c_str();
	GSettingsHandler->Reports.CSVOutput  = eOOCSVOutput->Text.c_str();
	GSettingsHandler->Reports.TextOutput = eOOTextOutput->Text.c_str();

	GSettingsHandler->Reports.AutoSaveItem[0] = SliderStateToBoolean(cbADR_1->State);
	GSettingsHandler->Reports.AutoSaveItem[1] = SliderStateToBoolean(cbADR_2->State);
	GSettingsHandler->Reports.AutoSaveItem[2] = SliderStateToBoolean(cbADR_3->State);
	GSettingsHandler->Reports.AutoSaveItem[3] = SliderStateToBoolean(cbADR_4->State);
	GSettingsHandler->Reports.AutoSaveItem[4] = SliderStateToBoolean(cbADR_9->State);
	GSettingsHandler->Reports.AutoSaveItem[5] = SliderStateToBoolean(cbADR_5->State);

	GSettingsHandler->Reports.AutoSaveMode    = SliderStateToBoolean(cbASDrive->State);
}


bool TForm8::SliderStateToBoolean(TToggleSwitchState state)
{
	if (state == TToggleSwitchState::tssOff)
	{
		return false;
	}

	return true;
}


TToggleSwitchState TForm8::BooleanToSliderState(bool state)
{
	if (state)
	{
		return TToggleSwitchState::tssOn;
	}

	return TToggleSwitchState::tssOff;
}


#pragma region Section_Ascii
#pragma end_region


#pragma region Section_CSV
void __fastcall TForm8::SpeedButton9Click(TObject *Sender)
{
	std::wstring file_name = LoadDialogs::ExecuteExe(L"");

	if (!file_name.empty())
	{
		eOOCSVOutput->Text = file_name.c_str();
	}
}
#pragma end_region


#pragma region Section_HTML
#pragma end_region


#pragma region Section_Tree
#pragma end_region


#pragma region Section_Xinorbis
void __fastcall TForm8::cbXinorbisLayoutsChange(TObject *Sender)
{
	BuildXinorbisLayoutList(GSettingsHandler->Reports.Xinorbis[cbXinorbisLayouts->ItemIndex].Layout);
}


void TForm8::BuildXinorbisLayoutList(int layout)
{
	if (GSettingsHandler->Reports.Xinorbis[cbXinorbisLayouts->ItemIndex].Layout == 0)
	{
		rbXReportNormal->Checked = true;
	}
	else
	{
		rbXReportDetailed->Checked = true;
	}
}


void __fastcall TForm8::rbXReportNormalClick(TObject *Sender)
{
	if (rbXReportNormal->Checked)
	{
		GSettingsHandler->Reports.Xinorbis[cbXinorbisLayouts->ItemIndex].Layout = 0;
	}
	else
	{
		GSettingsHandler->Reports.Xinorbis[cbXinorbisLayouts->ItemIndex].Layout = 1;
	}
}
#pragma end_region


#pragma region Section_XML
void __fastcall TForm8::SpeedButton3Click(TObject *Sender)
{
	std::wstring file_name = LoadDialogs::ExecuteExe(L"");

	if (!file_name.empty())
	{
		eOOXMLOutput->Text = file_name.c_str();
	}
}
#pragma end_region


#pragma region Section_Autosave
void __fastcall TForm8::cbASDriveClick(TObject *Sender)
{
	cbADR_1->Enabled = SliderStateToBoolean(cbASDrive->State);
	cbADR_2->Enabled = SliderStateToBoolean(cbASDrive->State);
	cbADR_3->Enabled = SliderStateToBoolean(cbASDrive->State);
	cbADR_4->Enabled = SliderStateToBoolean(cbASDrive->State);
	cbADR_9->Enabled = SliderStateToBoolean(cbASDrive->State);
	cbADR_5->Enabled = SliderStateToBoolean(cbASDrive->State);
}
#pragma end_region


#pragma region Section_WebReports
void __fastcall TForm8::bTestFTPClick(TObject *Sender)
{
	lWebReportTest->Visible = true;

	ftpMain->Host     = eFTPHost->Text;
	ftpMain->Username = eFTPUsername->Text;
	ftpMain->Password = eFTPPassword->Text;

	int ftperror = 0;

	try
	{
		ftpMain->Connect();

		if (eFTPInitialFolder->Text != L"")
		{
			ftpMain->ChangeDir(eFTPInitialFolder->Text);
		}

		if (eFTPRemoteFolder->Text != L"")
		{
			TStringList *tsl = new TStringList();

			ftpMain->List(tsl, eFTPRemoteFolder->Text, true);

			if (tsl->Count == 0)
			{
				ftpMain->MakeDir(eFTPRemoteFolder->Text);
			}

			ftpMain->ChangeDir(eFTPRemoteFolder->Text);

			delete tsl;
		}

		std::wstring putfn = GSystemGlobal->ExePath + L"data\\languages\\" + GLanguageHandler->GetLanguageSymbol(GLanguageHandler->CurrentLanguage) + L"\\ftptest.htm";

		ftpMain->Put(putfn.c_str(), L"ftptest.htm");
	}
	catch(...)
	{
		ftperror = -1;
		// to do log TMSLogger.Error("FTP test exception: " + E.Message + " / " + E.ClassName);
	}

	if (ftperror == 0)
	{
		std::wstring ftplink = eFTPLink->Text.c_str();

		WindowsUtility::ExecuteFile(ftplink + L"/ftptest.htm", L"");
	}
	else
    {
		ShowXDialog(GLanguageHandler->Text[kError] + L": FTP upload",
					GLanguageHandler->Text[kFTPUploadTestFailed],
					XDialogTypeWarning);
	}
}


void __fastcall TForm8::bOpenLinkClick(TObject *Sender)
{
	if (eFTPLink->Text != L"")
	{
		WindowsUtility::ExecuteFile(eFTPLink->Text.c_str(), L"");
	}
}
#pragma end_region


void __fastcall TForm8::sbASCIIClick(TObject *Sender)
{
	int index = -1;

	if (typeid(*Sender) == typeid(TImage))
	{
		TImage *image = (TImage*)Sender;

		index = image->Tag;
	}
	else
	{
		TSpeedButton *sb = (TSpeedButton*)Sender;

		index = sb->Tag;

		sb->Down = true;
	}

	switch (index)
	{
	case kPageAutosave:
		pReportsAutosave->BringToFront();
		break;
	case kPageCSV:
		pReportsCSV->BringToFront();
		break;
	case kPageHTML:
		pReportsHTML->BringToFront();
		break;
	case kPageXML:
		pReportsXML->BringToFront();
		break;
	case kPageText:
		pReportsText->BringToFront();
		break;
	case kPageTree:
		pReportsTree->BringToFront();
		break;
	case kPageXinorbis:
		pReportsXinorbis->BringToFront();
		break;
	case kPageWebReports:
		pWebReports->BringToFront();
		break;
	}
}


void __fastcall TForm8::SpeedButton1Click(TObject *Sender)
{
	std::wstring file_name = LoadDialogs::ExecuteExe(L"");

	if (!file_name.empty())
	{
		eOOHTMLOutput->Text = file_name.c_str();
	}
}


void __fastcall TForm8::SpeedButton10Click(TObject *Sender)
{
	std::wstring file_name = LoadDialogs::ExecuteExe(L"");

	if (!file_name.empty())
	{
		eOOTextOutput->Text = file_name.c_str();
	}
}


void __fastcall TForm8::ftpMainStatus(TObject *ASender, const TIdStatus AStatus, const UnicodeString AStatusText)
{
	lWebReportTest->Caption = AStatusText;
}


void __fastcall TForm8::ftpMainWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax)
{
	lWebReportTest->Caption = (GLanguageHandler->Text[kUploading] + kEllipsis).c_str();
}


void __fastcall TForm8::ftpMainWorkEnd(TObject *ASender, TWorkMode AWorkMode)
{
	lWebReportTest->Caption = (GLanguageHandler->Text[kUpload] + L": Finished.").c_str();
}
