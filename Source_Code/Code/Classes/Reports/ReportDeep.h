// =====================================================================
//
// FolderScanUltra 5
//
// (c) Paul Alan Freshney 2019-2026
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FolderScanUltra
// 
// =====================================================================

#pragma once


#include <string>
#include <vector>

#include "ReportHTMLOptions.h"
#include "SizeOfFolder.h"


class ReportDeep
{
public:

	std::vector<SizeOfFolder> FolderData;

	unsigned __int64 largestSize = 0;
	unsigned __int64 largestCount = 0;

	// ======================================================================

	ReportDeep();

	void Add(std::wstring folder, unsigned __int64 size, int file_count);

	bool ProcessFolder(int);
};