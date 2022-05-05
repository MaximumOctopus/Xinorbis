// (c) Paul Alan Freshney 2006-2011
//
// Modified: December 16th 2010
//
// 221

unit X.Form.CustomiseXml;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, ExtCtrls,

  X.LanguageHandler;

type
  TfrmCustomXML = class(TForm)
    Label1: TLabel;
    GroupBox1: TGroupBox;
    lSI1: TLabel;
    lSI2: TLabel;
    lSI3: TLabel;
    lSI4: TLabel;
    lSI5: TLabel;
    lSI8: TLabel;
    lSI7: TLabel;
    lSI6: TLabel;
    lSI10: TLabel;
    lSI11: TLabel;
    lSI9: TLabel;
    lSI12: TLabel;
    bSave: TBitBtn;
    bCancel: TBitBtn;
    Bevel1: TBevel;
    sbDown: TSpeedButton;
    sbUp: TSpeedButton;
    sbRemove: TSpeedButton;
    lbSummaryLayout: TListBox;
    Label2: TLabel;
    lSI13: TLabel;
    lSI14: TLabel;
    lSI15: TLabel;
    lSI16: TLabel;
    Label6: TLabel;
    Label5: TLabel;
    Label4: TLabel;
    Label3: TLabel;
    lImportant: TLabel;
    function BuildSummaryLayout: string;
    procedure sbRemoveClick(Sender: TObject);
    procedure sbUpClick(Sender: TObject);
    procedure sbDownClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure lbSummaryLayoutClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmCustomXML: TfrmCustomXML;

function GetXMLReportLayout(const s : string): string;



implementation

{$R *.dfm}

uses X.Utility,

     X.Global, X.Constants;

const
 XMLItemsCount = 16;

var
 LayoutItems : array[1..XMLItemsCount] of TLabel;
 OldLayout : string;

function GetXMLReportLayout(const s : string): string;
 begin
  with TfrmCustomXML.Create(Application) do
    try
      OldLayout := s;

      ShowModal;

      if ModalResult = mrOK then begin
        Result := BuildSummaryLayout;
      end
      else begin
        Result := s;
      end;
    finally
      Free;
    end;
end;

procedure TfrmCustomXML.FormCreate(Sender: TObject);
 var
  t : integer;

 begin
  LayoutItems[1]:=lSI1;   LayoutItems[2]:=lSI2;
  LayoutItems[3]:=lSI3;   LayoutItems[4]:=lSI4;
  LayoutItems[5]:=lSI5;   LayoutItems[6]:=lSI6;
  LayoutItems[7]:=lSI7;   LayoutItems[8]:=lSI8;
  LayoutItems[9]:=lSI9;   LayoutItems[10]:=lSI10;
  LayoutItems[11]:=lSI11; LayoutItems[12]:=lSI12;
  LayoutItems[13]:=lSI13; LayoutItems[14]:=lSI14;
  LayoutItems[15]:=lSI15; LayoutItems[16]:=lSI16;  

  bSave.Caption   := XText[rsSave];
  bCancel.Caption := XText[rsCancel];

  for t := 1 to XMLItemsCount do begin
    LayoutItems[t].Caption := OtherReportItems[t];
  end;
end;

procedure TfrmCustomXML.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;

procedure TfrmCustomXML.FormShow(Sender: TObject);
 var
  t, lLayoutID : integer;
  s : string;

 begin
  s := '';

  for t := 1 to length(oldlayout) do begin
    if oldlayout[t] = ':' then begin
      lLayoutID := StrToIntDef(s, 99);

      if lLayoutID <= XMLItemsCount then begin
        lbSummaryLayout.Items.Add(LayoutItems[lLayoutID].Caption);
      end;

      s := '';
    end
    else
      s := s + oldlayout[t];
  end;

  //== languagey stuff =========================================================
  Caption            := XText[rsCustomise] + ' XML ' + XText[rsReportLayout];
  Label1.Caption     := XText[rsAvailable] + ' XML ' + XText[rsReportItems];
  Label2.Caption     := 'XML ' + XText[rsReportLayout];
  GroupBox1.Caption  := XText[rsClickToAdd];
  lImportant.Caption := XText[rsMaySlowDownReport];
end;

function TfrmCustomXML.BuildSummaryLayout: string;
 var
  t,z,idx : integer;

 begin
  Result := '';

  for t := 0 to lbSummaryLayout.Count - 1 do begin
    idx := 0;

    for z := 1 to XMLItemsCount do begin
      if LayoutItems[z].Caption = lbSummaryLayout.Items[t] then idx := z;
    end;

    Result := Result + IntToStr(idx) + ':';
  end;
end;

procedure TfrmCustomXML.sbRemoveClick(Sender: TObject);
 begin
  lbSummaryLayout.DeleteSelected;
end;

procedure TfrmCustomXML.sbUpClick(Sender: TObject);
 var
  a : integer;

 begin
  if lbSummaryLayout.ItemIndex > 0 then begin
    a := lbSummaryLayout.ItemIndex - 1;

    lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex - 1);

    lbSummaryLayout.ItemIndex := a;
  end;
end;

procedure TfrmCustomXML.sbDownClick(Sender: TObject);
 var
  a : integer;

 begin
  if lbSummaryLayout.ItemIndex <> -1 then begin
    if lbSummaryLayout.ItemIndex < lbSummaryLayout.Count - 1 then begin
      a := lbSummaryLayout.ItemIndex + 1;

      lbSummaryLayout.Items.Move(lbSummaryLayout.ItemIndex, lbSummaryLayout.ItemIndex + 1);

      lbSummaryLayout.ItemIndex := a;
    end;
  end;
end;

procedure TfrmCustomXML.lbSummaryLayoutClick(Sender: TObject);
 var
  status : boolean;

 begin
  if lbSummaryLayout.ItemIndex = -1 then
    status := False
  else
    status := True;

  sbUp.Enabled     := status;
  sbDown.Enabled   := status;
  sbRemove.Enabled := status;
end;


end.
