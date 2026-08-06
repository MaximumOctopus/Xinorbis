//---------------------------------------------------------------------------

#ifndef XFormReportOptionsH
#define XFormReportOptionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdFTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.WinXCtrls.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel10;
	TPanel *pReportsAutosave;
	TLabel *lReportsAutosave;
	TLabel *lASDrive;
	TLabel *lASOrganise;
	TLabel *lADR_1;
	TLabel *lADR_9;
	TLabel *lADR_4;
	TLabel *lADR_3;
	TLabel *lADR_2;
	TLabel *lADR_5;
	TPanel *pWebReports;
	TLabel *Label47;
	TLabel *Label48;
	TLabel *Label49;
	TLabel *Label50;
	TLabel *Label51;
	TLabel *Label52;
	TLabel *Label53;
	TLabel *Label54;
	TLabel *Label55;
	TLabel *lWebReportTest;
	TBitBtn *bTestFTP;
	TBitBtn *bOpenLink;
	TEdit *eFTPHost;
	TEdit *eFTPUsername;
	TEdit *eFTPPassword;
	TEdit *eFTPInitialFolder;
	TEdit *eFTPRemoteFolder;
	TEdit *eFTPLink;
	TPanel *pReportsTree;
	TLabel *lReportsTree;
	TPanel *pReportsText;
	TLabel *lReportsText;
	TLabel *lTextDefaultOutput;
	TSpeedButton *SpeedButton10;
	TEdit *eOOTextOutput;
	TPanel *pReportsXML;
	TLabel *lReportsXML;
	TLabel *Label8;
	TSpeedButton *SpeedButton3;
	TEdit *eOOXMLOutput;
	TPanel *pReportsXinorbis;
	TLabel *lReportsXinorbis;
	TGroupBox *gbXReportType;
	TComboBox *cbXinorbisLayouts;
	TPanel *pReportsHTML;
	TLabel *lReportsHTML;
	TLabel *Label6;
	TSpeedButton *SpeedButton1;
	TEdit *eOOHTMLOutput;
	TPanel *pReportsCSV;
	TLabel *lReportsCSV;
	TLabel *Label29;
	TSpeedButton *SpeedButton9;
	TEdit *eOOCSVOutput;
	TPanel *pOutputOptions;
	TLabel *lOutputOptions;
	TLabel *lDocOptions;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TLabel *Label31;
	TLabel *lReportMenuTree;
	TLabel *Label42;
	TLabel *Label44;
	TLabel *Label45;
	TLabel *Label46;
	TPanel *Panel1;
	TSpeedButton *sbGeneral;
	TSpeedButton *SpeedButton2;
	TSpeedButton *sbReportTree;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *sbAutoSave;
	TSpeedButton *sbWebReports;
	TSpeedButton *sbASCII;
	TBitBtn *bSave;
	TBitBtn *bCancel;
	TIdFTP *ftpMain;
	TToggleSwitch *cbASDrive;
	TToggleSwitch *cbASOrganise;
	TToggleSwitch *cbADR_1;
	TToggleSwitch *cbADR_9;
	TToggleSwitch *cbADR_4;
	TToggleSwitch *cbADR_3;
	TToggleSwitch *cbADR_2;
	TToggleSwitch *cbADR_5;
	TRadioButton *rbXReportNormal;
	TRadioButton *rbXReportDetailed;
	void __fastcall sbASCIIClick(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall cbXinorbisLayoutsChange(TObject *Sender);
	void __fastcall bTestFTPClick(TObject *Sender);
	void __fastcall bOpenLinkClick(TObject *Sender);
	void __fastcall ftpMainStatus(TObject *ASender, const TIdStatus AStatus, const UnicodeString AStatusText);
	void __fastcall ftpMainWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall ftpMainWorkEnd(TObject *ASender, TWorkMode AWorkMode);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cbASDriveClick(TObject *Sender);
	void __fastcall rbXReportNormalClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:

	constexpr static int kPageAutosave = 0;
	constexpr static int kPageCSV = 1;
	constexpr static int kPageHTML = 2;
	constexpr static int kPageXML = 3;
	constexpr static int kPageText = 4;
	constexpr static int kPageTree = 5;
	constexpr static int kPageXinorbis  = 6;
	constexpr static int kPageWebReports = 7;

	void Init();

	bool SliderStateToBoolean(TToggleSwitchState);
	TToggleSwitchState BooleanToSliderState(bool);

	void BuildXinorbisLayoutList(int);

public:
	__fastcall TForm8(TComponent* Owner);

    int OpenTab = 0;

	int OpenReportSettings(int);

    void UpdateSettings();
};

void OpenReportSettings(int);

//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
