//---------------------------------------------------------------------------

#ifndef XFormReportSaveH
#define XFormReportSaveH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>

#include "ReportCSVOptions.h"
#include "ReportHTMLOptions.h"
#include "ReportTextOptions.h"
#include "ReportTreeOptions.h"
#include "ReportXinorbisOptions.h"
#include "ReportXMLOptions.h"
//---------------------------------------------------------------------------
class TFormReportSaves : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TSpeedButton *SpeedButton3;
	TBitBtn *bGenerateFilenames;
	TBitBtn *bSave;
	TBitBtn *bCancel;
	TBitBtn *bHelp;
	TPanel *Panel1;
	TBitBtn *bSelectAll;
	TBitBtn *bSelectNone;
	TPageControl *pcReports;
	TTabSheet *tsCSV;
	TTabSheet *tsText;
	TTabSheet *tsTree;
	TTabSheet *tsXinorbis;
	TTabSheet *tsXML;
	TCheckBox *cbToggleCSV;
	TCheckBox *cbToggleText;
	TCheckBox *cbToggleTree;
	TCheckBox *cbToggleXinorbis;
	TCheckBox *cbToggleXML;
	TLabel *lCSVFileName;
	TEdit *eCSVFileName;
	TRadioButton *rbCSVCategories;
	TRadioButton *rbCSVFullFileList;
	TLabel *lCSVFFLHelpText;
	TCheckBox *cbCSVIncludeColumnTitles;
	TSpeedButton *sbCSVFolder;
	TTabSheet *tsHTML;
	TLabel *lHTMLFileName;
	TSpeedButton *sbHTMLFolder;
	TLabel *lHTMLLayout;
	TCheckBox *cbToggleHTML;
	TEdit *eHTMLFileName;
	TComboBox *cbHTMLLayouts;
	TLabel *lHTMLFileSize;
	TComboBox *cbHTMLFileSize;
	TLabel *lTextFileName;
	TEdit *eTextFileName;
	TLabel *Label7;
	TComboBox *cbTextLayouts;
	TSpeedButton *sbTextFolder;
	TLabel *lTreeFileName;
	TEdit *eTreeFileName;
	TLabel *Label9;
	TComboBox *cbTreeLayouts;
	TSpeedButton *sbTreeFolder;
	TLabel *lXinorbisFileName;
	TEdit *eXinorbisFileName;
	TSpeedButton *sbXinorbisFolder;
	TLabel *lXinorbisHelpText;
	TLabel *lXMLFileName;
	TEdit *eXMLFileName;
	TRadioButton *rbXMLScanData;
	TRadioButton *rbXMLFullFileList;
	TSpeedButton *sbXMLFolder;
	TLabel *lXMLLayouts;
	TComboBox *cbXMLLayouts;
	void __fastcall bSelectAllClick(TObject *Sender);
	void __fastcall bSelectNoneClick(TObject *Sender);
	void __fastcall bGenerateFilenamesClick(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall bSaveClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cbToggleCSVClick(TObject *Sender);
	void __fastcall sbCSVFolderClick(TObject *Sender);
	void __fastcall cbToggleHTMLClickClick(TObject *Sender);
	void __fastcall cbToggleTextClickClick(TObject *Sender);
	void __fastcall sbTextFolderClick(TObject *Sender);
	void __fastcall cbToggleTreeClickClick(TObject *Sender);
	void __fastcall sbTreeFolderClick(TObject *Sender);
	void __fastcall sbXinorbisFolderClick(TObject *Sender);
	void __fastcall cbToggleXinorbisClick(TObject *Sender);
	void __fastcall sbXMLFolderClick(TObject *Sender);
	void __fastcall cbToggleXMLClick(TObject *Sender);
	void __fastcall cbHTMLLayoutsChange(TObject *Sender);
	void __fastcall sbHTMLFolderClick(TObject *Sender);
private:

	std::wstring Folder = L"";

	TCheckBox *Checks[6];
	TEdit *Edits[6];

    void SetLanguage();

    void ChangeFolders(const std::wstring);

    void SetSaveStatus();

	void SetAll(bool);

public:
	__fastcall TFormReportSaves(TComponent* Owner);

	int DataSource = 0;

    void SaveReports();
};

bool OpenReportSave(int,
					TextReportOptions&, CSVReportOptions&,
					HTMLReportOptions&, XinorbisReportOptions&,
					XMLReportOptions&, TreeReportOptions&);

//---------------------------------------------------------------------------
extern PACKAGE TFormReportSaves *FormReportSaves;
//---------------------------------------------------------------------------
#endif
