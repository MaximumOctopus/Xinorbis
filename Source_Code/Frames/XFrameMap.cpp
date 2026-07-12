//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameMap.h"

#include "Convert.h"
#include "LanguageHandler.h"

extern LanguageHandler* GLanguageHandler;

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

	HasData = false;
	OldIndex = -1;

	rbBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();
	lMapSize->Caption = GLanguageHandler->Text[kSize].c_str();
}


void TFrameMap::DeInit()
{
	delete MapX;
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
		MapX->BlocksSize = 4;
		MapX->BlocksGap  = 1;
		break;
	case kBlockSizeB:
		MapX->BlocksSize = 5;
		MapX->BlocksGap  = 1;
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

			if (xdo->FolderName == L"\\")
			{
				lMapFolder->Caption = xdo->FolderName.c_str();
			}
			else
			{
				std::wstring caption = L"\\" + xdo->FolderName + L"\\";

				lMapFolder->Caption = caption.c_str();
			}

			std::wstring ftc = FloatToStrF((xdo->FileCount / MapX->FolderTotalCount) * 100, ffFixed, 7, 2).c_str();
            std::wstring fts = FloatToStrF((xdo->FileSize / MapX->FolderTotalSize) * 100, ffFixed, 7, 2).c_str();

			lMapDetails1->Caption = (std::to_wstring(xdo->FileCount) + L" " + GLanguageHandler->Text[kFiles] + L" " + ftc + L"%)").c_str();

			lMapDetails2->Caption = (Convert::ConvertToUsefulUnit(xdo->FileSize) + L" " + fts + L"%)").c_str();

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
//			DoExplore( GScanDetails[FSource].ScanPath)
		}
		else
		{
//			DoExplore(FSource, GScanDetails[FSource].ScanPath + TXMDO.FolderName + '\');
		}
	}
}


void TFrameMap::ClearMap()
{
	MapX->Clear();

	HasData = false;
	OldIndex = -1;
}


void TFrameMap::BeginData()
{
	MapX->BeginData();
}


void TFrameMap::AddData(const std::wstring folder_name, int file_count, unsigned __int64 file_size, int colour)
{
	MapX->AddData(folder_name, file_count, file_size, colour);
}


void TFrameMap::EndData()
{
	MapX->EndData();

	HasData = true;
}


void TFrameMap::SetDataSource(int source)
{
//  if aDataSource != XMap.DataSource then
//	ClearMap;
//
//  XMap.DataSource = aDataSource;
}
