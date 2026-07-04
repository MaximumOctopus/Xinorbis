//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameSelect.h"
#include "XFormXinorbisDialog.h"

#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "WindowsUtility.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameSelect *FrameSelect;
//---------------------------------------------------------------------------
__fastcall TFrameSelect::TFrameSelect(TComponent* Owner)
	: TFrame(Owner)
{
	Init();

	eScanPath->Text = dlbSelect->Directory;
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
	if (WindowsUtility::DirectoryExists(eScanPath->Text.c_str()))
	{
		std::wstring file_name = eScanPath->Text.c_str();

		WindowsUtility::ExecuteFile(L"\"" + file_name + L"\"", L"");
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kError],
					GLanguageHandler->Text[kFolderDoesNotExist],
					XDialogTypeWarning);
	}
}


void __fastcall TFrameSelect::bSelectClick(TObject *Sender)
{
	std::wstring folder = L""; //WindowsUtility::BrowseForFolder(Handle);

	if (!folder.empty())
	{
		eScanPath->Text = folder.c_str();

		GScanEngine->ExcludedFolders.clear();
		GScanEngine->ExcludedFiles.clear();

		if (eScanPath->Text[1] == L':')
		{
			dcbSelect->Drive     = folder[1];
			dlbSelect->Directory = folder.c_str();
		}
	}
}


void __fastcall TFrameSelect::bFavouritesClick(TObject *Sender)
{
//
}


void __fastcall TFrameSelect::bExcludeFoldersClick(TObject *Sender)
{
	// to do DoExcludedFolders(GScanEngine->ExcludedFolders, GScanEngine->ExcludeVirtual);

	if (GScanEngine->ExcludedFolders.size() != 0)
	{
		bExcludeFolders->Caption = (GLanguageHandler->Text[kExclude] + L" (" + std::to_wstring(GScanEngine->ExcludedFolders.size()) + L")").c_str();
	}
	else
	{
		bExcludeFolders->Caption = GLanguageHandler->Text[kExclude].c_str();
	}
}


void __fastcall TFrameSelect::bExcludeFilesClick(TObject *Sender)
{
	// to do 	DoExcludedFiles(GSystemGlobal.ExcludedFiles);

	if (GScanEngine->ExcludedFiles.size() != 0)
	{
		bExcludeFiles->Caption = (GLanguageHandler->Text[kExclude] + L" (" + std::to_wstring(GScanEngine->ExcludedFiles.size()) + L")").c_str();
	}
	else
	{
		bExcludeFiles->Caption = GLanguageHandler->Text[kExclude].c_str();
	}
}


void __fastcall TFrameSelect::bCombineClick(TObject *Sender)
{
	if (OnScanWithMultiple)
	{
		OnScanWithMultiple(1);
	}
}


void __fastcall TFrameSelect::dlbSelectChange(TObject *Sender)
{
	eScanPath->Text = dlbSelect->Directory;
}


void __fastcall TFrameSelect::puScanHistoryPopup(TObject *Sender)
{
	// to do miQFAdd->Enabled = !(Utility::QuickFolderExists(eScanPath->Text));
}
