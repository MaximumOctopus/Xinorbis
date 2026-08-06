//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <Vcl.Dialogs.hpp>

#include "XFormExcludeFolders.h"

#include "LanguageHandler.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm15 *Form15;
//---------------------------------------------------------------------------
__fastcall TForm15::TForm15(TComponent* Owner)
	: TForm(Owner)
{
}


void OpenExcludedFolders(std::vector<std::wstring> &folders, bool &ignore_virtual)
{
	Form15 = new TForm15(Application);

	Form15->cbIgnoreVirtual->Checked = !ignore_virtual;

	if (folders.size() != 0)
	{
		for (std::wstring folder : folders)
		{
			Form15->lbExcluded->Items->Add(folder.c_str());
		}
	}

	Form15->ToggleSave();

	if (Form15->ShowModal() == mrOk)
	{
		folders.clear();

		for (int t = 0; t < Form15->lbExcluded->Items->Count; t++)
		{
			folders.push_back(Form15->lbExcluded->Items->Strings[t].c_str());
		}

		ignore_virtual = !Form15->cbIgnoreVirtual->Checked;
	}

	delete Form15;
}


void TForm15::Init()
{
	Caption = GLanguageHandler->Text[kExcludeFromScan].c_str();

	cbIgnoreVirtual->Caption = GLanguageHandler->Text[kIgnoreVirtualFolders].c_str();
	bCancel->Caption         = GLanguageHandler->Text[kCancel].c_str();
	sbSpecial->Caption       = GLanguageHandler->Text[kSpecial].c_str();
	bSave->Caption           = GLanguageHandler->Text[kSave].c_str();
	bOpen->Caption           = GLanguageHandler->Text[kOpen].c_str();

	miSF1->Caption = WindowsUtility::GetSpecialFolder(1).c_str();
	miSF2->Caption = WindowsUtility::GetSpecialFolder(2).c_str();
	miSF3->Caption = WindowsUtility::GetSpecialFolder(3).c_str();
	miSF4->Caption = WindowsUtility::GetSpecialFolder(4).c_str();
}


#pragma region Popup_Menu
void __fastcall TForm15::miSF1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	std::wstring folder = mi->Caption.c_str();

	lbExcluded->Items->Add((folder + L"*").c_str());
}
#pragma end_region


void __fastcall TForm15::bOpenClick(TObject *Sender)
{
	odExclude->InitialDir = (GSystemGlobal->ExePath + L"data\\").c_str();
	odExclude->Filter     = GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt";
	odExclude->DefaultExt = L".txt";

	if (odExclude->Execute())
	{
		lbExcluded->Items->LoadFromFile(odExclude->FileName);
	}
}


void __fastcall TForm15::sbSpecialClick(TObject *Sender)
{
	puSF->Popup(Left + sbSpecial->Left, Top + 55);
}


void __fastcall TForm15::lbExcludedClick(TObject *Sender)
{
	if (lbExcluded->ItemIndex != -1)
	{
		sbRemove->Enabled = true;
		sbEdit->Enabled   = true;
	}
	else
	{
		sbRemove->Enabled = false;
		sbEdit->Enabled   = false;
	}
}


void __fastcall TForm15::sbRemoveClick(TObject *Sender)
{
	lbExcluded->DeleteSelected();

	ToggleSave();
}


void __fastcall TForm15::sbEditClick(TObject *Sender)
{
	std::wstring s = InputBox(GLanguageHandler->Text[kEditExclusion].c_str(),
							  GLanguageHandler->Text[kEdit].c_str(),
							  lbExcluded->Items->Strings[lbExcluded->ItemIndex]).c_str();

	if (!s.empty())
	{
		lbExcluded->Items->Strings[lbExcluded->ItemIndex] = s.c_str();
	}
}


void __fastcall TForm15::bSaveClick(TObject *Sender)
{
	sdExclude->InitialDir = (GSystemGlobal->ExePath + L"data\\").c_str();
	sdExclude->Filter     = (GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt").c_str();
	sdExclude->DefaultExt = L".txt";

	if (sdExclude->Execute())
	{
		lbExcluded->Items->SaveToFile(sdExclude->FileName);
	}
}


void __fastcall TForm15::sbAddClick(TObject *Sender)
{
	std::vector<std::wstring> paths;

	if (WindowsUtility::BrowseForFolder(paths, true, false))
	{
		std::wstring folder = paths[0] + L"*";

		lbExcluded->Items->Add(folder.c_str());

		ToggleSave();
	}
}


void TForm15::ToggleSave()
{
	if (lbExcluded->Items->Count == 0)
	{
		bSave->Enabled = false;
		bOK->Enabled   = false;
	}
	else
	{
		bSave->Enabled = true;
		bOK->Enabled   = true;
	}
}
