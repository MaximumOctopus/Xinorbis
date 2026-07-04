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
#include "ConstantsGui.h"
#include "ConstantsParameters.h"
#include "ConstantsReports.h"
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


bool SettingsHandler::SaveDefaults()
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
		// == Language                                                              ==
		// ===========================================================================
		// ===========================================================================

		WriteInteger(L"Prefs", L"Language", LanguageToInt(LanguageType::kUndefined));

		// ===========================================================================
		// ===========================================================================
		// == Load Settings                                                         ==
		// ===========================================================================
		// ===========================================================================

		WriteInteger(L"Prefs", L"Main_Top",      5);
		WriteInteger(L"Prefs", L"Main_Left",     5);
		WriteInteger(L"Prefs", L"Main_Width", 1016);
		WriteInteger(L"Prefs", L"Main_Height", 700);

		WriteBool(L"Prefs", L"Tutorial", true);

		// ===========================================================================
		// == Chart Options                                                         ==
		// ===========================================================================

		//  WriteIntegerToSettings(L"Prefs", L"Prefs_ChartStyle" + std::to_wstring(t),  DefaultChartStyles[t]);

		WriteInteger(L"Prefs", L"Prefs_ChartX8_a", 0x00333333);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_b", 0x00333333);
		WriteBool(L"Prefs", L"Prefs_ChartX8_c", false);

		WriteInteger(L"Prefs", L"Prefs_ChartX8_d", 100);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_e", 0);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_f", 0x00FFFFFF);
		WriteBool(L"Prefs", L"Prefs_ChartX8_g", true);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_h",   2);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_i", 315);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_j",   0);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_k",   0);
		WriteBool(L"Prefs", L"Prefs_ChartX8_m", true);

		WriteInteger(L"Prefs", L"Prefs_ChartX8_l", 0x00FFFFFF);

		// ===========================================================================
		// == File History                                                          ==
		// ===========================================================================

		for (int t = 1; t <= 2; t++)
		{
			for (int z = 1; z <= 6; z++)
			{
				WriteBool(L"FHCompare", L"X" + std::to_wstring(t) + L"Y" + std::to_wstring(z), false);
			}
		}

		// ===========================================================================
		// ==  navigation colours                                                   ==
		// ===========================================================================

		WriteInteger(L"Prefs", L"NavColour1", 0x00EEEEEE);
		WriteInteger(L"Prefs", L"NavColour2", 0x00FF4422);
		WriteInteger(L"Prefs", L"NavColour3", 0x00EEEEEE);
		WriteInteger(L"Prefs", L"NavColour4", 0x00FF44FF);
		WriteInteger(L"Prefs", L"NavColour5", 0x00DEDDFF);
		WriteInteger(L"Prefs", L"NavColour6", 0x005603F1);

		// ===========================================================================
		// == Tab Display Options                                                   ==
		// ===========================================================================

		for (int t = 0; t < 4; t++)
		{
			WriteString(L"Prefs", L"TabDisplayOptions" + std::to_wstring(t), L"011111111111111111111");
		}

		for (int t = 0; t < 2; t++)
		{
			WriteString(L"Prefs", L"NavigateDisplayOptions" + std::to_wstring(t), L"11111111111111111111");
		}

		// ===========================================================================
		// == FTP                                                                   ==
		// ===========================================================================

		for (int t = 1; t <= kFTPOptionsCount; t++)
		{
			WriteString(L"Prefs", L"ftpOptions" + std::to_wstring(t), L"");
		}

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		WriteBool(L"Prefs", L"JustInTimeDisplay", true);
		WriteInteger(L"Prefs", L"ProgressUpdate", 1);

		WriteBool(L"Prefs", L"AddToDate", false);
		WriteBool(L"Prefs", L"AddToDateLimit", false);
		WriteInteger(L"Prefs", L"AddToDateLimitCount", 1000);

		WriteBool(L"Prefs", L"BuildDateTree", false);
		WriteBool(L"Prefs", L"GetUserDetails", false);
		WriteBool(L"Prefs", L"GetTempFiles", false);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		WriteInteger(L"Prefs", L"TableBandColour",  0x00F9FFF9);
		WriteInteger(L"Prefs", L"RowHeight",        17);

		WriteInteger(L"Prefs", L"DateFormat",       0);
		WriteInteger(L"Prefs", L"MaxSearchResults", 20000);

		WriteString(L"Prefs", L"CustomViewer", L"notepad.exe");
		WriteBool(L"Prefs", L"SaveLog", false);

		WriteInteger(L"Prefs", L"PostScanMode", __kPostScanSummary);
		WriteInteger(L"Prefs", L"PostScanIPPage",   0);

		WriteInteger(L"Prefs", L"HandleMultipleExt", 0);
		WriteBool(L"Prefs", L"Prefs_ASMode",     false);
		WriteBool(L"Prefs", L"Prefs_ASOrganise", false);

		for (int t = 1; t <= kAutoSaveItemCount; t++)
		{
			WriteBool(L"Prefs", L"Prefs_AutoSaveDrive" + std::to_wstring(t), false);
		}

		WriteBool(L"Prefs", L"Prefs_AutoCheckUpdate", true);

		WriteString(L"Prefs", L"Prefs_HTMLOutput", L"");
		WriteString(L"Prefs", L"Prefs_HTMLCompareOutput", L"");
		WriteString(L"Prefs", L"Prefs_XMLOutput", L"notepad");
		WriteString(L"Prefs", L"Prefs_TextOutput", L"notepad");

		for (int t = 1; t <= kReportTypesCount; t++)
		{
			WriteInteger(L"Prefs", L"Prefs_CSVData" + std::to_wstring(t), kDataSummary);
			WriteInteger(L"Prefs", L"Prefs_CSVUnits" + std::to_wstring(t), 0);
			WriteBool(L"Prefs", L"Prefs_CSVTitles" + std::to_wstring(t), True);
			WriteInteger(L"Prefs", L"Prefs_CSVSeparator" + std::to_wstring(t), 0);

			WriteInteger(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_HTMLUnits",    0);
			WriteString(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_Layout", L"     0:1:2:3:4:5:6:7:8:9:12:13:14:15:16:");
			WriteString(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_CategoryList", L"1111111111111111111");
			WriteInteger(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_LayoutSize",   3);

			WriteString(L"Prefs", L"TextOptions" + std::to_wstring(t) + L"_Layout", L"1:2:3:4:5:6:7:8:9:12:13:14:");
			WriteString(L"Prefs", L"TextOptions" + std::to_wstring(t) + L"_CategoryList", L"1111111111111111111");

			WriteString(L"Prefs", L"TreeOptions" + std::to_wstring(t) + L"_Layout", L"1:");
			WriteString(L"Prefs", L"TreeOptions" + std::to_wstring(t) + L"_CategoryList", L"1111111111111111111");
			WriteBool(L"Prefs", L"TreeOptions" + std::to_wstring(t) + L"_IncludeSize", True);
			WriteBool(L"Prefs", L"TreeOptions" + std::to_wstring(t) + L"_IncludeAttributes", False);

			WriteString(L"Prefs", L"XMLOptions" + std::to_wstring(t) + L"_Layout", L"1:2:3:4:5:6:7:8:9:12:13:14:");
			WriteInteger(L"Prefs", L"Prefs_XMLData" + std::to_wstring(t) + L"_Data", kDataSummary);
			WriteBool(L"Prefs", L"Prefs_XMLData" + std::to_wstring(t) + L"_Open",    False);

			WriteInteger(L"Prefs", L"XinorbisOptions" + std::to_wstring(t) + L"_Layout",  0);

			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour1",  0x990000);  // link normal
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour2",  0x000000);  // link hover
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour3",  0xFFFFFF);  // background colour
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour4",  0x990000);  // text colour
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour5",  0x0000FF);  // bargraph colour
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour6",  0xFF9900);  // table background
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour7",  0xFFFFFF);  // table colour1
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour8",  0x000000);  // table colour2
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour9",  0xFFFFFF);  // graph background
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour10", 0xDDDDDD);  // table body background
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour11", 0xCCCCCC);  // table body background II
		}

		WriteInteger(L"Prefs", L"HTMLCompareOptions" + std::to_wstring(1) + L"_HTMLUnits", 0);
		WriteString(L"Prefs", L"HTMLCompareOptions" + std::to_wstring(1) + L"_Layout", L"0:1:2:3:4:");

		WriteString(L"Prefs", L"SummarayLayout", L"1:2:3:4:5:6:7:8:9:");

		// ===========================================================================
		// ==  History                                                              ==
		// ===========================================================================

		WriteBool(L"Prefs", L"Prefs_HistorySettings_Enabled",     True);
		WriteBool(L"Prefs", L"Prefs_HistorySettings_FullLogging", True);
		WriteBool(L"Prefs", L"Prefs_HistorySettings_SQLinSearch", False);

		for (int t = 0; t < __FileCategoriesCount; t++)
		{
			WriteInteger(L"Prefs", L"ChartColour" + std::to_wstring(t + 1), __DefaultDisplayColours[t]);
		}

		// ===========================================================================
		// == Quick Folders                                                         ==
		// ===========================================================================

		for (int t = 0; t < kQuickFolderCount; t++)
		{
			WriteString(L"Prefs", L"Prefs_QuickFolder" + std::to_wstring(t + 1), L"");
		}

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		for (int t = 0; t < 10; t++)
		{
			WriteString(L"TypeDescriptions", L"TypeDescriptions" + std::to_wstring(t + 1), DefaultExtensionFileName[t + 10]);
		}

		// ===========================================================================
		// == Close                                                                 ==
		// ===========================================================================

		CloseSettings();

		// ===========================================================================
		// == Forms
		// ===========================================================================

		ClearFormDetails(__kFormFileSpread);
		ClearFormDetails(__kFormReference);
		ClearFormDetails(__kFormReport);
		ClearFormDetails(__kFormInfoDatabase);
		ClearFormDetails(__kFormExplore);
		ClearFormDetails(__kFormFileAges);
		ClearFormDetails(__kFormCombine);
		ClearFormDetails(__kFormDeplicates);
		ClearFormDetails(__kFormDuplicates);
		ClearFormDetails(__kFormReportsList);
		ClearFormDetails(__kFormSearchSyntax);

		ClearFormDetails(__kFormEditHTMLReport);
		ClearFormDetails(__kFormEditTextReport);
		ClearFormDetails(__kFormEditTreeReport);
		ClearFormDetails(__kFormEditXMLReport);
		ClearFormDetails(__kFormEditCSVReport);

		// ===========================================================================
		// ===========================================================================

//	FDefault = True; to do what does this do

		return true;
	}

	return false;
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

		Reports.HTMLColours[0]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour1" , 0x990000, -1);  // link normal
		Reports.HTMLColours[1]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour2" , 0x000000, -1);  // link hover
		Reports.HTMLColours[2]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour3",  0xFFFFFF, -1);  // background colour
		Reports.HTMLColours[3]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour4",  0x990000, -1);  // text colour
		Reports.HTMLColours[4]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour5",  0x0000FF, -1);  // bargraph colour
		Reports.HTMLColours[5]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour6",  0xFF9900, -1);  // table background
		Reports.HTMLColours[6]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour7",  0xFFFFFF, -1);  // table colour1
		Reports.HTMLColours[7]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour8",  0x000000, -1);  // table colour2
		Reports.HTMLColours[8]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour9",  0xFFFFFF, -1);  // graph background
		Reports.HTMLColours[9]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour10", 0xDDDDDD, -1);  // table body background
		Reports.HTMLColours[10] = ReadInteger(L"Prefs", L"Prefs_HTMLColour11", 0xCCCCCC, -1);  // table body background II

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		Optimisations.ProgressUpdate = ReadIntegerInputCheck(L"Prefs", L"ProgressUpdate", 1, 0, 5);

		Optimisations.GetUserDetails = ReadBool(L"Prefs", L"GetUserDetails", false);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		General.DateFormat = ReadIntegerInputCheck(L"Prefs", L"DateFormat", 0, 0, 4);

		System.HandleMultipleExt = ReadIntegerInputCheck(L"Prefs", L"HandleMultipleExt", 0, 0, 2);

		// ===========================================================================
        /*
        var
  tsho   : TScanHistoryObject;
  t,z    : integer;
  s      : string;
  tf     : TextFile;

begin
  // ===========================================================================
  // ===========================================================================
  // == Initialise                                                            ==
  // ===========================================================================
  // ===========================================================================

  if OpenSettings(True) then begin

    // ===========================================================================
    // ===========================================================================
    // == Donation Stuff :(                                                     ==
    // ===========================================================================
    // ===========================================================================

    XSettings.System.RunX = ReadIntegerFromSettings(L"Prefs", L"RunX", 0, -1);

    // ===========================================================================
    // ===========================================================================
    // == Load Settings                                                         ==
    // ===========================================================================
    // ===========================================================================

    with frmMain do begin
      Top        = ReadIntegerFromSettings(L"Prefs", L"Main_Top", 5, -1);
      Left       = ReadIntegerFromSettings(L"Prefs", L"Main_Left", 5, -1);
      Width      = ReadIntegerFromSettings(L"Prefs", L"Main_Width", 1016, 1016);
      Height     = ReadIntegerFromSettings(L"Prefs", L"Main_Height", 700, 700);

      System.Tutorial   = ReadBoolFromSettings(L"Prefs", L"Tutorial", True);

      pTutorial.Visible = System.Tutorial;
    end;

    // ===========================================================================
    // == Chart Options                                                         ==
    // ===========================================================================

    //Charts.Options.ChartStyles   = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_ChartStyle", DefaultChartStyles[t], 0, 1);

	Charts.Options.ChartFrom     = ReadIntegerFromSettings(          'Prefs", L"Prefs_ChartX8_a", $00333333, -1); // check
    Charts.Options.ChartTo       = ReadIntegerFromSettings(          'Prefs", L"Prefs_ChartX8_b", $00333333, -1);
	Charts.Options.ChartGradient = ReadBoolFromSettings(             'Prefs", L"Prefs_ChartX8_c", False);

    Charts.Options.Zoom          = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_ChartX8_d", 100, 0, 150);
    Charts.Options.Explode       = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_ChartX8_e", 0, 0, 150);
    Charts.Options.MarkColour    = ReadIntegerFromSettings(          'Prefs", L"Prefs_ChartX8_f", $00FFFFFF, -1);
    Charts.Options.ShowMarks     = ReadBoolFromSettings(             'Prefs", L"Prefs_ChartX8_g", True);
    Charts.Options.MarksType     = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_ChartX8_h", 2, 0, 4);
    Charts.Options.Elevation     = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_ChartX8_i", 315, 315, 315);
    Charts.Options.LabelOptions  = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_ChartX8_j", 0, 0, 8);
    Charts.Options.XAxisDelta    = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_ChartX8_k", 0, 0, 0);
    Charts.Options.ShowLegend    = ReadBoolFromSettings(             'Prefs", L"Prefs_ChartX8_m", True);

    Charts.Options.TitleColour   = ReadIntegerFromSettings(          'Prefs", L"Prefs_ChartX8_l", $00FFFFFF, -1);

    // ===========================================================================
    // == File History                                                          ==
    // ===========================================================================

    for t = 1 to 2 do begin
      for z = 1 to 6 do begin
		FHCompare[t, z] = ReadBoolFromSettings(L"FHCompare", L"X' + std::to_wstring(t) + 'Y' + std::to_wstring(z), False);
      end;
    end;

    // ===========================================================================
    // ==  navigation colours                                                   ==
    // ===========================================================================

    Navigation.BarColours[1] = ReadIntegerFromSettings(L"Prefs", L"NavColour1", $00EEEEEE, -1);
    Navigation.BarColours[2] = ReadIntegerFromSettings(L"Prefs", L"NavColour2", $00FF4422, -1);
    Navigation.BarColours[3] = ReadIntegerFromSettings(L"Prefs", L"NavColour3", $00EEEEEE, -1);
	Navigation.BarColours[4] = ReadIntegerFromSettings(L"Prefs", L"NavColour4", $00FF44FF, -1);
    Navigation.BarColours[5] = ReadIntegerFromSettings(L"Prefs", L"NavColour5", $00DEDDFF, -1);
    Navigation.BarColours[6] = ReadIntegerFromSettings(L"Prefs", L"NavColour6", $005603F1, -1);

    // ===========================================================================
    // == Tab Display Options                                                   ==
    // ===========================================================================

    for t = 0 to 3 do
      TabDisplayOptions[t]      = ReadStringFromSettings(L"Prefs", L"TabDisplayOptions' + std::to_wstring(t), L"011111111111111111111');

    for t = 0 to 1 do
    begin
	  Navigation.DisplayOptions[t] = ReadStringFromSettings(L"Prefs", L"NavigateDisplayOptions' + std::to_wstring(t), L"11111111111111111111');

      if length(Navigation.DisplayOptions[t]) <> 20 then
        Navigation.DisplayOptions[t] = '11111111111111111111';
    end;

    // ===========================================================================
    // == FTP                                                                   ==
    // ===========================================================================

    for t = 1 to ftpOptionsCount do
      ftpOptions[t] = ReadStringFromSettings(L"Prefs", L"ftpOptions' + std::to_wstring(t), L"');

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    Optimisations.JustInTimeDisplay       = ReadBoolFromSettings(L"Prefs", L"JustInTimeDisplay", True);
    Optimisations.ProgressUpdate          = ReadIntegerFromSettingsInputCheck(L"Prefs", L"ProgressUpdate", 1, 0, 5);

    ProgressPercentage                    = ProgressUpdates[Optimisations.ProgressUpdate, 1];
    ProgressFileCount                     = ProgressUpdates[Optimisations.ProgressUpdate, 2];

    Optimisations.AddToDate               = ReadBoolFromSettings(L"Prefs", L"AddToDate", False);
    Optimisations.AddToDateLimit          = ReadBoolFromSettings(L"Prefs", L"AddToDateLimit", False);
    Optimisations.AddToDateLimitCount     = ReadIntegerFromSettings(L"Prefs", L"AddToDateLimitCount", 1000, -1);

    Optimisations.BuildDateTree           = ReadBoolFromSettings(L"Prefs", L"BuildDateTree", False);
    Optimisations.GetUserDetails          = ReadBoolFromSettings(L"Prefs", L"GetUserDetails", False);
    Optimisations.GetTempFiles            = ReadBoolFromSettings(L"Prefs", L"GetTempFiles", False);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    General.TableBandColour         = ReadIntegerFromSettings(L"Prefs", L"TableBandColour", $00F9FFF9, -1);
    General.RowHeight               = ReadIntegerFromSettingsInputCheck(L"Prefs", L"RowHeight", 17, 15, 40);

    General.DateFormat              = ReadIntegerFromSettingsInputCheck(L"Prefs", L"DateFormat", 0, 0, 4);
    General.MaxSearchResults        = ReadIntegerFromSettings(L"Prefs", L"MaxSearchResults", 20000, 20000);

    General.CustomViewer            = ReadStringFromSettings(L"Prefs", L"CustomViewer", L"notepad.exe');

    General.SaveLog                 = ReadBoolFromSettings(L"Prefs", L"SaveLog",        False);

    General.PostScanMode            = ReadIntegerFromSettingsInputCheck(L"Prefs", L"PostScanMode", CPostScanSummary, 0, 3);
    General.PostScanIPPage          = ReadIntegerFromSettingsInputCheck(L"Prefs", L"PostScanIPPage", 0, 0, 10);

    HandleMultipleExt               = ReadIntegerFromSettingsInputCheck(L"Prefs", L"HandleMultipleExt", 0, 0, 2);
    Report.AutoSaveMode             = ReadBoolFromSettings(L"Prefs", L"Prefs_ASMode", false);
    Report.AutoSaveOrganise         = ReadBoolFromSettings(L"Prefs", L"Prefs_ASOrganise", false);

    for t = 1 to AutoSaveItemCount do
	  Report.AutoSaveItem[t] = ReadBoolFromSettings(L"Prefs", L"Prefs_AutoSaveDrive' + std::to_wstring(t), False);

    General.AutoCheckUpdate         = ReadBoolFromSettings(L"Prefs", L"Prefs_AutoCheckUpdate", True);

    Report.HTMLOutput              = ReadStringFromSettings(L"Prefs", L"Prefs_HTMLOutput", L"');
    Report.HTMLCompareOutput       = ReadStringFromSettings(L"Prefs", L"Prefs_HTMLCompareOutput", L"');
    Report.XMLOutput               = ReadStringFromSettings(L"Prefs", L"Prefs_XMLOutput", L"notepad');

    Report.TextOutput              = ReadStringFromSettings(L"Prefs", L"Prefs_TextOutput", L"notepad');

    for t = 1 to ReportTypesCount do begin
	  Report.CSVOptions[t].CSVData                 = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_CSVData' + std::to_wstring(t), CDataFileList, CDataSummary, CDataFileList);
	  Report.CSVOptions[t].CSVUnits                = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_CSVUnits' + std::to_wstring(t), 0, 0, 3);
	  Report.CSVOptions[t].CSVTitles               = ReadBoolFromSettings(             'Prefs", L"Prefs_CSVTitles' + std::to_wstring(t), True);
	  Report.CSVOptions[t].CSVSeparator            = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_CSVSeparator' + std::to_wstring(t), 0, 0, 1);
      Report.CSVOptions[t].CSVAutoOpen             = False;

	  Report.HTMLOptions[t].HTMLUnits              = ReadIntegerFromSettingsInputCheck(L"Prefs", L"HTMLOptions' + std::to_wstring(t) + '_HTMLUnits", 0, 0, 3);
	  Report.HTMLOptions[t].Layout                 = ReadStringFromSettings(L"Prefs",  'HTMLOptions' + std::to_wstring(t) + '_Layout", L"0:1:2:3:4:5:6:7:8:9:12:13:14:15:16:17:');
	  Report.HTMLOptions[t].CategoryList           = ReadStringFromSettings(L"Prefs",  'HTMLOptions' + std::to_wstring(t) + '_CategoryList", L"1111111111111111111');
	  Report.HTMLOptions[t].LayoutSize             = ReadIntegerFromSettingsInputCheck(L"Prefs", L"HTMLOptions' + std::to_wstring(t) + '_LayoutSize", 3, 1, 3);

	  Report.TextOptions[t].Layout                 = ReadStringFromSettings(L"Prefs", L"TextOptions' + std::to_wstring(t) + '_Layout", L"1:2:3:4:5:6:7:8:9:12:13:14:15:');
	  Report.TextOptions[t].CategoryList           = ReadStringFromSettings(L"Prefs", L"TextOptions' + std::to_wstring(t) + '_CategoryList", L"1111111111111111111');

	  Report.TreeOptions[t].Layout                 = ReadStringFromSettings(L"Prefs", L"TreeOptions' + std::to_wstring(t) + '_Layout", L"1:');
	  Report.TreeOptions[t].CategoryList           = ReadStringFromSettings(L"Prefs", L"TreeOptions' + std::to_wstring(t) + '_CategoryList", L"1111111111111111111');
	  Report.TreeOptions[t].IncludeSize            = ReadBoolFromSettings(L"Prefs",   'TreeOptions' + std::to_wstring(t) + '_IncludeSize", True);
	  Report.TreeOptions[t].IncludeAttributes      = ReadBoolFromSettings(L"Prefs",   'TreeOptions' + std::to_wstring(t) + '_IncludeAttributes", False);

	  Report.XMLOptions[t].Layout                  = ReadStringFromSettings(L"Prefs", L"XMLOptions' + std::to_wstring(t) + '_Layout",  '1:2:3:4:5:6:7:8:9:12:13:14:15:');
	  Report.XMLOptions[t].XMLData                 = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_XMLData' + std::to_wstring(t) + '_Data", CDataFileList, CDataSummary, CDataFileList);
	  Report.XMLOptions[t].XMLAutoOpen             = ReadBoolFromSettings(L"Prefs", L"Prefs_XMLData' + std::to_wstring(t) + '_Open", False);

	  Report.XinorbisOptions[t].Layout             = ReadIntegerFromSettings(L"Prefs", L"XinorbisOptions' + std::to_wstring(t) + '_Layout",  0, -1);

	  Report.HTMLOptions[t].HTMLColours.Colour[1]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour1",  $990000, -1);  // link normal
	  Report.HTMLOptions[t].HTMLColours.Colour[2]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour2",  $000000, -1);  // link hover
	  Report.HTMLOptions[t].HTMLColours.Colour[3]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour3",  $FFFFFF, -1);  // background colour
	  Report.HTMLOptions[t].HTMLColours.Colour[4]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour4",  $990000, -1);  // text colour
	  Report.HTMLOptions[t].HTMLColours.Colour[5]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour5",  $0000FF, -1);  // bargraph colour
	  Report.HTMLOptions[t].HTMLColours.Colour[6]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour6",  $FF9900, -1);  // table background
	  Report.HTMLOptions[t].HTMLColours.Colour[7]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour7",  $FFFFFF, -1);  // table colour1
	  Report.HTMLOptions[t].HTMLColours.Colour[8]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour8",  $000000, -1);  // table colour2
	  Report.HTMLOptions[t].HTMLColours.Colour[9]  = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour9",  $FFFFFF, -1);  // graph background
	  Report.HTMLOptions[t].HTMLColours.Colour[10] = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour10", $DDDDDD, -1);  // table body background
	  Report.HTMLOptions[t].HTMLColours.Colour[11] = ReadIntegerFromSettings(L"Prefs", L"Prefs_Report' + std::to_wstring(t) + 'HTMLColour11", $CCCCCC, -1);  // table body background II
    end;

	Report.HTMLCompareOptions.HTMLUnits            = ReadIntegerFromSettingsInputCheck(L"Prefs", L"HTMLCompareOptions' + std::to_wstring(1) + '_HTMLUnits", 0, 0, 3);
	Report.HTMLCompareOptions.Layout               = ReadStringFromSettings(L"Prefs",  'HTMLCompareOptions' + std::to_wstring(1) + '_Layout", L"0:1:2:3:4:');

    Report.SummaryLayout                           = ReadStringFromSettings(L"Prefs",  'SummarayLayout",  '1:2:3:4:5:6:7:8:9:10:');

    // ===========================================================================
    // ==  History                                                              ==
    // ===========================================================================

    HistorySettings.Enabled     = ReadBoolFromSettings(L"Prefs", L"Prefs_HistorySettings_Enabled", True);
    HistorySettings.FullLogging = ReadBoolFromSettings(L"Prefs", L"Prefs_HistorySettings_FullLogging", True);
    HistorySettings.SQLinSearch = ReadBoolFromSettings(L"Prefs", L"Prefs_HistorySettings_SQLinSearch", False);

    GSystemGlobal.FileCategoryColors[0] = $00FFFFFF; // for folders

    for t = 1 to __FileCategoriesCount do
	  GSystemGlobal.FileCategoryColors[t] = ReadIntegerFromSettings(L"Prefs", L"ChartColour' + std::to_wstring(t), DefaultDisplayColours[t], -1);

    // ===========================================================================
    // == Quick Folders                                                         ==
    // ===========================================================================

    for t = 1 to QuickFolderCount do begin
	  s = ReadStringFromSettings(L"Prefs", L"Prefs_QuickFolder' + std::to_wstring(t), L"');

      if s <> '' then begin
        XSQuickFolder[t] = s;
      end;
    end;

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    for t = 1 to 10 do
      TypeDescriptions[t + 9] = ReadStringFromSettings(L"TypeDescriptions", L"TypeDescriptions' + std::to_wstring(t), defaultextfn[t + 9]);

    // ===========================================================================
    // == Close                                                                 ==
    // ===========================================================================

    CloseSettings;
  end;

  // ===========================================================================
  // == Update                                                                ==
  // ===========================================================================

  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
    if FileExists(GSystemGlobal.AppDataPath + 'scanhistory.dat') then begin
      try
		AssignFile(tf, GSystemGlobal.AppDataPath + 'scanhistory.dat');
        Reset(tf);

        While not(eof(tf)) do begin
          tsho = TScanHistoryObject.Create;

          readln(tf, s);
          tsho.Path           = s;

          readln(tf, s);
          tsho.DateI          = StrToIntDef(s, 19000101);

          readln(tf, s);
          tsho.TimeI          = s;

          readln(tf, s);
          tsho.ExcludeFiles   = s;

          readln(tf, s);
          tsho.ExcludeFolders = s;

          ScanHistory.Add(tsho);
        end;
      finally
        CloseFile(tf);
      end;
    end;
  end
  else begin
    FReg = TRegistry.Create(KEY_READ);

    try
      FReg.RootKey = HKEY_CURRENT_USER;
      FReg.OpenKey(L"\software\' + XinorbisRegistryKey + '\SinglePaths", True);

	  t = 0;
	  While FReg.ValueExists(L"PathX' + std::to_wstring(t)) do begin
        tsho = TScanHistoryObject.Create;

		tsho.Path           = FReg.ReadString(L"PathX' + std::to_wstring(t));
		tsho.DateI          = StrToIntDef(FReg.ReadString(L"PathY' + std::to_wstring(t)), 19000101);
		tsho.TimeI          = FReg.ReadString(L"PathZ' + std::to_wstring(t));
		tsho.ExcludeFiles   = FReg.ReadString(L"PathE1' + std::to_wstring(t));
        tsho.ExcludeFolders = FReg.ReadString(L"PathE2' + std::to_wstring(t));

        ScanHistory.Add(tsho);

        inc(t);
      end;

    finally
      FReg.Free;
    end;

    // ===========================================================================
    // ===========================================================================

    FReg = TRegistry.Create(KEY_READ);

    try
      FReg.RootKey = HKEY_CURRENT_USER;
      if FReg.OpenKey(L"\software\' + XinorbisRegistryKey + '\ChartColours", False) then begin
        GSystemGlobal.FileCategoryColors[0] = $00FFFFFF; // for folders

        for t = 1 to __FileCategoriesCount do begin
		  if FReg.ValueExists(L"ChartColour' + std::to_wstring(t)) then
            GSystemGlobal.FileCategoryColors[t] = FReg.ReadInteger(L"ChartColour' + std::to_wstring(t))
          else
            GSystemGlobal.FileCategoryColors[t] = DefaultDisplayColours[t];
        end;
      end
      else begin
        GSystemGlobal.FileCategoryColors[0] = $00FFFFFF; // for folders
        for t = 1 to __FileCategoriesCount do begin
          GSystemGlobal.FileCategoryColors[t] = DefaultDisplayColours[t];
        end;
      end;
    finally
      FReg.Free;
    end;
  end;

  // ===========================================================================
  // ===========================================================================

  //FileExtensionList.Clear;

  Result = -1;
		*/


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
			FileCategoryColors[t] = ReadInteger(L"Prefs", L"Chart Colour" + std::to_wstring(t), __DefaultDisplayColours[t], -1);
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


int SettingsHandler::LanguageToInt(LanguageType lt)
{
	switch (lt)
	{
	case LanguageType::kUK:
		return 1;
	case LanguageType::kNL:
		return 2;
	case LanguageType::kFR:
		return 3;
	case LanguageType::kDE:
		return 4;
	case LanguageType::kIT:
		return 5;
	case LanguageType::kPT:
		return 6;
	case LanguageType::kES:
		return 7;
	case LanguageType::kSW:
		return 8;
	case LanguageType::kCZ:
		return 9;
	case LanguageType::kHU:
		return 10;
	case LanguageType::kUS:
		return 11;
	case LanguageType::kRU:
		return 12;
	case LanguageType::kCAT:
		return 13;
	}

	return 0;
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

	int language = ReadInteger(L"Prefs", L"Language", -1, 0);

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


std::wstring SettingsHandler::ReadString(const std::wstring section, const std::wstring name, const std::wstring default_value)
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


int SettingsHandler::ReadInteger(const std::wstring section, const std::wstring name, int default_value, int ifZero)
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


int SettingsHandler::ReadIntegerInputCheck(const std::wstring section, const std::wstring name, int default_value, int min, int max)
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


bool SettingsHandler::ReadBool(const std::wstring section, const std::wstring name, bool default_value)
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


void SettingsHandler::WriteInteger(const std::wstring section, const std::wstring name, int value)
{
}


void SettingsHandler::WriteString(const std::wstring section, const std::wstring name, const std::wstring)
{
}


void SettingsHandler::WriteBool(const std::wstring section, const std::wstring name, bool value)
{
}


FormDetails SettingsHandler::LoadFormDetails(int FormId)
{
	FormDetails fd(FormId, -1, -1, -1, -1);

/*	if (customsettings.SettingsSaveLocation == SaveLocationConfigIni)
	{
		try
		  config = TINIFile.Create(GSystemGlobal.ExePath + L"custom.ini");

		  if config.SectionExists(L"Form_" + std::to_wstring(formID)) then begin
			Result.x  = config.ReadInteger(L"Form_" + std::to_wstring(formID), L"w", -1);
			Result.y  = config.ReadInteger(L"Form_" + std::to_wstring(formID), L"y", -1);
			Result.w  = config.ReadInteger(L"Form_" + std::to_wstring(formID), L"w", -1);
			Result.h  = config.ReadInteger(L"Form_" + std::to_wstring(formID), L"h", -1);
			Result.p1 = config.ReadInteger(L"Form_" + std::to_wstring(formID), L"p1", -1);
			Result.p2 = config.ReadInteger(L"Form_" + std::to_wstring(formID), L"p2", -1);
			Result.p3 = config.ReadInteger(L"Form_" + std::to_wstring(formID), L"p3", -1);
			Result.p4 = config.ReadInteger(L"Form_" + std::to_wstring(formID), L"p4", -1);
		  end
		  else
			Result.formID = -1;
		finally
		  config.Free;
		end;
	}
	else
	{
		Reg = TRegistry.Create(KEY_READ);

		Reg.RootKey = HKEY_CURRENT_USER;

		if Reg.KeyExists(L"\\software\\" + XinorbisRegistryKey + L"\\Form_" + std::to_wstring(formID)) then begin
		  Reg.OpenKey(L"\\software\\" + XinorbisRegistryKey + L"\\Form_" + std::to_wstring(formID), False);

		  Result.x  = Reg.ReadInteger(L"x");
		  Result.y  = Reg.ReadInteger(L"y");
		  Result.w  = Reg.ReadInteger(L"w");
		  Result.h  = Reg.ReadInteger(L"h");
		  Result.p1 = Reg.ReadInteger(L"p1");
		  Result.p2 = Reg.ReadInteger(L"p2");
		  Result.p3 = Reg.ReadInteger(L"p3");
		  Result.p4 = Reg.ReadInteger(L"p4");
		end
		else
		  Result.formID = -1;

		Reg.CloseKey;
		Reg.Free;
	}                */

	return fd;
}


void SettingsHandler::SaveFormDetails(FormDetails &fd)
{            /*
	if (customsettings.SettingsSaveLocation = SaveLocationConfigIni)
	{
		try
		  config = TINIFile.Create(GSystemGlobal.ExePath + L"custom.ini");

		  config.WriteInteger(L"Form_" + std::to_wstring(FormDetails.formID), L"w",  FormDetails.x);
		  config.WriteInteger(L"Form_" + std::to_wstring(FormDetails.formID), L"y",  FormDetails.y);
		  config.WriteInteger(L"Form_" + std::to_wstring(FormDetails.formID), L"w",  FormDetails.w);
		  config.WriteInteger(L"Form_" + std::to_wstring(FormDetails.formID), L"h",  FormDetails.h);
		  config.WriteInteger(L"Form_" + std::to_wstring(FormDetails.formID), L"p1", FormDetails.p1);
		  config.WriteInteger(L"Form_" + std::to_wstring(FormDetails.formID), L"p2", FormDetails.p2);
		  config.WriteInteger(L"Form_" + std::to_wstring(FormDetails.formID), L"p3", FormDetails.p3);
		  config.WriteInteger(L"Form_" + std::to_wstring(FormDetails.formID), L"p4", FormDetails.p4);
		finally
		  config.Free;
		end;
	}
	else
	{
		Reg = TRegistry.Create(KEY_WRITE);

		Reg.RootKey = HKEY_CURRENT_USER;

		Reg.OpenKey(L"\\software\\" + XinorbisRegistryKey + L"\\Form_" + std::to_wstring(FormDetails.formID), True);

		Reg.WriteInteger(L"x",  FormDetails.x);
		Reg.WriteInteger(L"y",  FormDetails.y);
		Reg.WriteInteger(L"w",  FormDetails.w);
		Reg.WriteInteger(L"h",  FormDetails.h);
		Reg.WriteInteger(L"p1", FormDetails.p1);
		Reg.WriteInteger(L"p2", FormDetails.p2);
		Reg.WriteInteger(L"p3", FormDetails.p3);
		Reg.WriteInteger(L"p4", FormDetails.p4);

		Reg.CloseKey;
		Reg.Free;
	}         */
}


bool SettingsHandler::ClearFormDetails(int FormId)
{    /*
	if (customsettings.SettingsSaveLocation = SaveLocationConfigIni)
	{
		try
		  config = TINIFile.Create(GSystemGlobal.ExePath + L"custom.ini");

		  config.EraseSection(L"Form_" + std::to_wstring(aFormID));
		finally
		  config.Free;
		end;
	}
	else
	{
		Reg = TRegistry.Create(KEY_WRITE);

		Reg.RootKey = HKEY_CURRENT_USER;

		Reg.DeleteKey(L"\\software\\" + XinorbisRegistryKey + L"\\Form_" + std::to_wstring(aFormID));

		Reg.CloseKey;
		Reg.Free;
	}  */

    return false;
}
