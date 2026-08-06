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

#include <cmath>
#include <fstream>
#include <string>
#include <Windows.h>

#include "ConstantsSystem.h"
#include "Convert.h"
#include "FileDateObject.h"
#include "FileExtension.h"
#include "FileExtensionHandler.h"
#include "FileObject.h"
#include "Formatting.h"
#include "LanguageHandler.h"
#include "ConstantsReports.h"
#include "ReportXML.h"
#include "ReportXMLOptions.h"
#include "RootFolder.h"
#include "ScanEngine.h"
#include "UserData.h"
#include "Utility.h"
#include "WindowsUtility.h"


extern FileExtensionHandler *GFileExtensionHandler;
extern LanguageHandler* GLanguageHandler;
extern ScanEngine* GScanEngine;


namespace ReportXML
{
	void Summary(XMLReportOptions options, std::vector<std::wstring> *data, int DataSource)
	{
		//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (XML):\n";
		//GLog->Add( options.FileName << "\n\n";

		data->push_back(L"<?xml version=\"1.0\"?>\n");
		data->push_back(L"<!-- generated with FolderScanUltra " + __XVersion + L" - " + __XDate + L" -->\n");
		data->push_back(L"<!-- https://github.com/MaximumOctopus/FolderScanUltra - Paul A Freshney -->\n");
		data->push_back(L"<folderscaneultrareport>\n");

		for (int t = 0; t < XMLReportOptionsCount; t++)
		{
			if (options.Layout[t])
			{
				switch (t)
				{
				case 0:
					ReportSummary(data, DataSource);
					break;
				case 1:
					ReportFileAttributes(data, DataSource);
					break;
				case 2:
					ReportFileCategory(data, DataSource);
					break;
				case 3:
					ReportFolderList(data, DataSource);
					break;
				case 4:
					ReportMagnitude(data, DataSource);
					break;
				case 5:
					ReportExtensionLists(data, DataSource);
					break;
				case 6:
					ReportNullFiles(data, DataSource);
					break;
				case 7:
					ReportFileDates(data, DataSource);
					break;
				case 8:
					ReportTopLarge(data, DataSource);
					ReportTopSmallest(data, DataSource);
					ReportTopNewest(data, DataSource);
					ReportTopOldest(data, DataSource);
					break;
				case 9:
					ReportUsers(data, DataSource);
					break;
				case 10:
					ReportTemporaryFiles(data, DataSource);
					break;
				}
			}
		}

		data->push_back(L"</folderscanultrareport>\n");
	}


	void ReportSummary(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<information>\n");

		data->push_back(Formatting::InsertElement(L"folder", Formatting::ReplaceEntitiesForXML(GScanEngine->Data[DataSource].Path.String), 1) + L"\n");
		data->push_back(Formatting::InsertElement(L"date", Utility::GetDate(DateTimeFormat::Display), 1) + L"\n");
		data->push_back(Formatting::InsertElement(L"time", Utility::GetTime(DateTimeFormat::Display), 1) + L"\n");
		data->push_back(Formatting::InsertElement(L"numberfiles", std::to_wstring(GScanEngine->Data[DataSource].FileCount), 1) + L"\n");
		data->push_back(Formatting::InsertElement(L"numberfolders", std::to_wstring(GScanEngine->Data[DataSource].FolderCount), 1) + L"\n");
		data->push_back(Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].TotalSize), 1) + L"\n");
		data->push_back(Formatting::InsertElement(L"drivetype", WindowsUtility::GetDiskTypeString(GScanEngine->Data[DataSource].GetDrive()), 1) + L"\n");

		if (GScanEngine->Data[DataSource].Source == ScanSource::FileCSV)
		{
			data->push_back(Formatting::InsertElement(L"csvsource", Formatting::ReplaceEntitiesForXML(GScanEngine->Data[DataSource].Path.FileName), 1) + L"\n");
		}

		if (GScanEngine->FilterCategory != -1)
		{
			data->push_back(Formatting::InsertElement(L"filtercategory", std::to_wstring(GScanEngine->FilterCategory), 1) + L"\n");
			data->push_back(Formatting::InsertElement(L"filtercategoryname", kFileExtensionFileName[GScanEngine->FilterCategory], 1) + L"\n");
		}

		//ofile << Formatting::InsertElement(L"sectorspercluster", std::to_wstring(Tmp_SectorsPerCluster), 1) << "\n";
		//ofile << Formatting::InsertElement(L"bytespersector", std::to_wstring(Tmp_BytesPerSector), 1) << "\n";
		//ofile << Formatting::InsertElement(L"freeclusters", std::to_wstring(Tmp_FreeClusters), 1) << "\n";
		//ofile << Formatting::InsertElement(L"totalclusters", std::to_wstring(Tmp_Clusters), 1) << "\n";
		//ofile << Formatting::InsertElement(L"volumename", Volname, 1) << "\n";
		//ofile << Formatting::InsertElement(L"serialnumber", std::to_wstring(SerialNumber, 8), 1) << "\n";
		//ofile << Formatting::InsertElement(L"filesystem", FileSysName, 1) << "\n";

		if (GScanEngine->Data[DataSource].DiskStats.DriveSpaceFree != 0)
		{
			data->push_back(Formatting::InsertElement(L"diskspacefree", Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].DiskStats.DriveSpaceFree), 1) + L"\n");
			data->push_back(Formatting::InsertElement(L"diskspacemax", Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].DiskStats.DriveSpaceTotal), 1) + L"\n");
		}
		else
		{
			data->push_back(Formatting::InsertElement(L"diskspacefree", L"0", 1) + L"\n");
			data->push_back(Formatting::InsertElement(L"diskspacemax", L"0", 1) + L"\n");
		}

		if (GScanEngine->FilterCategory != -1)
		{
			data->push_back(Formatting::InsertElement(L"filtercategory", std::to_wstring(GScanEngine->FilterCategory), 1) + L"\n");
			data->push_back(Formatting::InsertElement(L"filtercategoryname", kFileExtensionFileName[GScanEngine->FilterCategory], 1) + L"\n");
		}

		data->push_back(L"</information>\n");
	}


	void ReportFileAttributes(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<categorylist>\n");

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			for (int t = 0; t < kAttributesToDisplayCount; t++)
			{
				data->push_back(L"  <attribute name=\"" + GLanguageHandler->LanguageTypes[t] + L"\">\n");
				data->push_back(Formatting::InsertElement(L"numberfiles", std::to_wstring(GScanEngine->Data[DataSource].FileAttributes[t].Count), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"numberfilesaspercent", Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].FileAttributes[t].Count / (double)GScanEngine->Data[DataSource].FileCount), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].FileAttributes[t].Size), 2) + L"\n");

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", Convert::DoubleToPercent((double)GScanEngine->Data[DataSource].FileAttributes[t].Size / (double)GScanEngine->Data[DataSource].TotalSize), 2) + L"\n");
				}
				else
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", L"100%", 2) + L"\n");
				}

				data->push_back(L"  </attribute>\n");
			}
		}

		data->push_back(L"</categorylist>\n");
	}


	void ReportFileCategory(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<categorylist>\n");

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			for (int t = 0; t < kFileCategoriesCount; t++)
			{
				data->push_back(L"  <category name=\"" + GLanguageHandler->TypeDescriptions[t] + L"\" >\n");
				data->push_back(Formatting::InsertElement(L"umberfiles", std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"numberfilesaspercent", std::to_wstring(std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100)), 2) + L"\n");

				data->push_back(Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size), 2) + L"\n");

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100)), 2) + L"\n");
				}
				else
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) + L"\n");
				}

				data->push_back(L"  </category>)\n");
			}
		}

		data->push_back(L"</categorylist>\n");
	}


	void ReportFolderList(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<folderlist>\n");

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			for (RootFolder *rootfolder : GScanEngine->Data[DataSource].RootFolders)
			{
				data->push_back(L"  <folder name=\"" + rootfolder->Name + L"\" hidden=\"" + Utility::BoolToString((rootfolder->Attributes & FILE_ATTRIBUTE_HIDDEN) == FILE_ATTRIBUTE_HIDDEN) + L"\">\n");

				data->push_back(Formatting::InsertElement(L"numberoffiles", std::to_wstring(rootfolder->Count), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)rootfolder->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100)), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(rootfolder->Size), 2) + L"\n");

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)rootfolder->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100)), 2) + L"\n");
				}
				else
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) + L"\n");
				}

				data->push_back(L"  </folder>\n");
			}
		}

		data->push_back(L"</folderlist>\n");
	}


	void ReportMagnitude(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<magnitudelist>\n");

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			for (int t = 0; t < kMagnitudesCount; t++)
			{
				data->push_back(L"  <magnitude name=\"" + kMagnitudeLabels[t] + L"\">\n");
				data->push_back(Formatting::InsertElement(L"numberoffiles", std::to_wstring(GScanEngine->Data[DataSource].Magnitude[t].Count), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)GScanEngine->Data[DataSource].Magnitude[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100)), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].Magnitude[t].Size), 2) + L"\n");

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)GScanEngine->Data[DataSource].Magnitude[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100)), 2) + L"\n");
				}
				else
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) + L"\n");
				}

				data->push_back(L"  </magnitude>\n");
			}
		}

		data->push_back(L"</magnitudelist>\n");
	}


	void ReportExtensionLists(std::vector<std::wstring> *data, int DataSource)
	{
		for (int t = 1; t < kFileCategoriesCount; t++)
		{
			data->push_back(L"<extensiondata>\n");

			if (GScanEngine->Data[DataSource].FileCount != 0)
			{
				data->push_back(L"  <extensioncategory name=\"" + GLanguageHandler->TypeDescriptions[t] + L"\">\n");
				data->push_back(Formatting::InsertElement(L"numberoffiles", std::to_wstring(GScanEngine->Data[DataSource].ExtensionSpread[t].Count), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Count / (double)GScanEngine->Data[DataSource].FileCount) * 100)), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"sizoffiles", Convert::ConvertToUsefulUnit(GScanEngine->Data[DataSource].ExtensionSpread[t].Size), 2) + L"\n");

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)GScanEngine->Data[DataSource].ExtensionSpread[t].Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100)), 2) + L"\n");
				}
				else
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) + L"\n");
				}

				data->push_back(L"  </extensioncategory>\n");

				if (t <= 9)
				{
					for (FileExtension *tfx : GFileExtensionHandler->Extensions)
					{
						if (tfx->Category == t)
						{
							//only include within report if number of files in extension > 0
							if (tfx->Count > 0)
							{
								data->push_back(L"  <extension name=\"" + tfx->Name + L"\">\n");
								data->push_back(Formatting::InsertElement(L"numberoffiles", std::to_wstring(tfx->Count), 2) + L"\n");
								data->push_back(Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)tfx->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100)), 2) + L"\n");
								data->push_back(Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(tfx->Size), 2) + L"\n");

								if (GScanEngine->Data[DataSource].TotalSize != 0)
								{
									data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)tfx->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100)), 2) + L"\n");
								}
								else
								{
									data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) + L"\n");
								}

								data->push_back(L"  </extension>\n");
							}
						}
					}
				}
				else
				{
					for (FileExtension *tfx : GFileExtensionHandler->Extensions)
					{
						if (tfx->Category == kCategory_Other)
						{
							data->push_back(L"  <extension name=\"" + tfx->Name + L"\">\n");
							data->push_back(Formatting::InsertElement(L"numberoffiles", std::to_wstring(tfx->Count), 2) + L"\n");
							data->push_back(Formatting::InsertElement(L"numberoffilesaspercent", std::to_wstring(std::round(((double)tfx->Count / (double)GScanEngine->Data[DataSource].FileCount) * 100)), 2) + L"\n");
							data->push_back(Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(tfx->Size), 2) + L"\n");

							if (GScanEngine->Data[DataSource].TotalSize != 0)
							{
								data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", std::to_wstring(std::round(((double)tfx->Size / (double)GScanEngine->Data[DataSource].TotalSize) * 100)), 2) + L"\n");
							}
							else
							{
								data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", L"100", 2) + L"\n");
							}

							data->push_back(L"  </extension>\n");
						}
					}
				}

				data->push_back(L"</extensiondata>\n");
			}
		}
	}


	void ReportNullFiles(std::vector<std::wstring> *data, int DataSource)
	{
		if (GScanEngine->Data[DataSource].NullFiles.size() != 0)
		{
			data->push_back(L"<nullfiles>\n");

			for (std::wstring file : GScanEngine->Data[DataSource].NullFiles)
			{
				data->push_back(L"  <nullfile name=\"" + Formatting::ReplaceEntitiesForXML(file) + L"\" />\n");
			}

			data->push_back(L"</nullfiles>\n");
		}
		else
		{
			data->push_back(L"<nullfiles />\n");
		}

		if (GScanEngine->Data[DataSource].NullFolders.size() != 0)
		{
			data->push_back(L"<nullfolders>\n");

			for (std::wstring folder : GScanEngine->Data[DataSource].NullFolders)
			{
				data->push_back(L"  <nullfolder name=\"" + Formatting::ReplaceEntitiesForXML(folder) + L"\" />\n");
			}

			data->push_back(L"</nullfolders>\n");
		}
		else
		{
			data->push_back(L"<nullfolders />\n");
		}
	}


	void ReportTemporaryFiles(std::vector<std::wstring> *data, int DataSource)
	{
		if (GScanEngine->Data[DataSource].TemporaryFiles.size() != 0)
		{
			data->push_back(L"<tempfiles>\n");

			for (std::wstring file : GScanEngine->Data[DataSource].TemporaryFiles)
			{
				data->push_back(L"  <tempfile name=\"" + Formatting::ReplaceEntitiesForXML(file) + L"\" />\n");
			}

			data->push_back(L"</tempfiles>\n");
		}
		else
		{
			data->push_back(L"<tempfiles />\n");
		}
	}


	void ReportFileDates(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<filedates type=\"created\">\n");

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			for (FileDateObject *fdo : GScanEngine->Data[DataSource].FileDates)
			{
				if (fdo->Count != 0)
				{
					data->push_back(L"  <filedate year=\"" + std::to_wstring(fdo->Year) + L"\">\n");
					data->push_back(L"    <filecount percentage=\"" + Convert::DoubleToPercent((double)fdo->Count / (double)GScanEngine->Data[DataSource].FileCount) + L"\">" + std::to_wstring(fdo->Count) + L"</filecount>\n");

					if (GScanEngine->Data[DataSource].TotalSize != 0)
					{
						data->push_back(L"    <filesize percentage=\"" + Convert::DoubleToPercent((double)fdo->Size / (double)GScanEngine->Data[DataSource].TotalSize) + L"\">" + std::to_wstring(fdo->Size) + L"</filesize>\n");
					}
					else
					{
						data->push_back(L"    <filesize percentage=\"100%\">0</filesize>\n");
					}

					data->push_back(L"  </filedate>\n");
				}
			}
		}

		data->push_back(L"</filedates>\n");
	}


	void ReportUsers(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<users>\n");

		if (GScanEngine->Data[DataSource].FileCount != 0)
		{
			for (UserData *user : GScanEngine->Data[DataSource].Users)
			{
				data->push_back(L"<user name=\"" + user->Name + L"\">\n");
				data->push_back(Formatting::InsertElement(L"numberfiles", std::to_wstring(user->Count), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"numberfilesaspercent", Convert::DoubleToPercent((double)user->Count / (double)GScanEngine->Data[DataSource].FileCount), 2) + L"\n");
				data->push_back(Formatting::InsertElement(L"sizeoffiles", Convert::ConvertToUsefulUnit(user->Size), 2) + L"\n");

				if (GScanEngine->Data[DataSource].TotalSize != 0)
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", Convert::DoubleToPercent((double)user->Size / (double)GScanEngine->Data[DataSource].TotalSize), 2) + L"\n");
				}
				else
				{
					data->push_back(Formatting::InsertElement(L"sizeoffilesaspercent", L"100%", 2) + L"\n");
				}

				data->push_back(L"</user>\n");
			}
		}

		data->push_back(L"</users>\n");
	}


	void ReportTopLarge(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<top101largest>\n");

		for (FileObject *file : GScanEngine->Data[DataSource].Top100Large)
		{
			data->push_back(L"  <top101large sizebytes=\"" + std::to_wstring(file->Size) + L"\">" +
				Formatting::ReplaceEntitiesForXML(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name) +
				L"</top101large>\n");
		}

		data->push_back(L"</top101largest>\n");
	}


	void ReportTopSmallest(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<top101smallest>\n");

		for (FileObject *file : GScanEngine->Data[DataSource].Top100Small)
		{
			data->push_back(L"  <top5101small sizebytes=\"" + std::to_wstring(file->Size) + L"\">" +
				Formatting::ReplaceEntitiesForXML(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name) +
				L"</top101small>\n");
		}

		data->push_back(L"</top101smallest>\n");
	}


	void ReportTopNewest(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<top101newest>\n");

		for (FileObject *file : GScanEngine->Data[DataSource].Top100Newest)
		{
			data->push_back(L"  <top101new date=\"" + Convert::IntDateToString(file->DateCreated) + L"\" " +
				L"sizebytes=\"" + std::to_wstring(file->Size) + L"\" " +
				L"size=\"" + Convert::ConvertToUsefulUnit(file->Size) + L"\" " +
				L"owner=\"" + GScanEngine->Data[DataSource].Users[file->Owner]->Name + L"\">" +
				Formatting::ReplaceEntitiesForXML(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name) +
				L"</top101new>\n");
		}

		data->push_back(L"</top101newest>\n");
	}


	void ReportTopOldest(std::vector<std::wstring> *data, int DataSource)
	{
		data->push_back(L"<top101oldest>\n");

		for (FileObject *file : GScanEngine->Data[DataSource].Top100Oldest)
		{
			data->push_back(L"  <top101old date=\"" + Convert::IntDateToString(file->DateCreated) + L"\" " +
				L"sizebytes=\"" + std::to_wstring(file->Size) + L"\" " +
				L"size=\"" + Convert::ConvertToUsefulUnit(file->Size) + L"\" " +
				L"owner=\"" + GScanEngine->Data[DataSource].Users[file->Owner]->Name + L"\">" +
				Formatting::ReplaceEntitiesForXML(GScanEngine->Data[DataSource].Folders[file->FilePathIndex] + file->Name) +
				L"</top101old>\n");
		}

		data->push_back(L"</top101oldest>\n");
	}


	void FullList(XMLReportOptions options, std::vector<std::wstring> *data, int DataSource)
	{
		//GLog->Add( GLanguageHandler->Text[kSavingReports] + L" (XML Full List):\n";

		data->push_back(L"<?xml version=\"1.0\"?>\n");
		data->push_back(L"<!--  -->\n");
		data->push_back(L"<!-- generated with Xinorbis " + __XVersion + L" - " + __XDate + L" -->\n");
		data->push_back(L"<!-- https://github.com/MaximumOctopus/Xinorbis - Paul A Freshney -->\n");
		data->push_back(L"<!--  -->\n");
		data->push_back(L"<xinorbisfilelist>\n");

		for (FileObject *file : GScanEngine->Data[DataSource].Files)
		{
			data->push_back(file->ToXml(GScanEngine->Data[DataSource].Folders[file->FilePathIndex],
				GScanEngine->Data[DataSource].Users[file->Owner]->Name));
		}

		data->push_back(L"</xinorbisfilelist>\n");
	}
};
