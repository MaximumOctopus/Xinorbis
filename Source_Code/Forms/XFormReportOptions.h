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
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
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
	TSpeedButton *SpeedButton12;
	TBitBtn *bSave;
	TBitBtn *bCancel;
	TIdFTP *ftpMain;
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
