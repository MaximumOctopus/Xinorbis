//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormProgress.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm18 *Form18;
//---------------------------------------------------------------------------
__fastcall TForm18::TForm18(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



/*

procedure TfrmProgress.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  Action := caFree;
end;


procedure TfrmProgress.SetProcessText(const s : string);
 begin
  lStatus.Caption := s;
  lStatus.Refresh;

  lStatus2.Caption := '';
  lStatus2.Refresh;

  lStatus3.Caption := '';
  lStatus3.Refresh;
end;


procedure TfrmProgress.SetPercentage(const s : string);
 begin
  lStatus2.Caption := s;
  lStatus2.Invalidate;
end;


procedure TfrmProgress.SetStatus3(const s : string);
 begin
  lStatus3.Caption := s;
  lStatus3.Invalidate;
end;


procedure TfrmProgress.SetProcessIcon(i : integer);
 var
  lImage : TImage;

 begin
  lImage := Nil;

  case i of
    1 : lImage := iProgress1;
    2 : lImage := iProgress2;
    3 : lImage := iProgress3;
    4 : lImage := iProgress4;
    5 : lImage := iProgress5;
  end;

  lImage.Visible := True;
  lImage.Invalidate;
end;


procedure TfrmProgress.SetProcessBar(newposition : integer);
 begin
//  pbProcess.Position := newposition;
//  pbProcess.Invalidate;
end;


procedure TfrmProgress.FormCreate(Sender: TObject);
begin
  sbStop.Caption := XText[kCancel];
end;


procedure TfrmProgress.sbStopClick(Sender: TObject);
begin
// stopscan := True;

//  ffMain.Abort;

//  XSettings.ProgressForm.SetAbort;
end;


procedure TfrmProgress.SetAbort;
 begin
  lAbortStatus.Visible := True;
  lAbortStatus.Invalidate;
end;


*/