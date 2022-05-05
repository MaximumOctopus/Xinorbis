// (c) Paul Alan Freshney 2006-2011
//
// Modified: December 16th 2010
//
// 357

unit X.Form.EditTextReport;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, Buttons, ExtCtrls,

  X.Constants, X.Help,

  X.CTextReports,

  X.Utility, CheckLst, X.Settings, X.CReportOptions, X.LanguageHandler,
  X.SystemGlobal;

const
 TextItemsCount = 17;

type
  TfrmEditTextReport = class(TForm)
    Panel1: TPanel;
    Panel2: TPanel;
    sbSave: TSpeedButton;
    sbEditTextLayout: TSpeedButton;
    cbTextLayouts: TComboBox;
    Panel3: TPanel;
    Label1: TLabel;
    sbRemove: TSpeedButton;
    sbUp: TSpeedButton;
    sbDown: TSpeedButton;
    Label2: TLabel;
    Label3: TLabel;
    lImportant: TLabel;
    Label6: TLabel;
    Label5: TLabel;
    Label4: TLabel;
    pCategoryOptions: TPanel;
    bCloseAC: TSpeedButton;
    lAC: TLabel;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    clbCategoryOptions: TCheckListBox;
    GroupBox1: TGroupBox;
    lSI1: TLabel;
    lSI2: TLabel;
    lSI3: TLabel;
    lSI4: TLabel;
    lSI5: TLabel;
    lSI8: TLabel;
    lSI7: TLabel;
    lSI6: TLabel;
    lSI12: TLabel;
    lSI11: TLabel;
    lSI10: TLabel;
    lSI9: TLabel;
    lSI13: TLabel;
    lSI14: TLabel;
    lSI15: TLabel;
    lSI16: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    lbSummaryLayout: TListBox;
    bAdvanced: TBitBtn;
    lReportsHTMLCustom: TGroupBox;
    sbPreview: TBitBtn;
    cbAutoRefresh: TCheckBox;
    Memo1: TMemo;
    sbCancel: TSpeedButton;
    SpeedButton3: TSpeedButton;
    lSI17: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure sbRemoveClick(Sender: TObject);
    procedure sbUpClick(Sender: TObject);
    procedure sbDownClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure lbSummaryLayoutDblClick(Sender: TObject);
    procedure lSI1Click(Sender: TObject);
    procedure lbSummaryLayoutClick(Sender: TObject);
    procedure bAdvancedClick(Sender: TObject);
    procedure bCloseACClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    procedure sbEditTextLayoutClick(Sender: TObject);
    procedure sbSaveClick(Sender: TObject);
    procedure sbPreviewClick(Sender: TObject);
    procedure FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight,
      MaxWidth, MaxHeight: Integer);
    procedure Panel2Click(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
  private
    FSource : integer;

    LayoutItems : array[1..TextItemsCount] of TLabel;

    FTempReport : TTextReportOptions;
    FOneOffCustom : boolean;

    procedure UpdateDisplay;

    procedure BuildReport(var textRL : TTextReportOptions);

    procedure AutoRefresh;
  public
  end;


var
  frmEditTextReport: TfrmEditTextReport;


function DoTextReport(aReportID, aSource : integer; aOneOffCustom : boolean): TTextReportOptions;


implementation

{$R *.dfm}


uses
  X.Global, X.Dialogs.Dialog, X.Conversions, X.Frame.Reports;


function DoTextReport(aReportID, aSource : integer; aOneOffCustom : boolean): TTextReportOptions;
 begin
  with TfrmEditTextReport.Create(Application) do
    try
      FSource       := aSource;
      FOneOffCustom := aOneOffCustom;

      cbTextLayouts.ItemIndex := aReportID;

      sbEditTextLayoutClick(Nil);

      if FOneOffCustom then begin
        sbEditTextLayout.Visible := False;
        cbTextLayouts.Visible    := False;
      end;

      ShowModal;

      if FOneOffCustom then begin
        Result := FTempReport;
      end;

    finally
      Free;
    end;
end;


procedure TfrmEditTextReport.FormCreate(Sender: TObject);
var
  t : integer;
  fd : TFormDetails;

begin
  fd := XSettings.LoadFormDetails(_FormEditTextReport);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  // ===========================================================================

  Caption                  := XText[rsCustomise] + ' ' + XText[rsText] + ' ' + XText[rsReport];

  sbSave.Caption           := XText[rsSave];
  sbCancel.Caption         := XText[rsCancel];
  sbEditTextLayout.Caption := XText[rsEdit];

  sbPreview.Caption        := XText[rsPreview];
  cbAutoRefresh.Caption    := XText[rsAutoRefresh];

  // ===========================================================================

  LayoutItems[1] := lSI1;   LayoutItems[2] := lSI2;
  LayoutItems[3] := lSI3;   LayoutItems[4] := lSI4;
  LayoutItems[5] := lSI5;   LayoutItems[6] := lSI6;
  LayoutItems[7] := lSI7;   LayoutItems[8] := lSI8;
  LayoutItems[9] := lSI9;   LayoutItems[10] := lSI10;
  LayoutItems[11] := lSI11; LayoutItems[12] := lSI12;
  LayoutItems[13] := lSI13; LayoutItems[14] := lSI14;
  LayoutItems[15] := lSI15; LayoutItems[16] := lSI16;
  LayoutItems[17] := lSI17;

  for t := 1 to TextItemsCount do begin
    LayoutItems[t].Caption := GenericReportItems[t];
  end;

  cbTextLayouts.Items.Add(XText[rsAutoSave]);
  cbTextLayouts.Items.Add(XText[rsQuick]);
  cbTextLayouts.Items.Add(XText[rsOther]);
  cbTextLayouts.Items.Add(XText[rsCustom1]);
  cbTextLayouts.Items.Add(XText[rsCustom2]);
  cbTextLayouts.Items.Add(XText[rsCustom3]);

  cbTextLayouts.ItemIndex := 0;

  for t := 1 to 19 do
    clbCategoryOptions.Items.Add(TypeDescriptions[t]);

  //== languagey stuff =========================================================

  lImportant.Caption       := XText[rsMaySlowDownReport];
  Label1.Caption           := XText[rsAvailable] + ' ' + XText[rsText] + ' ' + XText[rsReportItems];
  Label2.Caption           := XText[rsText] + ' ' + XText[rsReportLayout];
  bCloseAC.Caption         := XText[rsHide];
  lAC.Caption              := XText[rsSelectCategories];
  bAdvanced.Caption        := XText[rsCategories];
end;


procedure TfrmEditTextReport.FormClose(Sender: TObject; var Action: TCloseAction);
var
  fd : TFormDetails;

begin
  fd.formID := _FormEditHTMLReport;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  Action := caFree;
end;


procedure TfrmEditTextReport.FormConstrainedResize(Sender: TObject;
  var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
begin
  MinWidth  := 700;
  MinHeight := 524;
end;


procedure TfrmEditTextReport.AutoRefresh;
begin
  if cbAutoRefresh.Checked then
    sbPreviewClick(Nil);
end;


procedure TfrmEditTextReport.UpdateDisplay;
var
  t, lLayoutID : integer;
  s : string;

begin
  s := '';

  lbSummaryLayout.Clear;

  for t := 1 to length(FTempReport.Layout) do begin
    if FTempReport.Layout[t] = ':' then begin
      lLayoutID := StrToIntDef(s, 99);

      if lLayoutID <= TextItemsCount then begin
        lbSummaryLayout.Items.Add(LayoutItems[lLayoutID].Caption);
      end;

      s := '';
    end
    else
      s := s + FTempReport.Layout[t];
  end;
end;


procedure TfrmEditTextReport.BuildReport(var textRL : TTextReportOptions);
 var
  t,z,idx : integer;
  s : string;

 begin
  s := '';

  for t := 0 to lbSummaryLayout.Count - 1 do begin
    idx := 0;

    for z := 1 to TextItemsCount do begin
      if LayoutItems[z].Caption = lbSummaryLayout.Items[t] then idx := z;
    end;

    s := s + IntToStr(idx) + ':';
  end;

  textRL.Layout := s;

  s := '';
  for t := 1 to 19 do
    s := s + IntToStr(TConvert.BoolToInteger(clbCategoryOptions.Checked[t - 1]));

  textRL.CategoryList := s;
end;


procedure TfrmEditTextReport.sbRemoveClick(Sender: TObject);
 begin
  lbSummaryLayout.DeleteSelected;

  AutoRefresh;
end;


procedure TfrmEditTextReport.sbSaveClick(Sender: TObject);
begin
  // save report stuff =========================================================

  BuildReport(FTempReport);

  // save colours ==============================================================

  if not(FOneOffCustom) then
    XSettings.Report.TextOptions[cbTextLayouts.ItemIndex + 1] := FTempReport;

  ModalResult := mrOK;
end;


procedure TfrmEditTextReport.sbUpClick(Sender: TObject);
var
  a : integer;

begin
  if lbSummaryLayout.ItemIndex > 0 then begin
    a:=lbSummaryLayout.ItemIndex - 1;

    lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex - 1);

    lbSummaryLayout.ItemIndex := a;

    AutoRefresh;
  end;
end;


procedure TfrmEditTextReport.sbDownClick(Sender: TObject);
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


procedure TfrmEditTextReport.sbEditTextLayoutClick(Sender: TObject);
begin
  FTempReport := XSettings.Report.TextOptions[cbTextLayouts.ItemIndex + 1];

  if FTempReport.Layout <> '' then begin
    UpdateDisplay;

    sbPreviewClick(Nil);
  end;
end;


procedure TfrmEditTextReport.sbPreviewClick(Sender: TObject);
var
  lReportOutput : TStringList;

begin
  lReportOutput := TStringList.Create;

  BuildReport(FTempReport);

  GReportText.GenerateTextReport(FSource, lReportOutput, FTempReport);

  Memo1.Clear;

  Memo1.Lines.Assign(lReportOutput);

  FreeAndNil(lReportOutput);
end;


procedure TfrmEditTextReport.lbSummaryLayoutDblClick(Sender: TObject);
 begin
  lbSummaryLayout.DeleteSelected;

  sbRemove.Enabled := False;
  sbUp.Enabled     := False;
  sbDown.Enabled   := False;

  AutoRefresh;
end;


procedure TfrmEditTextReport.lSI1Click(Sender: TObject);
 begin
  if lbSummaryLayout.Items.IndexOf(TLabel(Sender).Caption) = -1 then begin
    lbSummaryLayout.Items.Add(TLabel(Sender).Caption);

    AutoRefresh;
  end;
end;


procedure TfrmEditTextReport.Panel2Click(Sender: TObject);
begin
  FTempReport.Layout := '$';

  ModalResult := mrCancel;
end;

procedure TfrmEditTextReport.lbSummaryLayoutClick(Sender: TObject);
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

  if status then begin
    if lbSummaryLayout.Items[lbSummaryLayout.ItemIndex] = lSI7.Caption then
      bAdvanced.Enabled := True
    else
      bAdvanced.Enabled := False;
  end
  else
    bAdvanced.Enabled := False;
end;


procedure TfrmEditTextReport.bAdvancedClick(Sender: TObject);
 begin
  pCategoryOptions.BringToFront;
  pCategoryOptions.Visible := True;
end;


procedure TfrmEditTextReport.bCloseACClick(Sender: TObject);
 begin
  pCategoryOptions.SendToBack;
  pCategoryOptions.Visible := False;
end;


procedure TfrmEditTextReport.SpeedButton1Click(Sender: TObject);
 var
  t : integer;

 begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := True;
end;


procedure TfrmEditTextReport.SpeedButton2Click(Sender: TObject);
 var
  t : integer;

 begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := False;
end;


procedure TfrmEditTextReport.SpeedButton3Click(Sender: TObject);
begin
  THelp.OpenHelpPage('report_text.htm');
end;

end.
