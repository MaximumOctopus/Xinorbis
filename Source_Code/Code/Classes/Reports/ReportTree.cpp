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
    bool sortByPath(const FileObject& lhs, const FileObject& rhs) 
    { 
        std::wstring l = GScanEngine->Data.Folders[lhs.FilePathIndex] + lhs.Name;
        std::wstring r = GScanEngine->Data.Folders[rhs.FilePathIndex] + rhs.Name;

        std::transform(l.begin(), l.end(), l.begin(), ::tolower);
        std::transform(r.begin(), r.end(), r.begin(), ::tolower);

        if (l.compare(r) <= 0)
        {
            return true;
        }

        return false;
    }


    void Generate(TreeReportOptions options)
    {
        std::ofstream file(options.FileName);

        if (file)
        {
            std::sort(GScanEngine->Data.Files.begin(), GScanEngine->Data.Files.end(), sortByPath);

			//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (Tree):\n";
			//GLog->Add( L"    " << options.FileName << "\n\n";

            std::wstring OldPath = L"";
            std::wstring Optional = L"";
            int Indent = 1;

            file << Formatting::to_utf8(L"\n");
            file << Formatting::to_utf8(GLanguageHandler->SummaryReport[1] + std::to_wstring(GScanEngine->Data.FileCount) + L"\n");
            file << Formatting::to_utf8(GLanguageHandler->SummaryReport[2] + std::to_wstring(GScanEngine->Data.FolderCount) + L"\n");
            file << Formatting::to_utf8(GLanguageHandler->SummaryReport[3] + Convert::ConvertToUsefulUnit(GScanEngine->Data.TotalSize) + L"\n");
            file << Formatting::to_utf8(L"\n");

            file << Formatting::to_utf8(GScanEngine->Path.String + L"\n");

            if (GScanEngine->Data.Source == ScanSource::CSVImport)
            {
                file << Formatting::to_utf8(L"    (from CSV import \"" + GScanEngine->Path.CSVSource + L"\")\n");
            }

            for (int t = 0; t < GScanEngine->Data.Files.size(); t++)
            {
                if (FILE_ATTRIBUTE_DIRECTORY & GScanEngine->Data.Files[t].Attributes)
                {
                    if (GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex] + GScanEngine->Data.Files[t].Name != OldPath)
                    {
                        file << "\n";

                        OldPath = GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex] + GScanEngine->Data.Files[t].Name;

                        Indent = GetIndent(GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex] + GScanEngine->Data.Files[t].Name);

                        if (options.IncludeAttributes)
                        {
                            Optional = L" [" + Formatting::GetAttributeAsString(GScanEngine->Data.Files[t].Attributes) + L"]";
                        }
                        else
                        {
                            Optional.clear();
                        }

                        file << Formatting::to_utf8(Formatting::StringOfCharacters(Indent * 4, L" ") + L"\\ " + Utility::LastFolder(GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex] + GScanEngine->Data.Files[t].Name) + Optional + L"\n");
                    }
                }
                else
                {
                    if (OldPath != GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex])
                    {
                        file << "\n";

                        OldPath = GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex];

                        Indent = GetIndent(GScanEngine->Data.Folders[GScanEngine->Data.Files[t].FilePathIndex] + GScanEngine->Data.Files[t].Name);
                    }

                    Optional.clear();

                    if (options.IncludeSize)
                    {
                        Optional = Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data.Files[t].Size), 10, ' ') + L" ";
                    }

                    if (options.IncludeAttributes)
                    {
                        Optional += Formatting::GetAttributeAsString(GScanEngine->Data.Files[t].Attributes) + L" ";
                    }

                    file << Formatting::to_utf8(Formatting::StringOfCharacters(Indent * 4, L" ") + Optional + GScanEngine->Data.Files[t].Name + L"\n");
                }
            }
        }
        else
        {
			//GLog->Add( GLanguageHandler->Text[kErrorSaving] + L" (Tree):\n";
			//GLog->Add( L"    " << options.FileName << "\n\n";
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