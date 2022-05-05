{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.FileExtension;


interface


uses
  System.SysUtils, System.Generics.Collections,

  X.Constants, X.Dialogs.Dialog;


const
  AvailableDataPages = 3;


type
  TFileExtension = class(TObject)
  private
  public
    Name     : string;
    Category : integer;
    Quantity : array[0..AvailableDataPages - 1] of integer;
    Size     : array[0..AvailableDataPages - 1] of int64;

    constructor Create;
  end;

  TExtensionExistsIn = record
    NotFound         : boolean;
    RawCategory      : integer;
  end;


implementation


uses
  X.Settings;


constructor TFileExtension.Create;
 begin
  Category    := 0;

  Quantity[0] := 0;
  Quantity[1] := 0;

  Size[0]     := 0;
  Size[1]     := 0;
end;


// =============================================================================


end.
