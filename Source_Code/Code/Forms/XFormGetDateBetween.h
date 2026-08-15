//---------------------------------------------------------------------------

#ifndef XFormGetDateBetweenH
#define XFormGetDateBetweenH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TLabel *Label1;
	TLabel *Label2;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TMonthCalendar *mcFrom;
	TMonthCalendar *mcTo;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};

std::wstring OpenDateDialog(const std::wstring);

//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
