//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormDebug.h"

#include "ScanEngine.h"
#include "SystemGlobal.h"

extern ScanEngine *GScanEngine;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDebug *FormDebug;
//---------------------------------------------------------------------------
__fastcall TFormDebug::TFormDebug(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TFormDebug::FormShow(TObject *Sender)
{
	lExePath->Caption = GSystemGlobal->ExePath.c_str();
	lAppDataPath->Caption = GSystemGlobal->AppDataPath.c_str();

	std::wstring data1 = L"Files: " + std::to_wstring(GScanEngine->Data[0].Files.size());
	std::wstring data2 = L"Files: " + std::to_wstring(GScanEngine->Data[1].Files.size());

	lData1->Caption = data1.c_str();
	lData2->Caption = data2.c_str();
}


