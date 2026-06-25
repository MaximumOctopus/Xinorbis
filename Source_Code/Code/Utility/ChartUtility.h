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

enum class ChartType { kUnknown = 0, kPie, kBar, kHorizontal };


namespace ChartUtility
{
	void SaveChartToPNG(TChart*, const std::wstring);

	void ChangeChartToPie(TChart*);

	void ChangeChartToBar(TChart*, bool);

	ChartType GetChartType(TChart *);
}
