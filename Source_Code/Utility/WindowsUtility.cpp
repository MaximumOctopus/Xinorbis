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
#include <string>
#include <windows.h>

#include "ConstantsData.h"
#include "Convert.h"
#include "DriveDetails.h"
#include "LanguageHandler.h"
#include "Registry.h"
#include "Utility.h"
#include "WindowsUtility.h"


//#pragma comment(lib, "advapi32.lib")


extern LanguageHandler* GLanguageHandler;


bool WindowsUtility::AddToContextMenu(std::wstring path)
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

		if (!Registry::WriteRegistryString(hKey, L"\\directory\\shell\\FolderScanUltra", L"Examine this folder with FolderScanUltra"))
		{
			//GLog->Add( << L"Unable to add \"\\directory\\shell\\FolderScanUltra\" to registry.\n";
		}

		if (!Registry::WriteRegistryString(hKey, L"\\directory\\shell\\FolderScanUltra\\Command", L"\"" + path + L"\" \"%1\" \"/pause\""))
		{
		   //	GLog->Add( << L"Unable to add \"\\directory\\shell\\FolderScanUltra\\Command\" to registry.\n";
		}

		if (!Registry::WriteRegistryString(hKey, L"\\directory\\shell\\FolderScanUltra\\DefaultIcon", L"\"" + path + L", 0\""))
		{
			//GLog->Add( << L"Unable to add \"\\directory\\shell\\FolderScanUltra\\DefaultIcon\" to registry.\n";
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

    return Utility::SplitFilename(std::wstring(result)) + L"\\";
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


bool WindowsUtility::SendToRecycleBin(const std::wstring file_name)
{
    return false;
}
