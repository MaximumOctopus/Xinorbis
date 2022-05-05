//
// (c) Paul Alan Freshney 2019
//
// Utility for Xinorbis
//
// Last Modified: January 16th 2019
//
// 3466

unit X.PurchaseUtility;

interface

uses
  Windows, Messages, System.SysUtils, Graphics, classes, Contnrs, comctrls,

  X.Settings, X.Global, X.MD5,

  X.CSearchCriteriaObject, X.Constants, X.SystemGlobal;

type
  TPurchaseUtility = class
  public
    class function  HasPurchased: boolean;
    class function  CheckActivationCode(eName, aEmail, aCode : string): boolean;
    class function  IsActivated: boolean;
  end;


implementation


class function TPurchaseUtility.HasPurchased: boolean;
 var
  tf : TextFile;
  s : string;

 begin
  if FileExists(GSystemGlobal.AppDataPath + 'registration.data') then begin
    AssignFile(tf, GSystemGlobal.AppDataPath + 'registration.data');
    Reset(tf);

    readln(tf, s);
    XSettings.System.ActivatedEmail := s;

    readln(tf, s);
    XSettings.System.ActivatedCode := s;

    CloseFile(tf);

    if CheckActivationCode(XSettings.System.ActivatedName, XSettings.System.ActivatedEmail, XSettings.System.ActivatedCode) then
      Result := True
    else
      Result := False;
  end
  else
    Result := False;
end;


class function TPurchaseUtility.CheckActivationCode(eName, aEmail, aCode : string): boolean;
 var
  xcode, ycode, zcode : string;
  t : integer;

 begin
  xcode := TMD5.Generate(UpperCase(aEmail));
  ycode := TMD5.Generate(LowerCase(eName));

  zcode := ycode;

  for t := 1 to 32 do begin
    zcode[t] := Chr(65 + ((Ord(xcode[t]) + Ord(ycode[t])) mod 26));
  end;

  if zcode = aCode then
    Result := True
  else
    Result := False;
end;


class function TPurchaseUtility.IsActivated: boolean;
var
//  tf : TextFile;
  lName, lEmail, lCode : string;

begin
  Result := True;

  lName  := 'CATSAREAWESOME';
  lEmail := 'CATSAREAWESOME';
  lCode  := 'FGEJVQWHDKNOQSGWCVCTPOMBGQZUVQOQ';

  {if FileExists(GSystemGlobal.UsersPath + 'registration.data') then begin
    AssignFile(tf, GSystemGlobal.UsersPath + 'registration.data');
    Reset(tf);

    Readln(tf, lName);
    Readln(tf, lEmail);
    Readln(tf, lCode);

    CloseFile(tf);

    Result := CheckActivationCode(lName, lEmail, lCode);
  end;}
end;


end.
