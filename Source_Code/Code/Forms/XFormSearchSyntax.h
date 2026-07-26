//---------------------------------------------------------------------------

#ifndef XFormSearchSyntaxH
#define XFormSearchSyntaxH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <SHDocVw.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.OleCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSearchSyntax : public TForm
{
__published:	// IDE-managed Components
	TWebBrowser *wbSearch;
	TPanel *Panel1;
	TWebBrowser *wbIndex;
	TCheckBox *cbStayOnTop;
	TBitBtn *bClose;
	void __fastcall cbStayOnTopClick(TObject *Sender);
	void __fastcall wbIndexBeforeNavigate2(TObject *ASender, IDispatch * const pDisp,
          const OleVariant &URL, const OleVariant &Flags, const OleVariant &TargetFrameName,
          const OleVariant &PostData, const OleVariant &Headers,
          WordBool &Cancel);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:

	std::wstring LanguageSymbol = L"uk";

public:
	__fastcall TFormSearchSyntax(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSearchSyntax *FormSearchSyntax;
//---------------------------------------------------------------------------
#endif
