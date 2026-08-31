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
#include <vector>

#include <Vcl.Clipbrd.hpp>

#include "Formatting.h"
#include "GridUtility.h"
#include "ImageHandler.h"

extern ImageHandler *GImageHandler;


void GridUtility::ToggleColumn(TStringGrid *grid, TSpeedButton *button, int column_index, int new_width, int glyph_id)
{
	if (grid->ColWidths[column_index] == -1)    // hidden
	{
		grid->ColWidths[column_index] = new_width;

		if (button != nullptr)
		{
			GImageHandler->SetButtonOnImage(button, glyph_id);
		}
	}
	else
	{
		grid->ColWidths[column_index] = -1;

		if (button != nullptr)
		{
			GImageHandler->SetButtonOffImage(button, glyph_id);
		}
	}
}


void GridUtility::Clear(TStringGrid *grid, bool clear_objects)
{
	if (clear_objects)
	{
		for (int t = 1; t < grid->RowCount; t++)
		{
			if (grid->Objects[t][0] != NULL)
			{
				grid->Objects[t][0]->Free();
			}
		}
	}

	for (int r = 1; r < grid->RowCount; r++)
	{
		grid->Rows[r]->Clear();
	}

	grid->RowCount = 2;
}


void GridUtility::CopyGridToClipboard(TStringGrid* grid, int start_column)
{
	std::vector<std::wstring> *data = new std::vector<std::wstring>;

	for (int r = 0; r < grid->RowCount; r++)
	{
		std::wstring s = L"";

		for (int t = start_column; t < grid->ColCount; t++)
		{
			std::wstring cell = grid->Cells[t][r].c_str();

			if (t != grid->ColCount)
			{
				s += L"\"" + cell + L"\",";
			}
			else
			{
				s += L"\"" + cell + L"\"";
			}
		}

		data->push_back(s + L"\n");
	}

	std::wstring output = L"";

	for (std::wstring s : *data)
	{
		output += s;
	}

	Clipboard()->AsText = output.c_str();

	delete data;
}


void GridUtility::SaveGrid(TStringGrid *grid, const std::wstring file_name)
{
	std::ofstream file(file_name);

	if (file)
	{
		for (int r = 0; r < grid->RowCount; r++)
		{
			std::wstring s = L"";

			for (int t = 0; t < grid->ColCount; t++)
			{
				std::wstring cell = grid->Cells[t][r].c_str();

				if (t != grid->ColCount)
				{
					s += L"\"" + cell + L"\",";
				}
				else
				{
					s += L"\"" + cell + L"\"";
				}
			}

			file << Formatting::to_utf8(s + L"\n");
		}

		file.close();
	}
}
