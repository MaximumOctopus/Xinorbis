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
// January 30th 2019
//


#include "ErrorConstants.h"
#include "Ini.h"
#include "ParameterHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"
#include <iostream>
#include <string>


extern ParameterHandler* GParameterHandler;
SystemGlobal* GSystemGlobal;


// =============================================================


SystemGlobal::SystemGlobal(int argc, wchar_t *argv[])
{
	InitialiseXinorbis();

	GParameterHandler = new ParameterHandler(argc, argv);
}


void SystemGlobal::InitialiseXinorbis()
{
	AppPath   = WindowsUtility::GetExePath();
	UsersPath = GetUsersPath(AppPath);

	if (!InstallationCheck())
	{
		InitOkay = __ErrorInstallationCheckFailed;
	}
}


bool SystemGlobal::InstallationCheck()
{
	return true;
}


bool SystemGlobal::CheckFolderStructure()
{
	int failCount = 0;

	std::wstring cName = WindowsUtility::GetComputerNetName();

	if (!WindowsUtility::DirectoryExistsWString(AppPath + L"logs\\"))											 { failCount += WindowsUtility::CreateWFolder(AppPath + L"logs"); }

	if (!WindowsUtility::DirectoryExistsWString(UsersPath))												         { failCount += WindowsUtility::CreateWFolder(UsersPath); }

	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"X.Robot\\Saves\\Custom Reports"))                  { failCount += WindowsUtility::CreateWFolder(UsersPath + L"X.Robot\\Saves\\Custom Reports"); }
	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"X.Robot\\Reports\\" + cName))                      { failCount += WindowsUtility::CreateWFolder(UsersPath + L"X.Robot\\Reports\\" + cName); }
		
	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\CSV\\"))         { failCount += WindowsUtility::CreateWFolder(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\CSV\\"); }

	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\HTML\\data"))    { failCount += WindowsUtility::CreateWFolder(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\HTML\\data"); }

	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\Xinorbis\\"))    { failCount += WindowsUtility::CreateWFolder(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\Xinorbis\\"); }

 	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\Summary\\"))     { failCount += WindowsUtility::CreateWFolder(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\Summary\\"); }

 	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\Text\\"))        { failCount += WindowsUtility::CreateWFolder(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\Text\\"); }

	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\Tree\\"))        { failCount += WindowsUtility::CreateWFolder(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\Tree\\"); }

	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\XML\\"))         { failCount += WindowsUtility::CreateWFolder(UsersPath + L"X.Robot\\Reports\\" + cName + L"\\XML\\"); }

	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"FolderHistory\\Database\\"))                       { failCount += WindowsUtility::CreateWFolder(UsersPath + L"FolderHistory\\Database\\"); }
	
	if (!WindowsUtility::DirectoryExistsWString(UsersPath + L"FolderHistory\\" + cName))                         { failCount += WindowsUtility::CreateWFolder(UsersPath + L"FolderHistory\\" + cName); }

	
	if (!WindowsUtility::DirectoryExistsWString(AppPath + L"data\\"))
	{
		std::wcout << L"Xinorbis is not properly installed" << std::endl;
		std::wcout << L"Missing folder: " + AppPath + L"Data" << std::endl << std::endl;
		
		failCount++;
	}

	if (failCount != 0)
	{
		// ====================================================================================
		// DO NO USE TRANSLATED TEXT FOR THESE CONSTANTS!
		// ====================================================================================

		std::wcout << L"Error(s) while updating \"" + UsersPath + L"\"." << std::endl;
		std::wcout << L"This folder, and all subfolders, must be read/write." << std::endl << std::endl;
		
		return false;
	}

	return true;
}


void SystemGlobal::UpdateDriveDetails(std::wstring folder)
{

}


std::wstring SystemGlobal::GetUsersPath(std::wstring appPath)
{
	if (WindowsUtility::FileExists(appPath + L"custom.ini"))
	{
		Ini* config = new Ini(appPath + L"custom.ini");

		std::wstring lDataPath = config->ReadString(L"X.Robot", L"DataPath", L"");

		if (lDataPath == L"")
		{
			lDataPath = config->ReadString(L"Main", L"DataPath", L"");
		}

		delete config;

		// =========================================================================
		// == Portable specific modes                                             ==
		// =========================================================================

		if (lDataPath != L"")
		{
			if (lDataPath[lDataPath.length() - 1] != L'\\') { lDataPath += L'\\'; }

			// lets check for special variables
			if (lDataPath.find(L"$xdrive") != std::wstring::npos)
			{
				lDataPath = Utility::ReplaceString(lDataPath, L"$xdrive", appPath[0] + L":");
			}

			if (lDataPath.find(L"$xfolder") != std::wstring::npos)
			{
				lDataPath = Utility::ReplaceString(lDataPath, L"$xfolder", appPath.substr(0, appPath.length() - 1));
			}

			// handle enviromental variable
			if (lDataPath.find(L"<") != std::wstring::npos)
			{
				size_t a = lDataPath.find(L"<");
				size_t b = lDataPath.find(L">");

				if (b != std::wstring::npos)
				{
					std::wstring envName = lDataPath.substr(a + 1, (b - a) - 1);

					std::wstring envValue = WindowsUtility::GetEnvVariable(envName);

					if (envValue != L"")
					{
						lDataPath = Utility::ReplaceString(lDataPath, L"<" + envName + L">", envValue);
					}
					else
					{
						std::wcout << L"Configuration error!";
						std::wcout << L"Environment variable \"" + envName + L"\" not found.";
						std::wcout << L"Using: " + AppPath + L"system\\";
						std::wcout << L"";

						lDataPath = AppPath + L"system\\";
					}
				} 
			}

			return lDataPath;
		}
		else
		{
			return AppPath + L"system\\";
		}

		// =========================================================================
		// ==                                                                     ==
		// =========================================================================
	}
	else
	{
		return WindowsUtility::GetDataFolder();
	}
}