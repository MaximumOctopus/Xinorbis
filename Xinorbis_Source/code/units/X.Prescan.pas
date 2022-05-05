//
//  pre-scan setup code
//
//       Started : December 16th 2015
// Last Modified : January 16th 2019

unit X.Prescan;

interface

uses SysUtils, advgrid,

     TMSLogging,

     X.Global, X.FileExtension, X.FileExtensionsObject, X.CRootFoldersData,

     X.Constants, X.GlobalObjects, X.GridUtility, X.Utility, X.SystemGlobal;


type
  TPreScan = class
    class procedure PurgeAllData(aDataIndex : integer; asgNullFiles, asgNullFolders, asgSearchResults : TAdvStringGrid);
    class procedure PurgeAllDataRefresh(aDataIndex : integer; asgNullFiles, asgNullFolders, asgSearchResults : TAdvStringGrid);
  end;


implementation


class procedure TPreScan.PurgeAllData(aDataIndex : integer; asgNullFiles, asgNullFolders, asgSearchResults : TAdvStringGrid);
 var
  t : integer;
  tfx : TFileExtension;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'PurgeAllData :: invalid dataindex :: ' + inttostr(aDataIndex));

  // ===========================================================================

  GScanDetails[aDataIndex].ClearAll;

  // ===========================================================================

  for t := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
    tfx := FileExtensionsObject.CategoryExtensions[t];

    tfx.Size[aDataIndex]     := 0;
    tfx.Quantity[aDataIndex] := 0;
  end;

  // ===========================================================================

  GSystemGlobal.FolderStructure.Clear;
  HGraphData.Clear;
  FHGraphData.Clear;

  case aDataIndex of
    dataLatestScan : begin
                       TGridUtility.ClearStringGird(asgNullFiles, false);
                       TGridUtility.ClearStringGird(asgNullFolders, false);
                     end;
  end;

  if asgSearchResults <> Nil then
    TGridUtility.ClearStringGird(asgSearchResults, False);
end;


class procedure TPreScan.PurgeAllDataRefresh(aDataIndex : integer; asgNullFiles, asgNullFolders, asgSearchResults : TAdvStringGrid);
 var
  t : integer;
  tfx : TFileExtension;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'PurgeAllData :: invalid dataindex :: ' + inttostr(aDataIndex));

  // ===========================================================================

  GScanDetails[aDataIndex].ClearForRefresh;

  // ===========================================================================

  for t := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
    tfx := FileExtensionsObject.CategoryExtensions[t];

    tfx.Size[aDataIndex]     := 0;
    tfx.Quantity[aDataIndex] := 0;
  end;

  // ===========================================================================

  GSystemGlobal.FolderStructure.Clear;
  HGraphData.Clear;
  FHGraphData.Clear;

  case aDataIndex of
    dataLatestScan : begin
                       TGridUtility.ClearStringGird(asgNullFiles, false);
                       TGridUtility.ClearStringGird(asgNullFolders, false);
                     end;
  end;

  if asgSearchResults <> Nil then
    TGridUtility.ClearStringGird(asgSearchResults, False);
end;


end.
