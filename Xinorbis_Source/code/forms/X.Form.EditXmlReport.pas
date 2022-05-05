{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Form.EditXmlReport;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, Buttons, ExtCtrls,

  X.Help,

  X.Settings,

  X.CReportOptions, X.CXMLReports,

  X.Frame.Reports,

  X.LanguageHandler, AdvSmoothSlider;


const
 XMLItemsCount = 17;


type
  TfrmEditXMLReport = class(TForm)
    Panel3: TPanel;
    Panel1: TPanel;
    Label1: TLabel;
    sbDown: TSpeedButton;
    sbUp: TSpeedButton;
    sbRemove: TSpeedButton;
    Label2: TLabel;
    Label3: TLabel;
    lImportant: TLabel;
    GroupBox1: TGroupBox;
    lSI1: TLabel;
    lSI2: TLabel;
    lSI3: TLabel;
    lSI4: TLabel;
    lSI5: TLabel;
    lSI8: TLabel;
    lSI7: TLabel;
    lSI6: TLabel;
    lSI10: TLabel;
    lSI11: TLabel;
    lSI9: TLabel;
    lSI12: TLabel;
    lSI13: TLabel;
    lSI14: TLabel;
    lSI15: TLabel;
    lSI16: TLabel;
    Label6: TLabel;
    Label5: TLabel;
    Label4: TLabel;
    lbSummaryLayout: TListBox;
    Panel2: TPanel;
    sbSave: TSpeedButton;
    sbEditXMLLayout: TSpeedButton;
    cbXMLLayouts: TComboBox;
    Memo1: TMemo;
    lReportsHTMLCustom: TGroupBox;
    sbPreview: TBitBtn;
    cbAutoRefresh: TCheckBox;
    lXMLAutoOpen: TLabel;
    cbXMLAutoOpen: TAdvSmoothSlider;
    cbXMLData: TComboBox;
    Label39: TLabel;
    SpeedButton1: TSpeedButton;
    lSI17: TLabel;
    procedure sbRemoveClick(Sender: TObject);
    procedure sbUpClick(Sender: TObject);
    procedure sbDownClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure lbSummaryLayoutClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure sbEditXMLLayoutClick(Sender: TObject);
    procedure FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight,
      MaxWidth, MaxHeight: Integer);
    procedure sbPreviewClick(Sender: TObject);
    procedure sbSaveClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
  private
    FSource : integer;

    LayoutItems : array[1..XMLItemsCount] of TLabel;

    FTempReport : TXMLReportOptions;

    procedure AutoRefresh;
    procedure UpdateDisplay;

    procedure BuildReport(var textRL : TXMLReportOptions);
  public
    { Public declarations }
  end;

var
  frmEditXMLReport: TfrmEditXMLReport;


procedure DoXMLReport(aReportID, aSource : integer);


implementation

{$R *.dfm}

uses X.Utility,

     X.Global, X.Constants;


procedure DoXMLReport(aReportID, aSource : integer);
 begin
  with TfrmEditXMLReport.Create(Application) do
    try
      FSource := aSource;

      cbXMLLayouts.ItemIndex := aReportID;

      sbEditXMLLayoutClick(Nil);

      ShowModal;
    finally
      Free;
    end;
end;


procedure TfrmEditXMLReport.FormCreate(Sender: TObject);
var
  t : integer;
  fd : TFormDetails;

begin
  fd := XSettings.LoadFormDetails(_FormEditXMLReport);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  // ===========================================================================

  Caption                  := XText[rsCustomise] + ' XML ' + XText[rsReport];

  sbSave.Caption           := XText[rsSave];
//  sbCancel.Caption         := XText[rsCancel];
  sbEditXMLLayout.Caption  := XText[rsEdit];

  Label1.Caption           := XText[rsAvailable] + ' XML ' + XText[rsReportItems];
  Label2.Caption           := 'XML ' + XText[rsReportLayout];
  GroupBox1.Caption        := XText[rsClickToAdd];
  lImportant.Caption       := XText[rsMaySlowDownReport];

  Label39.Caption          := XText[rsWhichData];
  lXMLAutoOpen.Caption     := XText[rsAutoOpen];

  sbPreview.Caption        := XText[rsPreview];
  cbAutoRefresh.Caption    := XText[rsAutoRefresh];

  cbXMLLayouts.Items.Add(XText[rsAutoSave]);
  cbXMLLayouts.Items.Add(XText[rsQuick]);
  cbXMLLayouts.Items.Add(XText[rsOther]);
  cbXMLLayouts.Items.Add(XText[rsCustom1]);
  cbXMLLayouts.Items.Add(XText[rsCustom2]);
  cbXMLLayouts.Items.Add(XText[rsCustom3]);

  cbXMLLayouts.ItemIndex := 0;

  cbXMLData.Items.Add(XText[rsReport]);
  cbXMLData.Items.Add(XText[rsFullFileList]);

  cbXMLData.ItemIndex := 0;

  // ===========================================================================

  LayoutItems[1]  := lSI1;   LayoutItems[2]  := lSI2;
  LayoutItems[3]  := lSI3;   LayoutItems[4]  := lSI4;
  LayoutItems[5]  := lSI5;   LayoutItems[6]  := lSI6;
  LayoutItems[7]  := lSI7;   LayoutItems[8]  := lSI8;
  LayoutItems[9]  := lSI9;   LayoutItems[10] := lSI10;
  LayoutItems[11] := lSI11;  LayoutItems[12] := lSI12;
  LayoutItems[13] := lSI13;  LayoutItems[14] := lSI14;
  LayoutItems[15] := lSI15;  LayoutItems[16] := lSI16;
  LayoutItems[17] := lSI17;

  for t := 1 to XMLItemsCount do begin
    LayoutItems[t].Caption := GenericReportItems[t];
  end;
end;


procedure TfrmEditXMLReport.FormClose(Sender: TObject; var Action: TCloseAction);
var
  fd : TFormDetails;

begin
  fd.formID := _FormEditXMLReport;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  Action := caFree;
end;


procedure TfrmEditXMLReport.FormConstrainedResize(Sender: TObject; var MinWidth,
  MinHeight, MaxWidth, MaxHeight: Integer);
begin
  MinWidth  := 700;
  MinHeight := 515;
end;


procedure TfrmEditXMLReport.AutoRefresh;
begin
  if cbAutoRefresh.Checked then
    sbPreviewClick(Nil);
end;


procedure TfrmEditXMLReport.UpdateDisplay;
var
  t, lLayoutID : integer;
  s : string;

 begin
  s := '';

  lbSummaryLayout.Clear;

  for t := 1 to length(FTempReport.Layout) do begin
    if FTempReport.Layout[t] = ':' then begin
      lLayoutID := StrToIntDef(s, 99);

      if lLayoutID <= XMLItemsCount then begin
        lbSummaryLayout.Items.Add(LayoutItems[lLayoutID].Caption);
      end;

      s := '';
    end
    else
      s := s + FTempReport.Layout[t];
  end;

  cbXMLData.ItemIndex := FTempReport.XMLData;

  if XSettings.Report.XMLOptions[cbXMLLayouts.ItemIndex + 1].XMLAutoOpen then
    cbXMLAutoOpen.State := ssOn
  else
    cbXMLAutoOpen.State := ssOff;
end;


procedure TfrmEditXMLReport.sbRemoveClick(Sender: TObject);
 begin
  lbSummaryLayout.DeleteSelected;

  AutoRefresh;
end;


procedure TfrmEditXMLReport.sbSaveClick(Sender: TObject);
begin
  // save report stuff =========================================================

  BuildReport(FTempReport);

  XSettings.Report.XMLOptions[cbXMLLayouts.ItemIndex + 1] := FTempReport;

  ModalResult := mrOK;
end;


procedure TfrmEditXMLReport.sbUpClick(Sender: TObject);
 var
  a : integer;

 begin
  if lbSummaryLayout.ItemIndex > 0 then begin
    a := lbSummaryLayout.ItemIndex - 1;

    lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex - 1);

    lbSummaryLayout.ItemIndex := a;

    AutoRefresh;
  end;
end;


procedure TfrmEditXMLReport.SpeedButton1Click(Sender: TObject);
begin
  THelp.OpenHelpPage('report_xml.htm');
end;


procedure TfrmEditXMLReport.sbDownClick(Sender: TObject);
 var
  a : integer;

 begin
  if lbSummaryLayout.ItemIndex <> -1 then begin
    if lbSummaryLayout.ItemIndex < lbSummaryLayout.Count - 1 then begin
      a := lbSummaryLayout.ItemIndex + 1;

      lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex + 1);

      lbSummaryLayout.ItemIndex := a;

      AutoRefresh;
    end;
  end;
end;


procedure TfrmEditXMLReport.sbEditXMLLayoutClick(Sender: TObject);
begin
  FTempReport := XSettings.Report.XMLOptions[cbXMLLayouts.ItemIndex + 1];

  if FTempReport.Layout <> '' then begin
    UpdateDisplay;

    sbPreviewClick(Nil);
  end;
end;


procedure TfrmEditXMLReport.sbPreviewClick(Sender: TObject);
var
  lReportOutput : TStringList;
  lTempCaption : string;

begin
  lTempCaption := Caption;
  Caption      := Caption + ' ' + XText[rsPleaseWait] + '...';

  // ===========================================================================

  lReportOutput := TStringList.Create;

  BuildReport(FTempReport);

  if FTempReport.XMLData = CDataSummary then
    GReportXML.GenerateXMLOutput(FSource, FTempReport, lReportOutput)
  else
    GReportXML.GenerateXMLOutputFileList('',  lReportOutput, FSource, LayoutUnknown);

  Memo1.Clear;

  Memo1.Lines.Assign(lReportOutput);

  FreeAndNil(lReportOutput);

  // ===========================================================================

  Caption := lTempCaption;
end;


procedure TfrmEditXMLReport.lbSummaryLayoutClick(Sender: TObject);
 var
  status : boolean;

 begin
  if lbSummaryLayout.ItemIndex = -1 then
    status := False
  else
    status := True;

  sbUp.Enabled     := status;
  sbDown.Enabled   := status;
  sbRemove.Enabled := status;
end;


procedure TfrmEditXMLReport.BuildReport(var textRL : TXMLReportOptions);
 var
  t,z,idx : integer;
  s : string;

 begin
  s := '';

  for t := 0 to lbSummaryLayout.Count - 1 do begin
    idx := 0;

    for z := 1 to XMLItemsCount do begin
      if LayoutItems[z].Caption = lbSummaryLayout.Items[t] then idx := z;
    end;

    s := s + IntToStr(idx) + ':';
  end;

  textRL.Layout := s;

  textRL.XMLData := cbXMLData.ItemIndex;

  if cbXMLAutoOpen.State = ssOn then
    textRL.XMLAutoOpen := True
  else
    textRL.XMLAutoOpen := False;
end;


end.
