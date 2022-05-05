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


#pragma once


#include <string>
#include <vector>


class LanguageHandler
{
private:

	int currentLanguage;

    bool LoadLanguage(std::wstring fileName);

	void SetReportText();
	void SetXDates();

    std::wstring GetLanguageSymbol(int languageIndex);

public:
	std::wstring ShortDays[7] = { L"Sun", L"Mon", L"Tue", L"Wed", L"Thu", L"Fri", L"Sat" };

	bool LanguageLoadOK;
	
	std::vector<std::wstring> XText;
	std::vector<std::wstring> XDates;

	std::wstring Months[12];
	std::wstring ShortMonths[12];
	std::wstring TypeDescriptions[20];

	std::wstring LanguageTypes[13];

	std::wstring TextReport[19];
	std::wstring SummaryReport[15];
	std::wstring DriveReport[11];
	std::wstring GenericReportItems[17];
	std::wstring OtherReportItems[9];

	std::wstring GetLanguageSymbol(void);

    LanguageHandler(std::wstring folder, int languageIndex);
};