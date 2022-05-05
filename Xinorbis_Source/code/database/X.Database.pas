{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: November 12th 2008
  Last Modified: January 11th 2020
}


unit X.Database;

interface

uses windows,  SysUtils, classes, AdvGrid, DB, Data.DbxSqlite,
     ADODB, htmltv,ComCtrls, X.Global, Data.SqlExpr,

     TMSLogging,

     X.LanguageHandler, X.CSizeOfFolder;


function  InitSqlite(const path : string): boolean;
function  InitODBC(const connectionstring : string): boolean;
procedure CloseODBC;
function  GetAllAvailableTables: TStringList;
function  TableExists(const tablename : string): boolean;
procedure InitialiseTreeWithFolders(const tablename : string; treeview : THTMLTreeView);
function  PopulateGridFromSQL(grid : TAdvStringGrid; const sql : string; option1 : integer; option2 : boolean): TSizeOfFolder;
procedure PopulateTreeFolder(const tablename : string; treeview : THTMLTreeView; node : TTreeNode; folder : string; folderID : integer);
procedure DeleteTable(const tablename : string);

function  ExportTableToCSV(const filename, tablename : string): boolean;
function  ExportTableToXML(const filename, tablename : string): boolean;

procedure PopulateXinFilesFromTable(const tablename : string);


implementation


uses shellapi, ShlObj, Forms, X.Utility,

     X.Settings, X.CFileObject, X.Constants, X.CUserData, X.Dialogs.Dialog, X.GlobalObjects,

     X.Database.Sqlite, X.Database.ODBC;


// =================================================================================================
// == ODBC Specific ================================================================================
// =================================================================================================


function  InitODBC(const connectionstring : string): boolean;
 begin
  Assert(connectionstring <> '', 'InitODBC :: Empty connnection string');

  Result := True;

  try
    XODBC := TADOConnection.Create(nil);
    XODBC.LoginPrompt      := False;
    XODBC.ConnectionString := connectionstring;
    XODBC.Connected        := True;
  except
    Result := False;
  end;
end;


procedure CloseODBC;
 begin
  if XODBC.Connected then
    XODBC.Close;

  XODBC.Free;
end;


// =================================================================================================
// =================================================================================================
// =================================================================================================


function InitSqlite(const path : string): boolean;
begin
  Result := DBSqlite.CreateEmptyFile(path);
end;


// =================================================================================================
// =================================================================================================
// =================================================================================================


function GetAllAvailableTables: TStringList;
begin
  Result := TStringList.Create;

  if XSettings.Database.UseODBC then begin
    try
      XODBC.GetTableNames(Result, False);
    finally
    end;
  end
  else begin
    DBSqlite.GetAllAvailableTables(Result);
  end;
end;


procedure DeleteTable(const tablename : string);
 begin
  TMSLogger.Info('Delete table "' + tablename + '".');

  if XSettings.Database.UseODBC then begin
    {}
  end
  else begin
    DBSqlite.DeleteTable(tablename);
  end;
end;


function TableExists(const tablename : string): boolean;
begin
  if XSettings.Database.UseODBC then begin
    Result := DBODBC.TableExists(tablename);
  end
  else begin
    Result := DBSqlite.TableExists(tablename);
  end;
end;


function PopulateGridFromSQL(grid : TAdvStringGrid; const sql : string; option1 : integer; option2 : boolean): TSizeOfFolder;
begin
  Assert(grid <> nil, 'PopulateGridFromSQL :: Nil grid');

  TMSLogger.Info('Populate Grid with sql:');
  TMSLogger.Info(sql);

  if XSettings.Database.UseODBC then begin
    Result := DBODBC.PopulateGridFromSQL(grid, sql, option1, option2);
  end
  else begin
    Result := DBSqlite.PopulateGridFromSQL(grid, sql, option1, option2);
  end;
end;


function ExportTableToXML(const filename, tablename : string): boolean;
begin
  TMSLogger.Info('Exporting table "' + tablename + '" to XML.');

  if XSettings.Database.UseODBC then begin
    Result := DBODBC.ExportTableToXML(filename, tablename);
  end
  else begin
    Result := DBSqlite.ExportTableToXML(filename, tablename);
  end;
end;


function ExportTableToCSV(const filename, tablename : string): boolean;
begin
  TMSLogger.Info('Exporting table "' + tablename + '" to CSV.');

  if XSettings.Database.UseODBC then begin
    Result := DBODBC.ExportTableToCSV(filename, tablename);
  end
  else begin
    Result := DBSqlite.ExportTableToCSV(filename, tablename);
  end;
end;


procedure PopulateXinFilesFromTable(const tablename : string);
var
  tud : TUserData;

begin
  Assert(tablename <> '', 'PopulateXinFilesFromTable :: Empty table');

  TMSLogger.Info('Populating Xinorbis files from table "' + tablename + '" to XML.');

  if XSettings.Database.UseODBC then begin
    DBODBC.PopulateXinFilesFromTable(tablename);
  end
  else begin
    DBSqlite.PopulateXinFilesFromTable(tablename);
  end;

  if GScanDetails[dataFolderHistory].Users.Count = 0 then begin
    tud      := TUserData.Create;
    tud.Name := XText[rsNOT_SPECIFIED];

    GScanDetails[dataFolderHistory].Users.Add(tud);

    GScanDetails[dataFolderHistory].Users[0].Data[XUserCount] := GScanDetails[dataFolderHistory].FileCount;
    GScanDetails[dataFolderHistory].Users[0].Data[XUserSize]  := GScanDetails[dataFolderHistory].TotalSize;
  end;
end;


procedure InitialiseTreeWithFolders(const tablename : string; treeview : THTMLTreeView);
begin
  TMSLogger.Info('Initialise Tree with folders, table "' + tablename + '" to XML.');

  if XSettings.Database.UseODBC then begin
    DBODBC.InitialiseTreeWithFolders(tablename, treeview);
  end
  else begin
    DBSqlite.InitialiseTreeWithFolders(tablename, treeview);
  end;
end;


procedure PopulateTreeFolder(const tablename : string; treeview : THTMLTreeView; node : TTreeNode; folder : string; folderID : integer);
begin
  TMSLogger.Info('Populate tree with table "' + tablename + '" to XML.');

  if XSettings.Database.UseODBC then begin
    DBODBC.PopulateTreeFolder(tablename, treeview, node, folder, folderID);
  end
  else begin
    DBSqlite.PopulateTreeFolder(tablename, treeview, node, folder, folderID);
  end;
end;


end.
