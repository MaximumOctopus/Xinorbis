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

#include <Vcl.Menus.hpp>
#include <vector>


enum class QMAction { kNone = 0, kSearchString, kOther };


struct QuickMenuAction
{
	QMAction Action = QMAction::kNone;

	std::wstring Search = L"";

	int SubAction = 0;
};


class QuickMenuHandler
{
	std::vector<std::wstring> Commands;

	std::wstring ParseMenuSearchCommand(const std::wstring);
    int ParseMenuSearchCommandII(const std::wstring);

public:

	bool LoadMenu(TPopupMenu*, const std::wstring);

	QuickMenuAction FromMenu(int);

	std::wstring GetCommand(int);
};

