//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Graphics.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *pViews;
	TImage *Image15;
	TImage *Image16;
	TImage *Image17;
	TImage *Image25;
	TImage *Image8;
	TLabel *lAdvID3;
	TLabel *lAdvID2;
	TLabel *lTaskID7;
	TLabel *lTaskID6;
	TLabel *lAdvID1;
	TImage *Image12;
	TLabel *lTaskID1;
	TLabel *lTaskID2;
	TImage *Image13;
	TImage *Image14;
	TLabel *lTaskID3;
	TImage *Image2;
	TImage *Image24;
	TLabel *lTaskID4;
	TLabel *lTaskID5;
	TImage *Image1;
	TLabel *lTaskID8;
	TPanel *pNavigation;
	TImage *Image9;
	TImage *Image11;
	TLabel *lWelcomeScan;
	TLabel *lWelcomeFolderHistory;
	TLabel *lDataSource;
	TToolBar *tbMain;
	TPanel *pReports;
	TPanel *pMainCanvas;
	TToolButton *tbSaveReports;
	TToolButton *tbOpen;
	TToolButton *tbSettings;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *tbWizard;
	TToolButton *tbRefresh;
	TToolButton *ToolButton11;
	TToolButton *tbAbout;
	TImageList *ImageList1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *File2;
	TMenuItem *About1;
	TMenuItem *Exit1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall lTaskID1Click(TObject *Sender);
	void __fastcall tbSaveReportsClick(TObject *Sender);
	void __fastcall tbOpenClick(TObject *Sender);
	void __fastcall tbSettingsClick(TObject *Sender);
	void __fastcall tbWizardClick(TObject *Sender);
	void __fastcall tbRefreshClick(TObject *Sender);
	void __fastcall tbAboutClick(TObject *Sender);
private:

	int PanelInFront = -1;
	int PanelSource = -1;

	// Application init
	void CreateFrames();
    void SetLanguageText();

	// post scan
    void PostScan();

	// Frame_Events
	void __fastcall OnNewScan(const std::wstring);

	// GUI control
    void ToggleSoftwareStatus(bool);
	void SetSidePanelDisplay(int, int, int, bool);
	void SetWelcomeDisplay(int);
    void HandleResizing(int);
	void DoWelcome(int);
	void DoTask(int, int);

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
