//---------------------------------------------------------------------------

#ifndef XFormImportFromCSVH
#define XFormImportFromCSVH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>

#include "CSVDataFormat.h"

//---------------------------------------------------------------------------
class TFormImportCSV : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *lFileName;
	TLabel *lSelectedFileName;
	TGroupBox *GroupBox2;
	TComboBox *cbType1;
	TComboBox *cbType2;
	TComboBox *cbType3;
	TComboBox *cbType4;
	TComboBox *cbType5;
	TComboBox *cbType6;
	TComboBox *cbType7;
	TComboBox *cbType8;
	TComboBox *cbType9;
	TComboBox *cbType10;
	TComboBox *cbType11;
	TComboBox *cbType12;
	TComboBox *cbType13;
	TComboBox *cbType14;
	TComboBox *cbType15;
	TComboBox *cbType16;
	TComboBox *cbType17;
	TComboBox *cbType18;
	TComboBox *cbType19;
	TComboBox *cbType20;
	TCheckBox *cbIFR;
	TBitBtn *bImport;
	TLabel *lFieldDataType;
	TLabel *lContentsFirstRecord;
	TBitBtn *bCancel;
	TBitBtn *bHelp;
	TBitBtn *bAuto;
	TLabel *lContents1;
	TLabel *lContents2;
	TLabel *lContents3;
	TLabel *lContents4;
	TLabel *lContents5;
	TLabel *lContents6;
	TLabel *lContents7;
	TLabel *lContents8;
	TLabel *lContents9;
	TLabel *lContents10;
	TLabel *lContents11;
	TLabel *lContents12;
	TLabel *lContents13;
	TLabel *lContents14;
	TLabel *lContents15;
	TLabel *lContents16;
	TLabel *lContents17;
	TLabel *lContents18;
	TLabel *lContents19;
	TLabel *lContents20;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bAutoClick(TObject *Sender);
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall cbType1Change(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:

    std::wstring CSVRow[2] = { L"", L"" };

	TLabel* LabelList[20];
	TComboBox* ComboList[20];

    bool ProcessSuccessful = false;

	int FieldCount = 0;

	void Init();

	bool ProcessFile();

	bool ReadTopTwoLines();

    int GetFieldCount(const std::wstring);

public:
	__fastcall TFormImportCSV(TComponent* Owner);

	std::wstring FileName = L"";

    CSVDataFormat GetImportInstructions();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormImportCSV *FormImportCSV;
//---------------------------------------------------------------------------
#endif
