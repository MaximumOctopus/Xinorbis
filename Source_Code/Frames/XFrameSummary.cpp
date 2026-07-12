//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameSummary.h"

#include "ScanEngine.h"
#include "LanguageHandler.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;

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


void TFrameSummary::Init()
{
	lSummaryBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	lSummaryByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();

  //== configure summary panel =================================================
  lSNoF->Caption        = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[1]).c_str();
  lSNoD->Caption        = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[2]).c_str();
  lSSoF->Caption        = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[3]).c_str();
  lSSoFoD->Caption      = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[4]).c_str();
  lSAFS->Caption         = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[8]).c_str();
  lSAFF->Caption         = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[9]).c_str();
  lSEF->Caption          = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[6]).c_str();
  lSED->Caption          = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[7]).c_str();
  lSLFSoF->Caption      = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[10] + L" (" + lSSoF->Caption.c_str() + L")").c_str();
  lSLFNoF->Caption     = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[10] + L" (" + lSNoF->Caption.c_str() + L")").c_str();
  lSLF->Caption          = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[12]).c_str();
  lSULSSoF->Caption      = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[13] + L" (" + lSSoF->Caption.c_str() + L")").c_str();
  lSULSNoF->Caption     = GLanguageHandler->FormatForScreen(GLanguageHandler->SummaryReport[13] + L" (" + lSNoF->Caption.c_str() + L")").c_str();

//  lSVolName->Caption    := FormatForScreen(DriveReport[7]);
//  lSSerial.Caption     := FormatForScreen(DriveReport[8]);
//  lSFileSystem.Caption := FormatForScreen(DriveReport[9]);
//  lSVolMax.Caption     := FormatForScreen(DriveReport[1]);
//  lSVolFree.Caption    := FormatForScreen(DriveReport[2]);

//  if lSThisFolder.Canvas.TextWidth(XText[kFolder]) < 80 then
//    lSThisFolder.Left := gSThisFolder.Left + (Round((80 - lSThisFolder.Canvas.TextWidth(XText[kFolder])) / 2));
//  lSThisFolder.Caption := XText[kFolder];

//  if lSDSpaceUsed.Canvas.TextWidth(XText[kUsedSpace]) < 80 then
//    lSDSpaceUsed.Left := gSFS.Left + (Round((80 - lSDSpaceUsed.Canvas.TextWidth(XText[kUsedSpace])) / 2));
//  lSDSpaceUsed.Caption := XText[kUsedSpace];

	tsSummary->Caption = GLanguageHandler->Text[kSummary].c_str();
//  tsImportFromFile.Caption := XText[kORIReport9];
}


void TFrameSummary::Update()
{
	BuildPreamble();
	BuildSummaryLabels();
	BuildGauges();

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
	lScanPath->Caption = GScanEngine->Path.String.c_str();
	lScanPath->Hint    = GScanEngine->Path.String.c_str();
}


void TFrameSummary::BuildSummaryLabels()
{
	lSNoFX->Caption = IntToStr(GScanEngine->Data.FileCount);
	lSNoDX->Caption = IntToStr(GScanEngine->Data.FolderCount);

//	lSSoFx.Caption := TConvert.ConvertToUsefulUnit(GScanEngine[FSource].TotalSize);

//	if drivesectorsize <> 0 then
//		lSSoFoDx.Caption   := TConvert.ConvertToUsefulUnit(GScanEngine[FSource].TotalSizeOD)
//  else
//	lSSoFoDx.Caption   := '-';

	if (GScanEngine->Data.FileCount != 0)
	{
//		lSAFSX.Caption    := TConvert.ConvertToUsefulUnit(Round(GScanEngine[FSource].TotalSize / GScanEngine[FSource].FileCount))
	}
	else
	{
		lSAFSX->Caption = L"-";
	}

	if (GScanEngine->Data.FolderCount != 0)
	{
//		lSAFFX.Caption    := FloatToStrF(GScanEngine[FSource].FileCount / GScanEngine[FSource].FolderCount, ffFixed, 7, 2, XinorbisFormatSettings)
	}
	else
	{
		lSAFFX->Caption = L"-";
	}

//	lNFX->Caption = IntToStr(aNullFileCount);
//	lNDX->Caption = IntToStr(aNullFolderCount);
}


void TFrameSummary::BuildGauges()
{
//
}



