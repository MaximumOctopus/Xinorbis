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

#pragma once


#include <string>

#include "DriveDetails.h"


namespace WindowsUtility
{
	[[nodiscard]] bool AddToContextMenu(const std::wstring);
	[[nodiscard]] bool RemoveFromContextMenu();
	
	[[nodiscard]] bool CreateFolder(const std::wstring&);
	
	[[nodiscard]] bool DirectoryExists(const std::wstring&);

	[[nodiscard]] bool FileExists(const std::wstring&);
	
	[[nodiscard]] std::wstring GetFileOwner(std::wstring);

	[[nodiscard]] std::wstring GetComputerNetName();
	[[nodiscard]] std::wstring GetUserFromWindows();

	[[nodiscard]] std::wstring GetDiskTypeString(const std::wstring&);
	[[nodiscard]] DriveDetails GetDriveDetails(const std::wstring&);

	[[nodiscard]] std::wstring GetExePath();
	[[nodiscard]] std::wstring GetDataFolder();

	[[nodiscard]] std::wstring GetEnvVariable(std::wstring);

	void ExecuteFile(const std::wstring, const std::wstring);

	std::wstring GetSpecialFolder(int);

	bool ShowFilePropertiesDialog(HWND, const std::wstring);
	bool BrowseForFolder(std::vector<std::wstring> &, bool, bool);

	bool CopyAllFiles(const std::wstring, const std::wstring);
	bool MoveAllFiles(const std::wstring, const std::wstring);

	bool SendToRecycleBin(const std::wstring);
}