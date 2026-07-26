//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormGetCopyMove.h"

#include "LanguageHandler.h"

extern LanguageHandler *GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGetCopyMove *FormGetCopyMove;
//---------------------------------------------------------------------------
__fastcall TFormGetCopyMove::TFormGetCopyMove(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


std::wstring GetCopyMoveFolder(const std::wstring title)
{
	TFormGetCopyMove *FormGetCopyMove = new TFormGetCopyMove(Application);

	FormGetCopyMove->Caption = title.c_str();
	FormGetCopyMove->bCancel->Caption = GLanguageHandler->Text[kCancel].c_str();
	FormGetCopyMove->lTitle->Caption = title.c_str();


	std::wstring selection = L"";

	if (FormGetCopyMove->ShowModal() == mrOk)
	{
		selection = FormGetCopyMove->eFolder->Text.c_str();
	}

	delete FormGetCopyMove;

	return selection;
}


void __fastcall TFormGetCopyMove::SpeedButton1Click(TObject *Sender)
{
	std::wstring folder = L"";// WindowsUtility::BrowseForFolder(Handle); TO DO

	if (!folder.empty())
	{
		eFolder->Text = folder.c_str();
    }
}
