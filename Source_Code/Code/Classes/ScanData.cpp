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

#include <algorithm>
#include <fstream>

#include "Formatting.h"
#include "LanguageHandler.h"
#include "ScanData.h"
#include "SettingsHandler.h"
#include "Utility.h"

extern LanguageHandler *GLanguageHandler;
extern SettingsHandler *GSettingsHandler;

bool static sortBySize(const FileObject *lhs, const FileObject *rhs) { return lhs->Size < rhs->Size; }
bool static sortByDate(const FileObject *lhs, const FileObject *rhs) { return lhs->DateCreated < rhs->DateCreated; }
bool static sortByAttributes(const FileObject *lhs, const FileObject *rhs) { return lhs->Attributes < rhs->Attributes; }
bool static sortByFileName(const FileObject *lhs, const FileObject *rhs) { return lhs->Name < rhs->Name; }
bool static sortByFullPath(const FileObject *lhs, const FileObject *rhs) { return lhs->FullPath < rhs->FullPath; }

bool static sortByCreatedDate(const FileObject *lhs, const FileObject *rhs) { return lhs->DateCreated < rhs->DateCreated; }
bool static sortByAccessedDate(const FileObject *lhs, const FileObject *rhs) { return lhs->DateAccessed < rhs->DateAccessed; }
bool static sortByModifiedDate(const FileObject *lhs, const FileObject *rhs) { return lhs->DateModified < rhs->DateModified; }

bool static sortRootBySize(const RootFolder* lhs, const RootFolder* rhs) { return lhs->Size > rhs->Size; }
bool static sortRootByCount(const RootFolder* lhs, const RootFolder* rhs) { return lhs->Count > rhs->Count; }
bool static sortRootByName(const RootFolder* lhs, const RootFolder* rhs) { return lhs->Name > rhs->Name; }


ScanData::ScanData()
{
	for (int t = 0; t < 280; t++)
	{
		if (t != 279)
		{
			Lengths[t].Name = std::to_wstring(t + 1);
		}
		else
		{
			Lengths[t].Name = L">=280";
		}

		Lengths[t].Ordinal = t + 1;
	}
}

void ScanData::Clear()
{
	FileCount   = 0;
	FolderCount = 0;
	TotalSize   = 0;
	TotalSizeOD = 0;

    DiskStats.Clear();

	for (int t = 0; t < kMagnitudesCount; t++)
	{
		Magnitude[t].Count = 0;
		Magnitude[t].Size = 0;
	}

	for (int t = 0; t < kAttributesCount; t++)
	{
		FileAttributes[t].Count = 0;
		FileAttributes[t].Size = 0;
	}

	for (int t = 0; t < kFileCategoriesCount; t++)
	{
		ExtensionSpread[t].Count = 0;
		ExtensionSpread[t].Size = 0;
	}

	HasLengthData = false;

	for (int t = 0; t < 280; t++)
	{
		Lengths[t].Clear();
	}

	Files.clear();
	Folders.clear();

	TemporaryFiles.clear();

	NullFiles.clear();
	NullFolders.clear();

	Top100Large.clear();
	Top100Small.clear();
	Top100Newest.clear();
	Top100Oldest.clear();

	FileDates.clear();

	Users.clear();

	RootFiles.clear();
	RootFolders.clear();

	RootFolder *rfd = new RootFolder();

	rfd->Name        = L"\\ (root)";
	rfd->Attributes  = 0;
	rfd->Size        = 0;
	rfd->Count       = 0;
	rfd->FilesInRoot = true;

	RootFolders.push_back(rfd);
}


void ScanData::AddUserNotSpecified()
{
	UserData *ud = new UserData(GLanguageHandler->Text[kNOT_SPECIFIED]);

	ud->Count = FileCount;
	ud->Size  = TotalSize;

	Users.push_back(ud);
}


// folder_name must terminate with "\"
SizeOfFolder ScanData::GetSizeOfFolder(const std::wstring folder_name)
{
	SizeOfFolder sof;

	for (FileObject *file : Files)
	{
		if (file->Category != kFileCategoryDirectory)
		{
			std::wstring full_path = Folders[file->FilePathIndex];

			if (full_path.compare(0, folder_name.size(), folder_name))
			{
				sof.Size += file->Size;
				sof.SizeOnDisk += file->SizeOnDisk;

				sof.FileCount++;
			}
		}
	}

	return sof;
}


// folder_name must terminate with "\"
int ScanData::GetFullFolderIndex(const std::wstring folder_name)
{
	for (int t = 0; t < Folders.size(); t++)
	{
		if (Folders[t] == folder_name)
		{
			return t;
		}
	}

	return -1;
}


// assume the shortest folder path is likely to be the root folder
std::wstring ScanData::GetScanPathFromFolderList()
{
	std::wstring path(L"");

	if (Folders.size() != 0)
	{
		path = Folders[0];

		for (int t = 0; t < Folders.size(); t++)
		{
			if (Folders[t].length() < path.length())
			{
				path = Folders[t];

				RootFolderIndex = t;
			}
		}

		return path;
	}

	return L"Unknown :(";
}


void ScanData::PopulateSortedFiles()
{
	for (int t = 0; t < Files.size(); t++)
	{
		std::wstring n = Folders[Files[t]->FilePathIndex] + Files[t]->Name;

		FileObjectSorted fso(t, n.substr(Path.String.length()));

		SortedFiles.insert(fso);
	}
}


// =============================================================================
// =============================================================================


// searches for a single term within file name
void ScanData::Search(Command command)
{
	int count = 0;

	std::wstring term = command.secondary;
	std::wstring filename = L"";

	std::transform(term.begin(), term.end(), term.begin(), ::tolower);

	for (FileObject *file : Files)
	{
		if (file->Name.find(term) != std::wstring::npos)
		{
			// //GLog->Add( std::format(L"{0}  {1}{2}\n", Formatting::AddLeadingSpace(Convert::ConvertToUsefulUnit(file.Size), 8), Folders[file.FilePathIndex], file.Name);

			count++;
		}
	}

	if (count != 0)
	{
		//GLog->Add( << std::format(L"\nFound {0} matching files\n", count);
	}
}



// =============================================================================
// =============================================================================


void ScanData::BuildFileDates()
{
	#ifdef DEBUG
	Debug::Output(L"ScanEngine::BuildFileDates()");
	#endif

	int currentYear = DateUtility::CurrentYearI();

	for (int y = 1980; y <= currentYear; y++)
	{
		FileDateObject *fdo = new FileDateObject(y);

		FileDates.push_back(fdo);
	}

	if (Files.size() != 0)
	{
		for (FileObject *file : Files)
		{
			if (!(file->Attributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				int year = Convert::StrToIntDef(std::to_wstring(file->DateCreated).substr(0, 4), -1);

				if ((year >= 1980) && (year <= currentYear))
				{
					FileDates[year - 1980]->Count++;
					FileDates[year - 1980]->Size += file->Size;
				}
			}
		}
	}
}


void ScanData::BuildTop100SizeLists()
{
	#ifdef DEBUG
	Debug::Output(L"ScanEngine::BuildTop100SizeLists()");
	#endif

	Top100Large.clear();
	Top100Small.clear();

	std::sort(Files.begin(), Files.end(), sortBySize);

	if (Files.size() != 0)
	{
		int i = 0;

		while ((i < 100) && (i < Files.size()))
		{
			Top100Small.push_back(Files[i]);
			Top100Large.push_back(Files[Files.size() - i - 1]);

			i++;
		}
	}
}


void ScanData::BuildTop100DateLists()
{
	#ifdef DEBUG
	Debug::Output(L"ScanEngine::BuildTop100DateLists()");
	#endif

	Top100Newest.clear();
	Top100Oldest.clear();

	std::sort(Files.begin(), Files.end(), sortByDate);

	if (Files.size() != 0)
	{
		int i = 0;

		while ((i < 100) && (i < Files.size()))
		{
			Top100Oldest.push_back(Files[i]);
			Top100Newest.push_back(Files[Files.size() - i - 1]);

			i++;
		}
	}
}


int ScanData::RootIndex()
{
	for (int r = 0; r < RootFolders.size(); r++)
	{
		if (RootFolders[r]->FilesInRoot)
		{
			return r;
		}
	}

	return 0;
}


void ScanData::ListRoot()
{
	std::wstring tmp = Path.String + L"*";

	WIN32_FIND_DATAW file;

	HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);

	if (search_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			// =======================================================================================================
			// Folder
			// =======================================================================================================
			if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
					continue;

				//GLog->Add( L"    " << Path.String << file.cFileName << L"\\ \n";
			}
			else
			// =======================================================================================================
			// Files
			// =======================================================================================================
			{
				//GLog->Add( L"    " << Path.String << file.cFileName << L"\n";
			}

		} while (FindNextFileW(search_handle, &file));

		FindClose(search_handle);
	}
}


SizeOfFolder ScanData::GetSizeOfFolder(const std::wstring full_folder_name, const std::wstring folder)
{
	SizeOfFolder sof;

	sof.Folder = folder;

	for (FileObject *file : Files)
	{
		if (file->Category != kFileCategoryDirectory)
		{
			if (Folders[file->FilePathIndex].rfind(full_folder_name + L'\\', 0) == 0)
			{
				sof.Size += file->Size;
				sof.SizeOnDisk += file->SizeOnDisk;

				sof.FileCount++;
			}
		}
	}

	return sof;
}


std::wstring ScanData::GetDrive()
{
	return Path.String.substr(0, 2);
}


int ScanData::GetFolderIndex(const std::wstring folder_name)
{
	for (int t = 0; t < Folders.size(); t++)
	{
		if (Folders[t].rfind(folder_name, 0) == 0)
		{
			return t;
		}
	}

	return -1;
}


// =============================================================================
// Sorting
// =============================================================================


void ScanData::SortByProperty(SortMode sort)
{
	switch (sort)
	{
	case SortMode::kSize:
		std::sort(Files.begin(), Files.end(), sortByCreatedDate);
		break;
	case SortMode::kAttributes:
		std::sort(Files.begin(), Files.end(), sortByAttributes);
		break;
	case SortMode::kFileName:
		std::sort(Files.begin(), Files.end(), sortByFileName);
		break;
	case SortMode::kFullPath:
		std::sort(Files.begin(), Files.end(), sortByFullPath);
		break;
	case SortMode::kDateCreated:
		std::sort(Files.begin(), Files.end(), sortByCreatedDate);
		break;
	case SortMode::kDateAccessed:
		std::sort(Files.begin(), Files.end(), sortByAccessedDate);
		break;
	case SortMode::kDateModified:
		std::sort(Files.begin(), Files.end(), sortByModifiedDate);
		break;
	case SortMode::kUser:
		break;

	case SortMode::kRootFoldersSize:
		std::sort(RootFolders.begin(), RootFolders.end(), sortRootBySize);
		break;
	case SortMode::kRootFoldersCount:
		std::sort(RootFolders.begin(), RootFolders.end(), sortRootByCount);
		break;
	case SortMode::kRootFoldersName:
		std::sort(RootFolders.begin(), RootFolders.end(), sortRootByName);
		break;
	}

    LastSort = sort;
}


// =============================================================================
// Export data
// =============================================================================


void ScanData::SaveRawData(Command command)
{
	if (Files.size() != 0)
	{
		std::wstring FileName(command.secondary);

		if (FileName.empty())
		{
			FileName = Utility::ProcessFileName(L"search_$yyyy$mm$dd_$Th$Tm$Ts.csv");
		}

		std::ofstream ofile(FileName);

		if (ofile)
		{
			std::wstring s = GLanguageHandler->Text[kFileName] + L',' +
					GLanguageHandler->Text[kFilePath] + L',' +
					GLanguageHandler->Text[kSize] + L',' +
					GLanguageHandler->Text[kSizeOfFilesBytes] + L',' +
					GLanguageHandler->Text[kCreatedDate] + L',' +
					GLanguageHandler->Text[kAccessedDate] + L',' +
					GLanguageHandler->Text[kModifiedDate] + L',' +
					GLanguageHandler->Text[kCreatedDate] + L" (" + GLanguageHandler->Text[kTime] + L")" + L',' +
					GLanguageHandler->Text[kAccessedDate] + L" (" + GLanguageHandler->Text[kTime] + L")" + L',' +
					GLanguageHandler->Text[kModifiedDate] + L" (" + GLanguageHandler->Text[kTime] + L")" + L',' +
					GLanguageHandler->Text[kCategory] + L',' +
					GLanguageHandler->Text[kCategory] + L"ID" + L',' +
					GLanguageHandler->Text[kOwner] + L',' +
					GLanguageHandler->LanguageTypes[kFileType_ReadOnly] + L',' +
					GLanguageHandler->LanguageTypes[kFileType_Hidden] + L',' +
					GLanguageHandler->LanguageTypes[kFileType_System] + L',' +
					GLanguageHandler->LanguageTypes[kFileType_Archive] + L',' +
					GLanguageHandler->Text[kTemporary] + L',' +
					GLanguageHandler->Text[kFileAttributes];

			ofile << Formatting::to_utf8(s + L"\n");

			std::wstring ucFolder = GLanguageHandler->Text[kFolder];

			std::transform(ucFolder.begin(), ucFolder.end(), ucFolder.begin(), ::toupper);

			for (FileObject *file : Files)
			{
				std::wstring output;

				if (file->Attributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					output = L"\"" + file->Name + L"\"" + L',' +
						L"\"" + Folders[file->FilePathIndex] + file->Name + L"\"" + L',' +

						ucFolder + L',' +
						L"-1" + L',' +

						Convert::IntDateToString(file->DateCreated) + L',' +
						Convert::IntDateToString(file->DateAccessed) + L',' +
						Convert::IntDateToString(file->DateModified) + L',' +

						std::to_wstring(file->TimeCreated) + L',' +
						std::to_wstring(file->TimeAccessed) + L',' +
						std::to_wstring(file->TimeModified) + L',' +

						ucFolder + L',' +

						L"99" + L',' +

						Users[file->Owner]->Name + L',' +

						Convert::AttributeToIntAsString(file->Attributes, FILE_ATTRIBUTE_READONLY) + L',' +
						Convert::AttributeToIntAsString(file->Attributes, FILE_ATTRIBUTE_HIDDEN) + L',' +
						Convert::AttributeToIntAsString(file->Attributes, FILE_ATTRIBUTE_SYSTEM) + L',' +
						Convert::AttributeToIntAsString(file->Attributes, FILE_ATTRIBUTE_ARCHIVE) + L',' +
						Convert::BoolToString(file->Temp) + L',' +
						std::to_wstring(file->Attributes);
				}
				else
				{
					output = L"\"" + file->Name + L"\"" + L',' +
						L"\"" + Folders[file->FilePathIndex] + file->Name + L"\"" + L',' +

						L"\"" + Convert::GetSizeString(0, file->Size) + L"\"" + L',' +
						L"\"" + std::to_wstring(file->Size) + L"\"" + L',' +

						Convert::IntDateToString(file->DateCreated) + L',' +
						Convert::IntDateToString(file->DateAccessed) + L',' +
						Convert::IntDateToString(file->DateModified) + L',' +

						std::to_wstring(file->TimeCreated) + L',' +
						std::to_wstring(file->TimeAccessed) + L',' +
						std::to_wstring(file->TimeModified) + L',' +

						GLanguageHandler->TypeDescriptions[file->Category] + L',' +

						std::to_wstring(file->Category) + L',' +

						Users[file->Owner]->Name + L',' +

						Convert::AttributeToIntAsString(file->Attributes, FILE_ATTRIBUTE_READONLY) + L',' +
						Convert::AttributeToIntAsString(file->Attributes, FILE_ATTRIBUTE_HIDDEN) + L',' +
						Convert::AttributeToIntAsString(file->Attributes, FILE_ATTRIBUTE_SYSTEM) + L',' +
						Convert::AttributeToIntAsString(file->Attributes, FILE_ATTRIBUTE_ARCHIVE) + L',' +
						Convert::BoolToString(file->Temp) + L',' +
						std::to_wstring(file->Attributes);
				}

				ofile << Formatting::to_utf8(output + L"\n");
			}

			ofile.close();

			//GLog->Add( L"    Saved ok.\n";
		}
		else
		{
			//GLog->Add( L"    Error: unable to save file.\n";
		}
	}
	else
	{
		//GLog->Add( L" No search results to save :(\n";
	}
}


// =============================================================================
// Import
// =============================================================================


FileObject* ScanData::ImportRow(const std::wstring input)
{
	FileObject *f = new FileObject();
	int index = 0;
	std::wstring row(input + L",");
	std::wstring field(L"");
	bool inquotes = false;

	for (int t = 0; t < row.length(); t++)
	{
		if (row[t] == L'\"')
		{
			inquotes = !inquotes;
		}
		else if (row[t] == L',' && !inquotes)
		{
			switch (index)
			{
			case 0:
				f->Name = field;
				break;
			case 1:
				//
				break;
			case 2:
			{
				int folderindex = -1;

				for (int d = 0; d < Folders.size(); d++)
				{
					if (field == Folders[d])
					{
						folderindex = d;
					}
				}

				if (folderindex == -1)
				{
					Folders.push_back(field);

					f->FilePathIndex = Folders.size() - 1;
				}
				else
				{
					f->FilePathIndex = folderindex;
				}

				break;
			}
			case 3:
				// size as text, captured below
				break;
			case 4:
				f->Size = stoll(field);
				break;
			case 5:
				f->SizeOnDisk = stoi(field);
				break;
			case 6:
				// date as text, captured from 8
				break;
			case 7:
				// date as text, captured from 9
				break;
			case 8:
				// date as text, captured from 10
				break;
			case 9:
				f->DateCreated = stoi(field);
				break;
			case 10:
				f->DateAccessed = stoi(field);
				break;
			case 11:
				f->DateModified = stoi(field);
				break;
			case 12:
				f->TimeCreated = stoi(field);
				break;
			case 13:
				f->TimeAccessed = stoi(field);
				break;
			case 14:
				f->TimeModified = stoi(field);
				break;
			case 15:
				// category as text, captured below
				break;
			case 16:
				f->Category = stoi(field);

				if (f->Category == 99)
				{
					FolderCount++;

					f->Category = kFileCategoryDirectory;
				}
				break;
			case 17:
				if (GSettingsHandler->Optimisations.GetUserDetails)
				{
					std::wstring owner = field;

					if (owner.empty())
					{
						owner = GLanguageHandler->Text[kNOT_SPECIFIED];
					}

					int z = FindUser(owner);

					if (z == -1)
					{
						UserData *newUser = new UserData(owner);

						Users.push_back(newUser);

						z = Users.size() - 1;
					}

					f->Owner = z;
				}
				else
				{
					f->Owner = 0;
				}
				break;
			case 18:
				// readonly, captured from attributes
				break;
			case 19:
				// hidden, captured from attributes
				break;
			case 20:
				// system, captured from attributes
				break;
			case 21:
				// archive, captured from attributes
				break;
			case 22:
				// temporary, captured from attributes
				break;
			case 23:
				f->Attributes = stoi(field);

				if (f->Attributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					f->Category = kFileCategoryDirectory;
				}

				break;
			}

			index++;

			field.clear();
		}
		else
		{
			field += row[t];
		}
	}

	return f;
}


int ScanData::FindUser(std::wstring name)
{
	for (int t = 0; t < Users.size(); t++)
	{
		if (Users[t]->Name == name)
		{
			return t;
		}
	}

	return -1;
}


bool ScanData::ImportFromCSV(const std::wstring file_name)
{
	std::wifstream file(file_name);

	if (file)
	{
		int RowCount = 0;
		std::wstring s;

		while (std::getline(file, s))
		{
			if (!s.empty())
			{
				if (s[0] == L'\"')
				{
					FileObject *f = ImportRow(s);

					if (!f->Name.empty())
					{
						Files.push_back(f);
					}
				}
			}

			RowCount++;
		}

		//GLog->Add( L"Imported " << Files.size() << L" items from " << RowCount << L" rows.\n";

		if (!GSettingsHandler->Optimisations.GetUserDetails)
		{
			AddUserNotSpecified();
		}

		Path.String = GetScanPathFromFolderList();

		file.close();

		return true;
	}

	return false;
}


bool ScanData::ImportFromCSVCustom(const std::wstring file_name, CSVDataFormat csvdf)
{                /*
	GScanDetails[aDataIndex].TimeStarted := Now;

	if (LoadFromCustomCSV(file_name, csvdf))
	{

		TPopulate.FromXinFilesFromCSV(aDataIndex, ret, fn);

		GXinorbisScan.AnalyseDataFromCSVImport(aDataIndex);
	}
			   */
	return true;
}


bool ScanData::LoadFromCustomCSV(const std::wstring file_name, CSVDataFormat csvdf)
{                 /*
var
  tf : TextFile;
  s,r,fdir,fname : string;
  z,t,i,a : integer;
  xfo : TFileObject;
  tud : TUserData;
  recordcount : integer;
  processthisfield, inquotes : boolean;
  tempString : string;

  function IsValidNumber(const s : string): boolean;
   var
    t : integer;

  begin
   Result := True;

   for t := 1 to length(s) do
     if (ord(s[t]) < 48) or (ord(s[t]) > 57) then
       Result := False;
  end;

 begin
  Result := True;

  if FileExists(aFileName) then begin

    GScanDetails[aDataIndex].ClearAll; // to do, maybe need to set MD5 and others

    GScanDetails[aDataIndex].InitNow;

    GScanDetails[aDataIndex].ScanType   := ScanTypeNormal;
    GScanDetails[aDataIndex].ScanSource := ScanSourceFileCSV;
    GScanDetails[aDataIndex].Filename   := aFileName;

    GScanDetails[aDataIndex].ScanPath   := 'unknown :(';

    recordcount := 0;

    AssignFile(tf, aFileName);
    Reset(tf);

    XSettings.Forms.ProgressForm.SetProcessIcon(1);

    while not(eof(tf)) do begin
      Readln(tf, s);

      s := s + ' ';

      if Pos(',', s) <> 0 then begin
        xfo := TFileObject.Create;
        xfo.FileName       := '';
        xfo.FilePathIndex  := 0;
        xfo.FileSize       := 0;
        xfo.FileSizeOnDisk := 0;
        xfo.FileDateC      := TConvert.DateToYYYYMMDDI(Now);
        xfo.FileDateA      := TConvert.DateToYYYYMMDDI(Now);
        xfo.FileDateM      := TConvert.DateToYYYYMMDDI(Now);
        xfo.FileTimeC      := 0;
        xfo.FileTimeA      := 0;
        xfo.FileTimeM      := 0;
        xfo.FileCategory   := 7;
        xfo.Attributes     := 0;
        xfo.Temp           := False;
        xfo.Owner          := 0;

        r := '';
        i := 0;
        processthisfield := False;
        inquotes         := False;

        for t := 1 to length(s) do begin

          case s[t] of
            '"' : begin
                    if inquotes then begin
                      case s[t + 1] of
                        ',' : inquotes := False;
                      else
                        r := r + s[t];
                      end;
                    end
                    else
                      inquotes := not(inquotes);
                  end;
            ',' : begin
                    if not(inquotes) then
                      processthisfield := True;
                  end;
          else
            r := r + s[t];
          end;

          if processthisfield then begin
            if i <= MaxCSVFields then begin
              if not((recordcount = 0) and (aCSVDataFormat.IgnoreFirstRecord)) then begin
                r := Trim(r);

                case aCSVDataFormat.Fields[i] of
                   CFieldIgnore            : {}; // ignore
                   CFieldFullFilePath      : begin
											   xfo.FileName := Utility::SplitFileName(r);

                                               tempString   := ExtractFilePath(r);

                                               a := GScanDetails[aDataIndex].Folders.IndexOf(tempstring);

                                               if a <> -1 then
                                                 xfo.FilePathIndex := a
                                               else begin
                                                 GScanDetails[aDataIndex].Folders.Add(tempString);
                                                 xfo.FilePathIndex := GScanDetails[aDataIndex].Folders.Count - 1;
                                               end;
                                             end;
                   CFieldFileSizeBytes     : if IsValidNumber(r) then begin
                                               xfo.FileSize := StrToInt64(r);

                                               inc(GScanDetails[aDataIndex].TotalSize, xfo.FileSize);

                                               SetMagnitude(0, aDataIndex, xfo.FileSize);
                                             end
                                             else
                                               xfo.attributes:=xfo.Attributes+faDirectory;
                   CFieldFileSizeOnDIsk    : if IsValidNumber(r) then
                                               xfo.FileSizeOnDisk:=StrToInt64(r);
                   CFieldCreatedDDMMYYYY   : if length(r) = 10 then
                                               xfo.FileDateC := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
                   CFieldCreatedMMDDYYYY   : xfo.FileDateC := TConvert.UStoUKDate(r);
                   CFieldModifiedDDMMYYYY  : if length(r) = 10 then
                                               xfo.FileDateM := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
                   CFieldModifiedMMDDYYYY  : xfo.FileDateM := TConvert.UStoUKDate(r);
                   CFieldAccessedDDMMYYYY  : if length(r) = 10 then
                                               xfo.FileDateA := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
                   CFieldAccessedMMDDYYYY  : xfo.FileDateA := TConvert.UStoUKDate(r);
                  CFieldFilePath           : if r[length(r)] <> '\' then
                                               fdir := r + '\'
                                             else
                                               fdir := r;
                  CFieldFileName           : fname:=r;
                  CFieldOwner              : begin
                                               if XSettings.Optimisations.GetUserDetails then begin
                                                 z := TUtility.FindUserIndex(1, r);
                                                 if z = -1 then begin
                                                   tud      := TUserData.Create;
                                                   tud.Name := r;

                                                   GScanDetails[aDataIndex].Users.Add(tud);

                                                   z := GScanDetails[aDataIndex].Users.Count - 1;
                                                 end;

                                                 xfo.Owner:=z;

                                                 inc(GScanDetails[aDataIndex].Users[z].Data[XUserCount]);
                                                 inc(GScanDetails[aDataIndex].Users[z].Data[XUserSize], xfo.FileSize);
                                               end;
                                             end;
                  CFieldCategory           : if IsValidNumber(r) then begin
                                               xfo.FileCategory := StrToInt(r);

                                               SetMagnitude(xfo.FileCategory, aDataIndex, xfo.FileSize);
                                             end;
                  CFieldReadOnly           : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Attributes := xfo.Attributes + Sysutils.faReadOnly;
                  CFieldHidden             : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Attributes := xfo.Attributes + Sysutils.faHidden;
                  CFieldSystem             : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Attributes := xfo.Attributes + Sysutils.faSysFile;
                  CFieldArchive            : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Attributes := xfo.Attributes + Sysutils.faArchive;
                  CFieldTemp               : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Temp := True;
                  CFieldAttributes         : if IsValidNumber(r) then
                                               xfo.Attributes := StrToInt(r);
                  CFieldCreatedTimeHHMMSS  : if IsValidNumber(r) then
                                               xfo.FileTimeC := StrToInt(r);
                  CFieldModifiedTimeHHMMSS : if IsValidNumber(r) then
                                               xfo.FileTimeA := StrToInt(r);
                  CFieldAccessedTimeHHMMSS : if IsValidNumber(r) then
                                               xfo.FileTimeM := StrToInt(r);
                end;
              end;

              r := '';

              processthisfield := False;
              inquotes         := False;
            end;

            inc(i);
          end;
        end;

        if i <= MaxCSVFields then begin
          if not((recordcount = 0) and (aCSVDataFormat.IgnoreFirstRecord)) then begin
            r := Trim(r);

            case aCSVDataFormat.Fields[i] of
              CFieldIgnore             : {}; // ignore
              CFieldFullFilePath       : begin
                                           xfo.FileName := Utility::SplitFileName(r);

                                           tempString   := ExtractFilePath(r);

                                           a := GScanDetails[aDataIndex].Folders.IndexOf(tempstring);

                                           if a <> -1 then
                                             xfo.FilePathIndex := a
                                           else begin
                                             GScanDetails[aDataIndex].Folders.Add(tempString);
                                             xfo.FilePathIndex := GScanDetails[aDataIndex].Folders.Count - 1;
                                           end;
                                         end;
              CFieldFileSizeBytes      : if IsValidNumber(r) then begin
                                           xfo.FileSize := StrToInt64(r);

                                           if xfo.FileSize > 0 then
                                             inc(GScanDetails[aDataIndex].TotalSize, xfo.FileSize);

                                           //-- now lets put the size into the magnitude section --------------------
                                           SetMagnitude(0, aDataIndex, xfo.FileSize);
                                         end
                                         else
                                           xfo.attributes := xfo.Attributes+faDirectory;
              CFieldFileSizeOnDisk     : if IsValidNumber(r) then
                                           xfo.FileSizeOnDisk := StrToInt64(r);
              CFieldCreatedDDMMYYYY    : if (length(r) = 10) then
                                           xfo.FileDateC := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
              CFieldCreatedMMDDYYYY    : xfo.FileDateC := TConvert.UStoUKDate(r);
              CFieldModifiedDDMMYYYY   : if (length(r) = 10) then
                                           xfo.FileDateM := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
              CFieldModifiedMMDDYYYY   : xfo.FileDateM := TConvert.UStoUKDate(r);
              CFieldAccessedDDMMYYYY   : if (length(r) = 10) then
                                           xfo.FileDateA := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
              CFieldAccessedMMDDYYYY   : xfo.FileDateA := TConvert.UStoUKDate(r);
              CFieldFilePath           : if r[length(r)] <> '\' then
                                          fdir := r + '\'
                                        else
                                          fdir:=r;
              CFieldFileName           : fname:=r;
              CFieldOwner              : begin
                                           if XSettings.Optimisations.GetUserDetails then begin
                                             z := TUtility.FindUserIndex(aDataIndex, r);

                                             if z = -1 then begin
                                               tud      := TUserData.Create;
                                               tud.Name := r;

                                               GScanDetails[aDataIndex].Users.Add(tud);

                                               z := GScanDetails[aDataIndex].Users.Count - 1;
                                             end;

                                             xfo.Owner := z;

                                             inc(GScanDetails[aDataIndex].Users[z].Data[XUserCount]);
                                             inc(GScanDetails[aDataIndex].Users[z].Data[XUserSize], xfo.FileSize);
                                           end;
                                         end;
              CFieldCategory           : if IsValidNumber(r) then begin
                                           xfo.FileCategory := StrToInt(r);

                                           SetMagnitude(xfo.FileCategory, aDataIndex, xfo.FileSize);
                                         end;
              CFieldReadOnly           : if IsValidNumber(r) then
                                          if StrToInt(r) <> 0 then
                                            xfo.Attributes := xfo.Attributes + Sysutils.faReadOnly;
              CFieldHidden             : if IsValidNumber(r) then
                                          if StrToInt(r) <> 0 then
                                            xfo.Attributes := xfo.Attributes + faHidden;
              CFieldSystem             : if IsValidNumber(r) then
                                          if StrToInt(r) <> 0 then
                                            xfo.Attributes := xfo.Attributes + faSysFile;
              CFieldArchive            : if IsValidNumber(r) then
                                           if StrToInt(r) <> 0 then
                                             xfo.Attributes := xfo.Attributes + faArchive;
              CFieldTemp               : if IsValidNumber(r) then
                                          if StrToInt(r) <> 0 then
                                            xfo.Temp := True;
              CFieldAttributes         : if IsValidNumber(r) then
                                           xfo.Attributes := StrToInt(r);
              CFieldCreatedTimeHHMMSS  : if IsValidNumber(r) then
                                           xfo.FileTimeC := StrToInt(r);
              CFieldModifiedTimeHHMMSS : if IsValidNumber(r) then
                                           xfo.FileTimeA := StrToInt(r);
              CFieldAccessedTimeHHMMSS : if IsValidNumber(r) then
                                           xfo.FileTimeM := StrToInt(r);
            end;
          end;
        end;

        if xfo.FileName = '' then
          xfo.FileName := fname;

//        if xfo.FilePath='' then
//          xfo.FilePath:=fdir;

        if not((recordcount = 0) and (aCSVDataFormat.IgnoreFirstRecord)) then
          GScanDetails[aDataIndex].Files.Add(xfo);

        inc(recordcount);
      end;
    end;

    CloseFile(tf);

    GScanDetails[aDataIndex].ScanPath := GetScanPathFromFolderList(aDataIndex);

    if GScanDetails[aDataIndex].Users.Count = 0 then begin
      tud      := TUserData.Create;
      tud.Name := XText[rsNOT_SPECIFIED];

      GScanDetails[aDataIndex].Users.Add(tud);

      GScanDetails[aDataIndex].Users[0].Data[XUserCount] := GScanDetails[aDataIndex].FileCount;
      GScanDetails[aDataIndex].Users[0].Data[XUserSize]  := GScanDetails[aDataIndex].TotalSize;
    end;
  end
  else
	Result := False; */
}




// =============================================================================
// Export settings
// =============================================================================


std::wstring ScanData::ToJSON()
{
	switch (Source)
	{
	case ScanSource::None:
		return L"\"scan\":[{\"error\":\"invalid scan source\"}],\n";
	case ScanSource::LiveScan:
		return L"\"scan\":[{\"path\":\"" + Formatting::ReplaceForJSON(Path.String) + L"\", \"filecount\":\"" + std::to_wstring(FileCount) + L"\", \"foldercount\":\"" + std::to_wstring(FolderCount) + L"\", \"sizebytes\":\"" + std::to_wstring(TotalSize) + L"\", \"date\":\"" + DateUtility::GetDate(DateTimeFormat::Display) + L"\", \"time\":\"" + DateUtility::GetTime(DateTimeFormat::Display) + L"\"}],\n";
	case ScanSource::FileCSV:
		return L"\"scan\":[{\"path\":\"" + Formatting::ReplaceForJSON(Path.String) + L"\", \"csvsource\":\"" + Formatting::ReplaceForJSON(Path.FileName) + L"\", \"filecount\":\"" + std::to_wstring(FileCount) + L"\", \"foldercount\":\"" + std::to_wstring(FolderCount) + L"\", \"sizebytes\":\"" + std::to_wstring(TotalSize) + L"\", \"date\":\"" + DateUtility::GetDate(DateTimeFormat::Display) + L"\", \"time\":\"" + DateUtility::GetTime(DateTimeFormat::Display) + L"\"}],\n";
	}

	return L"";
}
