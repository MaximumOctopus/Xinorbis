{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CUserData;

interface

uses
  X.Constants;


type
  TUserData = class(TObject)
  private
  public
    Name             : string;
    Data             : array[1..2] of Int64;
    CategoryDataQty  : array[1..__FileCategoriesCount] of integer;
    CategoryDataSize : array[1..__FileCategoriesCount] of Int64;

    constructor Create;
  end;


implementation


constructor TUserData.Create;
 var
  t : integer;

 begin
  Name    := '';
  Data[1] := 0;
  Data[2] := 0;

  for t := 1 to __FileCategoriesCount do begin
    CategoryDataQty[t]  := 0;
    CategoryDataSize[t] := 0;
  end;
end;


end.
