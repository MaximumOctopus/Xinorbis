//---------------------------------------------------------------------------

#ifndef XFormEditTreeReportH
#define XFormEditTreeReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "ReportTreeOptions.h"

//---------------------------------------------------------------------------
class TFormEditTreeReport : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TSpeedButton *sbSave;
	TSpeedButton *sbEditTreeLayout;
	TSpeedButton *sbCancel;
	TComboBox *cbTreeLayouts;
	TPanel *Panel3;
	TSpeedButton *SpeedButton1;
	TGroupBox *gbCategories;
	TSpeedButton *sbSetAll;
	TSpeedButton *SpeedButton2;
	TCheckListBox *clbCategoryOptions;
	TGroupBox *gbOptions;
	TGroupBox *lReportsHTMLCustom;
	TBitBtn *sbPreview;
	TCheckBox *cbAutoRefresh;
	TMemo *Memo1;
	TCheckBox *cbFileSize;
	TCheckBox *cbAttributes;
	void __fastcall FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight);
	void __fastcall sbCancelClick(TObject *Sender);
	void __fastcall sbSetAllClick(TObject *Sender);
	void __fastcall sbEditTreeLayoutClick(TObject *Sender);
	void __fastcall sbPreviewClick(TObject *Sender);
	void __fastcall sbSaveClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall cbAutoRefreshClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall clbCategoryOptionsClick(TObject *Sender);
private:

	bool OneOffCustom = false;

	void Init();
	void BuildReport(TreeReportOptions);
    void UpdateDisplay();

public:		// User declarations
	__fastcall TFormEditTreeReport(TComponent* Owner);

	TreeReportOptions InternalReport;

	void SetOneOff(bool);
};

TreeReportOptions OpenTreeReportOptions(int, bool);

//---------------------------------------------------------------------------
extern PACKAGE TFormEditTreeReport *FormEditTreeReport;
//---------------------------------------------------------------------------
#endif
