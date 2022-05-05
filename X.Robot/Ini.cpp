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


#include "Ini.h"

#include <algorithm>
#include <codecvt>
#include <fstream>
#include <locale>
#include <string>
#include <vector>



Ini::Ini(std::wstring fileName)
{
	Loaded = LoadFile(fileName);
}


bool Ini::LoadFile(std::wstring fileName)
{
	std::wifstream file(fileName);

	file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

	if (file)
	{
		Lines.clear();

		std::wstring s;

		while (std::getline(file, s))
		{
			if (s != L"")
			{
				Lines.push_back(s);
			}
		}

		file.close();

		return true;

	}

	return false;
}


int Ini::ReadInteger(std::wstring section, std::wstring key, int default)
{
	std::wstring::size_type sz;   // alias of size_t

	try
	{
		int i = std::stoi(ReadString(section, key, L"-1"), &sz);

		if (i == -1)
		{
			return default;
		}

		return i;
	}
	catch(...)
	{
		return default;
	}
}


std::wstring Ini::ReadString(std::wstring section, std::wstring key, std::wstring default)
{
	bool inSection = false;
	std::wstring sectionName = L"";

	key = key + L'=';

	std::transform(section.begin(), section.end(), section.begin(), ::tolower);

	for (int i = 0; i < Lines.size(); i++)
	{
		if (Lines[i][0] == L'[')
		{
			if (inSection)
			{
				// we were in the right section, but now entered a new one.... which means the key we're looking
				// for must be missing, so return the default value

				return default;
			}
			else
			{
				std::size_t bo = Lines[i].find(L"[");
				std::size_t bc = Lines[i].find(L"]");

				sectionName = Lines[i].substr(bo + 1, bc - 1);

				std::transform(sectionName.begin(), sectionName.end(), sectionName.begin(), ::tolower);

				if (sectionName == section)
				{
					inSection = true;
				}
			}
		}
		else
		{
			if (inSection)
			{
				if (Lines[i] != L"")
				{
					if ((Lines[i][0] != L';') && (Lines[i][0] != L'/'))
					{
						if (Lines[i].find(key) == 0)
						{
							if (Lines[i].length() > key.length())
							{
								return Lines[i].substr(key.length());
							}
							else
							{
								// key is emtpy (key= ) so let's return the default                                

								return default;
							}
						}
					}
				}
			}
		}
	}

	return default;
}