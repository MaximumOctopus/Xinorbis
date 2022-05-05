{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.GuiLogic;

interface

uses
  Vcl.Buttons, AdvGrid,

  X.CReportOptions, X.Settings;


const
  CWindowAnalysisProgress = 0;
  CWindowZipProgress      = 1;


type
  TMainReportsChange       = procedure(const aNewTab : integer) of object;

  TSetStatusBarText        = procedure(const aText : string) of object;
  TSetTutorialBarText      = procedure(const aText : string) of object;

  TExtSetSidePanelDisplay  = procedure(welcomeID, taskID, tasksubID, canAddToHistory : integer) of object;

  TOpenSettingsTab         = procedure(const aNewTab : integer) of object;
  TOpenSearchWizard        = procedure(const aStatus : integer) of object;

  TChangeFHPath            = procedure(const aPath : string) of object;

  TToggleColumn            = procedure(const grid : TAdvStringGrid; buttonID : TSpeedButton; columnID, glyphID : integer);

  TUpdateLeftStatusPanel   = procedure(const aStatus : integer) of object;

  TScanWithNewPath         = procedure(aDataIndex : integer; aFromFile : boolean; const aNewPath : string) of object;
  TScanWithMultiple        = procedure(const aStatus : integer) of object;

  TSearchWithParameter     = procedure(aDataIndex : integer; const aNewSearch : string) of object;
  TNewSummary              = procedure(aDataIndex : integer; const aAutoOpen : integer) of object;

  TProcessWindowProgress   = procedure(const aProgress : integer) of object;
  TProcessWindowStatus     = procedure(const aWindow, aStatus : integer) of object;

  TMenuChange              = procedure(const aNewText : string; aMenuItem, aState : integer) of object;

  TJustInTime              = procedure(aValue : integer) of object;

  TGetLeftOffset           = function: integer of object;
  TGetTopOffset            = function: integer of object;

  TIsFHUpdateThreadRunning = function: boolean of object;

  TOnResetDisplay          = procedure(aStatus : integer) of object;

  TBuildInformationDisplay = procedure(aPage : integer) of object;

  TScanFromFolderHistory   = procedure(const aScanPath, aTableName : string; aFileHistoryDate : string) of object;
  TUpdateHistoryFinished   = procedure of object;

  TChartsHaveChanged       = procedure of object;

  TNewReport               = procedure of object;


implementation

end.
