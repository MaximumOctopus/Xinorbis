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

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "ConstantsData.h"
#include "ConstantsReports.h"
#include "FileExtension.h"
#include "FileExtensionHandler.h"
#include "Utility.h"

FileExtensionHandler* GFileExtensionHandler;


FileExtensionHandler::FileExtensionHandler(const std::wstring folder)
{
	LoadDefaultFileExtensions(folder);
}


bool FileExtensionHandler::LoadDefaultFileExtensions(const std::wstring folder)
{
	for (int t = 0; t < __FileCategoriesCount; t++)
	{
		std::wstring fileName = folder + L"system\\config\\DefaultExtensions\\" + __FileExtensionFileName[t] + L".txt";

		std::wifstream file(fileName);

		if (file)
		{
			std::wstring s;

			while (std::getline(file, s))
			{
				FileExtension file_extension;

				if (s.find('\n') != std::string::npos)
				{
					s.erase(std::remove(s.begin(), s.end(), '\n'), s.begin()); // to do, does it contain \n? do we need it?!
				}

				file_extension.Name     = s;
				file_extension.Category = t;

				Extensions.push_back(file_extension);
			}

			file.close();
		}
	}

   // to do	std::ranges::sort(Extensions, {}, &FileExtension::Name);

	#ifdef _DEBUG
	ReportDuplicates();
	#endif

	return true;
}


int FileExtensionHandler::GetExtensionCategoryIDFromName(const std::wstring file_name)
{
	std::wstring ext = Utility::GetFileExtension(file_name);

	ExtensionSearch exi = GetExtensionCategoryID(ext);

	if (exi.Found)
	{
		return exi.Category;
	}

	return __FileCategoriesOther;
}


ExtensionSearch FileExtensionHandler::GetExtensionCategoryID(const std::wstring extension)
{
	ExtensionSearch extension_search;

	auto pos = std::find_if(Extensions.begin(), Extensions.end(),
						    [extension](const FileExtension& fx) { return fx.Name == extension; });

	if (pos != Extensions.end())
	{
		extension_search.Found = true;
		extension_search.Category = pos->Category;
		extension_search.Extension = std::distance(std::begin(Extensions), pos);

		return extension_search;
	}

	return extension_search;
}


int FileExtensionHandler::GetExtensionCategory(const std::wstring extension)
{
	auto pos = std::find_if(Extensions.begin(), Extensions.end(),
							[extension](const FileExtension& fx) { return fx.Name == extension; });

	if (pos != Extensions.end())
	{
		return pos->Category;
	}

	return __FileCategoriesOther;
}


void FileExtensionHandler::ReportDuplicates()
{
	bool found = false;

	for (int z = 0; z < Extensions.size() - 1; z++)
	{
		int index = z + 1;

		while (index < Extensions.size() && Extensions[index].Name == Extensions[z].Name)
		{
			std::wcout << L"Duplicate extension: " << Extensions[z].Name << L" : " << __FileExtensionFileName[Extensions[z].Category] << L" & " << __FileExtensionFileName[Extensions[index].Category] << "\n";

			index++;

			found = true;
		}
	}
}
