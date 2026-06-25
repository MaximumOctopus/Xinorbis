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

#include <string>

#include "ConstantsData.h"

static const int kDisplayModeConsole = 0;
static const int kDisplayModeFile = 1;


namespace DateUtility
{
	std::wstring CurrentYear();
	int CurrentYearI();

	std::wstring GetDate(DateTimeFormat);
	std::wstring GetTime(DateTimeFormat);

	int TodayAsInteger();

	std::wstring DateTime(int);
}
