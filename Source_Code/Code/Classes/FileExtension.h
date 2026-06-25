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


class FileExtension
{
public:
    std::wstring Name = L"";

    int Category = 0;
    int Quantity = 0;
	
	unsigned __int64 Size = 0;

    FileExtension();
};