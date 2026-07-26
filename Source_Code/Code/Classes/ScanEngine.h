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


class ScanEngine
{
private:

	int CurrentFolderIndex = 0;
	std::wstring CurrentFolder = L"";

    void Init();
	void InitLanguage();

	void PopulateDiskStat();

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

	int FindUser(std::wstring);

public:

    int DataSource = 0;

	std::vector<std::wstring> ExcludedFolders;
	std::vector<std::wstring> ExcludedFiles;

	int TodayAsInteger = 0;

	int FilterCategory = -1;

	ScanData Data[2];

	Disk DiskStats;

	bool AllowVirtualFiles = false;

	std::chrono::system_clock::time_point StartTime;

	// ======================================================================

	ScanEngine();

	void ClearData();

	bool Execute(bool, const std::wstring, ExecutionParameters);

	void ListRoot() const;

	void AddUserNotSpecified();

	void AddToExcludeList(const std::wstring);
	std::wstring GetExcludeItem(int);
	int ExcludeCount();

	void PopulateSortedFiles();

	// ======================================================================

	void SaveSearchResults(Command);

	void Search(Command);
	[[nodiscard]] int Filter(Command);
};
