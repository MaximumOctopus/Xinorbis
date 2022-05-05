{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Form.EditHTMLReport;

interface

uses
  System.UITypes, Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics, dialogs,
  Vcl.Controls, Vcl.Forms, AdvSmoothSlider, Vcl.ExtCtrls, inifiles,
  Vcl.StdCtrls, Vcl.Buttons, Vcl.CheckLst, Vcl.OleCtrls, SHDocVw,

  TMSLogging,

  X.Dialogs.Colour, X.Dialogs.Load, X.Dialogs.Save,

  X.CReportOptions, X.CHTMLPreview, X.CReportColours,

  X.Constants, X.Conversions, X.Help,

  X.LanguageHandler, X.Settings, X.Global, X.SystemGlobal;

const
  HTMLItemsCount = 17;


type
  TfrmEditHTMLReport = class(TForm)
    wbHTML: TWebBrowser;
    Panel3: TPanel;
    Panel2: TPanel;
    sbSave: TSpeedButton;
    sbEditHTMLLayout: TSpeedButton;
    cbHTMLLayouts: TComboBox;
    Panel1: TPanel;
    Label2: TLabel;
    Label5: TLabel;
    sbRemove: TSpeedButton;
    sbUp: TSpeedButton;
    sbDown: TSpeedButton;
    Label10: TLabel;
    lImportant: TLabel;
    pCategoryOptions: TPanel;
    bCloseAC: TSpeedButton;
    lAC: TLabel;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    clbCategoryOptions: TCheckListBox;
    bAdvanced: TBitBtn;
    lbSummaryLayout: TListBox;
    GroupBox1: TGroupBox;
    Label6: TLabel;
    Label8: TLabel;
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
    Label9: TLabel;
    lSI15: TLabel;
    lSI16: TLabel;
    cbIncludeImages: TCheckBox;
    cbLayoutSize: TComboBox;
    lReportsHTMLCustom: TGroupBox;
    sHTMLColour2: TShape;
    sHTMLColour1: TShape;
    Label16: TLabel;
    Label17: TLabel;
    sHTMLColour3: TShape;
    sHTMLColour9: TShape;
    sHTMLColour4: TShape;
    Label19: TLabel;
    Label18: TLabel;
    Label3: TLabel;
    sHTMLColour6: TShape;
    sHTMLColour10: TShape;
    sHTMLColour11: TShape;
    sHTMLColour7: TShape;
    sHTMLColour8: TShape;
    Label20: TLabel;
    Label4: TLabel;
    Label7: TLabel;
    Label22: TLabel;
    Label23: TLabel;
    sHTMLColour5: TShape;
    Label21: TLabel;
    Label1: TLabel;
    LOOSingleColour: TLabel;
    sbLoadHTMLColours: TBitBtn;
    sbSaveHTMLColours: TBitBtn;
    sbPreview: TBitBtn;
    cbHTMLUnits: TComboBox;
    cbOOSingleColour: TAdvSmoothSlider;
    cbAutoRefresh: TCheckBox;
    sbCancel: TSpeedButton;
    SpeedButton3: TSpeedButton;
    lSI17: TLabel;
    procedure sbPreviewClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure sbEditHTMLLayoutClick(Sender: TObject);
    procedure sbRemoveClick(Sender: TObject);
    procedure sbUpClick(Sender: TObject);
    procedure sbDownClick(Sender: TObject);
    procedure lSI1Click(Sender: TObject);
    procedure sHTMLColour1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure lbSummaryLayoutClick(Sender: TObject);
    procedure cbIncludeImagesClick(Sender: TObject);
    procedure sbLoadHTMLColoursClick(Sender: TObject);
    procedure sbSaveHTMLColoursClick(Sender: TObject);
    procedure bAdvancedClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    procedure bCloseACClick(Sender: TObject);
    procedure sbSaveClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormCanResize(Sender: TObject; var NewWidth, NewHeight: Integer;
      var Resize: Boolean);
    procedure sbCancelClick(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
  private
    FTempReport   : THTMLReportOptions;
    FOneOffCustom : boolean;

    LayoutItems : array[1..HTMLItemsCount] of TLabel;
    HTMLColoursArray  : array[1..HTMLColoursCount] of TShape;

    procedure AutoRefresh;

    procedure BuildTopHalf;
    procedure BuildBottomHalf;

    procedure BuildReport(var aHTMLReport : THTMLReportOptions);

    procedure LoadHTMLColours(const filename : string);
    procedure SaveHTMLColours(const filename : string);
  public
    { Public declarations }
  end;

var
  frmEditHTMLReport: TfrmEditHTMLReport;


function DoHTMLReport(aReportID : integer; aOneOffCustom : boolean): THTMLReportOptions;


implementation

{$R *.dfm}


function DoHTMLReport(aReportID : integer; aOneOffCustom : boolean): THTMLReportOptions;
 begin
  with TfrmEditHTMLReport.Create(Application) do
    try
      FOneOffCustom := aOneOffCustom;

      cbHTMLLayouts.ItemIndex := aReportID;

      sbEditHTMLLayoutClick(Nil);

      if FOneOffCustom then begin
        sbEditHTMLLayout.Visible := False;
        cbHTMLLayouts.Visible    := False;
      end;

      ShowModal;

      if FOneOffCustom then begin
        Result := FTempReport;
      end;

    finally
      Free;
    end;
end;


procedure TfrmEditHTMLReport.FormCreate(Sender: TObject);
var
  t : integer;
  fd : TFormDetails;

begin
  fd := XSettings.LoadFormDetails(_FormEditHTMLReport);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  // ===========================================================================

  Caption                  := XText[rsCustomise] + ' HTML ' + XText[rsReport];

  sbSave.Caption           := XText[rsSave];
  sbCancel.Caption         := XText[rsCancel];
  sbEditHTMLLayout.Caption := XText[rsEdit];

  // ===========================================================================

  cbHTMLLayouts.Items.Add(XText[rsAutoSave]);
  cbHTMLLayouts.Items.Add(XText[rsQuick]);
  cbHTMLLayouts.Items.Add(XText[rsOther]);
  cbHTMLLayouts.Items.Add(XText[rsCustom1]);
  cbHTMLLayouts.Items.Add(XText[rsCustom2]);
  cbHTMLLayouts.Items.Add(XText[rsCustom3]);

  cbHTMLLayouts.ItemIndex := 0;

  LayoutItems[1]  := lSI1;   LayoutItems[2]  := lSI2;
  LayoutItems[3]  := lSI3;   LayoutItems[4]  := lSI4;
  LayoutItems[5]  := lSI5;   LayoutItems[6]  := lSI6;
  LayoutItems[7]  := lSI7;   LayoutItems[8]  := lSI8;
  LayoutItems[9]  := lSI9;   LayoutItems[10] := lSI10;
  LayoutItems[11] := lSI11;  LayoutItems[12] := lSI12;
  LayoutItems[13] := lSI13;  LayoutItems[14] := lSI14;
  LayoutItems[15] := lSI15;  LayoutItems[16] := lSI16;
  LayoutItems[17] := lSI17;

  for t := 1 to HTMLItemsCount do begin
    LayoutItems[t].Caption := GenericReportItems[t];
  end;

  cbLayoutSize.Items.Add('800 x 600');
  cbLayoutSize.Items.Add('1024 x 768');
  cbLayoutSize.Items.Add('1280 x 1024');

  // ===========================================================================

  Label1.Caption           := XText[rsAvailable] + ' HTML ' + XText[rsReportItems];
  Label2.Caption           := 'HTML ' + XText[rsReportLayout];
  cbIncludeImages.Caption  := XText[rsIncludeImages];
  GroupBox1.Caption        := XText[rsClickToAdd];
  lImportant.Caption       := XText[rsMaySlowDownReport];
  bCloseAC.Caption         := XText[rsHide];
  lAC.Caption              := XText[rsSelectCategories];
  bAdvanced.Caption        := XText[rsCategories];

  for t := 1 to 19 do
    clbCategoryOptions.Items.Add(TypeDescriptions[t]);

  //

  sbLoadHTMLColours.Caption := XText[rsLoad];
  sbSaveHTMLColours.Caption := XText[rsSaveAs];
  sbPreview.Caption         := XText[rsPreview];
  cbAutoRefresh.Caption     := XText[rsAutoRefresh];

  lReportsHTMLCustom.Caption := XText[rsHTMLReportOptions];
  Label16.Caption            := XText[rsLinkNormal];
  Label17.Caption            := XText[rsLinkHover];
  Label18.Caption            := XText[rsPageBackground];
  Label3.Caption             := XText[rsGraphBackground];
  Label19.Caption            := XText[rsTextColour];
  Label20.Caption            := XText[rsTableHeader];
  Label4.Caption             := XText[rsTableBackground] + ' I';
  Label7.Caption             := XText[rsTableBackground] + ' II';
  Label22.Caption            := XText[rsTableTextColour];
  Label23.Caption            := XText[rsTableTextColour2];
  lOOSingleColour.Caption    := XText[rsSetBargraphToASingleColour];
  Label21.Caption            := XText[rsBarGraphColour];
  Label1.Caption             := XText[rsShowFileSizesAs];

  HTMLColoursArray[1]  := sHTMLColour1;
  HTMLColoursArray[2]  := sHTMLColour2;
  HTMLColoursArray[3]  := sHTMLColour3;
  HTMLColoursArray[4]  := sHTMLColour4;
  HTMLColoursArray[5]  := sHTMLColour5;
  HTMLColoursArray[6]  := sHTMLColour6;
  HTMLColoursArray[7]  := sHTMLColour7;
  HTMLColoursArray[8]  := sHTMLColour8;
  HTMLColoursArray[9]  := sHTMLColour9;
  HTMLColoursArray[10] := sHTMLColour10;
  HTMLColoursArray[11] := sHTMLColour11;

  cbHTMLUnits.Items.Add(XText[rsMostConvenient]);
  cbHTMLUnits.Items.Add(XText[rsXBytes]);
  cbHTMLUnits.Items.Add(XText[rsXKilobytes]);
  cbHTMLUnits.Items.Add(XText[rsXMegabytes]);
  cbHTMLUnits.Items.Add(XText[rsXGigabytes]);
  cbHTMLUnits.ItemIndex := 0;
end;


procedure TfrmEditHTMLReport.FormCanResize(Sender: TObject; var NewWidth,
  NewHeight: Integer; var Resize: Boolean);
begin
  if (NewWidth > 800) and (NewHeight > 610) then
    Resize := True
  else
    Resize := False;
end;


procedure TfrmEditHTMLReport.FormClose(Sender: TObject;
  var Action: TCloseAction);
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


procedure TfrmEditHTMLReport.BuildTopHalf;
var
  t, lLayoutID : integer;
  s : string;

begin
  s := '';

  lbSummaryLayout.Clear;

  for t := 1 to length(FTempReport.Layout) do begin
    if FTempReport.Layout[t] = ':' then begin
      lLayoutID := StrToIntDef(s, 99);

      if lLayoutID <= HTMLItemsCount then begin
        if lLayoutID = 0 then
          cbIncludeImages.Checked := True
        else
          lbSummaryLayout.Items.Add(LayoutItems[lLayoutID].Caption);
      end;

      s := '';
    end
    else
      s := s + FTempReport.Layout[t];
  end;

  cbLayoutSize.ItemIndex := FTempReport.LayoutSize - 1;

  for t := 1 to 19 do begin
    if FTempReport.CategoryList[t] = '1' then
      clbCategoryOptions.Checked[t - 1] := True
    else
      clbCategoryOptions.Checked[t - 1] := False;
  end;
end;


procedure TfrmEditHTMLReport.cbIncludeImagesClick(Sender: TObject);
begin
  AutoRefresh;
end;


procedure TfrmEditHTMLReport.bAdvancedClick(Sender: TObject);
begin
  pCategoryOptions.BringToFront;
  pCategoryOptions.Visible := True;
end;


procedure TfrmEditHTMLReport.bCloseACClick(Sender: TObject);
begin
  pCategoryOptions.SendToBack;
  pCategoryOptions.Visible := False;
end;


procedure TfrmEditHTMLReport.BuildBottomHalf;
var
  t : integer;

begin
  cbHTMLUnits.ItemIndex := FTempReport.HTMLUnits;

  for t := 1 to HTMLColoursCount do
    HTMLColoursArray[t].Brush.Color := XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].HTMLColours.Colour[t];
end;


procedure TfrmEditHTMLReport.AutoRefresh;
begin
  if cbAutoRefresh.Checked then
    sbPreviewClick(Nil);
end;


// =============================================================================
// =============================================================================
// =============================================================================


procedure TfrmEditHTMLReport.sbCancelClick(Sender: TObject);
begin
  FTempReport.Layout := '$';

  ModalResult := mrCancel;
end;


procedure TfrmEditHTMLReport.sbDownClick(Sender: TObject);
 var
  a : integer;

 begin
  if lbSummaryLayout.ItemIndex <> -1 then begin
    if lbSummaryLayout.ItemIndex<lbSummaryLayout.Count - 1 then begin
      a:=lbSummaryLayout.ItemIndex + 1;

      lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex + 1);

      lbSummaryLayout.ItemIndex := a;

      AutoRefresh;
    end;
  end;
end;


procedure TfrmEditHTMLReport.sbEditHTMLLayoutClick(Sender: TObject);
begin
  FTempReport := XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1];

  if FTempReport.Layout <> '' then begin
    BuildTopHalf;
    BuildBottomHalf;

    sbPreviewClick(Nil);
  end;
end;


procedure TfrmEditHTMLReport.sbLoadHTMLColoursClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXOpenDialog.Execute(XText[rsLayoutFiles] + ' (*.data)|*.data',
                                    '.data',
                                    GSystemGlobal.ExePath + 'data\layouts',
                                    '');

  if lFileName <> '' then begin
    LoadHTMLColours(lFileName);
  end;
end;


procedure TfrmEditHTMLReport.sbPreviewClick(Sender: TObject);
var
  Doc: Variant;
  lColours : THTMLColours;
  t : integer;

begin
  for t := 1 to HTMLColoursCount do
    lColours.Colour[t] := HTMLColoursArray[t].Brush.Color;

  if cbOOSingleColour.State = ssOn then
    lColours.MonoBargraph := True
  else
    lColours.MonoBargraph := False;

  BuildReport(FTempReport);

  // ===========================================================================

  if NOT Assigned(wbHTML.Document) then
    wbHTML.Navigate('about:blank');

  try
    Doc := wbHTML.Document;
    Doc.Clear;
    Doc.Write(THTMLPreview.Get(FTempReport, lColours));
    Doc.Close;
  except
    TMSLogger.Error('Error writing out preview HTML file.');
  end;
end;


procedure TfrmEditHTMLReport.sbRemoveClick(Sender: TObject);
begin
  lbSummaryLayout.DeleteSelected;

  sbRemove.Enabled := False;
  sbUp.Enabled     := False;
  sbDown.Enabled   := False;

  AutoRefresh;
end;


procedure TfrmEditHTMLReport.sbSaveClick(Sender: TObject);
var
  t : integer;

begin
  // save report stuff =========================================================

  BuildReport(FTempReport);

  // save colours ==============================================================

  for t := 1 to HTMLColoursCount do
    FTempReport.HTMLColours.Colour[t] := HTMLColoursArray[t].Brush.Color;

  if not(FOneOffCustom) then
    XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1] := FTempReport;

  ModalResult := mrOK;
end;


procedure TfrmEditHTMLReport.sbSaveHTMLColoursClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsLayoutFiles] + ' (*.data)|*.data',
                                    '.data',
                                    '',
                                    GSystemGlobal.ExePath + 'data\layouts');
  if lFileName <> '' then begin
    SaveHTMLColours(lFileName);
  end;
end;


procedure TfrmEditHTMLReport.sbUpClick(Sender: TObject);
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


procedure TfrmEditHTMLReport.sHTMLColour1MouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  lColour : integer;

begin
  if button = mbLeft then begin
    Assert(TShape(sender).tag <= HTMLColoursCount, 'sHTMLColourMouseDown :: Object tag incorrect.');

    lColour := TXColourDialog.Execute(TShape(Sender).Brush.Color);

    if lColour <> -1 then begin
      TShape(Sender).Brush.Color := lColour;
    end;

    AutoRefresh;
  end;
end;


procedure TfrmEditHTMLReport.SpeedButton1Click(Sender: TObject);
 var
  t : integer;

 begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := True;
end;

procedure TfrmEditHTMLReport.SpeedButton2Click(Sender: TObject);
var
  t : integer;

begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := False;
end;

procedure TfrmEditHTMLReport.SpeedButton3Click(Sender: TObject);
begin
  THelp.OpenHelpPage('report_html.htm');
end;

procedure TfrmEditHTMLReport.BuildReport(var aHTMLReport : THTMLReportOptions);
var
  t, z, idx : integer;
  s : string;

begin
  s := '';

  if cbIncludeImages.Checked then       // where's value for not included?!?!
    s := s + '0:';

  for t := 0 to lbSummaryLayout.Count - 1 do begin
    idx := 0;

    for z := 1 to HTMLItemsCount do begin
      if LayoutItems[z].Caption = lbSummaryLayout.Items[t] then idx := z;
    end;

    s := s + IntToStr(idx) + ':';
  end;

  aHTMLReport.HTMLUnits  := cbHTMLUnits.ItemIndex;
  aHTMLReport.Layout     := s;
  aHTMLReport.LayoutSize := cbLayoutSize.ItemIndex + 1;

  s := '';
  for t := 1 to 19 do
    s := s + IntToStr(TConvert.BoolToInteger(clbCategoryOptions.Checked[t - 1]));

  aHTMLReport.CategoryList := s;
end;


procedure TfrmEditHTMLReport.LoadHTMLColours(const filename : string);
 var
  config : TIniFile;

 begin
  config := TINIFile.Create(filename);

  try
    sHTMLColour1.Brush.Color  := config.ReadInteger('Main', 'LinkNormal',       $00FFFFFF);
    sHTMLColour2.Brush.Color  := config.ReadInteger('Main', 'LinkHover',        $00FFFFFF);

    sHTMLColour3.Brush.Color  := config.ReadInteger('Main', 'PageBackground',   $00FFFFFF);
    sHTMLColour9.Brush.Color  := config.ReadInteger('Main', 'GraphBackground',  $00FFFFFF);
    sHTMLColour4.Brush.Color  := config.ReadInteger('Main', 'TextColour',       $00FFFFFF);

    sHTMLColour6.Brush.Color  := config.ReadInteger('Main', 'TableHeader',      $00FFFFFF);
    sHTMLColour10.Brush.Color := config.ReadInteger('Main', 'TableBackground',  $00FFFFFF);
    sHTMLColour11.Brush.Color := config.ReadInteger('Main', 'TableBackground2', $00CCCCCC);
    sHTMLColour7.Brush.Color  := config.ReadInteger('Main', 'TableTextColour',  $00FFFFFF);
    sHTMLColour8.Brush.Color  := config.ReadInteger('Main', 'TableTextColour2', $00FFFFFF);
  finally
    config.Free;
  end;
end;


procedure TfrmEditHTMLReport.SaveHTMLColours(const filename : string);
 var
  config : TIniFile;

 begin
  config := TINIFile.Create(filename);

  try
    config.WriteInteger('Main', 'LinkNormal',       sHTMLColour1.Brush.Color);
    config.WriteInteger('Main', 'LinkHover',        sHTMLColour2.Brush.Color);

    config.WriteInteger('Main', 'PageBackground',   sHTMLColour3.Brush.Color);
    config.WriteInteger('Main', 'GraphBackground',  sHTMLColour9.Brush.Color);
    config.WriteInteger('Main', 'TextColour',       sHTMLColour4.Brush.Color);

    config.WriteInteger('Main', 'TableHeader',      sHTMLColour6.Brush.Color);
    config.WriteInteger('Main', 'TableBackground',  sHTMLColour10.Brush.Color);
    config.WriteInteger('Main', 'TableBackground2', sHTMLColour11.Brush.Color);
    config.WriteInteger('Main', 'TableTextColour',  sHTMLColour7.Brush.Color);
    config.WriteInteger('Main', 'TableTextColour2', sHTMLColour8.Brush.Color);
  finally
    config.Free;
  end;
end;


procedure TfrmEditHTMLReport.lbSummaryLayoutClick(Sender: TObject);
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


procedure TfrmEditHTMLReport.lSI1Click(Sender: TObject);
begin
  if lbSummaryLayout.Items.IndexOf(TLabel(Sender).Caption) = -1 then begin
    lbSummaryLayout.Items.Add(TLabel(Sender).Caption);
  end;
end;



end.
