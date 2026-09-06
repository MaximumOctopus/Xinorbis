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
	TEdit *cbFHAvailablePath;
	TComboBox *cbFHAvailableFilter;
	TComboBox *cbFHAvailableComputer;
	TSpeedButton *SpeedButton1;
	TLabel *lFHAvailableComputer;
	TLabel *Label2;
	TSpeedButton *bFHISelect;
	TTabSheet *tsSearch;
	TPageControl *pcStats;
	TTabSheet *tsChart;
	TTabSheet *tsTable;
	TTabSheet *tsTimeLine;
	TPanel *Panel2;
	TChart *Chart1;
	TPanel *Panel3;
	TLabel *lMagnitude;
	TPanel *Panel4;
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
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TStringGrid *StringGrid1;
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
	TComboBox *eSearch;
	TPanel *Panel9;
	TPanel *Panel10;
	TSplitter *Splitter1;
	TPanel *Panel11;
	TStringGrid *StringGrid2;
	TStringGrid *StringGrid3;
	TComboBox *ComboBox2;
	TCheckBox *cbCompareShowFullPath;
	TCheckBox *cbCompareColourCode;
	TPanel *Panel13;
	TSpeedButton *SpeedButton3;
	TSpeedButton *sbCompareFolderSearch;
	TSpeedButton *SpeedButton5;
	TComboBox *ComboBox3;
	TCheckBox *CheckBox5;
	TPanel *Panel14;
	TStringGrid *StringGrid4;
	TSplitter *Splitter2;
	TPanel *Panel16;
	TStringGrid *StringGrid5;
	TPanel *Panel18;
	TSpeedButton *sbCompareTree;
	TPanel *Panel19;
	TPanel *Panel20;
	TPanel *Panel21;
	TPanel *Panel22;
	TSplitter *Splitter3;
	TSpeedButton *SpeedButton7;
	TBitBtn *BitBtn1;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TLabel *Label1;
	TPanel *Panel12;
	TSpeedButton *SpeedButton16;
	TSpeedButton *SpeedButton17;
	TSpeedButton *SpeedButton20;
	TSpeedButton *SpeedButton21;
	TSpeedButton *SpeedButton22;
	TSpeedButton *SpeedButton23;
	TSpeedButton *SpeedButton24;
	TSpeedButton *SpeedButton25;
	TSpeedButton *SpeedButton26;
	TLabel *Label3;
	TBitBtn *BitBtn2;
	TBitBtn *bCompareTreeLeft;
	TSpeedButton *SpeedButton28;
	TSpeedButton *SpeedButton29;
	TBitBtn *bCompareTreeRight;
	TPanel *Panel15;
	TSpeedButton *SpeedButton31;
	TSpeedButton *SpeedButton32;
	TBitBtn *BitBtn5;
	TPanel *Panel17;
	TSpeedButton *SpeedButton33;
	TSpeedButton *SpeedButton34;
	TBitBtn *BitBtn6;
	TLabel *Label4;
	TLabel *Label5;
	TTreeView *TreeView1;
	TTreeView *TreeView2;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton27;
	TSpeedButton *SpeedButton2;
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
	void __fastcall bCompareTreeLeftClick(TObject *Sender);
	void __fastcall bCompareTreeRightClick(TObject *Sender);
	void __fastcall SpeedButton28Click(TObject *Sender);
	void __fastcall SpeedButton29Click(TObject *Sender);
	void __fastcall sbCompareTreeClick(TObject *Sender);
	void __fastcall ShowCalendar(TObject *Sender);
	void __fastcall Splitter2Moved(TObject *Sender);
	void __fastcall Splitter1Moved(TObject *Sender);
	void __fastcall BitBtn5Click(TObject *Sender);
	void __fastcall BitBtn6Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall cbFHAvailableComputerChange(TObject *Sender);
	void __fastcall cbFHAvailableFilterChange(TObject *Sender);
	void __fastcall cbFHAvailablePathChange(TObject *Sender);
	void __fastcall bFHISelectClick(TObject *Sender);
	void __fastcall cbCompareColourCodeClick(TObject *Sender);
	void __fastcall pcStatsChange(TObject *Sender);
	void __fastcall StringGrid2DrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall StringGrid3DrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall StringGrid1DrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall StringGrid5DrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall TreeView1Expanding(TObject *Sender, TTreeNode *Node, bool &AllowExpansion);
	void __fastcall TreeView2Expanding(TObject *Sender, TTreeNode *Node, bool &AllowExpansion);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton17Click(TObject *Sender);
	void __fastcall SpeedButton15Click(TObject *Sender);
	void __fastcall SpeedButton26Click(TObject *Sender);
	void __fastcall eSearchChange(TObject *Sender);
	void __fastcall eSearchKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall sbGoSearchClick(TObject *Sender);
	void __fastcall sbCompareFolderSearchClick(TObject *Sender);


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

	constexpr static int kCompareColoursX[2] = { 0x00FFFFFF, 0x0070b7fe };

	constexpr static int kImageBase[20] = {  5,  7,  9, 11, 13, 15, 17, 19, 21, 23,
										    25, 27, 29, 31, 33, 35, 37, 39, 41, 43 };

	void Init();

	void ResetDisplay(bool, bool);

	void LoadSettings();
	void SaveSettings();

	// tab stats
	void InitTable();
    void BuildFolderHistoryTable();
	void BuildFolderHistorySelectDataMenu();

	// tab compare
    void InitCompare();

public:
	__fastcall TFrameFolderHistory(TComponent* Owner);

	void DoFHSearch(const std::wstring);
	void DoCompareSearch(const std::wstring);
	void DoCompareDriveSearch(const std::wstring);

	void BuildFolderHistoryAvailable();

	int GetActivePage();
	void SetActivePage(int);

	std::wstring GetSelectedPath();
	void SetSelectedPath(const std::wstring);

	std::wstring GetSelectedComputer();
	std::wstring GetFolderHistoryItem(int);
	std::wstring GetFolderHistoryItemSelected();

	bool GetAvailablePathContains(const std::wstring);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameFolderHistory *FrameFolderHistory;
//---------------------------------------------------------------------------
#endif
