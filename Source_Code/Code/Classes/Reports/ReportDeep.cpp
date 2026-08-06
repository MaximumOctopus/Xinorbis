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


bool ReportDeep::ProcessFolder(int DataSource, int folder_index)
{
    FolderData.clear();

    largestSize = 0;
    largestCount = 0;

	for (FileObject *file : GScanEngine->Data[DataSource].Files)
	{
		if (file->FilePathIndex == folder_index)
		{
			if (file->Category == kFileCategoryDirectory)
            {
				SizeOfFolder sof = GScanEngine->Data[DataSource].GetSizeOfFolder(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name,
																                 file->Name);

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