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
#include "TabUiHistory.h"

extern ScanEngine* GScanEngine;


std::wstring TabUiHistory::Chart(TChart* chart, std::vector<std::wstring> &search_strings, int UserId,
								 TDateTime date_from, TDateTime date_to,
								 int interval, int date_selectm, bool quantity, bool cumulative,
								 std::wstring interval_caption)
{
/* TO DO var
  t, x, iFromDate, iToDate, iFileDate, currentdate, hcount, : integer;
  hsize, HistoryTotalSize : int64;
  HistoryTotalCount : integer;
  xfo : TFileObject;
  xtitle,s,s2 : string;
  haschanged : boolean;
  dtcurrentdate : TDateTime;
  HoursC : array[0..23] of integer;
  HoursS : array[0..23] of int64;
  lCapacityItem : TCapacityItem;
  lNewData : boolean;

  procedure AddBar;
   var
    ss : string;

   begin
    ss := IntToStr(currentdate);

	switch (Interval)
	{
	case kIntervalDay   : begin
						 xtitle := ss[7] + ss[8] + '/' + ss[5] + ss[6];

						 hgData.Add('(date=' + ss + ')');
					   end;
	case kIntervalWeek  : begin
						 xtitle := IntToStr(WeekOf(dtcurrentdate)) + '/' + ss[3] + ss[4];

						 hgData.Add('(week:' + IntToStr(WeekOf(dtcurrentdate)) + ':' + ss[3] + ss[4] + ')');
					   end;
	case kIntervalMonth : begin
						 xtitle := ss[5] + ss[6] + '/' + ss[3] + ss[4];

						 hgData.Add('(date>' + ss[1] + ss[2] + ss[3] + ss[4 ] +ss[5] + ss[6] + '01) (date<' + ss[1] + ss[2] + ss[3] + ss[4] + ss[5] + ss[6] + '31)');
					   end;
	case kIntervalYear  : begin
						 xtitle :=ss[1] + ss[2] + ss[3] + ss[4];

						 hgData.Add('(date>' + ss[1] + ss[2] + ss[3] + ss[4] + '0101) (date<' + ss[1] + ss[2] + ss[3] + ss[4] + '1231)');
					   end;
    }

	if hQuantity then
	  oChart.SeriesList.Items[0].Add(hcount, xtitle, spectrumcolours[x mod spectrummod])
	else
	  oChart.SeriesList.Items[0].Add(hsize, xtitle, spectrumcolours[x mod spectrummod]);

	inc(x);
  end;

  procedure AddHourBar(const xfrom, xto : string; idx, xcount : integer; xsize : int64);
   begin
	xtitle := xfrom;

    case hInterval of
      CIntervalHour : begin
                        hgData.Add('(time>' + xfrom + ') (time<' + xto + ')');
                      end;
    end;

    if hQuantity then
	  oChart.SeriesList.Items[0].Add(xcount, xtitle, spectrumcolours[idx mod spectrummod])
	else
      oChart.SeriesList.Items[0].Add(xsize, xtitle, spectrumcolours[idx mod spectrummod]);
  end;

  function IntegerDateToDate(i : integer): TDateTime;
   var
    s : string;

   begin
    s := IntToStr(i);

    try
      Result := EncodeDate(StrToInt(s[1] + s[2] + s[3] + s[4]), StrToInt(s[5] + s[6]), StrToInt(s[7] + s[8]))
    except
      Result := EncodeDate(1990, 01, 01);

      TMSLogger.Error('Invalid data: ' + IntToStr(i));
    end;
  end;

 begin
  Assert((aDataIndex >= 0) and (aDataIndex <= 2), 'InformationTabHistoryGraph :: invalid dataindex :: ' + inttostr(aDataIndex));

  if XSettings.System.Debug then TMSLogger.Info('InformationTabHistoryGraph : ' + IntToStr(aDataIndex) + '/' + IntToStr(user.ItemIndex) + '/' + IntToStr(GScanDetails[aDataIndex].Files.Count));

	if (hInterval <= CIntervalYear) then begin
	case hDateSelect of
	  CCreatedDate  : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
	  CAccessedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
	  CModifiedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
	end;
	end;

	for t := 0 to 23 do begin
	HoursC[t] := 0;
	HoursS[t] := 0;
	end;

	for t := 1 to __FileCategoriesCount do begin // clear data
	ExtSpreadHistory[t, 1] := 0;
	ExtSpreadHistory[t, 2] := 0;
	end;

	oChart.SeriesList.Items[0].Clear;

	hgData.Clear;

	currentdate   := 19000001;
	iFileDate     := 19000001;
	dtcurrentdate := IncDay(Now, 1);

	hcount            := 0;
	hsize             := 0;
	HistoryTotalSize  := 0;
	HistoryTotalCount := 0;
	x                 := 0;
	lNewData          := False;

	iFromDate         := TConvert.DateTimeToInteger(fromDate);
	iToDate           := TConvert.DateTimeToInteger(toDate);

	// ===========================================================================
	switch (hDateSelect)
	{
	case kCreatedDate:
		oChart.Title.Text.Strings[0] := XText[kFileCreationHistory]        + ' ' +
										XText[kFrom]                       + ' ' +
										TConvert.DateToString(fromDate)     + ' ' +
										XText[kTo]                         + ' ' +
										TConvert.DateToString(toDate);
		break;
	case kAccessedDate:
		oChart.Title.Text.Strings[0] := XText[kFileAccessHistory]          + ' ' +
										XText[kFrom]                       + ' ' +
										TConvert.DateToString(fromDate)     + ' ' +
										XText[kTo]                         + ' ' +
										TConvert.DateToString(toDate);
		break;
	case kModifiedDate:
		oChart.Title.Text.Strings[0] := XText[kFileModificationHistory]    + ' ' +
										XText[kFrom]                       + ' ' +
										TConvert.DateToString(fromDate)     + ' ' +
										XText[kTo]                         + ' ' +
										TConvert.DateToString(toDate);
		break;
	}

	switch (hInterval)
	{
	case kIntervalDay:
		oChart.BottomAxis.Title.Caption := XText[kDayMonth];
		break;
	case kIntervalWeek:
		oChart.BottomAxis.Title.Caption := XText[kWeekYear];
		break;
	case kIntervalMonth:
		oChart.BottomAxis.Title.Caption := XText[kMonthYear];
		break;
	case kIntervalYear:
		oChart.BottomAxis.Title.Caption := XText[kYear];
		break;
	case kIntervalHour:
		oChart.BottomAxis.Title.Caption := hIntervalCaption;
		break;

	default:
		oChart.BottomAxis.Title.Caption := XText[kDayMonth];
	//showmessage(inttostr(hinterval));
	}

	if (quantity)
	{
		oChart.LeftAxis.Title.Caption := XText[kQuantity]
	}
	else
	{
		oChart.LeftAxis.Title.Caption := XText[kSize] + ' (' + XText[kXBytes] + ')';
	}

	// ===========================================================================

	if (hInterval <= CIntervalYear)
	{
		for t := 0 to GScanDetails[aDataIndex].Files.Count - 1; t++)
		{
			xfo := GScanDetails[aDataIndex].Files.Items[t];

			switch (DateSelect)
			{
			case kCreatedDate:
				iFileDate := xfo.FileDateC;
				break;
			case kAccessedDate:
				iFileDate := xfo.FileDateA;
				break;
			case kModifiedDate:
				iFileDate := xfo.FileDateM;
				break;
			}

			if (iFileDate >= iFromDate) and (iFileDate <= iToDate)
			{
				if ((faDirectory and xfo.Attributes) <> faDirectory)
				{
				switch hInterval of
				CIntervalDay   : haschanged := (iFileDate <> currentdate);
				CIntervalWeek  : haschanged := (WeekOf(IntegerDateToDate(iFileDate)) <> WeekOf(dtcurrentdate));
				CIntervalMonth : begin
								   s  := IntToStr(currentdate);
								   s2 := IntToStr(iFileDate);

								   haschanged := (s2[5] + s2[6] <> s[5] + s[6]) or (s2[3] + s2[4] <> s[3] + s[4]);
								 end;
				CIntervalYear  : begin
								   s  := IntToStr(currentdate);
								   s2 := IntToStr(iFileDate);

								   haschanged := (s2[1] + s2[2] + s2[3] + s2[4] <> s[1] + s[2] + s[3] + s[4]);
								 end;
				default:
					haschanged := False;
				}

			  // ===================================================================

			  if userid <> -1 then begin
				if xfo.Owner <> userid then
				  haschanged := False;
			  end;

			  // ===================================================================

			  if haschanged then begin
				if currentdate <> 19000001 then
				  AddBar;

				currentdate := iFileDate;

				if hInterval = CIntervalWeek then
				  dtcurrentdate := IntegerDateToDate(iFileDate);

				if not(hCumulative) then begin
				  hcount := 0;
				  hsize  := 0;
				end;

				lNewData := True;
			  end;

			  inc(hcount);
			  inc(hsize, xfo.FileSize);

			  inc(HistoryTotalCount);
			  inc(HistoryTotalSize, xfo.FileSize);

			  inc(ExtSpreadHistory[xfo.FileCategory, 1]);
			  inc(ExtSpreadHistory[xfo.FileCategory, 2], xfo.FileSize);

			  case hInterval
			  {
				CIntervalDay   :  if (t = GScanDetails[aDataIndex].Files.Count - 1) then begin
									AddBar;

									lNewData := False;
								  end;
				CIntervalWeek  :  if (t = GScanDetails[aDataIndex].Files.Count - 1) then begin
									AddBar;

									lNewData := False;
								  end;
				CIntervalMonth :  if (t = GScanDetails[aDataIndex].Files.Count - 1) then begin
									AddBar;

									lNewData := False;
								  end;
				CIntervalYear  :  if (t = GScanDetails[aDataIndex].Files.Count - 1) then begin
									AddBar;

									lNewData := False;
								  end;

			}
			end;
		  end;
		end;

		if (lNewData) and (hCount <> 0) then begin
		  case hInterval of
			CIntervalDay..CIntervalYear : AddBar;
		  end;
		end;
	}
	else
	{
		for t := 0 to GScanDetails[aDataIndex].Files.Count - 1; t++)
		{
			xfo := GScanDetails[aDataIndex].Files.Items[t];

			if (hDateSelect = 0)
			{
				iFileDate := xfo.FileDateC
			}
			else if (hDateSelect = 1)
			{
				iFileDate := xfo.FileDateA
			}
			else
			{
				iFileDate := xfo.FileDateM;
			}

			if (iFileDate >= iFromDate) and (iFileDate <= iToDate)
			{
				if ((faDirectory and xfo.Attributes) = 0)
				{
					switch (Interval)
					{
					case kIntervalHour:
					{
						s := IntToStr(iFileDate);

						if length(s) = 3 then s := '0' + s;
						if length(s) = 2 then s := '00' + s;

						x := StrToInt(Copy(s, 1, 2));

						inc(HoursC[x]);
						inc(HoursS[x], xfo.FileSize);

						inc(HistoryTotalCount);
						inc(HistoryTotalSize, xfo.FileSize);

						inc(ExtSpreadHistory[xfo.FileCategory, 1]);
						inc(ExtSpreadHistory[xfo.FileCategory, 2], xfo.FileSize);
						break;
					}
					}
				}
			}
		}

		for (int t = 0; t < 24; t++)
		{
			std::wstring s = L"";
			std::wstring s2 = L"";

			if (t < 10)
			{
				s = L"0" + std::to_wstring(t);
			}
			else
			{
				s = std::to_wstring(t);
			}

			s = s + L"00";
			s2 = s + L"59";

			AddHourBar(s, s2, t, HoursC[t], HoursS[t]);
		}
	}

	// ===========================================================================

	if oCapacityBar <> Nil then begin

	oCapacityBar.Items.Clear;

	for t := 1 to __FileCategoriesCount do begin
	  if hQuantity then begin
		if HistoryTotalCount <> 0 then begin
		  if ExtSpreadHistory[t, 1] <> 0 then begin
			lCapacityItem             := oCapacityBar.Items.Add;
			lCapacityItem.Value       := (ExtSpreadHistory[t, 1] / HistoryTotalCount) * 100;
			lCapacityItem.Color       := GSystemGlobal.FileCategoryColors[t];
			lCapacityItem.ColorTo     := GSystemGlobal.FileCategoryColors[t];
			lCapacityItem.DisplayName := TypeDescriptions[t];
			lCapacityItem.Description := TypeDescriptions[t];
			lCapacityItem.Hint        := TypeDescriptions[t] + ' (' + IntToStr(ExtSpreadHistory[t, 1]) + ' files)';
		  end;
		end;
	  end
	  else begin
		if HistoryTotalSize <> 0 then begin
		  if ExtSpreadHistory[t, 2] <> 0 then begin
			lCapacityItem             := oCapacityBar.Items.Add;
			lCapacityItem.Value       := (ExtSpreadHistory[t, 2] / HistoryTotalSize) * 100;
			lCapacityItem.Color       := GSystemGlobal.FileCategoryColors[t];
			lCapacityItem.ColorTo     := GSystemGlobal.FileCategoryColors[t];
			lCapacityItem.DisplayName := TypeDescriptions[t];
			lCapacityItem.Description := TypeDescriptions[t];
			lCapacityItem.Hint        := TypeDescriptions[t] + ' (' + TConvert.ConvertToUsefulUnit(ExtSpreadHistory[t, 2]) + ')';
		  end;
		end;
	  end;
	end;
	end;

	Result := XText[kFound] + ' <b>' + IntToStr(HistoryTotalCount) + '</b> ' + XText[kFiles] + '    ' + XText[kSize] + ' : <b>' + TConvert.ConvertToUsefulUnit(HistoryTotalSize) + '</b>';

	// ===========================================================================

	if hInterval <= CIntervalYear then begin
		case hDateSelect of
		CCreatedDate  : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
		CAccessedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
		CModifiedDate : GScanDetails[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
		end;
	end;  */
}
