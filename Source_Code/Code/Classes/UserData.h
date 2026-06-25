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


class UserData
{
public:
    std::wstring Name = L"";

    int Count = 0;
    unsigned __int64 Size = 0;

    int CategoryDataQty[__FileCategoriesCount] = { 0 };
	unsigned __int64 CategoryDataSize[__FileCategoriesCount] = { 0 };

    UserData(const std::wstring);
};
