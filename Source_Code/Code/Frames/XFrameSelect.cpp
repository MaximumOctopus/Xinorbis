//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <algorithm>
#include <System.DateUtils.hpp>

#include "XFrameSelect.h"
#include "XFormExcludeFiles.h"
#include "XFormExcludeFolders.h"
#include "XFormXinorbisDialog.h"

#include "ConstantsGui.h"
#include "GridUtility.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "ReportInformation.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "ScanHistoryHandler.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine *GScanEngine;
extern ScanHistoryHandler *GScanHistoryHandler;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

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
	// tab scan
	tsScan->Caption = GLanguageHandler->Text[kScanDriveFolder].c_str();

	bScanNow->Caption = GLanguageHandler->Text[kScan].c_str();
	bExplore->Caption = GLanguageHandler->Text[kExplore].c_str();

	bSelect->Caption = GLanguageHandler->Text[kSelect].c_str();
	bFavourites->Caption = GLanguageHandler->Text[kFavourites].c_str();
	bExcludeFolders->Caption = GLanguageHandler->Text[kExclude].c_str();
	bExcludeFiles->Caption = GLanguageHandler->Text[kExclude].c_str();
	bCombine->Caption = GLanguageHandler->Text[kCombine].c_str();

	// tab import
	tsImport->Caption = GLanguageHandler->Text[kImportScanDetail].c_str();

	bSelectImport->Caption = GLanguageHandler->Text[kSelect].c_str();
	bOpenImport->Caption = GLanguageHandler->Text[kOpen].c_str();

	// tab history
	tsScanHistory->Caption = GLanguageHandler->Text[kScanHistory].c_str();

	sgScanHistory->ColWidths[3] = -1;
	sgScanHistory->ColWidths[4] = -1;
	sgScanHistory->Cells[0][0] = GLanguageHandler->Text[kDate].c_str();
	sgScanHistory->Cells[1][0] = GLanguageHandler->Text[kTime].c_str();
	sgScanHistory->Cells[2][0] = GLanguageHandler->Text[kFolder].c_str();
	sgScanHistory->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;

	bShowYesterday->Caption = GLanguageHandler->Text[kYesterday].c_str();
	bShowLastMonth->Caption = GLanguageHandler->Text[kLastMonth].c_str();
	bShowAll->Caption       = GLanguageHandler->Text[kAll].c_str();
	bShowThisWeek->Caption  = GLanguageHandler->Text[kThisWeek].c_str();
	bShowThisMonth->Caption = GLanguageHandler->Text[kThisMonth].c_str();
	bShowLastWeek->Caption  = GLanguageHandler->Text[kLastWeek].c_str();

	// popup menus
	miExploreFromScanHistory->Caption = GLanguageHandler->Text[kExploreFolder].c_str();
	miShowInFolderHistory->Caption    = GLanguageHandler->Text[kOpenInFileHistory].c_str();
	miSaveAs->Caption                 = (GLanguageHandler->Text[kSaveAs] + kEllipsis).c_str();

	miQFTitle->Caption = GLanguageHandler->Text[kFavourites].c_str();
	miQFAdd->Caption = GLanguageHandler->Text[kAddCurrentFolder].c_str();

	if (GScanHistoryHandler->History.size() != 0)
	{
		int index = GScanHistoryHandler->History.size() - 1;

		while (cbScanPath->Items->Count <= 20 && index >= 0)
		{
			if (cbScanPath->Items->IndexOf(GScanHistoryHandler->History[index]->Path.c_str()) == -1)
			{
				cbScanPath->Items->Insert(0, GScanHistoryHandler->History[index]->Path.c_str());
			}

			index--;
		}

        cbScanPath->ItemIndex = 0;
	}
	else
	{
		cbScanPath->Text = dlbSelect->Directory;
	}

    BuildScanHistory(0);
}


void TFrameSelect::SaveSettings()
{
	GSettingsHandler->State.LastScanPath = cbScanPath->Text.c_str();
}


#pragma region Tab_Scan
void __fastcall TFrameSelect::bScanNowClick(TObject *Sender)
{
	if (OnNewScan)
	{
		std::wstring path = cbScanPath->Text.c_str();

		if (cbScanPath->Items->IndexOf(cbScanPath->Text) == -1)
		{
			cbScanPath->Items->Insert(0, cbScanPath->Text.c_str());
		}

		OnNewScan(path, DataSource, false);
	}
}


void __fastcall TFrameSelect::bExploreClick(TObject *Sender)
{
	if (WindowsUtility::DirectoryExists(cbScanPath->Text.c_str()))
	{
		std::wstring file_name = cbScanPath->Text.c_str();

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
	std::vector<std::wstring> paths;

	if (WindowsUtility::BrowseForFolder(paths, true, false))
	{
		std::wstring folder = paths[0];

		if (!folder.empty())
		{
			cbScanPath->Text = folder.c_str();

			GScanEngine->ExcludedFolders.clear();
			GScanEngine->ExcludedFiles.clear();

			if (cbScanPath->Text[1] == L':')
			{
				dcbSelect->Drive     = folder[1];
				dlbSelect->Directory = folder.c_str();
			}
		}
	}
}


void __fastcall TFrameSelect::bFavouritesClick(TObject *Sender)
{
	TPoint mouse_pos = Mouse->CursorPos;

	puQuickFolder->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameSelect::bExcludeFoldersClick(TObject *Sender)
{
	OpenExcludedFolders(GScanEngine->ExcludedFolders, GScanEngine->AllowVirtualFiles);

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
	OpenExcludedFiles(GScanEngine->ExcludedFiles);

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
	cbScanPath->Text = dlbSelect->Directory;
}
#pragma end_region


#pragma region Tab_Import
void __fastcall TFrameSelect::bSelectImportClick(TObject *Sender)
{
	std::wstring file_name = LoadDialogs::Execute(GLanguageHandler->Text[kSupportedFileTypes] + L" (*.csv, *.zsr, *.zsr2)|*.csv; *.zsr; *.zsr2|" + GLanguageHandler->Text[kCSVFiles] + L" (*.csv)|*.csv|Xinorbis (*.zsr)|*.zsr|Xinorbis v2 (*.zsr2)|*.zsr2",
												  L".csv",
												  GSystemGlobal->AppDataPath + L"reports\\",
												  L"");

	if (!file_name.empty())
	{
		eImportFileName->Text = file_name.c_str();

		ReportDetail(file_name);
	}
}


void __fastcall TFrameSelect::bOpenImportClick(TObject *Sender)
{
	if (OnNewScan)
	{
		OnNewScan(eImportFileName->Text.c_str(), kDataScan, true);
	}
}


void TFrameSelect::ReportDetail(const std::wstring file_name)
{
	mImport->Clear();

	std::vector<std::wstring> *data = new std::vector<std::wstring>;

	std::wstring fnuc = file_name;

	std::transform(fnuc.begin(), fnuc.end(), fnuc.begin(), ::toupper);

	if (fnuc.find(L".ZSR2") != std::wstring::npos)
	{
		ReportInformation::GetInfoXinorbis2Report(file_name, data);
	}
	else if (fnuc.find(L".ZSR") != std::wstring::npos)
	{
		ReportInformation::GetInfoXinorbisReport(file_name, data);
	}
	else if (fnuc.find(L".CSV") != std::wstring::npos)
	{
		ReportInformation::GetInfoCSVReport(file_name, data);
	}
	else
	{
		data->push_back(GLanguageHandler->Text[kReport] + L": " + GLanguageHandler->Text[kUnknown]);
	}

	if (data->size() != 0)
	{
		for (std::wstring s : *data)
		{
            mImport->Lines->Add(s.c_str());
		}
	}

    delete data;
}
#pragma end_region


#pragma region Tab_Recent
void __fastcall TFrameSelect::bShowAllClick(TObject *Sender)
{
	TBitBtn *button = (TBitBtn*)Sender;

    BuildScanHistory(button->Tag);
}


void TFrameSelect::BuildScanHistory(int range)
{
	const static int kRangeAll = 0;
	const static int kRangeYesterday = 1;
	const static int kRangeThisWeek = 2;
	const static int kRangeThisMonth = 3;
	const static int kRangeLastWeek = 4;
	const static int kRangeLastMonth = 5;

	int DateFrom = 0;
	int DateTo = 0;
	int Count = 0;

	if (GScanHistoryHandler->History.size() != 0)
	{
		switch (range)
		{
		case kRangeAll:
			DateFrom = 00000000;
			DateTo   = 99999999;
			break;
		case kRangeYesterday:
			DateFrom = Convert::DateToYYYYMMDDI(IncDay(Now(), -1));
			DateTo   = Convert::DateToYYYYMMDDI(IncDay(Now(), -1));
			break;
		case kRangeThisWeek:
			DateFrom = Convert::DateToYYYYMMDDI(IncMonth(Now(), -7));
			DateTo   = Convert::DateToYYYYMMDDI(Now());
			break;
		case kRangeThisMonth:
			DateFrom = Convert::DateToYYYYMMDDI(IncDay(Now(), -31));
			DateTo   = Convert::DateToYYYYMMDDI(Now());
			break;
		case kRangeLastWeek:
			DateFrom = Convert::DateToYYYYMMDDI(IncDay(Now(), -14));
			DateTo   = Convert::DateToYYYYMMDDI(IncDay(Now(), -7));
			break;
		case kRangeLastMonth:
			DateFrom = Convert::DateToYYYYMMDDI(StartOfTheMonth(IncMonth(Now(), -1)));
			DateTo   = Convert::DateToYYYYMMDDI(EndOfTheMonth(IncMonth(Now(), -1)));
			break;

		default:
			DateFrom = 00000000;
			DateTo   = 99999999;
		}

//		sgScanHistory.ClearRows(1, sgScanHistory.RowCount - 1);
		sgScanHistory->RowCount = 2;

		for (ScanHistoryItem *sho : GScanHistoryHandler->History)
		{
			if (sho->Date >= DateFrom && sho->Date <= DateTo)
			{
				sgScanHistory->Cells[0][Count + 1] = Convert::IntDateToString(sho->Date).c_str();
				sgScanHistory->Cells[1][Count + 1] = sho->Time.c_str();
				sgScanHistory->Cells[2][Count + 1] = sho->Path.c_str();
				sgScanHistory->Cells[3][Count + 1] = sho->ExcludeFiles.c_str();
				sgScanHistory->Cells[4][Count + 1] = sho->ExcludeFolders.c_str();

				sgScanHistory->RowCount++;

				Count++;
			}
		}

		if (sgScanHistory->Cells[0][1] == L"")
		{
			sgScanHistory->Cells[0][Count + 1] = GLanguageHandler->Text[kNoneFound].c_str();
			sgScanHistory->Cells[1][Count + 1] = L"";
			sgScanHistory->Cells[2][Count + 1] = L"";
			sgScanHistory->Cells[3][Count + 1] = L"";
			sgScanHistory->Cells[4][Count + 1] = L"";
		}
	}
	else
	{
		sgScanHistory->RowCount = 2;

		sgScanHistory->Cells[0][1] = L"----";
		sgScanHistory->Cells[1][1] = L"----";
		sgScanHistory->Cells[2][1] = L"----";
		sgScanHistory->Cells[3][1] = L"";
		sgScanHistory->Cells[4][1] = L"";
	}

	tsScanHistory->Caption = (GLanguageHandler->Text[kScanHistory] + L" (" + std::to_wstring(Count) + L")").c_str();
}


void __fastcall TFrameSelect::tsScanHistoryResize(TObject *Sender)
{
	sgScanHistory->ColWidths[kScanHistoryDate] = HistoryWidths[kScanHistoryDate];
	sgScanHistory->ColWidths[kScanHistoryTime] = HistoryWidths[kScanHistoryTime];
	sgScanHistory->ColWidths[kScanHistoryPath] = sgScanHistory->Width - (__WidthOfScrollbar + HistoryWidths[kScanHistoryDate] + HistoryWidths[kScanHistoryTime]);
}


void __fastcall TFrameSelect::sgScanHistoryDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	if (ARow != 0)
	{
		if (State.Contains(gdSelected))
		{
			sgScanHistory->Canvas->Brush->Color = TColor(kGridColourSelected);

			sgScanHistory->Canvas->Font->Color = clWhite;
		}
		else
		{
			sgScanHistory->Canvas->Font->Color = clWhite;

			if (ARow % 2)
			{
				sgScanHistory->Canvas->Brush->Color = TColor(kGridColourOff);
			}
			else
			{
				sgScanHistory->Canvas->Brush->Color = TColor(kGridColourOn);
			}
		}

		sgScanHistory->Canvas->FillRect(Rect);

		switch (ACol)
		{
		case 0:
		case 1:
		case 2:
			sgScanHistory->Canvas->Brush->Style = bsClear;
			sgScanHistory->Canvas->TextOut(Rect.Left, Rect.Top, sgScanHistory->Cells[ACol][ARow]);
			break;
		}
	}
	else
	{
		sgScanHistory->Canvas->Brush->Color = TColor(kGridHeader);
		sgScanHistory->Canvas->FillRect(Rect);

		sgScanHistory->Canvas->Brush->Style = bsClear;
		sgScanHistory->Canvas->Font->Color = clWhite;
		sgScanHistory->Canvas->Font->Style = TFontStyles() << fsBold;
		sgScanHistory->Canvas->TextOut(Rect.Left, Rect.Top, sgScanHistory->Cells[ACol][0]);
		sgScanHistory->Canvas->Font->Style = TFontStyles();
	}
}
#pragma end_region


#pragma region Popup_ScanHistory
void __fastcall TFrameSelect::puScanHistoryPopup(TObject *Sender)
{
	std::wstring folder = cbScanPath->Text.c_str();

	miQFAdd->Enabled = !WindowsUtility::DirectoryExists(folder);
}


void __fastcall TFrameSelect::miExploreFromScanHistoryClick(TObject *Sender)
{
	if (sgScanHistory->Selection.Top > 0)
	{
		std::wstring path = sgScanHistory->Cells[2][sgScanHistory->Selection.Top].c_str();

		WindowsUtility::ExecuteFile(L"\"" + path + L"\"", L"");
	}
}


void __fastcall TFrameSelect::miShowInFolderHistoryClick(TObject *Sender)
{
	if (sgScanHistory->Selection.Top > 0)
	{
		if (OnChangeFolderHistoryPath)
		{
			std::wstring path = sgScanHistory->Cells[2][sgScanHistory->Selection.Top].c_str();

			OnChangeFolderHistoryPath(path);
		}
	}
}


void __fastcall TFrameSelect::miSaveAsClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kScanHistory]));

	if (!file_name.empty())
	{
		GridUtility::SaveGrid(sgScanHistory, file_name);
	}
}
#pragma end_region


#pragma region Popup_QuickFolder
void __fastcall TFrameSelect::miQFTitleClick(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	cbScanPath->Text = GSettingsHandler->QuickFolders[mi->Tag].c_str();
}


void TFrameSelect::UpdateQuickFolders()
{
	for (int t = 0; t < puQuickFolder->Items->Count; t++)
	{
		puQuickFolder->Items[t].Free();
	}

	for (int t = 0; t < kQuickFolderCount; t++)
	{
		if (GSettingsHandler->QuickFolders[t] != L"")
		{
			TMenuItem *mi = new TMenuItem(this);

			mi->Caption = GSettingsHandler->QuickFolders[t].c_str();
			mi->Tag = t;
			mi->OnClick = miQFTitleClick;

			puQuickFolder->Items->Add(mi);
		}
	}
}
#pragma end_region
