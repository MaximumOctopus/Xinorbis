//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormProgress.h"

#include "LanguageHandler.h"

extern LanguageHandler *GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm18 *Form18;
//---------------------------------------------------------------------------
__fastcall TForm18::TForm18(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm18::FormCreate(TObject *Sender)
{
	sbStop->Caption = GLanguageHandler->Text[kCancel].c_str();
}


void __fastcall TForm18::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}


void TForm18::SetProcessText(const std::wstring s)
{
	lStatus->Caption = s.c_str();
	lStatus->Refresh();

	lStatus2->Caption = L"";
	lStatus2->Refresh();

	lStatus3->Caption = L"";
	lStatus3->Refresh();
}


void TForm18::SetPercentage(const std::wstring s)
{
	lStatus2->Caption = s.c_str();
	lStatus2->Invalidate();
}


void TForm18::SetStatus3(const std::wstring s)
{
	lStatus3->Caption = s.c_str();
	lStatus3->Invalidate();
}


void TForm18::SetProcessIcon(int i)
{
	TImage *image = nullptr;

	switch (i)
	{
	case 1:
		image = iProgress1;
		break;
	case 2:
		image = iProgress2;
		break;
	case 3:
		image = iProgress3;
		break;
	case 4:
		image = iProgress4;
		break;
	case 5:
		image = iProgress5;
		break;

	default:
		return;
	}

	image->Visible = true;
	image->Invalidate();
}


void TForm18::SetProcessBar(int position)
{
//  pbProcess.Position := newposition;
//  pbProcess.Invalidate;
}


void TForm18::SetAbort()
{
	//lAbortStatus.Visible := True;
	//lAbortStatus.Invalidate;
}


void __fastcall TForm18::sbStopClick(TObject *Sender)
{
// stopscan := True;

//  ffMain.Abort;

//  XSettings.ProgressForm.SetAbort;
}
