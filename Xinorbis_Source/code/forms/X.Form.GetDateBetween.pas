unit X.Form.GetDateBetween;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, Buttons, ComCtrls, ExtCtrls;

type
  TForm2 = class(TForm)
    BitBtn1: TBitBtn;
    BitBtn2: TBitBtn;
    Bevel1: TBevel;
    mcFrom: TMonthCalendar;
    Label1: TLabel;
    Label2: TLabel;
    mcTo: TMonthCalendar;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;

function GetDateDialog(datecontext : string): string;

implementation

{$R *.dfm}


uses
  X.Conversions, X.Utility;

// TO DO, change To and From to include selected dates

function GetDateDialog(datecontext : string): string;
var
  str : string;

begin
  str := '';

  with TForm2.Create(Application) do
    try
      mcFrom.Date := IncMonth(Now, -1);
      mcTo.Date   := Now;

      ShowModal;

      if ModalResult=mrOK then
        Result := '(' + datecontext + '>' + TConvert.DateToYYYYMMDD(mcFrom.Date) + ') (' + datecontext + '<' + TConvert.DateToYYYYMMDD(mcTo.Date) + ')'
      else
        Result := '';
    except
      free;
  end;
end;

end.
