{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CReportColours;

interface


uses
  X.Constants;


type
  THTMLColours = record
    Colour       : array[1..HTMLColoursCount] of integer;
    MonoBargraph : boolean;
  end;


implementation


end.
