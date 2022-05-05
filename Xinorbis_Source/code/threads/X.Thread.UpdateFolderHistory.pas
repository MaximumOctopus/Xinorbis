{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Thread.UpdateFolderHistory;

interface

uses
  StdCtrls, SysUtils, classes, AdvGrid, ADODB, Data.DB, Data.SqlExpr, Data.DbxSqlite, Data.DBXCommon,

  SyncObjs,

  TMSLogging,

  X.Utility, X.Constants, X.SystemGlobal;


type
  TUpdateFolderHistoryUpdateThread = class(TThread)
  private
    FSource : integer;

    FError  : string;

//    FCriticalSection: TCriticalSection;
  public
    constructor Create(aCreateSuspended: Boolean); overload;
    destructor Destroy; override;

    procedure SetData(const aFromTableName, aConnectionString : string; aUseODBC : boolean; aOutputLabel : TLabel);

    property Error : string read FError;
  protected
    XODBC    : TADOConnection;

    FFromTableName, FTempOutput, FODDBConnectionString : string;
    FUseODBC : boolean;
    FOutputLabel : TLabel;

    function  InitODBC(const connectionstring : string): boolean;
    procedure CloseODBC;

    function  BoolToIntAsString(mrbool : boolean): string;
    function  AttributeToIntAsString(AttributeData : integer; AttributeValue : integer): string;

    function  CreateNewFolderTable(const tablename : string): boolean;
    function  CreateNewFileTable(const tablename : string): boolean;
    function  PopulateFolderTable(const tablename : string): boolean;
    function  PopulateFileTable(const tablename : string): boolean;

    function ODBCCreateNewFolderTable(const aTablename : string): boolean;
    function SqliteCreateNewFolderTable(const aTablename : string): boolean;

    function ODBCCreateNewFileTable(const aTablename : string): boolean;
    function SqliteCreateNewFileTable(const aTablename : string): boolean;

    function ODBCPopulateFolderTable(const aTablename : string): boolean;
    function SqlitePopulateFolderTable(const aTablename : string): boolean;

    function ODBCPopulateFileTable(const aTableName : string): boolean;
    function SqlitePopulateFileTable(const aTableName : string): boolean;

    procedure Execute; override;
  end;


implementation


uses
  X.GlobalObjects, X.CFileObject, X.CUserData;


constructor TUpdateFolderHistoryUpdateThread.Create(aCreateSuspended : boolean);
begin
  inherited;

  Suspended := aCreateSuspended;

  FSource   := dataLatestScan;
end;


destructor TUpdateFolderHistoryUpdateThread.Destroy;
begin
//  FCriticalSection.Free;

  inherited;
end;


// =================================================================================================
// == ODBC Specific ================================================================================
// =================================================================================================


function  TUpdateFolderHistoryUpdateThread.InitODBC(const connectionstring : string): boolean;
 begin
  Assert(connectionstring <> '', 'TUpdateFolderHistoryUpdateThread.InitODBC :: invalid connection string');

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


procedure TUpdateFolderHistoryUpdateThread.CloseODBC;
 begin
  if XODBC.Connected then
    XODBC.Close;

  XODBC.Free;
end;


// =================================================================================================
// =================================================================================================
// =================================================================================================


function TUpdateFolderHistoryUpdateThread.BoolToIntAsString(mrbool : boolean): string;
begin
  if mrbool then
    Result := '1'
  else
    Result := '0';
end;


function TUpdateFolderHistoryUpdateThread.AttributeToIntAsString(AttributeData : integer; AttributeValue : integer): string;
begin
  if (AttributeValue and AttributeData) = AttributeValue then
    Result := '1'
  else
    Result := '0';
end;


// =================================================================================================
// =================================================================================================
// =================================================================================================


function TUpdateFolderHistoryUpdateThread.CreateNewFolderTable(const tablename : string): boolean;
begin
  Assert(tablename <> '', 'CreateNewFolderTable :: Empty table name');

  if FUseODBC then begin
    Result := ODBCCreateNewFolderTable(tablename);
  end
  else begin
    Result := SqliteCreateNewFolderTable(tablename);
  end;
end;


function TUpdateFolderHistoryUpdateThread.CreateNewFileTable(const tablename : string): boolean;
begin
  if FUseODBC then begin
    Result := ODBCCreateNewFileTable(tablename);
  end
  else begin
    Result := SqliteCreateNewFileTable(tablename);
  end;
end;


function TUpdateFolderHistoryUpdateThread.PopulateFolderTable(const tablename : string): boolean;
begin
  Assert(tablename <> '', 'PopulateFolderTable :: Empty table name');

//  FCriticalSection.Acquire;

  if FUseODBC then begin
    Result := ODBCPopulateFolderTable(tablename);
  end
  else begin
    Result := SqlitePopulateFolderTable(tablename);
  end;

//  FCriticalSection.Leave;
end;


function TUpdateFolderHistoryUpdateThread.PopulateFileTable(const tablename : string): boolean;
begin
//  FCriticalSection.Acquire;

  if FUseODBC then begin
    Result := ODBCPopulateFileTable(TableName);
  end
  else begin
    Result := SqlitePopulateFileTable(TableName);
  end;

//  FCriticalSection.Leave;
end;

procedure TUpdateFolderHistoryUpdateThread.SetData(const aFromTableName, aConnectionString : string; aUseODBC : boolean; aOutputLabel : TLabel);
 begin
  FError                := '';

  FFromTableName        := aFromTableName;
  FTempOutput           := FOutputLabel.Caption;
  FUseODBC              := aUseODBC;
  FODDBConnectionString := aConnectionString;

  FOutputLabel          := aOutputLabel;

//  FCriticalSection := TCriticalSection.Create;
end;

procedure TUpdateFolderHistoryUpdateThread.Execute;
 begin
//  FreeOnTerminate := True;

  if FUseODBC then begin
    if InitODBC(FODDBConnectionString) then
      {}
    else
      Exit;
  end;

  if CreateNewFolderTable(FFromTableName + 'F') then begin
    if PopulateFolderTable(FFromTableName + 'F') then begin

      if CreateNewFileTable(FFromTableName) then begin
        if not(PopulateFileTable(FFromTableName)) then
          FError := 'Failed to populate table "' + FFromTableName + '".';
      end
      else
        FError := 'Failed to create new table "' + FFromTableName + '".';
    end
    else
      FError := 'Failed to populate table "' + FFromTableName + 'F' + '".';
  end
  else
    FError := 'Failed to create table "' + FFromTableName + 'F' + '".';

  if FUseODBC then
    CloseODBC;
end;


// =============================================================================


function TUpdateFolderHistoryUpdateThread.ODBCCreateNewFolderTable(const aTablename : string): boolean;
var
  ADOCommand : TADOCommand;

begin
  Result := True;

  try
    ADOCommand := TADOCommand.Create(nil);
    ADOCommand.Connection  := XODBC;
    ADOCommand.Parameters.Clear;
    ADOCommand.CommandText := 'CREATE TABLE "' + aTablename + '" (FilePath VARCHAR (1024))';
    ADOCommand.Execute;
    ADOCommand.Free;
  except
    on e : exception do begin
      Result := False;

      TMSLogger.Error('ODBC::Error creating folder table "' + aTablename + '".');
      TMSLogger.Error(e.Message);
    end;
  end;
end;


function TUpdateFolderHistoryUpdateThread.SqliteCreateNewFolderTable(const aTablename : string): boolean;
var
  lSQliteConnection : TSQLConnection;

begin
  Result := True;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('FailIfMissing=false');
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try

    try
     lSQliteConnection.Connected := True;

     lSQliteConnection.ExecuteDirect('CREATE TABLE "' + aTablename + '" ([ID] INTEGER PRIMARY KEY, [FilePath] VARCHAR (1024))');

    except
      on e : exception do begin
        Result := False;

        TMSLogger.Error('Sqlite::Error creating folder table "' + aTablename + '".');
        TMSLogger.Error(e.Message);
      end;
    end;

  finally
    lSQliteConnection.Connected := False;

    FreeAndNil(lSQliteConnection);
  end;
end;


// =============================================================================


function TUpdateFolderHistoryUpdateThread.ODBCCreateNewFileTable(const aTablename : string): boolean;
var
  ADOCommand : TADOCommand;

begin
  Result := True;

  try
    ADOCommand := TADOCommand.Create(nil);

    ADOCommand.Connection := XODBC;
    ADOCommand.Parameters.Clear;
    ADOCommand.CommandText := 'CREATE TABLE "' + aTablename + '" (FilePath VARCHAR (1024), ' +
                                                'FilePathIdx INT, ' +
                                                'FileName VARCHAR (255), ' +
                                                'FileSize BIGINT, ' +
                                                'FileSizeDisk BIGINT, ' +
                                                'FileDateC INT, ' +
                                                'FileDateA INT, ' +
                                                'FileDateM INT, ' +
                                                'Category INT, ' +
                                                'Directory INT, ' +
                                                'Readonly INT, ' +
                                                'Hidden INT, ' +
                                                'System INT, ' +
                                                'Archive INT, ' +
                                                'Temp INT, ' +
                                                'Owner VARCHAR (255))';
    ADOCommand.Execute;

    ADOCommand.Free;

  except
    on e : exception do begin
      Result := False;

      TMSLogger.Error('ODBC::Error creating file table "' + aTablename + '".');
      TMSLogger.Error(e.Message);
    end;
  end;
end;


function TUpdateFolderHistoryUpdateThread.SqliteCreateNewFileTable(const aTableName : string): boolean;
var
  lSQliteConnection : TSQLConnection;
  lSQL : string;

begin
  Result := True;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('FailIfMissing=false');
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    lSQL := 'CREATE TABLE "' + aTableName + '" ([ID] INTEGER PRIMARY KEY, ' +
                                                 '[FilePath] VARCHAR (1024), ' +
                                                 '[FilePathIdx] INTEGER, ' +
                                                 '[FileName] VARCHAR (255), ' +
                                                 '[FileSize] INTEGER, ' +
                                                 '[FileSizeDisk] INTEGER, ' +
                                                 '[FileDateC] INTEGER, ' +
                                                 '[FileDateA] INTEGER, ' +
                                                 '[FileDateM] INTEGER, ' +
                                                 '[Category] INTEGER, ' +
                                                 '[Directory] INTEGER, ' +
                                                 '[Readonly] INTEGER, ' +
                                                 '[Hidden] INTEGER, ' +
                                                 '[System] INTEGER, ' +
                                                 '[Archive] INTEGER, ' +
                                                 '[Temp] INTEGER, ' +
                                                 '[Owner] VARCHAR (255))';

    try
      lSQliteConnection.ExecuteDirect(lSQL);
    except
      on e : exception do begin
        Result := False;

        TMSLogger.Error('SQlite::Error creating file table "' + aTablename + '".');
        TMSLogger.Error(e.Message);
      end;
    end;
  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;
end;


// =============================================================================


function TUpdateFolderHistoryUpdateThread.ODBCPopulateFolderTable(const aTablename : string): boolean;
var
  t : integer;
  ADOCommand : TADOCommand;

begin
  Result := True;

  try
    for t := 0 to GScanDetails[FSource].Folders.Count - 1 do begin
      ADOCommand := TADOCommand.Create(nil);

      ADOCommand.Connection  := XODBC;
      ADOCommand.Parameters.Clear;
      ADOCommand.CommandText := 'INSERT INTO "' + aTablename + '" (FilePath) VALUES (:FilePath)';
      ADOCommand.ParamCheck  := False;
      ADOCommand.Parameters.ParamByName('FilePath').Value := GScanDetails[FSource].Folders[t];
      ADOCommand.Execute;

      ADOCommand.Free;
    end;
  except
    on e : exception do begin
      Result := False;

      TMSLogger.Error('ODBC::Error populating folder table "' + aTablename + '".');
      TMSLogger.Error(e.Message);
    end;
  end;
end;


function TUpdateFolderHistoryUpdateThread.SqlitePopulateFolderTable(const aTablename : string): boolean;
var
  lSQliteConnection : TSQLConnection;
  lDBXT: TDBXTransaction;
  t, lTCount : integer;

begin
  Result  := True;
  lDBXT   := Nil;
  lTCount := 0;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('FailIfMissing=false');
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    lDBXT := lSQliteConnection.BeginTransaction;

    for t := 0 to GScanDetails[FSource].Folders.Count - 1 do begin

      lSQliteConnection.ExecuteDirect('INSERT INTO "' + aTablename + '" (FilePath) VALUES ' + '("' + GScanDetails[FSource].Folders[t] + '")');

      inc(lTCount);

      if (lTCount = 100) then begin

         lSQliteConnection.CommitFreeAndNil(lDBXT);

         if (t <> GScanDetails[FSource].Folders.Count - 1) then
           lDBXT := lSQliteConnection.BeginTransaction;
      end;
    end;

    if Assigned(lDBXT) then
      lSQliteConnection.CommitFreeAndNil(lDBXT);

  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;
end;


// =============================================================================


function TUpdateFolderHistoryUpdateThread.ODBCPopulateFileTable(const aTableName : string): boolean;
var
  t : integer;
  ADOCommand : TADOCommand;
  xfo : TFileObject;

begin
  Result := True;

  try

    for t := 0 to GScanDetails[FSource].Files.Count - 1 do begin
      xfo := GScanDetails[FSource].Files.Items[t];

      ADOCommand := TADOCommand.Create(nil);

      ADOCommand.Connection  := XODBC;
      ADOCommand.Parameters.Clear;
      ADOCommand.CommandText := 'INSERT INTO "' + aTableName + '" (FilePath, FilePathIdx, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner) VALUES ' +
                                                                  '(' + QuotedStr(GScanDetails[FSource].Folders[xfo.FilepathIndex] ) + ', ' +
                                                                  IntToStr(xfo.FilePathIndex)                                + ', ' +
                                                                  QuotedStr(xfo.Filename)                                    + ', ' +
                                                                  IntToStr(xfo.FileSize)                                     + ', ' +
                                                                  IntToStr(xfo.FileSizeOnDisk)                               + ', ' +
                                                                  IntToStr(xfo.FileDateC)                                    + ', ' +
                                                                  IntToStr(xfo.FileDateA)                                    + ', ' +
                                                                  IntToStr(xfo.FileDateM)                                    + ', ' +
                                                                  IntToStr(xfo.FileCategory)                                 + ', ' +
                                                                  AttributeToIntAsString(xfo.Attributes, faDirectory)        + ', ' +
                                                                  AttributeToIntAsString(xfo.Attributes,Sysutils.faReadOnly) + ', ' +
                                                                  AttributeToIntAsString(xfo.Attributes,faHidden)            + ', ' +
                                                                  AttributeToIntAsString(xfo.Attributes, faSysFile)          + ', ' +
                                                                  AttributeToIntAsString(xfo.Attributes, faArchive)          + ', ' +
                                                                  BoolToIntAsString(xfo.Temp)                                + ', ''' +
                                                                  GScanDetails[FSource].Users[xfo.Owner].Name         + ''')';
      ADOCommand.Execute;

      ADOCommand.Free;

      if t mod 200 = 0 then begin
        FOutputLabel.Caption := FTempOutput + ' (' + IntToStr(Round((t / GScanDetails[FSource].Files.Count) * 100)) + '%)';
      end;
    end;
  except
    on e : exception do begin
      Result := False;

      TMSLogger.Error('ODBC::Error populating file table "' + aTablename + '".');
      TMSLogger.Error(e.Message);
    end;
  end;
end;


function TUpdateFolderHistoryUpdateThread.SqlitePopulateFileTable(const aTableName : string): boolean;
var
  lSQliteConnection : TSQLConnection;
  lDBXT: TDBXTransaction;
  xfo : TFileObject;
  t, lTCount : integer;
  lSQL : string;

begin
  Result  := True;
  lDBXT   := Nil;
  lTCount := 0;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('FailIfMissing=false');
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    lDBXT := lSQliteConnection.BeginTransaction;

    for t := 0 to GScanDetails[FSource].Files.Count - 1 do begin
      xfo := GScanDetails[FSource].Files.Items[t];

      lSQL := 'INSERT INTO "' + aTableName + '" (FilePath, FilePathIdx, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner) VALUES ' +
                                                 '("' + GScanDetails[FSource].Folders[xfo.FilePathIndex] + '", ' +
                                                  IntToStr(xfo.FilePathIndex) + ', ' +
                                                  '"' + xfo.Filename + '", ' +
                                                  IntToStr(xfo.FileSize) + ', ' +
                                                  IntToStr(xfo.FileSizeOnDisk) + ', ' +
                                                  IntToStr(xfo.FileDateC) + ', ' +
                                                  IntToStr(xfo.FileDateA) + ', ' +
                                                  IntToStr(xfo.FileDateM) + ', ' +
                                                  IntToStr(xfo.FileCategory) + ', ' +
                                                  AttributeToIntAsString(xfo.Attributes, SysUtils.faDirectory) + ', ' +
                                                  AttributeToIntAsString(xfo.Attributes, SysUtils.faReadOnly)  + ', ' +
                                                  AttributeToIntAsString(xfo.Attributes, SysUtils.faHidden)    + ', ' +
                                                  AttributeToIntAsString(xfo.Attributes, SysUtils.faSysFile)   + ', ' +
                                                  AttributeToIntAsString(xfo.Attributes, SysUtils.faArchive)   + ', ' +
                                                  BoolToIntAsString(xfo.Temp) + ', ' +
                                                  '"' + GScanDetails[FSource].Users[xfo.Owner].Name + '")';

      lSQliteConnection.ExecuteDirect(lSQL);

      inc(lTCount);

      if (lTCount = 100) then begin

         lSQliteConnection.CommitFreeAndNil(lDBXT);

         if (t <> GScanDetails[FSource].Files.Count - 1) then
           lDBXT := lSQliteConnection.BeginTransaction;
      end;
    end;

    if Assigned(lDBXT) then
      lSQliteConnection.CommitFreeAndNil(lDBXT);

  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;
end;


end.
