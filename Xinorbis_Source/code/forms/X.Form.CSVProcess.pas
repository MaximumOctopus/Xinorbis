// CSV Import stuff
//
//       Started: December 20th 2007
// Last Modified: May 11th 2019
//
// 287

unit X.Form.CSVProcess;

interface

uses
  System.UITypes, Windows, Messages, System.SysUtils, System.Variants, Classes, Graphics, Controls, Forms,
  ExtCtrls, StdCtrls, Buttons,

  X.Help, X.Utility, X.CCSVDataFormat, X.LanguageHandler, X.SystemGlobal;


type
  TfrmCSVProcess = class(TForm)
    bImport: TBitBtn;
    bCancel: TBitBtn;
    Bevel1: TBevel;
    bHelp: TBitBtn;
    cbIFR: TCheckBox;
    GroupBox1: TGroupBox;
    lContents1: TLabel;
    lContents2: TLabel;
    lContents3: TLabel;
    lContents4: TLabel;
    lContents5: TLabel;
    lContents6: TLabel;
    lContents7: TLabel;
    cbType1: TComboBox;
    cbType2: TComboBox;
    cbType3: TComboBox;
    cbType4: TComboBox;
    cbType5: TComboBox;
    cbType6: TComboBox;
    cbType7: TComboBox;
    GroupBox2: TGroupBox;
    lFilename: TLabel;
    Label3: TLabel;
    cbType8: TComboBox;
    lContents8: TLabel;
    cbType9: TComboBox;
    lContents9: TLabel;
    cbType15: TComboBox;
    cbType13: TComboBox;
    cbType12: TComboBox;
    cbType11: TComboBox;
    cbType14: TComboBox;
    cbType10: TComboBox;
    lContents15: TLabel;
    lContents14: TLabel;
    lContents13: TLabel;
    lContents12: TLabel;
    lContents11: TLabel;
    lContents10: TLabel;
    BitBtn1: TBitBtn;
    Label1: TLabel;
    Label2: TLabel;
    cbType19: TComboBox;
    lContents19: TLabel;
    lContents18: TLabel;
    lContents17: TLabel;
    lContents16: TLabel;
    cbType16: TComboBox;
    cbType17: TComboBox;
    cbType18: TComboBox;
    cbType20: TComboBox;
    lContents20: TLabel;
    procedure ProcessFile(const fn : string);
    procedure bHelpClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
    procedure cbType1Change(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    FFieldCount : integer;

    function GetFieldCount(aRow : string): integer;
  public
    { Public declarations }
  end;

var
  frmCSVProcess: TfrmCSVProcess;

function GetCSVDataFormat(const filename : string): TCSVDataFormat;

implementation

{$R *.dfm}

uses
  X.Global, X.Constants, X.Dialogs.Dialog;

var
 LabelList : array[0..MaxCSVFields] of TLabel;
 ComboList : array[0..MaxCSVFields] of TComboBox;


function GetCSVDataFormat(const filename : string): TCSVDataFormat;
 var
  t : integer;

begin
  with TfrmCSVProcess.Create(Application) do
    try
      LabelList[0]  := lContents1;  LabelList[1]  := lContents2;  LabelList[2]  := lContents3;  LabelList[3]  := lContents4;  LabelList[4]  := lContents5;
      LabelList[5]  := lContents6;  LabelList[6]  := lContents7;  LabelList[7]  := lContents8;  LabelList[8]  := lContents9;  LabelList[9]  := lContents10;
      LabelList[10] := lContents11; LabelList[11] := lContents12; LabelList[12] := lContents13; LabelList[13] := lContents14; LabelList[14] := lContents15;
      LabelList[15] := lContents16; LabelList[16] := lContents17; LabelList[17] := lContents18; LabelList[18] := lContents19; LabelList[19] := lContents20;

      ComboList[0]  := cbType1;     ComboList[1]  := cbType2;   ComboList[2]  := cbType3;   ComboList[3]  := cbType4;
      ComboList[4]  := cbType5;     ComboList[5]  := cbType6;   ComboList[6]  := cbType7;   ComboList[7]  := cbType8;
      ComboList[8]  := cbType9;     ComboList[9]  := cbType10;  ComboList[10] := cbType11;  ComboList[11] := cbType12;
      ComboList[12] := cbType13;    ComboList[13] := cbType14;  ComboList[14] := cbType15;  ComboList[15] := cbType16;
      ComboList[16] := cbType17;    ComboList[17] := cbType18;  ComboList[18] := cbType19;  ComboList[19] := cbType20;

      lFilename.Caption := filename;
      lFilename.Hint    := filename;

      ShowModal;

      if ModalResult = mrOK then begin
        for t := 0 to MaxCSVFields do
          Result.Fields[t] := ComboList[t].ItemIndex;

        Result.IgnoreFirstRecord := cbIFR.Checked;
      end
      else begin
        for t := 0 to MaxCSVFields do
          Result.Fields[t] := -1;
      end;
    finally
      free;
    end;
end;

procedure TfrmCSVProcess.FormCreate(Sender: TObject);
begin
  Caption := XText[rsImportCSVData];
end;

procedure TfrmCSVProcess.FormShow(Sender: TObject);
var
  x, t : integer;

begin
  Label1.Caption := XText[rsFieldDataType];
  Label2.Caption := XText[rsContentsFirstRecord];
  Label3.Caption := XText[rsFilename];

  for x := 0 to MaxCSVFields do begin
    ComboList[x].Items.Add(XText[rsIgnore]);
    ComboList[x].Items.Add(XText[rsFullFilePath]);
    ComboList[x].Items.Add(XText[rsFileSizeBytes]);
    ComboList[x].Items.Add(XText[rsFileSizeOnDisk]);
    ComboList[x].Items.Add(XText[rsCreatedDateDDMMYYYY]);
    ComboList[x].Items.Add(XText[rsCreatedDateMMDDYYYY]);
    ComboList[x].Items.Add(XText[rsModifiedDateDDMMYYYY]);
    ComboList[x].Items.Add(XText[rsModifiedDateMMDDYYYY]);
    ComboList[x].Items.Add(XText[rsAccessedDateDDMMYYYY]);
    ComboList[x].Items.Add(XText[rsAccessedDateMMDDYYYY]);
    ComboList[x].Items.Add(XText[rsFilePath]);
    ComboList[x].Items.Add(XText[rsFileName]);
    ComboList[x].Items.Add(XText[rsOwner]);
    ComboList[x].Items.Add(XText[rsCategory]);
    ComboList[x].Items.Add(XText[rsReadOnly]);
    ComboList[x].Items.Add(XText[rsHidden]);
    ComboList[x].Items.Add(XText[rsSystem]);
    ComboList[x].Items.Add(XText[rsArchive]);
    ComboList[x].Items.Add(XText[rsTemporary]);
    ComboList[x].Items.Add(XText[rsFileAttributes]);
    ComboList[x].Items.Add(XText[rsCreated] + ' ' + XText[rsTime] + ' (HHMM)');
    ComboList[x].Items.Add(XText[rsAccessed] + ' ' + XText[rsTime] + ' (HHMM)');
    ComboList[x].Items.Add(XText[rsModified] + ' ' + XText[rsTime] + ' (HHMM)');
  end;

  cbIFR.Caption   := XText[rsIgnoreFirstRecord];
  bHelp.Caption   := XText[rsHelp];
  bImport.Caption := XText[rsImport];
  bCancel.Caption := XText[rsCancel];

  for t := 0 to MaxCSVFields do begin
    LabelList[t].Caption   := '';
    LabelList[t].Visible   := False;
    ComboList[t].ItemIndex := 0;
  end;

  ProcessFile(lFilename.Caption);
end;

procedure TfrmCSVProcess.ProcessFile(const fn : string);
 var
  tf : TextFile;
  s,r : string;
  t,i : integer;
  inquotes, processthisfield : boolean;

 begin
  AssignFile(tf, fn);
  {$I-}
  Reset(tf);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsWarning],
                XText[rsErrorOpening] + ' "' + fn + '".',
                XDialogTypeWarning);
  end
  else begin
    repeat
      Readln(tf, s);
    until (Pos(',', s) <> 0) or (eof(tf));

    CloseFile(tf);
  end;
  {$I+}

  if Pos(',', s) <> 0 then begin
    FFieldCount := GetFieldCount(s);

    r                := '';
    i                := 0;
    inquotes         := False;
    processthisfield := False;

    for t := 1 to length(s) do begin

      case s[t] of
        '"' : begin
                if inquotes then begin
                  case s[t + 1] of
                    ',' : inquotes := False;
                  else
                    r := r + s[t];
                  end;
                end
                else
                  inquotes := not(inquotes);
              end;
        ',' : begin
                if not(inquotes) then
                  processthisfield := True;
              end;
      else
        r := r + s[t];
      end;

      if processthisfield then begin
        if i <= MaxCSVFields then begin
          LabelList[i].Caption := r;
          LabelList[i].Visible := True;
          ComboList[i].Visible := True;
        end;

        processthisfield := False;

        r := '';

        inc(i);
      end;
    end;

    if i <= MaxCSVFields then begin
      LabelList[i].Caption := r;
      LabelList[i].Visible := True;
      ComboList[i].Visible := True;
    end;
  end
  else
    ShowXDialog(XText[rsWarning], XText[rsBadCSVFile], XDialogTypeWarning);
end;

procedure TfrmCSVProcess.bHelpClick(Sender: TObject);
 begin
  THelp.OpenHelpPage('w21.htm');
end;

procedure TfrmCSVProcess.BitBtn1Click(Sender: TObject);
 begin
  cbType1.ItemIndex  := CFieldFileName;
  cbType2.ItemIndex  := CFieldFullFilePath;
  cbType3.ItemIndex  := CFieldIgnore;
  cbType4.ItemIndex  := CFieldFileSizeBytes;
  cbType5.ItemIndex  := CFieldFileSizeOnDIsk;
  cbType6.ItemIndex  := CFieldCreatedDDMMYYYY;
  cbType7.ItemIndex  := CFieldModifiedDDMMYYYY;
  cbType8.ItemIndex  := CFieldAccessedDDMMYYYY;
  cbType9.ItemIndex  := CFieldCreatedTimeHHMMSS;
  cbType10.ItemIndex := CFieldModifiedTimeHHMMSS;
  cbType11.ItemIndex := CFieldAccessedTimeHHMMSS;
  cbType12.ItemIndex := CFieldIgnore;
  cbType13.ItemIndex := CFieldCategory;
  cbType14.ItemIndex := CFieldOwner;
  cbType15.ItemIndex := CFieldReadOnly;
  cbType16.ItemIndex := CFieldHidden;
  cbType17.ItemIndex := CFieldSystem;
  cbType18.ItemIndex := CFieldArchive;
  cbType19.ItemIndex := CFieldTemp;

  if FFieldCount = 20 then begin
    cbType20.ItemIndex := CFieldAttributes;
  end
  else begin
    cbType20.ItemIndex := CFieldIgnore;
  end;

  cbType1Change(cbType2);
  cbType1Change(cbType3);
  cbType1Change(cbType9);
end;

procedure TfrmCSVProcess.cbType1Change(Sender: TObject);

 function IsNumber(s : string): boolean;
  var
   t : integer;

  begin
   Result := True;

   for t := 1to length(s) do
     if (ord(s[t]) < 48) or (ord(s[t]) > 57) then
       Result := False;
 end;

 begin
  case TComboBox(Sender).ItemIndex of
     2 : if not(IsNumber(LabelList[TComboBox(Sender).ItemIndex].Caption)) then
           cbIFR.Checked := True;
     3 : if not(IsNumber(LabelList[TComboBox(Sender).ItemIndex].Caption)) then
           cbIFR.Checked := True;
    13 : if not(IsNumber(LabelList[TComboBox(Sender).ItemIndex].Caption)) then
           cbIFR.Checked := True;
  end;
end;


function TfrmCSVProcess.GetFieldCount(aRow : string): integer;
var
  t : integer;
  count : integer;
  inString : boolean;

begin
  count    := 1;
  inString := False;

  for t := 1 to length(aRow) do begin
    if aRow[t] = '"' then begin
      if inString then
        inString := False
      else
        inString := True;
    end
    else if aRow[t] = ',' then begin
      if not(inString) then
        inc(count);
    end;
  end;

  Result := count;
end;


end.
