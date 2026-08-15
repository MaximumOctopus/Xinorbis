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

#include <string>
#include <tchar.h>

#include "ConstantsData.h"
#include "ConstantsGui.h"
#include "ConstantsParameters.h"
#include "ConstantsReports.h"
#include "ConstantsSystem.h"
#include "Ini.h"
#include "Registry.h"
#include "SettingsHandler.h"
#include "SystemGlobal.h"
#include "WindowsUtility.h"

SettingsHandler *GSettingsHandler;

extern SystemGlobal* GSystemGlobal;


SettingsHandler::SettingsHandler()
{
	Custom.SettingsSaveLocation  = SettingsSource::Registry;

	//if (LoadCustomSettings())
   //	{
	System.Loaded = Load();
  //	}

	SetupFormat();
}


void SettingsHandler::SetupFormat()
{
	GetLocaleFormatSettings(0, XinorbisFormat);

	XinorbisFormat.ShortDateFormat = L"dd/MM/yyyy";
}


void SettingsHandler::SetDefaults()
{
	Optimisations.ProcessData    = true;
	Optimisations.GetTempFiles   = false;
	Optimisations.GetUserDetails = false;

	Optimisations.ProgressUpdate = false;
}


bool SettingsHandler::SaveDefaults()
{
	// ===========================================================================
	// ===========================================================================
	// == Initialise                                                            ==
	// ===========================================================================
	// ===========================================================================

	if (OpenSettings(true))
	{
		// ===========================================================================
		// ===========================================================================
		// == Language                                                              ==
		// ===========================================================================
		// ===========================================================================

		WriteInteger(L"Prefs", L"Language", LanguageToInt(LanguageType::kUndefined));

		// ===========================================================================
		// ===========================================================================
		// == Save Settings                                                         ==
		// ===========================================================================
		// ===========================================================================

		WriteInteger(L"Prefs", L"Main_Top",      5);
		WriteInteger(L"Prefs", L"Main_Left",     5);
		WriteInteger(L"Prefs", L"Main_Width", 1016);
		WriteInteger(L"Prefs", L"Main_Height", 700);

		WriteBool(L"Prefs", L"Tutorial", true);

		WriteString(L"Prefs", L"Main_Path", State.LastScanPath);
		WriteString(L"Main", L"DataPath", State.DataPath);

		// ===========================================================================
		// == Chart Options                                                         ==
		// ===========================================================================

		//  WriteIntegerToSettings(L"Prefs", L"Prefs_ChartStyle" + std::to_wstring(t),  DefaultChartStyles[t]);

		WriteInteger(L"Prefs", L"Prefs_ChartX8_a", 0x00333333);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_b", 0x00333333);
		WriteBool(L"Prefs", L"Prefs_ChartX8_c", false);

		WriteInteger(L"Prefs", L"Prefs_ChartX8_d", 100);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_e", 0);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_f", 0x00FFFFFF);
		WriteBool(L"Prefs", L"Prefs_ChartX8_g", true);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_h",   2);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_i", 315);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_j",   0);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_k",   0);
		WriteBool(L"Prefs", L"Prefs_ChartX8_m", true);

		WriteInteger(L"Prefs", L"Prefs_ChartX8_l", 0x00FFFFFF);

		// ===========================================================================
		// == File History                                                          ==
		// ===========================================================================

		for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				WriteBool(L"FHCompare", L"X" + std::to_wstring(x + 1) + L"Y" + std::to_wstring(y + 1), false);
			}
		}

		// ===========================================================================
		// ==  navigation colours                                                   ==
		// ===========================================================================

		WriteInteger(L"Prefs", L"NavColour1", 0x00EEEEEE);
		WriteInteger(L"Prefs", L"NavColour2", 0x00FF4422);
		WriteInteger(L"Prefs", L"NavColour3", 0x00EEEEEE);
		WriteInteger(L"Prefs", L"NavColour4", 0x00FF44FF);
		WriteInteger(L"Prefs", L"NavColour5", 0x00DEDDFF);
		WriteInteger(L"Prefs", L"NavColour6", 0x005603F1);

		// ===========================================================================
		// == Tab Display Options                                                   ==
		// ===========================================================================

		for (int t = 0; t < 4; t++)
		{
			WriteString(L"Prefs", L"TabDisplayOptions" + std::to_wstring(t), L"011111111111111111111");
		}

		for (int t = 0; t < 2; t++)
		{
			WriteString(L"Prefs", L"NavigateDisplayOptions" + std::to_wstring(t), L"11111111111111111111");
		}

		// ===========================================================================
		// == FTP                                                                   ==
		// ===========================================================================

		for (int t = 1; t <= kFTPOptionsCount; t++)
		{
			WriteString(L"Prefs", L"ftpOptions" + std::to_wstring(t), L"");
		}

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		WriteBool(L"Prefs", L"JustInTimeDisplay", true);
		WriteInteger(L"Prefs", L"ProgressUpdate", 1);

		WriteBool(L"Prefs", L"AddToDate", false);
		WriteBool(L"Prefs", L"AddToDateLimit", false);
		WriteInteger(L"Prefs", L"AddToDateLimitCount", 1000);

		WriteBool(L"Prefs", L"BuildDateTree", false);
		WriteBool(L"Prefs", L"GetUserDetails", false);
		WriteBool(L"Prefs", L"GetTempFiles", false);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		WriteInteger(L"Prefs", L"TableBandColour",  0x00F9FFF9);
		WriteInteger(L"Prefs", L"RowHeight",        17);

		WriteInteger(L"Prefs", L"DateFormat",       0);
		WriteInteger(L"Prefs", L"MaxSearchResults", 20000);

		WriteString(L"Prefs", L"CustomViewer", L"notepad.exe");
		WriteBool(L"Prefs", L"SaveLog", false);

		WriteInteger(L"Prefs", L"PostScanMode", kPostScanSummary);
		WriteInteger(L"Prefs", L"PostScanIPPage",   0);

		WriteInteger(L"Prefs", L"HandleMultipleExt", 0);
		WriteBool(L"Prefs", L"Prefs_ASMode",     false);
		WriteBool(L"Prefs", L"Prefs_ASOrganise", false);

		for (int t = 1; t <= kAutoSaveItemCount; t++)
		{
			WriteBool(L"Prefs", L"Prefs_AutoSaveDrive" + std::to_wstring(t), false);
		}

		WriteBool(L"Prefs", L"Prefs_AutoCheckUpdate", true);

		WriteString(L"Prefs", L"Prefs_HTMLOutput", L"");
		WriteString(L"Prefs", L"Prefs_HTMLCompareOutput", L"");
		WriteString(L"Prefs", L"Prefs_XMLOutput", L"notepad");
		WriteString(L"Prefs", L"Prefs_TextOutput", L"notepad");

		for (int t = 1; t < kReportTypeCount; t++)
		{
			WriteInteger(L"Prefs", L"Prefs_CSVData" + std::to_wstring(t), kDataSummary);
			WriteInteger(L"Prefs", L"Prefs_CSVUnits" + std::to_wstring(t), 0);
			WriteBool(L"Prefs", L"Prefs_CSVTitles" + std::to_wstring(t), True);
			WriteInteger(L"Prefs", L"Prefs_CSVSeparator" + std::to_wstring(t), 0);

			WriteInteger(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_HTMLUnits",    0);
			WriteString(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_Layout", L"     0:1:2:3:4:5:6:7:8:9:12:13:14:15:16:");
			WriteString(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_CategoryList", L"1111111111111111111");
			WriteInteger(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_LayoutSize",   3);

			WriteString(L"Prefs", L"TextOptions" + std::to_wstring(t) + L"_Layout", L"1:2:3:4:5:6:7:8:9:12:13:14:");
			WriteString(L"Prefs", L"TextOptions" + std::to_wstring(t) + L"_CategoryList", L"1111111111111111111");

			WriteString(L"Prefs", L"TreeOptions" + std::to_wstring(t) + L"_Layout", L"1:");
			WriteString(L"Prefs", L"TreeOptions" + std::to_wstring(t) + L"_CategoryList", L"1111111111111111111");
			WriteBool(L"Prefs", L"TreeOptions" + std::to_wstring(t) + L"_IncludeSize", True);
			WriteBool(L"Prefs", L"TreeOptions" + std::to_wstring(t) + L"_IncludeAttributes", False);

			WriteString(L"Prefs", L"XMLOptions" + std::to_wstring(t) + L"_Layout", L"1:2:3:4:5:6:7:8:9:12:13:14:");
			WriteInteger(L"Prefs", L"Prefs_XMLData" + std::to_wstring(t) + L"_Data", kDataSummary);
			WriteBool(L"Prefs", L"Prefs_XMLData" + std::to_wstring(t) + L"_Open",    False);

			WriteInteger(L"Prefs", L"XinorbisOptions" + std::to_wstring(t) + L"_Layout",  0);

			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour1",  0x990000);  // link normal
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour2",  0x000000);  // link hover
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour3",  0xFFFFFF);  // background colour
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour4",  0x990000);  // text colour
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour5",  0x0000FF);  // bargraph colour
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour6",  0xFF9900);  // table background
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour7",  0xFFFFFF);  // table colour1
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour8",  0x000000);  // table colour2
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour9",  0xFFFFFF);  // graph background
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour10", 0xDDDDDD);  // table body background
			WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour11", 0xCCCCCC);  // table body background II
		}

		WriteInteger(L"Prefs", L"HTMLCompareOptions" + std::to_wstring(1) + L"_HTMLUnits", 0);
		WriteString(L"Prefs", L"HTMLCompareOptions" + std::to_wstring(1) + L"_Layout", L"0:1:2:3:4:");

		WriteString(L"Prefs", L"SummarayLayout", L"1:2:3:4:5:6:7:8:9:");

		// ===========================================================================
		// ==  History                                                              ==
		// ===========================================================================

		WriteBool(L"Prefs", L"Prefs_HistorySettings_Enabled",     True);
		WriteBool(L"Prefs", L"Prefs_HistorySettings_FullLogging", True);
		WriteBool(L"Prefs", L"Prefs_HistorySettings_SQLinSearch", False);

		for (int t = 0; t < kFileCategoriesCount; t++)
		{
			WriteInteger(L"Prefs", L"ChartColour" + std::to_wstring(t + 1), kDefaultDisplayColours[t]);
		}

		// ===========================================================================
		// == Quick Folders                                                         ==
		// ===========================================================================

		for (int t = 0; t < kQuickFolderCount; t++)
		{
			WriteString(L"Prefs", L"Prefs_QuickFolder" + std::to_wstring(t + 1), L"");
		}

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		for (int t = 0; t < 10; t++)
		{
			WriteString(L"TypeDescriptions", L"TypeDescriptions" + std::to_wstring(t + 1), DefaultExtensionFileName[t + 10]);
		}

		// ===========================================================================
		// == Close                                                                 ==
		// ===========================================================================

		CloseSettings();

		// ===========================================================================
		// == Forms
		// ===========================================================================

		ClearFormDetails(kFormFileSpread);
		ClearFormDetails(kFormReference);
		ClearFormDetails(kFormReport);
		ClearFormDetails(kFormInfoDatabase);
		ClearFormDetails(kFormExplore);
		ClearFormDetails(kFormFileAges);
		ClearFormDetails(kFormCombine);
		ClearFormDetails(kFormDeplicates);
		ClearFormDetails(kFormDuplicates);
		ClearFormDetails(kFormReportsList);
		ClearFormDetails(kFormSearchSyntax);

		ClearFormDetails(kFormEditHTMLReport);
		ClearFormDetails(kFormEditTextReport);
		ClearFormDetails(kFormEditTreeReport);
		ClearFormDetails(kFormEditXMLReport);
		ClearFormDetails(kFormEditCSVReport);

		// ===========================================================================
		// ===========================================================================

		return true;
	}

	return false;
}


void SettingsHandler::ProcessProcessingSetting(ParameterOption option)
{
	switch (option)
	{
	case ParameterOption::NoUsers:
		Optimisations.GetUserDetails = false;
		break;
	case ParameterOption::NoProcess:
		Optimisations.ProcessData = false;
		break;
	case ParameterOption::NoTemp:
		Optimisations.GetTempFiles = false;
		break;
	}
}

bool SettingsHandler::OpenSettings(bool read_only)
{
    if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
    {
		__iniFile = new Ini(GSystemGlobal->ExePath + L"custom.ini");

		if (__iniFile->Loaded)
		{
			return true;
		}
	}
	else
	{
		if (read_only)
		{
			LONG dwRet;

			if (Registry::Open(hKey, L"software\\" + __XRegistryPath, true) != ERROR_SUCCESS)
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}

	return false;
}


bool SettingsHandler::CloseSettings()
{
    if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
    {
		delete __iniFile;

		return true;
    }
    else
    {
        RegCloseKey(hKey);

        hKey = NULL;

		return true;
    }
}


bool SettingsHandler::LoadCustomSettings()
{
	if (WindowsUtility::FileExists(GSystemGlobal->ExePath + L"custom.ini"))
	{
		std::unique_ptr<Ini> IniFile = std::make_unique<Ini>(GSystemGlobal->ExePath + L"custom.ini");

		if (IniFile->Loaded)
		{
			int pcm = IniFile->ReadInteger(L"Main", L"PortableMode", 0);

			if (pcm == 1)
			{
				Custom.SettingsSaveLocation = SettingsSource::ConfigIni;

				//GLog->Add( << L"Portable mode active (from custom.ini).\n";
			}
		}
	}

	return true;
}


bool SettingsHandler::Load()
{
	// ===========================================================================
    // ===========================================================================
    // == Initialise                                                            ==
    // ===========================================================================
    // ===========================================================================

	if (OpenSettings(true))
	{
		// =====================================================================
		// =====================================================================
		// == Load Settings                                                   ==
		// =====================================================================
		// =====================================================================

		FDMain.X      = ReadInteger(L"Prefs", L"Main_Top", 5, -1);
		FDMain.Y      = ReadInteger(L"Prefs", L"Main_Left", 5, -1);
		FDMain.Width  = ReadInteger(L"Prefs", L"Main_Width", 1016, 1016);
		FDMain.Height = ReadInteger(L"Prefs", L"Main_Height", 700, 700);

		System.Tutorial = ReadBool(L"Prefs", L"Tutorial", true);

		//

		for (int r = 0; r < kReportTypeCount; r++)
		{
			Reports.CSV[r].Data      = ReadIntegerInputCheck(L"Prefs", L"Prefs_CSVData" + std::to_wstring(r), kDataFileList, kDataSummary, kDataFileList);
			Reports.CSV[r].Units     = ReadIntegerInputCheck(L"Prefs", L"Prefs_CSVUnits" + std::to_wstring(r), 0, 0, 3);
			Reports.CSV[r].Titles    = ReadBool(L"Prefs", L"Prefs_CSVTitles" + std::to_wstring(r), true);
			Reports.CSV[r].Separator = ReadIntegerInputCheck(L"Prefs", L"Prefs_CSVSeparator" + std::to_wstring(r), 0, 0, 1);
			Reports.CSV[r].AutoOpen  = false;

			Reports.HTML[r].Units        = ReadIntegerInputCheck(L"Prefs", L"HTMLOptions" + std::to_wstring(r) + L"_HTMLUnits", 0, 0, 3);
			Reports.HTML[r].Layout       = ReadString(L"Prefs", L"HTMLOptions" + std::to_wstring(r) + L"_Layout", L"0:1:2:3:4:5:6:7:8:9:12:13:14:15:16:17:");
			Reports.HTML[r].LayoutSize   = ReadIntegerInputCheck(L"Prefs", L"HTMLOptions" + std::to_wstring(r) + L"_LayoutSize", 3, 1, 3);
			Reports.HTML[r].LoadCategoryList(ReadString(L"Prefs", L"HTMLOptions" + std::to_wstring(r) + L"_CategoryList", L"1111111111111111111"));

			Reports.HTML[r].Colours.Colour[0]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour1" , 0x990000, -1);  // link normal
			Reports.HTML[r].Colours.Colour[1]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour2" , 0x000000, -1);  // link hover
			Reports.HTML[r].Colours.Colour[2]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour3",  0xFFFFFF, -1);  // background colour
			Reports.HTML[r].Colours.Colour[3]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour4",  0x990000, -1);  // text colour
			Reports.HTML[r].Colours.Colour[4]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour5",  0x0000FF, -1);  // bargraph colour
			Reports.HTML[r].Colours.Colour[5]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour6",  0xFF9900, -1);  // table background
			Reports.HTML[r].Colours.Colour[6]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour7",  0xFFFFFF, -1);  // table colour1
			Reports.HTML[r].Colours.Colour[7]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour8",  0x000000, -1);  // table colour2
			Reports.HTML[r].Colours.Colour[8]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour9",  0xFFFFFF, -1);  // graph background
			Reports.HTML[r].Colours.Colour[9]  = ReadInteger(L"Prefs", L"Prefs_HTMLColour10", 0xDDDDDD, -1);  // table body background
			Reports.HTML[r].Colours.Colour[10] = ReadInteger(L"Prefs", L"Prefs_HTMLColour11", 0xCCCCCC, -1);  // table body background II

			Reports.Text[r].Layout = ReadString(L"Prefs", L"TextOptions" + std::to_wstring(r) + L"_Layout", L"1:2:3:4:5:6:7:8:9:12:13:14:15:");
			Reports.Text[r].LoadCategoryList(ReadString(L"Prefs", L"TextOptions" + std::to_wstring(r) + L"_CategoryList", L"1111111111111111111"));

			Reports.Tree[r].Layout            = ReadString(L"Prefs", L"TreeOptions" + std::to_wstring(r) + L"_Layout", L"1:");
			Reports.Tree[r].IncludeSize       = ReadBool(L"Prefs",   L"TreeOptions" + std::to_wstring(r) + L"_IncludeSize", true);
			Reports.Tree[r].IncludeAttributes = ReadBool(L"Prefs",   L"TreeOptions" + std::to_wstring(r) + L"_IncludeAttributes", false);
			Reports.Tree[r].LoadCategoryList(ReadString(L"Prefs", L"TreeOptions" + std::to_wstring(r) + L"_CategoryList", L"1111111111111111111"));

			Reports.XML[r].Layout   = ReadString(L"Prefs", L"XMLOptions" + std::to_wstring(r) + L"_Layout",  L"1:2:3:4:5:6:7:8:9:12:13:14:15:");
			Reports.XML[r].Data     = ReadIntegerInputCheck(L"Prefs", L"Prefs_XMLData" + std::to_wstring(r) + L"_Data", kDataFileList, kDataSummary, kDataFileList);
			Reports.XML[r].AutoOpen = ReadBool(L"Prefs", L"Prefs_XMLData" + std::to_wstring(r) + L"_Open", false);

			Reports.Xinorbis[r].Layout = ReadInteger(L"Prefs", L"XinorbisOptions" + std::to_wstring(r) + L"_Layout",  0, -1);
		}

		Reports.Summary.Layout = ReadString(L"Prefs", L"SummarayLayout", L"1:2:3:4:5:6:7:8:9:10:");

		Reports.CSVCommand = ReadString(L"Prefs", L"Prefs_CSVOutput", L"");
		Reports.DateCommand = ReadString(L"Prefs", L"Prefs_DateVOutput", L"");
		Reports.HTMLCommand = ReadString(L"Prefs", L"Prefs_HTMLOutput", L"");
		Reports.JSONCommand = ReadString(L"Prefs", L"Prefs_JSONOutput", L"");
		Reports.SummaryCommand = ReadString(L"Prefs", L"Prefs_SummaryOutput", L"");
		Reports.TextCommand = ReadString(L"Prefs", L"Prefs_TextOutput", L"");
		Reports.TreeCommand = ReadString(L"Prefs", L"Prefs_TreeOutput", L"");
		Reports.XinorbisCommand = ReadString(L"Prefs", L"Prefs_XinorbisOutput", L"");
		Reports.XMLCommand = ReadString(L"Prefs", L"Prefs_XMLOutput", L"");

		Reports.HTMLCompareCommand = ReadString(L"Prefs", L"Prefs_HTMLCompareOutput", L"");

		Reports.HTMLCompare.Units  = ReadIntegerInputCheck(L"Prefs", L"HTMLCompareOptions1_HTMLUnits", 0, 0, 3);
		Reports.HTMLCompare.Layout = ReadString(L"Prefs", L"HTMLCompareOptions1_Layout", L"0:1:2:3:4:");

		Reports.AutoSaveMode = ReadBool(L"Prefs", L"Prefs_ASMode", false);
		Reports.AutoSaveOrganise = ReadBool(L"Prefs", L"Prefs_ASOrganise", false);

		for (int t = 0; t < kAutoSaveItemCount; t++)
		{
			Reports.AutoSaveItem[t] = ReadBool(L"Prefs", L"Prefs_AutoSaveDrive" + std::to_wstring(t + 1), false);
		}

		// =====================================================================
		// == Chart Options                                                   ==
		// =====================================================================

		//Charts.Options.ChartStyles   = ReadIntegerFromSettingsInputCheck(L"Prefs", L"Prefs_ChartStyle", DefaultChartStyles[t], 0, 1);

		Chart.ChartFrom     = ReadInteger(          L"Prefs", L"Prefs_ChartX8_a", 0x00333333, -1); // check
		Chart.ChartTo       = ReadInteger(          L"Prefs", L"Prefs_ChartX8_b", 0x00333333, -1);
		Chart.ChartGradient = ReadBool(             L"Prefs", L"Prefs_ChartX8_c", false);

		Chart.Zoom          = ReadIntegerInputCheck(L"Prefs", L"Prefs_ChartX8_d", 100, 0, 150);
		Chart.Explode       = ReadIntegerInputCheck(L"Prefs", L"Prefs_ChartX8_e", 0, 0, 150);
		Chart.MarkColour    = ReadInteger(          L"Prefs", L"Prefs_ChartX8_f", 0x00FFFFFF, -1);
		Chart.ShowMarks     = ReadBool(             L"Prefs", L"Prefs_ChartX8_g", true);
		Chart.MarksType     = ReadIntegerInputCheck(L"Prefs", L"Prefs_ChartX8_h", 2, 0, 4);
		Chart.Elevation     = ReadIntegerInputCheck(L"Prefs", L"Prefs_ChartX8_i", 315, 315, 315);
		Chart.LabelOptions  = ReadIntegerInputCheck(L"Prefs", L"Prefs_ChartX8_j", 0, 0, 8);
		Chart.XAxisDelta    = ReadIntegerInputCheck(L"Prefs", L"Prefs_ChartX8_k", 0, 0, 0);
		Chart.ShowLegend    = ReadBool(             L"Prefs", L"Prefs_ChartX8_m", True);

		Chart.TitleColour   = ReadInteger(          L"Prefs", L"Prefs_ChartX8_l", 0x00FFFFFF, -1);

		// =====================================================================
		// ==  appearance and navigation colours                              ==
		// =====================================================================

		Appearance.RowHeight       = ReadIntegerInputCheck(L"Prefs", L"RowHeight", 17, 15, 40);
		Appearance.TableBandColour = ReadInteger(L"Prefs", L"TableBandColour", 0x00F9FFF9, -1);

		Appearance.BarColours[0] = ReadInteger(L"Prefs", L"NavColour1", 0x00EEEEEE, -1);
		Appearance.BarColours[1] = ReadInteger(L"Prefs", L"NavColour2", 0x00FF4422, -1);
		Appearance.BarColours[2] = ReadInteger(L"Prefs", L"NavColour3", 0x00EEEEEE, -1);
		Appearance.BarColours[3] = ReadInteger(L"Prefs", L"NavColour4", 0x00FF44FF, -1);
		Appearance.BarColours[4] = ReadInteger(L"Prefs", L"NavColour5", 0x00DEDDFF, -1);
		Appearance.BarColours[5] = ReadInteger(L"Prefs", L"NavColour6", 0x005603F1, -1);

		// =====================================================================
		// == Tab Display Options                                             ==
		// =====================================================================

		for (int t = 0; t < 4; t++)
		{
			std::wstring option = ReadString(L"Prefs", L"TabDisplayOptions" + std::to_wstring(t), L"011111111111111111111");

			for (int z = 0; z < option.size(); z++)
			{
				if (option[z] == L'1')
				{
					TabDisplay[t].Option[z].Value = true;
				}
				else
				{
					TabDisplay[t].Option[z].Value = false;
				}
			}
		}

		for (int t = 0; t < 2; t++)
		{
			Navigation.Display[t] = ReadString(L"Prefs", L"NavigateDisplayOptions" + std::to_wstring(t), L"11111111111111111111");

			if (Navigation.Display[t].size() != 20)
			{
				Navigation.Display[t] = L"11111111111111111111";
			}
		}

		// =====================================================================
		// ==                                                                 ==
		// =====================================================================

		Optimisations.AddToDate           = ReadBool(L"Prefs", L"AddToDate", false);
		Optimisations.AddToDateLimit      = ReadBool(L"Prefs", L"AddToDateLimit", false);
		Optimisations.AddToDateLimitCount = ReadInteger(L"Prefs", L"AddToDateLimitCount", 1000, -1);

		Optimisations.BuildDateTree = ReadBool(L"Prefs", L"BuildDateTree", false);
		Optimisations.GetTempFiles = ReadBool(L"Prefs", L"GetTempFiles", false);
		Optimisations.GetUserDetails = ReadBool(L"Prefs", L"GetUserDetails", false);
		Optimisations.JustInTimeDisplay = ReadBool(L"Prefs", L"JustInTimeDisplay", true);
		Optimisations.ProgressUpdate = ReadIntegerInputCheck(L"Prefs", L"ProgressUpdate", 1, 0, 5);

		// =====================================================================
		// ==                                                                 ==
		// =====================================================================

		int fd = ReadIntegerInputCheck(L"Prefs", L"DateFormat", 0, 0, 4);

		switch (fd)
		{
		case 0:
			General.FormatDate = DateFormat::kSlashDDMMYYYY;
			break;
		case 1:
			General.FormatDate = DateFormat::kSlashMMDDYYYY;
			break;
		case 2:
			General.FormatDate = DateFormat::kSlashYYYYMMDD;
			break;
		case 3:
			General.FormatDate = DateFormat::kHyphenDDMMYYYY;
			break;
		case 4:
			General.FormatDate = DateFormat::kHyphenMMDDYYYY;
			break;
		}

		// =====================================================================
		// ==                                                                 ==
		// =====================================================================

		General.MaxSearchResults = ReadInteger(L"Prefs", L"MaxSearchResults", 20000, 20000);

		General.CustomViewer            = ReadString(L"Prefs", L"CustomViewer", L"notepad.exe");

		General.SaveLog                 = ReadBool(L"Prefs", L"SaveLog", false);

		General.PostScanMode            = ReadIntegerInputCheck(L"Prefs", L"PostScanMode", kPostScanSummary, 0, 3);
		General.PostScanIPPage          = ReadIntegerInputCheck(L"Prefs", L"PostScanIPPage", 0, 0, 10);

		General.AutoCheckUpdate         = ReadBool(L"Prefs", L"Prefs_AutoCheckUpdate", true);

		// =====================================================================
		// ==                                                                 ==
		// =====================================================================

		FileCategoryColors[0] = 0x00FFFFFF; // for folders

		for (int t = 1; t < kFileCategoriesCount; t++)
		{
			FileCategoryColors[t] = ReadInteger(L"Prefs", L"ChartColour" + std::to_wstring(t), kDefaultDisplayColours[t], -1);
		}

		// =====================================================================
		// == FTP                                                             ==
		// =====================================================================

		FTP.Options[kFTPOptionHost] = ReadString(L"Prefs", L"ftpOptions0", L"");
		FTP.Options[kFTPOptionUserName] = ReadString(L"Prefs", L"ftpOptions1", L"");
		FTP.Options[kFTPOptionPassword] = ReadString(L"Prefs", L"ftpOptions2", L"");
		FTP.Options[kFTPOptionRemoteFolder] = ReadString(L"Prefs", L"ftpOptions3", L"");
		FTP.Options[kFTPOptionActualLink] = ReadString(L"Prefs", L"ftpOptions4", L"");
		FTP.Options[kFTPOptionInitialFolder] = ReadString(L"Prefs", L"ftpOptions5", L"");

		// =====================================================================
		// == Quick Folders                                                   ==
		// =====================================================================

		for (int t = 0; t < kQuickFolderCount; t++)
		{
			std::wstring s = ReadString(L"Prefs", L"Prefs_QuickFolder" + std::to_wstring(t), L"");

			if (!s.empty())
			{
				QuickFolders[t] = s;
			}
		}

		// =====================================================================
		// == Folder History                                                  ==
		// =====================================================================

		History.Enabled     = ReadBool(L"Prefs", L"Prefs_HistorySettings_Enabled", true);
		History.FullLogging = ReadBool(L"Prefs", L"Prefs_HistorySettings_FullLogging", true);
		History.SQLinSearch = ReadBool(L"Prefs", L"Prefs_HistorySettings_SQLinSearch", false);

		for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				FolderHistory.Compare[x][y] = ReadBool(L"FHCompare", L"X" + std::to_wstring(x + 1) + L"Y" + std::to_wstring(y + 1), false);
			}
		}

		CloseSettings();
	}
	else
	{
		// =====================================================================

        for (int r = 0; r < kReportTypeCount; r++)
		{
			Reports.HTML[r].Colours.Colour[0]  = 0x990000;  // link normal
			Reports.HTML[r].Colours.Colour[1]  = 0x000000;  // link hover
			Reports.HTML[r].Colours.Colour[2]  = 0xFFFFFF;  // background colour
			Reports.HTML[r].Colours.Colour[3]  = 0x990000;  // text colour
			Reports.HTML[r].Colours.Colour[4]  = 0x0000FF;  // bargraph colour
			Reports.HTML[r].Colours.Colour[5]  = 0xFF9900;  // table background
			Reports.HTML[r].Colours.Colour[6]  = 0xFFFFFF;  // table colour1
			Reports.HTML[r].Colours.Colour[7]  = 0x000000;  // table colour2
			Reports.HTML[r].Colours.Colour[8]  = 0xFFFFFF;  // graph background
			Reports.HTML[r].Colours.Colour[9]  = 0xDDDDDD;  // table body background
			Reports.HTML[r].Colours.Colour[10] = 0xCCCCCC;  // table body background II
		}

		FileCategoryColors[0]  = 0x00FFFFFF; // for folders

		for (int t = 1; t < kFileCategoriesCount; t++)
		{
			FileCategoryColors[t] = ReadInteger(L"Prefs", L"Chart Colour" + std::to_wstring(t), kDefaultDisplayColours[t], -1);
		}

		// ===========================================================================

		Optimisations.ProgressUpdate = 1;

		Optimisations.GetUserDetails = false;

		// ===========================================================================

		General.FormatDate = DateFormat::kSlashYYYYMMDD;
		System.HandleMultipleExt = 0;
	}

    return true;
}


bool SettingsHandler::Save(int X, int Y, int W, int H, const std::wstring current_language)
{
	// ===========================================================================
	// ===========================================================================
	// == Initialise                                                            ==
	// ===========================================================================
	// ===========================================================================

	if (OpenSettings(false))
	{
		// ===========================================================================
		// == Window                                                                ==
		// ===========================================================================

		WriteInteger(L"Prefs", L"Main_Top", X);
		WriteInteger(L"Prefs", L"Main_Left", Y);
		WriteInteger(L"Prefs", L"Main_Width", W);
		WriteInteger(L"Prefs", L"Main_Height", H);

		WriteBool(L"Prefs", L"Tutorial", System.Tutorial);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		WriteBool(L"Prefs",    L"BuildDateTree",       Optimisations.BuildDateTree);
		WriteBool(L"Prefs",    L"GetUserDetails",      Optimisations.GetUserDetails);
		WriteBool(L"Prefs",    L"GetTempFiles",        Optimisations.GetTempFiles);

		WriteInteger(L"Prefs", L"TableBandColour",     Appearance.TableBandColour);
		WriteInteger(L"Prefs", L"RowHeight",           Appearance.RowHeight);
		WriteInteger(L"Prefs", L"DateFormat",          General.DateFormatToInt());
		WriteInteger(L"Prefs", L"MaxSearchResults",    General.MaxSearchResults);

		WriteString(L"Prefs",  L"CustomViewer",        General.CustomViewer);

		WriteBool(L"Prefs",    L"SaveLog",             General.SaveLog);

		WriteString(L"Prefs", L"Language",             current_language);
		WriteInteger(L"Prefs", L"ProgressUpdate",      Optimisations.ProgressUpdate);
		WriteInteger(L"Prefs", L"PostScanMode",        General.PostScanMode);
		WriteInteger(L"Prefs", L"PostScanIPPage",      General.PostScanIPPage);
		WriteBool(L"Prefs",    L"Prefs_ASMode",        Reports.AutoSaveMode);
		WriteBool(L"Prefs",    L"Prefs_ASOrganise",    Reports.AutoSaveOrganise);
		WriteBool(L"Prefs",    L"JustInTimeDisplay",   Optimisations.JustInTimeDisplay);

		WriteBool(L"Prefs",    L"AddToDate",           Optimisations.AddToDate);
		WriteBool(L"Prefs",    L"AddToDateLimit",      Optimisations.AddToDateLimit);
		WriteInteger(L"Prefs", L"AddToDateLimitCount", Optimisations.AddToDateLimitCount);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		for (int t = 0; t < kAutoSaveItemCount; t++)
		{
			WriteBool(L"Prefs", L"Prefs_AutoSaveDrive" + std::to_wstring(t), Reports.AutoSaveItem[t]);
		}

		WriteBool(L"Prefs", L"Prefs_AutoCheckUpdate", General.AutoCheckUpdate);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		WriteString(L"Prefs", L"Prefs_HTMLOutput", Reports.HTMLCommand);
		WriteString(L"Prefs", L"Prefs_HTMLCompareOutput", Reports.HTMLCompareCommand);

		for (int t = 0; t < kReportTypeCount; t++)
		{
			for (int x = 0; x < kFileCategoriesCount; x++)
			{
				WriteBool(L"Prefs",  L"HTMLOptions" + std::to_wstring(t) + L"_CategoryList" + std::to_wstring(x),   Reports.HTML[t].CategoryList[x]);
				WriteBool(L"Prefs",  L"TextOptions" + std::to_wstring(t) + L"_CategoryList" + std::to_wstring(x), Reports.Text[t].CategoryList[x]);
				WriteBool(L"Prefs",  L"TreeOptions" + std::to_wstring(t) + L"_CategoryList" + std::to_wstring(x), Reports.Tree[t].CategoryList[t]);
			}

			WriteInteger(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_HTMLUnits",         Reports.HTML[t].Units);
			WriteString(L"Prefs",  L"HTMLOptions" + std::to_wstring(t) + L"_Layout",            Reports.HTML[t].Layout);

			WriteInteger(L"Prefs", L"HTMLOptions" + std::to_wstring(t) + L"_LayoutSize",        Reports.HTML[t].LayoutSize);

			for (int x = 0; x < kHTMLColoursCount; x++)
			{
				WriteInteger(L"Prefs", L"Prefs_Report" + std::to_wstring(t) + L"HTMLColour" + std::to_wstring(x), Reports.HTML[t].Colours.Colour[x]);
			}

			WriteString(L"Prefs",  L"TextOptions" + std::to_wstring(t) + L"_Layout",            Reports.Text[t].Layout);

			WriteString(L"Prefs",  L"TreeOptions" + std::to_wstring(t) + L"_Layout",            Reports.Tree[t].Layout);
			WriteBool(L"Prefs",    L"TreeOptions" + std::to_wstring(t) + L"_IncludeSize",       Reports.Tree[t].IncludeSize);
			WriteBool(L"Prefs",    L"TreeOptions" + std::to_wstring(t) + L"_IncludeAttributes", Reports.Tree[t].IncludeAttributes);

			WriteString(L"Prefs",  L"XMLOptions" + std::to_wstring(t) + L"_Layout",             Reports.XML[t].Layout);
			WriteInteger(L"Prefs", L"Prefs_XMLData" + std::to_wstring(t) + L"_Data",            Reports.XML[t].Data);
			WriteBool(L"Prefs",    L"Prefs_XMLData" + std::to_wstring(t) + L"_Open",            Reports.XML[t].AutoOpen);

			WriteInteger(L"Prefs", L"XinorbisOptions" + std::to_wstring(t) + L"_Layout",        Reports.Xinorbis[t].Layout);
		}

		WriteInteger(L"Prefs", L"HTMLCompareOptions" + std::to_wstring(1) + L"_HTMLUnits",    Reports.HTMLCompare.Units);
		WriteString(L"Prefs",  L"HTMLCompareOptions" + std::to_wstring(1) + L"_Layout",       Reports.HTMLCompare.Layout);

		WriteString(L"Prefs", L"Prefs_XMLOutput",  Reports.XMLCommand);
		WriteString(L"Prefs", L"Prefs_TextOutput", Reports.TextCommand);

		WriteInteger(L"Prefs", L"Prefs_OtherCSVUnits",     Reports.CSV[kReportLayoutAutoSave].Units);
		WriteBool(L"Prefs",    L"Prefs_OtherCSVTitles",    Reports.CSV[kReportLayoutAutoSave].Titles);
		WriteInteger(L"Prefs", L"Prefs_OtherCSVData",      Reports.CSV[kReportLayoutAutoSave].Data);
		WriteInteger(L"Prefs", L"Prefs_OtherCSVSeparator", Reports.CSV[kReportLayoutAutoSave].Separator);

		WriteInteger(L"Prefs", L"Prefs_CSVUnits",           Reports.CSV[kReportLayoutQuick].Units);
		WriteBool(L"Prefs",    L"Prefs_CSVTitles",         Reports.CSV[kReportLayoutQuick].Titles);
		WriteInteger(L"Prefs", L"Prefs_CSVData",           Reports.CSV[kReportLayoutQuick].Data);
		WriteInteger(L"Prefs", L"Prefs_CSVSeparator",      Reports.CSV[kReportLayoutQuick].Separator);
		WriteBool(L"Prefs",    L"Prefs_CSVAutoOpen",       Reports.CSV[kReportLayoutQuick].AutoOpen);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		WriteString(L"Prefs", L"SummaryLayout", Reports.Summary.Layout);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		WriteBool(L"Prefs", L"Prefs_HistorySettings_Enabled",     History.Enabled);
		WriteBool(L"Prefs", L"Prefs_HistorySettings_FullLogging", History.FullLogging);
		WriteBool(L"Prefs", L"Prefs_HistorySettings_SQLinSearch", History.SQLinSearch);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		WriteInteger(L"Prefs", L"Prefs_ChartX8_a",  Chart.ChartFrom);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_b",  Chart.ChartTo);
		WriteBool(L"Prefs",    L"Prefs_ChartX8_c",  Chart.ChartGradient);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_d",  Chart.Zoom);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_e",  Chart.Explode);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_f",  Chart.MarkColour);
		WriteBool(L"Prefs",    L"Prefs_ChartX8_g",  Chart.ShowMarks);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_h",  Chart.MarksType);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_i",  Chart.Elevation);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_j",  Chart.LabelOptions);
		WriteBool(L"Prefs",    L"Prefs_ChartX8_m",  Chart.ShowLegend);

		WriteInteger(L"Prefs", L"Prefs_ChartX8_k",  Chart.XAxisDelta);
		WriteInteger(L"Prefs", L"Prefs_ChartX8_l",  Chart.TitleColour);

		for (int t = 0; t < kQuickFolderCount; t++)
		{
			WriteString(L"Prefs", L"Prefs_QuickFolder" + std::to_wstring(t), QuickFolders[t]);
		}

		FileCategoryColors[0] = 0x00FFFFFF; // for folders

		for (int t = 0; t < kFileCategoriesCount; t++)
		{
			WriteInteger(L"Prefs", L"ChartColour" + std::to_wstring(t), FileCategoryColors[t]);
		}

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		for (int t = 0; t < 6; t++)
		{
			WriteInteger(L"Prefs", L"NavColour" + std::to_wstring(t), Navigation.BarColours[t]);
		}

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		for (int t = 0; t < 3; t++)
		{
			for (int x = 0; x < 22; x++)
			{
				WriteString(L"Prefs", L"TabDisplayOptions" + std::to_wstring(t), TabDisplay[t].Option[x].Name);
				WriteInteger(L"Prefs", L"TabDisplayOptions" + std::to_wstring(t), TabDisplay[t].Option[x].Value);
			}
		}

		WriteString(L"Prefs", L"NavigateDisplayOptions0", Navigation.Display[0]);
		WriteString(L"Prefs", L"NavigateDisplayOptions1", Navigation.Display[1]);

		// ===========================================================================
		// ==                                                                       ==
		// ===========================================================================

		for (int t = 0; t < kFTPOptionsCount; t++)
		{
			WriteString(L"Prefs", L"ftpOptions" + std::to_wstring(t), FTP.Options[t]);
		}

		// ===========================================================================
		// == Close                                                                 ==
		// ===========================================================================

		CloseSettings();
	}
}


int SettingsHandler::LanguageToInt(LanguageType lt)
{
	switch (lt)
	{
	case LanguageType::kUK:
		return 1;
	case LanguageType::kNL:
		return 2;
	case LanguageType::kFR:
		return 3;
	case LanguageType::kDE:
		return 4;
	case LanguageType::kIT:
		return 5;
	case LanguageType::kPT:
		return 6;
	case LanguageType::kES:
		return 7;
	case LanguageType::kSW:
		return 8;
	case LanguageType::kCZ:
		return 9;
	case LanguageType::kHU:
		return 10;
	case LanguageType::kUS:
		return 11;
	case LanguageType::kRU:
		return 12;
	case LanguageType::kCAT:
		return 13;
	}

	return 0;
}


bool SettingsHandler::LoadLanguage()
{
    // ===========================================================================
    // ===========================================================================
    // == Initialise                                                            ==
    // ===========================================================================
    // ===========================================================================

    OpenSettings(true);

    // ===========================================================================
    // ===========================================================================
    // == Load Settings                                                         ==
    // ===========================================================================
    // ===========================================================================

	int language = ReadInteger(L"Prefs", L"Language", -1, 0);

	switch (language)
	{
	case 1:
		System.CurrentLanguage = LanguageType::kUK;
		break;
	case 2:
		System.CurrentLanguage = LanguageType::kNL;
		break;
	case 3:
		System.CurrentLanguage = LanguageType::kFR;
		break;
	case 4:
		System.CurrentLanguage = LanguageType::kDE;
		break;
	case 5:
		System.CurrentLanguage = LanguageType::kIT;
		break;
	case 6:
		System.CurrentLanguage = LanguageType::kPT;
		break;
	case 7:
		System.CurrentLanguage = LanguageType::kES;
		break;
	case 8:
		System.CurrentLanguage = LanguageType::kSW;
		break;
	case 9:
		System.CurrentLanguage = LanguageType::kCZ;
		break;
	case 10:
		System.CurrentLanguage = LanguageType::kHU;
		break;
	case 11:
		System.CurrentLanguage = LanguageType::kUS;
		break;
	case 12:
		System.CurrentLanguage = LanguageType::kRU;
		break;
	case 13:
		System.CurrentLanguage = LanguageType::kCAT;
		break;
	default:
		System.CurrentLanguage = LanguageType::kUndefined;
	}

	// ===========================================================================
    // == Close                                                                 ==
    // ===========================================================================

    CloseSettings();

	if (System.CurrentLanguage == LanguageType::kUndefined)
	{
		System.CurrentLanguage = LanguageType::kUK;
	}

    return true;
}


std::wstring SettingsHandler::ReadString(const std::wstring section, const std::wstring name, const std::wstring default_value)
{
    if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
    {
		std::wstring rs = __iniFile->ReadString(section, name, default_value);

		return rs;
    }
    else
    {
		return Registry::ReadString(hKey, name, default_value);
    }
}


int SettingsHandler::ReadInteger(const std::wstring section, const std::wstring name, int default_value, int ifZero)
{
    int setting;

    if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
    {
		int ri = __iniFile->ReadInteger(section, name, default_value);

		if (ri == 0)
		{
			return ifZero;
		}

		return ri;
    }
    else
    {
		setting = Registry::ReadInteger(hKey, name, default_value);
	}

    if (setting == 0)
    {
        if (ifZero != -1)
        {
            return  ifZero;
        }
        else
        {
            return setting;
        }
    }
    else
    {
        return setting;
    }
}


int SettingsHandler::ReadIntegerInputCheck(const std::wstring section, const std::wstring name, int default_value, int min, int max)
{
	if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
	{
		int ri = __iniFile->ReadInteger(section, name, default_value);

		if ((ri < min) || (ri > max))
		{
			return  default_value;
		}
		else
		{
			return ri;
		}
	}
	else
	{
		int setting = Registry::ReadInteger(hKey, name, default_value);

		if ((setting < min) || (setting > max))
		{
			return  default_value;
		}
		else
		{
			return setting;
		}
	}
}


bool SettingsHandler::ReadBool(const std::wstring section, const std::wstring name, bool default_value)
{
	if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
	{
		return true;
	}
	else
	{
		return Registry::ReadBool(hKey, name, default_value);
	}
}


void SettingsHandler::WriteInteger(const std::wstring section, const std::wstring name, int value)
{
}


void SettingsHandler::WriteString(const std::wstring section, const std::wstring name, const std::wstring)
{
}


void SettingsHandler::WriteBool(const std::wstring section, const std::wstring name, bool value)
{
}


FormDetails SettingsHandler::LoadFormDetails(int FormId)
{
	FormDetails fd(FormId, -1, -1, -1, -1);

	if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
	{
		if (OpenSettings(true))
		{
			fd.X = ReadInteger(L"Form_" + std::to_wstring(FormId), L"x", -1, -1);
			fd.Y = ReadInteger(L"Form_" + std::to_wstring(FormId), L"y", -1, -1);
			fd.Width = ReadInteger(L"Form_" + std::to_wstring(FormId), L"w", -1, -1);
			fd.Height = ReadInteger(L"Form_" + std::to_wstring(FormId), L"h", -1, -1);
			fd.P1 = ReadInteger(L"Form_" + std::to_wstring(FormId), L"p1", -1, -1);
			fd.P2 = ReadInteger(L"Form_" + std::to_wstring(FormId), L"p2", -1, -1);
			fd.P3 = ReadInteger(L"Form_" + std::to_wstring(FormId), L"p3", -1, -1);
			fd.P4 = ReadInteger(L"Form_" + std::to_wstring(FormId), L"p4", -1, -1);
		}
		else
		{
			fd.FormId = -1;
        }
	}
	else
	{
		HKEY hKey;

		if (Registry::Open(hKey, L"\\software\\" + __XRegistryPath + L"\\Form_" + std::to_wstring(FormId), false) == ERROR_SUCCESS)
		{
			fd.X = Registry::ReadInteger(hKey, L"x", -1);
			fd.Y = Registry::ReadInteger(hKey, L"x", -1);
			fd.Width = Registry::ReadInteger(hKey, L"w", -1);
			fd.Height = Registry::ReadInteger(hKey, L"h", -1);
			fd.P1 = Registry::ReadInteger(hKey, L"p1", -1);
			fd.P2 = Registry::ReadInteger(hKey, L"p2", -1);
			fd.P3 = Registry::ReadInteger(hKey, L"p3", -1);
			fd.P4 = Registry::ReadInteger(hKey, L"p4", -1);

			Registry::Close(hKey);
		}
		else
		{
			fd.FormId = -1;
		}
	}

	return fd;
}


void SettingsHandler::SaveFormDetails(FormDetails &fd)
{
	if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
	{
		if (OpenSettings(false))
		{
			WriteInteger(L"Form_" + std::to_wstring(fd.FormId), L"x", fd.X);
			WriteInteger(L"Form_" + std::to_wstring(fd.FormId), L"y", fd.Y);
			WriteInteger(L"Form_" + std::to_wstring(fd.FormId), L"w", fd.Width);
			WriteInteger(L"Form_" + std::to_wstring(fd.FormId), L"h", fd.Height);
			WriteInteger(L"Form_" + std::to_wstring(fd.FormId), L"p1", fd.P1);
			WriteInteger(L"Form_" + std::to_wstring(fd.FormId), L"p2", fd.P2);
			WriteInteger(L"Form_" + std::to_wstring(fd.FormId), L"p3", fd.P3);
			WriteInteger(L"Form_" + std::to_wstring(fd.FormId), L"p4", fd.P4);
		}
		else
		{
            fd.FormId = -1;
		}
	}
	else
	{
		HKEY hKey;

		if (Registry::Open(hKey, L"\\software\\" + __XRegistryPath + L"\\Form_" + std::to_wstring(fd.FormId), true) == ERROR_SUCCESS)
		{
			Registry::WriteInteger(hKey, L"x", fd.X);
			Registry::WriteInteger(hKey, L"y", fd.Y);
			Registry::WriteInteger(hKey, L"w", fd.Width);
			Registry::WriteInteger(hKey, L"h", fd.Height);
			Registry::WriteInteger(hKey, L"p1", fd.P1);
			Registry::WriteInteger(hKey, L"p2", fd.P2);
			Registry::WriteInteger(hKey, L"p3", fd.P3);
			Registry::WriteInteger(hKey, L"p4", fd.P4);

			Registry::Close(hKey);
		}
	}
}


bool SettingsHandler::ClearFormDetails(int FormId)
{
	if (Custom.SettingsSaveLocation == SettingsSource::ConfigIni)
	{
		Ini *ini = new Ini(GSystemGlobal->ExePath + L"\\custom.ini");

		if (ini->DeleteSection(L"Form_" + std::to_wstring(FormId)))
		{
			ini->SaveFile(GSystemGlobal->ExePath + L"\\custom.ini");
		}

		delete ini;
	}
	else
	{
		HKEY hKey;

		if (Registry::Open(hKey, L"\\software\\" + __XRegistryPath + L"\\Form_" + std::to_wstring(FormId), true) == ERROR_SUCCESS)
		{
			if (Registry::Delete(hKey, L"\\software\\" + __XRegistryPath + L"\\Form_" + std::to_wstring(FormId)) != ERROR_SUCCESS)
			{
                // error
			}

			Registry::Close(hKey);
		}
	}

    return false;
}
