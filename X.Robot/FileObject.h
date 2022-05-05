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


class FileObject
{
public:
    int FilePathIndex;
    std::wstring FileName;
	unsigned __int64 Size;
    int SizeOnDisk;
    int FileDateC;	// yyyymmdd
    int FileDateA;	// yyyymmdd
    int FileDateM;	// yyyymmdd
    int FileTimeC;	// hhmmss
    int FileTimeA;	// hhmmss
    int FileTimeM;	// hhmmss
	int Category;
    DWORD Attributes;
    bool Temp;
    int Owner;

	FileObject();
};