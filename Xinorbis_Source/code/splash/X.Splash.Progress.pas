{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Splash.Progress;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Buttons, AdvSmoothProgressBar, StdCtrls, ExtCtrls,

  X.Constants, X.LanguageHandler;

type
  TfrmProgress = class(TForm)
    iProgress1: TImage;
    iProgress2: TImage;
    iProgress3: TImage;
    iProgress4: TImage;
    iProgress5: TImage;
    lStatus: TLabel;
    lStatus2: TLabel;
    lStatus3: TLabel;
    Image1: TImage;
    lAbortStatus: TLabel;
    sbStop: TSpeedButton;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure sbStopClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    procedure SetProcessText(const s : string);
    procedure SetProcessIcon(i : integer);
    procedure SetPercentage(const s : string);
    procedure SetProcessBar(newposition : integer);
    procedure SetStatus3(const s : string);
    procedure SetAbort;
  end;

var
  frmProgress: TfrmProgress;



implementation

{$R *.dfm}

uses
  X.Global;


procedure TfrmProgress.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  Action := caFree;
end;


procedure TfrmProgress.SetProcessText(const s : string);
 begin
  lStatus.Caption := s;
  lStatus.Refresh;

  lStatus2.Caption := '';
  lStatus2.Refresh;

  lStatus3.Caption := '';
  lStatus3.Refresh;
end;


procedure TfrmProgress.SetPercentage(const s : string);
 begin
  lStatus2.Caption := s;
  lStatus2.Invalidate;
end;


procedure TfrmProgress.SetStatus3(const s : string);
 begin
  lStatus3.Caption := s;
  lStatus3.Invalidate;
end;


procedure TfrmProgress.SetProcessIcon(i : integer);
 var
  lImage : TImage;

 begin
  lImage := Nil;

  case i of
    1 : lImage := iProgress1;
    2 : lImage := iProgress2;
    3 : lImage := iProgress3;
    4 : lImage := iProgress4;
    5 : lImage := iProgress5;
  end;

  lImage.Visible := True;
  lImage.Invalidate;
end;


procedure TfrmProgress.SetProcessBar(newposition : integer);
 begin
//  pbProcess.Position := newposition;
//  pbProcess.Invalidate;
end;


procedure TfrmProgress.FormCreate(Sender: TObject);
begin
  sbStop.Caption := XText[rsCancel];
end;


procedure TfrmProgress.sbStopClick(Sender: TObject);
begin
// stopscan := True;

//  ffMain.Abort;

//  XSettings.ProgressForm.SetAbort;
end;


procedure TfrmProgress.SetAbort;
 begin
  lAbortStatus.Visible := True;
  lAbortStatus.Invalidate;
end;


end.
