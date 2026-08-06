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

#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>


namespace GridUtility
{
	void ToggleColumn(TStringGrid*, TSpeedButton*, int, int, int);

	void Clear(TStringGrid*, bool);

	void CopyGridToClipboard(TStringGrid*, int);

	void SaveGrid(TStringGrid*, const std::wstring);
}
