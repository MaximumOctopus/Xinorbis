{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: December 14th 2015
  Last Modified: January 11th 2020
}


unit X.Thread.AanalyseData;

interface

uses SysUtils, classes, AdvGrid, SyncObjs, X.Utility,

     X.Settings, X.Global, progressdisplay;

type
  TAnalyseDataThread = class(TThread)
    procedure SetData(aDataIndex : integer; asgTemp : TAdvStringGrid);
  private
    FFileTotalSpace : Int64;
    FFileOnDisk     : Int64;
    FFileCount      : integer;
    FFolderCount    : integer;
    FFinished       : boolean;

    FCriticalSection: TCriticalSection;

    procedure ProcessObject(aIndex : integer);
  public
    property FileTotalSpace : Int64   read FFileTotalSpace;
    property FileOnDisk     : Int64   read FFileOnDisk;
    property FileCount      : integer read FFileCount;
    property FolderCount    : integer read FFolderCount;
    property Finish         : boolean read FFinished        write FFinished;

    destructor Destroy; override;    
  protected
    DATAINDEX : integer;
    sgTTemp   : TAdvStringGrid;

    procedure Execute; override;
  end;

implementation

uses
  X.Constants, X.CFileObject, X.CUserData, rootfoldersdata, fileextension;


destructor TAnalyseDataThread.Destroy;
begin
  FCriticalSection.Free;

  inherited;
end;

procedure TAnalyseDataThread.SetData(aDataIndex : integer; asgTemp : TAdvStringGrid);
 begin
  DATAINDEX        := aDataIndex;
  sgTTemp          := asgTemp;

  FFileTotalSpace  := 0;
  FFileOnDisk      := 0;
  FFileCount       := 0;
  FFolderCount     := 0;
  FFinished        := False;

  FCriticalSection := TCriticalSection.Create;
end;

procedure TAnalyseDataThread.Execute;
 var
  lIndex, lCount, lAttribute : integer;
  lFinished : boolean;

 begin
//  FreeOnTerminate := True;
  lFinished  := False;

  while (XSettings.ProgressForm <> Nil) and (lFinished = False) do begin

    // =========================================================================

    FCriticalSection.Acquire;

    lCount := GScanDetails[DataIndex].Files.Count;

    FCriticalSection.Leave;

    // =========================================================================

    if lCount <> 0 then
    begin
      lIndex := lCount - 1;

      FCriticalSection.Acquire;

        if lIndex >= 0 then
          lAttribute := (GScanDetails[DataIndex].Files[lIndex].Attributes and $80000)
        else
          lAttribute := -1;

      FCriticalSection.Leave;

      while (lIndex >= 0) and (lAttribute = 0) do begin

        // =====================================================================
        // =====================================================================

        ProcessObject(lIndex);

        // =====================================================================
        // =====================================================================

        dec(lIndex);

        if lIndex >= 0 then begin
          FCriticalSection.Acquire;

            lAttribute := (GScanDetails[DataIndex].Files[lIndex].Attributes and $80000);

          FCriticalSection.Leave;
        end;
      end;

    end;

    FCriticalSection.Acquire;

    lCount := GScanDetails[DataIndex].Files.Count;

    FCriticalSection.Leave;

    //Sleep(25);

    XSettings.ProgressForm.SetStatus3(IntToStr(lCount));

    FCriticalSection.Acquire;

    if (FFinished = True) and (((GScanDetails[DataIndex].Files[0].Attributes and $80000) = $80000)) and
       (((GScanDetails[DataIndex].Files[GScanDetails[DataIndex].Files.Count - 1].Attributes and $80000) = $80000)) then
       lFinished := True;

    FCriticalSection.Leave;
  end;
end;

procedure TAnalyseDataThread.ProcessObject(aIndex : integer);
 var
  toi, temp, idx, extidx, xtidx, xinc, i, t, z, lucy, modval : integer;
  s, tx, str, ext : string;
  searchrec : TSearchRec;
  found : boolean;

  tud : TUserData;
  rfd : TRootFoldersData;
  exi : TExtensionExistsIn;
  tfx : TFileExtension;
  tfo : TFileObject;
  tfr : TFileObject;
  
 begin
  FCriticalSection.Acquire;

  try
    tfo := GScanDetails[DataIndex].Files[aIndex];

    tfo.Attributes := tfo.Attributes or $80000;

   // =======================================================================
    // =================== ITEM IS A FILE ====================================
    // =======================================================================
    if ((faDirectory and tfo.Attributes) = 0) then begin

      // =====================================================================
      // =====================================================================
      ext := LowerCase(ExtractFileExt(tfo.FileName));
      ext := Copy(ext, 2, length(ext) - 1);

      exi := GetExtensionCategoryID(ext);

      if exi.NotFound then begin  // "other" extension
        inc(extspread[DATAINDEX, __FileCategoriesOther, 1]);
        extspread[DATAINDEX, __FileCategoriesOther, 2] := extspread[DATAINDEX, __FileCategoriesOther, 2] + tfo.FileSize;

        tfx := TFileExtension.Create;
        tfx.Name                := ext;
        tfx.Category            := Category_Other;
        tfx.Quantity[DATAINDEX] := 1;
        tfx.Size[DATAINDEX]     := tfo.FileSize;
        Extensions.Add(tfx);

        tfo.FileCategory        := __FileCategoriesOther;
      end
      else begin
        inc(GScanDetails[FDataIndex].ExtensionSpread[exi.RawCategory, 1]);
        inc(GScanDetails[FDataIndex].ExtensionSpread[exi.RawCategory, 2], tfo.FileSize);

        inc(FileExtensionsObject.CategoryExtensions[exi.RawCategory].Quantity[FDataIndex]);
        inc(FileExtensionsObject.CategoryExtensions[exi.RawCategory].Size[FDataIndex], tfo.FileSize);

        tfo.FileCategory := i;
      end;

      // =====================================================================
      // =====================================================================

      inc(FFileCount);
      inc(FFileTotalSpace, tfo.FileSize);
      inc(FFileOnDisk, tfo.FileSizeOnDisk);

      if (Sysutils.faHidden and tfo.Attributes) = Sysutils.faHidden then begin       //file is hidden
        inc(GScanDetails[DataIndex].FileAttributes[FileType_Hidden, 0]);
        inc(GScanDetails[DataIndex].FileAttributes[FileType_Hidden, 1], tfo.FileSize);
      end;
      if (faSysFile and tfo.Attributes) = faSysFile then begin     //file is system
        inc(GScanDetails[DataIndex].FileAttributes[FileType_System, 0]);
        inc(GScanDetails[DataIndex].FileAttributes[FileType_System, 1], tfo.FileSize);
      end;
      if (faArchive and tfo.Attributes) = faArchive then begin     //file is archive
        inc(GScanDetails[DataIndex].FileAttributes[FileType_Archive, 0]);
        inc(GScanDetails[DataIndex].FileAttributes[FileType_Archive, 1], tfo.FileSize);
      end;
      if (Sysutils.faReadOnly and tfo.Attributes) = Sysutils.faReadOnly then begin   //file is read only
        inc(GScanDetails[DataIndex].FileAttributes[FileType_ReadOnly, 0]);
        inc(GScanDetails[DataIndex].FileAttributes[FileType_ReadOnly, 1], tfo.FileSize);
      end;

      if tfo.FileDateC =GScanDetails[DATAINDEX].TodayAsInteger then begin                 // file is created today
        inc(GScanDetails[DataIndex].FileAttributes[FileType_CreatedToday, 0]);
        inc(GScanDetails[DataIndex].FileAttributes[FileType_CreatedToday, 1], tfo.FileSize);
      end;

      if tfo.FileDateA =GScanDetails[DATAINDEX].TodayAsInteger then begin                 // file is accessed today
        inc(GScanDetails[DataIndex].FileAttributes[FileType_AccessedToday, 0]);
        inc(GScanDetails[DataIndex].FileAttributes[FileType_AccessedToday, 1], tfo.FileSize);
      end;

      if tfo.FileDateM =GScanDetails[DATAINDEX].TodayAsInteger then begin                 // file is modified today
        inc(GScanDetails[DataIndex].FileAttributes[FileType_ModifiedToday, 0]);
        inc(GScanDetails[DataIndex].FileAttributes[FileType_ModifiedToday, 1], tfo.FileSize);
      end;

      //-- now lets put the size into the magnitude section ----------------
      if (tfo.FileSize >= 0) and (tfo.FileSize <= 1024) then begin
        inc(GScanDetails[DataIndex].Magnitude[0, 0]);
        inc(GScanDetails[DataIndex].Magnitude[0, 1], tfo.FileSize);

        if tfo.FileSize = 0 then begin                               // file is null length
          inc(GScanDetails[DataIndex].FileAttributes[FileType_Null, 0]);
        end;
      end
      else if (tfo.FileSize > 1024) and (tfo.FileSize <= (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[1, 0]);
        inc(GScanDetails[DataIndex].Magnitude[1, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > (1024 * 1024)) and (tfo.FileSize <= 10 * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[2, 0]);
        inc(GScanDetails[DataIndex].Magnitude[2, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > 10 * (1024 * 1024)) and (tfo.FileSize <= 50 * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[3, 0]);
        inc(GScanDetails[DataIndex].Magnitude[3, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > 50 * (1024 * 1024)) and (tfo.FileSize <= 100 * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[4, 0]);
        inc(GScanDetails[DataIndex].Magnitude[4, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > 100 * (1024 * 1024)) and (tfo.FileSize <= 150 * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[5, 0]);
        inc(GScanDetails[DataIndex].Magnitude[5, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > 150 * (1024 * 1024)) and (tfo.FileSize <= 200 * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[6, 0]);
        inc(GScanDetails[DataIndex].Magnitude[6, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > 200 * (1024 * 1024)) and (tfo.FileSize <= 250 * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[7, 0]);
        inc(GScanDetails[DataIndex].Magnitude[7, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > 250 * (1024 * 1024)) and (tfo.FileSize <= 500 * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[8, 0]);
        inc(GScanDetails[DataIndex].Magnitude[8, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > 500 * (1024 * 1024)) and (tfo.FileSize <= 1000 * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[9, 0]);
        inc(GScanDetails[DataIndex].Magnitude[9, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > 1000 * (1024 * 1024)) and (tfo.FileSize <= 2000 * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[10, 0]);
        inc(GScanDetails[DataIndex].Magnitude[10, 1], tfo.FileSize);
      end
      else if (tfo.FileSize > 2000 * (1024 * 1024)) and (tfo.FileSize <= Int64(5000) * (1024 * 1024)) then begin
        inc(GScanDetails[DataIndex].Magnitude[11, 0]);
        inc(GScanDetails[DataIndex].Magnitude[11, 1], tfo.FileSize);
      end
      else begin
        inc(GScanDetails[DataIndex].Magnitude[12, 0]);
        inc(GScanDetails[DataIndex].Magnitude[12, 1], tfo.FileSize);
      end;

      // =======================================================================
      // process usernames -----------------------------------------------------
      // =======================================================================

      if (XSettings.GetUserDetails) then begin
        if (tfo.FileCategory <> FileCategoryDirectory) then begin
          inc(GScanDetails[DataIndex].Users[tfo.owner].CategoryDataQty[tfo.FileCategory]);
          inc(GScanDetails[DataIndex].Users[tfo.owner].CategoryDataSize[tfo.FileCategory], tfo.FileSize);
        end;

        inc(GScanDetails[DataIndex].Users[tfo.owner].Data[XUserCount]);
        inc(GScanDetails[DataIndex].Users[tfo.owner].Data[XUserSize], tfo.FileSize);
      end;

      // =======================================================================
      // process folder path ---------------------------------------------------
      // =======================================================================

      if tfo.FilePathIndex > GScanDetails[DataIndex].Folders.Count - 1 then begin
//        inc(iserrorcount);

        tfo.FilePathIndex := 0;
      end
      else if GScanDetails[DATAINDEX].ScanPath = GScanDetails[DataIndex].Folders[tfo.FilePathIndex] then begin
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

        tfr.FileCategory   := GetExtensionCategoryID(s).RawCategory;

        GScanDetails[DataIndex].RootFiles.Add(tfr);
      end;

      // =======================================================================
      // process temporary file types ------------------------------------------
      // =======================================================================
      z := 0;

      s := UpperCase(GScanDetails[DataIndex].Folders[tfo.FilePathIndex] + tfo.FileName);

      found := False;

      while (not(found)) and (z < Extensions.Count) do begin
        tfx := Extensions[z];

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
        sgTTemp.Cells[0, sgTTemp.RowCount - 1] := GScanDetails[DataIndex].Folders[tfo.FilePathIndex] + tfo.FileName;
        sgTTemp.Cells[1, sgTTemp.RowCount - 1] := ConvertToUsefulUnit(tfo.FileSize);
        sgTTemp.Cells[2, sgTTemp.RowCount - 1] := IntToStr(tfo.FileSize);

        sgTTemp.RowCount := sgTTemp.RowCount + 1;

        inc(extspread[DATAINDEX, Category_Temp, 1]);
        inc(extspread[DATAINDEX, Category_Temp, 2], tfo.FileSize);

        tfo.Temp := True;
      end
      else
        tfo.Temp := False;
    end
    else begin // == ITEM IS A FOLDER ========================================
      tfo.FileCategory := FileCategoryDirectory;

      inc(FFolderCount);

      if GScanDetails[DATAINDEX].ScanPath = GScanDetails[DataIndex].Folders[tfo.FilePathIndex] then begin
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

        tfr.FileCategory := FileCategoryDirectory;

        GScanDetails[DataIndex].RootFiles.Add(tfr);

        if (faDirectory and tfo.Attributes) = faDirectory then begin
          idx := -1;
          s   := GScanDetails[DataIndex].Folders[tfo.FilePathIndex] + tfo.FileName;

          for i := 1 to length(s) do
            if s[i] = '\' then
              idx := i;

          if idx <> -1 then begin
            rfd := TRootFoldersData.Create;

            rfd.Name       := (Copy(GScanDetails[DataIndex].Folders[tfo.FilePathIndex] + tfo.FileName,
                                    idx + 1,
                                    length(GScanDetails[DataIndex].Folders[tfo.FilePathIndex] + tfo.FileName) - idx + 1));
            rfd.Attributes := tfo.Attributes;

            GScanDetails[DataIndex].RootFolders.Add(rfd);
          end;
        end;
     end;

    end
//    XSettings.ProgressForm.SetPercentage('100%');
//    XSettings.ProgressForm.SetStatus3(IntToStr(GScanDetails[DataIndex].Files.Count));
  except
   // MessageDlg(XText[rsDialog13, mtWarning, [mbOK], 0);
  end;

  FCriticalSection.Leave;
end;

end.
