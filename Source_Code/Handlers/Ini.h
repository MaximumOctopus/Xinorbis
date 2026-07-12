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
#include <vector>


class Ini
{
private:

	std::wstring LastSection = L"";		// cache the name of the last section checked, used with below
	int LastSectionIndex = 0;			// cache the index to lines so the next Read call is quicker

	[[nodiscard]] bool LoadFile(const std::wstring);

    std::wstring NormaliseEntry(const std::wstring);

public:

	bool Loaded = false;

	bool LastKeyExist = false;

	std::vector<std::wstring> Lines;

	Ini(const std::wstring);

	[[nodiscard]] std::wstring ReadString(const std::wstring, std::wstring, const std::wstring);
	[[nodiscard]] int ReadInteger(std::wstring, std::wstring, int);
};