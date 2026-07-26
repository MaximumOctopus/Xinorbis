//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameStructure.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameStructure *FrameStructure;
//---------------------------------------------------------------------------
__fastcall TFrameStructure::TFrameStructure(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
