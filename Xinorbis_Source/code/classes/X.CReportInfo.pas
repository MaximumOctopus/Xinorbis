{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CReportInfo;

interface


uses
  System.Sysutils, System.Classes, Vcl.StdCtrls,

  TMSLogging,

  X.DisplayUtility, X.LanguageHandler;


type
  TReportInfo = class
    class procedure GetInfoXinorbisReport(aFileName : string; var aMemo : TMemo);
    class function GetInfoXinorbis2Report(aFileName : string; var aMemo : TMemo): boolean;

    class procedure GetInfoCSVReport(aFileName : string; var aMemo : TMemo);
  end;


implementation


const
  CInfoHeader      = 0;
  CInfoPath        = 1;
  CInfoFolderCount = 2;
  CInfoFileCOunt   = 3;
  CInfoTotalSize   = 4;
  CInfoDate        = 5;
  CInfoScanSource  = 6;



class procedure TReportInfo.GetInfoXinorbisReport(aFileName : string; var aMemo : TMemo);
begin
  aMemo.Clear;

  aMemo.Lines.Add(XText[rsReport] + ': Xinorbis (old version)');
end;


class function TReportInfo.GetInfoXinorbis2Report(aFileName : string; var aMemo : TMemo): boolean;
var
  tf : TextFile;
  str : string;
  rowIndex : integer;
  inInfo   : boolean;

begin
  Result := True;

  aMemo.Clear;

  if FileExists(aFileName) then begin

    inInfo   := False;
    rowIndex := 0;

    AssignFile(tf, aFileName);
    {$I-}
    Reset(tf);

    if IOResult <> 0 then begin
      Result := False;

      aMemo.Lines.Add('Error <' + IntToStr(IOResult) + '> loading report "' + aFileName + '".');

      TMSLogger.Error('Error <' + IntToStr(IOResult) + '> loading report "' + aFileName + '".');
    end
    else begin

      aMemo.Lines.Add(XText[rsReport] + ': Xinorbis v2');
      aMemo.Lines.Add('');

      while not(eof(tf)) do begin
        readln(tf, str);

        if str <> '' then begin
          case str[1] of
            '{' : begin
                    if Pos('info', str) <> 0 then
                      inInfo := True;

                    rowIndex  := 0;
                  end;
            '}' : begin
                    if (inInfo) then
                      Break;
                  end;
          else
            if inInfo then begin
              case rowIndex of
//                CInfoHeader : aMemo.Lines.Add(str); // header
                CInfoPath        : aMemo.Lines.Add(str);
                CInfoFolderCount : aMemo.Lines.Add(XText[rsFolders] + ': ' + str);
                CInfoFileCOunt   : aMemo.Lines.Add(XText[rsFiles] + ': ' + str);
                CInfoTotalSize   : aMemo.Lines.Add(XText[rsTotalSize] + ': ' + str);
                CInfoDate        : aMemo.Lines.Add(str);
                CInfoScanSource  : aMemo.Lines.Add(TDisplayUtility.GetSourceAsString(StrToInt(str)));
              end;
            end;

            inc(rowIndex);
          end;
        end;
      end;
    end;

    CloseFile(tf);
  end
  else begin
    Result := False;

    TMSLogger.Error('Error report file not found "' + aFileName + '".');

    aMemo.Lines.Add('Error report file not found "' + aFileName + '".');
  end;
  {$I+}
end;


class procedure TReportInfo.GetInfoCSVReport(aFileName : string; var aMemo : TMemo);
var
  lFile : TStringList;

begin
  aMemo.Clear;

  aMemo.Lines.Add(XText[rsReport] + ': CSV');

  lFile := TStringList.Create;
  lFile.LoadFromFile(aFileName);

  aMemo.Lines.Add(IntToStr(lFile.Count) + ' records');

  lFile.Free;
end;


end.
