{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.ScanDetails;

interface


uses
  Generics.Defaults, System.Generics.Collections, System.Classes, System.SysUtils, dialogs,

  X.CFileObject, X.CRootFoldersData, X.CUserData, X.CMagnitude,

  X.Utility, X.Conversions, X.Constants;


type
  TScanDetails = class
  public
    ScanType        : integer;
    ScanSource      : integer;
    ScanPath        : string;
    ScanTable       : string;

    InProgress      : boolean;
    Filename        : string;
    MappedToNetwork : string;

    FromFile        : boolean;

    TimeStarted     : TDateTime;
    TodayAsInteger  : integer;

    ScanDateStr     : string;
    ScanDateInt     : string;
    ScanMD5         : string;

    ScanDateFHStr   : string;

    MultipleList    : TStringList;

    // =========================================================================

    FileCount       : integer;
    FolderCount     : integer;
    TotalSize       : int64;
    TotalSizeOD     : int64;

    Files           : TObjectList<TFileObject>;
    Folders         : TStringList;

    RootFiles       : TObjectList<TFileObject>;
    RootFolders     : TObjectList<TRootFoldersData>;

    Users           : TObjectList<TUserData>;

    Magnitude       : TMagnitude;

    NameLengthCount : array[0..279] of integer;
    NameLengthSize  : array[0..279] of int64;

    FileAttributes  : array[0..__AttributesTotalCount, 0..1] of Int64;  // Hidden, system, null, archive, read only,
                                                                   // created today, accessed today, modified today

    ExtensionSpread : array[0..__FileCategoriesCount, 1..2] of Int64;   //maintains extension match counts - 1..main, 2 for compare, 3 = search

    // =========================================================================

    constructor Create;
    destructor Destroy; override;

    procedure InitNow;

    procedure ClearUserStatistics;

    procedure ClearAll;
    procedure ClearForRefresh;

    function GetFolderIndex(aFolder : string): integer;
    function GetFullFolderIndex(aFolder : string): integer;
  end;


implementation


constructor TScanDetails.Create;
begin
  inherited;

  Files         := TObjectList<TFileObject>.Create;
  Folders       := TStringList.Create;

  RootFiles     := TObjectList<TFileObject>.Create;
  RootFolders   := TObjectList<TRootFoldersData>.Create;

  Users         := TObjectList<TUserData>.Create;

  MultipleList  := TStringList.Create;

  Magnitude     := TMagnitude.Create;

  ScanType      := -1;
  ScanSource    := -1;
  ScanPath      := '';
  ScanTable     := '';
  ScanDateFHStr := '';

  Filename      := '';

  InProgress    := False;
end;


destructor TScanDetails.Destroy;
begin
  FreeAndNil(Magnitude);

  FreeAndNil(MultipleList);

  FreeAndNil(Users);

  FreeAndNil(RootFolders);
  FreeAndNil(RootFiles);

  FreeAndNil(Folders);
  FreeAndNil(Files);

  inherited;
end;


function TScanDetails.GetFolderIndex(aFolder : string): integer;
var
  t : integer;
  lFolder : string;

begin
  Result := -1;
  t := 0;

  if aFolder <> '\' then
    lFolder := ScanPath + aFolder + '\'
  else
    lFolder := ScanPath;


  while t < Folders.Count do begin

    if Folders[t] = lFolder then begin
      Result := t;

      t := Folders.Count;
    end;

    inc(t);
  end;
end;


function TScanDetails.GetFullFolderIndex(aFolder : string): integer;
var
  t : integer;

begin
  Result := -1;
  t := 0;

  while t < Folders.Count do begin

    if Folders[t] = aFolder then begin
      Result := t;

      t := Folders.Count;
    end;

    inc(t);
  end;
end;


// =================================================================================


procedure TScanDetails.InitNow;
begin
  TimeStarted    := Now;
  TodayAsInteger := TConvert.DateTimeToInteger(Now);
  ScanDateStr    := TUtility.GetDate(GETTIMEFORMAT_SLASH) + ' ' + TUtility.GetTime(GETTIMEFORMAT_SLASH);
  ScanDateInt    := TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + TUtility.GetTime(GETTIMEFORMAT_FILE);

  ScanDateFHStr  := '';
end;


// =================================================================================


procedure TScanDetails.ClearUserStatistics;
var
  t, z : integer;

begin
  if Users.Count <> 0 then begin
    for t := 0 to Users.Count - 1 do begin
      Users[t].Data[XUserSize]  := 0;
      Users[t].Data[XUserCount] := 0;

      for z := 1 to __FileCategoriesCount do begin
        Users[t].CategoryDataQty[z]  := 0;
        Users[t].CategoryDataSize[z] := 0;
      end;
    end;
  end;
end;


procedure TScanDetails.ClearAll;
var
  t : integer;
  rfd : TRootFoldersData;

begin
  for t := 0 to __FileCategoriesCount do begin
    ExtensionSpread[t, 1] := 0;
    ExtensionSpread[t, 2] := 0;
  end;

  for t := 0 to __AttributesTotalCount do begin
    FileAttributes[t, 0] := 0;
    FileAttributes[t, 1] := 0;
  end;

  for t := 0 to 279 do begin
    NameLengthCount[t] := 0;
    NameLengthSize[t]  := 0;
  end;

  Magnitude.Clear;

  // ===========================================================================

  FileCount   := 0;
  FolderCount := 0;
  TotalSize   := 0;
  TotalSizeOD := 0;

  Users.Clear;
  Files.Clear;
  Folders.Clear;

  //  this prepares for BuildDirList functions =================================

  RootFiles.Clear;

  RootFolders.Clear;

  rfd := TRootFoldersData.Create;
  rfd.Name       := '\';
  rfd.Attributes := 0;

  RootFolders.Add(rfd);
end;


procedure TScanDetails.ClearForRefresh;
var
  t : integer;
  rfd : TRootFoldersData;

begin
  for t := 0 to __FileCategoriesCount do begin
    ExtensionSpread[t, 1] := 0;
    ExtensionSpread[t, 2] := 0;
  end;

  for t := 0 to __AttributesTotalCount do begin
    FileAttributes[t, 0] := 0;
    FileAttributes[t, 1] := 0;
  end;

  Magnitude.Clear;

  // ===========================================================================

  FileCount   := 0;
  FolderCount := 0;
  TotalSize   := 0;
  TotalSizeOD := 0;

  ClearUserStatistics;

  //  this prepares for BuildDirList functions =================================

  RootFiles.Clear;

  RootFolders.Clear;

  rfd := TRootFoldersData.Create;
  rfd.Name       := '\';
  rfd.Attributes := 0;

  RootFolders.Add(rfd);
end;


end.
