//---------------------------------------------------------------------------

#ifndef XFormEditHTMLReportH
#define XFormEditHTMLReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <SHDocVw.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.OleCtrls.hpp>

#include "ConstantsReports.h"
#include "ReportHTMLOptions.h"
#include <Vcl.Dialogs.hpp>

//---------------------------------------------------------------------------
class TFormEditHTMLReport : public TForm
{
__published:	// IDE-managed Components
	TWebBrowser *wbHTML;
	TPanel *Panel3;
	TPanel *Panel2;
	TSpeedButton *sbSave;
	TSpeedButton *sbEditHTMLLayout;
	TSpeedButton *sbCancel;
	TComboBox *cbHTMLLayouts;
	TPanel *Panel1;
	TLabel *Label2;
	TLabel *Label5;
	TSpeedButton *sbRemove;
	TSpeedButton *sbUp;
	TSpeedButton *sbDown;
	TLabel *Label10;
	TLabel *lImportant;
	TPanel *pCategoryOptions;
	TSpeedButton *bCloseAC;
	TLabel *lAC;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TCheckListBox *clbCategoryOptions;
	TBitBtn *bAdvanced;
	TListBox *lbSummaryLayout;
	TGroupBox *GroupBox1;
	TLabel *Label6;
	TLabel *Label8;
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
	TLabel *Label9;
	TLabel *lSI15;
	TLabel *lSI16;
	TLabel *lSI17;
	TCheckBox *cbIncludeImages;
	TComboBox *cbLayoutSize;
	TGroupBox *lReportsHTMLCustom;
	TShape *sHTMLColour2;
	TShape *sHTMLColour1;
	TLabel *Label16;
	TLabel *Label17;
	TShape *sHTMLColour3;
	TShape *sHTMLColour9;
	TShape *sHTMLColour4;
	TLabel *Label19;
	TLabel *Label18;
	TLabel *Label3;
	TShape *sHTMLColour6;
	TShape *sHTMLColour10;
	TShape *sHTMLColour11;
	TShape *sHTMLColour7;
	TShape *sHTMLColour8;
	TLabel *Label20;
	TLabel *Label4;
	TLabel *Label7;
	TLabel *Label22;
	TLabel *Label23;
	TShape *sHTMLColour5;
	TLabel *Label21;
	TLabel *Label1;
	TLabel *lOOSingleColour;
	TSpeedButton *SpeedButton3;
	TBitBtn *sbLoadHTMLColours;
	TBitBtn *sbSaveHTMLColours;
	TBitBtn *sbPreview;
	TComboBox *cbHTMLUnits;
	TCheckBox *cbAutoRefresh;
	TColorDialog *cdHTML;
	void __fastcall lbSummaryLayoutClick(TObject *Sender);
	void __fastcall lSI1Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall sHTMLColour1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbUpClick(TObject *Sender);
	void __fastcall sbSaveClick(TObject *Sender);
	void __fastcall sbRemoveClick(TObject *Sender);
	void __fastcall sbPreviewClick(TObject *Sender);
	void __fastcall sbSaveHTMLColoursClick(TObject *Sender);
	void __fastcall sbLoadHTMLColoursClick(TObject *Sender);
	void __fastcall sbEditHTMLLayoutClick(TObject *Sender);
	void __fastcall sbDownClick(TObject *Sender);
	void __fastcall sbCancelClick(TObject *Sender);
	void __fastcall bCloseACClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall bAdvancedClick(TObject *Sender);
	void __fastcall cbIncludeImagesClick(TObject *Sender);
	void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);
	void __fastcall FormCreate(TObject *Sender);

private:

	TLabel* LayoutItems[__HTMLItemsCount];
	TShape* HTMLColoursArray[__HTMLColoursCount];

	void Init();

	void BuildTopHalf();
	void BuildBottomHalf();
	void AutoRefresh();;
	void BuildReport(HTMLReportOptions htmlro);
	void LoadHTMLColours(const std::wstring file_name);
	void SaveHTMLColours(const std::wstring file_name);

public:		// User declarations
	__fastcall TFormEditHTMLReport(TComponent* Owner);

	HTMLReportOptions InternalReport;

	bool OneOffCustom = false;
};

HTMLReportOptions OpenHTMLReportOptions(int, bool);

//---------------------------------------------------------------------------
extern PACKAGE TFormEditHTMLReport *FormEditHTMLReport;
//---------------------------------------------------------------------------
#endif
