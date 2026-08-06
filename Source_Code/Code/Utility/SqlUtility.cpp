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

#include <algorithm>
#include <vector>

#include "ConstantsSearch.h"
#include "Convert.h"
#include "SettingsHandler.h"
#include "SqlUtility.h"
#include "Utility.h"

extern SettingsHandler *GSettingsHandler;


std::wstring SqlUtility::XinorbisSearchToSQL(const std::wstring xdate, const std::wstring xfolder, const std::wstring xcomputer, const std::wstring xinsearch,
	int limitx, int limity, bool demomode)
{
	if (xinsearch.empty()) return L"";

	std::vector<std::wstring> sqlterms;

	// == now add required fields ==============================================

	std::wstring sql = L"SELECT ";

	if (GSettingsHandler->Database.UseODBC)
	{
		GetODBCSpecificPreTerms(xinsearch, sqlterms);

		if (sqlterms.size() != 0)
		{
			sql += L" " + sqlterms[0];
		}
	}

    // == now add required fields ==============================================

	if (demomode)
	{
		sql += L" *";
	}
	else
	{
		sql += L" FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner";
	}

	// =========================================================================

	sql += L" FROM ";

	// =========================================================================

	if (demomode)
	{
		sql += L"$x$";
	}
	else
	{
		sql += L"\"" + Convert::CreateTableName(xdate, xfolder, xcomputer) + L"\"";
	}

    // =========================================================================

	GetSearchTerms(xinsearch, sqlterms);

	if (sqlterms.size() != 0)
	{
		sql += L" WHERE ";

		for (int t = 0; t < sqlterms.size(); t++)
		{
			sql += sqlterms[t];

			if (t != sqlterms.size() - 1)
			{
				sql += L" AND ";
			}
		}
	}

    // ===========================================================================

	GetPostTerms(xinsearch, sqlterms);

	if (sqlterms.size() != 0)
	{
		sql += L" " + sqlterms[0];
	}

	// ===========================================================================

	if (sql.find(L" LIMIT ") == std::wstring::npos)
	{
		if (GSettingsHandler->Database.UseODBC)
		{
			sql += L";";
		}
		else
		{
			sql += L" LIMIT " + std::to_wstring(limitx) + L", " + std::to_wstring(limity) + L";";
		}
	}

	// ===========================================================================

	return sql;
}


std::wstring SqlUtility::XinorbisSearchAllToSQL(const std::wstring xdate, const std::wstring xfolder, const std::wstring xcomputer, bool demomode)
{
	// == now add required fields ==============================================

	std::wstring sql = L"SELECT FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner";

	// =========================================================================

	sql += L" FROM ";

	// =========================================================================

	if (demomode)
	{
		sql += L"$x$";
	}
	else
	{
		sql += L"\"" + Convert::CreateTableName(xdate, xfolder, xcomputer) + L"\"";
	}

	// =========================================================================

	return sql + L";";
}


// private, do not use externally :)


void SqlUtility::GetSearchTerms(const std::wstring input, std::vector<std::wstring> &data)
{
	std::wstring s = L"";
	bool reading = false;
	bool inside  = false;

	data.clear();

	for (int t = 0; t < input.size(); t++)
	{
		if (input[t] == L'\"')
		{
			if (!reading)
			{
				reading = true;
			}
			else
			{
				reading = false;

				std::transform(s.begin(), s.end(), s.begin(), ::toupper);

				std::wstring pst = ProcessSearchTermToSQL(s);

				if (!pst.empty())
				{
					data.push_back(pst);
				}

				s = L"";
			}
		}
		else if (input[t] == L'(')
		{
			inside = true;
		}
		else if (input[t] == L')')
		{
			inside = false;
		}
		else if (input[t] == L' ' && !inside)
		{
			if (reading)
			{
				s += L" ";
			}
			else
			{
				if (!s.empty())
				{
					std::transform(s.begin(), s.end(), s.begin(), ::toupper);

					std::wstring pst = ProcessSearchTermToSQL(s);

					if (!pst.empty())
					{
						data.push_back(pst);
					}

					s = L"";
				}
			}
		}
		else
		{
			s += input[t];
		}
	}

	if (!s.empty())
	{
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);

		std::wstring pst = ProcessSearchTermToSQL(s);

		if (!pst.empty())
		{
			data.push_back(pst);
		}
	}
}


void SqlUtility::GetPostTerms(const std::wstring input, std::vector<std::wstring> &data)
{
	std::wstring s = L"";
	bool reading = false;
	bool inside = false;

	data.clear();

	for (int t = 0; t < input.size(); t++)
	{
		if (input[t] == L'\"')
		{
			if (!reading)
			{
				reading = true;
			}
			else
			{
				reading = false;

				std::transform(s.begin(), s.end(), s.begin(), ::toupper);

				std::wstring pst = ProcessSearchTermToSQLPost(s);

				if (!pst.empty())
				{
					data.push_back(pst);
				}

				s = L"";
			}
		}
		else if (input[t] == L'(')
		{
			inside = true;
		}
		else if (input[t] == L')')
		{
			inside = false;
		}
		else if (input[t] == L' ' && !inside)
		{
			if (reading)
			{
				s += L' ';
			}
			else
			{
				if (!s.empty())
				{
					std::transform(s.begin(), s.end(), s.begin(), ::toupper);

					std::wstring pst = ProcessSearchTermToSQLPost(s);

					if (!pst.empty())
					{
						data.push_back(pst);
					}

					s = L"";
				}
			}
		}
		else
		{
			s += input[t];
		}
	}

	if (!s.empty())
	{
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);

		std::wstring pst = ProcessSearchTermToSQLPost(s);

		if (!pst.empty())
		{
			data.push_back(pst);
		}
	}
}


void SqlUtility::GetODBCSpecificPreTerms(const std::wstring input, std::vector<std::wstring> &data)
{
	std::wstring s = L"";
	bool reading = false;
	bool inside = false;

	data.clear();

	for (int t = 0; t < input.size(); t++)
	{
		if (input[t] == L'\"')
		{
			if (!reading)
			{
				reading = true;
			}
			else
			{
				reading = false;

				std::transform(s.begin(), s.end(), s.begin(), ::toupper);

				std::wstring pst = ProcessSearchTermToSQLPostODBC(s);

				if (!pst.empty())
				{
					data.push_back(pst);
				}

				s = L"";
			}
		}
		else if (input[t] == L'(')
		{
			inside = true;
		}
		else if (input[t] == L')')
		{
			inside = false;
		}
		else if (input[t] == L' ' && !inside)
		{
			if (reading)
			{
				s += L' ';
			}
			else
			{
				if (!s.empty())
				{
					std::transform(s.begin(), s.end(), s.begin(), ::toupper);

					std::wstring pst = ProcessSearchTermToSQLPostODBC(s);

					if (!pst.empty())
					{
						data.push_back(pst);
					}

					s = L"";
				}
			}
		}
		else
		{
			s += input[t];
		}
	}

	if (!s.empty())
	{
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);

		std::wstring pst = ProcessSearchTermToSQLPostODBC(s);

		if (!pst.empty())
		{
			data.push_back(pst);
		}
	}
}


std::wstring SqlUtility::ProcessSearchTermToSQL(const std::wstring input)
{
	std::wstring f_length = L"";
	std::wstring parameter = L"";
	std::wstring value = L"";
	std::wstring valueuc = L"";
	std::wstring output = L"";

	int test = 0;

	if (GSettingsHandler->Database.UseODBC) // sqlite and sqlserver have different functions for length :(
	{
		f_length = L"len";
	}
	else
	{
		f_length = L"length";
	}

	GetTokens(input, parameter, value, test);

	valueuc = value;

	std::transform(valueuc.begin(), valueuc.end(), valueuc.begin(), ::toupper);

	if (parameter == L"SIZE")
	{
		switch (test)
		{
		case SearchConstants::kTestLessThan   : output = L"(FileSize<=" + Convert::ConvertUsefulUnitToString(value) + L")"; break;
		case SearchConstants::kTestEqualTo    : output = L"(FileSize="  + Convert::ConvertUsefulUnitToString(value) + L")"; break;
		case SearchConstants::kTestGreaterThan: output = L"(FileSize>=" + Convert::ConvertUsefulUnitToString(value) + L")"; break;
		};
	}
	else if (parameter == L"ADATE")
	{
		switch (test)
		{
		case SearchConstants::kTestLessThan   : output = L"(FileDateA<=" + std::to_wstring(Convert::DateFromAnyFormatToYYYYMMDD(value)) + L")"; break;
		case SearchConstants::kTestEqualTo    : output = L"(FileDateA="  + std::to_wstring(Convert::DateFromAnyFormatToYYYYMMDD(value)) + L")"; break;
		case SearchConstants::kTestGreaterThan: output = L"(FileDateA>=" + std::to_wstring(Convert::DateFromAnyFormatToYYYYMMDD(value)) + L")"; break;
		};
	}
	else if (parameter == L"MDATE")
	{
		switch (test)
		{
		case SearchConstants::kTestLessThan   : output = L"(FileDateM<=" + std::to_wstring(Convert::DateFromAnyFormatToYYYYMMDD(value)) + L")"; break;
		case SearchConstants::kTestEqualTo    : output = L"(FileDateM="  + std::to_wstring(Convert::DateFromAnyFormatToYYYYMMDD(value)) + L")"; break;
		case SearchConstants::kTestGreaterThan: output = L"(FileDateM>=" + std::to_wstring(Convert::DateFromAnyFormatToYYYYMMDD(value)) + L")"; break;
		};
	}
	else if (parameter == L"DATE")
	{
		switch (test)
		{
		case SearchConstants::kTestLessThan   : output = L"(FileDateC<=" + std::to_wstring(Convert::DateFromAnyFormatToYYYYMMDD(value)) + L")"; break;
		case SearchConstants::kTestEqualTo    : output = L"(FileDateC="  + std::to_wstring(Convert::DateFromAnyFormatToYYYYMMDD(value)) + L")"; break;
		case SearchConstants::kTestGreaterThan: output = L"(FileDateC>=" + std::to_wstring(Convert::DateFromAnyFormatToYYYYMMDD(value)) + L")"; break;
		};
	}
	else if (parameter == L"USER")
	{
		switch (test)
		{
		case SearchConstants::kTestLessThan:
		case SearchConstants::kTestEqualTo:
		case SearchConstants::kTestGreaterThan: output = L"(Owner='"           + valueuc + L"')"; break;
		case SearchConstants::kTestNotEqualTo : output = L"(Owner!='"          + valueuc + L"')"; break;
		case SearchConstants::kTestContains   : output = L"(Owner LIKE '%"     + valueuc + L"%')"; break;
		case SearchConstants::kTestNotContains: output = L"(Owner NOT LIKE '%" + valueuc + L"%')"; break;
		};
	}
	else if (parameter == L"FILENAMELENGTH")
	{
		switch (test)
		{
		case SearchConstants::kTestLessThan   : output = L"(" + f_length + L"(FileName)<=" + value + L")"; break;
		case SearchConstants::kTestEqualTo    : output = L"(" + f_length + L"(FileName)="  + value + L")"; break;
		case SearchConstants::kTestGreaterThan: output = L"(" + f_length + L"(FileName)>=" + value + L")"; break;
		};
	}
	else if (parameter == L"FILEPATHLENGTH")
	{
		switch (test)
		{
		case SearchConstants::kTestLessThan   : output = L"(" + f_length + L"(FileName) + " + f_length + L"(FilePath)<=" + value + L")"; break;
		case SearchConstants::kTestEqualTo    : output = L"(" + f_length + L"(FileName) + " + f_length + L"(FilePath)="  + value + L")"; break;
		case SearchConstants::kTestGreaterThan: output = L"(" + f_length + L"(FileName) + " + f_length + L"(FilePath)>=" + value + L")"; break;
		};
	}
	else if (parameter == L"CATEGORY")
	{
		switch (test)
		{
		case SearchConstants::kTestEqualTo   : output = L"(Category="  + value + L")"; break;
		case SearchConstants::kTestNotEqualTo: output = L"(Category!=" + value + L")"; break;
		};
	}
	else if (parameter == L"ATTRIBUTES")
	{
		switch (StrToIntDef(value.c_str(), kFileType_File))
		{
		case kFileType_File         : output = L"(Directory=0)"; break;
		case kFileType_Folder       : output = L"(Directory=1)"; break;
		case kFileType_Hidden       : output = L"(Hidden=1)"; break;
		case kFileType_System       : output = L"(System=1)"; break;
		case kFileType_Archive      : output = L"(Archive=1)"; break;
		case kFileType_Null         : output = L"(FileSize=0)"; break;
		case kFileType_ReadOnly     : output = L"(Readonly=1)"; break;
		case kFileType_CreatedToday : output = L"(FileDateC=" + Utility::GetDate(DateTimeFormat::YYYYMMDD) + L")"; break;
		case kFileType_AccessedToday: output = L"(FileDateA=" + Utility::GetDate(DateTimeFormat::YYYYMMDD) + L")"; break;
		case kFileType_ModifiedToday: output = L"(FileDateM=" + Utility::GetDate(DateTimeFormat::YYYYMMDD) + L")"; break;
		case kFileType_Temp         : output = L"(Temp=1)"; break;
		}
	};

	if (test == SearchConstants::kTestNotEqualTo)
	{
		output = Utility::ReplaceString(output, L"=", L"!=");
	}
	else if (parameter == L"TOP")
	{
		output = L"";
	}
	else if (parameter == L"BOT")
	{
		output = L"";
	}
	else if (parameter == L"FILE")
	{
		output = L"(FileName LIKE '%" + valueuc + L"%')";
	}
	else if (parameter == L"EXTENSION")
	{
		output = L"(FilePath LIKE '%" + valueuc + L"%') OR (FileName LIKE '%" + valueuc + L"%')";
	}
	else
	{
		output = L"(FilePath LIKE '%" + valueuc + L"%') OR (FileName LIKE '%" + valueuc + L"%')";
	};

	return output;
}


std::wstring SqlUtility::ProcessSearchTermToSQLPost(const std::wstring input)
{
	std::wstring s = input;

	std::transform(s.begin(), s.end(), s.begin(), ::toupper);

	if (GSettingsHandler->Database.UseODBC)
	{
		if (s.find(L"TOP=") != std::wstring::npos)
		{
			return L" ORDER BY FileSize DESC";
		}
		else if (s.find(L"CTOP=") != std::wstring::npos)
		{
			return L" ORDER BY FileDateC DESC";
		}
		else if (s.find(L"ATOP=") != std::wstring::npos)
		{
			return L" ORDER BY FileDateA DESC";
		}
		else if (s.find(L"MTOP=") != std::wstring::npos)
		{
			return L" ORDER BY FileDateM DESC";
		}
		else if (s.find(L"BOT=") != std::wstring::npos)
		{
			return L" ORDER BY FileSize ASC";
		}
	}
	else
	{
		if (s.find(L"TOP=") != std::wstring::npos)
		{
			return L" ORDER BY FileSize DESC LIMIT " + s.substr(4);
		}
		else if (s.find(L"CTOP=") != std::wstring::npos)
		{
			return L" ORDER BY FileDateC DESC LIMIT " + s.substr(5);
		}
		else if (s.find(L"ATOP=") != std::wstring::npos)
		{
			return L" ORDER BY FileDateA DESC LIMIT " + s.substr(5);
		}
		else if (s.find(L"MTOP=") != std::wstring::npos)
		{
			return L" ORDER BY FileDateM DESC LIMIT " + s.substr(5);
		}
		else if (s.find(L"BOT=") != std::wstring::npos)
		{
			return L" ORDER BY FileSize ASC LIMIT " + s.substr(4);
		}
	}

	return L"";
}


std::wstring SqlUtility::ProcessSearchTermToSQLPostODBC(const std::wstring input)
{
	std::wstring s = input;

	std::transform(s.begin(), s.end(), s.begin(), ::toupper);

	if (s.find(L"TOP=") != std::wstring::npos)
	{
		return L"TOP " + s.substr(4) + L" " ;
	}
	else if (s.find(L"CTOP=") != std::wstring::npos)
	{
		return L"TOP " + s.substr(5) + L" ";
	}
	else if (s.find(L"ATOP=") != std::wstring::npos)
	{
		return L"TOP " + s.substr(5) + L" ";
	}
	else if (s.find(L"MTOP=") != std::wstring::npos)
	{
		return L"TOP " + s.substr(5) + L" ";
	}
	else if (s.find(L"BOT=") != std::wstring::npos)
	{
		return L"TOP " + s.substr(4) + L" ";
	}

	return L"";
}


void SqlUtility::GetTokens(const std::wstring aInput, std::wstring &aParameter, std::wstring &aValue, int &aTest)
{
	aParameter = L"";
	aValue     = L"";
	aTest      = SearchConstants::kTestEqualTo;
	std::wstring test = L"";

	int mode = 0;

	if (!aInput.empty())
	{
		if (aInput[1] == L'#')
		{
			aParameter = L"CATEGORY";

			for (int t = 0; t < SearchConstants::kCategoryTermCount; t++)
			{
				if (aInput.find(L"#" + SearchConstants::kCategoryTerms[t]) != std::wstring::npos)
				{
					if (aInput.back() == L'-')
					{
						aTest = SearchConstants::kTestNotEqualTo;
					}
					else
					{
						aTest = SearchConstants::kTestEqualTo;
					}

					aValue = std::to_wstring(SearchConstants::kCategoryValues[t]);
				}
			}
		}
		else if (aInput[1] == L'@')
		{
			aParameter = L"ATTRIBUTES";

			for (int t = 0; t < SearchConstants::kTypeTermCount; t++)
			{
				if (aInput.find(L"@" + SearchConstants::kTypeTerms[t]) != std::wstring::npos)
				{
					if (aInput.back() == L'-')
					{
						aTest = SearchConstants::kTestNotEqualTo;
					}
					else
					{
						aTest = SearchConstants::kTestEqualTo;
					}

					aValue = std::to_wstring(SearchConstants::kTypeValues[t]);
				}
			}
		}
		else
		{
			int pos = 0;

			while (pos < aInput.size())
			{
				switch (mode)
				{
				case SearchConstants::kModeField:
					if (isalpha(aInput[pos]))
					{
						aParameter += aInput[pos];

						pos++;
					}
					else
					{
						mode = 1;
					}
					break;
				case SearchConstants::kModeTest:
					if (Utility::IsTestCharacter(aInput[pos]))
					{
						test += aInput[pos];

						pos++;
					}
					else
					{
						if (test == L"<" || test == L"<=" || test == L"=<")
						{
							aTest = SearchConstants::kTestLessThan;
						}
						else if (test == L"=" || test == L"==")
						{
							aTest = SearchConstants::kTestEqualTo;
						}
						else if (test == L">" || test == L">=" || test == L"=>")
						{
							aTest = SearchConstants::kTestGreaterThan;
						}
						else if (test == L"!=" || test == L"<>")
						{
							aTest = SearchConstants::kTestNotEqualTo;
						}
						else if (test == L"~")
						{
							aTest = SearchConstants::kTestContains;
						}
						else if (test == L"!~" || test == L"~!")
						{
							aTest = SearchConstants::kTestNotContains;
						}

						mode = 2;
					}
					break;
				case SearchConstants::kModeValue:
					aValue += aInput[pos];

					pos++;
					break;
				}
			}
		}
	}
}
