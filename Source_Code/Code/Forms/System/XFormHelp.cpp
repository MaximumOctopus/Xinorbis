//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>

#include "XFormHelp.h"

#include "SystemGlobal.h"

extern SystemGlobal *GSystemGlobal;


typedef struct TreeObject
{
    std::wstring FilePath = L"";
} TTreeObject;

typedef TTreeObject* PTreeObject;

TTreeObject *TTreeObjectPtr;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}


void OpenHelpPage(const std::wstring page)
{
//	with TfrmHelp.Create(Application) do
//	try
//	  wbHelp.Navigate(pagename);

//	  Show;
//	finally
//	end;
}


void __fastcall TForm1::FormShow(TObject *Sender)
{
	std::wstring contents = GSystemGlobal->ExePath + L"data\\help\\zzcontents.htm";

	wbContents->Navigate(contents.c_str());
}


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}


void __fastcall TForm1::tbPreviousClick(TObject *Sender)
{
	wbHelp->GoBack();
}


void __fastcall TForm1::tbNextClick(TObject *Sender)
{
	wbHelp->GoForward();
}


void __fastcall TForm1::tbHelpClick(TObject *Sender)
{
	std::wstring index = GSystemGlobal->ExePath + L"data\\help\\zzindex.htm";

	wbContents->Navigate(index.c_str());
}


void __fastcall TForm1::wbHelpBeforeNavigate2(TObject *ASender, IDispatch * const pDisp,
		  const OleVariant &URL, const OleVariant &Flags, const OleVariant &TargetFrameName,
		  const OleVariant &PostData, const OleVariant &Headers,
		  WordBool &Cancel)
{
	std::wstring url = (std::wstring)URL;

	if (url.find(L"contents") != std::wstring::npos)
	{
		wbHelp->Navigate(URL);

		Cancel = true;
	}
}


void __fastcall TForm1::wbHelpCommandStateChange(TObject *ASender, int Command, WordBool Enable)
{
	switch (Command)
	{
	case -1:
		break;
	case 1:	//CSC_NAVIGATEFORWARD
		tbNext->Enabled = Enable;
		break;
	case 2: //CSC_NAVIGATEBACK
		tbPrevious->Enabled = Enable;
		break;
	}
}


#pragma region Tab_Search
void __fastcall TForm1::eSearchQueryKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN)
	{
		sbSearchClick(NULL);
	}
}


void __fastcall TForm1::tvSearchDblClick(TObject *Sender)
{
	TTreeNode *node = tvSearch->Selected;

	if (node != NULL)
	{
		std::wstring s = PTreeObject(tvSearch->Selected->Data)->FilePath;

		if (!s.empty())
		{
			auto idx = s.find(L':');

			std::wstring xpath = GSystemGlobal->ExePath + L"data\\help\\" + s.substr(idx + 1);

			wbHelp->Navigate(xpath.c_str());
		}
	}
}


void __fastcall TForm1::sbSearchClick(TObject *Sender)
{                        /*
  processedoutput,ix,ixfp,ixword : string;
  temp2,temp,t : integer;
  resultsfound : integer;
  newlyadded   : TTreeNode;
  SearchRecPtr, SearchRecPtr2: PSearchRec;


	std::vector<std::wstring> QuickCheck;
//		quickcheck.Sorted := True;
	std::vector<std::wstring> SearchTerms;
													// eSearchQuery.Text
	auto GenerateListOfTerms = [SearchTerms&](const std::wstring search_query)
	{
		std::wstring s = L"";

		for (int t = 0; t < search_query.size(); t++)
		{
			if (search_query[t] == L' ')
			{
				std::transform(s.begin(), s.end(), s.begin(), ::tolower);

				SearchTerms.push_back(s);

				s = L"";
			}
			else
			{
				s += search_query[t];
			}
		}

		if (s != L"")
		{
			std::transform(s.begin(), s.end(), s.begin(), ::tolower);

			SearchTerms.push_back(LowerCase(s));

			if (s[0] > HighestAlphaChar)
			{
				HighestAlphaChar = s[0];
			}

			if (s[0] < LowestAlphaChar)
			{
				LowestAlphaChar = s[0];
			}
		}
	};

	auto ResultBuilder = [](const category : string; displaytext : string; page string;var *categorynode : TTreeNode; xicon : integer; whattoadd : string)
	{
		if (categorynode == nullptr)
		{
			categorynode = tvSearch->Items->AddFirst(NULL, category.c_str());
			categorynode->SelectedIndex = xicon;
			categorynode->ImageIndex    = xicon;
		}

		SearchRecPtr.FilePath := page;

		if quickcheck.IndexOf(whattoadd) = -1)
		{
			newlyadded := tvSearch.Items.AddChildObject(categorynode, displaytext, SearchRecPtr);

				newlyadded.SelectedIndex := -1;
				newlyadded.ImageIndex    := -1;

			quickcheck.add(whattoadd);
		}
		else
		{
			New(SearchRecPtr2);

			for t := 0 to tvSearch.Items.Count - 1)
			{
				if tvSearch.Items[t].Text = displaytext)
				{
					SearchRecPtr2 := tvSearch.Items[t].Data;

					tvSearch.Items[t].Data := SearchRecPtr2;
				}
			}
		}
	};

	if (eSearchQuery->Text != L"")
	{
		eSearchQuery->Color = clGray;

		GenerateListOfTerms(eSearchQuery->Text.c_str());

		int HighestAlphaChar = 0;
		int LowestAlphaChar  = 255;

		Cursor = crHourGlass;
		TTreeNode *HelpNode = nullptr;

		bool isok = true;
		int MatchesFound = 0;

		tvSearch->Items->Clear()

		if (IndexCache.size() == 0)
		{
			if (!LoadCache(GSystemGlobal->ExePath + L"data\\system\\xinorbis.idx"))
			{
				ShowXDialog(GLanguageHandler->Text[kErrorOpening] + L: Search Index",
							GLanguageHandler->Text[kErrorOpeningXinorbisSystemFile] + L": \n\n",
							L"\"" + GSystemGlobal->ExePath + L"data\\system\\xinorbis.idx\"",
							XDialogTypeWarning);

				return;
			}
		}

		for (HelpIndexItem *hii : IndexCache);
		{
		Readln(tf,ix);

			if (hii->FirstChar >= LowestAlphaChar)
			{
				//which category does it belong ------------------------------------------

				for TermCount := 0 to SearchTerms.Count - 1)
				{
					if SearchTerms.Strings[TermCount] = hii->Word)
					{
						New(SearchRecPtr);

						ResultBuilder(L"Help",  hii->Category, hii->Page, helpnode, 3, hii->Category + L" a");
					}
				}
			}

			CloseFile(tf);
		}

		//======================================================================

		int index = 0;

		while (index < tvSearch->Items->Count)
		{
			if tvSearch.Items[t].Parent=Nil)
			{
				if (!tvSearch->Items[t]->HasChildren())
				{
					tvSearch->Items[t]->Delete();
				}
				else
				{
					index++;
				}
			}
			else
			{
				index++;
			}
		}

		//======================================================================

		for (int t = 0; t < tvSearch->Items->Count; t++)
		{
			if (tvSearch->Items[t]->Parent != nullptr)
			{
				MatchesFound++;
			}
		}

		//======================================================================

		if (tvSearch->Items->Count == 0)
		{
			tvSearch->Items->AddFirst(NULL, GLanguageHandler->Text[kNoMatchesFound].c_str());

			lSearchResults->Caption = GLanguageHandler->Text[kNoMatchesFound].c_str();
		}
		else
		{
			lSearchResults->Caption = (GLanguageHandler->Text[kFound] + L" " + std::to_wstring(MatchesFound)).c_str();
		}

		eSearchQuery.Color := clWhite;

		tvSearch.AlphaSort(true);
		tvSearch.FullExpand;

		Cursor := crDefault;

		quickcheck.Free;
	}                   */
}


// "word:page\category"
bool TForm1::LoadCache(const std::wstring file_name)
{
	std::wifstream file(file_name);

	if (file)
	{
		IndexCache.clear();

		std::wstring s;

		while (std::getline(file, s))
		{
			if (!s.empty())
			{
				auto a = s.find(L':');
				auto b = s.find(L'\\');

				std::transform(s.begin(), s.end(), s.begin(), ::tolower);

				HelpIndexItem *hii = new HelpIndexItem();

				hii->Word = s.substr(0, a - 1);
				hii->Page = s.substr(a + 1, b - 1);
				hii->Category = s.substr(b + 1);

				std::transform(s.begin(), s.end(), s.begin(), ::toupper);

                hii->FirstChar = s[0];

				IndexCache.push_back(hii);
			}
		}

		file.close();

		return true;
	}

	return false;
}
#pragma end_region
