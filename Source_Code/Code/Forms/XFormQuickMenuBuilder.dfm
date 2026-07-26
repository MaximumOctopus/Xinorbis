object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Form9'
  ClientHeight = 626
  ClientWidth = 1131
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  OnConstrainedResize = FormConstrainedResize
  OnCreate = FormCreate
  TextHeight = 15
  object mMain: TMemo
    Left = 235
    Top = 0
    Width = 896
    Height = 626
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
    Height = 626
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
    object PageControl1: TPageControl
      Left = 8
      Top = 92
      Width = 221
      Height = 517
      ActivePage = TabSheet1
      MultiLine = True
      TabOrder = 0
      TabPosition = tpLeft
      object TabSheet1: TTabSheet
        Caption = 'Category'
        object sbCatProg: TSpeedButton
          Left = 3
          Top = 3
          Width = 184
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatSys: TSpeedButton
          Left = 3
          Top = 31
          Width = 184
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatGFX: TSpeedButton
          Left = 3
          Top = 59
          Width = 184
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatMov: TSpeedButton
          Left = 3
          Top = 87
          Width = 184
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatSound: TSpeedButton
          Left = 3
          Top = 115
          Width = 184
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatOff: TSpeedButton
          Left = 3
          Top = 143
          Width = 184
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatCod: TSpeedButton
          Left = 3
          Top = 171
          Width = 184
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatCom: TSpeedButton
          Left = 3
          Top = 199
          Width = 184
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatOther: TSpeedButton
          Left = 3
          Top = 227
          Width = 184
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC1: TSpeedButton
          Left = 5
          Top = 290
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC2: TSpeedButton
          Left = 99
          Top = 290
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC4: TSpeedButton
          Left = 99
          Top = 318
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC3: TSpeedButton
          Left = 5
          Top = 318
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC5: TSpeedButton
          Left = 5
          Top = 346
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC6: TSpeedButton
          Left = 99
          Top = 346
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC8: TSpeedButton
          Left = 99
          Top = 374
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC7: TSpeedButton
          Left = 5
          Top = 374
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC10: TSpeedButton
          Left = 99
          Top = 402
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
        object sbCatC9: TSpeedButton
          Left = 5
          Top = 402
          Width = 88
          Height = 22
          OnClick = sbCatProgClick
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Structure'
        ImageIndex = 1
        object sbSeparator: TSpeedButton
          Left = 3
          Top = 15
          Width = 184
          Height = 22
          OnClick = sbSeparatorClick
        end
        object sbSubMenuTemplate: TSpeedButton
          Tag = 1
          Left = 3
          Top = 43
          Width = 184
          Height = 22
          OnClick = sbSeparatorClick
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'Dialogs'
        ImageIndex = 2
        object sbDCreatedDate: TSpeedButton
          Left = 3
          Top = 3
          Width = 184
          Height = 22
          OnClick = sbDCreatedDateClick
        end
        object sbDSize: TSpeedButton
          Left = 3
          Top = 87
          Width = 184
          Height = 22
          OnClick = sbDCreatedDateClick
        end
        object sbDAccessedDate: TSpeedButton
          Left = 3
          Top = 31
          Width = 184
          Height = 22
          OnClick = sbDCreatedDateClick
        end
        object sbDWizard: TSpeedButton
          Left = 3
          Top = 115
          Width = 184
          Height = 22
          OnClick = sbDCreatedDateClick
        end
        object sbDModifiedDate: TSpeedButton
          Left = 3
          Top = 59
          Width = 184
          Height = 22
          OnClick = sbDCreatedDateClick
        end
      end
      object TabSheet5: TTabSheet
        Caption = 'Attributes'
        ImageIndex = 4
        object sbAArchive: TSpeedButton
          Left = 3
          Top = 3
          Width = 184
          Height = 22
          OnClick = sbAArchiveClick
        end
        object sbASystem: TSpeedButton
          Left = 3
          Top = 31
          Width = 184
          Height = 22
          OnClick = sbAArchiveClick
        end
        object sbAHidden: TSpeedButton
          Left = 3
          Top = 59
          Width = 184
          Height = 22
          OnClick = sbAArchiveClick
        end
        object sbAReadOnly: TSpeedButton
          Left = 3
          Top = 87
          Width = 184
          Height = 22
          OnClick = sbAArchiveClick
        end
      end
      object TabSheet6: TTabSheet
        Caption = 'Dates'
        ImageIndex = 5
        object sbZToday: TSpeedButton
          Left = 3
          Top = 103
          Width = 184
          Height = 22
          OnClick = sbZTodayClick
        end
        object sbZYesterday: TSpeedButton
          Left = 3
          Top = 135
          Width = 184
          Height = 22
          OnClick = sbZTodayClick
        end
        object sbZThisWeek: TSpeedButton
          Left = 3
          Top = 163
          Width = 184
          Height = 22
          OnClick = sbZTodayClick
        end
        object sbZThisMonth: TSpeedButton
          Left = 3
          Top = 191
          Width = 184
          Height = 22
          OnClick = sbZTodayClick
        end
        object sbZLastSixMonths: TSpeedButton
          Left = 3
          Top = 219
          Width = 184
          Height = 22
          OnClick = sbZTodayClick
        end
        object sbZLastYear: TSpeedButton
          Left = 3
          Top = 247
          Width = 184
          Height = 22
          OnClick = sbZTodayClick
        end
        object rbZCreated: TRadioButton
          Left = 16
          Top = 16
          Width = 113
          Height = 17
          Caption = 'rbZCreated'
          TabOrder = 0
        end
        object rbZAccessed: TRadioButton
          Left = 16
          Top = 39
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 1
        end
        object rbZModified: TRadioButton
          Left = 16
          Top = 62
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 2
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
