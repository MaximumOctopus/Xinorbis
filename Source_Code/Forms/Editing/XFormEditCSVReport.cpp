//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <vector>

#include "XFormEditCSVReport.h"

#include "ConstantsGui.h"
#include "FormDetails.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEditCSVReport *FormEditCSVReport;
//---------------------------------------------------------------------------
__fastcall TFormEditCSVReport::TFormEditCSVReport(TComponent* Owner)
	: TForm(Owner)
{
}


CSVReportOptions OpenCSVReportOptions(int report_id, bool one_off_custom)
{
	TFormEditCSVReport* FormEditCSVReport = new TFormEditCSVReport(Application);

	FormEditCSVReport->OneOffCustom = one_off_custom;

	FormEditCSVReport->cbCSVLayouts->ItemIndex = report_id;

	//  sbEditCSVLayoutClick(Nil);

	if (one_off_custom)
	{
		FormEditCSVReport->sbEditCSVLayout->Visible = false;
		FormEditCSVReport->cbCSVLayouts->Visible    = false;
	}

	FormEditCSVReport->ShowModal();

	CSVReportOptions csvro = FormEditCSVReport->InternalReport;

	delete FormEditCSVReport;

	return csvro;
}


void __fastcall TFormEditCSVReport::FormCreate(TObject *Sender)
{
	Init();
}


void __fastcall TFormEditCSVReport::FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
		  int &MaxWidth, int &MaxHeight)
{
	MinWidth  = 500;
	MinHeight = 410;
}



void __fastcall TFormEditCSVReport::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormEditCSVReport, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


void TFormEditCSVReport::Init()
{
	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormEditCSVReport);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}

	// ===========================================================================

	Caption                   = (GLanguageHandler->Text[kCustomise] + L" CSV " + GLanguageHandler->Text[kReport]).c_str();

	sbSave->Caption           = GLanguageHandler->Text[kSave].c_str();
	sbCancel->Caption         = GLanguageHandler->Text[kCancel].c_str();
	sbEditCSVLayout->Caption  = GLanguageHandler->Text[kEdit].c_str();

	sbPreview->Caption        = GLanguageHandler->Text[kPreview].c_str();
	cbAutoRefresh->Caption    = GLanguageHandler->Text[kAutoRefresh].c_str();

	// ===========================================================================

	cbCSVLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbCSVLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbCSVLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbCSVLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbCSVLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbCSVLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbCSVLayouts->ItemIndex = 0;

	//============================================================================

	cbCSVSeparator->Items->Add(L"Comma (,)");
	cbCSVSeparator->Items->Add(L"Tab");
	cbCSVSeparator->Items->Add(L"Pling (|)");
	cbCSVSeparator->ItemIndex = 0;

	lcsvs->Caption        = GLanguageHandler->Text[kSeparator].c_str();
	lCSVTitle->Caption    = GLanguageHandler->Text[kDefaultCSVOutputSettings].c_str();
	lCSVTitles->Caption   = GLanguageHandler->Text[kIncludeColumnTitles].c_str();
	Label2->Caption       = GLanguageHandler->Text[kWhichData].c_str();
	Label27->Caption      = GLanguageHandler->Text[kShowSizesIn].c_str();
	lCSVAutoOpen->Caption = GLanguageHandler->Text[kAutoOpen].c_str();

	cbCSVData->Items->Add(GLanguageHandler->Text[kReport].c_str());
	cbCSVData->Items->Add(GLanguageHandler->Text[kFullFileList].c_str());

	cbCSVUnits->Items->Add(GLanguageHandler->Text[kMostConvenient].c_str());
	cbCSVUnits->Items->Add(GLanguageHandler->Text[kBytes].c_str());
	cbCSVUnits->Items->Add(GLanguageHandler->Text[kKilobytes].c_str());
	cbCSVUnits->Items->Add(GLanguageHandler->Text[kMegabytes].c_str());
}


void __fastcall TFormEditCSVReport::sbSaveClick(TObject *Sender)
{
	// save report stuff =========================================================

	BuildReport(InternalReport);

	// save colours ==============================================================

	if (!OneOffCustom)
	{
	   //	XSettings.Report.CSVOptions[cbCSVLayouts->ItemIndex] = InternalReport;
	}

	ModalResult = mrOk;
}


void __fastcall TFormEditCSVReport::sbCancelClick(TObject *Sender)
{
	InternalReport.Layout = L"$";

	ModalResult = mrCancel;
}


void __fastcall TFormEditCSVReport::sbEditCSVLayoutClick(TObject *Sender)
{
  	InternalReport = GSettingsHandler->Reports.CSV[cbCSVLayouts->ItemIndex];

	UpdateDisplay();

	sbPreviewClick(NULL);
}


void __fastcall TFormEditCSVReport::sbPreviewClick(TObject *Sender)
{
	std::vector<std::wstring> Preview;

	BuildReport(InternalReport);

   // TO DO	CSVPreview::Get(InternalReport, Preview);

	Memo1->Clear();

	for (int t = 0; t < Preview.size(); t++)
	{
		Memo1->Lines->Add(Preview[t].c_str());
    }
}


void __fastcall TFormEditCSVReport::SpeedButton1Click(TObject *Sender)
{
	// TO DO THelp.OpenHelpPage("report_csv.htm");
}


void __fastcall TFormEditCSVReport::cbCSVSeparatorChange(TObject *Sender)
{
	AutoRefresh();
}


void __fastcall TFormEditCSVReport::tsIncludeColumnTitlesClick(TObject *Sender)
{
	AutoRefresh();
}


void TFormEditCSVReport::UpdateDisplay()
{
	cbCSVSeparator->ItemIndex = InternalReport.Separator;
	cbCSVData->ItemIndex      = InternalReport.Data;
	cbCSVUnits->ItemIndex     = InternalReport.Units;

	if (InternalReport.Titles)
	{
		tsIncludeColumnTitles->State = tssOn;
	}
	else
	{
		tsIncludeColumnTitles->State = tssOff;
	}

	if (InternalReport.AutoOpen)
	{
		tsAutoOpen->State = tssOn;
	}
	else
	{
		tsAutoOpen->State = tssOff;
	}
}


void TFormEditCSVReport::BuildReport(CSVReportOptions csvro)
{
	csvro.Separator  = cbCSVSeparator->ItemIndex;
	csvro.Data       = cbCSVData->ItemIndex;
	csvro.Units      = cbCSVUnits->ItemIndex;

	if (tsIncludeColumnTitles->State == tssOn)
	{
		csvro.Titles = true;
	}
	else
	{
		csvro.Titles = false;
	}

	if (tsAutoOpen->State == tssOn)
	{
		csvro.AutoOpen = true;
	}
	else
	{
		csvro.AutoOpen = false;
	}
}


void TFormEditCSVReport::AutoRefresh()
{
	if (cbAutoRefresh->Checked)
	{
		sbPreviewClick(NULL);
	}
}
