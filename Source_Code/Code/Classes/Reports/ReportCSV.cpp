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
#include <fstream>
#include <string>

#include "Convert.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportCSV.h"
#include "ReportCSVOptions.h"
#include "ScanEngine.h"


extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;



void ReportCSV::Summary(CSVReportOptions options, std::vector<std::wstring> *data, int DataSource)
{
	//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (CSV):\n\n";

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
			data->push_back(GLanguageHandler->Text[kCategory] + separator +
					 GLanguageHandler->Text[kQuantity] + separator +
					 GLanguageHandler->Text[kQuantity] + separator + GLanguageHandler->Text[kAsPercent] + separator +
					 GLanguageHandler->Text[kSize] + separator +
					 GLanguageHandler->Text[kSizeOfFilesBytes] + separator +
					 GLanguageHandler->Text[kSize] + GLanguageHandler->Text[kAsPercent] + L"\n");
		}

		std::wstring output;

		// ignore 0 (that's a hack for something I can't remember as I write this)
		for (int t = 1; t < kFileCategoriesCount; t++)
		{
			output = GLanguageHandler->TypeDescriptions[t] + separator +

					  std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count) + separator +

					  std::to_wstring(std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100)) + L"\"" + separator +

					  Convert::GetSizeString(options.Units, GScanEngine->Data[DataSource].ExtensionSpread[t].Size) + L"\"" + separator +

					  std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Size) + L"\"" + separator;

			if (GScanEngine->Data[DataSource].TotalSize != 0)
			{
				output += L"\"" + std::to_wstring(std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100)) + L"\"";
			}
			else
			{
				output += L"\"100\"";
			}

			data->push_back(output + L"\n");
		}

		ofile.close();
	}
}


void ReportCSV::FullList(CSVReportOptions options, std::vector<std::wstring> *data, int DataSource)
{
	//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (CSV):\n";
	//GLog->Add( L"    " << options.FileName << "\n\n";

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
				GLanguageHandler->LanguageTypes[kFileType_ReadOnly] + separator +
				GLanguageHandler->LanguageTypes[kFileType_Hidden] + separator +
				GLanguageHandler->LanguageTypes[kFileType_System] + separator +
				GLanguageHandler->LanguageTypes[kFileType_Archive] + separator +
				GLanguageHandler->Text[kTemporary] + separator +
				GLanguageHandler->Text[kFileAttributes];

			data->push_back(s + L"\n");
		}

		for (int t = 0; t < GScanEngine->Data[DataSource].Files.size(); t++)
		{
			bool AddToFile = false;

			if (options.Category == -1)
			{
				AddToFile = true;
			}
			else
			{
				if (GScanEngine->Data[DataSource].Files[t]->Category == options.Category)
				{
					AddToFile = true;
				}
			}

			if (AddToFile)
			{
				data->push_back(GScanEngine->Data[DataSource].Files[t]->ToCSV(GScanEngine->Data[DataSource].Folders[GScanEngine->Data[DataSource].Files[t]->FilePathIndex],
																 GScanEngine->Data[DataSource].Users[GScanEngine->Data[DataSource].Files[t]->Owner]->Name,
																 options.Units) + L"\n");
			}
		}

		ofile.close();
	}
}
