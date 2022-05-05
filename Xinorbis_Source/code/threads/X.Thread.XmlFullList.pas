{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Thread.XmlFullList;

interface

uses SysUtils, classes,

     X.Utility, X.CFileObject, X.Global, X.GlobalObjects, X.Formatting;


type
  TXMLFullListThread = class(TThread)
  public
    FError : boolean;

    procedure SetData(const s : string; dx : integer);
  private
    FileName  : string;
    DataIndex : integer;
  protected
    procedure Execute; override;
  end;


implementation


uses
  X.Constants, X.CUserData, X.Conversions;


procedure TXMLFullListThread.SetData(const s : string; dx : integer);
 begin
  FileName  := s;
  DataIndex := dx;

  FError    := False;
end;


procedure TXMLFullListThread.Execute;
 var
  wp : TextFile;
  t : integer;
  tfo : TFileObject;

  function BoolToString(fish : boolean): String;
   begin
    if fish then
      Result := '1'
    else
      Result := '0';
  end;

 begin
  FreeOnTerminate := True;

  AssignFile(wp, FileName);
  {$I-}
  Rewrite(wp);

  if IOResult <> 0 then
    FError := True;
  {$I+}

  Writeln(wp, '<?xml version="1.0"?>');
  Writeln(wp, '<!--  -->');
  Writeln(wp, '<!-- generated with Xinorbis ' + x8Title + ' - ' + x8Date + ' -->');
  Writeln(wp, '<!-- http://xinorbis.com - Paul A Freshney -->');
  Writeln(wp, '<!--  -->');  
  Writeln(wp, '<xinorbisfilelist>');

  for t := 0 to GScanDetails[DataIndex].Files.Count - 1 do begin
    tfo := GScanDetails[DataIndex].Files.Items[t];

    Writeln(wp, '<item>');
    Writeln(wp, TXFormatting.InsertElement('name', TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(tfo.FileName)), 2));
    Writeln(wp, TXFormatting.InsertElement('path', TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(GScanDetails[DataIndex].Folders[tfo.FilePathIndex])), 2));

    if (faDirectory and tfo.Attributes) = faDirectory then begin
      Writeln(wp, TXFormatting.InsertElement('sizewords', '-1', 2));
      Writeln(wp, TXFormatting.InsertElement('sizebytes', '-1', 2));
      Writeln(wp, TXFormatting.InsertElement('sizeondiskwords', '-1', 2));
      Writeln(wp, TXFormatting.InsertElement('sizeondiskbytes', '-1', 2));
    end
    else begin
      Writeln(wp, TXFormatting.InsertElement('sizewords', TConvert.ConvertToUsefulUnit(tfo.FileSize), 2));
      Writeln(wp, TXFormatting.InsertElement('sizebytes', IntToStr(tfo.FileSize), 2));
      Writeln(wp, TXFormatting.InsertElement('sizeondiskwords', TConvert.ConvertToUsefulUnit(tfo.FileSizeOnDisk), 2));
      Writeln(wp, TXFormatting.InsertElement('sizeondiskbytes', IntToStr(tfo.FileSizeOnDisk), 2));
    end;

    Writeln(wp, TXFormatting.InsertElement('owner',                TXFormatting.Privacy(GScanDetails[DataIndex].Users[tfo.Owner].Name), 2));
    Writeln(wp, TXFormatting.InsertElement('timecreated',          IntToStr(tfo.FileTimeC), 2));
    Writeln(wp, TXFormatting.InsertElement('timemodified',         IntToStr(tfo.FileTimeM), 2));
    Writeln(wp, TXFormatting.InsertElement('timeaccessed',         IntToStr(tfo.FileTimeA), 2));
    Writeln(wp, TXFormatting.InsertElement('datecreated',          TConvert.IntDateToString(tfo.FileDateC), 2));
    Writeln(wp, TXFormatting.InsertElement('datemodified',         TConvert.IntDateToString(tfo.FileDateM), 2));
    Writeln(wp, TXFormatting.InsertElement('dateaccessed',         TConvert.IntDateToString(tfo.FileDateA), 2));
    Writeln(wp, TXFormatting.InsertElement('datecreatedyyyymmdd',  IntToStr(tfo.FileDateC), 2));
    Writeln(wp, TXFormatting.InsertElement('datemodifiedyyyymmdd', IntToStr(tfo.FileDateM), 2));
    Writeln(wp, TXFormatting.InsertElement('dateaccessedyyyymmdd', IntToStr(tfo.FileDateA), 2));
    Writeln(wp, TXFormatting.InsertElement('category',             IntToStr(tfo.FileCategory), 2));
    Writeln(wp, TXFormatting.InsertElement('folder',               TConvert.AttributeToIntAsString(tfo.Attributes, faDirectory), 2));
    Writeln(wp, TXFormatting.InsertElement('readonly',             TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly), 2));
    Writeln(wp, TXFormatting.InsertElement('hidden',               TConvert.AttributeToIntAsString(tfo.Attributes, faHidden), 2));
    Writeln(wp, TXFormatting.InsertElement('system',               TConvert.AttributeToIntAsString(tfo.Attributes, faSysFile), 2));
    Writeln(wp, TXFormatting.InsertElement('archive',              TConvert.AttributeToIntAsString(tfo.Attributes, faArchive), 2));
    Writeln(wp, TXFormatting.InsertElement('temp',                 BoolToString(tfo.Temp), 2));
    Writeln(wp, '</item>');
  end;

  Writeln(wp, '</xinorbisfilelist>');

  CloseFile(wp);
end;


end.
