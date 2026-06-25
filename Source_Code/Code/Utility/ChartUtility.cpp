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


namespace ChartUtility
{
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


	void ChartChangeChartToPie(TChart* chart)
	{
		if (GetChartType(chart) != ChartType::kPie)
		{
			TChartSeries *old = chart->Series[0];

			ChangeSeriesType(old, __classid(TPieSeries));

			chart->Series[0]->Marks->Style = smsLabel;
			chart->View3D = true;

			if (chart->SeriesCount != 0)
			{
				//TPieSeries(mychart.Series[0]).ExplodeBiggest := XSettings.Charts.Options.Explode;
			  //mychart.View3DOptions.Zoom                   := XSettings.Charts.Options.Zoom;     to do
			}
		}
	}


	void ChangeChartToBar(TChart* chart, bool is_folder_list)
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


	ChartType GetChartType(TChart *chart)
	{
		if (chart->SeriesCount != 0)
		{
			if (typeid(chart->Series[0]) == typeid(TPieSeries))
			{
				return ChartType::kPie;
			}
			else if (typeid(chart->Series[0]) == typeid(TBarSeries))
			{
				return ChartType::kChartBar;
			}
			else if (typeid(chart->Series[0]) == typeid(THorizBarSeries))
			{
				return ChartType::kHorizontal;
			}
		}

		return ChartType::kUnknown;
	}
}
