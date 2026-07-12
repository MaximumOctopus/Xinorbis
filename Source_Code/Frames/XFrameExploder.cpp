//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameExploder.h"

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

		int folder_id = -1; // to do GScanEngine->GetFullFolderIndex(DirectoryList[DirectoryIndex]->Name);

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
			// to do DoExplore(FSource, xdo.FolderName)
		}
		else
		{
			//DoExplore(FSource, FDirectoryList[FDirectoryList.Count - 1].Name + xdo.FolderName + '\');
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


void TFrameExploder::ClearExploder()
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


void TFrameExploder::AddData(const std::wstring folder_name, int folder_id, int file_count, unsigned __int64 file_size, int colour)
{
	ExploderX->AddData(folder_name, folder_id, file_count, file_size, colour);

	if (AddToCache)
	{
		AddItemToCache(folder_name, folder_id, file_count, file_size, colour);
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
		AddData(ExploderCache[t]->FolderName,
				ExploderCache[t]->FolderID,
				ExploderCache[t]->FileCount,
				ExploderCache[t]->FileSize,
				ExploderCache[t]->Colour);
	};

	EndData();
};


void TFrameExploder::BuildFromFolderID(int folder_id, int count, unsigned __int64 size)
{
	if (GScanEngine->Data.Files.size() == 0) return;

	int ColourMod = 0;

	unsigned __int64 total_size = 0;
	int total_count = 0;

	BeginData(GScanEngine->Data.Folders[folder_id], count, size);

	for (FileObject file : GScanEngine->Data.Files)
	{
		if (file.FilePathIndex == folder_id)
		{
			if (faDirectory & file.Attributes)
			{
				SizeOfFolder sof;

				// cache the results in the FileSize, FileSizeOnDisk, and FileCategory parameters of the file object as these aren't used for folders
				// ===================================================================================================================
				if (file.Size == 0)
				{
					sof = GScanEngine->Data.GetSizeOfFolder(GScanEngine->Data.Folders[file.FilePathIndex] + file.Name + L"\\");

					file.Size = sof.Size;
					file.SizeOnDisk = sof.SizeOnDisk;

					file.Category = sof.FileCount;
				}
				else
				{
					sof.Size = file.Size;
					sof.SizeOnDisk = file.SizeOnDisk;

					sof.FileCount = file.Category;
				}

				AddData(file.Name, GScanEngine->Data.GetFullFolderIndex(GScanEngine->Data.Folders[file.FilePathIndex] + file.Name + L"\\"),
						sof.FileCount,
						sof.Size,
						__SpectrumColours[ColourMod % __SpectrumMod]);

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
			AddData(L"/", -1,
					count - total_count,
					size - total_size,
					__SpectrumColours[ColourMod % __SpectrumMod]);
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


/*


uses Vcl.Controls, Vcl.StdCtrls, AdvOfficeButtons, Vcl.ExtCtrls, HTMLabel,
  System.Classes,  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants,
  Vcl.Graphics, Vcl.Forms, dialogs, System.Generics.Collections, Vcl.Buttons,

  X.Form.Explore,

  X.CSizeOfFolder, X.CExploderDataObject,

  X.Constants, X.GlobalObjects, X.Conversions, X.Exploder, X.LanguageHandler,
  X.Windows;

type
  TFolderDetail = class
    Name  : string;
    Size  : int64;
    Count : integer;
  };

  TFrameExploder = class(TFrame)
    pExploder: TPanel;
    pExploderTop: TPanel;
    lExploderFolder: TLabel;
    cbExploderSize: TAdvOfficeRadioButton;
    cbExploderQuantity: TAdvOfficeRadioButton;
    lExploderDetails: THTMLabel;
    lExploderDetails2: THTMLabel;
    shapeExploder: TShape;
    bEBack: TBitBtn;
    procedure cbExploderSizeClick(S}er: TObject);
    procedure pExploderResize(S}er: TObject);
    procedure bEBakClick(S}er: TObject);
  private
    FExploderCache  : TObjectList<TXExploderDataObject>;
    FDirectoryList  : TObjectList<TFolderDetail>;
    FDirectoryIndex : integer;
    FAddToCache     : boolean;

    FSource   : integer;

    FHasData  : boolean;
    FOldIndex : integer;

    XExploder : TXExploder;

    function  GetDataSource: integer;
    procedure SetDataSource(aDataSource : integer);

    procedure OnMouseMove(const aFolderID : integer);
    procedure OnMouseClick(aFolderID, aCount : integer; aSize : int64);
    procedure OnMouseDblClick(const aFolderID : integer);
    procedure OnMouseRightClick(const aFolderID : integer);
    procedure OnGoBack;

    procedure WMDestroy(var Msg: TWMDestroy); message WM_DESTROY;

    procedure AddToCache(const aFolderName : string; aFolderID, aFileCount : integer; aFileSize : int64; aColour : integer);

    procedure BuildFromCache;
    procedure BuildFromFolderID(aFolderID : integer; aCount : integer;aSize : int64);
  public
    procedure Init;
    procedure DeInit;

    procedure ClearExploder;

    procedure {Data(const aCurrentFolder : string; aCount : integer; aSize : int64);
    procedure AddData(const aFolderName : string; aFolderID, aFileCount : integer; aFileSize : int64; aColour : integer);
    procedure }Data;

    property Source     : integer read FSource       write FSource;
    property DataSource : integer read GetDataSource write SetDataSource;
    property HasData    : boolean read FHasData;
  };







function  TFrameExploder.GetDataSource: integer;
{
  Result = ExploderX->DataSource;
};


procedure TFrameExploder.SetDataSource(aDataSource : integer);
{
  if aDataSource != ExploderX->DataSource then
	ClearExploder;

  ExploderX->DataSource = aDataSource;
};





procedure TFrameExploder.bEBakClick(S}er: TObject);
{
  OnGoBack;
};



*/

//450
