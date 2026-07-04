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


class XExploderDataObject
{
public:

	std::wstring FolderName = L"";
	int FolderID = 0;

	int FileCount = 0;
	unsigned __int64 FileSize = 0;

	int Colour = 0;

	double PieSize = 0;
	double PieQuantity = 0;
};
