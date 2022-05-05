{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.SystemGlobal;

interface


uses
  System.SysUtils, System.Classes, Forms, Inifiles, dialogs,

  TMSLogging, TMSLoggingTextOutputHandler,

  X.Constants, X.Windows, X.Dialogs.Dialog, X.LanguageHandler;


type
  TSystemGlobal = class
  private
    FNewVersionAvailable : boolean;
    FLogEnabled          : boolean;
    FLogPath             : string;

    procedure CheckFolderStructure;
    function  GetUsersPath: string;
    procedure CheckLogSettings;

    procedure FileCheck(const aFileName : string);
  public
    DriveSpaceMax                 : Int64;
    DriveSpaceFree                : Int64;
    DriveSectorSize               : integer;

    CurrentNavigationSideLocation : string;
    FolderStructure               : TStringList;

    ExePath                       : string;
    HelpPath                      : string;
    AppDataPath                   : string;
    ExcludeVirtual                : boolean;
    ExcludedFolders               : TStringList;
    ExcludedFiles                 : TStringList;

    FileCategoryColors            : array[0..__FileCategoriesCount] of integer;  // 0 is a hack for "folders"

    constructor Create;
    destructor Destroy; override;

    procedure InstallationCheck;

    property NewVersionAvailable : boolean read FNewVersionAvailable write FNewVersionAvailable;
  end;


var
 GSystemGlobal : TSystemGlobal;


implementation


uses
  X.Utility;


constructor TSystemGlobal.Create;
begin
  inherited;

  ExePath         := ExtractFilePath(Application.ExeName);
  HelpPath        := 'http://xinorbis.com/help/';
  AppDataPath     := GetUsersPath;

  FLogEnabled     := False;
  FLogPath        := ExePath + 'Logs\';

  CheckLogSettings;

  if (FLogEnabled) then
    TMSLogger.RegisterOutputHandlerClass(TTMSLoggerTextOutputHandler,
                                         [FLogPath + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt']);

  TMSLogger.Info('ExePath     : ' + ExePath);
  TMSLogger.Info('AppDataPath : ' + AppDataPath);

  FolderStructure := TStringList.Create;

  ExcludedFolders := TStringList.Create;
  ExcludedFiles   := TStringList.Create;

  CheckFolderStructure;
end;


destructor TSystemGlobal.Destroy;
begin
  FreeAndNil(FolderStructure);

  FreeAndNil(ExcludedFolders);
  FreeAndNil(ExcludedFiles);

  inherited;
end;


// =============================================================================


procedure TSystemGlobal.CheckLogSettings;
var
  t : integer;
  tlp : string;

begin
  tlp := '';

  for t := 0 to ParamCount do begin
    if (UpperCase(ParamStr(t)) = '/LOG') then
      FLogEnabled := True;

    if (Pos('/LOGPATH;', UpperCase(ParamStr(t))) <> 0) then
      tlp := Copy(ParamStr(t), 10);
  end;

  if tlp <> '' then begin
    FLogPath := tlp;

    if FLogPath[length(FLogPath)] <> '\' then
      FLogPath := FLogPath + '\';
  end;
end;


function TSystemGlobal.GetUsersPath: string;
 var
  config : TINIFile;
  a,b : integer;
  lDataPath, lCustomIni, lCINIEnv, lWinEnv : string;

 begin
  lCustomIni := ExePath + 'custom.ini';

  if FileExists(lCustomIni) then begin
    config := TINIFile.Create(lCustomIni);

    try
      lDataPath := config.ReadString('Main', 'DataPath', '');

      // =========================================================================
      // == Portable specific modes                                             ==
      // =========================================================================

      if lDataPath <> '' then begin
        if lDataPath[length(lDataPath)] <> '\' then lDataPath := lDataPath + '\';

        // lets check for special variables
        if Pos('$xdrive', lDataPath) <> 0 then begin
          lDataPath := StringReplace(lDataPath, '$xdrive', ExePath[1] + ':', [rfReplaceAll]);
        end;

        if Pos('$xfolder', lDataPath) <> 0 then begin
          lDataPath := StringReplace(lDataPath,
                                     '$xfolder',
                                     Copy(ExePath, 1, length(ExePath) - 1),
                                     [rfReplaceAll]);
        end;

        // handle enviromental variable
        if Pos('<', lDataPath) <> 0 then begin
          a := Pos('<', lDataPath);
          b := Pos('>', lDataPath);

          if b <> 0 then begin
            lCINIEnv := Copy(lDataPath, a + 1, (b - a) - 1);

            lWinEnv  := TXWindows.GetEnvVarValue(lCINIEnv);

            if lWinEnv <> '' then begin
              lDataPath := StringReplace(lDataPath, '<' + lCINIEnv + '>', lWinEnv, [rfReplaceAll]);
            end
            else begin
              ShowXDialog('Configuration error',
                          'Environment variable "' + lCINIEnv + '" not found.' + #13#13 + 'Using: ' + ExePath + 'xinorbis\',
                          XDialogTypeWarning);

              lDataPath := ExePath + 'Xinorbis\';
            end;
          end;
        end;

        Result := lDataPath;
      end
      else
        Result := ExtractFilePath(Application.ExeName) + 'system\';

      if config.ReadBool('Main', 'LocalHelp', True) then
        HelpPath := ExePath + 'data\help\';

      // =========================================================================
      // ==                                                                     ==
      // =========================================================================
    finally
      config.Free;
    end;
  end
  else begin
    Result := TXWindows.GetSpecialFolder(11);
  end;

  if Result = '' then begin
    Result := ExtractFilePath(Application.ExeName) + 'system\';

    TMSLogger.Error('Error getting Users path. Using portable mode default.');
  end;
end;


procedure TSystemGlobal.CheckFolderStructure;
 var
  cname : string;
  wasIOResult : boolean;

  procedure CreateFolder(folderpath : string);
   begin
    try
      ForceDirectories(folderpath);
    except
      wasIOResult := True;
    end;
  end;

 begin
  cname := TXWindows.GetComputerNetName;

  wasIOResult := False;

  {$I-}

  if not(DirectoryExists(ExePath + 'Logs'))                                                then CreateFolder(ExePath + 'Logs');

  if not(DirectoryExists(AppDataPath)) then CreateFolder(AppDataPath);

  if not(DirectoryExists(AppDataPath + 'FolderHistory\Database'))                            then CreateFolder(AppDataPath + 'FolderHistory\Database');
  if not(DirectoryExists(AppDataPath + 'FolderHistory\' + cname))                            then CreateFolder(AppDataPath + 'FolderHistory\' + cname);

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname))                                  then CreateFolder(AppDataPath + 'Reports\' + cname);

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\CSV\autosaves'))               then CreateFolder(AppDataPath + 'Reports\' + cname + '\CSV\autosaves');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\CSV\quick'))                   then CreateFolder(AppDataPath + 'Reports\' + cname + '\CSV\quick');

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\HTML\data'))                   then CreateFolder(AppDataPath + 'Reports\' + cname + '\HTML\data');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\HTML\autosaves\data'))         then CreateFolder(AppDataPath + 'Reports\' + cname + '\HTML\autosaves\data');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\HTML\quick\data'))             then CreateFolder(AppDataPath + 'Reports\' + cname + '\HTML\quick\data');

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\HTML_Compare\data'))           then CreateFolder(AppDataPath + 'Reports\' + cname + '\HTML_Compare\data');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\HTML_Compare\autosaves\data')) then CreateFolder(AppDataPath + 'Reports\' + cname + '\HTML_Compare\autosaves\data');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\HTML_Compare\quick\data'))     then CreateFolder(AppDataPath + 'Reports\' + cname + '\HTML_Compare\quick\data');

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\Xinorbis\autosaves'))          then CreateFolder(AppDataPath + 'Reports\' + cname + '\Xinorbis\autosaves');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\Xinorbis\quick'))              then CreateFolder(AppDataPath + 'Reports\' + cname + '\Xinorbis\quick');

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\Summary\autosaves'))           then CreateFolder(AppDataPath + 'Reports\' + cname + '\Summary\autosaves');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\Summary\quick'))               then CreateFolder(AppDataPath + 'Reports\' + cname + '\Summary\quick');

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\Text\autosaves'))              then CreateFolder(AppDataPath + 'Reports\' + cname + '\Text\autosaves');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\Text\quick'))                  then CreateFolder(AppDataPath + 'Reports\' + cname + '\Text\quick');

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\Tree\autosaves'))              then CreateFolder(AppDataPath + 'Reports\' + cname + '\Tree\autosaves');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\Tree\quick'))                  then CreateFolder(AppDataPath + 'Reports\' + cname + '\Tree\quick');

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\XML\autosaves'))               then CreateFolder(AppDataPath + 'Reports\' + cname + '\XML\autosaves');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\XML\quick'))                   then CreateFolder(AppDataPath + 'Reports\' + cname + '\XML\quick');

  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\XML_Compare\autosaves'))       then CreateFolder(AppDataPath + 'Reports\' + cname + '\XML_Compare\autosaves');
  if not(DirectoryExists(AppDataPath + 'Reports\' + cname + '\XML_Compare\quick'))           then CreateFolder(AppDataPath + 'Reports\' + cname + '\XML_Compare\quick');

  if not(DirectoryExists(AppDataPath + 'Saves\Custom Reports'))                              then CreateFolder(AppDataPath + 'Saves\Custom Reports');

  {$I+}

  // ====================================================================================
  // DO NO USE TRANSLATED TEXT FOR THESE CONSTANTS!
  // ====================================================================================

  if (wasIOResult) then
    ShowXDialog('Error(s) while updating "' + AppDataPath + '".',
                'This folder, and all subfolders, must be read/write.',
                XDialogTypeWarning);

  if not(DirectoryExists(ExePath + 'Data')) then begin
    ShowXDialog('Xinorbis is not properly installed',
                'Missing folder: ' + ExePath + 'Data',
                XDialogTypeWarning);

    Halt(0);
  end;
end;


procedure TSystemGlobal.FileCheck(const aFileName : string);
begin
  if not(FileExists(aFileName)) then
    ShowXDialog(TLanguageHandler.FillParameter(rsCannotFindFileParam, ExtractFileName(aFileName)),
                XText[rsPleaseCheckXinorbisInstalled],
                XDialogTypeWarning);
end;


procedure TSystemGlobal.InstallationCheck;
begin
  {$ifdef CPUX64}
    FileCheck(ExePath + 'DelZip192x64.dll');

    FileCheck(ExePath + 'sqlite3.dll');
  {$else}
    FileCheck(ExePath + 'DelZip192.dll');

    FileCheck(ExePath + 'sqlite3.dll');
  {$endif}
end;


end.
