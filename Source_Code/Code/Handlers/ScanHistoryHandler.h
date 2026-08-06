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

	bool Load(const std::wstring, bool);
	bool Save(const std::wstring, bool);

public:

	std::vector<ScanHistoryItem*> History;

    void Clear();

	void Add(const std::wstring, const std::wstring, const std::wstring);
};
