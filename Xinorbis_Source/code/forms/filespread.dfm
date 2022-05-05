object frmSpread: TfrmSpread
  Left = 491
  Top = 258
  BorderIcons = [biSystemMenu]
  ClientHeight = 504
  ClientWidth = 812
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 174
    Height = 504
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
        18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFF874480833F7E7F387D7C337C792E7BC63A13C63712C4
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
        8185FE7C81FEACAFFED97B39EAB28AE49F6EE39C6AE7A87DD1621AFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFF7478FEB8BBFEB6B9FEB3B6FEB0B3FEDF8445ECB792E6
        A578E6A273E9AD85D66B1EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7478FE7478FE
        7276FE6E71FD6A6CFCE18D52EDBB99E9AC81E7A87CEAB38DD8742CFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE2925CEEC1A0EA
        B189E9AE85EDB794DB7C3AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFE69B67F0C5A6ECB691EBB38CEEBC9BDF8547FFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8A070F2C8ACF0
        C6A8F0C5A6EFC2A2E18E53FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFEAA677E8A474E8A06EE69D6BE49965E2955EFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      TabOrder = 0
      OnClick = bGoClick
    end
    object GroupBox1: TGroupBox
      Left = 6
      Top = 280
      Width = 161
      Height = 65
      Caption = 'Chart'
      TabOrder = 1
      object rbCMulti: TAdvOfficeRadioButton
        Left = 12
        Top = 18
        Width = 135
        Height = 20
        TabOrder = 0
        OnClick = rbCMultiClick
        Alignment = taLeftJustify
        Caption = 'Multi-coloured'
        Checked = True
        Down = True
        ReturnIsTab = False
        Version = '1.4.1.1'
      end
      object rbCGradient: TAdvOfficeRadioButton
        Left = 12
        Top = 38
        Width = 135
        Height = 20
        TabOrder = 1
        OnClick = rbCMultiClick
        Alignment = taLeftJustify
        Caption = 'Gradient'
        ReturnIsTab = False
        Version = '1.4.1.1'
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
        TabOrder = 0
        OnClick = cbLogClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.4.1.1'
      end
    end
    object bHelp: TBitBtn
      Left = 6
      Top = 433
      Width = 161
      Height = 25
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4ECE5D6BAA2B6845AAC
        7445AB7243B27E53D2B59CF2EAE3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFE7D5C6BA895FD7BBA3E9DACAECE0D1ECE0D1E8D8C8D3B59CB07A4DE2CF
        BEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEAD9CBBE8C62E7D5C4E5D2BFC9A685B8
        8E67B68A65C5A180E0CCBAE3D0BEAF7648E3D0C0FFFFFFFFFFFFFFFFFFF7F1EC
        C99D79EAD8C9E3CDBAC0946BBA8C62CFB094CFB094B7895FB28761DAC0AAE4D1
        C0B68359F4ECE6FFFFFFFFFFFFE6CFBCE4CCB9EAD6C5C79971BF9066BF9066F7
        F1ECF6F0EAB7895FB7895FB58963E2CEBBD9BDA6D9BEA7FFFFFFFFFFFFD9B395
        EFE1D3D9B595C7986CC39569C19367BF9066BF9066BB8B63B98A63B88A62CBA7
        86EADCCCC2956FFFFFFFFFFFFFDAB393F2E4D9D1A57AC5996BC4976AC49669FA
        F6F2F3EAE1C2956DBE8F65BE8F64C0956DEFE3D5C19067FFFFFFFFFFFFE1BB9D
        F2E5DAD1A67ECC9D71C79A6CC5986BE2CCB6F8F3EEF6EEE8D9BDA1C29468C59B
        71F0E2D6C79971FFFFFFFFFFFFEACAB0F3E5D9DFBB9ECFA075CD9E72F5EBE3E4
        CBB4E7D3BFFBF8F6E5D3BFC4986BD6B491EEE0D2D3AC8BFFFFFFFFFFFFF5E4D6
        F4E3D4EFDCCDD5A87ED0A077FBF8F5FCF8F5FCF8F5FBF8F5D1A881CFA47BEAD5
        C3EAD4C2E9D4C2FFFFFFFFFFFFFDF9F5F1D3BBF6E9DDECD8C6D7AC81DCBB9AF6
        ECE3F5ECE2E4C8AED2A77BE6CEBAF1E2D5DFBB9CFAF4F0FFFFFFFFFFFFFFFFFF
        FBF1E9F3D4BBF7EADFEEDED0E3C1A7D8AE89D7AC86DDBB9CEBD6C7F3E6D9E4C1
        A3F5E9DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCF2EAF6DAC3F9E9DCF6E8DDF3
        E5DAF3E5DAF5E7DCF5E4D6EDCDB4F8ECE3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFEFAF7FCEDE1F8DEC9F6D9C1F5D7BFF5D9C3F8E8DCFDF8F5FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
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
        Left = 13
        Top = 20
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
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clWhite
      Fill.ColorMirrorTo = clWhite
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtVertical
      Fill.BorderColor = 13542013
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
        PageAppearance.Color = 16575452
        PageAppearance.ColorTo = 16571329
        PageAppearance.ColorMirror = clNone
        PageAppearance.ColorMirrorTo = clNone
        PageAppearance.GradientType = gtVertical
        PageAppearance.GradientMirrorType = gtVertical
        PageAppearance.BorderColor = 13542013
        PageAppearance.Rounding = 0
        PageAppearance.ShadowOffset = 0
        PageAppearance.Glow = gmNone
        TabAppearance.Appearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Appearance.Font.Color = clBlack
        TabAppearance.Appearance.Font.Height = -11
        TabAppearance.Appearance.Font.Name = 'Tahoma'
        TabAppearance.Appearance.Font.Style = []
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
        TabAppearance.BevelColor = 13542013
        TabAppearance.BevelColorDown = 16645114
        TabAppearance.BevelColorSelected = 16645114
        TabAppearance.BevelColorHot = 16645114
        TabAppearance.BevelColorDisabled = 16645114
        TabAppearance.Color = 16575452
        TabAppearance.ColorDown = 16575452
        TabAppearance.ColorSelected = 16575452
        TabAppearance.ColorDisabled = 16765357
        TMSStyle = 11
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
          TabOrder = 2
          OnClick = cbUsersChange
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
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
      object AdvSmoothTabPager13: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 159
        Height = 176
        Caption = 'Benford'#39's Law'
        PageAppearance.Color = 16575452
        PageAppearance.ColorTo = 16571329
        PageAppearance.ColorMirror = clNone
        PageAppearance.ColorMirrorTo = clNone
        PageAppearance.GradientType = gtVertical
        PageAppearance.GradientMirrorType = gtVertical
        PageAppearance.BorderColor = 13542013
        PageAppearance.Rounding = 0
        PageAppearance.ShadowOffset = 0
        PageAppearance.Glow = gmNone
        TabAppearance.Appearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Appearance.Font.Color = clBlack
        TabAppearance.Appearance.Font.Height = -11
        TabAppearance.Appearance.Font.Name = 'Tahoma'
        TabAppearance.Appearance.Font.Style = []
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
        TabAppearance.BevelColor = 13542013
        TabAppearance.BevelColorDown = 16645114
        TabAppearance.BevelColorSelected = 16645114
        TabAppearance.BevelColorHot = 16645114
        TabAppearance.BevelColorDisabled = 16645114
        TabAppearance.Color = 16575452
        TabAppearance.ColorDown = 16575452
        TabAppearance.ColorSelected = 16575452
        TabAppearance.ColorDisabled = 16765357
        TMSStyle = 11
        object Label1: TLabel
          Left = 38
          Top = 152
          Width = 78
          Height = 13
          Cursor = crHandPoint
          Caption = 'More information'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          OnClick = Label1Click
        end
        object cbBLNormal: TAdvOfficeCheckBox
          Left = 11
          Top = 8
          Width = 135
          Height = 20
          TabOrder = 0
          OnClick = cbBLNormalClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
        end
      end
    end
    object cbAutoRefresh: TAdvOfficeCheckBox
      Left = 6
      Top = 459
      Width = 162
      Height = 20
      Checked = True
      TabOrder = 6
      Alignment = taLeftJustify
      Caption = '.'
      ReturnIsTab = False
      State = cbChecked
      Version = '1.4.1.1'
    end
  end
  object Panel2: TPanel
    Left = 174
    Top = 0
    Width = 638
    Height = 504
    Align = alClient
    BevelOuter = bvNone
    Caption = 'Panel2'
    TabOrder = 1
    object vtcSpread: TChart
      Left = 0
      Top = 0
      Width = 638
      Height = 480
      BackWall.Brush.Style = bsClear
      Gradient.EndColor = clWhite
      Gradient.StartColor = 15724527
      Gradient.Visible = True
      LeftWall.Color = clWhite
      Legend.Visible = False
      Title.AutoSize = False
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
      RightAxis.Automatic = False
      RightAxis.AutomaticMaximum = False
      RightAxis.AutomaticMinimum = False
      Zoom.Allow = False
      Align = alClient
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
      Top = 480
      Width = 638
      Height = 24
      Align = alBottom
      BevelEdges = []
      BevelOuter = bvNone
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      DesignSize = (
        638
        24)
      object lData: THTMLabel
        Left = 6
        Top = 6
        Width = 626
        Height = 17
        Anchors = [akLeft, akTop, akRight]
        HTMLText.Strings = (
          '...')
        Transparent = True
        Version = '1.9.2.6'
        ExplicitWidth = 624
      end
    end
  end
  object puChart: TPopupMenu
    Left = 402
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
  object sdFSS: TSaveDialog
    DefaultExt = '.jpg'
    Filter = 'JPEG Image files (*.jpg)|*.jpg'
    Left = 370
    Top = 9
  end
end
