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
#include "ExtensionSearch.h"
#include "FileExtension.h"
#include <vector>


class FileExtensionHandler
{
public:
	std::vector<FileExtension> Extensions;

	FileExtensionHandler();

	bool LoadDefaultFileExtensions();

	int GetExtensionCategoryIDFromName(const std::wstring name);
	ExtensionSearch GetExtensionCategoryID(std::wstring extension);
};