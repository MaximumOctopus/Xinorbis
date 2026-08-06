//---------------------------------------------------------------------------

#ifndef XFormReferenceH
#define XFormReferenceH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMemo *mResults;
	TPageControl *pcReference;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TSpeedButton *sbFileExtensions;
	TEdit *eFileExtension;
	TBitBtn *bHelp;
	TSpeedButton *sbWindowsFile;
	TEdit *eWindowsFile;
	TRadioButton *rbXP;
	TRadioButton *rbW7;
	void __fastcall sbFileExtensionsClick(TObject *Sender);
	void __fastcall eFileExtensionKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall eFileExtensionChange(TObject *Sender);
	void __fastcall eWindowsFileKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall eWindowsFileChange(TObject *Sender);
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall sbWindowsFileClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};

void ShowReference();

//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
