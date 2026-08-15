//---------------------------------------------------------------------------

#ifndef XFrameSearchH
#define XFrameSearchH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>

#include "ProcessSearch.h"

#include "XIceCream.h"
#include <Vcl.Samples.Gauges.hpp>

//---------------------------------------------------------------------------
class TFrameSearch : public TFrame
{
__published:	// IDE-managed Components
	TPageControl *pcSearch;
	TTabSheet *tsSearch;
	TTabSheet *tsProperties;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel7;
	TStringGrid *sgSearchResults;
	TSpeedButton *sbQuickSearch;
	TSpeedButton *sbGoSearch;
	TSpeedButton *sbSearchHelp;
	TSpeedButton *sbSearchSyntax;
	TLabel *lSearchDetails;
	TCheckBox *cbSearchShowPath;
	TCheckBox *cbSearchColourCode;
	TSpeedButton *sbSCAccessed;
	TSpeedButton *sbSCModified;
	TSpeedButton *sbSCOwner;
	TSpeedButton *sbSCAttributes;
	TSpeedButton *sbSaveSearch;
	TPopupMenu *puQuickSearch;
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
	TMenuItem *miSSave;
	TComboBox *eSearch;
	TSpeedButton *sbSettings;
	TSpeedButton *sbPagePrevious;
	TSpeedButton *sbPageNext;
	TLabel *lPageNumber;
	TLabel *lShowing;
	TPanel *pICSearch;
	TLabel *lGaugeQuantity;
	TLabel *lGaugeSize;
	TGauge *gaugeQuantity;
	TGauge *gaugeSize;
	void __fastcall sbGoSearchClick(TObject *Sender);
	void __fastcall eSearchChange(TObject *Sender);
	void __fastcall eSearchKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall sbSearchHelpClick(TObject *Sender);
	void __fastcall sbSearchSyntaxClick(TObject *Sender);
	void __fastcall sbSCAccessedClick(TObject *Sender);
	void __fastcall cbSearchColourCodeClick(TObject *Sender);
	void __fastcall cbSearchShowPathClick(TObject *Sender);
	void __fastcall miSearchOpenClick(TObject *Sender);
	void __fastcall miSearchOpenCustomClick(TObject *Sender);
	void __fastcall miExploreDirectoryClick(TObject *Sender);
	void __fastcall miSFilePropertiesClick(TObject *Sender);
	void __fastcall miGenerateMD5Click(TObject *Sender);
	void __fastcall miHexEditClick(TObject *Sender);
	void __fastcall miZIPClick(TObject *Sender);
	void __fastcall miSearchExportToCBClick(TObject *Sender);
	void __fastcall miSSaveClick(TObject *Sender);
	void __fastcall miCopySelectedClick(TObject *Sender);
	void __fastcall miMoveSelectedClick(TObject *Sender);
	void __fastcall miDeleteSelectedClick(TObject *Sender);
	void __fastcall miCopyAllClick(TObject *Sender);
	void __fastcall miMoveAllClick(TObject *Sender);
	void __fastcall miDeleteAllClick(TObject *Sender);
	void __fastcall sbSaveSearchClick(TObject *Sender);
	void __fastcall puSearchPopup(TObject *Sender);
	void __fastcall FrameResize(TObject *Sender);
	void __fastcall sbSettingsClick(TObject *Sender);
	void __fastcall sbPagePreviousClick(TObject *Sender);
	void __fastcall sbPageNextClick(TObject *Sender);
	void __fastcall pcSearchChange(TObject *Sender);
private:

	const int kschVFileName     = 0;
	const int kschVSize         = 1;
	const int kschVCDate        = 2;
	const int kschVADate        = 3;
	const int kschVMDate        = 4;
	const int kschVOwner        = 5;
	const int kschVAttributes   = 6;
	const int kschIFileName     = 7;
	const int kschISize         = 8;
	const int kschICDate        = 9;
	const int kschIADate        = 10;
	const int kschIMDate        = 11;
	const int kschIColour       = 12;

	const int DefaultColumnWidths[13] = { 20, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64 };

    XIceCream *ice = nullptr;

	int Source  = 0;
	int PageNumber = 0;
	int FirstPage = 1;	// indexed from 1
	int LastPage = 1;   // indexed from 1
	//TFrameReports *FrameReports;
	bool SearchDataChanged = false;

	unsigned __int64 TotalSearchSize = 0;	// values from search thread
	int TotalSearchFilesCount = 0;			//
	int TotalSearchFoldersCount = 0;		//

	ProcessSearch *SearchEngine = nullptr;

//	FMenuChange        : TMenuChange;
//	FSetStatusBarText  : TSetStatusBarText;
//	FOpenSearchWizard  : TOpenSearchWizard;
//	FOnProcessWindowStatus : TProcessWindowStatus;

	void __fastcall miQuickSearchClick(TObject *Sender);

	void Init();
	void DeInit();

    void ClearGUI(bool);
	void UpdateGUI();
    void UpdateSearchGUI();

    void PostSearch();

	void RenderResults(int, int);

	void UpdateIceCream();

	void BuildPropertiesTab(int);

	void SearchCSVReport();

	void LoadSettings();
	void SaveSettings();

	void __fastcall OnRequestNewSearch(int, const std::wstring);
	void __fastcall OnNewResults(unsigned __int64, int, int);

public:
	__fastcall TFrameSearch(TComponent* Owner);

	int DataSource = 0;
	int DataTarget = 1;

    int CurrentTab();
	void SetTab(int);

	void ExecuteSearch(const std::wstring);

	void BuildSearchCharts();

	std::wstring GetSelectedFileName(int);
	std::wstring GetSearchText();

	std::function<void(const std::wstring, int, int)> OnMenuChange;
	std::function<void(int)> OnOpenSearchWizard;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameSearch *FrameSearch;
//---------------------------------------------------------------------------
#endif
