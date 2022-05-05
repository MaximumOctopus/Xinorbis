//
// X.Robot 4.0 :: C++ rewrite
//
// (c) Paul Alan Freshney 2019-2020
//     Maximum Octopus Limited
//
// xinorbis.com
// maximumoctopus.com
// 
// twitter.com/maximumoctopus
//
//
// June 4th 2020
//


#include "Convert.h"
#include "ReportXinorbis.h"
#include "ReportXinorbisReportOptions.h"
#include "ScanDetails.h"
#include "Utility.h"
#include <algorithm>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <string>

extern ScanDetails* GScanDetails;

namespace ReportXinorbis
{
	void GenerateXinorbisReport(XinorbisReportOptions options)
	{
		std::wofstream ofile(options.Filename);

		ofile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

		if (ofile)
		{
			// == header ============================================================================================================

			ofile << L"{info" << std::endl;
			ofile << L"XReport2" << std::endl;

			ofile << GScanDetails->ScanPath << std::endl;
			ofile << GScanDetails->FolderCount << std::endl;
			ofile << GScanDetails->FileCount << std::endl;
			ofile << Convert::ConvertToUsefulUnit(GScanDetails->TotalSize) << std::endl;
			ofile << Utility::GetDate(__GETTIMEFORMAT_DISPLAY) + L", " + Utility::GetTime(__GETTIMEFORMAT_DISPLAY) << std::endl;
			ofile << 0 << std::endl;

			ofile << L"}" << std::endl;

			// ======================================================================================================================

			if (GScanDetails->FolderCount != 0)
			{
				ofile << L"{folderlist" << std::endl;

				for (int t = 0; t < GScanDetails->Folders.size(); t++)
				{
					ofile << GScanDetails->Folders[t] << std::endl;
				}

				ofile << L"}" << std::endl;
			}

			if (GScanDetails->FileCount != 0)
			{
				for (int t = 0; t < GScanDetails->Files.size(); t++)
				{
					ofile << L"{file" << std::endl;

					ofile << GScanDetails->Files[t].FileName << std::endl;
					ofile << GScanDetails->Files[t].FilePathIndex << std::endl;
					ofile << GScanDetails->Files[t].Size << std::endl;
					ofile << GScanDetails->Files[t].SizeOnDisk << std::endl;
					ofile << GScanDetails->Files[t].FileDateC << std::endl;
					ofile << GScanDetails->Files[t].FileDateA << std::endl;
					ofile << GScanDetails->Files[t].FileDateM << std::endl;
					ofile << GScanDetails->Files[t].FileTimeC << std::endl;
					ofile << GScanDetails->Files[t].FileTimeA << std::endl;
					ofile << GScanDetails->Files[t].FileTimeM << std::endl;
					ofile << GScanDetails->Files[t].Category << std::endl;
					ofile << (GScanDetails->Files[t].Attributes & FILE_ATTRIBUTE_READONLY) << std::endl;
					ofile << (GScanDetails->Files[t].Attributes & FILE_ATTRIBUTE_HIDDEN) << std::endl;
					ofile << (GScanDetails->Files[t].Attributes & FILE_ATTRIBUTE_SYSTEM) << std::endl;
					ofile << (GScanDetails->Files[t].Attributes & FILE_ATTRIBUTE_ARCHIVE) << std::endl;
					ofile << GScanDetails->Files[t].Temp << std::endl;
					ofile << GScanDetails->Users[GScanDetails->Files[t].Owner].Name << std::endl;
					ofile << GScanDetails->Files[t].Attributes << std::endl;

					ofile << L"}" << std::endl;
				}
			}

			ofile.close();
		}
	}
}