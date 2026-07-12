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

#pragma once

#include <string>
#include <vector>

#include "Command.h"
#include "FileObject.h"
#include "SearchCriteriaObject.h"


class ProcessSearch
{

	bool FindSpecial(bool, SearchCriteriaObject&, FileObject&);
	bool FindCategory(bool, SearchCriteriaObject&, FileObject&);
	bool FindUserName(bool, SearchCriteriaObject&, FileObject&);

public:

	ProcessSearch();

    int Filter(Command);
};
