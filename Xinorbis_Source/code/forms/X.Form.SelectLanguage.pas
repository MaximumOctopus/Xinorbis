{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: April 23rd 2009
  Last Modified: January 11th 2020
}


unit X.Form.SelectLanguage;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  ExtCtrls, StdCtrls, Vcl.Imaging.pngimage,

  TMSLogging,

  X.SystemGlobal;

type
  TfrmSetLanguage = class(TForm)
    i1: TImage;
    i2: TImage;
    i3: TImage;
    i4: TImage;
    i5: TImage;
    i6: TImage;
    i7: TImage;
    i9: TImage;
    i8: TImage;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    Image1: TImage;
    i10: TImage;
    Label10: TLabel;
    i11: TImage;
    Label11: TLabel;
    procedure FormShow(Sender: TObject);
    procedure i1Click(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
  private
    procedure LoadFlag(aImage : TImage; aFlag : string);
  end;

var
  frmSetLanguage: TfrmSetLanguage;

function GetInitialLanguage: integer;


implementation

{$R *.dfm}

uses
  X.Utility, X.Global, X.Constants;


var
 lID : integer;


function GetInitialLanguage: integer;
 begin
  with TfrmSetLanguage.Create(Application) do
    try
      lID := languageUNDEFINED;

      ShowModal;

      Result := lID
    finally
      free;
  end;
end;


procedure TfrmSetLanguage.FormCloseQuery(Sender: TObject;
  var CanClose: Boolean);
begin
  if lID <> languageUNDEFINED then
    CanClose := True
  else
    CanClose := False;
end;


procedure TfrmSetLanguage.FormShow(Sender: TObject);
 begin
  LoadFlag(i1,  'UK\flag.bmp');
  LoadFlag(i2,  'FR\flag.bmp');
  LoadFlag(i3,  'DE\flag.bmp');
  LoadFlag(i4,  'ES\flag.bmp');
  LoadFlag(i5,  'IT\flag.bmp');
  LoadFlag(i6,  'NL\flag.bmp');
  LoadFlag(i7,  'HU\flag.bmp');
  LoadFlag(i8,  'US\flag.bmp');
  LoadFlag(i9,  'CAT\flag.bmp');
  LoadFlag(i10, 'RU\flag.bmp');
  LoadFlag(i11, 'CZ\flag.bmp');
end;


procedure TfrmSetLanguage.i1Click(Sender: TObject);
 begin
  lID := languageUNDEFINED;

  case TImage(Sender).Tag of
     1 : lID := languageUK;
     2 : lID := languageFR;
     3 : lID := languageDE;
     4 : lID := languageES;
     5 : lID := languageIT;
     6 : lID := languageNL;
     7 : lID := languageHU;
     8 : lID := languageUS;
     9 : lID := languageCAT;
    10 : lID := languageRU;
    11 : lID := languageCZ;
  end;

  if lID <> languageUNDEFINED then
    ModalResult := mrOK;
end;


procedure TfrmSetLanguage.LoadFlag(aImage : TImage; aFlag : string);
begin
  if FileExists(GSystemGlobal.ExePath  + 'data\languages\' + aFlag) then
    aImage.Picture.LoadFromFile(GSystemGlobal.ExePath  + 'data\languages\' + aFlag)
  else begin
    if FileExists(GSystemGlobal.ExePath  + 'data\flag.bmp') then
      aImage.Picture.LoadFromFile(GSystemGlobal.ExePath  + 'data\flag.bmp');

    aImage.Enabled := False;

    TMSLogger.Error('Missing flag file "' + aFlag + '".');
  end;
end;


end.
