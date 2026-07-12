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
#include "SearchCriteriaObject.h"
#include "SearchUtility.h"
#include "Utility.h"


namespace SearchUtility
{
    SearchCriteriaObject ProcessSearchTerm(const std::wstring s)
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


    void ProcessSearchTermSize(SearchCriteriaObject& sco, std::wstring input)
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


    void ProcessSearchTermTime(SearchCriteriaObject& sco, std::wstring input)
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


    void ProcessSearchTermDate(SearchCriteriaObject& sco, std::wstring input)
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


    void ProcessSearchTermUser(SearchCriteriaObject& sco, std::wstring input)
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


    void ProcessSearchTermFNL(SearchCriteriaObject& sco, std::wstring input)
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


    void ProcessExtensions(SearchCriteriaObject& sco, std::wstring input)
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


    void ProcessExcludeFolder(SearchCriteriaObject& sco, std::wstring input)
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


    void ProcessIncludeFolder(SearchCriteriaObject& sco, std::wstring input)
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


    void ProcessSearchTermCategory(SearchCriteriaObject& sco, std::wstring input)
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


    void ProcessSearchTermTypes(SearchCriteriaObject& sco, std::wstring input)
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


    void IntegerValueHelper(SearchCriteriaObject& sco, std::wstring input, int from, int to, SearchType search_type)
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
    void GetTokens(const std::wstring input, std::wstring& parameter, std::wstring& value, TestType& test_type)
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
}