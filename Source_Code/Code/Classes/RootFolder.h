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
#include <Windows.h>


class RootFolder
{
public:
	std::wstring Name = L"";

	DWORD Attributes = 0;
	int Count = 0;
	unsigned __int64 Size = 0;

	double PercentCount = 0;
	double PercentSize = 0;

	std::wstring PercentCountString = L"";
	std::wstring PercentSizeString = L"";

	// this represents the files in the root of the scan folder
	bool FilesInRoot = false;

	void PostProcess(int total_count, unsigned __int64 total_size)
	{
		if (total_count != 0)
		{
			PercentCount = (double)Count / (double)total_count;
			PercentCountString = Convert::DoubleToPercent(PercentCount);
		}
		else
		{
			PercentCount = 1.0;
			PercentCountString = L"100%";
		}

		if (total_size != 0)
		{
			PercentSize = (double)Size / (double)total_size;
			PercentSizeString = Convert::DoubleToPercent(PercentSize);
		}
		else
		{
			PercentSize = 1.0;
			PercentSizeString = L"100%";
		}
	}
};
