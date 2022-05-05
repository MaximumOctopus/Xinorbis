{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

        Started: January 28th 2002
  Last Modified: January 16th 2019
}

unit X.Form.Report;

interface

uses
  Windows, Messages, System.SysUtils, System.UITypes, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, Buttons, ExtCtrls, AdvOfficeButtons, AdvSmoothTabPager,

  X.Dialogs.Save,

  X.Utility, X.Formatting, X.Windows, X.Settings, X.CReportOptions, X.LanguageHandler,
  X.SystemGlobal, X.Help, X.ThemeHelper;

type
  TfrmReport = class(TForm)
    Panel2: TPanel;
    bGenerateFilenames: TBitBtn;
    bSave: TBitBtn;
    bCancel: TBitBtn;
    bHelp: TBitBtn;
    pScanSelection: TAdvSmoothTabPager;
    tsSelectFolder: TAdvSmoothTabPage;
    tsScanHistory: TAdvSmoothTabPage;
    tabText: TAdvSmoothTabPage;
    tabTree: TAdvSmoothTabPage;
    tsXinorbis: TAdvSmoothTabPage;
    tsXML: TAdvSmoothTabPage;
    cbCSVReport: TAdvOfficeCheckBox;
    Label6: TLabel;
    eCSVOutput: TEdit;
    SpeedButton2: TSpeedButton;
    cbHTMLReport: TAdvOfficeCheckBox;
    Label4: TLabel;
    eHTMLReport: TEdit;
    Label35: TLabel;
    cbHTMLLayouts: TComboBox;
    cbHTMLUnits: TComboBox;
    lHTMLUnits: TLabel;
    sbHTMLReport: TSpeedButton;
    cbTextReport: TAdvOfficeCheckBox;
    Label2: TLabel;
    eTextReport: TEdit;
    Label38: TLabel;
    cbTextLayouts: TComboBox;
    sbTextReport: TSpeedButton;
    cbTreeReport: TAdvOfficeCheckBox;
    Label1: TLabel;
    eTreeReport: TEdit;
    Label7: TLabel;
    cbTreeLayouts: TComboBox;
    sbTreeReport: TSpeedButton;
    cbXinorbisReport: TAdvOfficeCheckBox;
    eZSReport: TEdit;
    Label3: TLabel;
    sbZSReport: TSpeedButton;
    cbXMLReport: TAdvOfficeCheckBox;
    Label5: TLabel;
    eXMLOutput: TEdit;
    Label36: TLabel;
    cbXMLLayouts: TComboBox;
    SpeedButton1: TSpeedButton;
    rbXMLMode1: TAdvOfficeRadioButton;
    rbXMLMode2: TAdvOfficeRadioButton;
    rbCSVMode1: TAdvOfficeRadioButton;
    rbCSVMode2: TAdvOfficeRadioButton;
    Panel1: TPanel;
    bSelectAll: TBitBtn;
    bSelectNone: TBitBtn;
    SpeedButton3: TSpeedButton;
    cbCSVTitles: TAdvOfficeCheckBox;
    lThisReport1: TLabel;
    lThisReport2: TLabel;
    procedure sbTextReportClick(Sender: TObject);
    procedure sbZSReportClick(Sender: TObject);
    procedure sbHTMLReportClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure bGenerateFilenamesClick(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure cbTextReportClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure bSaveClick(Sender: TObject);
    procedure bHelpClick(Sender: TObject);
    procedure sbTreeReportClick(Sender: TObject);
    procedure bSelectNoneClick(Sender: TObject);
    procedure bSelectAllClick(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
    procedure cbHTMLLayoutsChange(Sender: TObject);
  private
    FDataIndex : integer;
    FFolder    : string;

    FChecks    : array[1..6] of TAdvOfficeCheckBox;
    FEdits     : array[1..6] of TEdit;

    function  GetFileName(aFolder, aFileName : string): string;
    procedure ChangeFolders(aFolder : string);
    procedure SetAll(aStatus : boolean);
    procedure SetLanguage;
    procedure SetSaveStatus;

    procedure SetTheme;
  public
  end;

var
  frmReport: TfrmReport;


function DoReportSave(aDataIndex : integer;
                      var TextOptions : TTextReportOptions; var CSVOptions  : TCSVReportOptions;
                      var HTMLOptions : THTMLReportOptions; var XinOptions  : TXinorbisReportOptions;
                      var XMLOptions  : TXMLReportOptions; var TreeOptions  : TTreeReportOptions): boolean;


implementation

{$R *.DFM}


uses
  X.Global, X.Constants, X.GlobalObjects;


function DoReportSave(aDataIndex : integer;
                      var TextOptions : TTextReportOptions; var CSVOptions  : TCSVReportOptions;
                      var HTMLOptions : THTMLReportOptions; var XinOptions  : TXinorbisReportOptions;
                      var XMLOptions  : TXMLReportOptions; var TreeOptions  : TTreeReportOptions): boolean;

 function CheckFilename(const fn, validext : string): string;
  begin
   if Pos(UpperCase(validext), UpperCase(ExtractFileExt(fn))) <> 0 then
     Result := fn
   else begin
     Result := fn + validext;
   end;
 end;

 begin
  with TfrmReport.Create(Application) do
    try
      FDataIndex := aDataIndex;

      SetLanguage;

      if XMLOptions.XMLData = CDataSummary then
        rbXMLMode1.Checked := True
      else
        rbXMLMode2.Checked := True;

      if CSVOptions.CSVData = CDataSummary then
        rbCSVMode1.Checked := True
      else
        rbCSVMode2.Checked := True;

      // =======================================================================
      // =======================================================================

      ShowModal;

      // =======================================================================
      // =======================================================================

      if ModalResult = mrOK then begin

        Result := True;

        // =====================================================================

        if cbCSVReport.Checked then begin
          CSVOptions.Filename  := CheckFilename(eCSVOutput.Text, '.csv');
          CSVOptions.Category  := -1;
          CSVOptions.CSVUnits  := CSVUnitsMegabytes;
          CSVOptions.CSVTitles := cbCSVTitles.Checked;

          if rbCSVMode1.Checked then
            CSVOptions.CSVData := CDataSummary
          else
            CSVOptions.CSVData := CDataFileList;

          XSettings.Report.CSVOptions[LayoutAutoSave].CSVData := CSVOptions.CSVData;
        end;

        // =====================================================================

        if cbHTMLReport.Checked then begin
          HTMLOptions.HTMLColours  := XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].HTMLColours;

          HTMLOptions.Filename     := CheckFilename(eHTMLReport.Text, '.htm');
          HTMLOptions.HTMLUnits    := cbHTMLUnits.ItemIndex;
          HTMLOptions.Layout       := XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].Layout;
          HTMLOptions.LayoutSize   := XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].LayoutSize;
          HTMLOptions.CategoryList := XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].CategoryList;
        end;

        // =====================================================================

        if cbTextReport.Checked then begin
          TextOptions.Filename     := CheckFilename(eTextReport.Text, '.txt');

          TextOptions.Layout       := XSettings.Report.TextOptions[cbTextLayouts.ItemIndex + 1].Layout;
          TextOptions.CategoryList := XSettings.Report.TextOptions[cbTextLayouts.ItemIndex + 1].CategoryList;
        end;

        // =====================================================================

        if cbTreeReport.Checked then begin
          TreeOptions.Filename          := CheckFilename(eTreeReport.Text, '.txt');
          TreeOptions.Layout            := XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1].Layout;
          TreeOptions.IncludeSize       := XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1].IncludeSize;
          TreeOptions.IncludeAttributes := XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1].IncludeAttributes;
          TreeOptions.CategoryList      := XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1].CategoryList;
        end;

        // =====================================================================

        if cbXMLReport.Checked then begin
          XMLOptions.Filename := CheckFilename(eXMLOutput.Text, '.xml');

          if rbXMLMode1.Checked then
            XMLOptions.XMLData := CDataSummary
          else
            XMLOptions.XMLData := CDataFileList;

          XMLOptions.Layout := XSettings.Report.XMLOptions[cbXMLLayouts.ItemIndex + 1].Layout;
        end;

        // =====================================================================

        if cbXinorbisReport.Checked then begin
          XinOptions.Filename := CheckFilename(eZSReport.Text, '.zsr');

          XinOptions.Layout := 1;
        end;

        // =====================================================================
      end
      else begin
        Result := False;
      end;
    finally
      free;
  end;
end;


procedure TfrmReport.FormCreate(Sender: TObject);
var
  fd : TFormDetails;

begin
  fd := XSettings.LoadFormDetails(_FormReport);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  FFolder := '';

  FEdits[1]  := eCSVOutput;
  FEdits[2]  := eHTMLReport;
  FEdits[3]  := eTextReport;
  FEdits[4]  := eTreeReport;
  FEdits[5]  := eZSReport;
  FEdits[6]  := eXMLOutput;

  FChecks[1] := cbCSVReport;
  FChecks[2] := cbHTMLReport;
  FChecks[3] := cbTextReport;
  FChecks[4] := cbTreeReport;
  FChecks[5] := cbXinorbisReport;
  FChecks[6] := cbXMLReport;

  SetTheme;
end;


procedure TfrmReport.FormClose(Sender: TObject; var Action: TCloseAction);
 var
  fd : TFormDetails;

 begin
  fd.formID := _FormReport;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  Action := caFree;
end;


procedure TfrmReport.SetTheme;
begin
  TThemeHelper.SetSmoothTabPager(pScanSelection);

  TThemeHelper.SetSmoothTabPage(tsSelectFolder);
  TThemeHelper.SetSmoothTabPage(tsScanHistory);
  TThemeHelper.SetSmoothTabPage(tabText);
  TThemeHelper.SetSmoothTabPage(tabTree);
  TThemeHelper.SetSmoothTabPage(tsXinorbis);
  TThemeHelper.SetSmoothTabPage(tsXML);
end;


procedure TfrmReport.sbTextReportClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsTextFiles] + ' (*.txt)|*.txt',
                                    '.txt',
                                    TUtility.GetDefaultFileName('.txt', XText[rsReport] + '_' + XText[rsExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    eTextReport.Text := lFileName;

    if not(cbTextReport.Checked) then begin
      cbTextReportClick(cbTextReport);
    end;
  end;
end;


procedure TfrmReport.sbZSReportClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute('Xinorbis v2 (*.zsr2)|*.zsr2',
                                    '.zsr2',
                                    TUtility.GetDefaultFileName('.zsr2', XText[rsReport] + '_' + XText[rsExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    eZSReport.Text := lFileName;

    if not(cbXinorbisReport.Checked) then begin
      cbTextReportClick(cbXinorbisReport);
    end;
  end;
end;

procedure TfrmReport.sbHTMLReportClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsHTMLFiles] + ' (*.html, *.htm)|*.html; *.htm',
                                    '.htm',
                                    TUtility.GetDefaultFileName('.htm', XText[rsReport] + '_' + XText[rsExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    eHTMLReport.Text := lFileName;

    if not(cbHTMLReport.Checked) then begin
      cbTextReportClick(cbHTMLReport);
    end;
  end;
end;

procedure TfrmReport.SpeedButton1Click(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsXMLFiles] + ' (*.xml)|*.xml',
                                    '.xml',
                                    TUtility.GetDefaultFileName('.xml', XText[rsReport] + '_' + XText[rsExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    eXMLOutput.Text := lFileName;

    if not(cbXMLReport.Checked) then begin
      cbTextReportClick(cbXMLReport);
    end;
  end;
end;

procedure TfrmReport.SpeedButton2Click(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsCSVFiles] + ' (*.csv)|*.csv',
                                    '.csv',
                                    TUtility.GetDefaultFileName('.csv', XText[rsReport] + '_' + XText[rsExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    eCSVOutput.Text := lFileName;

    if not(cbCSVReport.Checked) then begin
      cbTextReportClick(cbCSVReport);
    end;
  end;
end;


procedure TfrmReport.SpeedButton3Click(Sender: TObject);
 var
  str : string;

 begin
  str := TXWindows.BrowseForFolder(Handle);

  if str <> '' then begin
    FFolder := str;

    ChangeFolders(FFolder);
  end;
end;


procedure TfrmReport.bGenerateFilenamesClick(Sender: TObject);
var
  cname : string;

begin
  cname := TXWindows.GetComputerNetName;

  eCSVOutput.Text  := GetFileName(GSystemGlobal.AppDataPath + 'reports\' + cname + '\csv\',
                                  TXFormatting.MakeFilenameCompatible(GScanDetails[FDataIndex].ScanPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.csv');

  eHTMLReport.Text := GetFileName(GSystemGlobal.AppDataPath + 'reports\' + cname + '\html\',
                                  TXFormatting.MakeFilenameCompatible(GScanDetails[FDataIndex].ScanPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.html');

  eTextReport.Text := GetFileName(GSystemGlobal.AppDataPath + 'reports\' + cname + '\Text\',
                                  TXFormatting.MakeFilenameCompatible(GScanDetails[FDataIndex].ScanPath) + '_' + XText[rsText] + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt');

  eTreeReport.Text := GetFileName(GSystemGlobal.AppDataPath + 'reports\' + cname + '\Tree\',
                                  TXFormatting.MakeFilenameCompatible(GScanDetails[FDataIndex].ScanPath) + '_' + XText[rsTree] + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt');

  eZSReport.Text   := GetFileName(GSystemGlobal.AppDataPath + 'reports\' + cname + '\Xinorbis\',
                                  TXFormatting.MakeFilenameCompatible(GScanDetails[FDataIndex].ScanPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.zsr2');

  eXMLOutput.Text  := GetFileName(GSystemGlobal.AppDataPath + 'reports\' + cname + '\xml\',
                                  TXFormatting.MakeFilenameCompatible(GScanDetails[FDataIndex].ScanPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.xml');
end;


procedure TfrmReport.cbHTMLLayoutsChange(Sender: TObject);
begin
  cbHTMLUnits.ItemIndex    := XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].HTMLUnits;

//  cbHTMLShowImages.Checked := TUtility.FindReportItem(XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1], 0);
end;


procedure TfrmReport.cbTextReportClick(Sender: TObject);
 begin
  if TAdvOfficeCheckBox(Sender).Checked then begin
    TAdvOfficeCheckBox(Sender).Font.Style := [];
    TAdvOfficeCheckBox(Sender).Checked    := False;

    TAdvSmoothTabPage(TAdvOfficeCheckBox(Sender).Parent).TabAppearance.Status.Visible := False;
  end
  else begin
    TAdvOfficeCheckBox(Sender).Font.Style := [fsBold];
    TAdvOfficeCheckBox(Sender).Checked    := True;

    TAdvSmoothTabPage(TAdvOfficeCheckBox(Sender).Parent).TabAppearance.Status.Visible := True;
  end;

  if (cbCSVReport.Enabled or cbHTMLReport.Enabled or cbTextReport.Enabled or cbTreeReport.Enabled or cbXinorbisReport.Enabled or cbXMLReport.Enabled) and
     (GScanDetails[FDataIndex].Files.Count <> 0) then
    bSave.Enabled := True
  else
    bSave.Enabled := False;

  SetSaveStatus;
end;


procedure TfrmReport.SetLanguage;
begin
  cbHTMLUnits.Items.Add(XText[rsMostConvenient]);
  cbHTMLUnits.Items.Add(XText[rsXBytes]);
  cbHTMLUnits.Items.Add(XText[rsXKilobytes]);
  cbHTMLUnits.Items.Add(XText[rsXMegabytes]);
  cbHTMLUnits.Items.Add(XText[rsXGigabytes]);
  cbHTMLUnits.ItemIndex := 0;

  // ===========================================================================

  bSelectAll.Caption         := XText[rsSelectAll];
  bSelectNone.Caption        := XText[rsSelectNone];

  Caption                    := XText[rsSaveReports];
  Label1.Caption             := XText[rsTreeFilename];
  Label2.Caption             := XText[rsTextReportFilename];
  Label3.Caption             := XText[rsXinorbisReportFilename];
  Label4.Caption             := XText[rsOutputAsHTML];
  Label5.Caption             := XText[rsOutputAsXML];
  rbXMLMode1.Caption         := XText[rsScanData];
  rbXMLMode2.Caption         := XText[rsFullFileList];
  Label6.Caption             := XText[rsOutputAsCSV];
  rbCSVMode1.Caption         := XText[rsCategories];
  rbCSVMode2.Caption         := XText[rsFullFileList];
  cbCSVTitles.Caption        := XText[rsIncludeColumnTitles];
  bGenerateFilenames.Caption := XText[rsGenerateFilenames];
  bSave.Caption              := XText[rsSave];
  bCancel.Caption            := XText[rsCancel];
  bHelp.Caption              := XText[rsHelp];

  lHTMLUnits.Caption         := XText[rsShowFileSizesAs];

  tabText.Caption            := XText[rsText];
  tabTree.Caption            := XText[rsTree];

  cbCSVReport.Caption        := 'CSV '      + XText[rsReport];
  cbHTMLReport.Caption       := 'HTML '     + XText[rsReport];
  cbTextReport.Caption       := XText[rsText]      + ' ' + XText[rsReport];
  cbTreeReport.Caption       := XText[rsTree]      + ' ' + XText[rsReport];
  cbXinorbisReport.Caption   := 'Xinorbis ' + XText[rsReport];
  cbXMLReport.Caption        := 'XML '      + XText[rsReport];

  cbHTMLLayouts.Items.Add(XText[rsAutoSave]);
  cbHTMLLayouts.Items.Add(XText[rsQuick]);
  cbHTMLLayouts.Items.Add(XText[rsOther]);
  cbHTMLLayouts.Items.Add(XText[rsCustom1]);
  cbHTMLLayouts.Items.Add(XText[rsCustom2]);
  cbHTMLLayouts.Items.Add(XText[rsCustom3]);

  cbTextLayouts.Items.Add(XText[rsAutoSave]);
  cbTextLayouts.Items.Add(XText[rsQuick]);
  cbTextLayouts.Items.Add(XText[rsOther]);
  cbTextLayouts.Items.Add(XText[rsCustom1]);
  cbTextLayouts.Items.Add(XText[rsCustom2]);
  cbTextLayouts.Items.Add(XText[rsCustom3]);

  cbTreeLayouts.Items.Add(XText[rsAutoSave]);
  cbTreeLayouts.Items.Add(XText[rsQuick]);
  cbTreeLayouts.Items.Add(XText[rsOther]);
  cbTreeLayouts.Items.Add(XText[rsCustom1]);
  cbTreeLayouts.Items.Add(XText[rsCustom2]);
  cbTreeLayouts.Items.Add(XText[rsCustom3]);

  cbXMLLayouts.Items.Add(XText[rsAutoSave]);
  cbXMLLayouts.Items.Add(XText[rsQuick]);
  cbXMLLayouts.Items.Add(XText[rsOther]);
  cbXMLLayouts.Items.Add(XText[rsCustom1]);
  cbXMLLayouts.Items.Add(XText[rsCustom2]);
  cbXMLLayouts.Items.Add(XText[rsCustom3]);

  cbHTMLLayouts.ItemIndex := 2;
  cbTextLayouts.ItemIndex := 2;
  cbTreeLayouts.ItemIndex := 2;
  cbXMLLayouts.ItemIndex  := 2;

  Label36.Caption := XText[rsReportLayout];
  Label35.Caption := XText[rsReportLayout];
  Label38.Caption := XText[rsReportLayout];
  Label7.Caption  := XText[rsReportLayout];

  lThisReport1.Caption := XText[rsThisReportCanBeImported];
  lThisReport2.Caption := XText[rsThisReportCanBeImported];
end;


procedure TfrmReport.bSaveClick(Sender: TObject);
 var
  s : string;

 begin
  s := '';

  if (cbTextReport.Checked) and (eTextReport.Text = '') then begin
    s := '"' + XText[rsText] + ' ' + XText[rsReport] + '" ' + XText[rsHasBeenSelected];
  end;

  if (cbXinorbisReport.Checked) and (eZSReport.Text = '') then begin
    if s <> '' then
      s := s + #13 + #13;

    s := s + '"' + 'Xinorbis ' + XText[rsReport] + '" ' + XText[rsHasBeenSelected];
  end;

  if (cbHTMLReport.Checked) and (eHTMLReport.Text = '') then begin
    if s <> '' then
      s := s + #13 + #13;

    s := s + '"HTML ' + XText[rsReport] + '" ' + XText[rsHasBeenSelected];
  end;

  if (cbCSVReport.Checked) and (eCSVOutput.Text = '') then begin
    if s <> '' then
      s := s + #13 + #13;

    s := s + '"CSV ' + XText[rsReport] + '" ' + XText[rsHasBeenSelected];
  end;

  if (cbXMLReport.Checked) and (eXMLOutput.Text = '') then begin
    if s <> '' then
      s := s + #13 + #13;

    s := s + '"XML ' + XText[rsReport] + '" ' + XText[rsHasBeenSelected];
  end;

  if s = '' then
    ModalResult := mrOK // surely no mrOK
  else begin
    if MessageDlg(s + #13 + #13 + XText[rsAreYouSureContinue], mtWarning, [mbYes, mbCancel], 0) = mrYes then
      ModalResult := mrOK;
  end;
end;


procedure TfrmReport.bSelectAllClick(Sender: TObject);
begin
  SetAll(True);
end;


procedure TfrmReport.bSelectNoneClick(Sender: TObject);
begin
  SetAll(False);
end;


procedure TfrmReport.bHelpClick(Sender: TObject);
 begin
  THelp.OpenHelpPage('savereporst.htm');
end;


procedure TfrmReport.sbTreeReportClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsTreeFiles] + ' (*.xcrtree)|*.xcrtree',
                                    '.xcrtree',
                                    TUtility.GetDefaultFileName('.xcrtree', XText[rsReport] + '_' + XText[rsExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    eTreeReport.Text := lFileName;

    if not(cbTreeReport.Checked) then begin
      cbTextReportClick(cbTreeReport);
    end;
  end;
end;


procedure TfrmReport.SetAll(aStatus : boolean);
begin
  aStatus := not(aStatus);

  cbCSVReport.Checked      := aStatus;
  cbHTMLReport.Checked     := aStatus;
  cbTextReport.Checked     := aStatus;
  cbTreeReport.Checked     := aStatus;
  cbXinorbisReport.Checked := aStatus;
  cbXMLReport.Checked      := aStatus;

  cbTextReportClick(cbCSVReport);
  cbTextReportClick(cbHTMLReport);
  cbTextReportClick(cbTextReport);
  cbTextReportClick(cbTreeReport);
  cbTextReportClick(cbXinorbisReport);
  cbTextReportClick(cbXMLReport);

  SetSaveStatus;
end;


function TfrmReport.GetFileName(aFolder, aFileName : string): string;
begin
  if FFolder <> '' then
    Result := FFolder + aFileName
  else
    Result := aFolder + aFileName
end;


procedure TfrmReport.ChangeFolders(aFolder : string);
var
  t : integer;
  lFileName : string;

begin
  for t := 1 to 6 do begin
    if FEdits[t].Text <> '' then begin
      lFileName := ExtractFileName(FEdits[t].Text);

      FEdits[t].Text := aFolder + lFileName;
    end;
  end;
end;


procedure TfrmReport.SetSaveStatus;
var
  t : integer;
  lStatus : boolean;

begin
  if GScanDetails[FDataIndex].Files.Count = 0 then begin
    lStatus := False;
  end
  else begin
    lStatus := False;

    for t := 1 to 6 do begin
      if FChecks[t].Checked then
        lStatus := True;
    end;
  end;

  bSave.Enabled              := lStatus;
  bGenerateFilenames.Enabled := lStatus;
end;


end.
