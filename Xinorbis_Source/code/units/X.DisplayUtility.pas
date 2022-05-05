{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: April 23rd 2009
  Last Modified: January 11th 2020
}


unit X.DisplayUtility;

interface

uses
  Generics.Defaults, Classes, SysUtils, DateUtils, VCLTee.Chart, AdvGrid,
  StdCtrls, htmltv, CheckLst, AdvOfficeButtons, AdvSmoothCapacityBar,

  TMSLogging,

  X.Formatting, X.LanguageHandler, X.FileExtensionsObject, X.SystemGlobal;


type
  TDisplayUtility = class
    class procedure DoTableSort(MrGrid : TAdvStringGrid; DisplayColumn, SortingColumn : integer);

    class procedure InformationTabFileExtensions(aDataIndex : integer; EAll, ECustom, EOther : TAdvOfficeCheckBox; oTable : TAdvStringGrid);
    class procedure InformationTabTableTable(aDataIndex : integer; oTableDisplay : integer; oTable : TAdvStringGrid);
    class procedure InformationTabFolderTable(aDataIndex : integer; oTable : TAdvStringGrid);
    class procedure InformationTabTypesList(aDataIndex : integer; oTable : TAdvStringGrid);
    class procedure InformationTabMagnitudeTable(aDataIndex, aCategory : integer; oTable : TAdvStringGrid);
    class procedure InformationTabUsersTable(aDataIndex : integer; oDisplayMode : integer; oTable : TAdvStringGrid);

    class procedure InformationTabUsersGraph(aDataIndex : integer; oChart : TChart);

    class procedure InformationTabTableGraph(aDataIndex : integer; oChart : TChart; ChartLabelOption : integer);
    class procedure InformationTabFolderChart(aDataIndex, filterindex : integer; oChart : TChart; ChartLabelOption : integer);
    class function  InformationTabTypesTable(aDataIndex : integer; oTableDisplay : integer; oTreeView : THTMLTreeView): integer;
    class function  InformationTabTypesTablePost(oTreeView : THTMLTreeView): integer;
    class procedure InformationTabTypesChart(aDataIndex : integer; oChart : TChart; ChartLabelOption : integer);
    class procedure InformationTabLengthGraph(aDataIndex : integer; oChart : TChart; ChartLabelOption : integer);
    class function  InformationTabHistoryGraph(aDataIndex : integer; oChart : TChart; user : TComboBox;
                                               hgData : TStringList; fromDate, toDate : TDateTime;
                                               hInterval, hDateSelect : integer; hQuantity, hCumulative : boolean;
                                               const hIntervalCaption : string; oCapacityBar : TAdvSmoothCapacityBar): string;
    class procedure InformationTabFileDatesTree(aDataIndex, datarange : integer; user : TComboBox; buildtree : boolean; oTree : THTMLTreeView; oChart : TChart; aQuantity : boolean; oCapacityBar : TAdvSmoothCapacityBar);
    class procedure InformationTabMagnitudeGraph(aDataIndex, aCategory : integer; oChart : TChart; rangestatus : boolean);
    class procedure InformationTabLengthTable(aDataIndex : integer; oTableDisplay : integer; oTable : TAdvStringGrid);
    class procedure InformationTabNullFiles(aDataIndex : integer; oTable : TAdvStringGrid);

    class function  BuildTempChart(aDataIndex : integer; oTable : TAdvStringGrid; oChart : TChart; oTempSize : boolean): string;
    class procedure BuildFolderHistoryGraph(oPath : string; oChart : TChart; oFolderHistory : TCheckListBox; oFHCount, oFHSize, oFHMagCount, oFHMagSize : boolean);

    class function BuildTop101FileSize(aDataIndex : integer; oTableBig, oTableSmall : TAdvStringGrid; oTopUsers : TComboBox; oCapacityBar : TAdvSmoothCapacityBar): string;
    class function BuildTop101Date(aDataIndex : integer; oTopBig, oTopSmall : TAdvStringGrid; aUser, aDate : TComboBox): string;

    class function GetSourceAsString(aScanSource : integer) : string;
  end;


implementation


uses ComCtrls, VCLTee.Series, VCLTee.TeeProcs, VCLTee.TeEngine, dialogs,
     X.Global, X.Utility, X.GridUtility, GDIPFill,

     X.Conversions, X.Settings, X.CFileObject, X.FileExtension, X.Constants, X.CUserData,
     X.CRootFoldersData, X.GlobalObjects,

     X.CFolderHistoryObject, X.Dialogs.Dialog;

var
  ExtSpreadHistory : array[0..__FileCategoriesCount, 1..2] of Int64;
  ExtSpreadDates   : array[0..__FileCategoriesCount, 1..2] of Int64;


const
  fQuantity = 1;
  fSize     = 2;

  FilterValuesCount = 7;
  FilterValues : array[0..FilterValuesCount] of integer = (0, 1, 2, 3, 4, 5, 10, 15);

  DirListSortColumns    : array[0..8] of integer = (7, 7, 2, 2, 4, 8, 8, 7, 8);
  MainReportSortColumns : array[0..8] of integer = (7, 7, 2, 2, 4, 8, 8, 7, 8);
  MagnitudeSortColumns  : array[0..8] of integer = (7, 7, 2, 2, 4, 8, 8, 7, 8);
  TempSortColumns       : array[0..2] of integer = (0, 2, 2);
  UsersSortColumns      : array[0..7] of integer = (0, 1, 2, 2, 4, 7, 7, 7);

  CDisplayModeShowAll = 0;

  CSelectionQuantity = 1;
  CSelectionSize     = 2;

  CCreatedDate  = 0;
  CAccessedDate = 1;
  CModifiedDate = 2;

  CUsersTableName       = 1;
  CUsersTableCount      = 2;
  CUsersTableCountAs    = 3;
  CUsersTableSeparator  = 4;
  CUsersTableSize       = 5;
  CUsersTableSizeAs     = 6;
  CUsersTableSortSize   = 7;
  CUsersTableGraphCount = 8;
  CUsersTableGraphSize  = 9;

  CTopBigFullPath       = 0;
  CTopBigFileDate       = 1;
  CTopBigFileSizeUU     = 2;
  CTopBigName           = 3;
  CTopBigFileName       = 4;
  CTopBigFileSizeAB     = 5;

  CLabelOptionDefault        = 0;
  CLabelOptionMostConvenient = 1;
  CLabelOptionKilobyte       = 2;
  CLabelOptionMegabyte       = 3;
  CLabelOptionGigabyte       = 4;

  CIntervalDay               = 0;
  CIntervalWeek              = 1;
  CIntervalMonth             = 2;
  CIntervalYear              = 3;
  CIntervalHour              = 4;


class procedure TDisplayUtility.DoTableSort(MrGrid : TAdvStringGrid; DisplayColumn, SortingColumn : integer);
 begin
  MrGrid.SortSettings.Column := SortingColumn;

  MrGrid.QSort;

  MrGrid.SortSettings.Column := DisplayColumn;
end;


//================================================================================================================================================
//================================================================================================================================================
//== New Information Tab Display Code ============================================================================================================
//================================================================================================================================================
//================================================================================================================================================


class procedure TDisplayUtility.InformationTabFileExtensions(aDataIndex : integer; EAll, ECustom, EOther : TAdvOfficeCheckBox; oTable : TAdvStringGrid);
 var
  t,i : integer;
  tfx : TFileExtension;

  function GetSuggestion(const fileext : string): string;
   var
    x : string;
    t : smallint;

   begin
    x := '';

    if fileext <> '' then begin
      t := 0;

      while (t < FileExtensionsObject.FileExtensionDescriptions.Count) do begin
        if Pos(fileext, UpperCase(FileExtensionsObject.FileExtensionDescriptions.Strings[t])) = 1 then begin
          x := FileExtensionsObject.FileExtensionDescriptions.Strings[t];

          t := FileExtensionsObject.FileExtensionDescriptions.Count;
        end;

        inc(t);
      end;
    end;

    if x = '' then
      Result := XText[rsUnknownFileType]
    else
      Result := x;
  end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabFileExtensions :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabFileExtensions : ' + IntToStr(aDataIndex) + '/' + IntToStr(FileExtensionsObject.CategoryExtensions.Count) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

  oTable.ClearRows(1, oTable.RowCount - 1);
  oTable.RowCount := 2;

  i := 1;

  oTable.BeginUpdate;

  if FileExtensionsObject.CategoryExtensions.Count > 0 then begin
    for t := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
      tfx := FileExtensionsObject.CategoryExtensions[t];

      if (tfx.Quantity[aDataIndex]) > 0 then begin
        if ((EAll.Checked) and (tfx.Category <> Category_Other)) or
           ((EOther.Checked) and (tfx.Category = Category_Other)) then begin

          oTable.Cells[0, i]   := tfx.Name;
          oTable.Cells[1, i]   := IntToStr(tfx.Quantity[aDataIndex]);

          if GScanDetails[aDataIndex].FileCount <> 0 then begin
            oTable.Cells[2, i]   := TConvert.RealToPercent(tfx.Quantity[aDataIndex] /GScanDetails[aDataIndex].FileCount);
            oTable.Cells[11, i]  := IntToStr(Round((tfx.Quantity[aDataIndex] /GScanDetails[aDataIndex].FileCount) * 50));
          end
          else begin
            oTable.Cells[2, i]   := '100%';
            oTable.Cells[11, i]  := '100';
          end;

          oTable.Cells[4, i]   := TConvert.ConvertToUsefulUnit(tfx.Size[aDataIndex]);

          if GScanDetails[aDataIndex].TotalSize <> 0 then begin
            oTable.Cells[5, i]   := TConvert.RealToPercent(tfx.Size[aDataIndex] /GScanDetails[aDataIndex].TotalSize);
            oTable.Cells[12, i]  := IntToStr(Round((tfx.Size[aDataIndex] /GScanDetails[aDataIndex].TotalSize) * 50))
          end
          else begin
            oTable.Cells[12, i]  := '100%';
            oTable.Cells[12, i]  := '100';
          end;

          oTable.Cells[7, i]   := GetSuggestion(UpperCase(tfx.Name) + ' ');

          oTable.Cells[8, i]   := IntToStr(tfx.Quantity[aDataIndex]);
          oTable.Cells[9, i]   := IntToStr(tfx.Size[aDataIndex]);
          oTable.Cells[10, i]  := IntToStr(tfx.Category);

          oTable.RowCount := oTable.RowCount + 1;

          inc(i);
        end;
      end;
    end;

    oTable.RowCount := oTable.RowCount - 1;
  end;

  oTable.EndUpdate;

  // ===========================================================================
//  DoTableSort(oTable, 0, 0);
  //  oTable.SortByColumn(0);
end;


class procedure TDisplayUtility.InformationTabTableGraph(aDataIndex : integer; oChart : TChart; ChartLabelOption : integer);
 var
  t  : integer;
  s  : string;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabTableGraph :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabTableGraph : ' + IntToStr(aDataIndex) + '/' + IntToStr(ChartLabelOption) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount));

  if GScanDetails[aDataIndex].FileCount > 0 then begin
    // == don't show size details if the chart is in quantity mode =============
    if oChart.Tag = fQuantity then
      ChartLabelOption := 0;
    // =========================================================================

    oChart.SeriesList.Items[0].Clear;
    oChart.Legend.TextStyle := ltsPlain;
    if XSettings.LastScanMultiple then
      oChart.Title.Text.Strings[0] := XText[rsMultipleFolders]
    else
      oChart.Title.Text.Strings[0] := GScanDetails[aDataIndex].ScanPath;

    for t := 1 to __FileCategoriesCount do begin
      if GScanDetails[aDataIndex].ExtensionSpread[t, oChart.Tag] <> 0 then begin
        case ChartLabelOption of
          CLabelOptionDefault        : s := TypeDescriptions[t];
          CLabelOptionMostConvenient : s := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, fSize]);
          CLabelOptionKilobyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].ExtensionSpread[t, fSize], unitKB);
          CLabelOptionMegabyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].ExtensionSpread[t, fSize], unitMB);
          CLabelOptionGigabyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].ExtensionSpread[t, fSize], unitGB);
        end;

        oChart.SeriesList.Items[0].Add(GScanDetails[aDataIndex].ExtensionSpread[t, oChart.Tag], s, GSystemGlobal.FileCategoryColors[t]);
      end;
    end;
  end;
end;


class procedure TDisplayUtility.InformationTabTableTable(aDataIndex : integer; oTableDisplay : integer; oTable : TAdvStringGrid);
 var
  t      : integer;
  addrow : boolean;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabTableTable :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabTableTable : ' + IntToStr(aDataIndex) + '/' + IntToStr(oTableDisplay) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

  if XSettings.Forms.ProgressForm <> Nil then
    XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsTableDisplay]);

  oTable.BeginUpdate;

  oTable.RowCount := 2;

  t := 1;

  while t <= __FileCategoriesCount do begin
    case Ord(XSettings.TabDisplayOptions[oTableDisplay][1]) of
      CCharacter_1 : addrow := True;
      CCharacter_2 : if GScanDetails[aDataIndex].ExtensionSpread[t, 1] <> 0 then
                       addrow := True
                     else
                       addrow := False;
      CCharacter_3 : if XSettings.TabDisplayOptions[oTableDisplay][t + 1] = '1' then
                       addrow := True
                     else
                       addrow := False;
    else
      addrow := False;
    end;

    if addrow then begin
      oTable.Cells[1, oTable.RowCount - 1] := TypeDescriptions[t];
      oTable.Cells[2, oTable.RowCount - 1] := IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]);

      if GScanDetails[aDataIndex].FileCount <> 0 then begin
        oTable.Cells[3, oTable.RowCount - 1] := TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 1] /GScanDetails[aDataIndex].FileCount);
        oTable.Cells[9, oTable.RowCount - 1] := IntToStr(Round((GScanDetails[aDataIndex].ExtensionSpread[t, 1] /GScanDetails[aDataIndex].FileCount) * 50));
      end
      else begin
        oTable.Cells[3, oTable.RowCount - 1] := '100%';
        oTable.Cells[9, oTable.RowCount - 1] := '100';
      end;

      oTable.Cells[5, oTable.RowCount - 1] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, 2]);

      if GScanDetails[aDataIndex].TotalSize <> 0 then begin
        oTable.Cells[6, oTable.RowCount - 1]  := TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDataIndex].TotalSize);
        oTable.Cells[10, oTable.RowCount - 1] := IntToStr(Round((GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDataIndex].TotalSize) * 50))
      end
      else begin
        oTable.Cells[6, oTable.RowCount - 1]  := '100%';
        oTable.Cells[10, oTable.RowCount - 1] := '100';
      end;

      oTable.Cells[7, oTable.RowCount - 1]  := IntToStr(t);
      oTable.Cells[8, oTable.RowCount - 1]  := IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 2]);

      oTable.RowCount := oTable.RowCount + 1;
    end;

    inc(t);
  end;

  oTable.RowCount := oTable.RowCount - 1;

  oTable.EndUpdate;

  DoTableSort(oTable, oTable.SortSettings.Column, MainReportSortColumns[oTable.SortSettings.Column]);
end;


class procedure TDisplayUtility.InformationTabFolderTable(aDataIndex : integer; oTable : TAdvStringGrid);
 var
  t : integer;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabFolderTable :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabFolderTable : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(GScanDetails[aDataIndex].RootFolders.Count));

  if XSettings.Forms.ProgressForm <> Nil then begin
    XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsFolderList]);
    XSettings.System.JustInTimeProcessed[aDataIndex, TabIndexFolder] := True;
  end;

  oTable.BeginUpdate;

  oTable.RowCount := GScanDetails[aDataIndex].RootFolders.Count + 1;

  for t := 0 to GScanDetails[aDataIndex].RootFolders.Count - 1 do begin
    oTable.Cells[1, t + 1] := GScanDetails[aDataIndex].RootFolders[t].Name;
    oTable.Cells[2, t + 1] := IntToStr(GScanDetails[aDataIndex].RootFolders[t].Data[XRootCount]);

    if GScanDetails[aDataIndex].FileCount <> 0 then begin
      oTable.Cells[3, t + 1]  := TConvert.RealToPercent(GScanDetails[aDataIndex].RootFolders[t].Data[XRootCount] /GScanDetails[aDataIndex].FileCount);
      oTable.Cells[9, t + 1] := IntToStr(Round(GScanDetails[aDataIndex].RootFolders[t].Data[XRootCount] /GScanDetails[aDataIndex].FileCount) * 50);
    end
    else begin
      oTable.Cells[3, t + 1] := '100%';
      oTable.Cells[9, t + 1] := '100';
    end;

    oTable.Cells[5, t + 1] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].RootFolders[t].Data[XRootSize]);

    if GScanDetails[aDataIndex].TotalSize <> 0 then begin
      oTable.Cells[6,  t + 1] := TConvert.RealToPercent(GScanDetails[aDataIndex].RootFolders[t].Data[XRootSize] /GScanDetails[aDataIndex].TotalSize);
      oTable.Cells[10, t + 1] := IntToStr(Round((GScanDetails[aDataIndex].RootFolders[t].Data[XRootSize] /GScanDetails[aDataIndex].TotalSize) * 50));
    end
    else begin
      oTable.Cells[6,  t + 1] := '100%';
      oTable.Cells[10, t + 1] := '100';
    end;

    oTable.Cells[7, t + 1] := IntToStr(t);
    oTable.Cells[8, t + 1] := IntToStr(GScanDetails[aDataIndex].RootFolders[t].Data[XRootSize]);
  end;

  oTable.EndUpdate;

  DoTableSort(oTable, oTable.SortSettings.Column, DirListSortColumns[oTable.SortSettings.Column]);
end;


class procedure TDisplayUtility.InformationTabFolderChart(aDataIndex, filterindex : integer; oChart : TChart; ChartLabelOption : integer);
 var
  t, colindex : integer;
  filtertest : double;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabFolderChart :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabFolderChart : ' + IntToStr(aDataIndex) + '/' + IntToStr(filterindex) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount) + '/' + IntToStr(GScanDetails[aDataIndex].RootFolders.Count));

  if GScanDetails[aDataIndex].FileCount > 0 then begin
    if oChart.Tag = 1 then begin
      oChart.LeftAxis.Title.Caption   := LowerCase(XText[rsFolder]);
      oChart.BottomAxis.Title.Caption := LowerCase(XText[rsBytes]);
    end
    else begin
      oChart.LeftAxis.Title.Caption   := LowerCase(XText[rsFolder]);
      oChart.BottomAxis.Title.Caption := LowerCase(XText[rsQuantity]);
    end;

    //-- build graph -------------------------------------------------------------
    oChart.SeriesList.Items[0].Clear;
    if oChart.SeriesList.Items[0] is THorizBarSeries then
      oChart.SeriesList.Items[0].Marks.Style := smsXValue
    else
      oChart.SeriesList.Items[0].Marks.Style := smsLabelValue;
    oChart.Legend.TextStyle := ltsPlain;

    oChart.Title.Text.Strings[0] := GScanDetails[aDataIndex].ScanPath;

    colindex := 0;

    for t := 0 to GScanDetails[aDataIndex].RootFolders.Count - 1 do begin
      if oChart.Tag = 1 then begin
        if GScanDetails[aDataIndex].TotalSize <> 0 then
          filtertest := (GScanDetails[aDataIndex].RootFolders[t].Data[oChart.Tag] / GScanDetails[aDataIndex].TotalSize) * 100
        else
          filtertest := 100;
      end
      else begin
        filtertest := (GScanDetails[aDataIndex].RootFolders[t].Data[oChart.Tag] / GScanDetails[aDataIndex].FileCount) * 100;
      end;

      if (GScanDetails[aDataIndex].RootFolders[t].Data[oChart.Tag] <> 0) and (filtertest > FilterValues[filterindex]) then begin
        oChart.SeriesList.Items[0].Add(GScanDetails[aDataIndex].RootFolders[t].Data[oChart.Tag], GScanDetails[aDataIndex].RootFolders[t].Name, spectrumcolours[colindex mod spectrummod]);

        inc(colindex);
      end;
    end;
  end;
end;


class procedure TDisplayUtility.InformationTabTypesChart(aDataIndex : integer; oChart : TChart; ChartLabelOption : integer);
 var
  t,ci : integer;
  s    : string;
  tfx  : TFileExtension;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabTypesChart :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabTypesChart : ' + IntToStr(aDataIndex) + '/' + IntToStr(ChartLabelOption) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(FileExtensionsObject.CategoryExtensions.Count) + '/' + IntToStr(GScanDetails[aDataIndex].RootFolders.Count));

  if GScanDetails[aDataIndex].FileCount > 0 then begin
    oChart.SeriesList.Items[0].Clear;
    oChart.Legend.TextStyle      := ltsPlain;
    oChart.Title.Text.Strings[0] := TypeDescriptions[XSettings.System.Treeindex];

    ci := 0;

    for t := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
      tfx := FileExtensionsObject.CategoryExtensions[t];

      if tfx.Category = XSettings.System.Treeindex then begin
        case oChart.Tag of
          CSelectionQuantity : if tfx.Quantity[aDataIndex] <> 0 then begin
                                 case ChartLabelOption of
                                   CLabelOptionDefault        : s := tfx.Name;
                                   CLabelOptionMostConvenient : s := tfx.Name + ' ' + IntToStr(tfx.Quantity[aDataIndex]) + ' (' + TConvert.ConvertToUsefulUnit(tfx.Size[aDataIndex]) + ')';
                                   CLabelOptionKilobyte       : s := tfx.Name + ' ' + IntToStr(tfx.Quantity[aDataIndex]) + ' (' + TConvert.ConvertToStaticUnit(tfx.Size[aDataIndex], unitKB) + ')';
                                   CLabelOptionMegabyte       : s := tfx.Name + ' ' + tfx.Name + ' ' + IntToStr(tfx.Quantity[aDataIndex]) + ' (' + TConvert.ConvertToStaticUnit(tfx.Size[aDataIndex], unitMB) + ')';
                                   CLabelOptionGigabyte       : s := IntToStr(tfx.Quantity[aDataIndex]) + ' (' + TConvert.ConvertToStaticUnit(tfx.Size[aDataIndex], unitGB) + ')';
                                 end;

                                 oChart.SeriesList.Items[0].Add(tfx.Quantity[aDataIndex], s, spectrumcolours[ci mod spectrummod]);
                               end;
          CSelectionSize     : if tfx.Size[aDataIndex] <> 0 then begin
                                 case ChartLabelOption of
                                   CLabelOptionDefault        : s := tfx.Name;
                                   CLabelOptionMostConvenient : s := tfx.Name + ' (' + TConvert.ConvertToUsefulUnit(tfx.Size[aDataIndex]) + ')';
                                   CLabelOptionKilobyte       : s := tfx.Name + ' (' + TConvert.ConvertToStaticUnit(tfx.Size[aDataIndex], unitKB) + ')';
                                   CLabelOptionMegabyte       : s := tfx.Name + ' (' + TConvert.ConvertToStaticUnit(tfx.Size[aDataIndex], unitMB) + ')';
                                   CLabelOptionGigabyte       : s := tfx.Name + ' (' + TConvert.ConvertToStaticUnit(tfx.Size[aDataIndex], unitGB) + ')';
                                 end;

                                 oChart.SeriesList.Items[0].Add(tfx.Size[aDataIndex], s, spectrumcolours[ci mod spectrummod]);
                               end;
        end;

        inc(ci);
      end;
    end;
  end;
end;


class procedure TDisplayUtility.InformationTabLengthGraph(aDataIndex : integer; oChart : TChart; ChartLabelOption : integer);
 var
  t  : integer;
  s, lNameLength : string;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabTableGraph :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabTableGraph : ' + IntToStr(aDataIndex) + '/' + IntToStr(ChartLabelOption) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount));

  if GScanDetails[aDataIndex].FileCount > 0 then begin
    // == don't show size details if the chart is in quantity mode =============
    if oChart.Tag = fQuantity then
      ChartLabelOption := 0;
    // =========================================================================

    oChart.SeriesList.Items[0].Clear;
    oChart.Legend.TextStyle := ltsPlain;
    if XSettings.LastScanMultiple then
      oChart.Title.Text.Strings[0] := XText[rsMultipleFolders]
    else
      oChart.Title.Text.Strings[0] := GScanDetails[aDataIndex].ScanPath;

    for t := 0 to 279 do begin
      if t = 279 then
        lNameLength := '>=280'
      else
        lNameLength := IntToStr(t + 1);

      if oChart.Tag = 1 then begin
        if GScanDetails[aDataIndex].NameLengthCount[t] <> 0 then begin
          case ChartLabelOption of
            CLabelOptionDefault        : s := lNameLength;
            CLabelOptionMostConvenient : s := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].NameLengthCount[t]);
            CLabelOptionKilobyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].NameLengthCount[t], unitKB);
            CLabelOptionMegabyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].NameLengthCount[t], unitMB);
            CLabelOptionGigabyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].NameLengthCount[t], unitGB);
          end;

          oChart.SeriesList.Items[0].Add(GScanDetails[aDataIndex].NameLengthCount[t], s, spectrumcolours[t mod spectrummod]);
        end;
      end
      else begin
        if GScanDetails[aDataIndex].NameLengthSize[t] <> 0 then begin
          case ChartLabelOption of
            CLabelOptionDefault        : s := lNameLength;
            CLabelOptionMostConvenient : s := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].NameLengthSize[t]);
            CLabelOptionKilobyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].NameLengthSize[t], unitKB);
            CLabelOptionMegabyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].NameLengthSize[t], unitMB);
            CLabelOptionGigabyte       : s := TConvert.ConvertToStaticUnit(GScanDetails[aDataIndex].NameLengthSize[t], unitGB);
          end;

          oChart.SeriesList.Items[0].Add(GScanDetails[aDataIndex].NameLengthSize[t], s, spectrumcolours[t mod spectrummod]);
        end;
      end;
    end;
  end;
end;


class procedure TDisplayUtility.InformationTabTypesList(aDataIndex : integer; oTable : TAdvStringGrid);
 var
  t : integer;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabTypesList :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabTypesList : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

  if XSettings.Forms.ProgressForm <> Nil then begin
    XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsFileTypes]);
    XSettings.System.JustInTimeProcessed[aDataIndex, TabIndexTypes] := True;
  end;

  oTable.BeginUpdate;

  for t := 1 to __AttributesToDisplayCount do begin
    oTable.Cells[0, t] := LanguageTypes[t];

    oTable.Cells[1, t] := IntToStr(GScanDetails[aDataIndex].FileAttributes[t, 0]);

    if GScanDetails[aDataIndex].FileCount <> 0 then begin
      oTable.Cells[2, t] := TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 0] / GScanDetails[aDataIndex].FileCount);
      oTable.Cells[6, t] := IntToStr(Round((GScanDetails[aDataIndex].FileAttributes[t, 0] / GScanDetails[aDataIndex].FileCount) * 50));
    end
    else begin
      oTable.Cells[2, t] := '100%';
      oTable.Cells[6, t] := '100';
    end;

    oTable.Cells[4, t] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].FileAttributes[t, 1]);

    if GScanDetails[aDataIndex].TotalSize <> 0 then begin
      oTable.Cells[5, t] := TConvert.RealToPercent(GScanDetails[aDataIndex].FileAttributes[t, 1] / GScanDetails[aDataIndex].TotalSize);
      oTable.Cells[7, t] := IntToStr(Round((GScanDetails[aDataIndex].FileAttributes[t, 1] / GScanDetails[aDataIndex].TotalSize) * 50));
    end
    else begin
      oTable.Cells[5, t] := '100%';
      oTable.Cells[7, t] := '100';
    end;
  end;

  oTable.EndUpdate;

  oTable.Refresh;
end;


class function TDisplayUtility.InformationTabTypesTable(aDataIndex : integer; oTableDisplay : integer; oTreeView : THTMLTreeView): integer;
 var
  tvNode         : TTreeNode;
  t, z           : integer;
  cx             : string;
  tfx            : TFileExtension;
  numstr, ftsstr : string;
  addrow         : boolean;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabTypesTable :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabTypesList : ' + IntToStr(aDataIndex) + '/' + IntToStr(oTableDisplay) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount));

  oTreeView.Tag := aDataIndex;

  if XSettings.Forms.ProgressForm <> Nil then begin
    XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsTree]);
    XSettings.System.JustInTimeProcessed[aDataIndex, TabIndexMain] := True;
  end;

  oTreeView.Items.Clear;
  oTreeView.BeginUpdate;

  t := 1;

  while t <= __FileCategoriesCount do begin
    case Ord(XSettings.TabDisplayOptions[oTableDisplay][1]) of
      CCharacter_1 : addrow := True;
      CCharacter_2 : if GScanDetails[aDataIndex].ExtensionSpread[t, 1] <> 0 then
                       addrow := True
                     else
                       addrow := False;
      CCharacter_3 : if XSettings.TabDisplayOptions[oTableDisplay][t + 1] = '1' then
                       addrow := True
                     else
                       addrow := False;
    else
      addrow := False;
    end;

    if addrow then begin

      if GScanDetails[aDataIndex].FileCount <> 0 then begin
        numstr := TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 1] / GScanDetails[aDataIndex].FileCount);
        numstr := StringReplace(numstr, '<', '&lt;', [rfReplaceAll]);   // or tree component gets confused!
      end
      else
        numstr := '100%';

      if GScanDetails[aDataIndex].TotalSize <> 0 then begin
        ftsstr := TConvert.RealToPercent(GScanDetails[aDataIndex].ExtensionSpread[t, 2] / GScanDetails[aDataIndex].TotalSize);
        ftsstr := StringReplace(ftsstr, '<', '&lt;', [rfReplaceAll]);   // or tree component gets confused!
      end
      else
        ftsstr := '100%';

      cx := '<b>' + TypeDescriptions[t] + '</b> [ ' + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]) + ' ' + XText[rsFiles] + ' (' + numstr + ') / ' + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[t, 2]) + ' (' + ftsstr + ') ]';

      tvNode := oTreeView.Items.Add(nil, cx);

      for z := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
        tfx := FileExtensionsObject.CategoryExtensions[z];

        if tfx.Category = t then begin
          if tfx.Quantity[aDataIndex] <> 0 then
            oTreeView.Items.AddChild(tvNode, '.' + tfx.Name + ': ' + IntToStr(tfx.Quantity[aDataIndex]) + ' (' + TConvert.ConvertToUsefulUnit(tfx.Size[aDataIndex]) + ')');
        end;
      end;
    end;

    inc(t);
  end;

  oTreeView.EndUpdate;

  Result := oTreeView.Items.Count;
end;


class procedure TDisplayUtility.InformationTabLengthTable(aDataIndex : integer; oTableDisplay : integer; oTable : TAdvStringGrid);
 var
  t      : integer;
  addrow : boolean;
  lNameLength : string;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabTableTable :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabTableTable : ' + IntToStr(aDataIndex) + '/' + IntToStr(oTableDisplay) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

  if XSettings.Forms.ProgressForm <> Nil then
    XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsTableDisplay]);

  oTable.BeginUpdate;

  oTable.RowCount := 2;

  t := 0;

  while t <= 279 do begin
    case Ord(XSettings.TabDisplayOptions[oTableDisplay][1]) of
      48 : addrow := True;
      49 : if GScanDetails[aDataIndex].NameLengthCount[t] <> 0 then
             addrow := True
           else
             addrow := False;
    else
      addrow := False;
    end;

    if addrow then begin
      if t = 279 then
        lNameLength := '>=280'
      else
        lNameLength := IntToStr(t + 1);

      oTable.Cells[1, oTable.RowCount - 1] := lNameLength;
      oTable.Cells[2, oTable.RowCount - 1] := IntToStr(GScanDetails[aDataIndex].NameLengthCount[t]);

      if GScanDetails[aDataIndex].FileCount <> 0 then begin
        oTable.Cells[3, oTable.RowCount - 1] := TConvert.RealToPercent(GScanDetails[aDataIndex].NameLengthCount[t] / GScanDetails[aDataIndex].FileCount);
        oTable.Cells[9, oTable.RowCount - 1] := IntToStr(Round((GScanDetails[aDataIndex].NameLengthCount[t] / GScanDetails[aDataIndex].FileCount) * 50));
      end
      else begin
        oTable.Cells[3, oTable.RowCount - 1] := '100%';
        oTable.Cells[9, oTable.RowCount - 1] := '100';
      end;

      oTable.Cells[5, oTable.RowCount - 1] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].NameLengthSize[t]);

      if GScanDetails[aDataIndex].TotalSize <> 0 then begin
        oTable.Cells[6, oTable.RowCount - 1]  := TConvert.RealToPercent(GScanDetails[aDataIndex].NameLengthSize[t] / GScanDetails[aDataIndex].TotalSize);
        oTable.Cells[10, oTable.RowCount - 1] := IntToStr(Round((GScanDetails[aDataIndex].NameLengthSize[t] / GScanDetails[aDataIndex].TotalSize) * 50))
      end
      else begin
        oTable.Cells[6, oTable.RowCount - 1]  := '100%';
        oTable.Cells[10, oTable.RowCount - 1] := '100';
      end;

      oTable.Cells[7, oTable.RowCount - 1]  := IntToStr(t);
      oTable.Cells[8, oTable.RowCount - 1]  := IntToStr(GScanDetails[aDataIndex].NameLengthSize[t]);

      oTable.RowCount := oTable.RowCount + 1;
    end;

    inc(t);
  end;

  oTable.RowCount := oTable.RowCount - 1;

  oTable.EndUpdate;

  DoTableSort(oTable, oTable.SortSettings.Column, MainReportSortColumns[oTable.SortSettings.Column]);
end;


class function TDisplayUtility.InformationTabTypesTablePost(oTreeView : THTMLTreeView): integer;
 var
  i : integer;
  t : integer;
 begin
  Result := 0;

  if oTreeView.Items.Count <> 0 then begin
    i := -1;
    t := 0;

    while (i = -1) and (t <= oTreeView.Items.Count - 1) do begin
      if oTreeView.Items[t].Parent = Nil then begin
        if Pos('0%', oTreeView.Items[t].Text) = 0 then begin
          i := t;
        end;
      end;

      inc(t);
    end;

    if i <> -1 then begin
      oTreeView.Select(oTreeView.Items[i], []);

      Result := 1;
    end;
  end
  else begin
    Result := 2;
  end;
end;


class procedure TDisplayUtility.InformationTabMagnitudeTable(aDataIndex, aCategory : integer; oTable : TAdvStringGrid);
 var
  t : integer;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabMagnitudeTable :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabMagnitudeTable : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(GScanDetails[aDataIndex].TotalSize));

  if aDataIndex = dataLatestScan then begin
    if XSettings.Forms.ProgressForm <> Nil then begin
      XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsMagnitude]);
      XSettings.System.JustInTimeProcessed[aDataIndex, TabIndexMagnitude] := True;
    end;
  end;

  oTable.BeginUpdate;

  oTable.RowCount := __MagnitudesCount + 2;

  for t := 0 to __MagnitudesCount do begin
    oTable.Cells[1, t + 1] := magnilabels[t];
    oTable.Cells[2, t + 1] := IntToStr(GScanDetails[aDataIndex].Magnitude.Data[aCategory, t, 0]);

    if GScanDetails[aDataIndex].FileCount <> 0 then begin
      oTable.Cells[3, t + 1] := TConvert.RealToPercent(GScanDetails[aDataIndex].Magnitude.Data[aCategory, t, 0] / GScanDetails[aDataIndex].FileCount);
      oTable.Cells[9, t + 1] := IntToStr(Round((GScanDetails[aDataIndex].Magnitude.Data[aCategory, t, 0] /GScanDetails[aDataIndex].FileCount) * 50));
    end
    else begin
      oTable.Cells[3, t + 1] := '100%';
      oTable.Cells[9, t + 1] := '100';
    end;

    oTable.Cells[5, t + 1] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].Magnitude.Data[aCategory, t, 1]);

    if GScanDetails[aDataIndex].TotalSize <> 0 then begin
      oTable.Cells[6,  t + 1] := TConvert.RealToPercent(GScanDetails[aDataIndex].Magnitude.Data[aCategory, t, 1] / GScanDetails[aDataIndex].TotalSize);
      oTable.Cells[10, t + 1] := IntToStr(Round((GScanDetails[aDataIndex].Magnitude.Data[aCategory, t, 1] / GScanDetails[aDataIndex].TotalSize) * 50));
    end
    else begin
      oTable.Cells[6,  t + 1] := '100%';
      oTable.Cells[10, t + 1] := '100';
    end;

    oTable.Cells[7, t + 1] := IntToStr(t);
    oTable.Cells[8, t + 1] := IntToStr(GScanDetails[aDataIndex].Magnitude.Data[aCategory, t, 1]);
  end;

  oTable.EndUpdate;

  DoTableSort(oTable, oTable.SortSettings.Column, MagnitudeSortColumns[oTable.SortSettings.Column]);
end;


class procedure TDisplayUtility.InformationTabMagnitudeGraph(aDataIndex, aCategory : integer; oChart : TChart; rangestatus : boolean);
 var
  datarange, t : integer;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2),'InformationTabMagnitudeGraph :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabMagnitudeGraph : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount));

  if GScanDetails[aDataIndex].FileCount > 0 then begin
    if rangestatus then
      datarange := 1
    else
      datarange := 0;

    //-- build graph -------------------------------------------------------------
    oChart.SeriesList.Items[0].Clear;
    oChart.Legend.TextStyle:=ltsPlain;
    oChart.Title.Text.Strings[0] :=GScanDetails[aDataIndex].ScanPath;
    if datarange = 1 then
      oChart.BottomAxis.Title.Caption := XText[rsBytes]
    else
      oChart.BottomAxis.Title.Caption := XText[rsQuantity];

    for t := 0 to __MagnitudesCount do begin
      if GScanDetails[aDataIndex].Magnitude.Data[aCategory, t, datarange] <> 0 then begin
        oChart.SeriesList.Items[0].Add(GScanDetails[aDataIndex].Magnitude.Data[aCategory, t, datarange], magnilabels[t], magnicolors[t]);
      end;
    end;
  end;
end;


class function TDisplayUtility.InformationTabHistoryGraph(aDataIndex : integer; oChart : TChart; user : TComboBox;
                                                           hgData : TStringList; fromDate, toDate : TDateTime;
                                                           hInterval, hDateSelect : integer; hQuantity, hCumulative : boolean;
                                                           const hIntervalCaption : string; oCapacityBar : TAdvSmoothCapacityBar): string;
 var
  t, x, iFromDate, iToDate, iFileDate, currentdate, hcount, userid : integer;
  hsize, HistoryTotalSize : int64;
  HistoryTotalCount : integer;
  xfo : TFileObject;
  xtitle,s,s2 : string;
  haschanged : boolean;
  dtcurrentdate : TDateTime;
  HoursC : array[0..23] of integer;
  HoursS : array[0..23] of int64;
  lCapacityItem : TCapacityItem;
  lNewData : boolean;

  procedure AddBar;
   var
    ss : string;

   begin
    ss := IntToStr(currentdate);

    case hInterval of
      CIntervalDay   : begin
                         xtitle := ss[7] + ss[8] + '/' + ss[5] + ss[6];

                         hgData.Add('(date=' + ss + ')');
                       end;
      CIntervalWeek  : begin
                         xtitle := IntToStr(WeekOf(dtcurrentdate)) + '/' + ss[3] + ss[4];

                         hgData.Add('(week:' + IntToStr(WeekOf(dtcurrentdate)) + ':' + ss[3] + ss[4] + ')');
                       end;
      CIntervalMonth : begin
                         xtitle := ss[5] + ss[6] + '/' + ss[3] + ss[4];

                         hgData.Add('(date>' + ss[1] + ss[2] + ss[3] + ss[4 ] +ss[5] + ss[6] + '01) (date<' + ss[1] + ss[2] + ss[3] + ss[4] + ss[5] + ss[6] + '31)');
                       end;
      CIntervalYear  : begin
                         xtitle :=ss[1] + ss[2] + ss[3] + ss[4];

                         hgData.Add('(date>' + ss[1] + ss[2] + ss[3] + ss[4] + '0101) (date<' + ss[1] + ss[2] + ss[3] + ss[4] + '1231)');
                       end;
    end;

    if hQuantity then
      oChart.SeriesList.Items[0].Add(hcount, xtitle, spectrumcolours[x mod spectrummod])
    else
      oChart.SeriesList.Items[0].Add(hsize, xtitle, spectrumcolours[x mod spectrummod]);

    inc(x);
  end;

  procedure AddHourBar(const xfrom, xto : string; idx, xcount : integer; xsize : int64);
   begin
    xtitle := xfrom;

    case hInterval of
      CIntervalHour : begin
                        hgData.Add('(time>' + xfrom + ') (time<' + xto + ')');
                      end;
    end;

    if hQuantity then
      oChart.SeriesList.Items[0].Add(xcount, xtitle, spectrumcolours[idx mod spectrummod])
    else
      oChart.SeriesList.Items[0].Add(xsize, xtitle, spectrumcolours[idx mod spectrummod]);
  end;

  function IntegerDateToDate(i : integer): TDateTime;
   var
    s : string;

   begin
    s := IntToStr(i);

    try
      Result := EncodeDate(StrToInt(s[1] + s[2] + s[3] + s[4]), StrToInt(s[5] + s[6]), StrToInt(s[7] + s[8]))
    except
      Result := EncodeDate(1990, 01, 01);

      TMSLogger.Error('Invalid data: ' + IntToStr(i));
    end;
  end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabHistoryGraph :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabHistoryGraph : ' + IntToStr(aDataIndex) + '/' + IntToStr(user.ItemIndex) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

  if user.ItemIndex <> 0 then begin
    userid := TUtility.FindUserIndex(aDataIndex, user.Items[user.ItemIndex]);
  end
  else
    userid := -1;

  if (hInterval <= CIntervalYear) then begin
    case hDateSelect of
      CCreatedDate  : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
      CAccessedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
      CModifiedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
    end;
  end;

  for t := 0 to 23 do begin
    HoursC[t] := 0;
    HoursS[t] := 0;
  end;

  for t := 1 to __FileCategoriesCount do begin // clear data
    ExtSpreadHistory[t, 1] := 0;
    ExtSpreadHistory[t, 2] := 0;
  end;

  oChart.SeriesList.Items[0].Clear;

  hgData.Clear;

  currentdate   := 19000001;
  iFileDate     := 19000001;
  dtcurrentdate := IncDay(Now, 1);

  hcount            := 0;
  hsize             := 0;
  HistoryTotalSize  := 0;
  HistoryTotalCount := 0;
  x                 := 0;
  lNewData          := False;

  iFromDate         := TConvert.DateTimeToInteger(fromDate);
  iToDate           := TConvert.DateTimeToInteger(toDate);

  // ===========================================================================
  case hDateSelect of
    CCreatedDate  : oChart.Title.Text.Strings[0] := XText[rsFileCreationHistory]        + ' ' +
                                                    XText[rsFrom]                       + ' ' +
                                                    TConvert.DateToString(fromDate)     + ' ' +
                                                    XText[rsTo]                         + ' ' +
                                                    TConvert.DateToString(toDate);
    CAccessedDate : oChart.Title.Text.Strings[0] := XText[rsFileAccessHistory]          + ' ' +
                                                    XText[rsFrom]                       + ' ' +
                                                    TConvert.DateToString(fromDate)     + ' ' +
                                                    XText[rsTo]                         + ' ' +
                                                    TConvert.DateToString(toDate);
    CModifiedDate : oChart.Title.Text.Strings[0] := XText[rsFileModificationHistory]    + ' ' +
                                                    XText[rsFrom]                       + ' ' +
                                                    TConvert.DateToString(fromDate)     + ' ' +
                                                    XText[rsTo]                         + ' ' +
                                                    TConvert.DateToString(toDate);
  end;

  case hInterval of
    CIntervalDay   : oChart.BottomAxis.Title.Caption := XText[rsDayMonth];
    CIntervalWeek  : oChart.BottomAxis.Title.Caption := XText[rsWeekYear];
    CIntervalMonth : oChart.BottomAxis.Title.Caption := XText[rsMonthYear];
    CIntervalYear  : oChart.BottomAxis.Title.Caption := XText[rsYear];
    CIntervalHour  : oChart.BottomAxis.Title.Caption := hIntervalCaption;
  else
    oChart.BottomAxis.Title.Caption := XText[rsDayMonth];
    //showmessage(inttostr(hinterval));
  end;

  if hQuantity then
    oChart.LeftAxis.Title.Caption := XText[rsQuantity]
  else
    oChart.LeftAxis.Title.Caption := XText[rsSize] + ' (' + XText[rsXBytes] + ')';

  // ===========================================================================

  if (hInterval <= CIntervalYear) then begin
    for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
      xfo := GScanDetails[aDataIndex].Files.Items[t];

      case hDateSelect of
        CCreatedDate  : iFileDate := xfo.FileDateC;
        CAccessedDate : iFileDate := xfo.FileDateA;
        CModifiedDate : iFileDate := xfo.FileDateM;
      end;

      if (iFileDate >= iFromDate) and (iFileDate <= iToDate) then begin
        if ((faDirectory and xfo.Attributes) <> faDirectory) then begin

          case hInterval of
            CIntervalDay   : haschanged := (iFileDate <> currentdate);
            CIntervalWeek  : haschanged := (WeekOf(IntegerDateToDate(iFileDate)) <> WeekOf(dtcurrentdate));
            CIntervalMonth : begin
                               s  := IntToStr(currentdate);
                               s2 := IntToStr(iFileDate);

                               haschanged := (s2[5] + s2[6] <> s[5] + s[6]) or (s2[3] + s2[4] <> s[3] + s[4]);
                             end;
            CIntervalYear  : begin
                               s  := IntToStr(currentdate);
                               s2 := IntToStr(iFileDate);

                               haschanged := (s2[1] + s2[2] + s2[3] + s2[4] <> s[1] + s[2] + s[3] + s[4]);
                             end;
          else
            haschanged := False;
          end;

          // ===================================================================

          if userid <> -1 then begin
            if xfo.Owner <> userid then
              haschanged := False;
          end;

          // ===================================================================

          if haschanged then begin
            if currentdate <> 19000001 then
              AddBar;

            currentdate := iFileDate;

            if hInterval = CIntervalWeek then
              dtcurrentdate := IntegerDateToDate(iFileDate);

            if not(hCumulative) then begin
              hcount := 0;
              hsize  := 0;
            end;

            lNewData := True;
          end;

          inc(hcount);
          inc(hsize, xfo.FileSize);

          inc(HistoryTotalCount);
          inc(HistoryTotalSize, xfo.FileSize);

          inc(ExtSpreadHistory[xfo.FileCategory, 1]);
          inc(ExtSpreadHistory[xfo.FileCategory, 2], xfo.FileSize);

          case hInterval of
            CIntervalDay   :  if (t = GScanDetails[aDataIndex].Files.Count - 1) then begin
                                AddBar;

                                lNewData := False;
                              end;
            CIntervalWeek  :  if (t = GScanDetails[aDataIndex].Files.Count - 1) then begin
                                AddBar;

                                lNewData := False;
                              end;
            CIntervalMonth :  if (t = GScanDetails[aDataIndex].Files.Count - 1) then begin
                                AddBar;

                                lNewData := False;
                              end;
            CIntervalYear  :  if (t = GScanDetails[aDataIndex].Files.Count - 1) then begin
                                AddBar;

                                lNewData := False;
                              end;
          end;
        end;
      end;
    end;

    if (lNewData) and (hCount <> 0) then begin
      case hInterval of
        CIntervalDay..CIntervalYear : AddBar;
      end;
    end;
  end
  else begin

    for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
      xfo := GScanDetails[aDataIndex].Files.Items[t];

      if (hDateSelect = 0) then
        iFileDate := xfo.FileDateC
      else if (hDateSelect = 1) then
        iFileDate := xfo.FileDateA
      else
        iFileDate := xfo.FileDateM;

      if (iFileDate >= iFromDate) and (iFileDate <= iToDate) then begin
        if ((faDirectory and xfo.Attributes) = 0) then begin

          case hInterval of
            CIntervalHour : begin
                              s := IntToStr(iFileDate);

                              if length(s) = 3 then s := '0' + s;
                              if length(s) = 2 then s := '00' + s;

                              x := StrToInt(Copy(s, 1, 2));

                              inc(HoursC[x]);
                              inc(HoursS[x], xfo.FileSize);

                              inc(HistoryTotalCount);
                              inc(HistoryTotalSize, xfo.FileSize);

                              inc(ExtSpreadHistory[xfo.FileCategory, 1]);
                              inc(ExtSpreadHistory[xfo.FileCategory, 2], xfo.FileSize);
                            end;
          end;
        end;
      end;
    end;

    for t := 0 to 23 do begin
      if t < 10 then
        s := '0' + IntToStr(t)
      else
        s := IntToStr(t);

      s  := s + '00';
      s2 := s2 + '59';

      AddHourBar(s, s2, t, HoursC[t], HoursS[t]);
    end;
  end;

  // ===========================================================================

  if oCapacityBar <> Nil then begin
  
    oCapacityBar.Items.Clear;

    for t := 1 to __FileCategoriesCount do begin
      if hQuantity then begin
        if HistoryTotalCount <> 0 then begin        
          if ExtSpreadHistory[t, 1] <> 0 then begin
            lCapacityItem             := oCapacityBar.Items.Add;
            lCapacityItem.Value       := (ExtSpreadHistory[t, 1] / HistoryTotalCount) * 100;
            lCapacityItem.Color       := GSystemGlobal.FileCategoryColors[t];
            lCapacityItem.ColorTo     := GSystemGlobal.FileCategoryColors[t];
            lCapacityItem.DisplayName := TypeDescriptions[t];
            lCapacityItem.Description := TypeDescriptions[t];
            lCapacityItem.Hint        := TypeDescriptions[t] + ' (' + IntToStr(ExtSpreadHistory[t, 1]) + ' files)';
          end;
        end;
      end
      else begin
        if HistoryTotalSize <> 0 then begin
          if ExtSpreadHistory[t, 2] <> 0 then begin
            lCapacityItem             := oCapacityBar.Items.Add;
            lCapacityItem.Value       := (ExtSpreadHistory[t, 2] / HistoryTotalSize) * 100;
            lCapacityItem.Color       := GSystemGlobal.FileCategoryColors[t];
            lCapacityItem.ColorTo     := GSystemGlobal.FileCategoryColors[t];
            lCapacityItem.DisplayName := TypeDescriptions[t];
            lCapacityItem.Description := TypeDescriptions[t];
            lCapacityItem.Hint        := TypeDescriptions[t] + ' (' + TConvert.ConvertToUsefulUnit(ExtSpreadHistory[t, 2]) + ')';
          end;
        end;
      end;
    end;
  end;

  Result := XText[rsFound] + ' <b>' + IntToStr(HistoryTotalCount) + '</b> ' + XText[rsFiles] + '    ' + XText[rsSize] + ' : <b>' + TConvert.ConvertToUsefulUnit(HistoryTotalSize) + '</b>';

  // ===========================================================================

  if hInterval <= CIntervalYear then begin
    case hDateSelect of
      CCreatedDate  : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
      CAccessedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
      CModifiedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
    end;
  end;
end;


class procedure TDisplayUtility.InformationTabUsersGraph(aDataIndex : integer; oChart : TChart);
 var
  t : integer;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabUsersGraph :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabUsersGraph : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

  if GScanDetails[aDataIndex].FileCount > 0 then begin
    oChart.SeriesList.Items[0].Clear;
    oChart.Legend.TextStyle := ltsPlain;

    if oChart.Tag = 1 then
      oChart.Title.Text.Strings[0] := XText[rsQuantityFilesUser]
    else
      oChart.Title.Text.Strings[0] := XText[rsSizeFilesUser];

    for t := 0 to GScanDetails[aDataIndex].Users.Count - 1 do begin
      if oChart.Tag = 1 then
        oChart.SeriesList.Items[0].Add(GScanDetails[aDataIndex].Users[t].Data[XUserCount], GScanDetails[aDataIndex].Users[t].Name, spectrumcolours[t mod spectrummod])
      else begin
        if GScanDetails[aDataIndex].TotalSize <> 0 then
          oChart.SeriesList.Items[0].Add(GScanDetails[aDataIndex].Users[t].Data[XUserSize] /GScanDetails[aDataIndex].TotalSize, GScanDetails[aDataIndex].Users[t].Name, spectrumcolours[t mod spectrummod])
        else
          oChart.SeriesList.Items[0].Add(100, GScanDetails[aDataIndex].Users[t].Name, spectrumcolours[t mod spectrummod]);
      end;
    end;
  end;
end;


class procedure TDisplayUtility.InformationTabUsersTable(aDataIndex : integer; oDisplayMode : integer; oTable : TAdvStringGrid);
 var
  t : integer;
  xCount, xSize : Int64;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabUsersTable :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabUsersTable : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].Users.Count) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count)+ '/' + IntToStr(GScanDetails[aDataIndex].FileCount));

  if XSettings.Forms.ProgressForm <> Nil then
    XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsUserDetails]);

  oTable.ClearRows(1, oTable.RowCount - 1);
  oTable.RowCount := 2;

  oTable.BeginUpdate;

  if GScanDetails[aDataIndex].Users.Count <> 0 then begin
    oTable.RowCount := GScanDetails[aDataIndex].Users.Count + 1;

    for t := 0 to GScanDetails[aDataIndex].Users.Count - 1 do begin
      case oDisplayMode of
        CDisplayModeShowAll : begin
                                xCount := GScanDetails[aDataIndex].Users[t].Data[XUserCount];
                                xSize  := GScanDetails[aDataIndex].Users[t].Data[XUserSize];
                              end;
      else
        xCount := GScanDetails[aDataIndex].Users[t].CategoryDataQty[oDisplayMode];
        xSize  := GScanDetails[aDataIndex].Users[t].CategoryDataSize[oDisplayMode];
      end;

      oTable.Cells[CUsersTableName,  t + 1] := GScanDetails[aDataIndex].Users[t].Name;
      oTable.Cells[CUsersTableCount, t + 1] := IntToStr(xCount);

      if GScanDetails[aDataIndex].FileCount<> 0 then begin
        oTable.Cells[CUsersTableCountAs,    t + 1] := TConvert.RealToPercent(xCount /GScanDetails[aDataIndex].FileCount);
        oTable.Cells[CUsersTableGraphCount, t + 1] := IntToStr(Round((xCount /GScanDetails[aDataIndex].FileCount) * 50));
      end
      else begin
        oTable.Cells[CUsersTableCountAs,    t + 1] := '100%';
        oTable.Cells[CUsersTableGraphCount, t + 1] := '50';
      end;

      oTable.Cells[CUsersTableSize, t + 1] := TConvert.ConvertToUsefulUnit(xSize);

      if GScanDetails[aDataIndex].TotalSize <> 0 then begin
        oTable.Cells[CUsersTableSizeAs,    t + 1] := TConvert.RealToPercent(xSize /GScanDetails[aDataIndex].TotalSize);
        oTable.Cells[CUsersTableGraphSize, t + 1] := IntToStr(Round((xSize /GScanDetails[aDataIndex].TotalSize) * 50));
      end
      else begin
        oTable.Cells[CUsersTableSizeAs,    t + 1] := '100%';
        oTable.Cells[CUsersTableGraphSize, t + 1] := '50';
      end;

      oTable.Cells[CUsersTableSortSize, t + 1] := IntToStr(xSize);
    end;

    DoTableSort(oTable, oTable.SortSettings.Column, UsersSortColumns[oTable.SortSettings.Column]);
  end
  else begin
    oTable.RowCount                  := 2;
    oTable.Cells[CUsersTableName, 1] := XText[rsNoneFound];
  end;

  oTable.EndUpdate;
end;


class procedure TDisplayUtility.InformationTabFileDatesTree(aDataIndex, datarange : integer; user : TComboBox; buildtree : boolean; oTree : THTMLTreeView; oChart : TChart; aQuantity : boolean; oCapacityBar : TAdvSmoothCapacityBar);
var
  yearnode, monthnode, daynode : TTreeNode;
  yy,mm,dd : string;
  oldyear, oldmonth, oldday, strdate : string;
  yearcount, monthcount, daycount, x,t,i,userid : integer;
  yearsize, monthsize, daysize  : int64;
  addFileName : boolean;
  lCapacityItem : TCapacityItem;
  DatesTotalSize : int64;
  DatesTotalCount : integer;

begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabFileDatesTree :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabFileDatesTree : ' + IntToStr(aDataIndex) + '/' + IntToStr(datarange) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count)+ '/' + IntToStr(user.ItemIndex));

  // ===========================================================================

  DatesTotalSize  := 0;
  DatesTotalCount := 0;

  for t := 1 to __FileCategoriesCount do begin // clear data
    ExtSpreadDates[t, 1] := 0;
    ExtSpreadDates[t, 2] := 0;
  end;

  if user.ItemIndex > 0 then begin
    userid := TUtility.FindUserIndex(aDataIndex, user.Items[user.ItemIndex]);
  end
  else
    userid := -1;

  // ===========================================================================

  try
    oTree.Items.Clear;
    oTree.BeginUpdate;

    //graph details
    oChart.SeriesList.Items[0].Clear;

    if (buildtree) and (GScanDetails[aDataIndex].Files.Count <> 0) then begin
      if XSettings.Forms.ProgressForm <> Nil then
        XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsDateTree]);

      addFileName := False;

      if XSettings.Optimisations.AddToDate then begin
        if XSettings.Optimisations.AddToDateLimit then begin
          if GScanDetails[aDataIndex].FileCount <= XSettings.Optimisations.AddToDateLimitCount then
            addFileName := True;
        end
        else
          addFileName := True;
      end;

      case datarange of
        CCreatedDate  : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
        CAccessedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
        CModifiedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
      end;

      oldyear  := '9999';
      oldmonth := '9999';
      oldday   := '9999';

      yearcount  := 0;
      yearsize   := 0;
      monthcount := 0;
      monthsize  := 0;
      daycount   := 0;
      daysize    := 0;

      for x := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin

        if ((faDirectory and GScanDetails[aDataIndex].Files.Items[x].Attributes) = 0) then begin
          case datarange of
            CCreatedDate  : begin
                              strdate := IntToStr(GScanDetails[aDataIndex].Files.Items[x].FileDateC);
                              yy      := Copy(strdate, 1, 4);
                              mm      := Copy(strdate, 5, 2);
                              dd      := Copy(strdate, 7, 2);
                            end;
            CAccessedDate : begin
                              strdate := IntToStr(GScanDetails[aDataIndex].Files.Items[x].FileDateA);
                              yy      := Copy(strdate, 1, 4);
                              mm      := Copy(strdate, 5, 2);
                              dd      := Copy(strdate, 7, 2);
                            end;
            CModifiedDate : begin
                              strdate := IntToStr(GScanDetails[aDataIndex].Files.Items[x].FileDateM);
                              yy      := Copy(strdate, 1, 4);
                              mm      := Copy(strdate, 5, 2);
                              dd      := Copy(strdate, 7, 2);
                            end;
          end;

          // ===================================================================

          case StrToInt(dd) of
            1, 21, 31 : dd := dd + 'st';
            2, 22     : dd := dd + 'nd';
            3, 23     : dd := dd + 'rd';
          else
            dd := dd + 'th';
          end;

          // ===================================================================          

          if yy <> oldyear then begin
            if oldyear <> '9999' then
              yearnode.Text := '<b>' + oldyear + '</b> [' + XText[rsFiles] + ': ' + IntToStr(yearcount) + ' (' + TConvert.ConvertToUsefulUnit(yearsize) + ')]';

            if oldmonth <> '9999' then
              monthnode.Text := '<b>' + shortmonths[StrToInt(oldmonth)] + '</b> [' + XText[rsFiles] + ': ' + IntToStr(monthcount) + ' (' + TConvert.ConvertToUsefulUnit(monthsize) + ')]';

            if oldday <> '9999' then
              daynode.Text := '<b>' + oldday + '</b> [' + XText[rsFiles] + ': ' + IntToStr(daycount) + ' (' + TConvert.ConvertToUsefulUnit(daysize) + ')]';

            oldyear   := yy;
            oldday    := dd;
            oldmonth  := mm;

            yearnode  := oTree.Items.Add(Nil, yy);
            monthnode := oTree.Items.AddChild(yearnode, shortmonths[StrToInt(mm)]);
            daynode   := oTree.Items.AddChild(monthnode, dd);

            yearcount  := 0;  yearsize  := 0;
            monthcount := 0;  monthsize := 0;
            daycount   := 0;  daysize   := 0;
          end;
          if mm <> oldmonth then begin
            if oldmonth <> '9999' then
              monthnode.Text := '<b>' + shortmonths[StrToInt(oldmonth)] + '</b> [' + XText[rsFiles] + ': ' + IntToStr(monthcount) + ' (' + TConvert.ConvertToUsefulUnit(monthsize) + ')]';

            if oldday <> '9999' then
              daynode.Text := '<b>' + oldday + '</b> [' + XText[rsFiles] + ': ' + IntToStr(daycount) + ' (' + TConvert.ConvertToUsefulUnit(daysize) + ')]';

            oldday     := dd;
            oldmonth   := mm;

            monthnode  := oTree.Items.AddChild(yearnode, shortmonths[StrToInt(mm)]);
            daynode    := oTree.Items.AddChild(monthnode, dd);

            monthcount := 0;
            monthsize  := 0;
            daycount   := 0;
            daysize    := 0;
          end;
          if dd <> oldday then begin
            if oldday <> '9999' then
              daynode.Text := '<b>' + oldday + '</b> [' + XText[rsFiles] + ': ' + IntToStr(daycount) + ' (' + TConvert.ConvertToUsefulUnit(daysize) + ')]';

            oldday   := dd;
            if assigned(monthnode) then            
              daynode := oTree.Items.AddChild(monthnode, dd);

            daycount := 0;
            daysize  := 0;
          end;

          // ===================================================================

          if userid <> -1 then begin
            if GScanDetails[aDataIndex].Files.Items[x].Owner <> userid then
              addFileName := False;
          end;

          // ===================================================================

          if addFileName then
            oTree.Items.AddChild(daynode, GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files.Items[x].FilePathIndex] + GScanDetails[aDataIndex].Files.Items[x].FileName);

          inc(yearcount);
          inc(monthcount);
          inc(daycount);
          inc(yearsize,  GScanDetails[aDataIndex].Files.Items[x].FileSize);
          inc(monthsize, GScanDetails[aDataIndex].Files.Items[x].FileSize);
          inc(daysize,   GScanDetails[aDataIndex].Files.Items[x].FileSize);

          inc(DatesTotalCount);
          inc(DatesTotalSize, GScanDetails[aDataIndex].Files.Items[x].FileSize);

          inc(ExtSpreadDates[GScanDetails[aDataIndex].Files.Items[x].FileCategory, 1]);
          inc(ExtSpreadDates[GScanDetails[aDataIndex].Files.Items[x].FileCategory, 2], GScanDetails[aDataIndex].Files.Items[x].FileSize);
        end;
      end;

      yearnode.Text  := '<b>' + yy + '</b> [' + XText[rsFiles] + ': ' + IntToStr(yearcount) + ' (' + TConvert.ConvertToUsefulUnit(yearsize) + ')]';
      monthnode.Text := '<b>' + shortmonths[StrToInt(oldmonth) ] + '</b> [' + XText[rsFiles] + ': ' + IntToStr(monthcount) + ' (' + TConvert.ConvertToUsefulUnit(monthsize) + ')]';
      daynode.Text   := '<b>' + oldday + '</b> [' + XText[rsFiles] + ': ' + IntToStr(daycount) + ' (' + TConvert.ConvertToUsefulUnit(daysize) + ')]';

      i := 0;
      // build graph from tree nodes ===============================================
      for t := 0 to oTree.Items.Count - 1 do begin
        if oTree.Items[t].Parent = Nil then begin
          x  := Pos(':', oTree.Items[t].Text) + 2;

          dd := '';
          while oTree.Items[t].Text[x] <> ' ' do begin
            dd := dd + oTree.Items[t].Text[x];
            inc(x);
          end;

          oChart.SeriesList.Items[0].Add(StrToInt(dd), Copy(TXFormatting.FilterTags(oTree.Items[t].Text), 1, 4), spectrumcolours[i mod spectrummod]); // ignore <b> from text

          inc(i);
        end;
      end;
    end;

    // ===========================================================================

    if oCapacityBar <> Nil then begin

      oCapacityBar.Items.Clear;

      for t := 1 to __FileCategoriesCount do begin
        if aQuantity then begin
          if DatesTotalCount <> 0 then begin
            if ExtSpreadDates[t, 1] <> 0 then begin
              lCapacityItem             := oCapacityBar.Items.Add;
              lCapacityItem.Value       := (ExtSpreadDates[t, 1] / DatesTotalCount) * 100;
              lCapacityItem.Color       := GSystemGlobal.FileCategoryColors[t];
              lCapacityItem.ColorTo     := GSystemGlobal.FileCategoryColors[t];
              lCapacityItem.DisplayName := TypeDescriptions[t];
              lCapacityItem.Description := TypeDescriptions[t];
              lCapacityItem.Hint        := TypeDescriptions[t] + ' (' + IntToStr(ExtSpreadDates[t, 1]) + ' files)';
            end;
          end;
        end
        else begin
          if DatesTotalSize <> 0 then begin
            if ExtSpreadDates[t, 2] <> 0 then begin
              lCapacityItem             := oCapacityBar.Items.Add;
              lCapacityItem.Value       := (ExtSpreadDates[t, 2] / DatesTotalSize) * 100;
              lCapacityItem.Color       := GSystemGlobal.FileCategoryColors[t];
              lCapacityItem.ColorTo     := GSystemGlobal.FileCategoryColors[t];
              lCapacityItem.DisplayName := TypeDescriptions[t];
              lCapacityItem.Description := TypeDescriptions[t];
              lCapacityItem.Hint        := TypeDescriptions[t] + ' (' + TConvert.ConvertToUsefulUnit(ExtSpreadDates[t, 2]) + ')';
            end;
          end;
        end;
      end;
    end;

  // ===========================================================================

  oTree.EndUpdate;

    case aDataIndex of
      dataLatestScan    : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathLS));
      dataFolderHistory : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathFH));
    end;
  except
    on E : Exception do begin
      oTree.Items.Clear;

      ShowXDialog('Error building display',
                  XText[rsDialog13] + #13#13 + 'ITFDT' + #13#13 + e.Message,
                  XDialogTypeWarning);

      TMSLogger.Error('Error building display. ' + e.ClassName + ' / ' + e.Message);
    end;
  end;
end;


class procedure TDisplayUtility.InformationTabNullFiles(aDataIndex : integer; oTable : TAdvStringGrid);
 var
  t,i : integer;
  xfo : TFileObject;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabNullFiles :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabNullFiles : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

  if aDataIndex = dataLatestScan then begin
    if XSettings.Forms.ProgressForm <> Nil then begin
      XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsNullFiles]);
      XSettings.System.JustInTimeProcessed[aDataIndex, TabIndexNull] := True;
    end;
  end;

  i := 0;

  // ===========================================================================

  oTable.ClearRows(1, oTable.RowCount - 1);
  oTable.RowCount := 2;

  oTable.BeginUpdate;

  for t := 0 to GScanDetails[aDataIndex].Files.Count - 1 do begin
    xfo := GScanDetails[aDataIndex].Files[t];

    if (faDirectory and xfo.Attributes) = 0 then begin
      if xfo.FileSize = 0 then begin
        oTable.Cells[0, oTable.RowCount - 1] := GScanDetails[aDataIndex].Folders[xfo.FilePathIndex] + xfo.Filename;

        oTable.RowCount := oTable.RowCount + 1;

        inc(i);
      end;
    end;
  end;

  if i = 0 then begin
    oTable.Cells[0, 1] := XText[rsNoneFound];
  end
  else
    oTable.RowCount := oTable.RowCount - 1;

  oTable.EndUpdate;    
end;

// sgTemp, vtcTemp, rbTempSize.Checked  : lTempStatus.Caption
class function TDisplayUtility.BuildTempChart(aDataIndex : integer; oTable : TAdvStringGrid; oChart : TChart; oTempSize : boolean): string;
 begin
  if XSettings.Forms.ProgressForm <> Nil then
    XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsTempList]);

  if XSettings.System.Debug then TMSLogger.Info('BuildTempChart : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[Category_Temp, 1]));

  if oTable.Cells[0, oTable.RowCount - 1] = '' then begin
    if oTable.RowCount = 2 then
      oTable.Cells[0,1] := XText[rsNoneFound]
    else
     oTable.RowCount := oTable.RowCount - 1;
  end;

  if GScanDetails[aDataIndex].ExtensionSpread[Category_Temp, 1] <> 0 then
    Result := '<b>' + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[Category_Temp, 1]) + '</b> ' + XText[rsFiles] + ' (<b>' + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].ExtensionSpread[Category_Temp, 2]) + '</b>)'
  else
    Result := XText[rsNoTempFilesFound];

  oChart.SeriesList.Items[0].Clear;
  oChart.Legend.TextStyle := ltsPlain;

  if GScanDetails[aDataIndex].TotalSize <> 0 then begin
    if oTempSize then begin
      oChart.Title.Text.Strings[0] := XText[rsTempFilePTSF];

      oChart.SeriesList.Items[0].Add(100 - ((GScanDetails[aDataIndex].ExtensionSpread[Category_Temp, 2]) / GScanDetails[aDataIndex].TotalSize) * 100, XText[rsAllOtherFiles], $444444);
      oChart.SeriesList.Items[0].Add(((GScanDetails[aDataIndex].ExtensionSpread[Category_Temp, 2]) / GScanDetails[aDataIndex].TotalSize) * 100, XText[rsTempFiles], $00CCFF);
    end
    else begin
      oChart.Title.Text.Strings[0] := XText[rsTempFilePTNF];

      if (GScanDetails[aDataIndex].FileCount <> 0) then begin
        oChart.SeriesList.Items[0].Add(100 - ((GScanDetails[aDataIndex].ExtensionSpread[Category_Temp, 1]) / GScanDetails[aDataIndex].FileCount) * 100, XText[rsAllOtherFiles], $444444);
        oChart.SeriesList.Items[0].Add(((GScanDetails[aDataIndex].ExtensionSpread[Category_Temp, 1]) / GScanDetails[aDataIndex].FileCount) * 100, XText[rsTempFiles], $00CCFF);
      end;
    end;
  end;

  DoTableSort(oTable, oTable.SortSettings.Column, TempSortColumns[oTable.SortSettings.Column]);
end;


//                                                      ePath, vtcFolderHistory, clbFolderHistory.Items, rbFHCount.Checked, rbFHSize.Checked, rbFHMagCount, rbFHMagSize
class procedure TDisplayUtility.BuildFolderHistoryGraph(oPath : string; oChart : TChart; oFolderHistory : TCheckListBox; oFHCount, oFHSize, oFHMagCount, oFHMagSize : boolean);
 var
  t,i,fhidx, gidx : integer;
  barseries : TBarSeries;
  ShouldAddColumn : array[0..__FileCategoriesCount] of boolean;

 begin
  if XSettings.System.Debug then TMSLogger.Info('BuildFolderHistoryGraph : ' + oPath + '/' + IntToStr(oFolderHistory.Items.Count));

  oChart.SeriesList.Clear;
  oChart.Title.Text.Clear;
  oChart.Title.Text.Add(XText[rsFolderHistoryFor] + ' "' + oPath + '"');

  if oFHCount then
    oChart.LeftAxis.Title.Caption := XText[rsNumberOfFiles]
  else if oFHSize then
    oChart.LeftAxis.Title.Caption := XText[rsSizeOfFilesBytes];

  // ===========================================================================
  // == Pre-calculate which columns need adding (don't need to add them all) ===
  // ===========================================================================

  for t := 0 to __FileCategoriesCount do
    ShouldAddColumn[t] := FALSE;

  for t  := 0  to oFolderHistory.Items.Count - 1 do begin
    if oFolderHistory.Checked[t] then begin
      fhidx := FolderHistory.Count - t - 1;

      if (oFHCount) or (oFHSize) then begin
        for i := 0 to __FileCategoriesCount do begin
          if FHCCStatus[i] then begin
            if oFHCount then begin
              if FolderHistory[fhidx].CategoryCount[i] <> 0 then ShouldAddColumn[i] := True
            end
            else if oFHSize then begin
              if FolderHistory[fhidx].CategorySize[i] <> 0 then ShouldAddColumn[i] := True;
            end;
          end;
        end;
      end
      else if (oFHMagCount) or (oFHMagSize) then begin
        for i := 0 to __MagnitudesCount do begin
          if oFHMagCount then begin
            if FolderHistory[fhidx].MagnitudeCount[i] <> 0 then ShouldAddColumn[i] := True
          end
          else if oFHMagSize then begin
            if FolderHistory[fhidx].MagnitudeSize[i] <> 0 then  ShouldAddColumn[i] := True;
          end;
        end;
      end;
    end;
  end;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  gidx := 1;

  for t := 0 to oFolderHistory.Items.Count - 1 do begin
    if oFolderHistory.Checked[t] then begin
      barseries := TBarSeries.Create(oChart);

      with barseries do begin
        Title          := oFolderHistory.Items[t];
        NormalBarColor := DefaultDisplayColours[1 + (gidx mod 12)];
        Marks.Visible  := False;
      end;

      barseries.SeriesColor := DefaultDisplayColours[1 + (gidx mod 12)];

      fhidx := FolderHistory.Count - t - 1;

      if (oFHCount) or (oFHSize) then begin
        for i := 0 to __FileCategoriesCount do begin
          if (FHCCStatus[i]) and (ShouldAddColumn[i]) then begin
            if oFHCount then
              barseries.Add(FolderHistory[fhidx].CategoryCount[i], TypeDescriptionsSmall[i], DefaultDisplayColours[1 + (gidx mod 12)])
            else if oFHSize then
              barseries.Add(FolderHistory[fhidx].CategorySize[i], TypeDescriptionsSmall[i], DefaultDisplayColours[1 + (gidx mod 12)]);
          end;
        end;
      end
      else if (oFHMagCount) or (oFHMagSize) then begin
        for i := 0 to __MagnitudesCount do begin
          if (ShouldAddColumn[i]) then begin
            if (oFHMagCount) then
              barseries.Add(FolderHistory[fhidx].MagnitudeCount[i], magnilabels2[i], DefaultDisplayColours[1 + (gidx mod 12)])
            else if oFHMagSize then
              barseries.Add(FolderHistory[fhidx].MagnitudeSize[i], magnilabels2[i], DefaultDisplayColours[1 + (gidx mod 12)]);
          end;
        end;
      end;

      oChart.AddSeries(barseries);

      inc(gidx);
    end;
  end;
end;


// sgTop50Big, sgTop50Small, cbTopUsers : pTop101Left.Caption
class function TDisplayUtility.BuildTop101FileSize(aDataIndex : integer; oTableBig, oTableSmall : TAdvStringGrid; oTopUsers : TComboBox; oCapacityBar : TAdvSmoothCapacityBar): string;
 var
  t,cx : integer;
  TopSize : Int64;
  canadd : boolean;
  lCapacityItem : TCapacityItem;

 begin
  if GScanDetails[aDataIndex].FileCount <> 0 then begin

    if XSettings.System.Debug then TMSLogger.Info('BuildTop101FileSize : ' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(GScanDetails[aDataIndex].TotalSize) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount));

    if oTopUsers.ItemIndex < 0 then oTopUsers.ItemIndex := 0;

    if XSettings.Forms.ProgressForm <> Nil then
      XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsTop101]);

    GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileSizes));

    TGridUtility.ClearStringGird(oTableBig, False);
    TGridUtility.ClearStringGird(oTableSmall, False);

    oTableBig.BeginUpdate;
    oTableSmall.BeginUpdate;

    // == build top list of largest files ========================================
    cx      := 0;
    t       := GScanDetails[aDataIndex].Files.Count - 1;
    TopSize := 0;

    while (t >= 0) and (cx <= 100) do begin
      if ((faDirectory and GScanDetails[aDataIndex].Files.Items[t].Attributes) = 0) then begin
        if oTopUsers.ItemIndex = 0 then
          canadd := True
        else
          canadd := (GScanDetails[aDataIndex].Users[GScanDetails[aDataIndex].Files.Items[t].Owner].Name = oTopUsers.Items[oTopUsers.ItemIndex]);

        if canadd then begin
          oTableBig.Cells[0, oTableBig.RowCount - 1] := GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files.Items[t].FilePathIndex] + GScanDetails[aDataIndex].Files.Items[t].FileName;
          oTableBig.Cells[1, oTableBig.RowCount - 1] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].Files.Items[t].FileSize);
          oTableBig.Cells[2, oTableBig.RowCount - 1] := GScanDetails[aDataIndex].Users[GScanDetails[aDataIndex].Files.Items[t].Owner].Name;
          oTableBig.Cells[3, oTableBig.RowCount - 1] := IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize);
          oTableBig.Cells[4, oTableBig.RowCount - 1] := IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanDetails[aDataIndex].Files.Items[t].FileName));

          oTableBig.RowCount := oTableBig.RowCount + 1;

          inc(cx);
          inc(TopSize, GScanDetails[aDataIndex].Files.Items[t].FileSize);
        end;
      end;

      dec(t);
    end;

    oTableBig.RowCount := oTableBig.RowCount - 1;

    oCapacityBar.Items.Clear;

    if (GScanDetails[aDataIndex].TotalSize <> 0) and (GScanDetails[aDataIndex].FileCount <> 0) then begin
      Result := IntToStr(oTableBig.RowCount - 1) + ' ' +
                         XText[rsFiles] + ' (' +
                         TConvert.RealToPercent((oTableBig.RowCount - 1) /GScanDetails[aDataIndex].FileCount) + '), ' +
                         TConvert.ConvertToUsefulUnit(TopSize) + ' (' + TConvert.RealToPercent(TopSize / GScanDetails[aDataIndex].TotalSize) + ')';

      lCapacityItem             := oCapacityBar.Items.Add;
      lCapacityItem.Value       := (TopSize /GScanDetails[aDataIndex].TotalSize * 100);
      lCapacityItem.Color       := $00FF8822;
      lCapacityItem.ColorTo     := $00FF8822;
      lCapacityItem.DisplayName := 'Top 101';
      lCapacityItem.Description := 'Top 101';
      lCapacityItem.Hint        := 'Top 101  (' + TConvert.ConvertToUsefulUnit(TopSize) + ')';

      lCapacityItem             := oCapacityBar.Items.Add;
      lCapacityItem.Value       := 100 - ((TopSize /GScanDetails[aDataIndex].TotalSize * 100));
      lCapacityItem.Color       := $00AAAAAA;
      lCapacityItem.ColorTo     := $00AAAAAA;
      lCapacityItem.DisplayName := 'Others';
      lCapacityItem.Description := 'Others';
      lCapacityItem.Hint        := 'Others  (' + TConvert.ConvertToUsefulUnit(TopSize -GScanDetails[aDataIndex].TotalSize) + ')';
    end
    else
      Result := IntToStr(oTableBig.RowCount - 1) + ' ' + XText[rsFiles] + ' (100%), ' + TConvert.ConvertToUsefulUnit(TopSize) + ' (100%)';

    // == build top list of smallest files =======================================
    cx := 0;
    t  := 0;

    while (t < GScanDetails[aDataIndex].Files.Count) and (cx <= 100) do begin
      if ((faDirectory and GScanDetails[aDataIndex].Files.Items[t].Attributes) = 0) then begin
        oTableSmall.Cells[0, oTableSmall.RowCount - 1] := GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files.Items[t].FilePathIndex] + GScanDetails[aDataIndex].Files.Items[t].FileName;
        oTableSmall.Cells[1, oTableSmall.RowCount - 1] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].Files.Items[t].FileSize);
        oTableSmall.Cells[2, oTableSmall.RowCount - 1] := IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize);
        oTableSmall.Cells[3, oTableSmall.RowCount - 1] := IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanDetails[aDataIndex].Files.Items[t].FileName));

        oTableSmall.RowCount := oTableSmall.RowCount + 1;

        inc(cx);
      end;

      inc(t);
    end;

    oTableSmall.RowCount := oTableSmall.RowCount - 1;

    oTableSmall.EndUpdate;
    oTableBig.EndUpdate;
  end
  else begin
    Result := '';
  end;
end;


// sgTop101BigDate, sgTop101SmallDate, cbTop101Dates : pTop101Left.Caption
class function TDisplayUtility.BuildTop101Date(aDataIndex : integer; oTopBig, oTopSmall : TAdvStringGrid; aUser, aDate : TComboBox): string;
 var
  t,cx : integer;
  TopSize : Int64;
  canadd  : boolean;

 begin
  if GScanDetails[aDataIndex].FileCount <> 0 then begin

    if XSettings.System.Debug then TMSLogger.Info('BuildTop101Date : ' + IntToStr(GScanDetails[aDataIndex].Files.Count) + '/' + IntToStr(aUser.ItemIndex) + '/' + IntToStr(GScanDetails[aDataIndex].TotalSize) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount));

    if XSettings.Forms.ProgressForm <> Nil then
      XSettings.Forms.ProgressForm.SetProcessText(XText[rsBuilding] + ' ' + XText[rsTop101]);

    case aDate.ItemIndex of
      CCreatedDate  : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
      CAccessedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
      CModifiedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
    end;

    TGridUtility.ClearStringGird(oTopBig, False);
    TGridUtility.ClearStringGird(oTopSmall, False);

    oTopBig.BeginUpdate;
    oTopSmall.BeginUpdate;

    // == build top list of largest files ========================================
    cx      := 0;
    t       := GScanDetails[aDataIndex].Files.Count - 1;
    TopSize := 0;

    while (t >= 0) and (cx <= 100) do begin
     if ((faDirectory and GScanDetails[aDataIndex].Files.Items[t].Attributes) = 0) then begin
        if aUser.ItemIndex = 0 then
          canadd := True
        else
          canadd := (GScanDetails[aDataIndex].Users[GScanDetails[aDataIndex].Files.Items[t].Owner].Name = aUser.Items[aUser.ItemIndex]);

        if canadd then begin
          oTopBig.Cells[CTopBigFullPath, oTopBig.RowCount - 1] := GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files.Items[t].FilePathIndex] + GScanDetails[aDataIndex].Files.Items[t].FileName;

          case aDate.ItemIndex of
            CCreatedDate  : oTopBig.Cells[CTopBigFileDate, oTopBig.RowCount - 1] := TConvert.IntDateToString(GScanDetails[aDataIndex].Files.Items[t].FileDateC);
            CAccessedDate : oTopBig.Cells[CTopBigFileDate, oTopBig.RowCount - 1] := TConvert.IntDateToString(GScanDetails[aDataIndex].Files.Items[t].FileDateA);
            CModifiedDate : oTopBig.Cells[CTopBigFileDate, oTopBig.RowCount - 1] := TConvert.IntDateToString(GScanDetails[aDataIndex].Files.Items[t].FileDateM);
          end;

          oTopBig.Cells[CTopBigFileSizeUU, oTopBig.RowCount - 1] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].Files.Items[t].FileSize);
          oTopBig.Cells[CTopBigName,       oTopBig.RowCount - 1] := GScanDetails[aDataIndex].Users[GScanDetails[aDataIndex].Files.Items[t].Owner].Name;
          oTopBig.Cells[CTopBigFileName,   oTopBig.RowCount - 1] := IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanDetails[aDataIndex].Files.Items[t].FileName));
          oTopBig.Cells[CTopBigFileSizeAB, oTopBig.RowCount - 1] := IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize);

          oTopBig.RowCount := oTopBig.RowCount + 1;

          inc(cx);
          inc(TopSize, GScanDetails[aDataIndex].Files.Items[t].FileSize);
        end;
      end;

      dec(t);
    end;

    oTopBig.RowCount := oTopBig.RowCount - 1;

    if (GScanDetails[aDataIndex].TotalSize <> 0) and (GScanDetails[aDataIndex].FileCount <> 0) then
      Result := IntToStr(oTopBig.RowCount - 1) + ' ' + XText[rsFiles] + ' (' + TConvert.RealToPercent((oTopBig.RowCount - 1) /GScanDetails[aDataIndex].FileCount) + '), ' + TConvert.ConvertToUsefulUnit(TopSize) + ' (' + TConvert.RealToPercent(TopSize / GScanDetails[aDataIndex].TotalSize) + ')'
    else
      Result := IntToStr(oTopBig.RowCount - 1) + ' ' + XText[rsFiles] + ' (100%), ' + TConvert.ConvertToUsefulUnit(TopSize) + ' (100%)';

    // == build top list of smallest files =======================================
    cx := 0;
    t  := 0;

    while (t < GScanDetails[aDataIndex].Files.Count) and (cx <= 100) do begin
      if ((faDirectory and GScanDetails[aDataIndex].Files.Items[t].Attributes) = 0) then begin

        oTopSmall.Cells[CTopBigFullPath, oTopSmall.RowCount - 1] := GScanDetails[aDataIndex].Folders[GScanDetails[aDataIndex].Files.Items[t].FilePathIndex] + GScanDetails[aDataIndex].Files.Items[t].FileName;

        case aDate.ItemIndex of
          CCreatedDate  : oTopSmall.Cells[CTopBigFileDate, oTopSmall.RowCount - 1] := TConvert.IntDateToString(GScanDetails[aDataIndex].Files.Items[t].FileDateC);
          CAccessedDate : oTopSmall.Cells[CTopBigFileDate, oTopSmall.RowCount - 1] := TConvert.IntDateToString(GScanDetails[aDataIndex].Files.Items[t].FileDateA);
          CModifiedDate : oTopSmall.Cells[CTopBigFileDate, oTopSmall.RowCount - 1] := TConvert.IntDateToString(GScanDetails[aDataIndex].Files.Items[t].FileDateM);
        end;

        oTopSmall.Cells[CTopBigFileSizeUU, oTopSmall.RowCount - 1] := TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].Files.Items[t].FileSize);
        oTopSmall.Cells[CTopBigName,       oTopSmall.RowCount - 1] := GScanDetails[aDataIndex].Users[GScanDetails[aDataIndex].Files.Items[t].Owner].Name;
        oTopSmall.Cells[CTopBigFileName,   oTopSmall.RowCount - 1] := IntToStr(FileExtensionsObject.GetExtensionCategoryIDFromName(GScanDetails[aDataIndex].Files.Items[t].FileName));
        oTopSmall.Cells[CTopBigFileSizeAB, oTopSmall.RowCount - 1] := IntToStr(GScanDetails[aDataIndex].Files.Items[t].FileSize);

        oTopSmall.RowCount := oTopSmall.RowCount + 1;

        inc(cx);
      end;

      inc(t);
    end;

    oTopSmall.RowCount := oTopSmall.RowCount - 1;

    oTopBig.EndUpdate;
    oTopSmall.EndUpdate;
  end
end;


class function TDisplayUtility.GetSourceAsString(aScanSource : integer) : string;
begin
  case aScanSource of
    ScanSourceLive             : Result := 'Live scan';
    ScanSourceFileXinNormal    : Result := 'Xinorbis report (v1) normal data';
    ScanSourceFileCSV          : Result := 'CSV report';
    ScanSourceFileXinDetailed  : Result := 'Xinorbis report (v1) detailed data';
    ScanSourceLiveShare        : Result := 'Live scan (shared drive)';
    ScanSourceFolderHistory    : Result := 'Folder History';
    ScanSourceSearchResults    : Result := 'Search results';
    ScanSourceFileXin2Detailed : Result := 'Xinorbis report (v2) detailed data';
  else
    Result := 'Unknown data source';
  end;
end;


end.
