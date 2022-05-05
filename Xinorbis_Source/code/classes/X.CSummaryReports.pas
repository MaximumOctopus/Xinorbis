{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CSummaryReports;

interface

uses
   System.SysUtils,

   AdvGrid, {htmltv,}

   X.Utility, X.Global, X.Settings,

   X.Constants,

   X.GuiLogic, X.Formatting, X.Windows, X.LanguageHandler,
   X.SystemGlobal;


type
  TSummaryReports = class
  private
    FSetStatusBarText   : TSetStatusBarText;

    FGrids              : array[0..2, 1..5] of TAdvStringGrid;
 public
    constructor Create;
    destructor  Destroy; override;

    procedure SaveSummary(aDataIndex : integer; const FileName : string);

    procedure SetGrids(aDataIndex : integer; var aNullFiles   : TAdvStringGrid;
                                             var aNullFolders : TAdvStringGrid;
                                             var aDirList     : TAdvStringGrid;
                                             var aTop50Big    : TAdvStringGrid;
                                             var aUsers       : TAdvStringGrid);

    property  OnSetStatusBarText : TSetStatusBarText read FSetStatusBarText   write FSetStatusBarText;
  end;


var
  GReportSummary : TSummaryReports;



implementation


uses
  X.ChartUtility, X.DisplayUtility,
  X.Conversions, X.Dialogs.Dialog, X.GlobalObjects;


const
  CNullFiles    = 1;
  CNullFolders  = 2;
  CDirList      = 3;
  CTop50Big     = 4;
  CUsers        = 5;


constructor TSummaryReports.Create;
begin
  inherited create;

end;


destructor TSummaryReports.Destroy;
begin

  inherited destroy;
end;


procedure TSummaryReports.SetGrids(aDataIndex : integer; var aNullFiles : TAdvStringGrid;
                                                         var aNullFolders : TAdvStringGrid;
                                                         var aDirList : TAdvStringGrid;
                                                         var aTop50Big : TAdvStringGrid;
                                                         var aUsers : TAdvStringGrid);
begin
  FGrids[aDataIndex, CNullFiles]   := aNullFiles;
  FGrids[aDataIndex, CNullFolders] := aNullFolders;
  FGrids[aDataIndex, CDirList]     := aDirList;
  FGrids[aDataIndex, CTop50Big]    := aTop50Big;
  FGrids[aDataIndex, CUsers]       := aUsers;
end;


// =============================================================================
// =============================================================================


procedure TSummaryReports.SaveSummary(aDataIndex : integer; const FileName : string);
 var
  lDriveDetails : TXDriveDetails;

  tf : TextFile;
  z,t : integer;
  s : string;

  procedure AddSummaryItem(sidx : integer);
   var
    t : integer;

   begin
    case sidx of
      1 : begin
            Writeln(tf, ' =============================================================');
            Writeln(tf, '');

            if XSettings.LastScanMultiple then begin
              Writeln(tf, SummaryReport[0] + '"' + GScanDetails[aDataIndex].MultipleList.Strings[0] + '"');

              for t := 1 to GScanDetails[aDataIndex].MultipleList.Count - 1 do begin
                Writeln(tf, TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + '"' + GScanDetails[aDataIndex].MultipleList.Strings[t] + '"');
              end;
            end
            else
              Writeln(tf, SummaryReport[0] + '"' + GScanDetails[aDataIndex].ScanPath + '"');

            if (GScanDetails[aDataIndex].ScanSource = ScanSourceFileXinNormal) or
               (GScanDetails[aDataIndex].ScanSource = ScanSourceFileXinDetailed) or
               (GScanDetails[aDataIndex].ScanSource = ScanSourceFileCSV) then begin
              Writeln(tf, TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + XText[rsFrom] + ': ' + ExtractFilename(GScanDetails[aDataIndex].Filename));
            end;

            Writeln(tf, TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + TUtility.GetDate(GETTIMEFORMAT_DISPLAY) + ', ' + TUtility.GetTime(GETTIMEFORMAT_DISPLAY));

            if (aDataIndex = dataFolderHistory) then begin
              Writeln(tf, '');
              Writeln(tf, TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + XText[rsFolderHistory] + ': ' + GScanDetails[aDataIndex].ScanDateFHStr);
            end;

            Writeln(tf, '');

            if GSystemGlobal.ExcludedFolders.Count <> 0 then begin
              Writeln(tf, TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + XText[rsExcludedFolders] + ';');

              for t := 0 to GSystemGlobal.ExcludedFolders.Count - 1 do begin
                Writeln(tf, TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + '"' + GSystemGlobal.ExcludedFolders.Strings[t] + '"');
              end;

              Writeln(tf, '');
            end;

            if GSystemGlobal.ExcludedFiles.Count <> 0 then begin
              Writeln(tf, TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + XText[rsExcludedFiles] + ';');

              for t := 0 to GSystemGlobal.ExcludedFiles.Count - 1 do begin
                Writeln(tf, TXFormatting.AddLeading('', Length(SummaryReport[0]) - 1, ' ') + '"' + GSystemGlobal.ExcludedFiles.Strings[t] + '"');
              end;

              Writeln(tf, '');
            end;

            Writeln(tf, ' =============================================================');
          end;
      2 : begin
            Writeln(tf, SummaryReport[1] + IntToStr(GScanDetails[aDataIndex].FileCount));
            Writeln(tf, SummaryReport[2] + IntToStr(GScanDetails[aDataIndex ].FolderCount));
          end;
      3 : begin
            Writeln(tf, SummaryReport[3] + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].TotalSize));

            if drivesectorsize <> 0 then begin
              Writeln(tf, SummaryReport[4] + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].TotalSizeOD));
              Writeln(tf, SummaryReport[5] + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].TotalSizeOD - GScanDetails[aDataIndex].TotalSize));
            end;
          end;
      4 : begin
            Writeln(tf, SummaryReport[6] + IntToStr(FGrids[aDataIndex, CNullFiles].RowCount - 1));
            Writeln(tf, SummaryReport[7] + IntToStr(FGrids[aDataIndex, CNullFolders].RowCount - 1));
          end;
      5 : begin // averages
            if GScanDetails[aDataIndex].FileCount <> 0 then
              Writeln(tf, SummaryReport[8] + TConvert.ConvertToUsefulUnit(Round(GScanDetails[aDataIndex].TotalSize / GScanDetails[aDataIndex].FileCount)))
            else
              Writeln(tf, SummaryReport[8] + '0');

            if GScanDetails[aDataIndex].FolderCount <> 0 then
              Writeln(tf, SummaryReport[9] + FloatToStrF(GScanDetails[aDataIndex].FileCount /GScanDetails[aDataIndex].FolderCount, ffFixed, 7, 2, XinorbisFormatSettings));
          end;
      6 : begin
            z := 1;
            for t := 1 to FGrids[aDataIndex, CDirList].RowCount - 1 do begin
              if StrToInt64(FGrids[aDataIndex, CDirList].Cells[8, t]) > StrToInt64(FGrids[aDataIndex, CDirList].Cells[8, z]) then
                z := t;
            end;

            if FGrids[aDataIndex, CDirList].Cells[1, z] <> '\' then
              Writeln(tf, SummaryReport[10] + '\' + FGrids[aDataIndex, CDirList].Cells[1, z] + '\ (' + TConvert.ConvertToUsefulUnit(StrToInt64(FGrids[aDataIndex, CDirList].Cells[8, z])) + ', ' + FGrids[aDataIndex, CDirList].Cells[3, z] + ' of files)')
            else
              Writeln(tf, SummaryReport[11] + '(' + TConvert.ConvertToUsefulUnit(StrToInt64(FGrids[aDataIndex, CDirList].Cells[8, z])) + ', ' + FGrids[aDataIndex, CDirList].Cells[3, z] + ' of files)');

            Writeln(tf, SummaryReport[12] + FGrids[aDataIndex, CTop50Big].Cells[0, 1] + ' (' + FGrids[aDataIndex, CTop50Big].Cells[1, 1] + ')');
          end;
      7 : begin
            if GScanDetails[aDataIndex].Users.Count <> 0 then begin
              z := 1;

              for t := 1 to FGrids[aDataIndex, CUsers].RowCount - 1 do begin
                if StrToInt64(FGrids[aDataIndex, CUsers].Cells[7, t]) > StrToInt64(FGrids[aDataIndex, CUsers].Cells[7, z]) then
                  z := t;
              end;

              Writeln(tf, SummaryReport[13] + FGrids[aDataIndex, CUsers].Cells[1, z] + ' (' + TConvert.ConvertToUsefulUnit(StrToInt64(FGrids[aDataIndex, CUsers].Cells[7, z])) + ', ' + FGrids[aDataIndex, CUsers].Cells[3, z] + ')');
            end;
          end;
      8 : begin
            Writeln(tf, SummaryReport[14]);

            for t := 1 to __FileCategoriesCount do begin
              if GScanDetails[aDataIndex].ExtensionSpread[t, 1] = 0 then
                Writeln(tf, TXFormatting.AddTrailing(' ' + TypeDescriptions[t], 25, ' ') + ': ' + TXFormatting.AddLeading(' ' +IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]), 7, ' ') + ' :: ' + TXFormatting.AddLeading(' ' + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, 2]), 11, ' '))
              else begin
                if GScanDetails[aDataIndex].TotalSize <> 0 then
                  Writeln(tf, TXFormatting.AddTrailing(' ' + TypeDescriptions[t], 25, ' ') + ': ' + TXFormatting.AddLeading(' ' +IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]), 7, ' ') + ' :: ' + TXFormatting.AddLeading(' ' + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, 2]), 11, ' ') + '  (' + TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDataIndex].TotalSize) + ')')
                else
                  Writeln(tf, TXFormatting.AddTrailing(' ' + TypeDescriptions[t], 25, ' ') + ': ' + TXFormatting.AddLeading(' ' +IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]), 7, ' ') + ' :: ' + TXFormatting.AddLeading(' ' + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, 2]), 11, ' ') + '  (100%)');
              end;
            end;
          end;
      9 : begin
            if GScanDetails[aDataIndex].ScanSource <> ScanSourceFileCSV then begin

              if Pos('\\',GScanDetails[aDataIndex].ScanPath) = 0 then begin
                Writeln(tf, DriveReport[0] + TXWindows.GetDiskTypeString(GScanDetails[aDataIndex].ScanPath + ':'));

                if GSystemGlobal.drivespacemax >= 0 then begin
                  Writeln(tf, DriveReport[1] + TConvert.ConvertToUsefulUnit(GSystemGlobal.drivespacemax));
                  Writeln(tf, DriveReport[2] + TConvert.ConvertToUsefulUnit(GSystemGlobal.drivespacefree));
                end
                else begin
                  Writeln(tf, DriveReport[1] + 'n/a');
                  Writeln(tf, DriveReport[2] + 'n/a');
                end;

                lDriveDetails := TXWindows.GetDriveDetails(GScanDetails[aDataIndex].ScanPath[1]);

                if lDriveDetails.Clusters <> 0 then begin
                  Writeln(tf, '');
                  Writeln(tf, DriveReport[3] + IntToStr(lDriveDetails.SectorsPerCluster));
                  Writeln(tf, DriveReport[4] + IntToStr(lDriveDetails.BytesPerSector));
                  Writeln(tf, DriveReport[5] + IntToStr(lDriveDetails.FreeClusters));
                  Writeln(tf, DriveReport[6] + IntToStr(lDriveDetails.Clusters));
                  Writeln(tf, '');
                  Writeln(tf, DriveReport[7] + lDriveDetails.VolumeName);
                  Writeln(tf, DriveReport[8] + lDriveDetails.SerialNumber + ' ($' + lDriveDetails.SerialNumberHex + ')');
                  Writeln(tf, DriveReport[9] + lDriveDetails.FileSystem);
                end;
              end
              else begin
                Writeln(tf, DriveReport[10]);
              end;
            end;
          end;
    end;

    Writeln(tf, '');
  end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 1), 'SaveSummary :: invalid dataindex :: ' + inttostr(aDataIndex));

  // ===========================================================================
  // -- save summary data ------------------------------------------------------
  // ===========================================================================

  AssignFile(tf, FileName);
  {$I-}
  Rewrite(tf);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsErrorSaving] + ': ' + XText[rsSummary], XText[rsErrorSaving] + ' "' + filename + '".', XDialogTypeWarning);
  end
  else begin
    s := '';

    for t := 1 to length(XSettings.Report.SummaryLayout) do begin
      if XSettings.Report.SummaryLayout[t] = ':' then begin
        AddSummaryItem(StrToInt(s));

        s := '';
      end
      else
        s := s + XSettings.Report.SummaryLayout[t];
    end;

    Writeln(tf, ' =============================================================');

    CloseFile(tf);
  end;

  if Assigned(FSetStatusBarText) then
    FSetStatusBarText(XText[rsSummary] + ': '  + FileName);
  {$I+}
end;

end.
