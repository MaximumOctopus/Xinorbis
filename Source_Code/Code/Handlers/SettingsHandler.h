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
#include "ConstantsSettings.h"
#include "ReportCSVOptions.h"
#include "ReportDateOptions.h"
#include "ReportHTMLOptions.h"
#include "ReportHTMLCompareOptions.h"
#include "ReportJSONOptions.h"
#include "ReportSummaryOptions.h"
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


struct FolderHistorySettings
{
	bool Compare[2][6];
};


struct DatabaseSettings
{
	bool Enabled = false;

	bool FolderHistoryEnabled = false;

	bool Privacy = false;

	bool UseODBC = false;
};


struct FTPSettings
{
	std::wstring Options[kFTPOptionsCount];
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

	bool SaveLog = false;

	std::wstring CustomViewer = L"";

	int DateFormatToInt()
	{
		switch (FormatDate)
		{
		case DateFormat::kSlashDDMMYYYY:
			return 0;
		case DateFormat::kSlashMMDDYYYY:
			return 1;
		case DateFormat::kSlashYYYYMMDD:
			return 2;
		case DateFormat::kHyphenDDMMYYYY:
			return 3;
		case DateFormat::kHyphenMMDDYYYY:
			return 4;
		case DateFormat::kYYYYMMDD:
			return 5;
		};

        return 2;
	}
};


struct HistorySettings
{
	bool Enabled = false;

	bool FullLogging = false;

    bool SQLinSearch = false;
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
	bool UseFastAnalysis = false;
};


struct NavigationOptions
{
	std::wstring Display[2] = { L"11111111111111111111", L"11111111111111111111" };
};


struct ReportSettings
{
	std::wstring CSVCommand = L"";
	std::wstring DateCommand = L"";
	std::wstring HTMLCommand = L"";
	std::wstring JSONCommand = L"";
	std::wstring SummaryCommand = L"";
	std::wstring TextCommand = L"";
	std::wstring TreeCommand = L"";
	std::wstring XinorbisCommand = L"";
	std::wstring XMLCommand = L"";

	std::wstring HTMLCompareCommand = L"";

	CSVReportOptions CSV[kReportTypeCount];
	DateReportOptions Date[kReportTypeCount];
	HTMLReportOptions HTML[kReportTypeCount];
	JSONReportOptions JSON[kReportTypeCount];
	SummaryReportOptions Summary;
	TextReportOptions Text[kReportTypeCount];
	TreeReportOptions Tree[kReportTypeCount];
	XinorbisReportOptions Xinorbis[kReportTypeCount];
	XMLReportOptions XML[kReportTypeCount];

	HTMLCompareReportOptions HTMLCompare;

	bool AutoSaveMode = false;
	bool AutoSaveOrganise = false;
	bool AutoSaveItem[8];
};


struct AppearanceSettings
{
	int RowHeight = 17;

	int TableBandColour = 0;

	int BarColours[6] = { 0, 0, 0, 0, 0, 0 };
};


struct SystemSettings
{
	bool Loaded = false;

	bool Processed = false;

	LanguageType CurrentLanguage = LanguageType::kUndefined;
	int HandleMultipleExt = 0;

	bool Tutorial = false;

    int RunX = 0;

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


// cache, then save when exit
struct StateOptions
{
	std::wstring LastScanPath = L"";

	std::wstring DataPath = L"";
};


class SettingsHandler
{
    HKEY hKey;

	Ini* __iniFile;

	std::wstring ExePath = L"";

	void SetupFormat();

    bool ClearFormDetails(int);

	bool Load();
	bool LoadCustomSettings();
	bool LoadLanguage();

	int LanguageToInt(LanguageType);

public:

	FormDetails FDMain;

	TFormatSettings XinorbisFormat;

	ChartOptions Chart;
	TabDisplayOptions TabDisplay[4];
	TabInternalOptions TabInternal;

	AppearanceSettings Appearance;
	CustomSettings Custom;
	DatabaseSettings Database;
	FolderHistorySettings FolderHistory;
	HistorySettings History;
	GeneralSettings General;
	OptimisationSettings Optimisations;
	NavigationOptions Navigation;
	ReportSettings Reports;
	SystemSettings System;
	FTPSettings FTP;
	StateOptions State;

	int ProgressPercentage = 10;
	int ProgressFileCount = 10000;

	std::wstring QuickFolders[kQuickFolderCount];

	int FileCategoryColors[kFileCategoriesCount]; // 0 is a hack for "folders"

	void ProcessProcessingSetting(ParameterOption);

	void SetDefaults();

	FormDetails LoadFormDetails(int);
	void SaveFormDetails(FormDetails &);

	bool SaveDefaults();

	SettingsHandler(const std::wstring);

    bool Save(int, int, int, int, const std::wstring);

	bool OpenSettings(bool);
	bool CloseSettings();

	std::wstring ReadString(const std::wstring, const std::wstring, std::wstring);
	int ReadInteger(const std::wstring, const std::wstring, int, int);
	int ReadIntegerInputCheck(const std::wstring, const std::wstring, int, int, int);
	bool ReadBool(const std::wstring, const std::wstring, bool);

	void WriteString(const std::wstring, const std::wstring, std::wstring);
	void WriteInteger(const std::wstring, const std::wstring, int);
	void WriteBool(const std::wstring, const std::wstring, bool);
};
