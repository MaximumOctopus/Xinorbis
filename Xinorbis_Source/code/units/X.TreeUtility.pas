unit X.TreeUtility;

interface

uses
  htmltv, clipbrd,

  X.Formatting, X.Utility;


type
  TTreeUtility = class
  public
    class procedure CopyTreeToClipboard(XTree : THTMLTreeView);
  end;


implementation


class procedure TTreeUtility.CopyTreeToClipboard(XTree : THTMLTreeView);
 var
  s : string;
  t : integer;

 begin
  s := '';

  for t := 0 to XTree.Items.Count - 1 do begin
    s := s + TXFormatting.StringOfChars(XTree.Items[t].Level * 2, ' ') + XTree.Items[t].Text + #13;
  end;

  Clipboard.AsText := s;
end;


end.
