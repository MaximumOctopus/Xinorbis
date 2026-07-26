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


#include "ReportTreeOptions.h"


namespace ReportTree
{
	void Generate(TreeReportOptions, std::vector<std::wstring>*, int);

	int GetIndent(const std::wstring);
}