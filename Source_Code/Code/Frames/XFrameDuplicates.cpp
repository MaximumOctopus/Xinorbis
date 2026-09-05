//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>

#include "XFrameDuplicates.h"
#include "XFormGetCopyMove.h"
#include "XFormXinorbisDialog.h"

#include "ConstantsGui.h"
#include "Formatting.h"
#include "GridUtility.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "Log.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;
extern Log *GLog;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameDuplicates *FrameDuplicates;
//---------------------------------------------------------------------------
__fastcall TFrameDuplicates::TFrameDuplicates(TComponent* Owner)
	: TFrame(Owner)
{
	Init();
}


void __fastcall TFrameDuplicates::FrameResize(TObject *Sender)
{
	sgDuplicatesName->ColWidths[0] = sgDuplicatesName->Width - (64 + __WidthOfScrollbar);
	sgDuplicatesSize->ColWidths[0] = sgDuplicatesSize->Width - (64 + __WidthOfScrollbar);
}


void TFrameDuplicates::Init()
{
	tsDuplicatesName->Caption = GLanguageHandler->Text[kDuplicatesName].c_str();
	tsDuplicatesSize->Caption = GLanguageHandler->Text[kDuplicatesSize].c_str();

	sgDuplicatesName->ColWidths[1] = 64;
	sgDuplicatesName->ColWidths[2] = -1;
	sgDuplicatesName->Cells[0][0]  = GLanguageHandler->Text[kFilePath].c_str();
	sgDuplicatesName->Cells[1][0]  = GLanguageHandler->Text[kSize].c_str();

	sgDuplicatesSize->ColWidths[1] = 64;
	sgDuplicatesSize->ColWidths[2] = -1;
	sgDuplicatesSize->Cells[0][0]  = GLanguageHandler->Text[kFilePath].c_str();
	sgDuplicatesSize->Cells[1][0]  = GLanguageHandler->Text[kSize].c_str();

	miExploreDirectory->Caption = GLanguageHandler->Text[kExploreFolder].c_str();

	miSearchOpen->Caption       = GLanguageHandler->Text[kViewOpenFile].c_str();
	miSearchOpenCustom->Caption = GLanguageHandler->Text[kOpenWithCustomViewer].c_str();
	miExploreDirectory->Caption = GLanguageHandler->Text[kExploreFolder].c_str();
	miSFileProperties->Caption  = GLanguageHandler->Text[kFileProperties].c_str();
	miGenerateMD5->Caption      = GLanguageHandler->Text[kGenerateMD5].c_str();
	miHexEdit->Caption          = GLanguageHandler->Text[kHexEdit].c_str();

	miCopyMenu->Caption         = GLanguageHandler->Text[kCopy].c_str();
	miCopySelected->Caption     = (GLanguageHandler->Text[kSelected] + kEllipsis).c_str();
	miMoveMenu->Caption         = GLanguageHandler->Text[kMove].c_str();
	miMoveSelected->Caption     = (GLanguageHandler->Text[kSelected] + kEllipsis).c_str();
	miDeleteMenu->Caption       = GLanguageHandler->Text[kDelete].c_str();
	miDeleteSelected->Caption   = (GLanguageHandler->Text[kSelected] + kEllipsis).c_str();

	miSearchExportToCB->Caption = GLanguageHandler->Text[kCopyResultsToClipboard].c_str();

	miSSave->Caption            = (GLanguageHandler->Text[kSaveAs] + kEllipsis).c_str();
}


void TFrameDuplicates::SetTab(int tab)
{
	pcDuplicates->ActivePageIndex = tab;
}


int TFrameDuplicates::GetActivePage()
{
	return pcDuplicates->ActivePageIndex;
}


std::wstring TFrameDuplicates::GetSelectedFileName(int tag)
{
	switch (tag)
	{
	case 2:
		return sgDuplicatesName->Cells[0][sgDuplicatesName->Selection.Top].c_str();
	case 3:
		return sgDuplicatesSize->Cells[0][sgDuplicatesSize->Selection.Top].c_str();
	}

	return L"";
}


#pragma region Gui
void __fastcall TFrameDuplicates::pcDuplicatesResize(TObject *Sender)
{
	sgDuplicatesName->ColWidths[0] = sgDuplicatesName->Width - (64 + __WidthOfScrollbar);
	sgDuplicatesSize->ColWidths[0] = sgDuplicatesSize->Width - (64 + __WidthOfScrollbar);
}


void __fastcall TFrameDuplicates::sgDuplicatesNameDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	if (ARow != 0)
	{
		static_cast<TStringGrid*>(Sender)->Canvas->Font->Style = TFontStyles();

		if (State.Contains(gdSelected))
		{
			static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(kGridColourSelected);
		}
		else
		{
			if (ARow % 2)
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(kGridColourOff);
			}
			else
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(kGridColourOn);
			}
		}

		static_cast<TStringGrid*>(Sender)->Canvas->FillRect(Rect);

		switch (ACol)
		{
		case 1:
		{
			int left = Rect.Right - static_cast<TStringGrid*>(Sender)->Canvas->TextWidth(static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]) - 2;
			static_cast<TStringGrid*>(Sender)->Canvas->TextOut(left, Rect.Top + 3, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
			break;
		}
		default:
			if (static_cast<TStringGrid*>(Sender)->ColWidths[0] != -1)
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Style = bsClear;
				static_cast<TStringGrid*>(Sender)->Canvas->Font->Color = clWhite;
				static_cast<TStringGrid*>(Sender)->Canvas->TextOut(Rect.Left, Rect.Top, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
			}
		}
	}
	else
	{
		static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(kGridHeader);
		static_cast<TStringGrid*>(Sender)->Canvas->FillRect(Rect);

		static_cast<TStringGrid*>(Sender)->Canvas->Brush->Style = bsClear;
		static_cast<TStringGrid*>(Sender)->Canvas->Font->Color = clWhite;
		static_cast<TStringGrid*>(Sender)->Canvas->Font->Style = TFontStyles() << fsBold;
		static_cast<TStringGrid*>(Sender)->Canvas->TextOut(Rect.Left, Rect.Top, static_cast<TStringGrid*>(Sender)->Cells[ACol][0]);
	}
}
#pragma end_region


#pragma region Duplicates_Name
void __fastcall TFrameDuplicates::sbDNGoClick(TObject *Sender)
{
	Screen->Cursor = crHourGlass;

	// =========================================================================

//	sgDuplicatesName.ClearRows(1, sgDuplicatesName->RowCount - 1);
	sgDuplicatesName->RowCount = 2;
	sgDuplicatesName->BeginUpdate();

	bool status = false;
	std::wstring fn = L"";
	int count = 0;

	GScanEngine->Data[DataSource].SortByProperty(SortMode::kFileName);

	// ===========================================================================

	for (int t = 1; t < GScanEngine->Data[DataSource].Files.size(); t++)
	{
		FileObject *tfo1 = GScanEngine->Data[DataSource].Files[t - 1];
		FileObject *tfo2 = GScanEngine->Data[DataSource].Files[t];

		if (tfo1->Name == tfo2->Name)
		{
			if (fn.empty())
			{
				sgDuplicatesName->Cells[0][sgDuplicatesName->RowCount - 1] = (GScanEngine->Data[DataSource].Folders[tfo1->FilePathIndex] + tfo1->Name).c_str();;

				if (!(tfo1->Attributes & faDirectory))
				{
					sgDuplicatesName->Cells[1][sgDuplicatesName->RowCount - 1] = Convert::ConvertToUsefulUnit(tfo1->Size).c_str();
					sgDuplicatesName->Cells[2][sgDuplicatesName->RowCount - 1] = std::to_wstring(tfo1->Size).c_str();
				}
				else
				{
					sgDuplicatesName->Cells[1][sgDuplicatesName->RowCount - 1] = GLanguageHandler->Text[kFolder].c_str();
					sgDuplicatesName->Cells[2][sgDuplicatesName->RowCount - 1] = L"0";
				}

				sgDuplicatesName->RowCount++;

				fn = tfo1->Name;

				count++;
			}

			sgDuplicatesName->Cells[0][sgDuplicatesName->RowCount - 1] = (GScanEngine->Data[DataSource].Folders[tfo2->FilePathIndex] + tfo2->Name).c_str();
			sgDuplicatesName->Cells[1][sgDuplicatesName->RowCount - 1] = Convert::ConvertToUsefulUnit(tfo2->Size).c_str();

			if (!(tfo2->Attributes & faDirectory))
			{
				sgDuplicatesName->Cells[1][sgDuplicatesName->RowCount - 1] = Convert::ConvertToUsefulUnit(tfo2->Size).c_str();;
				sgDuplicatesName->Cells[2][sgDuplicatesName->RowCount - 1] = std::to_wstring(tfo1->Size).c_str();
			}
			else
			{
				sgDuplicatesName->Cells[1][sgDuplicatesName->RowCount - 1] = GLanguageHandler->Text[kFolder].c_str();
				sgDuplicatesName->Cells[2][sgDuplicatesName->RowCount - 1] = L"0";
			}

			sgDuplicatesName->RowCount++;
		}
		else
		{
			if (!fn.empty())
			{
				sgDuplicatesName->RowCount++;
			}

			fn = L"";
		}
	}

	// ===========================================================================

	lDSStatus->Caption = (GLanguageHandler->Text[kFound] + L" " + std::to_wstring(count) + L" " + GLanguageHandler->Text[kDuplicateFilenames] + L".").c_str();

	if (count == 0)
	{
		status = false;
	}
	else
	{
		status = true;
	}

	sbDNSave->Enabled = status;
	sbDNClipboard->Enabled = status;
	sbDNCSV->Enabled = status;

	sgDuplicatesName->EndUpdate();

	Screen->Cursor = crDefault;
}


void __fastcall TFrameDuplicates::sbDNHelpClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"a21.htm");
}


void __fastcall TFrameDuplicates::sbDNSaveClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt",
												  L".txt",
												  Utility::GetDefaultFileName(L".txt", L"duplicates_" + GLanguageHandler->Text[kReport]),
												  GSystemGlobal->AppDataPath + L"Saves\\Duplicates");

	if (!file_name.empty())
	{
		std::ofstream file(file_name);

		if (file)
		{
			for (int t = 1; t < sgDuplicatesName->RowCount; t++)
			{
				std::wstring a = sgDuplicatesName->Cells[1][t].c_str();
				std::wstring b = sgDuplicatesName->Cells[0][t].c_str();

				file << Formatting::to_utf8(Formatting::AddLeading(a, 10, L' ') + L" " + b + L"\n");
			}

			file.close();
		}
		else
		{
			ShowXDialog(GLanguageHandler->Text[kErrorSaving] + L": " + GLanguageHandler->Text[kDuplicatesFileName],
						GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
						XDialogTypeWarning);
		}
	}
}


void __fastcall TFrameDuplicates::sbDNCSVClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.csv)|*.csv",
												  L".csv",
												  Utility::GetDefaultFileName(L".csv", L"duplicates_" + GLanguageHandler->Text[kReport]),
												  GSystemGlobal->AppDataPath + L"Saves\\Duplicates");

	if (!file_name.empty())
	{
		std::ofstream file(file_name);

		if (file)
		{
			for (int t = 1; t < sgDuplicatesName->RowCount; t++)
			{
				if (sgDuplicatesName->Cells[0][t] != L"")
				{
					std::wstring a = sgDuplicatesName->Cells[0][t].c_str();
					std::wstring b = sgDuplicatesName->Cells[1][t].c_str();
					std::wstring c = sgDuplicatesName->Cells[2][t].c_str();

					file << Formatting::to_utf8(L"\"" + a + L"\"," + b + L"," + L"\n");
				}
			}

			file.close();
		}
		else
		{
			ShowXDialog(GLanguageHandler->Text[kErrorSavingReport] + L" (CSV)",
						GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
						XDialogTypeWarning);
		}
	}
}


void __fastcall TFrameDuplicates::sbDNClipboardClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(sgDuplicatesName, 0);
}
#pragma end_region


#pragma region Duplicates_Size
void __fastcall TFrameDuplicates::sbDSGoClick(TObject *Sender)
{
	Screen->Cursor = crHourGlass;

	// ===========================================================================

//	sgDuplicatesSize.ClearRows(1, sgDuplicatesSize->RowCount - 1);
	sgDuplicatesSize->RowCount = 2;
	sgDuplicatesSize->BeginUpdate();

	unsigned __int64 fs = -1;
	int count = 0;

	GScanEngine->Data[DataSource].SortByProperty(SortMode::kSize);

	// ===========================================================================

	for (int t = 1; t < GScanEngine->Data[DataSource].Files.size(); t++)
	{
		FileObject *tfo1 = GScanEngine->Data[DataSource].Files[t - 1];
		FileObject *tfo2 = GScanEngine->Data[DataSource].Files[t];

		if (tfo1->Size == tfo2->Size &&
		   !(tfo1->Attributes & faDirectory) &&
		   !(tfo2->Attributes & faDirectory))
		{
			if (fs == -1)
			{
				sgDuplicatesSize->Cells[0][sgDuplicatesSize->RowCount - 1] = (GScanEngine->Data[DataSource].Folders[tfo1->FilePathIndex] + tfo1->Name).c_str();
				sgDuplicatesSize->Cells[1][sgDuplicatesSize->RowCount - 1] = Convert::ConvertToUsefulUnit(tfo1->Size).c_str();
				sgDuplicatesSize->Cells[2][sgDuplicatesSize->RowCount - 1] = tfo1->Size;

				sgDuplicatesSize->RowCount++;

				fs = tfo1->Size;

				count++;
			}

			sgDuplicatesSize->Cells[0][sgDuplicatesSize->RowCount - 1] = (GScanEngine->Data[DataSource].Folders[tfo2->FilePathIndex] + tfo2->Name).c_str();
			sgDuplicatesSize->Cells[1][sgDuplicatesSize->RowCount - 1] = Convert::ConvertToUsefulUnit(tfo2->Size).c_str();
			sgDuplicatesSize->Cells[2][sgDuplicatesSize->RowCount - 1] = tfo2->Size;

			sgDuplicatesSize->RowCount++;
		}
		else
		{
			if (fs != -1)
			{
				sgDuplicatesSize->RowCount++;

				fs = -1;
			}
		}
	}

	// ===========================================================================

	lDNStatus->Caption = (GLanguageHandler->Text[kFound] + L" " + std::to_wstring(count) + L" " + GLanguageHandler->Text[kDuplicateFilenames] + L".").c_str();

	bool status = false;

	if (count == 0)
	{
		status = false;
	}
	else
	{
		status = true;
	}

	sbDSSave->Enabled    = status;
	sbDSClipboard->Enabled    = status;
	sbDSCSV->Enabled = status;

	sgDuplicatesSize->EndUpdate();

	Screen->Cursor = crDefault;
}


void __fastcall TFrameDuplicates::sbDSHelpClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"a31.htm");
}


void __fastcall TFrameDuplicates::sbDSSaveClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kXFileList] + L" (*.txt)|*.txt",
												  L".txt",
												  Utility::GetDefaultFileName(L".txt", L"duplicates_" + GLanguageHandler->Text[kReport]),
												  GSystemGlobal->AppDataPath + L"Saves\\Duplicates");

	if (!file_name.empty())
	{
		std::ofstream file(file_name);

		if (file)
		{
			for (int t = 1; t < sgDuplicatesSize->RowCount; t++)
			{
				std::wstring a = sgDuplicatesSize->Cells[1][t].c_str();
				std::wstring b = sgDuplicatesSize->Cells[1][t].c_str();

				file << Formatting::to_utf8(Formatting::AddLeading(a, 10, L' ') + Formatting::AddLeading(b, 10, L' ') + L"\n");
			}

			file.close();
		}
		else
		{
			ShowXDialog(GLanguageHandler->Text[kErrorSaving] + L": " + GLanguageHandler->Text[kDuplicatesFileSize],
						GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
						XDialogTypeWarning);
		}

	}
}


void __fastcall TFrameDuplicates::sbDSCSVClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.csv)|*.csv",
												  L".csv",
												  Utility::GetDefaultFileName(L".csv", L"duplicates_" + GLanguageHandler->Text[kReport]),
												  GSystemGlobal->AppDataPath + L"Saves\\Duplicates");

	if (!file_name.empty())
	{
		std::ofstream file(file_name);

		if (file)
		{
			for (int t = 1; t < sgDuplicatesSize->RowCount; t++)
			{
				if (sgDuplicatesSize->Cells[0][t] != L"")
				{
					std::wstring a = sgDuplicatesSize->Cells[0][t].c_str();
					std::wstring b = sgDuplicatesSize->Cells[1][t].c_str();
					std::wstring c = sgDuplicatesSize->Cells[2][t].c_str();

					file << Formatting::to_utf8(L"\"" + a + L"\"," + b + L"," + c + L"\n");
				}
			}

			file.close();
		}
		else
		{
			ShowXDialog(GLanguageHandler->Text[kErrorSavingReport] + L" (CSV)",
						GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
						XDialogTypeWarning);
		}
	}
}


void __fastcall TFrameDuplicates::sbDSClipboardClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(sgDuplicatesSize, 0);
}
#pragma end_region


#pragma region Popup_Search
void __fastcall TFrameDuplicates::puSearchPopup(TObject *Sender)
{
	bool status = true;

	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		status = false;
	}

	miSearchOpen->Enabled       = status;
	miSearchOpenCustom->Enabled = status;
	miExploreDirectory->Enabled = status;
	miSFileProperties->Enabled  = status;
	miGenerateMD5->Enabled      = status;
	miHexEdit->Enabled          = status;
	miCopyMenu->Enabled         = status;
	miMoveMenu->Enabled         = status;
	miDeleteMenu->Enabled       = status;
	miSearchExportToCB->Enabled = status;
	miSSave->Enabled            = status;
}


void __fastcall TFrameDuplicates::miSearchOpenClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		WindowsUtility::ExecuteFile(L"\"" + file_name + L"\"", L"");
	}
}


void __fastcall TFrameDuplicates::miSearchOpenCustomClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		if (FileExists(file_name.c_str()))
		{
			WindowsUtility::ExecuteFile(L"\"" + GSettingsHandler->General.CustomViewer + L"\"", L"\"" + file_name + L"\"");
		}
		else
		{
			GLog->AddError(L"miSearchOpenCustomClick() loading file \"" + file_name + L"\".");
		}
	}
}


void __fastcall TFrameDuplicates::miExploreDirectoryClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		std::wstring fe = ExtractFilePath(file_name.c_str()).c_str();

		WindowsUtility::ExecuteFile(L"\"" + fe + L"\"", L"");
	}
}


void __fastcall TFrameDuplicates::miSFilePropertiesClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, file_name);
	}
}


void __fastcall TFrameDuplicates::miHexEditClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		WindowsUtility::ExecuteFile(L"\"" + GSystemGlobal->ExePath + L"\\Be.HexEditor.exe\"", file_name);
	}
}


void __fastcall TFrameDuplicates::miGenerateMD5Click(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!file_name.empty())
	{
		//ShowMD5Checksum(file_name, TMD5.Generate(file_name));
	}
}


void __fastcall TFrameDuplicates::miCopySelectedClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kCopyTo] + kEllipsis);
	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!folder.empty() && !file_name.empty())
	{
		CopyFile(file_name.c_str(),
				 (folder + Utility::SplitFileName(file_name)).c_str(),
				 false);
	}
}


void __fastcall TFrameDuplicates::miMoveSelectedClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kMoveTo] + kEllipsis);
	std::wstring file_name = GetSelectedFileName(grid->Tag);

	if (!folder.empty() && !file_name.empty())
	{
		MoveFileEx(file_name.c_str(),
				   (folder + file_name).c_str(),
				   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
	}
}


void __fastcall TFrameDuplicates::miDeleteSelectedClick(TObject *Sender)
{
	if (MessageDlg(GLanguageHandler->Text[kDialog3].c_str(), mtWarning, mbYesNo, 0) == mrYes)
	{
		TMenuItem *mi = (TMenuItem*)Sender;
		TStringGrid *grid = (TStringGrid*)mi->GetParentMenu();

		std::wstring file_name = GetSelectedFileName(grid->Tag);

		if (!file_name.empty())
		{
			WindowsUtility::SendToRecycleBin(file_name);
		}
	}
}


void __fastcall TFrameDuplicates::miSearchExportToCBClick(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pum = (TPopupMenu*)mi->GetParentMenu();

	switch (pum->Tag)
	{
	case 2:
		sbDNClipboardClick(NULL);
		break;
	case 3:
		sbDSClipboardClick(NULL);
		break;
	}
}


void __fastcall TFrameDuplicates::miSSaveClick(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pum = (TPopupMenu*)mi->GetParentMenu();

	switch (pum->Tag)
	{
	case 2:
		sbDNSaveClick(NULL);
		break;
	case 3:
		sbDSSaveClick(NULL);
		break;
	}
}
#pragma end_region

