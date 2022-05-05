{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: April 23rd 2009
  Last Modified: January 11th 2020
}


unit X.Conversions;

interface


uses
  System.DateUtils, System.SysUtils, Windows, Graphics,

  X.Settings, X.Constants, X.CFolderHistoryInfo, X.CTableDetails, X.MD5,

  X.LanguageHandler, X.Windows, X.Global;


type
  TConvert = class
    class function  ConvertToUsefulUnit(x : Int64): string;
    class function  ConvertToStaticUnit(x : Int64; aUnit : integer): string;
    class function  ConvertUsefulUnitToInteger(const s : string): int64;
    class function  ConvertUsefulUnitToString(const s : string): string;
    class function  GetSizeOnDisk(filesize : int64): int64;
    class function  GetSizeString(gfsMode : integer; xsize : Int64): string;
    class function  MultiplyBy(value : int64; mmode : integer): string;

    class function  RealToPercent(xvalue : double): string;  // 0.0 to 1.0

    class function  DateToYYYYMMDD(const s : string): integer; overload;
    class function  DateToYYYYMMDD(dt : TDateTime): string; overload;
    class function  DateToYYYYMMDDI(dt : TDateTime): integer;
    class function  DateToYYYYMMDDF(dt : TDateTime): string;
    class function  DateTimeToInteger(dt : TDateTime): integer;
    class function  TimeToString(dt : TDateTime; separator : boolean): string;
    class function  DateTimeToTimeWord(dt : TDateTime): word;
    class function  UStoUKDate(const s : string): integer;
    class function  IntDateToString(dx : integer): string;
    class function  IntegerDateToTDate(i : integer): TDateTime;
    class function  IntegerDateToTDateTime(const s : string): TDateTime;
    class function  GetDateFormat: string;
    class function  YYYYMMDDHHMMSSToString(aDate : string): string;
    class function  StrDateToFString(const xd : string): string;
    class function  DateToString(dt : TDateTime): string;
    class function  DateTimeFToYYYYMMDD(const d : string): string;
    class function  DateTimeFToYYYYMMDDHHMMSS(const d : string): string;
    class function  TimeFromAnyFormatToHHMM(const s : string): integer;
    class function  DateFromAnyFormatToYYYYMMDD(s : string): integer;

    class function  FileDateExtToTimeStr(ft : TFileTime): word;
    class function  FileDateExtToDateStr(ft : TFileTime): integer;

    class function  HexToInt(const s : string): integer;
    class function  WebColor(Col : TColor): string;

    class function  BoolToInteger(boole : boolean): integer;
    class function  StringBoolToInteger(const s : string): boolean;

    class function  AttributeToIntAsString(AttributeData : integer; AttributeValue : integer): string;
    class function  AttributesToString(AttributeData : integer): string;

    class function  CreateTableName(const ScanDate, ScanPath, ScanComputer : string): string;
    class function  SplitTableName(const tablename : string): TTableDetails;

    class function  GetDelta(deltablues : int64): string;
    class function  GetDeltaSize(deltablues : int64): string;
  end;


var
 drivesectorsize : integer;


const
  gfsModeConvenient = 0;
  gfsModeBytes      = 1;
  gfsModeKilobytes  = 2;
  gfsModeMegabytes  = 3;
  gfsModeGigabytes  = 4;

  CThousand         = 0;
  CMillion          = 1;
  CBillion          = 2;


implementation


class function TConvert.ConvertToUsefulUnit(x : Int64): string;
 begin
  if (x < 0 ) then                      Result := '0'
  else if (x >= 0) and (x < 1024)  then Result := IntToStr(x) + ' ' + XText[rsBytes]
  else if x < (1024 * 1024)        then Result := FloatToStrF((x / 1024),                 ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitKB]
  else if x < (1024 * 1024 * 1024) then Result := FloatToStrF((x / (1024 * 1024)),        ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitMB]
  else if x < (1099511627776)      then Result := FloatToStrF((x / (1024 * 1024 * 1024)), ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitGB]
  else
    Result := FloatToStrF(x / 1099511627776, ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitTB];
end;


class function TConvert.ConvertToStaticUnit(x : Int64; aUnit : integer): string;
 begin
  Assert((aUnit >= unitKB) and (aUnit <= unitGB), 'ConvertToStaticUnit :: unit error');

  case aUnit of
    unitKB : Result := FloatToStrF((x/1024),                 ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitKB];
    unitMB : Result := FloatToStrF((x/(1024 * 1024)),        ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitMB];
    unitGB : Result := FloatToStrF((x/(1024 * 1024 * 1024)), ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitGB];
    unitTB : Result := FloatToStrF((x/(1099511627776)),      ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitTB];
  end;
end;


class function TConvert.ConvertUsefulUnitToInteger(const s : string): int64;
 var
  t : integer;
  num, unt : string;

 begin
  Assert(s <> '', 'ConvertUsefulUnitToInteger :: blank input');

  num := '0';
  unt := '';

  for t := 1 to length(s) do begin
    if (Ord(s[t]) >= 65) and (Ord(s[t]) <= 122) then
      unt := unt + Upcase(s[t])
    else
      num := num + s[t];
  end;

  num := Trim(num);

  if (Pos(XinorbisFormatSettings.DecimalSeparator, num) <> 0) then begin  // handle non integer values differently
    if unt = UpperCase(XText[rsBytes]) then
      Result := Round(StrToFloat(num))
    else if (unt = 'K') or (unt = 'KB') or (unt = UpperCase(XText[rsUnitKB])) then Result := Round(StrToFloat(num) * 1024)
    else if (unt = 'M') or (unt = 'MB') or (unt = UpperCase(XText[rsUnitMB])) then Result := Round(StrToFloat(num) * 1024 * 1024)
    else if (unt = 'G') or (unt = 'GB') or (unt = UpperCase(XText[rsUnitGB])) then Result := Round(StrToFloat(num) * 1024 * 1024 * 1024)
    else
      Result := Round(StrToFloat(num));
  end
  else begin
    if unt = UpperCase(XText[rsBytes]) then
      Result := StrToInt64(num)
    else if (unt = 'K') or (unt = 'KB') or (unt = UpperCase(XText[rsUnitKB])) then Result := StrToInt64(num) * 1024
    else if (unt = 'M') or (unt = 'MB') or (unt = UpperCase(XText[rsUnitMB])) then Result := StrToInt64(num) * 1024 * 1024
    else if (unt = 'G') or (unt = 'GB') or (unt = UpperCase(XText[rsUnitGB])) then Result := StrToInt64(num) * 1024 * 1024 * 1024
    else
      Result := StrToInt64(num);
  end;
end;


class function TConvert.ConvertUsefulUnitToString(const s : string): string;
begin
  Result := IntToStr(ConvertUsefulUnitToInteger(s));
end;


class function TConvert.GetSizeOnDisk(filesize : int64): int64;
 var
  sectorcount : double;

 begin
  if drivesectorsize <> 0 then begin
    sectorcount := filesize / drivesectorsize;

    if Frac(sectorcount) = 0 then
      Result := Trunc(sectorcount) * drivesectorsize
    else
      Result := (Trunc(sectorcount) + 1) * drivesectorsize;
  end
  else
    Result := filesize;
end;


class function TConvert.GetSizeString(gfsMode : integer; xsize : Int64): string;
 begin
  Assert((gfsMode >= 0) and (gfsMode <= 4), 'GetSizeString :: input out of bounds');

  case gfsMode of
    gfsModeConvenient : Result := TConvert.ConvertToUsefulUnit(xsize);
    gfsModeBytes      : Result := IntToStr(xsize);
    gfsModeKilobytes  : Result := FloatToStrF(xsize/1024,             ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitKB];
    gfsModeMegabytes  : Result := FloatToStrF(xsize/(1024*1024),      ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitMB];
    gfsModeGigabytes  : Result := FloatToStrF(xsize/(1024*1024*1024), ffFixed, 7, 2, XinorbisFormatSettings) + XUnit[rsUnitGB];
  else
    Result := TConvert.ConvertToUsefulUnit(xsize);
  end;
end;


class function TConvert.MultiplyBy(value : int64; mmode : integer): string;
 begin
  case mmode of
    CThousand : value := value * 1024;
    CMillion  : value := value * (1024 * 1024);
    CBillion  : value := value * (1024 * 1024 * 1024);
  end;

  Result := IntToStr(value);
end;


class function TConvert.RealToPercent(xvalue : double): string;  // 0.0 to 1.0
 begin
  if xvalue <> 0 then begin
    if (xvalue < 0.001) then
      Result := '<0.1%'
    else if (xvalue < 0.01) then
      Result := '<1%'
    else begin
      if (Round(xvalue * 100) = 100) and (xvalue < 1.0) then
        Result := '>99%'
      else
        Result := IntToStr(Round(xvalue * 100)) + '%';
    end;
  end
  else
    Result := '0%';
end;


class function TConvert.DateToYYYYMMDD(const s : string): integer;
 var
  dt : TDateTime;
  yy,mm,dd : word;

 begin
  Assert(length(s) = 10, 'DateToYYYYMMDD :: input error');

  if length(s) = 10 then begin
    try
      dt := StrToDate(s);
    except
      dt := EncodeDate(1990, 01, 01);
    end;

    DecodeDate(dt, yy, mm, dd);

    Result := (yy * 10000) + (mm * 100) + dd;
  end
  else
    Result := 19900101;
end;


class function TConvert.DateToYYYYMMDDI(dt : TDateTime): integer;
 var
  yy,mm,dd : word;

 begin
  DecodeDate(dt, yy, mm, dd);

  Result := (yy * 10000) + (mm * 100) + dd;
end;


class function TConvert.DateToYYYYMMDD(dt : TDateTime): string;
 var
  yy,mm,dd : word;

 begin
  DecodeDate(dt, yy, mm, dd);

  Result := IntToStr((yy * 10000) + (mm * 100) + dd);
end;


class function TConvert.DateToYYYYMMDDF(dt : TDateTime): string;
 var
  yy,mm,dd : word;
  s : string;

 begin
  DecodeDate(dt, yy,mm,dd);

  s := IntToStr(yy);

  s := s + '/';

  if mm < 10 then
    s := s + '0' + IntToStr(mm)
  else
    s := s + IntToStr(mm);

  s := s + '/';

  if dd < 10 then
    s := s + '0' + IntToStr(dd)
  else
    s := s + IntToStr(dd);

  Result := s;
end;


class function TConvert.DateTimeToInteger(dt : TDateTime): integer;
 var
  dd,mm,yyyy : word;

 begin
  DecodeDate(dt, yyyy, mm, dd);

  Result := (yyyy * 10000) + (mm * 100) + dd;
end;


class function TConvert.TimeToString(dt : TDateTime; separator : boolean): string;
 var
  hh,mm,ss,sss : word;
  s : string;

 begin
  DecodeTime(dt, hh, mm, ss, sss);

  s := '';

  if hh < 10 then
    s := '0' + IntToStr(hh)
  else
    s := s + IntToStr(hh);

  if separator then
    s := s + ':';

  if mm < 10 then
    s := s + '0' + IntToStr(mm)
  else
    s := s + IntToStr(mm);

  Result := s;
end;


class function TConvert.DateTimeToTimeWord(dt : TDateTime): word;
 var
  hh,mm,ss,sss : word;

 begin
  DecodeTime(dt, hh, mm, ss, sss);

  Result := (hh * 100) + mm;
end;


class function TConvert.UStoUKDate(const s : string): integer;
 begin
  Assert(length(s) = 10, 'UStoUKDate :: input error');

  if length(s) = 10 then
    Result := StrToIntDef(s[7] + s[8] + s[9] + s[10] + s[1] + s[2] + s[4] + s[5], DateToYYYYMMDDI(Now))
  else
    Result := StrToIntDef(DateToYYYYMMDD(Now), 19900101);
end;


class function TConvert.FileDateExtToTimeStr(ft : TFileTime): word;
 var
  dt : TFileTime;
  st : TSystemTime;

 begin
  if (ft.dwLowDateTime <> 0) and (ft.dwHighDateTime <> 0) then begin
    FileTimeToLocalFileTime(ft, dt);
    FileTimeToSystemTime(dt,st);

    Result := (st.wHour * 100) + st.wMinute;
  end
  else
    Result := 1200;
end;


class function TConvert.FileDateExtToDateStr(ft : TFileTime): integer;
 var
  dt : TFileTime;
  st : TSystemTime;

 begin
  if (ft.dwLowDateTime <> 0) and (ft.dwHighDateTime <> 0) then begin
    FileTimeToLocalFileTime(ft, dt);
    FileTimeToSystemTime(dt,st);

    Result := (st.wYear * 10000) + (st.wMonth * 100) + st.wDay;
  end
  else
    Result := 19900101;
end;


class function TConvert.IntDateToString(dx : integer): string;
 var
  xd : string;

 begin
  Assert(length(IntToStr(dx))=8, 'IntDateToString :: input error :: ' + IntToStr(length(IntToStr(dx))));

  xd := IntToStr(dx);

  case XSettings.General.DateFormat of
    CDateFormatSlashDDMMYYYY  : Result := xd[7] + xd[8] + '/' + xd[5] + xd[6] + '/' + xd[1] + xd[2] + xd[3] + xd[4];   // dd/mm/yyyy
    CDateFormatSlashMMDDYYYY  : Result := xd[5] + xd[6] + '/' + xd[7] + xd[8] + '/' + xd[1] + xd[2] + xd[3] + xd[4];   // mm/dd/yyyy
    CDateFormatSlashYYYYMMDD  : Result := xd[1] + xd[2] + xd[3] + xd[4] + '/' + xd[5] + xd[6] + '/' + xd[7] + xd[8];   // yyyy/mm/dd
    CDateFormatHyphenDDMMYYYY : Result := xd[7] + xd[8] + '-' + xd[5] + xd[6] + '-' + xd[1] + xd[2] + xd[3] + xd[4];   // dd-mm-yyyy
    CDateFormatHyphenMMDDYYYY : Result := xd[5] + xd[6] + '-' + xd[7] + xd[8] + '-' + xd[1] + xd[2] + xd[3] + xd[4];   // mm-dd-yyyy
  end;
end;


class function TConvert.GetDateFormat: string;
begin
  case XSettings.General.DateFormat of
    CDateFormatSlashDDMMYYYY  : Result := 'dd/mm/yyyy';
    CDateFormatSlashMMDDYYYY  : Result := 'mm/dd/yyyy';
    CDateFormatSlashYYYYMMDD  : Result := 'yyyy/mm/dd';
    CDateFormatHyphenDDMMYYYY : Result := 'dd-mm-yyyy';
    CDateFormatHyphenMMDDYYYY : Result := 'mm-dd-yyyy';
  end;
end;


class function TConvert.YYYYMMDDHHMMSSToString(aDate : string): string;
begin
  Result := IntDateToString(StrToInt(Copy(aDate, 1, 8)));

  Result := Result + ' ' + aDate[9] + aDate[10] + ':' + aDate[11] + aDate[12] + '.' + aDate[13] + aDate[14];
end;


class function TConvert.IntegerDateToTDate(i : integer): TDateTime;
 var
  s : string;
  yyyy,mm,dd : integer;

 begin
  Assert(length(IntToStr(i)) = 8, 'IntegerDateToTDate :: input error');

  s := IntToStr(i);

  yyyy := StrToIntDef(Copy(s, 1, 4), 1975);
  mm   := StrToIntDef(Copy(s, 5, 2),    4);
  dd   := StrToIntDef(Copy(s, 7, 2),   17);

  Result := EncodeDate(yyyy, mm, dd);
end;


class function TConvert.IntegerDateToTDateTime(const s : string): TDateTime;
var
  yyyy, mm, dd, hh, nn, ss : integer;

begin
  Assert(length(s) = 14, 'IntegerDateToTDateTime :: input error');

  yyyy := StrToIntDef(Copy(s, 1, 4), 1975);
  mm   := StrToIntDef(Copy(s, 5, 2),    4);
  dd   := StrToIntDef(Copy(s, 7, 2),   17);

  hh   := StrToIntDef(copy(s,  9, 2),   0);
  nn   := StrToIntDef(copy(s, 11, 2),   0);
  ss   := StrToIntDef(copy(s, 13, 2),   0);

  Result := EncodeDate(yyyy, mm, dd);

  Result := RecodeTime(Result, hh, nn, ss, 0);
end;


class function TConvert.StrDateToFString(const xd : string): string;
 begin
  Assert(length(xd)=8, 'StrDateToFString :: input error');

  case XSettings.General.DateFormat of
    CDateFormatSlashDDMMYYYY  : Result := xd[7] + xd[8] + '/' + xd[5] + xd[6] + '/' + xd[1] + xd[2] + xd[3] + xd[4];   // dd/mm/yyyy
    CDateFormatSlashMMDDYYYY  : Result := xd[5] + xd[6] + '/' + xd[7] + xd[8] + '/' + xd[1] + xd[2] + xd[3] + xd[4];   // mm/dd/yyyy
    CDateFormatSlashYYYYMMDD  : Result := xd[1] + xd[2] + xd[3] + xd[4] + '/' + xd[5] + xd[6] + '/' + xd[7] + xd[8];   // yyyy/mm/dd
    CDateFormatHyphenDDMMYYYY : Result := xd[7] + xd[8] + '-' + xd[5] + xd[6] + '-' + xd[1] + xd[2] + xd[3] + xd[4];   // dd-mm-yyyy
    CDateFormatHyphenMMDDYYYY : Result := xd[5] + xd[6] + '-' + xd[7] + xd[8] + '-' + xd[1] + xd[2] + xd[3] + xd[4];   // mm-dd-yyyy
  end;
end;


class function TConvert.DateToString(dt : TDateTime): string;
 var
  yy,mm,dd : word;
  xd : string;

 begin
  DecodeDate(dt, yy, mm, dd);

  xd := IntToStr(yy);
  if mm < 10 then
    xd := xd + '0' + IntToStr(mm)
  else
    xd := xd + IntToStr(mm);

  if dd < 10 then
    xd := xd + '0' + IntToStr(dd)
  else
    xd := xd + IntToStr(dd);

  case XSettings.General.DateFormat of
    CDateFormatSlashDDMMYYYY  : Result := xd[7] + xd[8] + '/' + xd[5] + xd[6] + '/' + xd[1] + xd[2] + xd[3] + xd[4];   // dd/mm/yyyy
    CDateFormatSlashMMDDYYYY  : Result := xd[5] + xd[6] + '/' + xd[7] + xd[8] + '/' + xd[1] + xd[2] + xd[3] + xd[4];   // mm/dd/yyyy
    CDateFormatSlashYYYYMMDD  : Result := xd[1] + xd[2] + xd[3] + xd[4] + '/' + xd[5] + xd[6] + '/' + xd[7] + xd[8];   // yyyy/mm/dd
    CDateFormatHyphenDDMMYYYY : Result := xd[7] + xd[8] + '-' + xd[5] + xd[6] + '-' + xd[1] + xd[2] + xd[3] + xd[4];   // dd-mm-yyyy
    CDateFormatHyphenMMDDYYYY : Result := xd[5] + xd[6] + '-' + xd[7] + xd[8] + '-' + xd[1] + xd[2] + xd[3] + xd[4];   // mm-dd-yyyy
  end;
end;


class function TConvert.DateTimeFToYYYYMMDD(const d : string): string;
 begin
  Assert(length(d) = 19, 'DateTimeFToYYYYMMDD :: input error');                   // ?

  case XSettings.General.DateFormat of
    CDateFormatSlashDDMMYYYY  : Result := d[07] + d[08] + d[09] + d[10] + d[04] + d[05] + d[01] + d[02]; // dd/mm/yyyy hh:mm:ss -> yyyymmdd
    CDateFormatSlashMMDDYYYY  : Result := d[07] + d[08] + d[09] + d[10] + d[01] + d[02] + d[04] + d[05]; // mm/dd/yyyy hh:mm:ss -> yyyymmdd
    CDateFormatSlashYYYYMMDD  : Result := d[01] + d[02] + d[03] + d[04] + d[06] + d[07] + d[09] + d[10]; // yyyy/mm/dd hh:mm:ss -> yyyymmdd
    CDateFormatHyphenDDMMYYYY : Result := d[07] + d[08] + d[09] + d[10] + d[04] + d[05] + d[01] + d[02]; // dd-mm-yyyy hh:mm:ss -> yyyymmdd
    CDateFormatHyphenMMDDYYYY : Result := d[07] + d[08] + d[09] + d[10] + d[01] + d[02] + d[04] + d[05]; // mm-dd-yyyy hh:mm:ss -> yyyymmdd
  end;
end;


class function TConvert.DateTimeFToYYYYMMDDHHMMSS(const d : string): string;
 begin
  Assert(length(d) = 19, 'DateTimeFToYYYYMMDDHHMMSS :: input error');

  case XSettings.General.DateFormat of
    CDateFormatSlashDDMMYYYY  : Result := d[07] + d[08] + d[09] + d[10] + d[04] + d[05] + d[01] + d[02] + d[12] + d[13] + d[15] + d[16] + d[18] + d[19]; // dd/mm/yyyy hh:mm:ss -> yyyymmddhhmmss
    CDateFormatSlashMMDDYYYY  : Result := d[07] + d[08] + d[09] + d[10] + d[01] + d[02] + d[04] + d[05] + d[12] + d[13] + d[15] + d[16] + d[18] + d[19]; // mm/dd/yyyy hh:mm:ss -> yyyymmddhhmmss
    CDateFormatSlashYYYYMMDD  : Result := d[01] + d[02] + d[03] + d[04] + d[06] + d[07] + d[09] + d[10] + d[12] + d[13] + d[15] + d[16] + d[18] + d[19]; // yyyy/mm/dd hh:mm:ss -> yyyymmddhhmmss
    CDateFormatHyphenDDMMYYYY : Result := d[07] + d[08] + d[09] + d[10] + d[04] + d[05] + d[01] + d[02] + d[12] + d[13] + d[15] + d[16] + d[18] + d[19]; // dd-mm-yyyy hh:mm:ss -> yyyymmddhhmmss
    CDateFormatHyphenMMDDYYYY : Result := d[07] + d[08] + d[09] + d[10] + d[01] + d[02] + d[04] + d[05] + d[12] + d[13] + d[15] + d[16] + d[18] + d[19]; // mm-dd-yyyy hh:mm:ss -> yyyymmddhhmmss
  end;
end;


class function TConvert.TimeFromAnyFormatToHHMM(const s : string): integer;
 begin
  Result := StrToIntDef(s, 1200);
end;


class function TConvert.DateFromAnyFormatToYYYYMMDD(s : string): integer;
 var
  t : integer;
  hastext : boolean;
  num : string;

 begin
  if Pos('!', s) = 1 then begin                // !x where x is number of days
    t := StrToIntDef(Copy(s, 2, length(s) - 1), 0);

    Result := StrToInt(TConvert.DateToYYYYMMDD(IncDay(Now, -t)));
  end
  else if Pos('$', s) = 1 then begin           // $x where x is number of months
    t:= StrToIntDef(Copy(s, 2, length(s) - 1), 0);

    Result := StrToInt(TConvert.DateToYYYYMMDD(IncMonth(Now, -t)));
  end
  else begin
    hastext := False;

    s := StringReplace(s, '\', '*', [rfReplaceAll]);
    s := StringReplace(s, '/', '*', [rfReplaceAll]);
    s := UpperCase(s);

    for t := 1 to length(s) do
      if (Ord(s[t]) >= 65) and (Ord(s[t]) <= 90) then hastext := True;

    // if the user has entered the month as text the replace the text with
    // the correct ordinal month value
    if hastext then begin
      for t := 1 to 12 do begin
        if Pos(UpperCase(shortmonths[t]), s) <> 0 then begin
          if t < 10 then
            num := '0' + IntToStr(t)
          else
            num := IntToStr(t);

          s:= StringReplace(s, UpperCase(shortmonths[t]), num, [rfReplaceAll]);
        end;
      end;
    end;

    // ===========================================================================

    if Pos('*', s) = 3 then begin             // dd/mm/yyyy
      if XSettings.General.DateFormat = CDateFormatSlashMMDDYYYY then  // assume the user is entering in mm/dd/yyyy
        Result := StrToIntDef(Copy(s, 7, 4) + Copy(s, 1, 2) + Copy(s, 4, 2), 19900101)
      else
        Result := TConvert.DateToYYYYMMDD(s);
    end
    else if pos('*', s) = 5 then begin        // yyyy/mm/dd
      Result := StrToIntDef(Copy(s, 1, 4) + Copy(s, 6, 2) + Copy(s, 9, 2), 19900101);
    end
    else begin                                // yyyymmdd
      Result := StrToIntDef(s, 19900101);
    end;
  end;
end;


class function TConvert.HexToInt(const s : string): integer;
var
  lValue : integer;

begin
  if TryStrToInt('$' + s, lValue) then
    Result := lValue
  else
    Result := 0;
end;


class function TConvert.WebColor(Col : TColor): string;
 var
  zz,tt : string;

 begin
  zz := IntToHex(Col, 6);
  tt := zz;

  zz[1] := tt[5];
  zz[2] := tt[6];
  zz[5] := tt[1];
  zz[6] := tt[2];

  Result := zz;
end;


class function TConvert.BoolToInteger(boole : boolean): integer;
 begin
  if boole then
    Result := 1
  else
    Result := 0;
end;


class function TConvert.StringBoolToInteger(const s : string): boolean;
 begin
  if s = '1' then
    Result := True
  else
    Result := False;
end;


class function TConvert.AttributeToIntAsString(AttributeData : integer; AttributeValue : integer): string;
 begin
  if (AttributeValue and AttributeData) = AttributeValue then
    Result := '1'
  else
    Result := '0';
end;


class function TConvert.AttributesToString(AttributeData : integer): string;
begin
  Result := '----';

  if ((faArchive and AttributeData)  = faArchive) then  Result[1] := 'A';
  if ((faReadOnly and AttributeData) = faReadOnly) then Result[2] := 'R';
  if ((faSysFile and AttributeData)  = faSysFile) then  Result[3] := 'S';
  if ((faHidden and AttributeData)   = faHidden) then   Result[4] := 'H';
end;


// scandate must be in "YYYYMMDDHHMMSS" format
class function TConvert.CreateTableName(const ScanDate, ScanPath, ScanComputer : string): string;
 begin
  Result := TMD5.Generate(UpperCase(ScanPath)) + ScanDate + ScanComputer;
end;


class function TConvert.SplitTableName(const tablename : string): TTableDetails;
 var
  s : string;
  t,i : integer;

 begin
  s := Copy(tablename, 1, 32);

  i := -1;
  for t := 0 to FolderHistoryAvailable.Count - 1 do begin
    if Copy(FolderHistoryAvailable[t].MD5, 1, 32) = s then
      i := t;
  end;

  if i <> -1 then
    Result.Path := FolderHistoryAvailable[i].ScanPath
  else
    Result.Path := XText[rsUnknown];

  Result.Date := Copy(tablename, 33, 8);
  Result.Time := Copy(tablename, 41, 6);

  Result.DateYYYYMMDD := Copy(tablename, 33, 4) + '/' + Copy(tablename, 37, 2) + '/' + Copy(tablename, 39, 2);
  Result.TimeHHMMSS   := Copy(tablename, 41, 2) + ':' + Copy(tablename, 43, 2) + '.' + Copy(tablename, 45, 2);

  Result.Computer := Copy(tablename, 47, Length(tablename) - 46);
end;


class function TConvert.GetDelta(deltablues : int64): string;
 begin
  if deltablues = 0 then
    Result := '0'
  else if deltablues < 0 then
    Result := IntToStr(deltablues)
  else if deltablues > 0 then
    Result := '+' + IntToStr(deltablues);
end;


class function TConvert.GetDeltaSize(deltablues : int64): string;
 begin
  if deltablues = 0 then
    Result := '0'
  else if deltablues < 0 then
    Result := TConvert.ConvertToUsefulUnit(deltablues)
  else if deltablues > 0 then
    Result := '+' + TConvert.ConvertToUsefulUnit(deltablues);
end;


end.
