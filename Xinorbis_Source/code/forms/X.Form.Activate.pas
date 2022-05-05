unit X.Form.Activate;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons,

  X.LanguageHandler, X.PurchaseUtility, X.Utility, X.Windows, X.SystemGlobal;

type
  TfrmActivate = class(TForm)
    GroupBox1: TGroupBox;
    eEmail: TEdit;
    lEmailAddress: TLabel;
    lActivationKey: TLabel;
    eActivationCode: TEdit;
    bOK: TBitBtn;
    bCancel: TBitBtn;
    lHow: TLabel;
    lTrial: TLabel;
    BitBtn1: TBitBtn;
    BitBtn2: TBitBtn;
    lName: TLabel;
    eName: TEdit;
    procedure bOKClick(Sender: TObject);
    procedure eActivationCodeChange(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmActivate: TfrmActivate;

function ShowActivate: word;


implementation

{$R *.dfm}


uses
  X.Global, X.Settings, X.Constants, X.Dialogs.Dialog;


function ShowActivate: word;
 begin
  with TfrmActivate.Create(Application) do
    try
      ShowModal;

      Result := ModalResult;
    finally
      free;
    end;
end;


procedure TfrmActivate.FormCreate(Sender: TObject);
 begin
  lName.Caption          := XText[rsName];
  lEmailAddress.Caption  := XText[rsEmailAddress];
  lActivationKey.Caption := XText[rsActivationKey];
end;


procedure TfrmActivate.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;


procedure TfrmActivate.bOKClick(Sender: TObject);
 var
   tf : TextFile;

 begin
  if TPurchaseUtility.CheckActivationCode(eName.Text, eEmail.Text, eActivationCode.Text) then begin
    AssignFile(tf, GSystemGlobal.UsersPath + 'registration.data');

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsWarning],
                  XText[rsErrorSaving] + ' "' + GSystemGlobal.UsersPath + 'registration.data".' + #13#13 + 'Make sure this folder is read/write!',
                  XDialogTypeWarning);
    end
    else begin    Rewrite(tf);
      writeln(tf, eName.Text);
      writeln(tf, eEmail.Text);
      writeln(tf, eActivationCode.Text);

      CloseFile(tf);

      ModalResult := mrOK;
    end;
    {$I+}
  end
  else begin
    ShowXDialog(XText[rsWarning],
                XText[rsInvalidNameEmailCodeCombination],
                XDialogTypeWarning);
  end;
end;


procedure TfrmActivate.eActivationCodeChange(Sender: TObject);
 begin
  if eActivationCode.Text = '' then
    bOK.Enabled := False
  else
    bOK.Enabled := True;
end;


procedure TfrmActivate.BitBtn1Click(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'http://www.xinorbis.com/buy.htm', '', '')
end;


procedure TfrmActivate.BitBtn2Click(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, 'mailto:xinorbis@maximumoctopus.com?Subject=Xinorbis Suggestions', '', '');
end;


end.
