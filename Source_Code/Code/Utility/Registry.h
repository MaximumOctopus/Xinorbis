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
#include <Windows.h>


namespace Registry
{
	LONG Open(HKEY&, const std::wstring, bool);
	LONG Close(HKEY&);

	std::wstring ReadString(HKEY, std::wstring, std::wstring);

	int ReadInteger(HKEY, std::wstring, int);

	bool ReadBool(HKEY, std::wstring, bool);

	bool WriteInteger(HKEY hKey, const std::wstring&, int);

	bool WriteString(HKEY, const std::wstring&, const std::wstring&);

	bool Delete(HKEY, const std::wstring&);
}