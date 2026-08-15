//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormGetDate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}


TDateTime GetDate()
{
	Form7 = new TForm7(Application);

	if (Form7->ShowModal() == mrOk)
	{

	}

	delete Form7;

	return Now();
}


void __fastcall TForm7::FormCreate(TObject *Sender)
{
	cMain->Date = Now();
}
