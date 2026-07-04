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
	std::vector<XMapDataObject> MapData;
	/*
	bool HighlightMode = false;
	int BlocksSize
	int BlocksGap
	int Mode

	procedure PaintBoxUpdateQuantity(Sender: TObject);
	procedure PaintBoxUpdateSize(Sender: TObject);
	procedure PaintBoxMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
	procedure PaintBoxMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);

	function  GetMapItemFrom(x, y : integer): integer;

	function  GetMapItem(aIndex : integer): TXMapDataObject;

	procedure SetBlocksSize(aBlocksSize : integer);
	procedure SetBlocksGap(aBlocksGap : integer);
	procedure SetHighlightMode(aHighlightMode : boolean);
	procedure SetMode(aMode : integer);

	function  ColourToBW(aColour : integer): integer; */

public:
/*
	int FolderTotalCount = 0;
	unsigned __int64 FolderTotalSize = 0;

	std::function<void(int)> OnMouseClick;
	std::function<void(int)> OnMouseOver;

	XMap();
	~XMap();

	procedure Clear;

	procedure BeginData;
	procedure AddData(const aFolderName : string; aFileCount : integer; aFileSize : int64; aColour : integer);
	procedure EndData;

	XMapDataObject GetItem(int);

procedure TXMap.SetBlocksGap(aBlocksGap : integer);
procedure TXMap.SetHighlightMode(aHighlightMode : boolean);
procedure TXMap.SetMode(aMode : integer);

                                              */
};
