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


struct CSVReportOptions
{
	std::wstring FileName = L"";

	int Separator = 0;
	int Units = 0;
	bool Titles = true;
	int Category = -1; //0-14 or -1 for ALL
};