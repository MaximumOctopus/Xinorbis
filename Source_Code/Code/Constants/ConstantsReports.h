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


static const int __FileCategoriesCount = 20;
static const int __FileCategoriesOther = 9;
static const int __FileCategoriesCustom1 = 10;

static const int __TextReportOptionsCount = 11;
static const int __TreeReportOptionsCount = 6;

static const int __GraphWidth = 150;

static const int __SpectrumMod = 29;

static const int __ReportSizes[8] = { 1250, 370, 350, 618, 1238, 618, 1238, 152 };  // 1280x mode

static const int __DefaultDisplayColours[__FileCategoriesCount] = { 0xFFFF00, 0x9d9fff, 0x70b7fe, 0x72f1fc, 0x73fcb7, 0xc5fd71, 0xeefc72, 0xfccf72, 0xfc8d72, 0xfe79be,
																	0xfe70f3, 0x99bdd5, 0x8c8c8c, 0xd1d1d1, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff };

static const int __AttributesToDisplayCount = 13;    // attributes that are output to reports/screen etc.
static const int __AttributesCount = 21;
static const int __MagnitudesCount = 13;

static const int __HTMLColoursCount = 11;

static const int __rsTableWidth = 0;
static const int __rsBarGraph = 1;
static const int __rsChartDD = 2;
static const int __rsChartCM = 3;
static const int __rsChartCD = 4;
static const int __rsChartXM = 5;
static const int __rsChartFD = 6;
static const int __rsBarGraphSmall = 7;