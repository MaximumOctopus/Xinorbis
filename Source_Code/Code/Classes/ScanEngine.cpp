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
#include <cctype>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

#include "Command.h"
#include "ConstantsData.h"
#include "Convert.h"
#include "DateUtility.h"
#include "ExecutionParameters.h"
#include "ExtensionSearch.h"
#include "FileExtension.h"
#include "FileExtensionHandler.h"
#include "FileDateObject.h"
#include "FileObject.h"
#include "FileObjectSorted.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ConstantsReports.h"
#include "RootFolder.h"
#include "ScanEngine.h"
#include "SearchCriteriaObject.h"
#include "SearchUtility.h"
#include "SettingsHandler.h"
#include "SizeOfFolder.h"
#include "UserData.h"
#include "Utility.h"
#include "WindowsUtility.h"


extern FileExtensionHandler* GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern SettingsHandler* GSettingsHandler;

ScanEngine* GScanEngine;


bool static sortRootByLength(const RootFolder* lhs, const RootFolder* rhs) { return lhs->Name.length() > rhs->Name.length(); }


ScanEngine::ScanEngine()
{
	Init();
	InitLanguage();

	TodayAsInteger     = DateUtility::TodayAsInteger();

	AllowVirtualFiles  = false;

	ClearData();

	Data[0].Source = ScanSource::LiveScan;
	Data[1].Source = ScanSource::SearchResults;

	std::wstring scan_source;

	/*
	if (input.back() == L'\"') // folder path may contain erroneous quote char
	{
		scan_source = input.substr(0, input.length() - 1);
	}
	else
	{
		scan_source = input;
	}

	switch (Data.Source)
	{
	case ScanSource::None:
		break;
	case ScanSource::LiveScan:
		if (WindowsUtility::DirectoryExists(scan_source))
		{
			Path.String = scan_source + L"\\";

			Path.Set = true;
		}
		else
		{
			Path.Set = false;
		}

		break;
	case ScanSource::CSVImport:
		if (WindowsUtility::FileExists(scan_source))
		{
			Path.CSVSource = scan_source;

			Path.Set = true;
		}
		else
		{
			Path.Set = false;
		}

		break;
	}      */
}


void ScanEngine::Init()
{
//
}


void ScanEngine::InitLanguage()
{
	for (int d = 0; d < kAvailableDataSlots; d++)
	{
		for (int t = 0; t < kFileCategoriesCount; t++)
		{
			Data[d].ExtensionSpread[t].Name = GLanguageHandler->TypeDescriptions[t];
		}
	}
}


void ScanEngine::ClearData()
{
	Data[DataSource].Clear();
}


void ScanEngine::AddToExcludeList(const std::wstring exclude)
{
	ExcludedFolders.push_back(exclude);
}


int ScanEngine::ExcludeCount()
{
	return ExcludedFolders.size();
}


std::wstring ScanEngine::GetExcludeItem(int index)
{
	return ExcludedFolders[index];
}


void ScanEngine::AddUserNotSpecified()
{
	UserData *ud = new UserData(GLanguageHandler->Text[kNOT_SPECIFIED]);

	ud->Count = Data[DataSource].FileCount;
	ud->Size  = Data[DataSource].TotalSize;

	Data[DataSource].Users.push_back(ud);
}


void ScanEngine::PopulateDiskStat()
{
	#ifdef DEBUG
	Debug::Output(L"ScanEngine::PopulateDiskStat()");
	#endif

	ULARGE_INTEGER available;
	ULARGE_INTEGER total;
	ULARGE_INTEGER free;

	if (GetDiskFreeSpaceExW(Data[DataSource].Path.String.c_str(),
		                    &available,
							&total,
							&free) != 0)
	{
		Data[DataSource].DiskStats.DriveSpaceTotal = total.QuadPart;
		Data[DataSource].DiskStats.DriveSpaceFree  = free.QuadPart;

		Data[DataSource].DiskStats.DriveSpaceUsed  = total.QuadPart - free.QuadPart;
	}
}


bool ScanEngine::Execute(bool process_data, const std::wstring folder, ExecutionParameters ex)
{
	Data[DataSource].Path.Update(folder);

	FilterCategory = ex.FilterByCategory;

	switch (Data[DataSource].Source)
	{
	case ScanSource::None:
	case ScanSource::LiveScan:
		return Scan(process_data, ex.ProcessTop100Size, ex.ProcessTop100Date, ex.ProcessFileDates);
	case ScanSource::FileCSV:
		return Import(process_data, ex.ProcessTop100Size, ex.ProcessTop100Date, ex.ProcessFileDates);
	}

	return false;
}


bool ScanEngine::Scan(bool process_data, bool process_top_100_size, bool process_top_100_date, bool process_file_dates)
{
	StartTime = std::chrono::system_clock::now();

	if (process_data)
	{
		PopulateDiskStat();

		if (ExcludedFolders.size() != 0)
		{
			Data[DataSource].Path.ExcludeFolders = true;
		}

		if (ExcludedFiles.size() != 0)
		{
			Data[DataSource].Path.ExcludeFiles = true;
		}

		if (Data[DataSource].Path.ExcludeFolders)
		{
			ScanFolderExt(Data[DataSource].Path.String);
		}
		else
		{
			ScanFolder(Data[DataSource].Path.String);
		}

		PostScan();

		if (GSettingsHandler->Optimisations.UseFastAnalysis)
		{
			AnalyseFast();
		}
		else
		{
			Analyse();
		}

		AnalyseRootFolders();

		AnalysePostExtensionSpread();

		if (process_file_dates)
		{
			Data[DataSource].BuildFileDates();
		}

		if (process_top_100_size)
		{
			Data[DataSource].BuildTop100SizeLists();
		}

		if (process_top_100_date)
		{
			Data[DataSource].BuildTop100DateLists();
		}
	}
	else
	{
		AddUserNotSpecified();
	}

	return true;
}


bool ScanEngine::Import(bool process_data, bool process_top_100_size, bool process_top_100_date, bool process_file_dates)
{
	bool success = Data[DataSource].ImportFromCSV(Data[DataSource].Path.FileName);

	if (!success)
	{
		//GLog->Add( L"  Unable to import from \"" << Path.CSVSource << L"\".\n";

		return false;
	}

	if (process_data)
	{
		PostScan();

		if (GSettingsHandler->Optimisations.UseFastAnalysis)
		{
			AnalyseFast();
		}
		else
		{
			Analyse();
		}

		AnalyseRootFolders();

		AnalysePostExtensionSpread();

		if (process_file_dates)
		{
			Data[DataSource].BuildFileDates();
		}

		if (process_top_100_size)
		{
			Data[DataSource].BuildTop100SizeLists();
		}

		if (process_top_100_date)
		{
			Data[DataSource].BuildTop100DateLists();
		}
	}

	return true;
}


bool ScanEngine::Analyse()
{
	#ifdef DEBUG
	Debug::Output(L"ScanEngine::Analyse()");
	#endif

	ScanData &TargetData = Data[DataSource];

	for (FileObject *file : TargetData.Files)
	{
		// =======================================================================================================
		// Folder
		// =======================================================================================================

		if (file->Attributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (file->FilePathIndex == Data[DataSource].RootFolderIndex) // (ScanPath == Folders[Files[t].FilePathIndex])
			{
				FileObject *tfx = new FileObject();

				tfx->Name           = file->Name;
				tfx->FilePathIndex  = file->FilePathIndex;
				tfx->Size	        = file->Size;
				tfx->SizeOnDisk     = file->SizeOnDisk;
				tfx->DateCreated    = file->DateCreated;
				tfx->DateAccessed   = file->DateAccessed;
				tfx->DateModified   = file->DateModified;
				tfx->Attributes     = file->Attributes;
				tfx->Owner          = file->Owner;

				TargetData.RootFiles.push_back(tfx);

				std::wstring s = Data[DataSource].Folders[file->FilePathIndex] + file->Name;

				size_t idx = s.rfind(L"\\");

				if (idx != std::wstring::npos)
				{
					RootFolder *rfd = new RootFolder();

					rfd->Name       = s.substr(idx + 1);
					rfd->Attributes = file->Attributes;

					Data[DataSource].RootFolders.push_back(rfd);
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

			if (file->Attributes & FILE_ATTRIBUTE_HIDDEN)
			{
				TargetData.FileAttributes[kFileType_Hidden].Count++;
				TargetData.FileAttributes[kFileType_Hidden].Size += file->Size;
			}

			if (file->Attributes & FILE_ATTRIBUTE_SYSTEM)
			{
				TargetData.FileAttributes[kFileType_System].Count++;
				TargetData.FileAttributes[kFileType_System].Size += file->Size;
			}

			if (file->Attributes & FILE_ATTRIBUTE_ARCHIVE)
			{
				TargetData.FileAttributes[kFileType_Archive].Count++;
				TargetData.FileAttributes[kFileType_Archive].Size += file->Size;
			}

			if (file->Attributes & FILE_ATTRIBUTE_READONLY)
			{
				TargetData.FileAttributes[kFileType_ReadOnly].Count++;
				TargetData.FileAttributes[kFileType_ReadOnly].Size += file->Size;
			}

			if (file->Attributes & FILE_ATTRIBUTE_COMPRESSED)
			{
				TargetData.FileAttributes[kFileType_Compressed].Count++;
				TargetData.FileAttributes[kFileType_Compressed].Size += file->Size;
			}

			if (file->Attributes & FILE_ATTRIBUTE_ENCRYPTED)
			{
				TargetData.FileAttributes[kFileType_Encrypted].Count++;
				TargetData.FileAttributes[kFileType_Encrypted].Size += file->Size;
			}

			if (file->Attributes & FILE_ATTRIBUTE_RECALL_ON_OPEN)
			{
				TargetData.FileAttributes[kFileType_RecallOnOpen].Count++;
				TargetData.FileAttributes[kFileType_RecallOnOpen].Size += file->Size;
			}

			if (file->Attributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS)
			{
				TargetData.FileAttributes[kFileType_RecallOnDataAccess].Count++;
				TargetData.FileAttributes[kFileType_RecallOnDataAccess].Size += file->Size;
			}

			if (file->Attributes & FILE_ATTRIBUTE_OFFLINE)
			{
				TargetData.FileAttributes[kFileType_Offline].Count++;
				TargetData.FileAttributes[kFileType_Offline].Size += file->Size;
			}

			if (file->DateCreated == TodayAsInteger)
			{
				TargetData.FileAttributes[kFileType_CreatedToday].Count++;
				TargetData.FileAttributes[kFileType_CreatedToday].Size += file->Size;
			}

			if (file->DateAccessed == TodayAsInteger)
			{
				TargetData.FileAttributes[kFileType_AccessedToday].Count++;
				TargetData.FileAttributes[kFileType_AccessedToday].Size += file->Size;
			}

			if (file->DateModified == TodayAsInteger)
			{
				TargetData.FileAttributes[kFileType_ModifiedToday].Count++;
				TargetData.FileAttributes[kFileType_ModifiedToday].Size += file->Size;
			}

			if ((AllowVirtualFiles) ||
				(!(file->Attributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS) &&
				(!(file->Attributes & FILE_ATTRIBUTE_RECALL_ON_OPEN) &&
				(!(file->Attributes & FILE_ATTRIBUTE_OFFLINE)))))
			{

				TargetData.FileCount++;
				TargetData.TotalSize += file->Size;

				// ============================================================================
				// Magnitude
				// ============================================================================

				if (file->Size <= 1024)
				{
					TargetData.Magnitude[0].Count++;
					TargetData.Magnitude[0].Size += file->Size;

					if (file->Size == 0)
					{
						TargetData.FileAttributes[kFileType_Null].Count++;

						TargetData.NullFiles.push_back(TargetData.Folders[file->FilePathIndex] + file->Name);
					}
				}
				else if (file->Size <= 1048576)
				{
					TargetData.Magnitude[1].Count++;
					TargetData.Magnitude[1].Size += file->Size;
				}
				else if (file->Size <= 10485760)
				{
					TargetData.Magnitude[2].Count++;
					TargetData.Magnitude[2].Size += file->Size;
				}
				else if (file->Size <= 52428800)
				{
					TargetData.Magnitude[3].Count++;
					TargetData.Magnitude[3].Size += file->Size;
				}
				else if (file->Size <= 104857600)
				{
					TargetData.Magnitude[4].Count++;
					TargetData.Magnitude[4].Size += file->Size;
				}
				else if (file->Size <= 157286400)
				{
					TargetData.Magnitude[5].Count++;
					TargetData.Magnitude[5].Size += file->Size;
				}
				else if (file->Size <= 209715200)
				{
					TargetData.Magnitude[6].Count++;
					TargetData.Magnitude[6].Size += file->Size;
				}
				else if (file->Size <= 262144000)
				{
					TargetData.Magnitude[7].Count++;
					TargetData.Magnitude[7].Size += file->Size;
				}
				else if (file->Size <= 524288000)
				{
					TargetData.Magnitude[8].Count++;
					TargetData.Magnitude[8].Size += file->Size;
				}
				else if (file->Size <= 1048576000)
				{
					TargetData.Magnitude[9].Count++;
					TargetData.Magnitude[9].Size += file->Size;
				}
				else if (file->Size <= 2097152000)
				{
					TargetData.Magnitude[10].Count++;
					TargetData.Magnitude[10].Size += file->Size;
				}
				else if (file->Size <= 5242880000)
				{
					TargetData.Magnitude[11].Count++;
					TargetData.Magnitude[11].Size += file->Size;
				}
				else
				{
					TargetData.Magnitude[12].Count++;
					TargetData.Magnitude[12].Size += file->Size;
				}

				// =======================================================================
				// process usernames -----------------------------------------------------
				// =======================================================================

				if (GSettingsHandler->Optimisations.GetUserDetails)
				{
					if (file->Category != kFileCategoryDirectory)
					{
						TargetData.Users[file->Owner]->CategoryDataQty[file->Category]++;
						TargetData.Users[file->Owner]->CategoryDataSize[file->Category] += file->Size;
					}

					TargetData.Users[file->Owner]->Count++;
					TargetData.Users[file->Owner]->Size += file->Size;
				}
			}

			// ====================================================================== =
			// process folder path ---------------------------------------------------
			// =======================================================================

			if (Data[DataSource].Path.String == TargetData.Folders[file->FilePathIndex])
			{
				FileObject *tfx = new FileObject();

				tfx->Name           = file->Name;
				tfx->FilePathIndex  = file->FilePathIndex;
				tfx->Size		    = file->Size;
				tfx->SizeOnDisk     = file->SizeOnDisk;
				tfx->DateCreated    = file->DateCreated;
				tfx->DateAccessed   = file->DateAccessed;
				tfx->DateModified   = file->DateModified;
				tfx->Attributes     = file->Attributes;
				tfx->Owner          = file->Owner;

				std::wstring ext = Utility::GetFileExtension(file->Name);

				tfx->Category     = GFileExtensionHandler->GetExtensionCategory(ext);

				TargetData.RootFiles.push_back(tfx);
			}

			// =======================================================================
			// process temporary file types ------------------------------------------
			// =======================================================================
			if (GSettingsHandler->Optimisations.GetTempFiles)
			{
				int z = 0;

				std::wstring s = TargetData.Folders[file->FilePathIndex] + file->Name;

				std::transform(s.begin(), s.end(), s.begin(), ::toupper);

				bool found = false;

				while ((!found) && (z < GFileExtensionHandler->Extensions.size()))
				{
					FileExtension *tfx = GFileExtensionHandler->Extensions[z];

					if (tfx->Category == kCategory_Temp)
					{
						std::wstring tx = tfx->Name;

						std::transform(tx.begin(), tx.end(), tx.begin(), ::toupper);

						int i = tx.find(L"*");

						if (i != std::string::npos)
						{
							if (i == 0)
							{
								// first character is *

								if (tx.rfind(L"*") == tx.length() - 1)   // last character is also * ; eg *.~*
								{
									std::wstring mask = tx.substr(1, tx.length() - 2);

									if (mask.find(s) != std::string::npos)
									{
										found = true;
									}
								}
								else
								{
									std::wstring mask = tx.substr(1, tx.length() - 1);

									if (mask.find(s) != std::string::npos)
									{
										found = true;
									}
								}
							}
							else
							{
								std::wstring mask = tx.substr(0, tx.length() - 1);

								if (mask.find(s) == 0)
								{
									found = true;
								}
							}
						}
						else if (tx.find(s) != std::string::npos)
						{
							found = true;
						};
					};

					z++;
				};

				if (found)
				{
					TargetData.TemporaryFiles.push_back(TargetData.Folders[file->FilePathIndex] + file->Name);

					GFileExtensionHandler->Extensions[kCategory_Temp]->Count++;
					GFileExtensionHandler->Extensions[kCategory_Temp]->Size += file->Size;
				}

				file->Temp = found;
			}
		}
	}

	// ============================================================================

	TargetData.AverageFileSize = (float)TargetData.TotalSize / (float)TargetData.FileCount;
	TargetData.AverageFilesPerFolder = (float)TargetData.FileCount / (float)TargetData.FolderCount;

	// ============================================================================

	if (!GSettingsHandler->Optimisations.GetUserDetails)
	{
		AddUserNotSpecified();
	}

	return true;
}


bool ScanEngine::AnalyseFast()
{
	#ifdef DEBUG
	Debug::Output(L"ScanEngine::AnalyseFast()");
	#endif

	ScanData &TargetData = Data[DataSource];

	for (FileObject *file : TargetData.Files)
	{
		// =======================================================================================================
		// Folder
		// =======================================================================================================
		if (file->Attributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (file->FilePathIndex == TargetData.RootFolderIndex)
			{
				FileObject *tfx = new FileObject();

				tfx->Name          = file->Name;
				tfx->FilePathIndex = file->FilePathIndex;
				tfx->Size          = file->Size;
				tfx->SizeOnDisk    = file->SizeOnDisk;
				tfx->DateCreated   = file->DateCreated;
				tfx->DateAccessed  = file->DateAccessed;
				tfx->DateModified  = file->DateModified;
				tfx->Attributes    = file->Attributes;
				tfx->Owner         = file->Owner;

				TargetData.RootFiles.push_back(tfx);

				std::wstring s = TargetData.Folders[file->FilePathIndex] + file->Name;

				size_t idx = s.rfind(L"\\");

				if (idx != std::wstring::npos)
				{
					RootFolder *rfd = new RootFolder();

					rfd->Name = s.substr(idx + 1);
					rfd->Attributes = file->Attributes;

					TargetData.RootFolders.push_back(rfd);
				}
			}
		}
		// =======================================================================================================
		// Files
		// =======================================================================================================
		else
		{
			if ((AllowVirtualFiles) ||
				(!(file->Attributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS) &&
					(!(file->Attributes & FILE_ATTRIBUTE_RECALL_ON_OPEN) &&
						(!(file->Attributes & FILE_ATTRIBUTE_OFFLINE)))))
			{

				TargetData.FileCount++;
				TargetData.TotalSize += file->Size;
			}

			// =======================================================================
			// process folder path ---------------------------------------------------
			// =======================================================================

			if (Data[DataSource].Path.String == TargetData.Folders[file->FilePathIndex])
			{
				FileObject *tfx = new FileObject();

				tfx->Name          = file->Name;
				tfx->FilePathIndex = file->FilePathIndex;
				tfx->Size          = file->Size;
				tfx->SizeOnDisk    = file->SizeOnDisk;
				tfx->DateCreated   = file->DateCreated;
				tfx->DateAccessed  = file->DateAccessed;
				tfx->DateModified  = file->DateModified;
				tfx->Attributes    = file->Attributes;
				tfx->Owner         = file->Owner;
				tfx->Category      = file->Category;

				std::wstring ext = Utility::GetFileExtension(file->Name);

				TargetData.RootFiles.push_back(tfx);
			}
		}
	}

	// ============================================================================

	TargetData.AverageFileSize = (float)TargetData.TotalSize / (float)TargetData.FileCount;
	TargetData.AverageFilesPerFolder = (float)TargetData.FileCount / (float)TargetData.FolderCount;

	// ============================================================================

	AddUserNotSpecified();

	return true;
}


void ScanEngine::AnalyseRootFolders()
{
	#ifdef DEBUG
	Debug::Output(L"ScanEngine::AnalyseRootFolders()");
	#endif

	ScanData &TargetData = Data[DataSource];

	if (TargetData.RootFolders.size() != 0)
	{
		int SpecialRoot = Data[DataSource].RootIndex();

		TargetData.RootFolders[SpecialRoot]->Name.clear(); // enables correct sorting and folder size attribution

		std::sort(TargetData.RootFolders.begin(), TargetData.RootFolders.end(), sortRootByLength);

		for (FileObject *file : TargetData.Files)
		{
			// =======================================================================
			// =================== Ony process files =================================
			// =======================================================================

			if (!(file->Attributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				// == IS THIS FILE IN A ROOT FOLDER? ===================================
				int selected = -1;
				int index    = 0;

				std::wstring filepath = TargetData.Folders[file->FilePathIndex] + file->Name;

				while ((selected == -1) && (index < TargetData.RootFolders.size()))
				{
					if (filepath.find(Data[DataSource].Path.String + TargetData.RootFolders[index]->Name) != std::wstring::npos)
					{
						TargetData.RootFolders[index]->Count++;
						TargetData.RootFolders[index]->Size += file->Size;

						selected = index;
					}

					index++;
				}

				//must be in root directory
				if (selected == -1)
				{
					TargetData.RootFolders[SpecialRoot]->Count++;
					TargetData.RootFolders[SpecialRoot]->Size += file->Size;
				}
			}
		}

		// sorting will have moved the root folder in the list, so let's find it again!
		SpecialRoot = Data[DataSource].RootIndex();

		TargetData.RootFolders[SpecialRoot]->Name = L"\\ (root)";	// back to normal
	}
}


void ScanEngine::AnalysePostExtensionSpread()
{
	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		Data[DataSource].ExtensionSpread[t].PostProcess(Data[DataSource].FileCount, Data[DataSource].TotalSize);
	}
}


// stage 1, process all files and folders in select directory
// stage 2, another pass, but ScanFolder for each found directory
void ScanEngine::ScanFolder(const std::wstring &folder)
{
	#ifdef DEBUG
	Debug::Output(L"ScanEngine::ScanFolder(" + folder + L")");
	#endif

	std::wstring tmp = folder + L"*";

	int sizeOfFolder = 0;

	Data[DataSource].Folders.push_back(folder);

	CurrentFolderIndex = Data[DataSource].Folders.size() - 1;
	CurrentFolder      = folder;

	WIN32_FIND_DATAW file;

	HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);

	if (search_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			FileObject *file_object = new FileObject();

			file_object->Name          = std::wstring(file.cFileName);
			file_object->FullPath      = folder + file_object->Name;
			file_object->FilePathIndex = CurrentFolderIndex;
			file_object->DateCreated   = Convert::FileTimeToDateInt(&file.ftCreationTime);
			file_object->DateAccessed  = Convert::FileTimeToDateInt(&file.ftLastAccessTime);
			file_object->DateModified  = Convert::FileTimeToDateInt(&file.ftLastWriteTime);
			file_object->TimeCreated   = Convert::FileTimeToTimeInt(&file.ftCreationTime);
			file_object->TimeAccessed  = Convert::FileTimeToTimeInt(&file.ftLastAccessTime);
			file_object->TimeModified  = Convert::FileTimeToTimeInt(&file.ftLastWriteTime);
			file_object->Attributes    = file.dwFileAttributes;

			// =======================================================================================================
			// Folder
			// =======================================================================================================

			if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
					continue;

				file_object->Category = kFileCategoryDirectory;

				Data[DataSource].Files.push_back(file_object);

				Data[DataSource].FolderCount++;
			}
			// =======================================================================================================
			else
			// =======================================================================================================
			// Files
			// =======================================================================================================
			{
				// ============================================================================
				// File Size
				// ============================================================================

				file_object->Size = file.nFileSizeHigh;
				file_object->Size <<= sizeof(file.nFileSizeHigh) * 8;
				file_object->Size |= file.nFileSizeLow;

				// ============================================================================
				// File Extension / Category
				// ============================================================================

				std::wstring ext = Utility::GetFileExtension(file_object->Name);

				ExtensionSearch exi = GFileExtensionHandler->GetExtensionCategoryID(ext);

				if (exi.Category == kFileCategoriesOther)  // "other" extension
				{
					file_object->Category = kFileCategoriesOther;

					if (FilterCategory != -1 && FilterCategory != kFileCategoriesOther)
						continue;

					Data[DataSource].ExtensionSpread[kFileCategoriesOther].Count++;
					Data[DataSource].ExtensionSpread[kFileCategoriesOther].Size += file_object->Size;

					FileExtension *tfx = new FileExtension(ext, kCategory_Other);

					tfx->Count = 1;
					tfx->Size = file_object->Size;

					GFileExtensionHandler->Extensions.push_back(tfx);
				}
				else
				{
					file_object->Category = exi.Category;

					if (FilterCategory != -1 && FilterCategory != file_object->Category)
						continue;

					Data[DataSource].ExtensionSpread[exi.Category].Count++;
					Data[DataSource].ExtensionSpread[exi.Category].Size += file_object->Size;

					GFileExtensionHandler->Extensions[exi.Extension]->Count++;
					GFileExtensionHandler->Extensions[exi.Extension]->Size += file_object->Size;
				}

				// ============================================================================
				// User Name
				// ============================================================================

				if (GSettingsHandler->Optimisations.GetUserDetails)
				{
					std::wstring owner = WindowsUtility::GetFileOwner(CurrentFolder + file_object->Name);

					if (owner.empty())
					{
						owner = GLanguageHandler->Text[kNOT_SPECIFIED];
					}

					int z = FindUser(owner);

					if (z == -1)
					{
						UserData *newUser = new UserData(owner);

						Data[DataSource].Users.push_back(newUser);

						z = Data[DataSource].Users.size() - 1;
					}

					file_object->Owner = z;
				}
				else
				{
					file_object->Owner = 0;
				}

				Data[DataSource].Files.push_back(file_object);

				sizeOfFolder += file_object->Size;
			}

		} while (FindNextFileW(search_handle, &file));

		FindClose(search_handle);
	}

	// =======================================================================================================

	if (sizeOfFolder == 0)
	{
		Data[DataSource].NullFolders.push_back(tmp);
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

				tmp = folder + std::wstring(file.cFileName) + L"\\";

				if (!AllowVirtualFiles)
				{
					if (!(file.dwFileAttributes & FILE_ATTRIBUTE_OFFLINE) && !(file.dwFileAttributes & FILE_ATTRIBUTE_RECALL_ON_OPEN) && !(file.dwFileAttributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS))
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
}


// ext version does extra processing (eg excluded)
// stage 1, process all files and folders in select directory
// stage 2, another pass, but ScanFolder for each found directory
void ScanEngine::ScanFolderExt(const std::wstring& folder)
{
	#ifdef DEBUG
	Debug::Output(L"ScanEngine::ScanFolderExt(" + folder + L")");
	#endif

	std::vector<FileObject*> FolderList;

	std::wstring tmp = folder + L"*";

	int sizeOfFolder = 0;

	Data[DataSource].Folders.push_back(folder);

	CurrentFolderIndex = Data[DataSource].Folders.size() - 1;
	CurrentFolder = folder;

	WIN32_FIND_DATAW file;

	HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);

	if (search_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			FileObject *file_object = new FileObject();

			file_object->Name          = std::wstring(file.cFileName);
			file_object->FullPath      = folder + file_object->Name;
			file_object->FilePathIndex = CurrentFolderIndex;
			file_object->DateCreated   = Convert::FileTimeToDateInt(&file.ftCreationTime);
			file_object->DateAccessed  = Convert::FileTimeToDateInt(&file.ftLastAccessTime);
			file_object->DateModified  = Convert::FileTimeToDateInt(&file.ftLastWriteTime);
			file_object->TimeCreated   = Convert::FileTimeToTimeInt(&file.ftCreationTime);
			file_object->TimeAccessed  = Convert::FileTimeToTimeInt(&file.ftLastAccessTime);
			file_object->TimeModified  = Convert::FileTimeToTimeInt(&file.ftLastWriteTime);
			file_object->Attributes    = file.dwFileAttributes;

			// =======================================================================================================
			// Folder
			// =======================================================================================================

			if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
					continue;

				bool skip = false;

				std::wstring f(file.cFileName);

				std::transform(f.begin(), f.end(), f.begin(), ::tolower);

				for (int i = 0; i < ExcludedFolders.size(); i++)
				{
					if (f.find(ExcludedFolders[i]) != std::wstring::npos)
					{
						skip = true;

						Data[DataSource].Path.ExcludedFolderCount++;

						#ifdef DEBUG
						Debug::Output(L"ScanEngine::ScanFolderExt(" + folder + file.cFileName + L") (EXCLUDED)");
						#endif

						break;
					}
				}

				if (skip) continue;

				file_object->Category = kFileCategoryDirectory;

				Data[DataSource].Files.push_back(file_object);

				Data[DataSource].FolderCount++;

				FolderList.push_back(file_object);
			}
			// =======================================================================================================
			else
				// =======================================================================================================
				// Files
				// =======================================================================================================
			{
				file_object->Size = file.nFileSizeHigh;
				file_object->Size <<= sizeof(file.nFileSizeHigh) * 8;
				file_object->Size |= file.nFileSizeLow;

				// ============================================================================
				// File Extension / Category
				// ============================================================================

				std::wstring ext = Utility::GetFileExtension(file_object->Name);

				ExtensionSearch exi = GFileExtensionHandler->GetExtensionCategoryID(ext);

				if (exi.Category == kFileCategoriesOther)  // uncategorised extension
				{
					file_object->Category = kFileCategoriesOther;

					if (FilterCategory != -1 && FilterCategory != kFileCategoriesOther)
						continue;

					Data[DataSource].ExtensionSpread[kFileCategoriesOther].Count++;
					Data[DataSource].ExtensionSpread[kFileCategoriesOther].Size += file_object->Size;

					FileExtension *tfx = new FileExtension(ext, kCategory_Other);

					tfx->Count = 1;
					tfx->Size = file_object->Size;

					GFileExtensionHandler->Extensions.push_back(tfx);
				}
				else
				{
					file_object->Category = exi.Category;

					if (FilterCategory != -1 && FilterCategory != file_object->Category)
						continue;

					Data[DataSource].ExtensionSpread[exi.Category].Count++;
					Data[DataSource].ExtensionSpread[exi.Category].Size += file_object->Size;

					GFileExtensionHandler->Extensions[exi.Extension]->Count++;
					GFileExtensionHandler->Extensions[exi.Extension]->Size += file_object->Size;
				}

				// ============================================================================
				// User Name
				// ============================================================================

				if (GSettingsHandler->Optimisations.GetUserDetails)
				{
					std::wstring owner = WindowsUtility::GetFileOwner(CurrentFolder + file_object->Name);

					if (owner.empty())
					{
						owner = GLanguageHandler->Text[kNOT_SPECIFIED];
					}

					int z = FindUser(owner);

					if (z == -1)
					{
						UserData *newUser = new UserData(owner);

						Data[DataSource].Users.push_back(newUser);

						z = Data[DataSource].Users.size() - 1;
					}

					file_object->Owner = z;
				}
				else
				{
					file_object->Owner = 0;
				}

				Data[DataSource].Files.push_back(file_object);

				sizeOfFolder += file_object->Size;
			}

		} while (FindNextFileW(search_handle, &file));

		FindClose(search_handle);
	}

	// =======================================================================================================

	if (sizeOfFolder == 0)
	{
		Data[DataSource].NullFolders.push_back(tmp);
	}

	// =======================================================================================================

	for (int t = 0; t < FolderList.size(); t++)
	{
		tmp = folder + std::wstring(FolderList[t]->Name) + L"\\";

		if (!AllowVirtualFiles)
		{
			if (!(FolderList[t]->Attributes & FILE_ATTRIBUTE_OFFLINE) && !(FolderList[t]->Attributes & FILE_ATTRIBUTE_RECALL_ON_OPEN) &&
			    !(FolderList[t]->Attributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS))
			{
				ScanFolderExt(tmp);
			}
		}
		else
		{
			ScanFolderExt(tmp);
		}
	}
}


void ScanEngine::PostScan()
{
	if (Data[DataSource].FileCount != 0)
	{
		Data[DataSource].AverageFileSize = (float)Data[DataSource].TotalSize / (float)Data[DataSource].FileCount;
	}
	else
	{
		Data[DataSource].AverageFileSize = 0;
	}

	if (Data[DataSource].FolderCount != 0)
	{
		Data[DataSource].AverageFilesPerFolder = (float)Data[DataSource].FileCount / (float)Data[DataSource].FolderCount;
	}
	else
	{
		Data[DataSource].AverageFilesPerFolder = 0;
	}
}


int ScanEngine::FindUser(std::wstring name)
{
	for (int t = 0; t < Data[DataSource].Users.size(); t++)
	{
		if (Data[DataSource].Users[t]->Name == name)
		{
			return t;
		}
	}

	return -1;
}

//                                                                XSettings.Navigation.DisplayOptions[side]
SizeOfFolder ScanEngine::SizeOfFolderNav(const std::wstring folder, const std::wstring display_options)
{
	//Assert(aFolderName <> '', 'SizeOfFolder :: blank input error');

	SizeOfFolder sof;

	int index = 0;

	while (index < Data[DataSource].Files.size())
	{
		if (Data[DataSource].Files[index]->Category != kFileCategoryDirectory)
		{
			if (display_options[Data[DataSource].Files[index]->Category] == L'1')
			{
				if ((folder + L"\\").compare(0, Data[DataSource].Folders[Data[DataSource].Files[index]->FilePathIndex].size(), Data[DataSource].Folders[Data[DataSource].Files[index]->FilePathIndex]) == 0)
				{
					sof.Size += Data[DataSource].Files[index]->Size;
					sof.SizeOnDisk += Data[DataSource].Files[index]->SizeOnDisk;

					sof.FileCount++;
				}
			}
		}

		index++;
	}

    return sof;
}
