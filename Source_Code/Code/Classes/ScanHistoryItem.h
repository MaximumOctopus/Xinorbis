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


class ScanHistoryItem
{
public:

	int Date;   		// yyyymmdd
	std::wstring Time;  // hh:mm

	std::wstring Path = L"";

	std::wstring ExcludeFiles = L"";
    std::wstring ExcludeFolders = L"";
};
