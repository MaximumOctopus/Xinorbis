//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <Vcl.Clipbrd.hpp>

#include "XFormXinorbisDialog.h"

#include "LanguageHandler.h"

extern LanguageHandler* GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormXDialog *FormXDialog;
//---------------------------------------------------------------------------
__fastcall TFormXDialog::TFormXDialog(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void ShowXDialog(const std::wstring title, const std::wstring body, int dialog_type)
{
	TFormXDialog *FormXDialog = new TFormXDialog(Application);

	FormXDialog->lTitle->Caption = title.c_str();
	FormXDialog->lBody->Caption = body.c_str();

	FormXDialog->bCopyToClipboard->Caption = GLanguageHandler->Text[kCopyToClipboard].c_str();

	switch (dialog_type)
	{
	case XDialogTypeInformation:
		FormXDialog->iInformation->Visible = true;
		break;
	case XDialogTypeWarning:
		FormXDialog->iWarning->Visible = true;
		break;
	case XDialogTypeXinorbis:
		FormXDialog->iXinorbis->Visible = true;
		break;
	default:
		FormXDialog->iInformation->Visible = true;
		break;
	}

	FormXDialog->ShowModal();

	delete FormXDialog;
}


void __fastcall TFormXDialog::bCopyToClipboardClick(TObject *Sender)
{
	Clipboard()->AsText = lTitle->Caption + L" / " + lBody->Caption;
}
