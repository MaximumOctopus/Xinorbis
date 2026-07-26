//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormQuickMenuBuilder.h"

#include "ConstantsData.h"
#include "SystemGlobal.h"
#include "LanguageHandler.h"

extern LanguageHandler *GLanguageHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}


void OpenQuickMenuBuilder()
{
	TForm9 *Form9 = new TForm9(Application);

	Form9->ShowModal();

	delete Form9;
}


void __fastcall TForm9::FormCreate(TObject *Sender)
{
	Init();

	std::wstring LanguageSymbol = GLanguageHandler->GetLanguageSymbol();

	odMain->InitialDir = (GSystemGlobal->ExePath + L"data\\languages\\" + LanguageSymbol + L"\\").c_str();
}


void __fastcall TForm9::FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
		  int &MaxWidth, int &MaxHeight)
{
	MinWidth  = 650;
	MinHeight = 581;
}


void TForm9::Init()
{
	// category
	sbCatProg->Caption = GLanguageHandler->TypeDescriptions[1].c_str();
	sbCatSys->Caption = GLanguageHandler->TypeDescriptions[2].c_str();
	sbCatGFX->Caption = GLanguageHandler->TypeDescriptions[3].c_str();
	sbCatMov->Caption = GLanguageHandler->TypeDescriptions[4].c_str();
	sbCatSound->Caption = GLanguageHandler->TypeDescriptions[5].c_str();
	sbCatOff->Caption = GLanguageHandler->TypeDescriptions[6].c_str();
	sbCatCod->Caption = GLanguageHandler->TypeDescriptions[7].c_str();
	sbCatCom->Caption = GLanguageHandler->TypeDescriptions[8].c_str();
	sbCatOther->Caption = GLanguageHandler->TypeDescriptions[9].c_str();

	sbCatC1->Caption = GLanguageHandler->TypeDescriptions[10].c_str();
	sbCatC2->Caption = GLanguageHandler->TypeDescriptions[11].c_str();
	sbCatC3->Caption = GLanguageHandler->TypeDescriptions[12].c_str();
	sbCatC4->Caption = GLanguageHandler->TypeDescriptions[13].c_str();
	sbCatC5->Caption = GLanguageHandler->TypeDescriptions[14].c_str();
	sbCatC6->Caption = GLanguageHandler->TypeDescriptions[15].c_str();
	sbCatC7->Caption = GLanguageHandler->TypeDescriptions[16].c_str();
	sbCatC8->Caption = GLanguageHandler->TypeDescriptions[17].c_str();
	sbCatC9->Caption = GLanguageHandler->TypeDescriptions[18].c_str();
	sbCatC10->Caption = GLanguageHandler->TypeDescriptions[19].c_str();

	// structure
	sbSeparator->Caption = GLanguageHandler->Text[kSeparator].c_str();
	sbSubMenuTemplate->Caption = L"Sub-menu Template"; // to do

	// dialogs
	sbDCreatedDate->Caption = GLanguageHandler->Text[kCreatedDate].c_str();
	sbDAccessedDate->Caption = GLanguageHandler->Text[kAccessedDate].c_str();
	sbDModifiedDate->Caption = GLanguageHandler->Text[kModifiedDate].c_str();
	sbDSize->Caption = GLanguageHandler->Text[kSize].c_str();
	sbDWizard->Caption = GLanguageHandler->Text[kWizard].c_str();

	// attributes
	sbAArchive->Caption = GLanguageHandler->Text[kArchive].c_str();
	sbASystem->Caption = GLanguageHandler->Text[kSystem].c_str();
	sbAHidden->Caption = GLanguageHandler->Text[kHidden].c_str();
	sbAReadOnly->Caption = GLanguageHandler->Text[kReadOnly].c_str();

	// dates
	rbZCreated->Caption = GLanguageHandler->Text[kCreated].c_str();
	rbZAccessed->Caption = GLanguageHandler->Text[kAccessed].c_str();
	rbZModified->Caption = GLanguageHandler->Text[kModified].c_str();

	sbZToday->Caption = L"Today"; // to do add to lang file
	sbZYesterday->Caption = L"Yesterday";
	sbZThisWeek->Caption = L"This Week";
	sbZThisMonth->Caption = L"This Month";
	sbZLastSixMonths->Caption = L"Last 6 months";
	sbZLastYear->Caption = L"Last Year";
}


void __fastcall TForm9::SpeedButton1Click(TObject *Sender)
{
	if (odMain->Execute())
	{
		mMain->Lines->LoadFromFile(odMain->FileName);
	}
}


void __fastcall TForm9::bClearClick(TObject *Sender)
{
	mMain->Clear();

	mMain->Lines->Add(L"{Empty menu template}");
	mMain->Lines->Add(L"-");
	mMain->Lines->Add(L"[submenu title]");
	mMain->Lines->Add(L".sumenu item 1=search");
	mMain->Lines->Add(L".sumenu item 2=search");
	mMain->Lines->Add(L".sumenu item 3=search");
	mMain->Lines->Add(L"*");
}


void __fastcall TForm9::SpeedButton3Click(TObject *Sender)
{
	if (!FileName.empty())
	{
		try
		{
			mMain->Lines->SaveToFile(FileName.c_str());
		}
		catch(...)
		{
		//	ShowXDialog('Quick Menu Builder - error',
// to do 					'Unable to save file "' + filename + '". ' + e.ClassName + ' / ' + e.Message,
		 //		XDialogTypeWarning);
		}
	}
	else
	{
		SpeedButton4Click(NULL);
	}
}


void __fastcall TForm9::SpeedButton4Click(TObject *Sender)
{
	if (sdMain->Execute())
	{
		try
		{
			mMain->Lines->SaveToFile(sdMain->FileName);
		}
		catch(...)
		{
		//	ShowXDialog('Quick Menu Builder - error',
// to do 					'Unable to save file "' + filename + '". ' + e.ClassName + ' / ' + e.Message,
		 //		XDialogTypeWarning);
		}

		FileName = sdMain->FileName.c_str();
	}
}


void __fastcall TForm9::sbTestClick(TObject *Sender)
{
	if (mMain->Lines->Count == 0) return;

	TMenuItem *LastNode = nullptr;

	MenuStrings.clear();
	puTest->Items->Clear();

	for (int t = 0; t < mMain->Lines->Count; t++)
	{
		if (mMain->Lines->Strings[t] != L"")
		{
			std::wstring line = mMain->Lines->Strings[t].c_str();

			switch (line[0])
			{
			case L'-':
			{
				TMenuItem *mi = new TMenuItem(puTest);
				mi->Caption = L"-";

				if (LastNode == nullptr)
				{
					puTest->Items->Add(mi);
				}
				else
				{
					LastNode->Add(mi);
				}
				break;
			}
			case L'{':
			{
				TMenuItem *mi = new TMenuItem(puTest);
				mi->Caption = line.substr(1).c_str();
				mi->Enabled = false;

				if (LastNode == nullptr)
				{
					puTest->Items->Add(mi);
				}
				else
				{
					LastNode->Add(mi);
				}
				break;
			}
			case L'[':
			{
				TMenuItem *mi = new TMenuItem(puTest);
				mi->Caption = line.substr(1).c_str();
				mi->Enabled = true;

				if (LastNode == nullptr)
				{
					puTest->Items->Add(mi);
				}
				else
				{
					LastNode->Add(mi);
				}

				LastNode = mi;

				break;
			}
			case L'.':
			{
				TMenuItem *mi = new TMenuItem(puTest);
				auto ix = line.find(L'=');

				if (ix != std::wstring::npos)
				{
					mi->Caption = line.substr(1, ix - 1).c_str();

					MenuStrings.push_back(line.substr(ix + 1).c_str());

					//mi.OnClick := MenuClick;
					mi->Tag = MenuStrings.size() - 1;
				}
				else
				{
					mi->Caption = line.substr(1, ix - 1).c_str();
				}

				mi->Enabled = true;

				if (LastNode == nullptr)
				{
					puTest->Items->Add(mi);
				}
				else
				{
					LastNode->Add(mi);
				}
				break;
			}
			case L'*':
				LastNode = LastNode->Parent;
				break;
			}
		}
	}

	TSpeedButton *sb = (TSpeedButton*)Sender;

	puTest->Popup(Left + sb->Left + 5, Top + sb->Top + 45);
}


void __fastcall TForm9::MenuClick(TObject *Sender)
{
//	ShowXDialog('Quick Menu Builder - output',
//			  MenuStrings[TMenuItem(Sender).Tag],
//			  XDialogTypeXinorbis);
}


void __fastcall TForm9::sbCatProgClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	std::wstring s = L"";

	switch (sb->Tag)
	{
	case kCategory_Program:	   s = L"#PROG"; break;
	case kCategory_System:     s = L"#SYS";	break;
	case kCategory_Graphics:   s = L"#GFX";	break;
	case kCategory_Movie:      s = L"#MOVIE"; break;
	case kCategory_Sound:      s = L"#SOUND"; break;
	case kCategory_Office:     s = L"#OFF";	break;
	case kCategory_Code: 	   s = L"#COD"; break;
	case kCategory_Compressed: s = L"#COM"; break;
	case kCategory_Other:      s = L"#OTH"; break;
	case kCategory_Custom_1:   s = L"#C1"; break;
	case kCategory_Custom_2:   s = L"#C2"; break;
	case kCategory_Custom_3:   s = L"#C3"; break;
	case kCategory_Custom_4:   s = L"#C4"; break;
	case kCategory_Custom_5:   s = L"#C5"; break;
	case kCategory_Custom_6:   s = L"#C6"; break;
	case kCategory_Custom_7:   s = L"#C7"; break;
	case kCategory_Custom_8:   s = L"#C8"; break;
	case kCategory_Custom_9:   s = L"#C9"; break;
	case kCategory_Custom_10:  s = L"#C10"; break;
	}

	mMain->SelText = s.c_str();
}


void __fastcall TForm9::sbSeparatorClick(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	int CurrentLine = mMain->CaretPos.Y;

	switch (mi->Tag)
	{
	case 0:
	{
		mMain->Lines->Insert(CurrentLine, L"-");
		break;
	}
	case 1:
	{
		//  mMain.Lines[lCurrentLine] :
		mMain->Lines->Insert(CurrentLine, L"*");
		mMain->Lines->Insert(CurrentLine, L".sumenu item 3=search");
		mMain->Lines->Insert(CurrentLine, L".sumenu item 2=search");
		mMain->Lines->Insert(CurrentLine, L".sumenu item 1=search");
		mMain->Lines->Insert(CurrentLine, L"[submenu title]");
		break;
	}
	}
}


void __fastcall TForm9::sbDCreatedDateClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	std::wstring s = L"";

	switch (sb->Tag)
	{
	case kDialogCreatedDate:  s = L"{GetDateDialogC}"; break;
	case kDialogAccessedDate: s = L"{GetDateDialogA}"; break;
	case kDialogModifiedDate: s = L"{GetDateDialogM}"; break;

	case kDialogSize:         s = L"{GetSizeDialog}"; break;

	case kDialogSearchWizard: s = L"$SearchWizard"; break;
	}

	mMain->SelText = s.c_str();
}


void __fastcall TForm9::sbAArchiveClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	std::wstring s = L"";

	switch (sb->Tag)
	{
	case kAttribArchive:  s = L"@ARCHIVE"; break;
	case kAttribSystem:   s = L"@SYSTEM"; break;
	case kAttribHidden:   s = L"@HIDDEN"; break;
	case kAttribReadOnly: s = L"@READONLY"; break;
	}

	mMain->SelText = s.c_str();
}


void __fastcall TForm9::sbZTodayClick(TObject *Sender)
{
	TSpeedButton *sb = (TSpeedButton*)Sender;

	std::wstring s = L"";
	std::wstring date = L"cdate";

	if (rbZAccessed->Checked)
	{
		date = L"adate";
	}
	else if (rbZModified->Checked)
	{
		date = L"mdate";
	}

	switch (sb->Tag)
	{
	case kDateToday: 	     s = L"(" + date + L"={NOW})"; break;
	case kDateYesterday:     s = L"(" + date + L"={YESTERDAY})"; break;
	case kDateLastWeek:      s = L"(" + date + L">{DECWEEK}) (" + date + L"<{NOW})"; break;
	case kDateLastMonth:     s = L"(" + date + L">{DECMONTH}) (" + date + L"<{NOW})"; break;
	case kDateLastSixMonths: s = L"(" + date + L"<{DECMONTH6})"; break;
	case kDateLastYear:      s = L"(" + date + L"<{DECMONTH12})"; break;
	}

	mMain->SelText = s.c_str();
}
