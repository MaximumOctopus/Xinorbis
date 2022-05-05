{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Form.EditCSVReport;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, ExtCtrls,

  X.Constants, X.CCSVPreview, X.Help,

  X.Utility, CheckLst, X.Settings, X.CReportOptions, X.LanguageHandler,
  X.SystemGlobal, AdvSmoothSlider;

const
 TextItemsCount = 16;

type
  TfrmEditCSVReport = class(TForm)
    Panel1: TPanel;
    Panel2: TPanel;
    sbSave: TSpeedButton;
    sbEditCSVLayout: TSpeedButton;
    cbCSVLayouts: TComboBox;
    Panel3: TPanel;
    lReportsHTMLCustom: TGroupBox;
    sbPreview: TBitBtn;
    cbAutoRefresh: TCheckBox;
    lCSVTitle: TLabel;
    cbCSVTitles: TAdvSmoothSlider;
    lCSVTitles: TLabel;
    cbCSVSeparator: TComboBox;
    cbCSVData: TComboBox;
    cbCSVUnits: TComboBox;
    cbCSVAutoOpen: TAdvSmoothSlider;
    lCSVAutoOpen: TLabel;
    lcsvs: TLabel;
    Label2: TLabel;
    Label27: TLabel;
    sbCancel: TSpeedButton;
    Memo1: TMemo;
    SpeedButton1: TSpeedButton;
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure sbEditCSVLayoutClick(Sender: TObject);
    procedure sbSaveClick(Sender: TObject);
    procedure sbPreviewClick(Sender: TObject);
    procedure FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight,
      MaxWidth, MaxHeight: Integer);
    procedure cbCSVSeparatorChange(Sender: TObject);
    procedure cbCSVTitlesStateChanged(Sender: TObject;
      State: TAdvSmoothSliderState; Value: Double);
    procedure sbCancelClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
  private
    FTempReport : TCSVReportOptions;
    FOneOffCustom : boolean;

    procedure UpdateDisplay;

    procedure BuildReport(var textRL : TCSVReportOptions);

    procedure AutoRefresh;
  public
  end;


var
  frmEditCSVReport: TfrmEditCSVReport;


function DoCSVReport(aReportID : integer; aOneOffCustom : boolean): TCSVReportOptions;


implementation

{$R *.dfm}


uses
  X.Global, X.Dialogs.Dialog, X.Conversions;


function DoCSVReport(aReportID : integer; aOneOffCustom : boolean): TCSVReportOptions;
 begin
  with TfrmEditCSVReport.Create(Application) do
    try
      FOneOffCustom := aOneOffCustom;

      cbCSVLayouts.ItemIndex := aReportID;

      sbEditCSVLayoutClick(Nil);

      if FOneOffCustom then begin
        sbEditCSVLayout.Visible := False;
        cbCSVLayouts.Visible    := False;
      end;

      ShowModal;

      if FOneOffCustom then begin
        Result := FTempReport;
      end;

    finally
      Free;
    end;
end;


procedure TfrmEditCSVReport.FormCreate(Sender: TObject);
var
  fd : TFormDetails;

begin
  fd := XSettings.LoadFormDetails(_FormEditCSVReport);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  // ===========================================================================

  Caption                  := XText[rsCustomise] + ' CSV ' + XText[rsReport];

  sbSave.Caption           := XText[rsSave];
  sbCancel.Caption         := XText[rsCancel];
  sbEditCSVLayout.Caption  := XText[rsEdit];

  sbPreview.Caption        := XText[rsPreview];
  cbAutoRefresh.Caption    := XText[rsAutoRefresh];

  // ===========================================================================

  cbCSVLayouts.Items.Add(XText[rsAutoSave]);
  cbCSVLayouts.Items.Add(XText[rsQuick]);
  cbCSVLayouts.Items.Add(XText[rsOther]);
  cbCSVLayouts.Items.Add(XText[rsCustom1]);
  cbCSVLayouts.Items.Add(XText[rsCustom2]);
  cbCSVLayouts.Items.Add(XText[rsCustom3]);

  cbCSVLayouts.ItemIndex := 0;

  //============================================================================

  cbCSVSeparator.Items.Add('Comma (,)');
  cbCSVSeparator.Items.Add('Tab');
  cbCSVSeparator.Items.Add('Pling (|)');
  cbCSVSeparator.ItemIndex := 0;

  lcsvs.Caption        := XText[rsSeparator];
  lCSVTitle.Caption    := XText[rsDefaultCSVOutputSettings];
  lCSVTitles.Caption   := XText[rsIncludeColumnTitles];
  Label2.Caption       := XText[rsWhichData];
  Label27.Caption      := XText[rsShowSizesIn];
  lCSVAutoOpen.Caption := XText[rsAutoOpen];

  cbCSVData.Items.Add(XText[rsReport]);
  cbCSVData.Items.Add(XText[rsFullFileList]);

  cbCSVUnits.Items.Add(XText[rsMostConvenient]);
  cbCSVUnits.Items.Add(XText[rsBytes]);
  cbCSVUnits.Items.Add(XText[rsKilobytes]);
  cbCSVUnits.Items.Add(XText[rsMegabytes]);
end;


procedure TfrmEditCSVReport.FormClose(Sender: TObject; var Action: TCloseAction);
var
  fd : TFormDetails;

begin
  fd.formID := _FormEditCSVReport;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  Action := caFree;
end;


procedure TfrmEditCSVReport.FormConstrainedResize(Sender: TObject;
  var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
begin
  MinWidth  := 500;
  MinHeight := 410;
end;


procedure TfrmEditCSVReport.AutoRefresh;
begin
  if cbAutoRefresh.Checked then
    sbPreviewClick(Nil);
end;


procedure TfrmEditCSVReport.UpdateDisplay;
begin
  cbCSVSeparator.ItemIndex := FTempReport.CSVSeparator;
  cbCSVData.ItemIndex      := FTempReport.CSVData;
  cbCSVUnits.ItemIndex     := FTempReport.CSVUnits;

  if FTempReport.CSVTitles then
    cbCSVTitles.State := ssOn
  else
    cbCSVTitles.State := ssOff;

  if FTempReport.CSVAutoOpen then
    cbCSVAutoOpen.State := ssOn
  else
    cbCSVAutoOpen.State := ssOff;
end;


procedure TfrmEditCSVReport.BuildReport(var textRL : TCSVReportOptions);
begin
  textRL.CSVSeparator  := cbCSVSeparator.ItemIndex;
  textRL.CSVData       := cbCSVData.ItemIndex;
  textRL.CSVUnits      := cbCSVUnits.ItemIndex;

  if cbCSVTitles.State = ssOn then
    textRL.CSVTitles := True
  else
    textRL.CSVTitles := False;

  if cbCSVAutoOpen.State = ssOn  then
    textRL.CSVAutoOpen := True
  else
    textRL.CSVAutoOpen := False;
end;


procedure TfrmEditCSVReport.cbCSVSeparatorChange(Sender: TObject);
begin
  AutoRefresh;
end;


procedure TfrmEditCSVReport.cbCSVTitlesStateChanged(Sender: TObject;
  State: TAdvSmoothSliderState; Value: Double);
begin
  AutoRefresh;
end;


procedure TfrmEditCSVReport.sbSaveClick(Sender: TObject);
begin
  // save report stuff =========================================================

  BuildReport(FTempReport);

  // save colours ==============================================================

  if not(FOneOffCustom) then
    XSettings.Report.CSVOptions[cbCSVLayouts.ItemIndex + 1] := FTempReport;

  ModalResult := mrOK;
end;


procedure TfrmEditCSVReport.SpeedButton1Click(Sender: TObject);
begin
  THelp.OpenHelpPage('report_csv.htm');
end;


procedure TfrmEditCSVReport.sbCancelClick(Sender: TObject);
begin
  FTempReport.Layout := '$';

  ModalResult := mrCancel;
end;


procedure TfrmEditCSVReport.sbEditCSVLayoutClick(Sender: TObject);
begin
  FTempReport := XSettings.Report.CSVOptions[cbCSVLayouts.ItemIndex + 1];

  UpdateDisplay;

  sbPreviewClick(Nil);
end;


procedure TfrmEditCSVReport.sbPreviewClick(Sender: TObject);
var
  lList : TStringList;

begin
  lList := TStringList.Create;

  BuildReport(FTempReport);

  TCSVPreview.Get(FTempReport, lList);

  Memo1.Clear;

  Memo1.Lines.Assign(lList);

  lList.Free;
end;


end.
