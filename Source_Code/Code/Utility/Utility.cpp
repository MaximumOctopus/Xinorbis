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

#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>

#include "ConstantsData.h"
#include "Convert.h"
#include "LanguageHandler.h"
#include "MD5.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"


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


	std::wstring GetMD5(const std::wstring input)
	{
		std::string str(input.begin(), input.end());

		std::transform(str.begin(), str.end(), str.begin(), ::toupper);

		char *y = new char[str.length() + 1];

		std::strcpy(y, str.c_str());

		std::wstring MD5 = MD5::GetMD5HashString(y);

		delete[] y;

		return MD5.substr(0, MD5.size() - 2); // removes weird \n from end of string ?!
	}


	std::wstring GetFileExtension(const std::wstring& file_name)
	{
		size_t index = file_name.rfind(L".");

		if (index != std::wstring::npos)
		{
			std::wstring ext = file_name.substr(index + 1);

			std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

			return ext;
		}

		return L"";
	}


	std::wstring LastFolder(const std::wstring& input)
	{
		std::wstring output = L"";

		if (input.size() > 0)
		{
			if (input.back() == L'\\')
			{
				int t = input.size() - 2;

				while (t >= 0 && input[t] != L'\\')
				{
					output = input[t] + output;

					t--;
				}
			}
			else
			{
				int t = input.size() - 1;

				while (t >= 0 && input[t] != L'\\')
				{
					output = input[t] + output;

					t--;
				}
			}
		}

		return output;
	}


	std::wstring ProcessFileName(const std::wstring& file_name)
	{
		if (file_name.find(L"$") != std::wstring::npos)
		{
			std::wstring pfn = file_name;

			time_t now = time(nullptr);

			tm *ltm = localtime(&now);

			int mm = ltm->tm_mon + 1;
			int dd = ltm->tm_mday;

			// =========================================================================
			// == Folder { processed ===============================================
			// =========================================================================

			if (file_name.find(L"$XD") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$XD", GSystemGlobal->ExePath[1] + L":");
			}

			if (file_name.find(L"$XF") != std::wstring::npos)
			{
				std::wstring path = GSystemGlobal->ExePath.substr(0, GSystemGlobal->ExePath.length() - 1);

				pfn = ReplaceString(pfn, L"$XF", path);
			}

			// =========================================================================
			// == System ===============================================================
			// =========================================================================

			if (file_name.find(L"$PC") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$PC", WindowsUtility::GetComputerNetName());
			}

			if (file_name.find(L"$User") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$User", WindowsUtility::GetUserFromWindows());
			}

			// =========================================================================
			// == Date =================================================================
			// =========================================================================

			if (file_name.find(L"$yyyy") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$yyyy", std::to_wstring(ltm->tm_year + 1900));
			}

			if (file_name.find(L"$YY") != std::wstring::npos)
			{ 
				std::wstring yy = std::to_wstring(ltm->tm_year + 1900);

				pfn = ReplaceString(pfn, L"$YY", yy.substr(2, 2));
			}

			// =========================================================================

			if (file_name.find(L"$mm") != std::wstring::npos)
			{
				std::wstring mmm = std::to_wstring(mm);

				if (mm < 10)
				{
					mmm = L"0" + mmm;
				}
			
				pfn = ReplaceString(pfn, L"$mm", mmm);
			}

			if (file_name.find(L"$MM") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$MM", GLanguageHandler->Months[mm]);
			}

			// =========================================================================

			if (file_name.find(L"$dd") != std::wstring::npos)
			{
				std::wstring ddd = std::to_wstring(dd);

				if (dd < 10)
				{
					ddd = L"0" + ddd;
				}
				
				pfn = ReplaceString(pfn, L"$dd", ddd);
			}

			if (file_name.find(L"$DD") != std::wstring::npos)
			{
				pfn = ReplaceString(pfn, L"$DD", GLanguageHandler->ShortDays[ltm->tm_wday]);
			}

			// =========================================================================
			// == Time =================================================================
			// =========================================================================

			if (file_name.find(L"$Th") != std::wstring::npos)
			{
				std::wstring hhh = std::to_wstring(ltm->tm_hour);

				if (ltm->tm_hour < 10)
				{
					hhh = L"0" + hhh;
				}

				pfn = ReplaceString(pfn, L"$Th", hhh);
			}

			// =========================================================================

			if (file_name.find(L"Tm") != std::wstring::npos)
			{
				std::wstring mmm = std::to_wstring(ltm->tm_min);
			
				if (ltm->tm_min < 10)
				{
					mmm = L"0" + mmm;
				}

				pfn = ReplaceString(pfn, L"$Tm", mmm);
			}

			// =========================================================================

			if (file_name.find(L"Ts") != std::wstring::npos)
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

		return file_name;
	}


	std::wstring ReplaceString(const std::wstring subject, const std::wstring& search, const std::wstring& replace)
	{
		std::wstring output = subject;

		size_t pos = 0;

		while ((pos = output.find(search, pos)) != std::wstring::npos)
		{
			output.replace(pos, search.length(), replace);

			pos += replace.length();
		}

		return output;
	}


    std::wstring SplitFilename(const std::wstring &str)
    {
		size_t found;

        found = str.rfind(L"\\");

		return str.substr(0, found);
	}


	std::wstring GetDefaultFileName(const std::wstring extension, const std::wstring prefix)
	{
		std::wstring file_name = prefix + L"_" + std::to_wstring(Convert::DateToYYYYMMDDI(Now())) + L"_" + Convert::TimeToString(Now(), false) + extension;

		return Convert::ToReportFileName(file_name);
	}


	std::wstring BoolToString(bool input)
	{
		if (input)
		{
			return L"1";
		}
		else
		{
			return L"0";
		}
	}


	bool StringToBool(wchar_t input)
	{
		if (input == L'0')
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	int OptionToInt(wchar_t input)
	{
		switch (input)
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


	bool IsTestCharacter(wchar_t value)
	{
		switch (value)
		{
		case L'>':
		case L'=':
		case L'<':
		case L'!':
		case L'~':
			return true;
		}

		return false;
	}


	bool IsNumber(const std::wstring input)
	{
		for (wchar_t c : input)
		{
			if (!isdigit(c))
			{
				return false;
            }
		}

		return true;
	}


	std::wstring WebFileLink(const std::wstring input)
	{
		std::wstring wfl = input;

		std::replace(wfl.begin(), wfl.end(), ':', '|');
		std::replace(wfl.begin(), wfl.end(), '\\', '/');

		return L"file:///" + wfl;
	}
}