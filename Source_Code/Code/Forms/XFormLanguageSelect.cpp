//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormLanguageSelect.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
}


/*


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
*/
