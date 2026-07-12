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

#include <ctime>
#include <string>

#include "DateUtility.h"
#include "LanguageHandler.h"

extern LanguageHandler* GLanguageHandler;


namespace DateUtility
{
	std::wstring CurrentYear()
	{
		time_t now = time(nullptr);

		tm *ltm = localtime(&now);

		return std::to_wstring(ltm->tm_year + 1900);
	}


	int CurrentYearI()
	{
		time_t now = time(nullptr);

		tm *ltm = localtime(&now);

		return (ltm->tm_year + 1900);
	}


	std::wstring GetDate(DateTimeFormat date_format)
	{
		time_t now = time(nullptr);

		tm *ltm = localtime(&now);

		wchar_t buffer[10];

		switch (date_format)
		{
		case DateTimeFormat::Display:
			return GLanguageHandler->Months[ltm->tm_mon] + L" " + std::to_wstring(ltm->tm_mday) + L" " + std::to_wstring(ltm->tm_year + 1900);

		case DateTimeFormat::File:

			wcsftime(buffer, 10, L"%d%m%Y", ltm);

			return buffer;

		case DateTimeFormat::YYYYMMDD:

			wcsftime(buffer, 10, L"%Y%m%d", ltm);

			return buffer;

		case DateTimeFormat::Slash:

			wcsftime(buffer, 10, L"%Y/%m/%d", ltm);

			return buffer;

		default:
			return L"?";
		}
	}


	std::wstring GetTime(DateTimeFormat time_format)
	{
		time_t now = time(nullptr);

		tm *ltm = localtime(&now);

		wchar_t buffer[10];

		switch (time_format)
		{
		case DateTimeFormat::Display:
			wcsftime(buffer, 10, L"%H:%M.%S", localtime(&now));

			return buffer;

		case DateTimeFormat::File:
			wcsftime(buffer, 10, L"%H%M%S", localtime(&now));

			return buffer;

		case DateTimeFormat::Slash:
			wcsftime(buffer, 10, L"%H:%M.%S", localtime(&now));

			return buffer;

		case DateTimeFormat::HHMM:

			wcsftime(buffer, 10, L"%H:%M", localtime(&now));

			return buffer;

		default:
			return L"?";
		}
	}


	int TodayAsInteger()
	{
		time_t now = time(nullptr);

		tm *ltm = localtime(&now);

		return ((ltm->tm_year + 1900) * 10000) + ((ltm->tm_mon + 1) * 100) + ltm->tm_mday;
	}


	std::wstring DateTime(int mode)
	{
		time_t now = time(0);

		tm *ltm = localtime(&now);

		std::wstring year  = std::to_wstring(ltm->tm_year + 1900);
		std::wstring month = std::to_wstring(ltm->tm_mon + 1);
		std::wstring day   = std::to_wstring(ltm->tm_mday);
		std::wstring hour  = std::to_wstring(ltm->tm_hour);
		std::wstring min   = std::to_wstring(ltm->tm_min);
		std::wstring sec   = std::to_wstring(ltm->tm_sec);

		if (ltm->tm_mon + 1 < 10)
		{
			month = L"0" + month;
		}

		if (ltm->tm_mday < 10)
		{
			month = L"0" + month;
		}

		if (ltm->tm_hour < 10)
		{
			hour = L"0" + hour;
		}

		if (ltm->tm_min < 10)
		{
			min = L"0" + min;
		}

		if (ltm->tm_sec < 10)
		{
			sec = L"0" + sec;
		}

		if (mode == 0)
		{
			return year + L"/" + month + L"/" + day + L" " + hour + L":" + min + L"." + sec;
		}
		else
		{
			return year + month + day + hour + min + sec;
		}
	}


	std::wstring DateToString(TDateTime dt, DateFormat df)
	{
		unsigned short yy = 0;
		unsigned short mm = 0;
		unsigned short dd = 0;

		dt.DecodeDate(&yy, &mm, &dd);

		std::wstring yyyy = std::to_wstring(yy);
		std::wstring mmmm = L"";
		std::wstring dddd = L"";

		if (mm < 10)
		{
			mmmm = L"0" + std::to_wstring(mm);
		}
		else
		{
			mmmm = std::to_wstring(mm);
		}

		if (dd < 10)
		{
			dddd = L"0" + std::to_wstring(dd);
		}
		else
		{
			dddd = std::to_wstring(dd);
		}

		switch (df)
		{
		case DateFormat::kSlashDDMMYYYY:
			return dddd + L"//" + mmmm + L"//" + yyyy;   // dd/mm/yyyy
		case DateFormat::kSlashMMDDYYYY:
			return mmmm + L"//" + dddd + L"//" + yyyy;   // mm/dd/yyyy
		case DateFormat::kSlashYYYYMMDD:
			return yyyy + L"//" + mmmm + L"//" + dddd;   // yyyy/mm/dd
		case DateFormat::kHyphenDDMMYYYY:
			return dddd + L"-" + mmmm + L"-" + yyyy;   // dd-mm-yyyy
		case DateFormat::kHyphenMMDDYYYY:
			return mmmm + L"-" + dddd + L"-" + yyyy;   // mm-dd-yyyy
		}

		return dddd + L"//" + mmmm + L"//" + yyyy;   // dd/mm/yyyy
	}


	TDateTime YYYYMMDDToDate(int date)
	{
		std::wstring s = std::wstring(s);

		try
		{
			return EncodeDate(stoi(s.substr(0, 4)), stoi(s.substr(4, 2)), stoi(s.substr(6, 2)));
		}
		catch(...)
		{
		}

		return EncodeDate(1990, 1, 1);
	}
}
