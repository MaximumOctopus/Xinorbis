// (c) Paul Alan Freshney 2006-2020
//
// Modified: February 16th 2020
//
// 594

unit X.Form.SearchWizard;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  ExtCtrls, StdCtrls, Buttons, ComCtrls, ImgList, AdvOfficeButtons,
  System.ImageList,

  X.LanguageHandler;

type
  TfrmSearchWizard = class(TForm)
    Shape1: TShape;
    bCancel: TBitBtn;
    bOK: TBitBtn;
    ScrollBox1: TScrollBox;
    pContaining: TPanel;
    lContaining: TLabel;
    eContaining: TEdit;
    pSize: TPanel;
    Label1: TLabel;
    Label2: TLabel;
    eSLT: TEdit;
    cbSLTUnit: TComboBox;
    eSGT: TEdit;
    cbSGTUnit: TComboBox;
    pCategory: TPanel;
    sbProg: TCheckBox;
    sbSys: TCheckBox;
    sbGfx: TCheckBox;
    sbMovie: TCheckBox;
    sbSnd: TCheckBox;
    sbOffice: TCheckBox;
    sbCode: TCheckBox;
    sbCompressed: TCheckBox;
    sbOther: TCheckBox;
    sbCustom1: TCheckBox;
    sbCustom2: TCheckBox;
    sbCustom3: TCheckBox;
    sbCustom4: TCheckBox;
    sbCustom7: TCheckBox;
    sbCustom5: TCheckBox;
    sbCustom8: TCheckBox;
    sbCustom6: TCheckBox;
    sbCustom9: TCheckBox;
    sbCustom10: TCheckBox;
    pAttributes: TPanel;
    cbAHidden: TCheckBox;
    cbASystem: TCheckBox;
    cbAArchive: TCheckBox;
    cbAReadOnly: TCheckBox;
    cbATemp: TCheckBox;
    cbAFolder: TCheckBox;
    cbAFile: TCheckBox;
    pCreated: TPanel;
    cbCreated1: TComboBox;
    cbCreated2: TComboBox;
    dtpCreated2: TDateTimePicker;
    dtpCreated1: TDateTimePicker;
    pAccessed: TPanel;
    cbAccessed1: TComboBox;
    dtpAccessed1: TDateTimePicker;
    cbAccessed2: TComboBox;
    dtpAccessed2: TDateTimePicker;
    pModified: TPanel;
    cbModified1: TComboBox;
    dtpModified1: TDateTimePicker;
    cbModified2: TComboBox;
    dtpModified2: TDateTimePicker;
    pOwner: TPanel;
    cbUSelect: TComboBox;
    eUContent: TEdit;
    bShowSQL: TBitBtn;
    ImageList1: TImageList;
    pSQL: TPanel;
    eSQL: TEdit;
    cbOwner: TAdvOfficeCheckBox;
    cbAttributes: TAdvOfficeCheckBox;
    cbModified: TAdvOfficeCheckBox;
    cbAccessed: TAdvOfficeCheckBox;
    cbCreated: TAdvOfficeCheckBox;
    cbCategory: TAdvOfficeCheckBox;
    cbSize: TAdvOfficeCheckBox;
    cbContaining: TAdvOfficeCheckBox;
    cbAVirtual: TCheckBox;
    cbAEncrypted: TCheckBox;
    cbACompressed: TCheckBox;
    procedure BuildSearchString;
    procedure FormShow(Sender: TObject);
    procedure eSLTChange(Sender: TObject);
    procedure cbCreated1Change(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure cbUSelectChange(Sender: TObject);
    procedure cbSizeClick(Sender: TObject);
    procedure cbCategoryClick(Sender: TObject);
    procedure cbAttributesClick(Sender: TObject);
    procedure cbCreatedClick(Sender: TObject);
    procedure cbOwnerClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure CheckForValidSearch;
    procedure cbContainingClick(Sender: TObject);
    procedure bShowSQLClick(Sender: TObject);
    procedure BuildSQLDisplay(Sender: TObject);
  private
    SearchString      : string;
    DateControls      : array[1..6] of TDateTimePicker;
    CategoryControls  : array[1..19] of TCheckBox;
    AttributeControls : array[1..10] of TCheckBox;  public
  end;

var
  frmSearchWizard: TfrmSearchWizard;

function DoSearchWizard: string;


implementation

{$R *.dfm}

uses
  X.SearchUtility, X.Utility, X.Global, X.Constants, X.Conversions;


const
  CUnitsBytes     = 0;
  CUnitsKilobytes = 1;
  CUnitsMegabytes = 2;
  CUnitsGigabytes = 3;


function DoSearchWizard: string;
 begin
  with TfrmSearchWizard.Create(Application) do
    try
      SearchString := '';

      ShowModal;

      if ModalResult = mrOK then begin
        BuildSearchString;

        Result := SearchString;
      end
      else
        Result := SearchString;
    finally
      free;
  end;
end;

procedure TfrmSearchWizard.FormCreate(Sender: TObject);
var
  t : integer;
  lThings : array[1..3] of string;
begin
  Caption := XText[rsSearch] + ' ' + XText[rsWizard];

  // ===========================================================================

  lThings[1] := XText[rsOn];
  lThings[2] := XText[rsBefore];
  lThings[3] := XText[rsAfter];

  cbSLTUnit.Items.Add(XText[rsXBytes]);
  cbSLTUnit.Items.Add(XText[rsXKilobytes]);
  cbSLTUnit.Items.Add(XText[rsXMegabytes]);
  cbSLTUnit.Items.Add(XText[rsXGigabytes]);
  cbSLTUnit.ItemIndex := 0;

  cbSGTUnit.Items.Add(XText[rsXBytes]);
  cbSGTUnit.Items.Add(XText[rsXKilobytes]);
  cbSGTUnit.Items.Add(XText[rsXMegabytes]);
  cbSGTUnit.Items.Add(XText[rsXGigabytes]);
  cbSGTUnit.ItemIndex := 0;

  // ===========================================================================

  DateControls[1] := dtpCreated1;
  DateControls[2] := dtpCreated2;
  DateControls[3] := dtpAccessed1;
  DateControls[4] := dtpAccessed2;
  DateControls[5] := dtpModified1;
  DateControls[6] := dtpModified2;

  cbUSelect.Items.Add(XText[rsEqualTo]);
  cbUSelect.Items.Add(XText[rsNotEqualTo]);
  cbUSelect.Items.Add(XText[rsContains]);
  cbUSelect.Items.Add(XText[rsDoesntContain]);

  cbUSelect.ItemIndex := 0;

  // ===========================================================================

  cbCreated1.Items.Add('----------');
  cbCreated2.Items.Add('----------');
  cbAccessed1.Items.Add('----------');
  cbAccessed2.Items.Add('----------');
  cbModified1.Items.Add('----------');
  cbModified2.Items.Add('----------');

  for t := 1 to 3 do begin
    cbCreated1.Items.Add(lThings[t]);
    cbCreated2.Items.Add(lThings[t]);
    cbAccessed1.Items.Add(lThings[t]);
    cbAccessed2.Items.Add(lThings[t]);
    cbModified1.Items.Add(lThings[t]);
    cbModified2.Items.Add(lThings[t]);
  end;

  cbCreated1.ItemIndex  := 0;
  cbCreated2.ItemIndex  := 0;
  cbAccessed1.ItemIndex := 0;
  cbAccessed2.ItemIndex := 0;
  cbModified1.ItemIndex := 0;
  cbModified2.ItemIndex := 0;

  dtpCreated1.DateTime  := Now;
  dtpCreated2.DateTime  := Now;
  dtpAccessed1.DateTime := Now;
  dtpAccessed2.DateTime := Now;
  dtpModified1.DateTime := Now;
  dtpModified2.DateTime := Now;

  // ===========================================================================

  CategoryControls[1] := sbProg;       CategoryControls[2] := sbSys;      CategoryControls[3] := sbGfx;       CategoryControls[4] := sbMovie;
  CategoryControls[5] := sbSnd;        CategoryControls[6] := sbOffice;   CategoryControls[7] := sbCode;      CategoryControls[8] := sbCompressed;
  CategoryControls[9] := sbOther;      CategoryControls[10] := sbCustom1; CategoryControls[11] := sbCustom2;  CategoryControls[12] := sbCustom3;
  CategoryControls[13] := sbCustom4;   CategoryControls[14] := sbCustom5; CategoryControls[15] := sbCustom6;  CategoryControls[16] := sbCustom7;
  CategoryControls[17] := sbCustom8;   CategoryControls[18] := sbCustom9; CategoryControls[19] := sbCustom10;

  AttributeControls[1] := cbAHidden;    AttributeControls[2] := cbASystem;     AttributeControls[3] := cbAArchive;  AttributeControls[4] := cbATemp; AttributeControls[5]  := cbAReadOnly;
  AttributeControls[6] := cbAEncrypted; AttributeControls[7] := cbACompressed; AttributeControls[8] := cbAFolder;   AttributeControls[9] := cbAFile; AttributeControls[10] := cbAVirtual;

  bShowSQLClick(Nil);
end;

procedure TfrmSearchWizard.FormShow(Sender: TObject);
 begin
  cbContaining.Caption  := XText[rsContainingText];
  cbSize.Caption        := XText[rsFileSize];
  cbCategory.Caption    := XText[rsCategory];
  cbAttributes.Caption  := XText[rsFileAttributes];
  cbCreated.Caption     := XText[rsCreatedDate];
  cbAccessed.Caption    := XText[rsAccessedDate];
  cbModified.Caption    := XText[rsModifiedDate];
  cbOwner.Caption       := XText[rsFileOwner];

  lContaining.Caption   := XText[rsContains];

  sbProg.Caption        := TypeDescriptions[1];
  sbSys.Caption         := TypeDescriptions[2];
  sbGfx.Caption         := TypeDescriptions[3];
  sbMovie.Caption       := TypeDescriptions[4];
  sbSnd.Caption         := TypeDescriptions[5];
  sbOffice.Caption      := TypeDescriptions[6];
  sbCode.Caption        := TypeDescriptions[7];
  sbCompressed.Caption  := TypeDescriptions[8];
  sbOther.Caption       := TypeDescriptions[9];
  sbCustom1.Caption     := TypeDescriptions[10];
  sbCustom2.Caption     := TypeDescriptions[11];
  sbCustom3.Caption     := TypeDescriptions[12];
  sbCustom4.Caption     := TypeDescriptions[13];
  sbCustom5.Caption     := TypeDescriptions[14];
  sbCustom6.Caption     := TypeDescriptions[15];
  sbCustom7.Caption     := TypeDescriptions[16];
  sbCustom8.Caption     := TypeDescriptions[17];
  sbCustom9.Caption     := TypeDescriptions[18];
  sbCustom10.Caption    := TypeDescriptions[19];

  cbAHidden.Caption     := LanguageTypes[1];
  cbASystem.Caption     := LanguageTypes[2];
  cbAArchive.Caption    := LanguageTypes[3];
  cbAReadOnly.Caption   := LanguageTypes[5];
  cbATemp.Caption       := XText[rsTemporary];
  cbAEncrypted.Caption  := XText[rsEncrypted];
  cbACompressed.Caption := XText[rsCompressed];
  cbAFolder.Caption     := XText[rsFolders];
  cbAFile.Caption       := XText[rsFiles];

  bCancel.Caption       := XText[rsCancel];
end;

procedure TfrmSearchWizard.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;

procedure TfrmSearchWizard.BuildSearchString;
var
  t : integer;

  function GetUnit(u : integer): string;
  begin
    case u of
      CUnitsBytes     : Result := '';
      CUnitsKilobytes : Result := XUnit[rsUnitKB];
      CUnitsMegabytes : Result := XUnit[rsUnitMB];
      CUnitsGigabytes : Result := XUnit[rsUnitGB];
    end;
  end;

  function GetDate(mode : integer; dt : TDate): string;
  begin
    case mode of
      1 : Result := '=' + TConvert.DateToYYYYMMDDF(dt);
      2 : Result := '<' + TConvert.DateToYYYYMMDDF(dt);
      3 : Result := '>' + TConvert.DateToYYYYMMDDF(dt);
    end;
  end;

 begin
  SearchString := '';

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  if cbContaining.Checked then begin
    if eContaining.Text <> '' then
      SearchString := SearchString + eContaining.Text + ' ';
  end;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  if cbSize.Checked then begin
    if eSLT.Text <> '' then begin
      SearchString := SearchString + '(size<' + eSLT.Text + GetUnit(cbSLTUnit.ItemIndex) + ') ';
    end;

    if eSGT.Text <> '' then begin
      SearchString := SearchString + '(size>' + eSGT.Text + GetUnit(cbSGTUnit.ItemIndex) + ') ';
    end;
  end;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  if cbCategory.Checked then begin
    for t := 1 to 19 do
      if CategoryControls[t].Checked then
        SearchString := SearchString + TSearchUtility.GetSearchText(t) + ' ';
  end;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  if cbAttributes.Checked then begin
    for t := 1 to 10 do
     if AttributeControls[t].Checked then
       SearchString := SearchString + TSearchUtility.GetSearchAttribute(AttributeControls[t].Tag) + ' ';
  end;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  if cbCreated.Checked then begin
    if cbCreated1.ItemIndex <> 0 then
      SearchString := SearchString + '(date' + GetDate(cbCreated1.ItemIndex, dtpCreated1.Date) + ') ';

    if cbCreated2.ItemIndex <> 0 then
      SearchString := SearchString + '(date' + GetDate(cbCreated2.ItemIndex, dtpCreated2.Date) + ') ';
  end;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  if cbAccessed.Checked then begin
    if cbAccessed1.ItemIndex <> 0 then
      SearchString := SearchString + '(adate' + GetDate(cbAccessed1.ItemIndex, dtpAccessed1.Date) + ') ';

    if cbAccessed2.ItemIndex <> 0 then
      SearchString := SearchString + '(adate' + GetDate(cbAccessed2.ItemIndex, dtpAccessed2.Date) + ') ';
  end;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  if cbModified.Checked then begin
    if cbModified1.ItemIndex <> 0 then
      SearchString := SearchString + '(mdate' + GetDate(cbModified1.ItemIndex, dtpModified1.Date) + ') ';

    if cbModified2.ItemIndex <> 0 then
      SearchString := SearchString + '(mdate' + GetDate(cbModified2.ItemIndex, dtpModified2.Date) + ') ';
  end;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

  if cbOwner.Checked then begin
    if cbUSelect.ItemIndex <> 0 then begin
      case cbUSelect.ItemIndex of
        1 : SearchString := SearchString + '(user='  + eUContent.Text + ') ';
        2 : SearchString := SearchString + '(user!=' + eUContent.Text + ') ';
        3 : SearchString := SearchString + '(user~'  + eUContent.Text + ') ';
        4 : SearchString := SearchString + '(user!~' + eUContent.Text + ') ';
      end;
    end;
  end;

  // ===========================================================================
  // ===========================================================================
  // ===========================================================================

end;

procedure TfrmSearchWizard.eSLTChange(Sender: TObject);
 begin
  if TEdit(Sender).Text = '' then
    TEdit(Sender).Color := clBtnFace
  else
    TEdit(Sender).Color := clWindow;

  BuildSQLDisplay(Nil);  
end;

procedure TfrmSearchWizard.cbCreated1Change(Sender: TObject);
 begin
  if TComboBox(Sender).ItemIndex = 0 then begin
    DateControls[TComboBox(Sender).Tag].Enabled := False;
  end
  else begin
    DateControls[TComboBox(Sender).Tag].Enabled := True;
  end;

  BuildSQLDisplay(Nil);  
end;

procedure TfrmSearchWizard.cbUSelectChange(Sender: TObject);
 begin
  if cbUSelect.ItemIndex = 0 then
    eUContent.Enabled := False
  else
    eUContent.Enabled := True;

  BuildSQLDisplay(Nil);
end;

procedure TfrmSearchWizard.cbContainingClick(Sender: TObject);
 begin
  if TAdvOfficeCheckBox(Sender).Checked then begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 64;

    TAdvOfficeCheckBox(Sender).Font.Style := [fsBold];
  end
  else begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 24;

    TAdvOfficeCheckBox(Sender).Font.Style := [];
  end;

  CheckForValidSearch;
end;

procedure TfrmSearchWizard.cbSizeClick(Sender: TObject);
 begin
  if TAdvOfficeCheckBox(Sender).Checked then begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 64;

    TAdvOfficeCheckBox(Sender).Font.Style := [fsBold];
  end
  else begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 24;

    TAdvOfficeCheckBox(Sender).Font.Style := [];
  end;

  CheckForValidSearch;
end;

procedure TfrmSearchWizard.cbCategoryClick(Sender: TObject);
 begin
  if TAdvOfficeCheckBox(Sender).Checked then begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 112;

    TAdvOfficeCheckBox(Sender).Font.Style := [fsBold];
  end
  else begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 24;

    TAdvOfficeCheckBox(Sender).Font.Style := [];
  end;

  CheckForValidSearch;
end;

procedure TfrmSearchWizard.cbAttributesClick(Sender: TObject);
 begin
  if TAdvOfficeCheckBox(Sender).Checked then begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 97;

    TAdvOfficeCheckBox(Sender).Font.Style := [fsBold];
  end
  else begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 24;

    TAdvOfficeCheckBox(Sender).Font.Style := [];
  end;

  CheckForValidSearch;
end;

procedure TfrmSearchWizard.cbCreatedClick(Sender: TObject);
 begin
  if TAdvOfficeCheckBox(Sender).Checked then begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 64;

    TAdvOfficeCheckBox(Sender).Font.Style := [fsBold];
  end
  else begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 24;

    TAdvOfficeCheckBox(Sender).Font.Style := [];
  end;

  CheckForValidSearch;
end;

procedure TfrmSearchWizard.cbOwnerClick(Sender: TObject);
 begin
  if TAdvOfficeCheckBox(Sender).Checked then begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 64;

    TAdvOfficeCheckBox(Sender).Font.Style := [fsBold];
  end
  else begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 24;

    TAdvOfficeCheckBox(Sender).Font.Style := [];
  end;

  CheckForValidSearch;
end;

procedure TfrmSearchWizard.CheckForValidSearch;
 begin
  if (cbContaining.Checked or cbCreated.Checked or cbAccessed.Checked or cbModified.Checked or
      cbSize.Checked or cbCategory.Checked or cbOwner.Checked or cbAttributes.Checked) then
    bOK.Enabled := True
  else
    bOK.Enabled := False;
end;

procedure TfrmSearchWizard.bShowSQLClick(Sender: TObject);
 var
  tbmp : TBitmap;

 begin
  tbmp := TBitmap.Create;

  if bShowSQL.Tag = 1 then begin
    bShowSQL.Tag := 0;
    pSQL.Visible := False;
  end
  else begin
    bShowSQL.Tag := 1;
    pSQL.Visible := True;

    BuildSQLDisplay(Nil);
  end;

  ImageList1.GetBitmap(bShowSQL.Tag, tbmp);
  bShowSQL.Glyph := tbmp;

  tbmp.Free;
end;

procedure TfrmSearchWizard.BuildSQLDisplay(Sender: TObject);
 begin
  if bShowSQL.Tag = 1 then begin
    BuildSearchString;

    eSQL.Text := TSearchUtility.XinorbisSearchToSQL('', '', '', searchstring, 0, 500, True);
  end;
end;


end.
