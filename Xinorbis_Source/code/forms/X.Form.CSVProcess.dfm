object frmCSVProcess: TfrmCSVProcess
  Left = 639
  Top = 263
  BorderStyle = bsDialog
  Caption = 'Import CSV data'
  ClientHeight = 670
  ClientWidth = 504
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 13
    Top = 629
    Width = 486
    Height = 4
    Shape = bsTopLine
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 63
    Width = 488
    Height = 537
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
    object lContents19: TLabel
      Left = 192
      Top = 467
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents18: TLabel
      Left = 192
      Top = 443
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents17: TLabel
      Left = 192
      Top = 395
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents16: TLabel
      Left = 192
      Top = 419
      Width = 15
      Height = 13
      Caption = '.....'
    end
    object lContents20: TLabel
      Left = 192
      Top = 491
      Width = 15
      Height = 13
      Caption = '.....'
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
    object cbType19: TComboBox
      Tag = 14
      Left = 8
      Top = 464
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 15
      Visible = False
      OnChange = cbType1Change
    end
    object cbType16: TComboBox
      Tag = 11
      Left = 8
      Top = 392
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 16
      Visible = False
      OnChange = cbType1Change
    end
    object cbType17: TComboBox
      Tag = 12
      Left = 8
      Top = 416
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 17
      Visible = False
      OnChange = cbType1Change
    end
    object cbType18: TComboBox
      Tag = 13
      Left = 8
      Top = 440
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 18
      Visible = False
      OnChange = cbType1Change
    end
    object cbType20: TComboBox
      Tag = 14
      Left = 8
      Top = 488
      Width = 178
      Height = 21
      Style = csDropDownList
      TabOrder = 19
      Visible = False
      OnChange = cbType1Change
    end
  end
  object bImport: TBitBtn
    Left = 296
    Top = 637
    Width = 110
    Height = 25
    Caption = '.'
    ModalResult = 1
    TabOrder = 0
  end
  object bCancel: TBitBtn
    Left = 413
    Top = 637
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
    Left = 11
    Top = 637
    Width = 86
    Height = 25
    Caption = '.'
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
    TabOrder = 2
    OnClick = bHelpClick
  end
  object cbIFR: TCheckBox
    Left = 16
    Top = 606
    Width = 457
    Height = 17
    Caption = '.'
    TabOrder = 3
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 8
    Width = 488
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
    Left = 144
    Top = 637
    Width = 102
    Height = 25
    Caption = 'Auto'
    Glyph.Data = {
      36030000424D3603000000000000360000002800000010000000100000000100
      18000000000000030000120B0000120B00000000000000000000333333333537
      332E29331F0D323E47326DA23976B33C79B63B7BBB3B72A8385E84343C433124
      17322E2A333536333333333536332B233523122E6392299CFE3297F73E88D23D
      82C63D82C73D89D5368BE03380CE33597E33291E322C26333436332E2A332211
      3071B242B8FF3B8CDC3673B22D75BC4082C44082C32E76BD3278BD3B84CD4B9C
      ED37669531281E322E2A331F0C3461911EA7FF5BABFBEEEDECDCE8F4508DC921
      6DBA2570BB4887C6D9E6F3EFF4F96B9FD32784E1385C7F31241733393E349DFF
      309FFF1386F8C6E5FFFFFFFFD6E4F21364B50D60B3CCDDEFFFFFFFD4E3F2206C
      B83781CB3D87D1343C4334659534AEFF3697FA218DF9248FF9EEF7FFFFFFFF6D
      9FD16197CDFFFFFFF4F8FC3379BF2671BB3E7FC13E90E3385E843480CB34A7FF
      3497F83899F90981F868B2FBFFFFFFF7FAFCF7F9FCFFFFFF75A5D41163B54082
      C33C7FC23D89D53A71A93490EB349CFF3497F93497F93397F90B82F89DCDFCFF
      FFFFFFFFFFA5C4E31465B63A7EC23C7FC23C7FC23C81C73B7BBB348FEA349CFF
      3497F93497F93A9AF9007CF76EB4FBFFFFFFFFFFFF88B1DA095EB24182C43C7F
      C23C7FC23C82C73B7AB9347EC834A8FF3497F83798F91989F83799F9F4F9FFFF
      FFFFFFFFFBFFFFFF508CC81B6AB83F81C33C7FC23E87D03A71A834629034ADFF
      3496FA3095F90A82F8C3E1FEFFFFFF95B6D77BABDCFFFFFFD7E4F21B6AB8347A
      C03E79B43B99F534699D333639349BFE34A3FF1084F78CC4FCFFFFFFF8F4F01F
      7AD4037DF5E4F2FFFFFFFFA6C0DB1B61A83A8DDD33A2FF323F4C331F0C345C87
      2CADFF2E98FFC9E2FDD8EBFD70AFEE1186F8158AFE5BABFAD6EAFED3E5F83D8D
      DC28AEFF32669A331F0A33302C33210F326AA33DB5FF35A3FF278FF9228EFB36
      99FB3899F8248EF8278FF932A2FF3BBAFF3171AF332211332E29333536332D26
      34210F325C832D97F22DA9FF33A7FF359DFF359CFF33A7FF2DAAFF2D99F63260
      8B342212332B2433353733333333353633302C331F0D33363A34628A347EC134
      90E63490E73480C434658D33393E331F0D332F2A333537333333}
    TabOrder = 6
    OnClick = BitBtn1Click
  end
end
