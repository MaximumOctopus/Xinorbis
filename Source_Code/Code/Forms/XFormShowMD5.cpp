//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <Vcl.Clipbrd.hpp>

#include "XFormShowMD5.h"

#include "LanguageHandler.h"

extern LanguageHandler *GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm22 *Form22;
//---------------------------------------------------------------------------
__fastcall TForm22::TForm22(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void OpenMD5Checksum(const std::wstring file_name, const std::wstring md5)
{
	Form22 = new TForm22(Application);

	Form22->lFileName->Caption = file_name.c_str();
	Form22->lMD5->Caption = md5.c_str();

	Form22->ShowModal();

	delete Form22;
}


void __fastcall TForm22::FormCreate(TObject *Sender)
{
	bCopy->Caption = GLanguageHandler->Text[kCopy].c_str();
	bCancel->Caption = GLanguageHandler->Text[kCancel].c_str();
}


void __fastcall TForm22::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}


void __fastcall TForm22::bCopyClick(TObject *Sender)
{
	Clipboard()->AsText = lMD5->Caption;
}
