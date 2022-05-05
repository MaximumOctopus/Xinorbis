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
// February 24th 2019
//


#pragma once


#include <string>
#include <Windows.h>


class FileDateObject
{
public:
	int Year;
	
	int Count;
	unsigned __int64 Size;

	FileDateObject(int oYear);
};