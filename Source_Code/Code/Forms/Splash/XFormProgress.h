//---------------------------------------------------------------------------

#ifndef XFormProgressH
#define XFormProgressH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormProgress : public TForm
{
__published:	// IDE-managed Components
	TImage *iBackground;
	TImage *iProgress1;
	TImage *iProgress2;
	TImage *iProgress3;
	TImage *iProgress4;
	TImage *iProgress5;
	TLabel *lStatus;
	TLabel *lStatus2;
	TLabel *lStatus3;
	TLabel *lAbortStatus;
	TSpeedButton *sbStop;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall sbStopClick(TObject *Sender);
private:
public:
	__fastcall TFormProgress(TComponent* Owner);

	void SetProcessBar(int);

    void SetAbort();
	void SetProcessText(const std::wstring);
	void SetPercentage(const std::wstring);
	void SetStatus3(const std::wstring);
	void SetProcessIcon(int);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProgress *FormProgress;
//---------------------------------------------------------------------------
#endif
