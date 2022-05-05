{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: April 23rd 2009
  Last Modified: January 11th 2020
}


unit X.Form.FileSpread;

interface

uses
  Windows, Messages, System.UITypes, SysUtils, Variants, Classes, Graphics, Controls, Forms, math,
  Dialogs, ExtCtrls, VCLTee.TeeProcs, VCLTee.TeEngine, VCLTee.Chart, StdCtrls, Buttons, VCLTee.Series,
  Menus, ComCtrls, AdvSmoothTabPager, AdvOfficeButtons, HTMLabel,
  VclTee.TeeGDIPlus,

  TMSLogging,

  X.Dialogs.Save,

  X.Utility, X.Formatting, X.Windows, X.ChartUtility, X.Global, X.Help,
  X.GlobalObjects, X.Dialogs.Dialog, X.SystemGlobal, X.GuiLogic, X.ThemeHelper,
  X.Settings, X.CFileObject, X.Constants, X.CUserData, X.Conversions, X.LanguageHandler;


type
  TfrmSpread = class(TForm)
    Panel1: TPanel;
    bGo: TBitBtn;
    gbChart: TGroupBox;
    Panel2: TPanel;
    vtcSpread: TChart;
    pHeader: TPanel;
    Series1: TBarSeries;
    puChart: TPopupMenu;
    miOptions: TMenuItem;
    miSaveChart: TMenuItem;
    miCopyToClipboard: TMenuItem;
    N1: TMenuItem;
    miSaveData: TMenuItem;
    GroupBox3: TGroupBox;
    Series2: TBarSeries;
    bHelp: TBitBtn;
    gbUsers: TGroupBox;
    cbUsers: TComboBox;
    pcFS: TAdvSmoothTabPager;
    tsFileSize: TAdvSmoothTabPage;
    tsBenfordsLaw: TAdvSmoothTabPage;
    lMoreDetail: TLabel;
    lBGR: TLabel;
    eCoEff: TEdit;
    cbUnit: TComboBox;
    cbBLNormal: TAdvOfficeCheckBox;
    rbCMulti: TAdvOfficeRadioButton;
    rbCGradient: TAdvOfficeRadioButton;
    cbLog: TAdvOfficeCheckBox;
    cbRange: TAdvOfficeCheckBox;
    eRangeFrom: TEdit;
    cbRangeFrom: TComboBox;
    eRangeTo: TEdit;
    cbRangeTo: TComboBox;
    Label2: TLabel;
    lData: THTMLabel;
    cbAutoRefresh: TAdvOfficeCheckBox;
    bExportCSV: TBitBtn;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure bGoClick(Sender: TObject);
    procedure cbLogClick(Sender: TObject);
    procedure vtcSpreadMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure eCoEffKeyPress(Sender: TObject; var Key: Char);
    procedure FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
    procedure BuildFileSpread;
    procedure BuildBenfordsLaw;
    procedure miSaveChartClick(Sender: TObject);
    procedure miCopyToClipboardClick(Sender: TObject);
    procedure miSaveDataClick(Sender: TObject);
    procedure lMoreDetailClick(Sender: TObject);
    procedure pcFSxxChange(Sender: TObject);
    procedure bHelpClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure cbBLNormalClick(Sender: TObject);
    procedure cbUsersChange(Sender: TObject);
    procedure rbCMultiClick(Sender: TObject);
    procedure eCoEffEnter(Sender: TObject);
    procedure eCoEffExit(Sender: TObject);
    procedure bExportCSVClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    FOldText : string;
    FDataIndex     : integer;

    coeff, lf, sx : int64;
    spread        : array of integer;
    benford       : array[1..9] of integer;

    FULSP : TUpdateLeftStatusPanel;

    procedure ExportData(aFileName : string);

    procedure SetTheme;
  public
    property OnHide : TUpdateLeftStatusPanel read FULSP write FULSP;
  end;

var
  frmSpread: TfrmSpread;

procedure DoSpread(whichDataIndex : integer);

implementation

{$R *.dfm}


const
  nd : array[1..9] of string = ('30.10', '17.61', '12.49', '9.69', '7.92', '6.69',  '5.80',  '5.12',  '4.58');

  CUnitBytes     = 0;
  CUnitKilobytes = 1;
  CUnitMegabytes = 2;
  CUnitGigabytes = 3;


procedure DoSpread(whichDataIndex : integer);
 begin
  frmSpread.FDataIndex := whichDataIndex;

  frmSpread.Show;
end;


procedure TfrmSpread.FormShow(Sender: TObject);
 var
  t : integer;
  xfo : TFileObject;
  fd : TFormDetails;

 begin
  // ===========================================================================

  cbRangeFrom.Items.Clear;
  cbRangeTo.Items.Clear;
  cbUnit.Items.Clear;

  cbRangeFrom.Items.Add(XText[rsXBytes]);
  cbRangeFrom.Items.Add(XText[rsXKilobytes]);
  cbRangeFrom.Items.Add(XText[rsXMegabytes]);
  cbRangeFrom.Items.Add(XText[rsXGigabytes]);
  cbRangeTo.Items.Add(XText[rsXBytes]);
  cbRangeTo.Items.Add(XText[rsXKilobytes]);
  cbRangeTo.Items.Add(XText[rsXMegabytes]);
  cbRangeTo.Items.Add(XText[rsXGigabytes]);
  cbUnit.Items.Add(XText[rsXBytes]);
  cbUnit.Items.Add(XText[rsXKilobytes]);
  cbUnit.Items.Add(XText[rsXMegabytes]);
  cbUnit.Items.Add(XText[rsXGigabytes]);

  // ===========================================================================

  tsFileSize.Caption        := XText[rsFileSize];
  bGo.Caption               := XText[rsShow];
  lBGR.Caption              := XText[rsBarGraphResolution];
  cbBLNormal.Caption        := XText[rsNormalDistribution];
  lMoreDetail.Caption       := XText[rsMoreDetail];
  cbRange.Caption           := XText[rsRange];
  gbChart.Caption           := ' ' + XText[rsChart] + ' ';
  rbCMulti.Caption          := XText[rsMultiColoured];
  rbCGradient.Caption       := XText[rsGradient];
  cbLog.Caption             := XText[rsLogarthmic];
  Caption                   := XText[rsFileSizeSpread];
  bHelp.Caption             := XText[rsHelp];
  miOptions.Caption         := XText[rsChartOptions];
  miSaveChart.Caption       := XText[rsSaveChart];
  miCopyToClipboard.Caption := XText[rsCopyChartToClipboard];
  miSaveData.Caption        := XText[rsSaveData];

  cbAutoRefresh.Caption     := XText[rsAutoRefresh];

  // ===========================================================================

  gbUsers.Caption           := XText[rsUsers];

  cbUsers.Items.Add(XText[rsAll]);

  for t := 0 to GScanDetails[FDataIndex].Users.Count - 1 do begin
    cbUsers.Items.Add(GScanDetails[FDataIndex].Users[t].Name);
  end;

  cbUsers.ItemIndex := 0;

  // ===========================================================================

  cbUnit.ItemIndex      := CUnitKilobytes;
  cbRangeFrom.ItemIndex := CUnitKilobytes;
  cbRangeTo.ItemIndex   := CUnitKilobytes;

  // ===========================================================================

  fd := XSettings.LoadFormDetails(_FormFileSpread);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  // ===========================================================================

  lf := 0;

  for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
    xfo := GScanDetails[FDataIndex].Files.Items[t];

    if xfo.FileSize > lf then lf := xfo.FileSize;
  end;

  if GScanDetails[FDataIndex].Files.Count = 0 then
    bGo.Enabled := False;
end;


procedure TfrmSpread.FormCreate(Sender: TObject);
begin
  SetTheme;
end;


procedure TfrmSpread.FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
 begin
  MinHeight := 511;
  MinWidth  := 600;
end;


procedure TfrmSpread.FormClose(Sender: TObject; var Action: TCloseAction);
 var
  fd : TFormDetails;

 begin
  fd.formID := _FormFileSpread;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  if Assigned(FULSP) then
    FULSP(_FormFileSpread);

  Action := caHide;
end;


procedure TfrmSpread.SetTheme;
begin
  TThemeHelper.SetSmoothTabPager(pcFS);

  TThemeHelper.SetSmoothTabPage(tsFileSize);
  TThemeHelper.SetSmoothTabPage(tsBenfordsLaw);
end;


procedure TfrmSpread.bExportCSVClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsCSVFiles] + ' (*.csv)|*.csv',
                                    '.csv',
                                    TUtility.GetDefaultFileName('.csv', XText[rsFileSizeSpread] + '_' + XText[rsReport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    ExportData(lFileName);
  end;
end;


procedure TfrmSpread.bGoClick(Sender: TObject);
 begin
  if GScanDetails[FDataIndex].Files.Count <> 0 then begin
    lData.HTMLText[0] := XText[rsPleaseWait];
    lData.Refresh;

    if pcFS.ActivePageIndex = 0 then begin
      BuildFileSpread;
    end
    else begin
      BuildBenfordsLaw;
    end;

    lData.HTMLText[0] := '';
  end
end;


procedure TfrmSpread.BuildFileSpread;
 var
  t, maxhit, x, colx, userid : integer;
  xfo : TFileObject;
  rfrom, rto : int64;
  canadd : boolean;

 begin
  rfrom := -1;
  rto   := -1;

  Screen.Cursor := crHourGlass;

  vtcSpread.SeriesList.Items[1].Active := False;
  vtcSpread.BottomAxis.Visible         := False;
  vtcSpread.LeftAxis.Title.Caption     := XText[rsQuantity];

  if cbRange.Checked then begin
    case cbRangeFrom.ItemIndex of
      CUnitBytes     : rfrom := StrToInt64(eRangeFrom.Text);
      CUnitKilobytes : rfrom := StrToInt64(eRangeFrom.Text) * 1024;
      CUnitMegabytes : rfrom := StrToInt64(eRangeFrom.Text) * 1024 * 1024;
      CUnitGigabytes : rfrom := StrToInt64(eRangeFrom.Text) * 1024 * 1024 * 1024;
    end;

    case cbRangeTo.ItemIndex of
      CUnitBytes     : rto := StrToInt64(eRangeTo.Text);
      CUnitKilobytes : rto := StrToInt64(eRangeTo.Text) * 1024;
      CUnitMegabytes : rto := StrToInt64(eRangeTo.Text) * 1024 * 1024;
      CUnitGigabytes : rto := StrToInt64(eRangeTo.Text) * 1024 * 1024 * 1024;
    end;

    if (rto = -1) or (rfrom = -1) then
      ShowXDialog('Error: BuildFileSpread',
                  'Error: BuildFileSpread',
                  XDialogTypeWarning);
  end;

  // ===========================================================================
  // ===========================================================================

  case cbUnit.ItemIndex of
    CUnitBytes     : begin
                       sx    := Floor(lf / StrToInt(eCoEff.Text));
                       coeff := StrToInt64(eCoEff.Text);
                     end;
    CUnitKilobytes : begin
                       sx    := Floor(lf / ((StrToInt(eCoEff.Text) * 1024)));
                       coeff := StrToInt64(eCoEff.Text) * 1024;
                     end;
    CUnitMegabytes : begin
                       sx    := Floor(lf / (StrToInt(eCoEff.Text) * 1024 * 1024));
                       coeff := StrToInt64(eCoEff.Text) * 1024 * 1024;
                     end;
    CUnitGigabytes : begin
                       sx    := Floor(lf / (StrToInt64(eCoEff.Text) * 1024 * 1024 * 1024));
                       coeff := StrToInt64(eCoEff.Text) * 1024 * 1024 * 1024;
                     end;
  end;

  SetLength(spread, sx + 1);

  for t := 0 to sx do
    spread[t] := 0;

  if cbUsers.ItemIndex = 0 then begin // optimised for all users
    for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
      xfo := GScanDetails[FDataIndex].Files.Items[t];

      if (faDirectory and xfo.Attributes) <> faDirectory then begin
        x := Floor(xfo.FileSize / coeff);

        inc(spread[x]);
      end;
    end;
  end
  else begin
    userid := TUtility.FindUserIndex(FDataIndex, cbUsers.Items[cbUsers.ItemIndex]);

    for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
      xfo := GScanDetails[FDataIndex].Files.Items[t];

      if (faDirectory and xfo.Attributes) <> faDirectory then begin
        if xfo.owner = userid then begin
          x := Floor(xfo.FileSize / coeff);

          inc(spread[x]);
        end;
      end;
    end;
  end;

  // ===========================================================================
  // ===========================================================================

  maxhit := 0;
  
  for t := 0 to sx do begin
    if spread[t] > maxhit then maxhit := spread[t];
  end;

  // ===========================================================================
  // ===========================================================================

  vtcSpread.SeriesList.Items[0].Clear;
  for t := 0 to sx do begin
    canadd := True;

    if cbRange.Checked then begin
      if (coeff * t >= rfrom) and (coeff * t <= rto) then
        canadd := True
      else
        canadd := False;
    end;

    if canadd then begin
      if rbCGradient.Checked then begin
        colx := Round((spread[t] / maxhit) * 255);

        if colx < 0 then   colx := 0;
        if colx > 255 then colx := 255;

        colx := $FFFFFF - ((colx * 65536) + (colx * 256) + colx);
      end
      else
        colx := spectrumcolours[t mod spectrummod];

      if spread[t] <> 0 then
        vtcSpread.SeriesList.Items[0].Add(spread[t], '', colx)
      else
        vtcSpread.SeriesList.Items[0].Add(spread[t], '', $00ffffff);
    end;
  end;

  Screen.Cursor := crDefault;
end;


procedure TfrmSpread.BuildBenfordsLaw;
 var
  t,i,jf : integer;
  zig : double;
  s : string;
  xfo : TFileObject;

 begin
  Screen.Cursor := crHourGlass;

  vtcSpread.SeriesList.Items[1].Active := cbBLNormal.Checked;
  vtcSpread.BottomAxis.Visible         := True;
  vtcSpread.LeftAxis.Title.Caption     := '%';

  for t := 1 to 9 do
    benford[t] := 0;

  jf := 0;
  for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
    xfo := GScanDetails[FDataIndex].Files.Items[t];

    if (faDirectory and xfo.Attributes) = 0 then begin
      if xfo.FileSize <> 0 then begin
        s := IntToStr(xfo.FileSize);

        i := Ord(s[1]) - 48;

        inc(benford[i]);

        inc(jf);
      end;
    end;
  end;

  vtcSpread.SeriesList.Items[0].Clear;
  vtcSpread.SeriesList.Items[1].Clear;

  for t := 1 to 9 do begin
    if jf <> 0 then
      zig := (benford[t] / jf) * 100
    else
      zig := 0;

    vtcSpread.SeriesList.Items[0].Add(zig, IntToStr(t), spectrumcolours[t mod spectrummod]);

    if cbBLNormal.Checked then begin
      zig := (log10(t + 1) - log10(t)) * 100;

      vtcSpread.SeriesList.Items[1].Add(zig, IntToStr(t), $D6D5DB);
    end;
  end;

  Screen.Cursor := crDefault;
end;


procedure TfrmSpread.cbBLNormalClick(Sender: TObject);
begin
  if cbAutoRefresh.Checked then
    bGoClick(Nil);
end;


procedure TfrmSpread.cbLogClick(Sender: TObject);
 begin
  if cbLog.Checked then
    vtcSpread.LeftAxis.Logarithmic := True
  else
    vtcSpread.LeftAxis.Logarithmic := False;
end;


procedure TfrmSpread.cbUsersChange(Sender: TObject);
begin
  if cbAutoRefresh.Checked then
    bGoClick(Nil);
end;


procedure TfrmSpread.vtcSpreadMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
 var
  AValueIndex :Integer;
  s : string;

 begin
  AValueIndex := vtcSpread.SeriesList[0].GetCursorValueIndex;

  if vtcSpread.SeriesList[1].Active then begin
    if AValueIndex = -1 then
      AValueIndex := vtcSpread.SeriesList[1].GetCursorValueIndex;
  end;

  if AValueIndex > -1 then begin
    if pcFS.ActivePageIndex = 0 then begin
      s := TConvert.ConvertToUsefulUnit(AValueIndex * coeff) + ' -> ' + TConvert.ConvertToUsefulUnit((AValueIndex * coeff) + coeff) + ' ( ';
      s := s + FloatToStr(vtcSpread.SeriesList[0].YValue[AValueIndex]) + ' )';

      lData.HTMLText[0] := s;
    end
    else begin
      lData.HTMLText[0] := '"' + IntToStr(AValueIndex + 1) +
                                 '" <b>' + FloatToStrF(vtcSpread.SeriesList[0].YValue[AValueIndex], ffFixed, 7, 2, XinorbisFormatSettings) + '%</b> (' +
                                 IntToStr(benford[AValueIndex + 1]) + ' ' + XText[rsFiles] + ')  (normal distribution: ' + nd[AValueIndex + 1] + '%)';
    end;
  end
  else begin
    lData.HTMLText[0] := 'n/a';
  end;
end;


procedure TfrmSpread.eCoEffEnter(Sender: TObject);
begin
  FOldText := TEdit(Sender).Text;
end;


procedure TfrmSpread.eCoEffExit(Sender: TObject);
var
  lValue : integer;
begin
  lValue := StrToIntDef(TEdit(Sender).Text, -1);

  if lValue = -1 then
    TEdit(Sender).Text := FOldText;
end;


procedure TfrmSpread.eCoEffKeyPress(Sender: TObject; var Key: Char);
 begin
  if (Key = #13) and (TEdit(Sender).Text <> '') then
    if cbAutoRefresh.Checked then
      bGoClick(Nil);
end;


procedure TfrmSpread.miSaveChartClick(Sender: TObject);
 var
  mychart : TChart;
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsPNGFiles] + ' (*.png)|*.png',
                                    '.png',
                                    TUtility.GetDefaultFileName('.png', XText[rsFileSizeSpread]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

    TChartUtility.SaveChartToPNG(mychart, lFileName);
  end;
end;


procedure TfrmSpread.miCopyToClipboardClick(Sender: TObject);
 var
  mychart : TChart;

 begin
  mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  TChartUtility.CopyChartToClipboard(mychart);
end;


procedure TfrmSpread.miSaveDataClick(Sender: TObject);
 var
  tf : TextFile;
  t : integer;
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsTextFiles] + ' (*.txt)|*.txt',
                                    '.txt',
                                    TUtility.GetDefaultFileName('.txt', XText[rsFileSizeSpread] + '_' + XText[rsReport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    AssignFile(tf, lFileName);

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsWarning],
                  XText[rsErrorSaving] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      for t := 0 to sx do begin
        Writeln(tf,GScanDetails[FDataIndex].ScanPath);
        Writeln(tf, XText[rsCreated] + ': ' + TUtility.GetTime(GETTIMEFORMAT_DISPLAY) + ' ' + TUtility.GetDate(GETTIMEFORMAT_DISPLAY));
        Writeln(tf, '');
        Writeln(tf, XText[rsInterval] + ': ' + eCoEff.Text + ' ' + cbUnit.Text);
        Writeln(tf, '');

        if cbRange.Checked then begin
          Writeln(tf, XText[rsRange] + ' : ' + eRangeFrom.Text + ' ' + cbRangeFrom.Text);
          Writeln(tf, TXFormatting.AddLeading('', Length(XText[rsRange]) + 3, ' ') + eRangeTo.Text + ' ' + cbRangeTo.Text);
          Writeln(tf, '');
        end;

        Writeln(tf, TXFormatting.AddLeading(IntToStr(spread[t]), 7, ' ') + ' : ' + TConvert.ConvertToUsefulUnit(t * coeff) + ' <= x < ' + TConvert.ConvertToUsefulUnit((t * coeff) + coeff - 1));
      end;

      CloseFile(tf);
    end;
    {$I+}
  end;
end;


procedure TfrmSpread.lMoreDetailClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'http://en.wikipedia.org/wiki/Benford''s_law', '', '');
end;


procedure TfrmSpread.pcFSxxChange(Sender: TObject);
 begin
  if cbAutoRefresh.Checked then
    bGoClick(Nil);
end;


procedure TfrmSpread.rbCMultiClick(Sender: TObject);
 begin
  if cbAutoRefresh.Checked then
    bGoClick(Nil);
end;


procedure TfrmSpread.bHelpClick(Sender: TObject);
 begin
  THelp.OpenHelpPage('a11.htm');
end;


procedure TfrmSpread.ExportData(aFileName : string);
var
  tf : TextFile;
  t : integer;

begin
  if (vtcSpread.SeriesList[0].Count <> 0) then begin

    AssignFile(tf, aFilename);
    {$I-}
    Rewrite(tf);
    {$I+}

    if (IOResult <> 0) then begin
      TMSLogger.Error('Error writing CSV file "' + aFileName + '".');
     end
     else begin
       writeln(tf, 'RangeFromBytes,RangeToBytes,Range,Quantity');

       for t := 0 to vtcSpread.SeriesList[0].Count - 1 do begin
         writeln(tf, IntToStr(t * coeff) + ',' +
                     IntToStr((t * coeff) + coeff - 1) + ',' +
                     '"' + TConvert.ConvertToUsefulUnit(t * coeff) + ' -> ' + TConvert.ConvertToUsefulUnit((t * coeff) + coeff - 1) + '",' +
                     FloatToStr(vtcSpread.SeriesList[0].YValue[t]));
       end;

       CloseFile(tf);
     end;
  end
  else
    ShowXDialog(XText[rsWarning],
                XText[rsNoDataToExport],
                XDialogTypeWarning);
end;


end.
