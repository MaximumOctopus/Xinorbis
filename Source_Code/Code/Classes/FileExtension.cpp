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

#include "FileExtension.h"


FileExtension::FileExtension(const std::wstring name, int category)
{
	Name = name;
    Category = category;
}


void FileExtension::PostProcess(int total_count, unsigned __int64 total_size)
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


void FileExtension::Clear()
{
	Name = L"";
	Description = L"";

	Category = 0;
	Count = 0;

	Size = 0;

	PercentCount = 0;
	PercentSize = 0;

	PercentCountString = L"";
	PercentSizeString = L"";
}