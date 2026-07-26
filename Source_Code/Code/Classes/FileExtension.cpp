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
	PercentCount = (double)Count / (double)total_count;
	PercentSize = (double)Size / (double)total_size;

	PercentCountString = Convert::DoubleToPercent(PercentCount);
	PercentSizeString = Convert::DoubleToPercent(PercentSize);
}


void FileExtension::Clear()
{
// to do
}