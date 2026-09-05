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

#include "SplashHandler.h"

#include "XFormProgress.h"

SplashHandler *GSplashHandler;


SplashHandler::SplashHandler()
{
	FormProgress = new TFormProgress(Application);
}


SplashHandler::~SplashHandler()
{
	delete FormProgress;
}


bool SplashHandler::ProcessWindowsVisible()
{
	return FormProgress->Visible;
}


void SplashHandler::ShowProcessWindow()
{
	FormProgress->Visible = true;
}


void SplashHandler::HideProcessWindow()
{
	FormProgress->Visible = false;
}


void SplashHandler::SetProgressBar(int progress)
{
}


void SplashHandler::SetIcon(int icon)
{
	FormProgress->SetProcessIcon(icon);
}


void SplashHandler::ShowZipWindow()
{
}


void SplashHandler::HideZipWindow()
{
}
