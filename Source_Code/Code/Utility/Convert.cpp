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
#include <string>
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "ConstantsData.h"
#include "Convert.h"
#include "LanguageHandler.h"
#include "SettingsHandler.h"
#include "Utility.h"


extern LanguageHandler* GLanguageHandler;
extern SettingsHandler* GSettingsHandler;


namespace Convert
{
	std::wstring AttributeToIntAsString(int attribute_data, int attribute_value)
	{
		if (attribute_data & attribute_value)
		{
			return L"1";
		}
		else
		{
			return L"0";
		}
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


	std::wstring ConvertToUsefulUnit(unsigned __int64 value)
	{
		if (value < 0)
		{	
			return L"0 " + GLanguageHandler->Text[kBytes];
		}
		else if (value < 1024)
		{
			return std::to_wstring(value) + L" " + GLanguageHandler->Text[kBytes];
		}
		else if (value < 1048576)
		{
			double size = (double)value / (double)1024;

			return L"TO DO";//std::format(L"{0:.2f}KB", size);
		}
		else if (value < 1073741824)
		{
			double size = (double)value / (double)1048576;

			return L"TO DO";//std::format(L"{0:.2f}MB", size);
		}
		else if (value < 1099511627776)
		{
			double size = (double)value / (double)1073741824;

			return L"TO DO";//std::format(L"{0:.2f}GB", size);
		}
		else
		{
			double size = (double)value / (double)1099511627776;

			return L"TO DO";//std::format(L"{0:.2f}TB", size);
		}
	}


	unsigned __int64 ConvertUsefulUnitToInteger(const std::wstring input)
	{
		int output = 0;

		std::wstring value = L"0";
		std::wstring unit = L"";

		for (int t = 0; t < input.length(); t++)
		{
			if (input[t] != L' ')
			{
				if (isalpha(input[t]))
				{
					unit += toupper(input[t]);
				}
				else
				{
					value += input[t];
				}
			}
		}

		if (value.find(GSettingsHandler->General.DecimalSeparator) != std::wstring::npos)  // handle non integer values differently
		{
			if (unit == GLanguageHandler->UpperCaseText(kBytes))
			{
				output = static_cast<int>(std::stod(value));
			}
			else if (unit == L"K" || unit == L"KB" || unit == GLanguageHandler->UpperCaseUnit(kUnitKB))
			{
				output = static_cast<int>(std::stod(value)) * 1024;
			}
			else if (unit == L"M" || unit == L"MB" || unit == GLanguageHandler->UpperCaseUnit(kUnitMB))
			{
				output = static_cast<int>(std::stod(value)) * 1024 * 1024;
			}
			else if (unit == L"G" || unit == L"GB" || unit == GLanguageHandler->UpperCaseUnit(kUnitGB))
			{
				output = static_cast<int>(std::stod(value)) * 1024 * 1024 * 1024;
			}
			else
			{
				output = static_cast<int>(std::stod(value));
			}
		}
		else
		{
			if (unit == GLanguageHandler->UpperCaseText(kBytes))
			{
				output = stoi(value);
			}
			else if (unit == L"K" || unit == L"KB" || unit == GLanguageHandler->UpperCaseUnit(kUnitKB))
			{
				output = stoi(value) * 1024;
			}
			else if (unit == L"M" || unit == L"MB" || unit == GLanguageHandler->UpperCaseUnit(kUnitMB))
			{
				output = stoi(value) * 1024 * 1024;
			}
			else if (unit == L"G" || unit == L"GB" || unit == GLanguageHandler->UpperCaseUnit(kUnitGB))
			{
				output = stoi(value) * 1024 * 1024 * 1024;
			}
			else
			{
				output = stoi(value);
			}
		}

		return output;
	}


	int DateFromAnyFormatToYYYYMMDD(std::wstring input)
	{
		int output = 0;
		bool hastext = false;
		std::wstring value = L"";

		if (input.find(L"!") == 0)                // !x where x is number of days
		{
			int t = 0;

			try
			{
				t = stoi(input.substr(1));
			}
			catch (...)
			{
				
			}

			output = Convert::TodayPlusDaysToYYYYMMDD(-t);
		}
		else if (input.find(L"$") == 0)           // $x where x is number of months
		{
			int t = 0;

			try
			{
				t = stoi(input.substr(1));
			}
			catch (...)
			{

			}

			output = Convert::TodayPlusDaysToYYYYMMDD(-(t * 30)); // -months
		}
		else
		{
			hastext = false;
		}

		input = Utility::ReplaceString(input, L"\\", L"*");
		input = Utility::ReplaceString(input, L"/", L"*");
		
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);

		for (int t = 0; t < input.length(); t++)
		{
			if (isalpha(input[t]))
			{
				hastext = true;
			}
		}

		// if the user has entered the month as text the replace the text with
		// the correct ordinal month value
		if (hastext)
		{
			std::wstring smup = L"";

			for (int t = 0; t < 12; t++)
			{
				smup = GLanguageHandler->ShortMonths[t];

				std::transform(smup.begin(), smup.end(), smup.begin(), ::toupper);

				if (input.find(smup) != std::wstring::npos)
				{
					if (t < 10)
					{
						value = L'0' + std::to_wstring(t);
					}
					else
					{
						value = std::to_wstring(t);
					}

					input = Utility::ReplaceString(input, smup, value);
				}
			}
		}

		// ===========================================================================

		if (input.find(L"*") == 2)             // dd/mm/yyyy
		{
			if (false) // to do XSettings.General.DateFormat = CDateFormatSlashMMDDYYYY)  // assume the user is entering in mm/dd/yyyy
			{
				std::wstring mmddyyyy = input.substr(6, 4) + input.substr(0, 2) + input.substr(3, 2);

				try
				{
					output = stoi(mmddyyyy);
				}
				catch (...)
				{
					output = 19900101;
				}
			}
			else
			{
				output = Convert::DateToYYYYMMDD(input);
			}
		}
		else if (input.find(L"*") == 4)        // yyyy/mm/dd
		{
			std::wstring yyyymmdd = input.substr(0, 4) + input.substr(5, 2) + input.substr(8, 2);

			try
			{
				output = stoi(yyyymmdd);
			}
			catch(...)
			{
				output = 19900101;
			}
		}
		else
		{
			try
			{
				output = stoi(input);
			}
			catch (...)
			{
				output = 19900101;
			}
		}

		return output;
	}


	// input is in format dd/mm/yyyy
	int DateToYYYYMMDD(const std::wstring input)
	{
		if (input.length() == 10)
		{
			int d = stoi(input.substr(0, 2));
			int m = stoi(input.substr(3, 2));
			int y = stoi(input.substr(5, 4));			
			
			return (y * 10000) + (m * 100) + d;
		}

		return 19900101;
	}


	// +/- day count
	int TodayPlusDaysToYYYYMMDD(int days)
	{
		time_t now = time(nullptr) + (days * 24 * 60 * 60);

		tm* ltm = localtime(&now);

		wchar_t buffer[10];

		wcsftime(buffer, 10, L"%Y%m%d", ltm);

		std::wstring output(buffer);

		return stoi(output);
	}


	std::wstring DoubleToPercent(double value)
	{
		if (value != 0)
		{
			if (value < 0.001)
			{
				return L"<0.1%";
			}
			else if (value < 0.01)
			{
				return L"<1%";
			}

			if ((value * 100 == 100) && (value < 1.0))
			{
				return L">99%";
			}
		
			return L"to do";//std::format(L"{0:.2f}%", value * 100);
		}

		return L"0%";
	}


	int FileTimeToDateInt(FILETIME* file_time)
	{
		if ((file_time->dwLowDateTime != 0) && (file_time->dwHighDateTime != 0))
		{
			SYSTEMTIME lpSystemTime;

			FileTimeToSystemTime(file_time, &lpSystemTime);

			int date = lpSystemTime.wDay;

			date += lpSystemTime.wMonth * 100;

			date += lpSystemTime.wYear * 10000;

			return date;
		}
	
		return 19000101;
	}


	int FileTimeToTimeInt(FILETIME* file_time)
	{
		if ((file_time->dwLowDateTime != 0) && (file_time->dwHighDateTime != 0))
		{
			SYSTEMTIME lpSystemTime;

			FileTimeToSystemTime(file_time, &lpSystemTime);

			int time = lpSystemTime.wMinute;

			time += lpSystemTime.wHour * 100;

			return time;
		}

		return 1200;
	}


	std::wstring GetSizeString(int units, unsigned __int64 size)
	{
		switch (units)
		{
			case 0:
				return ConvertToUsefulUnit(size);
			case 1:
				return std::to_wstring(size);
			case 2:
				return L"to do";//std::format(L"{0:.2f}KB", (double)size / 1024);
			case 3:
				return L"to do";//std::format(L"{0:.2f}MB", (double)size / 1048576);
			case 4:
				return L"to do";//std::format(L"{0:.2f}GB", (double)size / 1073741824);
			
			default:
				return ConvertToUsefulUnit(size);
		}
	}


	std::wstring IntDateToString(int dx)
	{
		std::wstring xd    = std::to_wstring(dx);

		std::wstring day   = xd.substr(6, 2);
		std::wstring month = xd.substr(4, 2);
		std::wstring year  = xd.substr(0, 4);

		switch (GSettingsHandler->General.DateFormat)
		{
			case 0:
				return day + L"/" + month + L"/" + year;   // dd/mm/yyyy
			case 1:
				return month + L"/" + day + L"/" + year;   // mm/dd/yyyy
			case 2:
				return year + L"/" + month + L"/" + day;   // yyyy/mm/dd
			case 3:
				return day + L"-" + month + L"-" + year;   // dd-mm-yyyy
			case 4:
				return month + L"-" + day + L"-" + year;   // mm-dd-yyyy
		}

		return L"01/01/1990";
	}


	std::wstring IntToHex(int value, int size)
	{
		std::wstringstream stream;

		stream << std::setfill(L'0') << std::setw(size) << std::hex << value;

		return stream.str();
	}


	int StrToIntDef(std::wstring input, int default_value)
	{
		std::wstring::size_type sz;   // alias of size_t

		try
		{
			int i = std::stoi(input, &sz);

			return i;
		}
		catch (...)
		{
			return default_value;
		}
	}


	int TimeFromAnyFormatToHHMM(const std::wstring input)
	{
		try
		{
			int output = stoi(input);

			return output;
		}
		catch (...)
		{

		}
		
		return 1200;
	}

	std::wstring YYYYMMDDToMonthDayYear(int date)
	{
		std::wstring yyyymmdd = std::to_wstring(date);

		int mm = std::stoi(yyyymmdd.substr(4, 2));
		
		return GLanguageHandler->Months[mm - 1] + L" " + yyyymmdd.substr(6, 2) + L" " + yyyymmdd.substr(0, 4);
	}

	std::wstring YYYYMMDDToMonthYear(int date)
	{
		std::wstring yyyymmdd = std::to_wstring(date);

		int mm = std::stoi(yyyymmdd.substr(4, 2));
		
		return GLanguageHandler->Months[mm - 1] + L" " + yyyymmdd.substr(0, 4);
	}

	std::wstring YYYYMMDDToMonth(int date)
	{
		std::wstring yyyymmdd = std::to_wstring(date);

		return yyyymmdd.substr(0, 4);
	}

	// RGB -> BGR
	std::wstring WebColour(int colour)
	{
		std::wstring red   = IntToHex((colour & 0xFF0000) >> 16, 2);
		std::wstring green = IntToHex((colour & 0x00FF00) >> 8, 2);
		std::wstring blue  = IntToHex((colour & 0x0000FF), 2);

		return blue + green + red;
	}
};