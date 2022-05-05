object frmCSVProcess: TfrmCSVProcess
  Left = 639
  Top = 263
  BorderStyle = bsDialog
  Caption = 'Import CSV data'
  ClientHeight = 536
  ClientWidth = 431
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 496
    Width = 417
    Height = 4
    Shape = bsTopLine
  end
  object bImport: TBitBtn
    Left = 256
    Top = 504
    Width = 81
    Height = 25
    Caption = '.'
    ModalResult = 1
    TabOrder = 0
  end
  object bCancel: TBitBtn
    Left = 344
    Top = 504
    Width = 83
    Height = 25
    Cancel = True
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
    ModalResult = 2
    TabOrder = 1
  end
  object bHelp: TBitBtn
    Left = 6
    Top = 504
    Width = 75
    Height = 25
    Caption = '.'
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
    TabOrder = 2
    OnClick = bHelpClick
  end
  object cbIFR: TCheckBox
    Left = 16
    Top = 472
    Width = 409
    Height = 17
    Caption = '.'
    TabOrder = 3
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 64
    Width = 417
    Height = 401
    TabOrder = 4
    object lContents1: TLabel
      Left = 192
      Top = 35
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents2: TLabel
      Left = 192
      Top = 60
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents3: TLabel
      Left = 192
      Top = 83
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents4: TLabel
      Left = 192
      Top = 107
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents5: TLabel
      Left = 192
      Top = 131
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents6: TLabel
      Left = 192
      Top = 155
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents7: TLabel
      Left = 192
      Top = 179
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents8: TLabel
      Left = 192
      Top = 203
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents9: TLabel
      Left = 192
      Top = 227
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents15: TLabel
      Left = 192
      Top = 371
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents14: TLabel
      Left = 192
      Top = 347
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents13: TLabel
      Left = 192
      Top = 323
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents12: TLabel
      Left = 192
      Top = 299
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents11: TLabel
      Left = 192
      Top = 275
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents10: TLabel
      Left = 192
      Top = 251
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object Label1: TLabel
      Left = 8
      Top = 14
      Width = 5
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 192
      Top = 14
      Width = 5
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object cbType1: TComboBox
      Tag = 1
      Left = 8
      Top = 32
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 0
      Visible = False
      OnChange = cbType1Change
    end
    object cbType2: TComboBox
      Tag = 1
      Left = 8
      Top = 56
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 1
      Visible = False
      OnChange = cbType1Change
    end
    object cbType3: TComboBox
      Tag = 2
      Left = 8
      Top = 80
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 2
      Visible = False
      OnChange = cbType1Change
    end
    object cbType4: TComboBox
      Tag = 3
      Left = 8
      Top = 104
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 3
      Visible = False
      OnChange = cbType1Change
    end
    object cbType5: TComboBox
      Tag = 4
      Left = 8
      Top = 128
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 4
      Visible = False
      OnChange = cbType1Change
    end
    object cbType6: TComboBox
      Tag = 5
      Left = 8
      Top = 152
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 5
      Visible = False
      OnChange = cbType1Change
    end
    object cbType7: TComboBox
      Tag = 6
      Left = 8
      Top = 176
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 6
      Visible = False
      OnChange = cbType1Change
    end
    object cbType8: TComboBox
      Tag = 7
      Left = 8
      Top = 200
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 7
      Visible = False
      OnChange = cbType1Change
    end
    object cbType9: TComboBox
      Tag = 8
      Left = 8
      Top = 224
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 8
      Visible = False
      OnChange = cbType1Change
    end
    object cbType15: TComboBox
      Tag = 14
      Left = 8
      Top = 368
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 14
      Visible = False
      OnChange = cbType1Change
    end
    object cbType13: TComboBox
      Tag = 12
      Left = 8
      Top = 320
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 12
      Visible = False
      OnChange = cbType1Change
    end
    object cbType12: TComboBox
      Tag = 11
      Left = 8
      Top = 296
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 11
      Visible = False
      OnChange = cbType1Change
    end
    object cbType11: TComboBox
      Tag = 10
      Left = 8
      Top = 272
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 10
      Visible = False
      OnChange = cbType1Change
    end
    object cbType14: TComboBox
      Tag = 13
      Left = 8
      Top = 344
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 13
      Visible = False
      OnChange = cbType1Change
    end
    object cbType10: TComboBox
      Tag = 9
      Left = 8
      Top = 248
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 9
      Visible = False
      OnChange = cbType1Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 8
    Width = 417
    Height = 49
    TabOrder = 5
    object lFilename: TLabel
      Left = 8
      Top = 24
      Width = 6
      Height = 13
      Caption = '..'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
    end
    object Label3: TLabel
      Left = 8
      Top = 8
      Width = 5
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object BitBtn1: TBitBtn
    Left = 214
    Top = 504
    Width = 35
    Height = 25
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000130B0000130B00000000000000000000FF00FF4E4E4E
      3F3F3F3F3F3F3F3F3F515251FF00FFFF00FFFF00FFFF00FF4E4E4E3F3F3F3F3F
      3F3F3F3F515251FF00FFFF00FF4E4E4E3F3F3F3F3F3F3F3F3F525252FF00FFFF
      00FFFF00FFFF00FF4E4E4E3F3F3F3F3F3F3F3F3F525252FF00FF19191A9D607F
      AF6A8FAF6A8FAF6A8F9D5F80262626FF00FFFF00FF19191A9D5F80AF6991AF69
      91AF69959D5F832626261919196C6C6C7979797979797979796C6C6C262626FF
      00FFFF00FF1919196C6C6C7979797979797A7A7A6D6D6D26262619191A9D5F6F
      E28E90FF969CBA77829D5F6F262626FF00FFFF00FF19191A9D5F71D37C8FFF96
      A0E28E949D5F72262626191919686868959595A0A0A07F7F7F686868262626FF
      00FFFF00FF191919686868888888A1A1A1969696686868262626FF00FF4E4E4E
      746B67E2A985BC9071686968FF00FFFF00FFFF00FFFF00FF606060BD8E71E2A3
      85666464515251FF00FFFF00FF4E4E4E6B6B6BA7A7A78D8D8D696969FF00FFFF
      00FFFF00FFFF00FF6060608C8C8CA2A2A2646464525252FF00FFFF00FFFF00FF
      35353565665BF9E38E999C6B747474FF00FFFF00FF676767A59768E8D88D6363
      543A3A3AFF00FFFF00FFFF00FFFF00FF353535636363D6D6D6939393747474FF
      00FFFF00FF6767678F8F8FCCCCCC6060603A3A3AFF00FFFF00FFFF00FFFF00FF
      FF00FF252525615F48DDFF917180544D4A4E888485788C54D7FA93616D582D2D
      2DFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF2525255A5A5AEAEAEA7777774B
      4B4B858585818181E7E7E76868682D2D2DFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FF505051656D51AEFF915D6E53566C4EAEFF9159664E1A1A19FF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF505050676767E8E8E868
      6868656565E8E8E86161611A1A1AFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FF7575755A8C628FFAA28FFAA2597C50888485FF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF757575818181E5
      E5E5E5E5E5727272858585FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FF3A3A3A44524F91FEDB8EFAD1494A4C3D3D3DFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF3A3A3A505050F2
      F2F2EDEDED4A4A4A3D3D3DFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FF66696783CDD77CBBCC7CBBCC7BC6D339353CFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF686868CCCCCCBC
      BCBCBCBCBCC6C6C6373737FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FF45454570A2BD81BDD672747961616480C3E26F9FBD565657FF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF454545A6A6A6C1C1C175
      7575626262C8C8C8A4A4A4565656FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FF6A6A6A6E85AD84B5E2565E653A3A3A35353550595B8EBAEA637A947474
      74FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF6A6A6A8E8E8EBEBEBE5F5F5F3A
      3A3A353535595959C4C4C47F7F7F747474FF00FFFF00FFFF00FFFF00FF2D2D2D
      60606056648C8EA0EA3A3841636462FF00FFFF00FF5757572F394891A3FF4E56
      8071706C313231FF00FFFF00FF2D2D2D6060606E6E6EB3B3B33A3A3A636363FF
      00FFFF00FF5757573C3C3CBCBCBC6161616F6F6F323232FF00FFFF00FF4D4460
      8670C6AA91FF9783E28570C658506CFF00FFFF00FF4D44608570C6A090EAA191
      FF8170C658506CFF00FFFF00FF4C4C4C8B8B8BB3B3B3A0A0A08B8B8B585858FF
      00FFFF00FF4C4C4C8B8B8BABABABB2B2B28A8A8A585858FF00FFFF00FF544460
      9370C59370C59370C59370C55F506BFF00FFFF00FF5244609070C59070C59070
      C59070C55F506BFF00FFFF00FF4C4C4C8B8B8B8B8B8B8B8B8B8B8B8B585858FF
      00FFFF00FF4C4C4C8B8B8B8B8B8B8B8B8B8B8B8B585858FF00FFFF00FF2E2E2E
      3F3F3F3F3F3F3F3F3F3F3F3F313231FF00FFFF00FF2E2E2E3F3F3F3F3F3F3F3F
      3F3F3F3F313231FF00FFFF00FF2E2E2E3F3F3F3F3F3F3F3F3F3F3F3F323232FF
      00FFFF00FF2E2E2E3F3F3F3F3F3F3F3F3F3F3F3F323232FF00FF}
    NumGlyphs = 2
    TabOrder = 6
    OnClick = BitBtn1Click
  end
end
