// (c) Paul Alan Freshney 2006-2011
//
// Modified: December 16th 2010
//
// 173

unit X.Form.CustomiseTree;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, CheckLst, Buttons, ExtCtrls, AdvOfficeButtons,

  X.Utility, X.Settings, X.CReportOptions, X.LanguageHandler, X.SystemGlobal;


type
  TfrmCustomiseTree = class(TForm)
    bOK: TBitBtn;
    bSaveAs: TBitBtn;
    bSave: TBitBtn;
    bCancel: TBitBtn;
    gbCategories: TGroupBox;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    clbCategoryOptions: TCheckListBox;
    gbOptions: TGroupBox;
    sdTree: TSaveDialog;
    cbFileSize: TAdvOfficeCheckBox;
    cbAttributes: TAdvOfficeCheckBox;
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    function  BuildSummaryLayout(treeRL : TTreeReportOptions): TTreeReportOptions;
    procedure FormShow(Sender: TObject);
    procedure bSaveAsClick(Sender: TObject);
  private
    OldReport : TTreeReportOptions;
  public
    { Public declarations }
  end;

var
  frmCustomiseTree: TfrmCustomiseTree;


function GetTreeReportLayout(treeRL : TTreeReportOptions; OldDataOnCancel : boolean): TTreeReportOptions;


implementation

{$R *.dfm}


uses
  X.Global, X.Dialogs.Dialog, X.Constants, X.Conversions;


function GetTreeReportLayout(treeRL : TTreeReportOptions; OldDataOnCancel : boolean): TTreeReportOptions;
 var
  t : integer;

 begin
  with TfrmCustomiseTree.Create(Application) do
    try
      // =======================================================================

      if Not(OldDataOnCancel) then
        bOK.BringToFront;

      OldReport := treeRL;

      for t := 1 to 19 do begin
        clbCategoryOptions.Items.Add(TypeDescriptions[t]);

        if treeRL.CategoryList[t] = '1' then
          clbCategoryOptions.Checked[t - 1] := True;
      end;

      cbFileSize.Checked   := treeRL.IncludeSize;
      cbAttributes.Checked := treeRL.IncludeAttributes;

      // =======================================================================

      ShowModal;

      if ModalResult=mrOK then begin
        Result := BuildSummaryLayout(treeRL);
      end
      else begin
        if OldDataOnCancel then
          Result := treeRL
        else begin
          treeRL.Layout := '$';

          Result := treeRL
        end;
      end;

      // =======================================================================

    finally
      Free;
    end;
end;


procedure TfrmCustomiseTree.FormShow(Sender: TObject);
 begin
  Caption              := XText[rsCustomise] + ' Tree ' + XText[rsReportLayout];
  gbOptions.Caption    := XText[rsOutputOptions];
  cbFileSize.Caption   := XText[rsFileSize];
  cbAttributes.Caption := XText[rsFileAttributes];
  gbCategories.Caption := XText[rsSelectCategories];
  bCancel.Caption      := XText[rsCancel];
  bSave.Caption        := XText[rsSave];
  bSaveAs.Caption      := XText[rsSaveAs];
end;


procedure TfrmCustomiseTree.SpeedButton1Click(Sender: TObject);
 var
  t : integer;

 begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := True;
end;


procedure TfrmCustomiseTree.SpeedButton2Click(Sender: TObject);
 var
  t : integer;

 begin
  for t := 0 to clbCategoryOptions.Count - 1 do
    clbCategoryOptions.Checked[t] := False;
end;


function TfrmCustomiseTree.BuildSummaryLayout(treeRL : TTreeReportOptions): TTreeReportOptions;
 var
  t : integer;
  s : string;

 begin
  s := '';

  for t := 1 to 19 do
    s := s + IntToStr(TConvert.BoolToInteger(clbCategoryOptions.Checked[t - 1]));

  treeRL.CategoryList      := s;
  treeRL.IncludeSize       := cbFileSize.Checked;
  treeRL.IncludeAttributes := cbAttributes.Checked;

  Result := treeRL;
end;


procedure TfrmCustomiseTree.bSaveAsClick(Sender: TObject);
 var
  tf : TextFile;
  tempTree : TTreeReportOptions;

 begin
  sdTree.InitialDir := GSystemGlobal.UsersPath + 'Saves\Custom Reports';
  sdTree.Filter     := XText[rsCustomReportFiles] + ' (*.xcrtree)|*.xcrtree';

  if sdTree.Execute then begin
    AssignFile(tf, sdTree.Filename);

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorSavingReport] + ' (Tree)',
                  XText[rsErrorSaving] + ' "' + sdTree.FileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      tempTree := BuildSummaryLayout(tempTree);

      Writeln(tf, IntToStr(TConvert.BoolToInteger(tempTree.IncludeSize)));
      Writeln(tf, IntToStr(TConvert.BoolToInteger(tempTree.IncludeAttributes)));
      Writeln(tf, tempTree.CategoryList);

      CloseFile(tf);
    end;
    {$I+}
  end;
end;


end.
