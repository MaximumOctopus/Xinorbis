{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CFolderHistoryInfo;

interface


uses
  System.Generics.Collections;


type
  TFolderHistoryInfo     = class(TObject)
  private
  public
    ScanPath     : string;
    ComputerName : string;
    MD5          : string;
  end;


var
  FolderHistoryAvailable : TObjectList<TFolderHistoryInfo>;


implementation


end.
