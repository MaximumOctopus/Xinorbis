//---------------------------------------------------------------------------

#ifndef XFrameStructureH
#define XFrameStructureH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrameStructure : public TFrame
{
__published:	// IDE-managed Components
	TPanel *pLeftSide;
	TPanel *Panel2;
	TSplitter *Splitter1;
	TPanel *pRightSide;
	TPanel *Panel4;
private:	// User declarations
public:		// User declarations
	__fastcall TFrameStructure(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameStructure *FrameStructure;
//---------------------------------------------------------------------------
#endif
