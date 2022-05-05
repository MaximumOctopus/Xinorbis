object frmSpread: TfrmSpread
  Left = 491
  Top = 258
  BorderIcons = [biSystemMenu]
  ClientHeight = 687
  ClientWidth = 1379
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
  OnConstrainedResize = FormConstrainedResize
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 174
    Height = 687
    Align = alLeft
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 0
    object bGo: TBitBtn
      Left = 6
      Top = 401
      Width = 161
      Height = 25
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FF874480833F7E7F387D7C337C792E7BC63A13C63712C4
        3112C02E11C02A10BF270F7C4F257A4A2177461E75421B733F19413DF3999BFE
        9698FE9395FE9193FEC94315E0935DDF8F59DF8D55DE8A51C02E11A2C99E9DC6
        9998C39594C091276D2C4A47F59EA0FE5B5EFE5659FE9597FECD4C16E19763DA
        8041D97D3BDF8F58C63512A8CDA477B07170AB6A9AC4962E76335351F6A2A4FE
        6266FE5D61FE999BFECF5518E39C6CDC864ADB8344E0945EC63C13AFD1AB80B7
        7A79B273A0C89C35803C5B5BF8A8AAFE6B6FFE6569FE9EA0FED1601AE5A274DE
        8C53DD894DE29966C94515B5D5B08ABD8383B87DA7CDA33D8B446364FAACAFFE
        7276FE6D71FEA2A4FED6691EE7A77BE0925CDF8F56E49E6ECD4E16BAD9B5B7D6
        B1B3D3AEAED1A945964D6A6CFCB0B3FE797EFE7579FEA8AAFED8742AE8AD83E2
        9865E19560E5A376CF571860BC6C5CB66757B06152A85C4DA1557073FDB4B7FE
        8185FE7C81FEACAFFED97B39EAB28AE49F6EE39C6AE7A87DD1621AFF00FFFF00
        FFFF00FFFF00FFFF00FF7478FEB8BBFEB6B9FEB3B6FEB0B3FEDF8445ECB792E6
        A578E6A273E9AD85D66B1EFF00FFFF00FFFF00FFFF00FFFF00FF7478FE7478FE
        7276FE6E71FD6A6CFCE18D52EDBB99E9AC81E7A87CEAB38DD8742CFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFE2925CEEC1A0EA
        B189E9AE85EDB794DB7C3AFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFE69B67F0C5A6ECB691EBB38CEEBC9BDF8547FF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFE8A070F2C8ACF0
        C6A8F0C5A6EFC2A2E18E53FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFEAA677E8A474E8A06EE69D6BE49965E2955EFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      TabOrder = 0
      OnClick = bGoClick
    end
    object gbChart: TGroupBox
      Left = 6
      Top = 280
      Width = 161
      Height = 65
      TabOrder = 1
      object rbCMulti: TAdvOfficeRadioButton
        Left = 12
        Top = 12
        Width = 135
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = rbCMultiClick
        Alignment = taLeftJustify
        Caption = '.'
        Checked = True
        Down = True
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
      object rbCGradient: TAdvOfficeRadioButton
        Left = 12
        Top = 38
        Width = 135
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = rbCMultiClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
    object GroupBox3: TGroupBox
      Left = 6
      Top = 354
      Width = 161
      Height = 41
      TabOrder = 2
      object cbLog: TAdvOfficeCheckBox
        Left = 12
        Top = 11
        Width = 146
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = cbLogClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
    object bHelp: TBitBtn
      Left = 6
      Top = 433
      Width = 161
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
      TabOrder = 3
      OnClick = bHelpClick
    end
    object gbUsers: TGroupBox
      Left = 6
      Top = 218
      Width = 161
      Height = 46
      TabOrder = 4
      object cbUsers: TComboBox
        Left = 8
        Top = 17
        Width = 145
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = cbUsersChange
      end
    end
    object pcFS: TAdvSmoothTabPager
      Left = 6
      Top = 4
      Width = 161
      Height = 204
      Fill.Color = 3355443
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clWhite
      Fill.ColorMirrorTo = clWhite
      Fill.GradientType = gtSolid
      Fill.GradientMirrorType = gtSolid
      Fill.BorderColor = 3355443
      Fill.BorderWidth = 0
      Fill.Rounding = 0
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      Transparent = False
      ActivePage = tsFileSize
      TabSettings.StartMargin = 4
      TabReorder = False
      OnChange = pcFSxxChange
      TabOrder = 5
      object tsFileSize: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 159
        Height = 176
        Caption = ''
        PageAppearance.Color = 3355443
        PageAppearance.ColorTo = 3355443
        PageAppearance.ColorMirror = 3355443
        PageAppearance.ColorMirrorTo = 3355443
        PageAppearance.GradientType = gtSolid
        PageAppearance.GradientMirrorType = gtSolid
        PageAppearance.BorderColor = 3355443
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
        TabAppearance.BevelColorSelected = 13542013
        TabAppearance.BevelColorDisabled = clWhite
        TabAppearance.Color = clWhite
        TabAppearance.ColorDown = clWhite
        TabAppearance.ColorSelected = clWhite
        TabAppearance.ColorDisabled = 15658734
        TMSStyle = 21
        object lBGR: TLabel
          Left = 3
          Top = 8
          Width = 3
          Height = 13
          Caption = '.'
        end
        object Label2: TLabel
          Left = 41
          Top = 122
          Width = 9
          Height = 13
          Caption = 'to'
        end
        object eCoEff: TEdit
          Left = 3
          Top = 22
          Width = 54
          Height = 21
          BiDiMode = bdLeftToRight
          ParentBiDiMode = False
          TabOrder = 0
          Text = '512'
          OnEnter = eCoEffEnter
          OnExit = eCoEffExit
          OnKeyPress = eCoEffKeyPress
        end
        object cbUnit: TComboBox
          Left = 56
          Top = 22
          Width = 97
          Height = 21
          Style = csDropDownList
          TabOrder = 1
          OnChange = cbUsersChange
        end
        object cbRange: TAdvOfficeCheckBox
          Left = 16
          Top = 70
          Width = 120
          Height = 20
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = cbUsersChange
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.5.0.9'
        end
        object eRangeFrom: TEdit
          Tag = 1
          Left = 25
          Top = 98
          Width = 41
          Height = 21
          TabOrder = 3
          Text = '0'
          OnEnter = eCoEffEnter
          OnExit = eCoEffExit
          OnKeyPress = eCoEffKeyPress
        end
        object cbRangeFrom: TComboBox
          Left = 65
          Top = 98
          Width = 81
          Height = 21
          Style = csDropDownList
          TabOrder = 4
          OnChange = cbUsersChange
        end
        object eRangeTo: TEdit
          Tag = 2
          Left = 25
          Top = 138
          Width = 41
          Height = 21
          TabOrder = 5
          Text = '512'
          OnEnter = eCoEffEnter
          OnExit = eCoEffExit
          OnKeyPress = eCoEffKeyPress
        end
        object cbRangeTo: TComboBox
          Left = 65
          Top = 138
          Width = 81
          Height = 21
          Style = csDropDownList
          TabOrder = 6
          OnChange = cbUsersChange
        end
      end
      object tsBenfordsLaw: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 159
        Height = 176
        Caption = 'Benford'#39's Law'
        PageAppearance.Color = 3355443
        PageAppearance.ColorTo = 3355443
        PageAppearance.ColorMirror = 3355443
        PageAppearance.ColorMirrorTo = 3355443
        PageAppearance.GradientType = gtSolid
        PageAppearance.GradientMirrorType = gtSolid
        PageAppearance.BorderColor = 3355443
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
        TabAppearance.BevelColorSelected = 13542013
        TabAppearance.BevelColorDisabled = clWhite
        TabAppearance.Color = clWhite
        TabAppearance.ColorDown = clWhite
        TabAppearance.ColorSelected = clWhite
        TabAppearance.ColorDisabled = 15658734
        TMSStyle = 21
        object lMoreDetail: TLabel
          Left = 3
          Top = 152
          Width = 152
          Height = 13
          Cursor = crHandPoint
          Alignment = taCenter
          AutoSize = False
          Caption = ','
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          OnClick = lMoreDetailClick
        end
        object cbBLNormal: TAdvOfficeCheckBox
          Left = 12
          Top = 3
          Width = 135
          Height = 20
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = cbBLNormalClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.5.0.9'
        end
      end
    end
    object cbAutoRefresh: TAdvOfficeCheckBox
      Left = 6
      Top = 459
      Width = 162
      Height = 20
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      Alignment = taLeftJustify
      Caption = '.'
      ReturnIsTab = False
      State = cbChecked
      Version = '1.5.0.9'
    end
    object bExportCSV: TBitBtn
      Left = 6
      Top = 527
      Width = 161
      Height = 25
      Caption = 'CSV'
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        20000000000000040000120B0000120B00000000000000000000FF00FF00E2C0
        AA00CC8D6600C0714000BC6B3600BC6B3600BC6B3600BC6A3600BC6A3600BB6A
        3500BB6A3500BB693500BD6E3B00CA8B6300E3C2AE00FF00FF00FF00FF00C57C
        4D00F8F2EB00F7ECDF00F6EBDE00F6EADE00F6EADC00F6EADC00FAF3EB00FAF3
        EB00FAF2EA00FCF7F300FCF8F400FEFEFD00C37A4D00FF00FF00FF00FF00C277
        4000F5EBDF00FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
        D100FCE4D100FCE4D100FCE4D100FDFBF800BC6B3700FF00FF00FF00FF00C37C
        4200F7EDE300FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
        D100FCE4D100FCE4D100FCE4D100FBF7F400BD6C3700FF00FF00FF00FF00C680
        4600F7F0E600FCE4D100FCE4D100E5D9C200689E700057966500599766006CA0
        7300FCE4D100FCE4D100FCE4D100FCF9F500C1743C00FF00FF00328449001A75
        33001975330019743300448A5200619B6B00BBD6C30078BB840061AB6A005796
        6400FCE2CC00FBE0C900FBE1C800FDFAF700C37A4100FF00FF00A3C8AD001B75
        33005BA06E0049965C0047905B00C7DDCD005DB6710067AE7500448D58001B75
        3300FCE2CD00FBE1CB00FBE1C900FBF7F200C7804500FF00FF00FF00FF008281
        43001F78370048915D00C7DDCD006AC0840071B68200448E5900B1C1A100FBE4
        D000FBE3CC00FADFC700FADFC600FAF2EA00C8844800FF00FF00FF00FF00C48C
        4F00619E7100C5DCCC0076C9970073BC8700438D580055936000F5E0CC00FBE1
        CC00FAE0C700F9DDC300F8DCC200FAF4ED00C8864B00FF00FF00FF00FF00718C
        5500C0D9C80082D3A3006DC18A00549563004B96600051976400679A6800F4DC
        C300F8DCC200F6DABD00F6D8BB00FAF4EF00C8874C00FF00FF0080B28E00B5D3
        BE009CDAB50074C89500549563004A935F005DA4740059A16E00509764006297
        6200E9D1B400F3D4B500F1D2B300F8F4F000C6864C00FF00FF005B9C6E00568C
        57005396660054956300A1B995008DAE83002E7F42002E7F41003A8448003682
        450090B49000F7F2EC00FBF7F300F5EFE900C3804800FF00FF00FF00FF00C88D
        5200F9F5F100FCE3CD00FBE3CE00FBE3CD00FBE2CB00F9E0C800F8DCC200F5D6
        BA00FDFBF800FCE6CD00FAE5C900E2B68400D5A88400FF00FF00FF00FF00CA92
        5A00FAF6F200FAE0C700FBE1C900FBE2C900FBE0C800F9DFC500F8DBC100F4D6
        B800FFFBF800F6D8B400E1B07D00DC966900FF00FF00FF00FF00FF00FF00D2A2
        7400F8F3ED00F8F4EE00F8F4ED00F8F3ED00F8F3ED00F8F3ED00F8F2EC00F7F2
        EC00F2E6D700E2B27D00DC986B00FF00FF00FF00FF00FF00FF00FF00FF00E8CE
        B900D7AA7C00CC945B00CA905500CA905500CA905500CA915500CB905500C98F
        5500CF9D6900DDB19000FF00FF00FF00FF00FF00FF00FF00FF00}
      TabOrder = 7
      OnClick = bExportCSVClick
    end
  end
  object Panel2: TPanel
    Left = 174
    Top = 0
    Width = 1205
    Height = 687
    Align = alClient
    BevelOuter = bvNone
    Caption = 'Panel2'
    TabOrder = 1
    object vtcSpread: TChart
      Left = 0
      Top = 0
      Width = 1205
      Height = 663
      BackWall.Brush.Style = bsClear
      Gradient.EndColor = clWhite
      Gradient.StartColor = 15724527
      LeftWall.Color = clWhite
      Legend.Visible = False
      Title.AutoSize = False
      Title.Font.Color = clWhite
      Title.Text.Strings = (
        '...')
      Title.AdjustFrame = False
      BottomAxis.Visible = False
      DepthAxis.Automatic = False
      DepthAxis.AutomaticMaximum = False
      DepthAxis.AutomaticMinimum = False
      DepthAxis.Maximum = 0.830000000000000300
      DepthAxis.Minimum = -0.169999999999999900
      DepthTopAxis.Automatic = False
      DepthTopAxis.AutomaticMaximum = False
      DepthTopAxis.AutomaticMinimum = False
      DepthTopAxis.Maximum = 0.830000000000000300
      DepthTopAxis.Minimum = -0.169999999999999900
      LeftAxis.Axis.Color = clWhite
      LeftAxis.LabelsFormat.Font.Color = clWhite
      RightAxis.Automatic = False
      RightAxis.AutomaticMaximum = False
      RightAxis.AutomaticMinimum = False
      RightAxis.Axis.Color = clWhite
      Zoom.Allow = False
      Align = alClient
      Color = 3355443
      PopupMenu = puChart
      TabOrder = 0
      OnMouseMove = vtcSpreadMouseMove
      DefaultCanvas = 'TGDIPlusCanvas'
      ColorPaletteIndex = 13
      object Series1: TBarSeries
        BarPen.Visible = False
        Marks.Visible = False
        Marks.Callout.Length = 8
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Bar'
        YValues.Order = loNone
      end
      object Series2: TBarSeries
        Active = False
        Marks.Visible = False
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Bar'
        YValues.Order = loNone
      end
    end
    object pHeader: TPanel
      Left = 0
      Top = 663
      Width = 1205
      Height = 24
      Align = alBottom
      BevelEdges = []
      BevelOuter = bvNone
      Color = 3355443
      ParentBackground = False
      TabOrder = 1
      DesignSize = (
        1205
        24)
      object lData: THTMLabel
        Left = 6
        Top = 6
        Width = 1193
        Height = 17
        Anchors = [akLeft, akTop, akRight]
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        HTMLText.Strings = (
          '...')
        ParentFont = False
        Transparent = True
        Version = '2.1.0.0'
        ExplicitWidth = 624
      end
    end
  end
  object puChart: TPopupMenu
    Left = 690
    Top = 9
    object miOptions: TMenuItem
      Caption = '.'
      Enabled = False
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object miSaveChart: TMenuItem
      Caption = '.'
      OnClick = miSaveChartClick
    end
    object miCopyToClipboard: TMenuItem
      Caption = '.'
      OnClick = miCopyToClipboardClick
    end
    object miSaveData: TMenuItem
      Caption = '.'
      OnClick = miSaveDataClick
    end
  end
end
