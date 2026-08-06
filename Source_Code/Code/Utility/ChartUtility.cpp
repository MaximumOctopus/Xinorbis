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

#include <Vcl.Imaging.pngimage.hpp>
#include <VCLTee.Series.hpp>

#include "ChartUtility.h"
#include "SettingsHandler.h"

extern SettingsHandler *GSettingsHandler;


void ChartUtility::SetAdvancedOptions(TChart* chart, ChartOptions co)
{
	if (chart->SeriesCount != 0)
	{
		chart->SeriesList->Items[0]->Marks->BackColor = TColor(co.MarkColour);
		chart->SeriesList->Items[0]->Marks->Visible   = co.ShowMarks;
		chart->SeriesList->Items[0]->Marks->Style     = IntegerToSeriesMarksStyle(co.MarksType);

		if (chart->Series[0]->ClassNameIs(L"TPieSeries"))
		{
			reinterpret_cast<TPieSeries*>(chart->SeriesList->Items[0])->ExplodeBiggest = co.Explode;
			chart->View3DOptions->Zoom = co.Zoom;
		}
		//else if (chart.Series[0] is TBarSeries)
		//{
		//}
		//else if (chart.Series[0] is THorizBarSeries)
		//{
		//}
	}

	chart->View3DOptions->Elevation = co.Elevation;

	chart->Legend->Visible = co.ShowLegend;

	chart->Title->Font->Color                   = TColor(co.TitleColour);

	chart->AxesList->Bottom->Axis->Color        = TColor(co.MarkColour);
	chart->AxesList->Left->Axis->Color          = TColor(co.MarkColour);
	chart->AxesList->Right->Axis->Color         = TColor(co.MarkColour);
	chart->AxesList->Top->Axis->Color           = TColor(co.MarkColour);

	chart->AxesList->Bottom->LabelsFont->Color  = TColor(co.MarkColour);
	chart->AxesList->Left->LabelsFont->Color    = TColor(co.MarkColour);
	chart->AxesList->Right->LabelsFont->Color   = TColor(co.MarkColour);
	chart->AxesList->Top->LabelsFont->Color     = TColor(co.MarkColour);

	chart->AxesList->Bottom->Title->Font->Color = TColor(co.MarkColour);
	chart->AxesList->Left->Title->Font->Color   = TColor(co.MarkColour);
	chart->AxesList->Right->Title->Font->Color  = TColor(co.MarkColour);
	chart->AxesList->Top->Title->Font->Color    = TColor(co.MarkColour);

	chart->Color                = TColor(co.ChartFrom);
	chart->Gradient->StartColor = TColor(co.ChartFrom);
	chart->Gradient->EndColor   = TColor(co.ChartTo);
	chart->Gradient->Visible    = co.ChartGradient;
}


void ChartUtility::SaveChartToPNG(TChart *chart, const std::wstring file_name)
{
	if (chart != nullptr)
	{
		TPngImage* png  = new TPngImage();
		TBitmap *bmp = new TBitmap();

		try
		{
			bmp->PixelFormat = pf24bit;
			bmp->Width = chart->Width;
			bmp->Height = chart->Height;

			chart->Draw(bmp->Canvas, Rect(0, 0, bmp->Width, bmp->Height));

			png->Assign(bmp);
			png->SaveToFile(file_name.c_str());
		}
		catch(...)
		{
		}

		delete bmp;
		delete png;
	}
}


void ChartUtility::ChangeChartToPie(TChart* chart)
{
	if (GetChartType(chart) != ChartType::kPie)
	{
		TChartSeries *old = chart->Series[0];

		ChangeSeriesType(old, __classid(TPieSeries));

		chart->Series[0]->Marks->Style = smsLabel;
		chart->View3D = true;

		if (chart->SeriesCount != 0)
		{
			reinterpret_cast<TPieSeries*>(chart->SeriesList->Items[0])->ExplodeBiggest = GSettingsHandler->Chart.Explode;

			chart->View3DOptions->Zoom = GSettingsHandler->Chart.Zoom;
		}
	}
}


void ChartUtility::ChangeChartToHorizontalBar(TChart *chart, bool is_folder_list)
{
	if (GetChartType(chart) != ChartType::kBar)
	{
		TChartSeries *old = chart->Series[0];

		ChangeSeriesType(old, __classid(THorizBarSeries));

		if (is_folder_list)
		{
			chart->Series[0]->Marks->Style = smsXValue;
		}
		else
		{
			chart->Series[0]->Marks->Style = smsPercent;
		}

		chart->View3D = false;
	}
}


ChartType ChartUtility::GetChartType(TChart *chart)
{
	if (chart->SeriesCount != 0)
	{
		if (chart->Series[0]->ClassNameIs(L"TPieSeries"))
		{
			return ChartType::kPie;
		}
		else if (chart->Series[0]->ClassNameIs(L"TBarSeries"))
		{
			return ChartType::kBar;
		}
		else if (chart->Series[0]->ClassNameIs(L"THorizBarSeries"))
		{
			return ChartType::kHorizontal;
		}
	}

	return ChartType::kUnknown;
}


int ChartUtility::GetChartTypeInt(TChart *chart)
{
	if (chart->SeriesCount != 0)
	{
		if (chart->Series[0]->ClassNameIs(L"TPieSeries"))
		{
			return 1;
		}
		else if (chart->Series[0]->ClassNameIs(L"TBarSeries"))
		{
			return 2;
		}
		else if (chart->Series[0]->ClassNameIs(L"THorizBarSeries"))
		{
			return 3;
		}
	}

	return 0;
}


void ChartUtility::CopyChartToClipboard(TChart *chart)
{
/*
	bmp : TBitmap;
	zig : TRect;

	begin
	Assert(chart <> Nil, 'CopyChartToClipboard :: Chart nil!');

	if chart <> nil then begin
	bmp := TBitmap.Create;
	bmp.Width  := chart.width;
	bmp.Height := chart.Height;

	try
	  zig.Top    := 0;
	  zig.Left   := 0;
	  zig.Right  := bmp.width;
	  zig.Bottom := bmp.Height;

	  chart.Draw(bmp.Canvas, zig);

	  Clipboard.Assign(bmp);
	finally
	  bmp.Free;
	end;
	end; */
}


TSeriesMarksStyle ChartUtility::IntegerToSeriesMarksStyle(int value)
{
	if (value >= ksmsValue && value <= ksmsXValue)
	{
		switch (value)
		{
		case ksmsValue             : return smsValue;
		case ksmsPercent           : return smsPercent;
		case ksmsLabel             : return smsLabel;
		case ksmsLabelPercent      : return smsLabelPercent;
		case ksmsLabelValue        : return smsLabelValue;
		case ksmsLegend            : return smsLegend;
		case ksmsPercentTotal      : return smsPercentTotal;
		case ksmsLabelPercentTotal : return smsLabelPercentTotal;
		case ksmsXValue            : return smsXValue;
		}
	}

	return smsValue;
}
