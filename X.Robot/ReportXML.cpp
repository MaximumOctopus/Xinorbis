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
#include "ReportXML.h"
#include "ReportXMLReportOptions.h"
#include "ScanDetails.h"
#include "Utility.h"
#include <codecvt>
#include <fstream>
#include <iostream>
#include <string>


extern FileExtensionHandler *GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern ScanDetails* GScanDetails;


namespace ReportXML
{
	void Summary(XMLReportOptions options)
	{
		std::wofstream ofile(options.Filename);

		ofile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

		if (ofile)
		{
			std::wcout << GLanguageHandler->XText[rsSavingReports] + L" (XML):" << std::endl;
			std::wcout << options.Filename << std::endl << std::endl;

			ofile << L"<?xml version=\"1.0\"?>" << std::endl;
			ofile << L"<!-- generated with X.Robot " + __XRVersion + L" - " + __XRDate + L" -->" << std::endl;
			ofile << L"<!-- http://www.xinorbis.com - Paul A Freshney -->" << std::endl;
			ofile << L"<xinorbisreport>" << std::endl;

			for (int t = 0; t < XMLReportOptionsCount; t++)
			{
				if (options.Layout[t])
				{
					switch (t)
					{
					case 0:
						ReportSummary(ofile);
						break;
					case 1:
						ReportFileAttributes(ofile);
						break;
					case 2:
						ReportFileCategory(ofile);
						break;
					case 3:
						ReportFolderList(ofile);
						break;
					case 4:
						ReportMagnitude(ofile);
						break;
					case 5:
						ReportExtensionLists(ofile);
						break;
					case 6:
						ReportNullFiles(ofile);
						break;
					case 7:
						ReportFileDates(ofile);
						break;
					case 8:
						ReportTopLarge(ofile);
						ReportTopSmallest(ofile);
						ReportTopNewest(ofile);
						ReportTopOldest(ofile);
						break;
					case 9:
						ReportUsers(ofile);
						break;
					}
				}
			}

			ofile << L"</xinorbisreport>" << std::endl;

			ofile.close();
		}
		else
		{
			std::wcout << std::endl;
			std::wcout << GLanguageHandler->XText[rsErrorSaving] + L" \"" + options.Filename + L"\"." << std::endl;
			std::wcout << std::endl;
		}
	}


	void ReportSummary(std::wofstream &ofile)
	{
		ofile << L"<information>" << std::endl;

		ofile << Formatting::InsertElement(L"folder", Formatting::ReplaceEntitiesForXML(GScanDetails->ScanPath), 1) << std::endl;
		ofile << Formatting::InsertElement(L"date", Utility::GetDate(__GETTIMEFORMAT_DISPLAY), 1) << std::endl;
		ofile << Formatting::InsertElement(L"time", Utility::GetTime(__GETTIMEFORMAT_DISPLAY), 1) << std::endl;
		ofile << Formatting::InsertElement(L"numberfiles", std::to_wstring(GScanDetails->FileCount), 1) << std::endl;
		ofile << Formatting::InsertElement(L"numberfolders", std::to_wstring(GScanDetails->FolderCount), 1) << std::endl;
		ofile << Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanDetails->TotalSize), 1) << std::endl;
		//ofile << Formatting::InsertElement(L"drivetype", TXWindows.GetDiskTypeString(GScanDetails->ScanPath + ':'), 1) << std::endl;
		//ofile << Formatting::InsertElement(L"sectorspercluster", std::to_wstring(Tmp_SectorsPerCluster), 1) << std::endl;
		//ofile << Formatting::InsertElement(L"bytespersector", std::to_wstring(Tmp_BytesPerSector), 1) << std::endl;
		//ofile << Formatting::InsertElement(L"freeclusters", std::to_wstring(Tmp_FreeClusters), 1) << std::endl;
		//ofile << Formatting::InsertElement(L"totalclusters", std::to_wstring(Tmp_Clusters), 1) << std::endl;
		//ofile << Formatting::InsertElement(L"volumename", Volname, 1) << std::endl;
		//ofile << Formatting::InsertElement(L"serialnumber", std::to_wstring(SerialNumber, 8), 1) << std::endl;
		//ofile << Formatting::InsertElement(L"filesystem", FileSysName, 1) << std::endl;

		if (GScanDetails->DiskStats.DriveSpaceFree != 0)
		{
			ofile << Formatting::InsertElement(L"diskspacefree", Convert::ConvertToUsefulUnit(GScanDetails->DiskStats.DriveSpaceFree), 1) << std::endl;
			ofile << Formatting::InsertElement(L"diskspacemax", Convert::ConvertToUsefulUnit(GScanDetails->DiskStats.DriveSpaceTotal), 1) << std::endl;
		}
		else
		{
			ofile << Formatting::InsertElement(L"diskspacefree", L"0", 1) << std::endl;
			ofile << Formatting::InsertElement(L"diskspacemax", L"0", 1) << std::endl;
		}

		ofile << L"</information>" << std::endl;
	}


	void ReportFileAttributes(std::wofstream &ofile)
	{
		//-----------------------------------------------------------------
		//file attributes -------------------------------------------------
		//-----------------------------------------------------------------
		ofile << L"<categorylist>" << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < __AttributesCount; t++)
			{
				ofile << L"  <attribute name=\"" + GLanguageHandler->LanguageTypes[t] + L"\">" << std::endl;
				ofile << Formatting::InsertElement(L"numberfiles", std::to_wstring(GScanDetails->FileAttributes[t][__faCount]), 2) << std::endl;
				ofile << Formatting::InsertElement(L"numberfilesaspercent", Convert::DoubleToPercent((double)GScanDetails->FileAttributes[t][__faCount] / (double)GScanDetails->FileCount), 2) << std::endl;
				ofile << Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanDetails->FileAttributes[t][__faSize]), 2) << std::endl;

				if (GScanDetails->TotalSize != 0)
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", Convert::DoubleToPercent((double)GScanDetails->FileAttributes[t][__faSize] / (double)GScanDetails->TotalSize), 2) << std::endl;
				}
				else
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", L"100%", 2) << std::endl;
				}

				ofile << L"  </attribute>" << std::endl;
			}
		}

		ofile << L"</categorylist>" << std::endl;
	}


	void ReportFileCategory(std::wofstream &ofile)
	{
		//-----------------------------------------------------------------
		//file category table----------------------------------------------
		//-----------------------------------------------------------------
		ofile << L"<categorylist>" << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < __FileCategoriesCount; t++)
			{
				ofile << L"  <category name=\"" + GLanguageHandler->TypeDescriptions[t] + L"\" >" << std::endl;
				ofile << Formatting::InsertElement(L"umberfiles", std::to_wstring(GScanDetails->ExtensionSpread[t][__esCount]), 2) << std::endl;
				ofile << Formatting::InsertElement(L"numberfilesaspercent", std::to_wstring(std::round(((double)GScanDetails->ExtensionSpread[t][__esCount] / (double)GScanDetails->FileCount) * 100)), 2) << std::endl;

				ofile << Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanDetails->ExtensionSpread[t][__esSize]), 2) << std::endl;

				if (GScanDetails->TotalSize != 0)
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)GScanDetails->ExtensionSpread[t][__esSize] / (double)GScanDetails->TotalSize) * 100)), 2) << std::endl;
				}
				else
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) << std::endl;
				}

				ofile << L"  </category>" << std::endl;
			}
		}

		ofile << L"</categorylist>" << std::endl;
	}


	void ReportFolderList(std::wofstream &ofile)
	{
		//----------------------------------------------------------------------------
		// --directory list---by file count-------------------------------------------
		//----------------------------------------------------------------------------
		ofile << L"<folderlist>" << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < GScanDetails->RootFolders.size(); t++)
			{
				ofile << L"  <folder name=\"" + GScanDetails->RootFolders[t].Name + L"\" hidden=\"" + Utility::BoolToString((GScanDetails->RootFolders[t].Attributes & FILE_ATTRIBUTE_HIDDEN) == FILE_ATTRIBUTE_HIDDEN) + L"\">" << std::endl;

				ofile << Formatting::InsertElement(L"numberoffiles", std::to_wstring(GScanDetails->RootFolders[t].Data[__RootCount]), 2) << std::endl;
				ofile << Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)GScanDetails->RootFolders[t].Data[__RootCount] / (double)GScanDetails->FileCount) * 100)), 2) << std::endl;
				ofile << Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanDetails->RootFolders[t].Data[__RootSize]), 2) << std::endl;

				if (GScanDetails->TotalSize != 0)
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)GScanDetails->RootFolders[t].Data[__RootSize] / (double)GScanDetails->TotalSize) * 100)), 2) << std::endl;
				}
				else
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) << std::endl;
				}

				ofile << L"  </folder>" << std::endl;
			}
		}

		ofile << L"</folderlist>" << std::endl;
	}


	void ReportMagnitude(std::wofstream &ofile)
	{
		//-----------------------------------------------------------------
		//-- magnitudes ---------------------------------------------------
		//-----------------------------------------------------------------
		ofile << L"<magnitudelist>" << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < __MagnitudesCount; t++)
			{
				ofile << L"  <magnitude name=\"" + __MagniLabels3[t] + L"\">" << std::endl;
				ofile << Formatting::InsertElement(L"numberoffiles", std::to_wstring(GScanDetails->Magnitude[t][__mCount]), 2) << std::endl;
				ofile << Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)GScanDetails->Magnitude[t][__mCount] / (double)GScanDetails->FileCount) * 100)), 2) << std::endl;
				ofile << Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanDetails->Magnitude[t][__mSize]), 2) << std::endl;

				if (GScanDetails->TotalSize != 0)
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)GScanDetails->Magnitude[t][__mSize] / (double)GScanDetails->TotalSize) * 100)), 2) << std::endl;
				}
				else
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) << std::endl;
				}

				ofile << L"  </magnitude>" << std::endl;
			}
		}

		ofile << L"</magnitudelist>" << std::endl;
	}


	void ReportExtensionLists(std::wofstream &ofile)
	{
		//-----------------------------------------------------------------
		//----- extension lists -------------------------------------------
		//-----------------------------------------------------------------
		for (int t = 1; t < __FileCategoriesCount; t++)
		{
			ofile << L"<extensiondata>" << std::endl;

			if (GScanDetails->FileCount != 0)
			{
				ofile << L"  <extensioncategory name=\"" + GLanguageHandler->TypeDescriptions[t] + L"\">" << std::endl;
				ofile << Formatting::InsertElement(L"numberoffiles", std::to_wstring(GScanDetails->ExtensionSpread[t][__esCount]), 2) << std::endl;
				ofile << Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)GScanDetails->ExtensionSpread[t][__esCount] / (double)GScanDetails->FileCount) * 100)), 2) << std::endl;
				ofile << Formatting::InsertElement(L"sizoffiles", Convert::ConvertToUsefulUnit(GScanDetails->ExtensionSpread[t][__esSize]), 2) << std::endl;

				if (GScanDetails->TotalSize != 0)
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)GScanDetails->ExtensionSpread[t][__esSize] / (double)GScanDetails->TotalSize) * 100)), 2) << std::endl;
				}
				else
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) << std::endl;
				}

				ofile << L"  </extensioncategory>" << std::endl;

				if (t <= 9)
				{
					for (int z = 0; z < GFileExtensionHandler->Extensions.size(); z++)
					{
						FileExtension tfx = GFileExtensionHandler->Extensions[z];

						if (tfx.Category == t)
						{
							//only include within report if number of files in extension > 0
							if (tfx.Quantity > 0)
							{
								ofile << L"  <extension name=\"" + tfx.Name + L"\">" << std::endl;
								ofile << Formatting::InsertElement(L"numberoffiles", std::to_wstring(tfx.Quantity), 2) << std::endl;
								ofile << Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)tfx.Quantity / (double)GScanDetails->FileCount) * 100)), 2) << std::endl;
								ofile << Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(tfx.Size), 2) << std::endl;

								if (GScanDetails->TotalSize != 0)
								{
									ofile << Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)tfx.Size / (double)GScanDetails->TotalSize) * 100)), 2) << std::endl;
								}
								else
								{
									ofile << Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) << std::endl;
								}

								ofile << L"  </extension>" << std::endl;
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
							ofile << L"  <extension name=\"" + GFileExtensionHandler->Extensions[z].Name + L"\" >" << std::endl;
							ofile << Formatting::InsertElement(L"numberoffiles", std::to_wstring(GFileExtensionHandler->Extensions[z].Quantity), 2) << std::endl;
							ofile << Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)GFileExtensionHandler->Extensions[z].Quantity / (double)GScanDetails->FileCount) * 100)), 2) << std::endl;
							ofile << Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GFileExtensionHandler->Extensions[z].Size), 2) << std::endl;

							if (GScanDetails->TotalSize != 0)
							{
								ofile << Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)GFileExtensionHandler->Extensions[z].Size / (double)GScanDetails->TotalSize) * 100)), 2) << std::endl;
							}
							else
							{
								ofile << Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) << std::endl;
							}

							ofile << L"  </extension>" << std::endl;
						}
					}
				}

				ofile << L"</extensiondata>" << std::endl;
			}
		}
	}


	void ReportNullFiles(std::wofstream &ofile)
	{
		//-----------------------------------------------------------------
		//--null files ----------------------------------------------------
		//-----------------------------------------------------------------

		if (GScanDetails->NullFiles.size() != 0)
		{
			ofile << L"<nullfiles>" << std::endl;

			for (int t = 0; t < GScanDetails->NullFiles.size(); t++)
			{
				ofile << L"  <nullfile name=\"" + Formatting::ReplaceEntitiesForXML(GScanDetails->NullFiles[t]) + L"\" />" << std::endl;
			}

			ofile << L"</nullfiles>" << std::endl;
		}
		else
		{
			ofile << L"<nullfiles />" << std::endl;
		}

		if (GScanDetails->NullFolders.size() != 0)
		{
			ofile << L"<nullfolders>" << std::endl;

			for (int t = 0; t < GScanDetails->NullFiles.size(); t++)
			{
				ofile << L"  <nullfolder name=\"" + Formatting::ReplaceEntitiesForXML(GScanDetails->NullFolders[t]) + L"\" />" << std::endl;
			}

			ofile << L"</nullfolders>" << std::endl;
		}
		else
		{
			ofile << L"<nullfolders />" << std::endl;
		}
	}


	void ReportFileDates(std::wofstream &ofile)
	{
		ofile << L"<filedates type=\"created\">" << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < GScanDetails->FileDates.size(); t++)
			{

				if (GScanDetails->FileDates[t].Count != 0)
				{
					ofile << L"  <filedate year=\"" + std::to_wstring(GScanDetails->FileDates[t].Year) + L"\">" << std::endl;
					ofile << L"    <filecount percentage=\"" + Convert::DoubleToPercent((double)GScanDetails->FileDates[t].Count / (double)GScanDetails->FileCount) + L"\">" + std::to_wstring(GScanDetails->FileDates[t].Count) + L"</filecount>" << std::endl;

					if (GScanDetails->TotalSize != 0)
					{
						ofile << L"    <filesize percentage=\"" + Convert::DoubleToPercent((double)GScanDetails->FileDates[t].Size / (double)GScanDetails->TotalSize) + L"\">" + std::to_wstring(GScanDetails->FileDates[t].Size) + L"</filesize>" << std::endl;
					}
					else
					{
						ofile << L"    <filesize percentage=\"100%\">0</filesize>" << std::endl;
					}

					ofile << L"  </filedate>" << std::endl;
				}
			}
		}

		ofile << L"</filedates>" << std::endl;
	}


	void ReportUsers(std::wofstream &ofile)
	{
		ofile << L"<users>" << std::endl;

		if (GScanDetails->FileCount != 0)
		{
			for (int t = 0; t < GScanDetails->Users.size(); t++)
			{
				ofile << L"<user name=\"" + GScanDetails->Users[t].Name + L"\">" << std::endl;
				ofile << Formatting::InsertElement(L"numberfiles", std::to_wstring(GScanDetails->Users[t].Data[__UserCount]), 2) << std::endl;
				ofile << Formatting::InsertElement(L"numberfilesaspercent", Convert::DoubleToPercent((double)GScanDetails->Users[t].Data[__UserCount] / (double)GScanDetails->FileCount), 2) << std::endl;
				ofile << Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanDetails->Users[t].Data[__UserSize]), 2) << std::endl;

				if (GScanDetails->TotalSize != 0)
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", Convert::DoubleToPercent((double)GScanDetails->Users[t].Data[__UserSize] / (double)GScanDetails->TotalSize), 2) << std::endl;
				}
				else
				{
					ofile << Formatting::InsertElement(L"sizeoffilesaspercent", L"100%", 2) << std::endl;
				}

				ofile << L"</user>" << std::endl;
			}
		}

		ofile << L"</users>" << std::endl;
	}

	
	void ReportTopLarge(std::wofstream &ofile)
	{
		ofile << L"<top101largest>" << std::endl;

		for (int t = 0; t <GScanDetails->Top100Large.size(); t++)
		{
			ofile << L"  <top101large sizebytes=\"" + std::to_wstring(GScanDetails->Top100Large[t].Size) + L"\">" +
				Formatting::ReplaceEntitiesForXML(GScanDetails->Folders[GScanDetails->Top100Large[t].FilePathIndex] + GScanDetails->Top100Large[t].FileName) +
				L"</top101large>" << std::endl;
		}

		ofile << L"</top101largest>" << std::endl;
	}


	void ReportTopSmallest(std::wofstream &ofile)
	{
		ofile << L"<top101smallest>" << std::endl;

		for (int t = 0; t < GScanDetails->Top100Large.size(); t++)
		{
			ofile << L"  <top5101small sizebytes=\"" + std::to_wstring(GScanDetails->Top100Small[t].Size) + L"\">" +
				Formatting::ReplaceEntitiesForXML(GScanDetails->Folders[GScanDetails->Top100Small[t].FilePathIndex] + GScanDetails->Top100Small[t].FileName) +
				L"</top101small>" << std::endl;
		}

		ofile << L"</top101smallest>" << std::endl;
	}


	void ReportTopNewest(std::wofstream &ofile)
	{
		ofile << L"<top101newest>" << std::endl;

		for (int t = 0; t < GScanDetails->Top100Newest.size(); t++)
		{
			ofile << L"  <top101new date=\"" << Convert::IntDateToString(GScanDetails->Top100Newest[t].FileDateC) << L"\" " <<
				L"sizebytes=\"" << GScanDetails->Top100Newest[t].Size << L"\" " <<
				L"size=\"" << Convert::ConvertToUsefulUnit(GScanDetails->Top100Newest[t].Size) << L"\" " <<
				L"owner=\"" << GScanDetails->Users[GScanDetails->Top100Newest[t].Owner].Name << L"\">" <<
				Formatting::ReplaceEntitiesForXML(GScanDetails->Folders[GScanDetails->Top100Newest[t].FilePathIndex] + GScanDetails->Top100Newest[t].FileName) +
				L"</top101new>" << std::endl;
		}
		
		ofile << L"</top101newest>" << std::endl;
	}


	void ReportTopOldest(std::wofstream &ofile)
	{	
		ofile << L"<top101oldest>" << std::endl;

		for (int t = 0; t < GScanDetails->Top100Oldest.size(); t++)
		{
			ofile << L"  <top101old date=\"" << Convert::IntDateToString(GScanDetails->Top100Oldest[t].FileDateC) << L"\" " <<
				L"sizebytes=\"" << GScanDetails->Top100Oldest[t].Size << L"\" " <<
				L"size=\"" << Convert::ConvertToUsefulUnit(GScanDetails->Top100Oldest[t].Size) << L"\" " <<
				L"owner=\"" << GScanDetails->Users[GScanDetails->Top100Oldest[t].Owner].Name << L"\">" <<
				Formatting::ReplaceEntitiesForXML(GScanDetails->Folders[GScanDetails->Top100Oldest[t].FilePathIndex] + GScanDetails->Top100Oldest[t].FileName) +
				L"</top101old>" << std::endl;
		}

		ofile << L"</top101oldest>" << std::endl;
	}

	
	void FullList(XMLReportOptions options)
	{
		std::wofstream ofile(options.Filename);

		ofile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

		if (ofile)
		{
			std::wcout << GLanguageHandler->XText[rsSavingReports] + L" (XML Full List): " << std::endl;
			std::wcout << std::endl;

			ofile << L"<?xml version=\"1.0\"?>" << std::endl;
			ofile << L"<!--  -->" << std::endl;
			ofile << L"<!-- generated with X.Robot " + __XRVersion + L" - " + __XRDate + L" -->" << std::endl;
			ofile << L"<!-- http://xinorbis.com - Paul A Freshney -->" << std::endl;
			ofile << L"<!--  -->" << std::endl;
			ofile << L"<xinorbisfilelist>" << std::endl;

			for (int t = 0; t < GScanDetails->Files.size(); t++)
			{
				ofile << L"<item>" << std::endl;
				ofile << Formatting::InsertElement(L"name", Formatting::ReplaceEntitiesForXML(GScanDetails->Files[t].FileName), 2) << std::endl;
				ofile << Formatting::InsertElement(L"path", Formatting::ReplaceEntitiesForXML(GScanDetails->Folders[GScanDetails->Files[t].FilePathIndex]), 2) << std::endl;

				if (GScanDetails->Files[t].Attributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					ofile << Formatting::InsertElement(L"sizewords", L"-1", 2) << std::endl;
					ofile << Formatting::InsertElement(L"sizebytes", L"-1", 2) << std::endl;
					ofile << Formatting::InsertElement(L"sizeondiskwords", L"-1", 2) << std::endl;
					ofile << Formatting::InsertElement(L"sizeondiskbytes", L"-1", 2) << std::endl;
				}
				else
				{
					ofile << Formatting::InsertElement(L"sizewords",		Convert::ConvertToUsefulUnit(GScanDetails->Files[t].Size), 2) << std::endl;

					ofile << Formatting::InsertElement(L"sizebytes",		std::to_wstring(GScanDetails->Files[t].Size), 2) << std::endl;
					ofile << Formatting::InsertElement(L"sizeondiskwords",	Convert::ConvertToUsefulUnit(GScanDetails->Files[t].SizeOnDisk), 2) << std::endl;
					ofile << Formatting::InsertElement(L"sizeondiskbytes",  std::to_wstring(GScanDetails->Files[t].SizeOnDisk), 2) << std::endl;
				}

				ofile << Formatting::InsertElement(L"owner",				GScanDetails->Users[GScanDetails->Files[t].Owner].Name, 2) << std::endl;
				ofile << Formatting::InsertElement(L"timecreated",			std::to_wstring(GScanDetails->Files[t].FileTimeC), 2) << std::endl;
				ofile << Formatting::InsertElement(L"timemodified",			std::to_wstring(GScanDetails->Files[t].FileTimeM), 2) << std::endl;
				ofile << Formatting::InsertElement(L"timeaccessed",			std::to_wstring(GScanDetails->Files[t].FileTimeA), 2) << std::endl;
				ofile << Formatting::InsertElement(L"datecreated",			Convert::IntDateToString(GScanDetails->Files[t].FileDateC), 2) << std::endl;
				ofile << Formatting::InsertElement(L"datemodified",			Convert::IntDateToString(GScanDetails->Files[t].FileDateM), 2) << std::endl;
				ofile << Formatting::InsertElement(L"dateaccessed",			Convert::IntDateToString(GScanDetails->Files[t].FileDateA), 2) << std::endl;
				ofile << Formatting::InsertElement(L"datecreatedyyyymmdd",	std::to_wstring(GScanDetails->Files[t].FileDateC), 2) << std::endl;
				ofile << Formatting::InsertElement(L"datemodifiedyyyymmdd", std::to_wstring(GScanDetails->Files[t].FileDateM), 2) << std::endl;
				ofile << Formatting::InsertElement(L"dateaccessedyyyymmdd", std::to_wstring(GScanDetails->Files[t].FileDateA), 2) << std::endl;
				ofile << Formatting::InsertElement(L"category",				std::to_wstring(GScanDetails->Files[t].Category), 2) << std::endl;
				ofile << Formatting::InsertElement(L"folder",				Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_DIRECTORY), 2) << std::endl;
				ofile << Formatting::InsertElement(L"readonly",				Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_READONLY), 2) << std::endl;
				ofile << Formatting::InsertElement(L"hidden",				Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_HIDDEN), 2) << std::endl;
				ofile << Formatting::InsertElement(L"system",				Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_SYSTEM), 2) << std::endl;
				ofile << Formatting::InsertElement(L"archive",				Convert::AttributeToIntAsString(GScanDetails->Files[t].Attributes, FILE_ATTRIBUTE_ARCHIVE), 2) << std::endl;
				ofile << Formatting::InsertElement(L"temp",					Convert::BoolToString(GScanDetails->Files[t].Temp), 2) << std::endl;
				ofile << L"</item>" << std::endl;
			}

			ofile << L"</xinorbisfilelist>" << std::endl;

			ofile.close();
		}
	}
};