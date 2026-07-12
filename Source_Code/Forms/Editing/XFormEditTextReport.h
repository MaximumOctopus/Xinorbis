//---------------------------------------------------------------------------

#ifndef XFormEditTextReportH
#define XFormEditTextReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "ConstantsReports.h"
#include "ReportTextOptions.h"

//---------------------------------------------------------------------------
class TFormEditTextReport : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TSpeedButton *sbSave;
	TSpeedButton *sbEditTextLayout;
	TComboBox *cbTextLayouts;
	TPanel *Panel3;
	TLabel *Label1;
	TSpeedButton *sbRemove;
	TSpeedButton *sbUp;
	TSpeedButton *sbDown;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *lImportant;
	TLabel *Label6;
	TLabel *Label5;
	TLabel *Label4;
	TSpeedButton *SpeedButton3;
	TPanel *pCategoryOptions;
	TSpeedButton *bCloseAC;
	TLabel *lAC;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TCheckListBox *clbCategoryOptions;
	TGroupBox *GroupBox1;
	TLabel *lSI1;
	TLabel *lSI2;
	TLabel *lSI3;
	TLabel *lSI4;
	TLabel *lSI5;
	TLabel *lSI8;
	TLabel *lSI7;
	TLabel *lSI6;
	TLabel *lSI12;
	TLabel *lSI11;
	TLabel *lSI10;
	TLabel *lSI9;
	TLabel *lSI13;
	TLabel *lSI14;
	TLabel *lSI15;
	TLabel *lSI16;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *lSI17;
	TListBox *lbSummaryLayout;
	TBitBtn *bAdvanced;
	TGroupBox *lReportsHTMLCustom;
	TBitBtn *sbPreview;
	TCheckBox *cbAutoRefresh;
	TMemo *Memo1;
	TSpeedButton *sbCancel;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight);
	void __fastcall sbSaveClick(TObject *Sender);
	void __fastcall sbEditTextLayoutClick(TObject *Sender);
	void __fastcall sbUpClick(TObject *Sender);
	void __fastcall sbDownClick(TObject *Sender);
	void __fastcall sbRemoveClick(TObject *Sender);
	void __fastcall sbPreviewClick(TObject *Sender);
	void __fastcall bAdvancedClick(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall bCloseACClick(TObject *Sender);
	void __fastcall lbSummaryLayoutClick(TObject *Sender);
	void __fastcall Panel2Click(TObject *Sender);
	void __fastcall lSI1Click(TObject *Sender);
	void __fastcall lbSummaryLayoutDblClick(TObject *Sender);
private:

	TLabel *LayoutItems[__TextItemsCount];

	void Init();

	void AutoRefresh();
	void UpdateDisplay();
	void BuildReport(TextReportOptions);

public:

	__fastcall TFormEditTextReport(TComponent* Owner);

	TextReportOptions InternalReport;

   	bool OneOffCustom = false;
};

TextReportOptions OpenTextReportOptions(int, bool);

//---------------------------------------------------------------------------
extern PACKAGE TFormEditTextReport *FormEditTextReport;
//---------------------------------------------------------------------------
#endif
