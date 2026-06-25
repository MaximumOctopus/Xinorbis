#include <string>
#include <Windows.h>
#include <wincrypt.h>
#include <windef.h>
#include <iostream>


#pragma once


#include <string>


namespace MD5
{
	[[nodiscard]] std::wstring GetMD5HashString(char* pcValue);
}