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
#include "ParameterHandler.h"
#include "ReportCSV.h"
#include "ReportCSVReportOptions.h"
#include "ReportHandler.h"
#include "ReportHTML.h"
#include "ReportHTMLReportOptions.h"
#include "ReportSummary.h"
#include "ReportText.h"
#include "ReportTextReportOptions.h"
#include "ReportXML.h"
#include "ReportXMLReportOptions.h"
#include "ReportXinorbis.h"
#include "ReportXinorbisReportOptions.h"
#include "Utility.h"
#include <iostream>


extern ParameterHandler* GParameterHandler;


namespace ReportHandler
{
	int GenerateReports()
	{
		int reportCount = 0;

		for (int t = 1; t < GParameterHandler->Count(); t++)
		{
			int lReportType = GParameterHandler->IsReport(t);

			if (lReportType != -1)
			{
				ParameterDetails lParameterDetails = GParameterHandler->ParametersForReport(t, lReportType);

				lParameterDetails.Value = Utility::ProcessFileName(lParameterDetails.Value);

				switch (lParameterDetails.Type)
				{
				case __ReportTypeCSV:
				{
					CSVReportOptions trOptions;

					trOptions.Filename  = lParameterDetails.Value;
					trOptions.Category  = -1;
					trOptions.Separator = 0; // comma
					trOptions.Titles    = Utility::StringToBool(lParameterDetails.Options[1]);
					trOptions.Units     = Utility::OptionToInt(lParameterDetails.Options[2]);

					if (lParameterDetails.Options[0] == L'0')
					{
						ReportCSV::Summary(trOptions);
					}
					else
					{
						ReportCSV::FullList(trOptions);
					}

					reportCount++;

					break;
				}
				case __ReportTypeHTML:
				{
					HTMLReportOptions trOptions;

					trOptions.Filename   = lParameterDetails.Value;
					trOptions.Align      = L"right";
					trOptions.LayoutSize = Utility::OptionToInt(lParameterDetails.Options[10]);
					trOptions.Units      = Utility::OptionToInt(lParameterDetails.Options[11]);

					trOptions.Layout[0]  = true; // header always visible

					for (int t = 1; t < __HTMLLayoutOptionsCount; t++)
					{
						trOptions.Layout[t] = Utility::StringToBool(lParameterDetails.Options[t]);
					}

					ReportHTML::GenerateReport(trOptions);

					reportCount++;

					break;
				}
				case __ReportTypeSummary:
				{
					ReportSummary::Generate();

					reportCount++;

					break;
				}
				case __ReportTypeText:
				{
					TextReportOptions trOptions;

					trOptions.Filename = lParameterDetails.Value;

					for (int t = 0; t < __TextReportOptionsCount; t++)
					{
						trOptions.Layout[t] = Utility::StringToBool(lParameterDetails.Options[t]);
					}

					for (int t = 0; t < __FileCategoriesCount; t++)
					{
						trOptions.CategoryList[t] = true;
					}

					ReportText::FullList(trOptions);

					reportCount++;

					break;
				}
				case __ReportTypeXML:
				{
					XMLReportOptions trOptions;

					trOptions.Filename = lParameterDetails.Value;

					for (int t = 0; t < XMLReportOptionsCount; t++)
					{
						trOptions.Layout[t] = Utility::StringToBool(lParameterDetails.Options[t]);
					}

					ReportXML::Summary(trOptions);

					reportCount++;

					break;
				}
				case __ReportTypeXMLFullList:
				{
					XMLReportOptions trOptions;

					trOptions.Filename = lParameterDetails.Value;

					ReportXML::FullList(trOptions);

					reportCount++;

					break;
				}
				case __ReportTypeXinorbis:
				{
					XinorbisReportOptions xrOptions;

					xrOptions.Filename = lParameterDetails.Value;

					ReportXinorbis::GenerateXinorbisReport(xrOptions);

					reportCount++;

					break;
				}

				case __ReportTypeTop20:
				{
					ReportSummary::Top20();

					reportCount++;

					break;
				}
				case __ReportTypeBottom20:
				{
					ReportSummary::Bottom20();

					reportCount++;

					break;
				}
				case __ReportTypeNew20:
				{
					ReportSummary::New20();

					reportCount++;

					break;
				}
				case __ReportTypeOld20:
				{
					ReportSummary::Old20();

					reportCount++;

					break;
				}

				case __ReportAll20:
				{
					ReportSummary::Top20();
					ReportSummary::Bottom20();
					ReportSummary::New20();
					ReportSummary::Old20();

					reportCount++;

					break;
				}


				default:
					std::wcout << L"Unknown report type: " << lParameterDetails.Type << std::endl << std::endl;
				}
			}
		}

		return reportCount;
	}


	void ShowDefaultOutput()
	{
		ReportSummary::Generate();
	}
}