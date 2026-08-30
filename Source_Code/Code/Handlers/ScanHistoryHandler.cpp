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

#include "ConstantsSystem.h"
#include "DateUtility.h"
#include "Formatting.h"
#include "Registry.h"
#include "ScanHistoryHandler.h"

ScanHistoryHandler *GScanHistoryHandler;


ScanHistoryHandler::ScanHistoryHandler(const std::wstring path)
{
	Load(path + L"scanhistory.dat", true);
}


ScanHistoryHandler::~ScanHistoryHandler()
{
	Save();
}


void ScanHistoryHandler::Add(const std::wstring path, const std::wstring exclude_files, const std::wstring exclude_folders)
{
	ScanHistoryItem *shi = new ScanHistoryItem();

	shi->Path = path;
	shi->Date = stoi(DateUtility::GetDate(DateTimeFormat::YYYYMMDD));
	shi->Time = DateUtility::GetTime(DateTimeFormat::HHMM);
	shi->ExcludeFiles = exclude_files;
	shi->ExcludeFolders = exclude_folders;

	History.push_back(shi);
}


bool ScanHistoryHandler::Load(const std::wstring path, bool from_file)
{
	if (from_file)
	{
		FilePath = path;
		FromFile = from_file;

		std::wifstream file(path);

		if (file)
		{
			int param = 0;
            std::wstring s = L"";

			int Date = 19990101;   			// yyyymmdd
			std::wstring Time = L"00:00";   // hhmm
			std::wstring Path = L"";
			std::wstring ExcludeFiles = L"";
			std::wstring ExcludeFolders = L"";

			while (std::getline(file, s))
			{
				switch (param)
				{
				case 0:
					Path = s;
					break;
				case 1:
					Date = stoi(s);
					break;
				case 2:
					Time = s;
					break;
				case 3:
					ExcludeFiles = s;
					break;
				case 4:
				{
					ExcludeFolders = s;

					ScanHistoryItem *shi = new ScanHistoryItem();
					shi->Path = Path;
					shi->Date = Date;
					shi->Time = Time;
					shi->ExcludeFiles = ExcludeFiles;
					shi->ExcludeFolders = ExcludeFolders;

					History.push_back(shi);

					break;
				}
				}

				if (param == 4)
				{
					param = 0;
				}
				else
				{
					param++;
				}
			}

			file.close();

            return true;
		}
	}
	else
	{
		HKEY hKey;

		if (Registry::Open(hKey, L"\\software\\" + __XRegistryPath + L"\\SinglePaths", true) != ERROR_SUCCESS)
		{
			bool success = true;
			int ordinal = 0;

			do
			{
				std::wstring path = Registry::ReadString(hKey, L"PathX" + std::to_wstring(ordinal), L"");

				if (!path.empty())
				{
					ScanHistoryItem *shi = new ScanHistoryItem();
					shi->Path = path;
					shi->Date = Registry::ReadInteger(hKey, L"PathY" + std::to_wstring(ordinal), 19900101);
					shi->Time = Registry::ReadString(hKey, L"PathZ" + std::to_wstring(ordinal), L"00:00");
					shi->ExcludeFiles = Registry::ReadString(hKey, L"PathE1" + std::to_wstring(ordinal), L"");
					shi->ExcludeFolders = Registry::ReadString(hKey, L"PathE2" + std::to_wstring(ordinal), L"");

					History.push_back(shi);

				}
				else
				{
					success = false;
				}
			}
			while (success);

			Registry::Close(hKey);
        }
	}

	return false;
}


void ScanHistoryHandler::Clear()
{
	History.clear();

	HKEY hKey;

	if (Registry::Open(hKey, L"\\software\"" + __XRegistryPath + L"\\SinglePaths", false) == ERROR_SUCCESS)
	{
		Registry::Delete(hKey, L"\\software\"" + __XRegistryPath + L"\\SinglePaths");

		Registry::Close(hKey);
	}
}


bool ScanHistoryHandler::Save()
{
	if (FromFile)
	{
		std::ofstream file(FilePath);

		if (file)
		{
			for (ScanHistoryItem *item : History)
			{
				file << Formatting::to_utf8(item->Path + L"\n");
				file << Formatting::to_utf8(std::to_wstring(item->Date) + L"\n");
				file << Formatting::to_utf8(item->Time + L"\n");
				file << Formatting::to_utf8(item->ExcludeFiles + L"\n");
				file << Formatting::to_utf8(item->ExcludeFolders + L"\n");
            }

			file.close();

			return true;
		}
	}
	else
	{
	}

	return false;
}
