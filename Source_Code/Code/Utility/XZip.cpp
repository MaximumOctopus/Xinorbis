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

#include <System.Zip.hpp>

#include "XZip.h"

XZip *GXZip;


XZip::XZip()
{

}


bool XZip::Files(const std::wstring file_name, std::vector<std::wstring> &data, const std::wstring message)
{
	TZipFile *zippy = new TZipFile();

	zippy->Open(file_name.c_str(), zmWrite);

	for (std::wstring s : data)
	{
		zippy->Add(s.c_str());
	}

	zippy->Close();

	delete zippy;

	return true;
}


bool XZip::Folder(const std::wstring file_name, const std::wstring folder)
{
	TZipFile *zippy = new TZipFile();

	zippy->Open(file_name.c_str(), zmWrite);

	zippy->AddDirectory(folder.c_str());

	zippy->Close();

	delete zippy;

	return true;
}
