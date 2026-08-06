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

#include "DateUtility.h"
#include "Log.h"

Log *GLog;


void Log::Add(const std::wstring output)
{
	LogData.push_back(DateUtility::DateTime(kDisplayModeConsole) + L"  " + output);
}


void Log::AddError(const std::wstring output)
{
	LogData.push_back(DateUtility::DateTime(kDisplayModeConsole) + L" X " + output);
}
