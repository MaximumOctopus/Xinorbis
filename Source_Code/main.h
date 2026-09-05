//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Graphics.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *pViews;
	TImage *Image15;
	TImage *Image16;
	TImage *Image17;
	TImage *Image25;
	TImage *Image8;
	TLabel *lAdvID3;
	TLabel *lAdvID2;
	TLabel *lTaskID7;
	TLabel *lTaskID6;
	TLabel *lAdvID1;
	TImage *Image12;
	TLabel *lTaskID1;
	TLabel *lTaskID2;
	TImage *Image13;
	TImage *Image14;
	TLabel *lTaskID3;
	TImage *Image2;
	TImage *Image24;
	TLabel *lTaskID4;
	TLabel *lTaskID5;
	TImage *Image1;
	TLabel *lTaskID8;
	TPanel *pNavigation;
	TImage *Image9;
	TImage *Image11;
	TLabel *lWelcomeScan;
	TLabel *lWelcomeFolderHistory;
	TLabel *lDataSource;
	TToolBar *tbMain;
	TPanel *pReports;
	TPanel *pMainCanvas;
	TToolButton *tbSaveReports;
	TToolButton *tbOpen;
	TToolButton *tbSettings;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *tbWizard;
	TToolButton *tbRefresh;
	TToolButton *ToolButton11;
	TToolButton *tbAbout;
	TImageList *ilBigToolbar;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *File2;
	TMenuItem *miHAbout;
	TMenuItem *miFExit;
	TSpeedButton *sbHome;
	TSpeedButton *sbNavigatePrevious;
	TSpeedButton *sbNavigateNext;
	TSpeedButton *sbToggleFolderHistory;
	TSpeedButton *sbTogglePrivacy;
	TSpeedButton *sbReportSummary;
	TSpeedButton *sbReportCSV;
	TSpeedButton *sbReportHTML;
	TSpeedButton *sbReportText;
	TSpeedButton *sbReportTree;
	TSpeedButton *sbReportXML;
	TSpeedButton *sbReportSettings;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TBevel *Bevel4;
	TMenuItem *Edit1;
	TMenuItem *Search1;
	TMenuItem *View1;
	TMenuItem *Report1;
	TMenuItem *ools1;
	TMenuItem *Detail1;
	TStatusBar *sbMain;
	TMenuItem *miDFileSizeSpread;
	TMenuItem *miDDuplicatesFileName;
	TMenuItem *miDDuplicatesFileSize;
	TMenuItem *miDFolderDetail;
	TMenuItem *miDFileAge;
	TMenuItem *miESettings;
	TMenuItem *miEReportOptions;
	TMenuItem *miEFileTypes;
	TMenuItem *N8;
	TMenuItem *miECustomiseQuickFolder;
	TMenuItem *miFScan;
	TMenuItem *N11;
	TMenuItem *miFSaveReports;
	TMenuItem *N13;
	TMenuItem *miHTutorial;
	TMenuItem *N15;
	TMenuItem *miHHelpCats;
	TMenuItem *N17;
	TMenuItem *miHHelp;
	TMenuItem *miHContextHelp;
	TMenuItem *miHUserManual;
	TMenuItem *miHReference;
	TMenuItem *miHFAQs;
	TMenuItem *N23;
	TMenuItem *miHXinorbisHome;
	TMenuItem *miHReportBug;
	TMenuItem *N26;
	TMenuItem *miHCheckForUpdates;
	TMenuItem *N28;
	TMenuItem *miRNew;
	TMenuItem *N30;
	TMenuItem *miRCustomiseCSVReport;
	TMenuItem *miRCustomiseHTMLReport;
	TMenuItem *miRCustomiseTextReport;
	TMenuItem *miRCustomiseTreeReport;
	TMenuItem *miRCustomiseXMLReport;
	TMenuItem *N36;
	TMenuItem *miRReportOptions;
	TMenuItem *N38;
	TMenuItem *miRReportBrowser;
	TMenuItem *miSSearch;
	TMenuItem *miSWizard;
	TMenuItem *N42;
	TMenuItem *miSSearchSyntax;
	TMenuItem *miTFolderHistoryInfo;
	TMenuItem *miTBackupXinorbis;
	TMenuItem *N46;
	TMenuItem *N47;
	TMenuItem *miTLanguage;
	TMenuItem *miTAddToContextMenu;
	TMenuItem *miVOpenLastReport;
	TMenuItem *miRCopyLastReportToClipboard;
	TMenuItem *N52;
	TMenuItem *miVFolderProperties;
	TMenuItem *N54;
	TMenuItem *miVCategoryColours;
	TMenuItem *N56;
	TMenuItem *miVLogs;
	TMenuItem *miTabTable;
	TMenuItem *miTabTree;
	TMenuItem *miTabOther;
	TMenuItem *miTabFolders;
	TMenuItem *miTabMagnitude;
	TMenuItem *miTabFileDates;
	TMenuItem *miTabHistory;
	TMenuItem *miTabTop101;
	TMenuItem *miTabNullFiles;
	TMenuItem *miTabUsers;
	TMenuItem *miTabTemp;
	TMenuItem *miTabNameLength;
	TMenuItem *miHTMLReport;
	TMenuItem *miCSVReport;
	TMenuItem *miTextReport;
	TMenuItem *miTreeReport;
	TMenuItem *miXMLReport;
	TSpeedButton *sbReportDate;
	TMenuItem *miDebug;
	TMenuItem *miDOpenDebug;
	TSpeedButton *sbReportJSON;
	TMenuItem *miLang1;
	TMenuItem *miLang3;
	TMenuItem *miLang4;
	TMenuItem *miLang5;
	TMenuItem *miLang6;
	TMenuItem *miLang7;
	TMenuItem *miLang8;
	TMenuItem *miLang9;
	TMenuItem *miLang10;
	TMenuItem *miLang2;
	TMenuItem *miLang12;
	TMenuItem *miLang13;
	TMenuItem *miLang11;
	TMenuItem *N1;
	TCheckBox *cbFastAnalysis;
	TImageList *ilNavToolbar_Off;
	TImageList *ilNavToolbar_On;
	TImageList *ilReports;
	TImageList *ilMenu;
	TBevel *Bevel5;
	TSpeedButton *sbToggleVirtualFiles;
	TSpeedButton *sbReportXinorbis;
	TLabel *lDataTitle;
	TShape *Shape1;
	TLabel *lReportsTitle;
	TShape *Shape2;
	TMenuItem *miJSONReport;
	TMenuItem *miDateReport;
	TSpeedButton *sbSourceLive;
	TSpeedButton *sbSourceFolderHistory;
	TImage *iScanWarning;
	TMenuItem *miXinorbisReport;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *Select1;
	TMenuItem *Select2;
	TMenuItem *Search2;
	TMenuItem *Search3;
	TMenuItem *Structure1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall lTaskID1Click(TObject *Sender);
	void __fastcall tbSaveReportsClick(TObject *Sender);
	void __fastcall tbOpenClick(TObject *Sender);
	void __fastcall tbRefreshClick(TObject *Sender);
	void __fastcall tbAboutClick(TObject *Sender);
	void __fastcall miFSaveReportsClick(TObject *Sender);
	void __fastcall miFExitClick(TObject *Sender);
	void __fastcall miESettingsClick(TObject *Sender);
	void __fastcall miEReportOptionsClick(TObject *Sender);
	void __fastcall miEFileTypesClick(TObject *Sender);
	void __fastcall miECustomiseQuickFolderClick(TObject *Sender);
	void __fastcall miVOpenLastReportClick(TObject *Sender);
	void __fastcall miRCopyLastReportToClipboardClick(TObject *Sender);
	void __fastcall miTabTableClick(TObject *Sender);
	void __fastcall miVCategoryColoursClick(TObject *Sender);
	void __fastcall miVLogsClick(TObject *Sender);
	void __fastcall miRCustomiseCSVReportClick(TObject *Sender);
	void __fastcall miRCustomiseHTMLReportClick(TObject *Sender);
	void __fastcall miRCustomiseTextReportClick(TObject *Sender);
	void __fastcall miRCustomiseTreeReportClick(TObject *Sender);
	void __fastcall miRCustomiseXMLReportClick(TObject *Sender);
	void __fastcall miRReportOptionsClick(TObject *Sender);
	void __fastcall miRReportBrowserClick(TObject *Sender);
	void __fastcall miHTMLReportClick(TObject *Sender);
	void __fastcall miTFolderHistoryInfoClick(TObject *Sender);
	void __fastcall miTBackupXinorbisClick(TObject *Sender);
	void __fastcall miTAddToContextMenuClick(TObject *Sender);
	void __fastcall miDFileSizeSpreadClick(TObject *Sender);
	void __fastcall miDDuplicatesFileNameClick(TObject *Sender);
	void __fastcall miDDuplicatesFileSizeClick(TObject *Sender);
	void __fastcall miDFolderDetailClick(TObject *Sender);
	void __fastcall miDFileAgeClick(TObject *Sender);
	void __fastcall miHTutorialClick(TObject *Sender);
	void __fastcall miHHelpCatsClick(TObject *Sender);
	void __fastcall miHHelpClick(TObject *Sender);
	void __fastcall miHContextHelpClick(TObject *Sender);
	void __fastcall miHUserManualClick(TObject *Sender);
	void __fastcall miHReferenceClick(TObject *Sender);
	void __fastcall miHFAQsClick(TObject *Sender);
	void __fastcall miHXinorbisHomeClick(TObject *Sender);
	void __fastcall miHReportBugClick(TObject *Sender);
	void __fastcall miHCheckForUpdatesClick(TObject *Sender);
	void __fastcall sbHomeClick(TObject *Sender);
	void __fastcall sbNavigatePreviousClick(TObject *Sender);
	void __fastcall sbNavigateNextClick(TObject *Sender);
	void __fastcall sbToggleFolderHistoryClick(TObject *Sender);
	void __fastcall sbTogglePrivacyClick(TObject *Sender);
	void __fastcall sbReportSettingsClick(TObject *Sender);
	void __fastcall miSSearchClick(TObject *Sender);
	void __fastcall miSWizardClick(TObject *Sender);
	void __fastcall miSSearchSyntaxClick(TObject *Sender);
	void __fastcall sbReportTreeMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbReportXMLMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall lWelcomeScanClick(TObject *Sender);
	void __fastcall miLang1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall sbToggleVirtualFilesClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall lWelcomeFolderHistoryMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ToolButton7Click(TObject *Sender);
	void __fastcall ToolButton8Click(TObject *Sender);
	void __fastcall sbReportSummaryMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbReportCSVMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbReportDateMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbReportHTMLMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbReportJSONMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbReportTextMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbReportXinorbisMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight);
	void __fastcall miDateReportClick(TObject *Sender);
	void __fastcall miJSONReportClick(TObject *Sender);
	void __fastcall miCSVReportClick(TObject *Sender);
	void __fastcall miTreeReportClick(TObject *Sender);
	void __fastcall miTextReportClick(TObject *Sender);
	void __fastcall miXMLReportClick(TObject *Sender);
	void __fastcall sbSourceLiveClick(TObject *Sender);
	void __fastcall sbSourceFolderHistoryClick(TObject *Sender);
	void __fastcall miXinorbisReportClick(TObject *Sender);
	void __fastcall miDOpenDebugClick(TObject *Sender);
	void __fastcall Select1Click(TObject *Sender);
	void __fastcall cbFastAnalysisClick(TObject *Sender);
private:

	constexpr static int kSideMenuWelcomeCount  = 2;
	constexpr static int kSideMenuTasksCount    = 8;
	constexpr static int kSideMenuAdvancedCount = 3;

	constexpr static int kToolbarSaveOff   = 0;
	constexpr static int kToolbarSaveOn    = 9;
	constexpr static int kToolbarPrefsOff  = 1;
	constexpr static int kToolbarPrefsOn   = 10;
	constexpr static int kToolbarWizardOff = 5;
	constexpr static int kToolbarWizardOn  = 8;

	std::vector<std::wstring> NavigationHistory;
	std::vector<std::wstring> MenuStrings;

	TMenuItem *LanguageMenus[13];

	TLabel *WelcomeOptions[kSideMenuWelcomeCount];
	TLabel *TaskOptions[kSideMenuTasksCount];
	TLabel *AdvancedOptions[kSideMenuAdvancedCount];

	int DataSource = 0;

	int PanelInFront = -1;
	int PanelSource = -1;

	// Application init
	void CreateFrames();
    void CreateFolderHistoryFrame();
	void FreeFrames();
	void SetLanguageText();
	void SetMenuLanguageText();
	void ConfigureObjects();
	void UpdateGUICustomNames(int);

	void UpdateMainMenu();

	void ToggleSoftwareStatus(int, bool);
    void UpdateLeftPanelStatus();

	void DoNavigationHistoryAction(const std::wstring);

	// post scan
	void PostScan();

	// Frame_Events
	void __fastcall OnNewScan(const std::wstring);
    void __fastcall OnStatusBarText(const std::wstring);

	// GUI_Navigation

	// GUI control
	void ToggleSoftwareStatus(bool);
	void SetSidePanelDisplay(int, int, int, bool);
	void SetWelcomeDisplay(int);
	void HandleResizing(int);
	void DoWelcome(int);
	void DoTask(int, int);
	void SetTasksDisplay(int);

	void AddToPageNavigationHistory(const std::wstring);

	void UpdateFrameExploder();
	void UpdateFrameMap();

	void DoPreferenceChanges();

    void AutoSaveReports(int);

	// hooks
	void OnOpenSettingsTab(int);
	void OnNewReport();
	void OnJustInTime(int);
    void OnStatusBarChange(const std::wstring);
	void OnReportsChange(int);
	void OnTutorialBarChange(const std::wstring);
	void OnResetDisplay(int);
	void OnMenuChange(const std::wstring, int, int);
	void OnProcessWindowStatusChange(int, int);
	void OnFormClose(int);
	void OnExtSetSidePanelDisplay(int, int, int, int);
	void OnProcessWindowProgressChange(int);
	void OnUpdateHistoryFinished();
	void OnChartsHaveChanged();
	void OnOpenSearchWizard(int);

	void RequestNewScan(const std::wstring, int, bool);
	void RequestNewCombineScan(int);
	void RequestNewSummary(int, bool);
	void RequestNewFHPath(const std::wstring);
	void RequestNewSearch(const std::wstring, int);
	void BuildMainFromCSV(const std::wstring, int);
	void CombineScan();

	void NewSourceAvailable(int);
	void ActivateSource(int);
	void DeactivateSource(int);

public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
