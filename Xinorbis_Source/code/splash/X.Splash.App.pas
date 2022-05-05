{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Splash.App;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  jpeg, ExtCtrls, StdCtrls, Vcl.Imaging.pngimage;

type
  TfrmSplash = class(TForm)
    Image1: TImage;
    Label2: TLabel;
    Timer1: TTimer;
    Label1: TLabel;
    procedure Timer1Timer(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmSplash: TfrmSplash;

implementation

{$R *.DFM}

procedure TfrmSplash.Timer1Timer(Sender: TObject);
 begin
  Timer1.Enabled := False;

  Close;
end;

end.
