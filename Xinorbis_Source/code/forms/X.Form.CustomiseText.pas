// (c) Paul Alan Freshney 2006-2011
//
// Modified: December 16th 2010
//
// 357

unit X.Form.CustomiseText;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, ExtCtrls,

  X.Utility, CheckLst, X.Settings, X.CReportOptions, X.LanguageHandler,
  X.SystemGlobal;

type
  TfrmCustomText = class(TForm)
    Label1: TLabel;
    GroupBox1: TGroupBox;
    lSI1: TLabel;
    lSI2: TLabel;
    lSI3: TLabel;
    lSI4: TLabel;
    lSI5: TLabel;
    lSI8: TLabel;
    lSI7: TLabel;
    lSI6: TLabel;
    sbRemove: TSpeedButton;
    sbUp: TSpeedButton;
    sbDown: TSpeedButton;
    Bevel1: TBevel;
    Label2: TLabel;
    bSave: TBitBtn;
    bCancel: TBitBtn;
    lbSummaryLayout: TListBox;
    lSI12: TLabel;
    lSI11: TLabel;
    lSI10: TLabel;
    lSI9: TLabel;
    lSI13: TLabel;
    lSI14: TLabel;
    lSI15: TLabel;
    lSI16: TLabel;
    pCategoryOptions: TPanel;
    bCloseAC: TSpeedButton;
    lAC: TLabel;
    clbCategoryOptions: TCheckListBox;
    bAdvanced: TBitBtn;
    bSaveAs: TBitBtn;
    bOK: TBitBtn;
    sdTEXT: TSaveDialog;
    Label3: TLabel;
    lImportant: TLabel;
    Label6: TLabel;
    Label5: TLabel;
    Label4: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    function  BuildSummaryLayout(textRL : TTextReportOptions): TTextReportOptions;
    procedure FormCreate(Sender: TObject);
    procedure sbRemoveClick(Sender: TObject);
    procedure sbUpClick(Sender: TObject);
    procedure sbDownClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure lbSummaryLayoutDblClick(Sender: TObject);
    procedure lSI1Click(Sender: TObject);
    procedure lbSummaryLayoutClick(Sender: TObject);
    procedure bAdvancedClick(Sender: TObject);
    procedure bCloseACClick(Sender: TObject);
    procedure bSaveAsClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
  private
    LayoutItems : array[1..16] of TLabel;
    OldLayout : TTextReportOptions;
  public
    { Public declarations }
  end;

var
  frmCustomText: TfrmCustomText;


function GetTextReportLayout(textRL : TTextReportOptions; OldDataOnCancel : boolean): TTextReportOptions;


implementation

{$R *.dfm}


uses
  X.Global, X.Dialogs.Dialog, X.Constants, X.Conversions;


const
 TextItemsCount = 16;


function GetTextReportLayout(textRL : TTextReportOptions; OldDataOnCancel : boolean): TTextReportOptions;
 var
  t : integer;
  
 begin
  with TfrmCustomText.Create(Application) do
    try

      // =======================================================================

      OldLayout := textRL;

      if Not(OldDataOnCancel) then
        bOK.BringToFront;

      for t := 1 to 19 do begin
        clbCategoryOptions.Items.Add(TypeDescriptions[t]);

        if textRL.CategoryList[t] = '1' then
          clbCategoryOptions.Checked[t - 1] := True;
      end;

      // =======================================================================

      ShowModal;

      if ModalResult = mrOK then begin
        Result := BuildSummaryLayout(textRL);
      end
      else begin
        if OldDataOnCancel then
          Result := textRL
        else begin
          textRL.Layout := '$';

          Result := textRL
        end;
      end;

      // =======================================================================

    finally
      Free;
    end;
end;

procedure TfrmCustomText.FormCreate(Sender: TObject);
 var
  t : integer;

 begin
  LayoutItems[1] := lSI1;   LayoutItems[2] := lSI2;
  LayoutItems[3] := lSI3;   LayoutItems[4] := lSI4;
  LayoutItems[5] := lSI5;   LayoutItems[6] := lSI6;
  LayoutItems[7] := lSI7;   LayoutItems[8] := lSI8;
  LayoutItems[9] := lSI9;   LayoutItems[10] := lSI10;
  LayoutItems[11] := lSI11; LayoutItems[12] := lSI12;
  LayoutItems[13] := lSI13; LayoutItems[14] := lSI14;
  LayoutItems[15] := lSI15; LayoutItems[16] := lSI16;

  bSave.Caption   := XText[rsSave];
  bCancel.Caption := XText[rsCancel];

  for t := 1 to TextItemsCount do begin
    LayoutItems[t].Caption := OtherReportItems[t];
  end;
end;

procedure TfrmCustomText.FormShow(Sender: TObject);
 var
  t, lLayoutID : integer;
  s : string;

 begin
  s := '';

  for t := 1 to length(OldLayout.Layout) do begin
    if OldLayout.Layout[t] = ':' then begin
      lLayoutID := StrToIntDef(s, 99);

      if lLayoutID <= TextItemsCount then begin
        lbSummaryLayout.Items.Add(LayoutItems[lLayoutID].Caption);
      end;

      s := '';
    end
    else
      s := s + OldLayout.Layout[t];
  end;

  //== languagey stuff =========================================================
  Caption                  := XText[rsCustomise] + ' ' + XText[rsText] + ' ' + XText[rsReportLayout];
  lImportant.Caption       := XText[rsMaySlowDownReport];
  Label1.Caption           := XText[rsAvailable] + ' ' + XText[rsText] + ' ' + XText[rsReportItems];
  Label2.Caption           := XText[rsText] + ' ' + XText[rsReportLayout];
  bCloseAC.Caption         := XText[rsHide];
  lAC.Caption              := XText[rsSelectCategories];
  bAdvanced.Caption        := XText[rsAdvanced];
  bSaveAs.Caption          := XText[rsSaveAs];
end;

procedure TfrmCustomText.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;

function TfrmCustomText.BuildSummaryLayout(textRL : TTextReportOptions): TTextReportOptions;
 var
  t,z,idx : integer;
  s : string;

 begin
  s := '';

  for t := 0 to lbSummaryLayout.Count - 1 do begin
    idx := 0;

    for z := 1 to TextItemsCount do begin
      if LayoutItems[z].Caption = lbSummaryLayout.Items[t] then idx := z;
    end;

    s := s + IntToStr(idx) + ':';
  end;

  textRL.Layout := s;

  s := '';
  for t := 1 to 19 do
    s := s + IntToStr(TConvert.BoolToInteger(clbCategoryOptions.Checked[t - 1]));

  textRL.CategoryList := s;

  Result := textRL;
end;

procedure TfrmCustomText.sbRemoveClick(Sender: TObject);
 begin
  lbSummaryLayout.DeleteSelected;
end;

procedure TfrmCustomText.sbUpClick(Sender: TObject);
var
  a : integer;

begin
  if lbSummaryLayout.ItemIndex > 0 then begin
    a:=lbSummaryLayout.ItemIndex - 1;

    lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex - 1);

    lbSummaryLayout.ItemIndex := a;
  end;
end;

procedure TfrmCustomText.sbDownClick(Sender: TObject);
 var
  a : integer;

 begin
  if lbSummaryLayout.ItemIndex <> -1 then begin
    if lbSummaryLayout.ItemIndex < lbSummaryLayout.Count - 1 then begin
      a := lbSummaryLayout.ItemIndex + 1;

      lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex + 1);

      lbSummaryLayout.ItemIndex := a;
    end;
  end;
end;

procedure TfrmCustomText.lbSummaryLayoutDblClick(Sender: TObject);
 begin
  lbSummaryLayout.DeleteSelected;

  sbRemove.Enabled := False;
  sbUp.Enabled     := False;
  sbDown.Enabled   := False;
end;

procedure TfrmCustomText.lSI1Click(Sender: TObject);
 begin
  if lbSummaryLayout.Items.IndexOf(TLabel(Sender).Caption) = -1 then begin
    lbSummaryLayout.Items.Add(TLabel(Sender).Caption);
  end;
end;

procedure TfrmCustomText.lbSummaryLayoutClick(Sender: TObject);
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

procedure TfrmCustomText.bAdvancedClick(Sender: TObject);
 begin
  pCategoryOptions.BringToFront;
  pCategoryOptions.Visible := True;
end;

procedure TfrmCustomText.bCloseACClick(Sender: TObject);
 begin
  pCategoryOptions.SendToBack;
  pCategoryOptions.Visible := False;
end;

procedure TfrmCustomText.bSaveAsClick(Sender: TObject);
 var
  tf : TextFile;
  tempTEXT : TTextReportOptions;

 begin
  sdTEXT.InitialDir := GSystemGlobal.UsersPath + 'Saves\Custom Reports';
  sdTEXT.Filter     := XText[rsCustomReportFiles] + ' (*.xcrtext)|*.xcrtext';

  if sdTEXT.Execute then begin
    AssignFile(tf, sdTEXT.Filename);

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorSavingReport],
                  XText[rsErrorSaving] + ' "' + sdText.FileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      tempTEXT := BuildSummaryLayout(tempTEXT);

      Writeln(tf, tempTEXT.Layout);
      Writeln(tf, tempTEXT.CategoryList);

      CloseFile(tf);
    end;
    {$I+}
  end;
end;

procedure TfrmCustomText.SpeedButton1Click(Sender: TObject);
 var
  t : integer;

 begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := True;
end;

procedure TfrmCustomText.SpeedButton2Click(Sender: TObject);
 var
  t : integer;

 begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := False;
end;

end.
