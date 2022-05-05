{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: April 23rd 2009
  Last Modified: January 11th 2020
}


unit X.Form.FileAssociations;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, System.UITypes, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls,
  Vcl.StdCtrls, Vcl.Buttons, System.Win.Registry, System.Inifiles,

  TMSLogging,

  X.Dialogs.Load, X.Dialogs.Save, X.Dialogs.Dialog,

  X.Constants, X.Help,

  X.FileExtensionsObject, X.FileExtension, X.Global, X.LanguageHandler,
  X.Settings, X.SystemGlobal;

type
  TfrmFileAssociations = class(TForm)
    lCategory: TLabel;
    cbFACategories: TComboBox;
    GroupBox2: TGroupBox;
    sCat1: TShape;
    sbRenameCategory: TSpeedButton;
    lFAColour: TLabel;
    gbAFE: TGroupBox;
    sbAdd: TSpeedButton;
    sbFADelete: TSpeedButton;
    sbSearchFileExt: TSpeedButton;
    miFECut: TSpeedButton;
    miFEPaste: TSpeedButton;
    sbRD: TSpeedButton;
    lbExtlist: TListBox;
    bImportLIst: TBitBtn;
    bExportList: TBitBtn;
    eAdd: TEdit;
    Bevel7: TBevel;
    bSave: TBitBtn;
    bCancel: TBitBtn;
    cdMain: TColorDialog;
    bHelp: TBitBtn;
    procedure cbFACategoriesChange(Sender: TObject);
    procedure sCat1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure sbRenameCategoryClick(Sender: TObject);
    procedure eAddChange(Sender: TObject);
    procedure eAddKeyPress(Sender: TObject; var Key: Char);
    procedure sbAddClick(Sender: TObject);
    procedure sbFADeleteClick(Sender: TObject);
    procedure sbSearchFileExtClick(Sender: TObject);
    procedure lbExtlistClick(Sender: TObject);
    procedure miFECutClick(Sender: TObject);
    procedure miFEPasteClick(Sender: TObject);
    procedure bImportLIstClick(Sender: TObject);
    procedure bExportListClick(Sender: TObject);
    procedure sbRDClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure bHelpClick(Sender: TObject);
  private
    currentIndex      : integer;
    SLClipboard       : TStringList;

    OldCustomNames    : array[1..10] of string;

    procedure SetLanguage;
    procedure BuildList(idx : integer);
    procedure SaveCustomNames;
  public
  end;


var
  frmFileAssociations: TfrmFileAssociations;


function DoFileAssociations: integer;


implementation


{$R *.dfm}


function DoFileAssociations: integer;
var
  t : integer;

begin
  with TfrmFileAssociations.Create(Application) do
    try
      SetLanguage;

      SLClipboard := TStringList.Create;

      for t := 1 to 10 do
        OldCustomNames[t] := TypeDescriptions[t + 9];

      currentIndex             := -1;
      cbFACategories.ItemIndex := 0;
      BuildList(1);

      ShowModal;

      Result := ModalResult;

      if ModalResult = mrOK then begin
        SaveCustomNames;
      end;
    finally
      free;
  end;
end;


procedure TfrmFileAssociations.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  SLClipboard.Free;

  Action := caFree;
end;


procedure TfrmFileAssociations.SetLanguage;
 var
  t : integer;

 begin
  Caption := XText[rsFileTypes];

  bHelp.Caption              := XText[rsHelp];
  bSave.Caption              := XText[rsSave];
  bCancel.Caption            := XText[rsCancel];

  // ===========================================================================

  for t := 1 to __FileCategoriesCount do begin
    cbFACategories.Items.Add(TypeDescriptions[t]);
  end;

  lCategory.Caption            := XText[rsCategory];
  lFAColour.Caption            := XText[rsDisplayColour];
  gbAFE.Caption                := XText[rsAssociatedFileExtensions];
  sbRD.Caption                 := XText[rsRestoreDefaults];

  bImportLIst.Caption          := XText[rsImportList];
  bExportList.Caption          := XText[rsExportList];

  sbRenameCategory.Caption     := XText[rsRenameCustomCategory];
end;


procedure TfrmFileAssociations.bExportListClick(Sender: TObject);
 var
  tf : TextFile;
  t : integer;
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsTextFiles] + ' (*.txt)|*.txt',
                                    '.txt',
                                    TypeDescriptions[currentIndex] + '.txt',
                                    GSystemGlobal.ExePath + 'data\');

  if lFileName <> '' then begin
    AssignFile(tf, lFilename);

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorSaving] + ': ' + XText[rsExtensions],
                  XText[rsErrorSaving] + ' "' + lFileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      for t := 0 to lbExtlist.Items.Count - 1 do
        Writeln(tf, lbExtlist.Items[t]);

      CloseFile(tf);
    end;
    {$I+}
  end;
end;


procedure TfrmFileAssociations.bHelpClick(Sender: TObject);
begin
  THelp.OpenHelpPage('filetypes.htm');
end;


procedure TfrmFileAssociations.bImportLIstClick(Sender: TObject);
 var
  tf : TextFile;
  s : string;
  lFileName : string;

begin
  lFileName := TXOpenDialog.Execute(XText[rsTextFiles] + ' (*.txt)|*.txt',
                                    '.txt',
                                    GSystemGlobal.ExePath + 'data\layouts',
                                    '');

  if lFileName <> '' then begin
    AssignFile(tf, lFilename);
    {$I-}
    Reset(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorOpening] + ': ' + XText[rsReport],
                  XText[rsErrorOpening] + ' "' + lFilename + '".',
                  XDialogTypeWarning);
    end
    else begin
      while not(eof(tf)) do begin
        Readln(tf, s);

        lbExtlist.Items.Add(s);
      end;

      CloseFile(tf);
    end;
    {$I+}
  end;
end;


procedure TfrmFileAssociations.cbFACategoriesChange(Sender: TObject);
begin
  BuildList(cbFACategories.ItemIndex + 1);
end;


procedure TfrmFileAssociations.eAddChange(Sender: TObject);
begin
  if eAdd.Text = '' then
    sbAdd.Enabled := False
  else
    sbAdd.Enabled := True;
end;


procedure TfrmFileAssociations.eAddKeyPress(Sender: TObject; var Key: Char);
begin
  if key = #13 then
    sbAddClick(Nil);
end;


procedure TfrmFileAssociations.lbExtlistClick(Sender: TObject);
begin
  if lbExtList.SelCount = 0 then begin
    sbFADelete.Enabled := False;
    miFECut.Enabled    := False;
  end
  else begin
    miFECut.Enabled    := True;
    sbFADelete.Enabled := True;
  end;
end;


procedure TfrmFileAssociations.miFECutClick(Sender: TObject);
 var
  t : integer;

 begin
  if lbExtList.SelCount <> 0 then begin
    SLClipboard.Clear;

    for t := 0 to lbExtList.Items.Count - 1 do begin
      if lbExtList.Selected[t] then
        SLClipboard.Add(lbExtList.Items[t]);
    end;

    lbExtList.DeleteSelected;

    miFEPaste.Enabled := True;
  end;
end;


procedure TfrmFileAssociations.miFEPasteClick(Sender: TObject);
 var
  t : integer;

 begin
  if SLClipboard.Count <> 0 then begin
    for t := 0 to SLClipboard.Count - 1 do begin
      lbExtList.Items.Add(SLClipboard[t]);
    end;

    miFECut.Enabled   := False;
    miFEPaste.Enabled := False;
  end;
end;


procedure TfrmFileAssociations.sbAddClick(Sender: TObject);
begin
  if lbExtList.Items.IndexOf(eAdd.Text) = -1 then begin
    lbExtList.Items.Add(eAdd.Text);
  end;

  eAdd.Text := '';
end;


procedure TfrmFileAssociations.sbFADeleteClick(Sender: TObject);
begin
  lbExtList.DeleteSelected;
end;

procedure TfrmFileAssociations.sbRDClick(Sender: TObject);
 var
  t : integer;

 begin
  if MessageDlg(XText[rsRestoreDefaultExtensions], mtWarning, [mbYes, mbNo], 0) = mrYes then begin
    // clear the file-extension caches first
    FileExtensionsObject.CategoryExtensions.Clear;

    FileExtensionsObject.LoadDefaultFileExtensions;

    // =========================================================================

    for t := 1 to __FileCategoriesCount do begin
      GSystemGlobal.FileCategoryColors[t] := DefaultDisplayColours[t];
    end;

    // =========================================================================

    for t := 1 to 10 do
      OldCustomNames[t] := 'custom' + IntToStr(t);

    currentIndex := -1;

    cbFACategories.ItemIndex := 0;
    BuildList(cbFACategories.ItemIndex);
  end;
end;


procedure TfrmFileAssociations.sbRenameCategoryClick(Sender: TObject);
 var
  s : string;

 begin
  s := InputBox(XText[rsRenameCustomCategory], XText[rsEnterANameFor] + ' "' + cbFACategories.Text + '"', cbFACategories.Text);

  if s <> '' then begin
    OldCustomNames[cbFACategories.ItemIndex - 8] := s;

    cbFACategories.Items[cbFACategories.ItemIndex] := s;
  end;
end;


procedure TfrmFileAssociations.sbSearchFileExtClick(Sender: TObject);
 var
  fs, s : string;
  i : integer;

 begin
  s := InputBox(XText[rsFileExtensions], XText[rsSearch], '');

  if s <> '' then begin
    s  := UpperCase(s);
    fs := '';

    for i := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
      if UpperCase(FileExtensionsObject.CategoryExtensions[i].Name) = s then begin
        fs := fs + '- ' + TypeDescriptions[FileExtensionsObject.CategoryExtensions[i].Category];
      end;
    end;

    if fs <> '' then begin
      fs := XText[rsFoundIn] + ':' + #13 + #13 + fs;

      ShowXDialog(XText[rsWarning], fs, XDialogTypeWarning);
    end
    else begin
      ShowXDialog(XText[rsWarning], '"' + s + '", ' + XText[rsNoneFound], XDialogTypeWarning);
    end;
  end;
end;


procedure TfrmFileAssociations.sCat1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if button = mbLeft then begin
    Assert(cbFACategories.ItemIndex + 1 <= __FileCategoriesCount, 'sColourMouseDown :: Object tag incorrect.');

    cdMain.Color := TShape(Sender).Brush.Color;

    if cdMain.Execute then begin
      TShape(Sender).Brush.Color := cdMain.Color;

      GSystemGlobal.FileCategoryColors[cbFACategories.ItemIndex + 1] := cdMain.Color;
    end;
  end;
end;


procedure TfrmFileAssociations.BuildList(idx : integer);
 var
  t : integer;
  tfx : TFileExtension;

 begin
  //-- save current -----------------------------------------------------------
  if currentIndex <> -1 then begin
    t := 0;
    while t <= FileExtensionsObject.CategoryExtensions.Count - 1 do begin
      if FileExtensionsObject.CategoryExtensions[t].Category = currentIndex then
        FileExtensionsObject.CategoryExtensions.Delete(t)
      else
        inc(t);
    end;

    if lbExtList.Items.Count <> 0 then begin
      for t := 0 to lbExtList.Items.Count - 1 do begin
        tfx := TFileExtension.Create;
        tfx.Name     := lbExtList.Items[t];
        tfx.Category := currentIndex;
        FileExtensionsObject.CategoryExtensions.Add(tfx);
      end;
    end;

  end;

  //-- load new idx  -----------------------------------------------------------

  lbExtList.Clear;

  sCat1.Brush.Color := GSystemGlobal.FileCategoryColors[idx];

  if (idx >= Category_Custom_1) and (idx <= Category_Custom_10) then
    sbRenameCategory.Enabled := True
  else
    sbRenameCategory.Enabled := False;

  if idx <> __FileCategoriesOther then begin
    for t := 0 to FileExtensionsObject.CategoryExtensions.Count - 1 do begin
      tfx := FileExtensionsObject.CategoryExtensions[t];

      if tfx.Category = idx then begin
        if lbExtList.Items.IndexOf(tfx.Name) = -1 then
          lbExtList.Items.Add(tfx.Name);
      end;
    end;

    eAdd.Enabled        := True;
    bImportLIst.Enabled := True;
    bExportList.Enabled := True;
  end
  else begin
    eAdd.Enabled        := False;
    bImportLIst.Enabled := False;
    bExportList.Enabled := False;
  end;

  currentIndex := idx;
end;


procedure TfrmFileAssociations.SaveCustomNames;
 var
  t : integer;
  Reg: TRegistry;
  changed : boolean;
  config : TIniFile;

 begin
  changed := False;

  for t := 1 to 10 do begin
    if OldCustomNames[t] <> TypeDescriptions[t + 9] then changed := True;
  end;

  if changed then begin
    for t := 1 to 10 do
      TypeDescriptions[t + 9] := OldCustomNames[t];

    if (XSettings.customsettings.SettingsSaveLocation = SaveLocationRegistry) then begin
      Reg := TRegistry.Create(KEY_WRITE);

      try
        Reg.RootKey := HKEY_CURRENT_USER;
        Reg.OpenKey('\software\' + XinorbisRegistryKey, True);

        for t := 1 to 10 do begin
          Reg.WriteString('Custom' + IntToStr(t), TypeDescriptions[t + 9]);
        end;
      finally
        Reg.Free;
      end;
    end
    else begin
      config := TINIFile.Create(GSystemGlobal.ExePath + 'custom.ini');

      try
        try
          for t := 1 to 10 do
            config.WriteString('TypeDescriptions', 'TypeDescriptions' + IntToStr(t), TypeDescriptions[t + 9]);
        except
          on e : exception do begin
            TMSLogger.Error('Error saving custom names. ' + e.ClassName + ' / ' + e.Message);
          end;
        end;
      finally
        config.Free;
      end;
    end;
  end;
end;


end.
