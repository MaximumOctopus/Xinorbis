//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormFileSpread.h"
#include "XFormXinorbisDialog.h"

#include "ChartUtility.h"
#include "ConstantsReports.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"

extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormFileSpread *FormFileSpread;
//---------------------------------------------------------------------------
__fastcall TFormFileSpread::TFormFileSpread(TComponent* Owner)
	: TForm(Owner)
{
	Init();
}


//    FULSP : TUpdateLeftStatusPanel;

//	procedure SetTheme;
//  public
//    property OnHide : TUpdateLeftStatusPanel read FULSP write FULSP;
//  end;


//procedure DoSpread(whichDataIndex : integer);
// begin
//  frmSpread.FDataIndex := whichDataIndex;

//  frmSpread.Show;
//end;


void __fastcall TFormFileSpread::FormShow(TObject *Sender)
{
	gbUsers->Caption = GLanguageHandler->Text[kUsers].c_str();

	cbUsers->Items->Clear();
	cbUsers->Items->Add(GLanguageHandler->Text[kAll].c_str());

	for (int t = 0; t < GScanEngine->Data.Users.size(); t++)
	{
		cbUsers->Items->Add(GScanEngine->Data.Users[t].Name.c_str());
	}

	cbUsers->ItemIndex = 0;

	//

	LargestFileSize = 0;

	if (GScanEngine->Data.Files.size() == 0)
	{
		sbShow->Enabled = false;
	}
	else
	{
		for (int t = 0; t < GScanEngine->Data.Files.size(); t++)
		{
			if (GScanEngine->Data.Files[t].Size > LargestFileSize)
			{
				LargestFileSize = GScanEngine->Data.Files[t].Size;
			}
		}
    }
}


void __fastcall TFormFileSpread::FormConstrainedResize(TObject *Sender, int &MinWidth,
		  int &MinHeight, int &MaxWidth, int &MaxHeight)
{
	MinHeight = 511;
	MinWidth = 600;
}


void __fastcall TFormFileSpread::FormClose(TObject *Sender, TCloseAction &Action)

{
//	FormDetails fd(_FormFileSpread, Left, Right, Width, Height); TO DO

//  	XSettings.SaveFormDetails(fd);

//	 if Assigned(FULSP) then
//	FULSP(_FormFileSpread);

	Action = caHide;
}


void TFormFileSpread::Init()
{
	cbResolutionUnits->Items->Clear();
	cbRangeFromUnits->Items->Clear();
	cbRangeToUnits->Items->Clear();

	cbResolutionUnits->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbResolutionUnits->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbResolutionUnits->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbResolutionUnits->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());
	cbRangeFromUnits->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbRangeFromUnits->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbRangeFromUnits->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbRangeFromUnits->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());
	cbRangeToUnits->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbRangeToUnits->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbRangeToUnits->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbRangeToUnits->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());

	cbResolutionUnits->ItemIndex = kUnitKilobytes;
	cbRangeFromUnits->ItemIndex = kUnitKilobytes;
	cbRangeToUnits->ItemIndex = kUnitKilobytes;

	// =========================================================================

	Caption                       = GLanguageHandler->Text[kFileSizeSpread].c_str();

	tsFileSize->Caption           = GLanguageHandler->Text[kFileSize].c_str();
	lBGR->Caption                 = GLanguageHandler->Text[kBarGraphResolution].c_str();
	cbRange->Caption              = GLanguageHandler->Text[kRange].c_str();

	cbNormalDistribution->Caption = GLanguageHandler->Text[kNormalDistribution].c_str();
	sbMoreDetail->Caption         = GLanguageHandler->Text[kMoreDetail].c_str();

	gbChart->Caption              = GLanguageHandler->Text[kChart].c_str();
	rbMulticoloured->Caption      = GLanguageHandler->Text[kMultiColoured].c_str();
	rbGradient->Caption           = GLanguageHandler->Text[kGradient].c_str();
	cbLogarithmic->Caption        = GLanguageHandler->Text[kLogarthmic].c_str();
	sbShow->Caption               = GLanguageHandler->Text[kShow].c_str();
	sbHelp->Caption               = GLanguageHandler->Text[kHelp].c_str();
	cbAutoRefresh->Caption        = GLanguageHandler->Text[kAutoRefresh].c_str();

	miOptions->Caption            = GLanguageHandler->Text[kChartOptions].c_str();
	miSaveChart->Caption          = GLanguageHandler->Text[kSaveChart].c_str();
	miCopyToClipboard->Caption    = GLanguageHandler->Text[kCopyChartToClipboard].c_str();
	miSaveData->Caption           = GLanguageHandler->Text[kSaveData].c_str();

	// =========================================================================

//	FormDetails fd = XSettings.LoadFormDetails(_FormFileSpread); TO DO

//	if (fd.FormId != -1)
//	{
//		Left   = fd.X;
//		Top    = fd.Y;
//		Width  = fd.Width;
//		Height = fd.Height;
//	}
}


void __fastcall TFormFileSpread::cbLogarithmicClick(TObject *Sender)
{
	if (cbLogarithmic->Checked)
	{
		vtcSpread->LeftAxis->Logarithmic = true;
	}
	else
	{
		vtcSpread->LeftAxis->Logarithmic = false;
	}
}


void __fastcall TFormFileSpread::sbShowClick(TObject *Sender)
{
	if (GScanEngine->Data.Files.size() != 0)
	{
		pBottom->Caption = GLanguageHandler->Text[kPleaseWait].c_str();
		pBottom->Refresh();

		if (pcFileSpread->ActivePageIndex == 0)
		{
			BuildFileSpread();
		}
		else
		{
			BuildBenfordsLaw();
		}

		pBottom->Caption = L"";
	}
}


void __fastcall TFormFileSpread::sbHelpClick(TObject *Sender)
{
	//THelp.OpenHelpPage('a11.htm');
}


void __fastcall TFormFileSpread::sbCSVReportClick(TObject *Sender)
{
	std::wstring FileName = L"";// to do TXSaveDialog.Execute(GLanguageHandler->Text[kCSVFiles] + ' (*.csv)|*.csv',
//									'.csv',
//									TUtility.GetDefaultFileName('.csv', GLanguageHandler->Text[kFileSizeSpread] + '_' + GLanguageHandler->Text[kReport]),
//									GSystemGlobal.AppDataPath);

	if (FileName != L"")
	{
		ExportData(FileName);
	}
}


void TFormFileSpread::BuildFileSpread()
{
	unsigned __int64 RangeFrom = -1;
	unsigned __int64 RangeTo = -1;

	Screen->Cursor = crHourGlass;

	vtcSpread->SeriesList->Items[1]->Active = false;
	vtcSpread->BottomAxis->Visible = false;
	vtcSpread->LeftAxis->Title->Caption = GLanguageHandler->Text[kQuantity].c_str();

	if (cbRange->Checked)
	{
		switch (cbRangeFromUnits->ItemIndex)
		{
		case kUnitBytes:
			RangeFrom = StrToInt64(eRangeFrom->Text);
			break;
		case kUnitKilobytes:
			RangeFrom = StrToInt64(eRangeFrom->Text) * 1024;
			break;
		case kUnitMegabytes:
			RangeFrom = StrToInt64(eRangeFrom->Text) * 1024 * 1024;
			break;
		case kUnitGigabytes:
			RangeFrom = StrToInt64(eRangeFrom->Text) * 1024 * 1024 * 1024;
			break;
		}

		switch (cbRangeToUnits->ItemIndex)
		{
		case kUnitBytes:
			RangeTo = StrToInt64(eRangeTo->Text);
			break;
		case kUnitKilobytes:
			RangeTo = StrToInt64(eRangeTo->Text) * 1024;
			break;
		case kUnitMegabytes:
			RangeTo = StrToInt64(eRangeTo->Text) * 1024 * 1024;
			break;
		case kUnitGigabytes:
			RangeTo = StrToInt64(eRangeTo->Text) * 1024 * 1024 * 1024;
			break;
		}

		if (RangeTo == -1 || RangeFrom == -1)
		{
			ShowXDialog(L"Error: BuildFileSpread",
						L"Error: BuildFileSpread",
						XDialogTypeWarning);
		}
	}

	// =====================================================================
	// =====================================================================

	switch (cbResolutionUnits->ItemIndex)
	{
	case kUnitBytes:
		SX    = std::floor(LargestFileSize / StrToInt(eResolution->Text));
		Coeff = StrToInt64(eResolution->Text);
		break;
	case kUnitKilobytes:
		SX    = std::floor(LargestFileSize / ((StrToInt(eResolution->Text) * 1024)));
		Coeff = StrToInt64(eResolution->Text) * 1024;
		break;
	case kUnitMegabytes:
		SX    = std::floor(LargestFileSize / (StrToInt(eResolution->Text) * 1024 * 1024));
		Coeff = StrToInt64(eResolution->Text) * 1024 * 1024;
		break;
	case kUnitGigabytes:
		SX    = std::floor(LargestFileSize / (StrToInt64(eResolution->Text) * 1024 * 1024 * 1024));
		Coeff = StrToInt64(eResolution->Text) * 1024 * 1024 * 1024;
		break;
	}

	SX++;

	Spread = new int[SX];

	for (int t = 0; t < SX; t++)
	{
		Spread[t] = 0;
	}

	if (cbUsers->ItemIndex == 0) // optimised for all users
	{
		for (int t = 0; t < GScanEngine->Data.Files.size(); t++)
		{
			if (!(GScanEngine->Data.Files[t].Attributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				int box = std::floor(GScanEngine->Data.Files[t].Size / Coeff);

				Spread[box]++;
			}
		}
	}
	else
	{
/*	    int UserUId := TUtility.FindUserIndex(FDataIndex, cbUsers.Items[cbUsers.ItemIndex]);

		for t := 0 to GScanEngine[FDataIndex].Files.Count - 1)
		{
			xfo := GScanEngine[FDataIndex].Files.Items[t];

			if (faDirectory and xfo.Attributes) <> faDirectory)
			{
				if (xfo.owner = userid)
				{
					x := Floor(xfo.FileSize / Coeff);

					Spread[x]++;
				}
			}
		} */
	}

	int MaxHit = 0;

	for (int t = 0; t < SX; t++)
	{
		if (Spread[t] > MaxHit)
		{
			MaxHit = Spread[t];
        }
	}

	// =====================================================================
	// =====================================================================

	vtcSpread->SeriesList->Items[0]->Clear();

	for (int t = 0; t < SX; t++)
	{
		bool CanAdd = true;

		if (cbRange->Checked)
		{
			if (Coeff * t >= RangeFrom && Coeff * t <= RangeTo)
			{
				CanAdd = true;
			}
			else
			{
				CanAdd = false;
			}
		}

		if (CanAdd)
		{
			int colx = 0;

			if (rbGradient->Checked)
			{
				colx = std::round((Spread[t] / MaxHit) * 255);

				if (colx < 0) colx = 0;
				if (colx > 255) colx = 255;

				colx = 0xFFFFFF - ((colx * 65536) + (colx * 256) + colx);
			}
			else
			{
				//colx := spectrumcolours[t mod spectrummod];
			}

			if (Spread[t] != 0)
			{
				vtcSpread->SeriesList->Items[0]->Add(Spread[t], L"", TColor(colx));
			}
			else
			{
				vtcSpread->SeriesList->Items[0]->Add(Spread[t], L"", TColor(0x00ffffff));
			}
		}
	}

	Screen->Cursor = crDefault;
}


void TFormFileSpread::BuildBenfordsLaw()
{
	Screen->Cursor = crHourGlass;

	vtcSpread->SeriesList->Items[1]->Active = cbLogarithmic->Checked;
	vtcSpread->BottomAxis->Visible = true;
	vtcSpread->LeftAxis->Title->Caption = L"%";

	for (int t = 0; t < 9; t++)
	{
		BenfordBoxes[t] = 0;
	}

	int jf = 0;

	for (int t = 0; t < GScanEngine->Data.Files.size(); t++)
	{
		FileObject xfo = GScanEngine->Data.Files[t];

		if (!(faDirectory & xfo.Attributes))
		{
			if (xfo.Size != 0)
			{
				int i = std::to_wstring(GScanEngine->Data.Files[t].Size)[0] - 48;

				BenfordBoxes[i]++;

				jf++;
			}
		}
	}

	vtcSpread->SeriesList->Items[0]->Clear();
	vtcSpread->SeriesList->Items[1]->Clear();

	for (int t = 0; t < 9; t++)
	{
		double zig = 0;

		if (jf != 0)
		{
			zig = (BenfordBoxes[t] / jf) * 100;
		}

		vtcSpread->SeriesList->Items[0]->Add(zig, std::to_wstring(t + 1).c_str(), TColor(__SpectrumColours[t % __SpectrumMod]));

//		if (cbNormalDistribution->Checked)
//		{
//			zig = (log10(t + 1) - log10(t)) * 100;

//			vtcSpread->SeriesList->Items[1]->Add(zig, std::to_wstring(t + 1), TColor(0xD6D5DB));
//		}
	}

	Screen->Cursor = crDefault;
}


void __fastcall TFormFileSpread::vtcSpreadMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
   int ValueIndex = vtcSpread->SeriesList->Items[0]->GetCursorValueIndex();

	if (vtcSpread->SeriesList->Items[0]->Active)
	{
		if (ValueIndex == -1)
		{
			ValueIndex = vtcSpread->SeriesList->Items[1]->GetCursorValueIndex();
		}
	}

	if (ValueIndex > -1)
	{
		if (pcFileSpread->ActivePageIndex == 0)
		{
			std::wstring s = Convert::ConvertToUsefulUnit(ValueIndex * Coeff) + L" -> " + Convert::ConvertToUsefulUnit((ValueIndex * Coeff) + Coeff) + L" ( " +
							 std::to_wstring(vtcSpread->SeriesList->Items[0]->YValue[ValueIndex]) + L" )";

			pBottom->Caption = s.c_str();
		}
		else
		{
//		  pBottom->Caption = L"\"" + IntToStr(ValueIndex + 1) +
//								 '" <b>' + FloatToStrF(vtcSpread.SeriesList[0].YValue[ValueIndex], ffFixed, 7, 2, XinorbisFormatSettings) + '%</b> (' +
//								 IntToStr(benford[ValueIndex + 1]) + ' ' + GLanguageHandler->Text[kFiles] + ')  (normal distribution: ' + nd[ValueIndex + 1] + '%)';
		}
	}
	else
	{
		pBottom->Caption = L"n/a";
	}
}


void __fastcall TFormFileSpread::eResolutionEnter(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	OldText = edit->Text.c_str();
}


void __fastcall TFormFileSpread::eResolutionExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int value = edit->Text.ToIntDef(-1);

	if (value == -1)
	{
		edit->Text = OldText.c_str();
	}
}


void __fastcall TFormFileSpread::eResolutionKeyPress(TObject *Sender, System::WideChar &Key)

{
//	if (Key = #13) and (TEdit(Sender).Text <> '') TO DO
//	{
		if (cbAutoRefresh->Checked)
		{
			sbShowClick(NULL);
		}
//	}
}


void __fastcall TFormFileSpread::miSaveChartClick(TObject *Sender)
{
/*  lFileName := TXSaveDialog.Execute(GLanguageHandler->Text[kPNGFiles] + ' (*.png)|*.png',
									'.png',
									TUtility.GetDefaultFileName('.png', GLanguageHandler->Text[kFileSizeSpread]),
									GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
	mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

	TChartUtility.SaveChartToPNG(mychart, lFileName);
  end;
end; */
}


void __fastcall TFormFileSpread::miCopyToClipboardClick(TObject *Sender)
{
//  	TChart *chart = TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

	ChartUtility::CopyChartToClipboard(vtcSpread);
}


void __fastcall TFormFileSpread::miSaveDataClick(TObject *Sender)
{
/*  lFileName := TXSaveDialog.Execute(GLanguageHandler->Text[kTextFiles] + ' (*.txt)|*.txt',
									'.txt',
                                    TUtility.GetDefaultFileName('.txt', GLanguageHandler->Text[kFileSizeSpread] + '_' + GLanguageHandler->Text[kReport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
	AssignFile(tf, lFileName);

	{$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(GLanguageHandler->Text[kWarning],
                  GLanguageHandler->Text[kErrorSaving] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      for t := 0 to sx do begin
		Writeln(tf,GScanEngine[FDataIndex].ScanPath);
		Writeln(tf, GLanguageHandler->Text[kCreated] + ': ' + TUtility.GetTime(GETTIMEFORMAT_DISPLAY) + ' ' + TUtility.GetDate(GETTIMEFORMAT_DISPLAY));
        Writeln(tf, '');
		Writeln(tf, GLanguageHandler->Text[kInterval] + ': ' + eResolution->Text + ' ' + cbUnit.Text);
        Writeln(tf, '');

        if cbRange.Checked then begin
          Writeln(tf, GLanguageHandler->Text[kRange] + ' : ' + eRangeFrom.Text + ' ' + cbRangeFrom.Text);
          Writeln(tf, TXFormatting.AddLeading('', Length(GLanguageHandler->Text[kRange]) + 3, ' ') + eRangeTo.Text + ' ' + cbRangeTo.Text);
          Writeln(tf, '');
        end;

        Writeln(tf, TXFormatting.AddLeading(IntToStr(spread[t]), 7, ' ') + ' : ' + TConvert.ConvertToUsefulUnit(t * coeff) + ' <= x < ' + TConvert.ConvertToUsefulUnit((t * coeff) + coeff - 1));
      end;

      CloseFile(tf);
	end;
	{$I+}
  end; */
}


void __fastcall TFormFileSpread::rbMulticolouredClick(TObject *Sender)
{
	if (cbAutoRefresh->Checked)
	{
		sbShowClick(NULL);
	}
}


void __fastcall TFormFileSpread::pcFileSpreadChange(TObject *Sender)
{
	if (cbAutoRefresh->Checked)
	{
		sbShowClick(NULL);
	}
}


void __fastcall TFormFileSpread::sbMoreDetailClick(TObject *Sender)
{
// TO DO	TXWindows.ExecuteFile(0, 'http://en.wikipedia.org/wiki/Benford''s_law', '', '');
}


void TFormFileSpread::ExportData(const std::wstring file_name)
{
	if (vtcSpread->SeriesList[0].Count != 0)
	{
/*		AssignFile(tf, aFilename);
		{$I-}
		Rewrite(tf);
		{$I+}

		if (IOResult <> 0) then begin
			  TMSLogger.Error('Error writing CSV file "' + aFileName + '".');
		end
		else
		{
			   writeln(tf, 'RangeFromBytes,RangeToBytes,Range,Quantity');

			for t := 0 to vtcSpread.SeriesList[0].Count - 1 do begin
				 writeln(tf, IntToStr(t * coeff) + ',' +
						 IntToStr((t * coeff) + coeff - 1) + ',' +
						 '"' + TConvert.ConvertToUsefulUnit(t * coeff) + ' -> ' + TConvert.ConvertToUsefulUnit((t * coeff) + coeff - 1) + '",' +
						 FloatToStr(vtcSpread.SeriesList[0].YValue[t]));
			end;

			CloseFile(tf);
		 end; */
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kWarning],
					GLanguageHandler->Text[kNoDataToExport],
					XDialogTypeWarning);
	}
}
