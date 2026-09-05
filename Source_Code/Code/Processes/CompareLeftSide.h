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

#include <Vcl.Grids.hpp>


class CompareLeftSide
{
   //	XODBC    : TADOConnection;

	std::wstring SQL = L"";
	int Option1 = 0;
	bool Option2 = false;
	TStringGrid *grid = nullptr;

	void ProcessODBC(const std::wstring);
	void ProcessSqlite(const std::wstring);

	bool InitODBC(const std::wstring);
	void CloseODBC();

public:

	void Execute();

	void SetData(const std::wstring, int, bool, TStringGrid*);
};
