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


#ifdef DEBUG
static const std::wstring __XVersion = L"10.0 (debug)";
#else
static const std::wstring __XVersion = L"10.0";
#endif

static const std::wstring __XDate    = L"July 4th 2026";

// used by checkversion
static const UnicodeString __ApplicationVersionFileUrl = L"http://www.maximumoctopus.com/versions/x10.html";
static const UnicodeString __ApplicationHistoryFileUrl = L"http://www.maximumoctopus.com/versions/x10h.html";

static const std::wstring __XRegistryPath = L"\\MaximumOctopus\\Xinorbis10";
