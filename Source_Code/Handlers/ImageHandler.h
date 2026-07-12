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


class ImageHandler
{
	std::wstring FlagFiles[11] = { L"UK\flag.bmp", L"FR\flag.bmp", L"DE\flag.bmp", L"ES\flag.bmp",
								   L"IT\flag.bmp", L"NL\flag.bmp", L"HU\flag.bmp", L"US\flag.bmp",
								   L"CAT\flag.bmp", L"RU\flag.bmp", L"CZ\flag.bmp" };

	std::vector<TBitmap*> ImagesOn;
	std::vector<TBitmap*> ImagesOff;
	std::vector<TBitmap*> FileTypes;

	void LoadIcons(const std::wstring);
	void LoadFlags(const std::wstring);

public:

	std::vector<TBitmap*> Flags;

	ImageHandler(const std::wstring);
};
