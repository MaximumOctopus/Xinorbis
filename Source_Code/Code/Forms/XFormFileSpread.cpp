//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>

#include "XFormFileSpread.h"
#include "XFormXinorbisDialog.h"

#include "ChartUtility.h"
#include "ConstantsGui.h"
#include "ConstantsReports.h"
#include "Formatting.h"
#include "FormDetails.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "Log.h"
#include "SaveDialogs.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;
extern Log *GLog;
extern ScanEngine *GScanEngine;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

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


void OpenFileSpread(int data_index)
{
	FormFileSpread->SetSource(data_index);

    FormFileSpread->Show();
}


void __fastcall TFormFileSpread::FormShow(TObject *Sender)
{
	gbUsers->Caption = GLanguageHandler->Text[kUsers].c_str();

	cbUsers->Items->Clear();
	cbUsers->Items->Add(GLanguageHandler->Text[kAll].c_str());

	for (int t = 0; t < GScanEngine->Data[DataSource].Users.size(); t++)
	{
		cbUsers->Items->Add(GScanEngine->Data[DataSource].Users[t]->Name.c_str());
	}

	cbUsers->ItemIndex = 0;

	//

	LargestFileSize = 0;

	if (GScanEngine->Data[DataSource].Files.size() == 0)
	{
		sbShow->Enabled = false;
	}
	else
	{
		for (int t = 0; t < GScanEngine->Data[DataSource].Files.size(); t++)
		{
			if (GScanEngine->Data[DataSource].Files[t]->Size > LargestFileSize)
			{
				LargestFileSize = GScanEngine->Data[DataSource].Files[t]->Size;
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
	FormDetails fd(kFormFileSpread, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	if (OnULSP)
	{
		OnULSP(kFormFileSpread);
	}

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

	FormDetails fd = GSettingsHandler->LoadFormDetails(kFormFileSpread);

	if (fd.FormId != -1)
	{
		Left   = fd.X;
		Top    = fd.Y;
		Width  = fd.Width;
		Height = fd.Height;
	}
}


void TFormFileSpread::SetSource(int data_source)
{
    DataSource = data_source;
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
	if (GScanEngine->Data[DataSource].Files.size() != 0)
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
	HelpHandler::OpenHelpPage(L"a11.htm");
}


void __fastcall TFormFileSpread::sbCSVReportClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCSVFiles] + L" (*.csv)|*.csv",
												  L".csv",
												  Utility::GetDefaultFileName(L".csv", GLanguageHandler->Text[kFileSizeSpread] + L"_" + GLanguageHandler->Text[kReport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		ExportData(file_name);
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
		BlockSize = std::floor(LargestFileSize / StrToInt(eResolution->Text));
		Coeff = StrToInt64(eResolution->Text);
		break;
	case kUnitKilobytes:
		BlockSize = std::floor(LargestFileSize / ((StrToInt(eResolution->Text) * 1024)));
		Coeff = StrToInt64(eResolution->Text) * 1024;
		break;
	case kUnitMegabytes:
		BlockSize = std::floor(LargestFileSize / (StrToInt(eResolution->Text) * 1024 * 1024));
		Coeff = StrToInt64(eResolution->Text) * 1024 * 1024;
		break;
	case kUnitGigabytes:
		BlockSize = std::floor(LargestFileSize / (StrToInt64(eResolution->Text) * 1024 * 1024 * 1024));
		Coeff = StrToInt64(eResolution->Text) * 1024 * 1024 * 1024;
		break;
	}

	BlockSize++;

	Spread = new int[BlockSize];

	for (int t = 0; t < BlockSize; t++)
	{
		Spread[t] = 0;
	}

	if (cbUsers->ItemIndex == 0) // optimised for all users
	{
		for (int t = 0; t < GScanEngine->Data[DataSource].Files.size(); t++)
		{
			if (!(GScanEngine->Data[DataSource].Files[t]->Attributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				int box = std::floor(GScanEngine->Data[DataSource].Files[t]->Size / Coeff);

				Spread[box]++;
			}
		}
	}
	else
	{
		int UserId = GScanEngine->Data[DataSource].FindUser(cbUsers->Items->Strings[cbUsers->ItemIndex].c_str());

		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			if (!(faDirectory & file->Attributes))
			{
				if (file->Owner == UserId)
				{
					int box = std::floor(file->Size / Coeff);

					Spread[box]++;
				}
			}
		}
	}

	int MaxHit = 0;

	for (int t = 0; t < BlockSize; t++)
	{
		if (Spread[t] > MaxHit)
		{
			MaxHit = Spread[t];
        }
	}

	// =====================================================================
	// =====================================================================

	vtcSpread->SeriesList->Items[0]->Clear();

	for (int t = 0; t < BlockSize; t++)
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
				colx = kSpectrumColours[t % kSpectrumMod];
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

	for (int t = 0; t < GScanEngine->Data[DataSource].Files.size(); t++)
	{
		FileObject *xfo = GScanEngine->Data[DataSource].Files[t];

		if (!(faDirectory & xfo->Attributes))
		{
			if (xfo->Size != 0)
			{
				int i = std::to_wstring(GScanEngine->Data[DataSource].Files[t]->Size)[0] - 48;

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

		vtcSpread->SeriesList->Items[0]->Add(zig, std::to_wstring(t + 1).c_str(), TColor(kSpectrumColours[t % kSpectrumMod]));

		if (cbNormalDistribution->Checked)
		{
			zig = (log10(t + 1) - log10(t)) * 100;

			vtcSpread->SeriesList->Items[1]->Add(zig, std::to_wstring(t + 1).c_str(), TColor(0xD6D5DB));
		}
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
	TEdit *edit = (TEdit*)Sender;

	if (Key == VK_RETURN && edit->Text != L"")
	{
		if (cbAutoRefresh->Checked)
		{
			sbShowClick(NULL);
		}
	}
}


void __fastcall TFormFileSpread::miSaveChartClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kPNGFiles] + L" (*.png)|*.png",
												  L".png",
												  Utility::GetDefaultFileName(L".png", GLanguageHandler->Text[kFileSizeSpread]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		ChartUtility::SaveChartToPNG(vtcSpread, file_name);
	}
}


void __fastcall TFormFileSpread::miCopyToClipboardClick(TObject *Sender)
{
//  	TChart *chart = TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

	ChartUtility::CopyChartToClipboard(vtcSpread);
}


void __fastcall TFormFileSpread::miSaveDataClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kTextFiles] + L" (*.txt)|*.txt",
												  L".txt",
												  Utility::GetDefaultFileName(L".txt", GLanguageHandler->Text[kFileSizeSpread] + L"_" + GLanguageHandler->Text[kReport]),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		std::ofstream file(file_name);

		if (file)
		{
			for (int t = 0; t < BlockSize; t++)
			{
				std::wstring ru = (eResolution->Text + L" " + cbResolutionUnits->Text).c_str();

				file << Formatting::to_utf8(GScanEngine->Data[DataSource].Path.String + L"\n");
				file << Formatting::to_utf8(GLanguageHandler->Text[kCreated] + L": " + Utility::GetTime(DateTimeFormat::Display) + L" " + Utility::GetDate(DateTimeFormat::Display) + L"\n");
				file << Formatting::to_utf8(L"\n");
				file << Formatting::to_utf8(GLanguageHandler->Text[kInterval] + L": " + ru + L"\n");
				file << Formatting::to_utf8(L"\n");

				if (cbRange->Checked)
				{
					std::wstring ff = (eRangeFrom->Text + L" " + cbRangeFromUnits->Text).c_str();
					std::wstring tt = (eRangeTo->Text + L" " + cbRangeToUnits->Text).c_str();

					file << Formatting::to_utf8(GLanguageHandler->Text[kRange] + L" : " + ff + L"\n");
					file << Formatting::to_utf8(Formatting::AddLeading(L"", GLanguageHandler->Text[kRange].size() + 3, L' ') + tt + L"\n");
					file << Formatting::to_utf8(L"\n");
				}

				file << Formatting::to_utf8(Formatting::AddLeading(std::to_wstring(Spread[t]), 7, L' ') + L" : " + Convert::ConvertToUsefulUnit(t * Coeff) + L" <= x < " + Convert::ConvertToUsefulUnit((t * Coeff) + Coeff - 1) + L"\n");;
			}

			file.close();
		}
		else
		{
			  ShowXDialog(GLanguageHandler->Text[kWarning],
						  GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
						  XDialogTypeWarning);
		}
	}
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
	WindowsUtility::ExecuteFile(L"http://en.wikipedia.org/wiki/Benford''s_law", L"");
}


void TFormFileSpread::ExportData(const std::wstring file_name)
{
	if (vtcSpread->SeriesList[0].Count != 0)
	{
		std::ofstream file(file_name);

		if (file)
		{
			file << Formatting::to_utf8(L"RangeFromBytes,RangeToBytes,Range,Quantity\n");

			for (int t = 0; t < vtcSpread->SeriesList[0].Count; t++)
			{
				 std::wstring s = std::to_wstring(t * Coeff) + L"," +
								  std::to_wstring((t * Coeff) + Coeff - 1) + L"," +
								  L"\"" + Convert::ConvertToUsefulUnit(t * Coeff) + L" -> " + Convert::ConvertToUsefulUnit((t * Coeff) + Coeff - 1) + L"\"," +
								  std::to_wstring(vtcSpread->SeriesList->Items[0]->YValue[t]);

                 file << Formatting::to_utf8(s + L"\n");
			}

			file.close();
		}
		else
		{
			GLog->AddError(L"Error writing CSV file \"" + file_name + L"\".");
		}
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kWarning],
					GLanguageHandler->Text[kNoDataToExport],
					XDialogTypeWarning);
	}
}
