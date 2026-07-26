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

#include "LoadDialogs.h"


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

/*	TOpenDialog *od = new TOpenDialog(NULL);

	od->Filter = filter.c_str();
	od->DefaultExt = default_ext.c_str();
	od->InitialDir = initial_folder.c_str();
	od->FileName = file_name;

	if (od->Execute())
	{
		selected_file_name = od->FileName;
	}
                  TO DO
	delete od; */

	return selected_file_name;
}

	   /*
var
  lOpenDialog : TOpenDialog;

begin
  Result := '';

  lOpenDialog := TOpenDialog.Create(Nil);

  lOpenDialog.Filter     := XText[kPrograms] + ' (*.exe)|*.exe';
  lOpenDialog.DefaultExt := '.exe';
  lOpenDialog.FileName   := TUtility.ReportFileName(aFileName);

  if lOpenDialog.Execute then
	Result := lOpenDialog.FileName;

  FreeAndNil(lOpenDialog);
}*/
