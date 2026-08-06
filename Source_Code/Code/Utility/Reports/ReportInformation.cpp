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

#include "FileIO.h"
#include "LanguageHandler.h"
#include "ReportInformation.h"
#include "Utility.h"

extern LanguageHandler *GLanguageHandler;


void ReportInformation::GetInfoCSVReport(const std::wstring file_name, std::vector<std::wstring> *data)
{
	data->push_back(GLanguageHandler->Text[kReport] + L": CSV");

	std::vector<std::wstring> *report = new std::vector<std::wstring>;

	if (FileIO::LoadIntoVector(report, file_name))
	{
		data->push_back(std::to_wstring(report->size()) + L" records");
	}
	else
	{
		data->push_back(L"Unable to load file.");
	}

	delete report;
}


void ReportInformation::GetInfoXinorbisReport(const std::wstring file_name, std::vector<std::wstring> *data)
{
	data->push_back(GLanguageHandler->Text[kReport] + L": Xinorbis (old version)");
}


bool ReportInformation::GetInfoXinorbis2Report(const std::wstring file_name, std::vector<std::wstring> *data)
{
	const static int kInfoHeader      = 0;
	const static int kInfoPath        = 1;
	const static int kInfoFolderCount = 2;
	const static int kInfoFileCOunt   = 3;
	const static int kInfoTotalSize   = 4;
	const static int kInfoDate        = 5;
	const static int kInfoScanSource  = 6;

	std::vector<std::wstring> *report = new std::vector<std::wstring>;

	data->clear();

	if (FileIO::LoadIntoVector(report, file_name))
	{
		data->push_back(GLanguageHandler->Text[kReport] + L": Xinorbis v2");
		data->push_back(L"");

		bool ininfo = false;
		int row = 0;

		for (std::wstring s : *report)
		{
			if (!s.empty())
			{
				switch (s[0])
				{
				case L'{':
					if (s.find(L"info") != std::wstring::npos)
					{
						ininfo = true;

						row = 0;
					}
					break;
				case L'}':
					break;

				default:
					if (ininfo)
					{
						switch (row)
						{
						case kInfoHeader:
							data->push_back(s);
							break;
						case kInfoPath:
							data->push_back(s);
							break;
						case kInfoFolderCount:
							data->push_back(GLanguageHandler->Text[kFolders] + L": " + s);
							break;
						case kInfoFileCOunt:
							data->push_back(GLanguageHandler->Text[kFiles] + L": " + s);
							break;
						case kInfoTotalSize:
							data->push_back(GLanguageHandler->Text[kTotalSize] + L": " + s);
							break;
						case kInfoDate:
							data->push_back(s);
							break;
						case kInfoScanSource:
						{
							int source = stoi(s);

							data->push_back(Utility::GetSourceAsString(Utility::GetSourceFromInt(source)));
							break;
						}
						}
					}

					row++;
				}
			}
		}

		delete report;

		return true;
	}

    delete report;

	data->push_back(L"Error loading report \"" + file_name + L"\".");

//	GLog->Error(L"Error <" + IntToStr(IOResult) + L"> loading report \"" + aFileName + "\".");

	return false;
}
