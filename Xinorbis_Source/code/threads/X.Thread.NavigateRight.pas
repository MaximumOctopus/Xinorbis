{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Thread.NavigateRight;

interface

uses
  Classes, AdvGrid, SyncObjs,

  X.ScanAnalysis, X.CSizeOfFolder, X.SystemGlobal;


type
  TNavigateRightThread = class(TThread)
  private
    FFileSize    : Int64;
    FFileCount   : integer;
    FFolderCount : integer;
  public
    procedure SetData(aSource, aFromfolderID : integer; p : int64; g : TAdvStringGrid; aFilterChanged : boolean);

    destructor Destroy; override;

    property FileSize    : Int64   read FFileSize;
    property FileCount   : integer read FFileCount;
    property FolderCount : integer read FFolderCount;
  protected
    FSource      : integer;

    fromfolderID : integer;
    foldersize   : int64;
    Grid         : TAdvStringGrid;
    FFilterChanged : boolean;

    procedure Execute; override;
  end;

implementation

 uses {main,} Contnrs, sysutils,

      X.Constants, X.Utility, X.GridUtility, X.Global, X.Settings, X.CFileObject,
      X.CUserData, X.Conversions, X.GlobalObjects;


destructor TNavigateRightThread.Destroy;
begin
  inherited;
end;


procedure TNavigateRightThread.SetData(aSource, aFromfolderID : integer; p : int64; g : TAdvStringGrid; aFilterChanged : boolean);
 begin
  FSource        := aSource;
  fromfolderID   := aFromfolderID;
  foldersize     := p;
  Grid           := g;
  FFilterChanged := aFilterChanged;
end;


procedure TNavigateRightThread.Execute;
var
  i, orderx, rowidx : integer;
  s : string;
  tsof : TSizeOfFolder;

begin
  s            := '';
  i            := 0;
  orderx       := 0;
  FFileSize    := 0;
  FFileCount   := 0;
  FFolderCount := 0;

  if GScanDetails[FSource].Files.Count > 0 then begin
    TGridUtility.ClearStringGird(Grid, False);

    GSystemGlobal.FolderStructure.Add(GScanDetails[FSource].Folders[fromfolderID] + '?' + IntToStr(foldersize));

    GSystemGlobal.CurrentNavigationSideLocation := GScanDetails[FSource].Folders[fromfolderID];

    while i < GScanDetails[FSource].Files.Count do begin
      if GScanDetails[FSource].Files.Items[i].FilePathIndex = fromfolderID then begin

        rowidx := Grid.RowCount - 1;

        if ((faDirectory and GScanDetails[FSource].Files.Items[i].Attributes) = faDirectory) or
           (XSettings.Navigation.DisplayOptions[1][GScanDetails[FSource].Files.Items[i].FileCategory] = '1') then begin

          if ((faDirectory and GScanDetails[FSource].Files.Items[i].Attributes) <> faDirectory) then begin  // file
            Grid.Cells[sgnFileName, rowidx]       := GScanDetails[FSource].Files.Items[i].FileName;

            Grid.Cells[sgnStringSize, rowidx]     := TConvert.ConvertToUsefulUnit(GScanDetails[FSource].Files.Items[i].FileSize);
            Grid.Cells[sgnIntegerSize, rowidx]    := IntToStr(GScanDetails[FSource].Files.Items[i].FileSize);

            inc(FFileSize, GScanDetails[FSource].Files.Items[i].FileSize);

            if foldersize <> 0 then begin
              Grid.Cells[sgnStringPCent, rowidx]  := TConvert.RealToPercent(GScanDetails[FSource].Files.Items[i].FileSize / foldersize);
              Grid.Cells[sgnIntegerPCent, rowidx] := IntToStr(Round((GScanDetails[FSource].Files.Items[i].FileSize / foldersize) * 50));
            end
            else begin
              Grid.Cells[sgnStringPCent, rowidx]   := '100%';
              Grid.Cells[sgnIntegerPCent, rowidx] := '100';
            end;

            Grid.Cells[sgnFolderFile, rowidx]     := '0';

            Grid.Cells[sgnCreatedDate, rowidx]    := TConvert.IntDateToString(GScanDetails[FSource].Files.Items[i].FileDateC);
            Grid.Cells[sgnAccessedDate, rowidx]   := TConvert.IntDateToString(GScanDetails[FSource].Files.Items[i].FileDateA);
            Grid.Cells[sgnModifiedDate, rowidx]   := TConvert.IntDateToString(GScanDetails[FSource].Files.Items[i].FileDateM);
            Grid.Cells[sgnUserName, rowidx]       := GScanDetails[FSource].Users[GScanDetails[FSource].Files.Items[i].Owner].Name;

            s := '----';
            if ((Sysutils.faArchive and  GScanDetails[FSource].Files.Items[i].Attributes) = Sysutils.faArchive) then  s[1] := 'A';
            if ((Sysutils.faReadOnly and GScanDetails[FSource].Files.Items[i].Attributes) = Sysutils.faReadOnly) then s[2] := 'R';
            if ((Sysutils.faSysFile and  GScanDetails[FSource].Files.Items[i].Attributes) = Sysutils.faSysFile) then  s[3] := 'S';
            if ((Sysutils.faHidden and   GScanDetails[FSource].Files.Items[i].Attributes) = Sysutils.faHidden) then   s[4] := 'H';

            Grid.Cells[sgnAttributes, rowidx]     := s;

            Grid.Cells[sgnSizeOnDisk, rowidx]     := TConvert.ConvertToUsefulUnit(GScanDetails[FSource].Files.Items[i].FileSizeOnDisk);
            Grid.Cells[sgnIntegetSoD, rowidx]     := IntToStr(GScanDetails[FSource].Files.Items[i].FileSizeOnDisk);

            Grid.Cells[sgnOrderIndex, rowidx]     := IntToStr(orderx + 50000);

            Grid.Cells[sgnCategoryIndex, rowidx]  := IntToStr(GScanDetails[FSource].Files.Items[i].FileCategory);

            inc(FFileCount);
          end
          else begin   // folder
            // cache the results in the FileSize and FileSizeOnDisk parameters of the file object as these aren't used for folders
            // ===================================================================================================================
            if ((GScanDetails[FSource].Files.Items[i].FileSize = 0) or (FFilterChanged)) then begin

              tsof := GXinorbisScan.SizeOfFolderNav(1, GScanDetails[FSource].Folders[GScanDetails[FSource].Files.Items[i].FilePathIndex] + GScanDetails[FSource].Files.Items[i].FileName);

              GScanDetails[FSource].Files.Items[i].FileSize       := tsof.Data[XFileSize];
              GScanDetails[FSource].Files.Items[i].FileSizeOnDisk := tsof.Data[XFileUsed];
            end
            else begin
              tsof.Data[XFileSize] := GScanDetails[FSource].Files.Items[i].FileSize;
              tsof.Data[XFileUsed] := GScanDetails[FSource].Files.Items[i].FileSizeOnDisk;
            end;

            Grid.Cells[sgnFileName, rowidx]   := GScanDetails[FSource].Files.Items[i].FileName;

            Grid.Cells[sgnStringSize, rowidx] := TConvert.ConvertToUsefulUnit(tsof.Data[XFileUsed]);

            s := '----';
            if ((Sysutils.faArchive and  GScanDetails[FSource].Files.Items[i].Attributes) = Sysutils.faArchive) then  s[1] := 'A';
            if ((Sysutils.faReadOnly and GScanDetails[FSource].Files.Items[i].Attributes) = Sysutils.faReadOnly) then s[2] := 'R';
            if ((Sysutils.faSysFile and  GScanDetails[FSource].Files.Items[i].Attributes) = Sysutils.faSysFile) then  s[3] := 'S';
            if ((Sysutils.faHidden and   GScanDetails[FSource].Files.Items[i].Attributes) = Sysutils.faHidden) then   s[4] := 'H';

            Grid.Cells[sgnAttributes, rowidx]     := s;

            Grid.Cells[sgnSizeOnDisk, rowidx]     := TConvert.ConvertToUsefulUnit(tsof.Data[XSpaceUsed]);
            Grid.Cells[sgnIntegetSoD, rowidx]     := IntToStr(tsof.Data[XSpaceUsed]);

            Grid.Cells[sgnCreatedDate, rowidx]    := TConvert.IntDateToString(GScanDetails[FSource].Files.Items[i].FileDateC);
            Grid.Cells[sgnAccessedDate, rowidx]   := TConvert.IntDateToString(GScanDetails[FSource].Files.Items[i].FileDateA);
            Grid.Cells[sgnModifiedDate, rowidx]   := TConvert.IntDateToString(GScanDetails[FSource].Files.Items[i].FileDateM);
            Grid.Cells[sgnUserName, rowidx]       := GScanDetails[FSource].Users[GScanDetails[FSource].Files.Items[i].Owner].Name;

            if foldersize <> 0 then begin
              Grid.Cells[sgnStringPCent, rowidx]  := TConvert.RealToPercent(tsof.Data[XFileUsed] / foldersize);
              Grid.Cells[sgnIntegerPCent, rowidx] := IntToStr(Round((tsof.Data[XFileUsed] / foldersize) * 50));
            end
            else begin
              Grid.Cells[sgnStringPCent, rowidx]  := '100%';
              Grid.Cells[sgnIntegerPCent, rowidx] := '100';
            end;

            Grid.Cells[sgnIntegerSize, rowidx]    := IntToStr(tsof.Data[XFileUsed]);

            inc(FFileSize, tsof.Data[XFileUsed]);

            Grid.Cells[sgnFolderFile, rowidx]     := '1';
            Grid.Cells[sgnOrderIndex, rowidx]     := IntToStr(orderx);

            Grid.Cells[sgnCategoryIndex, rowidx]  := '0';

            inc(FFolderCount);
          end;

          Grid.RowCount := Grid.RowCount + 1;

          inc(orderx);
        end;
      end;

      inc(i);
    end;

    // =========================================================================
  end;
end;


end.
