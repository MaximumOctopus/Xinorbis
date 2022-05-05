{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.GuiUtil;

interface

uses
  System.SysUtils, Graphics, Vcl.Buttons, Vcl.Controls, AdvGrid, W7Buttons;


type
  TGuiUtil = class
  private
    FImageOnList  : TImageList;
    FImageOffList : TImageList;
    FFileTypes    : TImageList;

    procedure LoadIcons(aFolder : string);
  public
    constructor Create(aFolder : string);
    destructor Destroy; override;

    procedure SetButtonOnImage(mrbutton : TSpeedButton; imageindex : integer);
    procedure SetButtonOffImage(mrbutton : TSpeedButton; imageindex : integer);

    procedure SetButtonImageEnabled(mrbutton : TW7ToolButton; aOffStart : integer; aEnabled : boolean);

    procedure SetFolderHistoryButtonImage(mrbutton : TSpeedButton; imageindex : integer);

    procedure SetPieBarImages(piez, barz : TSpeedButton);
  end;


const
  CImageCreated    = 1;
  CImageAccessed   = 2;
  CImageModified   = 3;
  CImageOwner      = 4;
  CImageAttributes = 5;
  CImageSizeOnDisk = 6;
  CImageColourCode = 7;
  CImageShow       = 8;
  CImagePieGraph   = 9;
  CImageBarGraph   = 10;


implementation


constructor TGuiUtil.Create(aFolder : string);
begin
  inherited create;

  FImageOnList  := TImageList.Create(Nil);
  FImageOffList := TImageList.Create(Nil);
  FFileTypes    := TImageList.Create(Nil);

  FImageOnList.BkColor  := $00FF00FF;
  FImageOffList.BkColor := $00FF00FF;
  FFileTypes.BkColor    := $00FF00FF;

  LoadIcons(aFolder);
end;


destructor TGuiUtil.Destroy;
begin
  FreeAndNil(FImageOnList);
  FreeAndNil(FImageOffList);
  FreeAndNil(FFileTypes);

  inherited destroy;
end;


procedure TGuiUtil.LoadIcons(aFolder : string);
var
  t : integer;
  lBMP : TBitmap;

begin
  for t:= 0 to 10 do begin
    lBMP := TBitmap.Create;
    lBMP.LoadFromFile(aFolder + '\On\' + IntToStr(t) + '.bmp');
    FImageOnList.Add(lBmp, nil);
    lbmp.free;

    lBMP := TBitmap.Create;
    lBMP.LoadFromFile(aFolder + '\Off\' + IntToStr(t) + '.bmp');
    FImageOffList.Add(lBmp, nil);
    lbmp.free;
  end;

  for t:= 0 to 66 do begin
    lBMP := TBitmap.Create;
    lBMP.LoadFromFile(aFolder + '\Icons\' + IntToStr(t) + '.bmp');
    FFileTypes.Add(lBmp, nil);
    lbmp.free;
  end;
end;


procedure TGuiUtil.SetButtonOnImage(mrbutton : TSpeedButton; imageindex : integer);
 var
  tbmp : TBitmap;

 begin
  tbmp := TBitmap.Create;

  mrbutton.Glyph := nil;

  FImageOnList.GetBitmap(imageindex, tbmp);
  mrbutton.Glyph.Assign(tbmp);

  tbmp.Free;
end;


procedure TGuiUtil.SetButtonOffImage(mrbutton : TSpeedButton; imageindex : integer);
 var
  tbmp : TBitmap;

 begin
  tbmp := TBitmap.Create;

  FImageOffList.GetBitmap(imageindex, tbmp);
  mrbutton.Glyph.Assign(tbmp);

  tbmp.Free;
end;


// on images start at 0 + button.tag, off images start at aOffStart + button.tag
procedure TGuiUtil.SetButtonImageEnabled(mrbutton : TW7ToolButton; aOffStart : integer; aEnabled : boolean);
begin
  if aEnabled then
    mrbutton.ImageIndex := mrbutton.Tag
  else
    mrbutton.ImageIndex := mrbutton.Tag + aOffStart;

  mrbutton.Enabled    := aEnabled;
end;


procedure TGuiUtil.SetFolderHistoryButtonImage(mrbutton : TSpeedButton; imageindex : integer);
 var
  tbmp : TBitmap;

 begin
  if FFileTypes.Count <> 0 then
  begin
    tbmp := TBitmap.Create;

    FFileTypes.GetBitmap(imageindex, tbmp);
    mrbutton.Glyph := tbmp;

    tbmp.Free;
  end;
end;


procedure TGuiUtil.SetPieBarImages(piez, barz : TSpeedButton);
 begin
  if piez.Down then begin
    SetButtonOnImage(piez, CImagePieGraph);
    SetButtonOffImage(barz, CImageBarGraph);
  end
  else begin
    SetButtonOffImage(piez, CImagePieGraph);
    SetButtonOnImage(barz, CImageBarGraph);
  end;
end;


end.
