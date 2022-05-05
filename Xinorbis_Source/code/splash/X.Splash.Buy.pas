unit X.Splash.Buy;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, ExtCtrls, Vcl.Imaging.pngimage,

  X.Utility, X.Windows, Vcl.Buttons;

type
  TfrmDonate = class(TForm)
    Image1: TImage;
    Label1: TLabel;
    Label2: TLabel;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    Image7: TImage;
    procedure Button1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmDonate: TfrmDonate;

procedure ShowPleaseDonate;

implementation

{$R *.dfm}


procedure ShowPleaseDonate;
 begin
  with TfrmDonate.Create(Application) do
    try
      ShowModal;
    finally
      free;
    end;
 end;


procedure TfrmDonate.Button1Click(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'http://xinorbis.com/buy.htm', '', '');
end;


procedure TfrmDonate.SpeedButton2Click(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, 'http://xinorbis.com/compare.htm', '', '');
end;

end.
