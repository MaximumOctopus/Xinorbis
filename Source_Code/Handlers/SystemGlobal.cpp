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
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

extern FileExtensionHandler* GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SettingsHandler* GSettingsHandler;

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
	//AppDataPath = GetUsersPath(AppPath);

	//if (InstallationCheck())
//	{
//		Status = InitStatus::Success;
//	}
//	else      TO DO
//	{
//		Status = InitStatus::InstallationCheckFailed;
//	}
}


void SystemGlobal::CreateObjects()
{
	// load settings first!
	GSettingsHandler = new SettingsHandler();

	//
	GFileExtensionHandler = new FileExtensionHandler(ExePath);

	GLanguageHandler = new LanguageHandler();
	GLanguageHandler->InitLanguage(ExePath, LanguageType::kUK);

	GScanEngine = new ScanEngine();
}
