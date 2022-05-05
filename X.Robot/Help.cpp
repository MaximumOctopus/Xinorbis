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


#include <iostream>
#include <string>
#include "Constants.h"
#include "Convert.h"
#include "FileExtensionHandler.h"
#include "Help.h"
#include "LanguageHandler.h"
#include "ScanDetails.h"
#include "SystemGlobal.h"
#include "Utility.h"


extern FileExtensionHandler* GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern ScanDetails* GScanDetails;
extern SystemGlobal* GSystemGlobal;


namespace Help
{
	void OutputHelpOption(int option)
	{
		std::wcout << L"opt " << option << std::endl;

		switch (option)
		{
		case __HelpSimple:
			OutputSimple();   // /version
			break;
		case __HelpHelp:
			OutputHelp();     // default
			break;
		case __HelpUsage:
			OutputUsage();    // /? or /h
			break;
		case __HelpStats:
			Stats();          // /stats
			break;
		case __HelpCat:       // cats :)
			Cat();
			break;

		default:
			std::wcout << L"Unknown help type ?!?! " << option << std::endl;
		}
	}


    void OutputSimple()
    {
		std::wcout << std::endl << L"    X.Robot " << __XRVersion << " :: " << __XRDate << std::endl;
		std::wcout << L" (c) Paul Alan Freshney 2020, www.Xinorbis.com, www.MaximumOctopus.com" << std::endl << std::endl;
    }


    void OutputHelp()
    {
        std::wcout << std::endl << L"  X.Robot " << __XRVersion << std::endl;
        std::wcout << L"    " << __XRDate << std::endl;
        std::wcout << std::endl;
        std::wcout << L"  AppPath : " + GSystemGlobal->AppPath << std::endl;
        std::wcout << L"  DataPath: " + GSystemGlobal->UsersPath << std::endl;
        std::wcout << std::endl;
        std::wcout << L"    (c) Paul Alan Freshney 2011-" << Utility::CurrentYear()  << std::endl;
        std::wcout << std::endl;
        std::wcout << L"      www.xinorbis.com" << std::endl;
        std::wcout << L"      www.maximumoctopus.com" << std::endl;
        std::wcout << std::endl;
        std::wcout << L"  Use \"X.Robot /?\" for simple help." << std::endl;
        std::wcout << L"  Use \"X.Robot /u\" to open the usage document." << std::endl;
        std::wcout << std::endl;
    }


    void OutputUsage()
    {
        std::wcout << std::endl << L"  X.Robot " << __XRVersion << std::endl;
        std::wcout << L"    " << __XRDate << std::endl;
        std::wcout << L"    (c) Paul Alan Freshney 2011-" << Utility::CurrentYear() << std::endl;
        std::wcout << std::endl;
        std::wcout << L"    www.xinorbis.com" << std::endl;
        std::wcout << L"    www.maximumoctopus.com" << std::endl;
        std::wcout << std::endl;
		std::wcout << L"  AppPath : " + GSystemGlobal->AppPath << std::endl;
		std::wcout << L"  DataPath: " + GSystemGlobal->UsersPath << std::endl;
        std::wcout << std::endl;
        std::wcout << L"  Usage:" << std::endl;
        std::wcout << std::endl;
        std::wcout << L"  X.Robot <folder to scan>" << std::endl;
        std::wcout << std::endl;
        std::wcout << L"    /csv;options;filename : output CSV to <filename>" << std::endl;
        std::wcout << L"    /htm;options;filename : output HTML to <filename>" << std::endl;
        std::wcout << L"    /txt;options;filename : output Text to <filename>" << std::endl;
        std::wcout << L"    /xml;options;filename : output XML to <filename>" << std::endl;
		std::wcout << L"    /xfl;options;filename : output XML file list to <filename>" << std::endl;
		std::wcout << L"    /xin;options;filename : output xinorbis reports to <filename>" << std::endl;
		std::wcout << std::endl;
		std::wcout << L"    /updatefolderhistory  : update the folder history database" << std::endl;
		std::wcout << L"    /ODBC                 : folder history is via ODBC" << std::endl;
		std::wcout << L"    /sqlite               : folder history is SQlite" << std::endl;
		std::wcout << std::endl;
		std::wcout << L"    /dbstructured         : write out in alternate database format" << std::endl;
		std::wcout << L"    /systemtable;name     : use with above, set system table name" << std::endl;
		std::wcout << L"    /datatable;name       : use with above, set data table name" << std::endl;
		std::wcout << L"    /updatescanhistory    : update the scan history file" << std::endl;
		std::wcout << std::endl;
		std::wcout << L"    /sum                  : output simple summory to console" << std::endl;
		std::wcout << L"    /top20                : output top 20 largest files to console" << std::endl;
		std::wcout << L"    /bottom20             : output bottom 20 smallest files to console" << std::endl;
		std::wcout << L"    /new20                : output top 20 newest files to console" << std::endl;
		std::wcout << L"    /old20                : output top 20 oldest files to console" << std::endl;
		std::wcout << std::endl;
		std::wcout << L"    /allowvirtual         : enable processing of virtual files" << std::endl;
		std::wcout << std::endl;
        std::wcout << L"  Saves to default output folder if filename not specified." << std::endl;
        std::wcout << L"  (Xinorbis data folder, or X.Robot install)" << std::endl;
        std::wcout << std::endl;
    }


	void Stats()
	{
		std::wcout << L"Stats" << std::endl;
		std::wcout << std::endl;
		std::wcout << L"AppPath           : " + GSystemGlobal->AppPath << std::endl;
		std::wcout << L"DataPath          : " + GSystemGlobal->UsersPath << std::endl;
		std::wcout << std::endl;
		std::wcout << L"Size of Scan      : " + Convert::ConvertToUsefulUnit(GScanDetails->TotalSize) << std::endl;
		std::wcout << std::endl;
		std::wcout << L"Files             : " + GScanDetails->FileCount << std::endl;
		std::wcout << L"Average file size : " + Convert::ConvertToUsefulUnit(GScanDetails->AverageFileSize) << std::endl;
		std::wcout << std::endl;
		std::wcout << L"Language          : " << GLanguageHandler->GetLanguageSymbol() << std::endl;
		std::wcout << L"File Extensions   : " << GFileExtensionHandler->Extensions.size() << std::endl;
		std::wcout << std::endl;
	}


	void Cat()
	{
		std::wcout << std::endl;
		std::wcout << L"               *     ,MMM8&&&.            *" << std::endl;
		std::wcout << L"                    MMMM88&&&&&    ." << std::endl;
		std::wcout << L"                   MMMM88&&&&&&&" << std::endl;
		std::wcout << L"       *           MMM88&&&&&&&&" << std::endl;
		std::wcout << L"                   MMM88&&&&&&&&" << std::endl;
		std::wcout << L"                   'MMM88&&&&&&'" << std::endl;
		std::wcout << L"                     'MMM8&&&'      *" << std::endl;
		std::wcout << L"            |\\___/|" << std::endl;
		std::wcout << L"            )     (             .              " << std::endl;
		std::wcout << L"           =\\     /=" << std::endl;
		std::wcout << L"             )===(       *" << std::endl;
		std::wcout << L"            /     \\" << std::endl;
		std::wcout << L"            |     |" << std::endl;
		std::wcout << L"           /       \\" << std::endl;
		std::wcout << L"           \\       /" << std::endl;
		std::wcout << L"    _/\\_/\\_/\\__  _/_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_" << std::endl;
		std::wcout << L"    |  |  |  |( (  |  |  |  |  |  |  |  |  |  |" << std::endl;
		std::wcout << L"    |  |  |  | ) ) |  |  |  |  |  |  |  |  |  |" << std::endl;
		std::wcout << L"    |  |  |  |(_(  |  |  |  |  |  |  |  |  |  |" << std::endl;
		std::wcout << L"    |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << std::endl;
		std::wcout << L"    |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << std::endl;
		std::wcout << std::endl;
		std::wcout << L"        www.xinorbis.com/developmentcats.htm" << std::endl;
		std::wcout << std::endl;
	}
}