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
#include <string>

#include "Convert.h"
#include "ConstantsSearch.h"
#include "LanguageHandler.h"
#include "SearchCriteriaObject.h"
#include "SearchUtility.h"
#include "Utility.h"

extern LanguageHandler *GLanguageHandler;


SearchCriteriaObject SearchUtility::ProcessSearchTerm(const std::wstring s)
{
	SearchCriteriaObject sco;

	if (s.find(L"SIZE") != std::wstring::npos)
	{
		ProcessSearchTermSize(sco, s);
	}

	if (s.find(L"TIME") != std::wstring::npos)
	{
		ProcessSearchTermTime(sco, s);
	}

	if (s.find(L"DATE") != std::wstring::npos)
	{
		ProcessSearchTermDate(sco, s);
	}

	if (s.find(L"USER") != std::wstring::npos)
	{
		ProcessSearchTermUser(sco, s);
	}

	if (s.find(L"FILENAMELENGTH") != std::wstring::npos || s.find(L"FILEPATHLENGTH") != std::wstring::npos)
	{
		ProcessSearchTermFNL(sco, s);
	}

	if (s.find(L"EXTENSION=") != std::wstring::npos)
	{
		ProcessExtensions(sco, s);
	}

	if (s.find(L"EXCLUDEFOLDER=") != std::wstring::npos)
	{
		ProcessExcludeFolder(sco, s);
	}

	if (s.find(L"INCLUDEFOLDER=") != std::wstring::npos)
	{
		ProcessIncludeFolder(sco, s);
	}

	if (!s.empty())
	{
		if (s[0] == L'#')
		{
			ProcessSearchTermCategory(sco, s);
		}
		else if (s[0] == L'@')
		{
			ProcessSearchTermTypes(sco, s);
		}
	}

	return sco;
}


void SearchUtility::ProcessSearchTermSize(SearchCriteriaObject& sco, std::wstring input)
{
	std::wstring parameter = L"";
	std::wstring value = L"";
	TestType test = TestType::None;

	GetTokens(input, parameter, value, test);

	if (parameter == L"SIZE")
	{
		switch (test)
		{
		case TestType::LessThan:
			sco.Type = SearchType::SizeLess;
			break;

		case TestType::EqualTo:
			sco.Type = SearchType::SizeEqual;
			break;

		case TestType::GreaterThan:
			sco.Type = SearchType::SizeMore;
			break;
		}
	}

	sco.IntegerValue = Convert::ConvertUsefulUnitToInteger(value);
}


void SearchUtility::ProcessSearchTermTime(SearchCriteriaObject& sco, std::wstring input)
{
	std::wstring parameter = L"";
	std::wstring value = L"";
	TestType test = TestType::None;

	GetTokens(input, parameter, value, test);

	if (parameter == L"ATIME")
	{
		switch (test)
		{
		case TestType::LessThan:
			sco.Type = SearchType::ATimeLess;
			break;

		case TestType::EqualTo:
			sco.Type = SearchType::ATimeEqual;
			break;

		case TestType::GreaterThan:
			sco.Type = SearchType::ATimeMore;
			break;
		}

		sco.IntegerValue = Convert::TimeFromAnyFormatToHHMM(value);
	}
	else if (parameter == L"MTIME")
	{
		switch (test)
		{
		case TestType::LessThan:
			sco.Type = SearchType::MTimeLess;
			break;

		case TestType::EqualTo:
			sco.Type = SearchType::MTimeEqual;
			break;

		case TestType::GreaterThan:
			sco.Type = SearchType::MTimeMore;
			break;
		}

		sco.IntegerValue = Convert::TimeFromAnyFormatToHHMM(value);
	}
	else if (parameter == L"TIME" || parameter == L"CTIME")
	{
		switch (test)
		{
		case TestType::LessThan:
			sco.Type = SearchType::TimeLess;
			break;

		case TestType::EqualTo:
			sco.Type = SearchType::TimeEqual;
			break;

		case TestType::GreaterThan:
			sco.Type = SearchType::TimeMore;
			break;
		}

		sco.IntegerValue = Convert::TimeFromAnyFormatToHHMM(value);
	}
}


void SearchUtility::ProcessSearchTermDate(SearchCriteriaObject& sco, std::wstring input)
{
	std::wstring parameter = L"";
	std::wstring value = L"";
	TestType test = TestType::None;

	GetTokens(input, parameter, value, test);

	if (parameter == L"DATE" || parameter == L"CDATE")
	{
		switch (test)
		{
		case TestType::LessThan:
			sco.Type = SearchType::DateLess;
			break;

		case TestType::EqualTo:
			sco.Type = SearchType::DateEqual;
			break;

		case TestType::GreaterThan:
			sco.Type = SearchType::DateMore;
			break;
		}

		sco.IntegerValue = Convert::DateFromAnyFormatToYYYYMMDD(value);
	}
	else if (parameter == L"ADATE")
	{
		switch (test)
		{
		case TestType::LessThan:
			sco.Type = SearchType::ADateLess;
			break;
		case TestType::EqualTo:
			sco.Type = SearchType::ADateEqual;
			break;
		case TestType::GreaterThan:
			sco.Type = SearchType::ADateMore;
			break;
		}

		sco.IntegerValue = Convert::DateFromAnyFormatToYYYYMMDD(value);
	}
	else if (parameter == L"MDATE")
	{
		switch (test)
		{
		case TestType::LessThan:
			sco.Type = SearchType::MDateLess;
			break;

		case TestType::EqualTo:
			sco.Type = SearchType::MDateEqual;
			break;

		case TestType::GreaterThan:
			sco.Type = SearchType::MDateMore;
			break;
		}

		sco.IntegerValue = Convert::DateFromAnyFormatToYYYYMMDD(value);
	}
}


void SearchUtility::ProcessSearchTermUser(SearchCriteriaObject& sco, std::wstring input)
{
	std::wstring parameter = L"";
	std::wstring value = L"";
	TestType test = TestType::None;

	GetTokens(input, parameter, value, test);

	if (parameter == L"USER")
	{
		switch (test)
		{
		case TestType::LessThan:
		case TestType::EqualTo:
		case TestType::GreaterThan:
			sco.Type = SearchType::UserName;
			break;

		case TestType::NotEqualTo:
			sco.Type = SearchType::NotUserName;
			break;

		case TestType::Contains:
			sco.Type = SearchType::UserNameContains;
			break;

		case TestType::NotContains:
			sco.Type = SearchType::UserNameNotContains;
			break;
		}
	}

	std::transform(value.begin(), value.end(), value.begin(), ::toupper);

	sco.StringValue = value;
}


void SearchUtility::ProcessSearchTermFNL(SearchCriteriaObject& sco, std::wstring input)
{
	int index = 0;

	if (input.find(L"FILENAMELENGTH=") != std::wstring::npos)
	{
		index = input.find(L"FILENAMELENGTH=");

		IntegerValueHelper(sco, input, index + 15, 15, SearchType::FileNameLengthEqual);
	}
	else if (input.find(L"FILENAMELENGTH<") != std::wstring::npos)
	{
		index = input.find(L"FILENAMELENGTH<");

		IntegerValueHelper(sco, input, index + 15, 15, SearchType::FileNameLengthLess);
	}
	else if (input.find(L"FILENAMELENGTH>") != std::wstring::npos)
	{
		index = input.find(L"FILENAMELENGTH>");

		IntegerValueHelper(sco, input, index + 15, 15, SearchType::FilenameLengthMore);
	}
	else if (input.find(L"FILEPATHLENGTH=") != std::wstring::npos)
	{
		index = input.find(L"FILEPATHLENGTH=");

		IntegerValueHelper(sco, input, index + 15, 15, SearchType::FilePathLengthEqual);
	}
	else if (input.find(L"FILEPATHLENGTH<") != std::wstring::npos)
	{
		index = input.find(L"FILEPATHLENGTH<");

		IntegerValueHelper(sco, input, index + 15, 15, SearchType::FilePathLengthLess);
	}
	else if (input.find(L"FILEPATHLENGTH>") != std::wstring::npos)
	{
		index = input.find(L"FILEPATHLENGTH>");

		IntegerValueHelper(sco, input, index + 15, 15, SearchType::FilePathLengthMore);
	}
}


void SearchUtility::ProcessExtensions(SearchCriteriaObject& sco, std::wstring input)
{
	std::wstring parameter = L"";
	std::wstring value = L"";
	TestType test = TestType::None;

	GetTokens(input, parameter, value, test);

	if (parameter == L"EXTENSION")
	{
		if (test == TestType::EqualTo)
		{
			std::transform(value.begin(), value.end(), value.begin(), ::toupper);

			sco.Type = SearchType::FileExtensionEqual;
			sco.StringValue = value;

			if (!sco.StringValue.empty())
			{
				if (sco.StringValue[0] != L'.')
				{
					sco.StringValue = L'.' + sco.StringValue;
				}
			}
		}
	}
}


void SearchUtility::ProcessExcludeFolder(SearchCriteriaObject& sco, std::wstring input)
{
	std::wstring parameter = L"";
	std::wstring value = L"";
	TestType test = TestType::None;

	GetTokens(input, parameter, value, test);

	if (parameter == L"EXCLUDEFOLDER")
	{
		if (test == TestType::EqualTo)
		{
			std::transform(value.begin(), value.end(), value.begin(), ::toupper);

			sco.Type = SearchType::FolderExclude;
			sco.StringValue = value;
		}
	}
}


void SearchUtility::ProcessIncludeFolder(SearchCriteriaObject& sco, std::wstring input)
{
	std::wstring parameter = L"";
	std::wstring value = L"";
	TestType test = TestType::None;

	GetTokens(input, parameter, value, test);

	if (parameter == L"INCLUDEFOLDER")
	{
		if (test == TestType::EqualTo)
		{
			std::transform(value.begin(), value.end(), value.begin(), ::toupper);

			sco.Type = SearchType::FolderInclude;
			sco.StringValue = value;
		}
	}
}


void SearchUtility::ProcessSearchTermCategory(SearchCriteriaObject& sco, std::wstring input)
{
	std::wstring parameter = L"";
	std::wstring value = L"";
	TestType test = TestType::None;

	GetTokens(input, parameter, value, test);

	switch (test)
	{
	case TestType::EqualTo:
		sco.Type = SearchType::Category;
		break;

	case TestType::NotEqualTo:
		sco.Type = SearchType::NotCategory;
		break;
	}

	try
	{
		sco.IntegerValue = std::stoi(value);
	}
	catch (...)
	{
		sco.IntegerValue = 1;
	}
}


void SearchUtility::ProcessSearchTermTypes(SearchCriteriaObject& sco, std::wstring input)
{
	for (int t = 0; t < SearchConstants::TypeTermCount; t++)
	{
		if (input.find(L'@' + SearchConstants::TypeTerms[t]) != std::wstring::npos)
		{
			if (input.back() == L'-')
			{
				sco.Type = SearchType::NotFileType;
			}
			else
			{
				sco.Type = SearchType::FileType;
			}

			sco.IntegerValue = SearchConstants::TypeValues[t];
		}
	}
}


void SearchUtility::IntegerValueHelper(SearchCriteriaObject& sco, std::wstring input, int from, int to, SearchType search_type)
{
	int value = -1;

	try
	{
		value = std::stoi(input.substr(from, input.length() - to));
	}
	catch (...)
	{

	}

	if (value != -1)
	{
		sco.Type = search_type;
		sco.IntegerValue = value;
	}
	else
	{
		sco.Type = SearchType::Error;
		//sco.error = XText[kInvalidInput] + ' "' + Copy(aInput, aFrom, length(aInput) - aTo) + '"'; to do
	}
}


// format
// lparameter ltest lvalue
// alphanumeric !=<>~ anything
// OR
// #x- #x
//
void SearchUtility::GetTokens(const std::wstring input, std::wstring& parameter, std::wstring& value, TestType& test_type)
{
	int mode = SearchConstants::ModeField;
	std::wstring test = L"";
	int position = 0;

	parameter.clear();
	value.clear();
	test_type = TestType::EqualTo;

	if (!input.empty())
	{
		if (input[0] == L'#')
		{
			parameter = L"CATEGORY";

			for (int t = 0; t < SearchConstants::CategoryTermCount; t++)
			{
				if (input.find(L'#' + SearchConstants::CategoryTerms[t]) != std::wstring::npos)
				{
				if (input.back() == L'-')
				{
					test_type = TestType::NotEqualTo;
				}
				else
				{
					test_type = TestType::EqualTo;
				}

				value = std::to_wstring(SearchConstants::CategoryValues[t]);
				}
			}
		}
		else if (input[0] == L'@')
		{
			parameter = L"ATTRIBUTES";

			for (int t = 0; t < SearchConstants::TypeTermCount; t++)
			{
				if (input.find(L'@' + SearchConstants::TypeTerms[t]) != std::wstring::npos)
				{
					if (input.back() == L'-')
					{
						test_type = TestType::NotEqualTo;
					}
					else
					{
						test_type = TestType::EqualTo;
					}

					value = std::to_wstring(SearchConstants::TypeValues[t]);
				}
			}
		}
		else
		{
			while (position < input.length())
			{
				switch (mode)
				{
				case SearchConstants::ModeField:
					if (isalpha(input[position]))
					{
						parameter = parameter + input[position];

						position++;
					}
					else
					{
						mode = SearchConstants::ModeTest;
					}

					break;

				case SearchConstants::ModeTest:
					if (Utility::IsTestCharacter(input[position]))
					{
						test += input[position];

						position++;
					}
					else
					{
						if (test == L"<" || test == L"<=" || test == L"=<")
						{
							test_type = TestType::LessThan;
						}
						else if (test == L"=" || test == L"==")
						{
							test_type = TestType::EqualTo;
						}
						else if (test == L">" || test == L">=" || test == L"=>")
						{
							test_type = TestType::GreaterThan;
						}
						else if (test == L"!=" || test == L"<>")
						{
							test_type = TestType::NotEqualTo;
						}
						else if (test == L"~")
						{
							test_type = TestType::Contains;
						}
						else if (test == L"!~" || test == L"~!")
						{
							test_type = TestType::NotContains;
						}

						mode = SearchConstants::ModeValue;
					}

					break;

				case SearchConstants::ModeValue:
					value += input[position];

					position++;

					break;
				}
			}
		}
	}
}


std::wstring SearchUtility::GetSearchText(int category)
{
	switch (category)
	{
	case kCategory_Program:
		return L"#PROG";
	case kCategory_System:
		return L"#SYS";
	case kCategory_Graphics:
		return L"#GFX";
	case kCategory_Movie:
		return L"#MOVIE";
	case kCategory_Sound:
		return L"#SOUND";
	case kCategory_Office:
		return L"#OFF";
	case kCategory_Code:
		return L"#COD";
	case kCategory_Compressed:
		return L"#COM";
	case kCategory_Other:
		return L"#OTH";
	case kCategory_Custom_1:
		return L"#C1";
	case kCategory_Custom_2:
		return L"#C2";
	case kCategory_Custom_3:
		return L"#C3";
	case kCategory_Custom_4:
		return L"#C4";
	case kCategory_Custom_5:
		return L"#C5";
	case kCategory_Custom_6:
		return L"#C6";
	case kCategory_Custom_7:
		return L"#C7";
	case kCategory_Custom_8:
		return L"#C8";
	case kCategory_Custom_9:
		return L"#C9";
	case kCategory_Custom_10:
		return L"#C10";
	case 20:
	case 99:
		return L"#CX";
	}

	return L"#PROG";
}


std::wstring SearchUtility::GetSearchAttribute(int attribute)
{
	switch (attribute)
	{
	case kFileType_System:
		return L"@SYSTEM";
	case kFileType_Hidden:
		return L"@HIDDEN";
	case kFileType_Archive:
		return L"@ARCHIVE";
	case kFileType_Null:
		return L"@NULL";
	case kFileType_ReadOnly:
		return L"@READONLY";
	case kFileType_Compressed:
		return L"@COMPRESSED";
	case kFileType_Encrypted:
		return L"@ENCRYPTED";
	case kFileType_CreatedToday:
		return L"@CREATED";
	case kFileType_AccessedToday:
		return L"@ACCESSED";
	case kFileType_ModifiedToday:
		return L"@MODIFIED";
	case kFileType_Temp:
		return L"@TEMP";
	case kFileType_Folder:
		return L"@FOLDER";
	case kFileType_File:
		return L"@FILE";
	case kFileType_RecallOnOpen:
		return L"@RECALLONOPEN";
	case kFileType_RecallOnDataAccess:
		return L"@RECALLONDATAACCESS";
	case kFileType_Virtual:
		return L"@VIRTUAL";
	}

	return L"@FILE";
}


std::wstring SearchUtility::GetSearchSize(int from_size, int from_unit, int to_size, int to_unit)
{
	std::wstring output = L"";

	if (from_size != -1)
	{
		output = L"(size>" + std::to_wstring(from_size) + GLanguageHandler->Units[from_unit] + L")";
	}

	if (to_size != -1)
	{
		if (!output.empty())
		{
			output += L" ";
		}

		output += L"(size<" + std::to_wstring(to_size) + GLanguageHandler->Units[to_unit] + L")";
	}

    return output;
}


std::wstring SearchUtility::XinorbisSearchToSQL(const std::wstring xdate, const std::wstring xfolder, const std::wstring xcomputer, const std::wstring xinsearch,
	int limitx, int limity, bool demomode)
{/*
 var
  SQLTerms : TStringList;
  t : integer;

  procedure GetSearchTerms(const xinsearch2 : string);
   var
    i : integer;
    s : string;
    reading : boolean;
    inside : boolean;

    function AddThisKeyword(const s : string): string;
     var
      ts : string;

     begin
      ts := ProcessSearchTermToSQL(s);

      if ts <> '' then
        SQLTerms.Add(ts);
    end;

   begin
    s       := '';
    reading := False;
    inside  := False;
    SQLTerms.Clear;

    for i := 1 to length(xinsearch2) do begin
      if xinsearch2[i] = '"' then begin
        if reading=False then
          reading := True
        else begin
          reading := False;

          AddThisKeyword(UpperCase(s));
          s := '';
        end;
      end
      else if xinsearch2[i] = '(' then
        inside := True
      else if xinsearch2[i] = ')' then
        inside := False
      else if (xinsearch2[i] = ' ') and not(inside) then begin
        if reading then
          s := s + ' '
        else begin
          if s <> '' then begin
            AddThisKeyword(UpperCase(s));
            s := '';
          end;
        end;
      end
      else begin
        s := s + xinsearch2[i];
      end;
    end;

    if s <> '' then AddThisKeyword(UpperCase(s));
  end;

  procedure GetODBCSpecificPreTerms(const xinsearch2 : string);
   var
    i : integer;
    s : string;
    reading : boolean;
    inside : boolean;

    function AddThisKeyword(const s : string): string;
     var
      ts : string;

     begin
      ts := ProcessSearchTermToSQLPostODBC(s);

      if ts <> '' then
        SQLTerms.Add(ts);
    end;

   begin
    s       := '';
    reading := False;
    inside  := False;
    SQLTerms.Clear;

    for i := 1 to length(xinsearch2) do begin
      if xinsearch2[i] = '"' then begin
        if reading = False then
          reading := True
        else begin
          reading := False;

          AddThisKeyword(UpperCase(s));
          s := '';
        end;
      end
      else if xinsearch2[i] = '(' then
        inside := True
      else if xinsearch2[i] = ')' then
        inside := False
      else if (xinsearch2[i] = ' ') and not(inside) then begin
        if reading then
          s:= S + ' '
        else begin
          if s <> '' then begin
            AddThisKeyword(UpperCase(s));
            s := '';
          end;
        end;
      end
      else begin
        s := s + xinsearch2[i];
      end;
    end;

    if s <> '' then AddThisKeyword(UpperCase(s));
  end;

  procedure GetPostTerms(const xinsearch2 : string);
   var
    i : integer;
    s : string;
    reading : boolean;
    inside : boolean;

    function AddThisKeyword(const s : string): string;
     var
      ts : string;

     begin
      ts := ProcessSearchTermToSQLPost(s);

      if ts <> '' then
        SQLTerms.Add(ts);
    end;

   begin
    s       := '';
    reading := False;
    inside  := False;
    SQLTerms.Clear;

    for i := 1 to length(xinsearch2) do begin
      if xinsearch2[i] = '"' then begin
        if reading = False then
          reading := True
        else begin
          reading := False;

          AddThisKeyword(UpperCase(s));
          s := '';
        end;
      end
      else if xinsearch2[i] = '(' then
        inside := True
      else if xinsearch2[i] = ')' then
        inside := False
      else if (xinsearch2[i] = ' ') and not(inside) then begin
        if reading then
          s := s + ' '
        else begin
          if s <> '' then begin
            AddThisKeyword(UpperCase(s));
            s := '';
          end;
        end;
      end
      else begin
        s := s + xinsearch2[i];
      end;
    end;

    if s <> '' then AddThisKeyword(UpperCase(s));
  end;

 begin
  if xinsearch <> '' then begin

    SQLTerms := TStringList.Create;

    // == now add required fields ==============================================

    Result := 'SELECT ';

    if XSettings.Database.UseODBC then begin
      GetODBCSpecificPreTerms(xinsearch);

      if SQLTerms.Count <> 0 then
        Result := Result + ' ' + SQLTerms[0];
    end;

    // == now add required fields ==============================================

    if demomode then
      Result := Result + ' *'
    else
      Result := Result + ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner';

    // =========================================================================

    Result := Result + ' FROM ';

    // =========================================================================

    if demomode then
      Result := Result + '$x$'
    else
      Result := Result + '"' + TConvert.CreateTableName(xdate, xfolder, xcomputer) + '"';

    // =========================================================================

    GetSearchTerms(xinsearch);

    if SQLTerms.Count <> 0 then begin
      Result := Result + ' WHERE ';

      for t := 0 to SQLTerms.Count - 1 do begin
        Result := Result + SQLTerms[t];

        if t <> SQLTerms.Count - 1 then
          Result := Result + ' AND ';
      end;
    end;

    // ===========================================================================

    GetPostTerms(xinsearch);

    if SQLTerms.Count <> 0 then begin
      Result := Result + ' ' + SQLTerms[0];
    end;

    // ===========================================================================

    SQLTerms.Free;

    if Pos(' LIMIT ', Result) = 0 then begin
      if XSettings.Database.UseODBC then
        Result := Result + ';'
      else
        Result := Result + ' LIMIT ' + IntToStr(limitx) + ', ' + IntToStr(limity) + ';';
    end;

    // ===========================================================================
  end; */

  return L"to do";
}


std::wstring SearchUtility::XinorbisSearchAllToSQL(const std::wstring xdate, const std::wstring xfolder, const std::wstring xcomputer, bool demomode)
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
