//---------------------------------------------------------------------------

#ifndef XFrameSummaryH
#define XFrameSummaryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrameSummary : public TFrame
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *tsSummary;
	TTabSheet *TabSheet2;
	TSpeedButton *SpeedButton1;
	TLabel *lSNoF;
	TLabel *lSNoD;
	TLabel *lSNoFX;
	TLabel *lSNoDX;
	TLabel *lSSoF;
	TLabel *lSoFX;
	TLabel *lSSoFoD;
	TLabel *lSSoFODX;
	TLabel *lSAFF;
	TLabel *lSAFSX;
	TLabel *lSAFS;
	TLabel *lSAFFX;
	TLabel *lSLF;
	TLabel *lSLFSoF;
	TLabel *lSULSSoF;
	TLabel *lSEDX;
	TLabel *lSED;
	TLabel *lSEF;
	TLabel *lSEFX;
	TLabel *lProcessTime;
	TLabel *lSummaryByQuantity;
	TLabel *lSummaryBySize;
	TLabel *lSLFSoFX;
	TLabel *lSLFNoF;
	TLabel *lSLFNoFX;
	TLabel *lSULSNoF;
	TLabel *lScanPath;
	TLabel *lSULSNoFX;
	TLabel *lSLFX;
	TLabel *lSULSSoFX;
private:

	void Init();
    void BuildPreamble();
	void BuildSummaryLabels();
	void BuildGauges();

public:
	__fastcall TFrameSummary(TComponent* Owner);

    void Update();

};
//---------------------------------------------------------------------------
extern PACKAGE TFrameSummary *FrameSummary;
//---------------------------------------------------------------------------
#endif
