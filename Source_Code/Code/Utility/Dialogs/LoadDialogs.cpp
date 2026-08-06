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

#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "Utility.h"

extern LanguageHandler *GLanguageHandler;


std::wstring LoadDialogs::Execute(const std::wstring filter, const std::wstring default_ext, const std::wstring initial_folder, const std::wstring file_name)
{
	std::wstring selected_file_name = L"";

	TOpenDialog *od = new TOpenDialog(NULL);

	od->Filter = filter.c_str();
	od->DefaultExt = default_ext.c_str();
	od->InitialDir = initial_folder.c_str();
	od->FileName = file_name.c_str();

	if (od->Execute())
	{
		selected_file_name = od->FileName;
	}

	delete od;

	return selected_file_name;
}


std::wstring LoadDialogs::ExecuteExe(const std::wstring file_name)
{
	std::wstring selected_file_name = L"";

	TOpenDialog *od = new TOpenDialog(NULL);

	od->Filter = (GLanguageHandler->Text[kPrograms] + L" (*.exe)|*.exe").c_str();
	od->DefaultExt = L".exe";
	od->FileName = Utility::ReportFileName(file_name).c_str();

	if (od->Execute())
	{
		selected_file_name = od->FileName;
	}

	delete od;

	return selected_file_name;
}
