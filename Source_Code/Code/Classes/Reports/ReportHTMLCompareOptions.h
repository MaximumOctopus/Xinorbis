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


struct HTMLCompareReportOptions
{
	std::wstring FileName = L"";
	int Units = 0;
	std::wstring Layout = L"";

	int LayoutSize = 3;	// 1 = 800x600, 2 = 1024x768, 3 = 1280x960
};
