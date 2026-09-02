// =====================================================================
//
//   Xinorbis 10.0
//
// (c) Paul Alan Freshney 2002-2026
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/Xinorbis
//
// =====================================================================

#include "XMap.h"


XMap::XMap(TComponent* owner, TWinControl* Zig)
{
	pbMap             = new TPaintBox(owner);
	pbMap->Parent     = Zig;
	pbMap->Align       = alClient;
	pbMap->OnPaint     = PaintBoxUpdateSize;
	pbMap->OnMouseDown = PaintBoxMouseDown;
	pbMap->OnMouseMove = PaintBoxMouseMove;

	BlocksSize         = 4;
	BlocksGap          = 1;
	BlocksPixel        = BlocksSize + BlocksGap;

	BlocksX           = std::round(pbMap->Width / BlocksSize);
	BlocksY           = std::round(pbMap->Height / BlocksSize);

	HasData           = false;
	Busy              = false;
	DataSource        = -1;

	Selected          = -1;
	HighlightMode     = true;
}


XMap::~XMap()
{
	delete pbMap;
}


void __fastcall XMap::PaintBoxUpdateSize(TObject* Sender)
{
	if (!HasData) return;

	int BlocksX = (int)std::floor((double)pbMap->Width / (double)BlocksPixel);
	int BlocksY = (int)std::floor((double)pbMap->Height / (double)BlocksPixel);

	int FolderItem = 0;

	if (!HighlightMode || Selected == FolderItem)
	{
		pbMap->Canvas->Brush->Color = TColor(MapData[FolderItem]->Colour);
	}
	else
	{
		pbMap->Canvas->Brush->Color = TColor(MapData[FolderItem]->ColourBW);
	}

	int Blocks     = (int)std::round(((double)MapData[FolderItem]->FileSize / (double)FolderTotalSize) * (double)(BlocksX * BlocksY));
	int BlockCount = 0;

	MapData[FolderItem]->BlockStart = 0;
	MapData[FolderItem]->BlockEnd   = Blocks - 1;

	if (BlocksY > 0 && BlocksX > 0)
	{
		for (int y = 0; y < BlocksY; y++)
		{
			for (int x = 0; x < BlocksX; x++)
			{
				pbMap->Canvas->FillRect(Rect(x * BlocksPixel,
											 y * BlocksPixel,
											(x * BlocksPixel) + BlocksSize,
											(y * BlocksPixel) + BlocksSize));

				BlockCount++;

				if (BlockCount >= Blocks)
				{
					FolderItem++;

					if (FolderItem < MapData.size())
					{
						Blocks     = (int)std::round(((double)MapData[FolderItem]->FileSize / (double)FolderTotalSize) * (double)(BlocksX * BlocksY));

						MapData[FolderItem]->BlockStart = MapData[FolderItem - 1]->BlockEnd + 1;
						MapData[FolderItem]->BlockEnd   = MapData[FolderItem]->BlockStart + Blocks - 1;

						BlockCount = 0;

						if (!HighlightMode || Selected == FolderItem)
						{
							pbMap->Canvas->Brush->Color = TColor(MapData[FolderItem]->Colour);
						}
						else
						{
							pbMap->Canvas->Brush->Color = TColor(MapData[FolderItem]->ColourBW);
						}
					}
					else
					{
						pbMap->Canvas->Brush->Color = TColor(0x00ffffff);
					}
				}
			}
		}
	}
	else
	{
		pbMap->Canvas->Brush->Color = TColor(0x00aaaaaa);

		if (BlocksY > 0 && BlocksX > 0)
		{
			for (int y = 0; y < BlocksY; y++)
			{
				for (int x = 0; x < BlocksX; x++)
				{
					pbMap->Canvas->FillRect(Rect(x * BlocksPixel,
												 y * BlocksPixel,
												(x * BlocksPixel) + BlocksSize,
												(y * BlocksPixel) + BlocksSize));
				}
			}
		}
	}
}


void __fastcall XMap::PaintBoxUpdateQuantity(TObject* Sender)
{
	if (!HasData) return;

	int BlocksX = (int)std::floor((double)pbMap->Width / (double)BlocksPixel);
	int BlocksY = (int)std::floor((double)pbMap->Height / (double)BlocksPixel);

	int FolderItem = 0;

	if (!HighlightMode || Selected == FolderItem)
	{
		pbMap->Canvas->Brush->Color = TColor(MapData[FolderItem]->Colour);
	}
	else
	{
		pbMap->Canvas->Brush->Color = TColor(MapData[FolderItem]->ColourBW);
	}

	int Blocks     = (int)std::floor(((double)MapData[FolderItem]->FileCount / (double)FolderTotalCount) * (double)(BlocksX * BlocksY));
	int BlockCount = 0;

	MapData[FolderItem]->BlockStart = 0;
	MapData[FolderItem]->BlockEnd = Blocks - 1;

	if (BlocksY > 0 && BlocksX > 0)
	{
		for (int y = 0; y < BlocksY; y++)
		{
			for (int x = 0; x < BlocksX; x++)
			{
				pbMap->Canvas->FillRect(Rect(x * BlocksPixel,
											 y * BlocksPixel,
											(x * BlocksPixel) + BlocksSize,
											(y * BlocksPixel) + BlocksSize));

				BlockCount++;

				if (BlockCount >= Blocks)
				{
					FolderItem++;

					if (FolderItem < MapData.size())
					{
						Blocks     = (int)std::round(((double)MapData[FolderItem]->FileCount / (double)FolderTotalCount) * ((double)BlocksX * (double)BlocksY));

						MapData[FolderItem]->BlockStart = MapData[FolderItem - 1]->BlockEnd + 1;
						MapData[FolderItem]->BlockEnd   = MapData[FolderItem]->BlockStart + Blocks - 1;

						BlockCount = 0;

						if (!HighlightMode || Selected == FolderItem)
						{
							pbMap->Canvas->Brush->Color = TColor(MapData[FolderItem]->Colour);
						}
						else
						{
							pbMap->Canvas->Brush->Color = TColor(MapData[FolderItem]->ColourBW);
						}
					}
					else
					{
						pbMap->Canvas->Brush->Color = TColor(0x00ffffff);
					}
				}
			}
		}
	}
	else
	{
		pbMap->Canvas->Brush->Color = TColor(0x00aaaaaa);

		if (BlocksY > 0 && BlocksX > 0)
		{
			for (int y = 0; y < BlocksY; y++)
			{
				for (int x = 0; x < BlocksX; x++)
				{
					pbMap->Canvas->FillRect(Rect(x * BlocksPixel,
												 y * BlocksPixel,
												(x * BlocksPixel) + BlocksSize,
												(y * BlocksPixel) + BlocksSize));
				}
			}
		}
	}
}


void __fastcall XMap::PaintBoxMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if (OnMouseOver && HasData)
	{
		int item = GetItemFrom(X, Y);

		OnMouseClick(item);

		if (HighlightMode && Selected != item)
		{
			Selected = item;

			pbMap->Invalidate();
		}
	}
}


void __fastcall XMap::PaintBoxMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
	if (OnMouseOver && HasData)
	{
		int item = GetItemFrom(X, Y);

		OnMouseOver(item);

		if (HighlightMode && Selected != item)
		{
			Selected = item;

			pbMap->Invalidate();
        }
	}
}


#pragma region Data
void XMap::Clear()
{
	Busy = true;
	HasData = false;

    Selected = -1;

	FolderTotalCount = 0;
	FolderTotalSize  = 0;

	for (int t = 0; t < MapData.size(); t++)
	{
		delete MapData[t];
	}
	MapData.clear();

	Busy = false;
}


void XMap::BeginData()
{
	Clear();
}


void XMap::AddData(const std::wstring folder_name, int count, unsigned __int64 size, int colour)
{
	XMapDataObject *xmdo = new XMapDataObject();

	xmdo->FolderName = folder_name;
	xmdo->FileCount  = count;
	xmdo->FileSize   = size;
	xmdo->Colour     = colour;
	xmdo->ColourBW   = ColourToBW(colour);

	MapData.push_back(xmdo);

	FolderTotalCount += count;
	FolderTotalSize += size;
}


void XMap::EndData()
{
	Busy = false;
	HasData = true;
}
#pragma end_region


int XMap::GetItemFrom(int x, int y)
{
	int lX = (int)std::floor((double)x / (double)BlocksPixel);
	int lY = (int)std::floor((double)y / (double)BlocksPixel);
	double row = std::floor((double)pbMap->Width / (double)BlocksPixel);

	int block = (int)std::floor((double)lX + ((double)lY * row));

	if (OnDebug) OnDebug(std::to_wstring(lX) + L", " + std::to_wstring(lY) + L"; " + std::to_wstring(block));

	if (MapData.size() > 0)
	{
		for (int t = 0; t < MapData.size(); t++)
		{
			if (MapData[t]->BlockStart <= block && MapData[t]->BlockEnd >= block)
			{
				return t;
			}
		}
	}

	return -1;
}


XMapDataObject* XMap::GetItem(int index)
{
	if (index >= 0 && index < MapData.size())
	{
		return MapData[index];
	}

    return NULL;
}


#pragma region Public_Control
void XMap::SetMode(DisplayMode mode)
{
	Mode = mode;

	switch (mode)
	{
	case DisplayMode::kSize:
		pbMap->OnPaint = PaintBoxUpdateSize;
		break;
	case DisplayMode::kQuantity:
		pbMap->OnPaint = PaintBoxUpdateQuantity;
		break;
	}

	pbMap->Invalidate();
}


void XMap::SetBlocksSize(int size)
{
	if (size > 0)
	{
		BlocksSize = size;

		BlocksPixel = BlocksSize + BlocksGap;
	}

	pbMap->Invalidate();
}


void XMap::SetBlocksGap(int gap)
{
	if (gap > 0)
	{
		BlocksGap = gap;

		BlocksPixel = BlocksSize + BlocksGap;
	}

	pbMap->Invalidate();
}


void XMap::SetHighlightMode(bool mode)
{
	HighlightMode = mode;

	pbMap->Invalidate();
}
#pragma end_region


int XMap::ColourToBW(int colour)
{
	int R = (colour & 0x000000FF);
	int G = (colour & 0x0000FF00) >> 8;
	int B = (colour & 0x00FF0000) >> 16;

	int i = std::round(((double)R * 0.30) + ((double)G * 0.59) + ((double)B * 0.11));

	return (i << 16) + (i << 8) + (i);
}
