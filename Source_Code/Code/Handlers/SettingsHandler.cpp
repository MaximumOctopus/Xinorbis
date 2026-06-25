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

#include <iostream>
#include <string>
#include <tchar.h>

#include "ConstantsData.h"
#include "ConstantsParameters.h"
#include "Ini.h"
#include "Registry.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

SettingsHandler *GSettingsHandler;

extern SystemGlobal* GSystemGlobal;


SettingsHandler::SettingsHandler()
{
	Custom.SettingsSaveLocation  = SettingsSource::Registry;

	SetDefaults();

	//System.Debug = false;

	//System.Loaded = false;

	//if (LoadCustomSettings())
   //	{
   //		LoadLanguage();

  //		System.Loaded = LoadBasic();
  //	}
}


void SettingsHandler::SetDefaults()
{
	Optimisations.ProcessData    = true;
	Optimisations.GetTempFiles   = false;
	Optimisations.GetUserDetails = false;

	Optimisations.ProgressUpdate = false;
}


void SettingsHandler::ProcessProcessingSetting(ParameterOption option)
{
	switch (option)
	{
	case ParameterOption::NoUsers:
		Optimisations.GetUserDetails = false;
		break;
	case ParameterOption::NoProcess:
		Optimisations.ProcessData = false;
		break;
	case ParameterOption::NoTemp:
		Optimisations.GetTempFiles = false;
		break;
	}
}


bool SettingsHandler::OpenSettings(bool read_only)
{
    if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
    {
		__iniFile = new Ini(GSystemGlobal->ExePath + L"custom.ini");

		if (__iniFile->Loaded)
		{
			return true;
		}

		return false;
    }
    else
    {
        if (read_only)
        {
            LONG dwRet;

            dwRet = RegOpenKeyEx(HKEY_CURRENT_USER,
                                 L"software\\maximumoctopus\\FolderScanUltra",
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


bool SettingsHandler::CloseSettings()
{
    if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
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


bool SettingsHandler::LoadCustomSettings()
{
	if (WindowsUtility::FileExists(GSystemGlobal->ExePath + L"custom.ini"))
	{
		std::unique_ptr<Ini> IniFile = std::make_unique<Ini>(GSystemGlobal->ExePath + L"custom.ini");

		if (IniFile->Loaded)
		{
			int pcm = IniFile->ReadInteger(L"Main", L"PortableMode", 0);

			if (pcm == 1)
			{
				Custom.SettingsSaveLocation = SettingsSource::ConfigIni;

				std::wcout << L"Portable mode active (from custom.ini).\n";
			}
		}
	}

	return true;
}


bool SettingsHandler::LoadBasic()
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

		Reports.HTMLColours[0]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour1" , 0x990000, -1);  // link normal
		Reports.HTMLColours[1]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour2" , 0x000000, -1);  // link hover
		Reports.HTMLColours[2]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour3",  0xFFFFFF, -1);  // background colour
		Reports.HTMLColours[3]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour4",  0x990000, -1);  // text colour
		Reports.HTMLColours[4]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour5",  0x0000FF, -1);  // bargraph colour
		Reports.HTMLColours[5]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour6",  0xFF9900, -1);  // table background
		Reports.HTMLColours[6]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour7",  0xFFFFFF, -1);  // table colour1
		Reports.HTMLColours[7]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour8",  0x000000, -1);  // table colour2
		Reports.HTMLColours[8]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour9",  0xFFFFFF, -1);  // graph background
		Reports.HTMLColours[9]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour10", 0xDDDDDD, -1);  // table body background
		Reports.HTMLColours[10] = ReadIntegerFromSettings(L"Prefs", L"Prefs_HTMLColour11", 0xCCCCCC, -1);  // table body background II

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		Optimisations.ProgressUpdate = ReadIntegerFromSettingsInputCheck(L"Prefs", L"ProgressUpdate", 1, 0, 5);

		Optimisations.GetUserDetails = ReadBoolFromSettings(L"Prefs", L"GetUserDetails", false);

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

		Reports.HTMLColours[0]  = 0x990000;  // link normal
		Reports.HTMLColours[1]  = 0x000000;  // link hover
		Reports.HTMLColours[2]  = 0xFFFFFF;  // background colour
		Reports.HTMLColours[3]  = 0x990000;  // text colour
		Reports.HTMLColours[4]  = 0x0000FF;  // bargraph colour
		Reports.HTMLColours[5]  = 0xFF9900;  // table background
		Reports.HTMLColours[6]  = 0xFFFFFF;  // table colour1
		Reports.HTMLColours[7]  = 0x000000;  // table colour2
		Reports.HTMLColours[8]  = 0xFFFFFF;  // graph background
		Reports.HTMLColours[9]  = 0xDDDDDD;  // table body background
		Reports.HTMLColours[10] = 0xCCCCCC;  // table body background II

		FileCategoryColors[0]  = 0x00FFFFFF; // for folders

		for (int t = 1; t < __FileCategoriesCount; t++)
		{
			FileCategoryColors[t] = ReadIntegerFromSettings(L"Prefs", L"Chart Colour" + std::to_wstring(t), __DefaultDisplayColours[t], -1);
		}

		// ===========================================================================

		Optimisations.ProgressUpdate = 1;

		Optimisations.GetUserDetails = false;

		// ===========================================================================

		General.DateFormat       = 0;
		System.HandleMultipleExt = 0;
	}

    return true;
}


bool SettingsHandler::LoadLanguage()
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

    int language = ReadIntegerFromSettings(L"Prefs", L"Language", -1, 0);

	switch (language)
	{
	case 1:
		System.CurrentLanguage = LanguageType::kUK;
		break;
	case 2:
		System.CurrentLanguage = LanguageType::kNL;
		break;
	case 3:
		System.CurrentLanguage = LanguageType::kFR;
		break;
	case 4:
		System.CurrentLanguage = LanguageType::kDE;
		break;
	case 5:
		System.CurrentLanguage = LanguageType::kIT;
		break;
	case 6:
		System.CurrentLanguage = LanguageType::kPT;
		break;
	case 7:
		System.CurrentLanguage = LanguageType::kES;
		break;
	case 8:
		System.CurrentLanguage = LanguageType::kSW;
		break;
	case 9:
		System.CurrentLanguage = LanguageType::kCZ;
		break;
	case 10:
		System.CurrentLanguage = LanguageType::kHU;
		break;
	case 11:
		System.CurrentLanguage = LanguageType::kUS;
		break;
	case 12:
		System.CurrentLanguage = LanguageType::kRU;
		break;
	case 13:
		System.CurrentLanguage = LanguageType::kCAT;
		break;
	default:
		System.CurrentLanguage = LanguageType::kUndefined;
	}

	// ===========================================================================
    // == Close                                                                 ==
    // ===========================================================================

    CloseSettings();

	if (System.CurrentLanguage == LanguageType::kUndefined)
	{
		System.CurrentLanguage = LanguageType::kUK;
	}

    return true;
}


std::wstring SettingsHandler::ReadStringFromSettings(const std::wstring section, const std::wstring name, const std::wstring default_value)
{
    if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
    {
		std::wstring rs = __iniFile->ReadString(section, name, default_value);

		return rs;
    }
    else
    {
        return Registry::ReadRegistryString(hKey, name, default_value);
    }
}


int SettingsHandler::ReadIntegerFromSettings(const std::wstring section, const std::wstring name, int default_value, int ifZero)
{
    int setting;

    if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
    {
		int ri = __iniFile->ReadInteger(section, name, default_value);

		if (ri == 0)
		{
			return ifZero;
		}

		return ri;
    }
    else
    {
		setting = Registry::ReadRegistryInteger(hKey, name, default_value);
    }

    if (setting == 0)
    {
        if (ifZero != -1)
        {
            return  ifZero;
        }
        else
        {
            return setting;
        }
    }
    else
    {
        return setting;
    }
}


int SettingsHandler::ReadIntegerFromSettingsInputCheck(const std::wstring section, const std::wstring name, int default_value, int min, int max)
{
	if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
	{
		int ri = __iniFile->ReadInteger(section, name, default_value);

		if ((ri < min) || (ri > max))
		{
			return  default_value;
		}
		else
		{
			return ri;
		}
	}
	else
	{
		int setting = Registry::ReadRegistryInteger(hKey, name, default_value);

		if ((setting < min) || (setting > max))
		{
			return  default_value;
		}
		else
		{
			return setting;
		}
	}
}


bool SettingsHandler::ReadBoolFromSettings(const std::wstring section, const std::wstring name, bool default_value)
{
    if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
    {
		return true;
    }
    else
    {
        return Registry::ReadRegistryBool(hKey, name, default_value);
    }
}
