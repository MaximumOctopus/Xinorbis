//---------------------------------------------------------------------------

#ifndef XFrameFolderHistoryH
#define XFrameFolderHistoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrameFolderHistory : public TFrame
{
__published:	// IDE-managed Components
	TPopupMenu *puFHQuickSearch;
	TPopupMenu *puFHCompareSave;
	TMenuItem *miFHCSSaveAll;
	TMenuItem *miFHCSSaveDo;
	TMenuItem *miFHCSSaveDont;
	TPopupMenu *puGenericTable;
	TMenuItem *miGenericExport;
	TMenuItem *miGenericClipboard;
	TMenuItem *miGenericClipboardHTML;
	TImageList *ilToggle;
	TImageList *ilTabs;
	TPopupMenu *puCharts;
	TMenuItem *miChartOptions;
	TMenuItem *N9;
	TMenuItem *miCOSave;
	TMenuItem *miCOCopy;
	TMenuItem *miCOAdvanced;
	TPopupMenu *puFHSelectDate;
	TPageControl *PageControl1;
	TTabSheet *tsStats;
	TPanel *Panel1;
	TEdit *Edit2;
	TComboBox *ComboBox1;
	TComboBox *cbFHAvailableComputer;
	TSpeedButton *SpeedButton1;
	TLabel *lFHAvailableComputer;
	TLabel *Label2;
	TCheckBox *CheckBox1;
	TSpeedButton *SpeedButton2;
	TTabSheet *tsSearch;
	TPageControl *PageControl2;
	TTabSheet *tsChart;
	TTabSheet *tsTable;
	TTabSheet *tsTimeLine;
	TPanel *Panel2;
	TChart *Chart1;
	TPanel *Panel3;
	TLabel *lMagnitude;
	TPanel *Panel4;
	TSpeedButton *sbFHCF1;
	TSpeedButton *sbFHCF2;
	TSpeedButton *sbFHCF3;
	TSpeedButton *sbFHCF4;
	TSpeedButton *sbFHCF5;
	TSpeedButton *sbFHCF6;
	TSpeedButton *sbFHCF7;
	TSpeedButton *sbFHCF8;
	TSpeedButton *sbFHCF9;
	TSpeedButton *sbFHCF10;
	TSpeedButton *sbFHCF11;
	TSpeedButton *sbFHCF12;
	TSpeedButton *sbFHCF13;
	TSpeedButton *sbFHCF14;
	TSpeedButton *sbFHCF15;
	TSpeedButton *sbFHCF16;
	TSpeedButton *sbFHCF17;
	TSpeedButton *sbFHCF18;
	TSpeedButton *sbFHCF19;
	TSpeedButton *sbFHCF20;
	TCheckBox *cbFiles;
	TCheckBox *cbCategory;
	TPanel *Panel5;
	TLabel *lFolderCount;
	TLabel *lFileCount;
	TLabel *lTotalSize;
	TLabel *lFolderCountValue;
	TLabel *lFileCountValue;
	TLabel *lTotalSizeValue;
	TCheckListBox *CheckListBox1;
	TPanel *Panel6;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TStringGrid *StringGrid1;
	TPanel *Panel7;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton19;
	TLabel *Label10;
	TLabel *Label11;
	TRadioButton *RadioButton3;
	TRadioButton *rbSize;
	TRadioButton *rbMagnitudeCount;
	TRadioButton *rbMagnitudeSize;
	TPageControl *PageControl3;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet6;
	void __fastcall miFHCSSaveAllClick(TObject *Sender);
	void __fastcall miFHCSSaveDoClick(TObject *Sender);
	void __fastcall miFHCSSaveDontClick(TObject *Sender);
	void __fastcall miGenericExportClick(TObject *Sender);
	void __fastcall miGenericClipboardClick(TObject *Sender);
	void __fastcall miGenericClipboardHTMLClick(TObject *Sender);
	void __fastcall miCOSaveClick(TObject *Sender);
	void __fastcall miCOCopyClick(TObject *Sender);
	void __fastcall miCOAdvancedClick(TObject *Sender);
	void __fastcall puGenericTablePopup(TObject *Sender);
	void __fastcall puFHCompareSavePopup(TObject *Sender);
	void __fastcall sbFHCF1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrameFolderHistory(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameFolderHistory *FrameFolderHistory;
//---------------------------------------------------------------------------
#endif
