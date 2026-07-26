//---------------------------------------------------------------------------

#ifndef XFormSearchWizardH
#define XFormSearchWizardH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TBitBtn *bCancel;
	TBitBtn *bOK;
	TScrollBox *ScrollBox1;
	TPanel *pContaining;
	TLabel *lContaining;
	TEdit *eContaining;
	TPanel *pSize;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *eSLT;
	TComboBox *cbSLTUnit;
	TEdit *eSGT;
	TComboBox *cbSGTUnit;
	TPanel *pCategory;
	TCheckBox *sbProg;
	TCheckBox *sbSys;
	TCheckBox *sbGfx;
	TCheckBox *sbMovie;
	TCheckBox *sbSnd;
	TCheckBox *sbOffice;
	TCheckBox *sbCode;
	TCheckBox *sbCompressed;
	TCheckBox *sbOther;
	TCheckBox *sbCustom1;
	TCheckBox *sbCustom2;
	TCheckBox *sbCustom3;
	TCheckBox *sbCustom4;
	TCheckBox *sbCustom7;
	TCheckBox *sbCustom5;
	TCheckBox *sbCustom8;
	TCheckBox *sbCustom6;
	TCheckBox *sbCustom9;
	TCheckBox *sbCustom10;
	TPanel *pAttributes;
	TCheckBox *cbAHidden;
	TCheckBox *cbASystem;
	TCheckBox *cbAArchive;
	TCheckBox *cbAReadOnly;
	TCheckBox *cbATemp;
	TCheckBox *cbAFolder;
	TCheckBox *cbAFile;
	TCheckBox *cbAVirtual;
	TCheckBox *cbAEncrypted;
	TCheckBox *cbACompressed;
	TPanel *pCreated;
	TComboBox *cbCreated1;
	TComboBox *cbCreated2;
	TDateTimePicker *dtpCreated2;
	TDateTimePicker *dtpCreated1;
	TPanel *pAccessed;
	TComboBox *cbAccessed1;
	TDateTimePicker *dtpAccessed1;
	TComboBox *cbAccessed2;
	TDateTimePicker *dtpAccessed2;
	TPanel *pModified;
	TComboBox *cbModified1;
	TDateTimePicker *dtpModified1;
	TComboBox *cbModified2;
	TDateTimePicker *dtpModified2;
	TPanel *pOwner;
	TComboBox *cbUSelect;
	TEdit *eUContent;
	TBitBtn *bShowSQL;
	TPanel *pSQL;
	TEdit *eSQL;
	TImageList *ImageList1;
	TCheckBox *cbContaining;
	TCheckBox *cbSize;
	TCheckBox *cbCategory;
	TCheckBox *cbCreated;
	TCheckBox *cbAccessed;
	TCheckBox *cbModified;
	TCheckBox *cbOwner;
	TCheckBox *cbAttributes;
	void __fastcall cbContainingClick(TObject *Sender);
	void __fastcall bShowSQLClick(TObject *Sender);
	void __fastcall eSLTChange(TObject *Sender);
	void __fastcall cbUSelectChange(TObject *Sender);
	void __fastcall cbCreated1Change(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:

	int Heights[7] = { 64, 112, 64, 64, 64, 97, 64 };
	TDateTimePicker *DateControls[6];
	TCheckBox *CategoryControls[19];
	TCheckBox *AttributeControls[10];

	void Init();

	void CheckForValidSearch();
	void BuildSQLDisplay();

public:
	__fastcall TForm11(TComponent* Owner);

    std::wstring SearchString = L"";

	void BuildSearchString();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
//---------------------------------------------------------------------------
#endif
