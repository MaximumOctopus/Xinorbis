//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormEditTextReport.h"

#include "ConstantsGui.h"
#include "ConstantsReports.h"
#include "Convert.h"
#include "FormDetails.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEditTextReport *FormEditTextReport;
//---------------------------------------------------------------------------
__fastcall TFormEditTextReport::TFormEditTextReport(TComponent* Owner)
	: TForm(Owner)
{
}


TextReportOptions OpenTextReportOptions(int report_id, bool one_off_custom)
{
	TFormEditTextReport* FormEditTextReport = new TFormEditTextReport(Application);

	FormEditTextReport->OneOffCustom = one_off_custom;

	FormEditTextReport->cbTextLayouts->ItemIndex = report_id;

//	  sbEditHTMLLayoutClick(Nil);

	if (one_off_custom)
	{
		FormEditTextReport->sbEditTextLayout->Visible = false;
		FormEditTextReport->cbTextLayouts->Visible    = false;
	}

	FormEditTextReport->ShowModal();

	TextReportOptions textro = FormEditTextReport->InternalReport;

	delete FormEditTextReport;

	return textro;
}


void __fastcall TFormEditTextReport::FormConstrainedResize(TObject *Sender, int &MinWidth,
		  int &MinHeight, int &MaxWidth, int &MaxHeight)
{
	MinWidth  = 700;
	MinHeight = 524;
}


void __fastcall TFormEditTextReport::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormEditHTMLReport, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


void TFormEditTextReport::Init()
{
	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormEditTextReport);

	if (fd.FormId != -1)
	{
		Left             = fd.X;
		Top              = fd.Y;
		Width            = fd.Width;
		Height           = fd.Height;
	}

	// ===========================================================================

	Caption = (GLanguageHandler->Text[kCustomise] + L" " + GLanguageHandler->Text[kText] + L" " + GLanguageHandler->Text[kReport]).c_str();

	sbSave->Caption           = GLanguageHandler->Text[kSave].c_str();
	sbCancel->Caption         = GLanguageHandler->Text[kCancel].c_str();
	sbEditTextLayout->Caption = GLanguageHandler->Text[kEdit].c_str();

	sbPreview->Caption        = GLanguageHandler->Text[kPreview].c_str();
	cbAutoRefresh->Caption    = GLanguageHandler->Text[kAutoRefresh].c_str();

	// ===========================================================================

	LayoutItems[0] = lSI1;   LayoutItems[1] = lSI2;
	LayoutItems[2] = lSI3;   LayoutItems[3] = lSI4;
	LayoutItems[4] = lSI5;   LayoutItems[5] = lSI6;
	LayoutItems[6] = lSI7;   LayoutItems[7] = lSI8;
	LayoutItems[8] = lSI9;   LayoutItems[9] = lSI10;
	LayoutItems[10] = lSI11; LayoutItems[11] = lSI12;
	LayoutItems[12] = lSI13; LayoutItems[13] = lSI14;
	LayoutItems[14] = lSI15; LayoutItems[15] = lSI16;
	LayoutItems[16] = lSI17;

	for (int t = 0; t < __TextItemsCount; t++)
	{
		LayoutItems[t]->Caption = GLanguageHandler->GenericReportItems[t].c_str();
	}

	cbTextLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbTextLayouts->ItemIndex = 0;

	for (int t = 0; t < 20; t++)
	{
		clbCategoryOptions->Items->Add(GLanguageHandler->TypeDescriptions[t].c_str());
	}

	//== languagey stuff =========================================================

	lImportant->Caption       = GLanguageHandler->Text[kMaySlowDownReport].c_str();
	Label1->Caption           = (GLanguageHandler->Text[kAvailable] + L" " + GLanguageHandler->Text[kText] + L" " + GLanguageHandler->Text[kReportItems]).c_str();
	Label2->Caption           = (GLanguageHandler->Text[kText] + L" " + GLanguageHandler->Text[kReportLayout]).c_str();
	bCloseAC->Caption         = GLanguageHandler->Text[kHide].c_str();
	lAC->Caption              = GLanguageHandler->Text[kSelectCategories].c_str();
	bAdvanced->Caption        = GLanguageHandler->Text[kCategories].c_str();
}


void __fastcall TFormEditTextReport::sbSaveClick(TObject *Sender)
{
	// save report stuff =========================================================

	BuildReport(InternalReport);

	// save colours ==============================================================

	if (!OneOffCustom)
	{
		GSettingsHandler->Reports.Text[cbTextLayouts->ItemIndex] = InternalReport;
	}

	ModalResult = mrOk;
}

void __fastcall TFormEditTextReport::sbEditTextLayoutClick(TObject *Sender)
{
	InternalReport = GSettingsHandler->Reports.Text[cbTextLayouts->ItemIndex];

	if (InternalReport.Layout != L"")
	{
		UpdateDisplay();

		sbPreviewClick(NULL);
	}
}


void __fastcall TFormEditTextReport::sbUpClick(TObject *Sender)
{
	if (lbSummaryLayout->ItemIndex > 0)
	{
		int a = lbSummaryLayout->ItemIndex - 1;

		lbSummaryLayout->Items->Move(lbSummaryLayout->ItemIndex, lbSummaryLayout->ItemIndex - 1);

		lbSummaryLayout->ItemIndex = a;

		AutoRefresh();
	}
}


void __fastcall TFormEditTextReport::sbDownClick(TObject *Sender)
{
	if (lbSummaryLayout->ItemIndex != -1)
	{
		if (lbSummaryLayout->ItemIndex < lbSummaryLayout->Items->Count - 1)
		{
			int a = lbSummaryLayout->ItemIndex + 1;

			lbSummaryLayout->Items->Move(lbSummaryLayout->ItemIndex, lbSummaryLayout->ItemIndex + 1);

			lbSummaryLayout->ItemIndex = a;

			AutoRefresh();
		}
	}
}


void __fastcall TFormEditTextReport::sbRemoveClick(TObject *Sender)
{
	lbSummaryLayout->DeleteSelected();

	AutoRefresh();
}


void __fastcall TFormEditTextReport::sbPreviewClick(TObject *Sender)
{
	std::vector<std::wstring> Output;

	BuildReport(InternalReport);

	// TO DO GReportText.GenerateTextReport(FSource, lReportOutput, InternalReport);

	Memo1->Clear();

	for (int t = 0; t < Output.size(); t++)
	{
		Memo1->Lines->Add(Output[t].c_str());
	}
}


void __fastcall TFormEditTextReport::bAdvancedClick(TObject *Sender)
{
	pCategoryOptions->BringToFront();
	pCategoryOptions->Visible = true;
}


void __fastcall TFormEditTextReport::SpeedButton3Click(TObject *Sender)
{
//	THelp.OpenHelpPage('report_text.htm');
}


void __fastcall TFormEditTextReport::SpeedButton2Click(TObject *Sender)
{
	for (int t = 0; t < clbCategoryOptions->Items->Count; t++)
	{
		clbCategoryOptions->Checked[t] = false;
	}
}


void __fastcall TFormEditTextReport::SpeedButton1Click(TObject *Sender)
{
	for (int t = 0; t < clbCategoryOptions->Items->Count; t++)
	{
		clbCategoryOptions->Checked[t] = true;
	}
}


void __fastcall TFormEditTextReport::bCloseACClick(TObject *Sender)
{
	pCategoryOptions->SendToBack();
	pCategoryOptions->Visible = false;
}


void __fastcall TFormEditTextReport::lbSummaryLayoutClick(TObject *Sender)
{
	bool status = true;

	if (lbSummaryLayout->ItemIndex == -1)
	{
		status = false;
	}

	sbUp->Enabled     = status;
	sbDown->Enabled   = status;
	sbRemove->Enabled = status;

	if (status)
	{
		if (lbSummaryLayout->Items->Strings[lbSummaryLayout->ItemIndex] == lSI7->Caption)
		{
			bAdvanced->Enabled = true;
		}
		else
		{
			bAdvanced->Enabled = false;
		}
	}
	else
	{
		bAdvanced->Enabled = false;
	}
}


void __fastcall TFormEditTextReport::Panel2Click(TObject *Sender)
{
	InternalReport.Layout = L"$";

	ModalResult = mrCancel;
}


void __fastcall TFormEditTextReport::lSI1Click(TObject *Sender)
{
	TLabel *label = (TLabel*)Sender;

	if (lbSummaryLayout->Items->IndexOf(label->Caption) == -1)
	{
		lbSummaryLayout->Items->Add(label->Caption);

		AutoRefresh();
	}
}


void __fastcall TFormEditTextReport::lbSummaryLayoutDblClick(TObject *Sender)
{
	lbSummaryLayout->DeleteSelected();

	sbRemove->Enabled = false;
	sbUp->Enabled     = false;
	sbDown->Enabled   = false;

	AutoRefresh();
}


void TFormEditTextReport::AutoRefresh()
{
	if (cbAutoRefresh->Checked)
	{
		sbPreviewClick(NULL);
	}
}


void TFormEditTextReport::UpdateDisplay()
{
	std::wstring s = L"";

	lbSummaryLayout->Clear();

	for (int t = 0; t < InternalReport.Layout.size(); t++)
	{
		if (InternalReport.Layout[t] == L':')
		{
			int LayoutId = StrToIntDef(s.c_str(), 99);

			if (LayoutId <= __TextItemsCount)
			{
				lbSummaryLayout->Items->Add(LayoutItems[LayoutId]->Caption);
			}

			s = L"";
		}
		else
		{
			s += InternalReport.Layout[t];
		}
	}
}


void TFormEditTextReport::BuildReport(TextReportOptions tro)
{
	std::wstring s = L"";

	for (int t = 0; t < lbSummaryLayout->Count; t++)
	{
		int idx = 0;

		for (int z = 0; z < __TextItemsCount; z++)
		{
			if (LayoutItems[z]->Caption == lbSummaryLayout->Items->Strings[t])
			{
				idx = z;
			}
		}

		s += std::to_wstring(idx) + L":";
	}

	tro.Layout = s;

	s = L"";

	for (int t = 0; t < 20; t++)
	{
		s += std::to_wstring(Convert::BoolToInteger(clbCategoryOptions->Checked[t]));
	}

	tro.LoadCategoryList(s);
}
