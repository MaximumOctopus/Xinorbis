//---------------------------------------------------------------------------

#ifndef XFormExcludeFoldersH
#define XFormExcludeFoldersH
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
class TForm15 : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *sbAdd;
	TBevel *Bevel1;
	TSpeedButton *sbRemove;
	TSpeedButton *sbEdit;
	TSpeedButton *sbSpecial;
	TListBox *lbExcluded;
	TBitBtn *bOK;
	TBitBtn *bCancel;
	TBitBtn *bSave;
	TBitBtn *bOpen;
	TPopupMenu *puSF;
	TMenuItem *miSF1;
	TMenuItem *miSF2;
	TMenuItem *miSF3;
	TMenuItem *miSF4;
	TSaveDialog *sdExclude;
	TOpenDialog *odExclude;
private:	// User declarations
public:		// User declarations
	__fastcall TForm15(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm15 *Form15;
//---------------------------------------------------------------------------
#endif
