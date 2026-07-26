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

#include <vector>

#include "HTMLColours.h"
#include "ReportHTMLOptions.h"


namespace HTMLPreview
{
	void Get(std::vector<std::wstring> &, HTMLReportOptions &, HTMLColours &);

	void BuildMenuList(std::vector<std::wstring> &);

	void AddHTMLReportItem(std::vector<std::wstring> &, std::vector<std::wstring> &, HTMLColours &, int, const std::wstring, int);
}
