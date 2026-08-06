//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormSearchWizard.h"

#include "DateUtility.h"
#include "LanguageHandler.h"
#include "SearchUtility.h"
#include "SqlUtility.h"

extern LanguageHandler *GLanguageHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
	: TForm(Owner)
{
}


std::wstring OpenSearchWizard()
{
	TForm11 *Form11 = new TForm11(Application);

	std::wstring search = L"";

	if (Form11->ShowModal() == mrOk)
	{
		Form11->BuildSearchString();
	}

	search = Form11->SearchString;

    delete Form11;

	return search;
}


void __fastcall TForm11::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}


void TForm11::Init()
{
	std::wstring things[3];
	things[0] = GLanguageHandler->Text[kOn];
	things[1] = GLanguageHandler->Text[kBefore];
	things[2] = GLanguageHandler->Text[kAfter];

	Caption = (GLanguageHandler->Text[kSearch] + L" " + GLanguageHandler->Text[kWizard]).c_str();

	cbContaining->Caption  = GLanguageHandler->Text[kContainingText].c_str();
	cbSize->Caption        = GLanguageHandler->Text[kFileSize].c_str();
	cbCategory->Caption    = GLanguageHandler->Text[kCategory].c_str();
	cbAttributes->Caption  = GLanguageHandler->Text[kFileAttributes].c_str();
	cbCreated->Caption     = GLanguageHandler->Text[kCreatedDate].c_str();
	cbAccessed->Caption    = GLanguageHandler->Text[kAccessedDate].c_str();
	cbModified->Caption    = GLanguageHandler->Text[kModifiedDate].c_str();
	cbOwner->Caption       = GLanguageHandler->Text[kFileOwner].c_str();

	lContaining->Caption   = GLanguageHandler->Text[kContains].c_str();

	sbProg->Caption        = GLanguageHandler->TypeDescriptions[1].c_str();
	sbSys->Caption         = GLanguageHandler->TypeDescriptions[2].c_str();
	sbGfx->Caption         = GLanguageHandler->TypeDescriptions[3].c_str();
	sbMovie->Caption       = GLanguageHandler->TypeDescriptions[4].c_str();
	sbSnd->Caption         = GLanguageHandler->TypeDescriptions[5].c_str();
	sbOffice->Caption      = GLanguageHandler->TypeDescriptions[6].c_str();
	sbCode->Caption        = GLanguageHandler->TypeDescriptions[7].c_str();
	sbCompressed->Caption  = GLanguageHandler->TypeDescriptions[8].c_str();
	sbOther->Caption       = GLanguageHandler->TypeDescriptions[9].c_str();
	sbCustom1->Caption     = GLanguageHandler->TypeDescriptions[10].c_str();
	sbCustom2->Caption     = GLanguageHandler->TypeDescriptions[11].c_str();
	sbCustom3->Caption     = GLanguageHandler->TypeDescriptions[12].c_str();
	sbCustom4->Caption     = GLanguageHandler->TypeDescriptions[13].c_str();
	sbCustom5->Caption     = GLanguageHandler->TypeDescriptions[14].c_str();
	sbCustom6->Caption     = GLanguageHandler->TypeDescriptions[15].c_str();
	sbCustom7->Caption     = GLanguageHandler->TypeDescriptions[16].c_str();
	sbCustom8->Caption     = GLanguageHandler->TypeDescriptions[17].c_str();
	sbCustom9->Caption     = GLanguageHandler->TypeDescriptions[18].c_str();
	sbCustom10->Caption    = GLanguageHandler->TypeDescriptions[19].c_str();

	cbAHidden->Caption     = GLanguageHandler->LanguageTypes[1].c_str();
	cbASystem->Caption     = GLanguageHandler->LanguageTypes[2].c_str();
	cbAArchive->Caption    = GLanguageHandler->LanguageTypes[3].c_str();
	cbAReadOnly->Caption   = GLanguageHandler->LanguageTypes[5].c_str();
	cbATemp->Caption       = GLanguageHandler->Text[kTemporary].c_str();
	cbAEncrypted->Caption  = GLanguageHandler->Text[kEncrypted].c_str();
	cbACompressed->Caption = GLanguageHandler->Text[kCompressed].c_str();
	cbAFolder->Caption     = GLanguageHandler->Text[kFolders].c_str();
	cbAFile->Caption       = GLanguageHandler->Text[kFiles].c_str();

	bCancel->Caption       = GLanguageHandler->Text[kCancel].c_str();

	// ===========================================================================

	cbSLTUnit->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbSLTUnit->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbSLTUnit->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbSLTUnit->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());
	cbSLTUnit->ItemIndex  = 0;

	cbSGTUnit->Items->Add(GLanguageHandler->Text[kXBytes].c_str());
	cbSGTUnit->Items->Add(GLanguageHandler->Text[kXKilobytes].c_str());
	cbSGTUnit->Items->Add(GLanguageHandler->Text[kXMegabytes].c_str());
	cbSGTUnit->Items->Add(GLanguageHandler->Text[kXGigabytes].c_str());
	cbSGTUnit->ItemIndex  = 0;

	// ===========================================================================

	DateControls[0] = dtpCreated1;
	DateControls[1] = dtpCreated2;
	DateControls[2] = dtpAccessed1;
	DateControls[3] = dtpAccessed2;
	DateControls[4] = dtpModified1;
	DateControls[5] = dtpModified2;

	cbUSelect->Items->Add(GLanguageHandler->Text[kEqualTo].c_str());
	cbUSelect->Items->Add(GLanguageHandler->Text[kNotEqualTo].c_str());
	cbUSelect->Items->Add(GLanguageHandler->Text[kContains].c_str());
	cbUSelect->Items->Add(GLanguageHandler->Text[kDoesntContain].c_str());

	cbUSelect->ItemIndex  = 0;

	// ===========================================================================

	cbCreated1->Items->Add(L"----------");
	cbCreated2->Items->Add(L"----------");
	cbAccessed1->Items->Add(L"----------");
	cbAccessed2->Items->Add(L"----------");
	cbModified1->Items->Add(L"----------");
	cbModified2->Items->Add(L"----------");

	for (int t = 0; t < 3; t++)
	{
		cbCreated1->Items->Add(things[t].c_str());
		cbCreated2->Items->Add(things[t].c_str());
		cbAccessed1->Items->Add(things[t].c_str());
		cbAccessed2->Items->Add(things[t].c_str());
		cbModified1->Items->Add(things[t].c_str());
		cbModified2->Items->Add(things[t].c_str());
	}

	cbCreated1->ItemIndex   = 0;
	cbCreated2->ItemIndex   = 0;
	cbAccessed1->ItemIndex  = 0;
	cbAccessed2->ItemIndex  = 0;
	cbModified1->ItemIndex  = 0;
	cbModified2->ItemIndex  = 0;

	dtpCreated1->DateTime  = Now();
	dtpCreated2->DateTime  = Now();
	dtpAccessed1->DateTime = Now();
	dtpAccessed2->DateTime = Now();
	dtpModified1->DateTime = Now();
	dtpModified2->DateTime = Now();

	// ===========================================================================

	CategoryControls[0] = sbProg;     CategoryControls[1] = sbSys;      CategoryControls[2] = sbGfx;       CategoryControls[3] = sbMovie;
	CategoryControls[4] = sbSnd;      CategoryControls[5] = sbOffice;   CategoryControls[6] = sbCode;      CategoryControls[7] = sbCompressed;
	CategoryControls[8] = sbOther;    CategoryControls[9] = sbCustom1;  CategoryControls[10] = sbCustom2;  CategoryControls[11] = sbCustom3;
	CategoryControls[12] = sbCustom4; CategoryControls[14] = sbCustom5; CategoryControls[14] = sbCustom6;  CategoryControls[15] = sbCustom7;
	CategoryControls[16] = sbCustom8; CategoryControls[17] = sbCustom9; CategoryControls[18] = sbCustom10;

	AttributeControls[0] = cbAHidden;    AttributeControls[1] = cbASystem;     AttributeControls[2] = cbAArchive;  AttributeControls[3] = cbATemp; AttributeControls[4] = cbAReadOnly;
	AttributeControls[5] = cbAEncrypted; AttributeControls[6] = cbACompressed; AttributeControls[7] = cbAFolder;   AttributeControls[8] = cbAFile; AttributeControls[9] = cbAVirtual;

	bShowSQLClick(NULL);
}


void __fastcall TForm11::bShowSQLClick(TObject *Sender)
{
	if (bShowSQL->Tag == 1)
	{
		bShowSQL->Tag = 0;
		pSQL->Visible = false;
	}
	else
	{
		bShowSQL->Tag = 1;
		pSQL->Visible = true;

		BuildSQLDisplay();
	}

	TBitmap *bmp = new TBitmap();
	ImageList1->GetBitmap(bShowSQL->Tag, bmp);
	bShowSQL->Glyph = bmp;

	delete bmp;
}


void __fastcall TForm11::cbContainingClick(TObject *Sender)
{
	TCheckBox *cb = (TCheckBox*)Sender;

	TPanel *panel = (TPanel*)cb->Parent;

	if (cb->Checked)
	{
		panel->Height = Heights[cb->Tag];
	}
	else
	{
		panel->Height = 24;
	}

	CheckForValidSearch();
}


void __fastcall TForm11::eSLTChange(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	if (edit->Text == L"")
	{
		edit->Color = clBtnFace;
	}
	else
	{
		edit->Color = clWindow;
	}

	BuildSQLDisplay();
}


void __fastcall TForm11::cbUSelectChange(TObject *Sender)
{
	if (cbUSelect->ItemIndex == 0)
	{
		eUContent->Enabled = false;
	}
	else
	{
		eUContent->Enabled = true;
	}

	BuildSQLDisplay();
}


void __fastcall TForm11::cbCreated1Change(TObject *Sender)
{
	TComboBox *cb = (TComboBox*)Sender;

	if (cb->ItemIndex == 0)
	{
		DateControls[cb->Tag]->Enabled = false;
	}
	else
	{
		DateControls[cb->Tag]->Enabled = true;
	}

	BuildSQLDisplay();
}


void TForm11::BuildSearchString()
{
	auto GetDate = [](int mode, TDateTime dt) -> std::wstring
	{
		switch (mode)
		{
		case 1:
			return L"=" + DateUtility::DateToString(dt, DateFormat::kYYYYMMDD);
		case 2:
			return L"<" + DateUtility::DateToString(dt, DateFormat::kYYYYMMDD);
		case 3:
			return L">" + DateUtility::DateToString(dt, DateFormat::kYYYYMMDD);
		}

		return L"";
	};

	SearchString = L"";

	// ===========================================================================
	// ===========================================================================
	// ===========================================================================

	if (cbContaining->Checked)
	{
		if (eContaining->Text != L"")
		{
			std::wstring ct = eContaining->Text.c_str();

			SearchString += ct + L" ";
		}
	}

	// ===========================================================================
	// ===========================================================================
	// ===========================================================================

	if (cbSize->Checked)
	{
		if (eSLT->Text != L"")
		{
			std::wstring slt = eSLT->Text.c_str();

			SearchString += L"(size<" + slt + GLanguageHandler->GetUnit(cbSLTUnit->ItemIndex ) + L") ";
		}

		if (eSGT->Text != L"")
		{
			std::wstring sgt = eSGT->Text.c_str();

			SearchString += L"(size>" + sgt + GLanguageHandler->GetUnit(cbSGTUnit->ItemIndex ) + L") ";
		}
	}

	// ===========================================================================
	// ===========================================================================
	// ===========================================================================

	if (cbCategory->Checked)
	{
		for (int t = 0; t < 19; t++)
		{
			if (CategoryControls[t]->Checked)
			{
				SearchString += SearchUtility::GetSearchText(t) + L" ";
			}
		}
	}

	// ===========================================================================
	// ===========================================================================
	// ===========================================================================

	if (cbAttributes->Checked)
	{
		for (int t = 0; t < 10; t++)
		{
			if (AttributeControls[t]->Checked)
			{
				SearchString += SearchUtility::GetSearchAttribute(AttributeControls[t]->Tag) + L" ";
			}
		}
	}

	// ===========================================================================
	// ===========================================================================
	// ===========================================================================

	if (cbCreated->Checked)
	{
		if (cbCreated1->ItemIndex != 0)
		{
			 SearchString += L"(date" + GetDate(cbCreated1->ItemIndex, dtpCreated1->DateTime) + L") ";
		}

		if (cbCreated2->ItemIndex != 0)
		{
			SearchString += L"(date" + GetDate(cbCreated2->ItemIndex, dtpCreated2->DateTime) + L") ";
		}
	}

	// ===========================================================================
	// ===========================================================================
	// ===========================================================================

	if (cbAccessed->Checked)
	{
		if (cbAccessed1->ItemIndex != 0)
		{
			SearchString += L"(adate" + GetDate(cbAccessed1->ItemIndex, dtpAccessed1->DateTime) + L") ";
		}

		if (cbAccessed2->ItemIndex != 0)
		{
			SearchString += L"(adate" + GetDate(cbAccessed2->ItemIndex, dtpAccessed2->DateTime) + L") ";
		}
	}

	// =========================================================================

	if (cbModified->Checked)
	{
		if (cbModified1->ItemIndex != 0)
		{
			SearchString += L"(mdate" + GetDate(cbModified1->ItemIndex, dtpModified1->DateTime) + L") ";
		}

		if (cbModified2->ItemIndex != 0)
		{
			SearchString += L"(mdate" + GetDate(cbModified2->ItemIndex, dtpModified2->DateTime) + L") ";
		}
	}

	// =========================================================================

	if (cbOwner->Checked)
	{
		if (cbUSelect->ItemIndex != 0)
		{
			std::wstring uc = eUContent->Text.c_str();

			switch (cbUSelect->ItemIndex)
			{
			case 1:
				SearchString += L"(user="  + uc + L") ";
				break;
			case 2:
				SearchString += L"(user!=" + uc + L") ";
				break;
			case 3:
				SearchString += L"(user~"  + uc + L") ";
				break;
			case 4:
				SearchString += L"(user!~" + uc + L") ";
				break;
			}
		}
	}
}


void TForm11::CheckForValidSearch()
{
	if (cbContaining->Checked || cbCreated->Checked || cbAccessed->Checked || cbModified->Checked ||
		cbSize->Checked | cbCategory->Checked || cbOwner->Checked || cbAttributes->Checked)
	{
		bOK->Enabled = true;
	}
	else
	{
		bOK->Enabled = false;
	}
}


void TForm11::BuildSQLDisplay()
{
	if (bShowSQL->Tag == 1)
	{
		BuildSearchString();

		eSQL->Text = SqlUtility::XinorbisSearchToSQL(L"", L"", L"", SearchString, 0, 500, true).c_str();
	}
}
