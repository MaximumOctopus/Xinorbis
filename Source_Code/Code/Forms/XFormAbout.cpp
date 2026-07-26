//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormAbout.h"

#include "ConstantsSystem.h"
#include "DateUtility.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

extern LanguageHandler* GLanguageHandler;
extern SettingsHandler* GSettingsHandler;
extern SystemGlobal* GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAbout *FormAbout;
//---------------------------------------------------------------------------
__fastcall TFormAbout::TFormAbout(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TFormAbout::FormCreate(TObject *Sender)
{
	lDate->Caption    = __XDate.c_str();
	lVersion->Caption = (L"xinorbis " + __XVersion).c_str();
	lAuthor->Caption  = (L"(c) Paul Alan Freshney 2002-" + DateUtility::CurrentYear()).c_str();

	gbSocialMedia->Caption = (L" " + GLanguageHandler->Text[kSocialMedia] + L" ").c_str();
	gbThanks->Caption      = (L" " + GLanguageHandler->Text[kThanks] + L" ").c_str();

  // ===========================================================================

	if (GSettingsHandler->Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
	{
		lMode->Caption = GLanguageHandler->Text[kPortable].c_str();
	}
	else
	{
		lMode->Caption = GLanguageHandler->Text[kStandard].c_str();
	}

	if (GSettingsHandler->Database.Enabled)
	{
		if (GSettingsHandler->Database.UseODBC)
		{
			lMode->Caption = lMode->Caption + L" (ODBC)";
		}
		else
		{
			lMode->Caption = lMode->Caption + L" (SQlite)";
		}
	}
	else
	{
		lMode->Caption = lMode->Caption + L" (No DB)";
	}

	lDataPath->Caption   = GSystemGlobal->AppDataPath.c_str();
	lSystemPath->Caption = GSystemGlobal->ExePath.c_str();
}


void __fastcall TFormAbout::Label12Click(TObject *Sender)
{
	WindowsUtility::ExecuteFile(L"mailto:paul@freshney.org", L"");
}


void __fastcall TFormAbout::Label13Click(TObject *Sender)
{
	TLabel* label = (TLabel*)Sender;

	WindowsUtility::ExecuteFile(label->Caption.c_str(), L"");
}


void __fastcall TFormAbout::Label16Click(TObject *Sender)
{
	WindowsUtility::ExecuteFile(L"http://xinorbis.com/developmentcats.htm", L"");
}


void __fastcall TFormAbout::lDevCatsClick(TObject *Sender)
{
	WindowsUtility::ExecuteFile(L"http://xinorbis.com/developmentcats.htm", L"");
}
