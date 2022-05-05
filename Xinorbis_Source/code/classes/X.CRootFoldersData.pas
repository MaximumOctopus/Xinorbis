{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CRootFoldersData;

interface

type
  TRootFoldersData  = class(TObject)
  private
  public
    Name       : string;

    Attributes : integer;
    Data       : array[0..1] of Int64;     // 0-count, 1-size
  end;


implementation


end.
