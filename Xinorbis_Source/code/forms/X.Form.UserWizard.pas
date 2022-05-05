// January 16th 2019

unit X.Form.UserWizard;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  ExtCtrls, AdvNavBar, Buttons, StdCtrls, AdvGlowButton,

  X.LanguageHandler, X.Help, X.SearchUtility,

  X.Conversions, Vcl.Imaging.pngimage;

type
  TfrmUserWizard = class(TForm)
    Panel1: TPanel;
    Panel2: TPanel;
    pTitle: TPanel;
    sbOk: TSpeedButton;
    SpeedButton9: TSpeedButton;
    Label1: TLabel;
    pEnd: TPanel;
    pMultimedia: TPanel;
    Label3: TLabel;
    sbPrevious: TSpeedButton;
    sbNext: TSpeedButton;
    AdvGlowButton4: TAdvGlowButton;
    AdvGlowButton5: TAdvGlowButton;
    AdvGlowButton6: TAdvGlowButton;
    AdvGlowButton7: TAdvGlowButton;
    gbMultimedia1: TAdvGlowButton;
    gbMultimedia2: TAdvGlowButton;
    gbMultimedia3: TAdvGlowButton;
    pProductivity: TPanel;
    Label2: TLabel;
    gbProductivity1: TAdvGlowButton;
    gbProductivity2: TAdvGlowButton;
    gbProductivity3: TAdvGlowButton;
    Label4: TLabel;
    pSize: TPanel;
    Label5: TLabel;
    gbSize1: TAdvGlowButton;
    gbSize2: TAdvGlowButton;
    gbSize3: TAdvGlowButton;
    gbSize4: TAdvGlowButton;
    gbSize5: TAdvGlowButton;
    gbSize6: TAdvGlowButton;
    pPopular: TPanel;
    Label6: TLabel;
    gbPCreated: TAdvGlowButton;
    gbPAccessed: TAdvGlowButton;
    gbPYesterday: TAdvGlowButton;
    gbPThisWeek: TAdvGlowButton;
    gbPModified: TAdvGlowButton;
    AdvGlowButton1: TAdvGlowButton;
    AdvGlowButton2: TAdvGlowButton;
    sbSearch: TSpeedButton;
    AdvGlowButton3: TAdvGlowButton;
    AdvGlowButton8: TAdvGlowButton;
    pSystem: TPanel;
    Label8: TLabel;
    gbSystem1: TAdvGlowButton;
    gbSystem2: TAdvGlowButton;
    pCompressed: TPanel;
    Label7: TLabel;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    SpeedButton3: TSpeedButton;
    Label9: TLabel;
    Label10: TLabel;
    gbCompressed: TAdvGlowButton;
    gbSystem3: TAdvGlowButton;
    procedure FormCreate(Sender: TObject);
    procedure sbOkClick(Sender: TObject);
    procedure SpeedButton9Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure sbPreviousClick(Sender: TObject);
    procedure sbNextClick(Sender: TObject);
    procedure AdvGlowButton1Click(Sender: TObject);
    procedure MultipleSelectionClick(Sender: TObject);
    procedure gbSize1Click(Sender: TObject);
    procedure sbSearchClick(Sender: TObject);
  private
    FSelectedType   : integer;
    FSelectedOption : integer;
    FPage           : integer;

    function BuildSearchString: string;
  public
    { Public declarations }
  end;


var
  frmUserWizard: TfrmUserWizard;


function DoUserWizard: string;


implementation


{$R *.dfm}


const
  CTypeNotSelected  = -1;
  CTypeMultimedia   = 1;
  CTypeProductivity = 2;
  CTypeCompressed   = 3;
  CTypeSystem       = 4;
  CTypePopular      = 10;
  CTypeSize         = 20;

  CPageMain         = 0;
  CPageEnd          = 1;

  CDateToday        = 0;
  CDateYesterday    = 1;
  CDateLastWeek     = 2;
  CDateLastMonth    = 3;

  CSizeLess1MB      = 0;
  CSize1To10MB      = 1;
  CSize10To50MB     = 2;
  CSize50To100MB    = 3;
  CSize100MBTo1GB   = 4;
  CSizeGreater1GB   = 5;

   {Category_Program    : Result := '#PROG';
    Category_System     : Result := '#SYS';
    Category_Graphics   : Result := '#GFX';
    Category_Movie      : Result := '#MOVIE';
    Category_Sound      : Result := '#SOUND';
    Category_Office     : Result := '#OFF';
    Category_Code       : Result := '#COD';
    Category_Compressed : Result := '#COM';
    Category_Other      : Result := '#OTH';
    Category_Custom_1   : Result := '#C1';
    Category_Custom_2   : Result := '#C2';
    Category_Custom_3   : Result := '#C3';
    Category_Custom_4   : Result := '#C4';
    Category_Custom_5   : Result := '#C5';
    Category_Custom_6   : Result := '#C6';
    Category_Custom_7   : Result := '#C7';
    Category_Custom_8   : Result := '#C8';
    Category_Custom_9   : Result := '#C9';
    Category_Custom_10  : Result := '#C10';
    20, 99              : Result := '#CX';        }


function DoUserWizard: string;
 begin
  with TfrmUserWizard.Create(Application) do
    try
      Result        := '';
      FSelectedType := CTypeNotSelected;
      FPage         := 0;

      ShowModal;

      if ModalResult = mrOK then begin
        Result := BuildSearchString;
      end;

    finally
      free;
  end;
end;


procedure TfrmUserWizard.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;


procedure TfrmUserWizard.FormCreate(Sender: TObject);
begin
  pTitle.Align := alClient;
  pTitle.BringToFront;

  Caption := XText[rsSearch] + ' ' + XText[rsWizard];
end;

procedure TfrmUserWizard.sbNextClick(Sender: TObject);
var
  lPanel : TPanel;
begin
  lPanel := Nil;

  case FSelectedType of
    CTypeMultimedia   : case FPage of
                          CPageMain : lPanel := pMultimedia;
                          CPageEnd  : lPanel := pEnd;
                        end;
    CTypeProductivity : case FPage of
                          CPageMain : lPanel := pProductivity;
                          CPageEnd  : lPanel := pEnd;
                        end;
    CTypeCompressed   : case FPage of
                          CPageMain : lPanel := pCompressed;
                          CPageEnd  : lPanel := pEnd;
                        end;
    CTypeSystem       : case FPage of
                          CPageMain : lPanel := pSystem;
                          CPageEnd  : lPanel := pEnd;
                        end;
    CTypePopular      : case FPage of
                          CPageMain : lPanel := pPopular;
                          CPageEnd  : lPanel := pEnd;
                        end;
    CTypeSize         : case FPage of
                          CPageMain : lPanel := pSize;
                          CPageEnd  : lPanel := pEnd;
                        end;
  end;

  if lPanel <> Nil then begin
    lPanel.Align := alClient;
    lPanel.BringToFront;

    sbNext.Enabled := False;

    inc(FPage);

    if lPanel = pEnd then
      sbOK.Enabled := True;
  end;

  if FPage > 0 then
    sbPrevious.Enabled := True;
end;


procedure TfrmUserWizard.sbPreviousClick(Sender: TObject);
var
  lPanel : TPanel;
begin
  lPanel := Nil;

  case FSelectedType of
    CTypeMultimedia   : case FPage of
                          1 : lPanel := pTitle;
                          2 : lPanel := pMultimedia;
                        end;
    CTypeProductivity : case FPage of
                          1 : lPanel := pTitle;
                          2 : lPanel := pProductivity;
                        end;
    CTypeCompressed   : case FPage of
                          1 : lPanel := pTitle;
                          2 : lPanel := pCompressed;
                        end;
    CTypeSystem       : case FPage of
                          1 : lPanel := pTitle;
                          2 : lPanel := pSystem;
                        end;
    CTypePopular      : case FPage of
                          1 : lPanel := pTitle;
                          2 : lPanel := pPopular;
                        end;
    CTypeSize         : case FPage of
                          1 : lPanel := pTitle;
                          2 : lPanel := pSize;
                        end;
  end;

  if lPanel <> Nil then begin
    lPanel.Align := alClient;
    lPanel.BringToFront;

    sbNext.Enabled := False;

    dec(FPage);
  end;

  if FPage = 0 then
    sbPrevious.Enabled := False;

  sbOK.Enabled := True;
end;


procedure TfrmUserWizard.sbSearchClick(Sender: TObject);
begin
  THelp.OpenHelpPage('userwizard.htm');
end;


procedure TfrmUserWizard.sbOkClick(Sender: TObject);
 begin
  ModalResult := mrOK;
end;


procedure TfrmUserWizard.MultipleSelectionClick(Sender: TObject);
begin
  if TAdvGlowButton(Sender).Down then
    TAdvGlowButton(Sender).Down := False
  else
    TAdvGlowButton(Sender).Down := True;

  case TAdvGlowButton(Sender).Tag of
    1 : sbNext.Enabled := gbMultimedia1.Down or
                          gbMultimedia2.Down or
                          gbMultimedia3.Down;
    2 : sbNext.Enabled := gbProductivity1.Down or
                          gbProductivity2.Down or
                          gbProductivity3.Down;
    3 : sbNext.Enabled := gbCompressed.Down;
    4 : sbNext.Enabled := gbSystem1.Down or
                          gbSystem2.Down or
                          gbSystem3.Down;
  end;
end;


procedure TfrmUserWizard.gbSize1Click(Sender: TObject);
begin
  sbNext.Enabled := True;

  FSelectedOption := TAdvGlowButton(Sender).Tag;
end;


procedure TfrmUserWizard.SpeedButton9Click(Sender: TObject);
 begin
  ModalResult := mrCancel;
end;


procedure TfrmUserWizard.AdvGlowButton1Click(Sender: TObject);
begin
  FSelectedType := TAdvGlowButton(Sender).Tag;

  if FSelectedType <> CTypeNotSelected then
    sbNext.Enabled := True;
end;

function TfrmUserWizard.BuildSearchString: string;
var
  lDate : string;
begin
  Result := '';

  case FSelectedType of
    CTypeMultimedia    : begin
                           if gbMultimedia1.Down then
                             Result := Result + '#GFX ';

                           if gbMultimedia2.Down then
                             Result := Result + '#MOVIE ';

                           if gbMultimedia3.Down then
                             Result := Result + '#SOUND ';
                         end;
    CTypeProductivity  : begin
                           if gbProductivity1.Down then
                             Result := Result + '#OFF ';

                           if gbProductivity2.Down then
                             Result := Result + '#COD ';

                           if gbProductivity3.Down then
                             Result := Result + '#COM ';
                         end;
    CTypeCompressed    : begin
                           Result := Result + '#COM ';
                         end;
    CTypeSystem        : begin
                           if gbSystem1.Down then
                             Result := Result + '#PROG ';

                           if gbSystem2.Down then
                             Result := Result + '#SYSTEM ';

                           if gbSystem3.Down then
                             Result := Result + '#SYSTEM #PROG';
                         end;
    CTypePopular       : begin
                           if gbPCreated.Down then
                             lDate := 'cdate'
                           else if gbPAccessed.Down then
                             lDate := 'adate'
                           else if gbPModified.Down then
                             lDate := 'mdate';

                           case FSelectedOption of
                             CDateToday     : Result := '(' + lDate + '=' + TConvert.DateToYYYYMMDD(Now) + ')';
                             CDateYesterday : Result := '(' + lDate + '=' + TConvert.DateToYYYYMMDD(Now - 1) + ')';
                             CDateLastWeek  : Result := '(' + lDate + '>' + TConvert.DateToYYYYMMDD(Now - 7) + ') (' + lDate + '<' + TConvert.DateToYYYYMMDD(Now) + ')';
                             CDateLastMonth : Result := '(' + lDate + '>' + TConvert.DateToYYYYMMDD(Now - 31) + ') (' + lDate + '<' + TConvert.DateToYYYYMMDD(Now) + ')';
                           end;
                         end;
    CTypeSize          : case FSelectedOption of
                           CSizeLess1MB    : Result := TSearchUtility.GetSearchSize( -1,       -1,   1, rsUnitMB);
                           CSize1To10MB    : Result := TSearchUtility.GetSearchSize(  1, rsUnitMB,  10, rsUnitMB);
                           CSize10To50MB   : Result := TSearchUtility.GetSearchSize( 10, rsUnitMB,  50, rsUnitMB);
                           CSize50To100MB  : Result := TSearchUtility.GetSearchSize( 50, rsUnitMB, 100, rsUnitMB);
                           CSize100MBTo1GB : Result := TSearchUtility.GetSearchSize(100, rsUnitMB,   1, rsUnitGB);
                           CSizeGreater1GB : Result := TSearchUtility.GetSearchSize(  1, rsUnitGB,  -1,       -1);
                         end;
  end;

  Result := Trim(Result);
end;


end.
