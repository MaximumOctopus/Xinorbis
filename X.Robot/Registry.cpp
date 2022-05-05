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


#include <iostream>
#include <string>
#include <tchar.h>
#include <windows.h>

#include "Registry.h"


std::wstring Registry::ReadRegistryString(HKEY hKey, std::wstring aKeyname, std::wstring aDefaultValue)
{
	const DWORD SIZE = 1024;
	wchar_t szValue[SIZE];
	DWORD dwValue = SIZE;
	DWORD dwType = 0;

	long dwRet = RegQueryValueEx(hKey,
		aKeyname.c_str(),
		NULL,
		&dwType,
		(LPBYTE)&szValue,
		&dwValue);

	if ((dwRet != ERROR_SUCCESS) || (dwType != REG_SZ))
	{
		return aDefaultValue;
	}

	return szValue;
}


int Registry::ReadRegistryInteger(HKEY hKey, std::wstring aKeyname, int aDefaultValue)
{
	DWORD dwBufferSize(sizeof(DWORD));
	DWORD nResult(0);
	DWORD dwType = 0;

	long dwRet = RegQueryValueEx(hKey,
		aKeyname.c_str(),
		NULL,
		&dwType,
		reinterpret_cast<LPBYTE>(&nResult),
		&dwBufferSize);

	if (dwRet != ERROR_SUCCESS)
	{
		return aDefaultValue;
	}

	return nResult;
}


bool Registry::ReadRegistryBool(HKEY hKey, std::wstring aKeyname, bool aDefaultValue)
{
	DWORD val = 0;
	DWORD valSize = sizeof(DWORD);
	DWORD valType = REG_NONE;

	long ret = RegQueryValueEx(hKey, 
		                       aKeyname.c_str(),
							   NULL,
		                       &valType,
		                       (PBYTE)&val, &valSize);

	if ((ERROR_SUCCESS == ret) && (REG_DWORD == valType))
	{
		return (0 != val);
	}

	return aDefaultValue;
}


bool Registry::WriteRegistryString(HKEY hKey, const std::wstring& aKeyName, const std::wstring& value)
{
	return (RegSetValueExW(hKey,
		                   aKeyName.c_str(),
		                   0,
		                   REG_SZ,
		                   (LPBYTE)(value.c_str()),
		                   (value.size() + 1) * sizeof(wchar_t)) == ERROR_SUCCESS);		         
}