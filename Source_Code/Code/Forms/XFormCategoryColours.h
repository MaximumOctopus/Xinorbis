//---------------------------------------------------------------------------

#ifndef XFormCategoryColoursH
#define XFormCategoryColoursH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TShape *sCat1;
	TShape *sCat2;
	TShape *sCat3;
	TShape *sCat4;
	TShape *sCat5;
	TShape *sCat6;
	TShape *sCat7;
	TShape *sCat8;
	TShape *sCat9;
	TShape *sCat10;
	TShape *sCat11;
	TShape *sCat12;
	TShape *sCat13;
	TShape *sCat14;
	TLabel *sbFC1;
	TLabel *sbFC2;
	TLabel *sbFC3;
	TLabel *sbFC8;
	TLabel *sbFC9;
	TLabel *sbFC6;
	TLabel *sbFC7;
	TLabel *sbFC4;
	TLabel *sbFC5;
	TLabel *sbFC10;
	TLabel *sbFC11;
	TLabel *sbFC12;
	TLabel *sbFC13;
	TLabel *sbFC14;
	TShape *sCat15;
	TShape *sCat16;
	TShape *sCat17;
	TShape *sCat18;
	TShape *sCat19;
	TLabel *sbFC15;
	TLabel *sbFC16;
	TLabel *sbFC17;
	TLabel *sbFC18;
	TLabel *sbFC19;
	TImage *Image1;
	TSpeedButton *sbSearch;
	TSpeedButton *SpeedButton1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
private:

	TShape* ChartColours[19];

public:
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
