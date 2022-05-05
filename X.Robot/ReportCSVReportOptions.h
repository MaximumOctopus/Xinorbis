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


struct CSVReportOptions
{
	std::wstring Filename;
	int Separator;
	int Units;
	bool Titles;
	int Category; //0-14 or -1 for ALL
};