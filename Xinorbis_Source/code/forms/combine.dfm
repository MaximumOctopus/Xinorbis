object frmCombine: TfrmCombine
  Left = 711
  Top = 357
  BorderStyle = bsDialog
  ClientHeight = 365
  ClientWidth = 449
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
  DesignSize = (
    449
    365)
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 361
    Width = 449
    Height = 4
    Align = alBottom
    Shape = bsBottomLine
    ExplicitTop = 341
    ExplicitWidth = 369
  end
  object Bevel2: TBevel
    Left = 0
    Top = 0
    Width = 449
    Height = 4
    Align = alTop
    Shape = bsTopLine
    ExplicitWidth = 369
  end
  object Bevel3: TBevel
    Left = 445
    Top = 4
    Width = 4
    Height = 357
    Align = alRight
    Shape = bsRightLine
    ExplicitLeft = 365
    ExplicitHeight = 337
  end
  object Bevel4: TBevel
    Left = 0
    Top = 4
    Width = 4
    Height = 357
    Align = alLeft
    Shape = bsLeftLine
    ExplicitHeight = 337
  end
  object Bevel5: TBevel
    Left = 8
    Top = 323
    Width = 433
    Height = 9
    Anchors = [akLeft, akRight]
    Shape = bsTopLine
    ExplicitTop = 304
    ExplicitWidth = 353
  end
  object lChoose: TLabel
    Left = 8
    Top = 16
    Width = 3
    Height = 13
    Caption = '.'
  end
  object sbDrive2Add: TSpeedButton
    Left = 419
    Top = 34
    Width = 23
    Height = 22
    Hint = 'add this folder to the scan list'
    Anchors = [akTop, akRight]
    Flat = True
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFE5F0E7A0C8A6569C5E3F8F493C8D454C955398C19BE1EDE3FFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEEEEEEC1C1C18F8F8F7F
      7F7F7D7D7D888888B9B9B9EBEBEBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFC4DEC957A0644199507DC28F96D0A696CFA678BE89368D42418D48B9D5
      BCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD9D9D9939393898989B5B5B5C5
      C5C5C4C4C4B0B0B07D7D7D7F7F7FD0D0D0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      C6E0CC55A06464B478A8DBB587CC9866BC7D64BA7C86CB98A5D9B458AA6B3586
      3DB9D5BCFFFFFFFFFFFFFFFFFFFFFFFFDBDBDB929292A5A5A5D1D1D1BFBFBFAD
      ADADABABABBEBEBECFCFCF9B9B9B777777D0D0D0FFFFFFFFFFFFFFFFFFE9F3EB
      67AC766AB97DA8DBB260BC775CBA7359B87059B56F58B56F5BB774A5D9B35AAA
      6C428F49E2EEE3FFFFFFFFFFFFF1F1F19F9F9FAAAAAAD0D0D0ABABABA9A9A9A7
      A7A7A4A4A4A4A4A4A7A7A7CFCFCF9B9B9B808080ECECECFFFFFFFFFFFFAFD5B8
      53AB68AADDB464C1795FBE7160BC77FFFFFFFFFFFF59B87058B56E5CB774A6DA
      B4388F4397C19BFFFFFFFFFFFFCECECE9B9B9BD2D2D2B0B0B0ACACACABABABFF
      FFFFFFFFFFA7A7A7A4A4A4A7A7A7D0D0D07F7F7FB9B9B9FFFFFFFFFFFF77B888
      8ACC9889D3966BC67A63C17055AB65FFFFFFFFFFFF59B87059B8705BB97285CC
      977BBE8D4D9655FFFFFFFFFFFFACACACBFBFBFC4C4C4B5B5B5AFAFAF9B9B9BFF
      FFFFFFFFFFA7A7A7A7A7A7A8A8A8BFBFBFB1B1B1888888FFFFFFFFFFFF6AB27F
      A9DDB37DCF8A75CC81FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF59B87067BE
      7D9CD4AB3B8C44FFFFFFFFFFFFA4A4A4D2D2D2BEBEBEBABABAFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFA7A7A7AEAEAEC9C9C97D7D7DFFFFFFFFFFFF6EB583
      B6E2BE8BD5977AC986FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF59B87069C1
      7E9DD4AA3F8F49FFFFFFFFFFFFA8A8A8D9D9D9C6C6C6B9B9B9FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFA7A7A7B1B1B1C9C9C9808080FFFFFFFFFFFF82BF95
      ACDDB6A6DFAF81CB8C7CC9866EBD79FFFFFFFFFFFF5BAC6A60BC775CBA738BD1
      9980C592589E61FFFFFFFFFFFFB4B4B4D3D3D3D3D3D3BBBBBBB9B9B9ADADADFF
      FFFFFFFFFF9C9C9CABABABA9A9A9C3C3C3B8B8B8919191FFFFFFFFFFFFB8DCC4
      85C797D2EED795D9A08AD3947FC889FFFFFFFFFFFF79CD856BC37C6FC77EACDF
      B5459E57A1C9A7FFFFFFFFFFFFD5D5D5BBBBBBE8E8E8CBCBCBC4C4C4B8B8B8FF
      FFFFFFFFFFBCBCBCB2B2B2B6B6B6D4D4D48E8E8EC1C1C1FFFFFFFFFFFFECF6EF
      7FBF93AADAB7D8F1DC92D89D88CD9384CC8E8BD4968AD49583D28EAFE0B76BB9
      7D5BA367E6F1E8FFFFFFFFFFFFF4F4F4B4B4B4D1D1D1EBEBEBCACACABFBFBFBD
      BDBDC5C5C5C5C5C5C1C1C1D5D5D5AAAAAA959595EFEFEFFFFFFFFFFFFFFFFFFF
      D1E9D976BB8CAFDCBBDCF2E0B6E4BD9BDBA596D9A0A5DFAFC0E8C579C28A58A2
      66C5DECAFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5AFAFAFD3D3D3EDEDEDDADADACE
      CECECBCBCBD3D3D3DFDFDFB4B4B4949494DADADAFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFD1E9D97FBF9394CEA4C3E6CBCFEBD4C9E9CEAFDDB86DB97F68AE78C7E0
      CDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5B3B3B3C3C3C3DFDFDFE5
      E5E5E2E2E2D3D3D3ABABABA0A0A0DCDCDCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFECF6EFB9DDC582C09571B7866EB58279B98AB1D6BAE9F3EBFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4F4F4D6D6D6B5B5B5AA
      AAAAA7A7A7ADADADCFCFCFF1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    NumGlyphs = 2
    OnClick = sbDrive2AddClick
    ExplicitLeft = 339
  end
  object sbDelete: TSpeedButton
    Left = 10
    Top = 293
    Width = 35
    Height = 25
    Hint = 'remove all selected items from the scan list'
    Enabled = False
    Flat = True
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFE5E8F79EA9E1546BC73F59C03A53BF4C67C297A7DCE1E6F5FFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFECECECBCBCBC8888887B
      7B7B777777848484B8B8B8EBEBEBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFC3C9ED5566CC3C52CC757AE88F92EE8F92EE7178E4334DC1405CBEB9C4
      E7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD4D4D48787877B7B7B9C9C9CAD
      ADADADADAD9999997373737C7C7CCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      C5C9EF5160CD5C65E0A1A6F57E86EF5B63E9595DE77D84EE9EA0F4515DD73452
      BAB9C4E7FFFFFFFFFFFFFFFFFFFFFFFFD5D5D58484848D8D8DBBBBBBA5A5A590
      90908C8C8CA4A4A4B7B7B7858585747474CFCFCFFFFFFFFFFFFFFFFFFFE8EAF9
      6571D4616BE3A1ACF5545FEC505CEA4D59E94E59E64C56E65056E69EA2F45460
      D6405CBFE2E7F5FFFFFFFFFFFFEFEFEF919191919191BFBFBF8F8F8F8D8D8D8B
      8B8B8A8A8A888888888888B8B8B88686867D7D7DECECECFFFFFFFFFFFFACB0EA
      4B56DBA2ABF65664F05266EE4D59E94D59E94D59E94D59E94C58E6525AE69FA3
      F53450C496A6DCFFFFFFFFFFFFC3C3C3838383BFBFBF9393939393938B8B8B8B
      8B8B8B8B8B8B8B8B8989898A8A8AB9B9B9767676B7B7B7FFFFFFFFFFFF7378DD
      818CEE7E91F75D73F34D59E94D59E94D59E94D59E94D59E94D59E94F5BE97B83
      F0757BE24C64C4FFFFFFFFFFFF999999A8A8A8AEAEAE9B9B9B8B8B8B8B8B8B8B
      8B8B8B8B8B8B8B8B8B8B8B8C8C8CA4A4A49A9A9A848484FFFFFFFFFFFF6569DB
      A1ABF77086F86882F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4D59E95C66
      EA969CF13956BEFFFFFFFFFFFF8E8E8EBFBFBFA8A8A8A5A5A5FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFF8B8B8B919191B3B3B3787878FFFFFFFFFFFF696EDC
      AFB9F97F93FA7085F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4D59E95E6A
      EE969DF13D55C0FFFFFFFFFFFF919191CACACAB0B0B0A4A4A4FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFF8B8B8B959595B4B4B4787878FFFFFFFFFFFF7C7FE3
      A5AFF59DABFA778CF0545FEC545FEC545FEC545FEC545FEC545FEC6377F2818E
      F4787FE9566BC9FFFFFFFFFFFF9F9F9FC2C2C2C0C0C0A8A8A88F8F8F8F8F8F8F
      8F8F8F8F8F8F8F8F8F8F8F9D9D9DACACAC9F9F9F898989FFFFFFFFFFFFB5B5F0
      7D83EACDD4FC8B9DFA7E93F7758AEE6C84F66C84F66C84F66C84F66379F3A4AF
      F83E4FD0A0ABE1FFFFFFFFFFFFC8C8C8A2A2A2DEDEDEB7B7B7AFAFAFA6A6A6A6
      A6A6A6A6A6A6A6A6A6A6A69F9F9FC2C2C27B7B7BBCBCBCFFFFFFFFFFFFEBEBFB
      7978E3A3A7F3D4DBFD879AFA7F91F07A8EF17F94F87E92F9768CF8A8B6F8636E
      E35868CDE6E8F7FFFFFFFFFFFFF0F0F09B9B9BBBBBBBE3E3E3B5B5B5ACACACAA
      AAAAB0B0B0AFAFAFABABABC7C7C7939393888888EDEDEDFFFFFFFFFFFFFFFFFF
      CFCFF6706FE1AAADF2D8DCFDAEBAFA91A3FA8B9DFA9CA9FBBAC7FC707BE95462
      CEC3C9EEFFFFFFFFFFFFFFFFFFFFFFFFDCDCDC959595BFBFBFE4E4E4CACACABB
      BBBBB7B7B7BFBFBFD4D4D49C9C9C858585D5D5D5FFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFCFCFF67979E28E93EDBEC3F8CCD3F9C4CBF9AAB4F46670E2646ED6C6CA
      EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDCDCDC9B9B9BADADADD0D0D0DC
      DCDCD7D7D7C5C5C59393938F8F8FD6D6D6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFEBEBFBB6B6F07D7FE26A6BDE686BDC7479DEAFB3EBE8E9F9FFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F0F0C9C9C99F9F9F90
      90909090909A9A9AC5C5C5EFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    NumGlyphs = 2
    OnClick = sbDeleteClick
  end
  object SpeedButton4: TSpeedButton
    Left = 394
    Top = 34
    Width = 23
    Height = 22
    Hint = 'choose a folder'
    Anchors = [akTop, akRight]
    Flat = True
    Glyph.Data = {
      36030000424D3603000000000000360000002800000010000000100000000100
      18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA2CAEE
      76B2E63E91DB348CD9348CD9348CD9348CD9348CD9348CD9348CD9348CD9348B
      D9398FDA85B9E9FFFFFFFFFFFF4799DDDEF1FAA8DDF49EDBF496DAF38ED8F386
      D7F37FD4F279D3F272D2F16CD0F169CFF1C2EAF83F95DBFFFFFFFFFFFF3B97DB
      EFFAFEA1E9F991E5F881E1F772DEF663DAF554D7F447D3F339D0F22ECDF126CB
      F0CAF2FB3B97DBFFFFFFFFFFFF3C9DDBF2FAFDB3EDFAA4E9F995E6F885E2F776
      DEF665DBF557D7F449D4F33BD1F230CEF1CCF2FB3B9BDBFFFFFFFFFFFF3BA3DB
      F6FCFEC8F2FCB9EFFBACECFA9CE8F98BE3F77CE0F66CDCF65DD9F54FD6F444D3
      F3D0F3FC3BA2DBFFFFFFFFFFFF3BA8DBFEFFFFF8FDFFF6FDFFF5FCFFF3FCFED8
      F6FC94E6F885E3F776DFF668DBF55CD8F4D7F4FC3BA7DBFFFFFFFFFFFF39ADDB
      E8F6FB94D4EF88CEEE73C1E9C9E9F6F2FCFEF3FCFEF2FCFEF0FCFEEFFBFEEEFB
      FEFEFFFF3CAEDBFFFFFFFFFFFF40AEDCF1FAFD94DEF593DCF481D5F26ACAED6C
      CBEA85D3EF80D2EF7AD0EF76CFEE72CFEEE9F7FB3EB2DCFFFFFFFFFFFF41B4DC
      F7FCFE8EE4F891DEF59FE0F5ACE1F6EFFBFEF4FDFEF3FCFEF1FCFEEFFBFEEEFB
      FEFAFDFF58BCE0FFFFFFFFFFFF3CB5DBFDFEFEFEFFFFFEFEFFFDFEFFFEFFFFEA
      F7FB6EC8E56FC9E46FC9E46FC9E47DCFE784D0E8BAE5F2FFFFFFFFFFFF59C2E0
      61C3E263C4E363C4E363C4E362C4E356C0E0EDF8FCF3FAFDF3FAFDF3FAFDF3FA
      FDF3FBFDFCFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    OnClick = SpeedButton4Click
    ExplicitLeft = 314
  end
  object lFolderList: TLabel
    Left = 8
    Top = 72
    Width = 3
    Height = 13
    Caption = '.'
  end
  object Bevel6: TBevel
    Left = 8
    Top = 64
    Width = 433
    Height = 4
    Anchors = [akLeft, akTop, akRight, akBottom]
    Shape = bsTopLine
    ExplicitHeight = 5
  end
  object sbExplore: TSpeedButton
    Left = 304
    Top = 292
    Width = 138
    Height = 25
    Hint = 'open the selected folder in Explorer'
    Anchors = [akRight, akBottom]
    Enabled = False
    Flat = True
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA2CAEE76B2E6
      3E91DB348CD9348CD9348CD9348CD9348CD9348CD9348CD9348CD9348BD9398F
      DA85B9E9FFFFFFFFFFFFD3D3D3BFBFBFA3A3A39F9F9F9F9F9F9F9F9F9F9F9F9F
      9F9F9F9F9F9F9F9F9F9F9F9E9E9EA1A1A1C5C5C5FFFFFFFFFFFF4799DDDEF1FA
      A8DDF49EDBF496DAF38ED8F386D7F37FD4F279D3F272D2F16CD0F169CFF1C2EA
      F83F95DBFFFFFFFFFFFFA9A9A9F3F3F3E0E0E0DEDEDEDDDDDDDBDBDBDADADAD8
      D8D8D7D7D7D6D6D6D4D4D4D3D3D3ECECECA6A6A6FFFFFFFFFFFF3B97DBEFFAFE
      A1E9F991E5F881E1F772DEF663DAF554D7F447D3F339D0F22ECDF126CBF0CAF2
      FB3B97DBFFFFFFFFFFFFA7A7A7FBFBFBEAEAEAE6E6E6E2E2E2DFDFDFDCDCDCDA
      DADAD6D6D6D3D3D3D1D1D1CFCFCFF2F2F2A7A7A7FFFFFFFFFFFF3C9DDBF2FAFD
      B3EDFAA4E9F995E6F885E2F776DEF665DBF557D7F449D4F33BD1F230CEF1CCF2
      FB3B9BDBFFFFFFFFFFFFAAAAAAFBFBFBEEEEEEEAEAEAE7E7E7E3E3E3E0E0E0DD
      DDDDDADADAD7D7D7D4D4D4D2D2D2F2F2F2AAAAAAFFFFFFFFFFFF3BA3DBF6FCFE
      C8F2FCB9EFFBACECFA9CE8F98BE3F77CE0F66CDCF65DD9F54FD6F444D3F3D0F3
      FC3BA2DBFFFFFFFFFFFFAEAEAEFDFDFDF3F3F3EFEFEFECECECE9E9E9E4E4E4E1
      E1E1DEDEDEDBDBDBD9D9D9D6D6D6F3F3F3AEAEAEFFFFFFFFFFFF3BA8DBFEFFFF
      F8FDFFF6FDFFF5FCFFF3FCFED8F6FC94E6F885E3F776DFF668DBF55CD8F4D7F4
      FC3188B94D7CA3416F96B2B2B2FFFFFFFEFEFEFEFEFEFDFDFDFCFCFCF6F6F6E7
      E7E7E4E4E4E0E0E0DDDDDDDADADAF5F5F592929284848477777739ADDBE8F6FB
      94D4EF88CEEE73C1E9C9E9F6F2FCFEF3FCFEF2FCFEF0FCFEEFFBFEEEFBFEB0C1
      D1578BB78CB1D446759FB4B4B4F7F7F7D8D8D8D3D3D3C8C8C8EBEBEBFCFCFCFC
      FCFCFCFCFCFCFCFCFBFBFBFBFBFBC4C4C4949494B8B8B87D7D7D40AEDCF1FAFD
      94DEF593DCF481D5F26ACAED6CCBEA87C8DD98B2B4C7AC94CDAF96C8A88DAB99
      8E96B1CB5D8CB8B2C3D2B6B6B6FBFBFBE0E0E0DEDEDED9D9D9CFCFCFCFCFCFCA
      CACAB1B1B1A9A9A9ACACACA5A5A5989898B6B6B6969696C6C6C641B4DCF7FCFE
      8EE4F891DEF59FE0F5ACE1F6EFFBFEC6B8AAE2CDBCF5E0CCF7E0C7F8E2CBF3D1
      B3A7998FB4C5D5FFFFFFB9B9B9FDFDFDE5E5E5E0E0E0E2E2E2E4E4E4FBFBFBB6
      B6B6CBCBCBDDDDDDDDDDDDDFDFDFCDCDCD989898C8C8C8FFFFFF3CB5DBFDFEFE
      FEFFFFFEFEFFFDFEFFFEFFFFEAF7FBC9AC94F3E3D4F4DAC1F3D8BDF3D8BDF8E3
      CCC4A48BFFFFFFFFFFFFBABABAFEFEFEFFFFFFFEFEFEFEFEFEFFFFFFF8F8F8A9
      A9A9E1E1E1D7D7D7D4D4D4D4D4D4E0E0E0A1A1A1FFFFFFFFFFFF59C2E061C3E2
      63C4E363C4E363C4E362C4E356C0E0C8A98DF8EADCF4DDC6F4DCC4F3D8BDF8E2
      CDCCAD93FFFFFFFFFFFFC6C6C6C7C7C7C8C8C8C8C8C8C8C8C8C8C8C8C4C4C4A6
      A6A6E8E8E8DADADAD9D9D9D4D4D4DFDFDFAAAAAAFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCAAE95F2E3D5F6E0CAF5DEC6F5DEC5F7E5
      D2C5AA94FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAB
      ABABE2E2E2DDDDDDDBDBDBDBDBDBE2E2E2A7A7A7FFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC2B6A8DDC3ABF4E6DAF8ECDFF2DDC9E3C9
      B2C4B4A6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB4
      B4B4C0C0C0E5E5E5EAEAEADADADAC6C6C6B2B2B2FFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFEFEC2B7A8BFAE97C9AB8FCDAF95BEAB
      98F7FAFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE
      FEFEB4B4B4ABABABA8A8A8ACACACA9A9A9FAFAFAFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    NumGlyphs = 2
    OnClick = sbExploreClick
    ExplicitLeft = 224
    ExplicitTop = 272
  end
  object lbCombine: TListBox
    Left = 8
    Top = 88
    Width = 433
    Height = 199
    Anchors = [akLeft, akTop, akRight, akBottom]
    ItemHeight = 13
    TabOrder = 0
    OnClick = lbCombineClick
  end
  object bCancel: TBitBtn
    Left = 360
    Top = 332
    Width = 83
    Height = 25
    Anchors = [akRight, akBottom]
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
    TabOrder = 1
  end
  object bScan: TBitBtn
    Left = 272
    Top = 332
    Width = 82
    Height = 25
    Anchors = [akRight, akBottom]
    Enabled = False
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFDFEE7EE
      F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFDFDFDEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFBFD6494BA2267
      9D81A8C6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFCFCFC9B9B9B737373ADADADFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFCFD6F9CC2558DBC89B5
      DD185F97FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFCFCFCA4A4A4979797BDBDBD6C6C6CFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFCFD7BA4CA6497C59DC1E46699
      C73171A5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFCFCFCABABABA1A1A1C8C8C8A3A3A37D7D7DFFFFFFFFFFFFFFFFFFFFFFFF
      FFFEFEE8CFBADBB292D3A680D0A17CD2A685AEA19975A2CCABCBE876A4CE407B
      AFDEE8F1FFFFFFFFFFFFFFFFFFFFFFFFFEFEFECDCDCDAFAFAFA2A2A29E9E9EA3
      A3A3A0A0A0ABABABD1D1D1ACACAC878787EAEAEAFFFFFFFFFFFFFFFFFFFFFEFE
      E8CAB0E8C9AEF5E1CDF7E5D3F7E5D1F3DDC8DFBA9CC7A89186AED55087BBE1EA
      F3FFFFFFFFFFFFFFFFFFFFFFFFFEFEFEC7C7C7C6C6C6DEDEDEE3E3E3E2E2E2DA
      DADAB7B7B7A6A6A6B6B6B6939393ECECECFFFFFFFFFFFFFFFFFFFFFFFFF1DBC8
      EDD0B7F8E8D9F5DEC8F3D8BDF3D6BBF4DBC2F7E4D2DFBB9DA09795E3ECF5FFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFD9D9D9CDCDCDE6E6E6DBDBDBD4D4D4D2D2D2D8
      D8D8E2E2E2B7B7B7989898EEEEEEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEECEB2
      F7E7D7F6E1CCF4DBC2F4DAC0F3D8BDF3D7BBF4DBC2F3DEC9D2A887FFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFCBCBCBE5E5E5DEDEDED8D8D8D7D7D7D4D4D4D3
      D3D3D8D8D8DBDBDBA5A5A5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0CEAF
      F9ECDFF5DFC8F5DDC6F4DCC3F4DAC1F3D9BEF3D7BDF8E6D3D3A680FFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFCACACAEAEAEADCDCDCDADADAD9D9D9D7D7D7D5
      D5D5D4D4D4E3E3E3A2A2A2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4D3B5
      F9EDE1F6E1CCF5DFC9F5DEC7F4DCC4F4DBC2F4DAC0F8E7D6D7AB87FFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFCFCFCFECECECDEDEDEDCDCDCDBDBDBD9D9D9D8
      D8D8D7D7D7E5E5E5A8A8A8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8DBC1
      F9EBDEF7E7D6F6E1CCF5E0CAF5DEC8F5DDC5F6E1CBF5E2D0DFB999FFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFD8D8D8E9E9E9E5E5E5DEDEDEDDDDDDDBDBDBDA
      DADADEDEDEE0E0E0B5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCEAD8
      F8E2CCFAEEE3F7E7D6F6E2CEF6E1CBF6E3D0F9EADDECCFB5ECD4BFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFE8E8E8DFDFDFEDEDEDE5E5E5DFDFDFDEDEDEE0
      E0E0E9E9E9CCCCCCD2D2D2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FBE4CEF9E2CDFAECDEF9EEE2F9EDE2F8E9DAF0D5BDEDD0B7FFFEFEFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1DFDFDFEAEAEAEDEDEDECECECE7
      E7E7D2D2D2CDCDCDFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFCEAD9FADDC2F6D6B9F4D3B5F3D4B8F5E0CDFFFFFEFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8E8E8D9D9D9D2D2D2CFCFCFD1
      D1D1DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    ModalResult = 1
    NumGlyphs = 2
    TabOrder = 2
  end
  object bLoadList: TBitBtn
    Left = 91
    Top = 332
    Width = 75
    Height = 25
    Hint = 'load a previously saved scan list'
    Anchors = [akLeft, akBottom]
    Glyph.Data = {
      36030000424D3603000000000000360000002800000010000000100000000100
      18000000000000030000130B0000130B00000000000000000000FF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8F6E1CFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
      00FF816100FF9F2A8F6F1DFF00FFFF00FFFF00FFFF00FFFF00FFA8A8A8737373
      553F2A553F2A3D3D3D3D3D3DB4B4B4806100FF9F2AD9A77DFF9F2A8F6F1C7373
      737474743D3D3DA7A7A7919191A9FFFF99F8FF99F8FF55DFFF55BFD3806100D9
      A77DD9A77DD9A77DD9A77DFF9F2A8F6F1D55DFFF55C0D43D3D3D919191A9FFFF
      A9FFFFA9FFFFA9FFFF806100D9A77DFFFFC3FFFFC3D9A77DD9A77DD9A77DFF9F
      2A8F6F1D55DFFF3D3D3D919191A9FFFFA9FFFFA9FFFFE1BE788F6F1C8F6F1C8F
      6E1CFFFFC3FFFFC4D9A77D8F6F1D8F6F1C8F6F1CE1BE78737373909090A9FFFF
      A9FFFFA9FFFFA9FFFFA9FFFFA9FFFF9D7C30FFFFC3FFFFC3FFF1AB9D7C30B4B4
      B499F8FF55DFFF3D3D3D919191E8E8E8A9FFFFA9FFFFA9FFFFA9FFFFA9FFFFAB
      8A40FFFFC3FFFFC3D9A77DFBD79198F7FF55DFFFAADFD53D3D3D919191A9FFFF
      A9FFFFA9FFFFA9FFFFA9FFFFB9974FD9A77DFFF0AAFFFFC3AB8A4099F7FF99F7
      FF99F8FF55DFFF595959A8A8A8ECECECA9FFFFECECECA9FFFFA8FEFFB9974EFF
      E49EFFF0AAE1BE77FBD790A9FFFFA9FFFFA9FFFFA9FFFF666666B4B4B4A9FFFF
      EEEEEEA9FFFFA8FEFFAB893FD9A77DFBD790E1BE78A9FFFFA9FFFFA9FFFFA9FF
      FFA9FFFFA9FFFF737373C1C1C1F0F0F0A9FFFFF0F0F0D4B16AD4B26BD4B26BD4
      B26BEECB84C6C6C6C6C6C6AADFD555BFD354BFD355BFD3818181CCCCCCB5B5B5
      B4B4B4B4B4B4CBCBCBAADFD5AADFD555DFFF55DFFF55DFFF55DFFF55DFFF55DF
      FF55DFFF54BFD3C1C1C1FF00FFDADADA00F2FF00F2FF00F1FF00F1FF55BFD3E6
      E6E68D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8D8DFF00FFFF00FF9B9B9B
      54FFFF67F4FF67F4FF67F4FF00F1FFB4B4B4FF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFB9B19E9B9B9B8D8D8D8D8D8D8D8D8D9B9B9BFF
      00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
    TabOrder = 3
    OnClick = bLoadListClick
  end
  object bSaveList: TBitBtn
    Left = 10
    Top = 332
    Width = 75
    Height = 25
    Hint = 'save this scan list'
    Anchors = [akLeft, akBottom]
    Enabled = False
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000D8AB8ECD9570
      BD7342B76835B56835B46734B26634B06533AE6433AC6332AA6232A96132A860
      31A76132AB693CBC8661A8A8A893939371717167676766666666666665656564
      64646363636262626161616060605F5F5F606060676767838383C37D4FEBC6AD
      EAC5ADFEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFB
      F8C89A7CC79879AD6B407B7B7BC4C4C4C3C3C3FBFBFBFBFBFBFBFBFBFBFBFBFB
      FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFB989898969696696969BA6C38EDCAB3
      E0A27AFEFAF762C08862C08862C08862C08862C08862C08862C08862C088FDF9
      F6CA8D65C99B7CA761326A6A6AC8C8C89F9F9FFAFAFAB1B1B1B1B1B1B1B1B1B1
      B1B1B1B1B1B1B1B1B1B1B1B1B1B1F9F9F98A8A8A989898606060BB6C38EECCB6
      E1A27AFEFAF7BFDCC2BFDCC2BFDCC2BFDCC2BFDCC2BFDCC2BFDCC2BFDCC2FDF9
      F6CD9068CC9E81A861326B6B6BCACACA9F9F9FFAFAFAD6D6D6D6D6D6D6D6D6D6
      D6D6D6D6D6D6D6D6D6D6D6D6D6D6F9F9F98D8D8D9C9C9C606060BB6B38EFCEB8
      E1A279FEFAF762C08862C08862C08862C08862C08862C08862C08862C088FDF9
      F6CF936ACEA384AA61326A6A6ACCCCCC9F9F9FFAFAFAB1B1B1B1B1B1B1B1B1B1
      B1B1B1B1B1B1B1B1B1B1B1B1B1B1F9F9F9909090A0A0A0606060BA6A36EFD0BB
      E2A27AFEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFB
      F8D3966DD2A78AAB6232696969CECECE9F9F9FFBFBFBFBFBFBFBFBFBFBFBFBFB
      FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFB939393A4A4A4616161BB6A36F0D2BE
      E2A37AE2A37AE1A37AE2A37BE1A37BE0A178DE9F77DD9F76DC9D74D99B72D899
      71D69970D5AB8EAD6333696969D0D0D0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A09E
      9E9E9C9C9C9C9C9C9A9A9A989898979797969696A8A8A8626262BB6A36F2D5C2
      E3A37AE3A37AE2A37BE2A37BE2A47BE1A279E0A178DEA077DE9E75DC9D74DA9B
      73D99B73DAB095AF6433696969D3D3D3A0A0A0A0A0A0A0A0A0A0A0A0A1A1A19F
      9F9F9E9E9E9D9D9D9B9B9B9A9A9A999999989898AEAEAE636363BB6A36F2D8C5
      E3A47BE3A37AE3A47AE2A47BE2A37BE1A37BE1A279DFA077DE9F76DD9E74DB9C
      72DC9D74DDB59AB16534696969D6D6D6A1A1A1A0A0A0A1A1A1A1A1A1A0A0A0A0
      A0A09F9F9F9D9D9D9C9C9C9B9B9B9999999A9A9AB2B2B2646464BB6B36F4D9C7
      E6A67DC88C64C98D65C98E67CB926CCB926DCA9069C88C65C88C64C88C64C88C
      64DA9C74E1BA9FB366346A6A6AD7D7D7A3A3A38989898A8A8A8B8B8B8F8F8F90
      90908D8D8D8A8A8A898989898989898989999999B7B7B7656565BB6C37F4DCC9
      E7A77DF9ECE1F9ECE1F9EDE3FCF4EEFDFAF7FDF7F3FAEDE5F7E7DBF7E5D9F6E5
      D8DEA077E4BEA4B467346B6B6BDADADAA4A4A4EBEBEBEBEBEBECECECF4F4F4FA
      FAFAF7F7F7EDEDEDE6E6E6E4E4E4E4E4E49D9D9DBBBBBB666666BD6E3AF5DDCC
      E7A87EFAF0E8FAF0E8C98D66FAF0E9FDF8F3FEFAF8FCF4EFF9E9DFF7E7DBF7E5
      D9E0A278E7C2A9B668356C6C6CDBDBDBA5A5A5EFEFEFEFEFEF8B8B8BF0F0F0F8
      F8F8FAFAFAF4F4F4E8E8E8E6E6E6E4E4E49F9F9FC0C0C0676767C07442F6DFD0
      E8A87EFCF6F1FCF6F1C88C64FAF1E9FBF4EEFDFAF7FDF9F6FAF0E8F8E8DDF7E6
      DBE1A37AEFD5C3B76A36727272DDDDDDA5A5A5F6F6F6F6F6F6898989F0F0F0F4
      F4F4FAFAFAF9F9F9EFEFEFE7E7E7E5E5E5A0A0A0D3D3D3686868C68255F6DFD1
      E9AA80FEFAF6FDFAF6C88C64FBF3EEFBF1EAFCF6F2FEFBF8FCF6F1F9ECE2F8E7
      DBEED0BAECD0BDBD7443808080DEDEDEA7A7A7FAFAFAFAFAFA898989F3F3F3F1
      F1F1F6F6F6FBFBFBF6F6F6EBEBEBE6E6E6CDCDCDCECECE727272D6A585F6E0D1
      F7E0D1FEFBF8FEFBF7FDF9F6FCF5F0FAF0EAFBF2EDFDF9F6FDFAF7FBF1EBF8E9
      DFECD1BECD926AE2C5B1A3A3A3DEDEDEDEDEDEFBFBFBFBFBFBF9F9F9F5F5F5F0
      F0F0F2F2F2F9F9F9FAFAFAF1F1F1E8E8E8CFCFCF8F8F8FC3C3C3E1BDA6D9AB8D
      C9895EC07543BD6E3ABB6C37BB6B36BB6A36BB6A36BC6C39BD6E3BBB6D3ABF74
      44C98D65E7CEBCFFFFFFBBBBBBA8A8A88686867373736C6C6C6B6B6B6A6A6A69
      69696969696B6B6B6D6D6D6B6B6B7373738A8A8ACCCCCCFFFFFF}
    NumGlyphs = 2
    TabOrder = 4
    OnClick = bSaveListClick
  end
  object eDirectory: TEdit
    Left = 8
    Top = 34
    Width = 384
    Height = 21
    TabOrder = 5
    OnKeyPress = eDirectoryKeyPress
  end
  object odCombine: TOpenDialog
    DefaultExt = 'xcl'
    Filter = 'Xinorbis Scan Lists (.xcl)|*.xcl'
    Left = 376
    Top = 16
  end
  object sdCombine: TSaveDialog
    DefaultExt = 'xcl'
    Filter = 'Xinorbis Scan Lists (.xcl)|*.xcl'
    Left = 416
    Top = 24
  end
end
