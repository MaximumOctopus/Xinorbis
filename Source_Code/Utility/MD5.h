


#pragma once

#include <string>
#include <Windows.h>
#include <wincrypt.h>
#include <windef.h>


namespace MD5
{
	[[nodiscard]] std::wstring GetMD5HashString(char* pcValue);
}