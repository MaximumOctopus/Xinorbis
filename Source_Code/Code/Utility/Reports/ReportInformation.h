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


namespace ReportInformation
{
	void GetInfoCSVReport(const std::wstring, std::vector<std::wstring>*);
	void GetInfoXinorbisReport(const std::wstring, std::vector<std::wstring>*);
	bool GetInfoXinorbis2Report(const std::wstring, std::vector<std::wstring>*);
}
