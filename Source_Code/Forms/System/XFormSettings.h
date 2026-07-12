//---------------------------------------------------------------------------

#ifndef XFormSettingsH
#define XFormSettingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.WinXCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSettings : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel10;
	TPanel *pPostScan;
	TLabel *lPostScan;
	TComboBox *cbIPPostScan;
	TPanel *pFavourites;
	TLabel *lQuickFolders;
	TLabel *lFavourites;
	TGroupBox *GroupBox4;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *sbQFExplore;
	TListBox *lbQuickFolders;
	TPanel *pNavigate;
	TShape *sNL1;
	TLabel *lNavigate;
	TShape *sNL2;
	TShape *sNL3;
	TLabel *lNRightSideProgress;
	TLabel *lNLeftSideProgress;
	TShape *sNL4;
	TBevel *Bevel3;
	TShape *sNL5;
	TShape *sNL6;
	TLabel *lNAllOtherTables;
	TPanel *pOptimisations;
	TLabel *lOptimisations;
	TLabel *lProgressUpdate;
	TLabel *lOJustInTime;
	TLabel *lOBuildDateTree;
	TLabel *lShowFilesInTypeBox;
	TLabel *lShowFilesInTypeBoxLimit;
	TLabel *lOGetUserDetails;
	TLabel *lOGetTempFiles;
	TComboBox *cbProgressUpdate;
	TEdit *eShowFilesInTypeBoxLimit;
	TPanel *pTemp;
	TLabel *lTypesOfTempFile;
	TSpeedButton *sbTemp;
	TSpeedButton *eDeleteTemp;
	TLabel *lTemp;
	TListBox *lbTemp;
	TEdit *eAddTemp;
	TPanel *pPaths;
	TLabel *lPaths;
	TLabel *tDataFolder;
	TSpeedButton *sbXinorbisFolder;
	TLabel *tCustomViewer;
	TSpeedButton *sbGCustomViewer;
	TEdit *eXinorbisFolder;
	TEdit *eGCustomViewer;
	TPanel *pGeneral;
	TLabel *lGeneral;
	TLabel *lTableRowHeight;
	TLabel *lDateFormat;
	TLabel *lMaxSearchResults;
	TLabel *lDefaultMaxSearchResults;
	TLabel *lRowHeight;
	TLabel *lAutoCheckUpdates;
	TLabel *lFHEnable;
	TLabel *lFHLogEnable;
	TLabel *lAllowSQLInSearch;
	TLabel *lSaveLog;
	TEdit *eRowHeight;
	TEdit *eMaxSearchResults;
	TComboBox *cbDateFormat;
	TGroupBox *GroupBox1;
	TBitBtn *bGResetGraphGradients;
	TBitBtn *bClearScanHistory;
	TBitBtn *bClearAllSettings;
	TBitBtn *bSave;
	TBitBtn *bCancel;
	TBitBtn *bHelp;
	TPanel *Panel1;
	TSpeedButton *sbGeneral;
	TSpeedButton *sbPostScan;
	TSpeedButton *sbOptimisations;
	TSpeedButton *sbPaths;
	TSpeedButton *sbAppearance;
	TSpeedButton *sbFavourites;
	TSpeedButton *sbTempFiles;
	TColorDialog *cdMain;
	TPopupMenu *puFSpecial;
	TMenuItem *miFSH1;
	TMenuItem *miFSH2;
	TMenuItem *miFSH3;
	TMenuItem *miFSH4;
	TMenuItem *miFSH5;
	TStringGrid *sgNavigationSide;
	TToggleSwitch *tsAutoCheckUpdates;
	TToggleSwitch *tsFolderHistory;
	TToggleSwitch *tsLogEnable;
	TToggleSwitch *tsAllowSQLInSearch;
	TRadioButton *rbPSDoNothing;
	TRadioButton *rbPSSummary;
	TRadioButton *rbPSInformationPage;
	TRadioButton *rbPSFolderStructure;
	TToggleSwitch *tsOJIT;
	TToggleSwitch *tsODateTree;
	TToggleSwitch *tsOFileNamesDateTree;
	TToggleSwitch *tsOFileNameDateTreeLimit;
	TToggleSwitch *tsOIgnoreOwner;
	TToggleSwitch *tsOIgnoreTemporary;
	TToggleSwitch *tsLogging;
	void __fastcall sbGeneralClick(TObject *Sender);
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall bGResetGraphGradientsClick(TObject *Sender);
	void __fastcall bClearScanHistoryClick(TObject *Sender);
	void __fastcall bClearAllSettingsClick(TObject *Sender);
	void __fastcall sbXinorbisFolderClick(TObject *Sender);
	void __fastcall sbGCustomViewerClick(TObject *Sender);
	void __fastcall sbTempClick(TObject *Sender);
	void __fastcall eDeleteTempClick(TObject *Sender);
	void __fastcall eAddTempChange(TObject *Sender);
	void __fastcall eAddTempKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall lbTempClick(TObject *Sender);
	void __fastcall sNL2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SpeedButton14Click(TObject *Sender);
	void __fastcall SpeedButton13Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton12Click(TObject *Sender);
	void __fastcall sbQFExploreClick(TObject *Sender);
	void __fastcall miFSH1Click(TObject *Sender);
	void __fastcall sgNavigationSideDrawCell(TObject *Sender, System::LongInt ACol,
          System::LongInt ARow, TRect &Rect, TGridDrawState State);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:

	static const int kChartCount = 19;

	static const int kPagePostScan      = 0;
	static const int kPageOptimisations = 1;
	static const int kPagePaths         = 2;
	static const int kPageGeneral       = 3;
	static const int kPageNavigate      = 4;
	static const int kPageUNUSED        = 5;
	static const int kPageFavourites    = 6;
	static const int kPageTemp          = 7;

	const std::wstring Things[10] = { L"Guineasaurus Rex", L"Giant wooden badgers", L"Roswell Rods", L"Cheesy comestibles", L"Anne Elk (Mrs)",
											 L"Shatner's Bassoon", L"Jelly (green)", L"Solo Polo vision", L"Fluffy kittens", L"Hovercraft full of eels" };

	TShape *bargraphs[6];

	void Init();
	void SetLanguage();
	void BuildNavigationTable();

	bool SliderStateToBoolean(TToggleSwitchState state);
	TToggleSwitchState BooleanToSliderState(bool);

public:
	__fastcall TFormSettings(TComponent* Owner);

	int OpenTabAtStart = kPageGeneral;

    void UpdateSettingsOnSave();
};

int OpenSettings(int);

//---------------------------------------------------------------------------
extern PACKAGE TFormSettings *FormSettings;
//---------------------------------------------------------------------------
#endif
