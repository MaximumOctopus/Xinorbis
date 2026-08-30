//---------------------------------------------------------------------------

#ifndef XFormDBSelectedFolderH
#define XFormDBSelectedFolderH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm20 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TLabel *lFolder;
	TLabel *lCount;
	TLabel *lComputerName;
	TPanel *Panel2;
	TBitBtn *bHelp;
	TBitBtn *bCopy;
	TBitBtn *bClose;
	TBitBtn *bFiles;
	TBitBtn *bSize;
	TChart *vtcSelected;
	TBarSeries *Series1;
	TSplitter *Splitter1;
	TStringGrid *sgDatabase;
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall bFilesClick(TObject *Sender);
	void __fastcall bCopyClick(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall vtcSelectedMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sgDatabaseDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall Splitter1Moved(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm20(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm20 *Form20;
//---------------------------------------------------------------------------
#endif
