//---------------------------------------------------------------------------

#ifndef XFormQuickMenuBuilderH
#define XFormQuickMenuBuilderH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>

#include <vector>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TMemo *mMain;
	TPanel *Panel1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *sbTest;
	TSpeedButton *bClear;
	TOpenDialog *odMain;
	TPopupMenu *puTest;
	TSaveDialog *sdMain;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet5;
	TTabSheet *TabSheet6;
	TSpeedButton *sbCatProg;
	TSpeedButton *sbCatSys;
	TSpeedButton *sbCatGFX;
	TSpeedButton *sbCatMov;
	TSpeedButton *sbCatSound;
	TSpeedButton *sbCatOff;
	TSpeedButton *sbCatCod;
	TSpeedButton *sbCatCom;
	TSpeedButton *sbCatOther;
	TSpeedButton *sbCatC1;
	TSpeedButton *sbCatC2;
	TSpeedButton *sbCatC4;
	TSpeedButton *sbCatC3;
	TSpeedButton *sbCatC5;
	TSpeedButton *sbCatC6;
	TSpeedButton *sbCatC8;
	TSpeedButton *sbCatC7;
	TSpeedButton *sbCatC10;
	TSpeedButton *sbCatC9;
	TSpeedButton *sbSeparator;
	TSpeedButton *sbSubMenuTemplate;
	TSpeedButton *sbDCreatedDate;
	TSpeedButton *sbDSize;
	TSpeedButton *sbDAccessedDate;
	TSpeedButton *sbDWizard;
	TSpeedButton *sbDModifiedDate;
	TSpeedButton *sbAArchive;
	TSpeedButton *sbASystem;
	TSpeedButton *sbAHidden;
	TSpeedButton *sbAReadOnly;
	TSpeedButton *sbZToday;
	TSpeedButton *sbZYesterday;
	TSpeedButton *sbZThisWeek;
	TSpeedButton *sbZThisMonth;
	TSpeedButton *sbZLastSixMonths;
	TSpeedButton *sbZLastYear;
	TRadioButton *rbZCreated;
	TRadioButton *rbZAccessed;
	TRadioButton *rbZModified;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall bClearClick(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall sbTestClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall sbCatProgClick(TObject *Sender);
	void __fastcall sbSeparatorClick(TObject *Sender);
	void __fastcall sbDCreatedDateClick(TObject *Sender);
	void __fastcall sbAArchiveClick(TObject *Sender);
	void __fastcall sbZTodayClick(TObject *Sender);
	void __fastcall FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight);
private:

	constexpr static int kAttribArchive  = 0;
	constexpr static int kAttribSystem   = 1;
	constexpr static int kAttribHidden   = 2;
	constexpr static int kAttribReadOnly = 3;

	constexpr static int kDateToday         = 0;
	constexpr static int kDateYesterday     = 1;
	constexpr static int kDateLastWeek      = 2;
	constexpr static int kDateLastMonth     = 3;
	constexpr static int kDateLastSixMonths = 4;
	constexpr static int kDateLastYear      = 5;

	constexpr static int kDialogCreatedDate  = 0;
	constexpr static int kDialogAccessedDate = 1;
	constexpr static int kDialogModifiedDate = 2;
	constexpr static int kDialogSize         = 10;
	constexpr static int kDialogSearchWizard = 20;

	std::vector<std::wstring> MenuStrings;
	std::wstring FileName = L"";

	void __fastcall MenuClick(TObject *Sender);

    void Init();

public:
	__fastcall TForm9(TComponent* Owner);
};

void OpenQuickMenuBuilder();

//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
