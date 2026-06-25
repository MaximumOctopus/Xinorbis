// =====================================================================
//
// FolderScanUltra 5
//
// (c) Paul Alan Freshney 2019-2026
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FolderScanUltra
// 
// =====================================================================

#pragma once


#include <string>


struct DriveDetails
{
	bool Valid = false;

	std::wstring VolumeName = L"";
	std::wstring FileSystem = L"";
	std::wstring SerialNumber = L"";
	std::wstring SerialNumberHex = L"";

	int SectorsPerCluster = 0;
	int BytesPerSector = 0;
	int FreeClusters = 0;
	int Clusters = 0;

	int SectorSize = 0;
};