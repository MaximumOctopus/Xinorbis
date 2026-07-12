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

#include "ConstantsSearch.h"
#include "ProcessSearch.h"
#include "ScanEngine.h"
#include "SearchUtility.h"

extern ScanEngine* GScanEngine;


ProcessSearch::ProcessSearch()
{

}


int ProcessSearch::Filter(Command command)
{
	std::wstring UserSearchTerms(command.secondary);

	FileObject file_object;

	bool CategorySearchFound = false;
	bool UserSearchFound = false;
	bool ExcludeFolderSearchFound = false;
	bool IncludeFolderSearchFound = false;
	int CategorySearchCount = 0;
	int UserSearchCount = 0;
	int ExcludeFolderSearchCount = 0;
	int IncludeFolderSearchCount = 0;

	bool Found = false;
	int FoundCount = 0;

	SearchCriteriaObject sco;

	std::vector<SearchCriteriaObject> SearchCriteria;
	std::vector<std::wstring> SearchTerms;
	std::vector<std::wstring> QuickTerms;
	std::vector<std::wstring> FoundTerms;

	auto AddThisKeyword = [&SearchCriteria](const std::wstring s)
	{
		SearchCriteriaObject sco = SearchUtility::ProcessSearchTerm(s);

		if (sco.Type != SearchType::None)
		{
			SearchCriteria.push_back(sco);

			return false;
		}

		return true;
	};

	auto ProcessQuickTerms = [&QuickTerms](std::wstring s)
	{
		std::wstring output = L"";
		bool inside = false;

		QuickTerms.clear();

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == L'"')
			{
				// do nothing
			}
			else if (s[i] == L'(')
			{
				inside = true;
			}
			else if (s[i] == L')')
			{
				inside = false;
			}
			else if (s[i] == L' ' && !inside)
			{
				QuickTerms.push_back(output);

				output.clear();
			}
			else
			{
				output += s[i];
			}
		}

		if (!output.empty())
		{
			QuickTerms.push_back(output);
		}
	};

	// getsearchterms
	std::wstring s = L"";
	bool reading = false;
	bool inside = false;

	for (int i = 0; i < UserSearchTerms.length(); i++)
	{
		if (UserSearchTerms[i] == L'"')
		{
			reading = !reading;

			std::transform(s.begin(), s.end(), s.begin(), ::toupper);

			if (AddThisKeyword(s))
			{
				SearchTerms.push_back(L'"' + s + L'"');
			}

			s.clear();
		}
		else if (UserSearchTerms[i] == L'(')
		{
			inside = true;
		}
		else if (UserSearchTerms[i] == L')')
		{
			inside = false;
		}
		else if (UserSearchTerms[i] == L' ' && !inside)
		{
			if (reading)
			{
				s += L' ';
			}
			else
			{
				if (!s.empty())
				{
					std::transform(s.begin(), s.end(), s.begin(), ::toupper);

					if (AddThisKeyword(s)) // not a bracketted search function, must
					{
						// be a text AND or single string search
						SearchTerms.push_back(s);
					}

					s.clear();
				}
			}
		}
		else
		{
			s += UserSearchTerms[i];
		}
	}

	if (!s.empty())
	{
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);

		if (AddThisKeyword(s))
		{
			SearchTerms.push_back(s);
		}
	}

	// -------------------------------------------------------------------------

	try
	{
		GScanEngine->DataSearch.Clear();

		// -------------------------------------------------------------------------

		for (int z = 0; z < SearchCriteria.size(); z++)
		{
			sco = SearchCriteria[z];

			switch (sco.Type)
			{
			case SearchType::Category:
				CategorySearchCount++;
				break;
			case SearchType::NotCategory:
				CategorySearchCount++;
				break;
			case SearchType::UserName:
				UserSearchCount++;
				break;
			case SearchType::NotUserName:
				UserSearchCount++;
				break;
			case SearchType::FolderExclude:
				ExcludeFolderSearchCount++;
				break;
			case SearchType::FolderInclude:
				IncludeFolderSearchCount++;
				break;
			}
		}

		if (CategorySearchCount == 0)
		{
			CategorySearchFound = true;
		}
		else
		{
			CategorySearchFound = false;
		}

		if (UserSearchCount == 0)
		{
			UserSearchFound = true;
		}
		else
		{
			UserSearchFound = false;
		}

		if (ExcludeFolderSearchCount == 0)
		{
			ExcludeFolderSearchFound = true;
		}
		else
		{
			ExcludeFolderSearchFound = false;
		}

		if (IncludeFolderSearchCount == 0)
		{
			IncludeFolderSearchFound = true;
		}
		else
		{
			IncludeFolderSearchFound = false;
		}

		// =========================================================================
		// =========================================================================

		for (FileObject file : GScanEngine->Data.Files)
		{
			Found = false;

			// search for each search term -------------------------------------------
			for (int x = 0; x < SearchTerms.size(); x++)
			{
				if (SearchTerms[x][0] == '"')  // this is an AND search...
				{
					ProcessQuickTerms(SearchTerms[x]);

					FoundTerms.clear();

					for (std::wstring term : QuickTerms)
					{
						std::wstring filename(GScanEngine->Data.Folders[file.FilePathIndex] + file.Name);

						std::transform(filename.begin(), filename.end(), filename.begin(), ::toupper);

						if (term.find(filename) != std::wstring::npos)
						{
							if (std::find(FoundTerms.begin(), FoundTerms.end(), term) != FoundTerms.end())
							{
								FoundTerms.push_back(term);
							}
						}
					}

					if (FoundTerms.size() == QuickTerms.size())
					{
						Found = true;
					}
				}
				else
				{
					auto z = SearchTerms[x].find(L'*');

					if (z != std::wstring::npos)
					{
						if (!(file.Attributes & FILE_ATTRIBUTE_DIRECTORY))
						{
							std::wstring filename(file.Name);
							std::transform(filename.begin(), filename.end(), filename.begin(), ::toupper);

							if (z == 0)
							{
								std::wstring parameter(SearchTerms[x].substr(1));

								if (parameter.find(filename) == filename.length() - SearchTerms[x].length() + 2) // to do check!

								{
									Found = true;
								}
							}
							else if (z == SearchTerms[x].length() - 1)
							{
								std::wstring parameter(SearchTerms[x].substr(0, SearchTerms[x].length() - 1));

								if (parameter.find(filename) == 0) // to do check!
								{
									Found = true;
								}
							}
						}
					}
					else
					{
						std::wstring filename(GScanEngine->Data.Folders[file.FilePathIndex] + file.Name);
						std::transform(filename.begin(), filename.end(), filename.begin(), ::toupper);

						if (SearchTerms[x].find(filename) != std::wstring::npos)
						{
							Found = true;
						}
					}
				}
			}

			// if there are no search terms, but search criteria then we set found to
			// true in order that we check every item for the criteria
			if (SearchTerms.size() == 0 && SearchCriteria.size() > 0)
			{
				Found = true;
			}

			// =======================================================================
			// =======================================================================

			// == process any special search criteria ================================
			if (Found && SearchCriteria.size() != 0)
			{
				for (int z = 0; z < SearchCriteria.size(); z++)
				{
					sco = SearchCriteria[z];

					Found = FindSpecial(Found, sco, file);
				}
			}

			// =======================================================================
			// =======================================================================

			if (CategorySearchCount > 0)
			{
				CategorySearchFound = false;

				for (int z = 0; z < SearchCriteria.size(); z++)
				{
					sco = SearchCriteria[z];

					CategorySearchFound = FindCategory(CategorySearchFound, sco, file);
				}
			}

			// =======================================================================
			// =======================================================================

			if (UserSearchCount > 0)
			{
				UserSearchFound = true;

				for (int z = 0; z < SearchCriteria.size(); z++)
				{
					sco = SearchCriteria[z];

					UserSearchFound = FindUserName(UserSearchFound, sco, file);
				}
			}

			// =======================================================================
			// =======================================================================

			if (ExcludeFolderSearchCount > 0)
			{
				ExcludeFolderSearchFound = true;

				for (int z = 0; z < SearchCriteria.size(); z++)
				{
					sco = SearchCriteria[z];

					switch (sco.Type)
					{
					case SearchType::FolderExclude:
					{
						std::wstring folder(GScanEngine->Data.Folders[file_object.FilePathIndex]);

						std::transform(folder.begin(), folder.end(), folder.begin(), ::toupper);

						if (sco.StringValue.find(folder) != std::wstring::npos)
						{
							ExcludeFolderSearchFound = false;
						}
						break;
					}
					}
				}
			}

			// =======================================================================
			// =======================================================================

			if (IncludeFolderSearchCount > 0)
			{
				IncludeFolderSearchFound = false;

				for (int z = 0; z < SearchCriteria.size(); z++)
				{
					sco = SearchCriteria[z];

					switch (sco.Type)
					{
					case SearchType::FolderInclude:
					{
						std::wstring folder(GScanEngine->Data.Folders[file_object.FilePathIndex]);

						std::transform(folder.begin(), folder.end(), folder.begin(), ::toupper);

						if (sco.StringValue.find(folder) != std::wstring::npos)
						{
							IncludeFolderSearchFound = true;
						}

						break;
					}
					}
				}
			}

			// =======================================================================
			// =======================================================================

			Found = (Found && CategorySearchFound && UserSearchFound && ExcludeFolderSearchFound && IncludeFolderSearchFound);

			// =======================================================================
			// =======================================================================

			if (Found)
			{
				if (FILE_ATTRIBUTE_DIRECTORY & file_object.Attributes)
				{
					GScanEngine->DataSearch.FolderCount++;
				}
				else
				{
					GScanEngine->DataSearch.FileCount++;
				}

				GScanEngine->DataSearch.TotalSize += file_object.Size;

				//GLog->Add( std::format(L"{0}  {1}{2}\n", Formatting::AddLeadingSpace(Convert::ConvertToUsefulUnit(file_object.Size), 8), Data.Folders[file_object.FilePathIndex], file_object.Name);

				FoundCount++;

				// ===================================================================

				GScanEngine->DataSearch.Files.push_back(file_object);

				// ===================================================================
			}
		}
	}
	catch(...)
	{

	}

	return FoundCount;
}


bool ProcessSearch::FindSpecial(bool found, SearchCriteriaObject &sco, FileObject &tfo)
{
	switch (sco.Type)
	{
	case SearchType::SizeLess: // size <
		if (!(faDirectory & tfo.Attributes))
		{
			if (tfo.Size > sco.IntegerValue)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::SizeEqual: // size =
		if (!(faDirectory & tfo.Attributes))
		{
			if (tfo.Size == sco.IntegerValue)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::SizeMore: // size >
		if (!(faDirectory & tfo.Attributes))
		{
			if (tfo.Size < sco.IntegerValue)
			{
				   return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::DateLess: // date <
		if (tfo.DateCreated != 0)
		{
			if (tfo.DateCreated > sco.IntegerValue)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::DateMore: // date >
		if (tfo.DateCreated != 0)
		{
			if (tfo.DateCreated < sco.IntegerValue)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::DateEqual: // date =
		if (tfo.DateCreated != 0)
		{
			if (tfo.DateCreated != sco.IntegerValue)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::ATimeLess:
		if (tfo.TimeAccessed > sco.IntegerValue)
		{
			return false;
		}
		break;
	case SearchType::ATimeMore :
		if (tfo.TimeAccessed < sco.IntegerValue)
		{
			return false;
		}
		break;
	case SearchType::ATimeEqual:
		if (tfo.TimeAccessed != sco.IntegerValue)
		{
			return false;
		}
		break;
	case SearchType::MTimeLess :
		if (tfo.TimeModified > sco.IntegerValue)
		{
			return false;
		}
		break;
	case SearchType::MTimeMore:
		if (tfo.TimeModified < sco.IntegerValue)
		{
			return false;
		}
		break;
	case SearchType::MTimeEqual:
		if (tfo.TimeModified != sco.IntegerValue)
		{
			return false;
		}
		break;
	case SearchType::TimeLess:
		if (tfo.TimeCreated > sco.IntegerValue)
		{
			return false;
		}
		break;
	case SearchType::TimeMore:
		if (tfo.TimeCreated < sco.IntegerValue)
		{
			return false;
		}
		break;
	case SearchType::TimeEqual:
		if (tfo.TimeCreated != sco.IntegerValue)
		{
			return false;
		}
		break;
	case SearchType::FileType: // hidden and system etc.
		switch (sco.IntegerValue)
		{
		case __FileType_Hidden            : if (!(faHidden & tfo.Attributes))                    return false;
		case __FileType_System            : if (!(faSysFile & tfo.Attributes))                   return false;
		case __FileType_Archive           : if (!(faArchive & tfo.Attributes))                   return false;
		case __FileType_Null              : if (tfo.Size != 0)                                   return false;
		case __FileType_ReadOnly          : if (!(faReadOnly & tfo.Attributes))                  return false;
		case __FileType_Compressed        : if (!(faCompressed & tfo.Attributes))                return false;
		case __FileType_Encrypted         : if (!(faEncrypted & tfo.Attributes))                 return false;
		case __FileType_RecallOnOpen      : if (!(faRecallOnOpen & tfo.Attributes))              return false;
		case __FileType_RecallOnDataAccess: if (!(faRecallOnDataAccess & tfo.Attributes))        return false;
		case __FileType_Offline           : if (!(faOffline & tfo.Attributes))                   return false;
		case __FileType_CreatedToday      : if (tfo.DateCreated != GScanEngine->TodayAsInteger)  return false;
		case __FileType_AccessedToday     : if (tfo.DateAccessed != GScanEngine->TodayAsInteger) return false;
		case __FileType_ModifiedToday     : if (tfo.DateModified != GScanEngine->TodayAsInteger) return false;
		case __FileType_Temp              : if (!tfo.Temp)                                       return false;
		case __FileType_Folder            : if (!(faDirectory & tfo.Attributes))                 return false;
		case __FileType_File              : if (faDirectory & tfo.Attributes)         		     return false;
		case __FileType_NoExtension       : if (ExtractFileExt(tfo.Name.c_str()) != L"")         return false;
			case __FileType_SparseFile        : if (!(faSparseFile & tfo.Attributes))            return false;
			case __FileType_Reparsepoint      : if (!(faReparsePoint & tfo.Attributes))          return false;
			case __FileType_NotContentI       : if (!(faNotContentI & tfo.Attributes))           return false;

		case __FileType_Virtual           : if (!(faRecallOnOpen & tfo.Attributes) &&
												!(faRecallOnDataAccess & tfo.Attributes) &&
												!(faOffline & tfo.Attributes))                   return false;
		}
		break;
	case SearchType::NotFileType: // hidden and system etc.
		switch (sco.IntegerValue)
		{
		case __FileType_Hidden            : if (faHidden & tfo.Attributes)                       return false;
		case __FileType_System            : if (faSysFile & tfo.Attributes)                      return false;
		case __FileType_Archive           : if (faArchive & tfo.Attributes)                      return false;
		case __FileType_Null              : if (tfo.Size == 0)                                   return false;
		case __FileType_ReadOnly          : if (faReadOnly & tfo.Attributes)                     return false;
		case __FileType_Compressed        : if (faCompressed & tfo.Attributes)                   return false;
		case __FileType_Encrypted         : if (faEncrypted & tfo.Attributes)                    return false;
		case __FileType_RecallOnOpen      : if (faRecallOnOpen & tfo.Attributes)                 return false;
		case __FileType_RecallOnDataAccess: if (faRecallOnDataAccess & tfo.Attributes)           return false;
		case __FileType_Offline           : if (faOffline & tfo.Attributes)                      return false;
		case __FileType_CreatedToday      : if (tfo.DateCreated == GScanEngine->TodayAsInteger)  return false;
		case __FileType_AccessedToday     : if (tfo.DateAccessed == GScanEngine->TodayAsInteger) return false;
		case __FileType_ModifiedToday     : if (tfo.DateModified == GScanEngine->TodayAsInteger) return false;
		case __FileType_Temp              : if (tfo.Temp)                                        return false;
		case __FileType_Folder            : if (faDirectory & tfo.Attributes)                    return false;
		case __FileType_File              : if (!(faDirectory & tfo.Attributes))                 return false;
		case __FileType_NoExtension       : if (ExtractFileExt(tfo.Name.c_str()) != L"")         return false;
		case __FileType_SparseFile        : if (faSparseFile & tfo.Attributes)                   return false;
		case __FileType_Reparsepoint      : if (faReparsePoint & tfo.Attributes)                 return false;
		case __FileType_NotContentI       : if (faNotContentI & tfo.Attributes)                  return false;

		case __FileType_Virtual           : if ((faRecallOnOpen & tfo.Attributes) ||
												(faRecallOnDataAccess & tfo.Attributes) ||
											    (faOffline & tfo.Attributes))                    return false;
		}
		break;
	case SearchType::ADateLess: // adate <
		if (tfo.DateAccessed != 0)
		{
			if (tfo.DateAccessed > sco.IntegerValue)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::ADateMore: // adate >
		if (tfo.DateAccessed != 0)
		{
			if (tfo.DateAccessed < sco.IntegerValue)
			{
				return false;;
			}
		}
		else
		{
			return false;;
		}
		break;
	case SearchType::ADateEqual: // adate =
		if (tfo.DateAccessed != 0)
		{
			if (tfo.DateAccessed != sco.IntegerValue)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::MDateLess: // mdate <
		if (tfo.DateModified != 0)
		{
			if (tfo.DateModified > sco.IntegerValue)
			{
				return false;;
			}
		}
		else
		{
			return false;;
		}
		break;
	case SearchType::MDateMore: // mdate >
		if (tfo.DateModified != 0)
		{
			if (tfo.DateModified < sco.IntegerValue)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::MDateEqual: // mdate =
		if (tfo.DateModified != 0)
		{
			if (tfo.DateModified != sco.IntegerValue)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case SearchType::FileNameLengthEqual:
		if (tfo.Name.size() != sco.IntegerValue)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case SearchType::FileNameLengthLess:
		if (tfo.Name.size() > sco.IntegerValue)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case SearchType::FilenameLengthMore:
		if (tfo.Name.size() < sco.IntegerValue)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case SearchType::FilePathLengthEqual:
		if (GScanEngine->Data.Folders[tfo.FilePathIndex].size() + tfo.Name.size() != sco.IntegerValue)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case SearchType::FilePathLengthLess:
		if (GScanEngine->Data.Folders[tfo.FilePathIndex].size() + tfo.Name.size() > sco.IntegerValue)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case SearchType::FilePathLengthMore:
		if (GScanEngine->Data.Folders[tfo.FilePathIndex].size() + tfo.Name.size() < sco.IntegerValue)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case SearchType::FileExtensionEqual:
	{
		std::wstring ext = ExtractFileExt(tfo.Name.c_str()).c_str();

		std::transform(ext.begin(), ext.end(), ext.begin(), ::toupper);

		if (ext != sco.StringValue)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	}
	}

	return found;
}


bool ProcessSearch::FindCategory(bool found, SearchCriteriaObject &sco, FileObject &tfo)
{
	switch (sco.Type)
	{
	case SearchType::Category: // category
		if (!(faDirectory & tfo.Attributes))
		{
			if (sco.IntegerValue == __Category_Custom_All)
			{
				if (tfo.Category >= __Category_Custom_1)
				{
					return true;
				}
			}
		}
		else
		{
			if (tfo.Category == sco.IntegerValue)
			{
				return true;
			}
		}
		break;
	case SearchType::NotCategory: // category
		if (!(faDirectory & tfo.Attributes))
		{
			if (sco.IntegerValue == __Category_Custom_All)
			{
				if (tfo.Category < __Category_Custom_1)
				{
					return true;
				}
			}
		}
		else
		{
			if (tfo.Category != sco.IntegerValue)
			{
				return true;
			}
		}
        break;
	}

	return found;
}


bool ProcessSearch::FindUserName(bool found, SearchCriteriaObject &sco, FileObject &tfo)
{
	std::wstring name = GScanEngine->Data.Users[tfo.Owner].Name;

	std::transform(name.begin(), name.end(), name.begin(), ::toupper);

	switch (sco.Type)
	{
	case SearchType::UserName:
		if (name != sco.StringValue)
		{
			return false;
		}
		break;
	case SearchType::NotUserName:
		if (name == sco.StringValue)
		{
			return false;
		}
		break;
	case SearchType::UserNameContains:
		if (name.find(sco.StringValue) == std::wstring::npos)
		{
			return false;
		}
		break;
	case SearchType::UserNameNotContains:
	{
		if (name.find(sco.StringValue) != std::wstring::npos)
		{
			return false;
		}
		break;
	}
    }

	return found;
}
