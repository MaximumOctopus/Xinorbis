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
#include <vector>


namespace TabUiHistory
{
	std::wstring Chart(TChart*, std::vector<std::wstring> &, int,
					   TDateTime, TDateTime,
					   int, int, bool, bool,
					   std::wstring);
}