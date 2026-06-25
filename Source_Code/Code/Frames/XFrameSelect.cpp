//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameSelect.h"

#include "LanguageHandler.h"

extern LanguageHandler* GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameSelect *FrameSelect;
//---------------------------------------------------------------------------
__fastcall TFrameSelect::TFrameSelect(TComponent* Owner)
	: TFrame(Owner)
{
	Init();
}


void TFrameSelect::Init()
{
	bScanNow->Caption = GLanguageHandler->Text[kScan].c_str();
	bExplore->Caption = GLanguageHandler->Text[kExplore].c_str();

	bSelect->Caption = GLanguageHandler->Text[kSelect].c_str();
	bFavourites->Caption = GLanguageHandler->Text[kFavourites].c_str();
	bExcludeFolders->Caption = GLanguageHandler->Text[kExclude].c_str();
	bExcludeFiles->Caption = GLanguageHandler->Text[kExclude].c_str();
	bCombine->Caption = GLanguageHandler->Text[kCombine].c_str();

	// popup menus
    miQFTitle->Caption = GLanguageHandler->Text[kFavourites].c_str();
	miQFAdd->Caption = GLanguageHandler->Text[kAddCurrentFolder].c_str();
}


void __fastcall TFrameSelect::bScanNowClick(TObject *Sender)
{
	if (OnNewScan)
	{
		std::wstring path = eScanPath->Text.c_str();

		OnNewScan(path);
	}
}


void __fastcall TFrameSelect::bExploreClick(TObject *Sender)
{
//
}


void __fastcall TFrameSelect::bSelectClick(TObject *Sender)
{
//
}


void __fastcall TFrameSelect::bFavouritesClick(TObject *Sender)
{
//
}


void __fastcall TFrameSelect::bExcludeFoldersClick(TObject *Sender)
{
//
}


void __fastcall TFrameSelect::bExcludeFilesClick(TObject *Sender)
{
//
}


void __fastcall TFrameSelect::bCombineClick(TObject *Sender)
{
//
}


void __fastcall TFrameSelect::dlbSelectChange(TObject *Sender)
{
	eScanPath->Text = dlbSelect->Directory;
}
//---------------------------------------------------------------------------

