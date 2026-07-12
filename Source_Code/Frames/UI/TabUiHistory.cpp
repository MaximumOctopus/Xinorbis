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

#include <System.SysUtils.hpp>
#include <System.DateUtils.hpp>

#include "Convert.h"
#include "DateUtility.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "SettingsHandler.h"
#include "TabUiHistory.h"

extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;
extern SettingsHandler* GSettingsHandler;


int TabUiHistory::AddBar(TChart* chart, std::vector<std::wstring> &search_strings, TDateTime dtcurrent_date, int interval, bool quantity, int count, unsigned __int64 size, int current_date, int colour_mod)
{
	std::wstring ss = std::to_wstring(current_date);

	std::wstring title = L"";

	switch (interval)
	{
	case kIntervalDay:
		title = ss.substr(6, 2) + L"//" + ss.substr(4, 2);

		search_strings.push_back(L"(date=" + ss + L")");
		break;
	case kIntervalWeek:
		title = std::to_wstring(WeekOf(dtcurrent_date)) + L"/" + ss.substr(2, 2);
		search_strings.push_back(L"(week:" + std::to_wstring(WeekOf(dtcurrent_date)) + L":" + ss.substr(2, 2) + L")");
		break;
	case kIntervalMonth:
	{
		title = ss.substr(4, 2) + L"//" + ss.substr(2, 2);

		search_strings.push_back(L"(date>" + ss.substr(0, 6) + L"01) (date<" + ss.substr(0, 6) + L"31)");
		break;
	}
	case kIntervalYear:
		title = ss.substr(0, 4);

		search_strings.push_back(L"(date>" + title + L"0101) (date<" + title + L"1231)");
		break;
	}

	if (quantity)
	{
		chart->SeriesList->Items[0]->Add(count, title.c_str(), TColor(__SpectrumColours[colour_mod % __SpectrumMod]));
	}
	else
	{
		chart->SeriesList->Items[0]->Add(size, title.c_str(), TColor(__SpectrumColours[colour_mod % __SpectrumMod]));
	}

	return ++colour_mod;
}


int TabUiHistory::AddHourBar(TChart* chart, std::vector<std::wstring> &search_strings, int interval, bool quantity,
							 const std::wstring xfrom, const std::wstring xto, int count, int __int64 size, int colour_mod)
{
	std::wstring title = xfrom;

	switch (interval)
	{
	case kIntervalHour:
		search_strings.push_back(L"(time>" + xfrom + L") (time<" + xto + L")");
		break;
	}

	if (quantity)
	{
		chart->SeriesList->Items[0]->Add(count, title.c_str(), TColor(__SpectrumColours[colour_mod % __SpectrumMod]));
	}
	else
	{
		chart->SeriesList->Items[0]->Add(size, title.c_str(), TColor(__SpectrumColours[colour_mod % __SpectrumMod]));
	}

	return ++colour_mod;
}


std::wstring TabUiHistory::Chart(TChart* chart, std::vector<std::wstring> &search_strings, int user_id,
								 TDateTime date_from, TDateTime date_to,
								 int interval, int date_select, bool quantity, bool cumulative,
								 std::wstring interval_caption)
{
	if (interval <= kIntervalYear)
	{
//		switch (date_select)
//		{                   TO DO TO DO TO Do
//		CCreatedDate  : GScanEngine->[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
//		CAccessedDate : GScanEngine->[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
//		CModifiedDate : GScanEngine->[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
//		}
	}

	unsigned __int64 ExtSpreadHistory[__FileCategoriesCount][2];
	unsigned __int64 ExtSpreadDates[__FileCategoriesCount][2];

	int HoursC[24];
	int HoursS[24];

	for (int t = 0; t < 24; t++)
	{
		HoursC[t] = 0;
		HoursS[t] = 0;
	}

	for (int t = 0; t < __FileCategoriesCount; t++)
	{
		ExtSpreadHistory[t][0] = 0;
		ExtSpreadHistory[t][1] = 0;
	}

	chart->SeriesList->Items[0]->Clear();

	search_strings.clear();

	int current_date   = 19000001;
	int file_date     = 19000001;
	TDateTime dt_current_date = IncDay(Now());

	int count            = 0;
	unsigned __int64 size = 0;
	int HistoryTotalCount = 0;
	unsigned __int64 HistoryTotalSize  = 0;
	int ColourMod = 0;
	bool NewData = false;

    bool has_changed = false;

	int FromDate = Convert::DateToYYYYMMDDI(date_from);
	int ToDate   = Convert::DateToYYYYMMDDI(date_to);

	// ===========================================================================
	switch (date_select)
	{
	case kCreatedDate:
		chart->Title->Text->Strings[0] = (GLanguageHandler->Text[kFileCreationHistory] + L" " +
										 GLanguageHandler->Text[kFrom] + L" " +
										 DateUtility::DateToString(date_from, GSettingsHandler->General.FormatDate) + L" " +
										 GLanguageHandler->Text[kTo] + L" " +
										 DateUtility::DateToString(date_to, GSettingsHandler->General.FormatDate)).c_str();
		break;
	case kAccessedDate:
		chart->Title->Text->Strings[0] = (GLanguageHandler->Text[kFileAccessHistory] + L" " +
										 GLanguageHandler->Text[kFrom] + L" " +
										 DateUtility::DateToString(date_from, GSettingsHandler->General.FormatDate) + L" " +
										 GLanguageHandler->Text[kTo] + L" " +
										 DateUtility::DateToString(date_to, GSettingsHandler->General.FormatDate)).c_str();
		break;
	case kModifiedDate:
		chart->Title->Text->Strings[0] = (GLanguageHandler->Text[kFileModificationHistory] + L" " +
										  GLanguageHandler->Text[kFrom] + L" " +
										  DateUtility::DateToString(date_from, GSettingsHandler->General.FormatDate) + L" " +
										  GLanguageHandler->Text[kTo] + L" " +
										  DateUtility::DateToString(date_to, GSettingsHandler->General.FormatDate)).c_str();
		break;
	}

	switch (interval)
	{
	case kIntervalDay:
		chart->BottomAxis->Title->Caption = GLanguageHandler->Text[kDayMonth].c_str();
		break;
	case kIntervalWeek:
		chart->BottomAxis->Title->Caption = GLanguageHandler->Text[kWeekYear].c_str();
		break;
	case kIntervalMonth:
		chart->BottomAxis->Title->Caption = GLanguageHandler->Text[kMonthYear].c_str();
		break;
	case kIntervalYear:
		chart->BottomAxis->Title->Caption = GLanguageHandler->Text[kYear].c_str();
		break;
	case kIntervalHour:
		chart->BottomAxis->Title->Caption = interval_caption.c_str();
		break;

	default:
		chart->BottomAxis->Title->Caption = GLanguageHandler->Text[kDayMonth].c_str();
	}

	if (quantity)
	{
		chart->LeftAxis->Title->Caption = GLanguageHandler->Text[kQuantity].c_str();
	}
	else
	{
		chart->LeftAxis->Title->Caption = (GLanguageHandler->Text[kSize] + L" (" + GLanguageHandler->Text[kXBytes] + L")").c_str();
	}

	// ===========================================================================

	if (interval <= kIntervalYear)
	{
		for (int f = 0; f < GScanEngine->Data.Files.size(); f++)
		{
			FileObject xfo = GScanEngine->Data.Files[f];

			switch (date_select)
			{
			case kCreatedDate:
				file_date = xfo.DateCreated;
				break;
			case kAccessedDate:
				file_date = xfo.DateAccessed;
				break;
			case kModifiedDate:
				file_date = xfo.DateModified;
				break;
			}

			if (file_date >= FromDate && file_date <= ToDate)
			{
				if (!(faDirectory & xfo.Attributes))
				{
					switch (interval)
					{
					case kIntervalDay:
						has_changed = (file_date != current_date);
						break;
					case kIntervalWeek:
						has_changed = (WeekOf(DateUtility::YYYYMMDDToDate(file_date)) != WeekOf(dt_current_date));
						break;
					case kIntervalMonth:
					{
						std::wstring s  = std::to_wstring(current_date);
						std::wstring s2 = std::to_wstring(file_date);

						has_changed = (s2[5] + s2[6] != s[5] + s[6]) || (s2[3] + s2[4] != s[3] + s[4]);
						break;
					}
					case kIntervalYear:
					{
						std::wstring s  = std::to_wstring(current_date);
						std::wstring s2 = std::to_wstring(file_date);

						has_changed = (s2[1] + s2[2] + s2[3] + s2[4] != s[1] + s[2] + s[3] + s[4]);
						break;
                    }

					default:
						has_changed = false;
						break;
					}

					// ===================================================================

					if (user_id != -1)
					{
						if (xfo.Owner != user_id)
						{
							has_changed = false;
						}
					}

					// ===================================================================

					if (has_changed)
					{
						if (current_date != 19000001)
						{
							ColourMod = AddBar(chart, search_strings, dt_current_date, interval, quantity, count, size, current_date, ColourMod);
                        }

						current_date = file_date;

						if (interval == kIntervalWeek)
						{
							dt_current_date = DateUtility::YYYYMMDDToDate(file_date);
						}

						if (!cumulative)
						{
							count = 0;
							size  = 0;
						}

						NewData = true;
					}

					count++;
					size += xfo.Size;

					HistoryTotalCount++;
					HistoryTotalSize += xfo.Size;

					ExtSpreadHistory[xfo.Category][0]++;
					ExtSpreadHistory[xfo.Category][1] += xfo.Size;

					switch (interval)
					{
					case kIntervalDay:
						if (f == GScanEngine->Data.Files.size() - 1)
						{
							ColourMod = AddBar(chart, search_strings, dt_current_date, interval, quantity, count, size, current_date, ColourMod);

							NewData = false;
						}
						break;
					case kIntervalWeek:
						if (f == GScanEngine->Data.Files.size() - 1)
						{
							ColourMod = AddBar(chart, search_strings, dt_current_date, interval, quantity, count, size, current_date, ColourMod);

							NewData = false;
						}
						break;
					case kIntervalMonth:
						if (f == GScanEngine->Data.Files.size() - 1)
						{
							ColourMod = AddBar(chart, search_strings, dt_current_date, interval, quantity, count, size, current_date, ColourMod);

							NewData = false;
						}
						break;
					case kIntervalYear:
						if (f == GScanEngine->Data.Files.size() - 1)
						{
							ColourMod = AddBar(chart, search_strings, dt_current_date, interval, quantity, count, size, current_date, ColourMod);

							NewData = false;
						}
						break;
					}
				}
			}
		}

		if (NewData && count != 0)
		{
			switch (interval)
			{
			case kIntervalDay:
			case kIntervalWeek:
			case kIntervalMonth:
			case kIntervalYear:
				ColourMod = AddBar(chart, search_strings, dt_current_date, interval, quantity, count, size, current_date, ColourMod);
				break;
			}
		}
	}
	else
	{
		for (FileObject file : GScanEngine->Data.Files)
		{
			if (date_select == 0)
			{
				file_date = file.DateCreated;
			}
			else if (date_select == 1)
			{
				file_date = file.DateAccessed;
			}
			else
			{
				file_date = file.DateModified;
			}

			if (file_date >= FromDate && file_date <= ToDate)
			{
				if (!(faDirectory & file.Attributes))
				{
					switch (interval)
					{
					case kIntervalHour:
					{
						std::wstring s = std::to_wstring(file_date);

						if (s.size() == 3) s = L"0" + s;
						if (s.size() == 2) s = L"00" + s;

						int x = stoi(s.substr(0, 2));

						HoursC[x]++;
						HoursS[x] += file.Size;

						HistoryTotalCount++;
						HistoryTotalSize += file.Size;

						ExtSpreadHistory[file.Category][0]++;
						ExtSpreadHistory[file.Category][1] += file.Size;
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

			AddHourBar(chart, search_strings, interval, quantity,
					   s, s2, HoursC[t], HoursS[t], ColourMod);
		}
	}

	// ===========================================================================


	return GLanguageHandler->Text[kFound] + L" " + std::to_wstring(HistoryTotalCount) + L" " + GLanguageHandler->Text[kFiles] + L"    " +
	       GLanguageHandler->Text[kSize] + L" : " + Convert::ConvertToUsefulUnit(HistoryTotalSize);

	// ===========================================================================

	if (interval <= kIntervalYear)
	{
//		switch (date_select)
//		{                TO DO
//		case kCreatedDate  : GScanEngine->[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDates));
//		case kAccessedDate : GScanEngine->[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesAccessed));
//		case kModifiedDate : GScanEngine->[aDataIndex].Files.Sort(TComparer<TFileObject>.Construct(CompareFileDatesModified));
//		}
	}
} //440
