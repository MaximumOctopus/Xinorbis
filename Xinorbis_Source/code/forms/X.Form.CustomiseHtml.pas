// (c) Paul Alan Freshney 2006-2011
//
// Modified: December 16th 2010
//
// 361

unit X.Form.CustomiseHtml;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, ExtCtrls,

  X.Utility, CheckLst, X.Settings, X.CReportOptions,

  X.Global, X.Constants, X.Dialogs.Dialog, X.Conversions, X.LanguageHandler,
  X.SystemGlobal, Vcl.OleCtrls;


const
  HTMLItemsCount = 16;


type
  TfrmCustomHTML = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    sbRemove: TSpeedButton;
    Bevel1: TBevel;
    sbUp: TSpeedButton;
    sbDown: TSpeedButton;
    lbSummaryLayout: TListBox;
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
    lSI10: TLabel;
    lSI11: TLabel;
    lSI9: TLabel;
    lSI12: TLabel;
    cbIncludeImages: TCheckBox;
    lSI13: TLabel;
    lSI14: TLabel;
    Label3: TLabel;
    lImportant: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    lSI15: TLabel;
    lSI16: TLabel;
    cbLayoutSize: TComboBox;
    pCategoryOptions: TPanel;
    clbCategoryOptions: TCheckListBox;
    bCloseAC: TSpeedButton;
    bAdvanced: TBitBtn;
    lAC: TLabel;
    bSaveAs: TBitBtn;
    bOK: TBitBtn;
    sdHTML: TSaveDialog;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    procedure sbRemoveClick(Sender: TObject);
    procedure sbUpClick(Sender: TObject);
    procedure sbDownClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    function  BuildSummaryLayout(htmlRL : THTMLReportOptions): THTMLReportOptions;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure lSI1Click(Sender: TObject);
    procedure lbSummaryLayoutClick(Sender: TObject);
    procedure bCloseACClick(Sender: TObject);
    procedure bAdvancedClick(Sender: TObject);
    procedure bSaveAsClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
  private
    LayoutItems : array[1..HTMLItemsCount] of TLabel;
    OldReport : THTMLReportOptions;  public
  end;


var
  frmCustomHTML: TfrmCustomHTML;


function GetHTMLReportLayout(htmlRL : THTMLReportOptions; OldDataOnCancel : boolean): THTMLReportOptions;


implementation


{$R *.dfm}


function GetHTMLReportLayout(htmlRL : THTMLReportOptions; OldDataOnCancel : boolean): THTMLReportOptions;
 var
  t : integer;
  
 begin
  with TfrmCustomHTML.Create(Application) do
    try
      // =======================================================================

      if Not(OldDataOnCancel) then
        bOK.BringToFront;

      OldReport := htmlRL;

      for t := 1 to 19 do begin
        clbCategoryOptions.Items.Add(TypeDescriptions[t]);

        if htmlRL.CategoryList[t] = '1' then
          clbCategoryOptions.Checked[t - 1] := True;
      end;

      // =======================================================================

      ShowModal;

      if ModalResult = mrOK then begin
        Result := BuildSummaryLayout(htmlRL);
      end
      else begin
        if OldDataOnCancel then
          Result := htmlRL
        else begin
          htmlRL.Layout := '$';

          Result := htmlRL
        end;
      end;

      // =======================================================================

    finally
      Free;
    end;
end;

procedure TfrmCustomHTML.FormCreate(Sender: TObject);
 var
  t : integer;

 begin
  cbLayoutSize.Items.Add('800 x 600');
  cbLayoutSize.Items.Add('1024 x 768');
  cbLayoutSize.Items.Add('1280 x 1024'); 

  LayoutItems[1]  := lSI1;   LayoutItems[2]  := lSI2;
  LayoutItems[3]  := lSI3;   LayoutItems[4]  := lSI4;
  LayoutItems[5]  := lSI5;   LayoutItems[6]  := lSI6;
  LayoutItems[7]  := lSI7;   LayoutItems[8]  := lSI8;
  LayoutItems[9]  := lSI9;   LayoutItems[10] := lSI10;
  LayoutItems[11] := lSI11;  LayoutItems[12] := lSI12;
  LayoutItems[13] := lSI13;  LayoutItems[14] := lSI14;
  LayoutItems[15] := lSI15;  LayoutItems[16] := lSI16;

  bSave.Caption   := XText[rsSave];
  bCancel.Caption := XText[rsCancel];

  for t := 1 to HTMLItemsCount do begin
    LayoutItems[t].Caption := GenericReportItems[t];
  end;
end;

procedure TfrmCustomHTML.FormShow(Sender: TObject);
 var
  t, lLayoutID : integer;
  s : string;

 begin
  s := '';
  for t := 1 to length(oldReport.Layout) do begin
    if oldReport.Layout[t] = ':' then begin
      lLayoutID := StrToIntDef(s, 99);

      if lLayoutID <= HTMLItemsCount then begin
        if lLayoutID = 0 then
          cbIncludeImages.Checked := True
        else
          lbSummaryLayout.Items.Add(LayoutItems[lLayoutID].Caption);
      end;

      s := '';
    end
    else
      s := s + oldReport.Layout[t];
  end;

  cbLayoutSize.ItemIndex   := OldReport.LayoutSize - 1;

  //== languagey stuff =========================================================
  Caption                  := XText[rsCustomise] + ' HTML ' + XText[rsReportLayout];
  Label1.Caption           := XText[rsAvailable] + ' HTML ' + XText[rsReportItems];
  Label2.Caption           := 'HTML ' + XText[rsReportLayout];
  cbIncludeImages.Caption  := XText[rsIncludeImages];
  GroupBox1.Caption        := XText[rsClickToAdd];
  lImportant.Caption       := XText[rsMaySlowDownReport];
  bCloseAC.Caption         := XText[rsHide];
  lAC.Caption              := XText[rsSelectCategories];
  bAdvanced.Caption        := XText[rsAdvanced];
  bSaveAs.Caption          := XText[rsSaveAs];
end;

procedure TfrmCustomHTML.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;

procedure TfrmCustomHTML.sbRemoveClick(Sender: TObject);
 begin
  lbSummaryLayout.DeleteSelected;

  sbRemove.Enabled := False;
  sbUp.Enabled     := False;
  sbDown.Enabled   := False;
end;

procedure TfrmCustomHTML.sbUpClick(Sender: TObject);
 var
  a : integer;

 begin
  if lbSummaryLayout.ItemIndex > 0 then begin
    a:=lbSummaryLayout.ItemIndex - 1;

    lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex - 1);

    lbSummaryLayout.ItemIndex := a;
  end;
end;

procedure TfrmCustomHTML.sbDownClick(Sender: TObject);
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

function TfrmCustomHTML.BuildSummaryLayout(htmlRL : THTMLReportOptions): THTMLReportOptions;
 var
  t,z,idx : integer;
  s : string;

 begin
  s := '';

  if cbIncludeImages.Checked then
    s := s + '0:';

  for t := 0 to lbSummaryLayout.Count - 1 do begin
    idx := 0;

    for z := 1 to HTMLItemsCount do begin
      if LayoutItems[z].Caption = lbSummaryLayout.Items[t] then idx := z;
    end;

    s := s + IntToStr(idx) + ':';
  end;

  htmlRL.Layout     := s;
  htmlRL.LayoutSize := cbLayoutSize.ItemIndex + 1;

  s := '';
  for t := 1 to 19 do
    s := s + IntToStr(TConvert.BoolToInteger(clbCategoryOptions.Checked[t - 1]));

  htmlRL.CategoryList := s;

  Result := htmlRL;
end;

procedure TfrmCustomHTML.lSI1Click(Sender: TObject);
 begin
  if lbSummaryLayout.Items.IndexOf(TLabel(Sender).Caption) = -1 then begin
    lbSummaryLayout.Items.Add(TLabel(Sender).Caption);
  end;
end;

procedure TfrmCustomHTML.lbSummaryLayoutClick(Sender: TObject);
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

  if status then begin
    if lbSummaryLayout.Items[lbSummaryLayout.ItemIndex] = lSI7.Caption then
      bAdvanced.Enabled := True
    else
      bAdvanced.Enabled := False;
  end
  else
    bAdvanced.Enabled := False;
end;

procedure TfrmCustomHTML.bCloseACClick(Sender: TObject);
 begin
  pCategoryOptions.SendToBack;
  pCategoryOptions.Visible := False;
end;

procedure TfrmCustomHTML.bAdvancedClick(Sender: TObject);
 begin
  pCategoryOptions.BringToFront;
  pCategoryOptions.Visible := True;
end;

procedure TfrmCustomHTML.bSaveAsClick(Sender: TObject);
 var
  tf : TextFile;
  tempHTML : THTMLReportOptions;

 begin
  sdHTML.InitialDir := GSystemGlobal.UsersPath + 'Saves\Custom Reports';
  sdHTML.Filter     := XText[rsCustomReportFiles] + ' (*.xcrhtml)|*.xcrhtml';

  if sdHTML.Execute then begin
    AssignFile(tf, sdHTML.Filename);

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsWarning],
                  XText[rsErrorSaving] + ' "' + sdHTML.FileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      tempHTML := BuildSummaryLayout(tempHTML);

      Writeln(tf, tempHTML.Layout);
      Writeln(tf, tempHTML.CategoryList);
      Writeln(tf, IntToStr(tempHTML.LayoutSize));

      CloseFile(tf);
    end;
    {$I+}
  end;
end;

procedure TfrmCustomHTML.SpeedButton1Click(Sender: TObject);
 var
  t : integer;

 begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := True;
end;

procedure TfrmCustomHTML.SpeedButton2Click(Sender: TObject);
 var
  t : integer;

 begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := False;
end;

end.
