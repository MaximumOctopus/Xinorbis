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

#include <Vcl.Dialogs.hpp>

#include "Convert.h"
#include "LanguageHandler.h"
#include "SaveDialogs.h"

extern LanguageHandler *GLanguageHandler;


std::wstring SaveDialogs::Execute(const std::wstring filter, const std::wstring default_ext, const std::wstring initial_folder, const std::wstring file_name)
{
	std::wstring selected_file_name = L"";

	TSaveDialog *sd = new TSaveDialog(NULL);

	sd->Filter = filter;
	sd->DefaultExt = default_ext;
	sd->FileName = Convert::ToReportFileName(file_name).c_str();

	if (initial_folder != L"")
	{
		sd->InitialDir = initial_folder.c_str();
	}

	if (sd->Execute())
	{
		selected_file_name = sd->FileName.c_str();
	}

	delete sd;

	return selected_file_name;
}


std::wstring SaveDialogs::ExecuteImages(const std::wstring file_name)
{
	std::wstring selected_file_name = L"";

	TSaveDialog *sd = new TSaveDialog(NULL);

	sd->Filter = (GLanguageHandler->Text[kPNGFiles] + L" (*.png)|*.png").c_str();
	sd->DefaultExt = L".png";
	sd->FileName = Convert::ToReportFileName(file_name).c_str();

	if (sd->Execute())
	{
		selected_file_name = sd->FileName;
	}

	delete sd;

	return selected_file_name;
}


std::wstring SaveDialogs::ExecuteReports(const std::wstring file_name)
{
	std::wstring selected_file_name = L"";

	TSaveDialog *sd = new TSaveDialog(NULL);

	sd->Filter = (GLanguageHandler->Text[kCSVFiles] + L" (*.csv)|*.csv|" +
				  L"HTML (*.htm)|*.htm|" +
				  GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt").c_str();
	sd->DefaultExt = L".csv";
	sd->FileName = Convert::ToReportFileName(file_name).c_str();

	if (sd->Execute())
	{
		selected_file_name = sd->FileName;
	}

	delete sd;

	return selected_file_name;
}
