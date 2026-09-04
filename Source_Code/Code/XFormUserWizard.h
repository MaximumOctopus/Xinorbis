//---------------------------------------------------------------------------

#ifndef XFormUserWizardH
#define XFormUserWizardH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm12 : public TForm
{
__published:	// IDE-managed Components
	TPanel *pSize;
	TLabel *Label5;
	TPanel *pPopular;
	TLabel *Label6;
	TPanel *pEnd;
	TLabel *Label4;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TLabel *Label9;
	TLabel *Label10;
	TPanel *pProductivity;
	TLabel *Label2;
	TPanel *pMultimedia;
	TLabel *Label3;
	TPanel *pCompressed;
	TLabel *Label7;
	TPanel *pSystem;
	TLabel *Label8;
	TPanel *pTitle;
	TLabel *Label1;
	TPanel *Panel1;
	TPanel *Panel2;
	TSpeedButton *sbOK;
	TSpeedButton *SpeedButton9;
	TSpeedButton *sbPrevious;
	TSpeedButton *sbNext;
	TSpeedButton *sbSearch;
	TRadioButton *rbSelectMultimedia;
	TRadioButton *rbSelectProductivity;
	TRadioButton *rbSelectCompressed;
	TRadioButton *rbSelectSystem;
	TRadioButton *rbSelectPopular;
	TRadioButton *rbPrograms;
	TRadioButton *rbSystem;
	TRadioButton *rbAllSystem;
	TRadioButton *rbAllCompressed;
	TRadioButton *rbOffice;
	TRadioButton *rbProgramming;
	TRadioButton *rbCompressed;
	TRadioButton *rbToday;
	TRadioButton *rbYesterday;
	TRadioButton *rbThisWeek;
	TRadioButton *rbThisMonth;
	TRadioButton *rbSelectFileSizes;
	TRadioButton *rbSize1;
	TRadioButton *rbSize2;
	TRadioButton *rbSize3;
	TRadioButton *rbSize4;
	TRadioButton *rbSize5;
	TRadioButton *rbSize6;
	TCheckBox *cbMultimedia1;
	TCheckBox *cbMultimedia2;
	TCheckBox *cbMultimedia3;
	TGroupBox *GroupBox1;
	TRadioButton *rbCreated;
	TRadioButton *rbAccessed;
	TRadioButton *rbModified;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall sbPreviousClick(TObject *Sender);
	void __fastcall sbNextClick(TObject *Sender);
	void __fastcall sbOKClick(TObject *Sender);
	void __fastcall sbSearchClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall rbSelectMultimediaClick(TObject *Sender);
	void __fastcall rbSize1Click(TObject *Sender);
	void __fastcall rbTodayClick(TObject *Sender);
private:

	constexpr static int kTypeMultimedia   = 1;
	constexpr static int kTypeProductivity = 2;
	constexpr static int kTypeCompressed   = 3;
	constexpr static int kTypeSystem       = 4;
	constexpr static int kTypePopular      = 10;
	constexpr static int kTypeSize         = 20;

	constexpr static int kPageMain         = 0;
	constexpr static int kPageEnd          = 1;

	constexpr static int kDateToday        = 1;
	constexpr static int kDateYesterday    = 2;
	constexpr static int kDateLastWeek     = 3;
	constexpr static int kDateLastMonth    = 4;

	constexpr static int kSizeLess1MB      = 1;
	constexpr static int kSize1To10MB      = 2;
	constexpr static int kSize10To50MB     = 3;
	constexpr static int kSize50To100MB    = 4;
	constexpr static int kSize100MBTo1GB   = 5;
	constexpr static int kSizeGreater1GB   = 6;

	int CurrentPage = 0;

	int SelectedCategory = 1;

	int SelectedDateRange = 1;
	int SelectedSizeRange = 1;

public:
	__fastcall TForm12(TComponent* Owner);

    std::wstring BuildSearchString();
};

std::wstring OpenUserWizard();

//---------------------------------------------------------------------------
extern PACKAGE TForm12 *Form12;
//---------------------------------------------------------------------------
#endif
