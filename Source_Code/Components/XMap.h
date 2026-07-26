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

#include <vector>

#include "XMapDataObject.h"


class XMap
{
	std::vector<XMapDataObject*> MapData;

	bool Busy = false;
	bool HasData = false;
	int DataSource = 0;

	int BlocksPixel = 5;

	int BlocksX = 1;
	int BlocksY = 1;

	int Selected = -1;
	bool HighlightMode = true;

	TPaintBox *pbMap;

	void __fastcall PaintBoxUpdateSize(TObject*);
	void __fastcall PaintBoxUpdateQuantity(TObject*);
	void __fastcall PaintBoxMouseMove(TObject*, TShiftState, int, int);
	void __fastcall PaintBoxMouseDown(TObject*, TMouseButton, TShiftState, int, int);

	int ColourToBW(int);

public:

	enum class DisplayMode { kSize = 0, kQuantity };

	DisplayMode Mode = DisplayMode::kSize;

	int BlocksSize = 4;
	int BlocksGap = 1;

	int FolderTotalCount = 0;
	unsigned __int64 FolderTotalSize = 0;

	std::function<void(int)> OnMouseClick;
	std::function<void(int)> OnMouseOver;

	XMap(TComponent* owner, TWinControl* Zig);
	~XMap();

	void Clear();

	void BeginData();
	void AddData(const std::wstring, int, unsigned __int64, int);
	void EndData();

	int GetItemFrom(int, int);
	XMapDataObject* GetItem(int);

	void SetMode(DisplayMode);
	void SetBlocksSize(int);
	void SetBlocksGap(int);
	void SetHighlightMode(bool);

};
