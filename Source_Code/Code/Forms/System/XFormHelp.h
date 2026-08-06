//---------------------------------------------------------------------------

#ifndef XFormHelpH
#define XFormHelpH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <SHDocVw.hpp>
#include <System.ImageList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.OleCtrls.hpp>
#include <Vcl.ToolWin.hpp>

#include <vector>

#include "HelpIndexItem.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TSplitter *Splitter1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TWebBrowser *wbContents;
	TTabSheet *TabSheet2;
	TTreeView *tvSearch;
	TPanel *Panel1;
	TSpeedButton *sbSearch;
	TLabel *lSearchResults;
	TEdit *eSearchQuery;
	TCoolBar *CoolBar1;
	TToolBar *ToolBar1;
	TToolButton *tbPrevious;
	TToolButton *tbNext;
	TToolButton *ToolButton4;
	TToolButton *tbHelp;
	TWebBrowser *wbHelp;
	TImageList *ilNavToolbar_On;
	TImageList *ilNavToolbar_Off;
	void __fastcall tbPreviousClick(TObject *Sender);
	void __fastcall tbNextClick(TObject *Sender);
	void __fastcall tbHelpClick(TObject *Sender);
	void __fastcall wbHelpBeforeNavigate2(TObject *ASender, IDispatch * const pDisp,
          const OleVariant &URL, const OleVariant &Flags, const OleVariant &TargetFrameName,
          const OleVariant &PostData, const OleVariant &Headers,
          WordBool &Cancel);
	void __fastcall wbHelpCommandStateChange(TObject *ASender, int Command, WordBool Enable);
	void __fastcall tvSearchDblClick(TObject *Sender);
	void __fastcall eSearchQueryKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall sbSearchClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:

	std::vector<HelpIndexItem*> IndexCache;

    bool LoadCache(const std::wstring);

public:
	__fastcall TForm1(TComponent* Owner);
};

void OpenHelpPage(const std::wstring);

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
