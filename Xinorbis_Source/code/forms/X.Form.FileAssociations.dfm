object frmFileAssociations: TfrmFileAssociations
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 436
  ClientWidth = 728
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object lCategory: TLabel
    Left = 17
    Top = 8
    Width = 4
    Height = 13
    Caption = '.'
  end
  object Bevel7: TBevel
    Left = 8
    Top = 391
    Width = 712
    Height = 4
    Shape = bsTopLine
  end
  object cbFACategories: TComboBox
    Left = 17
    Top = 24
    Width = 209
    Height = 21
    Style = csDropDownList
    TabOrder = 0
    OnChange = cbFACategoriesChange
  end
  object GroupBox2: TGroupBox
    Left = 57
    Top = 67
    Width = 521
    Height = 60
    TabOrder = 1
    object sCat1: TShape
      Tag = 1
      Left = 114
      Top = 16
      Width = 47
      Height = 31
      Cursor = crHandPoint
      Hint = 'click to change the selected categories colour'
      OnMouseDown = sCat1MouseDown
    end
    object sbRenameCategory: TSpeedButton
      Tag = 2
      Left = 351
      Top = 18
      Width = 157
      Height = 22
      Hint = 'rename category'
      GroupIndex = 1
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFEFECE4
        E5DFD8E2DCD5E6DED7E7DDD6E8DCD6EADCD6ECDCD6ECDCD6EEDBD6EEDBD6ECDC
        D6EADCD6EADCD6FF00FFFF00FFEAEAEADEDEDEDBDBDBDDDDDDDCDCDCDBDBDBDC
        DCDCDBDBDBDCDCDCDCDCDCDADADADCDCDCDBDBDBDBDBDBFF00FFEAE1D8CAC1B8
        B6ABA3B4A79FBBABA4BBA9A2BCA9A2BCA9A2BEA8A2C0A8A2C0A8A2C0A8A2C0A8
        A2BEA8A2FF00FFBEA8A2DFDFDFBFBFBFAAAAAAA7A7A7AAAAAAA8A8A8A9A9A9A9
        A9A9A8A8A8A9A9A9A8A8A8A8A8A8A8A8A8A8A8A8FF00FFA8A8A8EFE3D9D1C1B5
        C1ADA2C4B0A5CEB9B1C6B3ABC5B3ACC3B3ACC3B3ACC6B3ACC8B2ACCCB2ABCCB2
        ABCCB3A9CCB3A9FF00FFE1E1E1BEBEBEACACACAEAEAEB8B8B8B3B3B3B3B3B3B3
        B3B3B2B2B2B3B3B3B2B2B2B2B2B2B2B2B2B3B3B3B2B2B2FF00FFF1E1D4D7BDAD
        FEE0CFFFE3D4EFD8C9F3E5D9FFFFF7F1F2E8FFFFF9FDFBF1FFF6ECFFF1E6EFDA
        CBF7E1CFFF00FFF9E1CDDFDFDFBBBBBBDFDFDFE1E1E1D6D6D6E3E3E3FEFEFEF1
        F1F1FEFEFEF9F9F9F4F4F4EFEFEFD9D9D9DEDEDEFF00FFDFDFDFEBDACDC3A594
        FFE0CCFFE7D4FDE5D3FFFFF3090900000400EEF7ED070B00070300FFFCEEFFED
        DCFAE5D0FCE6CDFF00FFD9D9D9A3A3A3DEDEDEE4E4E4E2E2E2FDFDFD06060602
        0202F4F4F4080808030303F9F9F9EBEBEBE2E2E2E2E2E2FF00FFEEDDD0AB8D7C
        FFE8D6FFEADAFFEFDFEBDFD3FFFFF5F8FDF4000500F5F6ECFEF8EDFFFCF0E6D2
        C1FEE9D4FF00FFFFE9D3DBDBDB8C8C8CE6E6E6E7E7E7EDEDEDDDDDDDFDFDFDFC
        FCFC030303F3F3F3F7F7F7F9F9F9CFCFCFE6E6E6FF00FFE6E6E6F8E7DA8E7162
        FFE7D4FAD9C9F3DACAFDEFE3E1DFD5FFFFFB0B0F09FFFFF9E6E0D5FFF6EAFFF4
        E5FFEAD8FFEBD5FF00FFE5E5E5707070E5E5E5D8D8D8D8D8D8EEEEEEDDDDDDFE
        FEFE0D0D0DFEFEFEDDDDDDF5F5F5F1F1F1E8E8E8E7E7E7FF00FFF8E7DA6F5243
        FDDCCCE7C8B9DEC4B6C7B8AFB4AFA6FFFFFB000200FDFAF2FFFBF2F3E2D9F6E0
        D4FFECDCFF00FFFFEDDBE5E5E5505050DADADAC7C7C7C3C3C3B7B7B7AEAEAEFF
        FFFF010101F8F8F8F9F9F9E2E2E2DFDFDFEAEAEAFF00FFEAEAEAF1E1D55D4234
        FFE7D6FEE1D2F7E0D1F3E4DBFFFFF8FCF9F50D0A06FFFFFBE0D7CEF0DFD6FFFC
        EFFFEFDFFFF0DEFF00FFE0E0E0424242E6E6E6E0E0E0DEDEDEE3E3E3FEFEFEF8
        F8F8080808FEFEFED5D5D5DFDFDFF9F9F9EDEDEDEDEDEDFF00FFF0DFD6584132
        FFF5E5FFFDEFFFFAEEFFF9F2FFFBF4FFFFFC050000FFFFFBFFFFF9FFFBF4FFF2
        E7FFF3E4FF00FFFFF3E4DEDEDE3F3F3FF3F3F3FAFAFAF8F8F8F7F7F7FAFAFAFE
        FEFE000000FEFEFEFDFDFDFAFAFAF1F1F1F1F1F1FF00FFF0F0F0EFDFD8513E31
        FFF0E1FFFAEBFFF0E3FFFEF60B00000A0202FFF9F90900000B0000FFFFF8FDEC
        E3FFF6E9FFF6E9FF00FFDEDEDE3E3E3EEEEEEEF7F7F7EEEEEEFDFDFD00000003
        0303FAFAFA000000000000FEFEFEEBEBEBF3F3F3F4F4F4FF00FFF4E7DF5E4E42
        F9E8DBFFFEF1FFF3E7FFFAF4FFF9F7FFF9FAFFF9FAFFF9F9FFF9F7FFFAF4FFFC
        F2FFF6EDFF00FFFFF7EBE6E6E64D4D4DE6E6E6FBFBFBF1F1F1F9F9F9F9F9F9FA
        FAFAFAFAFAF9F9F9F9F9F9F9F9F9FAFAFAF5F5F5FF00FFF5F5F5F7EDE64C4036
        564B3D4C41334F453B4A4039483F3C483D3F463D40483D3F483F3C4A40394A41
        384D40384D4137FF00FFEDEDED3F3F3F4A4A4A3F3F3F4444444040403E3E3E3F
        3F3F3E3E3E3F3F3F3F3F3F3E3E3E404040404040404040FF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = sbRenameCategoryClick
    end
    object lFAColour: TLabel
      Left = 16
      Top = 24
      Width = 4
      Height = 13
      Caption = '.'
    end
  end
  object gbAFE: TGroupBox
    Left = 57
    Top = 133
    Width = 663
    Height = 238
    TabOrder = 2
    object sbAdd: TSpeedButton
      Left = 121
      Top = 25
      Width = 29
      Height = 22
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF569C5E3F8F493C8D454C9553FF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8F8F8F7F
        7F7F7D7D7D888888FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF57A0644199507DC28F96D0A696CFA678BE89368D42418D48FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF939393898989B5B5B5C5
        C5C5C4C4C4B0B0B07D7D7D7F7F7FFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF55A06464B478A8DBB587CC9866BC7D64BA7C86CB98A5D9B458AA6B3586
        3DFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF929292A5A5A5D1D1D1BFBFBFAD
        ADADABABABBEBEBECFCFCF9B9B9B777777FF00FFFF00FFFF00FFFF00FFFF00FF
        67AC766AB97DA8DBB260BC775CBA7359B87059B56F58B56F5BB774A5D9B35AAA
        6C428F49FF00FFFF00FFFF00FFFF00FF9F9F9FAAAAAAD0D0D0ABABABA9A9A9A7
        A7A7A4A4A4A4A4A4A7A7A7CFCFCF9B9B9B808080FF00FFFF00FFFF00FFFF00FF
        53AB68AADDB464C1795FBE7160BC77FFFFFFFFFFFF59B87058B56E5CB774A6DA
        B4388F43FF00FFFF00FFFF00FFFF00FF9B9B9BD2D2D2B0B0B0ACACACABABABFF
        FFFFFFFFFFA7A7A7A4A4A4A7A7A7D0D0D07F7F7FFF00FFFF00FFFF00FF77B888
        8ACC9889D3966BC67A63C17055AB65FFFFFFFFFFFF59B87059B8705BB97285CC
        977BBE8D4D9655FF00FFFF00FFACACACBFBFBFC4C4C4B5B5B5AFAFAF9B9B9BFF
        FFFFFFFFFFA7A7A7A7A7A7A8A8A8BFBFBFB1B1B1888888FF00FFFF00FF6AB27F
        A9DDB37DCF8A75CC81FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF59B87067BE
        7D9CD4AB3B8C44FF00FFFF00FFA4A4A4D2D2D2BEBEBEBABABAFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFA7A7A7AEAEAEC9C9C97D7D7DFF00FFFF00FF6EB583
        B6E2BE8BD5977AC986FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF59B87069C1
        7E9DD4AA3F8F49FF00FFFF00FFA8A8A8D9D9D9C6C6C6B9B9B9FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFA7A7A7B1B1B1C9C9C9808080FF00FFFF00FF82BF95
        ACDDB6A6DFAF81CB8C7CC9866EBD79FFFFFFFFFFFF5BAC6A60BC775CBA738BD1
        9980C592589E61FF00FFFF00FFB4B4B4D3D3D3D3D3D3BBBBBBB9B9B9ADADADFF
        FFFFFFFFFF9C9C9CABABABA9A9A9C3C3C3B8B8B8919191FF00FFFF00FFFF00FF
        85C797D2EED795D9A08AD3947FC889FFFFFFFFFFFF79CD856BC37C6FC77EACDF
        B5459E57FF00FFFF00FFFF00FFFF00FFBBBBBBE8E8E8CBCBCBC4C4C4B8B8B8FF
        FFFFFFFFFFBCBCBCB2B2B2B6B6B6D4D4D48E8E8EFF00FFFF00FFFF00FFFF00FF
        7FBF93AADAB7D8F1DC92D89D88CD9384CC8E8BD4968AD49583D28EAFE0B76BB9
        7D5BA367FF00FFFF00FFFF00FFFF00FFB4B4B4D1D1D1EBEBEBCACACABFBFBFBD
        BDBDC5C5C5C5C5C5C1C1C1D5D5D5AAAAAA959595FF00FFFF00FFFF00FFFF00FF
        FF00FF76BB8CAFDCBBDCF2E0B6E4BD9BDBA596D9A0A5DFAFC0E8C579C28A58A2
        66FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFAFAFAFD3D3D3EDEDEDDADADACE
        CECECBCBCBD3D3D3DFDFDFB4B4B4949494FF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF7FBF9394CEA4C3E6CBCFEBD4C9E9CEAFDDB86DB97F68AE78FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFB3B3B3C3C3C3DFDFDFE5
        E5E5E2E2E2D3D3D3ABABABA0A0A0FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF82C09571B7866EB58279B98AFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFB5B5B5AA
        AAAAA7A7A7ADADADFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = sbAddClick
    end
    object sbFADelete: TSpeedButton
      Left = 153
      Top = 25
      Width = 33
      Height = 22
      Hint = 'delete selected extensions'
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF546BC73F59C03A53BF4C67C2FF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8888887B
        7B7B777777848484FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF5566CC3C52CC757AE88F92EE8F92EE7178E4334DC1405CBEFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8787877B7B7B9C9C9CAD
        ADADADADAD9999997373737C7C7CFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF5160CD5C65E0A1A6F57E86EF5B63E9595DE77D84EE9EA0F4515DD73452
        BAFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8484848D8D8DBBBBBBA5A5A590
        90908C8C8CA4A4A4B7B7B7858585747474FF00FFFF00FFFF00FFFF00FFFF00FF
        6571D4616BE3A1ACF5545FEC505CEA4D59E94E59E64C56E65056E69EA2F45460
        D6405CBFFF00FFFF00FFFF00FFFF00FF919191919191BFBFBF8F8F8F8D8D8D8B
        8B8B8A8A8A888888888888B8B8B88686867D7D7DFF00FFFF00FFFF00FFFF00FF
        4B56DBA2ABF65664F05266EE4D59E94D59E94D59E94D59E94C58E6525AE69FA3
        F53450C4FF00FFFF00FFFF00FFFF00FF838383BFBFBF9393939393938B8B8B8B
        8B8B8B8B8B8B8B8B8989898A8A8AB9B9B9767676FF00FFFF00FFFF00FF7378DD
        818CEE7E91F75D73F34D59E94D59E94D59E94D59E94D59E94D59E94F5BE97B83
        F0757BE24C64C4FF00FFFF00FF999999A8A8A8AEAEAE9B9B9B8B8B8B8B8B8B8B
        8B8B8B8B8B8B8B8B8B8B8B8C8C8CA4A4A49A9A9A848484FF00FFFF00FF6569DB
        A1ABF77086F86882F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4D59E95C66
        EA969CF13956BEFF00FFFF00FF8E8E8EBFBFBFA8A8A8A5A5A5FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF8B8B8B919191B3B3B3787878FF00FFFF00FF696EDC
        AFB9F97F93FA7085F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4D59E95E6A
        EE969DF13D55C0FF00FFFF00FF919191CACACAB0B0B0A4A4A4FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF8B8B8B959595B4B4B4787878FF00FFFF00FF7C7FE3
        A5AFF59DABFA778CF0545FEC545FEC545FEC545FEC545FEC545FEC6377F2818E
        F4787FE9566BC9FF00FFFF00FF9F9F9FC2C2C2C0C0C0A8A8A88F8F8F8F8F8F8F
        8F8F8F8F8F8F8F8F8F8F8F9D9D9DACACAC9F9F9F898989FF00FFFF00FFFF00FF
        7D83EACDD4FC8B9DFA7E93F7758AEE6C84F66C84F66C84F66C84F66379F3A4AF
        F83E4FD0FF00FFFF00FFFF00FFFF00FFA2A2A2DEDEDEB7B7B7AFAFAFA6A6A6A6
        A6A6A6A6A6A6A6A6A6A6A69F9F9FC2C2C27B7B7BFF00FFFF00FFFF00FFFF00FF
        7978E3A3A7F3D4DBFD879AFA7F91F07A8EF17F94F87E92F9768CF8A8B6F8636E
        E35868CDFF00FFFF00FFFF00FFFF00FF9B9B9BBBBBBBE3E3E3B5B5B5ACACACAA
        AAAAB0B0B0AFAFAFABABABC7C7C7939393888888FF00FFFF00FFFF00FFFF00FF
        FF00FF706FE1AAADF2D8DCFDAEBAFA91A3FA8B9DFA9CA9FBBAC7FC707BE95462
        CEFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF959595BFBFBFE4E4E4CACACABB
        BBBBB7B7B7BFBFBFD4D4D49C9C9C858585FF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF7979E28E93EDBEC3F8CCD3F9C4CBF9AAB4F46670E2646ED6FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9B9B9BADADADD0D0D0DC
        DCDCD7D7D7C5C5C59393938F8F8FFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF7D7FE26A6BDE686BDC7479DEFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9F9F9F90
        90909090909A9A9AFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = sbFADeleteClick
    end
    object sbSearchFileExt: TSpeedButton
      Left = 211
      Top = 24
      Width = 33
      Height = 22
      Hint = 'find'
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF006494BA0022679D0081A8C600FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF006F9CC200558DBC0089B5DD00185F9700FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF007BA4
        CA006497C5009DC1E4006699C7003171A500FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00E8CFBA00DBB29200D3A68000D0A17C00D2A68500AEA1990075A2
        CC00ABCBE80076A4CE00407BAF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00E8CAB000E8C9AE00F5E1CD00F7E5D300F7E5D100F3DDC800DFBA9C00C7A8
        910086AED5005087BB00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00F1DB
        C800EDD0B700F8E8D900F5DEC800F3D8BD00F3D6BB00F4DBC200F7E4D200DFBB
        9D00A0979500FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00EECE
        B200F7E7D700F6E1CC00F4DBC200F4DAC000F3D8BD00F3D7BB00F4DBC200F3DE
        C900D2A88700FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00F0CE
        AF00F9ECDF00F5DFC800F5DDC600F4DCC300F4DAC100F3D9BE00F3D7BD00F8E6
        D300D3A68000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00F4D3
        B500F9EDE100F6E1CC00F5DFC900F5DEC700F4DCC400F4DBC200F4DAC000F8E7
        D600D7AB8700FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00F8DB
        C100F9EBDE00F7E7D600F6E1CC00F5E0CA00F5DEC800F5DDC500F6E1CB00F5E2
        D000DFB99900FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FCEA
        D800F8E2CC00FAEEE300F7E7D600F6E2CE00F6E1CB00F6E3D000F9EADD00ECCF
        B500ECD4BF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FBE4CE00F9E2CD00FAECDE00F9EEE200F9EDE200F8E9DA00F0D5BD00EDD0
        B700FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FCEAD900FADDC200F6D6B900F4D3B500F3D4B800F5E0CD00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      OnClick = sbSearchFileExtClick
    end
    object miFECut: TSpeedButton
      Left = 17
      Top = 209
      Width = 25
      Height = 22
      Hint = 'cut'
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFAF7A51B87A45AF784DFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FF787878767676767676FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFB4825DE7B263C69D61DDAB62B07A51FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF80
        8080A9A9A9969696A3A3A3787878FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFCB9F5ED8A65BB88A5FFF00FFB27A4DD2A25AFF00FFBAA484B57741FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9797979E9E9E878787FF00FF77
        77779A9A9AFF00FFA0A0A0737373FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        BC8E56DAAC69C09E6CECB666B48455B37847C79A59FF00FFC0B19BB77840FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF888888A5A5A5999999ADADAD81818175
        7575929292FF00FFAEAEAE747474FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        C19053C1A377FF00FFC1A986E7B066CAA275E5B167AE8560C4A16CB27643FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF8989899E9E9EFF00FFA5A5A5A8A8A89C
        9C9CA8A8A88383839B9B9B737373FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        BC9A75D6A65FFF00FFFF00FFE4AD60DCBD9BEFCDA5EFB767D8A65DFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF9797979E9E9EFF00FFFF00FFA5A5A5B9
        B9B9C8C8C8AEAEAE9E9E9EFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFBC905DDCAA60D2A35CEAB365D8BA99F8EBE1C3A883FF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8B8B8BA2A2A29B9B9BAAAAAAB6
        B6B6EAEAEAA4A4A4FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFBD9A76BF9563C19E77C9AB85F0E0D0C7AA83FF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9797979090909B9B9BA7
        A7A7DEDEDEA5A5A5FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFD7C2A5F5E9DDE2CDB4D3BC9CFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFBE
        BEBEE8E8E8CACACAB7B7B7FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFD6C0A3F1E2D3D1B692F5E9DCD8C5AAFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFBC
        BCBCE1E1E1B1B1B1E8E8E8C2C2C2FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFD6C1A4EDDECED7C4A8D8C2A6E7D6C4E7DC
        CBFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFBE
        BEBEDCDCDCC1C1C1BFBFBFD5D5D5DADADAFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFD7C4A9E6D4C0FF00FFFF00FFD9C3A7D8C0
        A3FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC1
        C1C1D2D2D2FF00FFFF00FFBEBEBEBCBCBCFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFD9C6ABDEC8AEFF00FFFF00FFFF00FFD6BE
        9ECEB593FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC3
        C3C3C5C5C5FF00FFFF00FFFF00FFB9B9B9B0B0B0FF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFDAC7AED6BEA0FF00FFFF00FFFF00FFFF00
        FFC6A880FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC5
        C5C5B9B9B9FF00FFFF00FFFF00FFFF00FFA4A4A4FF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFDAC9B0D1B794FF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC6
        C6C6B2B2B2FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC8AD87FF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFA9A9A9FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = miFECutClick
    end
    object miFEPaste: TSpeedButton
      Left = 41
      Top = 209
      Width = 25
      Height = 22
      Hint = 'paste'
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFD39570CC8357C87646CA7B4ECB7B4ECA7B4ECA7B
        4ECA7B4ECA8155CD865CFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF94949482
        82827575757B7B7B7B7B7B7B7B7B7B7B7B7A7A7A808080848484FF00FF4A80AB
        206398206398206398206398C98F67FCF3ECFAF1E8FAF0E7FBF1E9FBF2EAFBF2
        EAFBF2EBFDF4EECB8358FF00FF8A8A8A6F6F6F6F6F6F6F6F6F6F6F6F8C8C8CF3
        F3F3F0F0F0EFEFEFF0F0F0F1F1F1F1F1F1F2F2F2F4F4F48181815588B174ADD8
        7BB2DD78AEDC75AADA74A9DADAA97DEFF1E7FFE9D9FFEADBFFE9D9FFE7D7FFE5
        D2FFE2CBEFF2E8CE8156919191B6B6B6BBBBBBB7B7B7B4B4B4B3B3B3A4A4A4EF
        EFEFE7E7E7E8E8E8E7E7E7E5E5E5E3E3E3DFDFDFF0F0F080808020639880B9E1
        5395D15092D04E8ECE4D8CCDD6A97DFBF5EEFFE9D9FFEADBFFE9D9FFE7D7FFE5
        D2FFE2CBFBF6EFCC83566F6F6FC0C0C0A2A2A2A0A0A09D9D9D9B9B9BA4A4A4F4
        F4F4E7E7E7E8E8E8E7E7E7E5E5E5E3E3E3DFDFDFF5F5F581818120639884BFE2
        569AD35397D15092CF5091CFD6A97DFFF7F1FFE9D9FFEADBFFE9D9FFE7D7FFE5
        D2FFE2CBFFF7F1CB85566F6F6FC5C5C5A6A6A6A4A4A4A0A0A09F9F9FA4A4A4F7
        F7F7E7E7E7E8E8E8E7E7E7E5E5E5E3E3E3DFDFDFF7F7F782828220639888C4E6
        599FD6569BD35397D15395D1D7AC7FFFF7F0FFE7D5FDE7D6FDE6D4FCE4D0FBE3
        CBFADCC2FEF3E8CC86576F6F6FCACACAAAAAAAA7A7A7A4A4A4A2A2A2A7A7A7F7
        F7F7E5E5E5E5E5E5E4E4E4E1E1E1E0E0E0D9D9D9F2F2F28383832063988BC9E7
        5CA5D759A0D5579CD3569AD3D7AC7FFFF7F2FEE7D5FEE7D5FDE5D1FAE0CAF9DE
        C4F7D9BCFDF2E7CC87586F6F6FCDCDCDAFAFAFABABABA7A7A7A6A6A6A7A7A7F7
        F7F7E5E5E5E5E5E5E2E2E2DDDDDDDBDBDBD5D5D5F1F1F184848420639891CDE9
        5FA9D95DA5D85AA0D6599FD6D8AD81FEF7F1FCE5D2FCE4D1FBE2CCF9DDC4F6D7
        BBF3D1AFFAEFE4CC87596F6F6FD1D1D1B2B2B2AFAFAFABABABAAAAAAA8A8A8F7
        F7F7E3E3E3E2E2E2DFDFDFDADADAD3D3D3CDCDCDEEEEEE84848420639898D2EB
        65AEDA60AAD95DA6D85CA5D7D9AF84FEF6F0FCE2CDFCE3CDFADFC8F7D9BCF5E9
        DDFAF3EBFBF8F3CA83546F6F6FD5D5D5B6B6B6B3B3B3B0B0B0AFAFAFAAAAAAF6
        F6F6E0E0E0E0E0E0DCDCDCD5D5D5E8E8E8F2F2F2F7F7F78080802063989ED6ED
        6BB2DC66AFDC60AADA5FA9D9D9AF84FEF5EDFCDEC5FBE0C7F9DCC2F5D3B4FEF9
        F3FAE2C4ECC193D2986E6F6F6FD9D9D9B9B9B9B7B7B7B3B3B3B2B2B2AAAAAAF4
        F4F4DBDBDBDDDDDDD9D9D9CFCFCFF9F9F9DEDEDEBBBBBB969696206398A5DAEF
        6FB5DE68B0DC60A9D95FA9D9D7AD81FFFFFEFDF3E9FDF3EAFCF2E8FAEFE3FAF2
        E7EABB88D39469FF00FF6F6F6FDDDDDDBCBCBCB8B8B8B2B2B2B2B2B2A8A8A8FF
        FFFFF2F2F2F2F2F2F1F1F1EEEEEEF1F1F1B5B5B5919191FF00FF206398AADDF1
        74B9E070B6DF6CB3DD6BB2DCD9AF84D7AE81D7AC7FD7AC7FCCA070CD9F71B38F
        67D39B71FF00FFFF00FF6F6F6FE0E0E0C0C0C0BDBDBDBABABAB9B9B9AAAAAAA8
        A8A8A7A7A7A7A7A79A9A9A9A9A9A8A8A8A989898FF00FFFF00FF206398B0E1F2
        79BDE24498DD4497DC4396DC4296DC4295DC4195DB539ED489C6E6206398FF00
        FFFF00FFFF00FFFF00FF6F6F6FE3E3E3C3C3C3A8A8A8A7A7A7A6A6A6A6A6A6A6
        A6A6A5A5A5A9A9A9CBCBCB6F6F6FFF00FFFF00FFFF00FFFF00FF3B76A595C9E0
        AEE2F24E9DDFB5EEFD75D4F075D4F0B5EEFD4B9BDE8ECBE993CDE92A6A9DFF00
        FFFF00FFFF00FFFF00FF818181CCCCCCE4E4E4ACACACEFEFEFD7D7D7D7D7D7EF
        EFEFAAAAAACFCFCFD1D1D1767676FF00FFFF00FFFF00FFFF00FFFF00FF6392B7
        2063983775A4B6EFFE80DBF380DBF3B6EFFE2E6EA12063986F9ABCFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FF9A9A9A6F6F6F7F7F7FF0F0F0DDDDDDDDDDDDF0
        F0F07979796F6F6FA2A2A2FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF2063982063982063982063982063982D6C9EFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF6F6F6F6F6F6F6F6F6F6F6F6F6F
        6F6F777777FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = miFEPasteClick
    end
    object sbRD: TSpeedButton
      Left = 537
      Top = 210
      Width = 113
      Height = 21
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFAEAEAE
        3E3E3E171717FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FF696969C9C9C9959595161616FF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF696969
        DEDEDE313131454545151515FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF4343438181813535353E3E3E151515FF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF4747478383833737373F3F3F151515FF00FFFF00FFFF00FFBAE9FBFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF5858588484843737373F
        3F3F151515FF00FFC3EDFC48C7F5FF00FFFF00FFB7E8FAFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FF4E4E4E6767673737374040401616166CD4F703B4F1C6EE
        FC30C0F496DEF9FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF4E4E4E67
        67673838384242424D4D4D4BCCF519BDF20DB7F2FF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF5BD1F74F4F4F6767678C8C8CA9A9A94197B477D9
        F803B6F133C4F480D9F8FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF59
        D1F64C4C4CCACACAF7F7F7D3D3D34BA1BF74D9F80CB8F2C7EFFCFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FF90E0FA51CFF64FA5C2F8F8F8FEFEFE5AB0
        CD6AD6F72AC3F3FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF62D3F825
        C1F54ECEF783DDF84EA4C25BB1CF68BFDC41CAF608BCF168D6F7FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF95E1FA5AD0F76DD7F87DDCF84BCD
        F619BFF3FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FF54CFF767D4F867D3F850CEF798E3FA27C3F4ACE8FBFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA9E6FBFF00FFC1EEFC53CEF7FF00
        FFFF00FFA5E6FAFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFACE8FBFF00FFFF00FFFF00FFFF00FF}
      OnClick = sbRDClick
    end
    object lbExtlist: TListBox
      Left = 15
      Top = 59
      Width = 634
      Height = 145
      Columns = 5
      ItemHeight = 13
      MultiSelect = True
      Sorted = True
      TabOrder = 0
      OnClick = lbExtlistClick
    end
    object bImportLIst: TBitBtn
      Left = 89
      Top = 210
      Width = 75
      Height = 21
      TabOrder = 1
      OnClick = bImportLIstClick
    end
    object bExportList: TBitBtn
      Left = 169
      Top = 210
      Width = 75
      Height = 21
      TabOrder = 2
      OnClick = bExportListClick
    end
    object eAdd: TEdit
      Left = 15
      Top = 25
      Width = 100
      Height = 21
      TabOrder = 3
      OnChange = eAddChange
      OnKeyPress = eAddKeyPress
    end
  end
  object bSave: TBitBtn
    Left = 472
    Top = 400
    Width = 126
    Height = 25
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
    ModalResult = 1
    TabOrder = 3
  end
  object bCancel: TBitBtn
    Left = 604
    Top = 401
    Width = 116
    Height = 25
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
    ModalResult = 2
    TabOrder = 4
  end
  object bHelp: TBitBtn
    Left = 7
    Top = 401
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
    TabOrder = 5
    OnClick = bHelpClick
  end
  object cdMain: TColorDialog
    Options = [cdFullOpen]
    Left = 396
    Top = 398
  end
end
