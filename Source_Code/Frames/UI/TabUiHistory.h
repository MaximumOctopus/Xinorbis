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

#pragma once

#include <VCLTee.Chart.hpp>
#include <vector>


namespace TabUiHistory
{
	const static int kIntervalDay   = 0;
	const static int kIntervalWeek  = 1;
	const static int kIntervalMonth = 2;
	const static int kIntervalYear  = 3;
	const static int kIntervalHour  = 4;

	int AddBar(TChart*, std::vector<std::wstring> &, TDateTime, int, bool, int, unsigned __int64, int, int);

	int AddHourBar(TChart*, std::vector<std::wstring> &, int, bool,
				   const std::wstring, const std::wstring, int, int __int64, int);

	std::wstring Chart(TChart*, std::vector<std::wstring> &, int,
					   TDateTime, TDateTime,
					   int, int, bool, bool,
					   std::wstring);
}