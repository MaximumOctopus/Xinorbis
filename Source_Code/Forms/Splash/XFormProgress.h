//---------------------------------------------------------------------------

#ifndef XFormProgressH
#define XFormProgressH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
class TForm18 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *iProgress1;
	TImage *iProgress2;
	TImage *iProgress3;
	TImage *iProgress4;
	TImage *iProgress5;
	TLabel *lStatus;
	TLabel *lStatus2;
	TLabel *lStatus3;
	TLabel *lAbortStatus;
	TSpeedButton *sbStop;
private:	// User declarations
public:		// User declarations
	__fastcall TForm18(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm18 *Form18;
//---------------------------------------------------------------------------
#endif
