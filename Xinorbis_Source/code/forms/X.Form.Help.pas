{
  (c) Paul Alan Freshney 2002-2011

        Started: December 30th 2011
  Last Modified: December 30th 2011

  398
}

unit X.Form.Help;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, OleCtrls, SHDocVw, ExtCtrls, ComCtrls, ToolWin, ImgList,
  StdCtrls, Buttons, System.ImageList,

  X.LanguageHandler, X.SystemGlobal;

type
  TfrmHelp = class(TForm)
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    CoolBar1: TCoolBar;
    ToolBar1: TToolBar;
    Splitter1: TSplitter;
    wbHelp: TWebBrowser;
    tbNext: TToolButton;
    tbPrevious: TToolButton;
    tbHelp: TToolButton;
    ToolButton4: TToolButton;
    ilNavToolbar_On: TImageList;
    ilNavToolbar_Off: TImageList;
    wbContents: TWebBrowser;
    tvSearch: TTreeView;
    Panel1: TPanel;
    eSearchQuery: TEdit;
    sbSearch: TSpeedButton;
    lSearchResults: TLabel;
    procedure tbPreviousClick(Sender: TObject);
    procedure tbNextClick(Sender: TObject);
    procedure tbHelpClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure sbSearchClick(Sender: TObject);
    procedure eSearchQueryKeyPress(Sender: TObject; var Key: Char);
    procedure tvSearchDblClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure wbContentsBeforeNavigate2(ASender: TObject;
      const pDisp: IDispatch; const URL, Flags, TargetFrameName, PostData,
      Headers: OleVariant; var Cancel: WordBool);
    procedure wbHelpCommandStateChange(ASender: TObject; Command: Integer;
      Enable: WordBool);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmHelp: TfrmHelp;

procedure OpenHelpPage(const pagename : string);



implementation

{$R *.dfm}

uses
  X.Utility, X.Global, X.Constants, X.Dialogs.Dialog;


type
 PSearchRec = ^TSearchRec;
 TSearchRec = record
                FilePath : string;
              end;

procedure OpenHelpPage(const pagename : string);
 begin
  with TfrmHelp.Create(Application) do
    try
      wbHelp.Navigate(pagename);

      Show;
    finally
    end;
end;

procedure TfrmHelp.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;

procedure TfrmHelp.tbPreviousClick(Sender: TObject);
 begin
  wbHelp.GoBack;
end;

procedure TfrmHelp.tbNextClick(Sender: TObject);
 begin
  wbHelp.GoForward;
end;

procedure TfrmHelp.tbHelpClick(Sender: TObject);
 begin
  wbContents.Navigate(GSystemGlobal.AppPath + 'data\help\zzindex.htm');
end;

procedure TfrmHelp.FormShow(Sender: TObject);
 begin
  wbContents.Navigate(GSystemGlobal.AppPath + 'data\help\zzcontents.htm');
end;

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
end;

procedure TfrmHelp.eSearchQueryKeyPress(Sender: TObject; var Key: Char);
 begin
  if key = #13 then sbSearchClick(Nil);
end;

procedure TfrmHelp.tvSearchDblClick(Sender: TObject);
 var
  t,idx : integer;
  s,xpath : string;

 begin
  if tvSearch.Selected.Parent <> nil then begin
    s := PSearchRec(tvSearch.Selected.Data).FilePath;

    if s <> '' then begin
      idx := pos(':', s);

      xpath := '';
      for t:=idx + 1 to length(s) do
        xpath := xpath + s[t];

      wbHelp.Navigate(GSystemGlobal.AppPath + 'data\help\' + xpath);
    end;
  end;
end;

procedure TfrmHelp.wbContentsBeforeNavigate2(ASender: TObject;
  const pDisp: IDispatch; const URL, Flags, TargetFrameName, PostData,
  Headers: OleVariant; var Cancel: WordBool);
begin
  if Pos('contents', URL) = 0 then begin
    wbHelp.Navigate(URL);

    Cancel := True;
  end;
end;

procedure TfrmHelp.wbHelpCommandStateChange(ASender: TObject;
  Command: Integer; Enable: WordBool);
begin
  case Command of
    -1 : begin
         end;
    CSC_NAVIGATEBACK    : tbPrevious.Enabled := Enable;
    CSC_NAVIGATEFORWARD : tbNext.Enabled     := Enable;
  else
  end;
end;


end.
