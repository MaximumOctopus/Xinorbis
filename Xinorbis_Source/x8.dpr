program x8;

uses
  FastMM4,
  Controls,
  dialogs,
  Forms,
  System.SysUtils,
  main,
  TMSLogging,
  X.Form.CheckVersion,
  X.Constants,
  X.PurchaseUtility,
  X.Utility,
  X.GuiUtil in 'code\units\X.GuiUtil.pas',
  X.Dialogs.Colour in 'code\dialogs\X.Dialogs.Colour.pas',
  X.ScanAnalysis in 'code\units\X.ScanAnalysis.pas',
  X.MD5 in 'code\units\X.MD5.pas',
  X.Database.Sqlite in 'code\database\X.Database.Sqlite.pas',
  X.Database.ODBC in 'code\database\X.Database.ODBC.pas',
  X.SearchUtility in 'code\units\X.SearchUtility.pas',
  X.ScanDetails in 'code\units\X.ScanDetails.pas',
  X.Form.About in 'code\forms\X.Form.About.pas' {frmAbout},
  X.Form.CatColours in 'code\forms\X.Form.CatColours.pas' {frmCategoryColours},
  X.Form.ChartOptions in 'code\forms\X.Form.ChartOptions.pas' {frmChartOptions},
  X.CCSVDataFormat in 'code\classes\X.CCSVDataFormat.pas',
  X.Windows in 'code\units\X.Windows.pas',
  X.CSizeOfFolder in 'code\classes\X.CSizeOfFolder.pas',
  X.CTableDetails in 'code\classes\X.CTableDetails.pas',
  X.Database in 'code\database\X.Database.pas',
  X.Splash.App in 'code\splash\X.Splash.App.pas' {frmSplash},
  X.Splash.Buy in 'code\splash\X.Splash.Buy.pas' {frmDonate},
  X.Splash.Progress in 'code\splash\X.Splash.Progress.pas' {frmProgress},
  X.Splash.Zip in 'code\splash\X.Splash.Zip.pas' {frmZipDisplay},
  X.LanguageHandler in 'code\units\X.LanguageHandler.pas',
  X.ChartUtility in 'code\units\X.ChartUtility.pas',
  X.Conversions in 'code\units\X.Conversions.pas',
  X.DisplayUtility in 'code\units\X.DisplayUtility.pas',
  X.ErrorHandler in 'code\units\X.ErrorHandler.pas',
  X.FileExtensionsObject in 'code\units\X.FileExtensionsObject.pas',
  X.Formatting in 'code\units\X.Formatting.pas',
  X.GlobalObjects in 'code\units\X.GlobalObjects.pas',
  X.GridUtility in 'code\units\X.GridUtility.pas',
  X.GuiLogic in 'code\units\X.GuiLogic.pas',
  X.Settings in 'code\units\X.Settings.pas',
  X.Form.SelectLanguage in 'code\forms\X.Form.SelectLanguage.pas' {frmSetLanguage},
  X.CQuickMenuHandler in 'code\classes\X.CQuickMenuHandler.pas',
  X.Form.QuickMenuBuilder in 'code\forms\X.Form.QuickMenuBuilder.pas' {frmQuickMenuBuilder},
  X.SystemGlobal in 'code\units\X.SystemGlobal.pas',
  X.Frame.FileHistory in 'code\frames\X.Frame.FileHistory.pas' {FrameFolderHistory: TFrame},
  X.Frame.Navigation in 'code\frames\X.Frame.Navigation.pas' {FrameNavigation: TFrame},
  X.Frame.Reports in 'code\frames\X.Frame.Reports.pas' {FrameReports: TFrame},
  X.Frame.Search in 'code\frames\X.Frame.Search.pas' {FrameSearch: TFrame},
  X.Frame.Summary in 'code\frames\X.Frame.Summary.pas' {frameSummary: TFrame},
  X.Frame.WebReports in 'code\frames\X.Frame.WebReports.pas' {FrameWebReports: TFrame},
  X.Frame.Map in 'code\frames\X.Frame.Map.pas' {FrameMap: TFrame},
  X.Form.DatabaseInfo in 'code\forms\X.Form.DatabaseInfo.pas' {frmDatabaseInfo},
  X.Form.DBSelectedFolder in 'code\forms\X.Form.DBSelectedFolder.pas' {frmDBSelectedFolder},
  X.Frame.Select in 'code\frames\X.Frame.Select.pas' {FrameSelect: TFrame},
  X.Form.EditCSVReport in 'code\forms\X.Form.EditCSVReport.pas' {frmEditCSVReport},
  X.Form.EditTreeReport in 'code\forms\X.Form.EditTreeReport.pas' {frmEditTreeReport},
  X.Form.EditXmlReport in 'code\forms\X.Form.EditXmlReport.pas' {frmEditXMLReport},
  X.CReportOptions in 'code\classes\X.CReportOptions.pas',
  X.Form.FileAges in 'code\forms\X.Form.FileAges.pas' {frmFileAges},
  X.Form.FileSpread in 'code\forms\X.Form.FileSpread.pas' {frmSpread},
  X.Help in 'code\units\X.Help.pas',
  X.Form.EditHTMLReport in 'code\forms\X.Form.EditHTMLReport.pas' {frmEditHTMLReport},
  X.CHTMLPreview in 'code\classes\X.CHTMLPreview.pas',
  X.CReportColours in 'code\classes\X.CReportColours.pas',
  Vcl.Themes,
  Vcl.Styles,
  X.CHTMLReports in 'code\classes\X.CHTMLReports.pas',
  X.CTextReports in 'code\classes\X.CTextReports.pas',
  X.CXMLReports in 'code\classes\X.CXMLReports.pas',
  X.ReportUtility in 'code\units\X.ReportUtility.pas',
  X.CXinorbisReports in 'code\classes\X.CXinorbisReports.pas',
  X.CCSVReports in 'code\classes\X.CCSVReports.pas',
  X.CTreeReports in 'code\classes\X.CTreeReports.pas',
  X.CSummaryReports in 'code\classes\X.CSummaryReports.pas',
  X.CReportInfo in 'code\classes\X.CReportInfo.pas',
  X.CFolderHistoryUtility in 'code\classes\X.CFolderHistoryUtility.pas' {$R *.res},
  X.Form.FileAssociations in 'code\forms\X.Form.FileAssociations.pas' {frmFileAssociations},
  X.Frame.Exploder in 'code\frames\X.Frame.Exploder.pas' {FrameExploder: TFrame},
  X.Form.ReportOptions in 'code\forms\X.Form.ReportOptions.pas' {Form1},
  X.ThemeHelper in 'code\units\X.ThemeHelper.pas';

{$R *.res}


begin
  Application.Initialize;

  // ===========================================================================
  // ===========================================================================

  TStyleManager.TrySetStyle('Carbon');

  {$IFDEF CPUX64}
      Application.Title := 'Xinorbis 8.0 Pro (64-bit)';
  {$ELSE}
      Application.Title := 'Xinorbis 8.0 Pro (32-bit)';
  {$ENDIF}

  // ===========================================================================
  // ===========================================================================

  GSystemGlobal := TSystemGlobal.Create; // important it's first!!

  XSettings := TSettingsObject.Create;
  XSettings.CustomSettings.SettingsSaveLocation := SaveLocationRegistry;
  XSettings.CustomSettings.CopyPreferences      := False;
  XSettings.Database.PrivacyActive              := False;
  XSettings.LastScanMultiple                    := False;

  XSettings.LoadCustomSettings;

  XSettings.LoadLanguage;

  if XSettings.CurrentLanguage = LanguageUNDEFINED then
    XSettings.CurrentLanguage := GetInitialLanguage;

  if (XSettings.ShowSpecial) then begin

    ShowMessage('The data path for ALL Xinorbis data is now:' + #13#13 +
                '\users\<user>\Documents\MaximumOctopus\Xinorbis' + #13#13 +
                'instead of (default):' + #13#13 +
                '\users\<user>\Xinorbis' + #13#13 +
                'YOU MUST move the old data to this new folder in order to use it.' + #13#13 +
                'Xinorbis will NOT MOVE the data for you.' + #13#13 +
                'See Help->About to view this folder on your system.');
//               mtWarning, [mbOK], 0);

    XSettings.SaveSpecial;
  end;

  // ===========================================================================
  // ===========================================================================

  TLanguageHandler.InitLanguage(XSettings.CurrentLanguage);

  // ===========================================================================
  // ===========================================================================

  GSystemGlobal.InstallationCheck;

  // ===========================================================================
  // ===========================================================================

  if ParamCount = 0 then begin
    frmSplash := TfrmSplash.Create(Application);
    frmSplash.Show;
    frmSplash.Update;

    if CheckForNewVersionSilent(x8Version, x8Date, 'x8') = mrAll then
      Halt(0);

    while frmSplash.Timer1.Enabled do
      Application.ProcessMessages;

    //its not? close it.
    frmSplash.Hide;
    frmSplash.Free;
  end;

  // ===========================================================================
  // ===========================================================================

  Application.CreateForm(TfrmMain, frmMain);
  Application.CreateForm(TfrmProgress, frmProgress);
  Application.CreateForm(TfrmZipDisplay, frmZipDisplay);
  Application.CreateForm(TfrmFileAges, frmFileAges);
  Application.CreateForm(TfrmSpread, frmSpread);
  Application.CreateForm(TfrmFileAssociations, frmFileAssociations);
  Application.CreateForm(TForm1, Form1);
  // ===========================================================================
  // ===========================================================================

  Application.Run;

  // ===========================================================================
  // ===========================================================================
end.
