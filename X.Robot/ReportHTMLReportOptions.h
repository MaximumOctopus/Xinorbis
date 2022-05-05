//
// X.Robot 4.0 :: C++ rewrite
//
// (c) Paul Alan Freshney 2019-2020
//     Maximum Octopus Limited
//
// xinorbis.com
// maximumoctopus.com
// 
// twitter.com/maximumoctopus
//
//
// January 30th 2019
//


#pragma once


#include "Constants.h"
#include <string>


static const int __HTMLLayoutOptionsCount = 10;


struct HTMLReportOptions
{
	std::wstring Filename;
	int Units;
	std::wstring Align;
	bool Layout[__HTMLLayoutOptionsCount];
	int LayoutSize;						 // 1 = 800x600, 2 = 1024x768, 3 = 1280x960
	bool CategoryList[20];
	bool AutoOpen;
};