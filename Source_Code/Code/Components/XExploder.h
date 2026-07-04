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

#include "XExploderDataObject.h"


class XExploder
{
	std::vector<XExploderDataObject> ExploderData;

	int Mode = 0;

	void Resize();

	void ClearDisplay();

	void DrawHub();
	void DrawText(const std::wstring, int, int);
	void DrawPie(const std::wstring, double, double, double, int);

	void __fastcall PaintBoxUpdateSize(TObject *);
	void __fastcall PaintBoxUpdateQuantity(TObject *);

	void __fastcall PaintBoxMouseDown(TObject *, TMouseButton, TShiftState, int, int);
	void __fastcall PaintBoxMouseMove(TObject *, TShiftState, int, int);

	int GetExploderItemFrom(int, int);
	XExploderDataObject GetExploderItem(int);

	void CalculatePies();

public:

	int FolderTotalCount = 0;
	unsigned __int64 FolderTotalSize = 0;

	int BackgroundColour = 0;

	std::function<void(int, int, unsigned __int64)> OnMouseClick;
	std::function<void(int)> OnMouseRightClick;
	std::function<void(int)> OnMouseDblClick;
	std::function<void(int)> OnMouseOver;
	std::function<void()> OnGoBack;

	XExploder();
	~XExploder();

	void Clear();

	void SetMode(int);

	void BeginData(const std::wstring);
	void AddData(const std::wstring, int, int, unsigned __int64, int);
	void EndData();

	XExploderDataObject GetItem(int);
};
