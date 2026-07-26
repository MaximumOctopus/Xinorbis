
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormExcludeFiles.h"

#include "LanguageHandler.h"
#include "SystemGlobal.h"

extern LanguageHandler *GLanguageHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm14 *Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner)
	: TForm(Owner)
{
}


void OpenExcludedFiles(std::vector<std::wstring> &files)
{
	TForm14 *Form14 = new TForm14(Application);

	if (files.size() != 0)
	{
		for (std::wstring file : files)
		{
			Form14->lbExcluded->Items->Add(file.c_str());
		}
	}

	Form14->ToggleSave();

	if (Form14->ShowModal() == mrOk)
	{
		files.clear();

		for (int t = 0; t < Form14->lbExcluded->Items->Count; t++)
		{
			files.push_back(Form14->lbExcluded->Items->Strings[t].c_str());
		}
	}

    delete Form14;
}


void __fastcall TForm14::FormCreate(TObject *Sender)
{
	Caption = GLanguageHandler->Text[kExcludeFilesFromScan].c_str();

	lPatternToExclude->Caption = GLanguageHandler->Text[kPatternToExclude].c_str();

	bSave->Caption   = GLanguageHandler->Text[kSave].c_str();
	bOpen->Caption   = GLanguageHandler->Text[kOpen].c_str();
	bCancel->Caption = GLanguageHandler->Text[kCancel].c_str();
}


void __fastcall TForm14::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}


void TForm14::ToggleSave()
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


void __fastcall TForm14::sbAddClick(TObject *Sender)
{
	if (ePattern->Text != L"")
	{
		lbExcluded->Items->Add(ePattern->Text);

		ePattern->Text = L"";

		ToggleSave();
	}
}


void __fastcall TForm14::ePatternKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN)
	{
		sbAddClick(NULL);
	}
}


void __fastcall TForm14::bSaveClick(TObject *Sender)
{
	sdExclude->InitialDir = (GSystemGlobal->ExePath + L"data\\").c_str();
	sdExclude->Filter     = (GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt").c_str();
	sdExclude->DefaultExt = L".txt";

	if (sdExclude->Execute())
	{
		lbExcluded->Items->SaveToFile(sdExclude->FileName);
	}
}


void __fastcall TForm14::bOpenClick(TObject *Sender)
{
	odExclude->InitialDir = (GSystemGlobal->ExePath + L"data\\").c_str();
	odExclude->Filter     = GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt";
	odExclude->DefaultExt = L".txt";

	if (odExclude->Execute())
	{
		lbExcluded->Items->LoadFromFile(odExclude->FileName);
	}
}


void __fastcall TForm14::sbRemoveClick(TObject *Sender)
{
	lbExcluded->DeleteSelected();

	ToggleSave();
}


void __fastcall TForm14::sbEditClick(TObject *Sender)
{
	std::wstring s = InputBox(GLanguageHandler->Text[kEditExclusion].c_str(),
							  GLanguageHandler->Text[kEdit].c_str(),
							  lbExcluded->Items->Strings[lbExcluded->ItemIndex].c_str()).c_str();

	if (!s.empty())
	{
		lbExcluded->Items->Strings[lbExcluded->ItemIndex] = s.c_str();
	}
}


void __fastcall TForm14::lbExcludedClick(TObject *Sender)
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
