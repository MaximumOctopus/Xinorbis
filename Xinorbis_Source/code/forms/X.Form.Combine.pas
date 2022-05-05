{
  (c) Paul Alan Freshney 2002
  (c) Aardvark Digital 2002

        Started: January 23rd 2002
  Last Modified: November 28th 2007

  203
}

unit X.Form.Combine;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls, Buttons, FileCtrl, ComCtrls, ShellCtrls,

  X.LanguageHandler, X.Windows, X.SystemGlobal;


type
  TfrmCombine = class(TForm)
    Bevel1: TBevel;
    Bevel2: TBevel;
    Bevel3: TBevel;
    Bevel4: TBevel;
    lbCombine: TListBox;
    Bevel5: TBevel;
    bCancel: TBitBtn;
    bScan: TBitBtn;
    lChoose: TLabel;
    sbDrive2Add: TSpeedButton;
    sbDelete: TSpeedButton;
    SpeedButton4: TSpeedButton;
    lFolderList: TLabel;
    Bevel6: TBevel;
    bLoadList: TBitBtn;
    bSaveList: TBitBtn;
    odCombine: TOpenDialog;
    sdCombine: TSaveDialog;
    sbExplore: TSpeedButton;
    eDirectory: TEdit;
    procedure SetLanguage;
    procedure sbDrive2AddClick(Sender: TObject);
    procedure lbCombineClick(Sender: TObject);
    procedure sbDeleteClick(Sender: TObject);
    procedure SpeedButton4Click(Sender: TObject);
    procedure eDirectoryKeyPress(Sender: TObject; var Key: Char);
    procedure bLoadListClick(Sender: TObject);
    procedure bSaveListClick(Sender: TObject);
    procedure sbExploreClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmCombine: TfrmCombine;

function DoCombine: TStringList;

implementation

{$R *.DFM}

uses
  shlobj, shellAPI,

  X.Global, X.Settings, X.Utility, X.Constants, X.Dialogs.Dialog;


function DoCombine: TStringList;
 var
  dc : TStringList;
  t : integer;

 begin
  dc := TStringList.Create;

  with TfrmCombine.Create(Application) do
    try
      odCombine.InitialDir := GSystemGlobal.AppDataPath + 'saves';
      sdCombine.InitialDir := GSystemGlobal.AppDataPath + 'saves';

      SetLanguage;

      ShowModal;

      if ModalResult=mrOK then begin
        for t := 0 to lbCombine.Items.Count - 1 do
          dc.Add(lbCombine.Items[t]);
      end;
    finally
      Free;
  end;

  Result := dc;
end;


procedure TfrmCombine.FormCreate(Sender: TObject);
 var
  fd : TFormDetails;

 begin
  fd := XSettings.LoadFormDetails(_FormCombine);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;
end;


procedure TfrmCombine.FormClose(Sender: TObject; var Action: TCloseAction);
 var
  fd : TFormDetails;

 begin
  fd.formID :=_FormCombine;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);
  Action := caFree;
end;


procedure TfrmCombine.SetLanguage;
 begin
  lChoose.Caption     := XText[rsChooseFolders];
  lFolderList.Caption := XText[rsFoldersToScan];

  sbExplore.Caption   := XText[rsExploreFolder];

  bSaveList.Caption   := XText[rsSave];
  bLoadList.Caption   := XText[rsLoad];
  bScan.Caption       := XText[rsScan];
  bCancel.Caption     := XText[rsCancel];

  Caption             := XText[rsCombineDrivesFolders];
end;


procedure TfrmCombine.sbDrive2AddClick(Sender: TObject);
 begin
  if eDirectory.Text <> '' then begin
    if System.SysUtils.DirectoryExists(eDirectory.Text) then begin
      if eDirectory.Text[length(eDirectory.Text)] <> '\' then
        eDirectory.Text := eDirectory.Text + '\';

      lbCombine.Items.Add(eDirectory.Text);
      eDirectory.Text   := '';

      bScan.Enabled     := True;
      bSaveList.Enabled := True;
    end;
  end;
end;


procedure TfrmCombine.lbCombineClick(Sender: TObject);
 begin
  if lbCombine.SelCount <> 0 then begin
    sbDelete.Enabled  := True;
    sbExplore.Enabled := True;
  end
  else begin
    sbDelete.Enabled  := False;
    sbExplore.Enabled := False;
  end;
end;


procedure TfrmCombine.sbDeleteClick(Sender: TObject);
 begin
  lbCombine.DeleteSelected;

  if lbCombine.Items.Count = 0 then begin
    bScan.Enabled     := False;
    bSaveList.Enabled := False;
  end;
end;


procedure TfrmCombine.sbExploreClick(Sender: TObject);
 begin
  TXWindows.ExecuteFile(0, '"' + lbCombine.Items[lbCombine.ItemIndex] + '"', '', '');
end;


procedure TfrmCombine.SpeedButton4Click(Sender: TObject);
 var
  str : string;

 begin
  str := TXWindows.BrowseForFolder(Handle);

  if str <> '' then begin
    eDirectory.Text := str;
  end;
end;


procedure TfrmCombine.eDirectoryKeyPress(Sender: TObject; var Key: Char);
 begin
  if key = #13 then
    sbDrive2AddClick(Nil);
end;


procedure TfrmCombine.bLoadListClick(Sender: TObject);
 var
  t : integer;
  
 begin
  if odCombine.Execute then begin
    lbCombine.Clear;

    lbCombine.Items.LoadFromFile(odCombine.FileName);

    if lbCombine.Count <> 0 then
      bScan.Enabled := True;

    for t := 0 to lbCombine.Count - 1 do begin
      if not(System.SysUtils.DirectoryExists(lbCombine.Items[t])) then
        ShowXDialog(XText[rsError] + ': ' + XText[rsFolder],
                    XText[rsFolder] + ': "' + lbCombine.Items[t] + '" ' + XText[rsDoesNotExist],
                    XDialogTypeWarning);
    end;
  end;
end;


procedure TfrmCombine.bSaveListClick(Sender: TObject);
 begin
  if sdCombine.Execute then begin
    lbCombine.Items.SaveToFile(sdCombine.FileName);
  end;
end;


end.
