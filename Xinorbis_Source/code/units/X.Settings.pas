{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: September 24th 2014
  Last Modified: January 13th 2020
}


unit X.Settings;

interface

uses
  Windows, classes, VCLTee.Chart, inifiles, Registry, ComCtrls, Messages, dialogs,
  System.SysUtils, Graphics, Contnrs, Forms, ClipBrd, ShlObj,
  AdvGrid, VCLTee.TeEngine, ShFolder, dateutils, VCLTee.TeCanvas,

  TMSLogging,

  X.Global, X.LanguageHandler,
  X.Splash.Progress, X.Splash.Zip,
  X.CScanHistoryObject, X.CReportColours,

  X.Database,

  X.Constants, X.CReportOptions;


type

  TFormDetails = record
                   formID : integer;
                   x, y   : integer;
                   w, h   : integer;
                   p1, p2, p3, p4 : integer;
                 end;

  TReportOptions  = record
    HTMLOutput           : string;
    HTMLOptions          : array[1..ReportTypesCount] of THTMLReportOptions;

    HTMLCompareOutput    : string;
    HTMLCompareOptions   : THTMLCompareOptions;

    // ==========================================================
    TextOutput           : string;
    TextOptions          : array[1..ReportTypesCount] of TTextReportOptions;

    // ==========================================================
    XMLOutput            : string;
    XMLOptions           : array[1..ReportTypesCount] of TXMLReportOptions;

    // ==========================================================
    TreeOutput           : string;
    TreeOptions          : array[1..ReportTypesCount] of TTreeReportOptions;

    // ==========================================================
    XinorbisOptions      : array[1..ReportTypesCount] of TXinorbisReportOptions;

    // ==========================================================
    CSVOutput            : string;
    CSVOptions           : array[1..ReportTypesCount] of TCSVReportOptions;

    // ==========================================================
    SummaryLayout        : string;

    // ==========================================================

    AutoSaveMode         : boolean;
    AutoSaveOrganise     : boolean;
    AutoSaveItem         : array[1..6] of boolean;
  end;

  TOptimisations  = record
    JustInTimeDisplay    : boolean;
    BuildDateTree        : boolean;

    AddToDate            : boolean;
    AddToDateLimit       : boolean;
    AddToDateLimitCount  : integer;

    GetUserDetails       : boolean;
    GetTempFiles         : boolean;
    ProgressUpdate       : integer;
  end;

  TDatabaseOptions = record
    UseODBC              : boolean;
    ODBConnectionString  : string;

    PrivacyActive        : boolean;
    PrivacyMode          : integer;
  end;

  TSpecial = record
    NewDataPath : boolean;
  end;

  TNavigationOptions = record
    BarColours     : array[1..6] of integer;
    DisplayOptions : array[0..1] of string;
  end;

  TSystemSettings = record
    ActivatedName      : string;
    ActivatedEmail     : string;
    ActivatedCode      : string;
    HasPurchased       : boolean;

    Debug              : boolean;
    RunX               : integer;

    TreeIndex          : integer;

    Tutorial           : boolean;
    UserEnabledFH      : boolean;
    UserEnabledVirtual : boolean;

    JustInTimeProcessed  : array[0..2, 0..18] of boolean;  // [source, jit option]
  end;

  TGeneralOptions = record
    AutoCheckUpdate      : boolean;
    DateFormat           : integer; // 0: dd/mm/yyyy 1: mm/dd/yyyy 2: yyyy/mm/dd
    MaxSearchResults     : integer;
    RowHeight            : integer;
    TableBandColour      : integer;

    PostScanMode         : integer; // nothing, summary, information page, structure
    PostScanIPPage       : integer;

    CustomViewer         : string;

    SaveLog              : boolean;
  end;

  TCustomSettings = record
    SettingsSaveLocation : boolean;
    CopyPreferences      : boolean;
  end;

  TChartOptions = record
    Result        : integer;

    ChartType     : integer; // 0 = bar, 1 = pie, 2 = horizontalbar  // but not used, each form frame to decide/save/load

    ChartStyles   : integer;
    ChartFrom     : integer;
    ChartTo       : integer;
    ChartGradient : boolean;
    Zoom          : integer;
    Elevation     : integer;
    Explode       : integer;
    MarkColour    : integer;
    ShowMarks     : boolean;
    MarksType     : integer;
    LabelOptions  : integer;
    XAxisDelta    : integer;
    ShowLegend    : boolean;

    TitleColour   : integer;
  end;

  TChartSettings = record
    Options     : TChartOptions;
  end;

  THistorySettings       = record
    Enabled     : boolean;
    FullLogging : boolean;
    SQLinSearch : boolean;
  end;

  TForms = record
    ProgressForm         : TfrmProgress;
    ZipForm              : TfrmZipDisplay;
  end;

  TSettingsObject = class
  private
    FReg    : TRegistry;
    Fconfig : TINIFile;

    FDefault : boolean;
  public
    LastScanMultiple     : boolean;

    CurrentLanguage      : integer;

    HandleMultipleExt    : integer;

    FHCompare            : array[1..2, 1..6] of boolean;

    XSQuickFolder        : array[1..QuickFolderCount] of string;

    // ==========================================================
    TabDisplayOptions    : array[0..3] of string;

    // ==========================================================
    ftpOptions           : array[1..ftpOptionsCount] of string;

    // ==========================================================
    ProgressPercentage   : integer;
    ProgressFileCount    : integer;

    // ==========================================================
    Charts               : TChartSettings;
    CustomSettings       : TCustomSettings;
    Database             : TDatabaseOptions;
    Forms                : TForms;
    General              : TGeneralOptions;
    HistorySettings      : THistorySettings;
    Navigation           : TNavigationOptions;
    Optimisations        : TOptimisations;
    Report               : TReportOptions;
    System               : TSystemSettings;

    Special              : TSpecial;

    // =======================================================

    constructor Create;
    destructor Destroy; override;

    function  OpenSettings(aReadOnly : boolean): boolean;
    function  CloseSettings: boolean;

    function  SetAllToDefault: boolean;

    function  LoadBasic: integer;
    function  LoadLanguage: boolean;
    function  SaveBasic: boolean;

    function  ShowSpecial: boolean;
    function  SaveSpecial: boolean;

    function  ReadRegistryString(keyname : string; defaultval : string): string;
    function  ReadRegistryInteger(keyname : string; defaultval : Integer): Integer;
    function  ReadRegistryBool(keyname : string; defaultval : boolean): Boolean;
    function  ReadStringFromSettings(section, name, default : string): string;
    function  ReadIntegerFromSettings(section, name : string; default, ifzero : integer): integer;
    function  ReadIntegerFromSettingsInputCheck(section, name : string; default, min, max : integer): integer;
    function  ReadBoolFromSettings(section, name : string; default : boolean): boolean;

    procedure WriteStringToSettings(section, name, data : string);
    procedure WriteIntegerToSettings(section, name : string; data : integer);
    procedure WriteBoolToSettings(section, name : string; data : boolean);

    procedure LoadCustomSettings;

    function  LoadFormDetails(formID : integer): TFormDetails;
    procedure SaveFormDetails(FormDetails : TFormDetails);
    procedure ClearFormDetails(aFormID : integer);

    function  FTPSettingsValid: boolean;

    procedure ResetChartGradients;

    function  ShowProgressWindow: integer;
    procedure MaximiseProgressWindow;
    procedure MinimiseProgressWindow;
    function  HideProgressWindow: integer;

    //function  ShowPrintWindow: integer;
    //function  HidePrintWindow: integer;

    function  ShowZipWindow: integer;
    function  HideZipWindow: integer;
    function  ProcessWindowsVisible: boolean;
  end;


 var
   XSettings : TSettingsObject;


const
  CDateFormatSlashDDMMYYYY  = 0;
  CDateFormatSlashMMDDYYYY  = 1;
  CDateFormatSlashYYYYMMDD  = 2;
  CDateFormatHyphenDDMMYYYY = 3;
  CDateFormatHyphenMMDDYYYY = 4;


implementation


uses
  X.FileExtensionsObject,

  X.Utility, X.ChartUtility, Main, X.Dialogs.Dialog,
  X.Conversions, X.MD5, X.Windows, X.SystemGlobal;


const
  DefaultChartStyles : array[1..ChartCount] of integer = (XPieChart, XPieChart, XBarChart, XBarChart, XBarChart, XPieChart, XPieChart, XPieChart, XPieChart,
                                                          XPieChart, XPieChart, XPieChart, XPieChart, XBarChart, XPieChart, XBarChart, XBarChart, XPieChart, XPieChart);


constructor TSettingsObject.Create;
 begin
  inherited Create;

  System.Debug := False;

  FDefault     := False;
end;


destructor TSettingsObject.Destroy;
 begin


  inherited Destroy;
end;


function TSettingsObject.OpenSettings(aReadOnly : boolean): boolean;
begin
  Result := True;

  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
    try
      FConfig := TINIFile.Create(GSystemGlobal.ExePath + 'custom.ini');
    except
      on e : exception do begin
        TMSLogger.Error('Error opening settings. ' + e.ClassName + ' / ' + e.Message);

        Result := False;
      end;
    end;
  end
  else begin
    try
      if aReadOnly then
        FReg := TRegistry.Create(KEY_READ)
      else
        FReg := TRegistry.Create(KEY_WRITE);

      FReg.RootKey := HKEY_CURRENT_USER;
      FReg.OpenKey('\software\' + XinorbisRegistryKey, True);
    except
      on e : exception do begin
        TMSLogger.Error('Error opening settings. ' + e.ClassName + ' / ' + e.Message);

        Result := False;
      end;
    end;
  end;
end;


function TSettingsObject.CloseSettings: boolean;
begin
  Result := True;

  try
    if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
      FConfig.Free;
    end
    else begin
      FReg.Free;
    end;
  except
    on e : exception do begin
      TMSLogger.Error('Error closing settings. ' + e.ClassName + ' / ' + e.Message);

      Result := False;
    end;
  end;
end;


// =============================================================================


function TSettingsObject.SetAllToDefault: boolean;
var
  t, z : integer;

begin
  // ===========================================================================
  // ===========================================================================
  // == Initialise                                                            ==
  // ===========================================================================
  // ===========================================================================

  if OpenSettings(True) then begin

    // ===========================================================================
    // ===========================================================================
    // == Language                                                              ==
    // ===========================================================================
    // ===========================================================================

    WriteIntegerToSettings('Prefs', 'Language', LanguageUNDEFINED);

    // ===========================================================================
    // ===========================================================================
    // == Load Settings                                                         ==
    // ===========================================================================
    // ===========================================================================

    WriteIntegerToSettings('Prefs', 'Main_Top',      5);
    WriteIntegerToSettings('Prefs', 'Main_Left',     5);
    WriteIntegerToSettings('Prefs', 'Main_Width', 1016);
    WriteIntegerToSettings('Prefs', 'Main_Height', 700);

    WriteBoolToSettings(   'Prefs', 'Tutorial',   True);

    // ===========================================================================
    // == Chart Options                                                         ==
    // ===========================================================================

  //  WriteIntegerToSettings('Prefs', 'Prefs_ChartStyle' + IntToStr(t),  DefaultChartStyles[t]);

    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_a', $00333333);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_b', $00333333);
    WriteBoolToSettings(   'Prefs', 'Prefs_ChartX8_c', False);

    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_d', 100);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_e', 0);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_f', $00FFFFFF);
    WriteBoolToSettings(   'Prefs', 'Prefs_ChartX8_g', True);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_h',   2);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_i', 315);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_j',   0);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_k',   0);
    WriteBoolToSettings(   'Prefs', 'Prefs_ChartX8_m', True);

    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_l', $00FFFFFF);

    // ===========================================================================
    // == File History                                                          ==
    // ===========================================================================

    for t := 1 to 2 do begin
      for z := 1 to 6 do begin
        WriteBoolToSettings('FHCompare', 'X' + IntToStr(t) + 'Y' + IntToStr(z), False);
      end;
    end;

    // ===========================================================================
    // ==  navigation colours                                                   ==
    // ===========================================================================

    WriteIntegerToSettings('Prefs', 'NavColour1', $00EEEEEE);
    WriteIntegerToSettings('Prefs', 'NavColour2', $00FF4422);
    WriteIntegerToSettings('Prefs', 'NavColour3', $00EEEEEE);
    WriteIntegerToSettings('Prefs', 'NavColour4', $00FF44FF);
    WriteIntegerToSettings('Prefs', 'NavColour5', $00DEDDFF);
    WriteIntegerToSettings('Prefs', 'NavColour6', $005603F1);

    // ===========================================================================
    // == Tab Display Options                                                   ==
    // ===========================================================================

    for t := 0 to 3 do
      WriteStringToSettings('Prefs', 'TabDisplayOptions' + IntToStr(t), '011111111111111111111');

    for t := 0 to 1 do
    begin
      WriteStringToSettings('Prefs', 'NavigateDisplayOptions' + IntToStr(t), '11111111111111111111');
    end;

    // ===========================================================================
    // == FTP                                                                   ==
    // ===========================================================================

    for t := 1 to ftpOptionsCount do
      WriteStringToSettings('Prefs', 'ftpOptions' + IntToStr(t), '');

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    WriteBoolToSettings(   'Prefs', 'JustInTimeDisplay',   True);
    WriteIntegerToSettings('Prefs', 'ProgressUpdate',      1);

    WriteBoolToSettings(   'Prefs', 'AddToDate',           False);
    WriteBoolToSettings(   'Prefs', 'AddToDateLimit',      False);
    WriteIntegerToSettings('Prefs', 'AddToDateLimitCount', 1000);

    WriteBoolToSettings(   'Prefs', 'BuildDateTree',       False);
    WriteBoolToSettings(   'Prefs', 'GetUserDetails',      False);
    WriteBoolToSettings(   'Prefs', 'GetTempFiles',        False);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    WriteIntegerToSettings('Prefs', 'TableBandColour',  $00F9FFF9);
    WriteIntegerToSettings('Prefs', 'RowHeight',        17);

    WriteIntegerToSettings('Prefs', 'DateFormat',       0);
    WriteIntegerToSettings('Prefs', 'MaxSearchResults', 20000);

    WriteStringToSettings( 'Prefs', 'CustomViewer',     'notepad.exe');

    WriteBoolToSettings(   'Prefs', 'SaveLog',          False);

    WriteIntegerToSettings('Prefs', 'PostScanMode',     CPostScanSummary);
    WriteIntegerToSettings('Prefs', 'PostScanIPPage',   0);

    WriteIntegerToSettings('Prefs', 'HandleMultipleExt', 0);
    WriteBoolToSettings(   'Prefs', 'Prefs_ASMode',     False);
    WriteBoolToSettings(   'Prefs', 'Prefs_ASOrganise', False);

    for t := 1 to AutoSaveItemCount do
      WriteBoolToSettings('Prefs', 'Prefs_AutoSaveDrive' + IntToStr(t), False);

    WriteBoolToSettings('Prefs', 'Prefs_AutoCheckUpdate', True);

    WriteStringToSettings('Prefs', 'Prefs_HTMLOutput',        '');
    WriteStringToSettings('Prefs', 'Prefs_HTMLCompareOutput', '');
    WriteStringToSettings('Prefs', 'Prefs_XMLOutput',         'notepad');
    WriteStringToSettings('Prefs', 'Prefs_TextOutput',        'notepad');

    for t := 1 to ReportTypesCount do begin
      WriteIntegerToSettings('Prefs', 'Prefs_CSVData' + IntToStr(t), CDataSummary);
      WriteIntegerToSettings('Prefs', 'Prefs_CSVUnits' + IntToStr(t), 0);
      WriteBoolToSettings(             'Prefs', 'Prefs_CSVTitles' + IntToStr(t), True);
      WriteIntegerToSettings('Prefs', 'Prefs_CSVSeparator' + IntToStr(t), 0);

      WriteIntegerToSettings('Prefs', 'HTMLOptions' + IntToStr(t) + '_HTMLUnits',    0);
      WriteStringToSettings('Prefs',  'HTMLOptions' + IntToStr(t) + '_Layout', '     0:1:2:3:4:5:6:7:8:9:12:13:14:15:16:');
      WriteStringToSettings('Prefs',  'HTMLOptions' + IntToStr(t) + '_CategoryList', '1111111111111111111');
      WriteIntegerToSettings('Prefs', 'HTMLOptions' + IntToStr(t) + '_LayoutSize',   3);

      WriteStringToSettings('Prefs', 'TextOptions' + IntToStr(t) + '_Layout', '1:2:3:4:5:6:7:8:9:12:13:14:');
      WriteStringToSettings('Prefs', 'TextOptions' + IntToStr(t) + '_CategoryList', '1111111111111111111');

      WriteStringToSettings('Prefs', 'TreeOptions' + IntToStr(t) + '_Layout', '1:');
      WriteStringToSettings('Prefs', 'TreeOptions' + IntToStr(t) + '_CategoryList', '1111111111111111111');
      WriteBoolToSettings('Prefs',   'TreeOptions' + IntToStr(t) + '_IncludeSize', True);
      WriteBoolToSettings('Prefs',   'TreeOptions' + IntToStr(t) + '_IncludeAttributes', False);

      WriteStringToSettings('Prefs', 'XMLOptions' + IntToStr(t) + '_Layout',   '1:2:3:4:5:6:7:8:9:12:13:14:');
      WriteIntegerToSettings('Prefs', 'Prefs_XMLData' + IntToStr(t) + '_Data', CDataSummary);
      WriteBoolToSettings('Prefs', 'Prefs_XMLData' + IntToStr(t) + '_Open',    False);

      WriteIntegerToSettings('Prefs', 'XinorbisOptions' + IntToStr(t) + '_Layout',  0);

      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour1',  $990000);  // link normal
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour2',  $000000);  // link hover
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour3',  $FFFFFF);  // background colour
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour4',  $990000);  // text colour
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour5',  $0000FF);  // bargraph colour
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour6',  $FF9900);  // table background
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour7',  $FFFFFF);  // table colour1
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour8',  $000000);  // table colour2
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour9',  $FFFFFF);  // graph background
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour10', $DDDDDD);  // table body background
      WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour11', $CCCCCC);  // table body background II
    end;

    WriteIntegerToSettings('Prefs', 'HTMLCompareOptions' + IntToStr(1) + '_HTMLUnits', 0);
    WriteStringToSettings('Prefs',  'HTMLCompareOptions' + IntToStr(1) + '_Layout', '0:1:2:3:4:');

    WriteStringToSettings('Prefs',  'SummarayLayout',  '1:2:3:4:5:6:7:8:9:');

    // ===========================================================================
    // ==  History                                                              ==
    // ===========================================================================

    WriteBoolToSettings('Prefs', 'Prefs_HistorySettings_Enabled',     True);
    WriteBoolToSettings('Prefs', 'Prefs_HistorySettings_FullLogging', True);
    WriteBoolToSettings('Prefs', 'Prefs_HistorySettings_SQLinSearch', False);

    for t := 1 to __FileCategoriesCount do
      WriteIntegerToSettings('Prefs', 'ChartColour' + IntToStr(t), DefaultDisplayColours[t]);

    // ===========================================================================
    // == Quick Folders                                                         ==
    // ===========================================================================

    for t := 1 to QuickFolderCount do begin
      WriteStringToSettings('Prefs', 'Prefs_QuickFolder' + IntToStr(t), '');
    end;

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    for t := 1 to 10 do
      WriteStringToSettings('TypeDescriptions', 'TypeDescriptions' + IntToStr(t), defaultextfn[t + 9]);

    // ===========================================================================
    // == Close                                                                 ==
    // ===========================================================================

    CloseSettings;
  end;

  // ===========================================================================
  // == Forms
  // ===========================================================================

  ClearFormDetails(_FormFileSpread);
  ClearFormDetails(_FormReference);
  ClearFormDetails(_FormReport);
  ClearFormDetails(_FormInfoDatabase);
  ClearFormDetails(_FormExplore);
  ClearFormDetails(_FormFileAges);
  ClearFormDetails(_FormCombine);
  ClearFormDetails(_FormDeplicates);
  ClearFormDetails(_FormDuplicates);
  ClearFormDetails(_FormReportsList);
  ClearFormDetails(_FormSearchSyntax);

  ClearFormDetails(_FormEditHTMLReport);
  ClearFormDetails(_FormEditTextReport);
  ClearFormDetails(_FormEditTreeReport);
  ClearFormDetails(_FormEditXMLReport);
  ClearFormDetails(_FormEditCSVReport);

  // ===========================================================================
  // ===========================================================================

  FDefault := True;

  Result   := True;
end;


// =============================================================================


function TSettingsObject.ReadRegistryString(keyname : string; defaultval : string): string;
begin
  if FReg.ValueExists(keyname) then begin
    if FReg.ReadString(keyname) = '' then
      Result := defaultval
    else
      Result := FReg.ReadString(keyname);
  end
  else
    Result := defaultval;
end;


function TSettingsObject.ReadRegistryInteger(keyname : string; defaultval : Integer): Integer;
begin
  if FReg.ValueExists(keyname) then
    Result := FReg.ReadInteger(keyname)
  else
    Result := defaultval;
end;


function TSettingsObject.ReadRegistryBool(keyname : string; defaultval : boolean): Boolean;
begin
  if FReg.ValueExists(keyname) then
    Result := FReg.ReadBool(keyname)
  else
    Result := defaultval;
end;


function TSettingsObject.ReadStringFromSettings(section, name, default : string): string;
begin
  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then
    Result := FConfig.ReadString(section, name, default)
  else
    Result := ReadRegistryString(name, default);
end;


function TSettingsObject.ReadIntegerFromSettings(section, name : string; default, ifzero : integer): integer;
begin
  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then
    Result := FConfig.ReadInteger(section, name, default)
  else
    Result := ReadRegistryInteger(name, default);

  if Result = 0 then begin
    if ifzero <> -1 then
      Result := ifzero;
  end;
end;


function TSettingsObject.ReadIntegerFromSettingsInputCheck(section, name : string; default, min, max : integer): integer;
begin
  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then
    Result := FConfig.ReadInteger(section, name, default)
  else
    Result := ReadRegistryInteger(name, default);

  if (Result < Min) or (Result > Max) then
    Result := default;
end;


function TSettingsObject.ReadBoolFromSettings(section, name : string; default : boolean): boolean;
begin
  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then
    Result := FConfig.ReadBool(section, name, default)
  else
    Result := ReadRegistryBool(name, default);
end;


procedure TSettingsObject.WriteStringToSettings(section, name, data : string);
begin
  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then
    Fconfig.WriteString(section, name, data)
  else
    FReg.WriteString(name, data);
end;


procedure TSettingsObject.WriteIntegerToSettings(section, name : string; data : integer);
begin
  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then
    Fconfig.WriteInteger(section, name, data)
  else
    FReg.WriteInteger(name, data);
end;


procedure TSettingsObject.WriteBoolToSettings(section, name : string; data : boolean);
begin
  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then
    Fconfig.WriteBool(section, name, data)
  else
    FReg.WriteBool(name, data);
end;


// =============================================================================


function TSettingsObject.LoadBasic: integer;
var
  tsho   : TScanHistoryObject;
  t,z    : integer;
  s      : string;
  tf     : TextFile;

begin
  // ===========================================================================
  // ===========================================================================
  // == Initialise                                                            ==
  // ===========================================================================
  // ===========================================================================

  if OpenSettings(True) then begin

    // ===========================================================================
    // ===========================================================================
    // == Donation Stuff :(                                                     ==
    // ===========================================================================
    // ===========================================================================

    XSettings.System.RunX := ReadIntegerFromSettings('Prefs', 'RunX', 0, -1);

    // ===========================================================================
    // ===========================================================================
    // == Load Settings                                                         ==
    // ===========================================================================
    // ===========================================================================

    with frmMain do begin
      Top        := ReadIntegerFromSettings('Prefs', 'Main_Top', 5, -1);
      Left       := ReadIntegerFromSettings('Prefs', 'Main_Left', 5, -1);
      Width      := ReadIntegerFromSettings('Prefs', 'Main_Width', 1016, 1016);
      Height     := ReadIntegerFromSettings('Prefs', 'Main_Height', 700, 700);

      System.Tutorial   := ReadBoolFromSettings('Prefs', 'Tutorial', True);

      pTutorial.Visible := System.Tutorial;
    end;

    // ===========================================================================
    // == Chart Options                                                         ==
    // ===========================================================================

    //Charts.Options.ChartStyles   := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_ChartStyle', DefaultChartStyles[t], 0, 1);

    Charts.Options.ChartFrom     := ReadIntegerFromSettings(          'Prefs', 'Prefs_ChartX8_a', $00333333, -1); // check
    Charts.Options.ChartTo       := ReadIntegerFromSettings(          'Prefs', 'Prefs_ChartX8_b', $00333333, -1);
    Charts.Options.ChartGradient := ReadBoolFromSettings(             'Prefs', 'Prefs_ChartX8_c', False);

    Charts.Options.Zoom          := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_ChartX8_d', 100, 0, 150);
    Charts.Options.Explode       := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_ChartX8_e', 0, 0, 150);
    Charts.Options.MarkColour    := ReadIntegerFromSettings(          'Prefs', 'Prefs_ChartX8_f', $00FFFFFF, -1);
    Charts.Options.ShowMarks     := ReadBoolFromSettings(             'Prefs', 'Prefs_ChartX8_g', True);
    Charts.Options.MarksType     := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_ChartX8_h', 2, 0, 4);
    Charts.Options.Elevation     := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_ChartX8_i', 315, 315, 315);
    Charts.Options.LabelOptions  := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_ChartX8_j', 0, 0, 8);
    Charts.Options.XAxisDelta    := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_ChartX8_k', 0, 0, 0);
    Charts.Options.ShowLegend    := ReadBoolFromSettings(             'Prefs', 'Prefs_ChartX8_m', True);

    Charts.Options.TitleColour   := ReadIntegerFromSettings(          'Prefs', 'Prefs_ChartX8_l', $00FFFFFF, -1);

    // ===========================================================================
    // == File History                                                          ==
    // ===========================================================================

    for t := 1 to 2 do begin
      for z := 1 to 6 do begin
        FHCompare[t, z] := ReadBoolFromSettings('FHCompare', 'X' + IntToStr(t) + 'Y' + IntToStr(z), False);
      end;
    end;

    // ===========================================================================
    // ==  navigation colours                                                   ==
    // ===========================================================================

    Navigation.BarColours[1] := ReadIntegerFromSettings('Prefs', 'NavColour1', $00EEEEEE, -1);
    Navigation.BarColours[2] := ReadIntegerFromSettings('Prefs', 'NavColour2', $00FF4422, -1);
    Navigation.BarColours[3] := ReadIntegerFromSettings('Prefs', 'NavColour3', $00EEEEEE, -1);
    Navigation.BarColours[4] := ReadIntegerFromSettings('Prefs', 'NavColour4', $00FF44FF, -1);
    Navigation.BarColours[5] := ReadIntegerFromSettings('Prefs', 'NavColour5', $00DEDDFF, -1);
    Navigation.BarColours[6] := ReadIntegerFromSettings('Prefs', 'NavColour6', $005603F1, -1);

    // ===========================================================================
    // == Tab Display Options                                                   ==
    // ===========================================================================

    for t := 0 to 3 do
      TabDisplayOptions[t]      := ReadStringFromSettings('Prefs', 'TabDisplayOptions' + IntToStr(t), '011111111111111111111');

    for t := 0 to 1 do
    begin
      Navigation.DisplayOptions[t] := ReadStringFromSettings('Prefs', 'NavigateDisplayOptions' + IntToStr(t), '11111111111111111111');

      if length(Navigation.DisplayOptions[t]) <> 20 then
        Navigation.DisplayOptions[t] := '11111111111111111111';
    end;

    // ===========================================================================
    // == FTP                                                                   ==
    // ===========================================================================

    for t := 1 to ftpOptionsCount do
      ftpOptions[t] := ReadStringFromSettings('Prefs', 'ftpOptions' + IntToStr(t), '');

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    Optimisations.JustInTimeDisplay       := ReadBoolFromSettings('Prefs', 'JustInTimeDisplay', True);
    Optimisations.ProgressUpdate          := ReadIntegerFromSettingsInputCheck('Prefs', 'ProgressUpdate', 1, 0, 5);

    ProgressPercentage                    := ProgressUpdates[Optimisations.ProgressUpdate, 1];
    ProgressFileCount                     := ProgressUpdates[Optimisations.ProgressUpdate, 2];

    Optimisations.AddToDate               := ReadBoolFromSettings('Prefs', 'AddToDate', False);
    Optimisations.AddToDateLimit          := ReadBoolFromSettings('Prefs', 'AddToDateLimit', False);
    Optimisations.AddToDateLimitCount     := ReadIntegerFromSettings('Prefs', 'AddToDateLimitCount', 1000, -1);

    Optimisations.BuildDateTree           := ReadBoolFromSettings('Prefs', 'BuildDateTree', False);
    Optimisations.GetUserDetails          := ReadBoolFromSettings('Prefs', 'GetUserDetails', False);
    Optimisations.GetTempFiles            := ReadBoolFromSettings('Prefs', 'GetTempFiles', False);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    General.TableBandColour         := ReadIntegerFromSettings('Prefs', 'TableBandColour', $00F9FFF9, -1);
    General.RowHeight               := ReadIntegerFromSettingsInputCheck('Prefs', 'RowHeight', 17, 15, 40);

    General.DateFormat              := ReadIntegerFromSettingsInputCheck('Prefs', 'DateFormat', 0, 0, 4);
    General.MaxSearchResults        := ReadIntegerFromSettings('Prefs', 'MaxSearchResults', 20000, 20000);

    General.CustomViewer            := ReadStringFromSettings('Prefs', 'CustomViewer', 'notepad.exe');

    General.SaveLog                 := ReadBoolFromSettings('Prefs', 'SaveLog',        False);

    General.PostScanMode            := ReadIntegerFromSettingsInputCheck('Prefs', 'PostScanMode', CPostScanSummary, 0, 3);
    General.PostScanIPPage          := ReadIntegerFromSettingsInputCheck('Prefs', 'PostScanIPPage', 0, 0, 10);

    HandleMultipleExt               := ReadIntegerFromSettingsInputCheck('Prefs', 'HandleMultipleExt', 0, 0, 2);
    Report.AutoSaveMode             := ReadBoolFromSettings('Prefs', 'Prefs_ASMode', false);
    Report.AutoSaveOrganise         := ReadBoolFromSettings('Prefs', 'Prefs_ASOrganise', false);

    for t := 1 to AutoSaveItemCount do
      Report.AutoSaveItem[t] := ReadBoolFromSettings('Prefs', 'Prefs_AutoSaveDrive' + IntToStr(t), False);

    General.AutoCheckUpdate         := ReadBoolFromSettings('Prefs', 'Prefs_AutoCheckUpdate', True);

    Report.HTMLOutput              := ReadStringFromSettings('Prefs', 'Prefs_HTMLOutput', '');
    Report.HTMLCompareOutput       := ReadStringFromSettings('Prefs', 'Prefs_HTMLCompareOutput', '');
    Report.XMLOutput               := ReadStringFromSettings('Prefs', 'Prefs_XMLOutput', 'notepad');

    Report.TextOutput              := ReadStringFromSettings('Prefs', 'Prefs_TextOutput', 'notepad');

    for t := 1 to ReportTypesCount do begin
      Report.CSVOptions[t].CSVData                 := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_CSVData' + IntToStr(t), CDataFileList, CDataSummary, CDataFileList);
      Report.CSVOptions[t].CSVUnits                := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_CSVUnits' + IntToStr(t), 0, 0, 3);
      Report.CSVOptions[t].CSVTitles               := ReadBoolFromSettings(             'Prefs', 'Prefs_CSVTitles' + IntToStr(t), True);
      Report.CSVOptions[t].CSVSeparator            := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_CSVSeparator' + IntToStr(t), 0, 0, 1);
      Report.CSVOptions[t].CSVAutoOpen             := False;

      Report.HTMLOptions[t].HTMLUnits              := ReadIntegerFromSettingsInputCheck('Prefs', 'HTMLOptions' + IntToStr(t) + '_HTMLUnits', 0, 0, 3);
      Report.HTMLOptions[t].Layout                 := ReadStringFromSettings('Prefs',  'HTMLOptions' + IntToStr(t) + '_Layout', '0:1:2:3:4:5:6:7:8:9:12:13:14:15:16:17:');
      Report.HTMLOptions[t].CategoryList           := ReadStringFromSettings('Prefs',  'HTMLOptions' + IntToStr(t) + '_CategoryList', '1111111111111111111');
      Report.HTMLOptions[t].LayoutSize             := ReadIntegerFromSettingsInputCheck('Prefs', 'HTMLOptions' + IntToStr(t) + '_LayoutSize', 3, 1, 3);

      Report.TextOptions[t].Layout                 := ReadStringFromSettings('Prefs', 'TextOptions' + IntToStr(t) + '_Layout', '1:2:3:4:5:6:7:8:9:12:13:14:15:');
      Report.TextOptions[t].CategoryList           := ReadStringFromSettings('Prefs', 'TextOptions' + IntToStr(t) + '_CategoryList', '1111111111111111111');

      Report.TreeOptions[t].Layout                 := ReadStringFromSettings('Prefs', 'TreeOptions' + IntToStr(t) + '_Layout', '1:');
      Report.TreeOptions[t].CategoryList           := ReadStringFromSettings('Prefs', 'TreeOptions' + IntToStr(t) + '_CategoryList', '1111111111111111111');
      Report.TreeOptions[t].IncludeSize            := ReadBoolFromSettings('Prefs',   'TreeOptions' + IntToStr(t) + '_IncludeSize', True);
      Report.TreeOptions[t].IncludeAttributes      := ReadBoolFromSettings('Prefs',   'TreeOptions' + IntToStr(t) + '_IncludeAttributes', False);

      Report.XMLOptions[t].Layout                  := ReadStringFromSettings('Prefs', 'XMLOptions' + IntToStr(t) + '_Layout',  '1:2:3:4:5:6:7:8:9:12:13:14:15:');
      Report.XMLOptions[t].XMLData                 := ReadIntegerFromSettingsInputCheck('Prefs', 'Prefs_XMLData' + IntToStr(t) + '_Data', CDataFileList, CDataSummary, CDataFileList);
      Report.XMLOptions[t].XMLAutoOpen             := ReadBoolFromSettings('Prefs', 'Prefs_XMLData' + IntToStr(t) + '_Open', False);

      Report.XinorbisOptions[t].Layout             := ReadIntegerFromSettings('Prefs', 'XinorbisOptions' + IntToStr(t) + '_Layout',  0, -1);

      Report.HTMLOptions[t].HTMLColours.Colour[1]  := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour1',  $990000, -1);  // link normal
      Report.HTMLOptions[t].HTMLColours.Colour[2]  := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour2',  $000000, -1);  // link hover
      Report.HTMLOptions[t].HTMLColours.Colour[3]  := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour3',  $FFFFFF, -1);  // background colour
      Report.HTMLOptions[t].HTMLColours.Colour[4]  := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour4',  $990000, -1);  // text colour
      Report.HTMLOptions[t].HTMLColours.Colour[5]  := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour5',  $0000FF, -1);  // bargraph colour
      Report.HTMLOptions[t].HTMLColours.Colour[6]  := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour6',  $FF9900, -1);  // table background
      Report.HTMLOptions[t].HTMLColours.Colour[7]  := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour7',  $FFFFFF, -1);  // table colour1
      Report.HTMLOptions[t].HTMLColours.Colour[8]  := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour8',  $000000, -1);  // table colour2
      Report.HTMLOptions[t].HTMLColours.Colour[9]  := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour9',  $FFFFFF, -1);  // graph background
      Report.HTMLOptions[t].HTMLColours.Colour[10] := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour10', $DDDDDD, -1);  // table body background
      Report.HTMLOptions[t].HTMLColours.Colour[11] := ReadIntegerFromSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour11', $CCCCCC, -1);  // table body background II
    end;

    Report.HTMLCompareOptions.HTMLUnits            := ReadIntegerFromSettingsInputCheck('Prefs', 'HTMLCompareOptions' + IntToStr(1) + '_HTMLUnits', 0, 0, 3);
    Report.HTMLCompareOptions.Layout               := ReadStringFromSettings('Prefs',  'HTMLCompareOptions' + IntToStr(1) + '_Layout', '0:1:2:3:4:');

    Report.SummaryLayout                           := ReadStringFromSettings('Prefs',  'SummarayLayout',  '1:2:3:4:5:6:7:8:9:10:');

    // ===========================================================================
    // ==  History                                                              ==
    // ===========================================================================

    HistorySettings.Enabled     := ReadBoolFromSettings('Prefs', 'Prefs_HistorySettings_Enabled', True);
    HistorySettings.FullLogging := ReadBoolFromSettings('Prefs', 'Prefs_HistorySettings_FullLogging', True);
    HistorySettings.SQLinSearch := ReadBoolFromSettings('Prefs', 'Prefs_HistorySettings_SQLinSearch', False);

    GSystemGlobal.FileCategoryColors[0] := $00FFFFFF; // for folders

    for t := 1 to __FileCategoriesCount do
      GSystemGlobal.FileCategoryColors[t] := ReadIntegerFromSettings('Prefs', 'ChartColour' + IntToStr(t), DefaultDisplayColours[t], -1);

    // ===========================================================================
    // == Quick Folders                                                         ==
    // ===========================================================================

    for t := 1 to QuickFolderCount do begin
      s := ReadStringFromSettings('Prefs', 'Prefs_QuickFolder' + IntToStr(t), '');

      if s <> '' then begin
        XSQuickFolder[t] := s;
      end;
    end;

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    for t := 1 to 10 do
      TypeDescriptions[t + 9] := ReadStringFromSettings('TypeDescriptions', 'TypeDescriptions' + IntToStr(t), defaultextfn[t + 9]);

    // ===========================================================================
    // == Close                                                                 ==
    // ===========================================================================

    CloseSettings;
  end;

  // ===========================================================================
  // == Update                                                                ==
  // ===========================================================================

  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
    if FileExists(GSystemGlobal.AppDataPath + 'scanhistory.dat') then begin
      try
        AssignFile(tf, GSystemGlobal.AppDataPath + 'scanhistory.dat');
        Reset(tf);

        While not(eof(tf)) do begin
          tsho := TScanHistoryObject.Create;

          readln(tf, s);
          tsho.Path           := s;

          readln(tf, s);
          tsho.DateI          := StrToIntDef(s, 19000101);

          readln(tf, s);
          tsho.TimeI          := s;

          readln(tf, s);
          tsho.ExcludeFiles   := s;

          readln(tf, s);
          tsho.ExcludeFolders := s;

          ScanHistory.Add(tsho);
        end;
      finally
        CloseFile(tf);
      end;
    end;
  end
  else begin
    FReg := TRegistry.Create(KEY_READ);

    try
      FReg.RootKey := HKEY_CURRENT_USER;
      FReg.OpenKey('\software\' + XinorbisRegistryKey + '\SinglePaths', True);

      t := 0;
      While FReg.ValueExists('PathX' + IntToStr(t)) do begin
        tsho := TScanHistoryObject.Create;

        tsho.Path           := FReg.ReadString('PathX' + IntToStr(t));
        tsho.DateI          := StrToIntDef(FReg.ReadString('PathY' + IntToStr(t)), 19000101);
        tsho.TimeI          := FReg.ReadString('PathZ' + IntToStr(t));
        tsho.ExcludeFiles   := FReg.ReadString('PathE1' + IntToStr(t));
        tsho.ExcludeFolders := FReg.ReadString('PathE2' + IntToStr(t));

        ScanHistory.Add(tsho);

        inc(t);
      end;

    finally
      FReg.Free;
    end;

    // ===========================================================================
    // ===========================================================================

    FReg := TRegistry.Create(KEY_READ);

    try
      FReg.RootKey := HKEY_CURRENT_USER;
      if FReg.OpenKey('\software\' + XinorbisRegistryKey + '\ChartColours', False) then begin
        GSystemGlobal.FileCategoryColors[0] := $00FFFFFF; // for folders

        for t := 1 to __FileCategoriesCount do begin
          if FReg.ValueExists('ChartColour' + IntToStr(t)) then
            GSystemGlobal.FileCategoryColors[t] := FReg.ReadInteger('ChartColour' + IntToStr(t))
          else
            GSystemGlobal.FileCategoryColors[t] := DefaultDisplayColours[t];
        end;
      end
      else begin
        GSystemGlobal.FileCategoryColors[0] := $00FFFFFF; // for folders
        for t := 1 to __FileCategoriesCount do begin
          GSystemGlobal.FileCategoryColors[t] := DefaultDisplayColours[t];
        end;
      end;
    finally
      FReg.Free;
    end;
  end;

  // ===========================================================================
  // ===========================================================================

  //FileExtensionList.Clear;

  Result := -1;
end;


function TSettingsObject.LoadLanguage: boolean;
begin
  // ===========================================================================
  // ===========================================================================
  // == Initialise                                                            ==
  // ===========================================================================
  // ===========================================================================

  if OpenSettings(True) then begin

    // ===========================================================================
    // ===========================================================================
    // == Load Settings                                                         ==
    // ===========================================================================
    // ===========================================================================

    CurrentLanguage := ReadIntegerFromSettings('Prefs', 'Language', LanguageUNDEFINED, -1);

    // ===========================================================================
    // == Close                                                                 ==
    // ===========================================================================

    CloseSettings;
  end
  else
    CurrentLanguage := LanguageUK;

  Result := True;
end;


function TSettingsObject.ShowSpecial: boolean;
var
  NewDataPath : boolean;

begin
  // ===========================================================================
  // ===========================================================================
  // == Initialise                                                            ==
  // ===========================================================================
  // ===========================================================================

  NewDataPath := False;

  if OpenSettings(True) then begin

    // ===========================================================================
    // ===========================================================================
    // == Load Settings                                                         ==
    // ===========================================================================
    // ===========================================================================

    NewDataPath := ReadBoolFromSettings('Special', 'NewDataPath', true);

    // ===========================================================================
    // == Close                                                                 ==
    // ===========================================================================

    CloseSettings;
  end;

  Result := NewDataPath;
end;


function TSettingsObject.SaveSpecial: boolean;
begin
  // ===========================================================================
  // ===========================================================================
  // == Initialise                                                            ==
  // ===========================================================================
  // ===========================================================================

  if OpenSettings(False) then begin

    WriteBoolToSettings('Special', 'NewDataPath', false);

    CloseSettings;
  end;

  Result := True;
end;


function TSettingsObject.SaveBasic: boolean;
var
  tf     : TextFile;
  t, x   : integer;
  tsho   : TScanHistoryObject;

begin
  Result := True;

  if FDefault then Exit;

  // ===========================================================================
  // ===========================================================================
  // == Initialise                                                            ==
  // ===========================================================================
  // ===========================================================================

  if OpenSettings(False) then begin

    // ===========================================================================
    // == Donation Stuff :(                                                     ==
    // ===========================================================================

    inc(XSettings.System.RunX);

    WriteIntegerToSettings('Prefs', 'RunX',    XSettings.System.RunX);

    // ===========================================================================
    // == Window                                                                ==
    // ===========================================================================

    with frmMain do begin
      WriteIntegerToSettings('Prefs', 'Main_Top',    Top);
      WriteIntegerToSettings('Prefs', 'Main_Left',   Left);
      WriteIntegerToSettings('Prefs', 'Main_Width',  Width);
      WriteIntegerToSettings('Prefs', 'Main_Height', Height);

      WriteBoolToSettings('Prefs', 'Tutorial', System.Tutorial);
    end;

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    WriteBoolToSettings('Prefs',    'BuildDateTree',       Optimisations.BuildDateTree);
    WriteBoolToSettings('Prefs',    'GetUserDetails',      Optimisations.GetUserDetails);
    WriteBoolToSettings('Prefs',    'GetTempFiles',        Optimisations.GetTempFiles);

    WriteIntegerToSettings('Prefs', 'TableBandColour',     General.TableBandColour);
    WriteIntegerToSettings('Prefs', 'RowHeight',           General.RowHeight);
    WriteIntegerToSettings('Prefs', 'DateFormat',          General.DateFormat);
    WriteIntegerToSettings('Prefs', 'MaxSearchResults',    General.MaxSearchResults);

    WriteStringToSettings('Prefs',  'CustomViewer',        General.CustomViewer);

    WriteBoolToSettings('Prefs',    'SaveLog',             General.SaveLog);

    WriteIntegerToSettings('Prefs', 'Language',            CurrentLanguage);
    WriteIntegerToSettings('Prefs', 'ProgressUpdate',      Optimisations.ProgressUpdate);
    WriteIntegerToSettings('Prefs', 'PostScanMode',        General.PostScanMode);
    WriteIntegerToSettings('Prefs', 'PostScanIPPage',      General.PostScanIPPage);
    WriteIntegerToSettings('Prefs', 'HandleMultipleExt',   HandleMultipleExt);
    WriteBoolToSettings('Prefs',    'Prefs_ASMode',        Report.autosavemode);
    WriteBoolToSettings('Prefs',    'Prefs_ASOrganise',    Report.autosaveorganise);
    WriteBoolToSettings('Prefs',    'JustInTimeDisplay',   Optimisations.JustInTimeDisplay);

    WriteBoolToSettings('Prefs',    'AddToDate',           Optimisations.AddToDate);
    WriteBoolToSettings('Prefs',    'AddToDateLimit',      Optimisations.AddToDateLimit);
    WriteIntegerToSettings('Prefs', 'AddToDateLimitCount', Optimisations.AddToDateLimitCount);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    for t := 1 to AutoSaveItemCount do
      WriteBoolToSettings('Prefs', 'Prefs_AutoSaveDrive' + IntToStr(t), Report.AutoSaveItem[t]);

    WriteBoolToSettings('Prefs', 'Prefs_AutoCheckUpdate', General.AutoCheckUpdate);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    WriteStringToSettings('Prefs', 'Prefs_HTMLOutput', Report.HTMLOutput);
    WriteStringToSettings('Prefs', 'Prefs_HTMLCompareOutput', Report.HTMLCompareOutput);

    for t := 1 to ReportTypesCount do begin
      WriteIntegerToSettings('Prefs', 'HTMLOptions' + IntToStr(t) + '_HTMLUnits',         Report.HTMLOptions[t].HTMLUnits);
      WriteStringToSettings('Prefs',  'HTMLOptions' + IntToStr(t) + '_Layout',            Report.HTMLOptions[t].Layout);
      WriteStringToSettings('Prefs',  'HTMLOptions' + IntToStr(t) + '_CategoryList',      Report.HTMLOptions[t].CategoryList);
      WriteIntegerToSettings('Prefs', 'HTMLOptions' + IntToStr(t) + '_LayoutSize',        Report.HTMLOptions[t].LayoutSize);

      for x := 1 to HTMLColoursCount do
        WriteIntegerToSettings('Prefs', 'Prefs_Report' + IntToStr(t) + 'HTMLColour' + IntToStr(x), Report.HTMLOptions[t].HTMLColours.Colour[x]);

      WriteStringToSettings('Prefs',  'TextOptions' + IntToStr(t) + '_Layout',            Report.TextOptions[t].Layout);
      WriteStringToSettings('Prefs',  'TextOptions' + IntToStr(t) + '_CategoryList',      Report.TextOptions[t].CategoryList);

      WriteStringToSettings('Prefs',  'TreeOptions' + IntToStr(t) + '_Layout',            Report.TreeOptions[t].Layout);
      WriteStringToSettings('Prefs',  'TreeOptions' + IntToStr(t) + '_CategoryList',      Report.TreeOptions[t].CategoryList);
      WriteBoolToSettings('Prefs',    'TreeOptions' + IntToStr(t) + '_IncludeSize',       Report.TreeOptions[t].IncludeSize);
      WriteBoolToSettings('Prefs',    'TreeOptions' + IntToStr(t) + '_IncludeAttributes', Report.TreeOptions[t].IncludeAttributes);

      WriteStringToSettings('Prefs',  'XMLOptions' + IntToStr(t) + '_Layout',             Report.XMLOptions[t].Layout);
      WriteIntegerToSettings('Prefs', 'Prefs_XMLData' + IntToStr(t) + '_Data',            Report.XMLOptions[t].XMLData);
      WriteBoolToSettings('Prefs',    'Prefs_XMLData' + IntToStr(t) + '_Open',            Report.XMLOptions[t].XMLAutoOpen);

      WriteIntegerToSettings('Prefs', 'XinorbisOptions' + IntToStr(t) + '_Layout',        Report.XinorbisOptions[t].Layout);
    end;

    WriteIntegerToSettings('Prefs', 'HTMLCompareOptions' + IntToStr(1) + '_HTMLUnits',    Report.HTMLCompareOptions.HTMLUnits);
    WriteStringToSettings('Prefs',  'HTMLCompareOptions' + IntToStr(1) + '_Layout',       Report.HTMLCompareOptions.Layout);

    WriteStringToSettings('Prefs', 'Prefs_XMLOutput', Report.XMLOutput);
    WriteStringToSettings('Prefs', 'Prefs_TextOutput', Report.TextOutput);

    WriteIntegerToSettings('Prefs', 'Prefs_OtherCSVUnits',     Report.CSVOptions[LayoutAutoSave].CSVUnits);
    WriteBoolToSettings('Prefs', 'Prefs_OtherCSVTitles',       Report.CSVOptions[LayoutAutoSave].CSVTitles);
    WriteIntegerToSettings('Prefs', 'Prefs_OtherCSVData',      Report.CSVOptions[LayoutAutoSave].CSVData);
    WriteIntegerToSettings('Prefs', 'Prefs_OtherCSVSeparator', Report.CSVOptions[LayoutAutoSave].CSVSeparator);

    WriteIntegerToSettings('Prefs', 'Prefs_CSVUnits',     Report.CSVOptions[LayoutQuick].CSVUnits);
    WriteBoolToSettings('Prefs', 'Prefs_CSVTitles',       Report.CSVOptions[LayoutQuick].CSVTitles);
    WriteIntegerToSettings('Prefs', 'Prefs_CSVData',      Report.CSVOptions[LayoutQuick].CSVData);
    WriteIntegerToSettings('Prefs', 'Prefs_CSVSeparator', Report.CSVOptions[LayoutQuick].CSVSeparator);
    WriteBoolToSettings('Prefs', 'Prefs_CSVAutoOpen',     Report.CSVOptions[LayoutQuick].CSVAutoOpen);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    WriteStringToSettings('Prefs', 'SummarayLayout', Report.SummaryLayout);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    WriteBoolToSettings('Prefs', 'Prefs_HistorySettings_Enabled',     HistorySettings.Enabled);
    WriteBoolToSettings('Prefs', 'Prefs_HistorySettings_FullLogging', HistorySettings.FullLogging);
    WriteBoolToSettings('Prefs', 'Prefs_HistorySettings_SQLinSearch', HistorySettings.SQLinSearch);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_a',  Charts.Options.ChartFrom);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_b',  Charts.Options.ChartTo);
    WriteBoolToSettings('Prefs',    'Prefs_ChartX8_c',  Charts.Options.ChartGradient);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_d',  Charts.Options.Zoom);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_e',  Charts.Options.Explode);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_f',  Charts.Options.MarkColour);
    WriteBoolToSettings('Prefs',    'Prefs_ChartX8_g',  Charts.Options.ShowMarks);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_h',  Charts.Options.MarksType);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_i',  Charts.Options.Elevation);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_j',  Charts.Options.LabelOptions);
    WriteBoolToSettings('Prefs',    'Prefs_ChartX8_m',  Charts.Options.ShowLegend);

    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_k',  Charts.Options.XAxisDelta);
    WriteIntegerToSettings('Prefs', 'Prefs_ChartX8_l',  Charts.Options.TitleColour);

    for t := 1 to QuickFolderCount do
      WriteStringToSettings('Prefs', 'Prefs_QuickFolder' + IntToStr(t), XSQuickFolder[t]);

    GSystemGlobal.FileCategoryColors[0] := $00FFFFFF; // for folders
    for t := 1 to __FileCategoriesCount do
      WriteIntegerToSettings('Prefs', 'ChartColour' + IntToStr(t), GSystemGlobal.FileCategoryColors[t]);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    for t := 1 to 6 do
      WriteIntegerToSettings('Prefs', 'NavColour' + IntToStr(t), Navigation.BarColours[t]);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    for t := 0 to 3 do
      WriteStringToSettings('Prefs', 'TabDisplayOptions' + IntToStr(t), TabDisplayOptions[t]);

    for t := 0 to 1 do
      WriteStringToSettings('Prefs', 'NavigateDisplayOptions' + IntToStr(t), Navigation.DisplayOptions[t]);

    // ===========================================================================
    // ==                                                                       ==
    // ===========================================================================

    for t := 1 to ftpOptionsCount do
      WriteStringToSettings('Prefs', 'ftpOptions' + IntToStr(t), XSettings.ftpOptions[t]);

    // ===========================================================================
    // == Close                                                                 ==
    // ===========================================================================

    CloseSettings;
  end;

  // ===========================================================================
  // == Secondary Data                                                        ==
  // ===========================================================================

  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
    try
      AssignFile(tf, GSystemGlobal.AppDataPath + 'scanhistory.dat');
      Rewrite(tf);

      if ScanHistory.Count <> 0 then begin

        t := 0;
        while (t < ScanHistory.Count) and (t < 100) do begin
          tsho := ScanHistory[t];

          writeln(tf, tsho.Path);
          writeln(tf, IntToStr(tsho.DateI));
          writeln(tf, tsho.TimeI);
          writeln(tf, tsho.ExcludeFiles);
          writeln(tf, tsho.ExcludeFolders);

          inc(t);
        end;
      end;

    finally
      CloseFile(tf);
    end;
  end
  else begin
    if ScanHistory.Count <> 0 then begin
      FReg := TRegistry.Create(KEY_WRITE);

      try
        FReg.RootKey := HKEY_CURRENT_USER;
        FReg.OpenKey('\software\' + XinorbisRegistryKey + '\SinglePaths', True);

        t := 0;
        while (t < ScanHistory.Count) and (t < 100) do begin
          tsho := ScanHistory[t];

          FReg.WriteString('PathX' + IntToStr(t),  tsho.Path);
          FReg.WriteString('PathY' + IntToStr(t),  IntToStr(tsho.DateI));
          FReg.WriteString('PathZ' + IntToStr(t),  tsho.TimeI);
          FReg.WriteString('PathE1' + IntToStr(t), tsho.ExcludeFiles);
          FReg.WriteString('PathE2' + IntToStr(t), tsho.ExcludeFolders);

          inc(t);
        end;
      finally
        FReg.Free;
      end;
    end;

    // ===========================================================================

    FileExtensionsObject.SaveFileExtensionLists(XSettings.CustomSettings.SettingsSaveLocation);
  end;
end;


procedure TSettingsObject.LoadCustomSettings;
var
  config : TINIFile;

begin
  if FileExists(GSystemGlobal.ExePath + 'custom.ini') then begin
    config := TINIFile.Create(GSystemGlobal.ExePath + 'custom.ini');

    try
      if config.ReadInteger('Main', 'useodbc', 0) <> 0 then begin
        Database.useodbc             := True;
        XSettings.Database.ODBConnectionString := config.ReadString('Main', 'connectionstring', '');

        if InitODBC(XSettings.Database.ODBConnectionString) then begin
        end
        else begin
          ShowXDialog(XText[rsError] + ': ' + XText[rsDatabaseConnections],
                      XText[rsErrorConnectingODBC],
                      XDialogTypeWarning);

          XSettings.Database.useodbc := False;
        end;
      end
      else
        XSettings.Database.useodbc := False;

      customsettings.SettingsSaveLocation := TConvert.StringBoolToInteger(config.ReadString('Main', 'PortableMode', '0'));
      customsettings.CopyPreferences      := TConvert.StringBoolToInteger(config.ReadString('Main', 'CopyPrefs', '0'));

      // =========================================================================
      // ==                                                                     ==
      // =========================================================================
    finally
      config.Free;
    end;
  end;

  if not(Database.UseODBC) then
    InitSqlite(GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');
end;


procedure TSettingsObject.SaveFormDetails(FormDetails : TFormDetails);
 var
  Reg : TRegistry;
  config : TIniFile;

 begin
  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
    try
      config := TINIFile.Create(GSystemGlobal.ExePath + 'custom.ini');

      config.WriteInteger('Form_' + IntToStr(FormDetails.formID), 'w',  FormDetails.x);
      config.WriteInteger('Form_' + IntToStr(FormDetails.formID), 'y',  FormDetails.y);
      config.WriteInteger('Form_' + IntToStr(FormDetails.formID), 'w',  FormDetails.w);
      config.WriteInteger('Form_' + IntToStr(FormDetails.formID), 'h',  FormDetails.h);
      config.WriteInteger('Form_' + IntToStr(FormDetails.formID), 'p1', FormDetails.p1);
      config.WriteInteger('Form_' + IntToStr(FormDetails.formID), 'p2', FormDetails.p2);
      config.WriteInteger('Form_' + IntToStr(FormDetails.formID), 'p3', FormDetails.p3);
      config.WriteInteger('Form_' + IntToStr(FormDetails.formID), 'p4', FormDetails.p4);
    finally
      config.Free;
    end;
  end
  else begin
    Reg := TRegistry.Create(KEY_WRITE);

    Reg.RootKey := HKEY_CURRENT_USER;

    Reg.OpenKey('\software\' + XinorbisRegistryKey + '\Form_' + IntToStr(FormDetails.formID), True);

    Reg.WriteInteger('x',  FormDetails.x);
    Reg.WriteInteger('y',  FormDetails.y);
    Reg.WriteInteger('w',  FormDetails.w);
    Reg.WriteInteger('h',  FormDetails.h);
    Reg.WriteInteger('p1', FormDetails.p1);
    Reg.WriteInteger('p2', FormDetails.p2);
    Reg.WriteInteger('p3', FormDetails.p3);
    Reg.WriteInteger('p4', FormDetails.p4);

    Reg.CloseKey;
    Reg.Free;
  end;
end;


procedure TSettingsObject.ClearFormDetails(aFormID : integer);
 var
  Reg : TRegistry;
  config : TIniFile;

 begin
  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
    try
      config := TINIFile.Create(GSystemGlobal.ExePath + 'custom.ini');

      config.EraseSection('Form_' + IntToStr(aFormID));
    finally
      config.Free;
    end;
  end
  else begin
    Reg := TRegistry.Create(KEY_WRITE);

    Reg.RootKey := HKEY_CURRENT_USER;

    Reg.DeleteKey('\software\' + XinorbisRegistryKey + '\Form_' + IntToStr(aFormID));

    Reg.CloseKey;
    Reg.Free;
  end;
end;


function TSettingsObject.LoadFormDetails(formID : integer): TFormDetails;
 var
  Reg : TRegistry;
  config : TIniFile;

 begin
  Result.formID := formID;

  if (customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
    try
      config := TINIFile.Create(GSystemGlobal.ExePath + 'custom.ini');

      if config.SectionExists('Form_' + IntToStr(formID)) then begin
        Result.x  := config.ReadInteger('Form_' + IntToStr(formID), 'w', -1);
        Result.y  := config.ReadInteger('Form_' + IntToStr(formID), 'y', -1);
        Result.w  := config.ReadInteger('Form_' + IntToStr(formID), 'w', -1);
        Result.h  := config.ReadInteger('Form_' + IntToStr(formID), 'h', -1);
        Result.p1 := config.ReadInteger('Form_' + IntToStr(formID), 'p1', -1);
        Result.p2 := config.ReadInteger('Form_' + IntToStr(formID), 'p2', -1);
        Result.p3 := config.ReadInteger('Form_' + IntToStr(formID), 'p3', -1);
        Result.p4 := config.ReadInteger('Form_' + IntToStr(formID), 'p4', -1);
      end
      else
        Result.formID := -1;
    finally
      config.Free;
    end;
  end
  else begin
    Reg := TRegistry.Create(KEY_READ);

    Reg.RootKey := HKEY_CURRENT_USER;

    if Reg.KeyExists('\software\' + XinorbisRegistryKey + '\Form_' + IntToStr(formID)) then begin
      Reg.OpenKey('\software\' + XinorbisRegistryKey + '\Form_' + IntToStr(formID), False);

      Result.x  := Reg.ReadInteger('x');
      Result.y  := Reg.ReadInteger('y');
      Result.w  := Reg.ReadInteger('w');
      Result.h  := Reg.ReadInteger('h');
      Result.p1 := Reg.ReadInteger('p1');
      Result.p2 := Reg.ReadInteger('p2');
      Result.p3 := Reg.ReadInteger('p3');
      Result.p4 := Reg.ReadInteger('p4');
    end
    else
      Result.formID := -1;

    Reg.CloseKey;
    Reg.Free;
  end;
end;


function TSettingsObject.ShowProgressWindow: integer;
 begin
  Result := 0;

  Forms.ProgressForm := TfrmProgress.Create(Application);
  Forms.ProgressForm.Show;
end;


procedure TSettingsObject.MaximiseProgressWindow;
begin
  Forms.ProgressForm.Visible := True;
end;


procedure TSettingsObject.MinimiseProgressWindow;
begin
  Forms.ProgressForm.Visible := False;
end;


function TSettingsObject.HideProgressWindow: integer;
 begin
  Result := 0;

  Forms.ProgressForm.Close;

  Forms.ProgressForm := Nil;
end;


function TSettingsObject.ShowZipWindow: integer;
 begin
  Result := 0;

  Forms.ZipForm := TfrmZipDisplay.Create(Application);
  Forms.ZipForm.Show;
end;


function TSettingsObject.HideZipWindow: integer;
 begin
  Result := 0;

  Forms.ZipForm.Close;

  Forms.ZipForm := Nil;
end;


function TSettingsObject.ProcessWindowsVisible: boolean;
begin
  Result := True;

  if (Forms.ZipForm = Nil) and (Forms.ProgressForm = Nil) then
    Result := False;
end;


procedure TSettingsObject.ResetChartGradients;
begin
  XSettings.Charts.Options.ChartFrom     := 16777215;
  XSettings.Charts.Options.ChartTo       := 16118773;
end;


function TSettingsObject.FTPSettingsValid: boolean;
begin
  if ((ftpOptions[ftpHost] <> '') and
     (ftpOptions[ftpUserName] <> '') and
     (ftpOptions[ftpPassword] <> '')) then

    Result := true
  else
    Result := false;
end;


end.
