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
#include <Windows.h>


class RootFolder
{
public:
	std::wstring Name;

	DWORD Attributes;
	unsigned __int64 Data[2];   // [0] count
								// [1] size
};