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

#include <VCLTee.Chart.hpp>
#include <Vcl.Grids.hpp>

#include "XIceCream.h"


namespace TabUiDates
{
	void Chart(TTreeView*, TChart*);

	void Tree(TTreeView*, XIceCream*, int, int, int, bool, bool);
}
