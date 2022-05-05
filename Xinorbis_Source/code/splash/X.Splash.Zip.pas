{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Splash.Zip;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  AdvSmoothProgressBar, StdCtrls, ExtCtrls, Vcl.Imaging.pngimage, Shader,

  X.LanguageHandler;

type
  TfrmZipDisplay = class(TForm)
    lZipCurrentFile: TLabel;
    pbZip: TAdvSmoothProgressBar;
    lZipStatus: TLabel;
    Shape1: TShape;
    shaderTitle: TShader;
    Image1: TImage;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    procedure SetZipFileName(const s : string);
    procedure SetCaption(const s : string);
    procedure SetPosition(i : integer);
  end;

var
  frmZipDisplay: TfrmZipDisplay;

implementation


{$R *.dfm}


procedure TfrmZipDisplay.FormCreate(Sender: TObject);
begin
  shaderTitle.Caption := XText[rsPleaseWait];
end;


procedure TfrmZipDisplay.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;


procedure TfrmZipDisplay.SetZipFileName(const s : string);
begin
  lZipCurrentFile.Caption := s;
end;


procedure TfrmZipDisplay.SetCaption(const s : string);
 begin
  lZipStatus.Caption := s;
end;


procedure TfrmZipDisplay.SetPosition(i : integer);
 begin
  pbZip.Position := i;
end;


end.
