//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "GaugeX.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TGaugeX *)
{
	new TGaugeX(NULL);
}
//---------------------------------------------------------------------------
__fastcall TGaugeX::TGaugeX(TComponent* Owner)
	: TGauge(Owner)
{
}
//---------------------------------------------------------------------------
namespace Gaugex
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TGaugeX)};
		RegisterComponents(L"Samples", classes, 0);
	}
}
//---------------------------------------------------------------------------
