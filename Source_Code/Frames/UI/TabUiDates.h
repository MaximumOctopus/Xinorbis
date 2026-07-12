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


class TabUiDates
{
public:

	void Chart(TTreeView* tree, TChart* chart);

	void Table(TTreeView* tree, int userid, int data_range, bool build_tree, bool quantity);
};
