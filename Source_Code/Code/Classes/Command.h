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

// available commands for the in-built console

#pragma once


#include <string>


static const int kCommandCount = 7;

enum class PrimaryCommand { None = 0, Exit = 1, Help = 2, Report = 3, Search = 4, Filter = 5, Save = 6 };

static const std::wstring ValidCommandText[kCommandCount] = { L"", L"exit", L"help", L"report", L"search", L"filter", L"save" };

static const PrimaryCommand ValidCommands[kCommandCount] = { PrimaryCommand::None, PrimaryCommand::Exit, PrimaryCommand::Help, PrimaryCommand::Report, PrimaryCommand::Search,
	PrimaryCommand::Filter, PrimaryCommand::Save
};


struct Command
{
	PrimaryCommand primary = PrimaryCommand::None;

	std::wstring primarystr = L"";
	std::wstring fullcommandstr = L"";

	std::wstring secondary = L"";
	std::wstring tertiary = L"";
	std::wstring quaternary = L"";

	std::wstring GetFullCommand();

	void Print();
};