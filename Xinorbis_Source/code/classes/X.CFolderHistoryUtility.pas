{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CFolderHistoryUtility;

interface


uses
  SysUtils,

  X.Dialogs.Dialog,

  X.GlobalObjects, X.SystemGlobal,

  X.Constants, X.LanguageHandler, X.MD5, X.Windows;


type
  TFolderHistoryUtility = class
    class procedure UpdateFolderHistoryFile(aDataIndex : integer; aScanPath : string);
  end;


implementation


class procedure TFolderHistoryUtility.UpdateFolderHistoryFile(aDataIndex : integer; aScanPath : string);
var
  tf : TextFile;
  t  : integer;
  lTitle : string;
  lFileName : string;

begin
  lFileName := GSystemGlobal.AppDataPath + 'FolderHistory\' + TXWindows.GetComputerNetName + '\' + TMD5.Generate(UpperCase(aScanPath)) + '.xfh';

  AssignFile(tf, lFileName);

  {$I-}

  if FileExists(lFileName) then
    Append(tf)
  else begin
    Rewrite(tf);

    writeln(tf, aScanPath);
  end;

  if IOResult <> 0 then begin
    if SysUtils.DirectoryExists(GSystemGlobal.AppDataPath + 'FolderHistory\' + TXWindows.GetComputerNetName) then
    begin
      if FileExists(lFileName) then
        lTitle := 'Error updating Xinorbis system file (Folder + File Exist)'
      else
        lTitle := 'Error updating Xinorbis system file (Folder Exists, File Does Not)'
    end
    else
      lTitle := 'Error updating Xinorbis system file (Folder Not Found)';

    ShowXDialog(lTitle,
                XText[rsErrorSaving] + ' "' + lFileName + '"',
                XDialogTypeWarning);
  end
  else begin
    writeln(tf, '{');
    writeln(tf, 'SYS:Xinorbis ' + x8Version);
    writeln(tf, 'DAT:' + GScanDetails[aDataIndex].ScanDateStr);
    writeln(tf, 'DAX:' + GScanDetails[aDataIndex].ScanDateInt);
    writeln(tf, 'FIC:' + IntToStr(GScanDetails[aDataIndex].FileCount));
    writeln(tf, 'FIS:' + IntToStr(GScanDetails[aDataIndex].TotalSize));
    writeln(tf, 'FOC:' + IntToStr(GScanDetails[aDataIndex].FolderCount));
    writeln(tf, 'SOD:' + IntToStr(GScanDetails[aDataIndex].TotalSizeOD));

    for t := 0 to __FileCategoriesCount do begin
      writeln(tf, 'X' + IntToHex(t, 2) + ':' + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 1]));
      writeln(tf, 'Y' + IntToHex(t, 2) + ':' + IntToStr(GScanDetails[aDataIndex].ExtensionSpread[t, 2]));
    end;

    for t := 0 to __MagnitudesCount do begin
      writeln(tf, 'M' + IntToHex(t, 1) + 'C:' + IntToStr(GScanDetails[aDataIndex].Magnitude.Data[Category_MagnitudeAll, t, 0]));
      writeln(tf, 'M' + IntToHex(t, 1) + 'S:' + IntToStr(GScanDetails[aDataIndex].Magnitude.Data[Category_MagnitudeAll, t, 1]));
    end;

    writeln(tf, '}');

    CloseFile(tf);
  end;
  {$I+}
end;


end.
