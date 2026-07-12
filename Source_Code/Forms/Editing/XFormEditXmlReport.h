//---------------------------------------------------------------------------

#ifndef XFormEditXmlReportH
#define XFormEditXmlReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.WinXCtrls.hpp>

#include "ConstantsReports.h"
#include "ReportXMLOptions.h"

//---------------------------------------------------------------------------
class TFormEditXmlReport : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel3;
	TPanel *Panel1;
	TLabel *Label1;
	TSpeedButton *sbDown;
	TSpeedButton *sbUp;
	TSpeedButton *sbRemove;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *lImportant;
	TGroupBox *GroupBox1;
	TLabel *lSI1;
	TLabel *lSI2;
	TLabel *lSI3;
	TLabel *lSI4;
	TLabel *lSI5;
	TLabel *lSI8;
	TLabel *lSI7;
	TLabel *lSI6;
	TLabel *lSI10;
	TLabel *lSI11;
	TLabel *lSI9;
	TLabel *lSI12;
	TLabel *lSI13;
	TLabel *lSI14;
	TLabel *lSI15;
	TLabel *lSI16;
	TLabel *Label6;
	TLabel *Label5;
	TLabel *Label4;
	TLabel *lSI17;
	TListBox *lbSummaryLayout;
	TGroupBox *lReportsHTMLCustom;
	TLabel *lXMLAutoOpen;
	TLabel *Label39;
	TSpeedButton *SpeedButton1;
	TBitBtn *sbPreview;
	TCheckBox *cbAutoRefresh;
	TComboBox *cbXMLData;
	TPanel *Panel2;
	TSpeedButton *sbSave;
	TSpeedButton *sbEditXMLLayout;
	TComboBox *cbXMLLayouts;
	TMemo *Memo1;
	TToggleSwitch *tsAutoOpen;
	void __fastcall FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight);
	void __fastcall lbSummaryLayoutClick(TObject *Sender);
	void __fastcall sbPreviewClick(TObject *Sender);
	void __fastcall sbEditXMLLayoutClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall sbUpClick(TObject *Sender);
	void __fastcall sbDownClick(TObject *Sender);
	void __fastcall sbRemoveClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall sbSaveClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:

	TLabel *LayoutItems[__XMLItemsCount];

	void Init();

	void AutoRefresh();
	void UpdateDisplay();
	void BuildReport(XMLReportOptions);

public:
	__fastcall TFormEditXmlReport(TComponent* Owner);

    XMLReportOptions InternalReport;
};

XMLReportOptions OpenXMLReportOptions(int, bool);

//---------------------------------------------------------------------------
extern PACKAGE TFormEditXmlReport *FormEditXmlReport;
//---------------------------------------------------------------------------
#endif
