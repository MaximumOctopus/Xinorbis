//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameProperties.h"
#include "XFormChartOptions.h"

#include "ChartUtility.h"
#include "Convert.h"
#include "FileExtensionHandler.h"
#include "GridUtility.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "TreeUtility.h"
#include "Utility.h"
#include "WindowsUtility.h"

#include "TabUiTypes.h"

extern FileExtensionHandler* GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SettingsHandler* GSettingsHandler;
extern SystemGlobal* GSystemGlobal;

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

	// tabs
	InitCategoriesTab();
	InitTypesTab();
	InitExtensionsTab();
	InitFoldersTab();
	InitMagnitudeTab();
	InitDatesTab();
	InitHistoryTab();
	InitTop101Tab();
	InitUsersTab();
	InitTempTab();
	InitLengthTab();

	// extensions
	cbExtensionsAll->Caption = GLanguageHandler->Text[kShowCategorised].c_str();
	cbExtensionsOther->Caption = GLanguageHandler->Text[kShowUncategorised].c_str();
	cbExtensionsCustom->Caption = GLanguageHandler->Text[kShowCustom].c_str();
	cbExtensionsColourCode->Caption = GLanguageHandler->Text[kColourCode].c_str();
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
	BuildCategoriesTable();
	BuildCategoriesChart();

	TabUiTypes::Tree(tvTypes, 2);
	rbTypesBySizeClick(NULL);

	BuildExtensionsTable();

    Top101UpdateDropDowns();

	BuildMagnitudeTable();
}


#pragma region Tab_Generic
void __fastcall TFrameProperties::sbCategoriesPieClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	sb->Down = true;

	switch (sb->Tag)
	{
	case 1:
		ChartUtility::ChangeChartToPie(vtcCategories);
		//GXGuiUtil.SetPieBarImages(sbCategoriesPie, sbCategoriesBar);
		break;
	case 2:
		ChartUtility::ChangeChartToPie(vtcTypes);
		//GXGuiUtil.SetPieBarImages(sbTreePie, sbTreeBar);
		break;
	case 3:
		ChartUtility::ChangeChartToPie(vtcFolders);
		//   GXGuiUtil.SetPieBarImages(sbDirListPie, sbDirListBar);
		break;
	case 4 :
		ChartUtility::ChangeChartToPie(vtcMagnitude);
		//   GXGuiUtil.SetPieBarImages(sbMagnitudePie, sbMagnitudeBar);
		break;
	case 8:
		ChartUtility::ChangeChartToPie(vtcFileDates);
		//   GXGuiUtil.SetPieBarImages(sbFileDatesPie, sbFileDatesBar);
		break;
	case 11:
		ChartUtility::ChangeChartToPie(vtcUsers);
		//   GXGuiUtil.SetPieBarImages(sbUsersPie, sbUsersBar);
		break;
	case 12 :
		ChartUtility::ChangeChartToPie(vtcLengths);
		//   GXGuiUtil.SetPieBarImages(sbLengthPie, sbLengthBar);
		break;
	}
}


void __fastcall TFrameProperties::sbCategoriesBarClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	sb->Down = true;

	switch (sb->Tag)
	{
	case 1:
		ChartUtility::ChangeChartToHorizontalBar(vtcCategories, false);
//		   GXGuiUtil.SetPieBarImages(sbCategoriesPie, sbCategoriesBar);
		break;
	case 2:
		ChartUtility::ChangeChartToHorizontalBar(vtcTypes, false);
//		   GXGuiUtil.SetPieBarImages(sbTreePie, sbTreeBar);
		break;
	case 3:
		ChartUtility::ChangeChartToHorizontalBar(vtcFolders, true);
//		   GXGuiUtil.SetPieBarImages(sbDirListPie, sbDirListBar);
		break;
	case 4:
		ChartUtility::ChangeChartToHorizontalBar(vtcMagnitude, false);
//		   GXGuiUtil.SetPieBarImages(sbMagnitudePie, sbMagnitudeBar);
		break;
	case 8:
		ChartUtility::ChangeChartToHorizontalBar(vtcFileDates, false);
//		   GXGuiUtil.SetPieBarImages(sbFileDatesPie, sbFileDatesBar);
		break;
	case 11:
		ChartUtility::ChangeChartToHorizontalBar(vtcUsers, false);
//		   GXGuiUtil.SetPieBarImages(sbUsersPie, sbUsersBar);
		break;
	case 12:
		ChartUtility::ChangeChartToHorizontalBar(vtcLengths, false);
//		   GXGuiUtil.SetPieBarImages(sbLengthPie, sbLengthBar);
		break;
	}
}


void TFrameProperties::RefreshTableDisplay(int tab)
{
    // to do
}
#pragma end_region


#pragma region Tab_Categories
void TFrameProperties::InitCategoriesTab()
{
	rbCategoriesBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbCategoriesByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sgCategories->RowCount = __FileCategoriesCount + 1;
}


void TFrameProperties::BuildCategoriesTable()
{
	int Row = 1;

	for (int t = 0; t < __FileCategoriesCount; t++)
	{
		sgCategories->Cells[1][Row] = GScanEngine->Data.ExtensionSpread[t].Name.c_str();
		sgCategories->Cells[2][Row] = GScanEngine->Data.ExtensionSpread[t].Count;
		sgCategories->Cells[3][Row] = GScanEngine->Data.ExtensionSpread[t].PercentCountString.c_str();
		sgCategories->Cells[5][Row] = Convert::ConvertToUsefulUnit(GScanEngine->Data.ExtensionSpread[t].Size).c_str();
		sgCategories->Cells[6][Row] = GScanEngine->Data.ExtensionSpread[t].PercentSizeString.c_str();

		Row++;
	}
}


void TFrameProperties::BuildCategoriesChart()
{
	if (GScanEngine->Data.FileCount > 0)
	{
		// == don't show size details if the chart is in quantity mode =============
///		if oChart->Tag = fQuantity then
//		  ChartLabelOption = 0;
		// =========================================================================

		vtcCategories->SeriesList->Items[0]->Clear();
		vtcCategories->Legend->TextStyle = ltsPlain;
//		    if XSettings.LastScanMultiple then
//      oChart.Title.Text.Strings[0] = GLanguageHandler->Text[kMultipleFolders]
//    else
      	vtcCategories->Title->Text->Strings[0] = GScanEngine->Path.String.c_str();

		for (int t = 0; t < __FileCategoriesCount; t++)
		{
			if (GScanEngine->Data.ExtensionSpread[t].Count != 0)
			{
				std::wstring s = L"";

				s = GScanEngine->Data.ExtensionSpread[t].Name;

//        case ChartLabelOption of
//          CLabelOptionDefault        : s = TypeDescriptions[t];
//          CLabelOptionMostConvenient : s = TConvert.ConvertToUsefulUnit(GScanEngine[aDataIndex].ExtensionSpread[t, fSize]);
//          CLabelOptionKilobyte       : s = TConvert.ConvertToStaticUnit(GScanEngine[aDataIndex].ExtensionSpread[t, fSize], unitKB);
//          CLabelOptionMegabyte       : s = TConvert.ConvertToStaticUnit(GScanEngine[aDataIndex].ExtensionSpread[t, fSize], unitMB);
//          CLabelOptionGigabyte       : s = TConvert.ConvertToStaticUnit(GScanEngine[aDataIndex].ExtensionSpread[t, fSize], unitGB);
//        }

				vtcCategories->SeriesList->Items[0]->Add((double)GScanEngine->Data.ExtensionSpread[t].Count,
														 s.c_str(),
														 TColor(0xff8844));//GSystemGlobal.FileCategoryColors[t]);
			}
		}
	}
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
#pragma end_region


#pragma region Tab_Types
void TFrameProperties::InitTypesTab()
{
	rbTypesBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbTypesByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();
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

	TabUiTypes::Chart(vtcTypes, 0); // to do XSettings.Charts.Options.LabelOptions);
}


void __fastcall TFrameProperties::tvTypesClick(TObject *Sender)
{
	if (GScanEngine->Data.FileCount != 0)
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

		for (int t = 0; t < __FileCategoriesCount; t++)
		{
			if (text.find(GLanguageHandler->TypeDescriptions[t]) != std::wstring::npos)
			{
				GSettingsHandler->TabInternal.TreeViewChartIndex = t;
				break;
            }
		}

		TabUiTypes::Chart(vtcTypes, 0); //XSettings.Charts.Options.LabelOptions);
	}
}
#pragma end_region


#pragma region Tab_Extensions
void TFrameProperties::InitExtensionsTab()
{
	cbExtensionsAll->Caption = GLanguageHandler->Text[kShowCategorised].c_str();
	cbExtensionsCustom->Caption = GLanguageHandler->Text[kShowCustom].c_str();
	cbExtensionsOther->Caption = GLanguageHandler->Text[kShowUncategorised].c_str();
	cbExtensionsColourCode->Caption = GLanguageHandler->Text[kColourCode].c_str();
}


void TFrameProperties::BuildExtensionsTable()
{
	int row = 1;

	for (int t = 0; t < GFileExtensionHandler->Extensions.size(); t++)
	{
		if (GFileExtensionHandler->Extensions[t]->Count != 0)
		{
			sgExtensions->Cells[1][row] = GFileExtensionHandler->Extensions[t]->Name.c_str();
			sgExtensions->Cells[1][row] = GFileExtensionHandler->Extensions[t]->Count;
			sgExtensions->Cells[2][row] = GFileExtensionHandler->Extensions[t]->PercentCountString.c_str();
			sgExtensions->Cells[4][row] = Convert::ConvertToUsefulUnit(GFileExtensionHandler->Extensions[t]->Size).c_str();
			sgExtensions->Cells[5][row] = GFileExtensionHandler->Extensions[t]->PercentSizeString.c_str();
			sgExtensions->Cells[7][row] = GFileExtensionHandler->Extensions[t]->Description.c_str();

			sgExtensions->RowCount++;

			row++;
		}
	}

	if (sgExtensions->RowCount != 2)
	{
		sgExtensions->RowCount--;
	}
}
#pragma end_region


#pragma region Tab_Folders
void TFrameProperties::InitFoldersTab()
{
	rbFoldersBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbFoldersByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sbFoldersMoreDetail->Caption = (GLanguageHandler->Text[kMoreDetail] + kEllipsis).c_str();
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
// to do			DoExplore(FSource,GScanDetails[FSource].ScanPath)
		}
		else
		{
//			DoExplore(FSource,GScanDetails[FSource].ScanPath + sgDirList.Cells[1, row] + '\');
		}
	}
}
#pragma end_region


#pragma region Tab_Magnitude
void TFrameProperties::InitMagnitudeTab()
{
	rbMagnitudeBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbMagnitudeByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();
}


void TFrameProperties::BuildMagnitudeTable()
{
	for (int t = 0; t < __MagnitudesCount; t++)
	{
		sgMagnitude->Cells[1][t + 1] = GScanEngine->Data.Magnitude[t].Name.c_str();
		sgMagnitude->Cells[2][t + 1] = GScanEngine->Data.Magnitude[t].Count;
		sgMagnitude->Cells[3][t + 1] = GScanEngine->Data.Magnitude[t].PercentCountString.c_str();
		sgMagnitude->Cells[5][t + 1] = GScanEngine->Data.Magnitude[t].Size;
		sgMagnitude->Cells[6][t + 1] = GScanEngine->Data.Magnitude[t].PercentSizeString.c_str();
	}
}
#pragma end_region


#pragma region Tab_Dates
void TFrameProperties::InitDatesTab()
{
	rbDatesBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbDatesByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	sbDatesCollapseNodes->Caption = GLanguageHandler->Text[kCollapseNodes].c_str();
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

	lHistoryUser->Caption = GLanguageHandler->Text[kUsers].c_str();

	sbHistoryRefresh->Caption = GLanguageHandler->Text[kRefresh].c_str();
	cbHistoryAutoRefresh->Caption = GLanguageHandler->Text[kAutoRefresh].c_str();
}
#pragma end_region


#pragma region Tab_Top_101
void TFrameProperties::InitTop101Tab()
{
	cbTop101SizeColourCode->Caption = GLanguageHandler->Text[kColourCode].c_str();
	cbTop101DateColourCode->Caption = GLanguageHandler->Text[kColourCode].c_str();

	cbTop101DateDate->Items->Clear();
	cbTop101DateDate->Items->Add(GLanguageHandler->Text[kCreated].c_str());
	cbTop101DateDate->Items->Add(GLanguageHandler->Text[kAccessed].c_str());
	cbTop101DateDate->Items->Add(GLanguageHandler->Text[kModified].c_str());
	cbTop101DateDate->ItemIndex = 0;
}


void TFrameProperties::Top101UpdateDropDowns()
{
	cbTop101SizeUser->Items->Clear();
	cbTop101SizeUser->Items->Add(GLanguageHandler->Text[kAllUsers].c_str());

	cbTop101DateUser->Items->Clear();
	cbTop101DateUser->Items->Add(GLanguageHandler->Text[kAllUsers].c_str());

	for (int t = 0; t < GScanEngine->Data.Users.size(); t++)
	{
		cbTop101SizeUser->Items->Add(GScanEngine->Data.Users[t].Name.c_str());
		cbTop101DateUser->Items->Add(GScanEngine->Data.Users[t].Name.c_str());
	}

	cbTop101SizeUser->ItemIndex = 0;
	cbTop101DateUser->ItemIndex = 0;
}
#pragma end_region


#pragma region Tab_NullFiles
void TFrameProperties::InitNullTab()
{
}
#pragma end_region


#pragma region Tab_Users
void TFrameProperties::InitUsersTab()
{
	rbUsersBySize->Caption  = GLanguageHandler->Text[kBySize].c_str();
	rbUsersByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();
}
#pragma end_region


#pragma region Tab_Temp
void TFrameProperties::InitTempTab()
{
	rbTempBySize->Caption  = GLanguageHandler->Text[kBySize].c_str();
	rbTempByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();
}
#pragma end_region


#pragma region Tab_Length
void TFrameProperties::InitLengthTab()
{
	rbLengthBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbLengthByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	miLengthShowAll->Caption = GLanguageHandler->Text[kShowAll].c_str();
	miLengthNonZero->Caption = GLanguageHandler->Text[kShowNonZero].c_str();
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

	for (int r = 1; r < sgExtensions->RowCount; r++)
	{
//		if (sgExtensions->RowSelect[r])      to do
//		{
 //			FileExtension tfx;
		// //	tfx.Name = sgExtensions->Cells[0][r];
		//	tfx.Category = idx;

		//	FileExtensionsObject.CategoryExtensions.Add(tfx);
//		}
	}

	//FileExtensionsObject.SaveFileExtensionLists(GSettingsHandler->Custom.SettingsSaveLocation);
}


void __fastcall TFrameProperties::miShowOtherFilesClick(TObject *Sender)
{
	std::wstring search = sgExtensions->Cells[0][sgExtensions->Selection.Top].c_str();

	if (!search.empty())
	{
		if (OnNewSearch)
		{
			OnNewSearch(L"." + search);
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
		GridUtility::CopyGridToClipboard(0, sgTemporary);
		break;
	case kGridTop101Big:
		GridUtility::CopyGridToClipboard(0, sgTop101Big);
		break;
	case kGridTop101Small:
		GridUtility::CopyGridToClipboard(0, sgTop101Small);
		break;
	case kGridTop101BigDate:
		GridUtility::CopyGridToClipboard(0, sgTop101BigDate);
		break;
	case kGridTop101SmallDate:
		GridUtility::CopyGridToClipboard(0, sgTop101SmallDate);
		break;
	case kGridExtension:
		GridUtility::CopyGridToClipboard(0, sgExtensions);
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
//		if (Sender.ClassType = TMenuItem)
//		{
//	TO DO	sbFolderConfig->Tag = TMenuItem(Sender)->Tag;
//		}
	}

	if (rbFoldersBySize->Checked)
	{
		vtcFolders->Tag = 1;
	}
	else
	{
		vtcFolders->Tag = 0;
	}

	// TO DO DisplayUtility.InformationTabFolderChart(FSource, sbFoldersConfig->Tag, vtcFolders, GSettingsHandler->Charts.Options.LabelOptions);
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
		std::wstring path = GScanEngine->Path.String + sgFolders->Cells[1][sgFolders->Selection.Top].c_str() + L"\"";

		if (OnScanWithNewPath)
		{
			OnScanWithNewPath(false, path);
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
				WindowsUtility::ExecuteFile(L"\"" + GScanEngine->Path.String + L"\"", L"");
			}
			else
			{
				WindowsUtility::ExecuteFile(L"\"" + GScanEngine->Path.String + sgFolders->Cells[1][sgFolders->Selection.Top].c_str() + L"\"", L"");
			}
		}
	}
}


void __fastcall TFrameProperties::miFolderExportSelectedCBClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(1, sgFolders);
}
#pragma end_region


#pragma region PopupMenu_Length
void __fastcall TFrameProperties::miLengthShowAllClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puLength->Tag].Option[0].Value = 0;

	RefreshTableDisplay(puLength->Tag);
}


void __fastcall TFrameProperties::miLengthNonZeroClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puLength->Tag].Option[0].Value = 1;

	RefreshTableDisplay(puLength->Tag);
}
#pragma end_region


#pragma region PopupMenu_Magnitude
void __fastcall TFrameProperties::miMagnitudeExportClick(TObject *Sender)
{
/* to do        var
  wp : TextFile;
  str : string;
  t, lDataIndex : integer;
  grid : TAdvStringGrid;
  lFileName : string;

 {
  lDataIndex = FSource;
  grid       = sgMagnitude;

  Assert(grid != NULL, 'miMagnitudeExportClick :: Grid is NULL');

  lFileName = SaveDialog::ExecuteReports(TUtility.GetDefaultFileName('.csv", GLanguageHandler->Text[kMagnitude] + L"_' + GLanguageHandler->Text[kExport]));

  if lFileName != L"" then {
    if UpperCase(ExtractFileExt(lFileName)) = '.TXT' then {
      AssignFile(wp, lFileName);

      {$I-}
      Rewrite(wp);
      {$I+}

      if (IOResult != 0) then {
		ShowXDialog(GLanguageHandler->Text[kErrorSavingReport],
					GLanguageHandler->Text[kErrorSaving] + L" " + lFileName + L".",
                    XDialogTypeWarning);
      end
      else {
        //-- file magnitudes ----------------------------------------------
        writeln(wp, TextReport[0]);
        writeln(wp, TextReport[7]);
        writeln(wp, TextReport[0]);
        writeln(wp, TextReport[2]);
        writeln(wp, TextReport[0]);

		if GScanEngine[lDataIndex].FileCount != 0 then {
          for t = 0 to __MagnitudesCount do {
			str = TXFormatting.AddTrailing(' ' + magNULLabels[t], 25, L" ");
			str = str + TXFormatting.AddLeading(IntToStr(GScanEngine[lDataIndex].Magnitude.Data[Category_MagnitudeAll, t, 0]), 8, L" ");
            str = str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanEngine[lDataIndex].Magnitude.Data[Category_MagnitudeAll, t, 0] / GScanEngine[lDataIndex].FileCount), 6, ' ');
			str = str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanEngine[lDataIndex].Magnitude.Data[Category_MagnitudeAll, t, 1]), 11, L" ");

            if GScanEngine[lDataIndex].TotalSize != 0 then
              str = str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanEngine[lDataIndex].Magnitude.Data[Category_MagnitudeAll, t, 1] /GScanEngine[lDataIndex].TotalSize), 6, ' ')
            else
			  str = str + TXFormatting.AddLeading(L"100%", 6, L" ");

            writeln(wp, str);
		  }
        }

		writeln(wp, GLanguageHandler->Text[kFavourite]);
        writeln(wp, L"");

        CloseFile(wp);
      }
    end
    else {
      GridUtility::SaveGrid(grid, lFileName);
    }
  }   */
}


void __fastcall TFrameProperties::miMagnitudeZipClick(TObject *Sender)
{/*
	if (!XSettings.ProcessWindowsVisible)
	{
		std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
													  L".zip",
													  Utility::GetDefaultFileName(L".zip", GLanguageHandler->Text[kMagnitude] + L"_" + GLanguageHandler->Text[kExport]));

		if (!file_name.empty())
		{
			XinorbisZip.ZipFilesOfType(FSource, file_name, 3, L"", sgMagnitude->Selection.Top);
		}
	} */
}


void __fastcall TFrameProperties::miMagnitudeExportCBClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(1, sgMagnitude);
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
		//ndowsUtility::ShowFilePropertiesDialog(Application->Handle,
		//						         sgNullFiles->Cells[0][sgNullFiles->Selection.Top]);
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
		//WindowsUtility::ShowFilePropertiesDialog(Application->Handle, sgNullFolders->Cells[0][sgNullFolders->Selection.Top]);
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
//		WindowsUtility::ShowFilePropertiesDialog(Application.Handle, sgTemporary->Cells[0][sgTemporary->Selection.Top]);
		break;

	case kGridTop101Big:
//		WindowsUtility::ShowFilePropertiesDialog(Application.Handle, sgTop101Big->Cells[0][sgTop101Big->Selection.Top]);
		break;
	case kGridTop101Small:
//		WindowsUtility::ShowFilePropertiesDialog(Application.Handle, sgTop101Small->Cells[0][sgTop101Small->Selection.Top]);
		break;

	case kGridTop101BigDate:
//		WindowsUtility::ShowFilePropertiesDialog(Application.Handle, sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top]);
		break;
	case kGridTop101SmallDate:
//		WindowsUtility::ShowFilePropertiesDialog(Application.Handle, sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top]);
		break;
	}
}


void __fastcall TFrameProperties::miGenerateMD5Click(TObject *Sender)
{ /* to do
	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTemp:
		ShowMD5Checksum(sgTemporary->Cells[0][sgTemporary->Selection.Top], TMD5.Generate(sgTemporary->Cells[0][sgTemporary->Selection.Top]));

	case kGridTop101Big:
		ShowMD5Checksum(sgTop101Big->Cells[0][sgTop101Big->Selection.Top], TMD5.Generate(sgTop101Big->Cells[0][sgTop101Big->Selection.Top]));
		break;
	case kGridTop101Small:
		ShowMD5Checksum(sgTop101Small->Cells[0][sgTop101Small->Selection.Top], TMD5.Generate(sgTop101Small->Cells[0][sgTop101Small->Selection.Top]));
		break;

	case kGridTop101BigDate:
		ShowMD5Checksum(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top], TMD5.Generate(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top]));
		break;
	CGridTop101SmallDate:
		ShowMD5Checksum(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top], TMD5.Generate(sgTop101SmallDate->Cells[0, sgTop101SmallDate->Selection.Top]));
		break;
	}     */
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
{/*
  lFileName = SaveDialog::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
                                    '.zip",
									TUtility.GetDefaultFileName('.zip", GLanguageHandler->Text[kTop101] + L"_' + GLanguageHandler->Text[kExport]));

  if lFileName != L"" then {

	lZipCount = -1;

	TMenuItem* mi = (TMenuItem*)Sender;
	TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
	TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
	int tag = sg->Tag;

	switch (tag)
	{
	case kGridTop101Big:
		lZipCount = XinorbisZip.ZipAllFiles(lFileName, TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag, sgTop101Big, 0);
	case kGridTop101Small:
		lZipCount = XinorbisZip.ZipAllFiles(lFileName, TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag, sgTop101Small, 0);
	case kCGridTop101BigDate:
		lZipCount = XinorbisZip.ZipAllFiles(lFileName, TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag, sgTop101BigDate, 0);
	case kGridTop101SmallDate:
		lZipCount = XinorbisZip.ZipAllFiles(lFileName, TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag, sgTop101SmallDate, 0);
	}

	if lZipCount = -1)
	{
	  ShowXDialog(GLanguageHandler->Text[kErrorCompressingFiles],
				  GLanguageHandler->Text[kErrorCompressingFiles],
				  XDialogTypeWarning)
	}
	else if lZipCount = 0 then
	{
	  ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kNoFilesToCompress], XDialogTypeWarning);
	} */
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
		GridUtility::CopyGridToClipboard(0, sgTemporary);
		break;
	case kGridTop101Big:
		GridUtility::CopyGridToClipboard(0, sgTop101Big);
		break;
	case kGridTop101Small:
		GridUtility::CopyGridToClipboard(0, sgTop101Small);
		break;
	case kGridTop101BigDate:
		GridUtility::CopyGridToClipboard(0, sgTop101BigDate);
		break;
	case kGridTop101SmallDate:
		GridUtility::CopyGridToClipboard(0, sgTop101SmallDate);
		break;
	case kGridExtension:
		GridUtility::CopyGridToClipboard(0, sgExtensions);
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
/*     var
  CSVOptions : TCSVReportOptions;
  lFileName : string;
  lCSVReport : TStringList;

{
  if sgMainReport->Cells[7, sgMainReport->Selection.Top] != L"" then {
	lFileName = SaveDialog::ExecuteReports(TUtility.GetDefaultFileName('.csv", GLanguageHandler->Text[kCategories] + L"_' + GLanguageHandler->Text[kExport]));

	if lFileName != L"" then {

	  if UpperCase(ExtractFileExt(lFileName)) = '.CSV' then {
		 CSVOptions.FileName = lFileName;
		 CSVOptions.CSVData  = CDataFileList;
		if sgMainReport->Cells[7, sgMainReport->Selection.Top] != L"" then
		  CSVOptions.Category = StrToInt(sgMainReport->Cells[7, sgMainReport->Selection.Top])
		else
		  CSVOptions.Category = __FileCategoriesOther;

		lCSVReport = TStringList.Create;

		GReportCSV.GenerateCSVReport(FSource, lCSVReport, CSVOptions, LayoutUnknown);

		lCSVReport.Free;
	  end
	  else {
		GridUtility::SaveGrid(sgMainReport, lFileName);
	  }
	}
  } TO DO */
}


void __fastcall TFrameProperties::miTableZipClick(TObject *Sender)
{/*
	std::wstring file_name = SaveDialog::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
							'.zip",
							TUtility.GetDefaultFileName('.zip", GLanguageHandler->Text[kTable] + L"_' + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
		if sgUsers->Cells[2, sgUsers->Selection.Top] != '0')
		{
			XinorbisZip.ZipFilesOfType(FSource, lFileName, 4, sgUsers->Cells[1, sgUsers->Selection.Top], 0);
		}
	}*/
}


void __fastcall TFrameProperties::miTableExportSelectedCBClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(1, sgCategories);
}
#pragma end_region


#pragma region PopupMenu_TableDisplay
void __fastcall TFrameProperties::miTDShowAllClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puTableDisplay->Tag].Option[0].Value = 0;

	RefreshTableDisplay(puTableDisplay->Tag);
}


void __fastcall TFrameProperties::miTDNonZeroClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puTableDisplay->Tag].Option[0].Value = 1;

	RefreshTableDisplay(puTableDisplay->Tag);
}


void __fastcall TFrameProperties::miTDUserDefinedClick(TObject *Sender)
{
	GSettingsHandler->TabDisplay[puTableDisplay->Tag].Option[0].Value = 2;

	RefreshTableDisplay(puTableDisplay->Tag);
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

	RefreshTableDisplay(puTableDisplay->Tag);
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
		//WindowsUtility::ShowFilePropertiesDialog(Application.Handle, tvFileDates.Selected.Text);
	}
}


void __fastcall TFrameProperties::miDGenerateMD5Click(TObject *Sender)
{
	if (FileExists(tvDates->Selected->Text))
	{
		//ShowMD5Checksum(tvFileDates.Selected.Text, TMD5.Generate(tvFile->Selected->Text));
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
		  // to do tvDates->SaveToFile(file_name);
		}
		catch(...)
		{
			//ShowXDialog(GLanguageHandler->Text[kErrorSavingReport],
		   //				GLanguageHandler->Text[kErrorSaving] + L" " + file_name + L".",
		   //				XDialogTypeWarning);
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
		// to do tvTypes->SaveToFile(file_name);
	}
}


void __fastcall TFrameProperties::miTypeZipClick(TObject *Sender)
{ /*
  lFileName = SaveDialog::Execute(GLanguageHandler->Text[kCompressedFiles] + L" (*.zip)|*.zip",
									L".zip",
									TUtility.GetDefaultFileName(L".zip", GLanguageHandler->Text[kFiles] + L"_" + GLanguageHandler->Text[kExport]));

  if lFileName != L"" then {

    if tvFileTypes.Selected.Parent = NULL then {
      s = L"";
      t = 1;

      while tvFileTypes.Selected.Text[t] != ' ' do {
        s = s + tvFileTypes.Selected.Text[t];

        inc(t);
      }

      idx = -1;
      s   = TXFormatting.FilterTags(s); // removes html formatting from parent node text

      for t = 1 to __FileCategoriesCount do
        if UpperCase(TypeDescriptions[t]) = UpperCase(s) then
          idx = t;

      if idx != -1 then
        XinorbisZip.ZipFilesOfType(FSource, lFileName, 2, L"", idx);
    end
	else {
      s = L"";
      t = 1;

      while tvFileTypes.Selected.Text[t] != ':' do {
        s = s + tvFileTypes.Selected.Text[t];

        inc(t);
      }

      XinorbisZip.ZipFilesOfType(FSource, lFileName, 1, UpperCase(s), -1);
    }
  }     */
}


void __fastcall TFrameProperties::miTypeExportCBClick(TObject *Sender)
{
	TreeUtility::CopyTreeToClipboard(tvTypes);
}
#pragma end_region


#pragma region PopupMenu_Users
void __fastcall TFrameProperties::miUsersExportSelectedClick(TObject *Sender)
{  /*
		var
  str : string;
  wp : TextFile;
  t, lDataIndex : integer;
  grid : TAdvStringGrid;
  lFileName : string;

  lDataIndex = FSource;
  grid       = sgUsers;

  Assert(grid != NULL, 'miUsersExportSelectedClick :: Grid is NULL');

	std::wstring file_name = SaveDialog::ExecuteReports(TUtility.GetDefaultFileName('.csv", GLanguageHandler->Text[kUsers] + L"_' + GLanguageHandler->Text[kExport]));

	if (!file_name.empty())
	{
	if UpperCase(ExtractFileExt(lFileName)) = '.TXT' then {
	  AssignFile(wp, lFileName);

	  {$I-}
      Rewrite(wp);

	  if IOResult != 0 then {
		ShowXDialog(GLanguageHandler->Text[kErrorSavingReport],
					GLanguageHandler->Text[kErrorSaving] + L" "' + lFileName + L"".",
                    XDialogTypeWarning);
	  end
	  else {
		writeln(wp, TextReport[0]);
        writeln(wp, TextReport[11]);
		writeln(wp, TextReport[0]);
        writeln(wp, TextReport[12]);
		writeln(wp, TextReport[0]);

		if GScanEngine[lDataIndex].FileCount != 0 then {
          for t = 0 to GScanEngine[lDataIndex].Users.Count - 1 do {
			str = TXFormatting.AddTrailing(' ' + GScanEngine[lDataIndex].Users[t].Name, 25, ' ');
			str = str + TXFormatting.AddLeading(IntToStr(GScanEngine[lDataIndex].Users[t].Data[XUserCount]), 8, ' ');

            if (GScanEngine[lDataIndex].FileCount != 0) then
			  str = str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanEngine[lDataIndex].Users[t].Data[XUserCount] / GScanEngine[lDataIndex].FileCount), 6, ' ')
			else
			  str = str + TXFormatting.AddLeading('100%", 6, ' ');

			str = str + TXFormatting.AddLeading(TConvert.ConvertToUsefulUnit(GScanEngine[lDataIndex].Users[t].Data[XUserSize]), 11, ' ');
			if GScanEngine[lDataIndex].TotalSize != 0 then
			  str = str + TXFormatting.AddLeading(TConvert.RealToPercent(GScanEngine[lDataIndex].Users[t].Data[XUserSize] / GScanEngine[lDataIndex].TotalSize), 6, ' ')
			else
			  str = str + TXFormatting.AddLeading('100%", 6, ' ');

            writeln(wp, str);
          }
		}

        writeln(wp, TextReport[0]);

		CloseFile(wp);
      }

	  {$I+}
	end
	else {
	  GridUtility::SaveGrid(grid, lFileName);
	}
  }   */
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
// to do			XinorbisZip.ZipFilesOfType(FSource, file_name, 4, sgUsers->Cells[1, sgUsers->Selection.Top], 0);
		}
	}
}


void __fastcall TFrameProperties::miUsersExportSelectedCBClick(TObject *Sender)
{
	GridUtility::CopyGridToClipboard(1, sgUsers);
}
#pragma end_region



void __fastcall TFrameProperties::miCopySelectedClick(TObject *Sender)
{ /*
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
			CopyFile(PChar(sgTemporary->Cells[0, sgTemporary->Selection.Top]),
					  PChar(s + ExtractFileName(sgTemporary->Cells[0][sgTemporary->Selection.Top])),
					 False);
			break;
		case kGridTop101Big:
			 CopyFile(PChar(sgTop101Big->Cells[0, sgTop101Big->Selection.Top]),
					  PChar(s + ExtractFileName(sgTop101Big->Cells[0][sgTop101Big->Selection.Top])),
					  False);
			break;
		case kGridTop101Small:
			CopyFile(PChar(sgTop101Small->Cells[0, sgTop101Small->Selection.Top]),
					  PChar(s + ExtractFileName(sgTop101Small->Cells[0][sgTop101Small->Selection.Top])),
				  False);
			break;

		case kGridTop101BigDate:
			CopyFile(PChar(sgTop101BigDate->Cells[0, sgTop101BigDate->Selection.Top]),
					  PChar(s + ExtractFileName(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top])),
				  False);
			break;
		case kGridTop101SmallDate:
			CopyFile(PChar(sgTop101SmallDate->Cells[0, sgTop101SmallDate->Selection.Top]),
					  PChar(s + ExtractFileName(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top])),
				  False);
			break;
		}
	} */
}


void __fastcall TFrameProperties::miCopyAllClick(TObject *Sender)
{       /*
// to do	std::wstring s = GetCopyMoveFolder((GLanguageHandler->Text[kCopyTo] + kEllipsis).c_str());

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
				CopyFile(PChar(sgTemporary->Cells[0][r]),
						  PChar(s + ExtractFileName(sgTemporary->Cells[0][r])),
						  False);
			}
			break;
		case kGridTop101Big:
			for (int r = 1; r < sgTop101Big->RowCount; r++)
			{
				CopyFile(PChar(sgTop101Big->Cells[0][r]),
					  PChar(s + ExtractFileName(sgTop101Big->Cells[0][r])),
					  False);
			}
			break;
		case kGridTop101Small:
			for (int r = 1; r < sgTop101Small->RowCount; r++)
			{
				 CopyFile(PChar(sgTop101Small->Cells[0][r]),
					  PChar(s + ExtractFileName(sgTop101Small->Cells[0][r])),
					  False);
			}
			break;
		}
	}     */
}


void __fastcall TFrameProperties::miMoveSelectedClick(TObject *Sender)
{                               /*
	std::wstring s = GetCopyMoveFolder((GLanguageHandler->Text[kMoveTo] + kEllipsis).c_str());

	if (!s.empty())
	{
		TMenuItem* mi = (TMenuItem*)Sender;
		TPopupMenu* pum = (TPopupMenu*)mi->GetParentMenu();
		TStringGrid* sg = (TStringGrid*)pum->PopupComponent;
		int tag = sg->Tag;

		switch (tag)
		{
		case kGridTemp:
			MoveFileEx(PChar(sgTemporary->Cells[0, sgTemporary->Selection.Top]),
						PChar(s + ExtractFileName(sgTemporary->Cells[0][sgTemporary->Selection.Top])),
						MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		case kGridTop101Big:
			MoveFileEx(PChar(sgTop01Big->Cells[0][sgTop101Big->Selection.Top]),
					PChar(s + ExtractFileName(sgTop101Big->Cells[0][sgTop101Big->Selection.Top])),
					MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		case kGridTop101Small:
			MoveFileEx(PChar(sgTop101Small->Cells[0][sgTop101Small->Selection.Top]),
						PChar(s + ExtractFileName(sgTop101Small->Cells[0][sgTop101Small->Selection.Top])),
						MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		case kGridTop101BigDate:
			MoveFileEx(PChar(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top]),
						PChar(s + ExtractFileName(sgTop101BigDate->Cells[0][sgTop101BigDate->Selection.Top])),
						MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		case kGridTop101SmallDate:
			MoveFileEx(PChar(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top]),
						PChar(s + ExtractFileName(sgTop101SmallDate->Cells[0][sgTop101SmallDate->Selection.Top])),
						MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			break;
		}
	}     */
}


void __fastcall TFrameProperties::miMoveAllClick(TObject *Sender)
{      /*
	std::wstring s = GetCopyMoveFolder((GLanguageHandler->Text[kMoveTo] + kEllipsis).c_str());

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
				 MoveFileEx(PChar(sgTemporary->Cells[0][r]),
							PChar( s+ ExtractFileName(sgTemporary->Cells[0][r])),
							MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			}
			break;
		case kCGridTop101Big:
			for (int r = 1; r < sgTop101Big->RowCount; r++)
			{
				 MoveFileEx(PChar(sgTop101Big->Cells[0][r]),
							PChar(s + ExtractFileName(sgTop01Big->Cells[0][r])),
							MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			}
			break;
		case kGridTop101Small:
			for (int r = 1; r < sgTop101Small->RowCount; r++)
			{
				 MoveFileEx(PChar(sgTop101Small->Cells[0][r]),
							PChar(s + ExtractFileName(sgTop101Small->Cells[0][r])),
							MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
			}
			break;
		}
	}     */
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
//1716

