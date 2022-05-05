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


#include "Constants.h"
#include "Ini.h"
#include "ParameterHandler.h"
#include "Registry.h"
#include "Settings.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

#include <iostream>
#include <string>
#include <tchar.h>


Settings* GSettings;

extern SystemGlobal* GSystemGlobal;


Settings::Settings()
{
	Custom.SettingsSaveLocation  = __SaveLocationRegistry;

	SetDefaults();

    System.Debug = false;

	System.Loaded = false;

	if (LoadCustomSettings())
	{
		LoadLanguage();

		System.Loaded = LoadBasic();
	}
}


void Settings::SetDefaults()
{
	Database.UpdateScanHistory = false;

	Database.DatabaseMode = __dbSQLite;

	Database.DBStructured = false;
	Database.SystemTable = false;
	Database.DataTable = false;

	Database.DataTable = L"data";
	Database.SystemTable = L"system";

	Database.UpdateFolderHistory = false;

	Database.ODBCConnectionString = L"";
	
	Optimisations.ProcessData    = true;
	Optimisations.GetTempFiles   = false;
	Optimisations.GetUserDetails = false;
	
	Optimisations.ProgressUpdate = false;
}


void Settings::ProcessProcessingSetting(int pps)
{
	switch (pps)
	{
	case __parameterNoUserDetails:
		Optimisations.GetUserDetails = false;
		break;
	case __parameterNoProcess:
		Optimisations.ProcessData = false;
		break;
	case __parameterNoTempFiles:
		Optimisations.GetTempFiles = false;
		break;
	}
}


void Settings::ProcessDatabaseSetting(int pds, std::wstring value)
{
	switch (pds)
	{
	case 0x06:
		Database.UpdateScanHistory = true;
		break;
	case 0x07:
		Database.DatabaseMode = __dbODBC;
		break;
	case 0x08:
		Database.DatabaseMode = __dbSQLite;
		break;
	case 0x09:
		Database.DBStructured = true;
		break;
	case 0x0A:
		Database.SystemTable = true;

		if (value != L"")
		{
			Database.SystemTableName = value;
		}
		break;
	case 0x0B:
		Database.DataTable = true;

		if (value != L"")
		{
			Database.DataTableName = value;
		}
		break;
	case 0x0C:
		Database.UpdateFolderHistory = true;
		break;
	}
}


bool Settings::OpenSettings(bool readOnly)
{
    if (Custom.SettingsSaveLocation == __SaveLocationConfigIni)
    {
		__iniFile = new Ini(GSystemGlobal->AppPath + L"custom.ini");


		std::wcout << GSystemGlobal->AppPath + L"custom.ini" << std::endl;

		if (__iniFile->Loaded)
		{
			return true;
		}

		return false;
    }
    else
    {
        if (readOnly)
        {
            LONG dwRet;

            dwRet = RegOpenKeyEx(HKEY_CURRENT_USER,
                                 L"\\software\\maximumoctopus\\Xinorbis8",
                                 NULL,
                                 KEY_QUERY_VALUE,
                                 &hKey);

            if (dwRet != ERROR_SUCCESS)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
			return true; 
        }
    }
}


bool Settings::CloseSettings()
{
    if (Custom.SettingsSaveLocation == __SaveLocationConfigIni)
    {
		delete __iniFile;

		return true;
    }
    else
    {
        RegCloseKey(hKey);

        hKey = NULL;

		return true;
    }
}


bool Settings::LoadCustomSettings()
{
	if (WindowsUtility::FileExists(GSystemGlobal->AppPath + L"custom.ini"))
	{
		Ini* IniFile = new Ini(GSystemGlobal->AppPath + L"custom.ini");

		if (IniFile->Loaded)
		{
			std::wstring pcm = IniFile->ReadString(L"Main", L"PortableMode", L"0"); // to do change to readint

			if (pcm == L"1")
			{
				Custom.SettingsSaveLocation = __SaveLocationConfigIni;

				std::wcout << L"Portable mode active (from custom.ini)." << std::endl;
			}

			pcm = IniFile->ReadString(L"Main", L"useodbc", L"0"); // to do change to readint

			if (pcm == L"1")
			{
				Database.DatabaseMode = __dbODBC;

				Database.ODBCConnectionString = IniFile->ReadString(L"Main", L"connectionstring", L"");

				if (Database.ODBCConnectionString == L"")
				{
					std::wcout << L"ODBC mode active, but connection string invalid (empty). Exiting." << std::endl;

					return false;
				}
			}
		}

		delete IniFile;
	}

	return true;
}


bool Settings::LoadBasic()
{
    // ===========================================================================
    // ===========================================================================
    // == Initialise                                                            ==
    // ===========================================================================
    // ===========================================================================

	if (OpenSettings(true))
	{
		// ===========================================================================
		// ===========================================================================
		// == Load Settings                                                         ==
		// ===========================================================================
		// ===========================================================================

		Report.HTMLColours[0]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour1" , 0x990000, -1);  // link normal
		Report.HTMLColours[1]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour2" , 0x000000, -1);  // link hover
		Report.HTMLColours[2]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour3",  0xFFFFFF, -1);  // background colour
		Report.HTMLColours[3]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour4",  0x990000, -1);  // text colour
		Report.HTMLColours[4]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour5",  0x0000FF, -1);  // bargraph colour
		Report.HTMLColours[5]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour6",  0xFF9900, -1);  // table background
		Report.HTMLColours[6]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour7",  0xFFFFFF, -1);  // table colour1
		Report.HTMLColours[7]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour8",  0x000000, -1);  // table colour2
		Report.HTMLColours[8]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour9",  0xFFFFFF, -1);  // graph background
		Report.HTMLColours[9]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour10", 0xDDDDDD, -1);  // table body background
		Report.HTMLColours[10] = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour11", 0xCCCCCC, -1);  // table body background II

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		Optimisations.ProgressUpdate = ReadIntegerFromSettingsInputCheck(L"Prefs", L"ProgressUpdate", 1, 0, 5);

		Optimisations.GetUserDetails = true;// ReadBoolFromSettings(L"Prefs", L"GetUserDetails", true);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		General.DateFormat = ReadIntegerFromSettingsInputCheck(L"Prefs", L"DateFormat", 0, 0, 4);

		System.HandleMultipleExt = ReadIntegerFromSettingsInputCheck(L"Prefs", L"HandleMultipleExt", 0, 0, 2);

		//Report.HTMLOutput            = ReadStringFromSettings('Prefs', 'Prefs_HTMLOutput', '');
		//Report.HTMLCompareOutput     = ReadStringFromSettings('Prefs', 'Prefs_HTMLCompareOutput', '');
		//Report.XMLOutput             = ReadStringFromSettings('Prefs', 'Prefs_XMLOutput', 'notepad');

		//Report.TextOutput            = ReadStringFromSettings('Prefs', 'Prefs_TextOutput', 'notepad');


		CloseSettings();
	}
	else
	{
		// ===========================================================================

		Report.HTMLColours[0]  = 0x990000;  // link normal
		Report.HTMLColours[1]  = 0x000000;  // link hover
		Report.HTMLColours[2]  = 0xFFFFFF;  // background colour
		Report.HTMLColours[3]  = 0x990000;  // text colour
		Report.HTMLColours[4]  = 0x0000FF;  // bargraph colour
		Report.HTMLColours[5]  = 0xFF9900;  // table background
		Report.HTMLColours[6]  = 0xFFFFFF;  // table colour1
		Report.HTMLColours[7]  = 0x000000;  // table colour2
		Report.HTMLColours[8]  = 0xFFFFFF;  // graph background
		Report.HTMLColours[9]  = 0xDDDDDD;  // table body background
		Report.HTMLColours[10] = 0xCCCCCC;  // table body background II

		FileCategoryColors[0]  = 0x00FFFFFF; // for folders

		for (int t = 1; t < __FileCategoriesCount; t++)
		{
			FileCategoryColors[t] = ReadIntegerFromSettings(L"Prefs", L"Chart Colour" + std::to_wstring(t), __DefaultDisplayColours[t], -1);
		}

		// ===========================================================================

		Optimisations.ProgressUpdate = 1;

		Optimisations.GetUserDetails = true;

		// ===========================================================================

		General.DateFormat       = 0;
		System.HandleMultipleExt = 0;
	}

    return true;
}


bool Settings::LoadLanguage()
{
    // ===========================================================================
    // ===========================================================================
    // == Initialise                                                            ==
    // ===========================================================================
    // ===========================================================================

    OpenSettings(true);

    // ===========================================================================
    // ===========================================================================
    // == Load Settings                                                         ==
    // ===========================================================================
    // ===========================================================================

    System.CurrentLanguage = ReadIntegerFromSettings(L"Prefs", L"Language", __LanguageUNDEFINED, 0);

    // ===========================================================================
    // == Close                                                                 ==
    // ===========================================================================

    CloseSettings();

	if (System.CurrentLanguage == __LanguageUNDEFINED)
	{
		System.CurrentLanguage = __LanguageUK;
	}

    return true;
}


std::wstring Settings::ReadStringFromSettings(std::wstring section, std::wstring name, std::wstring defaultValue)
{
    if (Custom.SettingsSaveLocation == __SaveLocationConfigIni)
    {
		std::wstring rs = __iniFile->ReadString(section, name, defaultValue);

		return rs;
    }
    else
    {
        return Registry::ReadRegistryString(hKey, name, defaultValue);
    }
}


int Settings::ReadIntegerFromSettings(std::wstring section, std::wstring name, int defaultValue, int ifZero)
{
    int lResult;

    if (Custom.SettingsSaveLocation == __SaveLocationConfigIni)
    {
		int ri = __iniFile->ReadInteger(section, name, defaultValue);

		if (ri == 0)
		{
			return ifZero;
		}

		return ri;
    }
    else
    {
        lResult = Registry::ReadRegistryInteger(hKey, name, defaultValue);
    }

    if (lResult == 0)
    {
        if (ifZero != -1)
        {
            return  ifZero;
        }
        else
        {
            return lResult;
        }
    }
    else
    {
        return lResult;
    }
}


int Settings::ReadIntegerFromSettingsInputCheck(std::wstring section, std::wstring name, int defaultValue, int min, int max)
{
	if (Custom.SettingsSaveLocation == __SaveLocationConfigIni)
	{
		int ri = __iniFile->ReadInteger(section, name, defaultValue);

		if ((ri < min) || (ri > max))
		{
			return  defaultValue;
		}
		else
		{
			return ri;
		}
	}
	else
	{
		int lResult = Registry::ReadRegistryInteger(hKey, name, defaultValue);
	
		if ((lResult < min) || (lResult > max))
		{
			return  defaultValue;
		}
		else
		{
			return lResult;
		}
	}
}


bool Settings::ReadBoolFromSettings(std::wstring section, std::wstring name, bool defaultValue)
{
    if (Custom.SettingsSaveLocation == __SaveLocationConfigIni)
    {
		return true;
    }
    else
    {
        return Registry::ReadRegistryBool(hKey, name, defaultValue);
    }
}