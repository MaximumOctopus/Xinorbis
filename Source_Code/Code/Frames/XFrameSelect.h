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
//---------------------------------------------------------------------------
class TFrameSelect : public TFrame
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *tsSelectFolder;
	TTabSheet *TabSheet2;
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
	void __fastcall bScanNowClick(TObject *Sender);
	void __fastcall bExploreClick(TObject *Sender);
	void __fastcall bSelectClick(TObject *Sender);
	void __fastcall bFavouritesClick(TObject *Sender);
	void __fastcall bExcludeFoldersClick(TObject *Sender);
	void __fastcall bExcludeFilesClick(TObject *Sender);
	void __fastcall bCombineClick(TObject *Sender);
	void __fastcall dlbSelectChange(TObject *Sender);
	void __fastcall puScanHistoryPopup(TObject *Sender);
private:

	void Init();

public:
	__fastcall TFrameSelect(TComponent* Owner);

	std::function<void(const std::wstring)> OnNewScan;
    std::function<void(int)> OnScanWithMultiple;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameSelect *FrameSelect;
//---------------------------------------------------------------------------
#endif
