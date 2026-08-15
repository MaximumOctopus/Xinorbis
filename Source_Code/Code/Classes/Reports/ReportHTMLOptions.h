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
#include "ConstantsReports.h"
#include "HTMLColours.h"
#include <string>


static const int kHTMLLayoutOptionsCount = 11;


struct HTMLReportOptions
{
	std::wstring FileName = L"";
	int Units = 0;
	std::wstring Align = L"";
	std::wstring Layout = L"";
	int LayoutSize = 2;						 // 0 = 800x600, 1 = 1024x768, 2 = 1280x960
	bool CategoryList[kFileCategoriesCount] = { 0 };
	bool AutoOpen = false;

	HTMLColours Colours;

	bool DeepScan = false;

	void LoadCategoryList(const std::wstring input)
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (i < kFileCategoriesCount)
			{
				if (input[i])
				{
					CategoryList[i] = true;
				}
				else
				{
					CategoryList[i] = false;
				}
			}
		}
	}
};
