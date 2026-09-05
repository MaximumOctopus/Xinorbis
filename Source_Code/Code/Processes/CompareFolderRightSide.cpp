// =====================================================================
//
//   Xinorbis 10.0
//
// (c) Paul Alan Freshney 2002-2026
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/Xinorbis
//
// =====================================================================

#include "CompareFolderRightSide.h"


void CompareFolderRightSide::Execute()
{
/*  t        : integer;
  addrow   : boolean;

	if XSettings.Database.UseODBC)
	{
		if InitODBC(XSettings.Database.ODBConnectionString)
		{
		}
		else
		{
			Exit;
        }
	}

	for t := 0 to __FileCategoriesCount)
	{
		extspreadt[t, 1] := 0;
		extspreadt[t, 2] := 0;
	}

	tnumfiless             := 0;
	tFileTotalSpace        := 0;
	tnumfiless_folder      := 0;
	tFileTotalSpace_folder := 0;

	// =========================================================================
	// =========================================================================
	// =========================================================================

	grid.BeginUpdate;

	grid.ClearRows(1, grid.RowCount - 2);
	grid.BeginUpdate;
	grid.RowCount := 2;

	CompareData[XLeftSide].Data[XFileCount]   := 0;
	CompareData[XLeftSide].Data[XFolderCount] := 0;
	CompareData[XLeftSide].Data[XFileSize]    := 0;

	if XSettings.Database.UseODBC)
	{
		ProcessODBC(SQL);
	}
	else
	{
		ProcessSqlite(SQL);
	}

	t := 1;

	while t <= __FileCategoriesCount)
	{
		addrow := True;

		if addrow
		{
			grid.Cells[1, grid.RowCount - 1] := TypeDescriptions[t];
			grid.Cells[2, grid.RowCount - 1] := IntToStr(extspreadt[t, 1]);

			if tnumfiless <> 0)
			{
				grid.Cells[3, grid.RowCount - 1] := TConvert.RealToPercent(extspreadt[t, 1] / tnumfiless);
				grid.Cells[9, grid.RowCount - 1] := IntToStr(Round((extspreadt[t, 1] / tnumfiless) * 50));
			}
			else
			{
				grid.Cells[3, grid.RowCount - 1] := '100%';
				grid.Cells[9, grid.RowCount - 1] := '100';
			}

			grid.Cells[5, grid.RowCount - 1] := TConvert.ConvertToUsefulUnit(extspreadt[t, 2]);

			if tFileTotalSpace <> 0)
			{
				grid.Cells[6, grid.RowCount - 1]  := TConvert.RealToPercent(extspreadt[t, 2] / tFileTotalSpace);
				grid.Cells[10, grid.RowCount - 1] := IntToStr(Round((extspreadt[t, 2] / tFileTotalSpace) * 50))
			}
			else
			{
				grid.Cells[6, grid.RowCount - 1]  := '100%';
				grid.Cells[10, grid.RowCount - 1] := '100';
			}

			grid.Cells[7, grid.RowCount - 1]  := IntToStr(t);
			grid.Cells[8, grid.RowCount - 1]  := IntToStr(extspreadt[t, 2]);

			grid.RowCount := grid.RowCount + 1;
		}

		inc(t);
	}

	slabel.Caption := IntToStr(tnumfiless_folder) +
					' (<b>' + TConvert.ConvertToUsefulUnit(tFileTotalSpace_folder) + '</b>) of ' + IntToStr(tnumfiless) + ' (<b>' + TConvert.ConvertToUsefulUnit(tFileTotalSpace) + '</b>)';

	grid.RowCount  := grid.RowCount - 1;

	// =========================================================================
	// =========================================================================
	// =========================================================================

	grid.EndUpdate;

	if XSettings.Database.UseODBC)
	{
		CloseODBC;
	}*/
}


void CompareFolderRightSide::SetData(const std::wstring s, const std::wstring o1, bool o2, TStringGrid* gridx)
{
//procedure TCompareFolderLeftThread.SetData(const s : string; o1 : string; o2 : THTMLabel; gridx : TAdvStringGrid);
	SQL = s;
//	Folder = L"\\" + UpperCase(o1) + L"\\";
//  slabel := o2;
  	grid  = gridx;
}


void CompareFolderRightSide::ProcessODBC(const std::wstring sql)
{
/*  XQuery   : TADOQuery;

	XQuery := TADOQuery.Create(nil);

	try
		XQuery.Connection := XODBC;
		XQuery.SQL.Add(sql);
		XQuery.Open;

		while not XQuery.eof)
		{
			if XQuery.FieldByname('Directory').AsString <> '1')
			{
				if Pos(folder, UpperCase(XQuery.FieldByName('FilePath').AsString)) <> 0)
				{
					inc(extspreadt[XQuery.FieldByname('Category').AsInteger, 1]);
					inc(extspreadt[XQuery.FieldByname('Category').AsInteger, 2], StrToInt64(XQuery.FieldByName('FileSize').AsString));

					inc(tnumfiless_folder);
					inc(tFileTotalSpace_folder, StrToInt64(XQuery.FieldByName('FileSize').AsString));
				}

				inc(tnumfiless);
				inc(tFileTotalSpace, StrToInt64(XQuery.FieldByName('FileSize').AsString));
			}

		  XQuery.Next;
	}
	catch(...)
	{
	}

	XQuery.Free;*/
}


void CompareFolderRightSide::ProcessSqlite(const std::wstring sql)
{
/*  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;

	lSQliteConnection := TSQLConnection.Create(Nil);

	lSQliteConnection.DriverName  := 'Sqlite';
	lSQliteConnection.LoginPrompt := False;
	lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

	try
	{
		lSQliteConnection.Connected := True;

		lSQliteConnection.Execute(aSQL, nil, lResults);

		if not lResults.IsEmpty)
		{
			lResults.First;

			while not lResults.Eof)
			{
				if lResults.Fields[fDirectory].AsString <> '1')
				{
					if Pos(folder, UpperCase(lResults.Fields[fFilePath].AsString)) <> 0)
					{
						inc(extspreadt[lResults.Fields[fCategory].AsInteger, 1]);
						inc(extspreadt[lResults.Fields[fCategory].AsInteger, 2], lResults.Fields[fFileSize].AsLargeInt);

						inc(tnumfiless_folder);
						inc(tFileTotalSpace_folder, lResults.Fields[fFileSize].AsLargeInt);
					}

					inc(tnumfiless);
					inc(tFileTotalSpace, lResults.Fields[fFileSize].AsLargeInt);
				}

				lResults.Next;
			}
		}
	}
	catch(...)
	{
	}

	lSQliteConnection.Connected := False;
	FreeAndNil(lSQliteConnection); */
}


// =================================================================================================
// == ODBC Specific ================================================================================
// =================================================================================================


bool CompareFolderRightSide::InitODBC(const std::wstring connection_string)
{
/*  try
	{
		XODBC := TADOConnection.Create(nil);
		XODBC.LoginPrompt      := False;
		XODBC.ConnectionString := connectionstring;
		XODBC.Connected        := True;
	}
	catch(...)
	{
		return false;
	}*/

	return true;
}


void CompareFolderRightSide::CloseODBC()
{
/* if XODBC.Connected then
	XODBC.Close;

  XODBC.Free;*/
}
