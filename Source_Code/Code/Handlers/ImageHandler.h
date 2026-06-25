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

	std::vector<TBitmap*> ImagesOn;
	std::vector<TBitmap*> ImagesOff;
	std::vector<TBitmap*> FileTypes;

	void LoadIcons(const std::wstring);

public:

    ImageHandler(const std::wstring);

};
