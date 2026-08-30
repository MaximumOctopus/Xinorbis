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
	if (!folder.empty())
	{
		LoadIcons(folder + L"\\system\\images\\");
	}
}


ImageHandler::~ImageHandler()
{
}


void ImageHandler::LoadIcons(const std::wstring folder)
{
	for (int t = 0; t < kButtonImagesCount; t++)
	{
		std::wstring file_name = folder + L"\\On\\" + std::to_wstring(t) + L".bmp";

		TBitmap *bmon = new TBitmap();
		bmon->LoadFromFile(file_name.c_str());
		ImagesOn.push_back(bmon);
		bmon->Free();

		file_name = folder + L"\\Off\\" + std::to_wstring(t) + L".bmp";
		TBitmap *bmon2 = new TBitmap();
		bmon2->LoadFromFile(file_name.c_str());
		ImagesOff.push_back(bmon);
		bmon2->Free();
	}

	for (int t = 0; t < kFileTypeImagesCount; t++)
	{
		std::wstring file_name = folder + L"\\Icons\\" + std::to_wstring(t) + L".bmp";

		TBitmap *bmft = new TBitmap();
		bmft->LoadFromFile(file_name.c_str());
		FileTypes.push_back(bmft);
		bmft->Free();
	}
}


void ImageHandler::LoadFlags(const std::wstring folder)
{
	for (int t = 0; t < 11; t++)
	{
		TBitmap* flag = new TBitmap();
		flag->LoadFromFile((folder + FlagFiles[t]).c_str());

		Flags.push_back(flag);

		delete flag;
	}
}


void ImageHandler::SetButtonOnImage(TSpeedButton* button, int inded)
{
}


void ImageHandler::SetButtonOffImage(TSpeedButton* button, int inded)
{
}


void ImageHandler::SetFolderHistoryButtonImage(TSpeedButton* button, int index)
{
}


void ImageHandler::SetPieBarImages(TSpeedButton* button1, TSpeedButton* button2)
{
	if (button1->Down)
	{
		SetButtonOnImage(button1, kImagePieGraph);
		SetButtonOffImage(button2, kImageBarGraph);
	}
	else
	{
		SetButtonOnImage(button2, kImageBarGraph);
		SetButtonOffImage(button1, kImagePieGraph);
	}
}
