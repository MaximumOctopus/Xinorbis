{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Windows;

interface


uses
  Windows, ShellAPI, ShlObj, System.Classes, System.SysUtils, Registry, Forms,

  TMSLogging,

  X.Constants, X.LanguageHandler, X.Global;

type
  TXDriveDetails = record
                     VolumeName      : string;
                     FileSystem      : string;
                     SerialNumber    : string;
                     SerialNumberHex : string;

                     SectorsPerCluster : DWORD;
                     BytesPerSector    : DWORD;
                     FreeClusters      : DWORD;
                     Clusters          : DWORD;

                     SectorSize        : integer;
                   end;


  TXWindows = class
    class procedure AddXinorbisToContextMenu;

    class function  BrowseForFolder(mrhandle : THandle) : string;
    class function  ExecuteFile(bob : THandle; const FileName, Params, DefaultDir: string): THandle;
    class function  GetComputerNetName: string;
    class function  GetDiskTypeString(const driveroot : string): string;
    class function  GetDriveDetails(const aPath : string): TXDriveDetails;
    class function  GetEnvVarValue(const VarName: string): string;
    class function  GetFileOwner(const FileName: string; var Username: string): Boolean;
    class function  GetUserFromWindows: string;
    class function  GetTempDirectory: string;
    class function  SendToRecycleBin(const aFileName : string): Boolean;
    class function  SetupFormatSettings: boolean;
    class function  ShowFilePropertiesDialog(hWndOwner: HWND; const FileName: string): Boolean;

    class function  CopyAllFiles(aFromPath, aToPath : string): boolean;
    class function  MoveAllFiles(aFromPath, aToPath : string): boolean;

    class function  GetSpecialFolder(xID : integer): string;

    class function  ConvertPathToNetwork(const xpath : string; nwid : integer): string;
    class procedure GetNetworkDrives;
    class function  IsThisNetworkDrive(const s : string): integer;
  end;


var
  XinorbisFormatSettings : TFormatSettings;
  NetworkDrivesList  : TStringList;


implementation


uses
  X.Settings;


class procedure TXWindows.AddXinorbisToContextMenu;
var
  reg : TRegistry;

begin
  try
    try
      Reg := TRegistry.Create(KEY_WRITE);

      Reg.RootKey := HKEY_CLASSES_ROOT;

      Reg.OpenKey('\directory\shell\Xinorbis8', True);
      Reg.WriteString('', 'Examine this folder with Xinorbis');

      Reg.OpenKey('\directory\shell\Xinorbis8\Command', True);
      Reg.WriteString('', '"' + Application.ExeName + '" "%1"');

      Reg.OpenKey('\directory\shell\Xinorbis8\DefaultIcon', True);
      Reg.WriteExpandString('', '"' + Application.ExeName + ',0"');
    except
      on e : exception do begin
        TMSLogger.Error('Error adding Xinorbis to context menu: ' + e.ClassName + ' / ' + e.Message);
      end;
    end;
  finally
    if (Assigned(Reg)) then
      Reg.Free;
  end;
end;


class function TXWindows.BrowseForFolder(mrhandle : THandle) : string;
 var
  BrowseInfo   : TBrowseInfoW;
  PIDL         : PItemIDList;
  SelectedPath : array[0..MAX_PATH] of WideChar;

 begin
  Result := '';

  FillChar(BrowseInfo,SizeOf(BrowseInfo), #0);
  BrowseInfo.hwndOwner      := mrhandle;
  BrowseInfo.pszDisplayName := @SelectedPath[0];
  BrowseInfo.lpszTitle      := PWideChar(XText[rsFolder]);
  BrowseInfo.ulFlags        := BIF_RETURNONLYFSDIRS;

  PIDL := SHBrowseForFolderW(BrowseInfo);

  if Assigned(PIDL) then
    if SHGetPathFromIDListW(PIDL, SelectedPath) then begin
      Result := SelectedPath;

      if Result[length(Result)] <> '\' then
        Result := Result + '\';
    end;
end;


class function TXWindows.ExecuteFile(bob : THandle; const FileName, Params, DefaultDir: string): THandle;
begin
  Result := ShellExecuteW(bob, nil, PChar(FileName), PWideChar(Params), PChar(DefaultDir), SW_SHOW)
end;


class function TXWindows.GetComputerNetName: string;
var
  buffer: array[0..255] of char;
  size: dword;

begin
  size := 256;

  if GetComputerName(buffer, size) then
    Result := buffer
  else begin
    Result := XText[rsUnknown];

    TMSLogger.Error('Error getting computer name. Using Unknown');
  end;
end;


class function TXWindows.GetDiskTypeString(const driveroot : string): string;
 var
  s : string;
  ret : integer;

 begin
  if driveroot <> '' then
    ret := GetDriveType(PChar(driveroot))
  else
    ret := 0;

  case ret of
    0	              : s := XText[rsDriveCannotDetermind];
    1	              : s := XText[rsTheRootNotExist];
    DRIVE_REMOVABLE	: s := XText[rsRemovable];
    DRIVE_FIXED	    : s := XText[rsHardDisk];
    DRIVE_REMOTE    : s := XText[rsRemoteDrive];
    DRIVE_CDROM	    : s := XText[rsCDROM];
    DRIVE_RAMDISK	  : s := XText[rsRAMDisk];
  end;

  Result := s;
end;


class function TXWindows.GetDriveDetails(const aPath : string): TXDriveDetails;
var
  Tmp_SectorsPerCluster,     // holds the sectors per cluster
  Tmp_BytesPerSector,        // holds the bytes per sector
  Tmp_FreeClusters,          // holds the number of free clusters
  Tmp_Clusters      :DWORD;  // holds the total number of disk clusters
  VolName           :PChar;  // holds the volume name
  SerialNumber      :PDWORD; // holds the serial number
  MaxCLength        :DWORD;  // holds the maximum file component length
  FileSysFlag       :DWORD;  // holds file system flags
  FileSysName       :PChar;  // holds the name of the file system
  driven : string;

begin
  Result.VolumeName        := XText[rsUnknown];
  Result.FileSystem        := XText[rsUnknown];
  Result.SerialNumber      := XText[rsUnknown];
  Result.SerialNumberHex   := XText[rsUnknown];
  Result.SectorsPerCluster := 0;
  Result.BytesPerSector    := 0;
  Result.FreeClusters      := 0;
  Result.Clusters          := 0;
  Result.SectorSize        := 0;

  GetMem(VolName, 255);
  GetMem(FileSysName, 255);
  GetMem(SerialNumber, 255);

  if (aPath <> '') then begin

    if Pos('\\', aPath) = 0 then begin
      driven := aPath[1] + ':\';

      if GetDiskFreeSpace(PChar(driven), Tmp_SectorsPerCluster, Tmp_BytesPerSector, Tmp_FreeClusters, Tmp_Clusters) then begin

        Result.SectorsPerCluster := Tmp_SectorsPerCluster;
        Result.BytesPerSector    := Tmp_BytesPerSector;
        Result.FreeClusters      := Tmp_FreeClusters;
        Result.Clusters          := Tmp_Clusters;

        Result.SectorSize        := Tmp_SectorsPerCluster * Tmp_BytesPerSector;

        if GetVolumeInformation(PChar(driven), VolName, 255, SerialNumber, MaxCLength, FileSysFlag, FileSysName, 255) then begin

          Result.VolumeName        := StrPas(Volname);
          Result.FileSystem        := FileSysName;
          Result.SerialNumber      := IntToStr(SerialNumber^);
          Result.SerialNumberHex   := IntToHex(SerialNumber^, 8);
        end;
      end;
    end
  end;

  FreeMem(SerialNumber);
  FreeMem(FileSysName);
  FreeMem(VolName);
end;


class function TXWindows.GetEnvVarValue(const VarName: string): string;
 var
  BufSize: Integer;  // buffer size required for value

 begin
  // Get required buffer size (inc. terminal #0)
  BufSize := GetEnvironmentVariable(PChar(VarName), nil, 0);

  if BufSize > 0 then begin
    // Read env var value into result string
    SetLength(Result, BufSize - 1);
    GetEnvironmentVariable(PChar(VarName), PChar(Result), BufSize);
  end
  else
    // No such environment variable
    Result := '';
end;


class function TXWindows.GetFileOwner(const FileName: string; var Username: string): Boolean;
 var
  SecDescr: PSecurityDescriptor;
  OwnerSID: PSID;
  OwnerDefault: BOOL;
  OwnerName, DomainName: PChar;
  OwnerType: SID_NAME_USE;
  SizeNeeded : DWORD;

 begin
  GetFileOwner := False;

  GetMem(SecDescr, 1024);
  GetMem(OwnerName, 1024);
  GetMem(DomainName, 1024);

  try
    SizeNeeded  := 1024;

    if not GetFileSecurity(PChar(FileName), OWNER_SECURITY_INFORMATION, SecDescr, 1024, SizeNeeded) then
      Exit;

    if not GetSecurityDescriptorOwner(SecDescr, OwnerSID, OwnerDefault) then
      Exit;

    if not LookupAccountSID(nil, OwnerSID, OwnerName, SizeNeeded, DomainName, SizeNeeded, OwnerType) then
      Exit;

    //Domain   := DomainName;
    Username := OwnerName;
  finally
    FreeMem(SecDescr);
    FreeMem(OwnerName);
    FreeMem(DomainName);
  end;

  GetFileOwner := True;
end;


class function TXWindows.GetUserFromWindows: string;
 var
  UserName : string;
  UserNameLen : Dword;

 begin
  UserNameLen := 255;

  SetLength(userName, UserNameLen) ;

  if GetUserName(PChar(UserName), UserNameLen) then
    Result := Copy(UserName,1, UserNameLen - 1)
  else begin
    Result := XText[rsUnknown];

    TMSLogger.Error('Error getting user name. Using Unknown');
  end;
end;


// http://msdn.microsoft.com/en-us/library/bb762494.aspx
class function TXWindows.GetSpecialFolder(xID : integer): string;
 var
  szPath: array [0..MAX_PATH] of Char;
  xcopy, temp : string;
  t : integer;
  go : boolean;

 begin
  Assert((xID >= 1) and (xID <= 11), 'GetSpecialFolder :: Invalid ID');

  case xID of
     1 : SHGetFolderPath(0, CSIDL_PROGRAM_FILES,    0, 0, @szPath[0]);
     2 : SHGetFolderPath(0, CSIDL_PROGRAM_FILESX86, 0, 0, @szPath[0]);
     3 : SHGetFolderPath(0, CSIDL_WINDOWS,          0, 0, @szPath[0]);
     4 : begin // users
           SHGetFolderPath(0, $0028, 0, 0, @szPath[0]);

           xcopy := SzPath;
           temp  := '';
           go    := false;

           t     := length(xcopy);

           while t > 0 do begin
             if go then
               temp := xcopy[t] + temp;

             if xcopy[t] = '\' then go := True;

             dec(t);
           end;
         end;
     5 : SHGetFolderPath(0, $0028, 0, 0, @szPath[0]);
     6 : SHGetFolderPath(0, $000D, 0, 0, @szPath[0]);
     7 : SHGetFolderPath(0, $0027, 0, 0, @szPath[0]);
     8 : SHGetFolderPath(0, $0005, 0, 0, @szPath[0]);
     9 : SHGetFolderPath(0, $000E, 0, 0, @szPath[0]);
    10 : begin
           ShGetSpecialFolderPath(0, szPath, $0028, FALSE);

           temp := szPath + '\xinorbis';
         end;
    11 : begin
           ShGetSpecialFolderPath(0, szPath, CSIDL_PERSONAL, FALSE);

           temp := szPath + '\MaximumOctopus\xinorbis';
         end;
  end;

  if (xID <> 4) and (xID < 10) then
    temp := SzPath;

  Result := temp + '\';
end;


class function TXWindows.CopyAllFiles(aFromPath, aToPath : string): boolean;
var
  FOS: TSHFileOpStruct;

begin
  ZeroMemory(@FOS, SizeOf(FOS));

  FOS.wFunc  := FO_COPY;
  FOS.fFlags := FOF_ALLOWUNDO or FOF_SIMPLEPROGRESS;
  FOS.pFrom  := PChar(aFromPath + '*.*'#0);
  FOS.pTo    := PChar(aToPath + #0);

  Result := (SHFileOperationW(FOS) = 0);
end;


class function TXWindows.MoveAllFiles(aFromPath, aToPath : string): boolean;
var
  FOS: TSHFileOpStruct;

begin
  ZeroMemory(@FOS, SizeOf(FOS));

  FOS.wFunc  := FO_MOVE;
  FOS.fFlags := FOF_ALLOWUNDO or FOF_SIMPLEPROGRESS;
  FOS.pFrom  := PChar(aFromPath + '*.*'#0);
  FOS.pTo    := PChar(aToPath + #0);

  Result := (SHFileOperationW(FOS) = 0);
end;


class function TXWindows.GetTempDirectory: string;
 var
  tempFolder: array[0..MAX_PATH] of widechar;

 begin
  GetTempPathW(MAX_PATH, @tempFolder);

  Result := tempFolder;
end;


class function TXWindows.SendToRecycleBin(const aFileName : string): Boolean;
 var
  FOS: TSHFileOpStruct;

 begin
  FillChar(FOS, SizeOf(FOS), 0);

  FOS.wFunc  := FO_DELETE;
  FOS.pFrom  := PChar(aFileName + #0);
  FOS.fFlags := FOF_ALLOWUNDO or FOF_NOCONFIRMATION or FOF_SILENT;

  Result := (SHFileOperation(FOS) = 0);
end;


class function TXWindows.SetupFormatSettings: boolean;
begin
  GetLocaleFormatSettings(0, XinorbisFormatSettings);

  XinorbisFormatSettings.ShortDateFormat := 'dd/MM/yyyy';

  Result := True;
end;


class function TXWindows.ShowFilePropertiesDialog(hWndOwner: HWND; const FileName: string): Boolean;
var
  Info: TShellExecuteInfo;

begin
  with Info do begin
    cbSize       := SizeOf(Info);
    fMask        := SEE_MASK_NOCLOSEPROCESS or SEE_MASK_INVOKEIDLIST or SEE_MASK_FLAG_NO_UI;
    wnd          := hWndOwner;
    lpVerb       := 'properties';
    lpFile       := pChar(FileName);
    lpParameters := nil;
    lpDirectory  := nil;
    nShow        := 0;
    hInstApp     := 0;
    lpIDList     := nil;
  end;

  Result := ShellExecuteEx(@Info);
end;


class procedure TXWindows.GetNetworkDrives;

  function SuperTrim(const s : string): string;
  var
    i : integer;
    ts : string;

  begin
    i  := 1;

    ts := '';
    while (ord(s[i]) >= 32) and (ord(s[i]) <= 126) do begin
      ts := ts + s[i];
      inc(i);
    end;

    Result := ts;
  end;

  function GetNetworkDriveMappings(var sl : TStringList ) : integer;
  var
    i               : integer;
    sNetPath        : string;
    dwMaxNetPathLen : DWord;

  begin
    sl.Clear;
    dwMaxNetPathLen := MAX_PATH;
    SetLength( sNetPath, dwMaxNetPathLen );

    for i := 0 to 25 do begin
      if( NO_ERROR = Windows.WNetGetConnection(PChar('' + Chr( 65 + i ) + ':' ), PChar( sNetPath ), dwMaxNetPathLen ) ) then begin
        sl.Add( Chr( 65 + i ) + SuperTrim(sNetPath) + '\');
      end;
    end;

    Result := sl.Count;
  end;

 begin
  GetNetworkDriveMappings(NetworkDrivesList);
end;


class function TXWindows.IsThisNetworkDrive(const s : string): integer;
var
  t : integer;

begin
  Result := -1;

  if NetworkDrivesList.Count <> 0 then begin
    for t := 0 to NetworkDrivesList.Count - 1 do begin
      if UpCase(s[1]) = NetworkDrivesList.Strings[t][1] then begin
        Result := t;

        Break;
      end;
    end;
  end;
end;


class function TXWindows.ConvertPathToNetwork(const xpath : string; nwid : integer): string;
var
  netpath : string;

begin
  netpath := Copy(NetworkDrivesList.Strings[nwid], 2, length(NetworkDrivesList.Strings[nwid]) - 1);

  Result  := StringReplace(xpath, xpath[1] + ':\', netpath, [rfIgnoreCase]);
end;


end.
