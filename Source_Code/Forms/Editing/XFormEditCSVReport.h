//---------------------------------------------------------------------------

#ifndef XFormEditCSVReportH
#define XFormEditCSVReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "ReportCSVOptions.h"
#include <Vcl.WinXCtrls.hpp>

//---------------------------------------------------------------------------
class TFormEditCSVReport : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TSpeedButton *sbSave;
	TSpeedButton *sbEditCSVLayout;
	TSpeedButton *sbCancel;
	TComboBox *cbCSVLayouts;
	TPanel *Panel3;
	TLabel *lCSVTitle;
	TLabel *lCSVTitles;
	TLabel *lCSVAutoOpen;
	TLabel *lcsvs;
	TLabel *Label2;
	TLabel *Label27;
	TSpeedButton *SpeedButton1;
	TGroupBox *lReportsHTMLCustom;
	TBitBtn *sbPreview;
	TCheckBox *cbAutoRefresh;
	TComboBox *cbCSVSeparator;
	TComboBox *cbCSVData;
	TComboBox *cbCSVUnits;
	TMemo *Memo1;
	TToggleSwitch *tsIncludeColumnTitles;
	TToggleSwitch *tsAutoOpen;
	void __fastcall sbPreviewClick(TObject *Sender);
	void __fastcall FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight);
	void __fastcall sbSaveClick(TObject *Sender);
	void __fastcall sbCancelClick(TObject *Sender);
	void __fastcall sbEditCSVLayoutClick(TObject *Sender);
	void __fastcall cbCSVSeparatorChange(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tsIncludeColumnTitlesClick(TObject *Sender);
private:

	void Init();

	void BuildReport(CSVReportOptions);

	void UpdateDisplay();

	void AutoRefresh();

public:		// User declarations
	__fastcall TFormEditCSVReport(TComponent* Owner);

   	CSVReportOptions InternalReport;

	bool OneOffCustom = false;
};

CSVReportOptions OpenCSVReportOptions(int, bool);

//---------------------------------------------------------------------------
extern PACKAGE TFormEditCSVReport *FormEditCSVReport;
//---------------------------------------------------------------------------
#endif
