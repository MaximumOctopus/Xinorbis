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


class TabUiUsers
{
public:

	const static int kDisplayModeShowAll   = 0;

	const static int kUsersTableName       = 1;
	const static int kUsersTableCount      = 2;
	const static int kUsersTableCountAs    = 3;
	const static int kUsersTableSeparator  = 4;
	const static int kUsersTableSize       = 5;
	const static int kUsersTableSizeAs     = 6;
	const static int kUsersTableSortSize   = 7;
	const static int kUsersTableGraphCount = 8;
	const static int kUsersTableGraphSize  = 9;

	void Chart(TChart* chart);

	void Table(TStringGrid* grid, int display_mode);
};
