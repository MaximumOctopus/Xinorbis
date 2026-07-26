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

#include "ChartOptions.h"


namespace ChartUtility
{
	void SetAdvancedOptions(TChart*, ChartOptions);

	void SaveChartToPNG(TChart*, const std::wstring);

	void ChangeChartToPie(TChart*);

	void ChangeChartToHorizontalBar(TChart*, bool);

	ChartType GetChartType(TChart *);

    void CopyChartToClipboard(TChart*);
}
