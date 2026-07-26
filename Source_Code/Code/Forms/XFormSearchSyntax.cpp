//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormSearchSyntax.h"

#include "ConstantsGui.h"
#include "FormDetails.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSearchSyntax *FormSearchSyntax;
//---------------------------------------------------------------------------
__fastcall TFormSearchSyntax::TFormSearchSyntax(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void OpenSearchSyntax()
{
	TFormSearchSyntax *FormSearchSyntax = new TFormSearchSyntax(Application);

	FormSearchSyntax->Show();
}


void __fastcall TFormSearchSyntax::FormCreate(TObject *Sender)
{
	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormSearchSyntax);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}
}


void __fastcall TFormSearchSyntax::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormSearchSyntax, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


void __fastcall TFormSearchSyntax::FormShow(TObject *Sender)
{
	LanguageSymbol = GLanguageHandler->GetLanguageSymbol();

	bClose->Caption = GLanguageHandler->Text[kClose].c_str();

	std::wstring index = GSystemGlobal->ExePath + L"data\\languages\\" + LanguageSymbol + L"\\search\\sindex.htm";
	std::wstring search = GSystemGlobal->ExePath + L"data\\languages\\" + LanguageSymbol + L"\\search\\index.htm";

	wbIndex->Navigate(index.c_str());
	wbSearch->Navigate(search.c_str());
}


void __fastcall TFormSearchSyntax::cbStayOnTopClick(TObject *Sender)
{
	if (cbStayOnTop->Checked)
	{
		FormStyle = fsStayOnTop;
	}
	else
	{
		FormStyle = fsNormal;
	}
}


void __fastcall TFormSearchSyntax::wbIndexBeforeNavigate2(TObject *ASender, IDispatch * const pDisp,
		  const OleVariant &URL, const OleVariant &Flags, const OleVariant &TargetFrameName,
		  const OleVariant &PostData, const OleVariant &Headers,
		  WordBool &Cancel)
{
	std::wstring url = (std::wstring)URL;

	if (url.find(L"sx:") != std::wstring::npos)
	{
		std::wstring search = GSystemGlobal->ExePath + L"data\\languages\\" + LanguageSymbol + L"\\search\\" + url.substr(3) + L".htm";

		wbSearch->Navigate(search.c_str());

		Cancel = true;
	}
}
