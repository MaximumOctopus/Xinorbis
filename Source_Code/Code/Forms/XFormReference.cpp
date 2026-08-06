//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormReference.h"
#include "XFormXinorbisDialog.h"

#include <algorithm>
#include <fstream>

#include "ConstantsGui.h"
#include "FileExtensionHandler.h"
#include "FormDetails.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"

extern FileExtensionHandler *GFileExtensionHandler;
extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void ShowReference()
{
	Form2 = new TForm2(Application);

	Form2->ShowModal();

	delete Form2;
}


void __fastcall TForm2::FormCreate(TObject *Sender)
{
	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormReference);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}
}


void __fastcall TForm2::FormShow(TObject *Sender)
{
	Caption = GLanguageHandler->Text[kReference].c_str();

	pcReference->Pages[0]->Caption = GLanguageHandler->Text[kFileExtensions].c_str();
	pcReference->Pages[0]->Caption = GLanguageHandler->Text[kWindowsFiles].c_str();
}


void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormReference, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


void __fastcall TForm2::sbFileExtensionsClick(TObject *Sender)
{
	mResults->Clear();

	if (eFileExtension->Text != L"")
	{
		std::wstring s = eFileExtension->Text.c_str();

		if (s[0] == L'.')
		{
			s = s.substr(1);
		}

		std::transform(s.begin(), s.end(), s.begin(), ::toupper);

		for (int t = 0; t < GFileExtensionHandler->Descriptions.size(); t++)
		{
			if (GFileExtensionHandler->Descriptions[t].find(s) != std::wstring::npos)
			{
				mResults->Lines->Add(GFileExtensionHandler->Descriptions[t].c_str());
			}
		}

		if (mResults->Lines->Count == 0)
		{
			mResults->Lines->Add(GLanguageHandler->Text[kNoneFound].c_str());
		}
	}
}


void __fastcall TForm2::eFileExtensionKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN)
	{
		sbFileExtensionsClick(NULL);
	}
}


void __fastcall TForm2::eFileExtensionChange(TObject *Sender)
{
	if (eFileExtension->Text == L"")
	{
		sbFileExtensions->Enabled = false;
	}
	else
	{
		sbFileExtensions->Enabled = true;
	}
}


void __fastcall TForm2::eWindowsFileKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN)
	{
		sbWindowsFileClick(NULL);
	}
}


void __fastcall TForm2::eWindowsFileChange(TObject *Sender)
{
	if (eWindowsFile->Text == L"")
	{
		sbWindowsFile->Enabled = false;
	}
	else
	{
		sbWindowsFile->Enabled = true;
	}
}


void __fastcall TForm2::sbWindowsFileClick(TObject *Sender)
{
	std::wstring data_file_name = L"Windows7_dlls.dat";

	if (rbXP->Checked)
	{
		data_file_name = L"WindowsXP_dlls.dat";
	}

	std::wifstream file(data_file_name);

	if (file)
	{
		mResults->Clear();

		std::wstring search = eWindowsFile->Text.c_str();

		std::transform(search.begin(), search.end(), search.begin(), ::toupper);

		std::wstring s = L"";

		while (std::getline(file, s))
		{
	        std::transform(s.begin(), s.end(), s.begin(), ::toupper);

			if (s.find(search) != std::wstring::npos)
			{
				int idx = s.find(L',');

				if (idx != std::wstring::npos)
				{
					mResults->Lines->Add(s.substr(0, idx - 1).c_str());
					mResults->Lines->Add(s.substr(idx + 1).c_str());
					mResults->Lines->Add(L"");
				}
			}
		}

		file.close();
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kErrorOpeningXinorbisSystemFile],
					GLanguageHandler->Text[kErrorOpening] + L" \"" + GSystemGlobal->ExePath + L"data\\system\\" + data_file_name + L"\".",
					XDialogTypeWarning);
	}
}


void __fastcall TForm2::bHelpClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"reference.htm");
}
