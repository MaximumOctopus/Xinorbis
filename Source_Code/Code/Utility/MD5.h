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
#include <wincrypt.h>
#include <windef.h>


namespace MD5
{
	[[nodiscard]] std::wstring Generate(char* pcValue);
}