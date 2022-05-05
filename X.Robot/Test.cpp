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
// June 4th 2020
//


#include "Constants.h"
#include "Ini.h"
#include "SystemGlobal.h"
#include "ParameterHandler.h"
#include "Test.h"
#include "WindowsUtility.h"

#include <iostream>


extern SystemGlobal* GSystemGlobal;
extern ParameterHandler* GParameterHandler;


namespace Test
{
	void RunTest()
	{
		bool lErrors = false;

		std::wcout << std::endl << L"    Testing parameters..." << std::endl << std::endl;

		if (!CheckScanFolder()) { lErrors = true; }

		if (!CheckInstallationFolder()) { lErrors = true; }
		
		if (!CustomIni()) { lErrors = true; }

		if (!Scan()) { lErrors = true; }

		if (!Database()) { lErrors = true; }

		if (!Reports()) { lErrors = true; }

		if (!ParameterChain()) { lErrors = true; }

		if (lErrors)
		{
			std::wcout << std::endl << "    Errors found :(" << std::endl;
		}
		else
		{
			std::wcout << std::endl << "    No errors found :)" << std::endl;
		}

		std::wcout << std::endl;
	}


	bool CheckScanFolder()
	{
		std::wstring firstParameter = GParameterHandler->GetParameter(0);

		if (firstParameter.find(L'\\') != std::wstring::npos)
		{
			if (WindowsUtility::DirectoryExistsWString(firstParameter))
			{
				std::wcout << L"      Scan folder exists \"" + firstParameter + L"\"" << std::endl << std::endl;

				return true;
			}
			else
			{
				std::wcout << L"      Scan folder does not exist \"" + firstParameter + L"\"" << std::endl << std::endl;

				return false;
			}
		}
		else
		{
			std::wcout << L"      No scan folder specified." << std::endl << std::endl;

			return true;
		}
	}


	bool CheckInstallationFolder()
	{
		std::wcout << L"    X.Robot installation" << std::endl << std::endl;

		if (WindowsUtility::DirectoryExistsWString(GSystemGlobal->AppPath + L"data\\"))
		{
			std::wcout << L"      \\data\\ folder found." << std::endl;

			if (WindowsUtility::DirectoryExistsWString(GSystemGlobal->AppPath + L"data\\languages\\"))
			{
				std::wcout << L"      \\data\\languages\\ folder found." << std::endl;

				return true;
			}
			else
			{
				std::wcout << L"      \\data\\languages\\ folder not found" << std::endl;
			}
		}
		else
		{
			std::wcout << L"      \\data\\ folder not found" << std::endl;
		}

		
		return false;
	}


	bool ParameterChain()
	{
		bool parametersOK = true;

		if (GParameterHandler->Count() != 1)
		{
			for (int t = 1; t < GParameterHandler->Count(); t++)
			{
				int id = GParameterHandler->GetParameterType(GParameterHandler->GetParameter(t));

				if (id == __parameterInvalid)
				{
					parametersOK = false;

					std::wcout << L"      Unknown command \"" + GParameterHandler->GetParameter(t) + L"\"" << std::endl;
				}
			}
		}
		else
		{
			return true; // one parameter, must be /test (not much to do here)
		}

		return parametersOK;
	}


	bool Reports()
	{
		if (GParameterHandler->Count() >= 2)
		{
			std::wcout << std::endl << L"    Reports" << std::endl << std::endl;

			int reportCount = 0;

			for (int t = 0; t < GParameterHandler->Count(); t++)
			{
				int rt = GParameterHandler->IsReport(t);

				if (rt != -1)
				{
					ParameterDetails pd = GParameterHandler->ParametersForReport(t, rt);

					switch (rt)
					{
					case __ReportTypeCSV:
						std::wcout << L"      CSV     : " << pd.Value << std::endl;

						for (int x = 0; x < pd.Options.size(); x++)
						{
							std::wcout << L"              : " << CSVOptions(x, pd.Options[x]) << std::endl;
						}

						break;
					case __ReportTypeHTML:
						std::wcout << L"      HTM     : " << pd.Value << std::endl;

						for (int x = 0; x < pd.Options.size(); x++)
						{
							std::wcout << L"              : " << HTMLOptions(x, pd.Options[x]) << std::endl;
						}

						break;
					case __ReportTypeSummary:
						std::wcout << L"      Summary : output to console" << std::endl;
						break;
					case __ReportTypeText:
						std::wcout << L"      Text    : " << pd.Value << std::endl;

						for (int x = 0; x < pd.Options.size(); x++)
						{
							std::wcout << L"              : " << TextOptions(x, pd.Options[x]) << std::endl;
						}

						break;
					case __ReportTypeXML:
						std::wcout << L"      XML     : " << pd.Value << std::endl;

						for (int x = 0; x < pd.Options.size(); x++)
						{
							std::wcout << L"              : " << XMLOptions(x, pd.Options[x]) << std::endl;
						}

						break;
					case __ReportTypeXMLFullList:
						std::wcout << L"      XML     : (file list)" << pd.Value << std::endl;
						break;

					case __ReportTypeTop20:
						std::wcout << L"      Top 20  : output to console" << std::endl;
						break;
					case __ReportTypeBottom20:
						std::wcout << L"      Bot 20  : output to console" << std::endl;
						break;
					case __ReportTypeNew20:
						std::wcout << L"      New 20  : output to console" << std::endl;
						break;
					case __ReportTypeOld20:
						std::wcout << L"      Old 20  : output to console" << std::endl;
						break;

					case __ReportAll20:
						std::wcout << L"      All 20  : outputs all 20 lists console" << std::endl;
						break;
					}

					reportCount++;
				}
			}

			if (reportCount == 0)
			{
				std::wcout << L"      No reports parameters found." << std::endl;
			}
		}
		else
		{
			std::wcout << L"      No reports specified." << std::endl;
		}

		return true;
	}


	bool Database()
	{
		int errorCount = 0;
		int dbpCount   = 0;

		bool userSetFolderHistory = false;
		bool userSetODBC = false;
		bool userSetSQlite = false;

		if (GParameterHandler->Count() >= 2)
		{
			std::wcout << std::endl << L"    Database" << std::endl << std::endl;

			for (int t = 0; t < GParameterHandler->Count(); t++)
			{
				if (GParameterHandler->IsDatabaseSwitch(t) != __parameterInvalid)
				{
					dbpCount++;

					int pt = GParameterHandler->GetParameterType(GParameterHandler->GetParameter(t));

					switch (pt)
					{
					case __parameterDBUpdateScanHistory:
						std::wcout << L"      Update scan history." << std::endl;

						userSetFolderHistory = true;

						break;
					case __parameterDBODBC:
						std::wcout << L"      Use ODBC database." << std::endl;

						userSetODBC = true;

						break;
					case __parameterDBSQlite:
						std::wcout << L"      Use SQlite database." << std::endl;

						userSetSQlite = true;

						break;
					case __parameterDBStructured:
						std::wcout << L"      Use structured database format." << std::endl;
						break;
					case __parameterDBSystemTable:
					{
						std::wstring tableName = GParameterHandler->GetParameterValue(t);

						if (tableName != L"")
						{
							std::wcout << L"      Specified system table name \"" + tableName + L"\"." << std::endl;
						}
						else
						{
							std::wcout << L"      Specified system table name missing (will use default)." << std::endl;

							errorCount++;
						}

						break;
					}
					case __parameterDBDataTable:
					{
						std::wstring tableName = GParameterHandler->GetParameterValue(t);

						if (tableName != L"")
						{
							std::wcout << L"      Specified data table name \"" + tableName + L"\"." << std::endl;
						}
						else
						{
							std::wcout << L"      Specified data table name missing (will use default)." << std::endl;

							errorCount++;
						}

						break;
					}
					case __parameterDBUpdateFolderistory:
						std::wcout << L"      Update folder history database." << std::endl;
						break;

					default:
						std::wcout << L" unknown " << pt << std::endl;
					}
				}
			}

			if (dbpCount == 0)
			{
				std::wcout << L"      No database parameters found." << std::endl;
			}
		}
		else
		{
			std::wcout << L"      No database parameters specified." << std::endl;
		}

		if (!userSetFolderHistory)
		{
			std::wcout << L"      Folder history controlled via custom.ini (default is off)" << std::endl;
		}

		if (userSetODBC && userSetSQlite)
		{
			std::wcout << L"      SQlite and ODBC settings are mutually exclusive!" << std::endl;

			errorCount++;
		}

		if (!(userSetODBC && userSetSQlite))
		{
			std::wcout << L"      Database source controlled via custom.ini (default is SQlite)" << std::endl;
		}

		if (errorCount != 0)
		{
			return false;
		}

		return true;
	}


	bool Scan()
	{
		if (GParameterHandler->FindParameter(L"/nouser"))
		{
			std::wcout << L"      Will not gather user name information (optimisation)." << std::endl;
		}
		else
		{
			std::wcout << L"      Will gather user name information." << std::endl;
		}

		if (GParameterHandler->FindParameter(L"/notemp"))
		{
			std::wcout << L"      Will not process temporary file stats (optimisation)." << std::endl;
		}
		else
		{
			std::wcout << L"      Will process temporary file stats." << std::endl;
		}

		if (GParameterHandler->FindParameter(L"/o"))
		{
			std::wcout << L"     Disabling console output." << std::endl;
		}

		if (GParameterHandler->FindParameter(L"/allowvirtual"))
		{
			std::wcout << L"     Virtual files will be processed." << std::endl;
		}
		else
		{
			std::wcout << L"     Virtual files will not be processed." << std::endl;
		}

		return true;
	}


	std::wstring CSVOptions(int option, wchar_t value)
	{
		switch (option)
		{
		case 0:

			if (value == L'0')
			{
				return L"Category ouput only";
			}
			else if (value == L'1')
			{
				return L"Full file list (default)";
			}

			break;
		case 1:

			if (value == L'0')
			{
				return L"Don't add 'heading row'";
			}
			else if (value == L'1')
			{
				return L"Add 'heading row' (default)";
			}

			break;
		case 2:

			if (value == L'0')
			{
				return L"File sizes in most convenient format";
			}
			else if (value == L'1')
			{
				return L"All file sizes in bytes";
			}
			else if (value == L'2')
			{
				return L"All file sizes in kilobytes";
			}
			else if (value == L'3')
			{
				return L"All file sizes in megabytes";
			}

			break;
		}

		return L"Unknown option :(";
	}


	std::wstring HTMLOptions(int option, wchar_t value)
	{
		switch (option)
		{
		case 0:

			if (value == L'0')
			{
				return L"Graphs not included";
			}
			else if (value == L'1')
			{
				return L"Graphs on (not supported yet)";
			}

			break;

		case 1:

			if (value == L'0')
			{
				return L"Exclude File Attributes section";
			}
			else if (value == L'1')
			{
				return L"Include File Attributes section";
			}

			break;

		case 2:

			if (value == L'0')
			{
				return L"Exclude Category section";
			}
			else if (value == L'1')
			{
				return L"Include Category section";
			}

			break;

		case 3:

			if (value == L'0')
			{
				return L"Exclude Directories section";
			}
			else if (value == L'1')
			{
				return L"Include Directories section";
			}

			break;

		case 4:

			if (value == L'0')
			{
				return L"Exclude Magnitude section";
			}
			else if (value == L'1')
			{
				return L"Include Magnitude section";
			}

			break;

		case 5:

			if (value == L'0')
			{
				return L"Exclude File Extension section";
			}
			else if (value == L'1')
			{
				return L"Include File Extension section";
			}

			break;

		case 6:

			if (value == L'0')
			{
				return L"Exclude Null Files section";
			}
			else if (value == L'1')
			{
				return L"Include Null Files section";
			}

			break;

		case 7:

			if (value == L'0')
			{
				return L"Exclude File Dates section";
			}
			else if (value == L'1')
			{
				return L"Include File Dates section";
			}

			break;

		case 8:

			if (value == L'0')
			{
				return L"Exclude Top 50 section";
			}
			else if (value == L'1')
			{
				return L"Include Top 50 section";
			}

			break;

		case 9:

			if (value == L'0')
			{
				return L"Exclude Users section";
			}
			else if (value == L'1')
			{
				return L"Include Users section";
			}

			break;

		case 10:

			if (value == L'0')
			{
				return L"Report is 800 pixels wide";
			}
			else if (value == L'1')
			{
				return L"Report is 1024 pixels wide";
			}
			else if (value == L'2')
			{
				return L"Report is 1280 pixels wides";
			}

			break;

		case 11:

			if (value == L'0')
			{
				return L"File sizes in most convenient format";
			}
			else if (value == L'1')
			{
				return L"All file sizes in bytes";
			}
			else if (value == L'2')
			{
				return L"All file sizes in kilobytes";
			}
			else if (value == L'3')
			{
				return L"All file sizes in megabytes";
			}

			break;
		}

		return L"Unknown option :(";
	}


	std::wstring TextOptions(int option, wchar_t value)
	{
		switch (option)
		{
		case 0:

			return L"Unused";

		case 1:

			if (value == L'0')
			{
				return L"Exclude File Attributes section";
			}
			else if (value == L'1')
			{
				return L"Include File Attributes section";
			}

			break;

		case 2:

			if (value == L'0')
			{
				return L"Exclude Category section";
			}
			else if (value == L'1')
			{
				return L"Include Category section";
			}

			break;

		case 3:

			if (value == L'0')
			{
				return L"Exclude Directories section";
			}
			else if (value == L'1')
			{
				return L"Include Directories section";
			}

			break;

		case 4:

			if (value == L'0')
			{
				return L"Exclude Magnitude section";
			}
			else if (value == L'1')
			{
				return L"Include Magnitude section";
			}

			break;

		case 5:

			if (value == L'0')
			{
				return L"Exclude File Extension section";
			}
			else if (value == L'1')
			{
				return L"Include File Extension section";
			}

			break;

		case 6:

			if (value == L'0')
			{
				return L"Exclude Null Files section";
			}
			else if (value == L'1')
			{
				return L"Include Null Files section";
			}

			break;

		case 7:

			if (value == L'0')
			{
				return L"Exclude File Dates section";
			}
			else if (value == L'1')
			{
				return L"Include File Dates section";
			}

			break;

		case 8:

			if (value == L'0')
			{
				return L"Exclude Top 50 section";
			}
			else if (value == L'1')
			{
				return L"Include Top 50 section";
			}

			break;

		case 9:

			if (value == L'0')
			{
				return L"Exclude Users section";
			}
			else if (value == L'1')
			{
				return L"Include Users section";
			}

			break;

		case 10:

			if (value == L'0')
			{
				return L"Exclude File Dates section";
			}
			else if (value == L'1')
			{
				return L"Include File Dates section";
			}

			break;
		}

		return L"Unknown option :(";
	}


	std::wstring XMLOptions(int option, wchar_t value)
	{
		switch (option)
		{
		case 0:

			if (value == L'0')
			{
				return L"Summary of results";
			}
			else if (value == L'1')
			{
				return L"Full file list";
			}

			break;

		case 1:

			if (value == L'0')
			{
				return L"Exclude File Attributes section";
			}
			else if (value == L'1')
			{
				return L"Include File Attributes section";
			}

			break;

		case 2:

			if (value == L'0')
			{
				return L"Exclude Category section";
			}
			else if (value == L'1')
			{
				return L"Include Category section";
			}

			break;

		case 3:

			if (value == L'0')
			{
				return L"Exclude Directories section";
			}
			else if (value == L'1')
			{
				return L"Include Directories section";
			}

			break;

		case 4:

			if (value == L'0')
			{
				return L"Exclude Magnitude section";
			}
			else if (value == L'1')
			{
				return L"Include Magnitude section";
			}

			break;

		case 5:

			if (value == L'0')
			{
				return L"Exclude File Extension section";
			}
			else if (value == L'1')
			{
				return L"Include File Extension section";
			}

			break;

		case 6:

			if (value == L'0')
			{
				return L"Exclude Null Files section";
			}
			else if (value == L'1')
			{
				return L"Include Null Files section";
			}

			break;

		case 7:

			if (value == L'0')
			{
				return L"Exclude File Dates section";
			}
			else if (value == L'1')
			{
				return L"Include File Dates section";
			}

			break;

		case 8:

			if (value == L'0')
			{
				return L"Exclude Top 50 section";
			}
			else if (value == L'1')
			{
				return L"Include Top 50 section";
			}

			break;

		case 9:

			if (value == L'0')
			{
				return L"Exclude Users section";
			}
			else if (value == L'1')
			{
				return L"Include Users section";
			}

			break;
		}

		return L"Unknown option :(";
	}


	bool CustomIni()
	{
		if (WindowsUtility::FileExists(GSystemGlobal->AppPath + L"custom.ini"))
		{
			std::wcout << std::endl << L"    Custom.ini found" << std::endl << std::endl;

			Ini* iniFile = new Ini(GSystemGlobal->AppPath + L"custom.ini");

			if (iniFile->Loaded)
			{
				std::wcout << GSystemGlobal->AppPath + L"Loaded okay" << std::endl;

				std::wstring pcm = iniFile->ReadString(L"Main", L"PortableMode", L"");

				if (pcm == L"")
				{
					std::wcout << L"      Portable mode not specified" << std::endl;
				}
				else
				{
					std::wcout << L"      Portable mode set to: " << pcm << std::endl;
				}

				pcm = iniFile->ReadString(L"Main", L"useodbc", L"");

				if (pcm == L"")
				{
					std::wcout << L"      ODBC mode not specified" << std::endl;
				}
				else
				{
					std::wcout << L"      ODBC mode set to: " << pcm << std::endl;
				}
				
				pcm = iniFile->ReadString(L"Main", L"connectionstring", L"");

				if (pcm == L"")
				{
					std::wcout << L"      Connection string not specified" << std::endl;
				}
				else
				{
					std::wcout << L"      Connection string found" << pcm << std::endl;
				}

				return true;
			}
			else
			{
				std::wcout << GSystemGlobal->AppPath + L"Failure to load :(" << std::endl;
			}
				
			delete iniFile;

			return false;
		}
		else
		{
			std::wcout << std::endl << L"    Custom.ini Not found" << std::endl << std::endl;
		}

		return true;
	}
}