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

#include "ConstantsImages.h"
#include "ImageHandler.h"

ImageHandler* GImageHandler;


ImageHandler::ImageHandler(const std::wstring folder)
{
    LoadIcons(folder);
}


void ImageHandler::LoadIcons(const std::wstring folder)
{
	for (int t = 0; t < kButtonImagesCount; t++)
	{
		std::wstring file_name = folder + L"\On\\" + std::to_wstring(t) + L".bmp";

		TBitmap *bmon = new TBitmap();
		bmon->LoadFromFile(file_name.c_str());
		ImagesOn.push_back(bmon);
		bmon->Free();

		file_name = folder + L"\Off\\" + std::to_wstring(t) + L".bmp";
		TBitmap *bmon2 = new TBitmap();
		bmon2->LoadFromFile(file_name.c_str());
		ImagesOff.push_back(bmon);
		bmon2->Free();
	}

	for (int t = 0; t < kFileTypeImagesCount; t++)
	{
		std::wstring file_name = folder + L"\Icons\\" + std::to_wstring(t) + L".bmp";

		TBitmap *bmft = new TBitmap();
		bmft->LoadFromFile(file_name.c_str());
		FileTypes.push_back(bmft);
		bmft->Free();
	}
}
