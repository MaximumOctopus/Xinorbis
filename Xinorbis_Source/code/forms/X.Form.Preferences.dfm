object frmFileTypes: TfrmFileTypes
  Left = 610
  Top = 348
  BorderStyle = bsDialog
  Caption = '.'
  ClientHeight = 525
  ClientWidth = 912
  Color = clWhite
  DoubleBuffered = True
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
  object Bevel10: TBevel
    Left = 6
    Top = 484
    Width = 901
    Height = 4
    Shape = bsTopLine
  end
  object pPostScan: TPanel
    Left = 175
    Top = 8
    Width = 734
    Height = 468
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 3
    object lPostScan: TLabel
      Left = 4
      Top = 4
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
    object rbNPostScan: TAdvOfficeRadioButton
      Left = 32
      Top = 45
      Width = 441
      Height = 20
      AutoSize = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = True
      Alignment = taLeftJustify
      Caption = '.'
      Checked = True
      GroupIndex = 1
      ReturnIsTab = False
      Version = '1.5.0.9'
    end
    object rbSPostScan: TAdvOfficeRadioButton
      Left = 32
      Top = 71
      Width = 361
      Height = 20
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Alignment = taLeftJustify
      Caption = '.'
      GroupIndex = 1
      ReturnIsTab = False
      Version = '1.5.0.9'
    end
    object rbIPPostScan: TAdvOfficeRadioButton
      Left = 32
      Top = 97
      Width = 361
      Height = 20
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Alignment = taLeftJustify
      Caption = '.'
      GroupIndex = 1
      ReturnIsTab = False
      Version = '1.5.0.9'
    end
    object rbFSPostScan: TAdvOfficeRadioButton
      Left = 32
      Top = 165
      Width = 361
      Height = 20
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Alignment = taLeftJustify
      Caption = '.'
      GroupIndex = 1
      ReturnIsTab = False
      Version = '1.5.0.9'
    end
    object cbIPPostScan: TComboBox
      Left = 53
      Top = 130
      Width = 201
      Height = 21
      Style = csDropDownList
      TabOrder = 4
    end
  end
  object pFavourites: TPanel
    Left = 175
    Top = 8
    Width = 734
    Height = 468
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 6
    object lQuickFolders: TLabel
      Left = 72
      Top = 40
      Width = 3
      Height = 13
      Caption = '.'
    end
    object lFavourites: TLabel
      Left = 4
      Top = 4
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
    object GroupBox4: TGroupBox
      Left = 30
      Top = 57
      Width = 36
      Height = 172
      TabOrder = 0
      object SpeedButton14: TSpeedButton
        Left = 6
        Top = 14
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          36060000424D3606000000000000360000002800000020000000100000000100
          18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF286E2D2569292164251E6022FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF6161615C
          5C5C585858545454FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF2D753374BD7A72BD78226526FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF676767AD
          ADADADADAD595959FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF337D3979C07E76BF7C266B2BFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF6F6F6FB0
          B0B0AFAFAF5E5E5EFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF39853F7DC2827AC1802B7230FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF777777B3
          B3B3B1B1B1646464FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF3F8D4681C5877EC385317A36FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF7E7E7EB6
          B6B6B4B4B46C6C6CFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF45954C85C78C82C68936823DFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF858585B9
          B9B9B7B7B7747474FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF4A9E538ACA9187C98E3C8A43FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8D8D8DBC
          BCBCBBBBBB7B7B7BFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF50A6598ECC958BCB9342924AFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF959595BE
          BEBEBDBDBD838383FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF56AD5F93CF9A90CE98489A50FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9C9C9CC2
          C2C2C1C1C18A8A8AFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF5BB46596D29F94D09C5DAC65FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA2A2A2C5
          C5C5C3C3C39C9C9CFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FF8ED39767C17379C6839AD4A398D3A17DC38655A75D7CB983FF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC6C6C6B0B0B0B6B6B6C8
          C8C8C6C6C6B4B4B4969696ADADADFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FF7CCC867CCA879ED6A79CD4A573C07D6EB876FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFBDBDBDBABABACA
          CACAC8C8C8B0B0B0AAAAAAFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF82CF8B7ECA887BC8857BC584FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC0C0C0BA
          BABAB8B8B8B7B7B7FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FF87D29189D091FF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC3
          C3C3C2C2C2FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
        NumGlyphs = 2
        OnClick = SpeedButton14Click
      end
      object SpeedButton13: TSpeedButton
        Left = 6
        Top = 38
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          36060000424D3606000000000000360000002800000020000000100000000100
          18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FF578C5B508553FF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF82
          82827B7B7BFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF558F59488F4D458C4A4A814DFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF84848480
          80807D7D7D777777FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FF56955B51995779C07E76BF7C468D4B427C45FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8A8A8A8A8A8AB0
          B0B0AFAFAF7E7E7E707070FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FF77B07C43904B65AD6C7DC2827AC1804B92502E72335E9061FF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA6A6A68181819E9E9EB3
          B3B3B1B1B1838383656565878787FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF4E9A5581C5877EC385317A36FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8B8B8BB6
          B6B6B4B4B46C6C6CFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF45954C85C78C82C68936823DFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF858585B9
          B9B9B7B7B7747474FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF4A9E538ACA9187C98E3C8A43FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8D8D8DBC
          BCBCBBBBBB7B7B7BFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF50A6598ECC958BCB9342924AFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF959595BE
          BEBEBDBDBD838383FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF56AD5F93CF9A90CE98489A50FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9C9C9CC2
          C2C2C1C1C18A8A8AFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF5BB46596D29F94D09C4EA257FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA2A2A2C5
          C5C5C3C3C3919191FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF5FBB6A9AD4A398D3A153AA5DFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA9A9A9C8
          C8C8C6C6C6999999FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF63C06F9ED6A79CD4A559B263FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFAEAEAECA
          CACAC8C8C8A0A0A0FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF66C572A2D8ABA0D7A95DB868FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFB2B2B2CD
          CDCDCBCBCBA6A6A6FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF68C77467C67365C27062BE6DFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFB4B4B4B3
          B3B3B0B0B0ACACACFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
        NumGlyphs = 2
        OnClick = SpeedButton13Click
      end
      object SpeedButton11: TSpeedButton
        Left = 6
        Top = 72
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          9E020000424D9E0200000000000036000000280000000E0000000E0000000100
          18000000000068020000C21E0000C21E00000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FF569C5E3F8F493C8D454C9553FF00FFFF00FFFF00FFFF00
          FFFF00FF0000FF00FFFF00FFFF00FF57A0644199507DC28F96D0A696CFA678BE
          89368D42418D48FF00FFFF00FFFF00FF0000FF00FFFF00FF55A06464B478A8DB
          B587CC9866BC7D64BA7C86CB98A5D9B458AA6B35863DFF00FFFF00FF0073FF00
          FF67AC766AB97DA8DBB260BC775CBA7359B87059B56F58B56F5BB774A5D9B35A
          AA6C428F49FF00FFA927FF00FF53AB68AADDB464C1795FBE7160BC77FFFFFFFF
          FFFF59B87058B56E5CB774A6DAB4388F43FF00FF006977B8888ACC9889D3966B
          C67A63C17055AB65FFFFFFFFFFFF59B87059B8705BB97285CC977BBE8D4D9655
          49226AB27FA9DDB37DCF8A75CC81FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          59B87067BE7D9CD4AB3B8C44006F6EB583B6E2BE8BD5977AC986FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF59B87069C17E9DD4AA3F8F49000082BF95ACDDB6
          A6DFAF81CB8C7CC9866EBD79FFFFFFFFFFFF5BAC6A60BC775CBA738BD19980C5
          92589E610018FF00FF85C797D2EED795D9A08AD3947FC889FFFFFFFFFFFF79CD
          856BC37C6FC77EACDFB5459E57FF00FF0000FF00FF7FBF93AADAB7D8F1DC92D8
          9D88CD9384CC8E8BD4968AD49583D28EAFE0B76BB97D5BA367FF00FF437EFF00
          FFFF00FF76BB8CAFDCBBDCF2E0B6E4BD9BDBA596D9A0A5DFAFC0E8C579C28A58
          A266FF00FFFF00FF0065FF00FFFF00FFFF00FF7FBF9394CEA4C3E6CBCFEBD4C9
          E9CEAFDDB86DB97F68AE78FF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FF82C09571B7866EB58279B98AFF00FFFF00FFFF00FFFF00FFFF00FF
          0000}
        PopupMenu = puFSpecial
        OnClick = SpeedButton11Click
      end
      object SpeedButton12: TSpeedButton
        Left = 6
        Top = 96
        Width = 23
        Height = 22
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
        OnClick = SpeedButton12Click
      end
      object sbQFExplore: TSpeedButton
        Left = 6
        Top = 136
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00A2CAEE0076B2
          E6003E91DB00348CD900348CD900348CD900348CD900348CD900348CD900348C
          D900348CD900348BD900398FDA0085B9E900FF00FF00FF00FF004799DD00DEF1
          FA00A8DDF4009EDBF40096DAF3008ED8F30086D7F3007FD4F20079D3F20072D2
          F1006CD0F10069CFF100C2EAF8003F95DB00FF00FF00FF00FF003B97DB00EFFA
          FE00A1E9F90091E5F80081E1F70072DEF60063DAF50054D7F40047D3F30039D0
          F2002ECDF10026CBF000CAF2FB003B97DB00FF00FF00FF00FF003C9DDB00F2FA
          FD00B3EDFA00A4E9F90095E6F80085E2F70076DEF60065DBF50057D7F40049D4
          F3003BD1F20030CEF100CCF2FB003B9BDB00FF00FF00FF00FF003BA3DB00F6FC
          FE00C8F2FC00B9EFFB00ACECFA009CE8F9008BE3F7007CE0F6006CDCF6005DD9
          F5004FD6F40044D3F300D0F3FC003BA2DB00FF00FF00FF00FF003BA8DB00FEFF
          FF00F8FDFF00F6FDFF00F5FCFF00F3FCFE00D8F6FC0094E6F80085E3F70076DF
          F60068DBF5005CD8F400D7F4FC003188B9004D7CA300416F960039ADDB00E8F6
          FB0094D4EF0088CEEE0073C1E900C9E9F600F2FCFE00F3FCFE00F2FCFE00F0FC
          FE00EFFBFE00EEFBFE00B0C1D100578BB7008CB1D40046759F0040AEDC00F1FA
          FD0094DEF50093DCF40081D5F2006ACAED006CCBEA0087C8DD0098B2B400C7AC
          9400CDAF9600C8A88D00AB998E0096B1CB005D8CB800B2C3D20041B4DC00F7FC
          FE008EE4F80091DEF5009FE0F500ACE1F600EFFBFE00C6B8AA00E2CDBC00F5E0
          CC00F7E0C700F8E2CB00F3D1B300A7998F00B4C5D500FF00FF003CB5DB00FDFE
          FE00FEFFFF00FEFEFF00FDFEFF00FEFFFF00EAF7FB00C9AC9400F3E3D400F4DA
          C100F3D8BD00F3D8BD00F8E3CC00C4A48B00FF00FF00FF00FF0059C2E00061C3
          E20063C4E30063C4E30063C4E30062C4E30056C0E000C8A98D00F8EADC00F4DD
          C600F4DCC400F3D8BD00F8E2CD00CCAD9300FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00CAAE9500F2E3D500F6E0
          CA00F5DEC600F5DEC500F7E5D200C5AA9400FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C2B6A800DDC3AB00F4E6
          DA00F8ECDF00F2DDC900E3C9B200C4B4A600FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C2B7A800BFAE
          9700C9AB8F00CDAF9500BEAB9800FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        OnClick = sbQFExploreClick
      end
    end
    object lbQuickFolders: TListBox
      Left = 72
      Top = 56
      Width = 649
      Height = 394
      ItemHeight = 13
      TabOrder = 1
    end
  end
  object pNavigate: TPanel
    Left = 175
    Top = 8
    Width = 734
    Height = 468
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 7
    object sNL1: TShape
      Tag = 1
      Left = 51
      Top = 65
      Width = 52
      Height = 18
      Cursor = crHandPoint
      OnMouseDown = Shape6MouseDown
    end
    object lNavigate: TLabel
      Left = 4
      Top = 4
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
    object sNL2: TShape
      Tag = 2
      Left = 52
      Top = 66
      Width = 30
      Height = 17
      Cursor = crHandPoint
      Brush.Color = clLime
      Pen.Style = psClear
      OnMouseDown = Shape6MouseDown
    end
    object sNL3: TShape
      Tag = 3
      Left = 240
      Top = 64
      Width = 52
      Height = 18
      Cursor = crHandPoint
      OnMouseDown = Shape6MouseDown
    end
    object lNRightSideProgress: TLabel
      Left = 224
      Top = 41
      Width = 148
      Height = 13
      AutoSize = False
      Caption = '.'
    end
    object lNLeftSideProgress: TLabel
      Left = 35
      Top = 41
      Width = 161
      Height = 13
      AutoSize = False
      Caption = '.'
    end
    object sNL4: TShape
      Tag = 4
      Left = 241
      Top = 65
      Width = 30
      Height = 17
      Cursor = crHandPoint
      Brush.Color = clLime
      Pen.Style = psClear
      OnMouseDown = Shape6MouseDown
    end
    object Bevel3: TBevel
      Left = 11
      Top = 97
      Width = 337
      Height = 4
      Shape = bsTopLine
    end
    object sNL5: TShape
      Tag = 5
      Left = 52
      Top = 133
      Width = 52
      Height = 18
      Cursor = crHandPoint
      Brush.Color = 14605823
      OnMouseDown = Shape6MouseDown
    end
    object sNL6: TShape
      Tag = 6
      Left = 53
      Top = 134
      Width = 25
      Height = 17
      Cursor = crHandPoint
      Brush.Color = 5637105
      Pen.Style = psClear
      OnMouseDown = Shape6MouseDown
    end
    object lNAllOtherTables: TLabel
      Left = 33
      Top = 109
      Width = 3
      Height = 13
      Caption = '.'
    end
    object sgNavigationSide: TAdvStringGrid
      Tag = 5
      Left = 86
      Top = 198
      Width = 537
      Height = 208
      Cursor = crDefault
      ColCount = 9
      DefaultRowHeight = 18
      DrawingStyle = gdsClassic
      FixedCols = 0
      RowCount = 11
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goHorzLine, goDrawFocusSelected, goRowSelect]
      ParentFont = False
      ParentShowHint = False
      ScrollBars = ssBoth
      ShowHint = True
      TabOrder = 0
      OnDrawCell = sgNavigationSideDrawCell
      GridLineColor = 14474202
      GridFixedLineColor = 14474202
      HoverRowCells = [hcNormal, hcSelected]
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      ActiveCellColor = 10344697
      ActiveCellColorTo = 6210033
      CellNode.TreeColor = clSilver
      ControlLook.FixedGradientFrom = 16250613
      ControlLook.FixedGradientTo = 16250613
      ControlLook.FixedGradientMirrorFrom = 16250613
      ControlLook.FixedGradientMirrorTo = 16250613
      ControlLook.FixedGradientHoverFrom = 15000287
      ControlLook.FixedGradientHoverTo = 14406605
      ControlLook.FixedGradientHoverMirrorFrom = 14406605
      ControlLook.FixedGradientHoverMirrorTo = 13813180
      ControlLook.FixedGradientHoverBorder = 12033927
      ControlLook.FixedGradientDownFrom = 14991773
      ControlLook.FixedGradientDownTo = 14991773
      ControlLook.FixedGradientDownMirrorFrom = 14991773
      ControlLook.FixedGradientDownMirrorTo = 14991773
      ControlLook.FixedGradientDownBorder = 14991773
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
      FilterDropDown.TextChecked = 'Checked'
      FilterDropDown.TextUnChecked = 'Unchecked'
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
      FixedColWidth = 124
      FixedRowHeight = 18
      FixedFont.Charset = DEFAULT_CHARSET
      FixedFont.Color = clBlack
      FixedFont.Height = -11
      FixedFont.Name = 'Tahoma'
      FixedFont.Style = [fsBold]
      FloatFormat = '%.2f'
      HoverButtons.Buttons = <>
      HoverButtons.Position = hbLeftFromColumnLeft
      HTMLSettings.ImageFolder = 'images'
      HTMLSettings.ImageBaseName = 'img'
      Look = glCustom
      MouseActions.DisjunctRowSelect = True
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
      SearchFooter.Color = 16250613
      SearchFooter.ColorTo = 16250613
      SearchFooter.FindNextCaption = 'Find &next'
      SearchFooter.FindPrevCaption = 'Find &previous'
      SearchFooter.Font.Charset = DEFAULT_CHARSET
      SearchFooter.Font.Color = clWindowText
      SearchFooter.Font.Height = -11
      SearchFooter.Font.Name = 'MS Sans Serif'
      SearchFooter.Font.Style = []
      SearchFooter.HighLightCaption = 'Highlight'
      SearchFooter.HintClose = 'Close'
      SearchFooter.HintFindNext = 'Find next occurrence'
      SearchFooter.HintFindPrev = 'Find previous occurrence'
      SearchFooter.HintHighlight = 'Highlight occurrences'
      SearchFooter.MatchCaseCaption = 'Match case'
      SearchFooter.ResultFormat = '(%d of %d)'
      SelectionColor = 14327846
      SelectionTextColor = clWhite
      ShowSelection = False
      ShowDesignHelper = False
      SortSettings.DefaultFormat = ssAutomatic
      SortSettings.Column = 0
      SortSettings.Show = True
      Version = '8.4.2.5'
      ColWidths = (
        124
        13
        84
        13
        79
        11
        64
        18
        64)
      RowHeights = (
        18
        18
        18
        18
        18
        18
        18
        18
        18
        18
        18)
    end
  end
  object pOptimisations: TPanel
    Left = 175
    Top = 8
    Width = 734
    Height = 468
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 4
    object lOptimisations: TLabel
      Left = 4
      Top = 4
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
    object lProgressUpdate: TLabel
      Left = 25
      Top = 285
      Width = 3
      Height = 13
      Caption = '.'
    end
    object lOJustInTime: TLabel
      Left = 125
      Top = 38
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
    object lOBuildDateTree: TLabel
      Left = 125
      Top = 72
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
    object lShowFilesInTypeBox: TLabel
      Left = 125
      Top = 106
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
    object lShowFilesInTypeBoxLimit: TLabel
      Left = 225
      Top = 141
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
    object lOGetUserDetails: TLabel
      Left = 125
      Top = 174
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
    object lOGetTempFiles: TLabel
      Left = 125
      Top = 208
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
    object cbProgressUpdate: TComboBox
      Left = 25
      Top = 304
      Width = 313
      Height = 21
      Style = csDropDownList
      TabOrder = 0
    end
    object eShowFilesInTypeBoxLimit: TEdit
      Left = 323
      Top = 139
      Width = 66
      Height = 21
      TabOrder = 1
    end
    object cbOJustInTime: TAdvSmoothSlider
      Left = 25
      Top = 33
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      TabOrder = 2
      TMSStyle = 0
    end
    object cbOBuildDateTree: TAdvSmoothSlider
      Left = 25
      Top = 67
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      TabOrder = 3
      TMSStyle = 0
    end
    object cbShowFilesInTypeBox: TAdvSmoothSlider
      Left = 25
      Top = 101
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      OnStateChanged = cbShowFilesInTypeBoxStateChanged
      TabOrder = 4
      TMSStyle = 0
    end
    object cbShowFilesInTypeBoxLimit: TAdvSmoothSlider
      Left = 125
      Top = 136
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      TabOrder = 5
      TMSStyle = 0
    end
    object cbOGetUserDetails: TAdvSmoothSlider
      Left = 25
      Top = 169
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      TabOrder = 6
      TMSStyle = 0
    end
    object cbOGetTempFiles: TAdvSmoothSlider
      Left = 25
      Top = 203
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      TabOrder = 7
      TMSStyle = 0
    end
  end
  object pTemp: TPanel
    Left = 175
    Top = 8
    Width = 732
    Height = 468
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 8
    object lTypesOfTempFile: TLabel
      Left = 25
      Top = 40
      Width = 3
      Height = 13
      Caption = '.'
    end
    object sbTemp: TSpeedButton
      Left = 168
      Top = 64
      Width = 41
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
      OnClick = sbTempClick
    end
    object eDeleteTemp: TSpeedButton
      Left = 216
      Top = 64
      Width = 41
      Height = 22
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
      OnClick = eDeleteTempClick
    end
    object lTemp: TLabel
      Left = 4
      Top = 4
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
    object lbTemp: TListBox
      Left = 25
      Top = 94
      Width = 680
      Height = 342
      Columns = 3
      ItemHeight = 13
      Sorted = True
      TabOrder = 0
      OnClick = lbTempClick
    end
    object eAddTemp: TEdit
      Left = 25
      Top = 64
      Width = 128
      Height = 21
      TabOrder = 1
      OnChange = eAddTempChange
      OnKeyPress = eAddTempKeyPress
    end
  end
  object pPaths: TPanel
    Left = 175
    Top = 8
    Width = 734
    Height = 472
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 5
    object lPaths: TLabel
      Left = 4
      Top = 4
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
    object tDataFolder: TLabel
      Left = 25
      Top = 38
      Width = 3
      Height = 13
      Caption = '.'
    end
    object sbXinorbisFolder: TSpeedButton
      Left = 677
      Top = 56
      Width = 23
      Height = 22
      Flat = True
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        20000000000000040000120B0000120B00000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00A2CA
        EE0076B2E6003E91DB00348CD900348CD900348CD900348CD900348CD900348C
        D900348CD900348CD900348BD900398FDA0085B9E900FF00FF00FF00FF004799
        DD00DEF1FA00A8DDF4009EDBF40096DAF3008ED8F30086D7F3007FD4F20079D3
        F20072D2F1006CD0F10069CFF100C2EAF8003F95DB00FF00FF00FF00FF003B97
        DB00EFFAFE00A1E9F90091E5F80081E1F70072DEF60063DAF50054D7F40047D3
        F30039D0F2002ECDF10026CBF000CAF2FB003B97DB00FF00FF00FF00FF003C9D
        DB00F2FAFD00B3EDFA00A4E9F90095E6F80085E2F70076DEF60065DBF50057D7
        F40049D4F3003BD1F20030CEF100CCF2FB003B9BDB00FF00FF00FF00FF003BA3
        DB00F6FCFE00C8F2FC00B9EFFB00ACECFA009CE8F9008BE3F7007CE0F6006CDC
        F6005DD9F5004FD6F40044D3F300D0F3FC003BA2DB00FF00FF00FF00FF003BA8
        DB00FEFFFF00F8FDFF00F6FDFF00F5FCFF00F3FCFE00D8F6FC0094E6F80085E3
        F70076DFF60068DBF5005CD8F400D7F4FC003BA7DB00FF00FF00FF00FF0039AD
        DB00E8F6FB0094D4EF0088CEEE0073C1E900C9E9F600F2FCFE00F3FCFE00F2FC
        FE00F0FCFE00EFFBFE00EEFBFE00FEFFFF003CAEDB00FF00FF00FF00FF0040AE
        DC00F1FAFD0094DEF50093DCF40081D5F2006ACAED006CCBEA0085D3EF0080D2
        EF007AD0EF0076CFEE0072CFEE00E9F7FB003EB2DC00FF00FF00FF00FF0041B4
        DC00F7FCFE008EE4F80091DEF5009FE0F500ACE1F600EFFBFE00F4FDFE00F3FC
        FE00F1FCFE00EFFBFE00EEFBFE00FAFDFF0058BCE000FF00FF00FF00FF003CB5
        DB00FDFEFE00FEFFFF00FEFEFF00FDFEFF00FEFFFF00EAF7FB006EC8E5006FC9
        E4006FC9E4006FC9E4007DCFE70084D0E800BAE5F200FF00FF00FF00FF0059C2
        E00061C3E20063C4E30063C4E30063C4E30062C4E30056C0E000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      OnClick = sbXinorbisFolderClick
    end
    object tCustomViewer: TLabel
      Left = 26
      Top = 97
      Width = 3
      Height = 13
      Caption = '.'
    end
    object sbGCustomViewer: TSpeedButton
      Left = 678
      Top = 115
      Width = 23
      Height = 22
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC6A18CC38E68
        C08B66BE8864BB8561B9835FB47E5CB27C5AB17B58AE7957AD7656AB7554A973
        53A97151C6A18CFF00FFC8926CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA97251FF00FFCA946EFFFFFF
        FFFFFFFFFFFEFFFFFDFEFEFDFEFEFCFEFEFCFEFEFCFEFEFCFEFEFAFEFEFAFCFC
        F9FFFFFFAA7353FF00FFCC976FFFFFFFFFFFFCFFFFFDFEFEFCFEFEFCFEFEFBFD
        FDFAFDFDFAFDFDFAFDFDFAFCFCF7FBFBF6FFFFFFAC7554FF00FFD19C73FFFFFF
        FEFEFCFEFEFCFEFEFCFDFDFBFDFDFBFDFDFAFDFDF8FBFBF9FBFAF7FBFAF6FBF8
        F4FFFFFFB07A58FF00FFD49E75FFFFFFFEFEFCFDFDFBFDFDFCFDFDFBFDFDF9FC
        FCF8FBF9F7FBF9F5FBF8F4FBF7F2FBF5F2FFFFFFB27C5AFF00FFD5A076FFFFFF
        FDFDFCFDFDFBFDFDFAFCFCF9FCFBF7FBF9F5FBF8F4FBF7F3FBF5F2FAF3EFF8F2
        ECFFFFFFB57E5CFF00FFD8A279FFFFFFFDFDFAFCFCFAFCFBF9FBFAF6FBF8F5FB
        F7F4FBF6F1F8F4EEF7F2EBF7F0EAF6ECE8FFFFFFB7815EFF00FFD9A379FFFFFF
        FCFBF9FCFBF8FBF9F7FBF7F4FAF7F2F9F5F0F7F3EDF6EFEAF5EBE7F3EAE4F2E7
        DEFFFFFFBA8560FF00FFDBA47AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBD8763FF00FFDCA77BDCA77B
        DCA77BDCA77BDCA77BDCA77BDCA77BDCA77BDCA77BDCA77BDCA77BDCA77BDCA7
        7BDCA77BC08B66FF00FFDDAD86E8B992E8B992E8B992E8B992E8B992E8B992E8
        B992E8B992E8B992E8B992E8B992E8B992E8B992C19170FF00FFDBC3B6DEB492
        DCA77BDCA67ADAA47AD8A279D5A076D49E75D29D73CF9A72CE9970CB966FC994
        6CC79E80DBC3B6FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      OnClick = sbGCustomViewerClick
    end
    object eXinorbisFolder: TEdit
      Left = 25
      Top = 56
      Width = 646
      Height = 21
      TabOrder = 0
    end
    object eGCustomViewer: TEdit
      Left = 26
      Top = 115
      Width = 646
      Height = 21
      TabOrder = 1
    end
  end
  object pGeneral: TPanel
    Left = 175
    Top = 10
    Width = 734
    Height = 468
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 9
    object lGeneral: TLabel
      Left = 4
      Top = 4
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
    object lTableRowHeight: TLabel
      Left = 25
      Top = 221
      Width = 3
      Height = 13
      Caption = '.'
    end
    object lDateFormat: TLabel
      Left = 25
      Top = 252
      Width = 3
      Height = 13
      Caption = '.'
    end
    object lMaxSearchResults: TLabel
      Left = 25
      Top = 280
      Width = 3
      Height = 13
      Caption = '.'
    end
    object lDefaultMaxSearchResults: TLabel
      Left = 269
      Top = 279
      Width = 3
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lRowHeight: TLabel
      Left = 209
      Top = 220
      Width = 3
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lAutoCheckUpdates: TLabel
      Left = 125
      Top = 38
      Width = 3
      Height = 13
      Caption = '.'
    end
    object lFHEnable: TLabel
      Left = 125
      Top = 72
      Width = 3
      Height = 13
      Caption = '.'
    end
    object lFHLogEnable: TLabel
      Left = 225
      Top = 106
      Width = 3
      Height = 13
      Caption = '.'
    end
    object lAllowSQLInSearch: TLabel
      Left = 225
      Top = 140
      Width = 3
      Height = 13
      Caption = '.'
    end
    object lSaveLog: TLabel
      Left = 125
      Top = 404
      Width = 3
      Height = 13
      Caption = '.'
    end
    object eRowHeight: TEdit
      Left = 154
      Top = 216
      Width = 49
      Height = 21
      TabOrder = 0
    end
    object eMaxSearchResults: TEdit
      Left = 154
      Top = 275
      Width = 109
      Height = 21
      TabOrder = 1
    end
    object cbDateFormat: TComboBox
      Left = 154
      Top = 247
      Width = 109
      Height = 21
      Style = csDropDownList
      TabOrder = 2
    end
    object cbAutoCheckUpdates: TAdvSmoothSlider
      Left = 25
      Top = 33
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      TabOrder = 3
      TMSStyle = 0
    end
    object GroupBox1: TGroupBox
      Left = 368
      Top = 329
      Width = 348
      Height = 126
      TabOrder = 4
      object bGResetGraphGradients: TBitBtn
        Left = 16
        Top = 24
        Width = 321
        Height = 25
        TabOrder = 0
        OnClick = bGResetGraphGradientsClick
      end
      object bClearScanHistory: TBitBtn
        Left = 16
        Top = 55
        Width = 321
        Height = 25
        TabOrder = 1
        OnClick = bClearScanHistoryClick
      end
      object bClearAllSettings: TBitBtn
        Left = 16
        Top = 86
        Width = 321
        Height = 25
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000120B0000120B00000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF4C62CC36
          4FC5344DC3465DC7FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FF4C63D15264D48490E795A0EE959FED838EE54C5DCE3D54C3FF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF4760D57584E3A1ACF47F8BEC5C
          67E45B66E37D87EA9FA8F16F7CDD324BC2FF00FFFF00FFFF00FFFF00FFFF00FF
          5970DE7888E6A3B0F55767E75665E68992ED8892EC535FE2525DE19FA9F26F7D
          DD4157C6FF00FFFF00FFFF00FFFF00FF6073E0A4B3F75A6EEB596CEA5869E8FF
          FFFFFFFFFF5562E55461E3535FE29FA9F25061D1FF00FFFF00FFFF00FF6A82E9
          8E9FF08499F45C73EE5B70EC5A6EEB909DF1A6AFF35767E75665E65562E57D89
          EB8591E74E64CEFF00FFFF00FF5D76EAA0B3F76580F25F78F05D76EF5C73EEFF
          FFFFFFFFFF596CEA5869E85767E75D6CE799A5F13C55CCFF00FFFF00FF617BEE
          A1B6F86784F4607CF35F7AF15F78F0FFFFFFFFFFFF5B70EC5A6EEB596CEA5F6F
          E99BA8F14159D0FF00FFFF00FF768DF391A6F388A1F86280F4617EF3607CF3FF
          FFFFFFFFFF5D76EF5C73EE5B70EC8293F18998EC5970D8FF00FFFF00FFFF00FF
          6C81ECA9BDFB6382F56281F56280F4FFFFFFFFFFFF5F7AF15F78F05D76EFA5B5
          F85D70DDFF00FFFF00FFFF00FFFF00FF758CF78397F0A9BDFB6382F56382F5FF
          FFFFFFFFFF617EF3607CF3A6B9F97B8DEA5C74E1FF00FFFF00FFFF00FFFF00FF
          FF00FF6D86F88497F1A9BDFB8AA3F86B89F66B89F689A2F8A8BCFA7F92EC5972
          E5FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF778EFA6E83EE92A6F4A0
          B4F8A0B4F891A6F3687DE96981EDFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FF7C94FA6C86F76A84F5778EF5FF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
        TabOrder = 2
        OnClick = bClearAllSettingsClick
      end
    end
    object cbFHEnable: TAdvSmoothSlider
      Left = 26
      Top = 67
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      OnStateChanged = cbFHEnableStateChanged
      TabOrder = 5
      TMSStyle = 0
    end
    object cbFHLogEnable: TAdvSmoothSlider
      Left = 125
      Top = 101
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      TabOrder = 6
      TMSStyle = 0
    end
    object cbAllowSQLInSearch: TAdvSmoothSlider
      Left = 125
      Top = 135
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      TabOrder = 7
      TMSStyle = 0
    end
    object cbSaveLog: TAdvSmoothSlider
      Left = 25
      Top = 399
      Width = 77
      Height = 23
      AppearanceOn.Fill.Color = 39423
      AppearanceOn.Fill.ColorTo = 52479
      AppearanceOn.Fill.ColorMirror = clNone
      AppearanceOn.Fill.ColorMirrorTo = clNone
      AppearanceOn.Fill.GradientType = gtVertical
      AppearanceOn.Fill.GradientMirrorType = gtSolid
      AppearanceOn.Fill.BorderColor = clNone
      AppearanceOn.Fill.Rounding = 3
      AppearanceOn.Fill.RoundingType = rtLeft
      AppearanceOn.Fill.ShadowOffset = 0
      AppearanceOn.Fill.Glow = gmNone
      AppearanceOn.FillDisabled.Color = 14474460
      AppearanceOn.FillDisabled.ColorMirror = clNone
      AppearanceOn.FillDisabled.ColorMirrorTo = clNone
      AppearanceOn.FillDisabled.GradientType = gtVertical
      AppearanceOn.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOn.FillDisabled.BorderColor = clNone
      AppearanceOn.FillDisabled.Rounding = 0
      AppearanceOn.FillDisabled.ShadowOffset = 0
      AppearanceOn.FillDisabled.Glow = gmNone
      AppearanceOn.Caption = '|'
      AppearanceOn.Font.Charset = DEFAULT_CHARSET
      AppearanceOn.Font.Color = clBlack
      AppearanceOn.Font.Height = -13
      AppearanceOn.Font.Name = 'Tahoma'
      AppearanceOn.Font.Style = [fsBold]
      AppearanceOff.Fill.Color = 15461355
      AppearanceOff.Fill.ColorTo = clWhite
      AppearanceOff.Fill.ColorMirror = clNone
      AppearanceOff.Fill.ColorMirrorTo = clNone
      AppearanceOff.Fill.GradientType = gtVertical
      AppearanceOff.Fill.GradientMirrorType = gtSolid
      AppearanceOff.Fill.BorderColor = clNone
      AppearanceOff.Fill.Rounding = 5
      AppearanceOff.Fill.RoundingType = rtRight
      AppearanceOff.Fill.ShadowOffset = 0
      AppearanceOff.Fill.Glow = gmNone
      AppearanceOff.FillDisabled.Color = 14474460
      AppearanceOff.FillDisabled.ColorMirror = clNone
      AppearanceOff.FillDisabled.ColorMirrorTo = clNone
      AppearanceOff.FillDisabled.GradientType = gtVertical
      AppearanceOff.FillDisabled.GradientMirrorType = gtSolid
      AppearanceOff.FillDisabled.BorderColor = clNone
      AppearanceOff.FillDisabled.Rounding = 0
      AppearanceOff.FillDisabled.ShadowOffset = 0
      AppearanceOff.FillDisabled.Glow = gmNone
      AppearanceOff.Caption = 'O'
      AppearanceOff.Font.Charset = DEFAULT_CHARSET
      AppearanceOff.Font.Color = clBlack
      AppearanceOff.Font.Height = -13
      AppearanceOff.Font.Name = 'Tahoma'
      AppearanceOff.Font.Style = [fsBold]
      ButtonAppearance.Fill.Color = 15263976
      ButtonAppearance.Fill.ColorTo = clSilver
      ButtonAppearance.Fill.ColorMirror = clNone
      ButtonAppearance.Fill.ColorMirrorTo = clNone
      ButtonAppearance.Fill.GradientType = gtVertical
      ButtonAppearance.Fill.GradientMirrorType = gtSolid
      ButtonAppearance.Fill.BorderColor = 10066329
      ButtonAppearance.Fill.Rounding = 3
      ButtonAppearance.Fill.ShadowOffset = 0
      ButtonAppearance.Fill.Glow = gmNone
      ButtonAppearance.FillDisabled.Color = 14474460
      ButtonAppearance.FillDisabled.ColorMirror = clNone
      ButtonAppearance.FillDisabled.ColorMirrorTo = clNone
      ButtonAppearance.FillDisabled.GradientType = gtVertical
      ButtonAppearance.FillDisabled.GradientMirrorType = gtSolid
      ButtonAppearance.FillDisabled.BorderColor = clNone
      ButtonAppearance.FillDisabled.Rounding = 0
      ButtonAppearance.FillDisabled.ShadowOffset = 0
      ButtonAppearance.FillDisabled.Glow = gmNone
      ButtonAppearance.Size = 35
      Fill.Color = clWhite
      Fill.ColorTo = clWhite
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.Opacity = 135
      Fill.OpacityTo = 160
      Fill.BorderColor = clSilver
      Fill.Rounding = 3
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      FillDisabled.Color = 14474460
      FillDisabled.ColorTo = 11974326
      FillDisabled.ColorMirror = clNone
      FillDisabled.ColorMirrorTo = clNone
      FillDisabled.GradientType = gtVertical
      FillDisabled.GradientMirrorType = gtSolid
      FillDisabled.BorderColor = clNone
      FillDisabled.Rounding = 0
      FillDisabled.ShadowOffset = 0
      FillDisabled.Glow = gmNone
      TabOrder = 8
      TMSStyle = 0
    end
  end
  object bSave: TBitBtn
    Left = 660
    Top = 493
    Width = 126
    Height = 25
    Caption = '.'
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
    TabOrder = 0
  end
  object bCancel: TBitBtn
    Left = 792
    Top = 494
    Width = 116
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
    Left = 8
    Top = 494
    Width = 161
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
  object Panel1: TPanel
    Left = -3
    Top = 2
    Width = 172
    Height = 476
    Color = clWhite
    ParentBackground = False
    TabOrder = 10
    object sbGeneral: TSpeedButton
      Tag = 3
      Left = 9
      Top = 10
      Width = 153
      Height = 22
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFECE0E0C9A9A9C7A7A7E8DCDCFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1AC
        ACACA9A9A9DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFF4ECECD4B7B7BA8F8FF8BFBFE5B0B0C39696CCB1B1F0E9E9FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEDEDEDB9B9B9929292C4
        C4C4B4B4B4999999B3B3B3E9E9E9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FAF6F6DEC7C7C29999EEB7B7FFDBDBFFD8D8F7BEBEF8BFBFD9A6A6B89090D5BE
        BEF7F3F3FFFFFFFFFFFFFFFFFFFFFFFFF6F6F6C8C8C89C9C9CBBBBBBDEDEDEDB
        DBDBC3C3C3C4C4C4AAAAAA939393C0C0C0F3F3F3FFFFFFFFFFFFFEFDFDE8D6D6
        CBA5A5EAB3B3FFD8D8FFDBDBFFCECEFFC7C7E2AEAEE2AEAEF6BDBDF1B9B9CF9F
        9FBC9898DFCDCDFCFAFAFDFDFDD7D7D7A7A7A7B7B7B7DBDBDBDEDEDED2D2D2CB
        CBCBB2B2B2B2B2B2C2C2C2BDBDBDA2A2A29B9B9BCECECEFAFAFAD7B4B4E6B1B1
        FFD3D3FFE0E0FFD7D7FFCECEFFCBCBFFC7C7E6B1B1EAB3B3EAB3B3E2AEAEF6BD
        BDE8B3B3C99A9AC5A6A6B6B6B6B5B5B5D7D7D7E2E2E2DADADAD2D2D2CFCFCFCB
        CBCBB5B5B5B7B7B7B7B7B7B2B2B2C2C2C2B7B7B79D9D9DA9A9A9CA9C9CFFE4E4
        FFE1E1FFD7D7FFD4D4FFCFCFFFCCCCFFC7C7E8B3B3EBB4B4EBB4B4EBB4B4E5B0
        B0E6B1B1F3BBBBB68E8E9F9F9FE6E6E6E3E3E3DADADAD7D7D7D3D3D3D0D0D0CB
        CBCBB7B7B7B8B8B8B8B8B8B8B8B8B4B4B4B5B5B5C0C0C0919191CFA3A3FFE2E2
        FFDFDFFFDBDBFFDADAFFD4D4FFCBCBFFC9C9EDB6B6E2AEAEE6B1B1EBB4B4ECB5
        B5E8B3B3F6BDBDBC9494A6A6A6E4E4E4E1E1E1DEDEDEDDDDDDD7D7D7CFCFCFCD
        CDCDBABABAB2B2B2B5B5B5B8B8B8B9B9B9B7B7B7C2C2C2979797D1A4A4FFE2E2
        FFE0E0FFDDDDFFD1D1F1B9B9F6BDBDFDC2C2FDC2C2F7BEBED6A5A5E2AEAEE8B3
        B3E8B3B3F9C0C0BD9595A7A7A7E4E4E4E2E2E2E0E0E0D5D5D5BDBDBDC2C2C2C6
        C6C6C6C6C6C3C3C3A9A9A9B2B2B2B7B7B7B7B7B7C5C5C5979797D2A5A5FFE2E2
        FFD9D9FFCECEFFCECEEBB4B4FFCBCBFFEBEBFFEBEBFFCBCBECB5B5FFC8C8E2AE
        AEE2AEAEFAC1C1BE9696A7A7A7E4E4E4DCDCDCD2D2D2D2D2D2B8B8B8CFCFCFED
        EDEDEDEDEDCFCFCFB9B9B9CCCCCCB2B2B2B2B2B2C5C5C5989898D1A1A1FFC9C9
        F8BFBFF9C0C0FDC2C2D0A0A0FFEDEDFFEDEDFFEDEDFFEDEDD0A0A0FDC2C2F7BE
        BEEAB3B3E6B1B1BD9292A4A4A4CDCDCDC4C4C4C5C5C5C6C6C6A3A3A3EFEFEFEF
        EFEFEFEFEFEFEFEFA3A3A3C6C6C6C3C3C3B7B7B7B5B5B5959595E4C5C5D3A2A2
        FFC6C6FFEBEBFFEBEBF1B9B9DBA8A8C59898C59898DBA8A8F1B9B9FFEAEAFFE9
        E9FEC3C3D3A2A2D5B8B8C7C7C7A5A5A5CACACAEDEDEDEDEDEDBDBDBDACACAC9B
        9B9B9B9B9BACACACBDBDBDECECECEBEBEBC7C7C7A5A5A5BABABAFFFFFFCDA0A0
        FFEDEDFFEDEDFFEDEDFFD0D0D0A0A0FDC2C2FDC2C2CF9F9FFFD0D0FFEDEDFFED
        EDFFEDEDCDA0A0FFFFFFFFFFFFA3A3A3EFEFEFEFEFEFEFEFEFD4D4D4A3A3A3C6
        C6C6C6C6C6A2A2A2D4D4D4EFEFEFEFEFEFEFEFEFA3A3A3FFFFFFFFFFFFF4D8D8
        DEB1B1C49898C49797D6A5A5FFC7C7FFEBEBFFEAEAFFC4C4D6A5A5C49797C498
        98DEB1B1F4D8D8FFFFFFFFFFFFDADADAB5B5B59B9B9B9A9A9AA9A9A9CBCBCBED
        EDEDECECECC8C8C8A9A9A99A9A9A9B9B9BB5B5B5DADADAFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFBF7F7CD9F9FFFEDEDFFEDEDFFEDEDFFEDEDCD9F9FF9F5F5FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7A2A2A2EFEFEFEF
        EFEFEFEFEFEFEFEFA2A2A2F5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFF4D8D8DDAFAFC49797C49797DDAFAFF4D8D8FFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDADADAB3B3B39A
        9A9A9A9A9AB3B3B3DADADAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      Margin = 5
      NumGlyphs = 2
      OnClick = sbPostScanClick
    end
    object sbPostScan: TSpeedButton
      Left = 9
      Top = 34
      Width = 153
      Height = 22
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF928FF5514BEE1D15E8D6
        D5FBFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF524DF35856EB6C6DE7332DE9D7D6FBAA6B47A86C4DC49F8BFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF6262F37D7FEE9499EB8D91E93B37ECD9
        D7FBB2704DD68E62B866439C5A38FF00FFFF00FFFF00FFFF00FFFF00FF6767F8
        9599F2A5AAEE7B81E6979AEB4440EFDAD9FCB87752DB9970E6A47FCB8057A655
        31FF00FFFF00FFFF00FFFF00FFA6A7FC6666F98485F4A3A8EFA0A5ED4F4CF1DC
        DBFDC07E58DEA179DE895BE6A67FD0875C954E27FF00FFFF00FFABD1AEB1D3B4
        FF00FFAAAAFC6464F87C7EF35958F4DEDDFDC6865EE1A881E09264D9794CE7A8
        84BE704AC69F8AFF00FF6FB67690BF934F9C55A6CBA9FF00FFB2B2FC6261F8E0
        DFFDCE8D65E4B08BE39C6DDD8554E29667DA976DAD6E4CFF00FF60B469CAE8C8
        AFD9AB92BF9448954D9BC19DFF00FFFF00FFD4966BE7B793E7A677E0905DDE8E
        5CE6AD88A75B32FF00FF64BA6EB6E0B17BCC6F92D289ADD9A989B88B83B386F2
        DAC8D38D5AEFC8A9E6A673E29B67E29866E7B38FB0663AFF00FF84CD8FBADFB8
        7ACC6D66C65972C866A8DAA368A86DD0E3D1E1AC83E6B58EF0CCACE5A671E9B1
        84E3AF88C2815BFF00FFB7E3BDB3DAB5A2D89A6DCA5F66C65880CC75A3CEA363
        A769F7EBE0D99460F2D1B2EBB98DF0C9AAD89C70DCB39BFF00FFFF00FF7BCC88
        BEE1BE94D4896ECA626EC9609ED69793C196B1D4B3ECC5A5E7B48EF3D3B5E9BB
        98CD8653FF00FFFF00FFFF00FFFF00FFA0D5A8BAE0BBA7DAA07DCE707FCD73B0
        D9AD57A85EF1F2E8E1A573EBC29EDDA273FF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF89D395B4DCB7BCE0BAB9E1B5CEEACBA4CEA695C99AF3DAC4E3AB7CFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFBDE7C492D49C6CC37965
        BD7180C689ACD7B0FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      Margin = 5
      OnClick = sbPostScanClick
    end
    object sbOptimisations: TSpeedButton
      Tag = 1
      Left = 9
      Top = 58
      Width = 153
      Height = 22
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFFF00FF
        B0B0B0A4A4A4FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA7A7
        A7ABABABFF00FFFF00FFFF00FFFF00FFB8B8B8DBDBDBB8B8B7BDAC969C816084
        643B84643B9C8160BDAB95B7B7B6D9D9D9B5B5B5FF00FFFF00FFFF00FFFF00FF
        FF00FFD3D3D3C3C0BE9C6B3BA66C35AE6F37AE6F37A66C35A1764AC5C4C3C6C6
        C5FF00FFFF00FFFF00FFFF00FFFF00FFD1C1AEA78D6FAF7844BB8C5EC29371C4
        9174C38F71BF906CB88A5DB48659A58A6AD1C1AEFF00FFFF00FFFF00FFFF00FF
        A7855BB37D46C29971D8AA89EFDFCFFAF6F3FAF5F3EFDFD1D7A785BE946CB37D
        46A7855BFF00FFFF00FFFF00FFD0BAA0B0804AC69B6FD9AA88FFFEEBFFFAEEFF
        FDF2FFFEF2FFFCEFFFFDEBD9A37AC2996CB0804AD0BAA0FF00FFFF00FFC19E75
        BF8F58CDA381F0DBC1FFF7E6FAF2E3C5C0B6F1EDDEFFFCE8FFF5DFEFD4AFC899
        72BF8F58C19E75FF00FFFF00FFBC8F5AC99C66CF9F80FAF3E2FDF6E9F2F0E38D
        8C84817F77D2CFC2FFFBEBFAECCCC7906DC99C66BC8F5AFF00FFFF00FFC69860
        CEA671D1A589FAF6E9FDF8EEFFFFF9818079B1AEA4817F77C9C6BAFAF0D3C996
        72CEA671C69860FF00FFFF00FFD9B284D3AC75D9B798F1E3D6FEFBF5F5F5F39F
        9E95F0F0E9F8F8F2BEB9ADF0DAC2D2AA87D3AC75D9B284FF00FFFF00FFD6CAB3
        D3AD77DFC49ADEBDAAFFFFFFF0F0EEE7E5DAFFFFF7FFFFF7FFFEF3DCB498DBC0
        96C2AA7EE1CDB1FF00FFFF00FF2FA9DE36A0C7DEBF8AE2C9A7DFBFAEF1E3DCF3
        F1ECF4F1EBF1E2D9DCBAA3DFC39E8CB1A93DA8D23CADDEFF00FF82D0F185D4F3
        6BC7E93DA5C7E2C792E6D1A9E0C2A6D5AE96D5AB92DEBDA0E4CFA6BFC19E48B3
        D7ACE3F649BCEBFF00FF84D5F46ECFF2B5E8F96BCBEC43AECEECC488E9CB94E7
        D09DE7D09DE9CB94DEC28E3AADD286D5F17FD4F432B8EDFF00FFFF00FF75D3F6
        6CD1F5BFECFA6ACFF276C4D5FBCD96FAC17EFAC17EFBCD967BC4D574D3F385D9
        F736BFF2FF00FFFF00FFFF00FFFF00FF7FDAF92EC2F635C4F6FF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FF2EC2F636C5F6FF00FFFF00FFFF00FF}
      Margin = 5
      OnClick = sbPostScanClick
    end
    object sbPaths: TSpeedButton
      Tag = 2
      Left = 9
      Top = 82
      Width = 153
      Height = 22
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        20000000000000040000120B0000120B00000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00A2CA
        EE0076B2E6003E91DB00348CD900348CD900348CD900348CD900348CD900348C
        D900348CD900348CD900348BD900398FDA0085B9E900FF00FF00FF00FF004799
        DD00DEF1FA00A8DDF4009EDBF40096DAF3008ED8F30086D7F3007FD4F20079D3
        F20072D2F1006CD0F10069CFF100C2EAF8003F95DB00FF00FF00FF00FF003B97
        DB00EFFAFE00A1E9F90091E5F80081E1F70072DEF60063DAF50054D7F40047D3
        F30039D0F2002ECDF10026CBF000CAF2FB003B97DB00FF00FF00FF00FF003C9D
        DB00F2FAFD00B3EDFA00A4E9F90095E6F80085E2F70076DEF60065DBF50057D7
        F40049D4F3003BD1F20030CEF100CCF2FB003B9BDB00FF00FF00FF00FF003BA3
        DB00F6FCFE00C8F2FC00B9EFFB00ACECFA009CE8F9008BE3F7007CE0F6006CDC
        F6005DD9F5004FD6F40044D3F300D0F3FC003BA2DB00FF00FF00FF00FF003BA8
        DB00FEFFFF00F8FDFF00F6FDFF00F5FCFF00F3FCFE00D8F6FC0094E6F80085E3
        F70076DFF60068DBF5005CD8F400D7F4FC003BA7DB00FF00FF00FF00FF0039AD
        DB00E8F6FB0094D4EF0088CEEE0073C1E900C9E9F600F2FCFE00F3FCFE00F2FC
        FE00F0FCFE00EFFBFE00EEFBFE00FEFFFF003CAEDB00FF00FF00FF00FF0040AE
        DC00F1FAFD0094DEF50093DCF40081D5F2006ACAED006CCBEA0085D3EF0080D2
        EF007AD0EF0076CFEE0072CFEE00E9F7FB003EB2DC00FF00FF00FF00FF0041B4
        DC00F7FCFE008EE4F80091DEF5009FE0F500ACE1F600EFFBFE00F4FDFE00F3FC
        FE00F1FCFE00EFFBFE00EEFBFE00FAFDFF0058BCE000FF00FF00FF00FF003CB5
        DB00FDFEFE00FEFFFF00FEFEFF00FDFEFF00FEFFFF00EAF7FB006EC8E5006FC9
        E4006FC9E4006FC9E4007DCFE70084D0E800BAE5F200FF00FF00FF00FF0059C2
        E00061C3E20063C4E30063C4E30063C4E30062C4E30056C0E000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Margin = 5
      OnClick = sbPostScanClick
    end
    object sbAppearance: TSpeedButton
      Tag = 4
      Left = 9
      Top = 106
      Width = 153
      Height = 22
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFE1818FD1496CC92B63C72D77CF519FDF8DCBFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFE87C7AD61219E14059EE6384F3
        73A1F071B2E45AB6D236B4C41BBBDC91E1FF00FFFF00FFFF00FFFF00FFFF00FF
        EB6E51E95240F88584FF969FFF7491FF609AFF60B7FF78D8FC92EFE871EAB632
        CCBC6ED9FF00FFFF00FFFF00FFF69E6DF07744FCA692FF7B6FFF5158FF5A79FF
        5E9BFF5CBCFF57DAFF4CF7F17BFFD685F19734CFBA90E4FF00FFFF00FFF87E0F
        FBB98EFF976AFF795BFF716BFF7689FF7CADFF7BCDFF71EDF763FFD952FFCF7C
        FFB373EC661AD0FF00FFFDC861FDBE60FFD09CFFA55BFFA271FF9A84FF979BFF
        9FBFFF9FE0FE92FBE77CFFC966FFA84FFFBE95FD7240DDA086E7F7CA32FEDD80
        FFD16CFFC76BFFC785FFC49EFFBDB3FFBFD0FFBFF1F4B0FFD696FFB679FF955E
        FF9977FF8265EC664BDDF2DC1BFFF290FFE962FFE876FFE793FFE7B0FFE6CAFF
        E5E5FCDEFDE1C6FFC2A6FFA184FF7E66FF7664FF887BF63D2EDBEBED18F9FA92
        FAFD64FAFD7BF9FD98FAFDB5FAFED3FAFEEFEFF3FFD0D5FFAFB3FF8D91FF6C6F
        FF6769FF8283FB2C2FDED4ED30E4F582E5FF6FE0FF79E0FF95DFFFAFDCFFC7DC
        FFE0D9FEFAC5E9FFA7CAFF87AAFF698BFF788EFF7386FB475AE6CBEE57C6EB67
        DDFF9BC5FF6FC3FF8CBEFFA1B9FFB3BDFFCFBDFFEEB0F8FF99DEFF7EC2FF63A3
        FF9EBDFF5983F87792EFFF00FFA0E138CBF697AEFF6CA4FF7A9DFF8D9BFFA3A4
        FFC4A2FFDF97FFF885EFFF6ED3FF78C5FF92C5FC1C73F4FF00FFFF00FFA1E555
        94E257BBF99D8AFF6E79FF7682FF9789FFB687FFD17EFFEC6DFBFE76E8FF9BDF
        FC54BAFB75B9FAFF00FFFF00FFFF00FF6EDD3B74E158A1F6999EFFA67BFF9E70
        FFAE70FFC77CFFE3A5FFFA98F4FB55D8F552CCFBFF00FFFF00FFFF00FFFF00FF
        FF00FF66DF563AD73D6AE67C88F3AA96F9C497FBD387F7DB68EFE01EE7E66DE6
        F3FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF58DF7437D96E22
        D67A25D8923BDFB265E8D3FF00FFFF00FFFF00FFFF00FFFF00FF}
      Margin = 5
      OnClick = sbPostScanClick
    end
    object sbFavourites: TSpeedButton
      Tag = 6
      Left = 9
      Top = 130
      Width = 153
      Height = 22
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
      Margin = 5
      OnClick = sbPostScanClick
    end
    object sbTempFiles: TSpeedButton
      Tag = 7
      Left = 9
      Top = 154
      Width = 153
      Height = 22
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFE2C0AACC8D66BC6B36BC6B36BC6A36BC
        6A36BB6A35BB6A35BB6935BD6E3BCA8B63E3C2AEFF00FFFF00FFFF00FFFF00FF
        C57C4DF8F1EAF8F3EDF8F3EDF8F3EDF8F3EDFAF3EBFAF2EAF8F3EDF8F3EDF8F3
        EDC37A4DFF00FFFF00FFFF00FFFF00FFC68046F7F0E6F8F3EDF8F3EDF8F3EDF8
        F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDC1743CFF00FFFF00FFFF00FFFF00FF
        C78448F8F1E8F8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3
        EDC37A41FF00FFFF00FFFF00FFFF00FFC7864BF8F2EBF8F3EDF8F3EDF8F3EDF8
        F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDC78045FF00FFFF00FFFF00FFFF00FF
        C8884DF9F3ECF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3
        EDC88448FF00FFFF00FFFF00FFFF00FFC88C4FF9F4EDF8F3EDF8F3EDF8F3EDF8
        F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDC8864BFF00FFFF00FFFF00FFFF00FF
        C88C50F8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDFAF4
        EFC8874CFF00FFFF00FFFF00FFFF00FFC88D51F8F3EDF8F3EDF8F3EDF8F3EDF8
        F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F4F0C6864CFF00FFFF00FFFF00FFFF00FF
        C88D51F8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF8F3EDF7F2ECFBF7F3F5EF
        E9C38048FF00FFFF00FFFF00FFFF00FFC88D52F9F5F1F8F3EDF8F3EDF8F3EDF8
        F3EDF8F3EDF8F3EDFCE6CDFAE5C9E2B684D5A884FF00FFFF00FFFF00FFFF00FF
        CA925AFAF6F2F8F3EDF8F3EDF8F3EDF8F3EDF8F3EDFFFBF8F6D8B4E1B07DDC96
        69FF00FFFF00FFFF00FFFF00FFFF00FFD2A274F8F3EDF8F3EDF8F3EDF8F3EDF8
        F2ECF7F2ECF2E6D7E2B27DDC986BFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        E8CEB9D7AA7CCA9055CA9055CA9155CB9055C98F55CF9D69DDB190FF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      Margin = 5
      OnClick = sbPostScanClick
    end
  end
  object cdMain: TColorDialog
    Options = [cdFullOpen]
    Left = 253
    Top = 480
  end
  object puFSpecial: TPopupMenu
    AutoHotkeys = maManual
    AutoLineReduction = maManual
    Left = 301
    Top = 480
    object miFSH1: TMenuItem
      Caption = '.'
      OnClick = miFSH1Click
    end
    object miFSH2: TMenuItem
      Caption = '.'
      OnClick = miFSH1Click
    end
    object miFSH3: TMenuItem
      Caption = '.'
      OnClick = miFSH1Click
    end
    object miFSH4: TMenuItem
      Caption = '.'
      OnClick = miFSH1Click
    end
    object miFSH5: TMenuItem
      Caption = '.'
      OnClick = miFSH1Click
    end
  end
end
