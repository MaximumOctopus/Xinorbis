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
// February 18th 2019
//


#include <iostream> 
#include <string.h>

#include "Convert.h"
#include "DatabaseODBC.h"
#include "LanguageHandler.h"
#include "ScanDetails.h"


extern LanguageHandler* GLanguageHandler;
extern ScanDetails* GScanDetails;


DatabaseODBC::DatabaseODBC(std::wstring &connectionString)
{
	dbAvailable = CreateConnection(connectionString);

	if (dbAvailable)
	{
		std::wcout << L"ODBC connection open!" << std::endl;
	}
	else
	{
		std::wcout << L"ODBC connection fail :(" << std::endl;
	}
}


DatabaseODBC::~DatabaseODBC()
{
	SQLFreeHandle(SQL_HANDLE_STMT, hSqlStatement);
	SQLDisconnect(hSqlConnection);
	SQLFreeHandle(SQL_HANDLE_DBC, hSqlConnection);
	SQLFreeHandle(SQL_HANDLE_ENV, hSqlEnv);
}


bool DatabaseODBC::CreateConnection(std::wstring &connectionString)
{
	if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hSqlEnv))
	{

		if (SQL_SUCCESS == SQLSetEnvAttr(hSqlEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		{

			if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_DBC, hSqlEnv, &hSqlConnection))
			{

				SQLWCHAR retconstring[1024];

				SQLRETURN sdc = SQLDriverConnectW(hSqlConnection,
											  	  NULL,
												  (SQLWCHAR *)connectionString.c_str(),
												  SQL_NTS,
												  retconstring,
												  1024,
												  NULL,
												  SQL_DRIVER_NOPROMPT);

				switch (sdc)
				{
				case SQL_SUCCESS_WITH_INFO:
					
					ShowError(SQL_HANDLE_DBC, hSqlStatement);
					
					break;
				case SQL_INVALID_HANDLE:
				case SQL_ERROR:
					
					ShowError(SQL_HANDLE_DBC, hSqlConnection);

					return false;
				default:
					break;
				}

				if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_STMT, hSqlConnection, &hSqlStatement))
				{

				}
			}
		}
	}


	return true;
}


void DatabaseODBC::ShowError(unsigned int handletype, const SQLHANDLE& handle) 
{
	SQLWCHAR sqlstate[1024];
	SQLWCHAR message[1024];

	if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL))
	{
		std::wcout << L"    ODBC ERROR : " << message << L"\n    SQLSTATE: " << sqlstate << std::endl;
	}
}


bool DatabaseODBC::CreateNewFileTable(std::wstring tableName)
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

	if (SQL_SUCCESS == SQLExecDirect(hSqlStatement, (SQLWCHAR *)sql.c_str(), SQL_NTS)) 
	{
		ShowError(SQL_HANDLE_STMT, hSqlStatement);
	}

	return false;
}


bool DatabaseODBC::CreateNewFolderTable(std::wstring tableName)
{
	std::wstring sql = L"CREATE TABLE \"" + tableName + L"\" (ID INTEGER PRIMARY KEY, FilePath VARCHAR (1024));";

	if (SQL_SUCCESS == SQLExecDirect(hSqlStatement, (SQLWCHAR *)sql.c_str(), SQL_NTS))
	{
		ShowError(SQL_HANDLE_STMT, hSqlStatement);
	}

	return false;
}


bool DatabaseODBC::PopulateFileTable(std::wstring tableName)
{
	std::wcout << L"Populating File table..." << std::endl;

	std::wstring stem = L"INSERT INTO \"" + tableName + L"\" (FilePath, FilePathIdx, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner) VALUES (";
	std::wstring sql;

	for (int t = 0; t < GScanDetails->Folders.size(); t++)
	{
		sql = stem + L"\"" + GScanDetails->Folders[GScanDetails->Files[t].FilePathIndex] + L"\", " +
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

		if (SQL_SUCCESS == SQLExecDirect(hSqlStatement, (SQLWCHAR *)sql.c_str(), SQL_NTS))
		{
			ShowError(SQL_HANDLE_STMT, hSqlStatement);

			return false;
		}
	}

	return true;
}


bool DatabaseODBC::PopulateFolderTable(std::wstring tableName)
{
	std::wcout << L"Populating Folder table..." << std::endl;

	std::wstring stem = L"INSERT INTO \"" + tableName + L"\" (FilePath) VALUES (\"";
	std::wstring sql;



	for (int t = 0; t < GScanDetails->Folders.size(); t++)
	{
		sql = stem + GScanDetails->Folders[t] + L"\");";

		if (SQL_SUCCESS == SQLExecDirect(hSqlStatement, (SQLWCHAR *)sql.c_str(), SQL_NTS))
		{
			ShowError(SQL_HANDLE_STMT, hSqlStatement);

			return false;
		}
	}


	
	return false;
}

// ======================================================================================================
// ======================================================================================================
// ======================================================================================================

bool DatabaseODBC::CreateNewDataTable(std::wstring tableName)
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

	if (SQL_SUCCESS == SQLExecDirect(hSqlStatement, (SQLWCHAR *)sql.c_str(), SQL_NTS))
	{
		ShowError(SQL_HANDLE_STMT, hSqlStatement);
	}

	return false;
}


bool DatabaseODBC::CreateNewSystemTable(std::wstring tableName)
{
	std::wstring sql = L"CREATE TABLE \"" + tableName + L"\" (ID INTEGER PRIMARY KEY, " +
		L"TableName VARCHAR (255), " +
		L"Folder VARCHAR (1024), " +
		L"SizeString VARCHAR (100), " +
		L"Size BIGINT, " +
		L"Files INT, " +
		L"Folders INT, " +
		L"ScanData BIGINT);";
	
	if (SQL_SUCCESS == SQLExecDirect(hSqlStatement, (SQLWCHAR *)sql.c_str(), SQL_NTS))
	{
		ShowError(SQL_HANDLE_STMT, hSqlStatement);
	}

	return false;
}


bool DatabaseODBC::PopulateDataTable(std::wstring tableName)
{
	std::wcout << L"Populating Data table..." << std::endl << std::endl;

	std::wstring stem = L"INSERT INTO \"" + tableName + L"\" (FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner, ScanDate) VALUES (";
	std::wstring sql;


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

		if (SQL_SUCCESS == SQLExecDirect(hSqlStatement, (SQLWCHAR *)sql.c_str(), SQL_NTS))
		{
			ShowError(SQL_HANDLE_STMT, hSqlStatement);

			return false;
		}
	}

	
	return false;
}


bool DatabaseODBC::PopulateSystemTable(std::wstring tableName, std::wstring dataTableName)
{
	std::wcout << L"Populating System table..." << std::endl << std::endl;

	std::wstring stem = L"INSERT INTO \"" + tableName + L"\" (TableName, Folder, SizeString, Size, Files, Folders, ScanDate) VALUES (\"";
	std::wstring sql;


	for (int t = 0; t < GScanDetails->Folders.size(); t++)
	{
		sql = stem + L"\"" + dataTableName + L"\", " +
			L"\"" + GScanDetails->ScanPath + L"\", " +
			L"\"" + Convert::ConvertToUsefulUnit(GScanDetails->TotalSize) + L"\", " +
			std::to_wstring(GScanDetails->TotalSize) + L", " +
			std::to_wstring(GScanDetails->FileCount) + L", " +
			std::to_wstring(GScanDetails->FolderCount) + L", " +
			GScanDetails->ScanDateInt + L");";

		if (SQL_SUCCESS == SQLExecDirect(hSqlStatement, (SQLWCHAR *)sql.c_str(), SQL_NTS))
		{
			ShowError(SQL_HANDLE_STMT, hSqlStatement);

			return false;
		}
	}


	return false;
}