//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormGetCopyMove.h"

#include "LanguageHandler.h"
#include "WindowsUtility.h"

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

    FormGetCopyMove->Init(title);

	std::wstring selection = L"";

	if (FormGetCopyMove->ShowModal() == mrOk)
	{
		selection = FormGetCopyMove->eFolder->Text.c_str();
	}

	delete FormGetCopyMove;

	return selection;
}


void TFormGetCopyMove::Init(const std::wstring title)
{
	Caption = title.c_str();

	bCancel->Caption = GLanguageHandler->Text[kCancel].c_str();
	lTitle->Caption = title.c_str();
}


void __fastcall TFormGetCopyMove::SpeedButton1Click(TObject *Sender)
{
	std::vector<std::wstring> paths;

	if (WindowsUtility::BrowseForFolder(paths, true, false))
	{
		std::wstring folder = paths[0];

		eFolder->Text = folder.c_str();
	}
}
