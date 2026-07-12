//---------------------------------------------------------------------------

#ifndef XFormAboutH
#define XFormAboutH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormAbout : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TLabel *lDate;
	TLabel *lVersion;
	TLabel *lAuthor;
	TImage *Image7;
	TGroupBox *gbSocialMedia;
	TLabel *Label2;
	TLabel *Label12;
	TLabel *Label5;
	TLabel *Label3;
	TLabel *Label13;
	TGroupBox *gbThanks;
	TImage *Image4;
	TImage *Image5;
	TLabel *Label9;
	TLabel *Label10;
	TImage *Image3;
	TLabel *Label11;
	TImage *Image2;
	TLabel *Label1;
	TImage *Image8;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *lDevCats;
	TImage *Image9;
	TLabel *Label17;
	TGroupBox *GroupBox3;
	TLabel *Label6;
	TLabel *lMode;
	TLabel *lDataPath;
	TLabel *lSystemPath;
	TLabel *Label18;
	TLabel *Label19;
	TBitBtn *bClose;
	void __fastcall Label12Click(TObject *Sender);
	void __fastcall Label13Click(TObject *Sender);
	void __fastcall Label16Click(TObject *Sender);
	void __fastcall lDevCatsClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAbout *FormAbout;
//---------------------------------------------------------------------------
#endif
