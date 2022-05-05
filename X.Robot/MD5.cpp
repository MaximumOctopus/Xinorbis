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


#include "MD5.h"
#include <string>
#include <Windows.h>
#include <wincrypt.h>
#include <windef.h>
#include <iostream>

namespace MD5
{
	std::wstring GetMD5HashString(char* pcValue)
	{
		BYTE *bytes = reinterpret_cast<BYTE *>(&pcValue[0]);
		DWORD byteLength = strlen(pcValue) * sizeof(pcValue[0]);

		HCRYPTPROV hCryptProvider;
		HCRYPTHASH hCryptHash;

		// Create provider and hash algorithm
		CryptAcquireContext(&hCryptProvider, nullptr, nullptr, PROV_RSA_FULL, 0);
		CryptCreateHash(hCryptProvider, CALG_MD5, 0, 0, &hCryptHash);

		// Hash the data    
		CryptHashData(hCryptHash, bytes, byteLength, 0);

		// Get back the hash value    
		BYTE hashBytes[128 / 8];
		DWORD paramLength = sizeof(hashBytes);
		CryptGetHashParam(hCryptHash, HP_HASHVAL, hashBytes, &paramLength, 0);

		// Cleanup
		CryptDestroyHash(hCryptHash);
		CryptReleaseContext(hCryptProvider, 0);

		DWORD base64Length = 0;

		// Figure out how much memory we need for the base64 string
		CryptBinaryToStringA(hashBytes, sizeof(hashBytes), CRYPT_STRING_HEXRAW, nullptr, &base64Length);

		char *pcMD5HashString = new char[base64Length];

		// Actually convert to base64
		CryptBinaryToStringA(hashBytes, sizeof(hashBytes), CRYPT_STRING_HEXRAW, pcMD5HashString, &base64Length);

		std::string output(pcMD5HashString);

		int size_needed = MultiByteToWideChar(CP_UTF8, 0, &output[0], (int)output.size(), NULL, 0);
		std::wstring outputHashed(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, &output[0], (int)output.size(), &outputHashed[0], size_needed);

		return outputHashed;
	}
}