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
	std::wstring AddLeading(std::wstring aInput, int aLength, char aCharacter)
	{
		if (aInput.length() == aLength)
		{
			return aInput;
		}
		else if (aInput.length() < aLength)
		{
			for (int t = aInput.length(); t < aLength; t++)
			{
				aInput.insert(aInput.begin(), aCharacter);
			}

			return aInput;
		}
		else
		{
			return aInput;
		}
	}


	std::wstring AddTrailing(std::wstring aInput, int aLength, char aCharacter)
	{
		if (aInput.length() == aLength)
		{
			return aInput;
		}
		else if (aInput.length() < aLength)
		{
			for (int t = aInput.length(); t < aLength; t++)
			{
				aInput += aCharacter;
			}

			return aInput;
		}
		else
		{
			return aInput; // to do (should trim)
		}
	}


	std::wstring MakeItalic(std::wstring aInput, bool aCondition)
	{
		if (aCondition)
		{
			return L"<i>" + aInput + L"</i>";
		}
		else
		{
			return aInput;
		}
	}


	std::wstring InsertElement(std::wstring aName, std::wstring aContents, int aLevel)
	{
		std::wstring output(aLevel * 2, L' ');

		return output + L"<" + aName + L">" + aContents + L"</" + aName + L">";
	}


	std::wstring ReplaceEntitiesForXML(std::wstring aContent)
	{
		size_t pos = 0;

		std::wstring searchFor   = L"&";
		std::wstring replaceWith = L"&amp;";

		while ((pos = aContent.find(searchFor, pos)) != std::wstring::npos)
		{
			aContent.replace(pos, searchFor.length(), replaceWith);

			pos += replaceWith.length();
		}

		return aContent;
	}


	std::wstring TrimFileNameForOutput(std::wstring aFileName)
	{
		return aFileName;
	}
}