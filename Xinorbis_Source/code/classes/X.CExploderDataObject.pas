{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CExploderDataObject;


interface


type
  TXExploderDataObject = class
    FolderName  : string;
    FolderID    : integer;

    FileCount   : integer;
    FileSize    : int64;

    Colour      : integer;

    PieSize     : double;
    PieQuantity : double;
  end;


implementation


end.
