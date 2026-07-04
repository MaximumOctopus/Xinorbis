//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormReportOptions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


/*
uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, AdvOfficeButtons,
  Vcl.Buttons, AdvSmoothSlider, Vcl.ExtCtrls,

  IdBaseComponent, IdTCPConnection, IdComponent,
  IdTCPClient, IdExplicitTLSClientServerBase, IdFTP,

  TMSLogging,

  X.Dialogs.Load, X.Dialogs.Dialog,

  X.Constants, X.LanguageHandler, X.Settings, X.SystemGlobal, X.Windows;

type
  TForm1 = class(TForm)
    pOutputOptions: TPanel;
    lOutputOptions: TLabel;
    lDocOptions: TLabel;
    Image2: TImage;
    Image3: TImage;
    Image4: TImage;
    Image5: TImage;
    Image6: TImage;
    Image7: TImage;
    Label31: TLabel;
    lReportMenuTree: TLabel;
    Label42: TLabel;
    Label44: TLabel;
    Label45: TLabel;
    Label46: TLabel;
    Panel1: TPanel;
    bSave: TBitBtn;
    bCancel: TBitBtn;
    Bevel10: TBevel;
    pReportsAutosave: TPanel;
    lReportsAutosave: TLabel;
    lASDrive: TLabel;
    lASOrganise: TLabel;
    lADR_1: TLabel;
    lADR_9: TLabel;
    lADR_4: TLabel;
    lADR_3: TLabel;
    lADR_2: TLabel;
    lADR_5: TLabel;
    cbASOrganise: TAdvSmoothSlider;
    cbADR_5: TAdvSmoothSlider;
    cbADR_2: TAdvSmoothSlider;
    cbADR_3: TAdvSmoothSlider;
    cbADR_4: TAdvSmoothSlider;
    cbADR_9: TAdvSmoothSlider;
    cbADR_1: TAdvSmoothSlider;
    cbASDrive: TAdvSmoothSlider;
    pWebReports: TPanel;
    Label47: TLabel;
    Label48: TLabel;
    Label49: TLabel;
    Label50: TLabel;
    Label51: TLabel;
    Label52: TLabel;
    Label53: TLabel;
    Label54: TLabel;
    Label55: TLabel;
    lWebReportTest: TLabel;
    BitBtn1: TBitBtn;
    BitBtn2: TBitBtn;
    eFTPHost: TEdit;
    eFTPUsername: TEdit;
    eFTPPassword: TEdit;
    eFTPInitialFolder: TEdit;
    eFTPRemoteFolder: TEdit;
    eFTPLink: TEdit;
    pReportsTree: TPanel;
    lReportsTree: TLabel;
    pReportsText: TPanel;
    lReportsText: TLabel;
    lTextDefaultOutput: TLabel;
    SpeedButton10: TSpeedButton;
    eOOTextOutput: TEdit;
    pReportsXML: TPanel;
    lReportsXML: TLabel;
    Label8: TLabel;
    SpeedButton3: TSpeedButton;
    eOOXMLOutput: TEdit;
    pReportsXinorbis: TPanel;
    lReportsXinorbis: TLabel;
    gbXReportType: TGroupBox;
    rbXReportDetailed: TAdvOfficeRadioButton;
    rbXReportNormal: TAdvOfficeRadioButton;
    cbXinorbisLayouts: TComboBox;
    pReportsHTML: TPanel;
    lReportsHTML: TLabel;
    Label6: TLabel;
    SpeedButton1: TSpeedButton;
    eOOHTMLOutput: TEdit;
    pReportsCSV: TPanel;
    lReportsCSV: TLabel;
    Label29: TLabel;
    SpeedButton9: TSpeedButton;
    eOOCSVOutput: TEdit;
    ftpMain: TIdFTP;
    sbGeneral: TSpeedButton;
    SpeedButton2: TSpeedButton;
    sbReportTree: TSpeedButton;
    SpeedButton5: TSpeedButton;
    SpeedButton6: TSpeedButton;
    sbAutoSave: TSpeedButton;
    sbWebReports: TSpeedButton;
    SpeedButton12: TSpeedButton;
    procedure SpeedButton17Click(Sender: TObject);
    procedure cbASDriveStateChanged(Sender: TObject;
      State: TAdvSmoothSliderState; Value: Double);
    procedure SpeedButton9Click(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure rbXReportNormalClick(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
    procedure SpeedButton10Click(Sender: TObject);
    procedure sbWebReportsClick(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure ftpMainStatus(ASender: TObject; const AStatus: TIdStatus;
      const AStatusText: string);
    procedure ftpMainWorkBegin(ASender: TObject; AWorkMode: TWorkMode;
      AWorkCountMax: Int64);
    procedure ftpMainWorkEnd(ASender: TObject; AWorkMode: TWorkMode);
    procedure cbXinorbisLayoutsChange(Sender: TObject);
  private
    opentabatstart    : integer;

    procedure SetLanguage;

    procedure BuildXinorbisLayoutList(xinlayout : integer);

    function  BooleanToSliderState(aBoolean : boolean): TAdvSmoothSliderState;
    function  SliderStateToBoolean(aState : TAdvSmoothSliderState): boolean;
  public
    { Public declarations }
  end;

var
  Form1: TForm1;


function DoReportSettings(OpenAtTab : integer): integer;


implementation


{$R *.dfm}


const
  CPageAutosave = 0;
  CPageCSV      = 1;
  CPageHTML     = 2;
  CPageXML      = 3;
  CPageText     = 4;
  CPageTree     = 5;
  CPageXinorbis = 6;


function DoReportSettings(OpenAtTab : integer): integer;
begin
  with TForm1.Create(Application) do
    try
      SetLanguage;

      eFTPHost.Text          := XSettings.ftpOptions[ftpHost];
      eFTPUsername.Text      := XSettings.ftpOptions[ftpUsername];
      eFTPPassword.Text      := XSettings.ftpOptions[ftpPassword];
      eFTPRemoteFolder.Text  := XSettings.ftpOptions[ftpRemoteFolder];
      eFTPLink.Text          := XSettings.ftpOptions[ftpActualLink];
      eFTPInitialFolder.Text := XSettings.ftpOptions[ftpInitialFolder];

      // =======================================================================

      cbASDrive.State := BooleanToSliderState(XSettings.Report.autosavemode);
      cbASDriveStateChanged(cbASDrive, cbASDrive.State, 0);

      cbADR_1.State   := BooleanToSliderState(XSettings.Report.AutoSaveItem[1]);
      cbADR_2.State   := BooleanToSliderState(XSettings.Report.AutoSaveItem[2]);
      cbADR_3.State   := BooleanToSliderState(XSettings.Report.AutoSaveItem[3]);
      cbADR_4.State   := BooleanToSliderState(XSettings.Report.AutoSaveItem[4]);
      cbADR_9.State   := BooleanToSliderState(XSettings.Report.AutoSaveItem[5]);
      cbADR_5.State   := BooleanToSliderState(XSettings.Report.AutoSaveItem[6]);

      // =======================================================================

      cbXinorbisLayoutsChange(Nil);

      eOOHTMLOutput.Text       := XSettings.Report.HTMLOutput;
      eOOXMLOutput.Text        := XSettings.Report.XMLOutput;
      eOOCSVOutput.Text        := XSettings.Report.CSVOutput;
      eOOTextOutput.Text       := XSettings.Report.TextOutput;

      // =======================================================================

      ShowModal;

      // =======================================================================

      if ModalResult = mrOK then begin

        XSettings.ftpOptions[ftpHost]          := eFTPHost.Text;
        XSettings.ftpOptions[ftpUsername]      := eFTPUsername.Text;
        XSettings.ftpOptions[ftpPassword]      := eFTPPassword.Text;
        XSettings.ftpOptions[ftpRemoteFolder]  := eFTPRemoteFolder.Text;
        XSettings.ftpOptions[ftpActualLink]    := eFTPLink.Text;
        XSettings.ftpOptions[ftpInitialFolder] := eFTPInitialFolder.Text;

        // ---------------------------------------------------------------------

        XSettings.Report.HTMLOutput    := eOOHTMLOutput.Text;
        XSettings.Report.XMLOutput     := eOOXMLOutput.Text;
        XSettings.Report.CSVOutput     := eOOCSVOutput.Text;
        XSettings.Report.TextOutput    := eOOTextOutput.Text;

        XSettings.Report.AutoSaveItem[1] := SliderStateToBoolean(cbADR_1.State);
        XSettings.Report.AutoSaveItem[2] := SliderStateToBoolean(cbADR_2.State);
        XSettings.Report.AutoSaveItem[3] := SliderStateToBoolean(cbADR_3.State);
        XSettings.Report.AutoSaveItem[4] := SliderStateToBoolean(cbADR_4.State);
        XSettings.Report.AutoSaveItem[5] := SliderStateToBoolean(cbADR_9.State);
        XSettings.Report.AutoSaveItem[6] := SliderStateToBoolean(cbADR_5.State);

        XSettings.Report.autosavemode    := SliderStateToBoolean(cbASDrive.State);
      end;

  finally
    Free;
  end;
end;


procedure TForm1.FormShow(Sender: TObject);
begin
  case opentabatstart of
    8 : pOutputOptions.BringToFront;
    9 : sbWebReportsClick(sbWebReports);
  else
    pOutputOptions.BringToFront;
  end;

  opentabatstart := -1;
end;


procedure TForm1.BuildXinorbisLayoutList(xinlayout : integer);
 begin
  if XSettings.Report.XinorbisOptions[cbXinorbisLayouts.ItemIndex + 1].Layout = 0 then
    rbXReportNormal.Checked   := True
  else
    rbXReportDetailed.Checked := True;
end;


procedure TForm1.ftpMainStatus(ASender: TObject; const AStatus: TIdStatus;
  const AStatusText: string);
begin
  lWebReportTest.Caption := AStatusText;
end;


procedure TForm1.ftpMainWorkBegin(ASender: TObject; AWorkMode: TWorkMode;
  AWorkCountMax: Int64);
begin
  lWebReportTest.Caption := XText[kUploading] + rsEllipsis;
end;


procedure TForm1.ftpMainWorkEnd(ASender: TObject; AWorkMode: TWorkMode);
begin
  lWebReportTest.Caption := XText[kUpload] + ': Finished.';
end;


procedure TForm1.rbXReportNormalClick(Sender: TObject);
begin
  if rbXReportNormal.Checked then
    XSettings.Report.XinorbisOptions[cbXinorbisLayouts.ItemIndex+1].Layout := 0
  else
    XSettings.Report.XinorbisOptions[cbXinorbisLayouts.ItemIndex+1].Layout := 1;
end;


procedure TForm1.sbWebReportsClick(Sender: TObject);
begin
  pWebReports.BringToFront;
end;


procedure TForm1.SetLanguage;
begin
  Caption := XText[kSettings];

  // ===========================================================================

  sbWebReports.Caption       := XText[kWebReports];

  sbAutoSave.Caption         := XText[kAutosave];

  sbReportTree.Caption       := XText[kTree];

  lOutputOptions.Caption     := XText[kReportOptions];
  lReportsAutosave.Caption   := XText[kReportOptions] + ': Autosave';
  lReportsCSV.Caption        := XText[kReportOptions] + ': CSV';
  lReportsHTML.Caption       := XText[kReportOptions] + ': HTML';
  lReportsTree.Caption       := XText[kReportOptions] + ': ' + XText[kTree];
  lReportsText.Caption       := XText[kReportOptions] + ': Text';
  lReportsXML.Caption        := XText[kReportOptions] + ': XML';
  lReportsXinorbis.Caption   := XText[kReportOptions] + ': Xinorbis';

  // ===========================================================================

//  bHelp.Caption              := XText[kHelp];
  bSave.Caption              := XText[kSave];
  bCancel.Caption            := XText[kCancel];

  // ===========================================================================

  lASDrive.Caption     := XText[kAutoSaveReports];

  lADR_5.Caption       := XText[kTree];

  lASOrganise.Caption  := XText[kOrganiseReports];

  // ===========================================================================

  Label6.Caption             := XText[kOpenInApplication];
  lTextDefaultOutput.Caption := XText[kOpenInApplication];
  Label8.Caption             := XText[kOpenInApplicationsDefault];
  Label29.Caption            := XText[kOpenInApplicationsDefault];

  // document options ==========================================================

  lDocOptions.Caption := XText[kDocOptions];

  // == report main menu =======================================================

  lReportMenuTree.Caption := XText[kTree];

  // == text tab ===============================================================


  // ===========================================================================

  gbXReportType.Caption     := XText[kChooseReportType];
  rbXReportNormal.Caption   := XText[kNormal];
  rbXReportDetailed.Caption := XText[kDetailed];

  cbXinorbisLayouts.Items.Add(XText[kAutoSave]);
  cbXinorbisLayouts.Items.Add(XText[kQuick]);
  cbXinorbisLayouts.Items.Add(XText[kOther]);
  cbXinorbisLayouts.Items.Add(XText[kCustom1]);
  cbXinorbisLayouts.Items.Add(XText[kCustom2]);
  cbXinorbisLayouts.Items.Add(XText[kCustom3]);

  cbXinorbisLayouts.ItemIndex := 0;

  // == FTP ====================================================================

  Label47.Caption := XText[kWebReports];
  Label48.Caption := XText[kFTPHost];
  Label49.Caption := XText[kFTPUsername];
  Label50.Caption := XText[kFTPPassword];
  Label53.Caption := XText[kInitialFolder];
  Label51.Caption := XText[kReportsFolder];
  Label52.Caption := XText[kReportsURL];
end;


procedure TForm1.BitBtn1Click(Sender: TObject);
 var
  ftperror : integer;
  filelist : TStringList;

 begin
  filelist := TStringList.Create;
  ftperror := 0;
  lWebReportTest.Visible := True;

  ftpMain.Host     := eFTPHost.Text;
  ftpMain.Username := eFTPUsername.Text;
  ftpMain.Password := eFTPPassword.Text;

  try
    ftpMain.Connect;

    if eFTPInitialFolder.Text <> '' then
      ftpMain.ChangeDir(eFTPInitialFolder.Text);

    if eFTPRemoteFolder.Text <> '' then begin
      ftpMain.List(filelist, eFTPRemoteFolder.Text, True);

      if filelist.Count = 0 then
        ftpMain.MakeDir(eFTPRemoteFolder.Text);

      ftpMain.ChangeDir(eFTPRemoteFolder.Text);
    end;

    ftpMain.Put(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) + '\ftptest.htm', 'ftptest.htm');
  except
    on E : Exception do begin
      ftperror := -1;

      TMSLogger.Error('FTP test exception: ' + E.Message + ' / ' + E.ClassName);
    end;
  end;

  if ftperror = 0 then begin
    TXWindows.ExecuteFile(0, eFTPLink.Text + '/ftptest.htm', '', '');
  end
  else
    ShowXDialog(XText[kError] + ': FTP upload',
                XText[kFTPUploadTestFailed],
                XDialogTypeWarning);

  FreeAndNil(filelist);
end;


procedure TForm1.BitBtn2Click(Sender: TObject);
begin
  if eFTPLink.Text <> '' then
    TXWindows.ExecuteFile(0, eFTPLink.Text, '', '');
end;


procedure TForm1.cbASDriveStateChanged(Sender: TObject;
  State: TAdvSmoothSliderState; Value: Double);
begin
  cbADR_1.Enabled := SliderStateToBoolean(State);
  cbADR_2.Enabled := SliderStateToBoolean(State);
  cbADR_3.Enabled := SliderStateToBoolean(State);
  cbADR_4.Enabled := SliderStateToBoolean(State);
  cbADR_9.Enabled := SliderStateToBoolean(State);
  cbADR_5.Enabled := SliderStateToBoolean(State);
end;


procedure TForm1.cbXinorbisLayoutsChange(Sender: TObject);
begin
  BuildXinorbisLayoutList(XSettings.Report.XinorbisOptions[(cbXinorbisLayouts.ItemIndex + 1)].Layout);
end;


procedure TForm1.SpeedButton10Click(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXOpenDialog.ExecuteExe('');

  if lFileName <> '' then
    eOOTextOutput.Text := lFileName;
end;


procedure TForm1.SpeedButton17Click(Sender: TObject);
 var
  i : integer;

 begin
  if Sender is TImage then
    i := TImage(Sender).Tag
  else begin
    i := TSpeedButton(Sender).Tag;

    TSpeedButton(Sender).Down := True;
  end;

  case i of
    CPageAutosave : pReportsAutosave.BringToFront;
    CPageCSV      : pReportsCSV.BringToFront;
    CPageHTML     : pReportsHTML.BringToFront;
    CPageXML      : pReportsXML.BringToFront;
    CPageText     : pReportsText.BringToFront;
    CPageTree     : pReportsTree.BringToFront;
    CPageXinorbis : pReportsXinorbis.BringToFront;
  end;
end;


procedure TForm1.SpeedButton1Click(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXOpenDialog.ExecuteExe('');

  if lFileName <> '' then
    eOOHTMLOutput.Text := lFileName;
end;


procedure TForm1.SpeedButton3Click(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXOpenDialog.ExecuteExe('');

  if lFileName <> '' then
    eOOXMLOutput.Text := lFileName;
end;


procedure TForm1.SpeedButton9Click(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXOpenDialog.ExecuteExe('');

  if lFileName <> '' then
    eOOCSVOutput.Text := lFileName;
end;


function TForm1.BooleanToSliderState(aBoolean : boolean): TAdvSmoothSliderState;
begin
  if aBoolean then
    Result := ssOn
  else
    Result := ssOff;
end;


function TForm1.SliderStateToBoolean(aState : TAdvSmoothSliderState): boolean;
begin
  if aState = ssOn then
    Result := True
  else
    Result := False;
end;


*/
