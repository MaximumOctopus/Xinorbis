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
#include <windows.h>

#include "Formatting.h"


namespace Formatting
{
	std::wstring AddLeading(std::wstring input, int length, char character)
	{
		if (input.length() == length)
		{
			return input;
		}
		else if (input.length() < length)
		{
			for (int t = input.length(); t < length; t++)
			{
				input.insert(input.begin(), character);
			}

			return input;
		}
		else
		{
			return input;
		}
	}


	std::wstring AddLeadingSpace(std::wstring input, int length)
	{
		if (input.length() == length)
		{
			return input;
		}
		else if (input.length() < length)
		{
			for (int t = input.length(); t < length; t++)
			{
				input.insert(input.begin(), L' ');
			}

			return input;
		}
		else
		{
			return input;
		}
	}


	std::wstring AddTrailing(std::wstring input, int length, char character)
	{
		if (input.length() == length)
		{
			return input;
		}
		else if (input.length() < length)
		{
			for (int t = input.length(); t < length; t++)
			{
				input += character;
			}

			return input;
		}
		else
		{
			return input; // to do (should trim)
		}
	}


	std::wstring MakeItalic(const std::wstring input, bool condition)
	{
		if (condition)
		{
			return L"<i>" + input + L"</i>";
		}
		else
		{
			return input;
		}
	}


	std::wstring InsertElement(const std::wstring name, std::wstring contents, int level)
	{
		std::wstring output(level * 2, L' ');

		return output + L"<" + name + L">" + contents + L"</" + name + L">";
	}


	std::wstring ReplaceEntitiesForXML(std::wstring content)
	{
		size_t pos = 0;

		std::wstring searchFor   = L"&";
		std::wstring replaceWith = L"&amp;";

		while ((pos = content.find(searchFor, pos)) != std::wstring::npos)
		{
			content.replace(pos, searchFor.length(), replaceWith);

			pos += replaceWith.length();
		}

		return content;
	}

	std::wstring ReplaceForJSON(std::wstring content)
	{
		size_t pos = 0;

		std::wstring searchFor = L"\\";
		std::wstring replaceWith = L"\\\\";

		while ((pos = content.find(searchFor, pos)) != std::wstring::npos)
		{
			content.replace(pos, searchFor.length(), replaceWith);

			pos += replaceWith.length();
		}

		return content;
	}


	std::wstring TrimFileNameForOutput(const std::wstring file_name)
	{
		return file_name;
	}


	std::wstring GetAttributeAsString(int attributes)
	{
		std::wstring output = L"....";

		if (FILE_ATTRIBUTE_ARCHIVE & attributes) output[0] = L'A';
		if (FILE_ATTRIBUTE_READONLY & attributes) output[1] = L'R';
		if (FILE_ATTRIBUTE_SYSTEM & attributes) output[2] = L'S';
		if (FILE_ATTRIBUTE_HIDDEN & attributes) output[3] = L'H';

		return output;
	}


	std::wstring StringOfCharacters(int count, std::wstring fill)
	{
		std::wstring output = L"";

		if (count != 0)
		{
			for (int t = 0; t < count; t++)
			{
				output += fill;
			}
		}

		return output;
	}


	// extension must be lowercase
	std::wstring AffixFileExtension(const std::wstring file_name, const std::wstring extension)
	{
		std::wstring f = file_name;
		std::transform(f.begin(), f.end(), f.begin(), ::tolower);

		if (f.find(extension) == std::wstring::npos)
		{
			return file_name + extension;
		}

		return file_name;
	}


	// utf8 output magic
	std::string to_utf8(const std::wstring& str)
	{
		return to_utf8x(str.c_str(), (int)str.size());
	}


	std::string to_utf8x(const wchar_t* buffer, int len)
	{
		int nChars = ::WideCharToMultiByte(
			CP_UTF8,
			0,
			buffer,
			len,
			NULL,
			0,
			NULL,
			NULL);
		if (nChars == 0) return "";

		std::string newbuffer;

		newbuffer.resize(nChars);
		::WideCharToMultiByte(
			CP_UTF8,
			0,
			buffer,
			len,
			const_cast<char*>(newbuffer.c_str()),
			nChars,
			NULL,
			NULL);

		return newbuffer;
	}
}