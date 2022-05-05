unit X.ZipFiles;

interface

uses
  ZipMstr, AdvGrid, dialogs,

  TMSLogging,

  X.Constants, X.LanguageHandler, X.SystemGlobal;

type
  TZipFiles = class
  public
    constructor Create;
    destructor  Destroy; override;

    function  ZipFilesOfType(aDataIndex : integer; aFileName : string; FileOfType : integer; StringContext : string; IntContext : integer): integer;
    function  ZipAllFiles(aFileName : string; aObjectIndex : integer; aTable : TAdvStringGrid; aFileNameColumn : integer): integer;
    function  ZipFolder(aFileName, aFolder : string): boolean;
  private
    zipMaster: TZipMaster;

    procedure zipMasterMessage(Sender: TObject; ErrCode: Integer; const ErrMsg: String);
    procedure zipMasterProgress(Sender: TObject; details: TZMProgressDetails);
  end;


var
  XinorbisZip: TZipFiles;


implementation


uses SysUtils,

     X.Dialogs.Dialog,

     X.GlobalObjects, X.Global, X.CFileObject, X.CUserData, X.Settings;


const
    CFileFilterExtension = 1;
    CFileFilterCategory  = 2;
    CFileFilterMagnitude = 3;
    CFileFilterOwner     = 4;

constructor TZipFiles.Create;
begin
  inherited;

  zipMaster := TZipMaster.Create(Nil);
  zipMaster.Dll_Load   := True;
  zipMaster.OnMessage  := zipMasterMessage;
  zipMaster.OnProgress := zipMasterProgress;
end;


destructor TZipFiles.Destroy;
begin
  FreeAndNil(zipMaster);

  inherited;
end;


procedure TZipFiles.zipMasterMessage(Sender: TObject; ErrCode: Integer; const ErrMsg: String);
 begin
  if ErrCode <> 0 then
    ShowXDialog(XText[rsErrorCompressingFiles],
                XText[rsError] + ': ' + ErrMsg,
                XDialogTypeWarning);

  XSettings.Forms.ZipForm.SetCaption(ErrMsg);
end;


procedure TZipFiles.zipMasterProgress(Sender: TObject; details: TZMProgressDetails);
 begin
  if details.ItemPerCent >= 0 then begin
    XSettings.Forms.ZipForm.SetPosition(details.ItemPerCent);

//    wsTaskbarProgress.Position := details.ItemPerCent;
  end;

  XSettings.Forms.ZipForm.SetZipFileName('Zipping: ' + details.ItemName);
end;


function TZipFiles.ZipFolder(aFileName, aFolder : string): boolean;
begin
  Result := True;

  try
    XinorbisZip.zipMaster.ZipFileName := aFileName;

    XinorbisZip.zipMaster.AddOptions  := [];
    XinorbisZip.zipMaster.AddOptions  := [AddRecurseDirs, AddDirNames, AddHiddenFiles, AddEmptyDirs ];

    XinorbisZip.zipMaster.FSpecArgs.Clear;

    XinorbisZip.zipMaster.RootDir := aFolder;    //to do, make sure this doesn't affecct other zipping funcs
    XinorbisZip.zipMaster.FSpecArgs.Add('*.*');

    XinorbisZip.zipMaster.Add;
  except
    Result := False;
  end;
end;


function TZipFiles.ZipFilesOfType(aDataIndex : integer; aFileName : string; FileOfType : integer; StringContext : string; IntContext : integer): integer;
 var
  xfo      : TFileObject;
  t        : integer;
  AddToZip : boolean;

 begin
  XSettings.ShowZipWindow;

  // ===========================================================================

  zipMaster.ZipFileName := aFileName;

  zipMaster.AddOptions  := [];
  zipMaster.AddOptions  := [AddDirNames, AddHiddenFiles, AddEmptyDirs];

  zipMaster.FSpecArgs.Clear;

  for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
    xfo := GScanDetails[aDataIndex].Files[t];

    AddToZip := False;

    if ((faDirectory and xfo.Attributes) = faDirectory) then begin
    end
    else begin
      case FileOfType of
        CFileFilterExtension : begin         // by extension
                                 if UpperCase(ExtractFileExt(xfo.FileName)) = StringContext then
                                   AddToZip := True;
                               end;
        CFileFilterCategory  : begin         // by category
                                 if xfo.FileCategory = IntContext then
                                   AddToZip := True;
                               end;
        CFileFilterMagnitude : begin         // magnitude
                                 case IntContext of
                                   CMagnitude1  : if (xfo.FileSize >= 0)                   and (xfo.FileSize <= 1024)                 then AddToZip := True;
                                   CMagnitude2  : if (xfo.FileSize > 1024)                 and (xfo.FileSize <= (1024 * 1024))        then AddToZip := True;
                                   CMagnitude3  : if (xfo.FileSize > (1024 * 1024))        and (xfo.FileSize <=   10 * (1024 * 1024)) then AddToZip := True;
                                   CMagnitude4  : if (xfo.FileSize >   10 * (1024 * 1024)) and (xfo.FileSize <=   50 * (1024 * 1024)) then AddToZip := True;
                                   CMagnitude5  : if (xfo.FileSize >   50 * (1024 * 1024)) and (xfo.FileSize <=  100 * (1024 * 1024)) then AddToZip := True;
                                   CMagnitude6  : if (xfo.FileSize >  100 * (1024 * 1024)) and (xfo.FileSize <=  150 * (1024 * 1024)) then AddToZip := True;
                                   CMagnitude7  : if (xfo.FileSize >  150 * (1024 * 1024)) and (xfo.FileSize <=  200 * (1024 * 1024)) then AddToZip := True;
                                   CMagnitude8  : if (xfo.FileSize >  200 * (1024 * 1024)) and (xfo.FileSize <=  250 * (1024 * 1024)) then AddToZip := True;
                                   CMagnitude9  : if (xfo.FileSize >  250 * (1024 * 1024)) and (xfo.FileSize <=  500 * (1024 * 1024)) then AddToZip := True;
                                   CMagnitude10 : if (xfo.FileSize >  500 * (1024 * 1024)) and (xfo.FileSize <= 1000 * (1024 * 1024)) then AddToZip := True;
                                   CMagnitude11 : if (xfo.FileSize > 1000 * (1024 * 1024)) and (xfo.FileSize <= 2000 * (1024 * 1024)) then AddToZip := True;
                                   CMagnitude12 : if (xfo.FileSize > 2000 * (1024 * 1024)) and (xfo.FileSize <= 5000 * Int64((1024 * 1024))) then AddToZip := True;
                                   CMagnitude13 : if (xfo.FileSize > 5000 * Int64(1024 * 1024)) then AddToZip := True;
                                 end;
                               end;
        CFileFilterOwner     : begin
                                 if (GScanDetails[aDataIndex].Users[xfo.Owner].Name) = StringContext then
                                   AddToZip := True;
                               end;
      end;

      if AddToZip then
        zipMaster.FSpecArgs.Add(GScanDetails[aDataIndex].Folders[xfo.FilePathIndex] + xfo.FileName);
    end;
  end;

  // ===========================================================================

  Result := zipMaster.FSpecArgs.Count;

  if zipMaster.FSpecArgs.Count = -1 then
    ShowXDialog(XText[rsErrorCompressingFiles], '', XDialogTypeWarning)
  else if zipMaster.FSpecArgs.Count = 0 then
    ShowXDialog(XText[rsNoFilesToCompress], '', XDialogTypeInformation)
  else begin
    try
      zipMaster.Add;
    except
      on e : exception do begin
        TMSLogger.Error('Zip error: ' + e.ClassName + ' / ' + e.Message);
      end;
    end;
  end;

  // ===========================================================================

  XSettings.HideZipWindow;
end;


function TZipFiles.ZipAllFiles(aFileName : string;
                               aObjectIndex : integer; aTable : TAdvStringGrid;
                               aFileNameColumn : integer): integer;
 var
  t : integer;
  lFileName : string;

 begin
  XSettings.ShowZipWindow;

  // ===========================================================================

  zipMaster.ZipFileName := aFileName;

  zipMaster.AddOptions  := [];
  zipMaster.AddOptions  := [AddRecurseDirs, AddDirNames, AddHiddenFiles, AddEmptyDirs];

  zipMaster.FSpecArgs.Clear;

  case aObjectIndex of
       1 : begin                                                                   // search
             for t := 1 to aTable.RowCount - 1 do begin
               if FileExists(aTable.Cells[aFileNameColumn, t]) then begin
                 zipMaster.FSpecArgs.Add(aTable.Cells[aFileNameColumn, t]);

                 XSettings.Forms.ZipForm.SetZipFileName('+ ' + aTable.Cells[aFileNameColumn, t]);
               end;
             end;
           end;
       2 : zipMaster.FSpecArgs.Add(aTable.Cells[aFileNameColumn, aTable.Selection.Top]);
       3 : begin                                                                   // top 101 small size
             for t := 1 to aTable.RowCount - 1 do begin
               if FileExists(aTable.Cells[aFileNameColumn, t]) then begin
                 zipMaster.FSpecArgs.Add(aTable.Cells[aFileNameColumn, t]);

                 XSettings.Forms.ZipForm.SetZipFileName('+ ' + aTable.Cells[aFileNameColumn, t]);
               end;
             end;
           end;
       4 : begin
             for t := 1 to aTable.RowCount - 1 do begin
               if aTable.RowSelect[t] then begin
                 if (aTable.Cells[sgnFolderFile, t] = '1') then
                   lFileName := GScanDetails[dataLatestScan].ScanPath + aTable.Cells[1, t] + '\*'
                 else
                   lFileName := GScanDetails[dataLatestScan].ScanPath + aTable.Cells[1, t];

                 zipMaster.FSpecArgs.Add(lFileName);

                 XSettings.Forms.ZipForm.SetZipFileName('+ ' + lFileName);
               end;
             end;
           end;
       5 : begin
             for t := 1 to aTable.RowCount - 1 do begin
               if aTable.RowSelect[t] then begin
                 if (aTable.Cells[sgnFolderFile, t] = '1') then
                   lFileName := GSystemGlobal.CurrentNavigationSideLocation + aTable.Cells[1, t] + '\*'
                 else
                   lFileName := GSystemGlobal.CurrentNavigationSideLocation + aTable.Cells[1, t];

                 zipMaster.FSpecArgs.Add(lFileName);

                 XSettings.Forms.ZipForm.SetZipFileName('+ ' + lFileName);
               end;
             end;
           end;
    6, 7 : begin                                                                   // top 101 small/big date
          for t := 1 to aTable.RowCount - 1 do begin
            if FileExists(aTable.Cells[aFileNameColumn, t]) then begin
              zipMaster.FSpecArgs.Add(aTable.Cells[aFileNameColumn, t]);

              XSettings.Forms.ZipForm.SetZipFileName('+ ' + aTable.Cells[aFileNameColumn, t]);
            end;
          end;
        end;
  end;

  // ===========================================================================

  Result := zipMaster.FSpecArgs.Count;

  try
    zipMaster.Add;
  except
    on e : exception do begin
      TMSLogger.Error('Zip error: ' + e.ClassName + ' / ' + e.Message);
    end;
  end;

  XSettings.HideZipWindow;
end;


end.
