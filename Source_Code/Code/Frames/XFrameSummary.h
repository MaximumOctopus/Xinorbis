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
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Gauges.hpp>

#include "XIceCream.h"

#include "DriveDetails.h"

//---------------------------------------------------------------------------
class TFrameSummary : public TFrame
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *tsSummary;
	TTabSheet *tsDrive;
	TSpeedButton *SpeedButton1;
	TLabel *lSNoF;
	TLabel *lSNoD;
	TLabel *lSNoFX;
	TLabel *lSNoDX;
	TLabel *lSSoF;
	TLabel *lSSoFX;
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
	TPanel *pICQuantity;
	TPanel *pICSize;
	TGauge *gDFolder;
	TGauge *gDUsedSpace;
	TLabel *lSVolName;
	TLabel *lSVolNameValue;
	TLabel *lSVolMaxValue;
	TLabel *lSVolMax;
	TLabel *lSSerial;
	TLabel *lSSerialValue;
	TLabel *lSFileSystem;
	TLabel *lSFileSystemValue;
	TLabel *lSVolFree;
	TLabel *lSVolFreeValue;
	TLabel *lDFolder;
	TLabel *lDUsedSpace;
	TGauge *g1;
	TGauge *g2;
	TGauge *Gauge1;
	void __fastcall FrameResize(TObject *Sender);
	void __fastcall lSNoFXClick(TObject *Sender);
	void __fastcall lSAFSXClick(TObject *Sender);
	void __fastcall lSEFXClick(TObject *Sender);
	void __fastcall lSNoDXClick(TObject *Sender);
	void __fastcall lSLFXClick(TObject *Sender);
	void __fastcall lSULSSoFXClick(TObject *Sender);
private:

	XIceCream *icQuantity = nullptr;
	XIceCream *icSize = nullptr;

    DriveDetails dd;

	void Init();
	void BuildPreamble();
	void BuildSummaryLabels();

	void BuildIceCream();
	void BuildGauges();

	void BuildDriveSection();

public:
	__fastcall TFrameSummary(TComponent* Owner);

	void Destroy();

    int DataSource = 0;

	void Update();

	void SetProcessTime(const std::wstring);

	std::function<void(int)> OnDataSelected;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameSummary *FrameSummary;
//---------------------------------------------------------------------------
#endif
