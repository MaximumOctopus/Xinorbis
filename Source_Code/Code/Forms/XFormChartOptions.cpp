//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormChartOptions.h"

#include "ChartUtility.h"
#include "ConstantsReports.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm17 *Form17;
//---------------------------------------------------------------------------
__fastcall TForm17::TForm17(TComponent* Owner)
	: TForm(Owner)
{
}


ChartOptions ShowChartOptions(ChartOptions co)
{
	Form17 = new TForm17(Application);

	Form17->InitOptions(co);

	co.Result = 0;

	if (Form17->ShowModal() == mrOk)
	{
		co = Form17->SetFromGui(co);

		GSettingsHandler->Chart = co;
	}

	delete Form17;

    return co;
}


void __fastcall TForm17::FormCreate(TObject *Sender)
{
	Init();
}


void __fastcall TForm17::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}



void TForm17::Init()
{
	Caption = GLanguageHandler->Text[kChartOptions].c_str();

	bSave->Caption        = GLanguageHandler->Text[kSave].c_str();
	bCancel->Caption      = GLanguageHandler->Text[kCancel].c_str();
	bHelp->Caption        = GLanguageHandler->Text[kHelp].c_str();

	Label1->Caption       = GLanguageHandler->Text[kChartZoomLevel].c_str();
	Label2->Caption       = GLanguageHandler->Text[kExplodeLargestSlice].c_str();
	Label3->Caption       = GLanguageHandler->Text[kLabelColour].c_str();
	cbShowLegend->Caption = GLanguageHandler->Text[kLegend].c_str();
	cbShowLabels->Caption = GLanguageHandler->Text[kShowLabels].c_str();

	cbMarksType->Items->Add(GLanguageHandler->Text[kValue].c_str());
	cbMarksType->Items->Add(GLanguageHandler->Text[kPercent].c_str());
	cbMarksType->Items->Add(GLanguageHandler->Text[kLabel].c_str());
	cbMarksType->Items->Add(GLanguageHandler->Text[kLabelPercent].c_str());
	cbMarksType->Items->Add(GLanguageHandler->Text[kLabelValue].c_str());
	cbMarksType->Items->Add(GLanguageHandler->Text[kLegend].c_str());
	cbMarksType->Items->Add(GLanguageHandler->Text[kPercentTotal].c_str());
	cbMarksType->Items->Add(GLanguageHandler->Text[kLabelPercentTotal].c_str());
	cbMarksType->Items->Add(GLanguageHandler->Text[kXValue].c_str());
	cbMarksType->ItemIndex = 0;

	cbLabelOptions->Items->Add(GLanguageHandler->Text[kDefault].c_str());
	cbLabelOptions->Items->Add(GLanguageHandler->Text[kMostConvenient].c_str());
	cbLabelOptions->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbLabelOptions->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbLabelOptions->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());

	lTitleColour->Caption = GLanguageHandler->Text[kTitleColour].c_str();

	lGradientFrom->Caption  = GLanguageHandler->Text[kGradientFrom].c_str();
	lGradientTo->Caption    = GLanguageHandler->Text[kGradientTo].c_str();
	cbShowGradient->Caption = GLanguageHandler->Text[kToggleGradient].c_str();
}


void TForm17::InitOptions(ChartOptions co)
{
	tbZoom->Position           = co.Zoom;
	tbExplodeBiggest->Position = co.Explode;

	sLabelColour->Brush->Color = TColor(co.MarkColour);
	cbShowLabels->Checked      = co.ShowMarks;
	cbMarksType->ItemIndex     = co.MarksType;
	cbLabelOptions->ItemIndex  = co.LabelOptions;
	cbShowLegend->Checked      = co.ShowLegend;

	if (cbMarksType->ItemIndex == 2)
	{
		cbLabelOptions->Enabled = true;
	}
	else
	{
		cbLabelOptions->Enabled = false;
	}

	vtcOptions->SeriesList->Items[0]->Clear();
	vtcOptions->SeriesList->Items[0]->Add(200, L"", TColor(kSpectrumColours[0]));
	vtcOptions->SeriesList->Items[0]->Add(100, L"", TColor(kSpectrumColours[1]));
	vtcOptions->SeriesList->Items[0]->Add( 50, L"", TColor(kSpectrumColours[2]));
	vtcOptions->SeriesList->Items[0]->Add( 20, L"", TColor(kSpectrumColours[3]));
	vtcOptions->SeriesList->Items[0]->Add( 10, L"", TColor(kSpectrumColours[4]));

	vtcOptions->View3DOptions->Zoom = co.Zoom;

	vtcOptions->SeriesList->Items[0]->Marks->Style = ChartUtility::IntegerToSeriesMarksStyle(co.MarksType);

	vtcOptions->Title->Font->Color   = TColor(co.TitleColour);
	sTitleColour->Brush->Color       = TColor(co.TitleColour);

	vtcOptions->Gradient->StartColor = TColor(co.ChartFrom);
	vtcOptions->Gradient->EndColor   = TColor(co.ChartTo);
	vtcOptions->Color                = TColor(co.ChartFrom);
	vtcOptions->Gradient->Visible    = co.ChartGradient;
	cbShowGradient->Checked          = co.ChartGradient;

	Shape1->Brush->Color = TColor(co.ChartFrom);
	Shape2->Brush->Color = TColor(co.ChartTo);

	switch (co.Type)
	{
	case ChartType::kUnknown:
		break;
	case ChartType::kPie:
		reinterpret_cast<TPieSeries*>(vtcOptions->SeriesList->Items[0])->ExplodeBiggest = tbExplodeBiggest->Position;
		break;
	case ChartType::kBar:
	{
		tbExplodeBiggest->Enabled = false;

		TChartSeries *old = vtcOptions->Series[0];

		ChangeSeriesType(old, __classid(TBarSeries));

		vtcOptions->View3D = false;
		break;
	}
	case ChartType::kHorizontal:
	{
		tbExplodeBiggest->Enabled = false;

		TChartSeries *old = vtcOptions->Series[0];

		ChangeSeriesType(old, __classid(THorizBarSeries));

		vtcOptions->View3D = false;
		break;
	}
	}

	SetChartFurniture(sLabelColour->Brush->Color);

	tbZoomChange(NULL);
	tbExplodeBiggestChange(NULL);
}


ChartOptions TForm17::SetFromGui(ChartOptions co)
{
	co.Result        = 1;

	co.Zoom          = tbZoom->Position;
	co.Explode       = tbExplodeBiggest->Position;
	co.MarkColour    = sLabelColour->Brush->Color;
	co.ShowMarks     = cbShowLabels->Checked;
	co.MarksType     = cbMarksType->ItemIndex;
	co.LabelOptions  = cbLabelOptions->ItemIndex;
	co.ShowLegend    = cbShowLegend->Checked;

	co.TitleColour   = vtcOptions->Title->Font->Color;

	co.ChartFrom     = vtcOptions->Gradient->StartColor;
	co.ChartTo       = vtcOptions->Gradient->EndColor;
	co.ChartGradient = cbShowGradient->Checked;
}


void __fastcall TForm17::Shape1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	TShape *shape = (TShape*)Sender;

	cdMain->Color = shape->Brush->Color;

	if (cdMain->Execute())
	{
		shape->Brush->Color = cdMain->Color;

		vtcOptions->Gradient->StartColor = cdMain->Color;

		vtcOptions->Color = cdMain->Color; // needed if gradient is disabled
	}
}


void __fastcall TForm17::Shape2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	TShape *shape = (TShape*)Sender;

	cdMain->Color = shape->Brush->Color;

	if (cdMain->Execute())
	{
		shape->Brush->Color = cdMain->Color;

		vtcOptions->Gradient->EndColor = cdMain->Color;
	}
}


void __fastcall TForm17::tbZoomChange(TObject *Sender)
{
	vtcOptions->View3DOptions->Zoom = tbZoom->Position;

	lZoom->Caption = (std::to_wstring(tbZoom->Position) + L"%").c_str();
}


void __fastcall TForm17::tbExplodeBiggestChange(TObject *Sender)
{
	if (vtcOptions->Series[0]->ClassNameIs(L"TPieSeries"))
	{
		reinterpret_cast<TPieSeries*>(vtcOptions->Series[0])->ExplodeBiggest = tbExplodeBiggest->Position;

		lExplodeBiggest->Caption = tbExplodeBiggest->Position;
	}
}


void __fastcall TForm17::sLabelColourMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	TShape *shape = (TShape*)Sender;

	cdMain->Color = shape->Brush->Color;

	if (cdMain->Execute())
	{
		shape->Brush->Color = cdMain->Color;

		SetChartFurniture(cdMain->Color);
	}
}


void __fastcall TForm17::sTitleColourMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	TShape *shape = (TShape*)Sender;

	cdMain->Color = shape->Brush->Color;

	if (cdMain->Execute())
	{
		shape->Brush->Color = cdMain->Color;

		vtcOptions->Title->Font->Color = cdMain->Color;
	}
}


void __fastcall TForm17::cbMarksTypeChange(TObject *Sender)
{
	vtcOptions->SeriesList->Items[0]->Marks->Style = ChartUtility::IntegerToSeriesMarksStyle(cbMarksType->ItemIndex);

	if (cbMarksType->ItemIndex == 2)
	{
		cbLabelOptions->Enabled = true;
	}
	else
	{
		cbLabelOptions->Enabled = false;
	}
}


void __fastcall TForm17::bHelpClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"chartoptions.htm");
}


void __fastcall TForm17::cbShowGradientClick(TObject *Sender)
{
	vtcOptions->Gradient->Visible = cbShowGradient->Checked;
}


void __fastcall TForm17::cbShowLabelsClick(TObject *Sender)
{
	vtcOptions->Series[0]->Marks->Visible = cbShowLabels->Checked;
}


void __fastcall TForm17::cbShowLegendClick(TObject *Sender)
{
	vtcOptions->Legend->Visible = cbShowLegend->Checked;
}


void TForm17::SetChartFurniture(int colour)
{
	vtcOptions->Series[0]->Marks->BackColor = TColor(cdMain->Color);

	vtcOptions->AxesList->Bottom->Axis->Color       = TColor(colour);
	vtcOptions->AxesList->Left->Axis->Color         = TColor(colour);
	vtcOptions->AxesList->Right->Axis->Color        = TColor(colour);
	vtcOptions->AxesList->Top->Axis->Color          = TColor(colour);

	vtcOptions->AxesList->Bottom->LabelsFont->Color = TColor(colour);
	vtcOptions->AxesList->Left->LabelsFont->Color   = TColor(colour);
	vtcOptions->AxesList->Right->LabelsFont->Color  = TColor(colour);
	vtcOptions->AxesList->Top->LabelsFont->Color    = TColor(colour);

	vtcOptions->AxesList->Bottom->Title->Font->Color = TColor(colour);
	vtcOptions->AxesList->Left->Title->Font->Color   = TColor(colour);
	vtcOptions->AxesList->Right->Title->Font->Color  = TColor(colour);
	vtcOptions->AxesList->Top->Title->Font->Color    = TColor(colour);
}
