//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormEditHTMLReport.h"

#include "ConstantsGui.h"
#include "Convert.h"
#include "FormDetails.h"
#include "HelpHandler.h"
#include "HTMLPreview.h"
#include "Log.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "SaveDialogs.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"

extern LanguageHandler *GLanguageHandler;
extern Log *GLog;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEditHTMLReport *FormEditHTMLReport;
//---------------------------------------------------------------------------
__fastcall TFormEditHTMLReport::TFormEditHTMLReport(TComponent* Owner)
	: TForm(Owner)
{
}


HTMLReportOptions OpenHTMLReportOptions(int report_id, bool one_off_custom)
{
	TFormEditHTMLReport* FormEditHTMLReport = new TFormEditHTMLReport(Application);

	FormEditHTMLReport->OneOffCustom = one_off_custom;

//	  cbHTMLLayouts.ItemIndex = aReportID;

//	  sbEditHTMLLayoutClick(Nil);

	if (one_off_custom)
	{
//		sbEditHTMLLayout->Visible = False;
//		cbHTMLLayouts->Visible    = False;
	}

	FormEditHTMLReport->ShowModal();

	HTMLReportOptions htmlro = FormEditHTMLReport->InternalReport;

	delete FormEditHTMLReport;

	return htmlro;
}


void __fastcall TFormEditHTMLReport::FormCreate(TObject *Sender)
{
	Init();
}


void __fastcall TFormEditHTMLReport::FormCanResize(TObject *Sender, int &NewWidth,
		  int &NewHeight, bool &Resize)
{
	if (NewWidth > 800 && NewHeight > 610)
	{
		Resize = true;
	}
	else
	{
		Resize = false;
	}
}


void __fastcall TFormEditHTMLReport::FormClose(TObject *Sender, TCloseAction &Action)

{
	FormDetails fd(kFormEditHTMLReport, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


void TFormEditHTMLReport::Init()
{
	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormEditHTMLReport);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}

	// ===========================================================================

	Caption = (GLanguageHandler->Text[kCustomise] + L" HTML " + GLanguageHandler->Text[kReport]).c_str();

	sbSave->Caption           = GLanguageHandler->Text[kSave].c_str();
	sbCancel->Caption         = GLanguageHandler->Text[kCancel].c_str();
	sbEditHTMLLayout->Caption = GLanguageHandler->Text[kEdit].c_str();

	// ===========================================================================

	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbHTMLLayouts->ItemIndex = 0;

	LayoutItems[0]  = lSI1;   LayoutItems[1]  = lSI2;
	LayoutItems[2]  = lSI3;   LayoutItems[3]  = lSI4;
	LayoutItems[4]  = lSI5;   LayoutItems[5]  = lSI6;
	LayoutItems[6]  = lSI7;   LayoutItems[7]  = lSI8;
	LayoutItems[8]  = lSI9;   LayoutItems[9] = lSI10;
	LayoutItems[10] = lSI11;  LayoutItems[11] = lSI12;
	LayoutItems[12] = lSI13;  LayoutItems[13] = lSI14;
	LayoutItems[14] = lSI15;  LayoutItems[15] = lSI16;
	LayoutItems[16] = lSI17;

	for (int t = 0; t < kHTMLItemsCount; t++)
	{
		LayoutItems[t]->Caption = GLanguageHandler->GenericReportItems[t].c_str();
	}

	cbLayoutSize->Items->Add(L"800 x 600");
	cbLayoutSize->Items->Add(L"1024 x 768");
	cbLayoutSize->Items->Add(L"1280 x 1024");

	// ===========================================================================

	Label1->Caption           = (GLanguageHandler->Text[kAvailable] + L" HTML " + GLanguageHandler->Text[kReportItems]).c_str();
	Label2->Caption           = (L"HTML " + GLanguageHandler->Text[kReportLayout]).c_str();
	cbIncludeImages->Caption  = GLanguageHandler->Text[kIncludeImages].c_str();
	GroupBox1->Caption        = GLanguageHandler->Text[kClickToAdd].c_str();
	lImportant->Caption       = GLanguageHandler->Text[kMaySlowDownReport].c_str();
	bCloseAC->Caption         = GLanguageHandler->Text[kHide].c_str();
	lAC->Caption              = GLanguageHandler->Text[kSelectCategories].c_str();
	bAdvanced->Caption        = GLanguageHandler->Text[kCategories].c_str();

	for (int t = 0; t < 20; t++)
	{
		clbCategoryOptions->Items->Add(GLanguageHandler->TypeDescriptions[t].c_str());
	}

	//

	sbLoadHTMLColours->Caption = GLanguageHandler->Text[kLoad].c_str();
	sbSaveHTMLColours->Caption = GLanguageHandler->Text[kSaveAs].c_str();
	sbPreview->Caption         = GLanguageHandler->Text[kPreview].c_str();
	cbAutoRefresh->Caption     = GLanguageHandler->Text[kAutoRefresh].c_str();

	lReportsHTMLCustom->Caption = GLanguageHandler->Text[kHTMLReportOptions].c_str();
	Label16->Caption            = GLanguageHandler->Text[kLinkNormal].c_str();
	Label17->Caption            = GLanguageHandler->Text[kLinkHover].c_str();
	Label18->Caption            = GLanguageHandler->Text[kPageBackground].c_str();
	Label3->Caption             = GLanguageHandler->Text[kGraphBackground].c_str();
	Label19->Caption            = GLanguageHandler->Text[kTextColour].c_str();
	Label20->Caption            = GLanguageHandler->Text[kTableHeader].c_str();
	Label4->Caption             = (GLanguageHandler->Text[kTableBackground] + L" I").c_str();
	Label7->Caption             = (GLanguageHandler->Text[kTableBackground] + L" II").c_str();
	Label22->Caption            = GLanguageHandler->Text[kTableTextColour].c_str();
	Label23->Caption            = GLanguageHandler->Text[kTableTextColour2].c_str();
	lOOSingleColour->Caption    = GLanguageHandler->Text[kSetBargraphToASingleColour].c_str();
	Label21->Caption            = GLanguageHandler->Text[kBarGraphColour].c_str();
	Label1->Caption             = GLanguageHandler->Text[kShowFileSizesAs].c_str();

	HTMLColoursArray[0]  = sHTMLColour1;
	HTMLColoursArray[1]  = sHTMLColour2;
	HTMLColoursArray[2]  = sHTMLColour3;
	HTMLColoursArray[3]  = sHTMLColour4;
	HTMLColoursArray[4]  = sHTMLColour5;
	HTMLColoursArray[5]  = sHTMLColour6;
	HTMLColoursArray[6]  = sHTMLColour7;
	HTMLColoursArray[7]  = sHTMLColour8;
	HTMLColoursArray[8]  = sHTMLColour9;
	HTMLColoursArray[9]  = sHTMLColour10;
	HTMLColoursArray[10] = sHTMLColour11;

	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kMostConvenient].c_str());
	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());
	cbHTMLUnits->ItemIndex = 0;
}


void __fastcall TFormEditHTMLReport::lbSummaryLayoutClick(TObject *Sender)
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


void __fastcall TFormEditHTMLReport::lSI1Click(TObject *Sender)
{
	TLabel *label = (TLabel*)Sender;

	if (lbSummaryLayout->Items->IndexOf(label->Caption) == -1)
	{
		lbSummaryLayout->Items->Add(label->Caption);
	}
}


void __fastcall TFormEditHTMLReport::SpeedButton1Click(TObject *Sender)
{
	for (int t = 0; t < clbCategoryOptions->Count; t++)
	{
		clbCategoryOptions->Checked[t] = true;
	}
}


void __fastcall TFormEditHTMLReport::SpeedButton2Click(TObject *Sender)
{
	for (int t = 0; t <clbCategoryOptions->Count; t++)
	{
		clbCategoryOptions->Checked[t] = false;
	}
}


void __fastcall TFormEditHTMLReport::SpeedButton3Click(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"report_html.htm");
}


void __fastcall TFormEditHTMLReport::sHTMLColour1MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (Shift.Contains(ssLeft))
	{
		//Assert(TShape(sender).tag <= HTMLColoursCount, "sHTMLColourMouseDown :: Object tag incorrect.");

		TShape *shape = (TShape*)Sender;

		cdHTML->Color = shape->Brush->Color;

		if (cdHTML->Execute())
		{
			shape->Brush->Color = cdHTML->Color;

			AutoRefresh();
		}
	}
}


void __fastcall TFormEditHTMLReport::sbUpClick(TObject *Sender)
{
	if (lbSummaryLayout->ItemIndex > 0)
	{
		int a = lbSummaryLayout->ItemIndex - 1;

		lbSummaryLayout->Items->Move(lbSummaryLayout->ItemIndex, lbSummaryLayout->ItemIndex - 1);

		lbSummaryLayout->ItemIndex = a;

		AutoRefresh();
	}
}


void __fastcall TFormEditHTMLReport::sbSaveClick(TObject *Sender)
{
	BuildReport(InternalReport);

  // save colours ==============================================================

	for (int t = 0; t < kHTMLColoursCount; t++)
	{
		InternalReport.Colours.Colour[t] = HTMLColoursArray[t]->Brush->Color;

		if (OneOffCustom)
		{
			GSettingsHandler->Reports.HTML[cbHTMLLayouts->ItemIndex] = InternalReport;
		}

		ModalResult = mrOk;
	}
}


void __fastcall TFormEditHTMLReport::sbRemoveClick(TObject *Sender)
{
	lbSummaryLayout->DeleteSelected();

	sbRemove->Enabled = false;
	sbUp->Enabled     = false;
	sbDown->Enabled   = false;

	AutoRefresh();

}


void __fastcall TFormEditHTMLReport::sbPreviewClick(TObject *Sender)
{
	for (int t = 0; t < kHTMLColoursCount; t++)
	{
		InternalReport.Colours.Colour[t] = HTMLColoursArray[t]->Brush->Color;
	}

	if (tsSingleColour->State == tssOn)
	{
		InternalReport.Colours.MonoBargraph = true;
	}
	else
	{
		InternalReport.Colours.MonoBargraph = false;
	}

	BuildReport(InternalReport);

	try
	{
		wbHTML->NavigateToString(HTMLPreview::Get(InternalReport, InternalReport.Colours).c_str());
	}
	catch(...)
	{
		GLog->AddError(L"Error writing out preview HTML file.");
	}
}


void __fastcall TFormEditHTMLReport::sbSaveHTMLColoursClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kLayoutFiles] + L" (*.data)|*.data",
												  L".data",
												  L"",
												  GSystemGlobal->ExePath + L"data\\layouts");
	if (!file_name.empty())
	{
		SaveHTMLColours(file_name);
	}
}


void __fastcall TFormEditHTMLReport::sbLoadHTMLColoursClick(TObject *Sender)
{
	std::wstring file_name = LoadDialogs::Execute(GLanguageHandler->Text[kLayoutFiles] + L" (*.data)|*.data",
												  L".data",
												  GSystemGlobal->ExePath + L"data\\layouts",
												  L"");

	if (!file_name.empty())
	{
		LoadHTMLColours(file_name);
	}
}


void __fastcall TFormEditHTMLReport::sbEditHTMLLayoutClick(TObject *Sender)
{
	InternalReport = GSettingsHandler->Reports.HTML[cbHTMLLayouts->ItemIndex];

	if (InternalReport.Layout != L"")
	{
		BuildTopHalf();
		BuildBottomHalf();

		sbPreviewClick(NULL);
	}
}


void __fastcall TFormEditHTMLReport::sbDownClick(TObject *Sender)
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


void __fastcall TFormEditHTMLReport::sbCancelClick(TObject *Sender)
{
	InternalReport.Layout = L"$";

	ModalResult = mrCancel;
}


void __fastcall TFormEditHTMLReport::bCloseACClick(TObject *Sender)
{
	pCategoryOptions->SendToBack();

	pCategoryOptions->Visible = false;
}


void __fastcall TFormEditHTMLReport::bAdvancedClick(TObject *Sender)
{
	pCategoryOptions->BringToFront();

	pCategoryOptions->Visible = true;
}


void __fastcall TFormEditHTMLReport::cbIncludeImagesClick(TObject *Sender)
{
	AutoRefresh();
}


void TFormEditHTMLReport::BuildTopHalf()
{
	std::wstring s = L"";

	lbSummaryLayout->Clear();

	for (int t = 0; t < InternalReport.Layout.size(); t++)
	{
		if (InternalReport.Layout[t] == L':')
		{
			int LayoutId = StrToIntDef(s.c_str(), 99);

			if (LayoutId <= kHTMLItemsCount)
			{
				if (LayoutId == 0)
				{
					cbIncludeImages->Checked = true;
				}
			}
			else
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

	cbLayoutSize->ItemIndex = InternalReport.LayoutSize;

	for (int t = 0; t < 20; t++)
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
}


void TFormEditHTMLReport::BuildBottomHalf()
{
	cbHTMLUnits->ItemIndex = InternalReport.Units;

	for (int t = 0; t < kHTMLItemsCount; t++)
	{
		HTMLColoursArray[t]->Brush->Color = TColor(GSettingsHandler->Reports.HTML[cbHTMLLayouts->ItemIndex].Colours.Colour[t]);
	}
}


void TFormEditHTMLReport::AutoRefresh()
{
	if (cbAutoRefresh->Checked)
	{
		sbPreviewClick(NULL);
	}
}



void TFormEditHTMLReport::BuildReport(HTMLReportOptions htmlro)
{
	std::wstring s = L"";

	if (cbIncludeImages->Checked)       // where"s value for not included?!?!
	{
		s += L"0:";
	}

	for (int t = 0; t < lbSummaryLayout->Count; t++)
	{
		int idx = 0;

		for (int z = 0; z < kHTMLItemsCount; z++)
		{
			if (LayoutItems[z]->Caption == lbSummaryLayout->Items->Strings[t])
			{
				idx = z;
			}
		}

		s += std::to_wstring(idx) + L":";
	}

	htmlro.Units = cbHTMLUnits->ItemIndex;
	htmlro.Layout = s;
	htmlro.LayoutSize = cbLayoutSize->ItemIndex;

	s = L"";

	for (int t = 0; t < 20; t++)
	{
		s += std::to_wstring(Convert::BoolToInteger(clbCategoryOptions->Checked[t]));
	}

	htmlro.LoadCategoryList(s);
}


void TFormEditHTMLReport::LoadHTMLColours(const std::wstring file_name)
{
	if (GSettingsHandler->OpenSettings(true))
	{
		sHTMLColour1->Brush->Color  = TColor(GSettingsHandler->ReadInteger(L"Main", L"LinkNormal",       0x00FFFFFF, 0x00FFFFFF));
		sHTMLColour2->Brush->Color  = TColor(GSettingsHandler->ReadInteger(L"Main", L"LinkHover",        0x00FFFFFF, 0x00FFFFFF));

		sHTMLColour3->Brush->Color  = TColor(GSettingsHandler->ReadInteger(L"Main", L"PageBackground",   0x00FFFFFF, 0x00FFFFFF));
		sHTMLColour9->Brush->Color  = TColor(GSettingsHandler->ReadInteger(L"Main", L"GraphBackground",  0x00FFFFFF, 0x00FFFFFF));
		sHTMLColour4->Brush->Color  = TColor(GSettingsHandler->ReadInteger(L"Main", L"TextColour",       0x00FFFFFF, 0x00FFFFFF));

		sHTMLColour6->Brush->Color  = TColor(GSettingsHandler->ReadInteger(L"Main", L"TableHeader",      0x00FFFFFF, 0x00FFFFFF));
		sHTMLColour10->Brush->Color = TColor(GSettingsHandler->ReadInteger(L"Main", L"TableBackground",  0x00FFFFFF, 0x00FFFFFF));
		sHTMLColour11->Brush->Color = TColor(GSettingsHandler->ReadInteger(L"Main", L"TableBackground2", 0x00CCCCCC, 0x00FFFFFF));
		sHTMLColour7->Brush->Color  = TColor(GSettingsHandler->ReadInteger(L"Main", L"TableTextColour",  0x00FFFFFF, 0x00FFFFFF));
		sHTMLColour8->Brush->Color  = TColor(GSettingsHandler->ReadInteger(L"Main", L"TableTextColour2", 0x00FFFFFF, 0x00FFFFFF));

		GSettingsHandler->CloseSettings();
	}
}


void TFormEditHTMLReport::SaveHTMLColours(const std::wstring file_name)
{
	if (GSettingsHandler->OpenSettings(false))
	{
		GSettingsHandler->WriteInteger(L"Main", L"LinkNormal",       sHTMLColour1->Brush->Color);
		GSettingsHandler->WriteInteger(L"Main", L"LinkHover",        sHTMLColour2->Brush->Color);

		GSettingsHandler->WriteInteger(L"Main", L"PageBackground",   sHTMLColour3->Brush->Color);
		GSettingsHandler->WriteInteger(L"Main", L"GraphBackground",  sHTMLColour9->Brush->Color);
		GSettingsHandler->WriteInteger(L"Main", L"TextColour",       sHTMLColour4->Brush->Color);

		GSettingsHandler->WriteInteger(L"Main", L"TableHeader",      sHTMLColour6->Brush->Color);
		GSettingsHandler->WriteInteger(L"Main", L"TableBackground",  sHTMLColour10->Brush->Color);
		GSettingsHandler->WriteInteger(L"Main", L"TableBackground2", sHTMLColour11->Brush->Color);
		GSettingsHandler->WriteInteger(L"Main", L"TableTextColour",  sHTMLColour7->Brush->Color);
		GSettingsHandler->WriteInteger(L"Main", L"TableTextColour2", sHTMLColour8->Brush->Color);

		GSettingsHandler->CloseSettings();
	}
}

