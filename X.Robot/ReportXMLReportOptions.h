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

#include <string>


static const int XMLReportOptionsCount = 10;


struct XMLReportOptions
{
	std::wstring Filename;
	bool Layout[XMLReportOptionsCount];
};