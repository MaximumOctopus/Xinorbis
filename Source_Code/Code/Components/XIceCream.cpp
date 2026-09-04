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

#include "XIceCream.h"


XIceCream::XIceCream(TComponent *owner, TWinControl *Zig)
{
	Owner = owner; // cache it for later!
	Canvas = Zig;

	PaintBox = new TPaintBox(owner);
	PaintBox->Font->Color = clWhite;
	PaintBox->Parent = Canvas;
	PaintBox->Align = alClient;
	PaintBox->OnPaint = PaintBoxUpdate;

	TextY = std::round(((double)IdCubeSize - (double)PaintBox->Canvas->TextHeight(L"Yg")) / 2);
	TextH = PaintBox->Canvas->TextHeight(L"Yg");
}


XIceCream::~XIceCream()
{
}


// colour in Windows BGR format
int XIceCream::CreateShade(int input_colour, ColourMode mode)
{
	int bx = (input_colour & 0xFF0000) >> 16;
	int gx = (input_colour & 0x00FF00) >> 8;
	int rx = (input_colour & 0x0000FF);

	switch (mode)
	{
	case ColourMode::kBrighten:
		rx = (int)(double(rx) * 1.25);
		gx = (int)(double(gx) * 1.25);
		bx = (int)(double(bx) * 1.25);

		if (rx > 255) rx = 255;
		if (gx > 255) gx = 255;
		if (bx > 255) bx = 255;
		break;
	case ColourMode::kDarken:
		rx = (int)(double(rx) * 0.75);
		gx = (int)(double(gx) * 0.75);
		bx = (int)(double(bx) * 0.75);
        break;
	}

	return (bx << 16) + (gx << 8) + rx;
}


void XIceCream::Clear()
{
	Sprinkles[0].clear();
	Sprinkles[1].clear();
}


void XIceCream::Begin()
{
	Busy = true;

	Clear();
}


void XIceCream::Add(int data_source, double value, const std::wstring display, const std::wstring hint, int colour)
{
	XSprinkle *s = new XSprinkle();

	s->Value = value;

	s->DisplayName = display;
	s->Hint = hint;

	s->ColourTop = CreateShade(colour, ColourMode::kBrighten);
	s->ColourMiddle = colour;
	s->ColourBottom = CreateShade(colour, ColourMode::kDarken);

    Sprinkles[data_source].push_back(s);
}


void XIceCream::End()
{
	Update();

	Busy = false;
}


void XIceCream::Update()
{
	for (int d = 0; d < 2; d++)
	{
		int total_width = 0;
		DisplayNamesTotalWidth[d] = 0;

		if (Sprinkles[d].size() == 0) continue;

		for (int s = 0; s < Sprinkles[d].size(); s++)
		{
			if (s != Sprinkles[d].size() -1)
			{
				Sprinkles[d][s]->Width = (int)((Sprinkles[d][s]->Value / 100) * (double)PaintBox->Width);

				total_width + Sprinkles[d][s]->Width;
			}

			Sprinkles[d][s]->DisplayNameWidth = PaintBox->Canvas->TextWidth(Sprinkles[d][s]->DisplayName.c_str());

			DisplayNamesTotalWidth[d] += Sprinkles[d][s]->DisplayNameWidth;
		}

   		Sprinkles[d].back()->Width = PaintBox->Width - total_width;
	}

	PaintBox->Invalidate();
}


void __fastcall XIceCream::PaintBoxUpdate(TObject *Sender)
{
	if (Sprinkles[DataSource].size() == 0 || Busy) return;

	int sprinkle_x = 0;
	int text_x = std::round((PaintBox->Width - (DisplayNamesTotalWidth[DataSource] + (Sprinkles[DataSource].size() * (IdCubeSize + 5)) + ((Sprinkles[DataSource].size() - 1) * 10))) / 2);

	for (XSprinkle *s : Sprinkles[DataSource])
	{
		PaintBox->Canvas->Brush->Color = TColor(s->ColourTop);
		PaintBox->Canvas->FillRect(Rect(sprinkle_x, 0, sprinkle_x + s->Width, 5));

		PaintBox->Canvas->Brush->Color = TColor(s->ColourMiddle);
		PaintBox->Canvas->FillRect(Rect(sprinkle_x, 5, sprinkle_x + s->Width, 25));

		PaintBox->Canvas->Brush->Color = TColor(s->ColourBottom);
		PaintBox->Canvas->FillRect(Rect(sprinkle_x, 25, sprinkle_x + s->Width, 30));

		sprinkle_x += s->Width;

		PaintBox->Canvas->Brush->Color = TColor(s->ColourMiddle);
		PaintBox->Canvas->FillRect(Rect(text_x, IdCubeY, text_x + IdCubeSize, IdCubeY + IdCubeSize));

		text_x += IdCubeSize + 5;

		PaintBox->Canvas->Brush->Color = PaintBox->Color;
		PaintBox->Canvas->Pen->Color = clNone;
		PaintBox->Canvas->TextOut(text_x, IdCubeY + TextY, s->DisplayName.c_str());
		PaintBox->Canvas->TextOut(text_x, IdCubeY + TextY + TextH, FloatToStrF(s->Value, ffFixed, 7, 2) + L"%");

		text_x += s->DisplayNameWidth + 10;
	}
}


void XIceCream::SetSource(int source)
{
	if (Sprinkles[source].size() != 0)
	{
		DataSource = source;

		Update();

		PaintBox->Invalidate();
    }
}


void XIceCream::Swap()
{
	if (DataSource == 0)
	{
		if (Sprinkles[1].size() != 0) DataSource = 1;
	}
	else
	{
		if (Sprinkles[0].size() != 0) DataSource = 0;
	}

	PaintBox->Invalidate();
}


std::wstring XIceCream::Debug()
{
	return L"DataSet #1: " + std::to_wstring(Sprinkles[0].size()) + L"; DataSet #2: " + std::to_wstring(Sprinkles[1].size()) + L"; Using: #" + std::to_wstring(DataSource) + L";";
}
