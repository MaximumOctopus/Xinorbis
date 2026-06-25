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

#include "Convert.h"


// used when an analysis category requires file count and file size.
class ConsolidatedData
{
public:

    std::wstring Name = L"";

	int Count = 0;
	unsigned __int64 Size = 0;

	double PercentCount = 0;
	double PercentSize = 0;

	std::wstring PercentCountString = L"";
	std::wstring PercentSizeString = L"";

	void PostProcess(int total_count, unsigned __int64 total_size)
	{
		PercentCount = (double)Count / (double)total_count;
		PercentSize = (double)Size / (double)total_size;

		PercentCountString = Convert::DoubleToPercent(PercentCount);
		PercentSizeString = Convert::DoubleToPercent(PercentSize);
	}
};
