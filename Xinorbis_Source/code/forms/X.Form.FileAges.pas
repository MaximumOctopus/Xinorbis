{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Created: March 23rd 2011
  Last Modified: January 11th 2020
}


unit X.Form.FileAges;

interface

uses
  Generics.Defaults, Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, Buttons, ExtCtrls, Grids, BaseGrid, AdvGrid, AdvObj,
  AdvOfficeButtons, DBAdvOfficeButtons, HTMLabel, AdvUtil,

  TMSLogging,

  X.GuiLogic,

  X.Dialogs.Save,

  X.Formatting, X.LanguageHandler, X.SystemGlobal, Vcl.Dialogs;


type
  TfrmFileAges = class(TForm)
    Panel1: TPanel;
    bGo: TBitBtn;
    bHelp: TBitBtn;
    BitBtn1: TBitBtn;
    BitBtn2: TBitBtn;
    Panel2: TPanel;
    sgResults: TAdvStringGrid;
    Panel23: TPanel;
    gbUsers: TGroupBox;
    cbUsers: TComboBox;
    cbFiles: TAdvOfficeCheckBox;
    cbFolders: TAdvOfficeCheckBox;
    cbAutoRefresh: TAdvOfficeCheckBox;
    cbAttribute: TComboBox;
    cbFileAgeType: TComboBox;
    cbInterval: TComboBox;
    eCount: TEdit;
    lStatus: THTMLabel;
    procedure FormCreate(Sender: TObject);
    procedure bGoClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormResize(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
    procedure sgResultsCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
    procedure ExportDataTo(mode : integer; const filename : string);
    procedure FormCanResize(Sender: TObject; var NewWidth, NewHeight: Integer;
      var Resize: Boolean);
    procedure cbAttributeChange(Sender: TObject);
    procedure eCountKeyPress(Sender: TObject; var Key: Char);
    procedure eCountEnter(Sender: TObject);
    procedure eCountExit(Sender: TObject);
    procedure sgResultsGetCellColor(Sender: TObject; ARow, ACol: Integer;
      AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
    procedure sgResultsGetAlignment(Sender: TObject; ARow, ACol: Integer;
      var HAlign: TAlignment; var VAlign: TVAlignment);
  private
    FDataIndex : integer;

    FOldText   : string;

    FULSP : TUpdateLeftStatusPanel;
  public
    property OnHide : TUpdateLeftStatusPanel read FULSP write FULSP;
  end;

var
  frmFileAges: TfrmFileAges;

procedure DoFileAges(whichDataIndex : integer);


implementation


{$R *.dfm}


uses X.Utility, dateutils, X.Global, X.GlobalObjects,

     X.Conversions, X.Settings, X.CFileObject, X.Constants, X.CUserData;


const
  CAttributeCreated  = 0;
  CAttributeAccessed = 1;
  CAttributeModified = 2;

  CIntervalDay       = 0;
  CIntervalWeek      = 1;
  CIntervalMonth     = 2;
  CIntervalYear      = 3;

  CModeCSV           = 0;
  CModeXML           = 1;

  CTypeOlderThan     = 0;
  CTypeWithinTheLast = 1;


procedure DoFileAges(whichDataIndex : integer);
begin
  frmFileAges.FDataIndex := whichDataIndex;

  frmFileAges.Show;
end;


procedure TfrmFileAges.FormCreate(Sender: TObject);
var
  fd : TFormDetails;
begin
  Caption               := XText[rsFileAge];

  bGo.Caption           := XText[rsShow];
  cbAutoRefresh.Caption := XText[rsAutoRefresh];

  cbFiles.Caption   := XText[rsFiles];
  cbFolders.Caption := XText[rsFolders];

  cbAttribute.Items.Add(XText[rsCreated]);
  cbAttribute.Items.Add(XText[rsAccessed]);
  cbAttribute.Items.Add(XText[rsModified]);
  cbAttribute.ItemIndex := 0;

  sgResults.Cells[0, 0] := XText[rsFilename];
  sgResults.Cells[1, 0] := XText[rsCreated];
  sgResults.Cells[2, 0] := XText[rsAccessed];
  sgResults.Cells[3, 0] := XText[rsModified];
  sgResults.Cells[4, 0] := XText[rsSize];

  sgResults.HideColumn(5);

  cbFileAgeType.Items.Add(XText[rsOlderThan]);
  cbFileAgeType.Items.Add(XText[rsWithinTheLast]);
  cbFileAgeType.ItemIndex := 0;

  cbInterval.Items.Add(XText[rsDay]);
  cbInterval.Items.Add(XText[rsWeek]);
  cbInterval.Items.Add(XText[rsMonth]);
  cbInterval.Items.Add(XText[rsYear]);

  cbInterval.ItemIndex := CIntervalDay;

  // ===========================================================================

  fd := XSettings.LoadFormDetails(_FormFileAges);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;
end;


procedure TfrmFileAges.FormResize(Sender: TObject);
 begin
  sgResults.ColWidths[0] := sgResults.Width - (_WidthOfScrollbar + 256);
end;


procedure TfrmFileAges.FormShow(Sender: TObject);
var
  t : integer;
  
begin
  FormResize(Nil);

  // ===========================================================================  

  gbUsers.Caption := XText[rsUsers];

  cbUsers.Items.Add(XText[rsAll]);

  for t := 0 to GScanDetails[FDataIndex].Users.Count - 1 do begin
    cbUsers.Items.Add(GScanDetails[FDataIndex].Users[t].Name);
  end;

  cbUsers.ItemIndex := 0;

  // ===========================================================================
end;


procedure TfrmFileAges.sgResultsCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
begin
  if Acol = 4 then begin
    DoSort := False; // stops the component for sorting automatically

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction := sdAscending
      else
        SortSettings.Direction := sdDescending;

      Sortsettings.Column := 5;
      QSort;

      SortSettings.Column := 4;
    end;
  end
end;


procedure TfrmFileAges.FormCanResize(Sender: TObject; var NewWidth,
  NewHeight: Integer; var Resize: Boolean);
begin
  if (NewHeight > 404) and (NewWidth > 740) then
    Resize := True
  else
    Resize := False;
end;


procedure TfrmFileAges.FormClose(Sender: TObject; var Action: TCloseAction);
var
  fd : TFormDetails;

begin
  fd.formID := _FormFileAges;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  if Assigned(FULSP) then
    FULSP(_FormFileAges);

  Action := caHide;
end;


procedure TfrmFileAges.sgResultsGetAlignment(Sender: TObject; ARow,
  ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  if (ACol = 4) then
    HAlign := taRightJustify
  else
    HAlign := taLeftJustify;
end;


procedure TfrmFileAges.sgResultsGetCellColor(Sender: TObject; ARow,
  ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
begin
  if gdSelected in AState then
    ABrush.Color := CGridColourSelected
  else begin
    if Odd(ARow) then
      ABrush.Color := CGridColourOn
    else
      ABrush.Color := CGridColourOff;
  end;
end;


procedure TfrmFileAges.bGoClick(Sender: TObject);
var
  dt, fcount, userid,ix, addcount,t : integer;
  tfo : TFileObject;
  addto,checkuser : boolean;
  fsize : int64;

begin
  Cursor := crHourGlass;

  if bGo.Tag <> cbAttribute.ItemIndex then begin
    case cbAttribute.ItemIndex of
      CAttributeCreated  : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesCreated));
      CAttributeAccessed : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
      CAttributeModified : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
    end;

    bGo.Tag := cbAttribute.ItemIndex;
  end;

  sgResults.ClearRows(1, sgResults.RowCount - 1);
  sgResults.RowCount := 2;
  sgResults.BeginUpdate;

  ix := StrToIntDef(eCount.Text, 30);

  // ===========================================================================
  // ===========================================================================

  case cbInterval.ItemIndex of
    CIntervalDay   : dt := TConvert.DateToYYYYMMDDI(IncDay(Now, -ix));          // day
    CIntervalWeek  : dt := TConvert.DateToYYYYMMDDI(IncWeek(Now, -ix));         // week
    CIntervalMonth : dt := TConvert.DateToYYYYMMDDI(IncMonth(Now, -ix));        // month
    CIntervalYear  : dt := TConvert.DateToYYYYMMDDI(IncMonth(Now, -(12 * ix))); // year
  else
    dt := TConvert.DateToYYYYMMDDI(IncDay(Now, -ix));
  end;

  // ===========================================================================
  // ===========================================================================

  addcount := 1;
  fsize    := 0;
  fcount   := 0;
  userid   := -1;

  if cbUsers.ItemIndex = 0 then
    userid := TUtility.FindUserIndex(FDataIndex, cbUsers.Items[cbUsers.ItemIndex]);

  checkuser := True;

  // ===========================================================================
  // ===========================================================================  

  case cbFileAgeType.ItemIndex of
    CTypeOlderThan     : begin
                           for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
                             tfo := GScanDetails[FDataIndex].Files[t];

                             if userid <> -1 then begin
                               if tfo.Owner = userid then
                                 checkuser := True
                               else
                                 checkuser := False;
                             end;

                             if (checkuser) and (((((faDirectory and tfo.Attributes) = faDirectory) and (cbFolders.Checked)) or
                                (((faDirectory and tfo.Attributes) <> faDirectory) and (cbFiles.Checked)))) then begin

                               addto := False;

                               case cbAttribute.ItemIndex of
                                 CAttributeCreated  : if tfo.FileDateC <= dt then addto := True;
                                 CAttributeAccessed : if tfo.FileDateA <= dt then addto := True;
                                 CAttributeModified : if tfo.FileDateM <= dt then addto := True;
                               end;

                               if (addto) then begin
                                 inc(fsize, tfo.FileSize);
                                 inc(fcount);

                                 if (addcount < 1000) then begin
                                   sgResults.Cells[0, addcount] := GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName;

                                   sgResults.Cells[1, addcount] := TConvert.IntDateToString(tfo.FileDateC);
                                   sgResults.Cells[2, addcount] := TConvert.IntDateToString(tfo.FileDateA);
                                   sgResults.Cells[3, addcount] := TConvert.IntDateToString(tfo.FileDateM);

                                   if (faDirectory and tfo.Attributes) = faDirectory then begin
                                     sgResults.Cells[4, addcount] := XText[rsFolder];
                                     sgResults.Cells[5, addcount] := '0';
                                   end
                                   else begin
                                     sgResults.Cells[4, addcount] := TConvert.ConvertToUsefulUnit(tfo.FileSize);
                                     sgResults.Cells[5, addcount] := IntToStr(tfo.FileSize);
                                   end;

                                   sgResults.RowCount := sgResults.RowCount + 1;

                                   inc(addcount);
                                 end;
                               end;
                             end;
                           end;
                         end;
    CTypeWithinTheLast : begin
                           for t:= GScanDetails[FDataIndex].Files.Count - 1 downto 0 do begin
                             tfo := GScanDetails[FDataIndex].Files[t];

                             if userid <> -1 then begin
                               if tfo.Owner=userid then
                                 checkuser := True
                               else
                                 checkuser := False;
                             end;

                             if (checkuser) and (((((faDirectory and tfo.Attributes) = faDirectory) and (cbFolders.Checked)) or
                                (((faDirectory and tfo.Attributes) <> faDirectory) and (cbFiles.Checked)))) then begin

                               addto := False;

                               case cbAttribute.ItemIndex of
                                 CAttributeCreated  : if tfo.FileDateC >= dt then addto := True;
                                 CAttributeAccessed : if tfo.FileDateA >= dt then addto := True;
                                 CAttributeModified : if tfo.FileDateM <= dt then addto := True;
                               end;

                               if (addto) then begin
                                 inc(fsize, tfo.FileSize);
                                 inc(fcount);

                                 if (addcount < 1000) then begin
                                   sgResults.Cells[0, addcount] := GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName;

                                   sgResults.Cells[1, addcount] := TConvert.IntDateToString(tfo.FileDateC);
                                   sgResults.Cells[2, addcount] := TConvert.IntDateToString(tfo.FileDateA);
                                   sgResults.Cells[3, addcount] := TConvert.IntDateToString(tfo.FileDateM);

                                   if (faDirectory and tfo.Attributes)=faDirectory then begin
                                     sgResults.Cells[4, addcount] := XText[rsFolder];
                                     sgResults.Cells[5, addcount] := '0';
                                   end
                                   else begin
                                     sgResults.Cells[4, addcount] := TConvert.ConvertToUsefulUnit(tfo.FileSize);
                                     sgResults.Cells[5, addcount] := IntToStr(tfo.FileSize);
                                   end;

                                   sgResults.RowCount := sgResults.RowCount + 1;

                                   inc(addcount);
                                 end;
                               end;
                             end;
                           end;
                         end;
  end;

  if addcount <> 1 then
    sgResults.RowCount := sgResults.RowCount - 1
  else
    sgResults.Cells[0, 1] := XText[rsNoMatchesFound];

  sgResults.EndUpdate;

  lStatus.HTMLText[0] := '<b>' + IntToStr(fcount) + '</b> ' + XText[rsFiles] + ' (<b>' + TConvert.ConvertToUsefulUnit(fsize) + '</b>)';

  Cursor := crDefault;
end;


procedure TfrmFileAges.BitBtn1Click(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsCSVFiles] + ' (*.csv)|*.csv',
                                    '.csv',
                                    TUtility.GetDefaultFileName('.csv', XText[rsFileAge] + '_' + XText[rsReport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    ExportDataTo(0, lFileName);
  end;
end;


procedure TfrmFileAges.BitBtn2Click(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsXMLFiles] + ' (*.xml)|*.xml',
                                    '.xml',
                                    TUtility.GetDefaultFileName('.xml',  XText[rsFileAge] + '_' + XText[rsReport]),
                                    GSystemGlobal.AppDataPath);

  if lFileName <> '' then begin
    ExportDataTo(1, lFileName);
  end;
end;


procedure TfrmFileAges.cbAttributeChange(Sender: TObject);
begin
  if cbAutoRefresh.Checked then
    bGoClick(Nil);
end;


procedure TfrmFileAges.eCountEnter(Sender: TObject);
begin
  FOldText := eCount.Text;
end;


procedure TfrmFileAges.eCountExit(Sender: TObject);
var
  lValue : integer;

begin
  lValue := StrToIntDef(eCount.Text, -1);

  if lValue = -1 then
    eCount.Text := FOldText;
end;


procedure TfrmFileAges.eCountKeyPress(Sender: TObject; var Key: Char);
begin
  if (key = #13) and (cbAutoRefresh.Checked) then
    bGoClick(Nil);
end;


procedure TfrmFileAges.ExportDataTo(mode : integer; const filename : string);
var
  dt : integer;
  ix, t : integer;
  tfo : TFileObject;
  addto : boolean;
  wp : TextFile;
  s : string;

  procedure WriteCSVObject;
  begin
    if (faDirectory and tfo.Attributes) = faDirectory then begin
      s := '"' + GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.FileName + '",';
      s := '"' + GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + '","' + tfo.FileName + '",';

      s := s + UpperCase(XText[rsFolder]) + ',';
      s := s + '-1' + ',';
      s := s + '-1' + ',';

      s := s + TConvert.IntDateToString(tfo.FileDateC) + ',';
      s := s + TConvert.IntDateToString(tfo.FileDateA) + ',';
      s := s + TConvert.IntDateToString(tfo.FileDateM) + ',';

      s := s + UpperCase(XText[rsFolder]) + ',';

      s := s + '99' + ',';

      s := s + GScanDetails[FDataIndex].Users[tfo.Owner].Name + ',';

      s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly) + ',';
      s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faHidden) + ',';
      s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faSysFile) + ',';
      s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faArchive) + ',';
      s := s + IntToStr(TConvert.BoolToInteger(tfo.Temp)) + ',';

      s := s + IntToStr(DaysBetween(Now, TConvert.IntegerDateToTDate(tfo.FileDateC))) + ',';
      s := s + IntToStr(DaysBetween(Now, TConvert.IntegerDateToTDate(tfo.FileDateA))) + ',';
      s := s + IntToStr(DaysBetween(Now, TConvert.IntegerDateToTDate(tfo.FileDateM)));
    end
    else begin
      s := '"' + GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.Filename + '",';
      s := '"' + GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + '","' + tfo.FileName + '",';

      s := s + '"' + TConvert.GetSizeString(0, tfo.FileSize) + '",';
      s := s + '"' + IntToStr(tfo.FileSize) + '",';
      s := s + '"' + IntToStr(tfo.FileSizeOnDisk) + '",';

      s := s + TConvert.IntDateToString(tfo.FileDateC) + ',';
      s := s + TConvert.IntDateToString(tfo.FileDateA) + ',';
      s := s + TConvert.IntDateToString(tfo.FileDateM) + ',';

      s := s + TypeDescriptions[tfo.FileCategory] + ',';

      s := s + IntToStr(tfo.FileCategory) + ',';

      s := s + GScanDetails[FDataIndex].Users[tfo.Owner].Name + ',';

      s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly) + ',';
      s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faHidden) + ',';
      s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faSysFile) + ',';
      s := s + TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faArchive) + ',';
      s := s + IntToStr(TConvert.BoolToInteger(tfo.Temp)) + ',';

      s := s + IntToStr(DaysBetween(Now, TConvert.IntegerDateToTDate(tfo.FileDateC))) + ',';
      s := s + IntToStr(DaysBetween(Now, TConvert.IntegerDateToTDate(tfo.FileDateA))) + ',';
      s := s + IntToStr(DaysBetween(Now, TConvert.IntegerDateToTDate(tfo.FileDateM)));
    end;

    Writeln(wp, s);
  end;

  procedure WriteXMLObject;
  
   function BoolToString(fish : boolean): String;
    begin
     if fish then
       Result := '1'
     else
       Result := '0';
   end;

   begin
    Writeln(wp, '    <file>');
    Writeln(wp, TXFormatting.InsertElement('name',                 TXFormatting.ReplaceEntitiesForXML(tfo.FileName), 2));
    Writeln(wp, TXFormatting.InsertElement('path',                 TXFormatting.ReplaceEntitiesForXML(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex]), 2));
    Writeln(wp, TXFormatting.InsertElement('sizewords',            TConvert.ConvertToUsefulUnit(tfo.FileSize), 2));
    Writeln(wp, TXFormatting.InsertElement('sizebytes',            IntToStr(tfo.FileSize), 2));
    Writeln(wp, TXFormatting.InsertElement('sizeondiskwords',      TConvert.ConvertToUsefulUnit(tfo.FileSizeOnDisk), 2));
    Writeln(wp, TXFormatting.InsertElement('sizeondiskbytes',      IntToStr(tfo.FileSizeOnDisk), 2));
    Writeln(wp, TXFormatting.InsertElement('owner',                GScanDetails[FDataIndex].Users[tfo.Owner].Name, 2));
    Writeln(wp, TXFormatting.InsertElement('datecreated',          TConvert.IntDateToString(tfo.FileDateC), 2));
    Writeln(wp, TXFormatting.InsertElement('datemodified',         TConvert.IntDateToString(tfo.FileDateM), 2));
    Writeln(wp, TXFormatting.InsertElement('dateaccessed',         TConvert.IntDateToString(tfo.FileDateA), 2));
    Writeln(wp, TXFormatting.InsertElement('datecreatedyyyymmdd',  IntToStr(tfo.FileDateC), 2));
    Writeln(wp, TXFormatting.InsertElement('datemodifiedyyyymmdd', IntToStr(tfo.FileDateM), 2));
    Writeln(wp, TXFormatting.InsertElement('dateaccessedyyyymmdd', IntToStr(tfo.FileDateA), 2));
    Writeln(wp, TXFormatting.InsertElement('category',             IntToStr(tfo.FileCategory), 2));
    Writeln(wp, TXFormatting.InsertElement('directory',            TConvert.AttributeToIntAsString(tfo.Attributes, faDirectory), 2));
    Writeln(wp, TXFormatting.InsertElement('readonly',             TConvert.AttributeToIntAsString(tfo.Attributes, Sysutils.faReadOnly), 2));
    Writeln(wp, TXFormatting.InsertElement('hidden',               TConvert.AttributeToIntAsString(tfo.Attributes, faHidden), 2));
    Writeln(wp, TXFormatting.InsertElement('system',               TConvert.AttributeToIntAsString(tfo.Attributes, faSysFile), 2));
    Writeln(wp, TXFormatting.InsertElement('archive',              TConvert.AttributeToIntAsString(tfo.Attributes, faArchive), 2));
    Writeln(wp, TXFormatting.InsertElement('temp',                 BoolToString(tfo.Temp), 2));
    Writeln(wp, TXFormatting.InsertElement('createdagefulldays',   IntToStr(DaysBetween(Now, TConvert.IntegerDateToTDate(tfo.FileDateC))), 2));
    Writeln(wp, TXFormatting.InsertElement('accessedagefulldays',  IntToStr(DaysBetween(Now, TConvert.IntegerDateToTDate(tfo.FileDateA))), 2));
    Writeln(wp, TXFormatting.InsertElement('modifiedagefulldays',  IntToStr(DaysBetween(Now, TConvert.IntegerDateToTDate(tfo.FileDateM))), 2));
    Writeln(wp, '    </file>');
  end;

 begin
  if bGo.Tag <> cbAttribute.ItemIndex then begin
    case cbAttribute.ItemIndex of
      CAttributeCreated  : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesCreated));
      CAttributeAccessed : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
      CAttributeModified : GScanDetails[FDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
    end;

    bGo.Tag := cbAttribute.ItemIndex;
  end;

  ix := StrToIntDef(eCount.Text, 30);

  case mode of
    CModeCSV : begin // CSV
                 AssignFile(wp, Filename);
                {$I-}
                 Rewrite(wp);
                 {$I+}

                 if (IOResult <> 0) then begin
                   TMSLogger.Error('Error writing XML file "' + FileName + '".');
                 end
                 else begin
                   Writeln(wp, XText[rsFilePath]                   + ',' +
                               XText[rsFolder]                     + ',' +
                               XText[rsFileName]                   + ',' +
                               XText[rsSize]                       + ',' +
                               XText[rsSizeOfFilesBytes]           + ',' +
                               XText[rsSizeOnDisk]                 + ',' +
                               XText[rsCreatedDate]                + ',' +
                               XText[rsAccessedDate]               + ',' +
                               XText[rsModifiedDate]               + ',' +
                               XText[rsCategory]                   + ',' +
                               XText[rsCategory]                   + 'ID' + ',' +
                               XText[rsOwner]                      + ',' +
                               LanguageTypes[FileType_ReadOnly]    + ',' +
                               LanguageTypes[FileType_Hidden]      + ',' +
                               LanguageTypes[FileType_System]      + ',' +
                               LanguageTypes[FileType_Archive]     + ',' +
                               XText[rsTemporary]                  + ',' +
                               'CreatedAgeFullDays,'               +
                               'AccessedAgeFullDays,'              +
                              'ModifiedAgeFullDays');
                 end;
               end;
    CModeXML : begin
                 AssignFile(wp, Filename);
                 {$I-}
                 Rewrite(wp);
                 {$I+}

                 if (IOResult <> 0) then begin
                   TMSLogger.Error('Error writing XML file "' + FileName + '".');
                 end
                 else begin
                   Writeln(wp, '<?xml version="1.0"?>');
                   Writeln(wp, '<!-- generated with Xinorbis ' + x8Title + ' - ' + x8Date + ' -->');
                   Writeln(wp, '<!-- http://xinorbis.com - Paul A Freshney ' + TUtility.GetCurrentYear + ' -->');
                   Writeln(wp, '<!-- File Age: ' + cbAttribute.Text + ', ' + cbFileAgeType.Text + ', ' + eCount.Text + ', ' + cbInterval.Text + ' -->');
                   Writeln(wp, '<xinorbisfilelist>');
                 end;
               end;
  end;

  // ===========================================================================
  // ===========================================================================

  case cbInterval.ItemIndex of
    CIntervalDay   : dt := TConvert.DateToYYYYMMDDI(IncDay(Now,   -ix));        // day
    CIntervalWeek  : dt := TConvert.DateToYYYYMMDDI(IncWeek(Now,  -ix));        // week
    CIntervalMonth : dt := TConvert.DateToYYYYMMDDI(IncMonth(Now, -ix));        // month
    CIntervalYear  : dt := TConvert.DateToYYYYMMDDI(IncMonth(Now, -(12 * ix))); // year
  else
    dt := TConvert.DateToYYYYMMDDI(IncDay(Now, -ix));              // day
  end;

  // ===========================================================================
  // ===========================================================================

  case cbFileAgeType.ItemIndex of
    CTypeOlderThan     : begin
                           for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
                             tfo := GScanDetails[FDataIndex].Files[t];

                             addto := False;

                             case cbAttribute.ItemIndex of
                               CAttributeCreated  : if tfo.FileDateC <= dt then addto := True;
                               CAttributeAccessed : if tfo.FileDateA <= dt then addto := True;
                               CAttributeModified : if tfo.FileDateM <= dt then addto := True;
                             end;

                             if addto then begin
                               case mode of
                                 CModeCSV : begin
                                              WriteCSVObject;
                                            end;
                                 CModeXML : begin
                                              WriteXMLObject;
                                            end;
                               end;
                             end;
                           end;
                         end;
    CTypeWithinTheLast : begin
                           for t := GScanDetails[FDataIndex].Files.Count downto 0 do begin
                             tfo := GScanDetails[FDataIndex].Files[t];

                             addto := False;

                             case cbAttribute.ItemIndex of
                               CAttributeCreated  : if tfo.FileDateC >= dt then addto := True;
                               CAttributeAccessed : if tfo.FileDateA >= dt then addto := True;
                               CAttributeModified : if tfo.FileDateM >= dt then addto := True;
                             end;

                             if addto then begin
                               case mode of
                                 CModeCSV : begin
                                              WriteCSVObject;
                                            end;
                                 CModeXML : begin
                                              WriteXMLObject;
                                            end;
                               end;
                             end;
                           end;
                         end;
  end;

  case mode of
    CModeCSV : CloseFile(wp);
    CModeXML : begin
                 Writeln(wp, '</xinorbisfilelist>');

                 CloseFile(wp);
               end;
  end;
end;


end.
