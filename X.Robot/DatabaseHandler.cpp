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
// February 16th 2019
//


#include <algorithm>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

#include "Constants.h"
#include "Convert.h"
#include "DatabaseHandler.h"
#include "DatabaseODBC.h"
#include "DatabaseSQlite.h"
#include "FolderHistoryHandler.h"
#include "LanguageHandler.h"
#include "Registry.h"
#include "ScanHistoryObject.h"
#include "Utility.h"
#include "WindowsUtility.h"


extern LanguageHandler* GLanguageHandler;


// dbparameter : file name for sqlite mode
//             : connectionString from ODBC mode 
DatabaseHandler::DatabaseHandler(int mode, std::wstring dbParameter)
{
	dbMode = mode;

	initOK = false;

	switch (dbMode)
	{
	case __dbNone:
		std::wcout << L"No database mode selected (use /odbc or /sqlite)." << std::endl;

		break;
	case __dbSQLite:
	{
		initOK = InitSQlite(dbParameter);

		break;
	}
	case __dbODBC:
	{
		initOK = InitODBC(dbParameter);

		break;
	}

	default:
		std::wcout << std::endl << L"Unknown database mode \"" << mode << "\"." << std::endl;
	}
}


DatabaseHandler::~DatabaseHandler()
{
	if (dbSQlite != nullptr)
	{
		delete dbSQlite;
	}

	if (dbODBC != nullptr)
	{
		delete dbODBC;
	}
}


bool DatabaseHandler::InitSQlite(std::wstring SQliteFileName)
{
	try
	{
		if (WindowsUtility::FileExists(SQliteFileName))
		{
			// file not found, will create, should show message?!
		}

		std::wcout << L"Initialising SQlite..." << std::endl;

		dbSQlite = new DatabaseSQlite(SQliteFileName);

		return dbSQlite->dbAvailable;
	}
	catch (...)
	{
		std::wcout << L"Error initialising SQLite :(" << std::endl << std::endl;

		dbSQlite->dbAvailable = false;
	}

	return dbSQlite->dbAvailable;
}


bool DatabaseHandler::InitODBC(std::wstring connectionString)
{
	try
	{
		dbODBC = new DatabaseODBC(connectionString);
	}
	catch (...)
	{
		std::wcout << L"Error initialising SQLite :(" << std::endl << std::endl;

		dbODBC->dbAvailable = false;
	}

	return dbODBC->dbAvailable;
}


bool DatabaseHandler::UpdateFolderHistory(std::wstring tableFolder, std::wstring tableFile)
{
	if (dbMode == __dbSQLite)
	{
		if (dbSQlite->CreateNewFolderTable(tableFolder))
		{

			if (dbSQlite->CreateNewFileTable(tableFile))
			{
				dbSQlite->PopulateFolderTable(tableFolder);

				dbSQlite->PopulateFileTable(tableFile);

				std::wcout << std::endl << GLanguageHandler->XText[rsUpdatingFolderHistory] << L"..." << std::endl;

				UpdateFolderHistoryFile();
			}
			else
			{
				std::wcout << L"SQlite File Table Creation Failed \"" + tableFile + L"\"" << std::endl;

				return false;
			}
		}
		else
		{
			std::wcout << L"SQlite Folder Table Creation Failed \"" + tableFolder + L"\"" << std::endl;

			return false;
		}

		return true;
	}
	else if (dbMode == __dbODBC)
	{
		if (dbODBC->CreateNewFolderTable(tableFolder))
		{

			if (dbODBC->CreateNewFileTable(tableFile))
			{
				dbODBC->PopulateFolderTable(tableFolder);

				dbODBC->PopulateFileTable(tableFile);

				std::wcout << std::endl << GLanguageHandler->XText[rsUpdatingFolderHistory] << L"..." << std::endl;

				UpdateFolderHistoryFile();
			}
			else
			{
				std::wcout << L"ODBC File Table Creation Failed \"" + tableFile + L"\"" << std::endl;

				return false;
			}
		}
		else
		{
			std::wcout << L"ODBC Folder Table Creation Failed \"" + tableFolder + L"\"" << std::endl;

			return false;
		}

		return true;
	}

	return false;
}


bool DatabaseHandler::UpdateFolderHistoryStructured(std::wstring tableSystem, std::wstring tableData)
{
	if (dbMode == __dbSQLite)
	{
		if (dbSQlite->CreateNewSystemTable(tableSystem))
		{

			if (dbSQlite->CreateNewDataTable(tableData))
			{
				std::wcout << L"Populating structured folder table..." << std::endl;
				dbSQlite->PopulateSystemTable(tableSystem, tableData);

				std::wcout << L"Populating structured file table..." << std::endl;
				dbSQlite->PopulateDataTable(tableData);

				std::wcout << GLanguageHandler->XText[rsUpdatingFolderHistory] << std::endl;
				UpdateFolderHistoryFile();
			}
			else
			{
				std::wcout << L"SQlite structured File Table Creation Failed \"" + tableData + L"\"" << std::endl;

				return false;
			}
		}
		else
		{
			std::wcout << L"SQlite structured Folder Table Creation Failed \"" + tableSystem + L"\"" << std::endl;

			return false;
		}

		return true;
	}
	else if (dbMode == __dbODBC)
	{
		if (dbODBC->CreateNewSystemTable(tableSystem))
		{

			if (dbODBC->CreateNewDataTable(tableData))
			{
				std::wcout << L"Populating structured folder table..." << std::endl;
				dbODBC->PopulateSystemTable(tableSystem, tableData);

				std::wcout << L"Populating structured file table..." << std::endl;
				dbODBC->PopulateDataTable(tableData);

				std::wcout << GLanguageHandler->XText[rsUpdatingFolderHistory] << std::endl;
				UpdateFolderHistoryFile();
			}
			else
			{
				std::wcout << L"ODBC structured File Table Creation Failed \"" + tableData + L"\"" << std::endl;

				return false;
			}
		}
		else
		{
			std::wcout << L"ODBC structured Folder Table Creation Failed \"" + tableSystem + L"\"" << std::endl;

			return false;
		}

		return true;
	}

	return false;
}


bool DatabaseHandler::UpdateFolderHistoryFile(void)
{
	FolderHistoryHandler* GFolderHistoryHandler = new FolderHistoryHandler();

	GFolderHistoryHandler->UpdateFolderHistoryFile();

	delete GFolderHistoryHandler;

	return false;
}


bool DatabaseHandler::UpdateXinorbisScanHistory(int saveLocation, std::wstring folder, std::wstring usersPath)
{
	if (saveLocation == __SaveLocationRegistry)
	{
		return UpdateXinorbisScanHistoryRegistry(folder, usersPath);
	}
	else
	{
		return UpdateXinorbisScanHistoryIni(folder, usersPath);
	}
}


// updates the xinorbis file containing a list of the previous 100 scan paths
bool DatabaseHandler::UpdateXinorbisScanHistoryIni(std::wstring folder, std::wstring usersPath)
{
	if (WindowsUtility::FileExists(usersPath + L"scanhistory.dat"))
	{
		std::vector<ScanHistoryObject> ScanHistory;

		try
		{
			std::wifstream file(usersPath + L"scanhistory.dat");

			file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

			if (file)
			{
				std::wstring s;

				while (std::getline(file, s))
				{
					ScanHistoryObject ho;

					ho.Path = s;

					std::getline(file, s);

					ho.DateI = Convert::StrToIntDef(s, 19000101);

					std::getline(file, s);

					ho.TimeI = s;

					std::getline(file, s);

					ho.ExcludeFiles = s;

					std::getline(file, s);

					ho.ExcludeFolders = s;

					ScanHistory.push_back(ho);
				}

				file.close();
			}
		}
		catch(...)
		{
			std::wcout << L"Error reading \"" << usersPath + L"scanhistory.dat" << L"\"" << std::endl;

			return false;
		}

		std::wcout << L"Loaded " << ScanHistory.size() << L" scan history items." << std::endl;

		// =====================================================================================
		// Add This Scan
		// =====================================================================================
		
		ScanHistoryObject ho;

		ho.Path           = folder;
		ho.DateI          = Utility::TodayAsInteger();
		ho.TimeI          = Utility::GetTime(__GETTIMEFORMAT_HHMM);
		ho.ExcludeFiles   = L"";
		ho.ExcludeFolders = L"";

		ScanHistory.insert(ScanHistory.begin(), ho);

		// =====================================================================================
		// Save ScanHistory
		// =====================================================================================
		
		try
		{
			if (ScanHistory.size() != 0)
			{
				std::wofstream ofile(usersPath + L"scanhistory.dat");

				ofile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

				if (ofile)
				{
					int t = 0;

					// write a maximum of 100 items back to the file
					while ((t < ScanHistory.size()) && (t < 100))
					{
						ScanHistoryObject ho = ScanHistory[t];

						ofile << ho.Path << std::endl;
						ofile << std::to_wstring(ho.DateI) << std::endl;
						ofile << ho.TimeI << std::endl;
						ofile << ho.ExcludeFiles << std::endl;
						ofile << ho.ExcludeFolders << std::endl;

						t++;
					}

					ofile.close();
				}
				else
				{

				}
			}
		}
		catch(...)
		{
			
		} 

		return true;
	}
	
	return false;
}


bool DatabaseHandler::UpdateXinorbisScanHistoryRegistry(std::wstring folder, std::wstring usersPath)
{
	std::vector<ScanHistoryObject> ScanHistory;

	LONG dwRet;
	HKEY hKey;

	dwRet = RegOpenKeyEx(HKEY_CURRENT_USER,
						 L"\\software\\maximumoctopus\\Xinorbis8\\SinglePaths",
						 NULL,
						 KEY_QUERY_VALUE,
						 &hKey);

	if (dwRet == ERROR_SUCCESS)
	{
		int count = 0;

		while (Registry::ReadRegistryString(hKey, L"PathX" + std::to_wstring(count), L"") != L"")
		{
			ScanHistoryObject ho;

			ho.Path             = Registry::ReadRegistryString(hKey, L"PathX" + std::to_wstring(count), L"");
			ho.DateI            = Registry::ReadRegistryInteger(hKey, L"PathY" + std::to_wstring(count), 19750417);
			ho.TimeI            = Registry::ReadRegistryString(hKey, L"PathZ" + std::to_wstring(count), L"");
			ho.ExcludeFiles     = Registry::ReadRegistryString(hKey, L"PathE1" + std::to_wstring(count), L"");
			ho.ExcludeFolders   = Registry::ReadRegistryString(hKey, L"PathE2" + std::to_wstring(count), L"");

			ScanHistory.push_back(ho);

			count++;
		}

		RegCloseKey(hKey);
	}
	else
	{
		// key not found, but that's okay, we'll create it at the next reg access
	}
	
	   
	// =====================================================================================
	// Add This Scan
	// =====================================================================================

	ScanHistoryObject ho;

	ho.Path		      = folder;
	ho.DateI          = Utility::TodayAsInteger();
	ho.TimeI          = Utility::GetTime(__GETTIMEFORMAT_HHMM);
	ho.ExcludeFiles   = L"";
	ho.ExcludeFolders = L"";

	ScanHistory.insert(ScanHistory.begin(), ho);

	// =====================================================================================
	// Save ScanHistory
	// =====================================================================================

	if (ScanHistory.size() != 0)
	{
		dwRet = RegCreateKeyEx(HKEY_CURRENT_USER, 
			                   L"\\software\\maximumoctopus\\Xinorbis8\\SinglePaths", 
			                   0,
			                   NULL,
			                   REG_OPTION_NON_VOLATILE, 
			                   KEY_WRITE, 
			                   NULL,
			                   &hKey, 
							   NULL);

		if (dwRet == ERROR_SUCCESS)
		{
			int count = 0;

			while ((count < ScanHistory.size()) && (count < 100))
			{ 
				Registry::WriteRegistryString(hKey, L"PathX"  + std::to_wstring(count), ho.Path);
				Registry::WriteRegistryString(hKey, L"PathY"  + std::to_wstring(count), std::to_wstring(ho.DateI));
				Registry::WriteRegistryString(hKey, L"PathZ"  + std::to_wstring(count), ho.TimeI);
				Registry::WriteRegistryString(hKey, L"PathE1" + std::to_wstring(count), ho.ExcludeFiles);
				Registry::WriteRegistryString(hKey, L"PathE2" + std::to_wstring(count), ho.ExcludeFolders);

				count++;
			}
		}
	}

	return false;
}