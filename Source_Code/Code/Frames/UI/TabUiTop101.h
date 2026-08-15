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

#include "XIceCream.h"


namespace TabUiTop101
{
	std::wstring Date(TStringGrid*, TStringGrid*, int, int, int);

	std::wstring Size(TStringGrid*, TStringGrid*, XIceCream*, int, int);
}
