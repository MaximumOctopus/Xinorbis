//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameMap.h"
#include "XFormMoreDetail.h"

#include "Convert.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine *GScanEngine;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameMap *FrameMap;
//---------------------------------------------------------------------------
__fastcall TFrameMap::TFrameMap(TComponent* Owner)
	: TFrame(Owner)
{
	Init();
}


void TFrameMap::Init()
{
	DoubleBuffered = true;

	MapX = new XMap(this, pMap);
	MapX->OnMouseClick = std::bind(OnMouseClick, std::placeholders::_1);
	MapX->OnMouseOver  = OnMouseMove;
	MapX->OnDebug = OnDebug;

	HasData = false;
	OldIndex = -1;

	rbBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();
	lMapSize->Caption = GLanguageHandler->Text[kSize].c_str();

	cbHighlightMode->Caption = GLanguageHandler->Text[kHighlight].c_str();
}


void TFrameMap::DeInit()
{
	delete MapX;
}


void TFrameMap::Update()
{
    if (!NeedsRefresh) return;

	Clear();

	MapX->BeginData();

	int ColourMod = 0;

	for (RootFolder *folder : GScanEngine->Data[DataSource].RootFolders)
	{
		MapX->AddData(folder->Name,
					  folder->Count,
					  folder->Size,
					  kSpectrumColours[ColourMod % kSpectrumMod]);

        ColourMod++;
	}

	MapX->EndData();

	HasData = true;

    NeedsRefresh = false;
}


void __fastcall TFrameMap::rbBySizeClick(TObject *Sender)
{
	if (rbBySize->Checked)
	{
		MapX->SetMode(XMap::DisplayMode::kSize);
	}
	else
	{
		MapX->SetMode(XMap::DisplayMode::kQuantity);
	}
}


void __fastcall TFrameMap::cbMapSizeSelectChange(TObject *Sender)
{
	switch (cbMapSizeSelect->ItemIndex)
	{
	case kBlockSizeA:
		MapX->SetBlocksSize(4);
		break;
	case kBlockSizeB:
		MapX->SetBlocksSize(5);
		break;
	}
}


void __fastcall TFrameMap::cbHighlightModeClick(TObject *Sender)
{
	MapX->SetHighlightMode(cbHighlightMode->Checked);
}


void __fastcall TFrameMap::OnMouseMove(int folder_id)
{
	if (folder_id != -1)
	{
		if (folder_id != OldIndex)
		{
			XMapDataObject *xdo = MapX->GetItem(folder_id);

			std::wstring caption = L"";

			if (xdo->FolderName == L"\\")
			{
				caption = xdo->FolderName;
			}
			else
			{
				caption = L"\\" + xdo->FolderName + L"\\";
			}

			#ifdef _DEBUG
            caption += L" (" + std::to_wstring(xdo->BlockStart) + L" to " + std::to_wstring(xdo->BlockEnd) + L")";
			#endif

			lMapFolder->Caption = caption.c_str();

			std::wstring ftc = FloatToStrF(((double)xdo->FileCount / (double)MapX->FolderTotalCount) * 100, ffFixed, 7, 2).c_str();
			std::wstring fts = FloatToStrF(((double)xdo->FileSize / (double)MapX->FolderTotalSize) * 100, ffFixed, 7, 2).c_str();

			lMapDetails1->Caption = (std::to_wstring(xdo->FileCount) + L" " + GLanguageHandler->Text[kFiles] + L" (" + ftc + L"%)").c_str();

			lMapDetails2->Caption = (Convert::ConvertToUsefulUnit(xdo->FileSize) + L" (" + fts + L"%)").c_str();

			shapeMap->Brush->Color = TColor(xdo->Colour);

			OldIndex = folder_id;
		}
	}
	else
	{
		lMapFolder->Caption = L"";
		lMapDetails1->Caption = L"";
		lMapDetails2->Caption = L"";

		OldIndex = -1;

		shapeMap->Brush->Color = TColor(0x00ffffff);
	}
}


void __fastcall TFrameMap::OnMouseClick(int folder_id)
{
	if (folder_id != -1)
	{
		XMapDataObject *xdo	= MapX->GetItem(folder_id);

		if (xdo->FolderName == L"\\")
		{
			OpenMoreDetails(0, GScanEngine->Data[DataSource].Path.String);
		}
		else
		{
			OpenMoreDetails(0, GScanEngine->Data[DataSource].Path.String + xdo->FolderName + L"\\");
		}
	}
}


void __fastcall TFrameMap::OnDebug(const std::wstring debug)
{
	lDebug->Caption = debug.c_str();
}


void TFrameMap::Clear()
{
	MapX->Clear();

	HasData = false;
	OldIndex = -1;
}


void TFrameMap::SetDataSource(int source)
{
//  if aDataSource != XMap.DataSource then
//	ClearMap;
//
//  XMap.DataSource = aDataSource;
}
