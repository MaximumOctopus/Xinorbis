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

// available commands for the in-built console

#include "Command.h"


std::wstring Command::GetFullCommand()
{
	return primarystr + L" " + fullcommandstr;
}


void Command::Print()
{
	//GLog->Add( "  Primary      :" << primarystr << "\n";
	//GLog->Add( "  Secondary    :" << secondary << "\n";
	//GLog->Add( "  Tertiary     :" << tertiary << "\n";
	//GLog->Add( "  Quaternary   :" << quaternary << "\n";
	//GLog->Add( "  Full Command :" << fullcommandstr << "\n";
}