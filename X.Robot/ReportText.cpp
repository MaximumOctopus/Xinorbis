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


#include "Constants.h"
#include "Convert.h"
#include "FileExtensionHandler.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ReportText.h"
#include "ReportTextReportOptions.h"
#include "ScanDetails.h"
#include "Utility.h"
#include <codecvt>
#include <fstream>
#include <iostream>
#include <string>


extern FileExtensionHandler *GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern ScanDetails* GScanDetails;


namespace ReportText
{
	void FullList(TextReportOptions options)
	{
		std::wofstream ofile(options.Filename);

		ofile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

		if (ofile)
		{
			std::wcout << GLanguageHandler->XText[rsSavingReports] + L" (Text): " << std::endl;
			std::wcout << L"    " << options.Filename << std::endl << std::endl;

			for (int t = 0; t < __TextReportOptionsCount; t++)
			{
				if (options.Layout[t])
				{
					switch (t)
					{
						case 0:
							ReportHeader(ofile);
							break;
						case 1:
							ReportAttributes(ofile);
							break;
						case 2:
							ReportCategories(ofile);
							break;
						case 3:
							ReportDirectoryList(ofile);
							break;
						case 4:
							ReportMagnitude(ofile);
							break;
						case 5:
							ReportExtensions(ofile, options);
							break;
						case 6:
							ReportNullFiles(ofile);
							break;
						case 7:
							break;
						case 8:
							ReportLargestFiles(ofile);
							ReportSmallestFiles(ofile);
							ReportNewestFiles(ofile);
							ReportOldestFiles(ofile);
							break;
						case 9:
							ReportUsers(ofile);
							break;
						case 10:
							ReportFileDates(ofile);
							break;
					}
				}
			}

			ofile << std::endl;
			ofile << GLanguageHandler->TextReport[0] << std::endl;
			ofile << L"================ X.Robot Text Report = (c) Paul A Freshney 2019 ==" << std::endl;

			ofile.close();
		}
		else
		{
			std::wcout << GLanguageHandler->XText[rsErrorSaving] + L" (Text):" << std::endl;
			std::wcout << L"    " << options.Filename << std::endl << std::endl;
		}
	}


	void ReportHeader(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << L"------------------------------------------------------------------" << std::endl;
		ofile << L"-- X.Robot -------------------------------------------------------" << std::endl;
		ofile << L"------------------------------------------------------------------" << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << L"" << std::endl;
	}


	void ReportSummary(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->SummaryReport[0] + L" \"" + GScanDetails->ScanPath + L"\"" << std::endl;

		ofile << Formatting::AddLeading(L"", GLanguageHandler->SummaryReport[0].size(), L' ') + Utility::GetDate(__GETTIMEFORMAT_DISPLAY) + L", " + Utility::GetTime(__GETTIMEFORMAT_DISPLAY) << std::endl;
		ofile << std::endl;
		ofile << GLanguageHandler->SummaryReport[1] + L" " << GScanDetails->FileCount << std::endl;
		ofile << GLanguageHandler->SummaryReport[2] + L" " << GScanDetails->FolderCount << std::endl;
		ofile << GLanguageHandler->SummaryReport[3] + L" " << Convert::ConvertToUsefulUnit(GScanDetails->TotalSize) << std::endl;

		ofile << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			ofile << GLanguageHandler->SummaryReport[8] + L" " + Convert::ConvertToUsefulUnit(GScanDetails->AverageFileSize) << std::endl;
		}

		if (GScanDetails->FolderCount != 0)
		{
			ofile << GLanguageHandler->SummaryReport[9] + L" " << GScanDetails->AverageFilesPerFolder << std::endl;
		}

		ofile << std::endl;
	}


	void ReportAttributes(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[3] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[4] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < __AttributesToDisplayCount; t++)
			{
				std::wstring str =	Formatting::AddTrailing(L" " + GLanguageHandler->LanguageTypes[t], TRDescriptionWidth, L' ') +
									Formatting::AddLeading(std::to_wstring(GScanDetails->FileAttributes[t][__faCount]), TRQuantityWidth, L' ') + L"  " +
									Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->FileAttributes[t][__faCount] / (double)GScanDetails->FileCount), TRAsPercentWidth, ' ') + L"  " +
									Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->FileAttributes[t][__faSize]), TRSizeWidth, ' ');

				if (GScanDetails->TotalSize != 0)
				{	
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->FileAttributes[t][__faSize] / (double)GScanDetails->TotalSize), TRAsPercentWidth, ' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				ofile << str << std::endl;
			}
		}

		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << std::endl;
	}


	void ReportCategories(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[1] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[2] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < __FileCategoriesCount; t++)
			{
				std::wstring str = Formatting::AddTrailing(L" " + GLanguageHandler->TypeDescriptions[t], TRDescriptionWidth, L' ') +
					Formatting::AddLeading(std::to_wstring(GScanDetails->ExtensionSpread[t][__esCount]), TRQuantityWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->ExtensionSpread[t][__esCount] / (double)GScanDetails->FileCount), TRAsPercentWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->ExtensionSpread[t][__esSize]), TRSizeWidth, L' ');

				if (GScanDetails->TotalSize != 0)
				{
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->ExtensionSpread[t][__esSize] / (double)GScanDetails->TotalSize), TRAsPercentWidth, L' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				ofile << str << std::endl;
			}

			ofile << std::endl;
			
			std::wstring str =	Formatting::AddTrailing(L' ' + GLanguageHandler->XText[rsTemporary], TRDescriptionWidth, L' ') +
								Formatting::AddLeading(std::to_wstring(GScanDetails->ExtensionSpread[0][__esCount]), TRQuantityWidth, L' ') + L"  " +
								Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->ExtensionSpread[0][__esCount] / (double)GScanDetails->FileCount), TRAsPercentWidth, L' ') + L"  " +
								Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->ExtensionSpread[0][__esSize]), TRSizeWidth, L' ');

			if (GScanDetails->TotalSize != 0)
			{
				str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->ExtensionSpread[0][__esSize] / (double)GScanDetails->TotalSize), TRAsPercentWidth, L' ');
			}
			else
			{
				str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
			}

			ofile << str << std::endl;

			ofile << GLanguageHandler->TextReport[0] << std::endl;
			ofile << std::endl;
		}
	}


	void ReportDirectoryList(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[5] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[6] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			if (GScanDetails->RootFolders.size() != 0)
			{
				for (int t = 0; t < GScanDetails->RootFolders.size(); t++)
				{
					std::wstring str =	Formatting::AddTrailing(L' ' + GScanDetails->RootFolders[t].Name, TRDescriptionWidth, L' ') +
										Formatting::AddLeading(std::to_wstring(GScanDetails->RootFolders[t].Data[__RootCount]), TRQuantityWidth, L' ') + L"  " +
										Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->RootFolders[t].Data[__RootCount] / (double)GScanDetails->FileCount), TRAsPercentWidth, L' ') + L"  " +
										Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->RootFolders[t].Data[__RootSize]), TRSizeWidth, L' ');

					if (GScanDetails->TotalSize != 0)
					{
						str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->RootFolders[t].Data[__RootSize] / (double)GScanDetails->TotalSize), TRAsPercentWidth, L' ');
					}
					else
					{
						str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
					}

					//      str := str + '  ' + TXFormatting.GetAttributesAsString(GScanDetails.RootFolders[t].Attributes);

					ofile << str << std::endl;
				}
			}
		}

		ofile << GLanguageHandler->TextReport[0] << std::endl << std::endl;
	}


	void ReportFileDates(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[17] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[18] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			if (GScanDetails->FileDates.size() != 0)
			{
				for (int t = 0; t < GScanDetails->FileDates.size(); t++)
				{
					if (GScanDetails->FileDates[t].Count != 0)
					{
						std::wstring str = Formatting::AddTrailing(L' ' + std::to_wstring(GScanDetails->FileDates[t].Year), TRDescriptionWidth, L' ') +
							Formatting::AddLeading(std::to_wstring(GScanDetails->FileDates[t].Count), TRQuantityWidth, L' ') + L"  " +
							Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->FileDates[t].Count / (double)GScanDetails->FileCount), TRAsPercentWidth, L' ') + L"  " +
							Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->FileDates[t].Size), TRSizeWidth, L' ');

						if (GScanDetails->TotalSize != 0)
						{
							str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->FileDates[t].Size / (double)GScanDetails->TotalSize), TRAsPercentWidth, L' ');
						}
						else
						{
							str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
						}

						ofile << str << std::endl;
					}
				}
			}
		}

		ofile << GLanguageHandler->TextReport[0] << std::endl << std::endl;
	}

	
	void ReportMagnitude(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[7] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[2] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < __MagnitudesCount; t++)
			{
				std::wstring str = Formatting::AddTrailing(L' ' + __MagniLabels[t], TRDescriptionWidth, L' ') +
					Formatting::AddLeading(std::to_wstring(GScanDetails->Magnitude[t][__mCount]), TRQuantityWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->Magnitude[t][__mCount] / (double)GScanDetails->FileCount), TRAsPercentWidth, L' ') + L"  " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->Magnitude[t][__mSize]), TRSizeWidth, L' ');

				if (GScanDetails->TotalSize != 0)
				{
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->Magnitude[t][__mSize] / (double)GScanDetails->TotalSize), TRAsPercentWidth, L' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				ofile << str << std::endl;
			}
		}

		ofile << GLanguageHandler->XText[rsFavourite] << std::endl;
		ofile << std::endl;
	}


	void ReportExtensions(std::wofstream &ofile, TextReportOptions options)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[8] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 1; t < __FileCategoriesCount; t++)
			{
				if (options.CategoryList[t])
				{
					ofile << GLanguageHandler->TextReport[2] << std::endl;

					std::wstring str  = Formatting::AddTrailing(L' ' + GLanguageHandler->TypeDescriptions[t], TRDescriptionWidth, L' ') +
										Formatting::AddLeading(std::to_wstring(GScanDetails->ExtensionSpread[t][__esCount]), TRQuantityWidth, L' ') +
										Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->ExtensionSpread[t][__esCount] / (double)GScanDetails->FileCount), TRAsPercentWidth, L' ') +
										Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->ExtensionSpread[t][__esSize]), TRSizeWidth, L' ');

					if (GScanDetails->TotalSize != 0)
					{
						str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->ExtensionSpread[t][__esSize] / (double)GScanDetails->TotalSize), TRAsPercentWidth, L' ');
					}
					else
					{
						str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
					}

					ofile << str << std::endl;
					ofile << L"------------------------------------------------------------------" << std::endl;

					if (t != __FileCategoriesOther)
					{
						for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
						{
							FileExtension tfx = GFileExtensionHandler->Extensions[z];

							if (tfx.Category == t)
							{
								//only include within report if number of files in extension > 0
								if (tfx.Quantity > 0)
								{
									std::wstring str  = Formatting::AddTrailing(L' ' + tfx.Name, TRDescriptionWidth, L' ') + 
														Formatting::AddLeading(std::to_wstring(tfx.Quantity), TRQuantityWidth, ' ') +
														Formatting::AddLeading(Convert::DoubleToPercent((double)tfx.Quantity / (double)GScanDetails->FileCount), TRAsPercentWidth, ' ') +
														Formatting::AddLeading(Convert::ConvertToUsefulUnit(tfx.Size), TRSizeWidth, L' ');

									if (GScanDetails->TotalSize != 0)
									{
										str += Formatting::AddLeading(Convert::DoubleToPercent((double)tfx.Size / (double)GScanDetails->TotalSize), TRAsPercentWidth, L' ');
									}
									else
									{
										str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
									}

									ofile << str << std::endl;
								}
							}
						}
					}
					else
					{
						for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
						{
							if (GFileExtensionHandler->Extensions[z].Category == __Category_Other)
							{
								std::wstring str  = Formatting::AddTrailing(L' ' + GFileExtensionHandler->Extensions[z].Name, TRDescriptionWidth, L' ') +
													Formatting::AddLeading(std::to_wstring(GFileExtensionHandler->Extensions[z].Quantity), TRQuantityWidth, L' ') +
													Formatting::AddLeading(Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z].Quantity / (double)GScanDetails->FileCount), TRAsPercentWidth, L' ') +
													Formatting::AddLeading(Convert::ConvertToUsefulUnit(GFileExtensionHandler->Extensions[z].Size), TRSizeWidth, L' ');

								if (GScanDetails->TotalSize != 0)
								{
									str += Formatting::AddLeading(Convert::DoubleToPercent((double)GFileExtensionHandler->Extensions[z].Size / (double)GScanDetails->TotalSize), TRAsPercentWidth, L' ');
								}
								else
								{
									str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
								}

								ofile << str << std::endl;
							}
						}
					}

					ofile << std::endl;
				}
			}
		}
	}

	void ReportNullFiles(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[9] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		if (GScanDetails->NullFiles.size() != 0)
		{
			for (int t = 0; t < GScanDetails->NullFiles.size(); t++)
			{
				ofile << GScanDetails->NullFiles[t] << std::endl;
			}
		}
		else
		{
			ofile << GLanguageHandler->XText[rsNoneFound] << std::endl;
		}

		ofile << std::endl;

		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[10] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		if (GScanDetails->NullFolders.size() != 0)
		{
			for (int t = 0; t < GScanDetails->NullFolders.size(); t++)
			{
				ofile << GScanDetails->NullFolders[t] << std::endl;
			}
		}
		else
		{
			ofile << GLanguageHandler->XText[rsNoneFound] << std::endl;
		}

		ofile << std::endl;
	}


	void ReportUsers(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[11] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[12] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < GScanDetails->Users.size(); t++)
			{
				std::wstring str  = Formatting::AddTrailing(L' ' + GScanDetails->Users[t].Name, TRDescriptionWidth, L' ') +
									Formatting::AddLeading(std::to_wstring(GScanDetails->Users[t].Data[__UserCount]), TRQuantityWidth, L' ') + L"  " +
									Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->Users[t].Data[__UserCount] / (double)GScanDetails->FileCount), TRAsPercentWidth, L' ') + L"  " +
									Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->Users[t].Data[__UserSize]), TRSizeWidth, L' ');

				if (GScanDetails->TotalSize != 0)
				{
					str += Formatting::AddLeading(Convert::DoubleToPercent((double)GScanDetails->Users[t].Data[__UserSize] / (double)GScanDetails->TotalSize), TRAsPercentWidth, L' ');
				}
				else
				{
					str += Formatting::AddLeading(L"100%", TRAsPercentWidth, L' ');
				}

				ofile << str << std::endl;
			}
		}

		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << std::endl;
	}

	
	void ReportLargestFiles(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[13] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		for (int t = 0; t < GScanDetails->Top100Large.size(); t++)
		{
			ofile << Formatting::AddLeading(Convert::IntDateToString(GScanDetails->Top100Large[t].FileDateC), 9, L' ') + L" " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->Top100Large[t].Size), 14, L' ') + L" " +
					GScanDetails->Folders[GScanDetails->Top100Large[t].FilePathIndex] + GScanDetails->Top100Large[t].FileName << std::endl;
		}

		ofile << std::endl;
	}


	void ReportSmallestFiles(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[14] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		for (int t = 0; t < GScanDetails->Top100Large.size(); t++)
		{
			ofile << Formatting::AddLeading(Convert::IntDateToString(GScanDetails->Top100Small[t].FileDateC), 9, ' ') + L" " +
					Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->Top100Small[t].Size), 14, ' ') + L" " +
					GScanDetails->Folders[GScanDetails->Top100Small[t].FilePathIndex] + GScanDetails->Top100Small[t].FileName << std::endl;
		}

		ofile << std::endl;
	}


	void ReportNewestFiles(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[15] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		for (int t = 0; t < GScanDetails->Top100Newest.size(); t++)
		{
			ofile << Formatting::AddLeading(Convert::IntDateToString(GScanDetails->Top100Newest[t].FileDateC), 9, ' ') + L" " +
				Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->Top100Newest[t].Size), 14, ' ') + L" " +
				GScanDetails->Folders[GScanDetails->Top100Newest[t].FilePathIndex] + GScanDetails->Top100Newest[t].FileName << std::endl;
		}

		ofile << std::endl;
	}


	void ReportOldestFiles(std::wofstream &ofile)
	{
		ofile << GLanguageHandler->TextReport[0] << std::endl;
		ofile << GLanguageHandler->TextReport[16] << std::endl;
		ofile << GLanguageHandler->TextReport[0] << std::endl;

		for (int t = 0; t < GScanDetails->Top100Oldest.size(); t++)
		{
			ofile << Formatting::AddLeading(Convert::IntDateToString(GScanDetails->Top100Oldest[t].FileDateC), 9, ' ') + L" " +
				Formatting::AddLeading(Convert::ConvertToUsefulUnit(GScanDetails->Top100Oldest[t].Size), 14, ' ') + L" " +
				GScanDetails->Folders[GScanDetails->Top100Oldest[t].FilePathIndex] + GScanDetails->Top100Oldest[t].FileName << std::endl;
		}

		ofile << std::endl;
	}
}