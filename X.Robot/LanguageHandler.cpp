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
// June 4th 2020
//


#include "Constants.h"
#include "LanguageHandler.h"
#include "WindowsUtility.h"
#include <codecvt>
#include <fstream>
#include <locale>
#include <string>

#include <iostream>


LanguageHandler* GLanguageHandler;


LanguageHandler::LanguageHandler(std::wstring aFolder, int languageIndex)
{
	currentLanguage = languageIndex;

    std::wstring fileName = aFolder + L"data\\languages\\" + GetLanguageSymbol(languageIndex) + L"\\language.txt";

	if (LoadLanguage(fileName))
	{
		SetReportText();
		SetXDates();

		LanguageLoadOK = true;
	}
	else
	{
		LanguageLoadOK = false;
	}
}


bool LanguageHandler::LoadLanguage(std::wstring fileName)
{
	if (WindowsUtility::FileExists(fileName))
	{
		std::wifstream file(fileName);

		file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

		if (file)
		{
			std::wstring s;

			while (std::getline(file, s))
			{
				XText.push_back(s);
			}

			file.close();

			return true;
		}
	}
	else
	{
		std::wcout << L"Language file missing: " << std::endl << fileName << std::endl;
	}

    return false;
}


void LanguageHandler::SetReportText()
{
	Months[0] = XText[rsJanuary]; Months[1]  = XText[rsFebruary];  Months[2]  = XText[rsMarch];
	Months[3] = XText[rsApril];   Months[4]  = XText[rsMay];       Months[5]  = XText[rsJune];
	Months[6] = XText[rsJuly];    Months[7]  = XText[rsAugust];    Months[8]  = XText[rsSeptember];
	Months[9] = XText[rsOctober]; Months[10] = XText[rsNovember];  Months[11] = XText[rsDecember];

	ShortMonths[0] = XText[rsJan]; ShortMonths[1]  = XText[rsFeb];  ShortMonths[2]  = XText[rsMar];
	ShortMonths[3] = XText[rsApr]; ShortMonths[4]  = XText[rsMxy];  ShortMonths[5]  = XText[rsJun];
	ShortMonths[6] = XText[rsJul]; ShortMonths[7]  = XText[rsAug];  ShortMonths[8]  = XText[rsSep];
	ShortMonths[9] = XText[rsOct]; ShortMonths[10] = XText[rsNov];  ShortMonths[11] = XText[rsDec];

	TypeDescriptions[0]  = XText[rsTemporary];  TypeDescriptions[1]  = XText[rsPrograms];
	TypeDescriptions[2]  = XText[rsSystem];     TypeDescriptions[3]  = XText[rsGraphics];
	TypeDescriptions[4]  = XText[rsMovie];      TypeDescriptions[5]  = XText[rsAudio];
	TypeDescriptions[6]  = XText[rsOffice];     TypeDescriptions[7]  = XText[rsProgramming];
	TypeDescriptions[8]  = XText[rsCompressed]; TypeDescriptions[9]  = XText[rsUncategorised];
	TypeDescriptions[10] = XText[rsCustom1];    TypeDescriptions[11] = XText[rsCustom2];
	TypeDescriptions[12] = XText[rsCustom3];    TypeDescriptions[13] = XText[rsCustom4];
	TypeDescriptions[14] = XText[rsCustom5];    TypeDescriptions[15] = XText[rsCustom6];
	TypeDescriptions[16] = XText[rsCustom7];    TypeDescriptions[17] = XText[rsCustom8];
	TypeDescriptions[18] = XText[rsCustom9];    TypeDescriptions[19] = XText[rsCustom10];

	TextReport[0]  = XText[rsTextReport1];
	TextReport[1]  = XText[rsTextReport2];
	TextReport[2]  = XText[rsTextReport3];
	TextReport[3]  = XText[rsTextReport4];
	TextReport[4]  = XText[rsTextReport5];
	TextReport[5]  = XText[rsTextReport6];
	TextReport[6]  = XText[rsTextReport7];
	TextReport[7]  = XText[rsTextReport8];
	TextReport[8]  = XText[rsTextReport9];
	TextReport[9]  = XText[rsTextReport10];
	TextReport[10] = XText[rsTextReport11];
	TextReport[11] = XText[rsTextReport12];
	TextReport[12] = XText[rsTextReport13];
	TextReport[13] = XText[rsTextReport14];
	TextReport[14] = XText[rsTextReport15];
	TextReport[15] = XText[rsTextReport16];
	TextReport[16] = XText[rsTextReport17];
	TextReport[17] = XText[rsTextReport18];
	TextReport[18] = XText[rsTextReport19];

	LanguageTypes[0] = XText[rsHidden];
	LanguageTypes[1] = XText[rsSystem];
	LanguageTypes[2] = XText[rsArchive];
	LanguageTypes[3] = XText[rsNull];
	LanguageTypes[4] = XText[rsReadOnly];
	LanguageTypes[5] = XText[rsCompressed];
	LanguageTypes[6] = XText[rsEncrypted];
	LanguageTypes[7] = L"Recall on Open";
	LanguageTypes[8] = L"Recall on Data Access";
	LanguageTypes[9] = XText[rsOffline];
	LanguageTypes[10] = XText[rsCreatedToday];
	LanguageTypes[11] = XText[rsAccessedToday];
	LanguageTypes[12] = XText[rsModifiedToday];

	GenericReportItems[0]  = XText[rsHTMLReport1];
	GenericReportItems[1]  = XText[rsHTMLReport2];
	GenericReportItems[2]  = XText[rsHTMLReport3];
	GenericReportItems[3]  = XText[rsHTMLReport4];
	GenericReportItems[4]  = XText[rsHTMLReport5];
	GenericReportItems[5]  = XText[rsHTMLReport6];
	GenericReportItems[6]  = XText[rsHTMLReport7];
	GenericReportItems[7]  = XText[rsHTMLReport8];
	GenericReportItems[8]  = XText[rsHTMLReport9];
	GenericReportItems[9]  = XText[rsHTMLReport10];
	GenericReportItems[10] = XText[rsHTMLReport11];
	GenericReportItems[11] = XText[rsHTMLReport12];
	GenericReportItems[12] = XText[rsHTMLReport13];
	GenericReportItems[13] = XText[rsHTMLReport14];
	GenericReportItems[14] = XText[rsHTMLReport15];
	GenericReportItems[15] = XText[rsHTMLReport16];
	GenericReportItems[16] = XText[rsHTMLReport17];

	SummaryReport[0]  = XText[rsSummReport1];
	SummaryReport[1]  = XText[rsSummReport2];
	SummaryReport[2]  = XText[rsSummReport3];
	SummaryReport[3]  = XText[rsSummReport4];
	SummaryReport[4]  = XText[rsSummReport5];
	SummaryReport[5]  = XText[rsSummReport6];
	SummaryReport[6]  = XText[rsSummReport7];
	SummaryReport[7]  = XText[rsSummReport8];
	SummaryReport[8]  = XText[rsSummReport9];
	SummaryReport[9]  = XText[rsSummReport10];
	SummaryReport[10] = XText[rsSummReport11];
	SummaryReport[11] = XText[rsSummReport12];
	SummaryReport[12] = XText[rsSummReport13];
	SummaryReport[13] = XText[rsSummReport14];
	SummaryReport[14] = XText[rsSummReport15];

	DriveReport[0]  = XText[rsDriveReport1];
	DriveReport[1]  = XText[rsDriveReport2];
	DriveReport[2]  = XText[rsDriveReport3];
	DriveReport[3]  = XText[rsDriveReport4];
	DriveReport[4]  = XText[rsDriveReport5];
	DriveReport[5]  = XText[rsDriveReport6];
	DriveReport[6]  = XText[rsDriveReport7];
	DriveReport[7]  = XText[rsDriveReport8];
	DriveReport[8]  = XText[rsDriveReport9];
	DriveReport[9]  = XText[rsDriveReport10];
	DriveReport[10] = XText[rsDriveReport11];
}


void LanguageHandler::SetXDates()
{
	// rsDateDD
	XDates.push_back(XText[rsDay].substr(0) + XText[rsDay].substr(0));

	// rsDateMM
	XDates.push_back(XText[rsMonth].substr(0) + XText[rsMonth].substr(0));

	// rsDateYYYY
	XDates.push_back(XText[rsYear].substr(0) + XText[rsYear].substr(0) + XText[rsYear].substr(0) + XText[rsYear].substr(0));
}


std::wstring LanguageHandler::GetLanguageSymbol(int languageIndex)
{
    switch (languageIndex)
    {
        case __LanguageUK:
            return L"uk";
        case __LanguageNL:
            return L"nl";
        case __LanguageFR:
            return L"fr";
        case __LanguageDE:
            return L"de";
        case __LanguageIT:
            return L"it";
        case __LanguagePT:
            return L"pt";
        case __LanguageES:
            return L"es";
        case __LanguageSW:
            return L"sw";
        case __LanguageCZ:
            return L"cz";
        case __LanguageHU:
            return L"hu";
        case __LanguageUS:
            return L"us";
        case __LanguageRU:
            return L"ru";
        case __LanguageCAT:
            return L"cat";

        default:
            return L"uk";
    }
}


std::wstring LanguageHandler::GetLanguageSymbol(void)
{
	switch (currentLanguage)
	{
	case 0:
		return L"English (UK)";
	case 1:
		return L"Dutch";
	case 2:
		return L"French";
	case 3:
		return L"German";
	case 4:
		return L"Italian";
	case 5:
		return L"Portugese";
	case 6:
		return L"Spanish";
	case 7:
		return L"Swedish";
	case 8:
		return L"Czech";
	case 9:
		return L"Hungarian";
	case 10:
		return L"English (US)";
	case 11:
		return L"Russian";
	case 12:
		return L"lolcat";
	
	default:
		return L"Undefined";
	}
}