//---------------------------------------------------------------------------

#ifndef XFrameDuplicatesH
#define XFrameDuplicatesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TFrameDuplicates : public TFrame
{
__published:	// IDE-managed Components
	TPageControl *pcDuplicates;
	TTabSheet *tsDuplicatesName;
	TTabSheet *tsDuplicatesSize;
	TPanel *Panel5;
	TSpeedButton *sbDNSave;
	TSpeedButton *sbDNCSV;
	TSpeedButton *sbDNClipboard;
	TSpeedButton *sbDNGo;
	TSpeedButton *sbDNHelp;
	TStringGrid *sgDuplicatesName;
	TPanel *Panel1;
	TSpeedButton *sbDSSave;
	TSpeedButton *sbDSCSV;
	TSpeedButton *sbDSClipboard;
	TSpeedButton *sbDSGo;
	TSpeedButton *sbDSHelp;
	TStringGrid *sgDuplicatesSize;
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
	TMenuItem *miMoveMenu;
	TMenuItem *miMoveSelected;
	TMenuItem *miDeleteMenu;
	TMenuItem *miDeleteSelected;
	TMenuItem *N23;
	TMenuItem *miSearchExportToCB;
	TMenuItem *N36;
	TMenuItem *miSSave;
	TLabel *lDSStatus;
	TLabel *lDNStatus;
	void __fastcall sbDNGoClick(TObject *Sender);
	void __fastcall sbDSGoClick(TObject *Sender);
	void __fastcall sbDNHelpClick(TObject *Sender);
	void __fastcall sbDNSaveClick(TObject *Sender);
	void __fastcall sbDNCSVClick(TObject *Sender);
	void __fastcall sbDNClipboardClick(TObject *Sender);
	void __fastcall sbDSCSVClick(TObject *Sender);
	void __fastcall sbDSHelpClick(TObject *Sender);
	void __fastcall sbDSSaveClick(TObject *Sender);
	void __fastcall sbDSClipboardClick(TObject *Sender);
	void __fastcall FrameResize(TObject *Sender);
	void __fastcall miSearchOpenClick(TObject *Sender);
	void __fastcall miSearchOpenCustomClick(TObject *Sender);
	void __fastcall miExploreDirectoryClick(TObject *Sender);
	void __fastcall miSFilePropertiesClick(TObject *Sender);
	void __fastcall miHexEditClick(TObject *Sender);
	void __fastcall miGenerateMD5Click(TObject *Sender);
	void __fastcall miCopySelectedClick(TObject *Sender);
	void __fastcall miMoveSelectedClick(TObject *Sender);
	void __fastcall miDeleteSelectedClick(TObject *Sender);
	void __fastcall miSearchExportToCBClick(TObject *Sender);
	void __fastcall miSSaveClick(TObject *Sender);
	void __fastcall puSearchPopup(TObject *Sender);
	void __fastcall sgDuplicatesNameDrawCell(TObject *Sender, System::LongInt ACol,
          System::LongInt ARow, TRect &Rect, TGridDrawState State);
	void __fastcall pcDuplicatesResize(TObject *Sender);
private:

	void Init();

	std::wstring GetSelectedFileName(int);

public:
	__fastcall TFrameDuplicates(TComponent* Owner);

	int DataSource = 0;

	void SetTab(int);
	int GetActivePage();

};
//---------------------------------------------------------------------------
extern PACKAGE TFrameDuplicates *FrameDuplicates;
//---------------------------------------------------------------------------
#endif
