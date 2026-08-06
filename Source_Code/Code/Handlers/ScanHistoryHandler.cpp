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

#include <fstream>

#include "ScanHistoryHandler.h"

ScanHistoryHandler *GScanHistoryHandler;


void ScanHistoryHandler::Add(const std::wstring path, const std::wstring exclude_files, const std::wstring exclude_folders)
{
	//
}

			  // GSystemGlobal.AppDataPath + 'scanhistory.dat'
bool ScanHistoryHandler::Load(const std::wstring path, bool from_file)
{
	if (from_file)
	{
		std::wifstream file(path);

		if (file)
		{
			int param = 0;
            std::wstring s = L"";

			int Date = 19990101;   			// yyyymmdd
			std::wstring Time = L"00:00";   // hhmm
			std::wstring Path = L"";
			std::wstring ExcludeFiles = L"";
			std::wstring ExcludeFolders = L"";

			while (std::getline(file, s))
			{
				switch (param)
				{
				case 0:
					Path = s;
					break;
				case 1:
					Date = stoi(s);
					break;
				case 2:
					Time = s;
					break;
				case 3:
					ExcludeFiles = s;
					break;
				case 4:
				{
					ExcludeFolders = s;

					ScanHistoryItem *shi = new ScanHistoryItem();
					shi->Path = Path;
					shi->Date = Date;
					shi->Time = Time;
					shi->ExcludeFiles = ExcludeFiles;
					shi->ExcludeFolders = ExcludeFolders;

					History.push_back(shi);

					break;
				}
				}

				if (param == 4)
				{
					param = 0;
				}
				else
				{
					param++;
				}
			}

			file.close();

            return true;
		}
	}
	else
	{ /*
		FReg := TRegistry.Create(KEY_READ);

		try
		  FReg.RootKey := HKEY_CURRENT_USER;
		  FReg.OpenKey('\software\' + XinorbisRegistryKey + '\SinglePaths', True);

		  t := 0;
		  While FReg.ValueExists('PathX' + IntToStr(t)) do begin
			tsho := TScanHistoryObject.Create;

			tsho.Path           := FReg.ReadString('PathX' + IntToStr(t));
			tsho.DateI          := StrToIntDef(FReg.ReadString('PathY' + IntToStr(t)), 19000101);
			tsho.TimeI          := FReg.ReadString('PathZ' + IntToStr(t));
			tsho.ExcludeFiles   := FReg.ReadString('PathE1' + IntToStr(t));
			tsho.ExcludeFolders := FReg.ReadString('PathE2' + IntToStr(t));

			ScanHistory.Add(tsho);

			inc(t);
		  end;

		finally
		  FReg.Free; */
	}

	return false;
}


void ScanHistoryHandler::Clear()
{
	History.clear();

/*	Reg = TRegistry.Create(KEY_WRITE);

	try
	  Reg.RootKey = HKEY_CURRENT_USER;
	  Reg.DeleteKey('\software\' + XinorbisRegistryKey + L"\SinglePaths');
	finally
	 Reg.Free;
	end;
  end; TO DO DO DO */
}


bool ScanHistoryHandler::Save(const std::wstring path, bool from_file)
{
    return false;
}
