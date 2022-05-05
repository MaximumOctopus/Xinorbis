// (c) Paul Alan Freshney 2006-2011
//
// Modified: April 26th 2011
//
// 33

unit X.Splash.CheckUpdate;

interface

uses
  Windows, Forms, StdCtrls, ExtCtrls, Vcl.Imaging.pngimage,

  X.LanguageHandler, System.Classes, Vcl.Controls;


type
  TfrmUpdateSplash = class(TForm)
    Image1: TImage;
    Label1: TLabel;
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;


var
  frmUpdateSplash: TfrmUpdateSplash;


implementation


{$R *.dfm}


procedure TfrmUpdateSplash.FormShow(Sender: TObject);
begin
  Label1.Caption := XText[rsCheckingForUpdates];
end;


end.
