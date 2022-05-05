// (c) Paul Alan Freshney 2006-2011
//
// Modified: December 16th 2010
//
// 146

unit X.Form.ExcludeFolders;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Buttons, StdCtrls, ExtCtrls, Menus,

  X.Utility, X.Global, X.Constants, X.LanguageHandler,

  X.Windows, X.SystemGlobal, Vcl.Dialogs, AdvOfficeButtons;

type
  TfrmExcludedFolders = class(TForm)
    lbExcluded: TListBox;
    sbAdd: TSpeedButton;
    bOK: TBitBtn;
    Bevel1: TBevel;
    sbRemove: TSpeedButton;
    bCancel: TBitBtn;
    sbEdit: TSpeedButton;
    sbSpecial: TSpeedButton;
    puSF: TPopupMenu;
    miSF1: TMenuItem;
    miSF2: TMenuItem;                                       
    miSF3: TMenuItem;
    miSF4: TMenuItem;
    bSave: TBitBtn;
    bOpen: TBitBtn;
    sdExclude: TSaveDialog;
    odExclude: TOpenDialog;
    cbIgnoreVirtual: TAdvOfficeCheckBox;
    procedure sbAddClick(Sender: TObject);
    procedure lbExcludedClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure sbEditClick(Sender: TObject);
    procedure sbRemoveClick(Sender: TObject);
    procedure sbSpecialClick(Sender: TObject);
    procedure miSF1Click(Sender: TObject);
    procedure bSaveClick(Sender: TObject);
    procedure bOpenClick(Sender: TObject);
    procedure ToggleSave;
  private
    { Private declarations }
  public
    { Public declarations }
  end;


var
  frmExcludedFolders: TfrmExcludedFolders;


procedure DoExcludedFolders(var tef : TStringList; var aIV : boolean);


implementation


{$R *.dfm}


procedure DoExcludedFolders(var tef : TStringList; var aIV : boolean);
 var
  t : integer;

 begin
  with TfrmExcludedFolders.Create(Application) do
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

        aIV := cbIgnoreVirtual.Checked;
      end;
    finally
      free;
    end;
end;

procedure TfrmExcludedFolders.bOpenClick(Sender: TObject);
 begin
  odExclude.InitialDir := GSystemGlobal.ExePath + 'data\';
  odExclude.Filter     := XText[rsTextFiles] + ' (*.txt)|*.txt';
  odExclude.DefaultExt := '.txt';

  if odExclude.Execute then begin
    lbExcluded.Items.LoadFromFile(odExclude.FileName);
  end;
end;

procedure TfrmExcludedFolders.bSaveClick(Sender: TObject);
 begin
  sdExclude.InitialDir := GSystemGlobal.ExePath + 'data\';
  sdExclude.Filter     := XText[rsTextFiles] + ' (*.txt)|*.txt';
  sdExclude.DefaultExt := '.txt';

  if sdExclude.Execute then begin
    lbExcluded.Items.SaveToFile(sdExclude.FileName);
  end;
end;

procedure TfrmExcludedFolders.FormCreate(Sender: TObject);
 begin
  Caption                 := XText[rsExcludeFromScan];
  cbIgnoreVirtual.Caption := XText[rsIgnoreVirtualFolders];
  bCancel.Caption         := XText[rsCancel];
  sbSpecial.Caption       := XText[rsSpecial];
  bSave.Caption           := XText[rsSave];
  bOpen.Caption           := XText[rsOpen];

  miSF1.Caption := TXWindows.GetSpecialFolder(1);
  miSF2.Caption := TXWindows.GetSpecialFolder(2);
  miSF3.Caption := TXWindows.GetSpecialFolder(3);
  miSF4.Caption := TXWindows.GetSpecialFolder(4);
end;

procedure TfrmExcludedFolders.sbAddClick(Sender: TObject);
 var
  s : string;

 begin
  s := TXWindows.BrowseForFolder(Handle);

  if s <> '' then begin
    lbExcluded.Items.Add(s + '*');

    ToggleSave;
  end;
end;

procedure TfrmExcludedFolders.lbExcludedClick(Sender: TObject);
 begin
  if lbExcluded.ItemIndex <> -1 then begin
    sbRemove.Enabled := True;
    sbEdit.Enabled   := True;
  end
  else begin
    sbRemove.Enabled := False;
    sbEdit.Enabled   := False;
  end;
end;

procedure TfrmExcludedFolders.sbEditClick(Sender: TObject);
 var
  s : string;

 begin
  s := InputBox(XText[rsEditExclusion], XText[rsEdit], lbExcluded.Items[lbExcluded.ItemIndex]);

  if s <> '' then
    lbExcluded.Items[lbExcluded.ItemIndex] := s;
end;

procedure TfrmExcludedFolders.sbRemoveClick(Sender: TObject);
 begin
  lbExcluded.DeleteSelected;

  ToggleSave;
end;

procedure TfrmExcludedFolders.sbSpecialClick(Sender: TObject);
 begin
  puSF.Popup(Left + sbSpecial.Left, Top + 55);
end;

procedure TfrmExcludedFolders.miSF1Click(Sender: TObject);
 begin
  lbExcluded.Items.Add(TMenuItem(Sender).Caption + '*');
end;

procedure TfrmExcludedFolders.ToggleSave;
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
