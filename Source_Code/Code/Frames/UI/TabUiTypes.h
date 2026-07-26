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


namespace TabUiTypes
{
	void Chart(TChart*, int, int);

	void List(TStringGrid*, int);

	void Tree(TTreeView*, int, int);
	void TreePost(TTreeView* view);
}