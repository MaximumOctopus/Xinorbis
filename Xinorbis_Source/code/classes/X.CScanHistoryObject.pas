{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}

unit X.CScanHistoryObject;

interface

uses
  System.Generics.Collections;


type
  TScanHistoryObject = class(TObject)
  private
  public
    DateI          : integer; // yyyymmdd
    TimeI          : string;  // hh:mm
    Path           : string;
    ExcludeFiles   : string;
    ExcludeFolders : string;
  end;


var
 ScanHistory : TObjectList<TScanHistoryObject>;


procedure AddToScanHistory(aPath : string; aDateI : integer; aTimeI, aExcludeFiles, aExcludeFolders : string);


implementation


procedure AddToScanHistory(aPath : string; aDateI : integer; aTimeI, aExcludeFiles, aExcludeFolders : string);
var
  tsho : TScanHistoryObject;

begin
  tsho := TScanHistoryObject.Create;

  tsho.Path           := aPath;
  tsho.DateI          := aDateI;
  tsho.TimeI          := aTimeI;
  tsho.ExcludeFiles   := aExcludeFiles;
  tsho.ExcludeFolders := aExcludeFolders;

  ScanHistory.Insert(0, tsho);
end;

end.
