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
// 13274


#pragma comment(lib, "crypt32.lib") 


#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <string>

#include "DatabaseHandler.h"
#include "Errors.h"
#include "ErrorConstants.h"
#include "GlobalObjects.h"
#include "Help.h"
#include "ParameterHandler.h"
#include "ReportHandler.h"
#include "ScanDetails.h"
#include "Settings.h"
#include "SystemGlobal.h"
#include "Test.h"
#include "Utility.h"
#include "WindowsUtility.h"
#include "VersionCheck.h"


extern ParameterHandler* GParameterHandler;
extern ScanDetails* GScanDetails;
extern SystemGlobal* GSystemGlobal;
extern Settings* GSettings;


void Database()
{
	if (GSettings->Database.UpdateFolderHistory || GSettings->Database.UpdateScanHistory)
	{
		std::wstring dbParameter;

		if (GSettings->Database.DatabaseMode == __dbSQLite)
		{
			dbParameter = GSystemGlobal->UsersPath + L"FolderHistory\\Database\\Xinorbis.db";
		}
		else if (GSettings->Database.DatabaseMode == __dbODBC)
		{
			dbParameter = GSettings->Database.ODBCConnectionString;
		}
		else
		{
			std::wcout << L"Invalid ODBC mode: " << GSettings->Database.DatabaseMode << std::endl;

			return;
		}

		DatabaseHandler* GDatabaseHandler = new DatabaseHandler(GSettings->Database.DatabaseMode, dbParameter);

		if (GDatabaseHandler->initOK)
		{
			if (GSettings->Database.UpdateFolderHistory)
			{
				if (GSettings->Database.DBStructured)
				{
					std::wstring tableData   = GSettings->Database.DataTableName;
					std::wstring tableSystem = GSettings->Database.SystemTableName;

					GDatabaseHandler->UpdateFolderHistoryStructured(tableSystem, tableData);
				}
				else
				{
					std::wstring tableFile   = Utility::GetMD5(GScanDetails->ScanPath) + GScanDetails->ScanDateInt + WindowsUtility::GetComputerNetName();
					std::wstring tableFolder = Utility::GetMD5(GScanDetails->ScanPath) + GScanDetails->ScanDateInt + WindowsUtility::GetComputerNetName() + L"F";

					GDatabaseHandler->UpdateFolderHistory(tableFolder, tableFile);

					if (GSettings->Database.UpdateScanHistory)
					{
						GDatabaseHandler->UpdateXinorbisScanHistory(GSettings->Custom.SettingsSaveLocation, GScanDetails->ScanPath, GSystemGlobal->UsersPath);
					}
				}
			}
		}

		delete GDatabaseHandler;
	}
}


void ProcessSettingsFromCommandLine()
{
	for (int t = 0; t < GParameterHandler->Count(); t++)
	{
		int i = GParameterHandler->IsProcessingSwitch(t);

		if (i != __parameterInvalid)
		{
			GSettings->ProcessProcessingSetting(i);
		}

		i = GParameterHandler->IsDatabaseSwitch(t);

		if (i != __parameterInvalid)
		{
			GSettings->ProcessDatabaseSetting(i, GParameterHandler->GetParameterValue(i));
		}
	}
}


int wmain(int argc, wchar_t* argv[])
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	// ==========================================================================================
	// ==========================================================================================
	// ==========================================================================================

	if (argc == 1)
	{
		Help::OutputHelpOption(__HelpSimple);

		#ifdef _DEBUG
		system("pause");
		#endif

		return 0;
	}

	// ==========================================================================================
	// ==========================================================================================
	// ==========================================================================================

	GSystemGlobal = new SystemGlobal(argc, argv);

	if (GSystemGlobal->InitOkay == 0)
	{
		if (GParameterHandler->HasScanFolder())
		{
			if (GParameterHandler->FindParameter(L"/allowvirtual"))
			{
				GScanDetails->AllowVirtualFiles = true;
			}

			if (GParameterHandler->FindParameter(L"/test"))
			{
				Test::RunTest();
			}
			else
			{
				if (WindowsUtility::DirectoryExistsWString(GParameterHandler->GetParameter(0)))
				{
					int cgoResult = GlobalObjects::CreateGlobalObjects();

					if (cgoResult == 0)
					{
						ProcessSettingsFromCommandLine();

						if (GScanDetails->ScanPathSet)
						{
							if (GParameterHandler->FindParameter(L"/listroot"))
							{
								GScanDetails->ListRoot();
							}
							else
							{
								if (GScanDetails->Scan(GSettings->Optimisations.ProcessData,
									GParameterHandler->NeedToProcessTopDateLists(),
									GParameterHandler->NeedToProcessTopSizeLists(),
									GParameterHandler->NeedToProcessFileDates()))
								{
									if (ReportHandler::GenerateReports() == 0)
									{
										ReportHandler::ShowDefaultOutput();
									}

									Database();
								}
							}
						}
					}

					if (cgoResult != 0)
					{
						ErrorHandler::OutputErrorConsole(cgoResult);
					}
				}
				else
				{
					ErrorHandler::OutputErrorConsole(__ErrorScanFolderDoesNotExist);
				}
			}
		}
		else
		{
			if (GParameterHandler->FindParameter(L"/test"))
			{
				Test::RunTest();
			}
			else if (GParameterHandler->FindParameter(L"/versioncheck"))
			{
				VersionCheck::IsNewVersion(L"");
			}
			else
			{
				Help::OutputHelpOption(GParameterHandler->HelpSwitch(GParameterHandler->GetParameter(0)));
			}
		}
	}
	else
	{
		ErrorHandler::OutputErrorConsole(GSystemGlobal->InitOkay);
	}

	// ==========================================================================================
	// ==========================================================================================
	// ==========================================================================================
	
	GlobalObjects::FreeGlobalObjects();

	// ==========================================================================================
	// ==========================================================================================
	// ==========================================================================================

	#ifdef _DEBUG
	system("pause");
	#endif

	// ==========================================================================================
	// ==========================================================================================
	// ==========================================================================================
	
    return 0;
}