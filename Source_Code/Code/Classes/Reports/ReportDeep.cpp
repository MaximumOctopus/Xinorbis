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

#include <iostream>

#include "ReportDeep.h"
#include "ScanEngine.h"
#include "SizeOfFolder.h"


extern ScanEngine* GScanEngine;


ReportDeep::ReportDeep()
{
}


void ReportDeep::Add(std::wstring folder, unsigned __int64 size, int file_count)
{
    SizeOfFolder sof = { folder, size, 0, file_count };

    FolderData.push_back(sof);
}


bool ReportDeep::ProcessFolder(int folder_index)
{
    FolderData.clear();

    largestSize = 0;
    largestCount = 0;

    for (int f = 0; f < GScanEngine->Data.Files.size(); f++)
    {
        if (GScanEngine->Data.Files[f].FilePathIndex == folder_index)
        {
            if (GScanEngine->Data.Files[f].Category == __FileCategoryDirectory)
            {
			    //std::wcout << L"      " << GScanDetails->Folders[GScanDetails->Files[f].FilePathIndex] + GScanDetails->Files[f].FileName << "\n";

                SizeOfFolder sof = GScanEngine->GetSizeOfFolder(GScanEngine->Data.Folders[GScanEngine->Data.Files[f].FilePathIndex] + GScanEngine->Data.Files[f].Name,
                                                                GScanEngine->Data.Files[f].Name);

                FolderData.push_back(sof);

                if (sof.Size > largestSize)
                {
                    largestSize = sof.Size;
                }

                if (sof.FileCount > largestCount)
                {
                    largestCount = sof.FileCount;
                }
            }
        }
	}

    if (FolderData.size() == 0)
    {
        return false;
    }

    return true;
}