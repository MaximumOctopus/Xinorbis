unit showcalendar;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Grids, BaseGrid, AdvGrid, ExtCtrls, StdCtrls, Spin, Buttons,
  CheckLst, AdvObj, AdvUtil;

type
  TfrmShowCalendar = class(TForm)
    lSelected: TLabel;
    lAvailableTimes: TLabel;
    Panel1: TPanel;
    Shape1: TShape;
    Shape2: TShape;
    Shape3: TShape;
    Shape4: TShape;
    Shape5: TShape;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Bevel2: TBevel;
    Bevel3: TBevel;
    SpinEdit1: TSpinEdit;
    cbTimes: TListBox;
    Panel2: TPanel;
    CheckBox1: TCheckBox;
    bUse: TBitBtn;
    bCancel: TBitBtn;
    Panel3: TPanel;
    Label6: TLabel;
    sgCalendar: TAdvStringGrid;
    procedure BuildDate(year : integer);
    procedure sgCalendarDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
    procedure SpinEdit1Change(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure sgCalendarClickCell(Sender: TObject; ARow, ACol: Integer);
    procedure cbTimesClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure SpinEdit1Enter(Sender: TObject);
    procedure SpinEdit1Exit(Sender: TObject);
  private
    FOldText : string;

    FileHistoryData  : array[1..37, 1..12] of integer;
    FileHistoryInput : TStringList;
    SelectedDate     : string;
    SelectedDateTime : string;
  public
    { Public declarations }
  end;

var
  frmShowCalendar: TfrmShowCalendar;


function DoShowCalendar(fhd : TStrings): string;


implementation

{$R *.dfm}


uses
  DateUtils, utility, xglobal, constants, conversions;


const
 GridColours : array[0..5] of integer = ($00EEEEEE, $00C6FFC9, $00C1FFFF, $00FFFFC0, $00B3C4FF, $00F9D7FF);


function DoShowCalendar(fhd : TStrings): string;
 var
  t : integer;

 begin
  with TfrmShowCalendar.Create(Application) do
    try
      FileHistoryInput   := TStringList.Create;

      Shape1.Brush.Color := GridColours[1];
      Shape2.Brush.Color := GridColours[2];
      Shape3.Brush.Color := GridColours[3];
      Shape4.Brush.Color := GridColours[4];
      Shape5.Brush.Color := GridColours[5];

      for t := 0 to fhd.Count - 1 do
        FileHistoryInput.Add(fhd[t]);

      ShowModal;

      if ModalResult = mrCancel then
        Result := ''
      else
        Result := SelectedDateTime;
    finally
      free;
    end;
end;

procedure TfrmShowCalendar.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  FileHistoryInput.Free;

  Action := caFree;
end;

procedure TfrmShowCalendar.FormShow(Sender: TObject);
 var
  mm,dd,yyyy : word;

 begin
  Caption                 := rsFolderHistory;
  bCancel.Caption         := rsCancel;
  lAvailableTimes.Caption := rsAvailableTimes;

  for mm := 0 to 36 do
    sgCalendar.Cells[mm+1, 0] := rsDayInitials[(mm mod 7) + 1];

  DecodeDate(Now, yyyy, mm, dd);

  SpinEdit1.Value := yyyy;

  BuildDate(yyyy);
end;

procedure TfrmShowCalendar.BuildDate(year : integer);
 var
  t, i, z  : integer;
  dt       : TDateTime;
  cmm, cdd, cyy : integer;
  xdate    : string;

 begin
  // ===========================================================================
  // == Build FileHistory array ================================================
  // ===========================================================================

  for t := 1 to 37 do
    for z := 1 to 12 do begin
      case t of
        6,7,13,14,20,21,27,28,34,35 : FileHistoryData[t, z] := 0;
      else
        FileHistoryData[t, z] := -1;
      end;
    end;

  for t := 0 to FileHistoryInput.Count - 1 do begin
    xdate := TConvert.DateTimeFToYYYYMMDD(FileHistoryInput[t]);

    cyy   := StrToInt(Copy(xdate, 1, 4));

    if cyy = year then begin
      cmm := StrToInt(Copy(xdate, 5, 2));
      cdd := StrToInt(Copy(xdate, 7, 2));

      dt := EncodeDate(cyy, cmm, 1);
      z  := DayOfTheWeek(dt);

      if FileHistoryData[(cdd + z) - 1, cmm] <= 0 then
        FileHistoryData[(cdd + z) - 1, cmm] := 1
      else begin
        if FileHistoryData[(cdd + z) - 1, cmm] < 5 then
          FileHistoryData[(cdd + z) - 1, cmm] := FileHistoryData[(cdd + z) - 1, cmm] + 1;
      end;
    end;
  end;

  // ===========================================================================
  // ===========================================================================

  sgCalendar.BeginUpdate;

  sgCalendar.ClearRows(1, 12);

  for t := 1 to 12 do begin
    sgCalendar.Cells[0, t] := Months[t];

    dt := EncodeDate(year, t, 1);

    z  := DayOfTheWeek(dt);

    for i := 1 to DaysInAMonth(year, t) do begin
      sgCalendar.Cells[(i + z) - 1, t] := IntToStr(i);
    end;
  end;

  sgCalendar.EndUpdate;
end;

procedure TfrmShowCalendar.sgCalendarDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
 begin
  if (ARow > 0) and (ACol > 0) then begin
    if FileHistoryData[ACol, ARow] <> -1 then begin
      TAdvStringGrid(Sender).Canvas.Brush.Color := GridColours[FileHistoryData[ACol, ARow]];
      TAdvStringGrid(Sender).Canvas.FillRect(Rect);
      TAdvStringGrid(Sender).Canvas.TextOut(Rect.Left + 5, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
    end;
  end;
end;

procedure TfrmShowCalendar.SpinEdit1Change(Sender: TObject);
 begin
  BuildDate(SpinEdit1.Value);
end;

procedure TfrmShowCalendar.SpinEdit1Enter(Sender: TObject);
begin
  FOldText := SpinEdit1.Text;
end;

procedure TfrmShowCalendar.SpinEdit1Exit(Sender: TObject);
var
  lValue : integer;
begin
  lValue := StrToIntDef(SpinEdit1.Text, -1);

  if lValue = -1 then
    SpinEdit1.Text := FOldText;
end;

procedure TfrmShowCalendar.sgCalendarClickCell(Sender: TObject; ARow, ACol: Integer);
 var
  temp : string;
  t : integer;

 begin
  SelectedDate      := '';

  lSelected.Caption := '';
  bUse.Enabled      := False;
  cbTimes.Clear;
  
  if (ARow > 1) and (ACol > 1) then begin
    if sgCalendar.Cells[ACol, ARow] <> '' then begin
      SelectedDate := IntToStr(SpinEdit1.Value);

      if ARow < 10 then
        SelectedDate := SelectedDate + '0' + IntToStr(ARow)
      else
        SelectedDate := SelectedDate + IntToStr(ARow);

      if StrToInt(sgCalendar.Cells[ACol, ARow]) < 10 then
        SelectedDate := SelectedDate + '0' + sgCalendar.Cells[ACol, ARow]
      else
        SelectedDate := SelectedDate+sgCalendar.Cells[ACol, ARow];

      temp := TConvert.IntDateToString(StrToInt(SelectedDate));

      for t := 0 to FileHistoryInput.Count - 1 do begin
        if Pos(temp, FileHistoryInput[t]) <> 0 then begin
          cbTimes.Items.Add(Copy(FileHistoryInput[t], 12, 8));
        end;
      end;

      if cbTimes.Count = 1 then begin
        cbTimes.ItemIndex := 0;

        cbTimesClick(Nil);
      end;
    end
    else begin
    end;
  end
  else begin
  end;
end;

procedure TfrmShowCalendar.cbTimesClick(Sender: TObject);
 var
  s : string;

 begin
  if cbTimes.ItemIndex >= 0 then begin
    s := cbTimes.Items[cbTimes.ItemIndex];

    SelectedDateTime  := SelectedDate + s[1] + s[2] + s[4] + s[5] + s[7] + s[8];

    lSelected.Caption := TConvert.IntDateToString(StrToInt(SelectedDate)) + ' ' + s;

    bUse.Enabled := True;
  end;
end;

end.
