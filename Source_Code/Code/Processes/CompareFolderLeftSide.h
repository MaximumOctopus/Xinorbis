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


class CompareFolderLeftSide
{
	constexpr static int kFieldEmpty = 0;
	constexpr static int kFieldCategoryCountPC = 3;
	constexpr static int kFieldCategorySizePC  = 6;

//	XODBC      : TADOConnection;

	std::wstring SQL = L"";
	std::wstring Folder = L"";
	TStringGrid *grid = nullptr;
//	slabel     : THTMLabel;
//	extspreadt : array[0..__FileCategoriesCount, 1..2] of Int64;   //maintains extension match counts - 1..count, 2..size
//	tnumfiless, tnumfiless_folder : integer;
//	tFileTotalSpace, tFileTotalSpace_folder : int64;

	void ProcessODBC(const std::wstring);
	void ProcessSqlite(const std::wstring);

	bool InitODBC(const std::wstring);
	void CloseODBC();

public:

	void Execute();

	void SetData(const std::wstring, const std::wstring, bool, TStringGrid*);
};