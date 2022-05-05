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


#include "Constants.h"
#include "LanguageHandler.h"
#include "MD5.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>


extern LanguageHandler* GLanguageHandler;
extern SystemGlobal* GSystemGlobal;


namespace Utility
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



	std::wstring GetDate(int aDateFormat)
	{
		time_t now = time(nullptr);

		tm *ltm = localtime(&now);

		wchar_t buffer[10];

		switch (aDateFormat)
		{
		case __GETTIMEFORMAT_DISPLAY:
			return GLanguageHandler->Months[ltm->tm_mon] + L" " + std::to_wstring(ltm->tm_mday) + L" " + std::to_wstring(ltm->tm_year + 1900);

		case __GETTIMEFORMAT_FILE:

			wcsftime(buffer, 10, L"%d%m%Y", ltm);

			return buffer;

		case __GETTIMEFORMAT_YYYYMMDD:

			wcsftime(buffer, 10, L"%Y%m%d", ltm);

			return buffer;

		case __GETTIMEFORMAT_SLASH:

			wcsftime(buffer, 10, L"%Y/%m/%d", ltm);

			return buffer;

		default:
			return L"?";
		}
	}


	std::wstring GetTime(int aTimeFormat)
	{
		time_t now = time(nullptr);

		tm *ltm = localtime(&now);

		wchar_t buffer[10];

		switch (aTimeFormat)
		{
		case __GETTIMEFORMAT_DISPLAY:
			wcsftime(buffer, 10, L"%H:%M.%S", localtime(&now));

			return buffer;

		case __GETTIMEFORMAT_FILE:
			wcsftime(buffer, 10, L"%H%M%S", localtime(&now));

			return buffer;

		case __GETTIMEFORMAT_SLASH:
			wcsftime(buffer, 10, L"%H:%M.%S", localtime(&now));

			return buffer;

		case __GETTIMEFORMAT_HHMM:

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


	std::wstring DateTime(int aMode)
	{
		time_t now = time(0);

		tm *ltm = localtime(&now);

		std::wstring year  = std::to_wstring(ltm->tm_year + 1900);
		std::wstring month = std::to_wstring(ltm->tm_mon + 1);
		std::wstring day   = std::to_wstring(ltm->tm_mday);
		std::wstring hour  = std::to_wstring(ltm->tm_hour);
		std::wstring min   = std::to_wstring(ltm->tm_min);
		std::wstring sec   = std::to_wstring(ltm->tm_sec);

		if (ltm->tm_mon < 10)
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

		if (aMode == 0)
		{
			return year + L"/" + month + L"/" + day + L" " + hour + L":" + min + L":" + sec;
		}
		else
		{
			return year + month + day + hour + min + sec;
		}
	}


	std::wstring Utility::GetMD5(std::wstring input)
	{
		std::string str(input.begin(), input.end());

		std::transform(str.begin(), str.end(), str.begin(), ::toupper);

		char *y = new char[str.length() + 1];

		std::strcpy(y, str.c_str());

		std::wstring MD5 = MD5::GetMD5HashString(y);

		delete[] y;

		return MD5.substr(0, MD5.size() - 2); // removes weird \n from end of string ?!
	}


	std::wstring GetFileExtension(const std::wstring &FileName)
	{
		size_t index = FileName.find_last_of(L".");

		if (index != std::wstring::npos)
		{
			std::wstring ext = FileName.substr(index + 1);

			std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

			return ext;
		}
		else
		{
			return L"";
		}
	}


	std::wstring ProcessFileName(const std::wstring &FileName)
	{
		if (FileName.find(L"$") != std::wstring::npos)
		{
			std::wstring pfn = FileName;

			time_t now = time(nullptr);

			tm *ltm = localtime(&now);

			int mm = ltm->tm_mon + 1;
			int dd = ltm->tm_mday;

			// =========================================================================
			// == Folder { processed ===============================================
			// =========================================================================

			if (FileName.find(L"$XD") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$XD", GSystemGlobal->AppPath[1] + L":");
			}

			if (FileName.find(L"$XF") != std::wstring::npos)
			{

				std::wstring path = GSystemGlobal->AppPath.substr(0, GSystemGlobal->AppPath.length() - 1);

				pfn = ReplaceString(pfn, L"$XF", path);
			}

			// =========================================================================
			// == System ===============================================================
			// =========================================================================

			if (FileName.find(L"$PC") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$PC", WindowsUtility::GetComputerNetName());
			}

			if (FileName.find(L"$User") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$User", WindowsUtility::GetUserFromWindows());
			}

			// =========================================================================
			// == Date =================================================================
			// =========================================================================

			if (FileName.find(L"$yyyy") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$yyyy", std::to_wstring(ltm->tm_year + 1900));
			}

			if (FileName.find(L"$YY") != std::wstring::npos)
			{ 
				std::wstring yy = std::to_wstring(ltm->tm_year + 1900);

				pfn = ReplaceString(pfn, L"$YY", yy.substr(2, 2));
			}

			// =========================================================================

			if (FileName.find(L"$mm") != std::wstring::npos)
			{
				std::wstring mmm = std::to_wstring(mm);

				if (mm < 10)
				{
					mmm = L"0" + mmm;
				}
			
				pfn = ReplaceString(pfn, L"$mm", mmm);
			}

			if (FileName.find(L"$MM") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$MM", GLanguageHandler->Months[mm]);
			}

			// =========================================================================

			if (FileName.find(L"$dd") != std::wstring::npos)
			{
				std::wstring ddd = std::to_wstring(dd);

				if (dd < 10)
				{
					ddd = L"0" + ddd;
				}
				
				pfn = ReplaceString(pfn, L"$dd", ddd);
			}

			if (FileName.find(L"$DD") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$DD", GLanguageHandler->ShortDays[ltm->tm_wday]);
			}

			// =========================================================================
			// == Time =================================================================
			// =========================================================================

			if (FileName.find(L"$Th") != std::wstring::npos)
			{
				std::wstring hhh = std::to_wstring(ltm->tm_hour);

				if (ltm->tm_hour < 10)
				{
					hhh = L"0" + hhh;
				}

				pfn = ReplaceString(pfn, L"$Th", hhh);
			}

			// =========================================================================

			if (FileName.find(L"Tm") != std::wstring::npos)
			{
				std::wstring mmm = std::to_wstring(ltm->tm_min);
			
				if (ltm->tm_min < 10)
				{
					mmm = L"0" + mmm;
				}

				pfn = ReplaceString(pfn, L"$Tm", mmm);
			}

			// =========================================================================

			if (FileName.find(L"Ts") != std::wstring::npos)
			{
				std::wstring sss = std::to_wstring(ltm->tm_sec);

				if (ltm->tm_sec < 10)
				{
					sss = L"0" + sss;
				}
			
				pfn = ReplaceString(pfn, L"$Ts", sss);
			}

			// =========================================================================

			return pfn;
		}

		return FileName;
	}


	std::wstring ReplaceString(std::wstring subject, const std::wstring& search, const std::wstring& replace)
	{
		size_t pos = 0;

		while ((pos = subject.find(search, pos)) != std::wstring::npos)
		{
			subject.replace(pos, search.length(), replace);

			pos += replace.length();
		}

		return subject;
	}


    std::wstring SplitFilename(const std::wstring &str)
    {
        size_t found;

        found = str.find_last_of(L"/\\");

        return str.substr(0, found);
    }


	std::wstring BoolToString(bool aInput)
	{
		if (aInput)
		{
			return L"1";
		}
		else
		{
			return L"0";
		}
	}


	bool StringToBool(wchar_t aInput)
	{
		if (aInput == L'0')
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	int OptionToInt(wchar_t aInput)
	{
		switch (aInput)
		{
		case L'0':
			return 0;
		case L'1':
			return 1;
		case L'2':
			return 2;
		case L'3':
			return 3;

		default:
			return 0;
		}
	}


	std::wstring WebFileLink(std::wstring &str)
	{
		std::replace(str.begin(), str.end(), ':', '|');
		std::replace(str.begin(), str.end(), '\\', '/');

		return L"file:///" + str;
	}
}