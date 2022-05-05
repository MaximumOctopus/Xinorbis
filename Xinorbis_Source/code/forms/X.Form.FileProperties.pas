unit X.Form.FileProperties;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  Buttons, ExtCtrls, StdCtrls,

  X.FileExtensionsObject, X.LanguageHandler;

type
  TfrmFileProperties = class(TForm)
    SpeedButton1: TSpeedButton;
    Label1: TLabel;
    lFilename: TLabel;
    Image1: TImage;
    Label2: TLabel;
    lDate: TLabel;
    Label3: TLabel;
    lSize: TLabel;
    Shape1: TShape;
    cbSuggestion: TComboBox;
    Label4: TLabel;
    procedure ProcessFile(s : string);
    procedure SpeedButton1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmFileProperties: TfrmFileProperties;

procedure ShowFileProperties(filename : string);


implementation

{$R *.DFM}


uses X.Utility, X.Global;


procedure ShowFileProperties(filename : string);
 begin
  with TfrmFileProperties.Create(Application) do
    try
      ProcessFile(filename);

      ShowModal;
    except
      free;
    end;
end;


procedure TfrmFileProperties.ProcessFile(s : string);
 var
  julie : File of byte;
  t : integer;
  
 begin
  lFileName.Caption := s;

  AssignFile(julie, s);
  Reset(julie);

  lSize.Caption := IntToStr(FileSize(julie)) + ' ' + XText[rsBytes];

  CloseFile(julie);

  // file type
  cbSuggestion.Clear;

  s := UpperCase(Copy(ExtractFileExt(s), 2, Length(ExtractFileExt(s)) - 1));

  for t := 0 to FileExtensionsObject.FileExtensionDescriptions.Count - 1 do begin
    if Pos(s, FileExtensionsObject.FileExtensionDescriptions.Strings[t]) = 1 then
      cbSuggestion.Items.Add(FileExtensionsObject.FileExtensionDescriptions.Strings[t]);
  end;

  if cbSuggestion.Items.Count = 0 then
    cbSuggestion.Items.Add('* ' + XText[rsUnknown] + ' *')
  else begin
    for t := 0 to cbSuggestion.Items.Count-1 do begin
      cbSuggestion.Items[t] := IntToStr(t + 1) + '/' + IntToStr(cbSuggestion.Items.Count) + ' : ' + cbSuggestion.Items[t];
    end;
  end;

  cbSuggestion.ItemIndex := 0;
end;


procedure TfrmFileProperties.SpeedButton1Click(Sender: TObject);
 begin
  Close;
end;


end.
