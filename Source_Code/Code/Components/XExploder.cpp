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

#include <algorithm>

#include "Convert.h"
#include "XExploder.h"


XExploder::XExploder(TComponent* owner, TWinControl* Zig)
{
	pbExploder              = new TPaintBox(owner);
	pbExploder->Parent      = Zig;
	pbExploder->Align       = alClient;
	pbExploder->OnPaint     = PaintBoxUpdateSize;
	pbExploder->OnMouseDown = PaintBoxMouseDown;
	pbExploder->OnMouseMove = PaintBoxMouseMove;

	HasData             = false;
	Busy                = false;
	DataSource          = -1;

	SelectedSlice       = -1;
	SelectedOldSlice    = -1;

	SliceForText        = 28; // degrees

	LargestSize         = -1;
	LargestQuantity     = -1;

	MaxRadius           = std::min(pbExploder->Height, pbExploder->Width) - 20;
	HubRadius           = 25;
}


XExploder::~XExploder()
{
	delete pbExploder;

	ExploderData.clear();
}


void __fastcall XExploder::PaintBoxUpdateSize(TObject *Sender)
{
	ClearDisplay();

	if (ExploderData.size() != 0)
	{
		for (int t = 0; t < ExploderData.size(); t++)
		{
			XExploderDataObject *xdo = ExploderData[t];

			if (SelectedSlice != t)
			{
				DrawPie(xdo->FolderName + L" (" + Convert::ConvertToUsefulUnit(xdo->FileSize) + L")",
						t * SliceAngle, (t * SliceAngle) + SliceAngle,
						xdo->PieSize,
						xdo->Colour);
			}
		}

		if (SelectedSlice != -1)
		{
			if (ExploderData.size() > 1)
			{
				DrawPie(ExploderData[SelectedSlice]->FolderName + L" (" + Convert::ConvertToUsefulUnit(ExploderData[SelectedSlice]->FileSize) + L")",
						(SelectedSlice * SliceAngle), (SelectedSlice * SliceAngle) + SliceAngle,
						ExploderData[SelectedSlice]->PieSize,
						0x00CCCCCC);
			}
			else
			{
				DrawPie(ExploderData[SelectedSlice]->FolderName + L" (" + Convert::ConvertToUsefulUnit(ExploderData[SelectedSlice]->FileSize) + L")",
						(SelectedSlice * SliceAngle), (SelectedSlice * SliceAngle) + SliceAngle,
						ExploderData[SelectedSlice]->PieSize,
						ExploderData[SelectedSlice]->Colour);
			}
		}
	}

	DrawHub();
}


void __fastcall XExploder::PaintBoxUpdateQuantity(TObject* Sender)
{
	if (ExploderData.size() == 0) return;

	ClearDisplay();

	for (int t = 0; t < ExploderData.size(); t++)
	{
		XExploderDataObject *xmdo = ExploderData[t];

		if (SelectedSlice != t)
		{
			DrawPie(xmdo->FolderName + L" (" + std::to_wstring(xmdo->FileCount) + L")",
					t * SliceAngle, (t * SliceAngle) + SliceAngle,
					xmdo->PieQuantity,
					xmdo->Colour);
		}
	}

	if (SelectedSlice != -1)
	{
		if (ExploderData.size() > 1)
		{
			DrawPie(ExploderData[SelectedSlice]->FolderName + L" (" + std::to_wstring(ExploderData[SelectedSlice]->FileCount) + L")",
					(SelectedSlice * SliceAngle), (SelectedSlice * SliceAngle) + SliceAngle,
					ExploderData[SelectedSlice]->PieQuantity,
					0x00CCCCCC);
		}
		else
		{
			DrawPie(ExploderData[SelectedSlice]->FolderName + L" (" + std::to_wstring(ExploderData[SelectedSlice]->FileCount) + L")",
					(SelectedSlice * SliceAngle), (SelectedSlice * SliceAngle) + SliceAngle,
					ExploderData[SelectedSlice]->PieQuantity,
					ExploderData[SelectedSlice]->Colour);
		}
	}

	DrawHub();
}


void __fastcall XExploder::PaintBoxMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if (OnMouseOver && HasData)
	{
		if (Shift.Contains(ssLeft))
		{
			int item = GetItemFrom(X, Y);

			SelectedSlice = item;

			if (item != -1)
			{
				pbExploder->Invalidate();

				if (ExploderData[item]->FolderName != L"\\") // represents root of the folder, can't enter it!
				{
					if (OnMouseClick)
					{
						OnMouseClick(ExploderData[item]->FolderID,
									 ExploderData[item]->FileCount,
									 ExploderData[item]->FileSize);
					}
				}
			}
			else
			{
				if (OnGoBack)
				{
					OnGoBack();
				}

				pbExploder->Invalidate();
			}
		}
		else if (Shift.Contains(ssRight))
		{
			if (OnMouseRightClick && HasData)
			{
				int item = GetItemFrom(X, Y);

				SelectedSlice = item;

				if (SelectedSlice != SelectedOldSlice)
				{
					pbExploder->Invalidate();

					SelectedOldSlice = SelectedSlice;
				}

				OnMouseRightClick(item);
			}
		}
		else if (Shift.Contains(ssMiddle))
		{
			if (OnMouseDblClick && HasData)
			{
				int item = GetItemFrom(X, Y);

				SelectedSlice = item;

				if (SelectedSlice != SelectedOldSlice)
				{
					pbExploder->Invalidate();

					SelectedOldSlice = SelectedSlice;
				}

				OnMouseDblClick(item);
			}
		}
	}
}


void __fastcall XExploder::PaintBoxMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
	if (OnMouseOver && HasData)
	{
		int item = GetItemFrom(X, Y);

		SelectedSlice = item;

		if (SelectedSlice != SelectedOldSlice)
		{
			pbExploder->Invalidate();

			SelectedOldSlice = SelectedSlice;
		}

		OnMouseOver(item);
	}
}



void XExploder::DrawHub()
{
	pbExploder->Canvas->Brush->Color = TColor(BackgroundColour);
	pbExploder->Canvas->Pen->Color = clBlack;
	pbExploder->Canvas->Ellipse(CentreX - HubRadius,
								CentreY - HubRadius,
								CentreX + HubRadius,
								CentreY + HubRadius);
}


void XExploder::DrawText(const std::wstring text, int X5, int Y5)
{
	pbExploder->Canvas->Brush->Color = TColor(BackgroundColour);
	pbExploder->Canvas->Brush->Style = bsClear;
	pbExploder->Canvas->Pen->Color = clBlack;
	pbExploder->Canvas->TextOut(X5, Y5, text.c_str());
}


void XExploder::DrawPie(const std::wstring text, double start_angle, double slice_angle, double slice_radius, int colour)
{
	int Radius = 50 + std::round(MaxRadius * slice_radius);

	int X1 = CentreX - Radius;
	int Y1 = CentreY - Radius;
	int X2 = CentreX + Radius;
	int Y2 = CentreY + Radius;

//  { negative signs on "Y" values to correct for "flip" from normal math defintion for "Y" dimension }
	int X3 = CentreX + std::round(Radius * std::cos(DegToRad(start_angle)));
	int Y3 = CentreY - std::round(Radius * std::sin(DegToRad(start_angle)));
	int X4 = CentreX + std::round(Radius * std::cos(DegToRad(slice_angle)));
	int Y4 = CentreY - std::round(Radius * std::sin(DegToRad(slice_angle)));

	pbExploder->Canvas->Brush->Color = TColor(colour);
	pbExploder->Canvas->Brush->Style = bsSolid;

	pbExploder->Canvas->Pie(X1, Y1, X2, Y2, X3, Y3, X4, Y4);

	//== draw text ===============================================================
	// +10 is a naughty hack to centre the text within the slice. the co-ords
	// refer to the top left corner of the text (not the centre :(

	// only draw the text if the slices are above a minimum width (so the text fits nicely)
	if (SliceForText <= SliceAngle)
	{
		int Orientation = std::round(start_angle + ((slice_angle - start_angle) / 2));

		pbExploder->Canvas->Font->Size = 12;

		int X5 = 0;
		int Y5 = 0;

		if (Orientation > 90 && Orientation < 270)
		{
			Orientation += 180;

			pbExploder->Canvas->Font->Orientation = Orientation * 10;

			X5 = CentreX + std::round((HubRadius + 20 + (pbExploder->Canvas->TextWidth(text.c_str()))) * std::cos(DegToRad(start_angle - 5 + (((slice_angle - start_angle) / 2)))));
			Y5 = CentreY - std::round((HubRadius + 20 + (pbExploder->Canvas->TextWidth(text.c_str()))) * std::sin(DegToRad(start_angle - 5 + (((slice_angle - start_angle) / 2)))));
		}
		else
		{
			pbExploder->Canvas->Font->Orientation = Orientation * 10;

			X5 = CentreX + std::round((HubRadius + 20) * std::cos(DegToRad(start_angle + 10 + (((slice_angle - start_angle) / 2)))));
			Y5 = CentreY - std::round((HubRadius + 20) * std::sin(DegToRad(start_angle + 10 + (((slice_angle - start_angle) / 2)))));
		}

		DrawText(text, X5, Y5);
	}
}


void XExploder::Resize()
{
	MaxRadius    = std::round(std::min(pbExploder->Height, pbExploder->Width) / 2) - 50;

	CentreX      = std::round(pbExploder->Width / 2);
	CentreY      = std::round(pbExploder->Height / 2);

	SliceForText = 28; // degrees

	pbExploder->Invalidate();
}


void XExploder::ClearDisplay()
{
	pbExploder->Canvas->Brush->Color = TColor(BackgroundColour);
	pbExploder->Canvas->FillRect(Rect(0, 0, pbExploder->Width - 1, pbExploder->Height - 1));
}


void XExploder::Clear()
{
	ExploderData.clear();

	Busy = true;
	HasData = false;

	FolderTotalCount = 0;
	FolderTotalSize = 0;

	LargestSize = -1;
	LargestQuantity = -1;

	Busy = false;
}


void XExploder::SetMode(DisplayMode mode)
{
	Mode = mode;

	switch (mode)
	{
	case DisplayMode::kSize:
		pbExploder->OnPaint = PaintBoxUpdateSize;
		break;
	case DisplayMode::kQuantity:
		pbExploder->OnPaint = PaintBoxUpdateQuantity;
		break;
	}

	pbExploder->Invalidate();
}


void XExploder::BeginData(const std::wstring current_folder)
{
	Clear();

	CurrentFolder = current_folder;
}


void XExploder::AddData(const std::wstring folder_name, int folder_id, int file_count, unsigned __int64 file_size, int colour)
{
	XExploderDataObject *xdo = new XExploderDataObject();

	xdo->FolderName = folder_name;
	xdo->FolderID   = folder_id;
	xdo->FileCount  = file_count;
	xdo->FileSize   = file_size;
	xdo->Colour     = colour;

	ExploderData.push_back(xdo);

	FolderTotalCount += file_count;
	FolderTotalSize += file_size;

	if (LargestSize < file_size)
	{
		LargestSize = file_size;
	}

	if (LargestQuantity < file_count)
	{
		LargestQuantity = file_count;
	}
}


void XExploder::EndData()
{
	HasData          = true;
	SelectedSlice    = -1;
	SelectedOldSlice = -1;

	CalculatePies();

	pbExploder->Invalidate();

	Busy = false;
}


int XExploder::GetItemFrom(int x, int y)
{
	// first check that we're outside the hub
	double radius = std::sqrt(((CentreY - y) * (CentreY - y)) + ((x - CentreX) * (x - CentreX)));

	if (radius < HubRadius)
	{
	}
	else
	{
		double rad = std::atan2(CentreY - y, x - CentreX);

		int deg = std::round(rad * (180 / 3.14159265359));

		if (ExploderData.size() > 0)
		{
			if (deg < 0)
			{
				deg += 360;

				return std::ceil(deg / ((1 / ExploderData.size()) * 360)) - 1;
			}
		}
	}

	return -1;
}


XExploderDataObject* XExploder::GetItem(int index)
{
	if (index >= 0 && index < ExploderData.size())
	{
		return ExploderData[index];
	}

	return new XExploderDataObject();
}


void XExploder::CalculatePies()
{
	if (ExploderData.size() != 0)
	{
		SliceAngle = (1 / ExploderData.size()) * 360;

		for (int t = 0; t < ExploderData.size(); t++)
		{
			XExploderDataObject *xdo = ExploderData[t];

			if (FolderTotalSize != 0)
			{
				xdo->PieSize = (xdo->FileSize  / LargestSize);
			}
			else
			{
				xdo->PieSize     = 1;
			}

			if (FolderTotalCount != 0)
			{
				xdo->PieQuantity = (xdo->FileCount / LargestQuantity);
			}
			else
			{
				xdo->PieQuantity = 1;
			}
		}
	}
	else
	{
		XExploderDataObject *xdo = new XExploderDataObject();

		xdo->FolderName  = L"";
		xdo->FolderID    = -1;
		xdo->FileCount   = 0;
		xdo->FileSize    = 0;
		xdo->Colour      = 0x00cccccc;
		xdo->PieSize     = 100;
		xdo->PieQuantity = 100;

		ExploderData.push_back(xdo);
	}
}


double XExploder::DegToRad(double degrees)
{
	return degrees * (3.14159265359 / 180);
}
