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

static const std::wstring kFileExtensionFileName[] = { L"Temp", L"Programs", L"System", L"Graphics", L"Movie", L"Audio", L"Office", L"Programming", L"Compressed", L"Other",
													   L"Custom1", L"Custom2", L"Custom3", L"Custom4", L"Custom5", L"Custom6", L"Custom7", L"Custom8", L"Custom9", L"Custom10" };


class FileExtensionHandler
{

public:

	std::vector<FileExtension*> Extensions;
	std::vector<std::wstring> Descriptions;

	FileExtensionHandler(const std::wstring);

	bool LoadFileExtensions(const std::wstring, bool);

	bool LoadDescriptions(const std::wstring);

	void Sort();

	bool SaveFileExtensionLists(const std::wstring, bool, bool);

	int GetExtensionCategoryIDFromName(const std::wstring);
	ExtensionSearch GetExtensionCategoryID(const std::wstring);
	int GetExtensionCategory(const std::wstring);

	void ReportDuplicates();
};
