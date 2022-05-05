unit X.Splash.Print;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls;

type
  TfrmPrintDisplay = class(TForm)
    Image3: TImage;
    lPrinting: TLabel;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmPrintDisplay: TfrmPrintDisplay;

implementation

{$R *.dfm}

procedure TfrmPrintDisplay.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;

end.
