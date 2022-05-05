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


#include "Utility.h"
#include "WindowsUtility.h"
#include <iostream>
#include <ShlObj.h>  
#include <string>
#include <windows.h>
#include <Lmcons.h>
#include <windows.h>
#include "accctrl.h"
#include "aclapi.h"


#pragma comment(lib, "advapi32.lib")


// returns 0 on success, 1 on fail
int WindowsUtility::CreateWFolder(const std::wstring& dirName_in)
{
	bool success = CreateDirectoryW(dirName_in.c_str(), NULL);

	if (success)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


bool WindowsUtility::DirectoryExists(LPCTSTR szPath)
{
	DWORD dwAttrib = GetFileAttributes(szPath);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		   (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}


bool WindowsUtility::DirectoryExistsWString(const std::wstring& dirName_in)
{
	DWORD ftyp = GetFileAttributesW(dirName_in.c_str());

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
	{
		return true;   // this is a directory!
	}

	//if (ftyp == INVALID_FILE_ATTRIBUTES)
//		return false;  //something is wrong with your path!

	return false;    // this is not a directory!
}


bool WindowsUtility::FileExists(const std::wstring& aFileName)
{
	if (FILE *file = _wfopen(aFileName.c_str(), L"r"))
	{
		fclose(file);
		
		return true;
	}
	else
	{
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

		wsValue += L"\\MaximumOctopus\\xinorbis";
	}

	return wsValue;
}

// https://stackoverflow.com/questions/4130180/how-to-use-vs-c-getenvironmentvariable-as-cleanly-as-possible
std::wstring WindowsUtility::GetEnvVariable(std::wstring aName)
{
	DWORD bufferSize = 65535;

	std::wstring value;

	value.resize(bufferSize);

	bufferSize = GetEnvironmentVariableW(aName.c_str(), &value[0], bufferSize);

	if (!bufferSize)
	{
		return L"";
	}

	value.resize(bufferSize);

	return value;
}


std::wstring WindowsUtility::GetFileOwner(std::wstring aFileName)
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
	hFile = CreateFile(aFileName.c_str(),	GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,	FILE_ATTRIBUTE_NORMAL, NULL);

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
	bRtnBool = LookupAccountSid(NULL,                   // name of local or remote computer
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
	wchar_t name[UNLEN + 1];
	DWORD size = UNLEN + 1;

	if (GetUserNameW((LPWSTR)name, &size))
	{
		std::wstring wname(name);

		return wname;
	}
	else
	{
		return L"Unknown";
	}
} 