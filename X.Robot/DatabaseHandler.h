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
// February 9th 2019
//


#pragma once


#include <string>

#include "DatabaseODBC.h"
#include "DatabaseSQlite.h"


class DatabaseHandler
{
private:

	int dbMode;

	DatabaseODBC* dbODBC;
	DatabaseSQlite* dbSQlite;

	bool InitSQlite(std::wstring SQliteFileName);
	bool InitODBC(std::wstring connectionString);

	bool UpdateXinorbisScanHistoryIni(std::wstring folder, std::wstring usersPath);
	bool UpdateXinorbisScanHistoryRegistry(std::wstring folder, std::wstring usersPath);

public:

	bool initOK;

	bool UpdateFolderHistory(std::wstring tableFolder, std::wstring tableFile);
	bool UpdateFolderHistoryFile(void);
	bool UpdateXinorbisScanHistory(int saveLocation, std::wstring folder, std::wstring usersPath);

	bool UpdateFolderHistoryStructured(std::wstring tableSystem, std::wstring tableData);

	DatabaseHandler(int mode, std::wstring SQliteFileName);
	~DatabaseHandler();
};