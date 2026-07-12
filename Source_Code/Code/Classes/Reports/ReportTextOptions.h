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

#include <string>
#include "ConstantsReports.h"


struct TextReportOptions
{
	std::wstring FileName = L"";

	std::wstring Layout = L"";
	bool CategoryList[__FileCategoriesCount] = { false };

	bool DeepScan = false;

	bool AutoOpen = false;

	void LoadCategoryList(const std::wstring input)
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (i < __FileCategoriesCount)
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
