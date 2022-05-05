{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CMagnitude;


interface


uses
  X.Constants;


type
  TMagnitudeArray = array[0..__FileCategoriesCount, 0..__MagnitudesCount, 0..1] of Int64; // [0, ...] is "all" data

  TMagnitude = class
  private
   FMagnitude : array[0..__FileCategoriesCount, 0..__MagnitudesCount, 0..1] of Int64;

   function  GetMagnitude(A1, A2, A3 : integer): Int64;
   procedure SetMagnitude(A1, A2, A3 : integer; aValue : Int64);
  public
    constructor Create;

    procedure Clear;
    function  HasData(aCategory : integer): boolean;

    property  Data[A1, A2, A3 : integer] : Int64 read GetMagnitude write SetMagnitude;
  end;


implementation


constructor TMagnitude.Create;
begin
  Clear;
end;


function TMagnitude.GetMagnitude(A1, A2, A3 : integer): Int64;
begin
  Result := FMagnitude[A1, A2, A3];
end;


procedure TMagnitude.SetMagnitude(A1, A2, A3 : integer; aValue : Int64);
begin
  FMagnitude[A1, A2, A3] := aValue;
end;


procedure TMagnitude.Clear;
var
  c, m : integer;

begin
  for c:= 0 to __FileCategoriesCount do begin
    for m := 0 to __MagnitudesCount do begin
      FMagnitude[c, m, 0] := 0;
      FMagnitude[c, m, 1] := 0;
    end;
  end;
end;


function TMagnitude.HasData(aCategory : integer): boolean;
var
  m : integer;

begin
  Result := False;

  for m := 0 to __MagnitudesCount do begin
    if FMagnitude[aCategory, m, 0] > 0 then
      Result := True;
  end;
end;


end.
