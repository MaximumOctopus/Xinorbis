//---------------------------------------------------------------------------

#ifndef XFramePropertiesH
#define XFramePropertiesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <VCLTee.Series.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>

#include <vector>

#include "JITProperties.h"

//---------------------------------------------------------------------------
class TFrameProperties : public TFrame
{
__published:	// IDE-managed Components
	TPageControl *pcProperties;
	TTabSheet *tsCategories;
	TTabSheet *tsTypes;
	TTabSheet *tsExtensions;
	TTabSheet *tsFolders;
	TTabSheet *tsMagnitude;
	TTabSheet *tsDates;
	TTabSheet *tsHistory;
	TTabSheet *tsTop101;
	TTabSheet *tsNull;
	TTabSheet *tsUsers;
	TTabSheet *tsTemporary;
	TTabSheet *tsLength;
	TStringGrid *sgCategories;
	TSplitter *splitCategories;
	TPopupMenu *puCharts;
	TMenuItem *miChartOptions;
	TMenuItem *N9;
	TMenuItem *miCOSave;
	TMenuItem *miCOCopy;
	TMenuItem *miCOAdvanced;
	TPopupMenu *puType;
	TMenuItem *miTypeExportContent;
	TMenuItem *miTypeZip;
	TMenuItem *miTypeExportCB;
	TPopupMenu *puExtensionsMain;
	TMenuItem *miOtherAddTo;
	TMenuItem *miOA1;
	TMenuItem *miOA2;
	TMenuItem *miOA3;
	TMenuItem *miOA4;
	TMenuItem *miOA5;
	TMenuItem *miOA6;
	TMenuItem *miOA7;
	TMenuItem *miOA8;
	TMenuItem *miCustomEM;
	TMenuItem *miOA9;
	TMenuItem *miOA10;
	TMenuItem *miOA11;
	TMenuItem *miOA12;
	TMenuItem *miOA13;
	TMenuItem *miOA14;
	TMenuItem *miOA15;
	TMenuItem *miOA16;
	TMenuItem *miOA17;
	TMenuItem *miOA18;
	TMenuItem *N2;
	TMenuItem *miShowOtherFiles;
	TMenuItem *miExtensionsExportTableCSV;
	TMenuItem *N37;
	TMenuItem *SaveasCSV2;
	TPopupMenu *puFolders;
	TMenuItem *miFolderMoreDetail;
	TMenuItem *miScanFromDirList;
	TMenuItem *miExploreFromDirList;
	TMenuItem *miFolderExportSelectedCB;
	TPopupMenu *puMagnitude;
	TMenuItem *miMagnitudeExport;
	TMenuItem *miMagnitudeZip;
	TMenuItem *miMagnitudeExportCB;
	TPopupMenu *puTreeDate;
	TMenuItem *MenuItem20;
	TMenuItem *MenuItem18;
	TMenuItem *MenuItem19;
	TMenuItem *miFileDatesExploreDir;
	TMenuItem *miFileDatesInfo;
	TMenuItem *miDGenerateMD5;
	TMenuItem *N11;
	TMenuItem *miFileDatesExport;
	TMenuItem *miFileDatesExportCB;
	TPopupMenu *puSearch;
	TMenuItem *miSearchOpen;
	TMenuItem *miSearchOpenCustom;
	TMenuItem *N4;
	TMenuItem *miExploreDirectory;
	TMenuItem *miSFileProperties;
	TMenuItem *miGenerateMD5;
	TMenuItem *miHexEdit;
	TMenuItem *N21;
	TMenuItem *miCopyMenu;
	TMenuItem *miCopySelected;
	TMenuItem *miCopyAll;
	TMenuItem *miMoveMenu;
	TMenuItem *miMoveSelected;
	TMenuItem *miMoveAll;
	TMenuItem *miDeleteMenu;
	TMenuItem *miDeleteSelected;
	TMenuItem *miDeleteAll;
	TMenuItem *N23;
	TMenuItem *miZIP;
	TMenuItem *N22;
	TMenuItem *miSearchExportToCB;
	TMenuItem *N36;
	TMenuItem *miSaveAs;
	TPopupMenu *puUsers;
	TMenuItem *miUsersExportSelected;
	TMenuItem *miUsersZip;
	TMenuItem *miUsersExportSelectedCB;
	TPopupMenu *puFolderConfig;
	TMenuItem *miFCO;
	TMenuItem *miFCOShowAll;
	TMenuItem *N110;
	TMenuItem *N28;
	TMenuItem *N31;
	TMenuItem *N41;
	TMenuItem *N51;
	TMenuItem *N101;
	TMenuItem *N151;
	TPopupMenu *puTableDisplay;
	TMenuItem *miTDShowAll;
	TMenuItem *miTDNonZero;
	TMenuItem *miTDUserDefined;
	TMenuItem *N13;
	TMenuItem *miTD1;
	TMenuItem *miTD2;
	TMenuItem *miTD3;
	TMenuItem *miTD4;
	TMenuItem *miTD5;
	TMenuItem *miTD6;
	TMenuItem *miTD7;
	TMenuItem *miTD8;
	TMenuItem *miTD9;
	TMenuItem *miTDCustom;
	TMenuItem *miTD10;
	TMenuItem *miTD11;
	TMenuItem *miTD12;
	TMenuItem *miTD13;
	TMenuItem *miTD14;
	TMenuItem *miTD15;
	TMenuItem *miTD16;
	TMenuItem *miTD17;
	TMenuItem *miTD18;
	TMenuItem *miTD19;
	TPopupMenu *puTable;
	TMenuItem *miTableExportSelected;
	TMenuItem *miTableZip;
	TMenuItem *miTableExportSelectedCB;
	TPopupMenu *puNullFiles;
	TMenuItem *miNFExplore;
	TMenuItem *miNFProperties;
	TPopupMenu *puNullFolders;
	TMenuItem *miNFExploreFolder;
	TMenuItem *miNFFolderProperties;
	TPopupMenu *puLength;
	TMenuItem *miLengthShowAll;
	TMenuItem *miLengthNonZero;
	TSpeedButton *sbCategoriesPie;
	TSpeedButton *sbCategoriesBar;
	TSpeedButton *sbCategoriesConfig;
	TRadioButton *rbCategoriesBySize;
	TRadioButton *rbCategoriesByQuantity;
	TChart *vtcCategories;
	TPieSeries *Series1;
	TSplitter *Splitter2;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *Panel8;
	TPanel *Panel9;
	TPanel *Panel10;
	TPanel *Panel11;
	TPanel *Panel12;
	TTreeView *tvDates;
	TStringGrid *sgFolders;
	TSplitter *splitFolders;
	TChart *vtcFolders;
	TStringGrid *sgMagnitude;
	TSplitter *splitMagnitude;
	TChart *vtcMagnitude;
	TSplitter *splitTypes;
	TChart *vtcTypes;
	TStringGrid *sgUsers;
	TSplitter *splitUsers;
	TChart *vtcUsers;
	TPanel *Panel13;
	TChart *vtcHistory;
	TCheckBox *cbExtensionsAll;
	TCheckBox *cbExtensionsOther;
	TCheckBox *cbExtensionsCustom;
	TCheckBox *cbExtensionsColourCode;
	TPanel *Panel14;
	TTreeView *tvTypes;
	TStringGrid *sgExtensions;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TRadioButton *rbDatesBySize;
	TRadioButton *rbDatesByQuantity;
	TComboBox *cbDatesUsers;
	TComboBox *cbDatesDateRange;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton5;
	TRadioButton *rbUsersSize;
	TRadioButton *rbUsersQuantity;
	TStringGrid *sgTemporary;
	TSplitter *splitTemporary;
	TChart *vtcTemporary;
	TSpeedButton *SpeedButton6;
	TRadioButton *rbTempBySize;
	TRadioButton *rbTempByQuantity;
	TPageControl *pcTop101;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TPanel *Panel1;
	TPanel *Panel15;
	TSplitter *splitTop101Size;
	TPanel *Panel16;
	TPanel *Panel17;
	TStringGrid *sgTop101Big;
	TStringGrid *sgTop101Small;
	TComboBox *cbTop101SizeUser;
	TCheckBox *cbTop101SizeColourCode;
	TPanel *Panel18;
	TComboBox *cbTop101DateUser;
	TCheckBox *cbTop101DateColourCode;
	TPanel *Panel19;
	TPanel *Panel20;
	TStringGrid *sgTop101BigDate;
	TSplitter *splitTop101Dates;
	TStringGrid *sgTop101SmallDate;
	TComboBox *cbTop101DateDate;
	TStringGrid *sgLengths;
	TChart *vtcLengths;
	TSplitter *splitLengths;
	TStringGrid *sgNullFolders;
	TSplitter *Splitter11;
	TStringGrid *sgNullFiles;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TPanel *Panel21;
	TSpeedButton *SpeedButton9;
	TSpeedButton *sbDatesCollapseNodes;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *sbFoldersConfig;
	TRadioButton *rbFoldersBySize;
	TRadioButton *rbFoldersByQuantity;
	TSpeedButton *sbFoldersMoreDetail;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TRadioButton *rbLengthSize;
	TRadioButton *rbLengthQuantity;
	TSpeedButton *SpeedButton16;
	TSpeedButton *SpeedButton17;
	TRadioButton *rbMagnitudeBySize;
	TRadioButton *rbMagnitudeByQuantity;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton19;
	TSpeedButton *SpeedButton20;
	TRadioButton *rbTypesBySize;
	TRadioButton *rbTypesByQuantity;
	TComboBox *cbUsersDisplayMode;
	TSpeedButton *SpeedButton21;
	TLabel *lHistoryFrom;
	TLabel *lHistoryInterval;
	TLabel *lHistoryTo;
	TLabel *Label4;
	TDateTimePicker *dtpHistoryFrom;
	TDateTimePicker *dtpHistoryTo;
	TComboBox *cbHistoryInterval;
	TComboBox *cbHistoryDateSelect;
	TGroupBox *gbHistoryOptions;
	TRadioButton *rbHistoryQuantity;
	TRadioButton *rbHistorySize;
	TCheckBox *cbHistoryCumulative;
	TCheckBox *cbHistoryAutoRefresh;
	TComboBox *cbHistoryUsers;
	TSpeedButton *sbHistoryRefresh;
	TLabel *lHistoryUser;
	TPieSeries *Series2;
	TImageList *ilTabs;
	TPieSeries *Series3;
	TStringGrid *sgTypes;
	TSplitter *Splitter12;
	TComboBox *ComboBox3;
	TPanel *Panel22;
	TChart *vtcDates;
	TPanel *pDatesIceCream;
	void __fastcall sbCategoriesPieClick(TObject *Sender);
	void __fastcall sbCategoriesBarClick(TObject *Sender);
	void __fastcall miOA1Click(TObject *Sender);
	void __fastcall miShowOtherFilesClick(TObject *Sender);
	void __fastcall miExtensionsExportTableCSVClick(TObject *Sender);
	void __fastcall SaveasCSV2Click(TObject *Sender);
	void __fastcall miFCOShowAllClick(TObject *Sender);
	void __fastcall miLengthShowAllClick(TObject *Sender);
	void __fastcall miLengthNonZeroClick(TObject *Sender);
	void __fastcall miFolderMoreDetailClick(TObject *Sender);
	void __fastcall miScanFromDirListClick(TObject *Sender);
	void __fastcall miExploreFromDirListClick(TObject *Sender);
	void __fastcall miFolderExportSelectedCBClick(TObject *Sender);
	void __fastcall miCOSaveClick(TObject *Sender);
	void __fastcall miCOCopyClick(TObject *Sender);
	void __fastcall miCOAdvancedClick(TObject *Sender);
	void __fastcall miMagnitudeExportClick(TObject *Sender);
	void __fastcall miMagnitudeZipClick(TObject *Sender);
	void __fastcall miMagnitudeExportCBClick(TObject *Sender);
	void __fastcall miNFExploreClick(TObject *Sender);
	void __fastcall miNFPropertiesClick(TObject *Sender);
	void __fastcall miNFExploreFolderClick(TObject *Sender);
	void __fastcall miNFFolderPropertiesClick(TObject *Sender);
	void __fastcall miSearchOpenClick(TObject *Sender);
	void __fastcall miSearchOpenCustomClick(TObject *Sender);
	void __fastcall miExploreDirectoryClick(TObject *Sender);
	void __fastcall miSFilePropertiesClick(TObject *Sender);
	void __fastcall miGenerateMD5Click(TObject *Sender);
	void __fastcall miHexEditClick(TObject *Sender);
	void __fastcall miZIPClick(TObject *Sender);
	void __fastcall miSearchExportToCBClick(TObject *Sender);
	void __fastcall miSaveAsClick(TObject *Sender);
	void __fastcall miUsersExportSelectedClick(TObject *Sender);
	void __fastcall miUsersZipClick(TObject *Sender);
	void __fastcall miUsersExportSelectedCBClick(TObject *Sender);
	void __fastcall miTableExportSelectedClick(TObject *Sender);
	void __fastcall miTableZipClick(TObject *Sender);
	void __fastcall miTableExportSelectedCBClick(TObject *Sender);
	void __fastcall MenuItem20Click(TObject *Sender);
	void __fastcall MenuItem18Click(TObject *Sender);
	void __fastcall miFileDatesExploreDirClick(TObject *Sender);
	void __fastcall miFileDatesInfoClick(TObject *Sender);
	void __fastcall miDGenerateMD5Click(TObject *Sender);
	void __fastcall miFileDatesExportClick(TObject *Sender);
	void __fastcall miFileDatesExportCBClick(TObject *Sender);
	void __fastcall miTypeExportContentClick(TObject *Sender);
	void __fastcall miTypeZipClick(TObject *Sender);
	void __fastcall miTypeExportCBClick(TObject *Sender);
	void __fastcall miTDShowAllClick(TObject *Sender);
	void __fastcall miTDNonZeroClick(TObject *Sender);
	void __fastcall miTDUserDefinedClick(TObject *Sender);
	void __fastcall miTD1Click(TObject *Sender);
	void __fastcall miCopySelectedClick(TObject *Sender);
	void __fastcall miCopyAllClick(TObject *Sender);
	void __fastcall miMoveSelectedClick(TObject *Sender);
	void __fastcall miMoveAllClick(TObject *Sender);
	void __fastcall miDeleteSelectedClick(TObject *Sender);
	void __fastcall miDeleteAllClick(TObject *Sender);
	void __fastcall sbCategoriesConfigClick(TObject *Sender);
	void __fastcall sbFoldersMoreDetailClick(TObject *Sender);
	void __fastcall sbFoldersConfigClick(TObject *Sender);
	void __fastcall SpeedButton15Click(TObject *Sender);
	void __fastcall sgFoldersDblClick(TObject *Sender);
	void __fastcall tvTypesClick(TObject *Sender);
	void __fastcall rbTypesBySizeClick(TObject *Sender);
	void __fastcall pcPropertiesChange(TObject *Sender);
	void __fastcall splitCategoriesMoved(TObject *Sender);
	void __fastcall tsExtensionsResize(TObject *Sender);
	void __fastcall splitTypesMoved(TObject *Sender);
	void __fastcall splitFoldersMoved(TObject *Sender);
	void __fastcall splitMagnitudeMoved(TObject *Sender);
	void __fastcall splitTop101DatesMoved(TObject *Sender);
	void __fastcall splitTop101SizeMoved(TObject *Sender);
	void __fastcall splitUsersMoved(TObject *Sender);
	void __fastcall splitTemporaryMoved(TObject *Sender);
	void __fastcall splitLengthsMoved(TObject *Sender);
private:	// User declarations

	static constexpr int CategoryWidths[7] = { 10, 100, 50, 52, 4, 62, 52 };
	static constexpr int TypesWidths[6] = { 100, 50, 52, 4, 60, 52 };
	static constexpr int ExtensionsWidths[8] = { 75, 65, 52, 4, 65, 52, 4, 100 };
	static constexpr int FoldersWidths[7] = { 10, 100, 50, 52, 4, 62, 52 };
	static constexpr int MagnitudesWidths[7] = { 10, 100, 40, 52, 4, 60, 52 };
	static constexpr int Top101SizeBigWidths[3] = { 100, 60, 90 };
	static constexpr int Top101SizeSmallWidths[2] = { 100, 60 };
	static constexpr int Top101DateBigWidths[4] = { 100, 65, 60, 90 };
	static constexpr int Top101DateSmallWidths[4] = { 100, 65, 60, 90 };
	static constexpr int UsersWidths[7] = { 10, 100, 50, 52, 4, 62, 52 };
	static constexpr int TempWidths[2] = { 100, 80 };
	static constexpr int LengthsWidths[7] = { 10, 100, 50, 52, 4, 62, 52 };

	static constexpr double FilterValues[8] = { 0, 1, 2, 3, 4, 5, 10, 15 };

    static const int kChartCount = 9;

	static const int kGridTemp            = 0;
	static const int kGridTop101Big       = 2;
	static const int kGridTop101Small     = 3;
	static const int kGridTop101BigDate   = 6;
	static const int kGridTop101SmallDate = 7;
	static const int kGridExtension       = 8;

	static const int kColumnIdentifier    = 0;
	static const int kColumnCountGraph    = 3;
	static const int kCOlumnSizeGraph     = 6;

	static const int kCreatedDate  = 0;
	static const int kAccessedDate = 1;
	static const int kModifiedDate = 2;

    std::vector<std::wstring> SearchStrings;

	TChart* Charts[kChartCount];

	TMenuItem* FileCategoryMenus[19];

	void Init();
	void InitMenus();

	// tab generic
	void UpdateControls();

	// tab categories
	void InitCategoriesTab();
	void BuildCategoriesTable();
	void BuildCategoriesChart(int);

	// tab types
    void InitTypesTab();

	// tab extensions
	void InitExtensionsTab();
	void BuildExtensionsTable();

	// tab folders
	void InitFoldersTab();
    void FoldersDoubleClickCell(int);

	// tab magnitude
	void InitMagnitudeTab();
	void BuildMagnitudeTable();
	void BuildMagnitudeChart(bool);

	// tab dates
	void InitDatesTab();
	void DatesUpdateDropDowns();

	// tab history
	void InitHistoryTab();
    void UpdateHistoryDropDowns();

	// tab top 101
	void InitTop101Tab();
    void Top101UpdateDropDowns();

	// tab mull
	void InitNullTab();

	// tab users
	void InitUsersTab();
    void UsersUpdateDropDowns();

	// tab temp
	void InitTempTab();

	// tab length
	void InitLengthTab();

public:		// User declarations
	__fastcall TFrameProperties(TComponent* Owner);

	int DataSource = 0;

	JITProperties JIT;

	void UpdateDisplay(int);

    void SaveSettings();

	void Update();

	std::function<void(const std::wstring)> OnNewSearch;
	std::function<void(bool, const std::wstring)> OnScanWithNewPath;
	std::function<void(int)> OnChartsChanged;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameProperties *FrameProperties;
//---------------------------------------------------------------------------
#endif
