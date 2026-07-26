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
#include <string>

#include "Convert.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportDates.h"
#include "ScanEngine.h"
#include "Utility.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


void ReportDates::ReportDates(DateReportOptions options, std::vector<std::wstring> *data, int DataSource)
{
	if (options.Created)
	{
		// to do std::ranges::sort(GScanEngine->Data[DataSource].Files, {}, &FileObject::DateCreated);
	}
	else
	{
		// to do std::ranges::sort(GScanEngine->Data[DataSource].Files, {}, &FileObject::DateModified);
	}

	if (options.Day)
	{
		Day(options, data, DataSource);
	}

	if (options.Month)
	{
		Month(options, data, DataSource);
	}

	if (options.Year)
	{
		Year(options, data, DataSource);
	}
}


void ReportDates::Day(DateReportOptions options, std::vector<std::wstring> *data, int DataSource)
{
   //GLog->Add( << GLanguageHandler->Text[kSavingReports] << L" (Dates::Day):\n\n";

	if (GScanEngine->Data[DataSource].Files.size() != 0)
	{
		data->push_back(L"    FolderScanUltra: Dates::Day \"" + GScanEngine->Data[DataSource].Path.String + L"\"\n");
		data->push_back(L"        " + GLanguageHandler->Text[kAnalysedAt] + L" " + Utility::GetTime(DateTimeFormat::Display) + L", " + Utility::GetDate(DateTimeFormat::Display) + L"\n\n");

		int lastdate = 0;
		std::wstring date(L"");

		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			if (options.Created)
			{
				if (file->DateCreated != lastdate)
				{
					data->push_back(L"\n " + Convert::YYYYMMDDToMonthDayYear(file->DateCreated) + L"\n\n");

					lastdate = file->DateCreated;

					date = std::to_wstring(file->DateCreated);
				}
			}
			else
			{
				if (file->DateModified != lastdate)
				{
					data->push_back(L"\n " + Convert::YYYYMMDDToMonthDayYear(file->DateModified) + L"\n\n");

					lastdate = file->DateModified;

					date = std::to_wstring(file->DateModified);
				}
			}

			if (file->Attributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				data->push_back(L"  " +
					date + L"  " +
					L"      [FOLDER] " +
					GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
			}
			else
			{
				data->push_back(L"  " +
					date + L"  " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(file->Size), 14, L' ') + L" " +
					GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
			}
		}
	}

   //GLog->Add( GLanguageHandler->Text[kTextReportSavedAs] << L" " << options.FileName << L"\n\n";
}


void ReportDates::Month(DateReportOptions options, std::vector<std::wstring> *data, int DataSource)
{
   //GLog->Add( GLanguageHandler->Text[kSavingReports] << L" (Dates::Month):\n\n";

	if (GScanEngine->Data[DataSource].Files.size() != 0)
	{
		data->push_back(L"    FolderScanUltra: Dates::Month \"" + GScanEngine->Data[DataSource].Path.String + L"\"\n");
		data->push_back(L"        " + GLanguageHandler->Text[kAnalysedAt] + L" " + Utility::GetTime(DateTimeFormat::Display) + L", " + Utility::GetDate(DateTimeFormat::Display) + L"\n\n");

		int lastmonth = 99;
		std::wstring date(L"");

		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			if (options.Created)
			{
				std::wstring cd = std::to_wstring(file->DateCreated);

				int fm = std::stoi(cd.substr(4, 2));

				if (fm != lastmonth)
				{
					data->push_back(L"\n " + Convert::YYYYMMDDToMonthYear(file->DateCreated) + L"\n\n");

					lastmonth = fm;
				}

				date = std::to_wstring(file->DateCreated);
			}
			else
			{
				std::wstring cd = std::to_wstring(file->DateModified);

				int fm = std::stoi(cd.substr(4, 2));

				if (fm != lastmonth)
				{
					data->push_back(L"\n " + Convert::YYYYMMDDToMonthYear(file->DateModified) + L"\n\n");

					lastmonth = fm;
				}

				date = std::to_wstring(file->DateModified);
			}

			if (file->Attributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				data->push_back(L"  " +
					date + L"  " +
					L"      [FOLDER] " +
					GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
			}
			else
			{
				data->push_back(L"  " +
					date + L"  " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(file->Size), 14, L' ') + L" " +
					GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
			}
		}
	}

	//GLog->Add( GLanguageHandler->Text[kTextReportSavedAs] << L" " << options.FileName << L"\n\n";
}


void ReportDates::Year(DateReportOptions options, std::vector<std::wstring> *data, int DataSource)
{
	//GLog->Add( GLanguageHandler->Text[kSavingReports] << L" (Dates::Year):\n\n";

	if (GScanEngine->Data[DataSource].Files.size() != 0)
	{
		data->push_back(L"    FolderScanUltra: Dates::Year \"" + GScanEngine->Data[DataSource].Path.String + L"\"\n");
		data->push_back(L"        " + GLanguageHandler->Text[kAnalysedAt] + L" " + Utility::GetTime(DateTimeFormat::Display) + L", " + Utility::GetDate(DateTimeFormat::Display) + L"\n\n");

		int lastyear = 0;
		std::wstring date(L"");

		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			if (options.Created)
			{
				std::wstring cd = std::to_wstring(file->DateCreated);

				int fy = std::stoi(cd.substr(0, 4));

				if (fy != lastyear)
				{
					data->push_back(L"\n " + Convert::YYYYMMDDToMonthYear(file->DateCreated) + L"\n\n");

					lastyear = fy;
				}

				date = std::to_wstring(file->DateCreated);
			}
			else
			{
				std::wstring cd = std::to_wstring(file->DateModified);

				int fy = std::stoi(cd.substr(0, 4));

				if (fy != lastyear)
				{
					data->push_back(L"\n " + Convert::YYYYMMDDToMonthYear(file->DateModified) + L"\n\n");

					lastyear = fy;
				}

				date = std::to_wstring(file->DateModified);
			}

			if (file->Attributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				data->push_back(L"  " +
					date + L"  " +
					L"      [FOLDER] " +
					GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
			}
			else
			{
				data->push_back(L"  " +
					date + L"  " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(file->Size), 14, L' ') + L" " +
					GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name + L"\n");
			}
		}
	}

	//GLog->Add( GLanguageHandler->Text[kTextReportSavedAs] << L" " << options.FileName << L"\n\n";
}