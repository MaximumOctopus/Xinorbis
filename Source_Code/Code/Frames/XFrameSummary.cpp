//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameSummary.h"

#include "ConstantsGui.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "WindowsUtility.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SettingsHandler *GSettingsHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameSummary *FrameSummary;
//---------------------------------------------------------------------------
__fastcall TFrameSummary::TFrameSummary(TComponent* Owner)
	: TFrame(Owner)
{
	Init();
}
//---------------------------------------------------------------------------


void __fastcall TFrameSummary::FrameResize(TObject *Sender)
{
	icQuantity->Update();
	icSize->Update();
}


void TFrameSummary::Init()
{
	icQuantity = new XIceCream(this, pICQuantity);
	icSize = new XIceCream(this, pICSize);

	lSummaryBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	lSummaryByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

	//== configure summary panel =================================================
	lSNoF->Caption    = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[1]).c_str();
	lSNoD->Caption    = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[2]).c_str();
	lSSoF->Caption    = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[3]).c_str();
	lSSoFoD->Caption  = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[4]).c_str();
	lSAFS->Caption    = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[8]).c_str();
	lSAFF->Caption    = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[9]).c_str();
	lSEF->Caption     = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[6]).c_str();
	lSED->Caption     = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[7]).c_str();
	lSLFSoF->Caption  = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[10] + L" (" + lSSoF->Caption.c_str() + L")").c_str();
	lSLFNoF->Caption  = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[10] + L" (" + lSNoF->Caption.c_str() + L")").c_str();
	lSLF->Caption     = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[12]).c_str();
	lSULSSoF->Caption = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[13] + L" (" + lSSoF->Caption.c_str() + L")").c_str();
	lSULSNoF->Caption = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[13] + L" (" + lSNoF->Caption.c_str() + L")").c_str();

	lSVolName->Caption    = GLanguageHandler->FormatForScreen(GLanguageHandler->DriveReport[7]).c_str();
	lSSerial->Caption     = GLanguageHandler->FormatForScreen(GLanguageHandler->DriveReport[8]).c_str();
	lSFileSystem->Caption = GLanguageHandler->FormatForScreen(GLanguageHandler->DriveReport[9]).c_str();
	lSVolMax->Caption     = GLanguageHandler->FormatForScreen(GLanguageHandler->DriveReport[1]).c_str();
	lSVolFree->Caption    = GLanguageHandler->FormatForScreen(GLanguageHandler->DriveReport[2]).c_str();

	lDFolder->Caption = GLanguageHandler->Text[kFolder].c_str();
	lDUsedSpace->Caption = GLanguageHandler->Text[kUsedSpace].c_str();

	tsSummary->Caption = GLanguageHandler->Text[kSummary].c_str();
	tsDrive->Caption = GLanguageHandler->Text[kORIReport9].c_str();
}


void TFrameSummary::Destroy()
{
	delete icQuantity;
	delete icSize;
}


void __fastcall TFrameSummary::lSNoFXClick(TObject *Sender)
{
	if (OnDataSelected)
	{
		OnDataSelected(kTabIndexCategories);
	}
}


void __fastcall TFrameSummary::lSAFSXClick(TObject *Sender)
{
	if (OnDataSelected)
	{
		OnDataSelected(kTabIndexMagnitude);
	}
}


void __fastcall TFrameSummary::lSEFXClick(TObject *Sender)
{
	if (OnDataSelected)
	{
		OnDataSelected(kTabIndexNull);
	}
}


void __fastcall TFrameSummary::lSNoDXClick(TObject *Sender)
{
	if (OnDataSelected)
	{
		OnDataSelected(kTabIndexFolders);
	}
}

void __fastcall TFrameSummary::lSLFXClick(TObject *Sender)
{
	if (OnDataSelected)
	{
		OnDataSelected(kTabIndexTop101);
	}
}


void __fastcall TFrameSummary::lSULSSoFXClick(TObject *Sender)
{
	if (OnDataSelected)
	{
		OnDataSelected(kTabIndexUsers);
	}
}


void TFrameSummary::Update()
{
	dd = WindowsUtility::GetDriveDetails(GScanEngine->Data[DataSource].Path.String.substr(0, 2));

	BuildPreamble();
	BuildSummaryLabels();
	BuildGauges();
	BuildIceCream();
	BuildDriveSection();
}


void TFrameSummary::SetProcessTime(const std::wstring process_time)
{
	lProcessTime->Caption = process_time.c_str();
}


void TFrameSummary::BuildPreamble()
{
//	if XSettings.LastScanMultiple then begin
//	lSScanPath.Caption := XText[kMultipleFolders];
//	lSScanPath.Hint    := '';

//	for t := 0 to GScanDetails[FSource].MultipleList.Count - 1 do begin
//	  lSScanPath.Hint := lSScanPath.Hint + GScanDetails[FSource].MultipleList[t];

//	  if t <> GScanDetails[FSource].MultipleList.Count - 1 then
//		lSScanPath.Hint := lSScanPath.Hint + #13;
//	end;
//	end
//	else begin
	lScanPath->Caption = GScanEngine->Data[DataSource].Path.String.c_str();
	lScanPath->Hint    = GScanEngine->Data[DataSource].Path.String.c_str();
}


void TFrameSummary::BuildSummaryLabels()
{
	lSNoFX->Caption = IntToStr(GScanEngine->Data[DataSource].FileCount);
	lSNoDX->Caption = IntToStr(GScanEngine->Data[DataSource].FolderCount);

	lSSoFX->Caption = Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSize).c_str();

	if (dd.SectorSize != 0)
	{
		lSSoFODX->Caption = Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSizeOD).c_str();
	}
	else
	{
		lSSoFODX->Caption = L"n/a";
	}

	if (GScanEngine->Data[DataSource].FileCount != 0)
	{
		lSAFSX->Caption = Convert::ConvertToUsefulUnit(std::round(GScanEngine->Data[DataSource].TotalSize / GScanEngine->Data[DataSource].FileCount)).c_str();
	}
	else
	{
		lSAFSX->Caption = L"-";
	}

	if (GScanEngine->Data[DataSource].FolderCount != 0)
	{
		lSAFFX->Caption = FloatToStrF(GScanEngine->Data[DataSource].FileCount / GScanEngine->Data[DataSource].FolderCount, ffFixed, 7, 2, GSettingsHandler->XinorbisFormat);
	}
	else
	{
		lSAFFX->Caption = L"-";
	}

	Statistics stats = GScanEngine->Data[DataSource].Stats;

	lSLFX->Caption = (stats.LargestFileName + L" (" + Convert::ConvertToUsefulUnit(stats.LargestFileSize) + L")").c_str();

	lSLFSoFX->Caption = (stats.LargestFolderNameSize + L" (" +
						 Convert::ConvertToUsefulUnit(stats.LargestFolderSize) + L", " +
						 Convert::DoubleToPercent((double)stats.LargestFolderSize / (double)GScanEngine->Data[DataSource].TotalSize) + L" of files)").c_str();
	lSLFNoFX->Caption = (stats.LargestFolderNameCount + L" (" +
						 std::to_wstring(stats.LargestFolderCount) + L", " +
						 Convert::DoubleToPercent((double)stats.LargestFolderCount / (double)GScanEngine->Data[DataSource].FileCount) + L" of files)").c_str();

	lSULSSoFX->Caption = (stats.LargestUserNameSize + L" (" +
						  Convert::ConvertToUsefulUnit(stats.LargestUserSize) + L", " +
						  Convert::DoubleToPercent((double)stats.LargestUserSize / (double)GScanEngine->Data[DataSource].TotalSize) + L" of files)").c_str();
	lSULSNoFX->Caption = (stats.LargestUserNameCount + L" (" +
						  std::to_wstring(stats.LargestUserCount) + L", " +
						  Convert::DoubleToPercent((double)stats.LargestUserCount / (double)GScanEngine->Data[DataSource].FileCount) + L" of files)").c_str();
}


void TFrameSummary::BuildGauges()
{
	Statistics stats = GScanEngine->Data[DataSource].Stats;

	if (GScanEngine->Data[DataSource].TotalSize != 0)
	{
		gSLF->Progress = ((double)stats.LargestFileSize / (double)GScanEngine->Data[DataSource].TotalSize) * 100;
	}
	else
	{
		gSLF->Progress = 0;
	}

	gSLDCount->Progress = ((double)stats.LargestFolderCount / (double)GScanEngine->Data[DataSource].FileCount) * 100;
	gSLDSize->Progress  = ((double)stats.LargestFolderSize / (double)GScanEngine->Data[DataSource].TotalSize) * 100;

	if (GScanEngine->Data[DataSource].Users.size() != 0)
	{
		gSLUCount->Progress = ((double)stats.LargestUserCount / (double)GScanEngine->Data[DataSource].FileCount) * 100;
		gSLUSize->Progress  = ((double)stats.LargestUserSize / (double)GScanEngine->Data[DataSource].TotalSize) * 100;
	}
	else
	{
		gSLUCount->Progress = 0;
		gSLUSize->Progress  = 0;
	}
}


void TFrameSummary::BuildIceCream()
{
	icQuantity->Begin();
	icSize->Begin();

	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		if (GScanEngine->Data[DataSource].Files.size() != 0)
		{
			if (GScanEngine->Data[DataSource].ExtensionSpread[t].Count != 0)
			{
				icQuantity->Add(0,
								GScanEngine->Data[DataSource].ExtensionSpread[t].PercentCount,
								GLanguageHandler->TypeDescriptions[t],
								GLanguageHandler->TypeDescriptions[t] + L" (" + std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count) + L" " + GLanguageHandler->Text[kFiles] + L")",
								GSettingsHandler->FileCategoryColors[t]);
			}
		}

		if (GScanEngine->Data[DataSource].TotalSize != 0)
		{
			if (GScanEngine->Data[DataSource].ExtensionSpread[t].Size != 0)
			{
				icSize->Add(0,
							GScanEngine->Data[DataSource].ExtensionSpread[t].PercentSize,
							GLanguageHandler->TypeDescriptions[t],
							GLanguageHandler->TypeDescriptions[t] + L" (" + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size) + L")",
							GSettingsHandler->FileCategoryColors[t]);
			}
		}
	}

	icQuantity->End();
	icSize->End();
}


void TFrameSummary::BuildDriveSection()
{
	bool show_control = GScanEngine->Data[DataSource].Source != ScanSource::FileCSV &&
						GScanEngine->Data[DataSource].Source != ScanSource::LiveShare &&
						GScanEngine->Data[DataSource].Source != ScanSource::FolderHistory;

	lSVolName->Visible         = show_control;
	lSVolNameValue->Visible    = show_control;
	lSSerial->Visible          = show_control;
	lSSerialValue->Visible     = show_control;
	lSFileSystem->Visible      = show_control;
	lSFileSystemValue->Visible = show_control;
	lSVolMax->Visible          = show_control;
	lSVolMaxValue->Visible     = show_control;
	lSVolFree->Visible         = show_control;
	lSVolFreeValue->Visible    = show_control;

	gDFolder->Visible          = show_control;
	lDFolder->Visible          = show_control;

	gDUsedSpace->Visible       = show_control;
	lDUsedSpace->Visible       = show_control;

	if (show_control)
	{
		lSVolNameValue->Caption    = dd.VolumeName.c_str();
		lSSerialValue->Caption     = (dd.SerialNumber + L" ($" + dd.SerialNumberHex + L")").c_str();
		lSFileSystemValue->Caption = dd.FileSystem.c_str();

		if (dd.SpaceTotal > 0)
		{
			lSVolMaxValue->Caption  = Convert::ConvertToUsefulUnit(dd.SpaceTotal).c_str();
			lSVolFreeValue->Caption = Convert::ConvertToUsefulUnit(dd.SpaceFree).c_str();

			gDFolder->Progress    = (GScanEngine->Data[DataSource].TotalSize / dd.SpaceTotal) * 100;
			gDUsedSpace->Progress = 100 - ((dd.SpaceFree / dd.SpaceTotal) * 100);
		}
		else
		{
			lSVolMaxValue->Caption  = L"n/a";
			lSVolFreeValue->Caption = L"n/a";

			gDFolder->Progress = 0;
			gDUsedSpace->Progress = 0;
		}
	}
	else
	{
		gDFolder->Progress = 0;
		gDUsedSpace->Progress = 0;
	}
}
