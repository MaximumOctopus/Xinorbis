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

#include "ChartOptions.h"
#include "ConstantsData.h"
#include "ConstantsLanguage.h"
#include "FormDetails.h"
#include "Ini.h"
#include "ConstantsParameters.h"
#include "ConstantsReports.h"
#include "ReportCSVOptions.h"
#include "ReportDateOptions.h"
#include "ReportHTMLOptions.h"
#include "ReportTextOptions.h"
#include "ReportTreeOptions.h"
#include "ReportXinorbisOptions.h"
#include "ReportXMLOptions.h"
#include "Setting.h"


enum class SettingsSource { None = 0, ConfigIni = 1, Registry = 2 };


struct CustomSettings
{
	SettingsSource SettingsSaveLocation = SettingsSource::None;

	bool CopyPreferences = false;
};


struct DatabaseSettings
{
	bool Enabled = false;

	bool UseODBC = false;
};


struct GeneralSettings
{
    bool AutoCheckUpdate = false;

	DateFormat FormatDate = DateFormat::kSlashDDMMYYYY;

	std::wstring DecimalSeparator = L".";

	bool ShowStatusOutput = true;
	bool ShowProgress = true;

	int MaxSearchResults = 10000;

	int PostScanMode = 0;
	int PostScanIPPage = 0;

	std::wstring CustomViewer = L"";
};


struct OptimisationSettings
{
	bool ProcessData = false;
	bool GetTempFiles = false;
	bool GetUserDetails = false;

	bool BuildDateTree = false;

	bool AddToDate = false;
	bool AddToDateLimit = false;
    int AddToDateLimitCount = 10000;

	bool JustInTimeDisplay = false;

	int ProgressUpdate = 0;

	// calculated optimisation settings based on user parameters
	bool UseFastAnalysis = true;
};


struct ReportSettings
{
	std::wstring CSVOutput = L"";
	std::wstring HTMLOutput = L"";
	std::wstring SummaryLayout = L"";
	std::wstring TextOutput = L"";
	std::wstring TreeOutput = L"";
	std::wstring XMLOutput = L"";

	CSVReportOptions CSV[kReportTypeCount];
	DateReportOptions Date[kReportTypeCount];
	HTMLReportOptions HTML[kReportTypeCount];
	TextReportOptions Text[kReportTypeCount];
	TreeReportOptions Tree[kReportTypeCount];
	XinorbisReportOptions Xinorbis[kReportTypeCount];
	XMLReportOptions XML[kReportTypeCount];

	bool AutoSaveMode = false;
	bool AutoSaveOrganise = false;
//	AutoSaveItem         : array[1..6] of boolean;
};


struct AppearanceSettings
{
	int RowHeight = 17;

	int BarColours[6] = { 0, 0, 0, 0, 0, 0 };
};


struct SystemSettings
{
	bool Loaded = false;

	bool Processed = false;

	LanguageType CurrentLanguage = LanguageType::kUndefined;
	int HandleMultipleExt = 0;

	bool Debug = false;
};


struct TabDisplayOptions
{
	Setting Option[22];
};


struct TabInternalOptions
{
	int TreeViewChartIndex = 0;
};

class SettingsHandler
{
    HKEY hKey;

	Ini* __iniFile;

	bool OpenSettings(bool);
	bool CloseSettings();

    bool ClearFormDetails(int);

	bool LoadBasic();
	bool LoadCustomSettings();
	bool LoadLanguage();

	int LanguageToInt(LanguageType);

	std::wstring ReadString(const std::wstring, const std::wstring, std::wstring);
	int ReadInteger(const std::wstring, const std::wstring, int, int);
	int ReadIntegerInputCheck(const std::wstring, const std::wstring, int, int, int);
	bool ReadBool(const std::wstring, const std::wstring, bool);

	void WriteString(const std::wstring, const std::wstring, std::wstring);
	void WriteInteger(const std::wstring, const std::wstring, int);
	void WriteBool(const std::wstring, const std::wstring, bool);

public:

	ChartOptions Chart;
	TabDisplayOptions TabDisplay[4];
	TabInternalOptions TabInternal;

    AppearanceSettings Appearance;
	CustomSettings Custom;
	DatabaseSettings Database;
	GeneralSettings General;
	OptimisationSettings Optimisations;
	ReportSettings Reports;
	SystemSettings System;

    std::wstring QuickFolders[kQuickFolderCount];

	int FileCategoryColors[__FileCategoriesCount]; // 0 is a hack for "folders"

	void ProcessProcessingSetting(ParameterOption);

	void SetDefaults();

	FormDetails LoadFormDetails(int);
	void SaveFormDetails(FormDetails &);

	bool SaveDefaults();

	SettingsHandler();
};
