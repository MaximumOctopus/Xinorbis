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
#include <Windows.h>


namespace Convert
{
	std::wstring AttributeToIntAsString(int aAttributeData, int aAttributeValue);
	std::wstring ConvertToUsefulUnit(unsigned __int64 aValue);
	std::wstring DoubleToPercent(double aValue);
	std::wstring GetSizeString(int aUnits, unsigned long long aSize);

	std::wstring BoolToString(bool aInput);

	int FileTimeToDateInt(FILETIME* lFileTime);
	int FileTimeToTimeInt(FILETIME* lFileTime);
	std::wstring IntDateToString(int dx);
	std::wstring IntToHex(int aValue, int aSize);

	std::wstring WebColour(int aColour);

	int StrToIntDef(std::wstring input, int default);
};