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
#include <vector>


class Ini
{
private:
	bool LoadFile(std::wstring fileName);

public:

	bool Loaded;

	std::vector<std::wstring> Lines;

	Ini(std::wstring fileName);

	std::wstring ReadString(std::wstring section, std::wstring key, std::wstring default);
	int ReadInteger(std::wstring section, std::wstring key, int default);
};