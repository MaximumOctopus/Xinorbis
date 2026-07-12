//---------------------------------------------------------------------------

#ifndef XFormFileAgesH
#define XFormFileAgesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFormFileAges : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TPanel *pStatus;
	TStringGrid *sgResults;
	TPanel *Panel1;
	TComboBox *cbAttribute;
	TComboBox *cbFileAgeType;
	TEdit *eCount;
	TComboBox *cbInterval;
	TBitBtn *bGo;
	TBitBtn *bReportCSV;
	TBitBtn *bHelp;
	TBitBtn *bReportXML;
	TCheckBox *cbFiles;
	TCheckBox *cbFolders;
	TCheckBox *cbAutoRefresh;
	TGroupBox *gbUsers;
	TComboBox *cbUsers;
	void __fastcall bGoClick(TObject *Sender);
	void __fastcall bReportCSVClick(TObject *Sender);
	void __fastcall bReportXMLClick(TObject *Sender);
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall cbAttributeChange(TObject *Sender);
	void __fastcall eCountEnter(TObject *Sender);
	void __fastcall eCountExit(TObject *Sender);
	void __fastcall eCountKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:

	static const int kAttributeCreated  = 0;
	static const int kAttributeAccessed = 1;
	static const int kAttributeModified = 2;

	static const int kIntervalDay       = 0;
	static const int kIntervalWeek      = 1;
	static const int kIntervalMonth     = 2;
	static const int kIntervalYear      = 3;

	static const int kTypeOlderThan     = 0;
	static const int kTypeWithinTheLast = 1;

	std::wstring OldText = L"";

    void Init();

	void ExportDataCSV(const std::wstring);
	void ExportDataXML(const std::wstring);

public:
	__fastcall TFormFileAges(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFileAges *FormFileAges;
//---------------------------------------------------------------------------
#endif
