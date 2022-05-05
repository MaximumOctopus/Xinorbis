object frmExplore: TfrmExplore
  Left = 491
  Top = 275
  BorderIcons = [biSystemMenu]
  Caption = '.'
  ClientHeight = 419
  ClientWidth = 907
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  ShowHint = True
  OnClose = FormClose
  OnConstrainedResize = FormConstrainedResize
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 391
    Width = 907
    Height = 28
    Align = alBottom
    BevelOuter = bvNone
    FullRepaint = False
    TabOrder = 0
    DesignSize = (
      907
      28)
    object bHelp: TBitBtn
      Left = 1
      Top = 2
      Width = 107
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
      TabOrder = 0
      OnClick = bHelpClick
    end
    object bClose: TBitBtn
      Left = 814
      Top = 2
      Width = 92
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
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
      ModalResult = 1
      TabOrder = 1
      OnClick = bCloseClick
    end
    object bFilter: TBitBtn
      Left = 163
      Top = 2
      Width = 92
      Height = 25
      Cancel = True
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFDFEFD9FC2A2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEBABABAFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF8BBC905E9D63FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB1B1B18F8F8FFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF9BCBA066B06E61AA683D8B4437833E327B373D7F436496689EBC
        A0E6EDE6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0A1A1A19B9B9B7C
        7C7C7575756D6D6D7272728B8B8BB5B5B5ECECECFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFAAD8AF73BD7C96D19F94CF9C8FCD968ACA9185C78B7ABE8165AD6C4B92
        5168976BCDDCCEFFFFFFFFFFFFFFFFFFFFFFFFCDCDCDAEAEAEC4C4C4C2C2C2BF
        BFBFBCBCBCB8B8B8AFAFAF9E9E9E8383838C8C8CD9D9D9FFFFFFFFFFFFFFFFFF
        FFFFFFA9DBAF79C4839ED7A79BD4A497D29F92CF9A8DCC9588CA907AC2827EC4
        855DA46369996CE6EDE6FFFFFFFFFFFFFFFFFFD0D0D0B4B4B4CBCBCBC8C8C8C5
        C5C5C2C2C2BEBEBEBCBCBCB2B2B2B5B5B59595958E8E8EECECECFFFFFFFFFFFF
        FFFFFFFFFFFFA4DAAB7BC78577C28154AB5E4EA357499B5163AC6B83C38B87C9
        8F82C689509756A0BFA2FFFFFFFFFFFFFFFFFFFFFFFFCECECEB7B7B7B2B2B29A
        9A9A9292928B8B8B9D9D9DB5B5B5BBBBBBB7B7B7888888B8B8B8FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF9ED8A57BC784FFFFFFFFFFFFFFFFFF9BC9A05BA26286C6
        8E88C98F6FB376699D6DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCBCBCBB7B7B7FF
        FFFFFFFFFFFFFFFFBEBEBE939393B8B8B8BBBBBBA5A5A5929292B8D7BBB6D4B9
        B4D1B6B2CEB4AFCBB1FDFEFDB4E2BAFFFFFFFFFFFFFFFFFFFFFFFFA4CFA854A0
        5B48954F408B47478B4ED0D0D0CDCDCDCACACAC7C7C7C4C4C4FEFEFED8D8D8FF
        FFFFFFFFFFFFFFFFFFFFFFC5C5C59090908686867C7C7C7D7D7D5DA9644C9C54
        48954F49904F97BE9BFFFFFFFFFFFFFFFFFFFFFFFF92B294FCFDFCBEDFC2BCDC
        BFBAD9BDB7D6BBB5D3B89999998C8C8C868686818181B5B5B5FFFFFFFFFFFFFF
        FFFFFFFFFFAAAAAAFDFDFDD8D8D8D5D5D5D2D2D2CFCFCFCCCCCC84C38B80C389
        8DCC9583C48A54995A90BA94FFFFFFFFFFFFFFFFFF4A814D739C76FFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFB5B5B5B4B4B4BEBEBEB6B6B68B8B8BB0B0B0FFFFFFFF
        FFFFFFFFFF757575929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB7DEBB75BF7E
        98D2A194CF9C86C78D5EA765398640347E3A2E763349904F458B4A7EA581FFFF
        FFFFFFFFFFFFFFFFFFFFD5D5D5B0B0B0C6C6C6C2C2C2B9B9B998989877777770
        70706868688181817D7D7D9C9C9CFFFFFFFFFFFFFFFFFFFFFFFFEDF7EE8ECD96
        85C98E9BD4A48FCE9892CF9A8DCC9588CA9083C68B7EC48579C17F478D4C87AC
        89FFFFFFFFFFFFFFFFFFF5F5F5BFBFBFBABABAC8C8C8C0C0C0C2C2C2BEBEBEBC
        BCBCB7B7B7B5B5B5B1B1B17E7E7EA3A3A3FFFFFFFFFFFFFFFFFFFFFFFFDCF0DE
        90CF9779C38389CA9294D09C95D19E90CF998CCB9487C98F80C4874E95548FB3
        92FFFFFFFFFFFFFFFFFFFFFFFFEBEBEBC1C1C1B3B3B3BCBCBCC3C3C3C4C4C4C1
        C1C1BDBDBDBBBBBBB5B5B5868686ABABABFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        EDF8EFB9E1BE89C99064B46C50A65A4B9E5345964D60A8685BA2628CB690FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6D8D8D8BBBBBBA4A4A49595958D
        8D8D878787999999939393ACACACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF67AB6E8BBC90FFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFF9C9C9CB1B1B1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFACD4B0FDFEFDFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFCACACAFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ModalResult = 1
      NumGlyphs = 2
      TabOrder = 2
      OnClick = bFilterClick
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 391
    Align = alLeft
    Color = clWhite
    FullRepaint = False
    ParentBackground = False
    TabOrder = 1
    object Bevel1: TBevel
      Left = 218
      Top = 6
      Width = 4
      Height = 21
      Shape = bsLeftLine
    end
    object sbBack: TSpeedButton
      Left = 226
      Top = 4
      Width = 23
      Height = 22
      Enabled = False
      Flat = True
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFDFB037B1E007D21FBFD
        FBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFDFDFD6A6A6A6C6C6CFDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9FCFA33954C43A15F06852FFFFF
        FFF9FCFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFCFCFC858585929292747474FFFFFFFCFCFCFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF04802546A36280C1963A9F5E0F8B
        3B158F431D924A239852FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF6F6F6F949494B6B6B69090907A7A7A7E7E7E828282888888FFFFFF6EACE4
        4796DD2F88D82D88D82D88D82D89D40D833B48A56682C2976AB68588C59E8AC6
        A18DC8A590CAA9299B5BFFFFFFB8B8B8A7A7A79C9C9C9C9C9C9C9C9C9B9B9B73
        7373969696B7B7B7A9A9A9BABABABCBCBCBEBEBEC0C0C08B8B8BFFFFFF4799DD
        DEF1FAA8DDF49EDBF496DAF30180263CA05C83C29867B58261B38066B6856BB8
        896FBA8E94CDAD319F63FFFFFFA8A8A8F2F2F2E0E0E0DEDEDEDDDDDD6F6F6F90
        9090B7B7B7A8A8A8A5A5A5A9A9A9ABABABAEAEAEC4C4C4909090FFFFFF3B97DB
        EFFAFEA1E9F991E5F881E1F772DEF608873846A5688AC7A174BC9090CBA891CB
        AA94CDAD96CEB037A36BFFFFFFA7A7A7FBFBFBEAEAEAE6E6E6E2E2E2DFDFDF77
        7777969696BCBCBCB0B0B0C1C1C1C1C1C1C4C4C4C6C6C6949494FFFFFF3C9DDB
        F2FAFDB3EDFAA4E9F995E6F885E2F776DEF61A91484FAB7491CBAA55AF7C309E
        6334A26938A46F3DA56FFFFFFFABABABFBFBFBEEEEEEEAEAEAE7E7E7E3E3E3E0
        E0E08080809D9D9DC1C1C1A2A2A28F8F8F939393969696979797FFFFFF3BA3DB
        F6FCFEC8F2FCB9EFFBACECFA9CE8F98BE3F77CE0F62898575AB38134A46E44D3
        F3D0F3FC38A1DBF3FCFEFFFFFFAEAEAEFDFDFDF3F3F3EFEFEFECECECE9E9E9E4
        E4E4E1E1E1888888A6A6A6969696D6D6D6F3F3F3ADADADFCFCFCFFFFFF3BA8DB
        FEFFFFF8FDFFF6FDFFF5FCFFF3FCFED8F6FC94E6F885E3F7319F653CA8765CD8
        F4D7F4FC3AA7DBFFFFFFFFFFFFB2B2B2FFFFFFFEFEFEFEFEFEFDFDFDFCFCFCF6
        F6F6E7E7E7E4E4E49090909A9A9ADADADAF5F5F5B1B1B1FFFFFFFFFFFF39ADDB
        E8F6FB94D4EF88CEEE73C1E9C9E9F6F2FCFEF3FCFEF2FCFEF0FCFEEFFBFEEEFB
        FEFEFFFF36ABDAFFFFFFFFFFFFB5B5B5F7F7F7D8D8D8D3D3D3C8C8C8EBEBEBFC
        FCFCFCFCFCFCFCFCFCFCFCFBFBFBFBFBFBFFFFFFB3B3B3FFFFFFFFFFFF40AEDC
        F1FAFD94DEF593DCF481D5F26ACAED6CCBEA85D3EF80D2EF7AD0EF76CFEE72CF
        EEE9F7FB34AEDAFFFFFFFFFFFFB6B6B6FBFBFBE0E0E0DEDEDED9D9D9CFCFCFCF
        CFCFD6D6D6D6D6D6D4D4D4D3D3D3D3D3D3F7F7F7B5B5B5FFFFFFFFFFFF41B4DC
        F7FCFE8EE4F891DEF59FE0F5ACE1F6EFFBFEF4FDFEF3FCFEF1FCFEEFFBFEEEFB
        FEFAFDFF3CB1DBFFFFFFFFFFFFBABABAFDFDFDE5E5E5E0E0E0E2E2E2E4E4E4FB
        FBFBFDFDFDFCFCFCFCFCFCFBFBFBFBFBFBFEFEFEB7B7B7FFFFFFFFFFFF3CB5DB
        FDFEFEFEFFFFFEFEFFFDFEFFFEFFFFEAF7FB6EC8E56FC9E46FC9E46FC9E479CD
        E676CBE58CD3EAFFFFFFFFFFFFBABABAFEFEFEFFFFFFFEFEFEFEFEFEFFFFFFF8
        F8F8CBCBCBCCCCCCCCCCCCCCCCCCD0D0D0CECECED6D6D6FFFFFFFFFFFF59C2E0
        61C3E263C4E363C4E363C4E35FC3E240B7DCEDF8FCF3FAFDF3FAFDF3FAFDF3FA
        FDF3FBFDFCFEFEFFFFFFFFFFFFC5C5C5C7C7C7C8C8C8C8C8C8C8C8C8C7C7C7BC
        BCBCF9F9F9FBFBFBFBFBFBFBFBFBFBFBFBFCFCFCFEFEFEFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      NumGlyphs = 2
      OnClick = sbBackClick
    end
    object ScrollBox1: TScrollBox
      Left = 1
      Top = 28
      Width = 255
      Height = 362
      Align = alBottom
      Anchors = [akLeft, akTop, akRight, akBottom]
      Color = clWhite
      ParentColor = False
      TabOrder = 0
      object pAttributes: TPanel
        Left = 0
        Top = 78
        Width = 251
        Height = 26
        Align = alTop
        TabOrder = 0
        object cbAHidden: TCheckBox
          Tag = 1
          Left = 24
          Top = 32
          Width = 107
          Height = 17
          Caption = '.'
          TabOrder = 0
        end
        object cbASystem: TCheckBox
          Tag = 2
          Left = 24
          Top = 48
          Width = 107
          Height = 17
          Caption = '.'
          TabOrder = 1
        end
        object cbAArchive: TCheckBox
          Tag = 3
          Left = 24
          Top = 64
          Width = 107
          Height = 17
          Caption = '.'
          TabOrder = 2
        end
        object cbAReadOnly: TCheckBox
          Tag = 5
          Left = 24
          Top = 80
          Width = 107
          Height = 17
          Caption = '.'
          TabOrder = 3
        end
        object cbATemp: TCheckBox
          Tag = 9
          Left = 24
          Top = 96
          Width = 107
          Height = 17
          Caption = '.'
          TabOrder = 4
        end
        object cbAttributes: TAdvOfficeCheckBox
          Left = 3
          Top = 1
          Width = 245
          Height = 20
          TabOrder = 5
          OnClick = cbAttributesClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
        end
      end
      object pOwner: TPanel
        Left = 0
        Top = 182
        Width = 251
        Height = 26
        Align = alTop
        TabOrder = 1
        object cbUSelect: TComboBox
          Left = 24
          Top = 32
          Width = 105
          Height = 21
          Style = csDropDownList
          TabOrder = 0
        end
        object eUContent: TEdit
          Left = 136
          Top = 32
          Width = 105
          Height = 21
          Color = clWhite
          Enabled = False
          TabOrder = 1
        end
        object cbOwner: TAdvOfficeCheckBox
          Left = 3
          Top = 1
          Width = 245
          Height = 20
          TabOrder = 2
          OnClick = cbOwnerClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
        end
      end
      object pModified: TPanel
        Left = 0
        Top = 156
        Width = 251
        Height = 26
        Align = alTop
        TabOrder = 2
        object cbModified1: TComboBox
          Tag = 5
          Left = 24
          Top = 32
          Width = 81
          Height = 21
          Style = csDropDownList
          TabOrder = 0
          OnChange = cbCreated1Change
        end
        object dtpModified1: TDateTimePicker
          Tag = 5
          Left = 112
          Top = 32
          Width = 121
          Height = 21
          Date = 39918.736574432870000000
          Time = 39918.736574432870000000
          DateFormat = dfLong
          Enabled = False
          TabOrder = 1
        end
        object cbModified2: TComboBox
          Tag = 6
          Left = 24
          Top = 56
          Width = 81
          Height = 21
          Style = csDropDownList
          TabOrder = 2
          OnChange = cbCreated1Change
        end
        object dtpModified2: TDateTimePicker
          Tag = 6
          Left = 112
          Top = 56
          Width = 121
          Height = 21
          Date = 39918.736574432870000000
          Time = 39918.736574432870000000
          DateFormat = dfLong
          Enabled = False
          TabOrder = 3
        end
        object cbModified: TAdvOfficeCheckBox
          Left = 3
          Top = 1
          Width = 245
          Height = 20
          TabOrder = 4
          OnClick = cbCreatedClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
        end
      end
      object pAccessed: TPanel
        Left = 0
        Top = 130
        Width = 251
        Height = 26
        Align = alTop
        TabOrder = 3
        object cbAccessed1: TComboBox
          Tag = 3
          Left = 24
          Top = 32
          Width = 81
          Height = 21
          Style = csDropDownList
          TabOrder = 0
          OnChange = cbCreated1Change
        end
        object dtpAccessed1: TDateTimePicker
          Tag = 3
          Left = 112
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
          Left = 24
          Top = 56
          Width = 81
          Height = 21
          Style = csDropDownList
          TabOrder = 2
          OnChange = cbCreated1Change
        end
        object dtpAccessed2: TDateTimePicker
          Tag = 4
          Left = 112
          Top = 56
          Width = 121
          Height = 21
          Date = 39918.736574432870000000
          Time = 39918.736574432870000000
          DateFormat = dfLong
          Enabled = False
          TabOrder = 3
        end
        object cbAccessed: TAdvOfficeCheckBox
          Left = 3
          Top = 1
          Width = 245
          Height = 20
          TabOrder = 4
          OnClick = cbCreatedClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
        end
      end
      object pCreated: TPanel
        Left = 0
        Top = 104
        Width = 251
        Height = 26
        Align = alTop
        TabOrder = 4
        object cbCreated1: TComboBox
          Tag = 1
          Left = 24
          Top = 32
          Width = 81
          Height = 21
          Style = csDropDownList
          TabOrder = 0
          OnChange = cbCreated1Change
        end
        object cbCreated2: TComboBox
          Tag = 2
          Left = 24
          Top = 56
          Width = 81
          Height = 21
          Style = csDropDownList
          TabOrder = 1
          OnChange = cbCreated1Change
        end
        object dtpCreated2: TDateTimePicker
          Tag = 2
          Left = 112
          Top = 56
          Width = 121
          Height = 21
          Date = 39918.736574432870000000
          Time = 39918.736574432870000000
          DateFormat = dfLong
          Enabled = False
          TabOrder = 2
        end
        object dtpCreated1: TDateTimePicker
          Tag = 1
          Left = 112
          Top = 32
          Width = 121
          Height = 21
          Date = 40071.736574432870000000
          Time = 40071.736574432870000000
          DateFormat = dfLong
          Enabled = False
          TabOrder = 3
        end
        object cbCreated: TAdvOfficeCheckBox
          Left = 3
          Top = 1
          Width = 245
          Height = 20
          TabOrder = 4
          OnClick = cbCreatedClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
        end
      end
      object pCategory: TPanel
        Left = 0
        Top = 52
        Width = 251
        Height = 26
        Align = alTop
        TabOrder = 5
        object sbProg: TCheckBox
          Tag = 1
          Left = 24
          Top = 32
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 0
        end
        object sbSys: TCheckBox
          Tag = 2
          Left = 136
          Top = 32
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 1
        end
        object sbGfx: TCheckBox
          Tag = 3
          Left = 24
          Top = 48
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 2
        end
        object sbMovie: TCheckBox
          Tag = 4
          Left = 136
          Top = 48
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 3
        end
        object sbSnd: TCheckBox
          Tag = 5
          Left = 24
          Top = 64
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 4
        end
        object sbOffice: TCheckBox
          Tag = 6
          Left = 136
          Top = 64
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 5
        end
        object sbCode: TCheckBox
          Tag = 7
          Left = 24
          Top = 80
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 6
        end
        object sbCompressed: TCheckBox
          Tag = 8
          Left = 136
          Top = 80
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 7
        end
        object sbOther: TCheckBox
          Tag = 9
          Left = 24
          Top = 96
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 8
        end
        object sbCustom1: TCheckBox
          Tag = 10
          Left = 24
          Top = 120
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 9
        end
        object sbCustom2: TCheckBox
          Tag = 11
          Left = 136
          Top = 120
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 10
        end
        object sbCustom3: TCheckBox
          Tag = 12
          Left = 24
          Top = 136
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 11
        end
        object sbCustom4: TCheckBox
          Tag = 13
          Left = 136
          Top = 136
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 12
        end
        object sbCustom7: TCheckBox
          Tag = 16
          Left = 24
          Top = 168
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 13
        end
        object sbCustom5: TCheckBox
          Tag = 14
          Left = 24
          Top = 152
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 14
        end
        object sbCustom8: TCheckBox
          Tag = 17
          Left = 136
          Top = 168
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 15
        end
        object sbCustom6: TCheckBox
          Tag = 15
          Left = 136
          Top = 152
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 16
        end
        object sbCustom9: TCheckBox
          Tag = 18
          Left = 24
          Top = 184
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 17
        end
        object sbCustom10: TCheckBox
          Tag = 19
          Left = 136
          Top = 184
          Width = 92
          Height = 17
          Caption = '.'
          TabOrder = 18
        end
        object cbCategory: TAdvOfficeCheckBox
          Left = 3
          Top = 1
          Width = 245
          Height = 20
          TabOrder = 19
          OnClick = cbCategoryClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
        end
      end
      object pSize: TPanel
        Left = 0
        Top = 26
        Width = 251
        Height = 26
        Align = alTop
        TabOrder = 6
        object Label2: TLabel
          Left = 24
          Top = 36
          Width = 12
          Height = 13
          Hint = 'less than or equal to'
          Caption = '<='
        end
        object Label3: TLabel
          Left = 24
          Top = 60
          Width = 12
          Height = 13
          Hint = 'greater than or equal to'
          Caption = '>='
        end
        object eSLT: TEdit
          Left = 40
          Top = 32
          Width = 65
          Height = 21
          TabOrder = 0
          OnEnter = eSLTEnter
          OnExit = eSLTExit
        end
        object cbSLTUnit: TComboBox
          Left = 112
          Top = 32
          Width = 79
          Height = 21
          Style = csDropDownList
          TabOrder = 1
        end
        object eSGT: TEdit
          Left = 40
          Top = 56
          Width = 65
          Height = 21
          TabOrder = 2
          OnEnter = eSLTEnter
          OnExit = eSLTExit
        end
        object cbSGTUnit: TComboBox
          Left = 112
          Top = 56
          Width = 79
          Height = 21
          Style = csDropDownList
          TabOrder = 3
        end
        object cbSize: TAdvOfficeCheckBox
          Left = 3
          Top = 1
          Width = 245
          Height = 25
          TabOrder = 4
          OnClick = cbSizeClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
        end
      end
      object pContaining: TPanel
        Left = 0
        Top = 0
        Width = 251
        Height = 26
        Align = alTop
        TabOrder = 7
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
          Width = 89
          Height = 21
          Color = clWhite
          TabOrder = 0
        end
        object cbContaining: TAdvOfficeCheckBox
          Left = 3
          Top = 1
          Width = 245
          Height = 20
          TabOrder = 1
          OnClick = cbContainingClick
          Alignment = taLeftJustify
          Caption = '.'
          ReturnIsTab = False
          Version = '1.4.1.1'
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 257
    Top = 0
    Width = 650
    Height = 391
    Align = alClient
    TabOrder = 2
    object sgExplore: TAdvStringGrid
      Left = 1
      Top = 29
      Width = 648
      Height = 361
      Cursor = crDefault
      Align = alClient
      ColCount = 10
      DefaultRowHeight = 21
      DrawingStyle = gdsClassic
      FixedCols = 0
      RowCount = 5
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      GridLineWidth = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goRowSelect]
      ParentFont = False
      ScrollBars = ssBoth
      TabOrder = 0
      OnDrawCell = sgExploreDrawCell
      HoverRowCells = [hcNormal, hcSelected]
      OnCanSort = sgExploreCanSort
      OnDblClickCell = sgExploreDblClickCell
      OnResize = sgExploreResize
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      Bands.Active = True
      Bands.PrimaryColor = 16381426
      CellNode.TreeColor = clSilver
      ControlLook.FixedGradientHoverFrom = clGray
      ControlLook.FixedGradientHoverTo = clWhite
      ControlLook.FixedGradientDownFrom = clGray
      ControlLook.FixedGradientDownTo = clSilver
      ControlLook.ControlStyle = csWinXP
      ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
      ControlLook.DropDownHeader.Font.Color = clWindowText
      ControlLook.DropDownHeader.Font.Height = -11
      ControlLook.DropDownHeader.Font.Name = 'Tahoma'
      ControlLook.DropDownHeader.Font.Style = []
      ControlLook.DropDownHeader.Visible = True
      ControlLook.DropDownHeader.Buttons = <>
      ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
      ControlLook.DropDownFooter.Font.Color = clWindowText
      ControlLook.DropDownFooter.Font.Height = -11
      ControlLook.DropDownFooter.Font.Name = 'MS Sans Serif'
      ControlLook.DropDownFooter.Font.Style = []
      ControlLook.DropDownFooter.Visible = True
      ControlLook.DropDownFooter.Buttons = <>
      Filter = <>
      FilterDropDown.Font.Charset = DEFAULT_CHARSET
      FilterDropDown.Font.Color = clWindowText
      FilterDropDown.Font.Height = -11
      FilterDropDown.Font.Name = 'MS Sans Serif'
      FilterDropDown.Font.Style = []
      FilterDropDownClear = '(All)'
      FilterEdit.TypeNames.Strings = (
        'Starts with'
        'Ends with'
        'Contains'
        'Not contains'
        'Equal'
        'Not equal'
        'Larger than'
        'Smaller than'
        'Clear')
      FixedColWidth = 206
      FixedFont.Charset = DEFAULT_CHARSET
      FixedFont.Color = clWindowText
      FixedFont.Height = -11
      FixedFont.Name = 'Tahoma'
      FixedFont.Style = [fsBold]
      FloatFormat = '%.2f'
      HoverButtons.Buttons = <>
      HoverButtons.Position = hbLeftFromColumnLeft
      HTMLSettings.ImageFolder = 'images'
      HTMLSettings.ImageBaseName = 'img'
      PrintSettings.DateFormat = 'dd/mm/yyyy'
      PrintSettings.Font.Charset = DEFAULT_CHARSET
      PrintSettings.Font.Color = clWindowText
      PrintSettings.Font.Height = -11
      PrintSettings.Font.Name = 'MS Sans Serif'
      PrintSettings.Font.Style = []
      PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
      PrintSettings.FixedFont.Color = clWindowText
      PrintSettings.FixedFont.Height = -11
      PrintSettings.FixedFont.Name = 'MS Sans Serif'
      PrintSettings.FixedFont.Style = []
      PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
      PrintSettings.HeaderFont.Color = clWindowText
      PrintSettings.HeaderFont.Height = -11
      PrintSettings.HeaderFont.Name = 'MS Sans Serif'
      PrintSettings.HeaderFont.Style = []
      PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
      PrintSettings.FooterFont.Color = clWindowText
      PrintSettings.FooterFont.Height = -11
      PrintSettings.FooterFont.Name = 'MS Sans Serif'
      PrintSettings.FooterFont.Style = []
      PrintSettings.PageNumSep = '/'
      SearchFooter.Font.Charset = DEFAULT_CHARSET
      SearchFooter.Font.Color = clWindowText
      SearchFooter.Font.Height = -11
      SearchFooter.Font.Name = 'MS Sans Serif'
      SearchFooter.Font.Style = []
      SearchFooter.ResultFormat = '(%d of %d)'
      ShowDesignHelper = False
      SortSettings.DefaultFormat = ssAutomatic
      SortSettings.Column = 0
      SortSettings.Show = True
      Version = '8.2.2.0'
      ColWidths = (
        206
        64
        64
        13
        65
        34
        26
        29
        29
        64)
      RowHeights = (
        21
        21
        21
        21
        21)
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 648
      Height = 28
      Align = alTop
      BevelOuter = bvNone
      Color = clWhite
      FullRepaint = False
      ParentBackground = False
      TabOrder = 1
      DesignSize = (
        648
        28)
      object lData: THTMLabel
        Left = 8
        Top = 8
        Width = 625
        Height = 17
        Anchors = [akLeft, akTop, akRight]
        HTMLText.Strings = (
          '...')
        Transparent = True
        Version = '1.9.2.6'
      end
    end
  end
  object ilExplore: TImageList
    Left = 858
    Top = 17
    Bitmap = {
      494C010101000800140010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000A2CAEE0076B2E6003E91
      DB00348CD900348CD900348CD900348CD900348CD900348CD900348CD900348C
      D900348BD900398FDA0085B9E900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000004799DD00DEF1FA00A8DD
      F4009EDBF40096DAF3008ED8F30086D7F3007FD4F20079D3F20072D2F1006CD0
      F10069CFF100C2EAF8003F95DB00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000003B97DB00EFFAFE00A1E9
      F90091E5F80081E1F70072DEF60063DAF50054D7F40047D3F30039D0F2002ECD
      F10026CBF000CAF2FB003B97DB00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000003C9DDB00F2FAFD00B3ED
      FA00A4E9F90095E6F80085E2F70076DEF60065DBF50057D7F40049D4F3003BD1
      F20030CEF100CCF2FB003B9BDB00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000003BA3DB00F6FCFE00C8F2
      FC00B9EFFB00ACECFA009CE8F9008BE3F7007CE0F6006CDCF6005DD9F5004FD6
      F40044D3F300D0F3FC003BA2DB00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000003BA8DB00FEFFFF00F8FD
      FF00F6FDFF00F5FCFF00F3FCFE00D8F6FC0094E6F80085E3F70076DFF60068DB
      F5005CD8F400D7F4FC003BA7DB00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000039ADDB00E8F6FB0094D4
      EF0088CEEE0073C1E900C9E9F600F2FCFE00F3FCFE00F2FCFE00F0FCFE00EFFB
      FE00EEFBFE00FEFFFF003CAEDB00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000040AEDC00F1FAFD0094DE
      F50093DCF40081D5F2006ACAED006CCBEA0085D3EF0080D2EF007AD0EF0076CF
      EE0072CFEE00E9F7FB003EB2DC00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000041B4DC00F7FCFE008EE4
      F80091DEF5009FE0F500ACE1F600EFFBFE00F4FDFE00F3FCFE00F1FCFE00EFFB
      FE00EEFBFE00FAFDFF0058BCE000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000003CB5DB00FDFEFE00FEFF
      FF00FEFEFF00FDFEFF00FEFFFF00EAF7FB006EC8E5006FC9E4006FC9E4006FC9
      E4007DCFE70084D0E800BAE5F200000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000059C2E00061C3E20063C4
      E30063C4E30063C4E30062C4E30056C0E000EDF8FC00F3FAFD00F3FAFD00F3FA
      FD00F3FAFD00F3FBFD00FCFEFE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFF000000000000FFFF000000000000
      8001000000000000800100000000000080010000000000008001000000000000
      8001000000000000800100000000000080010000000000008001000000000000
      800100000000000080010000000000008001000000000000FFFF000000000000
      FFFF000000000000FFFF00000000000000000000000000000000000000000000
      000000000000}
  end
end
