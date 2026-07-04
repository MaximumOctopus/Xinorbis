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

#include "ScanEngine.h"
#include "TabUiUsers.h"

extern ScanEngine* GScanEngine;


void TabUiUsers::Chart(TChart* chart)
{/*
class procedure TDisplayUtility.InformationTabUsersGraph(aDataIndex : integer; oChart : TChart);
 var
  t : integer;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabUsersGraph :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabUsersGraph : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].FileCount) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

	if (GScanDetails[aDataIndex].FileCount > 0)
	{
		oChart.SeriesList.Items[0].Clear;
		oChart.Legend.TextStyle := ltsPlain;

		if oChart.Tag = 1)
		{
			oChart.Title.Text.Strings[0] := XText[kQuantityFilesUser]
		}
		else
		{
			oChart.Title.Text.Strings[0] := XText[kSizeFilesUser];
		}

		for t := 0 to GScanDetails[aDataIndex].Users.Count - 1; )
		{
			if oChart.Tag = 1)
			{
				oChart.SeriesList.Items[0].Add(GScanDetails[aDataIndex].Users[t].Data[XUserCount], GScanDetails[aDataIndex].Users[t].Name, spectrumcolours[t mod spectrummod])
			}
			else
			{
				if GScanDetails[aDataIndex].TotalSize <> 0)
				{
					oChart.SeriesList.Items[0].Add(GScanDetails[aDataIndex].Users[t].Data[XUserSize] /GScanDetails[aDataIndex].TotalSize, GScanDetails[aDataIndex].Users[t].Name, spectrumcolours[t mod spectrummod])
				}
				else
				{
					oChart.SeriesList.Items[0].Add(100, GScanDetails[aDataIndex].Users[t].Name, spectrumcolours[t mod spectrummod]);
				}
			}
		}
	}
 */
}


void TabUiUsers::Table(TStringGrid* grid, int display_mode)
{ /*
class procedure TDisplayUtility.InformationTabUsersTable(aDataIndex : integer; oDisplayMode : integer; oTable : TAdvStringGrid);
 var
  t : integer;
  xCount, xSize : Int64;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabUsersTable :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabUsersTable : ' + IntToStr(aDataIndex) + '/' + IntToStr(GScanDetails[aDataIndex].Users.Count) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count)+ '/' + IntToStr(GScanDetails[aDataIndex].FileCount));

  if XSettings.Forms.ProgressForm <> Nil then
	XSettings.Forms.ProgressForm.SetProcessText(XText[kBuilding] + ' ' + XText[kUserDetails]);

  grid.ClearRows(1, oTable.RowCount - 1);
  grid.RowCount := 2;

  grid.BeginUpdate;

	if GScanDetails[aDataIndex].Users.Count <> 0)
	{
		grid.RowCount := GScanDetails[aDataIndex].Users.Count + 1;

		for t := 0 to GScanDetails[aDataIndex].Users.Count - 1)
		{
			case oDisplayMode of
			CDisplayModeShowAll : begin
									xCount := GScanDetails[aDataIndex].Users[t].Data[XUserCount];
									xSize  := GScanDetails[aDataIndex].Users[t].Data[XUserSize];
								  end;
			else
			xCount := GScanDetails[aDataIndex].Users[t].CategoryDataQty[oDisplayMode];
			xSize  := GScanDetails[aDataIndex].Users[t].CategoryDataSize[oDisplayMode];
			end;

			grid.Cells[CUsersTableName,  t + 1] := GScanDetails[aDataIndex].Users[t].Name;
			grid.Cells[CUsersTableCount, t + 1] := IntToStr(xCount);

			if GScanDetails[aDataIndex].FileCount<> 0)
			{
				grid.Cells[CUsersTableCountAs,    t + 1] := TConvert.RealToPercent(xCount /GScanDetails[aDataIndex].FileCount);
				grid.Cells[CUsersTableGraphCount, t + 1] := IntToStr(Round((xCount /GScanDetails[aDataIndex].FileCount) * 50));
			}
			else
			{
				grid.Cells[CUsersTableCountAs,    t + 1] := '100%';
				grid.Cells[CUsersTableGraphCount, t + 1] := '50';
			}

			grid.Cells[CUsersTableSize, t + 1] := TConvert.ConvertToUsefulUnit(xSize);

			if GScanDetails[aDataIndex].TotalSize <> 0)
			{
				grid.Cells[CUsersTableSizeAs,    t + 1] := TConvert.RealToPercent(xSize /GScanDetails[aDataIndex].TotalSize);
				grid.Cells[CUsersTableGraphSize, t + 1] := IntToStr(Round((xSize /GScanDetails[aDataIndex].TotalSize) * 50));
			}
			else
			{
				grid.Cells[CUsersTableSizeAs,    t + 1] := '100%';
				grid.Cells[CUsersTableGraphSize, t + 1] := '50';
			}

			grid.Cells[CUsersTableSortSize, t + 1] := IntToStr(xSize);
		}

		DoTableSort(oTable, oTable.SortSettings.Column, UsersSortColumns[oTable.SortSettings.Column]);
	}
	else
	{
		grid.RowCount                  := 2;
		grid.Cells[CUsersTableName, 1] := XText[kNoneFound];
    }

	table.EndUpdate; */
}




