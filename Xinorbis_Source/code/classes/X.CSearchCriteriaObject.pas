{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CSearchCriteriaObject;

interface

type
  TSearchCriteriaObject = class(TObject)
  private
  public
    sctype       : integer;
    stringvalue  : string;
    integervalue : int64;

    error        : string;

    constructor Create;
  end;


const
  SearchTypeNONE                = 0;
  SearchTypeSizeLess            = 1;
  SearchTypeSizeEqual           = 2;
  SearchTypeSizeMore            = 3;
  SearchTypeCategory            = 4;
  SearchTypeDateLess            = 5;
  SearchTypeDateMore            = 6;
  SearchTypeDateEqual           = 7;
  SearchTypeFileType            = 8;
  SearchTypeADateLess           = 9;
  SearchTypeADateMore           = 10;
  SearchTypeADateEqual          = 11;
  SearchTypeMDateLess           = 12;
  SearchTypeMDateMore           = 13;
  SearchTypeMDateEqual          = 14;
  SearchTypeUsername            = 15;
  SearchTypeNotUsername         = 16;
  SearchTypeNotCategory         = 17;
  SearchTypeNotFileType         = 18;
  SearchTypeATimeLess           = 19;
  SearchTypeATimeMore           = 20;
  SearchTypeATimeEqual          = 21;
  SearchTypeMTimeLess           = 22;
  SearchTypeMTimeMore           = 23;
  SearchTypeMTimeEqual          = 24;
  SearchTypeTimeLess            = 25;
  SearchTypeTimeMore            = 26;
  SearchTypeTimeEqual           = 27;
  SearchTypeUsernameContains    = 28;
  SearchTypeUsernameNotContains = 29;
  SearchTypeFilenameLengthEqual = 40;
  SearchTypeFilenameLengthLess  = 41;
  SearchTypeFilenameLengthMore  = 42;
  SearchTypeFilePathLengthEqual = 43;
  SearchTypeFilePathLengthLess  = 44;
  SearchTypeFilePathLengthMore  = 45;
  SearchTypeFileExtensionEqual  = 46;
  SearchTypeFolderExclude       = 60;
  SearchTypeFolderInclude       = 61;
  SearchTypeERROR               = 999;


implementation


constructor TSearchCriteriaObject.Create;
begin
  inherited;

  sctype       := SearchTypeNONE;
  stringvalue  := '';
  integervalue := 0;

  error        := '';
end;


end.
