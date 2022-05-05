{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.MD5;


interface


uses IdHashMessageDigest;


type
  TMD5 = class
    class function Generate(const aInput : string): string;
  end;


implementation


class function TMD5.Generate(const aInput : string):string;
var
  idmd5 : TIdHashMessageDigest5;

begin
  idmd5 := TIdHashMessageDigest5.Create;

  try
    result := idmd5.HashStringAsHex(aInput);
  finally
    idmd5.Free;
  end;
end;


end.
