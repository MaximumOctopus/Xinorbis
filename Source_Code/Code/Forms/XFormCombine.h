//---------------------------------------------------------------------------

#ifndef XFormCombineH
#define XFormCombineH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TBevel *Bevel4;
	TBevel *Bevel5;
	TLabel *lChoose;
	TSpeedButton *sbDrive2Add;
	TSpeedButton *sbDelete;
	TSpeedButton *SpeedButton4;
	TLabel *lFolderList;
	TBevel *Bevel6;
	TSpeedButton *sbExplore;
	TListBox *lbCombine;
	TBitBtn *bCancel;
	TBitBtn *bScan;
	TBitBtn *bLoadList;
	TBitBtn *bSaveList;
	TEdit *eDirectory;
	TOpenDialog *odCombine;
	TSaveDialog *sdCombine;
private:	// User declarations
public:		// User declarations
	__fastcall TForm13(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
//---------------------------------------------------------------------------
#endif
