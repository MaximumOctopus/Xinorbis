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


class SplashHandler
{
public:

	bool ProcessWindowsVisible();

	void ShowProcessWindow();
	void HideProcessWindow();
	void SetProgressBar(int);

	void ShowZipWindow();
	void HideZipWindow();
};
