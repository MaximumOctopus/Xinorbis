unit X.Dialogs.Load;

interface

uses
  Vcl.Dialogs, System.SysUtils,

  X.LanguageHandler, X.Utility;


type
  TXOpenDialog = class
  public
    class function Execute(aFilter, aDefaultExt, aInitialFolder, aFileName : string): string;
    class function ExecuteExe(aFileName : string): string;
  end;


implementation


class function TXOpenDialog.Execute(aFilter, aDefaultExt, aInitialFolder, aFileName : string): string;
var
  lOpenDialog : TOpenDialog;

begin
  Result := '';

  lOpenDialog := TOpenDialog.Create(Nil);

  lOpenDialog.Filter     := aFilter;
  lOpenDialog.DefaultExt := aDefaultExt;
  lOpenDialog.InitialDir := aInitialFolder;
  lOpenDialog.FileName   := TUtility.ReportFileName(aFileName);

  if lOpenDialog.Execute then
    Result := lOpenDialog.FileName;

  FreeAndNil(lOpenDialog);
end;


class function TXOpenDialog.ExecuteExe(aFileName : string): string;
var
  lOpenDialog : TOpenDialog;

begin
  Result := '';

  lOpenDialog := TOpenDialog.Create(Nil);

  lOpenDialog.Filter     := XText[rsPrograms] + ' (*.exe)|*.exe';
  lOpenDialog.DefaultExt := '.exe';
  lOpenDialog.FileName   := TUtility.ReportFileName(aFileName);

  if lOpenDialog.Execute then
    Result := lOpenDialog.FileName;

  FreeAndNil(lOpenDialog);
end;

 {
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
              }

end.
