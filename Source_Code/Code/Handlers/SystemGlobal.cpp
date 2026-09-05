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

#include "FileExtensionHandler.h"
#include "ImageHandler.h"
#include "LanguageHandler.h"
#include "Log.h"
#include "ReportHandler.h"
#include "ScanEngine.h"
#include "ScanHistoryHandler.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

extern FileExtensionHandler *GFileExtensionHandler;
extern ImageHandler *GImageHandler;
extern LanguageHandler *GLanguageHandler;
extern Log *GLog;
extern ReportHandler *GReportHandler;
extern ScanEngine *GScanEngine;
extern ScanHistoryHandler *GScanHistoryHandler;
extern SettingsHandler *GSettingsHandler;

SystemGlobal *GSystemGlobal;


SystemGlobal::SystemGlobal()
{
	Init();

	CreateObjects();
}


SystemGlobal::~SystemGlobal()
{
}


void SystemGlobal::Init()
{
	ExePath = WindowsUtility::GetExePath();
//	AppDataPath = GetUsersPath(AppPath);
	AppDataPath = ExePath + L"Data\\";

	if (InstallationCheck(WindowsUtility::GetComputerNetName()))
	{
		Status = InitStatus::kSuccess;
	}
	else
	{
		Status = InitStatus::kInstallCheckFail;
	}
}


void SystemGlobal::CreateObjects()
{
	// load settings first!
	GSettingsHandler = new SettingsHandler(ExePath);

	GImageHandler = new ImageHandler(ExePath);

	//
	GFileExtensionHandler = new FileExtensionHandler(ExePath);

	GLanguageHandler = new LanguageHandler();
	GLanguageHandler->InitLanguage(ExePath, LanguageType::kUK);

	GScanHistoryHandler = new ScanHistoryHandler(ExePath + L"system\\");

	GScanEngine = new ScanEngine();

	GReportHandler = new ReportHandler();

    GLog = new Log();
}


void SystemGlobal::FreeObjects()
{
//
}


bool SystemGlobal::InstallationCheck(const std::wstring cname)
{
	auto CreateIfMissing = [](const std::wstring path) -> bool
	{
		if (!DirectoryExists(path.c_str()))
		{
			try
			{
				ForceDirectories(path.c_str());
			}
			catch(...)
			{
				return false;
			}
		}

		return true;
	};

  	CreateIfMissing(ExePath + L"Logs");

	CreateIfMissing(AppDataPath);

	CreateIfMissing(AppDataPath + L"Database");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname);

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\CSV\\autosaves");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\CSV\\quick");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Date\\autosaves");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Date\\quick");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\HTML\\data");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\HTML\\autosaves\\data");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\HTML\\quick\\data");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\HTML_Compare\\data");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\HTML_Compare\\autosaves\\data");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\HTML_Compare\\quick\\data");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\JSON\\autosaves");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\JSON\\quick");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Summary\\autosaves");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Summary\\quick");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Text\\autosaves");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Text\\quick");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Tree\\autosaves");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Tree\\quick");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Xinorbis\\autosaves");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\Xinorbis\\quick");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\XML\\autosaves");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\XML\\quick");

	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\XML_Compare\\autosaves");
	CreateIfMissing(AppDataPath + L"Reports\\" + cname + L"\\XML_Compare\\quick");

	CreateIfMissing(AppDataPath + L"Saves\\Custom Reports");

	return true;
}
