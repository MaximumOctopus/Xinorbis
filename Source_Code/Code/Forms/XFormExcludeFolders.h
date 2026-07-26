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
	TCheckBox *cbIgnoreVirtual;
	void __fastcall bOpenClick(TObject *Sender);
	void __fastcall sbSpecialClick(TObject *Sender);
	void __fastcall lbExcludedClick(TObject *Sender);
	void __fastcall sbRemoveClick(TObject *Sender);
	void __fastcall sbEditClick(TObject *Sender);
	void __fastcall bSaveClick(TObject *Sender);
	void __fastcall sbAddClick(TObject *Sender);
	void __fastcall miSF1Click(TObject *Sender);
private:

	void Init();

	void ToggleSave();

public:
	__fastcall TForm15(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm15 *Form15;
//---------------------------------------------------------------------------
#endif
