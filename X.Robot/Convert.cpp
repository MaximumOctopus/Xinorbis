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
#include "Convert.h"
#include "LanguageHandler.h"
#include "Settings.h"
#include <string>
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <sstream>


extern LanguageHandler* GLanguageHandler;
extern Settings* GSettings;


namespace Convert
{
	std::wstring AttributeToIntAsString(int aAttributeData, int aAttributeValue)
	{
		if (aAttributeData & aAttributeValue)
		{
			return L"1";
		}
		else
		{
			return L"0";
		}
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


	std::wstring ConvertToUsefulUnit(unsigned __int64 aValue)
	{
		if (aValue < 0)
		{	
			return L"0";
		}
		else if ((aValue >= 0) && (aValue < 1024))
		{
			return std::to_wstring(aValue) + L" " + GLanguageHandler->XText[rsBytes];
		}
		else if (aValue < 1048576)
		{
			double lSize = (double)aValue / (double)1024;

			std::wstring s(7, '\0');
			int i = swprintf(&s[0], L"%.2f", lSize);
			s.resize(i);

			return s + L" KB";
		}
		else if (aValue < 1073741824)
		{
			double lSize = (double)aValue / (double)1048576;

			std::wstring s(7, '\0');
			int i = swprintf(&s[0], L"%.2f", lSize);
			s.resize(i);

			return s + L" MB";
		}
		else if (aValue < 1099511627776)
		{
			double lSize = (double)aValue / (double)1073741824;
				
			std::wstring s(7, '\0');
			int i = swprintf(&s[0], L"%.2f", lSize);
			s.resize(i);

			return s + L" GB";
		}
		else
		{
			double lSize = (double)aValue / (double)1099511627776;

			std::wstring s(7, '\0');
			int i = swprintf(&s[0], L"%.2f", lSize);
			s.resize(i);

			return s + L" TB";
		}
	}


	std::wstring DoubleToPercent(double aValue)
	{
		if (aValue != 0)
		{
			if (aValue < 0.001)
			{
				return L"<0.1%";
			}
			else if (aValue < 0.01)
			{
				return L"<1%";
			}

			if ((aValue * 100 == 100) && (aValue < 1.0))
			{
				return L">99%";
			}

			std::wstring s(100, '\0');
			int i = swprintf(&s[0], L"%.0f", aValue * 100);
			s.resize(i);

			return s + L"%";
		}
		else
		{
			return L"0%";
		}
	}


	int FileTimeToDateInt(FILETIME* lFileTime)
	{
		if ((lFileTime->dwLowDateTime != 0) && (lFileTime->dwHighDateTime != 0))
		{
			SYSTEMTIME lpSystemTime;

			FileTimeToSystemTime(lFileTime, &lpSystemTime);

			int lDate = 0;

			lDate += lpSystemTime.wDay;

			lDate += lpSystemTime.wMonth * 100;

			lDate += lpSystemTime.wYear * 10000;

			return lDate;
		}
		else
		{
			return 19000101;
		}
	}


	int FileTimeToTimeInt(FILETIME* lFileTime)
	{
		if ((lFileTime->dwLowDateTime != 0) && (lFileTime->dwHighDateTime != 0))
		{
			SYSTEMTIME lpSystemTime;

			FileTimeToSystemTime(lFileTime, &lpSystemTime);

			int lTime = 0;

			lTime += lpSystemTime.wMinute;

			lTime += lpSystemTime.wHour * 100;

			return lTime;
		}
		else
		{
			return 1200;
		}
	}


	std::wstring GetSizeString(int aUnits, unsigned long long aSize)
	{
		switch (aUnits)
		{
			case 0:
				return ConvertToUsefulUnit(aSize);
			case 1:
				return std::to_wstring(aSize);
			case 2:
			{
				std::wstring s(9, ' ');
				int i = swprintf(&s[0], L"%.2f", double(aSize / 1024));
				s.resize(i);

				return s + L"KB";
			}
			case 3:
			{
				std::wstring s(9, ' ');
				int i = swprintf(&s[0], L"%.2f", double(aSize / (1024 * 1024)));
				s.resize(i);

				return s + L"MB";
			}
			case 4:
			{
				std::wstring s(9, ' ');
				int i = swprintf(&s[0], L"%.2f", double(aSize / (1024 * 1024 * 1024)));
				s.resize(i);

				return s + L"GB";
			}
			
			default:
				return ConvertToUsefulUnit(aSize);
		}
	}


	std::wstring IntDateToString(int dx)
	{
		std::wstring xd    = std::to_wstring(dx);

		std::wstring day   = xd.substr(6, 2);
		std::wstring month = xd.substr(4, 2);
		std::wstring year  = xd.substr(0, 4);

		switch (GSettings->General.DateFormat)
		{
			case 0:
				return day + L"/" + month + L"/" + year;   // dd/mm/yyyy
				break;
			case 1:
				return month + L"/" + day + L"/" + year;   // mm/dd/yyyy
				break;
			case 2:
				return year + L"/" + month + L"/" + day;   // yyyy/mm/dd
				break;
			case 3:
				return day + L"-" + month + L"-" + year;   // dd-mm-yyyy
				break;
			case 4:
				return month + L"-" + day + L"-" + year;   // mm-dd-yyyy
				break;
		}

		return L"17/04/1975";
	}


	std::wstring IntToHex(int aValue, int aSize)
	{
		std::wstringstream stream;

		stream << std::setfill(L'0') << std::setw(aSize) << std::hex << aValue;

		return stream.str();
	}


	int StrToIntDef(std::wstring input, int default)
	{
		std::wstring::size_type sz;   // alias of size_t

		try
		{
			int i = std::stoi(input, &sz);

			return i;
		}
		catch (...)
		{
			return default;
		}
	}

	// RGB -> BGR
	std::wstring WebColour(int aColour)
	{
		std::wstring red   = IntToHex((aColour & 0xFF0000) >> 16, 2);
		std::wstring green = IntToHex((aColour & 0x00FF00) >> 8, 2);
		std::wstring blue  = IntToHex((aColour & 0x0000FF), 2);

		return blue + green + red;
	}
};