// (c) Paul Alan Freshney 2019
//
//  Started: June 10th 2006
// Modified: January 16th 2019
//
// 822

unit X.Form.Explore;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms, dialogs,
  Grids, BaseGrid, AdvGrid, ComCtrls, ToolWin, StdCtrls, Buttons, System.StrUtils,
  ExtCtrls, CheckLst, AdvObj, AdvOfficeButtons, HTMLabel, AdvUtil,
  System.ImageList, Vcl.ImgList,

  X.GuiLogic, X.Help, X.Windows,

  X.LanguageHandler, X.SystemGlobal, Vcl.Menus;

type
  TfrmExplore = class(TForm)
    Panel2: TPanel;
    bHelp: TBitBtn;
    bClose: TBitBtn;
    Panel3: TPanel;
    Bevel1: TBevel;
    sbBack: TSpeedButton;
    ScrollBox1: TScrollBox;
    pAttributes: TPanel;
    cbAHidden: TCheckBox;
    cbASystem: TCheckBox;
    cbAArchive: TCheckBox;
    cbAReadOnly: TCheckBox;
    cbATemp: TCheckBox;
    pOwner: TPanel;
    cbUSelect: TComboBox;
    eUContent: TEdit;
    pModified: TPanel;
    cbModified1: TComboBox;
    dtpModified1: TDateTimePicker;
    cbModified2: TComboBox;
    dtpModified2: TDateTimePicker;
    pAccessed: TPanel;
    cbAccessed1: TComboBox;
    dtpAccessed1: TDateTimePicker;
    cbAccessed2: TComboBox;
    dtpAccessed2: TDateTimePicker;
    pCreated: TPanel;
    cbCreated1: TComboBox;
    cbCreated2: TComboBox;
    dtpCreated2: TDateTimePicker;
    dtpCreated1: TDateTimePicker;
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
    pSize: TPanel;
    Label2: TLabel;
    Label3: TLabel;
    eSLT: TEdit;
    cbSLTUnit: TComboBox;
    eSGT: TEdit;
    cbSGTUnit: TComboBox;
    pContaining: TPanel;
    lContaining: TLabel;
    eContaining: TEdit;
    bFilter: TBitBtn;
    Panel1: TPanel;
    sgExplore: TAdvStringGrid;
    Panel4: TPanel;
    cbContaining: TAdvOfficeCheckBox;
    cbSize: TAdvOfficeCheckBox;
    cbCategory: TAdvOfficeCheckBox;
    cbAttributes: TAdvOfficeCheckBox;
    cbCreated: TAdvOfficeCheckBox;
    cbAccessed: TAdvOfficeCheckBox;
    cbModified: TAdvOfficeCheckBox;
    cbOwner: TAdvOfficeCheckBox;
    lData: THTMLabel;
    ilExplore: TImageList;
    PopupMenu1: TPopupMenu;
    miExploreFolder: TMenuItem;
    pNameLength: TPanel;
    cbNameLength: TAdvOfficeCheckBox;
    Label1: TLabel;
    eNLLT: TEdit;
    eNLGT: TEdit;
    Label4: TLabel;
    procedure FormShow(Sender: TObject);
    procedure FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure sgExploreResize(Sender: TObject);
    procedure sgExploreDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
    procedure FormKeyPress(Sender: TObject; var Key: Char);
    procedure sgExploreCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
    procedure sgExploreDblClickCell(Sender: TObject; ARow, ACol: Integer);
    procedure sbBackClick(Sender: TObject);
    procedure bHelpClick(Sender: TObject);
    procedure bCloseClick(Sender: TObject);
    procedure cbUSelectChange(Sender: TObject);
    procedure cbContainingClick(Sender: TObject);
    procedure bFilterClick(Sender: TObject);
    procedure CheckForValidSearch;
    procedure cbCreated1Change(Sender: TObject);
    procedure BuildFrom(const NewScanPath : String);
    procedure eSLTEnter(Sender: TObject);
    procedure eSLTExit(Sender: TObject);
    procedure sgExploreGetCellColor(Sender: TObject; ARow, ACol: Integer;
      AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
    procedure FormDestroy(Sender: TObject);
    procedure miExploreFolderClick(Sender: TObject);
    procedure sgExploreGetAlignment(Sender: TObject; ARow, ACol: Integer;
      var HAlign: TAlignment; var VAlign: TVAlignment);
  private
    FOldText : string;

    FDataIndex        : integer;
    DateControls      : array[1..6] of TDateTimePicker;
    CategoryControls  : array[1..19] of TCheckBox;
    DirectoryList     : TStringList;
    ExplorePath       : string;

    FULSP : TUpdateLeftStatusPanel;
  public
    property OnHide : TUpdateLeftStatusPanel read FULSP write FULSP;
  end;

var
  frmExplore: TfrmExplore;

procedure DoExplore(aDataIndex : integer; const path : string);


implementation

{$R *.dfm}

uses X.Utility, Types, X.Global, X.GlobalObjects,

     X.Conversions, X.Settings, X.CFileObject, X.Constants, X.CUserData;


const
  CUnitsBytes     = 0;
  CUnitsKilobytes = 1;
  CUnitsMegabytes = 2;
  CUnitsGigabytes = 3;

  colIcon            = 0;
  colFolderName      = 1;
  colFileCount       = 2;
  colFilesAsPercent  = 3;
  colSize            = 5;
  colSizeAsPercent   = 6;
  colFileCountPCache = 7;
  colSizePCache      = 8;
  colSizeCache       = 9;

  panelHeights       : array[0..5] of integer = (64, 89, 204,  121, 81, 65);


procedure DoExplore(aDataIndex : integer; const path : string);
begin
  frmExplore.DirectoryList.Add(path);

  frmExplore.ExplorePath := path;
  frmExplore.FDataIndex  := aDataIndex;

  frmExplore.Show;
end;


procedure TfrmExplore.FormCreate(Sender: TObject);
 var
  t : integer;
  fd : TFormDetails;
  lThings : array[1..3] of string;
begin
  DirectoryList := TStringList.Create;

  lThings[1] := XText[rsOn];
  lThings[2] := XText[rsBefore];
  lThings[3] := XText[rsAfter];

  fd := XSettings.LoadFormDetails(_FormExplore);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  sgExplore.Canvas.Brush.Color := $00FF4400;

  sgExplore.Cells[colFolderName,     0] := XText[rsFolder];
  sgExplore.Cells[colFileCount,      0] := '# ' + XText[rsFiles];
  sgExplore.Cells[colFilesAsPercent, 0] := XText[rsAsPercent];
  sgExplore.Cells[colSize,           0] := XText[rsSize];
  sgExplore.Cells[colSizeAsPercent,  0] := XText[rsAsPercent];

  sgExplore.HideColumn(7);
  sgExplore.HideColumn(8);
  sgExplore.HideColumn(9);

  // ===========================================================================

  miExploreFolder.Caption := XText[rsExploreFolder];

  // ===========================================================================

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

  bHelp.Caption        := XText[rsHelp];
  bClose.Caption       := XText[rsClose];

  cbContaining.Caption := XText[rsContainingText];
  cbSize.Caption       := XText[rsFileSize];
  cbCategory.Caption   := XText[rsCategory];
  cbAttributes.Caption := XText[rsFileAttributes];
  cbCreated.Caption    := XText[rsCreatedDate];
  cbAccessed.Caption   := XText[rsAccessedDate];
  cbModified.Caption   := XText[rsModifiedDate];
  cbOwner.Caption      := XText[rsFileOwner];
  cbNameLength.Caption := XText[rsFileNameLength];

  lContaining.Caption  := XText[rsContains];

  sbProg.Caption       := TypeDescriptions[1];
  sbSys.Caption        := TypeDescriptions[2];
  sbGfx.Caption        := TypeDescriptions[3];
  sbMovie.Caption      := TypeDescriptions[4];
  sbSnd.Caption        := TypeDescriptions[5];
  sbOffice.Caption     := TypeDescriptions[6];
  sbCode.Caption       := TypeDescriptions[7];
  sbCompressed.Caption := TypeDescriptions[8];
  sbOther.Caption      := TypeDescriptions[9];
  sbCustom1.Caption    := TypeDescriptions[10];
  sbCustom2.Caption    := TypeDescriptions[11];
  sbCustom3.Caption    := TypeDescriptions[12];
  sbCustom4.Caption    := TypeDescriptions[13];
  sbCustom5.Caption    := TypeDescriptions[14];
  sbCustom6.Caption    := TypeDescriptions[15];
  sbCustom7.Caption    := TypeDescriptions[16];
  sbCustom8.Caption    := TypeDescriptions[17];
  sbCustom9.Caption    := TypeDescriptions[18];
  sbCustom10.Caption   := TypeDescriptions[19];

  cbAHidden.Caption    := LanguageTypes[1];
  cbASystem.Caption    := LanguageTypes[2];
  cbAArchive.Caption   := LanguageTypes[3];
  cbAReadOnly.Caption  := LanguageTypes[5];
  cbATemp.Caption      := XText[rsTemporary];

  bFilter.Caption      := XText[rsFilter];

  // ===========================================================================

  DateControls[1]      := dtpCreated1;
  DateControls[2]      := dtpCreated2;
  DateControls[3]      := dtpAccessed1;
  DateControls[4]      := dtpAccessed2;
  DateControls[5]      := dtpModified1;
  DateControls[6]      := dtpModified2;

  for t := 1 to 6 do
    DateControls[t].DateTime := Now;

  cbUSelect.Items.Add(XText[rsEqualTo]);
  cbUSelect.Items.Add(XText[rsNotEqualTo]);
  cbUSelect.Items.Add(XText[rsContains]);
  cbUSelect.Items.Add(XText[rsDoesntContain]);


  cbUSelect.ItemIndex := 0;

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

  CategoryControls[1]  := sbProg;    CategoryControls[2]  := sbSys;     CategoryControls[3]  := sbGfx;      CategoryControls[4]  := sbMovie;
  CategoryControls[5]  := sbSnd;     CategoryControls[6]  := sbOffice;  CategoryControls[7]  := sbCode;     CategoryControls[8]  := sbCompressed;
  CategoryControls[9]  := sbOther;   CategoryControls[10] := sbCustom1; CategoryControls[11] := sbCustom2;  CategoryControls[12] := sbCustom3;
  CategoryControls[13] := sbCustom4; CategoryControls[14] := sbCustom5; CategoryControls[15] := sbCustom6;  CategoryControls[16] := sbCustom7;
  CategoryControls[17] := sbCustom8; CategoryControls[18] := sbCustom9; CategoryControls[19] := sbCustom10;
end;


procedure TfrmExplore.FormDestroy(Sender: TObject);
begin
  FreeAndNil(DirectoryList);
end;

procedure TfrmExplore.FormShow(Sender: TObject);
 begin
  Screen.Cursor := crHourGlass;

  BuildFrom(DirectoryList[0]);

  sgExploreResize(Nil);

  Screen.Cursor := crDefault;
end;


procedure TfrmExplore.miExploreFolderClick(Sender: TObject);
var
  s : string;

begin
  s := DirectoryList[DirectoryList.Count - 1] + sgExplore.Cells[colFolderName, sgExplore.Selection.Top] + '\';

  if s <> '' then
    TXWindows.ExecuteFile(0, s, '', '');
end;


procedure TfrmExplore.FormClose(Sender: TObject; var Action: TCloseAction);
 var
  fd : TFormDetails;

 begin
  fd.formID := _FormExplore;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  DirectoryList.Clear;

  if Assigned(FULSP) then
    FULSP(_FormExplore);

  Action := caHide;
end;


procedure TfrmExplore.sgExploreResize(Sender: TObject);
 begin
  sgExplore.ColWidths[0] := 18;
  sgExplore.ColWidths[1] := sgExplore.Width - 351;
  sgExplore.ColWidths[2] := 42;
  sgExplore.ColWidths[3] := 102;
  sgExplore.ColWidths[4] := 4;
  sgExplore.ColWidths[5] := 62;
  sgExplore.ColWidths[6] := 102;
end;


procedure TfrmExplore.FormConstrainedResize(Sender: TObject; var MinWidth, MinHeight, MaxWidth, MaxHeight: Integer);
 begin
  MinWidth  := 500;
  MinHeight := 210;
end;


procedure TfrmExplore.sgExploreDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
var
  zRect : TRect;

begin
  if ARow <> 0 then begin
    case ACol of
      colIcon           : begin
                            ilExplore.Draw(TAdvStringGrid(Sender).Canvas, Rect.Left + 1, Rect.Top, 0, True);
                          end;
      colFilesAsPercent : begin
                            TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[5];
                            TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

                            if TAdvStringGrid(Sender).Cells[colFileCountPCache, ARow] <> '0' then begin
                              zRect.Top    := Rect.Top + 1;
                              zRect.Bottom := Rect.Bottom - 1;
                              zRect.Left   := Rect.Left + 1;
                              zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[colFileCountPCache, ARow]);

                              TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[6];
                              TAdvStringGrid(Sender).Canvas.FillRect(zRect);
                            end;

                            TAdvStringGrid(Sender).Canvas.Brush.Style := bsClear;
                            TAdvStringGrid(Sender).Canvas.Font.Color  := clBlack;
                            TAdvStringGrid(Sender).Canvas.TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender).Cells[colFilesAsPercent, ARow]);
                          end;
      colSizeAsPercent  : begin
                            TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[5];
                            TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

                            if TAdvStringGrid(Sender).Cells[colSizePCache, ARow] <> '0' then begin
                              zRect.Top    := Rect.Top + 1;
                              zRect.Bottom := Rect.Bottom - 1;
                              zRect.Left   := Rect.Left + 1;
                              zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[colSizePCache, ARow]);

                              TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[6];
                              TAdvStringGrid(Sender).Canvas.FillRect(zRect);
                            end;

                            TAdvStringGrid(Sender).Canvas.Brush.Style := bsClear;
                            TAdvStringGrid(Sender).Canvas.Font.Color  := clBlack;
                            TAdvStringGrid(Sender).Canvas.TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender).Cells[colSizeAsPercent, ARow]);
                          end;
        end;
  end;
end;


procedure TfrmExplore.sgExploreGetAlignment(Sender: TObject; ARow,
  ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  if (ACol = colFileCount) or (ACol = colSize) then
    HAlign := taRightJustify
  else
    HAlign := taLeftJustify;
end;


procedure TfrmExplore.sgExploreGetCellColor(Sender: TObject; ARow,
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


procedure TfrmExplore.FormKeyPress(Sender: TObject; var Key: Char);
 begin
  if Key = #27 then Close;
end;


procedure TfrmExplore.sgExploreCanSort(Sender: TObject; ACol: Integer; var DoSort: Boolean);
 begin
  if (Acol = colFilesAsPercent) then begin
    DoSort := False;

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction := sdAscending
      else
        SortSettings.Direction := sdDescending;

      Sortsettings.Column := colFileCount;
      QSort;
      SortSettings.Column := Acol;
    end;
  end
  else if (Acol = colSize) or (ACol = colSizeAsPercent) then begin
    DoSort := False;

    with TAdvStringGrid(Sender) do begin
      if SortSettings.Direction = sdDescending then
        SortSettings.Direction := sdAscending
      else
        SortSettings.Direction := sdDescending;

      Sortsettings.Column := colSizeCache;
      QSort;
      SortSettings.Column := Acol;
    end;
  end;
end;


procedure TfrmExplore.sgExploreDblClickCell(Sender: TObject; ARow, ACol: Integer);
 begin
  if sgExplore.Cells[colFolderName, ARow] <> '\' then begin
    DirectoryList.Add(DirectoryList[DirectoryList.Count - 1] + sgExplore.Cells[colFolderName, ARow] + '\');

    BuildFrom(DirectoryList[DirectoryList.Count - 1]);

    sbBack.Enabled := True;
  end
  else begin
    if sbBack.Enabled then
      sbBackClick(Nil);
  end;
end;


procedure TfrmExplore.sbBackClick(Sender: TObject);
 begin
  DirectoryList.Delete(DirectoryList.Count - 1);

  BuildFrom(DirectoryList[DirectoryList.Count - 1]);

  if DirectoryList.Count = 1 then
    sbBack.Enabled := False;
end;


procedure TfrmExplore.bHelpClick(Sender: TObject);
 begin
  THelp.OpenHelpPage('a41.htm');
end;


procedure TfrmExplore.bCloseClick(Sender: TObject);
 begin
  Close;
end;


procedure TfrmExplore.cbUSelectChange(Sender: TObject);
 begin
  if cbUSelect.ItemIndex = 0 then
    eUContent.Enabled := False
  else
    eUContent.Enabled := True;
end;


procedure TfrmExplore.cbContainingClick(Sender: TObject);
 begin
  if TAdvOfficeCheckBox(Sender).Checked then begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := 24;

    TAdvOfficeCheckBox(Sender).Font.Style := [];
    TAdvOfficeCheckBox(Sender).Checked    := False;
  end
  else begin
    TPanel(TAdvOfficeCheckBox(Sender).Parent).Height := panelHeights[TAdvOfficeCheckBox(Sender).Tag];

    TAdvOfficeCheckBox(Sender).Font.Style := [];
    TAdvOfficeCheckBox(Sender).Checked    := True;
  end;

  CheckForValidSearch;

  bFilterClick(Nil);
end;


procedure TfrmExplore.bFilterClick(Sender: TObject);
 begin
  BuildFrom(DirectoryList[DirectoryList.Count - 1]);
end;


procedure TfrmExplore.CheckForValidSearch;
 begin
  if (cbContaining.Checked or cbCreated.Checked or cbAccessed.Checked or cbModified.Checked or
      cbSize.Checked or cbCategory.Checked or cbOwner.Checked or cbAttributes.Checked or
      cbNameLength.Checked) then
    bFilter.Enabled := True
  else
    bFilter.Enabled := False;
end;


procedure TfrmExplore.eSLTEnter(Sender: TObject);
begin
  FOldText := TEdit(Sender).Text;
end;


procedure TfrmExplore.eSLTExit(Sender: TObject);
var
  lValue : integer;

begin
  lValue := StrToIntDef(TEdit(Sender).Text, -1);

  if lValue = -1 then
    TEdit(Sender).Text := FOldText;
end;


procedure TfrmExplore.cbCreated1Change(Sender: TObject);
 begin
  if TComboBox(Sender).ItemIndex <> 0 then
    DateControls[TComboBox(Sender).Tag].Enabled := True
  else
    DateControls[TComboBox(Sender).Tag].Enabled := False;
end;


procedure TfrmExplore.BuildFrom(const NewScanPath : string);
 var
  t, dci       : integer;
  i            : word;
  DirCache     : TStringList;
  SizeCache    : TStringList;
  NumberCache  : TStringList;
  TotalSize    : int64;
  TempSize     : int64;
  TempNL       : integer;
  TotalFCount  : integer;
  TotalDCount  : integer;
  tempdir      : string;
  tfo          : TFileObject;
  OKToAdd      : boolean;
  CategoryAdd  : boolean;
  AttributeAdd : boolean;

  function GetInnerDir(const s : string): string;
   var
    t : integer;
    path : string;
    keepadding : boolean;

   begin
    path       := '';
    keepadding := True;

    for t := Length(NewScanPath) + 1 to length(s) do begin
      if s[t] = '\' then keepadding := False;

      if keepadding then
        path := path + s[t];
    end;

    if keepadding then
      Result := '\'
    else
      Result := path;
  end;

 begin
  Assert((FDataIndex >= 0) and (FDataIndex <= 1), 'TfrmExplore->BuildFrom :: invalid dataindex :: ' + inttostr(FDataIndex));

  Caption := XText[rsExploring] + ': ' + NewScanPath;

  sgExplore.FixedRowHeight := XSettings.General.RowHeight;

  DirCache := TStringList.Create;
  DirCache.Add('\');
  SizeCache := TStringList.Create;
  SizeCache.Add('0');
  NumberCache := TStringList.Create;
  NumberCache.Add('0');
  TotalSize   := 0;
  TotalFCount := 0;
  TotalDCount := 0;

  sgExplore.BeginUpdate;

  for t := 0 to GScanDetails[FDataIndex].Files.Count - 1 do begin
    tfo := GScanDetails[FDataIndex].Files[t];

    if AnsiStartsStr(NewScanPath, GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.Filename) then begin

      if (faDirectory and tfo.Attributes) = faDirectory then begin
        tempdir := GetInnerDir(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.Filename);

        dci := DirCache.IndexOf(tempdir);
        if dci = -1 then begin
          DirCache.Add(tempdir);
          SizeCache.Add(IntToStr(tfo.FileSize));
          NumberCache.Add('0');   // ignore folders
        end
        else begin
          SizeCache.Strings[dci] := IntToStr(StrToInt64(SizeCache.Strings[dci]) + tfo.FileSize);
          //NumberCache.Strings[dci]:=IntToStr(StrToInt(NumberCache.Strings[dci]) + 1); // ignore folders
        end;

        inc(TotalSize, tfo.FileSize);
        inc(TotalDCount);
      end
      else begin
        OKToAdd      := True;
        CategoryAdd  := True;
        AttributeAdd := True;

        //== check for size ====================================================

        if cbContaining.Checked then begin
          if eContaining.Text <> '' then
            if Pos(UpperCase(eContaining.Text), UpperCase(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.Filename)) = 0 then OKToAdd := False;
        end;

        //== check for size ====================================================

        if cbSize.Checked then begin
          if eSLT.Text <> '' then begin
            tempSize := StrToInt64(eSLT.Text);

            case cbSLTUnit.ItemIndex of
              CUnitsBytes     : if Not(tfo.FileSize <= tempSize)                        then OKToAdd := False;
              CUnitsKilobytes : if Not(tfo.FileSize <= (tempSize * 1024))               then OKToAdd := False;
              CUnitsMegabytes : if Not(tfo.FileSize <= (tempSize * 1024 * 1024))        then OKToAdd := False;
              CUnitsGigabytes : if Not(tfo.FileSize <= (tempSize * 1024 * 1024 * 1024)) then OKToAdd := False;
            end;
          end;

          if eSGT.Text <> '' then begin
            tempSize := StrToInt64(eSGT.Text);

            case cbSGTUnit.ItemIndex of
              CUnitsBytes     : if Not(tfo.FileSize >= tempSize)                        then OKToAdd := False;
              CUnitsKilobytes : if Not(tfo.FileSize >= (tempSize * 1024))               then OKToAdd := False;
              CUnitsMegabytes : if Not(tfo.FileSize >= (tempSize * 1024 * 1024))        then OKToAdd := False;
              CUnitsGigabytes : if Not(tfo.FileSize >= (tempSize * 1024 * 1024 * 1024)) then OKToAdd := False;
            end;
          end;
        end;

        //== check for category ================================================

        if cbCategory.Checked then begin
          CategoryAdd := False;

          for i := 1 to 19 do
            if CategoryControls[i].Checked and (tfo.FileCategory = i) then
              CategoryAdd := True;
        end;

        //== check for category ================================================

        if cbAttributes.Checked then begin
          AttributeAdd := False;

          if cbAHidden.Checked then   if (faHidden and tfo.Attributes) = faHidden     then AttributeAdd := True;
          if cbASystem.Checked then   if (faSysFile and tfo.Attributes) = faSysFile   then AttributeAdd := True;
          if cbAArchive.Checked then  if (faArchive and tfo.Attributes) = faArchive   then AttributeAdd := True;
          if cbAReadOnly.Checked then if (faReadOnly and tfo.Attributes) = faReadOnly then AttributeAdd := True;

          if cbATemp.Checked then     if (tfo.Temp) then AttributeAdd := True;
        end;

        //== check for created date ============================================

        if cbCreated.Checked then begin
          if cbCreated1.ItemIndex <> 0 then begin
            case cbCreated1.ItemIndex of
              1 : if TConvert.DateToYYYYMMDDI(dtpCreated1.Date) <> tfo.FileDateC then OKToAdd := False;
              2 : if TConvert.DateToYYYYMMDDI(dtpCreated1.Date) >= tfo.FileDateC then OKToAdd := False;
              3 : if TConvert.DateToYYYYMMDDI(dtpCreated1.Date) <= tfo.FileDateC then OKToAdd := False;
            end;
          end;

          if cbCreated2.ItemIndex <> 0 then begin
            case cbCreated2.ItemIndex of
              1 : if TConvert.DateToYYYYMMDDI(dtpCreated2.Date) <> tfo.FileDateC then OKToAdd := False;
              2 : if TConvert.DateToYYYYMMDDI(dtpCreated2.Date) >= tfo.FileDateC then OKToAdd := False;
              3 : if TConvert.DateToYYYYMMDDI(dtpCreated2.Date) <= tfo.FileDateC then OKToAdd := False;
            end;
          end;
        end;

        //== check for created date ============================================

        if cbAccessed.Checked then begin
          if cbAccessed1.ItemIndex <> 0 then begin
            case cbAccessed1.ItemIndex of
              1 : if TConvert.DateToYYYYMMDDI(dtpAccessed1.Date) <> tfo.FileDateA then OKToAdd := False;
              2 : if TConvert.DateToYYYYMMDDI(dtpAccessed1.Date) >= tfo.FileDateA then OKToAdd := False;
              3 : if TConvert.DateToYYYYMMDDI(dtpAccessed1.Date) <= tfo.FileDateA then OKToAdd := False;
            end;
          end;

          if cbAccessed2.ItemIndex <> 0 then begin
            case cbAccessed2.ItemIndex of
              1 : if TConvert.DateToYYYYMMDDI(dtpAccessed2.Date) <> tfo.FileDateA then OKToAdd := False;
              2 : if TConvert.DateToYYYYMMDDI(dtpAccessed2.Date) >= tfo.FileDateA then OKToAdd := False;
              3 : if TConvert.DateToYYYYMMDDI(dtpAccessed2.Date) <= tfo.FileDateA then OKToAdd := False;
            end;
          end;
        end;

        //== check for created date ============================================

        if cbModified.Checked then begin
          if cbModified1.ItemIndex <> 0 then begin
            case cbModified1.ItemIndex of
              1 : if TConvert.DateToYYYYMMDDI(dtpModified1.Date) <> tfo.FileDateM then OKToAdd := False;
              2 : if TConvert.DateToYYYYMMDDI(dtpModified1.Date) >= tfo.FileDateM then OKToAdd := False;
              3 : if TConvert.DateToYYYYMMDDI(dtpModified1.Date) <= tfo.FileDateM then OKToAdd := False;
            end;
          end;

          if cbModified2.ItemIndex <> 0 then begin
            case cbModified2.ItemIndex of
              1 : if TConvert.DateToYYYYMMDDI(dtpModified2.Date) <> tfo.FileDateM then OKToAdd := False;
              2 : if TConvert.DateToYYYYMMDDI(dtpModified2.Date) >= tfo.FileDateM then OKToAdd := False;
              3 : if TConvert.DateToYYYYMMDDI(dtpModified2.Date) <= tfo.FileDateM then OKToAdd := False;
            end;
          end;
        end;

        //== check for created date ============================================

        if cbOwner.Checked then begin
          if cbUSelect.ItemIndex <> 0 then begin
            case cbUSelect.ItemIndex of
              1 : if UpperCase(GScanDetails[FDataIndex].Users[tfo.Owner].Name) <> UpperCase(eUContent.Text)         then OKToAdd := False;
              2 : if UpperCase(GScanDetails[FDataIndex].Users[tfo.Owner].Name) = UpperCase(eUContent.Text)          then OKToAdd := False;
              3 : if Pos(UpperCase(eUContent.Text), UpperCase(GScanDetails[FDataIndex].Users[tfo.Owner].Name)) = 0  then OKToAdd := False;
              4 : if Pos(UpperCase(eUContent.Text), UpperCase(GScanDetails[FDataIndex].Users[tfo.Owner].Name)) <> 0 then OKToAdd := False;
            end;
          end;
        end;

        //== check for name lengths ============================================

        if cbNameLength.Checked then begin
          if eNLLT.Text <> '' then begin
            TempNL := StrToIntDef(eNLLT.Text, 300);

            if (Length(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.Filename) > TempNL) then
              OKToAdd := False;
          end;

          if eNLGT.Text <> '' then begin
            TempNL := StrToIntDef(eNLGT.Text, 1);

            if (Length(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.Filename) < TempNL) then
              OKToAdd := False;
          end;
        end;

        //======================================================================
        //======================================================================

        if (OKToAdd and CategoryAdd and AttributeAdd) then begin
          tempdir := GetInnerDir(GScanDetails[FDataIndex].Folders[tfo.FilePathIndex] + tfo.Filename);

          dci := DirCache.IndexOf(tempdir);
          if dci = -1 then begin
            DirCache.Add(tempdir);
            SizeCache.Add(IntToStr(tfo.FileSize));
            NumberCache.Add('1');
          end
          else begin
            SizeCache.Strings[dci]   := IntToStr(StrToInt64(SizeCache.Strings[dci]) + tfo.FileSize);
            NumberCache.Strings[dci] := IntToStr(StrToInt(NumberCache.Strings[dci]) + 1);
          end;

          inc(TotalSize, tfo.FileSize);
          inc(TotalFCount);
        end;
      end;
    end;
  end;

  // build display
  sgExplore.RowCount := DirCache.Count + 1;

  for t := 0 to DirCache.Count - 1 do begin
    sgExplore.Cells[colFolderName, t + 1] := DirCache[t];
    sgExplore.Cells[colFileCount,  t + 1] := NumberCache.Strings[t];

    if TotalFCount <> 0 then
      sgExplore.Cells[colFilesAsPercent, t + 1] := IntToStr(Round((StrToInt64(NumberCache.Strings[t]) / TotalFCount) * 100)) + '%'
    else
      sgExplore.Cells[colFilesAsPercent, t + 1] := 'n/a';

    sgExplore.Cells[colSize,      t + 1] := TConvert.ConvertToUsefulUnit(StrToInt64(SizeCache[t]));
    sgExplore.Cells[colSizeCache, t + 1] := SizeCache[t];

    if TotalSize <> 0 then
      sgExplore.Cells[colSizeAsPercent, t + 1] := IntToStr(Round((StrToInt64(SizeCache.Strings[t]) / TotalSize) * 100)) + '%'
    else
      sgExplore.Cells[colSizeAsPercent, t + 1]  := 'n/a';

    if TotalFCount <> 0 then
      sgExplore.Cells[colFileCountPCache, t + 1] := IntToStr(Round((StrToInt64(NumberCache.Strings[t]) / TotalFCount) * 100))
    else
      sgExplore.Cells[colFileCountPCache, t + 1] := '0';

    if TotalSize <> 0 then
      sgExplore.Cells[colSizePCache, t + 1] := IntToStr(Round((StrToInt64(SizeCache.Strings[t]) / TotalSize) * 100))
    else
      sgExplore.Cells[colSizePCache, t + 1] := '0';
  end;

  lData.HTMLText[0] := '<b>' + IntToStr(TotalFCount) + '</b> ' + XText[rsFiles] + '; <b>' + IntToStr(TotalDCount) + '</b> ' + XText[rsFolders] + '; <b>' + TConvert.ConvertToUsefulUnit(TotalSize) + '</b>';

  sgExplore.EndUpdate;

  DirCache.Free;
  SizeCache.Free;
  NumberCache.Free;
end;


end.
