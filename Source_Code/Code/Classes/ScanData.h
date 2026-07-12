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

#include "Consolidated.h"
#include "ConstantsData.h"
#include "SizeOfFolder.h"
#include "UserData.h"


enum class ScanSource { None = 0, LiveScan = 1, CSVImport = 2 };


class ScanData
{
public:

	bool HasLengthData = false;

	int RootFolderIndex = 0;

	ScanSource Source = ScanSource::None;

	int FileCount = 0;
	int FolderCount = 0;
	unsigned __int64 TotalSize = 0;
	unsigned __int64 TotalSizeOD = 0;
	unsigned __int64 AverageFileSize = 0;
	float AverageFilesPerFolder = 0;

	ConsolidatedData Magnitude[__MagnitudesCount];
	ConsolidatedData FileAttributes[__AttributesCount];
	ConsolidatedData ExtensionSpread[__FileCategoriesCount];

	ConsolidatedData Lengths[280];

	std::vector<FileObject> Files;
	std::vector<std::wstring> Folders;

	std::vector<std::wstring> TemporaryFiles;

	std::vector<std::wstring> NullFiles;
	std::vector<std::wstring> NullFolders;

	std::vector<FileObject> Top100Large;
	std::vector<FileObject> Top100Small;
	std::vector<FileObject> Top100Newest;
	std::vector<FileObject> Top100Oldest;

	std::vector<FileDateObject> FileDates;

	std::vector<UserData> Users;

	std::vector<FileObject> RootFiles;
	std::vector<RootFolder> RootFolders;

	void Clear()
	{
		FileCount   = 0;
		FolderCount = 0;
		TotalSize   = 0;
		TotalSizeOD = 0;

		for (int t = 0; t < __MagnitudesCount; t++)
		{
			Magnitude[t].Count = 0;
			Magnitude[t].Size = 0;
		}

		for (int t = 0; t < __AttributesCount; t++)
		{
			FileAttributes[t].Count = 0;
			FileAttributes[t].Size = 0;
		}

		for (int t = 0; t < __FileCategoriesCount; t++)
		{
			ExtensionSpread[t].Count = 0;
			ExtensionSpread[t].Size = 0;
		}

		HasLengthData = false;

		for (int t = 0; t < 280; t++)
		{
			Lengths[t].Clear();
		}

		Files.clear();
		Folders.clear();

		TemporaryFiles.clear();

		NullFiles.clear();
		NullFolders.clear();

		Top100Large.clear();
		Top100Small.clear();
		Top100Newest.clear();
		Top100Oldest.clear();

		FileDates.clear();

		Users.clear();

		RootFiles.clear();
		RootFolders.clear();

		RootFolder rfd;

		rfd.Name        = L"\\ (root)";
		rfd.Attributes  = 0;
		rfd.Size        = 0;
		rfd.Count       = 0;
		rfd.FilesInRoot = true;

		RootFolders.push_back(rfd);
	}


	// folder_name must terminate with "\"
	SizeOfFolder GetSizeOfFolder(const std::wstring folder_name)
	{
		SizeOfFolder sof;

		for (FileObject file : Files)
		{
			if (file.Category != __FileCategoryDirectory)
			{
				std::wstring full_path = Folders[file.FilePathIndex];

				if (full_path.compare(0, folder_name.size(), folder_name))
				{
					sof.Size += file.Size;
					sof.SizeOnDisk += file.SizeOnDisk;

					sof.FileCount++;
				}
			}
		}

		return sof;
	}


	// folder_name must terminate with "\"
	int GetFullFolderIndex(const std::wstring folder_name)
	{
		for (int t = 0; t < Folders.size(); t++)
		{
			if (Folders[t] == folder_name)
			{
				return t;
			}
		}

        return -1;
	}
};
