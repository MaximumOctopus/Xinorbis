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
//---------------------------------------------------------------------------
class TFrameSearch : public TFrame
{
__published:	// IDE-managed Components
	TPageControl *pcSearch;
	TTabSheet *tsSearch;
	TTabSheet *tsDuplicatesName;
	TTabSheet *tsDuplicatesSize;
	TTabSheet *tsProperties;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TStringGrid *StringGrid1;
	TStringGrid *StringGrid2;
	TPanel *Panel6;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TPanel *Panel7;
	TStringGrid *sgSearchResults;
	TSpeedButton *sbQuickSearch;
	TSpeedButton *sbGoSearch;
	TEdit *eSearch;
	TSpeedButton *sbSearchHelp;
	TSpeedButton *sbSearchSyntax;
	TLabel *Label1;
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
	void __fastcall sbGoSearchClick(TObject *Sender);
	void __fastcall eSearchChange(TObject *Sender);
	void __fastcall eSearchKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall sbQuickSearchClick(TObject *Sender);
	void __fastcall sbSearchHelpClick(TObject *Sender);
	void __fastcall sbSearchSyntaxClick(TObject *Sender);
	void __fastcall sbSCAccessedClick(TObject *Sender);
	void __fastcall cbSearchColourCodeClick(TObject *Sender);
	void __fastcall cbSearchShowPathClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrameSearch(TComponent* Owner);

	void SetTab(int);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameSearch *FrameSearch;
//---------------------------------------------------------------------------
#endif
