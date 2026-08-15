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

#include <fstream>

#include <System.DateUtils.hpp>

#include "XFormGetDateBetween.h"
#include "XFormGetSizeBetween.h"

#include "Convert.h"
#include "QuickMenuHandler.h"
#include "Utility.h"

QuickMenuHandler *GQuickMenuHandler;


QuickMenuAction QuickMenuHandler::FromMenu(int menu_index)
{
	std::wstring menu_string = Commands[menu_index];

	std::wstring search_command = L"";
	int other_command = -1;

	if (menu_string.find(L'{') != std::wstring::npos)
	{
		search_command = ParseMenuSearchCommand(menu_string);
	}
	else if (menu_string[0] == L'$')
	{
		other_command = ParseMenuSearchCommandII(menu_string);
	}
	else
	{
		search_command = menu_string;
	}

	QuickMenuAction qma;

	if (other_command != -1)
	{
		qma.Action = QMAction::kOther;
		qma.SubAction = other_command;
	}
	else
	{
		if (search_command != L"")
		{
			qma.Action = QMAction::kSearchString;
			qma.Search = search_command;
		}
	}

	return qma;
}


bool QuickMenuHandler::LoadMenu(TPopupMenu *pum, const std::wstring file_name)
{
	TMenuItem *LastNode = nullptr;

	std::wifstream file(file_name);

	if (file)
	{
		std::wstring s(L"");

		while (std::getline(file, s))
		{
			if (!s.empty())
			{
				switch (s[1])
				{
				case L'-':
				{
					TMenuItem *mi = new TMenuItem(pum);
					mi->Caption = L"-";
					mi->Tag = -1;

					if (LastNode == nullptr)
					{
						pum->Items->Add(mi);
					}
					else
					{
						LastNode->Add(mi);
					}

					break;
				}
				case L'{':
				{
					TMenuItem *mi = new TMenuItem(pum);
					mi->Caption = s.substr(1).c_str();
					mi->Enabled = false;
					mi->Tag = -1;

					if (LastNode == nullptr)
					{
						pum->Items->Add(mi);
					}
					else
					{
						LastNode->Add(mi);
					}
					break;
				}
				case L'[':
				{
					TMenuItem *mi = new TMenuItem(pum);
					mi->Caption = s.substr(1).c_str();
					mi->Enabled = true;
					mi->Tag = -1;

					if (LastNode == nullptr)
					{
						pum->Items->Add(mi);
					}
					else
					{
						LastNode->Add(mi);
					}

					LastNode = mi;
					break;
				}
				case L'.':
				{
					TMenuItem *mi = new TMenuItem(pum);

					auto ix = s.find(L'=');

					if (ix != std::wstring::npos)
					{
						mi->Caption = s.substr(0, ix - 1).c_str();

						Commands.push_back(s.substr(ix + 1).c_str());

						mi->Tag = Commands.size() - 1;
					}
					else
					{
						mi->Caption = s.substr(1, ix - 1).c_str();

	                    mi->Tag = -1;
					}

					mi->Enabled = true;

					if (LastNode == nullptr)
					{
						pum->Items->Add(mi);
					}
					else
					{
						LastNode->Add(mi);
					}
					break;
				}
				case L'*':
				{
					LastNode = LastNode->Parent;

					break;
				}
				}
			}
		}

		file.close();

		return true;
	}

    return false;
}


std::wstring QuickMenuHandler::ParseMenuSearchCommand(const std::wstring input)
{
	std::vector<std::wstring> ParameterList;

	std::wstring parameter = L"";
	bool gocopy = false;

	std::wstring s = L"";

	for (int t = 0; t < input.size(); t++)
	{
		if (input[t] == L'}')
		{
			gocopy = false;

			std::transform(parameter.begin(), parameter.end(), parameter.begin(), ::toupper);

			ParameterList.push_back(parameter);

			parameter = L"";
		}

		if (gocopy)
		{
			parameter += input[t];
		}

		if (input[t] == L'{')
		{
			gocopy = true;
		}
	}

	// =========================================================================

	int dwindex = 0;

	for (int t = 0; t < ParameterList.size(); t++)
	{
		if (ParameterList[t] == L"NOW")
		{
			s = Utility::ReplaceString(s, L"{NOW}", Convert::DateToYYYYMMDDS(Now()));
		}
		else if (ParameterList[t] == L"YESTERDAY")
		{
			s = Utility::ReplaceString(s, L"{YESTERDAY}", Convert::DateToYYYYMMDDS(Now()));
		}
		else if (ParameterList[t] == L"GETDATEDIALOGC")
		{
			s = OpenDateDialog(L"date");
		}
		else if (ParameterList[t] == L"GETDATEDIALOGA")
		{
			s = OpenDateDialog(L"adate");
		}
		else if (ParameterList[t] == L"GETDATEDIALOGM")
		{
			s = OpenDateDialog(L"mdate");
		}
		else if (ParameterList[t] == L"GETSIZEDIALOG")
		{
			s = OpenSizeDialog();
		}
		else if (ParameterList[t].find(L"DECWEEK") != std::wstring::npos)
		{
			if (ParameterList[t].size() != 7)
			{
				dwindex = StrToIntDef(ParameterList[t].substr(7).c_str(), 0);
			}
			else
			{
				dwindex = 1;
			}

			s = Utility::ReplaceString(s, L"{" + ParameterList[t] + L"}", Convert::DateToYYYYMMDDS(IncWeek(Now(), -dwindex)));
		}
		else if (ParameterList[t].find(L"DECMONTH") != std::wstring::npos)
		{
			if (ParameterList[t].size() != 8)
			{
				dwindex = StrToIntDef(ParameterList[t].substr(8).c_str(), 0);
			}
			else
			{
				dwindex = 1;
			}

			s = Utility::ReplaceString(s, L"{" + ParameterList[t] + L"}", Convert::DateToYYYYMMDDS(IncMonth(Now(), -dwindex)));
		}
	}

	return s;
}


int QuickMenuHandler::ParseMenuSearchCommandII(const std::wstring input)
{
	std::wstring command = input;

	std::transform(command.begin(), command.end(), command.begin(), ::tolower);

	if (command.substr(1) == L"searchwizard")
	{
		return 1;
	}

	return -1;
}


std::wstring QuickMenuHandler::GetCommand(int index)
{
	return Commands[index];
}
