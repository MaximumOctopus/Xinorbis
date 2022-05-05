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
// February 13th 2019
//


#pragma once


namespace Test
{
	void RunTest();

	bool CustomIni();
	bool CheckScanFolder();
	bool CheckInstallationFolder();
	bool ParameterChain();
	bool Reports();
	bool Database();
	bool Scan();

	std::wstring CSVOptions(int option, wchar_t value);
	std::wstring HTMLOptions(int option, wchar_t value);
	std::wstring TextOptions(int option, wchar_t value);
	std::wstring XMLOptions(int option, wchar_t value);
}