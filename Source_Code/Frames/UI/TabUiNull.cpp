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

#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "TabUiNull.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


void TabUiNull::TableFiles(TStringGrid* grid)
{
//	if XSettings.Forms.ProgressForm <> Nil then begin
//	  XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsNullFiles]);
//	  XSettings.System.JustInTimeProcessed[aDataIndex, TabIndexNull] := True;
//	end;

  // ===========================================================================

	int count = 0;

//	oTable.ClearRows(1, oTable.RowCount - 1);
	grid->RowCount = 2;

	grid->BeginUpdate();

	for (FileObject file : GScanEngine->Data.Files)
	{
		if (!(faDirectory & file.Attributes))
		{
			if (file.Size == 0)
			{
				grid->Cells[0][count + 1] = (GScanEngine->Data.Folders[file.FilePathIndex] + file.Name).c_str();

				grid->RowCount++;

				count++;
			}
		}
	}

	if (count == 0)
	{
		grid->Cells[0][1] = GLanguageHandler->Text[kNoneFound].c_str();
	}
	else
	{
		grid->RowCount--;
	}

	grid->EndUpdate();
}
