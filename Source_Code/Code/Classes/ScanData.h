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

#include <set>
#include <vector>

#include "Command.h"
#include "Consolidated.h"
#include "ConstantsData.h"
#include "DateUtility.h"
#include "FileDateObject.h"
#include "FileObject.h"
#include "FileObjectSorted.h"
#include "RootFolder.h"
#include "SizeOfFolder.h"
#include "UserData.h"


enum class ScanSource { None = 0, LiveScan, FileXinorbisNormal, FileXinorbisDetails, FileXinorbis2Details,
						FileCSV, LiveShare, FolderHistory, SearchResults };

struct ScanPath
{
	std::wstring CSVSource = L"";

	std::wstring String = L"";
	std::wstring DateStr = L"";
	std::wstring DateInt = L"";

	bool Set = false;

	bool ExcludeFolders = false;
	int ExcludedFolderCount = 0;

	bool ExcludeFiles = false;
	int ExcludedFilesCount = 0;

	bool LastScanMultiple = false;

	void Update(const std::wstring folder)
	{
		if (folder.back() == L'\\')
		{
			String = folder;
		}
		else
		{
			String = folder + L"\\";
		}

		DateStr = DateUtility::DateTime(0);
		DateInt = DateUtility::DateTime(1);
	}
};


class ScanData
{

    void AddUserNotSpecified();

public:

	bool HasLengthData = false;

	int RootFolderIndex = 0;

	ScanSource Source = ScanSource::None;

    ScanPath Path;

	int FileCount = 0;
	int FolderCount = 0;
	unsigned __int64 TotalSize = 0;
	unsigned __int64 TotalSizeOD = 0;
	unsigned __int64 AverageFileSize = 0;
	float AverageFilesPerFolder = 0;

	ConsolidatedData Magnitude[kMagnitudesCount];
	ConsolidatedData FileAttributes[kAttributesCount];
	ConsolidatedData ExtensionSpread[kFileCategoriesCount];

	ConsolidatedData Lengths[280];

	std::set<FileObjectSorted> SortedFiles;

	std::vector<FileObject*> Files;
	std::vector<std::wstring> Folders;

	std::vector<std::wstring> TemporaryFiles;

	std::vector<std::wstring> NullFiles;
	std::vector<std::wstring> NullFolders;

	std::vector<FileObject*> Top100Large;
	std::vector<FileObject*> Top100Small;
	std::vector<FileObject*> Top100Newest;
	std::vector<FileObject*> Top100Oldest;

	std::vector<FileDateObject*> FileDates;

	std::vector<UserData*> Users;

	std::vector<FileObject*> RootFiles;
	std::vector<RootFolder*> RootFolders;

	ScanData();

	void Clear();

	// folder_name must terminate with "\"
	SizeOfFolder GetSizeOfFolder(const std::wstring);

	// folder_name must terminate with "\"
	int GetFullFolderIndex(const std::wstring);


	std::wstring GetScanPathFromFolderList();

	void PopulateSortedFiles();

	// searches for a single term within file name
	void Search(Command);

	void BuildFileDates();
	void BuildTop100SizeLists();
	void BuildTop100DateLists();

	int RootIndex();

	void ListRoot();

	SizeOfFolder GetSizeOfFolder(const std::wstring, const std::wstring);

	std::wstring GetDrive();

	int GetFolderIndex(const std::wstring);

	int FindUser(std::wstring);

	// Sorting
	void SortRootBySize();
	void SortByProperty(int property);

	// Export data
	void SaveRawData(Command command);

	// Import
	FileObject* ImportRow(const std::wstring);
	bool ImportFromCSV(const std::wstring);

	// Export settings
	std::wstring ToJSON();
};
