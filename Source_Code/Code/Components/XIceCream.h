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

	int DisplayNameWidth = 0;

	int ColourTop = 0xff8800;
	int ColourMiddle = 0xff8800;
	int ColourBottom = 0xff8800;
};


class XIceCream
{
	enum class ColourMode { kBrighten = 0, kDarken };

	std::vector<XSprinkle*> Sprinkles[2];

	TPaintBox *PaintBox = nullptr;

	TComponent *Owner = nullptr;
	TWinControl *Canvas = nullptr;

	int DisplayNamesTotalWidth[2] = { 0, 0 };

	bool Busy = false;

	int DataSource = 0;

	int IdCubeSize = 15;
	int IdCubeY = 40;

	int TextY = 0;

	int CreateShade(int, ColourMode);

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

	void Swap();

    std::wstring Debug();
};
