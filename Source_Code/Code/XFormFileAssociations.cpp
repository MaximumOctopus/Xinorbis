//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <algorithm>
#include <fstream>

#include "XFormFileAssociations.h"
#include "XFormXinorbisDialog.h"

#include "ConstantsReports.h"
#include "FileExtensionHandler.h"
#include "Formatting.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "Log.h"
#include "SaveDialogs.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"

extern FileExtensionHandler *GFileExtensionHandler;
extern LanguageHandler *GLanguageHandler;
extern Log *GLog;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormFileAssociations *FormFileAssociations;
//---------------------------------------------------------------------------
__fastcall TFormFileAssociations::TFormFileAssociations(TComponent* Owner)
	: TForm(Owner)
{
}


bool OpenFileAssociations()
{
	TFormFileAssociations *FormFileAssociations = new TFormFileAssociations(Application);

	bool user_save = false;

	if (FormFileAssociations->ShowModal() == mrOk)
	{
		FormFileAssociations->SaveCustomNames();

        user_save = true;
	}

	delete FormFileAssociations;

	return user_save;
}


void __fastcall TFormFileAssociations::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}


void TFormFileAssociations::Init()
{
	Caption = GLanguageHandler->Text[kFileTypes].c_str();

	bHelp->Caption   = GLanguageHandler->Text[kHelp].c_str();
	bSave->Caption   = GLanguageHandler->Text[kSave].c_str();
	bCancel->Caption = GLanguageHandler->Text[kCancel].c_str();

	// ===========================================================================

	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		cbFACategories->Items->Add(GLanguageHandler->TypeDescriptions[t].c_str());
	}

	lCategory->Caption        = GLanguageHandler->Text[kCategory].c_str();
	lFAColour->Caption        = GLanguageHandler->Text[kDisplayColour].c_str();
	gbAFE->Caption            = GLanguageHandler->Text[kAssociatedFileExtensions].c_str();
	sbRD->Caption             = GLanguageHandler->Text[kRestoreDefaults].c_str();

	bImportLIst->Caption      = GLanguageHandler->Text[kImportList].c_str();
	bExportList->Caption      = GLanguageHandler->Text[kExportList].c_str();

	sbRenameCategory->Caption = GLanguageHandler->Text[kRenameCustomCategory].c_str();

	cbFACategories->ItemIndex = 0;

	for (int t = 0; t < 10; t++)
	{
		OldCustomNames[t] = GLanguageHandler->TypeDescriptions[t + 10];
	}

	BuildList(1);
}


void __fastcall TFormFileAssociations::lbExtListClick(TObject *Sender)
{
	if (lbExtList->SelCount == 0)
	{
		sbFADelete->Enabled = false;
		miFECut->Enabled    = false;
	}
	else
	{
		miFECut->Enabled    = true;
		sbFADelete->Enabled = true;
	}
}


void __fastcall TFormFileAssociations::sCat1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if (Shift.Contains(ssLeft))
	{
		TShape *shape = (TShape*)Sender;

		cdMain->Color = shape->Brush->Color;

		if (cdMain->Execute())
		{
			shape->Brush->Color = cdMain->Color;

			GSettingsHandler->FileCategoryColors[cbFACategories->ItemIndex + 1] = cdMain->Color;
		}
	}
}


void __fastcall TFormFileAssociations::sbSearchFileExtClick(TObject *Sender)
{
	std::wstring s = InputBox(GLanguageHandler->Text[kFileExtensions].c_str(),
							  GLanguageHandler->Text[kSearch].c_str(),
							  L"").c_str();

	if (!s.empty())
	{
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);

		std::wstring fs = L"";

		for (int i = 0; i < GFileExtensionHandler->Extensions.size(); i++)
		{
			std::wstring ext = GFileExtensionHandler->Extensions[i]->Name;

			std::transform(ext.begin(), ext.end(), ext.begin(), ::toupper);

			if (ext == s)
			{
				fs += L"- " + GLanguageHandler->TypeDescriptions[GFileExtensionHandler->Extensions[i]->Category];
			}
		}

		if (!fs.empty())
		{
			fs = GLanguageHandler->Text[kFoundIn] + L": " + fs;
		}

		ShowXDialog(GLanguageHandler->Text[kWarning],
					fs,
					XDialogTypeWarning);
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kWarning],
					L"\"" + s + L"\", " + GLanguageHandler->Text[kNoneFound],
					XDialogTypeWarning);
	}
}


void __fastcall TFormFileAssociations::sbAddClick(TObject *Sender)
{
	if (lbExtList->Items->IndexOf(eAdd->Text) == -1)
	{
		lbExtList->Items->Add(eAdd->Text);
	}

	eAdd->Text = L"";
}


void __fastcall TFormFileAssociations::sbFADeleteClick(TObject *Sender)
{
	lbExtList->DeleteSelected();
}


void __fastcall TFormFileAssociations::cbFACategoriesChange(TObject *Sender)
{
	BuildList(cbFACategories->ItemIndex);
}


void __fastcall TFormFileAssociations::eAddChange(TObject *Sender)
{
	if (eAdd->Text == L"")
	{
		sbAdd->Enabled = false;
	}
	else
	{
		sbAdd->Enabled = true;
	}
}


void __fastcall TFormFileAssociations::bHelpClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"filetypes.htm");
}


void __fastcall TFormFileAssociations::bImportLIstClick(TObject *Sender)
{
	std::wstring file_name = LoadDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt",
												  L".txt",
												  GSystemGlobal->ExePath + L"data\\layouts",
												  L"");

	if (!file_name.empty())
	{
		std::wifstream file(file_name);

		if (file)
		{
			std::wstring s = L"";

			while (std::getline(file, s))
			{
				lbExtList->Items->Add(s.c_str());
			}

			file.close();
		}
		else
		{
			ShowXDialog(GLanguageHandler->Text[kErrorOpening] + L": " + GLanguageHandler->Text[kReport],
						GLanguageHandler->Text[kErrorOpening] + L" \"" + file_name + L"\".",
						XDialogTypeWarning);
		}
	}
}


void __fastcall TFormFileAssociations::bExportListClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt",
												  L".txt",
												  GLanguageHandler->TypeDescriptions[CurrentIndex] + L".txt",
												  GSystemGlobal->ExePath + L"data\\");

	if (!file_name.empty())
	{
		std::ofstream file(file_name);

		if (file)
		{
			std::wstring s = L"";

			for (int t = 0; t < lbExtList->Items->Count; t++)
			{
				std::wstring item = lbExtList->Items->Strings[t].c_str();

				file << Formatting::to_utf8(item + L"\n");
			}

			file.close();
		}
	}
	else
	{
		  ShowXDialog(GLanguageHandler->Text[kErrorSaving] + L": " + GLanguageHandler->Text[kExtensions],
					  GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
					  XDialogTypeWarning);
	}
}


void __fastcall TFormFileAssociations::eAddKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN)
	{
		sbAddClick(NULL);
	}
}


void __fastcall TFormFileAssociations::sbRenameCategoryClick(TObject *Sender)
{
	std::wstring cfa = cbFACategories->Text.c_str();

	std::wstring s = InputBox(GLanguageHandler->Text[kRenameCustomCategory].c_str(),
							  (GLanguageHandler->Text[kEnterANameFor] + L" \""  + cfa + L"\"").c_str(),
							  cbFACategories->Text).c_str();

	if (!s.empty())
	{
		OldCustomNames[cbFACategories->ItemIndex - 10] = s;

		cbFACategories->Items->Strings[cbFACategories->ItemIndex] = s.c_str();
	}
}


void __fastcall TFormFileAssociations::miFECutClick(TObject *Sender)
{
	if (lbExtList->SelCount != 0)
	{
		SLClipboard.clear();

		for (int t = 0; t < lbExtList->Items->Count; t++)
		{
			if (lbExtList->Selected[t])
			{
				SLClipboard.push_back(lbExtList->Items->Strings[t].c_str());
			}
		}

		lbExtList->DeleteSelected();

		miFEPaste->Enabled = true;
	}
}


void __fastcall TFormFileAssociations::miFEPasteClick(TObject *Sender)
{
	if (SLClipboard.size() != 0)
	{
		for (int t = 0; t < SLClipboard.size(); t++)
		{
			lbExtList->Items->Add(SLClipboard[t].c_str());
		}

		miFECut->Enabled   = false;
		miFEPaste->Enabled = false;
	}
}


void __fastcall TFormFileAssociations::sbRDClick(TObject *Sender)
{
	if (MessageDlg(GLanguageHandler->Text[kRestoreDefaultExtensions].c_str(), mtWarning, mbYesNo, 0) == mrYes)
	{
		// clear the file-extension caches first
		GFileExtensionHandler->Extensions.clear();

		GFileExtensionHandler->LoadFileExtensions(GSystemGlobal->ExePath, false);

		// =========================================================================

		for (int t = 0; t < kFileCategoriesCount; t++)
		{
			GSettingsHandler->FileCategoryColors[t] = kDefaultDisplayColours[t];
		}

		// =========================================================================

		for (int t = 0; t < 10; t++)
		{
			OldCustomNames[t] = L"custom" + std::to_wstring(t + 1);
		}

		CurrentIndex = -1;

		cbFACategories->ItemIndex = 0;

		BuildList(cbFACategories->ItemIndex);
	}
}


void TFormFileAssociations::BuildList(int index)
{
	//-- save current -----------------------------------------------------------
	if (index != -1)
	{
		int t = GFileExtensionHandler->Extensions.size() - 1;

		while (t >= 0)
		{
			if (GFileExtensionHandler->Extensions[t]->Category == index)
			{
				GFileExtensionHandler->Extensions.erase(GFileExtensionHandler->Extensions.begin() + t);
			}
			else
			{
				t--;
			}
		}

		if (lbExtList->Items->Count != 0)
		{
			for (int t = 0; t < lbExtList->Items->Count; t++)
			{
				FileExtension *tfx = new FileExtension(lbExtList->Items->Strings[t].c_str(), index);

				GFileExtensionHandler->Extensions.push_back(tfx);
			}
		}
	}

	//-- load new idx  -----------------------------------------------------------

	lbExtList->Clear();

	sCat1->Brush->Color = TColor(GSettingsHandler->FileCategoryColors[index]);

	if (index >= kCategory_Custom_1 && index <= kCategory_Custom_10)
	{
		sbRenameCategory->Enabled = true;
	}
	else
	{
		sbRenameCategory->Enabled = false;
	}

	if (index != kFileCategoriesOther)
	{
		for (int t = 0; t < GFileExtensionHandler->Extensions.size(); t++)
		{
			FileExtension *tfx = GFileExtensionHandler->Extensions[t];

			if (tfx->Category == index)
			{
				if (lbExtList->Items->IndexOf(tfx->Name.c_str()) == -1)
				{
					lbExtList->Items->Add(tfx->Name.c_str());
				}
			}
		}

		eAdd->Enabled        = true;
		bImportLIst->Enabled = true;
		bExportList->Enabled = true;
	}
	else
	{
		eAdd->Enabled        = false;
		bImportLIst->Enabled = false;
		bExportList->Enabled = false;
	}

	CurrentIndex = index;
}


void TFormFileAssociations::SaveCustomNames()
{
	bool haschanged = false;

	for (int t = 0; t < 10; t++)
	{
		if (OldCustomNames[t] != GLanguageHandler->TypeDescriptions[10 + t])
		{
			haschanged = true;
		}
	}

	if (!haschanged) return;

	if (GSettingsHandler->OpenSettings(false))
	{
		for (int t = 0; t < 10; t++)
		{
			GLanguageHandler->TypeDescriptions[10 + t] = OldCustomNames[t];

			GSettingsHandler->WriteString(L"TypeDescriptions", L"TypeDescriptions" + std::to_wstring(t + 1), GLanguageHandler->TypeDescriptions[10 + t]);
		}

		GSettingsHandler->CloseSettings();
	}
	else
	{
		GLog->AddError(L"Error saving Custom Type Descriptions.");
	}
}
