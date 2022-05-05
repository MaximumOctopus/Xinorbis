// (c) Paul Alan Freshney 2006-2011
//
// Modified: December 16th 2010
//
// 70

unit X.Form.GetCopyMove;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, Buttons, ExtCtrls,

  shellAPI, X.Utility, X.Global, X.Constants,

  X.Windows, X.LanguageHandler;


type
  TfrmGetCopyMove = class(TForm)
    lTitle: TLabel;
    SpeedButton1: TSpeedButton;
    Bevel1: TBevel;
    bSave: TBitBtn;
    bCancel: TBitBtn;
    eFolder: TEdit;
    procedure SpeedButton1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmGetCopyMove: TfrmGetCopyMove;

function GetCopyMoveFolder(const xtitle : string): string;



implementation

{$R *.dfm}


function GetCopyMoveFolder(const xtitle : string): string;
 begin
  with TfrmGetCopyMove.Create(Application) do
    try
      Result := '';

      bCancel.Caption := XText[rsCancel];

      Caption        := xtitle;
      lTitle.Caption := xtitle;

      ShowModal;

      if ModalResult = mrOK then begin
        Result := eFolder.Text;
      end;
    finally
      free;
  end;
end;

procedure TfrmGetCopyMove.SpeedButton1Click(Sender: TObject);
 var
  str : string;

 begin
  str := TXWindows.BrowseForFolder(Handle);

  if str <> '' then begin
    eFolder.Text := str;
  end;
end;


end.
