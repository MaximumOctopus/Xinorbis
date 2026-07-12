//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormEditXmlReport.h"

#include "ConstantsGui.h"
#include "FormDetails.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEditXmlReport *FormEditXmlReport;
//---------------------------------------------------------------------------
__fastcall TFormEditXmlReport::TFormEditXmlReport(TComponent* Owner)
	: TForm(Owner)
{
}


XMLReportOptions OpenXMLReportOptions(int report_id, bool one_off_custom)
{
	TFormEditXmlReport *FormEditXmlReport = new TFormEditXmlReport(Application);

	FormEditXmlReport->cbXMLLayouts->ItemIndex = report_id;

//	  sbEditXMLLayoutClick(Nil);

	FormEditXmlReport->ShowModal();

	XMLReportOptions xmlro = FormEditXmlReport->InternalReport;

	delete FormEditXmlReport;

	return xmlro;
}


void __fastcall TFormEditXmlReport::FormCreate(TObject *Sender)
{
	Init();
}


void __fastcall TFormEditXmlReport::FormConstrainedResize(TObject *Sender, int &MinWidth,
		  int &MinHeight, int &MaxWidth, int &MaxHeight)
{
	MinWidth  = 700;
	MinHeight = 515;
}


void __fastcall TFormEditXmlReport::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormEditXMLReport, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


void TFormEditXmlReport::Init()
{
	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormEditXMLReport);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}

  // ===========================================================================

	Caption = (GLanguageHandler->Text[kCustomise] + L" XML " + GLanguageHandler->Text[kReport]).c_str();

	sbSave->Caption           = GLanguageHandler->Text[kSave].c_str();
	//  sbCancel->Caption         = GLanguageHandler->Text[kCancel].c_str();
	sbEditXMLLayout->Caption  = GLanguageHandler->Text[kEdit].c_str();

	Label1->Caption           = (GLanguageHandler->Text[kAvailable] + L" XML " + GLanguageHandler->Text[kReportItems]).c_str();
	Label2->Caption           = (L"XML " + GLanguageHandler->Text[kReportLayout]).c_str();
	GroupBox1->Caption        = GLanguageHandler->Text[kClickToAdd].c_str();
	lImportant->Caption       = GLanguageHandler->Text[kMaySlowDownReport].c_str();

	Label39->Caption          = GLanguageHandler->Text[kWhichData].c_str();
	lXMLAutoOpen->Caption     = GLanguageHandler->Text[kAutoOpen].c_str();

	sbPreview->Caption        = GLanguageHandler->Text[kPreview].c_str();
	cbAutoRefresh->Caption    = GLanguageHandler->Text[kAutoRefresh].c_str();

	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbXMLLayouts->ItemIndex = 0;

	cbXMLData->Items->Add(GLanguageHandler->Text[kReport].c_str());
	cbXMLData->Items->Add(GLanguageHandler->Text[kFullFileList].c_str());

	cbXMLData->ItemIndex = 0;

	// ===========================================================================

	LayoutItems[0]  = lSI1;   LayoutItems[1]  = lSI2;
	LayoutItems[2]  = lSI3;   LayoutItems[3]  = lSI4;
	LayoutItems[4]  = lSI5;   LayoutItems[5]  = lSI6;
	LayoutItems[6]  = lSI7;   LayoutItems[7]  = lSI8;
	LayoutItems[8]  = lSI9;   LayoutItems[9] = lSI10;
	LayoutItems[10] = lSI11;  LayoutItems[11] = lSI12;
	LayoutItems[12] = lSI13;  LayoutItems[13] = lSI14;
	LayoutItems[14] = lSI15;  LayoutItems[15] = lSI16;
	LayoutItems[16] = lSI17;

	for (int t = 0; t < __XMLItemsCount; t++)
	{
		LayoutItems[t]->Caption = GLanguageHandler->GenericReportItems[t].c_str();
	}
}


void __fastcall TFormEditXmlReport::lbSummaryLayoutClick(TObject *Sender)
{
	bool status = true;

	if (lbSummaryLayout->ItemIndex == -1)
	{
		status = false;
	}

	sbUp->Enabled     = status;
	sbDown->Enabled   = status;
	sbRemove->Enabled = status;
}


void __fastcall TFormEditXmlReport::sbPreviewClick(TObject *Sender)
{
	std::wstring TempCaption = Caption.c_str();

	Caption += (L" " + GLanguageHandler->Text[kPleaseWait] + L"...").c_str();

	// ===========================================================================

	std::vector<std::wstring> Output;

	BuildReport(InternalReport);

	if (InternalReport.Data == kDataSummary)
	{
//		GReportXML.GenerateXMLOutput(FSource, FTempReport, lReportOutput)
	}
	else
	{
//		GReportXML.GenerateXMLOutputFileList("",  lReportOutput, FSource, LayoutUnknown);
	}

	Memo1->Clear();

	for (std::wstring line : Output)
	{
		Memo1->Lines->Add(line.c_str());
	}

	// ===========================================================================

	Caption = TempCaption.c_str();
}


void __fastcall TFormEditXmlReport::sbEditXMLLayoutClick(TObject *Sender)
{
	InternalReport = GSettingsHandler->Reports.XML[cbXMLLayouts->ItemIndex];

	if (InternalReport.Layout != L"")
	{
		UpdateDisplay();

		sbPreviewClick(NULL);
	}
}


void __fastcall TFormEditXmlReport::SpeedButton1Click(TObject *Sender)
{
	//THelp.OpenHelpPage("report_xml.htm");
}


void __fastcall TFormEditXmlReport::sbUpClick(TObject *Sender)
{
	if (lbSummaryLayout->ItemIndex > 0)
	{
		int a = lbSummaryLayout->ItemIndex - 1;

		lbSummaryLayout->Items->Move(lbSummaryLayout->ItemIndex, lbSummaryLayout->ItemIndex - 1);

		lbSummaryLayout->ItemIndex = a;

		AutoRefresh();
	}
}


void __fastcall TFormEditXmlReport::sbDownClick(TObject *Sender)
{
	if (lbSummaryLayout->ItemIndex != -1)
	{
		if (lbSummaryLayout->ItemIndex < lbSummaryLayout->Count - 1)
		{
			int a = lbSummaryLayout->ItemIndex + 1;

			lbSummaryLayout->Items->Move(lbSummaryLayout->ItemIndex, lbSummaryLayout->ItemIndex + 1);

			lbSummaryLayout->ItemIndex = a;

			AutoRefresh();
		}
	}
}


void __fastcall TFormEditXmlReport::sbRemoveClick(TObject *Sender)
{
	lbSummaryLayout->DeleteSelected();

	AutoRefresh();
}


void __fastcall TFormEditXmlReport::sbSaveClick(TObject *Sender)
{
	BuildReport(InternalReport);

	GSettingsHandler->Reports.XML[cbXMLLayouts->ItemIndex] = InternalReport;

	ModalResult = mrOk;
}


void TFormEditXmlReport::AutoRefresh()
{
	if (cbAutoRefresh->Checked)
	{
		sbPreviewClick(NULL);
	}
}


void TFormEditXmlReport::UpdateDisplay()
{
	std::wstring s = L"";

	lbSummaryLayout->Clear();

	for (int t = 0; t < InternalReport.Layout.size(); t++)
	{
		if (InternalReport.Layout[t] == L':')
		{
			int LayoutId = StrToIntDef(s.c_str(), 99);

			if (LayoutId <= __XMLItemsCount)
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

	cbXMLData->ItemIndex = InternalReport.Data;

	if (GSettingsHandler->Reports.XML[cbXMLLayouts->ItemIndex].AutoOpen)
	{
		tsAutoOpen->State = tssOn;
	}
	else
	{
		tsAutoOpen->State = tssOff;
	}
}


void TFormEditXmlReport::BuildReport(XMLReportOptions xmlro)
{
	std::wstring s = L"";

	for (int t = 0; t < lbSummaryLayout->Count; t++)
	{
		int idx = 0;

		for (int z = 0; z < __XMLItemsCount; z++)
		{
			if (LayoutItems[z]->Caption == lbSummaryLayout->Items->Strings[t])
			{
				idx = z;
			}
		}

		s += std::to_wstring(idx) + L":";
	}

	xmlro.Layout = s;

	xmlro.Data = cbXMLData->ItemIndex;

	if (tsAutoOpen->State == tssOn)
	{
		xmlro.AutoOpen = true;
	}
	else
	{
		xmlro.AutoOpen = false;
	}
}
