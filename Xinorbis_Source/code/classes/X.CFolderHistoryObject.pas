{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CFolderHistoryObject;

interface

uses
  System.SysUtils, Classes, System.Generics.Collections, System.DateUtils,

  X.Dialogs.Dialog,

  X.Constants, X.LanguageHandler, X.SystemGlobal;


type
  TFolderHistoryObject   = class(TObject)
  private
  public
    ScanDate       : TDateTime;
    ScanDateInt    : string;
    ScanDateStr    : string;

    FileCount      : int64;
    FileSize       : int64;
    FileSizeOnDisk : int64;
    FolderCount    : integer;
    CategoryCount  : array[0..__FileCategoriesCount] of integer;
    CategorySize   : array[0..__FileCategoriesCount] of int64;
    MagnitudeCount : array[0..__MagnitudesCount] of integer;
    MagnitudeSize  : array[0..__MagnitudesCount] of int64;
  end;


var
  FolderHistory : TObjectList<TFolderHistoryObject>;


const
  CPropertyScanDateString     =  0;
  CPropertyScanDateInteger    =  1;
  CPropertyFileCount          =  2;
  CPropertyTotalSize          =  3;
  CPropertyFolderCount        =  4;
  CPropertyVersion            =  5;
  CPropertyCategoryCount8Bit  = 10;
  CPropertyCategorySize8Bit   = 11;
  CPropertyMagnitudeCount     = 20;
  CPropertyMagnitudeSize      = 21;
  CPropertyTotalSizeOnDisk    = 30;
  CPropertyCategoryCount16Bit = 40;
  CPropertyCategorySize16Bit  = 41;


function LoadFolderHistory(const ComputerName, ScanPath : string; aFolderHistoryList : TStrings): boolean;
function IdentifyProperty(const s : string): integer;


implementation


uses X.Global, X.MD5, X.Conversions, X.Utility;


function LoadFolderHistory(const ComputerName, ScanPath : string; aFolderHistoryList : TStrings): boolean;
 var
  tf : TextFile;
  fhobj : TFolderHistoryObject;
  s,xprop,xvalue,newdate : string;

 begin
  Result := True;
  fhobj  := Nil;

  if FileExists(GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh') then begin
    AssignFile(tf, GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh');

    {$I-}
    Reset(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorOpening] + ': ' + XText[rsFolderHistory],
                  XText[rsErrorOpeningXinorbisSystemFile] + ': ' + #13#13 +
                  GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh',
                  XDialogTypeWarning);
    end
    else begin
      // read the first line, it contains the scan path --------------------------
      Readln(tf, s);
      // -------------------------------------------------------------------------

      while not(eof(tf)) do begin
        Readln(tf, s);

        if s[1] = '{' then begin
          fhobj := TFolderHistoryObject.Create;

          fhobj.ScanDateInt := '00000000000000';
       end
        else if s[1] = '}' then begin
          if Assigned(fhobj) then
            FolderHistory.Add(fhobj);
        end
        else begin
          xprop  := Copy(s, 1, 3);
          xvalue := Copy(s, 5, length(s) - 4);

          case IdentifyProperty(xprop) of
            CPropertyScanDateString     : begin
                                            newdate := TConvert.IntDateToString(StrToInt(xvalue[1] + xvalue[2] + xvalue[3] + xvalue[4] + xvalue[6] + xvalue[7] + xvalue[9] + xvalue[10])) + ' ' + Copy(xvalue, 12, 8);

                                            aFolderHistoryList.Insert(0, newdate);

                                            fhobj.ScanDateStr := newdate;
                                          end;
            CPropertyScanDateInteger    : begin
                                            fhobj.ScanDateInt := xvalue;

                                            fhobj.ScanDate    := TConvert.IntegerDateToTDateTime(xvalue);
                                          end;
            CPropertyFileCount          : fhobj.FileCount   := StrToInt64Def(xvalue, 0);
            CPropertyTotalSize          : fhobj.FileSize    := StrToInt64Def(xvalue, 0);
            CPropertyFolderCount        : fhobj.FolderCount := StrToIntDef(xvalue, 0);

            CPropertyCategoryCount8bit  : fhobj.CategoryCount[TConvert.HexToInt(xprop[2])]  := StrToInt(xvalue);
            CPropertyCategorySize8bit   : fhobj.CategorySize[TConvert.HexToInt(xprop[2])]   := StrToInt64(xvalue);

            CPropertyMagnitudeCount     : fhobj.MagnitudeCount[TConvert.HexToInt(xprop[2])] := StrToInt64(xvalue);
            CPropertyMagnitudeSize      : fhobj.MagnitudeSize[TConvert.HexToInt(xprop[2])]  := StrToInt64(xvalue);

            CPropertyTotalSizeOnDisk    : fhobj.FileSizeOnDisk := StrToInt64(xvalue);

            CPropertyCategoryCount16bit : fhobj.CategoryCount[TConvert.HexToInt(xprop[2] + xprop[3])] := StrToInt(xvalue);
            CPropertyCategorySize16bit  : fhobj.CategorySize[TConvert.HexToInt(xprop[2] + xprop[3])]  := StrToInt64(xvalue);
          end;
        end;
      end;

      CloseFile(tf);
    end;
    {$I+}
  end
  else
    Result := False;
end;


function IdentifyProperty(const s : string): integer;
 begin
  Result := -1;

  if      s = 'DAT' then Result := CPropertyScanDateString
  else if s = 'DAX' then Result := CPropertyScanDateInteger
  else if s = 'FIC' then Result := CPropertyFileCount
  else if s = 'FIS' then Result := CPropertyTotalSize
  else if s = 'FOC' then Result := CPropertyFolderCount
  else if s = 'SYS' then Result := CPropertyVersion

  else if (s[1] = 'C') and (s[3] = 'C') then Result := CPropertyCategoryCount8Bit
  else if (s[1] = 'C') and (s[3] = 'S') then Result := CPropertyCategorySize8Bit

  else if (s[1] = 'M') and (s[3] = 'C') then Result := CPropertyMagnitudeCount
  else if (s[1] = 'M') and (s[3] = 'S') then Result := CPropertyMagnitudeSize

  else if s = 'SOD' then Result := CPropertyTotalSizeOnDisk

  else if s[1] = 'X' then Result := CPropertyCategoryCount16Bit  // X00 - XFF
  else if s[1] = 'Y' then Result := CPropertyCategorySize16Bit;   // Y00 - YFF
end;


end.
