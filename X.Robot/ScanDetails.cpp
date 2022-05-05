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


#include <algorithm>
#include <iostream>

#include "Convert.h"
#include "FileExtensionHandler.h"
#include "FileObject.h"
#include "FileDateObject.h"
#include "LanguageHandler.h"
#include "ScanDetails.h"
#include "Settings.h"
#include "Utility.h"
#include "WindowsUtility.h"


extern FileExtensionHandler* GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern Settings* GSettings;


ScanDetails* GScanDetails;


bool sortBySize(const FileObject &lhs, const FileObject &rhs) { return lhs.Size < rhs.Size; }
bool sortByDate(const FileObject &lhs, const FileObject &rhs) { return lhs.FileDateC < rhs.FileDateC; }


ScanDetails::ScanDetails(std::wstring folder)
{
	StartTime          = std::chrono::system_clock::now();

	TodayAsInteger     = Utility::TodayAsInteger();

	ScanDateStr        = Utility::DateTime(0);
	ScanDateInt        = Utility::DateTime(1);

	AllowVirtualFiles  = false;

	ClearData();

	if (WindowsUtility::DirectoryExistsWString(folder))
	{
		ScanPath    = folder + L"\\";

		ScanPathSet = true;
	}
	else
	{
		ScanPathSet = false;
	}
}


void ScanDetails::ClearData()
{
	FileCount   = 0;
	FolderCount = 0;
	TotalSize   = 0;
	TotalSizeOD = 0;

	DiskStats.DriveSpaceTotal = 0;
	DiskStats.DriveSpaceFree = 0;
	DiskStats.DriveSpaceUsed = 0;

	for (int t = 0; t < __MagnitudesCount; t++)
	{
		Magnitude[t][__mCount] = 0;
		Magnitude[t][__mSize]  = 0;
	}

	for (int t = 0; t < __AttributesCount; t++)
	{
		FileAttributes[t][__faCount] = 0;
		FileAttributes[t][__faSize]  = 0;
	}

	for (int t = 0; t < __FileCategoriesCount; t++)
	{
		ExtensionSpread[t][__esCount] = 0;
		ExtensionSpread[t][__esSize]  = 0;
	}

	RootFolder rfd;

	rfd.Name       = L"root";
	rfd.Attributes = 0;
	rfd.Data[0]	   = 0;
	rfd.Data[1]    = 0;

	RootFolders.push_back(rfd);
}


void ScanDetails::AddUserNotSpecified()
{
	UserData ud;
	
	ud.Name    = GLanguageHandler->XText[rsNOT_SPECIFIED];
	ud.Data[0] = GScanDetails->FileCount;
	ud.Data[1] = GScanDetails->TotalSize;

	Users.push_back(ud);
}


int ScanDetails::FindUser(std::wstring name)
{
	for (int t = 0; t < Users.size(); t++)
	{
		if (Users[t].Name == name)
		{
			return t;
		}
	}

	return -1;
}


void ScanDetails::PopulateDiskStat()
{
	ULARGE_INTEGER available;
	ULARGE_INTEGER total;
	ULARGE_INTEGER free;

	if (GetDiskFreeSpaceExW(GScanDetails->ScanPath.c_str(),
		                    &available,
							&total,
							&free) != 0)
	{
		DiskStats.DriveSpaceTotal = total.QuadPart;
		DiskStats.DriveSpaceFree  = free.QuadPart;

		DiskStats.DriveSpaceUsed  = total.QuadPart - free.QuadPart;
	}
}


bool ScanDetails::Scan(bool processData, bool processTop100Size, bool processTop100Date, bool processFileDates)
{
	if (processData)
	{
		PopulateDiskStat();

		ScanFolder(ScanPath);

		Analyse();

		AnalyseRootFolders();

		if (processFileDates)
		{
			BuildFileDates();
		}

		if (processTop100Size)
		{
			BuildTop100SizeLists();
		}

		if (processTop100Date)
		{
			BuildTop100DateLists();
		}
	}
	else
	{
		AddUserNotSpecified();
	}

	return true;
}


bool ScanDetails::Analyse()
{
	for (int t = 0; t < Files.size(); t++)
	{
		// =======================================================================================================
		// Folder
		// =======================================================================================================
		if (Files[t].Attributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			Files[t].Category = __FileCategoryDirectory;

			if (Files[t].FilePathIndex == 0) // (ScanPath == Folders[Files[t].FilePathIndex])
			{
				FileObject tfx;

				tfx.FileName       = Files[t].FileName;
				tfx.FilePathIndex  = Files[t].FilePathIndex;
				tfx.Size	       = Files[t].Size;
				tfx.SizeOnDisk     = Files[t].SizeOnDisk;
				tfx.FileDateC      = Files[t].FileDateC;
				tfx.FileDateA      = Files[t].FileDateA;
				tfx.FileDateM      = Files[t].FileDateM;
				tfx.Attributes     = Files[t].Attributes;
				tfx.Owner          = Files[t].Owner;

				//std::wstring s = Utility::GetFileExtension(Files[t].FileName);
					
				RootFiles.push_back(tfx);

				std::wstring s = Folders[Files[t].FilePathIndex] + Files[t].FileName;

				size_t idx = s.find_last_of(L"\\");

				if (idx != std::wstring::npos)
				{
					RootFolder rfd;
			
					rfd.Name       = s.substr(idx + 1);
					rfd.Attributes = Files[t].Attributes;
					rfd.Data[0]    = 0;
					rfd.Data[1]    = 0;
					
					RootFolders.push_back(rfd);
				}
			}
		}
		// =======================================================================================================
		// Files
		// =======================================================================================================
		else
		{
			// ============================================================================
			// File Attributes 
			// ============================================================================

			if (Files[t].Attributes & FILE_ATTRIBUTE_HIDDEN)
			{
				FileAttributes[__FileType_Hidden][0]++;
				FileAttributes[__FileType_Hidden][1] += Files[t].Size;
			}

			if (Files[t].Attributes & FILE_ATTRIBUTE_SYSTEM)
			{
				FileAttributes[__FileType_System][0]++;
				FileAttributes[__FileType_System][1] += Files[t].Size;
			}

			if (Files[t].Attributes & FILE_ATTRIBUTE_ARCHIVE)
			{
				FileAttributes[__FileType_Archive][0]++;
				FileAttributes[__FileType_Archive][1] += Files[t].Size;
			}

			if (Files[t].Attributes & FILE_ATTRIBUTE_READONLY)
			{
				FileAttributes[__FileType_ReadOnly][0]++;
				FileAttributes[__FileType_ReadOnly][1] += Files[t].Size;
			}

			if (Files[t].Attributes & FILE_ATTRIBUTE_COMPRESSED)
			{
				FileAttributes[__FileType_Compressed][0]++;
				FileAttributes[__FileType_Compressed][1] += Files[t].Size;
			}

			if (Files[t].Attributes & FILE_ATTRIBUTE_ENCRYPTED)
			{
				FileAttributes[__FileType_Encrypted][0]++;
				FileAttributes[__FileType_Encrypted][1] += Files[t].Size;
			}

			if (Files[t].Attributes & FILE_ATTRIBUTE_RECALL_ON_OPEN)
			{
				FileAttributes[__FileType_RecallOnOpen][0]++;
				FileAttributes[__FileType_RecallOnOpen][1] += Files[t].Size;
			}

			if (Files[t].Attributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS)
			{
				FileAttributes[__FileType_RecallOnDataAccess][0]++;
				FileAttributes[__FileType_RecallOnDataAccess][1] += Files[t].Size;
			}

			if (Files[t].Attributes & FILE_ATTRIBUTE_OFFLINE)
			{
				FileAttributes[__FileType_Offline][0]++;
				FileAttributes[__FileType_Offline][1] += Files[t].Size;
			}

			if (Files[t].FileDateC == TodayAsInteger)
			{
				FileAttributes[__FileType_CreatedToday][0]++;
				FileAttributes[__FileType_CreatedToday][1] += Files[t].Size;
			}

			if (Files[t].FileDateA == TodayAsInteger)
			{
				FileAttributes[__FileType_AccessedToday][0]++;
				FileAttributes[__FileType_AccessedToday][1] += Files[t].Size;
			}

			if (Files[t].FileDateM == TodayAsInteger)
			{
				FileAttributes[__FileType_ModifiedToday][0]++;
				FileAttributes[__FileType_ModifiedToday][1] += Files[t].Size;
			}

			if ((AllowVirtualFiles) ||
				(!(Files[t].Attributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS) &&
					(!(Files[t].Attributes & FILE_ATTRIBUTE_RECALL_ON_OPEN) &&
						(!(Files[t].Attributes & FILE_ATTRIBUTE_OFFLINE)))))
			{

				FileCount++;
				TotalSize += Files[t].Size;

				// ============================================================================
				// File Extension
				// ============================================================================

				std::wstring ext = Utility::GetFileExtension(Files[t].FileName);

				ExtensionSearch exi = GFileExtensionHandler->GetExtensionCategoryID(ext);

				if (!exi.Found)  // "other" extension
				{
					ExtensionSpread[__FileCategoriesOther][0]++;
					ExtensionSpread[__FileCategoriesOther][1] += Files[t].Size;

					FileExtension tfx;

					tfx.Name = ext;
					tfx.Category = __Category_Other;
					tfx.Quantity = 1;
					tfx.Size = Files[t].Size;

					GFileExtensionHandler->Extensions.push_back(tfx);

					Files[t].Category = __FileCategoriesOther;
				}
				else
				{
					for (int i = 1; i < __FileCategoriesCount; i++)
					{
						if (exi.Category[i] != -1)
						{
							ExtensionSpread[i][0]++;
							ExtensionSpread[i][1] += Files[t].Size;

							GFileExtensionHandler->Extensions[exi.Category[i]].Quantity++;
							GFileExtensionHandler->Extensions[exi.Category[i]].Size += Files[t].Size;

							Files[t].Category = i;
						}
					}
				}

				// ============================================================================
				// Magnitude
				// ============================================================================

				if ((Files[t].Size >= 0) && (Files[t].Size <= 1024))
				{
					Magnitude[0][__mCount]++;
					Magnitude[0][__mSize] += Files[t].Size;

					if (Files[t].Size == 0)
					{
						FileAttributes[__FileType_Null][__faCount]++;

						NullFiles.push_back(Folders[Files[t].FilePathIndex] + Files[t].FileName);
					}
				}
				else if ((Files[t].Size > 1024) && (Files[t].Size <= 1048576))
				{
					Magnitude[1][__mCount]++;
					Magnitude[1][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 1048576) && (Files[t].Size <= 10485760))
				{
					Magnitude[2][__mCount]++;
					Magnitude[2][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 10485760) && (Files[t].Size <= 52428800))
				{
					Magnitude[3][__mCount]++;
					Magnitude[3][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 52428800) && (Files[t].Size <= 104857600))
				{
					Magnitude[4][__mCount]++;
					Magnitude[4][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 104857600) && (Files[t].Size <= 157286400))
				{
					Magnitude[5][__mCount]++;
					Magnitude[5][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 157286400) && (Files[t].Size <= 209715200))
				{
					Magnitude[6][__mCount]++;
					Magnitude[6][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 209715200) && (Files[t].Size <= 262144000))
				{
					Magnitude[7][__mCount]++;
					Magnitude[7][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 262144000) && (Files[t].Size <= 524288000))
				{
					Magnitude[8][__mCount]++;
					Magnitude[8][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 524288000) && (Files[t].Size <= 1048576000))
				{
					Magnitude[9][__mCount]++;
					Magnitude[9][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 1048576000) && (Files[t].Size <= 2097152000))
				{
					Magnitude[10][__mCount]++;
					Magnitude[10][__mSize] += Files[t].Size;
				}
				else if ((Files[t].Size > 2097152000) && (Files[t].Size <= 5242880000))
				{
					Magnitude[11][__mCount]++;
					Magnitude[11][__mSize] += Files[t].Size;
				}
				else
				{
					Magnitude[12][__mCount]++;
					Magnitude[12][__mSize] += Files[t].Size;
				}

				// =======================================================================
				// process usernames -----------------------------------------------------
				// =======================================================================

				if (GSettings->Optimisations.GetUserDetails)
				{
					if (Files[t].Category != __FileCategoryDirectory)
					{
						Users[Files[t].Owner].CategoryDataQty[Files[t].Category]++;
						Users[Files[t].Owner].CategoryDataSize[Files[t].Category] += Files[t].Size;
					}

					Users[Files[t].Owner].Data[__UserCount]++;
					Users[Files[t].Owner].Data[__UserSize] += Files[t].Size;
				}
			}

			// ====================================================================== =
			// process folder path ---------------------------------------------------
			// =======================================================================

			//if tfo.FilePathIndex > GScanDetails.Folders.Count - 1 then {
					//          inc(iserrorcount);

					//tfo.FilePathIndex : = 0;
			//}
			if (ScanPath == Folders[Files[t].FilePathIndex])
			{
				FileObject tfx;
			
				tfx.FileName       = Files[t].FileName;
				tfx.FilePathIndex  = Files[t].FilePathIndex;
				tfx.Size		   = Files[t].Size;
				tfx.SizeOnDisk     = Files[t].SizeOnDisk;
				tfx.FileDateC      = Files[t].FileDateC;
				tfx.FileDateA      = Files[t].FileDateA;
				tfx.FileDateM      = Files[t].FileDateM;
				tfx.Attributes     = Files[t].Attributes;
				tfx.Owner          = Files[t].Owner;

				std::wstring ext = Utility::GetFileExtension(Files[t].FileName);

				tfx.Category     = GFileExtensionHandler->GetExtensionCategoryID(ext).RawCategory;

				RootFiles.push_back(tfx); 
			}

			// =======================================================================
			// process temporary file types ------------------------------------------
			// =======================================================================
			if (GSettings->Optimisations.GetTempFiles)
			{
				/*
				z: = 0;

				s: = UpperCase(GScanDetails.Folders[tfo.FilePathIndex] + tfo.FileName);

			found: = False;

				while (not(found)) and (z < FileExtensionsObject.CategoryExtensions.Count) do {
					tfx : = FileExtensionsObject.CategoryExtensions[z];

				if tfx.Category = Category_Temp then {
					//found:=MatchesMask(s, tfx.Name);

					tx : = UpperCase(tfx.Name);

				if Pos('*', tx) <> 0 then {
					i : = Pos('*', tx);

				if i = 1 then {                   // first character is *
					if tx[length(tx)] = '*' then {  // last character is also * ; eg *.~*
						if Pos(Copy(tx, 2, length(tx) - 2), s) <> 0 then
							found : = True;
				}
						else {
					if Pos(Copy(tx, 2, length(tx) - 1), s) <> 0 then
						found : = True;
				};
				}
					else {
					if Pos(Copy(tx, 1, length(tx) - 1), s) = 1 then
						found : = True;
				};
				}
					else if Pos(tx, s) <> 0 then {
					found : = True;
				};
				};

				inc(z);
				};

				if found then {
					if Assigned(FFoundTemp) then
						FFoundTemp(GScanDetails.Folders[tfo.FilePathIndex] + tfo.FileName,
							TConvert.ConvertToUsefulUnit(tfo.FileSize),
							IntToStr(tfo.FileSize));

				inc(GScanDetails.ExtensionSpread[Category_Temp, 1]);
				inc(GScanDetails.ExtensionSpread[Category_Temp, 2], tfo.FileSize);

				tfo.Temp : = True;
				}
					else
					tfo.Temp : = False;
					*/
			}
		}
	}

	if (!GSettings->Optimisations.GetUserDetails)
	{
		AddUserNotSpecified();
	}

	return true;
}


void ScanDetails::AnalyseRootFolders()
{
	if (RootFolders.size() != 0)
	{

		for (int t = 0; t < GScanDetails->Files.size(); t++)
		{
			// =======================================================================
			// =================== Ony process files =================================
			// =======================================================================

			if (!(Files[t].Attributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				// == IS THIS FILE IN A ROOT FOLDER? ===================================
				int lucy = -1;
				int i    = 1;

				std::wstring filepath = Folders[Files[t].FilePathIndex] + Files[t].FileName;

				while ((lucy == -1) && (i < RootFolders.size()))
				{
					//---------------------------------------------------------------------------------------------+'\'
					if (filepath.find(ScanPath + RootFolders[i].Name) != std::wstring::npos)
					{
						RootFolders[i].Data[__RootCount]++;
						RootFolders[i].Data[__RootSize] += Files[t].Size;

						lucy = i;
					}

					i++;
				}

				//must be in root directory
				if (lucy == -1)
				{
					RootFolders[0].Data[__RootCount]++;
					RootFolders[0].Data[__RootSize] += Files[t].Size;
				}
			}
		}
	}
}


// stage 1, process all files and folders in select directory
// stage 2, another pass, but ScanFolder for each found directory
void ScanDetails::ScanFolder(const std::wstring &directory)
{
	std::wstring tmp = directory + L"*";

	int sizeOfFolder = 0;

	Folders.push_back(directory);

	CurrentFolderIndex = Folders.size() - 1;
	CurrentFolder      = directory;

	WIN32_FIND_DATAW file;
	
	HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);
	
	if (search_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			FileObject lFileObject;

			lFileObject.FileName      = std::wstring(file.cFileName);
			lFileObject.FilePathIndex = CurrentFolderIndex;
			lFileObject.FileDateC = Convert::FileTimeToDateInt(&file.ftCreationTime);
			lFileObject.FileDateA = Convert::FileTimeToDateInt(&file.ftLastAccessTime);
			lFileObject.FileDateM = Convert::FileTimeToDateInt(&file.ftLastWriteTime);
			lFileObject.FileTimeC = Convert::FileTimeToTimeInt(&file.ftCreationTime);
			lFileObject.FileTimeA = Convert::FileTimeToTimeInt(&file.ftLastAccessTime);
			lFileObject.FileTimeM = Convert::FileTimeToTimeInt(&file.ftLastWriteTime);
			lFileObject.Attributes = file.dwFileAttributes;

			// =======================================================================================================
			// Folder
			// =======================================================================================================
			if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
					continue;

				Files.push_back(lFileObject);

				FolderCount++;
			}
			// =======================================================================================================
			else
			// =======================================================================================================
			// Files
			// =======================================================================================================
			{
				lFileObject.Size = (file.nFileSizeHigh * (MAXDWORD + 1)) + file.nFileSizeLow;

				if (GSettings->Optimisations.GetUserDetails)
				{
					std::wstring owner = WindowsUtility::GetFileOwner(CurrentFolder + lFileObject.FileName);

					if (owner == L"")
					{
						owner = GLanguageHandler->XText[rsNOT_SPECIFIED];
					}

					int z = FindUser(owner);

					if (z == -1)
					{
						UserData newUser;

						newUser.Name = owner;

						GScanDetails->Users.push_back(newUser);

						z = GScanDetails->Users.size() - 1;
					}
					
					lFileObject.Owner = z;
				}
				else
				{
					lFileObject.Owner = 0;
				}

				Files.push_back(lFileObject);

				sizeOfFolder += lFileObject.Size;
			}
			
		} while (FindNextFileW(search_handle, &file));

		FindClose(search_handle);
	}

	// =======================================================================================================

	if (sizeOfFolder == 0)
	{
		NullFolders.push_back(tmp);
	}

	// =======================================================================================================

	search_handle = FindFirstFileW(tmp.c_str(), &file);

	if (search_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
					continue;

				tmp = directory + std::wstring(file.cFileName) + L"\\";

				if (!AllowVirtualFiles)
				{
					if (!(file.dwFileAttributes & FILE_ATTRIBUTE_OFFLINE) & !(file.dwFileAttributes & FILE_ATTRIBUTE_RECALL_ON_OPEN) & !(file.dwFileAttributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS))
					{
						ScanFolder(tmp);
					}
				}
				else
				{
					ScanFolder(tmp);
				}
			}

		} while (FindNextFileW(search_handle, &file));

		FindClose(search_handle);
	}


	if (FileCount != 0)
	{
		AverageFileSize = (float)TotalSize / (float)FileCount;
	}
	else
	{
		AverageFileSize = 0;
	}
	
	if (FolderCount != 0)
	{
		AverageFilesPerFolder = (float)FileCount / (float)FolderCount;
	}
	else
	{
		AverageFilesPerFolder = 0;
	}
}


void ScanDetails::BuildFileDates()
{
	int currentYear = Utility::CurrentYearI();

	for (int y = 1980; y <= currentYear; y++)
	{
		FileDateObject fdo(y);

		FileDates.push_back(fdo);
	}

	if (Files.size() != 0)
	{
		for (int t = 0; t < Files.size(); t++)
		{
			if (!(Files[t].Attributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				int year = Convert::StrToIntDef(std::to_wstring(Files[t].FileDateC).substr(0, 4), -1);

				if ((year >= 1980) && (year <= currentYear))
				{
					FileDates[year - 1980].Count++;
					FileDates[year - 1980].Size += Files[t].Size;
				}
			}
		}
	}
}


void ScanDetails::BuildTop100SizeLists()
{
	Top100Large.clear();
	Top100Small.clear();

	std::sort(Files.begin(), Files.end(), sortBySize);

	int i     = 0;

	while ((i < 100) && (i < Files.size()))
	{
		Top100Small.push_back(Files[i]);
		Top100Large.push_back(Files[Files.size() - i - 1]);

		i++;
	}
}


void ScanDetails::BuildTop100DateLists()
{
	Top100Newest.clear();
	Top100Oldest.clear();

	std::sort(Files.begin(), Files.end(), sortByDate);

	int i = 0;

	while ((i < 100) && (i < Files.size()))
	{
		Top100Oldest.push_back(Files[i]);
		Top100Newest.push_back(Files[Files.size() - i - 1]);

		i++;
	}
}


void ScanDetails::ListRoot()
{
	std::wcout << std::endl << "  Listing root files/folders:" << std::endl << std::endl;

	std::wstring tmp = ScanPath + L"*";

	WIN32_FIND_DATAW file;

	HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);

	if (search_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			// =======================================================================================================
			// Folder
			// =======================================================================================================
			if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
					continue;

				std::wcout << L"    " << ScanPath << file.cFileName << L"\\" << std::endl;
			}
			else
			// =======================================================================================================
			// Files
			// =======================================================================================================
			{
				std::wcout << L"    " << ScanPath << file.cFileName << std::endl;
			}

		} while (FindNextFileW(search_handle, &file));

		FindClose(search_handle);
	}

	std::wcout << std::endl;
}