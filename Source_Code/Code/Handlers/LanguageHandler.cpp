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

#include <fstream>

#include "ConstantsLanguage.h"
#include "LanguageHandler.h"

LanguageHandler *GLanguageHandler;


LanguageHandler::LanguageHandler()
{

}


bool LanguageHandler::InitLanguage(const std::wstring folder, LanguageType language_type)
{
	CurrentLanguage = language_type;

	std::wstring fileName = folder + L"system\\languages\\" + GetLanguageSymbol(language_type) + L"\\language.txt";

	if (LoadLanguage(fileName))
	{
		InitReportText();
		InitXDates();

		if (LoadUnits(folder + L"system\\languages\\" + GetLanguageSymbol(language_type) + L"\\units.txt"))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}


bool LanguageHandler::LoadLanguage(const std::wstring file_name)
{
	std::wifstream file(file_name);

	if (file)
	{
		Text.clear();

		std::wstring s;

		while (std::getline(file, s))
		{
			Text.push_back(s);
		}

		file.close();

		// ======================================================================

		if (Text.size() != kLanguageConstantsCount)
		{
			//std::wcout << "Check your language files are up-to-date. They appear to have an incorrect number of entries! (" << rsLanguageConstantsCount << " vs " << Text.size()  << ")\n" << file_name << "\n" << "<install>\\system\\languages\\ \n";

		   //	for (int t = Text.size(); t < rsLanguageConstantsCount + 1; t++)
			//{
			//	Text.push_back(L"missing #" + std::to_wstring(Text.size()));
			//}

			//return false;
		}

		// ======================================================================

		return true;
	}

	return false;
}


bool LanguageHandler::LoadUnits(const std::wstring file_name)
{
	std::wifstream file(file_name);

	if (file)
	{
		std::wstring s;

		while (std::getline(file, s))
		{
			Units.push_back(s);
		}

		file.close();

		return true;
	}

	return false;
}


void LanguageHandler::InitReportText()
{
	Months[0] = Text[kJanuary]; Months[1]  = Text[kFebruary];  Months[2]  = Text[kMarch];
	Months[3] = Text[kApril];   Months[4]  = Text[kMay];       Months[5]  = Text[kJune];
	Months[6] = Text[kJuly];    Months[7]  = Text[kAugust];    Months[8]  = Text[kSeptember];
	Months[9] = Text[kOctober]; Months[10] = Text[kNovember];  Months[11] = Text[kDecember];

	ShortMonths[0] = Text[kJan];  ShortMonths[1] = Text[kFeb];  ShortMonths[2] = Text[kMar];
	ShortMonths[3] = Text[kApr];  ShortMonths[4] = Text[kMxy];  ShortMonths[5] = Text[kJun];
	ShortMonths[6] = Text[kJul];  ShortMonths[7] = Text[kAug];  ShortMonths[8] = Text[kSep];
	ShortMonths[9] = Text[kOct];  ShortMonths[10] = Text[kNov];  ShortMonths[11] = Text[kDec];

	TypeDescriptions[0]  = Text[kTemporary];  TypeDescriptions[1]  = Text[kPrograms];
	TypeDescriptions[2]  = Text[kSystem];     TypeDescriptions[3]  = Text[kGraphics];
	TypeDescriptions[4]  = Text[kMovie];      TypeDescriptions[5]  = Text[kAudio];
	TypeDescriptions[6]  = Text[kOffice];     TypeDescriptions[7]  = Text[kProgramming];
	TypeDescriptions[8]  = Text[kCompressed]; TypeDescriptions[9]  = Text[kUncategorised];
	TypeDescriptions[10] = Text[kCustom1];    TypeDescriptions[11] = Text[kCustom2];
	TypeDescriptions[12] = Text[kCustom3];    TypeDescriptions[13] = Text[kCustom4];
	TypeDescriptions[14] = Text[kCustom5];    TypeDescriptions[15] = Text[kCustom6];
	TypeDescriptions[16] = Text[kCustom7];    TypeDescriptions[17] = Text[kCustom8];
	TypeDescriptions[18] = Text[kCustom9];    TypeDescriptions[19] = Text[kCustom10];

	TypeDescriptionsSmall[0]  = Text[kTMP];   TypeDescriptionsSmall[1]  = Text[kEXE];
	TypeDescriptionsSmall[2]  = Text[kSYS];   TypeDescriptionsSmall[3]  = Text[kGFX];
	TypeDescriptionsSmall[4]  = Text[kMOV];   TypeDescriptionsSmall[5]  = Text[kSFX];
	TypeDescriptionsSmall[6]  = Text[kOFF];   TypeDescriptionsSmall[7]  = Text[kPRG];
	TypeDescriptionsSmall[8]  = Text[kZIP];   TypeDescriptionsSmall[9]  = Text[kUncat];
	TypeDescriptionsSmall[10] = Text[kC1];    TypeDescriptionsSmall[11] = Text[kC2];
	TypeDescriptionsSmall[12] = Text[kC3];    TypeDescriptionsSmall[13] = Text[kC4];
	TypeDescriptionsSmall[14] = Text[kC5];    TypeDescriptionsSmall[15] = Text[kC6];
	TypeDescriptionsSmall[16] = Text[kC7];    TypeDescriptionsSmall[17] = Text[kC8];
	TypeDescriptionsSmall[18] = Text[kC9];    TypeDescriptionsSmall[19] = Text[kC10];

	TextReport[0]  = Text[kTextReport1];
	TextReport[1]  = Text[kTextReport2];
	TextReport[2]  = Text[kTextReport3];
	TextReport[3]  = Text[kTextReport4];
	TextReport[4]  = Text[kTextReport5];
	TextReport[5]  = Text[kTextReport6];
	TextReport[6]  = Text[kTextReport7];
	TextReport[7]  = Text[kTextReport8];
	TextReport[8]  = Text[kTextReport9];
	TextReport[9]  = Text[kTextReport10];
	TextReport[10] = Text[kTextReport11];
	TextReport[11] = Text[kTextReport12];
	TextReport[12] = Text[kTextReport13];
	TextReport[13] = Text[kTextReport14];
	TextReport[14] = Text[kTextReport15];
	TextReport[15] = Text[kTextReport16];
	TextReport[16] = Text[kTextReport17];
	TextReport[17] = Text[kTextReport18];
	TextReport[18] = Text[kTextReport19];

	LanguageTypes[0]  = Text[kNull] + L" " + Text[kFolders];
	LanguageTypes[1]  = Text[kHidden];
	LanguageTypes[2]  = Text[kSystem];
	LanguageTypes[3]  = Text[kArchive];
	LanguageTypes[4]  = Text[kNullFiles];
	LanguageTypes[5]  = Text[kReadOnly];
	LanguageTypes[6]  = Text[kCompressed];
	LanguageTypes[7]  = Text[kEncrypted];
	LanguageTypes[8]  = L"Recall on Open";
	LanguageTypes[9]  = L"Recall on Data Access";
	LanguageTypes[10] = Text[kOffline];
	LanguageTypes[11] = Text[kCreatedToday];
	LanguageTypes[12] = Text[kAccessedToday];
	LanguageTypes[13] = Text[kModifiedToday];

	LanguageTypes[14] = Text[kTemporary];
	LanguageTypes[15] = Text[kFolder];
	LanguageTypes[16] = Text[kFile];
	LanguageTypes[17] = L"No extension";
	LanguageTypes[18] = Text[kSparseFile];
	LanguageTypes[19] = Text[kReparseFile];
	LanguageTypes[20] = Text[kNotContentIndexed];

	GenericReportItems[0]  = Text[kHTMLReport1];
	GenericReportItems[1]  = Text[kHTMLReport2];
	GenericReportItems[2]  = Text[kHTMLReport3];
	GenericReportItems[3]  = Text[kHTMLReport4];
	GenericReportItems[4]  = Text[kHTMLReport5];
	GenericReportItems[5]  = Text[kHTMLReport6];
	GenericReportItems[6]  = Text[kHTMLReport7];
	GenericReportItems[7]  = Text[kHTMLReport8];
	GenericReportItems[8]  = Text[kHTMLReport9];
	GenericReportItems[9]  = Text[kHTMLReport10];
	GenericReportItems[10] = Text[kHTMLReport11];
	GenericReportItems[11] = Text[kHTMLReport12];
	GenericReportItems[12] = Text[kHTMLReport13];
	GenericReportItems[13] = Text[kHTMLReport14];
	GenericReportItems[14] = Text[kHTMLReport15];
	GenericReportItems[15] = Text[kHTMLReport16];
	GenericReportItems[16] = Text[kHTMLReport17];
	GenericReportItems[17] = Text[kFileNameLength];

	SummaryReport[0]  = Text[kSummReport1]  + L" ";
	SummaryReport[1]  = Text[kSummReport2]  + L" ";
	SummaryReport[2]  = Text[kSummReport3]  + L" ";
	SummaryReport[3]  = Text[kSummReport4]  + L" ";
	SummaryReport[4]  = Text[kSummReport5]  + L" ";
	SummaryReport[5]  = Text[kSummReport6]  + L" ";
	SummaryReport[6]  = Text[kSummReport7]  + L" ";
	SummaryReport[7]  = Text[kSummReport8]  + L" ";
	SummaryReport[8]  = Text[kSummReport9]  + L" ";
	SummaryReport[9]  = Text[kSummReport10] + L" ";
	SummaryReport[10] = Text[kSummReport11] + L" ";
	SummaryReport[11] = Text[kSummReport12] + L" ";
	SummaryReport[12] = Text[kSummReport13] + L" ";
	SummaryReport[13] = Text[kSummReport14] + L" ";
	SummaryReport[14] = Text[kSummReport15] + L" ";

	DriveReport[0]  = Text[kDriveReport1]  + L" ";
	DriveReport[1]  = Text[kDriveReport2]  + L" ";
	DriveReport[2]  = Text[kDriveReport3]  + L" ";
	DriveReport[3]  = Text[kDriveReport4]  + L" ";
	DriveReport[4]  = Text[kDriveReport5]  + L" ";
	DriveReport[5]  = Text[kDriveReport6]  + L" ";
	DriveReport[6]  = Text[kDriveReport7]  + L" ";
	DriveReport[7]  = Text[kDriveReport8]  + L" ";
	DriveReport[8]  = Text[kDriveReport9]  + L" ";
	DriveReport[9]  = Text[kDriveReport10] + L" ";
	DriveReport[10] = Text[kDriveReport11] + L" ";
}


void LanguageHandler::InitXDates()
{
	// rsDateDD
	Dates.push_back(Text[kDay].substr(0, 1) + Text[kDay].substr(0, 1));

	// rsDateMM
	Dates.push_back(Text[kMonth].substr(0, 1) + Text[kMonth].substr(0, 1));

	// rsDateYYYY
	Dates.push_back(Text[kYear].substr(0, 1) + Text[kYear].substr(0, 1) + Text[kYear].substr(0, 1) + Text[kYear].substr(0, 1));
}


std::wstring LanguageHandler::GetLanguageSymbol(LanguageType language_type)
{
    switch (language_type)
    {
		case LanguageType::kUK:
			return L"uk";
		case LanguageType::kNL:
			return L"nl";
		case LanguageType::kFR:
			return L"fr";
		case LanguageType::kDE:
			return L"de";
		case LanguageType::kIT:
			return L"it";
		case LanguageType::kPT:
			return L"pt";
		case LanguageType::kES:
			return L"es";
		case LanguageType::kSW:
			return L"sw";
		case LanguageType::kCZ:
			return L"cz";
		case LanguageType::kHU:
			return L"hu";
		case LanguageType::kUS:
			return L"us";
		case LanguageType::kRU:
			return L"ru";
		case LanguageType::kCAT:
			return L"cat";

		default:
			return L"uk";
	}
}


std::wstring LanguageHandler::GetLanguageSymbol(void)
{
	switch (CurrentLanguage)
	{
	case LanguageType::kUK:
		return L"English (UK)";
	case LanguageType::kNL:
		return L"Dutch";
	case LanguageType::kFR:
		return L"French";
	case LanguageType::kDE:
		return L"German";
	case LanguageType::kIT:
		return L"Italian";
	case LanguageType::kPT:
		return L"Portugese";
	case LanguageType::kES:
		return L"Spanish";
	case LanguageType::kSW:
		return L"Swedish";
	case LanguageType::kCZ:
		return L"Czech";
	case LanguageType::kHU:
		return L"Hungarian";
	case LanguageType::kUS:
		return L"English (US)";
	case LanguageType::kRU:
		return L"Russian";
	case LanguageType::kCAT:
		return L"lolcat";

	default:
		return L"Undefined";
	}
}


std::wstring LanguageHandler::UpperCaseText(int reference)
{
	std::wstring input = Text[reference];

	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	return input;
}


std::wstring LanguageHandler::UpperCaseUnit(int reference)
{
	std::wstring input = Units[reference];

	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	return input;
}


std::wstring LanguageHandler::FormatForScreen(const std::wstring s)
{
	std::wstring output = s;

//	output = s.replace()(s,      ':', ' ', [rfReplaceAll]);
//	 Result := StringReplace(Result, '\', ' ', [rfReplaceAll]);

//	Result := Trim(Result); TO DO
	return s;
}
