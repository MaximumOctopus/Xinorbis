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
private:	// User declarations
public:		// User declarations
	__fastcall TForm20(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm20 *Form20;
//---------------------------------------------------------------------------
#endif
