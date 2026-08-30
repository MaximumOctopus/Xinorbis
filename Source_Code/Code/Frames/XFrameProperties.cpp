//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>


#include "XFrameProperties.h"

#include "XFormChartOptions.h"
#include "XFormGetCopyMove.h"
#include "XFormMoreDetail.h"
#include "XFormShowMD5.h"
#include "XFormXinorbisDialog.h"

#include "ChartUtility.h"
#include "ConstantsGui.h"
#include "Convert.h"
#include "FileExtensionHandler.h"
#include "Formatting.h"
#include "GridUtility.h"
#include "ImageHandler.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "MD5.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "TreeUtility.h"
#include "Utility.h"
#include "WindowsUtility.h"
#include "XZip.h"

#include "ReportCSV.h"

#include "TabUiDates.h"
#include "TabUiFolders.h"
#include "TabUiHistory.h"
#include "TabUiLength.h"
#include "TabUiMagnitude.h"
#include "TabUiNull.h"
#include "TabUiTop101.h"
#include "TabUiTypes.h"
#include "TabUiUsers.h"

extern FileExtensionHandler *GFileExtensionHandler;
extern ImageHandler *GImageHandler;
extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;
extern XZip *GXZip;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameProperties *FrameProperties;
//---------------------------------------------------------------------------
__fastcall TFrameProperties::TFrameProperties(TComponent* Owner)
	: TFrame(Owner)
{
	Init();
	InitMenus();
}
//---------------------------------------------------------------------------


#pragma region Application_Control
void TFrameProperties::Init()
{
	// tab titles
	tsCategories->Caption = GLanguageHandler->Text[kCategories].c_str();
	tsTypes->Caption      = GLanguageHandler->Text[kType].c_str();
	tsExtensions->Caption = GLanguageHandler->Text[kExtensions].c_str();
	tsFolders->Caption    = GLanguageHandler->Text[kFolders].c_str();
	tsMagnitude->Caption  = GLanguageHandler->Text[kMagnitude].c_str();
	tsDates->Caption      = GLanguageHandler->Text[kDates].c_str();
	tsHistory->Caption    = GLanguageHandler->Text[kHistory].c_str();
	tsTop101->Caption     = GLanguageHandler->Text[kTop101].c_str();
	tsNull->Caption       = GLanguageHandler->Text[kNull].c_str();
	tsUsers->Caption      = GLanguageHandler->Text[kUsers].c_str();
	tsTemporary->Caption  = GLanguageHandler->Text[kTemp].c_str();
	tsLength->Caption     = GLanguageHandler->Text[kLength].c_str();

	Charts[0] = vtcCategories; Charts[1] = vtcTypes;   Charts[2] = vtcFolders;
	Charts[3] = vtcMagnitude;  Charts[4] = vtcDates;   Charts[5] = vtcTemporary;
	Charts[6] = vtcUsers;      Charts[7] = vtcHistory; Charts[8] = vtcLengths;

	GImageHandler->SetPieBarImages(sbCategoriesPie, sbCategoriesBar);
	GImageHandler->SetPieBarImages(sbTypesPie, sbTypesBar);
	GImageHandler->SetPieBarImages(sbFoldersPie, sbFoldersBar);
	GImageHandler->SetPieBarImages(sbMagnitudePie, sbMagnitudeBar);
	GImageHandler->SetPieBarImages(sbDatesPie, sbDatesBar);
	GImageHandler->SetPieBarImages(sbUsersPie, sbUsersBar);
	GImageHandler->SetPieBarImages(sbLengthsPie, sbLengthsBar);

	// tabs
	InitCategoriesTab();
	InitTypesTab();
	InitExtensionsTab();
	InitFoldersTab();
	InitMagnitudeTab();
	InitDatesTab();
	InitHistoryTab();
	InitTop101Tab();
	InitNullTab();
	InitUsersTab();
	InitTempTab();
	InitLengthTab();

	// extensions
	cbExtensionsAll->Caption = GLanguageHandler->Text[kShowCategorised].c_str();
	cbExtensionsOther->Caption = GLanguageHandler->Text[kShowUncategorised].c_str();
	cbExtensionsCustom->Caption = GLanguageHandler->Text[kShowCustom].c_str();
	cbExtensionsColourCode->Caption = GLanguageHandler->Text[kColourCode].c_str();

	// ensure the tables are nicely resized to fit their containers
	splitCategoriesMoved(NULL);
	splitTypesMoved(NULL);
	splitFoldersMoved(NULL);
	splitMagnitudeMoved(NULL);
	splitTop101SizeMoved(NULL);
	splitTop101DatesMoved(NULL);
	splitUsersMoved(NULL);
	splitTemporaryMoved(NULL);
	splitLengthsMoved(NULL);
}


void TFrameProperties::InitMenus()
{
	FileCategoryMenus[0]  = miTD1;  FileCategoryMenus[1]  = miTD2;  FileCategoryMenus[2]  = miTD3;  FileCategoryMenus[3]  = miTD4;  FileCategoryMenus[4]  = miTD5;
	FileCategoryMenus[5]  = miTD6;  FileCategoryMenus[6]  = miTD7;  FileCategoryMenus[7]  = miTD8;  FileCategoryMenus[8]  = miTD9;  FileCategoryMenus[9] = miTD10;
	FileCategoryMenus[10] = miTD11; FileCategoryMenus[11] = miTD12; FileCategoryMenus[12] = miTD13; FileCategoryMenus[13] = miTD14; FileCategoryMenus[14] = miTD15;
	FileCategoryMenus[15] = miTD16; FileCategoryMenus[16] = miTD17; FileCategoryMenus[17] = miTD18; FileCategoryMenus[18] = miTD19;

	miOtherAddTo->Caption               = GLanguageHandler->Text[kAddTo].c_str();
	miOA1->Caption                      = GLanguageHandler->Text[kPrograms].c_str();
	miOA2->Caption                      = GLanguageHandler->Text[kSystem].c_str();
	miOA3->Caption                      = GLanguageHandler->Text[kGraphics].c_str();
	miOA4->Caption                      = GLanguageHandler->Text[kMovie].c_str();
	miOA5->Caption                      = GLanguageHandler->Text[kAudio].c_str();
	miOA6->Caption                      = GLanguageHandler->Text[kOffice].c_str();
	miOA7->Caption                      = GLanguageHandler->Text[kProgramming].c_str();
	miOA8->Caption                      = GLanguageHandler->Text[kCompressed].c_str();
	miCustomEM->Caption                 = GLanguageHandler->Text[kCustom].c_str();
	miOA9->Caption                      = GLanguageHandler->Text[kCustom1].c_str();
	miOA10->Caption                     = GLanguageHandler->Text[kCustom2].c_str();
	miOA11->Caption                     = GLanguageHandler->Text[kCustom3].c_str();
	miOA12->Caption                     = GLanguageHandler->Text[kCustom4].c_str();
	miOA13->Caption                     = GLanguageHandler->Text[kCustom5].c_str();
	miOA14->Caption                     = GLanguageHandler->Text[kCustom6].c_str();
	miOA15->Caption                     = GLanguageHandler->Text[kCustom7].c_str();
	miOA16->Caption                     = GLanguageHandler->Text[kCustom8].c_str();
	miOA17->Caption                     = GLanguageHandler->Text[kCustom9].c_str();
	miOA18->Caption                     = GLanguageHandler->Text[kCustom10].c_str();

	miShowOtherFiles->Caption           = GLanguageHandler->Text[kShowFiles].c_str();
	miExtensionsExportTableCSV->Caption = GLanguageHandler->Text[kCopyTableToClipboard].c_str();
	SaveasCSV2->Caption                 = (GLanguageHandler->Text[kSaveAs] + L" CSV").c_str();

	// ==============================================================================================

	miMagnitudeExport->Caption   = (GLanguageHandler->Text[kExportSelectedFile] + kEllipsis).c_str();
	miMagnitudeZip->Caption      = (GLanguageHandler->Text[kAddZipFile] + kEllipsis).c_str();
	miMagnitudeExportCB->Caption = GLanguageHandler->Text[kCopyTableToClipboard].c_str();

	// ==============================================================================================

	miUsersExportSelected->Caption   = (GLanguageHandler->Text[kExportContent] + kEllipsis).c_str();
	miUsersZip->Caption              = (GLanguageHandler->Text[kAddZipFile] + kEllipsis).c_str();
	miUsersExportSelectedCB->Caption = GLanguageHandler->Text[kCopyTableToClipboard].c_str();

	// ==============================================================================================

	miFCO->Caption        = GLanguageHandler->Text[kFilter].c_str();
	miFCOShowAll->Caption = GLanguageHandler->Text[kShowAll].c_str();

	// ==============================================================================================

	miTableExportSelected->Caption   = (GLanguageHandler->Text[kExportSelectedFile] + kEllipsis).c_str();
	miTableZip->Caption              = (GLanguageHandler->Text[kAddZipFile] + kEllipsis).c_str();
	miTableExportSelectedCB->Caption = GLanguageHandler->Text[kCopyTableToClipboard].c_str();

	// ==============================================================================================

	miNFExplore->Caption    = GLanguageHandler->Text[kExploreFolder].c_str();
	miNFProperties->Caption = GLanguageHandler->Text[kFileProperties].c_str();

	// ==============================================================================================

	miNFExploreFolder->Caption    = GLanguageHandler->Text[kExploreFolder].c_str();
	miNFFolderProperties->Caption = GLanguageHandler->Text[kFileProperties].c_str();

	// ==============================================================================================

	miTDShowAll->Caption     = GLanguageHandler->Text[kShowAll].c_str();
	miTDNonZero->Caption     = GLanguageHandler->Text[kShowNonZero].c_str();
	miTDUserDefined->Caption = GLanguageHandler->Text[kUserDefined].c_str();
	miTDCustom->Caption      = (GLanguageHandler->Text[kCustom] + kEllipsis).c_str();

	miLengthShowAll->Caption = GLanguageHandler->Text[kShowAll].c_str();
	miLengthNonZero->Caption = GLanguageHandler->Text[kShowNonZero].c_str();

	// ==============================================================================================

	miFolderMoreDetail->Caption       = (GLanguageHandler->Text[kMoreDetail] + kEllipsis).c_str();
	miScanFromDirList->Caption        = GLanguageHandler->Text[kAnalyseThisFolder].c_str();
	miExploreFromDirList->Caption     = GLanguageHandler->Text[kExploreThisFolder].c_str();
	miFolderExportSelectedCB->Caption = GLanguageHandler->Text[kCopyTableToClipboard].c_str();

	// ==============================================================================================

	MenuItem20->Caption            = GLanguageHandler->Text[kViewOpenFile].c_str();
	MenuItem18->Caption            = GLanguageHandler->Text[kOpenWithCustomViewer].c_str();
	miFileDatesExploreDir->Caption = GLanguageHandler->Text[kExploreFolder].c_str();
	miFileDatesInfo->Caption       = GLanguageHandler->Text[kFileProperties].c_str();
	miDGenerateMD5->Caption        = GLanguageHandler->Text[kGenerateMD5].c_str();
	miFileDatesExport->Caption     = (GLanguageHandler->Text[kExportContent] + kEllipsis).c_str();;
	miFileDatesExportCB->Caption   = GLanguageHandler->Text[kCopyTreeClipboard].c_str();

	// ==============================================================================================

	miTypeExportContent->Caption = (GLanguageHandler->Text[kExportContent] + kEllipsis).c_str();;
	miTypeZip->Caption           = (GLanguageHandler->Text[kAddZipFile] + kEllipsis).c_str();;
	miTypeExportCB->Caption      = GLanguageHandler->Text[kCopyTreeClipboard].c_str();

	// ==============================================================================================

	miChartOptions->Caption = GLanguageHandler->Text[kChartOptions].c_str();
	miCOSave->Caption       = GLanguageHandler->Text[kSaveChart].c_str();
	miCOCopy->Caption       = GLanguageHandler->Text[kCopyChartToClipboard].c_str();
	miCOAdvanced->Caption   = GLanguageHandler->Text[kAdvancedOptions].c_str();

	// ==============================================================================================

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
}


void TFrameProperties::Update()
{
	UpdateControls();

	BuildCategoriesTable();
	BuildCategoriesChart(GSettingsHandler->Chart.LabelOptions);

	TabUiFolders::Chart(vtcFolders, DataSource, FilterValues[sbFoldersConfig->Tag], GSettingsHandler->Chart.LabelOptions);
	TabUiFolders::Table(sgFolders, DataSource);

	TabUiTypes::Tree(tvTypes, DataSource, 2);
	rbTypesBySizeClick(NULL);

	BuildExtensionsTable();

	BuildMagnitudeTable();

	Top101UpdateDropDowns();
}


void TFrameProperties::UpdateControls()
{
	UpdateHistoryDropDowns();
}


void TFrameProperties::SaveSettings()
{
	if (GSettingsHandler->OpenSettings(false))
	{
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_sgMainReport_" + std::to_wstring(DataSource), sgCategories->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_sgDirList_"    + std::to_wstring(DataSource), sgFolders->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_sgMagnitude_"  + std::to_wstring(DataSource), sgMagnitude->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_tvMain_"       + std::to_wstring(DataSource), tvTypes->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_vtcTree_"      + std::to_wstring(DataSource), sgTemporary->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_vtcFileDates_" + std::to_wstring(DataSource), tvDates->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_Top50_"        + std::to_wstring(DataSource), sgTop101Big->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_Top101Dates_"  + std::to_wstring(DataSource), sgTop101BigDate->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_Users_"        + std::to_wstring(DataSource), sgUsers->Width);
		GSettingsHandler->WriteInteger(L"Prefs", L"Sizes_sgLength_"     + std::to_wstring(DataSource), sgLengths->Width);

		// ===========================================================================

		for (int t = 0; t < kChartCount; t++)
		{
			GSettingsHandler->WriteInteger(L"Charts", L"Report_" + std::to_wstring(DataSource) + L"_" + std::to_wstring(t + 1), ChartUtility::GetChartTypeInt(Charts[t]));
		}

		GSettingsHandler->CloseSettings();
	}
	else
	{
//		GLog		TMSLogger.Error('Error saving FrameReports settings.');
	}
}


void TFrameProperties::ToggleStatus(bool status)
{
//
}
#pragma end_region


#pragma region Tab_Generic
void __fastcall TFrameProperties::pcPropertiesChange(TObject *Sender)
{
	if (!JIT.GetTab(pcProperties->TabIndex))
	{
		UpdateDisplay(pcProperties->TabIndex);
	}
}


void TFrameProperties::UpdateDisplay(int display)
{
	switch (display)
	{
	case kTabIndexCategories:
		break;
	case kTabIndexTypes:
		TabUiTypes::Chart(vtcTypes, DataSource, GSettingsHandler->Chart.LabelOptions);
		TabUiTypes::Tree(tvTypes, DataSource, 2);
		TabUiTypes::TreePost(tvTypes);
		TabUiTypes::List(sgTypes, DataSource);
		break;
	case kTabIndexExtensions:
		break;
	case kTabIndexFolders:
		break;
	case kTabIndexMagnitude:
		break;
	case kTabIndexDates:
	{
		int user_id = -1;

		if (cbDatesUsers->ItemIndex != 0)
		{
			int user_id = cbDatesUsers->ItemIndex - 1;
		}

		TabUiDates::Tree(tvDates, nullptr, DataSource, user_id, cbDatesDateRange->ItemIndex, true, rbDatesByQuantity->Checked);
		TabUiDates::Chart(tvDates, vtcDates);
		break;
	}
	case kTabIndexHistory:
	{
		int user_id = -1;

		if (cbHistoryUsers->ItemIndex != 0)
		{
			user_id = cbHistoryUsers->ItemIndex - 1;
		}

		TabUiHistory::Chart(vtcHistory, SearchStrings, DataSource, user_id,
							dtpHistoryFrom->DateTime, dtpHistoryTo->DateTime,
							cbHistoryInterval->ItemIndex, cbHistoryDateSelect->ItemIndex,
							rbHistoryQuantity->Checked, cbHistoryCumulative->Checked,
							cbHistoryInterval->Text.c_str());
		break;
	}
	case kTabIndexTop101:
	{
		int suser_id = -1;
		int duser_id = -1;

		if (cbTop101SizeUser->ItemIndex != 0)
		{
			suser_id = cbTop101SizeUser->ItemIndex - 1;
		}

		if (cbTop101DateUser->ItemIndex != 0)
		{
			duser_id = cbTop101DateUser->ItemIndex - 1;
		}

		pTop101Size->Caption = TabUiTop101::Size(sgTop101Big, sgTop101Small, ice, DataSource, suser_id).c_str();
		pTop101Date->Caption = TabUiTop101::Date(sgTop101BigDate, sgTop101SmallDate, DataSource, duser_id, cbTop101DateDate->ItemIndex).c_str();
		break;
	}
	case kTabIndexNull:
		TabUiNull::TableFiles(sgNullFiles, DataSource);
		TabUiNull::TableFolders(sgNullFolders, DataSource);
		break;
	case kTabIndexUsers:
		if (rbUsersQuantity->Checked)
		{
			vtcUsers->Tag = 1;
		}
		else
		{
			vtcUsers->Tag = 2;
		}

		TabUiUsers::Chart(vtcUsers, DataSource);
		TabUiUsers::Table(sgUsers, DataSource, cbUsersDisplayMode->ItemIndex);
		break;
	case kTabIndexTemp:
		break;
	case kTabIndexNameLength:
		if (rbLengthQuantity->Checked)
		{
			vtcLengths->Tag = 1;
		}
		else
		{
			vtcLengths->Tag = 2;
		}

		TabUiLength::Table(sgLengths, DataSource, kTabDisplayOptionLengths, miLengthShowAll->Checked);
		TabUiLength::Chart(vtcLengths, DataSource, GSettingsHandler->Chart.LabelOptions);
		break;
	}

	JIT.SetTab(display);
}


void __fastcall TFrameProperties::sbCategoriesPieClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	sb->Down = true;

	switch (sb->Tag)
	{
	case kTabIndexCategories:
		ChartUtility::ChangeChartToPie(vtcCategories);
		GImageHandler->SetPieBarImages(sbCategoriesPie, sbCategoriesBar);
		break;
	case kTabIndexTypes:
		ChartUtility::ChangeChartToPie(vtcTypes);
		GImageHandler->SetPieBarImages(sbTypesPie, sbTypesBar);
		break;
	case kTabIndexFolders:
		ChartUtility::ChangeChartToPie(vtcFolders);
		GImageHandler->SetPieBarImages(sbFoldersPie, sbFoldersBar);
		break;
	case kTabIndexMagnitude:
		ChartUtility::ChangeChartToPie(vtcMagnitude);
		GImageHandler->SetPieBarImages(sbMagnitudePie, sbMagnitudeBar);
		break;
	case kTabIndexDates:
		ChartUtility::ChangeChartToPie(vtcDates);
		GImageHandler->SetPieBarImages(sbDatesPie, sbDatesBar);
		break;
	case kTabIndexUsers:
		ChartUtility::ChangeChartToPie(vtcUsers);
		GImageHandler->SetPieBarImages(sbUsersPie, sbUsersBar);
		break;
	case kTabIndexNameLength:
		ChartUtility::ChangeChartToPie(vtcLengths);
		GImageHandler->SetPieBarImages(sbLengthsPie, sbLengthsBar);
		break;
	}
}


void __fastcall TFrameProperties::sbCategoriesBarClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	sb->Down = true;

	switch (sb->Tag)
	{
	case kTabIndexCategories:
		ChartUtility::ChangeChartToHorizontalBar(vtcCategories, false);
		GImageHandler->SetPieBarImages(sbCategoriesPie, sbCategoriesBar);
		break;
	case kTabIndexTypes:
		ChartUtility::ChangeChartToHorizontalBar(vtcTypes, false);
		GImageHandler->SetPieBarImages(sbTypesPie, sbTypesBar);
		break;
	case kTabIndexFolders:
		ChartUtility::ChangeChartToHorizontalBar(vtcFolders, true);
		GImageHandler->SetPieBarImages(sbFoldersPie, sbFoldersBar);
		break;
	case kTabIndexMagnitude:
		ChartUtility::ChangeChartToHorizontalBar(vtcMagnitude, false);
		GImageHandler->SetPieBarImages(sbMagnitudePie, sbMagnitudeBar);
		break;
	case kTabIndexDates:
		ChartUtility::ChangeChartToHorizontalBar(vtcDates, false);
		GImageHandler->SetPieBarImages(sbDatesPie, sbDatesBar);
		break;
	case kTabIndexUsers:
		ChartUtility::ChangeChartToHorizontalBar(vtcUsers, false);
		GImageHandler->SetPieBarImages(sbUsersPie, sbUsersBar);
		break;
	case kTabIndexNameLength:
		ChartUtility::ChangeChartToHorizontalBar(vtcLengths, false);
		GImageHandler->SetPieBarImages(sbLengthsPie, sbLengthsBar);
		break;
	}
}


int TFrameProperties::CurrentTab()
{
	return pcProperties->ActivePageIndex;
}


void TFrameProperties::SetTab(int tab)
{
    pcProperties->ActivePageIndex = tab;
}
#pragma end_region


#pragma region Tab_Categories
void TFrameProperties::InitCategoriesTab()
{
	rbCategoriesBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbCategoriesByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sgCategories->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgCategories->RowCount = kFileCategoriesCount + 1;

	sgCategories->Cells[1][0] = GLanguageHandler->Text[kCategory].c_str();
	sgCategories->Cells[2][0] = GLanguageHandler->Text[kFiles].c_str();
	sgCategories->Cells[3][0] = GLanguageHandler->Text[kAsPercent].c_str();
	sgCategories->Cells[5][0] = GLanguageHandler->Text[kSize].c_str();
	sgCategories->Cells[6][0] = GLanguageHandler->Text[kAsPercent].c_str();

	for (int t = 0; t < 11; t++)
	{
		sgCategories->ColWidths[t] = CategoryWidths[t];
	}
}


void TFrameProperties::BuildCategoriesTable()
{
	int Row = 1;

	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		sgCategories->Cells[1][Row] = GScanEngine->Data[DataSource].ExtensionSpread[t].Name.c_str();
		sgCategories->Cells[2][Row] = GScanEngine->Data[DataSource].ExtensionSpread[t].Count;
		sgCategories->Cells[3][Row] = GScanEngine->Data[DataSource].ExtensionSpread[t].PercentCountString.c_str();

		sgCategories->Cells[5][Row] = Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size).c_str();
		sgCategories->Cells[6][Row] = GScanEngine->Data[DataSource].ExtensionSpread[t].PercentSizeString.c_str();

		sgCategories->Cells[7][Row] = GSettingsHandler->FileCategoryColors[t];
		sgCategories->Cells[8][Row] = GScanEngine->Data[DataSource].ExtensionSpread[t].Size;
		sgCategories->Cells[9][Row] = (int)(GScanEngine->Data[DataSource].ExtensionSpread[t].PercentCount * 50);
		sgCategories->Cells[10][Row] = (int)(GScanEngine->Data[DataSource].ExtensionSpread[t].PercentSize * 50);

		Row++;
	}
}


void TFrameProperties::BuildCategoriesChart(int LabelOptions)
{
	if (GScanEngine->Data[DataSource].FileCount > 0)
	{
		// == don't show size details if the chart is in quantity mode =============
///		if oChart->Tag = fQuantity then
//		  LabelOptions = kLabelOptionDefault;
		// =========================================================================

		vtcCategories->SeriesList->Items[0]->Clear();
		vtcCategories->Legend->TextStyle = ltsPlain;
//		    if XSettings.LastScanMultiple then
//      oChart.Title.Text.Strings[0] = GLanguageHandler->Text[kMultipleFolders]
//    else
		vtcCategories->Title->Text->Strings[0] = GScanEngine->Data[DataSource].Path.String.c_str();

		for (int t = 0; t < kFileCategoriesCount; t++)
		{
			if (GScanEngine->Data[DataSource].ExtensionSpread[t].Count != 0)
			{
				std::wstring s = L"";

				s = GScanEngine->Data[DataSource].ExtensionSpread[t].Name;

				switch (LabelOptions)
				{
				case kLabelOptionDefault: 		 s = GLanguageHandler->TypeDescriptions[t]; break;
				case kLabelOptionMostConvenient: s = Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size); break;
				case kLabelOptionKilobyte:       s = Convert::ConvertToStaticUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size, UnitConversion::kUnitKB); break;
				case kLabelOptionMegabyte:       s = Convert::ConvertToStaticUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size, UnitConversion::kUnitMB); break;
				case kLabelOptionGigabyte:       s = Convert::ConvertToStaticUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size, UnitConversion::kUnitGB); break;
				}

				vtcCategories->SeriesList->Items[0]->Add((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count,
														 s.c_str(),
														 TColor(GSettingsHandler->FileCategoryColors[t]));
			}
		}
	}
}


void __fastcall TFrameProperties::rbCategoriesBySizeClick(TObject *Sender)
{
//
}


void __fastcall TFrameProperties::sbCategoriesConfigClick(TObject *Sender)
{
	int tag = ((TSpeedButton*)Sender)->Tag;

	switch (GSettingsHandler->TabDisplay[tag].Option[0].Value)
	{
	case 0:
		miTDShowAll->Checked = true;
		break;
	case 1:
		miTDNonZero->Checked = true;
		break;
	case 2:
		miTDUserDefined->Checked = true;
		break;
	}

	for (int t = 0; t < 19; t++)
	{
		if (GSettingsHandler->TabDisplay[tag].Option[t + 1].Value == 1)
		{
			FileCategoryMenus[t]->Checked = true;
		}
		else
		{
			FileCategoryMenus[t]->Checked = false;
		}
	}

	puTableDisplay->Tag = tag;
	TPoint mouse_pos = Mouse->CursorPos;
	puTableDisplay->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameProperties::splitCategoriesMoved(TObject *Sender)
{
	int total = sgCategories->ColWidths[0];

	for (int t = 2; t < 7; t++)
	{
		total += sgCategories->ColWidths[t];
	}

	sgCategories->ColWidths[1] = sgCategories->Width - (total + __WidthOfScrollbar);
}


void __fastcall TFrameProperties::sgCategoriesDrawCell(TObject *Sender, System::LongInt ACol,
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
		case 0:
			if (static_cast<TStringGrid*>(Sender)->ColWidths[0] != -1)
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(StrToInt(static_cast<TStringGrid*>(Sender)->Cells[7][ARow]));
				static_cast<TStringGrid*>(Sender)->Canvas->FillRect(Rect);
			}
			break;
		case 2:
		case 5:
		{
			int left = Rect.Right - static_cast<TStringGrid*>(Sender)->Canvas->TextWidth(static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]) - 2;
			static_cast<TStringGrid*>(Sender)->Canvas->TextOut(left, Rect.Top + 3, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
			break;
		}
		case 3:
		{
			static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(0xff8822);
			static_cast<TStringGrid*>(Sender)->Canvas->Rectangle(Rect);

			if (static_cast<TStringGrid*>(Sender)->Cells[9][ARow] != L"0")
			{
				TRect zRect;
				zRect.Top    = Rect.Top + 1;
				zRect.Bottom = Rect.Bottom - 1;
				zRect.Left   = Rect.Left + 1;
				zRect.Right  = Rect.Left + StrToInt(static_cast<TStringGrid*>(Sender)->Cells[9][ARow]);

				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(0xdd4411);
				static_cast<TStringGrid*>(Sender)->Canvas->FillRect(zRect);
			}

			static_cast<TStringGrid*>(Sender)->Canvas->Brush->Style = bsClear;
			static_cast<TStringGrid*>(Sender)->Canvas->Font->Color  = clBlack;
			static_cast<TStringGrid*>(Sender)->Canvas->TextOut(Rect.Left + 5, Rect.Top + 3, static_cast<TStringGrid*>(Sender)->Cells[3][ARow]);
			break;
		}
		case 6:
		{
			static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(0xff8822);
			static_cast<TStringGrid*>(Sender)->Canvas->Rectangle(Rect);

			if (static_cast<TStringGrid*>(Sender)->Cells[10][ARow] != L"0")
			{
				TRect zRect;
			  zRect.Top    = Rect.Top + 1;
			  zRect.Bottom = Rect.Bottom - 1;
			  zRect.Left   = Rect.Left + 1;
			  zRect.Right  = Rect.Left + StrToInt(static_cast<TStringGrid*>(Sender)->Cells[10][ARow]);

			  static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(0xdd4411);
			  static_cast<TStringGrid*>(Sender)->Canvas->FillRect(zRect);
			}

			static_cast<TStringGrid*>(Sender)->Canvas->Brush->Style = bsClear;
			static_cast<TStringGrid*>(Sender)->Canvas->Font->Color  = clBlack;
			static_cast<TStringGrid*>(Sender)->Canvas->TextOut(Rect.Left + 5, Rect.Top + 3, static_cast<TStringGrid*>(Sender)->Cells[6][ARow]);
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


#pragma region Tab_Types
void TFrameProperties::InitTypesTab()
{
	rbTypesBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbTypesByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sgTypes->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgTypes->RowCount = 15;

	sgTypes->Cells[1][0] = GLanguageHandler->Text[kFileAttributes].c_str();
	sgTypes->Cells[2][0] = GLanguageHandler->Text[kFiles].c_str();
	sgTypes->Cells[3][0] = GLanguageHandler->Text[kAsPercent].c_str();
	sgTypes->Cells[5][0] = GLanguageHandler->Text[kSize].c_str();
	sgTypes->Cells[6][0] = GLanguageHandler->Text[kAsPercent].c_str();

	for (int t = 0; t < 11; t++)
	{
		sgTypes->ColWidths[t] = TypesWidths[t];
	}
}


void __fastcall TFrameProperties::rbTypesBySizeClick(TObject *Sender)
{
	if (rbTypesBySize->Checked)
	{
		vtcTypes->Tag = 2;
	}
	else
	{
		vtcTypes->Tag = 1;
	}

	TabUiTypes::Chart(vtcTypes, DataSource, GSettingsHandler->Chart.LabelOptions);
}


void __fastcall TFrameProperties::tvTypesClick(TObject *Sender)
{
	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		std::wstring text = L"";

		if (tvTypes->Selected->Parent == nullptr)
		{
			text = tvTypes->Selected->Text.c_str();
		}
		else
		{
			text = tvTypes->Selected->Parent->Text.c_str();
		}

		for (int t = 0; t < kFileCategoriesCount; t++)
		{
			if (text.find(GLanguageHandler->TypeDescriptions[t]) != std::wstring::npos)
			{
				GSettingsHandler->TabInternal.TreeViewChartIndex = t;
				break;
            }
		}

		TabUiTypes::Chart(vtcTypes, DataSource, 0); //XSettings.Charts.Options.LabelOptions);
	}
}


void __fastcall TFrameProperties::splitTypesMoved(TObject *Sender)
{
	int total = 0;

	for (int t = 1; t < 6; t++)
	{
		total += sgTypes->ColWidths[t];
	}

	sgTypes->ColWidths[1] = sgTypes->Width - (total + __WidthOfScrollbar);
}
#pragma end_region


#pragma region Tab_Extensions
void TFrameProperties::InitExtensionsTab()
{
	cbExtensionsAll->Caption = GLanguageHandler->Text[kShowCategorised].c_str();
	cbExtensionsCustom->Caption = GLanguageHandler->Text[kShowCustom].c_str();
	cbExtensionsOther->Caption = GLanguageHandler->Text[kShowUncategorised].c_str();
	cbExtensionsColourCode->Caption = GLanguageHandler->Text[kColourCode].c_str();

	sgExtensions->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgExtensions->RowCount = 2;

	sgExtensions->Cells[1][0] = GLanguageHandler->Text[kExtension].c_str();
	sgExtensions->Cells[2][0] = GLanguageHandler->Text[kFiles].c_str();
	sgExtensions->Cells[3][0] = GLanguageHandler->Text[kAsPercent].c_str();
	sgExtensions->Cells[5][0] = GLanguageHandler->Text[kSize].c_str();
	sgExtensions->Cells[6][0] = GLanguageHandler->Text[kAsPercent].c_str();
	sgExtensions->Cells[11][0] = GLanguageHandler->Text[kSuggestedFileType].c_str();

	for (int t = 0; t < 12; t++)
	{
		sgExtensions->ColWidths[t] = ExtensionsWidths[t];
	}
}


void TFrameProperties::BuildExtensionsTable()
{
	int row = 1;

	for (int t = 0; t < GFileExtensionHandler->Extensions.size(); t++)
	{
		if (GFileExtensionHandler->Extensions[t]->Count != 0)
		{
			sgExtensions->Cells[1][row] = GFileExtensionHandler->Extensions[t]->Name.c_str();
			sgExtensions->Cells[2][row] = GFileExtensionHandler->Extensions[t]->Count;
			sgExtensions->Cells[3][row] = GFileExtensionHandler->Extensions[t]->PercentCountString.c_str();

			sgExtensions->Cells[5][row] = Convert::ConvertToUsefulUnit(GFileExtensionHandler->Extensions[t]->Size).c_str();
			sgExtensions->Cells[6][row] = GFileExtensionHandler->Extensions[t]->PercentSizeString.c_str();

			sgExtensions->Cells[7][row] = 0;
			sgExtensions->Cells[8][row] = GFileExtensionHandler->Extensions[t]->Size;
			sgExtensions->Cells[9][row] = (int)(GFileExtensionHandler->Extensions[t]->PercentCount * 50);
			sgExtensions->Cells[10][row] = (int)(GFileExtensionHandler->Extensions[t]->PercentSize * 50);

			sgExtensions->Cells[11][row] = GFileExtensionHandler->Extensions[t]->Description.c_str();

			sgExtensions->RowCount++;

			row++;
		}
	}

	if (sgExtensions->RowCount != 2)
	{
		sgExtensions->RowCount--;
	}
}


void __fastcall TFrameProperties::tsExtensionsResize(TObject *Sender)
{
	int total = 0;

	for (int t = 0; t < 7; t++)
	{
		total += sgExtensions->ColWidths[t];
	}

	sgExtensions->ColWidths[11] = sgExtensions->Width - (total + __WidthOfScrollbar);
}


void __fastcall TFrameProperties::cbExtensionsAllClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Tab_Folders
void TFrameProperties::InitFoldersTab()
{
	rbFoldersBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbFoldersByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sbFoldersMoreDetail->Caption = (GLanguageHandler->Text[kMoreDetail] + kEllipsis).c_str();

	sgFolders->Cells[1][0] = GLanguageHandler->Text[kFolder].c_str();
	sgFolders->Cells[2][0] = GLanguageHandler->Text[kHashFiles].c_str();
	sgFolders->Cells[3][0] = GLanguageHandler->Text[kAsPercent].c_str();
	sgFolders->Cells[5][0] = GLanguageHandler->Text[kSize].c_str();
	sgFolders->Cells[6][0] = GLanguageHandler->Text[kPercent].c_str();

	sgFolders->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgFolders->RowCount = 2;

	for (int t = 0; t < 11; t++)
	{
		sgFolders->ColWidths[t] = FoldersWidths[t];
	}
}


void __fastcall TFrameProperties::sbFoldersConfigClick(TObject *Sender)
{
	TPoint mouse_pos = Mouse->CursorPos;

	puTableDisplay->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameProperties::sbFoldersMoreDetailClick(TObject *Sender)
{
	if (sgFolders->Selection.Top > 0)
	{
		FoldersDoubleClickCell(sgFolders->Selection.Top);
	}
}


void __fastcall TFrameProperties::sgFoldersDblClick(TObject *Sender)
{
	int Row = sgFolders->Selection.Top;

	FoldersDoubleClickCell(Row);
}


void TFrameProperties::FoldersDoubleClickCell(int row)
{
	if (row > 0)
	{
		if (row == 1)
		{
			OpenMoreDetails(DataSource, GScanEngine->Data[DataSource].Path.String);
		}
		else
		{
			std::wstring folder = sgFolders->Cells[1][row].c_str();

			OpenMoreDetails(DataSource, GScanEngine->Data[DataSource].Path.String + folder + L"\\");
		}
	}
}


void __fastcall TFrameProperties::splitFoldersMoved(TObject *Sender)
{
	int total = sgFolders->ColWidths[0];

	for (int t = 2; t < 7; t++)
	{
		total += sgFolders->ColWidths[t];
	}

	sgFolders->ColWidths[1] = sgFolders->Width - (total + __WidthOfScrollbar);
}


void __fastcall TFrameProperties::rbFoldersBySizeClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Tab_Magnitude
void TFrameProperties::InitMagnitudeTab()
{
	rbMagnitudeBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbMagnitudeByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sgMagnitude->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgMagnitude->RowCount = kMagnitudesCount + 1;

	sgMagnitude->Cells[1][0] = GLanguageHandler->Text[kFileSize].c_str();
	sgMagnitude->Cells[2][0] = GLanguageHandler->Text[kHashFiles].c_str();
	sgMagnitude->Cells[3][0] = GLanguageHandler->Text[kAsPercent].c_str();
	sgMagnitude->Cells[5][0] = GLanguageHandler->Text[kSize].c_str();
	sgMagnitude->Cells[6][0] = GLanguageHandler->Text[kAsPercent].c_str();

	for (int t = 0; t < 11; t++)
	{
		sgMagnitude->ColWidths[t] = MagnitudesWidths[t];
	}
}


void TFrameProperties::BuildMagnitudeTable()
{
	for (int t = 0; t < kMagnitudesCount; t++)
	{
		sgMagnitude->Cells[1][t + 1]  = GScanEngine->Data[DataSource].Magnitude[t].Name.c_str();
		sgMagnitude->Cells[2][t + 1]  = GScanEngine->Data[DataSource].Magnitude[t].Count;
		sgMagnitude->Cells[3][t + 1]  = GScanEngine->Data[DataSource].Magnitude[t].PercentCountString.c_str();

		sgMagnitude->Cells[5][t + 1]  = Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].Magnitude[t].Size).c_str();
		sgMagnitude->Cells[6][t + 1]  = GScanEngine->Data[DataSource].Magnitude[t].PercentSizeString.c_str();

		sgMagnitude->Cells[7][t + 1]  = TColor(kMagnitudeColours[t]);

		sgMagnitude->Cells[8][t + 1]  = GScanEngine->Data[DataSource].Magnitude[t].Size;
		sgMagnitude->Cells[9][t + 1]  = (int)(GScanEngine->Data[DataSource].Magnitude[t].PercentCount * 50);
		sgMagnitude->Cells[10][t + 1] = (int)(GScanEngine->Data[DataSource].Magnitude[t].PercentSize * 50);
	}
}


void TFrameProperties::BuildMagnitudeChart(bool range)
{
	if (GScanEngine->Data[DataSource].FileCount == 0) return;

	int data_range = 0;

	if (range)
	{
		data_range = 1;
	}

    //-- build graph -------------------------------------------------------------
	vtcMagnitude->SeriesList->Items[0]->Clear();
	vtcMagnitude->Legend->TextStyle = ltsPlain;
	vtcMagnitude->Title->Text->Strings[0] = GScanEngine->Data[DataSource].Path.String.c_str();

	if (data_range == 1)
	{
		vtcMagnitude->BottomAxis->Title->Caption = GLanguageHandler->Text[kBytes].c_str();
	}
	else
	{
		vtcMagnitude->BottomAxis->Title->Caption = GLanguageHandler->Text[kQuantity].c_str();
	}

	for (int t = 0; t < kMagnitudesCount; t++)
	{
		if (data_range == 0)
		{
			if (GScanEngine->Data[DataSource].Magnitude[t].Count != 0)
			{
				vtcMagnitude->SeriesList->Items[0]->Add(GScanEngine->Data[DataSource].Magnitude[t].Count, kMagnitudeLabelsShort[t].c_str(), TColor(kMagnitudeColours[t]));
			}
		}
		else
		{
			if (GScanEngine->Data[DataSource].Magnitude[t].Size != 0)
			{
				vtcMagnitude->SeriesList->Items[0]->Add(GScanEngine->Data[DataSource].Magnitude[t].Size, kMagnitudeLabelsShort[t].c_str(), TColor(kMagnitudeColours[t]));
			}
		}
	}
}


void __fastcall TFrameProperties::splitMagnitudeMoved(TObject *Sender)
{
	int total = sgMagnitude->ColWidths[0];

	for (int t = 2; t < 7; t++)
	{
		total += sgMagnitude->ColWidths[t];
	}

	sgMagnitude->ColWidths[1] = sgMagnitude->Width - (total + __WidthOfScrollbar);
}


void __fastcall TFrameProperties::rbMagnitudeBySizeClick(TObject *Sender)
{
//
}


void __fastcall TFrameProperties::ComboBox3Change(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Tab_Dates
void TFrameProperties::InitDatesTab()
{
	rbDatesBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbDatesByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sbDatesCollapseNodes->Caption = GLanguageHandler->Text[kCollapseNodes].c_str();

	cbDatesDateRange->Items->Add(GLanguageHandler->Text[kCreated].c_str());
	cbDatesDateRange->Items->Add(GLanguageHandler->Text[kAccessed].c_str());
	cbDatesDateRange->Items->Add(GLanguageHandler->Text[kModified].c_str());
    cbDatesDateRange->ItemIndex = 0;
}


void TFrameProperties::DatesUpdateDropDowns()
{
	cbDatesUsers->Items->Clear();
	cbDatesUsers->Items->Add(GLanguageHandler->Text[kAllUsers].c_str());

	for (int t = 0; t < GScanEngine->Data[DataSource].Users.size(); t++)
	{
		cbDatesUsers->Items->Add(GScanEngine->Data[DataSource].Users[t]->Name.c_str());
	}

	cbDatesUsers->ItemIndex = 0;
}


void __fastcall TFrameProperties::cbDatesUsersChange(TObject *Sender)
{
	//
}


void __fastcall TFrameProperties::sbDatesCollapseNodesClick(TObject *Sender)
{
	tvDates->FullCollapse();
}
#pragma end_region


#pragma region Tab_History
void TFrameProperties::InitHistoryTab()
{
	lHistoryFrom->Caption = GLanguageHandler->Text[kFrom].c_str();
	lHistoryTo->Caption = GLanguageHandler->Text[kTo].c_str();
	lHistoryInterval->Caption = GLanguageHandler->Text[kInterval].c_str();

	gbHistoryOptions->Caption = GLanguageHandler->Text[kOptions].c_str();
	rbHistoryQuantity->Caption = GLanguageHandler->Text[kQuantity].c_str();
	rbHistorySize->Caption = GLanguageHandler->Text[kSize].c_str();
	cbHistoryCumulative->Caption = GLanguageHandler->Text[kCumulative].c_str();

	cbHistoryInterval->Items->Add(GLanguageHandler->Text[kDay].c_str());
	cbHistoryInterval->Items->Add(GLanguageHandler->Text[kWeek].c_str());
	cbHistoryInterval->Items->Add(GLanguageHandler->Text[kMonth].c_str());
	cbHistoryInterval->Items->Add(GLanguageHandler->Text[kYear].c_str());
	cbHistoryInterval->Items->Add(GLanguageHandler->Text[kHour].c_str());
	cbHistoryInterval->ItemIndex = 0;

	cbHistoryDateSelect->Items->Add(GLanguageHandler->Text[kCreated].c_str());
	cbHistoryDateSelect->Items->Add(GLanguageHandler->Text[kAccessed].c_str());
	cbHistoryDateSelect->Items->Add(GLanguageHandler->Text[kModified].c_str());
	cbHistoryDateSelect->ItemIndex = 0;

	lHistoryUser->Caption = GLanguageHandler->Text[kUsers].c_str();

	sbHistoryRefresh->Caption = GLanguageHandler->Text[kRefresh].c_str();
	cbHistoryAutoRefresh->Caption = GLanguageHandler->Text[kAutoRefresh].c_str();
}


void TFrameProperties::UpdateHistoryDropDowns()
{
	cbHistoryUsers->Items->Clear();
	cbHistoryUsers->Items->Add(GLanguageHandler->Text[kAllUsers].c_str());

	for (int t = 0; t < GScanEngine->Data[DataSource].Users.size(); t++)
	{
		cbHistoryUsers->Items->Add(GScanEngine->Data[DataSource].Users[t]->Name.c_str());
	}

    cbHistoryUsers->ItemIndex = 0;
}


void __fastcall TFrameProperties::sbHistoryRefreshClick(TObject *Sender)
{
	int user_id = -1;

	if (cbHistoryUsers->ItemIndex != 0)
	{
		//
	}

	TabUiHistory::Chart(vtcHistory, SearchStrings,
						DataSource, user_id,
						dtpHistoryFrom->DateTime, dtpHistoryTo->DateTime,
						cbHistoryInterval->ItemIndex, cbHistoryDateSelect->ItemIndex,
						rbHistoryQuantity->Checked, cbHistoryCumulative->Checked,
						cbHistoryInterval->Text.c_str());
}


void __fastcall TFrameProperties::rbHistoryQuantityClick(TObject *Sender)
{
	if (cbHistoryAutoRefresh->Checked)
	{
		sbHistoryRefreshClick(NULL);
	}
}


void __fastcall TFrameProperties::vtcHistoryClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Tab_Top_101
void TFrameProperties::InitTop101Tab()
{
	ice = new XIceCream(this, pICTop101);

	tsTop101Size->Caption = GLanguageHandler->Text[kBySize].c_str();
	tsTop101Date->Caption = GLanguageHandler->Text[kByDate].c_str();

	cbTop101SizeColourCode->Caption = GLanguageHandler->Text[kColourCode].c_str();
	cbTop101DateColourCode->Caption = GLanguageHandler->Text[kColourCode].c_str();

	cbTop101DateDate->Items->Clear();
	cbTop101DateDate->Items->Add(GLanguageHandler->Text[kCreated].c_str());
	cbTop101DateDate->Items->Add(GLanguageHandler->Text[kAccessed].c_str());
	cbTop101DateDate->Items->Add(GLanguageHandler->Text[kModified].c_str());
	cbTop101DateDate->ItemIndex = 0;

	sgTop101Big->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgTop101Small->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgTop101BigDate->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgTop101SmallDate->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgTop101Big->RowCount = 2;
	sgTop101Small->RowCount = 2;
	sgTop101BigDate->RowCount = 2;
	sgTop101SmallDate->RowCount = 2;

	sgTop101Big->Cells[0][0] = GLanguageHandler->Text[kLargestFiles].c_str();
	sgTop101Big->Cells[1][0] = GLanguageHandler->Text[kSize].c_str();
	sgTop101Big->Cells[2][0] = GLanguageHandler->Text[kFileOwner].c_str();

	sgTop101Small->Cells[0][0] = GLanguageHandler->Text[kSmallestFiles].c_str();
	sgTop101Small->Cells[1][0] = GLanguageHandler->Text[kSize].c_str();

	sgTop101BigDate->Cells[0][0] = GLanguageHandler->Text[kNewestFiles].c_str();
	sgTop101BigDate->Cells[1][0] = GLanguageHandler->Text[kDate].c_str();
	sgTop101BigDate->Cells[2][0] = GLanguageHandler->Text[kSize].c_str();
	sgTop101BigDate->Cells[3][0] = GLanguageHandler->Text[kFileOwner].c_str();

	sgTop101SmallDate->Cells[0][0] = GLanguageHandler->Text[kOldestFiles].c_str();
	sgTop101SmallDate->Cells[1][0] = GLanguageHandler->Text[kDate].c_str();
	sgTop101SmallDate->Cells[2][0] = GLanguageHandler->Text[kSize].c_str();
	sgTop101SmallDate->Cells[3][0] = GLanguageHandler->Text[kFileOwner].c_str();

	for (int t = 0; t < 4; t++)
	{
		sgTop101Big->ColWidths[t] = Top101SizeBigWidths[t];
	}

	sgTop101Small->ColWidths[0] = Top101SizeBigWidths[0];
	sgTop101Small->ColWidths[1] = Top101SizeSmallWidths[1];
	sgTop101Small->ColWidths[2] = Top101SizeSmallWidths[2];

	for (int t = 0; t < 5; t++)
	{
		sgTop101BigDate->ColWidths[t] = Top101DateBigWidths[t];
		sgTop101SmallDate->ColWidths[t] = Top101DateSmallWidths[t];
	}
}


void TFrameProperties::Top101UpdateDropDowns()
{
	cbTop101SizeUser->Items->Clear();
	cbTop101SizeUser->Items->Add(GLanguageHandler->Text[kAllUsers].c_str());

	cbTop101DateUser->Items->Clear();
	cbTop101DateUser->Items->Add(GLanguageHandler->Text[kAllUsers].c_str());

	for (int t = 0; t < GScanEngine->Data[DataSource].Users.size(); t++)
	{
		cbTop101SizeUser->Items->Add(GScanEngine->Data[DataSource].Users[t]->Name.c_str());
		cbTop101DateUser->Items->Add(GScanEngine->Data[DataSource].Users[t]->Name.c_str());
	}

	cbTop101SizeUser->ItemIndex = 0;
	cbTop101DateUser->ItemIndex = 0;
}


void __fastcall TFrameProperties::cbTop101SizeUserChange(TObject *Sender)
{
	int suser_id = -1;

	if (cbTop101SizeUser->ItemIndex != 0)
	{
		suser_id = cbTop101SizeUser->ItemIndex - 1;
	}

	pTop101Size->Caption = TabUiTop101::Size(sgTop101Big, sgTop101Small, ice, DataSource, suser_id).c_str();
}


void __fastcall TFrameProperties::cbTop101SizeColourCodeClick(TObject *Sender)
{
	sgTop101Big->Invalidate();
    sgTop101Small->Invalidate();
}


void __fastcall TFrameProperties::cbTop101DateUserChange(TObject *Sender)
{
	int duser_id = -1;

	if (cbTop101DateUser->ItemIndex != 0)
	{
		duser_id = cbTop101DateUser->ItemIndex - 1;
	}

	pTop101Date->Caption = TabUiTop101::Date(sgTop101BigDate, sgTop101SmallDate, DataSource, duser_id, cbTop101DateDate->ItemIndex).c_str();
}


void __fastcall TFrameProperties::cbTop101DateColourCodeClick(TObject *Sender)
{
	sgTop101BigDate->Invalidate();
	sgTop101SmallDate->Invalidate();
}


void __fastcall TFrameProperties::splitTop101SizeMoved(TObject *Sender)
{
	int total = sgTop101Big->ColWidths[1] + sgTop101Big->ColWidths[2];

	sgTop101Big->ColWidths[0] = sgTop101Big->Width - total - __WidthOfScrollbar;

	sgTop101Small->ColWidths[0] = sgTop101Small->Width - (sgTop101Small->ColWidths[1] + __WidthOfScrollbar);
}


void __fastcall TFrameProperties::splitTop101DatesMoved(TObject *Sender)
{
	int total = sgTop101BigDate->ColWidths[1] + sgTop101BigDate->ColWidths[2] + sgTop101BigDate->ColWidths[3];

	sgTop101BigDate->ColWidths[0] = sgTop101BigDate->Width - total - __WidthOfScrollbar;

	total = sgTop101SmallDate->ColWidths[1] + sgTop101SmallDate->ColWidths[2] + sgTop101SmallDate->ColWidths[3];

	sgTop101SmallDate->ColWidths[0] = sgTop101SmallDate->Width - total - __WidthOfScrollbar;
}


void __fastcall TFrameProperties::sgTop101BigDrawCell(TObject *Sender, System::LongInt ACol,
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
			if (cbTop101SizeColourCode->Checked)
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(StrToInt(static_cast<TStringGrid*>(Sender)->Cells[3][ARow]));
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
		}

		static_cast<TStringGrid*>(Sender)->Canvas->FillRect(Rect);

		switch (ACol)
		{
		case 0:
		case 2:
			if (static_cast<TStringGrid*>(Sender)->ColWidths[0] != -1)
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Style = bsClear;
				static_cast<TStringGrid*>(Sender)->Canvas->Font->Color = clWhite;
				static_cast<TStringGrid*>(Sender)->Canvas->TextOut(Rect.Left, Rect.Top, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
			}
			break;
		case 1:
		{
			int left = Rect.Right - static_cast<TStringGrid*>(Sender)->Canvas->TextWidth(static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]) - 2;
			static_cast<TStringGrid*>(Sender)->Canvas->TextOut(left, Rect.Top + 3, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
			break;
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


void __fastcall TFrameProperties::sgTop101SmallDrawCell(TObject *Sender, System::LongInt ACol,
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
			if (cbTop101SizeColourCode->Checked)
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(StrToInt(static_cast<TStringGrid*>(Sender)->Cells[2][ARow]));
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
		}

		static_cast<TStringGrid*>(Sender)->Canvas->FillRect(Rect);

		switch (ACol)
		{
		case 0:
			if (static_cast<TStringGrid*>(Sender)->ColWidths[0] != -1)
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Style = bsClear;
				static_cast<TStringGrid*>(Sender)->Canvas->Font->Color = clWhite;
				static_cast<TStringGrid*>(Sender)->Canvas->TextOut(Rect.Left, Rect.Top, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
			}
			break;
		case 1:
		{
			int left = Rect.Right - static_cast<TStringGrid*>(Sender)->Canvas->TextWidth(static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]) - 2;
			static_cast<TStringGrid*>(Sender)->Canvas->TextOut(left, Rect.Top + 3, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
			break;
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


void __fastcall TFrameProperties::sgTop101BigDateDrawCell(TObject *Sender, System::LongInt ACol,
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
			if (cbTop101SizeColourCode->Checked)
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Color = TColor(StrToInt(static_cast<TStringGrid*>(Sender)->Cells[4][ARow]));
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
		}

		static_cast<TStringGrid*>(Sender)->Canvas->FillRect(Rect);

		switch (ACol)
		{
		case 0:
		case 1:
		case 3:
			if (static_cast<TStringGrid*>(Sender)->ColWidths[0] != -1)
			{
				static_cast<TStringGrid*>(Sender)->Canvas->Brush->Style = bsClear;
				static_cast<TStringGrid*>(Sender)->Canvas->Font->Color = clWhite;
				static_cast<TStringGrid*>(Sender)->Canvas->TextOut(Rect.Left, Rect.Top, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
			}
			break;
		case 2:
		{
			int left = Rect.Right - static_cast<TStringGrid*>(Sender)->Canvas->TextWidth(static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]) - 2;
			static_cast<TStringGrid*>(Sender)->Canvas->TextOut(left, Rect.Top + 3, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
			break;
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


#pragma region Tab_NullFiles
void TFrameProperties::InitNullTab()
{
	sgNullFiles->Cells[0][0] = GLanguageHandler->Text[kFilePath].c_str();
	sgNullFolders->Cells[0][0] = GLanguageHandler->Text[kFilePath].c_str();
}


void __fastcall TFrameProperties::tsNullResize(TObject *Sender)
{
	sgNullFiles->ColWidths[0] = sgNullFiles->Width - __WidthOfScrollbar;
	sgNullFolders->ColWidths[0] = sgNullFolders->Width - __WidthOfScrollbar;
}


void __fastcall TFrameProperties::sgNullFilesDrawCell(TObject *Sender, System::LongInt ACol,
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

		static_cast<TStringGrid*>(Sender)->Canvas->Brush->Style = bsClear;
		static_cast<TStringGrid*>(Sender)->Canvas->Font->Color = clWhite;
		static_cast<TStringGrid*>(Sender)->Canvas->TextOut(Rect.Left, Rect.Top, static_cast<TStringGrid*>(Sender)->Cells[ACol][ARow]);
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


#pragma region Tab_Users
void TFrameProperties::InitUsersTab()
{
	rbUsersSize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbUsersQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sgUsers->Cells[1][0] = GLanguageHandler->Text[kOwner].c_str();
	sgUsers->Cells[2][0] = GLanguageHandler->Text[kFiles].c_str();
	sgUsers->Cells[3][0] = GLanguageHandler->Text[kAsPercent].c_str();
	sgUsers->Cells[5][0] = GLanguageHandler->Text[kSize].c_str();
	sgUsers->Cells[6][0] = GLanguageHandler->Text[kAsPercent].c_str();

	cbUsersDisplayMode->Clear();
	cbUsersDisplayMode->Items->Add(GLanguageHandler->Text[kShowAll].c_str());

	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		cbUsersDisplayMode->Items->Add((L" - " + GLanguageHandler->TypeDescriptions[t]).c_str());
	}

	cbUsersDisplayMode->ItemIndex = 0;

	sgUsers->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgUsers->RowCount = 2;

	for (int t = 0; t < 11; t++)
	{
		sgUsers->ColWidths[t] = UsersWidths[t];
	}
}


void TFrameProperties::UsersUpdateDropDowns()
{
	cbUsersDisplayMode->Items->Clear();
	cbUsersDisplayMode->Items->Add(GLanguageHandler->Text[kAllUsers].c_str());

	for (int t = 0; t < GScanEngine->Data[DataSource].Users.size(); t++)
	{
		cbUsersDisplayMode->Items->Add(GScanEngine->Data[DataSource].Users[t]->Name.c_str());
	}

	cbUsersDisplayMode->ItemIndex = 0;
}


void __fastcall TFrameProperties::splitUsersMoved(TObject *Sender)
{
	int total = sgUsers->ColWidths[0];

	for (int t = 2; t < 11; t++)
	{
		if (sgUsers->ColWidths[t] != -1)
		{
			total += sgUsers->ColWidths[t];
        }
	}

	sgUsers->ColWidths[1] = sgUsers->Width - (total + __WidthOfScrollbar);
}


void __fastcall TFrameProperties::rbUsersSizeClick(TObject *Sender)
{
//
}


void __fastcall TFrameProperties::SpeedButton21Click(TObject *Sender)
{
//
}


void __fastcall TFrameProperties::cbUsersDisplayModeChange(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Tab_Temp
void TFrameProperties::InitTempTab()
{
	rbTempBySize->Caption  = GLanguageHandler->Text[kBySize].c_str();
	rbTempByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sgTemporary->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgTemporary->RowCount = 2;

	sgTemporary->ColWidths[0] = TempWidths[0];
	sgTemporary->ColWidths[1] = TempWidths[1];
	sgTemporary->ColWidths[2] = -1;
}


void __fastcall TFrameProperties::splitTemporaryMoved(TObject *Sender)
{
	sgTemporary->ColWidths[0] = TempWidths[1];

	sgTemporary->ColWidths[1] = sgTemporary->Width - (TempWidths[1] + __WidthOfScrollbar);
}


void __fastcall TFrameProperties::rbTempBySizeClick(TObject *Sender)
{
//
}


void __fastcall TFrameProperties::sgTemporaryDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
//
}
#pragma end_region


#pragma region Tab_Length
void TFrameProperties::InitLengthTab()
{
	rbLengthSize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbLengthQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	miLengthShowAll->Caption = GLanguageHandler->Text[kShowAll].c_str();
	miLengthNonZero->Caption = GLanguageHandler->Text[kShowNonZero].c_str();

	sgLengths->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
	sgLengths->RowCount = 2;

	sgLengths->Cells[1][0] = GLanguageHandler->Text[kFileNameLength].c_str();
	sgLengths->Cells[2][0] = GLanguageHandler->Text[kFiles].c_str();
	sgLengths->Cells[3][0] = GLanguageHandler->Text[kAsPercent].c_str();
	sgLengths->Cells[5][0] = GLanguageHandler->Text[kSize].c_str();
	sgLengths->Cells[6][0] = GLanguageHandler->Text[kAsPercent].c_str();

	for (int t = 0; t < 11; t++)
	{
		sgLengths->ColWidths[t] = LengthsWidths[t];
	}
}


void __fastcall TFrameProperties::SpeedButton15Click(TObject *Sender)
{
	int tag = ((TSpeedButton*)Sender)->Tag;

	switch (GSettingsHandler->TabDisplay[tag].Option[0].Value)
	{
	case 0:
		miLengthShowAll->Checked = true;
		break;
	case 1:
		miLengthNonZero->Checked = true;
		break;
	}

	TPoint mouse_pos = Mouse->CursorPos;

	puTableDisplay->Popup(mouse_pos.X, mouse_pos.Y);
}


void __fastcall TFrameProperties::splitLengthsMoved(TObject *Sender)
{
	int total = sgLengths->ColWidths[0];

	for (int t = 2; t < 7; t++)
	{
		if (sgLengths->ColWidths[t] != -1)
		{
			total += sgLengths->ColWidths[t];
		}
	}

	sgLengths->ColWidths[1] = sgLengths->Width - (total + __WidthOfScrollbar);
}


void __fastcall TFrameProperties::rbLengthSizeClick(TObject *Sender)
{
//
}
#pragma end_region


#pragma region PopupMenu_Charts
void __fastcall TFrameProperties::miCOSaveClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::ExecuteImages(Utility::GetDefaultFileName(L".png", GLanguageHandler->Text[kTable] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TChart* chart = (TChart*)pum->PopupComponent;

		ChartUtility::SaveChartToPNG(chart, file_name);
	}
}


void __fastcall TFrameProperties::miCOCopyClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TChart* chart = (TChart*)pum->PopupComponent;

	ChartUtility::CopyChartToClipboard(chart);
}


void __fastcall TFrameProperties::miCOAdvancedClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TChart* chart = (TChart*)pum->PopupComponent;

	ChartOptions co = GSettingsHandler->Chart;

	co.Type = ChartUtility::GetChartType(chart);

	// =========================================================================

	co = ShowChartOptions(co);

	// =========================================================================

	if (co.Result == 1)
	{
		ChartUtility::SetAdvancedOptions(chart, co);

		if (OnChartsChanged)
		{
			OnChartsChanged(0);
		}
	}
}
#pragma end_region


#pragma region PopupMenu_ExtensionsMain
void __fastcall TFrameProperties::miOA1Click(TObject *Sender)
{
	int tag = ((TMenuItem*)Sender)->Tag;

	if (sgExtensions->Selection.Top != -1)
	{
		for (int r = sgExtensions->Selection.Top; r <= sgExtensions->Selection.Bottom; r++)
		{
			FileExtension *tfx = new FileExtension(sgExtensions->Cells[0][r].c_str(), tag);

			GFileExtensionHandler->Extensions.push_back(tfx);
		}

		GFileExtensionHandler->SaveFileExtensionLists(GSystemGlobal->ExePath, false, true);
	}
}


void __fastcall TFrameProperties::miShowOtherFilesClick(TObject *Sender)
{
	std::wstring search = sgExtensions->Cells[0][sgExtensions->Selection.Top].c_str();

	if (!search.empty())
	{
		if (OnNewSearch)
		{
			OnNewSearch(L"." + search, DataSource);
		}
	}
}


void __fastcall TFrameProperties::miExtensionsExportTableCSVClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTemp:
		GridUtility::CopyGridToClipboard(sgTemporary, 0);
		break;
	case kGridTop101Big:
		GridUtility::CopyGridToClipboard(sgTop101Big, 0);
		break;
	case kGridTop101Small:
		GridUtility::CopyGridToClipboard(sgTop101Small, 0);
		break;
	case kGridTop101BigDate:
		GridUtility::CopyGridToClipboard(sgTop101BigDate, 0);
		break;
	case kGridTop101SmallDate:
		GridUtility::CopyGridToClipboard(sgTop101SmallDate, 0);
		break;
	case kGridExtension:
		GridUtility::CopyGridToClipboard(sgExtensions, 0);
		break;
	}
}


void __fastcall TFrameProperties::SaveasCSV2Click(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kSearchResults]));

	if (!file_name.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;

		GridUtility::SaveGrid(sg, file_name);
	}
}
#pragma end_region


#pragma region PopupMenu_FolderConfig
void __fastcall TFrameProperties::miFCOShowAllClick(TObject *Sender)
{
	if (Sender != NULL)
	{
		TMenuItem *mi = (TMenuItem*)Sender;

		sbFoldersConfig->Tag = mi->Tag;
	}

	if (rbFoldersBySize->Checked)
	{
		vtcFolders->Tag = 1;
	}
	else
	{
		vtcFolders->Tag = 0;
	}

	TabUiFolders::Chart(vtcFolders, DataSource, FilterValues[sbFoldersConfig->Tag], GSettingsHandler->Chart.LabelOptions);
}
#pragma end_region


#pragma region PopupMenu_Folders
void __fastcall TFrameProperties::miFolderMoreDetailClick(TObject *Sender)
{
	if (sgFolders->Selection.Top > 0)
	{
		FoldersDoubleClickCell(sgFolders->Selection.Top);
	}
}


void __fastcall TFrameProperties::miScanFromDirListClick(TObject *Sender)
{
	if (sgFolders->Cells[1][sgFolders->Selection.Top] != L"  -" &&
		sgFolders->Cells[1][sgFolders->Selection.Top] != L"")
	{
		std::wstring path = GScanEngine->Data[DataSource].Path.String + sgFolders->Cells[1][sgFolders->Selection.Top].c_str() + L"\"";

		if (OnScanWithNewPath)
		{
			OnScanWithNewPath(path, DataSource, false);
		}
	}
}


void __fastcall TFrameProperties::miExploreFromDirListClick(TObject *Sender)
{
	if (sgFolders->Cells[1][sgFolders->Selection.Top] != L"  -" &&
		sgFolders->Cells[1][sgFolders->Selection.Top] != L"")
	{
		if (sgFolders->Cells[1][sgFolders->Selection.Top] != L"")
		{
			if (sgFolders->Cells[1][sgFolders->Selection.Top] == L'\\')
			{
				WindowsUtility::ExecuteFile(L"\"" + GScanEngine->Data[DataSource].Path.String + L"\"", L"");
			}
			else
			{
				WindowsUtility::ExecuteFile(L"\"" + GScanEngine->Data[DataSource].Path.String + sgFolders->Cells[1][sgFolders->Selection.Top].c_str() + L"\"", L"");
			}
		}
	}
}


void __fastcall TFrameProperties::miFolderExportSelectedCBClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(sgFolders, 1);
}
#pragma end_region


#pragma region PopupMenu_Length
void __fastcall TFrameProperties::miLengthShowAllClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puLength->Tag].Option[0].Value = 0;

	UpdateDisplay(puLength->Tag);
}


void __fastcall TFrameProperties::miLengthNonZeroClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puLength->Tag].Option[0].Value = 1;

	UpdateDisplay(puLength->Tag);
}
#pragma end_region


#pragma region PopupMenu_Magnitude
void __fastcall TFrameProperties::miMagnitudeExportClick(TObject *Sender)
{
//  Assert(grid != NULL, 'miMagnitudeExportClick :: Grid is NULL');

	std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kMagnitude] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		if (Utility::GetFileExtension(file_name) == L".txt")
		{
			if (!TabUiMagnitude::AsText(file_name, DataSource))
			{
				ShowXDialog(GLanguageHandler->Text[kErrorSavingReport],
							GLanguageHandler->Text[kErrorSaving] + L" " + file_name + L".",
							XDialogTypeWarning);
			}
		}
		else
		{
			GridUtility::SaveGrid(sgMagnitude, file_name);
		}
	}
}


void __fastcall TFrameProperties::miMagnitudeZipClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
												  L".zip",
                                                  L"",
												  Utility::GetDefaultFileName(L".zip", GLanguageHandler->Text[kMagnitude] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		std::vector<std::wstring> data;

		std::wstring magnitude_bin = sgMagnitude->Cells[7][sgMagnitude->Selection.Top].c_str();

		int bin = stoi(magnitude_bin);

		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			if (file->MagnitudeBin == bin)
			{
				data.push_back(file->FullPath);
			}
		}

		if (data.size() != 0)
		{
			GXZip->Files(file_name, data, L"");
		}
	}
}


void __fastcall TFrameProperties::miMagnitudeExportCBClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(sgMagnitude, 1);
}
#pragma end_region


#pragma region PopupMenu_NullFiles
void __fastcall TFrameProperties::miNFExploreClick(TObject *Sender)
{
	if (sgNullFiles->Cells[0][1] != GLanguageHandler->Text[kNoneFound].c_str())
	{
        std::wstring file_name = sgNullFiles->Cells[0][sgNullFiles->Selection.Top].c_str();

		WindowsUtility::ExecuteFile(L"\"" + file_name + L"\"", L"");
	}
}


void __fastcall TFrameProperties::miNFPropertiesClick(TObject *Sender)
{
	if (sgNullFiles->Selection.Top > 0)
	{
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, sgNullFiles->Cells[0][sgNullFiles->Selection.Top].c_str());
	}
}
#pragma end_region


#pragma region PopupMenu_NullFolders
void __fastcall TFrameProperties::miNFExploreFolderClick(TObject *Sender)
{
	if (sgNullFolders->Cells[0][1] != GLanguageHandler->Text[kNoneFound].c_str())
	{
		std::wstring file_name = sgNullFolders->Cells[0][sgNullFolders->Selection.Top].c_str();

		WindowsUtility::ExecuteFile(L"\"" + file_name + L"\"", L"");
	}
}


void __fastcall TFrameProperties::miNFFolderPropertiesClick(TObject *Sender)
{
	if (sgNullFolders->Selection.Top != -1)
	{
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, sgNullFolders->Cells[0][sgNullFolders->Selection.Top].c_str());
	}
}
#pragma end_region


#pragma region PopupMenu_Search
void __fastcall TFrameProperties::miSearchOpenClick(TObject *Sender)
{
	std::wstring file_name = L"";

	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTemp:
		file_name = L"\"" + sgTemporary->Cells[0][sgTemporary->Selection.Top] + L"\"";
		break;

	case kGridTop101Big:
		file_name = L"\"" + sgTop101Big->Cells[0][sgTop101Big->Selection.Top] + L"\"";
		break;
	case kGridTop101Small:
		file_name = L"\"" + sgTop101Small->Cells[0][sgTop101Small->Selection.Top] + L"\"";
		break;

	case kGridTop101BigDate:
		file_name = L"\"" + sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top] + L"\"";
		break;
	case kGridTop101SmallDate:
		file_name = L"\"" + sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top] + L"\"";
		break;
	}

	if (!file_name.empty())
	{
		WindowsUtility::ExecuteFile(file_name, L"");
	}
}


void __fastcall TFrameProperties::miSearchOpenCustomClick(TObject *Sender)
{
	std::wstring file_name = L"";

	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTemp:
		file_name = L"\"" + sgTemporary->Cells[0][sgTemporary->Selection.Top] + L"\"";
		break;

	case kGridTop101Big:
		file_name = L"\"" + sgTop101Big->Cells[0][sgTop101Big->Selection.Top] + L"\"";
		break;
	case kGridTop101Small:
		file_name = L"\"" + sgTop101Small->Cells[0][sgTop101Small->Selection.Top] + L"\"";
		break;

	case kGridTop101BigDate:
		file_name = L"\"" + sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top] + L"\"";
		break;
	case kGridTop101SmallDate:
		file_name = L"\"" + sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top] + L"\"";
		break;
	}

	if (!file_name.empty())
	{
		WindowsUtility::ExecuteFile(L"\"" + GSettingsHandler->General.CustomViewer + L"\"", file_name);
    }
}


void __fastcall TFrameProperties::miExploreDirectoryClick(TObject *Sender)
{
	std::wstring file_name = L"";

	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTemp:
		file_name = L"\"" + ExtractFilePath(sgTemporary->Cells[0][sgTemporary->Selection.Top]) + L"\"";
		break;
	case kGridTop101Big:
		file_name = L"\"" + ExtractFilePath(sgTop101Big->Cells[0][sgTop101Big->Selection.Top]) + L"\"";
		break;
	case kGridTop101Small:
		file_name = L"\"" + ExtractFilePath(sgTop101Small->Cells[0][sgTop101Small->Selection.Top]) + L"\"";
		break;

	case kGridTop101BigDate:
		file_name = L"\"" + ExtractFilePath(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top]) + L"\"";
		break;
	case kGridTop101SmallDate:
		file_name = L"\"" + ExtractFilePath(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top]) + L"\"";
		break;
	}

	if (!file_name.empty())
	{
		WindowsUtility::ExecuteFile(file_name, L"");
	}
}


void __fastcall TFrameProperties::miSFilePropertiesClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTemp:
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, sgTemporary->Cells[0][sgTemporary->Selection.Top].c_str());
		break;

	case kGridTop101Big:
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, sgTop101Big->Cells[0][sgTop101Big->Selection.Top].c_str());
		break;
	case kGridTop101Small:
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, sgTop101Small->Cells[0][sgTop101Small->Selection.Top].c_str());
		break;

	case kGridTop101BigDate:
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top].c_str());
		break;
	case kGridTop101SmallDate:
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top].c_str());
		break;
	}
}


void __fastcall TFrameProperties::miGenerateMD5Click(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTemp:
		OpenMD5Checksum(sgTemporary->Cells[0][sgTemporary->Selection.Top].c_str(),
						Utility::GetMD5(sgTemporary->Cells[0][sgTemporary->Selection.Top].c_str()));
		break;
	case kGridTop101Big:
		OpenMD5Checksum(sgTop101Big->Cells[0][sgTop101Big->Selection.Top].c_str(),
						Utility::GetMD5(sgTop101Big->Cells[0][sgTop101Big->Selection.Top].c_str()));
		break;
	case kGridTop101Small:
		OpenMD5Checksum(sgTop101Small->Cells[0][sgTop101Small->Selection.Top].c_str(),
						Utility::GetMD5(sgTop101Small->Cells[0][sgTop101Small->Selection.Top].c_str()));
		break;
	case kGridTop101BigDate:
		OpenMD5Checksum(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top].c_str(),
						Utility::GetMD5(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top].c_str()));
		break;
	case kGridTop101SmallDate:
		OpenMD5Checksum(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top].c_str(),
						Utility::GetMD5(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top].c_str()));
		break;
	}
}


void __fastcall TFrameProperties::miHexEditClick(TObject *Sender)
{
	std::wstring file_name = L"";

	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTemp:
		file_name = sgTemporary->Cells[0][sgTemporary->Selection.Top];
		break;

	case kGridTop101Big:
		file_name = sgTop101Big->Cells[0][sgTop101Big->Selection.Top];
		break;
	case kGridTop101Small:
		file_name = sgTop101Small->Cells[0][sgTop101Small->Selection.Top];
		break;

	case kGridTop101BigDate:
		file_name = sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top];
		break;
	case kGridTop101SmallDate:
		file_name = sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top];
		break;
	}

	if (!file_name.empty())
	{
		WindowsUtility::ExecuteFile(L"\"" + GSystemGlobal->ExePath + L"\\Be.HexEditor.exe\"", file_name);
	}
}


void __fastcall TFrameProperties::miZIPClick(TObject *Sender)
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
		int tag = sg->Tag;

		std::vector<std::wstring> data;

		switch (tag)
		{
		case kGridTop101Big:
		{
			for (int t = 1; t < sgTop101Big->RowCount; t++)
			{
				data.push_back(sgTop101Big->Cells[0][t].c_str());
			}
			break;
		}
		case kGridTop101Small:
			for (int t = 1; t < sgTop101Small->RowCount; t++)
			{
				data.push_back(sgTop101Small->Cells[0][t].c_str());
			}
			break;
		case kGridTop101BigDate:
			for (int t = 1; t < sgTop101BigDate->RowCount; t++)
			{
				data.push_back(sgTop101BigDate->Cells[0][t].c_str());
			}
			break;
		case kGridTop101SmallDate:
			for (int t = 1; t < sgTop101SmallDate->RowCount; t++)
			{
				data.push_back(sgTop101SmallDate->Cells[0][t].c_str());
			}
			break;
		}

		if (data.size() != 0)
		{
			if (!GXZip->Files(file_name, data, L"Compressing files..."))
			{
				ShowXDialog(GLanguageHandler->Text[kErrorCompressingFiles],
							GLanguageHandler->Text[kErrorCompressingFiles],
							XDialogTypeWarning);
			}
		}
		else
		{
			ShowXDialog(GLanguageHandler->Text[kWarning],
						GLanguageHandler->Text[kNoFilesToCompress],
						XDialogTypeWarning);
		}
	}
}


void __fastcall TFrameProperties::miSearchExportToCBClick(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTemp:
		GridUtility::CopyGridToClipboard(sgTemporary, 0);
		break;
	case kGridTop101Big:
		GridUtility::CopyGridToClipboard(sgTop101Big, 0);
		break;
	case kGridTop101Small:
		GridUtility::CopyGridToClipboard(sgTop101Small, 0);
		break;
	case kGridTop101BigDate:
		GridUtility::CopyGridToClipboard(sgTop101BigDate, 0);
		break;
	case kGridTop101SmallDate:
		GridUtility::CopyGridToClipboard(sgTop101SmallDate, 0);
		break;
	case kGridExtension:
		GridUtility::CopyGridToClipboard(sgExtensions, 0);
		break;
	}
}


void __fastcall TFrameProperties::miSaveAsClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCSVFiles] + L" (*.csv)|*.csv",
												   L".csv",
                                                   L"",
												   Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kReport] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* grid = (TStringGrid*)pum->PopupComponent;

		GridUtility::SaveGrid(grid, file_name);
	}
}
#pragma end_region


#pragma region PopupMenu_Table
void __fastcall TFrameProperties::miTableExportSelectedClick(TObject *Sender)
{
	if (sgCategories->Cells[7][sgCategories->Selection.Top] != L"")
	{
		std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kCategories] + L"_" + GLanguageHandler->Text[kExport]));

		if (!file_name.empty())
		{
			if (Utility::GetFileExtension(file_name) == L".csv")
			{
				CSVReportOptions csvro;

				csvro.FileName = file_name;
				csvro.Data  = kDataFileList;

				if (sgCategories->Cells[7][sgCategories->Selection.Top] != L"")
				{
					csvro.Category = sgCategories->Cells[7][sgCategories->Selection.Top].ToInt();
				}
				else
				{
					csvro.Category = kFileCategoriesOther;
				}

				std::vector<std::wstring> *data = new std::vector<std::wstring>;

				ReportCSV::Summary(csvro, data, DataSource);

				delete data;
			}
			else
			{
				GridUtility::SaveGrid(sgCategories, file_name);
			}
		}
	}
}


void __fastcall TFrameProperties::miTableZipClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
												  L".zip",
                                                  L"",
												  Utility::GetDefaultFileName(L".zip", GLanguageHandler->Text[kTable] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		std::vector<std::wstring> data;

		int CategoryId = GScanEngine->Data[DataSource].FindUser(sgCategories->Cells[7][sgCategories->Selection.Top].c_str());

		if (CategoryId != -1)
		{
			for (FileObject *file : GScanEngine->Data[DataSource].Files)
			{
				if (file->Category == CategoryId)
				{
					data.push_back(file->FullPath);
				}
			}

			if (data.size() != 0)
			{
				GXZip->Files(file_name, data, L"");
			}
		}
	}
}


void __fastcall TFrameProperties::miTableExportSelectedCBClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(sgCategories, 1);
}
#pragma end_region


#pragma region PopupMenu_TableDisplay
void __fastcall TFrameProperties::miTDShowAllClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puTableDisplay->Tag].Option[0].Value = 0;

	UpdateDisplay(puTableDisplay->Tag);
}


void __fastcall TFrameProperties::miTDNonZeroClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puTableDisplay->Tag].Option[0].Value = 1;

	UpdateDisplay(puTableDisplay->Tag);
}


void __fastcall TFrameProperties::miTDUserDefinedClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puTableDisplay->Tag].Option[0].Value = 2;

	UpdateDisplay(puTableDisplay->Tag);
}


void __fastcall TFrameProperties::miTD1Click(TObject *Sender)
{
	TMenuItem* mi = (TMenuItem*)Sender;

	mi->Checked = !mi->Checked;

	if (mi->Checked)
	{
		GSettingsHandler->TabDisplay[puTableDisplay->Tag].Option[mi->Tag + 1].Value = 1;
	}
	else
	{
		GSettingsHandler->TabDisplay[puTableDisplay->Tag].Option[mi->Tag + 1].Value = 0;
	}

	UpdateDisplay(puTableDisplay->Tag);
}
#pragma end_region


#pragma region PopupMenu_TreeDate
void __fastcall TFrameProperties::MenuItem20Click(TObject *Sender)
{
	if (FileExists(tvDates->Selected->Selected))
	{
		std::wstring file_name = tvDates->Selected->Text.c_str();

		WindowsUtility::ExecuteFile(L"\"" + file_name + L"\"", L"");
	}
}


void __fastcall TFrameProperties::MenuItem18Click(TObject *Sender)
{
	if (FileExists(tvDates->Selected->Text))
	{
        std::wstring file_name = tvDates->Selected->Text.c_str();

		WindowsUtility::ExecuteFile(L"\"" + GSettingsHandler->General.CustomViewer + L"\"", L"\"" + file_name + L"\"");
	}
}


void __fastcall TFrameProperties::miFileDatesExploreDirClick(TObject *Sender)
{
	std::wstring folder = ExtractFilePath(tvDates->Selected->Text).c_str();

	WindowsUtility::ExecuteFile(L"\"" + folder + L"\"", L"");
}


void __fastcall TFrameProperties::miFileDatesInfoClick(TObject *Sender)
{
	if (FileExists(tvDates->Selected->Text))
	{
		WindowsUtility::ShowFilePropertiesDialog(Application->Handle, tvDates->Selected->Text.c_str());
	}
}


void __fastcall TFrameProperties::miDGenerateMD5Click(TObject *Sender)
{
	if (FileExists(tvDates->Selected->Text))
	{
		//ShowMD5Checksum(tvDates.Selected.Text, TMD5.Generate(tvFile->Selected->Text));
	}
}


void __fastcall TFrameProperties::miFileDatesExportClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt",
												  L".txt",
												  L"",
												  Utility::GetDefaultFileName(L".txt", GLanguageHandler->Text[kFileDates] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		try
		{
			tvDates->SaveToFile(file_name.c_str());
		}
		catch(...)
		{
			ShowXDialog(GLanguageHandler->Text[kErrorSavingReport],
						GLanguageHandler->Text[kErrorSaving] + L" " + file_name + L".",
						XDialogTypeWarning);
		}
	}
}


void __fastcall TFrameProperties::miFileDatesExportCBClick(TObject *Sender)
{
	TreeUtility::CopyTreeToClipboard(tvDates);
}
#pragma end_region


#pragma region PopupMenu_Type
void __fastcall TFrameProperties::miTypeExportContentClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt",
												  L".txt",
												  L"",
												  Utility::GetDefaultFileName(L".txt", GLanguageHandler->Text[kType] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		tvTypes->SaveToFile(file_name.c_str());
	}
}


void __fastcall TFrameProperties::miTypeZipClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
												  L".zip",
												  L"",
												  Utility::GetDefaultFileName(L".zip", GLanguageHandler->Text[kFiles] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		std::vector<std::wstring> data;

		std::wstring category_name = L"";

		int category = -1;

		std::wstring node_title = tvTypes->Selected->Text.c_str();

		if (tvTypes->Selected->Parent == NULL)
		{
			auto index = node_title.find(L' ');

			if (index != std::wstring::npos)
			{
				category_name = node_title.substr(0, index - 1);

				std::transform(category_name.begin(), category_name.end(), category_name.begin(), ::tolower);

				category = GLanguageHandler->CategoryIdFromDescription(category_name);
			}
		}
		else
		{
			auto index = node_title.find(L':');

			if (index != std::wstring::npos)
			{
				category_name = node_title.substr(0, index - 1);

				std::transform(category_name.begin(), category_name.end(), category_name.begin(), ::tolower);

				category = GLanguageHandler->CategoryIdFromDescription(category_name);
			}
		}

		if (category != -1)
		{
			for (FileObject *file : GScanEngine->Data[DataSource].Files)
			{
				if (file->Category == category)
				{
					data.push_back(file->FullPath);
				}
			}

			if (data.size() != 0)
			{
				GXZip->Files(file_name, data, L"Compressing files...");
			}
			else
			{
				ShowXDialog(GLanguageHandler->Text[kWarning],
							GLanguageHandler->Text[kNoFilesToCompress],
							XDialogTypeWarning);
			}
		}
	}
}


void __fastcall TFrameProperties::miTypeExportCBClick(TObject *Sender)
{
	TreeUtility::CopyTreeToClipboard(tvTypes);
}
#pragma end_region


#pragma region PopupMenu_Users
void __fastcall TFrameProperties::miUsersExportSelectedClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::ExecuteReports(Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kUsers] + L"_" + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		if (Utility::GetFileExtension(file_name) == L".txt")
		{
			std::ofstream file(file_name);

			if (file)
			{
				file << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
				file << Formatting::to_utf8(GLanguageHandler->TextReport[11] + L"\n");
				file << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
				file << Formatting::to_utf8(GLanguageHandler->TextReport[12] + L"\n");
				file << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");

				if (GScanEngine->Data[DataSource].FileCount != 0)
				{
					for (int t = 0; t < GScanEngine->Data[DataSource].Users.size(); t++)
					{
						std::wstring str = Formatting::AddTrailing(L" " + GScanEngine->Data[DataSource].Users[t]->Name, 25, L' ');
						str += Formatting::AddLeading(std::to_wstring(GScanEngine->Data[DataSource].Users[t]->Count), 8, L' ');

						if (GScanEngine->Data[DataSource].FileCount != 0)
						{
							str += Formatting::AddLeading(Convert::DoubleToPercent(GScanEngine->Data[DataSource].Users[t]->Count / GScanEngine->Data[DataSource].FileCount), 6, L' ');
						}
						else
						{
							str += Formatting::AddLeading(L"100%", 6, L' ');
						}

						str += Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].Users[t]->Size), 11, L' ');

						if (GScanEngine->Data[DataSource].TotalSize != 0)
						{
							str += Formatting::AddLeading(Convert::DoubleToPercent(GScanEngine->Data[DataSource].Users[t]->Size / GScanEngine->Data[DataSource].TotalSize), 6, L' ');
						}
						else
						{
							str += Formatting::AddLeading(L"100%", 6, L' ');
						}

						file << Formatting::to_utf8(str + L"\n");
					}
				}

				file << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");

				file.close();
			}
			else
			{
				ShowXDialog(GLanguageHandler->Text[kErrorSavingReport],
							GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
							XDialogTypeWarning);
			}
		}
		else
		{
			GridUtility::SaveGrid(sgUsers, file_name);
		}
	}
}


void __fastcall TFrameProperties::miUsersZipClick(TObject *Sender)
{
	if (sgUsers->Cells[2][sgUsers->Selection.Top] != L"0")
	{
		std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
													  L".zip",
													  L"",
													  Utility::GetDefaultFileName(L".zip", GLanguageHandler->Text[kUsers] + L"_" + GLanguageHandler->Text[kExport]));

		if (!file_name.empty())
		{
			std::vector<std::wstring> data;

			int UserId = GScanEngine->Data[DataSource].FindUser(sgUsers->Cells[kUsersTableName][sgUsers->Selection.Top].c_str());

			if (UserId != -1)
			{
				for (FileObject *file : GScanEngine->Data[DataSource].Files)
				{
					if (file->Owner == UserId)
					{
						data.push_back(file->FullPath);
					}
				}

				if (data.size() != 0)
				{
					GXZip->Files(file_name, data, L"");
				}
			}
		}
	}
}


void __fastcall TFrameProperties::miUsersExportSelectedCBClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(sgUsers, 1);
}
#pragma end_region



void __fastcall TFrameProperties::miCopySelectedClick(TObject *Sender)
{
	std::wstring s = GetCopyMoveFolder(GLanguageHandler->Text[kCopyTo] + kEllipsis);

	if (!s.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
		int tag = sg->Tag;

		switch (tag)
		{
		case kGridTemp:
			CopyFile(sgTemporary->Cells[0][sgTemporary->Selection.Top].c_str(),
					 (s + Utility::SplitFileName(sgTemporary->Cells[0][sgTemporary->Selection.Top].c_str())).c_str(),
					 false);
			break;
		case kGridTop101Big:
			CopyFile(sgTop101Big->Cells[0][sgTop101Big->Selection.Top].c_str(),
					 (s + Utility::SplitFileName(sgTop101Big->Cells[0][sgTop101Big->Selection.Top].c_str())).c_str(),
					  false);
			break;
		case kGridTop101Small:
			CopyFile(sgTop101Small->Cells[0][sgTop101Small->Selection.Top].c_str(),
					 (s + Utility::SplitFileName(sgTop101Small->Cells[0][sgTop101Small->Selection.Top].c_str())).c_str(),
					 false);
			break;

		case kGridTop101BigDate:
			CopyFile(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top].c_str(),
					 (s + Utility::SplitFileName(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top].c_str())).c_str(),
					 false);
			break;
		case kGridTop101SmallDate:
			CopyFile(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top].c_str(),
					 (s + Utility::SplitFileName(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top].c_str())).c_str(),
					 false);
			break;
		}
	}
}


void __fastcall TFrameProperties::miCopyAllClick(TObject *Sender)
{
	std::wstring s = GetCopyMoveFolder(GLanguageHandler->Text[kCopyTo] + kEllipsis);

	if (!s.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
		int tag = sg->Tag;

		switch (tag)
		{
		case kGridTemp:
			for (int r = 1; r < sgTemporary->RowCount; r++)
			{
				std::wstring fn = Utility::SplitFileName(sgTemporary->Cells[0][r].c_str());

				CopyFile(sgTemporary->Cells[0][r].c_str(),
						 (s + fn).c_str(),
						 false);
			}
			break;
		case kGridTop101Big:
			for (int r = 1; r < sgTop101Big->RowCount; r++)
			{
				std::wstring fn = Utility::SplitFileName(sgTop101Big->Cells[0][r].c_str());

				CopyFile(sgTop101Big->Cells[0][r].c_str(),
						 (s + fn).c_str(),
						 false);
			}
			break;
		case kGridTop101Small:
			for (int r = 1; r < sgTop101Small->RowCount; r++)
			{
				std::wstring fn = Utility::SplitFileName(sgTop101Small->Cells[0][r].c_str());

				CopyFile(sgTop101Small->Cells[0][r].c_str(),
						 (s + fn).c_str(),
					     false);
			}
			break;
		}
	}
}


void __fastcall TFrameProperties::miMoveSelectedClick(TObject *Sender)
{
	std::wstring s = GetCopyMoveFolder(GLanguageHandler->Text[kMoveTo] + kEllipsis);

	if (!s.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
		int tag = sg->Tag;

		switch (tag)
		{
		case kGridTemp:
			MoveFileEx(sgTemporary->Cells[0][sgTemporary->Selection.Top].c_str(),
					   (s + Utility::SplitFileName(sgTemporary->Cells[0][sgTemporary->Selection.Top].c_str())).c_str(),
					   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		case kGridTop101Big:
			MoveFileEx(sgTop101Big->Cells[0][sgTop101Big->Selection.Top].c_str(),
					   (s + Utility::SplitFileName(sgTop101Big->Cells[0][sgTop101Big->Selection.Top].c_str())).c_str(),
					   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		case kGridTop101Small:
			MoveFileEx(sgTop101Small->Cells[0][sgTop101Small->Selection.Top].c_str(),
					   (s + Utility::SplitFileName(sgTop101Small->Cells[0][sgTop101Small->Selection.Top].c_str())).c_str(),
					   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		case kGridTop101BigDate:
			MoveFileEx(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top].c_str(),
					   (s + Utility::SplitFileName(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top].c_str())).c_str(),
					   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		case kGridTop101SmallDate:
			MoveFileEx(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top].c_str(),
					   (s + Utility::SplitFileName(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top].c_str())).c_str(),
					   MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		}
	}
}


void __fastcall TFrameProperties::miMoveAllClick(TObject *Sender)
{
	std::wstring s = GetCopyMoveFolder(GLanguageHandler->Text[kMoveTo] + kEllipsis);

	if (!s.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
		int tag = sg->Tag;

		switch (tag)
		{
		case kGridTemp:
			for (int r = 1; r < sgTemporary->RowCount; r++)
			{
				 MoveFileEx(sgTemporary->Cells[0][r].c_str(),
							(s + Utility::SplitFileName(sgTemporary->Cells[0][r].c_str())).c_str(),
							MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			}
			break;
		case kGridTop101Big:
			for (int r = 1; r < sgTop101Big->RowCount; r++)
			{
				 MoveFileEx(sgTop101Big->Cells[0][r].c_str(),
							(s + Utility::SplitFileName(sgTop101Big->Cells[0][r].c_str())).c_str(),
							MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			}
			break;
		case kGridTop101Small:
			for (int r = 1; r < sgTop101Small->RowCount; r++)
			{
				 MoveFileEx(sgTop101Small->Cells[0][r].c_str(),
							(s + Utility::SplitFileName(sgTop101Small->Cells[0][r].c_str())).c_str(),
							MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			}
			break;
		}
	}
}


void __fastcall TFrameProperties::miDeleteSelectedClick(TObject *Sender)
{
	if (MessageDlg(GLanguageHandler->Text[kDialog3].c_str(), mtWarning, mbYesNo, 0) == mrYes)
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
		int tag = sg->Tag;

		switch (tag)
		{
		case kGridTemp:
			WindowsUtility::SendToRecycleBin(sgTemporary->Cells[0][sgTemporary->Selection.Top].c_str());
			break;
		case kGridTop101Big:
			WindowsUtility::SendToRecycleBin(sgTop101Big->Cells[0][sgTop101Big->Selection.Top].c_str());
			break;
		case kGridTop101Small:
			WindowsUtility::SendToRecycleBin(sgTop101Small->Cells[0][sgTop101Small->Selection.Top].c_str());
			break;
		case kGridTop101BigDate:
			WindowsUtility::SendToRecycleBin(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top].c_str());
			break;
		case kGridTop101SmallDate:
			WindowsUtility::SendToRecycleBin(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top].c_str());
			break;
		}
	}
}


void __fastcall TFrameProperties::miDeleteAllClick(TObject *Sender)
{
	if (MessageDlg(GLanguageHandler->Text[kDialog4].c_str(), mtWarning, mbYesNo, 0) == mrYes)
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
		int tag = sg->Tag;

		switch (tag)
		{
		case kGridTemp:
			for (int r = 1; r < sgTemporary->RowCount; r++)
			{
				WindowsUtility::SendToRecycleBin(sgTemporary->Cells[0][r].c_str());
			}
			break;
		case kGridTop101Big:
			for (int r = 1; r < sgTop101Big->RowCount; r++)
			{
				WindowsUtility::SendToRecycleBin(sgTop101Big->Cells[0][r].c_str());
			}
			break;
		case kGridTop101Small:
			for (int r = 1; r < sgTop101Small->RowCount; r++)
			{
				WindowsUtility::SendToRecycleBin(sgTop101Small->Cells[0][r].c_str());
			}
			break;
		}
	}
}
