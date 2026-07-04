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

	int Ordinal = 0;
	std::wstring Name = L"";

	int Count = 0;
	unsigned __int64 Size = 0;

	double PercentCount = 0;
	double PercentSize = 0;

	std::wstring PercentCountString = L"";
	std::wstring PercentSizeString = L"";

	void PostProcess(int total_count, unsigned __int64 total_size)
	{
		if (total_count != 0)
		{
			PercentCount = (double)Count / (double)total_count;
			PercentCountString = Convert::DoubleToPercent(PercentCount);
		}
		else
		{
			PercentCount = 100;
			PercentCountString = L"100%";
		}

		if (total_size != 0)
		{
			PercentSize = (double)Size / (double)total_size;
			PercentSizeString = Convert::DoubleToPercent(PercentSize);
		}
		else
		{
			PercentSize = 100;
			PercentSizeString = L"100%";
		}
	}

	void Clear()
	{
		Count = 0;
		Size = 0;

		PercentCount = 0;
		PercentSize = 0;

		PercentCountString = L"";
		PercentSizeString = L"";
	}
};
