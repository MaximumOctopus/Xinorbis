// Report browser/view
//
//       Started: January 7th 2008
// Last Modified: June 19th 2009
//
// 67

unit X.Form.SearchSyntax;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, ExtCtrls, ComCtrls, OleCtrls, SHDocVw,

  X.LanguageHandler, X.SystemGlobal;

type
  TfrmSearchSyntax = class(TForm)
    bClose: TBitBtn;
    wbSearch: TWebBrowser;
    Panel1: TPanel;
    wbIndex: TWebBrowser;
    cbStayOnTop: TCheckBox;
    procedure bCloseClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure cbStayOnTopClick(Sender: TObject);
    procedure wbIndexBeforeNavigate2(ASender: TObject;
      const pDisp: IDispatch; const URL, Flags, TargetFrameName, PostData,
      Headers: OleVariant; var Cancel: WordBool);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;


var
  frmSearchSyntax: TfrmSearchSyntax;


procedure ShowSearchSyntax;


implementation

{$R *.dfm}

uses
  X.Utility, X.Global, X.Settings, X.Constants;


var
  languagesymbol : string;


procedure ShowSearchSyntax;
 begin
  with TfrmSearchSyntax.Create(Application) do
    try
      Show;
    except
      free;
    end;
end;


procedure TfrmSearchSyntax.FormCreate(Sender: TObject);
var
  lFormDetails : TFormDetails;

begin
  lFormDetails := XSettings.LoadFormDetails(_FormSearchSyntax);

  if lFormDetails.formID <> -1 then begin
    Left             := lFormDetails.x;
    Top              := lFormDetails.y;
    Width            := lFormDetails.w;
    Height           := lFormDetails.h;
  end;
end;


procedure TfrmSearchSyntax.FormClose(Sender: TObject; var Action: TCloseAction);
 var
  lFormDetails : TFormDetails;

 begin
  lFormDetails.formID := _FormSearchSyntax;
  lFormDetails.x      := Left;
  lFormDetails.y      := Top;
  lFormDetails.w      := Width;
  lFormDetails.h      := Height;

  XSettings.SaveFormDetails(lFormDetails);

  Action := caFree;
end;


procedure TfrmSearchSyntax.bCloseClick(Sender: TObject);
 begin
  Close;
end;


procedure TfrmSearchSyntax.cbStayOnTopClick(Sender: TObject);
 begin
  if (cbStayOnTop.Checked) then
    frmSearchSyntax.FormStyle := fsStayOnTop
  else
    frmSearchSyntax.FormStyle := fsNormal;
end;


procedure TfrmSearchSyntax.FormShow(Sender: TObject);
 begin
  languagesymbol := TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage);

  bClose.Caption := XText[rsClose];

  wbIndex.Navigate(GSystemGlobal.AppPath + 'data\languages\' + languagesymbol + '\search\sindex.htm');
  wbSearch.Navigate(GSystemGlobal.AppPath + 'data\languages\' + languagesymbol + '\search\index.htm');
end;


procedure TfrmSearchSyntax.wbIndexBeforeNavigate2(ASender: TObject;
  const pDisp: IDispatch; const URL, Flags, TargetFrameName, PostData,
  Headers: OleVariant; var Cancel: WordBool);
begin
  if Pos('sx:', URL) <> 0 then begin
    wbSearch.Navigate(GSystemGlobal.AppPath + 'data\languages\' + languagesymbol + '\search\' + Copy(URL, 4, Length(URL) - 3) + '.htm');

    Cancel := True;
  end;
end;


end.
