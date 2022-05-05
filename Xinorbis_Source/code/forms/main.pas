{
      ZeemSpace - Hard Disk analyser

      ** xinorbis - Renamed February 28th 2002 **

      (c) Paul Alan Freshney 2002-2003
      (c) Aardvark Digital 2002-2003

  Delphi 7 convert, September 10th 2003

  Original Started: January 6th 2002
     Last Modified: September 9th 2003

  Version2

             Started: September 10th 2003
     Last Modiucfied: July 8th 2004

  Version3+

           Started: February 27th 2005
     Last Modified: February 14th 2014

  Version 6.1

           Started: March 6th 2014
     Last Modified: March 6th 2014

  Version 6.2 (Unicode vesion)

           Started: September 25th 2014
     Last Modified: September 25th 2014

  Version 7.0

           Started: December 16th 2015
     Last Modified: December 16th 2015

  Migration to Delphi 2007, December 7th 2012

  Version 8.0

  Migration to Delphi 10.1 Berlin

           Started: October 8th 2016
     Last Modified: June 9th 2019

  Version 8.3.0

           Started: January 6th 2020

  4596 (45520)
}


unit main;


interface


uses
  Generics.Defaults, Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs, ExtCtrls, ComCtrls, ToolWin, StdCtrls, Buttons,
  OleCtrls, ImgList, Menus, Spin, ActnList, Contnrs, HTMLabel, math, ShlObj,
  VCLTee.Series, VCLTee.TeEngine, VCLTee.TeeProcs, VCLTee.Chart,
  BaseGrid, AdvGrid, shellAPI, ShellCtrls, dateutils, CheckLst, ZipMstr, Gauges,
  IdBaseComponent, IdComponent, IdTCPConnection, IdTCPClient, AdvGlowButton,
  Grids, AdvSmoothButton, AdvSmoothTabPager, AdvSmoothPanel, AdvSmoothExpanderPanel, IdExplicitTLSClientServerBase,
  AdvUtil, Vcl.XPMan, System.ImageList, W7NaviButtons, W7Classes,
  AdvSmoothCapacityBar, AdvOfficeButtons, htmltv, AdvSplitter, AdvNavBar,
  AdvObj, Vcl.FileCtrl, FlCtrlEx, AeroButtons, VclTee.TeeGDIPlus, Vcl.AppEvnts, HTMLStatusBar,
  W7Buttons, W7Bars, AdvPanel,  AdvToolBtn, StrUtils,

  TMSLogging,

  X.Settings, X.Form.ReportOptions, X.Global, X.Help,

  X.FindFile, AdvPageControl, SyncObjs,
  X.Constants, X.ScanDetails,

  X.CReportOptions, X.ReportUtility,
  X.CCSVReports, X.CHTMLReports, X.CTextReports, X.CTreeReports, X.CXinorbisReports, X.CXMLReports,
  X.CSummaryReports,

  X.Form.EditCSVReport, X.Form.EditHTMLReport, X.Form.EditTextReport, X.Form.EditTreeReport,
  X.Form.EditXMLReport,

  X.GuiLogic,

  X.Thread.Search, X.Thread.WebReports,

  X.Thread.UpdateFolderHistory,
  X.Frame.FileHistory, X.Frame.Map, X.CFolderHistoryUtility,
  X.Frame.Exploder,

  Data.DbxSqlite, Data.DB, Data.SqlExpr, X.CCSVDataFormat, X.LanguageHandler, X.CQuickMenuHandler,

  X.Dialogs.Load, X.Dialogs.Save,

  X.Formatting, X.PurchaseUtility, X.Windows, X.Utility, X.SystemGlobal,

  X.Frame.Reports, X.Frame.Navigation, X.Frame.Summary, htmlhint, AdvToolBar,
  AdvMenus, AdvToolBarStylers;


const
  SideMenuWelcomeCount  = 2;
  SideMenuTasksCount    = 8;
  SideMenuAdvancedCount = 3;


type
  TFormDisplay = record
                   PanelInFront : integer;
                   Source       : integer;
                 end;


  TfrmMain = class(TForm)
    ilToolbar: TImageList;
    mMainMenu: TMainMenu;
    File1: TMenuItem;
    Exit1: TMenuItem;
    Help1: TMenuItem;
    About1: TMenuItem;
    miXinorbisHome: TMenuItem;
    Help2: TMenuItem;
    N7: TMenuItem;
    Edit1: TMenuItem;
    miPreferences: TMenuItem;
    View1: TMenuItem;
    miHTMLReport: TMenuItem;
    miXMLReport: TMenuItem;
    miSaveReports: TMenuItem;
    InformationSection1: TMenuItem;
    miTabTable: TMenuItem;
    miTabTree: TMenuItem;
    miTabFolders: TMenuItem;
    miTabOther: TMenuItem;
    miTabNullFiles: TMenuItem;
    miTabMagnitude: TMenuItem;
    miTabFileDates: TMenuItem;
    Checkforupdate1: TMenuItem;
    miTabTop50: TMenuItem;
    miLanguage: TMenuItem;
    miLang1: TMenuItem;
    miLang2: TMenuItem;
    miLang3: TMenuItem;
    miLang4: TMenuItem;
    miLang5: TMenuItem;
    miLang6: TMenuItem;
    miLang7: TMenuItem;
    miLang8: TMenuItem;
    miLang9: TMenuItem;
    miCSVReport: TMenuItem;
    miReportBrowser: TMenuItem;
    miTextReport: TMenuItem;
    miTabHistory: TMenuItem;
    miTabUsers: TMenuItem;
    miTabTemp: TMenuItem;
    N12: TMenuItem;
    ilBigToolbar: TImageList;
    miFHInfo: TMenuItem;
    N19: TMenuItem;
    miShowSearchSyntax: TMenuItem;
    miShowCategoryColours: TMenuItem;
    miContextHelp: TMenuItem;
    miSearch: TMenuItem;
    miSearchWizard: TMenuItem;
    miDetail: TMenuItem;
    miDFileSize: TMenuItem;
    miDDuplicatesName: TMenuItem;
    miDDuplicatesSize: TMenuItem;
    miSearchMain: TMenuItem;
    miFAQs: TMenuItem;
    miXinorbisReport: TMenuItem;
    miTreeReport: TMenuItem;
    miOpenLastReport: TMenuItem;
    N18: TMenuItem;
    miCopyLastReportToClipboard: TMenuItem;
    miBackupData: TMenuItem;
    miReference: TMenuItem;
    puCustomReport: TPopupMenu;
    miCustomReport: TMenuItem;
    N25: TMenuItem;
    miOpenCustomReport: TMenuItem;
    miUserManual: TMenuItem;
    N26: TMenuItem;
    miScan: TMenuItem;
    N27: TMenuItem;
    miMoreFolderDetail: TMenuItem;
    ilNavToolbar_On: TImageList;
    ilNavToolbar_Off: TImageList;
    N14: TMenuItem;
    miLang10: TMenuItem;
    pTutorial: TPanel;
    miTutorial: TMenuItem;
    N33: TMenuItem;
    lTutorial: THTMLabel;
    miHelpCats: TMenuItem;
    N34: TMenuItem;
    N35: TMenuItem;
    miAddXinorbistoExplorerToContextMenu: TMenuItem;
    miLang13: TMenuItem;
    ApplicationEvents1: TApplicationEvents;
    sbMain: THTMLStatusBar;
    vtcHTML: TChart;
    PieSeries6: TPieSeries;
    vtcHTML2: TChart;
    Series2: TBarSeries;
    miDebug: TMenuItem;
    ClearLanguage1: TMenuItem;
    DialogTest1: TMenuItem;
    Information1: TMenuItem;
    Warning1: TMenuItem;
    Xinorbis1: TMenuItem;
    miCustomiseQuickFolderMenu: TMenuItem;
    miLang11: TMenuItem;
    miLang12: TMenuItem;
    miMainReports: TMenuItem;
    miEditHTMLReports: TMenuItem;
    miEditTextReports: TMenuItem;
    miEditCSVReports: TMenuItem;
    miEditTreeReports: TMenuItem;
    miEditXMLReports: TMenuItem;
    N1: TMenuItem;
    Panel1: TPanel;
    pViews: TPanel;
    Image15: TImage;
    Image16: TImage;
    Image17: TImage;
    Image25: TImage;
    Image8: TImage;
    lAdvID3: TLabel;
    lAdvID2: TLabel;
    lTaskID7: TLabel;
    lTaskID6: TLabel;
    lAdvID1: TLabel;
    pNavigation: TPanel;
    Image12: TImage;
    lTaskID1: TLabel;
    lTaskID2: TLabel;
    Image13: TImage;
    Image14: TImage;
    lTaskID3: TLabel;
    Image2: TImage;
    Image24: TImage;
    lTaskID4: TLabel;
    lTaskID5: TLabel;
    Image9: TImage;
    Image11: TImage;
    lWelcomeScan: TLabel;
    lWelcomeFolderHistory: TLabel;
    advSource: TAdvPanel;
    advViews: TAdvPanel;
    N2: TMenuItem;
    miHelpSendFeedback: TMenuItem;
    tbSourceLive: TAdvToolButton;
    tbSourceFolderHistory: TAdvToolButton;
    Panel2: TPanel;
    ilReports: TImageList;
    trayIcon: TTrayIcon;
    miFileAges: TMenuItem;
    lDataSource: TLabel;
    HTMLHint1: THTMLHint;
    N4: TMenuItem;
    miNewReportSM: TMenuItem;
    miFileAssociations: TMenuItem;
    miEdit: TMenuItem;
    N5: TMenuItem;
    Image1: TImage;
    lTaskID8: TLabel;
    N6: TMenuItem;
    miViewLogFolder: TMenuItem;
    AdvDockPanel1: TAdvDockPanel;
    AdvToolBar1: TAdvToolBar;
    AdvToolBarSeparator1: TAdvToolBarSeparator;
    AdvToolBarSeparator3: TAdvToolBarSeparator;
    tbSave: TW7ToolButton;
    tbPreferences: TW7ToolButton;
    W7ToolButton2: TW7ToolButton;
    W7ToolButton1: TW7ToolButton;
    tbWebReports: TW7ToolButton;
    AdvToolBarSeparator4: TAdvToolBarSeparator;
    tbSearchWizard: TW7ToolButton;
    W7ToolButton3: TW7ToolButton;
    AdvToolBarSeparator5: TAdvToolBarSeparator;
    tbHelp: TW7ToolButton;
    AdvDockPanel2: TAdvDockPanel;
    AdvToolBar2: TAdvToolBar;
    tbHome: TW7ToolButton;
    AdvToolBarSeparator6: TAdvToolBarSeparator;
    tbNavigatePrevious: TW7ToolButton;
    tbNavigateNext: TW7ToolButton;
    tbPrivacy: TW7ToolButton;
    AdvToolBarSeparator7: TAdvToolBarSeparator;
    AdvToolBarSeparator8: TAdvToolBarSeparator;
    tbToggleFH: TW7ToolButton;
    AdvToolBar3: TAdvToolBar;
    tbReportSummary: TW7ToolButton;
    tbReportCSV: TW7ToolButton;
    tbReportHTML: TW7ToolButton;
    tbReportText: TW7ToolButton;
    tbReportTree: TW7ToolButton;
    tbReportXML: TW7ToolButton;
    tbReportPreferences: TW7ToolButton;
    AdvMenuStyler1: TAdvMenuStyler;
    AdvToolBarOfficeStyler1: TAdvToolBarOfficeStyler;
    N3: TMenuItem;
    ReportOptions1: TMenuItem;
    miReportOptions: TMenuItem;
    N9: TMenuItem;
    miTabNameLength: TMenuItem;
    tbReportXinorbis: TW7ToolButton;
    tbPostScanWarning: TW7ToolButton;
    Searchmanual1: TMenuItem;
    tbToggleVirtual: TW7ToolButton;

    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormResize(Sender: TObject);
    procedure HandleResizing(NewPanelInFront : integer);

    procedure CreateObjects;
    procedure CreateReportObjects;
    procedure ConfigureObjects;

    function  DoScanModeNormal(aDataIndex : integer; aScanPath : string): string;
    procedure XinorbisScanPre(aDataIndex : integer; const aFromFile : string);
    procedure XinorbisScanExecute(aDataIndex : integer);
    procedure XinorbisScanAnalysis(aDataIndex : integer);
    procedure XinorbisScanBuild(aDataIndex : integer);
    procedure XinorbisScanReportsAndFH(aDataIndex : integer);
    procedure XinorbisScanPost(aDataIndex : integer);
    procedure XinorbisScan(aDataIndex : integer; ScanPath : string; const fromfile : string; ScanType, ScanSource : integer);

    procedure CombineScan;
    procedure BuildDisplay(aDataIndex : integer);
    procedure AutoSaveReports(aDataIndex : integer);

    procedure ConfigureFindFile(aScanPath : string; aTag : integer);

    function  BuildXinFilesFromReport(const aReportPath : string): boolean;
    function  BuildXin2FilesFromReport(const aReportPath : string): boolean;
    procedure BuildMainFromCSV(aDataIndex : integer; const fn : string);
    procedure ToggleSoftwareStatus(aDataIndex : integer; newstatus : boolean);
    procedure tbPrefsClick(Sender: TObject);
    procedure tbExitClick(Sender: TObject);
    procedure DoPreferenceChanges;

    procedure Exit1Click(Sender: TObject);
    procedure miXinorbisHomeClick(Sender: TObject);
    procedure ClearAllData;
    procedure FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
    procedure Checkforupdate1Click(Sender: TObject);
    procedure LoadFileExtensionData;
    procedure LoadLanguageDetails(languageindex : integer; debugmode : boolean);
    procedure UpdateGUICustomNames(aDataIndex : integer);
    procedure miLang1Click(Sender: TObject);
    procedure sbRefreshClick(Sender: TObject);
    procedure miReportBrowserClick(Sender: TObject);
    procedure ShowProcessWindow;
    procedure SetProcessBar(newposition : integer);
    procedure HideProcessWindow;
    procedure AnaylseDataThreadOnTerminate(Sender : TObject);
    procedure ProcessUpdateFolderHistoryFile;
    procedure FormDestroy(Sender: TObject);
    procedure miFHInfoClick(Sender: TObject);
    procedure miShowCategoryColoursClick(Sender: TObject);
    procedure miContextHelpClick(Sender: TObject);
    procedure UpdateFolderHistoryOnTerminate(Sender: TObject);

    procedure sbFHCXMLReportClick(Sender: TObject);
    procedure miSearchWizardClick(Sender: TObject);
    procedure AdvancedOptionsClick(Sender: TObject);
    procedure SetAdvancedOptions(aOptions : integer);
    procedure miFAQsClick(Sender: TObject);
    procedure LoadMenu(xMenu : TPopupMenu; aFilename : string);
    procedure miOpenLastReportClick(Sender: TObject);
    procedure miCopyLastReportToClipboardClick(Sender: TObject);
    procedure ShowZipProcessWindow;
    procedure HideZipProcessWindow;
    procedure miBackupDataClick(Sender: TObject);
    procedure miReferenceClick(Sender: TObject);
    procedure miCustomReportClick(Sender: TObject);
    procedure miOpenCustomReportClick(Sender: TObject);

    procedure BuildOpenCSVReport(CSVr : TCSVReportOptions);
    procedure BuildOpenHTMLReport(aDataIndex : integer; HTMLr : THTMLReportOptions);
    procedure BuildOpenTextReport(Textr : TTextReportOptions);
    procedure BuildOpenTreeReport(Treer : TTreeReportOptions);
    procedure miUserManualClick(Sender: TObject);
    procedure iSideMenuWelcomeClick(Sender: TObject);
    procedure SetSidePanelDisplay(welcomeID, taskID, tasksubID, canAddToHistory : integer);
    procedure UpdateLeftPanelStatus;
    procedure SetTasksDisplay(taskID : integer);
    procedure SetWelcomeDisplay(welcomeID : integer);
    procedure SetAdvancedDisplay(advancedID : integer);
    procedure lTaskID1Click(Sender: TObject);
    procedure sbNewScanClick(Sender: TObject);
    procedure tbHomeClick(Sender: TObject);
    procedure lReportPreferencesClick(Sender: TObject);
    procedure DoNavigationHistoryAction(const navaction : string);
    procedure AddToPageNavigationHistory(const pagedata : string);
    procedure tbNavigatePreviousClick(Sender: TObject);
    procedure tbNavigateNextClick(Sender: TObject);
    procedure About1Click(Sender: TObject);
    procedure lHelpSendFeedbackClick(Sender: TObject);
    procedure miTabTableClick(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure IfScanCancelled(aDataIndex : integer);
    procedure tbPrivacyClick(Sender: TObject);
    procedure sgReportListCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
    procedure tbToggleFHClick(Sender: TObject);
    procedure lReportHTMLMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure lReportXMLMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure lReportCSVMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure lReportTextMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure lReportXinorbisMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure lReportTreeMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure lWelcomeWebReportsClick(Sender: TObject);
    procedure tbWebReportsClick(Sender: TObject);
    procedure miTutorialClick(Sender: TObject);
    procedure lTutorialDblClick(Sender: TObject);
    procedure miHelpCatsClick(Sender: TObject);
    procedure miAddXinorbistoExplorerToContextMenuClick(Sender: TObject);
    procedure tbSearchWizardClick(Sender: TObject);

    procedure miHTMLReportClick(Sender: TObject);
    procedure Help2Click(Sender: TObject);
    procedure tbPreferencesClick(Sender: TObject);
    procedure miXMLReportClick(Sender: TObject);
    procedure miSaveReportsClick(Sender: TObject);
    procedure miCSVReportClick(Sender: TObject);
    procedure miTreeReportClick(Sender: TObject);
    procedure miXinorbisReportClick(Sender: TObject);
    procedure miTextReportClick(Sender: TObject);
    procedure ApplicationEvents1ShowHint(var HintStr: string; var CanShow: Boolean; var HintInfo: THintInfo);
    procedure ClearLanguage1Click(Sender: TObject);
    procedure lReportSummaryMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Information1Click(Sender: TObject);
    procedure Warning1Click(Sender: TObject);
    procedure Xinorbis1Click(Sender: TObject);
    procedure miCustomiseQuickFolderMenuClick(Sender: TObject);
    procedure miShowSearchSyntaxClick(Sender: TObject);
    procedure miEditHTMLReportsClick(Sender: TObject);
    procedure tbSourceLiveClick(Sender: TObject);
    procedure tbSourceFolderHistoryClick(Sender: TObject);
    procedure trayIconClick(Sender: TObject);
    procedure trayIconBalloonClick(Sender: TObject);
    procedure miSearchMainClick(Sender: TObject);
    procedure miFileAssociationsClick(Sender: TObject);
    procedure lWelcomeFolderHistoryMouseDown(Sender: TObject;
      Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure W7ToolButton3Click(Sender: TObject);
    procedure miViewLogFolderClick(Sender: TObject);
    procedure ReportOptions1Click(Sender: TObject);
    procedure Searchmanual1Click(Sender: TObject);
    procedure tbToggleVirtualClick(Sender: TObject);
  private
    FSource : integer;

    WelcomeOptions  : array[1..SideMenuWelcomeCount] of TLabel;
    TaskOptions     : array[1..SideMenuTasksCount] of TLabel;
    AdvancedOptions : array[1..SideMenuAdvancedCount] of TLabel;

    LanguageMenus   : array[0..13] of TMenuItem;

    FormDisplay     : TFormDisplay;

    NavigationHistory : TStringList;

    FrameSummary    : array[0..1] of TFrameSummary;
    FrameNavigation : array[0..1] of TFrameNavigation;
    FrameReports    : array[0..1] of TFrameReports;

    GUpdateFolderHistoryUpdateThread : TUpdateFolderHistoryUpdateThread;

    procedure Init;

    procedure CreateFrames;
    procedure CreateSummaryFrame(aDataIndex : integer);
    procedure CreateNavigationFrame(aDataIndex : integer);
    procedure CreateReportsFrame(aDataIndex : integer);
    procedure CreateSearchFrame;

    procedure DestroyFrames;

    procedure DestroyReports;

    procedure BuildSummary(aDataIndex, aFileCatMode : integer);

    procedure RequestNewScan(aDataIndex : integer; aFromFile : boolean; const aNewPath : string);
    procedure RequestNewCombineScan(const aStatus : integer);
    procedure RequestNewSummary(aDataIndex : integer; const aAutoOpen : integer);
    procedure RequestNewFHPath(const aPath : string);
    procedure RequestNewSearch(aDataIndex : integer; const aNewSearch : string);

    procedure ScanOnFoundNull(aDataIndex : integer; const aFileName : string);
    procedure ScanOnFoundTemp(aDataIndex : integer; const aFileName, aSizeWords, aSize : string);
    procedure ScanOnProgress(const aCount : integer);

    procedure TryBuildFolderHistoryAvailable;

    procedure OnJustInTime(aValue : integer);
    procedure OnNewReport;
    procedure OnBuildInformationDisplay(aValue : integer);
    procedure OnMenuChange(const aNewText : string; aMenuItem, aState : integer);
    procedure OnOpenSettingsTab(const aNewTab : integer);
    procedure OnOpenSearchWizard(const aStatus : integer);
    procedure OnReportsChange(const aNewTab : integer);
    procedure OnStatusBarChange(const aText : string);
    procedure OnTutorialBarChange(const aText : string);
    procedure OnResetDisplay(aStatus : integer);
    procedure OnChartsHaveChanged;

    procedure DoWelcome(aWelcomeID : integer);
    procedure DoTask(aTaskID, aTaskSubID : integer);

    procedure OnFormClose(const aForm : integer);
    procedure OnExtSetSidePanelDisplay(welcomeID, taskID, tasksubID, canAddToHistory : integer);
    procedure OnProcessWindowProgressChange(const aProgress : integer);
    procedure ScanFromFolderHistory(const aScanPath, aTableName : string; aFileHistoryDate : string);
    procedure OnUpdateHistoryFinished;

    procedure OnProcessWindowStatusChange(const aWindow, aStatus : integer);

    function  OnGetLeftOffset: integer;
    function  OnGetTopOffset: integer;
    function  IsFolderHistoryRunning: boolean;

    procedure NewSourceAvailable(aSource : integer);
    procedure ActivateSource(aSource : integer);
    procedure DeactivateSource(aSource : integer);

    procedure DoUpdateBalloon;
    procedure UpdateMainMenu;

    procedure UpdateFrameMap;
    procedure UpdateFrameExploder;
  public
  end;


var
  frmMain: TfrmMain;


implementation


{$R *.DFM}


uses System.Generics.Collections, System.UITypes, GDIPFill,

     X.MD5, X.Form.Preferences, X.Form.FileAssociations, X.Form.About, X.Form.Report, X.Form.FileProperties, X.Form.CheckVersion,
     Registry, X.Form.CSVProcess, ClipBrd, inifiles, X.Form.GetDateBetween,
     X.Form.GetSizeBetween, X.Form.ShowMD5, X.Form.CatColours,
     X.Form.GetCopyMove, X.Form.SearchWizard, X.Form.FileSpread,X.Form.ExcludeFolders,
     X.Form.DBSelectedFolder, X.Form.ChartOptions, X.Form.SelectLanguage, X.Form.Reference,
     X.Form.ExcludeFiles, VCLTee.TeCanvas,
     Masks, X.Form.ShowCalendar, X.FileExtension, X.FileExtensionsObject,
     X.Form.UserWizard, X.GridUtility, X.ChartUtility, X.DisplayUtility, X.Splash.Zip,
     X.Prescan, X.CScanHistoryObject, X.CFileObject,
     X.CUserData, X.CRootFoldersData, X.CFolderHistoryObject, X.CFolderHistoryInfo, X.Populatexinfiles,
     X.Dialogs.Dialog, X.ZipFiles, X.GuiUtil, X.GlobalObjects, X.ScanAnalysis,
     X.Conversions,

     X.Database, X.Form.DatabaseInfo,

     X.Form.Explore, X.Form.FileAges,

     X.Frame.Select, X.Frame.WebReports, X.Frame.Search,
     X.Form.QuickMenuBuilder;


const
  CReportHTML = 0;
  CReportCSV  = 1;
  CReportText = 3;
  CReportTree = 5;

  CAOSpread   = 0;
  CAOExplore  = 3;
  CAOFileAges = 4;

  CReportOffStart = 7;

  CToolbarSaveOff   = 0;
  CToolbarSaveOn    = 9;
  CToolbarPrefsOff  = 1;
  CToolbarPrefsOn   = 10;
  CToolbarWizardOff = 5;
  CToolbarWizardOn  = 8;


procedure TfrmMain.FormCreate(Sender: TObject);
var
  t : integer;
  param, s : string;

begin
  TGLobal.InitialiseGlobalText;
  Init;
  TGLobal.InitialiseSortCode;

  GXGuiUtil := TGuiUtil.Create(GSystemGlobal.ExePath + 'data\system\images\');

  Randomize;

  Caption               := 'xinorbis :: ' + x8Title + ' / ' + x8Date;
  sbMain.Panels[0].Text := XText[rsWelcomeTo] + ' Xinorbis <b>' + x8Version + '</b> / <b>' + x8Date + '</b>. (c) Paul Alan Freshney 2002-' + TUtility.GetCurrentYear;

  XinorbisZip           := TZipFiles.Create;

  CreateObjects;

  XSettings.LoadBasic;

  CreateReportObjects; // needs to be before frames!

  CreateFrames;
  ConfigureObjects;

  // ===========================================================================

  for t := 0 to __FileCategoriesCount do
    FHCCStatus[t] := True;

  // ===========================================================================

  FrameSelect.SetupQuickFolders;

  // ===========================================================================

  if XSettings.HistorySettings.Enabled then begin
    tbToggleFH.Enabled    := True;
    tbToggleFH.ImageIndex := 6;

    XSettings.System.UserEnabledFH := True;
  end
  else begin
    tbToggleFH.Enabled    := False;
    tbToggleFH.ImageIndex := 5;

    XSettings.System.UserEnabledFH := False;
  end;

  XSettings.System.UserEnabledVirtual := False;

  // ===========================================================================

  FrameSelect.BuildScanHistoryTable(0);


  if not FileExtensionsObject.LoadFileExtensionLists(XSettings.CustomSettings.SettingsSaveLocation) then
    TMSLogger.Info('Failed to load file extension data!');

  if ParamStr(ParamCount) = '/languagedebug' then
    LoadLanguageDetails(XSettings.CurrentLanguage, True)
  else
    LoadLanguageDetails(XSettings.CurrentLanguage, False);

  if ParamStr(ParamCount) = '/debug' then begin
    XSettings.System.Debug := True;

    TMSLogger.Info('Debug activated');
  end;

  // ---------------------------------------------------------------------------

  LoadFileExtensionData;
  DoPreferenceChanges;
  TXWindows.GetNetworkDrives;

  TXWindows.SetupFormatSettings;

  FormDisplay.PanelInFront := pMainPanelIndex;
  FormDisplay.Source       := -1;

  FrameSelect.BringToFront;

  TryBuildFolderHistoryAvailable;

  // ===========================================================================

  HandleResizing(pScanSelectionPanelIndex);
  FrameSelect.BringToFront;

  // ===========================================================================

  GXGuiUtil.SetButtonOffImage(FrameSearch.sbSCAccessed,   CImageAccessed);
  GXGuiUtil.SetButtonOffImage(FrameSearch.sbSCModified,   CImageModified);
  GXGuiUtil.SetButtonOffImage(FrameSearch.sbSCOwner,      CImageOwner);
  GXGuiUtil.SetButtonOffImage(FrameSearch.sbSCAttributes, CImageAttributes);

  // ===========================================================================

  if (ParamStr(1) <> '') then begin
    if UpperCase(ExtractFileExt(ParamStr(1))) = '.ZSR2' then
      XinorbisScan(dataLatestScan, '', ParamStr(1), ScanTypeNormal, ScanSourceFileXin2Detailed)
    else if UpperCase(ExtractFileExt(ParamStr(1))) = '.ZSR' then
      XinorbisScan(dataLatestScan, '', ParamStr(1), ScanTypeNormal, ScanSourceFileXinDetailed)
    else begin
      if SysUtils.DirectoryExists(ParamStr(1)) then begin

        param := ParamStr(1);
        if param[length(param)] <> '\' then param := param + '\';

        FrameSelect.ePath.Text := param;
        FrameSelect.sbGoPathClick(Nil);
      end;
    end;
  end;

  if FrameSelect.ePath.Text = '' then
    FrameSelect.ePath.Text := 'C:\';

  if FrameSelect.ePath.Text[2] = ':' then begin
    s := FrameSelect.ePath.Text;

    FrameSelect.dcbexMain.Drive     := s[1];
    FrameSelect.dlbexMain.Directory := s;
  end;

  // ===========================================================================

  DoUpdateBalloon;

  OnTutorialBarChange('intro');
end;


procedure TfrmMain.Xinorbis1Click(Sender: TObject);
begin
  {$IFDEF debug}
  ShowXDialog('Debug', 'Dialog test', XDialogTypeXinorbis);
  {$ENDIF}
end;


procedure TfrmMain.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  trayIcon.Visible := False;

  // ===========================================================================

  FrameSelect.SaveSettings;

  FrameFolderHistory.SaveSettings;

  FrameReports[dataLatestScan].SaveSettings;

  if Assigned(FrameReports[dataFolderHistory]) then
    FrameReports[dataFolderHistory].SaveSettings;

  // ===========================================================================

  FolderHistoryAvailable.Clear;

  XSettings.SaveBasic;

  if XSettings.Database.UseODBC then
    CloseODBC;

  Action := caFree;
end;


procedure TfrmMain.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
    CanClose := False;

    ShowXDialog(XText[rsWarning], XText[rsPleaseWaitFolderHistory], XDialogTypeXinorbis);
  end
  else if GWebReportsThread <> Nil then begin
    CanClose := False;

    ShowXDialog(XText[rsXinorbisIsBusy],
                XText[rsPleaseWaitWebReports],
                XDialogTypeXinorbis);
  end
  else
    CanClose := True;
end;


procedure TfrmMain.FormDestroy(Sender: TObject);
begin
  DestroyFrames;
  DestroyReports;

  FreeAndNil(GXinorbisScan);
  FreeAndNil(GXGuiUtil);
  FreeAndNil(GSystemGlobal);

  FreeAndNil(GScanDetails);
  FreeAndNil(FileExtensionsObject);

  XSettings.Free;

  TUtility.StringListClear(NetworkDrivesList);
  NetworkDrivesList.Free;

  FolderHistory.Free;
  FolderHistoryAvailable.Free;

  ScanHistory.Free;

  TUtility.StringListClear(MenuStrings);
  MenuStrings.Free;

  TUtility.StringListClear(NavigationHistory);
  NavigationHistory.Free;

  TUtility.StringListClear(HGraphData);
  HGraphData.Free;
  TUtility.StringListClear(FHGraphData);
  FHGraphData.Free;

  FreeAndNil(XinorbisZip);

  TLanguageHandler.Free;
end;


procedure TfrmMain.Information1Click(Sender: TObject);
begin
  {$IFDEF debug}
  ShowXDialog('Debug', 'Dialog test', XDialogTypeInformation);
  {$ENDIF}
end;


procedure TfrmMain.Init;
begin
  frmSpread               := TfrmSpread.Create(Self);
  frmFileAges             := TfrmFileAges.Create(Self);
  frmExplore              := TfrmExplore.Create(Self);

  frmSpread.OnHide        := OnFormClose;
  frmFileAges.OnHide      := OnFormClose;
  frmExplore.OnHide       := OnFormClose;

  tbSourceFolderHistory.Caption := XText[rsFolderHistory];

  {$IFNDEF debug}
  miDebug.Visible  := False;
  {$ENDIF}

  lDataSource.Caption           := XText[rsDataSource];
  tbSourceLive.Caption          := XText[rsScan];

  // == File Menu ============================================================================

  miScan.Caption                      := XText[rsScan] + rsEllipsis;
  miSaveReports.Caption               := XText[rsSaveReports] + rsEllipsis;
  Exit1.Caption                       := '&' + XText[rsExit];

  // == Search Menu ==========================================================================

  miSearchMain.Caption                := XText[rsSearch];
  miSearchWizard.Caption              := XText[rsWizard] + rsEllipsis;

  // == View Menu ============================================================================

  miOpenLastReport.Caption            := XText[rsOpenLastReport];
  miCopyLastReportToClipboard.Caption := XText[rsCopyLastReportToClipboard];
  miReportOptions.Caption             := XText[rsReportOptions] + rsEllipsis;
  miReportBrowser.Caption             := XText[rsReportBrowser] + rsEllipsis;
  InformationSection1.Caption         := XText[rsFolderProperties];

  miTabTable.Caption                  := XText[rsCategories]; // to do hide/show these on popup menu if data available!"
  miTabTree.Caption                   := XText[rsType];
  miTabOther.Caption                  := XText[rsExtensions];
  miTabFolders.Caption                := XText[rsFolders];
  miTabMagnitude.Caption              := XText[rsMagnitude];
  miTabFileDates.Caption              := XText[rsDates];
  miTabHistory.Caption                := XText[rsHistory];
  miTabTop50.Caption                  := XText[rsTop101];
  miTabNullFiles.Caption              := XText[rsNull];
  miTabUsers.Caption                  := XText[rsUsers];
  miTabTemp.Caption                   := XText[rsTemp];
  miTabNameLength.Caption             := XText[rsFileNameLength];

  miShowSearchSyntax.Caption          := XText[rsSearchSyntax] + rsEllipsis;
  miShowCategoryColours.Caption       := XText[rsCategoryColours] + rsEllipsis;
  miViewLogFolder.Caption             := XText[rsLogs] + rsEllipsis;

  // == Reports ================================================================

  miNewReportSM.Caption               := XText[rsNew];
  miHTMLReport.Caption                := XText[rsHTMLReport];
  miXMLReport.Caption                 := XText[rsXMLReport];
  miCSVReport.Caption                 := XText[rsCSVReport];
  miTextReport.Caption                := XText[rsTextReport];
  miTreeReport.Caption                := XText[rsTreeReport];

  miMainReports.Caption               := XText[rsReport];
  miEditCSVReports.Caption            := XText[rsCustomise] + ' CSV ' + XText[rsReport];
  miEditHTMLReports.Caption           := XText[rsCustomise] + ' HTML ' + XText[rsReport];
  miEditTextReports.Caption           := XText[rsCustomise] + ' ' + XText[rsText] + ' ' + XText[rsReport];
  miEditTreeReports.Caption           := XText[rsCustomise] + ' ' + XText[rsTree] + ' ' + XText[rsReport];
  miEditXMLReports.Caption            := XText[rsCustomise] + ' XML ' + XText[rsReport];

  // == Detail ===============================================================================

  miDFileSize.Caption        := XText[rsFileSizeSpread] + rsEllipsis;
  miDDuplicatesName.Caption  := XText[rsDuplicatesFileName];
  miDDuplicatesSize.Caption  := XText[rsDuplicatesFileSize];
  miMoreFolderDetail.Caption := XText[rsFolderDetail] + rsEllipsis;
  miFileAges.Caption         := XText[rsFileAge] + rsEllipsis;

  // == Edit =================================================================================

  miPreferences.Caption                        := XText[rsSettings] + rsEllipsis;
  miFileAssociations.Caption                   := XText[rsFileTypes] + rsEllipsis;
  miCustomiseQuickFolderMenu.Caption           := XText[rsCustomiseQuickFolderMenu] + rsEllipsis;
  miFHInfo.Caption                             := XText[rsFolderHistoryInfo] + rsEllipsis;
  miBackupData.Caption                         := XText[rsBackupYourXinorbisData];
  miLanguage.Caption                           := XText[rsLanguage];
  miAddXinorbistoExplorerToContextMenu.Caption := XText[rsAddXinorbisToExplorerContextMenu];

  // == Help =================================================================================

  miTutorial.Caption         := XText[rsTutorial];
//  miDonate.Caption           := XText[rsPurchaseXinorbis];
  Help2.Caption              := XText[rsHelp];
  miContextHelp.Caption      := XText[rsContextHelp];
  miUserManual.Caption       := XText[rsUserManual];
  miReference.Caption        := XText[rsReference] + rsEllipsis;
  miXinorbisHome.Caption     := XText[rsXinorbisHome];
  miHelpSendFeedback.Caption := XText[rsReportBugFeature];
  Checkforupdate1.Caption    := XText[rsCheckForUpdates];
  About1.Caption             := XText[rsAbout];

  // =========================================================================================

  lWelcomeScan.Caption          := XText[rsScanDriveFolder];
  lWelcomeFolderHistory.Caption := XText[rsFolderHistory];

  lTaskID1.Caption              := XText[rsSummary];
  lTaskID2.Caption              := XText[rsFolderProperties];
  lTaskID3.Caption              := XText[rsFolderStructure];
  lTaskID4.Caption              := XText[rsSearch];
  lTaskID5.Caption              := XText[rsFolderMap];

  lTaskID6.Caption              := XText[rsDuplicatesFileName];
  lTaskID7.Caption              := XText[rsDuplicatesFileSize];

  lTaskID8.Caption              := XText[rsFolderExploder];

  lAdvID1.Caption               := XText[rsFileSizeSpread] + rsEllipsis;
  lAdvID2.Caption               := XText[rsFolderDetail] + rsEllipsis;
  lAdvID3.Caption               := XText[rsFileAge] + rsEllipsis;

  File1.Caption              := XText[rsFile];
  miEdit.Caption             := XText[rsEdit];
  Edit1.Caption              := XText[rsTools];
  miSearch.Caption           := XText[rsSearch];
  View1.Caption              := XText[rsView];
  Help1.Caption              := XText[rsHelp];
  miOpenCustomReport.Caption := XText[rsOpen] + rsEllipsis;
  miCustomReport.Caption     := XText[rsCustom] + rsEllipsis;
  miDetail.Caption           := XText[rsDetail];

  advSource.Text             := '<P align="center"><b>' + XText[rsWelcome] + '</b></P>';
  advViews.Text              := '<P align="center"><b>' + XText[rsView] + '</b></P>';

  // =========================================================================================

  tbNavigatePrevious.Hint := XText[rsHintM1];
  tbNavigateNext.Hint     := XText[rsHintM2];
  tbHome.Hint             := XText[rsHintM3];

  tbPrivacy.Hint          := XText[rsHintM4] + ' [' + XText[rsDisabled] + ']';
  tbToggleFH.Hint         := XText[rsHintM5] + ' [' + XText[rsEnabled] + ']';
  tbToggleVirtual.Hint    := XText[rsIgnoreVirtualFolders] + ' [' + XText[rsEnabled] + ']';

  // =========================================================================================

  tbReportSummary.Hint     := XText[rsSummary];
  tbReportCSV.Hint         := XText[rsCSVReport];
  tbReportHTML.Hint        := XText[rsHTMLReport];
  tbReportText.Hint        := XText[rsTextReport];
  tbReportTree.Hint        := XText[rsTreeReport];
  tbReportXML.Hint         := XText[rsXMLReport];
  tbReportPreferences.Hint := XText[rsReport] + ' ' + XText[rsSettings];
end;


procedure TfrmMain.OnNewReport;
begin
  UpdateMainMenu;
end;


procedure TfrmMain.OnJustInTime(aValue : integer);
begin
  FrameReports[FSource].JustInTimeDisplay(aValue);
end;


procedure TfrmMain.OnBuildInformationDisplay(aValue : integer);
begin
  case aValue of
    0 : TDisplayUtility.InformationTabFileDatesTree(FSource,
                                                    FrameReports[FSource].cbFileDates.ItemIndex, FrameReports[FSource].cbFileDatesUsers,
                                                    True, // or the display won't build!!
                                                    FrameReports[FSource].tvFileDates, FrameReports[FSource].vtcFileDates, True, Nil);
  end;
end;


procedure TfrmMain.OnStatusBarChange(const aText : string);
begin
  sbMain.Panels[0].Text := aText;
end;


procedure TfrmMain.OnReportsChange(const aNewTab : integer);
begin
  lTaskID1Click(lTaskID2);

  FrameReports[FSource].ActivePage := aNewTab;
end;


procedure TfrmMain.OnTutorialBarChange(const aText : string);
begin
  if XSettings.System.Tutorial then begin
    if Pos('\', aText) > 0 then begin
      if FileExists(aText) then
        lTutorial.HTMLText.LoadFromFile(aText)
      else
        lTutorial.HTMLText[0] := XText[rsMissingFile] + ': ' + aText;
    end
    else begin
      if FileExists(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
                    '\tutorial\' + aText + '.dat') then
        lTutorial.HTMLText.LoadFromFile(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
                                        '\tutorial\' + aText + '.dat')
      else
        lTutorial.HTMLText[0] := XText[rsMissingFile] + ': \tutorial\' + aText;
    end;
  end;
end;


procedure TfrmMain.OnResetDisplay(aStatus : integer);
begin
  if FrameMap.DataSource = dataFolderHistory then      // to do!  i think this should be source aware!
    FrameMap.ClearMap;
end;


procedure TfrmMain.OnMenuChange(const aNewText : string; aMenuItem, aState : integer);
begin
  case aMenuItem of
    0 : begin
          if aState = 0 then
            lTaskID4.Font.Color := clWindowText
          else
            lTaskID4.Font.Color := clGreen;

          if aNewText <> '' then
            lTaskID4.Caption := aNewText;
        end;
    1 : {};
    2 : {};
  end;
end;


procedure TfrmMain.OnOpenSettingsTab(const aNewTab : integer);
begin
  if DoFileTypePrefs(aNewTab) = mrOk then begin

    DoPreferenceChanges;

    FrameSelect.UpdateQuickFolders;

    FrameSearch.RebuildCharts;

    FrameFolderHistory.InitUpdate;
    FrameReports[dataLatestScan].InitUpdate;
    if Assigned(FrameReports[dataFolderHistory]) then
      FrameReports[ dataFolderHistory].InitUpdate;

    FrameSelect.BuildScanHistoryTable(0);

    // ===========================================================================

    XSettings.ProgressPercentage := ProgressUpdates[XSettings.Optimisations.ProgressUpdate, 1];
    XSettings.ProgressFileCount  := ProgressUpdates[XSettings.Optimisations.ProgressUpdate, 2];

    // ===========================================================================

    if XSettings.HistorySettings.Enabled then begin
      tbToggleFH.Enabled    := True;
      tbToggleFH.ImageIndex := 6;

      lWelcomeFolderHistory.Enabled  := True;

      XSettings.System.UserEnabledFH := True;
    end
    else begin
      tbToggleFH.Enabled    := False;
      tbToggleFH.ImageIndex := 5;

      lWelcomeFolderHistory.Enabled  := False;

      XSettings.System.UserEnabledFH := False;
    end;
  end;
end;


procedure TfrmMain.OnProcessWindowStatusChange(const aWindow, aStatus : integer);
begin
  case aStatus of
    CWindowAnalysisProgress : case aWindow of
                                CWindowAnalysisProgress : HideProcessWindow;
                                CWindowZipProgress      : HideZipProcessWindow;
                              end;
    CWindowZipProgress      : case aWindow of
                                CWindowAnalysisProgress : ShowProcessWindow;
                                CWindowZipProgress      : ShowZipProcessWindow;
                              end;
  end;
end;


procedure TfrmMain.OnFormClose(const aForm : integer);
begin
  case aForm of
    _FormFileSpread : lAdvID1.Font.Style := [];
    _FormExplore    : lAdvID2.Font.Style := [];
  end;
end;


procedure TfrmMain.OnExtSetSidePanelDisplay(welcomeID, taskID, tasksubID, canAddToHistory : integer);
begin
  SetSidePanelDisplay(welcomeID, taskID, tasksubID, canAddToHistory);
end;


procedure TfrmMain.OnProcessWindowProgressChange(const aProgress : integer);
begin
  SetProcessBar(aProgress);
end;


procedure TfrmMain.OnUpdateHistoryFinished;
begin
  if not Assigned(FrameNavigation[dataFolderHistory]) then
    CreateNavigationFrame(dataFolderHistory);

  BuildSummary(dataFolderHistory, 0);

  // ===========================================================================

  UpdateLeftPanelStatus;
end;


procedure TfrmMain.OnChartsHaveChanged;
begin
  FrameReports[dataLatestScan].InitUpdate;
  FrameNavigation[dataLatestScan].InitUpdate;

  if Assigned(FrameReports[dataFolderHistory]) then
    FrameReports[dataFolderHistory].InitUpdate;

  if Assigned(FrameNavigation[dataFolderHistory]) then
    FrameNavigation[dataFolderHistory].InitUpdate;

  FrameFolderHistory.InitUpdate;
end;


procedure TfrmMain.OnOpenSearchWizard(const aStatus : integer);
begin
  miSearchWizardClick(Nil);
end;


procedure TfrmMain.CreateFrames;
begin
  CreateSummaryFrame(dataLatestScan);
  CreateNavigationFrame(dataLatestScan);
  CreateReportsFrame(dataLatestScan);

  FrameSelect  := TFrameSelect.Create(Self);
  FrameSelect.Parent           := Panel2;
  FrameSelect.Align            := alClient;
  FrameSelect.GetLeftOffset    := OnGetLeftOffset;
  FrameSelect.GetTopOffset     := OnGetTopOffset;
  FrameSelect.OnChangeFHPath   := RequestNewFHPath;
  FrameSelect.OnNewScan        := RequestNewScan;
  FrameSelect.OnNewCombineScan := RequestNewCombineScan;
  FrameSelect.Init;

  CreateSearchFrame;

  FrameWebReports  := TFrameWebReports.Create(Self);
  FrameWebReports.Parent  := Panel2;
  FrameWebReports.Visible := False;

  FrameFolderHistory := TFrameFolderHistory.Create(Self);
  FrameFolderHistory.Parent  := Panel2;
  FrameFolderHistory.Visible := False;
  FrameFolderHistory.Init;
  FrameFolderHistory.GetLeftOffset                 := OnGetLeftOffset;
  FrameFolderHistory.GetTopOffset                  := OnGetTopOffset;
  FrameFolderHistory.IsFHUpdateThreadRunning       := IsFolderHistoryRunning;
  FrameFolderHistory.OnExtSetSidePanelDisplay      := OnExtSetSidePanelDisplay;
  FrameFolderHistory.OnOpenSearchWizard            := OnOpenSearchWizard;
  FrameFolderHistory.OnProcessWindowProgressChange := OnProcessWindowProgressChange;
  FrameFolderHistory.OnProcessWindowStatusChange   := OnProcessWindowStatusChange;
  FrameFolderHistory.OnSetStatusBarText            := OnStatusBarChange;
  FrameFolderHistory.OnSetTutorialBarText          := OnTutorialBarChange;
  FrameFolderHistory.OnResetDisplay                := OnResetDisplay;
  FrameFolderHistory.OnScanFromFolderHistory       := ScanFromFolderHistory;
  FrameFolderHistory.OnUpdateHistoryFinished       := OnUpdateHistoryFinished;
  FrameFolderHistory.OnChartsHaveChanged           := OnChartsHaveChanged;

  FrameMap := TFrameMap.Create(Self);
  FrameMap.Parent  := Panel2;
  FrameMap.Visible := False;
  FrameMap.Init;

  FrameExploder := TFrameExploder.Create(Self);
  FrameExploder.Parent  := Panel2;
  FrameExploder.Visible := False;
  FrameExploder.Init;
end;


procedure TfrmMain.CreateSummaryFrame(aDataIndex : integer);
begin
  FrameSummary[aDataIndex] := TFrameSummary.Create(Self);
  FrameSummary[aDataIndex].Name               := 'FrameSummary' + IntToStr(aDataIndex);
  FrameSummary[aDataIndex].Parent             := Panel2;
  FrameSummary[aDataIndex].Source             := aDataIndex;
  FrameSummary[aDataIndex].Visible            := False;
  FrameSummary[aDataIndex].Init;
  FrameSummary[aDataIndex].OnReportsChange    := OnReportsChange;
  FrameSummary[aDataIndex].OnSetStatusBarText := OnStatusBarChange;
end;


procedure TfrmMain.CreateNavigationFrame(aDataIndex : integer);
begin
  FrameNavigation[aDataIndex]  := TFrameNavigation.Create(Self);
  FrameNavigation[aDataIndex].Name          := 'FrameNavigation' + IntToStr(aDataIndex);
  FrameNavigation[aDataIndex].Parent        := Panel2;
  FrameNavigation[aDataIndex].Source        := aDataIndex;
  FrameNavigation[aDataIndex].GetLeftOffset := OnGetLeftOffset;
  FrameNavigation[aDataIndex].GetTopOffset  := OnGetTopOffset;
  FrameNavigation[aDataIndex].OnProcessWindowStatusChange   := OnProcessWindowStatusChange;
  FrameNavigation[aDataIndex].Init;
  FrameNavigation[aDataIndex].Visible       := False;
end;


procedure TfrmMain.CreateReportsFrame(aDataIndex : integer);
begin
  FrameReports[aDataIndex] := TFrameReports.Create(Self);
  FrameReports[aDataIndex].Name                        := 'FrameReports' + IntToStr(aDataIndex);
  FrameReports[aDataIndex].Parent                      := Panel2;
  FrameReports[aDataIndex].Source                      := aDataIndex;
  FrameReports[aDataIndex].Init;
  FrameReports[aDataIndex].Visible                     := False;
  FrameReports[aDataIndex].GetLeftOffset               := OnGetLeftOffset;
  FrameReports[aDataIndex].GetTopOffset                := OnGetTopOffset;
  FrameReports[aDataIndex].IsFHUpdateThreadRunning     := IsFolderHistoryRunning;
  FrameReports[aDataIndex].OnNewScan                   := RequestNewScan;
  FrameReports[aDataIndex].OnNewSearch                 := RequestNewSearch;
  FrameReports[aDataIndex].OnNewSummary                := RequestNewSummary;
  FrameReports[aDataIndex].OnProcessWindowStatusChange := OnProcessWindowStatusChange;
  FrameReports[aDataIndex].OnSetStatusBarText          := OnStatusBarChange;
  FrameReports[aDataIndex].OnSettingsTab               := OnOpenSettingsTab;
  FrameReports[aDataIndex].OnSetTutorialBarText        := OnTutorialBarChange;

  GReportText.SetGrids(aDataIndex, FrameReports[aDataIndex].sgNullFiles,
                                   FrameReports[aDataIndex].sgNullFolders,
                                   FrameReports[aDataIndex].sgTop50Big,
                                   FrameReports[aDataIndex].sgTop50Small,
                                   FrameReports[aDataIndex].sgTop101BigDate,
                                   FrameReports[aDataIndex].sgTop101SmallDate);

  GReportXML.SetGrids(aDataIndex,  FrameReports[aDataIndex].tvFileDates,
                                   FrameReports[aDataIndex].sgNullFiles,  FrameReports[aDataIndex].sgNullFolders,    FrameReports[aDataIndex].sgTop50Big,
                                   FrameReports[aDataIndex].sgTop50Small, FrameReports[aDataIndex].sgTop101BigDate,  FrameReports[aDataIndex].sgTop101SmallDate,
                                   FrameReports[aDataIndex].cbFileDates,  FrameReports[aDataIndex].cbFileDatesUsers, FrameReports[aDataIndex].cbTop101Dates);


  GReportHTML.SetGrids(aDataIndex, FrameReports[aDataIndex].tvFileDates,
                                   FrameReports[aDataIndex].sgNullFiles,  FrameReports[aDataIndex].sgNullFolders,    FrameReports[aDataIndex].sgTop50Big,
                                   FrameReports[aDataIndex].sgTop50Small, FrameReports[aDataIndex].sgTop101BigDate,  FrameReports[aDataIndex].sgTop101SmallDate,
                                   FrameReports[aDataIndex].cbFileDates,  FrameReports[aDataIndex].cbTop101Dates);


  GReportSummary.SetGrids(aDataIndex, FrameReports[aDataIndex].sgNullFiles,
                                      FrameReports[aDataIndex].sgNullFolders,
                                      FrameReports[aDataIndex].sgDirList,
                                      FrameReports[aDataIndex].sgTop50Big,
                                      FrameReports[aDataIndex].sgUsers);

  UpdateGUICustomNames(aDataIndex);
end;


procedure TfrmMain.CreateSearchFrame;
begin
  FrameSearch  := TFrameSearch.Create(Self);
  FrameSearch.Parent             := Panel2;
  FrameSearch.Visible            := False;
  FrameSearch.Init;
  FrameSearch.GetLeftOffset      := OnGetLeftOffset;
  FrameSearch.GetTopOffset       := OnGetTopOffset;
  FrameSearch.OnMenuChange       := OnMenuChange;
  FrameSearch.OnOpenSearchWizard := OnOpenSearchWizard;


  GReportText.SetGrids(dataSearch, FrameSearch.ReportFrame.sgNullFiles,
                                   FrameSearch.ReportFrame.sgNullFolders,
                                   FrameSearch.ReportFrame.sgTop50Big,
                                   FrameSearch.ReportFrame.sgTop50Small,
                                   FrameSearch.ReportFrame.sgTop101BigDate,
                                   FrameSearch.ReportFrame.sgTop101SmallDate);

  GReportXML.SetGrids(dataSearch,  FrameSearch.ReportFrame.tvFileDates,
                                   FrameSearch.ReportFrame.sgNullFiles,  FrameSearch.ReportFrame.sgNullFolders,    FrameSearch.ReportFrame.sgTop50Big,
                                   FrameSearch.ReportFrame.sgTop50Small, FrameSearch.ReportFrame.sgTop101BigDate,  FrameSearch.ReportFrame.sgTop101SmallDate,
                                   FrameSearch.ReportFrame.cbFileDates,  FrameSearch.ReportFrame.cbFileDatesUsers, FrameSearch.ReportFrame.cbTop101Dates);


  GReportHTML.SetGrids(dataSearch, FrameSearch.ReportFrame.tvFileDates,
                                   FrameSearch.ReportFrame.sgNullFiles,  FrameSearch.ReportFrame.sgNullFolders,    FrameSearch.ReportFrame.sgTop50Big,
                                   FrameSearch.ReportFrame.sgTop50Small, FrameSearch.ReportFrame.sgTop101BigDate,  FrameSearch.ReportFrame.sgTop101SmallDate,
                                   FrameSearch.ReportFrame.cbFileDates,  FrameSearch.ReportFrame.cbTop101Dates);


  GReportSummary.SetGrids(dataSearch, FrameSearch.ReportFrame.sgNullFiles,
                                      FrameSearch.ReportFrame.sgNullFolders,
                                      FrameSearch.ReportFrame.sgDirList,
                                      FrameSearch.ReportFrame.sgTop50Big,
                                      FrameSearch.ReportFrame.sgUsers);
end;


procedure TfrmMain.DestroyFrames;
begin
  FrameSummary[dataLatestScan].Free;

  if Assigned(FrameSummary[dataFolderHistory]) then
    FrameSummary[dataFolderHistory].Free;

  // ===========================================================================

  FrameNavigation[dataLatestScan].DeInit;
  FrameNavigation[dataLatestScan].Free;

  // ===========================================================================

  FrameSelect.Free;

  // ===========================================================================

  FrameSearch.DeInit;
  FrameSearch.Free;

  // ===========================================================================

  FrameWebReports.Free;

  FrameMap.DeInit;
  FrameMap.Free;

  FrameExploder.DeInit;
  FrameExploder.Free;

  FrameFolderHistory.DeInit;
  FreeAndNil(FrameFolderHistory);

  FreeAndNil(FrameReports);
end;


// =============================================================================


procedure TfrmMain.TryBuildFolderHistoryAvailable;
begin
  if (XSettings.HistorySettings.Enabled) and (XSettings.System.UserEnabledFH) then begin
    FrameFolderHistory.BuildFolderHistoryAvailable;
  end
  else begin
    lWelcomeFolderHistory.Enabled := False;
    lWelcomeFolderHistory.Hint    := 'Disabled, enable through Settings->General';
  end;
end;


procedure TfrmMain.CreateObjects;
var
  lScanDetails : TScanDetails;

begin
  // == file scanner ===========================================================
  GXinorbisScan := TXinorbisScan.Create(0);
  GXinorbisScan.OnFoundNull := ScanOnFoundNull;
  GXinorbisScan.OnFoundTemp := ScanOnFoundTemp;
  GXinorbisScan.OnScanCount := ScanOnProgress;

  // ===========================================================================

  GScanDetails := TObjectList<TScanDetails>.Create;

  lScanDetails := TScanDetails.Create;
  GScanDetails.Add(lScanDetails);

  lScanDetails := TScanDetails.Create;
  GScanDetails.Add(lScanDetails);

  lScanDetails := TScanDetails.Create;
  GScanDetails.Add(lScanDetails);

  FileExtensionsObject := TFileExtensionsObject.Create;

  // ===========================================================================

  NetworkDrivesList            := TStringList.Create;

  FolderHistory                := TObjectList<TFolderHistoryObject>.Create;
  FolderHistoryAvailable       := TObjectList<TFolderHistoryInfo>.Create;

  ScanHistory                  := TObjectList<TScanHistoryObject>.Create;

  MenuStrings                  := TStringList.Create;

  NavigationHistory            := TStringList.Create;
  NavigationHistory.Add('H0');

  HGraphData                   := TStringList.Create;
  FHGraphData                  := TStringList.Create;
end;


procedure TfrmMain.CreateReportObjects;
begin
  GReportUtility := TReportUtility.Create;
  GReportUtility.ReportListFileName := GSystemGlobal.AppDataPath + 'Reports\reportlist.dat';
  GReportUtility.OnNewReport        := OnNewReport;

  GReportCSV      := TCSVReport.Create;
  GReportCSV.OnJustInTime       := OnJustInTime;
  GReportCSV.OnMenuChange       := OnMenuChange;
  GReportCSV.OnSetStatusBarText := OnStatusBarChange;

  GReportHTML     := THTMLReport.Create;
  GReportHTML.Chart1                    := vtcHTML;
  GReportHTML.Chart2                    := vtcHTML2;
  GReportHTML.OnJustInTime              := OnJustInTime;
  GReportHTML.OnBuildInformationDisplay := OnBuildInformationDisplay;
  GReportHTML.OnSetStatusBarText        := OnStatusBarChange;

  GReportText     := TTextReport.Create;
  GReportText.OnJustInTime       := OnJustInTime;
  GReportText.OnSetStatusBarText := OnStatusBarChange;

  GReportTree     := TTreeReport.Create;
  GReportTree.OnSetStatusBarText := OnStatusBarChange;

  GReportXinorbis := TXinorbisReport.Create;
  GReportXinorbis.OnJustInTime       := OnJustInTime;
  GReportXinorbis.OnSetStatusBarText := OnStatusBarChange;

  GReportXML      := TXMLReport.Create;
  GReportXML.OnJustInTime       := OnJustInTime;
  GReportXML.OnSetStatusBarText := OnStatusBarChange;

  GReportSummary := TSummaryReports.Create;
  GReportSummary.OnSetStatusBarText := OnStatusBarChange;
end;


procedure TfrmMain.DestroyReports;
begin
  FreeAndNil(GReportXML);
  FreeAndNil(GReportXinorbis);
  FreeAndNil(GReportTree);
  FreeAndNil(GReportText);
  FreeAndNil(GReportSummary);
  FreeAndNil(GReportHTML);
  FreeAndNil(GReportCSV);

  FreeAndNil(GReportUtility);
end;


procedure TfrmMain.miCustomiseQuickFolderMenuClick(Sender: TObject);
begin
  ShowQuickMenuBuilder;
end;


procedure TfrmMain.ConfigureObjects;
begin
  WelcomeOptions[1] := lWelcomeScan; WelcomeOptions[2] := lWelcomeFolderHistory;

  TaskOptions[1] := lTaskID1; TaskOptions[2] := lTaskID2; TaskOptions[3] := lTaskID3;
  TaskOptions[4] := lTaskID4; TaskOptions[5] := lTaskID5; TaskOptions[6] := lTaskID6;
  TaskOptions[7] := lTaskID7; TaskOptions[8] := lTaskID8;

  AdvancedOptions[1] := lAdvID1; AdvancedOptions[2]:= lAdvID2; AdvancedOptions[3] := lAdvID3;

  LanguageMenus[0]  := miLang1;  LanguageMenus[1]  := miLang2;  LanguageMenus[2] := miLang3;
  LanguageMenus[3]  := miLang4;  LanguageMenus[4]  := miLang5;  LanguageMenus[5] := miLang6;
  LanguageMenus[6]  := miLang7;  LanguageMenus[7]  := miLang8;  LanguageMenus[8] := miLang9;
  LanguageMenus[9]  := miLang10; LanguageMenus[10] := miLang11; LanguageMenus[11]:= miLang12;
  LanguageMenus[12] := miLang13;
end;


procedure TfrmMain.HandleResizing(NewPanelInFront : integer);
begin
  if (FormDisplay.PanelInFront <> NewPanelInFront) or
     (FormDisplay.Source       <> FSource) then begin
    case FormDisplay.PanelInFront of
      pMainPanelIndex            : begin
                                     //pMain.Visible := False;
                                     //pMain.Align   := alNone;
                                   end;
      pScanSelectionPanelIndex   : begin
                                     FrameSelect.Visible := False;
                                     FrameSelect.Align   := alNone;
                                   end;
      pMainSummaryPanelIndex     : begin
                                     FrameSummary[FormDisplay.Source].Visible := False;
                                     FrameSummary[FormDisplay.Source].Align   := alNone;
                                   end;
      pMainReportsPanelIndex     : begin
                                     FrameReports[FormDisplay.Source].Visible := False;
                                     FrameReports[FormDisplay.Source].Align   := alNone;

                                     //FrameReports.pMainReportsResize(Nil);
                                   end;
      pMainNavigationPanelIndex  : begin
                                     FrameNavigation[FormDisplay.Source].Visible := False;
                                     FrameNavigation[FormDisplay.Source].Align   := alNone;

                                     FrameNavigation[FormDisplay.Source].Panel25Resize(nil);
                                     FrameNavigation[FormDisplay.Source].Panel26Resize(nil);

                                   end;
      pMainSearchPanelIndex      : begin
                                     FrameSearch.Visible := False;
                                     FrameSearch.Align   := alNone;
                                   end;
      pMainFileHistoryPanelIndex : begin
                                     FrameFolderHistory.Visible := False;
                                     FrameFolderHistory.Align   := alNone;
                                   end;
      pMainWebReportsPanelIndex  : begin
                                     FrameWebReports.Visible := False;
                                     FrameWebReports.Align   := alNone;
                                   end;
      pMainMapPanelIndex         : begin
                                     FrameMap.Visible := False;
                                     FrameMap.Align   := alNone;
                                   end;
      pMainExploderPanelIndex    : begin
                                     FrameExploder.Visible := False;
                                     FrameExploder.Align   := alNone;
                                   end;
      end;
    end;

    FormDisplay.PanelInFront := NewPanelInFront;
    FormDisplay.Source       := FSource;

    case NewPanelInFront of
      pMainPanelIndex            : begin
                                     //pMain.Visible := True;
                                     //pMain.Align   := alClient;
                                   end;
      pScanSelectionPanelIndex   : begin
                                     FrameSelect.Visible := True;
                                     FrameSelect.Align   := alClient;

                                     FrameSelect.pScanSelectionResize(Nil);
                                   end;
      pMainSummaryPanelIndex     : begin
                                     FrameSummary[FSource].Align   := alClient;
                                     FrameSummary[FSource].Visible := True;
                                   end;
      pMainReportsPanelIndex     : begin
                                     FrameReports[FSource].Visible := True;
                                     FrameReports[FSource].Align   := alClient;

                                     FrameReports[FSource].pMainReportsResize(Nil);
                                   end;
      pMainNavigationPanelIndex  : begin
                                     FrameNavigation[FSource].Visible := True;
                                     FrameNavigation[FSource].Align   := alClient;

                                     FrameNavigation[FSource].Panel25Resize(nil);
                                     FrameNavigation[FSource].Panel26Resize(nil);
                                   end;
      pMainSearchPanelIndex      : begin
                                     FrameSearch.Visible := True;
                                     FrameSearch.Align   := alClient;
                                     FrameSearch.FrameResize(Nil);
                                   end;
      pMainFileHistoryPanelIndex : begin
                                     FrameFolderHistory.Visible := True;
                                     FrameFolderHistory.Align   := alClient;

                                     FrameFolderHistory.tpFHStatsResize(Nil);
                                   end;
      pMainWebReportsPanelIndex  : begin
                                     FrameWebReports.Visible := True;
                                     FrameWebReports.Align   := alClient;
                                   end;
      pMainMapPanelIndex         : begin
                                     FrameMap.Visible := True;
                                     FrameMap.Align   := alClient;
                                    end;
      pMainExploderPanelIndex    : begin
                                     FrameExploder.Visible := True;
                                     FrameExploder.Align   := alClient;
                                   end;
  end;
end;


procedure TfrmMain.Help2Click(Sender: TObject);
begin
  THelp.OpenHelpPage('index.htm');
end;


procedure TfrmMain.ClearAllData;
 begin
  Screen.Cursor := crDefault;
end;


procedure TfrmMain.ConfigureFindFile(aScanPath : string; aTag : integer);
var
  t : integer;

begin
  GXinorbisScan.ClearFilters;

  if GSystemGlobal.ExcludedFolders.Count <> 0 then begin
    for t := 0 to GSystemGlobal.ExcludedFolders.Count - 1 do
      GXinorbisScan.AddExcludedFolder(GSystemGlobal.ExcludedFolders[t]);
  end;

  if GSystemGlobal.ExcludedFiles.Count <> 0 then begin
    for t:= 0 to GSystemGlobal.ExcludedFiles.Count - 1 do
      GXinorbisScan.AddExcludedFile(GSystemGlobal.ExcludedFiles[t]);
  end;

  GXinorbisScan.SetExcludeModes(GSystemGlobal.ExcludeVirtual);

  GXinorbisScan.Tag := aTag;

  GXinorbisScan.SetScanFolder(aScanPath);
end;


function TfrmMain.DoScanModeNormal(aDataIndex : integer; aScanPath : string): string;
var
  ts : string;
  nwid : integer;
  tempchar : char;

begin
  XSettings.Forms.ProgressForm.SetProcessText(XText[rsScanningFolder] + rsEllipsis);
  XSettings.Forms.ProgressForm.SetProcessIcon(1);
  XSettings.LastScanMultiple := False;
  GXinorbisScan.SizeOfCurrentScanFolder    := 1;

  ts        := aScanPath;
  ts[1]     := UpCase(ts[1]);
  aScanPath := ts;

  GScanDetails[aDataIndex].ScanPath := aScanPath;
  FrameSelect.ePath.Text            := aScanPath;

  if aDataIndex = dataLatestScan then begin
    tempchar := GScanDetails[aDataIndex].ScanPath[1];

    GSystemGlobal.drivespacemax  := DiskSize(Ord(tempchar) - 64);
    GSystemGlobal.drivespacefree := DiskFree(Ord(tempchar) - 64);
  end
  else begin
    //tempchar := 'C';

    GSystemGlobal.drivespacemax  := -1;
    GSystemGlobal.drivespacefree := -1;
  end;

  nwid := TXWindows.IsThisNetworkDrive(aScanPath);

  if nwid <> -1 then begin
    FrameSelect.ePath.Text := TXWindows.ConvertPathToNetwork(aScanPath, nwid);

    aScanPath := FrameSelect.ePath.Text;
    GScanDetails[aDataIndex].ScanPath := aScanPath;
  end;

  GScanDetails[aDataIndex].ScanMD5 := TMD5.Generate(UpperCase(aScanPath));

  // =====================================================================

  ConfigureFindFile(aScanPath, 1);

  GXinorbisScan.Scan;

  // =====================================================================

  Result := aScanPath;
end;


procedure TfrmMain.XinorbisScan(aDataIndex : integer; ScanPath : string; const fromfile : string; ScanType, ScanSource : integer);
begin
  if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
    ShowXDialog(XText[rsWarning], XText[rsPleaseWaitFolderHistory], XDialogTypeXinorbis);

    Exit;
  end;

  // =======================================================================================================

  GScanDetails[aDataIndex].ScanType   := ScanType;
  GScanDetails[aDataIndex].ScanSource := ScanSource;
  GScanDetails[aDataIndex].ScanPath   := ScanPath;
  GScanDetails[aDataIndex].InProgress := True;

  // =======================================================================================================

  XinorbisScanPre(aDataIndex, fromfile);

  // =======================================================================================================

  XinorbisScanExecute(aDataIndex);

  // =======================================================================================================

  XinorbisScanAnalysis(aDataIndex);

  // =======================================================================================================

  XinorbisScanBuild(aDataIndex);

  // =======================================================================================================

  XinorbisScanReportsAndFH(aDataIndex);

  // =======================================================================================================

  XinorbisScanPost(aDataIndex);

  // =======================================================================================================

  GScanDetails[aDataIndex].InProgress := False;
end;


procedure TfrmMain.XinorbisScanPre(aDataIndex : integer; const aFromFile : string);
var
  t : integer;

begin
  if Not(Assigned(FrameReports[aDataIndex])) then
    CreateReportsFrame(aDataIndex);

  if not Assigned(FrameSummary[aDataIndex]) then
    CreateSummaryFrame(aDataIndex);

  // ===========================================================================

  GScanDetails[aDataIndex].FromFile  := False;
  GScanDetails[aDataIndex].Filename  := aFromFile;
  GScanDetails[aDataIndex].ScanTable := aFromFile;

  if GScanDetails[aDataIndex].ScanPath <> '' then begin
    if GScanDetails[aDataIndex].ScanSource <> ScanSourceFolderHistory  then begin
      if GScanDetails[aDataIndex].ScanPath = '\' then
        GScanDetails[aDataIndex].ScanSource := ScanSourceLiveShare
      else
        GScanDetails[aDataIndex].ScanSource := ScanSourceLive;
    end;
  end;

  GScanDetails[aDataIndex].InitNow;

  Screen.Cursor  := crHourGlass;

  ToggleSoftwareStatus(aDataIndex, False);
  ShowProcessWindow;

  // ===========================================================================

  if GScanDetails[aDataIndex].ScanType = ScanTypeRefresh then begin
    TPreScan.PurgeAllDataRefresh(aDATAINDEX, FrameReports[aDataIndex].sgNullFiles,
                                             FrameReports[aDataIndex].sgNullFolders,
                                             FrameSearch.sgSearchResults);
  end
  else
    TPreScan.PurgeAllData(aDATAINDEX, FrameReports[aDataIndex].sgNullFiles,
                                      FrameReports[aDataIndex].sgNullFolders,
                                      FrameSearch.sgSearchResults);

  // ======================================================================================================

  for t := 0 to JustInTimeCount do begin
    if XSettings.Optimisations.JustInTimeDisplay then
      XSettings.System.JustInTimeProcessed[aDataIndex, t] := False
    else
      XSettings.System.JustInTimeProcessed[aDataIndex, t] := True;
  end;

  FrameMap.ClearMap;
  // to do clear frameexploder

  FrameReports[aDataIndex].PreScan;
end;

// aScanMode = ScanModeNormal : aScanpath is folder to scan
procedure TfrmMain.XinorbisScanExecute(aDataIndex : integer);
begin
  if (GXinorbisScan.StopScan) then Exit;

  SetProcessBar(1);

  // =======================================================================
  // -- Choose the data source ---------------------------------------------
  // =======================================================================
  case GScanDetails[aDataIndex].ScanType of
    ScanTypeNormal  : begin
                        if GScanDetails[aDataIndex].ScanPath <> '' then begin
                          case GScanDetails[aDataIndex].ScanSource of
                            ScanSourceFolderHistory : begin
                                                        PopulateXinFilesFromTable(GScanDetails[aDataIndex].ScanTable);              // db table name to use for data

                                                        GXinorbisScan.PrepareForFolderHistory;
                                                      end;
                          else
                            GScanDetails[aDataIndex].ScanPath := DoScanModeNormal(aDataIndex, GScanDetails[aDataIndex].ScanPath); // direct scan of ascanpath
                          end;
                        end
                        else begin                                 // From report
                          GScanDetails[aDataIndex].FromFile := True;

                          case GScanDetails[aDataIndex].ScanSource of
                            ScanSourceFileXinDetailed  : BuildXinFilesFromReport(GScanDetails[aDataIndex].Filename);
                            ScanSourceFileXin2Detailed : BuildXin2FilesFromReport(GScanDetails[aDataIndex].Filename);
                          else
                            showmessage('ERROR UNKNOWN SCAN SOURCE!!');
                          end;
                        end;

                        GXinorbisScan.DataIndex := aDataIndex;
                        GXinorbisScan.Analyse;

                        GScanDetails[aDataIndex].TotalSize   := GXinorbisScan.FileTotalSpace;
                        GScanDetails[aDataIndex].TotalSizeOD := GXinorbisScan.FileOnDisk;
                        GScanDetails[aDataIndex].FileCount   := GXinorbisScan.FileCount;
                        GScanDetails[aDataIndex].FolderCount := GXinorbisScan.FolderCount;

                        NewSourceAvailable(aDataIndex);
                      end;
    ScanTypeRefresh : begin
                        GXinorbisScan.DataIndex := aDataIndex;
                        GXinorbisScan.Clear;
                        GXinorbisScan.Analyse;

                        GScanDetails[aDataIndex].TotalSize   := GXinorbisScan.FileTotalSpace;
                        GScanDetails[aDataIndex].TotalSizeOD := GXinorbisScan.FileOnDisk;
                        GScanDetails[aDataIndex].FileCount   := GXinorbisScan.FileCount;
                        GScanDetails[aDataIndex].FolderCount := GXinorbisScan.FolderCount;
                      end;
  end;
end;


procedure TfrmMain.XinorbisScanAnalysis(aDataIndex : integer);
begin
  if (GXinorbisScan.StopScan) then Exit;

  XSettings.Forms.ProgressForm.SetProcessIcon(2);
//    BuildRootListFromXinFiles(1);

  XSettings.Forms.ProgressForm.SetProcessText(XText[rsAnalysingData] + rsEllipsis);

  GXinorbisScan.AnalyseData(True);

  FrameReports[aDataIndex].PostScan;
end;


procedure TfrmMain.XinorbisScanBuild(aDataIndex : integer);
begin
  if (GXinorbisScan.StopScan) then Exit;

  SetProcessBar(5);

  XSettings.Forms.ProgressForm.SetProcessIcon(3);

  // =====================================================================

  BuildDisplay(aDataIndex);

  // =====================================================================

  if (GScanDetails[aDataIndex].ScanSource <> ScanSourceFolderHistory) and
     (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXinDetailed) and
     (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXin2Detailed) then begin

    if GScanDetails[aDataIndex].ScanType = ScanTypeNormal then begin
      if (XSettings.HistorySettings.Enabled) and (XSettings.System.UserEnabledFH) then begin
        XSettings.Forms.ProgressForm.SetProcessIcon(4);
        XSettings.Forms.ProgressForm.SetProcessText(XText[rsUpdatingFolderHistory] + rsEllipsis);

        if not(GScanDetails[aDataIndex].FromFile) then begin
          ProcessUpdateFolderHistoryFile;
        end;
      end;
    end;
  end;

  // =====================================================================

  BuildSummary(aDataIndex, 0);

  FrameReports[aDataIndex].RefreshGraph(nil);
end;


procedure TfrmMain.XinorbisScanReportsAndFH(aDataIndex : integer);
begin
  if not(GXinorbisScan.StopScan) then begin
    XSettings.Forms.ProgressForm.SetProcessIcon(5);

    if (GScanDetails[aDataIndex].ScanSource <> ScanSourceFolderHistory) and
       (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXinDetailed) and
       (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXin2Detailed) then begin

      if XSettings.Report.autosavemode then begin
        XSettings.Forms.ProgressForm.SetProcessText(XText[rsSavingReports] + rsEllipsis);

        AutoSaveReports(aDataIndex);
      end;

      // ---------------------------------------------------------------------
      // -- set the history toolbar to show the newly scanned path -----------
      // ---------------------------------------------------------------------

      if FrameFolderHistory.GetAvailablePathContains(FrameSelect.ePath.Text) then
        TryBuildFolderHistoryAvailable;

      FrameFolderHistory.SetSelectedPathWithoutExecute(FrameSelect.ePath.Text);
    end;
  end
  else begin
    ClearAllData;
  end;
end;


procedure TfrmMain.XinorbisScanPost(aDataIndex : integer);
begin
  ToggleSoftwareStatus(aDataIndex, True);

  HideProcessWindow;

  Screen.Cursor := crDefault;

  // == only add if directory ================================================

  if not(GXinorbisScan.StopScan) then begin
    if (GScanDetails[aDataIndex].ScanSource <> ScanSourceFolderHistory) and
       (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXinDetailed) and
       (GScanDetails[aDataIndex].ScanSource <> ScanSourceFileXin2Detailed) then begin
      if length(GScanDetails[aDataIndex].ScanPath) >= 3 then begin
        AddToScanHistory(GScanDetails[aDataIndex].ScanPath, TConvert.DateToYYYYMMDDI(Now), TConvert.TimeToString(Now, True),
                         TUtility.ExcludedFilesToString, TUtility.ExcludedFoldersToString);

        FrameSelect.BuildScanHistoryTable(0);
      end;
    end;

    case XSettings.General.PostScanMode of
      CPostScanNothing     : {}; // do nothing
      CPostScanSummary     : lTaskID1Click(lTaskID1);
      CPostScanInformation : begin
                               lTaskID1Click(lTaskID2);

                               FrameReports[aDataIndex].ActivePage := XSettings.General.PostScanIPPage;
                             end;
      CPostScanStructure   : lTaskID1Click(lTaskID3);
    end;

    if (GScanDetails[aDataIndex].FileAttributes[FileType_RecallOnOpen, 0] <> 0) or
       (GScanDetails[aDataIndex].FileAttributes[FileType_RecallOnDataAccess, 0] <> 0) or
       (GScanDetails[aDataIndex].FileAttributes[FileType_Offline, 0] <> 0) then begin
      tbPostScanWarning.Visible := True;
      tbPostScanWarning.Hint    := XText[rsReportContainsVirtualFiles];
    end
    else
      tbPostScanWarning.Visible := False;
  end
  else begin
    tbPostScanWarning.Visible := True;
    tbPostScanWarning.Hint    := XText[rsScanStoppedBeforeComplete];
  end;

  // ===========================================================================

  if not(GXinorbisScan.StopScan) then begin
    FrameReports[aDataIndex].pMainReportsChange(Nil);

    FrameSummary[aDataIndex].lSProcessTime.Caption := XText[rsProcessedIn] + ' ' + TUtility.TimeElapsed(Now - GScanDetails[aDataIndex].TimeStarted);

    GXinorbisScan.StopScan := False;
  end
  else
    IfScanCancelled(aDataIndex);

  UpdateMainMenu;

  case GScanDetails[aDataIndex].ScanSource of
    ScanSourceLive,
    ScanSourceLiveShare        : TMSLogger.Info('Scan of "' + FrameSelect.ePath.Text + '" finished');
    ScanSourceFileXinNormal,
    ScanSourceFileCSV,
    ScanSourceFileXinDetailed,
    ScanSourceFileXin2Detailed : TMSLogger.Info('Import of "' + GScanDetails[aDataIndex].Filename + '" finished');
    ScanSourceFolderHistory    : TMSLogger.Info('Loaded from Folder History table "' + GScanDetails[aDataIndex].ScanTable + '".');
    ScanSourceSearchResults    : {};
  end;
end;


procedure TfrmMain.CombineScan;   // use FSouce when reactivating code
//var
//  t : integer;

begin
{  ScanMultiple := DoCombine;

  if ScanMultiple.Count <> 0 then begin
    XSettings.LastScanMultiple := True;

   GScanDetails[dataLatestScan].TimeStarted := Now;

    Screen.Cursor := crHourGlass;
    //ToggleSoftwareStatus(False);

    // =========================================================================
    GScanDetails[dataLatestScan].Users.Clear;
    GScanDetails[dataLatestScan].Files.Clear;
    GScanDetails[dataLatestScan].Folders.Clear;
    //ClearStringGird(sgNullFolders, False);
    // =========================================================================

   GScanDetails[dataLatestScan].ScanMode:=ScanSourceLive;

   GScanDetails[dataLatestScan].ScanDateStr := GetDate(GETTIMEFORMAT_SLASH) + ' ' + TUtility.GetTime(GETTIMEFORMAT_SLASH);
   GScanDetails[dataLatestScan].ScanDateInt := GetDate(GETTIMEFORMAT_YYYYMMDD) + TUtility.GetTime(GETTIMEFORMAT_FILE);

    if Assigned(FOnProcessWindowStatus) then
      FOnProcessWindowStatus(CWindowAnalysisProgress, 1);

    for t := 0 to ScanMultiple.Count - 1 do begin
      XSettings.ProgressForm.SetProcessText(XText[rsCreatingFileList]);

      ffMain.Criteria.Files.Location := ScanMultiple.strings[t];

      ffMain.Execute;
    end;

//    PrepareToAnalyse(ScanMultiple.strings[0], True, True, True);

    if Assigned(FOnProcessWindowStatus) then
        FOnProcessWindowStatus(CWindowAnalysisProgress, 1);
    // =========================================================================

    pMainReportsxxxChange(Nil);
    ToggleSoftwareStatus(True);

  //  case XSettings.PostScanMode of
//      0 : {};
//      1 : lTaskID1Click(Nil);
//      2 : begin
//            lTaskID2Click(Nil);

//            pMainReports.ActivePageIndex := XSettings.PostScanIPPage;
//          end;
//      3 : lTaskID4Click(Nil);
//    end;

    // =========================================================================
//  end;       }
end;


procedure TfrmMain.UpdateFolderHistoryOnTerminate(Sender: TObject);
 begin
  if GUpdateFolderHistoryUpdateThread.Error <> '' then begin
    ShowXDialog(XText[rsErrorSaving] + ': ' + XText[rsFolderHistory] + ' Database',
                GUpdateFolderHistoryUpdateThread.Error,
                XDialogTypeWarning);

    TMSLogger.Info(GUpdateFolderHistoryUpdateThread.Error);
  end;

  GUpdateFolderHistoryUpdateThread := Nil;

  FrameFolderHistory.BuildFolderHistory(TXWindows.GetComputerNetName, FrameSelect.ePath.Text);

  if FrameFolderHistory.clbFolderHistory.Count <> 0 then begin
    FrameFolderHistory.clbFolderHistory.Checked[0] := True;
    FrameFolderHistory.clbFolderHistory.ItemIndex  := 0;
    FrameFolderHistory.rbFHCountClick(Nil);
  end;

  lWelcomeFolderHistory.Font.Color := clWindowText;
  lWelcomeFolderHistory.Caption    := XText[rsFolderHistory];

  TMSLogger.Info('Folder History Update Finished.');
end;


procedure TfrmMain.BuildDisplay(aDataIndex : integer);
begin
  case aDataIndex of
    dataLatestScan    : begin
                          FrameReports[aDataIndex].BuildDisplay;

                          GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathLS));
                        end;
    dataFolderHistory : begin
                          FrameReports[aDataIndex].BuildDisplay;

                          GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathFH));
                        end;
  end;
end;


procedure TfrmMain.ApplicationEvents1ShowHint(var HintStr: string;
  var CanShow: Boolean; var HintInfo: THintInfo);
begin
  if HintInfo.HintControl = tbPrivacy  then
    OnTutorialBarChange('hintPrivacy')
  else if HintInfo.HintControl = tbToggleFH then
    OnTutorialBarChange('hintToggleFH')
  else if (HintInfo.HintControl = tbReportSummary) or (HintInfo.HintControl = tbReportCSV) or
          (HintInfo.HintControl = tbReportHTML) or (HintInfo.HintControl = tbReportText) or
          (HintInfo.HintControl = tbReportTree) or (HintInfo.HintControl = tbReportXML) then
    OnTutorialBarChange('hintReports');
end;


procedure TfrmMain.AutoSaveReports(aDataIndex : integer);
 begin
  XSettings.Report.TextOptions[LayoutAutoSave].FileName       := '';
  XSettings.Report.CSVOptions[LayoutAutoSave].FileName        := '';
  XSettings.Report.HTMLOptions[LayoutAutoSave].FileName       := '';
  XSettings.Report.XinorbisOptions[LayoutAutoSave].FileName   := '';
  XSettings.Report.XMLOptions[LayoutAutoSave].FileName        := '';
  XSettings.Report.TreeOptions[LayoutAutoSave].FileName       := '';

  if XSettings.Report.AutoSaveItem[1] then
    XSettings.Report.TextOptions[LayoutAutoSave].FileName     := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\text\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

  if XSettings.Report.AutoSaveItem[2] then
    XSettings.Report.XinorbisOptions[LayoutAutoSave].FileName := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\xinorbis\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.zsr2';

  if XSettings.Report.AutoSaveItem[3] then
    XSettings.Report.HTMLOptions[LayoutAutoSave].FileName     := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\HTML\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.htm';

  if XSettings.Report.AutoSaveItem[4] then
    XSettings.Report.XMLOptions[LayoutAutoSave].FileName      := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\XML\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.xml';

  if XSettings.Report.AutoSaveItem[5] then
    XSettings.Report.CSVOptions[LayoutAutoSave].FileName      := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\CSV\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_'  + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.csv';

  if XSettings.Report.AutoSaveItem[6] then
    XSettings.Report.TreeOptions[LayoutAutoSave].FileName     := GSystemGlobal.AppDataPath + 'reports\' +
                                                          TXWindows.GetComputerNetName + '\tree\autosaves\' +
                                                          TXFormatting.MakeFileNameCompatible(FrameSelect.ePath.Text) + '_' +
                                                          TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_'  + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

  FrameReports[aDataIndex].SaveReports(XSettings.Report.TextOptions[LayoutAutoSave],
                                       XSettings.Report.CSVOptions[LayoutAutoSave],
                                       XSettings.Report.HTMLOptions[LayoutAutoSave],
                                       XSettings.Report.XinorbisOptions[LayoutAutoSave],
                                       XSettings.Report.XMLOptions[LayoutAutoSave],
                                       XSettings.Report.TreeOptions[LayoutAutoSave]);
end;


procedure TfrmMain.tbPreferencesClick(Sender: TObject);
 begin
  tbPreferences.ImageIndex := CToolbarPrefsOn;

  OnOpenSettingsTab(0);

  tbPreferences.ImageIndex := CToolbarPrefsOff;
end;


procedure TfrmMain.tbPrefsClick(Sender: TObject);
 begin
  tbPreferencesClick(nil);
end;


procedure TfrmMain.tbExitClick(Sender: TObject);
 begin
  Close;
end;


procedure TfrmMain.miSaveReportsClick(Sender: TObject);
var
  TextOptions : TTextReportOptions;
  CSVOptions  : TCSVReportOptions;
  HTMLOptions : THTMLReportOptions;
  XinOptions  : TXinorbisReportOptions;
  XMLOptions  : TXMLReportOptions;
  TreeOptions : TTreeReportOptions;

begin
  tbSave.ImageIndex := CToolbarSaveOn;

  case FSource of
    dataLatestScan    : if DoReportSave(FSource, TextOptions, CSVOptions, HTMLOptions, XinOptions, XMLOptions, TreeOptions) then
                          FrameReports[FSource].SaveReports(TextOptions, CSVOptions, HTMLOptions, XinOptions, XMLOptions, TreeOptions);

    dataFolderHistory : if DoReportSave(FSource, TextOptions, CSVOptions, HTMLOptions, XinOptions, XMLOptions, TreeOptions) then
                          FrameFolderHistory.SaveReports(TextOptions, CSVOptions, HTMLOptions, XinOptions, XMLOptions, TreeOptions)
  end;

  tbSave.ImageIndex := CToolbarSaveOff;
end;


procedure TfrmMain.FormResize(Sender: TObject);
 begin
  sbMain.Panels[0].Width := Width;

  if WindowState = wsNormal then begin
    if (XSettings.Forms.ProgressForm <> nil) then
      XSettings.MaximiseProgressWindow;
  end
  else begin
    if (XSettings.Forms.ProgressForm <> nil) then
      XSettings.MinimiseProgressWindow;
  end;
end;


//only to be used for the 'main screen'
function TfrmMain.BuildXinFilesFromReport(const aReportPath : string): boolean;
 begin
  TPreScan.PurgeAllData(dataLatestScan,
                        FrameReports[dataLatestScan].sgNullFiles,
                        FrameReports[dataLatestScan].sgNullFolders,
                        FrameSearch.sgSearchResults);

  Result := TPopulate.FromXinFilesFromReport(dataLatestScan, aReportPath);
end;


//only to be used for the 'main screen'
function TfrmMain.BuildXin2FilesFromReport(const aReportPath : string): boolean;
begin
  TPreScan.PurgeAllData(dataLatestScan,
                        FrameReports[dataLatestScan].sgNullFiles,
                        FrameReports[dataLatestScan].sgNullFolders,
                        FrameSearch.sgSearchResults);

  Result := TPopulate.FromXin2FilesFromReport(dataLatestScan, aReportPath);
end;


procedure TfrmMain.BuildMainFromCSV(aDataIndex : integer; const fn : string);         // check this needs dataindex, dont think it does
 var
  ret : TCSVDataFormat;
  cx : string;
  t : integer;

  function IsValidNumber(const s : string): boolean;
   var
    t : integer;

  begin
   Result := True;

   for t := 1 to length(s) do
     if (ord(s[t]) < 48) or (ord(s[t]) > 57) then
       Result := False;
  end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 1), 'BuildMainFromCSV :: invalid dataindex :: ' + inttostr(aDataIndex));

  ret := GetCSVDataFormat(fn);

  if ret.Fields[0] <> -1 then begin
    GScanDetails[aDataIndex].TimeStarted := Now;

    cx      := Caption;
    Caption := XText[rsPleaseWait];

    ShowProcessWindow;

    //--------------------------------------------------------------------------

    SetProcessBar(3);

    TPreScan.PurgeAllData(aDataIndex,
                          FrameReports[aDataIndex].sgNullFiles,
                          FrameReports[aDataIndex].sgNullFolders,
                          FrameSearch.sgSearchResults);
    
    TPopulate.FromXinFilesFromCSV(aDataIndex, ret, fn);

    //--------------------------------------------------------------------------

    SetProcessBar(4);
    XSettings.Forms.ProgressForm.SetProcessIcon(2);

    //--------------------------------------------------------------------------

    GSystemGlobal.drivespacemax  := 0;
    GSystemGlobal.drivespacefree := 0;

    SetProcessBar(5);

    GXinorbisScan.AnalyseDataFromCSVImport(aDataIndex);

    //-- ensure that the top101 tab is configured for our list of users --------

    FrameReports[aDataIndex].cbTopUsers.Clear;
    FrameReports[aDataIndex].cbTop101DatesUser.Clear;
    FrameReports[aDataIndex].cbTopUsers.Items.Add(XText[rsAllUsers]);
    FrameReports[aDataIndex].cbTop101DatesUser.Items.Add(XText[rsAllUsers]);

    for t := 0 to GScanDetails[aDataIndex].Users.Count - 1 do begin
      FrameReports[aDataIndex].cbTopUsers.Items.Add(GScanDetails[aDataIndex].Users[t].Name);
      FrameReports[aDataIndex].cbTop101DatesUser.Items.Add(GScanDetails[aDataIndex].Users[t].Name);
    end;

    FrameReports[aDataIndex].cbTopUsers.ItemIndex := 0;
    FrameReports[aDataIndex].cbTop101DatesUser.ItemIndex  := 0;

    // =========================================================================

    SetProcessBar(6);
    XSettings.Forms.ProgressForm.SetProcessIcon(3);

    TDisplayUtility.InformationTabTableTable(    aDataIndex, 1, FrameReports[aDataIndex].sgMainReport);
    TDisplayUtility.InformationTabFolderTable(   aDataIndex, FrameReports[aDataIndex].sgDirList);
    TDisplayUtility.InformationTabTypesList(     aDataIndex, FrameReports[aDataIndex].sgFileTypes);
    TDisplayUtility.InformationTabMagnitudeTable(aDataIndex, FrameReports[aDataIndex].cbMagnitudeScope.ItemIndex, FrameReports[aDataIndex].sgMagnitude);
    TDisplayUtility.InformationTabUsersTable(    aDataIndex, FrameReports[aDataIndex].cbUsersDisplayMode.ItemIndex, FrameReports[aDataIndex].sgUsers);

    FrameReports[aDataIndex].RefreshGraphDirList(nil);

    TDisplayUtility.InformationTabTypesTable(aDataIndex, 2, FrameReports[aDataIndex].tvFileTypes);
    case TDisplayUtility.InformationTabTypesTablePost(FrameReports[aDataIndex].tvFileTypes) of
      1 : FrameReports[aDataIndex].tvFileTypesClick(FrameReports[aDataIndex].tvFileTypes);
      2 : FrameReports[aDataIndex].cbTreeSizeClick(Nil);
    end;

    TDisplayUtility.InformationTabMagnitudeGraph(aDataIndex, FrameReports[aDataIndex].cbMagnitudeScope.ItemIndex, FrameReports[aDataIndex].vtcMagnitude, FrameReports[aDataIndex].cbGraphSizeMagnitude.Checked);

    FrameReports[aDataIndex].BuildUserDetailsGraph(Nil);

    FrameReports[aDataIndex].pTop101Left.Caption     := TDisplayUtility.BuildTop101FileSize(aDataIndex, FrameReports[aDataIndex].sgTop50Big, FrameReports[aDataIndex].sgTop50Small, FrameReports[aDataIndex].cbTopUsers, FrameReports[aDataIndex].capacityTop101);
    FrameReports[aDataIndex].pTop101DateLeft.Caption := TDisplayUtility.BuildTop101Date(aDataIndex, FrameReports[aDataIndex].sgTop101BigDate, FrameReports[aDataIndex].sgTop101SmallDate, FrameReports[aDataIndex].cbTop101DatesUser, FrameReports[aDataIndex].cbTop101Dates);

    if not(XSettings.Optimisations.JustInTimeDisplay) then begin
      TDisplayUtility.InformationTabFileDatesTree(aDataIndex, FrameReports[aDataIndex].cbFileDates.ItemIndex, FrameReports[aDataIndex].cbFileDatesUsers, XSettings.Optimisations.BuildDateTree, FrameReports[aDataIndex].tvFileDates, FrameReports[aDataIndex].vtcFileDates, FrameReports[aDataIndex].rbDatesQuantity.Checked, FrameReports[aDataIndex].capacityBarDates);

      FrameReports[aDataIndex].lHistoryResults.HTMLText[0] := TDisplayUtility.InformationTabHistoryGraph(aDataIndex, FrameReports[aDataIndex].vtcHistory, FrameReports[aDataIndex].cbHUsers, HGraphData,
                                                                                                         FrameReports[aDataIndex].dtpHFrom.Date, FrameReports[aDataIndex].dtpHTo.Date, FrameReports[aDataIndex].cbHInterval.ItemIndex,
                                                                                                         FrameReports[aDataIndex].cbHDateSelect.ItemIndex, FrameReports[aDataIndex].rbHQuantity.Checked,
                                                                                                         FrameReports[aDataIndex].cbHCumulative.Checked, FrameReports[aDataIndex].cbHInterval.Items[FrameReports[aDataIndex].cbHInterval.ItemIndex], FrameReports[aDataIndex].capacityBarHistory);

      FrameReports[aDataIndex].lTempStatus.Caption := TDisplayUtility.BuildTempChart(aDataIndex, FrameReports[aDataIndex].sgTemp, FrameReports[aDataIndex].vtcTemp, FrameReports[aDataIndex].rbTempSize.Checked);



      case aDataIndex of
        dataLatestScan    : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathLS));
        dataFolderHistory : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathFH));
      end;

      FrameNavigation[aDataIndex].BuildNavigationTab;

      FrameNavigation[aDataIndex].SelectAndDblClick(1, 1);
    end;

    BuildSummary(aDataIndex, 0);

    FrameReports[aDataIndex].RefreshGraph(nil);

    ToggleSoftwareStatus(aDataIndex, True);

    HideProcessWindow;
    Caption := cx;
  end;
end;

procedure TfrmMain.ToggleSoftwareStatus(aDataIndex : integer; newstatus : boolean);  // to do for fsource?
var
  t : integer;

begin
  FrameSelect.sbGoPath.Enabled                := newstatus;
  FrameSelect.ePath.Enabled                   := newstatus;
  FrameSelect.sbGoPathEdit.Enabled            := newstatus;
  FrameSelect.sbExcludeFolders.Enabled        := newstatus;
  FrameSelect.sbExcludeFiles.Enabled          := newstatus;
  FrameSelect.sbQuickFolder.Enabled           := newstatus;
  FrameSelect.sbCombine.Enabled               := newstatus;
  FrameSelect.sbExploreDir.Enabled            := newstatus;

  GXGuiUtil.SetButtonImageEnabled(tbReportCSV,      CReportOffStart, newstatus);
  GXGuiUtil.SetButtonImageEnabled(tbReportHTML,     CReportOffStart, newstatus);
  GXGuiUtil.SetButtonImageEnabled(tbReportSummary,  CReportOffStart, newstatus);
  GXGuiUtil.SetButtonImageEnabled(tbReportText,     CReportOffStart, newstatus);
  GXGuiUtil.SetButtonImageEnabled(tbReportTree,     CReportOffStart, newstatus);
  GXGuiUtil.SetButtonImageEnabled(tbReportXML,      CReportOffStart, newstatus);
  GXGuiUtil.SetButtonImageEnabled(tbReportXinorbis, CReportOffStart, newstatus);

  for t := 1 to SideMenuTasksCount do
    TaskOptions[t].Enabled := newstatus;

  tbSearchWizard.Enabled := newstatus;

  for t := 1 to SideMenuAdvancedCount do
    AdvancedOptions[t].Enabled := newstatus;

  if Assigned(FrameReports[aDataIndex]) then begin
    FrameReports[aDataIndex].pMainReports.Enabled           := newstatus;

    FrameReports[aDataIndex].rbGraphSize.Enabled            := newstatus;
    FrameReports[aDataIndex].rbGraphQuantity.Enabled        := newstatus;

    FrameReports[aDataIndex].cbTreeSize.Enabled             := newstatus;
    FrameReports[aDataIndex].cbTreeQuantity.Enabled         := newstatus;

    FrameReports[aDataIndex].cbGraphSizeMagnitude.Enabled   := newstatus;
    FrameReports[aDataIndex].cbGraphQtyMagnitude.Enabled    := newstatus;

    FrameReports[aDataIndex].rbUsersSize.Enabled            := newstatus;
    FrameReports[aDataIndex].rbUsersQuantity.Enabled        := newstatus;
  end;
end;


procedure TfrmMain.trayIconBalloonClick(Sender: TObject);
begin
  Checkforupdate1Click(Nil);
end;


procedure TfrmMain.trayIconClick(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, 'http://www.xinorbis.com/index.htm', '', '');
end;


procedure TfrmMain.tbSearchWizardClick(Sender: TObject);
var
  s : string;

begin
  if not(XSettings.ProcessWindowsVisible) then begin

    tbSearchWizard.ImageIndex := CToolbarWizardOn;

    s := DoUserWizard;

    if FrameFolderHistory.Visible then begin
      case FrameFolderHistory.ActivePage of
        3 : FrameFolderHistory.DoFHSearch(s);
        4 : FrameFolderHistory.DoCompareSearch(s);
        5 : FrameFolderHistory.DoCompareDriveSearch(s);
      else
        lTaskID1Click(lTaskID4);

        FrameSearch.DoSearch(s);
      end;
    end
    else begin
      lTaskID1Click(lTaskID4);

      FrameSearch.DoSearch(s);
    end;

    tbSearchWizard.ImageIndex := CToolbarWizardOff;
  end;
end;


procedure TfrmMain.tbSourceFolderHistoryClick(Sender: TObject);
begin
  FSource := dataFolderHistory;

  ActivateSource(FSource);
end;


procedure TfrmMain.tbSourceLiveClick(Sender: TObject);
begin
  FSource := dataLatestScan;

  ActivateSource(FSource);
end;


procedure TfrmMain.miHTMLReportClick(Sender: TObject);
 begin
  lReportHTMLMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.lReportPreferencesClick(Sender: TObject);
 begin
  DoReportSettings(8);
end;


procedure TfrmMain.lReportSummaryMouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  lFileName : string;

begin
  if tbReportSummary.Enabled then begin
    if FrameFolderHistory.Visible then begin

      lFileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\summary\quick\' +
                   TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
                   TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' +
                   TUtility.GetTime(GETTIMEFORMAT_FILE) +
                   '.txt';

      GReportSummary.SaveSummary(FSource, lFileName);

      GReportUtility.SetLastReport(FSource, lFileName, GScanDetails[FSource].ScanPath, ReportSummary, LayoutUnknown);
    end
    else begin
      lFileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\summary\quick\' +
                   TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
                   TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' +
                   TUtility.GetTime(GETTIMEFORMAT_FILE) +
                   '.txt';

      GReportSummary.SaveSummary(FSource, lFileName);

      GReportUtility.SetLastReport(FSource, lFileName, GScanDetails[FSource].ScanPath, ReportSummary, LayoutUnknown);
    end;
  end;

  if (Button = mbMiddle) then begin
    miOpenLastReportClick(Nil);
  end;
end;


procedure TfrmMain.lReportHTMLMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 var
  lFileName : string;
  tempHTMLOptions : THTMLReportOptions;
  lReportOutput : TStringList;

 begin
  tempHTMLOptions := XSettings.Report.HTMLOptions[LayoutQuick];

  if FrameFolderHistory.Visible then begin
    Assert(Sender <> Nil, 'lFHReportHTMLMouseDown :: sender is nil');

    TLabel(Sender).Font.Style := [fsBold];

    if FrameFolderHistory.ActivePage = TabFHCompare then begin
      lFileName := TXFormatting.MakeFileNameCompatible(FrameFolderHistory.SelectedPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.htm';

      XSettings.Report.HTMLCompareOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML_Compare\quick\' + lFileName;

      GReportHTML.GenerateHTMLCompareReport(XSettings.Report.HTMLCompareOptions,
                                            FrameFolderHistory.SelectedPath, FrameFolderHistory.eFHCompareSearch.Text, FrameFolderHistory.bFHCompareLeft.Caption, FrameFolderHistory.bFHCompareRight.Caption,
                                            FrameFolderHistory.QuickCompareA, FrameFolderHistory.QuickCompareB,
                                            FrameFolderHistory.sgFHCompareLeft, FrameFolderHistory.sgFHCompareRight);

      if XSettings.Report.HTMLCompareOutput <> '' then
        TXWindows.ExecuteFile(0, '"' + XSettings.Report.HTMLCompareOutput + '"', '"' + GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML_Compare\quick\' + lFileName + '"', '')
      else
        TXWindows.ExecuteFile(0, '"' + GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML_Compare\quick\' + lFileName + '"', '', '');

      sbMain.Panels[0].Text := XText[rsHTMLCReportSavedAs] + ': <b>' + GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML_Compare\quick\' + lFileName + '</b>';
    end
    else begin
      lFileName := TXFormatting.MakeFileNameCompatible(FrameFolderHistory.SelectedPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.htm';

      tempHTMLOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\HTML\quick\FH_' + lFileName;

      GReportHTML.GenerateHTMLReport(FSource, tempHTMLOptions, FrameFolderHistory.bFHISelect.Caption);
    end;

    TLabel(Sender).Font.Style := [];
  end
  else begin
    if FrameSearch.Visible then begin
      if (GScanDetails[dataSearch].FileCount <> 0) then begin
        if FrameSearch.ActivePage = 1 then begin
          tempHTMLOptions.FileName := TXFormatting.MakeFileNameCompatible(XText[rsSearchResults] + '_' + GScanDetails[dataSearch].ScanPath) + '_' +
                                      TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '_' + XText[rsSearch] + '.htm';

          BuildOpenHTMLReport(dataSearch, tempHTMLOptions);
        end
        else begin
          lFileName := TXFormatting.MakeFileNameCompatible(XText[rsSearchResults] + '_' + GScanDetails[dataSearch].ScanPath) + '_' +
                     TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '_' + XText[rsSearch] + '.htm';

          lReportOutput := TStringList.Create;

          GReportHTML.GenerateHTMLFileReport(dataSearch, lReportOutput, XText[rsSearchResults] + ' "' + FrameSearch.SearchText + '"', lFileName);

          FreeAndNil(lReportOutput);
        end;
      end
      else begin
        ShowXDialog(XText[rsWarning],
                    XText[rsNoDataToExport],
                    XDialogTypeWarning);

        Exit;
      end;
    end
    else begin
      BuildOpenHTMLReport(FSource, tempHTMLOptions);
    end;
  end;

  if (Button = mbMiddle) then begin
    miOpenLastReportClick(Nil);
  end;
end;

procedure TfrmMain.lReportXMLMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  DT : string;
  lFileName : string;
  tempXMLOptions : TXMLReportOptions;
  lReportOutput : TStringList;
  lSource : integer;

begin
  if tbReportXML.Enabled then begin
    if FrameFolderHistory.Visible then begin

      TLabel(Sender).Font.Style := [fsBold];

      if (FrameFolderHistory.tpFHMain.ActivePageIndex = TabFHMainSearch) and
         (FrameFolderHistory.tsFHSearch.ActivePageIndex = TabFHCompare) then begin
        sbFHCXMLReportClick(nil);
      end
      else begin
        lFileName := TXSaveDialog.Execute(XText[rsXMLFiles] + ' (*.xml)|*.xml',
                                          '.xml',
                                          TUtility.GetDefaultFileName('.xml', 'xml_' + XText[rsReport]),
                                          GSystemGlobal.AppDataPath);

        if lFileName <> '' then begin
          DT := TConvert.DateTimeFToYYYYMMDDHHMMSS(FrameFolderHistory.FolderHistoryItemSelected);

          ExportTableToXML(lFileName, TMD5.Generate(UpperCase(FrameFolderHistory.SelectedPath)) + DT + FrameFolderHistory.SelectedComputer);

          GReportUtility.SetLastReport(FSource, lFileName, GScanDetails[FSource].ScanPath, ReportXML, LayoutUnknown);

          sbMain.Panels[0].Text := XText[rsXMLReportSavedAs] + ': <b>' + lFileName + '</b>';
        end;
      end;

      TLabel(Sender).Font.Style := [];
    end
    else begin
      tempXMLOptions := XSettings.Report.XMLOptions[LayoutQuick];

      if FrameSearch.Visible then begin
        if (GScanDetails[dataSearch].FileCount <> 0) then begin

          lSource   := dataSearch;

          lFileName := '_' + XText[rsSearch] + '.xml';

          tempXMLOptions.Special := FrameSearch.SearchText;

          if FrameSearch.ActivePage = 1 then begin
          end
          else begin
            tempXMLOptions.XMLData := CDataFileList;
          end;
        end
        else begin
          ShowXDialog(XText[rsWarning],
                      XText[rsNoDataToExport],
                      XDialogTypeWarning);

          Exit;
        end;
      end
      else begin
        lSource   := FSource;

        lFileName := '.xml';
      end;

      tempXMLOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\xml\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[lSource].ScanPath) + '_' +
                                 TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) +
                                 lFileName;

      lReportOutput := TStringList.Create;

      if tempXMLOptions.XMLData = CDataSummary then
        GReportXML.GenerateXMLOutput(lSource, tempXMLOptions, lReportOutput)
      else
        GReportXML.GenerateXMLOutputFileList(tempXMLOptions.FileName, lReportOutput, lSource, LayoutQuick);

      FreeAndNil(lReportOutput);
    end;
  end;

  if (Button = mbMiddle) and not(tempXMLOptions.XMLAutoOpen) then begin
    miOpenLastReportClick(Nil);
  end;
end;

procedure TfrmMain.lReportCSVMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 var
  DT : string;
  lFileName : string;
  tempCSVOptions : TCSVReportOptions;
  lCSVOutput : TStringList;
  lSource : integer;

 begin
  if tbReportCSV.Enabled then begin
    if FrameFolderHistory.Visible then begin

      TLabel(Sender).Font.Style := [fsBold];

      lFileName := TXSaveDialog.Execute(XText[rsCSVFiles] + ' (*.csv)|*.csv',
                                        '.csv',
                                        TUtility.GetDefaultFileName('.csv', 'csv_' + XText[rsReport]),
                                        GSystemGlobal.AppDataPath);

      if lFileName <> '' then begin
        DT := TConvert.DateTimeFToYYYYMMDDHHMMSS(FrameFolderHistory.FolderHistoryItemSelected);

        ExportTableToCSV(lFileName, TMD5.Generate(UpperCase(FrameFolderHistory.SelectedPath)) + DT + FrameFolderHistory.SelectedComputer);

        GReportUtility.SetLastReport(FSource, lFileName, GScanDetails[FSource].ScanPath, ReportCSV, LayoutUnknown);

        sbMain.Panels[0].Text := XText[rsCSVReportSavedAs] + ': <b>' + lFileName + '</b>';
      end;

      TLabel(Sender).Font.Style := [];
    end
    else begin
      tempCSVOptions := XSettings.Report.CSVOptions[LayoutQuick];

      if FrameSearch.Visible then begin
        if (GScanDetails[dataSearch].FileCount <> 0) then begin
          lSource   := dataSearch;

          if FrameSearch.ActivePage = 1 then begin
            lFileName := '_' + XText[rsSearch] + '.csv';
          end
          else begin
            tempCSVOptions.CSVData := CDataFileList;

            lFileName := '_' + XText[rsSearch] + '.csv';
          end
        end
        else begin
          ShowXDialog(XText[rsWarning],
                      XText[rsNoDataToExport],
                      XDialogTypeWarning);

          Exit;
        end;
      end
      else begin
        lSource   := FSource;

        lFileName := '.csv';
      end;

      tempCSVOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\csv\quick\' +
                                 TXFormatting.MakeFileNameCompatible(GScanDetails[lSource].ScanPath) + '_' +
                                 TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) +
                                 lFileName;

      tempCSVOptions.Category := -1;

      lCSVOutput := TStringList.Create;

      GReportCSV.GenerateCSVReport(lSource, lCSVOutput, tempCSVOptions, LayoutQuick);

      FreeAndNil(lCSVOutput);
    end;
  end;

  if (Button = mbMiddle) then begin
    miOpenLastReportClick(Nil);
  end;
end;

procedure TfrmMain.lReportTextMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  tempTextOptions : TTextReportOptions;
  lCSVOptions  : TCSVReportOptions;
  lHTMLOptions : THTMLReportOptions;
  lXinOptions  : TXinorbisReportOptions;
  lXMLOptions  : TXMLReportOptions;
  lTreeOptions : TTreeReportOptions;
  lSource : integer;
  lFileName : string;

begin
  tempTextOptions := XSettings.Report.TextOptions[LayoutQuick];

  if Button = mbMiddle then
    tempTextOptions.TextAutoOpen := True;

  if FrameFolderHistory.Visible then begin
    tempTextOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\text\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
                                TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

    FrameFolderHistory.SaveReports(tempTextOptions, lCSVOptions, lHTMLOptions, lXinOptions, lXMLOptions, lTreeOptions);
  end
  else begin
    if FrameSearch.Visible then begin
      lFileName := '_' + XText[rsSearch] + '.txt';

      tempTextOptions.Special := FrameSearch.SearchText;

      if FrameSearch.ActivePage = 1 then begin
        lSource   := dataSearch;
      end
      else begin
        lSource   := FSource;
      end;
    end
    else begin
      lSource   := FSource;

      lFileName := '.txt';
    end;

    tempTextOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\text\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[lSource].ScanPath) + '_' +
                                TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) +
                                lFileName;

    FrameReports[lSource].SaveReports(tempTextOptions, lCSVOptions, lHTMLOptions, lXinOptions, lXMLOptions, lTreeOptions);
  end;

  if tempTextOptions.TextAutoOpen then
    miOpenLastReportClick(Nil);
end;

procedure TfrmMain.lReportXinorbisMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 var
  lTextOptions : TTextReportOptions;
  lCSVOptions  : TCSVReportOptions;
  lHTMLOptions : THTMLReportOptions;
  lXMLOptions  : TXMLReportOptions;
  lTreeOptions : TTreeReportOptions;
  tempXinorbisOptions : TXinorbisReportOptions;

 begin
  tempXinorbisOptions := XSettings.Report.XinorbisOptions[LayoutQuick];
  tempXinorbisOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\xinorbis\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
                                  TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.zsr2';

  if Button = mbMiddle then
    tempXinorbisOptions.XinorbisAutoOpen := True;

  if FrameReports[FSource].SaveReports(lTextOptions, lCSVOptions, lHTMLOptions, tempXinorbisOptions, lXMLOptions, lTreeOptions) then
    GReportUtility.SetLastReport(FSource, lTreeOptions.Filename, GScanDetails[FSource].ScanPath, ReportTree, LayoutUnknown);

  if tempXinorbisOptions.XinorbisAutoOpen then
    miOpenLastReportClick(Nil);  
end;

procedure TfrmMain.lReportTreeMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 var
  lTextOptions : TTextReportOptions;
  lCSVOptions  : TCSVReportOptions;
  lHTMLOptions : THTMLReportOptions;
  lXinOptions  : TXinorbisReportOptions;
  lXMLOptions  : TXMLReportOptions;
  tempTreeOptions : TTreeReportOptions;

 begin
  if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
    ShowXDialog(XText[rsWarning], XText[rsPleaseWaitFolderHistory], XDialogTypeXinorbis);
  end
  else begin
    tempTreeOptions := XSettings.Report.TreeOptions[LayoutQuick];
    tempTreeOptions.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\tree\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
                                TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

    if Button = mbMiddle then
      tempTreeOptions.TreeAutoOpen := True;

    if FrameFolderHistory.Visible then
    begin
      if FrameFolderHistory.SaveReports(lTextOptions, lCSVOptions, lHTMLOptions, lXinOptions, lXMLOptions, tempTreeOptions) then
        GReportUtility.SetLastReport(dataFolderHistory, tempTreeOptions.Filename, GScanDetails[dataFolderHistory].ScanPath, ReportTree, LayoutUnknown);
    end
    else begin
      if FrameReports[FSource].SaveReports(lTextOptions, lCSVOptions, lHTMLOptions, lXinOptions, lXMLOptions, tempTreeOptions) then
        GReportUtility.SetLastReport(FSource, tempTreeOptions.Filename, GScanDetails[FSource].ScanPath, ReportTree, LayoutUnknown);
    end;

    if tempTreeOptions.TreeAutoOpen then
      miOpenLastReportClick(Nil);
  end;
end;

procedure TfrmMain.miCustomReportClick(Sender: TObject);
var
  tHTMLrl : THTMLReportOptions;
  tTEXTrl : TTextReportOptions;
  tTREErl : TTreeReportOptions;
  tCSVrl  : TCSVReportOptions;

begin
  case TLabel(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag of
    CReportHTML  : begin
                    tHTMLrl := DoHTMLReport(LayoutQuick, True);

                    if tHTMLrl.Layout <> '$' then begin
                      BuildOpenHTMLReport(FSource, tHTMLrl);
                    end;
                  end;
    CReportCSV  : begin
                    tCSVrl := DoCSVReport(LayoutQuick, True);

                    if tCSVrl.Layout <> '$' then begin
                      BuildOpenCSVReport(tCSVrl);
                    end;
                  end;
    CReportText : begin
                    tTEXTrl := DoTextReport(LayoutQuick, FSource, True);

                    if tTEXTrl.Layout <> '$' then begin
                      BuildOpenTextReport(tTEXTrl);
                    end;
                  end;
    CReportTree : begin
                    tTREErl := DoTreeReport(LayoutQuick, FSource, True);

                    if tTREErl.Layout <> '$' then begin
                      BuildOpenTreeReport(tTREErl);
                    end;
                  end;
  end;
end;


procedure TfrmMain.miOpenCustomReportClick(Sender: TObject);
var
  lFileName : string;

begin
  case TLabel(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent).Tag of
    CReportHTML : begin
                    lFileName := TXOpenDialog.Execute(XText[rsCustomReportFiles] + ' (*.xcrhtml)|*.xcrhtml',
                                                      '.xcrhtml',
                                                      GSystemGlobal.AppDataPath + 'Saves\Custom Reports',
                                                      '');

                    if lFileName <> '' then
                      BuildOpenHTMLReport(FSource, GReportHTML.BuildHTMLReportOptionsFromFile(lFileName));
                  end;
    CReportText : begin
                    lFileName := TXOpenDialog.Execute(XText[rsCustomReportFiles] + ' (*.xcrtxt)|*.xcrtxt',
                                                      '.xcrtxt',
                                                      GSystemGlobal.AppDataPath + 'Saves\Custom Reports',
                                                      '');

                    if lFileName <> '' then
                      BuildOpenTextReport(GReportText.BuildTextReportOptionsFromFile(lFileName));
                  end;
    CReportTree : begin
                    lFileName := TXOpenDialog.Execute(XText[rsCustomReportFiles] + ' (*.xcrtree)|*.xcrtree',
                                                      '.xcrtree',
                                                      GSystemGlobal.AppDataPath + 'Saves\Custom Reports',
                                                      '');

                    if lFileName <> '' then
                      BuildOpenTreeReport(GReportTree.BuildTreeReportOptionsFromFile(lFileName));
                  end;
  end;
end;


procedure TfrmMain.DoPreferenceChanges;
 begin
  FileExtensionsObject.CategoryExtensions.Sort(TComparer<TFileExtension>.Construct(CompareExtensions));
end;


procedure TfrmMain.miEditHTMLReportsClick(Sender: TObject);
begin
  case TMenuItem(Sender).Tag of
    0 : DoCSVReport(0, False);
    1 : DoHTMLReport(0, False);
    2 : DoTextReport(0, FSource, False);
    3 : DoTreeReport(0, FSource, False);
    4 : DoXMLReport(0, FSource);
  end;
end;


procedure TfrmMain.Exit1Click(Sender: TObject);
 begin
  Close;
end;


procedure TfrmMain.miXinorbisHomeClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'http://www.xinorbis.com/index.htm', '', '');
end;


procedure TfrmMain.miXinorbisReportClick(Sender: TObject);
 begin
  lReportXinorbisMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.miXMLReportClick(Sender: TObject);
 begin
  lReportXMLMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.miUserManualClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, '"' + GSystemGlobal.ExePath + 'Xinorbis8 User Manual.pdf"', '', '');
end;


procedure TfrmMain.miViewLogFolderClick(Sender: TObject);
begin
  TXWindows.ExecuteFile(0, '"' + GSystemGlobal.ExePath + 'Logs\"', '', '');
end;


procedure TfrmMain.miContextHelpClick(Sender: TObject);
var
  lFHSubIndex : integer;

begin
  case FrameReports[FSource].pMainReports.ActivePageIndex of
    TabFHMainStats  : lFHSubIndex := FrameFolderHistory.tpFHStats.ActivePageIndex;
    TabFHMainSearch : lFHSubIndex := FrameFolderHistory.tsFHSearch.ActivePageIndex;
  else
    lFHSubIndex := 0;
  end;

  THelp.OpenContextHelpPage(NavigationHistory[tbHome.Tag],
                            FrameReports[FSource].pMainReports.ActivePageIndex,
                            FrameFolderHistory.tpFHMain.ActivePageIndex,
                            lFHSubIndex);
end;


procedure TfrmMain.miFAQsClick(Sender: TObject);
begin
  THelp.OpenHelpPage('faqs.htm');
end;


procedure TfrmMain.miReferenceClick(Sender: TObject);
 begin
  ShowReference;
end;


procedure TfrmMain.AdvancedOptionsClick(Sender: TObject);
var
  lOption : integer;

begin
  lOption := -1;

  if Sender is TMenuItem then
    lOption := TMenuItem(Sender).Tag
  else if Sender is TLabel then
    lOption := TLabel(Sender).Tag;

  case lOption of
    0 : SetAdvancedOptions(lOption);
    1 : lTaskID1Click(lTaskID6);
    2 : lTaskID1Click(lTaskID7);
    3 : SetAdvancedOptions(lOption);
    4 : SetAdvancedOptions(lOption);
  end;
end;


procedure TfrmMain.SetAdvancedOptions(aOptions : integer);
begin
  case aOptions of
    CAOSpread   : begin
                    lAdvID1.Font.Style := [fsBold];

                    DoSpread(FSource);

                    lAdvID1.Font.Style := [];
                  end;
    CAOExplore  : begin
                    lAdvID2.Font.Style := [fsBold];

                    DoExplore(FSource, GScanDetails[FSource].ScanPath);

                    lAdvID2.Font.Style := [];
                  end;
    CAOFileAges : begin
                    lAdvID3.Font.Style := [fsBold];

                    DoFileAges(FSource);

                    lAdvID3.Font.Style := [];
                  end;
  end;
end;


procedure TfrmMain.miReportBrowserClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, '"' + GSystemGlobal.AppDataPath + 'reports' + '"', '', '');
end;


procedure TfrmMain.tbWebReportsClick(Sender: TObject);
 begin
  if XSettings.ftpOptions[ftpActualLink] <> '' then
    TXWindows.ExecuteFile(0, XSettings.ftpOptions[ftpActualLink], '', '')
  else
    ShowXDialog(XText[rsWebReports], XText[rsWebReportsSettingsMissing], XDialogTypeXinorbis);
end;


procedure TfrmMain.miTabTableClick(Sender: TObject);
 begin
  SetSidePanelDisplay(NullEntry, 2, TMenuITem(Sender).Tag, NullEntry);
end;


procedure TfrmMain.miShowCategoryColoursClick(Sender: TObject);
 begin
  ShowCategoryColours;
end;


procedure TfrmMain.miShowSearchSyntaxClick(Sender: TObject);
begin
  THelp.OpenSearchManual;
end;


procedure TfrmMain.sbRefreshClick(Sender: TObject);
 begin
  ShowProcessWindow;

  GXinorbisScan.Analyse; // check this works

  HideProcessWindow;
end;


procedure TfrmMain.FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
 begin
  MinWidth := 800;
end;


// =======================================================================================================
// =======================================================================================================


procedure TfrmMain.About1Click(Sender: TObject);
 begin
  ShowAbout;
end;


procedure TfrmMain.Checkforupdate1Click(Sender: TObject);
 begin
  if CheckForNewVersion(x8Version, x8Date, 'x8', False) = mrAll then
    Halt(0);
end;


procedure TfrmMain.miTextReportClick(Sender: TObject);
 begin
  lReportTextMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.miTreeReportClick(Sender: TObject);
 begin
  lReportTreeMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.LoadFileExtensionData;
begin
  if not(FileExtensionsObject.LoadFileExtensionDescriptions(GSystemGlobal.ExePath + 'data\system\xinfe.txt')) then begin
    ShowXDialog(XText[rsWarning],
                XText[rsErrorOpening] + ' "' + GSystemGlobal.ExePath + 'data\system\xinfe.txt' + '".',
                XDialogTypeWarning);

    sbMain.Panels[0].Text := '<b>' + XText[rsError] + '</b>: ' + GSystemGlobal.ExePath + 'data\system\xinfe.txt';
  end;
end;


procedure TfrmMain.LoadLanguageDetails(languageindex : integer; debugmode : boolean);
var
  t : integer;
  languagesymbol : string;

begin
  TGLobal.InitialiseGlobalText;

  // if the selected language folder doesn't exist the set it to English
  if Not(SysUtils.DirectoryExists(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(languageindex))) then begin
    languageindex := LanguageUK;

    ShowXDialog(XText[rsErrorOpeningXinorbisSystemFile], 'Language not found.', XDialogTypeWarning);
  end;

  languagesymbol := TLanguageHandler.GetLanguageSymbol(languageindex);

//  LanguageMenus[XSettings.CurrentLanguage].ImageIndex := 24 + XSettings.CurrentLanguage;
  LanguageMenus[XSettings.CurrentLanguage].ImageIndex := 13 + XSettings.CurrentLanguage;

  for t := 0 to 11 do
    LanguageTabs[t] := FrameReports[dataLatestScan].pMainReports.AdvSmoothTabPages[t].Caption;

  // ===========================================================================

  MenuStrings.Clear;

  LoadMenu(FrameSearch.puQuickSearch,          GSystemGlobal.ExePath + 'data\languages\' + languagesymbol + '\QuickSearch.menu');
  LoadMenu(FrameFolderHistory.puFHQuickSearch, GSystemGlobal.ExePath + 'data\languages\' + languagesymbol + '\FHQuickSearch.menu');

  // ===========================================================================

  if (XSettings.CustomSettings.SettingsSaveLocation = SaveLocationRegistry) then begin
    TGlobal.LoadTypeDescriptions;
  end;
end;


procedure TfrmMain.UpdateGUICustomNames(aDataIndex : integer);
begin
  if Assigned(FrameReports[aDataIndex]) then
    FrameReports[aDataIndex].UpdateGUICustomNames;

  if Assigned(FrameNavigation[aDataIndex]) then
    FrameNavigation[aDataIndex].UpdateGUICustomNames;
end;


procedure TfrmMain.miLang1Click(Sender: TObject);
 begin
   XSettings.CurrentLanguage := TMenuItem(Sender).Tag;
 //  LoadLanguageDetails(TMenuItem(Sender).Tag, False);
end;


procedure TfrmMain.ShowZipProcessWindow;
 begin
  XSettings.ShowZipWindow;
end;


procedure TfrmMain.HideZipProcessWindow;
 begin
  XSettings.HideZipWindow;
end;


procedure TfrmMain.ShowProcessWindow;
 begin
  XSettings.ShowProgressWindow;
end;


procedure TfrmMain.SetProcessBar(newposition : integer);
 begin
  XSettings.Forms.ProgressForm.SetProcessBar(newposition);
end;


procedure TfrmMain.HideProcessWindow;
 begin
  XSettings.HideProgressWindow;
end;


procedure TfrmMain.ProcessUpdateFolderHistoryFile;
 begin
  TFolderHistoryUtility.UpdateFolderHistoryFile(dataLatestScan, FrameSelect.ePath.Text);

  if XSettings.HistorySettings.FullLogging then begin
    lWelcomeFolderHistory.Font.Color := clGreen;

    TMSLogger.Info('Folder History Update Started');

    GUpdateFolderHistoryUpdateThread := TUpdateFolderHistoryUpdateThread.Create(True);
    GUpdateFolderHistoryUpdateThread.OnTerminate := UpdateFolderHistoryOnTerminate;
    GUpdateFolderHistoryUpdateThread.SetData(GScanDetails[dataLatestScan].ScanMD5 +
                                             GScanDetails[dataLatestScan].ScanDateInt +
                                             TXWindows.GetComputerNetName,
                                             XSettings.Database.ODBConnectionString,
                                             XSettings.Database.UseODBC,
                                             lWelcomeFolderHistory);
    GUpdateFolderHistoryUpdateThread.Start;
  end;
end;


procedure TfrmMain.miCSVReportClick(Sender: TObject);
begin
  lReportCSVMouseDown(Nil, mbLeft, [], 0, 0);
end;


procedure TfrmMain.miTutorialClick(Sender: TObject);
begin
  pTutorial.Visible := not(pTutorial.Visible);
end;


procedure TfrmMain.W7ToolButton3Click(Sender: TObject);
begin
  if FSource <> dataFolderHistory then                         // to do, make refresh work with folder history
    if GScanDetails[FSource].Files.Count <> 0 then begin
      XinorbisScan(FSource, GScanDetails[FSource].ScanPath, '', ScanTypeRefresh, GScanDetails[FSource].ScanSource);
    end;
end;


procedure TfrmMain.Warning1Click(Sender: TObject);
begin
  {$IFDEF debug}
  ShowXDialog('Debug', 'Dialog test', XDialogTypeWarning);
  {$ENDIF}
end;


procedure TfrmMain.miFHInfoClick(Sender: TObject);
 begin
  ShowDatabaseInfo;
end;


procedure TfrmMain.miFileAssociationsClick(Sender: TObject);
begin
  if DoFileAssociations = mrOK then begin

  end;
end;


procedure TfrmMain.miBackupDataClick(Sender: TObject);
var
 lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsCompressedFiles] + ' (*.zip)|*.zip',
                                    '.zip',
                                    'XinorbisBackup_' + TConvert.DateToYYYYMMDD(Now) + '.zip',
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    ShowZipProcessWindow;

    XinorbisZip.ZipFolder(lFileName, GSystemGlobal.AppDataPath);

    HideZipProcessWindow;
  end;
end;


procedure TfrmMain.sbFHCXMLReportClick(Sender: TObject);
var
  lFilename : string;

 begin
  lFilename := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\XML_Compare\quick\' + TXFormatting.MakeFileNameCompatible(FrameFolderHistory.SelectedPath) + '_' +
               TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.xml';

  GReportXML.GenerateXMLCompareOutput(lFilename, FrameFolderHistory.SelectedPath,
                                      FrameFolderHistory.bFHCompareLeft.Caption, FrameFolderHistory.bFHCompareRight.Caption,
                                      FrameFolderHistory.sgFHCompareLeft, FrameFolderHistory.sgFHCompareRight);

  if XSettings.Report.XMLOutput <> '' then
    TXWindows.ExecuteFile(0, '"' + XSettings.Report.XMLOutput + '"', '"' + lFilename + '"', '')
  else
    TXWindows.ExecuteFile(0, 'notepad.exe', '"' + lFilename + '"', '');

  sbMain.Panels[0].Text := XText[rsXMLCReportSavedAs] + ': ' + lFilename;
end;


procedure TfrmMain.miSearchMainClick(Sender: TObject);
begin
  lTaskID1Click(lTaskID4);
end;


procedure TfrmMain.miSearchWizardClick(Sender: TObject);
var
  s : string;

begin
  s := DoSearchWizard;

  if s <> '' then begin

    case FSource of
      dataLatestScan    : begin
                            if (GScanDetails[FSource].Files.Count <> 0) then begin
                              lTaskID1Click(lTaskID4);

                              FrameSearch.DoSearch(s);
                            end;
                          end;
     dataFolderHistory  : begin
                            if (FrameFolderHistory.tpFHMain.ActivePageIndex = TabFHMainSearch) and
                               (FrameFolderHistory.tsFHSearch.ActivePageIndex = TabFHCompare) then begin
                              FrameFolderHistory.eFHCompareSearch.Text := s;

                              FrameFolderHistory.sbFHCompareSearchClick(FrameFolderHistory.sbFHCompareSearch);
                            end
                            else begin
                              lTaskID1Click(lTaskID4);

                              FrameSearch.DoSearch(s);
                            end;
                          end;
    end;
  end;
end;


procedure TfrmMain.LoadMenu(xMenu : TPopupMenu; aFilename : string);
 var
  ix : integer;
  mi : TMenuItem;
  LastNode : TMenuItem;
  tf : TextFile;
  s : string;

 begin
  LastNode := Nil;

  if FileExists(aFilename) then begin

    AssignFile(tf, aFilename);
    {$I-}
    Reset(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorOpeningXinorbisSystemFile],
                  XText[rsErrorOpening] + ' "' + aFilename + '".',
                  XDialogTypeWarning);
    end
    else begin
      while not(eof(tf)) do begin
        Readln(tf, s);

        if s <> '' then begin
          case s[1] of
            '-' : begin
                    mi := TMenuItem.Create(xMenu);
                    mi.Caption := '-';

                    if LastNode = Nil then
                      xMenu.Items.Add(mi)
                    else
                      LastNode.Add(mi);
                  end;
            '{' : begin
                    mi := TMenuItem.Create(xMenu);
                    mi.Caption := Copy(s, 2, length(s) - 2);
                    mi.Enabled := False;

                    if LastNode = Nil then
                      xMenu.Items.Add(mi)
                    else
                      LastNode.Add(mi);
                  end;
            '[' : begin
                    mi := TMenuItem.Create(xMenu);
                    mi.Caption := Copy(s, 2, length(s) - 2);
                    mi.Enabled := True;

                    if LastNode = Nil then
                      xMenu.Items.Add(mi)
                    else
                      LastNode.Add(mi);

                    LastNode := mi;
                  end;
            '.' : begin
                    mi := TMenuItem.Create(xMenu);
                    ix := Pos('=', s);

                    if ix <> 0 then begin
                      mi.Caption := Copy(s, 2, ix - 2);

                      MenuStrings.Add(Copy(s, ix + 1, Length(s) - ix + 1));

                      if xMenu = FrameSearch.puQuickSearch then
                        mi.OnClick := FrameSearch.miQuickSearchClick
                      else
                        mi.OnClick := FrameFolderHistory.miQuickSearchClick;

                      mi.Tag     := MenuStrings.Count - 1;
                    end
                    else begin
                      mi.Caption := Copy(s, 2, ix - 1);
                    end;

                    mi.Enabled := True;

                    if LastNode = Nil then
                      xMenu.Items.Add(mi)
                    else
                      LastNode.Add(mi);
                  end;
            '*' : begin
                    LastNode := LastNode.Parent;
                  end;
          end;
        end;
      end;

      CloseFile(tf);
    end;
    {$I+}
  end
  else
    ShowXDialog(XText[rsErrorOpeningXinorbisSystemFile],
                XText[rsErrorOpening] + ' "' + aFilename + '".',
                XDialogTypeWarning);
end;


procedure TfrmMain.miOpenLastReportClick(Sender: TObject);
 begin
  if GReportUtility.LastReportFilename <> '' then begin
    if FileExists(GReportUtility.LastReportFilename) then begin

      case GReportUtility.GetReportType(GReportUtility.LastReportFilename) of
        CReportTypeCSV      : begin
                                if XSettings.Report.CSVOutput <> '' then
                                  TXWindows.ExecuteFile(0, '"' + XSettings.Report.CSVOutput + '"', '"' + GReportUtility.LastReportFilename + '"', '')
                                else
                                  TXWindows.ExecuteFile(0, 'notepad.exe', '"' + GReportUtility.LastReportFilename + '"', '');
                              end;
        CReportTypeHTML     : begin
                                if XSettings.Report.HTMLOutput <> '' then
                                  TXWindows.ExecuteFile(0, '"' + XSettings.Report.HTMLOutput + '"', '"' + GReportUtility.LastReportFilename + '"', '')
                                else
                                  TXWindows.ExecuteFile(0, '"' + GReportUtility.LastReportFilename + '"', '', '');
                              end;
        CReportTypeText     : begin
                                if XSettings.Report.TextOutput <> '' then
                                  TXWindows.ExecuteFile(0, '"' + XSettings.Report.TextOutput + '"', '"' + GReportUtility.LastReportFilename + '"', '')
                                else
                                  TXWindows.ExecuteFile(0, '"' + GReportUtility.LastReportFilename + '"', '', '');
                              end;
        CReportTypeXinorbis : begin
                                TXWindows.ExecuteFile(0, 'notepad.exe', '"' + GReportUtility.LastReportFilename + '"', '');
                              end;
        CReportTypeXML      : begin
                                if XSettings.Report.XMLOutput <> '' then
                                  TXWindows.ExecuteFile(0, '"' + XSettings.Report.XMLOutput + '"', '"' + GReportUtility.LastReportFilename + '"', '')
                                else
                                  TXWindows.ExecuteFile(0, 'notepad.exe', '"' + GReportUtility.LastReportFilename + '"', '');
                              end;
      else
        ShowXDialog(XText[rsReportNotFound],
                    GReportUtility.LastReportFilename,
                    XDialogTypeWarning);
      end;
    end;
  end;
end;


procedure TfrmMain.miCopyLastReportToClipboardClick(Sender: TObject);
var
  lDocument : TStringList;

begin
  if GReportUtility.LastReportFilename <> '' then begin
    lDocument := TStringList.Create;

    lDocument.LoadFromFile(GReportUtility.LastReportFilename);

    Clipboard.AsText := lDocument.Text;

    lDocument.Free;
  end;
end;


procedure TfrmMain.BuildOpenHTMLReport(aDataIndex : integer; HTMLr : THTMLReportOptions);
 begin
  HTMLr.Filename := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\html\quick\' +
                    TXFormatting.MakeFileNameCompatible(GScanDetails[aDataIndex].ScanPath) + '_' +
                    TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.htm';

  GReportHTML.GenerateHTMLReport(aDataIndex, HTMLr, '');

  if HTMLr.HTMLAutoOpen then
    miOpenLastReportClick(Nil);
end;


procedure TfrmMain.BuildOpenCSVReport(CSVr : TCSVReportOptions);
var
  lCSVOutput : TStringList;

begin
  CSVr.Filename := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\csv\quick\' +
                   TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' +
                   TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.csv';

  lCSVOutput := TStringList.Create;

  GReportCSV.GenerateCSVReport(FSource, lCSVOutput, CSVr, LayoutQuick);

  FreeAndNil(lCSVOutput);

  if CSVr.CSVAutoOpen then
    miOpenLastReportClick(Nil);
end;


procedure TfrmMain.BuildOpenTextReport(Textr : TTextReportOptions);
var
  lCSVOptions  : TCSVReportOptions;
  lHTMLOptions : THTMLReportOptions;
  lXinOptions  : TXinorbisReportOptions;
  lXMLOptions  : TXMLReportOptions;
  lTreeOptions : TTreeReportOptions;

begin
  Textr.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\text\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

  FrameReports[FSource].SaveReports(Textr, lCSVOptions, lHTMLOptions, lXinOptions, lXMLOptions, lTreeOptions);

  miOpenLastReportClick(Nil);
end;


procedure TfrmMain.BuildOpenTreeReport(Treer : TTreeReportOptions);
var
  lReportOutput : TStringList;

begin
  if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
    ShowXDialog(XText[rsWarning], XText[rsPleaseWaitFolderHistory], XDialogTypeXinorbis);
  end
  else begin
    Treer.FileName := GSystemGlobal.AppDataPath + 'reports\' + TXWindows.GetComputerNetName + '\tree\quick\' + TXFormatting.MakeFileNameCompatible(GScanDetails[FSource].ScanPath) + '_' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + '_' + TUtility.GetTime(GETTIMEFORMAT_FILE) + '.txt';

    lReportOutput := TStringList.Create;

    if GReportTree.GenerateTreeReport(FSource, lReportOutput, Treer) then
      GReportUtility.SetLastReport(FSource, Treer.Filename, GScanDetails[FSource].ScanPath, ReportTree, LayoutUnknown);

    FreeAndNil(lReportOutput);

    miOpenLastReportClick(Nil);
  end;
end;


procedure TfrmMain.iSideMenuWelcomeClick(Sender: TObject);
 begin
  Assert(sender <> nil, 'iSideMenuWelcomeClick :: Nil TImage');

  if TPanel(TImage(Sender).Parent).Height = TImage(Sender).Tag then begin
    TPanel(TImage(Sender).Parent).Height := 22;
  end
  else begin
    TPanel(TImage(Sender).Parent).Height := TImage(Sender).Tag;
  end;
end;


procedure TfrmMain.SetSidePanelDisplay(welcomeID, taskID, tasksubID, canAddToHistory : integer);
 begin
  SetWelcomeDisplay(welcomeID);

  DoWelcome(welcomeID);

  DoTask(taskID, tasksubID);

  if canAddToHistory = 1 then begin
    if welcomeID <> -1 then
      AddToPageNavigationHistory('W' + IntToStr(welcomeID));

    if taskID <> -1 then
      AddToPageNavigationHistory('T' + IntToStr(taskID));
  end;

  if (taskID = -1) and (welcomeID = -1) then begin
    HandleResizing(pMainPanelIndex);

    FrameSelect.BringToFront;
  end;

  UpdateLeftPanelStatus;
end;


procedure TfrmMain.DoWelcome(aWelcomeID : integer);
begin
  if aWelcomeID <> -1 then begin
    case aWelcomeID of
      1 : begin
            HandleResizing(pScanSelectionPanelIndex);

            FrameSelect.pScanSelection.BringToFront;
          end;
      2 : begin
            HandleResizing(pMainFileHistoryPanelIndex);
            FrameFolderHistory.BringToFront;

            FrameFolderHistory.AvailableComputerChange;
          end;
      5 : begin
            HandleResizing(pMainWebReportsPanelIndex);
            FrameWebReports.BringToFront;
          end;
    end;

    if XSettings.System.Tutorial then
      OnTutorialBarChange(GSystemGlobal.ExePath + 'data\languages\' +
                                                TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
                                                '\tutorial\w' + IntToStr(aWelcomeID) + '.dat');
  end;
end;


procedure TfrmMain.DoTask(aTaskID, aTaskSubID : integer);
begin
  if aTaskID < 99 then
    SetTasksDisplay(aTaskID);

  if aTaskID <> NullEntry then begin

    case aTaskID of
       1 : begin
             HandleResizing(pMainSummaryPanelIndex);
             FrameSummary[FSource].BringToFront;
           end;
       2 : begin
             HandleResizing(pMainReportsPanelIndex);
             FrameReports[FSource].BringToFront;

             if aTaskSubID <> NullEntry then
               FrameReports[FSource].pMainReports.ActivePageIndex := aTaskSubID;
           end;
       3 : begin
             if (GUpdateFolderHistoryUpdateThread <> Nil) then begin
               ShowXDialog(XText[rsWarning], XText[rsPleaseWaitFolderHistory], XDialogTypeXinorbis);
             end
             else begin
               HandleResizing(pMainNavigationPanelIndex);
               FrameNavigation[FSource].BringToFront;

               if XSettings.System.JustInTimeProcessed[FSource, TabNavigation] = False then begin
                 case FSource of
                   dataLatestScan    : GScanDetails[FSource].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathLS));
                   dataFolderHistory : GScanDetails[FSource].Files.Sort(TComparer<TFileObject>.Construct(CompareFileNamePathFH));
                 end;

                 FrameNavigation[FSource].BuildNavigationTab;

                 FrameNavigation[FSource].SelectAndDblClick(1, 1);

                 XSettings.System.JustInTimeProcessed[FSource, TabNavigation] := True;
               end;
             end;
           end;
       4 : begin
             HandleResizing(pMainSearchPanelIndex);

             FrameSearch.Source := FSource;
             FrameSearch.SetTab(0);
             FrameSearch.BringToFront;
           end;
       5 : begin
             HandleResizing(pMainMapPanelIndex);

             UpdateFrameMap;

             FrameMap.BringToFront;
           end;
       6 : begin
             HandleResizing(pMainSearchPanelIndex);

             FrameSearch.Source := FSource;
             FrameSearch.SetTab(2);
             FrameSearch.BringToFront;
           end;
       7 : begin
             HandleResizing(pMainSearchPanelIndex);

             FrameSearch.Source := FSource;
             FrameSearch.SetTab(3);
             FrameSearch.BringToFront;
           end;
       8 : begin
             HandleResizing(pMainExploderPanelIndex);

             UpdateFrameExploder;

             FrameExploder.BringToFront;
           end;
    end;

    if XSettings.System.Tutorial then
      OnTutorialBarChange(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
                                                  '\tutorial\t' + IntToStr(aTaskID) + '.dat');
  end;
end;


procedure TfrmMain.SetWelcomeDisplay(welcomeID : integer);
 var
  t : integer;

 begin
  for t := 1 to SideMenuWelcomeCount do begin
    if t <> welcomeID then begin
      WelcomeOptions[t].Font.Style := [];
    end;
  end;

  if (welcomeID <> -1) and (welcomeID <= SideMenuWelcomeCount) then
    WelcomeOptions[welcomeID].Font.Style := [fsBold];
end;


procedure TfrmMain.SetTasksDisplay(taskID : integer);
 var
  t : integer;

 begin
  for t := 1 to SideMenuTasksCount do begin
    if t <> taskID then begin
      TaskOptions[t].Font.Style := [];
    end;
  end;

  if taskID <> -1 then
    TaskOptions[taskID].Font.Style := [fsBold];
end;


procedure TfrmMain.UpdateLeftPanelStatus;
 var
  status : boolean;
  t : integer;

 begin
  if GScanDetails[FSource].Files.Count = 0 then
    status := False
  else
    status := True;

  // =========================================================================
  // == Tasks Panel ==========================================================
  // =========================================================================

  for t:= 1 to 5 do
    TaskOptions[t].Enabled   := status;

  // =========================================================================
  // == Advanced Panel =======================================================
  // =========================================================================

  AdvancedOptions[1].Enabled := status;
  AdvancedOptions[2].Enabled := status;
  AdvancedOptions[3].Enabled := status;

  // =========================================================================
  // == Quick Reports ========================================================
  // =========================================================================

  if FrameSearch.Visible then begin
    GXGuiUtil.SetButtonImageEnabled(tbReportSummary, CReportOffStart, False);
    GXGuiUtil.SetButtonImageEnabled(tbReportTree,    CReportOffStart, False);
  end
  else begin
    GXGuiUtil.SetButtonImageEnabled(tbReportSummary, CReportOffStart, status);
    GXGuiUtil.SetButtonImageEnabled(tbReportTree,    CReportOffStart, status);
  end;

  GXGuiUtil.SetButtonImageEnabled(tbReportCSV,       CReportOffStart, status);
  GXGuiUtil.SetButtonImageEnabled(tbReportHTML,      CReportOffStart, status);
  GXGuiUtil.SetButtonImageEnabled(tbReportText,      CReportOffStart, status);
  GXGuiUtil.SetButtonImageEnabled(tbReportXML,       CReportOffStart, status);
  GXGuiUtil.SetButtonImageEnabled(tbReportXinorbis,  CReportOffStart, status);
end;


procedure TfrmMain.Searchmanual1Click(Sender: TObject);
begin
  THelp.OpenSearchManual;
end;


procedure TfrmMain.SetAdvancedDisplay(advancedID : integer);
 var
  t : integer;

 begin
  for t := 1 to SideMenuAdvancedCount do begin
    if t <> advancedID then begin
      AdvancedOptions[t].Font.Style := [];
    end;
  end;

  if advancedID <> -1 then
    AdvancedOptions[advancedID].Font.Style := [fsBold];
end;


procedure TfrmMain.lTaskID1Click(Sender: TObject);
var
  cl : string;

begin
  Assert(Sender <> Nil, 'lTaskID1Click :: nil caller!');

  case TLabel(Sender).Tag of
    0 : SetSidePanelDisplay(NullEntry, 1, NullEntry, 1);
    1 : SetSidePanelDisplay(NullEntry, 2, NullEntry, 1);
    2 : SetSidePanelDisplay(NullEntry, 3, NullEntry, 1);
    3 : begin
          cl := Copy(NavigationHistory[NavigationHistory.Count - 1], 1, 2);

          SetSidePanelDisplay(NullEntry, 4, NullEntry, 1);
        end;
    4 : begin
          SetSidePanelDisplay(NullEntry, 5, NullEntry, 1);
        end;
    5 : begin
          SetSidePanelDisplay(NullEntry, 6, NullEntry, 1);
        end;
    6 : begin
          SetSidePanelDisplay(NullEntry, 7, NullEntry, 1);
        end;
    7 : begin
          SetSidePanelDisplay(NullEntry, 8, NullEntry, 1);
        end;
  end;
end;


procedure TfrmMain.lTutorialDblClick(Sender: TObject);
 begin
  miTutorialClick(Nil);
end;


procedure TfrmMain.sbNewScanClick(Sender: TObject);
 begin
  HandleResizing(pScanSelectionPanelIndex);
  FrameSelect.pScanSelection.BringToFront;

  SetSidePanelDisplay(1, NullEntry, NullEntry, 1);
end;


procedure TfrmMain.tbHomeClick(Sender: TObject);
 begin
  sbNewScanClick(Nil);
end;


procedure TfrmMain.tbPrivacyClick(Sender: TObject);
 begin
  if tbPrivacy.Tag = 0 then begin
    tbPrivacy.Tag                    := 1;
    XSettings.Database.PrivacyActive := True;
    tbPrivacy.ImageIndex             := 4;

    tbPrivacy.Hint                   := XText[rsHintM4] + ' [' + XText[rsEnabled] + ']';
  end
  else begin
    tbPrivacy.Tag                    := 0;
    XSettings.Database.PrivacyActive := False;
    tbPrivacy.ImageIndex             := 3;

    tbPrivacy.Hint                   := XText[rsHintM4] + ' [' + XText[rsDisabled] + ']';
  end;
end;


procedure TfrmMain.tbToggleFHClick(Sender: TObject);
 begin
  if XSettings.System.UserEnabledFH then begin
    tbToggleFH.ImageIndex := 5;

    tbToggleFH.Hint       := XText[rsHintM5] + ' [' + XText[rsDisabled] + ']';

    XSettings.System.UserEnabledFH := False;
  end
  else begin
    tbToggleFH.ImageIndex := 6;

    tbToggleFH.Hint       := XText[rsHintM5] + ' [' + XText[rsEnabled] + ']';

    XSettings.System.UserEnabledFH := True;
  end;
end;


procedure TfrmMain.tbToggleVirtualClick(Sender: TObject);
begin
  if XSettings.System.UserEnabledVirtual then begin
    tbToggleVirtual.ImageIndex := 16;

    tbToggleVirtual.Hint       := XText[rsIgnoreVirtualFolders] + ' [' + XText[rsEnabled] + ']';

    XSettings.System.UserEnabledVirtual := False;

    GXinorbisScan.AllowVirtual          := False;
  end
  else begin
    tbToggleVirtual.ImageIndex := 15;

    tbToggleVirtual.Hint       := XText[rsIgnoreVirtualFolders] + ' [' + XText[rsDisabled] + ']';

    XSettings.System.UserEnabledVirtual := True;

    GXinorbisScan.AllowVirtual          := True;
  end;
end;

procedure TfrmMain.lWelcomeFolderHistoryMouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if ssLeft in shift then
    SetSidePanelDisplay(2, NullEntry, NullEntry, 1)
  else if ssMiddle in shift then
     miReportBrowserClick(nil);
end;


procedure TfrmMain.lWelcomeWebReportsClick(Sender: TObject);
 begin
  SetSidePanelDisplay(5, NullEntry, NullEntry, 1);
end;


procedure TfrmMain.miAddXinorbistoExplorerToContextMenuClick(Sender: TObject);
 begin
  TXWindows.AddXinorbisToContextMenu;
end;


procedure TfrmMain.AddToPageNavigationHistory(const pagedata : string);
 begin
  if (NavigationHistory[NavigationHistory.Count - 1]) <> pagedata then begin // stop duplicates
    NavigationHistory.Add(pagedata);

    tbNavigatePrevious.Enabled := True;

    tbHome.Tag := NavigationHistory.Count - 1;
  end;
end;


procedure TfrmMain.miHelpCatsClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'http://xinorbis.com/catware.htm', '', '');
end;


procedure TfrmMain.DoNavigationHistoryAction(const navaction : string);
var
  htaskID, hwelcomeID : integer;

begin
  htaskID    := -1;
  hwelcomeID := -1;

  case navaction[1] of
    'W' : hwelcomeID := StrToInt(navaction[2]);
    'T' : htaskID    := StrToInt(navaction[2]);
    'H' : hwelcomeID := 1;                     // open Welcome option 1 (scan folder)
  end;

  SetSidePanelDisplay(hwelcomeID, htaskID, NullEntry, 0);
end;


procedure TfrmMain.tbNavigatePreviousClick(Sender: TObject);
 begin
  if tbHome.Tag > 0 then begin
    tbHome.Tag := tbHome.Tag - 1;

    if tbHome.Tag = 0 then
      tbNavigatePrevious.Enabled := False;

    tbNavigateNext.Enabled := True;

    DoNavigationHistoryAction(NavigationHistory[tbHome.Tag]);
  end;
end;


procedure TfrmMain.tbNavigateNextClick(Sender: TObject);
 begin
  if tbHome.Tag < NavigationHistory.Count - 1 then begin

    tbHome.Tag := tbHome.Tag + 1;

    if tbHome.Tag >= NavigationHistory.Count - 1 then
      tbNavigateNext.Enabled := False;

    tbNavigatePrevious.Enabled := True;

    DoNavigationHistoryAction(NavigationHistory[tbHome.Tag]);
  end;
end;


procedure TfrmMain.lHelpSendFeedbackClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'mailto:xinorbis@maximumoctopus.com?Subject=Xinorbis Feedback', '', '');
end;


procedure TfrmMain.BuildSummary(aDataIndex, aFileCatMode : integer);
var
  zSize, zCount, t : integer;
  lDirList          : TAdvStringGrid;

begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 1), 'BuildSummary :: invalid dataindex :: ' +inttostr(aDataindex));

  lDirList := FrameReports[aDataIndex].sgDirList;

//  if XSettings.Debug then frmLog.AddToLog('BuildSummary : ' + IntToStr(DataIndex) + '/' + IntToStr(GScanDetails[DataIndex].Files.Count) + '/' + IntToStr(GScanDetails[DATAINDEX].FileCount) + '/' + IntToStr(GScanDetails[DATAINDEX].TotalSize));

  //
  if GScanDetails[aDataIndex].FileCount <> 0 then
  begin
    sbMain.Panels[0].Text := '<b>' + IntToStr(GScanDetails[aDataIndex].FileCount) + '</b> ' + XText[rsFiles] + '  ::  ' +
                             '<b>' + IntToStr(GScanDetails[aDataIndex].FolderCount) + '</b> ' + XText[rsFolders] + '  ::  ' +
                             XText[rsSize] + ': <b>' + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].TotalSize) + '</b>';
  end
  else
  begin
    sbMain.Panels[0].Text := '<b>' + IntToStr(GScanDetails[aDataIndex].FileCount) + '</b> ' + XText[rsFiles] + '  ::  ' +
                             '<b>' + IntToStr(GScanDetails[aDataIndex].FolderCount) + '</b> ' + XText[rsFolders] + '  ::  ' +
                             XText[rsSize] + ': <b>' + TConvert.ConvertToUsefulUnit(GScanDetails[aDataIndex].TotalSize) + '</b>';
  end;

  FrameSummary[aDataIndex].BuildPreamble;

  // == files and folder =======================================================

  FrameSummary[aDataIndex].BuildFileFolders(GScanDetails[aDataIndex].FileAttributes[FileType_Null, 0],
                                            GScanDetails[aDataIndex].FileAttributes[FileType_NullFolder, 0]);

  //-- largest folder ----------------------------------------------------------

  zSize  := 1;
  zCount := 1;

  for t := 1 to FrameReports[aDataIndex].sgDirList.RowCount - 1 do begin
    if StrToInt(lDirList.Cells[2, t]) > StrToInt(lDirList.Cells[2, zCount])    then zCount := t;

    if StrToInt64(lDirList.Cells[8, t]) > StrToInt64(lDirList.Cells[8, zSize]) then zSize  := t;
  end;

  FrameSummary[aDataIndex].BuildLargestFile(FrameReports[aDataIndex].sgDirList.Cells[1, zSize], lDirList.Cells[5, zSize], TXFormatting.ReplaceEntities(lDirList.Cells[6, zSize]),
                                            FrameReports[aDataIndex].sgDirList.Cells[1, zCount], lDirList.Cells[2, zCount], TXFormatting.ReplaceEntities(lDirList.Cells[3, zCount]));

  FrameSummary[aDataIndex].SetChart(FrameSummary[aDataIndex].gSLDCount, StrToInt64(lDirList.Cells[2, zCount]), GScanDetails[aDataIndex].FileCount);
  FrameSummary[aDataIndex].SetChart(FrameSummary[aDataIndex].gSLDSize,  StrToInt64(lDirList.Cells[8, zSize]),  GScanDetails[aDataIndex].TotalSize);

  //-- largest file ------------------------------------------------------------
  FrameSummary[aDataIndex].lLFx.HTMLText[0] := FrameReports[aDataIndex].sgTop50Big.Cells[0, 1] + ' (<b>' + FrameReports[aDataIndex].sgTop50Big.Cells[1, 1] + '</b>)';

  if (GScanDetails[aDataIndex].TotalSize <> 0) and (FrameReports[aDataIndex].sgTop50Big.Cells[3, 1] <> '') then
    FrameSummary[aDataIndex].gSLF.SetDisplay((StrToInt64(FrameReports[aDataIndex].sgTop50Big.Cells[3, 1]) / GScanDetails[aDataIndex].TotalSize) * 100)
  else
    FrameSummary[aDataIndex].gSLF.SetDisplay(100);

  // == User stuff =============================================================

  if GScanDetails[aDataIndex].Users.Count <> 0 then begin
    zSize  := 1;
    zCount := 1;

    for t := 1 to FrameReports[aDataIndex].sgUsers.RowCount - 1 do begin
      if StrToInt(FrameReports[aDataIndex].sgUsers.Cells[2, t]) > StrToInt(FrameReports[aDataIndex].sgUsers.Cells[2, zCount]) then    zCount := t; // quantity of files

      if StrToInt64(FrameReports[aDataIndex].sgUsers.Cells[7, t]) > StrToInt64(FrameReports[aDataIndex].sgUsers.Cells[7, zSize]) then zSize  := t; // size of files
    end;

    FrameSummary[aDataIndex].lLUxSize.HTMLText[0]  := FrameReports[aDataIndex].sgUsers.Cells[1, zSize] + ' (<b>' + FrameReports[aDataIndex].sgUsers.Cells[5, zCount] + '</b>, <b>' + FrameReports[aDataIndex].sgUsers.Cells[6, zSize] + '</b>)';
    FrameSummary[aDataIndex].lLUxCount.HTMLText[0] := FrameReports[aDataIndex].sgUsers.Cells[1, zCount] + ' (<b>' + FrameReports[aDataIndex].sgUsers.Cells[2, zCount] + '</b>, <b>' + FrameReports[aDataIndex].sgUsers.Cells[3, zCount] + '</b>)';

    FrameSummary[aDataIndex].SetChart(FrameSummary[aDataIndex].gSLUCount, StrToInt64(FrameReports[aDataIndex].sgUsers.Cells[2, zCount]), GScanDetails[aDataIndex].FileCount);
    FrameSummary[aDataIndex].SetChart(FrameSummary[aDataIndex].gSLUSize,  StrToInt64(FrameReports[aDataIndex].sgUsers.Cells[7, zSize]),  GScanDetails[aDataIndex].TotalSize);
  end
  else begin
    FrameSummary[aDataIndex].lLUxSize.HTMLText[0]  := '-';
    FrameSummary[aDataIndex].lLUxCount.HTMLText[0] := '-';

    FrameSummary[aDataIndex].gSLUSize.SetDisplay(0);
    FrameSummary[aDataIndex].gSLUCount.SetDisplay(0);
  end;

  // == build file category stuffz =============================================

  FrameSummary[aDataIndex].BuildCapacityBars(aDataIndex);

  // == drive details ==========================================================

  FrameSummary[aDataIndex].BuildDriveSection(aDataIndex);
end;


procedure TfrmMain.IfScanCancelled(aDataIndex : integer);
 begin
  TMSLogger.Info('Scan cancelled');

  GScanDetails[aDataIndex].ClearAll;

  FrameReports[aDataIndex].ClearEverything;

  tbHomeClick(Nil);
end;


procedure TfrmMain.sgReportListCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
 begin
  if (Acol = 1) then begin
    DoSort := False;

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction := sdAscending
      else
        SortSettings.Direction := sdDescending;

      Sortsettings.Column := 5;
      QSort;

      SortSettings.Column := Acol;
    end;
  end
  else if (Acol = 2) then begin
    DoSort := False;

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction := sdAscending
      else
        SortSettings.Direction := sdDescending;

      Sortsettings.Column := 6;
      QSort;

      SortSettings.Column := Acol;
    end;
  end
end;


procedure TfrmMain.AnaylseDataThreadOnTerminate(Sender : TObject);
 begin
//  AnalyseDataThread := Nil;
end;


procedure TfrmMain.RequestNewScan(aDataIndex : integer; aFromFile : boolean; const aNewPath : string);
begin
  if aFromFile then begin
    if Pos('.zsr2', aNewPath) <> 0 then
      XinorbisScan(aDataIndex, '', aNewPath, ScanTypeNormal, ScanSourceFileXin2Detailed)
    else if Pos('.zsr', aNewPath) <> 0 then
      XinorbisScan(aDataIndex, '', aNewPath, ScanTypeNormal, ScanSourceFileXinDetailed)
    else
      BuildMainFromCSV(aDataIndex, aNewPath);
  end
  else
    XinorbisScan(aDataIndex, aNewPath, '', ScanTypeNormal, ScanSourceLive);
end;


procedure TfrmMain.ScanFromFolderHistory(const aScanPath, aTableName : string; aFileHistoryDate : string);
begin
  XinorbisScan(dataFolderHistory, aScanPath, aTableName, ScanTypeNormal, ScanSourceFolderHistory);

  GScanDetails[dataFolderHistory].ScanDateFHStr := aFileHistoryDate;
end;


procedure TfrmMain.ReportOptions1Click(Sender: TObject);
begin
  DoReportSettings(-1);
end;


procedure TfrmMain.RequestNewCombineScan(const aStatus : integer);
begin
  CombineScan;
end;


procedure TfrmMain.RequestNewSummary(aDataIndex : integer; const aAutoOpen : integer);
begin
  BuildSummary(aDataIndex, 0);
end;


procedure TfrmMain.RequestNewFHPath(const aPath : string);
begin
  if aPath <> '' then begin
    lWelcomeFolderHistoryMouseDown(lWelcomeFolderHistory, mbLeft, [ssLeft], 0, 0);

    FrameFolderHistory.SelectedPath := aPath;
  end;
end;


procedure TfrmMain.RequestNewSearch(aDataIndex : integer; const aNewSearch : string);
begin
  SetSidePanelDisplay(NullEntry, 4, NullEntry, 1);
  // make sure to set menu and show search frame ^ ?

  FrameSearch.DoSearch(aNewSearch);
end;


function  TfrmMain.OnGetLeftOffset: integer;
begin
  Result := Left + pNavigation.Width + 5;
end;


function  TfrmMain.OnGetTopOffset: integer;
begin
  Result := Top + pNavigation.Top;
end;


function  TfrmMain.IsFolderHistoryRunning: boolean;
begin
  Result := GUpdateFolderHistoryUpdateThread <> Nil;
end;


procedure TfrmMain.ScanOnFoundNull(aDataIndex : integer; const aFileName : string);
begin
  FrameReports[aDataIndex].AddNullFolder(aFileName);

  inc(GScanDetails[aDataIndex].FileAttributes[FileType_NullFolder, 0]);
end;


procedure TfrmMain.ScanOnFoundTemp(aDataIndex : integer; const aFileName, aSizeWords, aSize : string);
begin
  FrameReports[aDataIndex].AddTempFile(aFileName, aSizeWords, aSize);
end;


procedure TfrmMain.ScanOnProgress(const aCount : integer);
begin
  XSettings.Forms.ProgressForm.SetStatus3(IntToStr(aCount));
end;


procedure TfrmMain.ClearLanguage1Click(Sender: TObject);
begin
  {$IFDEF debug}
  XSettings.CurrentLanguage := LanguageUNDEFINED;
  {$ENDIF}
end;


procedure TfrmMain.UpdateFrameMap;
var
  t : integer;
  lDataSource : integer;

begin
  lDataSource := FSource;

  if lDataSource <> FrameMap.DataSource then
    FrameMap.ClearMap;

  // ====================================================================

  if not(FrameMap.HasData) then begin
    FrameMap.BeginData;

    for t:= 1 to FrameReports[lDataSource].sgDirList.RowCount - 1 do begin
      FrameMap.AddData(FrameReports[lDataSource].sgDirList.Cells[1, t],
                       StrToInt(FrameReports[lDataSource].sgDirList.Cells[2, t]),
                       StrToInt64(FrameReports[lDataSource].sgDirList.Cells[8, t]),
                       spectrumcolours[(t - 1) mod spectrummod]);
    end;

    FrameMap.EndData;
  end;
end;


procedure TfrmMain.UpdateFrameExploder;
var
  t : integer;
  lDataSource : integer;

begin
  lDataSource := FSource;

  if lDataSource <> FrameExploder.DataSource then
    FrameExploder.ClearExploder;

  // ====================================================================

  if not(FrameExploder.HasData) then begin

    FrameExploder.BeginData(GScanDetails[lDataSource].ScanPath, -1, -1); // -1 for initial data set

    for t:= 1 to FrameReports[lDataSource].sgDirList.RowCount - 1 do begin
      FrameExploder.AddData(FrameReports[lDataSource].sgDirList.Cells[1, t],
                            GScanDetails[lDataSource].GetFolderIndex(FrameReports[lDataSource].sgDirList.Cells[1, t]),
                            StrToInt(FrameReports[lDataSource].sgDirList.Cells[2, t]),
                            StrToInt64(FrameReports[lDataSource].sgDirList.Cells[8, t]),
                            spectrumcolours[(t - 1) mod spectrummod]);
    end;

    FrameExploder.EndData;
  end;
end;


procedure TfrmMain.NewSourceAvailable(aSource : integer);
begin
  case aSource of
    dataLatestScan    : begin
                          tbSourceLive.Enabled := True;

                          tbSourceLiveClick(Nil);
                        end;

    dataFolderHistory : begin
                          tbSourceFolderHistory.Enabled := True;

                          tbSourceFolderHistoryClick(Nil);
                        end;
  end;
end;


procedure TfrmMain.ActivateSource(aSource : integer);
begin
  case aSource of
    dataLatestScan    : begin
                          DeactivateSource(dataFolderHistory);

                          tbSourceLive.Color   := clMoneyGreen;
                          tbSourceLive.ColorTo := clNone;
                        end;

    dataFolderHistory : begin
                          DeactivateSource(dataLatestScan);

                          tbSourceFolderHistory.Color   := clMoneyGreen;
                          tbSourceFolderHistory.ColorTo := clNone;
                        end;
  end;

  UpdateMainMenu;

  DoNavigationHistoryAction(NavigationHistory[tbHome.Tag]);
end;


procedure TfrmMain.DeactivateSource(aSource : integer);
begin
  case aSource of
    dataLatestScan    : begin
                          tbSourceLive.Color   := clBtnFace;
                          tbSourceLive.ColorTo := clNone;
                        end;

    dataFolderHistory : begin
                          tbSourceFolderHistory.Color   := clBtnFace;
                          tbSourceFolderHistory.ColorTo := clNone;
                        end;
  end;
end;


procedure TfrmMain.DoUpdateBalloon;
begin
  if GSystemGlobal.NewVersionAvailable then begin
    trayIcon.BalloonHint := XText[rsANewVersionIsAvailable];

    trayIcon.ShowBalloonHint;
  end
end;


procedure TfrmMain.UpdateMainMenu;
var
  lStatus : boolean;

begin
  miOpenLastReport.Enabled            := (GReportUtility.LastReportFilename <> '');
  miCopyLastReportToClipboard.Enabled := (GReportUtility.LastReportFilename <> '');

  lStatus := (GScanDetails[FSource].Files.Count <> 0);

  miHTMLReport.Enabled            := lStatus;
  miXMLReport.Enabled             := lStatus;
  miCSVReport.Enabled             := lStatus;
  miTextReport.Enabled            := lStatus;
  miXinorbisReport.Enabled        := lStatus;
  miTreeReport.Enabled            := lStatus;

  miSaveReports.Enabled           := lStatus;
  miSearchMain.Enabled            := lStatus;
  miSearchWizard.Enabled          := lStatus;

  miDFileSize.Enabled             := lStatus;
  miDDuplicatesName.Enabled       := lStatus;
  miDDuplicatesSize.Enabled       := lStatus;
  miMoreFolderDetail.Enabled      := lStatus;
  miFileAges.Enabled              := lStatus;

  miTabTable.Enabled              := lStatus;
  miTabTree.Enabled               := lStatus;
  miTabOther.Enabled              := lStatus;
  miTabFolders.Enabled            := lStatus;
  miTabMagnitude.Enabled          := lStatus;
  miTabFileDates.Enabled          := lStatus;
  miTabHistory.Enabled            := lStatus;
  miTabTop50.Enabled              := lStatus;
  miTabNullFiles.Enabled          := lStatus;
  miTabUsers.Enabled              := lStatus;
  miTabTemp.Enabled               := lStatus;
  miTabNameLength.Enabled         := lStatus;
end;


end.
