//---------------------------------------------------------------------------

#ifndef XFormGetCopyMoveH
#define XFormGetCopyMoveH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormGetCopyMove : public TForm
{
__published:	// IDE-managed Components
	TLabel *lTitle;
	TSpeedButton *SpeedButton1;
	TBevel *Bevel1;
	TBitBtn *bSave;
	TBitBtn *bCancel;
	TEdit *eFolder;
	void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGetCopyMove(TComponent* Owner);
};

std::wstring GetCopyMoveFolder(const std::wstring);

//---------------------------------------------------------------------------
extern PACKAGE TFormGetCopyMove *FormGetCopyMove;
//---------------------------------------------------------------------------
#endif
