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

#include "ConstantsData.h"
#include "ConstantsReports.h"
#include "FileExtension.h"
#include "FileExtensionHandler.h"
#include "Utility.h"

FileExtensionHandler* GFileExtensionHandler;

bool sortByName (FileExtension *lhs, FileExtension *rhs) {return lhs->Name < rhs->Name; }


FileExtensionHandler::FileExtensionHandler(const std::wstring folder)
{
	LoadDefaultFileExtensions(folder);
}


bool FileExtensionHandler::LoadDefaultFileExtensions(const std::wstring folder)
{
	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		std::wstring FileName = folder + L"system\\config\\DefaultExtensions\\" + kFileExtensionFileName[t] + L".txt";

		std::wifstream file(FileName);

		if (file)
		{
			std::wstring s;

			while (std::getline(file, s))
			{
				if (s.find('\n') != std::string::npos)
				{
					s.erase(std::remove(s.begin(), s.end(), '\n'), s.begin()); // to do, does it contain \n? do we need it?!
				}

				FileExtension *file_extension = new FileExtension(s, t);

				Extensions.push_back(file_extension);
			}

			file.close();
		}
	}

	Sort();

	#ifdef _DEBUG
	ReportDuplicates();
	#endif

	return true;
}


bool FileExtensionHandler::LoadDescriptions(const std::wstring folder)
{
	std::wstring FileName = folder + L"system\\index\\xinfe.txt";

	std::wifstream file(FileName);

	if (file)
	{
		std::wstring s = L"";

		while (std::getline(file, s))
		{
			auto idx = s.find(L' ');

			if (idx != std::wstring::npos)
			{
				std::transform(s.begin(), s.begin() + idx, s.begin(), ::toupper);
            }

			Descriptions.push_back(s);
		}

		file.close();
	}

	return false;
}


void FileExtensionHandler::Sort()
{
	std::sort(Extensions.begin(), Extensions.end(), sortByName);
}


bool FileExtensionHandler::SaveFileExtensionLists(const std::wstring path, bool mode)
{
/*
function TFileExtensionsObject.SaveFileExtensionLists(aSaveMode : boolean): boolean;
 var
  t,z,x,i : integer;
  Reg : TRegistry;
  tf : TextFile;

 begin
  Result := True;

  if aSaveMode = SaveLocationRegistry then begin

    Reg := TRegistry.Create(KEY_WRITE);
    try
      Reg.RootKey := HKEY_CURRENT_USER;

      for z := 0 to __FileCategoriesCount do begin
        Reg.OpenKey('\software\' + XinorbisRegistryKey + '\FileExt' + IntToStr(z), True);

        t := 1;

        for i := 0 to CategoryExtensions.Count - 1 do begin
          if CategoryExtensions[i].Category = z then begin
			Reg.WriteString('Ext' + IntToStr(t), CategoryExtensions[i].Name);

            inc(t);
          end;
        end;

        // remove any keys that shouldn't be there as they've been deleted / re-organised -------
        for x := t to 300 do begin
          Reg.DeleteValue('Ext' + IntToStr(x));
        end;
        // --------------------------------------------------------------------------------------
      end
    finally
      Reg.Free;
    end;

    Reg := TRegistry.Create(KEY_WRITE);
    try
      Reg.RootKey := HKEY_CURRENT_USER;
      Reg.OpenKey('\software\' + XinorbisRegistryKey + '\ChartColours', True);

      for t := 1 to __FileCategoriesCount do
        Reg.WriteInteger('ChartColour' + IntToStr(t), GSystemGlobal.FileCategoryColors[t]);
    finally
      Reg.Free;
    end;
  end
  else begin
    for z := 0 to __FileCategoriesCount do begin

	  AssignFile(tf, path + 'system\\config\\DefaultExtensions\\' + defaultextfn[z] + '.txt');

      {$I-}
      Rewrite(tf);

      if IOResult <> 0 then begin
        Result := False;

        TMSLogger.Error('Error saving "' + GSystemGlobal.ExePath + 'data\' + defaultextfn[z] + '.txt".');
      end
      else begin
        for i := 0 to CategoryExtensions.Count - 1 do begin
          if CategoryExtensions[i].Category = z then
            Writeln(tf, CategoryExtensions[i].Name);
        end;

        CloseFile(tf);
      end;
      {$I+}
    end;
  end;
end;*/

	return false; // to
}


int FileExtensionHandler::GetExtensionCategoryIDFromName(const std::wstring file_name)
{
	std::wstring ext = Utility::GetFileExtension(file_name);

	ExtensionSearch exi = GetExtensionCategoryID(ext);

	if (exi.Found)
	{
		return exi.Category;
	}

	return kFileCategoriesOther;
}


ExtensionSearch FileExtensionHandler::GetExtensionCategoryID(const std::wstring extension)
{
	ExtensionSearch extension_search;

	auto pos = std::find_if(Extensions.begin(), Extensions.end(),
							[extension](const FileExtension *fx) { return fx->Name == extension; });

	if (pos != Extensions.end())
	{
		extension_search.Found = true;
		extension_search.Category = (*pos)->Category;
		extension_search.Extension = std::distance(std::begin(Extensions), pos);

		return extension_search;
	}

	return extension_search;
}


int FileExtensionHandler::GetExtensionCategory(const std::wstring extension)
{
	auto pos = std::find_if(Extensions.begin(), Extensions.end(),
							[extension](const FileExtension* fx) { return fx->Name == extension; });

	if (pos != Extensions.end())
	{
		return (*pos)->Category;
	}

	return kFileCategoriesOther;
}


void FileExtensionHandler::ReportDuplicates()
{
	bool found = false;

	for (int z = 0; z < Extensions.size() - 1; z++)
	{
		int index = z + 1;

		while (index < Extensions.size() && Extensions[index]->Name == Extensions[z]->Name)
		{
			//GLog->Add( << L"Duplicate extension: " << Extensions[z]->Name << L" : " << __FileExtensionFileName[Extensions[z]->Category] << L" & " << __FileExtensionFileName[Extensions[index]->Category] << "\n";

			index++;

			found = true;
		}
	}
}
