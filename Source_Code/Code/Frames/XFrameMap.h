//---------------------------------------------------------------------------

#ifndef XFrameMapH
#define XFrameMapH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrameMap : public TFrame
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *lMapFolder;
	TLabel *lMapSize;
	TShape *shapeMap;
	TComboBox *cbMapSizeSelect;
private:	// User declarations
public:		// User declarations
	__fastcall TFrameMap(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameMap *FrameMap;
//---------------------------------------------------------------------------
#endif
