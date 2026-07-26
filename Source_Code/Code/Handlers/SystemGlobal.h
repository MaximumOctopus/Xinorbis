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


class SystemGlobal
{

	void Init();

public:

	std::wstring ExePath = L"";
	std::wstring HelpPath = L"";
	std::wstring AppDataPath = L"";

	SystemGlobal();
	~SystemGlobal();

	void CreateObjects();
    void FreeObjects();
};
