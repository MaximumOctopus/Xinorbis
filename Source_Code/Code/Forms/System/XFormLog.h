//---------------------------------------------------------------------------

#ifndef XFormLogH
#define XFormLogH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormLog : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TMemo *mLog;
	TBitBtn *bSave;
	TBitBtn *bClose;
	TBitBtn *bRefresh;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall bRefreshClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormLog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLog *FormLog;
//---------------------------------------------------------------------------
#endif
