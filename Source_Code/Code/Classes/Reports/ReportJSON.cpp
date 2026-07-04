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
#include <iostream>
#include <string>

#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportJSON.h"
#include "ScanEngine.h"
#include "Utility.h"


extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


namespace ReportJSON
{
	void DetailedFileList(const std::wstring file_name)
	{
		std::wcout << GLanguageHandler->Text[kSavingReports] + L" (JSON, Detailed):\n\n";

		std::ofstream ofile(file_name);

		if (ofile)
		{
			ofile << Formatting::to_utf8(L"{\n");

			ofile << Formatting::to_utf8(GScanEngine->ToJSON());

			ofile << Formatting::to_utf8(L"\"files\":[\n");

			for (int t = 0; t < GScanEngine->Data.Files.size(); t++)
			{
				std::wstring json = GScanEngine->Data.Files[t].ToJSON(GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex], GScanEngine->Data.Users[GScanEngine->Data.Files[t].Owner].Name);

				if (t == GScanEngine->Data.Files.size() - 1)
				{
					ofile << Formatting::to_utf8(L"    " + json + L"\n");
				}
				else
				{
					ofile << Formatting::to_utf8(L"    " + json + L",\n");
				}
			}

			ofile << Formatting::to_utf8(L"]\n");
			ofile << Formatting::to_utf8(L"}\n");

			ofile.close();
		}
	}
	

	void SimpleFileList(const std::wstring file_name)
	{
		std::wcout << GLanguageHandler->Text[kSavingReports] + L" (JSON, Simple):\n\n";

		std::ofstream ofile(file_name);

		if (ofile)
		{
			ofile << Formatting::to_utf8(L"{\n");

			ofile << Formatting::to_utf8(GScanEngine->ToJSON());

			ofile << Formatting::to_utf8(L"\"files\":[\n");

			for (int t = 0; t < GScanEngine->Data.Files.size(); t++)
			{
				if (t == GScanEngine->Data.Files.size() - 1)
				{
					ofile << Formatting::to_utf8(L"    { \"file\": \"" + Formatting::ReplaceForJSON(GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex] + GScanEngine->Data.Files[t].Name) + L"\" }\n");
				}
				else
				{
					ofile << Formatting::to_utf8(L"    { \"file\": \"" + Formatting::ReplaceForJSON(GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex] + GScanEngine->Data.Files[t].Name) + L"\" },\n");
				}
			}

			ofile << Formatting::to_utf8(L"]\n");
			ofile << Formatting::to_utf8(L"}\n");

			ofile.close();
		}
	}
}