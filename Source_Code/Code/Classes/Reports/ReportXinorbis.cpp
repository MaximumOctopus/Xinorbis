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

#include "Convert.h"
#include "Formatting.h"
#include "ReportXinorbis.h"
#include "ReportXinorbisOptions.h"
#include "ScanEngine.h"
#include "Utility.h"


extern ScanEngine* GScanEngine;


namespace ReportXinorbis
{
	void Generate(XinorbisReportOptions options, std::vector<std::wstring> &data, int DataSource)
	{
		// == header ============================================================================================================

		data.push_back(L"{info\n");
		data.push_back(L"XReport2\n");

		data.push_back(GScanEngine->Data[DataSource].Path.String + L"\n");
		data.push_back(std::to_wstring(GScanEngine->Data[DataSource].FolderCount) + L"\n");
		data.push_back(std::to_wstring(GScanEngine->Data[DataSource].FileCount) + L"\n");
		data.push_back(Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSize) + L"\n");
		data.push_back(Utility::GetDate(DateTimeFormat::Display) + L", " + Utility::GetTime(DateTimeFormat::Display) + L"\n");
		data.push_back(L"0\n");

		data.push_back(L"}\n");

		// ======================================================================================================================

		if (GScanEngine->Data[DataSource].FolderCount != 0)
		{
			data.push_back(L"{folderlist\n");

			for (int t = 0; t < GScanEngine->Data[DataSource].Folders.size(); t++)
			{
				data.push_back(GScanEngine->Data[DataSource].Folders[t] + L"\n");
			}

			data.push_back(L"}\n");
		}

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			for (FileObject *file : GScanEngine->Data[DataSource].Files)
			{
				data.push_back(L"{file\n");

				data.push_back(file->Name + L"\n");
				data.push_back(std::to_wstring(file->FilePathIndex) + L"\n");
				data.push_back(std::to_wstring(file->Size) + L"\n");
				data.push_back(std::to_wstring(file->SizeOnDisk) + L"\n");
				data.push_back(std::to_wstring(file->DateCreated) + L"\n");
				data.push_back(std::to_wstring(file->DateAccessed) + L"\n");
				data.push_back(std::to_wstring(file->DateModified) + L"\n");
				data.push_back(std::to_wstring(file->TimeCreated) + L"\n");
				data.push_back(std::to_wstring(file->TimeAccessed) + L"\n");
				data.push_back(std::to_wstring(file->TimeModified) + L"\n");
				data.push_back(std::to_wstring(file->Category) + L"\n");
				data.push_back(std::to_wstring(file->Attributes & FILE_ATTRIBUTE_READONLY) + L"\n");
				data.push_back(std::to_wstring(file->Attributes & FILE_ATTRIBUTE_HIDDEN) + L"\n");
				data.push_back(std::to_wstring(file->Attributes & FILE_ATTRIBUTE_SYSTEM) + L"\n");
				data.push_back(std::to_wstring(file->Attributes & FILE_ATTRIBUTE_ARCHIVE) + L"\n");
				data.push_back(std::to_wstring(file->Temp) + L"\n");
				data.push_back(GScanEngine->Data[DataSource].Users[file->Owner]->Name + L"\n");
				data.push_back(std::to_wstring(file->Attributes) + L"\n");

				data.push_back(L"}\n");
			}
		}
	}
}
