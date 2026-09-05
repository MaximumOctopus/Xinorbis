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

#include <VCLTee.Chart.hpp>
#include <Vcl.Grids.hpp>
#include <vector>

#include "SizeOfFolder.h"


class XDatabase
{
public:

	bool InitSqlite(const std::wstring);

	bool InitODBC(const std::wstring);
	void CloseODBC();

	bool GetAllAvailableTables(std::vector<std::wstring> &);
	bool TableExists(const std::wstring);
	void InitialiseTreeWithFolders(TTreeView*, const const std::wstring);

	SizeOfFolder PopulateGridFromSQL(TStringGrid *, const std::wstring, int, bool);
	void PopulateTreeFolder(TTreeView*, const std::wstring, TTreeNode*, const std::wstring, int);

	bool DeleteTable(const std::wstring);

	bool ExportTableToCSV(const std::wstring, const std::wstring);
	bool ExportTableToXML(const std::wstring, const std::wstring);

	void PopulateXinFilesFromTable(const std::wstring);
};
