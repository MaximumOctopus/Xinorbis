//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormHelp.h"

#include "SystemGlobal.h"

extern SystemGlobal *GSystemGlobal;

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
	/*if tvSearch.Selected.Parent <> nil then begin
	s := PSearchRec(tvSearch.Selected.Data).FilePath;

	if s <> '' then begin
	  idx := pos(':', s);

	  xpath := '';
	  for t:=idx + 1 to length(s) do
		xpath := xpath + s[t];

	  wbHelp.Navigate(GSystemGlobal.AppPath + 'data\help\' + xpath);
	end;
  end;
end;  */
}


void __fastcall TForm1::sbSearchClick(TObject *Sender)
{                            /*
procedure TfrmHelp.sbSearchClick(Sender: TObject);
 var
  tf : Textfile;
  ok : boolean;
  processedoutput,ix,ixfp,ixword : string;
  temp2,temp,t : integer;
  resultsfound : integer;
  newlyadded   : TTreeNode;
  helpnode : TTreeNode;
  SearchRecPtr, SearchRecPtr2: PSearchRec;
  quickcheck : TStringList;
  SearchTerms : TStringList;
  TermCount : integer;
  HighestAlphaChar : integer;
  LowestAlphaChar : integer;

  procedure GenerateListOfTerms;
   var
	t : integer;
	s : string;

   begin
	s := '';
	for t := 1 to length(eSearchQuery.Text) do begin
	  if eSearchQuery.Text[t] = ' ' then begin
		SearchTerms.Add(LowerCase(s));
		s:= '';
	  end
	  else
		s := s + eSearchQuery.Text[t];
	end;

	if s <> '' then begin
	  SearchTerms.Add(LowerCase(s));

	  if Ord(UpCase(s[1])) > HighestAlphaChar then
		HighestAlphaChar := Ord(UpCase(s[1]));

	  if Ord(UpCase(s[1])) < LowestAlphaChar then
		LowestAlphaChar := Ord(UpCase(s[1]));
	end;
  end;

  procedure ClearNode(ttn : TTreeNode);
   begin
	ttn.SelectedIndex := -1;
	ttn.ImageIndex    := -1;
  end;

  procedure ResultBuilder(const category : string; displaytext : string; var categorynode : TTreeNode; xicon : integer; whattoadd : string);
   var
	t : integer;

   begin
	if categorynode = nil then begin
	  categorynode := tvSearch.Items.AddFirst(Nil, category);
	  categorynode.SelectedIndex := xicon;
	  categorynode.ImageIndex    := xicon;
	end;

	SearchRecPtr.FilePath := ixfp;
	if quickcheck.IndexOf(whattoadd) = -1 then begin
	  newlyadded := tvSearch.Items.AddChildObject(categorynode, displaytext, SearchRecPtr);

	  ClearNode(newlyadded);

	  quickcheck.add(whattoadd);
	end
	else begin
	  New(SearchRecPtr2);

	  for t := 0 to tvSearch.Items.Count - 1 do begin
		if tvSearch.Items[t].Text = displaytext then begin
		  SearchRecPtr2 := tvSearch.Items[t].Data;

		  tvSearch.Items[t].Data := SearchRecPtr2;
		end;
	  end;
	end;
  end;

 begin
  if eSearchQuery.Text <> '' then begin
	eSearchQuery.Color := clGray;

	SearchTerms := TStringList.Create;
	GenerateListOfTerms;

	HighestAlphaChar := 255;
	LowestAlphaChar  := 0;

	Cursor           := crHourGlass;
	helpnode         := nil;

	ok               := True;
	resultsfound     := 0;

	tvSearch.Items.Clear;
	quickcheck        := TStringList.Create;
	quickcheck.Sorted := True;

	FileMode := fmOpenRead;
	AssignFile(tf, GSystemGlobal.AppPath + 'data\system\xinorbis.idx');
	{$I-}
	Reset(tf);

	if IOResult <> 0 then begin
	  ShowXDialog(XText[rsErrorOpening] + ': Search Index',
				  XText[rsErrorOpeningXinorbisSystemFile] + ': ' + #13#13 +
				  '"' + GSystemGlobal.AppPath+ 'data\system\xinorbis.idx"',
				  XDialogTypeWarning);
	end
	else begin
	  while (not(eof(tf))) and (ok) do begin
		Readln(tf,ix);

		if Ord(UpCase(ix[1])) >= LowestAlphaChar then begin
		  ix     := LowerCase(ix);

		  temp   := pos(':', ix);
		  temp2  := pos('\', ix);

		  ixword := copy(ix, 1, temp - 1);

		  ixfp   := copy(ix, temp + 1, temp2 - temp - 1);

		  processedoutput := copy(ix, temp2 + 1, length(ix) - temp2);

		  //which category does it belong ------------------------------------------

		  for TermCount := 0 to SearchTerms.Count - 1 do begin
			if SearchTerms.Strings[TermCount] = ixword then begin
			  New(SearchRecPtr);

			  ResultBuilder('Help',  processedoutput, helpnode, 3, processedoutput + ' a');
			end;
		  end;
		end;
	  end;

	  CloseFile(tf);
	end;
	{$I+}

	//================================================================================

	t := 0;
	while t<=tvSearch.Items.Count - 1 do begin
	  if tvSearch.Items[t].Parent=Nil then begin
		if tvSearch.Items[t].HasChildren  = False then
		  tvSearch.Items[t].Delete
		else
		  inc(t);
	  end
	  else
		inc(t);
	end;

	//================================================================================
	for t := 0 to tvSearch.Items.Count - 1 do
	  if tvSearch.Items[t].Parent <> Nil then inc(resultsfound);
	//================================================================================

	if tvSearch.Items.Count = 0 then begin
	  tvSearch.Items.AddFirst(nil, XText[rsNoMatchesFound]);

	  lSearchResults.Caption := XText[rsNoMatchesFound] + '.';
	end
	else begin
	   lSearchResults.Caption := XText[rsFound] + ' ' + IntToStr(resultsfound) + '.';
	end;

	MessageBeep(MB_ICONEXCLAMATION);
	eSearchQuery.Color := clWhite;

	tvSearch.AlphaSort(true);
	tvSearch.FullExpand;

	Cursor := crDefault;

	quickcheck.Free;
  end;
end;           */
}
#pragma end_region
