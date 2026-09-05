//---------------------------------------------------------------------------

#ifndef XFormCombineH
#define XFormCombineH
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
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TBevel *Bevel4;
	TBevel *Bevel5;
	TLabel *lChoose;
	TSpeedButton *sbDrive2Add;
	TSpeedButton *sbDelete;
	TSpeedButton *SpeedButton4;
	TLabel *lFolderList;
	TBevel *Bevel6;
	TSpeedButton *sbExplore;
	TListBox *lbCombine;
	TBitBtn *bCancel;
	TBitBtn *bScan;
	TBitBtn *bLoadList;
	TBitBtn *bSaveList;
	TEdit *eDirectory;
	TOpenDialog *odCombine;
	TSaveDialog *sdCombine;
	void __fastcall sbDrive2AddClick(TObject *Sender);
	void __fastcall bSaveListClick(TObject *Sender);
	void __fastcall bLoadListClick(TObject *Sender);
	void __fastcall eDirectoryKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall sbExploreClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall lbCombineClick(TObject *Sender);
	void __fastcall sbDeleteClick(TObject *Sender);
private:

	void Init();

public:
	__fastcall TForm13(TComponent* Owner);
};

void OpenCombine(std::vector<std::wstring> &);

//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
//---------------------------------------------------------------------------
#endif
