{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: January 28th 2002
  Last Modified: January 11th 2020
}


unit X.Form.About;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  Buttons, StdCtrls, ExtCtrls, ImgList, Vcl.Imaging.pngimage, Vcl.Imaging.GIFImg,

  X.Windows, X.LanguageHandler, X.SystemGlobal;

type
  TfrmAbout = class(TForm)
    lDate: TLabel;
    lVersion: TLabel;
    Shape1: TShape;
    gbSocialMedia: TGroupBox;
    Label2: TLabel;
    Label12: TLabel;
    Label5: TLabel;
    Label3: TLabel;
    Label13: TLabel;
    gbThanks: TGroupBox;
    Image4: TImage;
    Image5: TImage;
    Label9: TLabel;
    Label10: TLabel;
    Image3: TImage;
    Label11: TLabel;
    lAuthor: TLabel;
    Image2: TImage;
    Label1: TLabel;
    GroupBox3: TGroupBox;
    Label6: TLabel;
    lMode: TLabel;
    lDataPath: TLabel;
    lSystemPath: TLabel;
    Image7: TImage;
    BitBtn1: TBitBtn;
    Image8: TImage;
    Label7: TLabel;
    Label8: TLabel;
    Label15: TLabel;
    Label16: TLabel;
    lDevCats: TLabel;
    Label18: TLabel;
    Label19: TLabel;
    Image9: TImage;
    Label17: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Label13Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure Label12Click(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
    procedure lDevCatsClick(Sender: TObject);
    procedure lSystemPathClick(Sender: TObject);
    procedure lDataPathClick(Sender: TObject);
  private
  public
    { Public declarations }
  end;


var
  frmAbout: TfrmAbout;


procedure ShowAbout;


implementation

{$R *.DFM}


uses
  X.Utility, X.Global, X.Settings, X.Constants;


procedure ShowAbout;
 begin
  with TfrmAbout.Create(Application) do
    try
      ShowModal;
    finally
      free;
    end;
end;


procedure TfrmAbout.FormCreate(Sender: TObject);
 begin
  lDate.Caption    := x8Date;
  lVersion.Caption := 'xinorbis ' + x8Version;
  lAuthor.Caption  := '(c) Paul Alan Freshney ' + TUtility.GetCurrentYear;

  gbSocialMedia.Caption := ' ' + XText[rsSocialMedia] + ' ';
  gbThanks.Caption      := ' ' + XText[rsThanks] + ' ';

  // ===========================================================================

  if XSettings.CustomSettings.SettingsSaveLocation = SaveLocationConfigIni then
    lMode.Caption := XText[rsPortable]
  else
    lMode.Caption := XText[rsStandard];

  if XSettings.Database.UseODBC then
    lMode.Caption := lMode.Caption + ' (ODBC)'
  else
    lMode.Caption := lMode.Caption + ' (SQlite)';

  lDataPath.Caption   := GSystemGlobal.AppDataPath;
  lSystemPath.Caption := GSystemGlobal.ExePath;
end;


procedure TfrmAbout.Label12Click(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, 'mailto:xinorbis@maximumoctopus.com', '', '');
end;


procedure TfrmAbout.Label13Click(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, TLabel(Sender).Caption, '', '');
end;


procedure TfrmAbout.lDataPathClick(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, '"' + lDataPath.Caption + '"', '', '');
end;

procedure TfrmAbout.lDevCatsClick(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, 'http://xinorbis.com/developmentcats.htm', '', '');
end;


procedure TfrmAbout.lSystemPathClick(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, '"' + lSystemPath.Caption + '"', '', '');
end;

procedure TfrmAbout.BitBtn1Click(Sender: TObject);
begin
  Close;
end;


procedure TfrmAbout.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;


end.
