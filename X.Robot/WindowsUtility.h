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
// January 30th 2019
//


#pragma once


#include <string>
#include <windows.h>


namespace WindowsUtility
{
	int CreateWFolder(const std::wstring& dirName_in);
	
	bool DirectoryExists(LPCTSTR szPath);
	bool DirectoryExistsWString(const std::wstring& dirName_in);

	bool FileExists(const std::wstring& aFileName);
	
	std::wstring GetFileOwner(std::wstring aFileName);

	std::wstring GetComputerNetName();
	std::wstring GetUserFromWindows();

	std::wstring GetExePath();
	std::wstring GetDataFolder();

	std::wstring GetEnvVariable(std::wstring aName);
}