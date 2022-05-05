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


#pragma once


#include <string>
#include <vector>

#include "ParameterDetails.h"


const static int __parameterInvalid = 0x00;

const static int __parameterReportCSV = 0x10;
const static int __parameterReportText = 0x11;
const static int __parameterReportHTML = 0x12;
const static int __parameterReportXinorbis = 0x13;
const static int __parameterReportXML = 0x14;
const static int __parameterReportXMLFileList = 0x15;
const static int __parameterReportSummary = 0x16;
const static int __parameterReportTop20 = 0x17;
const static int __parameterReportBottom20 = 0x18;
const static int __parameterReportNewest20 = 0x19;
const static int __parameterReportOldest20 = 0x1A;

const static int __parameterDBUpdateScanHistory = 0x06;
const static int __parameterDBODBC = 0x07;
const static int __parameterDBSQlite = 0x08;
const static int __parameterDBStructured = 0x09;
const static int __parameterDBSystemTable = 0x0A;
const static int __parameterDBDataTable = 0x0B;
const static int __parameterDBUpdateFolderistory = 0x0C;

const static int __parameterNoUserDetails = 0x20;
const static int __parameterNoProcess = 0x21;
const static int __parameterNoTempFiles = 0x22;
const static int __parameterAllowVirtual = 0x23;

const static int __parameterVersionCheck = 0x80;

const static int __parameterCat = 0x90;
const static int __parameterTest = 0x91;


class ParameterHandler
{
private:
    std::vector<std::wstring> parameters;
	std::vector<std::wstring> tokens;

	void ParameterHandler::CreateTokens(std::wstring parameter);

public:
    ParameterHandler(int argc, wchar_t *argv[]);

	bool FindParameter(std::wstring parameter);
	std::wstring GetParameter(int index);
	std::wstring GetParameterValue(int parameter);
	int Count();
	int IsReport(int aIndex);
	ParameterDetails ParameterInformation(int type);
	ParameterDetails ParametersForReport(int report, int reportType);

	int GetParameterType(std::wstring parameter);

	int IsProcessingSwitch(int parameter);
	int IsDatabaseSwitch(int parameter);

	std::wstring ReportSwitch(int report);
	int HelpSwitch(std::wstring& help);

	std::wstring DefaultFileName(int report);
	std::wstring DefaultOptions(int report);

	bool NeedToProcessTopSizeLists();
	bool NeedToProcessTopDateLists();
	bool NeedToProcessFileDates();

	bool HasScanFolder();
};