{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.CCSVDataFormat;


interface


const
  CFieldIgnore             = 0;
  CFieldFullFilePath       = 1;
  CFieldFileSizeBytes      = 2;
  CFieldFileSizeOnDIsk     = 3;
  CFieldCreatedDDMMYYYY    = 4;
  CFieldCreatedMMDDYYYY    = 5;
  CFieldModifiedDDMMYYYY   = 6;
  CFieldModifiedMMDDYYYY   = 7;
  CFieldAccessedDDMMYYYY   = 8;
  CFieldAccessedMMDDYYYY   = 9;
  CFieldFilePath           = 10;
  CFieldFileName           = 11;
  CFieldOwner              = 12;
  CFieldCategory           = 13;
  CFieldReadOnly           = 14;
  CFieldHidden             = 15;
  CFieldSystem             = 16;
  CFieldArchive            = 17;
  CFieldTemp               = 18;
  CFieldAttributes         = 19;
  CFieldCreatedTimeHHMMSS  = 20;
  CFieldModifiedTimeHHMMSS = 21;
  CFieldAccessedTimeHHMMSS = 22;

  MaxCSVFields             = 19; // maximum that can be imported from


type
  TCSVDataFormat = record
                     IgnoreFirstRecord : boolean;

                     Fields : array[0..MaxCSVFields] of integer;
                   end;

implementation

end.
