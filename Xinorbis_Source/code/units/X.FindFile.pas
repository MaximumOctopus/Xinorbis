                                                                                              // =======================================
// January 16th 2019
// =======================================

{$I DELPHIAREA.INC}

{$IFDEF COMPILER6_UP}
  {$WARN SYMBOL_PLATFORM OFF} // This is Win32, no warning for FindData record
{$ENDIF}

unit X.FindFile;

interface

uses
  Windows, Messages, Classes, SysUtils, Vcl.Dialogs,

  TMSLogging;

const
  FILE_ATTRIBUTE_READONLY              = $00000001;
  FILE_ATTRIBUTE_HIDDEN                = $00000002;
  FILE_ATTRIBUTE_SYSTEM                = $00000004;
  FILE_ATTRIBUTE_DIRECTORY             = $00000010;
  FILE_ATTRIBUTE_ARCHIVE               = $00000020;
  FILE_ATTRIBUTE_DEVICE                = $00000040;
  FILE_ATTRIBUTE_NORMAL                = $00000080;
  FILE_ATTRIBUTE_TEMPORARY             = $00000100;
  FILE_ATTRIBUTE_SPARSE_FILE           = $00000200;
  FILE_ATTRIBUTE_REPARSE_POINT         = $00000400;
  FILE_ATTRIBUTE_COMPRESSED            = $00000800;
  FILE_ATTRIBUTE_OFFLINE               = $00001000;
  FILE_ATTRIBUTE_NOT_CONTENT_INDEXED   = $00002000;
  FILE_ATTRIBUTE_ENCRYPTED             = $00004000;
  FILE_ATTRIBUTE_VIRTUAL               = $00010000;
  FILE_ATTRIBUTE_RECALL_ON_OPEN        = $00040000;
  FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS = $00400000;


type
  TTargetPath = class(TObject)
  private
    fFolder: String;
  public
    constructor Create;
    destructor Destroy; override;

    property Folder: string         read fFolder     write fFolder;
  end;

  TTargetPaths = class(TList)
  private
    function GetItems(Index: Integer): TTargetPath;
  protected
    procedure Notify(Ptr: Pointer; Action: TListNotification); override;
    function ExtractMeta(const Info: String): String;
  public
    function  Find(const Folder: String): TTargetPath;
    function  AddPath(const PathInfo: String): TTargetPath;
    function  AddFolderAndMasks(const FolderInfo: String): TTargetPath;

    property Items[Index: Integer]: TTargetPath read GetItems; default;
  end;

  TCustomCriteria = class(TPersistent)
  public
    procedure Clear; virtual; abstract;
  end;

  TFileCriteria = class(TCustomCriteria)
  private
    fLocation: String;
    fFilters: TStringList;
    fTargetPaths: TTargetPaths;

    function GetTargetPaths: TTargetPaths;
    procedure SetLocation(const Value: String);
    procedure SetFilters(Value: TStringList);
    procedure TargetPathsChanged(Sender: TObject);
  protected
    property TargetPaths: TTargetPaths read GetTargetPaths;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear; override;
    procedure Assign(Source: TPersistent); override;
    function Matches(const Folder, FileName: String): Boolean;
  published
    property Location: String     read fLocation write SetLocation;
    property Filters: TStringList read fFilters  write SetFilters;
  end;


  TSearchCriteria = class(TCustomCriteria)
  private
    fFiles: TFileCriteria;

    procedure SetFiles(Value: TFileCriteria);
  public
    constructor Create;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure Clear; override;
    function Matches(const Folder: String; const FindData: TWin32FindData): Boolean;
  published
    property Files: TFileCriteria read fFiles write SetFiles;
  end;

  TFolderChangeEvent = procedure (const Folder: String) of object;

  PFileDetails = ^TFileDetails;
  TFileDetails = record
    Location: String;
    Name: TFileName;
    Attributes: DWORD;
    Size: int64;
    CreatedTime : TDateTime;
    ModifiedTime: TDateTime;
    AccessedTime: TDateTime;
  end;

  TFileMatchEvent = procedure (const FileInfo: TFileDetails) of object;

  TFindFile = class(TComponent)
  private
    fCriteria      : TSearchCriteria;
    FIgnoreVirtual : boolean;
    fAborted       : Boolean;

    fOnFileMatch: TFileMatchEvent;
    fOnFolderChange: TFolderChangeEvent;
    fOnSearchBegin: TNotifyEvent;
    fOnSearchFinish: TNotifyEvent;
    ActiveCriteria: TSearchCriteria;
    ActiveTarget : TTargetPath;

    procedure SetCriteria(Value: TSearchCriteria);
    procedure InitializeSearch;
    procedure FinalizeSearch;
    procedure SearchForFiles;
    procedure SearchIn(const Path: String);
    procedure SearchInQuick(const Path: String); // optimised for zero filters
  protected
    procedure DoSearchBegin; virtual;
    procedure DoSearchFinish; virtual;
    function IsAcceptable(const Folder: String; const FindData: TWin32FindData): Boolean; virtual;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Execute;
    procedure Abort;
    property Aborted: Boolean read fAborted;
  published
    property IgnoreVirtual  : boolean            read FIgnoreVirtual  write FIgnoreVirtual;
    property Criteria       : TSearchCriteria    read fCriteria       write SetCriteria;
    property OnFileMatch    : TFileMatchEvent    read fOnFileMatch    write fOnFileMatch;
    property OnFolderChange : TFolderChangeEvent read fOnFolderChange write fOnFolderChange;
    property OnSearchBegin  : TNotifyEvent       read fOnSearchBegin  write fOnSearchBegin;
    property OnSearchFinish : TNotifyEvent       read fOnSearchFinish write fOnSearchFinish;
  end;

procedure Register;


function FileTimeToDateTime(const FileTime: TFileTime): TDateTime;
function WildcardMatches(S, M: PChar): Boolean;


implementation


const
  Delimiter   = ';';
  IncludeSign = '>';
  ExcludeSign = '<';

{ Character Map for faster case-insensitive search }

type
  PWideCharMap = ^TWideCharMap;
  TWideCharMap = array[WideChar] of WideChar;

var
  WideCharMap: TWideCharMap;
  WideLowerCharMap: TWideCharMap;
  WideIsDelimiter: array[WideChar] of Boolean;


procedure InitFastContentSearch;
var
  WC: WideChar;

begin
  for WC := Low(TWideCharMap) to High(TWideCharMap) do
  begin
    WideCharMap[WC] := WC;
    WideLowerCharMap[WC] := WC;
    WideIsDelimiter[WC] := not IsCharAlphaNumericW(WC);
  end;
  AnsiLowerBuff(PAnsiChar(@WideLowerCharMap), SizeOf(WideLowerCharMap));
end;

{ Helper Functions }


function FileTimeToDateTime(const FileTime: TFileTime): TDateTime;
var
  LocalFileTime: TFileTime;
  SystemTime: TSystemTime;

begin
  FileTimeToLocalFileTime(@FileTime, LocalFileTime);
  FileTimeToSystemTime(@LocalFileTime, SystemTime);

  try
    Result := EncodeDate(SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay);
  except
    on e : exception do begin
      Result := EncodeDate(1975, 4, 17);   // very important date

      TMSLogger.Error('Invalid date: ' + IntToStr(SystemTime.wYear) + ' / ' + IntToStr(SystemTime.wMonth) + ' / ' +IntToStr(SystemTime.wDay));
    end;
  end;

  if Result >= 0 then
    Result := Result + EncodeTime(SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond, SystemTime.wMilliSeconds)
  else
    Result := Result - EncodeTime(SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond, SystemTime.wMilliSeconds);
end;


function WildcardMatches(S, M: PChar): Boolean;
const
  CharMap: PWideCharMap = @WideLowerCharMap;

var
  Stop: Char;
begin
  Result := False;
  while (S^ <> #0) and (M^ <> #0) and (M^ <> '*') do
  begin
    if (M^ <> '?') and (CharMap^[M^] <> CharMap^[S^]) then
      Exit;
    Inc(S);
    Inc(M);
  end;
  if (S^ = #0) or (M^ = '*') then
  begin
    while (M^ = '*') or (M^ = '?') do
      Inc(M);
    if (S^ = #0) or (M^ = #0) then
      Result := (M^ = #0)
    else
    begin
      Stop := CharMap^[M^];
      Inc(M);
      while (S^ <> #0) and not Result do
      begin
        while (CharMap^[S^] <> Stop) and (S^ <> #0) do
          Inc(S);
        if S^ <> #0 then
        begin
          Inc(S);
          Result := WildcardMatches(S, M);
        end;
      end;
    end;
  end;
end;

{ TTargetPath }

constructor TTargetPath.Create;
begin
  inherited Create;
end;

destructor TTargetPath.Destroy;
begin
  inherited Destroy;
end;

{ TTargetPaths }

procedure TTargetPaths.Notify(Ptr: Pointer; Action: TListNotification);
begin
  if (Action = lnDeleted) and Assigned(Ptr) then
    TTargetPath(Ptr).Free;
end;


function TTargetPaths.Find(const Folder: String): TTargetPath;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    Result := Items[I];

    if CompareText(Result.Folder, Folder) = 0 then
      Exit;
  end;

  Result := nil;
end;

function TTargetPaths.AddPath(const PathInfo: String): TTargetPath;
var
  Folder: String;
begin
  Folder   := ExtractMeta(ExtractFilePath(PathInfo));
  Result   := Find(Folder);

  if not Assigned(Result) then
  begin
    Result := TTargetPath.Create;

    Add(Result);
  end;

  Result.Folder := Folder;
end;

function TTargetPaths.AddFolderAndMasks(const FolderInfo: String): TTargetPath;
var
  Folder: String;
begin
  Folder := ExtractMeta(FolderInfo);
  Result := Find(Folder);

  if not Assigned(Result) then
  begin
    Result := TTargetPath.Create;
    Add(Result);
  end;

  Result.Folder := Folder;
end;

// can speed this up... i think.
function TTargetPaths.ExtractMeta(const Info: String): String;
var
  P: Integer;

begin
  Result := Info;

  P := Pos(IncludeSign, Info);

  if P <> 0 then
  begin
    System.Delete(Result, 1, P);
  end
  else
  begin
    P := Pos(ExcludeSign, Info);

    if P <> 0 then
    begin
      System.Delete(Result, 1, P);
    end;
  end;

  Result := ExpandUNCFileName(Trim(Result));

  if not IsPathDelimiter(Result, High(Result)) then
    Result := Result + PathDelim;
end;

function TTargetPaths.GetItems(Index: Integer): TTargetPath;
begin
  Result := TTargetPath(Get(Index));
end;

{ TFileCriteria }

constructor TFileCriteria.Create;
begin
  inherited Create;

  fFilters := TStringList.Create;
  fFilters.Duplicates    := dupIgnore;
  fFilters.CaseSensitive := False;
end;

destructor TFileCriteria.Destroy;
begin
  fFilters.Free;

  if Assigned(fTargetPaths) then
    fTargetPaths.Free;

  inherited Destroy;
end;

procedure TFileCriteria.Assign(Source: TPersistent);
begin
  if Source is TFileCriteria then
  begin
    Location := TFileCriteria(Source).Location;
    Filters  := TFileCriteria(Source).Filters;
  end
  else
    inherited Assign(Source);
end;

procedure TFileCriteria.Clear;
begin
  Location := '';

  Filters.Clear;
end;

function TFileCriteria.Matches(const Folder, FileName: String): Boolean;
var
  I: Integer;
  Path: String;
  Mask: PChar;
begin
  Result := True;

  if Filters.Count <> 0 then
  begin
    Path := Folder + FileName;
    if ExtractFileExt(FileName) = '' then
      Path := Path + '.';
    for I := 0 to Filters.Count - 1 do
    begin
      Mask := PChar(Filters[I]);
      if Mask^ = IncludeSign then
      begin
        Inc(Mask);
        if WildcardMatches(PChar(Path), Mask) then
           Exit;
      end
      else
      begin
        if Mask^ = ExcludeSign then
          Inc(Mask);
        if WildcardMatches(PChar(Path), Mask) then
        begin
          Result := False;
          Exit;
        end;
      end;
    end;
  end;
end;

function TFileCriteria.GetTargetPaths: TTargetPaths;
var
  I: Integer;
  Folders: TStringList;

 begin
  if not Assigned(fTargetPaths) then
  begin
    fTargetPaths := TTargetPaths.Create;

    try
      Folders := TStringList.Create;
      Folders.Add(Location);

      try
        for I := 0 to Folders.Count - 1 do
          fTargetPaths.AddFolderAndMasks(Folders[I]);
      finally
        Folders.Free;
      end;
    finally
    end;
  end;
  Result := fTargetPaths;
end;


procedure TFileCriteria.SetLocation(const Value: String);
begin
  if fLocation <> Value then
  begin
    fLocation := Value;

    TargetPathsChanged(nil);
  end;
end;


procedure TFileCriteria.SetFilters(Value: TStringList);
begin
  fFilters.Assign(Value);
end;


procedure TFileCriteria.TargetPathsChanged(Sender: TObject);
begin
  if Assigned(fTargetPaths) then
  begin
    fTargetPaths.Free;

    fTargetPaths := nil;
  end;
end;


{ TSearchCriteria }

constructor TSearchCriteria.Create;
begin
  inherited Create;

  fFiles := TFileCriteria.Create;
end;

destructor TSearchCriteria.Destroy;
begin
  fFiles.Free;

  inherited Destroy;
end;

procedure TSearchCriteria.Assign(Source: TPersistent);
begin
  if Source is TSearchCriteria then
  begin
    Files := TSearchCriteria(Source).Files;
  end
  else
    inherited Assign(Source);
end;


procedure TSearchCriteria.Clear;
begin
  Files.Clear;
end;


function TSearchCriteria.Matches(const Folder: String; const FindData: TWin32FindData): Boolean;
begin
  Result := Files.Matches(Folder, String(FindData.cFileName));
end;


procedure TSearchCriteria.SetFiles(Value: TFileCriteria);
begin
  Files.Assign(Value);
end;


{ TFindFile }


constructor TFindFile.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);

  fCriteria := TSearchCriteria.Create;
  fAborted  := False;
end;


destructor TFindFile.Destroy;
begin
  fCriteria.Free;

  inherited Destroy;
end;


procedure TFindFile.Abort;
begin
  fAborted := True;
end;


procedure TFindFile.DoSearchBegin;
begin
  if Assigned(fOnSearchBegin) then
    fOnSearchBegin(Self);
end;


procedure TFindFile.DoSearchFinish;
begin
  if Assigned(fOnSearchFinish) and not (csDestroying in ComponentState) then
    fOnSearchFinish(Self);
end;


function TFindFile.IsAcceptable(const Folder: String; const FindData: TWin32FindData): Boolean;
begin
  Result := not Aborted and ActiveCriteria.Matches(Folder, FindData);
end;


procedure TFindFile.InitializeSearch;
begin
  fAborted := False;

  ActiveCriteria := TSearchCriteria.Create;
  ActiveCriteria.Assign(fCriteria);

  DoSearchBegin;
end;


procedure TFindFile.FinalizeSearch;
begin
  ActiveCriteria.Free;
  ActiveCriteria := nil;

  DoSearchFinish;
end;


procedure TFindFile.SearchForFiles;
 var
  I: Integer;

 begin
  with ActiveCriteria.Files.TargetPaths do begin
    for I := 0 to Count - 1 do begin
      if Aborted then Exit;

      ActiveTarget := Items[I];

      if (Criteria.Files.Filters.Count = 0) and (not(FIgnoreVirtual)) then
        SearchInQuick(ActiveTarget.Folder)
      else
        SearchIn(ActiveTarget.Folder);
    end;
  end;
end;


procedure TFindFile.SearchIn(const Path: String);
 var
  FileInfo: TFileDetails;
  FindData: Win32_Find_DataW;
  Handle: THandle;

begin
  if Aborted then Exit;

  try
    FOnFolderChange(Path);

    with ActiveTarget do begin
      Handle := Windows.FindFirstFileEx(PChar(Path + '*'), FindExInfoBasic, @FindData, FindExSearchNameMatch, nil, 2); //FIND_FIRST_EX_LARGE_FETCH

      if Handle <> INVALID_HANDLE_VALUE then
        try
          repeat
            if (not LongBool(FindData.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY) or
               ((FindData.cFileName[0] <> '.') or ((FindData.cFileName[1] <> #0) and
               ((FindData.cFileName[1] <> '.') or (FindData.cFileName[2] <> #0))))) and
               IsAcceptable(Path, FindData)
            then begin
              FileInfo.Location     := Path;
              FileInfo.Name         := String(FindData.cFileName);
              FileInfo.Attributes   := FindData.dwFileAttributes;

              FileInfo.Size         := Int64(FindData.nFileSizeHigh) shl Int64(32) + Int64(FindData.nFileSizeLow);

              FileInfo.CreatedTime  := FileTimeToDateTime(FindData.ftCreationTime);
              FileInfo.ModifiedTime := FileTimeToDateTime(FindData.ftLastWriteTime);
              FileInfo.AccessedTime := FileTimeToDateTime(FindData.ftLastAccessTime);

              fOnFileMatch(FileInfo);
            end;
          until not Windows.FindNextFile(Handle, FindData);
        finally
          Windows.FindClose(Handle);
      end;

      Handle := Windows.FindFirstFileEx(PChar(Path + '*'), FindExInfoBasic, @FindData, FindExSearchNameMatch, nil, 2); //FIND_FIRST_EX_LARGE_FETCH

      if Handle <> INVALID_HANDLE_VALUE then
        try
          repeat
            if LongBool(FindData.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY) and
              ((FindData.cFileName[0] <> '.') or ((FindData.cFileName[1] <> #0) and
              ((FindData.cFileName[1] <> '.') or (FindData.cFileName[2] <> #0))))
            then begin
              if (FIgnoreVirtual) then
                if (not LongBool(FindData.dwFileAttributes and FILE_ATTRIBUTE_OFFLINE)) and
                   (not LongBool(FindData.dwFileAttributes and FILE_ATTRIBUTE_RECALL_ON_OPEN)) and
                   (not LongBool(FindData.dwFileAttributes and FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS)) then
                SearchIn(Path + String(FindData.cFileName) + '\')
              else
                SearchIn(Path + String(FindData.cFileName) + '\');
            end;
          until not Windows.FindNextFile(Handle, FindData);
        finally
          Windows.FindClose(Handle);
        end;
    end;
  finally

  end;
end;


// optimised for Filters.Count = 0
procedure TFindFile.SearchInQuick(const Path: String);
 var
  FileInfo: TFileDetails;
  FindData: Win32_Find_DataW;
  Handle: THandle;

begin
  if Aborted then
    Exit;

  try
    FOnFolderChange(Path);

    with ActiveTarget do begin
      Handle := Windows.FindFirstFileEx(PChar(Path + '*'), FindExInfoBasic, @FindData, FindExSearchNameMatch, nil, 2); //FIND_FIRST_EX_LARGE_FETCH

      if Handle <> INVALID_HANDLE_VALUE then
        try
          repeat
            if (not LongBool(FindData.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY) or
               ((FindData.cFileName[0] <> '.') or ((FindData.cFileName[1] <> #0) and
               ((FindData.cFileName[1] <> '.') or (FindData.cFileName[2] <> #0)))))
            then begin
              FileInfo.Location     := Path;
              FileInfo.Name         := String(FindData.cFileName);
              FileInfo.Attributes   := FindData.dwFileAttributes;

              FileInfo.Size         := Int64(FindData.nFileSizeHigh) shl Int64(32) + Int64(FindData.nFileSizeLow);

              FileInfo.CreatedTime  := FileTimeToDateTime(FindData.ftCreationTime);
              FileInfo.ModifiedTime := FileTimeToDateTime(FindData.ftLastWriteTime);
              FileInfo.AccessedTime := FileTimeToDateTime(FindData.ftLastAccessTime);

              fOnFileMatch(FileInfo);
            end;
          until not Windows.FindNextFile(Handle, FindData);
        finally
          Windows.FindClose(Handle);
      end;

      Handle := Windows.FindFirstFileEx(PChar(Path + '*'), FindExInfoBasic, @FindData, FindExSearchNameMatch, nil, 2); //FIND_FIRST_EX_LARGE_FETCH

      if Handle <> INVALID_HANDLE_VALUE then
        try
          repeat
            if LongBool(FindData.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY) and
              ((FindData.cFileName[0] <> '.') or ((FindData.cFileName[1] <> #0) and
              ((FindData.cFileName[1] <> '.') or (FindData.cFileName[2] <> #0)))) then
              SearchInQuick(Path + String(FindData.cFileName) + '\');
          until not Windows.FindNextFile(Handle, FindData);
        finally
          Windows.FindClose(Handle);
        end;
    end;
  finally

  end;
end;

procedure TFindFile.Execute;
begin
  InitializeSearch;

  try
    SearchForFiles;
  finally
    FinalizeSearch;
  end;
end;

procedure TFindFile.SetCriteria(Value: TSearchCriteria);
begin
  Criteria.Assign(Value);
end;

procedure Register;
begin
  RegisterComponents('Delphi Area', [TFindFile]);
end;

initialization
  InitFastContentSearch ;
end.


