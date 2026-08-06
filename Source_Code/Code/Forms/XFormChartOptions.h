//---------------------------------------------------------------------------

#ifndef XFormChartOptionsH
#define XFormChartOptionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "ChartOptions.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>

//---------------------------------------------------------------------------
class TForm17 : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *lZoom;
	TLabel *lExplodeBiggest;
	TLabel *Label3;
	TShape *sLabelColour;
	TLabel *lTitleColour;
	TShape *sTitleColour;
	TShape *Shape1;
	TShape *Shape2;
	TLabel *lGradientFrom;
	TLabel *lGradientTo;
	TBitBtn *bSave;
	TBitBtn *bCancel;
	TChart *vtcOptions;
	TPieSeries *Series1;
	TBitBtn *bHelp;
	TTrackBar *tbZoom;
	TTrackBar *tbExplodeBiggest;
	TComboBox *cbLabelOptions;
	TComboBox *cbMarksType;
	TColorDialog *cdMain;
	TCheckBox *cbShowLegend;
	TCheckBox *cbShowLabels;
	TCheckBox *cbShowGradient;
	void __fastcall Shape1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Shape2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall tbZoomChange(TObject *Sender);
	void __fastcall tbExplodeBiggestChange(TObject *Sender);
	void __fastcall sLabelColourMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sTitleColourMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall cbMarksTypeChange(TObject *Sender);
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall cbShowGradientClick(TObject *Sender);
	void __fastcall cbShowLabelsClick(TObject *Sender);
	void __fastcall cbShowLegendClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
private:

	void Init();

	void SetChartFurniture(int);

public:
	__fastcall TForm17(TComponent* Owner);

	void InitOptions(ChartOptions);

	ChartOptions SetFromGui(ChartOptions);
};

ChartOptions ShowChartOptions(ChartOptions);
//---------------------------------------------------------------------------
extern PACKAGE TForm17 *Form17;
//---------------------------------------------------------------------------
#endif
