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

#include <fstream>

#include "ConstantsReports.h"
#include "Convert.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ScanEngine.h"
#include "TabUiMagnitude.h"

extern LanguageHandler *GLanguageHandler;
extern ScanEngine *GScanEngine;


bool TabUiMagnitude::AsText(const std::wstring file_name, int DataSource)
{
	std::ofstream file(file_name);

	if (file)
	{
		file << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
		file << Formatting::to_utf8(GLanguageHandler->TextReport[7] + L"\n");
		file << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");
		file << Formatting::to_utf8(GLanguageHandler->TextReport[2] + L"\n");
		file << Formatting::to_utf8(GLanguageHandler->TextReport[0] + L"\n");

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			for (int t = 0; t < kMagnitudesCount; t++)
			{
				std::wstring s = Formatting::AddTrailing(L" " + kMagnitudeLabels[t], 25, L' ');

				s += Formatting::AddLeading(std::to_wstring(GScanEngine->Data[DataSource].Magnitude[t].Count), 8, L' ');
				s += Formatting::AddLeading(GScanEngine->Data[DataSource].Magnitude[t].PercentCountString, 6, L' ');
				s += Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].Magnitude[t].Size), 11, L' ');

				s += Formatting::AddLeading(GScanEngine->Data[DataSource].Magnitude[t].PercentSizeString, 6, L' ');

				file << Formatting::to_utf8(s + L"\n");
			}
		}

		file << Formatting::to_utf8(GLanguageHandler->Text[kFavourite] + L"\n");
		file << Formatting::to_utf8(L"\n");

		file.close();

		return true;
	}

	return false;
}
