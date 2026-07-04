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

#include "Convert.h"
#include "Formatting.h"
#include "ReportXinorbis.h"
#include "ReportXinorbisOptions.h"
#include "ScanEngine.h"
#include "Utility.h"


extern ScanEngine* GScanEngine;


namespace ReportXinorbis
{
	void GenerateXinorbisReport(XinorbisReportOptions options)
	{
		std::ofstream ofile(options.FileName);

		if (ofile)
		{
			// == header ============================================================================================================

			ofile << Formatting::to_utf8(L"{info\n");
			ofile << Formatting::to_utf8(L"XReport2\n");

			ofile << Formatting::to_utf8(GScanEngine->Path.String + L"\n");
			ofile << Formatting::to_utf8(GScanEngine->Data.FolderCount + L"\n");
			ofile << Formatting::to_utf8(GScanEngine->Data.FileCount + L"\n");
			ofile << Formatting::to_utf8(Convert::ConvertToUsefulUnit(GScanEngine->Data.TotalSize) + L"\n");
			ofile << Formatting::to_utf8(Utility::GetDate(DateTimeFormat::Display) + L", " + Utility::GetTime(DateTimeFormat::Display) + L"\n");
			ofile << Formatting::to_utf8(L"0\n");

			ofile << Formatting::to_utf8(L"}\n");

			// ======================================================================================================================

			if (GScanEngine->Data.FolderCount != 0)
			{
				ofile << Formatting::to_utf8(L"{folderlist\n");

				for (int t = 0; t < GScanEngine->Data.Folders.size(); t++)
				{
					ofile << Formatting::to_utf8(GScanEngine->Data.Folders[t] + L"\n");
				}

				ofile << Formatting::to_utf8(L"}\n");
			}

			if (GScanEngine->Data.FileCount != 0)
			{
				for (int t = 0; t < GScanEngine->Data.Files.size(); t++)
				{
					ofile << Formatting::to_utf8(L"{file\n");

					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].Name + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].FilePathIndex + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].Size + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].SizeOnDisk + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].DateCreated + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].DateAccessed + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].DateModified + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].TimeCreated + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].TimeAccessed + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].TimeModified + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].Category + L"\n");
					ofile << Formatting::to_utf8((GScanEngine->Data.Files[t].Attributes & FILE_ATTRIBUTE_READONLY) + L"\n");
					ofile << Formatting::to_utf8((GScanEngine->Data.Files[t].Attributes & FILE_ATTRIBUTE_HIDDEN) + L"\n");
					ofile << Formatting::to_utf8((GScanEngine->Data.Files[t].Attributes & FILE_ATTRIBUTE_SYSTEM) + L"\n");
					ofile << Formatting::to_utf8((GScanEngine->Data.Files[t].Attributes & FILE_ATTRIBUTE_ARCHIVE) + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].Temp + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Users[GScanEngine->Data.Files[t].Owner].Name + L"\n");
					ofile << Formatting::to_utf8(GScanEngine->Data.Files[t].Attributes + L"\n");

					ofile << Formatting::to_utf8(L"}\n");
				}
			}

			ofile.close();
		}
	}
}