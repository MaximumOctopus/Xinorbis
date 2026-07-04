//---------------------------------------------------------------------------

#ifndef XFormFileSpreadH
#define XFormFileSpreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <VCLTee.Series.hpp>
//---------------------------------------------------------------------------
class TFormFileSpread : public TForm
{
__published:	// IDE-managed Components
	TPanel *pBottom;
	TPanel *Panel2;
	TPanel *Panel3;
	TChart *vtcSpread;
	TPageControl *pcFileSpread;
	TTabSheet *tsFileSize;
	TLabel *lBGR;
	TTabSheet *tsBenford;
	TSpeedButton *sbMoreDetail;
	TEdit *eResolution;
	TComboBox *cbResolutionUnits;
	TCheckBox *cbRange;
	TLabel *Label2;
	TEdit *eRangeFrom;
	TComboBox *cbRangeFromUnits;
	TEdit *eRangeTo;
	TComboBox *cbRangeToUnits;
	TCheckBox *cbNormalDistribution;
	TGroupBox *gbUsers;
	TGroupBox *gbChart;
	TGroupBox *GroupBox3;
	TSpeedButton *sbShow;
	TSpeedButton *sbHelp;
	TCheckBox *cbAutoRefresh;
	TSpeedButton *sbCSVReport;
	TRadioButton *rbMulticoloured;
	TRadioButton *rbGradient;
	TComboBox *cbUsers;
	TCheckBox *cbLogarithmic;
	TPopupMenu *puChart;
	TMenuItem *miOptions;
	TMenuItem *N1;
	TMenuItem *miSaveChart;
	TMenuItem *miCopyToClipboard;
	TMenuItem *miSaveData;
	TBarSeries *Series1;
	TBarSeries *Series2;
	void __fastcall sbShowClick(TObject *Sender);
	void __fastcall sbHelpClick(TObject *Sender);
	void __fastcall sbCSVReportClick(TObject *Sender);
	void __fastcall cbLogarithmicClick(TObject *Sender);
	void __fastcall FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight);
	void __fastcall vtcSpreadMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall eResolutionEnter(TObject *Sender);
	void __fastcall eResolutionExit(TObject *Sender);
	void __fastcall eResolutionKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall miSaveChartClick(TObject *Sender);
	void __fastcall miCopyToClipboardClick(TObject *Sender);
	void __fastcall miSaveDataClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall rbMulticolouredClick(TObject *Sender);
	void __fastcall pcFileSpreadChange(TObject *Sender);
	void __fastcall sbMoreDetailClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);

private:

	static const int kUnitBytes     = 0;
	static const int kUnitKilobytes = 1;
	static const int kUnitMegabytes = 2;
	static const int kUnitGigabytes = 3;

	unsigned __int64 LargestFileSize = 0;

	unsigned __int64 Coeff = 0;
	unsigned __int64 SX = 0;

    int *Spread = nullptr;

	std::wstring OldText = L"";

    std::wstring BenfordNormal[9] = { L"30.10", L"17.61", L"12.49", L"9.69", L"7.92", L"6.69", L"5.80", L"5.12", L"4.58" };
    int BenfordBoxes[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    void Init();

	void BuildFileSpread();
	void BuildBenfordsLaw();

    void ExportData(const std::wstring);

public:
	__fastcall TFormFileSpread(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFileSpread *FormFileSpread;
//---------------------------------------------------------------------------
#endif
