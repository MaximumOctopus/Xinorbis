// =====================================================================
//
// FolderScanUltra 5
//
// (c) Paul Alan Freshney 2019-2026
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FolderScanUltra
// 
// =====================================================================

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "Convert.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportCSV.h"
#include "ReportCSVOptions.h"
#include "ScanEngine.h"


extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


namespace ReportCSV
{
	void Summary(CSVReportOptions options)
	{
		std::wcout << GLanguageHandler->Text[kSavingReports] + L" (CSV):\n\n";

		std::ofstream ofile(options.FileName);

		if (ofile)
		{
			std::wstring separator = L",";

			if (options.Separator == 1)
			{
				// set to tab
			}

			if (options.Titles)
			{
				ofile << Formatting::to_utf8(GLanguageHandler->Text[kCategory] + separator +
						 GLanguageHandler->Text[kQuantity] + separator +
						 GLanguageHandler->Text[kQuantity] + separator + GLanguageHandler->Text[kAsPercent] + separator +
						 GLanguageHandler->Text[kSize] + separator +
						 GLanguageHandler->Text[kSizeOfFilesBytes] + separator +
						 GLanguageHandler->Text[kSize] + GLanguageHandler->Text[kAsPercent] + L"\n");
			}

			std::wstring output;

			// ignore 0 (that's a hack for something I can't remember as I write this)
			for (int t = 1; t < __FileCategoriesCount; t++)
			{
				output = GLanguageHandler->TypeDescriptions[t] + separator +

						  std::to_wstring(GScanEngine->Data.ExtensionSpread[t].Count) + separator +

						  std::to_wstring(std::round(((double)GScanEngine->Data.ExtensionSpread[t].Count / (double)GScanEngine->Data.FileCount) * 100)) + L"\"" + separator +

						  Convert::GetSizeString(options.Units, GScanEngine->Data.ExtensionSpread[t].Size) + L"\"" + separator +

						  std::to_wstring(GScanEngine->Data.ExtensionSpread[t].Size) + L"\"" + separator;

				if (GScanEngine->Data.TotalSize != 0)
				{
					output += L"\"" + std::to_wstring(std::round(((double)GScanEngine->Data.ExtensionSpread[t].Size / (double)GScanEngine->Data.TotalSize) * 100)) + L"\"";
				}
				else
				{
					output += L"\"100\"";
				}
			
				ofile << Formatting::to_utf8(output + L"\n");
			}

			ofile.close();
		}
	}


	void FullList(CSVReportOptions options)
	{
		std::wcout << GLanguageHandler->Text[kSavingReports] + L" (CSV):\n";
		std::wcout << L"    " << options.FileName << "\n\n";

		std::ofstream ofile(options.FileName);

		if (ofile)
		{
			std::wstring separator = L",";

			if (options.Separator == 1)
			{
				// set to tab
			}

			if (options.Titles)
			{
				std::wstring s = GLanguageHandler->Text[kFileName] + separator +
					GLanguageHandler->Text[kFilePath] + separator +
					GLanguageHandler->Text[kFolder] + separator +
					GLanguageHandler->Text[kSize] + separator +
					GLanguageHandler->Text[kSizeOfFilesBytes] + separator +
					GLanguageHandler->Text[kSizeOnDisk] + separator +
					GLanguageHandler->Text[kCreatedDate] + separator +
					GLanguageHandler->Text[kAccessedDate] + separator +
					GLanguageHandler->Text[kModifiedDate] + separator +
					GLanguageHandler->Text[kCreatedDate] + separator +
					GLanguageHandler->Text[kAccessedDate] + separator +
					GLanguageHandler->Text[kModifiedDate] + separator +
					GLanguageHandler->Text[kCreatedDate] + L" (" + GLanguageHandler->Text[kTime] + L")" + separator +
					GLanguageHandler->Text[kAccessedDate] + L" (" + GLanguageHandler->Text[kTime] + L")" + separator +
					GLanguageHandler->Text[kModifiedDate] + L" (" + GLanguageHandler->Text[kTime] + L")" + separator +
					GLanguageHandler->Text[kCategory] + separator +
					GLanguageHandler->Text[kCategory] + L"ID" + separator +
					GLanguageHandler->Text[kOwner] + separator +
					GLanguageHandler->LanguageTypes[__FileType_ReadOnly] + separator +
					GLanguageHandler->LanguageTypes[__FileType_Hidden] + separator +
					GLanguageHandler->LanguageTypes[__FileType_System] + separator +
					GLanguageHandler->LanguageTypes[__FileType_Archive] + separator +
					GLanguageHandler->Text[kTemporary] + separator +
					GLanguageHandler->Text[kFileAttributes];

				ofile << Formatting::to_utf8(s + L"\n");
			}
		
			for (int t = 0; t < GScanEngine->Data.Files.size(); t++)
			{
				bool AddToFile = false;

				if (options.Category == -1)
				{
					AddToFile = true;
				}
				else
				{
					if (GScanEngine->Data.Files[t].Category == options.Category)
					{
						AddToFile = true;
					}
				}

				if (AddToFile)
				{ 
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].ToCSV(GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex],
						                                                          GScanEngine->Data.Users[GScanEngine->Data.Files[t].Owner].Name, 
																				  options.Units) + L"\n");				
				}
			}

			ofile.close();
		}
	}
};