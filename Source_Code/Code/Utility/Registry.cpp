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

#include <iostream>
#include <string>
#include <tchar.h>
#include <windows.h>

#include "Registry.h"


std::wstring Registry::ReadRegistryString(HKEY hKey, std::wstring key_name, std::wstring aDefaultValue)
{
	const DWORD SIZE = 1024;
	wchar_t szValue[SIZE];
	DWORD dwValue = SIZE;
	DWORD dwType = 0;

	long dwRet = RegQueryValueEx(hKey,
		key_name.c_str(),
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


int Registry::ReadRegistryInteger(HKEY hKey, std::wstring key_name, int default_value)
{
	DWORD dwBufferSize(sizeof(DWORD));
	DWORD nResult(0);
	DWORD dwType = 0;

	long dwRet = RegQueryValueEx(hKey,
		key_name.c_str(),
		NULL,
		&dwType,
		reinterpret_cast<LPBYTE>(&nResult),
		&dwBufferSize);

	if (dwRet != ERROR_SUCCESS)
	{
		return default_value;
	}

	return nResult;
}


bool Registry::ReadRegistryBool(HKEY hKey, std::wstring key_name, bool default_value)
{
	DWORD val = 0;
	DWORD valSize = sizeof(DWORD);
	DWORD valType = REG_NONE;

	long ret = RegQueryValueEx(hKey, 
		                       key_name.c_str(),
							   NULL,
		                       &valType,
		                       (PBYTE)&val, &valSize);

	if ((ERROR_SUCCESS == ret) && (REG_DWORD == valType))
	{
		return (0 != val);
	}

	return default_value;
}


bool Registry::WriteRegistryString(HKEY hKey, const std::wstring& key_name, const std::wstring& value)
{
	return (RegSetValueExW(hKey,
		                   key_name.c_str(),
		                   0,
		                   REG_SZ,
		                   (LPBYTE)(value.c_str()),
		                   (value.size() + 1) * sizeof(wchar_t)) == ERROR_SUCCESS);
}


bool Registry::DeleteRegistry(HKEY hKey, const std::wstring& key_name)
{
	return (RegDeleteValue(hKey, key_name.c_str()) == ERROR_SUCCESS);
}