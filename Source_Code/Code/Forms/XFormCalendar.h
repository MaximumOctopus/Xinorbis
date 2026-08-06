//---------------------------------------------------------------------------

#ifndef XFormCalendarH
#define XFormCalendarH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class TForm21 : public TForm
{
__published:	// IDE-managed Components
	TLabel *lSelected;
	TLabel *lAvailableTimes;
	TPanel *Panel1;
	TShape *Shape1;
	TShape *Shape2;
	TShape *Shape3;
	TShape *Shape4;
	TShape *Shape5;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TSpinEdit *SpinEdit1;
	TListBox *cbTimes;
	TPanel *Panel2;
	TCheckBox *cbExcludeEmpty;
	TBitBtn *bUse;
	TBitBtn *bCancel;
	TPanel *Panel3;
	TLabel *lTitle;
private:

	constexpr static int GridColours[6] = { 0x00EEEEEE, 0x00C6FFC9, 0x00C1FFFF, 0x00B9DEFF, 0x00B7B7FF, 0x00FFD5FE };


public:
	__fastcall TForm21(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm21 *Form21;
//---------------------------------------------------------------------------
#endif
