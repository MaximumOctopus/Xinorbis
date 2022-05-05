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


#include "UserData.h"


UserData::UserData(void)
{
    Name    = L"";
    Data[0] = 0;
    Data[1] = 0;

    for (int t = 0; t < __FileCategoriesCount; t++)
    {
        CategoryDataQty[t]  = 0;
        CategoryDataSize[t] = 0;
    }
}