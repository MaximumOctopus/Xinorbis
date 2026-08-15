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


// used for "refresh"ing
struct LastScan
{
	bool ProcessData = false;
	std::wstring Folder = L"";

	ExecutionParameters Ex;
};


class ScanEngine
{
private:

	constexpr static int kAvailableDataSlots = 2;

	int CurrentFolderIndex = 0;
	std::wstring CurrentFolder = L"";

    void Init();
	void InitLanguage();

	void PopulateDiskStat();

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

	LastScan Last;

    int DataSource = 0;

	std::vector<std::wstring> FolderStructure;  		// used by FrameStructure and associated thread/process
	std::wstring CurrentNavigationSideLocation = L"";   //  ""                          ""

	std::vector<std::wstring> ExcludedFolders;
	std::vector<std::wstring> ExcludedFiles;

	int TodayAsInteger = 0;

	int FilterCategory = -1;

	ScanData Data[kAvailableDataSlots];

	bool AllowVirtualFiles = false;

	std::chrono::system_clock::time_point StartTime;

    std::wstring ProcessTime = L"";

	// ======================================================================

	ScanEngine();

	void ClearData();

	bool Execute(bool, const std::wstring, ExecutionParameters);

	void Refresh();

	void ListRoot() const;

	void AddUserNotSpecified();

	void AddToExcludeList(const std::wstring);
	std::wstring GetExcludeItem(int);
	int ExcludeCount();

	void PopulateSortedFiles();

    SizeOfFolder SizeOfFolderNav(const std::wstring, const std::wstring);

	// ======================================================================

	bool ImportFromCSVCustom(const std::wstring, int, CSVDataFormat, bool, bool, bool);

	// ======================================================================

	void SaveSearchResults(Command);

	void Search(Command);
	[[nodiscard]] int Filter(Command);
};
