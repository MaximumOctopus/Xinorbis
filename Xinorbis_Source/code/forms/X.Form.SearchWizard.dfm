object frmSearchWizard: TfrmSearchWizard
  Left = 625
  Top = 220
  BorderStyle = bsDialog
  ClientHeight = 549
  ClientWidth = 592
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
  object Shape1: TShape
    Left = 0
    Top = 0
    Width = 592
    Height = 33
    Align = alTop
    Brush.Color = 3355443
    Pen.Color = 3355443
    ExplicitLeft = 8
    ExplicitTop = -9
  end
  object bCancel: TBitBtn
    Left = 496
    Top = 4
    Width = 91
    Height = 25
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
    TabOrder = 0
  end
  object bOK: TBitBtn
    Left = 399
    Top = 4
    Width = 91
    Height = 25
    Caption = 'OK'
    Enabled = False
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
      00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FF3B8D3F257A292577293B853FFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF7F7F7F6A
      6A6A686868787878FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FF318F3542A05287CA9A9BD3AB9BD2AB83C7963D974C307C34FF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF7F7F7F8F8F8FBEBEBEC9
      C9C9C8C8C8BABABA8686866F6F6FFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FF258F2A6DBE83A8DBB587CC9866BC7D64BA7C86CB98A5D9B466B77D2472
      27FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF7D7D7DAFAFAFD1D1D1BFBFBFAD
      ADADABABABBEBEBECFCFCFA9A9A9656565FF00FFFF00FFFF00FFFF00FFFF00FF
      33A14472C287A8DBB260BC775CBA7359B87059B56F58B56F5BB774A5D9B369B8
      7F317F35FF00FFFF00FFFF00FFFF00FF909090B3B3B3D0D0D0ABABABA9A9A9A7
      A7A7A4A4A4A4A4A4A7A7A7CFCFCFAAAAAA727272FF00FFFF00FFFF00FFFF00FF
      4CB064AADDB464C1795FBE7175C585D4ECD98ACD9956B66C58B56E5CB774A6DA
      B4419B4EFF00FFFF00FFFF00FFFF00FF9F9F9FD2D2D2B0B0B0ACACACB5B5B5E7
      E7E7C0C0C0A5A5A5A4A4A4A7A7A7D0D0D08A8A8AFF00FFFF00FFFF00FF3FB55D
      91D29F8DD49A64C37479C987F2FAF4FFFFFFFDFEFD86CB9657B76D5BB97285CC
      9787C79A3B8B3FFF00FFFF00FFA3A3A3C5C5C5C6C6C6B1B1B1B9B9B9F9F9F9FF
      FFFFFEFEFEBEBEBEA6A6A6A8A8A8BFBFBFBBBBBB7D7D7DFF00FFFF00FF27B049
      A6DCAF70CA7F73CA80F0F9F1FFFFFFEBF7EDFFFFFFFBFDFC88CD965BB97167BE
      7DA0D7AF237F26FF00FFFF00FF9C9C9CD1D1D1B8B8B8B8B8B8F7F7F7FFFFFFF5
      F5F5FFFFFFFDFDFDBFBFBFA8A8A8AEAEAECDCDCD6E6E6EFF00FFFF00FF2EB751
      A7DDB172CC8066C773B0E1B7D2EED663C170B8E3BFFFFFFFFBFDFC8CD09969C1
      7EA1D7AE238426FF00FFFF00FFA2A2A2D2D2D2BABABAB4B4B4D6D6D6E7E7E7AF
      AFAFDADADAFFFFFFFDFDFDC2C2C2B1B1B1CCCCCC737373FF00FFFF00FF4BC56C
      95D7A191D79B69C97664C66F61C46E61C36F61C26FB9E4C0FFFFFFE3F4E68BD1
      998BCE9D3C993FFF00FFFF00FFB2B2B2C9C9C9C8C8C8B6B6B6B3B3B3B1B1B1B0
      B0B0AFAFAFDBDBDBFFFFFFF0F0F0C3C3C3C2C2C2898989FF00FFFF00FFFF00FF
      57BF70AFE1B76DCC7A68C87265C77063C56E62C46E63C471B6E3BE6FC77EACDF
      B548A95EFF00FFFF00FFFF00FFFF00FFADADADD6D6D6B9B9B9B5B5B5B4B4B4B2
      B2B2B1B1B1B1B1B1D9D9D9B6B6B6D4D4D4989898FF00FFFF00FFFF00FFFF00FF
      49C5667FCE90AEE1B56DCC7A6ACA7668C87268C87468C8756BC979ACDFB476C4
      8933A142FF00FFFF00FFFF00FFFF00FFB1B1B1BFBFBFD6D6D6B9B9B9B7B7B7B5
      B5B5B5B5B5B5B5B5B7B7B7D4D4D4B5B5B58F8F8FFF00FFFF00FFFF00FFFF00FF
      FF00FF3DC35C7FCE90AFE1B792D89D77CE8377CE8392D89DAEE1B578C88B27A1
      3BFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFAEAEAEBFBFBFD6D6D6CACACABC
      BCBCBCBCBCCACACAD6D6D6B9B9B98E8E8EFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FF4AC86959C27496D7A3A5DCAEA5DCAE95D6A150B96A35B355FF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFB4B4B4B0B0B0CACACAD0
      D0D0D0D0D0C9C9C9A6A6A6A0A0A0FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FF55CB723BC05C37BE5A49C36AFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFB8B8B8AB
      ABABA9A9A9B0B0B0FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
      00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
    ModalResult = 1
    NumGlyphs = 2
    TabOrder = 1
  end
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 59
    Width = 592
    Height = 490
    Align = alClient
    Color = clWhite
    ParentColor = False
    TabOrder = 2
    object pContaining: TPanel
      Left = 0
      Top = 0
      Width = 588
      Height = 24
      Align = alTop
      TabOrder = 0
      object lContaining: TLabel
        Left = 32
        Top = 36
        Width = 52
        Height = 13
        Caption = 'lContaining'
      end
      object eContaining: TEdit
        Left = 88
        Top = 32
        Width = 249
        Height = 21
        Color = clWhite
        TabOrder = 0
        OnChange = eSLTChange
      end
      object cbContaining: TAdvOfficeCheckBox
        Left = 6
        Top = 2
        Width = 555
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = cbContainingClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
    object pSize: TPanel
      Left = 0
      Top = 24
      Width = 588
      Height = 24
      Align = alTop
      TabOrder = 1
      object Label1: TLabel
        Left = 32
        Top = 36
        Width = 46
        Height = 13
        Caption = 'Less than'
      end
      object Label2: TLabel
        Left = 299
        Top = 36
        Width = 59
        Height = 13
        Caption = 'Greater than'
      end
      object eSLT: TEdit
        Left = 88
        Top = 32
        Width = 81
        Height = 21
        Color = clBtnFace
        TabOrder = 0
        OnChange = eSLTChange
      end
      object cbSLTUnit: TComboBox
        Left = 176
        Top = 32
        Width = 89
        Height = 21
        Style = csDropDownList
        TabOrder = 1
        OnChange = BuildSQLDisplay
      end
      object eSGT: TEdit
        Left = 368
        Top = 32
        Width = 81
        Height = 21
        Color = clBtnFace
        TabOrder = 2
        OnChange = eSLTChange
      end
      object cbSGTUnit: TComboBox
        Left = 456
        Top = 32
        Width = 89
        Height = 21
        Style = csDropDownList
        TabOrder = 3
        OnChange = BuildSQLDisplay
      end
      object cbSize: TAdvOfficeCheckBox
        Left = 6
        Top = 2
        Width = 555
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = cbSizeClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
    object pCategory: TPanel
      Left = 0
      Top = 48
      Width = 588
      Height = 24
      Align = alTop
      TabOrder = 2
      object sbProg: TCheckBox
        Left = 24
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 0
        OnClick = BuildSQLDisplay
      end
      object sbSys: TCheckBox
        Left = 136
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 1
        OnClick = BuildSQLDisplay
      end
      object sbGfx: TCheckBox
        Left = 248
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 2
        OnClick = BuildSQLDisplay
      end
      object sbMovie: TCheckBox
        Left = 360
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 3
        OnClick = BuildSQLDisplay
      end
      object sbSnd: TCheckBox
        Left = 472
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 4
        OnClick = BuildSQLDisplay
      end
      object sbOffice: TCheckBox
        Left = 24
        Top = 48
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 5
        OnClick = BuildSQLDisplay
      end
      object sbCode: TCheckBox
        Left = 136
        Top = 48
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 6
        OnClick = BuildSQLDisplay
      end
      object sbCompressed: TCheckBox
        Left = 248
        Top = 48
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 7
        OnClick = BuildSQLDisplay
      end
      object sbOther: TCheckBox
        Left = 360
        Top = 48
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 8
        OnClick = BuildSQLDisplay
      end
      object sbCustom1: TCheckBox
        Left = 24
        Top = 72
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 9
        OnClick = BuildSQLDisplay
      end
      object sbCustom2: TCheckBox
        Left = 136
        Top = 72
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 10
        OnClick = BuildSQLDisplay
      end
      object sbCustom3: TCheckBox
        Left = 248
        Top = 72
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 11
        OnClick = BuildSQLDisplay
      end
      object sbCustom4: TCheckBox
        Left = 360
        Top = 72
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 12
        OnClick = BuildSQLDisplay
      end
      object sbCustom7: TCheckBox
        Left = 136
        Top = 88
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 13
        OnClick = BuildSQLDisplay
      end
      object sbCustom5: TCheckBox
        Left = 472
        Top = 72
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 14
        OnClick = BuildSQLDisplay
      end
      object sbCustom8: TCheckBox
        Left = 248
        Top = 88
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 15
        OnClick = BuildSQLDisplay
      end
      object sbCustom6: TCheckBox
        Left = 24
        Top = 88
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 16
        OnClick = BuildSQLDisplay
      end
      object sbCustom9: TCheckBox
        Left = 360
        Top = 88
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 17
        OnClick = BuildSQLDisplay
      end
      object sbCustom10: TCheckBox
        Left = 472
        Top = 88
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 18
        OnClick = BuildSQLDisplay
      end
      object cbCategory: TAdvOfficeCheckBox
        Left = 6
        Top = 2
        Width = 555
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 19
        OnClick = cbCategoryClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
    object pAttributes: TPanel
      Left = 0
      Top = 144
      Width = 588
      Height = 129
      Align = alTop
      TabOrder = 3
      object cbAHidden: TCheckBox
        Tag = 1
        Left = 24
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 0
        OnClick = BuildSQLDisplay
      end
      object cbASystem: TCheckBox
        Tag = 2
        Left = 136
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 1
        OnClick = BuildSQLDisplay
      end
      object cbAArchive: TCheckBox
        Tag = 3
        Left = 248
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 2
        OnClick = BuildSQLDisplay
      end
      object cbAReadOnly: TCheckBox
        Tag = 5
        Left = 360
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 3
        OnClick = BuildSQLDisplay
      end
      object cbATemp: TCheckBox
        Tag = 14
        Left = 472
        Top = 32
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 4
        OnClick = BuildSQLDisplay
      end
      object cbAFolder: TCheckBox
        Tag = 15
        Left = 248
        Top = 64
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 5
        OnClick = BuildSQLDisplay
      end
      object cbAFile: TCheckBox
        Tag = 16
        Left = 360
        Top = 64
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 6
        OnClick = BuildSQLDisplay
      end
      object cbAttributes: TAdvOfficeCheckBox
        Left = 6
        Top = 2
        Width = 555
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        OnClick = cbAttributesClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
      object cbAVirtual: TCheckBox
        Tag = 21
        Left = 472
        Top = 64
        Width = 107
        Height = 17
        Caption = 'Virtual'
        TabOrder = 8
        OnClick = BuildSQLDisplay
      end
      object cbAEncrypted: TCheckBox
        Tag = 7
        Left = 24
        Top = 64
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 9
        OnClick = BuildSQLDisplay
      end
      object cbACompressed: TCheckBox
        Tag = 6
        Left = 136
        Top = 64
        Width = 107
        Height = 17
        Caption = '.'
        TabOrder = 10
        OnClick = BuildSQLDisplay
      end
    end
    object pCreated: TPanel
      Left = 0
      Top = 72
      Width = 588
      Height = 24
      Align = alTop
      TabOrder = 4
      object cbCreated1: TComboBox
        Tag = 1
        Left = 24
        Top = 32
        Width = 89
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = cbCreated1Change
      end
      object cbCreated2: TComboBox
        Tag = 2
        Left = 280
        Top = 32
        Width = 89
        Height = 21
        Style = csDropDownList
        TabOrder = 1
        OnChange = cbCreated1Change
      end
      object dtpCreated2: TDateTimePicker
        Tag = 2
        Left = 376
        Top = 32
        Width = 121
        Height = 21
        Date = 39918.736574432870000000
        Time = 39918.736574432870000000
        DateFormat = dfLong
        Enabled = False
        TabOrder = 2
        OnChange = BuildSQLDisplay
      end
      object dtpCreated1: TDateTimePicker
        Tag = 1
        Left = 120
        Top = 32
        Width = 121
        Height = 21
        Date = 40071.736574432870000000
        Time = 40071.736574432870000000
        DateFormat = dfLong
        Enabled = False
        TabOrder = 3
        OnChange = BuildSQLDisplay
      end
      object cbCreated: TAdvOfficeCheckBox
        Left = 6
        Top = 2
        Width = 555
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = cbCreatedClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
    object pAccessed: TPanel
      Left = 0
      Top = 96
      Width = 588
      Height = 24
      Align = alTop
      TabOrder = 5
      object cbAccessed1: TComboBox
        Tag = 3
        Left = 24
        Top = 32
        Width = 89
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = cbCreated1Change
      end
      object dtpAccessed1: TDateTimePicker
        Tag = 3
        Left = 120
        Top = 32
        Width = 121
        Height = 21
        Date = 39918.736574432870000000
        Time = 39918.736574432870000000
        DateFormat = dfLong
        Enabled = False
        TabOrder = 1
      end
      object cbAccessed2: TComboBox
        Tag = 4
        Left = 280
        Top = 32
        Width = 89
        Height = 21
        Style = csDropDownList
        TabOrder = 2
        OnChange = cbCreated1Change
      end
      object dtpAccessed2: TDateTimePicker
        Tag = 4
        Left = 376
        Top = 32
        Width = 121
        Height = 21
        Date = 39918.736574432870000000
        Time = 39918.736574432870000000
        DateFormat = dfLong
        Enabled = False
        TabOrder = 3
        OnChange = BuildSQLDisplay
      end
      object cbAccessed: TAdvOfficeCheckBox
        Left = 6
        Top = 2
        Width = 555
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = cbCreatedClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
    object pModified: TPanel
      Left = 0
      Top = 120
      Width = 588
      Height = 24
      Align = alTop
      TabOrder = 6
      object cbModified1: TComboBox
        Tag = 5
        Left = 24
        Top = 32
        Width = 89
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = cbCreated1Change
      end
      object dtpModified1: TDateTimePicker
        Tag = 5
        Left = 120
        Top = 32
        Width = 121
        Height = 21
        Date = 39918.736574432870000000
        Time = 39918.736574432870000000
        DateFormat = dfLong
        Enabled = False
        TabOrder = 1
        OnChange = BuildSQLDisplay
      end
      object cbModified2: TComboBox
        Tag = 6
        Left = 280
        Top = 32
        Width = 89
        Height = 21
        Style = csDropDownList
        TabOrder = 2
        OnChange = cbCreated1Change
      end
      object dtpModified2: TDateTimePicker
        Tag = 6
        Left = 376
        Top = 32
        Width = 121
        Height = 21
        Date = 39918.736574432870000000
        Time = 39918.736574432870000000
        DateFormat = dfLong
        Enabled = False
        TabOrder = 3
        OnChange = BuildSQLDisplay
      end
      object cbModified: TAdvOfficeCheckBox
        Left = 6
        Top = 2
        Width = 555
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = cbCreatedClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
    object pOwner: TPanel
      Left = 0
      Top = 273
      Width = 588
      Height = 24
      Align = alTop
      TabOrder = 7
      ExplicitTop = 168
      object cbUSelect: TComboBox
        Left = 24
        Top = 32
        Width = 105
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = cbUSelectChange
      end
      object eUContent: TEdit
        Left = 136
        Top = 32
        Width = 145
        Height = 21
        Color = clWhite
        Enabled = False
        TabOrder = 1
        OnChange = eSLTChange
      end
      object cbOwner: TAdvOfficeCheckBox
        Left = 6
        Top = 2
        Width = 555
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = cbOwnerClick
        Alignment = taLeftJustify
        Caption = '.'
        ReturnIsTab = False
        Version = '1.5.0.9'
      end
    end
  end
  object bShowSQL: TBitBtn
    Tag = 1
    Left = 4
    Top = 4
    Width = 82
    Height = 25
    Caption = 'SQL'
    NumGlyphs = 2
    TabOrder = 3
    OnClick = bShowSQLClick
  end
  object pSQL: TPanel
    Left = 0
    Top = 33
    Width = 592
    Height = 26
    Align = alTop
    TabOrder = 4
    Visible = False
    object eSQL: TEdit
      Left = 2
      Top = 3
      Width = 586
      Height = 21
      ReadOnly = True
      TabOrder = 0
    end
  end
  object ImageList1: TImageList
    BkColor = clFuchsia
    Left = 232
    Bitmap = {
      494C010102000400AC0010001000FF00FF00FF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      000000000000000000000000000000000000FF00FF00FF00FF00B1B1B1009A9A
      9A00929292008E8E8E008A8A8A00878787008383830080808000808080008080
      80008080800080808000808080009F9F9F00FF00FF00FF00FF00DFB49300D59D
      7400D1966800CE926300CB8E5E00C98A5B00C7875600C3845200C3845200C384
      5200C3845200C3845200C3845200D0A17D000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF00FF00FF00FF009D9D9D00F2F2
      F200EFEFEF00ECECEC00E9E9E900E6E6E600E3E3E300E1E1E100E1E1E100E1E1
      E100E1E1E100E1E1E100E1E1E10087878700FF00FF00FF00FF00D7A17500F8F2
      ED00F7F0EA00F6EDE600F4EAE200F3E7DE00F1E4DB00F0E2D800F0E2D800F0E2
      D800F0E2D800F0E2D800F0E2D800C58B5E000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF00FF00FF00FF00A0A0A000F3F3
      F300D0D0D000FFFFFF00D1D1D100FFFFFF00FFFFFF00FFFFFF00C4C4C400FFFF
      FF00FFFFFF00FFFFFF00E1E1E10088888800FF00FF00FF00FF00D9A47A00F9F3
      EE00EBD2BE00FFFFFF00EBD3BF00FFFFFF00FFFFFF00FFFFFF00EAC7AD00FFFF
      FF00FFFFFF00FFFFFF00F0E2D800C68C5F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF00FF00FF00FF00A4A4A400F3F3
      F300CDCDCD00CECECE00CECECE00CECECE00CECECE00CFCFCF00CACACA00CACA
      CA00CACACA00CACACA00E1E1E10086868600FF00FF00FF00FF00DDA87E00F9F3
      EF00EBD0BA00EBD0BB00EBD0BB00EBD0BB00EBD0BB00EBD1BD00EACDB500EACD
      B500EACDB500EACDB500F0E2D800C68A5C000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF00FF00FF00FF00A7A7A700F3F3
      F300CBCBCB00FFFFFF00CECECE00FFFFFF00FFFFFF00FFFFFF00CDCDCD00F6F6
      F600FFFFFF00FFFFFF00E1E1E10089898900FF00FF00FF00FF00DFAA8200F9F3
      EF00EACEB700FFFFFF00EBD0BB00FFFFFF00FFFFFF00FFFFFF00EACFBA00FBF6
      F200FFFFFF00FFFFFF00F0E2D800C88D5F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF00FF00FF00FF00A9A9A900DEDE
      DE00B9B9B900BFBFBF00C4C4C400C9C9C900C9C9C900CBCBCB00C4C4C400C4C4
      C400C6C6C600C5C5C500E1E1E10082828200FF00FF00FF00FF00D8AC8A00E3DE
      DB00D2BBA900DBC2AD00E3C7B000EACCB300EACCB300EACEB700E8C7AC00E8C7
      AC00E8C8B000E8C8AE00F0E2D800C48654000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF00FF00D9D9D900A3A3A300ABAB
      AB00A0A0A000A7A7A700A6A6A600F3F3F300FFFFFF00FFFFFF00C4C4C400FFFF
      FF00FFFFFF00FFFFFF00E4E4E40082828200FF00FF00D9D9D900AFA49C00ABAB
      AA00A4A09C00A7A7A700B6A79C00F3F3F300FFFFFF00FFFFFF00E8C7AC00FFFF
      FF00FFFFFF00FFFFFF00F1E5DB00C68655000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C6C6C600CBCBCB00EAEAEA00F0F0
      F000F2F2F200ECECEC00CACACA0095959500C6C6C600C6C6C600C4C4C400C6C6
      C600C6C6C600C9C9C900E6E6E60086868600C6C6C600CBCBCB00EAEAEA00F0F0
      F000F2F2F200ECECEC00CACACA009A959100E9C9AE00E9C9B000E8C7AC00E9C9
      B000E8C8B000E8CCB500F2E7DE00C88A59000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000B1B1B100FAFAFA00D7D7D700E2E2
      E200CACACA00CFCFCF00FFFFFF0093939300FFFFFF00FFFFFF00C4C4C400FFFF
      FF00FFFFFF00FFFFFF00F0F0F0008B8B8B00B1B1B100FAFAFA00D7D7D700E2E2
      E200CACACA00CFCFCF00FFFFFF0093939300FFFFFF00FFFFFF00E8C7AC00FFFF
      FF00FFFFFF00FFFFFF00F7F1EB00CB8F5F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000B5B5B500F8F8F800D1D1D100ECEC
      EC00C5C5C500C6C6C600FFFFFF009A9A9A00C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000F7F7F7008F8F8F00B5B5B500F8F8F800D1D1D100ECEC
      EC00C5C5C500C6C6C600FFFFFF009A9A9A00E9C3A600E9C3A600E9C3A600E9C3
      A600E9C3A600E9C3A600FBF7F400CE9364000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000B8B8B800F8F8F800D5D5D500EFEF
      EF00CBCBCB00CBCBCB00FFFFFF009E9E9E00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F7F7F70093939300B8B8B800F8F8F800D5D5D500EFEF
      EF00CBCBCB00CBCBCB00FFFFFF009E9E9E00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FBF7F400D1976A000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BBBBBB00F8F8F800DBDBDB00EFEF
      EF00D0D0D000D0D0D000FFFFFF00A2A2A200BDBDBD00BBBBBB00B7B7B700B4B4
      B400B1B1B100AEAEAE00F7F7F70097979700BBBBBB00F8F8F800DBDBDB00EFEF
      EF00D0D0D000D0D0D000FFFFFF00A2A2A2008BCB930087C98E0082C689007EC3
      84007AC1800076BE7C00FBF7F400D49B6F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BCBCBC00F2F2F200D9D9D900E4E4
      E400E2E2E200C8C8C800F1F1F100A5A5A500F7F7F700F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F7009F9F9F00BCBCBC00F2F2F200D9D9D900E4E4
      E400E2E2E200C8C8C800F1F1F100A5A5A500FBF7F400FBF7F400FBF7F400FBF7
      F400FBF7F400FBF7F400FBF7F400D8A378000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BDBDBD00F6F6F600F4F4F400F9F9
      F900FBFBFB00F6F6F600F6F6F600A8A8A800B3B3B300B1B1B100AEAEAE00ABAB
      AB00A9A9A900A5A5A500A1A1A100B3B3B300BDBDBD00F6F6F600F4F4F400F9F9
      F900FBFBFB00F6F6F600F6F6F600A8A8A800E7B79300E6B59000E4B28C00E2AF
      8800E0AC8400DDA98000DCA57D00E2B696000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000D3D3D300D6D6D600EDEDED00F9F9
      F900FBFBFB00F0F0F000D9D9D900B8B8B800FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00D3D3D300D6D6D600EDEDED00F9F9
      F900FBFBFB00F0F0F000D9D9D900B8B8B800FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FBFBFB00E2E2E200CACACA00BDBD
      BD00B8B8B800C0C0C000D4D4D400FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00CACACA00BDBD
      BD00B8B8B800C0C0C000D4D4D400FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00C000C00000000000C000C00000000000
      C000C00000000000C000C00000000000C000C00000000000C000C00000000000
      8000800000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00FF00FF0000000001FFC1FF0000000000000000000000000000000000000000
      000000000000}
  end
end
