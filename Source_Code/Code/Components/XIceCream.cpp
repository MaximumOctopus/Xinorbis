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
	PaintBox->Parent = Canvas;
    PaintBox->Align = alClient;
}


XIceCream::~XIceCream()
{
}


int XIceCream::CreateShade(int input_colour)
{
    return 0;
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

	s->Colour1 = colour;
	s->Colour2 = CreateShade(colour);

    Sprinkles[data_source].push_back(s);
}


void XIceCream::End()
{
	Update();

	Busy = false;
}


void XIceCream::Update()
{
	int total_width = 0;

	for (int s = 0; s < Sprinkles[DataSource].size() - 1; s++)
	{
		Sprinkles[DataSource][s]->Width = (int)((Sprinkles[DataSource][s]->Value / 100) * (double)PaintBox->Width);

		total_width + Sprinkles[DataSource][s]->Width;
	}

	Sprinkles[DataSource].back()->Width = PaintBox->Width - total_width;
}


void __fastcall XIceCream::PaintBoxUpdate(TObject *Sender)
{
	int x = 0;

	for (XSprinkle *s : Sprinkles[DataSource])
	{
		PaintBox->Canvas->Brush->Color = TColor(s->Colour1);

		PaintBox->Canvas->FillRect(Rect(x, 0, x + s->Width, PaintBox->Height));

        x += s->Width;
    }
}


void XIceCream::SetSource(int source)
{
	DataSource = source;

    Update();

	PaintBox->Invalidate();
}
