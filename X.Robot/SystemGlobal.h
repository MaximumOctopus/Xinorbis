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


class SystemGlobal
{
public:
    int InitOkay = 0;

    int DriveSpaceMax;
    int DriveSpaceFree;
    int DriveSectorSize;

    std::wstring AppPath;
    std::wstring UsersPath;

	SystemGlobal(int argc, wchar_t *argv[]);

    void InitialiseXinorbis();
    bool InstallationCheck();
	bool CheckFolderStructure();
	void UpdateDriveDetails(std::wstring folder);
	std::wstring SystemGlobal::GetUsersPath(std::wstring appPath);
};