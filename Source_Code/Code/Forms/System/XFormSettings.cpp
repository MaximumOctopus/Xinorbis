//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormSettings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm23 *Form23;
//---------------------------------------------------------------------------
__fastcall TForm23::TForm23(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------




/*


unit X.Form.Preferences;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ShlObj, System.UITypes, System.IniFiles, System.Win.Registry, StdCtrls,
  Buttons, ExtCtrls, ComCtrls, ImgList, Grids, BaseGrid, AdvGrid,
  Menus, X.Settings, IdBaseComponent, IdComponent, IdTCPConnection,
  IdTCPClient, IdExplicitTLSClientServerBase, IdFTP, ToolWin,
  AeroButtons, AdvOfficeButtons, AdvSmoothTabPager, AdvSmoothSlider, AdvUtil, AdvObj,

  TMSLogging,

  X.Utility, X.Windows,
  X.Global, X.CReportOptions, X.Help,

  X.Dialogs.Save, X.Dialogs.Load,

  X.FileExtensionsObject, X.FileExtension, X.Constants, X.Dialogs.Dialog,
  X.Conversions, X.LanguageHandler, X.CScanHistoryObject, X.SystemGlobal;


type
  TfrmFileTypes = class(TForm)
    bSave: TBitBtn;
    bCancel: TBitBtn;
    cdMain: TColorDialog;
    bHelp: TBitBtn;
    pPostScan: TPanel;
    pOptimisations: TPanel;
    pPaths: TPanel;
    pFavourites: TPanel;
    GroupBox4: TGroupBox;
    SpeedButton14: TSpeedButton;
    SpeedButton13: TSpeedButton;
    SpeedButton11: TSpeedButton;
    SpeedButton12: TSpeedButton;
    sbQFExplore: TSpeedButton;
    lQuickFolders: TLabel;
    lbQuickFolders: TListBox;
    pNavigate: TPanel;
    pTemp: TPanel;
    lTypesOfTempFile: TLabel;
    sbTemp: TSpeedButton;
    eDeleteTemp: TSpeedButton;
    lbTemp: TListBox;
    pGeneral: TPanel;
    lGeneral: TLabel;
    lPaths: TLabel;
    lOptimisations: TLabel;
    lPostScan: TLabel;
    lTemp: TLabel;
    lNavigate: TLabel;
    lFavourites: TLabel;
    Bevel10: TBevel;
    puFSpecial: TPopupMenu;
    miFSH1: TMenuItem;
    miFSH2: TMenuItem;
    miFSH3: TMenuItem;
    miFSH4: TMenuItem;
    miFSH5: TMenuItem;
    sNL2: TShape;
    sNL3: TShape;
    lNRightSideProgress: TLabel;
    lNLeftSideProgress: TLabel;
    sNL4: TShape;
    sNL1: TShape;
    Bevel3: TBevel;
    lTableRowHeight: TLabel;
    lDateFormat: TLabel;
    lMaxSearchResults: TLabel;
    lDefaultMaxSearchResults: TLabel;
    lRowHeight: TLabel;
    tDataFolder: TLabel;
    sbXinorbisFolder: TSpeedButton;
    tCustomViewer: TLabel;
    sbGCustomViewer: TSpeedButton;
    lProgressUpdate: TLabel;
    sNL5: TShape;
    sNL6: TShape;
    lNAllOtherTables: TLabel;
    Panel1: TPanel;
    rbNPostScan: TAdvOfficeRadioButton;
    rbSPostScan: TAdvOfficeRadioButton;
    rbIPPostScan: TAdvOfficeRadioButton;
    rbFSPostScan: TAdvOfficeRadioButton;
    eRowHeight: TEdit;
    eMaxSearchResults: TEdit;
    cbDateFormat: TComboBox;
    eXinorbisFolder: TEdit;
    eGCustomViewer: TEdit;
    eAddTemp: TEdit;
    cbProgressUpdate: TComboBox;
    eShowFilesInTypeBoxLimit: TEdit;
    cbIPPostScan: TComboBox;
    cbAutoCheckUpdates: TAdvSmoothSlider;
    GroupBox1: TGroupBox;
    bGResetGraphGradients: TBitBtn;
    bClearScanHistory: TBitBtn;
    cbFHEnable: TAdvSmoothSlider;
    cbFHLogEnable: TAdvSmoothSlider;
    cbAllowSQLInSearch: TAdvSmoothSlider;
    lAutoCheckUpdates: TLabel;
    lFHEnable: TLabel;
    lFHLogEnable: TLabel;
    lAllowSQLInSearch: TLabel;
    cbOJustInTime: TAdvSmoothSlider;
    cbOBuildDateTree: TAdvSmoothSlider;
    cbShowFilesInTypeBox: TAdvSmoothSlider;
    cbShowFilesInTypeBoxLimit: TAdvSmoothSlider;
    cbOGetUserDetails: TAdvSmoothSlider;
    lOJustInTime: TLabel;
    lOBuildDateTree: TLabel;
    lShowFilesInTypeBox: TLabel;
    lShowFilesInTypeBoxLimit: TLabel;
    lOGetUserDetails: TLabel;
    sgNavigationSide: TAdvStringGrid;
    cbSaveLog: TAdvSmoothSlider;
    lSaveLog: TLabel;
    bClearAllSettings: TBitBtn;
    cbOGetTempFiles: TAdvSmoothSlider;
    lOGetTempFiles: TLabel;
    sbGeneral: TSpeedButton;
    sbPostScan: TSpeedButton;
    sbOptimisations: TSpeedButton;
    sbPaths: TSpeedButton;
    sbAppearance: TSpeedButton;
    sbFavourites: TSpeedButton;
    sbTempFiles: TSpeedButton;
    procedure SaveUsersPath;
    procedure FormCreate(Sender: TObject);
    procedure bHelpClick(Sender: TObject);
    procedure SetLanguage;
    procedure eAddTempKeyPress(Sender: TObject; var Key: Char);
    procedure sbTempClick(Sender: TObject);
    procedure eDeleteTempClick(Sender: TObject);
    procedure eAddTempChange(Sender: TObject);
    procedure sbGCustomViewerClick(Sender: TObject);
    procedure SpeedButton12Click(Sender: TObject);
    procedure SpeedButton11Click(Sender: TObject);
    procedure SpeedButton14Click(Sender: TObject);
    procedure SpeedButton13Click(Sender: TObject);
    procedure Shape6MouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure sbQFExploreClick(Sender: TObject);
    procedure sbXinorbisFolderClick(Sender: TObject);
    procedure bClearScanHistoryClick(Sender: TObject);
    procedure lbTempClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure miFSH1Click(Sender: TObject);
    procedure sbPostScanClick(Sender: TObject);
    procedure bGResetGraphGradientsClick(Sender: TObject);
    procedure cbFHEnableStateChanged(Sender: TObject;
      State: TAdvSmoothSliderState; Value: Double);
    procedure sgNavigationSideDrawCell(Sender: TObject; ACol,
      ARow: Integer; Rect: TRect; State: TGridDrawState);
    procedure cbShowFilesInTypeBoxStateChanged(Sender: TObject;
      State: TAdvSmoothSliderState; Value: Double);
    procedure bClearAllSettingsClick(Sender: TObject);
  private
    olduserpath       : string;
    opentabatstart    : integer;

    bargraphs         : array[1..6] of TShape;

    function  SliderStateToBoolean(aState : TAdvSmoothSliderState): boolean;
    function  BooleanToSliderState(aBoolean : boolean): TAdvSmoothSliderState;
    procedure BuildNavigationTable;
  public
  end;


var
  frmFileTypes: TfrmFileTypes;


function DoFileTypePrefs(OpenAtTab : integer): integer;


implementation


{$R *.DFM}


const
  ChartCount = 19;

  CPagePostScan      = 0;
  CPageOptimisations = 1;
  CPagePaths         = 2;
  CPageGeneral       = 3;
  CPageNavigate      = 4;
  CPageUNUSED        = 5;
  CPageFavourites    = 6;
  CPageTemp          = 7;

  Things : array[1..10] of string = ('Guineasaurus Rex', 'Giant wooden badgers', 'Roswell Rods', 'Cheesy comestibles', 'Anne Elk (Mrs)',
                                     'Shatner''s Bassoon', 'Jelly (green)', 'Solo Polo vision', 'Fluffy kittens', 'Hovercraft full of eels');


function DoFileTypePrefs(OpenAtTab : integer): integer;
 var
  t : integer;
  tfx : TFileExtension;

 begin
  with TfrmFileTypes.Create(Application) do
    try
      SetLanguage;

      opentabatstart := OpenAtTab;

      olduserpath := GSystemGlobal.AppDataPath;

      // -----------------------------------------------------------------------

      cbOBuildDateTree.State            := BooleanToSliderState(not(XSettings.Optimisations.BuildDateTree));
      cbOGetUserDetails.State           := BooleanToSliderState(not(XSettings.Optimisations.GetUserDetails));
      cbOGetTempFiles.State             := BooleanToSliderState(not(XSettings.Optimisations.GetTempFiles));
      cbOJustInTime.State               := BooleanToSliderState(not(XSettings.Optimisations.JustInTimeDisplay));
      cbShowFilesInTypeBox.State        := BooleanToSliderState(XSettings.Optimisations.AddToDate);
      cbShowFilesInTypeBoxStateChanged(cbShowFilesInTypeBox, cbShowFilesInTypeBox.State, 0);
      cbShowFilesInTypeBoxLimit.State   := BooleanToSliderState(XSettings.Optimisations.AddToDateLimit);
      eShowFilesInTypeBoxLimit.Text     := IntToStr(XSettings.Optimisations.AddToDateLimitCount);
      cbProgressUpdate.ItemIndex        := XSettings.Optimisations.ProgressUpdate;

      eXinorbisFolder.Text              := GSystemGlobal.AppDataPath;
      eGCustomViewer.Text               := XSettings.General.CustomViewer;

      cbFHEnable.State                  := BooleanToSliderState(XSettings.HistorySettings.Enabled);
      cbFHLogEnable.State               := BooleanToSliderState(XSettings.HistorySettings.FullLogging);
      cbAllowSQLInSearch.State          := BooleanToSliderState(XSettings.HistorySettings.SQLinSearch);
      cbFHEnableStateChanged(cbFHEnable, cbFHEnable.State, 0);

      cbSaveLog.State                   := BooleanToSliderState(XSettings.General.SaveLog);

      cbDateFormat.ItemIndex            := XSettings.General.DateFormat;
      eRowHeight.Text                   := IntToStr(XSettings.General.RowHeight);
      eMaxSearchResults.Text            := IntToStr(XSettings.General.MaxSearchResults);

      cbAutoCheckUpdates.State          := BooleanToSliderState(XSettings.General.AutoCheckUpdate);

      // =======================================================================

      case XSettings.General.PostScanMode of
        CPostScanNothing     : rbNPostScan.Checked  := True;
        CPostScanSummary     : rbSPostScan.Checked  := True;
        CPostScanInformation : rbIPPostScan.Checked := True;
        CPostScanStructure   : rbFSPostScan.Checked := True;
      end;

      cbIPPostScan.ItemIndex := XSettings.General.PostScanIPPage;

      // update temporary file type list
      for t := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
        tfx := FileExtensionsObject.CategoryExtensions[t];

        if tfx.Category = 0 then begin
          if lbTemp.Items.IndexOf(tfx.Name) = -1 then
            lbTemp.Items.Add(tfx.Name);
        end;
      end;

      for t := 1 to QuickFolderCount do begin
        if XSettings.XSQuickFolder[t] <> '' then
          lbQuickFolders.Items.Add(XSettings.XSQuickFolder[t]);
      end;

      // =======================================================================

      bargraphs[1] := sNL1;
      bargraphs[2] := sNL2;
      bargraphs[3] := sNL3;
      bargraphs[4] := sNL4;
      bargraphs[5] := sNL5;
      bargraphs[6] := sNL6;

      for t := 1 to 6 do
        bargraphs[t].Brush.Color := XSettings.Navigation.BarColours[t];

      BuildNavigationTable;

      // =======================================================================

      ShowModal;

      Result := ModalResult;

      if ModalResult = mrOK then begin
        XSettings.Optimisations.BuildDateTree       := not SliderStateToBoolean(cbOBuildDateTree.State);
        XSettings.Optimisations.GetUserDetails      := not SliderStateToBoolean(cbOGetUserDetails.State);
        XSettings.Optimisations.GetTempFiles        := not SliderStateToBoolean(cbOGetTempFiles.State);

        XSettings.Optimisations.JustInTimeDisplay   := not SliderStateToBoolean(cbOJustInTime.State);
        XSettings.Optimisations.AddToDate           := SliderStateToBoolean(cbShowFilesInTypeBox.State);
        XSettings.Optimisations.AddToDateLimit      := SliderStateToBoolean(cbShowFilesInTypeBoxLimit.State);
        XSettings.Optimisations.AddToDateLimitCount := StrToIntDef(eShowFilesInTypeBoxLimit.Text, 5000);
        XSettings.Optimisations.ProgressUpdate      := cbProgressUpdate.ItemIndex;

        XSettings.General.DateFormat          := cbDateFormat.ItemIndex;
        XSettings.General.MaxSearchResults    := StrToIntDef(eMaxSearchResults.Text, 10000);
        XSettings.General.RowHeight           := StrToIntDef(eRowHeight.Text, 17);
        XSettings.General.CustomViewer        := eGCustomViewer.Text;

        XSettings.HistorySettings.Enabled     := SliderStateToBoolean(cbFHEnable.State);
        XSettings.HistorySettings.FullLogging := SliderStateToBoolean(cbFHLogEnable.State);
        XSettings.HistorySettings.SQLinSearch := SliderStateToBoolean(cbAllowSQLInSearch.State);

        XSettings.General.SaveLog             := SliderStateToBoolean(cbSaveLog.State);

        XSettings.General.Autocheckupdate := SliderStateToBoolean(cbAutoCheckUpdates.State);

        // =====================================================================

        if rbNPostScan.Checked then
          XSettings.General.PostScanMode := CPostScanNothing
        else if rbSPostScan.Checked then
          XSettings.General.PostScanMode := CPostScanSummary
        else if rbIPPostScan.Checked then
          XSettings.General.PostScanMode := CPostScanInformation
        else if rbFSPostScan.Checked then
          XSettings.General.PostScanMode := CPostScanStructure;

        XSettings.General.PostScanIPPage := cbIPPostScan.ItemIndex;

        // ---------------------------------------------------------------------

        for t:= FileExtensionsObject.CategoryExtensions.Count - 1 to 0 do
          if FileExtensionsObject.CategoryExtensions[t].Category = 0 then
            FileExtensionsObject.CategoryExtensions.Delete(t);

        for t := 0 to lbTemp.Items.Count - 1 do begin
          tfx := TFileExtension.Create;
          tfx.Name     := lbTemp.Items[t];
          tfx.Category := 0;
          FileExtensionsObject.CategoryExtensions.Add(tfx);
        end;

        // ---------------------------------------------------------------------



        for t := 1 to QuickFolderCount do
          XSettings.XSQuickFolder[t] := '';

        for t := 0 to lbQuickFolders.Count - 1 do
          XSettings.XSQuickFolder[t + 1] := lbQuickFolders.Items[t];

        for t := 1 to 6 do
          XSettings.Navigation.BarColours[t] := bargraphs[t].Brush.Color;

        FileExtensionsObject.SaveFileExtensionLists(XSettings.CustomSettings.SettingsSaveLocation);

        SaveUsersPath;
      end;
    finally
      Free;
  end;
end;


function TfrmFileTypes.SliderStateToBoolean(aState : TAdvSmoothSliderState): boolean;
begin
  if aState = ssOn then
    Result := True
  else
    Result := False;
end;


function TfrmFileTypes.BooleanToSliderState(aBoolean : boolean): TAdvSmoothSliderState;
begin
  if aBoolean then
    Result := ssOn
  else
    Result := ssOff;
end;


procedure TfrmFileTypes.FormCreate(Sender: TObject);
 begin
  miFSH1.Caption       := TXWindows.GetSpecialFolder(5);
  miFSH2.Caption       := TXWindows.GetSpecialFolder(6);
  miFSH3.Caption       := TXWindows.GetSpecialFolder(7);
  miFSH4.Caption       := TXWindows.GetSpecialFolder(8);
  miFSH5.Caption       := TXWindows.GetSpecialFolder(9);

  cbDateFormat.Items.Add(XDate[kDateDD] + '/' + XDate[kDateMM] + '/' + XDate[kDateYYYY]);
  cbDateFormat.Items.Add(XDate[kDateMM] + '/' + XDate[kDateDD] + '/' + XDate[kDateYYYY]);
  cbDateFormat.Items.Add(XDate[kDateYYYY] + '/' + XDate[kDateMM] + '/' + XDate[kDateDD]);
  cbDateFormat.Items.Add(XDate[kDateDD] + '-' + XDate[kDateMM] + '-' + XDate[kDateYYYY]);
  cbDateFormat.Items.Add(XDate[kDateMM] + '-' + XDate[kDateDD] + '-' + XDate[kDateYYYY]);
end;


procedure TfrmFileTypes.SaveUsersPath;
 var
  config : TIniFile;

 begin
  if olduserpath <> eXinorbisFolder.Text then begin
    config := TINIFile.Create(GSystemGlobal.ExePath + 'custom.ini');

    try
      config.WriteString('Main', 'DataPath', eXinorbisFolder.Text);
    finally
      config.Free;
    end;

    ShowXDialog(XText[kWarning], XText[kXinorbisDataFolderChanges], XDialogTypeWarning);
  end;
end;


procedure TfrmFileTypes.bHelpClick(Sender: TObject);
 begin
  THelp.OpenHelpPage('prefs.htm');
end;


procedure TfrmFileTypes.SetLanguage;
 var
  t : integer;

 begin
  Caption := XText[kSettings];

  // ===========================================================================

  sbGeneral.Caption          := XText[kGeneral];
  sbPostScan.Caption         := XText[kPostScan];
  sbOptimisations.Caption    := XText[kOptimisations];
  sbPaths.Caption            := XText[kPaths];

  sbAppearance.Caption       := XText[kAppearance];
  sbFavourites.Caption       := XText[kFavourite];
  sbTempFiles.Caption        := XText[kTempFiles];

  lGeneral.Caption           := XText[kGeneral];
  lPostScan.Caption          := XText[kPostScan];
  lOptimisations.Caption     := XText[kOptimisations];
  lPaths.Caption             := XText[kPaths];
  lTemp.Caption              := XText[kTempFiles];
  lFavourites.Caption        := XText[kFavourite];
  lNavigate.Caption          := XText[kAppearance];

  rbSPostScan.Caption        := XText[kSummary];
  rbIPPostScan.Caption       := XText[kInformationPages];
  rbFSPostScan.Caption       := XText[kFolderStructure];

  // ===========================================================================

  bHelp.Caption              := XText[kHelp];
  bSave.Caption              := XText[kSave];
  bCancel.Caption            := XText[kCancel];

  lQuickFolders.Caption      := XText[kFavourites];

  // ===========================================================================

  tDataFolder.Caption   := XText[kXinorbisDataFolder];
//  tPostScan.Caption     :=LanguageStrings[61];

  rbNPostScan.Caption   := XText[kDoNothing];

  for t:= 0 to 11 do
    cbIPPostScan.Items.Add(LanguageTabs[t]);

  lAutoCheckUpdates.Caption := XText[kAutomaticallyCheckForUpdates];
  lFHEnable.Caption         := XText[kEnableFolderHistory];
  lFHLogEnable.Caption      := XText[kEnableFullFileLogging];
  lAllowSQLInSearch.Caption := XText[kAllowSQLStatementsWhenSearching];

  lSaveLog.Caption          := XText[kSaveLog];

  lTableRowHeight.Caption          := XText[kTableRowHeight];
  lRowHeight.Caption               := '(' + XText[kDefault] + ': 17)';
  lDateFormat.Caption              := XText[kDateFormat];
  lMaxSearchResults.Caption        := XText[kSearchResultLimit];
  lDefaultMaxSearchResults.Caption := '(' + XText[kDefault] + ': 20000)';

  lOBuildDateTree.Caption          := XText[kDontBuildDateTree];
  lOGetUserDetails.Caption         := XText[kDontGetFileOwnerDetails];
  lOGetTempFiles.Caption           := XText[kDontProcessTempFiles];
  lOJustInTime.Caption             := XText[kJIT];
  lShowFilesInTypeBox.Caption      := XText[kAddFileNamesToDateTab];
  lShowFilesInTypeBoxLimit.Caption := XText[kWhenFewer] + ':';
  eShowFilesInTypeBoxLimit.Left    := lShowFilesInTypeBoxLimit.Left + lShowFilesInTypeBoxLimit.Width + 6;
  lProgressUpdate.Caption          := XText[kScanningProgress];

  cbProgressUpdate.Items.Add(XText[kUpdateProgress1]);
  cbProgressUpdate.Items.Add(XText[kUpdateProgress2]);
  cbProgressUpdate.Items.Add(XText[kUpdateProgress3]);
  cbProgressUpdate.Items.Add(XText[kUpdateProgress4]);
  cbProgressUpdate.Items.Add(XText[kUpdateProgress5]);
  cbProgressUpdate.Items.Add(XText[kUpdateProgress6]);

  tCustomViewer.Caption     := XText[kCustomViewer];

  bGResetGraphGradients.Caption := XText[kResetChartGradientColours];
  bClearScanHistory.Caption     := XText[kClearScanHistory];
  bClearAllSettings.Caption     := XText[kRestoreToDefaults];

  // ===========================================================================

  lTypesOfTempFile.Caption := XText[kTypesOfTempFiles];

  // == navigation =============================================================

  lNLeftSideProgress.Caption  := XText[kLeftSideProgressBar];
  lNRightSideProgress.Caption := XText[kRightSideProgressBar];
  lNAllOtherTables.Caption    := XText[kAllOtherTables];
end;


procedure TfrmFileTypes.sgNavigationSideDrawCell(Sender: TObject; ACol,
  ARow: Integer; Rect: TRect; State: TGridDrawState);
var
  zRect : TRect;

begin
  if ARow > 0 then begin
    case ACol of
      2 : begin
            TAdvStringGrid(Sender).Canvas.Brush.Color := sNL1.Brush.Color;
            TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

            if TAdvStringGrid(Sender).Cells[8, ARow] <> '0' then begin
              zRect.Top    := Rect.Top + 1;
              zRect.Bottom := Rect.Bottom - 1;
              zRect.Left   := Rect.Left + 1;
              zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[8, ARow]);

              TAdvStringGrid(Sender).Canvas.Brush.Color := sNL2.Brush.Color;
              TAdvStringGrid(Sender).Canvas.FillRect(zRect);
            end;
          end;
      4 : begin
            TAdvStringGrid(Sender).Canvas.Brush.Color := sNL3.Brush.Color;
            TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

            if TAdvStringGrid(Sender).Cells[8, ARow] <> '0' then begin
              zRect.Top    := Rect.Top + 1;
              zRect.Bottom := Rect.Bottom - 1;
              zRect.Left   := Rect.Left + 1;
              zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[8, ARow]);

              TAdvStringGrid(Sender).Canvas.Brush.Color := sNL4.Brush.Color;
              TAdvStringGrid(Sender).Canvas.FillRect(zRect);
            end;
          end;
      6 : begin
            TAdvStringGrid(Sender).Canvas.Brush.Color := sNL5.Brush.Color;
            TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

            if TAdvStringGrid(Sender).Cells[8, ARow] <> '0' then begin
              zRect.Top    := Rect.Top + 1;
              zRect.Bottom := Rect.Bottom - 1;
              zRect.Left   := Rect.Left + 1;
              zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[8, ARow]);

              TAdvStringGrid(Sender).Canvas.Brush.Color := sNL6.Brush.Color;
              TAdvStringGrid(Sender).Canvas.FillRect(zRect);
            end;
          end;
    end;
  end;
end;


procedure TfrmFileTypes.bClearAllSettingsClick(Sender: TObject);
begin
  if MessageDlg(XText[kRestoreToDefaults] + '?' + #13#13 + XText[kAreYouSureContinue], mtWarning, [mbYes, mbNo], 0) = mrYes then begin

    XSettings.SetAllToDefault;
  end;
end;


procedure TfrmFileTypes.bGResetGraphGradientsClick(Sender: TObject);
begin
  if MessageDlg(XText[kResetChartGradientColours] + #13#13 + XText[kAreYouSureContinue], mtWarning, [mbYes, mbNo], 0) = mrYes then begin
    XSettings.ResetChartGradients;
  end;
end;


procedure TfrmFileTypes.eAddTempKeyPress(Sender: TObject; var Key: Char);
 begin
  if key = #13 then
    sbTempClick(Nil);
end;


procedure TfrmFileTypes.sbTempClick(Sender: TObject);
 begin
  if lbTemp.Items.IndexOf(eAddTemp.Text) = -1 then begin
    lbTemp.Items.Add(eAddTemp.Text);
  end;

  eAddTemp.Text := '';
end;


procedure TfrmFileTypes.eDeleteTempClick(Sender: TObject);
 begin
  lbTemp.DeleteSelected;
end;


procedure TfrmFileTypes.eAddTempChange(Sender: TObject);
 begin
  if eAddTemp.Text = '' then
    sbTemp.Enabled := False
  else
    sbTemp.Enabled := True;
end;


procedure TfrmFileTypes.sbGCustomViewerClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXOpenDialog.ExecuteExe('');

  if lFileName <> '' then
    eGCustomViewer.Text := lFileName;
end;


procedure TfrmFileTypes.sbXinorbisFolderClick(Sender: TObject);
 var
  s : string;

 begin
  s := TXWindows.BrowseForFolder(Handle);

  if s <> '' then begin
    eXinorbisFolder.Text := s;
  end;
end;


procedure TfrmFileTypes.cbShowFilesInTypeBoxStateChanged(Sender: TObject;
  State: TAdvSmoothSliderState; Value: Double);
begin
  cbShowFilesInTypeBoxLimit.Enabled := SliderStateToBoolean(cbShowFilesInTypeBox.State);
  eShowFilesInTypeBoxLimit.Enabled  := SliderStateToBoolean(cbShowFilesInTypeBox.State);
end;


procedure TfrmFileTypes.SpeedButton12Click(Sender: TObject);
 begin
  lbQuickFolders.DeleteSelected;
end;


procedure TfrmFileTypes.sbQFExploreClick(Sender: TObject);
 begin
  if lbQuickFolders.ItemIndex <> -1 then
    TXWindows.ExecuteFile(0, '"' + lbQuickFolders.Items[lbQuickFolders.ItemIndex] + '"', '', '');
end;


procedure TfrmFileTypes.SpeedButton11Click(Sender: TObject);
 var
  s,str : string;
  t : integer;
  found : boolean;

 begin
  if lbQuickFolders.Count < QuickFolderCount then begin
    str := TXWindows.BrowseForFolder(Handle);

    if str <> '' then begin
      s := UpperCase(str);

      found := False;
      for t := 1 to 20 do begin
        if s = UpperCase(XSettings.XSQuickFolder[t]) then
          found := True;
      end;

      if not(found) then begin
        if s <> '' then
          lbQuickFolders.Items.Add(str);
      end
      else
        ShowXDialog(XText[kWarning], XText[kQuickFoldersAlreadyExists], XDialogTypeWarning);
    end;
  end;
end;


procedure TfrmFileTypes.SpeedButton14Click(Sender: TObject);
 var
  i : integer;

 begin
  if lbQuickFolders.ItemIndex > 0 then begin
    i := lbQuickFolders.ItemIndex;

    lbQuickFolders.Items.Move(i, i-1);

    lbQuickFolders.ItemIndex := i - 1;
  end;
end;


procedure TfrmFileTypes.SpeedButton13Click(Sender: TObject);
 var
  i : integer;

 begin
  if lbQuickFolders.ItemIndex < lbQuickFolders.Count - 1 then begin
    i := lbQuickFolders.ItemIndex;

    lbQuickFolders.Items.Move(i, i + 1);

    lbQuickFolders.ItemIndex := i + 1;
  end;
end;


procedure TfrmFileTypes.cbFHEnableStateChanged(Sender: TObject;
  State: TAdvSmoothSliderState; Value: Double);
begin
  cbFHLogEnable.Enabled      := SliderStateToBoolean(State);
  cbAllowSQLInSearch.Enabled := SliderStateToBoolean(State);
end;


procedure TfrmFileTypes.sbPostScanClick(Sender: TObject);
 begin
  TSpeedButton(Sender).Down := True;

  case TSpeedButton(Sender).Tag of
    CPagePostScan      : pPostScan.BringToFront;
    CPageOptimisations : pOptimisations.BringToFront;
    CPagePaths         : pPaths.BringToFront;
    CPageGeneral       : pGeneral.BringToFront;
    CPageNavigate      : pNavigate.BringToFront;
    CPageUNUSED        : {};
    CPageFavourites    : pFavourites.BringToFront;
    CPageTemp          : pTemp.BringToFront;
  end;
end;


procedure TfrmFileTypes.Shape6MouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 begin
  cdMain.Color := bargraphs[TShape(Sender).Tag].Brush.Color;

  if cdMain.Execute then begin
    bargraphs[TShape(Sender).Tag].Brush.Color := cdMain.Color;

    sgNavigationSide.Refresh;
  end;
end;


procedure TfrmFileTypes.bClearScanHistoryClick(Sender: TObject);
 var
  Reg: TRegistry;

 begin
  if MessageDlg(XText[kClearScanHistoryPrompt], mtWarning, [mbYes, mbNo], 0) = mrYes then begin
    ScanHistory.Clear;

    Reg := TRegistry.Create(KEY_WRITE);

    try
      Reg.RootKey := HKEY_CURRENT_USER;
      Reg.DeleteKey('\software\' + XinorbisRegistryKey + '\SinglePaths');
    finally
     Reg.Free;
    end;
  end;
end;


procedure TfrmFileTypes.lbTempClick(Sender: TObject);
 begin
  if lbTemp.SelCount = 0 then
    eDeleteTemp.Enabled := False
  else
    eDeleteTemp.Enabled := True;
end;


procedure TfrmFileTypes.FormShow(Sender: TObject);
 begin
  case opentabatstart of
    0         : sbPostScanClick(sbGeneral);
    2         : sbPostScanClick(sbOptimisations);
    CPageTemp : sbPostScanClick(sbTempFiles);
  end;

  opentabatstart := -1;
end;


procedure TfrmFileTypes.miFSH1Click(Sender: TObject);
 begin
  lbQuickFolders.Items.Add(TMenuItem(Sender).Caption);
end;


procedure TfrmFileTypes.BuildNavigationTable;
var
  t : integer;

begin
  sgNavigationSide.HideColumn(8);

  for t := 1 to 10 do begin
    sgNavigationSide.Cells[0, t] := Things[t];

    sgNavigationSide.Cells[8, t] := IntToStr(Round((t * 10) / 2));
  end;

  sgNavigationSide.ColWidths[1] := 10;
  sgNavigationSide.ColWidths[3] := 10;
  sgNavigationSide.ColWidths[5] := 10;
  sgNavigationSide.ColWidths[7] := 10;

  sgNavigationSide.ColWidths[2] := 50;
  sgNavigationSide.ColWidths[4] := 50;
  sgNavigationSide.ColWidths[6] := 50;

  sgNavigationSide.ColWidths[0] := sgNavigationSide.Width - (150 + 40) - 5;
end;


*/