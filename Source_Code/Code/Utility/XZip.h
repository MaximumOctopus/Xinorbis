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

#include <vector>


class XZip
{
public:

	XZip();

	bool Files(const std::wstring, std::vector<std::wstring>&, const std::wstring);

	bool Folder(const std::wstring, const std::wstring);
};
