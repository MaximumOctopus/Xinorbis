{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CFileObject;


interface


type
  TFileObject = class
    //FilePath       : string;
    FilePathIndex  : integer;
    FileName       : string;
    FileSize       : int64;
    FileSizeOnDisk : int64;
    FileDateC      : integer; // created
    FileDateA      : integer; // last accessed
    FileDateM      : integer; // last modified
    FileTimeC      : word;
    FileTimeA      : word;
    FileTimeM      : word;
    FileCategory   : integer;
    Attributes     : integer;
    Temp           : boolean;
    Owner          : integer; // index to users[]
  end;


  // to do, create method with defaults

implementation


end.
