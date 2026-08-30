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

#include "ScanHistoryItem.h"


class ScanHistoryHandler
{
	std::wstring FilePath = L"";
	bool FromFile = true;

	bool Load(const std::wstring, bool);
	bool Save();

public:

	std::vector<ScanHistoryItem*> History;

    ScanHistoryHandler(const std::wstring);
	~ScanHistoryHandler();

    void Clear();

	void Add(const std::wstring, const std::wstring, const std::wstring);
};
