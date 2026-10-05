// =====================================================================
//
//   Xinorbis 10.0
//
// (c) Paul Alan Freshney 2002-2026
//
// paul@freshney.org
//
// https://maximumoctopus.hashnode.dev/
//
// https://github.com/MaximumOctopus/Xinorbis
//
// =====================================================================

#pragma once

#include <vector>

#include "FolderHistoryObject.h"


class FolderHistoryInfo
{
public:

	std::wstring ScanPath = L"";
	std::wstring ComputerName = L"";
	std::wstring MD5 = L"";
};


class FolderHistoryHandler
{
public:

	std::vector<FolderHistoryObject*> FolderHistory;
	std::vector<FolderHistoryInfo*> FolderHistoryAvailable;

    bool Load(const std::wstring, const std::wstring, TStrings*);
};
