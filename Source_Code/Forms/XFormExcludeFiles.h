//---------------------------------------------------------------------------

#ifndef XFormExcludeFilesH
#define XFormExcludeFilesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm14 : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *sbAdd;
	TBevel *Bevel1;
	TSpeedButton *sbRemove;
	TSpeedButton *sbEdit;
	TLabel *lPatternToExclude;
	TLabel *Label1;
	TListBox *lbExcluded;
	TBitBtn *bOK;
	TBitBtn *bCancel;
	TEdit *ePattern;
	TBitBtn *bSave;
	TBitBtn *bOpen;
	TOpenDialog *odExclude;
	TSaveDialog *sdExclude;
private:	// User declarations
public:		// User declarations
	__fastcall TForm14(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm14 *Form14;
//---------------------------------------------------------------------------
#endif
