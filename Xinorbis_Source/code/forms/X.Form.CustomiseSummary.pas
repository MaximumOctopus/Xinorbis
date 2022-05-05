// (c) Paul Alan Freshney 2006-2011
//
// Modified: December 16th 2010
//
// 201

unit X.Form.CustomiseSummary;

interface

uses
  Windows, Messages, System.SysUtils, Variants, System.Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, ExtCtrls,

  X.Utility, X.Global, X.Settings, X.Constants, X.LanguageHandler;


const
  SummaryItemsCount = 9;


type
  TfrmCustomSummary = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    lbSummaryLayout: TListBox;
    sbRemove: TSpeedButton;
    Bevel1: TBevel;
    bCancel: TBitBtn;
    bSave: TBitBtn;
    GroupBox1: TGroupBox;
    lSI1: TLabel;
    lSI2: TLabel;
    lSI3: TLabel;
    lSI4: TLabel;
    lSI5: TLabel;
    lSI8: TLabel;
    lSI7: TLabel;
    lSI6: TLabel;
    sbUp: TSpeedButton;
    sbDown: TSpeedButton;
    LSI9: TLabel;
    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure lSI8Click(Sender: TObject);
    procedure sbRemoveClick(Sender: TObject);
    procedure lbSummaryLayoutDblClick(Sender: TObject);
    procedure sbUpClick(Sender: TObject);
    procedure sbDownClick(Sender: TObject);
    function  BuildSummaryLayout: string;
    procedure bSaveClick(Sender: TObject);
    procedure lbSummaryLayoutClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    SummaryItems : array[1..SummaryItemsCount] of TLabel;
  public
    { Public declarations }
  end;

var
  frmCustomSummary: TfrmCustomSummary;


procedure ShowCustomSummary;


implementation


{$R *.dfm}


procedure ShowCustomSummary;
 begin
  with TfrmCustomSummary.Create(Application) do
    try
      ShowModal;
    finally
      free;
    end;
end;


procedure TfrmCustomSummary.FormCreate(Sender: TObject);
 begin
  SummaryItems[1] := lSI1; SummaryItems[2] := lSI2; SummaryItems[3] := lSI3;
  SummaryItems[4] := lSI4; SummaryItems[5] := lSI5; SummaryItems[6] := lSI6;
  SummaryItems[7] := lSI7; SummaryItems[8] := lSI8; SummaryItems[9] := lSI9;
end;


procedure TfrmCustomSummary.FormShow(Sender: TObject);
 var
  t, lLayoutID : integer;
  s : string;

 begin
  s := '';

  lbSummaryLayout.Clear;

  //== languagey stuff =========================================================
  Caption           := XText[rsCustomise] + ' ' + XText[rsSummary] + ' ' + XText[rsReportLayout];
  Label1.Caption    := XText[rsAvailable] + ' ' + XText[rsSummary] + ' ' + XText[rsReportItems];
  Label2.Caption    := XText[rsSummary]   + ' ' + XText[rsReportLayout];
  GroupBox1.Caption := XText[rsClickToAdd];

  bSave.Caption     := XText[rsSave];
  bCancel.Caption   := XText[rsCancel];

  for t := 1 to SummaryItemsCount do begin
    SummaryItems[t].Caption := OtherReportItems[t - 1];
  end;

  // build current layout options

  for t := 1 to length(XSettings.Report.SummaryLayout) do begin
    if XSettings.Report.SummaryLayout[t] = ':' then begin
      lLayoutID := StrToIntDef(s, 99);

      if lLayoutID <= SummaryItemsCount then begin
        lbSummaryLayout.Items.Add(SummaryItems[lLayoutID].Caption);
      end;

      s := '';
    end
    else
      s := s + XSettings.Report.SummaryLayout[t];
  end;
end;


procedure TfrmCustomSummary.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;


procedure TfrmCustomSummary.lSI8Click(Sender: TObject);
 begin
  if lbSummaryLayout.Items.IndexOf(TLabel(Sender).Caption) = -1 then begin
    lbSummaryLayout.Items.Add(TLabel(Sender).Caption);
  end;
end;


procedure TfrmCustomSummary.sbRemoveClick(Sender: TObject);
 begin
  lbSummaryLayout.DeleteSelected;
end;


procedure TfrmCustomSummary.lbSummaryLayoutDblClick(Sender: TObject);
 begin
  lbSummaryLayout.DeleteSelected;

  sbRemove.Enabled := False;
  sbUp.Enabled     := False;
  sbDown.Enabled   := False;
end;


procedure TfrmCustomSummary.sbUpClick(Sender: TObject);
 var
  a : integer;

 begin
  if lbSummaryLayout.ItemIndex > 0 then begin
    a:=lbSummaryLayout.ItemIndex - 1;

    lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex - 1);

    lbSummaryLayout.ItemIndex := a;
  end;
end;


procedure TfrmCustomSummary.sbDownClick(Sender: TObject);
 var
  a : integer;

 begin
  if lbSummaryLayout.ItemIndex <> -1 then begin
    if lbSummaryLayout.ItemIndex<lbSummaryLayout.Count - 1 then begin
      a:=lbSummaryLayout.ItemIndex + 1;

      lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex + 1);

      lbSummaryLayout.ItemIndex := a;
    end;
  end;
end;


function TfrmCustomSummary.BuildSummaryLayout: string;
 var
  t,z,idx : integer;

 begin
  Result := '';

  for t := 0 to lbSummaryLayout.Count - 1 do begin
    idx := 0;

    for z := 1 to SummaryItemsCount do begin
      if SummaryItems[z].Caption = lbSummaryLayout.Items[t] then idx := z;
    end;

    Result := Result + IntToStr(idx) + ':';
  end;
end;


procedure TfrmCustomSummary.bSaveClick(Sender: TObject);
 begin
  XSettings.Report.SummaryLayout := BuildSummaryLayout;
end;


procedure TfrmCustomSummary.lbSummaryLayoutClick(Sender: TObject);
 var
  status : boolean;

 begin
  if lbSummaryLayout.ItemIndex = -1 then
    status := False
  else
    status := True;

  sbUp.Enabled     := status;
  sbDown.Enabled   := status;
  sbRemove.Enabled := status;
end;


end.
