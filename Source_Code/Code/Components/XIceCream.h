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

#pragma once

#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>


class XSprinkle
{
public:

	double Value = 0;

	std::wstring DisplayName = L"";
	int Width = 0;
	std::wstring Hint = L"";

	int Colour1 = 0xff8800;
	int Colour2 = 0xff8800;
};


class XIceCream
{
	std::vector<XSprinkle*> Sprinkles[2];

	TPaintBox *PaintBox = nullptr;

	TComponent *Owner = nullptr;
	TWinControl *Canvas = nullptr;

	bool Busy = false;

	int DataSource = 0;

	int CreateShade(int);

	void __fastcall PaintBoxUpdate(TObject *Sender);

public:

	XIceCream(TComponent*, TWinControl*);
	~XIceCream();

	void Clear();

	void Begin();
	void Add(int, double, const std::wstring, const std::wstring, int);
	void End();

	void Update();

	void SetSource(int);
};
