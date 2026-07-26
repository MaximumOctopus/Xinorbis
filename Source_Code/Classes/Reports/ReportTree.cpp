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
#include <Windows.h>

#include "Convert.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportTree.h"
#include "ReportTreeOptions.h"
#include "ScanEngine.h"
#include "Utility.h"


extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


namespace ReportTree
{
    // this might be quite slow... will optimise!
	bool sortByPath(const FileObject *lhs, const FileObject *rhs)
	{
		std::wstring l = lhs->FullPath;
		std::wstring r = rhs->FullPath;

        std::transform(l.begin(), l.end(), l.begin(), ::tolower);
        std::transform(r.begin(), r.end(), r.begin(), ::tolower);

        if (l.compare(r) <= 0)
        {
            return true;
        }

        return false;
    }


	void Generate(TreeReportOptions options, std::vector<std::wstring> *data, int DataSource)
    {
		std::sort(GScanEngine->Data[DataSource].Files.begin(), GScanEngine->Data[DataSource].Files.end(), sortByPath);

		//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (Tree):\n";
		//GLog->Add( L"    " << options.FileName << "\n\n";

		std::wstring OldPath = L"";
		std::wstring Optional = L"";
		int Indent = 1;

		data->push_back(L"\n");
		data->push_back(GLanguageHandler->SummaryReport[1] + std::to_wstring(GScanEngine->Data[DataSource].FileCount) + L"\n");
		data->push_back(GLanguageHandler->SummaryReport[2] + std::to_wstring(GScanEngine->Data[DataSource].FolderCount) + L"\n");
		data->push_back(GLanguageHandler->SummaryReport[3] + Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSize) + L"\n");
		data->push_back(L"\n");

		data->push_back(GScanEngine->Data[DataSource].Path.String + L"\n");

		if (GScanEngine->Data[DataSource].Source == ScanSource::FileCSV)
		{
			data->push_back(L"    (from CSV import \"" + GScanEngine->Data[DataSource].Path.CSVSource + L"\")\n");
		}

		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			if (FILE_ATTRIBUTE_DIRECTORY & file->Attributes)
			{
				if (GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name != OldPath)
				{
					data->push_back(L"\n");

					OldPath = GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name;

					Indent = GetIndent(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name);

					if (options.IncludeAttributes)
					{
						Optional = L" [" + Formatting::GetAttributeAsString(file->Attributes) + L"]";
					}
					else
					{
						Optional.clear();
					}

					data->push_back(Formatting::StringOfCharacters(Indent * 4, L" ") + L"\\ " + Utility::LastFolder(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name) + Optional + L"\n");
				}
			}
			else
			{
				if (OldPath != GScanEngine->Data[DataSource].Folders[file->FilePathIndex])
				{
					data->push_back(L"\n");

					OldPath = GScanEngine->Data[DataSource].Folders[file->FilePathIndex];

					Indent = GetIndent(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name);
				}

				Optional.clear();

				if (options.IncludeSize)
				{
					Optional = Formatting::AddLeading(Convert::ConvertToUsefulUnit(file->Size), 10, ' ') + L" ";
				}

				if (options.IncludeAttributes)
				{
					Optional += Formatting::GetAttributeAsString(file->Attributes) + L" ";
				}

				data->push_back(Formatting::StringOfCharacters(Indent * 4, L" ") + Optional + file->Name + L"\n");
			}
		}
	}


	int GetIndent(const std::wstring input)
	{
		int count = 0;

		for (int t = 0; t < input.size(); t++)
		{
			if (input[t] == L'\\')
			{
				count++;
			}
		}

		return count;
    }
}
