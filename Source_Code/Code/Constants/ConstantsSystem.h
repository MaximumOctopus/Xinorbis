// =====================================================================
//
//   Xinorbis 10.0
//
// (c) Paul Alan Freshney 2002-2026
//
// paul@freshney.org
//
// https://maximumoctopus.hashnode.dev/
//
// https://github.com/MaximumOctopus/Xinorbis
//
// =====================================================================

#pragma once


#ifdef DEBUG
static const std::wstring __XVersion = L"10.0.3 (debug)";
#else
static const std::wstring __XVersion = L"10.0.3";
#endif

static const std::wstring __XDate    = L"October 1st 2026";

// used by checkversion
static const UnicodeString __ApplicationVersionFileUrl = L"http://www.maximumoctopus.com/versions/x10.html";
static const UnicodeString __ApplicationHistoryFileUrl = L"http://www.maximumoctopus.com/versions/x10h.html";

static const std::wstring __XRegistryPath = L"\\MaximumOctopus\\Xinorbis10";

// ===========================================================================
// == Database ===============================================================
// ===========================================================================

enum class DBMode { None = 0, SQLite = 1, ODBC = 2 };
