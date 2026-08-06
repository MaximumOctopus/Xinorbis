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

#include <fstream>
#include <string>

#include <Vcl.Grids.hpp>


namespace ReportSummary
{
	void Generate(const std::wstring, int, TStringGrid *, TStringGrid *, TStringGrid *, TStringGrid *, TStringGrid *);

	void AddSummaryItem(std::ofstream &, TStringGrid*, TStringGrid*, int, int);
}