{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Form.EditTreeReport;


interface


uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, CheckLst, Buttons, ExtCtrls, AdvOfficeButtons,

  X.CTreeReports,

  X.Help,

  X.Utility, X.Settings, X.CReportOptions, X.LanguageHandler, X.SystemGlobal;


type
  TfrmEditTreeReport = class(TForm)
    Panel1: TPanel;
    Panel2: TPanel;
    sbSave: TSpeedButton;
    sbEditTreeLayout: TSpeedButton;
    cbTreeLayouts: TComboBox;
    Panel3: TPanel;
    gbCategories: TGroupBox;
    sbSetAll: TSpeedButton;
    SpeedButton2: TSpeedButton;
    gbOptions: TGroupBox;
    cbFileSize: TAdvOfficeCheckBox;
    cbAttributes: TAdvOfficeCheckBox;
    Memo1: TMemo;
    lReportsHTMLCustom: TGroupBox;
    sbPreview: TBitBtn;
    cbAutoRefresh: TCheckBox;
    clbCategoryOptions: TCheckListBox;
    sbCancel: TSpeedButton;
    SpeedButton1: TSpeedButton;
    procedure sbSetAllClick(Sender: TObject);
    procedure sbSaveClick(Sender: TObject);
    procedure sbEditTreeLayoutClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure sbPreviewClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormShow(Sender: TObject);
    procedure FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight,
      MaxWidth, MaxHeight: Integer);
    procedure clbCategoryOptionsClick(Sender: TObject);
    procedure sbCancelClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
  private
    FSource : integer;

    FTempReport : TTreeReportOptions;
    FOneOffCustom : boolean;

    procedure AutoRefresh;

    procedure BuildReport(var treeRL : TTreeReportOptions);
    procedure UpdateDisplay;
  public
    { Public declarations }
  end;

var
  frmEditTreeReport: TfrmEditTreeReport;


function DoTreeReport(aReportID, aSource : integer; aOneOffCustom : boolean): TTreeReportOptions;


implementation

{$R *.dfm}


uses
  X.Global, X.Dialogs.Dialog, X.Constants, X.Conversions;


function DoTreeReport(aReportID, aSource : integer; aOneOffCustom : boolean): TTreeReportOptions;
 begin
  with TfrmEditTreeReport.Create(Application) do
    try
      FSource       := aSource;
      FOneOffCustom := aOneOffCustom;

      cbTreeLayouts.ItemIndex := aReportID;

      sbEditTreeLayoutClick(Nil);

      if FOneOffCustom then begin
        sbEditTreeLayout.Visible := False;
        cbTreeLayouts.Visible    := False;
      end;

      ShowModal;

      if FOneOffCustom then begin
        Result := FTempReport;
      end;

    finally
      Free;
    end;
end;


procedure TfrmEditTreeReport.FormClose(Sender: TObject;
  var Action: TCloseAction);
var
  fd : TFormDetails;

begin
  fd.formID := _FormEditTreeReport;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  Action := caFree;
end;


procedure TfrmEditTreeReport.FormConstrainedResize(Sender: TObject;
  var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
begin
  MinWidth  := 600;
  MinHeight := 510;
end;

procedure TfrmEditTreeReport.FormCreate(Sender: TObject);
var
  t : integer;
  fd : TFormDetails;

begin
  fd := XSettings.LoadFormDetails(_FormEditTreeReport);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  // ===========================================================================

  Caption                  := XText[rsCustomise] + ' ' + XText[rsTree] + ' ' + XText[rsReport];

  sbSave.Caption           := XText[rsSave];
  sbCancel.Caption         := XText[rsCancel];
  sbEditTreeLayout.Caption := XText[rsEdit];

  sbPreview.Caption        := XText[rsPreview];
  cbAutoRefresh.Caption    := XText[rsAutoRefresh];

  cbTreeLayouts.Items.Add(XText[rsAutoSave]);
  cbTreeLayouts.Items.Add(XText[rsQuick]);
  cbTreeLayouts.Items.Add(XText[rsOther]);
  cbTreeLayouts.Items.Add(XText[rsCustom1]);
  cbTreeLayouts.Items.Add(XText[rsCustom2]);
  cbTreeLayouts.Items.Add(XText[rsCustom3]);

  cbTreeLayouts.ItemIndex := 0;

  // ===========================================================================

  gbOptions.Caption    := XText[rsOutputOptions];
  cbFileSize.Caption   := XText[rsFileSize];
  cbAttributes.Caption := XText[rsFileAttributes];
  gbCategories.Caption := XText[rsSelectCategories];

  for t := 1 to 19 do
    clbCategoryOptions.Items.Add(TypeDescriptions[t]);
end;


procedure TfrmEditTreeReport.FormShow(Sender: TObject);
begin
  {}
end;


procedure TfrmEditTreeReport.UpdateDisplay;
var
  t : integer;

begin
  for t := 1 to 19 do begin
    if FTempReport.CategoryList[t] = '1' then
      clbCategoryOptions.Checked[t - 1] := True
    else
      clbCategoryOptions.Checked[t - 1] := False;
  end;

  cbFileSize.Checked   := FTempReport.IncludeSize;
  cbAttributes.Checked := FTempReport.IncludeAttributes;
end;


procedure TfrmEditTreeReport.sbCancelClick(Sender: TObject);
begin
  FTempReport.Layout := '$';

  ModalResult := mrCancel;
end;


procedure TfrmEditTreeReport.sbEditTreeLayoutClick(Sender: TObject);
begin
  FTempReport := XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1];

  if FTempReport.Layout <> '' then begin
    UpdateDisplay;

    sbPreviewClick(Nil);
  end;
end;


procedure TfrmEditTreeReport.sbPreviewClick(Sender: TObject);
var
  lReportOutput : TStringList;

begin
  lReportOutput := TStringList.Create;

  BuildReport(FTempReport);

  GReportTree.GenerateTreeReport(FSource, lReportOutput, FTempReport);

  Memo1.Clear;

  Memo1.Lines.Assign(lReportOutput);

  FreeAndNil(lReportOutput);
end;


procedure TfrmEditTreeReport.sbSaveClick(Sender: TObject);
begin
  BuildReport(FTempReport);

  if not(FOneOffCustom) then
    XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1] := FTempReport;

  ModalResult := mrOK;
end;


procedure TfrmEditTreeReport.sbSetAllClick(Sender: TObject);
 var
  t : integer;
  lMode : boolean;

 begin
  if TSpeedButton(Sender).Tag = 0 then
    lMode := True
  else
    lMode := False;

  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := lMode;

  AutoRefresh;
end;


procedure TfrmEditTreeReport.SpeedButton1Click(Sender: TObject);
begin
  THelp.OpenHelpPage('report_tree.htm');
end;


procedure TfrmEditTreeReport.BuildReport(var treeRL : TTreeReportOptions);
 var
  t : integer;
  s : string;

 begin
  s := '';

  for t := 1 to 19 do
    s := s + IntToStr(TConvert.BoolToInteger(clbCategoryOptions.Checked[t - 1]));

  treeRL.CategoryList      := s;
  treeRL.IncludeSize       := cbFileSize.Checked;
  treeRL.IncludeAttributes := cbAttributes.Checked;
end;


procedure TfrmEditTreeReport.clbCategoryOptionsClick(Sender: TObject);
begin
  AutoRefresh;
end;


procedure TfrmEditTreeReport.AutoRefresh;
begin
  if cbAutoRefresh.Checked then
    sbPreviewClick(Nil);
end;


end.
