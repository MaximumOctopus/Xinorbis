{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Form.QuickMenuBuilder;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, System.Contnrs, Vcl.Buttons, Generics.Collections,
  Vcl.ExtCtrls, Vcl.Menus, Vcl.ComCtrls, Vcl.StdCtrls, AdvNavBar,

  X.Constants,

  X.LanguageHandler, X.Settings, X.Global, X.Dialogs.Dialog, X.SystemGlobal;

type
  TfrmQuickMenuBuilder = class(TForm)
    mMain: TMemo;
    odMain: TOpenDialog;
    puTest: TPopupMenu;
    sdMain: TSaveDialog;
    Panel1: TPanel;
    SpeedButton1: TSpeedButton;
    SpeedButton3: TSpeedButton;
    SpeedButton4: TSpeedButton;
    sbTest: TSpeedButton;
    bClear: TSpeedButton;
    AdvNavBar1: TAdvNavBar;
    AdvNavBarPanel1: TAdvNavBarPanel;
    AdvNavBarPanel2: TAdvNavBarPanel;
    AdvNavBarPanel3: TAdvNavBarPanel;
    SpeedButton8: TSpeedButton;
    SpeedButton9: TSpeedButton;
    SpeedButton10: TSpeedButton;
    SpeedButton11: TSpeedButton;
    SpeedButton35: TSpeedButton;
    SpeedButton29: TSpeedButton;
    SpeedButton33: TSpeedButton;
    SpeedButton34: TSpeedButton;
    SpeedButton32: TSpeedButton;
    SpeedButton13: TSpeedButton;
    SpeedButton24: TSpeedButton;
    SpeedButton18: TSpeedButton;
    SpeedButton19: TSpeedButton;
    SpeedButton25: TSpeedButton;
    SpeedButton26: TSpeedButton;
    SpeedButton20: TSpeedButton;
    SpeedButton30: TSpeedButton;
    SpeedButton27: TSpeedButton;
    SpeedButton28: TSpeedButton;
    SpeedButton31: TSpeedButton;
    SpeedButton23: TSpeedButton;
    SpeedButton16: TSpeedButton;
    SpeedButton21: TSpeedButton;
    SpeedButton22: TSpeedButton;
    SpeedButton15: TSpeedButton;
    SpeedButton17: TSpeedButton;
    SpeedButton14: TSpeedButton;
    SpeedButton12: TSpeedButton;
    AdvNavBarPanel4: TAdvNavBarPanel;
    SpeedButton5: TSpeedButton;
    SpeedButton6: TSpeedButton;
    AdvNavBarPanel5: TAdvNavBarPanel;
    SpeedButton7: TSpeedButton;
    SpeedButton36: TSpeedButton;
    SpeedButton37: TSpeedButton;
    SpeedButton38: TSpeedButton;
    SpeedButton39: TSpeedButton;
    SpeedButton42: TSpeedButton;
    rbDCreated: TRadioButton;
    rbDAccessed: TRadioButton;
    rbDModified: TRadioButton;

    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
    procedure SpeedButton4Click(Sender: TObject);
    procedure sbTestClick(Sender: TObject);
    procedure MenuClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure bClearClick(Sender: TObject);
    procedure SpeedButto8Click(Sender: TObject);
    procedure SpeedButton6Click(Sender: TObject);
    procedure SpeedButton12Click(Sender: TObject);
    procedure SpeedButton5Click(Sender: TObject);
    procedure SpeedButton33Click(Sender: TObject);
    procedure SpeedButton38Click(Sender: TObject);
    procedure FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight,
      MaxWidth, MaxHeight: Integer);
    procedure FormDestroy(Sender: TObject);
  private
    MenuStrings : TStringList;
    QMenuItems  : TObjectList<TMenuItem>;
    Filename    : string;
  public
  end;


var
  frmQuickMenuBuilder: TfrmQuickMenuBuilder;


procedure ShowQuickMenuBuilder;


implementation

{$R *.dfm}


const
  CAttribArchive  = 0;
  CAttribSystem   = 1;
  CAttribHidden   = 2;
  CAttribReadOnly = 3;

  CDateToday         = 0;
  CDateYesterday     = 1;
  CDateLastWeek      = 2;
  CDateLastMonth     = 3;
  CDateLastSixMonths = 4;
  CDateLastYear      = 5;

  CDialogCreatedDate  = 0;
  CDialogAccessedDate = 1;
  CDialogModifiedDate = 2;
  CDialogSize         = 10;
  CDialogSearchWizard = 20;


procedure ShowQuickMenuBuilder;
 begin
  with TfrmQuickMenuBuilder.Create(Application) do
    try
      ShowModal;
    finally
      free;
    end;
 end;


procedure TfrmQuickMenuBuilder.FormCreate(Sender: TObject);
var
  lLanguageSymbol : string;

begin
  MenuStrings := TStringList.Create;
  QMenuItems  := TObjectList<TMenuItem>.Create(False);

  Filename    := '';

  lLanguageSymbol := TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage);

  odMain.InitialDir := GSystemGlobal.ExePath + 'data\languages\' + lLanguageSymbol + '\';
end;


procedure TfrmQuickMenuBuilder.FormDestroy(Sender: TObject);
begin
  MenuStrings.Free;
 // QMenuItems.Free;
end;


procedure TfrmQuickMenuBuilder.FormConstrainedResize(Sender: TObject;
  var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
begin
  MinWidth  := 650;
  MinHeight := 581;
end;


procedure TfrmQuickMenuBuilder.bClearClick(Sender: TObject);
begin
  mMain.Clear;

  mMain.Lines.Add('{Empty menu template}');
  mMain.Lines.Add('-');
  mMain.Lines.Add('[submenu title]');
  mMain.Lines.Add('.sumenu item 1=search');
  mMain.Lines.Add('.sumenu item 2=search');
  mMain.Lines.Add('.sumenu item 3=search');
  mMain.Lines.Add('*');
end;


procedure TfrmQuickMenuBuilder.SpeedButton12Click(Sender: TObject);
var
  s : string;

begin
  case TSpeedbutton(Sender).Tag of
    Category_Program    : s := '#PROG';
    Category_System     : s := '#SYS';
    Category_Graphics   : s := '#GFX';
    Category_Movie      : s := '#MOVIE';
    Category_Sound      : s := '#SOUND';
    Category_Office     : s := '#OFF';
    Category_Code       : s := '#COD';
    Category_Compressed : s := '#COM';
    Category_Other      : s := '#OTH';

    Category_Custom_1   : s := '#C1';
    Category_Custom_2   : s := '#C2';
    Category_Custom_3   : s := '#C3';
    Category_Custom_4   : s := '#C4';
    Category_Custom_5   : s := '#C5';
    Category_Custom_6   : s := '#C6';
    Category_Custom_7   : s := '#C7';
    Category_Custom_8   : s := '#C8';
    Category_Custom_9   : s := '#C9';
    Category_Custom_10  : s := '#C10';
  end;

  mMain.SelText := s;
end;


procedure TfrmQuickMenuBuilder.SpeedButton1Click(Sender: TObject);
begin
  if odMain.Execute then begin
    mMain.Lines.LoadFromFile(odMain.FileName);
  end;
end;


procedure TfrmQuickMenuBuilder.sbTestClick(Sender: TObject);
 var
  t, ix : integer;
  mi : TMenuItem;
  LastNode : TMenuItem;

 begin
  LastNode := Nil;

  MenuStrings.Clear;
  QMenuItems.Clear;
  puTest.Items.Clear;

  if (mMain.Lines.Count > 0) then begin

    for t := 0 to mMain.Lines.Count - 1 do begin

      if mMain.Lines[t] <> '' then begin
        case mMain.Lines[t][1] of
          '-' : begin
                  mi := TMenuItem.Create(puTest);
                  mi.Caption := '-';

                  QMenuItems.Add(mi);

                  if LastNode = Nil then
                    puTest.Items.Add(mi)
                  else
                    LastNode.Add(mi);
                end;
          '{' : begin
                  mi := TMenuItem.Create(puTest);
                  mi.Caption := Copy(mMain.Lines[t], 2, length(mMain.Lines[t]) - 2);
                  mi.Enabled := False;

                  QMenuItems.Add(mi);

                  if LastNode = Nil then
                    puTest.Items.Add(mi)
                  else
                    LastNode.Add(mi);
                end;
          '[' : begin
                  mi := TMenuItem.Create(puTest);
                  mi.Caption := Copy(mMain.Lines[t], 2, length(mMain.Lines[t]) - 2);
                  mi.Enabled := True;

                  QMenuItems.Add(mi);

                  if LastNode = Nil then
                    puTest.Items.Add(mi)
                  else
                    LastNode.Add(mi);

                  LastNode := QMenuItems[QMenuItems.Count - 1];
                end;
          '.' : begin
                  mi := TMenuItem.Create(puTest);
                  ix := Pos('=', mMain.Lines[t]);

                  if ix <> 0 then begin
                    mi.Caption := Copy(mMain.Lines[t], 2, ix - 2);

                    MenuStrings.Add(Copy(mMain.Lines[t], ix + 1, Length(mMain.Lines[t]) - ix + 1));

                    mi.OnClick := MenuClick;
                    mi.Tag     := MenuStrings.Count - 1;
                  end
                  else begin
                    mi.Caption := Copy(mMain.Lines[t], 2, ix - 1);
                  end;

                  mi.Enabled := True;

                  QMenuItems.Add(mi);

                  if LastNode = Nil then
                    puTest.Items.Add(mi)
                  else
                    LastNode.Add(mi);
                end;
          '*' : begin
                  LastNode := LastNode.Parent;
                end;
        end;
      end;
    end;

    puTest.Popup(Left + TSpeedbutton(Sender).Left + 5, Top + TSpeedButton(Sender).Top + 45);
  end;
end;


procedure TfrmQuickMenuBuilder.SpeedButton33Click(Sender: TObject);
var
  s : string;

begin
  case TSpeedbutton(Sender).Tag of
    CAttribArchive  : s := '@ARCHIVE';
    CAttribSystem   : s := '@SYSTEM';
    CAttribHidden   : s := '@HIDDEN';
    CAttribReadOnly : s := '@READONLY';
  end;

  mMain.SelText := s;
end;


procedure TfrmQuickMenuBuilder.SpeedButton38Click(Sender: TObject);
var
  s : string;
  lDate : string;

begin
  if rbDCreated.Checked then
    lDate := 'cdate'
  else if rbDAccessed.Checked then
    lDate := 'adate'
  else
    lDate := 'mdate';

  case TSpeedbutton(Sender).Tag of
    CDateToday         : s := '(' + lDate + '={NOW})';
    CDateYesterday     : s := '(' + lDate + '={YESTERDAY})';
    CDateLastWeek      : s := '(' + lDate + '>{DECWEEK}) (' + lDate + '<{NOW})';
    CDateLastMonth     : s := '(' + lDate + '>{DECMONTH}) (' + lDate + '<{NOW})';
    CDateLastSixMonths : s := '(' + lDate + '<{DECMONTH6})';
    CDateLastYear      : s := '(' + lDate + '<{DECMONTH12})';
  end;

  mMain.SelText := s;
end;


procedure TfrmQuickMenuBuilder.SpeedButton3Click(Sender: TObject);
begin
  if Filename <> '' then begin
    try
      mMain.Lines.SaveToFile(Filename)
    except
      on e : exception do begin
        ShowXDialog('Quick Menu Builder - error',
                    'Unable to save file "' + filename + '". ' + e.ClassName + ' / ' + e.Message,
                    XDialogTypeWarning);
      end;
    end;
  end
  else
    SpeedButton4Click(Nil);
end;


procedure TfrmQuickMenuBuilder.SpeedButton4Click(Sender: TObject);
begin
  if sdMain.Execute then begin
    try
      mMain.Lines.SaveToFile(sdMain.Filename);
    except
      on e : exception do begin
        ShowXDialog('Quick Menu Builder - error',
                    'Unable to save file "' + sdMain.Filename + '". ' + e.ClassName + ' / ' + e.Message,
                    XDialogTypeWarning);
      end;
    end;

    Filename := sdMain.Filename;
  end
end;


procedure TfrmQuickMenuBuilder.SpeedButton5Click(Sender: TObject);
var
  lCurrentLine : integer;
begin
  lCurrentLine := mMain.CaretPos.Y;

  mMain.Lines.Insert(lCurrentLine, '-');
end;


procedure TfrmQuickMenuBuilder.SpeedButton6Click(Sender: TObject);
var
  lCurrentLine : integer;
begin
  lCurrentLine := mMain.CaretPos.Y;

//  mMain.Lines[lCurrentLine] :
  mMain.Lines.Insert(lCurrentLine, '*');
  mMain.Lines.Insert(lCurrentLine, '.sumenu item 3=search');
  mMain.Lines.Insert(lCurrentLine, '.sumenu item 2=search');
  mMain.Lines.Insert(lCurrentLine, '.sumenu item 1=search');
  mMain.Lines.Insert(lCurrentLine, '[submenu title]');
end;


procedure TfrmQuickMenuBuilder.SpeedButto8Click(Sender: TObject);
var
  s : string;

begin
  case TSpeedbutton(Sender).Tag of
    CDialogCreatedDate  : s := '{GetDateDialogC}';
    CDialogAccessedDate : s := '{GetDateDialogA}';
    CDialogModifiedDate : s := '{GetDateDialogM}';

    CDialogSize         : s := '{GetSizeDialog}';

    CDialogSearchWizard : s := '$SearchWizard';
  end;

  mMain.SelText := s;
end;


procedure TfrmQuickMenuBuilder.MenuClick(Sender: TObject);
 begin
  ShowXDialog('Quick Menu Builder - output',
              MenuStrings[TMenuItem(Sender).Tag],
              XDialogTypeXinorbis);
end;


end.
