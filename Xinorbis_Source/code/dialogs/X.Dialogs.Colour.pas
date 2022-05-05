{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Dialogs.Colour;

interface


uses
 Vcl.Dialogs, System.SysUtils;


type
  TXColourDialog = class
  public
    class function Execute(aColour : integer): integer;
  end;


implementation


class function TXColourDialog.Execute(aColour : integer): integer;
var
  lColorDialog : TColorDialog;
begin
  Result := -1;

  lColorDialog := TColorDialog.Create(Nil);

  if aColour <> -1 then
    lColorDialog.Color := aColour;

  if lColorDialog.Execute then
    Result := lColorDialog.Color;

  FreeAndNil(lColorDialog);
end;

end.
