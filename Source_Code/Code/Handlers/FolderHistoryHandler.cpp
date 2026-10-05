// =====================================================================
//
//   Xinorbis 10.0
//
// (c) Paul Alan Freshney 2002-2026
//
// paul@freshney.org
//
// https://maximumoctopus.hashnode.dev/
//
// https://github.com/MaximumOctopus/Xinorbis
//
// =====================================================================

#include "FolderHistoryHandler.h"

FolderHistoryHandler *GFolderHistoryHandler;


bool FolderHistoryHandler::Load(const std::wstring ComputerName, const std::wstring ScanPath, TStrings *aFolderHistoryList)
{/*
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
	Result := False; */
}
