object frmExcludedFolders: TfrmExcludedFolders
  Left = 507
  Top = 350
  BorderStyle = bsDialog
  ClientHeight = 280
  ClientWidth = 560
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
  PixelsPerInch = 96
  TextHeight = 13
  object sbAdd: TSpeedButton
    Left = 8
    Top = 8
    Width = 25
    Height = 25
    Flat = True
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
  object Bevel1: TBevel
    Left = 8
    Top = 240
    Width = 545
    Height = 4
    Shape = bsTopLine
  end
  object sbRemove: TSpeedButton
    Left = 34
    Top = 8
    Width = 25
    Height = 25
    Enabled = False
    Flat = True
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
    OnClick = sbRemoveClick
  end
  object sbEdit: TSpeedButton
    Left = 58
    Top = 8
    Width = 25
    Height = 25
    Enabled = False
    Flat = True
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000FF00FFE2C0AA
      CC8D66C07140BC6B36BC6B36BC6B36BC6A36BC6A36BB6A35BB6A35BB6935BD6E
      3BCA8B63E3C2AEFF00FFFF00FFC0C0C08D8D8D7171716B6B6B6B6B6B6B6B6B6A
      6A6A6A6A6A6969696969696969696E6E6E8B8B8BC2C2C2FF00FFFF00FFC57C4D
      F8F2EBF7ECDFF6EBDEF6EADEF6EADCF6EADCFAF3EBFAF3EBFAF2EAFCF7F3FCF8
      F4FEFEFDC37A4DFF00FFFF00FF7C7C7CF1F1F1EAEAEAE9E9E9E9E9E9E8E8E8E8
      E8E8F2F2F2F2F2F2F1F1F1F7F7F7F8F8F8FEFEFE7A7A7AFF00FFFF00FFC27740
      F5EBDFFDBF68FCBD67FBBE65FCBE64FCBE64FCBD62FBBD63FBBC61FCBE60FCBC
      62FDFBF8BC6B37FF00FFFF00FF757575EAEAEAB6B6B6B4B4B4B4B4B4B4B4B4B4
      B4B4B3B3B3B3B3B3B2B2B2B4B4B4B3B3B3FBFBFB6B6B6BFF00FFFF00FFC37C42
      F7EDE3FDC26E1842572B61874C89BC709FB3E3C99AFFD695FFD594FFD493FBBE
      65FBF7F4BD6C37FF00FFFF00FF797979ECECECB9B9B9464646696969949494A1
      A1A1C2C2C2CDCDCDCCCCCCCBCBCBB4B4B4F7F7F76C6C6CFF00FFFF00FFC68046
      F7F0E6F8B4552E668294C7F991C9F94185C92668A6D2A865F7B251F7B24FF7B2
      4FFCF9F5C1743CFF00FFFF00FF7D7D7DEFEFEFAAAAAA6B6B6BD1D1D1D3D3D395
      9595777777A0A0A0A8A8A8A8A8A8A8A8A8F9F9F9727272FF00FFFF00FFC78448
      F8F1E8FEE5D54389AAE0F2FF549AD81A7ABE4998C5488CC2DAD2CDFBE0C9FBE1
      C8FDFAF7C37A41FF00FFFF00FF808080F0F0F0E3E3E38E8E8EF4F4F4A8A8A88A
      8A8AA0A0A0979797D2D2D2DDDDDDDEDEDEFAFAFA777777FF00FFFF00FFC7864B
      F8F2EBFEE7D6A6B6BF7AB6D590B7D155C9E45BDFF578D0ED519BD9E1D6CDFBE1
      C9FBF7F2C78045FF00FFFF00FF828282F1F1F1E5E5E5B7B7B7BBBBBBBBBBBBCB
      CBCBE0E0E0D4D4D4A9A9A9D5D5D5DEDEDEF7F7F77D7D7DFF00FFFF00FFC8884D
      F9F3ECFEE8D6FEE8D7B3C6CC76B9D6C2F6FD63DFF75DE2F879D3F04998DAE2D5
      C8FAF2EAC88448FF00FFFF00FF848484F2F2F2E6E6E6E6E6E6C6C6C6BDBDBDF5
      F5F5E0E0E0E2E2E2D6D6D6A7A7A7D4D4D4F1F1F1808080FF00FFFF00FFC88C4F
      F9F4EDFEE8D8FEE8D8FEE8D7B0C6CC77CBE7C7F7FD5EDCF55AE1F77BD4F14B99
      DBD2DFE9C8864BFF00FFFF00FF878787F3F3F3E6E6E6E6E6E6E6E6E6C6C6C6CE
      CECEF6F6F6DDDDDDE2E2E2D7D7D7A8A8A8E1E1E1828282FF00FFFF00FFC88C50
      F9F4EFFEE7D7FDE7D6FDE7D5FDE6D4BDD6D579D3EEC7F7FD5FDCF55BE2F77AD6
      F251A1E0AF8864FF00FFFF00FF878787F4F4F4E5E5E5E5E5E5E5E5E5E4E4E4D5
      D5D5D6D6D6F6F6F6DDDDDDE2E2E2D9D9D9AFAFAF848484FF00FFFF00FFC88D51
      F9F4F0FCE6D3FCE6D4FDE7D3FCE4D1FBE3CDBED4D07DD4EEC4F6FD6CDDF66DCA
      ED63A3D76599C8FF00FFFF00FF888888F4F4F4E3E3E3E4E4E4E4E4E4E2E2E2E0
      E0E0D2D2D2D7D7D7F5F5F5DFDFDFCFCFCFAEAEAEA3A3A3FF00FFFF00FFC88D51
      F9F5F1FCE3CFFBE4D0FCE4CFFCE3CDFAE1CAF9DDC4AFCDC981D5EEB2E3F98BC0
      E7AED3F6C4E0FC6BA2D4FF00FF888888F5F5F5E1E1E1E1E1E1E1E1E1E0E0E0DE
      DEDEDADADACBCBCBD7D7D7E6E6E6C7C7C7DADADAE6E6E6ADADADFF00FFC88D52
      F9F5F1FCE3CDFBE3CEFBE3CDFBE2CBF9E0C8F8DCC2F5D6BAAFE3F177BEE7B4D2
      F0E5F3FFACD2EF5996CCFF00FF888888F5F5F5E0E0E0E0E0E0E0E0E0DFDFDFDD
      DDDDD9D9D9D2D2D2E4E4E4C6C6C6D8D8D8F5F5F5D8D8D8A2A2A2FF00FFCA925A
      FAF6F2FAE0C7FBE1C9FBE2C9FBE0C8F9DFC5F8DBC1F4D6B8FFFBF8B6CBC258A5
      D885B1DB469DD0FF00FFFF00FF8D8D8DF6F6F6DDDDDDDEDEDEDFDFDFDDDDDDDC
      DCDCD8D8D8D2D2D2FBFBFBC8C8C8AFAFAFB9B9B9A7A7A7FF00FFFF00FFD2A274
      F8F3EDF8F4EEF8F4EDF8F3EDF8F3EDF8F3EDF8F2ECF7F2ECF2E6D7E2B27DDC98
      6BFF00FFFF00FFFF00FFFF00FF9E9E9EF2F2F2F3F3F3F3F3F3F2F2F2F2F2F2F2
      F2F2F1F1F1F1F1F1E4E4E4ACACAC959595FF00FFFF00FFFF00FFFF00FFE8CEB9
      D7AA7CCC945BCA9055CA9055CA9055CA9155CB9055C98F55CF9D69DDB190FF00
      FFFF00FFFF00FFFF00FFFF00FFCDCDCDA6A6A68E8E8E8A8A8A8A8A8A8A8A8A8B
      8B8B8B8B8B8A8A8A999999AFAFAFFF00FFFF00FFFF00FFFF00FF}
    NumGlyphs = 2
    OnClick = sbEditClick
  end
  object sbSpecial: TSpeedButton
    Left = 104
    Top = 8
    Width = 89
    Height = 25
    Flat = True
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
    OnClick = sbSpecialClick
  end
  object lbExcluded: TListBox
    Left = 8
    Top = 40
    Width = 545
    Height = 169
    ItemHeight = 13
    TabOrder = 0
    OnClick = lbExcludedClick
  end
  object bOK: TBitBtn
    Left = 364
    Top = 248
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
  object bCancel: TBitBtn
    Left = 461
    Top = 248
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
    TabOrder = 2
  end
  object bSave: TBitBtn
    Left = 8
    Top = 248
    Width = 97
    Height = 25
    Enabled = False
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000FF00FFCD9570
      BD7342B76835B56835B46734B26634B06533AE6433AC6332AA6232A96132A860
      31A76132AB693CBC8661FF00FF93939371717167676766666666666665656564
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
      DFECD1BECD926AFF00FFA3A3A3DEDEDEDEDEDEFBFBFBFBFBFBF9F9F9F5F5F5F0
      F0F0F2F2F2F9F9F9FAFAFAF1F1F1E8E8E8CFCFCF8F8F8FFF00FFE1BDA6D9AB8D
      C9895EC07543BD6E3ABB6C37BB6B36BB6A36BB6A36BC6C39BD6E3BBB6D3ABF74
      44C98D65FF00FFFF00FFBBBBBBA8A8A88686867373736C6C6C6B6B6B6A6A6A69
      69696969696B6B6B6D6D6D6B6B6B7373738A8A8AFF00FFFF00FF}
    ModalResult = 1
    NumGlyphs = 2
    TabOrder = 3
    OnClick = bSaveClick
  end
  object bOpen: TBitBtn
    Left = 111
    Top = 248
    Width = 97
    Height = 25
    Glyph.Data = {
      36040000424D3604000000000000360000002800000010000000100000000100
      20000000000000040000120B0000120B00000000000000000000FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF008F6E1C00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF0081610000FF9F2A008F6F1D00FF00FF00FF00FF00FF00FF00FF00FF00A2CA
      EE0076B2E6003E91DB00348CD900348CD900348CD900348CD900348CD9008061
      0000FF9F2A00D9A77D00FF9F2A008F6F1C0085B9E900FF00FF00FF00FF004799
      DD00DEF1FA00A8DDF4009EDBF40096DAF3008ED8F30086D7F30080610000D9A7
      7D00D9A77D00D9A77D00D9A77D00FF9F2A008F6F1D00FF00FF00FF00FF003B97
      DB00EFFAFE00A1E9F90091E5F80081E1F70072DEF60080610000D9A77D00FFFF
      C300FFFFC300D9A77D00D9A77D00D9A77D00FF9F2A008F6F1D00FF00FF003C9D
      DB00F2FAFD00B3EDFA00A4E9F90095E6F80085E2F7008F6F1C008F6F1C008F6E
      1C00FFFFC300FFFFC400D9A77D008F6F1D008F6F1C008F6F1C00FF00FF003BA3
      DB00F6FCFE00C8F2FC00B9EFFB00ACECFA009CE8F9008BE3F7007CE0F6009D7C
      3000FFFFC300FFFFC300FFF1AB009D7C30003BA2DB00FF00FF00FF00FF003BA8
      DB00FEFFFF00F8FDFF00F6FDFF00F5FCFF00F3FCFE00D8F6FC0094E6F800AB8A
      4000FFFFC300FFFFC300D9A77D00FBD791003BA7DB00FF00FF00FF00FF0039AD
      DB00E8F6FB0094D4EF0088CEEE0073C1E900C9E9F600F2FCFE00B9974F00D9A7
      7D00FFF0AA00FFFFC300AB8A4000FEFFFF003CAEDB00FF00FF00FF00FF0040AE
      DC00F1FAFD0094DEF50093DCF40081D5F2006ACAED006CCBEA00B9974E00FFE4
      9E00FFF0AA00E1BE7700FBD79000E9F7FB003EB2DC00FF00FF00FF00FF0041B4
      DC00F7FCFE008EE4F80091DEF5009FE0F500ACE1F600AB893F00D9A77D00FBD7
      9000E1BE7800EFFBFE00EEFBFE00FAFDFF0058BCE000FF00FF00FF00FF003CB5
      DB00FDFEFE00FEFFFF00FEFEFF00FDFEFF00D4B16A00D4B26B00D4B26B00D4B2
      6B00EECB84006FC9E4007DCFE70084D0E800BAE5F200FF00FF00FF00FF0059C2
      E00061C3E20063C4E30063C4E30063C4E30062C4E30056C0E000FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
    ModalResult = 2
    TabOrder = 4
    OnClick = bOpenClick
  end
  object cbIgnoreVirtual: TAdvOfficeCheckBox
    Left = 18
    Top = 215
    Width = 511
    Height = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    Alignment = taLeftJustify
    Caption = ''
    ReturnIsTab = False
    Version = '1.5.0.9'
  end
  object puSF: TPopupMenu
    AutoHotkeys = maManual
    AutoLineReduction = maManual
    Left = 400
    Top = 8
    object miSF1: TMenuItem
      AutoHotkeys = maManual
      AutoLineReduction = maManual
      Caption = '.'
      OnClick = miSF1Click
    end
    object miSF2: TMenuItem
      AutoHotkeys = maManual
      AutoLineReduction = maManual
      Caption = '.'
      OnClick = miSF1Click
    end
    object miSF3: TMenuItem
      AutoHotkeys = maManual
      AutoLineReduction = maManual
      Caption = '.'
      OnClick = miSF1Click
    end
    object miSF4: TMenuItem
      AutoHotkeys = maManual
      AutoLineReduction = maManual
      Caption = '.'
      OnClick = miSF1Click
    end
  end
  object sdExclude: TSaveDialog
    Left = 472
    Top = 8
  end
  object odExclude: TOpenDialog
    Left = 512
    Top = 8
  end
end
