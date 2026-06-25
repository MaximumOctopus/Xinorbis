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


#include <string>


enum class SearchType {
	None = 0, Error = 1,
	SizeLess = 2, SizeEqual = 3, SizeMore = 4,
	Category = 5,
	DateLess = 6, DateMore = 7, DateEqual = 8,
	FileType = 9,
	ADateLess = 10, ADateMore = 11, ADateEqual = 12,
	MDateLess = 13, MDateMore = 14, MDateEqual = 15,
	UserName = 16,
	NotUserName = 17,
	NotCategory = 18,
	NotFileType = 19,
	ATimeLess = 20, ATimeMore = 21, ATimeEqual = 22,
	MTimeLess = 23, MTimeMore = 24, MTimeEqual = 25,
	TimeLess = 26, TimeMore = 27, TimeEqual = 28,
	UserNameContains = 29, UserNameNotContains = 30,
	FileNameLengthEqual = 31, FileNameLengthLess = 32, FilenameLengthMore = 33, FilePathLengthEqual = 34, FilePathLengthLess = 35, FilePathLengthMore = 36,
	FileExtensionEqual = 37,
	FolderExclude = 38, FolderInclude = 39
};

enum class TestType { None = 0, LessThan = 1, EqualTo = 2, GreaterThan = 3, NotEqualTo = 4, Contains = 5, NotContains = 6 };


class SearchCriteriaObject
{

public:

	SearchType Type = SearchType::None;
	std::wstring StringValue = L"";
	int IntegerValue = 0;

	std::wstring error = L"";

	SearchCriteriaObject();

	std::wstring Debug();
};