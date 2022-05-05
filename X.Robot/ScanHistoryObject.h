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
// February 10th 2019
//


#pragma once


#include <string>


class ScanHistoryObject
{
public:

	int DateI;
	std::wstring TimeI;

	std::wstring Path;

	std::wstring ExcludeFiles;
	std::wstring ExcludeFolders;
};