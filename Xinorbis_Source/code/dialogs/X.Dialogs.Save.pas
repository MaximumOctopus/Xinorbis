unit X.Dialogs.Save;

interface

uses
  Vcl.Dialogs, System.SysUtils,

  X.LanguageHandler;


type
  TXSaveDialog = class
  public
    class function Execute(aFilter, aDefaultExt, aFileName : string; aInitialDir : string = ''): string;
    class function ExecuteImages(aFileName : string): string;
    class function ExecuteReports(aFileName : string): string;
  end;


implementation


uses
  X.Utility;


class function TXSaveDialog.Execute(aFilter, aDefaultExt, aFileName : string; aInitialDir : string = ''): string;
var
  lSaveDialog : TSaveDialog;
begin
  Result := '';

  lSaveDialog := TSaveDialog.Create(Nil);

  lSaveDialog.Filter     := aFilter;
  lSaveDialog.DefaultExt := aDefaultExt;
  lSaveDialog.FileName   := TUtility.ReportFileName(aFileName);

  if aInitialDir <> '' then
    lSaveDialog.InitialDir := aInitialDir;

  if lSaveDialog.Execute then
    Result := lSaveDialog.FileName;

  FreeAndNil(lSaveDialog);
end;


class function TXSaveDialog.ExecuteImages(aFileName : string): string;
var
  lSaveDialog : TSaveDialog;
begin
  Result := '';

  lSaveDialog := TSaveDialog.Create(Nil);

  lSaveDialog.Filter     := XText[rsPNGFiles] + ' (*.png)|*.png';
  lSaveDialog.DefaultExt := '.png';
  lSaveDialog.FileName   := TUtility.ReportFileName(aFileName);

  if lSaveDialog.Execute then
    Result := lSaveDialog.FileName;

  FreeAndNil(lSaveDialog);
end;


class function TXSaveDialog.ExecuteReports(aFileName : string): string;
var
  lSaveDialog : TSaveDialog;
begin
  Result := '';

  lSaveDialog := TSaveDialog.Create(Nil);

  lSaveDialog.Filter     := XText[rsCSVFiles] + ' (*.csv)|*.csv|' +
                            'HTML (*.htm)|*.htm|' +
                            XText[rsTextFiles] + ' (*.txt)|*.txt';
  lSaveDialog.DefaultExt := '.csv';
  lSaveDialog.FileName   := TUtility.ReportFileName(aFileName);

  if lSaveDialog.Execute then
    Result := lSaveDialog.FileName;

  FreeAndNil(lSaveDialog);
end;


end.
