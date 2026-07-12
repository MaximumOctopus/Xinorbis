//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormEditTreeReport.h"

#include "ConstantsGui.h"
#include "Convert.h"
#include "FormDetails.h"
#include "LanguageHandler.h"
#include "ReportTreeOptions.h"
#include "SettingsHandler.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEditTreeReport *FormEditTreeReport;
//---------------------------------------------------------------------------
__fastcall TFormEditTreeReport::TFormEditTreeReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


TreeReportOptions OpenTreeReportOptions(int report_id, bool one_off_custom)
{
	TFormEditTreeReport *FormEditTreeReport = new TFormEditTreeReport(Application);

	FormEditTreeReport->SetOneOff(one_off_custom);

	FormEditTreeReport->cbTreeLayouts->ItemIndex = report_id;

	FormEditTreeReport->sbEditTreeLayoutClick(NULL);

	if (one_off_custom)
	{
		FormEditTreeReport->sbEditTreeLayout->Visible = false;
		FormEditTreeReport->cbTreeLayouts->Visible = false;
	}

	FormEditTreeReport->ShowModal();

	TreeReportOptions tro = FormEditTreeReport->InternalReport;

	delete FormEditTreeReport;

	return tro;
}


void __fastcall TFormEditTreeReport::FormCreate(TObject *Sender)
{
    Init();
}


void __fastcall TFormEditTreeReport::FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
		  int &MaxWidth, int &MaxHeight)
{
	MinWidth = 600;
	MinHeight = 510;
}


void __fastcall TFormEditTreeReport::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormEditTreeReport, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


void TFormEditTreeReport::Init()
{
	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormEditTreeReport);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}

	// ===========================================================================

	Caption = (GLanguageHandler->Text[kCustomise] + L" " + GLanguageHandler->Text[kTree] + L" " + GLanguageHandler->Text[kReport]).c_str();

	sbSave->Caption           = GLanguageHandler->Text[kSave].c_str();
	sbCancel->Caption         = GLanguageHandler->Text[kCancel].c_str();
	sbEditTreeLayout->Caption = GLanguageHandler->Text[kEdit].c_str();

	sbPreview->Caption        = GLanguageHandler->Text[kPreview].c_str();
	cbAutoRefresh->Caption    = GLanguageHandler->Text[kAutoRefresh].c_str();

	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbTreeLayouts->ItemIndex = 0;

	// ===========================================================================

	gbOptions->Caption    = GLanguageHandler->Text[kOutputOptions].c_str();
	cbFileSize->Caption   = GLanguageHandler->Text[kFileSize].c_str();
	cbAttributes->Caption = GLanguageHandler->Text[kFileAttributes].c_str();
	gbCategories->Caption = GLanguageHandler->Text[kSelectCategories].c_str();

	for (int t = 0; t < 19; t++)
	{
		clbCategoryOptions->Items->Add(GLanguageHandler->TypeDescriptions[t].c_str());
	}
}


void TFormEditTreeReport::SetOneOff(bool ofc)
{
	OneOffCustom = ofc;
}


void __fastcall TFormEditTreeReport::sbSaveClick(TObject *Sender)
{
	BuildReport(InternalReport);

	if (!OneOffCustom)
	{
		GSettingsHandler->Reports.Tree[cbTreeLayouts->ItemIndex] = InternalReport;
	}

	ModalResult = mrOk;
}


void __fastcall TFormEditTreeReport::sbCancelClick(TObject *Sender)
{
	InternalReport.Layout = L"$";

	ModalResult = mrCancel;
}


void TFormEditTreeReport::BuildReport(TreeReportOptions tro)
{
	std::wstring s = L"";

	for (int t = 0; t < 19; t++)
	{
		s += std::to_wstring(Convert::BoolToInteger(clbCategoryOptions->Checked[t]));
	}

	tro.LoadCategoryList(s);
	tro.IncludeSize = cbFileSize->Checked;
	tro.IncludeAttributes = cbAttributes->Checked;
}


void TFormEditTreeReport::UpdateDisplay()
{
	for (int t = 0; t < 19; t++)
	{
		if (InternalReport.CategoryList[t])
		{
			clbCategoryOptions->Checked[t] = true;
		}
		else
		{
			clbCategoryOptions->Checked[t] = false;
		}
	}

	cbFileSize->Checked = InternalReport.IncludeSize;
	cbAttributes->Checked = InternalReport.IncludeAttributes;
}


void __fastcall TFormEditTreeReport::sbSetAllClick(TObject *Sender)
{
	bool mode = false;

	TSpeedButton* sb = (TSpeedButton*)Sender;

	if (sb->Tag == 0)
	{
		mode = true;
	}

	for (int t = 0; t < clbCategoryOptions->Count; t++)
	{
		clbCategoryOptions->Checked[t] = mode;
	}

	cbAutoRefreshClick(NULL);
}


void __fastcall TFormEditTreeReport::sbEditTreeLayoutClick(TObject *Sender)
{
	InternalReport = GSettingsHandler->Reports.Tree[cbTreeLayouts->ItemIndex];

	if (InternalReport.Layout != L"")
	{
		UpdateDisplay();

		sbPreviewClick(NULL);
	}
}


void __fastcall TFormEditTreeReport::sbPreviewClick(TObject *Sender)
{
	std::vector<std::wstring> ReportOutput;

	BuildReport(InternalReport);

	// to do GReportTree.GenerateTreeReport(ReportOutput, InternalReport);

	Memo1->Clear();

	for (int t = 0; t < ReportOutput.size(); t++)
	{
		Memo1->Lines->Add(ReportOutput[t].c_str());
	}
}


void __fastcall TFormEditTreeReport::SpeedButton1Click(TObject *Sender)
{
	//THelp.OpenHelpPage("report_tree.htm");
}


void __fastcall TFormEditTreeReport::cbAutoRefreshClick(TObject *Sender)
{
	if (cbAutoRefresh->Checked)
	{
		sbPreviewClick(NULL);
	}
}


void __fastcall TFormEditTreeReport::clbCategoryOptionsClick(TObject *Sender)
{
	cbAutoRefreshClick(NULL);
}
