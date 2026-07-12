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

#pragma once

#include <vector>

#include "ExtensionSearch.h"
#include "FileExtension.h"

static const std::wstring __FileExtensionFileName[] = { L"Temp", L"Programs", L"System", L"Graphics", L"Movie", L"Audio", L"Office", L"Programming", L"Compressed", L"Other",
													    L"Custom1", L"Custom2", L"Custom3", L"Custom4", L"Custom5", L"Custom6", L"Custom7", L"Custom8", L"Custom9", L"Custom10" };


class FileExtensionHandler
{

	bool LoadDefaultFileExtensions(const std::wstring);

public:

	std::vector<FileExtension*> Extensions;

	FileExtensionHandler(const std::wstring);

	int GetExtensionCategoryIDFromName(const std::wstring);
	ExtensionSearch GetExtensionCategoryID(const std::wstring);
	int GetExtensionCategory(const std::wstring);

	void ReportDuplicates();
};
