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


namespace SqlUtility
{
	std::wstring XinorbisSearchToSQL(const std::wstring, const std::wstring, const std::wstring, const std::wstring, int, int, bool);

	std::wstring XinorbisSearchAllToSQL(const std::wstring, const std::wstring, const std::wstring, bool);

	// private, do not use externally :)

	void GetSearchTerms(const std::wstring, std::vector<std::wstring>&);
	void GetPostTerms(const std::wstring, std::vector<std::wstring>&);
	void GetODBCSpecificPreTerms(const std::wstring, std::vector<std::wstring>&);
	std::wstring ProcessSearchTermToSQL(const std::wstring);
	std::wstring ProcessSearchTermToSQLPost(const std::wstring);
	std::wstring ProcessSearchTermToSQLPostODBC(const std::wstring);

	void GetTokens(const std::wstring, std::wstring &, std::wstring &, int &);
}
