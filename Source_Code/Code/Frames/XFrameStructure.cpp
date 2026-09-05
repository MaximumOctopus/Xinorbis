//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameStructure.h"

#include "XFormChartOptions.h"
#include "XFormGetCopyMove.h"
#include "XFormXinorbisDialog.h"

#include "ChartUtility.h"
#include "ConstantsGui.h"
#include "ConstantsImages.h"
#include "ConstantsReports.h"
#include "Formatting.h"
#include "GridUtility.h"
#include "ImageHandler.h"
#include "LanguageHandler.h"
#include "Log.h"
#include "LoadDialogs.h"
#include "SaveDialogs.h"
#include "SettingsHandler.h"
#include "ScanEngine.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"
#include "XZip.h"

extern ImageHandler *GImageHandler;
extern LanguageHandler *GLanguageHandler;
extern Log *GLog;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;
extern XZip *GXZip;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameStructure *FrameStructure;
//---------------------------------------------------------------------------
__fastcall TFrameStructure::TFrameStructure(TComponent* Owner)
	: TFrame(Owner)
{
	Init();
}
//---------------------------------------------------------------------------


#pragma region Frame_Setup
void TFrameStructure::Init()
{
	NRS = new NavigateRightSide();

	FilterChanged = true;

	// =========================================================================

	miSearchOpen->Caption       = GLanguageHandler->Text[kViewOpenFile].c_str();
	miSearchOpenCustom->Caption = GLanguageHandler->Text[kOpenWithCustomViewer].c_str();
	miExploreDirectory->Caption = GLanguageHandler->Text[kExploreFolder].c_str();
	miSFileProperties->Caption  = GLanguageHandler->Text[kFileProperties].c_str();
	miGenerateMD5->Caption      = GLanguageHandler->Text[kGenerateMD5].c_str();
	miHexEdit->Caption          = GLanguageHandler->Text[kHexEdit].c_str();
	miCopyMenu->Caption         = GLanguageHandler->Text[kCopy].c_str();
	miCopySelected->Caption     = (GLanguageHandler->Text[kSelected] + kEllipsis).c_str();
	miCopyAll->Caption          = (GLanguageHandler->Text[kAll] + kEllipsis).c_str();
	miMoveMenu->Caption         = GLanguageHandler->Text[kMove].c_str();
	miMoveSelected->Caption     = (GLanguageHandler->Text[kSelected] + kEllipsis).c_str();
	miMoveAll->Caption          = (GLanguageHandler->Text[kAll] + kEllipsis).c_str();
	miDeleteMenu->Caption       = GLanguageHandler->Text[kDelete].c_str();
	miDeleteSelected->Caption   = (GLanguageHandler->Text[kSelected] + kEllipsis).c_str();
	miDeleteAll->Caption        = (GLanguageHandler->Text[kAll] + kEllipsis).c_str();
	miZIP->Caption              = (GLanguageHandler->Text[kAddZipFile] + kEllipsis).c_str();
	miSearchExportToCB->Caption = GLanguageHandler->Text[kCopyTableToClipboard].c_str();
	miSaveAs->Caption           = (GLanguageHandler->Text[kSaveAs] + kEllipsis).c_str();

	// =========================================================================

	miPUNO1->Caption    = GLanguageHandler->TypeDescriptions[0].c_str();
	miPUNO2->Caption    = GLanguageHandler->TypeDescriptions[1].c_str();
	miPUNO3->Caption    = GLanguageHandler->TypeDescriptions[2].c_str();
	miPUNO4->Caption    = GLanguageHandler->TypeDescriptions[3].c_str();
	miPUNO5->Caption    = GLanguageHandler->TypeDescriptions[4].c_str();
	miPUNO6->Caption    = GLanguageHandler->TypeDescriptions[5].c_str();
	miPUNO7->Caption    = GLanguageHandler->TypeDescriptions[6].c_str();
	miPUNO8->Caption    = GLanguageHandler->TypeDescriptions[7].c_str();
	miPUNO9->Caption    = GLanguageHandler->TypeDescriptions[8].c_str();
	miNOCustom->Caption = GLanguageHandler->Text[kCustom].c_str();
	miPUNO10->Caption   = GLanguageHandler->TypeDescriptions[9].c_str();
	miPUNO11->Caption   = GLanguageHandler->TypeDescriptions[10].c_str();
	miPUNO12->Caption   = GLanguageHandler->TypeDescriptions[11].c_str();
	miPUNO13->Caption   = GLanguageHandler->TypeDescriptions[12].c_str();
	miPUNO14->Caption   = GLanguageHandler->TypeDescriptions[13].c_str();
	miPUNO15->Caption   = GLanguageHandler->TypeDescriptions[14].c_str();
	miPUNO16->Caption   = GLanguageHandler->TypeDescriptions[15].c_str();
	miPUNO17->Caption   = GLanguageHandler->TypeDescriptions[16].c_str();
	miPUNO18->Caption   = GLanguageHandler->TypeDescriptions[17].c_str();
	miPUNO19->Caption   = GLanguageHandler->TypeDescriptions[18].c_str();

	// =========================================================================

	miChartOptions->Caption = GLanguageHandler->Text[kChartOptions].c_str();
	miCOSave->Caption       = GLanguageHandler->Text[kSaveChart].c_str();
	miCOCopy->Caption       = GLanguageHandler->Text[kCopyChartToClipboard].c_str();
	miCOAdvanced->Caption   = GLanguageHandler->Text[kAdvancedOptions].c_str();

	// =========================================================================

	NavigateFilter[0] = miPUNO1;   NavigateFilter[1] = miPUNO2;   NavigateFilter[2] = miPUNO3;   NavigateFilter[3] = miPUNO4;
	NavigateFilter[4] = miPUNO5;   NavigateFilter[5] = miPUNO6;   NavigateFilter[6] = miPUNO7;   NavigateFilter[7] = miPUNO8;
	NavigateFilter[8] = miPUNO9;   NavigateFilter[9] = miPUNO10;  NavigateFilter[10] = miPUNO11; NavigateFilter[11] = miPUNO12;
	NavigateFilter[12] = miPUNO13; NavigateFilter[13] = miPUNO14; NavigateFilter[14] = miPUNO15; NavigateFilter[15] = miPUNO16;
	NavigateFilter[16] = miPUNO17; NavigateFilter[17] = miPUNO18; NavigateFilter[18] = miPUNO19;

	GImageHandler->SetButtonOffImage(sbNMCreated,     kImageCreated);
	GImageHandler->SetButtonOffImage(sbNMAccessed,    kImageAccessed);
	GImageHandler->SetButtonOffImage(sbNMModified,    kImageModified);
	GImageHandler->SetButtonOffImage(sbNMUsers,       kImageOwner);
	GImageHandler->SetButtonOffImage(sbNMAttributes,  kImageAttributes);
	GImageHandler->SetButtonOffImage(sbNMColourCode,  kImageColourCode);
	GImageHandler->SetButtonOffImage(sbNMSizeOnDisk,  kImageSizeOnDisk);
	GImageHandler->SetButtonOffImage(sbNSBCreated,    kImageCreated);
	GImageHandler->SetButtonOffImage(sbNSBAccessed,   kImageAccessed);
	GImageHandler->SetButtonOffImage(sbNSBModified,   kImageModified);
	GImageHandler->SetButtonOffImage(sbNSBUsers,      kImageOwner);
	GImageHandler->SetButtonOffImage(sbNSBAttributes, kImageAttributes);
	GImageHandler->SetButtonOffImage(sbNSBColourCode, kImageColourCode);
	GImageHandler->SetButtonOffImage(sbNSBSizeOnDisk, kImageSizeOnDisk);

//	sgLeftSide->HideColumns(5, 16);

	for (int t = 0; t < 5; t++)
	{
		sgLeftSide->ColWidths[t] = ColumnWidths[t];
		sgRightSide->ColWidths[t] = ColumnWidths[t];
	}

	for (int t = 5; t < 17; t++)
	{
		sgLeftSide->ColWidths[t] = -1;
		sgRightSide->ColWidths[t] = -1;
	}

	sgLeftSide->DefaultRowHeight  = GSettingsHandler->Appearance.RowHeight;
	sgRightSide->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;

//	sgLeftSide->ClearRows(1, sgLeftSide->RowCount - 1);

	sgLeftSide->Cells[1][0]                = GLanguageHandler->Text[kFileName].c_str();
	sgLeftSide->Cells[2][0]                = GLanguageHandler->Text[kSize].c_str();
	sgLeftSide->Cells[3][0]                = L"%";
	sgLeftSide->Cells[4][0]                = L"%";
	sgLeftSide->Cells[5][0]                = GLanguageHandler->Text[kCreated].c_str();
	sgLeftSide->Cells[6][0]                = GLanguageHandler->Text[kAccessed].c_str();
	sgLeftSide->Cells[7][0]                = GLanguageHandler->Text[kModified].c_str();
	sgLeftSide->Cells[8][0]                = GLanguageHandler->Text[kOwner].c_str();
	sgLeftSide->Cells[ksgnAttributes][0]   = GLanguageHandler->Text[kAttr].c_str();
	sgLeftSide->Cells[ksgnSizeOnDisk][0]   = GLanguageHandler->Text[kUsed].c_str();
	sgLeftSide->Cells[ksgnIntegerPCent][1] = L"0";

	//sgRightSide.ClearRows(1, sgRightSide->RowCount - 1);

	sgRightSide->Cells[1][0]              = GLanguageHandler->Text[kFileName].c_str();
	sgRightSide->Cells[2][0]              = GLanguageHandler->Text[kSize].c_str();
	sgRightSide->Cells[3][0]              = L"%";
	sgRightSide->Cells[4][0]              = L"%";
	sgRightSide->Cells[5][0]              = GLanguageHandler->Text[kCreated].c_str();
	sgRightSide->Cells[6][0]              = GLanguageHandler->Text[kAccessed].c_str();
	sgRightSide->Cells[7][0]              = GLanguageHandler->Text[kModified].c_str();
	sgRightSide->Cells[8][0]              = GLanguageHandler->Text[kOwner].c_str();
	sgRightSide->Cells[ksgnAttributes][0] = GLanguageHandler->Text[kAttr].c_str();
	sgRightSide->Cells[ksgnSizeOnDisk][0] = GLanguageHandler->Text[kUsed].c_str();

	sgRightSide->Cells[ksgnIntegerPCent][1] = L"0";

	Panel25Resize(NULL);
	Panel26Resize(NULL);

	LoadSettings();

	InitHint();

	InitUpdate();
}


void TFrameStructure::DeInit()
{
	delete NRS;
}


void TFrameStructure::InitUpdate()
{
	ChartUtility::SetAdvancedOptions(vtcFS, GSettingsHandler->Chart);
}


void TFrameStructure::InitHint()
{
	sbNMCreated->Hint     = GLanguageHandler->Text[kHint1].c_str();
	sbNSBCreated->Hint    = GLanguageHandler->Text[kHint1].c_str();
	sbNMAccessed->Hint    = GLanguageHandler->Text[kHint2].c_str();
	sbNSBAccessed->Hint   = GLanguageHandler->Text[kHint2].c_str();
	sbNMModified->Hint    = GLanguageHandler->Text[kHint3].c_str();
	sbNSBModified->Hint   = GLanguageHandler->Text[kHint3].c_str();
	sbNMUsers->Hint       = GLanguageHandler->Text[kHint4].c_str();
	sbNSBUsers->Hint      = GLanguageHandler->Text[kHint4].c_str();
	sbNMAttributes->Hint  = GLanguageHandler->Text[kHint5].c_str();
	sbNSBAttributes->Hint = GLanguageHandler->Text[kHint5].c_str();
	sbNMSizeOnDisk->Hint  = GLanguageHandler->Text[kHint6].c_str();
	sbNSBSizeOnDisk->Hint = GLanguageHandler->Text[kHint6].c_str();
	sbNMColourCode->Hint  = GLanguageHandler->Text[kHint7].c_str();
	sbNSBColourCode->Hint = GLanguageHandler->Text[kHint7].c_str();
}


void TFrameStructure::UpdateGUICustomNames()
{
	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		NavigateFilter[t]->Caption = GLanguageHandler->TypeDescriptions[t].c_str();
	}
}
#pragma end_region


#pragma region Public_Stuff
void TFrameStructure::SelectAndDblClick(int row, int col)
{
	sgLeftSide->Row = row;

	sgLeftSideDblClick(NULL);
}
#pragma end_region


#pragma region Settings
void TFrameStructure::LoadSettings()
{
	if (GSettingsHandler->OpenSettings(true))
	{
		Panel25->Width = GSettingsHandler->ReadInteger(L"Prefs", L"StructureLeft_" + std::to_wstring(DataSource), 325, 325);
		sgRightSide->Height = GSettingsHandler->ReadInteger(L"Prefs", L"StructureRight", std::round(pMainNavigation->Height * 0.75), 10);

		// =====================================================================

		int chart_type = GSettingsHandler->ReadInteger(L"Charts", L"StructureReport_" + std::to_wstring(DataSource) + L"_1", 0, -1);

		ChartUtility::SetChartTo(vtcFS, chart_type);

		GSettingsHandler->CloseSettings();
	}
	else
	{
		GLog->AddError(L"Error loading settings FrameNavigation");
	}
}


void TFrameStructure::SaveSettings()
{
	if (GSettingsHandler->OpenSettings(false))
	{
		GSettingsHandler->WriteInteger(L"Prefs", L"StructureLeft_" + std::to_wstring(DataSource), Panel25->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"StructureRight", sgRightSide->Height);

		// =====================================================================

		GSettingsHandler->WriteInteger(L"Charts", L"StructureReport_" + std::to_wstring(DataSource) + L"_1", ChartUtility::GetChartTypeInt(vtcFS));

		GSettingsHandler->CloseSettings();
	}
	else
	{
		GLog->AddError(L"Error saving settings FrameNavigation");
	}
}
#pragma end_region


#pragma region Generic_Code
std::wstring TFrameStructure::GetSelectedFileName(int side)
{
	switch (side)
	{
	case 4:
	{
		std::wstring folder = sgLeftSide->Cells[ksgnFileName][sgLeftSide->Selection.Top].c_str();

		if (sgLeftSide->Cells[ksgnFolderFile][sgLeftSide->Selection.Top] == L"1")
		{
			return GScanEngine->Data[DataSource].Path.String + folder + L"\\";
		}
		else
		{
			return GScanEngine->Data[DataSource].Path.String + folder;
		}
		break;
	}
	case 5:
	{
		std::wstring folder = sgRightSide->Cells[ksgnFileName][sgRightSide->Selection.Top].c_str();

		if (sgRightSide->Cells[ksgnFolderFile][sgRightSide->Selection.Top] == L"1")
		{
			return CurrentFolder + folder + L"\\";
		}
		else
		{
			return CurrentFolder + folder;
		}
		break;
	}
	}

    return L"";
}


void __fastcall TFrameStructure::Splitter2Moved(TObject *Sender)
{
	int totall = sgLeftSide->ColWidths[0];
	int totalr = sgRightSide->ColWidths[0];

	for (int t = 2; t < 17; t++)
	{
		if (sgLeftSide->ColWidths[t] != -1)
		{
			totall += sgLeftSide->ColWidths[t];
		}

		if (sgRightSide->ColWidths[t] != -1)
		{
			totalr += sgRightSide->ColWidths[t];
		}
	}

	sgLeftSide->ColWidths[1] = sgLeftSide->Width - (totall + __WidthOfScrollbar);
    sgRightSide->ColWidths[1] = sgRightSide->Width - (totalr + __WidthOfScrollbar);
}
#pragma end_region


#pragma region Left_Side_Toolbar
void __fastcall TFrameStructure::sgLeftSideDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	if (ARow > 0)
	{
		sgLeftSide->Canvas->Font->Style = TFontStyles();

		if (State.Contains(gdSelected))
		{
			sgLeftSide->Canvas->Brush->Color = TColor(kGridColourSelected);
		}
		else
		{
			if (sbNMColourCode->Tag == 1)
			{
				sgLeftSide->Canvas->Brush->Color = TColor(0xff4400);
			}
			else
			{
				if (ARow % 2)
				{
					sgLeftSide->Canvas->Brush->Color = TColor(kGridColourOff);
				}
				else
				{
					sgLeftSide->Canvas->Brush->Color = TColor(kGridColourOn);
                }
			}
		}

		sgLeftSide->Canvas->FillRect(Rect);

		switch (ACol)
		{
		case ksgnIsFolder:
			if (ARow != 0)
			{
				if (sgLeftSide->Cells[ksgnFolderFile][ARow] == L"1")
				{
					XFNImages->Draw(sgLeftSide->Canvas, Rect.Left + 1, Rect.Top, 0, true);
				}
			}
			break;
		case ksgnGraphSize:
			sgLeftSide->Canvas->Brush->Color = TColor(GSettingsHandler->Appearance.BarColours[0]);
			sgLeftSide->Canvas->Rectangle(Rect);

			if (sgLeftSide->Cells[ksgnIntegerPCent][ARow] != L"0" && sgLeftSide->Cells[ksgnIntegerPCent][ARow] != L"")
			{
				sgLeftSide->Canvas->Brush->Color = TColor(GSettingsHandler->Appearance.BarColours[1]);
				sgLeftSide->Canvas->FillRect(TRect(Rect.Left + 1,
												   Rect.Top + 1,
												   Rect.Left + sgLeftSide->Cells[ksgnIntegerPCent][ARow].ToInt(),
												   Rect.Bottom - 1));
			}
			break;
		default:
			if (sgLeftSide->ColWidths[0] != -1)
			{
				sgLeftSide->Canvas->Brush->Style = bsClear;
				sgLeftSide->Canvas->Font->Color = clWhite;
				sgLeftSide->Canvas->TextOut(Rect.Left, Rect.Top, sgLeftSide->Cells[ACol][ARow]);
			}
			break;
		}
	}
	else
	{
		sgLeftSide->Canvas->Brush->Color = TColor(kGridHeader);
		sgLeftSide->Canvas->FillRect(Rect);

		sgLeftSide->Canvas->Brush->Style = bsClear;
		sgLeftSide->Canvas->Font->Color = clWhite;
		sgLeftSide->Canvas->Font->Style = TFontStyles() << fsBold;
		sgLeftSide->Canvas->TextOut(Rect.Left, Rect.Top, sgLeftSide->Cells[ACol][0]);
	}
}


void __fastcall TFrameStructure::sbNMCreatedClick(TObject *Sender)
{
	TSpeedButton *button = (TSpeedButton*)Sender;

	int tag = button->Tag;

	int column = TableColumnLookup[(button->Tag * 2) + 1];

	if (tag >= 16 && tag <= 21)
	{
		GridUtility::ToggleColumn(sgLeftSide, button,
								  column,
								  ColumnWidths[column],
								  TableColumnLookup[button->Tag * 2]);

		Panel25Resize(NULL);
	}
	else if (tag >= 22 && tag <= 27)
	{
		GridUtility::ToggleColumn(sgRightSide, button,
								  column,
                                  ColumnWidths[column],
								  TableColumnLookup[button->Tag * 2]);

		Panel26Resize(NULL);
	}
}


void __fastcall TFrameStructure::sbNMColourCodeClick(TObject *Sender)
{
	TSpeedButton *button = (TSpeedButton*)Sender;

	if (sbNMColourCode->Tag == 0)
	{
		GImageHandler->SetButtonOnImage(button, kImageColourCode);

		sbNMColourCode->Tag = 1;

		sgLeftSide->Font->Color = clBlack;
	}
	else
	{
		GImageHandler->SetButtonOffImage(button, kImageColourCode);

		sbNMColourCode->Tag = 0;

		sgLeftSide->Font->Color = clWhite;
	}

	sgLeftSide->Invalidate();
}


void __fastcall TFrameStructure::sbNLFilterClick(TObject *Sender)
{
	TSpeedButton *button = (TSpeedButton*)Sender;

	puNavigateOptions->Tag = button->Tag;

	for (int t = 0; t < 19; t++)
	{
		if (GSettingsHandler->Navigation.Display[puNavigateOptions->Tag][t] == L'1')
		{
			NavigateFilter[t]->Checked = true;
		}
		else
		{
			NavigateFilter[t]->Checked = false;
		}
	}

	TPoint mouse_pos = Mouse->CursorPos;

	switch (puNavigateOptions->Tag)
	{
	case kLeftOptions:
		puNavigateOptions->Popup(mouse_pos.X, mouse_pos.Y);
		break;
	case kRightOptions:
		puNavigateOptions->Popup(mouse_pos.X, mouse_pos.Y);
		break;
	}
}
#pragma end_region


#pragma region Left_Side
void __fastcall TFrameStructure::sgLeftSideDblClick(TObject *Sender)
{
	if (sgLeftSide->Cells[ksgnFolderFile][sgLeftSide->Selection.Top] == L"1")
	{
		GScanEngine->FolderStructure.clear();

		sbNavigationBack->Enabled = true;

		// =====================================================================

		Screen->Cursor = crHourGlass;

		std::wstring left = sgLeftSide->Cells[1][sgLeftSide->Selection.Top].c_str();

		std::wstring is = sgLeftSide->Cells[ksgnIntegerSize][sgLeftSide->Selection.Top].c_str();

		std::wstring s = GScanEngine->Data[DataSource].Path.String + left + L"\\";

		ShowMessage(is.c_str());

		unsigned __int64 i = std::stoull(is);

		CurrentFolder = s;

		lNavigationDetails->Caption = (L"\"" + s + L"\", " + Convert::ConvertToUsefulUnit(i) + L". ").c_str();

		// =====================================================================

		int xflID = -1;

		for (int t = 0; t < GScanEngine->Data[DataSource].Folders.size(); t++)
		{
			if (GScanEngine->Data[DataSource].Folders[t] == s)
			{
				xflID = t;

				break;
			}
		}

		// =====================================================================

		UpdateRightSide(xflID, i);

		// =====================================================================
	}
}


void __fastcall TFrameStructure::Panel25Resize(TObject *Sender)
{
	int total = sgLeftSide->ColWidths[0];

	for (int t = 2; t < 18; t++)
	{
		if (sgLeftSide->ColWidths[t] != -1)
		{
			total += sgLeftSide->ColWidths[t];
		}
	}

	sgLeftSide->ColWidths[1] = sgLeftSide->Width - (total + __WidthOfScrollbar);
}


void TFrameStructure::BuildNavigationTab()
{
	int orderx = 0;

	vtcFS->SeriesList->Items[0]->Clear();

	GridUtility::Clear(sgLeftSide, false);

	sgLeftSide->BeginUpdate();

	for (FileObject *file : GScanEngine->Data[DataSource].RootFiles)
	{
		int row = sgLeftSide->RowCount - 1;

		if ((faDirectory & file->Attributes) || GSettingsHandler->Navigation.Display[0][file->Category] == L'1')
		{
			if (faDirectory & file->Attributes)
			{
				SizeOfFolder bigtemp = GScanEngine->SizeOfFolderNav(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name, GSettingsHandler->Navigation.Display[0]);

				sgLeftSide->Cells[1][row]                    = file->Name.c_str();
				sgLeftSide->Cells[2][row]                    = Convert::ConvertToUsefulUnit(bigtemp.Size).c_str();
				sgLeftSide->Cells[ksgnIntegerSize][row]      = bigtemp.Size;

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					sgLeftSide->Cells[4][row]                = Convert::DoubleToPercent((double)bigtemp.Size / (double)GScanEngine->Data[DataSource].TotalSize).c_str();
					sgLeftSide->Cells[ksgnIntegerPCent][row] = (int)std::round(((double)bigtemp.Size / (double)GScanEngine->Data[DataSource].TotalSize) * 50);
				}
				else
				{
					sgLeftSide->Cells[4][row]                = L"100%";
					sgLeftSide->Cells[ksgnIntegerPCent][row] = L"100";
				}

				sgLeftSide->Cells[ksgnAttributes][row]       = Formatting::GetAttributeAsString(file->Attributes).c_str();

				sgLeftSide->Cells[ksgnCreatedDate][row]      = Convert::IntDateToString(file->DateCreated).c_str();
				sgLeftSide->Cells[ksgnAccessedDate][row]     = Convert::IntDateToString(file->DateAccessed).c_str();
				sgLeftSide->Cells[ksgnModifiedDate][row]     = Convert::IntDateToString(file->DateModified).c_str();

				sgLeftSide->Cells[ksgnUserName][row]         = GScanEngine->Data[DataSource].Users[file->Owner]->Name.c_str();

				sgLeftSide->Cells[ksgnSizeOnDisk][row]       = Convert::ConvertToUsefulUnit(bigtemp.SizeOnDisk).c_str();
				sgLeftSide->Cells[ksgnIntegetSoD][row]       = bigtemp.SizeOnDisk;

				sgLeftSide->Cells[ksgnFolderFile][row]       = L"1";
				sgLeftSide->Cells[ksgnOrderIndex][row]       = orderx;

				sgLeftSide->Cells[ksgnCategoryIndex][row]    = L"0";
			}
			else
			{
				sgLeftSide->Cells[1][row]                    = file->Name.c_str();
				sgLeftSide->Cells[2][row]                    = Convert::ConvertToUsefulUnit(file->Size).c_str();
				sgLeftSide->Cells[ksgnIntegerSize][row]      = file->Size;

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					sgLeftSide->Cells[4][row]                = Convert::DoubleToPercent((double)file->Size / (double)GScanEngine->Data[DataSource].TotalSize).c_str();
					sgLeftSide->Cells[ksgnIntegerPCent][row] = (int)std::round(((double)file->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 50);
				}
				else
				{
					sgLeftSide->Cells[4][row]                = L"100%";
					sgLeftSide->Cells[ksgnIntegerPCent][row] = L"100";
				}

				sgLeftSide->Cells[ksgnAttributes][row]       = Formatting::GetAttributeAsString(file->Attributes).c_str();

				sgLeftSide->Cells[ksgnCreatedDate][row]      = Convert::IntDateToString(file->DateCreated).c_str();
				sgLeftSide->Cells[ksgnAccessedDate][row]     = Convert::IntDateToString(file->DateAccessed).c_str();
				sgLeftSide->Cells[ksgnModifiedDate][row]     = Convert::IntDateToString(file->DateModified).c_str();

				sgLeftSide->Cells[ksgnUserName][row]         = GScanEngine->Data[DataSource].Users[file->Owner]->Name.c_str();

//				sgLeftSide->Cells[ksgnSizeOnDisk][row]       = Convert::ConvertToUsefulUnit(Convert::GetSizeOnDisk(file->Size));
//				sgLeftSide->Cells[ksgnIntegetSoD][row]       = Convert::GetSizeOnDisk(file->Size)); TO DO

				sgLeftSide->Cells[ksgnFolderFile][row]       = L"0";
				sgLeftSide->Cells[ksgnOrderIndex][row]       = orderx + 50000;

				sgLeftSide->Cells[ksgnCategoryIndex][row]    = file->Category;
			}

			orderx++;

			sgLeftSide->RowCount++;
		}
	}

	if (sgLeftSide->RowCount > 2)
	{
		sgLeftSide->RowCount--;
	}

	sgLeftSide->EndUpdate();

// TO DO	TGridUtility.DoTableSort(sgNavigation, sgLeftSide->SortSettings.Column, NavigationSortColumns[sgLeftSide->SortSettings.Column]);
}
#pragma end_region


#pragma region Right_Side_Toolbar
void __fastcall TFrameStructure::sgRightSideDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	if (ARow > 0)
	{
		sgRightSide->Canvas->Font->Style = TFontStyles();

		if (State.Contains(gdSelected))
		{
			sgRightSide->Canvas->Brush->Color = TColor(kGridColourSelected);
		}
		else
		{
			if (sbNSBColourCode->Tag == 1)
			{
				sgRightSide->Canvas->Brush->Color = TColor(0xffff00);
			}
			else
			{
				if (ARow % 2)
				{
					sgRightSide->Canvas->Brush->Color = TColor(kGridColourOff);
				}
				else
				{
					sgRightSide->Canvas->Brush->Color = TColor(kGridColourOn);
				}
			}
		}

		sgRightSide->Canvas->FillRect(Rect);

		switch (ACol)
		{
		case ksgnIsFolder:
			if (ARow != 0)
			{
				if (sgRightSide->Cells[ksgnFolderFile][ARow] == L"1")
				{
					XFNImages->Draw(sgRightSide->Canvas, Rect.Left + 1, Rect.Top, 0, true);
				}
			}
			break;
		case ksgnGraphSize:
			sgRightSide->Canvas->Brush->Color = TColor(GSettingsHandler->Appearance.BarColours[0]);
			sgRightSide->Canvas->Rectangle(Rect);

			if (sgRightSide->Cells[ksgnIntegerPCent][ARow] != L"0" && sgRightSide->Cells[ksgnIntegerPCent][ARow] != L"")
			{
				sgRightSide->Canvas->Brush->Color = TColor(GSettingsHandler->Appearance.BarColours[1]);
				sgRightSide->Canvas->FillRect(TRect(Rect.Left + 1,
												   Rect.Top + 1,
												   Rect.Left + sgRightSide->Cells[ksgnIntegerPCent][ARow].ToInt(),
												   Rect.Bottom - 1));
			}
			break;
		default:
			if (sgRightSide->ColWidths[0] != -1)
			{
				sgRightSide->Canvas->Brush->Style = bsClear;
				sgRightSide->Canvas->Font->Color = clWhite;
				sgRightSide->Canvas->TextOut(Rect.Left, Rect.Top, sgRightSide->Cells[ACol][ARow]);
			}
			break;
		}
	}
	else
	{
		sgRightSide->Canvas->Brush->Color = TColor(kGridHeader);
		sgRightSide->Canvas->FillRect(Rect);

		sgRightSide->Canvas->Brush->Style = bsClear;
		sgRightSide->Canvas->Font->Color = clWhite;
		sgRightSide->Canvas->Font->Style = TFontStyles() << fsBold;
		sgRightSide->Canvas->TextOut(Rect.Left, Rect.Top, sgRightSide->Cells[ACol][0]);
	}
}


void __fastcall TFrameStructure::sbNavigationBackClick(TObject *Sender)
{
	if (GScanEngine->FolderStructure.size() > 1)
	{
		std::wstring s = GScanEngine->FolderStructure[GScanEngine->FolderStructure.size() - 2];

		auto idx = s.find(L'?');

		GScanEngine->FolderStructure.pop_back();
		GScanEngine->FolderStructure.pop_back();

		// =========================================================================

		Screen->Cursor = crHourGlass;

		CurrentFolder = s.substr(0, idx - 1);

		lNavigationDetails->Caption = (L"\"" + CurrentFolder + L"\", " + Convert::ConvertToUsefulUnit(stoi(s.substr(idx + 1))) + L". ").c_str();

		sgRightSide->BeginUpdate();

		// =========================================================================

		int xflID = -1;

		for (int t = 0; t < GScanEngine->Data[DataSource].Folders.size(); t++)
		{
			if (GScanEngine->Data[DataSource].Folders[t] == CurrentFolder)
			{
				xflID = t;

				break;
			}
		}

		// =========================================================================

		if (xflID != -1)
		{
			unsigned __int64 i = stoi(s.substr(idx + 1));

			UpdateRightSide(xflID, i);
		}

		// =========================================================================

		if (GScanEngine->FolderStructure.size() <= 1)
		{
			sbNavigationBack->Enabled = false;
		}
	}
}


void __fastcall TFrameStructure::sbNSBColourCodeClick(TObject *Sender)
{
	TSpeedButton *button = (TSpeedButton*)Sender;

	if (sbNSBColourCode->Tag == 0)
	{
		GImageHandler->SetButtonOnImage(button, kImageColourCode);

		sbNSBColourCode->Tag = 1;

		sgRightSide->Font->Color = clBlack;
	}
	else
	{
		GImageHandler->SetButtonOffImage(button, kImageColourCode);

		sbNSBColourCode->Tag = 0;

		sgRightSide->Font->Color = clWhite;
	}

	sgRightSide->Invalidate();
}


void __fastcall TFrameStructure::Panel26Resize(TObject *Sender)
{
	int total = sgRightSide->ColWidths[0];

	for (int t = 2; t < 18; t++)
	{
		if (sgRightSide->ColWidths[t] != -1)
		{
			total += sgRightSide->ColWidths[t];
		}
	}

	sgRightSide->ColWidths[1] = sgRightSide->Width - (total + __WidthOfScrollbar);
}
#pragma end_region


#pragma region Right_Side_Grid
void __fastcall TFrameStructure::sgRightSideDblClick(TObject *Sender)
{
	if (sgRightSide->Cells[ksgnFolderFile][sgRightSide->Selection.Top] == L"1")
	{
		sbNavigationBack->Enabled = true;

		// =====================================================================

//		if Assigned(NavSideBarThread) then
//		{
//			NavSideBarThread.Terminate;
//			NavSideBarThread.WaitFor;
//			FreeAndNil(NavSideBarThread);
//		}

		std::wstring is = sgRightSide->Cells[ksgnIntegerSize][sgRightSide->Selection.Top].c_str();

        std::wstring right = sgRightSide->Cells[1][sgRightSide->Selection.Top].c_str();

		std::wstring s = GScanEngine->CurrentNavigationSideLocation + right + L"\\";
		unsigned __int64 i = stoi(is);

		CurrentFolder = s;

		lNavigationDetails->Caption = (L"\"" + s + L"\", " + Convert::ConvertToUsefulUnit(i) + L". ").c_str();

		// =====================================================================

		int xflID = -1;

		for (int t = 0; t < GScanEngine->Data[DataSource].Folders.size(); t++)
		{
			if (GScanEngine->Data[DataSource].Folders[t] == s)
			{
				xflID = t;

				break;
			}
		}

		// =====================================================================

		UpdateRightSide(xflID, i);

		// =========================================================================
	}
}


void TFrameStructure::UpdateRightSide(int folder_id, unsigned __int64 folder_size)
{
	Screen->Cursor = crHourGlass;

	sgRightSide->BeginUpdate();

	NRS->SetData(sgRightSide, DataSource, folder_id, folder_size, FilterChanged);

	NRS->Execute();

	BuildRightSide();

	sgRightSide->EndUpdate();

	Screen->Cursor = crDefault;
}


void TFrameStructure::BuildRightSide()
{
	vtcFS->Title->Text->Text = CurrentFolder.c_str();
	vtcFS->Series[0]->Clear();

	if (GScanEngine->Data[DataSource].TotalSize != 0)
	{
		vtcFS->SeriesList->Items[0]->Add(std::round((NRS->FileSize / GScanEngine->Data[DataSource].TotalSize) * 100), GLanguageHandler->Text[kSelectedFolder].c_str(), TColor(kMagnitudeColour[0]));
		vtcFS->SeriesList->Items[0]->Add(std::round(((GScanEngine->Data[DataSource].TotalSize - NRS->FileSize) / GScanEngine->Data[DataSource].TotalSize) * 100), L"Rest of scan", TColor(0x00FFFFFF));
	}
	else
	{
		vtcFS->SeriesList->Items[0]->Add(100, GLanguageHandler->Text[kSelectedFolder].c_str(), TColor(kMagnitudeColour[0]));
		vtcFS->SeriesList->Items[0]->Add(100, L"Rest of scan", TColor(0xFFFFFF));
	}

	// ===========================================================================

	if (sgRightSide->RowCount > 2)
	{
		sgRightSide->RowCount = sgRightSide->RowCount - 1;
	}

//	TGridUtility.DoTableSort(sgNavigationSide, sgNavigationSide.SortSettings.Column, NavigationSortColumns[sgNavigationSide.SortSettings.Column]);

	lNavigationDetails->Caption += (L" " + std::to_wstring(NRS->FileCount) + L" " +
									GLanguageHandler->Text[kFiles] +
									L";" + std::to_wstring(NRS->FolderCount) + L" " +
									GLanguageHandler->Text[kFolders] + L".").c_str();

	FilterChanged = false;
}
#pragma end_region


#pragma region Popup_Chart
void __fastcall TFrameStructure::miCOSaveClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::ExecuteImages(Utility::GetDefaultFileName(L".png", GLanguageHandler->Text[kTable] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		ChartUtility::SaveChartToPNG(vtcFS, file_name);
	}
}


void __fastcall TFrameStructure::miCOCopyClick(TObject *Sender)
{
	ChartUtility::CopyChartToClipboard(vtcFS);
}


void __fastcall TFrameStructure::miCOAdvancedClick(TObject *Sender)
{
	ChartOptions ceo = GSettingsHandler->Chart;

	ceo.Type = ChartUtility::GetChartType(vtcFS);

	// =========================================================================

	ceo = ShowChartOptions(ceo);

	// =========================================================================

	if (ceo.Result == 1)
	{
		ChartUtility::SetAdvancedOptions(vtcFS, ceo);

		if (OnChartsHaveChanged)
		{
			OnChartsHaveChanged();
		}
	}
}
#pragma end_region


#pragma region Popup_NavigateOptions
void __fastcall TFrameStructure::miPUNO1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	mi->Checked = !mi->Checked;

	if (mi->Checked)
	{
		GSettingsHandler->Navigation.Display[puNavigateOptions->Tag][mi->Tag] = L'1';
	}
	else
	{
		GSettingsHandler->Navigation.Display[puNavigateOptions->Tag][mi->Tag] = L'0';
	}

	if (GScanEngine->Data[DataSource].FileCount + GScanEngine->Data[DataSource].FolderCount > 0)
	{
		if (puNavigateOptions->Tag == 0)
		{
			BuildNavigationTab();
		}
		else
		{
			FilterChanged = true;

			sgLeftSideDblClick(NULL);
		}
	}
}
#pragma end_region


#pragma region Popup_Search
void __fastcall TFrameStructure::puSearchPopup(TObject *Sender)
{
	bool status = false;
	bool folder = false;

	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

	if (sg->Selection.Top > 0)
	{
		std::wstring file_name = sg->Cells[1][sg->Selection.Top].c_str();

		if (!file_name.empty())
		{
			status = true;

			folder = sg->Cells[ksgnFolderFile][sg->Selection.Top] == L"1";
		}
	}

	miSearchOpen->Enabled       = status;
	miSearchOpenCustom->Enabled = status;
	miExploreDirectory->Enabled = status;
	miSFileProperties->Enabled  = status;
	miGenerateMD5->Enabled      = status && !folder;
	miHexEdit->Enabled          = status && !folder;
	miCopyMenu->Enabled         = status;
	miMoveMenu->Enabled         = status;
	miDeleteMenu->Enabled       = status;
	miZIP->Enabled              = status;
	miSearchExportToCB->Enabled = status;
	miSaveAs->Enabled           = status;
}


void __fastcall TFrameStructure::miSearchOpenClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

	std::wstring s = GetSelectedFileName(sg->Tag);

	if (!s.empty())
	{
		WindowsUtility::ExecuteFile(L"\"" + s + L"\"", L"");
	}
}


void __fastcall TFrameStructure::miSearchOpenCustomClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

	std::wstring s = GetSelectedFileName(sg->Tag);

	if (!s.empty())
	{
		WindowsUtility::ExecuteFile(L"\"" + GSettingsHandler->General.CustomViewer + L"\"", L"\"" + s + L"\"");
	}
}


void __fastcall TFrameStructure::miExploreDirectoryClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

	std::wstring path = ExtractFilePath(GetSelectedFileName(sg->Tag).c_str()).c_str();

	std::wstring s = L"\"" + path + L"\"";

	if (!s.empty())
	{
		WindowsUtility::ExecuteFile(s, L"");
	}
}


void __fastcall TFrameStructure::miSFilePropertiesClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

	std::wstring s = GetSelectedFileName(sg->Tag);

	if (!s.empty())
	{
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, L"\"" + s + L"\"");
	}
}


void __fastcall TFrameStructure::miGenerateMD5Click(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

	std::wstring s = GetSelectedFileName(sg->Tag);

	if (!s.empty())
	{
// TO DO		ShowMD5Checksum(s, TMD5.Generate(s));
	}
}


void __fastcall TFrameStructure::miHexEditClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

	std::wstring s = GetSelectedFileName(sg->Tag);

	if (!s.empty())
	{
		WindowsUtility::ExecuteFile(L"\"" + GSystemGlobal->ExePath + L"\\Be.HexEditor.exe\"", L"\"" + s + L"\"");
	}
}


void __fastcall TFrameStructure::miCopySelectedClick(TObject *Sender)
{
	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kCopyTo] + kEllipsis);

	if (!folder.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

		switch (sg->Tag)
		{
		case 4:
		{
			std::wstring ls = sgLeftSide->Cells[kLeftFileName][sgLeftSide->Selection.Top].c_str();

			CopyFile(GetSelectedFileName(4).c_str(),
					 (folder + ls).c_str(),
					 false);
			break;
		}
		case 5:
		{
			std::wstring rs = sgRightSide->Cells[kRightFileName][sgRightSide->Selection.Top].c_str();

			CopyFile(GetSelectedFileName(5).c_str(),
					 (folder + rs).c_str(),
					 false);
			break;
		}
		}
	}
}


void __fastcall TFrameStructure::miCopyAllClick(TObject *Sender)
{
	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kCopyTo] + kEllipsis);

	if (!folder.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

		switch (sg->Tag)
		{
		case 4:
			WindowsUtility::CopyAllFiles(GScanEngine->Data[DataSource].Path.String, folder);
			break;
		case 5:
			WindowsUtility::CopyAllFiles(CurrentFolder, folder);
			break;
		}
	}
}


void __fastcall TFrameStructure::miMoveSelectedClick(TObject *Sender)
{
	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kMoveTo] + kEllipsis);

	if (!folder.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

		switch (sg->Tag)
		{
		case 4:
		{
			std::wstring ls = sgLeftSide->Cells[kLeftFileName][sgLeftSide->Selection.Top].c_str();

			MoveFileEx(GetSelectedFileName(4).c_str(),
					   (folder + ls).c_str(),
					   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
        }
		case 5:
		{
			std::wstring rs = sgRightSide->Cells[kRightFileName][sgRightSide->Selection.Top].c_str();

			MoveFileEx(GetSelectedFileName(5).c_str(),
					   (folder + rs).c_str(),
					   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		}
		}
	}
}


void __fastcall TFrameStructure::miMoveAllClick(TObject *Sender)
{
	std::wstring folder = GetCopyMoveFolder(GLanguageHandler->Text[kMoveTo] + kEllipsis);

	if (!folder.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

		switch (sg->Tag)
		{
		case 4:
			WindowsUtility::MoveAllFiles(GScanEngine->Data[DataSource].Path.String, folder);
			break;
		case 5:
			WindowsUtility::MoveAllFiles(CurrentFolder, folder);
			break;
		}
	}
}


void __fastcall TFrameStructure::miDeleteSelectedClick(TObject *Sender)
{
	if (MessageDlg(GLanguageHandler->Text[kDialog3].c_str(), mtWarning, mbYesNo, 0) == mrYes)
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

		std::wstring s = GetSelectedFileName(sg->Tag);

		if (!s.empty())
		{
			WindowsUtility::SendToRecycleBin(s);
		}
	}
}


void __fastcall TFrameStructure::miDeleteAllClick(TObject *Sender)
{
	if (MessageDlg(GLanguageHandler->Text[kDialog4].c_str(), mtWarning, mbYesNo, 0) == mrYes)
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

		switch (sg->Tag)
		{
		case 4:
			for (int t = 1; t < sgLeftSide->RowCount; t++)
			{
				WindowsUtility::SendToRecycleBin(GetSelectedFileName(sg->Tag));
			}
			break;
		case 5:
			for (int t = 1; t < sgRightSide->RowCount; t++)
			{
				WindowsUtility::SendToRecycleBin(GetSelectedFileName(sg->Tag));
			}
			break;
		}
	}
}


void __fastcall TFrameStructure::miZIPClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
												  L".zip",
                                                  L"",
												  Utility::GetDefaultFileName(L".zip", GLanguageHandler->Text[kTop101] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

		int count = -1;

		std::vector<std::wstring> data;

		for (int t = 1; t < sg->RowCount; t++)
		{
			data.push_back(sg->Cells[0][t].c_str());
		}

		if (data.size() != 0)
		{
			count = GXZip->Files(file_name, data, L"Zipping...");
		}

		if (count == -1)
		{
			ShowXDialog(GLanguageHandler->Text[kErrorCompressingFiles],
						GLanguageHandler->Text[kErrorCompressingFiles],
						XDialogTypeWarning);
		}
		else if (count == 0)
		{
			ShowXDialog(GLanguageHandler->Text[kWarning],
						GLanguageHandler->Text[kNoFilesToCompress],
						XDialogTypeWarning);
		}
	}
}


void __fastcall TFrameStructure::miSearchExportToCBClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

	switch (sg->Tag)
	{
	case 4:
		GridUtility::CopyGridToClipboard(sgLeftSide, 0);
		break;
	case 5:
		GridUtility::CopyGridToClipboard(sgRightSide, 0);
		break;
	}
}


void __fastcall TFrameStructure::miSaveAsClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(L".csv",
														 GLanguageHandler->Text[kSearchResults]));

	if (!file_name.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

		GridUtility::SaveGrid(sg, file_name);
	}
}
#pragma end_region

