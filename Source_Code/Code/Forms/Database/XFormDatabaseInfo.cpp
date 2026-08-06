//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFormDatabaseInfo.h"
#include "XFormXinorbisDialog.h"

#include "ConstantsGui.h"
#include "FormDetails.h"
#include "GridUtility.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "SaveDialogs.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "Utility.h"
#include "WindowsUtility.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;
extern SystemGlobal *GSystemGlobal;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm19 *Form19;
//---------------------------------------------------------------------------
__fastcall TForm19::TForm19(TComponent* Owner)
	: TForm(Owner)
{
}


void OpenDatabaseInformation()
{
	Form19 = new TForm19(Application);

	Form19->ShowModal();

	delete Form19;
}


void __fastcall TForm19::FormResize(TObject *Sender)
{
	int total = sgDatabase->ColWidths[0];

	for (int t = 1; t < 6; t++)
	{
		if (sgDatabase->ColWidths[t] != -1)
		{
			total += sgDatabase->ColWidths[t];
		}
	}

	sgDatabase->ColWidths[1] = sgDatabase->Width - (total + __WidthOfScrollbar);
}


void __fastcall TForm19::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormDetails fd(kFormInfoDatabase, Left, Top, Width, Height);

	GSettingsHandler->SaveFormDetails(fd);

	Action = caFree;
}


/*
const
  CColumnDateTime  = 120;
  CColumnTableName = 350;
  CColumnPCName    = 99;

  procedure TfrmDatabaseInfo.FormCreate(Sender: TObject);
 var
  fd : TFormDetails;

 begin
  sgDatabase.Cells[0, 0] := XText[rsComputer];
  sgDatabase.Cells[1, 0] := XText[rsFolder];
  sgDatabase.Cells[2, 0] := XText[rsDateTime];
  sgDatabase.Cells[3, 0] := XText[rsTableName];

  sgDatabase.HideColumns(3, 5);

  bCancel.Caption := XText[rsCancel];
  bSave.Caption   := XText[rsSave];

  lSize.Caption   := XText[rsSize];
  lTables.Caption := XText[rsTables];

  // ===========================================================================

  fd := XSettings.LoadFormDetails(_FormInfoDatabase);

  if fd.formID <> -1 then begin
    Left             := fd.x;
    Top              := fd.y;
	Width            := fd.w;
	Height           := fd.h;
  end;

  // ===========================================================================

  sgDatabaseResize(Nil);
end;


procedure TfrmDatabaseInfo.FormShow(Sender: TObject);
 var
  tsl : TStringList;
  t : integer;
  ttd, oldttd : TTableDetails;
  tf: file of Byte;
  lDBSize : int64;

 begin
  Caption               := XText[rsFileHistoryDBInfo];
  sbShowNames.Caption   := XText[rsShowNames];
  sbDeleteTable.Caption := XText[rsDelete];

  sgDatabase.ClearRows(1, sgDatabase.RowCount - 1);
  sgDatabase.RowCount   := 2;

  if XSettings.Database.UseODBC then begin
    lDatabaseSize.HTMLText[0] := '<i>' + XText[rsUnknown] + '</i>';
  end
  else begin
    lDBSize := 0;

    if FileExists(GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db') then begin
      AssignFile(tf, GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');
      {$I-}
      Reset(tf);

      if IOResult <> 0 then begin

      end
	  else begin
		lDBSize := FileSize(tf);
        CloseFile(tf);
      end;
      {$I+}
    end;

    if lDBSize <> 0 then begin
      // ===========================================================================

      tsl := GetAllAvailableTables;
      tsl.Sort;

      lTableCount.HTMLText[0] := '<b>' + IntToStr(tsl.Count) + '</b>';

      for t := 0 to tsl.Count - 1 do begin
        ttd := TConvert.SplitTableName(tsl.Strings[t]);

        if (ttd.Date = oldttd.Date) and (ttd.Time = oldttd.Time) and (ttd.Computer = oldttd.Computer + 'F') then begin
          sgDatabase.Cells[5, t]     := '1.1';
          sgDatabase.Cells[5, t + 1] := '1.1';

          sgDatabase.Cells[0, t + 1] := oldttd.Computer;
        end
        else begin
          sgDatabase.Cells[5, t + 1] := '1.0';
          sgDatabase.Cells[0, t + 1] := ttd.Computer;
        end;

        sgDatabase.Cells[1, t + 1] := ttd.Path;
        sgDatabase.Cells[2, t + 1] := ttd.DateYYYYMMDD + '  ' + ttd.TimeHHMMSS;
        sgDatabase.Cells[3, t + 1] := tsl.Strings[t];

        sgDatabase.Cells[4, t + 1] := ttd.Date + ttd.Time;

        sgDatabase.RowCount := sgDatabase.RowCount + 1;

        oldttd := ttd;
      end;

	  sgDatabase.RowCount := sgDatabase.RowCount - 1;
	end
    else begin
      sgDatabase.Cells[0, 1] := XText[rsDatabaseIsEmpty];

      sbShowNames.Enabled   := False;
      sbDeleteTable.Enabled := False;
      bSave.Enabled         := False;
      bExportCSV.Enabled    := False;
      bExportXML.Enabled    := False;
    end;

    lDatabaseSize.HTMLText[0] := '<b>' + TConvert.ConvertToUsefulUnit(lDBSize) + '</b> (<b>' + IntToStr(lDBSize) + '</b> ' + XText[rsBytes] + ')';
  end;
end;











procedure TfrmDatabaseInfo.sgDatabaseClick(Sender: TObject);
 begin
  bExportCSV.Enabled := True;
  bExportXML.Enabled := True;
end;


procedure TfrmDatabaseInfo.sgDatabaseGetCellColor(Sender: TObject; ARow,
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
end;

end.*/
void __fastcall TForm19::sbShowNamesClick(TObject *Sender)
{
	if (sgDatabase->ColWidths[3] == -1)
	{
		sgDatabase->ColWidths[3] = InfoWidths[3];

		sbShowNames->Caption = GLanguageHandler->Text[kHideNames].c_str();
	}
	else
	{
		sgDatabase->ColWidths[3] = -1;

		sbShowNames->Caption = GLanguageHandler->Text[kShowNames].c_str();
	}

	FormResize(NULL);
}


void __fastcall TForm19::sbDeleteTableClick(TObject *Sender)
{                                        /* to do
	if (sgDatabase->Selection.Top > 0)
	{
		if (MessageDlg(GLanguageHandler->Text[kDeleteFHAreYouSure].c_str(), mtWarning, mbYesNo], 0) == mrYes)
		{
			bExportCSV.Enabled := False;
			bExportXML.Enabled := False;

			DeleteTable(sgDatabase.Cells[3, sgDatabase.Selection.Top]);
			DeleteFromDatabaseXFH(GSystemGlobal.AppDataPath + 'FolderHistory\' +
									sgDatabase.Cells[0, sgDatabase.Selection.Top] + '\' +
									TMD5.Generate(UpperCase(sgDatabase.Cells[1, sgDatabase.Selection.Top])) + '.xfh',
									sgDatabase.Cells[4, sgDatabase.Selection.Top]);

			sgDatabase.RemoveRows(sgDatabase.Selection.Top, 1);
		}
	}          */
}


void __fastcall TForm19::bSaveClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kXFileList] + L" (*.txt)|*.txt",
												  L".txt",
												  Utility::GetDefaultFileName(L".txt", L"database_info"),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{
		GridUtility::SaveGrid(sgDatabase, file_name);
	}
}


void __fastcall TForm19::bExportCSVClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kCSVFiles] + L" (*.csv)|*.csv",
												  L".csv",
												  Utility::GetDefaultFileName(L".csv", L"database_info"),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{  /* to do when database folder history implemented...
		if (!ExportTableToCSV(file_name, sgDatabase->Cells[3][sgDatabase->Selection.Top].c_str()))
		{
			ShowXDialog(GLanguageHandler->Text[kErrorSavingReport] + L" (CSV)",
						GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
						XDialogTypeWarning);
		} */
	}
}


void __fastcall TForm19::bExportXMLClick(TObject *Sender)
{
	std::wstring file_name = SaveDialogs::Execute(GLanguageHandler->Text[kXMLFiles] + L" (*.xml)|*.xml",
												  L".xml",
												  Utility::GetDefaultFileName(L".xml", L"database_info"),
												  GSystemGlobal->AppDataPath);

	if (!file_name.empty())
	{          /* to do when database folder history implemented...
		if (!ExportTableToXML(file_name, sgDatabase->Cells[3][sgDatabase->Selection.Top].c_str()))
		{
			ShowXDialog(GLanguageHandler->Text[kkErrorSavingReport] + L" (XML)",
						GLanguageHandler->Text[kErrorSaving] + L" \"" + file_name + L"\".",
						XDialogTypeWarning);
		}       */
	}
}


void __fastcall TForm19::BitBtn1Click(TObject *Sender)
{
	WindowsUtility::ExecuteFile(L"http://xinorbis.co.uk/xdatabase/X.Database32.zip", L"");
}


void __fastcall TForm19::sbSearchClick(TObject *Sender)
{
	HelpHandler::OpenHelpPage(L"dbinfo.htm");
}


void __fastcall TForm19::Image1Click(TObject *Sender)
{
	/*Windows.ExecuteFile(0, '"' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\' + '"', '', ''); */
}


void TForm19::DeleteFromDatabaseXFH(const std::wstring file_name, const std::wstring date)
{/*
 var
  tf : textfile;
  bob : TStringList;
  t : integer;
  canwrite : boolean;

 begin
  if FileExists(filename) then begin
	bob := TStringList.Create;
	bob.LoadFromFile(filename);

	AssignFile(tf, filename);
	{$I-}
	Rewrite(tf);
	{$I+}

    if IOResult <> 0 then begin
	  ShowXDialog(L"Error writing to database",
                  TLanguageHandler.FillParameter(rsCannotFindFileParam, filename),
                  XDialogTypeWarning);
    end
    else begin
      Writeln(tf, bob.strings[0]);

      canwrite := false;

      for t := 1 to bob.Count - 1 do begin
        if bob.strings[t] <> '' then begin
          if bob.strings[t][1] = '{' then begin
            if Copy(bob.strings[t + 2], 5, 14) = date then begin
              canwrite := False
            end
            else begin
              canwrite := True;

              Writeln(tf, '{');
            end;
          end
          else begin
			if canwrite then
			  Writeln(tf, bob.strings[t]);
		  end;
		end;
	  end;

	  CloseFile(tf);
	end;

	bob.Free;
  end
  else
	ShowXDialog(L"Error locating database",
				TLanguageHandler.FillParameter(rsCannotFindFileParam, filename),
				XDialogTypeWarning);*/
}

