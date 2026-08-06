//---------------------------------------------------------------------------

#ifndef XFrameSelectH
#define XFrameSelectH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrameSelect : public TFrame
{
__published:	// IDE-managed Components
	TPageControl *pcSelect;
	TTabSheet *tsScan;
	TTabSheet *tsImport;
	TBitBtn *bScanNow;
	TDriveComboBox *dcbSelect;
	TDirectoryListBox *dlbSelect;
	TBitBtn *bSelect;
	TBitBtn *bExcludeFiles;
	TBitBtn *bExcludeFolders;
	TBitBtn *bCombine;
	TBitBtn *bFavourites;
	TBitBtn *bExplore;
	TEdit *eScanPath;
	TPopupMenu *puScanHistory;
	TMenuItem *miExploreFromScanHistory;
	TMenuItem *N20;
	TMenuItem *miShowInFolderHistory;
	TMenuItem *N1;
	TMenuItem *miSaveAs;
	TPopupMenu *puQuickFolder;
	TMenuItem *miQFTitle;
	TMenuItem *N16;
	TMenuItem *miQFAdd;
	TMenuItem *N17;
	TTabSheet *tsScanHistory;
	TMemo *mImport;
	TBitBtn *bSelectImport;
	TBitBtn *bOpenImport;
	TEdit *eImportFileName;
	TPanel *Panel1;
	TBitBtn *bShowAll;
	TBitBtn *bShowYesterday;
	TBitBtn *bShowThisWeek;
	TBitBtn *bShowThisMonth;
	TBitBtn *bShowLastWeek;
	TBitBtn *bShowLastMonth;
	TStringGrid *sgScanHistory;
	void __fastcall bScanNowClick(TObject *Sender);
	void __fastcall bExploreClick(TObject *Sender);
	void __fastcall bSelectClick(TObject *Sender);
	void __fastcall bFavouritesClick(TObject *Sender);
	void __fastcall bExcludeFoldersClick(TObject *Sender);
	void __fastcall bExcludeFilesClick(TObject *Sender);
	void __fastcall bCombineClick(TObject *Sender);
	void __fastcall dlbSelectChange(TObject *Sender);
	void __fastcall puScanHistoryPopup(TObject *Sender);
	void __fastcall bSelectImportClick(TObject *Sender);
	void __fastcall bOpenImportClick(TObject *Sender);
	void __fastcall bShowAllClick(TObject *Sender);
	void __fastcall tsScanHistoryResize(TObject *Sender);
private:

	const int kScanHistoryDate = 0;
	const int kScanHistoryTime = 1;
	const int kScanHistoryPath = 2;
	const int kScanHistoryExcludeFiles   = 3;
	const int kScanHistoryExcludeFolders = 4;

	constexpr static int HistoryWidths[5] = { 68, 40, 100, 64, 64 };

	void Init();

	void __fastcall miQFTitleClick(TObject *Sender);

	// import tab
	void ReportDetail(const std::wstring);

	// report history tab
	void BuildScanHistory(int);

public:
	__fastcall TFrameSelect(TComponent* Owner);

    int DataSource = 0;

	void UpdateQuickFolders();

    void SaveSettings();

	std::function<void(const std::wstring, int, bool)> OnNewScan;
    std::function<void(int)> OnScanWithMultiple;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameSelect *FrameSelect;
//---------------------------------------------------------------------------
#endif
