{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.ScanAnalysis;

interface


uses
  System.SysUtils, System.StrUtils, dialogs,

  X.FindFile,

  X.CFileObject, X.CUserData, X.CRootFoldersData, X.FileExtension, X.ReportUtility,

  X.Conversions, X.Utility, X.Global, X.Settings, X.Constants, X.Dialogs.Dialog,
  X.FileExtensionsObject,

  X.CSizeOfFolder, X.Windows, X.LanguageHandler;


type
  TFoundTemp = procedure(aDataIndex : integer; const aFileName, aSizeWords, aSize : string) of object;
  TFoundNull = procedure(aDataIndex : integer; const aFileName : string) of object;

  TScanCount = procedure(const aCount : integer) of object;

  TFoundFile = procedure(const rt, sp, dt, aFileName : string; aSize : int64) of object;


  TXinorbisScan = class
  private
   FFoundNull : TFoundNull;
   FFoundTemp : TFoundTemp;
   FScanCount : TScanCount;

   FFoundFile : TFoundFile;

   FFindFile : TFindFile;
   FTag : integer;
   FSizeOfCurrentScanFolder : int64;
   FDataIndex : integer;

   FAllowVirtual : boolean;

   FileUsername : string;

   FMainCurrentFolder      : string;
   FMainCurrentFolderIndex : integer;

   FFileTotalSpace : Int64;
   FFileOnDisk     : Int64;
   FFileCount      : integer;
   FFolderCount    : integer;

   procedure ffMainFileMatch(const FileInfo: TFileDetails);
   procedure ffMainFolderChange(const Folder: String);
   procedure ffMainSearchBegin(Sender: TObject);

   procedure ffMainFileMatchReportList(const FileInfo: TFileDetails);
   procedure ffMainFolderChangeReportList(const Folder: String);
  public
    stopscan : boolean;

    constructor Create(aMode : integer);
    destructor Destroy; override;

    procedure Clear;
    function  Scan: boolean;
    function  Analyse: boolean;
    function  AnalyseData(cleardata : boolean): boolean;
    function  BuildRootListFromXinFiles: integer;

    procedure PrepareForFolderHistory;

    procedure SetFileScanMode;
    procedure SetReportScanMode;

    procedure ClearFilters;
    procedure SetScanFolder(aFolder : string);
    procedure AddExcludedFolder(aFolder : string);
    procedure AddExcludedFile(aFile : string);
    procedure SetExcludeModes(aIgnoreVirtual : boolean);

    function  SizeOfFolderNav(aSide : integer; const aFolderName : string): TSizeOfFolder;
    function  SizeOfFolder(const aFolderName : string): TSizeOfFolder;

    procedure AnalyseDataFromCSVImport(aDataIndex : integer);

    property AllowVirtual   : boolean read FAllowVirtual write FAllowVirtual;

    property Tag : integer read FTag write FTag;
    property SizeOfCurrentScanFolder : int64 read FSizeOfCurrentScanFolder write FSizeOfCurrentScanFolder;

    property DataIndex      : integer read FDataIndex write FDataIndex;

    property FileTotalSpace : Int64   read FFileTotalSpace;
    property FileOnDisk     : Int64   read FFileOnDisk;
    property FileCount      : integer read FFileCount;
    property FolderCount    : integer read FFolderCount;

    property OnFoundNull    : TFoundNull read FFoundNull write FFoundNull;
    property OnFoundTemp    : TFoundTemp read FFoundTemp write FFoundTemp;
    property OnScanCount    : TScanCount read FScanCount write FScanCount;

    property OnFoundFile    : TFoundFile read FFoundFile write FFoundFile;
  end;

implementation


uses
  X.GlobalObjects;


constructor TXinorbisScan.Create(aMode : integer);
begin
  FFindFile := TFindFile.Create(Nil);

  if aMode = 0 then
    SetFileScanMode
  else
    SetReportScanMode;

  FDataIndex := dataLatestScan;
end;


destructor TXinorbisScan.Destroy;
begin
  FreeAndNil(FFindFile);

  inherited;
end;


procedure TXinorbisScan.SetFileScanMode;
begin
  FFindFile.OnFolderChange := ffMainFolderChange;
  FFindFile.OnFileMatch    := ffMainFileMatch;
  FFindFile.OnSearchBegin  := ffMainSearchBegin;
end;


procedure TXinorbisScan.SetReportScanMode;
begin
  FFindFile.OnFileMatch    := ffMainFileMatchReportList;
  FFindFile.OnFolderChange := ffMainFolderChangeReportList;
end;


procedure TXinorbisScan.PrepareForFolderHistory;
begin
  FFileTotalSpace  := 0;
  FFileOnDisk      := 0;
  FFileCount       := 0;
  FFolderCount     := 0;
end;


// =============================================================================
// =============================================================================


procedure TXinorbisScan.Clear;
begin
  FFileTotalSpace  := 0;
  FFileOnDisk      := 0;
  FFileCount       := 0;
  FFolderCount     := 0;
end;


function TXinorbisScan.Scan: boolean;
begin
  Result := True;

  Clear;

  FFindFile.Execute;
end;


function TXinorbisScan.Analyse: boolean;
var
  lIndex : integer;
  idx, i, z, l : integer;
  s, tx, ext : string;
  found : boolean;

  rfd : TRootFoldersData;
  exi : TExtensionExistsIn;
  tfx : TFileExtension;
  tfo : TFileObject;
  tfr : TFileObject;

begin
  Result := True;

  for lIndex := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin

    try
      tfo := GScanDetails[FDataIndex].Files[lIndex];

      // =======================================================================
      // =================== ITEM IS A FILE ====================================
      // =======================================================================
      if ((faDirectory and tfo.Attributes) = 0) then begin

        if (faHidden and tfo.Attributes) = faHidden then begin
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Hidden, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Hidden, 1], tfo.FileSize);
        end;
        if (faSysFile and tfo.Attributes) = faSysFile then begin
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_System, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_System, 1], tfo.FileSize);
        end;
        if (faArchive and tfo.Attributes) = faArchive then begin
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Archive, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Archive, 1], tfo.FileSize);
        end;
        if (faReadOnly and tfo.Attributes) = faReadOnly then begin
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_ReadOnly, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_ReadOnly, 1], tfo.FileSize);
        end;
        if (faCompressed and tfo.Attributes) = faCompressed then begin
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Compressed, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Compressed, 1], tfo.FileSize);
        end;
        if (faEncrypted and tfo.Attributes) = faEncrypted then begin
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Encrypted, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Encrypted, 1], tfo.FileSize);
        end;
        if (faRecallOnOpen and tfo.Attributes) = faRecallOnOpen then begin
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_RecallOnOpen, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_RecallOnOpen, 1], tfo.FileSize);
        end;
        if (faRecallOnDataAccess and tfo.Attributes) = faRecallOnDataAccess then begin
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_RecallOnDataAccess, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_RecallOnDataAccess, 1], tfo.FileSize);
        end;
        if (faOffline and tfo.Attributes) = faOffline then begin
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Offline, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_Offline, 1], tfo.FileSize);
        end;

        if tfo.FileDateC = GScanDetails[FDataIndex].TodayAsInteger then begin                 // file is created today
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_CreatedToday, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_CreatedToday, 1], tfo.FileSize);
        end;

        if tfo.FileDateA = GScanDetails[FDataIndex].TodayAsInteger then begin                 // file is accessed today
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_AccessedToday, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_AccessedToday, 1], tfo.FileSize);
        end;

        if tfo.FileDateM = GScanDetails[FDataIndex].TodayAsInteger then begin                 // file is modified today
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_ModifiedToday, 0]);
          inc(GScanDetails[FDataIndex].FileAttributes[FileType_ModifiedToday, 1], tfo.FileSize);
        end;

        // =====================================================================
        // == update data ONLY for non-virtual files ---------------------------
        // =====================================================================

        if (FAllowVirtual) or (not((faRecallOnDataAccess and tfo.Attributes) = faRecallOnDataAccess) and
           not((faRecallOnOpen and tfo.Attributes)       = faRecallOnOpen)       and
           not((faOffline and tfo.Attributes)            = faOffline)) then begin

          inc(FFileCount);
          inc(FFileTotalSpace, tfo.FileSize);
          inc(FFileOnDisk,     tfo.FileSizeOnDisk);

          // ===================================================================
          // ===================================================================

          ext := LowerCase(ExtractFileExt(tfo.FileName));
          ext := Copy(ext, 2, length(ext) - 1);

          exi := FileExtensionsObject.GetExtensionCategoryID(ext);

          if exi.NotFound then begin  // "other" extension
            inc(GScanDetails[FDataIndex].ExtensionSpread[__FileCategoriesOther, 1]);

            GScanDetails[FDataIndex].ExtensionSpread[__FileCategoriesOther, 2] := GScanDetails[FDataIndex].ExtensionSpread[__FileCategoriesOther, 2] + tfo.FileSize;

            tfx := TFileExtension.Create;
            tfx.Name                := ext;
            tfx.Category            := Category_Other;
            tfx.Quantity[FDataIndex] := 1;
            tfx.Size[FDataIndex]     := tfo.FileSize;

            FileExtensionsObject.CategoryExtensions.Add(tfx);

            tfo.FileCategory        := __FileCategoriesOther;
          end
          else begin
            inc(GScanDetails[FDataIndex].ExtensionSpread[exi.RawCategory, 1]);
            inc(GScanDetails[FDataIndex].ExtensionSpread[exi.RawCategory, 2], tfo.FileSize);

            inc(FileExtensionsObject.CategoryExtensions[exi.RawCategory].Quantity[FDataIndex]);
            inc(FileExtensionsObject.CategoryExtensions[exi.RawCategory].Size[FDataIndex], tfo.FileSize);

            tfo.FileCategory := exi.RawCategory;
          end;

          // =====================================================================
          // =====================================================================

          l := length(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName);

          if l < 280 then begin
            inc(GScanDetails[FDataIndex].NameLengthCount[l - 1]);
            inc(GScanDetails[FDataIndex].NameLengthSize[l - 1], tfo.FileSize);
          end
          else begin
            inc(GScanDetails[FDataIndex].NameLengthCount[279]);
            inc(GScanDetails[FDataIndex].NameLengthSize[279], tfo.FileSize);
          end;

          // =======================================================================
          // now lets put the size into the magnitude section ----------------------
          // =======================================================================

          if (tfo.FileSize >= 0) and (tfo.FileSize <= 1024) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  0, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  0, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  0, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  0, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       0, 0] := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      0, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       0, 1] := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      0, 1] + tfo.FileSize;

            if tfo.FileSize = 0 then begin                               // file is null length
              inc(GScanDetails[FDataIndex].FileAttributes[FileType_Null, 0]);
            end;
          end
          else if (tfo.FileSize > 1024) and (tfo.FileSize <= (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  1, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  1, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  1, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  1, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       1, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      1, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       1, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      1, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > (1024 * 1024)) and (tfo.FileSize <= 10 * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  2, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  2, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  2, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  2, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       2, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      2, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       2, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      2, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > 10 * (1024 * 1024)) and (tfo.FileSize <= 50 * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  3, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  3, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  3, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  3, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       3, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      3, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       3, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      3, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > 50 * (1024 * 1024)) and (tfo.FileSize <= 100 * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  4, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  4, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  4, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  4, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       4, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      4, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       4, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      4, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > 100 * (1024 * 1024)) and (tfo.FileSize <= 150 * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  5, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  5, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  5, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  5, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       5, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      5, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       5, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      5, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > 150 * (1024 * 1024)) and (tfo.FileSize <= 200 * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  6, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  6, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  6, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  6, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       6, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      6, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       6, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      6, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > 200 * (1024 * 1024)) and (tfo.FileSize <= 250 * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  7, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  7, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  7, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  7, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       7, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      7, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       7, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      7, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > 250 * (1024 * 1024)) and (tfo.FileSize <= 500 * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  8, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  8, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  8, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  8, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       8, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      8, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       8, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      8, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > 500 * (1024 * 1024)) and (tfo.FileSize <= 1000 * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  9, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  9, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  9, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll,  9, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       9, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      9, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,       9, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      9, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > 1000 * (1024 * 1024)) and (tfo.FileSize <= 2000 * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 10, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 10, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 10, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 10, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      10, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,     10, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      10, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,     10, 1] + tfo.FileSize;
          end
          else if (tfo.FileSize > 2000 * (1024 * 1024)) and (tfo.FileSize <= Int64(5000) * (1024 * 1024)) then begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 11, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 11, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 11, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 11, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      11, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,     11, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      11, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,     11, 1] + tfo.FileSize;
          end
          else begin
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 12, 0] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 12, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 12, 1] := GScanDetails[FDataIndex].Magnitude.Data[Category_MagnitudeAll, 12, 1] + tfo.FileSize;

            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      12, 0]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,     12, 0] + 1;
            GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,      12, 1]  := GScanDetails[FDataIndex].Magnitude.Data[tfo.FileCategory,     12, 1] + tfo.FileSize;
          end;

          // =======================================================================
          // process usernames -----------------------------------------------------
          // =======================================================================

          if (XSettings.Optimisations.GetUserDetails) then begin
            if (tfo.FileCategory <> FileCategoryDirectory) then begin
              inc(GScanDetails[FDataIndex].Users[tfo.owner].CategoryDataQty[tfo.FileCategory]);
              inc(GScanDetails[FDataIndex].Users[tfo.owner].CategoryDataSize[tfo.FileCategory], tfo.FileSize);
            end;

            inc(GScanDetails[FDataIndex].Users[tfo.owner].Data[XUserCount]);
            inc(GScanDetails[FDataIndex].Users[tfo.owner].Data[XUserSize], tfo.FileSize);
          end;
        end;

        // =======================================================================
        // process folder path ---------------------------------------------------
        // =======================================================================

        if (tfo.FilePathIndex = 0) then begin
          tfr := TFileObject.Create;

          tfr.FileName       := tfo.FileName;
          tfr.FilePathIndex  := tfo.FilePathIndex;
          tfr.FileSize       := tfo.FileSize;
          tfr.FileSizeOnDisk := tfo.FileSizeOnDisk;
          tfr.FileDateC      := tfo.FileDateC;
          tfr.FileDateA      := tfo.FileDateA;
          tfr.FileDateM      := tfo.FileDateM;
          tfr.Attributes     := tfo.Attributes;
          tfr.Owner          := tfo.Owner;

          s := LowerCase(ExtractFileExt(tfo.FileName));
          s := Copy(s, 2, length(s) - 1);

          tfr.FileCategory   := FileExtensionsObject.GetExtensionCategoryID(s).RawCategory;

          GScanDetails[FDataIndex].RootFiles.Add(tfr);
        end
        else if tfo.FilePathIndex > GScanDetails[FDataIndex].Folders.Count - 1 then begin
          tfo.FilePathIndex := 0;
        end;

        // =======================================================================
        // process temporary file types ------------------------------------------
        // =======================================================================
		    tfo.Temp := False;
		
        if (XSettings.Optimisations.GetTempFiles) then begin
          z := 0;

          s := UpperCase(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName);

          found := False;

          while (not(found)) and (z < FileExtensionsObject.CategoryExtensions.Count) do begin
            tfx := FileExtensionsObject.CategoryExtensions[z];

            if tfx.Category = Category_Temp then begin
              //found:=MatchesMask(s, tfx.Name);

              tx := UpperCase(tfx.Name);

              if Pos('*', tx) <> 0 then begin
                i := Pos('*', tx);

                if i = 1 then begin                   // first character is *
                  if tx[length(tx)] = '*' then begin  // last character is also * ; eg *.~*
                    if Pos(Copy(tx, 2, length(tx) - 2), s) <> 0 then
                      found := True;
                  end
                  else begin
                    if Pos(Copy(tx, 2, length(tx) - 1), s) <> 0 then
                      found := True;
                  end;
                end
                else begin
                  if Pos(Copy(tx, 1, length(tx) - 1), s) = 1 then
                    found := True;
                end;
              end
              else if Pos(tx, s) <> 0 then begin
                found := True;
              end;
            end;

            inc(z);
          end;

          if found then begin
            if Assigned(FFoundTemp) then   // to do add dataindex
              FFoundTemp(FDataIndex,
                         GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName,
                         TConvert.ConvertToUsefulUnit(tfo.FileSize),
                         IntToStr(tfo.FileSize));

            inc(GScanDetails[FDataIndex].ExtensionSpread[Category_Temp, 1]);
            inc(GScanDetails[FDataIndex].ExtensionSpread[Category_Temp, 2], tfo.FileSize);

            tfo.Temp := True;
          end;
        end;
      end
      else begin // == ITEM IS A FOLDER ========================================

        tfo.FileCategory := FileCategoryDirectory;

        inc(FFolderCount);

        if (tfo.FilePathIndex = 0) then begin // GScanDetails.ScanPath = GScanDetails.Folders[tfo.FilePathIndex]
          tfr := TFileObject.Create;

          tfr.FileName       := tfo.FileName;
          tfr.FilePathIndex  := tfo.FilePathIndex;
          tfr.FileSize       := tfo.FileSize;
          tfr.FileSizeOnDisk := tfo.FileSizeOnDisk;
          tfr.FileDateC      := tfo.FileDateC;
          tfr.FileDateA      := tfo.FileDateA;
          tfr.FileDateM      := tfo.FileDateM;
          tfr.Attributes     := tfo.Attributes;
          tfr.Owner          := tfo.Owner;

          s := LowerCase(ExtractFileExt(tfo.FileName));
          s := Copy(s, 2, length(s) - 1);

          GScanDetails[FDataIndex].RootFiles.Add(tfr);

          idx := -1;
          s   := GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName;

          for i := 1 to length(s) do
            if s[i] = '\' then
              idx := i;

          if idx <> -1 then begin
            rfd := TRootFoldersData.Create;

            rfd.Name       := (Copy(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName,
                                    idx + 1,
                                    length(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName) - idx + 1));
            rfd.Attributes := tfo.Attributes;

            GScanDetails[FDataIndex].RootFolders.Add(rfd);
          end;
        end;
      end
    except
      Result := False;
    end;
    {
    if (lIndex mod 5000) = 0 then
    begin
      if Assigned(FScanCount) then
      begin
        FScanCount(lIndex);

        //Application.ProcessMessages;
      end;
    end;}
  end;
end;


function TXinorbisScan.AnalyseData(cleardata : boolean): boolean;
 var
  i, t, lucy : integer;

  tud : TUserData;
  tfo : TFileObject;

 begin
  Assert((FDataIndex >= 0) and (FDataIndex <= 2), 'AnalyseData :: invalid dataindex :: ' + inttostr(FDataIndex));

  try

//    XSettings.ProgressForm.SetProcessBar(3);

    // -------------------------------------------------------------------------

//    case DATAINDEX of
//      dataLatestScan  : GScanDetails[DataIndex].RootFiles.Sort(@CompareFileNamePathLS);   GScanDetails[DataIndex].Files.Sort(TComparer<TFolderHistoryInfo>.Construct(CompareFileNamePathTreeLS));
//      dataFileHistory : GScanDetails[DataIndex].RootFiles.Sort(@CompareFileNamePathFH);   GScanDetails[DataIndex].Files.Sort(TComparer<TFolderHistoryInfo>.Construct(CompareFileNamePathTreeLS));
//    end;


  {  for t := 0 to GScanDetails[DataIndex].RootFiles.Count-1 do begin
      tfo := GScanDetails[DataIndex].RootFiles.Items[t];

      if (faDirectory and tfo.Attributes)=faDirectory then begin
        idx := -1;
        s   := GScanDetails[DataIndex].Folders[tfo.FilePathIndex] + tfo.FileName;

        for i := 1 to length(s) do
          if s[i] = '\' then
            idx:=i;

        if idx <> -1 then begin
          rfd := TRootFoldersData.Create;

          rfd.Name       := (Copy(GScanDetails[DataIndex].Folders[tfo.FilePathIndex] + tfo.FileName, idx + 1, length(GScanDetails[DataIndex].Folders[tfo.FilePathIndex]+tfo.FileName) - idx + 1));
          rfd.Attributes := tfo.Attributes;

          GScanDetails[DataIndex].RootFolders.Add(rfd);
        end;
      end;
    end; }

    // -------------------------------------------------------------------------

//    XSettings.ProgressForm.SetProcessBar(4);

    for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin

      tfo := GScanDetails[FDataIndex].Files[t];

      // =======================================================================
      // =================== ITEM IS A FILE ====================================
      // =======================================================================
      if ((faDirectory and tfo.Attributes) = 0) then begin

        // == IS THIS FILE IN A ROOT FOLDER? ===================================
        lucy := -1;
        i    := 1;

        while (lucy =- 1) and (i < GScanDetails[FDataIndex].RootFolders.Count) do begin
        //---------------------------------------------------------------------------------------------+'\'
          if AnsiStartsStr(GScanDetails[FDataIndex].ScanPath + GScanDetails[FDataIndex].RootFolders[i].Name + '\',
                           GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName) then begin
            inc(GScanDetails[FDataIndex].RootFolders[i].Data[XRootCount]);
            inc(GScanDetails[FDataIndex].RootFolders[i].Data[XRootSize], tfo.FileSize);

            lucy := i;
          end;

          inc(i);
        end;

        //must be in root directory
        if lucy = -1 then begin
          inc(GScanDetails[FDataIndex].RootFolders[0].Data[XRootCount]);
          inc(GScanDetails[FDataIndex].RootFolders[0].Data[XRootSize], tfo.FileSize);
        end;
      end;
    end;

//    XSettings.ProgressForm.SetPercentage('100%');
//    XSettings.ProgressForm.SetStatus3(IntToStr(GScanDetails[FDataIndex].Files.Count));
  except
    ShowXDialog(XText[rsError],
                XText[rsDialog13],
                XDialogTypeWarning);
  end;

  if not(XSettings.Optimisations.GetUserDetails) then begin
    tud      := TUserData.Create;
    tud.Name := XText[rsNOT_SPECIFIED];

    GScanDetails[FDataIndex].Users.Add(tud);

    GScanDetails[FDataIndex].Users[0].Data[XUserCount] := GScanDetails[FDataIndex].FileCount;
    GScanDetails[FDataIndex].Users[0].Data[XUserSize]  := GScanDetails[FDataIndex].TotalSize;
  end;
end;


function TXinorbisScan.BuildRootListFromXinFiles: integer;
 var
  t : integer;
  tfr, tfo : TFileObject;
  s : string;

 begin
  Assert((FDataIndex >= 0) and (FDataIndex <= 1), 'BuildRootListFromXinFiles :: invalid dataindex :: ' + inttostr(FDataIndex));

  Result := 0;

  GScanDetails[FDataIndex].RootFiles.Clear;

  for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
    tfo := GScanDetails[FDataIndex].Files[t];

    if tfo.FilePathIndex > GScanDetails[FDataIndex].Folders.Count - 1 then begin
      inc(Result);

      tfo.FilePathIndex := 0;
    end
    else if (tfo.FilePathIndex = 0) then begin
      tfr := TFileObject.Create;

      tfr.FileName       := tfo.FileName;
      tfr.FilePathIndex  := tfo.FilePathIndex;
      tfr.FileSize       := tfo.FileSize;
      tfr.FileSizeOnDisk := tfo.FileSizeOnDisk;
      tfr.FileDateC      := tfo.FileDateC;
      tfr.FileDateA      := tfo.FileDateA;
      tfr.FileDateM      := tfo.FileDateM;
      tfr.Attributes     := tfo.Attributes;
      tfr.Owner          := tfo.Owner;

      s := LowerCase(ExtractFileExt(tfo.FileName));
      s := Copy(s, 2, length(s) - 1);

      tfr.FileCategory   := FileExtensionsObject.GetExtensionCategoryID(s).RawCategory;

      GScanDetails[FDataIndex].RootFiles.Add(tfr);
    end;
  end;
end;


// =============================================================================
// =============================================================================


procedure TXinorbisScan.ClearFilters;
begin
  FFindFile.Criteria.Files.Filters.Clear;
end;


procedure TXinorbisScan.SetScanFolder(aFolder : string);
begin
  FFindFile.Criteria.Files.Location := aFolder;
end;


procedure TXinorbisScan.AddExcludedFolder(aFolder : string);
begin
  FFindFile.Criteria.Files.Filters.Add(aFolder);
end;


procedure TXinorbisScan.AddExcludedFile(aFile : string);
begin
  FFindFile.Criteria.Files.Filters.Add(aFile);
end;


procedure TXinorbisScan.SetExcludeModes(aIgnoreVirtual : boolean);
begin
  FFindFile.IgnoreVirtual := aIgnoreVirtual;
end;


// =============================================================================
// =============================================================================

// processes based on navigation frame display types
function TXinorbisScan.SizeOfFolderNav(aSide : integer; const aFolderName : string): TSizeOfFolder;
 var
  t : integer;

 begin
  Assert(aFolderName <> '', 'SizeOfFolder :: blank input error');

  Result.Data[XFileUsed]  := 0;
  Result.Data[XSpaceUsed] := 0;
  Result.Data[XCount]     := 0;

  t := 0;

  while (t < GScanDetails[FDataIndex].Files.Count) do begin
    if GScanDetails[FDataIndex].Files.Items[t].FileCategory <> FileCategoryDirectory then begin

      if (XSettings.Navigation.DisplayOptions[aSide][GScanDetails[FDataIndex].Files.Items[t].FileCategory] = '1') then begin

        if AnsiStartsStr(aFolderName + '\', GScanDetails[FDataIndex].Folders[GScanDetails[FDataIndex].Files.Items[t].FilePathIndex]) then begin
          inc(Result.Data[XFileUsed],  GScanDetails[FDataIndex].Files.Items[t].FileSize);
          inc(Result.Data[XSpaceUsed], GScanDetails[FDataIndex].Files.Items[t].FileSizeOnDisk);

         // showmessage(afoldername + '\' + GScanDetails[FDataIndex].Folders[GScanDetails[FDataIndex].Files.Items[t].FilePathIndex]);

          inc(Result.Data[XCount]);
        end;
      end;

    end;

    inc(t);
  end;
end;


function TXinorbisScan.SizeOfFolder(const aFolderName : string): TSizeOfFolder;
 var
  t : integer;

 begin
  Assert(aFolderName <> '', 'SizeOfFolder :: blank input error');

  Result.Data[XFileUsed]  := 0;
  Result.Data[XSpaceUsed] := 0;
  Result.Data[XCount]     := 0;

  t := 0;

  while (t < GScanDetails[FDataIndex].Files.Count) do begin
    if GScanDetails[FDataIndex].Files.Items[t].FileCategory <> FileCategoryDirectory then begin

      if AnsiStartsStr(aFolderName + '\', GScanDetails[FDataIndex].Folders[GScanDetails[FDataIndex].Files.Items[t].FilePathIndex]) then begin
        inc(Result.Data[XFileUsed],  GScanDetails[FDataIndex].Files.Items[t].FileSize);
        inc(Result.Data[XSpaceUsed], GScanDetails[FDataIndex].Files.Items[t].FileSizeOnDisk);

       // showmessage(afoldername + '\' + GScanDetails[FDataIndex].Folders[GScanDetails[FDataIndex].Files.Items[t].FilePathIndex]);

        inc(Result.Data[XCount]);
      end;

    end;

    inc(t);
  end;
end;


// =============================================================================
// =============================================================================


procedure TXinorbisScan.ffMainFolderChange(const Folder: String);
 begin
  if SizeOfCurrentScanFolder = 0 then begin
    if Assigned(FFoundNull) then
      FFoundNull(dataLatestScan, FMainCurrentFolder);
  end;

  SizeOfCurrentScanFolder := 0;

  FMainCurrentFolder := Folder;

  FMainCurrentFolderIndex := GScanDetails[dataLatestScan].Folders.Add(Folder);
end;


procedure TXinorbisScan.ffMainFileMatch(const FileInfo: TFileDetails);
 var
  z, lCount : integer;
  xfo : TFileObject;
  tud : TUserData;

 begin
  xfo := TFileObject.Create;

  xfo.FileName      := FileInfo.Name;
  //xfo.FilePath    := FFMainCurrentFolder;
  xfo.FilePathIndex := FMainCurrentFolderIndex;
  xfo.FileSize      := FileInfo.Size;
  xfo.FileDateC     := TConvert.DateTimeToInteger(FileInfo.CreatedTime);
  xfo.FileDateA     := TConvert.DateTimeToInteger(FileInfo.AccessedTime);
  xfo.FileDateM     := TConvert.DateTimeToInteger(FileInfo.ModifiedTime);
  xfo.FileTimeC     := TConvert.DateTimeToTimeWord(FileInfo.CreatedTime);
  xfo.FileTimeA     := TConvert.DateTimeToTimeWord(FileInfo.AccessedTime);
  xfo.FileTimeM     := TConvert.DateTimeToTimeWord(FileInfo.ModifiedTime);
  xfo.Attributes    := FileInfo.Attributes;

  if (faDirectory and FileInfo.Attributes) = faDirectory then begin
    xfo.FileSizeOnDisk := 0;
    xfo.FileSize       := 0;

    inc(FSizeOfCurrentScanFolder);
  end
  else begin
    if drivesectorsize <> 0 then
      xfo.FileSizeOnDisk := TConvert.GetSizeOnDisk(xfo.FileSize)
    else
      xfo.FileSizeOnDisk := xfo.FileSize;

    inc(FSizeOfCurrentScanFolder);

    if XSettings.Optimisations.GetUserDetails then begin
      //TXWindows.GetFileOwner(FMainCurrentFolder + FileInfo.Name, filedomain, fileusername);
      TXWindows.GetFileOwner(FMainCurrentFolder + FileInfo.Name, fileusername);

      if fileusername = '' then
        fileusername := XText[rsNOT_SPECIFIED];

      z := TUtility.FindUserIndex(dataLatestScan, fileusername);
      if z = -1 then begin
        tud      := TUserData.Create;
        tud.Name := fileusername;

        z := GScanDetails[dataLatestScan].Users.Add(tud);
      end;

      xfo.Owner := z;
    end
    else
      xfo.Owner := 0;
  end;

  lCount := GScanDetails[dataLatestScan].Files.Add(xfo);

  if (lCount mod XSettings.ProgressFileCount) = 0 then begin
    if Assigned(FScanCount) then
    begin
      FScanCount(lCount);

      //Application.ProcessMessages;
    end;
  end;
end;


procedure TXinorbisScan.ffMainSearchBegin(Sender: TObject);
 begin
   drivesectorsize := TXWindows.GetDriveDetails(FFindFile.Criteria.Files.Location).SectorSize;
end;


// =============================================================================


procedure TXinorbisScan.ffMainFolderChangeReportList(const Folder: String);
 begin
  {}
end;


procedure TXinorbisScan.ffMainFileMatchReportList(const FileInfo: TFileDetails);
 var
  rt, sp, dt, s, fn : string;
  t : integer;

 begin
  if Pos('_', FileInfo.Name) <> 0 then begin
    try
      rt := '0';

      case GReportUtility.GetReportType(FileInfo.Name) of
        CReportTypeCSV      : rt := '2';
        CReportTypeHTML     : rt := '3';
        CReportTypeTree     : rt := '4';
        CReportTypeXinorbis : rt := '6';
        CReportTypeXML      : rt := '7';
      end;

      if rt <> '0' then begin
        s := FileInfo.Name;

        if Pos('FH_', FileInfo.Name) = 1 then
          s := Copy(s, 4, Length(FileInfo.Name) - 3);

        dt := Copy(s, Length(s) - (14 + Length(ExtractFileExt(s))), length(s));
        dt := StringReplace(dt, '_', '', [rfReplaceAll]);

        sp := Copy(s, 1, length(s) - (15 + Length(ExtractFileExt(s))));
        sp := StringReplace(sp, '__', '\\', [rfReplaceAll]);

        for t := 1 to length(sp) do
          if (t <> 2) and (sp[t] = '_') then
            sp[t] := '?';

        sp := StringReplace(sp, '_', ':\', [rfReplaceAll]);
        sp := StringReplace(sp, '?', '\', [rfReplaceAll]);

        fn := FMainCurrentFolder + FileInfo.Name;

        if Assigned(FFoundFile) then
          FFoundFile(rt, sp, dt, fn, FileInfo.Size);
      end;
    except
    end;
  end;
end;


procedure TXinorbisScan.AnalyseDataFromCSVImport(aDataIndex : integer);
var
  ext : string;
  t, i, idx, lucy : integer;
  s : string;
  xfo : TFileObject;
  tfr : TFileObject;
  tfx : TFileExtension;
  exi : TExtensionExistsIn;
  rfd : TRootFoldersData;

begin
  for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
      xfo := GScanDetails[aDataIndex].Files.Items[t];

      //--------------------------------------------------------------------
      ext := LowerCase(ExtractFileExt(xfo.FileName));

      //-- is dir or file --------------------------------------------------------
      if (faDirectory and xfo.Attributes) = faDirectory then begin
        inc(GScanDetails[aDataIndex].FolderCount);

        xfo.FileCategory := FileCategoryDirectory;

        if GScanDetails[aDataIndex].ScanPath = GScanDetails[aDataIndex].Folders[xfo.FilePathIndex] then begin
          tfr := TFileObject.Create;

          tfr.FileName       := xfo.FileName;
          tfr.FilePathIndex  := xfo.FilePathIndex;
          tfr.FileSize       := xfo.FileSize;
          tfr.FileSizeOnDisk := xfo.FileSizeOnDisk;
          tfr.FileDateC      := xfo.FileDateC;
          tfr.FileDateA      := xfo.FileDateA;
          tfr.FileDateM      := xfo.FileDateM;
          tfr.Attributes     := xfo.Attributes;
          tfr.Owner          := xfo.Owner;

          s := LowerCase(ExtractFileExt(xfo.FileName));
          s := Copy(s, 2, length(s) - 1);

          tfr.FileCategory := FileCategoryDirectory;

          GScanDetails[aDataIndex].RootFiles.Add(tfr);

          idx := -1;
          s   := GScanDetails[aDataIndex].Folders[xfo.FilePathIndex] + xfo.FileName;

          for i := 1 to length(s) do
            if s[i] = '\' then
              idx := i;

          if idx <> -1 then begin
            rfd := TRootFoldersData.Create;

            rfd.Name       := (Copy(GScanDetails[aDataIndex].Folders[xfo.FilePathIndex] + xfo.FileName,
                                    idx + 1,
                                    length(GScanDetails[aDataIndex].Folders[xfo.FilePathIndex] + xfo.FileName) - idx + 1));
            xfo.Attributes := xfo.Attributes;

            GScanDetails[aDataIndex].RootFolders.Add(rfd);
          end;
        end;
      end
      else begin
        inc(GScanDetails[aDataIndex].FileCount);

        ext := Copy(ext, 2, length(ext) - 1);
        exi := FileExtensionsObject.GetExtensionCategoryID(ext);

        if exi.NotFound then begin  // "other" extension
          inc(GScanDetails[aDataIndex].ExtensionSpread[__FileCategoriesOther, 1]);
          inc(GScanDetails[aDataIndex].ExtensionSpread[__FileCategoriesOther, 2], xfo.FileSize);

          tfx := TFileExtension.Create;
          tfx.Name                := ext;
          tfx.Category            := Category_Other;
          tfx.Quantity[aDataIndex] := 1;
          tfx.Size[aDataIndex]     := xfo.FileSize;

          FileExtensionsObject.CategoryExtensions.Add(tfx);

          xfo.FileCategory := __FileCategoriesOther;
        end
        else begin
          inc(GScanDetails[FDataIndex].ExtensionSpread[exi.RawCategory, 1]);
          inc(GScanDetails[FDataIndex].ExtensionSpread[exi.RawCategory, 2], xfo.FileSize);

          inc(FileExtensionsObject.CategoryExtensions[exi.RawCategory].Quantity[FDataIndex]);
          inc(FileExtensionsObject.CategoryExtensions[exi.RawCategory].Size[FDataIndex], xfo.FileSize);

          xfo.FileCategory := i;
        end;

        // =======================================================================
        // =================== ITEM IS A FILE ====================================
        // =======================================================================

        // == IS THIS FILE IN A ROOT FOLDER? ===================================
        lucy := -1;
        i    := 1;
        while (lucy =- 1) and (i < GScanDetails[aDataIndex].RootFolders.Count) do begin
        //---------------------------------------------------------------------------------------------+'\'
          if AnsiStartsStr(GScanDetails[aDataIndex].ScanPath + GScanDetails[aDataIndex].RootFolders[i].Name + '\',
                           GScanDetails[aDataIndex].Folders[xfo.FilePathIndex] + xfo.FileName) then begin
            inc(GScanDetails[aDataIndex].RootFolders[i].Data[XRootCount]);
            inc(GScanDetails[aDataIndex].RootFolders[i].Data[XRootSize], xfo.FileSize);

            lucy := i;
          end;

          inc(i);
        end;

        //must be in root directory
        if lucy = -1 then begin
          inc(GScanDetails[aDataIndex].RootFolders[0].Data[XRootCount]);
          inc(GScanDetails[aDataIndex].RootFolders[0].Data[XRootSize], xfo.FileSize);
        end;
      end;

      if XSettings.Optimisations.GetUserDetails then begin
        if (xfo.FileCategory <> FileCategoryDirectory) then begin
          inc(GScanDetails[aDataIndex].Users[xfo.Owner].CategoryDataQty[xfo.FileCategory]);
          inc(GScanDetails[aDataIndex].Users[xfo.Owner].CategoryDataSize[xfo.FileCategory], xfo.FileSize);
        end;
      end;
    end;
end;


end.
