//
// (c) Paul Alan Freshney 2006-2019
//
// Modified: January 16th 2019
//
// 89

unit X.Form.ShowMD5;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls, Buttons,

  X.LanguageHandler;

type
  TfrmMD5 = class(TForm)
    bCancel: TBitBtn;
    Label1: TLabel;
    lMD5: TLabel;
    bCopy: TBitBtn;
    Bevel1: TBevel;
    Shape1: TShape;
    lFilename: TLabel;
    procedure bCancelClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure bCopyClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmMD5: TfrmMD5;

procedure ShowMD5Checksum(const fn, md5 : string);


implementation

{$R *.dfm}

uses
  clipbrd, X.Utility, X.Global, X.Constants;


procedure ShowMD5Checksum(const fn, md5 : string);
 begin
  with TfrmMD5.Create(Application) do
    try
      lFilename.Caption := fn;
      lMD5.Caption      := md5;

      ShowModal;
    finally
      free;
  end;
end;


procedure TfrmMD5.FormCreate(Sender: TObject);
 begin
  bCopy.Caption   := XText[rsCopy];
  bCancel.Caption := XText[rsCancel];
end;


procedure TfrmMD5.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;


procedure TfrmMD5.bCancelClick(Sender: TObject);
 begin
  Close;
end;


procedure TfrmMD5.bCopyClick(Sender: TObject);
 begin
  Clipboard.AsText := lMD5.Caption;
end;


end.
