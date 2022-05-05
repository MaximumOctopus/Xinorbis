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


#include "Convert.h"
#include "FolderHistoryHandler.h"
#include "SystemGlobal.h"
#include "MD5.h"
#include "ScanDetails.h"
#include "Utility.h"
#include "WindowsUtility.h"
#include <algorithm>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>


extern ScanDetails* GScanDetails;
extern SystemGlobal* GSystemGlobal;


FolderHistoryHandler::FolderHistoryHandler()
{

}


bool FolderHistoryHandler::UpdateFolderHistoryFile()
{
	std::wstring MD5 = Utility::GetMD5(GScanDetails->ScanPath);

	std::wcout << L"    \\" + MD5 + L".xfh" << std::endl;

	std::wstring lFileName = GSystemGlobal->UsersPath + L"FolderHistory\\" + WindowsUtility::GetComputerNetName() + L"\\" + MD5 + L".xfh";

	std::wofstream file(lFileName, std::ofstream::app);

	file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

	if (file)
	{
		file << L"{" << std::endl;
		file << L"SYS:X.Robot " + __XRVersion << std::endl;
		file << L"DAT:" + GScanDetails->ScanDateStr << std::endl;
		file << L"DAX:" + GScanDetails->ScanDateInt << std::endl;
		file << L"FIC:" + std::to_wstring(GScanDetails->FileCount) << std::endl;
		file << L"FIS:" + std::to_wstring(GScanDetails->TotalSize) << std::endl;
		file << L"FOC:" + std::to_wstring(GScanDetails->FolderCount) << std::endl;
		file << L"SOD:" + std::to_wstring(GScanDetails->TotalSizeOD) << std::endl;

		for (int t = 0; t < __FileCategoriesCount; t++)
		{
			file << L"X" + Convert::IntToHex(t, 2) + L":" + std::to_wstring(GScanDetails->ExtensionSpread[t][__esCount]) << std::endl;
			file << L"Y" + Convert::IntToHex(t, 2) + L":" + std::to_wstring(GScanDetails->ExtensionSpread[t][__esSize]) << std::endl;
		}

		for (int t = 0; t < __FileCategoriesCount; t++)
		{
			file << L"M" + Convert::IntToHex(t, 1) + L"C:" + std::to_wstring(GScanDetails->Magnitude[t][__mCount]) << std::endl;
			file << L"M" + Convert::IntToHex(t, 1) + L"S:" + std::to_wstring(GScanDetails->Magnitude[t][__mSize]) << std::endl;
		} 

		file << L"}" << std::endl;

		return true;
	}
	else
	{
		std::wcout << L"Failed to modify File History file :(" << std::endl;
	}

	return false;
}
