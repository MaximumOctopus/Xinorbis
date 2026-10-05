//---------------------------------------------------------------------------

#ifndef XFrameFolderHistoryH
#define XFrameFolderHistoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Grids.hpp>
#include <vector>

#include "CompareLeftSide.h"
#include "CompareRightSide.h"
#include "CompareFolderLeftSide.h"
#include "CompareFolderRightSide.h"

//---------------------------------------------------------------------------
class TFrameFolderHistory : public TFrame
{
__published:	// IDE-managed Components
	TPopupMenu *puFHQuickSearch;
	TPopupMenu *puFHCompareSave;
	TMenuItem *miFHCSSaveAll;
	TMenuItem *miFHCSSaveDo;
	TMenuItem *miFHCSSaveDont;
	TPopupMenu *puGenericTable;
	TMenuItem *miGenericExport;
	TMenuItem *miGenericClipboard;
	TMenuItem *miGenericClipboardHTML;
	TImageList *ilToggle;
	TImageList *ilTabs;
	TPopupMenu *puCharts;
	TMenuItem *miChartOptions;
	TMenuItem *N9;
	TMenuItem *miCOSave;
	TMenuItem *miCOCopy;
	TMenuItem *miCOAdvanced;
	TPopupMenu *puFHSelectDate;
	TPageControl *PageControl1;
	TTabSheet *tsStats;
	TPanel *Panel1;
	TComboBox *cbFHAvailableFilter;
	TComboBox *cbFHAvailableComputer;
	TSpeedButton *SpeedButton1;
	TLabel *lFHAvailableComputer;
	TLabel *Label2;
	TSpeedButton *bSelectDate;
	TTabSheet *tsSearch;
	TPageControl *pcStats;
	TTabSheet *tsChart;
	TTabSheet *tsTable;
	TTabSheet *tsTimeLine;
	TPanel *Panel2;
	TChart *vtcFolderHistory;
	TPanel *pStatsChartFiles;
	TLabel *lMagnitude;
	TPanel *pStatsChartCategory;
	TSpeedButton *sbFHCF1;
	TSpeedButton *sbFHCF2;
	TSpeedButton *sbFHCF3;
	TSpeedButton *sbFHCF4;
	TSpeedButton *sbFHCF5;
	TSpeedButton *sbFHCF6;
	TSpeedButton *sbFHCF7;
	TSpeedButton *sbFHCF8;
	TSpeedButton *sbFHCF9;
	TSpeedButton *sbFHCF10;
	TSpeedButton *sbFHCF11;
	TSpeedButton *sbFHCF12;
	TSpeedButton *sbFHCF13;
	TSpeedButton *sbFHCF14;
	TSpeedButton *sbFHCF15;
	TSpeedButton *sbFHCF16;
	TSpeedButton *sbFHCF17;
	TSpeedButton *sbFHCF18;
	TSpeedButton *sbFHCF19;
	TSpeedButton *sbFHCF20;
	TCheckBox *cbChartFiles;
	TCheckBox *cbChartCategory;
	TPanel *Panel5;
	TLabel *lFolderCount;
	TLabel *lFileCount;
	TLabel *lTotalSize;
	TLabel *lFolderCountValue;
	TLabel *lFileCountValue;
	TLabel *lTotalSizeValue;
	TCheckListBox *clbFolderHistory;
	TPanel *Panel6;
	TRadioButton *rbStatsTableToday;
	TRadioButton *rbStatsTablePrevious;
	TStringGrid *sgStatsTable;
	TPanel *Panel7;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton19;
	TLabel *Label10;
	TLabel *Label11;
	TRadioButton *rbChartCount;
	TRadioButton *rbChartSize;
	TRadioButton *rbMagnitudeCount;
	TRadioButton *rbMagnitudeSize;
	TPageControl *PageControl3;
	TTabSheet *tsCompareGrid;
	TTabSheet *tsCompareFolder;
	TTabSheet *tsCompareTree;
	TPanel *Panel8;
	TSpeedButton *sbQuickSearch;
	TSpeedButton *sbGoSearch;
	TSpeedButton *sbSearchSyntax;
	TLabel *lSearchDetails;
	TComboBox *eCompareSearch;
	TPanel *Panel9;
	TPanel *Panel10;
	TSplitter *Splitter1;
	TPanel *Panel11;
	TStringGrid *sgCompareLeft;
	TStringGrid *sgCompareRight;
	TComboBox *cbCompareUnits;
	TCheckBox *cbCompareShowFullPath;
	TCheckBox *cbCompareColourCode;
	TPanel *Panel13;
	TSpeedButton *SpeedButton3;
	TSpeedButton *sbCompareFolderSearch;
	TSpeedButton *SpeedButton5;
	TComboBox *eCompareFolderSearch;
	TCheckBox *CheckBox5;
	TPanel *Panel14;
	TStringGrid *sgCompareFolderRight;
	TSplitter *Splitter2;
	TPanel *Panel16;
	TStringGrid *sgCompareFolderLeft;
	TPanel *Panel18;
	TSpeedButton *sbCompareTree;
	TPanel *Panel19;
	TPanel *Panel20;
	TPanel *Panel21;
	TPanel *Panel22;
	TSplitter *Splitter3;
	TSpeedButton *SpeedButton7;
	TBitBtn *bCompareLeftDate;
	TSpeedButton *SpeedButton8;
	TSpeedButton *sbCompareFolderLeftSave;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *sbCompareLeftShow;
	TLabel *lCompareLeftResults;
	TPanel *Panel12;
	TSpeedButton *SpeedButton16;
	TSpeedButton *SpeedButton17;
	TSpeedButton *sbCompareFolderRightSave;
	TSpeedButton *SpeedButton21;
	TSpeedButton *SpeedButton22;
	TSpeedButton *SpeedButton23;
	TSpeedButton *SpeedButton24;
	TSpeedButton *SpeedButton25;
	TSpeedButton *sbCompareRightShow;
	TLabel *lCompareRightResults;
	TBitBtn *bCompareRightDate;
	TBitBtn *bCompareTreeLeftDate;
	TSpeedButton *SpeedButton28;
	TSpeedButton *SpeedButton29;
	TBitBtn *bCompareTreeRightDate;
	TPanel *Panel15;
	TSpeedButton *SpeedButton31;
	TSpeedButton *SpeedButton32;
	TBitBtn *bCompareFolderLeftDate;
	TPanel *Panel17;
	TSpeedButton *SpeedButton33;
	TSpeedButton *SpeedButton34;
	TBitBtn *bCompareFolderRightDate;
	TLabel *lCompareFolderLeftResults;
	TLabel *lCompareFolderRightResults;
	TTreeView *tvCompareLeft;
	TTreeView *tvCompareRight;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton27;
	TSpeedButton *SpeedButton2;
	TSpeedButton *sbStatsInfo;
	TSpeedButton *sbShowManual;
	TSpeedButton *SpeedButton30;
	TComboBox *cbFHAvailablePath;
	TPanel *Panel3;
	TBitBtn *lCLPagePrevious;
	TBitBtn *lCLPageNext;
	TLabel *lCLShowing;
	TLabel *lCLPageNumber;
	TPanel *Panel4;
	TLabel *lCRShowing;
	TLabel *lCRPageNumber;
	TBitBtn *lCRPagePrevious;
	TBitBtn *lCRPageNext;
	void __fastcall miFHCSSaveAllClick(TObject *Sender);
	void __fastcall miFHCSSaveDoClick(TObject *Sender);
	void __fastcall miFHCSSaveDontClick(TObject *Sender);
	void __fastcall miGenericExportClick(TObject *Sender);
	void __fastcall miGenericClipboardClick(TObject *Sender);
	void __fastcall miGenericClipboardHTMLClick(TObject *Sender);
	void __fastcall miCOSaveClick(TObject *Sender);
	void __fastcall miCOCopyClick(TObject *Sender);
	void __fastcall miCOAdvancedClick(TObject *Sender);
	void __fastcall puGenericTablePopup(TObject *Sender);
	void __fastcall puFHCompareSavePopup(TObject *Sender);
	void __fastcall sbFHCF1Click(TObject *Sender);
	void __fastcall bCompareTreeLeftDateClick(TObject *Sender);
	void __fastcall bCompareTreeRightDateClick(TObject *Sender);
	void __fastcall SpeedButton28Click(TObject *Sender);
	void __fastcall sbCompareTreeClick(TObject *Sender);
	void __fastcall ShowCalendar(TObject *Sender);
	void __fastcall Splitter2Moved(TObject *Sender);
	void __fastcall Splitter1Moved(TObject *Sender);
	void __fastcall bCompareFolderLeftDateClick(TObject *Sender);
	void __fastcall bCompareFolderRightDateClick(TObject *Sender);
	void __fastcall bCompareLeftDateClick(TObject *Sender);
	void __fastcall bCompareRightDateClick(TObject *Sender);
	void __fastcall cbFHAvailableComputerChange(TObject *Sender);
	void __fastcall cbFHAvailableFilterChange(TObject *Sender);
	void __fastcall cbFHAvailablePathChange(TObject *Sender);
	void __fastcall bSelectDateClick(TObject *Sender);
	void __fastcall cbCompareColourCodeClick(TObject *Sender);
	void __fastcall pcStatsChange(TObject *Sender);
	void __fastcall sgCompareLeftDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall sgCompareRightDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall sgStatsTableDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall sgCompareFolderLeftDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall tvCompareLeftExpanding(TObject *Sender, TTreeNode *Node, bool &AllowExpansion);
	void __fastcall tvCompareRightExpanding(TObject *Sender, TTreeNode *Node, bool &AllowExpansion);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton17Click(TObject *Sender);
	void __fastcall sbCompareLeftShowClick(TObject *Sender);
	void __fastcall sbCompareRightShowClick(TObject *Sender);
	void __fastcall eCompareSearchChange(TObject *Sender);
	void __fastcall eCompareSearchKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall sbGoSearchClick(TObject *Sender);
	void __fastcall sbCompareFolderSearchClick(TObject *Sender);
	void __fastcall eCompareFolderSearchKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall sbQuickSearchClick(TObject *Sender);
	void __fastcall cbChartFilesClick(TObject *Sender);
	void __fastcall cbChartCategoryClick(TObject *Sender);
	void __fastcall sbStatsInfoClick(TObject *Sender);
	void __fastcall SpeedButton32Click(TObject *Sender);
	void __fastcall sbCompareFolderLeftSaveClick(TObject *Sender);
	void __fastcall sbCompareFolderRightSaveClick(TObject *Sender);
	void __fastcall rbChartCountClick(TObject *Sender);
	void __fastcall rbStatsTableTodayClick(TObject *Sender);
	void __fastcall sbShowManualClick(TObject *Sender);
	void __fastcall sbSearchSyntaxClick(TObject *Sender);
	void __fastcall pcStatsResize(TObject *Sender);

private:

	void __fastcall miSelectDateTimeClick(TObject *Sender);

	constexpr static int kLeft  = 0;
	constexpr static int kRight = 1;

	constexpr static int kSectionFiles    = 0;
	constexpr static int kSectionCategory = 1;

	constexpr static int kCompareLeft        = 0;
	constexpr static int kCompareRight       = 1;
	constexpr static int kCompareFolderLeft  = 2;
	constexpr static int kCompareFolderRight = 3;
	constexpr static int kCompareTreeLeft    = 4;
	constexpr static int kCompareTreeRight   = 5;

	static constexpr int CompareWidths[14] = { 100, 70, 70, 70, 70, 70, 100, 55, -1, -1, -1, -1, -1, -1 };

	constexpr static int kCompareColoursX[2] = { 0x00FFFFFF, 0x0070b7fe };

	constexpr static int kImageBase[20] = {  5,  7,  9, 11, 13, 15, 17, 19, 21, 23,
										    25, 27, 29, 31, 33, 35, 37, 39, 41, 43 };

	CompareLeftSide *CLS = nullptr;
	CompareRightSide *CRS = nullptr;
	CompareFolderLeftSide *CFLS = nullptr;
	CompareFolderRightSide *CFRS = nullptr;

	std::vector<std::wstring> QuickCompareA;
    std::vector<std::wstring> QuickCompareB;

    // init
	void Init();
	void SetTableRowHeights();

	void ResetDisplay(bool, bool);

	void LoadSettings();
	void SaveSettings();

	int FindFolderHistoryItem(const std::wstring);

	void BuildInformationTabs();

	// tab stats
	void InitTableStats();
    void BuildFolderHistoryTable();
	void BuildFolderHistorySelectDataMenu();
	void BuildFolderHistory(const std::wstring, const std::wstring);
	void RepairFile(const std::wstring, const std::wstring);
	void FileHistoryControlStatus(bool);

	// tab compare
	void InitCompare();
	void CompareBuildLeft();
	void CompareBuildRight();
    void PostCompareLeft();
	void PostCompareRight();

	// tab compare folder
	void CompareFolderBuildLeft();
	void CompareFolderBuildRight();

	// timeline
    void BuildTimeLine();

public:
	__fastcall TFrameFolderHistory(TComponent* Owner);

	void DoFHSearch(const std::wstring);
	void DoCompareSearch(const std::wstring);
	void DoCompareDriveSearch(const std::wstring);

	void BuildFolderHistoryAvailable();

	int GetActivePage();
	void SetActivePage(int);

	std::wstring GetSelectedPath();

	std::wstring GetSelectedComputer();
	std::wstring GetFolderHistoryItem(int);
	std::wstring GetFolderHistoryItemSelected();

	bool GetAvailablePathContains(const std::wstring);

	std::function<void(int)> OnChartsHaveChanged;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameFolderHistory *FrameFolderHistory;
//---------------------------------------------------------------------------
#endif
