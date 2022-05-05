// (c) Paul Alan Freshney 2007
// Utility for Xinorbis
//
//  Created: October 2nd 2009
// Modified: October 2nd 2009
//
// 155

unit X.Form.Reference;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, Buttons, ComCtrls, AdvSmoothTabPager, AdvOfficeButtons,

  X.Help,X.LanguageHandler, X.FileExtensionsObject, X.SystemGlobal;

type
  TfrmReference = class(TForm)
    mResults: TMemo;
    pcReference: TAdvSmoothTabPager;
    AdvSmoothTabPager12: TAdvSmoothTabPage;
    AdvSmoothTabPager13: TAdvSmoothTabPage;
    sbFileExtensions: TSpeedButton;
    eFileExtension: TEdit;
    bHelp: TBitBtn;
    sbWindowsFile: TSpeedButton;
    eWindowsFile: TEdit;
    rbXP: TAdvOfficeRadioButton;
    rbW7: TAdvOfficeRadioButton;
    procedure sbFileExtensionsClick(Sender: TObject);
    procedure sbWindowsFileClick(Sender: TObject);
    procedure eFileExtensionChange(Sender: TObject);
    procedure eFileExtensionKeyPress(Sender: TObject; var Key: Char);
    procedure eWindowsFileChange(Sender: TObject);
    procedure eWindowsFileKeyPress(Sender: TObject; var Key: Char);
    procedure bHelpClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmReference: TfrmReference;

procedure ShowReference;

implementation

{$R *.dfm}

uses X.Utility, X.Global, X.Settings, X.Constants, X.Dialogs.Dialog;

procedure ShowReference;
 begin
  with TfrmReference.Create(Application) do
    try
      ShowModal;
    finally
      free;
    end;
end;

procedure TfrmReference.FormCreate(Sender: TObject);
 var
  fd : TFormDetails;

 begin
  // ===========================================================================

  fd := XSettings.LoadFormDetails(_FormReference);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
    Width            := fd.w;
    Height           := fd.h;
  end;

  rbXP.ParentColor := True;
end;

procedure TfrmReference.FormClose(Sender: TObject; var Action: TCloseAction);
 var
  fd : TFormDetails;

 begin
  fd.formID := _FormReference;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;

  XSettings.SaveFormDetails(fd);

  Action := caFree;
end;

procedure TfrmReference.sbFileExtensionsClick(Sender: TObject);
 var
  s : string;
  t : integer;

 begin
  mResults.Clear;

  if eFileExtension.Text <> '' then begin
    s := eFileExtension.Text;

    if eFileExtension.Text[1] = '.' then
      s := Copy(s, 2, Length(s) - 1);

    s := UpperCase(s);

    for t := 0 to FileExtensionsObject.FileExtensionDescriptions.Count - 1 do begin
      if Pos(s, FileExtensionsObject.FileExtensionDescriptions.Strings[t]) = 1 then
        mResults.Lines.Add(FileExtensionsObject.FileExtensionDescriptions.Strings[t]);
    end;

    if mResults.Lines.Count = 0 then begin
      mResults.Lines.Add(XText[rsNoneFound]);
    end;
  end;
end;

procedure TfrmReference.sbWindowsFileClick(Sender: TObject);
 var
  s, fn : string;
  tf : TextFile;
  i : integer;

 begin
  if rbXP.Checked then
    fn := 'WindowsXP_dlls.dat'
  else
    fn := 'Windows7_dlls.dat';

  mResults.Clear;

  AssignFile(tf, GSystemGlobal.ExePath + 'data\system\' + fn);
  {$I-}
  Reset(tf);

  if IOResult <> 0 then begin
    ShowXDialog(XText[rsErrorOpeningXinorbisSystemFile],
                XText[rsErrorOpening] + ' "' + GSystemGlobal.ExePath + 'data\system\' + fn + '".',
                XDialogTypeWarning);
  end
  else begin
    while not(eof(tf)) do begin
      readln(tf, s);

     if Pos(UpperCase(eWindowsFile.Text), UpperCase(s)) = 1 then begin
        i := Pos(',', s);

        if i <> 0 then begin
          mResults.Lines.Add(Copy(s, 1, i - 1));
          mResults.Lines.Add(Copy(s, i + 1, Length(s) - i));
          mResults.Lines.Add('');
        end;
      end;
    end;

    CloseFile(tf);
  end;
  {$I+}
end;

procedure TfrmReference.eFileExtensionChange(Sender: TObject);
 begin
  if eFileExtension.Text = '' then
    sbFileExtensions.Enabled := False
  else
    sbFileExtensions.Enabled := True;
end;

procedure TfrmReference.eFileExtensionKeyPress(Sender: TObject; var Key: Char);
 begin
  if key = #13 then
    sbFileExtensionsClick(Nil);
end;

procedure TfrmReference.eWindowsFileChange(Sender: TObject);
 begin
  if eWindowsFile.Text = '' then
    sbWindowsFile.Enabled := False
  else
    sbWindowsFile.Enabled := True;
end;

procedure TfrmReference.eWindowsFileKeyPress(Sender: TObject; var Key: Char);
 begin
  if key = #13 then
    sbWindowsFileClick(Nil);
end;

procedure TfrmReference.bHelpClick(Sender: TObject);
 begin
  THelp.OpenHelpPage('reference.htm');
end;

procedure TfrmReference.FormShow(Sender: TObject);
 begin
  Caption := XText[rsReference];

  pcReference.AdvSmoothTabPages[0].Caption := XText[rsFileExtensions];
  pcReference.AdvSmoothTabPages[1].Caption := XText[rsWindowsFiles];
end;

end.
