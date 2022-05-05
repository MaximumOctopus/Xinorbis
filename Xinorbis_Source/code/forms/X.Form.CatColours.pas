{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: January 25th 2009
  Last Modified: January 11th 2020
}


unit X.Form.CatColours;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  StdCtrls, ExtCtrls,

  X.Help, X.LanguageHandler, X.SystemGlobal, Vcl.Imaging.pngimage, Vcl.Buttons;

type
  TfrmCategoryColours = class(TForm)
    sCat1: TShape;
    sCat2: TShape;
    sCat3: TShape;
    sCat4: TShape;
    sCat5: TShape;
    sCat6: TShape;
    sCat7: TShape;
    sCat8: TShape;
    sCat9: TShape;
    sCat10: TShape;
    sCat11: TShape;
    sCat12: TShape;
    sCat13: TShape;
    sCat14: TShape;
    sbFC1: TLabel;
    sbFC2: TLabel;
    sbFC3: TLabel;
    sbFC8: TLabel;
    sbFC9: TLabel;
    sbFC6: TLabel;
    sbFC7: TLabel;
    sbFC4: TLabel;
    sbFC5: TLabel;
    sbFC10: TLabel;
    sbFC11: TLabel;
    sbFC12: TLabel;
    sbFC13: TLabel;
    sbFC14: TLabel;
    sCat15: TShape;
    sCat16: TShape;
    sCat17: TShape;
    sCat18: TShape;
    sCat19: TShape;
    sbFC15: TLabel;
    sbFC16: TLabel;
    sbFC17: TLabel;
    sbFC18: TLabel;
    sbFC19: TLabel;
    Image1: TImage;
    sbSearch: TSpeedButton;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure sbSearchClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmCategoryColours: TfrmCategoryColours;

procedure ShowCategoryColours;


implementation


{$R *.dfm}


uses
  X.Utility, X.Global, X.Constants;


var
  ChartColoursArray : array[1..19] of TShape;


procedure ShowCategoryColours;
begin
  with TfrmCategoryColours.Create(Application) do
    try
      ShowModal;
    finally
      free;
    end;
end;


procedure TfrmCategoryColours.FormCreate(Sender: TObject);
var
  t : integer;

begin
  ChartColoursArray[1]  := sCat1;  ChartColoursArray[2]  := sCat2;  ChartColoursArray[3]  := sCat3;
  ChartColoursArray[4]  := sCat4;  ChartColoursArray[5]  := sCat5;  ChartColoursArray[6]  := sCat6;
  ChartColoursArray[7]  := sCat7;  ChartColoursArray[8]  := sCat8;  ChartColoursArray[9]  := sCat9;
  ChartColoursArray[10] := sCat10; ChartColoursArray[11] := sCat11; ChartColoursArray[12] := sCat12;
  ChartColoursArray[13] := sCat13; ChartColoursArray[14] := sCat14; ChartColoursArray[15] := sCat15;
  ChartColoursArray[16] := sCat16; ChartColoursArray[17] := sCat17; ChartColoursArray[18] := sCat18;
  ChartColoursArray[19] := sCat19;

  for t := 1 to __FileCategoriesCount do
    ChartColoursArray[t].Brush.Color := GSystemGlobal.FileCategoryColors[t];

  sbFC1.Caption  := TypeDescriptions[1];
  sbFC2.Caption  := TypeDescriptions[2];
  sbFC3.Caption  := TypeDescriptions[3];
  sbFC4.Caption  := TypeDescriptions[4];
  sbFC5.Caption  := TypeDescriptions[5];
  sbFC6.Caption  := TypeDescriptions[6];
  sbFC7.Caption  := TypeDescriptions[7];
  sbFC8.Caption  := TypeDescriptions[8];
  sbFC9.Caption  := TypeDescriptions[9];
  sbFC10.Caption := TypeDescriptions[10];
  sbFC11.Caption := TypeDescriptions[11];
  sbFC12.Caption := TypeDescriptions[12];
  sbFC13.Caption := TypeDescriptions[13];
  sbFC14.Caption := TypeDescriptions[14];
  sbFC15.Caption := TypeDescriptions[15];
  sbFC16.Caption := TypeDescriptions[16];
  sbFC17.Caption := TypeDescriptions[17];
  sbFC18.Caption := TypeDescriptions[18];
  sbFC19.Caption := TypeDescriptions[19];
end;


procedure TfrmCategoryColours.FormShow(Sender: TObject);
begin
  Caption := XText[rsCategoryColours];
end;


procedure TfrmCategoryColours.sbSearchClick(Sender: TObject);
begin
  THelp.OpenHelpPage('catcolours.htm');
end;


procedure TfrmCategoryColours.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  Action := caFree;
end;


end.
