//---------------------------------------------------------------------------

#ifndef XFrameExploderH
#define XFrameExploderH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrameExploder : public TFrame
{
__published:	// IDE-managed Components
	TPanel *pExploderTop;
	TLabel *lExploderFolder;
	TShape *shapeExploder;
	TBitBtn *bEBack;
private:	// User declarations
public:		// User declarations
	__fastcall TFrameExploder(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameExploder *FrameExploder;
//---------------------------------------------------------------------------
#endif
