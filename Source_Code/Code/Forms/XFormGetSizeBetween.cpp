//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormGetSizeBetween.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}


std::wstring OpenSizeDialog()
{
	Form5 = new TForm5(Application);

	std::wstring selection = L"";

	if (Form5->ShowModal() == mrOk)
	{
		std::wstring from = (Form5->eFrom->Text + Form5->cbFrom->Text).c_str();
		std::wstring to = (Form5->eTo->Text + Form5->cbTo->Text).c_str();

		selection = L"(size>" + from + L") (size<" + to + L")";
	}

	delete Form5;

	return selection;
}
