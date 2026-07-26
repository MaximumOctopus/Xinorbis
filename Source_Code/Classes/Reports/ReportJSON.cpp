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

#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportJSON.h"
#include "ScanEngine.h"
#include "Utility.h"


extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


namespace ReportJSON
{
	void DetailedFileList(std::vector<std::wstring> &data, const std::wstring file_name, int DataSource)
	{
		//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (JSON, Detailed):\n\n";

		data.push_back(L"{\n");

		data.push_back(GScanEngine->Data[DataSource].ToJSON());

		data.push_back(L"\"files\":[\n");

		int mod = 0;

		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			std::wstring json = file->ToJSON(GScanEngine->Data[DataSource].Folders[file->FilePathIndex], GScanEngine->Data[DataSource].Users[file->Owner]->Name);

			if (mod == GScanEngine->Data[DataSource].Files.size() - 1)
			{
				data.push_back(L"    " + json + L"\n");
			}
			else
			{
				data.push_back(L"    " + json + L",\n");
			}

			mod++;
		}

		data.push_back(L"]\n");
		data.push_back(L"}\n");
	}


	void SimpleFileList(std::vector<std::wstring> &data, const std::wstring file_name, int DataSource)
	{
	   //GLog->Add( << GLanguageHandler->Text[kSavingReports] + L" (JSON, Simple):\n\n";

		data.push_back(L"{\n");

		data.push_back(GScanEngine->Data[DataSource].ToJSON());

		data.push_back(L"\"files\":[\n");

		for (int t = 0; t < GScanEngine->Data[DataSource].Files.size(); t++)
		{
			if (t == GScanEngine->Data[DataSource].Files.size() - 1)
			{
				data.push_back(L"    { \"file\": \"" + Formatting::ReplaceForJSON(GScanEngine->Data[DataSource].Folders[GScanEngine->Data[DataSource].Files[t]->FilePathIndex] + GScanEngine->Data[DataSource].Files[t]->Name) + L"\" }\n");
			}
			else
			{
				data.push_back(L"    { \"file\": \"" + Formatting::ReplaceForJSON(GScanEngine->Data[DataSource].Folders[GScanEngine->Data[DataSource].Files[t]->FilePathIndex] + GScanEngine->Data[DataSource].Files[t]->Name) + L"\" },\n");
			}
		}

		data.push_back(L"]\n");
		data.push_back(L"}\n");
	}
}
