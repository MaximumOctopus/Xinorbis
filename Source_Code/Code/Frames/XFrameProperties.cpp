//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameProperties.h"

#include "ChartUtility.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameProperties *FrameProperties;
//---------------------------------------------------------------------------
__fastcall TFrameProperties::TFrameProperties(TComponent* Owner)
	: TFrame(Owner)
{
	Init();
}
//---------------------------------------------------------------------------


void TFrameProperties::Init()
{
	// tab titles
	tsCategories->Caption = GLanguageHandler->Text[kCategories].c_str();

	InitCategoriesTable();
}


void TFrameProperties::Update()
{
	BuildCategoriesTable();
	BuildCategoriesChart();
}


#pragma region Tab_Generic
void __fastcall TFrameProperties::sbCategoriesPieClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	switch (sb->Tag)
	{
	case 0:
		ChartUtility::ChangeChartToPie(vtcCategories);
		break;
	}
}


void __fastcall TFrameProperties::sbCategoriesBarClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	switch (sb->Tag)
	{
	case 0:
		ChartUtility::ChangeChartToBar(vtcCategories);
		break;
	}
}
#pragma end_region


#pragma region Tab_Categories
void TFrameProperties::InitCategoriesTable()
{
	sgCategories->RowCount =__FileCategoriesCount + 1;
}


void TFrameProperties::BuildCategoriesTable()
{
	for (int t = 0; t < __FileCategoriesCount; t++)
	{
		sgCategories->Cells[1][t + 1] = GScanEngine->Data.ExtensionSpread[t].Name.c_str();
		sgCategories->Cells[2][t + 1] = GScanEngine->Data.ExtensionSpread[t].Count;
		sgCategories->Cells[3][t + 1] = GScanEngine->Data.ExtensionSpread[t].PercentCountString.c_str();
		sgCategories->Cells[5][t + 1] = GScanEngine->Data.ExtensionSpread[t].Size;
		sgCategories->Cells[6][t + 1] = GScanEngine->Data.ExtensionSpread[t].PercentSizeString.c_str();
	}
}


void TFrameProperties::BuildCategoriesChart()
{
	if (GScanEngine->Data.FileCount > 0)
	{
		// == don't show size details if the chart is in quantity mode =============
///		if oChart.Tag = fQuantity then
//		  ChartLabelOption := 0;
		// =========================================================================

		vtcCategories->SeriesList->Items[0]->Clear();
		vtcCategories->Legend->TextStyle = ltsPlain;
//		    if XSettings.LastScanMultiple then
//      oChart.Title.Text.Strings[0] := XText[rsMultipleFolders]
//    else
      	vtcCategories->Title->Text->Strings[0] = GScanEngine->Path.String.c_str();

		for (int t = 0; t < __FileCategoriesCount; t++)
		{
			if (GScanEngine->Data.ExtensionSpread[t].Count != 0)
			{
				std::wstring s = L"";

				s = GScanEngine->Data.ExtensionSpread[t].Name;

//        case ChartLabelOption of
//          CLabelOptionDefault        : s := TypeDescriptions[t];
//          CLabelOptionMostConvenient : s := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, fSize]);
//          CLabelOptionKilobyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].ExtensionSpread[t, fSize], unitKB);
//          CLabelOptionMegabyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].ExtensionSpread[t, fSize], unitMB);
//          CLabelOptionGigabyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].ExtensionSpread[t, fSize], unitGB);
//        end;

				vtcCategories->SeriesList->Items[0]->Add((double)GScanEngine->Data.ExtensionSpread[t].Count,
														 s.c_str(),
														 TColor(0xff8844));//GSystemGlobal.FileCategoryColors[t]);
			}
		}
	}
}
#pragma end_region


#pragma region Tab_Type
#pragma end_region


#pragma region Tab_Extensions
#pragma end_region


#pragma region Tab_Folders
#pragma end_region


#pragma region Tab_Magnitude
#pragma end_region


#pragma region Tab_Dates
#pragma end_region


#pragma region Tab_History
#pragma end_region


#pragma region Tab_Top_101
#pragma end_region


#pragma region Tab_NullFiles
#pragma end_region


#pragma region Tab_Users
#pragma end_region


#pragma region Tab_Temp
#pragma end_region


#pragma region Tab_Length
#pragma end_region
