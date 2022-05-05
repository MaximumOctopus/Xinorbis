// (c) Paul Alan Freshney 2006-2011
//
// Modified: December 16th 2010
//
// 123

unit X.Form.ExcludeFiles;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, Buttons, ExtCtrls,

  X.LanguageHandler, X.SystemGlobal, Vcl.Dialogs;

type
  TfrmExcludedFiles = class(TForm)
    sbAdd: TSpeedButton;
    Bevel1: TBevel;
    sbRemove: TSpeedButton;
    sbEdit: TSpeedButton;
    lbExcluded: TListBox;
    bOK: TBitBtn;
    bCancel: TBitBtn;
    ePattern: TEdit;
    lPatternToExclude: TLabel;
    Label1: TLabel;
    bSave: TBitBtn;
    bOpen: TBitBtn;
    odExclude: TOpenDialog;
    sdExclude: TSaveDialog;
    procedure FormCreate(Sender: TObject);
    procedure sbAddClick(Sender: TObject);
    procedure lbExcludedClick(Sender: TObject);
    procedure sbEditClick(Sender: TObject);
    procedure sbRemoveClick(Sender: TObject);
    procedure ePatternKeyPress(Sender: TObject; var Key: Char);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure bOpenClick(Sender: TObject);
    procedure bSaveClick(Sender: TObject);
    procedure ToggleSave;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmExcludedFiles: TfrmExcludedFiles;

procedure DoExcludedFiles(var tef : TStringList);

implementation

{$R *.dfm}


uses
  X.Utility, X.Global, X.Constants;


procedure DoExcludedFiles(var tef : TStringList);
 var
  t : integer;

 begin
  with TfrmExcludedFiles.Create(Application) do
    try
      if tef.Count <> 0 then begin
        for t := 0 to tef.Count - 1 do
          lbExcluded.Items.Add(tef.Strings[t]);
      end;

      ToggleSave;

      ShowModal;

      if ModalResult = mrOK then begin
        tef.Clear;

        for t := 0 to lbExcluded.Items.Count - 1 do
          tef.Add(lbExcluded.Items[t]);
      end;
    finally
      free;
    end;
end;


procedure TfrmExcludedFiles.FormCreate(Sender: TObject);
 begin
  Caption                   := XText[rsExcludeFilesFromScan];

  lPatternToExclude.Caption := XText[rsPatternToExclude];

  bSave.Caption             := XText[rsSave];
  bOpen.Caption             := XText[rsOpen];
  bCancel.Caption           := XText[rsCancel];
end;


procedure TfrmExcludedFiles.sbAddClick(Sender: TObject);
 begin
  if ePattern.Text <> '' then begin
    lbExcluded.Items.Add(ePattern.Text);

    ePattern.Text := '';

    ToggleSave;
  end;
end;


procedure TfrmExcludedFiles.lbExcludedClick(Sender: TObject);
 begin
  if lbExcluded.ItemIndex <> -1 then  begin
    sbRemove.Enabled := True;
    sbEdit.Enabled   := True;
  end
  else begin
    sbRemove.Enabled := False;
    sbEdit.Enabled   := False;
  end;
end;


procedure TfrmExcludedFiles.sbEditClick(Sender: TObject);
 var
  s : string;

 begin
  s := InputBox(XText[rsEditExclusion], XText[rsEdit], lbExcluded.Items[lbExcluded.ItemIndex]);

  if s <> '' then
    lbExcluded.Items[lbExcluded.ItemIndex] := s;
end;


procedure TfrmExcludedFiles.sbRemoveClick(Sender: TObject);
 begin
  lbExcluded.DeleteSelected;

  ToggleSave;
end;


procedure TfrmExcludedFiles.bOpenClick(Sender: TObject);
 begin
  odExclude.InitialDir := GSystemGlobal.ExePath + 'data\';
  odExclude.Filter     := XText[rsTextFiles] + ' (*.txt)|*.txt';
  odExclude.DefaultExt := '.txt';

  if odExclude.Execute then begin
    lbExcluded.Items.LoadFromFile(odExclude.FileName);
  end;
end;


procedure TfrmExcludedFiles.bSaveClick(Sender: TObject);
 begin
  sdExclude.InitialDir := GSystemGlobal.ExePath + 'data\';
  sdExclude.Filter     := XText[rsTextFiles] + ' (*.txt)|*.txt';
  sdExclude.DefaultExt := '.txt';

  if sdExclude.Execute then begin
    lbExcluded.Items.SaveToFile(sdExclude.FileName);
  end;
end;


procedure TfrmExcludedFiles.ePatternKeyPress(Sender: TObject; var Key: Char);
 begin
  if Key = #13 then
    sbAddClick(Nil);
end;


procedure TfrmExcludedFiles.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;


procedure TfrmExcludedFiles.ToggleSave;
 begin
  if lbExcluded.Items.Count = 0 then begin
    bSave.Enabled := False;
    bOK.Enabled   := False;
  end
  else begin
    bSave.Enabled := True;
    bOK.Enabled   := True;
  end;
end;


end.
