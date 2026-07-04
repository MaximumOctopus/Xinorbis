//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <System.DateUtils.hpp>

#include "ConstantsGui.h"
#include "LanguageHandler.h"
#include "LoadDialogs.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SystemGlobal.h"
#include "Utility.h"

#include "XFormFileAges.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SystemGlobal* GSystemGlobal;

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

	for (int t = 0; t < GScanEngine->Data.Users.size(); t++)
	{
		cbUsers->Items->Add(GScanEngine->Data.Users[t].Name.c_str());
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

	//fd := XSettings.LoadFormDetails(_FormFileAges);

//  if (fd.formID <> -1)
//  {
//	Left             := fd.x;
//	Top              := fd.y;
//    Width            := fd.w;
//    Height           := fd.h;
//	}
}

//    FULSP : TUpdateLeftStatusPanel;
//  public
//    property OnHide : TUpdateLeftStatusPanel read FULSP write FULSP;
//  end;


/*procedure TfrmFileAges.sgResultsCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
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
			GScanEngine->SortByProperty(0);
			break;
		case kAttributeAccessed:
			GScanEngine->SortByProperty(1);
			break;
		case kAttributeModified:
			GScanEngine->SortByProperty(2);
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
		StartDate = Convert::DateToYYYYMMDDI(IncDay(Now(), -xcount));          // day
		break;
	case kIntervalWeek:
		StartDate = Convert::DateToYYYYMMDDI(IncWeek(Now(), -xcount));         // week
		break;
	case kIntervalMonth:
		StartDate = Convert::DateToYYYYMMDDI(IncMonth(Now(), -xcount));        // month
		break;
	case kIntervalYear:
		StartDate = Convert::DateToYYYYMMDDI(IncMonth(Now(), -(12 * xcount))); // year
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
		UserId = GScanEngine->FindUser(cbUsers->Items->Strings[cbUsers->ItemIndex].c_str());
	}

	bool CheckUser = true;

	// ===========================================================================
	// ===========================================================================

	switch (cbFileAgeType->ItemIndex)
	{
	case kTypeOlderThan:
	{
		for (int f = 0; f < GScanEngine->Data.Files.size(); f++)
		{
			FileObject tfo = GScanEngine->Data.Files[f];

			if (UserId != -1)
			{
				if (tfo.Owner == UserId)
				{
					CheckUser = true;
				}
				else
				{
					CheckUser = false;
				}
			}

			if (CheckUser &&
				( ((tfo.Attributes & FILE_ATTRIBUTE_DIRECTORY) && cbFolders->Checked) ||
				  ((!(tfo.Attributes & FILE_ATTRIBUTE_DIRECTORY)) && cbFiles->Checked) ))
			{
				bool CanAdd = false;

				switch (cbAttribute->ItemIndex)
				{
				case kAttributeCreated:
					if (tfo.DateCreated <= StartDate) CanAdd = true;
					break;
				case kAttributeAccessed:
					if (tfo.DateAccessed <= StartDate) CanAdd = true;
					break;
				case kAttributeModified:
					if (tfo.DateModified <= StartDate) CanAdd = true;
					break;
				}

				if (CanAdd)
				{
					FileSize += tfo.Size;
					FileCount++;

					if (Row < 1000)
					{
						sgResults->Cells[0][Row] = (GScanEngine->Data.Folders[tfo.FilePathIndex] + tfo.Name).c_str();

						sgResults->Cells[1][Row] = Convert::IntDateToString(tfo.DateCreated).c_str();
						sgResults->Cells[2][Row] = Convert::IntDateToString(tfo.DateAccessed).c_str();
						sgResults->Cells[3][Row] = Convert::IntDateToString(tfo.DateModified).c_str();

						if (tfo.Attributes & FILE_ATTRIBUTE_DIRECTORY)
						{
							sgResults->Cells[4][Row] = GLanguageHandler->Text[kFolder].c_str();
							sgResults->Cells[5][Row] = L"0";
						}
						else
						{
							sgResults->Cells[4][Row] = Convert::ConvertToUsefulUnit(tfo.Size).c_str();
							sgResults->Cells[5][Row] = tfo.Size;
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
		for (int f = GScanEngine->Data.Files.size() - 1; f >=0 ; f--)
		{
			FileObject tfo = GScanEngine->Data.Files[f];

			if (UserId != -1)
			{
				if (tfo.Owner == UserId)
				{
					CheckUser = true;
				}
				else
				{
					CheckUser = false;
				}
			}

			if (CheckUser &&
				( ((tfo.Attributes & FILE_ATTRIBUTE_DIRECTORY) && cbFolders->Checked) ||
				  ((!(tfo.Attributes & FILE_ATTRIBUTE_DIRECTORY)) && cbFiles->Checked) ))
			{
				bool CanAdd = false;

				switch (cbAttribute->ItemIndex)
				{
				case kAttributeCreated:
					if (tfo.DateCreated >= StartDate) CanAdd = true;
					break;
				case kAttributeAccessed:
					if (tfo.DateAccessed >= StartDate) CanAdd = true;
					break;
				case kAttributeModified:
					if (tfo.DateModified >= StartDate) CanAdd = true;
					break;
				}

				if (CanAdd)
				{
					FileSize += tfo.Size;
					FileCount++;

					if (Row < 1000)
					{
						sgResults->Cells[0][Row] = (GScanEngine->Data.Folders[tfo.FilePathIndex] + tfo.Name).c_str();

						sgResults->Cells[1][Row] = Convert::IntDateToString(tfo.DateCreated).c_str();
						sgResults->Cells[2][Row] = Convert::IntDateToString(tfo.DateAccessed).c_str();
						sgResults->Cells[3][Row] = Convert::IntDateToString(tfo.DateModified).c_str();

						if (tfo.Attributes & FILE_ATTRIBUTE_DIRECTORY)
						{
							 sgResults->Cells[4][Row] = GLanguageHandler->Text[kFolder].c_str();
							 sgResults->Cells[5][Row] = L"0";
						}
						else
						{
							 sgResults->Cells[4][Row] = Convert::ConvertToUsefulUnit(tfo.Size).c_str();
							 sgResults->Cells[5][Row] = tfo.Size;
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

	if (Row != 1)
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
		ExportDataCSV(file_name);
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
	// TO DO if (key = #13 && cbAutoRefresh->Checked)
//	{
		bGoClick(NULL);
//	}
}


void TFormFileAges::ExportDataCSV(const std::wstring file_name)
{
/*procedure TfrmFileAges.ExportDataTo(mode : integer; const filename : string);
var
  dt : integer;
  ix, t : integer;
  tfo : TFileObject;
  addto : boolean;
  wp : TextFile;
  s : string;

  procedure WriteCSVObject;
  begin
	if (faDirectory and tfo.Attributes) = faDirectory then begin
	  s := '"' + GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName + '",';
	  s := '"' + GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + '","' + tfo.FileName + '",';

	  s := s + UpperCase(XText[kFolder]) + ',';
	  s := s + '-1' + ',';
	  s := s + '-1' + ',';

	  s := s + Convert::IntDateToString(tfo.FileDateC) + ',';
	  s := s + Convert::IntDateToString(tfo.FileDateA) + ',';
	  s := s + Convert::IntDateToString(tfo.FileDateM) + ',';

	  s := s + UpperCase(XText[kFolder]) + ',';

	  s := s + '99' + ',';

	  s := s + GScanDetails[FDataIndex].Users[tfo.Owner].Name + ',';

	  s := s + Convert::AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly) + ',';
	  s := s + Convert::AttributeToIntAsString(tfo.Attributes, Sysutils.faHidden) + ',';
	  s := s + Convert::AttributeToIntAsString(tfo.Attributes, Sysutils.faSysFile) + ',';
	  s := s + Convert::AttributeToIntAsString(tfo.Attributes, Sysutils.faArchive) + ',';
	  s := s + IntToStr(Convert::BoolToInteger(tfo.Temp)) + ',';

	  s := s + IntToStr(DaysBetween(Now, Convert::IntegerDateToTDate(tfo.FileDateC))) + ',';
	  s := s + IntToStr(DaysBetween(Now, Convert::IntegerDateToTDate(tfo.FileDateA))) + ',';
	  s := s + IntToStr(DaysBetween(Now, Convert::IntegerDateToTDate(tfo.FileDateM)));
	end
	else begin
	  s := '"' + GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.Filename + '",';
	  s := '"' + GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + '","' + tfo.FileName + '",';

	  s := s + '"' + Convert::GetSizeString(0, tfo.FileSize) + '",';
	  s := s + '"' + IntToStr(tfo.FileSize) + '",';
	  s := s + '"' + IntToStr(tfo.FileSizeOnDisk) + '",';

	  s := s + Convert::IntDateToString(tfo.FileDateC) + ',';
	  s := s + Convert::IntDateToString(tfo.FileDateA) + ',';
	  s := s + Convert::IntDateToString(tfo.FileDateM) + ',';

	  s := s + TypeDescriptions[tfo.FileCategory] + ',';

	  s := s + IntToStr(tfo.FileCategory) + ',';

	  s := s + GScanDetails[FDataIndex].Users[tfo.Owner].Name + ',';

	  s := s + Convert::AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly) + ',';
	  s := s + Convert::AttributeToIntAsString(tfo.Attributes, Sysutils.faHidden) + ',';
	  s := s + Convert::AttributeToIntAsString(tfo.Attributes, Sysutils.faSysFile) + ',';
	  s := s + Convert::AttributeToIntAsString(tfo.Attributes, Sysutils.faArchive) + ',';
	  s := s + IntToStr(Convert::BoolToInteger(tfo.Temp)) + ',';

	  s := s + IntToStr(DaysBetween(Now, Convert::IntegerDateToTDate(tfo.FileDateC))) + ',';
	  s := s + IntToStr(DaysBetween(Now, Convert::IntegerDateToTDate(tfo.FileDateA))) + ',';
	  s := s + IntToStr(DaysBetween(Now, Convert::IntegerDateToTDate(tfo.FileDateM)));
	end;

	Writeln(wp, s);
  end;

 begin
  if bGo.Tag <> cbAttribute.ItemIndex then begin
	case cbAttribute.ItemIndex of
	  CAttributeCreated  : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesCreated));
	  CAttributeAccessed : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
	  CAttributeModified : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
	end;

	bGo.Tag := cbAttribute.ItemIndex;
  end;

  ix := StrToIntDef(eCount.Text, 30);

  case mode of
	CModeCSV : begin // CSV
				 AssignFile(wp, Filename);
				{$I-}
				 Rewrite(wp);
				 {$I+}

				 if (IOResult <> 0) then begin
				   TMSLogger.Error('Error writing XML file "' + FileName + '".');
				 end
				 else begin
				   Writeln(wp, XText[kFilePath]                   + ',' +
							   XText[kFolder]                     + ',' +
							   XText[kFileName]                   + ',' +
							   XText[kSize]                       + ',' +
							   XText[kSizeOfFilesBytes]           + ',' +
							   XText[kSizeOnDisk]                 + ',' +
							   XText[kCreatedDate]                + ',' +
							   XText[kAccessedDate]               + ',' +
							   XText[kModifiedDate]               + ',' +
							   XText[kCategory]                   + ',' +
							   XText[kCategory]                   + 'ID' + ',' +
							   XText[kOwner]                      + ',' +
							   LanguageTypes[FileType_ReadOnly]    + ',' +
							   LanguageTypes[FileType_Hidden]      + ',' +
							   LanguageTypes[FileType_System]      + ',' +
							   LanguageTypes[FileType_Archive]     + ',' +
							   XText[kTemporary]                  + ',' +
							   'CreatedAgeFullDays,'               +
							   'AccessedAgeFullDays,'              +
							  'ModifiedAgeFullDays');
				 end;
			   end;
  end;

  // ===========================================================================
  // ===========================================================================

  case cbInterval.ItemIndex of
	CIntervalDay   : dt := Convert::DateToYYYYMMDDI(IncDay(Now,   -ix));        // day
	CIntervalWeek  : dt := Convert::DateToYYYYMMDDI(IncWeek(Now,  -ix));        // week
	CIntervalMonth : dt := Convert::DateToYYYYMMDDI(IncMonth(Now, -ix));        // month
	CIntervalYear  : dt := Convert::DateToYYYYMMDDI(IncMonth(Now, -(12 * ix))); // year
  else
	dt := Convert::DateToYYYYMMDDI(IncDay(Now, -ix));              // day
  end;

  // ===========================================================================
  // ===========================================================================

  case cbFileAgeType.ItemIndex of
	CTypeOlderThan     : begin
						   for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
							 tfo := GScanDetails[FDataIndex].Files[t];

							 addto := False;

							 case cbAttribute.ItemIndex of
							   CAttributeCreated  : if tfo.FileDateC <= dt then addto := True;
							   CAttributeAccessed : if tfo.FileDateA <= dt then addto := True;
							   CAttributeModified : if tfo.FileDateM <= dt then addto := True;
							 end;

							 if addto then begin
								 CModeCSV : begin
											  WriteCSVObject;
											end;
							   end;
							 end;
						   end;
						 end;
	CTypeWithinTheLast : begin
						   for t := GScanDetails[FDataIndex].Files.Count downto 0 do begin
							 tfo := GScanDetails[FDataIndex].Files[t];

							 addto := False;

							 case cbAttribute.ItemIndex of
							   CAttributeCreated  : if tfo.FileDateC >= dt then addto := True;
							   CAttributeAccessed : if tfo.FileDateA >= dt then addto := True;
							   CAttributeModified : if tfo.FileDateM >= dt then addto := True;
							 end;

							 if addto then begin
							   case mode of
								 CModeCSV : begin
											  WriteCSVObject;
											end;
							   end;
							 end;
						   end;
						 end;
  end;

  case mode of
	CModeCSV : CloseFile(wp);
end; */
}


void TFormFileAges::ExportDataXML(const std::wstring file_name)
{
/*  dt : integer;
  ix, t : integer;
  tfo : TFileObject;
  addto : boolean;
  wp : TextFile;
  s : string;

  procedure WriteXMLObject;

   function BoolToString(fish : boolean): String;
	begin
	 if fish then
	   Result := '1'
	 else
	   Result := '0';
   end;

   begin
	Writeln(wp, '    <file>');
	Writeln(wp, TXFormatting.InsertElement('name',                 TXFormatting.ReplaceEntitiesForXML(tfo.FileName), 2));
	Writeln(wp, TXFormatting.InsertElement('path',                 TXFormatting.ReplaceEntitiesForXML(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex]), 2));
	Writeln(wp, TXFormatting.InsertElement('sizewords',            Convert::ConvertToUsefulUnit(tfo.FileSize), 2));
	Writeln(wp, TXFormatting.InsertElement('sizebytes',            IntToStr(tfo.FileSize), 2));
	Writeln(wp, TXFormatting.InsertElement('sizeondiskwords',      Convert::ConvertToUsefulUnit(tfo.FileSizeOnDisk), 2));
	Writeln(wp, TXFormatting.InsertElement('sizeondiskbytes',      IntToStr(tfo.FileSizeOnDisk), 2));
	Writeln(wp, TXFormatting.InsertElement('owner',                GScanDetails[FDataIndex].Users[tfo.Owner].Name, 2));
	Writeln(wp, TXFormatting.InsertElement('datecreated',          Convert::IntDateToString(tfo.FileDateC), 2));
	Writeln(wp, TXFormatting.InsertElement('datemodified',         Convert::IntDateToString(tfo.FileDateM), 2));
	Writeln(wp, TXFormatting.InsertElement('dateaccessed',         Convert::IntDateToString(tfo.FileDateA), 2));
	Writeln(wp, TXFormatting.InsertElement('datecreatedyyyymmdd',  IntToStr(tfo.FileDateC), 2));
	Writeln(wp, TXFormatting.InsertElement('datemodifiedyyyymmdd', IntToStr(tfo.FileDateM), 2));
	Writeln(wp, TXFormatting.InsertElement('dateaccessedyyyymmdd', IntToStr(tfo.FileDateA), 2));
	Writeln(wp, TXFormatting.InsertElement('category',             IntToStr(tfo.FileCategory), 2));
	Writeln(wp, TXFormatting.InsertElement('directory',            Convert::AttributeToIntAsString(tfo.Attributes, faDirectory), 2));
	Writeln(wp, TXFormatting.InsertElement('readonly',             Convert::AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly), 2));
	Writeln(wp, TXFormatting.InsertElement('hidden',               Convert::AttributeToIntAsString(tfo.Attributes, faHidden), 2));
	Writeln(wp, TXFormatting.InsertElement('system',               Convert::AttributeToIntAsString(tfo.Attributes, faSysFile), 2));
	Writeln(wp, TXFormatting.InsertElement('archive',              Convert::AttributeToIntAsString(tfo.Attributes, faArchive), 2));
	Writeln(wp, TXFormatting.InsertElement('temp',                 BoolToString(tfo.Temp), 2));
	Writeln(wp, TXFormatting.InsertElement('createdagefulldays',   IntToStr(DaysBetween(Now, Convert::IntegerDateToTDate(tfo.FileDateC))), 2));
	Writeln(wp, TXFormatting.InsertElement('accessedagefulldays',  IntToStr(DaysBetween(Now, Convert::IntegerDateToTDate(tfo.FileDateA))), 2));
	Writeln(wp, TXFormatting.InsertElement('modifiedagefulldays',  IntToStr(DaysBetween(Now, Convert::IntegerDateToTDate(tfo.FileDateM))), 2));
	Writeln(wp, '    </file>');
  end;

 begin
  if bGo.Tag <> cbAttribute.ItemIndex then begin
	case cbAttribute.ItemIndex of
	  CAttributeCreated  : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesCreated));
	  CAttributeAccessed : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
	  CAttributeModified : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
	end;

	bGo.Tag := cbAttribute.ItemIndex;
  end;

  ix := StrToIntDef(eCount.Text, 30);

	CModeXML : begin
				 AssignFile(wp, Filename);
				 {$I-}
				 Rewrite(wp);
				 {$I+}

				 if (IOResult <> 0) then begin
				   TMSLogger.Error('Error writing XML file "' + FileName + '".');
				 end
				 else begin
				   Writeln(wp, '<?xml version="1.0"?>');
				   Writeln(wp, '<!-- generated with Xinorbis ' + x8Title + ' - ' + x8Date + ' -->');
				   Writeln(wp, '<!-- http://xinorbis.com - Paul A Freshney ' + TUtility.GetCurrentYear + ' -->');
				   Writeln(wp, '<!-- File Age: ' + cbAttribute.Text + ', ' + cbFileAgeType.Text + ', ' + eCount.Text + ', ' + cbInterval.Text + ' -->');
				   Writeln(wp, '<xinorbisfilelist>');
				 end;
			   end;
  end;

  // ===========================================================================
  // ===========================================================================

  case cbInterval.ItemIndex of
	CIntervalDay   : dt := Convert::DateToYYYYMMDDI(IncDay(Now,   -ix));        // day
	CIntervalWeek  : dt := Convert::DateToYYYYMMDDI(IncWeek(Now,  -ix));        // week
	CIntervalMonth : dt := Convert::DateToYYYYMMDDI(IncMonth(Now, -ix));        // month
	CIntervalYear  : dt := Convert::DateToYYYYMMDDI(IncMonth(Now, -(12 * ix))); // year
  else
	dt := Convert::DateToYYYYMMDDI(IncDay(Now, -ix));              // day
  end;

  // ===========================================================================
  // ===========================================================================

  case cbFileAgeType.ItemIndex of
	CTypeOlderThan     : begin
						   for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
							 tfo := GScanDetails[FDataIndex].Files[t];

							 addto := False;

							 case cbAttribute.ItemIndex of
							   CAttributeCreated  : if tfo.FileDateC <= dt then addto := True;
							   CAttributeAccessed : if tfo.FileDateA <= dt then addto := True;
							   CAttributeModified : if tfo.FileDateM <= dt then addto := True;
							 end;

							 if addto then begin
								 CModeXML : begin
											  WriteXMLObject;
											end;
							   end;
							 end;
						   end;
						 end;
	CTypeWithinTheLast : begin
						   for t := GScanDetails[FDataIndex].Files.Count downto 0 do begin
							 tfo := GScanDetails[FDataIndex].Files[t];

							 addto := False;

							 case cbAttribute.ItemIndex of
							   CAttributeCreated  : if tfo.FileDateC >= dt then addto := True;
							   CAttributeAccessed : if tfo.FileDateA >= dt then addto := True;
							   CAttributeModified : if tfo.FileDateM >= dt then addto := True;
							 end;

							 if addto then begin
								 CModeXML : begin
											  WriteXMLObject;
											end;
							   end;
							 end;
						   end;
						 end;
  end;

	CModeXML : begin
				 Writeln(wp, '</xinorbisfilelist>');

				 CloseFile(wp);

end; */
}
