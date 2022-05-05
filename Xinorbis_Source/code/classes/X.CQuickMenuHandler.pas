{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CQuickMenuHandler;

interface


uses
  Vcl.Menus, System.Classes, System.SysUtils, System.Contnrs, System.DateUtils,
  Generics.Collections,

  X.Conversions, X.Form.GetSizeBetween, X.Form.GetDateBetween, X.Utility;


var
  MenuStrings : TStringList;


function  ParseMenuSearchCommand(s : string): string;
function  ParseMenuSearchCommandII(s : string): integer;


implementation


function ParseMenuSearchCommand(s : string): string;
 var
  ParamList : TStringList;
  t,dwindex : integer;
  pm : string;
  gocopy : boolean;

 begin
  ParamList := TStringList.Create;

  pm     := '';
  gocopy := False;

  for t := 1 to Length(s) do begin
    if s[t] = '}' then begin
      gocopy := False;

      ParamList.Add(UpperCase(pm));

      pm := '';
    end;

    if gocopy then
      pm := pm + s[t];

    if s[t] = '{' then
      gocopy := True;
  end;

  // ===========================================================================

  for t := 0 to ParamList.Count - 1 do begin
    if ParamList[t] = 'NOW' then
      s := StringReplace(s, '{NOW}', TConvert.DateToYYYYMMDD(Now), [rfReplaceAll])
    else if ParamList[t] = 'YESTERDAY' then
      s := StringReplace(s, '{YESTERDAY}', TConvert.DateToYYYYMMDD(Now - 1), [rfReplaceAll])
    else if ParamList[t] = 'GETDATEDIALOGC' then
      s := GetDateDialog('date')
    else if ParamList[t] = 'GETDATEDIALOGA' then
      s := GetDateDialog('adate')
    else if ParamList[t] = 'GETDATEDIALOGM' then
      s := GetDateDialog('mdate')
    else if ParamList[t] = 'GETSIZEDIALOG' then
      s := GetSizeDialog
    else if Pos('DECWEEK', ParamList[t]) <> 0 then begin
      if Length(ParamList[t]) <> 7 then begin
        dwindex := StrToIntDef(Copy(ParamList[t], 8, length(ParamList[t]) - 7), 0);
      end
      else
        dwindex := 1;

      s := StringReplace(s, '{' +ParamList[t] + '}', TConvert.DateToYYYYMMDD(IncWeek(Now, -(dwindex))), [rfReplaceAll])
    end
    else if Pos('DECMONTH', ParamList[t]) <> 0 then begin
      if Length(ParamList[t]) <> 8 then begin
        dwindex := StrToIntDef(Copy(ParamList[t], 9, length(ParamList[t]) - 8), 0);
      end
      else
        dwindex := 1;

      s := StringReplace(s, '{' +ParamList[t] + '}', TConvert.DateToYYYYMMDD(IncMonth(Now, -(dwindex))), [rfReplaceAll]);
    end;
  end;

  TUtility.StringListClear(ParamList);
  ParamList.Free;

  Result := s;
end;


function ParseMenuSearchCommandII(s : string): integer;
 var
  cmd : string;
 begin
  Result := -1;

  cmd := UpperCase(Copy(s, 2, length(s) - 1));

  if cmd = 'SEARCHWIZARD' then
    Result := 1;
end;


end.
