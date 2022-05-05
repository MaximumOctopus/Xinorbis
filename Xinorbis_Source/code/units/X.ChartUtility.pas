{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.ChartUtility;


interface


uses
  System.Classes, Generics.Defaults, System.SysUtils,
  VCLTee.Series, VCLTee.TeeProcs, VCLTee.Chart, VCLTee.TeeExport, VCLTee.TeEngine,
  VCLTee.TeCanvas,

  TMSLogging,

  AdvGrid, StdCtrls, htmltv, PngImage,

  X.Settings;


type
  TChartUtility = class
    class function  SeriesMarksStyleToInteger(tsms : TSeriesMarksStyle): integer;
    class function  IntegerToSeriesMarksStyle(xint : integer): TSeriesMarksStyle;

    class procedure SetChartGradient(idx : integer; thischart : TChart; tco : TChartOptions);
    class procedure SetAdvancedOptions(mychart : TChart; tceo : TChartOptions);

    class procedure CopyChartToClipboard(var chart : TChart);
    class procedure ChangeChartToPie(mychart : TChart);
    class procedure ChangeChartToHorizontalBar(mychart : TChart; aIsDirList : boolean);
    class procedure SaveChartToPNG(var chart : TChart; const FileName : string);

    class function  GetChartType(var mychart : TChart): integer;
    class function  SetChartType(var mychart : TChart; aNewChartType : integer): integer;
  end;


const
  __TypeUnknown         = 0;
  __TypeChartPie        = 1;
  __TypeChartBar        = 2;
  __TypeChartHorizontal = 3;

  CsmsValue             = 0;
  CsmsPercent           = 1;
  CsmsLabel             = 2;
  CsmsLabelPercent      = 3;
  CsmsLabelValue        = 4;
  CsmsLegend            = 5;
  CsmsPercentTotal      = 6;
  CsmsLabelPercentTotal = 7;
  CsmsXValue            = 8;


implementation


uses Windows, Graphics, ClipBrd,

     X.FileExtension, X.Constants;


class function TChartUtility.SeriesMarksStyleToInteger(tsms : TSeriesMarksStyle): integer;
 begin
  Result := 0;

  if tsms = smsValue then
    Result := 0
  else if tsms = smsPercent then
    Result := 1
  else if tsms = smsLabel then
    Result := 2
  else if tsms = smsLabelPercent then
    Result := 3
  else if tsms = smsLabelValue then
    Result := 4
  else if tsms = smsLegend then
    Result := 5
  else if tsms = smsPercentTotal then
    Result := 6
  else if tsms = smsLabelPercentTotal then
    Result := 7
  else if tsms = smsXValue then
    Result := 8;
end;


class function TChartUtility.IntegerToSeriesMarksStyle(xint : integer): TSeriesMarksStyle;
begin
  Result := smsValue;

  if (xint >= CsmsValue) and (xint <= CsmsXValue)  then begin
    case xint of
      CsmsValue             : Result := smsValue;
      CsmsPercent           : Result := smsPercent;
      CsmsLabel             : Result := smsLabel;
      CsmsLabelPercent      : Result := smsLabelPercent;
      CsmsLabelValue        : Result := smsLabelValue;
      CsmsLegend            : Result := smsLegend;
      CsmsPercentTotal      : Result := smsPercentTotal;
      CsmsLabelPercentTotal : Result := smsLabelPercentTotal;
      CsmsXValue            : Result := smsXValue;
    end;
  end;
end;


class procedure TChartUtility.SetChartGradient(idx : integer; thischart : TChart; tco : TChartOptions);
 begin
  if idx <> 9 then begin
    if thischart <> Nil then begin
      thischart.Gradient.StartColor := tco.ChartFrom;
      thischart.Gradient.EndColor   := tco.ChartTo;
      thischart.Gradient.Visible    := tco.ChartGradient;

      SetAdvancedOptions(thischart, tco);
    end;
  end;
end;


class procedure TChartUtility.SetAdvancedOptions(mychart : TChart; tceo : TChartOptions);
begin
  Assert(mychart <> nil, 'SetAdvancedOptions :: Chart is nil');

  if mychart.SeriesCount <> 0 then begin
    mychart.Series[0].Marks.BackColor := tceo.MarkColour;
    mychart.Series[0].Marks.Visible   := tceo.ShowMarks;
    mychart.Series[0].Marks.Style     := IntegerToSeriesMarksStyle(tceo.MarksType);

    if mychart.Series[0] is TPieSeries then begin
      TPieSeries(mychart.Series[0]).ExplodeBiggest := tceo.Explode;
      mychart.View3DOptions.Zoom                       := tceo.Zoom;
    end
    else if mychart.Series[0] is TBarSeries then begin

    end
    else if mychart.Series[0] is THorizBarSeries then begin

    end;
  end;

  mychart.View3DOptions.Elevation          := tceo.Elevation;

  myChart.Legend.Visible                   := tceo.ShowLegend;

  mychart.Title.Font.Color                 := tceo.TitleColour;

  myChart.AxesList.Bottom.Axis.Color       := tceo.MarkColour;
  myChart.AxesList.Left.Axis.Color         := tceo.MarkColour;
  myChart.AxesList.Right.Axis.Color        := tceo.MarkColour;
  myChart.AxesList.Top.Axis.Color          := tceo.MarkColour;

  myChart.AxesList.Bottom.LabelsFont.Color := tceo.MarkColour;
  myChart.AxesList.Left.LabelsFont.Color   := tceo.MarkColour;
  myChart.AxesList.Right.LabelsFont.Color  := tceo.MarkColour;
  myChart.AxesList.Top.LabelsFont.Color    := tceo.MarkColour;

  myChart.AxesList.Bottom.Title.Font.Color := tceo.MarkColour;
  myChart.AxesList.Left.Title.Font.Color   := tceo.MarkColour;
  myChart.AxesList.Right.Title.Font.Color  := tceo.MarkColour;
  myChart.AxesList.Top.Title.Font.Color    := tceo.MarkColour;

  myChart.Color                     := tceo.ChartFrom;
  mychart.Gradient.StartColor       := tceo.ChartFrom;
  mychart.Gradient.EndColor         := tceo.ChartTo;
  mychart.Gradient.Visible          := tceo.ChartGradient;
end;


class procedure TChartUtility.CopyChartToClipboard(var chart : TChart);
 var
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
  end;
end;


class procedure TChartUtility.ChangeChartToPie(mychart : TChart);
 var
  MySeries  : TChartSeriesClass;
  oldseries : TChartSeries;

 begin
  Assert(mychart <> nil, 'ChangeChartToPie :: Chart is nil');

  if GetChartType(mychart) <> __TypeChartPie then begin

    myseries  := TPieSeries;
    oldseries := mychart.Series[0];

    ChangeSeriesType(oldseries, MySeries);
    mychart.series[0].Marks.Style := smsLabel;
    mychart.View3D := True;

    if mychart.SeriesCount <> 0 then begin
      TPieSeries(mychart.Series[0]).ExplodeBiggest := XSettings.Charts.Options.Explode;
      mychart.View3DOptions.Zoom                   := XSettings.Charts.Options.Zoom;
    end;
  end;
end;


class procedure TChartUtility.ChangeChartToHorizontalBar(mychart : TChart; aIsDirList : boolean);
 var
  MySeries  : TChartSeriesClass;
  oldseries : TChartSeries;

 begin
  Assert(mychart <> nil, 'ChangeChartToHorizontalBar :: Chart is nil');

  if GetChartType(mychart) <> __TypeChartHorizontal then begin

    myseries  := THorizBarSeries;
    oldseries := mychart.Series[0];

    ChangeSeriesType(oldseries, MySeries);

    if aIsDirList then
      mychart.Series[0].Marks.Style := smsXValue
    else
      mychart.series[0].Marks.Style := smsPercent;

    mychart.View3D := False;
  end;
end;


class procedure TChartUtility.SaveChartToPNG(var chart : TChart; const FileName : string);
 var
  bmp : TBitmap;
  png : TPNGImage;

 begin
  Assert(chart <> Nil, 'SaveChartToPNG :: Chart nil!');

  if chart <> Nil then begin
    png := TPNGImage.Create;
    bmp := TBitmap.Create;

    try
      bmp.PixelFormat := pf24bit;
      bmp.Width       := Chart.Width;
      bmp.Height      := Chart.Height;

      chart.Draw(bmp.Canvas, Rect(0, 0, bmp.Width, bmp.Height));

      try
        png.Assign(bmp);
        png.SaveToFile(filename);
      except
        on e : System.SysUtils.Exception do begin
          TMSLogger.Error('Couldn''t save chart file "' + filename + '". ' + e.ClassName + ' / ' + e.Message);
        end;
      end;
    finally
      bmp.Free;
      png.free;
    end;
  end;
end;


class function TChartUtility.GetChartType(var mychart : TChart): integer;
begin
  Result := __TypeUnknown;

  if mychart.SeriesCount <> 0 then begin
    if mychart.Series[0] is TPieSeries then
      Result := __TypeChartPie
    else if mychart.Series[0] is TBarSeries then
      Result := __TypeChartBar
    else if mychart.Series[0] is THorizBarSeries then
      Result := __TypeChartHorizontal;
  end;
end;


class function TChartUtility.SetChartType(var mychart : TChart; aNewChartType : integer): integer;
begin
  Result := 0;

  case aNewChartType of
    __TypeUnknown         : {};
    __TypeChartPie        : ChangeChartToPie(mychart);
    __TypeChartBar        : { does this need to do anything? };
    __TypeChartHorizontal : ChangeChartToHorizontalBar(mychart, False);
  end;
end;


end.
