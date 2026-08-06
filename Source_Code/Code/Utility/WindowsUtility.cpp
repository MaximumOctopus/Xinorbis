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

#include "accctrl.h"
#include "aclapi.h"
#include <filesystem>
#include <Lmcons.h>
#include <ShlObj.h>
#include <shobjidl.h>
#include <string>
#include <windows.h>
#include <vector>

#include "ConstantsData.h"
#include "Convert.h"
#include "DriveDetails.h"
#include "LanguageHandler.h"
#include "Registry.h"
#include "Utility.h"
#include "WindowsUtility.h"


//#pragma comment(lib, "advapi32.lib")


extern LanguageHandler* GLanguageHandler;


bool WindowsUtility::AddToContextMenu(const std::wstring path)
{
	try
	{
		HKEY hKey;

		LONG dwRet = RegOpenKeyEx(HKEY_CLASSES_ROOT,
			L"\\software\\maximumoctopus\\Xinorbis",
			NULL,
			KEY_SET_VALUE,
			&hKey);

		if (dwRet != ERROR_SUCCESS)
		{
			return false;
		}

		if (!Registry::WriteRegistryString(hKey, L"\\directory\\shell\\Xinorbis", L"Examine this folder with Xinorbis"))
		{
			//GLog->Add( << L"Unable to add \"\\directory\\shell\\Xinorbis\" to registry.\n";
		}

		if (!Registry::WriteRegistryString(hKey, L"\\directory\\shell\\Xinorbis\\Command", L"\"" + path + L"\" \"%1\""))
		{
		   //	GLog->Add( << L"Unable to add \"\\directory\\shell\\Xinorbis\\Command\" to registry.\n";
		}

		if (!Registry::WriteRegistryString(hKey, L"\\directory\\shell\\Xinorbis\\DefaultIcon", L"\"" + path + L", 0\""))
		{
			//GLog->Add( << L"Unable to add \"\\directory\\shell\\Xinorbis\\DefaultIcon\" to registry.\n";
		}
	}
	catch(...)
	{
		return false;
	}

	return true;
}


bool WindowsUtility::RemoveFromContextMenu()
{
	try
	{
		HKEY hKey;

		LONG dwRet = RegOpenKeyEx(HKEY_CLASSES_ROOT,
			L"\\software\\maximumoctopus\\FolderScanUltra",
			NULL,
			KEY_SET_VALUE,
			&hKey);

		if (dwRet != ERROR_SUCCESS)
		{
			return false;
		}

		if (!Registry::DeleteRegistry(hKey, L"\\directory\\shell\\FolderScanUltra"))
		{
		   //	GLog->Add( << L"Unable to delete \"\\directory\\shell\\FolderScanUltra\"\n";
		}

		if (!Registry::DeleteRegistry(hKey, L"\\directory\\shell\\FolderScanUltra\\Command"))
		{
		  //GLog->Add(<< L"Unable to delete \"\\directory\\shell\\FolderScanUltra\\Command\"\n";
		}

		if (!Registry::DeleteRegistry(hKey, L"\\directory\\shell\\FolderScanUltra\\DefaultIcon"))
		{
		  //GLog->Add(<< L"Unable to delete \"\\directory\\shell\\FolderScanUltra\\DefaultIcon\"\n";

		}
	}
	catch (...)
	{
		return false;
	}

	return true;
}


// returns 0 on success, 1 on fail
bool WindowsUtility::CreateFolder(const std::wstring& folder_name)
{
	try
	{
		return std::filesystem::create_directory(folder_name);
	}
	catch (const std::exception& e)
	{
		//GLog->Add( << e.what() << L"\n";

		return false;
	}
}


bool WindowsUtility::DirectoryExists(const std::wstring& folder_name)
{
	try
	{
		return std::filesystem::exists(folder_name);
	}
	catch (const std::exception& e)
	{
		//GLog->Add( << e.what() << L"\n";

		return false;
	}
}


bool WindowsUtility::FileExists(const std::wstring& file_name)
{
	try
	{
		return std::filesystem::exists(file_name);
	}
	catch (const std::exception& e)
	{
		//GLog->Add( << e.what() << L"\n";

		return false;
	}
}


std::wstring WindowsUtility::GetExePath()
{
    wchar_t result[MAX_PATH];

    GetModuleFileName( NULL, result, MAX_PATH );

	return Utility::SplitFileName(std::wstring(result)) + L"\\";
}


std::wstring WindowsUtility::GetComputerNetName()
{
	wchar_t buffer[MAX_COMPUTERNAME_LENGTH + 1] = { 0 };

	DWORD cchBufferSize = sizeof(buffer) / sizeof(buffer[0]);

	if (GetComputerNameW(buffer, &cchBufferSize))
	{
		return std::wstring(&buffer[0]);
	}

	return L"Unknown";
}


// http://msdn.microsoft.com/en-us/library/bb762494.aspx
std::wstring WindowsUtility::GetDataFolder()
{
	std::wstring wsValue = L"";

	wchar_t wzLocalAppData[MAX_PATH] = { 0 };

	if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, wzLocalAppData)))
	{
		wsValue = wzLocalAppData;

		wsValue += L"\\MaximumOctopus\\FolderScanUltra";
	}

	return wsValue;
}

// https://stackoverflow.com/questions/4130180/how-to-use-vs-c-getenvironmentvariable-as-cleanly-as-possible
std::wstring WindowsUtility::GetEnvVariable(std::wstring name)
{
	DWORD bufferSize = 65535;

	std::wstring value;

	value.resize(bufferSize);

	bufferSize = GetEnvironmentVariableW(name.c_str(), &value[0], bufferSize);

	if (!bufferSize)
	{
		return L"";
	}

	value.resize(bufferSize);

	return value;
}


std::wstring WindowsUtility::GetFileOwner(std::wstring file_name)
{
	DWORD dwRtnCode = 0;
	PSID pSidOwner = NULL;
	BOOL bRtnBool = TRUE;
	LPTSTR AcctName = NULL;
	LPTSTR DomainName = NULL;
	DWORD dwAcctName = 1024, dwDomainName = 1024;
	SID_NAME_USE eUse = SidTypeUnknown;
	HANDLE hFile;
	PSECURITY_DESCRIPTOR pSD = NULL;

	// Get the handle of the file object.
	hFile = CreateFile(file_name.c_str(),	GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,	FILE_ATTRIBUTE_NORMAL, NULL);

	// Check GetLastError for CreateFile error code.
	if (hFile == INVALID_HANDLE_VALUE) 
	{
		return L"";
	}

	// Get the owner SID of the file.
	dwRtnCode = GetSecurityInfo(hFile, SE_FILE_OBJECT, OWNER_SECURITY_INFORMATION, &pSidOwner, NULL, NULL, NULL, &pSD);

	// Check GetLastError for GetSecurityInfo error condition.
	if (dwRtnCode != ERROR_SUCCESS) 
	{
		return L"";
	}

	// Reallocate memory for the buffers.
	AcctName = (LPTSTR)GlobalAlloc(GMEM_FIXED, dwAcctName);

	// Check GetLastError for GlobalAlloc error condition.
	if (AcctName == NULL) 
	{
		return L"";
	}

	DomainName = (LPTSTR)GlobalAlloc(GMEM_FIXED, dwDomainName);

	// Check GetLastError for GlobalAlloc error condition.
	if (DomainName == NULL) 
	{
		return L"";
	}

	// Second call to LookupAccountSid to get the account name.
	bRtnBool = LookupAccountSidW(NULL,                   // name of local or remote computer
							 	 pSidOwner,              // security identifier
								 AcctName,               // account name buffer
								 (LPDWORD)&dwAcctName,   // size of account name buffer 
								 DomainName,             // domain name
								 (LPDWORD)&dwDomainName, // size of domain name buffer
								 &eUse);                 // SID type

	// Check GetLastError for LookupAccountSid error condition.
	if (bRtnBool == FALSE) 
	{
		return L"";
	}

	return std::wstring(AcctName);
}


std::wstring WindowsUtility::GetUserFromWindows()
{
	wchar_t name[UNLEN + 1] = L"";
	DWORD size = UNLEN + 1;

	if (GetUserNameW((LPWSTR)name, &size))
	{
		std::wstring wname(name);

		return wname;
	}

	return L"Unknown";
} 


// drive_root shoud be in the format n:
std::wstring WindowsUtility::GetDiskTypeString(const std::wstring& drive_root)
{
	if (!drive_root.empty() && drive_root != L"\\\\")
	{
		LPCWSTR cname;
		cname = drive_root.c_str() + '\\';

		int ret = GetDriveTypeW(cname);

		switch (ret)
		{
			case 0:               return GLanguageHandler->Text[kDriveCannotDetermind];
			case 1:               return GLanguageHandler->Text[kTheRootNotExist];
			case DRIVE_REMOVABLE: return GLanguageHandler->Text[kRemovable];
			case DRIVE_FIXED:     return GLanguageHandler->Text[kHardDisk];
			case DRIVE_REMOTE:    return GLanguageHandler->Text[kRemoteDrive];
			case DRIVE_CDROM:     return GLanguageHandler->Text[kCDROM];
			case DRIVE_RAMDISK:   return GLanguageHandler->Text[kRAMDisk];
		}
	}

	return GLanguageHandler->Text[kDriveCannotDetermind];
}


// drive_root shoud be in the format n:
DriveDetails WindowsUtility::GetDriveDetails(const std::wstring& drive_root)
{
	DriveDetails dd;

	if (!drive_root.empty() && drive_root != L"\\\\")
	{
		DWORD SectorsPerCluster, BytesPerSector, NumberOfFreeClusters, TotalNumberOfClusters;

		LPCWSTR cname;
		cname = drive_root.c_str() + '\\';

		if (GetDiskFreeSpace(cname,
			&SectorsPerCluster,
			&BytesPerSector,
			&NumberOfFreeClusters,
			&TotalNumberOfClusters))
		{
			dd.SectorsPerCluster = SectorsPerCluster;
			dd.BytesPerSector = BytesPerSector;
			dd.FreeClusters = NumberOfFreeClusters;
			dd.Clusters = TotalNumberOfClusters;

			dd.SectorSize = SectorsPerCluster * BytesPerSector;
		}

		auto constexpr maxLength = MAX_PATH + 1u;
		wchar_t volumeName[maxLength] = { 0 };
		DWORD maximumComponentLength = 0;
		DWORD SerialNumber = 0;
		DWORD fileSystemFlags = 0;
		wchar_t fileSystemNameBuffer[maxLength] = { 0 };

		if (GetVolumeInformationW(cname, volumeName, maxLength, &SerialNumber, &maximumComponentLength, &fileSystemFlags, fileSystemNameBuffer, maxLength))
		{
			dd.VolumeName = volumeName;
			dd.FileSystem = fileSystemNameBuffer;
			dd.SerialNumber = SerialNumber;
			dd.SerialNumberHex = Convert::IntToHex(SerialNumber, 8);
		}

		dd.Valid = true;
	}

	return dd;
}


void WindowsUtility::ExecuteFile(const std::wstring path, const std::wstring parameters)
{
	if (parameters.empty())
	{
		ShellExecute(0, L"open", path.c_str(), 0, 0 , SW_SHOW );
	}
	else
	{
		ShellExecute(0, L"open", path.c_str(), parameters.c_str(), 0 , SW_SHOW );
	}
}


// http://msdn.microsoft.com/en-us/library/bb762494.aspx
std::wstring WindowsUtility::GetSpecialFolder(int folder)
{          /*
var
  szPath: array [0..MAX_PATH] of Char;
  xcopy, temp : string;
  t : integer;
  go : boolean;

 begin
  Assert((xID >= 1) and (xID <= 11), 'GetSpecialFolder :: Invalid ID');

  case xID of
     1 : SHGetFolderPath(0, CSIDL_PROGRAM_FILES,    0, 0, @szPath[0]);
     2 : SHGetFolderPath(0, CSIDL_PROGRAM_FILESX86, 0, 0, @szPath[0]);
     3 : SHGetFolderPath(0, CSIDL_WINDOWS,          0, 0, @szPath[0]);
     4 : begin // users
           SHGetFolderPath(0, $0028, 0, 0, @szPath[0]);

           xcopy := SzPath;
           temp  := '';
           go    := false;

           t     := length(xcopy);

           while t > 0 do begin
             if go then
               temp := xcopy[t] + temp;

             if xcopy[t] = '\' then go := True;

             dec(t);
           end;
         end;
     5 : SHGetFolderPath(0, $0028, 0, 0, @szPath[0]);
     6 : SHGetFolderPath(0, $000D, 0, 0, @szPath[0]);
     7 : SHGetFolderPath(0, $0027, 0, 0, @szPath[0]);
     8 : SHGetFolderPath(0, $0005, 0, 0, @szPath[0]);
     9 : SHGetFolderPath(0, $000E, 0, 0, @szPath[0]);
    10 : begin
           ShGetSpecialFolderPath(0, szPath, $0028, FALSE);

           temp := szPath + '\xinorbis';
         end;
    11 : begin
           ShGetSpecialFolderPath(0, szPath, CSIDL_PERSONAL, FALSE);

           temp := szPath + '\MaximumOctopus\xinorbis';
         end;
  end;

  if (xID <> 4) and (xID < 10) then
    temp := SzPath;

  Result := temp + '\';      */

    return L"to do";
}


bool WindowsUtility::ShowFilePropertiesDialog(HWND handle, const std::wstring file_name)
{
	const wchar_t* widecstr = file_name.c_str();

	TShellExecuteInfo info;

	info.cbSize       = sizeof(info);
	info.fMask        = SEE_MASK_NOCLOSEPROCESS or SEE_MASK_INVOKEIDLIST or SEE_MASK_FLAG_NO_UI;
	info.hwnd         = handle;
	info.lpVerb       = L"properties";
	info.lpFile       = widecstr;
	info.lpParameters = NULL;
	info.lpDirectory  = NULL;
	info.nShow        = 0;
	info.hInstApp     = 0;
	info.lpIDList     = NULL;

	return ShellExecuteEx(&info);
}


// based on code from here https://gist.github.com/0xF5T9/3f3203950f480d348aa6d99850a26016
bool WindowsUtility::BrowseForFolder(std::vector<std::wstring> &paths, bool selectFolder, bool multiSelect)
{
    IFileOpenDialog *p_file_open = nullptr;
	bool are_all_operation_success = false;
    while (!are_all_operation_success)
    {
        HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
                                      IID_IFileOpenDialog, reinterpret_cast<void **>(&p_file_open));
        if (FAILED(hr))
            break;

        if (selectFolder || multiSelect)
        {
            FILEOPENDIALOGOPTIONS options = 0;
            hr = p_file_open->GetOptions(&options);
            if (FAILED(hr))
                break;

            if (selectFolder)
                options |= FOS_PICKFOLDERS;
            if (multiSelect)
                options |= FOS_ALLOWMULTISELECT;

            hr = p_file_open->SetOptions(options);
            if (FAILED(hr))
                break;
        }

        hr = p_file_open->Show(NULL);
        if (hr == HRESULT_FROM_WIN32(ERROR_CANCELLED)) // No items were selected.
		{
            are_all_operation_success = true;
            break;
        }
        else if (FAILED(hr))
            break;

        IShellItemArray *p_items;
        hr = p_file_open->GetResults(&p_items);
        if (FAILED(hr))
            break;
        DWORD total_items = 0;
        hr = p_items->GetCount(&total_items);
        if (FAILED(hr))
            break;

        for (int i = 0; i < static_cast<int>(total_items); ++i)
        {
            IShellItem *p_item;
            p_items->GetItemAt(i, &p_item);
            if (SUCCEEDED(hr))
            {
                PWSTR path;
                hr = p_item->GetDisplayName(SIGDN_FILESYSPATH, &path);
                if (SUCCEEDED(hr))
                {
                    paths.push_back(path);
                    CoTaskMemFree(path);
                }
                p_item->Release();
            }
        }

        p_items->Release();
        are_all_operation_success = true;
    }

    if (p_file_open)
        p_file_open->Release();
    return are_all_operation_success;
}


bool WindowsUtility::CopyAllFiles(const std::wstring PathFrom, const std::wstring PathTo)
{
	TSHFileOpStruct FOS;

	ZeroMemory(&FOS, sizeof(FOS));

	FOS.wFunc  = FO_COPY;
	FOS.fFlags = FOF_ALLOWUNDO || FOF_SIMPLEPROGRESS;
	FOS.pFrom  = (PathFrom + L"*.*\0").c_str();
	FOS.pTo    = (PathTo + L"\0").c_str();

	return (SHFileOperationW(&FOS) == 0);
}


bool WindowsUtility::MoveAllFiles(const std::wstring PathFrom, const std::wstring PathTo)
{
	TSHFileOpStruct FOS;

	ZeroMemory(&FOS, sizeof(FOS));

	FOS.wFunc  = FO_MOVE;
	FOS.fFlags = FOF_ALLOWUNDO || FOF_SIMPLEPROGRESS;
	FOS.pFrom  = (PathFrom + L"*.*\0").c_str();
	FOS.pTo    = (PathTo + L"\0").c_str();

	return (SHFileOperationW(&FOS) == 0);
}


bool WindowsUtility::SendToRecycleBin(const std::wstring file_name)
{
	const wchar_t* widecstr = file_name.c_str();

	SHFILEOPSTRUCT fileOp;
	fileOp.hwnd = NULL;
	fileOp.wFunc = FO_DELETE;
	fileOp.pFrom = widecstr;
	fileOp.pTo = NULL;
	fileOp.fFlags = FOF_ALLOWUNDO | FOF_NOERRORUI | FOF_NOCONFIRMATION | FOF_SILENT;

	int result = SHFileOperation(&fileOp);

	if (result == 0)
	{
		return true;
	}

	return false;
}
