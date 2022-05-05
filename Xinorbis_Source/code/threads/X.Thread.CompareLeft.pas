{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Thread.CompareLeft;

interface

uses
  StdCtrls, SysUtils, classes, AdvGrid, ADODB, Data.DB, Data.SqlExpr,

  SyncObjs,

  X.LanguageHandler, X.Utility, X.Constants, X.CSizeOfFolder, X.SystemGlobal;

type
  TCompareLeftThread = class(TThread)
  private
    FCriticalSection : TCriticalSection;

    function  InitODBC(const connectionstring : string): boolean;
    procedure CloseODBC;
  public
    destructor Destroy; override;

    procedure SetData(const s : string; o1 : integer; o2 : boolean; gridx : TAdvStringGrid);
  protected
    XODBC    : TADOConnection;

    SQL : string;
    option1 : integer;
    option2 : boolean;
    grid    : TAdvStringGrid;

    procedure Execute; override;

    procedure ProcessODBC(aSQL : string);
    procedure ProcessSqlite(aSQL : string);
  end;


implementation


uses
  Main,

  X.Conversions, X.Settings, X.Global;


destructor TCompareLeftThread.Destroy;
begin
  FCriticalSection.Free;

  inherited;
end;


// =================================================================================================
// == ODBC Specific ================================================================================
// =================================================================================================


function TCompareLeftThread.InitODBC(const connectionstring : string): boolean;
 begin
  Assert(connectionstring <> '', 'TCompareLeftThread.InitODBC :: invalid connection string');

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


procedure TCompareLeftThread.CloseODBC;
 begin
  if XODBC.Connected then
    XODBC.Close;

  XODBC.Free;
end;


// =================================================================================================
// =================================================================================================
// =================================================================================================


procedure TCompareLeftThread.SetData(const s : string; o1 : integer; o2 : boolean; gridx : TAdvStringGrid);
 begin
  SQL     := s;
  option1 := o1;
  option2 := o2;
  grid    := gridx;

  FCriticalSection := TCriticalSection.Create;
end;


procedure TCompareLeftThread.Execute;
begin
  FreeOnTerminate := True;

  FCriticalSection.Acquire;

  if XSettings.Database.UseODBC then begin
    if InitODBC(XSettings.Database.ODBConnectionString) then
      {}
    else
      Exit;
  end;

  // ==========================================================================
  // ==========================================================================
  // ==========================================================================

  grid.BeginUpdate;

  grid.ClearRows(1, grid.RowCount - 2);
  grid.BeginUpdate;
  grid.RowCount := 2;

  CompareData[XLeftSide].Data[XFileCount]   := 0;
  CompareData[XLeftSide].Data[XFolderCount] := 0;
  CompareData[XLeftSide].Data[XFileSize]    := 0;

  if XSettings.Database.UseODBC then begin
    ProcessODBC(SQL);
  end
  else begin
    ProcessSqlite(SQL);
  end;

  // ==========================================================================
  // ==========================================================================
  // ==========================================================================

  grid.EndUpdate;

  if XSettings.Database.UseODBC then
    CloseODBC;

  FCriticalSection.Leave;
end;


procedure TCompareLeftThread.ProcessODBC(aSQL : string);
var
  status : string;
  XQuery : TADOQuery;

begin
  XQuery := TADOQuery.Create(nil);

  try
    XQuery.Connection:=XODBC;
    XQuery.SQL.Add(sql);
    XQuery.Open;

    while not XQuery.eof do begin
      if option2 then
        grid.Cells[FHschFilename, grid.RowCount - 1] := XQuery.FieldByName('FilePath').AsString + XQuery.FieldByname('FileName').AsString
      else
        grid.Cells[FHschFilename, grid.RowCount - 1] := XQuery.FieldByName('FileName').AsString;

      if XQuery.FieldByname('Directory').AsString = '1' then
        grid.Cells[FHschSize, grid.RowCount - 1] := ' ' + UpperCase(XText[rsFolder])
      else
        grid.Cells[FHschSize, grid.RowCount - 1] := TConvert.GetSizeString(option1, StrToInt64(XQuery.FieldByName('FileSize').AsString));

      if XQuery.FieldByname('Directory').AsString = '1' then
        grid.Cells[FHschSizeOnDisk, grid.RowCount - 1] := ' ' + UpperCase(XText[rsFolder])
      else
        grid.Cells[FHschSizeOnDisk, grid.RowCount - 1] := TConvert.GetSizeString(option1, StrToInt64(XQuery.FieldByName('FileSize').AsString));

      grid.Cells[FHschCreated, grid.RowCount - 1]  := TConvert.StrDateToFString(XQuery.FieldByName('FileDateC').AsString);
      grid.Cells[FHschAccessed, grid.RowCount - 1] := TConvert.StrDateToFString(XQuery.FieldByName('FileDateA').AsString);
      grid.Cells[FHschModified, grid.RowCount - 1] := TConvert.StrDateToFString(XQuery.FieldByName('FileDateM').AsString);
      grid.Cells[FHschOwner, grid.RowCount - 1]    := XQuery.FieldByName('Owner').AsString;

      status := '------';

      if XQuery.FieldByname('Directory').AsInteger = 1 then status[1] := 'D';
      if XQuery.FieldByname('Readonly').AsInteger  = 1 then status[2] := 'R';
      if XQuery.FieldByname('Hidden').AsInteger    = 1 then status[3] := 'H';
      if XQuery.FieldByname('System').AsInteger    = 1 then status[4] := 'S';
      if XQuery.FieldByname('Archive').AsInteger   = 1 then status[5] := 'A';
      if XQuery.FieldByname('Temp').AsInteger      = 1 then status[6] := 'T';

      grid.Cells[FHschStatus, grid.RowCount - 1]   := status;

      grid.Cells[FHschCategory, grid.RowCount - 1] := XQuery.FieldByname('Category').AsString;

      if XQuery.FieldByName('Directory').AsInteger = 1 then
        grid.Cells[FHschSortSize,       grid.RowCount - 1] := '-1'
      else
        grid.Cells[FHschSortSize,       grid.RowCount - 1] := XQuery.FieldByname('FileSize').AsString;

      grid.Cells[FHschSortSizeOnDisk, grid.RowCount - 1] := XQuery.FieldByname('FileSizeDisk').AsString;
      grid.Cells[FHschSortCreated,    grid.RowCount - 1] := XQuery.FieldByname('FileDateC').AsString;
      grid.Cells[FHschSortAccessed,   grid.RowCount - 1] := XQuery.FieldByname('FileDateA').AsString;
      grid.Cells[FHschSortModified,   grid.RowCount - 1] := XQuery.FieldByname('FileDateM').AsString;

      grid.RowCount := grid.RowCount + 1;

      inc(CompareData[XLeftSide].Data[XFileSize], StrToInt64(XQuery.FieldByName('FileSize').AsString));

      if XQuery.FieldByname('Directory').AsInteger = 1 then // is folder
        inc(CompareData[XLeftSide].Data[XFolderCount])
      else
        inc(CompareData[XLeftSide].Data[XFileCount]);

      XQuery.Next;
    end;
  finally
    XQuery.Free;
  end;
end;


procedure TCompareLeftThread.ProcessSqlite(aSQL : string);
var
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;
  status : string;

begin
  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    lSQliteConnection.Execute(aSQL, nil, lResults);

    if not lResults.IsEmpty then begin
      lResults.First;

      while not lResults.Eof do begin
        if option2 then
          grid.Cells[FHschFilename, grid.RowCount - 1] := lResults.Fields[fFilePath].AsString + lResults.Fields[fFileName].AsString
        else
          grid.Cells[FHschFilename, grid.RowCount - 1] := lResults.Fields[fFileName].AsString;

        if lResults.Fields[fDirectory].AsString = '1' then
          grid.Cells[FHschSize, grid.RowCount - 1] := ' ' + UpperCase(XText[rsFolder])
        else
          grid.Cells[FHschSize, grid.RowCount - 1] := TConvert.GetSizeString(option1, lResults.Fields[fFileSize].AsLargeInt);

        if lResults.Fields[fDirectory].AsString = '1' then
          grid.Cells[FHschSizeOnDisk, grid.RowCount - 1] := ' ' + UpperCase(XText[rsFolder])
        else
          grid.Cells[FHschSizeOnDisk, grid.RowCount - 1] := TConvert.GetSizeString(option1, lResults.Fields[fFileSizeDisk].AsLargeInt);

        grid.Cells[FHschCreated, grid.RowCount - 1]  := TConvert.StrDateToFString(lResults.Fields[fFileDateC].AsString);
        grid.Cells[FHschAccessed, grid.RowCount - 1] := TConvert.StrDateToFString(lResults.Fields[fFileDateA].AsString);
        grid.Cells[FHschModified, grid.RowCount - 1] := TConvert.StrDateToFString(lResults.Fields[fFileDateM].AsString);
        grid.Cells[FHschOwner, grid.RowCount - 1]    := lResults.Fields[fOwner].AsString;

        status := '------';

        if lResults.Fields[fDirectory].AsString = '1' then status[1] := 'D';
        if lResults.Fields[fReadonly].AsString = '1'  then status[2] := 'R';
        if lResults.Fields[fHidden].AsString = '1'    then status[3] := 'H';
        if lResults.Fields[fSystem].AsString = '1'    then status[4] := 'S';
        if lResults.Fields[fArchive].AsString = '1'   then status[5] := 'A';
        if lResults.Fields[fTemp].AsString = '1'      then status[6] := 'T';

        grid.Cells[FHschStatus, grid.RowCount - 1]   := status;

        grid.Cells[FHschCategory, grid.RowCount - 1] := lResults.Fields[fCategory].AsString;

        if lResults.Fields[fDirectory].AsString = '1' then
          grid.Cells[FHschSortSize,       grid.RowCount - 1] := '-1'
        else
          grid.Cells[FHschSortSize,       grid.RowCount - 1] := lResults.Fields[fFileSize].AsString;

        grid.Cells[FHschSortSizeOnDisk, grid.RowCount - 1] := lResults.Fields[fFileSizeDisk].AsString;
        grid.Cells[FHschSortCreated,    grid.RowCount - 1] := lResults.Fields[fFileDateC].AsString;
        grid.Cells[FHschSortAccessed,   grid.RowCount - 1] := lResults.Fields[fFileDateA].AsString;
        grid.Cells[FHschSortModified,   grid.RowCount - 1] := lResults.Fields[fFileDateM].AsString;

        grid.RowCount := grid.RowCount + 1;

        inc(CompareData[XLeftSide].Data[XFileSize], lResults.Fields[fFileSize].AsLargeInt);

        if lResults.Fields[fDirectory].AsString = '1' then // is folder
          inc(CompareData[XLeftSide].Data[XFolderCount])
        else
          inc(CompareData[XLeftSide].Data[XFileCount]);

        lResults.Next;
      end;

      grid.RowCount := grid.RowCount - 1;
    end;

  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;
end;


end.
