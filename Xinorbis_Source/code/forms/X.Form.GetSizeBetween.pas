unit X.Form.GetSizeBetween;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  ExtCtrls, StdCtrls, Buttons;

type
  TfrmGetFileSize = class(TForm)
    Label1: TLabel;
    cbFrom: TComboBox;
    eFrom: TEdit;
    Label2: TLabel;
    cbTo: TComboBox;
    eTo: TEdit;
    Label3: TLabel;
    bOK: TBitBtn;
    BitBtn2: TBitBtn;
    Bevel1: TBevel;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmGetFileSize: TfrmGetFileSize;

function GetSizeDialog: string;


implementation

{$R *.dfm}


function GetSizeDialog: string;
 begin
  with TfrmGetFileSize.Create(Application) do
    try
      ShowModal;

      if ModalResult=mrOK then
        Result:='(size>'+eFrom.Text+cbFrom.Text+') (size<'+eTo.Text+cbTo.Text+')'
      else
        Result:='';
    except
      free;
  end;
end;


end.
