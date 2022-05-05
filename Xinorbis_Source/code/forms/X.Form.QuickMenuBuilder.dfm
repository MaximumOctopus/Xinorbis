object frmQuickMenuBuilder: TfrmQuickMenuBuilder
  Left = 0
  Top = 0
  Caption = 'Quick Menu builder'
  ClientHeight = 560
  ClientWidth = 859
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnConstrainedResize = FormConstrainedResize
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object mMain: TMemo
    Left = 235
    Top = 0
    Width = 624
    Height = 560
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 235
    Height = 560
    Align = alLeft
    Color = clWhite
    ParentBackground = False
    TabOrder = 1
    object SpeedButton1: TSpeedButton
      Left = 8
      Top = 8
      Width = 107
      Height = 22
      Caption = 'Open Menu'
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
      OnClick = SpeedButton1Click
    end
    object SpeedButton3: TSpeedButton
      Left = 8
      Top = 36
      Width = 107
      Height = 22
      Caption = 'Save...'
      OnClick = SpeedButton3Click
    end
    object SpeedButton4: TSpeedButton
      Left = 121
      Top = 36
      Width = 108
      Height = 22
      Caption = 'Save As...'
      OnClick = SpeedButton4Click
    end
    object sbTest: TSpeedButton
      Left = 8
      Top = 64
      Width = 221
      Height = 22
      Caption = 'Test'
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFB1E0F2FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFABD2
        EDFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF32B0DF30ADDE87CEEBFF00FFFF
        00FFFF00FFFF00FF9ACDEB2290D30D81CCFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF44B8E350CBEF39B7E52AA9DD73C5E782CAEA269ED92AA3DD39AEE5198C
        D1FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF5BC3E74DCAEE54CEF150C8EF40
        BAE839B5E546BDEB44BAEB3EB3E82C9AD6FF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF7AD0EC49C8EC49CCF131C3ED42C4EE46C3ED2CB6EA26B1E83CB4E746AB
        DDFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9BDCF144C6EA57D2F227C2ED23
        BDEC1FB7EA1BB3E936B9EA3AB3E667BDE4FF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF46C2E659D5F246D0F229C4EE25C0ED22BBEB1DB6E921B4E946BDEB2AA7
        DBFF00FFFF00FFFF00FFFF00FFFF00FF4DC8E94ACEED5EDBF530CDF12CC8EF27
        C3EE24BEEC20B8EA1CB4E949C0EC37B2E42DA8DDFF00FFFF00FFFF00FF54CEEB
        4CD2EE63E1F641D6F432CFF22ECBF02AC6EF26C1ED22BCEB1FB7EA20B4E947BE
        EC36B2E432ABDDFF00FF5ED3EE4DD5EF58DCF25EDEF560DEF55FDCF648D4F32D
        C9EF29C4EE35C4ED50C9EF4CC4EE45BEEB3DB7E733B0E236ADDEFF00FFB6EBF7
        7FDCF15BD0ED42C7E949CEED5BD9F447D3F23ACBF055CFF13EBFE835B7E24BBC
        E46EC8E9A3DBF1FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9CE2F349CEED5D
        D9F459D6F343C5EA79D1EDFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF47CAEA56D6F259D6F33AC0E6FF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFBCECF748
        CEED48CDED9BE0F3FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FF58D1EC47CBEAFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFD8
        F5FBC1EEF8FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      OnClick = sbTestClick
    end
    object bClear: TSpeedButton
      Left = 121
      Top = 8
      Width = 108
      Height = 22
      Caption = 'Clear'
      OnClick = bClearClick
    end
    object AdvNavBar1: TAdvNavBar
      Left = 1
      Top = 96
      Width = 233
      Height = 463
      Align = alBottom
      Anchors = [akLeft, akTop, akRight, akBottom]
      Color = clWhite
      ActiveColor = 16645114
      ActiveColorTo = 16643051
      ActiveTabIndex = 2
      BorderColor = 13542013
      CaptionColor = 16575452
      CaptionColorTo = 16571329
      CaptionFont.Charset = DEFAULT_CHARSET
      CaptionFont.Color = clBlack
      CaptionFont.Height = -15
      CaptionFont.Name = 'Tahoma'
      CaptionFont.Style = [fsBold]
      CollapsedCaption = 'Collapsed'
      DefaultGradientDirection = gdVertical
      DefaultTabColorTo = clWhite
      DownTabColor = 16575452
      DownTabColorTo = 16571329
      DownTabMirrorColor = clNone
      DownTabMirrorColorTo = clNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      HoverTabColor = 16645114
      HoverTabColorTo = 16643051
      HoverTabMirrorColor = clNone
      HoverTabMirrorColorTo = clNone
      SectionColor = 16645114
      SectionColorTo = 16643051
      SectionFont.Charset = DEFAULT_CHARSET
      SectionFont.Color = clWindowText
      SectionFont.Height = -11
      SectionFont.Name = 'Tahoma'
      SectionFont.Style = []
      ShowHint = True
      SplitterPosition = 5
      SplitterColor = 16575452
      SplitterColorTo = 16571329
      Style = esWindows7
      Version = '2.1.2.2'
      object AdvNavBarPanel1: TAdvNavBarPanel
        Left = 1
        Top = 27
        Width = 231
        Height = 213
        Caption = 'Attributes'
        CaptionStyle = []
        Color = clWhite
        PanelIndex = 1
        Sections = <>
        object SpeedButton29: TSpeedButton
          Tag = 2
          Left = 8
          Top = 44
          Width = 105
          Height = 22
          Caption = 'Hidden'
          OnClick = SpeedButton33Click
        end
        object SpeedButton33: TSpeedButton
          Left = 8
          Top = 16
          Width = 105
          Height = 22
          Caption = 'Archive'
          OnClick = SpeedButton33Click
        end
        object SpeedButton34: TSpeedButton
          Tag = 3
          Left = 118
          Top = 44
          Width = 105
          Height = 22
          Caption = 'Readonly'
          OnClick = SpeedButton33Click
        end
        object SpeedButton32: TSpeedButton
          Tag = 1
          Left = 118
          Top = 16
          Width = 105
          Height = 22
          Caption = 'System'
          OnClick = SpeedButton33Click
        end
      end
      object AdvNavBarPanel5: TAdvNavBarPanel
        Left = 1
        Top = 27
        Width = 231
        Height = 213
        Caption = 'Dates'
        CaptionStyle = []
        Color = clWhite
        PanelIndex = 0
        Sections = <>
        object SpeedButton7: TSpeedButton
          Tag = 1
          Left = 119
          Top = 48
          Width = 105
          Height = 22
          Caption = 'Yesterday'
          OnClick = SpeedButton38Click
        end
        object SpeedButton36: TSpeedButton
          Tag = 3
          Left = 119
          Top = 76
          Width = 105
          Height = 22
          Caption = 'This Month'
          OnClick = SpeedButton38Click
        end
        object SpeedButton37: TSpeedButton
          Tag = 2
          Left = 9
          Top = 76
          Width = 105
          Height = 22
          Caption = 'This Week'
          OnClick = SpeedButton38Click
        end
        object SpeedButton38: TSpeedButton
          Left = 9
          Top = 48
          Width = 105
          Height = 22
          Caption = 'Today'
          OnClick = SpeedButton38Click
        end
        object SpeedButton39: TSpeedButton
          Tag = 4
          Left = 9
          Top = 104
          Width = 105
          Height = 22
          Caption = 'Last 6 Months'
          OnClick = SpeedButton38Click
        end
        object SpeedButton42: TSpeedButton
          Tag = 5
          Left = 119
          Top = 104
          Width = 105
          Height = 22
          Caption = 'Last Year'
          OnClick = SpeedButton38Click
        end
        object rbDCreated: TRadioButton
          Left = 9
          Top = 16
          Width = 67
          Height = 17
          Caption = 'Created'
          Checked = True
          TabOrder = 0
          TabStop = True
        end
        object rbDAccessed: TRadioButton
          Left = 75
          Top = 16
          Width = 67
          Height = 17
          Caption = 'Accessed'
          TabOrder = 1
        end
        object rbDModified: TRadioButton
          Left = 148
          Top = 16
          Width = 67
          Height = 17
          Caption = 'Modified'
          TabOrder = 2
        end
      end
      object AdvNavBarPanel3: TAdvNavBarPanel
        Left = 1
        Top = 27
        Width = 231
        Height = 213
        Caption = 'Dialogs'
        CaptionStyle = []
        Color = clWhite
        PanelIndex = 3
        Sections = <>
        object SpeedButton8: TSpeedButton
          Left = 8
          Top = 16
          Width = 105
          Height = 22
          Caption = 'Created date'
          OnClick = SpeedButto8Click
        end
        object SpeedButton9: TSpeedButton
          Tag = 1
          Left = 8
          Top = 44
          Width = 105
          Height = 22
          Caption = 'Accessed date'
          OnClick = SpeedButto8Click
        end
        object SpeedButton10: TSpeedButton
          Tag = 2
          Left = 8
          Top = 72
          Width = 105
          Height = 22
          Caption = 'Modified date'
          OnClick = SpeedButto8Click
        end
        object SpeedButton11: TSpeedButton
          Tag = 10
          Left = 119
          Top = 16
          Width = 105
          Height = 22
          Caption = 'Size'
          OnClick = SpeedButto8Click
        end
        object SpeedButton35: TSpeedButton
          Tag = 20
          Left = 119
          Top = 44
          Width = 105
          Height = 22
          Caption = 'Wizard'
          OnClick = SpeedButto8Click
        end
      end
      object AdvNavBarPanel4: TAdvNavBarPanel
        Left = 1
        Top = 27
        Width = 231
        Height = 213
        Caption = 'Structure'
        CaptionStyle = []
        Color = clWhite
        PanelIndex = 4
        Sections = <>
        object SpeedButton5: TSpeedButton
          Left = 8
          Top = 16
          Width = 105
          Height = 22
          Caption = 'Separator'
          OnClick = SpeedButton5Click
        end
        object SpeedButton6: TSpeedButton
          Left = 8
          Top = 48
          Width = 104
          Height = 22
          Caption = 'Submenu template'
          OnClick = SpeedButton6Click
        end
      end
      object AdvNavBarPanel2: TAdvNavBarPanel
        Left = 1
        Top = 27
        Width = 231
        Height = 213
        Caption = 'Category'
        CaptionStyle = []
        Color = clWhite
        PanelIndex = 2
        Sections = <>
        object SpeedButton13: TSpeedButton
          Tag = 2
          Left = 82
          Top = 16
          Width = 68
          Height = 22
          Caption = 'SYS'
          OnClick = SpeedButton12Click
        end
        object SpeedButton24: TSpeedButton
          Tag = 15
          Left = 8
          Top = 144
          Width = 41
          Height = 22
          Caption = 'C6'
          OnClick = SpeedButton12Click
        end
        object SpeedButton18: TSpeedButton
          Tag = 10
          Left = 8
          Top = 116
          Width = 41
          Height = 22
          Caption = 'C1'
          OnClick = SpeedButton12Click
        end
        object SpeedButton19: TSpeedButton
          Tag = 11
          Left = 52
          Top = 116
          Width = 41
          Height = 22
          Caption = 'C2'
          OnClick = SpeedButton12Click
        end
        object SpeedButton25: TSpeedButton
          Tag = 16
          Left = 52
          Top = 144
          Width = 41
          Height = 22
          Caption = 'C7'
          OnClick = SpeedButton12Click
        end
        object SpeedButton26: TSpeedButton
          Tag = 17
          Left = 95
          Top = 144
          Width = 41
          Height = 22
          Caption = 'C8'
          OnClick = SpeedButton12Click
        end
        object SpeedButton20: TSpeedButton
          Tag = 12
          Left = 95
          Top = 116
          Width = 41
          Height = 22
          Caption = 'C3'
          OnClick = SpeedButton12Click
        end
        object SpeedButton30: TSpeedButton
          Tag = 13
          Left = 139
          Top = 116
          Width = 41
          Height = 22
          Caption = 'C4'
          OnClick = SpeedButton12Click
        end
        object SpeedButton27: TSpeedButton
          Tag = 18
          Left = 139
          Top = 144
          Width = 41
          Height = 22
          Caption = 'C9'
          OnClick = SpeedButton12Click
        end
        object SpeedButton28: TSpeedButton
          Tag = 19
          Left = 183
          Top = 144
          Width = 41
          Height = 22
          Caption = 'C10'
          OnClick = SpeedButton12Click
        end
        object SpeedButton31: TSpeedButton
          Tag = 14
          Left = 183
          Top = 116
          Width = 41
          Height = 22
          Caption = 'C5'
          OnClick = SpeedButton12Click
        end
        object SpeedButton23: TSpeedButton
          Tag = 9
          Left = 156
          Top = 72
          Width = 68
          Height = 22
          Caption = 'OTH'
          OnClick = SpeedButton12Click
        end
        object SpeedButton16: TSpeedButton
          Tag = 5
          Left = 82
          Top = 44
          Width = 68
          Height = 22
          Caption = 'SOUND'
          OnClick = SpeedButton12Click
        end
        object SpeedButton21: TSpeedButton
          Tag = 7
          Left = 8
          Top = 72
          Width = 68
          Height = 22
          Caption = 'COD'
          OnClick = SpeedButton12Click
        end
        object SpeedButton22: TSpeedButton
          Tag = 8
          Left = 82
          Top = 72
          Width = 68
          Height = 22
          Caption = 'COM'
          OnClick = SpeedButton12Click
        end
        object SpeedButton15: TSpeedButton
          Tag = 4
          Left = 8
          Top = 44
          Width = 68
          Height = 22
          Caption = 'MOV'
          OnClick = SpeedButton12Click
        end
        object SpeedButton17: TSpeedButton
          Tag = 6
          Left = 156
          Top = 44
          Width = 68
          Height = 22
          Caption = 'OFF'
          OnClick = SpeedButton12Click
        end
        object SpeedButton14: TSpeedButton
          Tag = 3
          Left = 156
          Top = 16
          Width = 68
          Height = 22
          Caption = 'GFX'
          OnClick = SpeedButton12Click
        end
        object SpeedButton12: TSpeedButton
          Tag = 1
          Left = 8
          Top = 16
          Width = 68
          Height = 22
          Caption = 'PROG'
          OnClick = SpeedButton12Click
        end
      end
    end
  end
  object odMain: TOpenDialog
    Filter = 'Xinorbis Menu Files (*.menu)|*.menu'
    Left = 488
    Top = 32
  end
  object puTest: TPopupMenu
    Left = 432
    Top = 32
  end
  object sdMain: TSaveDialog
    Filter = 'Xinorbis Menu Files (*.menu)|*.menu'
    Left = 600
    Top = 40
  end
end
