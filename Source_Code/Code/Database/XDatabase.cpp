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

#include "XDatabase.h"


bool XDatabase::InitODBC(const std::wstring connection_string)
{
/*  try
	{
		XODBC := TADOConnection.Create(nil);
		XODBC.LoginPrompt      := False;
		XODBC.ConnectionString := connectionstring;
		XODBC.Connected        := True;
	}
	catch(...)
	{
		Result := False;
	}*/

	return true;
}


bool XDatabase::InitSqlite(const std::wstring path)
{
//  Result := DBSqlite.CreateEmptyFile(path);

	return false;
}


void XDatabase::CloseODBC()
{
/*  if XODBC.Connected)
	{
		XODBC.Close;
	}

	XODBC.Free;*/
}

bool XDatabase::GetAllAvailableTables(std::vector<std::wstring> &data)
{
/*  Result := TStringList.Create;

	if XSettings.Database.UseODBC)
	{
		try
		{
			XODBC.GetTableNames(Result, False);
		}
		catch(...)
		{
		}
	}
	else
	{
		DBSqlite.GetAllAvailableTables(Result);
	} */

	return false;
}


bool XDatabase::TableExists(const std::wstring table_name)
{
/*  if XSettings.Database.UseODBC)
	{
		Result := DBODBC.TableExists(tablename);
	}
	else
	{
		Result := DBSqlite.TableExists(tablename);
	}*/

	return false;
}


void XDatabase::InitialiseTreeWithFolders(TTreeView *tree, const std::wstring table_name)
{
/*	if XSettings.Database.UseODBC)
	{
		DBODBC.InitialiseTreeWithFolders(tablename, treeview);
	}
	else
	{
		DBSqlite.InitialiseTreeWithFolders(tablename, treeview);
	} */
}


SizeOfFolder XDatabase::PopulateGridFromSQL(TStringGrid *grid, const std::wstring sql, int option1, bool option2)
{
	SizeOfFolder sof;

/*  if XSettings.Database.UseODBC)
	{
		Result := DBODBC.PopulateGridFromSQL(grid, sql, option1, option2);
	}
	else
	{
		Result := DBSqlite.PopulateGridFromSQL(grid, sql, option1, option2);
	}*/

	return sof;
}


void XDatabase::PopulateTreeFolder(TTreeView* tree, const std::wstring table_name, TTreeNode* node, const std::wstring folder, int folder_id)
{
/*  if XSettings.Database.UseODBC)
	{
		DBODBC.PopulateTreeFolder(tablename, treeview, node, folder, folderID);
	}
	else
	{
		DBSqlite.PopulateTreeFolder(tablename, treeview, node, folder, folderID);
	}      */
}


bool XDatabase::DeleteTable(const std::wstring table_name)
{
/*  if XSettings.Database.UseODBC)
	{
	}
	else
	{
		DBSqlite.DeleteTable(tablename);
	}*/

	return false;
}


bool XDatabase::ExportTableToCSV(const std::wstring file_name, const std::wstring table_name)
{
/*	if XSettings.Database.UseODBC)
	{
		Result := DBODBC.ExportTableToCSV(filename, tablename);
	}
	else
	{
		Result := DBSqlite.ExportTableToCSV(filename, tablename);
	}                   */

	return false;
}


bool XDatabase::ExportTableToXML(const std::wstring file_name, const std::wstring table_name)
{
/*	if XSettings.Database.UseODBC)
	{
		Result := DBODBC.ExportTableToXML(filename, tablename);
	}
	else
	{
		Result := DBSqlite.ExportTableToXML(filename, tablename);
	}*/

	return false;
}


void XDatabase::PopulateXinFilesFromTable(const std::wstring table_name)
{
/*  tud : TUserData;

	if XSettings.Database.UseODBC)
	{
		DBODBC.PopulateXinFilesFromTable(tablename);
	}
	else
	{
		DBSqlite.PopulateXinFilesFromTable(tablename);
	}

	if GScanDetails[dataFolderHistory].Users.Count = 0)
	{
		tud      := TUserData.Create;
		tud.Name := XText[rsNOT_SPECIFIED];

		GScanDetails[dataFolderHistory].Users.Add(tud);

		GScanDetails[dataFolderHistory].Users[0].Data[XUserCount] := GScanDetails[dataFolderHistory].FileCount;
		GScanDetails[dataFolderHistory].Users[0].Data[XUserSize]  := GScanDetails[dataFolderHistory].TotalSize;
	}*/
}
