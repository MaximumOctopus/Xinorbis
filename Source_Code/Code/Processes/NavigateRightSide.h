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

#include <Vcl.Grids.hpp>


class NavigateRightSide
{
public:

	int DataSource = 0;

	int FromFolderId = 0;
	unsigned __int64 FolderSize = 0;

	unsigned __int64 FileSize = 0;
	int FileCount = 0;
	int FolderCount = 0;

	TStringGrid *OutputGrid = nullptr;
	bool FilterChanged = false;

	void Execute();

	void SetData(TStringGrid*, int, int, unsigned __int64, bool);
};
