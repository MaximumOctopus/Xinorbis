//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormCombine.h"

#include "LanguageHandler.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
}


void OpenCombine(std::vector<std::wstring> &data)
{
/*  dc : TStringList;
  t : integer;

	Form13 = new TForm13(Application)

	odCombine->InitialDir = GSystemGlobal.AppDataPath + 'saves';
	sdCombine->InitialDir = GSystemGlobal.AppDataPath + 'saves';

	if (Form13->ShowModal() == mrOk)
	{
		for (int t = 0; lbCombine->Items->Count; t++)
		{
			data.push_back(lbCombine.Items[t].c_str());
		}
	}*/
}


void __fastcall TForm13::FormCreate(TObject *Sender)
{
	Init();

/*	FormDetails fd = XSettings.LoadFormDetails(_FormCombine);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}*/
}


void __fastcall TForm13::FormClose(TObject *Sender, TCloseAction &Action)
{
/*	FormDetails fd;

	fd.FormId :=_FormCombine;
	fd.X = Left;
	fd.Y = Top;
	fd.Width = Width;
	fd.Height = Height;

	XSettings.SaveFormDetails(fd);*/

	Action = caFree;
}


void TForm13::Init()
{
	lChoose->Caption     = GLanguageHandler->Text[kChooseFolders].c_str();
	lFolderList->Caption = GLanguageHandler->Text[kFoldersToScan].c_str();

	sbExplore->Caption   = GLanguageHandler->Text[kExploreFolder].c_str();

	bSaveList->Caption   = GLanguageHandler->Text[kSave].c_str();
	bLoadList->Caption   = GLanguageHandler->Text[kLoad].c_str();
	bScan->Caption       = GLanguageHandler->Text[kScan].c_str();
	bCancel->Caption     = GLanguageHandler->Text[kCancel].c_str();

	Caption              = GLanguageHandler->Text[kCombineDrivesFolders].c_str();
}


void __fastcall TForm13::sbDrive2AddClick(TObject *Sender)
{
/*	if (eDirectory->Text != L"")
	{
		if (System.SysUtils.DirectoryExists(eDirectory->Text)
		{
			if (eDirectory->Text[length(eDirectory.Text)] != L"\\")
			{
				std::wstring folder = eDirectory->Text.c_str();

				eDirectory->Text = folder + L"\\";
			}

			lbCombine->Items->Add(eDirectory->Text);
			eDirectory->Text = L"";

			bScan->Enabled = true;
			bSaveList->Enabled = true;
		}
	} */
}


void __fastcall TForm13::bSaveListClick(TObject *Sender)
{
	if (sdCombine->Execute())
	{
		lbCombine->Items->SaveToFile(sdCombine->FileName);
	}
}


void __fastcall TForm13::bLoadListClick(TObject *Sender)
{
	if (odCombine->Execute())
	{
		lbCombine->Clear();

		lbCombine->Items->LoadFromFile(odCombine->FileName);

		if (lbCombine->Count != 0)
		{
			bScan->Enabled = true;
		}

		for (int t = 0; t < lbCombine->Count; t++)
		{
//			if not(System.SysUtils.DirectoryExists(lbCombine.Items[t]))
//			{
//				ShowXDialog(XText[rsError] + ': ' + XText[rsFolder],
//							XText[rsFolder] + ': "' + lbCombine.Items[t] + '" ' + XText[rsDoesNotExist],
//							XDialogTypeWarning);
//			}
		}
	}
}


void __fastcall TForm13::eDirectoryKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN)
	{
		sbDrive2AddClick(NULL);
	}
}


void __fastcall TForm13::SpeedButton4Click(TObject *Sender)
{
	std::vector<std::wstring> paths;

	if (WindowsUtility::BrowseForFolder(paths, true, false))
	{
		std::wstring folder = paths[0];

		if (!folder.empty())
		{
			eDirectory->Text = folder.c_str();
		}
    }
}


void __fastcall TForm13::sbExploreClick(TObject *Sender)
{
	std::wstring folder = lbCombine->Items->Strings[lbCombine->ItemIndex].c_str();

	WindowsUtility::ExecuteFile(L"\"" + folder + L"\"", L"");
}


void __fastcall TForm13::lbCombineClick(TObject *Sender)
{
	if (lbCombine->SelCount != 0)
	{
		sbDelete->Enabled  = true;
		sbExplore->Enabled = true;
	}
	else
	{
		sbDelete->Enabled  = false;
		sbExplore->Enabled = false;
	}
}


void __fastcall TForm13::sbDeleteClick(TObject *Sender)
{
	lbCombine->DeleteSelected();

	if (lbCombine->Items->Count == 0)
	{
		bScan->Enabled = false;
		bSaveList->Enabled = false;
	}
}
