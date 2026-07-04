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

#include "Convert.h"


class FileExtension
{
public:
	std::wstring Name = L"";
    std::wstring Description = L"";

    int Category = 0;
    int Count = 0;
	
	unsigned __int64 Size = 0;

	double PercentCount = 0;
	double PercentSize = 0;

	std::wstring PercentCountString = L"";
	std::wstring PercentSizeString = L"";

	FileExtension(const std::wstring, int);

	void PostProcess(int, unsigned __int64);

	void Clear();
};