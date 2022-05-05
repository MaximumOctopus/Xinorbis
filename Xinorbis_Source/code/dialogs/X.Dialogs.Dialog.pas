unit X.Dialogs.Dialog;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants,
  System.Classes, Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs,
  Vcl.StdCtrls, Vcl.Buttons, Vcl.Clipbrd, Vcl.Imaging.pngimage, Vcl.ExtCtrls,

  TMSLogging,

  X.LanguageHandler;


type
  TfrmXinorbisDialog = class(TForm)
    BitBtn1: TBitBtn;
    lTitle: TLabel;
    lBody: TLabel;
    bCopyToClipboard: TBitBtn;
    iWarning: TImage;
    iInformation: TImage;
    iXinorbis: TImage;
    procedure bCopyToClipboardClick(Sender: TObject);
  private
  public
  end;


const
  XDialogTypeInformation = 0;
  XDialogTypeWarning     = 1;
  XDialogTypeXinorbis    = 2;


procedure ShowXDialog(aTitle, aBody : string; aDialogType : integer);


implementation

{$R *.dfm}


procedure ShowXDialog(aTitle, aBody : string; aDialogType : integer);
begin
  with TfrmXinorbisDialog.Create(Application) do
    try
      lTitle.Caption := aTitle;
      lBody.Caption  := aBody;

      bCopyToClipboard.Caption := XText[rsCopyToClipboard];

      case aDialogType of
        XDialogTypeInformation : iInformation.Visible := True;
        XDialogTypeWarning     : iWarning.Visible     := True;
        XDialogTypeXinorbis    : iXinorbis.Visible    := True;
      else
        iInformation.Visible   := True;
      end;

      TMSLogger.Debug('Dialog :: ' + aTitle + ' / ' + aBody + ' (' + IntToStr(aDialogType) + ')');

      ShowModal;
    finally
      Free;
    end;
end;


procedure TfrmXinorbisDialog.bCopyToClipboardClick(Sender: TObject);
begin
  Clipboard.AsText := lTitle.Caption + ' / ' + lBody.Caption;
end;


end.
