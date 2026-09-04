//---------------------------------------------------------------------------

#ifndef XFormCalendarH
#define XFormCalendarH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Grids.hpp>

#include <vector>

//---------------------------------------------------------------------------
class TForm21 : public TForm
{
__published:	// IDE-managed Components
	TLabel *lSelected;
	TLabel *lAvailableTimes;
	TPanel *Panel1;
	TShape *Shape1;
	TShape *Shape2;
	TShape *Shape3;
	TShape *Shape4;
	TShape *Shape5;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TSpinEdit *seYear;
	TListBox *cbTimes;
	TPanel *Panel2;
	TCheckBox *cbExcludeEmpty;
	TBitBtn *bUse;
	TBitBtn *bCancel;
	TPanel *Panel3;
	TLabel *lTitle;
	TStringGrid *sgCalendar;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall seYearEnter(TObject *Sender);
	void __fastcall seYearExit(TObject *Sender);
	void __fastcall seYearChange(TObject *Sender);
	void __fastcall cbTimesClick(TObject *Sender);
	void __fastcall sgCalendarSelectCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          bool &CanSelect);
	void __fastcall sgCalendarDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:

	constexpr static int kGridColours[6] = { 0x00EEEEEE, 0x00C6FFC9, 0x00C1FFFF, 0x00B9DEFF, 0x00B7B7FF, 0x00FFD5FE };

	constexpr static int ColWidths[38] = { 69, 20, 20, 20, 20, 21, 20, 20, 20, 20,
										   20, 20, 20, 21, 20, 20, 20, 20, 20, 20,
										   20, 20, 20, 20, 20, 20, 21, 20, 20, 20,
										   19, 19, 20, 20, 20, 21, 20, 20 };

	int FileHistoryData[37][12];
	std::vector<std::wstring> FileHistoryInput;

	std::wstring OldText = L"";

    std::wstring SelectedDate = L"";

	void Init();

	int GetLastYear();
	void BuildDate(int);

public:
	__fastcall TForm21(TComponent* Owner);

	std::wstring SelectedDateTime = L"";

    void Add(const std::wstring);
};

std::wstring OpenCalendar(const std::vector<std::wstring>&);

//---------------------------------------------------------------------------
extern PACKAGE TForm21 *Form21;
//---------------------------------------------------------------------------
#endif
