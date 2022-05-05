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
// February 11th 2019
//


#pragma once


#include <string>
#include <Windows.h>


namespace Registry
{
	std::wstring ReadRegistryString(HKEY hKey, std::wstring aKeyname, std::wstring aDefaultValue);

	int ReadRegistryInteger(HKEY hKey, std::wstring aKeyname, int aDefaultValue);

	bool ReadRegistryBool(HKEY hKey, std::wstring aKeyname, bool aDefaultValue);


	bool WriteRegistryString(HKEY hKey, const std::wstring& aKeyName, const std::wstring& value);
}