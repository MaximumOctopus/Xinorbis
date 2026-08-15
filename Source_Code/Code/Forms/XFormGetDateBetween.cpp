//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormGetDateBetween.h"

#include "Convert.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}

// change To and From to include selected dates

std::wstring OpenDateDialog(const std::wstring context)
{
	Form6 = new TForm6(Application);

	std::wstring selection = L"";

	if (Form6->ShowModal() == mrOk)
	{
		selection = L"(" + context + L">" + Convert::DateToYYYYMMDDS(Form6->mcFrom->Date) + L") (" + context + L"<" + Convert::DateToYYYYMMDDS(Form6->mcTo->Date) + L")";
	}

	delete Form6;

	return selection;
}


void __fastcall TForm6::FormCreate(TObject *Sender)
{
	mcFrom->Date = IncMonth(Now(), -1);
	mcTo->Date   = Now();
}
