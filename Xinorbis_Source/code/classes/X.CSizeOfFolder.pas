{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CSizeOfFolder;

interface


type
  TSizeOfFolder = record
                    Data : array[1..4] of int64;
                  end;


var
  CompareData                   : array[1..2] of TSizeOfFolder;


implementation

end.
