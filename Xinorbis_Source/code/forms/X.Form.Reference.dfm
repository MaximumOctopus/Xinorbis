object frmReference: TfrmReference
  Left = 551
  Top = 266
  BorderIcons = [biSystemMenu]
  Caption = '.'
  ClientHeight = 390
  ClientWidth = 651
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object mResults: TMemo
    Left = 0
    Top = 65
    Width = 651
    Height = 325
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      '')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object pcReference: TAdvSmoothTabPager
    Left = 0
    Top = 0
    Width = 651
    Height = 65
    Fill.Color = 16773091
    Fill.ColorTo = 16768452
    Fill.ColorMirror = 16765357
    Fill.ColorMirrorTo = 16767936
    Fill.GradientType = gtNone
    Fill.GradientMirrorType = gtVertical
    Fill.BorderColor = 16765357
    Fill.Rounding = 0
    Fill.ShadowOffset = 0
    Fill.Glow = gmNone
    Transparent = False
    Align = alTop
    ActivePage = AdvSmoothTabPager12
    Color = clWhite
    TabSettings.StartMargin = 4
    TabReorder = False
    TabOrder = 1
    object AdvSmoothTabPager12: TAdvSmoothTabPage
      Left = 1
      Top = 26
      Width = 649
      Height = 37
      Caption = ''
      PageAppearance.Color = clWhite
      PageAppearance.ColorTo = clWhite
      PageAppearance.ColorMirror = clWhite
      PageAppearance.ColorMirrorTo = clWhite
      PageAppearance.GradientType = gtVertical
      PageAppearance.GradientMirrorType = gtVertical
      PageAppearance.BorderColor = 13948116
      PageAppearance.Rounding = 0
      PageAppearance.ShadowOffset = 0
      PageAppearance.Glow = gmNone
      TabAppearance.Appearance.Font.Charset = DEFAULT_CHARSET
      TabAppearance.Appearance.Font.Color = 4473924
      TabAppearance.Appearance.Font.Height = -11
      TabAppearance.Appearance.Font.Name = 'Tahoma'
      TabAppearance.Appearance.Font.Style = []
      TabAppearance.Appearance.SimpleLayout = True
      TabAppearance.Appearance.SimpleLayoutBorder = True
      TabAppearance.Appearance.Rounding = 0
      TabAppearance.Status.Caption = '0'
      TabAppearance.Status.Appearance.Fill.Color = clRed
      TabAppearance.Status.Appearance.Fill.ColorMirror = clNone
      TabAppearance.Status.Appearance.Fill.ColorMirrorTo = clNone
      TabAppearance.Status.Appearance.Fill.GradientType = gtSolid
      TabAppearance.Status.Appearance.Fill.GradientMirrorType = gtSolid
      TabAppearance.Status.Appearance.Fill.BorderColor = clGray
      TabAppearance.Status.Appearance.Fill.Rounding = 0
      TabAppearance.Status.Appearance.Fill.ShadowOffset = 0
      TabAppearance.Status.Appearance.Fill.Glow = gmNone
      TabAppearance.Status.Appearance.Font.Charset = DEFAULT_CHARSET
      TabAppearance.Status.Appearance.Font.Color = clWhite
      TabAppearance.Status.Appearance.Font.Height = -11
      TabAppearance.Status.Appearance.Font.Name = 'Tahoma'
      TabAppearance.Status.Appearance.Font.Style = []
      TabAppearance.BevelColor = clWhite
      TabAppearance.BevelColorDown = clWhite
      TabAppearance.BevelColorSelected = 16765357
      TabAppearance.BevelColorDisabled = clWhite
      TabAppearance.Color = clWhite
      TabAppearance.ColorDown = clWhite
      TabAppearance.ColorSelected = clWhite
      TabAppearance.ColorDisabled = 15658734
      TMSStyle = 21
      object sbFileExtensions: TSpeedButton
        Left = 8
        Top = 8
        Width = 23
        Height = 22
        Enabled = False
        Flat = True
        Glyph.Data = {
          36060000424D3606000000000000360000002800000020000000100000000100
          18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF6494BA2267
          9D81A8C6FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FF9B9B9B737373ADADADFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF6F9CC2558DBC89B5
          DD185F97FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFA4A4A4979797BDBDBD6C6C6CFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF7BA4CA6497C59DC1E46699
          C73171A5FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFABABABA1A1A1C8C8C8A3A3A37D7D7DFF00FFFF00FFFF00FFFF00FF
          FF00FFE8CFBADBB292D3A680D0A17CD2A685AEA19975A2CCABCBE876A4CE407B
          AFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFCDCDCDAFAFAFA2A2A29E9E9EA3
          A3A3A0A0A0ABABABD1D1D1ACACAC878787FF00FFFF00FFFF00FFFF00FFFF00FF
          E8CAB0E8C9AEF5E1CDF7E5D3F7E5D1F3DDC8DFBA9CC7A89186AED55087BBFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFC7C7C7C6C6C6DEDEDEE3E3E3E2E2E2DA
          DADAB7B7B7A6A6A6B6B6B6939393FF00FFFF00FFFF00FFFF00FFFF00FFF1DBC8
          EDD0B7F8E8D9F5DEC8F3D8BDF3D6BBF4DBC2F7E4D2DFBB9DA09795FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFD9D9D9CDCDCDE6E6E6DBDBDBD4D4D4D2D2D2D8
          D8D8E2E2E2B7B7B7989898FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFEECEB2
          F7E7D7F6E1CCF4DBC2F4DAC0F3D8BDF3D7BBF4DBC2F3DEC9D2A887FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFCBCBCBE5E5E5DEDEDED8D8D8D7D7D7D4D4D4D3
          D3D3D8D8D8DBDBDBA5A5A5FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFF0CEAF
          F9ECDFF5DFC8F5DDC6F4DCC3F4DAC1F3D9BEF3D7BDF8E6D3D3A680FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFCACACAEAEAEADCDCDCDADADAD9D9D9D7D7D7D5
          D5D5D4D4D4E3E3E3A2A2A2FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFF4D3B5
          F9EDE1F6E1CCF5DFC9F5DEC7F4DCC4F4DBC2F4DAC0F8E7D6D7AB87FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFCFCFCFECECECDEDEDEDCDCDCDBDBDBD9D9D9D8
          D8D8D7D7D7E5E5E5A8A8A8FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFF8DBC1
          F9EBDEF7E7D6F6E1CCF5E0CAF5DEC8F5DDC5F6E1CBF5E2D0DFB999FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFD8D8D8E9E9E9E5E5E5DEDEDEDDDDDDDBDBDBDA
          DADADEDEDEE0E0E0B5B5B5FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFCEAD8
          F8E2CCFAEEE3F7E7D6F6E2CEF6E1CBF6E3D0F9EADDECCFB5ECD4BFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFE8E8E8DFDFDFEDEDEDE5E5E5DFDFDFDEDEDEE0
          E0E0E9E9E9CCCCCCD2D2D2FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FBE4CEF9E2CDFAECDEF9EEE2F9EDE2F8E9DAF0D5BDEDD0B7FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFE1E1E1DFDFDFEAEAEAEDEDEDECECECE7
          E7E7D2D2D2CDCDCDFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFCEAD9FADDC2F6D6B9F4D3B5F3D4B8F5E0CDFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFE8E8E8D9D9D9D2D2D2CFCFCFD1
          D1D1DDDDDDFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
        NumGlyphs = 2
        OnClick = sbFileExtensionsClick
      end
      object eFileExtension: TEdit
        Left = 32
        Top = 8
        Width = 153
        Height = 21
        TabOrder = 0
        OnChange = eFileExtensionChange
        OnKeyPress = eFileExtensionKeyPress
      end
      object bHelp: TBitBtn
        Left = 539
        Top = 3
        Width = 107
        Height = 25
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000120B0000120B00000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FFA393839D7753A3703EA2703F9D7855A39385FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA39282AB6D31AD6C2DAD6C2DAD
          6C2DAD6C2DAD6C2DAD6C2DAB6E33A49688FF00FFFF00FFFF00FFFF00FFFF00FF
          9C7F62AD6C2DAD6C2DAD6C2DAD6C2DBB8751B8824CAD6C2DAD6C2DAD6C2DAD6C
          2D9D8369FF00FFFF00FFFF00FFA29181AD6C2DAD6C2DAD6C2DAD6C2DB3793FFF
          FFFFFFFFFFAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DA49688FF00FFFF00FFAB6D31
          AD6C2DAD6C2DAD6C2DAD6C2DB07237FFFFFFFFFFFFAD6C2DAD6C2DAD6C2DAD6C
          2DAD6C2DA96C32FF00FFA1907FAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAE6E30AD
          6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DA395869E764FAD6C2D
          AD6C2DAD6C2DAD6C2DAD6C2DAE6F31FCFBF8FFFFFFB3773DAD6C2DAD6C2DAD6C
          2DAD6C2DAD6C2D9D7955A66F3AAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DDE
          C5AEFFFFFFFFFFFFB8814BAD6C2DAD6C2DAD6C2DAD6C2DA27140A56E39AD6C2D
          AD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAF6F32E4D0BCFFFFFFFFFFFFB57C44AD6C
          2DAD6C2DAD6C2DA370409E754DAD6C2DAD6C2DAD6C2DC08F5ECFAA87B67E47AD
          6C2DAD6D2EE5D1BEFFFFFFD6B698AD6C2DAD6C2DAD6C2D9D7752A08D7AAD6C2D
          AD6C2DAD6C2DDCC2A8FFFFFFDEC5ADAD6C2DAD6C2DE0C8B1FFFFFFD9BCA0AD6C
          2DAD6C2DAD6C2DA29281FF00FFAC6D2FAD6C2DAD6C2DBB8753FFFFFFFFFFFFF0
          E4D8F1E6DBFFFFFFFFFFFFBC8854AD6C2DAD6C2DAB6D31FF00FFFF00FF9F8B78
          AD6C2DAD6C2DAD6C2DBF8E5DEADACBFFFFFFFFFFFFEADACBC19162AD6C2DAD6C
          2DAD6C2DA29080FF00FFFF00FFFF00FF9C7B59AD6C2DAD6C2DAD6C2DAD6C2DAD
          6C2EAD6C2DAD6C2DAD6C2DAD6C2DAD6C2D9B7D5FFF00FFFF00FFFF00FFFF00FF
          FF00FF9F8A75AC6C2FAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAC6D2F9F8C
          79FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9F8A75A17347A9
          6D33A86D349F73489F8B78FF00FFFF00FFFF00FFFF00FFFF00FF}
        TabOrder = 1
        OnClick = bHelpClick
      end
    end
    object AdvSmoothTabPager13: TAdvSmoothTabPage
      Left = 1
      Top = 26
      Width = 649
      Height = 37
      Caption = ''
      PageAppearance.Color = clWhite
      PageAppearance.ColorTo = clWhite
      PageAppearance.ColorMirror = clWhite
      PageAppearance.ColorMirrorTo = clWhite
      PageAppearance.GradientType = gtVertical
      PageAppearance.GradientMirrorType = gtVertical
      PageAppearance.BorderColor = 13948116
      PageAppearance.Rounding = 0
      PageAppearance.ShadowOffset = 0
      PageAppearance.Glow = gmNone
      TabAppearance.Appearance.Font.Charset = DEFAULT_CHARSET
      TabAppearance.Appearance.Font.Color = 4473924
      TabAppearance.Appearance.Font.Height = -11
      TabAppearance.Appearance.Font.Name = 'Tahoma'
      TabAppearance.Appearance.Font.Style = []
      TabAppearance.Appearance.SimpleLayout = True
      TabAppearance.Appearance.SimpleLayoutBorder = True
      TabAppearance.Appearance.Rounding = 0
      TabAppearance.Status.Caption = '0'
      TabAppearance.Status.Appearance.Fill.Color = clRed
      TabAppearance.Status.Appearance.Fill.ColorMirror = clNone
      TabAppearance.Status.Appearance.Fill.ColorMirrorTo = clNone
      TabAppearance.Status.Appearance.Fill.GradientType = gtSolid
      TabAppearance.Status.Appearance.Fill.GradientMirrorType = gtSolid
      TabAppearance.Status.Appearance.Fill.BorderColor = clGray
      TabAppearance.Status.Appearance.Fill.Rounding = 0
      TabAppearance.Status.Appearance.Fill.ShadowOffset = 0
      TabAppearance.Status.Appearance.Fill.Glow = gmNone
      TabAppearance.Status.Appearance.Font.Charset = DEFAULT_CHARSET
      TabAppearance.Status.Appearance.Font.Color = clWhite
      TabAppearance.Status.Appearance.Font.Height = -11
      TabAppearance.Status.Appearance.Font.Name = 'Tahoma'
      TabAppearance.Status.Appearance.Font.Style = []
      TabAppearance.BevelColor = clWhite
      TabAppearance.BevelColorDown = clWhite
      TabAppearance.BevelColorSelected = 16765357
      TabAppearance.BevelColorDisabled = clWhite
      TabAppearance.Color = clWhite
      TabAppearance.ColorDown = clWhite
      TabAppearance.ColorSelected = clWhite
      TabAppearance.ColorDisabled = 15658734
      TMSStyle = 21
      object sbWindowsFile: TSpeedButton
        Left = 8
        Top = 8
        Width = 23
        Height = 22
        Enabled = False
        Glyph.Data = {
          36060000424D3606000000000000360000002800000020000000100000000100
          18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFDFEE7EE
          F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFDFDFDEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFBFD6494BA2267
          9D81A8C6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFCFCFC9B9B9B737373ADADADFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFCFD6F9CC2558DBC89B5
          DD185F97FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFCFCFCA4A4A4979797BDBDBD6C6C6CFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFCFD7BA4CA6497C59DC1E46699
          C73171A5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFCFCFCABABABA1A1A1C8C8C8A3A3A37D7D7DFFFFFFFFFFFFFFFFFFFFFFFF
          FFFEFEE8CFBADBB292D3A680D0A17CD2A685AEA19975A2CCABCBE876A4CE407B
          AFDEE8F1FFFFFFFFFFFFFFFFFFFFFFFFFEFEFECDCDCDAFAFAFA2A2A29E9E9EA3
          A3A3A0A0A0ABABABD1D1D1ACACAC878787EAEAEAFFFFFFFFFFFFFFFFFFFFFEFE
          E8CAB0E8C9AEF5E1CDF7E5D3F7E5D1F3DDC8DFBA9CC7A89186AED55087BBE1EA
          F3FFFFFFFFFFFFFFFFFFFFFFFFFEFEFEC7C7C7C6C6C6DEDEDEE3E3E3E2E2E2DA
          DADAB7B7B7A6A6A6B6B6B6939393ECECECFFFFFFFFFFFFFFFFFFFFFFFFF1DBC8
          EDD0B7F8E8D9F5DEC8F3D8BDF3D6BBF4DBC2F7E4D2DFBB9DA09795E3ECF5FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFD9D9D9CDCDCDE6E6E6DBDBDBD4D4D4D2D2D2D8
          D8D8E2E2E2B7B7B7989898EEEEEEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEECEB2
          F7E7D7F6E1CCF4DBC2F4DAC0F3D8BDF3D7BBF4DBC2F3DEC9D2A887FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFCBCBCBE5E5E5DEDEDED8D8D8D7D7D7D4D4D4D3
          D3D3D8D8D8DBDBDBA5A5A5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0CEAF
          F9ECDFF5DFC8F5DDC6F4DCC3F4DAC1F3D9BEF3D7BDF8E6D3D3A680FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFCACACAEAEAEADCDCDCDADADAD9D9D9D7D7D7D5
          D5D5D4D4D4E3E3E3A2A2A2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4D3B5
          F9EDE1F6E1CCF5DFC9F5DEC7F4DCC4F4DBC2F4DAC0F8E7D6D7AB87FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFCFCFCFECECECDEDEDEDCDCDCDBDBDBD9D9D9D8
          D8D8D7D7D7E5E5E5A8A8A8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8DBC1
          F9EBDEF7E7D6F6E1CCF5E0CAF5DEC8F5DDC5F6E1CBF5E2D0DFB999FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFD8D8D8E9E9E9E5E5E5DEDEDEDDDDDDDBDBDBDA
          DADADEDEDEE0E0E0B5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCEAD8
          F8E2CCFAEEE3F7E7D6F6E2CEF6E1CBF6E3D0F9EADDECCFB5ECD4BFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFE8E8E8DFDFDFEDEDEDE5E5E5DFDFDFDEDEDEE0
          E0E0E9E9E9CCCCCCD2D2D2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FBE4CEF9E2CDFAECDEF9EEE2F9EDE2F8E9DAF0D5BDEDD0B7FFFEFEFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1DFDFDFEAEAEAEDEDEDECECECE7
          E7E7D2D2D2CDCDCDFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFCEAD9FADDC2F6D6B9F4D3B5F3D4B8F5E0CDFFFFFEFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8E8E8D9D9D9D2D2D2CFCFCFD1
          D1D1DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        NumGlyphs = 2
        OnClick = sbWindowsFileClick
      end
      object eWindowsFile: TEdit
        Left = 32
        Top = 8
        Width = 153
        Height = 21
        TabOrder = 0
        OnChange = eWindowsFileChange
        OnKeyPress = eWindowsFileKeyPress
      end
      object rbXP: TAdvOfficeRadioButton
        Left = 198
        Top = 11
        Width = 43
        Height = 20
        TabOrder = 1
        Alignment = taLeftJustify
        Caption = 'XP'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
      object rbW7: TAdvOfficeRadioButton
        Left = 247
        Top = 11
        Width = 83
        Height = 20
        TabOrder = 2
        Alignment = taLeftJustify
        Caption = 'Windows 7'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
  end
end
