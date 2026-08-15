//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <System.DateUtils.hpp>
#include <fstream>

#include "ConstantsGui.h"
#include "ConstantsSystem.h"
#include "DateUtility.h"
#include "Formatting.h"
#include "FormDetails.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"

#include "XFormFileAges.h"

extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormFileAges *FormFileAges;
//---------------------------------------------------------------------------
__fastcall TFormFileAges::TFormFileAges(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormFileAges::FormCreate(TObject *Sender)
{
	Init();
}


void __fastcall TFormFileAges::FormShow(TObject *Sender)
{
	FormResize(NULL);

	cbUsers->Items->Clear();
	cbUsers->Items->Add(GLanguageHandler->Text[kAll].c_str());

	for (int t = 0; t < GScanEngine->Data[DataSource].Users.size(); t++)
	{
		cbUsers->Items->Add(GScanEngine->Data[DataSource].Users[t]->Name.c_str());
	}

	cbUsers->ItemIndex = 0;
}


void __fastcall TFormFileAges::FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight,
		  bool &Resize)
{
	if (NewHeight > 404 && NewWidth > 740)
	{
		Resize = true;
	}
	else
    {
		Resize = false;
	}
}


void __fastcall TFormFileAges::FormResize(TObject *Sender)
{
	int col_widths = sgResults->ColWidths[1] + sgResults->ColWidths[2] + sgResults->ColWidths[3] + sgResults->ColWidths[4];

	sgResults->ColWidths[0] = sgResults->Width - (__WidthOfScrollbar + col_widths);
}


void __fastcall TFormFileAges::FormClose(TObject *Sender, TCloseAction &Action)
{
//	FormDetails fd(_FormFileAges, Left, Top, Width, Height);

//	XSettings.SaveFormDetails(fd);

//	if Assigned(FULSP) then
//	{
//		FULSP(_FormFileAges);
//	}

//	Action = caHide;
}


void TFormFileAges::Init()
{
	Caption = GLanguageHandler->Text[kFileAge].c_str();

	gbUsers->Caption = GLanguageHandler->Text[kUsers].c_str();

	bGo->Caption = GLanguageHandler->Text[kShow].c_str();
	cbAutoRefresh->Caption = GLanguageHandler->Text[kAutoRefresh].c_str();

	cbFiles->Caption   = GLanguageHandler->Text[kFiles].c_str();
	cbFolders->Caption = GLanguageHandler->Text[kFolders].c_str();

	cbAttribute->Items->Add(GLanguageHandler->Text[kCreated].c_str());
	cbAttribute->Items->Add(GLanguageHandler->Text[kAccessed].c_str());
	cbAttribute->Items->Add(GLanguageHandler->Text[kModified].c_str());
	cbAttribute->ItemIndex = 0;

	sgResults->Cells[0][0] = GLanguageHandler->Text[kFileName].c_str();
	sgResults->Cells[1][0] = GLanguageHandler->Text[kCreated].c_str();
	sgResults->Cells[2][0] = GLanguageHandler->Text[kAccessed].c_str();
	sgResults->Cells[3][0] = GLanguageHandler->Text[kModified].c_str();
	sgResults->Cells[4][0] = GLanguageHandler->Text[kSize].c_str();

	//sgResults->HideColumn(5);

	cbFileAgeType->Items->Add(GLanguageHandler->Text[kOlderThan].c_str());
	cbFileAgeType->Items->Add(GLanguageHandler->Text[kWithinTheLast].c_str());
	cbFileAgeType->ItemIndex = 0;

	cbInterval->Items->Add(GLanguageHandler->Text[kDay].c_str());
	cbInterval->Items->Add(GLanguageHandler->Text[kWeek].c_str());
	cbInterval->Items->Add(GLanguageHandler->Text[kMonth].c_str());
	cbInterval->Items->Add(GLanguageHandler->Text[kYear].c_str());

	cbInterval->ItemIndex = kIntervalDay;

	// ===========================================================================

	int colwidth = this->Canvas->TextWidth(L"2026/88/88") + 15;

	sgResults->ColWidths[1] = colwidth;
	sgResults->ColWidths[2] = colwidth;
	sgResults->ColWidths[3] = colwidth;
	sgResults->ColWidths[4] = colwidth;

	// ===========================================================================

	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormFileAges);

	if (fd.FormId != 1)
	{
		Left   = fd.X;
		Top	   = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}
}

//    FULSP : TUpdateLeftStatusPanel;
//  public
//    property OnHide : TUpdateLeftStatusPanel read FULSP write FULSP;
//  end;


/*procedure TfrmFileAges.sgResultsCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);    to do
begin
  if Acol = 4 then begin
    DoSort := False; // stops the component for sorting automatically

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction := sdAscending
      else
        SortSettings.Direction := sdDescending;

      Sortsettings.Column := 5;
      QSort;

      SortSettings.Column := 4;
    end;
  end
end;

procedure TfrmFileAges.sgResultsGetAlignment(Sender: TObject; ARow,
  ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  if (ACol = 4) then
    HAlign := taRightJustify
  else
    HAlign := taLeftJustify;
end;


procedure TfrmFileAges.sgResultsGetCellColor(Sender: TObject; ARow,
  ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
begin
  if gdSelected in AState then
    ABrush.Color := CGridColourSelected
  else begin
    if Odd(ARow) then
      ABrush.Color := CGridColourOn
    else
      ABrush.Color := CGridColourOff;
  end;
end;*/


void __fastcall TFormFileAges::bGoClick(TObject *Sender)
{
	Cursor = crHourGlass;

	if (bGo->Tag != cbAttribute->ItemIndex)
	{
		switch (cbAttribute->ItemIndex)
		{
		case kAttributeCreated:
			GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateCreated);
			break;
		case kAttributeAccessed:
			GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateAccessed);
			break;
		case kAttributeModified:
			GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateModified);
			break;
		}

		bGo->Tag = cbAttribute->ItemIndex;
	}

//	sgResults->ClearRows(1, sgResults.RowCount - 1);
	sgResults->RowCount = 2;
	sgResults->BeginUpdate();

	int xcount = eCount->Text.ToIntDef(30);

	// ===========================================================================
	// ===========================================================================

	int StartDate = 0;

	switch (cbInterval->ItemIndex)
	{
	case kIntervalDay:
		StartDate = Convert::DateToYYYYMMDDI(IncDay(Now(), -xcount));
		break;
	case kIntervalWeek:
		StartDate = Convert::DateToYYYYMMDDI(IncWeek(Now(), -xcount));
		break;
	case kIntervalMonth:
		StartDate = Convert::DateToYYYYMMDDI(IncMonth(Now(), -xcount));
		break;
	case kIntervalYear:
		StartDate = Convert::DateToYYYYMMDDI(IncMonth(Now(), -(12 * xcount)));
		break;

	default:
		StartDate = Convert::DateToYYYYMMDDI(IncDay(Now(), -xcount));
		break;
	}

	// ===========================================================================
	// ===========================================================================

	int Row = 1;
	unsigned __int64 FileSize = 0;
	int FileCount = 0;
	int UserId = -1;

	Caption = StartDate;

	if (cbUsers->ItemIndex != 0)
	{
		UserId = GScanEngine->Data[DataSource].FindUser(cbUsers->Items->Strings[cbUsers->ItemIndex].c_str());
	}

	bool CheckUser = true;

	// ===========================================================================
	// ===========================================================================

	switch (cbFileAgeType->ItemIndex)
	{
	case kTypeOlderThan:
	{
		for (int f = 0; f < GScanEngine->Data[DataSource].Files.size(); f++)
		{
			FileObject *tfo = GScanEngine->Data[DataSource].Files[f];

			if (UserId != -1)
			{
				if (tfo->Owner == UserId)
				{
					CheckUser = true;
				}
				else
				{
					CheckUser = false;
				}
			}

			if (CheckUser &&
				( ((tfo->Attributes & FILE_ATTRIBUTE_DIRECTORY) && cbFolders->Checked) ||
				  ((!(tfo->Attributes & FILE_ATTRIBUTE_DIRECTORY)) && cbFiles->Checked) ))
			{
				bool CanAdd = false;

				switch (cbAttribute->ItemIndex)
				{
				case kAttributeCreated:
					if (tfo->DateCreated <= StartDate) CanAdd = true;
					break;
				case kAttributeAccessed:
					if (tfo->DateAccessed <= StartDate) CanAdd = true;
					break;
				case kAttributeModified:
					if (tfo->DateModified <= StartDate) CanAdd = true;
					break;
				}

				if (CanAdd)
				{
					FileSize += tfo->Size;
					FileCount++;

					if (Row < 1000)
					{
						sgResults->Cells[0][Row] = (GScanEngine->Data[DataSource].Folders[tfo->FilePathIndex] + tfo->Name).c_str();

						sgResults->Cells[1][Row] = Convert::IntDateToString(tfo->DateCreated).c_str();
						sgResults->Cells[2][Row] = Convert::IntDateToString(tfo->DateAccessed).c_str();
						sgResults->Cells[3][Row] = Convert::IntDateToString(tfo->DateModified).c_str();

						if (tfo->Attributes & FILE_ATTRIBUTE_DIRECTORY)
						{
							sgResults->Cells[4][Row] = GLanguageHandler->Text[kFolder].c_str();
							sgResults->Cells[5][Row] = L"0";
						}
						else
						{
							sgResults->Cells[4][Row] = Convert::ConvertToUsefulUnit(tfo->Size).c_str();
							sgResults->Cells[5][Row] = tfo->Size;
						}

						sgResults->RowCount++;

						Row++;
					}
				}
			}
		}
		break;
	}
	case kTypeWithinTheLast:
	{
		for (int f = GScanEngine->Data[DataSource].Files.size() - 1; f >=0 ; f--)
		{
			FileObject *tfo = GScanEngine->Data[DataSource].Files[f];

			if (UserId != -1)
			{
				if (tfo->Owner == UserId)
				{
					CheckUser = true;
				}
				else
				{
					CheckUser = false;
				}
			}

			if (CheckUser &&
				( ((tfo->Attributes & FILE_ATTRIBUTE_DIRECTORY) && cbFolders->Checked) ||
				  ((!(tfo->Attributes & FILE_ATTRIBUTE_DIRECTORY)) && cbFiles->Checked) ))
			{
				bool CanAdd = false;

				switch (cbAttribute->ItemIndex)
				{
				case kAttributeCreated:
					if (tfo->DateCreated >= StartDate) CanAdd = true;
					break;
				case kAttributeAccessed:
					if (tfo->DateAccessed >= StartDate) CanAdd = true;
					break;
				case kAttributeModified:
					if (tfo->DateModified >= StartDate) CanAdd = true;
					break;
				}

				if (CanAdd)
				{
					FileSize += tfo->Size;
					FileCount++;

					if (Row < 1000)
					{
						sgResults->Cells[0][Row] = (GScanEngine->Data[DataSource].Folders[tfo->FilePathIndex] + tfo->Name).c_str();

						sgResults->Cells[1][Row] = Convert::IntDateToString(tfo->DateCreated).c_str();
						sgResults->Cells[2][Row] = Convert::IntDateToString(tfo->DateAccessed).c_str();
						sgResults->Cells[3][Row] = Convert::IntDateToString(tfo->DateModified).c_str();

						if (tfo->Attributes & FILE_ATTRIBUTE_DIRECTORY)
						{
							 sgResults->Cells[4][Row] = GLanguageHandler->Text[kFolder].c_str();
							 sgResults->Cells[5][Row] = L"0";
						}
						else
						{
							 sgResults->Cells[4][Row] = Convert::ConvertToUsefulUnit(tfo->Size).c_str();
							 sgResults->Cells[5][Row] = tfo->Size;
						}

						sgResults->RowCount++;

						Row++;
					}
				}
			}
		}
		break;
	}
    }

	if (Row > 2)
	{
		sgResults->RowCount--;
	}
	else
	{
		sgResults->Cells[0][1] = GLanguageHandler->Text[kNoMatchesFound].c_str();
	}

	sgResults->EndUpdate();

	pStatus->Caption = (std::to_wstring(FileCount) + L" " + GLanguageHandler->Text[kFiles] + L" (" + Convert::ConvertToUsefulUnit(FileSize) + L")").c_str();

	Cursor = crDefault;
}


void __fastcall TFormFileAges::bReportCSVClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCSVFiles] + L" (*.csv)|*.csv",
												  L".csv",
												  Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kFileAge] + L"_" + GLanguageHandler->Text[kReport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		ExportDataCSV(file_name, true);
	}
}


void __fastcall TFormFileAges::bReportXMLClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kXMLFiles] + L" (*.xml)|*.xml",
												  L".xml",
												  Utility::GetDefaultFileName(L".xml", GLanguageHandler->Text[kFileAge] + L"_" + GLanguageHandler->Text[kReport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		ExportDataXML(file_name);
	}
}


void __fastcall TFormFileAges::bHelpClick(TObject *Sender)
{
//
}


void __fastcall TFormFileAges::cbAttributeChange(TObject *Sender)
{
	if (cbAutoRefresh->Checked)
	{
		bGoClick(NULL);
	}
}


void __fastcall TFormFileAges::eCountEnter(TObject *Sender)
{
	OldText = eCount->Text.c_str();
}


void __fastcall TFormFileAges::eCountExit(TObject *Sender)
{
	int Value = eCount->Text.ToIntDef(-1);

	if (Value == -1)
	{
		eCount->Text = OldText.c_str();
	}
}


void __fastcall TFormFileAges::eCountKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN && cbAutoRefresh->Checked)
	{
		bGoClick(NULL);
	}
}


void TFormFileAges::ExportDataCSV(const std::wstring file_name, bool include_header)
{
	auto WriteCSVObject = [&](FileObject *tfo) -> std::wstring
	{
		std::wstring s = L"";

		if (faDirectory & tfo->Attributes)
		{
			s = L"\"" + GScanEngine->Data[DataSource].Folders[tfo->FilePathIndex] + tfo->Name + L"\",";
			s += L"\"" + GScanEngine->Data[DataSource].Folders[tfo->FilePathIndex] + L"\",\"" + tfo->Name + L"\",";

			s += GLanguageHandler->Text[kFolderUC] + L",";
			s += L"-1,";
			s += L"-1,";

			s += Convert::IntDateToString(tfo->DateCreated) + L",";
			s += Convert::IntDateToString(tfo->DateAccessed) + L",";
			s += Convert::IntDateToString(tfo->DateModified) + L",";

			s += GLanguageHandler->Text[kFolderUC] + L",";

			s += L"99,";

			s += GScanEngine->Data[DataSource].Users[tfo->Owner]->Name + L",";

			s += Convert::AttributeToIntAsString(tfo->Attributes, faReadOnly) + L",";
			s += Convert::AttributeToIntAsString(tfo->Attributes, faHidden) + L",";
			s += Convert::AttributeToIntAsString(tfo->Attributes, faSysFile) + L",";
			s += Convert::AttributeToIntAsString(tfo->Attributes, faArchive) + L",";
			s += std::to_wstring(Convert::BoolToInteger(tfo->Temp)) + L",";

			s += std::to_wstring(DaysBetween(Now(), DateUtility::YYYYMMDDToDate(tfo->DateCreated))) + L",";
			s += std::to_wstring(DaysBetween(Now(), DateUtility::YYYYMMDDToDate(tfo->DateAccessed))) + L",";
			s += std::to_wstring(DaysBetween(Now(), DateUtility::YYYYMMDDToDate(tfo->DateModified)));
		}
		else
		{
			s = L"\"" + GScanEngine->Data[DataSource].Folders[tfo->FilePathIndex] + tfo->Name + L"\",";
			s += GScanEngine->Data[DataSource].Folders[tfo->FilePathIndex] + L"\",\"" + tfo->Name + L"\",";

			s += L"\"" + Convert::GetSizeString(0, tfo->Size) + L"\",";
			s += L"\"" + std::to_wstring(tfo->Size) + L"\",";
			s += L"\"" + std::to_wstring(tfo->SizeOnDisk) + L"\",";

			s += Convert::IntDateToString(tfo->DateCreated) + L",";
			s += Convert::IntDateToString(tfo->DateAccessed) + L",";
			s += Convert::IntDateToString(tfo->DateModified) + L",";

			s += GLanguageHandler->TypeDescriptions[tfo->Category] + L",";

			s += std::to_wstring(tfo->Category) + L",";

			s += GScanEngine->Data[DataSource].Users[tfo->Owner]->Name + L",";

			s += Convert::AttributeToIntAsString(tfo->Attributes, faReadOnly) + L",";
			s += Convert::AttributeToIntAsString(tfo->Attributes, faHidden) + L",";
			s += Convert::AttributeToIntAsString(tfo->Attributes, faSysFile) + L",";
			s += Convert::AttributeToIntAsString(tfo->Attributes, faArchive) + L",";
			s += std::to_wstring(Convert::BoolToInteger(tfo->Temp)) + L",";

			s += std::to_wstring(DaysBetween(Now(), DateUtility::YYYYMMDDToDate(tfo->DateCreated))) + L",";
			s += std::to_wstring(DaysBetween(Now(), DateUtility::YYYYMMDDToDate(tfo->DateAccessed))) + L",";
			s += std::to_wstring(DaysBetween(Now(), DateUtility::YYYYMMDDToDate(tfo->DateModified)));
		}

		return s;
	};

	if (bGo->Tag != cbAttribute->ItemIndex)
	{
		switch (cbAttribute->ItemIndex)
		{
		case kAttributeCreated:
			GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateCreated);
			break;
		case kAttributeAccessed:
			GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateAccessed);
            break;
		case kAttributeModified:
			GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateModified);
			break;
		}

		bGo->Tag = cbAttribute->ItemIndex;
	}

	int ix = StrToIntDef(eCount->Text, 30);

	std::ofstream file(file_name);

	if (file)
	{
		if (include_header)
		{
			std::wstring s = GLanguageHandler->Text[kFilePath] + L"," +
							 GLanguageHandler->Text[kFolder] + L"," +
							 GLanguageHandler->Text[kFileName] + L"," +
							 GLanguageHandler->Text[kSize] + L"," +
							 GLanguageHandler->Text[kSizeOfFilesBytes] + L"," +
							 GLanguageHandler->Text[kSizeOnDisk] + L"," +
							 GLanguageHandler->Text[kCreatedDate] + L"," +
							 GLanguageHandler->Text[kAccessedDate] + L"," +
							 GLanguageHandler->Text[kModifiedDate] + L"," +
							 GLanguageHandler->Text[kCategory] + L"," +
							 GLanguageHandler->Text[kCategory] + L"ID," +
							 GLanguageHandler->Text[kOwner] + L"," +
							 GLanguageHandler->LanguageTypes[kFileType_ReadOnly] + L"," +
							 GLanguageHandler->LanguageTypes[kFileType_Hidden] + L"," +
							 GLanguageHandler->LanguageTypes[kFileType_System] + L"," +
							 GLanguageHandler->LanguageTypes[kFileType_Archive] + L"," +
							 GLanguageHandler->Text[kTemporary] + L"," +
							 L"CreatedAgeFullDays," +
							 L"AccessedAgeFullDays," +
							 L"ModifiedAgeFullDays";

			file << Formatting::to_utf8(s + L"\n");
		}

		// =========================================================================
		// =========================================================================

		int dt = 0;

		switch (cbInterval->ItemIndex)
		{
		case kIntervalDay:
			dt = Convert::DateToYYYYMMDDI(IncDay(Now(),   -ix));        // day
			break;
		case kIntervalWeek:
			dt = Convert::DateToYYYYMMDDI(IncWeek(Now(),  -ix));        // week
			break;
		case kIntervalMonth:
			dt = Convert::DateToYYYYMMDDI(IncMonth(Now(), -ix));        // month
			break;
		case kIntervalYear:
			dt = Convert::DateToYYYYMMDDI(IncMonth(Now(), -(12 * ix))); // year
			break;

		default:
			dt = Convert::DateToYYYYMMDDI(IncDay(Now(), -ix));          // day
			break;
		}

		// ===========================================================================
		// ===========================================================================

		switch (cbFileAgeType->ItemIndex)
		{
		case kTypeOlderThan:
		{
			for (FileObject *tfo : GScanEngine->Data[DataSource].Files)
			{
				bool addto = false;

				switch (cbAttribute->ItemIndex)
				{
				case kAttributeCreated:
					if (tfo->DateCreated <= dt)
					{
						addto = true;
					}
					break;
				case kAttributeAccessed:
					if (tfo->DateAccessed <= dt)
					{
						addto = true;
					}
					break;
				case kAttributeModified:
					if (tfo->DateModified <= dt)
					{
						addto = true;
					}
					break;
				}

				if (addto)
				{
					file << Formatting::to_utf8(WriteCSVObject(tfo) + L"\n");
				}
			}
			break;
		}
		case kTypeWithinTheLast:
		{
			for (FileObject *tfo : GScanEngine->Data[DataSource].Files)
			{
				bool addto = false;

				switch (cbAttribute->ItemIndex)
				{
				case kAttributeCreated:
					if (tfo->DateCreated >= dt)
					{
						addto = true;
					}
					break;
				case kAttributeAccessed:
					if (tfo->DateAccessed >= dt)
					{
						addto = true;
					}
					break;
				case kAttributeModified:
					if (tfo->DateModified >= dt)
					{
						addto = true;
					}
					break;
				}

				if (addto)
				{
					file << Formatting::to_utf8(WriteCSVObject(tfo) + L"\n");
				}
			}
			break;
		}
		}

		file.close();
	}
}


void TFormFileAges::ExportDataXML(const std::wstring file_name)
{
	auto WriteXMLObject = [&](std::ofstream &file, FileObject *tfo)
	{
		file << Formatting::to_utf8(L"    <file>\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"name",                 Formatting::ReplaceEntitiesForXML(tfo->Name), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"path",                 Formatting::ReplaceEntitiesForXML(GScanEngine->Data[DataSource].Folders[tfo->FilePathIndex]), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"sizewords",            Convert::ConvertToUsefulUnit(tfo->Size), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"sizebytes",            std::to_wstring(tfo->Size), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"sizeondiskwords",      Convert::ConvertToUsefulUnit(tfo->SizeOnDisk), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"sizeondiskbytes",      std::to_wstring(tfo->SizeOnDisk), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"owner",                GScanEngine->Data[DataSource].Users[tfo->Owner]->Name, 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"datecreated",          Convert::IntDateToString(tfo->DateCreated), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"datemodified",         Convert::IntDateToString(tfo->DateModified), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"dateaccessed",         Convert::IntDateToString(tfo->DateAccessed), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"datecreatedyyyymmdd",  std::to_wstring(tfo->DateCreated), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"datemodifiedyyyymmdd", std::to_wstring(tfo->DateModified), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"dateaccessedyyyymmdd", std::to_wstring(tfo->DateAccessed), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"category",             std::to_wstring(tfo->Category), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"directory",            Convert::AttributeToIntAsString(tfo->Attributes, faDirectory), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"readonly",             Convert::AttributeToIntAsString(tfo->Attributes, faReadOnly), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"hidden",               Convert::AttributeToIntAsString(tfo->Attributes, faHidden), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"system",               Convert::AttributeToIntAsString(tfo->Attributes, faSysFile), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"archive",              Convert::AttributeToIntAsString(tfo->Attributes, faArchive), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"temp",                 Convert::BoolToString(tfo->Temp), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"createdagefulldays",   std::to_wstring(DaysBetween(Now(), DateUtility::YYYYMMDDToDate(tfo->DateCreated))), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"accessedagefulldays",  std::to_wstring(DaysBetween(Now(), DateUtility::YYYYMMDDToDate(tfo->DateAccessed))), 2) + L"\n");
		file << Formatting::to_utf8(Formatting::InsertElement(L"modifiedagefulldays",  std::to_wstring(DaysBetween(Now(), DateUtility::YYYYMMDDToDate(tfo->DateModified))), 2) + L"\n");
		file << Formatting::to_utf8(L"    </file>\n");
	};

	if (bGo->Tag != cbAttribute->ItemIndex)
	{
		switch (cbAttribute->ItemIndex)
		{
		case kAttributeCreated:
			GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateCreated);
			break;
		case kAttributeAccessed:
			GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateAccessed);
			break;
		case kAttributeModified:
			GScanEngine->Data[DataSource].SortByProperty(SortMode::kDateModified);
			break;
		}

		bGo->Tag = cbAttribute->ItemIndex;
	}

	int ix = StrToIntDef(eCount->Text, 30);

	std::ofstream file(file_name.c_str());

	if (file)
	{
		std::wstring contents = (cbAttribute->Text + L", " + cbFileAgeType->Text + L", " + eCount->Text + L", " + cbInterval->Text).c_str();

		file << Formatting::to_utf8(L"<?xml version=\"1.0\"?>\n");
		file << Formatting::to_utf8(L"<!-- generated with Xinorbis " + __XVersion + L" - " + __XDate + L" -->\n");
		file << Formatting::to_utf8(L"<!-- http://xinorbis.co.uk - Paul A Freshney " + DateUtility::CurrentYear() + L" -->\n");
		file << Formatting::to_utf8(L"<!-- File Age: " + contents + L" -->\n");
		file << Formatting::to_utf8(L"<xinorbisfilelist>\n");

		// ===========================================================================
		// ===========================================================================

		int dt = 0;

		switch (cbInterval->ItemIndex)
		{
		case kIntervalDay:
			dt = Convert::DateToYYYYMMDDI(IncDay(Now(),   -ix));        // day
			break;
		case kIntervalWeek:
			dt = Convert::DateToYYYYMMDDI(IncWeek(Now(),  -ix));        // week
			break;
		case kIntervalMonth:
			dt = Convert::DateToYYYYMMDDI(IncMonth(Now(), -ix));        // month
			break;
		case kIntervalYear:
			dt = Convert::DateToYYYYMMDDI(IncMonth(Now(), -(12 * ix))); // year
			break;

		default:
			dt = Convert::DateToYYYYMMDDI(IncDay(Now(), -ix));         // day
		}

		// ===========================================================================
		// ===========================================================================

		switch (cbFileAgeType->ItemIndex)
		{
		case kTypeOlderThan:
			for (FileObject *tfo : GScanEngine->Data[DataSource].Files)
			{
				bool addto = false;

				switch (cbAttribute->ItemIndex)
				{
				case kAttributeCreated:
					if (tfo->DateCreated <= dt)
					{
						addto = true;
					}
					break;
				case kAttributeAccessed:
					if (tfo->DateAccessed <= dt)
					{
						addto = true;
					}
					break;
				case kAttributeModified:
					if (tfo->DateModified <= dt)
					{
						addto = true;
					}
					break;
				}

				if (addto)
				{
					WriteXMLObject(file, tfo);
				}
			}
			break;
		case kTypeWithinTheLast:
			for (int t = GScanEngine->Data[DataSource].Files.size() - 1; t >= 0; t--)
			{
				FileObject *tfo = GScanEngine->Data[DataSource].Files[t];

				bool addto = false;

				switch (cbAttribute->ItemIndex)
				{
				case kAttributeCreated:
					if (tfo->DateCreated >= dt)
					{
						addto = true;
					}
					break;
				case kAttributeAccessed:
					if (tfo->DateAccessed >= dt)
					{
						addto = true;
					}
					break;
				case kAttributeModified:
					if (tfo->DateModified >= dt)
					{
						addto = true;
					}
					break;
				}

				if (addto)
				{
					WriteXMLObject(file, tfo);
				}
			}
		}

		file << Formatting::to_utf8(L"</xinorbisfilelist>\n");

		file.close();
	}
	else
	{
	}
}
