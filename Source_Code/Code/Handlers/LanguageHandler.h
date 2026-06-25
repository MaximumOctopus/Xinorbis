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
#include <vector>

#include "ConstantsData.h"
#include "ConstantsLanguage.h"


class LanguageHandler
{
	bool LoadLanguage(const std::wstring);
	bool LoadUnits(const std::wstring);

	void InitReportText();
	void InitXDates();

	std::wstring GetLanguageSymbol(LanguageType);
    std::wstring GetLanguageSymbol(void);

public:

	std::vector<std::wstring> Text;
	std::vector<std::wstring> Dates;
	std::vector<std::wstring> Units;

	LanguageType CurrentLanguage = LanguageType::kUndefined;

	std::wstring ShortDays[7] = { L"Sun", L"Mon", L"Tue", L"Wed", L"Thu", L"Fri", L"Sat" };
	std::wstring Months[12];
	std::wstring ShortMonths[12];
	std::wstring TypeDescriptions[20];
	std::wstring TypeDescriptionsSmall[20];

	std::wstring LanguageTabs[12];
	std::wstring LanguageTypes[kAttributesTotalCount];

	std::wstring TextReport[19];
	std::wstring SummaryReport[15];
	std::wstring DriveReport[11];
	std::wstring GenericReportItems[18];
	std::wstring OtherReportItems[9];

	std::wstring MagniLabels[kMagnitudesCount] = { L"<=1$K", L"1$K < x <=1$M", L"1$M < x <=10$M", L"10$M < x <=50$M", L"50$M < x <=100$M", L"100$M < x <=150$M",
												   L"150$M < x <=200$M", L"200$M < x <=250$M", L"250$M < x <=500$M", L"500$M < x <=1$G", L"1$G < x <=2$G",
												   L"2$G < x <=5$G", L">5$G" };

	std::wstring MagniLabels2[kMagnitudesCount] = { L"<=1$K", L"$K<=1$M", L"1$M<=10$M", L"10$M<=50$M", L"50$M<=100$M", L"100$M<=150$M",
													L"150$M<=200$M", L"200$M<=250$M", L"250$M<=500$M", L"500$M<=1$G", L"1$G<=2$G",
													L"2$G<=5$G", L">5$G" };

	std::wstring MagniLabels3[kMagnitudesCount] = { L"<= 1$K", L"1$K - 1$M", L"1$M - 10$M", L"10$M - 50$M", L"50$M - 100$M",
													L"100$M - 150$M", L"150$M - 200$M", L"200$M - 250$M", L"250$M - 500$M", L"500$M - 1$G",
													L"1$G - 2$G", L"2$G - 5$G", L"5$G+L" };

	LanguageHandler();

	bool InitLanguage(const std::wstring, LanguageType);

	std::wstring UpperCaseText(int);
	std::wstring UpperCaseUnit(int);
    std::wstring FormatForScreen(const std::wstring);
};