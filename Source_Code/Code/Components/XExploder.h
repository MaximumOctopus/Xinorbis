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
	std::vector<XExploderDataObject*> ExploderData;

	std::wstring CurrentFolder = L"";
	int CentreX = 0;
	int CentreY = 0;
	double SliceAngle = 0;
	int MaxRadius = 0;
	int SelectedSlice = 0;
	int SelectedOldSlice = 0;
	int HubRadius = 0;
	double SliceForText = 28;

	bool Busy = false;
	bool HasData = false;

	int DataSource = 0;

	unsigned __int64 LargestSize = 0;
	int LargestQuantity = 0;

	TPaintBox* pbExploder;

	void ClearDisplay();

	void DrawHub();
	void DrawText(const std::wstring, int, int);
	void DrawPie(const std::wstring, double, double, double, int);

	void __fastcall PaintBoxUpdateSize(TObject *);
	void __fastcall PaintBoxUpdateQuantity(TObject *);

	void __fastcall PaintBoxMouseDown(TObject *, TMouseButton, TShiftState, int, int);
	void __fastcall PaintBoxMouseMove(TObject *, TShiftState, int, int);

	int GetItemFrom(int, int);

	void CalculatePies();

	double DegToRad(double);

public:

	enum class DisplayMode { kSize = 0, kQuantity };

   	DisplayMode Mode = DisplayMode::kSize;

	int FolderTotalCount = 0;
	unsigned __int64 FolderTotalSize = 0;

	int BackgroundColour = 0;

	std::function<void(int, int, unsigned __int64)> OnMouseClick;
	std::function<void(int)> OnMouseRightClick;
	std::function<void(int)> OnMouseDblClick;
	std::function<void(int)> OnMouseOver;
	std::function<void()> OnGoBack;

	XExploder(TComponent*, TWinControl*);
	~XExploder();

	void Clear();

	void Resize();

	void SetMode(DisplayMode);

	void BeginData(const std::wstring);
	void AddData(const std::wstring, int, int, unsigned __int64, int);
	void EndData();

   	XExploderDataObject* GetItem(int);
};
