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


#include "Errors.h"
#include "ErrorConstants.h"
#include <string>
#include <iostream>


namespace ErrorHandler
{
	std::wstring GetErrorString(int errorID)
	{
		switch (errorID)
		{
		case __ErrorScanFolderDoesNotExist:
			return L"Folder does not exist.";
			break;
		case __ErrorInstallationCheckFailed:
			return L"Installation check failed.";
			break;
		case __ErrorLanguageLoadFail:
			return L"LanguageHandler failed to load language file!";
			break;
		case __ErrorSettingsLoadFail:
			return L"Settings load failed";
			break;


		default:
			return L"Unknown Error";
		}
	}


	void OutputErrorConsole(int errorID)
	{
		std::wcout << L"" << std::endl;
		std::wcout << GetErrorString(errorID) << std::endl;
		std::wcout << L"" << std::endl;
	}
}