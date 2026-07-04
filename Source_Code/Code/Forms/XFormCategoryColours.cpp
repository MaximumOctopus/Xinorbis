//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormCategoryColours.h"

#include "ConstantsReports.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"

extern LanguageHandler* GLanguageHandler;
extern SettingsHandler* GSettingsHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormCreate(TObject *Sender)
{
	ChartColours[0]  = sCat1;  ChartColours[1]  = sCat2;  ChartColours[2]  = sCat3;
	ChartColours[3]  = sCat4;  ChartColours[4]  = sCat5;  ChartColours[5]  = sCat6;
	ChartColours[6]  = sCat7;  ChartColours[7]  = sCat8;  ChartColours[8]  = sCat9;
	ChartColours[9]  = sCat10; ChartColours[10] = sCat11; ChartColours[11] = sCat12;
	ChartColours[12] = sCat13; ChartColours[13] = sCat14; ChartColours[14] = sCat15;
	ChartColours[15] = sCat16; ChartColours[16] = sCat17; ChartColours[17] = sCat18;
	ChartColours[18] = sCat19;

	for (int t = 0; t < __FileCategoriesCount; t++)
	{
		ChartColours[t]->Brush->Color = TColor(GSettingsHandler->FileCategoryColors[t]);
	}

	sbFC1->Caption  = GLanguageHandler->TypeDescriptions[0].c_str();
	sbFC2->Caption  = GLanguageHandler->TypeDescriptions[1].c_str();
	sbFC3->Caption  = GLanguageHandler->TypeDescriptions[2].c_str();
	sbFC4->Caption  = GLanguageHandler->TypeDescriptions[3].c_str();
	sbFC5->Caption  = GLanguageHandler->TypeDescriptions[4].c_str();
	sbFC6->Caption  = GLanguageHandler->TypeDescriptions[5].c_str();
	sbFC7->Caption  = GLanguageHandler->TypeDescriptions[6].c_str();
	sbFC8->Caption  = GLanguageHandler->TypeDescriptions[7].c_str();
	sbFC9->Caption  = GLanguageHandler->TypeDescriptions[8].c_str();
	sbFC10->Caption = GLanguageHandler->TypeDescriptions[9].c_str();
	sbFC11->Caption = GLanguageHandler->TypeDescriptions[10].c_str();
	sbFC12->Caption = GLanguageHandler->TypeDescriptions[11].c_str();
	sbFC13->Caption = GLanguageHandler->TypeDescriptions[12].c_str();
	sbFC14->Caption = GLanguageHandler->TypeDescriptions[13].c_str();
	sbFC15->Caption = GLanguageHandler->TypeDescriptions[14].c_str();
	sbFC16->Caption = GLanguageHandler->TypeDescriptions[15].c_str();
	sbFC17->Caption = GLanguageHandler->TypeDescriptions[16].c_str();
	sbFC18->Caption = GLanguageHandler->TypeDescriptions[17].c_str();
	sbFC19->Caption = GLanguageHandler->TypeDescriptions[18].c_str();
}


void __fastcall TForm2::FormShow(TObject *Sender)
{
	Caption = GLanguageHandler->Text[kCategoryColours].c_str();
}


void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{
	//THelp.OpenHelpPage('catcolours.htm');
}
