{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Formatting;

interface


uses
  System.SysUtils,

  X.Settings;


type
  TXFormatting = class
    class function  AddTrailing(const instr : string; len : integer; fillchar : char): string;
    class function  AddLeading(const instr : string; len : integer; fillchar : char): string;
    class function  FilterTags(aInput : string): string;
    class function  GetAttributesAsString(aAttributes : integer): string;
    class function  InsertElement(const name, contents : string; level : integer): string;
    class function  MakeFilenameCompatible(const s : string): string;
    class function  MakeItalic(aInput : string; aCondition : boolean): string;
    class function  Privacy(const s : string): string;
    class function  ReplaceEntities(aInput : string): string;
    class function  ReplaceEntitiesForXML(const s : string): string;
    class function  StringOfChars(len : integer; fillchar : char): string;
  end;


implementation


class function TXFormatting.AddTrailing(const instr : string; len : integer; fillchar : char): string;
 var
  s : string;
  t : integer;

 begin
  if Length(instr) <= len then begin
    s := instr;

    for t := Length(instr) + 1 to len do
      s := s + fillchar;
  end
  else begin
    s := '';

    for t := 1 to len - 3 do
      s := s + instr[t];

    s := s + '...';
  end;

  Result := s;
end;


class function TXFormatting.AddLeading(const instr : string; len : integer; fillchar : char): string;
 var
  t : integer;

 begin
  Result := instr;

  for t := length(instr) to len do
    Result := fillchar + Result;
end;


class function TXFormatting.FilterTags(aInput : string): string;
begin
  Result := StringReplace(aInput, '<b>',  '', [rfReplaceAll]);
  Result := StringReplace(Result, '</b>', '', [rfReplaceAll]);
  Result := StringReplace(Result, '<i>',  '', [rfReplaceAll]);
  Result := StringReplace(Result, '</i>', '', [rfReplaceAll]);
end;


class function TXFormatting.GetAttributesAsString(aAttributes : integer): string;
 begin
  Result := '....';

  if (faArchive and aAttributes)  = faArchive then  Result[1] := 'A';
  if (faReadOnly and aAttributes) = faReadOnly then Result[2] := 'R';
  if (faSysFile and aAttributes)  = faSysFile then  Result[3] := 'S';
  if (faHidden and aAttributes)   = faHidden then   Result[4] := 'H';
end;


class function TXFormatting.InsertElement(const name, contents : string; level : integer): string;
 var
  indent : string;
  t : integer;

 begin
  indent := '';

  if level <> 0 then
    for t := 1 to level do
      indent := indent + '  ';

  Result := indent + '<' + name + '>' + contents + '</' + name + '>';
end;


class function TXFormatting.MakeFilenameCompatible(const s : string): string;
 var
  t,idx : integer;
  ret, ts : string;

 begin
  Assert(s <> '', 'MakeFilenameCompatible :: blank input');

  if pos('\\', s) = 1 then begin            // network paths
    ret := StringReplace(s,   '\\', '__', [rfReplaceAll]);
    ret := StringReplace(ret, '\',  '_',  [rfReplaceAll]);

    if (ret[length(ret)] = '\') then
      ret := Copy(ret, 1, length(ret) - 1); // remove trailing "\" slash
  end
  else begin
    if (length(s) <> 0) then begin
      ret := S[1]; // get drive letter

      // now get the last folder name
      idx := -1;
      for t := 1 to length(s) - 1 do begin
        if s[t] = '\' then idx := t;
      end;

      if idx <> -1 then begin
        ts := '';

        for t := idx + 1 to length(s) - 1 do
          ts := ts + s[t];

        ret := ret + '_' + ts;
      end;
    end
    else
      ret := s;
  end;

  Result := ret;
end;


class function TXFormatting.MakeItalic(aInput : string; aCondition : boolean): string;
begin
  if aCondition then
    Result := '<i>' + aInput + '</i>'
  else
    Result := aInput;
end;


class function TXFormatting.Privacy(const s : string): string;
 var
  t : integer;

 begin
  if XSettings.Database.PrivacyActive then begin
    Result := s;

    for t := 1 to length(s) do
      if Result[t] <> '\' then
        Result[t] := 'x';
  end
  else
    Result := s;
end;


class function TXFormatting.ReplaceEntities(aInput : string): string;
begin
  Result := StringReplace(aInput, '<',  '&lt;', [rfReplaceAll]);
end;


class function TXFormatting.ReplaceEntitiesForXML(const s : string): string;
 begin
  Result := StringReplace(s, '&', '&amp;', [rfReplaceAll]);
  Result := StringReplace(Result, '<',  '&lt;', [rfReplaceAll]);
end;


class function TXFormatting.StringOfChars(len : integer; fillchar : char): string;
 var
  t : integer;

 begin
  Result := '';

  for t:= 1 to len do
    Result := Result + fillchar;
end;


end.
