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

#include <algorithm>

#include "ConstantsGui.h"
#include "HelpHandler.h"
#include "LanguageHandler.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

#include "XFormXinorbisDialog.h"

extern LanguageHandler *GLanguageHandler;
extern SystemGlobal *GSystemGlobal;

HelpHandler *GHelpHandler;


void HelpHandler::OpenContextHelpPage(const std::wstring history_item, int reports_index, int fh_main_index, int fh_sub_index)
{
	int TaskId = -1;
	int WelcomeId = -1;

	switch (history_item[0])
	{
	case L'H':
		break;
	case L'W':
		WelcomeId = stoi(history_item.substr(1, 1));
		break;
	case L'T':
		TaskId = stoi(history_item.substr(1, 1));
		break;
	}

	std::wstring page = L"";

	// ===========================================================================
	// ===========================================================================

	switch (TaskId)
	{
	case 1:
		page = L"t11";         // summary
		break;
	case 2:
		switch (reports_index) // report
		{
		case 0: page = L"t21"; break;
		case 1: page = L"t22"; break;
		case 2: page = L"t23"; break;
		case 3: page = L"t24"; break;
		case 4: page = L"t25"; break;
		case 5: page = L"t26"; break;
		case 6: page = L"t27"; break;
		case 7: page = L"t28"; break;
		case 8: page = L"t29"; break;
		case 9: page = L"t2a"; break;
		case 10: page = L"t2b"; break;
		case 11: page = L"t2c"; break;
		}
		break;
	case 3:
		page = L"t31";
		break;
	case 4:
		page = L"t41";
		break;
	case 5:
		page = L"t51";
		break;
	}

	// ===========================================================================
	// ===========================================================================

	switch (WelcomeId)
	{
	case 1:
		page = L"w11";
		break;
	case 2:
		switch (fh_main_index)
		{
		case kTabFHMainStats:
			switch (fh_sub_index)
			{
			case kTabFHChart:
				page = L"w22";
				break;
			case kTabFHTable:
				page = L"w23";
				break;
			case kTabFHTimeLine:
				page = L"w28";
				break;
			}
		case kTabFHMainSearch:
			switch (fh_sub_index)
			{
			case kTabFHCompare:
				page = L"w25";
				break;
			case kTabFHCompareDiff:
				page = L"w26";
				break;
			case kTabFHCompareTree:
				page = L"w27";
				break;
			}
		}
		break;
	}

	// ===========================================================================
	// ===========================================================================

	if (TaskId == -1 && WelcomeId == -1)
	{
		page = L"index";
	}

	// ===========================================================================
	// ===========================================================================

	if (!page.empty())
	{
		OpenHelpPage(page + L".htm");
	}
	else
	{
		ShowXDialog(GLanguageHandler->Text[kErrorOpeningXinorbisSystemFile],
					L"Error : Can't find help page: " + GSystemGlobal->ExePath + L"data\\help\\" + page + L".htm",
					XDialogTypeWarning);
	}
}


void HelpHandler::OpenHelpPage(const std::wstring page)
{
	std::wstring pagelc = page;

	std::transform(pagelc.begin(), pagelc.end(), pagelc.begin(), ::tolower);

	WindowsUtility::ExecuteFile(GSystemGlobal->HelpPath + pagelc, L"");
}


void HelpHandler::OpenSearchManual()
{
	WindowsUtility::ExecuteFile(L"\"" + GSystemGlobal->ExePath + L"Xinorbis10 Search Manual.pdf\"", L"");
}
