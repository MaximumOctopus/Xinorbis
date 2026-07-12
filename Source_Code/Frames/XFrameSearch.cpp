//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConstantsReports.h"

#include "XFrameSearch.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameSearch *FrameSearch;
//---------------------------------------------------------------------------
__fastcall TFrameSearch::TFrameSearch(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------


void TFrameSearch::SetTab(int tab)
{
	pcSearch->ActivePageIndex = tab;
}




/*


uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.UITypes, System.Variants,
  System.Classes, Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, AdvUtil, Vcl.Menus,
  HTMLabel, AdvOfficeButtons, X.Gauge, Vcl.Grids, Math, Generics.Defaults,
  AdvObj, BaseGrid, AdvGrid, Vcl.Buttons, AdvSmoothCapacityBar, W7NaviButtons,
  W7Classes, Vcl.StdCtrls, Vcl.ExtCtrls, clipbrd,

  TMSLogging,

  X.Frame.Reports,

  X.GuiLogic, X.LanguageHandler, X.Windows, X.CQuickMenuHandler, X.SystemGlobal,
  X.Formatting, X.CFileObject, X.FileExtensionsObject, X.GlobalObjects, X.CUserData,

  X.Dialogs.Dialog,

  X.CCSVReports, X.CHTMLReports, X.CSummaryReports, X.CTextReports, X.CXMLReports,

  X.CReportOptions, X.ReportUtility, X.Settings, X.ThemeHelper,

  X.Thread.Search, AeroButtons, AdvSmoothTabPager;


type
  TFrameSearch = class(TFrame)
    pMainSearch: TPanel;
    pSearchChart: TPanel;
    pSearchResults: TPanel;
	puSearch: TPopupMenu;
    miSearchOpen: TMenuItem;
    miSearchOpenCustom: TMenuItem;
    N4: TMenuItem;
    miExploreDirectory: TMenuItem;
    miSFileProperties: TMenuItem;
    miGenerateMD5: TMenuItem;
    miHexEdit: TMenuItem;
    N21: TMenuItem;
	miCopyMenu: TMenuItem;
    miCopySelected: TMenuItem;
    miCopyAll: TMenuItem;
    miMoveMenu: TMenuItem;
	miMoveSelected: TMenuItem;
    miMoveAll: TMenuItem;
    miDeleteMenu: TMenuItem;
    miDeleteSelected: TMenuItem;
    miDeleteAll: TMenuItem;
    N23: TMenuItem;
    miZIP: TMenuItem;
    N22: TMenuItem;
    miSearchExportToCB: TMenuItem;
    N36: TMenuItem;
	miSSave: TMenuItem;
	puQuickSearch: TPopupMenu;
	pSearchOptions: TAdvSmoothTabPager;
	tsSearch: TAdvSmoothTabPage;
    sbExploreDir: TAeroButton;
    sbExcludeFolders: TAeroButton;
    sbExcludeFiles: TAeroButton;
    sbCombine: TAeroButton;
    sbQuickFolder: TAeroButton;
    pSearch: TPanel;
	sbGoSearch: TSpeedButton;
    sbQuickSearch: TSpeedButton;
    lSearchDetails: THTMLabel;
    sbSearchSyntax: TSpeedButton;
	sbSearchHelp: TSpeedButton;
	pSearchNavigation: TPanel;
    lShowing: TLabel;
    lPageNumber: TLabel;
	W7NavigationFrame4: TW7NavigationFrame;
    lSPagePrevious: TW7NavigationButton;
    lSPageNext: TW7NavigationButton;
    capacitySearch: TAdvSmoothCapacityBar;
    sbSearchThing: TSpeedButton;
    pSearchGraph: TPanel;
    guageSearchQuantity: TXGauge;
    lPSearchQuantity: TLabel;
    guageSearchSize: TXGauge;
    lPSearchSize: TLabel;
	sgSearchResults: TAdvStringGrid;
    Panel1: TPanel;
    sbGoDN: TSpeedButton;
    sbSaveDN: TSpeedButton;
    sbCopyDN: TSpeedButton;
    bHelpDN: TSpeedButton;
    lDNCount: THTMLabel;
    sbCopyCSVDN: TSpeedButton;
    sgDuplicatesName: TAdvStringGrid;
    Panel2: TPanel;
    sbGoDS: TSpeedButton;
    sbSaveDS: TSpeedButton;
    sbCopyDS: TSpeedButton;
    SpeedButton5: TSpeedButton;
    lDCountDS: THTMLabel;
    sbCopyCSVDS: TSpeedButton;
    sgDuplicatesSize: TAdvStringGrid;
	tsProperties: TAdvSmoothTabPage;
	procedure sbQuickSearchClick(Sender: TObject);
    procedure sbGoSearchClick(Sender: TObject);
    procedure eSearchChange(Sender: TObject);
    procedure eSearchKeyPress(Sender: TObject; var Key: Char);
    procedure sbSearchHelpClick(Sender: TObject);
    procedure sbSearchSyntaxClick(Sender: TObject);
    procedure sbSaveSearchClick(Sender: TObject);
    procedure cbSearchShowPathClick(Sender: TObject);
	procedure cbSearchColourCodeClick(Sender: TObject);
    procedure sbSearchThingClick(Sender: TObject);
    procedure lSPagePreviousClick(Sender: TObject);
    procedure lSPageNextClick(Sender: TObject);
    procedure sgSearchResultsCanSort(Sender: TObject; ACol: Integer;
      var DoSort: Boolean);
    procedure sbSCAccessedClick(Sender: TObject);
    procedure miQuickSearchClick(Sender: TObject);
    procedure miSearchOpenClick(Sender: TObject);
    procedure miSearchOpenCustomClick(Sender: TObject);
    procedure miExploreDirectoryClick(Sender: TObject);
    procedure miSFilePropertiesClick(Sender: TObject);
    procedure miGenerateMD5Click(Sender: TObject);
    procedure miHexEditClick(Sender: TObject);
    procedure miCopySelectedClick(Sender: TObject);
    procedure miCopyAllClick(Sender: TObject);
    procedure miMoveSelectedClick(Sender: TObject);
    procedure miMoveAllClick(Sender: TObject);
    procedure miDeleteSelectedClick(Sender: TObject);
    procedure miDeleteAllClick(Sender: TObject);
    procedure miZIPClick(Sender: TObject);
    procedure miSearchExportToCBClick(Sender: TObject);
    procedure sgSearchResultsGetCellColor(Sender: TObject; ARow, ACol: Integer;
      AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
    procedure puSearchPopup(Sender: TObject);
    procedure sbGoDNClick(Sender: TObject);
    procedure sbSaveDNClick(Sender: TObject);
    procedure sbCopyCSVDNClick(Sender: TObject);
    procedure sbCopyDNClick(Sender: TObject);
    procedure bHelpDNClick(Sender: TObject);
    procedure sgDuplicatesNameCanSort(Sender: TObject; ACol: Integer;
      var DoSort: Boolean);
    procedure sgDuplicatesNameGetCellColor(Sender: TObject; ARow, ACol: Integer;
      AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
    procedure sbGoDSClick(Sender: TObject);
    procedure sbSaveDSClick(Sender: TObject);
    procedure sbCopyCSVDSClick(Sender: TObject);
    procedure sbCopyDSClick(Sender: TObject);
    procedure SpeedButton5Click(Sender: TObject);
    procedure FrameResize(Sender: TObject);
    procedure miSSaveClick(Sender: TObject);
    procedure sgSearchResultsEndColumnSize(Sender: TObject; ACol: Integer);
    procedure pSearchOptionsChange(Sender: TObject);
    procedure sgDuplicatesNameGetAlignment(Sender: TObject; ARow, ACol: Integer;
      var HAlign: TAlignment; var VAlign: TVAlignment);
  private
    FSource                       : integer;
    FPageNumber                   : integer; // zero-indexed
    FFirstPage                    : integer; // indexed from 1
    FLastPage                     : integer; // indexed from 1
    FReportsFrame                 : TFrameReports;
    FSearchDataChanged            : boolean;

    TotalSearchSize               : int64;   // values from search thread
    TotalSearchFilesCount         : integer; //
    TotalSearchFoldersCount       : integer; //

    FGetLeftOffset : TGetLeftOffset;
    FGetTopOffset  : TGetTopOffset;

    FSearchThread : TSearchThread;

    FMenuChange        : TMenuChange;
    FSetStatusBarText  : TSetStatusBarText;
    FOpenSearchWizard  : TOpenSearchWizard;
    FOnProcessWindowStatus : TProcessWindowStatus;

    function  GetActivePage: integer;

    procedure CreateReportsFrame(aDataIndex : integer);

    procedure LoadSettings;

    procedure SetTheme;

    procedure SearchThreadOnTerminate(Sender: TObject);

    procedure BuildSearchChart;
    procedure UpdateSearchCapacity;

    procedure OnNewResults(aSize : int64; aFilesCount, aFolderCount : integer);

    procedure RenderResults(aBegin, aEnd : integer);
    procedure UpdateGUI;
    procedure UpdateSearchGUI;
    procedure ResizeColumns;
    procedure ClearGUI(aNoResults : boolean);

    function  GetSelectedFileName(aTag : integer): string;
    function  GetSearchText: string;

    function  OnGetLeftOffset: integer;
    function  OnGetTopOffset: integer;

    procedure SearchCSVReport;

    procedure BuildPropertiesTab(aDataIndex : integer);
    procedure OnRequestNewSearch(aDataIndex : integer; const aNewSearch : string);
  public
    procedure Init;
    procedure DeInit;
    procedure SetTab(aTab : integer);
    procedure SaveSettings;

    procedure DoSearch(aSearchText : string);
    procedure RebuildCharts;

    property ReportFrame                 : TFrameReports        read FReportsFrame;

    property ActivePage                  : integer              read GetActivePage;

    property Source                      : integer              read FSource                 write FSource;
    property SearchText                  : string               read GetSearchText;

    property OnMenuChange                : TMenuChange          read FMenuChange             write FMenuChange;
    property OnOpenSearchWizard          : TOpenSearchWizard    read FOpenSearchWizard       write FOpenSearchWizard;
    property OnProcessWindowStatusChange : TProcessWindowStatus read FOnProcessWindowStatus  write FOnProcessWindowStatus;
    property OnSetStatusBarText          : TSetStatusBarText    read FSetStatusBarText       write FSetStatusBarText;

    property GetLeftOffset               : TGetLeftOffset       read FGetLeftOffset          write FGetLeftOffset;
    property GetTopOffset                : TGetTopOffset        read FGetTopOffset           write FGetTopOffset;
  end;


var
  FrameSearch : TFrameSearch;


implementation


{$R *.dfm}


uses
  GDIPFill, Registry,

  X.Help, X.Dialogs.Save, X.Form.GetCopyMove, X.MD5, X.Form.ShowMD5,
  X.GridUtility, X.Chartutility, X.Utility, X.ZipFiles, X.Conversions,

  X.Constants, X.Global;


const
  SearchSortColumns     : array[0..6] of integer = (schVFilename, schISize, 2, 3, 4, 5, 6);


procedure TFrameSearch.Init;
begin
  FSearchDataChanged := False;

  GScanDetails[dataSearch].ScanPath := XText[kSearch];

  tsSearch.Caption   := XText[kSearch];

  tsProperties.Caption     := XText[kDetail];
  tsDuplicatesName.Caption := XText[kDuplicatesName];
  tsDuplicatesSize.Caption := XText[kDuplicatesSize];

  sgDuplicatesName.HideColumn(2);
  sgDuplicatesName.Cells[0, 0]   := XText[kFilePath];
  sgDuplicatesName.Cells[1, 0]   := XText[kSize];

  sgDuplicatesSize.HideColumn(2);
  sgDuplicatesSize.Cells[0, 0]   := XText[kFilePath];
  sgDuplicatesSize.Cells[1, 0]   := XText[kSize];

  lSearchDetails.Caption := XText[kSearchResults];

  miExploreDirectory.Caption     := XText[kExploreFolder];

  lPSearchSize.Caption := XText[kBySize];

  lPSearchQuantity.Caption   := XText[kByQuantity];

  cbSearchShowPath.Caption   := XText[kShowFullPath];
  cbSearchColourCode.Caption := XText[kColourCode];

  sgSearchResults.DefaultRowHeight  := XSettings.General.RowHeight;

  sgSearchResults.Cells[schVFilename, 0]   := XText[kFileName];
  sgSearchResults.Cells[schVSize, 0]       := XText[kSize];
  sgSearchResults.Cells[schVCDate, 0]      := XText[kDate];

  sgSearchResults.Cells[schVADate, 0]      := XText[kAccessed];
  sgSearchResults.Cells[schVMDate, 0]      := XText[kModified];
  sgSearchResults.Cells[schVOwner, 0]      := XText[kFileOwner];
  sgSearchResults.Cells[schVAttributes, 0] := XText[kAttr];

  sgSearchResults.HideColumn(schVADate);
  sgSearchResults.HideColumn(schVMDate);
  sgSearchResults.HideColumn(schVAttributes);
  sgSearchResults.HideColumn(schVOwner);
  sgSearchResults.HideColumn(schIFilename);
  sgSearchResults.HideColumn(schISize);
  sgSearchResults.HideColumn(schICDate);
  sgSearchResults.HideColumn(schIADate);
  sgSearchResults.HideColumn(schIMDate);
  sgSearchResults.HideColumn(schIColour);

  // ===========================================================================================

  miSearchOpen.Caption       := XText[kViewOpenFile];
  miSearchOpenCustom.Caption := XText[kOpenWithCustomViewer];
  miExploreDirectory.Caption := XText[kExploreFolder];
  miSFileProperties.Caption  := XText[kFileProperties];
  miGenerateMD5.Caption      := XText[kGenerateMD5];
  miHexEdit.Caption          := XText[kHexEdit];

  miCopyMenu.Caption         := XText[kCopy];
  miCopySelected.Caption     := XText[kSelected] + rsEllipsis;
  miCopyAll.Caption          := XText[kAll] + rsEllipsis;
  miMoveMenu.Caption         := XText[kMove];
  miMoveSelected.Caption     := XText[kSelected] + rsEllipsis;
  miMoveAll.Caption          := XText[kAll] + rsEllipsis;
  miDeleteMenu.Caption       := XText[kDelete];
  miDeleteSelected.Caption   := XText[kSelected] + rsEllipsis;
  miDeleteAll.Caption        := XText[kAll] + rsEllipsis;

  miZIP.Caption              := XText[kAddZipFile] + rsEllipsis;
  miSearchExportToCB.Caption := XText[kCopyResultsToClipboard];

  miSSave.Caption            := XText[kSaveAs] + rsEllipsis;

  // ===========================================================================================

  CreateReportsFrame(dataSearch);

  // ===========================================================================================

  SetTheme;

  LoadSettings;
end;


procedure TFrameSearch.SetTheme;
begin
  TThemeHelper.SetSmoothTabPager(pSearchOptions);

  TThemeHelper.SetSmoothTabPage(tsSearch);
  TThemeHelper.SetSmoothTabPage(tsProperties);
  TThemeHelper.SetSmoothTabPage(tsDuplicatesName);
  TThemeHelper.SetSmoothTabPage(tsDuplicatesSize);
end;


procedure TFrameSearch.DeInit;
begin
  SaveSettings;
end;


function TFrameSearch.GetActivePage: integer;
begin
  Result := pSearchOptions.ActivePageIndex;
end;


procedure TFrameSearch.CreateReportsFrame(aDataIndex : integer);
begin
  FReportsFrame := TFrameReports.Create(Self);
  FReportsFrame.Name                        := 'FrameReports' + IntToStr(aDataIndex);
  FReportsFrame.Parent                      := tsProperties;
  FReportsFrame.Source                      := aDataIndex;
  FReportsFrame.Init;
  FReportsFrame.Visible                     := True;
  FReportsFrame.GetLeftOffset               := OnGetLeftOffset;
  FReportsFrame.GetTopOffset                := OnGetTopOffset;

//  FReportsFrame.OnNewScan                   := RequestNewScan;
  FReportsFrame.OnNewSearch                 := OnRequestNewSearch;
 {FReportsFrame.OnNewSummary                := RequestNewSummary;
  FReportsFrame.OnProcessWindowStatusChange := OnProcessWindowStatusChange;
  FReportsFrame.OnSetStatusBarText          := OnStatusBarChange;
  FReportsFrame.OnSettingsTab               := OnOpenSettingsTab;
  FReportsFrame.OnSetTutorialBarText        := OnTutorialBarChange; }

  GReportText.SetGrids(aDataIndex, FReportsFrame.sgNullFiles,
                                   FReportsFrame.sgNullFolders,
                                   FReportsFrame.sgTop50Big,
                                   FReportsFrame.sgTop50Small,
                                   FReportsFrame.sgTop101BigDate,
                                   FReportsFrame.sgTop101SmallDate);

  GReportXML.SetGrids(aDataIndex,  FReportsFrame.tvFileDates,
                                   FReportsFrame.sgNullFiles,  FReportsFrame.sgNullFolders,    FReportsFrame.sgTop50Big,
                                   FReportsFrame.sgTop50Small, FReportsFrame.sgTop101BigDate,  FReportsFrame.sgTop101SmallDate,
                                   FReportsFrame.cbFileDates,  FReportsFrame.cbFileDatesUsers, FReportsFrame.cbTop101Dates);


  GReportHTML.SetGrids(aDataIndex, FReportsFrame.tvFileDates,
                                   FReportsFrame.sgNullFiles,  FReportsFrame.sgNullFolders,    FReportsFrame.sgTop50Big,
                                   FReportsFrame.sgTop50Small, FReportsFrame.sgTop101BigDate,  FReportsFrame.sgTop101SmallDate,
                                   FReportsFrame.cbFileDates,  FReportsFrame.cbTop101Dates);


  GReportSummary.SetGrids(aDataIndex, FReportsFrame.sgNullFiles,
                                      FReportsFrame.sgNullFolders,
                                      FReportsFrame.sgDirList,
                                      FReportsFrame.sgTop50Big,
                                      FReportsFrame.sgUsers);

  //UpdateGUICustomNames(aDataIndex);
end;


function  TFrameSearch.OnGetLeftOffset: integer;
begin
  Result := FGetLeftOffSet;
end;


function  TFrameSearch.OnGetTopOffset: integer;
begin
  Result := FGetTopOffset + 16;
end;


procedure TFrameSearch.OnRequestNewSearch(aDataIndex : integer; const aNewSearch : string);
begin
  DoSearch(aNewSearch);
end;


procedure TFrameSearch.SetTab(aTab : integer);
begin
  pSearchOptions.ActivePageIndex := aTab;
end;


function TFrameSearch.GetSearchText: string;
begin
  Result := eSearch.Text;
end;


function TFrameSearch.GetSelectedFileName(aTag : integer): string;
begin
  case aTag of
    1 : Result := sgSearchResults.Cells[schIFileName, sgSearchResults.Selection.Top];
    2 : Result := sgDuplicatesName.Cells[0, sgDuplicatesName.Selection.Top];
    3 : Result := sgDuplicatesSize.Cells[0, sgDuplicatesSize.Selection.Top];
  else
    Result := '';
  end;
end;


procedure TFrameSearch.LoadSettings;
var
  t : integer;
  s : string;
  lReg : TRegistry;

begin
  if XSettings.OpenSettings(True) then begin

    pSearchChart.Width       := XSettings.ReadIntegerFromSettings('Prefs', 'Sizes_pSearchResults', 200, 200);

    cbSearchShowPath.Checked := XSettings.ReadBoolFromSettings('Prefs', 'Search_ShowPath', True);

    if (XSettings.customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
      for t := 1 to MaximumFolderHistory do begin
        s := XSettings.ReadStringFromSettings('Prefs', 'SearchTerm' + IntToStr(t), '');

       if s <> '' then
         eSearch.Items.Add(s);
       end;
    end
    else begin
      lReg := TRegistry.Create(KEY_READ);

      try
        lReg.RootKey := HKEY_CURRENT_USER;
        lReg.OpenKey('\software\' + XinorbisRegistryKey + '\SearchTerm', True);

        t := 0;
        While lReg.ValueExists('Term' + IntToStr(t)) do begin
          eSearch.Items.Add(lReg.ReadString('Term' + IntToStr(t)));
          inc(t);
        end;
      finally
        lReg.Free;
      end;
    end;

    XSettings.CloseSettings;
  end
  else
    TMSLogger.Error('Error loading settings in FrameSearch');

  RebuildCharts;
end;


procedure TFrameSearch.SaveSettings;
var
  t : integer;
  lReg : TRegistry;

begin
  if XSettings.OpenSettings(False) then begin

    XSettings.WriteIntegerToSettings('Prefs', 'Sizes_pSearchResults', pSearchChart.Width);

    XSettings.WriteBoolToSettings('Prefs', 'Search_ShowPath',         cbSearchShowPath.Checked);

    if (XSettings.customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
      if eSearch.Items.Count <> 0 then begin
        for t := 0 to eSearch.Items.Count - 1 do begin
          XSettings.WriteStringToSettings('Prefs', 'SearchTerm' + IntToStr(t + 1), eSearch.Items[t]);
        end;
      end;
    end
    else begin
      if eSearch.Items.Count <> 0 then begin
        lReg := TRegistry.Create(KEY_WRITE);

        try
          lReg.RootKey := HKEY_CURRENT_USER;
          lReg.OpenKey('\software\' + XinorbisRegistryKey + '\SearchTerm', True);

          for t := 0 to eSearch.Items.Count - 1 do
            if t < MaximumFolderHistory then lReg.WriteString('Term' + IntToStr(t), eSearch.Items[t]);
        finally
          lReg.Free;
        end;
      end;
    end;

    XSettings.CloseSettings;
  end
  else
    TMSLogger.Error('Error saving FrameSearch settings');
end;


procedure TFrameSearch.DoSearch(aSearchText : string);
begin
  if aSearchText <> '' then begin
    if eSearch.Items.IndexOf(aSearchText) = -1 then
      eSearch.Items.Add(aSearchText);

    eSearch.Text := aSearchText;
  end;

  pSearchOptions.ActivePageIndex := 0;

  sbGoSearchClick(sbGoSearch);
end;


procedure TFrameSearch.eSearchChange(Sender: TObject);
begin
//  ClearGUI(False);
end;


procedure TFrameSearch.eSearchKeyPress(Sender: TObject; var Key: Char);
begin
  if (key = #13) and (sbGoSearch.Enabled) then
    sbGoSearchClick(sbGoSearch);
end;


procedure TFrameSearch.FrameResize(Sender: TObject);
var
  i, t : integer;

begin
  i := 0;

  for t := 1 to 12 do begin
    if not(sgSearchResults.IsHiddenColumn(t)) then
      inc(i, sgSearchResults.ColWidths[t]);
  end;

  sgSearchResults.ColWidths[0]  := sgSearchResults.Width - (i + _WidthOfScrollbar);

  eSearch.Width                 := sgSearchResults.Width - 50;

  // =======================================================================

  sgDuplicatesName.ColWidths[0] := sgDuplicatesName.Width - (64 + _WidthOfScrollbar);
  sgDuplicatesSize.ColWidths[0] := sgDuplicatesSize.Width - (64 + _WidthOfScrollbar);
end;


procedure TFrameSearch.lSPageNextClick(Sender: TObject);
begin
  if FPageNumber < FLastPage then begin
    inc(FPageNumber);

    RenderResults(FPageNumber * XSettings.General.MaxSearchResults,
                  (FPageNumber * XSettings.General.MaxSearchResults) + XSettings.General.MaxSearchResults - 1);
    UpdateGUI;
  end;
end;


procedure TFrameSearch.lSPagePreviousClick(Sender: TObject);
begin
  if FPageNumber > FFirstPage then begin
    dec(FPageNumber);

    RenderResults(FPageNumber * XSettings.General.MaxSearchResults,
                  (FPageNumber * XSettings.General.MaxSearchResults) + XSettings.General.MaxSearchResults - 1);
    UpdateGUI;
  end;
end;


procedure TFrameSearch.pSearchOptionsChange(Sender: TObject);
begin
  if pSearchOptions.ActivePageIndex = 1 then begin
    if FSearchDataChanged then begin
      BuildPropertiesTab(dataSearch);

      FSearchDataChanged := False;
    end;
  end;
end;


procedure TFrameSearch.puSearchPopup(Sender: TObject);
var
  lFileName : string;
  lStatus : boolean;

begin
  lStatus   := True;

  if not(XSettings.ProcessWindowsVisible) then begin

    lFileName := GetSelectedFileName(TStringGrid(TPopupMenu(Sender).PopupComponent).Tag);

    if lFileName = '' then
      lStatus := False;

    miSearchOpen.Enabled       := lStatus;
    miSearchOpenCustom.Enabled := lStatus;
    miExploreDirectory.Enabled := lStatus;
    miSFileProperties.Enabled  := lStatus;
    miGenerateMD5.Enabled      := lStatus;
    miHexEdit.Enabled          := lStatus;
    miCopyMenu.Enabled         := lStatus;
    miMoveMenu.Enabled         := lStatus;
    miDeleteMenu.Enabled       := lStatus;
    miZIP.Enabled              := lStatus;
    miSearchExportToCB.Enabled := lStatus;
    miSSave.Enabled            := lStatus;

    case TStringGrid(TPopupMenu(Sender).PopupComponent).Tag of
      2, 3 : begin
               miCopyAll.Enabled   := False;
               miMoveAll.Enabled   := False;
               miDeleteAll.Enabled := False;

               miZIP.Enabled       := False;
             end;
    end;
  end;
end;


procedure TFrameSearch.sbCopyCSVDNClick(Sender: TObject);
var
  tf : TextFile;
  t : integer;
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[kTextFiles] + ' (*.csv)|*.csv',
                                    '.csv',
                                    TUtility.GetDefaultFileName('.csv', 'duplicates_' + XText[kReport]),
                                    GSystemGlobal.AppDataPath + 'Saves\Duplicates');

  if lFileName <> '' then begin
    AssignFile(tf, lFileName);

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[kErrorSavingReport] + ' (CSV)',
                  XText[kErrorSaving] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      for t := 1 to sgDuplicatesName.RowCount - 1 do begin
        if sgDuplicatesName.Cells[0, t] <> '' then
          Writeln(tf, '"' + sgDuplicatesName.Cells[0, t] + '",' + sgDuplicatesName.Cells[1, t] + ',' + sgDuplicatesName.Cells[2, t]);
      end;

      CloseFile(tf);
    end;
    {$I+}
  end;
end;


procedure TFrameSearch.sbCopyDNClick(Sender: TObject);
begin
  TGridUtility.CopyGridToClipboard(0, sgDuplicatesName);
end;


procedure TFrameSearch.sbGoDNClick(Sender: TObject);
var
  t, dcount : integer;
  tfo1, tfo2 : TFileObject;
  fn : string;
  status : boolean;

begin
  Screen.Cursor := crHourGlass;

  // ===========================================================================

  sgDuplicatesName.ClearRows(1, sgDuplicatesName.RowCount - 1);
  sgDuplicatesName.RowCount := 2;
  sgDuplicatesName.BeginUpdate;

  fn     := '';
  dcount := 0;

  GScanDetails[FSource].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNames));

  // ===========================================================================

  for t := 1 to GScanDetails[FSource].Files.Count - 1 do begin
    tfo1 := GScanDetails[FSource].Files.Items[t - 1];
    tfo2 := GScanDetails[FSource].Files.Items[t];

    if tfo1.FileName = tfo2.FileName then begin
      if fn = '' then begin
        sgDuplicatesName.Cells[0, sgDuplicatesName.RowCount - 1] := GScanDetails[FSource].Folders[tfo1.FilePathIndex] + tfo1.FileName;

        if ((tfo1.Attributes and faDirectory) = 0) then begin
          sgDuplicatesName.Cells[1, sgDuplicatesName.RowCount - 1] := TConvert.ConvertToUsefulUnit(tfo1.FileSize);
          sgDuplicatesName.Cells[2, sgDuplicatesName.RowCount - 1] := IntToStr(tfo1.FileSize)
        end
        else begin
          sgDuplicatesName.Cells[1, sgDuplicatesName.RowCount - 1] := XText[kFolder];
          sgDuplicatesName.Cells[2, sgDuplicatesName.RowCount - 1] := '0';
        end;

        sgDuplicatesName.RowCount := sgDuplicatesName.RowCount + 1;

        fn := tfo1.FileName;

        inc(dcount);
      end;

      sgDuplicatesName.Cells[0, sgDuplicatesName.RowCount - 1] := GScanDetails[FSource].Folders[tfo2.FilePathIndex] + tfo2.FileName;
      sgDuplicatesName.Cells[1, sgDuplicatesName.RowCount - 1] := TConvert.ConvertToUsefulUnit(tfo2.FileSize);

      if ((tfo2.Attributes and faDirectory) = 0) then begin
        sgDuplicatesName.Cells[1, sgDuplicatesName.RowCount - 1] := TConvert.ConvertToUsefulUnit(tfo2.FileSize);
        sgDuplicatesName.Cells[2, sgDuplicatesName.RowCount - 1] := IntToStr(tfo1.FileSize)
      end
      else begin
        sgDuplicatesName.Cells[1, sgDuplicatesName.RowCount - 1] := XText[kFolder];
        sgDuplicatesName.Cells[2, sgDuplicatesName.RowCount - 1] := '0';
      end;

      sgDuplicatesName.RowCount := sgDuplicatesName.RowCount + 1;
    end
    else begin
      if fn <> '' then
        sgDuplicatesName.RowCount := sgDuplicatesName.RowCount + 1;

      fn := '';
    end;
  end;

  // ===========================================================================

  lDNCount.HTMLText[0]:= XText[kFound] + ' <b>' + IntToStr(dcount) + '</b> ' + XText[kDuplicateFilenames] + '.';

  if dcount = 0 then
    status := False
  else
    status := True;

  sbSaveDN.Enabled    := status;
  sbCopyDN.Enabled    := status;
  sbCopyCSVDN.Enabled := status;

  sgDuplicatesName.EndUpdate;

  Screen.Cursor := crDefault;
end;

procedure TFrameSearch.OnNewResults(aSize : int64; aFilesCount, aFolderCount : integer);
begin
  TotalSearchSize         := aSize;
  TotalSearchFilesCount   := aFilesCount;
  TotalSearchFoldersCount := aFolderCount;
end;


procedure TFrameSearch.SearchThreadOnTerminate(Sender: TObject);
var
  t : integer;
  lUserData : TUserData;

begin
  for t:= 0 to GScanDetails[FSource].Users.Count - 1 do begin
    lUserData := TUserData.Create;

    lUserData.Name := GScanDetails[FSource].Users[t].Name;

    GScanDetails[dataSearch].Users.Add(lUserData);
  end;

  for t:= 0 to GScanDetails[FSource].Folders.Count - 1 do
    GScanDetails[dataSearch].Folders.Add(GScanDetails[FSource].Folders[t]);

  GScanDetails[dataSearch].ScanPath := GScanDetails[FSource].ScanPath;

  // ===========================================================================

  if Assigned(FMenuChange) then
    FMenuChange(XText[kSearch], 0, 0);

  UpdateSearchCapacity;

  if Assigned(FSetStatusBarText) then
    FSetStatusBarText(XText[kSearchFinished]);

  FFirstPage := 0;
  FLastPage  := Ceil(GScanDetails[dataSearch].Files.Count / XSettings.General.MaxSearchResults) - 1;

  RenderResults(0, XSettings.General.MaxSearchResults - 1);
  UpdateGUI;

  if pSearchChart.Visible then
    BuildSearchChart;

  UpdateSearchCapacity;

  sbGoSearch.Enabled := True;
end;


procedure TFrameSearch.sbQuickSearchClick(Sender: TObject);
begin
  puQuickSearch.Tag := TSpeedbutton(Sender).Tag;

  puQuickSearch.Popup(FGetLeftOffset + 32,
                      FGetTopOffset + 100);
end;


procedure TFrameSearch.sbSaveDNClick(Sender: TObject);
 var
  tf : TextFile;
  t : integer;
  lFileName : string;

 begin
  lFileName := TXSaveDialog.Execute(XText[kTextFiles] + ' (*.txt)|*.txt',
                                    '.txt',
                                    TUtility.GetDefaultFileName('.txt', 'duplicates_' + XText[kReport]),
                                    GSystemGlobal.AppDataPath + 'Saves\Duplicates');

  if lFileName <> '' then begin
    AssignFile(tf, lFileName);

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[kErrorSaving] + ': ' + XText[kDuplicatesFileName],
                  XText[kErrorSaving] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      for t := 1 to sgDuplicatesName.RowCount - 1 do begin
        Writeln(tf, TXFormatting.AddLeading(sgDuplicatesName.Cells[1, t], 10, ' ') + ' ' + sgDuplicatesName.Cells[0, t]);
      end;

      CloseFile(tf);
    end;
    {$I+}
  end;
end;


procedure TFrameSearch.sbSaveSearchClick(Sender: TObject);
var
  tf : TextFile;
  t, a, b, c, w : integer;
  lFileName : string;
  tempCSVOptions : TCSVReportOptions;
  lReportOutput : TStringList;

begin
  lFileName := TXSaveDialog.ExecuteReports(TUtility.GetDefaultFileName('.csv', XText[kSearchResults]));

  if lFileName <> '' then begin
    case GReportUtility.GetReportType(lFileName) of
      CReportTypeCSV  : begin
                          tempCSVOptions := XSettings.Report.CSVOptions[LayoutQuick];
                          tempCSVOptions.Category := -1;
                          tempCSVOptions.CSVData  := CDataFileList;
                          tempCSVOptions.FileName := lFileName;

                          lReportOutput := TStringList.Create;

                          GReportCSV.GenerateCSVReport(dataSearch, lReportOutput, tempCSVOptions, LayoutUnknown);

                          FreeAndNil(lReportOutput);
                        end;
      CReportTypeHTML : begin
                          lReportOutput := TStringList.Create;

                          GReportHTML.GenerateHTMLFileReport(dataSearch, lReportOutput, XText[kSearchResults] + ' "' + eSearch.Text + '"', lFileName);

                          FreeAndNil(lReportOutput);
                        end;
      CReportTypeText : begin
                          AssignFile(tf, lFileName);

                          {$I-}
                          Rewrite(tf);

                          if IOResult <> 0 then begin
                            ShowXDialog(XText[kWarning],
										XText[kErrorSaving] + ' "' + lFileName + '".',
                                        XDialogTypeWarning);

                            if Assigned(FSetStatusBarText) then
                              FSetStatusBarText(XText[kError] + ' ' + lFileName);
                          end
                          else begin
                            a := Length(XText[kPath]);
                            b := Length(XText[kSearch]);
                            c := Length(XText[kFound]);

                            w := Max(Max(a, b), c);   // find the largest of the three texts

                            Writeln(tf, '// Xinorbis 8.3 - ' + XText[kSearchResults]);
                            Writeln(tf, '//');

                            if FSource = dataLatestScan then
                              Writeln(tf, '// ' + XText[kPath] + TXFormatting.StringOfChars(w - a, ' ') + ' : ' + GScanDetails[FSource].ScanPath)
                            else
                              Writeln(tf, '// ' + XText[kPath] + TXFormatting.StringOfChars(w - a, ' ') + ' : ' + GScanDetails[FSource].ScanPath + ' (DB ' + XText[kTable] + ' ' + GScanDetails[FSource].ScanTable + ')');

                            Writeln(tf, '// ' + XText[kSearch] + TXFormatting.StringOfChars(w - b, ' ') + ' : ' + eSearch.Text);
                            Writeln(tf, '// ' + XText[kFound]  + TXFormatting.StringOfChars(w - c, ' ') + ' : ' + IntToStr(GScanDetails[dataSearch].Files.Count));
                            Writeln(tf, '');

                            writeln(tf, XText[kFilePath] + ' ' +
                                        ' [' +  XText[kSize] + '] ' +
                                        XText[kFileOwner] +  ' :: ' +
                                        XText[kAttr]);

                            Writeln(tf, '');

                            for t := 0 to GScanDetails[dataSearch].Files.Count - 1 do begin
                              Writeln(tf, GScanDetails[dataSearch].Folders[GScanDetails[dataSearch].Files[t].FilePathIndex] + GScanDetails[dataSearch].Files[t].Filename +
                                          '  [' + TConvert.ConvertToUsefulUnit(GScanDetails[dataSearch].Files[t].FileSize) + '] ' +
                                          GScanDetails[dataSearch].Users[GScanDetails[dataSearch].Files[t].Owner].Name + ' :: ' +
                                          TConvert.AttributesToString(GScanDetails[dataSearch].Files[t].Attributes));
                            end;

                            CloseFile(tf);
                          end;
                          {$I+}
                        end;
    end;
  end;
end;

procedure TFrameSearch.sbSearchThingClick(Sender: TObject);
begin
  if sbSearchThing.Tag = 1 then
    sbSearchThing.Tag := 2
  else
    sbSearchThing.Tag := 1;

  UpdateSearchCapacity;
end;


procedure TFrameSearch.sgDuplicatesNameCanSort(Sender: TObject; ACol: Integer;
  var DoSort: Boolean);
begin
  if Acol = 1 then begin
    DoSort := False; // stops the component for sorting automatically

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then  // make sure we toggle the search direction -
        SortSettings.Direction := sdAscending        // as this is not done for us
      else                                         //
        SortSettings.Direction := sdDescending;      //

      Sortsettings.Column := 2; //set the hidden column as the sort source
      QSort;                  //force a quick sort of above

      //this line refreshes the component and forces the glyphs to be redrawn
      //on our Location column and NOT the column we sorted on!
      SortSettings.Column := 1;
    end;
  end;
end;


procedure TFrameSearch.sgDuplicatesNameGetAlignment(Sender: TObject; ARow,
  ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  if (ACol = 1) then
    HAlign := taRightJustify
  else
    HAlign := taLeftJustify;
end;


procedure TFrameSearch.sgDuplicatesNameGetCellColor(Sender: TObject; ARow,
  ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
begin
  if gdSelected in AState then
    ABrush.Color := CGridColourSelected
  else begin
    if Odd(ARow) then
      ABrush.Color := CGridColourOn
    else
      ABrush.Color := CGridColourOff;
  end;
end;


procedure TFrameSearch.sgSearchResultsCanSort(Sender: TObject; ACol: Integer;
  var DoSort: Boolean);
begin
  DoSort := False;

  if TAdvStringGrid(Sender).SortSettings.Direction = sdDescending then
    TAdvStringGrid(Sender).SortSettings.Direction := sdAscending
  else
    TAdvStringGrid(Sender).SortSettings.Direction := sdDescending;

  case ACol of
    schVSize       : GScanDetails[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileSizes));
    schVCDate      : GScanDetails[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
    schVADate      : GScanDetails[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
    schVMDate      : GScanDetails[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
    schVFilename   : GScanDetails[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNames));
    schVOwner      : GScanDetails[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareOwnerSD));
    schVAttributes : GScanDetails[dataSearch].Files.Sort(TComparer<TFileObject>.Construct(CompareFileAttributes));
  end;

  RenderResults(FPageNumber * XSettings.General.MaxSearchResults,
               (FPageNumber * XSettings.General.MaxSearchResults) + XSettings.General.MaxSearchResults - 1);
  UpdateGUI;
end;


procedure TFrameSearch.sgSearchResultsEndColumnSize(Sender: TObject; ACol: Integer);
begin
  ResizeColumns;
end;


procedure TFrameSearch.sgSearchResultsGetCellColor(Sender: TObject; ARow,
  ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
begin
  if cbSearchColourCode.Checked then begin
    if ARow > 0 then
      ABrush.Color := GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender).Cells[schIColour, ARow])];
  end
  else begin
    if gdSelected in AState then
      ABrush.Color := CGridColourSelected
    else begin
      if Odd(ARow) then
        ABrush.Color := CGridColourOn
      else
        ABrush.Color := CGridColourOff;
    end;
  end;
end;


procedure TFrameSearch.sbGoDSClick(Sender: TObject);
var
  t, dcount : integer;
  tfo1, tfo2 : TFileObject;
  fs : int64;
  status : boolean;

begin
  Screen.Cursor := crHourGlass;

  // ===========================================================================

  sgDuplicatesSize.ClearRows(1, sgDuplicatesSize.RowCount - 1);
  sgDuplicatesSize.RowCount := 2;
  sgDuplicatesSize.BeginUpdate;

  fs     := -1;
  dcount := 0;

  GScanDetails[FSource].Files.Sort(TComparer<TFileObject>.Construct(CompareFileSizes));

  // ===========================================================================

  for t := 1 to GScanDetails[FSource].Files.Count - 1 do begin
    tfo1 := GScanDetails[FSource].Files.Items[t - 1];
    tfo2 := GScanDetails[FSource].Files.Items[t];

    if (tfo1.FileSize = tfo2.FileSize) and
       ((tfo1.Attributes and faDirectory) = 0) and
       ((tfo2.Attributes and faDirectory) = 0) then begin
      if fs = -1 then begin
        sgDuplicatesSize.Cells[0, sgDuplicatesSize.RowCount - 1] := GScanDetails[FSource].Folders[tfo1.FilePathIndex] + tfo1.FileName;
        sgDuplicatesSize.Cells[1, sgDuplicatesSize.RowCount - 1] := TConvert.ConvertToUsefulUnit(tfo1.FileSize);
        sgDuplicatesSize.Cells[2, sgDuplicatesSize.RowCount - 1] := IntToStr(tfo1.FileSize);

        sgDuplicatesSize.RowCount := sgDuplicatesSize.RowCount + 1;

        fs := tfo1.FileSize;

        inc(dcount);
      end;

      sgDuplicatesSize.Cells[0, sgDuplicatesSize.RowCount - 1] := GScanDetails[FSource].Folders[tfo2.FilePathIndex] + tfo2.FileName;
      sgDuplicatesSize.Cells[1, sgDuplicatesSize.RowCount - 1] := TConvert.ConvertToUsefulUnit(tfo2.FileSize);
      sgDuplicatesSize.Cells[2, sgDuplicatesSize.RowCount - 1] := IntToStr(tfo2.FileSize);

      sgDuplicatesSize.RowCount := sgDuplicatesSize.RowCount + 1;
    end
    else begin
      if fs <> -1 then
        sgDuplicatesSize.RowCount := sgDuplicatesSize.RowCount + 1;

      fs := -1;
    end;
  end;

  // ===========================================================================

  lDCountDS.HTMLText[0] := XText[kFound] + ' <b>' + IntToStr(dcount) + '</b> ' + XText[kDuplicateFilenames] + '.';

  if dcount = 0 then
    status := False
  else
    status := True;

  sbSaveDS.Enabled    := status;
  sbCopyDS.Enabled    := status;
  sbCopyCSVDS.Enabled := status;

  sgDuplicatesSize.EndUpdate;

  Screen.Cursor := crDefault;
end;


procedure TFrameSearch.sbSaveDSClick(Sender: TObject);
var
  tf : TextFile;
  t : integer;
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[kXFileList] + ' (*.txt)|*.txt',
                                    '.txt',
                                    TUtility.GetDefaultFileName('.txt', 'duplicates_' + XText[kReport]),
                                    GSystemGlobal.AppDataPath + 'Saves\Duplicates');

  if lFileName <> '' then begin
    AssignFile(tf, lFileName);

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[kErrorSaving] + ': ' + XText[kDuplicatesFileSize],
                  XText[kErrorSaving] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      for t := 1 to sgDuplicatesSize.RowCount - 1 do begin
        Writeln(tf, TXFormatting.AddLeading(sgDuplicatesSize.Cells[1, t], 10, ' ') + ' ' + sgDuplicatesSize.Cells[0, t]);
      end;

      CloseFile(tf);
    end;
    {$I+}
  end;
end;


procedure TFrameSearch.sbCopyDSClick(Sender: TObject);
begin
  TGridUtility.CopyGridToClipboard(0, sgDuplicatesSize);
end;


procedure TFrameSearch.SpeedButton5Click(Sender: TObject);
begin
  THelp.OpenHelpPage('a31.htm');
end;


procedure TFrameSearch.sbCopyCSVDSClick(Sender: TObject);
 var
  tf : TextFile;
  t : integer;
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[kTextFiles] + ' (*.csv)|*.csv',
                                    '.csv',
                                    TUtility.GetDefaultFileName('.csv', 'duplicates_' + XText[kReport]),
                                    GSystemGlobal.AppDataPath + 'Saves\Duplicates');

  if lFileName <> '' then begin
    AssignFile(tf, lFileName);

    {$I-}
    Rewrite(tf);
    {$I+}

    if IOResult <> 0 then begin
      ShowXDialog(XText[kErrorSavingReport] + ' (CSV)',
                  XText[kErrorSaving] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      for t := 1 to sgDuplicatesSize.RowCount - 1 do begin
        if sgDuplicatesSize.Cells[0, t] <> '' then
          Writeln(tf, '"' + sgDuplicatesSize.Cells[0, t] + '",' + sgDuplicatesSize.Cells[1, t] + ',' + sgDuplicatesSize.Cells[2, t]);
      end;

      CloseFile(tf);
    end;
  end;
end;


procedure TFrameSearch.miCopyAllClick(Sender: TObject);
 var
  s : string;
  t : integer;
  tfo : TFileObject;

 begin
  s := GetCopyMoveFolder(XText[kCopyTo] + rsEllipsis);

  if s <> '' then begin
    for t := 0 to GScanDetails[dataSearch].Files.Count - 1 do begin
      tfo := GScanDetails[dataSearch].Files[t];

      CopyFile(PChar(GScanDetails[dataSearch].Folders[tfo.FilePathIndex] + tfo.FileName),
               PChar(s + tfo.FileName),
               False);
    end;
  end;
end;


procedure TFrameSearch.miCopySelectedClick(Sender: TObject);
var
  s : string;
  lFileName : string;

begin
  s         := GetCopyMoveFolder(XText[kCopyTo] + rsEllipsis);
  lFileName := GetSelectedFileName(TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag);

  if (s <> '') and (lFileName <> '') then begin
    CopyFile(PChar(lFileName),
             PChar(s + ExtractFileName(lFileName)),
             False);
  end;
end;


procedure TFrameSearch.miDeleteAllClick(Sender: TObject);
var
  t : integer;
  tfo : TFileObject;

begin
  if MessageDlg(XText[kDialog4], mtWarning, [mbYes, mbNo], 0) = mrYes then begin
    for t := 0 to GScanDetails[dataSearch].Files.Count - 1 do begin
      tfo := GScanDetails[dataSearch].Files[t];

      TXWindows.SendToRecycleBin(GScanDetails[dataSearch].Folders[tfo.FilePathIndex] + tfo.FileName);
    end;
  end;
end;


procedure TFrameSearch.miDeleteSelectedClick(Sender: TObject);
var
  lFileName : string;

begin
  if MessageDlg(XText[kDialog3], mtWarning, [mbYes, mbNo], 0) = mrYes then begin
    lFileName := GetSelectedFileName(TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag);

    if (lFileName <> '') then begin
      TXWindows.SendToRecycleBin(lFileName);
    end;
  end;
end;


procedure TFrameSearch.miExploreDirectoryClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := GetSelectedFileName(TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag);

  if lFileName <> '' then
    TXWindows.ExecuteFile(0, '"' + ExtractFilePath(lFileName) + '"', '', '');
end;


procedure TFrameSearch.miGenerateMD5Click(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := GetSelectedFileName(TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag);

  if lFileName <> '' then
    ShowMD5Checksum(lFileName, TMD5.Generate(lFileName));
end;


procedure TFrameSearch.miHexEditClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := GetSelectedFileName(TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag);

  if lFileName <> '' then
    TXWindows.ExecuteFile(0, '"' + GSystemGlobal.ExePath + '\Be.HexEditor.exe"', lFileName, '');
end;


procedure TFrameSearch.miMoveAllClick(Sender: TObject);
 var
  s : string;
  t : integer;
  tfo : TFileObject;

 begin
  s := GetCopyMoveFolder(XText[kMoveTo] + rsEllipsis);

  if s <> '' then begin
    for t := 0 to GScanDetails[dataSearch].Files.Count - 1 do begin
      tfo := GScanDetails[dataSearch].Files[t];

      MoveFileEx(PChar(GScanDetails[dataSearch].Folders[tfo.FilePathIndex] + tfo.FileName),
                 PChar(s + tfo.FileName),
                 MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
    end;
  end;
end;


procedure TFrameSearch.miMoveSelectedClick(Sender: TObject);
var
  s : string;
  lFileName : string;

begin
  s         := GetCopyMoveFolder(XText[kMoveTo] + rsEllipsis);
  lFileName := GetSelectedFileName(TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag);

  if (s <> '') and (lFileName <> '') then begin
    MoveFileEx(PChar(lFileName),
               PChar(s + lFileName),
               MOVEFILE_COPY_ALLOWED + MOVEFILE_REPLACE_EXISTING + MOVEFILE_WRITE_THROUGH);
  end;
end;


procedure TFrameSearch.miQuickSearchClick(Sender: TObject);
var
  ss : string;
  ix : integer;

begin
  ss := '';
  ix := -1;

  if Pos('{', MenuStrings[TMenuItem(Sender).Tag]) <> 0 then
    ss := ParseMenuSearchCommand(MenuStrings[TMenuItem(Sender).Tag])
  else if MenuStrings[TMenuItem(Sender).Tag][1] = '$' then
    ix := ParseMenuSearchCommandII(MenuStrings[TMenuItem(Sender).Tag])
  else
    ss := MenuStrings[TMenuItem(Sender).Tag];

  if ix <> -1 then begin
    case ix of
      1 : if Assigned(FOpenSearchWizard) then
            FOpenSearchWizard(0);
    end;
  end
  else begin
    if ss <> '' then begin
      eSearch.Text := ss;
      eSearchChange(Nil);

      sbGoSearchClick(sbGoSearch);
    end;
  end;
end;


procedure TFrameSearch.miSearchExportToCBClick(Sender: TObject);
begin
  case TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag of
    1 : SearchCSVReport;
    2 : sbCopyCSVDNClick(Nil);
    3 : sbCopyCSVDSClick(Nil);
  end;
end;


procedure TFrameSearch.SearchCSVReport;
var
  lCSVOutput : TStringList;
  tempCSVOptions : TCSVReportOptions;

begin
  lCSVOutput := TStringList.Create;

  tempCSVOptions := XSettings.Report.CSVOptions[LayoutQuick];
  tempCSVOptions.CSVData  := CDataFileList;
  tempCSVOptions.FileName := '';
  tempCSVOptions.Category := -1;

  GReportCSV.GenerateCSVReport(dataSearch, lCSVOutput, tempCSVOptions, LayoutQuick);

  Clipboard.AsText := lCSVOutput.Text;

  FreeAndNil(lCSVOutput);
end;


procedure TFrameSearch.miSearchOpenClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := GetSelectedFileName(TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag);

  if lFileName <> '' then
    TXWindows.ExecuteFile(0, '"' + lFileName + '"', '', '');
end;


procedure TFrameSearch.miSearchOpenCustomClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := GetSelectedFileName(TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag);

  if lFileName <> '' then
    if FileExists(lFileName) then
      TXWindows.ExecuteFile(0, '"' + XSettings.General.CustomViewer + '"', '"' + lFileName + '"', '')
    else
      TMSLogger.Error('miSearchOpenCustomClickError loading file "' + lFileName + '".');
end;


procedure TFrameSearch.miSFilePropertiesClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := GetSelectedFileName(TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag);

  if lFileName <> '' then
    TXWindows.ShowFilePropertiesDialog(Application.Handle, lFileName);
end;


procedure TFrameSearch.miSSaveClick(Sender: TObject);
begin
  case TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag of
    1 : sbSaveSearchClick(Nil);
    2 : sbSaveDNClick(Nil);
    3 : sbSaveDSClick(Nil);
  end;
end;


procedure TFrameSearch.miZIPClick(Sender: TObject);
 var
  lZipCount : integer;
  lFileName : string;

 begin
  lFileName := TXSaveDialog.Execute(XText[kCompressedFiles] + ' (*.zip)|*.zip',
                                    '.zip',
                                    TUtility.GetDefaultFileName('.zip', XText[kSearch] + '_' + XText[kExport]));

  if lFileName <> '' then begin

    lZipCount := XinorbisZip.ZipAllFiles(lFileName, TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag, sgSearchResults, schIFileName);

    if lZipCount = -1 then
      ShowXDialog(XText[kErrorCompressingFiles],
                  XText[kErrorCompressingFiles],
                  XDialogTypeWarning)
    else if lZipCount = 0 then
      ShowXDialog(XText[kWarning],
                  XText[kNoFilesToCompress] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
  end;
end;


procedure TFrameSearch.bHelpDNClick(Sender: TObject);
begin
  THelp.OpenHelpPage('a21.htm');
end;


procedure TFrameSearch.BuildSearchChart;
 begin
  if (GScanDetails[FSource].FileCount <> 0) and (GScanDetails[FSource].TotalSize <> 0) then begin
    guageSearchQuantity.SetDisplay(((TotalSearchFilesCount + TotalSearchFoldersCount) / (GScanDetails[FSource].FileCount + GScanDetails[FSource].FolderCount)) * 100);
    guageSearchSize.SetDisplay(    ((TotalSearchSize) / GScanDetails[FSource].TotalSize) * 100);
  end
end;


procedure TFrameSearch.UpdateSearchCapacity;
 var
  t : integer;
  lCapacityItem : TCapacityItem;

 begin
  capacitySearch.Items.Clear;

  for t := 1 to __FileCategoriesCount do begin
    if sbSearchThing.Tag = 1 then begin
      if GScanDetails[dataSearch].Files.Count <> 0 then begin
        if ExtSpreadSearch[t, 1] <> 0 then begin
          lCapacityItem             := capacitySearch.Items.Add;
          lCapacityItem.Value       := (ExtSpreadSearch[t, 1] / TotalSearchFilesCount) * 100;
          lCapacityItem.Color       := GSystemGlobal.FileCategoryColors[t];
          lCapacityItem.ColorTo     := GSystemGlobal.FileCategoryColors[t];
          lCapacityItem.DisplayName := TypeDescriptions[t];
          lCapacityItem.Description := TypeDescriptions[t];
          lCapacityItem.Hint        := TypeDescriptions[t] + ' (' + IntToStr(ExtSpreadSearch[t, 1]) + ' files)';
        end;
      end;
    end
    else begin
      if TotalSearchSize <> 0 then begin
        if ExtSpreadSearch[t, 2] <> 0 then begin
          lCapacityItem             := capacitySearch.Items.Add;
          lCapacityItem.Value       := (ExtSpreadSearch[t, 2] / TotalSearchSize) * 100;
          lCapacityItem.Color       := GSystemGlobal.FileCategoryColors[t];
          lCapacityItem.ColorTo     := GSystemGlobal.FileCategoryColors[t];
          lCapacityItem.DisplayName := TypeDescriptions[t];
          lCapacityItem.Description := TypeDescriptions[t];
          lCapacityItem.Hint        := TypeDescriptions[t] + ' (' + TConvert.ConvertToUsefulUnit(ExtSpreadSearch[t, 2]) + ')';
        end;
      end;
     end;
  end;
end;


procedure TFrameSearch.RebuildCharts;
 begin
   {}
end;


procedure TFrameSearch.RenderResults(aBegin, aEnd : integer);
var
  lBegin, lEnd, lTemp, lInc : integer;
  t, sColourCode : integer;
  ts : string;
  lFinished : boolean;
  tfo : TFileObject;

begin
  lBegin    := aBegin;
  lEnd      := aEnd;
  lInc      := 1;

  if lBegin < 0 then
    lBegin := 0;

  if lEnd > GScanDetails[dataSearch].Files.Count - 1 then
    lEnd := GScanDetails[dataSearch].Files.Count - 1;

  if sgSearchResults.SortSettings.Direction = sdAscending then begin
    lTemp  := lEnd;
    lEnd   := lBegin;
    lBegin := lTemp;

    lInc   := -1;
  end;

  TGridUtility.ClearStringGird(sgSearchResults, False);

  sgSearchResults.BeginUpdate;

  sgSearchResults.RowCount := 2;

  if GScanDetails[dataSearch].Files.Count <> 0 then begin

    t := lBegin;

    repeat

      tfo := GScanDetails[dataSearch].Files[t];

      // == File Name / Path =====================================================

      if cbSearchShowPath.Checked then
       sgSearchResults.Cells[schVFileName, sgSearchResults.RowCount - 1] := GScanDetails[dataSearch].Folders[tfo.FilePathIndex] + tfo.FileName
      else
        sgSearchResults.Cells[schVFileName, sgSearchResults.RowCount - 1] := tfo.FileName;

      sgSearchResults.Cells[schIFileName, sgSearchResults.RowCount - 1] := GScanDetails[dataSearch].Folders[tfo.FilePathIndex] + tfo.FileName;

      // == File Size ============================================================

      if ((faDirectory and tfo.Attributes) = faDirectory) then begin
        sgSearchResults.Cells[schVSize,   sgSearchResults.RowCount - 1]   := UpperCase(XText[kFolder]);
        sgSearchResults.Cells[schISize,   sgSearchResults.RowCount - 1]   := '-1';

        sgSearchResults.Cells[schIColour, sgSearchResults.RowCount - 1] := IntToStr(FileCategoryDirectory);
      end
      else begin
        sgSearchResults.Cells[schVSize,   sgSearchResults.RowCount - 1]   := TConvert.ConvertToUsefulUnit(tfo.FileSize);
        sgSearchResults.Cells[schISize,   sgSearchResults.RowCount - 1]   := IntToStr(tfo.FileSize);

        sColourCode  := FileExtensionsObject.GetExtensionCategoryIDFromName(tfo.FileName);
        sgSearchResults.Cells[schIColour, sgSearchResults.RowCount - 1] := IntToStr(sColourCode);
      end;

      // == Attributes ===========================================================

      ts := '----  ';
      if ((faArchive and tfo.Attributes)  = faArchive) then  ts[1] := 'A';
      if ((faReadOnly and tfo.Attributes) = faReadOnly) then ts[2] := 'R';
      if ((faSysFile and tfo.Attributes)  = faSysFile) then  ts[3] := 'S';
      if ((faHidden and tfo.Attributes)   = faHidden) then   ts[4] := 'H';

      sgSearchResults.Cells[schVAttributes, sgSearchResults.RowCount - 1] := ts;

      // == User =================================================================

      sgSearchResults.Cells[schVOwner, sgSearchResults.RowCount - 1]      := GScanDetails[dataSearch].Users[tfo.Owner].Name;

      // == Dates ================================================================

      sgSearchResults.Cells[schVCDate, sgSearchResults.RowCount - 1]      := TConvert.IntDateToString(tfo.FileDateC);
      sgSearchResults.Cells[schICDate, sgSearchResults.RowCount - 1]      := IntToStr(tfo.FileDateC);

      sgSearchResults.Cells[schVADate, sgSearchResults.RowCount - 1]      := TConvert.IntDateToString(tfo.FileDateA);
      sgSearchResults.Cells[schIADate, sgSearchResults.RowCount - 1]      := IntToStr(tfo.FileDateA);

      sgSearchResults.Cells[schVMDate, sgSearchResults.RowCount - 1]      := TConvert.IntDateToString(tfo.FileDateM);
      sgSearchResults.Cells[schIMDate, sgSearchResults.RowCount - 1]      := IntToStr(tfo.FileDateM);

      // =========================================================================

      sgSearchResults.RowCount := sgSearchResults.RowCount + 1;

      inc(t, lInc);

      if (lInc = 1) then
        lFinished := t > lEnd
      else
        lFinished := t < lEnd;

    until lFinished;

    if sgSearchResults.RowCount <> 2 then
      sgSearchResults.RowCount := sgSearchResults.RowCount - 1;
  end;

  sgSearchResults.EndUpdate;
end;


procedure TFrameSearch.UpdateGUI;
var
  ts : string;

begin
  if sgSearchResults.Cells[schVFilename, 1] = '' then begin
    ClearGUI(True);
  end
  else begin
    ts := '';

    if TotalSearchFilesCount <> 0 then
      if GScanDetails[FSource].FileCount = 0 then
        ts := XText[kFound] + ' <b>' + IntToStr(TotalSearchFilesCount) + '</b> ' + XText[kFiles] + ' (100%)'
      else
        ts := XText[kFound] + ' <b>' + IntToStr(TotalSearchFilesCount) + '</b> ' + XText[kFiles] + ' (<b>' + FloatToStrF(((TotalSearchFilesCount) / GScanDetails[FSource].FileCount) * 100, ffFixed, 7, 2, XinorbisFormatSettings) + '%</b>)';

    if TotalSearchFoldersCount <> 0 then begin
      if ts = '' then
        ts := XText[kFound] + ' <b>' + IntToStr(TotalSearchFoldersCount) + '</b> ' + XText[kFolders] + ' (<b>' + FloatToStrF(((TotalSearchFoldersCount) / GScanDetails[FSource].FolderCount) * 100, ffFixed, 7, 2, XinorbisFormatSettings) + '%</b>)'
      else
        ts := ts + ' ' + XText[kAnd] + ' <b>' + IntToStr(TotalSearchFoldersCount) + '</b> ' + XText[kFolders] + ' (<b>' + FloatToStrF(((TotalSearchFoldersCount) / GScanDetails[FSource].FolderCount) * 100, ffFixed, 7, 2, XinorbisFormatSettings) + '%</b>)';
    end;

    if GScanDetails[FSource].TotalSize <> 0 then
      lSearchDetails.HTMLText[0] := ts + ', <b>' + TConvert.ConvertToUsefulUnit(TotalSearchSize) + '</b> (' + FloatToStrF((TotalSearchSize / GScanDetails[FSource].TotalSize) * 100, ffFixed, 7, 2, XinorbisFormatSettings) + '%)'
    else
      lSearchDetails.HTMLText[0] := ts + ', <b>' + TConvert.ConvertToUsefulUnit(TotalSearchSize) + '</b> (100%)';

    UpdateSearchGUI;
  end;
end;


procedure TFrameSearch.UpdateSearchGUI;
begin
  lPageNumber.Caption := IntToStr(FPageNumber + 1) + ' (' + IntToStr(FLastPage + 1) + ')';

  lShowing.Caption := XText[kShowing] + ' ' +
                      IntToStr((FPageNumber * XSettings.General.MaxSearchResults) + 1) +
                      rsEllipsis + IntToStr((FPageNumber * XSettings.General.MaxSearchResults) + sgSearchResults.RowCount - 1) + ' ' +
                      XText[kOf] + ' ' + IntToStr(TotalSearchFilesCount + TotalSearchFoldersCount) + '.';

  if FPageNumber > FFirstPage then
    lsPagePrevious.Enabled := True
  else
    lsPagePrevious.Enabled := False;

  if FPageNumber < FLastPage then
    lsPageNext.Enabled := True
  else
    lsPageNext.Enabled := False;

  ResizeColumns;
end;


procedure TFrameSearch.ClearGUI(aNoResults : boolean);
begin
  if aNoResults then
    lSearchDetails.HTMLText[0] := XText[kNoMatchesFound]
  else
    lSearchDetails.HTMLText[0] := '';

  lsPagePrevious.Enabled     := False;
  lsPageNext.Enabled         := False;

  FPageNumber                := 0;
  lPageNumber.Caption        := '';

  lShowing.Caption           := '';
end;


procedure TFrameSearch.ResizeColumns;
begin
  sgsearchresults.AutoFitColumns(true);
end;


// =============================================================================
// =============================================================================
// =============================================================================


procedure TFrameSearch.BuildPropertiesTab(aDataIndex : integer);
var
  t : integer;

begin
  Screen.Cursor  := crHourGlass;

  GScanDetails[aDataIndex].FromFile      := False;
  GScanDetails[aDataIndex].Filename      := '';
  GScanDetails[aDataIndex].ScanTable     := '';
  GScanDetails[aDataIndex].ScanType      := ScanTypeSearch;
  GScanDetails[aDataIndex].ScanSource    := GScanDetails[FSource].ScanSource;
  GScanDetails[aDataIndex].ScanDateFHStr := GScanDetails[FSource].ScanDateFHStr;

  GScanDetails[aDataIndex].InitNow;

//  ToggleSoftwareStatus(aDataIndex, False);
  XSettings.ShowProgressWindow;

  // ===========================================================================

//    PurgeAllDataRefresh(aDATAINDEX, FrameReports[aDataIndex].sgNullFiles,
//                                    FrameReports[aDataIndex].sgNullFolders,
//                                    FrameSearch.sgSearchResults);

  // ======================================================================================================

  for t := 0 to JustInTimeCount do begin
    if XSettings.Optimisations.JustInTimeDisplay then
      XSettings.System.JustInTimeProcessed[aDataIndex, t] := False
    else
      XSettings.System.JustInTimeProcessed[aDataIndex, t] := True;
  end;

  FReportsFrame.PreScan;

  XSettings.Forms.ProgressForm.SetProcessBar(1);
  GXinorbisScan.DataIndex := aDataIndex;
  GXinorbisScan.Clear;
  GXinorbisScan.Analyse;

  GScanDetails[aDataIndex].TotalSize   := GXinorbisScan.FileTotalSpace;
  GScanDetails[aDataIndex].TotalSizeOD := GXinorbisScan.FileOnDisk;
  GScanDetails[aDataIndex].FileCount   := GXinorbisScan.FileCount;
  GScanDetails[aDataIndex].FolderCount := GXinorbisScan.FolderCount;

  XSettings.Forms.ProgressForm.SetProcessIcon(2);
//    BuildRootListFromXinFiles(1);

  XSettings.Forms.ProgressForm.SetProcessText(XText[kAnalysingData] + rsEllipsis);

  GXinorbisScan.AnalyseData(True);

  FReportsFrame.PostScan;

  XSettings.Forms.ProgressForm.SetProcessBar(5);

  XSettings.Forms.ProgressForm.SetProcessIcon(3);

  // =====================================================================

  FReportsFrame.BuildDisplay;

  // =====================================================================

  FReportsFrame.RefreshGraph(nil);

//  ToggleSoftwareStatus(aDataIndex, True);

  XSettings.HideProgressWindow;

  Screen.Cursor := crDefault;
end;


end. */

#pragma region Tab_Search
void __fastcall TFrameSearch::sbGoSearchClick(TObject *Sender)
{
/*procedure TFrameSearch.sbGoSearchClick(Sender: TObject);
begin
  if not(XSettings.ProcessWindowsVisible) then begin
	if eSearch.Text <> '' then begin

	  FSearchDataChanged := True;

	  sbGoSearch.Enabled := False;

	  FPageNumber        := 0;

	  GScanEngine->Search.Clear();

	  if Assigned(FMenuChange) then
		FMenuChange('', 0, 1);

	  lSearchDetails.HTMLText[0] := XText[kSearching] + rsEllipsis;
	  lSearchDetails.Refresh;

	  if eSearch.Items.IndexOf(eSearch.Text) = -1 then begin
		if eSearch.Text <> '' then
		  eSearch.Items.Insert(0, eSearch.Text);
	  end;

	  FSearchThread := TSearchThread.Create(True);
	  FSearchThread.SetData(FSource, eSearch.Text);
	  FSearchThread.OnGetResults    := OnNewResults;
	  FSearchThread.OnTerminate     := SearchThreadOnTerminate;
	  FSearchThread.Priority        := tpHigher;
	  FSearchThread.Start;
	end;
  end;
end;*/
}


void __fastcall TFrameSearch::eSearchChange(TObject *Sender)
{
//  leave uncommented ClearGUI(False);
}


void __fastcall TFrameSearch::eSearchKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN && sbGoSearch->Enabled)
	{
		sbGoSearchClick(sbGoSearch);
	}
}


void __fastcall TFrameSearch::sbQuickSearchClick(TObject *Sender)
{
//
}


void __fastcall TFrameSearch::sbSearchHelpClick(TObject *Sender)
{
	// to do THelp.OpenHelpPage('t41.htm');
}


void __fastcall TFrameSearch::sbSearchSyntaxClick(TObject *Sender)
{
// to do	THelp.OpenSearchManual;
}


void __fastcall TFrameSearch::sbSCAccessedClick(TObject *Sender)
{
//	TGridUtility.ToggleColumn(sgSearchResults,
//							  TSpeedbutton(Sender),
//	   to do						  TableColumnLookup[(TSpeedbutton(Sender).Tag * 2) + 1],
//							  TableColumnLookup[TSpeedbutton(Sender).Tag * 2]);
//
//	ResizeColumns();
}


void __fastcall TFrameSearch::cbSearchColourCodeClick(TObject *Sender)
{
	if (sgSearchResults->Cells[__GridColVFilename][1] != L"")
	{
		if (cbSearchColourCode->Checked)
		{
			sgSearchResults->Font->Color = clBlack;
		}
		else
		{
			sgSearchResults->Font->Color = clWhite;
		}

		sgSearchResults->Refresh();
    }
}


void __fastcall TFrameSearch::cbSearchShowPathClick(TObject *Sender)
{
	sbGoSearchClick(sbGoSearch);
}
#pragma end_region


#pragma region Tab_Duplicates_Name
#pragma end_region


#pragma region Tab_Duplicates_Size
#pragma end_region


#pragma region Tab_Properties
#pragma end_region
