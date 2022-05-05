{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Thread.CompareFolderLeft;

interface

uses
  StdCtrls, SysUtils, classes, AdvGrid, ADODB, Data.DB, Data.SqlExpr, dialogs,
  SyncObjs, HTMLabel,

  X.Utility, X.Constants, X.CSizeOfFolder, X.SystemGlobal;

type
  TCompareFolderLeftThread = class(TThread)
  private
    FCriticalSection : TCriticalSection;

    function  InitODBC(const connectionstring : string): boolean;
    procedure CloseODBC;

    procedure ProcessODBC(aSQL : string);
    procedure ProcessSqlite(aSQL : string);
  public
    destructor Destroy; override;

    procedure SetData(const s : string; o1 : string; o2 : THTMLabel; gridx : TAdvStringGrid);
  protected
    XODBC      : TADOConnection;
    SQL        : string;
    folder     : string;
    grid       : TAdvStringGrid;
    slabel     : THTMLabel;
    extspreadt : array[0..__FileCategoriesCount, 1..2] of Int64;   //maintains extension match counts - 1..count, 2..size
    tnumfiless, tnumfiless_folder : integer;
    tFileTotalSpace, tFileTotalSpace_folder : int64;

    procedure Execute; override;
  end;


const
  CFieldEmpty           = 0;
  CFieldCategoryCountPC = 3;
  CFieldCategorySizePC  = 6;


implementation


uses
  X.Conversions, X.Global, X.Settings;


destructor TCompareFolderLeftThread.Destroy;
begin
  FCriticalSection.Free;

  inherited;
end;


// =================================================================================================
// == ODBC Specific ================================================================================
// =================================================================================================


function TCompareFolderLeftThread.InitODBC(const connectionstring : string): boolean;
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


procedure TCompareFolderLeftThread.CloseODBC;
 begin
  if XODBC.Connected then
    XODBC.Close;

  XODBC.Free;
end;


// =================================================================================================
// =================================================================================================
// =================================================================================================


procedure TCompareFolderLeftThread.SetData(const s : string; o1 : string; o2 : THTMLabel; gridx : TAdvStringGrid);
 begin
  SQL    := s;
  folder := '\' + UpperCase(o1) + '\';
  slabel := o2;
  grid   := gridx;

  FCriticalSection := TCriticalSection.Create;
end;


procedure TCompareFolderLeftThread.Execute;
var
  t        : integer;
  addrow   : boolean;

begin
  FreeOnTerminate := True;

  FCriticalSection.Acquire;

  if XSettings.Database.UseODBC then begin
    if InitODBC(XSettings.Database.ODBConnectionString) then
      {}
    else
      Exit;
  end;

  for t := 0 to __FileCategoriesCount do begin
    extspreadt[t, 1] := 0;
    extspreadt[t, 2] := 0;
  end;

  tnumfiless             := 0;
  tFileTotalSpace        := 0;
  tnumfiless_folder      := 0;
  tFileTotalSpace_folder := 0;

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

  t := 1;

  while t <= __FileCategoriesCount do begin
    addrow := True;

    if addrow then begin
      grid.Cells[1, grid.RowCount - 1] := TypeDescriptions[t];
      grid.Cells[2, grid.RowCount - 1] := IntToStr(extspreadt[t, 1]);

      if tnumfiless <> 0 then begin
        grid.Cells[3, grid.RowCount - 1] := TConvert.RealToPercent(extspreadt[t, 1] / tnumfiless);
        grid.Cells[9, grid.RowCount - 1] := IntToStr(Round((extspreadt[t, 1] / tnumfiless) * 50));
      end
      else begin
        grid.Cells[3, grid.RowCount - 1] := '100%';
        grid.Cells[9, grid.RowCount - 1] := '100';
      end;

      grid.Cells[5, grid.RowCount - 1] := TConvert.ConvertToUsefulUnit(extspreadt[t, 2]);

      if tFileTotalSpace <> 0 then begin
        grid.Cells[6, grid.RowCount - 1]  := TConvert.RealToPercent(extspreadt[t, 2] / tFileTotalSpace);
        grid.Cells[10, grid.RowCount - 1] := IntToStr(Round((extspreadt[t, 2] / tFileTotalSpace) * 50))
      end
      else begin
        grid.Cells[6, grid.RowCount - 1]  := '100%';
        grid.Cells[10, grid.RowCount - 1] := '100';
      end;

      grid.Cells[7, grid.RowCount - 1]  := IntToStr(t);
      grid.Cells[8, grid.RowCount - 1]  := IntToStr(extspreadt[t, 2]);

      grid.RowCount := grid.RowCount + 1;
    end;

    inc(t);
  end;

  slabel.Caption := IntToStr(tnumfiless_folder) +
                    ' (<b>' + TConvert.ConvertToUsefulUnit(tFileTotalSpace_folder) + '</b>) of ' + IntToStr(tnumfiless) + ' (<b>' + TConvert.ConvertToUsefulUnit(tFileTotalSpace) + '</b>)';

  grid.RowCount := grid.RowCount - 1;

  // ==========================================================================
  // ==========================================================================
  // ==========================================================================

  grid.EndUpdate;

  if XSettings.Database.UseODBC then
    CloseODBC;

  FCriticalSection.Leave;
end;


procedure TCompareFolderLeftThread.ProcessODBC;
var
  XQuery   : TADOQuery;

begin
  XQuery := TADOQuery.Create(nil);

  try
    XQuery.Connection := XODBC;
    XQuery.SQL.Add(sql);
    XQuery.Open;

    while not XQuery.eof do begin

      if XQuery.FieldByname('Directory').AsString <> '1' then begin

        if Pos(folder, UpperCase(XQuery.FieldByName('FilePath').AsString)) <> 0 then begin
          inc(extspreadt[XQuery.FieldByname('Category').AsInteger, 1]);
          inc(extspreadt[XQuery.FieldByname('Category').AsInteger, 2], StrToInt64(XQuery.FieldByName('FileSize').AsString));

          inc(tnumfiless_folder);
          inc(tFileTotalSpace_folder, StrToInt64(XQuery.FieldByName('FileSize').AsString));
        end;

        inc(tnumfiless);
        inc(tFileTotalSpace, XQuery.FieldByName('FileSize').AsLargeInt);
      end;

      XQuery.Next;
    end;
  finally
    XQuery.Free;
  end;
end;


procedure TCompareFolderLeftThread.ProcessSqlite(aSQL : string);
var
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;

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
        if lResults.Fields[fDirectory].AsString <> '1' then begin

          if Pos(folder, UpperCase(lResults.Fields[fFilePath].AsString)) <> 0 then begin
            inc(extspreadt[lResults.Fields[fCategory].AsInteger, 1]);
            inc(extspreadt[lResults.Fields[fCategory].AsInteger, 2], lResults.Fields[fFileSize].AsLargeInt);

            inc(tnumfiless_folder);
            inc(tFileTotalSpace_folder, lResults.Fields[fFileSize].AsLargeInt);
          end;

          inc(tnumfiless);
          inc(tFileTotalSpace, lResults.Fields[fFileSize].AsLargeInt);
        end;

        lResults.Next;
      end;
    end;
  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;
end;


end.
