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


struct DateReportOptions
{
	std::wstring FileName = L"";

	bool Created = true;
	bool OutputSorted = false;

	bool Day = false;
	bool Month = false;
	bool Year = false;
};