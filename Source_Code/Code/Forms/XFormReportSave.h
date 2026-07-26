//---------------------------------------------------------------------------

#ifndef XFormReportSaveH
#define XFormReportSaveH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TSpeedButton *SpeedButton3;
	TBitBtn *bGenerateFilenames;
	TBitBtn *bSave;
	TBitBtn *bCancel;
	TBitBtn *bHelp;
	TPanel *Panel1;
	TBitBtn *bSelectAll;
	TBitBtn *bSelectNone;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TTabSheet *TabSheet6;
	void __fastcall bSelectAllClick(TObject *Sender);
	void __fastcall bSelectNoneClick(TObject *Sender);
	void __fastcall bGenerateFilenamesClick(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall bSaveClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
private:

	std::wstring Folder = L"";

	TCheckBox *Checks[6];
	TEdit *Edits[6];

    void SetLanguage();

    void ChangeFolders(const std::wstring);

	void SetAll(bool);

public:
	__fastcall TForm13(TComponent* Owner);

	int DataSource = 0;

    void SaveReports();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
//---------------------------------------------------------------------------
#endif
