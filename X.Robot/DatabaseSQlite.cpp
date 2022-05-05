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
// February 15th 2019
//


#include <iostream> 
#include <string.h>

#include "Convert.h"
#include "DatabaseSQlite.h"
#include "LanguageHandler.h"
#include "ScanDetails.h"
#include "sqlite3.h"


extern LanguageHandler* GLanguageHandler;
extern ScanDetails* GScanDetails;


DatabaseSQlite::DatabaseSQlite(std::wstring fileName)
{
	dbFileName  = fileName;

	dbAvailable = CreateConnection();

	if (dbAvailable)
	{
		std::wcout << L"SQlite connection open!" << std::endl;
		std::wcout << L"       " << dbFileName << std::endl << std::endl;
	}
	else
	{
		std::wcout << L"SQlite connection fail :(" << std::endl;
		std::wcout << L"       " << dbFileName << std::endl << std::endl;
	}
}


DatabaseSQlite::~DatabaseSQlite()
{
	sqlite3_close(db);
}


bool DatabaseSQlite::CreateConnection(void)
{
	int rc = sqlite3_open16(dbFileName.c_str(), &db);

	if (rc)
	{
		return false;
	}

	return true;
}


bool DatabaseSQlite::CreateNewFileTable(std::wstring tableName)
{
	std::wstring sql = L"CREATE TABLE \"" + tableName + L"\" (ID INTEGER PRIMARY KEY, " +
									                  L"FilePath VARCHAR (1024), " +
													  L"FilePathIdx INTEGER, " +
													  L"FileName VARCHAR (255), " +
													  L"FileSize INTEGER, " +
													  L"FileSizeDisk INTEGER, " +
												      L"FileDateC INTEGER, " +
													  L"FileDateA INTEGER, " +
													  L"FileDateM INTEGER, " +
													  L"Category INTEGER, " +
													  L"Directory INTEGER, " +
													  L"Readonly INTEGER, " +
													  L"Hidden INTEGER, " +
													  L"System INTEGER, " +
												      L"Archive INTEGER, " +
													  L"Temp INTEGER, " +
											          L"Owner VARCHAR (255));";
	
	sqlite3_stmt* stmt;
	
	int rc = sqlite3_prepare16_v2(db, sql.c_str(), -1, &stmt, NULL);

	if (rc)
	{
		std::wcout << L"SQLite create file table fail: " << sqlite3_errmsg(db) << std::endl;

		return false;
	}
	
	rc = sqlite3_step(stmt);

	if (rc != SQLITE_DONE)
	{
		std::wcout << L"SQLite create file table fail: " << sqlite3_errmsg(db) << std::endl;

		return false;
	}

	std::wcout << L"SQlite created File table" << std::endl;

	sqlite3_finalize(stmt);

	return true;
}


bool DatabaseSQlite::CreateNewFolderTable(std::wstring tableName)
{
	std::wstring sql = L"CREATE TABLE \"" + tableName + L"\" (ID INTEGER PRIMARY KEY, FilePath VARCHAR (1024));";

	sqlite3_stmt* stmt;

	int rc = sqlite3_prepare16_v2(db, sql.c_str(), -1, &stmt, NULL);

	if (rc)
	{
		std::wcout << L"SQLite create folder table fail: " << sqlite3_errmsg(db) << std::endl;

		return false;
	}

	rc = sqlite3_step(stmt);

	if (rc != SQLITE_DONE)
	{
		std::wcout << L"SQLite create folder table fail: " << sqlite3_errmsg(db) << std::endl;

		return false;
	}

	std::wcout << L"SQlite created Folder table" << std::endl;

	sqlite3_finalize(stmt);

	return true;
}


bool DatabaseSQlite::PopulateFileTable(std::wstring tableName)
{
	std::wcout << L"Populating File table..." << std::endl;

	std::wstring stem = L"INSERT INTO \"" + tableName + L"\" (FilePath, FilePathIdx, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner) VALUES (";
	std::wstring sql;

	sqlite3_stmt* stmt;

	for (int t = 0; t < GScanDetails->Folders.size(); t++)
	{
		sql = stem +	L"\"" + GScanDetails->Folders[GScanDetails->Files[t].FilePathIndex] + L"\", " +
						std::to_wstring(GScanDetails->Files[t].FilePathIndex) + L", " +
						L"\"" + GScanDetails->Files[t].FileName + L"\", " +
						std::to_wstring(GScanDetails->Files[t].Size) + L", " +
						std::to_wstring(GScanDetails->Files[t].SizeOnDisk) + L", " +
						std::to_wstring(GScanDetails->Files[t].FileDateC) + L", " +
						std::to_wstring(GScanDetails->Files[t].FileDateA) + L", " +
						std::to_wstring(GScanDetails->Files[t].FileDateM) + L", " +
						std::to_wstring(GScanDetails->Files[t].Category) + L", " +
						Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_DIRECTORY) + L", " +
						Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_READONLY) + L", " +
						Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_HIDDEN) + L", " +
						Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_SYSTEM) + L", " +
						Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_ARCHIVE) + L", " +
						Convert::BoolToString(GScanDetails->Files[t].Temp) + L", " +
						L"\"" + GScanDetails->Users[GScanDetails->Files[t].Owner].Name + L"\");";

		int rc = sqlite3_prepare16_v2(db, sql.c_str(), -1, &stmt, NULL);

		if (rc)
		{
			std::wcout << L"SQLite populate file table fail: " << sqlite3_errmsg(db) << std::endl;

			return false;
		}

		rc = sqlite3_step(stmt);

		if (rc != SQLITE_DONE)
		{
			std::wcout << L"SQLite populate file table fail: " << sqlite3_errmsg(db) << std::endl;

			return false;
		}


		sqlite3_finalize(stmt);
	}

	return true;
}


bool DatabaseSQlite::PopulateFolderTable(std::wstring tableName)
{
	std::wcout << L"Populating Folder table..." << std::endl;

	std::wstring stem = L"INSERT INTO \"" + tableName + L"\" (FilePath) VALUES (\"";
	std::wstring sql;

	sqlite3_stmt* stmt;

	for (int t = 0; t < GScanDetails->Folders.size(); t++)
	{
		sql = stem + GScanDetails->Folders[t] + L"\");";

		int rc = sqlite3_prepare16_v2(db, sql.c_str(), -1, &stmt, NULL);

		if (rc)
		{
			std::wcout << L"SQLite populate folder table fail: " << sqlite3_errmsg(db) << std::endl;

			return false;
		}

		rc = sqlite3_step(stmt);

		if (rc != SQLITE_DONE)
		{
			std::wcout << L"SQLite populate folder table fail: " << sqlite3_errmsg(db) << std::endl;

			return false;
		}


		sqlite3_finalize(stmt);
	}

	return true;
}

// ======================================================================================================
// ======================================================================================================
// ======================================================================================================

bool DatabaseSQlite::CreateNewDataTable(std::wstring tableName)
{
	std::wstring sql = L"CREATE TABLE \"" + tableName + L"\" (ID INTEGER PRIMARY KEY, " +
		L"FilePath VARCHAR (1024), " +
		L"FileName VARCHAR (255), " +
		L"FileSize BIGINT, " +
		L"FileSizeDisk BIGINT, " +
		L"FileDateC INTEGER, " +
		L"FileDateA INTEGER, " +
		L"FileDateM INTEGER, " +
		L"Category INTEGER, " +
		L"Directory INTEGER, " +
		L"Readonly INTEGER, " +
		L"Hidden INTEGER, " +
		L"System INTEGER, " +
		L"Archive INTEGER, " +
		L"Temp INTEGER, " +
		L"Owner VARCHAR (255), " +
		L"ScanDate BIGINT);";

	sqlite3_stmt* stmt;

	int rc = sqlite3_prepare16_v2(db, sql.c_str(), -1, &stmt, NULL);

	if (rc)
	{
		std::wcout << L"SQLite create data table fail: " << sqlite3_errmsg(db) << std::endl;

		return false;
	}

	rc = sqlite3_step(stmt);

	if (rc != SQLITE_DONE)
	{
		std::wcout << L"SQLite create data table fail: " << sqlite3_errmsg(db) << std::endl;

		return false;
	}

	std::wcout << L"SQlite created data table" << std::endl;

	sqlite3_finalize(stmt);

	return true;
}


bool DatabaseSQlite::CreateNewSystemTable(std::wstring tableName)
{
	std::wstring sql = L"CREATE TABLE \"" + tableName + L"\" (ID INTEGER PRIMARY KEY, " +
														L"TableName VARCHAR (255), " +
														L"Folder VARCHAR (1024), " +
														L"SizeString VARCHAR (100), " +
														L"Size BIGINT, " +
														L"Files INT, " +
														L"Folders INT, " +
														L"ScanData BIGINT);";

	sqlite3_stmt* stmt;

	int rc = sqlite3_prepare16_v2(db, sql.c_str(), -1, &stmt, NULL);

	if (rc)
	{
		std::wcout << L"SQLite create system table fail: " << sqlite3_errmsg(db) << std::endl;

		return false;
	}

	rc = sqlite3_step(stmt);

	if (rc != SQLITE_DONE)
	{
		std::wcout << L"SQLite create system table fail: " << sqlite3_errmsg(db) << std::endl;

		return false;
	}

	std::wcout << L"SQlite created system table" << std::endl;

	sqlite3_finalize(stmt);

	return true;
}


bool DatabaseSQlite::PopulateDataTable(std::wstring tableName)
{
	std::wcout << L"Populating Data table..." << std::endl << std::endl;

	std::wstring stem = L"INSERT INTO \"" + tableName + L"\" (FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner, ScanDate) VALUES (";
	std::wstring sql;

	sqlite3_stmt* stmt;

	for (int t = 0; t < GScanDetails->Folders.size(); t++)
	{
		sql = stem + L"\"" + GScanDetails->Folders[GScanDetails->Files[t].FilePathIndex] + L"\", " +
			L"\"" + GScanDetails->Files[t].FileName + L"\", " +
			std::to_wstring(GScanDetails->Files[t].Size) + L", " +
			std::to_wstring(GScanDetails->Files[t].SizeOnDisk) + L", " +
			std::to_wstring(GScanDetails->Files[t].FileDateC) + L", " +
			std::to_wstring(GScanDetails->Files[t].FileDateA) + L", " +
			std::to_wstring(GScanDetails->Files[t].FileDateM) + L", " +
			std::to_wstring(GScanDetails->Files[t].Category) + L", " +
			Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_DIRECTORY) + L", " +
			Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_READONLY) + L", " +
			Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_HIDDEN) + L", " +
			Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_SYSTEM) + L", " +
			Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_ARCHIVE) + L", " +
			Convert::BoolToString(GScanDetails->Files[t].Temp) + L", " +
			L"\"" + GScanDetails->Users[GScanDetails->Files[t].Owner].Name + L"\", " +
			GScanDetails->ScanDateInt + L");";

		int rc = sqlite3_prepare16_v2(db, sql.c_str(), -1, &stmt, NULL);

		if (rc)
		{
			std::wcout << L"SQLite populate Data table fail: " << sqlite3_errmsg(db) << std::endl;

			return false;
		}

		rc = sqlite3_step(stmt);

		if (rc != SQLITE_DONE)
		{
			std::wcout << L"SQLite populate Data table fail: " << sqlite3_errmsg(db) << std::endl;

			return false;
		}


		sqlite3_finalize(stmt);
	}

	return true;
}


bool DatabaseSQlite::PopulateSystemTable(std::wstring tableName, std::wstring dataTableName)
{
	std::wcout << L"Populating System table..." << std::endl << std::endl;

	std::wstring stem = L"INSERT INTO \"" + tableName + L"\" (TableName, Folder, SizeString, Size, Files, Folders, ScanDate) VALUES (\"";
	std::wstring sql;

	sqlite3_stmt* stmt;

	for (int t = 0; t < GScanDetails->Folders.size(); t++)
	{
		sql = stem + L"\"" + dataTableName + L"\", " +
			L"\"" + GScanDetails->ScanPath + L"\", " +
			L"\"" + Convert::ConvertToUsefulUnit(GScanDetails->TotalSize) + L"\", " +
			std::to_wstring(GScanDetails->TotalSize) + L", " +
			std::to_wstring(GScanDetails->FileCount) + L", " +
			std::to_wstring(GScanDetails->FolderCount) + L", " +
			GScanDetails->ScanDateInt + L");";
			
		int rc = sqlite3_prepare16_v2(db, sql.c_str(), -1, &stmt, NULL);

		if (rc)
		{
			std::wcout << L"SQLite populate system table fail: " << sqlite3_errmsg(db) << std::endl;

			return false;
		}

		rc = sqlite3_step(stmt);

		if (rc != SQLITE_DONE)
		{
			std::wcout << L"SQLite populate system table fail: " << sqlite3_errmsg(db) << std::endl;

			return false;
		}


		sqlite3_finalize(stmt);
	}

	return true;
}