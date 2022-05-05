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
// June 6th 2020
//


#include "Constants.h"
#include "Utility.h"
#include "VersionCheck.h"
#include <codecvt>
#include <iostream> 
#include <stdio.h>
#include <string>
#include <urlmon.h>
#include <windows.h>

#pragma comment(lib, "urlmon.lib")


// download the file as UTF-8, copy it to the 8-bit buffer (lpResult), then
// smash it out to the versionInfo wide string using built-in conversion routines
// http://www.rohitab.com/discuss/topic/28719-downloading-a-file-winsock-http-c/page-2
bool VersionCheck::IsNewVersion(std::wstring currentVersion)
{
    // avoid caching issues by adding time as a parameter
    std::wstring url = L"http://maximumoctopus.com/versions/xrobot.php?" + Utility::GetTime(__GETTIMEFORMAT_FILE);

    LPSTR lpResult = NULL; // download buffer
    LPSTREAM lpStream;

    std::wstring versionInfo;

    std::wcout << L"Getting X.Robot version information from MaximumOctopus.com... " << std::endl << std::endl;

    if(SUCCEEDED(CoInitialize(NULL))) {

        if (SUCCEEDED(URLOpenBlockingStream(NULL, url.c_str(), &lpStream, 0, NULL))) {

            STATSTG statStream;
            if (SUCCEEDED(lpStream->Stat(&statStream, STATFLAG_NONAME))) {

                DWORD dwSize = statStream.cbSize.LowPart + 1;
                lpResult = (LPSTR)malloc(dwSize);

                if (lpResult) {
                    LARGE_INTEGER liPos;
                    ZeroMemory(&liPos, sizeof(liPos));
                    ZeroMemory(lpResult, dwSize);
                    lpStream->Seek(liPos, STREAM_SEEK_SET, NULL);
                    lpStream->Read(lpResult, (dwSize) - 1, NULL);
                }
                
                lpStream->Release();

                std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
                versionInfo = myconv.from_bytes(lpResult);

                free(lpResult);

                if (versionInfo.find(__XRVersion) == std::wstring::npos)
                {
                    std::wcout << L"New version available!" << std::endl << std::endl << std::endl;                    
                    std::wcout << L"This version        : " << __XRDate << L", " << __XRVersion << std::endl;
                    std::wcout << L"Most recent version : " << versionInfo << std::endl;
                }
                else
                {
                    std::wcout << L"Your version is up-to-date." << std::endl << std::endl;
                    std::wcout << L"This version        : " << __XRDate << L", " << __XRVersion << std::endl;
                    std::wcout << L"Most recent version : " << versionInfo << std::endl;
                }
            }
            else
            {
                std::wcout << L"... error with download." << std::endl;
            }
        }
        else
        {
            std::wcout << L"... error downloading version file." << std::endl;
        }

        CoUninitialize();
    }

    std::wcout << std::endl;

    return true;
}