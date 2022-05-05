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
// June 4th 2020
//


#pragma once


#include <chrono>
#include <string>
#include <vector>
#include "FileObject.h"
#include "FileDateObject.h"
#include "RootFolder.h"
#include "ScanDetails.h"
#include "UserData.h"


struct Disk
{
	unsigned __int64 DriveSpaceTotal;
	unsigned __int64 DriveSpaceFree;
	unsigned __int64 DriveSpaceUsed;

	std::wstring diskType;

	int sectorsPerCluster;
	int bytesPerSector;
	int freeClusters;
	int totalClusters;

	std::wstring volumeName;
	std::wstring serialNumber;
	std::wstring fileSystem;
};


class ScanDetails
{
private:
	int CurrentFolderIndex;
	std::wstring CurrentFolder;

	int TodayAsInteger;

	void PopulateDiskStat();

	bool Analyse();
	void AnalyseRootFolders();

	void BuildFileDates();

	void BuildTop100SizeLists();
	void BuildTop100DateLists();
public:
	std::wstring ScanPath;
	std::wstring ScanDateStr;
	std::wstring ScanDateInt;
	
	bool ScanPathSet;

	bool AllowVirtualFiles;

	std::chrono::system_clock::time_point StartTime;

	int FileCount;
	int FolderCount;
	unsigned __int64 TotalSize;
	unsigned __int64 TotalSizeOD;
	unsigned __int64 AverageFileSize;
	float AverageFilesPerFolder;
	
	Disk DiskStats;

	std::vector<FileObject> Files;
	std::vector<std::wstring> Folders;

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

	unsigned __int64 Magnitude[__MagnitudesCount][2];
	unsigned __int64 FileAttributes[__AttributesCount][2];
	unsigned __int64 ExtensionSpread[__FileCategoriesCount][2];
	
	// ======================================================================

	ScanDetails(std::wstring folder);

	void ClearData();

	int ScanDetails::FindUser(std::wstring name);

	bool Scan(bool processData, bool processTop100Size, bool processTop100Date, bool processFileDates);

	void ScanFolder(const std::wstring &directory);

	void ListRoot();

	void AddUserNotSpecified();
};