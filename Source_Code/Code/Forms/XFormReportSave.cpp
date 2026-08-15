//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormReportSave.h"

#include "ConstantsGui.h"
#include "Formatting.h"
#include "FormDetails.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "ReportHandler.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;
extern ReportHandler *GReportHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormReportSaves *FormReportSaves;
//---------------------------------------------------------------------------
__fastcall TFormReportSaves::TFormReportSaves(TComponent* Owner)
	: TForm(Owner)
{
}


bool OpenReportSave(int data_source)
{
	FormReportSaves = new TFormReportSaves(Application);

	FormReportSaves->DataSource = data_source;

	// =======================================================================
	// =======================================================================

	bool user_saves = false;

	if (FormReportSaves->ShowModal() == mrOk)
	{
		user_saves = true;

		if (FormReportSaves->UpdateReports() != 0)
		{
            FormReportSaves->SaveReports();
		}
	}

	delete FormReportSaves;

	return user_saves;
}



void __fastcall TFormReportSaves::FormCreate(TObject *Sender)
{
   /*	FormDetails fd = GSettingsHandler->LoadFormDetails(_FormReport);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.H;
		Width  = fd.Width;
		Height = fd.Height;
	}*/

	Folder = L"";

	Edits[0] = eCSVFileName;
	Edits[1] = eHTMLFileName;
	Edits[2] = eTextFileName;
	Edits[3] = eTreeFileName;
	Edits[4] = eXinorbisFileName;
	Edits[5] = eXMLFileName;

	Checks[0] = cbToggleCSV;
	Checks[1] = cbToggleHTML;
	Checks[2] = cbToggleText;
	Checks[3] = cbToggleTree;
	Checks[4] = cbToggleXinorbis;
	Checks[5] = cbToggleXML;

	SetLanguage();
}


void __fastcall TFormReportSaves::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormReport, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


void TFormReportSaves::SetLanguage()
{
	// csv tab
	lCSVFileName->Caption = GLanguageHandler->Text[kFileName].c_str();

	rbCSVCategories->Caption = GLanguageHandler->Text[kCategories].c_str();
	rbCSVFullFileList->Caption = GLanguageHandler->Text[kFullFileList].c_str();
	lCSVFFLHelpText->Caption = GLanguageHandler->Text[kThisReportCanBeImported].c_str();

	cbCSVIncludeColumnTitles->Caption = GLanguageHandler->Text[kIncludeColumnTitles].c_str();

	// html tab
	lHTMLFileName->Caption = GLanguageHandler->Text[kFileName].c_str();

	lHTMLLayout->Caption = GLanguageHandler->Text[kReportLayout].c_str();
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbHTMLLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());
	cbHTMLLayouts->ItemIndex = 2;

	lHTMLFileSize->Caption = GLanguageHandler->Text[kShowFileSizesAs].c_str();
	cbHTMLFileSize->Items->Add(GLanguageHandler->Text[kMostConvenient].c_str());
	cbHTMLFileSize->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbHTMLFileSize->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbHTMLFileSize->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbHTMLFileSize->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());
	cbHTMLFileSize->ItemIndex = 0;

	// text tab
	tsText->Caption = GLanguageHandler->Text[kText].c_str();

	lTextFileName->Caption = GLanguageHandler->Text[kFileName].c_str();

	cbTextLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbTextLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());
	cbTextLayouts->ItemIndex = 2;

	// tree tab
	tsTree->Caption = GLanguageHandler->Text[kTree].c_str();

	lTreeFileName->Caption = GLanguageHandler->Text[kFileName].c_str();

	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbTreeLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());
	cbTreeLayouts->ItemIndex = 2;

	// xinorbis tab
	lXinorbisFileName->Caption = GLanguageHandler->Text[kFileName].c_str();

	lXinorbisHelpText->Caption = GLanguageHandler->Text[kThisReportCanBeImported].c_str();

	// xml tab
	lXMLFileName->Caption = GLanguageHandler->Text[kFileName].c_str();

	rbXMLScanData->Caption = GLanguageHandler->Text[kScanData].c_str();
	rbXMLFullFileList->Caption = GLanguageHandler->Text[kFullFileList].c_str();

	lXMLLayouts->Caption = GLanguageHandler->Text[kReportLayout].c_str();
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kAutoSave].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kQuick].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kOther].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kCustom1].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kCustom2].c_str());
	cbXMLLayouts->Items->Add(GLanguageHandler->Text[kCustom3].c_str());
	cbXMLLayouts->ItemIndex  = 2;

	// top toolbar
	Caption                     = GLanguageHandler->Text[kSaveReports].c_str();
	bSelectAll->Caption         = GLanguageHandler->Text[kSelectAll].c_str();
	bSelectNone->Caption        = GLanguageHandler->Text[kSelectNone].c_str();

	// bottom toolbar
	bGenerateFilenames->Caption = GLanguageHandler->Text[kGenerateFilenames].c_str();
	bSave->Caption              = GLanguageHandler->Text[kSave].c_str();
	bCancel->Caption            = GLanguageHandler->Text[kCancel].c_str();
	bHelp->Caption              = GLanguageHandler->Text[kHelp].c_str();

	if (CSVOptions.Data == kDataSummary)
	{
		rbCSVCategories->Checked = true;
	}
	else
	{
		rbCSVFullFileList->Checked = true;
	}

	if (XMLOptions.Data == kDataSummary)
	{
		rbXMLScanData->Checked = true;
	}
	else
	{
		rbXMLFullFileList->Checked = true;
	}
}


int TFormReportSaves::UpdateReports()
{
	int count = 0;

	if (cbToggleCSV->Checked)
	{
		CSVOptions.FileName  = CheckFileName(eCSVFileName->Text.c_str(), L".csv");
		CSVOptions.Category  = -1;
		CSVOptions.Units  = kCSVUnitsMegabytes;
		CSVOptions.Titles = cbCSVIncludeColumnTitles->Checked;

		if (rbCSVCategories->Checked)
		{
			CSVOptions.Data = kDataSummary;
		}
		else
		{
			CSVOptions.Data = kDataFileList;
		}
	}

	// =====================================================================

	if (cbToggleHTML->Checked)
	{
		HTMLOptions.Colours  = GSettingsHandler->Reports.HTML[cbHTMLLayouts->ItemIndex].Colours;

		HTMLOptions.FileName     = CheckFileName(eHTMLFileName->Text.c_str(), L".htm");
		HTMLOptions.Units        = cbHTMLFileSize->ItemIndex;
		HTMLOptions.Layout       = GSettingsHandler->Reports.HTML[cbHTMLLayouts->ItemIndex].Layout;
		HTMLOptions.LayoutSize   = GSettingsHandler->Reports.HTML[cbHTMLLayouts->ItemIndex].LayoutSize;

		for (int t = 0; t < kFileCategoriesCount; t ++)
		{
			HTMLOptions.CategoryList[t] = GSettingsHandler->Reports.HTML[cbHTMLLayouts->ItemIndex].CategoryList[t];
		}
	}

	// =====================================================================

	if (cbToggleText->Checked)
	{
		TextOptions.FileName     = CheckFileName(eTextFileName->Text.c_str(), L".txt");

		TextOptions.Layout       = GSettingsHandler->Reports.Text[cbTextLayouts->ItemIndex].Layout;

		for (int t = 0; t < kFileCategoriesCount; t ++)
		{
			TextOptions.CategoryList[t] = GSettingsHandler->Reports.Text[cbTextLayouts->ItemIndex].CategoryList[t];
		}

		count++;
	}

	// =====================================================================

	if (cbToggleTree->Checked)
	{
		TreeOptions.FileName          = CheckFileName(eTreeFileName->Text.c_str(), L".txt");
		TreeOptions.Layout            = GSettingsHandler->Reports.Tree[cbTreeLayouts->ItemIndex].Layout;
		TreeOptions.IncludeSize       = GSettingsHandler->Reports.Tree[cbTreeLayouts->ItemIndex].IncludeSize;
		TreeOptions.IncludeAttributes = GSettingsHandler->Reports.Tree[cbTreeLayouts->ItemIndex].IncludeAttributes;

		for (int t = 0; t < kFileCategoriesCount; t ++)
		{
			TreeOptions.CategoryList[t] = GSettingsHandler->Reports.Tree[cbTreeLayouts->ItemIndex].CategoryList[t];
		}

		count++;
	}

	// =====================================================================

	if (cbToggleXML->Checked)
	{
		XMLOptions.FileName = CheckFileName(eXMLFileName->Text.c_str(), L".xml");

		if (rbXMLScanData->Checked)
		{
			XMLOptions.Data = kDataSummary;
		}
		else
		{
			XMLOptions.Data = kDataFileList;
		}

		XMLOptions.Layout = GSettingsHandler->Reports.XML[cbXMLLayouts->ItemIndex].Layout;

		count++;
	}

	// =====================================================================

	if (cbToggleXinorbis->Checked)
	{
		XinOptions.FileName = CheckFileName(eXinorbisFileName->Text.c_str(), L".zsr");

		XinOptions.Layout = 1;

		count++;
	}

	return count;
}


void TFormReportSaves::SaveReports()
{
	if (cbToggleCSV->Checked)
	{
		GReportHandler->SaveCSV(CSVOptions, DataSource, false, false);
	}

	// =====================================================================

	if (cbToggleHTML->Checked)
	{
		GReportHandler->SaveHTML(HTMLOptions, DataSource, false, false);
	}

	// =====================================================================

	if (cbToggleText->Checked)
	{
		GReportHandler->SaveText(TextOptions, DataSource, false, false);
	}

	// =====================================================================

	if (cbToggleTree->Checked)
	{
		GReportHandler->SaveTree(TreeOptions, DataSource, false, false);
	}

	// =====================================================================

	if (cbToggleXinorbis->Checked)
	{
		GReportHandler->SaveXinorbis(XinOptions, DataSource, false, false);
	}

	// =====================================================================

	if (cbToggleXML->Checked)
	{
		GReportHandler->SaveXML(XMLOptions, DataSource, false, false);
	}
}


void TFormReportSaves::ChangeFolders(const std::wstring folder)
{
	for (int t = 0; t < 6; t++)
	{
		if (Edits[t]->Text != L"")
		{
			std::wstring file_name = Utility::SplitFileName(Edits[t]->Text.c_str());

			Edits[t]->Text = (folder + file_name).c_str();
		}
	}
}


void TFormReportSaves::SetSaveStatus()
{
	bool status = true;

	if (GScanEngine->Data[DataSource].Files.size() == 0)
	{
		status = false;
	}
	else
	{
		status = false;

		for (int t = 0; t < 5; t++)
		{
			if (Checks[t]->Checked)
			{
				status = true;
				break;
			}
		}
	}

	bSave->Enabled = status;
	bGenerateFilenames->Enabled = status;
}


std::wstring TFormReportSaves::CheckFileName(const std::wstring file_name, const std::wstring valid_extension)
{
	std::wstring extension = Utility::GetFileExtension(file_name);

	if (extension == valid_extension)
	{
		return file_name;
	}

	return file_name + valid_extension;
}


#pragma region Top_Toolbar
void __fastcall TFormReportSaves::bSelectAllClick(TObject *Sender)
{
	SetAll(true);
}


void __fastcall TFormReportSaves::bSelectNoneClick(TObject *Sender)
{
	SetAll(false);
}


void TFormReportSaves::SetAll(bool status)
{
	cbToggleCSV->Checked      = status;
	cbToggleHTML->Checked     = status;
	cbToggleText->Checked     = status;
	cbToggleTree->Checked     = status;
	cbToggleXinorbis->Checked = status;
	cbToggleXML->Checked      = status;

	cbToggleCSVClick(cbToggleCSV);
	cbToggleCSVClick(cbToggleHTML);
	cbToggleCSVClick(cbToggleText);
	cbToggleCSVClick(cbToggleTree);
	cbToggleCSVClick(cbToggleXinorbis);
	cbToggleCSVClick(cbToggleXML);

	SetSaveStatus();
}
#pragma end_region


#pragma region Bottom_Toolbar
void __fastcall TFormReportSaves::bGenerateFilenamesClick(TObject *Sender)
{
	auto GetFileName = [&](std::wstring folder, std::wstring file_name) -> std::wstring
	{
		if (Folder != L"")
		{
			return Folder + file_name;
		}
		else
		{
			return folder + file_name;
		}
	};


	std::wstring cname = WindowsUtility::GetComputerNetName();

	eCSVFileName->Text      = GetFileName(GSystemGlobal->AppDataPath + L"reports\\" + cname + L"\\csv\\",
										  Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
										  Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".csv").c_str();

	eHTMLFileName->Text     = GetFileName(GSystemGlobal->AppDataPath + L"reports\\" + cname + L"\\html\\",
										  Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
										  Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".html").c_str();

	eTextFileName->Text     = GetFileName(GSystemGlobal->AppDataPath + L"reports\\" + cname + L"\\Text\\",
										  Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
										  GLanguageHandler->Text[kText] + L"_" + Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" +
										  Utility::GetTime(DateTimeFormat::File) + L".txt").c_str();

	eTreeFileName->Text     = GetFileName(GSystemGlobal->AppDataPath + L"reports\\" + cname + L"\\Tree\\",
										  Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
										  GLanguageHandler->Text[kTree] + L"_" + Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" +
										  Utility::GetTime(DateTimeFormat::File) + L".txt").c_str();

	eXinorbisFileName->Text = GetFileName(GSystemGlobal->AppDataPath + L"reports\\" + cname + L"\\Xinorbis\\",
										  Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
										  Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".zsr2").c_str();

	eXMLFileName->Text      = GetFileName(GSystemGlobal->AppDataPath + L"reports\\" + cname + L"\\xml\\",
										  Formatting::MakeFileNameCompatible(GScanEngine->Data[DataSource].Path.String) + L"_" +
										  Utility::GetDate(DateTimeFormat::YYYYMMDD) + L"_" + Utility::GetTime(DateTimeFormat::File) + L".xml").c_str();
}


void __fastcall TFormReportSaves::SpeedButton3Click(TObject *Sender)
{
	std::vector<std::wstring> paths;

	if (WindowsUtility::BrowseForFolder(paths, true, false))
	{
		std::wstring folder = paths[0];

		if (!folder.empty())
		{
			Folder = folder;

			ChangeFolders(Folder);
		}
	}
}


void __fastcall TFormReportSaves::bHelpClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"savereporst.htm");
}


void __fastcall TFormReportSaves::bSaveClick(TObject *Sender)
{
	std::wstring s = L"";

	if (cbToggleText->Checked && eTextFileName->Text != L"")
	{
		s = L"\"" + GLanguageHandler->Text[kText] + L" " + GLanguageHandler->Text[kReport] + L"\" " + GLanguageHandler->Text[kHasBeenSelected];
	}

	if (cbToggleXinorbis->Checked && eXinorbisFileName->Text != L"")
	{
		if (s != L"") s + L"\n\n";

		s += L"\"Xinorbis " + GLanguageHandler->Text[kReport] + L"\" " + GLanguageHandler->Text[kHasBeenSelected];
	}

	if (cbToggleHTML->Checked && eHTMLFileName->Text != L"")
	{
		if (s != L"") s + L"\n\n";

		s += L"\"HTML " + GLanguageHandler->Text[kReport] + L"\" " + GLanguageHandler->Text[kHasBeenSelected];
	}

	if (cbToggleCSV->Checked && eCSVFileName->Text != L"")
	{
		if (s != L"") s + L"\n\n";

		s += L"\"CSV " + GLanguageHandler->Text[kReport] + L"\" " + GLanguageHandler->Text[kHasBeenSelected];
	}

	if (cbToggleXML->Checked && eXMLFileName->Text != L"")
	{
		if (s != L"") s + L"\n\n";

		s += L"\"XML " + GLanguageHandler->Text[kReport] + L"\" " + GLanguageHandler->Text[kHasBeenSelected];
	}

	if (s == L"")
	{
		///ModalResult = mrOK // surely no mrOK
	}
	else
	{
		std::wstring message = s + L"\n\n" + GLanguageHandler->Text[kAreYouSureContinue];

		if (MessageDlg(s.c_str(), mtWarning, mbYesNo, 0) == mrYes)
		{
			ModalResult = mrOk;
		}
	}
}
#pragma end_region


#pragma region Tab_CSV
void __fastcall TFormReportSaves::cbToggleCSVClick(TObject *Sender)
{
	SetSaveStatus();
}


void __fastcall TFormReportSaves::sbCSVFolderClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCSVFiles] + L" (*.csv)|*.csv",
												  L".csv",
												  Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kReport] + L"_" + GLanguageHandler->Text[kExport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		eCSVFileName->Text = file_name.c_str();

		if (!cbToggleCSV->Checked)
		{
			SetSaveStatus();
		}
	}
}
#pragma end_region


#pragma region Tab_HTML
void __fastcall TFormReportSaves::cbToggleHTMLClickClick(TObject *Sender)
{
	SetSaveStatus();
}


void __fastcall TFormReportSaves::sbHTMLFolderClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kHTMLFiles] + L" (*.html, *.htm)|*.html; *.htm",
												  L".htm",
												  Utility::GetDefaultFileName(L".htm", GLanguageHandler->Text[kReport] + L"_" + GLanguageHandler->Text[kExport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		eHTMLFileName->Text = file_name.c_str();

		if (!cbToggleHTML->Checked)
		{
			SetSaveStatus();
		}
	}

}


void __fastcall TFormReportSaves::cbHTMLLayoutsChange(TObject *Sender)
{
	cbHTMLFileSize->ItemIndex = GSettingsHandler->Reports.HTML[cbHTMLLayouts->ItemIndex].Units;

// leave uncommented cbHTMLShowImages->Checked = TUtility.FindReportItem(XSettings.Report.HTMLOptions[cbHTMLLayouts.ItemIndex + 1], 0);
}
#pragma end_region


#pragma region Tab_Text
void __fastcall TFormReportSaves::cbToggleTextClickClick(TObject *Sender)
{
	SetSaveStatus();
}


void __fastcall TFormReportSaves::sbTextFolderClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt",
												  L".txt",
												  Utility::GetDefaultFileName(L".txt", GLanguageHandler->Text[kReport] + L"_" + GLanguageHandler->Text[kExport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		eTextFileName->Text = file_name.c_str();

		if (!cbToggleText->Checked)
		{
			SetSaveStatus();
		}
	}
}
#pragma end_region


#pragma region Tab_Tree
void __fastcall TFormReportSaves::cbToggleTreeClickClick(TObject *Sender)
{
	SetSaveStatus();
}


void __fastcall TFormReportSaves::sbTreeFolderClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTreeFiles] + L" (*.xcrtree)|*.xcrtree",
												  L".xcrtree",
												  Utility::GetDefaultFileName(L".xcrtree", GLanguageHandler->Text[kReport] + L"_" + GLanguageHandler->Text[kExport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		eTreeFileName->Text = file_name.c_str();

		if (!cbToggleTree->Checked)
		{
			SetSaveStatus();
		}
	}
}
#pragma end_region


#pragma region Tab_Xinorbis
void __fastcall TFormReportSaves::cbToggleXinorbisClick(TObject *Sender)
{
	SetSaveStatus();
}


void __fastcall TFormReportSaves::sbXinorbisFolderClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(L"Xinorbis v2 (*.zsr2)|*.zsr2",
												  L".zsr2",
												  Utility::GetDefaultFileName(L".zsr2", GLanguageHandler->Text[kReport] + L"_" + GLanguageHandler->Text[kExport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		eXinorbisFileName->Text = file_name.c_str();

		if (!cbToggleXinorbis->Checked)
		{
			SetSaveStatus();
		}
	}
}
#pragma end_region


#pragma region Tab_XML
void __fastcall TFormReportSaves::cbToggleXMLClick(TObject *Sender)
{
	SetSaveStatus();
}


void __fastcall TFormReportSaves::sbXMLFolderClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kXMLFiles] + L" (*.xml)|*.xml",
												  L".xml",
												  Utility::GetDefaultFileName(L".xml", GLanguageHandler->Text[kReport] + L"_" + GLanguageHandler->Text[kExport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		eXMLFileName->Text = file_name.c_str();

		if (!cbToggleXML->Checked)
		{
			SetSaveStatus();
		}
	}
}
#pragma end_region
