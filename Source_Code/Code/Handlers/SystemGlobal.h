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


enum class InitStatus { kNone = 0, kInstallCheckFail, kSuccess };


class SystemGlobal
{

	void Init();

	bool InstallationCheck();

public:

	InitStatus Status = InitStatus::kNone;

	std::wstring ExePath = L"";
	std::wstring HelpPath = L"";
	std::wstring AppDataPath = L"";

	SystemGlobal();
	~SystemGlobal();

	void CreateObjects();
    void FreeObjects();
};
