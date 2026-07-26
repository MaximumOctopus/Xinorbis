//---------------------------------------------------------------------------

#ifndef XFormExcludeFilesH
#define XFormExcludeFilesH
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
class TForm14 : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *sbAdd;
	TBevel *Bevel1;
	TSpeedButton *sbRemove;
	TSpeedButton *sbEdit;
	TLabel *lPatternToExclude;
	TLabel *Label1;
	TListBox *lbExcluded;
	TBitBtn *bOK;
	TBitBtn *bCancel;
	TEdit *ePattern;
	TBitBtn *bSave;
	TBitBtn *bOpen;
	TOpenDialog *odExclude;
	TSaveDialog *sdExclude;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall sbAddClick(TObject *Sender);
	void __fastcall ePatternKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall bSaveClick(TObject *Sender);
	void __fastcall bOpenClick(TObject *Sender);
	void __fastcall sbRemoveClick(TObject *Sender);
	void __fastcall sbEditClick(TObject *Sender);
	void __fastcall lbExcludedClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm14(TComponent* Owner);

	void ToggleSave();
};

void OpenExcludedFiles(std::vector<std::wstring> &);

//---------------------------------------------------------------------------
extern PACKAGE TForm14 *Form14;
//---------------------------------------------------------------------------
#endif
