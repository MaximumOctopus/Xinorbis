//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <System.DateUtils.hpp>

#include "XFormUserWizard.h"

#include "Convert.h"
#include "LanguageHandler.h"
#include "SearchUtility.h"

extern LanguageHandler *GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm12 *Form12;
//---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner)
	: TForm(Owner)
{
}


std::wstring OpenUserWizard()
{
	Form12 = new TForm12(Application);

	std::wstring search = L"";

	if (Form12->ShowModal() == mrOk)
	{
		search = Form12->BuildSearchString();
	}

	delete Form12;

	return search;
}


void __fastcall TForm12::FormCreate(TObject *Sender)
{
	pTitle->BringToFront();

	Caption = (GLanguageHandler->Text[kSearch] + L" " + GLanguageHandler->Text[kWizard]).c_str();
}


void __fastcall TForm12::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}


void __fastcall TForm12::rbSelectMultimediaClick(TObject *Sender)
{
	TRadioButton *rb = (TRadioButton*)Sender;

	SelectedCategory = rb->Tag;
}


void __fastcall TForm12::rbSize1Click(TObject *Sender)
{
	TRadioButton *rb = (TRadioButton*)Sender;

	SelectedSizeRange = rb->Tag;
}


void __fastcall TForm12::rbTodayClick(TObject *Sender)
{
	TRadioButton *rb = (TRadioButton*)Sender;

	SelectedDateRange = rb->Tag;
}


void __fastcall TForm12::sbSearchClick(TObject *Sender)
{
   //	GHelp.OpenHelpPage('userwizard.htm');
}


void __fastcall TForm12::sbPreviousClick(TObject *Sender)
{
	TPanel* panel = nullptr;

	switch (SelectedCategory)
	{
	case kTypeMultimedia:
		switch (CurrentPage)
		{
		case 1:
			panel = pTitle;
			break;
		case 2:
			panel = pMultimedia;
			break;
		}
		break;
	case kTypeProductivity:
		switch (CurrentPage)
		{
		case 1:
			panel = pTitle;
			break;
		case 2:
			panel = pProductivity;
			break;
		}
		break;
	case kTypeCompressed:
		switch (CurrentPage)
		{
		case 1:
			panel = pTitle;
			break;
		case 2:
			panel = pCompressed;
			break;
		}
		break;
	case kTypeSystem:
		switch (CurrentPage)
		{
		case 1:
			panel = pTitle;
			break;
		case 2:
			panel = pSystem;
			break;
		}
		break;
	case kTypePopular:
		switch (CurrentPage)
		{
		case 1:
			panel = pTitle;
			break;
		case 2:
			panel = pPopular;
			break;
		}
		break;
	case kTypeSize:
		switch (CurrentPage)
		{
		case 1:
			panel = pTitle;
			break;
		case 2:
			panel = pSize;
			break;
		}
		break;
	}

	if (panel != nullptr)
	{
		panel->BringToFront();

		CurrentPage--;
	}

	if (CurrentPage == 0)
	{
		sbPrevious->Enabled = false;
	}

	sbOK->Enabled = true;
}


void __fastcall TForm12::sbNextClick(TObject *Sender)
{
	TPanel* panel = nullptr;

	switch (SelectedCategory)
	{
	case kTypeMultimedia:
		switch (CurrentPage)
		{
		case kPageMain:
			panel = pMultimedia;
			break;
		case kPageEnd:
			panel = pEnd;
			break;
		}
		break;
	case kTypeProductivity:
		switch (CurrentPage)
		{
		case kPageMain:
			panel = pProductivity;
			break;
		case kPageEnd:
			panel = pEnd;
			break;
		}
		break;
	case kTypeCompressed:
		switch (CurrentPage)
		{
		case kPageMain:
			panel = pCompressed;
			break;
		case kPageEnd:
			panel = pEnd;
			break;
		}
		break;
	case kTypeSystem:
		switch (CurrentPage)
		{
		case kPageMain:
			panel = pSystem;
			break;
		case kPageEnd:
			panel = pEnd;
			break;
		}
		break;
	case kTypePopular:
		switch (CurrentPage)
		{
		case kPageMain:
			panel = pPopular;
			break;
		case kPageEnd:
			panel = pEnd;
			break;
		}
		break;
	case kTypeSize:
		switch (CurrentPage)
		{
		case kPageMain:
			panel = pSize;
			break;
		case kPageEnd:
			panel = pEnd;
			break;
		}
		break;
	}

	if (panel != nullptr)
	{
		panel->BringToFront();

		sbNext->Enabled = false;

		CurrentPage++;

		if (panel == pEnd)
		{
			sbOK->Enabled = true;
		}
	}

	if (CurrentPage != 0)
	{
		sbPrevious->Enabled = true;
	}
}


void __fastcall TForm12::sbOKClick(TObject *Sender)
{
	ModalResult = mrOk;
}


std::wstring TForm12::BuildSearchString()
{
	std::wstring output = L"";

	switch (SelectedCategory)
	{
	case kTypeMultimedia:
		if (cbMultimedia1->Checked) output += L"#GFX ";

		if (cbMultimedia2->Checked) output += L"#MOVIE ";

		if (cbMultimedia3->Checked) output += L"#SOUND ";
		break;
	case kTypeProductivity:
		if (rbOffice->Checked) output += L"#OFF ";

		if (rbProgramming->Checked) output += L"#COD ";

		if (rbCompressed->Checked) output += L"#COM ";
		break;
	case kTypeCompressed:
		output += L"#COM ";
		break;
	case kTypeSystem:
		if (rbPrograms->Checked) output += L"#PROG ";

		if (rbSystem->Checked) output += L"#SYSTEM ";

		if (rbAllSystem->Checked) output += L"#SYSTEM #PROG";
		break;
	case kTypePopular:
	{
		std::wstring date = L"cdate";

		if (rbAccessed->Checked)
		{
			date = L"adate";
		}
		else if (rbModified->Checked)
		{
			date = L"mdate";
		}

		switch (SelectedDateRange)
		{
		case kDateToday:
			output += L"(" + date + L"=" + Convert::DateToYYYYMMDDS(Now()) + L")";
			break;
		case kDateYesterday:
			output += L"(" + date + L"=" + Convert::DateToYYYYMMDDS(IncDay(Now(), -1)) + L")";
			break;
		case kDateLastWeek:
			output += L"(" + date + L">" + Convert::DateToYYYYMMDDS(IncDay(Now(), -7)) + L") (" + date + L"<" + Convert::DateToYYYYMMDDS(Now()) + L")";
			break;
		case kDateLastMonth:
			output += L"(" + date + L">" + Convert::DateToYYYYMMDDS(IncDay(Now(),  -31)) + L") (" + date + L"<" + Convert::DateToYYYYMMDDS(Now()) + L")";
			break;
		}
		break;
    }
	case kTypeSize:
		switch (SelectedSizeRange)
		{
		case kSizeLess1MB:
			output += SearchUtility::GetSearchSize( -1,      -1,   1, kUnitMB);
			break;
		case kSize1To10MB:
			output += SearchUtility::GetSearchSize(  1, kUnitMB,  10, kUnitMB);
			break;
		case kSize10To50MB:
			output += SearchUtility::GetSearchSize( 10, kUnitMB,  50, kUnitMB);
			break;
		case kSize50To100MB:
			output += SearchUtility::GetSearchSize( 50, kUnitMB, 100, kUnitMB);
			break;
		case kSize100MBTo1GB:
			output += SearchUtility::GetSearchSize(100, kUnitMB,   1, kUnitGB);
			break;
		case kSizeGreater1GB:
			output += SearchUtility::GetSearchSize(  1, kUnitGB,  -1,       -1);
			break;
		}
		break;
	}

	return output;
}
