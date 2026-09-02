//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormDBSelectedFolder.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm20 *Form20;
//---------------------------------------------------------------------------
__fastcall TForm20::TForm20(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm20::FormClose(TObject *Sender, TCloseAction &Action)
{
/*  fd : TFormDetails;

 begin
  fd.formID :=_DBSelectedFolder;
  fd.x      := Left;
  fd.y      := Top;
  fd.w      := Width;
  fd.h      := Height;
  fd.p1     := sgDatabase.Width;

  XSettings.SaveFormDetails(fd); */

	Action = caFree;
}


void __fastcall TForm20::Image1Click(TObject *Sender)
{
// TXWindows.ExecuteFile(0, '"' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\' + '"', '', '');
}


void __fastcall TForm20::bHelpClick(TObject *Sender)
{
	//HelpHandler::OpenHelpPage(L"dbselectedfolder.htm");
}


void __fastcall TForm20::bFilesClick(TObject *Sender)
{
/*  t,dataselect : integer;
  doutput : double;

 begin
  dataselect :=TBitBtn(Sender).Tag;

  vtcSelected.SeriesList[0].Clear;

  for t := 1 to sgDatabase.RowCount - 1 do begin
	case dataselect of
	  CDataFiles : vtcSelected.SeriesList[0].Add(StrToFloat(sgDatabase.Cells[1, t]), IntToStr(t), DefaultDisplayColours[1 + (t mod 12)]);
	  CDataSize  : begin
					 case graphsizeformat of
					   CGraphFormatKilobyte : doutput := StrToInt64(sgDatabase.Cells[4, t]) / Int64(1024);               // size in KB
					   CGraphFormatMegabyte : doutput := StrToInt64(sgDatabase.Cells[4, t]) / Int64(1024 * 1024);        // size in MB
					   CGraphFormatGigabyte : doutput := StrToInt64(sgDatabase.Cells[4, t]) / Int64(1024 * 1024 * 1024); // size in GB
					 else
					   doutput := StrToInt64(sgDatabase.Cells[4, t]) / Int64(1024);                   // size in KB
					 end;

							  vtcSelected.SeriesList[0].Add(doutput, IntToStr(t), DefaultDisplayColours[1 + (t mod 12)]);
		  end;
	end;*/
}


void __fastcall TForm20::bCopyClick(TObject *Sender)
{
	// TGridUtility.CopyGridToClipboard(0, sgDatabase);
}



/*    folder history

const
  CGraphFormatKilobyte = 0;
  CGraphFormatMegabyte = 1;
  CGraphFormatGigabyte = 2;

  CDataFiles           = 0;
  CDataSize            = 1;


procedure DoDBSelectedFolder(const a, b : string);
 begin
  with TfrmDBSelectedFolder.Create(Application) do
    try
      ComputerName :=a;
      ScanPath     :=b;

      lComputerName.Caption :=a;
      lFolder.Caption       :=b;

      ShowModal;
    finally
      free;
    end;
end;


procedure TfrmDBSelectedFolder.FormCreate(Sender: TObject);
 var
  fd : TFormDetails;

 begin
  bClose.Caption := XText[rsCancel];

  bFiles.Caption := XText[rsFiles];
  bSize.Caption  := XText[rsSize];

  sgDatabase.ColWidths[1] := 80;
  sgDatabase.ColWidths[2] := 80;
  sgDatabase.ColWidths[3] := 80;
  sgDatabase.HideColumn(4);

  fd := XSettings.LoadFormDetails(_DBSelectedFolder);

  if fd.formID <> -1 then begin
    Width            := fd.w;
    Height           := fd.h;
    sgDatabase.Width := fd.p1;

    sgDatabaseResize(Nil);
  end;
end;


procedure TfrmDBSelectedFolder.FormShow(Sender: TObject);
 var
  tf : TextFile;
  s,xprop,xvalue : string;
  largestitem : int64;

 begin
  largestitem := 0;

  sgDatabase.Cells[0, 0] := XText[rsDateTime];
  sgDatabase.Cells[1, 0] := XText[rsFiles];
  sgDatabase.Cells[2, 0] := XText[rsSizeOfFiles];
  sgDatabase.Cells[3, 0] := XText[rsFolders];

  Caption := XText[rsSelectedFolder];

  bHelp.Caption   := XText[rsHelp];

  if FileExists(GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh') then begin
    AssignFile(tf, GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh');
    {$I-}
    Reset(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorOpening] + ': ' + XText[rsFolderHistory],
                  XText[rsErrorOpeningXinorbisSystemFile] + ': ' + #13#13 +
                  GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh',
                  XDialogTypeWarning);
    end
    else begin
      // read the first line, it contains the scan path --------------------------
      Readln(tf, s);
      // -------------------------------------------------------------------------

      while not(eof(tf)) do begin
        Readln(tf, s);

        if s[1] = '{' then begin
        end
        else if s[1] = '}' then begin
          sgDatabase.RowCount := sgDatabase.RowCount + 1;
        end
        else begin
          xprop  := Copy(s, 1, 3);
          xvalue := Copy(s, 5, length(s) - 4);

          case IdentifyProperty(xprop) of
            CPropertyScanDateString : sgDatabase.Cells[0, sgDatabase.RowCount - 1] := xvalue;
           // : sgDatabase.Cells[1, sgDatabase.RowCount - 1] := xvalue;
            CPropertyFileCount      : sgDatabase.Cells[1, sgDatabase.RowCount - 1] := xvalue;
            CPropertyTotalSize      : begin
                                        sgDatabase.Cells[2, sgDatabase.RowCount - 1] := TConvert.ConvertToUsefulUnit(StrToInt64(xvalue));
                                        sgDatabase.Cells[4, sgDatabase.RowCount - 1] := xvalue;

                                        largestitem := StrToInt64(xvalue);                            // ?
                                      end;
            CPropertyFolderCount    : sgDatabase.Cells[3, sgDatabase.RowCount - 1] := xvalue;
          end;
        end;
      end;

      CloseFile(tf);
    end;
    {$I+}

    sgDatabase.RowCount := sgDatabase.RowCount - 1;

    lCount.Caption := XText[rsFound] + ': ' + IntToStr(sgDatabase.RowCount - 1);

    if largestitem < (1024 * 1024) then
      graphsizeformat := CGraphFormatKilobyte
    else if largestitem < (1024 * 1024 * 1024) then
      graphsizeformat := CGraphFormatMegabyte
    else
      graphsizeformat := CGraphFormatGigabyte;

    BuildGraph(bFiles);
  end
  else begin

  end;
end;



end. */


void __fastcall TForm20::vtcSelectedMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
/*  AValueIndex : integer;

begin
  AValueIndex := TChart(Sender).SeriesList[0].GetCursorValueIndex;

  if AValueIndex > -1 then begin
	Screen.cursor := crHandPoint;

	sgDatabase.SelectRows(AValueIndex + 1, 1);
  end
  else begin
	Screen.cursor := crDefault;
  end;*/
}


void __fastcall TForm20::sgDatabaseDrawCell(TObject *Sender, System::LongInt ACol,
          System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*procedure TfrmDBSelectedFolder.sgDatabaseDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
 var
  l,w : integer;

 begin
  if ARow <> 0 then begin
	case ACol of
	  1,2,3 : begin
				w := TAdvStringGrid(Sender).Canvas.TextWidth(TAdvStringGrid(Sender).Cells[ACol, ARow]);
				l := TAdvStringGrid(Sender).ColWidths[ACol] - w;

				TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + l - 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
			  end;
	end;
  end;
end;

procedure TfrmDBSelectedFolder.sgDatabaseGetCellColor(Sender: TObject; ARow,
  ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
begin
  if gdSelected in AState then
	ABrush.Color := CGridColourSelected
  else begin
	if Odd(ARow) then
	  ABrush.Color := CGridColourOn
	else
	  ABrush.Color := CGridColourOff;
  end;
end;*/
}


void __fastcall TForm20::Splitter1Moved(TObject *Sender)
{
//	sgDatabase.ColWidths[0] := sgDatabase.Width - (240 + 23);
}
