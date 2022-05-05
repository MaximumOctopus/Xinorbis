//
// (c) Paul Alan Freshney 2019
//
// Utility for Xinorbis
//
// Last Modified: January 16th 2019
//
// 455

unit
  X.Utility;

interface

uses
  System.SysUtils, Classes, dialogs,

  X.Global,

  X.Constants, X.Conversions, X.LanguageHandler, X.SystemGlobal;


type
  PNodeData = ^TNodeData;
  TNodeData = record
    FolderID : integer;
  end;


  TUtility = class
    class function  ExcludedFoldersToString: string;
    class function  ExcludedFilesToString: string;
    class procedure StringToExcludedFolders(const ef : string);
    class procedure StringToExcludedFiles(const ef : string);

    class function  TimeElapsed(dt : TDateTime): string;
    class function  GetCurrentYear: string;
    class function  GetTime(retformat : integer): string;
    class function  GetDate(retformat : integer): string;

    class function  GetDefaultFileName(aExtension, aPrefix : string): string;
    class function  LastFolder(const s : string): string;
    class procedure MakePath(const s : string);
    class function  ReturnFilenameWithoutExt(const s : string): string;

    class function  ReportFileName(const s : string): string;

    class function  IsAlphabetCharacter(aAsciiCode : integer): boolean;
    class function  IsTestCharacter(aAsciiCode : integer): boolean;

    class function  CountCharacters(const s : string; bob : char): integer;
    class function  FindReportItem(const ReportOptions : string; itemID : integer): boolean;
    class function  FindUserIndex(DATAINDEX : integer; const u : string): integer;
    class function  QuickFolderExists(s : string): boolean;
    class procedure StringListClear(const strings: TStrings);

    class function  FastStartsStr(const Sub, Str: string): boolean;

    class function  ComponentWidth(aTextWidth : integer; aMinWidth : integer): integer;
  end;


implementation


uses
  X.GlobalObjects, X.Settings;


class function TUtility.ExcludedFoldersToString: string;
 var
  t : integer;

 begin
  Result := '';

  if GSystemGlobal.ExcludedFolders.Count <> 0 then begin
    for t := 0 to GSystemGlobal.ExcludedFolders.Count - 1 do
      Result := Result + GSystemGlobal.ExcludedFolders[t] + ';';
  end;
end;


class function TUtility.ExcludedFilesToString: string;
 var
  t : integer;

 begin
  Result := '';

  if GSystemGlobal.ExcludedFiles.Count <> 0 then begin
    for t := 0 to GSystemGlobal.ExcludedFiles.Count - 1 do
      Result := Result + GSystemGlobal.ExcludedFiles[t] + ';';
  end;
end;


class procedure TUtility.StringToExcludedFolders(const ef : string);
 var
  t : integer;
  e : string;

 begin
  if ef <> '' then begin
    GSystemGlobal.ExcludedFolders.Clear;

    e := '';

    for t := 1 to length(ef) do begin
      if ef[t] = ';' then begin
        GSystemGlobal.ExcludedFolders.Add(e);

        e := '';
      end
      else
        e := e + ef[t];
    end;
  end;
end;

class procedure TUtility.StringToExcludedFiles(const ef : string);
 var
  t : integer;
  e : string;

 begin
  if ef <> '' then begin
    GSystemGlobal.ExcludedFiles.Clear;

    e := '';

    for t := 1 to length(ef) do begin
      if ef[t] = ';' then begin
        GSystemGlobal.ExcludedFiles.Add(e);

        e := '';
      end
      else
        e := e + ef[t];
    end;
  end;
end;


// =============================================================================
// =============================================================================


class function TUtility.TimeElapsed(dt : TDateTime): string;
 var
  hh,mm,ss,sss : word;

 begin
  Result := '';

  DecodeTime(dt, hh, mm, ss, sss);

  if hh > 0 then begin
    if hh = 1 then
      Result := Result + IntToStr(hh) + ' ' + XText[rsHour] + ' '
    else
      Result := Result + IntToStr(hh) + ' ' + XText[rsHours] + ' ';
  end;

  if mm > 0 then begin
    if mm = 1 then
      Result := Result + IntToStr(mm) + ' ' + XText[rsMinute] + ' '
    else
      Result := Result + IntToStr(mm) + ' ' + XText[rsMinutes] + ' ';
  end;

  if ss > 0 then begin
    if ss = 1 then
      Result := Result + IntToStr(ss) + ' ' + XText[rsSecond]
    else
      Result := Result + IntToStr(ss) + ' ' + XText[rsSeconds];
  end;

  if Result = '' then Result := '<1 ' + XText[rsSecond];
end;


class function TUtility.GetCurrentYear: string;
var
  yyyy, mm, dd : word;
begin
  DecodeDate(Now, yyyy, mm, dd);

  Result := IntToStr(yyyy);
end;


class function TUtility.GetTime(retformat : integer): string;
 var
  hh,mm,ss,sss : word;
  xhh,xmm,xss : string;

 begin
  Result := '';

  DecodeTime(Now, hh, mm, ss, sss);

  xhh := IntToStr(hh);
  if Length(xhh) = 1 then xhh := '0' + xhh;

  xmm := IntToStr(mm);
  if Length(xmm) = 1 then xmm := '0' + xmm;

  xss := IntToStr(ss);
  if Length(xss) = 1 then xss := '0' + xss;

  if retformat = GETTIMEFORMAT_DISPLAY then    Result := xhh + ':' + xmm + '.' + xss
  else if retformat = GETTIMEFORMAT_FILE then  Result := xhh + xmm + xss
  else if retformat = GETTIMEFORMAT_SLASH then Result := xhh + ':' + xmm + ':' + xss;
end;


class function TUtility.GetDate(retformat : integer): string;
 var
  Year, Month, Day : word;
  xday,xmonth, s : string;

 begin
  DecodeDate(Now, Year, Month, Day);

  xDay   := IntToStr(Day);
  xMonth := IntToStr(Month);

  case retformat of
    GETTIMEFORMAT_DISPLAY  : begin
                               s := Months[month] + ' ' + xDay + ' ' + IntToStr(Year);
                             end;
    GETTIMEFORMAT_FILE     : begin
                               if length(xDay) = 1 then   xDay   := '0' + xDay;
                               if length(xMonth) = 1 then xMonth := '0' + xMonth;

                               s := xDay + xMonth + IntToStr(Year);
                             end;
    GETTIMEFORMAT_YYYYMMDD : begin
                               if length(xDay) = 1 then   xDay   := '0' + xDay;
                               if length(xMonth) = 1 then xMonth := '0' + xMonth;

                               s := IntToStr(year) + xMonth + xDay;
                             end;
    GETTIMEFORMAT_SLASH    : begin
                               if length(xDay) = 1 then   xDay   := '0' + xDay;
                               if length(xMonth) = 1 then xMonth := '0' + xMonth;

                               s := IntToStr(year) + '/' + xMonth + '/' + xDay;
                             end;
  end;

  Result := s;
end;


// =============================================================================
// =============================================================================


class function TUtility.GetDefaultFileName(aExtension, aPrefix : string): string;
 begin
  Result := aPrefix + '_' + TConvert.DateToYYYYMMDD(Now) + '_' + TConvert.TimeToString(Now, False) + aExtension;

  Result := TUtility.ReportFileName(Result);
end;


class function TUtility.LastFolder(const s : string): string;
 var
  t : integer;

 begin
   Result := '';

  if length(s) > 0 then begin

    if s[Length(s)] = '\' then begin
      t := Length(s) - 1;

      while (t >= 1) and (s[t] <> '\') do begin
        Result := S[t] + Result;

        dec(t);
      end;
    end
    else begin
      t:=Length(s);

      while (t >= 1) and (s[t] <> '\') do begin
        Result := S[t] + Result;

        dec(t);
      end;
    end;
  end;
end;


class procedure TUtility.MakePath(const s : string);
var
  t : integer;
  paf : string;

begin
  paf := '';

  t := Pos(':\',s);

  if t = 0 then begin
    t := Pos('\\', s);

    if t <> 0 then
      paf := Copy(s, 1, 2);
  end
  else
    paf := Copy(s, 1, 3);

  inc(t,2);

  if t > 0 then begin
    while t <= length(s) do begin
      if s[t] = '\' then begin
        if not(DirectoryExists(paf + '\')) then
          CreateDir(paf);

        paf := paf + '\';
      end
      else
        paf := paf + s[t];

      inc(t);
    end;
  end;
end;


class function TUtility.ReturnFilenameWithoutExt(const s : string): string;
 var
  idx,t : integer;
  res : string;

 begin
  Assert(s <> '', 'ReturnFilenameWithoutExt :: blank input');

  idx := Pos('.', s);

  if idx = 0 then
    Result := S
  else begin
    res := '';
    for t := 1 to idx - 1 do
      res := res + s[t];

    Result := res;
  end;
end;


// =============================================================================
// =============================================================================


class function TUtility.ReportFileName(const s : string): string;
begin
  Result := LowerCase(StringReplace(s, ' ', '_', [rfReplaceAll]));
end;

// =============================================================================
// =============================================================================


class function TUtility.IsAlphabetCharacter(aAsciiCode : integer): boolean;
begin
  Result := False;

  if (aAsciiCode >= 65) and (aAsciiCode <= 90) or
     (aAsciiCode >= 97) and (aAsciiCode <= 122) then begin
    Result := True;
  end;
end;


// < = > ! ~
class function TUtility.IsTestCharacter(aAsciiCode : integer): boolean;
begin
  Result := False;

  if ((aAsciiCode >= 60) and (aAsciiCode <= 62)) or
     (aAsciiCode = 33) or (aAsciiCode = 126) then
    Result := True;
end;


// =============================================================================
// =============================================================================


class function TUtility.CountCharacters(const s : string; bob : char): integer;
 var
  t : integer;

 begin
  Result := 0;

  for t := 1 to length(s) do
    if s[t] = bob then

  inc(Result);
end;


class function TUtility.FindReportItem(const ReportOptions : string; itemID : integer): boolean;
 var
  s : string;
  t : integer;

 begin
  Result := False;
  s      := '';

  for t := 1 to length(ReportOptions) do begin
    if ReportOptions[t] = ':' then begin
      if StrToIntDef(s, -1) = itemID then Result := True;

      s := '';
    end
    else
      s := s + ReportOptions[t];
  end;
end;


class function TUtility.FindUserIndex(DATAINDEX : integer; const u : string): integer;
 var
  t : integer;

 begin
  Assert((dataindex >= 0) and (dataindex <= 1), 'FindUserIndex :: invalid dataindex :: ' + inttostr(dataindex));

  Result := -1;

  if GScanDetails[DataIndex].Users.Count <> 0 then begin
    for t := 0 to GScanDetails[DataIndex].Users.Count - 1 do begin
      if GScanDetails[DataIndex].Users[t].Name = u then begin
        Result := t;

        Break;
      end;
    end;
  end;
end;


class function TUtility.QuickFolderExists(s : string): boolean;
 var
  t : integer;

 begin
  Result := False;

  s := UpperCase(s);

  for t := 1 to 20 do begin
    if s = UpperCase(XSettings.XSQuickFolder[t]) then begin
      Result := True;

      Break;
    end;
  end;
end;


class procedure TUtility.StringListClear(const strings: TStrings);
 var
  idx : integer;

 begin
  for idx := 0 to Pred(strings.Count) do begin
    strings.Objects[idx].Free;
    strings.Objects[idx] := nil;
  end;
end;


class function TUtility.FastStartsStr(const Sub, Str: string): boolean;
var
  lSub, lStr : integer;

begin
  lSub := Length(Sub);
  lStr := Length(Str);

  {$IFDEF CPUX64}
  Result := (LSub > 0) and (LSub <= LStr) and CompareMem(Pointer(Sub), Pointer(Str), LSub * 2);
  {$ELSE}
  Result := (LSub > 0) and (LSub <= LStr) and CompareMem(Pointer(Sub), Pointer(Str), LSub);
  {$ENDIF}
end;


class function TUtility.ComponentWidth(aTextWidth : integer; aMinWidth : integer): integer;
begin
  if (aTextWidth < aMinWidth) then
    Result := aMinWidth
  else
    Result := aTextWidth;
end;


end.
