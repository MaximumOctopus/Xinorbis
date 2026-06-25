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

#pragma once

#include <Windows.h>

#include "ConstantsData.h"
#include "ConstantsLanguage.h"
#include "Ini.h"
#include "ConstantsParameters.h"
#include "ConstantsReports.h"
#include "ReportHTMLOptions.h"


enum class SettingsSource { None = 0, ConfigIni = 1, Registry = 2 };

struct CustomSettings
{
	SettingsSource SettingsSaveLocation = SettingsSource::None;

	bool CopyPreferences = false;
};


struct GeneralSettings
{
    int DateFormat = 2; // 0: dd/mm/yyyy 1: mm/dd/yyyy 2: yyyy/mm/dd

	std::wstring DecimalSeparator = L".";

    bool ShowStatusOutput = true;
    bool ShowProgress = true;
};


struct OptimisationSettings
{
	bool ProcessData = false;
	bool GetTempFiles = false;
	bool GetUserDetails = false;

	int ProgressUpdate = 0;

	// calculated optimisation settings based on user parameters
	bool UseFastAnalysis = true;
};


struct ReportSettings
{
	int HTMLColours[__HTMLColoursCount] = { 0 };
	bool HTMLMonoBargraph = false;

	std::wstring HTMLOutput = L"";
	HTMLReportOptions HTMLOptions;

	std::wstring HTMLCompareOutput = L"";
};


struct SystemSettings
{
	bool Loaded = false;

	bool Processed = false;

	LanguageType CurrentLanguage = LanguageType::kUndefined;
	int HandleMultipleExt = 0;

	bool Debug = false;
};


class SettingsHandler
{

    HKEY hKey;

	Ini* __iniFile;

	bool OpenSettings(bool);
	bool CloseSettings();

	bool LoadBasic();
	bool LoadCustomSettings();
	bool LoadLanguage();

	std::wstring ReadStringFromSettings(const std::wstring, const std::wstring, std::wstring);
	int ReadIntegerFromSettings(const std::wstring, const std::wstring, int, int);
	int ReadIntegerFromSettingsInputCheck(const std::wstring, const std::wstring, int, int, int);
	bool ReadBoolFromSettings(const std::wstring, const std::wstring, bool);

public:

	CustomSettings Custom;
	GeneralSettings General;
	OptimisationSettings Optimisations;
	ReportSettings Reports;
	SystemSettings System;

	int FileCategoryColors[__FileCategoriesCount]; // 0 is a hack for "folders"

	void ProcessProcessingSetting(ParameterOption);

	void SetDefaults();

	SettingsHandler();
};
