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
//---------------------------------------------------------------------------
class TForm23 : public TForm
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
private:	// User declarations
public:		// User declarations
	__fastcall TForm23(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm23 *Form23;
//---------------------------------------------------------------------------
#endif
