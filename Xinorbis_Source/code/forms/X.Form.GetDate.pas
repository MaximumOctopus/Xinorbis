unit X.Form.GetDate;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, Buttons, ComCtrls;

type
  TForm2 = class(TForm)
    cMain: TMonthCalendar;
    BitBtn1: TBitBtn;
    BitBtn2: TBitBtn;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;

function GetDate: TDateTime;

implementation

{$R *.dfm}

function GetDate: TDateTime;
 var
  temp,str : string;
  t,ret,i : integer;
  bob : TListItem;

 begin
  str:='';

  with TForm2.Create(Application) do
    try
      cMain.Date:=Now;

      ShowModal;

      if ModalResult=mrOK then
        Result:=cMain.Date;
      else
        Result:=IncMonth(Now, 1);

    except
      free;
  end;
  
  Result:=str;
end;

end.
