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


static const int ksmsValue             = 0;
static const int ksmsPercent           = 1;
static const int ksmsLabel             = 2;
static const int ksmsLabelPercent      = 3;
static const int ksmsLabelValue        = 4;
static const int ksmsLegend            = 5;
static const int ksmsPercentTotal      = 6;
static const int ksmsLabelPercentTotal = 7;
static const int ksmsXValue            = 8;


namespace ChartUtility
{
	void SetAdvancedOptions(TChart*, ChartOptions);

	void SaveChartToPNG(TChart*, const std::wstring);

    void SetChartTo(TChart*, int);

	void ChangeChartToBar(TChart*, bool);
	void ChangeChartToHorizontalBar(TChart*, bool);
	void ChangeChartToPie(TChart*);


	ChartType GetChartType(TChart *);
	int GetChartTypeInt(TChart *);

	TSeriesMarksStyle IntegerToSeriesMarksStyle(int);

	void CopyChartToClipboard(TChart*);
}
