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


#include "ConstantsData.h"
#include <string>


static const int __HTMLLayoutOptionsCount = 11;


struct HTMLReportOptions
{
	std::wstring FileName = L"";
	int Units = 0;
	std::wstring Align = L"";
	bool Layout[__HTMLLayoutOptionsCount] = { false };
	int LayoutSize = 2;						 // 0 = 800x600, 1 = 1024x768, 2 = 1280x960
	bool CategoryList[20] = { 0 };
	bool AutoOpen = false;

	bool DeepScan = false;
};
