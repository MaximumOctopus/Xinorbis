//---------------------------------------------------------------------------

#ifndef XFormGetSizeBetweenH
#define XFormGetSizeBetweenH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TComboBox *cbFrom;
	TEdit *eFrom;
	TComboBox *cbTo;
	TEdit *eTo;
	TBitBtn *bOK;
	TBitBtn *BitBtn2;
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};

std::wstring OpenSizeDialog();

//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
