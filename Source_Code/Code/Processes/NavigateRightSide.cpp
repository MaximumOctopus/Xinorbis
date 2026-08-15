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

#include "ConstantsGui.h"
#include "Convert.h"
#include "NavigateRightSide.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"

extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;


void NavigateRightSide::SetData(TStringGrid* grid, int data_source, int from_folder_id, unsigned __int64 p, bool filter_changed)
{
	DataSource = data_source;
	FromFolderId = from_folder_id;
	FolderSize = p;
	OutputGrid = grid;
	FilterChanged = filter_changed;
}


void NavigateRightSide::Execute()
{
	std::wstring s = L"";
	int orderx = 0;
	unsigned __int64 FileSize = 0;
	int FileCount   = 0;
	int FolderCount = 0;

    SizeOfFolder sof;

	if (GScanEngine->Data[DataSource].Files.size() == 0) return;

	//TGridUtility.ClearStringGird(Grid, False);

	GScanEngine->FolderStructure.push_back(GScanEngine->Data[DataSource].Folders[FromFolderId] + L"?" + std::to_wstring(FolderSize));

	GScanEngine->CurrentNavigationSideLocation = GScanEngine->Data[DataSource].Folders[FromFolderId];

	int row = 1;

	for (FileObject *file : GScanEngine->Data[DataSource].Files)
	{
		if (file->FilePathIndex == FromFolderId)
		{
			if (faDirectory & file->Attributes ||
				GSettingsHandler->Navigation.Display[1][file->Category] == L'1')
			{
				if (!(faDirectory & file->Attributes))  // file
				{
					OutputGrid->Cells[ksgnFileName][row] = file->Name.c_str();

					OutputGrid->Cells[ksgnStringSize][row]  = Convert::ConvertToUsefulUnit(file->Size).c_str();
					OutputGrid->Cells[ksgnIntegerSize][row] = std::to_wstring(file->Size).c_str();

					FileSize += file->Size;

					if (FolderSize != 0)
					{
						OutputGrid->Cells[ksgnStringPCent][row]  = Convert::DoubleToPercent(file->Size / FolderSize).c_str();
						OutputGrid->Cells[ksgnIntegerPCent][row] = std::round((file->Size / FolderSize) * 50);
					}
					else
					{
						OutputGrid->Cells[ksgnStringPCent][row]  = L"100%";
						OutputGrid->Cells[ksgnIntegerPCent][row] = L"100";
					}

					OutputGrid->Cells[ksgnFolderFile][row]     = L"0";

					OutputGrid->Cells[ksgnCreatedDate][row]    = Convert::IntDateToString(file->DateCreated).c_str();
					OutputGrid->Cells[ksgnAccessedDate][row]   = Convert::IntDateToString(file->DateAccessed).c_str();
					OutputGrid->Cells[ksgnModifiedDate][row]   = Convert::IntDateToString(file->DateModified).c_str();
					OutputGrid->Cells[ksgnUserName][row]       = GScanEngine->Data[DataSource].Users[file->Owner]->Name.c_str();

					s = L"----";
					if (faArchive & file->Attributes)  s[0] = L'A';
					if (faReadOnly & file->Attributes) s[1] = L'R';
					if (faSysFile & file->Attributes)  s[2] = L'S';
					if (faHidden & file->Attributes)   s[3] = L'H';

					OutputGrid->Cells[ksgnAttributes][row]     = s.c_str();

					OutputGrid->Cells[ksgnSizeOnDisk][row]     = Convert::ConvertToUsefulUnit(file->SizeOnDisk).c_str();
					OutputGrid->Cells[ksgnIntegetSoD][row]     = file->SizeOnDisk;

					OutputGrid->Cells[ksgnOrderIndex][row]     = orderx + 500000;

					OutputGrid->Cells[ksgnCategoryIndex][row]  = file->Category;

					FileCount++;
				}
				else   // folder
				{
					// cache the results in the FileSize & FileSizeOnDisk parameters of the file object as these aren"t used for folders
					// ===================================================================================================================
					if (file->Size == 0 || FilterChanged)
					{
						sof = GScanEngine->SizeOfFolderNav(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name,
														   GSettingsHandler->Navigation.Display[1]);

						file->Size = sof.Size;
						file->SizeOnDisk = sof.SizeOnDisk;
					}
					else
					{
						sof.Size = file->Size;
						sof.SizeOnDisk = file->SizeOnDisk;
					}

					OutputGrid->Cells[ksgnFileName][row]   = file->Name.c_str();

					OutputGrid->Cells[ksgnStringSize][row] = Convert::ConvertToUsefulUnit(sof.Size).c_str();

					s = L"----";
					if (faArchive & file->Attributes)  s[0] = L'A';
					if (faReadOnly & file->Attributes) s[1] = L'R';
					if (faSysFile & file->Attributes)  s[2] = L'S';
					if (faHidden & file->Attributes)   s[3] = L'H';

					OutputGrid->Cells[ksgnAttributes][row]     = s.c_str();

					OutputGrid->Cells[ksgnSizeOnDisk][row]     = Convert::ConvertToUsefulUnit(sof.SizeOnDisk).c_str();
					OutputGrid->Cells[ksgnIntegetSoD][row]     = sof.SizeOnDisk;

					OutputGrid->Cells[ksgnCreatedDate][row]    = Convert::IntDateToString(file->DateCreated).c_str();
					OutputGrid->Cells[ksgnAccessedDate][row]   = Convert::IntDateToString(file->DateAccessed).c_str();
					OutputGrid->Cells[ksgnModifiedDate][row]   = Convert::IntDateToString(file->DateModified).c_str();
					OutputGrid->Cells[ksgnUserName][row]       = GScanEngine->Data[DataSource].Users[file->Owner]->Name.c_str();

					if (FolderSize != 0)
					{
						OutputGrid->Cells[ksgnStringPCent][row]  = Convert::DoubleToPercent(sof.Size / FolderSize).c_str();
						OutputGrid->Cells[ksgnIntegerPCent][row] = std::round((sof.Size / FolderSize) * 50);
					}
					else
					{
						OutputGrid->Cells[ksgnStringPCent][row]  = L"100%";
						OutputGrid->Cells[ksgnIntegerPCent][row] = L"100";
					}

					OutputGrid->Cells[ksgnIntegerSize][row]    = sof.Size;

					FileSize += sof.Size;

					OutputGrid->Cells[ksgnFolderFile][row]     = L"1";
					OutputGrid->Cells[ksgnOrderIndex][row]     = orderx;

					OutputGrid->Cells[ksgnCategoryIndex][row]  = L"0";

					FolderCount++;
				}

				OutputGrid->RowCount++;

				row++;

				orderx++;
			}
		}
	}
}
