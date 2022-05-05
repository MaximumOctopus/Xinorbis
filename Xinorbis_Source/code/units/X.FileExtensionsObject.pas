{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: March 28th 2016
  Last Modified: January 11th 2020
}


unit X.FileExtensionsObject;

interface


uses
  SysUtils, registry, Windows, Classes, System.Contnrs, System.Generics.Collections,

  TMSLogging,

  X.Dialogs.Dialog,

  X.Global, X.LanguageHandler, X.FileExtension, X.Constants, X.SystemGlobal;


type
  TFileExtensionsObject = class
  private
    FFileExtensionDescriptions : TStringList;
  public
    CategoryExtensions : TObjectList<TFileExtension>;

    constructor Create;
    destructor  Destroy; override;

    function  LoadDefaultFileExtensions: boolean;
    function  LoadFileExtensionLists(aSettingsSaveLocation : boolean): boolean;

    function  RemoveExtension(const s : string): string;
    function  SaveFileExtensionLists(aSaveMode : boolean): boolean;

    function GetExtensionCategoryIDFromName(const fn : string): integer;
    function GetExtensionCategoryID(const aExtension : string): TExtensionExistsIn;

    function LoadFileExtensionDescriptions(aFileName : string): boolean;

    property FileExtensionDescriptions : TStringList read FFileExtensionDescriptions;
  end;


var
  FileExtensionsObject      : TFileExtensionsObject;



implementation


constructor TFileExtensionsObject.Create;
 begin
  inherited create;

  CategoryExtensions         := TObjectList<TFileExtension>.Create;
  FFileExtensionDescriptions := TStringList.Create;
end;


destructor TFileExtensionsObject.Destroy;
begin
  FreeAndNil(CategoryExtensions);
  FreeAndNil(FFileExtensionDescriptions);

  inherited;
end;


function TFileExtensionsObject.RemoveExtension(const s : string): string;
 var
  i,x : integer;
  ts : string;

 begin
  Assert(s <> '', 'RemoveExtension :: blank input');

  i := Pos('.', s);

  if i <> 0 then begin
    ts := '';

    for x := 1 to i - 1 do
      ts := ts + s[x];
  end
  else
    ts := s;

  Result := ts;
end;


function TFileExtensionsObject.SaveFileExtensionLists(aSaveMode : boolean): boolean;
 var
  t,z,x,i : integer;
  Reg : TRegistry;
  tf : TextFile;

 begin
  Result := True;

  if aSaveMode = SaveLocationRegistry then begin

    Reg := TRegistry.Create(KEY_WRITE);
    try
      Reg.RootKey := HKEY_CURRENT_USER;

      for z := 0 to __FileCategoriesCount do begin
        Reg.OpenKey('\software\' + XinorbisRegistryKey + '\FileExt' + IntToStr(z), True);

        t := 1;

        for i := 0 to CategoryExtensions.Count - 1 do begin
          if CategoryExtensions[i].Category = z then begin
            Reg.WriteString('Ext' + IntToStr(t), CategoryExtensions[i].Name);

            inc(t);
          end;
        end;

        // remove any keys that shouldn't be there as they've been deleted / re-organised -------
        for x := t to 300 do begin
          Reg.DeleteValue('Ext' + IntToStr(x));
        end;
        // --------------------------------------------------------------------------------------
      end
    finally
      Reg.Free;
    end;

    Reg := TRegistry.Create(KEY_WRITE);
    try
      Reg.RootKey := HKEY_CURRENT_USER;
      Reg.OpenKey('\software\' + XinorbisRegistryKey + '\ChartColours', True);

      for t := 1 to __FileCategoriesCount do
        Reg.WriteInteger('ChartColour' + IntToStr(t), GSystemGlobal.FileCategoryColors[t]);
    finally
      Reg.Free;
    end;
  end
  else begin
    for z := 0 to __FileCategoriesCount do begin

      AssignFile(tf, GSystemGlobal.ExePath + 'data\' + defaultextfn[z] + '.txt');

      {$I-}
      Rewrite(tf);

      if IOResult <> 0 then begin
        Result := False;

        TMSLogger.Error('Error saving "' + GSystemGlobal.ExePath + 'data\' + defaultextfn[z] + '.txt".');
      end
      else begin
        for i := 0 to CategoryExtensions.Count - 1 do begin
          if CategoryExtensions[i].Category = z then
            Writeln(tf, CategoryExtensions[i].Name);
        end;

        CloseFile(tf);
      end;
      {$I+}
    end;
  end;
end;

function TFileExtensionsObject.LoadDefaultFileExtensions: boolean;
 var
  tf : TextFile;
  t : integer;
  s : string;
  tfx : TFileExtension;

 begin
  Result := True;

  CategoryExtensions.Clear;

  for t := 0 to __FileCategoriesCount do begin
    if t <> __FileCategoriesOther then begin
      if FileExists(GSystemGlobal.ExePath + 'data\system\DefaultExtensions\' + defaultextfn[t] + '.txt') then begin
        AssignFile(tf, GSystemGlobal.ExePath + 'data\system\DefaultExtensions\' + defaultextfn[t] + '.txt');
        {$I-}
        Reset(tf);

        if IOResult <> 0 then begin
          Result := False;

          TMSLogger.Error('Default FileExtension failed "' + GSystemGlobal.ExePath + 'data\system\DefaultExtensions\' + defaultextfn[t] + '.txt' + '".');
        end
        else begin
          while not(eof(tf)) do begin
            readln(tf, s);

            if (s <> '') then begin
              tfx := TFileExtension.Create;
              tfx.Name     := s;
              tfx.Category := t;
              CategoryExtensions.Add(tfx);
            end;
          end;

          CloseFile(tf);
        end;
        {$I+}
      end
      else
        TMSLogger.Error('Default FileExtension list missing "' + GSystemGlobal.ExePath + 'data\system\DefaultExtensions\' + defaultextfn[t] + '.txt' + '".');
    end;
  end;
end;


function TFileExtensionsObject.LoadFileExtensionLists(aSettingsSaveLocation : boolean): boolean;
 var
  z,t : integer;
  Reg : TRegistry;
  InputChecker : TStringList;
  tf : TextFile;
  s,fn : string;
  tfx : TFileExtension;

 begin
  Result := True;

  CategoryExtensions.Clear;

  InputChecker := TStringList.Create;
  InputChecker.Sorted := True;

  if (aSettingsSaveLocation = SaveLocationConfigIni) then begin
    for t := 0 to __FileCategoriesCount do begin
      InputChecker.Clear;

      if t <> __FileCategoriesOther then begin
        fn := GSystemGlobal.ExePath + 'data\' + defaultextfn[t] + '.txt';

        if not(FileExists(GSystemGlobal.ExePath + 'data\' + defaultextfn[t] + '.txt')) then
          fn := GSystemGlobal.ExePath + 'data\system\DefaultExtensions\' + defaultextfn[t] + '.txt';

        if FileExists(fn) then begin
          AssignFile(tf, fn);

          {$I-}
          Reset(tf);

          if IOResult <> 0 then begin
            Result := False;

            TMSLogger.Error('FileExtension list failed "' + GSystemGlobal.ExePath + 'data\system\DefaultExtensions\' + defaultextfn[t] + '.txt' + '".');
          end
          else begin
            while not(eof(tf)) do begin
              readln(tf, s);

              if (s <> '') then begin
                if InputChecker.IndexOf(s) = -1 then begin
                  tfx := TFileExtension.Create;
                  tfx.Name     := s;
                  tfx.Category := t;
                  CategoryExtensions.Add(tfx);

                  InputChecker.Add(s);
                end;
              end;
            end;

            CloseFile(tf);
          end;

          {$I+}
        end
        else
          TMSLogger.Error('FileExtension list missing "' + fn + '".');
      end;
    end;
  end
  else begin
    Reg := TRegistry.Create(KEY_READ);
    try
      Reg.RootKey := HKEY_CURRENT_USER;

      for z := 0 to __FileCategoriesCount do begin
        InputChecker.Clear;

        if Reg.OpenKey('\software\' + XinorbisRegistryKey + '\FileExt' + IntToStr(z), False) then begin

          t := 1;
          while Reg.ValueExists('Ext' + IntToStr(t)) do begin
            if InputChecker.IndexOf(Reg.ReadString('Ext' + IntToStr(t)))= -1 then begin
              tfx := TFileExtension.Create;
              tfx.Name     := Reg.ReadString('Ext' + IntToStr(t));;
              tfx.Category := z;

              CategoryExtensions.Add(tfx);

              InputChecker.Add(Reg.ReadString('Ext' + IntToStr(t)));
            end;

            inc(t);
          end;
        end;
      end;

      if CategoryExtensions.Count = 0 then begin
        LoadDefaultFileExtensions;

        SaveFileExtensionLists(aSettingsSaveLocation);
      end;
    finally
      Reg.Free;
    end;
  end;

  InputChecker.Free;
end;


function TFileExtensionsObject.GetExtensionCategoryIDFromName(const fn : string): integer;
var
  ext : string;

begin
  ext    := LowerCase(ExtractFileExt(fn));
  ext    := Copy(ext, 2, length(ext) - 1);

  Result := GetExtensionCategoryID(ext).RawCategory;
end;


function TFileExtensionsObject.GetExtensionCategoryID(const aExtension : string): TExtensionExistsIn;
var
  z : integer;

begin
  Result.NotFound    := False;
  Result.RawCategory := -1;
  z                  := 0;

  while (Result.RawCategory = -1) and (z < CategoryExtensions.Count) do begin
    if aExtension = CategoryExtensions[z].Name then begin
      Result.RawCategory := CategoryExtensions[z].Category;
    end;

    inc(z);
  end;

  if Result.RawCategory = -1 then begin
    Result.NotFound    := True;
    Result.RawCategory := __FileCategoriesOther;
  end;
end;


function TFileExtensionsObject.LoadFileExtensionDescriptions(aFileName : string): boolean;
var
  tf : TextFile;
  s : string;
  t : integer;

begin
  Result := True;

  if FileExists(aFileName) then begin
    AssignFile(tf, aFileName);
    {$I-}
    Reset(tf);

    if IOResult <> 0 then begin
      Result := False;
    end
    else begin
      while not(eof(tf)) do begin
        readln(tf, s);

        t := 1;

        while s[t] <> ' ' do begin
          s[t] := UpCase(s[t]);

          inc(t);
        end;

        FFileExtensionDescriptions.Add(s);
      end;

      CloseFile(tf);
    end;
    {$I+}
  end;
end;


end.
