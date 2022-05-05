//
// X.Robot 4.0 :: C++ rewrite
//
// (c) Paul Alan Freshney 2019-2020
//     Maximum Octopus Limited
//
// xinorbis.com
// maximumoctopus.com
// 
// twitter.com/maximumoctopus
//
//
// January 30th 2019
//


#pragma once


#include <string>
#include "Constants.h"


class UserData
{
public:
    std::wstring Name;
    
	unsigned __int64 Data[2];

    int CategoryDataQty[__FileCategoriesCount];
	unsigned __int64 CategoryDataSize[__FileCategoriesCount];

    UserData(void);
};