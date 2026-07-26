//---------------------------------------------------------------------------

#ifndef XFormFileAssociationsH
#define XFormFileAssociationsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>

#include <vector>

//---------------------------------------------------------------------------
class TFormFileAssociations : public TForm
{
__published:	// IDE-managed Components
	TLabel *lCategory;
	TBevel *Bevel7;
	TComboBox *cbFACategories;
	TGroupBox *GroupBox2;
	TShape *sCat1;
	TSpeedButton *sbRenameCategory;
	TLabel *lFAColour;
	TGroupBox *gbAFE;
	TSpeedButton *sbAdd;
	TSpeedButton *sbFADelete;
	TSpeedButton *sbSearchFileExt;
	TSpeedButton *miFECut;
	TSpeedButton *miFEPaste;
	TSpeedButton *sbRD;
	TListBox *lbExtList;
	TBitBtn *bImportLIst;
	TBitBtn *bExportList;
	TEdit *eAdd;
	TBitBtn *bSave;
	TBitBtn *bCancel;
	TBitBtn *bHelp;
	TColorDialog *cdMain;
	void __fastcall lbExtListClick(TObject *Sender);
	void __fastcall sCat1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbSearchFileExtClick(TObject *Sender);
	void __fastcall sbAddClick(TObject *Sender);
	void __fastcall cbFACategoriesChange(TObject *Sender);
	void __fastcall eAddChange(TObject *Sender);
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall bExportListClick(TObject *Sender);
	void __fastcall bImportLIstClick(TObject *Sender);
	void __fastcall eAddKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall sbRenameCategoryClick(TObject *Sender);
	void __fastcall miFECutClick(TObject *Sender);
	void __fastcall miFEPasteClick(TObject *Sender);
	void __fastcall sbRDClick(TObject *Sender);
	void __fastcall sbFADeleteClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:

    std::vector<std::wstring> SLClipboard;

    std::wstring OldCustomNames[10];

    int CurrentIndex = -1;

	void Init();

	void SetLanguage();
	void BuildList(int);

public:
	__fastcall TFormFileAssociations(TComponent* Owner);

	void SaveCustomNames();
};

bool OpenFileAssociations();

//---------------------------------------------------------------------------
extern PACKAGE TFormFileAssociations *FormFileAssociations;
//---------------------------------------------------------------------------
#endif
