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

#include "SearchCriteriaObject.h"


SearchCriteriaObject::SearchCriteriaObject()
{

}


std::wstring SearchCriteriaObject::Debug()
{
	std::wstring output = L"";

	switch (Type)
	{
	case SearchType::None:
		output = L"None";
		break;
	case SearchType::Error:
		output = L"Error";
		break;
	case SearchType::SizeLess:
		output = L"SizeLess";
		break;
	case SearchType::SizeEqual:
		output = L"SizeEqual";
		break;
	case SearchType::SizeMore:
		output = L"SizeMore";
		break;
	case SearchType::Category:
		output = L"Category";
		break;
	case SearchType::DateLess:
		output = L"DateLess";
		break;
	case SearchType::DateMore:
		output = L"DateMore";
		break;
	case SearchType::DateEqual:
		output = L"DateEqual";
		break;
	case SearchType::FileType:
		output = L"FileType";
		break;
	case SearchType::ADateLess:
		output = L"ADateLess";
		break;
	case SearchType::ADateMore:
		output = L"ADateMore";
		break;
	case SearchType::ADateEqual:
		output = L"ADateEqual";
		break;
	case SearchType::MDateLess:
		output = L"MDateLess";
		break;
	case SearchType::MDateMore:
		output = L"MDateMore";
		break;
	case SearchType::MDateEqual:
		output = L"MDateEqual";
		break;
	case SearchType::UserName:
		output = L"UserName";
		break;
	case SearchType::NotUserName:
		output = L"NotUserName";
		break;
	case SearchType::NotCategory:
		output = L"NotCategory";
		break;
	case SearchType::NotFileType:
		output = L"NotFileType";
		break;
	case SearchType::ATimeLess:
		output = L"ATimeLess";
		break;
	case SearchType::ATimeMore:
		output = L"ATimeMore";
		break;
	case SearchType::ATimeEqual:
		output = L"ATimeEqual";
		break;
	case SearchType::MTimeLess:
		output = L"MTimeLess";
		break;
	case SearchType::MTimeMore: 
		output = L"MTimeMore";
		break;
	case SearchType::MTimeEqual:
		output = L"MTimeEqual";
		break;
	case SearchType::TimeLess:
		output = L"TimeLess";
		break;
	case SearchType::TimeMore:
		output = L"TimeMore";
		break;
	case SearchType::TimeEqual:
		output = L"TimeEqual";
		break;
	case SearchType::UserNameContains:
		output = L"UserNameContains";
		break;
	case SearchType::UserNameNotContains:
		output = L"UserNameNotContains";
		break;
	case SearchType::FileNameLengthEqual:
		output = L"FileNameLengthEqual";
		break;
	case SearchType::FileNameLengthLess:
		output = L"FileNameLengthLess";
		break;
	case SearchType::FilenameLengthMore:
		output = L"FilenameLengthMore";
		break;
	case SearchType::FilePathLengthEqual:
		output = L"FilePathLengthEqual";
		break;
	case SearchType::FilePathLengthLess:
		output = L"FilePathLengthLess";
		break;
	case SearchType::FilePathLengthMore:
		output = L"FilePathLengthMore";
		break;
	case SearchType::FileExtensionEqual:
		output = L"FileExtensionEqual";
		break;
	case SearchType::FolderExclude:
		output = L"FolderExclude";
		break;
	case SearchType::FolderInclude:
		output = L"FolderInclude";
		break;

	default:
		output = L"UnKnOwN!";
	}

	output += L"; " + StringValue + L"; " + std::to_wstring(IntegerValue);

	return output;
}