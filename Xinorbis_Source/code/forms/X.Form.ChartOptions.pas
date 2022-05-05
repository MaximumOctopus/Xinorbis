{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: January 16th 2019
  Last Modified: January 11th 2020
}


unit X.Form.ChartOptions;

interface

uses
  System.UITypes, Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, Buttons, ExtCtrls, ComCtrls, VCLTee.TeEngine, VCLTee.Series,
  VCLTee.TeeProcs, VCLTee.Chart, AdvOfficeButtons,
  VclTee.TeeGDIPlus, VclTee.TeCanvas,

  X.Help, X.ChartUtility, X.Utility, X.Settings, X.LanguageHandler, X.SystemGlobal,
  Vcl.Dialogs;

type
  TfrmChartOptions = class(TForm)
    bSave: TBitBtn;
    bCancel: TBitBtn;
    vtcOptions: TChart;
    Series1: TPieSeries;
    Bevel2: TBevel;
    cdMain: TColorDialog;
    bHelp: TBitBtn;
    Label1: TLabel;
    Label2: TLabel;
    lZoom: TLabel;
    lExplodeBiggest: TLabel;
    Label3: TLabel;
    sLabelColour: TShape;
    lTitleColour: TLabel;
    sTitleColour: TShape;
    tbZoom: TTrackBar;
    tbExplodeBiggest: TTrackBar;
    cbShowLegend: TAdvOfficeCheckBox;
    cbShowLabels: TAdvOfficeCheckBox;
    cbLabelOptions: TComboBox;
    cbMarksType: TComboBox;
    Shape1: TShape;
    Shape2: TShape;
    lGradientFrom: TLabel;
    lGradientTo: TLabel;
    cbShowGradient: TAdvOfficeCheckBox;
    procedure tbZoomChange(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormCreate(Sender: TObject);
    procedure tbExplodeBiggestChange(Sender: TObject);
    procedure sLabelColourMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure cbMarksTypeChange(Sender: TObject);
    procedure cbShowLabelsClick(Sender: TObject);
    procedure bHelpClick(Sender: TObject);
    procedure sTitleColourMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure cbShowLegendClick(Sender: TObject);
    procedure Shape1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Shape2MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure cbShowGradientClick(Sender: TObject);
  private
    procedure SetChartFurniture(aColour : integer);
  public
    { Public declarations }
  end;

var
  frmChartOptions: TfrmChartOptions;

function DoAdvancedChartOptions(tceox : TChartOptions): TChartOptions;


implementation


{$R *.dfm}


uses
  X.Global, X.Constants;


function DoAdvancedChartOptions(tceox : TChartOptions): TChartOptions;
 var
  oldseries : Tchartseries;

 begin
  with TfrmChartOptions.Create(Application) do
    try
      tbZoom.Position           := tceox.Zoom;
      tbExplodeBiggest.Position := tceox.Explode;

      sLabelColour.Brush.Color  := tceox.MarkColour;
      cbShowLabels.Checked      := tceox.ShowMarks;
      cbMarksType.ItemIndex     := tceox.MarksType;
      cbLabelOptions.ItemIndex  := tceox.LabelOptions;
      cbShowLegend.Checked      := tceox.ShowLegend;

      if cbMarksType.ItemIndex = 2 then
        cbLabelOptions.Enabled := True
      else
        cbLabelOptions.Enabled := False;

      vtcOptions.SeriesList.Items[0].Clear;
      vtcOptions.SeriesList.Items[0].Add(200, '', spectrumcolours[1]);
      vtcOptions.SeriesList.Items[0].Add(100, '', spectrumcolours[2]);
      vtcOptions.SeriesList.Items[0].Add(50, '',  spectrumcolours[3]);
      vtcOptions.SeriesList.Items[0].Add(20, '',  spectrumcolours[4]);
      vtcOptions.SeriesList.Items[0].Add(10, '',  spectrumcolours[5]);

      vtcOptions.View3DOptions.Zoom := tceox.Zoom;

      vtcOptions.SeriesList.Items[0].Marks.Style := TChartUtility.IntegerToSeriesMarksStyle(tceox.MarksType);

      vtcOptions.Title.Font.Color    := tceox.TitleColour;
      sTitleColour.Brush.Color       := tceox.TitleColour;

      vtcOptions.Gradient.StartColor := tceox.ChartFrom;
      vtcOptions.Gradient.EndColor   := tceox.ChartTo;
      vtcOptions.Color               := tceox.ChartFrom;
      vtcOptions.Gradient.Visible    := tceox.ChartGradient;
      cbShowGradient.Checked         := tceox.ChartGradient;

      Shape1.Brush.Color             := tceox.ChartFrom;
      Shape2.Brush.Color             := tceox.ChartTo;

      case tceox.ChartType of
        __TypeUnknown         : {};
        __TypeChartPie        : TPieSeries(vtcOptions.Series[0]).ExplodeBiggest := tbExplodeBiggest.Position;
        __TypeChartBar        : begin
                                  tbExplodeBiggest.Enabled := False;

                                  oldseries:=vtcOptions.Series[0];

                                  ChangeSeriesType(oldseries, TBarSeries);

                                  vtcOptions.View3D := False;
                                end;
        __TypeChartHorizontal : begin
                                  tbExplodeBiggest.Enabled := False;

                                  oldseries := vtcOptions.Series[0];
                                  ChangeSeriesType(oldseries, tHorizBarSeries);

                                  vtcOptions.View3D := False;
                                end;
      end;

      SetChartFurniture(sLabelColour.Brush.Color);

      tbZoomChange(Nil);
      tbExplodeBiggestChange(Nil);

      // =======================================================================

      ShowModal;

      // =======================================================================      

      tceox.Result        := 0;

      tceox.Zoom          := tbZoom.Position;
      tceox.Explode       := tbExplodeBiggest.Position;
      tceox.MarkColour    := sLabelColour.Brush.Color;
      tceox.ShowMarks     := cbShowLabels.Checked;
      tceox.MarksType     := cbMarksType.ItemIndex;
      tceox.LabelOptions  := cbLabelOptions.ItemIndex;
      tceox.ShowLegend    := cbShowLegend.Checked;

      tceox.TitleColour   := vtcOptions.Title.Font.Color;

      tceox.ChartFrom     := vtcOptions.Gradient.StartColor;
      tceox.ChartTo       := vtcOptions.Gradient.EndColor;
      tceox.ChartGradient := cbShowGradient.Checked;

      // =======================================================================

      if ModalResult = mrOK then begin
        tceox.Result := 1; // go!

        XSettings.Charts.Options := tceox;

        Result       := tceox;
      end;
    finally
      free;
    end;
end;


procedure TfrmChartOptions.FormCreate(Sender: TObject);
begin
  Caption              := XText[rsChartOptions];

  bSave.Caption        := XText[rsSave];
  bCancel.Caption      := XText[rsCancel];
  bHelp.Caption        := XText[rsHelp];

  Label1.Caption       := XText[rsChartZoomLevel];
  Label2.Caption       := XText[rsExplodeLargestSlice];
  Label3.Caption       := XText[rsLabelColour];
  cbShowLegend.Caption := XText[rsLegend];
  cbShowLabels.Caption := XText[rsShowLabels];

  cbMarksType.Items.Add(XText[rsValue]);
  cbMarksType.Items.Add(XText[rsPercent]);
  cbMarksType.Items.Add(XText[rsLabel]);
  cbMarksType.Items.Add(XText[rsLabelPercent]);
  cbMarksType.Items.Add(XText[rsLabelValue]);
  cbMarksType.Items.Add(XText[rsLegend]);
  cbMarksType.Items.Add(XText[rsPercentTotal]);
  cbMarksType.Items.Add(XText[rsLabelPercentTotal]);
  cbMarksType.Items.Add(XText[rsXValue]);

  cbLabelOptions.Items.Add(XText[rsDefault]);
  cbLabelOptions.Items.Add(XText[rsMostConvenient]);
  cbLabelOptions.Items.Add(XText[rsXKilobytes]);
  cbLabelOptions.Items.Add(XText[rsXMegabytes]);
  cbLabelOptions.Items.Add(XText[rsXGigabytes]);

  cbMarksType.ItemIndex := 0;

  lTitleColour.Caption := XText[rsTitleColour];

  lGradientFrom.Caption        := XText[rsGradientFrom];
  lGradientTo.Caption          := XText[rsGradientTo];
  cbShowGradient.Caption       := XText[rsToggleGradient];
end;


procedure TfrmChartOptions.Shape1MouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  cdMain.Color := TShape(Sender).Brush.Color;

  if cdMain.Execute then begin
    TShape(Sender).Brush.Color     := cdMain.Color;

    vtcOptions.Gradient.StartColor := cdMain.Color;

    vtcOptions.Color               := cdMain.Color; // needed if gradient is disabled
  end;
end;


procedure TfrmChartOptions.Shape2MouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  cdMain.Color := TShape(Sender).Brush.Color;

  if cdMain.Execute then begin
    TShape(Sender).Brush.Color   := cdMain.Color;

    vtcOptions.Gradient.EndColor := cdMain.Color;
  end;
end;


procedure TfrmChartOptions.FormClose(Sender: TObject; var Action: TCloseAction);
 begin
  Action := caFree;
end;


procedure TfrmChartOptions.tbZoomChange(Sender: TObject);
 begin
  vtcOptions.View3DOptions.Zoom := tbZoom.Position;

  lZoom.Caption := IntToStr(tbZoom.Position) + '%';
end;


procedure TfrmChartOptions.tbExplodeBiggestChange(Sender: TObject);
 begin
  if (vtcOptions.Series[0] is TPieSeries) then begin
    TPieSeries(vtcOptions.Series[0]).ExplodeBiggest := tbExplodeBiggest.Position;

    lExplodeBiggest.Caption := IntToStr(tbExplodeBiggest.Position);
  end;
end;


procedure TfrmChartOptions.sLabelColourMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 begin
  cdMain.Color := TShape(Sender).Brush.Color;

  if cdMain.Execute then begin
    TShape(Sender).Brush.Color := cdMain.Color;

    SetChartFurniture(cdMain.Color);
  end;
end;


procedure TfrmChartOptions.SetChartFurniture(aColour : integer);
begin
  vtcOptions.Series[0].Marks.BackColor        := cdMain.Color;

  vtcOptions.AxesList.Bottom.Axis.Color       := aColour;
  vtcOptions.AxesList.Left.Axis.Color         := aColour;
  vtcOptions.AxesList.Right.Axis.Color        := aColour;
  vtcOptions.AxesList.Top.Axis.Color          := aColour;

  vtcOptions.AxesList.Bottom.LabelsFont.Color := aColour;
  vtcOptions.AxesList.Left.LabelsFont.Color   := aColour;
  vtcOptions.AxesList.Right.LabelsFont.Color  := aColour;
  vtcOptions.AxesList.Top.LabelsFont.Color    := aColour;

  vtcOptions.AxesList.Bottom.Title.Font.Color := aColour;
  vtcOptions.AxesList.Left.Title.Font.Color   := aColour;
  vtcOptions.AxesList.Right.Title.Font.Color  := aColour;
  vtcOptions.AxesList.Top.Title.Font.Color    := aColour;
end;


procedure TfrmChartOptions.sTitleColourMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
 begin
  cdMain.Color := TShape(Sender).Brush.Color;

  if cdMain.Execute then begin
    TShape(Sender).Brush.Color  := cdMain.Color;

    vtcOptions.Title.Font.Color := cdMain.Color;
  end;
end;


procedure TfrmChartOptions.cbMarksTypeChange(Sender: TObject);
begin
  vtcOptions.Series[0].Marks.Style := TChartUtility.IntegerToSeriesMarksStyle(cbMarksType.ItemIndex);

  if cbMarksType.ItemIndex = 2 then
    cbLabelOptions.Enabled := True
  else
    cbLabelOptions.Enabled := False;
end;


procedure TfrmChartOptions.cbShowGradientClick(Sender: TObject);
begin
  vtcOptions.Gradient.Visible    := cbShowGradient.Checked;
end;


procedure TfrmChartOptions.cbShowLabelsClick(Sender: TObject);
 begin
  vtcOptions.Series[0].Marks.Visible := cbShowLabels.Checked;
end;


procedure TfrmChartOptions.cbShowLegendClick(Sender: TObject);
 begin
  vtcOptions.Legend.Visible := cbShowLegend.Checked;
end;


procedure TfrmChartOptions.bHelpClick(Sender: TObject);
 begin
  THelp.OpenHelpPage('chartoptions.htm');
end;


end.
