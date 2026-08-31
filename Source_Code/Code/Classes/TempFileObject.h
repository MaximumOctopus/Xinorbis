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


class TempFileObject
{

public:

	std::wstring Name = L"";
	std::wstring FullPath = L"";

	unsigned __int64 Size = 0;

	int Owner = 0;

	TempFileObject(const std::wstring name, const std::wstring full_path, unsigned __int64 size, int owner)
	{
		Name = name;
		FullPath = full_path;
		Size = size;
        Owner = owner;
	}
};
