//---------------------------------------------------------------------------

#ifndef XFormSelectLanguageH
#define XFormSelectLanguageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>

#include "ConstantsLanguage.h"

//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TImage *i1;
	TImage *i2;
	TImage *i3;
	TImage *i4;
	TImage *i5;
	TImage *i6;
	TImage *i7;
	TImage *i9;
	TImage *i8;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TImage *Image1;
	TImage *i10;
	TLabel *Label10;
	TImage *i11;
	TLabel *Label11;
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall i11Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);

	LanguageType SelectedLanguage = LanguageType::kUndefined;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
