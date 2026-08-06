//---------------------------------------------------------------------------

#ifndef XFormShowMD5H
#define XFormShowMD5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm22 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *lMD5;
	TBevel *Bevel1;
	TShape *Shape1;
	TLabel *lFileName;
	TBitBtn *bCancel;
	TBitBtn *bCopy;
	void __fastcall bCopyClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm22(TComponent* Owner);
};

void OpenMD5Checksum(const std::wstring, const std::wstring);

//---------------------------------------------------------------------------
extern PACKAGE TForm22 *Form22;
//---------------------------------------------------------------------------
#endif
