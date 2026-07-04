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

#include <string>

enum class ChartType { kUnknown = 0, kPie, kBar, kHorizontal };


class ChartOptions
{
public:

	int Result = 0;

	ChartType Type = ChartType::kPie;		// but not used, each form frame to decide/save/load

	int ChartStyles = 0;
	int ChartFrom = 0;
	int ChartTo = 0;
	bool ChartGradient = false;
	int Zoom = 0;
	int Elevation = 0;
	int Explode = 0;
	int MarkColour = 0;
	bool ShowMarks = false;
	int MarksType = 0;
	int LabelOptions = 0;
	int XAxisDelta = 0;
	int ShowLegend = 0;

	int TitleColour = 0;
};
