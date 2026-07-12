//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormImportFromCSV.h"

#include "ConstantsReports.h"
#include "LanguageHandler.h"
#include "Utility.h"

extern LanguageHandler* GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormImportCSV *FormImportCSV;
//---------------------------------------------------------------------------
__fastcall TFormImportCSV::TFormImportCSV(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TFormImportCSV::FormCreate(TObject *Sender)
{
	LabelList[0]  = lContents1;  LabelList[1]  = lContents2;  LabelList[2]  = lContents3;  LabelList[3]  = lContents4;  LabelList[4]  = lContents5;
	LabelList[5]  = lContents6;  LabelList[6]  = lContents7;  LabelList[7]  = lContents8;  LabelList[8]  = lContents9;  LabelList[9]  = lContents10;
	LabelList[10] = lContents11; LabelList[11] = lContents12; LabelList[12] = lContents13; LabelList[13] = lContents14; LabelList[14] = lContents15;
	LabelList[15] = lContents16; LabelList[16] = lContents17; LabelList[17] = lContents18; LabelList[18] = lContents19; LabelList[19] = lContents20;

	ComboList[0]  = cbType1;  ComboList[1]  = cbType2;  ComboList[2]  = cbType3;  ComboList[3]  = cbType4;
	ComboList[4]  = cbType5;  ComboList[5]  = cbType6;  ComboList[6]  = cbType7;  ComboList[7]  = cbType8;
	ComboList[8]  = cbType9;  ComboList[9]  = cbType10; ComboList[10] = cbType11; ComboList[11] = cbType12;
	ComboList[12] = cbType13; ComboList[13] = cbType14; ComboList[14] = cbType15; ComboList[15] = cbType16;
	ComboList[16] = cbType17; ComboList[17] = cbType18; ComboList[18] = cbType19; ComboList[19] = cbType20;
}


void __fastcall TFormImportCSV::FormShow(TObject *Sender)
{
	lFileName->Caption = FileName.c_str();

	ProcessSuccessful = ProcessFile();
}


void TFormImportCSV::Init()
{
	Caption = GLanguageHandler->Text[kImportCSVData].c_str();

	lFieldDataType->Caption = GLanguageHandler->Text[kFieldDataType].c_str();
	lContentsFirstRecord->Caption = GLanguageHandler->Text[kContentsFirstRecord].c_str();
	lFileName->Caption = GLanguageHandler->Text[kFileName].c_str();

	for (int x = 0; x < 20; x++)
	{
		ComboList[x]->Items->Add(GLanguageHandler->Text[kIgnore].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kFullFilePath].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kFileSizeBytes].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kFileSizeOnDisk].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kCreatedDateDDMMYYYY].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kCreatedDateMMDDYYYY].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kModifiedDateDDMMYYYY].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kModifiedDateMMDDYYYY].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kAccessedDateDDMMYYYY].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kAccessedDateMMDDYYYY].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kFilePath].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kFileName].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kOwner].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kCategory].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kReadOnly].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kHidden].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kSystem].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kArchive].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kTemporary].c_str());
		ComboList[x]->Items->Add(GLanguageHandler->Text[kFileAttributes].c_str());
		ComboList[x]->Items->Add((GLanguageHandler->Text[kCreated] + L" " + GLanguageHandler->Text[kTime] + L" (HHMM)").c_str());
		ComboList[x]->Items->Add((GLanguageHandler->Text[kAccessed] + L" " + GLanguageHandler->Text[kTime] + L" (HHMM)").c_str());
		ComboList[x]->Items->Add((GLanguageHandler->Text[kModified] + L" " + GLanguageHandler->Text[kTime] + L" (HHMM)").c_str());
	}

	  cbIFR->Caption   = GLanguageHandler->Text[kIgnoreFirstRecord].c_str();
	  bHelp->Caption   = GLanguageHandler->Text[kHelp].c_str();
	  bImport->Caption = GLanguageHandler->Text[kImport].c_str();
	  bCancel->Caption = GLanguageHandler->Text[kCancel].c_str();

	for (int t = 0; t < 20; t++)
	{
		LabelList[t]->Caption = L"";
		LabelList[t]->Visible = false;
		ComboList[t]->ItemIndex = 0;
	}
}


void __fastcall TFormImportCSV::cbType1Change(TObject *Sender)
{
	TComboBox* cb = (TComboBox*)Sender;

	switch (cb->ItemIndex)
	{
	case 2:
	case 3:
	case 13:
		if (Utility::IsNumber(LabelList[cb->ItemIndex]->Caption.c_str()))
		{
			cbIFR->Checked = true;
		}
		break;
	}
}


CSVDataFormat TFormImportCSV::GetImportInstructions()
{
	CSVDataFormat csvdf;

	csvdf.IsDataValid = ProcessSuccessful;

	if (csvdf.IsDataValid)
	{
		for (int t = 0; t < 20; t++)
		{
			csvdf.Fields[t] = ComboList[t]->ItemIndex;
		}

		csvdf.IgnoreFirstRecord = cbIFR->Checked;
	}
}


void __fastcall TFormImportCSV::bAutoClick(TObject *Sender)
{
	cbType1->ItemIndex  = kFieldFileName;
	cbType2->ItemIndex  = kFieldFullFilePath;
	cbType3->ItemIndex  = kFieldIgnore;
	cbType4->ItemIndex  = kFieldFileSizeBytes;
	cbType5->ItemIndex  = kFieldFileSizeOnDIsk;
	cbType6->ItemIndex  = kFieldCreatedDDMMYYYY;
	cbType7->ItemIndex  = kFieldModifiedDDMMYYYY;
	cbType8->ItemIndex  = kFieldAccessedDDMMYYYY;
	cbType9->ItemIndex  = kFieldCreatedTimeHHMMSS;
	cbType10->ItemIndex = kFieldModifiedTimeHHMMSS;
	cbType11->ItemIndex = kFieldAccessedTimeHHMMSS;
	cbType12->ItemIndex = kFieldIgnore;
	cbType13->ItemIndex = kFieldCategory;
	cbType14->ItemIndex = kFieldOwner;
	cbType15->ItemIndex = kFieldReadOnly;
	cbType16->ItemIndex = kFieldHidden;
	cbType17->ItemIndex = kFieldSystem;
	cbType18->ItemIndex = kFieldArchive;
	cbType19->ItemIndex = kFieldTemp;

	if (FieldCount == 20)
	{
		cbType20->ItemIndex = kFieldAttributes;
	}
	else
	{
		cbType20->ItemIndex = kFieldIgnore;
	}

	cbType1Change(cbType2);
	cbType1Change(cbType3);
	cbType1Change(cbType9);
}


void __fastcall TFormImportCSV::bHelpClick(TObject *Sender)
{
	// to do THelp.OpenHelpPage('w21.htm');
}


bool TFormImportCSV::ProcessFile()
{ /*
 var
  tf : TextFile;
  s,r : string;
  t,i : integer;
  inquotes, processthisfield : boolean;


	if (!ReadTopTwoLines())
	{
		return;
	}

	FieldCount = GetFieldCount(s);

    r                = '';
    i                = 0;
    inquotes         = False;
    processthisfield = False;

    for t = 1 to length(s) do begin

      case s[t] of
		'"' : begin
                if inquotes then begin
                  case s[t + 1] of
					',' : inquotes = False;
                  else
                    r = r + s[t];
                  end;
                end
                else
                  inquotes = not(inquotes);
              end;
        ',' : begin
                if not(inquotes) then
                  processthisfield = True;
              end;
      else
        r = r + s[t];
      end;

      if processthisfield then begin
        if i <= MaxCSVFields then begin
          LabelList[i]->Caption = r;
          LabelList[i].Visible = True;
          ComboList[i].Visible = True;
        end;

        processthisfield = False;

        r = '';

        inc(i);
      end;
    end;

    if i <= MaxCSVFields then begin
      LabelList[i]->Caption = r;
	  LabelList[i].Visible = True;
      ComboList[i].Visible = True;
    end;
  end
  else
	ShowXDialog(GLanguageHandler->Text[kWarning], GLanguageHandler->Text[kBadCSVFile], XDialogTypeWarning); */

	return false;
}


bool TFormImportCSV::ReadTopTwoLines()
{
	return false;
}


int TFormImportCSV::GetFieldCount(const std::wstring row)
{
	int count = 0;
/*
  t : integer;
  count : integer;
  inString : boolean;

begin
  count    = 1;
  inString = False;

  for t = 1 to length(aRow) do begin
	if aRow[t] = '"' then begin
	  if inString then
		inString = False
	  else
		inString = True;
	end
	else if aRow[t] = ',' then begin
	  if not(inString) then
		inc(count);
	end;
  end;

  Result = count;  */

	return count;
}
