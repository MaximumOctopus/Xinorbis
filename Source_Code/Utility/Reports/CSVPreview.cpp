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

#include "ConstantsReports.h"
#include "Convert.h"
#include "CSVPreview.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportCSVOptions.h"

extern LanguageHandler* GLanguageHandler;


void CSVPreview::Get(CSVReportOptions csvro, std::vector<std::wstring> &output)
{
	std::wstring separator = L",";

	switch (csvro.Separator)
	{
	case kCSVSeparatorComma:
		separator = L",";
		break;
	case kCSVSeparatorTab:
		separator = L"\t";
		break;
	case kCSVSeparatorPling:
		separator = L"|";
		break;
	}

	switch (csvro.Data)
	{
	case kDataSummary:
		if (csvro.Titles)
		{
			output.push_back(L"\"" + GLanguageHandler->Text[kCategory]         + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kQuantity]         + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kQuantity]         + L" " + GLanguageHandler->Text[kAsPercent] + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kSize]             + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kSizeOfFilesBytes] + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kSize] + L" " + GLanguageHandler->Text[kAsPercent] + L"\"");
		}

		for (int t = 0; t < __FileCategoriesCount; t++)
		{
			std::wstring s = L"\"" + GLanguageHandler->TypeDescriptions[t] + L"\"" + separator;

			s += L"1234" + separator;

			s += L"\"100%\"" + separator;

			switch (csvro.Units)
			{
			case kCSVUnitsConvenient:
				s += L"\"120.51 KB\"" + separator;
				break;
			case kCSVUnitsBytes:
				s += L"\"123412\"" + GLanguageHandler->Text[kBytes] + L"\"" + separator;
				break;
			case kCSVUnitsKilobytes:
				s += L"\"120.51 KB\"" + separator;
				break;
			case kCSVUnitsMegabytes:
				s += L"\"0.12 MB\"" + separator;
				break;
			}

			s += L"\"123412\"" + separator;

			s += L"\"100\"";

			output.push_back(s);
		}
		break;
	case kDataFileList:
		if (csvro.Titles)
		{
			output.push_back(L"\"" + GLanguageHandler->Text[kFileName]                                  + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kFilePath]                                  + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kSize]                                      + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kSizeOfFilesBytes]                          + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kSizeOnDisk]                                + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kCreatedDate]                               + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kAccessedDate]                              + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kModifiedDate]                              + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kCreatedDate] + L" (" + GLanguageHandler->Text[kTime] + L")"  + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kAccessedDate] + L" (" + GLanguageHandler->Text[kTime] + L")" + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kModifiedDate] + L" (" + GLanguageHandler->Text[kTime] + L")" + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kCategory]                                  + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kCategory] + L" ID"                          + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kOwner]                                     + L"\"" + separator +
							 L"\"" + GLanguageHandler->LanguageTypes[__FileType_ReadOnly]                   + L"\"" + separator +
							 L"\"" + GLanguageHandler->LanguageTypes[__FileType_Hidden]                     + L"\"" + separator +
							 L"\"" + GLanguageHandler->LanguageTypes[__FileType_System]                     + L"\"" + separator +
							 L"\"" + GLanguageHandler->LanguageTypes[__FileType_Archive]                    + L"\"" + separator +
							 L"\"" + GLanguageHandler->Text[kTemporary] + L"\"");
		}

		for (int t = 0; t < 16; t++)
		{
			std::wstring s = L"";

			if (t % 2)
			{
				s = L"\"" + Formatting::Privacy(L"CSV Folder" + std::to_wstring(t)) + L"\"" + separator;
				s += L"\"" + Formatting::Privacy(L"c:\\preview\\temp\\CSV Filename" + std::to_wstring(t)) + L"\""+  separator;

				s += GLanguageHandler->Text[kFolder] + separator;
				s += L"-1" + separator;
				s += L"-1" + separator;

				s += Convert::IntDateToString(19750417) + separator;
				s += Convert::IntDateToString(18710830) + separator;
				s += Convert::IntDateToString(19231215) + separator;

				s += std::to_wstring(19750417) + separator;
				s += std::to_wstring(18710830) + separator;
				s += std::to_wstring(19231215) + separator;

				s += GLanguageHandler->Text[kFolder] + separator;

				s += L"\"99\"" + separator;

				s += Formatting::Privacy(L"\"Rutherford\"") + separator;

				s += L"1" + separator;
				s += L"0" + separator;
				s += L"0" + separator;
				s += L"1" + separator;
				s += L"0";
			}
			else
			{
				s = L"\"" + Formatting::Privacy(L"CSV File Name" + std::to_wstring(t)) + L"\"" + separator;
				s += L"\"" + Formatting::Privacy(L"c:\\preview\\temp\\CSV File name" + std::to_wstring(t)) + L"\""+  separator;

				switch (csvro.Units)
				{
				case kCSVUnitsConvenient:
					s += L"\"196.98 KB\"" + separator;
					break;
				case kCSVUnitsBytes:
					s += L"\"201705 " + GLanguageHandler->Text[kBytes] + L"\"" + separator;
					break;
				case kCSVUnitsKilobytes:
					s += L"\"196.98 KB\"" + separator;
					break;
				case kCSVUnitsMegabytes:
					s += L"\"0.19 MB\"" + separator;
					break;
				}

				s += L"\"" + std::to_wstring(201705) + L"\"" + separator;
				s += L"\"" + std::to_wstring(201705) + L"\"" + separator;

				s += Convert::IntDateToString(19750417) + separator;
				s += Convert::IntDateToString(18710830) + separator;
				s += Convert::IntDateToString(19231215) + separator;

				s += std::to_wstring(19750417) + separator;
				s += std::to_wstring(18710830) + separator;
				s += std::to_wstring(19231215) + separator;

				s += L"\"" + GLanguageHandler->TypeDescriptions[t] + L"\"" + separator;

				s += std::to_wstring(t) + separator;

				s += Formatting::Privacy(L"\"Freeman\"") + separator;

				s += L"1" + separator;
				s += L"1" + separator;
				s += L"0" + separator;
				s += L"0" + separator;
				s += L"1";
			}

			output.push_back(s);
		}
	}
}

