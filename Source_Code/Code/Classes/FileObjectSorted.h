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


class FileObjectSorted
{
public:
    int Index = 0;

    std::wstring Name = L"";

    bool operator<(const FileObjectSorted& rhs) const
    {
        return Name < rhs.Name;
	}

    FileObjectSorted(int, const std::wstring);
};
