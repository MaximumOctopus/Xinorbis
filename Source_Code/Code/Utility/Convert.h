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
#include <Windows.h>

enum class UnitConversion { kUnitKB = 0, kUnitMB, kUnitGB, kUnitTB };

namespace Convert
{
	[[nodiscard]] std::wstring AttributeToIntAsString(int, int);
	[[nodiscard]] std::wstring ConvertToUsefulUnit(unsigned __int64);
    [[nodiscard]] std::wstring ConvertToStaticUnit(unsigned __int64, UnitConversion);
	[[nodiscard]] unsigned __int64 ConvertUsefulUnitToInteger(const std::wstring);
	[[nodiscard]] std::wstring DoubleToPercent(double);
	[[nodiscard]] std::wstring GetSizeString(int, unsigned __int64);

	[[nodiscard]] std::wstring BoolToString(bool);

	[[nodiscard]] int FileTimeToDateInt(FILETIME*);
	[[nodiscard]] int FileTimeToTimeInt(FILETIME*);
	[[nodiscard]] std::wstring IntDateToString(int);
	[[nodiscard]] std::wstring IntToHex(int, int);
	[[nodiscard]] int DateToYYYYMMDD(const std::wstring);
	[[nodiscard]] int DateToYYYYMMDDI(TDateTime);
	[[nodiscard]] int TodayPlusDaysToYYYYMMDD(int days);

	[[nodiscard]] int DateFromAnyFormatToYYYYMMDD(const std::wstring);
	[[nodiscard]] int TimeFromAnyFormatToHHMM(const std::wstring);

	[[nodiscard]] std::wstring TimeToString(TDateTime, bool);

	[[nodiscard]] std::wstring YYYYMMDDToMonthDayYear(int);
	[[nodiscard]] std::wstring YYYYMMDDToMonthYear(int);
	[[nodiscard]] std::wstring YYYYMMDDToMonth(int);

	[[nodiscard]] std::wstring WebColour(int);

	[[nodiscard]] int StrToIntDef(std::wstring, int);

	[[nodiscard]] std::wstring ToReportFileName(const std::wstring);
};