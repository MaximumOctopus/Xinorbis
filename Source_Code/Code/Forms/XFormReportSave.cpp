//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormReportSave.h"

#include "ConstantsGui.h"
#include "FormDetails.h"
#include "SettingsHandler.h"
#include "WindowsUtility.h"

extern SettingsHandler *GSettingsHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
}


bool OpenReportSave(int data_source)//aDataIndex : integer;
					 // var TextOptions : TTextReportOptions; var CSVOptions  : TCSVReportOptions;
					 // var HTMLOptions : THTMLReportOptions; var XinOptions  : TXinorbisReportOptions;
					 // var XMLOptions  : TXMLReportOptions; var TreeOptions  : TTreeReportOptions): boolean;
{
	Form13 = new TForm13(Application);

	Form13->DataSource = data_source;

/* TO DO	  if XMLOptions.XMLData = CDataSummary then
		rbXMLMode1->Checked = True
	  else
		rbXMLMode2->Checked = True;

	  if CSVOptions.CSVData = CDataSummary then
		rbCSVMode1->Checked = True
	  else
		rbCSVMode2->Checked = True; */

	  // =======================================================================
	  // =======================================================================

	bool user_saves = false;

	if (Form13->ShowModal() == mrOk)
	{
		user_saves = true;

		Form13->SaveReports();
	}

	delete Form13;

	return user_saves;
}



void __fastcall TForm13::FormCreate(TObject *Sender)
{
   /*	FormDetails fd = GSettingsHandler->LoadFormDetails(_FormReport);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.H;
		Width  = fd.Width;
		Height = fd.Height;
	}

	Folder = L"";

	Edits[0] = eCSVOutput;
	Edits[1] = eHTMLReport;
	Edits[2] = eTextReport;
	Edits[3] = eTreeReport;
	Edits[4] = eZSReport;
	Edits[5] = eXMLOutput;

	Checks[0] = cbCSVReport;
	Checks[1] = cbHTMLReport;
	Checks[2] = cbTextReport;
	Checks[3] = cbTreeReport;
	Checks[4] = cbXinorbisReport;
	Checks[5] = cbXMLReport;

	SetLanguage(); */
}


void __fastcall TForm13::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormReport, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


void TForm13::SetLanguage()
{
/*	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kMostConvenient].c_str());
	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbHTMLUnits->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());
	cbHTMLUnits->ItemIndex = 0;

	// ===========================================================================

	bSelectAll->Caption         = GLanguageHandler->Text[kSelectAll].c_str();
	bSelectNone->Caption        = GLanguageHandler->Text[kSelectNone].c_str();

	Caption                     = GLanguageHandler->Text[kSaveReports].c_str();
	Label1->Caption             = GLanguageHandler->Text[kTreeFilename].c_str();
	Label2->Caption             = GLanguageHandler->Text[kTextReportFilename].c_str();
	Label3->Caption             = GLanguageHandler->Text[kXinorbisReportFilename].c_str();
	Label4->Caption             = GLanguageHandler->Text[kOutputAsHTML].c_str();
	Label5->Caption             = GLanguageHandler->Text[kOutputAsXML].c_str();
	rbXMLMode1->Caption         = GLanguageHandler->Text[kScanData].c_str();
	rbXMLMode2->Caption         = GLanguageHandler->Text[kFullFileList].c_str();
	Label6->Caption             = GLanguageHandler->Text[kOutputAsCSV].c_str();
	rbCSVMode1->Caption         = GLanguageHandler->Text[kCategories].c_str();
	rbCSVMode2->Caption         = GLanguageHandler->Text[kFullFileList].c_str();
	cbCSVTitles->Caption        = GLanguageHandler->Text[kIncludeColumnTitles].c_str();
	bGenerateFilenames->Caption = GLanguageHandler->Text[kGenerateFilenames].c_str();
	bSave->Caption              = GLanguageHandler->Text[kSave].c_str();
	bCancel->Caption            = GLanguageHandler->Text[kCancel].c_str();
	bHelp->Caption              = GLanguageHandler->Text[kHelp].c_str();

	lHTMLUnits->Caption         = GLanguageHandler->Text[kShowFileSizesAs].c_str();

	tabText->Caption            = GLanguageHandler->Text[kText].c_str();
	tabTree->Caption            = GLanguageHandler->Text[kTree].c_str();

	cbCSVReport->Caption        = (L"CSV "      + GLanguageHandler->Text[kReport]).c_str();
	cbHTMLReport->Caption       = (L"HTML "     + GLanguageHandler->Text[kReport]).c_str();
	cbTextReport->Caption       = GLanguageHandler->Text[kText] + L" " + GLanguageHandler->Text[kReport]).c_str();
	cbTreeReport->Caption       = GLanguageHandler->Text[kTree] + L" " + GLanguageHandler->Text[kReport]).c_str();
	cbXinorbisReport->Caption   = (L"Xinorbis " + GLanguageHandler->Text[kReport]).c_str();
	cbXMLReport->Caption        = (L"XML "      + GLanguageHandler->Text[kReport]).c_str();

	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbTextLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());

	cbHTMLLayouts->ItemIndex = 2;
	cbTextLayouts->ItemIndex = 2;
	cbTreeLayouts->ItemIndex = 2;
	cbXMLLayouts->ItemIndex  = 2;

	Label36->Caption = GLanguageHandler->Text[kReportLayout].c_str();
	Label35->Caption = GLanguageHandler->Text[kReportLayout].c_str();
	Label38->Caption = GLanguageHandler->Text[kReportLayout].c_str();
	Label7->Caption  = GLanguageHandler->Text[kReportLayout].c_str();

	lThisReport1->Caption = GLanguageHandler->Text[kThisReportCanBeImported].c_str();
	lThisReport2->Caption = GLanguageHandler->Text[kThisReportCanBeImported].c_str();   */
}


void TForm13::SaveReports()
{
/* TO DO 	if (cbCSVReport->Checked)
	{
		CSVOptions.Filename  = CheckFilename(eCSVOutput->Text, ".csv");
		CSVOptions.Category  = -1;
		CSVOptions.CSVUnits  = CSVUnitsMegabytes;
		CSVOptions.CSVTitles = cbCSVTitles->Checked;

		if rbCSVMode1->Checked)
		{
			CSVOptions.CSVData = CDataSummary
		}
		else
		{
			CSVOptions.CSVData = CDataFileList;
		}

		XSettings.Report.CSVOptions[LayoutAutoSave].CSVData = CSVOptions.CSVData;
	}

	// =====================================================================

	if cbHTMLReport->Checked then
	{
		HTMLOptions.HTMLColours  = XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].HTMLColours;

		HTMLOptions.Filename     = CheckFilename(eHTMLReport->Text, ".htm");
		HTMLOptions.HTMLUnits    = cbHTMLUnits.ItemIndex;
		HTMLOptions.Layout       = XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].Layout;
		HTMLOptions.LayoutSize   = XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].LayoutSize;
		HTMLOptions.CategoryList = XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].CategoryList;
	}

	// =====================================================================

	if cbTextReport->Checked then
	{
		TextOptions.Filename     = CheckFilename(eTextReport->Text, ".txt");

		TextOptions.Layout       = XSettings.Report->TextOptions[cbTextLayouts.ItemIndex + 1].Layout;
		TextOptions.CategoryList = XSettings.Report->TextOptions[cbTextLayouts.ItemIndex + 1].CategoryList;
	}

	// =====================================================================

	if cbTreeReport->Checked then
	{
		TreeOptions.Filename          = CheckFilename(eTreeReport->Text, ".txt");
		TreeOptions.Layout            = XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1].Layout;
		TreeOptions.IncludeSize       = XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1].IncludeSize;
		TreeOptions.IncludeAttributes = XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1].IncludeAttributes;
		TreeOptions.CategoryList      = XSettings.Report.TreeOptions[cbTreeLayouts.ItemIndex + 1].CategoryList;
	}

	// =====================================================================

	if cbXMLReport->Checked then
	{
		XMLOptions.Filename = CheckFilename(eXMLOutput->Text, ".xml");

		if rbXMLMode1->Checked)
		{
			XMLOptions.XMLData = CDataSummary
		}
		else
		{
			XMLOptions.XMLData = CDataFileList;
		}

		XMLOptions.Layout = XSettings.Report.XMLOptions[cbXMLLayouts.ItemIndex + 1].Layout;
	}

	// =====================================================================

	if cbXinorbisReport->Checked
	{
		XinOptions.Filename = CheckFilename(eZSReport->Text, ".zsr");

		XinOptions.Layout = 1;
	}        */
}


void TForm13::ChangeFolders(const std::wstring folder)
{
	for (int t = 0; t < 6; t++)
	{
		if (Edits[t]->Text != L"")
		{
			std::wstring file_name = ExtractFileName(Edits[t]->Text).c_str();

			Edits[t]->Text = (folder + file_name).c_str();
		}
	}
}

	/*
procedure TfrmReport.sbTextReportClick(Sender: TObject);
var
  lFileName : string;

{
  lFileName = TXSaveDialog.Execute(GLanguageHandler->Text[kTextFiles] + " (*.txt)|*.txt",
									".txt",
									TUtility.GetDefaultFileName(".txt", GLanguageHandler->Text[kReport] + "_" + GLanguageHandler->Text[kExport]),
									GSystemGlobal.AppDataPath);

  if lFileName != "" then {
	eTextReport->Text = lFileName;

	if not(cbTextReport->Checked) then {
	  cbTextReportClick(cbTextReport);
	}
  }
}


procedure TfrmReport.sbZSReportClick(Sender: TObject);
var
  lFileName : string;

{
  lFileName = TXSaveDialog.Execute("Xinorbis v2 (*.zsr2)|*.zsr2",
									".zsr2",
									TUtility.GetDefaultFileName(".zsr2", GLanguageHandler->Text[kReport] + "_" + GLanguageHandler->Text[kExport]),
									GSystemGlobal.AppDataPath);

  if lFileName != "" then {
    eZSReport->Text = lFileName;

    if not(cbXinorbisReport->Checked) then {
      cbTextReportClick(cbXinorbisReport);
    }
  }
}

procedure TfrmReport.sbHTMLReportClick(Sender: TObject);
var
  lFileName : string;

{
  lFileName = TXSaveDialog.Execute(GLanguageHandler->Text[kHTMLFiles] + " (*.html, *.htm)|*.html; *.htm",
                                    ".htm",
                                    TUtility.GetDefaultFileName(".htm", GLanguageHandler->Text[kReport] + "_" + GLanguageHandler->Text[kExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName != "" then {
    eHTMLReport->Text = lFileName;

    if not(cbHTMLReport->Checked) then {
      cbTextReportClick(cbHTMLReport);
    }
  }
}

procedure TfrmReport.SpeedButton1Click(Sender: TObject);
var
  lFileName : string;

{
  lFileName = TXSaveDialog.Execute(GLanguageHandler->Text[kXMLFiles] + " (*.xml)|*.xml",
                                    ".xml",
                                    TUtility.GetDefaultFileName(".xml", GLanguageHandler->Text[kReport] + "_" + GLanguageHandler->Text[kExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName != "" then {
    eXMLOutput->Text = lFileName;

	if not(cbXMLReport->Checked) then {
      cbTextReportClick(cbXMLReport);
    }
  }
}

procedure TfrmReport.SpeedButton2Click(Sender: TObject);
var
  lFileName : string;

{
  lFileName = TXSaveDialog.Execute(GLanguageHandler->Text[kCSVFiles] + " (*.csv)|*.csv",
                                    ".csv",
                                    TUtility.GetDefaultFileName(".csv", GLanguageHandler->Text[kReport] + "_" + GLanguageHandler->Text[kExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName != "" then {
    eCSVOutput->Text = lFileName;

    if not(cbCSVReport->Checked) then {
      cbTextReportClick(cbCSVReport);
    }
  }
}



procedure TfrmReport.cbHTMLLayoutsChange(Sender: TObject);
{
  cbHTMLUnits.ItemIndex    = XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1].HTMLUnits;

//  cbHTMLShowImages->Checked = TUtility.FindReportItem(XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1], 0);
}


procedure TfrmReport.cbTextReportClick(Sender: TObject);
 {
  if TAdvOfficeCheckBox(Sender)->Checked then {
    TAdvOfficeCheckBox(Sender).Font.Style = [];
    TAdvOfficeCheckBox(Sender)->Checked    = False;

    TAdvSmoothTabPage(TAdvOfficeCheckBox(Sender).Parent).TabAppearance.Status.Visible = False;
  end
  else {
    TAdvOfficeCheckBox(Sender).Font.Style = [fsBold];
    TAdvOfficeCheckBox(Sender)->Checked    = True;

    TAdvSmoothTabPage(TAdvOfficeCheckBox(Sender).Parent).TabAppearance.Status.Visible = True;
  }

  if (cbCSVReport.Enabled or cbHTMLReport.Enabled or cbTextReport.Enabled or cbTreeReport.Enabled or cbXinorbisReport.Enabled or cbXMLReport.Enabled) and
     (GScanEngine->Data[DataSource].Files.Count != 0) then
    bSave.Enabled = True
  else
    bSave.Enabled = False;

  SetSaveStatus;
}



procedure TfrmReport.sbTreeReportClick(Sender: TObject);
var
  lFileName : string;

{
  lFileName = TXSaveDialog.Execute(GLanguageHandler->Text[kTreeFiles] + " (*.xcrtree)|*.xcrtree",
                                    ".xcrtree",
                                    TUtility.GetDefaultFileName(".xcrtree", GLanguageHandler->Text[kReport] + "_" + GLanguageHandler->Text[kExport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName != "" then {
    eTreeReport->Text = lFileName;

    if not(cbTreeReport->Checked) then {
      cbTextReportClick(cbTreeReport);
    }
  }
}





function TfrmReport.GetFileName(aFolder, aFileName : string): string;
{
  if FFolder != "" then
    Result = FFolder + aFileName
  else
    Result = aFolder + aFileName
}


procedure TfrmReport.SetSaveStatus;
var
  t : integer;
  lStatus : boolean;

{
  if GScanEngine->Data[DataSource].Files.Count = 0 then {
    lStatus = False;
  end
  else {
    lStatus = False;

    for t = 1 to 6 do {
      if FChecks[t]->Checked then
        lStatus = True;
    }
  }

  bSave.Enabled              = lStatus;
  bGenerateFilenames.Enabled = lStatus;
}
*/


#pragma region Top_Toolbar
void __fastcall TForm13::bSelectAllClick(TObject *Sender)
{
	SetAll(true);
}


void __fastcall TForm13::bSelectNoneClick(TObject *Sender)
{
	SetAll(false);
}


void TForm13::SetAll(bool status)
{
	/*aStatus = not(aStatus);

	cbCSVReport->Checked      = aStatus;
	cbHTMLReport->Checked     = aStatus;
	cbTextReport->Checked     = aStatus;
	cbTreeReport->Checked     = aStatus;
	cbXinorbisReport->Checked = aStatus;
	cbXMLReport->Checked      = aStatus;

	cbTextReportClick(cbCSVReport);
	cbTextReportClick(cbHTMLReport);
	cbTextReportClick(cbTextReport);
	cbTextReportClick(cbTreeReport);
	cbTextReportClick(cbXinorbisReport);
	cbTextReportClick(cbXMLReport);

	SetSaveStatus;*/
}
#pragma end_region


#pragma region Bottom_Toolbar
void __fastcall TForm13::bGenerateFilenamesClick(TObject *Sender)
{
	std::wstring cname = WindowsUtility::GetComputerNetName();
									   /* to do
  eCSVOutput->Text  = GetFileName(GSystemGlobal.AppDataPath + "reports\" + cname + "\csv\",
								  TXFormatting.MakeFilenameCompatible(GScanEngine->Data[DataSource].ScanPath) + "_" + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + "_" + TUtility.GetTime(GETTIMEFORMAT_FILE) + ".csv");

  eHTMLReport->Text = GetFileName(GSystemGlobal.AppDataPath + "reports\" + cname + "\html\",
								  TXFormatting.MakeFilenameCompatible(GScanEngine->Data[DataSource].ScanPath) + "_" + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + "_" + TUtility.GetTime(GETTIMEFORMAT_FILE) + ".html");

  eTextReport->Text = GetFileName(GSystemGlobal.AppDataPath + "reports\" + cname + "\Text\",
								  TXFormatting.MakeFilenameCompatible(GScanEngine->Data[DataSource].ScanPath) + "_" + GLanguageHandler->Text[kText] + "_" + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + "_" + TUtility.GetTime(GETTIMEFORMAT_FILE) + ".txt");

  eTreeReport->Text = GetFileName(GSystemGlobal.AppDataPath + "reports\" + cname + "\Tree\",
								  TXFormatting.MakeFilenameCompatible(GScanEngine->Data[DataSource].ScanPath) + "_" + GLanguageHandler->Text[kTree] + "_" + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + "_" + TUtility.GetTime(GETTIMEFORMAT_FILE) + ".txt");

  eZSReport->Text   = GetFileName(GSystemGlobal.AppDataPath + "reports\" + cname + "\Xinorbis\",
								  TXFormatting.MakeFilenameCompatible(GScanEngine->Data[DataSource].ScanPath) + "_" + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + "_" + TUtility.GetTime(GETTIMEFORMAT_FILE) + ".zsr2");

  eXMLOutput->Text  = GetFileName(GSystemGlobal.AppDataPath + "reports\" + cname + "\xml\",
								  TXFormatting.MakeFilenameCompatible(GScanEngine->Data[DataSource].ScanPath) + "_" + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + "_" + TUtility.GetTime(GETTIMEFORMAT_FILE) + ".xml");
*/
}


void __fastcall TForm13::SpeedButton3Click(TObject *Sender)
{
	std::wstring folder = L""; // to do WindowsUtility::BrowseForFolder(Handle);

	if (!folder.empty())
	{
		Folder = folder;

		ChangeFolders(Folder);
	}
}


void __fastcall TForm13::bHelpClick(TObject *Sender)
{
	// to do THelp.OpenHelpPage("savereporst.htm");
}


void __fastcall TForm13::bSaveClick(TObject *Sender)
{
	std::wstring s = L"";
																			  /*
  if (cbTextReport->Checked) and (eTextReport->Text = "") then {
	s = """ + GLanguageHandler->Text[kText] + " " + GLanguageHandler->Text[kReport] + "" " + GLanguageHandler->Text[kHasBeenSelected];
  }

  if (cbXinorbisReport->Checked) and (eZSReport->Text = "") then {
	if s != "" then
	  s = s + #13 + #13;

	s = s + """ + "Xinorbis " + GLanguageHandler->Text[kReport] + "" " + GLanguageHandler->Text[kHasBeenSelected];
  }

  if (cbHTMLReport->Checked) and (eHTMLReport->Text = "") then {
	if s != "" then
	  s = s + #13 + #13;

	s = s + ""HTML " + GLanguageHandler->Text[kReport] + "" " + GLanguageHandler->Text[kHasBeenSelected];
  }

  if (cbCSVReport->Checked) and (eCSVOutput->Text = "") then {
	if s != "" then
	  s = s + #13 + #13;

	s = s + ""CSV " + GLanguageHandler->Text[kReport] + "" " + GLanguageHandler->Text[kHasBeenSelected];
  }

  if (cbXMLReport->Checked) and (eXMLOutput->Text = "") then {
	if s != "" then
	  s = s + #13 + #13;

	s = s + ""XML " + GLanguageHandler->Text[kReport] + "" " + GLanguageHandler->Text[kHasBeenSelected];
  }

  if s = "" then
	ModalResult = mrOK // surely no mrOK
  else {
	if MessageDlg(s + #13 + #13 + GLanguageHandler->Text[kAreYouSureContinue], mtWarning, [mbYes, mbCancel], 0) = mrYes then
	  ModalResult = mrOK;
  }                       */
}
#pragma end_region

