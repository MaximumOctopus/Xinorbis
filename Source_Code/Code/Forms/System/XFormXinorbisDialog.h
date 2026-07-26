//---------------------------------------------------------------------------

#ifndef XFormXinorbisDialogH
#define XFormXinorbisDialogH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>

static const int XDialogTypeInformation = 0;
static const int XDialogTypeWarning     = 1;
static const int XDialogTypeXinorbis    = 2;

//---------------------------------------------------------------------------
class TFormXDialog : public TForm
{
__published:	// IDE-managed Components
	TImage *iInformation;
	TImage *iXinorbis;
	TImage *iWarning;
	TLabel *lTitle;
	TLabel *lBody;
	TBitBtn *BitBtn1;
	TBitBtn *bCopyToClipboard;
	void __fastcall bCopyToClipboardClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormXDialog(TComponent* Owner);

};

void ShowXDialog(const std::wstring, const std::wstring, int);

//---------------------------------------------------------------------------
extern PACKAGE TFormXDialog *FormXDialog;
//---------------------------------------------------------------------------
#endif
