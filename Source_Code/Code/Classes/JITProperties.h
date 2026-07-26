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


class JITProperties
{

	bool Tabs[12] = { false, false, false, false, false, false,
					  false, false, false, false, false, false };

public:


	void Clear()
	{
        for (int t = 0; t < 12; t++) Tabs[t] = false;
	}

	void SetTab(int tab)
	{
		Tabs[tab] = true;
	}

	bool GetTab(int tab)
	{
		return Tabs[tab];
	}
};
