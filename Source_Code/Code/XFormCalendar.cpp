//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <System.DateUtils.hpp>

#include "XFormCalendar.h"

#include "Convert.h"
#include "LanguageHandler.h"

extern LanguageHandler *GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm21 *Form21;
//---------------------------------------------------------------------------
__fastcall TForm21::TForm21(TComponent* Owner)
	: TForm(Owner)
{
}


std::wstring OpenCalendar(const std::vector<std::wstring> &data)
{
	Form21 = new TForm21(Application);

	for (int t = 0; t < data.size(); t++)
	{
		Form21->Add(data[t]);
	}

	std::wstring selection = L"";

	if (Form21->ShowModal() == mrOk)
	{
		selection = Form21->SelectedDateTime;
	}

	delete Form21;

	return selection;
}


void __fastcall TForm21::FormCreate(TObject *Sender)
{
	Init();
}


void __fastcall TForm21::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}


void TForm21::Init()
{
	Caption = GLanguageHandler->Text[kFolderHistory].c_str();
	bCancel->Caption = GLanguageHandler->Text[kCancel].c_str();
	lAvailableTimes->Caption = GLanguageHandler->Text[kAvailableTimes].c_str();

	for (int mm = 0; mm < 37; mm++)
	{
		std::wstring day = L"";

		day += GLanguageHandler->Text[kDayInitials][mm % 7];

		sgCalendar->Cells[mm + 1][0] = day.c_str();

		sgCalendar->ColWidths[mm] = ColWidths[mm];
	}

	lTitle->Caption = GLanguageHandler->Text[kAvailableFolderHistoryScans].c_str();

	Label1->Caption = (L"1 " + GLanguageHandler->Text[kScan]).c_str();
	Label2->Caption = (L"2 " + GLanguageHandler->Text[kScans]).c_str();
	Label3->Caption = (L"3 " + GLanguageHandler->Text[kScans]).c_str();
	Label4->Caption = (L"4 " + GLanguageHandler->Text[kScans]).c_str();
	Label5->Caption = (L"5+ " + GLanguageHandler->Text[kScans]).c_str();

	Shape1->Brush->Color = TColor(kGridColours[0]);
	Shape2->Brush->Color = TColor(kGridColours[1]);
	Shape3->Brush->Color = TColor(kGridColours[2]);
	Shape4->Brush->Color = TColor(kGridColours[3]);
	Shape5->Brush->Color = TColor(kGridColours[4]);

	cbExcludeEmpty->Caption = GLanguageHandler->Text[kExcludeEmpty].c_str();

	int last_year = GetLastYear();

	seYear->Value = last_year;

	BuildDate(last_year);
}


void TForm21::Add(const std::wstring s)
{
	FileHistoryInput.push_back(s);
}


void __fastcall TForm21::seYearEnter(TObject *Sender)
{
	OldText = seYear->Text.c_str();
}


void __fastcall TForm21::seYearExit(TObject *Sender)
{
	int value = StrToIntDef(seYear->Text, -1);

	if (value == -1)
	{
		seYear->Text = OldText.c_str();
	}
}

void __fastcall TForm21::seYearChange(TObject *Sender)
{
	BuildDate(seYear->Value);
}


void __fastcall TForm21::cbTimesClick(TObject *Sender)
{
	if (cbTimes->ItemIndex >= 0)
	{
//		std::wstring s = cbTimes->Items->Strings[cbTimes->ItemIndex].c_str();
//
//		SelectedDateTime  := SelectedDate + s.substr(0, 2) + s.substr(3, 2) + s.substr(6, 2);

//	lSelected.Caption := Convert::IntDateToString(StrToInt(SelectedDate)) + ' ' + s;

		bUse->Enabled = true;
	}
}


void __fastcall TForm21::sgCalendarSelectCell(TObject *Sender, System::LongInt ACol,
          System::LongInt ARow, bool &CanSelect)
{                /*
  temp : string;
  t : integer;

begin
  SelectedDate      := '';

  lSelected.Caption := '';
  bUse.Enabled      := False;
  cbTimes.Clear;

  if (ARow > 1) and (ACol > 1) then begin
    if sgCalendar.Cells[ACol, ARow] <> '' then begin
      SelectedDate := IntToStr(SpinEdit1.Value);

      if ARow < 10 then
        SelectedDate := SelectedDate + '0' + IntToStr(ARow)
      else
        SelectedDate := SelectedDate + IntToStr(ARow);

      if StrToInt(sgCalendar.Cells[ACol, ARow]) < 10 then
        SelectedDate := SelectedDate + '0' + sgCalendar.Cells[ACol, ARow]
      else
        SelectedDate := SelectedDate+sgCalendar.Cells[ACol, ARow];

      temp := TConvert.IntDateToString(StrToInt(SelectedDate));

      for t := 0 to FileHistoryInput.Count - 1 do begin
        if Pos(temp, FileHistoryInput[t]) <> 0 then begin
          cbTimes.Items.Add(Copy(FileHistoryInput[t], 12, 8));
        end;
      end;

      if cbTimes.Count = 1 then begin
        cbTimes.ItemIndex := 0;

        cbTimesClick(Nil);
      end;
    end
    else begin
    end;
  end
  else begin
  end;*/
}


void __fastcall TForm21::sgCalendarDrawCell(TObject *Sender, System::LongInt ACol,
          System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	if (ARow > 0 && ACol > 0)
	{
		if (FileHistoryData[ACol][ARow] != -1)
		{
			sgCalendar->Canvas->Brush->Color = TColor(kGridColours[FileHistoryData[ACol][ARow]]);
			sgCalendar->Canvas->FillRect(Rect);
			sgCalendar->Canvas->TextOut(Rect.Left + 5, Rect.Top + 2, sgCalendar->Cells[ACol][ARow]);
		}
	}
}


int TForm21::GetLastYear()
{
	int year = 1990;

	for (int t = 0; t < FileHistoryInput.size(); t++)
	{
		std::wstring date = Convert::DateTimeFToYYYYMMDD(FileHistoryInput[t]);

		int yyyy = stoi(date.substr(0, 4));

		if (yyyy > year)
		{
			year = yyyy;
		}
	}

	return year;
}


void TForm21::BuildDate(int year)
{
  // ===========================================================================
  // == Build FileHistory array ================================================
  // ===========================================================================

	for (int t = 0; t < 37; t++)
	{
		for (int z = 0; z < 12; z++)
		{
			switch (t)
			{
			case 5:
			case 6:
			case 12:
			case 13:
			case 19:
			case 20:
			case 26:
			case 27:
			case 33:
			case 34:
				FileHistoryData[t][z] = 0;
				break;

			default:
				FileHistoryData[t][z] = -1;
			}
		}
	}

	for (int t = 0; t < FileHistoryInput.size(); t++)
	{
		std::wstring xdate = Convert::DateTimeFToYYYYMMDD(FileHistoryInput[t]);

		int cyy = stoi(xdate.substr(0, 4));

		if (cyy = year)
		{
			int cmm = stoi(xdate.substr(4, 2));
			int cdd = stoi(xdate.substr(6, 2));

			TDateTime dt = EncodeDate(cyy, cmm, 1);
			int z = DayOfTheWeek(dt);

			if (FileHistoryData[(cdd + z) - 1][cmm] <= 0)
			{
				FileHistoryData[(cdd + z) - 1][cmm] = 1;
			}
			else
			{
				if (FileHistoryData[(cdd + z) - 1][cmm] < 5)
				{
					FileHistoryData[(cdd + z) - 1][cmm] = FileHistoryData[(cdd + z) - 1][cmm] + 1;
				}
			}
		}
	}

	// ===========================================================================
	// ===========================================================================

	sgCalendar->BeginUpdate();

//	sgCalendar->ClearRows(1, 12);

	for (int t = 0; t < 12; t++)
	{
		sgCalendar->Cells[0][t] = GLanguageHandler->Months[t].c_str();

		TDateTime dt = EncodeDate(year, t, 1);

		int z  = DayOfTheWeek(dt);

		for (int i = 0; i < DaysInAMonth(year, t); i++)
		{
			sgCalendar->Cells[i + z][t] = IntToStr(i);
		}
	}

	sgCalendar->EndUpdate();
}

