//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameFolderHistory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameFolderHistory *FrameFolderHistory;
//---------------------------------------------------------------------------
__fastcall TFrameFolderHistory::TFrameFolderHistory(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------


#pragma region Tab_Stats_Chart
void __fastcall TFrameFolderHistory::sbFHCF1Click(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Tab_Stats_Table
#pragma end_region


#pragma region Tab_Stats_TimeLine
#pragma end_region


#pragma region Tab_Search_FHCompare
#pragma end_region


#pragma region Tab_Search_CompareFolder
#pragma end_region


#pragma region Tab_Search_CompareFolderTree
#pragma end_region


#pragma region Popup_Charts
void __fastcall TFrameFolderHistory::miCOSaveClick(TObject *Sender)
{
/*  mychart : TChart;
  lFileName : string;

 begin
  lFileName := TXSaveDialog.ExecuteImages(TUtility.GetDefaultFileName('.png', XText[rsChart]));

  if lFileName <> '' then begin
	mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

	TChartUtility.SaveChartToPNG(mychart, lFileName);
  end; */
}


void __fastcall TFrameFolderHistory::miCOCopyClick(TObject *Sender)
{
/*  mychart : TChart;

 begin
  mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  TChartUtility.CopyChartToClipboard(mychart);*/
}


void __fastcall TFrameFolderHistory::miCOAdvancedClick(TObject *Sender)
{ /*
  mychart : TChart;
  tceo    : TChartOptions;

  mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  tceo := XSettings.Charts.Options;

  tceo.ChartType := TChartUtility.GetChartType(mychart);

  // ===========================================================================

  tceo := DoAdvancedChartOptions(tceo);

  // ===========================================================================

  if tceo.Result = 1 then begin
	TChartUtility.SetAdvancedOptions(mychart, tceo);

	if Assigned(FChartsHaveChanged) then
	  FChartsHaveChanged;
  end;                          */
}
#pragma end_region


#pragma region Popup_CompareSave
void __fastcall TFrameFolderHistory::puFHCompareSavePopup(TObject *Sender)
{
/*  status : boolean;

  function DoExist(sg : TAdvStringGrid): integer;
   var
	t : integer;

   begin
	Result := 0;

	for t := 1 to sg.RowCount - 1 do begin
	  if sg.Cells[FHschCategory, t] = '1' then inc(Result);
	end
  end;

  function DontExist(sg : TAdvStringGrid): integer;
   var
	t : integer;

   begin
	Result := 0;

	for t := 1 to sg.RowCount - 1 do begin
	  if sg.Cells[FHschCategory, t] = '2' then inc(Result);
	end
  end;

 begin
  miFHCSSaveDo.Caption   := XText[rsSaveDoExist];
  miFHCSSaveDont.Caption := XText[rsSaveDontExist];

  case TSpeedbutton(Tpopupmenu(Sender).PopupComponent).Tag of
	1 : begin
		  if sbFHCShowLeft.Tag = 0 then
			status := False
		  else begin
			status := True;

			miFHCSSaveDo.Caption   := XText[rsSaveDoExist] + ' (' + IntToStr(DoExist(sgFHCompareLeft)) + ')';
			miFHCSSaveDont.Caption := XText[rsSaveDontExist] + ' (' + IntToStr(DontExist(sgFHCompareLeft)) + ')';
		  end;

          miFHCSSaveDo.Enabled   := status;
		  miFHCSSaveDont.Enabled := status;
		end;
	2 : begin
          if sbFHCShowRight.Tag = 0 then
			status := False
          else begin
			status := True;

			miFHCSSaveDo.Caption   := XText[rsSaveDoExist] + ' (' + IntToStr(DoExist(sgFHCompareRight)) + ')';
			miFHCSSaveDont.Caption := XText[rsSaveDontExist] + ' (' + IntToStr(DontExist(sgFHCompareRight)) + ')';
          end;

		  miFHCSSaveDo.Enabled     := status;
          miFHCSSaveDont.Enabled   := status;
		end;
  end;        */
}


void __fastcall TFrameFolderHistory::miFHCSSaveAllClick(TObject *Sender)
{    /*
	case TSpeedbutton(Tpopupmenu(Sender).PopupComponent).Tag of
	1 : TGridUtility.SaveFHStringGridData(sgFHCompareLeft,  eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	2 : TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	}  */
}


void __fastcall TFrameFolderHistory::miFHCSSaveDoClick(TObject *Sender)
{       /*
	case TSpeedbutton(Tpopupmenu(Sender).PopupComponent).Tag of
	1 : TGridUtility.SaveFHStringGridData(sgFHCompareLeft,  eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	2 : TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	} */
}


void __fastcall TFrameFolderHistory::miFHCSSaveDontClick(TObject *Sender)
{          /*
	case TSpeedbutton(Tpopupmenu(Sender).PopupComponent).Tag of
	1 : TGridUtility.SaveFHStringGridData(sgFHCompareLeft,  eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	2 : TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	} */
}
#pragma end_region


#pragma region Popup_GenericTable
void __fastcall TFrameFolderHistory::puGenericTablePopup(TObject *Sender)
{
/*  lTable : TAdvStringGrid;
  lStatus : boolean;

begin
  if not(XSettings.ProcessWindowsVisible) then begin
	lTable := TAdvStringGrid(Tpopupmenu(Sender).PopupComponent);

	if (lTable.Cells[0, 1] = '') and (lTable.Cells[1, 1] = '') then
	  lStatus := False
	else
	  lStatus := True;

	miGenericExport.Enabled        := lStatus;
	miGenericClipboard.Enabled     := lStatus;
	miGenericClipboardHTML.Enabled := lStatus;
  end; */
}


void __fastcall TFrameFolderHistory::miGenericExportClick(TObject *Sender)
{
/*  grid : TAdvStringGrid;
  lFileName : string;

begin
  grid      := TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  lFileName := TXSaveDialog.ExecuteReports(TUtility.GetDefaultFileName('.csv', XText[rsSearch] + '_' + XText[rsExport]));

  if lFileName <> '' then begin
	TGridUtility.SaveGrid(grid, lFileName);
  end; */
}


void __fastcall TFrameFolderHistory::miGenericClipboardClick(TObject *Sender)
{
/*  grid : TAdvStringGrid;

  grid := TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  grid.CopyToClipBoard; */
}


void __fastcall TFrameFolderHistory::miGenericClipboardHTMLClick(TObject *Sender)
{
/*  grid : TAdvStringGrid;

  grid := TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  grid.CopyToClipBoardAsHTML; */
}
#pragma end_region


#pragma region Popup_QuickSearch
#pragma end_region


#pragma region Popup_SelectDate
#pragma end_region


#pragma region TimeLine
/*void TFrameFolderHistory::BuildTimeLine;
var
  t : integer;
  lRangeFrom, lRangeTo : TDateTime;

begin
  if FolderHistory.Count <> 0 then begin
    lRangeFrom := Now;
    lRangeTo   := EncodeDate(1975, 01, 01);

    atlFolderHistory.BeginUpdate;

    atlFolderHistory.RangeAppearance.DivisionFormat := TConvert.GetDateFormat + ' hh:nn';

    atlFolderHistory.TimeLineIndicators.Clear;

    for t := 0 to FolderHistory.Count - 1 do begin
      with atlFolderHistory.TimeLineIndicators.Add do begin
        Shape           := isDiamond;

        Position        := FolderHistory[t].ScanDate;

        AnnotationColor := spectrumcolours[t mod spectrummod];

        Color           := clWhite;
        ColorTo         := AnnotationColor;

        Annotation      := IntToStr(FolderHistory[t].FileCount) + ' ' + XText[rsFiles] + ' (' + TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSize) + ')';

        Fixed           := True;

        Tag             := t;

        if odd(t) then
          AnnotationPosition := apOnTop
        else
          AnnotationPosition := apAtBottom;

        if FolderHistory[t].ScanDate < lRangeFrom then
          lRangeFrom := FolderHistory[t].ScanDate;

        if FolderHistory[t].ScanDate > lRangeTo then
          lRangeTo := FolderHistory[t].ScanDate;
      end;
    end;

    atlFolderHistory.EndUpdate;

    atlFolderHistory.Range.MinimumRange := IncDay(lRangeFrom, -7);
    atlFolderHistory.Range.MaximumRange := IncDay(lRangeTo, 7);

    atlFolderHistory.Range.RangeFrom    := lRangeFrom;
    atlFolderHistory.Range.RangeTo      := lRangeTo;

    oldTLFrom := lRangeFrom;
    oldTLTo   := lRangeTo;

    sbTLResetClick(nil);
  end;
end;             */
#pragma end_region



/*
const
  __ChartCount = 1;


type
  TFrameFolderHistory = class(TFrame)
    puCharts: TPopupMenu;
    miChartOptions: TMenuItem;
    N9: TMenuItem;
    miCOSave: TMenuItem;
    miCOCopy: TMenuItem;
    miCOAdvanced: TMenuItem;
    puGenericTable: TPopupMenu;
    miGenericClipboard: TMenuItem;
    miGenericClipboardHTML: TMenuItem;
    puFHCompareSave: TPopupMenu;
    miFHCSSaveAll: TMenuItem;
    miFHCSSaveDo: TMenuItem;
    miFHCSSaveDont: TMenuItem;
    ilTabs: TImageList;
    puFHSelectDate: TPopupMenu;
    ilToggle: TImageList;
    puFHQuickSearch: TPopupMenu;
    miGenericExport: TMenuItem;
    tpFHMain: TAdvSmoothTabPager;
    tsFHMainStatus: TAdvSmoothTabPage;
    Panel46: TPanel;
    lFHAvailablePath: TLabel;
    sbFHFolderInfo: TSpeedButton;
    lFHAvailableComputer: TLabel;
    sbFHGetDate: TSpeedButton;
    llFHPleaseWait: TLabel;
    sbFHOpenFolder: TAeroButton;
    cbFHAvailableComputer: TComboBox;
    cbFHAvailablePath: TComboBox;
    bFHISelect: TBitBtn;
    cbFHAvailableFilter: TComboBox;
    tpFHStats: TAdvSmoothTabPager;
    tsFHChart: TAdvSmoothTabPage;
    Panel42: TPanel;
    clbFolderHistory: TCheckListBox;
    Panel19: TPanel;
    lFHCCategory: TLabel;
    sbFHCF1: TSpeedButton;
    sbFHCF6: TSpeedButton;
    sbFHCF7: TSpeedButton;
    sbFHCF2: TSpeedButton;
    sbFHCF3: TSpeedButton;
    sbFHCF8: TSpeedButton;
    sbFHCF9: TSpeedButton;
    sbFHCF4: TSpeedButton;
    sbFHCF5: TSpeedButton;
    sbFHCF10: TSpeedButton;
    sbFHCF15: TSpeedButton;
    sbFHCF20: TSpeedButton;
    sbFHCF19: TSpeedButton;
    sbFHCF14: TSpeedButton;
    sbFHCF13: TSpeedButton;
    sbFHCF18: TSpeedButton;
    sbFHCF17: TSpeedButton;
    sbFHCF12: TSpeedButton;
    sbFHCF11: TSpeedButton;
    sbFHCF16: TSpeedButton;
    Image36: TImage;
    Panel51: TPanel;
    lFHCFiles: TLabel;
    lFHCMagnitude: TLabel;
    Image35: TImage;
    rbFHCount: TAdvOfficeRadioButton;
    rbFHSize: TAdvOfficeRadioButton;
    rbFHMagCount: TAdvOfficeRadioButton;
    rbFHMagSize: TAdvOfficeRadioButton;
    Panel52: TPanel;
    lFHFolderCount: TLabel;
    lFHFolders: TLabel;
    lFHCFilesCount: TLabel;
    lFHFileCount: TLabel;
    lFHCTotalSize: TLabel;
    lFHFileSize: TLabel;
    vtcFolderHistory: TChart;
    tsFHTable: TAdvSmoothTabPage;
    Panel1: TPanel;
    rbFJTRToday: TAdvOfficeRadioButton;
    rbFJTRPrevious: TAdvOfficeRadioButton;
    sgFHTable: TAdvStringGrid;
    tsFHTimeLine: TAdvSmoothTabPage;
    tsFHMainSearch: TAdvSmoothTabPage;
    tsFHSearch: TAdvSmoothTabPager;
    tsFHCompare: TAdvSmoothTabPage;
    tsFHCompareFolder: TAdvSmoothTabPage;
    tsFHCompareFolder2: TAdvSmoothTabPage;
    Panel3: TPanel;
    sbTLReset: TSpeedButton;
    lFHTLUnderCursor: TLabel;
    lFHTLIndicatorDetails: THTMLabel;
    sbTLSave: TSpeedButton;
    atlFolderHistory: TAdvSmoothTimeLine;
    pFHCompare: TPanel;
    sbFHCompareFavourites: TSpeedButton;
    sbFHCompareSearch: TSpeedButton;
    lFHCompareSize: TLabel;
    sbFHCSearchSyntax: TSpeedButton;
    SpeedButton4: TSpeedButton;
    cbFHCompareUnits: TComboBox;
    eFHCompareSearch: TComboBox;
    cbFHComparePath: TAdvOfficeCheckBox;
    cbFHCompareColour: TAdvOfficeCheckBox;
    Panel14: TPanel;
    Panel32: TPanel;
    sbFHCLHideSOD: TSpeedButton;
    sbFHCLHideAttributes: TSpeedButton;
    sbFHCLHideOwner: TSpeedButton;
    sbFHCLHideModified: TSpeedButton;
    sbFHCLHideAccessed: TSpeedButton;
    sbFHCLHideCreated: TSpeedButton;
    sbFHCompareLeftSave: TSpeedButton;
    sbFHCShowLeft: TSpeedButton;
    SpeedButton21: TSpeedButton;
    lFHCompareLeft: THTMLabel;
    bFHCompareLeft: TBitBtn;
    sgFHCompareLeft: TAdvStringGrid;
    Panel17: TPanel;
    lCLShowing: TLabel;
    lCLPageNumber: TLabel;
    W7NavigationFrame1: TW7NavigationFrame;
    lCLPagePrevious: TW7NavigationButton;
    lCLPageNext: TW7NavigationButton;
    Splitter2: TAdvSplitter;
    Panel15: TPanel;
    Panel11: TPanel;
    sbFHCRHideCreated: TSpeedButton;
    sbFHCRHideAccessed: TSpeedButton;
    sbFHCRHideModified: TSpeedButton;
    sbFHCRHideOwner: TSpeedButton;
    sbFHCRHideAttributes: TSpeedButton;
    sbFHCRHideSOD: TSpeedButton;
    sbFHCompareRightSave: TSpeedButton;
    sbFHCShowRight: TSpeedButton;
    SpeedButton22: TSpeedButton;
    lFHCompareRight: THTMLabel;
    bFHCompareRight: TBitBtn;
    sgFHCompareRight: TAdvStringGrid;
    Panel30: TPanel;
    lCRShowing: TLabel;
    lCRPageNumber: TLabel;
    W7NavigationFrame2: TW7NavigationFrame;
    lCRPageNext: TW7NavigationButton;
    lCRPagePrevious: TW7NavigationButton;
    Panel4: TPanel;
    sbFHCompareFolderSearch: TSpeedButton;
    sbfhCompareDriveFavourites: TSpeedButton;
    sbSearchSyntax: TSpeedButton;
    eFHCompareDriveFolder: TComboBox;
    cbFHCompareFolderInclude: TAdvOfficeCheckBox;
    Panel48: TPanel;
    SpeedButton1: TSpeedButton;
    Panel54: TPanel;
    Panel55: TPanel;
    sbFHCompareFolder2LeftSaveClick: TSpeedButton;
    SpeedButton3: TSpeedButton;
    bFHCompareTreeLeft: TBitBtn;
    tvFHTLeft: THTMLTreeview;
    Splitter7: TAdvSplitter;
    Panel56: TPanel;
    Panel57: TPanel;
    sbFHCompareFolder2RightSaveClick: TSpeedButton;
    SpeedButton6: TSpeedButton;
    bFHCompareTreeRight: TBitBtn;
    tvFHTRight: THTMLTreeview;
    Splitter6: TPanel;
    Panel45: TPanel;
    sbFHCompareFolderLeftSave: TSpeedButton;
    SpeedButton16: TSpeedButton;
    lFHCDLeft: THTMLabel;
    bFHCompareFolderLeft: TBitBtn;
    sgFHCDLeft: TAdvStringGrid;
    splitterFHCD: TAdvSplitter;
    Panel49: TPanel;
    Panel53: TPanel;
    sbFHCompareFolderRightSave: TSpeedButton;
    SpeedButton33: TSpeedButton;
    lFHCDRight: THTMLabel;
    bFHCompareFolderRight: TBitBtn;
    sgFHCDRight: TAdvStringGrid;
    procedure sbFHOpenFolderClick(Sender: TObject);
    procedure cbFHAvailablePathChange(Sender: TObject);
    procedure sbFHFolderInfoClick(Sender: TObject);
    procedure cbFHAvailableComputerChange(Sender: TObject);
    procedure sbFHGetDateClick(Sender: TObject);
    procedure bFHISelectClick(Sender: TObject);
    procedure sbFHBuildInformationTabsClick(Sender: TObject);
    procedure lFHCFilesClick(Sender: TObject);
    procedure rbFHCountClick(Sender: TObject);
    procedure rbFJTRTodayClick(Sender: TObject);
    procedure sgFHTableDrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure sgFileHistoryCanSort(Sender: TObject; ACol: Integer;
      var DoSort: Boolean);
    procedure sbFHCompareFavouritesClick(Sender: TObject);
    procedure sbFHCompareSearchClick(Sender: TObject);
    procedure eFHCompareSearchChange(Sender: TObject);
    procedure eFHCompareSearchKeyPress(Sender: TObject; var Key: Char);
    procedure cbFHCompareColourClick(Sender: TObject);
	procedure SpeedButton21Click(Sender: TObject);
    procedure bFHCompareLeftClick(Sender: TObject);
    procedure sbFHCompareLeftSaveClick(Sender: TObject);
    procedure bFHCompareRightClick(Sender: TObject);
    procedure sbFHCompareRightSaveClick(Sender: TObject);
    procedure sgFHCompareLeftDrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure sgFHCompareRightDrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure sbFHCompareFolderSearchClick(Sender: TObject);
    procedure eFHCompareDriveFolderKeyPress(Sender: TObject; var Key: Char);
    procedure bFHCompareFolderLeftClick(Sender: TObject);
    procedure bFHCompareFolderRightClick(Sender: TObject);
    procedure sbFHCompareFolderLeftSaveClick(Sender: TObject);
    procedure sgFHCDLeftCanSort(Sender: TObject; ACol: Integer;
      var DoSort: Boolean);
    procedure sgFHCDLeftDrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure SpeedButton1Click(Sender: TObject);
    procedure bFHCompareTreeLeftClick(Sender: TObject);
    procedure bFHCompareTreeRightClick(Sender: TObject);
    procedure sbFHCompareFolder2LeftSaveClickClick(Sender: TObject);
    procedure tvFHTLeftExpanding(Sender: TObject; Node: TTreeNode;
      var AllowExpansion: Boolean);
    procedure tvFHTRightExpanding(Sender: TObject; Node: TTreeNode;
      var AllowExpansion: Boolean);
    procedure tpFHStatsChange(Sender: TObject);
    procedure Splitter2Moved(Sender: TObject);
    procedure puFHCompareSavePopup(Sender: TObject);
    procedure miCOSaveClick(Sender: TObject);
    procedure miCOCopyClick(Sender: TObject);
    procedure miCOAdvancedClick(Sender: TObject);
    procedure miCGradientToSelectClick(Sender: TObject);
    procedure miFHCSSaveAllClick(Sender: TObject);
    procedure miFHCSSaveDoClick(Sender: TObject);
    procedure miFHCSSaveDontClick(Sender: TObject);
    procedure miGenericExportClick(Sender: TObject);
    procedure miGenericClipboardClick(Sender: TObject);
    procedure miGenericClipboardHTMLClick(Sender: TObject);
    procedure miCCustomToClick(Sender: TObject);
    procedure sbFHCShowLeftClick(Sender: TObject);
    procedure sbFHCShowRightClick(Sender: TObject);
    procedure sbFHCF1Click(Sender: TObject);
    procedure sbFHCLHideCreatedClick(Sender: TObject);
    procedure sbFHCRHideCreatedClick(Sender: TObject);
    procedure splitterFHCDMoved(Sender: TObject);
    procedure miQuickSearchClick(Sender: TObject);
    procedure splitFHDirListCanResize(Sender: TObject; var NewSize: Integer;
      var Accept: Boolean);
    procedure tpFHStatsResize(Sender: TObject);
    procedure sbTLResetClick(Sender: TObject);
    procedure atlFolderHistoryMouseMove(Sender: TObject;
      Shift: TShiftState; X, Y: Integer);
    procedure atlFolderHistoryIndicatorClick(Sender: TObject;
      indicator: TAdvSmoothTimeLineBarIndicator);
    procedure atlFolderHistoryDblClick(Sender: TObject);
    procedure sbTLSaveClick(Sender: TObject);
    procedure sgFHTableGetCellColor(Sender: TObject; ARow, ACol: Integer;
      AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
    procedure puGenericTablePopup(Sender: TObject);
    procedure cbFHAvailableFilterChange(Sender: TObject);
    procedure sgFHTableGetAlignment(Sender: TObject; ARow, ACol: Integer;
      var HAlign: TAlignment; var VAlign: TVAlignment);
    procedure sgFHCompareLeftGetAlignment(Sender: TObject; ARow, ACol: Integer;
      var HAlign: TAlignment; var VAlign: TVAlignment);
    procedure sgFHCDLeftGetAlignment(Sender: TObject; ARow, ACol: Integer;
      var HAlign: TAlignment; var VAlign: TVAlignment);
    procedure SpeedButton4Click(Sender: TObject);
  private
    FHCatButtons  : array[0..19] of TSpeedButton;
    FCharts       : array[1..__ChartCount] of TChart;

    FOnUpdateLeftStatusPanel  : TUpdateLeftStatusPanel;
    FSetStatusBarText         : TSetStatusBarText;
    FSetTutorialBarText       : TSetTutorialBarText;
    FOnExtSetSidePanelDisplay : TExtSetSidePanelDisplay;
    FOnProcessWindowProgress  : TProcessWindowProgress;
    FOnProcessWindowStatus    : TProcessWindowStatus;
    FOnOpenSettingsTab        : TOpenSettingsTab;
    FOpenSearchWizard         : TOpenSearchWizard;
    FOnResetDisplay           : TOnResetDisplay;
    FScanFromFolderHistory    : TScanFromFolderHistory;
    FOnUpdateHistoryFinished  : TUpdateHistoryFinished;
    FChartsHaveChanged        : TChartsHaveChanged;

    FGetLeftOffset            : TGetLeftOffset;
    FGetTopOffset             : TGetTopOffset;

    FIsFHUpdateThreadRunning : TIsFHUpdateThreadRunning;

    FQuickCompareA : THashedStringList;
    FQuickCompareB : THashedStringList;

    oldTLFrom, oldTLTo : TDateTime;

    LastSQL : array[2..3] of string;

    procedure LoadSettings;
    procedure SetTheme;

    procedure RepairFile(const scanpath, FileName : string);

    procedure CompareFolderLeftThreadOnTerminate(Sender : TObject);
    procedure CompareFolderRightThreadOnTerminate(Sender : TObject);
    procedure CompareLeftThreadOnTerminate(Sender : TObject);
    procedure CompareRightThreadOnTerminate(Sender : TObject);

    procedure FHCompareFolderBuildLeft(Sender : TObject);
    procedure FHCompareFolderBuildRight(Sender : TObject);

    function  FindFolderHistoryItem(const xItem : string): integer;

    procedure FileHistoryControlStatus(newstatus : boolean);
    procedure miSelectDateTimeClick(Sender: TObject);

    // property funcs
    function  GetSelectedPath: string;
    procedure SetSelectedPath(aPath : string);
    function  GetSelectedComputer: string;

    function  GetFolderHistoryItem(Index: integer): string;
    function  GetFolderHistoryItemSelected: string;

    function  GetActivePage: integer;
    procedure SetActivePage(aNewPage : integer);
  public
    procedure Init;
    procedure DeInit;
    procedure InitUpdate;
    procedure InitHints;
    procedure InitDisplayDoOnce;
    procedure SaveSettings;

    function  GetAvailablePathContains(aPath : string): boolean;
    procedure SetSelectedPathWithoutExecute(aPath : string);

    procedure ResetDisplay(aDisableBuildInformationTabs, aMode : boolean);
    procedure BuildFolderHistoryTable;
    procedure BuildTimeLine;

    procedure FHCompareBuildLeft(Sender : TObject);
    procedure FHCompareBuildRight(Sender : TObject);

    procedure BuildFolderHistory(const ComputerName, ScanPath : string);
    procedure BuildFolderHistoryAvailable;
    procedure BuildFolderHistorySelectDataMenu;

    procedure AvailableComputerChange;

    procedure DoFHSearch(aSearchTerm : string);
    procedure DoCompareSearch(aSearchTerm : string);
    procedure DoCompareDriveSearch(aSearchTerm : string);

    procedure SetTableRowHeights;

    function SaveReports(var TextOptions : TTextReportOptions; var CSVOptions  : TCSVReportOptions;
                         var HTMLOptions : THTMLReportOptions; var XinOptions  : TXinorbisReportOptions;
                         var XMLOptions  : TXMLReportOptions;  var TreeOptions : TTreeReportOptions): boolean;

    property SelectedPath                     : string                  read  GetSelectedPath           write SetSelectedPath;
    property SelectedComputer                 : string                  read  GetSelectedComputer;
    property FolderHistoryItem[Index: integer]: string                  read  GetFolderHistoryItem;
    property FolderHistoryItemSelected        : string                  read  GetFolderHistoryItemSelected;
    property ActivePage                       : integer                 read  GetActivePage             write SetActivePage;
    property OnExtSetSidePanelDisplay         : TExtSetSidePanelDisplay read  FOnExtSetSidePanelDisplay write FOnExtSetSidePanelDisplay;
    property OnProcessWindowProgressChange    : TProcessWindowProgress  read  FOnProcessWindowProgress  write FOnProcessWindowProgress;
    property OnProcessWindowStatusChange      : TProcessWindowStatus    read  FOnProcessWindowStatus    write FOnProcessWindowStatus;
    property OnSettingsTab                    : TOpenSettingsTab        read  FOnOpenSettingsTab        write FOnOpenSettingsTab;
    property OnUpdateLeftStatusPanel          : TUpdateLeftStatusPanel  read  FOnUpdateLeftStatusPanel  write FOnUpdateLeftStatusPanel;
    property OnSetStatusBarText               : TSetStatusBarText       read  FSetStatusBarText         write FSetStatusBarText;
    property OnSetTutorialBarText             : TSetTutorialBarText     read  FSetTutorialBarText       write FSetTutorialBarText;
    property OnOpenSearchWizard               : TOpenSearchWizard       read  FOpenSearchWizard         write FOpenSearchWizard;
    property OnResetDisplay                   : TOnResetDisplay         read  FOnResetDisplay           write FOnResetDisplay;
    property OnScanFromFolderHistory          : TScanFromFolderHistory  read  FScanFromFolderHistory    write FScanFromFolderHistory;
    property OnUpdateHistoryFinished          : TUpdateHistoryFinished  read  FOnUpdateHistoryFinished  write FOnUpdateHistoryFinished;
    property OnChartsHaveChanged              : TChartsHaveChanged      read  FChartsHaveChanged        write FChartsHaveChanged;

    property GetLeftOffset                    : TGetLeftOffset          read  FGetLeftOffset            write FGetLeftOffset;
    property GetTopOffset                     : TGetTopOffset           read  FGetTopOffset             write FGetTopOffset;

    property IsFHUpdateThreadRunning          : TIsFHUpdateThreadRunning read FIsFHUpdateThreadRunning write FIsFHUpdateThreadRunning;

    property QuickCompareA                    : THashedStringList       read  FQuickCompareA            write FQuickCompareA;
    property QuickCompareB                    : THashedStringList       read  FQuickCompareB            write FQuickCompareB;
  end;

var
  FrameFolderHistory : TFrameFolderHistory;


implementation

{$R *.dfm}

uses
  System.UITypes, System.Contnrs, Registry,

  X.Form.ShowCalendar, X.Form.Explore, X.Form.DBSelectedFolder, X.Dialogs.Save, X.Dialogs.Colour, X.Form.ShowMD5,
  X.Dialogs.Dialog, X.Conversions,

  X.Database, X.MD5, X.ZipFiles, X.FileExtension, X.FileExtensionsObject, X.Prescan,

  X.Constants, X.GlobalObjects, X.GuiUtil,

  X.GridUtility, X.ChartUtility, X.DisplayUtility, X.Utility,
  X.Form.ChartOptions, X.TreeUtility, X.SearchUtility,

  X.CFolderHistoryObject, X.Global, X.Settings,

  X.Frame.Search, X.Frame.Select, X.CSizeOfFolder,

  X.Thread.CompareFolderLeft, X.Thread.CompareFolderRight,
  X.Thread.CompareLeft, X.Thread.CompareRight;


const
  CLeft  = 0;
  CRight = 1;

  CSectionFiles    = 0;
  CSectionCategory = 1;

  CCompareLeft        = 0;
  CCompareRight       = 1;
  CCompareFolderLeft  = 2;
  CCompareFolderRight = 3;
  CCompareTreeLeft    = 4;
  CCompareTreeRight   = 5;

  CompareColoursX : array[1..2] of integer = ($00FFFFFF, $0070b7fe);

  FHCCImageBase : array[0..19] of integer = (  5,  7,  9, 11, 13, 15, 17, 19, 21, 23,
                                              25, 27, 29, 31, 33, 35, 37, 39, 41, 43);


//    QuickCompareA.Free;
//  QuickCompareB.Free;

{$region init}
procedure TFrameFolderHistory.Init;
var
  t, lWidth : integer;
  lFA : array[0..2] of string;

begin
  lFA[0] := XText[rsCreated];
  lFA[1] := XText[rsAccessed];
  lFA[2] := XText[rsModified];

  FCharts[1] := vtcFolderHistory;

  // ===========================================================================

  miFHCSSaveAll.Caption  := XText[rsSaveAll];
  miFHCSSaveDo.Caption   := XText[rsSaveDoExist];
  miFHCSSaveDont.Caption := XText[rsSaveDontExist];

  // ===========================================================================

  miGenericExport.Caption        := XText[rsExportContent] + rsEllipsis;
  miGenericClipboard.Caption     := XText[rsCopyTableToClipboard];
  miGenericClipboardHTML.Caption := XText[rsSaveAs] + ' HTML';;

  // ===========================================================================

  miChartOptions.Caption         := XText[rsChartOptions];
  miCOSave.Caption               := XText[rsSaveChart];
  miCOCopy.Caption               := XText[rsCopyChartToClipboard];
  miCOAdvanced.Caption           := XText[rsAdvancedOptions];

  // ===========================================================================

  cbFHCompareUnits.Clear;

  cbFHCompareFolderInclude.Caption := XText[rsIncludeFullPath];

  tsFHMainStatus.Caption := 'Stats' + '        ';
  tsFHMainSearch.Caption := XText[rsSearch] + '        ';

  tsFHChart.Caption := XText[rsChart] + '        ';
  tsFHTable.Caption := XText[rsTable] + '        ';
  lFHCTotalSize.Caption := XText[rsTotalSize] + ':';


  rbFHSize.Caption               := XText[rsBySize];
  rbFHMagSize.Caption            := XText[rsBySize];

  rbFHCount.Caption                := XText[rsByQuantity];
  rbFHMagCount.Caption             := XText[rsByQuantity];

  lFHCompareSize.Caption := XText[rsSize];
  lFHCompareSize.Caption   := XText[rsSize];

  cbFHComparePath.Caption  := XText[rsShowFullPath];

  lFHFolderCount.Caption  := XText[rsFolders] + ':';
  lFHCMagnitude.Caption     := XText[rsMagnitude];

  sbFHOpenFolder.Caption:= XText[rsOpen];

  cbFHCompareColour.Caption       := XText[rsColourCode];
  llFHPleaseWait.Caption := XText[rsLoadingFileHistoryData] + rsEllipsis;

  rbFJTRToday.Caption:= XText[rsRelativeToToday];
  rbFJTRPrevious.Caption := XText[rsRelativeToPrevious];
  tsFHCompare.Caption := XText[rsFileHistoryCompare] + '        ';

  lFHAvailableComputer.Caption  := XText[rsFolderHistoryComputer];
  lFHAvailablePath.Caption      := XText[rsFolderHistoryFolder];

  lWidth := Max(lFHAvailableComputer.Width, lFHAvailablePath.Width);

  cbFHAvailableComputer.Left    := lFHAvailableComputer.Left + lWidth + 8;
  cbFHAvailableFilter.Left      := lFHAvailablePath.Left + lWidth + 8;
  cbFHAvailablePath.Left        := cbFHAvailableFilter.Left + 58;
  sbFHFolderInfo.Left           := cbFHAvailablePath.Left + cbFHAvailablePath.Width + 8;

  bFHISelect.Caption            := XText[rsSelectScanDateTime];
  bFHCompareLeft.Caption        := XText[rsSelectScanDateTime];
  bFHCompareRight.Caption       := XText[rsSelectScanDateTime];
  bFHCompareFolderLeft.Caption  := XText[rsSelectScanDateTime];
  bFHCompareFolderRight.Caption := XText[rsSelectScanDateTime];
  bFHCompareTreeLeft.Caption    := XText[rsSelectScanDateTime];
  bFHCompareTreeRight.Caption   := XText[rsSelectScanDateTime];

  tsFHCompareFolder.Caption  := XText[rsCompareFolder] + '        ';
  tsFHCompareFolder2.Caption := XText[rsCompareFolderTree] + '        ';

  lFHCFiles.Caption      := XText[rsFiles] + ':';
  lFHCCategory.Caption   := XText[rsCategory] + ':';
  lFHCFilesCount.Caption := XText[rsFiles] + ':';

  cbFHCompareUnits.Items.Add(XText[rsMostConvenient]);
  cbFHCompareUnits.Items.Add(XText[rsBytes]);
  cbFHCompareUnits.Items.Add(XText[rsKilobytes]);
  cbFHCompareUnits.Items.Add(XText[rsMegabytes]);

  FQuickCompareA := THashedStringList.Create;
  FQuickCompareB := THashedStringList.Create;

  tsFHTimeLine.Caption := XText[rsTimeLine] + '        ';

  tsFHMainSearch.TabVisible := False;

  GXGuiUtil.SetButtonOffImage(sbFHCLHideCreated,    CImageCreated);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideAccessed,   CImageAccessed);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideModified,   CImageModified);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideOwner,      CImageOwner);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideAttributes, CImageAttributes);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideSOD,        CImageSizeOnDisk);

  GXGuiUtil.SetButtonOffImage(sbFHCRHideCreated,    CImageCreated);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideAccessed,   CImageAccessed);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideModified,   CImageModified);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideOwner,      CImageOwner);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideAttributes, CImageAttributes);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideSOD,        CImageSizeOnDisk);

  GXGuiUtil.SetButtonOffImage(sbFHCShowLeft, 8);
  GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);

  InitDisplayDoOnce;

  if XSettings.FHCompare[1, 1] then sbFHCLHideCreatedClick(sbFHCLHideCreated);
  if XSettings.FHCompare[1, 2] then sbFHCLHideCreatedClick(sbFHCLHideAccessed);
  if XSettings.FHCompare[1, 3] then sbFHCLHideCreatedClick(sbFHCLHideModified);
  if XSettings.FHCompare[1, 4] then sbFHCLHideCreatedClick(sbFHCLHideOwner);
  if XSettings.FHCompare[1, 5] then sbFHCLHideCreatedClick(sbFHCLHideAttributes);
  if XSettings.FHCompare[1, 6] then sbFHCLHideCreatedClick(sbFHCLHideSOD);

  if XSettings.FHCompare[2, 1] then sbFHCRHideCreatedClick(sbFHCRHideCreated);
  if XSettings.FHCompare[2, 2] then sbFHCRHideCreatedClick(sbFHCRHideAccessed);
  if XSettings.FHCompare[2, 3] then sbFHCRHideCreatedClick(sbFHCRHideModified);
  if XSettings.FHCompare[2, 4] then sbFHCRHideCreatedClick(sbFHCRHideOwner);
  if XSettings.FHCompare[2, 5] then sbFHCRHideCreatedClick(sbFHCRHideAttributes);
  if XSettings.FHCompare[2, 6] then sbFHCRHideCreatedClick(sbFHCRHideSOD);

  FHCatButtons[0]:=sbFHCF1;   FHCatButtons[1]:=sbFHCF2;   FHCatButtons[2]:=sbFHCF3;   FHCatButtons[3]:=sbFHCF4;   FHCatButtons[4]:=sbFHCF5;
  FHCatButtons[5]:=sbFHCF6;   FHCatButtons[6]:=sbFHCF7;   FHCatButtons[7]:=sbFHCF8;   FHCatButtons[8]:=sbFHCF9;   FHCatButtons[9]:=sbFHCF10;
  FHCatButtons[10]:=sbFHCF11; FHCatButtons[11]:=sbFHCF12; FHCatButtons[12]:=sbFHCF13; FHCatButtons[13]:=sbFHCF14; FHCatButtons[14]:=sbFHCF15;
  FHCatButtons[15]:=sbFHCF16; FHCatButtons[16]:=sbFHCF17; FHCatButtons[17]:=sbFHCF18; FHCatButtons[18]:=sbFHCF19; FHCatButtons[19]:=sbFHCF20;

  for t := 0 to __FileCategoriesCount do begin
    GXGuiUtil.SetFolderHistoryButtonImage(FHCatButtons[t], FHCCImageBase[t]);

    FHCatButtons[t].Hint := FHCatButtons[t].Hint + ' (' + TypeDescriptionsSmall[t] + ')';
  end;

  cbFHCompareUnits.ItemIndex := 0;

  SetTheme;

  InitUpdate;
end;


procedure TFrameFolderHistory.DeInit;
begin
  FQuickCompareA.Free;
  FQuickCompareB.Free;
end;


procedure TFrameFolderHistory.InitUpdate;
var
  i : integer;

begin
  SetTableRowHeights;

  for i := 1 to __ChartCount do begin
    TChartUtility.SetAdvancedOptions(FCharts[i], XSettings.Charts.Options);
  end;
end;


procedure TFrameFolderHistory.InitHints;
begin
  sbFHCLHideCreated.Hint    := XText[rsHint1];
  sbFHCRHideAccessed.Hint   := XText[rsHint1];
  sbFHCLHideAccessed.Hint   := XText[rsHint2];
  sbFHCRHideAccessed.Hint   := XText[rsHint2];
  sbFHCLHideModified.Hint   := XText[rsHint3];
  sbFHCRHideModified.Hint   := XText[rsHint3];
  sbFHCLHideOwner.Hint      := XText[rsHint4];
  sbFHCRHideOwner.Hint      := XText[rsHint4];
  sbFHCLHideAttributes.Hint := XText[rsHint5];
  sbFHCRHideAttributes.Hint := XText[rsHint5];
  sbFHCLHideSOD.Hint        := XText[rsHint6];
  sbFHCRHideSOD.Hint        := XText[rsHint6];
  sbFHCShowLeft.Hint        := XText[rsHint8];
  sbFHCShowRight.Hint       := XText[rsHint8];
end;


procedure TFrameFolderHistory.SetTheme;
begin
  TThemeHelper.SetSmoothTabPager(tpFHMain);
  TThemeHelper.SetSmoothTabPager(tpFHStats);
  TThemeHelper.SetSmoothTabPager(tsFHSearch);

  TThemeHelper.SetSmoothTabPage(tsFHMainStatus);
  TThemeHelper.SetSmoothTabPage(tsFHMainSearch);
  TThemeHelper.SetSmoothTabPage(tsFHChart);
  TThemeHelper.SetSmoothTabPage(tsFHTable);
  TThemeHelper.SetSmoothTabPage(tsFHTimeLine);
  TThemeHelper.SetSmoothTabPage(tsFHCompare);
  TThemeHelper.SetSmoothTabPage(tsFHCompareFolder);
  TThemeHelper.SetSmoothTabPage(tsFHCompareFolder2);
end;
{$endregion}


procedure TFrameFolderHistory.LoadSettings;
var
  t, lChart : integer;
  s : string;
  lReg : TRegistry;

begin
  XSettings.OpenSettings(True);

  if (XSettings.customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
    for t := 1 to MaximumFolderHistory do begin
      s := XSettings.ReadStringFromSettings('Prefs', 'FHSearchTerm' + IntToStr(t), '');
   //   if s <> '' then
    //    eFHSearch.Items.Add(s);

      s := XSettings.ReadStringFromSettings('Prefs', 'FHSearchCompareTerm' + IntToStr(t), '');
      if s <> '' then
        eFHCompareSearch.Items.Add(s);
    end;
  end
  else begin
    lReg := TRegistry.Create(KEY_READ);

    try
      lReg.RootKey := HKEY_CURRENT_USER;
      lReg.OpenKey('\software\' + XinorbisRegistryKey + '\FHSearchTerm', True);

      t := 0;
      While lReg.ValueExists('Term' + IntToStr(t)) do begin
     //   eFHSearch.Items.Add(lReg.ReadString('Term' + IntToStr(t)));
        inc(t);
      end;
    finally
      lReg.Free;
    end;

    lReg := TRegistry.Create(KEY_READ);

    try
      lReg.RootKey := HKEY_CURRENT_USER;
      lReg.OpenKey('\software\' + XinorbisRegistryKey + '\FHCompareSearchTerm', True);

      t := 0;
      While lReg.ValueExists('Term' + IntToStr(t)) do begin
        eFHCompareSearch.Items.Add(lReg.ReadString('Term' + IntToStr(t)));
        inc(t);
      end;
    finally
      lReg.Free;
    end;
  end;

  // ===========================================================================

  for t := 1 to __ChartCount do begin
    lChart := XSettings.ReadIntegerFromSettings('Charts', 'FileHistory_' + IntToStr(t), 0, -1);

    TChartUtility.SetChartType(FCharts[t], lChart);
  end;

  XSettings.CloseSettings;
end;


procedure TFrameFolderHistory.SaveSettings;
var
  t : integer;
  lReg : TRegistry;

begin
  XSettings.OpenSettings(False);

  XSettings.WriteBoolToSettings('FHCompare', 'X1Y1', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideCreated.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y2', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideAccessed.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y3', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideModified.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y4', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideOwner.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y5', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideAttributes.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y6', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideSOD.Tag));

  XSettings.WriteBoolToSettings('FHCompare', 'X2Y1', sgFHCompareRight.IsHiddenColumn(sbFHCRHideCreated.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y2', sgFHCompareRight.IsHiddenColumn(sbFHCRHideAccessed.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y3', sgFHCompareRight.IsHiddenColumn(sbFHCRHideModified.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y4', sgFHCompareRight.IsHiddenColumn(sbFHCRHideOwner.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y5', sgFHCompareRight.IsHiddenColumn(sbFHCRHideAttributes.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y6', sgFHCompareRight.IsHiddenColumn(sbFHCRHideSOD.Tag));

  if (XSettings.customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
  {  if eFHSearch.Items.Count <> 0 then begin
      for t := 0 to eFHSearch.Items.Count - 1 do begin
        XSettings.WriteStringToSettings('Prefs', 'FHSearchTerm' + IntToStr(t + 1), eFHSearch.Items[t]);
      end;
    end;    }

    if eFHCompareSearch.Items.Count <> 0 then begin
      for t := 0 to eFHCompareSearch.Items.Count - 1 do begin
        XSettings.WriteStringToSettings('Prefs', 'FHSearchCompareTerm' + IntToStr(t + 1), eFHCompareSearch.Items[t]);
      end;
    end;
  end
  else begin
   { if eFHSearch.Items.Count <> 0 then begin
      lReg := TRegistry.Create(KEY_WRITE);

      try
        lReg.RootKey := HKEY_CURRENT_USER;
        lReg.OpenKey('\software\' + XinorbisRegistryKey + '\FHSearchTerm', True);

        for t := 0 to eFHSearch.Items.Count - 1 do
          if t < 20 then lReg.WriteString('Term' + IntToStr(t), eFHSearch.Items[t]);
      finally
       lReg.Free;
      end;
    end;    }

    if eFHCompareSearch.Items.Count <> 0 then begin
      lReg := TRegistry.Create(KEY_WRITE);

      try
        lReg.RootKey := HKEY_CURRENT_USER;
        lReg.OpenKey('\software\' + XinorbisRegistryKey + '\FHCompareSearchTerm', True);

        for t := 0 to eFHCompareSearch.Items.Count - 1 do
          if t < 20 then lReg.WriteString('Term' + IntToStr(t), eFHCompareSearch.Items[t]);
      finally
        lReg.Free;
      end;
    end;
  end;

  // ===========================================================================

  for t := 1 to __ChartCount do begin
    XSettings.WriteIntegerToSettings('Charts', 'FileHistory_' + IntToStr(t), TChartUtility.GetChartType(FCharts[t]));
  end;

  XSettings.CloseSettings;
end;


procedure TFrameFolderHistory.InitDisplayDoOnce ;
begin
  TGridUtility.ConfigureInfoTable(sgFHCDLeft);
  TGridUtility.ConfigureInfoTable(sgFHCDRight);

  // ===========================================================================

  sgFHTable.ColWidths[0]  := sgFHTable.Width - 603;
  sgFHTable.ColWidths[1]  := 70;
  sgFHTable.ColWidths[2]  := 70;
  sgFHTable.ColWidths[3]  := 6;
  sgFHTable.ColWidths[4]  := 70;
  sgFHTable.ColWidths[5]  := 70;
  sgFHTable.ColWidths[6]  := 6;
  sgFHTable.ColWidths[7]  := 70;
  sgFHTable.ColWidths[8]  := 70;
  sgFHTable.ColWidths[9]  := 6;
  sgFHTable.ColWidths[10] := 70;
  sgFHTable.ColWidths[11] := 70;

  // ===========================================================================

  sgFHCompareLeft.HideColumns(8, 13);

  sgFHCompareLeft.ColWidths[0] := sgFHCompareLeft.Width - 530;
  sgFHCompareLeft.ColWidths[1] := 70;
  sgFHCompareLeft.ColWidths[2] := 70;
  sgFHCompareLeft.ColWidths[3] := 70;
  sgFHCompareLeft.ColWidths[4] := 70;
  sgFHCompareLeft.ColWidths[5] := 70;
  sgFHCompareLeft.ColWidths[6] := 100;
  sgFHCompareLeft.ColWidths[7] := 55;

  // ===========================================================================

   sgFHCompareRight.HideColumns(8, 13);

  sgFHCompareRight.ColWidths[0] := sgFHCompareRight.Width - 530;
  sgFHCompareRight.ColWidths[1] := 70;
  sgFHCompareRight.ColWidths[2] := 70;
  sgFHCompareRight.ColWidths[3] := 70;
  sgFHCompareRight.ColWidths[4] := 70;
  sgFHCompareRight.ColWidths[5] := 70;
  sgFHCompareRight.ColWidths[6] := 100;
  sgFHCompareRight.ColWidths[7] := 55;

  // ===========================================================================

  LoadSettings;
end;


function TFrameFolderHistory.GetActivePage: integer;
begin
  Result := tpFHStats.ActivePageIndex;  // to do make sure new layout
end;


procedure TFrameFolderHistory.SetActivePage(aNewPage : integer);
begin
  tpFHStats.ActivePageIndex := aNewPage;        // to do make sure new layout
end;


procedure TFrameFolderHistory.SetTableRowHeights;
begin
  sgFHCompareLeft.DefaultRowHeight  := XSettings.General.RowHeight;
  sgFHCompareRight.DefaultRowHeight := XSettings.General.RowHeight;
  sgFHTable.DefaultRowHeight        := XSettings.General.RowHeight;
end;


function TFrameFolderHistory.GetAvailablePathContains(aPath : string): boolean;
begin
  if cbFHAvailablePath.Items.IndexOf(aPath) = -1 then
    Result := True
  else
    Result := False;
end;


function TFrameFolderHistory.GetSelectedPath: string;
begin
  Result := cbFHAvailablePath.Text;
end;


procedure TFrameFolderHistory.SetSelectedPath(aPath : string);
var
  t, xfound : integer;
begin
  if aPath <> '' then begin

    xfound := -1;

    cbFHAvailableComputerChange(Nil);

    for t := 0 to cbFHAvailablePath.Items.Count - 1 do begin
      if UpperCase(cbFHAvailablePath.Items[t]) = UpperCase(aPath) then
        xfound := t;
    end;

    if xfound <> -1 then begin
      cbFHAvailablePath.ItemIndex := xfound;

      sbFHOpenFolderClick(Nil);
    end;
  end;
end;


procedure TFrameFolderHistory.SetSelectedPathWithoutExecute(aPath : string);
var
  t, xfound : integer;
begin
  if aPath <> '' then begin

    xfound := -1;

    cbFHAvailableComputerChange(Nil);

    for t := 0 to cbFHAvailablePath.Items.Count - 1 do begin
      if cbFHAvailablePath.Items[t] = UpperCase(aPath) then
        xfound := t;
    end;

    if xfound <> -1 then begin
      cbFHAvailablePath.ItemIndex := xfound;
    end;
  end;
end;


function TFrameFolderHistory.GetSelectedComputer: string;
begin
  Result := cbFHAvailableComputer.Text;
end;


function TFrameFolderHistory.GetFolderHistoryItem(Index: integer): string;
begin
  if Index < clbFolderHistory.Count then
    Result := clbFolderHistory.Items[Index]
  else
    Result := '';
end;


function TFrameFolderHistory.GetFolderHistoryItemSelected: string;
begin
  Result := clbFolderHistory.Items[bFHISelect.Tag];
end;


procedure TFrameFolderHistory.bFHCompareFolderLeftClick(Sender: TObject);
begin
  puFHSelectDate.Tag := 5;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareLeft.Left + 20,
                       FGetTopOffset + Panel46.Height + Panel4.Height + Panel45.Height + 80);
end;

procedure TFrameFolderHistory.bFHCompareFolderRightClick(Sender: TObject);
begin
  puFHSelectDate.Tag := 6;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareLeft.Left + Panel49.Left + 20,
                       FGetTopOffset + Panel46.Height + Panel4.Height + Panel45.Height + 80);
end;

procedure TFrameFolderHistory.bFHCompareLeftClick(Sender: TObject);
begin
  puFHSelectDate.Tag := 2;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareLeft.Left + 20,
                       FGetTopOffset + Panel46.Height + Panel32.Height + pFHCompare.Height + 80);
end;

procedure TFrameFolderHistory.bFHCompareRightClick(Sender: TObject);
begin
  puFHSelectDate.Tag := 3;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareRight.Left + Panel15.Left ,
                       FGetTopOffset + Panel46.Height + Panel32.Height + pFHCompare.Height + 80);
end;

procedure TFrameFolderHistory.bFHCompareTreeLeftClick(Sender: TObject);
begin
  puFHSelectDate.Tag := 7;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareTreeLeft.Left + 20,
                       FGetTopOffset + Panel46.Height + Panel48.Height + Panel55.Height + 80);
end;

procedure TFrameFolderHistory.bFHCompareTreeRightClick(Sender: TObject);
begin
  puFHSelectDate.Tag := 8;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareTreeRight.Left + Panel56.Left + 20,
                       FGetTopOffset + Panel46.Height + Panel48.Height + Panel55.Height + 80);
end;

procedure TFrameFolderHistory.bFHISelectClick(Sender: TObject);
begin
  if not(XSettings.ProcessWindowsVisible) then begin
    puFHSelectDate.Tag := 1;

    puFHSelectDate.Popup(FGetLeftOffset + bFHISelect.Left + 20,
                         FGetTopOffset + 227);
  end;
end;

procedure TFrameFolderHistory.atlFolderHistoryDblClick(Sender: TObject);
begin
  sbTLResetClick(Nil);
end;


procedure TFrameFolderHistory.atlFolderHistoryIndicatorClick(
  Sender: TObject; indicator: TAdvSmoothTimeLineBarIndicator);
var
  lFHId : integer;

begin
  lFHId := indicator.Tag;

  lFHTLIndicatorDetails.HTMLText[0] := TConvert.DateToString(FolderHistory[lFHID].ScanDate) +
                                       ' @' + TConvert.TimeToString(FolderHistory[lFHID].ScanDate, True) +
                                       ' <b>' + IntToStr(FolderHistory[lFHId].FileCount) + '</b> ' + XText[rsFiles] +
                                       ' (<b>' + TConvert.ConvertToUsefulUnit(FolderHistory[lFHId].FileSize) + '</b>)';
end;


procedure TFrameFolderHistory.atlFolderHistoryMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
begin
  lFHTLUnderCursor.Caption := TConvert.DateToString(atlFolderHistory.XToDateTime(X));
end;


procedure TFrameFolderHistory.AvailableComputerChange;
begin
  cbFHAvailableComputerChange(Nil);
end;


procedure TFrameFolderHistory.cbFHAvailableComputerChange(Sender: TObject);
 var
  fha : TFolderHistoryInfo;
  t : integer;
  s : string;

 begin
  cbFHAvailableFilter.Items.Clear;
  cbFHAvailableFilter.Items.Add('*');
  cbFHAvailableFilter.Sorted := True;
  cbFHAvailablePath.Items.Clear;

  for t := 0 to FolderHistoryAvailable.Count - 1 do begin
    fha := FolderHistoryAvailable[t];

    if fha.ComputerName = cbFHAvailableComputer.Items[cbFHAvailableComputer.ItemIndex] then begin
      if (AnsiStartsStr('\\', fha.ScanPath)) then
        s := '\\'
      else
        s := Copy(fha.ScanPath, 1, 3);

      if (cbFHAvailableFilter.Items.IndexOf(s) = -1) then
        cbFHAvailableFilter.Items.Add(s);

      cbFHAvailablePath.Items.Add(fha.ScanPath);
    end;
  end;

  if (cbFHAvailablePath.Tag < cbFHAvailablePath.Items.Count) and (cbFHAvailablePath.Tag <> -1) then
    cbFHAvailablePath.ItemIndex := cbFHAvailablePath.Tag
  else begin
    cbFHAvailableFilter.ItemIndex := 0;
    cbFHAvailablePath.ItemIndex   := 0;
  end;

  cbFHAvailablePath.Refresh;
end;


procedure TFrameFolderHistory.cbFHAvailableFilterChange(Sender: TObject);
 var
  fha : TFolderHistoryInfo;
  t : integer;
  lAll : boolean;

 begin
  cbFHAvailablePath.Items.Clear;

  if cbFHAvailableFilter.Text = '*' then
    lAll := true
  else
    lAll := false;

  for t := 0 to FolderHistoryAvailable.Count - 1 do begin
    fha := FolderHistoryAvailable[t];

    if fha.ComputerName = cbFHAvailableComputer.Items[cbFHAvailableComputer.ItemIndex] then begin
      if lAll then
        cbFHAvailablePath.Items.Add(fha.ScanPath)
      else begin
        if AnsiStartsStr(cbFHAvailableFilter.Text, fha.ScanPath) then
          cbFHAvailablePath.Items.Add(fha.ScanPath)
      end;
    end;
  end;

  if (cbFHAvailablePath.Tag < cbFHAvailablePath.Items.Count) and (cbFHAvailablePath.Tag <> -1) then
    cbFHAvailablePath.ItemIndex := cbFHAvailablePath.Tag
  else
    cbFHAvailablePath.ItemIndex   := 0;

  cbFHAvailablePath.Refresh;
end;


procedure TFrameFolderHistory.cbFHAvailablePathChange(Sender: TObject);
begin
  ResetDisplay(False, False);

  cbFHAvailablePath.Tag   := cbFHAvailablePath.ItemIndex;

  bFHISelect.Caption      := XText[rsSelectDateTime];
  bFHISelect.Enabled      := False;
  bFHISelect.Tag          := -1;

  // ===========================================================================

  bFHCompareLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareRight.Caption := XText[rsSelectDateTime];
  bFHCompareLeft.Tag      := -1;
  bFHCompareRight.Tag     := -1;

  bFHCompareLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareRight.Caption := XText[rsSelectDateTime];
  bFHCompareLeft.Tag      := -1;
  bFHCompareRight.Tag     := -1;

  bFHCompareFolderLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareFolderRight.Caption := XText[rsSelectDateTime];
  bFHCompareFolderLeft.Tag      := -1;
  bFHCompareFolderRight.Tag     := -1;

  bFHCompareTreeLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareTreeRight.Caption := XText[rsSelectDateTime];
  bFHCompareTreeLeft.Tag      := -1;
  bFHCompareTreeRight.Tag     := -1;

  tvFHTLeft.Items.Clear;
  tvFHTRight.Items.Clear;

  // ===========================================================================

  if Assigned(FOnUpdateLeftStatusPanel) then
      FOnUpdateLeftStatusPanel(0);
end;


procedure TFrameFolderHistory.cbFHCompareColourClick(Sender: TObject);
begin
  if sgFHCompareLeft.Cells[0,1] <> '' then
    sgFHCompareLeft.Refresh;

  if sgFHCompareRight.Cells[0,1] <> '' then
    sgFHCompareRight.Refresh;
end;


procedure TFrameFolderHistory.eFHCompareDriveFolderKeyPress(Sender: TObject;
  var Key: Char);
begin
  if key = #13 then begin
    sbFHCompareFolderSearchClick(Nil);
  end;
end;


procedure TFrameFolderHistory.eFHCompareSearchChange(Sender: TObject);
begin
  lCLPagePrevious.Tag     := 0;
  lCRPagePrevious.Tag     := 0;

  lCLPagePrevious.Enabled := False;
  lCLPageNext.Enabled     := False;
  lCLPageNumber.Caption   := '1';
  lCLShowing.Caption      := 'n/a';

  lCRPagePrevious.Enabled := False;
  lCRPageNext.Enabled     := False;
  lCRPageNumber.Caption   := '1';
  lCRShowing.Caption      := 'n/a';
end;


procedure TFrameFolderHistory.eFHCompareSearchKeyPress(Sender: TObject; var Key: Char);
begin
  if key = #13 then
    sbFHCompareSearchClick(sbFHCompareSearch);
end;


procedure TFrameFolderHistory.lFHCFilesClick(Sender: TObject);

  procedure SetToggleIcon(ix : TImage; imageindex : integer);
   var
    tbmp : TBitmap;

   begin
    tbmp := TBitmap.Create;

    ilToggle.GetBitmap(imageindex, tbmp);
    ix.Picture.Bitmap.Assign(tbmp);

    tbmp.Free;

    ix.Tag := 1 - ix.Tag;
  end;

 begin
  if TPanel(TLabel(Sender).Parent).Height = TPanel(TLabel(Sender).Parent).Tag then
    TPanel(TLabel(Sender).Parent).Height := 21
  else
    TPanel(TLabel(Sender).Parent).Height := TPanel(TLabel(Sender).Parent).Tag;

  case TLabel(Sender).Tag of
    CSectionFiles    : SetToggleIcon(Image35, 1 - Image35.Tag);
    CSectionCategory : SetToggleIcon(Image36, 1 - Image36.Tag);
  end;
end;


procedure TFrameFolderHistory.rbFHCountClick(Sender: TObject);
 var
  fhidx : integer;

 begin
  if clbFolderHistory.ItemIndex <> -1 then begin
    fhidx := (FolderHistory.Count - clbFolderHistory.ItemIndex) - 1;

    lFHFileCount.Caption := IntToStr(FolderHistory[fhidx].FileCount);
    lFHFileSize.Caption  := TConvert.ConvertToUsefulUnit(FolderHistory[fhidx].FileSize);
    lFHFolders.Caption   := IntToStr(FolderHistory[fhidx].FolderCount);
  end;

  TDisplayUtility.BuildFolderHistoryGraph(GScanDetails[dataFolderHistory].ScanPath, vtcFolderHistory, clbFolderHistory, rbFHCount.Checked, rbFHSize.Checked, rbFHMagCount.Checked, rbFHMagSize.Checked);
end;


procedure TFrameFolderHistory.rbFJTRTodayClick(Sender: TObject);
begin
  BuildFolderHistoryTable;
end;


procedure TFrameFolderHistory.sbFHBuildInformationTabsClick(Sender: TObject);
var
  dt : string;

begin
  if (bFHISelect.Tag <> -1) then begin

    DT := TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHISelect.Tag]);

    // ===========================================================================

    if TableExists(TMD5.Generate(UpperCase(cbFHAvailablePath.Text)) + DT + cbFHAvailableComputer.Text) then begin

//      if Assigned(FOnProcessWindowStatus) then
//        FOnProcessWindowStatus(CWindowAnalysisProgress, 1);

      TPreScan.PurgeAllData(dataFolderHistory, Nil, Nil, Nil); //sgNullFiles, sgSearchResults);

      Screen.Cursor          := crSQLWait;
      llFHPleaseWait.Visible := True;

      if Assigned(FScanFromFolderHistory) then
        FScanFromFolderHistory(cbFHAvailablePath.Text,
                               TMD5.Generate(UpperCase(cbFHAvailablePath.Text)) + DT + cbFHAvailableComputer.Text,
                               TConvert.YYYYMMDDHHMMSSToString(DT));

      if assigned(FOnUpdateHistoryFinished) then
        FOnUpdateHistoryFinished;

      llFHPleaseWait.Visible := False;
    end
    else begin
      ShowXDialog(XText[rsWarning], XText[rsNoFileData] + ': ' + bFHISelect.Caption, XDialogTypeWarning);
    end;
  end;
end;


procedure TFrameFolderHistory.sbFHCF1Click(Sender: TObject);
var
 idx : integer;

begin
  FHCCStatus[TSpeedbutton(Sender).Tag] := not FHCCStatus[TSpeedbutton(Sender).Tag];

  if FHCCStatus[TSpeedbutton(Sender).Tag] then
    idx := FHCCImageBase[TSpeedbutton(Sender).Tag]
  else
    idx := FHCCImageBase[TSpeedbutton(Sender).Tag] + 1;

  GXGuiUtil.SetFolderHistoryButtonImage(TSpeedbutton(Sender), idx);

  rbFHCountClick(Nil);
end;


procedure TFrameFolderHistory.sbFHCLHideCreatedClick(Sender: TObject);
begin
  TGridUtility.ToggleColumn(sgFHCompareLeft,
                            TSpeedbutton(Sender),
                            TableColumnLookup[(TSpeedbutton(Sender).Tag * 2) + 1],
                            TableColumnLookup[TSpeedbutton(Sender).Tag * 2]);

  Splitter2Moved(Nil);
end;


procedure TFrameFolderHistory.sbFHCompareFavouritesClick(Sender: TObject);
begin
  puFHQuickSearch.Tag := TSpeedbutton(Sender).Tag;

  puFHQuickSearch.Popup(FGetLeftOffset + 38, FGetTopOffset + 205);
end;


procedure TFrameFolderHistory.sbFHCompareFolder2LeftSaveClickClick(
  Sender: TObject);
var
  stree : THTMLTreeView;
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsTextFiles] + ' (*.txt)|*.txt',
                                    '.txt',
                                    TUtility.GetDefaultFileName('.txt', XText[rsFileHistoryCompare] + '_' + XText[rsLeft]));

  if lFileName <> '' then begin

    case TSpeedbutton(Sender).Tag of
      CLeft  : stree := tvFHTLeft;
      CRight : stree := tvFHTRight;
    else
      stree := tvFHTLeft;
    end;

    try
      stree.SaveToFile(lFileName);
    except
      on e : exception do begin
        TMSLogger.Error('Error saving tree "' + e.ClassName + ' / ' + e.Message);
      end;
    end;
  end;
end;


procedure TFrameFolderHistory.sbFHCompareFolderLeftSaveClick(Sender: TObject);
 var
  sgrid : TAdvStringGrid;
  lFileName : string;

 begin
  lFileName := TXSaveDialog.ExecuteReports(TUtility.GetDefaultFileName('.csv', XText[rsFileHistoryCompare] + '_' + XText[rsLeft]));

  if lFileName <> '' then begin
    case TSpeedbutton(Sender).Tag of
      CLeft  : sgrid := sgFHCDLeft;
      CRight : sgrid := sgFHCDRight;
    else
      sgrid := sgFHCDLeft;
    end;

    TGridUtility.SaveGrid(sgrid, lFileName);
  end;
end;


procedure TFrameFolderHistory.sbFHCompareFolderSearchClick(Sender: TObject);
begin
  if not(XSettings.ProcessWindowsVisible) then begin
    if (bFHCompareFolderLeft.Tag <> -1) and (bFHCompareFolderRight.Tag <> -1) then begin
      if eFHCompareDriveFolder.Text <> '' then begin

        FHCompareFolderBuildLeft(Nil);
        FHCompareFolderBuildRight(Nil);
      end;
    end
    else
      ShowXDialog(XText[rsWarning], XText[rsPleaseSelectADate], XDialogTypeWarning);
  end;
end;


procedure TFrameFolderHistory.sbFHCompareLeftSaveClick(Sender: TObject);
begin
  TGridUtility.SaveFHStringGridData(sgFHCompareLeft, eFHCompareSearch.Text, fhscModeSaveAll);
end;


procedure TFrameFolderHistory.sbFHCompareRightSaveClick(Sender: TObject);
begin
  TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch.Text, fhscModeSaveAll);
end;


procedure TFrameFolderHistory.sbFHCompareSearchClick(Sender: TObject);
begin
  if not(XSettings.ProcessWindowsVisible) then begin
    if not(XSettings.ProcessWindowsVisible) then begin
      if (bFHCompareLeft.Tag <> -1) and (bFHCompareRight.Tag <> -1) then begin
        if eFHCompareSearch.Text <> '' then begin
          FHCompareBuildLeft(Nil);
          FHCompareBuildRight(Nil);

          if eFHCompareSearch.Items.IndexOf(eFHCompareSearch.Text) = -1 then begin
            if eFHCompareSearch.Text <> '' then
              eFHCompareSearch.Items.Insert(0, eFHCompareSearch.Text);
          end;
        end;
      end
      else
        ShowXDialog(XText[rsWarning], XText[rsPleaseSelectADate], XDialogTypeWarning);
    end;
  end;
end;


procedure TFrameFolderHistory.sbFHCRHideCreatedClick(Sender: TObject);
begin
  TGridUtility.ToggleColumn(sgFHCompareRight, TSpeedbutton(Sender), TableColumnLookup[(TSpeedbutton(Sender).Tag * 2) + 1], TableColumnLookup[TSpeedbutton(Sender).Tag * 2]);

  Splitter2Moved(Nil);
end;


procedure TFrameFolderHistory.sbFHCShowLeftClick(Sender: TObject);
 var
  t, i : integer;

 begin
  if sbFHCShowLeft.Tag = 0 then begin
    GXGuiUtil.SetButtonOffImage(sbFHCShowLeft, CImageShow);
    Screen.Cursor := crHourGlass;

    sbFHCShowLeft.Tag := 1;
    cbFHCompareColour.Checked := False;
    i := 0;

    FQuickCompareB.Clear;

    for t := 1 to sgFHCompareRight.RowCount - 1 do begin
      FQuickCompareB.Add(sgFHCompareRight.Cells[0, t]);
    end;

    FQuickCompareB.Sort;

    // ===========================================================================

    for t := 1 to sgFHCompareLeft.RowCount - 1 do begin
      if FQuickCompareB.IndexOf(sgFHCompareLeft.Cells[0, t]) <> -1 then
        sgFHCompareLeft.Cells[FHschCategory, t] := '1'
      else begin
        sgFHCompareLeft.Cells[FHschCategory, t] := '2';

        inc(i);
      end;
    end;

    lFHCompareLeft.HTMLText[0] := XText[rsFound] + ' <b>' + IntToStr(i) + '</b> ' + XText[rsFiles] + '.';
    Screen.Cursor := crDefault;
  end
  else begin
    sbFHCShowLeft.Tag := 0;
    GImageHandler->SetButtonOnImage(sbFHCShowLeft, kImageShow);
  end;

  sgFHCompareLeft.Refresh;
end;


procedure TFrameFolderHistory.sbFHCShowRightClick(Sender: TObject);
 var
  i, t : integer;

 begin
  if sbFHCShowRight.Tag = 0 then begin
    GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);

    Screen.Cursor := crHourGlass;

    sbFHCShowRight.Tag        := 1;
    cbFHCompareColour.Checked := False;
    i := 0;

    FQuickCompareA.Clear;

    for t := 1 to sgFHCompareLeft.RowCount - 1 do begin
      FQuickCompareA.Add(sgFHCompareLeft.Cells[0, t]);
    end;

    FQuickCompareA.Sort;

    // ===========================================================================

    for t := 1 to sgFHCompareRight.RowCount - 1 do begin
      if FQuickCompareA.IndexOf(sgFHCompareRight.Cells[0, t]) <> -1 then
        sgFHCompareRight.Cells[FHschCategory, t] := '1'
      else begin
        sgFHCompareRight.Cells[FHschCategory, t] := '2';

        inc(i);
      end;
    end;

    lFHCompareRight.Caption := XText[rsFound] + ' <b>' + IntToStr(i) + '</b> ' + XText[rsFiles] + '.';;

    Screen.Cursor := crDefault;
  end
  else begin
    GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);
    sbFHCShowRight.Tag := 0;
  end;

  sgFHCompareRight.Refresh;
end;


procedure TFrameFolderHistory.sbFHFolderInfoClick(Sender: TObject);
begin
  DoDBSelectedFolder(cbFHAvailableComputer.Text, UpperCase(cbFHAvailablePath.Text));
end;


procedure TFrameFolderHistory.sbFHOpenFolderClick(Sender: TObject);
var
  lDBExists : boolean;

begin
  if not(XSettings.ProcessWindowsVisible) then begin

    lDBExists := True;

    if not(XSettings.Database.UseODBC) then
      if not(FileExists(GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db')) then
        lDBExists := False;

    if lDBExists then begin
      if cbFHAvailablePath.Text <> '' then begin

        GScanDetails[dataFolderHistory].ScanPath := cbFHAvailablePath.Text;

        tpFHStats.Visible  := True;         // to do make sure new layout
        tsFHMainSearch.TabVisible := True;

        ResetDisplay(True, False);

        BuildFolderHistory(cbFHAvailableComputer.Text, cbFHAvailablePath.Text);

        BuildTimeLine;
      end
      else
        ShowXDialog(XText[rsWarning], XText[rsNoFHFSelected], XDialogTypeWarning);
    end
    else
      ShowXDialog(XText[rsError] + ' ' + XText[rsFolderHistory],
                  TLanguageHandler.FillParameter(rsCannotFindFileParam, GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db'),
                  XDialogTypeWarning);
  end;
end;


procedure TFrameFolderHistory.sbTLResetClick(Sender: TObject);
begin
  atlFolderHistory.Range.RangeFrom := oldTLFrom;
  atlFolderHistory.Range.RangeTo   := oldTLTo;

  atlFolderHistory.Resize;
end;


procedure TFrameFolderHistory.sbTLSaveClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.ExecuteImages(TUtility.GetDefaultFileName('.png', XText[rsTimeLine]));

  if lFileName <> '' then begin
    try
      atlFolderHistory.SaveToImage(lFileName,
                                   atlFolderHistory.Width, atlFolderHistory.Height,
                                   itPNG);
    except
      on e : exception do begin
        ShowXDialog(XText[rsWarning],
                    XText[rsErrorSaving] + ' "' + lFileName + '". ' + e.ClassName + ' / ' + e.Message,
                    XDialogTypeWarning);
      end;
    end;
  end;
end;


procedure TFrameFolderHistory.sgFHCDLeftCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
begin
  if (Acol = 0) or (Acol = 1) then begin
    DoSort := False; // stops the component for sorting automatically
    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then  // make sure we toggle the search direction -
        SortSettings.Direction := sdAscending        // as this is not done for us
      else                                         //
        SortSettings.Direction := sdDescending;      //

      Sortsettings.Column := 7; //set the hidden column as the sort source
      QSort;                  //force a quick sort of above

      SortSettings.Column := Acol;
    end;
  end
  else if Acol = 3 then begin
    DoSort := False; // stops the component for sorting automatically
    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then  // make sure we toggle the search direction -
        SortSettings.Direction := sdAscending        // as this is not done for us
      else                                         //
        SortSettings.Direction := sdDescending;      //

      Sortsettings.Column := 2; //set the hidden column as the sort source
      QSort;                  //force a quick sort of above

      SortSettings.Column := Acol;
    end;
  end
  else if (Acol = 5) or (Acol = 6) then begin
    DoSort := False; // stops the component for sorting automatically
    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then  // make sure we toggle the search direction -
        SortSettings.Direction := sdAscending        // as this is not done for us
      else                                         //
        SortSettings.Direction := sdDescending;      //

      Sortsettings.Column := 8; //set the hidden column as the sort source
      QSort;                  //force a quick sort of above

      SortSettings.Column := Acol;
    end;
  end;
end;


procedure TFrameFolderHistory.sgFHCompareLeftDrawCell(Sender: TObject; ACol,
  ARow: Integer; Rect: TRect; State: TGridDrawState);
 var
  l,w : integer;

 begin
  if (cbFHCompareColour.Checked) then begin
    if ARow <> 0 then begin

      TAdvStringGrid(Sender).Canvas.Brush.Color := GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender).Cells[FHschCategory, ARow])];
      TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
    end;
  end
  else if (sbFHCShowLeft.Tag = 1) then begin
    if ARow <> 0 then begin
      TAdvStringGrid(Sender).Canvas.Brush.Color := CompareColoursX[StrToInt(TAdvStringGrid(Sender).Cells[FHschCategory, ARow])];
      TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
    end;
  end;

  if ACol > 0 then begin
    case ACol of
      1,2 : begin
              w := TAdvStringGrid(Sender).Canvas.TextWidth(TAdvStringGrid(Sender).Cells[ACol, ARow]);
              l := TAdvStringGrid(Sender).ColWidths[ACol] - w;

              TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + l - 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
            end;
    end;
  end;
end;


procedure TFrameFolderHistory.sgFHCompareLeftGetAlignment(Sender: TObject; ARow,
  ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  if (ACol = 1) or (ACol = 2) then
    HAlign := taRightJustify
  else
    HAlign := taLeftJustify;
end;


procedure TFrameFolderHistory.sgFHCompareRightDrawCell(Sender: TObject; ACol,
  ARow: Integer; Rect: TRect; State: TGridDrawState);
begin
  if (cbFHCompareColour.Checked) then begin
    if ARow <> 0 then begin
      TAdvStringGrid(Sender).Canvas.Brush.Color := GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender).Cells[FHschCategory, ARow])];
      TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
    end;
  end
  else if (sbFHCShowRight.Tag = 1) then begin
    if ARow <> 0 then begin
      TAdvStringGrid(Sender).Canvas.Brush.Color := CompareColoursX[StrToInt(TAdvStringGrid(Sender).Cells[FHschCategory, ARow])];
      TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
    end;
  end;
end;


procedure TFrameFolderHistory.sgFHTableDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
begin
  if (ACol > 0) and (ARow > 0) then begin
    if sgFHTable.Cells[ACol, ARow] <> '' then begin
      if gdSelected in State then begin
        sgFHTable.Canvas.Brush.Color := sgFHTable.SelectionColor;
      end
      else begin
        if odd(ARow) then
          sgFHTable.Canvas.Brush.Color := sgFHTable.Bands.PrimaryColor
        else
          sgFHTable.Canvas.Brush.Color := $00FFFFFF;
      end;

      //sgFHTAble.Canvas.FillRect(Rect);
//      sgFHTable.Canvas.TextRect(Rect, Rect.Left + sgFHTable.ColWidths[ACol] - sgFHTable.Canvas.TextWidth(sgFHTable.Cells[ACol, ARow]) - 5, Rect.Top + 1, sgFHTable.Cells[ACol, ARow]);
    end;
  end;
end;


procedure TFrameFolderHistory.sgFHTableGetAlignment(Sender: TObject; ARow,
  ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  if (ACol = 1) or (ACol = 4) or (ACol = 7) or (ACol = 10)  then
    HAlign := taRightJustify
  else
    HAlign := taLeftJustify;
end;


procedure TFrameFolderHistory.sgFHTableGetCellColor(Sender: TObject; ARow,
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


procedure TFrameFolderHistory.sgFileHistoryCanSort(Sender: TObject; ACol: Integer;
  var DoSort: Boolean);
begin
  if (Acol >= 1) and (Acol <= 5) then begin
    DoSort := False;

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction := sdAscending
      else
        SortSettings.Direction := sdDescending;

      Sortsettings.Column := Acol + 8;

      QSort;

      SortSettings.Column := Acol;
    end;
  end;
end;


procedure TFrameFolderHistory.sbFHGetDateClick(Sender: TObject);
 var
  s, dx : string;
  i : integer;

 begin
  s := DoShowCalendar(clbFolderHistory.Items);

  if s <> '' then begin
    dx := TConvert.IntDateToString(StrToInt(Copy(s, 1, 8))) + ' ' +
                                   s[9] + s[10] + ':' + s[11] + s[12] + ':' + s[13] + s[14];

    i := FindFolderHistoryItem(dx);

    if i <> -1 then begin
      bFHISelect.Tag     := i;
      bFHISelect.Caption := dx;

     if bFHISelect.Tag <> -1 then
       sbFHBuildInformationTabsClick(nil);
    end;
  end;
end;


procedure TFrameFolderHistory.SpeedButton1Click(Sender: TObject);
begin
  if not(XSettings.ProcessWindowsVisible) then begin
    if bFHCompareTreeLeft.Tag <> -1 then
      InitialiseTreeWithFolders(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareTreeLeft.Tag]),
                                cbFHAvailablePath.Text, cbFHAvailableComputer.Text), tvFHTLeft);

    if bFHCompareTreeRight.Tag <> -1 then
      InitialiseTreeWithFolders(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareTreeRight.Tag]),
                                cbFHAvailablePath.Text, cbFHAvailableComputer.Text), tvFHTRight);

    sbFHCompareFolder2LeftSaveClick.Enabled  := True;
    sbFHCompareFolder2RightSaveClick.Enabled := True;
  end;
end;


procedure TFrameFolderHistory.SpeedButton21Click(Sender: TObject);
 var
  s,dx : string;
  i : integer;

 begin
  s := DoShowCalendar(clbFolderHistory.Items);

  if s <> '' then begin
    dx := TConvert.IntDateToString(StrToInt(Copy(s, 1, 8))) + ' ' +
                                   s[9] + s[10] + ':' + s[11] + s[12] + ':' + s[13] + s[14];

    i := FindFolderHistoryItem(dx);

    if i <> -1 then begin
      case TSpeedButton(Sender).Tag of
        CCompareLeft        : begin
                                bFHCompareLeft.Tag     := i;
                                bFHCompareLeft.Caption := dx;
                              end;
        CCompareRight       : begin
                                bFHCompareRight.Tag     := i;
                                bFHCompareRight.Caption := dx;
                              end;
        CCompareFolderLeft  : begin
                                bFHCompareFolderLeft.Tag     := i;
                                bFHCompareFolderLeft.Caption := dx;
                              end;
        CCompareFolderRight : begin
                                bFHCompareFolderRight.Tag     := i;
                                bFHCompareFolderRight.Caption := dx;
                              end;
        CCompareTreeLeft    : begin
                                bFHCompareTreeLeft.Tag     := i;
                                bFHCompareTreeLeft.Caption := dx;
                              end;
        CCompareTreeRight   : begin
                                bFHCompareTreeRight.Tag     := i;
                                bFHCompareTreeRight.Caption := dx;
                              end;
      end;
    end;
  end;
end;


procedure TFrameFolderHistory.SpeedButton4Click(Sender: TObject);
begin
  THelp.OpenSearchManual;
end;


procedure TFrameFolderHistory.tvFHTLeftExpanding(Sender: TObject; Node: TTreeNode;
  var AllowExpansion: Boolean);
begin
  if PNodeData(Node.Data)^.FolderID <> -2 then begin
    PopulateTreeFolder(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareTreeLeft.Tag]),
                       cbFHAvailablePath.Text,
                       cbFHAvailableComputer.Text),
                       tvFHTLeft, node, '', PNodeData(Node.Data)^.FolderID);

    PNodeData(Node.Data)^.FolderID := -2;
  end;
end;


procedure TFrameFolderHistory.tvFHTRightExpanding(Sender: TObject;
  Node: TTreeNode; var AllowExpansion: Boolean);
begin
  if PNodeData(Node.Data)^.FolderID <> -2 then begin
    PopulateTreeFolder(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareTreeRight.Tag]),
                       cbFHAvailablePath.Text,
                       cbFHAvailableComputer.Text),
                       tvFHTLeft, node, '', PNodeData(Node.Data)^.FolderID);

    PNodeData(Node.Data)^.FolderID := -2;
  end;
end;


procedure TFrameFolderHistory.sgFHCDLeftDrawCell(Sender: TObject; ACol,
  ARow: Integer; Rect: TRect; State: TGridDrawState);
var
  zRect : TRect;

begin
  if ARow <> 0 then begin
    case ACol of
      CFieldEmpty           : begin
                                Rect.Left   := Rect.Left;
                                Rect.Top    := Rect.Top;
                                Rect.Right  := Rect.Right;
                                Rect.Bottom := Rect.Bottom;

                                if TAdvStringGrid(Sender).Cells[7, Arow] <> '' then begin
                                  TAdvStringGrid(Sender).Canvas.Brush.Color := GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender).Cells[7, Arow])];
                                  TAdvStringGrid(Sender).Canvas.Rectangle(Rect);
                                end;
                              end;
      CFieldCategoryCountPC : begin
                                TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[5];
                                TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

                                if TAdvStringGrid(Sender).Cells[9, ARow] <> '0' then begin
                                  zRect.Top    := Rect.Top + 1;
                                  zRect.Bottom := Rect.Bottom - 1;
                                  zRect.Left   := Rect.Left + 1;
                                  zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[9, ARow]);

                                  TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[6];
                                  TAdvStringGrid(Sender).Canvas.FillRect(zRect);
                                end;

                                TAdvStringGrid(Sender).Canvas.Brush.Style := bsClear;
                                TAdvStringGrid(Sender).Canvas.Font.Color  := clBlack;
                                TAdvStringGrid(Sender).Canvas.TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender).Cells[3, ARow]);
                              end;
      CFieldCategorySizePC  : begin
                                TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[5];
                                TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

                                if TAdvStringGrid(Sender).Cells[10, ARow] <> '0' then begin
                                  zRect.Top    := Rect.Top + 1;
                                  zRect.Bottom := Rect.Bottom - 1;
                                  zRect.Left   := Rect.Left + 1;
                                  zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[10, ARow]);

                                  TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[6];
                                  TAdvStringGrid(Sender).Canvas.FillRect(zRect);
                                end;

                                TAdvStringGrid(Sender).Canvas.Brush.Style := bsClear;
                                TAdvStringGrid(Sender).Canvas.Font.Color  := clBlack;
                                TAdvStringGrid(Sender).Canvas.TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender).Cells[6, ARow]);
                              end;
    end;
  end;
end;


procedure TFrameFolderHistory.sgFHCDLeftGetAlignment(Sender: TObject; ARow,
  ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  if (ACol = 1) or (ACol = 2) then
    HAlign := taRightJustify
  else
    HAlign := taLeftJustify;
end;


procedure TFrameFolderHistory.ResetDisplay(aDisableBuildInformationTabs, aMode : boolean);
 begin
  TGridUtility.ConfigureInfoTable(sgFHCDLeft);
  TGridUtility.ConfigureInfoTable(sgFHCDRight);

  // ===========================================================================

  bFHISelect.Enabled  := aDisableBuildInformationTabs;
  sbFHGetDate.Enabled := aDisableBuildInformationTabs;

  // ===========================================================================

    sgFHTable.ClearRows(1, sgFHTable.RowCount - 1);
    sgFHTable.RowCount := 2;

    sgFHTable.Cells[ 0, 0] := XText[rsDate];
    sgFHTable.Cells[ 1, 0] := XText[rsFiles];
    sgFHTable.Cells[ 2, 0] := XText[rsDelta];
    sgFHTable.Cells[ 4, 0] := XText[rsFolders];
    sgFHTable.Cells[ 5, 0] := XText[rsDelta];
    sgFHTable.Cells[ 7, 0] := XText[rsTotalSize];
    sgFHTable.Cells[ 8, 0] := XText[rsDelta];
    sgFHTable.Cells[10, 0] := XText[rsUsedSpace];
    sgFHTable.Cells[11, 0] := XText[rsDelta];

  // ===========================================================================

    sgFHCompareLeft.ClearRows(1, sgFHCompareLeft.RowCount - 1);
    sgFHCompareLeft.RowCount := 2;

    if aMode = False then begin
      sgFHCompareLeft.Cells[ 0, 0]  := XText[rsFilename];
      sgFHCompareLeft.Cells[ 1, 0]  := XText[rsSize];
      sgFHCompareLeft.Cells[ 2, 0]  := XText[rsSizeOD];
      sgFHCompareLeft.Cells[ 3, 0]  := XText[rsCreated];
      sgFHCompareLeft.Cells[ 4, 0]  := XText[rsAccessed];
      sgFHCompareLeft.Cells[ 5, 0]  := XText[rsModified];
      sgFHCompareLeft.Cells[ 6, 0]  := XText[rsOwner];
      sgFHCompareLeft.Cells[ 7, 0]  := XText[rsStatus];
    end;

    eFHCompareSearchChange(Nil);
    lFHCompareRight.HTMLText[0] := rsEllipsis;
    lFHCompareLeft.HTMLText[0]  := rsEllipsis;

  // ===========================================================================

    sgFHCompareRight.ClearRows(1, sgFHCompareRight.RowCount - 1);
    sgFHCompareRight.RowCount := 2;

    if aMode=False then begin
      sgFHCompareRight.Cells[ 0, 0]  := XText[rsFilename];
      sgFHCompareRight.Cells[ 1, 0]  := XText[rsSize];
      sgFHCompareRight.Cells[ 2, 0]  := XText[rsSizeOD];
      sgFHCompareRight.Cells[ 3, 0]  := XText[rsCreated];
      sgFHCompareRight.Cells[ 4, 0]  := XText[rsAccessed];
      sgFHCompareRight.Cells[ 5, 0]  := XText[rsModified];
      sgFHCompareRight.Cells[ 6, 0]  := XText[rsOwner];
      sgFHCompareRight.Cells[ 7, 0]  := XText[rsStatus];
    end;

  // ===========================================================================

    vtcFolderHistory.SeriesList.Clear;

  // ============================================================================

  if Assigned(FOnResetDisplay) then
    FOnResetDisplay(dataFolderHistory);
end;


procedure TFrameFolderHistory.BuildFolderHistoryTable;
 var
  t, i : integer;

 begin
  TGridUtility.ClearStringGird(sgFHTable, False);

  // now build table ===========================================================

  sgFHTable.BeginUpdate;

  sgFHTable.RowCount := 1 + clbFolderHistory.Items.Count;

  i := clbFolderHistory.Items.Count;

  if rbFJTRPrevious.Checked then begin
    for t := 0 to clbFolderHistory.Items.Count - 1 do begin
      sgFHTable.Cells[ 0, i] := FolderHistory[t].ScanDateStr;

      sgFHTable.Cells[ 1, i] := IntToStr(FolderHistory[t].FileCount);
      sgFHTable.Cells[ 4, i] := IntToStr(FolderHistory[t].FolderCount);
      sgFHTable.Cells[ 7, i] := TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSize);
      sgFHTable.Cells[10, i] := TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSizeOnDisk);

      if t = 0 then begin
        sgFHTable.Cells[ 2, i] := '';
        sgFHTable.Cells[ 5, i] := '';
        sgFHTable.Cells[ 8, i] := '';
        sgFHTable.Cells[11, i] := '';
      end
      else begin
        sgFHTable.Cells[ 2, i] := TConvert.GetDelta(FolderHistory[t].FileCount -
                                                    FolderHistory[t - 1].FileCount);

        sgFHTable.Cells[ 5, i] := TConvert.GetDelta(FolderHistory[t].FolderCount -
                                                    FolderHistory[t - 1].FolderCount);

        sgFHTable.Cells[ 8, i] := TConvert.GetDeltaSize(FolderHistory[t].FileSize-
                                                        FolderHistory[t - 1].FileSize);

        sgFHTable.Cells[11, i] := TConvert.GetDeltaSize(FolderHistory[t].FileSizeOnDisk-
                                                        FolderHistory[t - 1].FileSizeOnDisk);
      end;

      dec(i);
    end;
  end
  else begin
    for t := 0 to clbFolderHistory.Items.Count - 1 do begin
      sgFHTable.Cells[ 0, i] := FolderHistory[t].ScanDateStr;

      sgFHTable.Cells[ 1, i] := IntToStr(FolderHistory[t].FileCount);
      sgFHTable.Cells[ 4, i] := IntToStr(FolderHistory[t].FolderCount);
      sgFHTable.Cells[ 7, i] := TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSize);
      sgFHTable.Cells[10, i] := TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSizeOnDisk);

      if t = clbFolderHistory.Items.Count - 1 then begin
        sgFHTable.Cells[ 2, i] := '';
        sgFHTable.Cells[ 5, i] := '';
        sgFHTable.Cells[ 8, i] := '';
        sgFHTable.Cells[11, i] := '';
      end
      else begin
        sgFHTable.Cells[ 2, i] := TConvert.GetDelta(FolderHistory[t].FileCount -
                                           FolderHistory[clbFolderHistory.Items.Count - 1].FileCount);

        sgFHTable.Cells[ 5, i] := TConvert.GetDelta(FolderHistory[t].FolderCount -
                                           FolderHistory[clbFolderHistory.Items.Count - 1].FolderCount);

        sgFHTable.Cells[ 8, i] := TConvert.GetDeltaSize(FolderHistory[t].FileSize -
                                           FolderHistory[clbFolderHistory.Items.Count - 1].FileSize);

        sgFHTable.Cells[11, i] := TConvert.GetDelta(FolderHistory[t].FileSizeOnDisk -
                                           FolderHistory[clbFolderHistory.Items.Count - 1].FileSizeOnDisk);
      end;

      dec(i);
    end;
  end;

  sgFHTable.EndUpdate;
end;


procedure TFrameFolderHistory.BuildFolderHistoryAvailable;
 var
  sr : TSearchRec;
  tf : TextFile;
  fha : TFolderHistoryInfo;
  sp, thispc  : string;
  t, tpxidx : integer;

 function GetPathFromFHFile(const FileName : string): string;
  var
   s : string;

  begin
   AssignFile(tf, FileName);
   {$I-}
   Reset(tf);

   if IOResult <> 0 then begin
     ShowXDialog(XText[rsError] + ': ' + XText[rsFolderHistory],
                 XText[rsErrorOpening] + ' "' + filename + '".',
                 XDialogTypeWarning);
   end
   else begin
     Readln(tf, s);

     CloseFile(tf);
   end;
   {$I+}

   Result := s;
 end;

 function GetComputerNameFromPath(const FileName : string): string;
  var
   s : string;
   i,z : integer;

  begin
   s := '';
   z := Pos('FOLDERHISTORY\', UpperCase(FileName));

   i := z + 14;
   while FileName[i] <> '\' do begin
     s := s + FileName[i];

     inc(i);
   end;

   Result := s;
 end;

 begin
  if (XSettings.HistorySettings.Enabled) and (XSettings.System.UserEnabledFH) then begin
    cbFHAvailablePath.Items.Clear;
    cbFHAvailableComputer.Items.Clear;
    FolderHistoryAvailable.Clear;

    thispc := TXWindows.GetComputerNetName;
    tpxidx := 0;

    // firstly we need a list of computer names and paths that have been scanned...
    if FindFirst(GSystemGlobal.AppDataPath + 'folderhistory\' + thispc + '\*.xfh', $3F, sr) = 0 then begin
      repeat
        sp := GetPathFromFHFile(GSystemGlobal.AppDataPath + 'folderhistory\' + thispc + '\' + sr.Name);

        fha := TFolderHistoryInfo.Create;
        fha.ScanPath     := sp;
        fha.MD5          := sr.Name;
        fha.ComputerName := GetComputerNameFromPath(GSystemGlobal.AppDataPath + 'folderhistory\' + thispc + '\' + sr.Name);;

        FolderHistoryAvailable.Add(fha);

      until FindNext(sr) <> 0;

      FindClose(sr);
    end;

    // now we populate the GUI with the new details
    for t := 0 to FolderHistoryAvailable.Count - 1 do begin
      fha := FolderHistoryAvailable[t];

      if cbFHAvailableComputer.Items.IndexOf(fha.ComputerName) = -1 then
        cbFHAvailableComputer.Items.Add(fha.ComputerName);

      if fha.ComputerName = thispc then
        tpxidx := cbFHAvailableComputer.Items.Count - 1;

    end;

    FolderHistoryAvailable.Sort(TComparer<TFolderHistoryInfo>.Construct(CompareFHPaths));

    cbFHAvailableComputer.ItemIndex := tpxidx;

    cbFHAvailableComputerChange(Nil);

    if cbFHAvailableComputer.Items.Count = 0 then begin
      cbFHAvailableComputer.Items.Add(thispc);
      cbFHAvailableComputer.ItemIndex := 0;
    end;

    cbFHAvailableComputer.Tag := -1;
    cbFHAvailablePath.Tag     := -1;
  end;
end;


procedure TFrameFolderHistory.splitFHDirListCanResize(Sender: TObject;
  var NewSize: Integer; var Accept: Boolean);
begin
  if NewSize < 335 then Accept := False;
end;


procedure TFrameFolderHistory.Splitter2Moved(Sender: TObject);
var
  i : integer;

 begin
  i := 530;

  if sgFHCompareLeft.IsHiddenColumn(2) then dec(i, 70);
  if sgFHCompareLeft.IsHiddenColumn(3) then dec(i, 70);
  if sgFHCompareLeft.IsHiddenColumn(4) then dec(i, 70);
  if sgFHCompareLeft.IsHiddenColumn(5) then dec(i, 70);
  if sgFHCompareLeft.IsHiddenColumn(6) then dec(i, 100);
  if sgFHCompareLeft.IsHiddenColumn(7) then dec(i, 55);

  sgFHCompareLeft.ColWidths[0]  := sgFHCompareLeft.Width - i;

  i := 530;

  if sgFHCompareRight.IsHiddenColumn(2) then dec(i, 70);
  if sgFHCompareRight.IsHiddenColumn(3) then dec(i, 70);
  if sgFHCompareRight.IsHiddenColumn(4) then dec(i, 70);
  if sgFHCompareRight.IsHiddenColumn(5) then dec(i, 70);
  if sgFHCompareRight.IsHiddenColumn(6) then dec(i, 100);
  if sgFHCompareRight.IsHiddenColumn(7) then dec(i, 55);

  sgFHCompareRight.ColWidths[0] := sgFHCompareRight.Width - i;
end;


procedure TFrameFolderHistory.splitterFHCDMoved(Sender: TObject);
begin
  sgFHCDLeft.ColWidths[0]  := 10;
  sgFHCDLeft.ColWidths[2]  := 50;
  sgFHCDLeft.ColWidths[3]  := 52;
  sgFHCDLeft.ColWidths[4]  := 4;
  sgFHCDLeft.ColWidths[5]  := 60;
  sgFHCDLeft.ColWidths[6]  := 52;

  sgFHCDLeft.ColWidths[1]  := sgFHCDLeft.Width - (230 + 23);

  sgFHCDRight.ColWidths[0] := 10;
  sgFHCDRight.ColWidths[2] := 50;
  sgFHCDRight.ColWidths[3] := 52;
  sgFHCDRight.ColWidths[4] := 4;
  sgFHCDRight.ColWidths[5] := 60;
  sgFHCDRight.ColWidths[6] := 52;

  sgFHCDRight.ColWidths[1] := sgFHCDRight.Width - (230 + 23);
end;


procedure TFrameFolderHistory.FHCompareFolderBuildLeft(Sender : TObject);
var
  SQL : string;

begin
  if Pos('SELECT ', eFHCompareDriveFolder.Text) <> 0 then begin
    if XSettings.HistorySettings.SQLinSearch then begin
      SQL := StringReplace(eFHCompareDriveFolder.Text, '*', ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ', [rfReplaceAll]);

      SQL := StringReplace(SQL, '$x$', '"' + TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text) + '"', [rfReplaceAll]);
    end
    else begin
      SQL := '';
      ShowXDialog(XText[rsWarning], XText[rsDialog10], XDialogTypeWarning);
    end;
  end
  else begin
    SQL := TSearchUtility.XinorbisSearchAllToSQL(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text, False)
  end;

  if TableExists(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text)) then begin
    if SQL <> '' then begin
      LastSQL[2] := SQL;

      GCompareFolderLeftThread := TCompareFolderLeftThread.Create(True);
      GCompareFolderLeftThread.SetData(SQL, eFHCompareDriveFolder.Text, lFHCDLeft, sgFHCDLeft);
      GCompareFolderLeftThread.OnTerminate := CompareFolderLeftThreadOnTerminate;
      GCompareFolderLeftThread.Priority    := tpTimeCritical;        //tpTimeCritical
      GCompareFolderLeftThread.Start;
    end;
  end
  else begin
    ShowXDialog(XText[rsWarning],
                XText[rsNoFileData] + ': ' + bFHCompareLeft.Caption,
                XDialogTypeWarning);
  end;
end;


procedure TFrameFolderHistory.CompareFolderLeftThreadOnTerminate(Sender : TObject);
 begin
  sgFHCDLeft.EndUpdate;

  Screen.Cursor := crDefault;
end;


procedure TFrameFolderHistory.FHCompareFolderBuildRight(Sender : TObject);
 var
  SQL : string;

 begin
  if Pos('SELECT ', eFHCompareDriveFolder.Text) <> 0 then begin
    if XSettings.HistorySettings.SQLinSearch then begin
      SQL := StringReplace(eFHCompareDriveFolder.Text, '*', ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ', [rfReplaceAll]);

      SQL := StringReplace(SQL, '$x$', '"' + TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text) + '"', [rfReplaceAll]);
    end
    else begin
      SQL := '';

      ShowXDialog(XText[rsWarning], XText[rsDialog10], XDialogTypeWarning);
    end;
  end
  else begin
    SQL := TSearchUtility.XinorbisSearchAllToSQL(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text, False)
  end;

  if TableExists(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text)) then begin
    if SQL <> '' then begin
      LastSQL[2] := SQL;

      GCompareFolderRightThread := TCompareFolderRightThread.Create(True);
      GCompareFolderRightThread.SetData(SQL, eFHCompareDriveFolder.Text, lFHCDRight, sgFHCDRight);
      GCompareFolderRightThread.OnTerminate := CompareFolderRightThreadOnTerminate;
      GCompareFolderRightThread.Priority    := tpTimeCritical;        //tpTimeCritical
      GCompareFolderRightThread.Start;
    end;
  end
  else begin
    ShowXDialog(XText[rsWarning],
                XText[rsNoFileData] + ': ' + bFHCompareLeft.Caption,
                XDialogTypeWarning);
  end;
end;


procedure TFrameFolderHistory.CompareFolderRightThreadOnTerminate(Sender : TObject);
 begin
  sgFHCDRight.EndUpdate;

  Screen.Cursor := crDefault;
end;


procedure TFrameFolderHistory.FHCompareBuildLeft(Sender : TObject);
 var
  SQL : string;

 begin
  if Pos('SELECT ', eFHCompareSearch.Text) <> 0 then begin
    if XSettings.HistorySettings.SQLinSearch then begin
      SQL := StringReplace(eFHCompareSearch.Text, '*', ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ', [rfReplaceAll]);

      SQL := StringReplace(SQL, '$x$', '"' + TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text) + '"', [rfReplaceAll]);
    end
    else begin
      SQL := '';

      ShowXDialog(XText[rsWarning],
                  XText[rsDialog10],
                  XDialogTypeWarning);
    end;
  end
  else begin
    SQL := TSearchUtility.XinorbisSearchToSQL(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareLeft.Tag]),
                                              cbFHAvailablePath.Text,
                                              cbFHAvailableComputer.Text,
                                              eFHCompareSearch.Text,
                                              lCLPagePrevious.Tag * XSettings.General.MaxSearchResults,
                                              XSettings.General.MaxSearchResults,
                                              False)
  end;

  if TableExists(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text)) then begin
    if SQL <> '' then begin
      sbFHCShowLeft.Tag := 0;
      GXGuiUtil.SetButtonOffImage(sbFHCShowLeft, 8);
      Screen.Cursor := crSQLWait;

      LastSQL[2] := SQL;

      GCompareLeftThread := TCompareLeftThread.Create(True);
      GCompareLeftThread.SetData(SQL, cbFHCompareUnits.ItemIndex, cbFHComparePath.Checked, sgFHCompareLeft);
      GCompareLeftThread.OnTerminate := CompareLeftThreadOnTerminate;
      GCompareLeftThread.Priority    := tpTimeCritical;        //tpTimeCritical
      GCompareLeftThread.Start;
    end;
  end
  else begin
    ShowXDialog(XText[rsWarning],
                XText[rsNoFileData] + ': ' +bFHCompareLeft.Caption,
                XDialogTypeWarning);
  end;
end;


procedure TFrameFolderHistory.FHCompareBuildRight(Sender : TObject);
 var
  SQL : string;

 begin
  if Pos('SELECT ', eFHCompareSearch.Text) <> 0 then begin
    if XSettings.HistorySettings.SQLinSearch then begin
      SQL := StringReplace(eFHCompareSearch.Text, '*', ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ', [rfReplaceAll]);

      SQL := StringReplace(SQL, '$x$', '"' + TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text) + '"', [rfReplaceAll]);
    end
    else begin
      SQL := '';

      ShowXDialog(XText[rsWarning], XText[rsDialog10], XDialogTypeWarning);
    end;
  end
  else begin
    SQL := TSearchUtility.XinorbisSearchToSQL(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text, eFHCompareSearch.Text, lCRPagePrevious.Tag*XSettings.General.MaxSearchResults, XSettings.General.MaxSearchResults, False)
  end;

  if TableExists(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text)) then begin
    if SQL <> '' then begin
      sbFHCShowRight.Tag := 0;
      GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);
      Screen.Cursor := crSQLWait;

      LastSQL[3] := SQL;

      GCompareRightThread := TCompareRightThread.Create(True);
      GCompareRightThread.SetData(SQL, cbFHCompareUnits.ItemIndex, cbFHComparePath.Checked, sgFHCompareRight);
      GCompareRightThread.OnTerminate := CompareRightThreadOnTerminate;
      GCompareRightThread.Priority    := tpTimeCritical;
      GCompareRightThread.Start;
    end;
  end
  else begin
    ShowXDialog(XText[rsWarning],
                XText[rsNoFileData] + ': ' + bFHCompareRight.Caption,
                XDialogTypeWarning);
  end;
end;


procedure TFrameFolderHistory.BuildFolderHistory(const ComputerName, ScanPath : string);
 begin
  bFHISelect.Caption            := XText[rsSelectDateTime];
  bFHCompareLeft.Caption        := XText[rsSelectDateTime];
  bFHCompareRight.Caption       := XText[rsSelectDateTime];
  bFHCompareFolderLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareFolderRight.Caption := XText[rsSelectDateTime];

  bFHISelect.Tag                := -1;
  bFHISelect.Enabled            := True;
  bFHCompareLeft.Tag            := -1;
  bFHCompareRight.Tag           := -1;
  bFHCompareFolderLeft.Tag      := -1;
  bFHCompareFolderRight.Tag     := -1;

  FolderHistory.Clear;

  clbFolderHistory.Clear;

  sgFHCompareLeft.ClearRows(1, sgFHCompareLeft.RowCount - 1);
  sgFHCompareRight.ClearRows(1, sgFHCompareRight.RowCount - 1);
  sgFHCompareLeft.RowCount  := 2;
  sgFHCompareRight.RowCount := 2;

  if LoadFolderHistory(ComputerName, ScanPath, clbFolderHistory.Items) then begin

    if FolderHistory.Count > 0 then begin

      BuildFolderHistoryTable;

      // ===========================================================================

      TDisplayUtility.BuildFolderHistoryGraph(FrameSelect.ePath.Text, vtcFolderHistory, clbFolderHistory, rbFHCount.Checked, rbFHSize.Checked, rbFHMagCount.Checked, rbFHMagSize.Checked);

      if clbFolderHistory.Count <> 0 then begin
        clbFolderHistory.Checked[0]     := True;
        clbFolderHistory.ItemIndex      := 0;
        rbFHCountClick(Nil);
      end;

      if clbFolderHistory.Count <> 0 then
        FileHistoryControlStatus(True)
      else
        FileHistoryControlStatus(False);
    end
    else begin
      ShowXDialog(XText[rsError] + ' :: ' + XText[rsFolderHistory], 'Error building File History!', XDialogTypeWarning);
    end;
  end
  else begin
    if FileExists(GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh') then begin
      if MessageDlg(XText[rsDialog7] + #13#13 + XText[rsDialog8], mtInformation, [mbYes, mbNo], 0) = mrYes then begin
        RepairFile(TMD5.Generate(UpperCase(ScanPath)) + '.xfh', GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(ScanPath) + '.xfh');
      end;
    end;
  end;

  BuildFolderHistorySelectDataMenu;
end;


procedure TFrameFolderHistory.BuildFolderHistorySelectDataMenu;
 var
  mi : TMenuItem;
  LastYearNode, LastMonthNode, LastDayNode : TMenuItem;
  lyy, lmm, ldd, t : integer;
  cyy, cmm, cdd : integer;
  xdate : string;

 begin
  bFHISelect.Tag := -1;
  LastYearNode   := Nil;
  LastMonthNode  := Nil;
  LastDayNode    := Nil;
  lyy            := -1;
  lmm            := -1;
  ldd            := -1;

  puFHSelectDate.Items.Clear;

  for t := 0 to clbFolderHistory.Count - 1 do begin
    xdate := TConvert.DateTimeFToYYYYMMDD(clbFolderHistory.Items[t]);

    if xdate <> '' then begin
      cyy := StrToInt(Copy(xdate, 1, 4));
      cmm := StrToInt(Copy(xdate, 5, 2));
      cdd := StrToInt(Copy(xdate, 7, 2));

      if cyy <> lyy then begin
        mi := TMenuItem.Create(puFHSelectDate);
        mi.Caption := IntToStr(cyy);

        puFHSelectDate.Items.Add(mi);
        LastYearNode := mi;

        lyy := cyy;
      end;

      if cmm <> lmm then begin
        mi := TMenuItem.Create(puFHSelectDate);
        mi.Caption := months[cmm];

        LastYearNode.Add(mi);
        LastMonthNode := mi;

        lmm := cmm;
      end;

      if cdd <> ldd then begin
        mi := TMenuItem.Create(puFHSelectDate);
        mi.Caption := IntToStr(cdd);

        LastMonthNode.Add(mi);
        LastDayNode := mi;

        ldd := cdd;
      end;

      mi := TMenuItem.Create(puFHSelectDate);
      mi.OnClick := miSelectDateTimeClick;
      mi.Caption := Copy(clbFolderHistory.Items[t], 12, 8);
      mi.Tag     := t;

      LastDayNode.Add(mi);
    end;
  end;
end;


procedure TFrameFolderHistory.miCCustomToClick(Sender: TObject);
var
  mychart : TChart;
  lColour : integer;

begin
  mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  lColour := TXColourDialog.Execute(mychart.Gradient.EndColor);

  if lColour <> -1 then begin
    mychart.Gradient.EndColor := lColour;

    XSettings.Charts.Options.ChartTo := lColour;
  end;
end;


procedure TFrameFolderHistory.miCGradientToSelectClick(Sender: TObject);
 var
  mychart : TChart;

 begin
  mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  mychart.Gradient.EndColor := ChartGradientSelection[TMenuItem(Sender).Tag];

  XSettings.Charts.Options.ChartTo := ChartGradientSelection[TMenuItem(Sender).Tag];
end;


procedure TFrameFolderHistory.miSelectDateTimeClick(Sender: TObject);
var
  lOldID : integer;

begin
  case Tpopupmenu(TMenuItem(Sender).GetParentMenu).Tag of
    1 : begin
          lOldID := bFHISelect.Tag;

          bFHISelect.Tag     := TMenuItem(Sender).Tag;
          bFHISelect.Caption := clbFolderHistory.Items[bFHISelect.Tag];

          if bFHISelect.Tag <> lOldID then
            sbFHBuildInformationTabsClick(nil);
        end;
    2 : begin
          bFHCompareLeft.Tag     := TMenuItem(Sender).Tag;
          bFHCompareLeft.Caption := clbFolderHistory.Items[bFHCompareLeft.Tag];
        end;
    3 : begin
          bFHCompareRight.Tag     := TMenuItem(Sender).Tag;
          bFHCompareRight.Caption := clbFolderHistory.Items[bFHCompareRight.Tag];
        end;
//    4 : begin
//        end;
    5 : begin
          bFHCompareFolderLeft.Tag     := TMenuItem(Sender).Tag;
          bFHCompareFolderLeft.Caption := clbFolderHistory.Items[bFHCompareFolderLeft.Tag];
        end;
    6 : begin
          bFHCompareFolderRight.Tag     := TMenuItem(Sender).Tag;
          bFHCompareFolderRight.Caption := clbFolderHistory.Items[bFHCompareFolderRight.Tag];
        end;
    7 : begin
          bFHCompareTreeLeft.Tag     := TMenuItem(Sender).Tag;
          bFHCompareTreeLeft.Caption := clbFolderHistory.Items[bFHCompareTreeLeft.Tag];
        end;
    8 : begin
          bFHCompareTreeRight.Tag     := TMenuItem(Sender).Tag;
          bFHCompareTreeRight.Caption := clbFolderHistory.Items[bFHCompareTreeRight.Tag];
        end;
  end;
end;


procedure TFrameFolderHistory.tpFHStatsChange(Sender: TObject);
begin
  if Assigned(FSetTutorialBarText) then
    FSetTutorialBarText(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
                                                '\tutorial\fht' + IntToStr(tpFHStats.ActivePageIndex) + '.dat');  // to do make sure new layout

  if tpFHStats.ActivePageIndex = 5 then
    atlFolderHistory.VerticalMargin := Round(atlFolderHistory.Height / 2) - 10;
end;


procedure TFrameFolderHistory.tpFHStatsResize(Sender: TObject);
begin
  atlFolderHistory.VerticalMargin := Round(atlFolderHistory.Height / 2) - 10;

  Panel14.Width              := Round(tpFHStats.Width / 2);        // to do make sure new layout

  sgFHTable.ColWidths[0]     := sgFHTable.Width - 615;

  Splitter2Moved(Nil);
  splitterFHCDMoved(Nil);

  sbFHCSearchSyntax.Left     := pFHCompare.Width - 28;
end;





function TFrameFolderHistory.FindFolderHistoryItem(const xItem : string): integer;
 var
   t : integer;

 begin
  Result := -1;

  for t := 0 to clbFolderHistory.Items.Count - 1 do begin
    if clbFolderHistory.Items[t] = xItem then begin
      Result := t;

      Break;
    end;
  end;
end;


procedure TFrameFolderHistory.CompareLeftThreadOnTerminate(Sender : TObject);
 begin
  if sgFHCompareLeft.Cells[0, 1] <> '' then begin
    if CompareData[XLeftSide].Data[XFileCount] = 0 then
      lFHCompareLeft.HTMLText[0] := XText[rsFound] + ' <b>' + IntToStr(CompareData[XLeftSide].Data[XFolderCount]) + '</b> ' + XText[rsFolders] + '.'
    else if CompareData[XRightSide].Data[XFolderCount] = 0 then
      lFHCompareLeft.HTMLText[0] := XText[rsFound] + ' <b>' + IntToStr(CompareData[XLeftSide].Data[XFileCount]) + '</b> ' + XText[rsFiles] + ' (<b>' + TConvert.ConvertToUsefulUnit(CompareData[XLeftSide].Data[XFileSize]) + '</b>).'
    else
      lFHCompareLeft.HTMLText[0] := XText[rsFound] + ' <b>' + IntToStr(CompareData[XLeftSide].Data[XFileCount]) + '</b> ' + XText[rsFiles] + ' (<b>' + TConvert.ConvertToUsefulUnit(CompareData[XLeftSide].Data[XFileSize]) + '</b>) + <b>' + IntToStr(CompareData[XLeftSide].Data[XFolderCount]) + '</b> ' + XText[rsFolders] + '.';
  end
  else
    lFHCompareLeft.HTMLText[0] := XText[rsNoFilesFound];

  // == navigation logic ===================================================

  lCLPageNumber.Caption := IntToStr(lCLPagePrevious.Tag + 1);
  lCLShowing.Caption    := IntToStr(lCLPagePrevious.Tag * XSettings.General.MaxSearchResults + 1) + rsEllipsis +
                                    IntToStr((lCLPagePrevious.Tag * XSettings.General.MaxSearchResults) + XSettings.General.MaxSearchResults);

  if lCLPagePrevious.Tag = 0 then
    lCLPagePrevious.Enabled := False
  else
    lCLPagePrevious.Enabled := True;

  if CompareData[XLeftSide].Data[XFileCount] + CompareData[XLeftSide].Data[XFolderCount] < XSettings.General.MaxSearchResults then begin
    if lCLPagePrevious.Tag = 0 then
      lCLPagePrevious.Enabled := False
    else
      lCLPagePrevious.Enabled := True;

    lCLPageNext.Enabled := False;
  end
  else begin
    lCLPagePrevious.Enabled := True;
    lCLPageNext.Enabled     := False;
  end;

  // =======================================================================

  sgFHCompareLeft.EndUpdate;

  TGridUtility.SortTable(sgFHCompareLeft, sgFHCompareLeft.SortSettings.Column);

  Screen.Cursor := crDefault;
end;


procedure TFrameFolderHistory.CompareRightThreadOnTerminate(Sender : TObject);
 begin
  if sgFHCompareRight.Cells[0,1] <> '' then begin
    if CompareData[XRightSide].Data[XFileCount] = 0 then
      lFHCompareRight.HTMLText[0] := XText[rsFound] +
                                     ' <b>' + IntToStr(CompareData[XRightSide].Data[XFolderCount]) + '</b> ' +
                                     XText[rsFolders] + '.'
    else if CompareData[XRightSide].Data[XFolderCount] = 0 then
      lFHCompareRight.HTMLText[0] := XText[rsFound] +
                                     ' <b>' + IntToStr(CompareData[XRightSide].Data[XFileCount]) + '</b> ' +
                                     XText[rsFiles] +
                                     ' (<b>' + TConvert.ConvertToUsefulUnit(CompareData[XRightSide].Data[XFileSize]) + '</b>).'
	else
      lFHCompareRight.HTMLText[0] := XText[rsFound] +
                                     ' <b>' + IntToStr(CompareData[XRightSide].Data[XFileCount]) + '</b> ' +
                                     XText[rsFiles] +
                                     ' (<b>' + TConvert.ConvertToUsefulUnit(CompareData[XRightSide].Data[XFileSize]) + '</b>) + <b>' +
                                     IntToStr(CompareData[XRightSide].Data[XFolderCount]) + '</b> ' + XText[rsFolders] + '.';
  end
  else
    lFHCompareRight.HTMLText[0] := XText[rsNoFilesFound];

  // == navigation logic ===================================================

  lCRPageNumber.Caption := IntToStr(lCRPagePrevious.Tag + 1);
  lCRShowing.Caption    := IntToStr(lCRPagePrevious.Tag * XSettings.General.MaxSearchResults + 1) + rsEllipsis + IntToStr((lCRPagePrevious.Tag * XSettings.General.MaxSearchResults) + XSettings.General.MaxSearchResults);

  if lCRPagePrevious.Tag = 0 then
    lCRPagePrevious.Enabled := False
  else
    lCRPagePrevious.Enabled := True;

  if CompareData[XRightSide].Data[XFileCount] + CompareData[XRightSide].Data[XFolderCount] < XSettings.General.MaxSearchResults then begin
    if lCRPagePrevious.Tag = 0 then
      lCRPagePrevious.Enabled := False
    else
      lCRPagePrevious.Enabled := True;

    lCRPageNext.Enabled := False;
  end
  else begin
    lCRPagePrevious.Enabled := True;
    lCRPageNext.Enabled     := False;
  end;

  // =======================================================================

  sgFHCompareRight.EndUpdate;

  TGridUtility.SortTable(sgFHCompareRight, sgFHCompareLeft.SortSettings.Column);

  Screen.Cursor := crDefault;
end;


procedure TFrameFolderHistory.miQuickSearchClick(Sender: TObject);
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
    if ss = 'SetLastSQL' then begin
      //
    end
    else begin
      if ss <> '' then begin
        case Tpopupmenu(TMenuItem(Sender).GetParentMenu).Tag of
          3 : begin
                eFHCompareSearch.Text := ss;
                eFHCompareSearchChange(Nil);

                sbFHCompareSearchClick(sbFHCompareSearch);
              end;
          4 : begin
                eFHCompareDriveFolder.Text := ss;
              end;
        end;
      end;
    end;
  end;
end;


procedure TFrameFolderHistory.FileHistoryControlStatus(newstatus : boolean);
 var
  t : integer;

 begin
  bFHISelect.Enabled  := newstatus;
  sbFHGetDate.Enabled := newstatus;

  rbFHCount.Enabled                := newstatus;
  rbFHSize.Enabled                 := newstatus;

  rbFJTRToday.Enabled              := newstatus;
  rbFJTRPrevious.Enabled           := newstatus;

  for t := 0 to __FileCategoriesCount do
    FHCatButtons[t].Enabled := newstatus;

  rbFHMagCount.Enabled               := newstatus;
  rbFHMagSize.Enabled                := newstatus;

  sbFHCompareFavourites.Enabled      := newstatus;
  sbfhCompareDriveFavourites.Enabled := newstatus;
  sbFHCompareSearch.Enabled          := newstatus;
  sbFHCSearchSyntax.Enabled          := newstatus;
  eFHCompareSearch.Enabled           := newstatus;
  cbFHCompareUnits.Enabled           := newstatus;
  cbFHComparePath.Enabled            := newstatus;
  cbFHCompareColour.Enabled          := newstatus;
  sbFHCompareLeftSave.Enabled        := newstatus;
  sbFHCompareRightSave.Enabled       := newstatus;

  sbFHCompareFolderSearch.Enabled    := newstatus;
  eFHCompareDriveFolder.Enabled      := newstatus;
  sbFHCompareFolderLeftSave.Enabled  := newstatus;
  sbFHCompareFolderRightSave.Enabled := newstatus;
end;


//par1, caption; par2, text FileName; par3, zsr report, par4; html report, par5; do charts, par6; xml reports
function TFrameFolderHistory.SaveReports(var TextOptions : TTextReportOptions; var CSVOptions  : TCSVReportOptions;
                                         var HTMLOptions : THTMLReportOptions; var XinOptions  : TXinorbisReportOptions;
                                         var XMLOptions  : TXMLReportOptions;  var TreeOptions : TTreeReportOptions): boolean;

var
  lReportOutput : TStringList;

begin
  if Assigned(FSetStatusBarText) then
    FSetStatusBarText(XText[rsSavingReports] + ' ' + XText[rsPleaseWait]);

  Result := True;

  // =========================================================================
  // -- save out text version ------------------------------------------------
  // =========================================================================
  if TextOptions.FileName <> '' then begin
    lReportOutput := TStringList.Create;

     GReportText.GenerateTextReport(dataFolderHistory, lReportOutput, TextOptions);

    FreeAndNil(lReportOutput);
  end;

  // =========================================================================
  // -- save out xinorbis report ---------------------------------------------
  // =========================================================================
  if XinOptions.FileName <> '' then begin
    GReportXinorbis.GenerateXinorbisReport(dataFolderHistory, XinOptions);
  end;

  // =========================================================================
  // -- save out HTML version ------------------------------------------------
  // =========================================================================
  if HTMLOptions.FileName <> '' then begin
    GReportHTML.GenerateHTMLReport(dataFolderHistory, HTMLOptions, '');
  end;

  // =========================================================================
  // -- save out XML version -------------------------------------------------
  // =========================================================================
  if XMLOptions.FileName <> '' then begin
    lReportOutput := TStringList.Create;

    if XMLOptions.XMLData = CDataSummary then
      GReportXML.GenerateXMLOutput(dataFolderHistory, XMLOptions, lReportOutput)
    else
      GReportXML.GenerateXMLOutputFileList(XMLOptions.FileName, lReportOutput, dataFolderHistory, LayoutUnknown);

    FreeAndNil(lReportOutput);
  end;

  // =========================================================================
  // -- save out CSV version -------------------------------------------------
  // =========================================================================
  if CSVOptions.FileName <> '' then begin
    lReportOutput := TStringList.Create;

    GReportCSV.GenerateCSVReport(dataFolderHistory, lReportOutput, CSVOptions, LayoutUnknown);

    FreeAndNil(lReportOutput);
  end;

  // =========================================================================
  // -- save out Tree version ------------------------------------------------
  // =========================================================================
  if TreeOptions.FileName <> '' then begin
    if not(FIsFHUpdateThreadRunning) then begin
      lReportOutput := TStringList.Create;

      GReportTree.GenerateTreeReport(dataFolderHistory, lReportOutput, TreeOptions);

      FreeAndNil(lReportOutput);
    end;
  end;

  // =========================================================================
  // -------------------------------------------------------------------------
  // =========================================================================

  if Assigned(FSetStatusBarText) then
    FSetStatusBarText('');
end;


procedure TFrameFolderHistory.RepairFile(const scanpath, FileName : string);
 begin
  if RenameFile(FileName, ExtractFilePath(FileName) + scanpath) then
    ShowXDialog(XText[rsWarning],
                XText[rsDialog5],
                XDialogTypeInformation)
  else
    ShowXDialog(XText[rsWarning],
                XText[rsDialog6],
                XDialogTypeInformation);
end;


procedure TFrameFolderHistory.DoFHSearch(aSearchTerm : string);
begin
  {}
end;


procedure TFrameFolderHistory.DoCompareSearch(aSearchTerm : string);
begin
  if aSearchTerm <> '' then begin
	eFHCompareSearch.Text := aSearchTerm;

	sbFHCompareSearchClick(Nil);
  end;
end;


procedure TFrameFolderHistory.DoCompareDriveSearch(aSearchTerm : string);
begin
  if aSearchTerm <> '' then begin
	eFHCompareDriveFolder.Text := aSearchTerm;

	sbFHCompareFolderSearchClick(Nil);
  end;
end;


end.
3428*/

