//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormSelectLanguage.h"

#include "ImageHandler.h"

extern ImageHandler* GImageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TForm3::FormCreate(TObject *Sender)
{
	i1->Assign(GImageHandler->Flags[0]);
	i2->Assign(GImageHandler->Flags[1]);
	i3->Assign(GImageHandler->Flags[2]);
	i4->Assign(GImageHandler->Flags[3]);
	i5->Assign(GImageHandler->Flags[4]);
	i6->Assign(GImageHandler->Flags[5]);
	i7->Assign(GImageHandler->Flags[6]);
	i8->Assign(GImageHandler->Flags[7]);
	i9->Assign(GImageHandler->Flags[8]);
	i10->Assign(GImageHandler->Flags[9]);
	i11->Assign(GImageHandler->Flags[10]);
}


void __fastcall TForm3::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (SelectedLanguage != LanguageType::kUndefined)
	{
		CanClose = true;
	}
	else
	{
		CanClose = false;
	}
}


void __fastcall TForm3::i11Click(TObject *Sender)
{
	SelectedLanguage = LanguageType::kUndefined;

	TImage* image = (TImage*)Sender;

	switch (image->Tag)
	{
	case 1:
		SelectedLanguage = LanguageType::kUK;
		break;
	case 2:
		SelectedLanguage = LanguageType::kFR;
		break;
	case 3:
		SelectedLanguage = LanguageType::kDE;
		break;
	case 4:
		SelectedLanguage = LanguageType::kES;
		break;
	case 5:
		SelectedLanguage = LanguageType::kIT;
		break;
	case 6:
		SelectedLanguage = LanguageType::kNL;
		break;
	case 7:
		SelectedLanguage = LanguageType::kHU;
		break;
	case 8:
		SelectedLanguage = LanguageType::kUS;
		break;
	case 9:
		SelectedLanguage = LanguageType::kCAT;
		break;
	case 10:
		SelectedLanguage = LanguageType::kRU;
		break;
	case 11:
		SelectedLanguage = LanguageType::kCZ;
		break;
	}

	if (SelectedLanguage != LanguageType::kUndefined)
	{
		ModalResult = mrOk;
	}
}
