//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameExploder.h"
#include "XFormMoreDetail.h"

#include "Convert.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "SizeOfFolder.h"
#include "WindowsUtility.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameExploder *FrameExploder;
//---------------------------------------------------------------------------
__fastcall TFrameExploder::TFrameExploder(TComponent* Owner)
	: TFrame(Owner)
{
	Init();
}


void TFrameExploder::Init()
{
	DoubleBuffered = true;

	DirectoryIndex = -1;

	ExploderX = new XExploder(this, pExploder);
	ExploderX->BackgroundColour  = 0x00333333;
	ExploderX->OnMouseClick      = OnMouseClick;
	ExploderX->OnMouseRightClick = OnMouseRightClick;
	ExploderX->OnMouseDblClick   = OnMouseDblClick;
	ExploderX->OnMouseOver       = OnMouseMove;
	ExploderX->OnGoBack          = OnGoBack;

	HasData = false;
	OldIndex = -1;

	rbBySize->Caption = GLanguageHandler->Text[kBySize].c_str();
	rbByQuantity->Caption = GLanguageHandler->Text[kByQuantity].c_str();
}


void TFrameExploder::DeInit()
{
}


void TFrameExploder::Update()
{
	if (!NeedsRefresh) return;

	Clear();

	BeginData(GScanEngine->Data[DataSource].Path.String, -1, 0); // -1 for initial data set

	for (int t = 0; t < GScanEngine->Data[DataSource].RootFolders.size(); t++)
	{
//		ExploderX->AddData(Folders[t]->Name, t, Folders[t]->Count, Folders[t]->Size, __SpectrumColours[(t - 1) % __SpectrumMod]);

//		if (AddToCache)
//		{
//			AddItemToCache(Folders[t]->Name, t, Folders[t]->Count, Folders[t]->Size, __SpectrumColours[(t - 1) % __SpectrumMod]);
//		}
	}

	NeedsRefresh = false;

	EndData();
}


void __fastcall TFrameExploder::pExploderResize(TObject *Sender)
{
	ExploderX->Resize();
}


void __fastcall TFrameExploder::rbBySizeClick(TObject *Sender)
{
	if (rbBySize->Checked)
	{
		ExploderX->SetMode(XExploder::DisplayMode::kSize);
	}
	else
	{
		ExploderX->SetMode(XExploder::DisplayMode::kQuantity);
	}
}


void __fastcall TFrameExploder::OnMouseMove(int folder_id)
{
	if (folder_id != -1)
	{
		if (folder_id != OldIndex)
		{
			XExploderDataObject *xdo = ExploderX->GetItem(folder_id);

			if (xdo->FolderName == L"\\")
			{
				lExploderFolder->Caption = xdo->FolderName.c_str();
			}
			else
			{
				lExploderFolder->Caption = (DirectoryList[DirectoryList.size() - 1]->Name + xdo->FolderName + L"\\").c_str();
			}

			std::wstring ftc = FloatToStrF((xdo->FileCount / ExploderX->FolderTotalCount) * 100, ffFixed, 7, 2).c_str();
			std::wstring fts = FloatToStrF((xdo->FileSize / ExploderX->FolderTotalSize) * 100, ffFixed, 7, 2).c_str();

			lExploderDetails1->Caption = (std::to_wstring(xdo->FileCount) + L" " + GLanguageHandler->Text[kFiles] + L" (" + ftc + L"%)").c_str();
			lExploderDetails2->Caption = (Convert::ConvertToUsefulUnit(xdo->FileSize) + L" " + L" (" + fts + L"%)").c_str();

			shapeExploder->Brush->Color = TColor(xdo->Colour);

			OldIndex = folder_id;
		}
	}
	else
	{
		if (DirectoryList.size() == 1)
		{
			lExploderFolder->Caption = L"";
		}
		else
		{
			lExploderFolder->Caption = (L"<- " + DirectoryList[DirectoryList.size() - 1]->Name).c_str();
		}

		lExploderDetails1->Caption = L"";
		lExploderDetails2->Caption = L"";

		shapeExploder->Brush->Color = TColor(0x00ffffff);

		OldIndex = -1;
	}
}


void __fastcall TFrameExploder::OnMouseClick(int folder_id, int count, unsigned __int64 size)
{
	if (folder_id != -1)
	{
		BuildFromFolderID(folder_id, count, size);
	}
}


void __fastcall TFrameExploder::OnGoBack()
{
	if (DirectoryIndex > 0)
	{
		DirectoryList.pop_back();

		DirectoryIndex = DirectoryList.size() - 1;

		int folder_id = GScanEngine->Data[DataSource].GetFullFolderIndex(DirectoryList[DirectoryIndex]->Name);

		if (DirectoryIndex == 0) // use cached data
		{
			BuildFromCache();
		}
		else
		{
			BuildFromFolderID(folder_id,
							  DirectoryList[DirectoryIndex]->Count,
							  DirectoryList[DirectoryIndex]->Size);
		}
	}
}


void __fastcall TFrameExploder::OnMouseDblClick(int folder_id)
{
	if (folder_id != -1)
	{
		XExploderDataObject *xdo = ExploderX->GetItem(folder_id);

		if (xdo->FolderName == L"\\")
		{
			OpenMoreDetails(DataSource, xdo->FolderName);
		}
		else
		{
			OpenMoreDetails(DataSource, DirectoryList[DirectoryList.size() - 1]->Name + xdo->FolderName + L"\\");
		}
	}
}


void __fastcall TFrameExploder::OnMouseRightClick(int folder_id)
{
	if (folder_id != -1)
	{
		XExploderDataObject *xdo = ExploderX->GetItem(folder_id);

		if (xdo->FolderName == L"\\")
		{
			WindowsUtility::ExecuteFile(L"\"" + xdo->FolderName + L"\"", L"");
		}
		else
		{
			WindowsUtility::ExecuteFile(L"\"" + DirectoryList[DirectoryList.size() - 1]->Name + xdo->FolderName + L"\\" + L"\"", L"");
		}
	}
};


void TFrameExploder::Clear()
{
	HasData = false;

	OldIndex = -1;
}


void TFrameExploder::BeginData(const std::wstring current_folder, int count, unsigned __int64 size)
{
	ExploderX->BeginData(current_folder);

	AddToCache = false;
	OldIndex = -1;
	bool CanAdd = false;

	if (DirectoryList.size() == 0)
	{
		CanAdd = true;

		AddToCache = true;
	}
	else
	{
		if (DirectoryList[DirectoryList.size() - 1]->Name != current_folder)
		{
			CanAdd = true;
		}
	}

	if (CanAdd)
	{
		FolderDetail *tfd = new FolderDetail();

		tfd->Name  = current_folder;
		tfd->Size  = size;
		tfd->Count = count;

		DirectoryList.push_back(tfd);

		DirectoryIndex = DirectoryList.size() - 1;
	}
}


void TFrameExploder::EndData()
{
	ExploderX->EndData();

	HasData = true;

	bBack->Enabled = DirectoryList.size() > 1;
}


void TFrameExploder::BuildFromCache()
{
	BeginData(DirectoryList[0]->Name, DirectoryList[0]->Size, DirectoryList[0]->Count);

	for (int t = 0; t < ExploderCache.size(); t++)
	{
		ExploderX->AddData(ExploderCache[t]->FolderName,
						   ExploderCache[t]->FolderID,
						   ExploderCache[t]->FileCount,
						   ExploderCache[t]->FileSize,
						   ExploderCache[t]->Colour);
	};

	EndData();
};


void TFrameExploder::BuildFromFolderID(int folder_id, int count, unsigned __int64 size)
{
	if (GScanEngine->Data[DataSource].Files.size() == 0) return;

	int ColourMod = 0;

	unsigned __int64 total_size = 0;
	int total_count = 0;

	BeginData(GScanEngine->Data[DataSource].Folders[folder_id], count, size);

	for (FileObject *file : GScanEngine->Data[DataSource].Files)
	{
		if (file->FilePathIndex == folder_id)
		{
			if (faDirectory & file->Attributes)
			{
				SizeOfFolder sof;

				// cache the results in the FileSize, FileSizeOnDisk, and FileCategory parameters of the file object as these aren't used for folders
				// ===================================================================================================================
				if (file->Size == 0)
				{
					sof = GScanEngine->Data[DataSource].GetSizeOfFolder(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\\");

					file->Size = sof.Size;
					file->SizeOnDisk = sof.SizeOnDisk;

					file->Category = sof.FileCount;
				}
				else
				{
					sof.Size = file->Size;
					sof.SizeOnDisk = file->SizeOnDisk;

					sof.FileCount = file->Category;
				}

				ExploderX->AddData(file->Name,
								   GScanEngine->Data[DataSource].GetFullFolderIndex(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\\"),
								   sof.FileCount,
								   sof.Size,
								   kSpectrumColours[ColourMod % kSpectrumMod]);

				if (AddToCache)
				{
					AddItemToCache(file->Name,
								   GScanEngine->Data[DataSource].GetFullFolderIndex(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\\"),
								   sof.FileCount,
								   sof.Size,
								   kSpectrumColours[ColourMod % kSpectrumMod]);
				}

				total_size += sof.Size;
				total_count += sof.FileCount;

				ColourMod++;
			}
        }
	}

	if (size != -1 && count != -1)
	{
		if (total_size != size || total_count != count)
		{
			ExploderX->AddData(L"/", -1,
							   count - total_count,
							   size - total_size,
							   kSpectrumColours[ColourMod % kSpectrumMod]);

			if (AddToCache)
			{
				AddItemToCache(L"/",
							   -1,
							   count - total_count,
							   size - total_size,
							   kSpectrumColours[ColourMod % kSpectrumMod]);
			}
		}
	}

	EndData();
}


void TFrameExploder::AddItemToCache(const std::wstring folder_name, int folder_id, int file_count, unsigned __int64 file_size, int colour)
{
	XExploderDataObject *xdo = new XExploderDataObject();

	xdo->FolderName = folder_name;
	xdo->FolderID   = folder_id;
	xdo->FileCount  = file_count;
	xdo->FileSize   = file_size;
	xdo->Colour     = colour;

	ExploderCache.push_back(xdo);
}


int TFrameExploder::GetDataSource()
{
	return 0;
}


void TFrameExploder::SetDataSource(int source)
{
    // to
}


void __fastcall TFrameExploder::bBackClick(TObject *Sender)
{
	if (OnGoBack)
	{
		OnGoBack();
	}
}
