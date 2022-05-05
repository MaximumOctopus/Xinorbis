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


#pragma once



#include <Windows.h>
#include <string>

#include "Ini.h"
#include "ReportHTMLReportOptions.h"


struct CustomSettings
{
    bool SettingsSaveLocation;
    bool CopyPreferences;
};


struct DatabaseSettings
{
	bool UpdateFolderHistory;

	bool UpdateScanHistory;
	
	int DatabaseMode; // __dbSQLite or __dbODBC

	bool DBStructured;
	bool SystemTable;
	bool DataTable;

	std::wstring ODBCConnectionString;

	std::wstring SystemTableName;
	std::wstring DataTableName;
};


struct GeneralSettings
{
    int DateFormat; // 0: dd/mm/yyyy 1: mm/dd/yyyy 2: yyyy/mm/dd

    bool ShowStatusOutput;
    bool ShowProgress;
};


struct OptimisationSettings
{
	bool ProcessData;
	bool GetTempFiles;
	bool GetUserDetails;
	
    int ProgressUpdate;
};


struct ReportSettings
{
	int HTMLColours[__HTMLColoursCount];
	bool HTMLMonoBargraph;

	std::wstring HTMLOutput;
	HTMLReportOptions HTMLOptions;

	std::wstring HTMLCompareOutput;
};


struct SystemSettings
{
	bool Loaded;

    std::wstring ActivatedName;
    std::wstring ActivatedEmail;
    std::wstring ActivatedCode;

    bool Processed;

    int CurrentLanguage;
    int HandleMultipleExt;

    bool Debug;
};


class Settings
{
private:
    HKEY hKey;

	Ini* __iniFile;

    bool OpenSettings(bool readOnly);
    bool CloseSettings();

    bool LoadBasic();
	bool LoadCustomSettings();
    bool LoadLanguage();

    std::wstring ReadStringFromSettings(std::wstring section, std::wstring name, std::wstring defaultValue);
    int ReadIntegerFromSettings(std::wstring section, std::wstring name, int defaultValue, int ifZero);
    int ReadIntegerFromSettingsInputCheck(std::wstring section, std::wstring name, int defaultValue, int min, int max);
    bool ReadBoolFromSettings(std::wstring section, std::wstring name, bool defaultValue);

public:
    CustomSettings Custom;
    DatabaseSettings Database;
    GeneralSettings General;
    OptimisationSettings Optimisations;
    ReportSettings Report;
    SystemSettings System;

	int FileCategoryColors[__FileCategoriesCount]; // 0 is a hack for "folders"

	void ProcessProcessingSetting(int pps);
	void ProcessDatabaseSetting(int pds, std::wstring value);

	void SetDefaults();

    Settings();
};