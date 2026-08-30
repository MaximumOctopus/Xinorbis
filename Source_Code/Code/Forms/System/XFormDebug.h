//---------------------------------------------------------------------------

#ifndef XFormDebugH
#define XFormDebugH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormDebug : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *lAppDataPath;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *lExePath;
	TBitBtn *bClose;
	TImage *Image1;
	TLabel *Label2;
	TLabel *lData1;
	TLabel *Label7;
	TLabel *lData2;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormDebug(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDebug *FormDebug;
//---------------------------------------------------------------------------
#endif
