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


static const int kPostScanNothing      = 0;
static const int kPostScanSummary      = 1;
static const int kPostScanInformation  = 2;
static const int kPostScanStructure    = 3;

static const int kFTPOptionsCount = 6;

static const int kFTPOptionHost          = 1;
static const int kFTPOptionUserName      = 2;
static const int kFTPOptionPassword      = 3;
static const int kFTPOptionRemoteFolder  = 4;
static const int kFTPOptionActualLink    = 5;
static const int kFTPOptionInitialFolder = 6;


static const int ProgressUpdates[6][2] = { { 30,   500 },
										   { 20,  2000 },
										   { 10,  5000 },
										   {  6, 10000 },
										   {  4, 20000 },
										   {  1, 40000 } };

