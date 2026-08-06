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

#include <fstream>

#include "FileIO.h"


bool FileIO::LoadIntoVector(std::vector<std::wstring> *data, const std::wstring file_name)
{
	std::wifstream file(file_name);

	if (file)
	{
		data->clear();

		std::wstring s = L"";

        while (std::getline(file, s))
		{
            data->push_back(s);
		}

		file.close();

		return true;
	}

	return false;
}
