// New Version Checking Stuff
//
//       Started: May 1st 2005
// Last Modified: January 16th 2019
//
// 268

unit X.Form.CheckVersion;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, IdBaseComponent, IdComponent, IdTCPConnection, Registry,
  IdTCPClient, IdHTTP, StdCtrls, Buttons,

  TMSLogging,

  X.LanguageHandler,

  X.SystemGlobal, X.Constants, X.Windows, X.Utility;


type
  TfrmCheckVersion = class(TForm)
    BitBtn1: TBitBtn;
    bHistory: TBitBtn;
    mHistory: TMemo;
    bDownload: TBitBtn;
    Shape1: TShape;
    lTitle: TLabel;
    bWebsite: TBitBtn;
    lDate1: TLabel;
    lVersion1: TLabel;
    gbOnline: TGroupBox;
    lDate2: TLabel;
    lVersion2: TLabel;
    lIVDate: TLabel;
    lIVVersion: TLabel;
    lLADate: TLabel;
    lLAVersion: TLabel;
    GroupBox1: TGroupBox;
    lWhat: TLabel;
    httpMain: TIdHTTP;
    gbInstalled: TGroupBox;
    procedure FormShow(Sender: TObject);
    procedure bHistoryClick(Sender: TObject);
    procedure bDownloadClick(Sender: TObject);
    procedure bWebsiteClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    FInstalledDate    : string;
    FInstalledVersion : string;

    ApplicationVersionFile : string;
    AutoClose : boolean;  public
  end;


var
  frmCheckVersion: TfrmCheckVersion;


function CheckForNewVersion(aCurrentVersion, aCurrentDate, appdat : string; autoclosemode : boolean): word;
function CheckForNewVersionSilent(aCurrentVersion, aCurrentDate, appdat : string): word;


implementation

{$R *.dfm}


function CheckForNewVersion(aCurrentVersion, aCurrentDate, appdat : string; autoclosemode : boolean): word;
 begin
  with TfrmCheckVersion.Create(Application) do
    try
      ApplicationVersionFile := appdat;

      autoclose          := autoclosemode;

      lIVDate.Caption    := aCurrentDate;
      lIVVersion.Caption := aCurrentVersion;

      ShowModal;

      Result := ModalResult;
    finally
      Free;
    end;
end;


function CheckForNewVersionSilent(aCurrentVersion, aCurrentDate, appdat : string): word;
 var
  s : string;
  x : TStringList;
  doautocheck : boolean;
  Reg: TRegistry;

 begin
  with TfrmCheckVersion.Create(Application) do
    try
      Result := mrOK;

      Reg := TRegistry.Create(KEY_READ);

      try
        Reg.RootKey := HKEY_CURRENT_USER;
        Reg.OpenKey('\software\' + XinorbisRegistryKey, False);

        if Reg.ValueExists('Prefs_AutoCheckUpdate') then
          doautocheck := Reg.ReadBool('Prefs_AutoCheckUpdate')
        else
          doautocheck := False;
      finally
        Reg.Free;
      end;

      if doautocheck then begin

        ApplicationVersionFile := appdat;

        FInstalledDate    := aCurrentDate;
        FInstalledVersion := aCurrentVersion;

        x := TStringList.Create;

        GSystemGlobal.NewVersionAvailable := False;

        try
          s := httpMain.Get('http://www.maximumoctopus.com/versions/' + ApplicationVersionFile + 'Prod.dat');

          x.Text := s;

          if x.Count > 0 then begin

            if (x.Strings[0] <> FInstalledDate) or
               (x.Strings[1] <> FInstalledVersion) then begin

              GSystemGlobal.NewVersionAvailable := True;
            end;
          end;
        except
          on e : exception do begin
            TMSLogger.Error('Update check error (silent). ' + e.ClassName + ' / ' + e.Message);
          end;
        end;

        x.Free;
      end;
  finally
    Free;
  end;
end;


procedure TfrmCheckVersion.FormCreate(Sender: TObject);
begin
  lTitle.Caption      := XText[rsCheckForUpdates];

  gbInstalled.Caption := XText[rsInstalledVersion];
  lDate1.Caption      := XText[rsDate];
  lVersion1.Caption   := XText[rsVersion];

  gbOnline.Caption    := XText[rsLatestAvailableOnline];
  lDate2.Caption      := XText[rsDate];
  lVersion2.Caption   := XText[rsVersion];

  bDownload.Caption   := '&' + XText[rsDownload];
  bWebsite.Caption    := '&' + XText[rsWebsite];
  bHistory.Caption    := '&' + XText[rsHistory] + ' >>';
end;


procedure TfrmCheckVersion.FormShow(Sender: TObject);
 var
  s : string;
  x : TStringList;

 begin
  x := TStringList.Create;

  try
    s := httpMain.Get('http://www.maximumoctopus.com/versions/' + ApplicationVersionFile + 'Prod.dat');

    x.Text := s;

    lLADate.Caption    := x.Strings[0];
    lLAVersion.Caption := x.Strings[1];

    if (lLADate.Caption <> lIVDate.Caption) or
       (lLAVersion.Caption <> lIVVersion.Caption) then begin
      lWhat.Caption := XText[rsANewVersionIsAvailable];

      s := httpMain.Get('http://www.maximumoctopus.com/versions/' + ApplicationVersionFile + 'Proh.dat');

      mHistory.Text := s;

      bHistory.Enabled   := True;
    end
    else begin
      lWhat.Caption      := XText[rsNoNewVersionIsAvailable];

      Close;
    end;
  except
    on e : exception do begin
      lLADate.Caption    := XText[rsError];
      lLAVersion.Caption := XText[rsError];

      lWhat.Caption      := XText[rsUnableToConnectTo] + ' "maximumoctopus.com!"';

      TMSLogger.Error('Update check error. ' + e.ClassName + ' / ' + e.Message);
    end;
  end;

  x.Free;
end;


procedure TfrmCheckVersion.bHistoryClick(Sender: TObject);
 begin
  if bHistory.Tag = 0 then begin
    bHistory.Tag     := 1;
    bHistory.Caption := XText[rsHistory] + ' <<';
    ClientHeight     := 494;
  end
  else begin
    bHistory.Tag     := 0;
    bHistory.Caption := XText[rsHistory] + ' >>';
    ClientHeight     := 271;
  end;
end;


procedure TfrmCheckVersion.bDownloadClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'http://xinorbis.com/downloads.htm', '', '');
end;


procedure TfrmCheckVersion.bWebsiteClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'http://www.xinorbis.com/', '', '');
end;


end.
