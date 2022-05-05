{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Help;

interface


uses
  Sysutils,

  X.Constants,

  X.Dialogs.Dialog,

  X.LanguageHandler, X.SystemGlobal, X.Windows;



type
  THelp = class
  public
    class procedure OpenContextHelpPage(aNavHistoryItem : string; aReportsIndex, aFHMainIndex, aFHSubIndex : integer);
    class procedure OpenHelpPage(aPageName : string);
    class procedure OpenSearchManual;
  end;


implementation


class procedure THelp.OpenHelpPage(aPageName : string);
begin
  TXWindows.ExecuteFile(0, GSystemGlobal.HelpPath + LowerCase(aPageName), '', '');
end;


class procedure THelp.OpenSearchManual;
begin
  TXWindows.ExecuteFile(0, '"' + GSystemGlobal.ExePath + 'Xinorbis8 Search Manual.pdf"', '', '');
end;


class procedure THelp.OpenContextHelpPage(aNavHistoryItem : string; aReportsIndex, aFHMainIndex, aFHSubIndex : integer);
var
  s : string;
  htaskID, hwelcomeID : integer;

begin
  htaskID    := -1;
  hwelcomeID := -1;

  case aNavHistoryItem[1] of
    'H' : {};
    'W' : hwelcomeID := StrToInt(aNavHistoryItem[2]);
    'T' : htaskID    := StrToInt(aNavHistoryItem[2]);
  end;

  s := '';

  // ===========================================================================
  // ===========================================================================

  case htaskID of
    1 : s := 't11';             // summary
    2 : begin
          case aReportsIndex of // report
             0 : s := 't21';
             1 : s := 't22';
             2 : s := 't23';
             3 : s := 't24';
             4 : s := 't25';
             5 : s := 't26';
             6 : s := 't27';
             7 : s := 't28';
             8 : s := 't29';
             9 : s := 't2a';
            10 : s := 't2b';
            11 : s := 't2c';
          end;
        end;
    3 : s := 't31';
    4 : s := 't41';
    5 : s := 't51';
  end;

  // ===========================================================================
  // ===========================================================================

  case hWelcomeID of
    1 : s := 'w11';
    2 : begin
          case aFHMainIndex of
            TabFHMainStats   : case aFHSubIndex of
                                  TabFHChart      : s := 'w22';
                                  TabFHTable      : s := 'w23';
                                  TabFHTimeLine   : s := 'w28';
                               end;

            TabFHMainSearch  : case aFHSubIndex of
                                 TabFHCompare     : s := 'w25';
                                 TabFHCompareDiff : s := 'w26';
                                 TabFHCompareTree : s := 'w27';
                               end;
          end;
        end;
  end;

  // ===========================================================================
  // ===========================================================================

  if (hTaskID = -1) and (hWelcomeID = -1) then
    s := 'index';

  // ===========================================================================
  // ===========================================================================

  if (s <> '') then
    OpenHelpPage(s + '.htm')
  else
    ShowXDialog(XText[rsErrorOpeningXinorbisSystemFile],
                'Error : Can''t find help page: ' + GSystemGlobal.ExePath + 'data\help\' + s + '.htm',
                XDialogTypeWarning);

  // ===========================================================================
  // ===========================================================================
end;


end.
