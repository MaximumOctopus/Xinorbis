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

#include "GuiUtility.h"


void GuiUtility::SetButtonImageEnabled(TSpeedButton *button, int start_offset, bool enabled)
{
	if (enabled)
	{
		button->ImageIndex = button->Tag;
	}
	else
	{
		button->ImageIndex = button->Tag + start_offset;
	}

	button->Enabled = enabled;
}
