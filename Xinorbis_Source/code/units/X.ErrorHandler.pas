{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: April 23rd 2009
  Last Modified: January 11th 2020
}


unit X.ErrorHandler;

interface


uses
  System.UITypes,

  TMSLogging,

  X.Dialogs.Dialog, X.LanguageHandler;


type
  TErrorHandler = class
    class procedure HandleError(aMessage : string; aShowUser : boolean);
  end;


implementation


class procedure TErrorHandler.HandleError(aMessage : string; aShowUser : boolean);
begin
  if aShowUser then
    ShowXDialog(XText[rsWarning], aMessage, XDialogTypeWarning);

  TMSLogger.Info(aMessage);
end;


end.
