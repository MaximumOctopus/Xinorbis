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

#include "ConstantsReports.h"
#include "Convert.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportCSVOptions.h"


namespace CSVPreview
{
	void Get(CSVReportOptions, std::vector<std::wstring> &);
}
