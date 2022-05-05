{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CSearchObject;

interface

uses comctrls;

type
  TSearchObject = class(TObject)
  private
  public
    Filename : string;
    MD5      : string;
    Node     : TTreeNode;
    NiceSize : string;
    Size     : int64;
  end;


implementation


end.
