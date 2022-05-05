{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

        Started: January 7th 2020
  Last Modified: January 11th 2020
}


unit X.ThemeHelper;


interface


uses AdvGDIP, AdvSmoothTabPager;

type
  TThemeHelper = class
    class procedure SetSmoothTabPage(stp : TAdvSmoothTabPage);
    class procedure SetSmoothTabPager(stp : TAdvSmoothTabPager);
  end;


const
  CBackgroundDark = $00222222;
  CBackground     = $00333333;
  CBackgroundTo   = $00FCDBC1;
  CTabDisabled    = $00EEEEEE;
  CTabDown        = $00AAAAAA;
  CTabHot         = $00AAAAAA;
  CTabSelected    = $00888888;
  CTextDisabled   = $00AAAAAA;
  CTextHot        = $00EEEEEE;
  CTextSelected   = $00EEEEEE;


implementation


class procedure TThemeHelper.SetSmoothTabPager(stp : TAdvSmoothTabPager);
begin
  stp.Color                   := CBackgroundDark;

  stp.Fill.Color              := CBackgroundDark;
  stp.Fill.ColorTo            := CBackgroundDark;
  stp.Fill.GradientMirrorType := gtSolid;
  stp.Fill.GradientType       := gtSolid;
end;


class procedure TThemeHelper.SetSmoothTabPage(stp : TAdvSmoothTabPage);
begin
  stp.PageAppearance.BorderColor          := CBackground;
  stp.PageAppearance.BorderWidth          := 0;
  stp.PageAppearance.Color                := CBackground;
  stp.PageAppearance.ColorMirror          := CBackground;
  stp.PageAppearance.ColorMirrorTo        := CBackground;
  stp.PageAppearance.ColorTo              := CBackground;
  stp.PageAppearance.GradientMirrorType   := gtSolid;
  stp.PageAppearance.GradientType         := gtSolid;

  stp.TabAppearance.BevelColor            := CTabHot;
  stp.TabAppearance.BevelColorDisabled    := CTabHot;
  stp.TabAppearance.BevelColorDown        := CTabHot;
  stp.TabAppearance.BevelColorHot         := CTabHot;
  stp.TabAppearance.BevelColorSelected    := CTabHot;

  stp.TabAppearance.Color                 := CBackground;
  stp.TabAppearance.ColorDisabled         := CTabDisabled;
  stp.TabAppearance.ColorDown             := CTabDown;
  stp.TabAppearance.ColorHot              := CTabHot;
  stp.TabAppearance.ColorSelected         := CTabSelected;

  stp.TabAppearance.ColorTextDisabled     := CTextDisabled;
  stp.TabAppearance.Appearance.Font.Color := CTextDisabled;
  stp.TabAppearance.ColorTextHot          := CTextHot;
  stp.TabAppearance.ColorTextSelected     := CTextSelected;
end;


end.


