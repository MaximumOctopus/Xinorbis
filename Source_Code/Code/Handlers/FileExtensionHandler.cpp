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
#include <string>

#include "ConstantsData.h"
#include "ConstantsReports.h"
#include "FileExtension.h"
#include "FileExtensionHandler.h"
#include "Formatting.h"
#include "Registry.h"
#include "Utility.h"

FileExtensionHandler* GFileExtensionHandler;

bool sortByName (FileExtension *lhs, FileExtension *rhs) {return lhs->Name < rhs->Name; }


FileExtensionHandler::FileExtensionHandler(const std::wstring folder)
{
	LoadFileExtensions(folder, false);
}


bool FileExtensionHandler::LoadFileExtensions(const std::wstring folder, bool force_default)
{
	Extensions.clear();

	std::wstring path = folder + L"system\\config\\";

	if (force_default)
	{
		path += L"DefaultExtensions\\";
	}

	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		std::wstring FileName = path +  kFileExtensionFileName[t] + L".txt";

		std::wifstream file(FileName);

		if (file)
		{
			std::wstring s;

			while (std::getline(file, s))
			{
				if (s.find('\n') != std::string::npos)
				{
					s.erase(std::remove(s.begin(), s.end(), '\n'), s.begin()); // to do, does it contain \n? do we need it?!
				}

				FileExtension *file_extension = new FileExtension(s, t);

				Extensions.push_back(file_extension);
			}

			file.close();
		}
	}

	Sort();

	#ifdef _DEBUG
	ReportDuplicates();
	#endif

	return true;
}


bool FileExtensionHandler::LoadDescriptions(const std::wstring folder)
{
	std::wstring FileName = folder + L"system\\index\\xinfe.txt";

	std::wifstream file(FileName);

	if (file)
	{
		std::wstring s = L"";

		while (std::getline(file, s))
		{
			auto idx = s.find(L' ');

			if (idx != std::wstring::npos)
			{
				std::transform(s.begin(), s.begin() + idx, s.begin(), ::toupper);
            }

			Descriptions.push_back(s);
		}

		file.close();
	}

	return false;
}


void FileExtensionHandler::Sort()
{
	std::sort(Extensions.begin(), Extensions.end(), sortByName);
}


bool FileExtensionHandler::SaveFileExtensionLists(const std::wstring path, bool to_registry, bool to_local_path)
{
	if (to_registry)
	{
		HKEY hKey;

		for (int z = 0; z < kFileCategoriesCount; z++)
		{
			if (Registry::Open(hKey, L"\\software\\MaximumOctopus\\\Xinorbis10\\FileExt" + std::to_wstring(z), true) == ERROR_SUCCESS)
			{
				for (int c = 0; c < Extensions.size(); c++)
				{
					if (Extensions[c]->Category == z)
					{
						Registry::WriteString(hKey, L"Ext" + std::to_wstring(c), Extensions[c]->Name);
					}
				}

				Registry::WriteString(hKey, L"Ext" + std::to_wstring(Extensions.size()), L":");

				Registry::Close(hKey);
            }
        }
	}

	if (to_local_path)
	{
		for (int z = 0; z < kFileCategoriesCount; z++)
		{
			std::ofstream file(path + L"system\\config\\" + kFileExtensionFileName[z] + L".txt");

			if (file)
			{
				for (int c = 0; c < Extensions.size(); c++)
				{
					if (Extensions[c]->Category == z)
					{
						file << Formatting::to_utf8(Extensions[c]->Name + L"\n");
					}
				}

				file.close();
			}
			else
			{
				return false;
			}
		}
	}

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

	return kFileCategoriesOther;
}


ExtensionSearch FileExtensionHandler::GetExtensionCategoryID(const std::wstring extension)
{
	ExtensionSearch extension_search;

	auto pos = std::find_if(Extensions.begin(), Extensions.end(),
							[extension](const FileExtension *fx) { return fx->Name == extension; });

	if (pos != Extensions.end())
	{
		extension_search.Found = true;
		extension_search.Category = (*pos)->Category;
		extension_search.Extension = std::distance(std::begin(Extensions), pos);

		return extension_search;
	}

	return extension_search;
}


int FileExtensionHandler::GetExtensionCategory(const std::wstring extension)
{
	auto pos = std::find_if(Extensions.begin(), Extensions.end(),
							[extension](const FileExtension* fx) { return fx->Name == extension; });

	if (pos != Extensions.end())
	{
		return (*pos)->Category;
	}

	return kFileCategoriesOther;
}


void FileExtensionHandler::ReportDuplicates()
{
	bool found = false;

	for (int z = 0; z < Extensions.size() - 1; z++)
	{
		int index = z + 1;

		while (index < Extensions.size() && Extensions[index]->Name == Extensions[z]->Name)
		{
			//GLog->Add( << L"Duplicate extension: " << Extensions[z]->Name << L" : " << __FileExtensionFileName[Extensions[z]->Category] << L" & " << __FileExtensionFileName[Extensions[index]->Category] << "\n";

			index++;

			found = true;
		}
	}
}
