//
// X.Robot 4.0 :: C++ rewrite
//
// (c) Paul Alan Freshney 2019-2020
//     Maximum Octopus Limited
//
// xinorbis.com
// maximumoctopus.com
// 
// twitter.com/maximumoctopus
//
//
// January 30th 2019
//


#include <string>


namespace Formatting
{
	std::wstring AddLeading(std::wstring aInput, int aLength, char aCharacter);
	std::wstring AddTrailing(std::wstring aInput, int aLength, char aCharacter);
	std::wstring MakeItalic(std::wstring aInput, bool aCondition);
	std::wstring InsertElement(std::wstring aName, std::wstring aContents, int aLevel);
	std::wstring ReplaceEntitiesForXML(std::wstring aContent);
	std::wstring TrimFileNameForOutput(std::wstring aFileName);
}