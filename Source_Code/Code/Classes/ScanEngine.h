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

#include "FileObject.h"

#include <chrono>
#include <set>
#include <string>
#include <vector>

#include "Command.h"
#include "Consolidated.h"
#include "DateUtility.h"
#include "ExecutionParameters.h"
#include "FileDateObject.h"
#include "FileObject.h"
#include "FileObjectSorted.h"
#include "ConstantsReports.h"
#include "RootFolder.h"
#include "ScanData.h"
#include "ScanEngine.h"
#include "SizeOfFolder.h"
#include "UserData.h"


struct Disk
{
	unsigned __int64 DriveSpaceTotal = 0;
	unsigned __int64 DriveSpaceFree = 0;
	unsigned __int64 DriveSpaceUsed = 0;

	std::wstring diskType = L"";

	int sectorsPerCluster = 0;
	int bytesPerSector = 0;
	int freeClusters = 0;
	int totalClusters = 0;

	std::wstring volumeName = L"";
	std::wstring serialNumber = L"";
	std::wstring fileSystem = L"";
};


struct SearchData
{
	std::vector<FileObject> Files;

	int FileCount = 0;
	int FolderCount = 0;
	unsigned __int64 TotalSize = 0;

	void Clear()
	{
		Files.clear();

		FileCount = 0;
		FolderCount = 0;
		TotalSize = 0;
	}
};


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


class ScanEngine
{
private:

	int CurrentFolderIndex = 0;
	std::wstring CurrentFolder = L"";

    void Init();
	void InitLanguage();

	void PopulateDiskStat();

	FileObject ImportRow(const std::wstring);
	bool ImportFromCSV(const std::wstring);
	std::wstring GetScanPathFromFolderList();

	[[nodiscard]] bool Import(bool, bool, bool, bool);
	[[nodiscard]] bool Scan(bool, bool, bool, bool);

	void ScanFolder(const std::wstring&);
	void ScanFolderExt(const std::wstring&);
	void PostScan();

	bool Analyse();
	bool AnalyseFast();
	void AnalyseRootFolders();
	void AnalysePostExtensionSpread();

	void BuildFileDates();

	void BuildTop100SizeLists();
	void BuildTop100DateLists();

	int RootIndex();

public:

	std::vector<std::wstring> ExcludedFolders;
	std::vector<std::wstring> ExcludedFiles;

	std::set<FileObjectSorted> SortedFiles;

	int TodayAsInteger = 0;

	int FilterCategory = -1;

	ScanData Data;
	SearchData DataSearch;

	ScanPath Path;

	Disk DiskStats;

	bool AllowVirtualFiles = false;

	std::chrono::system_clock::time_point StartTime;

	// ======================================================================

	ScanEngine();

	void ClearData();

	[[nodiscard]] int FindUser(std::wstring);

	bool Execute(bool, const std::wstring, ExecutionParameters);

	void ListRoot() const;

	void AddUserNotSpecified();

	[[nodiscard]] SizeOfFolder GetSizeOfFolder(const std::wstring, const std::wstring);

	[[nodiscard]] std::wstring GetDrive() const;

	[[nodiscard]] int GetFolderIndex(const std::wstring);

	void SortRootBySize();
    void SortByProperty(int);

	void AddToExcludeList(const std::wstring);
	std::wstring GetExcludeItem(int);
	int ExcludeCount();

	void PopulateSortedFiles();

	// ======================================================================

	void SaveSearchResults(Command);

	void Search(Command);
	[[nodiscard]] int Filter(Command);

	// ======================================================================

	std::wstring ToJSON();
};
