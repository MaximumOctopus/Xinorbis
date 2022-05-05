object frmEditCSVReport: TfrmEditCSVReport
  Left = 549
  Top = 273
  ClientHeight = 416
  ClientWidth = 958
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  OnConstrainedResize = FormConstrainedResize
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 553
    Height = 416
    Align = alLeft
    TabOrder = 0
    object Panel2: TPanel
      Left = 1
      Top = 1
      Width = 551
      Height = 35
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object sbSave: TSpeedButton
        Left = 4
        Top = 4
        Width = 110
        Height = 24
        Caption = '.'
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          20000000000000040000120B0000120B00000000000000000000FF00FF00CD95
          7000BD734200B7683500B5683500B4673400B2663400B0653300AE643300AC63
          3200AA623200A9613200A8603100A7613200AB693C00BC866100C37D4F00EBC6
          AD00EAC5AD00FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFB
          F800FEFBF800FEFBF800FEFBF800C89A7C00C7987900AD6B4000BA6C3800EDCA
          B300E0A27A00FEFAF70062C0880062C0880062C0880062C0880062C0880062C0
          880062C0880062C08800FDF9F600CA8D6500C99B7C00A7613200BB6C3800EECC
          B600E1A27A00FEFAF700BFDCC200BFDCC200BFDCC200BFDCC200BFDCC200BFDC
          C200BFDCC200BFDCC200FDF9F600CD906800CC9E8100A8613200BB6B3800EFCE
          B800E1A27900FEFAF70062C0880062C0880062C0880062C0880062C0880062C0
          880062C0880062C08800FDF9F600CF936A00CEA38400AA613200BA6A3600EFD0
          BB00E2A27A00FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFB
          F800FEFBF800FEFBF800FEFBF800D3966D00D2A78A00AB623200BB6A3600F0D2
          BE00E2A37A00E2A37A00E1A37A00E2A37B00E1A37B00E0A17800DE9F7700DD9F
          7600DC9D7400D99B7200D8997100D6997000D5AB8E00AD633300BB6A3600F2D5
          C200E3A37A00E3A37A00E2A37B00E2A37B00E2A47B00E1A27900E0A17800DEA0
          7700DE9E7500DC9D7400DA9B7300D99B7300DAB09500AF643300BB6A3600F2D8
          C500E3A47B00E3A37A00E3A47A00E2A47B00E2A37B00E1A37B00E1A27900DFA0
          7700DE9F7600DD9E7400DB9C7200DC9D7400DDB59A00B1653400BB6B3600F4D9
          C700E6A67D00C88C6400C98D6500C98E6700CB926C00CB926D00CA906900C88C
          6500C88C6400C88C6400C88C6400DA9C7400E1BA9F00B3663400BB6C3700F4DC
          C900E7A77D00F9ECE100F9ECE100F9EDE300FCF4EE00FDFAF700FDF7F300FAED
          E500F7E7DB00F7E5D900F6E5D800DEA07700E4BEA400B4673400BD6E3A00F5DD
          CC00E7A87E00FAF0E800FAF0E800C98D6600FAF0E900FDF8F300FEFAF800FCF4
          EF00F9E9DF00F7E7DB00F7E5D900E0A27800E7C2A900B6683500C0744200F6DF
          D000E8A87E00FCF6F100FCF6F100C88C6400FAF1E900FBF4EE00FDFAF700FDF9
          F600FAF0E800F8E8DD00F7E6DB00E1A37A00EFD5C300B76A3600C6825500F6DF
          D100E9AA8000FEFAF600FDFAF600C88C6400FBF3EE00FBF1EA00FCF6F200FEFB
          F800FCF6F100F9ECE200F8E7DB00EED0BA00ECD0BD00BD744300D6A58500F6E0
          D100F7E0D100FEFBF800FEFBF700FDF9F600FCF5F000FAF0EA00FBF2ED00FDF9
          F600FDFAF700FBF1EB00F8E9DF00ECD1BE00CD926A00FF00FF00E1BDA600D9AB
          8D00C9895E00C0754300BD6E3A00BB6C3700BB6B3600BB6A3600BB6A3600BC6C
          3900BD6E3B00BB6D3A00BF744400C98D6500FF00FF00FF00FF00}
        OnClick = sbSaveClick
      end
      object sbEditCSVLayout: TSpeedButton
        Left = 243
        Top = 4
        Width = 110
        Height = 24
        Caption = '.'
        OnClick = sbEditCSVLayoutClick
      end
      object sbCancel: TSpeedButton
        Left = 120
        Top = 5
        Width = 110
        Height = 24
        Caption = '.'
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1313F20000F10000F100
          00F10000EF0000EF0000ED1212EEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF1313F61A20F53C4CF93A49F83847F83545F83443F73242F7141BF11717
          EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1313F81D23F94453FA2429F91212F70F
          0FF60C0CF50909F5161BF53343F7141BF11717EFFFFFFFFFFFFFFFFFFF1313F9
          1F25FA4A58FB4247FBC9C9FD3B3BF91313F71010F63333F7C5C5FD3035F73444
          F7141BF21717EFFFFFFFFFFFFF0000FB4F5DFD3237FBCBCBFEF2F2FFEBEBFE3B
          3BF93939F8EAEAFEF1F1FEC5C5FD181DF63343F70000EFFFFFFFFFFFFF0000FD
          525FFD2828FC4747FCECECFFF2F2FFECECFFECECFEF1F1FFEAEAFE3434F70B0B
          F53545F80000EFFFFFFFFFFFFF0000FD5562FE2C2CFD2929FC4848FCEDEDFFF2
          F2FFF2F2FFECECFE3A3AF91212F70F0FF63848F80000F1FFFFFFFFFFFF0000FD
          5764FE3030FD2D2DFD4B4BFCEDEDFFF2F2FFF2F2FFECECFF3D3DF91616F81313
          F73C4BF80000F1FFFFFFFFFFFF0000FF5A67FE3333FE5050FDEDEDFFF3F3FFED
          EDFFEDEDFFF2F2FFECECFE3E3EFA1717F83F4EF90000F1FFFFFFFFFFFF0000FF
          5B68FF4347FECFCFFFF3F3FFEDEDFF4C4CFC4A4AFCECECFFF2F2FFCACAFE2A2F
          FA4251FA0000F3FFFFFFFFFFFF1414FF262BFF5D6AFF585BFFCFCFFF5252FE2F
          2FFD2C2CFD4B4BFCCCCCFE484CFB4957FB1D23F91414F6FFFFFFFFFFFFFFFFFF
          1414FF262BFF5D6AFF4347FF3434FE3232FE3030FD2D2DFD383CFC4F5DFC1F25
          FA1414F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1414FF262BFF5C69FF5B68FF5A
          67FE5865FE5663FE5461FE2227FC0D0DFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF1313FF0000FF0000FF0000FF0000FD0000FD0000FD1313FDFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        OnClick = sbCancelClick
      end
      object cbCSVLayouts: TComboBox
        Left = 359
        Top = 4
        Width = 178
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = sbEditCSVLayoutClick
      end
    end
    object Panel3: TPanel
      Left = 1
      Top = 36
      Width = 551
      Height = 379
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object lCSVTitle: TLabel
        Left = 17
        Top = 24
        Width = 3
        Height = 13
        Caption = '.'
      end
      object lCSVTitles: TLabel
        Left = 199
        Top = 56
        Width = 3
        Height = 13
        Caption = '.'
      end
      object lCSVAutoOpen: TLabel
        Left = 199
        Top = 179
        Width = 3
        Height = 13
        Caption = '.'
      end
      object lcsvs: TLabel
        Left = 17
        Top = 84
        Width = 3
        Height = 13
        Caption = '.'
      end
      object Label2: TLabel
        Left = 17
        Top = 111
        Width = 3
        Height = 13
        Caption = '.'
      end
      object Label27: TLabel
        Left = 17
        Top = 138
        Width = 3
        Height = 13
        Caption = '.'
      end
      object SpeedButton1: TSpeedButton
        Left = 514
        Top = 301
        Width = 23
        Height = 22
        Flat = True
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
        OnClick = SpeedButton1Click
      end
      object lReportsHTMLCustom: TGroupBox
        Left = 4
        Top = 242
        Width = 233
        Height = 87
        TabOrder = 0
        object sbPreview: TBitBtn
          Left = 15
          Top = 20
          Width = 160
          Height = 25
          Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            18000000000000030000120B0000120B00000000000000000000FF00FFFF00FF
            FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
            FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9A9A9A7C7C7C78787874
            74747070706C6C6C696969858585FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
            FF00FFFF00FFA8A8A8FBFBFBF7F7F7F6F6F6F5F5F5F7F7F7FBFBFB939393FF00
            FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8D8D8DB3B2B2C7C5C4C8
            C1C1C4BDBCCDC8C7A6A5A5757575FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
            FF00FFFF00FFFF00FFCECECEA8A8A8C8C6C5D9D5D4818181C1C1C1FF00FFFF00
            FFFF00FFFF00FFFF00FFFF00FFCFCFCFB5B5B5B1B1B1AEAEAEA3A3A3BBBBBBAB
            ABABA7A7A7B3B3B38F8F8F9494949191918D8D8DB9B9B9FF00FFFF00FFAEAEAE
            E4E3E3D7D6D5D6D3D2DBD8D7C4C1C1D2CDCCD1CCCBBDBBBAD5D2D2CCC9C9CCC9
            C9D8D6D6727272FF00FFFF00FFB4B4B4E0DEDDA7724DA7724DA7724DA7724DA7
            724DA7724DA7724DA7724DA7724DA7724DDAD6D4787878FF00FFFF00FFBABABA
            DEDBDBA7724DC8926CCA946DCC966ECD9770CF9971D19B73D39D74D49E75A772
            4DD7D2D17E7E7EFF00FFFF00FFBFBFBFDFDCDBA7724DC7916BC9936CCB956ECD
            976FCE9872D4A27DD6A580D6A47FA7724DD7D3D3848484FF00FFFF00FFC4C4C4
            E1DEDCA7724DC7916AC8926CCA946DD09D78D5A888D8AC8CD7A784D6A37DA772
            4DD9D5D48A8A8AFF00FFFF00FFC9C9C9E1DEDEA7724DC6906AC7916BCE9E7AD7
            AE90D9AF91D6A989D5A582D6A47EA7724DDBD6D6909090FF00FFFF00FFCECECE
            E2DFDFA7724DC58F69CB9975D6AE92DAB59AD9B092D7AC8DD7A988D7A885A772
            4DDBD7D7969696FF00FFFF00FFD2D2D2E2E0DFA7724DA7724DA7724DA7724DA7
            724DA7724DA7724DA7724DA7724DA7724DDCD9D89D9D9DFF00FFFF00FFD5D5D5
            F1EFEFE3E1DFE2E0DFE2DFDFE2DFDEE1DEDEE1DEDDE0DDDCDFDCDCDFDCDBDEDB
            DBEEECECA3A3A3FF00FFFF00FFD8D8D8D6D6D6D4D4D4D1D1D1CECECECACACAC7
            C7C7C3C3C3BFBFBFBBBBBBB7B7B7B2B2B2AEAEAEA9A9A9FF00FF}
          TabOrder = 0
          OnClick = sbPreviewClick
        end
        object cbAutoRefresh: TCheckBox
          Left = 16
          Top = 59
          Width = 159
          Height = 17
          TabOrder = 1
        end
      end
      object cbCSVTitles: TAdvSmoothSlider
        Left = 99
        Top = 51
        Width = 77
        Height = 23
        AppearanceOn.Fill.Color = 39423
        AppearanceOn.Fill.ColorTo = 52479
        AppearanceOn.Fill.ColorMirror = clNone
        AppearanceOn.Fill.ColorMirrorTo = clNone
        AppearanceOn.Fill.GradientType = gtVertical
        AppearanceOn.Fill.GradientMirrorType = gtSolid
        AppearanceOn.Fill.BorderColor = clNone
        AppearanceOn.Fill.Rounding = 3
        AppearanceOn.Fill.RoundingType = rtLeft
        AppearanceOn.Fill.ShadowOffset = 0
        AppearanceOn.Fill.Glow = gmNone
        AppearanceOn.FillDisabled.Color = 14474460
        AppearanceOn.FillDisabled.ColorMirror = clNone
        AppearanceOn.FillDisabled.ColorMirrorTo = clNone
        AppearanceOn.FillDisabled.GradientType = gtVertical
        AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
        AppearanceOn.FillDisabled.BorderColor = clNone
        AppearanceOn.FillDisabled.Rounding = 0
        AppearanceOn.FillDisabled.ShadowOffset = 0
        AppearanceOn.FillDisabled.Glow = gmNone
        AppearanceOn.Caption = '|'
        AppearanceOn.Font.Charset = DEFAULT_CHARSET
        AppearanceOn.Font.Color = clBlack
        AppearanceOn.Font.Height = -13
        AppearanceOn.Font.Name = 'Tahoma'
        AppearanceOn.Font.Style = [fsBold]
        AppearanceOff.Fill.Color = 15461355
        AppearanceOff.Fill.ColorTo = clWhite
        AppearanceOff.Fill.ColorMirror = clNone
        AppearanceOff.Fill.ColorMirrorTo = clNone
        AppearanceOff.Fill.GradientType = gtVertical
        AppearanceOff.Fill.GradientMirrorType = gtSolid
        AppearanceOff.Fill.BorderColor = clNone
        AppearanceOff.Fill.Rounding = 5
        AppearanceOff.Fill.RoundingType = rtRight
        AppearanceOff.Fill.ShadowOffset = 0
        AppearanceOff.Fill.Glow = gmNone
        AppearanceOff.FillDisabled.Color = 14474460
        AppearanceOff.FillDisabled.ColorMirror = clNone
        AppearanceOff.FillDisabled.ColorMirrorTo = clNone
        AppearanceOff.FillDisabled.GradientType = gtVertical
        AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
        AppearanceOff.FillDisabled.BorderColor = clNone
        AppearanceOff.FillDisabled.Rounding = 0
        AppearanceOff.FillDisabled.ShadowOffset = 0
        AppearanceOff.FillDisabled.Glow = gmNone
        AppearanceOff.Caption = 'O'
        AppearanceOff.Font.Charset = DEFAULT_CHARSET
        AppearanceOff.Font.Color = clBlack
        AppearanceOff.Font.Height = -13
        AppearanceOff.Font.Name = 'Tahoma'
        AppearanceOff.Font.Style = [fsBold]
        ButtonAppearance.Fill.Color = 15263976
        ButtonAppearance.Fill.ColorTo = clSilver
        ButtonAppearance.Fill.ColorMirror = clNone
        ButtonAppearance.Fill.ColorMirrorTo = clNone
        ButtonAppearance.Fill.GradientType = gtVertical
        ButtonAppearance.Fill.GradientMirrorType = gtSolid
        ButtonAppearance.Fill.BorderColor = 10066329
        ButtonAppearance.Fill.Rounding = 3
        ButtonAppearance.Fill.ShadowOffset = 0
        ButtonAppearance.Fill.Glow = gmNone
        ButtonAppearance.FillDisabled.Color = 14474460
        ButtonAppearance.FillDisabled.ColorMirror = clNone
        ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
        ButtonAppearance.FillDisabled.GradientType = gtVertical
        ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
        ButtonAppearance.FillDisabled.BorderColor = clNone
        ButtonAppearance.FillDisabled.Rounding = 0
        ButtonAppearance.FillDisabled.ShadowOffset = 0
        ButtonAppearance.FillDisabled.Glow = gmNone
        ButtonAppearance.Size = 35
        Fill.Color = clWhite
        Fill.ColorTo = clWhite
        Fill.ColorMirror = clNone
        Fill.ColorMirrorTo = clNone
        Fill.GradientType = gtVertical
        Fill.GradientMirrorType = gtSolid
        Fill.Opacity = 135
        Fill.OpacityTo = 160
        Fill.BorderColor = clSilver
        Fill.Rounding = 3
        Fill.ShadowOffset = 0
        Fill.Glow = gmNone
        FillDisabled.Color = 14474460
        FillDisabled.ColorTo = 11974326
        FillDisabled.ColorMirror = clNone
        FillDisabled.ColorMirrorTo = clNone
        FillDisabled.GradientType = gtVertical
        FillDisabled.GradientMirrorType = gtSolid
        FillDisabled.BorderColor = clNone
        FillDisabled.Rounding = 0
        FillDisabled.ShadowOffset = 0
        FillDisabled.Glow = gmNone
        OnStateChanged = cbCSVTitlesStateChanged
        TabOrder = 1
        TMSStyle = 0
      end
      object cbCSVSeparator: TComboBox
        Left = 99
        Top = 81
        Width = 230
        Height = 21
        Style = csDropDownList
        TabOrder = 2
        OnChange = cbCSVSeparatorChange
      end
      object cbCSVData: TComboBox
        Left = 99
        Top = 108
        Width = 230
        Height = 21
        Style = csDropDownList
        TabOrder = 3
        OnChange = cbCSVSeparatorChange
      end
      object cbCSVUnits: TComboBox
        Left = 99
        Top = 135
        Width = 230
        Height = 21
        Style = csDropDownList
        TabOrder = 4
        OnChange = cbCSVSeparatorChange
      end
      object cbCSVAutoOpen: TAdvSmoothSlider
        Left = 99
        Top = 174
        Width = 77
        Height = 23
        AppearanceOn.Fill.Color = 39423
        AppearanceOn.Fill.ColorTo = 52479
        AppearanceOn.Fill.ColorMirror = clNone
        AppearanceOn.Fill.ColorMirrorTo = clNone
        AppearanceOn.Fill.GradientType = gtVertical
        AppearanceOn.Fill.GradientMirrorType = gtSolid
        AppearanceOn.Fill.BorderColor = clNone
        AppearanceOn.Fill.Rounding = 3
        AppearanceOn.Fill.RoundingType = rtLeft
        AppearanceOn.Fill.ShadowOffset = 0
        AppearanceOn.Fill.Glow = gmNone
        AppearanceOn.FillDisabled.Color = 14474460
        AppearanceOn.FillDisabled.ColorMirror = clNone
        AppearanceOn.FillDisabled.ColorMirrorTo = clNone
        AppearanceOn.FillDisabled.GradientType = gtVertical
        AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
        AppearanceOn.FillDisabled.BorderColor = clNone
        AppearanceOn.FillDisabled.Rounding = 0
        AppearanceOn.FillDisabled.ShadowOffset = 0
        AppearanceOn.FillDisabled.Glow = gmNone
        AppearanceOn.Caption = '|'
        AppearanceOn.Font.Charset = DEFAULT_CHARSET
        AppearanceOn.Font.Color = clBlack
        AppearanceOn.Font.Height = -13
        AppearanceOn.Font.Name = 'Tahoma'
        AppearanceOn.Font.Style = [fsBold]
        AppearanceOff.Fill.Color = 15461355
        AppearanceOff.Fill.ColorTo = clWhite
        AppearanceOff.Fill.ColorMirror = clNone
        AppearanceOff.Fill.ColorMirrorTo = clNone
        AppearanceOff.Fill.GradientType = gtVertical
        AppearanceOff.Fill.GradientMirrorType = gtSolid
        AppearanceOff.Fill.BorderColor = clNone
        AppearanceOff.Fill.Rounding = 5
        AppearanceOff.Fill.RoundingType = rtRight
        AppearanceOff.Fill.ShadowOffset = 0
        AppearanceOff.Fill.Glow = gmNone
        AppearanceOff.FillDisabled.Color = 14474460
        AppearanceOff.FillDisabled.ColorMirror = clNone
        AppearanceOff.FillDisabled.ColorMirrorTo = clNone
        AppearanceOff.FillDisabled.GradientType = gtVertical
        AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
        AppearanceOff.FillDisabled.BorderColor = clNone
        AppearanceOff.FillDisabled.Rounding = 0
        AppearanceOff.FillDisabled.ShadowOffset = 0
        AppearanceOff.FillDisabled.Glow = gmNone
        AppearanceOff.Caption = 'O'
        AppearanceOff.Font.Charset = DEFAULT_CHARSET
        AppearanceOff.Font.Color = clBlack
        AppearanceOff.Font.Height = -13
        AppearanceOff.Font.Name = 'Tahoma'
        AppearanceOff.Font.Style = [fsBold]
        ButtonAppearance.Fill.Color = 15263976
        ButtonAppearance.Fill.ColorTo = clSilver
        ButtonAppearance.Fill.ColorMirror = clNone
        ButtonAppearance.Fill.ColorMirrorTo = clNone
        ButtonAppearance.Fill.GradientType = gtVertical
        ButtonAppearance.Fill.GradientMirrorType = gtSolid
        ButtonAppearance.Fill.BorderColor = 10066329
        ButtonAppearance.Fill.Rounding = 3
        ButtonAppearance.Fill.ShadowOffset = 0
        ButtonAppearance.Fill.Glow = gmNone
        ButtonAppearance.FillDisabled.Color = 14474460
        ButtonAppearance.FillDisabled.ColorMirror = clNone
        ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
        ButtonAppearance.FillDisabled.GradientType = gtVertical
        ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
        ButtonAppearance.FillDisabled.BorderColor = clNone
        ButtonAppearance.FillDisabled.Rounding = 0
        ButtonAppearance.FillDisabled.ShadowOffset = 0
        ButtonAppearance.FillDisabled.Glow = gmNone
        ButtonAppearance.Size = 35
        Fill.Color = clWhite
        Fill.ColorTo = clWhite
        Fill.ColorMirror = clNone
        Fill.ColorMirrorTo = clNone
        Fill.GradientType = gtVertical
        Fill.GradientMirrorType = gtSolid
        Fill.Opacity = 135
        Fill.OpacityTo = 160
        Fill.BorderColor = clSilver
        Fill.Rounding = 3
        Fill.ShadowOffset = 0
        Fill.Glow = gmNone
        FillDisabled.Color = 14474460
        FillDisabled.ColorTo = 11974326
        FillDisabled.ColorMirror = clNone
        FillDisabled.ColorMirrorTo = clNone
        FillDisabled.GradientType = gtVertical
        FillDisabled.GradientMirrorType = gtSolid
        FillDisabled.BorderColor = clNone
        FillDisabled.Rounding = 0
        FillDisabled.ShadowOffset = 0
        FillDisabled.Glow = gmNone
        OnStateChanged = cbCSVTitlesStateChanged
        TabOrder = 5
        TMSStyle = 0
      end
    end
  end
  object Memo1: TMemo
    Left = 553
    Top = 0
    Width = 405
    Height = 416
    Align = alClient
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 1
  end
end
