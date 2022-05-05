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
#include "ReportCSV.h"
#include "ReportCSVReportOptions.h"
#include "ScanDetails.h"
#include <algorithm>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <string>


extern LanguageHandler* GLanguageHandler;
extern ScanDetails* GScanDetails;


namespace ReportCSV
{
	void Summary(CSVReportOptions options)
	{
		std::wcout << GLanguageHandler->XText[rsSavingReports] + L" (CSV): " << std::endl << std::endl;

		std::wofstream ofile(options.Filename);

		ofile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

		if (ofile)
		{
			std::wstring separator = L",";

			if (options.Separator == 1)
			{
				// set to tab
			}

			if (options.Titles)
			{
				ofile << GLanguageHandler->XText[rsCategory] + separator +
						 GLanguageHandler->XText[rsQuantity] + separator +
						 GLanguageHandler->XText[rsQuantity] + separator + GLanguageHandler->XText[rsAsPercent] + separator +
						 GLanguageHandler->XText[rsSize] + separator +
						 GLanguageHandler->XText[rsSizeOfFilesBytes] + separator +
						 GLanguageHandler->XText[rsSize] + GLanguageHandler->XText[rsAsPercent] << std::endl;
			}

			std::wstring lOutput;

			// ignore 0 (that's a hack for something I can't remember as I write this)
			for (int t = 1; t < __FileCategoriesCount; t++)
			{
				lOutput = GLanguageHandler->TypeDescriptions[t] + separator +

						  std::to_wstring(GScanDetails->ExtensionSpread[t][0]) + separator +

						  std::to_wstring(std::round(((double)GScanDetails->ExtensionSpread[t][0] / (double)GScanDetails->FileCount) * 100)) + L"\"" + separator +

						  Convert::GetSizeString(options.Units, GScanDetails->ExtensionSpread[t][__esSize]) + L"\"" + separator +

						  std::to_wstring(GScanDetails->ExtensionSpread[t][__esSize]) + L"\"" + separator;

				if (GScanDetails->TotalSize != 0)
				{
					lOutput += L"\"" + std::to_wstring(std::round(((double)GScanDetails->ExtensionSpread[t][__esSize] / (double)GScanDetails->TotalSize) * 100)) + L"\"";
				}
				else
				{
					lOutput += L"\"100\"";
				}
			
				ofile << lOutput << std::endl;
			}

			ofile.close();
		}
	}


	void FullList(CSVReportOptions options)
	{
		std::wcout << GLanguageHandler->XText[rsSavingReports] + L" (CSV): " << std::endl;
		std::wcout << L"    " << options.Filename << std::endl << std::endl;

		std::wofstream ofile(options.Filename);

		ofile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

		if (ofile)
		{
			std::wstring separator = L",";

			if (options.Separator == 1)
			{
				// set to tab
			}

			if (options.Titles)
			{
				std::wstring s =	GLanguageHandler->XText[rsFileName] + separator +
									GLanguageHandler->XText[rsFilePath] + separator +
									GLanguageHandler->XText[rsSize] + separator +
									GLanguageHandler->XText[rsSizeOfFilesBytes] + separator +
									GLanguageHandler->XText[rsSizeOnDisk] + separator +
									GLanguageHandler->XText[rsCreatedDate] + separator +
									GLanguageHandler->XText[rsAccessedDate] + separator +
									GLanguageHandler->XText[rsModifiedDate] + separator +
									GLanguageHandler->XText[rsCreatedDate] + L" (" + GLanguageHandler->XText[rsTime] + L")" + separator +
									GLanguageHandler->XText[rsAccessedDate] + L" (" + GLanguageHandler->XText[rsTime] + L")" + separator +
									GLanguageHandler->XText[rsModifiedDate] + L" (" + GLanguageHandler->XText[rsTime] + L")" + separator +
									GLanguageHandler->XText[rsCategory] + separator +
									GLanguageHandler->XText[rsCategory] + L"ID" + separator +
									GLanguageHandler->XText[rsOwner] + separator +
									GLanguageHandler->LanguageTypes[__FileType_ReadOnly] + separator +
									GLanguageHandler->LanguageTypes[__FileType_Hidden] + separator +
									GLanguageHandler->LanguageTypes[__FileType_System] + separator +
									GLanguageHandler->LanguageTypes[__FileType_Archive] + separator +
									GLanguageHandler->XText[rsTemporary];

				ofile << s << std::endl;
			}

			std::wstring ucFolder = GLanguageHandler->XText[rsFolder];
			
			std::transform(ucFolder.begin(), ucFolder.end(), ucFolder.begin(), ::towupper);

			for (int t = 0; t < GScanDetails->Files.size(); t++)
			{
				bool AddToFile = false;

				if (options.Category == -1)
				{
					AddToFile = true;
				}
				else
				{
					if (GScanDetails->Files[t].Category == options.Category)
					{
						AddToFile = true;
					}
				}

				if (AddToFile)
				{ 
					std::wstring lOutput;
					
					if (GScanDetails->Files[t].Attributes & FILE_ATTRIBUTE_DIRECTORY)
					{
					
						lOutput =	L"\"" + GScanDetails->Files[t].FileName + L"\"" + separator +
									L"\"" + GScanDetails->Folders[GScanDetails->Files[t].FilePathIndex] +  GScanDetails->Files[t].FileName + L"\"" + separator +

									ucFolder + separator +
									L"-1" + separator +
									L"-1" + separator +

									Convert::IntDateToString(GScanDetails->Files[t].FileDateC) + separator +
									Convert::IntDateToString(GScanDetails->Files[t].FileDateA) + separator +
									Convert::IntDateToString(GScanDetails->Files[t].FileDateM) + separator +

									std::to_wstring(GScanDetails->Files[t].FileTimeC) + separator +
									std::to_wstring(GScanDetails->Files[t].FileTimeA) + separator +
									std::to_wstring(GScanDetails->Files[t].FileTimeM) + separator +

									ucFolder + separator +

									L"99" + separator +

									GScanDetails->Users[GScanDetails->Files[t].Owner].Name + separator +

									Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_READONLY) + separator +
									Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_HIDDEN) + separator +
									Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_SYSTEM) + separator +
									Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_ARCHIVE) + separator +
									Convert::BoolToString(GScanDetails->Files[t].Temp);
					}
					else
					{
						lOutput   = L"\"" + GScanDetails->Files[t].FileName + L"\"" + separator +
									L"\"" + GScanDetails->Folders[GScanDetails->Files[t].FilePathIndex] + GScanDetails->Files[t].FileName + L"\"" + separator +

									L"\"" + Convert::GetSizeString(options.Units, GScanDetails->Files[t].Size) + L"\"" + separator +
									L"\"" + std::to_wstring(GScanDetails->Files[t].Size) + L"\"" + separator +
									L"\"" + std::to_wstring(GScanDetails->Files[t].SizeOnDisk) + L"\"" + separator +

									Convert::IntDateToString(GScanDetails->Files[t].FileDateC) + separator +
									Convert::IntDateToString(GScanDetails->Files[t].FileDateA) + separator +
									Convert::IntDateToString(GScanDetails->Files[t].FileDateM) + separator +

									std::to_wstring(GScanDetails->Files[t].FileTimeC) + separator +
									std::to_wstring(GScanDetails->Files[t].FileTimeA) + separator +
									std::to_wstring(GScanDetails->Files[t].FileTimeM) + separator +

									GLanguageHandler->TypeDescriptions[GScanDetails->Files[t].Category] + separator +

									std::to_wstring(GScanDetails->Files[t].Category) + separator +

									GScanDetails->Users[GScanDetails->Files[t].Owner].Name + separator +

									Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_READONLY) + separator +
									Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_HIDDEN) + separator +
									Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_SYSTEM) + separator +
									Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_ARCHIVE) + separator +
									Convert::BoolToString(GScanDetails->Files[t].Temp);
					}

					ofile << lOutput << std::endl;
				}
			}

			ofile.close();
		}
	}
};